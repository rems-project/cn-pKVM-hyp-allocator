#!/usr/bin/env python3
"""
Sizing benchmark data collection script.
Measures input generation time at various sizes for property-based testing.

For each unique function in bug_finding.json, generates 100 inputs at sizes
1, 2, 4, 8, 16, 32 using three configurations:
  - darcy_4096: symbolic + --max-array-length=4096
  - darcy: symbolic (default array length)
  - bennet: random (no --symbolic)
"""

import argparse
import csv
import json
import math
import os
import re
import subprocess
import sys
import time

import plotly.graph_objects as go

try:
    from tqdm import tqdm
except ImportError:
    print("ERROR: This script requires tqdm.")
    print("Install it with: pip install tqdm")
    sys.exit(1)


# --- Constants ---

SIZES = [1, 2, 4, 8, 16, 32]
NUM_SAMPLES = 100
BENCH_DIR = '_test_sizing'

# Config name -> (needs_symbolic, extra_runtime_args)
CONFIGS = {
    'bennet':     (False, []),
    'darcy':      (True, []),
    'darcy_4096': (True, []),
}

# Build mode -> compile-time cn test flags
BUILD_MODES = {
    'darcy_4096': ['--symbolic', '--smt-pruning-at-runtime', '--max-array-length', '4096'],
    'darcy':      ['--symbolic', '--smt-pruning-at-runtime'],
    'bennet':     [],
}

BASE_COMMIT = 'b391f721fe71b8682a7e1752375c5c1bef936491'
BASE_FILES = [
    'src/alloc.c', 'src/shim.c', 'specs/spec.c',
    'include/alloc.h', 'include/fulminate.h', 'include/prelude.h',
]

CSV_FILENAME = 'pbt_sizing_data.csv'
CSV_FIELDNAMES = [
    'function', 'config', 'size', 'sample_idx',
    'gen_time_sec', 'status',
]


def checkout_base_version():
    """Checkout base version of source files and apply workaround patch."""
    result = subprocess.run(
        ['git', 'checkout', BASE_COMMIT, '--'] + BASE_FILES,
        capture_output=True, text=True, timeout=30)
    if result.returncode != 0:
        print(f"ERROR: Failed to checkout base version:\n{result.stderr}")
        sys.exit(1)

    result = subprocess.run(
        ['git', 'apply', 'patches/workaround.patch'],
        capture_output=True, text=True, timeout=30)
    if result.returncode != 0:
        print(f"ERROR: Failed to apply workaround patch:\n{result.stderr}")
        sys.exit(1)


def config_to_build_mode(config: str) -> str:
    return config


def output_dir_for(function: str, build_mode: str) -> str:
    return os.path.join(BENCH_DIR, f'{function}_{build_mode}')


def extract_unique_functions(
        bug_finding_path: str = 'pbt_bench/bug_finding.json') -> list[str]:
    with open(bug_finding_path, 'r') as f:
        data = json.load(f)
    seen = set()
    functions = []
    for entry in data:
        func = entry['fut']
        if func not in seen:
            seen.add(func)
            functions.append(func)
    return functions


def generate_code(function: str, build_mode: str) -> str:
    """Run cn test --no-run to generate C code. Returns output directory path."""
    out_dir = output_dir_for(function, build_mode)
    os.makedirs(out_dir, exist_ok=True)

    cmd = [
        'cn', 'test', '--no-run',
        f'--output-dir={out_dir}',
        f'--only={function}',
        f'--num-samples={NUM_SAMPLES}',
        # '--until-timeout=180',
        '--output-tyche=results.jsonl',
        'src/alloc.c',
        '-Isrc', '-Iinclude',
        '-D__cerb__', '-DSTANDALONE', '-DNO_STATEMENT_EXPRS',
        '--input-timeout=0',
    ] + BUILD_MODES[build_mode]

    result = subprocess.run(cmd, capture_output=True, text=True, timeout=180)
    if result.returncode != 0:
        raise RuntimeError(
            f"Code generation failed for {function}/{build_mode}:\n"
            f"{result.stderr}")
    return out_dir


def compile_binary(output_dir: str) -> str:
    """Compile by running the generated run_tests.sh (compile+link only)."""
    script_path = os.path.join(output_dir, 'run_tests.sh')

    # Strip the "# Run" section so we only compile+link (the run step can
    # hang indefinitely for symbolic configs with --input-timeout 0).
    with open(script_path, 'r') as f:
        script_content = f.read()
    run_idx = script_content.find('\n# Run\n')
    if run_idx >= 0:
        script_content = script_content[:run_idx]

    env = os.environ.copy()
    fulminate_path = os.path.abspath('fulminate2.h')
    env['CPPFLAGS'] = f'-include {fulminate_path}'
    env['CFLAGS'] = '-std=c2x'

    subprocess.run(
        ['bash', '-c', script_content],
        env=env,
        capture_output=True,
        text=True,
        timeout=300,
    )

    binary_path = os.path.join(output_dir, 'tests.out')
    if not os.path.isfile(binary_path):
        raise RuntimeError(f"Compilation failed: {binary_path} not found")
    return binary_path


def run_binary(binary_path: str, config: str, size: int,
               tyche_path: str, timeout: int = 180
               ) -> subprocess.CompletedProcess:
    """Run tests.out with specific runtime flags."""
    _, extra_args = CONFIGS[config]

    cmd = [
        binary_path,
        '--sizing-strategy', 'constant',
        '--max-generator-size', str(size),
        '--output-tyche', tyche_path,
        '--no-replays', '--no-replicas',
        '--input-timeout', '0',
    ] + extra_args

    return subprocess.run(
        cmd, capture_output=True, text=True, timeout=timeout)


def parse_tyche_jsonl(tyche_path: str) -> list[dict]:
    """Parse tyche JSONL, handling trailing commas and empty lines."""
    records = []
    with open(tyche_path, 'r') as f:
        for line in f:
            line = line.strip()
            if not line:
                continue
            # Fix trailing commas before } or ]
            line = re.sub(r',\s*([}\]])', r'\1', line)
            try:
                data = json.loads(line)
            except json.JSONDecodeError:
                continue
            if data.get('type') == 'test_case':
                records.append(data)
    return records


def extract_generation_time(timing: dict[str, float]) -> float:
    """Sum all timing keys except execute:* to get generation time."""
    return sum(v for k, v in timing.items() if not k.startswith('execute:'))


def load_existing_results(csv_path: str) -> set[tuple[str, str, int]]:
    """Load completed (function, config, size) tuples from existing CSV."""
    completed: dict[tuple[str, str, int], int] = {}
    try:
        with open(csv_path, 'r', newline='') as f:
            reader = csv.DictReader(f)
            for row in reader:
                key = (row['function'], row['config'], int(row['size']))
                completed[key] = completed.get(key, 0) + 1
    except FileNotFoundError:
        pass
    except Exception as e:
        print(f"WARNING: Could not parse existing {csv_path}: {e}")
        return set()
    # Consider complete if we have any rows (includes partial timeout data)
    return {k for k, count in completed.items() if count > 0}


def run_experiment(function: str, config: str, size: int,
                   binary_path: str, csvfile, csv_writer,
                   timeout: int = 180) -> bool:
    """Run a single (function, config, size) experiment. Returns True on success."""
    out_dir = os.path.dirname(binary_path)
    tyche_path = os.path.join(out_dir, f'results_{config}_{size}.jsonl')

    # Remove stale results
    if os.path.exists(tyche_path):
        os.remove(tyche_path)

    timed_out = False
    try:
        run_binary(binary_path, config, size, tyche_path, timeout=timeout)
    except subprocess.TimeoutExpired:
        timed_out = True

    if not os.path.exists(tyche_path):
        if timed_out:
            print(f"\n  TIMEOUT (no output): {function}/{config}/size={size}")
        else:
            print(f"\n  NO OUTPUT: {function}/{config}/size={size}")
        return False

    records = parse_tyche_jsonl(tyche_path)

    for idx, record in enumerate(records):
        timing = record.get('timing', {})
        gen_time = extract_generation_time(timing)
        status = record.get('status', 'unknown')
        csv_writer.writerow({
            'function': function,
            'config': config,
            'size': size,
            'sample_idx': idx,
            'gen_time_sec': gen_time,
            'status': status,
        })
    csvfile.flush()

    if timed_out:
        print(f"\n  TIMEOUT: {function}/{config}/size={size} "
              f"({len(records)}/{NUM_SAMPLES} samples recorded)")
        return False

    return True


def analyze_time_per_passed(csv_path: str, functions: list[str],
                            configs: list[str], sizes: list[int]):
    """Print relative speed table (bennet=1x, geometric mean of per-function ratios).
    Returns per-function totals dict, or None if the CSV is missing."""
    # Pre-populate at per-function granularity
    totals: dict[tuple[str, str, int], tuple[float, int]] = {
        (func, c, s): (0.0, 0)
        for func in functions for c in configs for s in sizes
    }
    try:
        with open(csv_path, 'r', newline='') as f:
            reader = csv.DictReader(f)
            for row in reader:
                key = (row['function'], row['config'], int(row['size']))
                if key not in totals:
                    continue
                total, passed = totals[key]
                total += float(row['gen_time_sec'])
                if row['status'] == 'passed':
                    passed += 1
                totals[key] = (total, passed)
    except FileNotFoundError:
        print(f"ERROR: {csv_path} not found")
        return None

    config_display = {
        'bennet': 'Bennet', 'darcy': 'Darcy', 'darcy_4096': 'Darcy-4096',
    }

    print("=" * 60)
    print(f"Relative speed (Bennet = 1x, geometric mean across "
          f"{len(functions)} functions)")
    print("=" * 60)

    header = f"  {'Size':>4}"
    for config in configs:
        header += f"  {config_display.get(config, config):>16}"
    print(header)
    print("  " + "-" * (len(header) - 2))

    # Accumulate for Avg row
    all_log_ratios: dict[str, list[float]] = {
        c: [] for c in configs if c != 'bennet'}
    all_na_counts: dict[str, int] = {c: 0 for c in configs}

    for size in sizes:
        row_str = f"  {size:>4}"
        for config in configs:
            na_count = sum(
                1 for func in functions
                if totals[(func, config, size)][1] == 0
            )
            all_na_counts[config] += na_count
            na_suffix = f" ({na_count})" if na_count > 0 else ""

            if config == 'bennet':
                row_str += f"  {'1x' + na_suffix:>16}"
            else:
                # Per-function ratio vs bennet, then geometric mean
                log_ratios = []
                for func in functions:
                    b_total, b_passed = totals[(func, 'bennet', size)]
                    c_total, c_passed = totals[(func, config, size)]
                    if b_passed > 0 and c_passed > 0:
                        ratio = (c_total / c_passed) / (b_total / b_passed)
                        log_ratios.append(math.log(ratio))
                all_log_ratios[config].extend(log_ratios)
                if log_ratios:
                    geomean = math.exp(sum(log_ratios) / len(log_ratios))
                    cell = f"{geomean:.2f}x{na_suffix}"
                else:
                    cell = f"N/A{na_suffix}"
                row_str += f"  {cell:>16}"
        print(row_str)

    # Avg row
    avg_str = f"  {'Avg':>4}"
    for config in configs:
        na_suffix = f" ({all_na_counts[config]})" if all_na_counts[config] > 0 else ""
        if config == 'bennet':
            avg_str += f"  {'1x' + na_suffix:>16}"
        else:
            if all_log_ratios[config]:
                geomean = math.exp(
                    sum(all_log_ratios[config]) / len(all_log_ratios[config]))
                cell = f"{geomean:.2f}x{na_suffix}"
            else:
                cell = f"N/A{na_suffix}"
            avg_str += f"  {cell:>16}"
    print(avg_str)

    # Raw average times table
    print(f"\n== Raw avg time per passed input (ms) ==")
    print(header)
    print("  " + "-" * (len(header) - 2))
    for size in sizes:
        row_str = f"  {size:>4}"
        for config in configs:
            agg_total = sum(totals[(func, config, size)][0]
                            for func in functions)
            agg_passed = sum(totals[(func, config, size)][1]
                             for func in functions)
            if agg_passed > 0:
                cell = f"{agg_total / agg_passed * 1000:.3f}"
            else:
                cell = "N/A"
            row_str += f"  {cell:>16}"
        print(row_str)

    print()
    return totals


def plot_time_per_passed(totals: dict[tuple[str, str, int], tuple[float, int]],
                         configs: list[str], sizes: list[int],
                         timeout: int, output_dir: str):
    """Generate a bar chart PNG for hyp allocator sizing results."""
    colors = {"darcy_4096": "#1f77b4", "darcy": "#ff7f0e", "bennet": "#2ca02c"}
    x_labels = [str(s) for s in sizes]
    os.makedirs(output_dir, exist_ok=True)

    # Aggregate per-function totals to per-(config, size)
    agg: dict[tuple[str, int], tuple[float, int]] = {}
    for (func, config, size), (total, passed) in totals.items():
        key = (config, size)
        prev_total, prev_passed = agg.get(key, (0.0, 0))
        agg[key] = (prev_total + total, prev_passed + passed)

    fig = go.Figure()
    for config in configs:
        normal_y = []
        timeout_y = []
        for size in sizes:
            total, passed = agg.get((config, size), (0.0, 0))
            if passed > 0:
                normal_y.append(total / passed)
                timeout_y.append(None)
            else:
                normal_y.append(None)
                timeout_y.append(timeout)

        color = colors.get(config, "#999999")
        fig.add_trace(go.Bar(
            name=config, x=x_labels, y=normal_y,
            marker_color=color,
            legendgroup=config, showlegend=True,
        ))
        fig.add_trace(go.Bar(
            name=f"{config} (N/A)", x=x_labels, y=timeout_y,
            marker_color="lightgray",
            marker_pattern_shape="/",
            legendgroup=config, showlegend=False,
        ))

    fig.update_layout(
        barmode="group",
        title="Hyp Allocator",
        xaxis_title="Size",
        yaxis_title="Gen time / passed input (s)",
        font=dict(family="Helvetica"),
    )
    path = os.path.join(output_dir, "hyp_allocator.png")
    fig.write_image(path, engine="kaleido")
    print(f"  Saved {path}")


def main():
    parser = argparse.ArgumentParser(
        description='Sizing benchmark: measure input generation time at various sizes.')
    parser.add_argument('--restart', action='store_true',
                        help='Ignore existing CSV and start fresh')
    parser.add_argument('--log-output', type=str, metavar='DIR',
                        help='Log test program output to files in DIR')
    parser.add_argument('--config',
                        choices=['darcy_4096', 'darcy', 'bennet', 'all'],
                        default='all',
                        help='Which config to run (default: all)')
    parser.add_argument('--only-function', type=str, metavar='FUNC',
                        help='Only benchmark this function')
    parser.add_argument('--analyze-only', action='store_true',
                        help='Skip experiments; analyze existing CSV results')
    parser.add_argument('--sizes', type=str, default=','.join(map(str, SIZES)),
                        help='Comma-separated sizes to test '
                             f'(default: {",".join(map(str, SIZES))})')
    args = parser.parse_args()

    sizes = [int(s) for s in args.sizes.split(',')]
    if args.config == 'all':
        configs = list(CONFIGS.keys())
    else:
        configs = [args.config]

    # Validate we're in the project root
    if not os.path.exists('pbt_bench/bug_finding.json'):
        print("ERROR: Run this script from the project root.")
        sys.exit(1)

    if args.analyze_only:
        functions = extract_unique_functions()
        if args.only_function:
            functions = [args.only_function]
        totals = analyze_time_per_passed(
            CSV_FILENAME, functions, configs, sizes)
        if totals is not None:
            plot_time_per_passed(totals, configs, sizes,
                                 timeout=180,
                                 output_dir=os.path.join('pbt_bench',
                                                         'sizing_plots'))
        return

    print("=" * 60)
    print("Property-Based Testing: Sizing Benchmark")
    print(f"Configs: {', '.join(configs)}")
    print(f"Sizes: {sizes}")
    print(f"Samples per run: {NUM_SAMPLES}")
    print("=" * 60)
    print()

    # Checkout base version and apply workaround patch
    print("Checking out base version of source files...")
    checkout_base_version()
    print("Base version checked out + workaround patch applied")
    print()

    # Extract functions
    functions = extract_unique_functions()
    if args.only_function:
        if args.only_function not in functions:
            print(
                f"ERROR: Function '{args.only_function}' not in bug_finding.json")
            print(f"Available: {', '.join(functions)}")
            sys.exit(1)
        functions = [args.only_function]

    print(f"Functions ({len(functions)}): {', '.join(functions)}")
    print()

    # Load existing results to skip completed experiments (and their builds)
    completed = set() if args.restart else load_existing_results(CSV_FILENAME)

    # Phase 1: Generate + Compile
    needed_builds = set()
    for func in functions:
        for config in configs:
            needed_builds.add((func, config_to_build_mode(config)))

    # Drop builds where every experiment is already complete
    needed_builds = {
        (func, bm) for func, bm in needed_builds
        if any(
            (func, config, size) not in completed
            for config in configs if config_to_build_mode(config) == bm
            for size in sizes
        )
    }

    binaries: dict[tuple[str, str], str] = {}
    print("Phase 1: Generate + Compile")
    build_failures = set()
    with tqdm(total=len(needed_builds), desc="Building", unit="build") as pbar:
        for func, build_mode in sorted(needed_builds):
            pbar.set_description(f"Building {func}/{build_mode}")
            try:
                out_dir = generate_code(func, build_mode)
                binary = compile_binary(out_dir)
                binaries[(func, build_mode)] = binary
            except Exception as e:
                print(f"\n  SKIP build {func}/{build_mode}: {e}")
                build_failures.add((func, build_mode))
            pbar.update(1)

    print(f"Built {len(binaries)}/{len(needed_builds)} binaries")
    print()

    # Phase 2: Run Experiments
    # Build experiment list
    experiments = []
    for func in functions:
        for config in configs:
            build_mode = config_to_build_mode(config)
            if (func, build_mode) in build_failures:
                continue
            for size in sizes:
                if (func, config, size) in completed:
                    continue
                experiments.append((func, config, size))

    if not experiments:
        print("All experiments already complete.")
        totals = analyze_time_per_passed(
            CSV_FILENAME, functions, configs, sizes)
        if totals is not None:
            plot_time_per_passed(totals, configs, sizes,
                                 timeout=180,
                                 output_dir=os.path.join('pbt_bench',
                                                         'sizing_plots'))
        return

    skipped = (len(functions) * len(configs) * len(sizes)
               - len(experiments)
               - len(build_failures) * len(sizes))
    if skipped > 0:
        print(f"Resuming: {skipped} experiments already complete, "
              f"{len(experiments)} remaining")

    print(f"Phase 2: Run {len(experiments)} experiments")
    print(f"Writing results to: {CSV_FILENAME}")
    print()

    if args.log_output:
        os.makedirs(args.log_output, exist_ok=True)

    # Open CSV
    file_exists = os.path.exists(CSV_FILENAME) and not args.restart
    csvfile = open(CSV_FILENAME, 'a' if file_exists else 'w', newline='')
    writer = csv.DictWriter(csvfile, fieldnames=CSV_FIELDNAMES)
    if not file_exists:
        writer.writeheader()
        csvfile.flush()

    try:
        successes = 0
        with tqdm(total=len(experiments), desc="Experiments",
                  unit="exp") as pbar:
            for func, config, size in experiments:
                pbar.set_description(
                    f"{func}/{config}/size={size}")
                build_mode = config_to_build_mode(config)
                binary = binaries[(func, build_mode)]

                ok = run_experiment(func, config, size, binary,
                                    csvfile, writer)
                if ok:
                    successes += 1

                pbar.set_postfix({"ok": f"{successes}/{pbar.n + 1}"})
                pbar.update(1)

        print()
        print(f"Done! {successes}/{len(experiments)} experiments succeeded.")
    finally:
        csvfile.close()

    totals = analyze_time_per_passed(CSV_FILENAME, functions, configs, sizes)
    if totals is not None:
        plot_time_per_passed(totals, configs, sizes,
                             timeout=180,
                             output_dir=os.path.join('pbt_bench',
                                                     'sizing_plots'))


if __name__ == '__main__':
    main()

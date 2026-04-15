#!/usr/bin/env python3
"""
Bug finding data collection script for property-based testing benchmark.
Tests each patch from bug_finding.json to measure bug detection rates and timing.
"""

import argparse
import csv
import json
import os
import re
import subprocess
import sys
import time

try:
    from tqdm import tqdm
except ImportError:
    print("ERROR: This script requires tqdm.")
    print("Install it with: pip install tqdm")
    sys.exit(1)


def checkout_base_version():
    """
    Checkout the base version of src/alloc.c, src/shim.c and specs/spec.c at commit b391f721fe71b8682a7e1752375c5c1bef936491.

    Exits with error if checkout fails.
    """
    try:
        result = subprocess.run(
            ['git', 'checkout', 'b391f721fe71b8682a7e1752375c5c1bef936491',
                '--',
                'src/alloc.c', 'src/shim.c',
                'specs/spec.c',
                'include/alloc.h', 'include/fulminate.h', 'include/prelude.h'],
            capture_output=True,
            text=True,
            timeout=30
        )

        if result.returncode != 0:
            print(
                "ERROR: Failed to checkout base version of src/alloc.c and specs/spec.c")
            print(f"Exit code: {result.returncode}")
            if result.stdout:
                print(f"Stdout: {result.stdout}")
            if result.stderr:
                print(f"Stderr: {result.stderr}")
            sys.exit(1)

    except subprocess.TimeoutExpired:
        print("ERROR: Git checkout timed out after 30 seconds")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: Failed to checkout base version: {e}")
        sys.exit(1)


def apply_patch(patch_path: str):
    """
    Apply a git patch to the current working directory.

    Args:
        patch_path: Path to the patch file

    Exits with error if patch application fails.
    """
    try:
        result = subprocess.run(
            ['git', 'apply', patch_path],
            capture_output=True,
            text=True,
            timeout=30
        )

        if result.returncode != 0:
            print(f"\nERROR: Failed to apply patch {patch_path}")
            print(f"Exit code: {result.returncode}")
            if result.stdout:
                print(f"Stdout: {result.stdout}")
            if result.stderr:
                print(f"Stderr: {result.stderr}")
            sys.exit(1)

    except subprocess.TimeoutExpired:
        print(
            f"\nERROR: Git apply timed out after 30 seconds for {patch_path}")
        sys.exit(1)
    except Exception as e:
        print(f"\nERROR: Failed to apply patch {patch_path}: {e}")
        sys.exit(1)


def reset_files():
    """
    Reset src/alloc.c and specs/spec.c to the base version (discard changes),
    then reapply the workaround patches.

    Exits with error if reset fails.
    """
    try:
        result = subprocess.run(
            ['git', 'checkout', '--', 'src/alloc.c', 'specs/spec.c'],
            capture_output=True,
            text=True,
            timeout=30
        )

        if result.returncode != 0:
            print("\nERROR: Failed to reset src/alloc.c and specs/spec.c")
            print(f"Exit code: {result.returncode}")
            if result.stdout:
                print(f"Stdout: {result.stdout}")
            if result.stderr:
                print(f"Stderr: {result.stderr}")
            sys.exit(1)

    except subprocess.TimeoutExpired:
        print("\nERROR: Git checkout timed out after 30 seconds")
        sys.exit(1)
    except Exception as e:
        print(f"\nERROR: Failed to reset src/alloc.c and specs/spec.c: {e}")
        sys.exit(1)

    # Reapply workaround patch after reset
    apply_patch('patches/workaround.patch')


def _write_log_file(log_dir: str, function: str, trial_num: int,
                    stdout: str, stderr: str, timed_out: bool = False):
    """Write test program output to a log file."""
    filename = f"{function}_trial{trial_num}.log"
    filepath = os.path.join(log_dir, filename)
    with open(filepath, 'w') as f:
        if timed_out:
            f.write("=== TIMED OUT (partial output) ===\n\n")
        if stdout:
            f.write("=== STDOUT ===\n")
            f.write(stdout)
            if not stdout.endswith('\n'):
                f.write('\n')
        if stderr:
            f.write("=== STDERR ===\n")
            f.write(stderr)
            if not stderr.endswith('\n'):
                f.write('\n')


def run_trial(function: str, trial_num: int, extra_args: list[str] | None = None,
              test_script: str = './test-symbolic.sh',
              log_output_dir: str | None = None,
              timeout: int = 120) -> tuple[bool, float, int | None, int | None]:
    """
    Run a single trial of testing for a specific function.

    Args:
        function: Function name to test
        trial_num: Trial number (for logging)
        extra_args: Optional additional arguments to pass to the test script
        test_script: Path to the test script to run (default: './test-symbolic.sh')

    Returns:
        Tuple of (bug_found: bool, elapsed_time: float, num_runs: int | None, num_discards: int | None)
        - bug_found is True if FAILED pattern is found in output
        - elapsed_time is in seconds
        - num_runs is the number of runs reported (None if not matched)
        - num_discards is the number of discards reported (None if not present)

    If timeout occurs, returns (False, elapsed_time, None, None)
    """
    start_time = time.time()

    try:
        cmd = [test_script, f'--only={function}',
               '--no-replicas', '--no-replays', '--exit-fast',
               #    '--until-timeout=120',
               '--num-samples=10000000']

        if extra_args:
            cmd.extend(extra_args)

        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=timeout
        )

        elapsed = time.time() - start_time

        # Combine stdout and stderr for pattern matching
        combined_output = result.stdout + result.stderr

        # Log test program output to file if requested
        if log_output_dir:
            _write_log_file(log_output_dir, function, trial_num,
                            result.stdout, result.stderr)

        # Parse runs and discards from output (always). The tool prints one
        # "Testing ...: N runs" line per tick when stdout is piped, so take
        # the last match rather than the first.
        stats_pattern = (r'Testing\s+[^\n]+:\s*(\d+)\s+runs'
                         r'(?:,\s*(\d+)\s+discards)?')
        stats_match = None
        for m in re.finditer(stats_pattern, combined_output):
            stats_match = m
        num_runs = None
        num_discards = None
        if stats_match:
            num_runs = int(stats_match.group(1))
            if stats_match.group(2):
                num_discards = int(stats_match.group(2))

        # Check for bug (FAILED pattern, but not FAILED TO GENERATE)
        bug_pattern = r'Testing\s+[^\n]+:[^\n]*\nFAILED(?! TO GENERATE)'
        bug_found = re.search(bug_pattern, combined_output) is not None

        # The printed run count doesn't include the failing run itself
        if bug_found:
            num_runs = (num_runs if num_runs is not None else 0) + 1

        # Check for generation failure (not a bug, but also not a successful run)
        generation_failed = 'FAILED TO GENERATE' in combined_output

        # Validate: non-zero exit code MUST match bug finding or generation failure
        if result.returncode != 0 and not bug_found and not generation_failed:
            print(
                f"\n  ERROR: {test_script} exited with code {result.returncode} but output did not match bug finding pattern")
            print(f"  Function: {function}, Trial: {trial_num}")
            print(f"  Expected pattern: {bug_pattern}")
            print("\n  === STDOUT ===")
            print(result.stdout)
            print("\n  === STDERR ===")
            print(result.stderr)
            raise RuntimeError(
                f"{test_script} returned non-zero exit code ({result.returncode}) "
                f"without matching bug finding pattern for {function} trial {trial_num}"
            )

        return (bug_found, elapsed, num_runs, num_discards)

    except subprocess.TimeoutExpired as e:
        elapsed = time.time() - start_time

        # Parse runs and discards from output captured before timeout
        num_runs = None
        num_discards = None
        stdout = e.stdout.decode('utf-8', errors='replace') if e.stdout else ''
        stderr = e.stderr.decode('utf-8', errors='replace') if e.stderr else ''
        combined_output = stdout + stderr

        # Log partial output captured before timeout
        if log_output_dir:
            _write_log_file(log_output_dir, function, trial_num,
                            stdout, stderr, timed_out=True)

        stats_pattern = (r'Testing\s+[^\n]+:\s*(\d+)\s+runs'
                         r'(?:,\s*(\d+)\s+discards)?')
        stats_match = None
        for m in re.finditer(stats_pattern, combined_output):
            stats_match = m
        if stats_match:
            num_runs = int(stats_match.group(1))
            if stats_match.group(2):
                num_discards = int(stats_match.group(2))

        # Timeout means no bug found within time limit
        return (False, elapsed, num_runs, num_discards)


def num_trials_for_patch(patch_data: dict) -> int:
    """Return the number of trials for a given patch (50 for patch-10-*, 10 otherwise)."""
    return 50 if "patch-10-" in patch_data["path"] else 10


def test_patch(patch_data: dict, csvfile, csv_writer,
               test_script: str = './test-symbolic.sh',
               log_output_dir: str | None = None,
               timeout: int = 120,
               trials_to_run: list[int] | None = None) -> int:
    """
    Test a patch by applying it and running multiple trials.
    Writes each trial result to CSV immediately.

    Args:
        patch_data: Dictionary with 'path', 'fut', and optionally 'args' keys
        csvfile: Open file object for flushing after each trial
        csv_writer: CSV DictWriter to write results to
        test_script: Path to the test script to run (default: './test-symbolic.sh')
        trials_to_run: Specific trial numbers to run (default: all trials for this patch)

    Returns:
        Number of bugs found across the trials run
    """
    patch_path = patch_data['path']
    function = patch_data['fut']
    extra_args = patch_data.get('args', None)

    if trials_to_run is None:
        trials_to_run = list(range(1, num_trials_for_patch(patch_data) + 1))

    # Apply the patch
    apply_patch(patch_path)

    # Run trials with nested progress bar
    bug_found_count = 0

    with tqdm(total=len(trials_to_run), desc="    Trials", unit="trial", leave=False) as trial_pbar:
        for trial in trials_to_run:
            bug_found, elapsed, num_runs, num_discards = run_trial(
                function, trial, extra_args, test_script=test_script,
                log_output_dir=log_output_dir, timeout=timeout)

            if bug_found:
                bug_found_count += 1

            # Write trial result immediately
            csv_writer.writerow({
                'patch': patch_path,
                'function': function,
                'trial_num': trial,
                'bug_found': bug_found,
                'elapsed_time': elapsed,
                'num_runs': num_runs if num_runs is not None else '',
                'num_discards': num_discards if num_discards is not None else ''
            })
            csvfile.flush()

            postfix = {
                "found": bug_found_count,
                "last": f"{elapsed:.2f}s",
            }
            if num_runs is not None:
                postfix["runs"] = num_runs
            if num_discards is not None:
                postfix["discards"] = num_discards
            trial_pbar.set_postfix(postfix)
            trial_pbar.update(1)

    # Reset files to base version
    reset_files()

    return bug_found_count


def load_bug_finding_data(only_buggy: bool = False) -> list[dict]:
    """
    Load the bug_finding.json file.

    Args:
        only_buggy: If True, only return patches where 'found' is True

    Returns:
        List of dictionaries with 'path', 'fut', and optionally 'args' keys

    Exits with error if file cannot be loaded.
    """
    try:
        with open('pbt_bench/bug_finding.json', 'r') as f:
            data = json.load(f)

        if only_buggy:
            data = [patch for patch in data if patch.get('found', False)]

        return data
    except FileNotFoundError:
        print("ERROR: pbt_bench/bug_finding.json not found")
        sys.exit(1)
    except json.JSONDecodeError as e:
        print(f"ERROR: Failed to parse bug_finding.json: {e}")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: Failed to load bug_finding.json: {e}")
        sys.exit(1)


MODES = {
    'symbolic': './test-symbolic.sh',
    'random': './test-random.sh',
}


def load_existing_results(csv_filename: str) -> dict[str, set[int]]:
    """
    Load completed trials from an existing CSV file.

    Returns:
        Dict mapping patch path to set of completed trial numbers.
        Empty dict if file doesn't exist or can't be parsed.
    """
    completed: dict[str, set[int]] = {}
    try:
        with open(csv_filename, 'r', newline='') as f:
            reader = csv.DictReader(f)
            for row in reader:
                patch = row['patch']
                trial_num = int(row['trial_num'])
                if patch not in completed:
                    completed[patch] = set()
                completed[patch].add(trial_num)
    except FileNotFoundError:
        pass
    except Exception as e:
        print(f"WARNING: Could not parse existing {csv_filename}: {e}")
        print("Starting fresh.")
        return {}
    return completed


def run_mode(mode: str, patches: list[dict],
             log_output_dir: str | None = None,
             restart: bool = False):
    """
    Run bug finding trials for a single mode (symbolic or random).

    Args:
        mode: Testing mode ('symbolic' or 'random')
        patches: List of patch data dictionaries
        restart: If True, ignore existing CSV and start fresh
    """
    test_script = MODES[mode]
    timeout = 30 if mode == 'random' else 180
    csv_filename = f'pbt_bug_finding_data_{mode}.csv'
    fieldnames = ['patch', 'function', 'trial_num', 'bug_found',
                  'elapsed_time', 'num_runs', 'num_discards']

    # Check for existing results to resume from
    completed = {} if restart else load_existing_results(csv_filename)

    # Figure out which patches still need work
    patches_with_remaining = []
    skipped = 0
    for patch_data in patches:
        num_trials = num_trials_for_patch(patch_data)
        done = completed.get(patch_data['path'], set())
        remaining = {t for t in range(1, num_trials + 1)} - done
        if remaining:
            patches_with_remaining.append((patch_data, done, num_trials))
        else:
            skipped += 1

    if not patches_with_remaining:
        print(f"All {mode} trials already complete in {csv_filename}")
        print()
        return

    if completed:
        print(f"Resuming {mode}: {skipped} patches complete, "
              f"{len(patches_with_remaining)} remaining")
    print(f"Writing {mode} results to: {csv_filename}")
    print()

    try:
        if completed:
            csvfile = open(csv_filename, 'a', newline='')
        else:
            csvfile = open(csv_filename, 'w', newline='')
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        if not completed:
            writer.writeheader()
        csvfile.flush()
    except Exception as e:
        print(f"\nERROR: Failed to open CSV file: {e}")
        sys.exit(1)

    total_bugs_found = 0
    total_trials = 0

    try:
        print(f"Running {mode} bug finding trials...")
        with tqdm(total=len(patches_with_remaining), desc="Patches", unit="patch") as patch_pbar:
            for i, (patch_data, done_trials, num_trials) in enumerate(patches_with_remaining, 1):
                function = patch_data['fut']

                patch_pbar.set_description(
                    f"Patch {i}/{len(patches_with_remaining)}: {function}")

                trials_to_run = sorted(
                    {t for t in range(1, num_trials + 1)} - done_trials)

                bugs_found = test_patch(patch_data, csvfile, writer,
                                        test_script=test_script,
                                        log_output_dir=log_output_dir,
                                        timeout=timeout,
                                        trials_to_run=trials_to_run)

                total_bugs_found += bugs_found
                total_trials += len(trials_to_run)

                patch_pbar.set_postfix({
                    "found": f"{bugs_found}/{len(trials_to_run)}"
                })
                patch_pbar.update(1)

        print()
        print(f"{mode.capitalize()} data collection complete!")
        print(f"Results saved to: {csv_filename}")
        print(f"Patches tested this run: {len(patches_with_remaining)}")
        if skipped:
            print(f"Patches skipped (already complete): {skipped}")
        print(f"Trials run: {total_trials}")
        print(f"Bugs found: {total_bugs_found}")
        print()

    except Exception as e:
        print(f"\nERROR during {mode} data collection: {e}")
        raise
    finally:
        csvfile.close()


def main():
    """Main entry point for bug finding data collection."""
    # Parse command line arguments
    parser = argparse.ArgumentParser(
        description='Bug finding data collection script for property-based testing benchmark.'
    )
    parser.add_argument('--only-buggy', action='store_true',
                        help='Only test patches where found=true in bug_finding.json')
    parser.add_argument('--mode', choices=['symbolic', 'random', 'both'],
                        default='both',
                        help='Testing mode: symbolic, random, or both (default: both)')
    parser.add_argument('--log-output', type=str, metavar='DIR',
                        help='Log test program output to files in DIR (one per trial)')
    parser.add_argument('--restart', action='store_true',
                        help='Ignore existing CSV data and start fresh')
    args = parser.parse_args()

    if args.mode == 'both':
        modes = ['symbolic', 'random']
    else:
        modes = [args.mode]

    print("="*60)
    print("Property-Based Testing: Bug Finding Data Collection")
    print(f"Mode: {args.mode}")
    print("="*60)
    print()

    # Checkout base version
    print("Checking out base version of src/alloc.c and specs/spec.c...")
    checkout_base_version()
    print("Base versions checked out")
    print()

    # Apply workaround patches
    print("Applying workaround patches...")
    apply_patch('patches/workaround.patch')
    print("Workaround patches applied")
    print()

    # Load patch data
    print("Loading bug_finding.json...")
    patches = load_bug_finding_data(only_buggy=args.only_buggy)
    if args.only_buggy:
        print(
            f"Loaded {len(patches)} patches (filtered to only buggy patches)")
    else:
        print(f"Loaded {len(patches)} patches")
    print()

    if args.log_output:
        os.makedirs(args.log_output, exist_ok=True)

    for mode in modes:
        run_mode(mode, patches, log_output_dir=args.log_output,
                 restart=args.restart)

    print("Run analyze_bugfinding.py for detailed statistics")


if __name__ == '__main__':
    main()

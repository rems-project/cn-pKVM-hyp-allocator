#!/usr/bin/env python3
"""
Bug finding data collection script for property-based testing benchmark.
Tests each patch from bug_finding.json to measure bug detection rates and timing.
"""

import argparse
import csv
import json
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
                '--', 'src/alloc.c', 'src/shim.c', 'specs/spec.c'],
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


def run_trial(function: str, trial_num: int, extra_args: list[str] | None = None) -> tuple[bool, float, int | None, int | None]:
    """
    Run a single trial of symbolic testing for a specific function.

    Args:
        function: Function name to test
        trial_num: Trial number (for logging)
        extra_args: Optional additional arguments to pass to test-symbolic.sh

    Returns:
        Tuple of (bug_found: bool, elapsed_time: float, num_runs: int | None, num_discards: int | None)
        - bug_found is True if FAILED pattern is found in output
        - elapsed_time is in seconds
        - num_runs is the number of runs reported (None if no bug found or not matched)
        - num_discards is the number of discards reported (None if not present or no bug found)

    If timeout occurs, returns (False, elapsed_time, None, None)
    """
    start_time = time.time()

    try:
        cmd = ['./test-symbolic.sh', f'--only={function}',
               '--no-replicas', '--no-replays', '--exit-fast',
               '--until-timeout=120',
               '--num-samples=100000']

        if extra_args:
            cmd.extend(extra_args)

        result = subprocess.run(
            cmd,
            capture_output=True,
            text=True,
            timeout=120  # 2 minute timeout
        )

        elapsed = time.time() - start_time

        # Combine stdout and stderr for pattern matching
        combined_output = result.stdout + result.stderr

        # Pattern to match: Testing <function>: N runs[, M discards]\nFAILED
        pattern = r'Testing\s+[^\n]+:(?:\s*(\d+)\s+runs(?:,\s*(\d+)\s+discards)?)?[^\n]*\nFAILED'
        match = re.search(pattern, combined_output)

        bug_found = match is not None
        num_runs = None
        num_discards = None

        if bug_found:
            if match.group(1):
                num_runs = int(match.group(1))
            # Group 2 is the discards (may be None if not present)
            if match.group(2):
                num_discards = int(match.group(2))

        # Validate: non-zero exit code MUST match bug finding pattern
        if result.returncode != 0 and not bug_found:
            print(
                f"\n  ERROR: test-symbolic.sh exited with code {result.returncode} but output did not match bug finding pattern")
            print(f"  Function: {function}, Trial: {trial_num}")
            print(f"  Expected pattern: {pattern}")
            print("\n  === STDOUT ===")
            print(result.stdout)
            print("\n  === STDERR ===")
            print(result.stderr)
            raise RuntimeError(
                f"test-symbolic.sh returned non-zero exit code ({result.returncode}) "
                f"without matching bug finding pattern for {function} trial {trial_num}"
            )

        return (bug_found, elapsed, num_runs, num_discards)

    except subprocess.TimeoutExpired:
        elapsed = time.time() - start_time
        # Timeout means no bug found within time limit
        return (False, elapsed, None, None)


def test_patch(patch_data: dict, csv_writer, num_trials: int = 10) -> int:
    """
    Test a patch by applying it and running multiple trials.
    Writes each trial result to CSV immediately.

    Args:
        patch_data: Dictionary with 'path', 'fut', and optionally 'args' keys
        csv_writer: CSV DictWriter to write results to
        num_trials: Number of trials to run (default: 10)

    Returns:
        Number of bugs found across all trials
    """
    patch_path = patch_data['path']
    function = patch_data['fut']
    extra_args = patch_data.get('args', None)

    # Apply the patch
    apply_patch(patch_path)

    # Run trials with nested progress bar
    bug_found_count = 0

    with tqdm(total=num_trials, desc="    Trials", unit="trial", leave=False) as trial_pbar:
        for trial in range(1, num_trials + 1):
            bug_found, elapsed, num_runs, num_discards = run_trial(
                function, trial, extra_args)

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

            trial_pbar.set_postfix({
                "found": bug_found_count,
                "last": f"{elapsed:.2f}s"
            })
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


def main():
    """Main entry point for bug finding data collection."""
    # Parse command line arguments
    parser = argparse.ArgumentParser(
        description='Bug finding data collection script for property-based testing benchmark.'
    )
    parser.add_argument('--only-buggy', action='store_true',
                        help='Only test patches where found=true in bug_finding.json')
    args = parser.parse_args()

    print("="*60)
    print("Property-Based Testing: Bug Finding Data Collection")
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
        print(f"Loaded {len(patches)} patches (filtered to only buggy patches)")
    else:
        print(f"Loaded {len(patches)} patches")
    print()

    # Initialize CSV file
    csv_filename = 'pbt_bug_finding_data.csv'
    try:
        csvfile = open(csv_filename, 'w', newline='')
        fieldnames = ['patch', 'function', 'trial_num', 'bug_found',
                      'elapsed_time', 'num_runs', 'num_discards']
        writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
        writer.writeheader()
        csvfile.flush()  # Ensure header is written immediately
        print(f"Writing results to: {csv_filename}")
        print()
    except Exception as e:
        print(f"\nERROR: Failed to create CSV file: {e}")
        sys.exit(1)

    # Test each patch
    total_bugs_found = 0
    total_trials = 0

    try:
        print("Running bug finding trials...")
        with tqdm(total=len(patches), desc="Patches", unit="patch") as patch_pbar:
            for i, patch_data in enumerate(patches, 1):
                function = patch_data['fut']

                patch_pbar.set_description(f"Patch {i}/{len(patches)}: {function}")

                num_trials = 10
                if "patch-10-" in patch_data["path"]:
                    num_trials = 50
                bugs_found = test_patch(patch_data, writer, num_trials=num_trials)
                csvfile.flush()  # Ensure results are written to disk immediately

                total_bugs_found += bugs_found
                total_trials += num_trials

                patch_pbar.set_postfix({
                    "found": f"{bugs_found}/{num_trials}"
                })
                patch_pbar.update(1)

        print()
        print("Data collection complete!")
        print(f"Results saved to: {csv_filename}")
        print(f"Total patches tested: {len(patches)}")
        print(f"Total trials: {total_trials}")
        print(f"Total bugs found: {total_bugs_found}")
        print()
        print("Run analyze_bugfinding.py for detailed statistics")

    except Exception as e:
        print(f"\nERROR during data collection: {e}")
        raise
    finally:
        csvfile.close()


if __name__ == '__main__':
    main()

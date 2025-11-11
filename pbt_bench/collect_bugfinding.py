#!/usr/bin/env python3
"""
Bug finding data collection script for property-based testing benchmark.
Tests each patch from bug_finding.json to measure bug detection rates and timing.
"""

import csv
import json
import math
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
    Checkout the base version of src/alloc.c and specs/spec.c at commit b391f721fe71b8682a7e1752375c5c1bef936491.

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
    Reset src/alloc.c and specs/spec.c to the base version (discard changes).

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


def run_trial(function: str, trial_num: int) -> tuple[bool, float, int | None, int | None]:
    """
    Run a single trial of symbolic testing for a specific function.

    Args:
        function: Function name to test
        trial_num: Trial number (for logging)

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
        result = subprocess.run(
            ['./test-symbolic.sh', f'--only={function}',
             '--no-replicas', '--no-replay', '--exit-fast',
             '--num-samples=100000'],
            capture_output=True,
            text=True,
            timeout=600  # 10 minute timeout
        )

        elapsed = time.time() - start_time

        # Combine stdout and stderr for pattern matching
        combined_output = result.stdout + result.stderr

        # Pattern to match: Testing <function>: N runs[, M discards]\nFAILED
        pattern = r'Testing\s+[^\n]+:\s*(\d+)\s+runs(?:,\s*(\d+)\s+discards)?[^\n]*\nFAILED'
        match = re.search(pattern, combined_output)

        bug_found = match is not None
        num_runs = None
        num_discards = None

        if bug_found:
            num_runs = int(match.group(1))
            # Group 2 is the discards (may be None if not present)
            if match.group(2):
                num_discards = int(match.group(2))

        return (bug_found, elapsed, num_runs, num_discards)

    except subprocess.TimeoutExpired:
        elapsed = time.time() - start_time
        # Timeout means no bug found within time limit
        return (False, elapsed, None, None)
    except Exception as e:
        print(f"\n  WARNING: Trial {trial_num} failed with exception: {e}")
        elapsed = time.time() - start_time
        return (False, elapsed, None, None)


def test_patch(patch_data: dict, num_trials: int = 10) -> dict:
    """
    Test a patch by applying it and running multiple trials.

    Args:
        patch_data: Dictionary with 'path' and 'fut' keys
        num_trials: Number of trials to run (default: 10)

    Returns:
        Dictionary with results including times, bug_found counts, etc.
    """
    patch_path = patch_data['path']
    function = patch_data['fut']

    # Apply the patch
    apply_patch(patch_path)

    # Run trials with nested progress bar
    bug_found_count = 0
    times = []
    runs_data = []  # List of runs for each successful detection
    discards_data = []  # List of discards for each successful detection

    with tqdm(total=num_trials, desc="    Trials", unit="trial", leave=False) as trial_pbar:
        for trial in range(1, num_trials + 1):
            bug_found, elapsed, num_runs, num_discards = run_trial(
                function, trial)

            if bug_found:
                bug_found_count += 1
                times.append(elapsed)

                # Store runs and discards data
                if num_runs is not None:
                    runs_data.append(num_runs)
                if num_discards is not None:
                    discards_data.append(num_discards)

            trial_pbar.set_postfix({
                "found": bug_found_count,
                "last": f"{elapsed:.2f}s"
            })
            trial_pbar.update(1)

    # Reset files to base version
    reset_files()

    # Calculate statistics (only for trials that found bugs)
    if times:
        avg_time = sum(times) / len(times)
        min_time = min(times)
        max_time = max(times)
    else:
        # No bugs found in any trial
        avg_time = math.nan
        min_time = math.nan
        max_time = math.nan

    # Calculate runs statistics
    if runs_data:
        avg_runs = sum(runs_data) / len(runs_data)
        min_runs = min(runs_data)
        max_runs = max(runs_data)
    else:
        avg_runs = math.nan
        min_runs = math.nan
        max_runs = math.nan

    # Calculate discards statistics
    if discards_data:
        avg_discards = sum(discards_data) / len(discards_data)
        min_discards = min(discards_data)
        max_discards = max(discards_data)
    else:
        avg_discards = math.nan
        min_discards = math.nan
        max_discards = math.nan

    return {
        'patch': patch_path,
        'function': function,
        'trials': num_trials,
        'bugs_found': bug_found_count,
        'detection_rate': bug_found_count / num_trials if num_trials > 0 else 0.0,
        'avg_time': avg_time,
        'min_time': min_time,
        'max_time': max_time,
        'all_times': times,
        # Runs statistics
        'avg_runs': avg_runs,
        'min_runs': min_runs,
        'max_runs': max_runs,
        'all_runs': runs_data,
        # Discards statistics
        'avg_discards': avg_discards,
        'min_discards': min_discards,
        'max_discards': max_discards,
        'all_discards': discards_data,
    }


def load_bug_finding_data() -> list[dict]:
    """
    Load the bug_finding.json file.

    Returns:
        List of dictionaries with 'path' and 'fut' keys

    Exits with error if file cannot be loaded.
    """
    try:
        with open('pbt_bench/bug_finding.json', 'r') as f:
            data = json.load(f)
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
    print("="*60)
    print("Property-Based Testing: Bug Finding Data Collection")
    print("="*60)
    print()

    # Checkout base version
    print("Checking out base version of src/alloc.c and specs/spec.c...")
    checkout_base_version()
    print("Base versions checked out")
    print()

    # Load patch data
    print("Loading bug_finding.json...")
    patches = load_bug_finding_data()
    print(f"Loaded {len(patches)} patches")
    print()

    # Test each patch
    results = []

    print("Running bug finding trials...")
    with tqdm(total=len(patches), desc="Patches", unit="patch") as patch_pbar:
        for i, patch_data in enumerate(patches, 1):
            function = patch_data['fut']

            patch_pbar.set_description(f"Patch {i}/{len(patches)}: {function}")

            result = test_patch(patch_data, num_trials=10)
            results.append(result)

            patch_pbar.set_postfix({
                "found": f"{result['bugs_found']}/10",
                "avg": f"{result['avg_time']:.2f}s"
            })
            patch_pbar.update(1)

    print()

    # Save to CSV
    csv_filename = 'pbt_bug_finding_data.csv'
    try:
        with open(csv_filename, 'w', newline='') as csvfile:
            fieldnames = ['patch', 'function', 'trials', 'bugs_found',
                          'detection_rate', 'avg_time', 'min_time', 'max_time', 'all_times',
                          'avg_runs', 'min_runs', 'max_runs', 'all_runs',
                          'avg_discards', 'min_discards', 'max_discards', 'all_discards']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(results)

        print("Data collection complete!")
        print(f"Results saved to: {csv_filename}")
        print(f"Total patches tested: {len(results)}")

        # Summary statistics
        total_bugs_found = sum(r['bugs_found'] for r in results)
        total_trials = sum(r['trials'] for r in results)
        overall_detection_rate = total_bugs_found / \
            total_trials if total_trials > 0 else 0.0

        print()
        print("="*60)
        print("Summary Statistics")
        print("="*60)
        print(f"Total trials: {total_trials}")
        print(f"Total bugs found: {total_bugs_found}")
        print(f"Overall detection rate: {overall_detection_rate:.2%}")

    except Exception as e:
        print(f"\nERROR: Failed to save CSV file: {e}")
        sys.exit(1)


if __name__ == '__main__':
    main()

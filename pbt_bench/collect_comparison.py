#!/usr/bin/env python3
"""
Data collection script for property-based testing benchmark.
Collects timing data for Bennet vs Darcy and saves to CSV.
"""

import argparse
import csv
import re
import subprocess
import sys
import time

try:
    import numpy as np
    from tqdm import tqdm
except ImportError:
    print("ERROR: This script requires numpy, and tqdm.")
    print("Install them with: pip install numpy tqdm")
    sys.exit(1)


def parse_test_failures(output: str) -> list[str]:
    """
    Parse test output to extract failure blocks.

    Returns:
        list of complete failure blocks (including "Testing" line and all details)
    """
    failures = []

    # Match pattern: "Testing <basename::function_name>: ..." followed by "FAILED"
    # Capture everything from "Testing" until the next "Testing" or end of output
    # Use [^\n]+ to match function name (greedy within the line, handles :: in names)
    pattern = r'(Testing\s+[^\n]+:[^\n]*\nFAILED\n.*?)(?=\nTesting|\Z)'

    matches = re.finditer(pattern, output, re.DOTALL)

    for match in matches:
        failure_block = match.group(1).strip()
        failures.append(failure_block)

    return failures


def extract_function_name(func_name: str) -> str:
    """
    Extract the function name from basename-prefixed format.

    Args:
        func_name: Function name (may have basename:: prefix)

    Returns:
        Function name without basename prefix
    """
    return func_name.split('::')[-1] if '::' in func_name else func_name


def select_benchmarks(should_fail: set[str], might_fail: set[str]) -> list[str]:
    """
    Run the full test suite and select which functions to benchmark.

    Args:
        should_fail: Set of function names that are expected to fail
        might_fail: Set of function names that might fail probabilistically

    Returns:
        List of function names to benchmark (excludes should-fail, might-fail, and unbenchmarkable functions)

    Exits with error if:
        - Expected failures don't fail (but might-fail can pass or fail without error)
        - Unexpected failures occur
    """
    print("Running full test suite with --progress-level=function...")

    try:
        result = subprocess.run(
            ['./test-random.sh', '--progress-level=function', '--num-samples=1000'],
            capture_output=True,
            text=True,
            timeout=3600  # 1 hour timeout
        )

        output = result.stdout + result.stderr

        # Parse function names from output
        # Look for "Testing <function_name>:" pattern
        # Match everything except newline up to : followed by space (handles :: in names)
        function_pattern = r'Testing\s+([^\n]+?):\s'
        functions = re.findall(function_pattern, output)

        # Remove basename:: prefix and duplicates while preserving order
        all_functions = list(dict.fromkeys(
            [extract_function_name(f) for f in functions]))

        # Parse actual failures
        failures = parse_test_failures(output)
        failed_functions = set()
        for failure in failures:
            # Match everything except newline up to : followed by space (handles :: in names)
            match = re.match(r'Testing\s+([^\n]+?):\s', failure)
            if match:
                func_name = match.group(1)
                # Remove basename:: prefix
                failed_functions.add(extract_function_name(func_name))

        # Parse functions that failed to generate valid input
        # Pattern: "Testing <function_name>: ... FAILED TO GENERATE VALID INPUT"
        input_gen_fail_pattern = r'Testing\s+([^\n]+?):\s[^\n]*\nFAILED TO GENERATE VALID INPUT'
        unbenchmarkable_raw = re.findall(input_gen_fail_pattern, output)
        # Remove basename:: prefix
        unbenchmarkable = set([extract_function_name(f)
                              for f in unbenchmarkable_raw])

        # Helper function to check if a function matches expected failures or might-fail
        def matches_category(func_name: str, category: set[str]) -> bool:
            return func_name in category

        # Categorize test results
        unexpected_successes = []
        unexpected_failures = []

        for func in all_functions:
            is_expected = matches_category(func, should_fail)
            is_might_fail = matches_category(func, might_fail)
            actually_failed = func in failed_functions

            # might-fail functions can pass or fail without error
            if is_might_fail:
                continue

            if is_expected and not actually_failed:
                unexpected_successes.append(func)
            elif not is_expected and actually_failed:
                unexpected_failures.append(func)

        # Report unexpected outcomes
        if unexpected_successes or unexpected_failures:
            if unexpected_successes:
                print(
                    f"\nERROR: {len(unexpected_successes)} function(s) were expected to fail but succeeded:")
                for func in unexpected_successes:
                    print(f"  - {func}")

            if unexpected_failures:
                print(
                    f"\nERROR: {len(unexpected_failures)} function(s) failed unexpectedly:")
                for func in unexpected_failures:
                    print(f"  - {func}")

            # Print failure details for context
            print("\n" + "="*60)
            print("FAILED: Test results did not match expectations")
            print("="*60)

            if failures:
                print(f"\n{len(failures)} test(s) failed:\n")
                for failure in failures:
                    print(failure)
                    print()
            else:
                print("\nFull test output:")
                print(output)

            sys.exit(1)

        # Build list of functions to benchmark
        # Exclude: expected failures, might-fail, and unbenchmarkable functions
        benchmarkable = []
        excluded_count = 0
        might_fail_count = 0

        for func in all_functions:
            if matches_category(func, should_fail):
                excluded_count += 1
                continue
            if matches_category(func, might_fail):
                might_fail_count += 1
                continue
            if func in unbenchmarkable:
                continue
            benchmarkable.append(func)

        print(f"\nAll tests behaved as expected!")
        print(f"Found {len(all_functions)} total functions:")
        print(f"  - {len(benchmarkable)} to benchmark")
        print(f"  - {excluded_count} expected to fail")
        if might_fail_count > 0:
            print(
                f"  - {might_fail_count} might fail (excluded from benchmarking)")
        print(
            f"  - {len(unbenchmarkable)} unbenchmarkable (failed to generate valid input)")

        return benchmarkable

    except subprocess.TimeoutExpired:
        print("ERROR: Test suite timed out after 1 hour")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: Failed to run test suite: {e}")
        sys.exit(1)


def time_bennet(function: str, num_trials: int = 10) -> list[float]:
    """
    Time how long Bennet (random testing) takes to test a specific function.

    Args:
        function: Function name to test (without basename:: prefix)
        num_trials: Number of trials to run (default: 10)

    Returns:
        List of times in seconds, one per trial

    Exits with error if any test fails
    """
    times = []

    with tqdm(total=num_trials, desc=f"  Bennet: {function}", unit="trial") as pbar:
        for trial in range(1, num_trials + 1):
            start_time = time.time()

            try:
                result = subprocess.run(
                    ['./test-random.sh', f'--only={function}',
                        '--exit-fast', '--no-replicas', '--no-replays'],
                    capture_output=True,
                    text=True,
                    timeout=3600
                )

                elapsed = time.time() - start_time

                if result.returncode != 0:
                    pbar.close()
                    print(f"\n{'='*60}")
                    print(
                        f"ERROR: Bennet test failed for function '{function}' (trial {trial})")
                    print(f"{'='*60}")
                    print(f"Exit code: {result.returncode}")
                    print(f"\nOutput:")
                    print(result.stdout)
                    if result.stderr:
                        print(f"\nStderr:")
                        print(result.stderr)
                    sys.exit(1)

                times.append(elapsed)
                pbar.set_postfix({"last": f"{elapsed:.3f}s"})
                pbar.update(1)

            except subprocess.TimeoutExpired:
                pbar.close()
                print(
                    f"\nERROR: Bennet test timed out for function '{function}' (trial {trial}) after 1 hour")
                sys.exit(1)
            except Exception as e:
                pbar.close()
                print(
                    f"\nERROR: Bennet test failed for '{function}' (trial {trial}): {e}")
                sys.exit(1)

    return times


def time_darcy(function: str, num_trials: int = 10) -> list[float]:
    """
    Time how long Darcy (symbolic testing) takes to test a specific function.

    Args:
        function: Function name to test (without basename:: prefix)
        num_trials: Number of trials to run (default: 10)

    Returns:
        List of times in seconds, one per trial

    Exits with error if any test fails
    """
    times = []

    with tqdm(total=num_trials, desc=f"  Darcy:  {function}", unit="trial") as pbar:
        for trial in range(1, num_trials + 1):
            start_time = time.time()

            try:
                result = subprocess.run(
                    ['./test-symbolic.sh', f'--only={function}',
                        '--exit-fast', '--no-replicas', '--no-replays'],
                    capture_output=True,
                    text=True,
                    timeout=3600
                )

                elapsed = time.time() - start_time

                if result.returncode != 0:
                    pbar.close()
                    print(f"\n{'='*60}")
                    print(
                        f"ERROR: Darcy test failed for function '{function}' (trial {trial})")
                    print(f"{'='*60}")
                    print(f"Exit code: {result.returncode}")
                    print(f"\nOutput:")
                    print(result.stdout)
                    if result.stderr:
                        print(f"\nStderr:")
                        print(result.stderr)
                    sys.exit(1)

                times.append(elapsed)
                pbar.set_postfix({"last": f"{elapsed:.3f}s"})
                pbar.update(1)

            except subprocess.TimeoutExpired:
                pbar.close()
                print(
                    f"\nERROR: Darcy test timed out for function '{function}' (trial {trial}) after 1 hour")
                sys.exit(1)
            except Exception as e:
                pbar.close()
                print(
                    f"\nERROR: Darcy test failed for '{function}' (trial {trial}): {e}")
                sys.exit(1)

    return times


def parse_args():
    """Parse command-line arguments."""
    parser = argparse.ArgumentParser(
        description="Collect timing data for Bennet (random testing) vs Darcy (symbolic testing).",
        formatter_class=argparse.RawDescriptionHelpFormatter
    )

    parser.add_argument(
        '--should-fail',
        action='append',
        metavar='FUNC1,FUNC2,...',
        help='Comma-separated list of function names expected to fail. Can be used multiple times.'
    )

    parser.add_argument(
        '--might-fail',
        action='append',
        metavar='FUNC1,FUNC2,...',
        help='Comma-separated list of function names that fail flakily. Can be used multiple times. '
             'These functions will be excluded from benchmarking but won\'t cause errors regardless of pass/fail status.'
    )

    parser.add_argument(
        '--trials',
        type=int,
        default=10,
        metavar='N',
        help='Number of trials to run for each test (default: 10)'
    )

    return parser.parse_args()


def main():
    """Main entry point for data collection."""
    args = parse_args()

    # Process --should-fail arguments
    should_fail = set()
    if args.should_fail:
        for func_list in args.should_fail:
            funcs = [f.strip() for f in func_list.split(',') if f.strip()]
            should_fail.update(funcs)

    # Process --might-fail arguments
    might_fail = set()
    if args.might_fail:
        for func_list in args.might_fail:
            funcs = [f.strip() for f in func_list.split(',') if f.strip()]
            might_fail.update(funcs)

    print("="*60)
    print("Property-Based Testing Benchmark: Data Collection")
    print("="*60)

    if should_fail:
        print(f"\nExpected failures: {', '.join(sorted(should_fail))}")
    if might_fail:
        print(f"Might fail: {', '.join(sorted(might_fail))}")
    print()

    # Select functions to benchmark
    functions_to_benchmark = select_benchmarks(should_fail, might_fail)
    print(f"Functions to benchmark: {', '.join(functions_to_benchmark)}")
    print()

    # Benchmark each function
    results = []

    for i, function in enumerate(functions_to_benchmark, 1):
        print(f"\n[{i}/{len(functions_to_benchmark)}] Benchmarking {function}...")

        bennet_times = time_bennet(function, num_trials=args.trials)
        darcy_times = time_darcy(function, num_trials=args.trials)

        bennet_mean = np.mean(bennet_times)
        darcy_mean = np.mean(darcy_times)

        result = {
            'function': function,
            'bennet_times': bennet_times,
            'darcy_times': darcy_times,
            'bennet_mean': bennet_mean,
            'darcy_mean': darcy_mean,
            'ratio': darcy_mean / bennet_mean if bennet_mean > 0 else float('inf')
        }
        results.append(result)

        print(
            f"  Bennet: {bennet_mean:.3f}s | Darcy: {darcy_mean:.3f}s | Ratio: {result['ratio']:.2f}x")

    # Save to CSV
    csv_filename = 'pbt_comparison_data.csv'
    try:
        with open(csv_filename, 'w', newline='') as csvfile:
            fieldnames = ['function', 'bennet_times', 'darcy_times',
                          'bennet_mean', 'darcy_mean', 'ratio']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(results)
        print(f"\nData collection complete!")
        print(f"Results saved to: {csv_filename}")
        print(f"Total functions benchmarked: {len(results)}")
    except Exception as e:
        print(f"\nERROR: Failed to save CSV file: {e}")
        sys.exit(1)


if __name__ == '__main__':
    main()

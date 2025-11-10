#!/usr/bin/env python3
"""
Analysis script for property-based testing benchmark results.
Reads CSV data and performs statistical analysis.
"""

import ast
import csv
import sys
from typing import Any

try:
    import numpy as np
    from scipy import stats
except ImportError:
    print("ERROR: This script requires scipy and numpy.")
    print("Install them with: pip install scipy numpy")
    sys.exit(1)


def load_results_from_csv(filename: str = 'pbt_comparison_results.csv') -> list[dict[str, Any]]:
    """
    Load benchmark results from CSV file.

    Args:
        filename: Path to CSV file

    Returns:
        List of dictionaries with timing data
    """
    results = []

    try:
        with open(filename, 'r', newline='') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                # Parse the list strings back into Python lists
                results.append({
                    'function': row['function'],
                    'bennet_times': ast.literal_eval(row['bennet_times']),
                    'darcy_times': ast.literal_eval(row['darcy_times']),
                })
    except FileNotFoundError:
        print(f"ERROR: File '{filename}' not found.")
        print("Please run data collection first with collect_comparison.py")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: Failed to read CSV file: {e}")
        sys.exit(1)

    return results


def analyze_data(results: list[dict[str, Any]]) -> None:
    """
    Analyze the benchmark results using Mann-Whitney U test.

    Args:
        results: List of dictionaries containing timing data for each function.
                 Each dict should have:
                 - 'function': function name
                 - 'bennet_times': list of trial times for Bennet
                 - 'darcy_times': list of trial times for Darcy
    """
    if not results:
        print("No results to analyze.")
        return

    print("\n" + "="*80)
    print("STATISTICAL ANALYSIS (Mann-Whitney U Test, α=0.01, two-tailed)")
    print("="*80)

    # Prepare data for CSV export
    csv_rows = []
    slowdowns = []

    # Print header
    print(f"\n{'Function':<30} {'Bennet Mean':<12} {'Darcy Mean':<12} {'Slowdown':<10} {'P-value':<10} {'Sig?':<5}")
    print("-" * 90)

    significant_count = 0

    for result in results:
        func_name = result['function']
        bennet_times = result['bennet_times']
        darcy_times = result['darcy_times']

        # Calculate statistics
        bennet_mean = np.mean(bennet_times)
        bennet_median = np.median(bennet_times)
        bennet_std = np.std(bennet_times, ddof=1)  # Sample std dev

        darcy_mean = np.mean(darcy_times)
        darcy_median = np.median(darcy_times)
        darcy_std = np.std(darcy_times, ddof=1)  # Sample std dev

        # Calculate slowdown (Darcy / Bennet)
        slowdown = darcy_mean / bennet_mean
        slowdowns.append(slowdown)

        # Perform Mann-Whitney U test (two-tailed)
        statistic, p_value = stats.mannwhitneyu(
            bennet_times, darcy_times, alternative='two-sided')

        # Check significance at α=0.01
        is_significant = p_value < 0.01
        if is_significant:
            significant_count += 1

        # Print row
        sig_marker = "✓" if is_significant else ""
        print(f"{func_name:<30} {bennet_mean:>10.3f}s {darcy_mean:>10.3f}s {slowdown:>8.2f}x {p_value:>9.6f} {sig_marker:<5}")

        # Add to CSV data
        csv_rows.append({
            'function': func_name,
            'bennet_mean': bennet_mean,
            'bennet_median': bennet_median,
            'bennet_std': bennet_std,
            'darcy_mean': darcy_mean,
            'darcy_median': darcy_median,
            'darcy_std': darcy_std,
            'slowdown': slowdown,
            'p_value': p_value,
            'significant_at_0.01': is_significant,
            'u_statistic': statistic,
            'bennet_times': bennet_times,
            'darcy_times': darcy_times
        })

    print("-" * 90)
    print(
        f"\nSignificant differences found: {significant_count}/{len(results)} functions")

    # Calculate and display geometric mean of slowdowns
    if slowdowns:
        geom_mean_slowdown = stats.gmean(slowdowns)
        print(f"Geometric mean slowdown (Darcy/Bennet): {geom_mean_slowdown:.2f}x")

        # Print LaTeX-formatted slowdown data
        latex_slowdowns = "\\\\".join(f"{s:.2f}" for s in slowdowns)
        print(f"LaTeX slowdown data: {latex_slowdowns}")

    # Calculate box plot statistics across all functions
    if csv_rows:
        bennet_means = np.array([row['bennet_mean'] for row in csv_rows])
        darcy_means = np.array([row['darcy_mean'] for row in csv_rows])

        print("\n" + "="*80)
        print("BOX PLOT STATISTICS ACROSS ALL FUNCTIONS")
        print("="*80)

        print(f"\n{'Metric':<15} {'Min':<10} {'Q1':<10} {'Median':<10} {'Q3':<10} {'Max':<10} {'IQR':<10} {'Mean':<10}")
        print("-" * 90)

        # Bennet statistics
        bennet_min = np.min(bennet_means)
        bennet_q1 = np.percentile(bennet_means, 25)
        bennet_median = np.median(bennet_means)
        bennet_q3 = np.percentile(bennet_means, 75)
        bennet_max = np.max(bennet_means)
        bennet_iqr = bennet_q3 - bennet_q1
        bennet_mean_of_means = np.mean(bennet_means)

        print(f"{'Bennet (s)':<15} {bennet_min:<10.3f} {bennet_q1:<10.3f} {bennet_median:<10.3f} {bennet_q3:<10.3f} {bennet_max:<10.3f} {bennet_iqr:<10.3f} {bennet_mean_of_means:<10.3f}")

        # Darcy statistics
        darcy_min = np.min(darcy_means)
        darcy_q1 = np.percentile(darcy_means, 25)
        darcy_median = np.median(darcy_means)
        darcy_q3 = np.percentile(darcy_means, 75)
        darcy_max = np.max(darcy_means)
        darcy_iqr = darcy_q3 - darcy_q1
        darcy_mean_of_means = np.mean(darcy_means)

        print(f"{'Darcy (s)':<15} {darcy_min:<10.3f} {darcy_q1:<10.3f} {darcy_median:<10.3f} {darcy_q3:<10.3f} {darcy_max:<10.3f} {darcy_iqr:<10.3f} {darcy_mean_of_means:<10.3f}")
        print("-" * 90)

    # Save CSV file
    csv_filename = 'pbt_comparison_results.csv'
    try:
        with open(csv_filename, 'w', newline='') as csvfile:
            fieldnames = ['function', 'bennet_mean', 'bennet_median', 'bennet_std',
                          'darcy_mean', 'darcy_median', 'darcy_std', 'slowdown',
                          'p_value', 'significant_at_0.01', 'u_statistic',
                          'bennet_times', 'darcy_times']
            writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(csv_rows)
        print(f"\nDetailed results saved to: {csv_filename}")
    except Exception as e:
        print(f"\nWarning: Failed to save CSV file: {e}")


def main():
    """Main entry point for analysis."""
    print("="*60)
    print("Property-Based Testing Benchmark: Analysis")
    print("="*60)
    print()

    # Load data from CSV
    results = load_results_from_csv('pbt_comparison_data.csv')

    if not results:
        print("No results found in CSV file.")
        sys.exit(1)

    print(f"Loaded data for {len(results)} functions.")

    # Analyze the data
    analyze_data(results)

    print("\nDone!")


if __name__ == '__main__':
    main()

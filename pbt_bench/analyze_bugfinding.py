#!/usr/bin/env python3
"""
Bug finding analysis script for property-based testing benchmark.
Analyzes trial-level data from pbt_bug_finding_data_{mode}.csv and generates statistics.
"""

import argparse
import csv
import math
import sys
from collections import defaultdict


def load_trial_data(filename: str) -> list[dict]:
    """
    Load trial-level data from CSV file.

    Args:
        filename: Path to the CSV file

    Returns:
        List of dictionaries containing trial data

    Exits with error if file cannot be loaded.
    """
    try:
        with open(filename, 'r') as f:
            reader = csv.DictReader(f)
            data = list(reader)
        return data
    except FileNotFoundError:
        print(f"ERROR: {filename} not found")
        print("Run collect_bugfinding.py first to generate the data")
        sys.exit(1)
    except Exception as e:
        print(f"ERROR: Failed to load {filename}: {e}")
        sys.exit(1)


def analyze_trials(trial_data: list[dict]) -> tuple[list[dict], dict]:
    """
    Analyze trial-level data and compute aggregated statistics.

    Args:
        trial_data: List of trial result dictionaries

    Returns:
        Tuple of (patch_statistics, overall_statistics)
        - patch_statistics: List of dicts with stats for each patch
        - overall_statistics: Dict with overall summary stats
    """
    # Group trials by patch
    patch_groups = defaultdict(list)
    for trial in trial_data:
        patch_key = (trial['patch'], trial['function'])
        patch_groups[patch_key].append(trial)

    # Calculate statistics for each patch
    patch_stats = []
    for (patch_path, function), trials in sorted(patch_groups.items()):
        # Extract data from trials
        num_trials = len(trials)
        bugs_found = sum(1 for t in trials if t['bug_found'] == 'True')

        # Times for successful detections only
        success_times = [float(t['elapsed_time'])
                         for t in trials if t['bug_found'] == 'True']

        # Runs and discards for all trials
        runs_data = [int(t['num_runs']) for t in trials
                     if t['num_runs'] != '']
        discards_data = [int(t['num_discards']) for t in trials
                         if t['num_discards'] != '']

        # Calculate time statistics
        if success_times:
            avg_time = sum(success_times) / len(success_times)
            min_time = min(success_times)
            max_time = max(success_times)
        else:
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

        patch_stats.append({
            'patch': patch_path,
            'function': function,
            'trials': num_trials,
            'bugs_found': bugs_found,
            'detection_rate': bugs_found / num_trials if num_trials > 0 else 0.0,
            'avg_time': avg_time,
            'min_time': min_time,
            'max_time': max_time,
            'avg_runs': avg_runs,
            'min_runs': min_runs,
            'max_runs': max_runs,
            'avg_discards': avg_discards,
            'min_discards': min_discards,
            'max_discards': max_discards,
        })

    # Calculate overall statistics
    total_trials = sum(p['trials'] for p in patch_stats)
    total_bugs_found = sum(p['bugs_found'] for p in patch_stats)
    overall_detection_rate = total_bugs_found / \
        total_trials if total_trials > 0 else 0.0

    # Overall time statistics (across all successful detections)
    all_success_times = [float(t['elapsed_time'])
                         for t in trial_data if t['bug_found'] == 'True']
    if all_success_times:
        overall_avg_time = sum(all_success_times) / len(all_success_times)
        overall_min_time = min(all_success_times)
        overall_max_time = max(all_success_times)
    else:
        overall_avg_time = math.nan
        overall_min_time = math.nan
        overall_max_time = math.nan

    overall_stats = {
        'total_patches': len(patch_stats),
        'total_trials': total_trials,
        'total_bugs_found': total_bugs_found,
        'detection_rate': overall_detection_rate,
        'avg_time': overall_avg_time,
        'min_time': overall_min_time,
        'max_time': overall_max_time,
    }

    return patch_stats, overall_stats


def print_report(patch_stats: list[dict], overall_stats: dict, individual: bool = False):
    """
    Print a formatted analysis report to console.

    Args:
        patch_stats: List of per-patch statistics
        overall_stats: Overall summary statistics
    """
    print("=" * 80)
    print("Bug Finding Analysis Report")
    print("=" * 80)
    print()

    # Overall summary
    print("Overall Summary:")
    print(f"  Total patches:       {overall_stats['total_patches']}")
    print(f"  Total trials:        {overall_stats['total_trials']}")
    print(f"  Total bugs found:    {overall_stats['total_bugs_found']}")
    print(f"  Detection rate:      {overall_stats['detection_rate']:.2%}")
    if not math.isnan(overall_stats['avg_time']):
        print(f"  Avg detection time:  {overall_stats['avg_time']:.2f}s")
        print(f"  Min detection time:  {overall_stats['min_time']:.2f}s")
        print(f"  Max detection time:  {overall_stats['max_time']:.2f}s")
    print()

    if not individual:
        return

    # Per-patch details
    print("=" * 80)
    print("Per-Patch Statistics:")
    print("=" * 80)
    print()

    for stat in patch_stats:
        print(f"Patch: {stat['patch']}")
        print(f"  Function:        {stat['function']}")
        print(f"  Trials:          {stat['trials']}")
        print(f"  Bugs found:      {stat['bugs_found']}")
        print(f"  Detection rate:  {stat['detection_rate']:.2%}")

        if not math.isnan(stat['avg_time']):
            print(
                f"  Avg time:        {stat['avg_time']:.2f}s (min: {stat['min_time']:.2f}s, max: {stat['max_time']:.2f}s)")

        if not math.isnan(stat['avg_runs']):
            print(
                f"  Avg runs:        {stat['avg_runs']:.1f} (min: {stat['min_runs']}, max: {stat['max_runs']})")

        if not math.isnan(stat['avg_discards']):
            print(
                f"  Avg discards:    {stat['avg_discards']:.1f} (min: {stat['min_discards']}, max: {stat['max_discards']})")

        print()


def save_summary_csv(patch_stats: list[dict], filename: str = 'pbt_bug_finding_summary.csv'):
    """
    Save aggregated patch statistics to a CSV file.

    Args:
        patch_stats: List of per-patch statistics
        filename: Output CSV filename
    """
    try:
        with open(filename, 'w', newline='') as f:
            fieldnames = ['patch', 'function', 'trials', 'bugs_found', 'detection_rate',
                          'avg_time', 'min_time', 'max_time',
                          'avg_runs', 'min_runs', 'max_runs',
                          'avg_discards', 'min_discards', 'max_discards']
            writer = csv.DictWriter(f, fieldnames=fieldnames)
            writer.writeheader()
            writer.writerows(patch_stats)
        print(f"Summary statistics saved to: {filename}")
    except Exception as e:
        print(f"ERROR: Failed to save summary CSV: {e}")
        sys.exit(1)


def analyze_mode(mode: str, individual: bool = False):
    """
    Load, analyze, and report on a single mode's data.

    Args:
        mode: Testing mode ('symbolic' or 'random')
    """
    csv_filename = f'pbt_bug_finding_data_{mode}.csv'
    summary_filename = f'pbt_bug_finding_summary_{mode}.csv'

    print(f"\n{'='*60}")
    print(f"Analyzing {mode} mode: {csv_filename}")
    print(f"{'='*60}\n")

    trial_data = load_trial_data(csv_filename)

    if not trial_data:
        print(f"ERROR: No trial data found in {csv_filename}")
        sys.exit(1)

    patch_stats, overall_stats = analyze_trials(trial_data)
    print_report(patch_stats, overall_stats, individual=individual)
    save_summary_csv(patch_stats, filename=summary_filename)


def main():
    """Main entry point for bug finding analysis."""
    parser = argparse.ArgumentParser(
        description='Bug finding analysis script for property-based testing benchmark.'
    )
    parser.add_argument('--mode', choices=['symbolic', 'random', 'both'],
                        default='both',
                        help='Testing mode: symbolic, random, or both (default: both)')
    parser.add_argument('--individual', action='store_true',
                        help='Print per-patch individual results')
    args = parser.parse_args()

    if args.mode == 'both':
        modes = ['symbolic', 'random']
    else:
        modes = [args.mode]

    for mode in modes:
        analyze_mode(mode, individual=args.individual)


if __name__ == '__main__':
    main()

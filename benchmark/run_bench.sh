#!/bin/sh
# Usage: ./benchmark/run_bench.sh <script>

set -e

NUM_BENCHMARKS=$(python3 -c "import json; print(len(json.load(open('pbt_bench/bug_finding.json'))))")

for i in $(seq 1 "$NUM_BENCHMARKS"); do
    ./benchmark/switch_to.sh "$i"
    "$1" "$i"
done

#!/bin/sh
# Usage: ./benchmark/run_correct_partial_spec.sh <script>

set -e

PARTIAL_SPEC_JSON="benchmark/partial_spec.json"
NUM_BENCHMARKS=$(python3 -c "import json; print(len(json.load(open('$PARTIAL_SPEC_JSON'))))")

for i in $(seq 1 "$NUM_BENCHMARKS"); do
    ./benchmark/switch_to.sh "$i" "$PARTIAL_SPEC_JSON"
    "$1" "$i"
done

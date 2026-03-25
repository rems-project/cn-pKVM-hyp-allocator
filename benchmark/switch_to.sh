#!/usr/bin/env bash
# switch_to.sh <benchmark_number>
#
# Switches the working tree to a specific benchmark by:
#   1. Restoring src/alloc.c, src/shim.c, specs/spec.c to the base commit
#   2. Applying the workaround patch
#   3. Applying the benchmark's patch
#
# Benchmark numbers are 1-indexed, as listed in benchmark/README.md.

set -euo pipefail

BASE_COMMIT="b391f721fe71b8682a7e1752375c5c1bef936491"
BUG_FINDING_JSON="pbt_bench/bug_finding.json"
WORKAROUND_PATCH="patches/workaround.patch"

usage() {
    echo "Usage: $0 <benchmark_number>"
    echo ""
    echo "Switches to the specified benchmark (1-indexed)."
    echo "See benchmark/README.md for the full list."
    exit 1
}

if [[ $# -ne 1 ]]; then
    usage
fi

BENCH_NUM="$1"

if ! [[ "$BENCH_NUM" =~ ^[0-9]+$ ]]; then
    echo "ERROR: benchmark_number must be a positive integer, got: '$BENCH_NUM'" >&2
    exit 1
fi

# Parse the JSON to get the Nth entry (1-indexed)
ENTRY=$(python3 -c "
import json, sys
with open('$BUG_FINDING_JSON') as f:
    data = json.load(f)
n = $BENCH_NUM - 1
if n < 0 or n >= len(data):
    print(f'ERROR: benchmark number $BENCH_NUM out of range (1-{len(data)})', file=sys.stderr)
    sys.exit(1)
e = data[n]
print(e['path'])
")

PATCH_PATH=$(echo "$ENTRY")

git checkout "$BASE_COMMIT" -- src/alloc.c src/shim.c specs/spec.c
git apply "$WORKAROUND_PATCH"
git apply "$PATCH_PATH"


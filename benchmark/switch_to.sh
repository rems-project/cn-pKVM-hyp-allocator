#!/usr/bin/env bash
# Usage: ./benchmark/switch_to.sh <benchmark_number>

set -euo pipefail

BASE_COMMIT="b391f721fe71b8682a7e1752375c5c1bef936491"
BUG_FINDING_JSON="pbt_bench/bug_finding.json"
WORKAROUND_PATCH="patches/workaround.patch"

BENCH_NUM="$1"

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
print(e['fut'])
print(e.get('found', False))
print(' '.join(e.get('args', [])))
")

PATCH_PATH=$(echo "$ENTRY" | sed -n '1p')

git checkout "$BASE_COMMIT" -- src/alloc.c src/shim.c specs/spec.c
git apply "$WORKAROUND_PATCH"
git apply "$PATCH_PATH"

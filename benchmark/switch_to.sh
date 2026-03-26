#!/usr/bin/env bash
# Usage: ./benchmark/switch_to.sh <benchmark_number> [json_file]

set -euo pipefail

BASE_COMMIT="b391f721fe71b8682a7e1752375c5c1bef936491"
JSON_FILE="${2:-pbt_bench/bug_finding.json}"
WORKAROUND_PATCH="patches/workaround.patch"

BENCH_NUM="$1"

ENTRY=$(python3 -c "
import json, sys
with open('$JSON_FILE') as f:
    data = json.load(f)
n = $BENCH_NUM - 1
if n < 0 or n >= len(data):
    print(f'ERROR: benchmark number $BENCH_NUM out of range (1-{len(data)})', file=sys.stderr)
    sys.exit(1)
e = data[n]
print(e['path'])
")

PATCH_PATH=$(echo "$ENTRY")

git checkout "$BASE_COMMIT" -- src/alloc.c src/main.c src/shim.c specs/spec.c include/linux/list.h
git apply "$WORKAROUND_PATCH"
git apply "$PATCH_PATH"

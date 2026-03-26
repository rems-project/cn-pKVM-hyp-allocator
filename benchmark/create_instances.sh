#!/usr/bin/env bash
# Creates per-instance source directories for supplementary material.
#
# For each benchmark in pbt_bench/bug_finding.json and benchmark/partial_spec.json,
# applies base commit + workaround + instance patch, then copies the patched files
# to benchmark/buggy/<patch-name>/ or benchmark/partial/<patch-name>/.
#
# The patched files copied are those that appear in both switch_to.sh and
# create_tarball.sh: src/alloc.c, src/shim.c, specs/spec.c, include/linux/list.h

set -euo pipefail

REPO_ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
BASE_COMMIT="b391f721fe71b8682a7e1752375c5c1bef936491"
WORKAROUND_PATCH="$REPO_ROOT/patches/workaround.patch"

# Files patched by switch_to.sh (needed in the worktree reset)
PATCHED_FILES_IN_WORKTREE="src/alloc.c src/main.c src/shim.c specs/spec.c include/linux/list.h"

# Subset of above that also appear in create_tarball.sh (what we actually copy)
TARBALL_PATCHED_FILES="src/alloc.c src/shim.c specs/spec.c include/linux/list.h"

DEST_BUGGY="$REPO_ROOT/benchmark/buggy"
DEST_PARTIAL="$REPO_ROOT/benchmark/partial"

# Create a temporary git worktree at BASE_COMMIT
WORKTREE=$(mktemp -d)
echo "Creating worktree at $WORKTREE ..."
git -C "$REPO_ROOT" worktree add --detach "$WORKTREE" "$BASE_COMMIT" 2>/dev/null
cleanup() {
    git -C "$REPO_ROOT" worktree remove --force "$WORKTREE" 2>/dev/null || true
    rm -rf "$WORKTREE"
}
trap cleanup EXIT

process_instance() {
    local json_file="$1"
    local dest_base="$2"
    local bench_num="$3"

    local patch_path
    patch_path=$(python3 -c "
import json, sys
with open('$json_file') as f:
    data = json.load(f)
n = $bench_num - 1
if n < 0 or n >= len(data):
    print('out of range', file=sys.stderr); sys.exit(1)
print(data[n]['path'])
")

    local patch_name
    patch_name=$(basename "$patch_path")
    local dest="$dest_base/$patch_name"

    echo "  [$bench_num] $patch_name"

    # Reset patched files in worktree back to BASE_COMMIT state
    git -C "$WORKTREE" checkout HEAD -- $PATCHED_FILES_IN_WORKTREE

    # Apply workaround, then the instance-specific patch
    git -C "$WORKTREE" apply "$WORKAROUND_PATCH"
    git -C "$WORKTREE" apply "$REPO_ROOT/$patch_path"

    # Copy patched files to destination
    for f in $TARBALL_PATCHED_FILES; do
        mkdir -p "$dest/$(dirname "$f")"
        cp "$WORKTREE/$f" "$dest/$f"
    done
}

mkdir -p "$DEST_BUGGY" "$DEST_PARTIAL"

echo "=== Buggy specification benchmarks ==="
BUG_JSON="$REPO_ROOT/pbt_bench/bug_finding.json"
total=$(python3 -c "import json; print(len(json.load(open('$BUG_JSON'))))")
for i in $(seq 1 "$total"); do
    process_instance "$BUG_JSON" "$DEST_BUGGY" "$i"
done

echo "=== Partial specification benchmarks ==="
PARTIAL_JSON="$REPO_ROOT/benchmark/partial_spec.json"
total=$(python3 -c "import json; print(len(json.load(open('$PARTIAL_JSON'))))")
for i in $(seq 1 "$total"); do
    process_instance "$PARTIAL_JSON" "$DEST_PARTIAL" "$i"
done

echo ""
echo "Done. Instance directories:"
echo "  $DEST_BUGGY"
echo "  $DEST_PARTIAL"

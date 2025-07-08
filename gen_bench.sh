#!/bin/bash
set -euo pipefail

mkdir -p efficiency-experiments
cd efficiency-experiments

FULMINATE_BASE=fulminate-exp-base

cd ..

while IFS= read -r line; do
    [[ -z "$line" ]] && continue
    [[ "$line" =~ ^# ]] && continue

    IFS=',' read -r commit_hash func_name cn_branch_and_comment <<< "$line"

    if [[ -n "${cn_branch_and_comment:-}" ]]; then
        cn_branch="${cn_branch_and_comment%%;*}"
        cn_branch="${cn_branch// /}"
    else
        cn_branch=""
    fi

    echo "Processing: $commit_hash ($func_name)"

    fulm_branch="fulminate-exp-$commit_hash"
    patch_base="efficiency-experiments/$commit_hash"

    echo "  Fulminate: $fulm_branch"
    git checkout "$fulm_branch"
    git diff "$FULMINATE_BASE" > "$patch_base.fulminate.patch"

    if [[ -n "$cn_branch" ]]; then
        echo "  CN       : $cn_branch"
        git checkout "$cn_branch"
        git diff "$FULMINATE_BASE" > "$patch_base.cn.patch"
    else
        echo "  CN       : no CN branch specified, using Fulminate branch"
        git checkout "$fulm_branch"
        git diff "$FULMINATE_BASE" > "$patch_base.cn.patch"
    fi


done < efficiency-experiments/benchmark.txt


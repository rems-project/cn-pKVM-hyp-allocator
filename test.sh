#!/bin/bash

JOBS=${1:-1}

targets=(
  chunk_unmapped_size
  setup_first_chunk
  chunk_inc_map
  list_add
  __list_add
)

run_test() {
  target="$1"
  if make ONLY="$target" cn-verify 2> /dev/null | tee "verify-${target}.log"; then
    if grep -q "\[1/1\]: $target -- pass" "verify-${target}.log"; then
      echo "$target passed"
    else
      echo "$target failed verification"
      exit 1
    fi
  else
    echo "failed for $target"
    exit 1
  fi
}

export -f run_test

printf "%s\n" "${targets[@]}" | xargs -n1 -P "$JOBS" bash -c 'run_test "$@"' _

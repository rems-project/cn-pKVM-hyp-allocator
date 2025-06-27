#!/bin/bash

JOBS=${1:-1}

# chunk_list_insert and LemmaCreateNewChunk should be very heavy
targets=(
  chunk_unmapped_size
  setup_first_chunk
  chunk_inc_map
  list_add
  __list_add
  chunk_get_next
  chunk_can_split
  chunk_hash_update
  chunk_addr_fixup
  chunk_get
  __chunk_next
  chunk_get_prev
  __chunk_prev
  LemmaNextChunk
  LemmaPrevChunk
  chunk_list_insert
  LemmaCreateNewChunk
  LemmaCreateNewChunkAux
)

run_test() {
  target="$1"
  start=$(date +%s.%N)

  if make ONLY="$target" cn-verify OPT="-p 20" > "verify-${target}.log" 2>/dev/null &&
     grep -q "\[1/1\]: $target -- pass" "verify-${target}.log"; then
    status="passed"
  else
    if grep -q "\[1/1\]: $target -- pass" "verify-${target}.log"; then
      status="failed verification"
    else
      status="failed"
    fi
  fi

  end=$(date +%s.%N)
  elapsed=$(echo "$end - $start" | bc)
  echo "$target $status (in ${elapsed}s)"

  [[ $status != "passed" ]] && exit 1
}

export -f run_test

printf "%s\n" "${targets[@]}" | xargs -n1 -P "$JOBS" bash -c 'run_test "$@"' _

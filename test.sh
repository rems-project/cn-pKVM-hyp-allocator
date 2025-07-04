#!/bin/bash

JOBS=${1:-1}

# CN cannot prove?
# chunk_hash_compute
# chunk_list_insert and LemmaCreateNewChunk should be very heavy
targets=(
  min_u32
  min_u64
  max_u64
  list_empty
  INIT_LIST_HEAD
  list_is_first
  list_is_last
  __list_del
  __list_del_entry
  list_del
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
  LemmaSplitAndNewChunk
  chunk_needs_mapping
  chunk_install
  get_free_chunk
  chunk_recycle
  hyp_alloc
  LemmaGetLastChunk
  LemmaLsegToChunkHdrs
  LemmaConcatCnChunkHdrsRev
  LemmaCnChunkHdrsRevToCnChunkHdrs
  LemmaCnChunkHdrsRevToCnHypAllocator
)
# unproved: chunk_install, get_free_hunk, chunk_recycle, hyp_alloc

run_test() {
  target="$1"
  start=$(date +%s.%N)
  opt="-p 20"

  if make ONLY="$target" cn-verify OPT="$opt" > "verify-${target}.log" 2>&1  &&
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

  RED='\033[0;31m'
  GREEN='\033[0;32m'
  NC='\033[0m'

  if [[ $status == "passed" ]]; then
    echo -e "$target ${GREEN}$status${NC} (in ${elapsed}s)"
  else
    echo -e "$target ${RED}$status${NC} (in ${elapsed}s)"
  fi

  [[ $status != "passed" ]] && exit 1
}

date
git log -1 --format="%H"
cn --version

export -f run_test

printf "%s\n" "${targets[@]}" | xargs -n1 -P "$JOBS" bash -c 'run_test "$@"' _

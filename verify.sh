#!/bin/bash

JOBS=${1:-1}

targets=(
  min_u32
  min_u64
  max_u64
  pkvm_remove_mappings
  hyp_phys_to_virt
  hyp_virt_to_phys
  push_hyp_memcache
  pop_hyp_memcache
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
  chunk_hash_compute
  chunk_hash_validate
  chunk_addr_fixup
  chunk_get
  __chunk_next
  chunk_get_prev
  __chunk_prev
  LemmaNextChunk
  LemmaPrevChunk
  LemmaFirstChunkToAllocator
  chunk_list_insert
  LemmaCreateNewChunk
  LemmaCreateNewChunkAux
  LemmaSplitAndNewChunk
  chunk_needs_mapping
  chunk_split_aligned
  chunk_install
  get_free_chunk
  chunk_recycle
  hyp_allocator_unmap
  hyp_allocator_map
  hyp_alloc
  LemmaGetLastChunk
  LemmaLsegToChunkHdrs
  LemmaConcatCnChunkHdrsRev
  LemmaCnChunkHdrsRevToCnChunkHdrs
  LemmaCnChunkHdrsRevToCnHypAllocator
  LemmaPtrToU64
  LemmaU64ToPtr
  LemmaTurnU32sToU64
  LemmaTurnU64ToU32s
  hyp_alloc_init
  pkvm_alloc_private_va_range
  LemmaMergeChunk
  LemmaMergeArrays
  chunk_merge
  chunk_list_del
  hyp_free
  hyp_alloc_errno
  hyp_alloc_missing_donations
  chunk_destroyable
  chunk_reclaimable
  hyp_alloc_reclaimable
  chunk_dec_map
  chunk_try_destroy
  hyp_alloc_size
  hyp_alloc_reclaim
  hyp_alloc_refill
)

OPT="${OPT:-""}"
run_test() {
  target="$1"
  start=$(date +%s.%N)

  if make ONLY="$target" cn-verify OPT="$OPT" > "verify-${target}.log" 2>&1  &&
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
  elapsed=$(awk "BEGIN { printf \"%.3f\", $end - $start }")

  RED='\033[0;31m'
  GREEN='\033[0;32m'
  NC='\033[0m'

  if [[ $status == "passed" ]]; then
    echo -e "$target ${GREEN}$status${NC} (in ${elapsed}s)"
  else
    echo -e "$target ${RED}$status${NC} (in ${elapsed}s)"
  fi

  if [[ $status != "passed" ]]; then
    exit 1
  fi
}

date
git log -1 --format="%H"
cn --version
echo "option: --incremental-solving=false --disable-multiclause-predicate-unfolding --no-vip $OPT"

export -f run_test

printf "%s\n" "${targets[@]}" | xargs -n1 -P "$JOBS" bash -c 'run_test "$@"' _

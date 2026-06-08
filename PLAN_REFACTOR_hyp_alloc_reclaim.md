# `hyp_alloc_reclaim` Spec Refactor Plan

## Current Concern

The current `hyp_alloc_reclaim` specification exposes several `MAXu64()`
arithmetic preconditions. These conditions are proof-useful, but they are not
an ideal public contract for the function. Conceptually, they approximate a
global page-budget fact: the whole system has a finite number of pages, so
transferring pages between memcaches should not overflow page counters.

That fact is not currently represented by a global ownership predicate, so the
proof carries the arithmetic constraints directly in the function precondition.

## Discussion Summary

- `target <= 0` returns early, so the spec should not require `0i32 <= target`.
- The positive-path shift-safety condition can likely be simplified to:

```c
target <= 524287i32;
```

  Negative and zero targets satisfy this and return before the dangerous path.

- `hyp_nr_cpus == 1u64` is acceptable for now as a modeling restriction.
- `!ptr_eq(mc, &hyp_allocator_mc)` is probably redundant because two
  `Cn_hyp_memcache` resources should imply separation.
- The remaining `MAXu64()` constraints are not naturally local facts about a
  single memcache. They should eventually come from a global page-conservation
  abstraction.

## Immediate Refactor

Status: achieved and then tightened further. Fulminate and focused CN passed
after applying the low-risk cleanup, and focused CN also passed after removing
several redundant `MAXu64()` preconditions.

1. Remove `0i32 <= target`.
2. Replace `target > 0i32 implies target <= 524287i32` with
   `target <= 524287i32`.
3. Try removing explicit `!ptr_eq(mc, &hyp_allocator_mc)` and check whether CN
   can derive the needed separation from ownership.
4. Keep the existing `MAXu64()` arithmetic constraints for now.

Follow-up audit result:

- Removable from the public precondition:
  - `target > 0i32 implies HostMC_pre.nr_pages < MAXu64()`
  - `target > 0i32 implies HostMC_pre.nr_pages <= MAXu64() - AllocMC_pre.nr_pages`
  - `target > 0i32 implies HostMC_pre.nr_pages + 1u64 <= MAXu64() - AllocMC_pre.nr_pages`
  - `target > 0i32 implies (u64)target <= MAXu64() - (AllocMC_pre.nr_pages + 1u64)`
- Still needed by the current proof/model:
  - `hyp_nr_cpus == 1u64`
  - `target <= 524287i32`
  - `target > 0i32 implies AllocMC_pre.nr_pages + (u64)target <= MAXu64() - HostMC_pre.nr_pages`
  - `target > 0i32 implies (u64)target + 1u64 <= MAXu64() - AllocMC_pre.nr_pages`

The two failed removal checks failed at the first loop invariant:

- without `target <= 524287i32`, CN could not establish the loop invariant
  carrying the shift-safety bound needed for `target << PAGE_SHIFT`;
- without `hyp_nr_cpus == 1u64`, CN could not establish the one-CPU loop
  invariant used by the current per-CPU memcache model.

Removing either remaining `MAXu64()` condition also failed immediately at the
first loop invariant, before the first memcache push. In the current proof they
are the minimal explicit substitute for the missing global page-budget
invariant.

After each change, run Fulminate and focused CN:

```sh
make cn-instrument
make cn-verify ONLY=hyp_alloc_reclaim
```

Use a command timeout of at least 2000 seconds for CN verification runs.

Verified commands:

```sh
make cn-instrument
make cn-verify ONLY=hyp_alloc_reclaim
timeout 2000s make cn-verify ONLY=hyp_alloc_reclaim
```

These passed on the refactored versions noted above.

## Longer-Term Refactor

Introduce a global system predicate, for example:

```c
Cn_hyp_allocator_system(...)
```

This predicate should own all relevant page containers together, such as:

- allocator chunks,
- the global allocator memcache,
- host/per-call memcache state,
- any modeled per-CPU memcache state.

It should expose or imply a bounded total page count. Once that exists, the
`MAXu64()` transfer constraints can be proved internally from the global budget
instead of appearing in the public `hyp_alloc_reclaim` precondition.

Until then, leaving the ugly arithmetic constraints in the top-level spec is
defensible because they are the current explicit replacement for the missing
global page-budget invariant.

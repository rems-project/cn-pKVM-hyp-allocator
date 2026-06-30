# CN Verification Tips for the pKVM Hyp Allocator

This is a practical note from the allocator verification work. It is not a
complete CN tutorial. It records the habits, commands, proof patterns, and
review lessons that were useful for `src/alloc.c`.

## Workflow

Start with the relevant implementation and the surrounding predicates. For this
repository, most allocator proof failures are not local arithmetic failures:
they are usually ownership-shape failures in one of these predicates:

- `Cn_hyp_allocator`
- `Cn_hyp_allocator_only`
- `Cn_hyp_allocator_focusing_on`
- `Cn_chunk_hdr`
- `Cn_chunk_hdrs`
- `Cn_chunk_hdrs_rev`
- `Cn_split_page`
- `Cn_hyp_memcache`

Use the smallest target that exercises the failing obligation:

```sh
make ONLY=<function> cn-verify
```

Use parallel verification for broad regression checks:

```sh
./verify.sh 8
```

For very slow targets, use a long external timeout:

```sh
timeout 20000 make ONLY=<function> cn-verify
```

The project has targets that can take many minutes, and full `verify.sh` runs
can take hours. A 2000 second timeout is useful for ordinary focused checks, but
some targets need longer to distinguish "slow" from "failing".

## Useful Commands

Normal focused proof:

```sh
make ONLY=hyp_allocator_map cn-verify
make ONLY=hyp_alloc_reclaim cn-verify
make ONLY=chunk_try_destroy cn-verify
```

Debug proof with CN trace detail:

```sh
make ONLY=<function> cn-verify OPT="-p 20"
```

The `-p 20` output is large. Usually inspect the last failing obligation first,
then search upward for the first resource or assertion CN could not establish.

Run all listed targets:

```sh
./verify.sh 8
```

`verify.sh` writes per-target logs named `verify-<target>.log`. A target is only
counted as passing when the log contains:

```text
[1/1]: <target> -- pass
```

Fulminate for executable spec checking:

```sh
make cn-instrument
```

For a one-file experiment outside the Makefile, the general form is:

```sh
cn instrument --run <file>
```

In this project, prefer the Makefile flow because Fulminate needs the same
preprocessing, includes, and runtime setup as the allocator translation unit.

Whitespace and accidental-diff check:

```sh
git diff --check -- src/alloc.c
```

Review cleanup:

```sh
git diff -- src/alloc.c
git diff --stat
```

## Reading CN Failures

First classify the failure. The fix depends on which category it is.

### Missing Ownership

Symptoms include messages saying CN cannot read, write, unfold, or satisfy a
predicate at some pointer. This often means the invariant or function spec has
the wrong resource shape.

Typical fixes:

- unfold the recursive predicate at the right point;
- add the missing resource to the loop invariant;
- prove a conversion lemma between two resource views;
- split on list-head/null cases before unfolding;
- focus the allocator predicate on the chunk being modified.

Do not paper over this with `trusted`. If CN lacks ownership, the proof state is
missing a real separation-logic fact.

### Wrong Shape After a List Operation

List operations often change which predicate view is convenient. For example,
after deleting or merging a chunk, the original `chunk` pointer may no longer be
readable through the old predicate.

Useful pattern:

```c
size_t saved = chunk->mapped_size;
chunk_list_del(chunk, allocator);
/* use saved after the ownership transfer */
```

If this changes implementation shape only for verification clarity, mark it:

```c
/* CN DIFF: explain exactly why this local is needed. */
```

The comment should state the ownership reason, not just "for CN".

### Arithmetic or Bounds Failure

CN can solve many simple facts, but page-alignment and overflow facts often need
the right precondition or invariant in scope.

Prefer moving stable facts into predicates or specs when they are true globally.
For allocator chunks, alignment facts such as:

```c
(u64)p & 7u64 == 0u64
```

belong naturally in chunk ownership predicates when every real chunk header has
that alignment.

Avoid adding one-off arithmetic lemmas unless the proof really needs induction
or a reusable abstraction boundary. Pure, non-recursive arithmetic lemmas add
review burden and are often unnecessary.

### Timeout Without Failure

A timeout is not a proof failure. Check whether the target used to be slow, and
whether the CN path is materially different after the edit.

Practical steps:

1. rerun the single target with a longer timeout;
2. compare the preprocessed or guarded path if a review cleanup removed an
   `#ifdef`;
3. try a smaller diff before changing proof structure;
4. inspect whether a new local variable was introduced before a loop and now
   needs loop framing.

One concrete lesson: a return-capture local introduced before a loop can make CN
try to frame that local through the whole loop. Prefer scoping such locals after
the loop:

```c
/* CN DIFF: capture the return value so CN can inspect the postcondition. */
{
        struct chunk_hdr *ret = chunk_get(best_chunk);
        /*@ unpack MaybeChunkHdr(best_chunk, !is_null(best_chunk)); @*/
        return ret;
}
```

## Specifications

Specifications should follow the Dryad-style ownership story, not merely the C
argument list. For allocator functions, ask:

- which global state is accessed;
- which allocator predicate owns the chunk list;
- whether the function focuses on one chunk or preserves the whole allocator;
- whether a memcache list is owned recursively;
- what happens on failure as well as success.

A successful return-only spec is usually incomplete if the implementation has
failure paths. For example, a map-style function should preserve ownership on
failure rather than silently consuming it.

Avoid weak top-level specs that only say "the allocator still exists" if the
caller needs stronger structure. A weak spec may verify the function but block
caller correctness because it loses list or memcache contents.

## Predicates

Use global recursive ownership predicates for real data structures.

For singly-linked memcache pages, the predicate should own the linked page list,
not just the `head` and `nr_pages` fields. Otherwise a proof of the local
function says little about callers that rely on actual pages.

Good predicates should contain stable physical facts:

- pointer alignment;
- chunk header layout;
- list next/prev consistency;
- mapped/allocated/VA-size bounds;
- page-sized ownership where a page is passed between memcache and allocator.

Do not include artificial tokens unless they describe real ownership. We removed
`page_token`-style bookkeeping because it did not correspond to a useful runtime
resource and made the predicates harder to explain.

## Loop Invariants

A loop invariant must describe both the heap split and the scalar progress.

For chunk-list scans, invariants usually need:

- allocator pointer unchanged;
- requested size unchanged;
- current chunk non-null when dereferenced;
- a recursive predicate for the processed prefix;
- a recursive predicate for the remaining suffix;
- the current best candidate, if any;
- enough bounds to avoid overflow in helper calls.

For loops that initialize a local on the first iteration, do not claim
unconditional `RW<T>(&local)` before the local has actually been written. If CN
allows it only through an unsound aliasing hole, avoid that proof. A sound model
is a phase predicate:

```c
/* pseudo-CN */
predicate RetSlot(pointer p, boolean init) {
        if init {
                take r = RW<int>(p);
        } else {
                take w = W<int>(p);
        }
}
```

Then prove that the uninitialized phase cannot be the loop-exit phase. If CN
cannot express the needed rule, prefer a small implementation-neutral
initialization when acceptable, or document the limitation. Do not exploit
duplicated global ownership through `accesses g` plus `take RW<T>(&g)`.

## Lemmas

Write lemmas for resource transformations, not for every arithmetic fact.

Good lemma use cases:

- converting a reversed list segment into a forward chunk list;
- appending or merging recursive predicates;
- converting between byte ownership and structured ownership;
- showing that a focused allocator view can be rebuilt after a local update.

Weak lemma use cases:

- pure page-alignment inequalities;
- simple overflow rearrangements;
- facts CN can derive from existing bounds once the right terms are in scope.

Every lemma should have a short comment explaining why it is ghost-only and why
it terminates. Recursive lemmas should recurse on a structurally smaller
resource, for example the tail of a list segment:

```c
/*
 * Ghost-only resource conversion. The function performs no heap writes.
 * The recursive call moves to the previous/next list node, consuming a
 * strictly smaller recursive predicate.
 */
```

Avoid `trusted` for target functions and helper lemmas. If a lemma cannot be
proved, treat that as evidence that the predicate split is wrong or that CN
needs a more explicit invariant.

## Byte Ownership and `my_memset`

`my_memset` works over byte-like ownership. Allocator pages and chunk headers
often start as structured ownership. The proof usually needs explicit
conversion:

1. split the page or chunk into header and byte tail;
2. convert the structured header field to bytes with `to_bytes`;
3. merge adjacent byte arrays;
4. call `my_memset`;
5. split the byte array again;
6. convert bytes back to structured ownership with `from_bytes`;
7. rebuild `Cn_split_page` or `Cn_chunk_hdr`.

Keep the real call outside `#ifdef __CN_VERIFY`:

```c
my_memset(data, 0, size);
#ifdef __CN_VERIFY
        /* proof-only splitting, conversion, and lemmas */
#endif
```

Actual heap-manipulating implementation code should not be hidden inside
`#ifdef __CN_VERIFY`.

## Fulminate

Use Fulminate before investing in a hard CN proof when the top-level spec is new
or suspicious.

Fulminate is good at finding:

- wrong preconditions;
- incorrect postconditions on concrete paths;
- missing failure cases;
- specs that claim ownership is consumed when failure should preserve it;
- harnesses that do not exercise all branches.

For this repo, use the Makefile target:

```sh
make cn-instrument
```

If writing a direct harness, keep it in the same translation unit or produce a
proper preprocessed combined file. Fulminate works on one C translation unit; it
does not magically link separate C files into one instrumented unit.

## Review Hygiene

Keep implementation diffs small. Reviewers care about this because CN proof
changes can accidentally change the verified program.

Rules that worked well:

- remove `#ifdef __CN_VERIFY` around magic comments; they are ignored outside CN;
- keep `#ifdef __CN_VERIFY` around lemma calls and proof-only control flow;
- do not put heap-mutating implementation code only inside `#ifdef __CN_VERIFY`;
- when changing implementation shape for verification, add `/* CN DIFF: ... */`;
- avoid indentation-only changes;
- prefer block-scoped return captures over broad CN/non-CN branches;
- do not add concrete parameters when a ghost argument would express the proof
  fact, unless CN cannot handle the ghost form and the limitation is documented.

Good return-capture pattern:

```c
/* CN DIFF: capture the return value so CN can inspect FooPost. */
{
        int ret = foo(...);
        /*@ unpack FooPost(...); @*/
        return ret;
}
```

Bad pattern:

```c
#ifdef __CN_VERIFY
        int ret = foo(...);
        /*@ unpack FooPost(...); @*/
        return ret;
#else
        return foo(...);
#endif
```

The bad pattern makes reviewers check whether the CN and non-CN implementation
paths are actually equivalent.

## Soundness Pitfalls

Do not combine `accesses g;` with an explicit `take RW<T>(&g)` for the same
global. CN has accepted this in some cases, creating two exclusive resources for
one address and making the context inconsistent. From an inconsistent context,
CN can prove false facts.

Sound alternatives:

- use only the implicit global access when that is enough;
- use a predicate that owns the global fields without duplicating `accesses`;
- pass ownership through one consistent abstraction.

When a proof suddenly becomes too easy, inspect the resources in the `-p 20`
log. If the same address appears twice as exclusive `RW`, the proof is suspect.

## Practical Debugging Checklist

When a proof fails:

1. Run the single target with `make ONLY=<function> cn-verify`.
2. If needed, rerun with `OPT="-p 20"`.
3. Read the last failing obligation first.
4. Decide whether the failure is ownership, shape, arithmetic, or timeout.
5. For ownership failures, find the missing predicate view.
6. For shape failures, split on null/list-head cases before unfolding.
7. For arithmetic failures, check whether the fact belongs in a predicate.
8. For timeout, try a smaller diff or a longer timeout before changing specs.
9. Run the nearest callers, not just the changed helper.
10. Run `git diff --check` before committing.

When adding a target to `verify.sh`, also verify it once directly. The script
only reports what is listed in `targets`.

## What to Avoid

- Do not weaken the target spec just to make the current function pass.
- Do not ignore failure cases in postconditions.
- Do not use `trusted` for target functions or proof lemmas.
- Do not hide implementation changes behind CN-specific preprocessor branches.
- Do not add pure non-recursive arithmetic lemmas unless they are truly needed.
- Do not leave debugging assertions in C bodies after the proof is stable.
- Do not assume a timeout is a semantic failure.
- Do not assume a passing helper spec is strong enough for its callers.

## Useful Mental Model

CN proofs in this file are mostly about preserving the exact ownership story:

```text
allocator fields
  plus recursive chunk list
  plus focused chunk or list segment
  plus memcache page list
  plus byte/structured page ownership
```

Most hard bugs were caused by losing one of those views, using a spec that was
too weak for a caller, or asking CN to recover a recursive shape without an
explicit lemma. Keep the ownership shape explicit, and make implementation diffs
obvious when verification needs a small local binding.

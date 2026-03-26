# Benchmark Suite

This directory contains the scripts for our two benchmark sets, the partial specification benchmark and the buggy specification benchmark, for the hyp allocator.

Since each specification is created by modifying the complete specification, we record only the diffs in the `patches` directory, without duplicating the source files.
To use a benchmark, check out the base commit and apply the corresponding patch.
The scripts in this directory make it easy to switch between specifications.

## Usage

### Switch to a specific benchmark

```sh
./benchmark/switch_to.sh <benchmark_number> [json_file]
```

The default `json_file` is `pbt_bench/bug_finding.json`. Pass `benchmark/partial_spec.json` to switch to the partial specification benchmark.

### Run a script over all buggy specification benchmarks

```sh
./benchmark/run_bug_bench.sh <script>
```

Example:

```sh
./benchmark/run_bug_bench.sh ./benchmark/run_fulminate.sh
```

### Run a script over all partial specification benchmarks

```sh
./benchmark/run_correct_partial_spec.sh <script>
```

## Benchmark Table

### Buggy Specification Benchmark

The specification bugs are collected from previous commits in this repository. The following table summarizes which function contains the bug in each benchmark.

| # | Patch | Function under test |
|---|-------|---------------------|
| 1 | patch-01 | `LemmaCreateNewChunk` |
| 2 | patch-03 | `chunk_list_insert` |
| 3 | patch-05 | `chunk_install` |
| 4 | patch-06 | `chunk_install` |
| 5 | patch-07 | `chunk_install` |
| 6 | patch-08 | `chunk_install` |
| 7 | patch-09 | `chunk_merge` |
| 8 | patch-10 | `chunk_install` |
| 9 | patch-11 | `chunk_merge` |
| 10 | patch-13 | `chunk_recycle` |
| 11 | patch-14 | `chunk_list_insert` |
| 12 | patch-15 | `chunk_unmapped_size` |
| 13 | patch-16 | `chunk_hash_update` |
| 14 | patch-17 | `chunk_can_split` |
| 15 | patch-18 | `chunk_install` |
| 16 | patch-19 | `chunk_install` |
| 17 | patch-20 | `chunk_install` |
| 18 | patch-22 | `chunk_list_insert` |
| 19 | patch-23 | `chunk_list_insert` |
| 20 | patch-24 | `chunk_install` |
| 21 | patch-25 | `chunk_get` |
| 22 | patch-26 | `setup_first_chunk` |
| 23 | patch-27 | `chunk_install` |
| 24 | patch-28 | `chunk_hash_update` |

### Partial Specification Benchmark

The partial specifications are correct but incomplete: some annotations (loop invariants, preconditions, postconditions, proof annotations, lemma calls) have been removed.

| benchmark_id | patch | description |
|---|-------|-------------|
| 1 | patch-28-no-loop-invariant | The loop invariant in `get_free_chunk` is removed |
| 2 | patch-29-no-hyp-alloc | The specification of the top-level function `hyp_alloc` is removed |
| 3 | patch-30-no-chunk-list-insert | The specification of the intermediate function `chunk_list_insert` is removed |
| 4 | patch-31-no-list-specs | The specifications of leaf list functions are removed |
| 5 | patch-32-missing-proof-annotations-in-hyp-alloc | Proof annotations (e.g. `split_case`) in `hyp_alloc` are removed |
| 6 | patch-33-missing-lemmas-in-hyp-alloc | Lemma calls in `hyp_alloc` are removed |
| 7 | patch-34-weak-postcondition | The postcondition of `chunk_recycle` is weakened |

Although these patches are artificial, they exhaustively illustrate the capabilities of our testing infrastructure.

## Base commit

All patches apply against commit `b391f721fe71b8682a7e1752375c5c1bef936491`
with `patches/workaround.patch` applied on top.

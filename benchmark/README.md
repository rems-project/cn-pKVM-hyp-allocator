# Benchmark Suite

This directory defines the benchmark suite of patched CN specifications for the
pKVM hypervisor allocator. Each benchmark corresponds to a mutant patch that
introduces a deliberate bug into the specification (`src/alloc.c` / `specs/spec.c`).

## Usage

### Switch to a specific benchmark

```sh
./benchmark/switch_to.sh <benchmark_number>
```

### Run a script over all benchmarks

```sh
./benchmark/run_bench.sh <script>
```

Example:

```sh
./benchmark/run_bench.sh ./benchmark/run_fulminate.sh
```

## Benchmark Table

The source of truth is `pbt_bench/bug_finding.json`. Benchmark numbers are
1-indexed and match the order of entries in that file.

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

**Note:** Patch numbers follow the original naming scheme; there are gaps (02, 04, 12, 21) because those patches were excluded from the benchmark.

## Base commit

All patches apply against commit `b391f721fe71b8682a7e1752375c5c1bef936491`
with `patches/workaround.patch` applied on top.

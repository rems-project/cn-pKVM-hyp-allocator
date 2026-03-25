# Benchmark Suite

This directory defines the benchmark suite of patched CN specifications for the
pKVM hypervisor allocator. Each benchmark corresponds to a mutant patch that
introduces a deliberate bug into the specification (`src/alloc.c` / `specs/spec.c`).

## Usage

### Switch to a specific benchmark

```sh
./benchmark/switch_to.sh <benchmark_number>
```

This restores `src/alloc.c`, `src/shim.c`, and `specs/spec.c` to the base
commit, applies the alignment workaround patch, and then applies the
benchmark's mutation patch. After this call you can run your tooling against
the patched specification.

Example:

```sh
./benchmark/switch_to.sh 3
./test-symbolic.sh --only=chunk_install
make cn-instrument
```

### Run a script over all benchmarks

```sh
./benchmark/run_bench.sh <script>
```

`run_bench.sh` iterates over every benchmark, calls `./benchmark/switch_to.sh <N>`,
then calls `<script> <N>`. After each run the working tree is restored to the
base commit before the next benchmark is applied.

Example:

```sh
./benchmark/run_bench.sh ./benchmark/run_fulminate.sh
```

Your script receives the benchmark number as `$1` and can use it to label
output or pick up metadata from `pbt_bench/bug_finding.json`.

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



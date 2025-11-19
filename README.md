# cn-pKVM-hyp-allocator

The code is copied from a snapshot of commit `74ae8d16a99681b567aa84d6ed643110ab4c3a76`
(in the `android16-6.12` branch: https://`android.googlesource.com/kernel/common/+/refs/heads/android16-6.12`)

* `arch/arm64/kvm/hyp/nvhe/alloc.c`
* `arch/arm64/kvm/hyp/include/nvhe/alloc.c`


## Building
You need `https://mesonbuild.com/` to build.

Initial setup after a clean checkout:

```
# meson setup _build
```

Then to build:

```
# ninja -C _build
```

This produces a test executable at `_build/src/main`.


## Specification/Implementation Bugs found by Fulminate

Commit messages that start with `[fulminate]` indicate that the issue fixed by the patch was discovered by **Fulminate**.


## Property-Based Testing Benchmark

The `pbt_bench/` directory contains benchmarking tools to compare the performance of different testing strategies:

### Data Collection: `make collect-pbt-comparison`

Collects timing data for Bennet (random testing) vs Darcy (symbolic testing) and saves to CSV.

Or manually:

```bash
./pbt_bench/collect_comparison.py [OPTIONS]
```

Options:
- `--should-fail=FUNC1,FUNC2,...`: Comma-separated list of function names expected to fail. Can be used multiple times. Supports both short names (e.g., `hyp_alloc_init`) and full names (e.g., `alloc::hyp_alloc_init`).
- `--might-fail=FUNC1,FUNC2,...`: Comma-separated list of function names that fail flakily. Can be used multiple times. These functions will be excluded from benchmarking but won't cause errors regardless of pass/fail status.
- `--trials=N`: Number of trials to run for each test (default: 10)

The script will:
1. Run the full test suite with `./test-random.sh --progress-level=function`
2. Verify test results match expectations:
   - Functions in `--should-fail` must fail (exits with error if they pass)
   - Functions in `--might-fail` can pass or fail without error
   - All other functions must pass or error (exits with error if they fail)
3. Select benchmarkable functions (excludes expected failures, might-fail functions, and functions that failed to generate valid input)
4. For each benchmarkable function, measure execution time for both:
   - **Bennet** (random testing): `./test-random.sh --only=<function> --exit-fast --no-replicas --no-replays`
   - **Darcy** (symbolic testing): `./test-symbolic.sh --only=<function> --exit-fast --no-replicas --no-replays`
5. Save timing data to `pbt_comparison_data.csv`

### Data Analysis: `make analyze-pbt-comparison`

Reads collected timing data and performs statistical analysis using the Mann-Whitney U test.

Usage:

```bash
make analyze-pbt-comparison
```

The script will:
1. Load timing data from `pbt_comparison_data.csv`
2. Perform Mann-Whitney U test (two-tailed, α=0.01) for each function
3. Display results with significance markers
4. Save detailed analysis to `pbt_comparison_results.csv`

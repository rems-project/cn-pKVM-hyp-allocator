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


## Verification

### Install CN

Install CN (commit=384f4f3bf1d404c54ee57ae389f309c280c315c0) as follows:

```
git clone https://github.com/rems-project/cn
cd cn
git checkout 384f4f3bf1d404c54ee57ae389f309c280c315c0
opam install ./cn.opam
make install
```

For more details, follow the instructions provided in the CN repository.

### Verify pKVM hyp allocator

Run `make cn-verify-par`.
This will automatically use as many cores as your system has.
If you prefer a more moderate load, run `./verify.sh <num of processes>` instead.


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

### Sizing Benchmark: `make collect-pbt-sizing`

Measures input generation time at various sizes for each unique function in `pbt_bench/bug_finding.json`, across three configurations:
- **Bennet**
- **Darcy** (default array length)
- **Darcy-4096** (`--max-array-length=4096`)

Or manually:

```bash
./pbt_bench/collect_sizing.py [OPTIONS]
```

Defaults: 100 samples per run (with a 180-second timeout; partial results are saved if the timeout is reached), sizes 1, 2, 4, 8, 16, 32.

Options:
- `--config {darcy_4096,darcy,bennet,all}`: Which config to run (default: `all`)
- `--only-function=FUNC`: Only benchmark a specific function
- `--sizes=1,2,4,8,16,32`: Comma-separated sizes to test
- `--restart`: Ignore existing CSV and start fresh
- `--analyze-only`: Skip experiments; analyze existing CSV results and generate plots
- `--log-output=DIR`: Log test program output to files in DIR

The script will:
1. Checkout the base version of source files and apply the workaround patch
2. **Phase 1 (Generate + Compile)**: For each (function, config), run `cn test --no-run` to generate C code, then compile the binary
3. **Phase 2 (Run Experiments)**: For each (function, config, size), run the binary and record per-input generation times.
4. Save results to `pbt_sizing_data.csv`

The repo includes pre-collected sizing data in `pbt_sizing_data.csv`, so running with `--analyze-only` will produce results immediately without re-running experiments. The script **resumes by default** — it skips `(function, config, size)` combinations already present in the CSV. Use `--restart` to start fresh.

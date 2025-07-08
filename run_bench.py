import subprocess
import sys
import tempfile
import os
import json
import time
import re
from concurrent.futures import ThreadPoolExecutor, as_completed

EFF_DIR = "efficiency-experiments"
MAX_WORKERS = 5
BENCH_FILE = os.path.join(EFF_DIR, "benchmark.txt")

def apply_patch_from_content(patch_content, base_branch):
    subprocess.run(["git", "checkout", base_branch], check=True)
    with tempfile.NamedTemporaryFile(mode="w", delete=True) as tmp:
        tmp.write(patch_content)
        tmp.flush()
        subprocess.run(["git", "apply", tmp.name], check=True)

def measure_time(cmd):
    start = time.time()
    try:
        subprocess.run(cmd, shell=True, check=True)
    except subprocess.CalledProcessError:
        pass
    return time.time() - start

def run_cn(target_function):
    cmd = f"make cn-verify ONLY={target_function}"
    return measure_time(cmd)

def workaround_fulminate():
    subprocess.run("make clean", shell=True, check=True)
    subprocess.run("make main.pp.exec.c", shell=True, check=True)

    path = "main.pp.exec.c"
    sig = re.escape("[[ cerb::hidden ]] __cerbty_uint64_t __builtin_bswap64 (__cerbty_uint64_t x);")
    prog = re.compile(sig)
    with open(path, "r") as f:
        lines = f.readlines()
    modified = False
    for i, line in enumerate(lines):
        if prog.search(line):
            lines[i] = "// " + line
            modified = True
            break
    if not modified:
        print("Warning: workaround_fulminate")
    with open(path, "w") as f:
        f.writelines(lines)
    subprocess.run("make main.exe", shell=True, check=True)

def run_fulminate():
    cmd = "./main.exe"
    return measure_time(cmd)

def run_bench(benchmark_name, target_function, cn_patch_content, fulm_patch_content):
    results = {"cn": [], "fulminate": []}

    apply_patch_from_content(cn_patch_content, base_branch="fulminate-exp-base")
    with ThreadPoolExecutor(max_workers=MAX_WORKERS) as exec_cn:
        futures = [exec_cn.submit(run_cn, target_function) for _ in range(MAX_WORKERS)]
        for f in as_completed(futures):
            try:
                results["cn"].append(f.result())
            except Exception as e:
                results["cn"].append(str(e))
    subprocess.run(["git", "reset", "--hard"], check=True)
    subprocess.run(["git", "checkout", "main"], check=True)

    apply_patch_from_content(fulm_patch_content, base_branch="fulminate-exp-base")
    workaround_fulminate()
    for _ in range(MAX_WORKERS):
        try:
            results["fulminate"].append(run_fulminate())
        except Exception as e:
            results["fulminate"].append(str(e))
    subprocess.run(["git", "reset", "--hard"], check=True)
    subprocess.run(["git", "checkout", "main"], check=True)

    return results

def parse_benchmark_txt():
    benchmarks = []
    with open(BENCH_FILE) as f:
        for line in f:
            line = line.strip()
            if not line or line.startswith("#"):
                continue
            parts = line.split(",")
            commit_hash = parts[0].strip()
            func_part = parts[1].split(";", 1)[0].strip() if len(parts) >= 2 else "unknown"
            benchmarks.append((commit_hash, func_part))
    return benchmarks

def check_clean_git():
    try:
        subprocess.run(["git", "diff", "--quiet"], check=True)
        subprocess.run(["git", "diff", "--cached", "--quiet"], check=True)
    except subprocess.CalledProcessError:
        print("Working tree or index is dirty. Commit or stash your changes before running.")
        sys.exit(1)

if __name__ == "__main__":
    check_clean_git()
    subprocess.run(["git", "checkout", "main"], check=True)
    benchmarks = parse_benchmark_txt()

    all_results = {}
    for commit_hash, func_name in benchmarks:
        cn_patch = os.path.join(EFF_DIR, f"{commit_hash}.cn.patch")
        fulm_patch = os.path.join(EFF_DIR, f"{commit_hash}.fulminate.patch")
        with open(cn_patch) as f:  cn_patch_content = f.read()
        with open(fulm_patch) as f: fulm_patch_content = f.read()

        print(f"\n=== Running benchmark: {commit_hash} ({func_name}) ===")
        try:
            res = run_bench(commit_hash, func_name, cn_patch_content, fulm_patch_content)
            all_results[commit_hash] = {"function": func_name, "results": res}
        except Exception as e:
            print(f"Benchmark {commit_hash} failed: {e}")
            all_results[commit_hash] = {"function": func_name, "error": str(e)}
        break


    with open("benchmark_results.json", "w") as outf:
        json.dump(all_results, outf, indent=2)

    print("\nAll benchmarks complete. Results saved to benchmark_results.json")


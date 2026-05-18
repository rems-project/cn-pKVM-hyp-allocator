#!/usr/bin/env python3

import subprocess
from os import listdir
from os.path import isfile, join
import argparse, sys, os
import pandas as pd
import numpy as np
import statistics
import re

# Usage: (from top-level dir) ./fulm_bench/fulm_bench.py --csv=<your-csv-name>.csv --max_n_alloc_exp=8
parser=argparse.ArgumentParser()
parser.add_argument("--csv", help="Store all results in csv file with provided name")
parser.add_argument("--max_n_alloc_exp", help="Maximum i to iterate to, where the number of allocations is 2**i")
parser.set_defaults(max_n_alloc_exp=5)

args=parser.parse_args()

opam_switch_prefix = os.environ["OPAM_SWITCH_PREFIX"]
runtime_prefix = opam_switch_prefix + "/lib/cn/runtime"

gtime = 'gtime -f ~%e~%M '

cc = "clang"

def run_cmd(cmd):
    print(cmd)
    subprocess.call(cmd.split())

def print_and_error(error_str):
    # global num_error_files
    print(error_str + " ERROR")
    exit()

def set_num_allocs(n_allocs):
    input_f = open ('src/main.c', 'r' )
    output_f = open ('main.subst.c', 'w' )

    for line in input_f:
        subst_line = re.sub(r'#define N_ALLOC (\d+)', '#define N_ALLOC ' + str(n_allocs), line)
        output_f.write(subst_line)



def preprocess(filename):
    runtime_cpp = cc + " -std=gnu11 -E -P -CC -isystem" + opam_switch_prefix + "/lib/cerberus-lib/runtime/libc/include/ -Werror -Wno-builtin-macro-redefined -D__cerb__  -undef -fkeep-system-includes  -Isrc -Iinclude  -DSTANDALONE -DNO_STATEMENT_EXPRS"
    preprocess_cmd = runtime_cpp + " main.subst.c"
    pp_f = open(filename, "w")
    print(preprocess_cmd)
    subprocess.call(preprocess_cmd.split(), stdout=pp_f)

def fulminate(filename):
    fulm = "cn instrument --exec-c-locs-mode --insert-curly-braces --without-loop-invariants --without-lemma-checks "
    run_cmd(fulm + filename)

def compile(filename):
    compile = cc + " -g -c -std=gnu11 -I" + runtime_prefix + "/include -Isrc -Iinclude -Wno-builtin-macro-redefined -Wno-unused-value -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS -include fulminate2.h "
    run_cmd(compile + filename)

def link(filename, instrumented):
    link = cc + " " + filename + " /Users/rinibanerjee/.opam/default/lib/cn/runtime/libcn_exec.a -L " + runtime_prefix + " -lcn_exec -o main" + (".instrumented" if instrumented else "") + ".exe"
    run_cmd(link)

def run(instrumented, time=False):
    run = (gtime if time else "") + "./main" + (".instrumented" if instrumented else "") + ".exe"
    print(run)
    res = subprocess.run(run.split(), capture_output=True, text = True)
    output = res.stderr
    if time:
        t, s = output.split('~')[-2:]
        return float(t), float(s)


data = {
    "num_allocs": [],
    "median_instr_time": [],
    "median_instr_space": []
}

max_power_of_2 = int(args.max_n_alloc_exp)
for i in range(1, max_power_of_2 + 1):
    n_alloc = 2**i
    set_num_allocs(n_alloc)
    data["num_allocs"].append(n_alloc)

    pp_f_prefix = "main.pp.bench"
    pp_f_name = pp_f_prefix + ".c"

    preprocess(pp_f_name)

    fulminate(pp_f_name)

    pp_f_exec_prefix = pp_f_prefix + ".exec"
    pp_f_exec_name = pp_f_exec_prefix + ".c"

    compile(pp_f_exec_name)

    pp_f_exec_obj_file = pp_f_exec_prefix + ".o"
    link(pp_f_exec_obj_file, instrumented=True)


    instr_times = []
    instr_spaces = []
    for i in range(11):
        time, space = run(instrumented=True, time=True)
        instr_times.append(time)
        instr_spaces.append(space)

    median_instr_time = statistics.median(instr_times)
    median_instr_space = statistics.median(instr_spaces)

    data["median_instr_time"].append(median_instr_time)
    data["median_instr_space"].append(median_instr_space)

df = pd.DataFrame(data)
print(df)

if args.csv:
    df.to_csv(args.csv, index=False) 

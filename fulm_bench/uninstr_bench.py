#!/usr/bin/env python3

import subprocess
from os import listdir
from os.path import isfile, join
import argparse, sys, os
import pandas as pd
import numpy as np
import statistics
import re
import fileinput

# IMPORTANT!
# Need to check out to old-hyp-for-fulm branch for this script to work, which builds on 
# commit eed7d8bc3e11d2a3398eef2ee5595e86b76ac40c, after which CN spec development started.

parser=argparse.ArgumentParser()
parser.add_argument("--csv", help="Store all results in csv file with provided name")
parser.add_argument("--max_n_alloc_exp", help="Maximum i to iterate to, where the number of allocations is 2**i")
parser.set_defaults(max_n_alloc_exp=5)

args=parser.parse_args()

def set_num_allocs(n_allocs):
    for line in fileinput.input("src/main.c", inplace=True):
        subst_line = re.sub(r'#define N_ALLOC (\d+)', '#define N_ALLOC ' + str(n_allocs), line)
        print(subst_line, end='')
    

def run_cmd(cmd):
    print(cmd)
    res = subprocess.check_output(cmd.split(), stderr=subprocess.STDOUT,text=True)
    # print(res.split(sep='~'))
    t, s = res.split('~')[1:]
    return float(t), float(s)

def find_and_replace_macro(f, input_basename, new_str):
    # Assume there is a macro of the form #define SIZE magic in the input file
    with open(f, 'r') as file:
        filedata = file.read()

    filedata = filedata.replace("magic", new_str)
    subst_f_name = input_basename + ".subst.c"

    with open(subst_f_name, 'w') as file:
        file.write(filedata)

    return subst_f_name

gtime = 'gtime -f ~%e~%M '
build_cmd = 'ninja -C _build'

data = {
    "num_allocs": [],
    "median_instr_time": [],
    "median_instr_space": []
}

max_i = int(args.max_n_alloc_exp)

for i in range(1, max_i + 1):
    n_alloc = 2**i
    set_num_allocs(n_alloc)
    data["num_allocs"].append(n_alloc)
    print(n_alloc)

    subprocess.run(build_cmd.split())

    times = []
    spaces = []
    for j in range(11):
        time, space = run_cmd(gtime + "./_build/src/main")
        times.append(time)
        spaces.append(space)
    data["median_instr_time"].append(statistics.median(times))
    data["median_instr_space"].append(statistics.median(spaces))

df = pd.DataFrame(data)
print(df)

if args.csv:
    df.to_csv(args.csv, index=False) 
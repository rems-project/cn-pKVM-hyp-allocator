#!/usr/bin/env python3

import subprocess
from os import listdir
from os.path import isfile, join
import argparse, sys, os
import pandas as pd
import numpy as np
import statistics

def run_cmd(cmd):
    print(cmd)
    res = subprocess.check_output(cmd.split(), stderr=subprocess.STDOUT,text=True)
    # print(res.split(sep='~'))
    return res.split('~')[1:]

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

times = []
spaces = []
# str_power = str(2**i)
# find_and_replace_macro("src/main.c", "main_" + str_power, str(2**i))
for j in range(11):
    time, space = run_cmd(gtime + "./uninstr/main")
    times.append(time)
    spaces.append(space)
print("Median time: " + str(statistics.median(times)))
print("Median space: " + str(statistics.median(spaces)))
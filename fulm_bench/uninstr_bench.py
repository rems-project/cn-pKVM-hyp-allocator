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


gtime = 'gtime -f ~%e~%M '

for i in range(1, 9):
    times = []
    spaces = []
    for j in range(11):
        time, space = run_cmd(gtime + "./uninstr/main_" + str(2 ** i))
        times.append(time)
        spaces.append(space)
    print("Number of pages: " + str(2**i))
    print("Median time: " + str(statistics.median(times)))
    print("Median space: " + str(statistics.median(spaces)))
#!/usr/bin/env python3

import subprocess
from os import listdir
from os.path import isfile, join
import argparse, sys, os
import pandas as pd
import numpy as np
import statistics

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

def preprocess(filename):
    runtime_cpp = cc + " -std=gnu11 -E -P -CC -isystem" + opam_switch_prefix + "/lib/cerberus-lib/runtime/libc/include/ -Werror -Wno-builtin-macro-redefined -D__cerb__  -undef -fkeep-system-includes  -Isrc -Iinclude  -DSTANDALONE -DNO_STATEMENT_EXPRS"
    preprocess_cmd = runtime_cpp + " src/main.c"
    pp_f = open(filename, "w")
    print(preprocess_cmd)
    subprocess.call(preprocess_cmd.split(), stdout=pp_f)

def fulminate(filename):
    fulm = "cn instrument --exec-c-locs-mode --insert-curly-braces "
    run_cmd(fulm + filename)

def compile(filename):
    compile = cc + " -g -c -O0 -std=gnu11 -I" + runtime_prefix + "/include -Isrc -Iinclude -Wno-builtin-macro-redefined -Wno-unused-value -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS -include fulminate2.h "
    run_cmd(compile + filename)

def link(filename, instrumented):
    link = cc + " " + filename + " /Users/rinibanerjee/.opam/default/lib/cn/runtime/libcn_exec.a -L " + runtime_prefix + " -lcn_exec -o main" + ".instrumented" if instrumented else "" + ".exe"
    run_cmd(link)

def run(instrumented):
    run = "./main" + ".instrumented" if instrumented else "" + ".exe"
    run_cmd(run)


pp_f_prefix = "main.pp.bench.new"
pp_f_name = pp_f_prefix + ".c"

preprocess(pp_f_name)
fulminate(pp_f_name)

pp_f_exec_prefix = pp_f_prefix + ".exec"
pp_f_exec_name = pp_f_exec_prefix + ".c"

compile(pp_f_exec_name)

pp_f_obj_file = pp_f_exec_prefix + ".o"

link(pp_f_obj_file, instrumented=True)
run(instrumented=True)
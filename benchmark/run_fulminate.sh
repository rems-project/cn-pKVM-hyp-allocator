#!/bin/sh
# Usage: ./benchmark/run_fulminate.sh <benchmark_number>

make main.exe > /dev/null 2>&1 && ./main.exe > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "Benchmark $1: No bug found"
else
    echo "Benchmark $1: Bug found"
fi

#!/usr/bin/env python3
import subprocess
import tempfile
import os
import sys


def preprocess(path):
    tmp = tempfile.NamedTemporaryFile('w+', suffix='.c', delete=False)
    proc = subprocess.run(
        ['gcc-15', '-E', '-P', '-fpreprocessed', path],
        stdout=tmp,
        stderr=subprocess.PIPE,
        text=True
    )
    tmp.flush()
    tmp.close()
    if proc.returncode != 0:
        print(proc.stderr, file=sys.stderr)
        os.remove(tmp.name)
        sys.exit(proc.returncode)
    return tmp.name


def clang_format(path):
    out = subprocess.run(
        ['clang-format', path],
        capture_output=True,
        text=True,
        check=True
    ).stdout
    tmp = tempfile.NamedTemporaryFile('w+', suffix='.c', delete=False)
    tmp.write(out)
    tmp.flush()
    tmp.close()
    return tmp.name


def main():
    os.chdir('../')
    a = clang_format(preprocess('misc/original_alloc.c'))
    b = clang_format(preprocess('src/alloc.c'))

    try:
        diff = subprocess.run(
            ['diff', '--ignore-all-space', a, b],
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True
        )
        print(diff.stdout if diff.stdout else 'no diff')
        if diff.stderr:
            print(diff.stderr, file=sys.stderr)
    finally:
        os.remove(a)
        os.remove(b)


if __name__ == '__main__':
    main()

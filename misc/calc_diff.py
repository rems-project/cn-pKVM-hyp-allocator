#!/usr/bin/env python3
import subprocess
import tempfile
import os
import sys


def preprocess(path):
    tmp2 = tempfile.NamedTemporaryFile('w+', suffix='.c', delete=False)
    with open(path, 'r') as f:
        s = f.read()
    res = ""
    skip = False
    skip2 = 0
    nested = False  # workaround for the last lines
    for line in s.splitlines():
        if (line.startswith('#ifdef __CN_VERIFY')
                or line.startswith('#if defined(__CN_VERIFY)')):
            assert (not skip and skip2 == 0)
            skip = True
            continue
        if line.startswith('#ifdef STANDALONE'):
            assert (not skip and skip2 == 0)
            skip2 = 1
            continue

        if line.startswith('#ifndef STANDALONE'):
            assert (not skip and skip2 == 0)
            skip2 = 3
            continue

        if skip2 >= 1 and line.startswith('#ifndef'):
            nested = True
            continue

        if skip and line.startswith('#endif'):
            skip = False
            continue

        if skip2 in [1, 2, 3] and line.startswith('#endif'):
            if nested:
                nested = False
                continue
            skip2 = 0
            continue
        if skip2 == 1 and line.startswith('#else'):
            skip2 = 2
            continue
        if skip2 == 3 and line.startswith('#else'):
            skip2 = 1
            continue

        if not skip and skip2 in [0, 2, 3]:
            res += line + '\n'
    tmp2.write(res)
    tmp2.flush()
    tmp2.close()

    tmp = tempfile.NamedTemporaryFile('w+', suffix='.c', delete=False)
    proc = subprocess.run(
        ['gcc-15', '-E', '-P', '-fpreprocessed', tmp2.name],
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

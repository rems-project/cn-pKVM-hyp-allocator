#!/usr/bin/env python3
import sys

def count_tagged_lines(filename):
    count = 0
    inside = False

    with open(filename, "r", encoding="utf-8") as f:
        for line in f:
            s = line.rstrip("\n")

            has_start = "/*@" in s
            has_end = "@*/" in s

            if has_start and has_end:
                count += 1
                continue

            if has_start:
                inside = True
                count += 1
                continue

            if has_end and inside:
                count += 1
                inside = False
                continue

            if inside:
                count += 1
                continue

            if "/*CN*/" in s:
                count += 1

    return count


def main():
    if len(sys.argv) < 2:
        sys.exit(1)

    total = 0
    for fn in sys.argv[1:]:
        c = count_tagged_lines(fn)
        total += c

    print(f"{total}")


if __name__ == "__main__":
    main()


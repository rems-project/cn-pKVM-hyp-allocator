#!/bin/sh
set -e

cn test --no-run \
    --output-dir=_test_random/ \
    --output-tyche=results.jsonl \
    src/alloc.c \
    -Isrc -Iinclude \
    -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS \
    --print-seed \
    --input-timeout=0 \
    "$@"

CPPFLAGS="-include ../fulminate2.h" ./_test_random/run_tests.sh

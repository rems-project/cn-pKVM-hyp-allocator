#!/bin/sh
set -e

cn test --no-run \
    --output-dir=_test_symbolic/ \
    --output-tyche=results.jsonl \
    src/alloc.c \
    -Isrc -Iinclude \
    -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS \
    --print-seed \
    --experimental-product-arg-destruction \
    --input-timeout=0 \
    --smt-pruning-before-absint=fast \
    --smt-pruning-keep-redundant-assertions \
    --smt-pruning-at-runtime \
    --symbolic \
    "$@"

CPPFLAGS="-include ../fulminate2.h -O3" ./_test_symbolic/run_tests.sh

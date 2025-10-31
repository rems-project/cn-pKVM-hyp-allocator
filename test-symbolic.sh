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
    --smt-pruning-at-runtime \
    --symbolic \
    --skip=chunk_try_destroy \
    --skip-fulminate=chunk_try_destroy \
    "$@"

CPPFLAGS="-include ../fulminate2.h -O3" ./_test_symbolic/run_tests.sh

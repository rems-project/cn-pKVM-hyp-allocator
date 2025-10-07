#!/bin/sh

cn test --no-run \
    --output-dir=_test_symbolic/ \
    src/alloc.c \
    -Isrc -Iinclude \
    -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS \
    --experimental-product-arg-destruction \
    --input-timeout=0 \
    --smt-pruning-before-absint=fast \
    --smt-pruning-at-runtime \
    --symbolic \
    --skip=chunk_try_destroy \
    --skip-fulminate=chunk_try_destroy \
    "$@"

CPPFLAGS="-include ../fulminate2.h" ./_test_symbolic/run_tests.sh

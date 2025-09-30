#!/bin/sh

cn test --no-run \
    --output-dir=_test_random/ \
    src/alloc.c \
    -Isrc -Iinclude \
    -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS \
    --experimental-product-arg-destruction \
    --input-timeout=0 \
    --smt-pruning-before-absint=fast \
    --skip=chunk_try_destroy \
    --skip-fulminate=chunk_try_destroy \
    "$@"

CPPFLAGS="-include ../fulminate2.h" ./_test_random/run_tests.sh

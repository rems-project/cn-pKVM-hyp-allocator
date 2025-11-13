#!/bin/sh
set -e

cn test --no-run \
    --output-dir=_test_random/ \
    --output-tyche=results.jsonl \
    src/alloc.c \
    -Isrc -Iinclude \
    -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS \
    --print-seed \
    --experimental-product-arg-destruction \
    --input-timeout=0 \
    --smt-pruning-before-absint=fast \
    --smt-pruning-keep-redundant-assertions \
    --trap \
    "$@"

CPPFLAGS="-include ../fulminate2.h" ./_test_random/run_tests.sh || lldb -S lldb_config_for_darcy.lldb

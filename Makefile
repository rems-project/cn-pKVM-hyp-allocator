# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

CC = clang-19

# includes adapted from _build/compile_commands.json
INCLUDES= -Isrc -Iinclude

INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=$(CC) -std=c11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

RUNTIME_PREFIX = $(OPAM_SWITCH_PREFIX)/lib/cn/runtime
RUNTIME_LIB = $(RUNTIME_PREFIX)
RUNTIME_CPP = $(CC) -std=gnu11 -E -P -CC -isystem$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Werror -Wno-builtin-macro-redefined -D__cerb__  -undef -fkeep-system-includes  -Isrc -Iinclude  -DSTANDALONE -DNO_STATEMENT_EXPRS

tmp-alloc.c: src/alloc.c
	$(CPP) -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c > tmp-alloc.c

.PHONY: with-cerb
with-cerb:
	cerberus -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c

.PHONY: ninja
ninja:
	ninja -C _build/

.PHONY: cn-verify-via-cpp
cn-verify-via-cpp: tmp-alloc.c
	cn verify tmp-alloc.c

.PHONY: cn-verify
cn-verify: src/alloc.c
	cn verify --disable-multiclause-predicate-unfolding --no-vip $(if $(OPT), $(OPT)) $(if $(ONLY),--only=$(ONLY)) -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c

main.pp.c: src/main.c src/alloc.c specs/spec.c
	$(RUNTIME_CPP) $< > $@

main.pp.exec.c: main.pp.c
	cn --version | sed -n 's/^git-\([0-9a-f]\{9\}\).*/\1/p' > .cn_version
	cn instrument $<

main.pp.exec.o: main.pp.exec.c
	$(CC) -g -c -O0 -std=gnu11 -I$(RUNTIME_PREFIX)/include -Isrc -Iinclude -Wno-builtin-macro-redefined -Wno-unused-value -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS -include fulminate2.h $<

main.exe: main.pp.exec.o $(RUNTIME_LIB)/libcn_exec.a
	$(CC) $^ -L $(RUNTIME_LIB) -lcn_exec -o $@

.PHONY: cn-instrument
cn-instrument: main.exe
	./main.exe || lldb -S lldb_config_for_fulminate.lldb

.PHONY: cn-test-random
cn-test-random: src/alloc.c
	./test-random.sh --cc=$(CC)

.PHONY: cn-test-symbolic
cn-test-symbolic: src/alloc.c
	./test-symbolic.sh --cc=$(CC) \
		--skip=hyp_alloc

.PHONY: cn-test-symbolic-lite
cn-test-symbolic-lite: src/alloc.c
	./test-symbolic.sh --cc=$(CC) \
		--skip=my_list_is_last,chunk_list_del \
		--skip=chunk_list_insert \
		--skip=LemmaCreateNewChunk \
		--skip=LemmaCnChunkHdrsRevToCnChunkHdrs \
		--skip=LemmaConcatCnChunkHdrsRev \
		--skip=LemmaNextChunk \
		--skip=LemmaPrevChunk \
		--skip=chunk_install \
		--skip=chunk_reclaimable \
		--skip=chunk_destroyable \
		--skip=LemmaLsegToChunkHdrs \
		--skip=chunk_recycle \
		--skip=LemmaGetLastChunk \
		--skip=get_free_chunk \
		--skip=setup_first_chunk \
		--skip=LemmaCnChunkHdrsRevToCnHypAllocator \
		--skip=chunk_merge \
		--skip=chunk_inc_map \
		--skip=chunk_can_split \
		--skip=brain_exploding_calculation \
		--skip=hyp_alloc \
		--skip=hyp_free

.PHONY: clean
clean:
	rm -f tmp-alloc.c
	rm -f *~
	rm -f *.pp.c
	rm -f *.exec.c
	rm -f *.exec.o
	rm -f *.exe
	rm -rf _test_symbolic
	rm -rf _test_random

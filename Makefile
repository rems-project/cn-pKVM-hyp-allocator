# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

CC = clang-19

# includes adapted from _build/compile_commands.json
INCLUDES= -Isrc -Iinclude

# KM version
INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=$(CC) -std=c11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

# Fulminate
RUNTIME_PREFIX = $(OPAM_SWITCH_PREFIX)/lib/cn/runtime
RUNTIME_LIB = $(RUNTIME_PREFIX)
# RUNTIME_INCLUDES= -Isrc -Iinclude
# RUNTIME_CPP = $(CC) -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -undef -D__x86_64__ -D__GNUC__="5" -D__cerb__ 
# RUNTIME_CPP = $(CC) -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__ 
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
	cn verify --no-vip $(if $(OPT), $(OPT)) $(if $(ONLY),--only=$(ONLY)) -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c

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

.PHONY: cn-test
cn-test: src/alloc.c
	cn test --no-run --output-dir=_test/ src/alloc.c -Isrc -Iinclude -D__cerb__ -DSTANDALONE -DNO_STATEMENT_EXPRS -d1
	CPPFLAGS="-std=c2x -include ../fulminate2.h $(CPPFLAGS)" ./_test/run_tests.sh

.PHONY: clean
clean:
	rm -f tmp-alloc.c
	rm -f *~
	rm -f *.pp.c
	rm -f *.exec.c
	rm -f *.exec.o
	rm -f *.exe

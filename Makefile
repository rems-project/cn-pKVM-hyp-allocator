# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

# includes adapted from _build/compile_commands.json
INCLUDES= -Isrc -Iinclude

# KM version
INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=clang-19 -std=c11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

# Fulminate
RUNTIME_PREFIX= $(OPAM_SWITCH_PREFIX)/lib/cn/runtime
# RUNTIME_INCLUDES= -Isrc -Iinclude
# RUNTIME_CPP=clang-19 -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -undef -D__x86_64__ -D__GNUC__="5" -D__cerb__ 
# RUNTIME_CPP=clang-19 -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__ 
RUNTIME_CPP=clang-19 -std=gnu11 -E -P -CC -isystem$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Werror -Wno-builtin-macro-redefined -D__cerb__  -undef -fkeep-system-includes  -Isrc -Iinclude  -DSTANDALONE -DNO_STATEMENT_EXPRS

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


.PHONY: cn-instrument
cn-instrument: src/alloc.c
	$(RUNTIME_CPP) src/main.c > main.pp.c
	cn instrument main.pp.c
	clang-19 -g -c -O0 -std=gnu11 -I$(RUNTIME_PREFIX)/include -Isrc -Iinclude -Wno-builtin-macro-redefined -Wno-unused-value -D__cerb__   -DSTANDALONE -DNO_STATEMENT_EXPRS -include fulminate2.h main.pp.exec.c
	clang-19 -I$(RUNTIME_PREFIX)/include -Isrc -Iinclude -o main.exe $(RUNTIME_PREFIX)/libcn_exec.a main.pp.exec.o
	./main.exe


.PHONY: clean
clean:
	rm -f tmp-alloc.c
	rm -f *~
	rm -f *.exec.c
	rm -f *.exec.o
	rm -f *.exe

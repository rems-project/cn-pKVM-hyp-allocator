# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

# includes adapted from _build/compile_commands.json
INCLUDES= -Isrc -Iinclude

# KM version
INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=cc -std=c11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

# Fulminate
RUNTIME_PREFIX= $(OPAM_SWITCH_PREFIX)/lib/cn/runtime
RUNTIME_INCLUDES= -Isrc -Iinclude
# RUNTIME_CPP=clang-19 -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -undef -D__x86_64__ -D__GNUC__="5" -D__cerb__ 
# RUNTIME_CPP=clang-19 -std=gnu11 -E -P -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__ 

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
	$(CPP) -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/main.c > main.pp.c
	cn instrument main.pp.c
	cc -g -c -O0 -std=gnu11 -I$(RUNTIME_PREFIX)/include/ main.pp.exec.c main.pp.cn.c


.PHONY: clean
clean:
	rm -f tmp-alloc.c
	rm -f *~

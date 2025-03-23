# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

# includes adapted from _build/compile_commands.json 
INCLUDES= -Isrc  -Iinclude

# KM version
INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=cc -std=c11 -E -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

tmp-alloc.c: src/alloc.c
	$(CPP) -DSTANDALONE $(INCLUDES) src/alloc.c > tmp-alloc.c



cn-verify-via-cpp: tmp-alloc.c
	cn verify tmp-alloc.c


cn-verify: src/alloc.c
	cn verify -DSTANDALONE $(INCLUDES) src/alloc.c

clean:
	rm -f tmp-alloc.c
	rm -f *~

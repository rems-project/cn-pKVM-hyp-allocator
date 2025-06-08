# attempts to run CN frontend on alloc.c, via an explicit cpp and direct

# includes adapted from _build/compile_commands.json 
INCLUDES= -Isrc  -Iinclude

# KM version
INCLUDES= -I$(OPAM_SWITCH_PREFIX)/lib/cerberus-lib/runtime/libc/include/ -Isrc -Iinclude
CPP=cc -std=c11 -E -CC -Werror -Wno-builtin-macro-redefined -nostdinc -undef -D__cerb__

tmp-alloc.c: src/alloc.c
	$(CPP) -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c > tmp-alloc.c



cn-verify-via-cpp: tmp-alloc.c
	cn verify tmp-alloc.c


cn-verify: src/alloc.c
	cn verify -DSTANDALONE -DNO_STATEMENT_EXPRS $(INCLUDES) src/alloc.c

clean:
	rm -f tmp-alloc.c
	rm -f *~

realclean:
	$(MAKE) clean
	rm -rf _build/ compile_commands.json 

mesonninja:
	meson setup _build
	ninja -C _build

# Arm build attempts for read-dwarf

# meson/ninja compile command for reference
# cc -Isrc/main.p -Isrc -I../src -I../include -fdiagnostics-color=always -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -O0 -g -fno-strict-aliasing -DSTANDALONE -MD -MQ src/main.p/alloc.c.o -MF src/main.p/alloc.c.o.d -o src/main.p/alloc.c.o -c ../src/alloc.c


# first try just with these local files

CLANG_CMD = clang -c -target aarch64 -v -gdwarf-4 -Wall -Wpedantic -std=c11 

alloc.O0.local.o: src/alloc.c Makefile
	$(CLANG_CMD)  -Isrc -Iinclude -fdiagnostics-color=always -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -O0 -g -fno-strict-aliasing -DSTANDALONE  -o alloc.O0.o -c src/alloc.c

# ... that complains /usr/include/stdlib.h:26:10: fatal error: 'bits/libc-header-start.h' file not found


# second try with the Linux header files (though for that I should presumably be using an unmodified alloc.c)

LINUX=~/repos/linux

LINUX_CLANG_CMD= clang -c \
 -nostdinc \
 -I$(LINUX)/arch/arm64/include \
 -I$(LINUX)/arch/arm64/include/generated \
 -I$(LINUX)/include \
 -I$(LINUX)/arch/arm64/include/uapi \
 -I$(LINUX)/arch/arm64/include/generated/uapi \
 -I$(LINUX)/include/uapi \
 -I$(LINUX)/include/generated/uapi \
 -include $(LINUX)/include/linux/compiler-version.h \
 -include $(LINUX)/include/linux/kconfig.h \
 -include $(LINUX)/include/linux/compiler_types.h \
 -I$(LINUX)/arch/arm64/kvm/hyp/include 



alloc.O0.linux.o: src/alloc.c Makefile
	$(LINUX_CLANG_CMD)  -Isrc -Iinclude -fdiagnostics-color=always -D_FILE_OFFSET_BITS=64 -Wall -Winvalid-pch -O0 -g -fno-strict-aliasing -DSTANDALONE  -o alloc.O0.o -c src/alloc.c

# ... that complains /home/pes20/repos/linux/include/linux/kconfig.h:5:10: fatal error: 'generated/autoconf.h' file not found



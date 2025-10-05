CC=clang
BUILD=build
INCLUDES=stddef.h posix_types.h getorder.h

.PHONY: clean run

run: $(BUILD)/driver.exe
	$<

$(BUILD)/driver.pp.c: driver.c page_alloc.c $(INCLUDES)
	mkdir -p $(BUILD)
	$(CC) -E -P -CC $< > $@

$(BUILD)/driver.pp.exec.c: $(BUILD)/driver.pp.c
	cn instrument $< --output=driver.pp.exec.c --output-dir=$(BUILD)
	mv $@ $@~
	sed -e"/ cerb::hidden .*bswap64/d" < $@~ > $@

$(BUILD)/driver.pp.exec.o: $(BUILD)/driver.pp.exec.c
	$(CC) -g -c -O0 -std=gnu11 -I$(OPAM_SWITCH_PREFIX)/lib/cn/runtime/include $< -o $@

$(BUILD)/driver.exe: $(BUILD)/driver.pp.exec.o
	$(CC) $< -o $@ $(OPAM_SWITCH_PREFIX)/lib/cn/runtime/libcn_exec.a -L$(OPAM_SWITCH_PREFIX)/lib/cn/runtime -lcn_exec

clean:
	rm -rf $(BUILD)

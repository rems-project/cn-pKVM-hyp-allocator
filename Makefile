
# includes adapted from _build/compile_commands.json 
INCLUDES= -Isrc  -Iinclude

cn-verify-via-cpp: src/alloc.c
	cpp -DSTANDALONE $(INCLUDES) src/alloc.c tmp-alloc.c
	cn verify tmp-alloc.c


cn-verify: src/alloc.c
	cn verify -DSTANDALONE $(INCLUDES) src/alloc.c

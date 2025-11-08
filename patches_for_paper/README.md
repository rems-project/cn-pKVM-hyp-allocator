## Darcy patch

### Diff

- Removed a single statement in the precondition
- Removed proof annotations 

### CN proof

```
[1/1]: cut_out_chunk_install -- fail
src/alloc.c:1538:9: error: Missing resource for writing
        chunk->mapped_size = prev_mapped_size - prev->mapped_size;
        ~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
Resource needed: W<unsigned int>(&chunk->mapped_size)
State file: file:///var/folders/5_/bc8gln213hx04f4_d3p9p7dr0000gn/T/state__alloc.c__cut_out_chunk_install.html
```


This error message is not directly related to the specification error, which can be removed by adding proof annotations (which are in fact laborious) .
We want to know the spec error first, don't we?

### Bennet

./test-random.sh
```
Using seed: 3f012bbcae0c44ad
Testing alloc::cut_out_chunk_install: 0 runs, 1000 discards
FAILED TO GENERATE VALID INPUT

Testing Summary:
cases: 1, passed: 0, failed: 0, errored: 1, skipped: 0
```

### Fulminate

Just successfully terminates.

```
> make cn-instrument
...omitted...
./main.exe || lldb -S lldb_config_for_fulminate.lldb
> 
```

### Darcy

Finds an error!

```
************************ Failed at *************************
no source location found (try running with --exec-c-locs-mode enabled)Store failed.
  ==> 0x764[0] (0x764) not owned
********************** Failing input ***********************

void* p3 = malloc(40);
void* p4 = malloc(32);
*((struct hyp_allocator*)p3) = (struct hyp_allocator) { .chunks = (struct list_head) { .next = ((uintptr_t)p4 + 8), .prev = ((uintptr_t)p4 + 8) }, .start = 1561822816, .size = 4294967295, .lock = 9223372036854775807 };
*((unsigned int*)p4) = 400;
*((unsigned int*)((uintptr_t)p4 + 4)) = 448;
*((struct list_head*)((uintptr_t)p4 + 8)) = (struct list_head) { .next = p3, .prev = p3 };
*((unsigned int*)((uintptr_t)p4 + 18)) = 0;
*((unsigned int*)((uintptr_t)p4 + 1c)) = 4294967295;
void* p5 = malloc(31);
*((unsigned char*)p5) = 255;
*((unsigned char*)((uintptr_t)p5 + 1)) = 0;
*((unsigned char*)((uintptr_t)p5 + 2)) = 255;
*((unsigned char*)((uintptr_t)p5 + 3)) = 0;
*((unsigned char*)((uintptr_t)p5 + 4)) = 0;
*((unsigned char*)((uintptr_t)p5 + 5)) = 255;
*((unsigned char*)((uintptr_t)p5 + 6)) = 0;
*((unsigned char*)((uintptr_t)p5 + 7)) = 255;
*((unsigned char*)((uintptr_t)p5 + 8)) = 255;
*((unsigned char*)((uintptr_t)p5 + 9)) = 0;
*((unsigned char*)((uintptr_t)p5 + a)) = 0;
*((unsigned char*)((uintptr_t)p5 + b)) = 0;
*((unsigned char*)((uintptr_t)p5 + c)) = 255;
*((unsigned char*)((uintptr_t)p5 + d)) = 0;
*((unsigned char*)((uintptr_t)p5 + e)) = 255;
*((unsigned char*)((uintptr_t)p5 + f)) = 255;
*((unsigned char*)((uintptr_t)p5 + 10)) = 0;
*((unsigned char*)((uintptr_t)p5 + 11)) = 255;
*((unsigned char*)((uintptr_t)p5 + 12)) = 255;
*((unsigned char*)((uintptr_t)p5 + 13)) = 0;
*((unsigned char*)((uintptr_t)p5 + 14)) = 0;
*((unsigned char*)((uintptr_t)p5 + 15)) = 0;
*((unsigned char*)((uintptr_t)p5 + 16)) = 255;
*((unsigned char*)((uintptr_t)p5 + 17)) = 255;
*((unsigned char*)((uintptr_t)p5 + 18)) = 255;
*((unsigned char*)((uintptr_t)p5 + 19)) = 255;
*((unsigned char*)((uintptr_t)p5 + 1a)) = 0;
*((unsigned char*)((uintptr_t)p5 + 1b)) = 0;
*((unsigned char*)((uintptr_t)p5 + 1c)) = 0;
*((unsigned char*)((uintptr_t)p5 + 1d)) = 0;
*((unsigned char*)((uintptr_t)p5 + 1e)) = 255;
struct chunk_hdr* chunk = (struct chunk_hdr*)(760);
size_t size = (size_t)(4227594208);
struct chunk_hdr* prev = (struct chunk_hdr*)(p4);
struct hyp_allocator* allocator = (struct hyp_allocator*)(p3);
cut_out_chunk_install(chunk, size, prev, allocator);

************************************************************


Testing Summary:
cases: 1, passed: 0, failed: 1, errored: 0, skipped: 0
```

## Fulminate patch

### Diff

- Changed the precondition (and postcondition) so that they only declare the ownership of `prev` chunk.
- Removed all the annotations of the leaf function (to show the effectiveness of fragmentary ownership)


### CN proof


# Supplementary material for Code-Specify-Test-Prove: Flexibly Integrating Separation Logic Specification into Conventional Workflows

This gives the code, specification, and CN proof of the stand-alone version of the pKVM hypervisor hyp allocator.

## Structure

The first two files below contain the implementation of the hyp allocator, specification, predicates for expressing global invariants, and proofs.

The example function `chunk_install` shown in the paper corresponds to lines 1410–1476 in `src/alloc.c`.

Its precondition and postcondition are defined by `ChunkInstallPre` and `ChunkInstallPost`, respectively.
As mentioned in the paper, the version of `chunk_install` presented there is simplified: it includes only the `else` branch of the first `if` statement in the original function - it handles only the case where `prev` is not `NULL`.
As one can see in the code here, the full precondition and postcondition become more complex once the other cases are included.

- `src/alloc.c`: the hyp allocator along with the specification, lemmas, and proofs
- `specs/spec.c`: the fundamental predicates used to specify the functions
- `include/linux/list.h`: list-related low-level functions with specs
- `src/shim.c`: minimal mock/stub implementations of hypervisor-level functions for local execution and verification
- `include/alloc.c`: header that defines the public API of the allocator
- `include/prelude.h`, `include/linux/container_of.h`, `include/linux/bitfield.h`, `include/linux/minmax.h`: minor macros and definitions
- `include/fulminate.h`: definitions for fulminate
- `benchmark/`: benchmark sets for partial specifications (`partial` directory) and buggy (`buggy` directory) specifications mentioned in the paper

## Renaming

We have renamed some predicate names and variables for presentation in the paper.
The following table shows the correspondence between the names used in the paper and those in the actual specification.

| paper                    | code                           |
| ------------------------ | ------------------------------ |
| barray                   | Cn_char_array                  |
| barray_with_offset       | Cn_char_array_with_offset      |
| Maybe_barray             | MaybeCn_char_array             |
| Maybe_barray_with_offset | MaybeCn_char_array_with_offset |
| hyp_allocator            | Cn_hyp_allocator               |
| ALIGN                    | cn_ALIGN                       |
| hdr_size                 | Cn_chunk_hdr_size              |
| cn_hdr                   | cn_chunk_hdr                   |
| cn_hdrs                  | cn_chunk_hdrs                  |
| Cn_hdrs                  | Cn_chunk_hdrs                  |

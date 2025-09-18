Upstream sources, no CN spec.

- `alloc.c`         — original file
- `alloc.pp.c`      — pre-processed in the Linux build environment
- `alloc.carved.c`  — carved version of the above, with only the relevant code
- `shim.h`          — makes cerberus happier

Carve roots:
`hyp_alloc,hyp_alloc_account,hyp_free,hyp_free_account,hyp_alloc_reclaimable,hyp_alloc_reclaim,hyp_alloc_refill,hyp_alloc_init,hyp_alloc_errno,hyp_alloc_missing_donations`

Run:
```
cerberus --include cerb.h alloc.carved.c --permissive --typecheck-core
cn instrument --include shim.h alloc.carved.c
```


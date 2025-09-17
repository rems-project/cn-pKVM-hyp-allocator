# pKVM heap allocator at EL2

WIP. Accurate as of 2025-09-17

## Run Fulminate on the carved, preprocessed heap allocator

Tried on Ubuntu (legion). 

Steps:

1. Extract the archive file `cn-el2-alloc.tar.zst` which is in this subdirectory:

```
tar --zstd -xvf cn-el2-alloc.tar.zst
```

This creates a `cn-el2-alloc` directory with the following files:

* README.md
* shim.h
* alloc.pp.c
* alloc.carved.c
* alloc.c
  
2. Create a new opam switch:

```
opam switch create el2-hyp-alloc ocaml-base-compiler.5.3.0
```

and switch to it:

```
eval $(opam env --switch=el2-hyp-alloc)
```


3. Clone David's Cerberus fork (https://github.com/pqwy/cerberus) and checkout to the right branch:

```
git checkout -b for-fulminate origin/for-fulminate
```

4. In the cerberus subdirectory, run the following opam commands:

```
opam pin add cerberus-lib.dev $(pwd)
opam pin add cerberus.dev $(pwd)
```


5. Now, in the parent directory, clone David's CN fork (https://github.com/pqwy/cn) and checkout to the right branch:

```
git checkout -b update-cerberus-for-fulminate+unions origin/update-cerberus-for-fulminate+unions
```

6. In the cn subdirectory, run the following opam commands:

```
opam install -- ignore-pin-depends ./cn.opam
```

7. Now cd back to `../cn-el2-alloc` and run Fulminate:

```
cn instrument --include shim.h alloc.carved.c
```

## TODO: Instructions on how to carve and preprocess allocator


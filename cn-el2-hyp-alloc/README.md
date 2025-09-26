# Fulminating hyp-alloc for EL2

WIP. Accurate as of 2025-09-17

## Run Fulminate on the carved, preprocessed heap allocator

Tried on Ubuntu (legion). 

Steps:
 
1. Create a new opam switch:

```
opam switch create el2-hyp-alloc ocaml-base-compiler.5.3.0
```

and switch to it:

```
eval $(opam env --switch=el2-hyp-alloc)
```


2. Clone David's Cerberus fork (https://github.com/pqwy/cerberus) and checkout to the right branch:

```
git checkout -b for-fulminate origin/for-fulminate
```

3. In the cerberus subdirectory, run the following opam commands:

```
opam pin add cerberus-lib.dev $(pwd)
opam pin add cerberus.dev $(pwd)
```


4. Now, in the parent directory, clone David's CN fork (https://github.com/pqwy/cn) and checkout to the right branch:

```
git checkout -b update-cerberus-for-fulminate+unions origin/update-cerberus-for-fulminate+unions
```

5. In the cn subdirectory, run the following opam commands:

```
opam install -- ignore-pin-depends ./cn.opam
```

6. Now cd to `el2-hyp-alloc` in the parent directory and run Fulminate:

```
cn instrument --include shim.h alloc.carved.c
```



## Instructions on how to carve and preprocess allocator


### Preprocess

1. Get the required commit of Linux locally.

**If you already have Linux cloned somewhere**

`cd` there, run `git fetch` and then run the following:

```
git worktree add ../SOMEWHERE/ELSE/linux 74ae8d16a996
```

`74ae8d16a996` is the commit hash of Linux that we (Hiro) have been CN-speccing, so here, we are checking out the required commit at the path `../SOMEWHERE/ELSE/linux`.

Now `cd` to `../SOMEWHERE/ELSE/linux` and checkout a new branch:

```
git checkout -b cn-el2
```


**If you don't have Linux locally** 

Clone it (warning: this takes a while):

```
git clone https://android-kvm.googlesource.com/linux
```

and checkout to the required commit on a new branch:

```
git checkout -b cn-el2 74ae8d16a996
```



2. **TODO: incomplete** Run the `pp` script:

```
CC=clang-19 pp pp arch/arm64/kvm/hyp/nvhe/alloc.c > alloc.pp.c
```




### Carve

TODO

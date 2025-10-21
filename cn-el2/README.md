# Fulminating hyp-alloc for EL2

For running Fulminate on the heap-allocator-for-EL2 file (`alloc.carved.c`), see
the [first section](#run-fulminate-on-the-preprocessed-carved-heap-allocator)
below. (For most use cases, this is probably all you need.)

For understanding how the sausage is made (i.e. how `alloc.carved.c` is
generated from the original `alloc.c` file in the pKVM source), read
[past the first section](#make-a-preprocessed-carved-heap-allocator) (at your own
risk).

## Run Fulminate on the preprocessed, carved heap allocator

Tried on Ubuntu (legion). 

Steps:
 
1. Create a new opam switch:
```bash
opam switch create el2-hyp-alloc ocaml-base-compiler.5.3.0
```
and switch to it:
```bash
eval $(opam env --switch=el2-hyp-alloc)
```

2. Clone [this Cerberus fork][cerberus-fork] and checkout the right branch:
```bash
git checkout -b el2-fulminate origin/el2-fulminate
```

3. In the cerberus subdirectory, run the following opam commands:
```bash
opam pin add cerberus-lib.dev $(pwd)
opam pin add cerberus.dev $(pwd)
```

4. Now, in the parent directory, clone [this CN fork][cn-fork] and checkout the right branch:
```bash
git checkout -b el2-fulminate origin/el2-fulminate
```

5. In the cn subdirectory, run the following opam commands:
```bash
opam install --ignore-pin-depends ./cn.opam
```

6. Now cd to `el2-hyp-alloc` in the parent directory and run Fulminate:
```bash
cn instrument --include shim.h --skip alternative_has_cap_likely --exec-c-locs-mode alloc.carved.c
```

`shim.h` is a crime in progress — it uses the C preprocessor to remove bits of
the file that Cerberus or CN don't support.

`alternative_has_cap_likey` is a function that should not be instrumented, for
reasons. It is even marked with `__attribute__((__no_instrument_function__))`;
but since we ignore attributes, we manually ask it to be skipped.

`alloc.carved.c` — at the time of writing — is the sacred litmus: the
non-annotated, but pre-processed and carved original source that was specced
(elsewhere in this repo). Until that file works, nothing possibly can.

[cerberus-fork]: https://github.com/pqwy/cerberus/tree/el2-fulminate
[cn-fork]: https://github.com/pqwy/cn/tree/el2-fulminate

## Make a preprocessed, carved heap allocator

Linux supports wide variety of environments, so the build system uses a
complicated network of conditional includes, some auto generated. A good idea is
to fully pre-process the target file ahead of time, creating a self-contained
source and exposing CN to a minimal number of degrees of freedom. The file can
then be carved, to shrink the language surface that we expose CN to.

### Get the sources

Check out the linux source tree at commit `74ae8d16a996`, the base commit that
pKVM allocator speccing work started from.

**If you already have Linux cloned somewhere**

Go there, `git fetch` to get the latest upstream, and make a parallel working
checkout with the same `.git` repository:
```bash
git worktree add -b this-new-branch ../SOMEWHERE/ELSE/linux.my.wip 74ae8d16a996
```

**If not** 

Clone it (warning: this takes a while):
```bash
git clone https://android-kvm.googlesource.com/linux
```
and checkout the required commit as a new branch:
```bash
git checkout -b this-new-branch 74ae8d16a996
```

### Configure the sources

No configuration, no generated includes. Follow your usual procedure to
configure an Aarch64 kernel with pKVM.

**When in panic**

At a minimum, get a working `.config`, for instance by reusing this random
config file that David has been using:
```bash
unzstd < /path/to/this/repo/davids-6.12-config.zst > /path/to/linux/checkout/.config
```
and running make to settle it into your environment and generate stuff:
```bash
make ARCH=arm64 LLVM=1 oldconfig
make ARCH=arm64 LLVM=1 -j16 arch/arm64/kvm/hyp/
```
(or remove the `arch/arm64/kvm/hyp/` subdir to build the entire kernel, as
needed)

### Make compile_commands.json

`compile_commands.json` is read by C LSP servers like clangd; it also serves as
a machine-readable export of the build environment. Generate the official
version:
```bash
scripts/clang-tools/gen_compile_commands.py
```
Note that it reflects the configuration environment. Changing the config, or
changing the build system -> regen the file.

### C pre-processor

Make sure you have the `jq` program installed. Confirm that the steps so far
worked by running
```bash
jq -r < compile_commands.json '.[]|select(.file|endswith("arm64/kvm/hyp/nvhe/alloc.c"))|.command'
```
and checking that it outputs a long and gnarly invocation of the C compiler. We
want to split that into pp and cc. First, save the command to a file:
```bash
jq -r < compile_commands.json '.[]|select(.file|endswith("arm64/kvm/hyp/nvhe/alloc.c"))|.command' \
    | sed -e's: \+:\n:g' -e "s:'\":\":g; s:\"':\":g" \
    | sed -e'1d; $d' > cc-args.master
```
`sed` 1) produces one arg per line, 2) removes one level of quoting (meant for
the shell) and 3) drops the argument file. `cc-args.master` can now be viewed,
e.g. `less cc-args.master`. Prepare a version without `-c` and `-o` flags:
```bash
sed < cc-args.master -e '/^-o$/{N;d}; /^-c$/d' > cc-args.pp
```
or by using an editor. `cc-args.pp` contains the remaining args. Then run the C
compiler in just the pre-processor mode:
```bash
clang -E -CC -P $(< cc-args.pp) arch/arm64/kvm/hyp/nvhe/alloc.c \
    | clang-format --style=WebKit > arch/arm64/kvm/hyp/nvhe/alloc.pp.c
```
`clang-format` slightly cleans the output up; and `WebKit` is the only standard
configuration that did not seem to take super-linear time.

The resulting `arm64/kvm/hyp/nvhe/alloc.pp.c` should be fully pre-processed and
make no references to other files. However, inlining the headers adds much more
code than needed.

### Carver

[Carver][carver] is used to remove code not directly referenced from the target file.

[Install it][carver]; if [this PR][carver-pr] is still open, use
[this branch][carver-fork] instead.

[carver]: https://github.com/rems-project/c-tree-carver
[carver-pr]: https://github.com/rems-project/c-tree-carver/pull/26
[carver-fork]: https://github.com/pqwy/c-tree-carver/tree/fix-segfault

Carver cannot consume the standard `compile_commands.json` format, requiring
relative paths. Save a copy of the file:
```bash
cp compile_commands.json compile_commands.original.json
```
assuming `/path/to/LINUX` is the absolute path to your linux working tree,
produce a relative-path version by running:
```bash
jq < compile_commands.original.json '[.[]|.file|=ltrimstr("/path/to/LINUX/")]' > compile_commands.json
```
The tool will use `compile_commands.json` to look up compiler args, but the
pre-processed file (`alloc.pp.c`) is not listed there. Move it in place of the
original:
```bash
cp arch/arm64/kvm/hyp/nvhe/alloc.c arch/arm64/kvm/hyp/nvhe/alloc.original.c
cp arch/arm64/kvm/hyp/nvhe/alloc.pp.c arch/arm64/kvm/hyp/nvhe/alloc.c
```

Finally, run the carver:
```bash
ROOT='hyp_alloc,hyp_alloc_account,hyp_free,hyp_free_account,hyp_alloc_reclaimable,hyp_alloc_reclaim,hyp_alloc_refill,hyp_alloc_init,hyp_alloc_errno,hyp_alloc_missing_donations'
c-tree-carve -p . -r $ROOTS arch/arm64/kvm/hyp/nvhe/alloc.c
```
It will reject the source file as not being valid C. Look at the error messages
and source locations, and correct them by hand using an editor; it should
involve adding newlines. Re-run the tool, as above. The last output line gives
the location of the output tree, somewhere in `/tmp/`. It contains only one
source file; copy it from there back into the linux source tree, as
`arch/arm64/kvm/hyp/nvhe/alloc.carved.c`.

## Fulminating the files

```bash
cn instrument --include shim.c alloc.which.ever.version.c
```

## C compiler

Prepare the arguments without forced `-include`s:
```bash
sed < cc-args.master -e '/^-include$/{N;d}' > cc-args.cc
```
and run the compiler:
```bash
EXTRA_FLAGS=(-Wno-unused-value)
clang $(< cc-args.cc) $EXTRA_FLAGS arch/arm64/kvm/hyp/nvhe/alloc.which.ever.version.c
```
which hopefully creates `arch/arm64/kvm/hyp/nvhe/alloc.nvhe.o`.


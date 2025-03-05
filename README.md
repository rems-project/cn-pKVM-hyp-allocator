# cn-pKVM-hyp-allocator

The code is copied from a snapshot of commit `74ae8d16a99681b567aa84d6ed643110ab4c3a76`
(in the `android16-6.12` branch: https://`android.googlesource.com/kernel/common/+/refs/heads/android16-6.12`)

* `arch/arm64/kvm/hyp/nvhe/alloc.c`
* `arch/arm64/kvm/hyp/include/nvhe/alloc.c`


## Building
You need `https://mesonbuild.com/` to build.

Initial setup after a clean checkout:

```
# meson setup builddir
```

Then to build:

```
# ninja -C builddir
```

This produces a test executable at `builddir/src/main`.

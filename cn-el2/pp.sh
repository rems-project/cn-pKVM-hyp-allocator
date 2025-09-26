#!/bin/zsh

CC=${CC:-clang}

RT_CPP_OPTS=(
	-std=gnu11
	-E
	-P
	-CC
	# -isystem${OPAM_SWITCH_PREFIX}/lib/cerberus-lib/runtime/libc/include/
	-Werror
	-Wno-builtin-macro-redefined
	-D__cerb__
	# -undef
	# -fkeep-system-includes
	# -Isrc
	# -Iinclude
	# -DSTANDALONE
	-DNO_STATEMENT_EXPRS
)

KERNEL_INC=(
	-include ./include/linux/compiler-version.h
	-include ./include/linux/kconfig.h
	-include ./include/linux/compiler_types.h
)

KERNEL_OPTS=(
	-Wp,-MMD,arch/arm64/kvm/hyp/nvhe/.alloc.nvhe.o.d
	-nostdinc
	-I./arch/arm64/include
	-I./arch/arm64/include/generated
	-I./include
	-I./arch/arm64/include/uapi
	-I./arch/arm64/include/generated/uapi
	-I./include/uapi
	-I./include/generated/uapi
	-D__KERNEL__
	--target=aarch64-linux-gnu
	-fintegrated-as
	-Werror=unknown-warning-option
	-Werror=ignored-optimization-argument
	-Werror=option-ignored
	-Werror=unused-command-line-argument
	-mlittle-endian
	-DKASAN_SHADOW_SCALE_SHIFT=
	-fmacro-prefix-map=./=
	-std=gnu11
	-fshort-wchar
	-funsigned-char
	-fno-common
	-fno-PIE
	-fno-strict-aliasing
	-mgeneral-regs-only
	-DCONFIG_CC_HAS_K_CONSTRAINT=1
	-Wno-psabi
	-fno-asynchronous-unwind-tables
	-fno-unwind-tables
	-mbranch-protection=pac-ret+bti
	-Wa,-march=armv8.5-a
	-DARM64_ASM_ARCH='"armv8.5-a"'
	-DKASAN_SHADOW_SCALE_SHIFT=
	-fno-delete-null-pointer-checks
	-O2
	-fstack-protector-strong
	-fno-omit-frame-pointer
	-fno-optimize-sibling-calls
	-ftrivial-auto-var-init=zero
	-fno-stack-clash-protection
	-falign-functions=4
	-fstrict-flex-arrays=3
	-fno-strict-overflow
	-fno-stack-check
	-Wall
	-Wundef
	-Werror=implicit-function-declaration
	-Werror=implicit-int
	-Werror=return-type
	-Werror=strict-prototypes
	-Wno-format-security
	-Wno-trigraphs
	-Wno-frame-address
	-Wno-address-of-packed-member
	-Wframe-larger-than=2048
	-Wno-gnu
	-Wvla
	-Wno-pointer-sign
	-Wcast-function-type
	-Wimplicit-fallthrough
	-Werror=date-time
	-Werror=incompatible-pointer-types
	-Wenum-conversion
	-Wextra
	-Wunused
	-Wno-unused-but-set-variable
	-Wno-unused-const-variable
	-Wno-format-overflow
	-Wno-format-overflow-non-kprintf
	-Wno-format-truncation-non-kprintf
	-Wno-override-init
	-Wno-pointer-to-enum-cast
	-Wno-tautological-constant-out-of-range-compare
	-Wno-unaligned-access
	-Wno-enum-compare-conditional
	-Wno-missing-field-initializers
	-Wno-type-limits
	-Wno-shift-negative-value
	-Wno-enum-enum-conversion
	-Wno-sign-compare
	-Wno-unused-parameter
	-g
	-fno-var-tracking
	-mstack-protector-guard=sysreg
	-mstack-protector-guard-reg=sp_el0
	-mstack-protector-guard-offset=1192
	-Iarch/arm64/kvm/hyp/include
	-fno-asynchronous-unwind-tables
	-fno-unwind-tables
	-D__KVM_NVHE_HYPERVISOR__
	-D__DISABLE_EXPORTS
	-D__DISABLE_TRACE_MMIO__
	-fno-stack-protector
	-DDISABLE_BRANCH_PROFILING
	-DKBUILD_MODFILE='"arch/arm64/kvm/hyp/nvhe/alloc.nvhe"'
	-DKBUILD_BASENAME='"alloc.nvhe"'
	-DKBUILD_MODNAME='"alloc.nvhe"'
	-D__KBUILD_MODNAME=kmod_alloc.nvhe
)

MORE_OPTS=(
	-Wno-builtin-macro-redefined
	-Wno-macro-redefined
	-Wno-unused-value
	-Wno-self-assign
	-Wno-misleading-indentation
	-Wno-comment
)

cmd=$1
shift

case $cmd in
	pp)
		$CC $RT_CPP_OPTS $KERNEL_INC $KERNEL_OPTS $MORE_OPTS $@ | clang-format --style=WebKit
		;;
	cc)
		# $CC $KERNEL_INC $KERNEL_OPTS $MORE_OPTS -c $@
		$CC $KERNEL_OPTS $MORE_OPTS -c $@
		;;
	*)
		echo Wat >&2
		exit 1
		;;
esac

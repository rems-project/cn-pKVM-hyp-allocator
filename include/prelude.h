/*
 * TODO(doc): this header contains cutdowns of headers from linux
 * which is under GPLv2
 */
#ifndef _PRELUDE_H
#define _PRELUDE_H

#include <stdbool.h>
#include <stddef.h> // offsetof()
#include <stdlib.h>
#ifndef __cerb__
#include <stdio.h>
#endif
#include <inttypes.h>
#include <string.h> // memset()


typedef uint8_t		u8;
typedef uint32_t	u32;
typedef uint64_t	u64;

typedef u64		phys_addr_t;

#define U32_MAX		((u32)~0U)
#define U8_MAX		((u8)~0U)


#ifdef __cerb__
// TODO
#define __aligned(x)
#define __attribute__(x)
#else
#define __aligned(x)		__attribute__((__aligned__(x)))
#endif

#ifdef __cerb__
// TODO
#define BUILD_BUG_ON(cond)
#define WARN_ON(condition)	(!!(condition))
#else
#define BUILD_BUG_ON(cond)	\
	_Static_assert(!(cond), "BUILD_BUG_ON failed: " #cond)
#define WARN_ON(condition) ({							\
	int __ret_warn_on = !!(condition);					\
	if (__ret_warn_on)							\
		fprintf(stderr, "WARN_ON: %s - %d\n", __FILE__, __LINE__);	\
	__ret_warn_on;								\
})
#endif


#define __ALIGN_KERNEL(x, a)	\
	__ALIGN_KERNEL_MASK(x, (typeof(x))(a) - 1)
#define __ALIGN_KERNEL_MASK(x, mask)	(((x) + (mask)) & ~(mask))

#define ALIGN(x, a)		__ALIGN_KERNEL((x), (a))
#define ALIGN_DOWN(x, a)	__ALIGN_KERNEL((x) - ((a) - 1), (a))

#define PAGE_ALIGN(addr)	ALIGN(addr, PAGE_SIZE)
#define PAGE_ALIGN_DOWN(addr)	ALIGN_DOWN(addr, PAGE_SIZE)

#define IS_ALIGNED(x, a)	(((x) & ((typeof(x))(a) - 1)) == 0)
#define PAGE_ALIGNED(addr)	IS_ALIGNED((unsigned long)(addr), PAGE_SIZE)

#define READ_ONCE(x)	(*(const volatile typeof(x) *)&(x))

#define WRITE_ONCE(x, val)						\
do {									\
	*(volatile typeof(x) *)&(x) = (val);				\
} while (0)

/*
 * From include/uapi/asm-generic/errno-base.h *********************************
 */
#define	E2BIG		 7	/* Argument list too long */
#define	ENOMEM		12	/* Out of memory */
#define	EBUSY		16	/* Device or resource busy */
#define	EINVAL		22	/* Invalid argument */

// /*@ function (i32) EINVAL() @*/
// static int c_EINVAL() /*@ cn_function EINVAL; @*/
// {
// 	return EINVAL;
// }
/*@
function (i32) EINVAL() {
	22i32
}
@*/

#include <linux/bitfield.h>
#include <linux/minmax.h>
#include <linux/list.h>

// TODO: spinlock
typedef u64		hyp_spinlock_t;
#define hyp_spin_lock_init(X)
void hyp_spin_lock(hyp_spinlock_t *lock);
void hyp_spin_unlock(hyp_spinlock_t *lock);

// TODO: we probably don't care about this for CN
#define kvm_flush_dcache_to_poc(X,Y)

// TODO: per-cpu stuff (for now fixing to only one CPU)
#define DEFINE_PER_CPU(TY, X)	TY X
#define this_cpu_ptr(X)		(X)
#define per_cpu_ptr(ptr, cpu)	(ptr)


// TODO: this is hardcoding 4K pages
#define PAGE_SHIFT		12
#define PAGE_SIZE		(1UL << PAGE_SHIFT)
#define PAGE_MASK		(~(PAGE_SIZE-1))

// HK: we cannot define c_PAGE_ALIGN_DOWN until here because PAGE_SIZE is defined just above.
// /*@ function (u64) PAGE_ALIGN_DOWN(u64 addr) @*/
static unsigned long c_PAGE_ALIGN_DOWN(unsigned long long addr)
// /*@ cn_function PAGE_ALIGN_DOWN; @*/
{
	return PAGE_ALIGN_DOWN(addr);
}

// /*@ function (u64) PAGE_ALIGN(u64 addr) @*/
// static unsigned long c_PAGE_ALIGN(unsigned long long addr) /*@  cn_function PAGE_ALIGN; @*/
// {
// 	return PAGE_ALIGN(addr);
// }

/*@
function (u64) PAGE_ALIGN_DOWN(u64 addr) {
	let page_mask = shift_left(1u64, 12u64) - 1u64;
	(addr & ~page_mask)
}
function (u64) PAGE_ALIGN(u64 addr) {
	let page_mask = shift_left(1u64, 12u64) - 1u64;
	(addr + page_mask) & ~page_mask
}
@*/

/*
 * KVM MEMCACHE ***************************************************************
 */
struct kvm_hyp_memcache {
	phys_addr_t head;
	unsigned long nr_pages;
	unsigned long flags;
};

static inline void push_hyp_memcache(struct kvm_hyp_memcache *mc,
				     phys_addr_t *p,
				     phys_addr_t (*to_pa)(void *virt),
				     unsigned long order)
{
	*p = mc->head;
	mc->head = (to_pa(p) & PAGE_MASK) |
		   FIELD_PREP(~PAGE_MASK, order);
	mc->nr_pages++;
}
static inline void *pop_hyp_memcache(struct kvm_hyp_memcache *mc,
				     void *(*to_va)(phys_addr_t phys),
				     unsigned long *order)
{
	phys_addr_t *p = to_va(mc->head & PAGE_MASK);
	if (!mc->nr_pages) {
		return NULL;
	}
	*order = FIELD_GET(~PAGE_MASK, mc->head);
	mc->head = *p;
	mc->nr_pages--;
	return p;
}

static inline int __topup_hyp_memcache(struct kvm_hyp_memcache *mc,
				       unsigned long min_pages,
				       void *(*alloc_fn)(void *arg, unsigned long order),
				       phys_addr_t (*to_pa)(void *virt),
				       void *arg,
				       unsigned long order)
{
	while (mc->nr_pages < min_pages) {
		phys_addr_t *p = alloc_fn(arg, order);
		if (!p) {
			return -ENOMEM;
		}
		push_hyp_memcache(mc, p, to_pa, order);
	}
	return 0;
}

int refill_memcache(struct kvm_hyp_memcache *mc, unsigned long min_pages,
		    struct kvm_hyp_memcache *host_mc);


phys_addr_t __pkvm_private_range_pa(void *va);
int __pkvm_hyp_donate_host(u64 pfn, u64 nr_pages);

void pkvm_remove_mappings(void *from, void *to);
void *hyp_phys_to_virt(phys_addr_t phys);
phys_addr_t hyp_virt_to_phys(void *addr);
u64 hyp_virt_to_pfn(void *addr);
int __hyp_allocator_map(unsigned long start, phys_addr_t phys);
int pkvm_alloc_private_va_range(size_t size, unsigned long *haddr);


u32 hash_32(u32 val, unsigned int bits);
u32 hash_64(u64 val, unsigned int bits);

#endif /* _PRELUDE_H */

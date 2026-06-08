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

#ifdef __cerb__
#define size_t unsigned long
#endif

typedef uint8_t		u8;
typedef uint32_t	u32;
typedef uint64_t	u64;
#ifdef __CN_VERIFY
[[cerb::byte]]
#endif
typedef unsigned char	byte;

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
function (u64) cn_ALIGN(u64 x, u64 a) {
	(x + (a - 1u64)) & ~(a - 1u64)
}
@*/

#include <linux/bitfield.h>
#include <linux/minmax.h>
#include <linux/list.h>

// TODO: spinlock
typedef u64		hyp_spinlock_t;
/* CN DIFF */
// HK: dummy init
#define hyp_spin_lock_init(X) { *X = 0; }
void hyp_spin_lock(hyp_spinlock_t *lock);
void hyp_spin_unlock(hyp_spinlock_t *lock);

// TODO: we probably don't care about this for CN
#define kvm_flush_dcache_to_poc(X,Y)

// TODO: per-cpu stuff (for now fixing to only one CPU)
#define DEFINE_PER_CPU(TY, X)	TY X
#define this_cpu_ptr(X)		(X)
#define per_cpu_ptr(ptr, cpu)	(ptr)


// TODO: this is hardcoding 4K pages
#define PAGE_SHIFT		12UL
#define PAGE_SIZE		(1UL << PAGE_SHIFT)
#define PAGE_MASK		(~(PAGE_SIZE-1))

/*@

function (u64) PAGE_SIZE() {
	shift_left(1u64, 12u64)
}

function (u64) CN_PAGE_MASK() {
	~(PAGE_SIZE() - 1u64)
}

function (u64) CN_MEMCACHE_ORDER(phys_addr_t head) {
	head & (PAGE_SIZE() - 1u64)
}

function (pointer) this_cpu_ptr(pointer p) {
	p
}

function (boolean) cn_IS_ALIGNED(u64 addr) {
	(addr & (PAGE_SIZE() - 1u64)) == 0u64
}

@*/

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

void *hyp_phys_to_virt(phys_addr_t phys);
phys_addr_t hyp_virt_to_phys(void *addr);

/*@
datatype cn_memcache_pages {
	Mc_nil {},
	Mc_cons { u64 page, datatype cn_memcache_pages tail }
}

type_synonym cn_hyp_memcache = {
	phys_addr_t head,
	u64 nr_pages,
	u64 flags,
	datatype cn_memcache_pages pages
}

function [rec] (u64) Cn_memcache_pages_len(datatype cn_memcache_pages pages) {
	match pages {
		Mc_nil {} => { 0u64 }
		Mc_cons { page: _, tail: tail } => { 1u64 + Cn_memcache_pages_len(tail) }
	}
}

function [rec] (datatype cn_memcache_pages) Cn_memcache_pages_push(u64 page,
								   datatype cn_memcache_pages pages) {
	Mc_cons { page: page, tail: pages }
}

function (datatype cn_memcache_pages) Cn_memcache_pages_pop(datatype cn_memcache_pages pages) {
	match pages {
		Mc_nil {} => { Mc_nil {} }
		Mc_cons { page: _, tail: tail } => { tail }
	}
}

predicate [nounfold] void Cn_char_array(pointer p, u64 size)
{
	take U = each(u64 i; 0u64 <= i && i < size) {
		W<byte>(array_shift<byte>(p, i))
	};
	return;
}

predicate void Cn_char_array_with_offset(pointer p, u64 size, u64 offset)
{
	take U = each(u64 i; offset <= i && i < offset + size) {
		W<byte>(array_shift<byte>(p, i))
	};
	return;
}

predicate void Conditional_Cn_char_array(pointer p, u64 size, boolean cond)
{
	if (cond) {
		take U = Cn_char_array(p, size);
		return;
	} else {
		return;
	}
}

predicate void MaybeCn_char_array(pointer p, u64 size)
{
	if (is_null(p)) {
		return;
	} else {
		take U = Cn_char_array(p, size);
		return;
	}
}

predicate void MaybeCn_char_array_with_offset(pointer p, u64 size, u64 offset)
{
	if (is_null(p)) {
		return;
	} else {
		take U = Cn_char_array_with_offset(p, size, offset);
		return;
	}
}

predicate (phys_addr_t) Cn_split_page(pointer page_token, u64 page)
{
	assert(cn_IS_ALIGNED(page));
	take Next = RW<phys_addr_t>((pointer)page);
	take Rest = Cn_char_array(array_shift<byte>((pointer)page, 8u64), PAGE_SIZE() - 8u64);
	return Next;
}

predicate (void) Conditional_Cn_split_page(pointer page_token, u64 page, boolean cond)
{
	if (cond) {
		take Page = Cn_split_page(page_token, page);
		return;
	} else {
		return;
	}
}

predicate void Cn_memset_buffer(pointer p, u64 size)
{
	if (size == PAGE_SIZE() && cn_IS_ALIGNED((u64)p)) {
		take Page = Cn_split_page(p, (u64)p);
		return;
	} else {
		take Bytes = Cn_char_array(p, size);
		return;
	}
}

predicate [rec] (datatype cn_memcache_pages) Cn_memcache_page_list(pointer page_token, u64 page, u64 nr_pages) {
	if (nr_pages == 0u64) {
		return Mc_nil {};
	} else {
		take Next = Cn_split_page(page_token, page);
		take Tail = Cn_memcache_page_list((pointer)Next, Next, nr_pages - 1u64);
		return Mc_cons { page: (u64)page, tail: Tail };
	}
}

predicate (cn_hyp_memcache) Cn_hyp_memcache(pointer mc) {
	take Head = RW<phys_addr_t>(member_shift<struct kvm_hyp_memcache>(mc, head));
	take Nr = RW<unsigned long>(member_shift<struct kvm_hyp_memcache>(mc, nr_pages));
	take Flags = RW<unsigned long>(member_shift<struct kvm_hyp_memcache>(mc, flags));
	take Pages = Cn_memcache_page_list((pointer)Head, Head, Nr);
	return { head: Head, nr_pages: Nr, flags: Flags, pages: Pages };
}

predicate (void) Conditional_phys_addr_RW(pointer p, boolean cond)
{
	if (cond) {
		take Page = RW<phys_addr_t>(p);
		return;
	} else {
		return;
	}
}

predicate [rec] void Cn_page_cells(pointer page, u64 nr_pages) {
	if (nr_pages == 0u64) {
		return;
	} else {
		take Page = RW<phys_addr_t>(page);
		take Tail = Cn_page_cells(array_shift<phys_addr_t>(page, 512u64), nr_pages - 1u64);
		return;
	}
}

predicate [rec] void Cn_page_cells_i32(pointer page, i32 nr_pages) {
	if (nr_pages <= 0i32) {
		return;
	} else {
		take Page = RW<phys_addr_t>(page);
		take Tail = Cn_page_cells_i32(array_shift<phys_addr_t>(page, 512u64), nr_pages - 1i32);
		return;
	}
}
@*/

static inline void push_hyp_memcache(struct kvm_hyp_memcache *mc,
				     phys_addr_t *p,
				     phys_addr_t (*to_pa)(void *virt),
				     unsigned long order)
#ifdef __CN_VERIFY
/*@
	requires
		take MC_pre = Cn_hyp_memcache(mc);
		take P_pre = Cn_split_page(p, (u64)p);
		order == 0u64;
		cn_IS_ALIGNED((u64)p);
		MC_pre.nr_pages < MAXu64();
		to_pa == &hyp_virt_to_phys;
	ensures
		take MC_post = Cn_hyp_memcache(mc);
		MC_post.nr_pages == MC_pre.nr_pages + 1u64;
		MC_post.flags == MC_pre.flags;
		MC_post.pages == Mc_cons { page: (u64)p, tail: MC_pre.pages };
@*/
#endif
{
	*p = mc->head;
#ifdef __CN_VERIFY
	/*@ assert(*p == MC_pre.head); @*/
#endif
#ifdef __CN_VERIFY
	mc->head = (phys_addr_t)p;
#else
	mc->head = (to_pa(p) & PAGE_MASK) |
		   FIELD_PREP(~PAGE_MASK, order);
#endif
#ifdef __CN_VERIFY
	/*@ assert(mc->head == (u64)p); @*/
	/*@ assert((mc->head & CN_PAGE_MASK()) == (u64)p); @*/
#endif
	mc->nr_pages++;
#ifdef __CN_VERIFY
	/*@ assert(mc->nr_pages == MC_pre.nr_pages + 1u64); @*/
	/*@ assert((mc->head & CN_PAGE_MASK()) == (u64)p); @*/
#endif
}
static inline void *pop_hyp_memcache(struct kvm_hyp_memcache *mc,
				     void *(*to_va)(phys_addr_t phys),
				     unsigned long *order)
#ifdef __CN_VERIFY
/*@
	requires
		take MC_pre = Cn_hyp_memcache(mc);
		take Order_pre = W<unsigned long>(order);
		MC_pre.nr_pages > 0u64;
		to_va == &hyp_phys_to_virt;
	ensures
		take MC_post = Cn_hyp_memcache(mc);
		take Order_post = RW<unsigned long>(order);
		take Page = Cn_split_page(return, (u64)return);
		return == (pointer)(MC_pre.head & CN_PAGE_MASK());
		Order_post == CN_MEMCACHE_ORDER(MC_pre.head);
		MC_post.nr_pages == MC_pre.nr_pages - 1u64;
		MC_post.flags == MC_pre.flags;
		MC_post.pages == Cn_memcache_pages_pop(MC_pre.pages);
@*/
#endif
{
	phys_addr_t *p = to_va(mc->head & PAGE_MASK);
#ifdef __CN_VERIFY
	/*@ assert(p == (pointer)(MC_pre.head & CN_PAGE_MASK())); @*/
	/*@ unpack Cn_memcache_page_list((pointer)MC_pre.head, MC_pre.head, MC_pre.nr_pages); @*/
	/*@ assert((MC_pre.head & CN_PAGE_MASK()) == MC_pre.head); @*/
	/*@ assert(p == (pointer)MC_pre.head); @*/
#endif
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
u64 hyp_virt_to_pfn(void *addr);
int __hyp_allocator_map(unsigned long start, phys_addr_t phys);
int pkvm_alloc_private_va_range(size_t size, unsigned long *haddr);


u32 hash_32(u32 val, unsigned int bits);
u32 hash_64(u64 val, unsigned int bits);

#endif /* _PRELUDE_H */

// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2023 Google LLC
 * Author: Vincent Donnefort <vdonnefort@google.com>
 */
/*
 * TODO(doc): this header contains cutdowns of headers from linux
 * which is under GPLv2
 */
#include <stdbool.h> /* clang -E -fkeep-system-includes */
#include <stddef.h> /* clang -E -fkeep-system-includes */

#include <stdlib.h> /* clang -E -fkeep-system-includes */

#include <inttypes.h> /* clang -E -fkeep-system-includes */

#include <string.h> /* clang -E -fkeep-system-includes */

typedef uint8_t u8;
typedef uint32_t u32;
typedef uint64_t u64;
typedef u64 phys_addr_t;
// TODO
// TODO
/*
 * From include/uapi/asm-generic/errno-base.h *********************************
 */
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
/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (C) 2014 Felix Fietkau <nbd@nbd.name>
 * Copyright (C) 2004 - 2009 Ivo van Doorn <IvDoorn@gmail.com>
 */
/*
 * This is a cutdown version of include/linux/bitfield.h
 */
/**
 * FIELD_PREP() - prepare a bitfield element
 * @_mask: shifted mask defining the field's length and position
 * @_val:  value to put in the field
 *
 * FIELD_PREP() masks and shifts up the value.  The result should
 * be combined with other fields of the bitfield using logical OR.
 */
/**
 * FIELD_GET() - extract a bitfield element
 * @_mask: shifted mask defining the field's length and position
 * @_reg:  value of entire bitfield
 *
 * FIELD_GET() extracts the field specified by @_mask from the
 * bitfield passed in as @_reg by masking and shifting it down.
 */
/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/minmax.h
 */
// PS addition, following KM - hardcoding 0 rather than x to make it look like a constant for now
/*
 * TODO: commenting-out type checking (signedness compatibility). We should
 * bring it back.
 */
// #define __cmp_once(op, x, y, unique_x, unique_y) ({
// 	typeof(x) unique_x = (x);
// 	typeof(y) unique_y = (y);
// 	static_assert(__types_ok(x, y),
// 		#op "(" #x ", " #y ") signedness error, fix types or consider u" #op "() before " #op "_t()");
// 	__cmp(op, unique_x, unique_y); })
// This delays the concatenation to allow the expension of __COUNTER__
// From linux source at include/linux/compiler.h
/* Not-quite-unique ID. */
static inline u32 min_u32(u32 x, u32 y)
/*@
	ensures return == (x < y ? x : y);
@*/
{
 return ((x) < (y) ? (x) : (y));
}
static inline u64 min_u64(u64 x, u64 y)
/*@
	ensures return == (x < y ? x : y);
@*/
{
 return ((x) < (y) ? (x) : (y));
}
static inline u64 max_u64(u64 x, u64 y)
/*@
	ensures return == (x > y ? x : y);
@*/
{
 return ((x) > (y) ? (x) : (y));
}
/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/list.h
 */
/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/container_of.h
 */
// DUMMY
/**
 * container_of - cast a member of a structure out to the containing structure
 * @ptr:    the pointer to the member.
 * @type:   the type of the container struct this is embedded in.
 * @member: the name of the member within the struct.
 *
 * WARNING: any const qualifier of @ptr is lost.
 */
// hack suggested by Kayvan: https://rems-chat.cl.cam.ac.uk/rems/pl/iarhiqj8dfrzujo3m1zysssoir
// TODO: Change unsigned char * back to void * once Cerberus allows (non-ISO) pointer arithmetic on void *

// This is defined in include/linux/types.h
struct list_head {
 struct list_head *next, *prev;
};
/*@
datatype list_head_option
{
		List_Head_None {},
		List_Head_Some { struct list_head L }
}
predicate(datatype list_head_option) CondListHead(pointer p, boolean condition)
{
		if (condition)
		{
				take L = RW<struct list_head>(p);
				return List_Head_Some{L : L};
		}
		else
		{
				return List_Head_None{};
		}
}
@*/
/**
 * list_empty - tests whether a list is empty
 * @head: the list to test.
 */
static inline int list_empty(const struct list_head *head)
/*@
	requires
		take H_pre = RW<struct list_head>(head);
	ensures
		take H_post = RW<struct list_head>(head);
		return == (ptr_eq(H_post.next, head) ? 1i32 : 0i32);
@*/
{
 return (*(const volatile typeof(head->next) *)&(head->next)) == head;
}
/**
 * INIT_LIST_HEAD - Initialize a list_head structure
 * @list: list_head structure to be initialized.
 *
 * Initializes the list_head to point to itself.  If it is a list header,
 * the result is an empty list.
 */
static inline void INIT_LIST_HEAD(struct list_head *list)
/*@
	requires
		take L_pre = RW<struct list_head>(list);
	ensures
		take L_post = RW<struct list_head>(list);
		ptr_eq(L_post.next, list);
		ptr_eq(L_post.prev, list);
@*/
{
 // HK(patch)
 // WRITE_ONCE(list->next, list);
 // WRITE_ONCE(list->prev, list);
 list->next = list;
 list->prev = list;
}
/**
 * list_entry - get the struct for this entry
 * @ptr:	the &struct list_head pointer.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 */
/**
 * list_prev_entry - get the prev element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
/**
 * list_next_entry - get the next element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
/**
 * list_first_entry - get the first element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
/**
 * list_last_entry - get the last element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
/**
 * list_entry_is_head - test if the entry points to the head of the list
 * @pos:	the type * to cursor
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
/**
 * list_is_first -- tests whether @list is the first entry in list @head
 * @list: the entry to test
 * @head: the head of the list
 */
static inline int list_is_first(const struct list_head *list, const struct list_head *head)
/*@
	requires
		take L_pre = RW<struct list_head>(list);
	ensures
		take L_post = RW<struct list_head>(list);
		L_pre == L_post;
		return == (ptr_eq(L_pre.prev, head) ? 1i32 : 0i32);
@*/
{
 return list->prev == head;
}
static inline int list_is_last(const struct list_head *list, const struct list_head *head)
/*@
	requires
		take L_pre = RW<struct list_head>(list);
	ensures
		take L_post = RW<struct list_head>(list);
		L_pre == L_post;
	return == (ptr_eq(L_pre.next, head) ? 1i32 : 0i32);
@*/
{
 return list->next == head;
}
/*
	* Insert a new entry between two known consecutive entries.
	*
	* This is only for internal list manipulation where we know
	* the prev/next entries already!
	*/
// HK: we have to handle the case for the first allocation where
// head == allocator->chunks and head->next == allocator->chunks
// That's why we need the pattern matching.
static inline void __list_add(struct list_head *new,
        struct list_head *prev,
        struct list_head *next)
/*@
	requires
		let head = prev;
		take New_pre = RW<struct list_head>(new);
		take Head_pre = RW<struct list_head>(head);
		!ptr_eq(new, next);
		let p = !ptr_eq(head, next);
		take Next_pre_opt = CondListHead(next, p);
	ensures
		take New_post = RW<struct list_head>(new);
		take Head_post = RW<struct list_head>(head);
		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));
		match Next_post_opt {
			List_Head_None {} => {
				list_add_aux(Head_post, New_post, Head_post, new, next, head)
			}
			List_Head_Some { L: Next_post } => {
				list_add_aux(Next_post, New_post, Head_post, new, next, head)
			}
		};
@*/
{
 /*@ split_case(!ptr_eq(head, next)); @*/
 next->prev = new;
 new->next = next;
 new->prev = prev;
 // HK: removed WRITE_ONCE
 // WRITE_ONCE(prev->next, new);
 prev->next = new;
}
/*@
function (boolean) list_add_aux(struct list_head Next_post, struct list_head New_post, struct list_head Head_post, pointer new, pointer next, pointer head)
{
	// HK: this is not complete
	// we have to handle the case for the first allocation where
	// head == allocator->chunks and head->next == allocator->chunks
	ptr_eq(Next_post.prev, new)
	&& ptr_eq(New_post.next, next)
	&& ptr_eq(New_post.prev, head)
	&& ptr_eq(Head_post.next, new)
}
@*/
// Spec is almost the copy of __list_add.
static inline void list_add(struct list_head *new, struct list_head *head)
/*@
	requires
		take New_pre = RW<struct list_head>(new);
		take Head_pre = RW<struct list_head>(head);
		let next = Head_pre.next;
		!ptr_eq(new, next);
		let p = !ptr_eq(head, next);
		take Next_pre_opt = CondListHead(next, p);
	ensures
		take New_post = RW<struct list_head>(new);
		take Head_post = RW<struct list_head>(head);
		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));
		match Next_post_opt {
			List_Head_None {} => {
				list_add_aux(Head_post, New_post, Head_post, new, next, head)
			}
			List_Head_Some { L: Next_post } => {
				list_add_aux(Next_post, New_post, Head_post, new, next, head)
			}
		};
@*/
{
 __list_add(new, head, head->next);
}
/*
 * Delete a list entry by making the prev/next entries
 * point to each other.
 *
 * This is only for internal list manipulation where we know
 * the prev/next entries already!
 */
static inline void __list_del(struct list_head * prev, struct list_head * next)
/*@
	requires
		take Next_pre = RW<struct list_head>(next);
		take Prev_pre = RW<struct list_head>(prev);
	ensures
		take Next_post = RW<struct list_head>(next);
		take Prev_post = RW<struct list_head>(prev);
		ptr_eq(Prev_post.next, next);
		ptr_eq(Next_post.prev, prev);
		ptr_eq(Prev_post.prev, Prev_pre.prev);
		ptr_eq(Next_post.next, Next_pre.next);
@*/
{
 next->prev = prev;
 // TODO: Recover WRITE_ONCE
 //WRITE_ONCE(prev->next, next);
 prev->next = next;
}
static inline void __list_del_entry(struct list_head *entry)
/*@
	requires
		take Entry_pre = RW<struct list_head>(entry);
		let next = Entry_pre.next;
		let prev = Entry_pre.prev;
		take Next_pre = RW<struct list_head>(next);
		take Prev_pre = RW<struct list_head>(prev);
	ensures
		take Entry_post = RW<struct list_head>(entry);
		take Next_post = RW<struct list_head>(next);
		take Prev_post = RW<struct list_head>(prev);
		ptr_eq(Prev_post.next, next);
		ptr_eq(Next_post.prev, prev);
		ptr_eq(Prev_post.prev, Prev_pre.prev);
		ptr_eq(Next_post.next, Next_pre.next);
@*/
{
 __list_del(entry->prev, entry->next);
}
// Spec is the copy of __list_del_entry.
static inline void list_del(struct list_head *entry)
/*@
	requires
		take Entry_pre = RW<struct list_head>(entry);
		let next = Entry_pre.next;
		let prev = Entry_pre.prev;
		take Next_pre = RW<struct list_head>(next);
		take Prev_pre = RW<struct list_head>(prev);
	ensures
		take Entry_post = RW<struct list_head>(entry);
		take Next_post = RW<struct list_head>(next);
		take Prev_post = RW<struct list_head>(prev);
		ptr_eq(Prev_post.next, next);
		ptr_eq(Next_post.prev, prev);
		ptr_eq(Prev_post.prev, Prev_pre.prev);
		ptr_eq(Next_post.next, Next_pre.next);
@*/
{
 __list_del_entry(entry);
}
/**
 * list_for_each_entry	-	iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
/**
 * list_for_each_entry_safe_reverse - iterate backwards over list safe against removal
 * @pos:	the type * to use as a loop cursor.
 * @n:		another type * to use as temporary storage
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 *
 * Iterate backwards over list of given type, safe against removal
 * of list entry.
 */

// TODO: spinlock
typedef u64 hyp_spinlock_t;
void hyp_spin_lock(hyp_spinlock_t *lock);
void hyp_spin_unlock(hyp_spinlock_t *lock);
// TODO: we probably don't care about this for CN
// TODO: per-cpu stuff (for now fixing to only one CPU)
// TODO: this is hardcoding 4K pages
// HK: we cannot define c_PAGE_ALIGN_DOWN until here because PAGE_SIZE is defined just above.
// /*@ function (u64) PAGE_ALIGN_DOWN(u64 addr) @*/
static unsigned long c_PAGE_ALIGN_DOWN(unsigned long long addr)
// /*@ cn_function PAGE_ALIGN_DOWN; @*/
{
 return ((((addr) - (((1UL << 12)) - 1)) + ((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1));
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
 mc->head = (to_pa(p) & (~((1UL << 12)-1))) |
     (((typeof(~(~((1UL << 12)-1))))(order) << (__builtin_ffsll(~(~((1UL << 12)-1))) - 1)) & (~(~((1UL << 12)-1))));
 mc->nr_pages++;
}
static inline void *pop_hyp_memcache(struct kvm_hyp_memcache *mc,
         void *(*to_va)(phys_addr_t phys),
         unsigned long *order)
{
 phys_addr_t *p = to_va(mc->head & (~((1UL << 12)-1)));
 if (!mc->nr_pages) {
  return __cerbvar_NULL;
 }
 *order = ((typeof(~(~((1UL << 12)-1))))(((mc->head) & (~(~((1UL << 12)-1)))) >> (__builtin_ffsll(~(~((1UL << 12)-1))) - 1)));
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
   return -12 /* Out of memory */;
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
/* SPDX-License-Identifier: GPL-2.0-only */
/**
 * hyp_alloc() - Allocate memory from the heap allocator
 *
 * @size:	Allocation size in bytes.
 *
 * Return: A pointer to the allocated memory on success, else NULL.
 */
void *hyp_alloc(size_t size);
/**
 * hyp_alloc_account() - Allocate memory from the heap allocator and account
 *
 * Similar to hyp_alloc(). But on success, the allocated memory will be
 * accounted against the vm (@host_kvm) protected_hyp_mem counter. This allows
 * the host to know about detailed footprint of that vm.
 *
 * @size:	Allocation size in bytes.
 * @host_kvm:	Pointer (in the hyp VA space) to the host KVM struct.
 *
 * Return: A pointer to the allocated memory on success, else NULL.
 */
/**
 * hyp_alloc_errno() - Read the errno on allocation error
 *
 * Get the return code from an allocation failure.
 *
 * Return: -ENOMEM if the allocator needs a refill from the host, -E2BIG if
 * there is no VA space left else 0.
 */
int hyp_alloc_errno(void);
/**
 * hyp_free() - Free memory allocated with hyp_alloc()
 *
 * @addr:	Address returned by the original hyp_alloc().
 *
 * The use of any other address than one returned by hyp_alloc() will cause a
 * hypervisor panic.
 */
void hyp_free(void *addr);
/**
 * hyp_free_account() - Free memory allocated with hyp_alloc_account()
 *
 * Similar to hyp_free, but for memory allocated with hyp_alloc_account().
 *
 * @addr:	Address returned by the original hyp_alloc_account().
 * @host_kvm:	pointer (in the hyp VA space) to the host KVM struct.
 *
 * The use of any other address than one returned by hyp_alloc() will cause a
 * hypervisor panic.
 */
int hyp_alloc_init(size_t size);
int hyp_alloc_refill(struct kvm_hyp_memcache *host_mc);
int hyp_alloc_reclaimable(void);
void hyp_alloc_reclaim(struct kvm_hyp_memcache *host_mc, int target);
u8 hyp_alloc_missing_donations(void);
extern unsigned long hyp_nr_cpus;
static unsigned long c_MIN_ALLOC()
{
        return 8UL;
}
/*@
function (u64) MIN_ALLOC () {
        8u64
}
@*/
static int hyp_allocator_errno;
static struct kvm_hyp_memcache hyp_allocator_mc;
static u8 hyp_allocator_missing_donations;
static struct hyp_allocator {
        struct list_head chunks;
        unsigned long start;
        u32 size;
        hyp_spinlock_t lock;
} hyp_allocator;
struct chunk_hdr {
        u32 alloc_size;
        u32 mapped_size;
        struct list_head node;
        u32 hash;
        char data ;
};
// HK: having char data at the end of the struct is very annoying
// If we write RW<struct chunk_hdr>, a single byte of the data is going to be owned
// unintentionally.
// TODO: rewrite the spec to use chunk_hdr_only instead of chunk_hdr
struct chunk_hdr_only {
        u32 alloc_size;
        u32 mapped_size;
        struct list_head node;
        u32 hash;
};
// Auxiliary functions for chunk_hdr
/*@
function (boolean) hash_change_only (struct chunk_hdr pre, struct chunk_hdr post)
{
    pre.alloc_size == post.alloc_size &&
    pre.mapped_size == post.mapped_size &&
    pre.node == post.node
}
@*/
static u32 chunk_hash_compute(struct chunk_hdr *chunk)
/*@
    trusted;
    requires
        take C_pre = RW<struct chunk_hdr>(chunk);
        // take C_pre = each(u64 i; 0u64 <= i && sizeof<unsigned long long> * i < (u64)offsetof(chunk_hdr, hash)) {
        //         RW<unsigned long long>(array_shift<unsigned long long>(chunk, i))
        // };
    ensures
        take C_post = RW<struct chunk_hdr>(chunk);
        //take C_post = each(u64 i; 0u64 <= i && sizeof<unsigned long long> *i < (u64)offsetof(chunk_hdr, hash)) {
        //        RW<unsigned long long>(array_shift<unsigned long long>(chunk, i))
        //};
        C_pre == C_post;
@*/
{
        size_t len = offsetof(struct chunk_hdr, hash);
        // HK: How do I handle this cast while having the ownership to chunk??
        u64 *data = (u64 *)chunk;
        u32 hash = 0;
                                                                                ;
    while (len >= sizeof(u64))
    /*@
        inv
        let L = (u64)offsetof(chunk_hdr, hash);
        take C = RW<struct chunk_hdr>(chunk);
        len <= L;
        (u64)data + len == (u64)chunk + L;
        {chunk} unchanged;
    @*/
    {
        // HK: I don't know how to say we have the ownership of data
        // because we see the struct into just a sequence of bytes.
        hash ^= hash_64(*data, 32);
        len -= sizeof(u64);
        data++;
    }
        if (len) {
                hash ^= hash_32(*(u32 *)data, 32);
        }
        return hash;
}
static inline void chunk_hash_update(struct chunk_hdr *chunk)
/*@
    requires
        take C_pre = RW<struct chunk_hdr>(chunk);
    ensures
        take C_post = RW<struct chunk_hdr>(chunk);
        hash_change_only(C_pre, C_post);
@*/
{
        if (chunk) {
                chunk->hash = chunk_hash_compute(chunk);
        }
}
static inline void chunk_hash_validate(struct chunk_hdr *chunk)
/*@
    requires
        take C_pre = MaybeChunkHdr(chunk, !is_null(chunk));
    ensures
        take C_post = MaybeChunkHdr(chunk, !is_null(chunk));
        C_post == C_pre;
@*/
{
        if (chunk) {
                (!!(chunk->hash != chunk_hash_compute(chunk)));
        }
}
// HK: eliminate the cast to unsigned long
// #define chunk_hdr_size() //         offsetof(struct chunk_hdr, data)
// HK: replace unsigned long with size_t
//#define chunk_size(size)         //(chunk_hdr_size() + max_u64((size_t)(size), MIN_ALLOC))
/*@
function (u64) Cn_chunk_hdr_size ()
{
        (u64) offsetof(chunk_hdr, data)
}
// HK: size_t cast is removed. Macro requires cast because it does not know what the
// argument type is.
function (u64) Cn_chunk_size (u64 size)
{
        Cn_chunk_hdr_size() + (size > MIN_ALLOC() ? size : MIN_ALLOC())
        //(u64) member_shift<struct chunk_hdr>(NULL, data) + (size > MIN_ALLOC() ? size : MIN_ALLOC())
}
function (pointer) Cn_chunk_data (struct chunk_hdr chunk)
{
    (pointer)chunk.data
}

@*/
/**
chunk:
| hdr | alloc'd | mapped-but-not-alloc'd | ..maybe unmapped VA part before the start of the next chunk (or the start+size) |

      ^^^^^^^^^^ alloc_size
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  mapped_size
**/
/* TP: perhaps there's an invariant that the last chunk is the only one that can be _partially_ used */
/*PS: `chunk_is_used` suggests that chunks can be unused, iff size=0.  But probably only transiently?  No, probably not - see the chunk_try_destroy comment.*/
/*PS: what are the hashes used for?  AIUI, to fail fast if the chunk header got stomped on by bad user code.  They cover the next/prev pointers so have to be updated whenever the list structure changes.  So not stable, so presumably not exposed to clients. Could be removed if the clients were persistently verified to be memory safe */
/*PS: in addition to our first sketch, the spec should constrain what is actually mapped - by making the underlying __hyp_allocator_map and pkvm_remove_mappings in shim.c have specs that record that as finite maps (and fail if something tries to map illegally).  And we need to spec the memcache operations. */
/*@
type_synonym va = u64

type_synonym cn_chunk_hdr = {
  va header_address, // the VA of the start of the chunk_hdr
  u32 alloc_size, // exactly as in the C
  u32 mapped_size,  // exactly as in the C
  u32 va_size      // implicit in the C: the total va space size of this chunk (TODO: update the other defns to match)
  // no node, no hash, no data, no ownership here
}

type_synonym cn_hyp_allocator = {
        pointer head,    // used for checking the last chunk
        pointer first,   // used for list walking
        pointer last,    // last chunk
        va start,
        u32 size
}

datatype cn_chunk_hdrs {
  Chunk_nil {},
  Chunk_cons { cn_chunk_hdr hd, datatype cn_chunk_hdrs tl }
}

datatype cn_chunk_hdr_option {
  Chunk_none {},
  Chunk_some { cn_chunk_hdr hdr }
}

@*/
/*PS: if we're abstracting the chunks to a CN custom list as above, then we'll abstract a `struct chunk_hdr *chunk` to a natural-number index into that list and define an `nth`?  Or add the actual address to the abstraction and search for that to access?  Think we need that address in any case, though that doesn't decide this. */
/*@
function (pointer) my_container_of_chunk_hdr (pointer p)
{
     (pointer)((u64)p - (u64)offsetof(chunk_hdr, node))
}
function (boolean) is_last_chunk(pointer node_address, struct hyp_allocator ha)
{
        ptr_eq(node_address, ha.chunks.prev)
}
predicate (cn_hyp_allocator) Cn_hyp_allocator_only(pointer p)
{
        take ha = RW<struct hyp_allocator>(p);
        let cn_hyp = {
                head:  member_shift<struct hyp_allocator>(p, chunks),
                first: ha.chunks.next,
                last:  ha.chunks.prev,
                start: ha.start,
                size:  ha.size
        };
        assert(ha.start < (u64)cn_hyp.start + (u64)cn_hyp.size);
        return cn_hyp;
}
@*/
/*@
// Own_chunk just owns the chunk header and the mapped part of the chunk
predicate (struct chunk_hdr_only) Own_chunk_hdr(pointer header_address)
{
        take cn_hdr = RW<struct chunk_hdr_only>(header_address);
        assert(cn_hdr.alloc_size <= cn_hdr.mapped_size);
        return cn_hdr;
}
// Cn_chunk_hdr validates the locations of the chunk header and its next are
// in the hyp_allocator's address space
predicate ({cn_chunk_hdr Hdr, struct list_head Node}) Cn_chunk_hdr(pointer header_address, cn_hyp_allocator ha)
{
        take hdr = Own_chunk_hdr(header_address);

        let end = ha.start + (u64)ha.size;
        let va_size = (Cn_list_is_last(hdr.node, ha.head) ? end : (u64)my_container_of_chunk_hdr(hdr.node.next) ) - (u64)header_address;
        assert(va_size <= (u64)MAXu32());
        assert((u64)hdr.node.next <= end);

        let cn_hdr = {
                header_address : (u64) header_address,
                alloc_size : hdr.alloc_size,
                mapped_size : hdr.mapped_size,
                va_size: (u32)va_size
        };
        assert(cn_hdr.mapped_size <= cn_hdr.va_size);

        // own chunk data
        let chunk_data = array_shift<unsigned char>(header_address, Cn_chunk_hdr_size());

        let start = cn_hdr.alloc_size == 0u32 ? chunk_data :
                array_shift<unsigned char>(chunk_data, cn_hdr.alloc_size);
        let size_owned_by_ha = cn_hdr.alloc_size == 0u32 ? ((u64) cn_hdr.va_size - Cn_chunk_hdr_size()) :
                ((u64)cn_hdr.va_size -  Cn_chunk_hdr_size() - (u64)cn_hdr.alloc_size);
        take A = Cn_char_array(start, size_owned_by_ha);

        // check non-overlappingness
        assert(cn_hdr.header_address >= ha.start);
        let chunk_end = cn_hdr.header_address + (u64) cn_hdr.mapped_size;
        assert(chunk_end <= end);
        // HK: needed to ensure no-integer overflow?
        assert(chunk_end >= cn_hdr.header_address);


        // HK: the chunk lists must be sorted in address order.
        // (otherwise, the chunk_unmapped_size function may return incorrect sizes)
        // unless this is not the last chunk
        assert(
                (u64)member_shift<struct chunk_hdr>(header_address, node) < (u64)hdr.node.next
                || (u64)hdr.node.next == (u64)ha.head
        );
        return {Hdr: cn_hdr, Node: hdr.node};

}
predicate ({cn_chunk_hdr hd, datatype cn_chunk_hdrs tl}) Cn_chunk_hdrs_non_last(pointer p, pointer prev, cn_hyp_allocator ha,  pointer last)
{
        let header_address = array_shift<char>(p, -(offsetof(chunk_hdr, node))); // or some offsetof arithmetic
        take cn_hdr = Cn_chunk_hdr(header_address, ha);
        assert(ptr_eq(cn_hdr.Node.prev, prev));
        take tl = Cn_chunk_hdrs(cn_hdr.Node.next, p, ha, last);
        // do we want to use resources to track the va-address-space "ownership" of any unmapped part of va address space between this chunk and the next (or the end)? unclear. pretend not for now
        return {hd: cn_hdr.Hdr, tl: tl};
}
// HK: prev is unused? what is for?
// -> HK: important for sanity check of linked list (e.g. node->next->prev == node)
predicate (datatype cn_chunk_hdrs) Cn_chunk_hdrs(pointer p, pointer prev, cn_hyp_allocator ha,  pointer last)
{
        if (ptr_eq(p,last)) {
                assert(ha.start <= ha.start + (u64)ha.size);
                return Chunk_nil {};
        } else {
                take T = Cn_chunk_hdrs_non_last(p, prev, ha, last);
                return Chunk_cons { hd: T.hd, tl: T.tl };
        }
}

predicate (datatype cn_chunk_hdrs) Cn_chunk_hdrs_rev(pointer p, pointer prev, cn_hyp_allocator ha,  pointer last, datatype cn_chunk_hdrs accum)
{
        if (ptr_eq(p,last)) {
                return accum;
        } else {
                let header_address = array_shift<char>(p, -(offsetof(chunk_hdr, node)));
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                assert(ptr_eq(cn_hdr.Node.prev, prev));
                let c = Chunk_cons { hd: cn_hdr.Hdr, tl: accum };
                take res = Cn_chunk_hdrs_rev(cn_hdr.Node.next, p, ha, last, c);
                return res;
        }
}

function (pointer) HeadOrValue(datatype cn_chunk_hdrs hdrs, pointer value)
{
        match (hdrs) {
        Chunk_nil {} => {
                value
        }
        Chunk_cons {hd:hdr, tl:tl} => {
                (pointer)hdr.header_address
        }
        }
}

type_synonym cn_lseg = {
        cn_chunk_hdrs before,
        cn_chunk_hdr chunk,
        cn_chunk_hdrs after
}

predicate ({cn_hyp_allocator ha, cn_lseg lseg}) Cn_hyp_allocator_focusing_on( pointer p, pointer chunk) { // p points to a struct hyp_allocator
  take ha = Cn_hyp_allocator_only(p);
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow

  take hdrs1 = Cn_chunk_hdrs_rev(ha.first, ha.head, ha, chunk, Chunk_nil {});
  let prev = HeadOrValue(hdrs1, ha.head);
  take T = Cn_chunk_hdrs_non_last(chunk, prev, ha, ha.head);
  let lseg = {before: hdrs1, chunk: T.hd, after: T.tl};
  return( {ha:ha, lseg: lseg} );
  // morally on initialisation this owns all the va space that isn't in the chunks - but we're not currently representing "va ownership" with ownership.  So there is no extra ownership on initialisation - that's all in the memcache
}


// **This function is specialized for chunk lists obtained by Cn_hyp_allocator_focusing_on**
// That is, it assumes
// - before: in the reverse order
// - after: in the forward order
function [rec] (datatype cn_chunk_hdrs) ConcatChunkList(datatype cn_chunk_hdrs before, cn_chunk_hdrs after)
{
        match (before) {
        Chunk_nil {} => {
                after
        }
        Chunk_cons {hd:hdr, tl:tl} => {
                ConcatChunkList(tl, Chunk_cons {hd:hdr, tl: after})
        }
        }
}

lemma LSegsToList(cn_hyp_allocator ha, datatype cn_chunk_hdrs before, cn_chunk_hdr chunk, datatype cn_chunk_hdrs after, pointer p, pointer chunkp)
requires
        take C = Cn_hyp_allocator_focusing_on(p, chunkp);
        let lseg = {before: before, chunk: chunk, after: after};
        C == {ha:ha, lseg: lseg};
ensures
        take C2 = Cn_hyp_allocator(p);
        let lseg2 = {before: before, chunk: chunk, after: after};
        C2 == {ha: ha, hdrs: ConcatChunkList(before, Chunk_cons {hd: chunk, tl: after})};

predicate ({cn_hyp_allocator ha, datatype cn_chunk_hdrs hdrs}) Cn_hyp_allocator( pointer p ) { // p points to a struct hyp_allocator
  take ha = Cn_hyp_allocator_only(p);
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow
  take hdrs = Cn_chunk_hdrs(ha.first, ha.head, ha, ha.head);
  return( {ha:ha, hdrs:hdrs} );
  // morally on initialisation this owns all the va space that isn't in the chunks - but we're not currently representing "va ownership" with ownership.  So there is no extra ownership on initialisation - that's all in the memcache
}

function (boolean) Is_chunk_some(datatype cn_chunk_hdr_option maybe_hdr)
{
        match (maybe_hdr) {
        Chunk_none {} => {
                false
        }
        Chunk_some {hdr:hdr} => {
                true
        }
        }
}


function [rec] (datatype cn_chunk_hdr_option) lookup(pointer p, datatype cn_chunk_hdrs hdrs)
{
        match (hdrs) {
        Chunk_nil {} => {
                Chunk_none {}
        }
        Chunk_cons {hd:hdr, tl:tl} => {
                if (hdr.header_address == (u64) p){
                        Chunk_some { hdr:hdr }
                } else {
                        lookup(p,tl)
                }
        }
        }
}

function [rec] (datatype cn_chunk_hdr_option) next_chunk(pointer p, datatype cn_chunk_hdrs hdrs)
{
        match (hdrs) {
        Chunk_nil {} => {
                Chunk_none {}
        }
        Chunk_cons {hd:hdr, tl:tl} => {
                if (hdr.header_address == (u64) p){
                        match (tl) {
                        Chunk_nil {} => {
                                Chunk_none {}
                        }
                        Chunk_cons {hd:hdr2, tl:tl2} => {
                                Chunk_some { hdr:hdr2 }
                        }
                        }
                } else {
                        lookup(p,tl)
                }
        }
        }
}

function (boolean) is_free_chunk(cn_chunk_hdr hdr, u32 size)
{
           hdr.alloc_size == 0u32 // i.e., unused
        && (u64) hdr.va_size // the code's available_size
        >= Cn_chunk_size((u64) size) // TODO: where chunk_size is a CN copy of their macro
        // we ignore the hash check of the chunk_get macro - even though to
        // prove safety of the actual code we would need to check the hash
        // checks succeed.
}

// function (bool) is_free_chunk(pointer p,u32 size, datatype cn_chunk_hdrs hdrs)
// {
//      // it returns a chunk in the list (or NIL?) st the alloc_size is zero
//      // and total size (not just mapped size, and including header size) is
//      // at least what you asked for.

//      _is_free_chunk(lookup(p, hdrs),size)
// }

@*/
static inline struct chunk_hdr* __chunk_next(struct chunk_hdr *chunk,
                           struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = B_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);
                A_post == A_pre;
                B_post == B_pre;
                C_post == C_pre;
@*/
{
        return list_is_last(&(chunk)->node, &(allocator)->chunks) ?
                __cerbvar_NULL : ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0UL - offsetof(typeof(*(chunk)), node))));
}
static inline struct chunk_hdr* __chunk_prev(struct chunk_hdr *chunk,
                           struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = B_pre.Node;
                let prev_node = Node.prev;
                let prev_chunk = my_container_of_chunk_hdr(prev_node);
                take C_pre = Cn_chunk_hdr(prev_chunk, A_pre);
                ptr_eq(C_pre.Node.next, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(prev_chunk, A_post);
                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);
                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, prev_chunk);
                A_post == A_pre;
                B_post == B_pre;
                C_post == C_pre;
@*/
{
        return list_is_first(&(chunk)->node, &(allocator)->chunks) ?
                __cerbvar_NULL : ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.prev) + (0UL - offsetof(typeof(*(chunk)), node))));
}
static inline struct chunk_hdr* chunk_get_next(struct chunk_hdr *chunk,
                                               struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = B_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);
                A_post == A_pre;
                B_post == B_pre;
                C_post == C_pre;
@*/
{
        struct chunk_hdr *next = __chunk_next(chunk, allocator);
        chunk_hash_validate(next);
        return next;
}
static inline struct chunk_hdr* chunk_get_prev(struct chunk_hdr *chunk,
                                               struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = B_pre.Node;
                let prev_node = Node.prev;
                let prev_chunk = my_container_of_chunk_hdr(prev_node);
                take C_pre = Cn_chunk_hdr(prev_chunk, A_pre);
                ptr_eq(C_pre.Node.next, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(prev_chunk, A_post);
                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);
                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, prev_chunk);
                A_post == A_pre;
                B_post == B_pre;
                C_post == C_pre;
@*/
{
        struct chunk_hdr *prev = __chunk_prev(chunk, allocator);
        chunk_hash_validate(prev);
        return prev;
}
static inline struct chunk_hdr* chunk_get(void *addr)
/*@
        requires
                take C_pre = RW<struct chunk_hdr>(addr);
        ensures
                take C_post = RW<struct chunk_hdr>(addr);
                C_pre == C_post;
                ptr_eq(return, addr);
@*/
{
        struct chunk_hdr *chunk = (struct chunk_hdr *)addr;
        chunk_hash_validate(chunk);
        return chunk;
}
/*@
function (u64) Cn_chunk_unmapped_region(pointer chunk_p, struct chunk_hdr chunk)
{
    (u64)chunk_p + (u64)chunk.mapped_size
}
@*/
// TODO(HK): C_pre should replaced with cn_chunk_hdr_option to handle the
// last chunk case
static inline unsigned long chunk_unmapped_size(struct chunk_hdr *chunk,
                                                struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Hdr = B_pre.Hdr;
                let Node = B_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                A_pre == A_post;
                B_pre == B_post;
                C_pre == C_post;
                return == (u64)Cn_chunk_unmapped_size(Hdr);
@*/
{
        struct chunk_hdr *next = chunk_get_next(chunk, allocator);
        unsigned long allocator_end = (allocator)->start +
                                      (allocator)->size;
        return next ? (unsigned long)next - ((unsigned long)(chunk) + chunk->mapped_size) :
                allocator_end - ((unsigned long)(chunk) + chunk->mapped_size);
}
/*@
function (boolean) Cn_list_is_first(struct list_head node, pointer chunks)
{
        ptr_eq(node.prev, chunks)
}
function (boolean) Cn_list_is_last(struct list_head node, pointer chunks)
{
        ptr_eq(node.next, chunks)
}
function (pointer) Cn_chunk_get_next(struct chunk_hdr chunk, pointer allocator)
{
        Cn_list_is_last(chunk.node, member_shift<struct hyp_allocator>(allocator, chunks)) ?
        NULL : my_container_of_chunk_hdr(chunk.node.next)
}
function (u32) Cn_chunk_unmapped_size(cn_chunk_hdr hdr)
{
        hdr.va_size - hdr.mapped_size
}
@*/
/*@
// check if the new chunk is at the right place in the allocator memory
function (boolean) chunk_list_insert_aux(cn_hyp_allocator ha, pointer chunk, struct chunk_hdr_only C, pointer prev, u64 next)
{
        let va_size = next - (u64)chunk;

        ha.start <= (u64)chunk && (u64)chunk < ha.start + (u64)ha.size
        && (u64)prev < (u64)chunk && (u64)chunk < next
        && (u64)C.mapped_size <= va_size
}
@*/
// This function takes
//   - a chunk *not in the chunk list*
//   - a chunk *in the chunk list*, which will be the previous chunk of the new chunk
//   - the allocator
// and inserts the new chunk into the chunk list after the previous chunk.
// HK: This is the point where raw pointer manipulations and beautiful list
// specifications meet, which is one of the most difficult parts of the whole
// spec writing.
// Currently, I "believe" that the spec I wrote is correct, but it is not
// automatically verified by CN.
static inline void chunk_list_insert(struct chunk_hdr *chunk,
                                     struct chunk_hdr *prev,
                                     struct hyp_allocator *allocator)
/*

1. chunk list in allocator
-> xx -> ... -> prev -> next -> ...
2. chunk is not in the list
==>
-> xx -> ... -> prev -> chunk -> next -> ...

*/
/*@
    trusted;
    requires
        take H_pre = Cn_hyp_allocator(allocator);

        // chunk is currently not in the chunk list
        !Is_chunk_some(lookup(chunk, H_pre.hdrs));
        take C = Own_chunk_hdr(chunk);

        // prev must be in the chunk list
        match (lookup(prev, H_pre.hdrs))
        {
        Chunk_none {} => { false }
        Chunk_some { hdr:Prev } => {
                // check if chunk is at the right place in the allocator memory
                match (next_chunk(prev, H_pre.hdrs)) {
                Chunk_none {} => {
                        // prev is the last chunk
                        chunk_list_insert_aux(H_pre.ha, chunk, C, prev, H_pre.ha.start + (u64)H_pre.ha.size)
                }
                Chunk_some { hdr:Next_Chunk } => {
                        chunk_list_insert_aux(H_pre.ha, chunk, C, prev, (u64)Next_Chunk.header_address)
                }
                }
        }
        };
    ensures
        take A_post = Cn_hyp_allocator(allocator);
@*/
{
        // HK: non-rust ownership type part
        // This is also why we cannot directly apply the idea of
        // [Hermes&Krebbers ITP 2024] to this program.
        // In p9, the specification for inserting a node into a list is
        // defined as:
        // { DCycle c L ∗ l ↦ [ _, _ ] } insert c l { DCycle c (l :: L) }
        // but we cannot give up the ownership of l just after the insertion.
        // HK: Proof for the ownership of RW<struct list_head*>(&(&prev->node)->next)
        //  - If prev->node is the last node, then prev->node.next == allocator->chunks,
        //    which is in H_pre.ha
        //  - If prev->node is not the last node, then prev->node.next is in Next_Chunk.
        // HK: Proof for the ownership of prev
        //   - prev must be in the chunk list from the precondition
        //   - that implies we have the ownership of prev
        list_add(&chunk->node, &prev->node);
        // /*@ unfold lookup(prev, H_pre.hdrs); @*/
        chunk_hash_update(prev);
        chunk_hash_update(__chunk_next(chunk, allocator));
        chunk_hash_update(chunk);
}
static inline void chunk_list_del(struct chunk_hdr *chunk,
                                  struct hyp_allocator *allocator)
{
        struct chunk_hdr *prev = __chunk_prev(chunk, allocator);
        struct chunk_hdr *next = __chunk_next(chunk, allocator);
        // non-rust ownership type part
        list_del(&chunk->node);
        chunk_hash_update(prev);
        chunk_hash_update(next);
}
static void hyp_allocator_unmap(struct hyp_allocator *allocator,
                                unsigned long va, size_t size)
{
        struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
        int nr_pages = size >> 12;
        unsigned long __va = va;
        (!!(!((((unsigned long)(va)) & ((typeof((unsigned long)(va)))((1UL << 12)) - 1)) == 0)));
        (!!(!((((unsigned long)(size)) & ((typeof((unsigned long)(size)))((1UL << 12)) - 1)) == 0)));
        while (nr_pages--) {
                phys_addr_t pa = __pkvm_private_range_pa((void *)__va);
                void *page = hyp_phys_to_virt(pa);
                push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                __va += (1UL << 12);
        }
        pkvm_remove_mappings((void *)va, (void *)(va + size));
}
static int hyp_allocator_map(struct hyp_allocator *allocator,
                             unsigned long va, size_t size)
// HK: Hyp_allocator_map mines a new memory from memcache and maps it.
// This means that it returns an ownership of this mined memory out of thin air.
/*@
        trusted;
        requires
                true;
        ensures
                true;
@*/
{
        struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
        unsigned long va_end = va + size;
        int ret, nr_pages = 0;
        if (!((((unsigned long)(va)) & ((typeof((unsigned long)(va)))((1UL << 12)) - 1)) == 0) || !((((unsigned long)(size)) & ((typeof((unsigned long)(size)))((1UL << 12)) - 1)) == 0)) {
                return -22 /* Invalid argument */;
        }
        if (va_end < va || va_end > (allocator->start + allocator->size)) {
                return -7 /* Argument list too long */;
        }
        if (mc->nr_pages < (size >> 12)) {
                u8 *missing_donations = (&hyp_allocator_missing_donations);
                u32 delta = (size >> 12) - mc->nr_pages;
                *missing_donations = min_u32(delta, ((u8)~0U));
                return -12 /* Out of memory */;
        }
        while (nr_pages < (size >> 12)) {
                void *page;
                unsigned long order;
                page = pop_hyp_memcache(mc, hyp_phys_to_virt, &order);
                /* We only expect 1 page at a time for now. */
                (!!(!page || order));
                ret = __hyp_allocator_map(va, hyp_virt_to_phys(page));
                if (ret) {
                        push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                        break;
                }
                va += (1UL << 12);
                nr_pages++;
        }
        if (ret && nr_pages) {
                va -= (1UL << 12) * nr_pages;
                hyp_allocator_unmap(allocator, va, nr_pages << 12);
        }
        return ret;
}
/*@
// no first chunk && no EINVAL in check_install
function (boolean) chunk_install_sanity_check(pointer prev_p, pointer chunk_p, struct chunk_hdr prev)
{
    !is_null(prev_p)
           && !(Cn_chunk_unmapped_region(prev_p, prev) < (u64)chunk_p)
           && !((u64)Cn_chunk_data(prev) + (u64)prev.alloc_size > (u64)chunk_p)
}

datatype chunk_hdr_option {
  ChunkHdr_none {},
  ChunkHdr_some { struct chunk_hdr hdr }
}

predicate (datatype chunk_hdr_option) MaybeChunkHdr(pointer chunk, boolean condition)
{
        if (condition)
        {
                take v = RW<struct chunk_hdr>(chunk);
                return ChunkHdr_some { hdr: v };
        }
        else
        {
                return ChunkHdr_none {};
        }
}
@*/
/*@
predicate (cn_hyp_allocator) ChunkInstallPre(pointer chunk, u64 size, pointer prev, pointer allocator)
{
        if (is_null(prev))
        {
        take a_in=Cn_hyp_allocator(allocator);
        assert(a_in.hdrs==Chunk_nil{});
        return a_in.ha;
        }
        else
        {
        take HA_pre = Cn_hyp_allocator_focusing_on(allocator, prev);
        take Chunk = Own_chunk_hdr(chunk);
        let allocator_end = (u64)HA_pre.ha.start + (u64)HA_pre.ha.size;
        // chunk is located in the allocator's memory
        assert(HA_pre.ha.start <= (u64)chunk && (u64)chunk < allocator_end);
        return HA_pre.ha;
        }
}
predicate (boolean) ChunkInstallPost(pointer chunk, u64 size, pointer prev, pointer allocator, cn_hyp_allocator ha_pre)
{
        if (is_null(prev))
        {
        take HA_post =Cn_hyp_allocator_focusing_on(allocator, chunk);
        let allocator_end = (u64)ha_pre.start + (u64)ha_pre.size;
        let first_chunk = {
                header_address: (u64)chunk,
                mapped_size: (u32)PAGE_ALIGN(Cn_chunk_size(size)),
                alloc_size: (u32) size,
                va_size: (u32) (allocator_end - (u64)chunk)
        };
        assert(HA_post.lseg.after == Chunk_nil {});
        assert(HA_post.lseg.chunk == first_chunk);
        assert(HA_post.lseg.before == Chunk_nil {} );
        return true;
        }
        else
        {
                //todo
                return true;
        }
}
@*/
// chunk: the new chunk to install
// size: alloc size for chunk
// prev: the previous chunk for `chunk`
//   - this is never be allocator->chunks
// invariant:
//   - there is no chunk between prev and chunk
//   - chunk is not owned by the allocator
static int chunk_install(struct chunk_hdr *chunk, size_t size,
                         struct chunk_hdr *prev,
                         struct hyp_allocator *allocator)
/*@
    requires
        take Pre = ChunkInstallPre(chunk, size, prev, allocator);
    ensures
        take Post = ChunkInstallPost(chunk, size, prev, allocator, Pre);
@*/
{
        size_t prev_mapped_size;
        /* First chunk, first allocation */
        if (!prev) {
                INIT_LIST_HEAD(&chunk->node);
                // HK: non-rust ownership type part
                // See the comments in chunk_list_insert
                list_add(&chunk->node, &allocator->chunks);
                chunk->mapped_size = (((((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))) + ((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1));
                chunk->alloc_size = size;
                chunk_hash_update(chunk);
                return 0;
        }
        if (((unsigned long)(prev) + prev->mapped_size) < (unsigned long)chunk) {
                return -22 /* Invalid argument */;
        }
        if ((unsigned long)((void *)(&(prev)->data)) + prev->alloc_size > (unsigned long)chunk) {
                return -22 /* Invalid argument */;
        }
        prev_mapped_size = prev->mapped_size;
        prev->mapped_size = (unsigned long)chunk - (unsigned long)prev;
        chunk->mapped_size = prev_mapped_size - prev->mapped_size;
        chunk->alloc_size = size;
        chunk_list_insert(chunk, prev, allocator);
        return 0;
}
static int chunk_merge(struct chunk_hdr *chunk, struct hyp_allocator *allocator)
{
        /* The caller already validates prev */
        struct chunk_hdr *prev = __chunk_prev(chunk, allocator);
        if ((!!(!prev))) {
                return -22 /* Invalid argument */;
        }
        /* Can only merge free chunks */
        if ((!!(chunk)->alloc_size) || (!!(prev)->alloc_size)) {
                return -16 /* Device or resource busy */;
        }
        /* Can't merge non-contiguous mapped regions */
        if (((unsigned long)(prev) + prev->mapped_size) != (unsigned long)chunk) {
                return 0;
        }
        /* mapped region inheritance */
        prev->mapped_size += chunk->mapped_size;
        chunk_list_del(chunk, allocator);
        return 0;
}
static size_t chunk_needs_mapping(struct chunk_hdr *chunk, size_t size)
/*@
        requires
                take C_pre = RW<struct chunk_hdr>(chunk);
                let mapping_needs = Cn_chunk_size(size);
                let mapping_missing = PAGE_ALIGN(mapping_needs - (u64)C_pre.mapped_size);
        ensures
                take C_post = RW<struct chunk_hdr>(chunk);
                C_pre == C_post;
                let res = (mapping_needs <= (u64)C_pre.mapped_size) ?
                           0u64 : mapping_missing;
                return == res;
@*/
{
        // TODO: fix this. Due to the Cerberus elaboration bug, we cannot use
        // size_t here currently.
        // size_t mapping_missing, mapping_needs = chunk_size(size);
        unsigned long mapping_missing, mapping_needs = (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL));
        if (mapping_needs <= chunk->mapped_size) {
                return 0;
        }
        mapping_missing = ((((mapping_needs - chunk->mapped_size)) + ((typeof((mapping_needs - chunk->mapped_size)))(((1UL << 12))) - 1)) & ~((typeof((mapping_needs - chunk->mapped_size)))(((1UL << 12))) - 1));
        return mapping_missing;
}
/*
 * When a chunk spans over several pages, split it at the start of the latest
 * page. This allows to punch holes in the mapping to reclaim pages.
 *
 *  +--------------+
 *  |______________|
 *  |______________|<- Next chunk
 *  |_ _ _ __ _ _ _|
 *  |              |<- New chunk installed, page aligned
 *  +--------------+
 *  +--------------+
 *  |              |
 *  |              |<- Allow to reclaim this page
 *  |              |
 *  |              |
 *  +--------------+
 *  +--------------+
 *  |              |
 *  |______________|
 *  |______________|<- Chunk to split at page alignment
 *  |              |
 *  +--------------+
 */
static int chunk_split_aligned(struct chunk_hdr *chunk,
                               struct hyp_allocator *allocator)
{
        struct chunk_hdr *next_chunk = chunk_get_next(chunk, allocator);
        unsigned long delta, mapped_end = ((unsigned long)(chunk) + chunk->mapped_size);
        struct chunk_hdr *new_chunk;
        if (((((unsigned long)(mapped_end)) & ((typeof((unsigned long)(mapped_end)))((1UL << 12)) - 1)) == 0)) {
                return 0;
        }
        new_chunk = (struct chunk_hdr *)((((mapped_end) - (((1UL << 12)) - 1)) + ((typeof((mapped_end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((mapped_end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1));
        if ((unsigned long)new_chunk <= (unsigned long)chunk) {
                return -22 /* Invalid argument */;
        }
        delta = ((unsigned long)next_chunk - (unsigned long)new_chunk);
        /*
         * This shouldn't happen, chunks are installed to a minimum distance
         * from the page start
         */
        (!!(delta < (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL))));
        (!!(chunk_install(new_chunk, 0, chunk, allocator)));
        return 0;
}
/*@
// HK: This lemma is unsound because it ignores pointer provenance.
// Workaround: attach a single provenance with the address in [HA.start, HA.end)
// and use it everywhere (TODO).
lemma ConcatArray (pointer va, u64 size1, u64 size2)
requires
    let va2 = (u64)va + size1;
    take U = each(u64 i; i < size1){
        W<char>(array_shift<char>(va, i))
    };
    take V = each(u64 i; i < size2){
        W<char>(array_shift<char>((pointer)va2, i))
    };
ensures
    take X = each(u64 i; i < size1 + size2){
        W<char>(array_shift<char>(va, i))
    };
@*/
// TODO(HK): fix this after the elaboration bug is fixed
//static int chunk_inc_map(struct chunk_hdr *chunk, size_t map_size,
static int chunk_inc_map(struct chunk_hdr *chunk, unsigned long map_size,
                         struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take C_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = C_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take Next_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(Next_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
                let cond = (u64)Cn_chunk_unmapped_size(C_pre.Hdr) >= map_size;
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take C_post = Cn_chunk_hdr(chunk, A_post);
                take Next_post = Cn_chunk_hdr(next_chunk, A_post);
                A_post == A_pre;
                Next_post == Next_pre;
                C_post.Hdr.alloc_size == C_pre.Hdr.alloc_size;
                C_post.Hdr.va_size == C_pre.Hdr.va_size;
                C_post.Hdr.header_address == C_pre.Hdr.header_address;
                !cond implies return == -EINVAL();
                return == 0i32 implies
                C_post.Hdr.mapped_size == (C_pre.Hdr.mapped_size + (u32)map_size);
                return != 0i32 implies
                C_post.Hdr.mapped_size == C_pre.Hdr.mapped_size;
                //cond implies C_post.mapped_size == (C_pre.mapped_size + map_size);
@*/
{
        int ret;
        if (chunk_unmapped_size(chunk, allocator) < map_size) {
                return -22 /* Invalid argument */;
        }
        // TODO(HK): this function returns a "new memory ownership", so we have
        // to handle this
        ret = hyp_allocator_map(allocator, ((unsigned long)(chunk) + chunk->mapped_size),
                                map_size);
        if (ret) {
                return ret;
        }
        /*@ apply ConcatArray(array_shift<unsigned char>(chunk, Cn_chunk_hdr_size()), (u64)chunk->mapped_size - Cn_chunk_hdr_size(), (u64)map_size); @*/
        chunk->mapped_size += map_size;
        chunk_hash_update(chunk);
        return 0;
}
static size_t chunk_dec_map(struct chunk_hdr *chunk,
                            struct hyp_allocator *allocator,
                            size_t reclaim_target)
{
        unsigned long start, end;
        size_t reclaimable;
        start = (((((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))) + ((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1));
        end = ((unsigned long)(chunk) + chunk->mapped_size);
        if (start >= end) {
                return 0;
        }
        reclaimable = end - start;
        if (reclaimable < (1UL << 12)) {
                return 0;
        }
        if (chunk_split_aligned(chunk, allocator)) {
                return 0;
        }
        end = ((unsigned long)(chunk) + chunk->mapped_size);
        reclaimable = min_u64(end - start, reclaim_target);
        start = end - reclaimable;
        hyp_allocator_unmap(allocator, start, reclaimable);
        chunk->mapped_size -= reclaimable;
        chunk_hash_update(chunk);
        return reclaimable;
}
static unsigned long chunk_addr_fixup(unsigned long addr)
/*@
    requires
        let min_chunk_size = Cn_chunk_size(0u64);
        let page = PAGE_ALIGN_DOWN(addr);
        let delta = addr - page;
        let res = delta == 0u64 ? addr :
                (delta < min_chunk_size ? (page + min_chunk_size) : addr);
    ensures
        return == res;
@*/
{
        unsigned long min_chunk_size = (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL));
        unsigned long page = ((((addr) - (((1UL << 12)) - 1)) + ((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1));
        unsigned long delta = addr - page;
        if (!delta) {
                return addr;
        }
        /*
         * To maximize reclaim, a chunk must fit between the page start and this
         * addr.
         */
        if (delta < min_chunk_size) {
                return page + min_chunk_size;
        }
        return addr;
}
// HK: for sanity check
// Note:
//   - Implementation says chunk->node->next == &allocator->chunks
//   - Spec says &chunk->node == allocator->chunks->prev
//   - This should be verified assuming that "chunks" satisfy the invariant for
//     doubly-linked lists, which should be a part of the global invariant for
//     chunks and allocators.
//   - To enforce this invariant holds, we probably need to write a kind
//     of specs like: chunk ∈ allocator-chunks (using lookup predicate).
//   - However, this is going to be a very "inefficient" spec (involves recursively
//     defined predicate). Is there any good way to avoid this?
// HK(Update): Even though the above comments will be applicable to somewhere in the
// future, to prove the following spec, it is actually not a problem.
// (if you replace Cn_list_is_last with is_last_chunk, you will have the problem)
static _Bool my_list_is_last(struct chunk_hdr *chunk, struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let chunk_node_ptr = member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                return == (Cn_list_is_last(B_pre.Node, member_shift<struct hyp_allocator>(allocator, chunks))? 1u8 : 0u8);
@*/
{
        return list_is_last(&(chunk)->node, &(allocator)->chunks);
}
static struct chunk_hdr *my_chunk_get_next(struct chunk_hdr *chunk, struct hyp_allocator *allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Node = B_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post =Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);
@*/
{
        struct chunk_hdr * next = list_is_last(&(chunk)->node, &(allocator)->chunks) ?
                __cerbvar_NULL : ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0UL - offsetof(typeof(*(chunk)), node))));
        chunk_hash_validate(next);
        return next;
}
static size_t my_chunk_unmapped_size(struct chunk_hdr * chunk, struct hyp_allocator* allocator)
/*@
        requires
                take A_pre = Cn_hyp_allocator_only(allocator);
                take B_pre = Cn_chunk_hdr(chunk, A_pre);
                let Hdr = B_pre.Hdr;
                let Node = B_pre.Node;
                let next_node = Node.next;
                let next_chunk = my_container_of_chunk_hdr(next_node);
                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);
                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                A_pre == A_post;
                B_pre == B_post;
                C_pre == C_post;
                return == (u64)(Hdr.va_size - Hdr.mapped_size);
@*/
{
        struct chunk_hdr *next = chunk_get_next(chunk, allocator);
        //struct chunk_hdr *next = my_chunk_get_next(chunk, allocator);
        unsigned long allocator_end = (allocator)->start + (allocator)->size;
        return next ? (unsigned long)next - ((unsigned long)(chunk) + chunk->mapped_size)
                    : allocator_end - ((unsigned long)(chunk) + chunk->mapped_size);
}
static _Bool chunk_can_split(struct chunk_hdr *chunk, unsigned long addr,
                            struct hyp_allocator *allocator)
/*
   required_size
   |-------------|-------------|
   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
           va_size
   => |---------|    |-----------|
        |--------------^
*/
/*@
    requires
        take A_pre = Cn_hyp_allocator_only(allocator);
        take B_pre = Cn_chunk_hdr(chunk, A_pre);
        let node_ptr = member_shift<struct chunk_hdr>(chunk, node);
        let C_pre = B_pre.Hdr;
        let Node = B_pre.Node;
        let next_node = Node.next;
        let next_chunk = my_container_of_chunk_hdr(next_node);
        take D_pre = Cn_chunk_hdr(next_chunk, A_pre);
        ptr_eq(D_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));
    ensures
        take A_post = Cn_hyp_allocator_only(allocator);
        take B_post = Cn_chunk_hdr(chunk, A_post);
        take D_post = Cn_chunk_hdr(next_chunk, A_post);
        let chunk_end = (u64)chunk + (u64)C_pre.mapped_size +
                (u64)Cn_chunk_unmapped_size(C_pre);

        Cn_list_is_last(Node, A_post.head)
        implies return == 0u8;
        !Cn_list_is_last(Node, A_post.head)
        implies return == (((addr + Cn_chunk_size(0u64)) < chunk_end) ? 1u8 : 0u8);
        A_pre == A_post;
        B_pre == B_post;
        D_pre == D_post;
        // HK: To prove the above, we require an invariant stating that
        // all sizes are less than 2^32 to avoid integer overflow.
@*/
{
        unsigned long chunk_end;
        /*
         * There is no point splitting the last chunk, subsequent allocations
         * would be able to use this space anyway.
         */
        if (list_is_last(&chunk->node, &allocator->chunks)) {
                return 0;
        }
        chunk_end = (unsigned long)chunk + chunk->mapped_size +
                    chunk_unmapped_size(chunk, allocator);
        return addr + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL)) < chunk_end;
}
static int chunk_recycle(struct chunk_hdr *chunk, size_t size,
                         struct hyp_allocator *allocator)
// remaining possible specifications
// -
/*@
    requires
        take HA_pre = Cn_hyp_allocator(allocator);

        take C_pre = RW<struct chunk_hdr>(chunk);
    ensures
        //take HA_out = Cn_hyp_allocator(allocator);
        take C_post = RW<struct chunk_hdr>(chunk);
        C_post.alloc_size == (u32)size;
        C_post.mapped_size == C_pre.mapped_size;
        C_post.node == C_pre.node;
        C_post.data == C_pre.data;
        return == 0i32;
        // TODO: write some spec on HA_out and HA_in
@*/
{
        unsigned long new_chunk_addr = (unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL));
        size_t missing_map, expected_mapping = size;
        struct chunk_hdr *new_chunk = __cerbvar_NULL;
        int ret;
        new_chunk_addr = chunk_addr_fixup(new_chunk_addr);
        if (chunk_can_split(chunk, new_chunk_addr, allocator)) {
                new_chunk = (struct chunk_hdr *)new_chunk_addr;
                // HK: when we can split the chunk,
                // the va addresses of the header of the new chunk have to be mapped.
                expected_mapping = new_chunk_addr + ((unsigned long)offsetof(struct chunk_hdr, data)) -
                                        (unsigned long)((void *)(&(chunk)->data));
        }
        // TODO: memcache part. We ignore this for now (HK).
        missing_map = chunk_needs_mapping(chunk, expected_mapping);
        if (missing_map) {
                ret = chunk_inc_map(chunk, missing_map, allocator);
                if (ret) {
                        return ret;
                }
        }
        chunk->alloc_size = size;
        chunk_hash_update(chunk);
        if (new_chunk) {
                (!!(chunk_install(new_chunk, 0, chunk, allocator)));
        }
        return 0;
}
static size_t chunk_try_destroy(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator,
                                size_t reclaim_target)
{
        size_t unmapped;
        if ((!!(chunk)->alloc_size)) {
                return 0;
        }
        /* Don't kill the entire chunk if this is not necessary */
        if (chunk->mapped_size > reclaim_target) {
                return 0;
        }
        if (list_is_first(&chunk->node, &allocator->chunks)) {
                /* last standing chunk ? */
                if (!list_is_last(&chunk->node, &allocator->chunks)) {
                        return 0;
                }
                list_del(&chunk->node);
                goto unmap;
        }
        /*
         * Resolve discontiguous unmapped zones that are the result
         * of a previous chunk_dec_map().
         *
         * To make sure we still keep track of that unmapped zone in our free
         * list, we need either to be the last chunk or to have prev unused. Two
         * contiguous chunks can be both free if they are separated by an
         * unmapped zone (see chunk_recycle()).
         */
        if (!((((unsigned long)((unsigned long)chunk)) & ((typeof((unsigned long)((unsigned long)chunk)))((1UL << 12)) - 1)) == 0)) {
                return 0;
        }
        if (list_is_last(&chunk->node, &allocator->chunks)) {
                goto destroy;
        }
        if ((!!(chunk_get_prev(chunk, allocator))->alloc_size)) {
                return 0;
        }
        if (chunk_split_aligned(chunk, allocator)) {
                return 0;
        }
destroy:
        chunk_list_del(chunk, allocator);
unmap:
        unmapped = chunk->mapped_size;
        hyp_allocator_unmap(allocator, (unsigned long)chunk,
                            chunk->mapped_size);
        return unmapped;
}
/*@
// function (boolean) SetupFirstChunk_ex1(cn_chunk_hdrs after)
// {
//         match (after) {
//             Chunk_nil {} => { false }
//             Chunk_cons { hd: next_chunk, tl: tl } => {
//                     tl == Chunk_nil {}
//             }
//         }
//
// }
predicate (boolean) SetupFirstChunk(pointer allocator, cn_hyp_allocator ha_pre,size_t size, i32 ret)
{
    if (ret == 0i32) {
        let start = (pointer)ha_pre.start;
        take a_out=Cn_hyp_allocator_focusing_on(allocator, start);
        // ownership to be returned to the client
        let chunk_data = array_shift<unsigned char>(start, Cn_chunk_hdr_size());
        take D = Cn_char_array(chunk_data, (u64)a_out.lseg.chunk.alloc_size);
        return a_out.lseg.before == Chunk_nil {}
            && a_out.lseg.chunk.header_address == (u64)start
            && (u64)a_out.lseg.chunk.alloc_size > size
            && a_out.lseg.after == Chunk_nil{};
    } else {
        take a_out=Cn_hyp_allocator(allocator);
        return a_out.ha == ha_pre && a_out.hdrs == Chunk_nil {};
    }
}
@*/
static int setup_first_chunk(struct hyp_allocator *allocator, size_t size)
/*@ requires take a_in=Cn_hyp_allocator(allocator);
    a_in.hdrs==Chunk_nil{};
    ensures
    take X = SetupFirstChunk(allocator, a_in.ha, size, return);
    X;
@*/
{
        int ret;
        ret = hyp_allocator_map(allocator, allocator->start,
                                (((((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))) + ((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)));
        if (ret) {
                return ret;
        }
        return chunk_install((struct chunk_hdr *)allocator->start, size, __cerbvar_NULL, allocator);
}
/*@
// datatype free_chunk_option {
//         FreeChunk_none {},
//         FreeChunk_some { cn_hyp_allocator ha, cn_free_chunk free_chunk}
// }
lemma ListSeg (pointer allocator, pointer result)
    requires
        take HA1 = Cn_hyp_allocator_focusing_on(allocator, result);
    ensures
        take HA2 = Cn_hyp_allocator(allocator);
        let lseg = HA1.lseg;
        HA2 == {ha: HA1.ha, hdrs: ConcatChunkList(lseg.before, Chunk_cons {hd: lseg.chunk, tl: lseg.after})};


predicate (boolean) GetFreeChunk(pointer allocator, u64 size, pointer result, {cn_hyp_allocator ha, datatype cn_chunk_hdrs hdrs} HA_in )
{
        if (ptr_eq(result, NULL)) {
                take HA_out = Cn_hyp_allocator(allocator);
                return HA_in == HA_out;
        } else {
                take HA_out = Cn_hyp_allocator_focusing_on(allocator, result);
                let lseg = HA_out.lseg;

                return
                is_free_chunk(lseg.chunk, (u32)size)
                && {ha: HA_out.ha, hdrs: ConcatChunkList(lseg.before, Chunk_cons {hd: lseg.chunk, tl: lseg.after})} == HA_in;
        }
}
@*/
static struct chunk_hdr *
get_free_chunk(struct hyp_allocator *allocator, size_t size)
// should the spec of this characterise "best", or just ensure that this returns a legit chunk?  We guess the latter is sufficient for functional correctness and we'll do that
// should the spec of this pull out the ownership of that chunk, or just identify the chunk?  We guess the context will sometimes have to mess with neighbouring chunks, so we'll do the pulling out there, not here
// what variable name to use for the result of Cn_hyp_allocator?
// (should CN support enforced per-type naming conventions?)
/*@
requires take HA_in = Cn_hyp_allocator(allocator);
ensures
        take res = GetFreeChunk(allocator, size, return, HA_in);
        res;

// is_free_chunk(ret,size,HA_in.hdrs); // it returns a chunk in the list (or NIL?) st the alloc_size is zero and total size (not just mapped size, and including header size) is at least what you asked for
@*/
{
        struct chunk_hdr *chunk, *best_chunk = __cerbvar_NULL;
        size_t best_available_size = allocator->size;
        // HK: O(n) search for the best chunk
        // Several thoughts:
        // 1. Doesn't care about the mapped_size, which may involve a lot of
        // mappings and unmappings. No?
        // 2. the invariant should be a bit complicated
        //  | 1 | -> | 2 | ... -> |best_chunk| -> ... -> |cur| -> ... -> |last|
        // a possible strategy for ownerships when best_chunk is not null
        //   - ListSeg Fst      ; first part until best_chunk
        //   - Chunk_hdr Best   ; best_chunk
        //   - ListSeg Discarded; from next of best_chunk to cur
        //   - Chunk_hdr Cur    ; cur
        //   - List Remaining   ; from next of cur to last
        // where ListSeg is a reversed list
        // if (best_chunk is not NULL) {
        //   take Fst  = ListSeg(ha.first, best_chunk);
        //   take Best = Chunk_hdr(best_chunk);
        //   take
        // }
        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0UL - offsetof(typeof(*(chunk)), node)))))
        /*@ inv {allocator} unchanged;
                {size} unchanged;
                //take Fst = Cn_chunk_hdrs_rev(ha.first, ha.head, ha, Chunk_nil{});
        @*/
        {
                size_t available_size = chunk->mapped_size +
                                        chunk_unmapped_size(chunk, allocator);
                if ((!!(chunk)->alloc_size)) {
                        continue;
                }
                if ((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)) > available_size) {
                        continue;
                }
                if (!best_chunk) {
                        best_chunk = chunk;
                        // [BUG] HK: why best_available_size is not set here?
                        continue;
                }
                if (best_available_size <= available_size) {
                        continue;
                }
                best_chunk = chunk;
                best_available_size = available_size;
        }
        return chunk_get(best_chunk);
}
/*@
predicate void Cn_char_array(pointer p, u64 size)
{
        take U = each(u64 i; i < size){
                W<char>(array_shift<char>(p, i))
        };
        return;
}

predicate void Conditional_Cn_char_array(pointer p, u64 size, boolean cond)
{
        if (cond) {
                take U = each(u64 i; i < size){
                        W<char>(array_shift<char>(p, i))
                };
                return;
        }
        else {
                return;
        }
}

predicate void MaybeCn_char_array(pointer p, u64 size)
{
        if (ptr_eq(p, NULL)) {
                return;
        } else {
                take U = Cn_char_array(p, size);
                return;
        }
}
@*/
void *hyp_alloc(size_t size)
/*@
        requires true;
        // TODO: allocator (global variable) ownership
        ensures take U = MaybeCn_char_array(return, size);
@*/
{
        struct hyp_allocator *allocator = &hyp_allocator;
        struct chunk_hdr *chunk, *last_chunk;
        unsigned long chunk_addr;
        int missing_map, ret = 0;
        size = ((((size)) + ((typeof((size)))((8UL)) - 1)) & ~((typeof((size)))((8UL)) - 1));
        hyp_spin_lock(&allocator->lock);
        //PS: ownership from lock invariant
        //PS: hyp_spin_lock returns Cn_hyp_allocator(&allocator)
        if (list_empty(&hyp_allocator.chunks)) {
                ret = setup_first_chunk(allocator, size);
                if (ret) {
                        goto end;
                }
                chunk = (struct chunk_hdr *)allocator->start;
                goto end;
        }
        chunk = get_free_chunk(allocator, size);
        if (chunk) {
                ret = chunk_recycle(chunk, size, allocator);
                goto end;
        }
        // HK: when there is no free chunk, we divide the last chunk
        last_chunk = chunk_get(((struct chunk_hdr *)((unsigned char *)((&allocator->chunks)->prev) + (0UL - offsetof(struct chunk_hdr, node)))));
        chunk_addr = (unsigned long)last_chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(last_chunk->alloc_size), 8UL));
        chunk_addr = chunk_addr_fixup(chunk_addr);
        chunk = (struct chunk_hdr *)chunk_addr;
        missing_map = chunk_needs_mapping(last_chunk,
                                          chunk_addr + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)) -
                                                (unsigned long)((void *)(&(last_chunk)->data)));
        if (missing_map) {
                ret = chunk_inc_map(last_chunk, missing_map, allocator);
                if (ret){
                        goto end;
                }
        }
        (!!(chunk_install(chunk, size, last_chunk, allocator)));
end:
        hyp_spin_unlock(&allocator->lock);
        *((&hyp_allocator_errno)) = ret;
        /* Enforce zeroing allocated memory */
        if (!ret) {
                memset(((void *)(&(chunk)->data)), 0, size);
        }
        return ret ? __cerbvar_NULL : ((void *)(&(chunk)->data));
}
void hyp_free(void *addr)
{
        struct chunk_hdr *chunk, *prev_chunk, *next_chunk;
        struct hyp_allocator *allocator = &hyp_allocator;
        char *chunk_data = (char *)addr;
        hyp_spin_lock(&allocator->lock);
        chunk = chunk_get(((struct chunk_hdr *)((unsigned char *)(chunk_data) + (0UL - offsetof(struct chunk_hdr, data)))));
        prev_chunk = chunk_get_prev(chunk, allocator);
        next_chunk = chunk_get_next(chunk, allocator);
        // HK: free is easy :) except for merging
        chunk->alloc_size = 0;
        chunk_hash_update(chunk);
        if (next_chunk && !(!!(next_chunk)->alloc_size)) {
                (!!(chunk_merge(next_chunk, allocator)));
        }
        if (prev_chunk && !(!!(prev_chunk)->alloc_size)) {
                (!!(chunk_merge(chunk, allocator)));
        }
        hyp_spin_unlock(&allocator->lock);
}
/*
 * While chunk_try_destroy() is actually destroying what can be, this function
 * only help with estimating how much pages can be reclaimed. However the same
 * comments apply here.
 */
static _Bool chunk_destroyable(struct chunk_hdr *chunk,
                              struct hyp_allocator *allocator)
{
        if ((!!(chunk)->alloc_size)) {
                return 0;
        }
        if (!((((unsigned long)(chunk)) & ((typeof((unsigned long)(chunk)))((1UL << 12)) - 1)) == 0)) {
                return 0;
        }
        if (list_is_first(&chunk->node, &allocator->chunks)) {
                if (list_is_last(&chunk->node, &allocator->chunks)) {
                        return 1;
                }
                return 0;
        }
        return !(!!(chunk_get_prev(chunk, allocator))->alloc_size);
}
static size_t chunk_reclaimable(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator)
{
        unsigned long start, end = ((unsigned long)(chunk) + chunk->mapped_size);
        /*
         * This should not happen, chunks are installed at a minimum distance
         * from the page start
         */
        (!!(!((((unsigned long)(end)) & ((typeof((unsigned long)(end)))((1UL << 12)) - 1)) == 0) && (end - ((((end) - (((1UL << 12)) - 1)) + ((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) < (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL)))));
        if (chunk_destroyable(chunk, allocator)) {
                start = (unsigned long)chunk;
        }
        else {
                start = (((((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))) + ((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1));
        }
        end = ((((end) - (((1UL << 12)) - 1)) + ((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1));
        if (start > end) {
                return 0;
        }
        return end - start;
}
// HK: counts the number of unused but mapped pages.
// This includes the pages that are in the memcache.
int hyp_alloc_reclaimable(void)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        struct chunk_hdr *chunk;
        int reclaimable = 0;
        int cpu;
        hyp_spin_lock(&allocator->lock);
        /*
         * This is slightly pessimistic: a real reclaim might be able to "fix"
         * discontiguous unmapped region by deleting chunks from the top to the
         * bottom.
         */
        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0UL - offsetof(typeof(*(chunk)), node)))))
                reclaimable += chunk_reclaimable(chunk, allocator) >> 12;
        for (cpu = 0; cpu < hyp_nr_cpus; cpu++) {
                struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
                reclaimable += mc->nr_pages;
        }
        hyp_spin_unlock(&allocator->lock);
        return reclaimable;
}
// Hk: another interesting target
void hyp_alloc_reclaim(struct kvm_hyp_memcache *mc, int target)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        struct kvm_hyp_memcache *alloc_mc;
        struct chunk_hdr *chunk, *tmp;
        int cpu;
        if (target <= 0) {
                return;
        }
        hyp_spin_lock(&allocator->lock);
        /* Start emptying potential unused memcache */
        for (cpu = 0; cpu < hyp_nr_cpus; cpu++) {
                alloc_mc = (&hyp_allocator_mc);
                while (alloc_mc->nr_pages) {
                        unsigned long order;
                        void *page = pop_hyp_memcache(alloc_mc, hyp_phys_to_virt, &order);
                        (!!(order));
                        push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                        (!!(__pkvm_hyp_donate_host(hyp_virt_to_pfn(page), 1)));
                        target--;
                        if (target <= 0) {
                                goto done;
                        }
                }
        }
        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->prev) + (0UL - offsetof(typeof(*chunk), node)))), tmp = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.prev) + (0UL - offsetof(typeof(*(chunk)), node)))); !(&chunk->node == (&allocator->chunks)); chunk = tmp, tmp = ((typeof(*(tmp)) *)((unsigned char *)((tmp)->node.prev) + (0UL - offsetof(typeof(*(tmp)), node))))) {
                size_t r;
                chunk_hash_validate(chunk);
                r = chunk_try_destroy(chunk, allocator, target << 12);
                if (!r) {
                        r = chunk_dec_map(chunk, allocator, target << 12);
                }
                target -= r >> 12;
                if (target <= 0) {
                        break;
                }
        }
        alloc_mc = (&hyp_allocator_mc);
        while (alloc_mc->nr_pages) {
                unsigned long order;
                void *page = pop_hyp_memcache(alloc_mc, hyp_phys_to_virt, &order);
                (!!(order));
                memset(page, 0, (1UL << 12));
                                                        ;
                push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                (!!(__pkvm_hyp_donate_host(hyp_virt_to_pfn(page), 1)));
        }
done:
        hyp_spin_unlock(&allocator->lock);
}
int hyp_alloc_refill(struct kvm_hyp_memcache *host_mc)
{
        struct kvm_hyp_memcache *alloc_mc = (&hyp_allocator_mc);
        return refill_memcache(alloc_mc, host_mc->nr_pages + alloc_mc->nr_pages,
                               host_mc);
}
int hyp_alloc_init(size_t size)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        int ret;
        size = ((((size)) + ((typeof((size)))(((1UL << 12))) - 1)) & ~((typeof((size)))(((1UL << 12))) - 1));
        /* constrained by chunk_hdr *_size types */
        if (size > ((u32)~0U)) {
                return -22 /* Invalid argument */;
        }
        ret = pkvm_alloc_private_va_range(size, &allocator->start);
        if (ret) {
                return ret;
        }
        allocator->size = size;
        INIT_LIST_HEAD(&allocator->chunks);
                                            ;
        return 0;
}
int hyp_alloc_errno(void)
{
        int *errno = (&hyp_allocator_errno);
        return *errno;
}
u8 hyp_alloc_missing_donations(void)
{
        u8 *missing = ((&hyp_allocator_missing_donations));
        u8 __missing = *missing;
        *missing = 0;
        return __missing;
}
void dump_chunks(void)
{
}

int main() {}
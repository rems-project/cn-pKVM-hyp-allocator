#include <stdlib.h> /* clang -E -fkeep-system-includes */

// #include <stdio.h>
#include <assert.h> /* clang -E -fkeep-system-includes */

/* SPDX-License-Identifier: GPL-2.0-only */
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
// #include <fulminate.h>
// #include "alloc.c"
phys_addr_t ident_to_pa(void *addr)
{
 return (phys_addr_t)addr;
}
void* ident_to_va(phys_addr_t addr)
{
 return (void*)addr;
}
int dummy_memcache(struct kvm_hyp_memcache *mc, u64 min_pages)
{
 while (mc->nr_pages < min_pages) {
  phys_addr_t *p = aligned_alloc((1UL << 12), (1UL << 12));
  memset(p, 0, (1UL << 12));
  if (!p) {
   return -12 /* Out of memory */;
  }
  push_hyp_memcache(mc, p, ident_to_pa, 0);
  // printf("  \x1b[32mPUSHED: %p -- head: %p\x1b[0m\n", p, (void*)mc->head);
 }
 return 0;
}
void dump_chunks(void);
struct kvm_hyp_memcache host_mc = { 0 };
void test1(void)
{
 int *p = hyp_alloc(4*sizeof(int));
 assert(p);
 dump_chunks();
 int *q = hyp_alloc((1UL << 12) + 128);
 assert(q);
 dump_chunks();
 hyp_free(p);
 dump_chunks();
 hyp_free(q);
 dump_chunks();
 p = hyp_alloc(sizeof(int));
 assert(p);
 dump_chunks();
}
void test2(void)
{
 dump_chunks();
 int *p = hyp_alloc(4*sizeof(int));
 assert(p);
 dump_chunks();
 int *q = hyp_alloc((1UL << 12) + 128);
 assert(q);
 dump_chunks();
 int *r = hyp_alloc(sizeof(int));
 assert(r);
 dump_chunks();
 hyp_free(r);
 dump_chunks();
 hyp_free(q);
 dump_chunks();
 r = hyp_alloc((1UL << 12));
 assert(r);
 dump_chunks();
 q = hyp_alloc(sizeof(int));
 assert(q);
 dump_chunks();
 // printf("==> %d\n", hyp_alloc_reclaimable());
 hyp_free(r);
 dump_chunks();
 hyp_alloc_reclaim(&host_mc, 14);
 dump_chunks();
 // printf("==> %d\n", hyp_alloc_reclaimable());
}
void test3(void)
{
 dump_chunks();
 assert(hyp_alloc(sizeof(int)));
 dump_chunks();
 int *p = hyp_alloc(8 + (1UL << 12));
 assert(p);
 dump_chunks();
 hyp_free(p);
 dump_chunks();
 int n = hyp_alloc_reclaimable();
 dump_chunks();
 // printf("==> %d\n", n);
 // printf("errno: %d\n", hyp_alloc_errno());
 hyp_alloc_reclaim(&host_mc, n);
 // n = hyp_alloc_reclaimable();
 // printf("==> %d\n", n);
}
void shim_create_hyp_mapping(size_t size);
int main(void)
{
 int ret;
 // SHIM INIT
 shim_create_hyp_mapping(64 << 12);
 // printf("HYP_ALLOC_INIT\n");
 ret = hyp_alloc_init(16*(1UL << 12));
 if(ret) {
  do { exit(1); } while(0);
 }
 ret = dummy_memcache(&host_mc, 16);
 if (ret) {
  do { exit(1); } while(0);
 }
 // printf("HYP_ALLOC_REFILL\n");
 hyp_alloc_refill(&host_mc);
 test3();
}

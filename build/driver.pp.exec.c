#define __CN_INSTRUMENT
#include <cn-executable/utils.h>
#include <cn-executable/cerb_types.h>
typedef __cerbty_intptr_t intptr_t;
typedef __cerbty_uintptr_t uintptr_t;
typedef __cerbty_intmax_t intmax_t;
typedef __cerbty_uintmax_t uintmax_t;
static const int __cerbvar_INT_MAX = 0x7fffffff;
static const int __cerbvar_INT_MIN = ~0x7fffffff;

/* ORIGINAL C STRUCTS */

struct list_head {
  struct list_head* next;
  struct list_head* prev;
};

struct hyp_pool {
  struct list_head free_area[11];
  unsigned long long range_start;
  unsigned long long range_end;
  unsigned char max_order;
};

struct hyp_page {
  unsigned short refcount;
  unsigned char order;
  unsigned char flags;
};


/* CN RECORDS */

struct Hyp_pool_ex1_record {
  cn_map* APs;
  struct hyp_pool_cn* pool;
  cn_map* vmemmap;
};
struct exclude_none_record {
  cn_bool* any;
  cn_bool* do_ex1;
  cn_bool* do_ex2;
  cn_bits_u64* ex1;
  cn_bits_u64* ex2;
};

/* CN VERSIONS OF C STRUCTS */

struct list_head_cn {
  cn_pointer* next;
  cn_pointer* prev;
};

struct hyp_pool_cn {
  cn_map* free_area;
  cn_bits_u64* range_start;
  cn_bits_u64* range_end;
  cn_bits_u8* max_order;
};

struct hyp_page_cn {
  cn_bits_u16* refcount;
  cn_bits_u8* order;
  cn_bits_u8* flags;
};



/* OWNERSHIP FUNCTIONS */

static cn_bits_i32* owned_signed_int(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_bits_u32* owned_unsigned_int(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_bits_u64* owned_unsigned_long_long(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_pointer* owned_struct_hyp_pool_pointer(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_bits_u8* owned_unsigned_char(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_pointer* owned_struct_hyp_page_pointer(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_bits_i64* owned_signed_long_long(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_pointer* owned_void_pointer(cn_pointer*, enum spec_mode, struct loop_ownership*);
static cn_bits_u8* owned_char(cn_pointer*, enum spec_mode, struct loop_ownership*);
static struct hyp_pool_cn* owned_struct_hyp_pool(cn_pointer*, enum spec_mode, struct loop_ownership*);
static struct hyp_page_cn* owned_struct_hyp_page(cn_pointer*, enum spec_mode, struct loop_ownership*);
static struct list_head_cn* owned_struct_list_head(cn_pointer*, enum spec_mode, struct loop_ownership*);
/* CONVERSION FUNCTIONS */

/* GENERATED STRUCT FUNCTIONS */

static struct hyp_page_cn* default_struct_hyp_page_cn();
static struct hyp_pool_cn* default_struct_hyp_pool_cn();
static struct list_head_cn* default_struct_list_head_cn();
static void* cn_map_get_struct_hyp_page_cn(cn_map*, cn_integer*);
static void* cn_map_get_struct_hyp_pool_cn(cn_map*, cn_integer*);
static void* cn_map_get_struct_list_head_cn(cn_map*, cn_integer*);
static cn_bool* struct_hyp_page_cn_equality(void*, void*);
static cn_bool* struct_hyp_pool_cn_equality(void*, void*);
static cn_bool* struct_list_head_cn_equality(void*, void*);
static struct hyp_page convert_from_struct_hyp_page_cn(struct hyp_page_cn*);
static struct hyp_pool convert_from_struct_hyp_pool_cn(struct hyp_pool_cn*);
static struct list_head convert_from_struct_list_head_cn(struct list_head_cn*);
static struct hyp_page_cn* convert_to_struct_hyp_page_cn(struct hyp_page);
static struct hyp_pool_cn* convert_to_struct_hyp_pool_cn(struct hyp_pool);
static struct list_head_cn* convert_to_struct_list_head_cn(struct list_head);
/* RECORD FUNCTIONS */
static cn_bool* struct_Hyp_pool_ex1_record_equality(void*, void*);
static cn_bool* struct_exclude_none_record_equality(void*, void*);
static struct Hyp_pool_ex1_record* default_struct_Hyp_pool_ex1_record();
static struct exclude_none_record* default_struct_exclude_none_record();
static void* cn_map_get_struct_Hyp_pool_ex1_record(cn_map*, cn_integer*);
static void* cn_map_get_struct_exclude_none_record(cn_map*, cn_integer*);
/* CN FUNCTIONS */

static struct list_head_cn* todo_default_list_head();
static cn_pointer* virt(cn_pointer*, cn_bits_i64*);
static cn_bits_u8* get_order_uf(cn_bits_u64*);
static cn_bool* hyp_pool_wf(cn_pointer*, struct hyp_pool_cn*, cn_pointer*, cn_bits_i64*);
static cn_bool* freeArea_cell_wf(cn_bits_u8*, cn_bits_i64*, cn_pointer*, cn_map*, cn_map*, cn_pointer*, struct hyp_pool_cn*, struct exclude_none_record*);
static cn_bool* vmemmap_l_wf(cn_bits_u64*, cn_bits_i64*, cn_pointer*, cn_map*, cn_map*, cn_pointer*, struct hyp_pool_cn*, struct exclude_none_record*);
static cn_bool* vmemmap_wf(cn_bits_u64*, cn_map*, cn_pointer*, struct hyp_pool_cn*);
static cn_bool* vmemmap_normal_order_wf(cn_bits_u64*, struct hyp_page_cn*, struct hyp_pool_cn*);
static cn_bool* init_vmemmap_page(cn_bits_u64*, cn_map*, cn_pointer*, struct hyp_pool_cn*);
static cn_bool* page_group_ok(cn_bits_u64*, cn_map*, struct hyp_pool_cn*);
static cn_bool* vmemmap_good_pointer(cn_bits_i64*, cn_pointer*, cn_map*, cn_bits_u64*, cn_bits_u64*, struct exclude_none_record*);
static struct exclude_none_record* exclude_two(cn_bits_u64*, cn_bits_u64*);
static struct exclude_none_record* exclude_one(cn_bits_u64*);
static struct exclude_none_record* exclude_none();
static cn_bool* excluded(struct exclude_none_record*, cn_bits_u64*);
static cn_bool* page_aligned(cn_bits_u64*, cn_bits_u8*);
static cn_bits_u64* page_size_of_order(cn_bits_u8*);
static cn_bool* cellPointer(cn_pointer*, cn_bits_u64*, cn_bits_u64*, cn_bits_u64*, cn_pointer*);
static cn_bits_u64* order_align(cn_bits_u64*, cn_bits_u8*);
static cn_bool* order_aligned(cn_bits_u64*, cn_bits_u8*);
static cn_bits_u64* pfn_buddy(cn_bits_u64*, cn_bits_u8*);
static cn_bits_u64* calc_buddy(cn_bits_u64*, cn_bits_u8*);
static cn_pointer* cn_hyp_page_to_virt(cn_pointer*, cn_bits_i64*, cn_pointer*, cn_pointer*);
static cn_pointer* cn__hyp_va(cn_pointer*, cn_bits_i64*, cn_bits_u64*);
static cn_bits_u64* cn_hyp_page_to_phys(cn_pointer*, cn_pointer*);
static cn_bits_u64* cn_hyp_pfn_to_phys(cn_bits_u64*);
static cn_bits_u64* cn_hyp_virt_to_pfn(cn_bits_i64*, cn_pointer*);
static cn_bits_u64* cn_hyp_phys_to_pfn(cn_bits_u64*);
static cn_bits_u64* cn__hyp_pa(cn_bits_i64*, cn_pointer*);
static cn_bits_u64* cn_hyp_page_to_pfn(cn_pointer*, cn_pointer*);
static cn_bits_u8* hyp_no_order();
static cn_bits_u8* max_order();
static cn_bits_u64* page_size();
static cn_pointer* copy_alloc_id_cn(cn_bits_u64*, cn_pointer*);
static cn_bits_u64* max_pfn();
static cn_bool* addr_eq(cn_pointer*, cn_pointer*);
static cn_bool* prov_eq(cn_pointer*, cn_pointer*);
static cn_bool* ptr_eq(cn_pointer*, cn_pointer*);
static cn_bool* is_null(cn_pointer*);
static cn_bool* not(cn_bool*);
static cn_bits_u8* MINu8();
static cn_bits_u8* MAXu8();
static cn_bits_u16* MINu16();
static cn_bits_u16* MAXu16();
static cn_bits_u32* MINu32();
static cn_bits_u32* MAXu32();
static cn_bits_u64* MINu64();
static cn_bits_u64* MAXu64();
static cn_bits_i8* MINi8();
static cn_bits_i8* MAXi8();
static cn_bits_i16* MINi16();
static cn_bits_i16* MAXi16();
static cn_bits_i32* MINi32();
static cn_bits_i32* MAXi32();
static cn_bits_i64* MINi64();
static cn_bits_i64* MAXi64();

static struct list_head_cn* O_struct_list_head(cn_pointer*, cn_bool*, enum spec_mode, struct loop_ownership*);
static struct Hyp_pool_ex1_record* Hyp_pool(cn_pointer*, cn_pointer*, cn_pointer*, cn_bits_i64*, enum spec_mode, struct loop_ownership*);
static struct Hyp_pool_ex1_record* Hyp_pool_ex2(cn_pointer*, cn_pointer*, cn_pointer*, cn_bits_i64*, cn_bits_u64*, cn_bits_u64*, enum spec_mode, struct loop_ownership*);
static struct Hyp_pool_ex1_record* Hyp_pool_ex1(cn_pointer*, cn_pointer*, cn_pointer*, cn_bits_i64*, cn_bits_u64*, enum spec_mode, struct loop_ownership*);
static struct list_head_cn* AllocatorPage(cn_pointer*, cn_bool*, cn_bits_u8*, enum spec_mode, struct loop_ownership*);
static void AllocatorPageZeroPart(cn_pointer*, cn_bits_u8*, enum spec_mode, struct loop_ownership*);
static void ZeroPage(cn_pointer*, cn_bool*, cn_bits_u8*, enum spec_mode, struct loop_ownership*);
static void Page(cn_pointer*, cn_bool*, cn_bits_u8*, enum spec_mode, struct loop_ownership*);
static void ByteV(cn_pointer*, cn_bits_u8*, enum spec_mode, struct loop_ownership*);
static void Byte(cn_pointer*, enum spec_mode, struct loop_ownership*);
static void bytes_to_struct_list_head(cn_pointer*, cn_bits_u8*);
static void struct_list_head_to_bytes(cn_pointer*);
static void page_size_of_order2(cn_bits_u8*);
static void find_buddy_xor(cn_bits_u64*, cn_bits_u8*);
static void attach_inc_loop(cn_map*, cn_pointer*, struct hyp_pool_cn*, cn_pointer*, cn_bits_u8*);
static void page_size_of_order_lemma();
static void order_aligned_init(cn_bits_u64*);
static void page_group_ok_easy(cn_pointer*, struct hyp_pool_cn*);
static void order_align_inv_loop(cn_pointer*, cn_map*, struct hyp_pool_cn*, cn_pointer*);
static void lemma4(cn_bits_u64*, cn_bits_u8*);
static void page_size_of_order_inc(cn_bits_u8*);
static void extract_l(cn_bits_u64*, cn_bits_u8*);
static void lemma2(cn_bits_u64*, cn_bits_u8*);
static void order_dec_inv(cn_bits_u64*, cn_bits_u64*, cn_bits_u8*, cn_bits_u8*);
enum CN_GHOST_ENUM {
  CLEARED,
  EMPTY
};
enum CN_GHOST_ENUM ghost_call_site;
#ifndef offsetof
#define offsetof(st, m) ((__cerbty_size_t)((char *)&((st *)0)->m - (char *)0))
#endif
#pragma GCC diagnostic ignored "-Wattributes"

/* GLOBAL ACCESSORS */
void* memcpy(void* dest, const void* src, __cerbty_size_t count );
signed long long* cn_test_get_static_driverpp_hyp_physvirt_offset();
void cn_test_set_static_driverpp_hyp_physvirt_offset(signed long long*const );
struct hyp_page** cn_test_get_static_driverpp___hyp_vmemmap();
void cn_test_set_static_driverpp___hyp_vmemmap(struct hyp_page**const );
void** cn_test_get_static_driverpp_cn_virt_base();
void cn_test_set_static_driverpp_cn_virt_base(void**const );
void** cn_test_get_static_driverpp_cn_virt_ptr();
void cn_test_set_static_driverpp_cn_virt_ptr(void**const );
// Some gcc builtins we support
[[ cerb::hidden ]] int __builtin_ffs (int x);
[[ cerb::hidden ]] int __builtin_ffsl (long x);
[[ cerb::hidden ]] int __builtin_ffsll (long long x);
[[ cerb::hidden ]] int __builtin_ctz (unsigned int x);
[[ cerb::hidden ]] int __builtin_ctzl (unsigned long x);
[[ cerb::hidden ]] int __builtin_ctzll (unsigned long long x);
[[ cerb::hidden ]] __cerbty_uint16_t __builtin_bswap16 (__cerbty_uint16_t x);
[[ cerb::hidden ]] __cerbty_uint32_t __builtin_bswap32 (__cerbty_uint32_t x);
[[ cerb::hidden ]] __cerbty_uint64_t __builtin_bswap64 (__cerbty_uint64_t x);
[[ cerb::hidden ]] void __builtin_unreachable(void);
// this is an optimisation hint that we can erase
/* originally: arch/arm64/kvm/hyp/nvhe/page_alloc.c */
// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2020 Google LLC
 * Author: Quentin Perret <qperret@google.com>
 */
/* originally ./include/uapi/asm-generic/posix_types.h */
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
typedef unsigned long __kernel_ulong_t;
typedef __kernel_ulong_t __kernel_size_t;
/* originally ./include/linux/stddef.h */
/* SPDX-License-Identifier: GPL-2.0 */
void *copy_alloc_id(unsigned long long i, void *p);
//#pragma clang diagnostic ignored "-Wunused-value"
void *copy_alloc_id(unsigned long long i, void *p) {
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&i), sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* i_addr_cn = convert_to_cn_pointer((&i));
  c_add_to_ghost_state((&p), sizeof(void*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    (unsigned long long) CN_LOAD(p);
    { __cn_ret = (void*) CN_LOAD(i); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&i), sizeof(unsigned long long));

  c_remove_from_ghost_state((&p), sizeof(void*));

return __cn_ret;

}
/* originally: ./tools/include/uapi/linux/const.h */
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/* const.h: Macros for dealing with constants.  */
/* CP: we fix a value for PAGE_SHIFT */
/* originally: ./arch/arm64/include/asm/page-def.h */
/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Based on arch/arm/include/asm/page.h
 *
 * Copyright (C) 1995-2003 Russell King
 * Copyright (C) 2017 ARM Ltd.
 */
typedef char PAGE_SIZE_t[((1UL) << 12)];
/* originally: ./include/vdso/limits.h */
/* SPDX-License-Identifier: GPL-2.0 */
/* originally: ./include/linux/mmzone.h */
/* SPDX-License-Identifier: GPL-2.0 */
/* originally: ./include/uapi/asm-generic/int-ll64.h */
/* SPDX-License-Identifier: GPL-2.0 WITH Linux-syscall-note */
/*
 * asm-generic/int-ll64.h
 *
 * Integer declarations for architectures which use "long long"
 * for 64-bit types.
 */
typedef unsigned char __u8;
typedef unsigned long long __u64;
typedef signed /* __signed__ */ long long __s64;
/* originally: ./include/asm-generic/int-ll64.h */
/* SPDX-License-Identifier: GPL-2.0 */
/*
 * asm-generic/int-ll64.h
 *
 * Integer declarations for architectures which use "long long"
 * for 64-bit types.
 */
typedef __u8 u8;
typedef __u64 u64;
typedef __s64 s64;
/* originally ./include/linux/types.h */
/* SPDX-License-Identifier: GPL-2.0 */
typedef __kernel_size_t size_t;
typedef u64 phys_addr_t;
struct list_head;
/* originally: ./tools/virtio/linux/kernel.h */
/* SPDX-License-Identifier: GPL-2.0 */
/* originally: */
/* #define container_of(ptr, type, member) ({            \ */
/*     const typeof( ((type *)0)->member ) *__mptr = (ptr);    \ */
/*     (type *)( (char *)__mptr - offsetof(type,member) );}) */
/* originally: ./include/linux/list.h */
/* SPDX-License-Identifier: GPL-2.0 */
static inline int list_empty(const struct list_head *head)
/*@ requires take O = Owned(head); 
  ptr_eq(head, (*head).next) || !addr_eq(head, (*head).next); 
 ensures take OR = Owned(head); 
  O == OR; 
  return == (((*head).next == head) ? 1i32 : 0i32); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("/*@ requires take O = Owned(llist); \n                  ^./driver.pp.c:86:19:");
  struct list_head_cn* O_cn = owned_struct_list_head(head_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take OR = Owned(llist); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:87:3-62");
  cn_assert(cn_bool_or(ptr_eq(head_cn, O_cn->next), cn_bool_not(addr_eq(head_cn, O_cn->next))), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&head), sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
    /* return READ_ONCE(head->next) == head; */
    { __cn_ret = CN_LOAD(CN_LOAD(head)->next) == CN_LOAD(head); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&head), sizeof(const struct list_head*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("  (*llist).next == llist; (*llist).prev == llist; @*/\n              ^./driver.pp.c:88:15:");
  struct list_head_cn* OR_cn = owned_struct_list_head(head_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~ ./driver.pp.c:89:3-11");
  cn_assert(struct_list_head_cn_equality(O_cn, OR_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* WRITE_ONCE (llist->next, llist); */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:90:3-52");
  cn_bits_i32* a_5138;
  if (convert_from_cn_bool(cn_pointer_equality(OR_cn->next, head_cn))) {
    a_5138 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_5138 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_5138), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/* renamed list to llist to avoid clash with CN keyword list */
static inline void INIT_LIST_HEAD(struct list_head *llist)
/*@ requires take O = Owned(llist); 
 ensures take OR = Owned(llist); 
  (*llist).next == llist; (*llist).prev == llist; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* llist_cn = convert_to_cn_pointer(llist);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("    return 1;\n                  ^./driver.pp.c:97:19:");
  struct list_head_cn* O_cn = owned_struct_list_head(llist_cn, PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&llist), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* llist_addr_cn = convert_to_cn_pointer((&llist));
  
    /* WRITE_ONCE (llist->next, llist); */
    CN_STORE(CN_LOAD(llist)->next, CN_LOAD(llist));
    CN_STORE(CN_LOAD(llist)->prev, CN_LOAD(llist));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&llist), sizeof(struct list_head*));

{
  update_cn_error_message_info("}\n              ^./driver.pp.c:98:15:");
  struct list_head_cn* OR_cn = owned_struct_list_head(llist_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void __list_del(struct list_head * prev, struct list_head * next)\n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:99:3-26");
  cn_assert(cn_pointer_equality(OR_cn->next, llist_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void __list_del(struct list_head * prev, struct list_head * next)\n                          ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:99:27-50");
  cn_assert(cn_pointer_equality(OR_cn->prev, llist_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline _Bool __list_del_entry_valid(struct list_head *entry)
/*@ ensures return == 1u8; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  _Bool __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* entry_cn = convert_to_cn_pointer(entry);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&entry), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* entry_addr_cn = convert_to_cn_pointer((&entry));
  
    { __cn_ret = 1; goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&entry), sizeof(struct list_head*));

{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  update_cn_error_message_info("  (*prev).next == next; \n            ^~~~~~~~~~~~~~ ./driver.pp.c:106:13-27");
  cn_assert(cn_bits_u8_equality(return_cn, convert_to_cn_bits_u8(1UL)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static inline void __list_del(struct list_head * prev, struct list_head * next)
/*@ requires take O1 = Owned(prev); 
  take O2 = O_struct_list_head(next, prev != next); 
 ensures take O1R = Owned(prev); 
  take O2R = O_struct_list_head(next, prev != next); 
  (prev == next) || (O2.next == O2R.next); 
  (prev == next) || {(*prev).prev} unchanged; 
  (*prev).next == next; 
  (prev == next) || (O2R.prev == prev); 
  (prev != next) || ((*prev).prev == prev); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* next_cn = convert_to_cn_pointer(next);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("        next->prev = prev;\n                  ^./driver.pp.c:111:19:");
  struct list_head_cn* O1_cn = owned_struct_list_head(prev_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /* WRITE_ONCE (prev->next, next); */\n       ^./driver.pp.c:112:8:");
  struct list_head_cn* O2_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&prev), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((&next), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
        update_cn_error_message_info(" ensures take O1R = Owned(entry); \n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:121:12-39");

cn_pop_msg_info();

        CN_STORE(CN_LOAD(next)->prev, CN_LOAD(prev));
        /* WRITE_ONCE (prev->next, next); */
        CN_STORE(CN_LOAD(prev)->next, CN_LOAD(next));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&prev), sizeof(struct list_head*));

  c_remove_from_ghost_state((&next), sizeof(struct list_head*));

{
  update_cn_error_message_info("        prev->next = next;\n              ^./driver.pp.c:113:15:");
  struct list_head_cn* O1R_cn = owned_struct_list_head(prev_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n       ^./driver.pp.c:114:8:");
  struct list_head_cn* O2R_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void __list_del_entry(struct list_head *entry)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:115:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2_cn->next, O2R_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ requires take O1 = Owned(entry); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:116:3-46");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O1R_cn->prev, O1_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  let prev = (*entry).prev; let next = (*entry).next; \n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:117:3-24");
  cn_assert(cn_pointer_equality(O1R_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  take O2 = O_struct_list_head(prev, prev != entry); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:118:3-40");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2R_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  take O3 = O_struct_list_head(next, prev != next); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:119:3-44");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_pointer_equality(O1R_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void __list_del_entry(struct list_head *entry)
/*@ requires take O1 = Owned(entry); 
  let prev = (*entry).prev; let next = (*entry).next; 
  take O2 = O_struct_list_head(prev, prev != entry); 
  take O3 = O_struct_list_head(next, prev != next); 
  (prev != entry) || (next == entry); 
 ensures take O1R = Owned(entry); 
  {*entry} unchanged; 
  take O2R = O_struct_list_head(prev, prev != entry); 
  take O3R = O_struct_list_head(next, prev != next); 
  (prev == next) || (O3.next == O3R.next); 
  (prev == next) || (O2.prev == O2R.prev); 
  (prev == entry) || (O2R.next == next); 
  (prev == next) || (O3R.prev == prev); 
  (prev != next) || ((prev == entry) || (O2R.prev == prev)); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* entry_cn = convert_to_cn_pointer(entry);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  (prev == entry) || (O2R.next == next); \n                  ^./driver.pp.c:127:19:");
  struct list_head_cn* O1_cn = owned_struct_list_head(entry_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* prev_cn;
  prev_cn = O1_cn->prev;
  cn_pointer* next_cn;
  next_cn = O1_cn->next;
  update_cn_error_message_info("  (prev != next) || ((prev == entry) || (O2R.prev == prev)); @*/\n       ^./driver.pp.c:129:8:");
  struct list_head_cn* O2_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, entry_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n       ^./driver.pp.c:130:8:");
  struct list_head_cn* O3_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ split_case (*entry).prev != entry; @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:131:3-38");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, entry_cn)), cn_pointer_equality(next_cn, entry_cn)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&entry), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* entry_addr_cn = convert_to_cn_pointer((&entry));
  
        update_cn_error_message_info("  (*entry).prev != entry; \n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:142:12-49");

cn_pop_msg_info();

        update_cn_error_message_info(" ensures take O1R = Owned(entry); \n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:143:12-57");

cn_pop_msg_info();

    if (!(
({
  ghost_call_site = EMPTY;
  0;
})
, __list_del_entry_valid(CN_LOAD(entry))))
        { goto __cn_epilogue; }

    (
({
  ghost_call_site = EMPTY;
  0;
})
, __list_del(CN_LOAD(CN_LOAD(entry)->prev), CN_LOAD(CN_LOAD(entry)->next)));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&entry), sizeof(struct list_head*));

{
  update_cn_error_message_info("        /*@ split_case (*entry).prev != (*entry).next; @*/\n              ^./driver.pp.c:132:15:");
  struct list_head_cn* O1R_cn = owned_struct_list_head(entry_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    if (!__list_del_entry_valid(entry))\n  ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:133:3-22");
  cn_assert(struct_list_head_cn_equality(O1R_cn, O1_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        return;\n       ^./driver.pp.c:134:8:");
  struct list_head_cn* O2R_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, entry_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    __list_del(entry->prev, entry->next);\n       ^./driver.pp.c:135:8:");
  struct list_head_cn* O3R_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:136:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3_cn->next, O3R_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void list_del_init(struct list_head *entry)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:137:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2_cn->prev, O2R_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ requires take O1 = Owned(entry); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:138:3-41");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, entry_cn), cn_pointer_equality(O2R_cn->next, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  let prev = (*entry).prev; let next = (*entry).next; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:139:3-40");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3R_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  take O2 = Owned(prev); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:140:3-61");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_bool_or(cn_pointer_equality(prev_cn, entry_cn), cn_pointer_equality(O2R_cn->prev, prev_cn))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void list_del_init(struct list_head *entry)
/*@ requires take O1 = Owned(entry); 
  let prev = (*entry).prev; let next = (*entry).next; 
  take O2 = Owned(prev); 
  take O3 = O_struct_list_head(next, prev != next); 
  (*entry).prev != entry; 
 ensures take O1R = Owned(entry); 
  (*entry).prev == entry; (*entry).next == entry; 
  take O2R = Owned(prev); 
  take O3R = O_struct_list_head(next, prev != next); 
  (prev == next) || (O3.next == O3R.next); 
  (prev == next) || {(*prev).prev} unchanged; 
  (*prev).next == next; 
  (prev == next) || (O3R.prev == prev); 
  (prev != next) || ((*prev).prev == prev); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* entry_cn = convert_to_cn_pointer(entry);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  (*prev).next == next; \n                  ^./driver.pp.c:149:19:");
  struct list_head_cn* O1_cn = owned_struct_list_head(entry_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* prev_cn;
  prev_cn = O1_cn->prev;
  cn_pointer* next_cn;
  next_cn = O1_cn->next;
  update_cn_error_message_info("  (prev != next) || ((*prev).prev == prev); @*/\n       ^./driver.pp.c:151:8:");
  struct list_head_cn* O2_cn = owned_struct_list_head(prev_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n       ^./driver.pp.c:152:8:");
  struct list_head_cn* O3_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/ if(entry->prev != entry)\n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:153:3-26");
  cn_assert(cn_bool_not(cn_pointer_equality(O1_cn->prev, entry_cn)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&entry), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* entry_addr_cn = convert_to_cn_pointer((&entry));
  
        /*CN*/ if(CN_LOAD(CN_LOAD(entry)->prev) != CN_LOAD(entry))
        ;
        /*CN*/ if(CN_LOAD(CN_LOAD(entry)->prev) != CN_LOAD(CN_LOAD(entry)->next))
        ;
    (
({
  ghost_call_site = EMPTY;
  0;
})
, __list_del_entry(CN_LOAD(entry)));
    (
({
  ghost_call_site = EMPTY;
  0;
})
, INIT_LIST_HEAD(CN_LOAD(entry)));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&entry), sizeof(struct list_head*));

{
  update_cn_error_message_info("        ;\n              ^./driver.pp.c:154:15:");
  struct list_head_cn* O1R_cn = owned_struct_list_head(entry_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/ if(entry->prev != entry->next)\n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:155:3-26");
  cn_assert(cn_pointer_equality(O1R_cn->prev, entry_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/ if(entry->prev != entry->next)\n                          ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:155:27-50");
  cn_assert(cn_pointer_equality(O1R_cn->next, entry_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        ;\n       ^./driver.pp.c:156:8:");
  struct list_head_cn* O2R_cn = owned_struct_list_head(prev_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    __list_del_entry(entry);\n       ^./driver.pp.c:157:8:");
  struct list_head_cn* O3R_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    INIT_LIST_HEAD(entry);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:158:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3_cn->next, O3R_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:159:3-46");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2R_cn->prev, O2_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline _Bool __list_add_valid(struct list_head *new,\n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:160:3-24");
  cn_assert(cn_pointer_equality(O2R_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                struct list_head *prev,\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:161:3-40");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3R_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                struct list_head *next)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:162:3-44");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_pointer_equality(O2R_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline _Bool __list_add_valid(struct list_head *new,
                struct list_head *prev,
                struct list_head *next)
/*@ ensures return == 1u8; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  _Bool __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* new_cn = convert_to_cn_pointer(new);
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* next_cn = convert_to_cn_pointer(next);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&new), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((&prev), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((&next), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
    { __cn_ret = 1; goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&new), sizeof(struct list_head*));

  c_remove_from_ghost_state((&prev), sizeof(struct list_head*));

  c_remove_from_ghost_state((&next), sizeof(struct list_head*));

{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  update_cn_error_message_info("  (*prev).next == new; \n            ^~~~~~~~~~~~~~ ./driver.pp.c:174:13-27");
  cn_assert(cn_bits_u8_equality(return_cn, convert_to_cn_bits_u8(1UL)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static inline void __list_add(struct list_head *new,
                  struct list_head *prev,
                  struct list_head *next)
/*@ requires take O1 = Owned(new); take O2 = Owned(prev); take O3 = O_struct_list_head(next, prev != next); 
 ensures take O1R = Owned(new); take O2R = Owned(prev); take O3R = O_struct_list_head(next, prev != next); 
  (prev == next) || {(*prev).prev} unchanged; 
  (prev == next) || (O3.next == O3R.next); 
  (*prev).next == new; 
  (prev == next) || (O3R.prev == new); 
  (prev != next) || ((*prev).prev == new); 
  (*new).next == next; (*new).prev == prev; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* new_cn = convert_to_cn_pointer(new);
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* next_cn = convert_to_cn_pointer(next);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("        /*@ split_case prev != next; @*/\n                  ^./driver.pp.c:181:19:");
  struct list_head_cn* O1_cn = owned_struct_list_head(new_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ split_case prev != next; @*/\n                                        ^./driver.pp.c:181:41:");
  struct list_head_cn* O2_cn = owned_struct_list_head(prev_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ split_case prev != next; @*/\n                                                               ^./driver.pp.c:181:64:");
  struct list_head_cn* O3_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&new), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((&prev), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((&next), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
    if (!(
({
  ghost_call_site = EMPTY;
  0;
})
, __list_add_valid(CN_LOAD(new), CN_LOAD(prev), CN_LOAD(next))))
        { goto __cn_epilogue; }

        update_cn_error_message_info("  take O3 = O_struct_list_head(prev, prev != next); \n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:192:12-39");

cn_pop_msg_info();

    CN_STORE(CN_LOAD(next)->prev, CN_LOAD(new));
    CN_STORE(CN_LOAD(new)->next, CN_LOAD(next));
    CN_STORE(CN_LOAD(new)->prev, CN_LOAD(prev));
    /* WRITE_ONCE (prev->next, new); */
    CN_STORE(CN_LOAD(prev)->next, CN_LOAD(new));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&new), sizeof(struct list_head*));

  c_remove_from_ghost_state((&prev), sizeof(struct list_head*));

  c_remove_from_ghost_state((&next), sizeof(struct list_head*));

{
  update_cn_error_message_info("    next->prev = new;\n              ^./driver.pp.c:182:15:");
  struct list_head_cn* O1R_cn = owned_struct_list_head(new_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    next->prev = new;\n                                     ^./driver.pp.c:182:38:");
  struct list_head_cn* O2R_cn = owned_struct_list_head(prev_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    next->prev = new;\n                                                             ^./driver.pp.c:182:62:");
  struct list_head_cn* O3R_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    new->next = next;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:183:3-46");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2R_cn->prev, O2_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    new->prev = prev;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:184:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3_cn->next, O3R_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* WRITE_ONCE (prev->next, new); */\n  ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:185:3-23");
  cn_assert(cn_pointer_equality(O2R_cn->next, new_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    prev->next = new;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:186:3-39");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3R_cn->prev, new_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:187:3-43");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_pointer_equality(O2R_cn->prev, new_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void list_add_tail(struct list_head *new, struct list_head *head)\n  ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:188:3-23");
  cn_assert(cn_pointer_equality(O1R_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void list_add_tail(struct list_head *new, struct list_head *head)\n                       ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:188:24-44");
  cn_assert(cn_pointer_equality(O1R_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void list_add_tail(struct list_head *new, struct list_head *head)
/*@ requires take O1 = Owned(new); 
  take O2 = Owned(head); 
  let prev = (*head).prev; let next = head; 
  take O3 = O_struct_list_head(prev, prev != next); 
 ensures take O1R = Owned(new); take O2R = Owned(head); take O3R = O_struct_list_head(prev, prev != next); 
  (prev == next) || (O3.prev == O3R.prev); 
  (prev == next) || {(*head).next} unchanged; 
  (*head).prev == new; 
  (prev == next) || (O3R.next == new); 
  (prev != next) || ((*head).next == new); 
  (*new).next == next; (*new).prev == prev; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* new_cn = convert_to_cn_pointer(new);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("{\n                  ^./driver.pp.c:200:19:");
  struct list_head_cn* O1_cn = owned_struct_list_head(new_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ split_case (*head).prev != head; @*/\n       ^./driver.pp.c:201:8:");
  struct list_head_cn* O2_cn = owned_struct_list_head(head_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* prev_cn;
  prev_cn = O2_cn->prev;
  cn_pointer* next_cn;
  next_cn = head_cn;
  update_cn_error_message_info("}\n       ^./driver.pp.c:203:8:");
  struct list_head_cn* O3_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&new), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((&head), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
        update_cn_error_message_info("/*\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:212:12-47");

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, __list_add(CN_LOAD(new), CN_LOAD(CN_LOAD(head)->prev), CN_LOAD(head)));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&new), sizeof(struct list_head*));

  c_remove_from_ghost_state((&head), sizeof(struct list_head*));

{
  update_cn_error_message_info("/* originally: ./include/linux/minmax.h */\n              ^./driver.pp.c:204:15:");
  struct list_head_cn* O1R_cn = owned_struct_list_head(new_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/* originally: ./include/linux/minmax.h */\n                                     ^./driver.pp.c:204:38:");
  struct list_head_cn* O2R_cn = owned_struct_list_head(head_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/* originally: ./include/linux/minmax.h */\n                                                             ^./driver.pp.c:204:62:");
  struct list_head_cn* O3R_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/* SPDX-License-Identifier: GPL-2.0 */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:205:3-43");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3_cn->prev, O3R_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* #define min(x, y)    __careful_cmp(x, y, <) */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:206:3-46");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O2R_cn->next, O2_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* originally: ./arch/arm64/kvm/hyp/include/nvhe/memory.h */\n  ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:207:3-23");
  cn_assert(cn_pointer_equality(O2R_cn->prev, new_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* SPDX-License-Identifier: GPL-2.0-only */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:208:3-39");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(O3R_cn->next, new_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* #include <asm/kvm_mmu.h> */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:209:3-43");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_pointer_equality(O2R_cn->next, new_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* #include <asm/page.h> */\n  ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:210:3-23");
  cn_assert(cn_pointer_equality(O1R_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* #include <asm/page.h> */\n                       ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:210:24-44");
  cn_assert(cn_pointer_equality(O1R_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
/* originally: ./include/linux/minmax.h */
/* SPDX-License-Identifier: GPL-2.0 */
/* #define min(x, y)    __careful_cmp(x, y, <) */
/* originally: ./arch/arm64/kvm/hyp/include/nvhe/memory.h */
/* SPDX-License-Identifier: GPL-2.0-only */
/* #include <asm/kvm_mmu.h> */
/* #include <asm/page.h> */
/* #include <linux/types.h> */
/*
 * Accesses to struct hyp_page flags must be serialized by the host stage-2
 * page-table lock due to the lack of atomics at EL2.
 */
struct hyp_pool;
struct hyp_page;
extern s64 hyp_physvirt_offset;
extern struct hyp_page *__hyp_vmemmap;
/*CN*/ /* extern */ void *cn_virt_base;
static inline void *hyp_phys_to_virt(phys_addr_t phys)
/*@ accesses hyp_physvirt_offset, cn_virt_base; 
 requires let virt = phys - (u64) hyp_physvirt_offset; 
 ensures {hyp_physvirt_offset} unchanged; 
  (u64) return == virt; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_bits_u64* phys_cn = convert_to_cn_bits_u64(phys);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  return == phys; @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:237:5-48");
  cn_bits_i64* O_hyp_physvirt_offset0_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  return == phys; @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:237:5-48");
  cn_pointer* O_cn_virt_base0_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_base()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* virt_cn;
  virt_cn = cn_bits_u64_sub(phys_cn, cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset0_cn));
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&phys), sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* phys_addr_cn = convert_to_cn_pointer((&phys));
  
    { __cn_ret = (
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)CN_LOAD((phys)) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_base)))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&phys), sizeof(unsigned long long));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("  return == phys; @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:237:5-48");
  cn_bits_i64* O_hyp_physvirt_offset1_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  return == phys; @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:237:5-48");
  cn_pointer* O_cn_virt_base1_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_base()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    return ((phys_addr_t)(addr) + hyp_physvirt_offset);\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:239:10-42");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset1_cn, O_hyp_physvirt_offset0_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:240:3-24");
  cn_assert(cn_bits_u64_equality(cast_cn_pointer_to_cn_bits_u64(return_cn), virt_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static inline phys_addr_t hyp_virt_to_phys(void *addr)
/*@ accesses hyp_physvirt_offset; 
 requires let phys = cn__hyp_pa(hyp_physvirt_offset, addr); 
 ensures {hyp_physvirt_offset} unchanged; 
  return == phys; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  unsigned long long __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("function (u64) max_pfn ()\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:245:5-34");
  cn_bits_i64* O_hyp_physvirt_offset2_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* phys_cn;
  phys_cn = cn__hyp_pa(O_hyp_physvirt_offset2_cn, addr_cn);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&addr), sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
    { __cn_ret = ((phys_addr_t)CN_LOAD((addr)) + CN_LOAD(hyp_physvirt_offset)); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&addr), sizeof(void*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("function (u64) max_pfn ()\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:245:5-34");
  cn_bits_i64* O_hyp_physvirt_offset3_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("@*/\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:247:10-42");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset3_cn, O_hyp_physvirt_offset2_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline u64 hyp_page_to_pfn(struct hyp_page *page)\n  ^~~~~~~~~~~~~~~ ./driver.pp.c:248:3-18");
  cn_assert(cn_bits_u64_equality(return_cn, phys_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
enum {
  enum_PAGE_SHIFT = 12,
};
/*@
function (u64) max_pfn ()
  { shift_right (0u64 - 1u64, (u64) enum_PAGE_SHIFT) }
@*/
static inline u64 hyp_page_to_pfn(struct hyp_page *page)
/*@ accesses __hyp_vmemmap; 
 requires let offs = ((u64) page) - ((u64) __hyp_vmemmap); 
  offs <= max_pfn () * (sizeof<struct hyp_page>); 
  mod(offs, sizeof<struct hyp_page>) == 0u64; 
 ensures return == offs / (sizeof<struct hyp_page>); 
  {__hyp_vmemmap} unchanged; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  unsigned long long __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* page_cn = convert_to_cn_pointer(page);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("/*     struct hyp_page *p = hyp_virt_to_page(addr); */\n    ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:260:5-28");
  cn_pointer* O___hyp_vmemmap0_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* offs_cn;
  offs_cn = cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(page_cn), cast_cn_pointer_to_cn_bits_u64(O___hyp_vmemmap0_cn));
  update_cn_error_message_info("/* } */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:262:3-50");
  cn_assert(cn_bits_u64_le(offs_cn, cn_bits_u64_multiply(max_pfn(), convert_to_cn_bits_u64(sizeof(struct hyp_page)))), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline int hyp_page_count(struct hyp_pool *pool, void *addr)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:263:3-46");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(offs_cn, convert_to_cn_bits_u64(sizeof(struct hyp_page))), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&page), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));
  
  { __cn_ret = ((struct hyp_page *)CN_LOAD((page)) - ((struct hyp_page *)CN_LOAD(__hyp_vmemmap))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&page), sizeof(struct hyp_page*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("/*     struct hyp_page *p = hyp_virt_to_page(addr); */\n    ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:260:5-28");
  cn_pointer* O___hyp_vmemmap1_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_base; \n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:264:10-53");
  cn_assert(cn_bits_u64_equality(return_cn, cn_bits_u64_divide(offs_cn, convert_to_cn_bits_u64(sizeof(struct hyp_page)))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires let hyp_vmemmap = __hyp_vmemmap; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:265:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap1_cn, O___hyp_vmemmap0_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/* static inline int hyp_page_count(void *addr) */
/* { */
/*     struct hyp_page *p = hyp_virt_to_page(addr); */
/*     return p->refcount; */
/* } */
static inline int hyp_page_count(struct hyp_pool *pool, void *addr)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_base; 
 requires let hyp_vmemmap = __hyp_vmemmap; 
  let phys = cn__hyp_pa(hyp_physvirt_offset, addr); 
  take H = Hyp_pool(pool, hyp_vmemmap, cn_virt_base, hyp_physvirt_offset); 
  H.pool.range_start <= phys; phys < H.pool.range_end; 
 ensures take H2 = Hyp_pool(pool, hyp_vmemmap, cn_virt_base, hyp_physvirt_offset); 
  {hyp_physvirt_offset} unchanged; {hyp_vmemmap} unchanged; 
  H2.pool == {H.pool}@start; 
  (u16) return == ((H2.vmemmap)[phys / (page_size())]).refcount; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_bits_i64* O_hyp_physvirt_offset4_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_pointer* O___hyp_vmemmap2_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_pointer* O_cn_virt_base2_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_base()), PRE, 0);
  cn_pop_msg_info();
  cn_pointer* hyp_vmemmap_cn;
  hyp_vmemmap_cn = O___hyp_vmemmap2_cn;
  cn_bits_u64* phys_cn;
  phys_cn = cn__hyp_pa(O_hyp_physvirt_offset4_cn, addr_cn);
  update_cn_error_message_info("    /* TODO originally: return p->refcount.  Introducing 'ret' here, so we can pack resources before returning; */\n       ^./driver.pp.c:278:8:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, hyp_vmemmap_cn, O_cn_virt_base2_cn, O_hyp_physvirt_offset4_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    int ret = p->refcount;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:279:3-30");
  cn_assert(cn_bits_u64_le(H_cn->pool->range_start, phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    int ret = p->refcount;\n                              ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:279:31-55");
  cn_assert(cn_bits_u64_lt(phys_cn, H_cn->pool->range_end), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&addr), sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
    struct hyp_page *p = (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[((((phys_addr_t)CN_LOAD((addr)) + CN_LOAD(hyp_physvirt_offset))) >> 12)]);
c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

    /*CN*/update_cn_error_message_info("  {(*p).order} unchanged; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:286:14-86");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("  (*p).refcount == {(*p).refcount}@start + 1u16; @*/\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:287:14-76");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("{\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:288:14-67");

update_cn_error_message_info("{\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:288:14-65");

cn_pop_msg_info();

cn_pop_msg_info();

    /* TODO originally: return p->refcount.  Introducing 'ret' here, so we can pack resources before returning; */
    int ret = CN_LOAD(CN_LOAD(p)->refcount);
c_add_to_ghost_state((&ret), sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&ret), sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&ret), sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&addr), sizeof(void*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_bits_i64* O_hyp_physvirt_offset5_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_pointer* O___hyp_vmemmap3_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:275:5-63");
  cn_pointer* O_cn_virt_base3_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_base()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        return ret;\n              ^./driver.pp.c:280:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, hyp_vmemmap_cn, O_cn_virt_base3_cn, O_hyp_physvirt_offset5_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:281:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset5_cn, O_hyp_physvirt_offset4_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:281:36-60");
  cn_assert(cn_pointer_equality(hyp_vmemmap_cn, hyp_vmemmap_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void hyp_page_ref_inc(struct hyp_page *p)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:282:3-29");
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, H_cn->pool), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ requires take O = Owned(p); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:283:3-65");
  cn_assert(cn_bits_u16_equality(cast_cn_bits_i32_to_cn_bits_u16(return_cn), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H2_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(cn_bits_u64_divide(phys_cn, page_size()))))->refcount), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static inline void hyp_page_ref_inc(struct hyp_page *p)
/*@ requires take O = Owned(p); 
  (*p).refcount < (shift_left(1u16,16u16) - 1u16); 
 ensures take OR = Owned(p); 
  {(*p).order} unchanged; 
  (*p).refcount == {(*p).refcount}@start + 1u16; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  (*p).refcount > 0u16; \n                  ^./driver.pp.c:294:19:");
  struct hyp_page_cn* O_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take OR = Owned(p); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:295:3-51");
  cn_assert(cn_bits_u16_lt(O_cn->refcount, cn_bits_u16_sub(cn_bits_u16_shift_left(convert_to_cn_bits_u16(1ULL), convert_to_cn_bits_u16(16ULL)), convert_to_cn_bits_u16(1ULL))), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    ((void) 0);
    CN_POSTFIX(CN_LOAD(p)->refcount, ++);

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  {(*p).order} unchanged; \n              ^./driver.pp.c:296:15:");
  struct hyp_page_cn* OR_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (*p).refcount == {(*p).refcount}@start - 1u16; @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:297:3-26");
  cn_assert(cn_bits_u8_equality(OR_cn->order, O_cn->order), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:298:3-49");
  cn_assert(cn_bits_u16_equality(OR_cn->refcount, cn_bits_u16_add(O_cn->refcount, convert_to_cn_bits_u16(1ULL))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void hyp_page_ref_dec(struct hyp_page *p)
/*@ requires take O = Owned(p); 
  (*p).refcount > 0u16; 
 ensures take OR = Owned(p); 
  {(*p).order} unchanged; 
  (*p).refcount == {(*p).refcount}@start - 1u16; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  (*p).refcount > 0u16; \n                  ^./driver.pp.c:304:19:");
  struct hyp_page_cn* O_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take OR = Owned(p); \n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:305:3-24");
  cn_assert(cn_bits_u16_lt(convert_to_cn_bits_u16(0ULL), O_cn->refcount), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    ((void) 0);
    CN_POSTFIX(CN_LOAD(p)->refcount, --);

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  {(*p).order} unchanged; \n              ^./driver.pp.c:306:15:");
  struct hyp_page_cn* OR_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (*p).refcount == {(*p).refcount}@start - 1u16; \n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:307:3-26");
  cn_assert(cn_bits_u8_equality(OR_cn->order, O_cn->order), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  return == (((*p).refcount == 0u16) ? 1i32 : 0i32); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:308:3-49");
  cn_assert(cn_bits_u16_equality(OR_cn->refcount, cn_bits_u16_sub(O_cn->refcount, convert_to_cn_bits_u16(1ULL))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline int hyp_page_ref_dec_and_test(struct hyp_page *p)
/*@ requires take O = Owned(p); 
  (*p).refcount > 0u16; 
 ensures take OR = Owned(p); 
  {(*p).order} unchanged; 
  (*p).refcount == {(*p).refcount}@start - 1u16; 
  return == (((*p).refcount == 0u16) ? 1i32 : 0i32); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("/*@ requires take O = Owned(p); \n                  ^./driver.pp.c:314:19:");
  struct hyp_page_cn* O_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (*p).refcount == 0u16; \n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:315:3-24");
  cn_assert(cn_bits_u16_lt(convert_to_cn_bits_u16(0ULL), O_cn->refcount), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    (
({
  ghost_call_site = EMPTY;
  0;
})
, hyp_page_ref_dec(CN_LOAD(p)));
    { __cn_ret = (CN_LOAD(CN_LOAD(p)->refcount) == 0); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info(" ensures take OR = Owned(p); \n              ^./driver.pp.c:316:15:");
  struct hyp_page_cn* OR_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {(*p).order} unchanged; \n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:317:3-26");
  cn_assert(cn_bits_u8_equality(OR_cn->order, O_cn->order), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  (*p).refcount == 1u16; @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:318:3-49");
  cn_assert(cn_bits_u16_equality(OR_cn->refcount, cn_bits_u16_sub(O_cn->refcount, convert_to_cn_bits_u16(1ULL))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:319:3-53");
  cn_bits_i32* a_6469;
  if (convert_from_cn_bool(cn_bits_u16_equality(OR_cn->refcount, convert_to_cn_bits_u16(0ULL)))) {
    a_6469 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_6469 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_6469), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static inline void hyp_set_page_refcounted(struct hyp_page *p)
/*@ requires take O = Owned(p); 
  (*p).refcount == 0u16; 
 ensures take OR = Owned(p); 
  {(*p).order} unchanged; 
  (*p).refcount == 1u16; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("/* #include <linux/list.h> */\n                  ^./driver.pp.c:325:19:");
  struct hyp_page_cn* O_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/* #include <nvhe/memory.h> */\n  ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:326:3-25");
  cn_assert(cn_bits_u16_equality(O_cn->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    ((void) 0);
    CN_STORE(CN_LOAD(p)->refcount, 1);

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("/* #include <nvhe/spinlock.h> */\n              ^./driver.pp.c:327:15:");
  struct hyp_page_cn* OR_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("struct hyp_pool {\n  ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:328:3-26");
  cn_assert(cn_bits_u8_equality(OR_cn->order, O_cn->order), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*\n  ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:329:3-25");
  cn_assert(cn_bits_u16_equality(OR_cn->refcount, convert_to_cn_bits_u16(1ULL)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
/* originally: ./arch/arm64/kvm/hyp/include/nvhe/gfp.h */
/* SPDX-License-Identifier: GPL-2.0-only */
/* #include <linux/list.h> */
/* #include <nvhe/memory.h> */
/* #include <nvhe/spinlock.h> */
struct hyp_pool;
/* Allocation */
void *hyp_alloc_pages(struct hyp_pool *pool, u8 order);
// void hyp_split_page(struct hyp_page *page);
void hyp_get_page(struct hyp_pool *pool, void *addr);
void hyp_put_page(struct hyp_pool *pool, void *addr);
/* Used pages cannot be freed */
int hyp_pool_init(struct hyp_pool *pool, u64 pfn, unsigned int nr_pages,
          unsigned int reserved_pages);
// // INLINE_FUNCPTR
// extern struct hyp_pool host_s2_pool;
// struct kvm_mem_range {
//     u64 start;
//     u64 end;
// };
// struct memblock_region *find_mem_range(phys_addr_t addr, struct kvm_mem_range *range);
// bool is_in_mem_range(u64 addr, struct kvm_mem_range *range);
// bool range_is_memory(u64 start, u64 end);
//
// void *host_s2_zalloc_pages_exact(size_t size);
//
// #define _UL(x)        (_AC(x, UL))
// #define BIT(nr)            (_UL(1) << (nr))
// /* from kvm_pgtable.h */
// /**
//  * enum kvm_pgtable_prot - Page-table permissions and attributes.
//  * @KVM_PGTABLE_PROT_X:        Execute permission.
//  * @KVM_PGTABLE_PROT_W:        Write permission.
//  * @KVM_PGTABLE_PROT_R:        Read permission.
//  * @KVM_PGTABLE_PROT_DEVICE:    Device attributes.
//  * @KVM_PGTABLE_PROT_SW0:    Software bit 0.
//  * @KVM_PGTABLE_PROT_SW1:    Software bit 1.
//  * @KVM_PGTABLE_PROT_SW2:    Software bit 2.
//  * @KVM_PGTABLE_PROT_SW3:    Software bit 3.
//  */
// enum kvm_pgtable_prot {
//     KVM_PGTABLE_PROT_X            = BIT(0),
//     KVM_PGTABLE_PROT_W            = BIT(1),
//     KVM_PGTABLE_PROT_R            = BIT(2),
//
//     KVM_PGTABLE_PROT_DEVICE            = BIT(3),
//
//     KVM_PGTABLE_PROT_SW0            = BIT(55),
//     KVM_PGTABLE_PROT_SW1            = BIT(56),
//     KVM_PGTABLE_PROT_SW2            = BIT(57),
//     KVM_PGTABLE_PROT_SW3            = BIT(58),
// };
//
// bool host_stage2_force_pte_cb(u64 addr, u64 end, enum kvm_pgtable_prot prot);
// void host_s2_put_page(void *addr);
// void *host_s2_zalloc_page(void *pool);
// void host_s2_get_page(void *addr);
// // /INLINE_FUNCPTR
/*@
function (pointer) copy_alloc_id_cn(u64 x, pointer p) {
    array_shift<char>(p, x - (u64) p)
}

function (u64) page_size () { 4096u64 }
function (u8) max_order () { 11u8 }
function (u8) hyp_no_order () { 255u8 }

function (u64) cn_hyp_page_to_pfn(pointer hypvmemmap, pointer p) {
  ((u64) p - (u64) hypvmemmap) / (u64) (sizeof<struct hyp_page>)
}

// copied and adjusted from the corresponding macro definition in memory.h 
function (u64) cn__hyp_pa(i64 physvirtoffset, pointer virt) {
  (u64) ((i64) virt + physvirtoffset)
}



// copied and adjusted from the corresponding macro definition in memory.h 
function (u64) cn_hyp_phys_to_pfn(u64 phys) {
  phys / page_size()
}

// copied and adjusted from the corresponding macro definition in memory.h 
function (u64) cn_hyp_virt_to_pfn (i64 physvirtoffset, pointer virt) {
  cn_hyp_phys_to_pfn(cn__hyp_pa(physvirtoffset, virt))
}


function (u64) cn_hyp_pfn_to_phys(u64 pfn) {
  pfn*page_size()
}

// copied and adjusted from the corresponding macro definition in memory.h 
function (u64) cn_hyp_page_to_phys(pointer hypvmemmap, pointer page) {
  cn_hyp_pfn_to_phys((cn_hyp_page_to_pfn(hypvmemmap, page)))
}

// copied and adjusted from the corresponding macro definition in memory.h 
function (pointer) cn__hyp_va(pointer virt_ptr, i64 physvirtoffset, u64 phys) {
  copy_alloc_id_cn((u64) ((i64) phys - physvirtoffset), virt_ptr)
}

// copied and adjusted from the corresponding macro definition in memory.h 
function (pointer) cn_hyp_page_to_virt(pointer virt_ptr, i64 physvirtoffset,
                                       pointer hypvmemmap, pointer page) {
  cn__hyp_va(virt_ptr, physvirtoffset, cn_hyp_page_to_phys(hypvmemmap, page))
}

function (u64) calc_buddy(u64 addr, u8 order) {
       xor_uf(addr, shift_left(page_size(), (u64) order))
}

function (u64) pfn_buddy (u64 x, u8 order) {
  cn_hyp_phys_to_pfn (calc_buddy(cn_hyp_pfn_to_phys(x), order))
}

// taking the definition from Buddy_Aligned.v
function (boolean) order_aligned (u64 x, u8 order) {
  mod(x, shift_left (1u64, (u64) order)) == 0u64
}

// taking the definition from Buddy_Aligned.v
function (u64) order_align (u64 x, u8 order) {
  x - mod(x, shift_left (1u64, (u64) order))
}

function (boolean) cellPointer(pointer base, u64 size, u64 starti, u64 endi, pointer p) {
   let offset = (u64) base - (u64) p;
   let start = array_shift<char>(base, size * starti);
   let end = array_shift<char>(base, size * endi);
   start <= p && p < end && mod(offset, size) == 0u64
}

// taking the definition from Pages_Aligned.v
function (u64) page_size_of_order (u8 order) {
  shift_left(1u64, (u64) order + 12u64)
}

// taking the definition from Pages_Aligned.v
function (boolean) page_aligned (u64 ptr, u8 order) {
  mod(ptr, page_size_of_order(order)) == 0u64
}






type_synonym excludes = {boolean any, boolean do_ex1, u64 ex1, boolean do_ex2, u64 ex2}

function (boolean) excluded (excludes ex, u64 i)
{
  ex.any && (
      (ex.do_ex1 && (i == ex.ex1))
      || (ex.do_ex2 && (i == ex.ex2))
  )
}

function (excludes) exclude_none ()
{
  {any: false, do_ex1: false, ex1: 0u64, do_ex2: false, ex2: 0u64}
}

function (excludes) exclude_one (u64 ex1)
{
  {any: true, do_ex1: true, ex1: ex1, do_ex2: false, ex2: 0u64}
}

function (excludes) exclude_two (u64 ex1, u64 ex2)
{
  {any: true, do_ex1: true, ex1: ex1, do_ex2: true, ex2: ex2}
}


// Check a pointer (to the struct list_head embedded in a free page) is a valid
// pointer, which includes knowing that its matching vmemmap entry has the
// refcount/order settings that indicate that the struct is present. 
function (boolean) vmemmap_good_pointer (i64 physvirt_offset, pointer p,
        map <u64, struct hyp_page> vmemmap,
        u64 range_start, u64 range_end, excludes ex)
{
  let pa = cn__hyp_pa(physvirt_offset, p);
  let pfn = cn_hyp_phys_to_pfn(pa);
    (mod(pa, page_size ()) == 0u64)
    && (range_start <= pa)
    && (pa < range_end)
    && (vmemmap[pfn].refcount == 0u16)
    && (vmemmap[pfn].order != (hyp_no_order ()))
    && (not (excluded (ex, pfn)))
}


function (boolean) page_group_ok (u64 page_index,
        map <u64, struct hyp_page> vmemmap, struct hyp_pool pool)
{
  let page = vmemmap[page_index];
  let start_i = (pool.range_start) / (page_size ());
  ((page.order == hyp_no_order())
    || (each (u8 i: 1, 10; (not (
        (order_align(page_index, i) < page_index)
        && (start_i <= order_align(page_index, i))
        && (i <= (vmemmap[(order_align(page_index, i))]).order)
        && ((vmemmap[(order_align(page_index, i))]).order != hyp_no_order())
    )))))
}

// There are no `AllocatorPage`s outputs to pass as arguments in `hyp_pool_init`
// Also a different invariant handles checking prev/next
function (boolean) init_vmemmap_page (u64 page_index,
        map <u64, struct hyp_page> vmemmap,
        pointer pool_pointer, struct hyp_pool pool)
{
  let page = vmemmap[page_index];
    (page.order == 0u8)
    && (page.refcount == 1u16)
    && (order_aligned(page_index, 0u8))
    && (((page_index * (page_size ())) + page_size_of_order(page.order)) <= pool.range_end)
}

function (boolean) vmemmap_normal_order_wf (u64 page_index, struct hyp_page page, struct hyp_pool pool) {
    (0u8 <= page.order && ((page.order < pool.max_order) && (page.order < max_order())))
    && order_aligned(page_index, page.order)
    && (((page_index * (page_size ())) + page_size_of_order(page.order)) <= pool.range_end)
}


function (boolean) vmemmap_wf (u64 page_index,
        map <u64, struct hyp_page> vmemmap, pointer pool_pointer, struct hyp_pool pool)
{
  let page = vmemmap[page_index];
    ((page.order == (hyp_no_order ())) || vmemmap_normal_order_wf(page_index, page, pool))
    && ((page.order != hyp_no_order()) || (page.refcount == 0u16))
    && (page_group_ok(page_index, vmemmap, pool))
}

function (boolean) vmemmap_l_wf (u64 page_index, i64 physvirt_offset,
        pointer virt_ptr,
        map <u64, struct hyp_page> vmemmap, map <u64, struct list_head> APs,
        pointer pool_pointer, struct hyp_pool pool, excludes ex)
{
  let page = vmemmap[page_index];
  let self_node_pointer = cn__hyp_va(virt_ptr, physvirt_offset, cn_hyp_pfn_to_phys(page_index));
  let pool_free_area_arr_pointer = member_shift<struct hyp_pool>(pool_pointer, free_area);
  let pool_free_area_pointer = array_shift<struct list_head>(pool_free_area_arr_pointer, page.order);
  let prev = (APs[page_index]).prev;
  let next = (APs[page_index]).next;
  let free_area_entry = pool.free_area[(u64) page.order];
  let prev_page_pointer = prev;
  let prev_page_index = cn_hyp_virt_to_pfn(physvirt_offset, prev_page_pointer);
  let prev_page = vmemmap[prev_page_index];
  let next_page_pointer = next;
  let next_page_index = cn_hyp_virt_to_pfn(physvirt_offset, next_page_pointer);
  let next_page = vmemmap[next_page_index];
  let prov = (alloc_id) virt_ptr;
  let prev_clause =
    ((prev == pool_free_area_pointer) && (free_area_entry.next == self_node_pointer))
    || (vmemmap_good_pointer (physvirt_offset, prev_page_pointer, vmemmap, pool.range_start, pool.range_end, ex)
        && (prov == (alloc_id) prev)
        && ((APs[prev_page_index]).next == self_node_pointer)
        && (prev_page.order == page.order)
        && (prev_page.refcount == 0u16));
  let next_clause =
    ((next == pool_free_area_pointer) && (free_area_entry.prev == self_node_pointer))
    || (vmemmap_good_pointer (physvirt_offset, next_page_pointer, vmemmap, pool.range_start, pool.range_end, ex)
        && (prov == (alloc_id) next)
        && ((APs[next_page_index]).prev == self_node_pointer)
        && (next_page.order == page.order)
        && (next_page.refcount == 0u16));
  // there is no self-loop case for this node type, as it is cleared unless it is
  // present in the per-order free list - TODO delete?
  let nonempty_clause = (prev != self_node_pointer) && (next != self_node_pointer);
  (prev_clause && next_clause)
}



function (boolean) freeArea_cell_wf (u8 cell_index, i64 physvirt_offset,
        pointer virt_ptr,
        map <u64, struct hyp_page> vmemmap, map <u64, struct list_head> APs,
        pointer pool_pointer, struct hyp_pool pool, excludes ex)
{
  let cell = pool.free_area[(u64) cell_index];
  let pool_free_area_arr_pointer = member_shift<struct hyp_pool>(pool_pointer, free_area);
  let cell_pointer = array_shift<struct list_head>(pool_free_area_arr_pointer, cell_index);
  let prev = cell.prev;
  let next = cell.next;
  let prev_page_pointer = prev;
  let prev_page_index = cn_hyp_virt_to_pfn(physvirt_offset, prev_page_pointer);
  let prev_page = vmemmap[prev_page_index];
  let next_page_pointer = next;
  let next_page_index = cn_hyp_virt_to_pfn(physvirt_offset, next_page_pointer);
  let next_page = vmemmap[next_page_index];
    ((prev == cell_pointer) == (next == cell_pointer))
    && ((prev == cell_pointer) || (
        ((alloc_id) prev == (alloc_id) virt_ptr)
        && (vmemmap_good_pointer (physvirt_offset, prev_page_pointer, vmemmap, pool.range_start, pool.range_end, ex))
        && (prev_page.order == cell_index)
        && (prev_page.refcount == 0u16)
        && ((APs[prev_page_index]).next == cell_pointer)
        && ((alloc_id) next == (alloc_id) virt_ptr)
        && (ptr_eq(next, cell_pointer) || !addr_eq(next, cell_pointer))
        && (vmemmap_good_pointer (physvirt_offset, next_page_pointer, vmemmap, pool.range_start, pool.range_end, ex))
        && (next_page.order == cell_index)
        && (next_page.refcount == 0u16)
        && ((APs[next_page_index]).prev == cell_pointer)
    ))
}

function (boolean) hyp_pool_wf (pointer pool_pointer, struct hyp_pool pool,
        pointer vmemmap_pointer, i64 physvirt_offset)
{
  let range_start = pool.range_start;
  let range_end = pool.range_end;
  let start_i = range_start / page_size ();
  let end_i = range_end / page_size ();
  let hp_sz = sizeof <struct hyp_page>;
  let pool_sz = sizeof <struct hyp_pool>;
  let vmemmap_start_pointer = array_shift<struct hyp_page>(vmemmap_pointer,  start_i);
  let vmemmap_boundary_pointer = array_shift<struct hyp_page>(vmemmap_pointer, end_i);
  let range_start_virt = (u64) (((i64) range_start) - physvirt_offset);
  let range_end_virt = (u64) (((i64) range_end) - physvirt_offset);
    (range_start < range_end)
    && (range_end < shift_left(1u64, 52u64))
    && (physvirt_offset < (i64) range_start) // use '<='
    && (mod((u64) physvirt_offset, (page_size ())) == 0u64)
    && (((range_start / (page_size ())) * (page_size ())) == range_start)
    && (((range_end / (page_size ())) * (page_size ())) == range_end)
    && (pool.max_order <= (max_order ()))
    && (mod(((u64) vmemmap_pointer), hp_sz) == 0u64)
    && (((((u64) pool_pointer) + pool_sz) <= ((u64) vmemmap_start_pointer))
        || (((u64) vmemmap_boundary_pointer) <= ((u64) pool_pointer)))
    && (((((u64) pool_pointer) + pool_sz) <= range_start_virt)
        || (range_end_virt <= ((u64) pool_pointer)))
}

function (u8) get_order_uf (u64 size) {
  (u8) bw_fls_uf(shift_right(size - 1u64, 12u64))
}

function (pointer) virt (pointer phys, i64 physvirt_offset) {
  array_shift<char>(phys, (0i64 - physvirt_offset))
}


predicate void Byte (pointer virt)
{
  take B = Block<char>(virt);
  return;
}

predicate void ByteV (pointer virt, u8 the_value)
{
  take B = Owned<char>(virt);
  assert (B == the_value);
  return;
}

predicate void Page (pointer vbase, boolean guard, u8 order)
{
  if (!guard) {
    return;
  }
  else {
    let length = page_size_of_order(order);
    let vbaseI = (u64) vbase;
    take Bytes = each (u64 i; (vbaseI <= i) && (i < (vbaseI + length)))
         {Byte(array_shift<char>(NULL, i))};
    return;
  }
}

predicate void ZeroPage (pointer vbase, boolean guard, u8 order)
{
  if (!guard) {
    return;
  }
  else {
    let length = page_size_of_order(order);
    let vbaseI = ((u64) vbase);
    take Bytes = each (u64 i; (vbaseI <= i) && (i < (vbaseI + length)))
         {ByteV(array_shift<char>(NULL, i), 0u8)};
    return;
  }
}

predicate void AllocatorPageZeroPart (pointer zero_start, u8 order)
{
  let start = (u64) zero_start;
  let region_length = page_size_of_order(order);
  let length = region_length - sizeof<struct list_head>;
  take Bytes = each (u64 i; (start <= i) && (i < (start + length)))
       {ByteV(array_shift<char>(NULL, i), 0u8)};
  return;
}

function (struct list_head) todo_default_list_head () {
  struct list_head { prev : NULL, next : NULL }
}

predicate struct list_head AllocatorPage
    (pointer vbase, boolean guard, u8 order)
{
  if (!guard) {
    return (todo_default_list_head ());
  }
  else {
    let zero_start = array_shift<struct list_head>(vbase, 1u8);
    take ZeroPart = AllocatorPageZeroPart (zero_start, order);
    take Node = Owned<struct list_head>(vbase);
    return Node;
  }
}


predicate {
    struct hyp_pool pool
    , map <u64, struct hyp_page> vmemmap
    , map <u64, struct list_head> APs
}
Hyp_pool_ex1 (
    pointer pool_l
    , pointer vmemmap_l
    , pointer virt_ptr
    , i64 physvirt_offset
    , u64 ex1
)
{
  let ex = exclude_one (ex1);
  take pool = Owned<struct hyp_pool>(pool_l);
  let start_i = pool.range_start / page_size();
  let end_i = pool.range_end / page_size();
  assert (hyp_pool_wf (pool_l, pool, vmemmap_l, physvirt_offset));
  take V = each(u64 i; (start_i <= i) && (i < end_i))
               {Owned(array_shift<struct hyp_page>(vmemmap_l, i))};
  let ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, 0u64);
  take APs = each(u64 i; (start_i <= i) && (i < end_i)
                  && ((V[i]).refcount == 0u16)
                  && ((V[i]).order != (hyp_no_order ()))
                  && ((not (excluded (ex, i)))))
                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};
  assert (each (u64 i; (start_i <= i) && (i < end_i))
    {vmemmap_wf (i, V, pool_l, pool)});
  assert (each (u64 i; (start_i <= i) && (i < end_i)
            && ((V[i]).refcount == 0u16)
            && ((V[i]).order != (hyp_no_order ()))
            && ((not (excluded (ex, i)))))
    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});
  assert (each(u8 i; 0u8 <= i && i < pool.max_order)
              {freeArea_cell_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});
  return {pool: pool, vmemmap: V, APs: APs};
}

predicate {
    struct hyp_pool pool
    , map <u64, struct hyp_page> vmemmap
    , map <u64, struct list_head> APs
}
Hyp_pool_ex2 (
    pointer pool_l
    , pointer vmemmap_l
    , pointer virt_ptr
    , i64 physvirt_offset
    , u64 ex1
    , u64 ex2
)
{
  let ex = exclude_two (ex1, ex2);
  take pool = Owned<struct hyp_pool>(pool_l);
  let start_i = pool.range_start / page_size();
  let end_i = pool.range_end / page_size();
  assert (hyp_pool_wf (pool_l, pool, vmemmap_l, physvirt_offset));
  take V = each(u64 i; (start_i <= i) && (i < end_i))
              {Owned(array_shift<struct hyp_page>(vmemmap_l,  i))};
  let ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, 0u64);
  take APs = each(u64 i; (start_i <= i) && (i < end_i)
                  && ((V[i]).refcount == 0u16)
                  && ((V[i]).order != (hyp_no_order ()))
                  && ((not (excluded (ex, i)))))
                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};
  assert (each (u64 i; (start_i <= i) && (i < end_i))
    {vmemmap_wf (i, V, pool_l, pool)});
  assert (each (u64 i; (start_i <= i) && (i < end_i)
            && ((V[i]).refcount == 0u16)
            && ((V[i]).order != (hyp_no_order ()))
            && ((not (excluded (ex, i)))))
    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});
  assert (each(u8 i; 0u8 <= i && i < pool.max_order)
              {freeArea_cell_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});
  return {pool: pool, vmemmap: V, APs: APs};
}

predicate {
    struct hyp_pool pool
    , map <u64, struct hyp_page> vmemmap
    , map <u64, struct list_head> APs
}
Hyp_pool (
    pointer pool_l
    , pointer vmemmap_l
    , pointer virt_ptr
    , i64 physvirt_offset
)
{
  let ex = exclude_none ();
  take P = Owned<struct hyp_pool>(pool_l);
  let start_i = P.range_start / page_size();
  let end_i = P.range_end / page_size();
  take V = each(u64 i; (start_i <= i) && (i < end_i))
              {Owned(array_shift<struct hyp_page>(vmemmap_l, i))};
  assert (hyp_pool_wf (pool_l, P, vmemmap_l, physvirt_offset));
  let ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, 0u64);
  take APs = each(u64 i; (start_i <= i) && (i < end_i)
                  && ((V[i]).refcount == 0u16)
                  && ((V[i]).order != (hyp_no_order ()))
                  && ((not (excluded (ex, i)))))
                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};
  assert (each (u64 i; (start_i <= i) && (i < end_i))
    {vmemmap_wf (i, V, pool_l, P)});
  assert (each (u64 i; (start_i <= i) && (i < end_i)
            && ((V[i]).refcount == 0u16)
            && ((V[i]).order != (hyp_no_order ()))
            && ((not (excluded (ex, i)))))
    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, P, ex)});
  assert (each(u8 i; 0u8 <= i && i < P.max_order)
              {freeArea_cell_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, P, ex)});
  return {pool: P, vmemmap: V, APs: APs};
}




predicate (struct list_head) O_struct_list_head(pointer p, boolean condition) 
{
  if (condition) {
    take v = Owned<struct list_head>(p);
    return v;
  }
  else {
    return todo_default_list_head ();
  }
}
@*/
// define intptr_t a hacky way, for lemmas 
// /*CN*/ typedef u64 intptr_t;
/*@
lemma order_dec_inv (u64 pool_range_end, // phys_addr_t
                     u64 pfn, // u64
                     u8 order1, // unsigned int
                     u8 order2) // unsigned int
  requires order_aligned(pfn, order1);
           (pfn*page_size()) + (page_size_of_order(order1)) <= pool_range_end;
           order2 <= order1;
  ensures order_aligned(pfn, order2);
          (pfn * page_size()) + (page_size_of_order(order2)) <= pool_range_end;



lemma lemma2 (u64 p_i, // intptr_t
              u8 order) // unsigned int
  requires let p_phys = p_i * page_size();
           let buddy_i = pfn_buddy(p_i, order);
           let buddy_phys = buddy_i * page_size();
           order_aligned(p_i, order);
           order_aligned(buddy_i, order);
           p_i <= max_pfn ();
  ensures let min_i = (p_i < buddy_i) ? p_i : buddy_i;
          let min_i_phys = min_i * page_size();
          buddy_i <= max_pfn ();
          order_aligned(min_i, order+1u8);
          page_aligned(min_i_phys, order+1u8);
          (p_phys + (page_size_of_order(order)) == buddy_phys) || (p_phys - (page_size_of_order(order)) == buddy_phys);


lemma extract_l (u64 p_i, // intptr_t
                 u8 order) // unsigned int
 requires let p_phys = p_i * page_size() ;
          let buddy_i = pfn_buddy(p_i, order) ;
          let buddy_phys = buddy_i * page_size() ;
          order_aligned(p_i, order + 1u8) ;
          p_i <= max_pfn ();
 ensures p_phys + (page_size_of_order(order)) == buddy_phys ;
         page_aligned(p_phys, order) ;
         page_aligned(buddy_phys, order);


lemma page_size_of_order_inc (u8 order) // unsigned int
  requires true;
  ensures (page_size_of_order(order+1u8)) == 2u64*(page_size_of_order(order));


lemma lemma4 (u64 p_i, // intptr_t
              u8 order) // unsigned int
  requires order >= 1u8 ;
           let p_phys = p_i * page_size() ;
           order_aligned(p_i, order) ;
           p_i <= max_pfn ();
  ensures let buddy_i = pfn_buddy(p_i, order - 1u8) ;
          buddy_i <= max_pfn () ;
          let buddy_phys = buddy_i * page_size() ;
          !(order_aligned(buddy_i, order)) ;
          buddy_phys == p_phys + (page_size_of_order(order - 1u8)) ;
          0u64 < (page_size_of_order(order)) ;
          0u64 < (page_size_of_order(order - 1u8)) ;
          (page_size_of_order(order - 1u8)) * 2u64 == (page_size_of_order(order)) ;
          (page_size_of_order(order - 1u8)) <= (page_size_of_order(order)) ;
          (order_align(buddy_i, order)) == p_i;




lemma order_align_inv_loop (pointer __hypvmemmap,
                            map<u64, struct hyp_page> V,
                            struct hyp_pool pool,
                            pointer p) // struct hyp_page* 
 requires let hypvmemmap = __hypvmemmap ;
          let p_i = ((u64) p - (u64) __hypvmemmap) / 4u64 ;
          let start_i = (pool).range_start / page_size() ;
          let end_i = (pool).range_end / page_size() ;
          let p_order = (V[p_i]).order ;
          p_order >= 1u8; p_order < 11u8 ;
          order_aligned(p_i, p_order) ;
          cellPointer(hypvmemmap, 4u64, start_i, end_i, p) ;
          let buddy_i = pfn_buddy(p_i, p_order - 1u8) ;
          each(u64 i; start_i <= i && i < end_i) { page_group_ok(i, V, pool) };
 ensures buddy_i <= max_pfn () ;
         let p_new_page = {order: (p_order - 1u8), ..V[p_i]} ;
         let buddy_new_page = {order: (p_order - 1u8), ..V[buddy_i]} ;
         each(u64 i; start_i <= i && i < end_i) { page_group_ok(i, V[p_i: p_new_page, buddy_i: buddy_new_page], pool) };



lemma page_group_ok_easy (pointer __hypvmemmap, struct hyp_pool pool)
  requires let hypvmemmap = __hypvmemmap ;
           let start_i = (pool).range_start / page_size() ;
           let end_i = (pool).range_end / page_size() ;
           take V = each (u64 i; start_i <= i && i < end_i) { Owned(array_shift<struct hyp_page>(hypvmemmap, i)) } ;
           each (u64 i; start_i <= i && i < end_i) { (V[i]).order == 0u8 };
  ensures take V2 = each (u64 i; start_i <= i && i < end_i) { Owned(array_shift<struct hyp_page>(hypvmemmap, i)) } ;
          V2 == V ;
          each(u64 i; start_i <= i && i < end_i) { page_group_ok(i, V2, pool) };


lemma order_aligned_init (u64 i) // unsigned long
  requires true;
  ensures order_aligned(i, 0u8);

lemma page_size_of_order_lemma ()
  requires true;
  ensures (page_size_of_order(0u8)) == page_size();


lemma attach_inc_loop (map<u64, struct hyp_page> V,
                            pointer __hypvmemmap,
                            struct hyp_pool pool,
                            pointer p, // struct hyp_page*
                            u8 order) // unsigned int
 requires let hypvmemmap = __hypvmemmap ;
          let start_i = (pool).range_start / page_size() ;
          let end_i = (pool).range_end / page_size() ;
          cellPointer(hypvmemmap, 4u64, start_i, end_i, p) ;
          let p_i = ((u64) p - (u64) __hypvmemmap) / 4u64 ;
          let buddy_i = pfn_buddy(p_i, order) ;
          let buddy_order = (V[buddy_i]).order ;
          start_i <= buddy_i; buddy_i < end_i ;
          order + 1u8 < 11u8; buddy_order == order ;
          order_aligned(p_i, order) ;
          order_aligned(buddy_i, order) ;
          (V[p_i]).order == (hyp_no_order ()) ;
          let p_page_tweaked = {order: order, ..V[p_i]} ;
          each(u64 i; start_i <= i && i < end_i) { page_group_ok(i, V[p_i: p_page_tweaked], pool) } ;
          let min_i = (p_i < buddy_i) ? p_i : buddy_i ;
          let min_page = {order: (order + 1u8), ..V[min_i]} ;
          let buddy_page = {order: (hyp_no_order ()), ..V[buddy_i]};
 ensures each(u64 i; start_i <= i && i < end_i) { page_group_ok(i, V[buddy_i: buddy_page,min_i: min_page], pool) };




// TODO: is this (and other) lemma even useful anymore?
lemma find_buddy_xor(u64 addr_i, // intptr_t
                     u8 order) // unsigned int
  requires order_aligned(addr_i, order) ;
           order < 11u8;
  ensures let two_to_order = power_uf(2u64, (u64) order);
          0u64 < two_to_order ;
          two_to_order < shift_left(1u64, 11u64) ;
          let buddy_addr = calc_buddy(addr_i * page_size(), order) ;
          let buddy_i = (buddy_addr / page_size()) ;
          buddy_i == (pfn_buddy (addr_i, order)) ;
          (mod(buddy_addr, page_size())) == 0u64 ;
          order_aligned(buddy_i, order) ;
          addr_i != buddy_i;


lemma page_size_of_order2(u8 order) // unsigned int
  requires order < 11u8;
  ensures 0u64 < power_uf(2u64, (u64) order) ;
          power_uf(2u64, (u64) order) < shift_left(1u64, 11u64) ;
          let size = page_size() * power_uf(2u64, (u64) order) ;
          size == (page_size_of_order(order));


lemma struct_list_head_to_bytes(pointer node) // struct list_head * 
  requires take Node = Owned<struct list_head>(node);
  ensures take B = each (u64 i; ((u64) node) <= i && i < (((u64) node) + (sizeof<struct list_head>))){Byte(array_shift<char>(NULL, i))};


lemma bytes_to_struct_list_head(pointer node, // struct list_head *
                                u8 order)
  requires let length = page_size_of_order(order) ;
           let nodeI = ((u64) node) ;
           take B = each (u64 i; (nodeI <= i) && (i < (nodeI + length))) {ByteV(array_shift<char>(NULL, i), 0u8)};
  ensures take Node = Owned<struct list_head>(node) ;
          take BR = each (u64 i; (nodeI + (sizeof<struct list_head>)) <= i && i < (nodeI + length)){ByteV(array_shift<char>(NULL, i), 0u8)};

@*/
/* NOTE: we give memset a bogus empty body to overcome a limitation of
   the current CN frontend (function declarations without body loose
   the variable name information that we rely on in the
   specifications).) */
void *memset(void *b, int cc, unsigned long len);
/*@ spec memset(pointer b, i32 cc, u64 len);
    requires let b_i = (u64) b;
             let c = (u8) cc;
             take B = each (u64 i; b_i <= i && i < b_i+len){Byte(array_shift<char>(NULL, i))};
    ensures take BR = each (u64 i; b_i <= i && i < b_i+len){ByteV(array_shift<char>(NULL,i), c)}; @*/
struct hyp_page *__hyp_vmemmap;
/*CN*/
void *cn_virt_ptr;
/*
 * Index the hyp_vmemmap to find a potential buddy page, but make no assumption
 * about its current state.
 *
 * Example buddy-tree for a 4-pages physically contiguous pool:
 *
 *                 o : Page 3
 *                /
 *               o-o : Page 2
 *              /
 *             /   o : Page 1
 *            /   /
 *           o---o-o : Page 0
 *    Order  2   1 0
 *
 * Example of requests on this pool:
 *   __find_buddy_nocheck(pool, page 0, order 0) => page 1
 *   __find_buddy_nocheck(pool, page 0, order 1) => page 2
 *   __find_buddy_nocheck(pool, page 1, order 0) => page 0
 *   __find_buddy_nocheck(pool, page 2, order 0) => page 3
 */
static struct hyp_page *__find_buddy_nocheck(struct hyp_pool *pool,
                         struct hyp_page *p,
                         u8 order)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap; 
 requires take O = Owned(pool); 
  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); 
  let start_i = (*pool).range_start / page_size (); 
  let end_i = (*pool).range_end / page_size (); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  order_aligned(p_i, order); 
  order < (*pool).max_order; 
 ensures take OR = Owned(pool); 
  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); 
  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; 
  {*pool} unchanged; 
  let buddy_i = pfn_buddy(p_i, order); 
  let buddy = array_shift<struct hyp_page>(__hyp_vmemmap, buddy_i); 
  let in_range_buddy = buddy_i >= start_i && buddy_i < end_i; 
  let good_buddy = in_range_buddy; 
  return == (good_buddy ? buddy : NULL); 
  is_null(return) ||
  (!addr_eq(return, NULL) && cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, buddy) && order_aligned(buddy_i, order) && p != buddy); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  struct hyp_page* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_bits_u8* order_cn = convert_to_cn_bits_u8(order);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1099:5-49");
  cn_bits_i64* O_hyp_physvirt_offset18_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1099:5-49");
  cn_pointer* O___hyp_vmemmap16_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {*pool} unchanged; \n               ^./driver.pp.c:1100:16:");
  struct hyp_pool_cn* O_cn = owned_struct_hyp_pool(pool_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let buddy_i = pfn_buddy(p_i, order); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1101:3-64");
  cn_assert(hyp_pool_wf(pool_cn, O_cn, O___hyp_vmemmap16_cn, O_hyp_physvirt_offset18_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(O_cn->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(O_cn->range_end, page_size());
  update_cn_error_message_info("  let good_buddy = in_range_buddy; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1104:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap16_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap16_cn, p_cn);
  update_cn_error_message_info("  is_null(return) ||\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1106:3-29");
  cn_assert(order_aligned(p_i_cn, order_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (!addr_eq(return, NULL) && cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, buddy) && order_aligned(buddy_i, order) && p != buddy); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1107:3-29");
  cn_assert(cn_bits_u8_lt(order_cn, O_cn->max_order), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&order), sizeof(unsigned char), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
    phys_addr_t addr = ((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12));
c_add_to_ghost_state((&addr), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));

    /*CN*/
    update_cn_error_message_info("/* Find a buddy page currently available for allocation */\n       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1122:8-76");

cn_pointer* read___hyp_vmemmap15 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));

cn_pointer* read_p14 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

cn_bits_u8* read_order2 = convert_to_cn_bits_u8(cn_pointer_deref(convert_to_cn_pointer((&order)), unsigned char));

update_cn_error_message_info("/* Find a buddy page currently available for allocation */\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1122:9-74");

find_buddy_xor(cn_hyp_page_to_pfn(read___hyp_vmemmap15, read_p14), read_order2);

cn_pop_msg_info();

cn_pop_msg_info();

    CN_STORE_OP(addr,^,(((1UL) << 12) << CN_LOAD(order)));
    update_cn_error_message_info("                       struct hyp_page *p,\n       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1124:8-97");

cn_bits_u64* read_addr0 = convert_to_cn_bits_u64(cn_pointer_deref(convert_to_cn_pointer((&addr)), unsigned long long));

cn_pointer* read___hyp_vmemmap16 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));

cn_pointer* read_p15 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

cn_bits_u8* read_order3 = convert_to_cn_bits_u8(cn_pointer_deref(convert_to_cn_pointer((&order)), unsigned char));

update_cn_error_message_info("                       struct hyp_page *p,\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1124:9-95");

update_cn_error_message_info("                       struct hyp_page *p,\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1124:9-95");

cn_assert(cn_bits_u64_equality(read_addr0, calc_buddy(cn_bits_u64_multiply(cn_hyp_page_to_pfn(read___hyp_vmemmap16, read_p15), page_size()), read_order3)), STATEMENT);

cn_pop_msg_info();

cn_pop_msg_info();

cn_pop_msg_info();

    /*
     * Don't return a page outside the pool range -- it belongs to
     * something else and may not be mapped in hyp_vmemmap.
     */
    if (CN_LOAD(addr) < CN_LOAD(CN_LOAD(pool)->range_start) || CN_LOAD(addr) >= CN_LOAD(CN_LOAD(pool)->range_end))
        { __cn_ret = ((void *)0); 
c_remove_from_ghost_state((&addr), sizeof(unsigned long long));
goto __cn_epilogue; }
    { __cn_ret = (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[(CN_LOAD((addr)) >> 12)]); 
c_remove_from_ghost_state((&addr), sizeof(unsigned long long));
goto __cn_epilogue; }

c_remove_from_ghost_state((&addr), sizeof(unsigned long long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&order), sizeof(unsigned char));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1099:5-49");
  cn_bits_i64* O_hyp_physvirt_offset19_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1099:5-49");
  cn_pointer* O___hyp_vmemmap17_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n              ^./driver.pp.c:1108:15:");
  struct hyp_pool_cn* OR_cn = owned_struct_hyp_pool(pool_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    phys_addr_t addr = ((phys_addr_t)(((hyp_page_to_pfn(p))) << 12));\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1109:3-64");
  cn_assert(hyp_pool_wf(pool_cn, OR_cn, O___hyp_vmemmap17_cn, O_hyp_physvirt_offset19_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1110:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset19_cn, O_hyp_physvirt_offset18_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1110:36-62");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap17_cn, O___hyp_vmemmap16_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ apply find_buddy_xor(cn_hyp_page_to_pfn(__hyp_vmemmap,p), order); @*/\n  ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1111:3-21");
  cn_assert(struct_hyp_pool_cn_equality(OR_cn, O_cn), POST);
  cn_pop_msg_info();
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i_cn, order_cn);
  cn_pointer* buddy_cn;
  buddy_cn = cn_array_shift(O___hyp_vmemmap17_cn, sizeof(struct hyp_page), buddy_i_cn);
  cn_bool* in_range_buddy_cn;
  in_range_buddy_cn = cn_bool_and(cn_bits_u64_le(start_i_cn, buddy_i_cn), cn_bits_u64_lt(buddy_i_cn, end_i_cn));
  cn_bool* good_buddy_cn;
  good_buddy_cn = in_range_buddy_cn;
  update_cn_error_message_info("     * something else and may not be mapped in hyp_vmemmap.\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1116:3-41");
  cn_pointer* a_8923;
  if (convert_from_cn_bool(good_buddy_cn)) {
    a_8923 = buddy_cn;
  }
  else {
    a_8923 = convert_to_cn_pointer(0);
  }
  cn_assert(cn_pointer_equality(return_cn, a_8923), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("     */\n  ^~~~~ ./driver.pp.c:1117:3-1118:161");
  cn_assert(cn_bool_or(is_null(return_cn), cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_not(addr_eq(return_cn, convert_to_cn_pointer(0))), cellPointer(O___hyp_vmemmap17_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, buddy_cn)), order_aligned(buddy_i_cn, order_cn)), cn_bool_not(cn_pointer_equality(p_cn, buddy_cn)))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/* Find a buddy page currently available for allocation */
static struct hyp_page *__find_buddy_avail(struct hyp_pool *pool,
                       struct hyp_page *p,
                       u8 order)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap; 
 requires take O1 = Owned(pool); 
  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); 
  let start_i = (*pool).range_start / page_size(); 
  let end_i = (*pool).range_end / page_size(); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  order_aligned(p_i, order); 
  order < (*pool).max_order; 
  take V = each (u64 i; start_i <= i && i < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, i)) }; 
 ensures take OR = Owned(pool); 
  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); 
  take V2 = each (u64 i; start_i <= i && i < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, i)) }; 
  V2 == V; 
  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; 
  {*pool} unchanged; 
  let buddy_i = pfn_buddy(p_i, order); 
  let same_order = V2[buddy_i].order == order; 
  let zero_refcount = V2[buddy_i].refcount == 0u16; 
  let buddy = array_shift<struct hyp_page>(__hyp_vmemmap, buddy_i); 
  let in_range_buddy = buddy_i >= start_i && buddy_i < end_i; 
  let good_buddy = in_range_buddy && same_order && zero_refcount; 
  return == (good_buddy ? buddy : NULL); 
  is_null(return) || !addr_eq(return, NULL) && (cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, buddy) && order_aligned(buddy_i, order) && p != buddy); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  struct hyp_page* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_bits_u8* order_cn = convert_to_cn_bits_u8(order);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1137:5-49");
  cn_bits_i64* O_hyp_physvirt_offset20_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1137:5-49");
  cn_pointer* O___hyp_vmemmap18_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take V2 = each (u64 i; start_i <= i && i < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, i)) }; \n               ^./driver.pp.c:1138:16:");
  struct hyp_pool_cn* O1_cn = owned_struct_hyp_pool(pool_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  V2 == V; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1139:3-64");
  cn_assert(hyp_pool_wf(pool_cn, O1_cn, O___hyp_vmemmap18_cn, O_hyp_physvirt_offset20_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(O1_cn->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(O1_cn->range_end, page_size());
  update_cn_error_message_info("  let buddy_i = pfn_buddy(p_i, order); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1142:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap18_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap18_cn, p_cn);
  update_cn_error_message_info("  let zero_refcount = V2[buddy_i].refcount == 0u16; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1144:3-29");
  cn_assert(order_aligned(p_i_cn, order_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let buddy = array_shift<struct hyp_page>(__hyp_vmemmap, buddy_i); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1145:3-29");
  cn_assert(cn_bits_u8_lt(order_cn, O1_cn->max_order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let in_range_buddy = buddy_i >= start_i && buddy_i < end_i; \n       ^./driver.pp.c:1146:8:");
  cn_map* V_cn = map_create();
  {
  cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
  while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
    if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
      cn_pointer* a_9056 = cn_array_shift(O___hyp_vmemmap18_cn, sizeof(struct hyp_page), i);
      cn_map_set(V_cn, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_9056, PRE, 0));
    }
    else {
      ;
    }
    cn_bits_u64_increment(i);
  }
}
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&order), sizeof(unsigned char), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
    struct hyp_page *buddy = (
({
  ghost_call_site = EMPTY;
  0;
})
, __find_buddy_nocheck(CN_LOAD(pool), CN_LOAD(p), CN_LOAD(order)));
c_add_to_ghost_state((&buddy), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* buddy_addr_cn = convert_to_cn_pointer((&buddy));

    /*CN*/ update_cn_error_message_info(" * each page when we take it out of the list.\n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1163:15-91");

cn_pop_msg_info();

    /*CN*/ update_cn_error_message_info(" */\n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1164:15-89");

cn_pop_msg_info();

    if (!CN_LOAD(buddy) || CN_LOAD(CN_LOAD(buddy)->order) != CN_LOAD(order) || CN_LOAD(CN_LOAD(buddy)->refcount))
        { __cn_ret = ((void *)0); 
c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));
goto __cn_epilogue; }
    { __cn_ret = CN_LOAD(buddy); 
c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));
goto __cn_epilogue; }

c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&order), sizeof(unsigned char));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1137:5-49");
  cn_bits_i64* O_hyp_physvirt_offset21_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, *pool, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1137:5-49");
  cn_pointer* O___hyp_vmemmap19_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let good_buddy = in_range_buddy && same_order && zero_refcount; \n              ^./driver.pp.c:1147:15:");
  struct hyp_pool_cn* OR_cn = owned_struct_hyp_pool(pool_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  return == (good_buddy ? buddy : NULL); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1148:3-64");
  cn_assert(hyp_pool_wf(pool_cn, OR_cn, O___hyp_vmemmap19_cn, O_hyp_physvirt_offset21_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  is_null(return) || !addr_eq(return, NULL) && (cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, buddy) && order_aligned(buddy_i, order) && p != buddy); @*/\n       ^./driver.pp.c:1149:8:");
  cn_map* V2_cn = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        cn_pointer* a_9160 = cn_array_shift(O___hyp_vmemmap19_cn, sizeof(struct hyp_page), i);
        cn_map_set(V2_cn, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_9160, POST, 0));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~ ./driver.pp.c:1150:3-11");
  cn_assert(cn_map_equality(V2_cn, V_cn, struct_hyp_page_cn_equality), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *buddy = __find_buddy_nocheck(pool, p, order);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1151:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset21_cn, O_hyp_physvirt_offset20_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *buddy = __find_buddy_nocheck(pool, p, order);\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1151:36-62");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap19_cn, O___hyp_vmemmap18_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/ /*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,buddy);@*/\n  ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1152:3-21");
  cn_assert(struct_hyp_pool_cn_equality(OR_cn, O1_cn), POST);
  cn_pop_msg_info();
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i_cn, order_cn);
  cn_bool* same_order_cn;
  same_order_cn = cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V2_cn, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->order, order_cn);
  cn_bool* zero_refcount_cn;
  zero_refcount_cn = cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V2_cn, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL));
  cn_pointer* buddy_cn;
  buddy_cn = cn_array_shift(O___hyp_vmemmap19_cn, sizeof(struct hyp_page), buddy_i_cn);
  cn_bool* in_range_buddy_cn;
  in_range_buddy_cn = cn_bool_and(cn_bits_u64_le(start_i_cn, buddy_i_cn), cn_bits_u64_lt(buddy_i_cn, end_i_cn));
  cn_bool* good_buddy_cn;
  good_buddy_cn = cn_bool_and(cn_bool_and(in_range_buddy_cn, same_order_cn), zero_refcount_cn);
  update_cn_error_message_info(" * Pages that are available for allocation are tracked in free-lists, so we use\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1159:3-41");
  cn_pointer* a_9236;
  if (convert_from_cn_bool(good_buddy_cn)) {
    a_9236 = buddy_cn;
  }
  else {
    a_9236 = convert_to_cn_pointer(0);
  }
  cn_assert(cn_pointer_equality(return_cn, a_9236), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" * the pages themselves to store the list nodes to avoid wasting space. As the\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1160:3-180");
  cn_assert(cn_bool_or(is_null(return_cn), cn_bool_and(cn_bool_not(addr_eq(return_cn, convert_to_cn_pointer(0))), cn_bool_and(cn_bool_and(cellPointer(O___hyp_vmemmap19_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, buddy_cn), order_aligned(buddy_i_cn, order_cn)), cn_bool_not(cn_pointer_equality(p_cn, buddy_cn))))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/*
 * Pages that are available for allocation are tracked in free-lists, so we use
 * the pages themselves to store the list nodes to avoid wasting space. As the
 * allocator always returns zeroed pages (which are zeroed on the hyp_put_page()
 * path to optimize allocation speed), we also need to clean-up the list node in
 * each page when we take it out of the list.
 */
static inline void page_remove_from_list(struct hyp_page *p)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  p_i <= max_pfn (); 
  let phys = p_i * page_size(); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  take OP = Owned(p); 
  let order = (*p).order; 
  order < 11u8; 
  take AP = AllocatorPage(virt, true, order); 
  let prev = AP.prev; let next = AP.next; 
  take Node_prev = O_struct_list_head(prev, prev != virt); 
  take Node_next = O_struct_list_head(next, prev != next); 
  (prev != virt) || (next == virt); 
  0i64 <= hyp_physvirt_offset; 
  (u64) hyp_physvirt_offset <= phys; phys < shift_left(1u64, 63u64); 
  (mod((u64) hyp_physvirt_offset, page_size())) == 0u64; 
 ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; {cn_virt_ptr} unchanged; 
  take OP2 = Owned(p); 
  {*p} unchanged; 
  take ZP = ZeroPage(virt, true, (*p).order); 
  take Node_prev2 = O_struct_list_head(prev, prev != virt); 
  take Node_next2 = O_struct_list_head(next, prev != next); 
  (prev == next) || (Node_next2.next == Node_next.next); 
  (prev == next) || (Node_prev2.prev == Node_prev.prev); 
  (prev == virt) || (Node_prev2.next == next); 
  (prev == next) || (Node_next2.prev == prev); 
  (prev != next) || ((prev == virt) || (Node_prev2.prev == prev)); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_pointer* O___hyp_vmemmap20_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_bits_i64* O_hyp_physvirt_offset22_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_pointer* O_cn_virt_ptr12_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap20_cn, p_cn);
  update_cn_error_message_info("  0i64 <= hyp_physvirt_offset; \n  ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1179:3-21");
  cn_assert(cn_bits_u64_le(p_i_cn, max_pfn()), PRE);
  cn_pop_msg_info();
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr12_cn, O_hyp_physvirt_offset22_cn, phys_cn);
  update_cn_error_message_info(" ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; {cn_virt_ptr} unchanged; \n       ^./driver.pp.c:1182:8:");
  struct hyp_page_cn* OP_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u8* order_cn;
  order_cn = OP_cn->order;
  update_cn_error_message_info("  {*p} unchanged; \n  ^~~~~~~~~~~~~ ./driver.pp.c:1184:3-16");
  cn_assert(cn_bits_u8_lt(order_cn, convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  take ZP = ZeroPage(virt, true, (*p).order); \n       ^./driver.pp.c:1185:8:");
  struct list_head_cn* AP_cn = AllocatorPage(virt_cn, convert_to_cn_bool(true), order_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* prev_cn;
  prev_cn = AP_cn->prev;
  cn_pointer* next_cn;
  next_cn = AP_cn->next;
  update_cn_error_message_info("  take Node_next2 = O_struct_list_head(next, prev != next); \n       ^./driver.pp.c:1187:8:");
  struct list_head_cn* Node_prev_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, virt_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_next2.next == Node_next.next); \n       ^./driver.pp.c:1188:8:");
  struct list_head_cn* Node_next_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_prev2.prev == Node_prev.prev); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1189:3-36");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, virt_cn)), cn_pointer_equality(next_cn, virt_cn)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == virt) || (Node_prev2.next == next); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1190:3-31");
  cn_assert(cn_bits_i64_le(convert_to_cn_bits_i64(0LL), O_hyp_physvirt_offset22_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_next2.prev == prev); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1191:3-37");
  cn_assert(cn_bits_u64_le(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset22_cn), phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_next2.prev == prev); \n                                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1191:38-69");
  cn_assert(cn_bits_u64_lt(phys_cn, cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(63ULL))), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev != next) || ((prev == virt) || (Node_prev2.prev == prev)); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1192:3-57");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset22_cn), page_size()), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    struct list_head *node = (
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)(((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12))) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_ptr))));
c_add_to_ghost_state((&node), sizeof(struct list_head*), get_cn_stack_depth());


cn_pointer* node_addr_cn = convert_to_cn_pointer((&node));

    update_cn_error_message_info("  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); \n       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1206:8-43");

cn_pop_msg_info();

    update_cn_error_message_info("  let phys = p_i * page_size(); \n       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1207:8-51");

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, __list_del_entry(CN_LOAD(node)));
    /*CN*/update_cn_error_message_info("  let start_i = HP.pool.range_start / page_size(); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1209:14-55");

cn_pointer* read_node4 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&node)), struct list_head*));

update_cn_error_message_info("  let start_i = HP.pool.range_start / page_size(); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1209:15-53");

struct_list_head_to_bytes(read_node4);

cn_pop_msg_info();

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, memset(CN_LOAD(node), 0, sizeof(*node)));
    /*CN*/update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1211:14-55");

cn_pointer* read_p16 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

struct hyp_page_cn* deref_read_p160 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p16, struct hyp_page));

update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1211:15-53");

page_size_of_order2(deref_read_p160->order);

cn_pop_msg_info();

cn_pop_msg_info();


c_remove_from_ghost_state((&node), sizeof(struct list_head*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_pointer* O___hyp_vmemmap21_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_bits_i64* O_hyp_physvirt_offset23_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take Node_next = O_struct_list_head(next, prev != next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1177:5-62");
  cn_pointer* O_cn_virt_ptr13_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1193:10-36");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap21_cn, O___hyp_vmemmap20_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1193:37-69");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset23_cn, O_hyp_physvirt_offset22_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n                                                                     ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1193:70-94");
  cn_assert(cn_pointer_equality(O_cn_virt_ptr13_cn, O_cn_virt_ptr12_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct list_head *node = copy_alloc_id((((phys_addr_t)(((phys_addr_t)(((hyp_page_to_pfn(p))) << 12))) - hyp_physvirt_offset)), (cn_virt_ptr));\n       ^./driver.pp.c:1194:8:");
  struct hyp_page_cn* OP2_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ split_case (*node).prev != node; @*/\n  ^~~~~~~~~~~~~~~ ./driver.pp.c:1195:3-18");
  cn_assert(struct_hyp_page_cn_equality(OP2_cn, OP_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ split_case (*node).prev != (*node).next; @*/\n       ^./driver.pp.c:1196:8:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), OP2_cn->order, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    __list_del_entry(node);\n       ^./driver.pp.c:1197:8:");
  struct list_head_cn* Node_prev2_cn = O_struct_list_head(prev_cn, cn_bool_not(cn_pointer_equality(prev_cn, virt_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@ apply struct_list_head_to_bytes(node); @*/\n       ^./driver.pp.c:1198:8:");
  struct list_head_cn* Node_next2_cn = O_struct_list_head(next_cn, cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    memset(node, 0, sizeof(*node));\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1199:3-57");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_next2_cn->next, Node_next_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@ apply page_size_of_order2((*p).order); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1200:3-57");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_prev2_cn->prev, Node_prev_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1201:3-47");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, virt_cn), cn_pointer_equality(Node_prev2_cn->next, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/* for verification */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1202:3-47");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_next2_cn->prev, prev_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void page_remove_from_list_pool(struct hyp_pool *pool, struct hyp_page *p)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1203:3-67");
  cn_assert(cn_bool_or(cn_bool_not(cn_pointer_equality(prev_cn, next_cn)), cn_bool_or(cn_pointer_equality(prev_cn, virt_cn), cn_pointer_equality(Node_prev2_cn->prev, prev_cn))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
/* for verification */
static inline void page_remove_from_list_pool(struct hyp_pool *pool, struct hyp_page *p)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires take HP = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  let phys = p_i * page_size(); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  let start_i = HP.pool.range_start / page_size(); 
  let end_i = HP.pool.range_end / page_size(); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  let order = HP.vmemmap[p_i].order; 
  order != hyp_no_order (); 
  HP.vmemmap[p_i].refcount == 0u16; 
 ensures take ZP = ZeroPage(virt, true, order); 
  take H2 = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); 
  {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  H2.vmemmap == HP.vmemmap; 
  H2.pool == {free_area: H2.pool.free_area, ..HP.pool}; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_pointer* O___hyp_vmemmap22_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_bits_i64* O_hyp_physvirt_offset24_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_pointer* O_cn_virt_ptr14_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take H2 = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); \n               ^./driver.pp.c:1216:16:");
  struct Hyp_pool_ex1_record* HP_cn = Hyp_pool(pool_cn, O___hyp_vmemmap22_cn, O_cn_virt_ptr14_cn, O_hyp_physvirt_offset24_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap22_cn, p_cn);
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr14_cn, O_hyp_physvirt_offset24_cn, phys_cn);
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(HP_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(HP_cn->pool->range_end, page_size());
  update_cn_error_message_info("    /*CN*//*@instantiate vmemmap_l_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1222:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap22_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u8* order_cn;
  order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1224:3-28");
  cn_assert(cn_bool_not(cn_bits_u8_equality(order_cn, hyp_no_order())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, node); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1225:3-36");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    /*CN*/struct list_head *node = (
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)(((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12))) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_ptr))));
c_add_to_ghost_state((&node), sizeof(struct list_head*), get_cn_stack_depth());


cn_pointer* node_addr_cn = convert_to_cn_pointer((&node));

    /*CN*/update_cn_error_message_info("    /*CN*/if (node_prev != node) {\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1233:14-77");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("        /*CN*/if (node_prev != free_node)\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1234:14-75");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("        ;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1235:14-86");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("        /*CN*/if (node_next != node_prev && node_next != free_node)\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1236:14-85");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("        ;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1237:14-55");

update_cn_error_message_info("        ;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1237:14-53");

cn_pop_msg_info();

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("    /*CN*/};\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1238:14-52");

update_cn_error_message_info("    /*CN*/};\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1238:14-50");

cn_pop_msg_info();

cn_pop_msg_info();

    /*CN*/void *node_prev = CN_LOAD(CN_LOAD(node)->prev);
c_add_to_ghost_state((&node_prev), sizeof(void*), get_cn_stack_depth());


cn_pointer* node_prev_addr_cn = convert_to_cn_pointer((&node_prev));

    /*CN*/void *node_next = CN_LOAD(CN_LOAD(node)->next);
c_add_to_ghost_state((&node_next), sizeof(void*), get_cn_stack_depth());


cn_pointer* node_next_addr_cn = convert_to_cn_pointer((&node_next));

    /*CN*/update_cn_error_message_info("static inline void page_add_to_list(struct hyp_page *p, struct list_head *head)\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1241:14-90");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1242:14-90");

cn_pop_msg_info();

        /*CN*/void *free_node = &CN_LOAD(pool)->free_area[CN_LOAD(CN_LOAD(p)->order)];
c_add_to_ghost_state((&free_node), sizeof(void*), get_cn_stack_depth());


cn_pointer* free_node_addr_cn = convert_to_cn_pointer((&free_node));

    /*CN*/if (CN_LOAD(node_prev) != CN_LOAD(node)) {
        /*CN*/if (CN_LOAD(node_prev) != CN_LOAD(free_node))
        ;
        /*CN*/if (CN_LOAD(node_next) != CN_LOAD(node_prev) && CN_LOAD(node_next) != CN_LOAD(free_node))
        ;
    /*CN*/};
    (
({
  ghost_call_site = EMPTY;
  0;
})
, page_remove_from_list(CN_LOAD(p)));

c_remove_from_ghost_state((&node), sizeof(struct list_head*));


c_remove_from_ghost_state((&node_prev), sizeof(void*));


c_remove_from_ghost_state((&node_next), sizeof(void*));


c_remove_from_ghost_state((&free_node), sizeof(void*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_pointer* O___hyp_vmemmap23_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_bits_i64* O_hyp_physvirt_offset25_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take ZP = ZeroPage(virt, true, order); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1215:5-62");
  cn_pointer* O_cn_virt_ptr15_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct list_head>, order; @*/\n              ^./driver.pp.c:1226:15:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), order_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, p_i; @*/\n       ^./driver.pp.c:1227:8:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool_ex1(pool_cn, O___hyp_vmemmap23_cn, O_cn_virt_ptr15_cn, O_hyp_physvirt_offset25_cn, p_i_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/void *node_prev = node->prev;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1228:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap23_cn, O___hyp_vmemmap22_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/void *node_prev = node->prev;\n                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1228:30-62");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset25_cn, O_hyp_physvirt_offset24_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/void *node_next = node->next;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1229:3-28");
  cn_assert(cn_map_equality(H2_cn->vmemmap, HP_cn->vmemmap, struct_hyp_page_cn_equality), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, node_prev); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1230:3-56");
  struct hyp_pool_cn* a_9902 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_9902->free_area = H2_cn->pool->free_area;
  a_9902->range_start = HP_cn->pool->range_start;
  a_9902->range_end = HP_cn->pool->range_end;
  a_9902->max_order = HP_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_9902), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void page_add_to_list(struct hyp_page *p, struct list_head *head)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  let phys = p_i * page_size(); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  take Hp = Owned(p); 
  let order = (*p).order; 
  order < 11u8; 
  take AP1 = ZeroPage(virt, true, order); 
  let next = head; 
  take Node_head = Owned<struct list_head>(next); 
  let prev = (*next).prev; 
  ptr_eq(prev, next) || !addr_eq(prev, next); 
  take Node_prev = O_struct_list_head(prev, !addr_eq(prev, next)); 
  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); 
  (mod((u64) hyp_physvirt_offset, page_size())) == 0u64; 
  phys > (u64) hyp_physvirt_offset; 
  p >= __hyp_vmemmap; 
 ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; {cn_virt_ptr} unchanged; 
  take AP1R = AllocatorPage(virt, true, order); 
  take Hp2 = Owned(p); 
  {*p} unchanged; 
  take Node_head2 = Owned<struct list_head>(next); 
  take Node_prev2 = O_struct_list_head(prev, !addr_eq(prev, next)); 
  (prev == next) || (Node_prev.prev == Node_prev2.prev); 
  (prev == next) || {(*next).next} unchanged; 
  (*next).prev == virt; 
  (prev == next) || (Node_prev2.next == virt); 
  !addr_eq(prev, next) || ((*next).next == virt); 
  (AP1R.next == head); (AP1R.prev == prev); @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_pointer* O___hyp_vmemmap24_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_bits_i64* O_hyp_physvirt_offset26_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_pointer* O_cn_virt_ptr16_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap24_cn, p_cn);
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr16_cn, O_hyp_physvirt_offset26_cn, phys_cn);
  update_cn_error_message_info("  phys > (u64) hyp_physvirt_offset; \n       ^./driver.pp.c:1257:8:");
  struct hyp_page_cn* Hp_cn = owned_struct_hyp_page(p_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u8* order_cn;
  order_cn = Hp_cn->order;
  update_cn_error_message_info(" ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; {cn_virt_ptr} unchanged; \n  ^~~~~~~~~~~~~ ./driver.pp.c:1259:3-16");
  cn_assert(cn_bits_u8_lt(order_cn, convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  take AP1R = AllocatorPage(virt, true, order); \n       ^./driver.pp.c:1260:8:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), order_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = head_cn;
  update_cn_error_message_info("  {*p} unchanged; \n       ^./driver.pp.c:1262:8:");
  struct list_head_cn* Node_head_cn = owned_struct_list_head(next_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* prev_cn;
  prev_cn = Node_head_cn->prev;
  update_cn_error_message_info("  take Node_prev2 = O_struct_list_head(prev, !addr_eq(prev, next)); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1264:3-46");
  cn_assert(cn_bool_or(ptr_eq(prev_cn, next_cn), cn_bool_not(addr_eq(prev_cn, next_cn))), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_prev.prev == Node_prev2.prev); \n       ^./driver.pp.c:1265:8:");
  struct list_head_cn* Node_prev_cn = O_struct_list_head(prev_cn, cn_bool_not(addr_eq(prev_cn, next_cn)), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || {(*next).next} unchanged; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1266:3-50");
  cn_assert(cn_bits_u64_le(cn_bits_u64_divide(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset26_cn), page_size()), p_i_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || {(*next).next} unchanged; \n                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1266:51-95");
  cn_assert(cn_bits_u64_lt(p_i_cn, cn_bits_u64_divide(cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(63ULL)), page_size())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (*next).prev == virt; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1267:3-57");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset26_cn), page_size()), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  (prev == next) || (Node_prev2.next == virt); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1268:3-36");
  cn_assert(cn_bits_u64_lt(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset26_cn), phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  !addr_eq(prev, next) || ((*next).next == virt); \n  ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1269:3-22");
  cn_assert(cn_pointer_le(O___hyp_vmemmap24_cn, p_cn), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&head), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
    struct list_head *node = (
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)(((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12))) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_ptr))));
c_add_to_ghost_state((&node), sizeof(struct list_head*), get_cn_stack_depth());


cn_pointer* node_addr_cn = convert_to_cn_pointer((&node));

    /*CN*/if (CN_LOAD(CN_LOAD(head)->prev) != CN_LOAD(head)) {}
    /*CN*/update_cn_error_message_info("  let free_area_l = member_shift<struct hyp_pool>(pool, free_area); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1285:14-67");

cn_pointer* read_node6 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&node)), struct list_head*));

cn_pointer* read_p20 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

struct hyp_page_cn* deref_read_p200 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p20, struct hyp_page));

update_cn_error_message_info("  let free_area_l = member_shift<struct hyp_pool>(pool, free_area); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1285:15-65");

bytes_to_struct_list_head(read_node6, deref_read_p200->order);

cn_pop_msg_info();

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, INIT_LIST_HEAD(CN_LOAD(node)));
    (
({
  ghost_call_site = EMPTY;
  0;
})
, list_add_tail(CN_LOAD(node), CN_LOAD(head)));

c_remove_from_ghost_state((&node), sizeof(struct list_head*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&head), sizeof(struct list_head*));

{
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_pointer* O___hyp_vmemmap25_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_bits_i64* O_hyp_physvirt_offset27_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  ptr_eq(prev, next) || !addr_eq(prev, next); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1253:5-62");
  cn_pointer* O_cn_virt_ptr17_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (AP1R.next == head); (AP1R.prev == prev); @*/\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1270:10-36");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap25_cn, O___hyp_vmemmap24_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  (AP1R.next == head); (AP1R.prev == prev); @*/\n                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1270:37-69");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset27_cn, O_hyp_physvirt_offset26_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  (AP1R.next == head); (AP1R.prev == prev); @*/\n                                                                     ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1270:70-94");
  cn_assert(cn_pointer_equality(O_cn_virt_ptr17_cn, O_cn_virt_ptr16_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n       ^./driver.pp.c:1271:8:");
  struct list_head_cn* AP1R_cn = AllocatorPage(virt_cn, convert_to_cn_bool(true), order_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct list_head *node = copy_alloc_id((((phys_addr_t)(((phys_addr_t)(((hyp_page_to_pfn(p))) << 12))) - hyp_physvirt_offset)), (cn_virt_ptr));\n       ^./driver.pp.c:1272:8:");
  struct hyp_page_cn* Hp2_cn = owned_struct_hyp_page(p_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/if (head->prev != head) {}\n  ^~~~~~~~~~~~~~~ ./driver.pp.c:1273:3-18");
  cn_assert(struct_hyp_page_cn_equality(Hp2_cn, Hp_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@ apply bytes_to_struct_list_head(node, (*p).order); @*/\n       ^./driver.pp.c:1274:8:");
  struct list_head_cn* Node_head2_cn = owned_struct_list_head(next_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    INIT_LIST_HEAD(node);\n       ^./driver.pp.c:1275:8:");
  struct list_head_cn* Node_prev2_cn = O_struct_list_head(prev_cn, cn_bool_not(addr_eq(prev_cn, next_cn)), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    list_add_tail(node, head);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1276:3-57");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_prev_cn->prev, Node_prev2_cn->prev)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1277:3-46");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_head2_cn->next, Node_head_cn->next)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("static inline void page_add_to_list_pool(struct hyp_pool *pool,\n  ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1278:3-24");
  cn_assert(cn_pointer_equality(Node_head2_cn->prev, virt_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                struct hyp_page *p, struct list_head *head)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1279:3-47");
  cn_assert(cn_bool_or(cn_pointer_equality(prev_cn, next_cn), cn_pointer_equality(Node_prev2_cn->next, virt_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1280:3-50");
  cn_assert(cn_bool_or(cn_bool_not(addr_eq(prev_cn, next_cn)), cn_pointer_equality(Node_head2_cn->next, virt_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires (alloc_id) __hyp_vmemmap == (alloc_id) p; \n  ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1281:3-23");
  cn_assert(cn_pointer_equality(AP1R_cn->next, head_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires (alloc_id) __hyp_vmemmap == (alloc_id) p; \n                       ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1281:24-44");
  cn_assert(cn_pointer_equality(AP1R_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void page_add_to_list_pool(struct hyp_pool *pool,
                struct hyp_page *p, struct list_head *head)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires (alloc_id) __hyp_vmemmap == (alloc_id) p; 
  p >= __hyp_vmemmap; 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  take HP = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); 
  let free_area_l = member_shift<struct hyp_pool>(pool, free_area); 
  let phys = p_i * page_size(); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  let virt_i = (u64) virt / page_size(); 
  let start_i = HP.pool.range_start / page_size(); 
  let end_i = HP.pool.range_end / page_size(); 
  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  let order = (HP.vmemmap[p_i]).order; 
  order != (hyp_no_order ()); 
  HP.vmemmap[p_i].refcount == 0u16; 
  take ZP = ZeroPage(virt, true, order); 
  head == array_shift<struct list_head>(&(pool->free_area), order); 
 ensures take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  H2.pool == {free_area: H2.pool.free_area, ..HP.pool}; 
  H2.vmemmap == HP.vmemmap; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_pointer* O___hyp_vmemmap26_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_bits_i64* O_hyp_physvirt_offset28_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_pointer* O_cn_virt_ptr18_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1292:11-52");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let order = (HP.vmemmap[p_i]).order; \n  ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1293:3-22");
  cn_assert(cn_pointer_le(O___hyp_vmemmap26_cn, p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap26_cn, p_cn);
  update_cn_error_message_info("  HP.vmemmap[p_i].refcount == 0u16; \n       ^./driver.pp.c:1295:8:");
  struct Hyp_pool_ex1_record* HP_cn = Hyp_pool_ex1(pool_cn, O___hyp_vmemmap26_cn, O_cn_virt_ptr18_cn, O_hyp_physvirt_offset28_cn, p_i_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* free_area_l_cn;
  free_area_l_cn = cn_member_shift(pool_cn, hyp_pool, free_area);
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr18_cn, O_hyp_physvirt_offset28_cn, phys_cn);
  cn_bits_u64* virt_i_cn;
  virt_i_cn = cn_bits_u64_divide(cast_cn_pointer_to_cn_bits_u64(virt_cn), page_size());
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(HP_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(HP_cn->pool->range_end, page_size());
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1302:3-50");
  cn_assert(cn_bits_u64_le(cn_bits_u64_divide(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset28_cn), page_size()), p_i_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n                                                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1302:51-95");
  cn_assert(cn_bits_u64_lt(p_i_cn, cn_bits_u64_divide(cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(63ULL)), page_size())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1303:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap26_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u8* order_cn;
  order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1305:3-30");
  cn_assert(cn_bool_not(cn_bits_u8_equality(order_cn, hyp_no_order())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1306:3-36");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/struct list_head *prev = head->prev;\n       ^./driver.pp.c:1307:8:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), order_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate freeArea_cell_wf, (*p).order;@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1308:3-68");
  cn_assert(cn_pointer_equality(head_cn, cn_array_shift(cn_member_shift(pool_cn, hyp_pool, free_area), sizeof(struct list_head), order_cn)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&head), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
    /*CN*/update_cn_error_message_info("        *prev;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1314:14-75");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("    /*CN*/};\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1315:14-61");

update_cn_error_message_info("    /*CN*/};\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1315:14-59");

cn_pop_msg_info();

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("    /*@ assert (ptr_eq(prev, head) || !addr_eq(prev, head)); @*/\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1316:14-84");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("    page_add_to_list(p, head);\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1317:14-86");

cn_pop_msg_info();

    /*CN*/struct list_head *prev = CN_LOAD(CN_LOAD(head)->prev);
c_add_to_ghost_state((&prev), sizeof(struct list_head*), get_cn_stack_depth());


cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));

    /*CN*/update_cn_error_message_info("static inline void page_add_to_list_pool_ex1(struct hyp_pool *pool,\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1319:14-56");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("                struct hyp_page *p, struct list_head *head, struct hyp_page *p_ex)\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1320:14-85");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1321:14-85");

cn_pop_msg_info();

    /*CN*/if (CN_LOAD(prev) != CN_LOAD(head)) {
        /*CN*/update_cn_error_message_info("  (alloc_id) __hyp_vmemmap == (alloc_id) p; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1323:18-90");

cn_pop_msg_info();

        /*CN*/update_cn_error_message_info("  let p_i2 = cn_hyp_page_to_pfn(__hyp_vmemmap, p_ex); \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1324:18-78");

cn_pop_msg_info();

        CN_LOAD(*CN_LOAD(prev));
    /*CN*/};
    update_cn_error_message_info("  let phys = p_i * page_size(); \n       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1327:8-63");

cn_pointer* read_prev5 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&prev)), struct list_head*));

cn_pointer* read_head2 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&head)), struct list_head*));

cn_pointer* read_prev6 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&prev)), struct list_head*));

cn_pointer* read_head3 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&head)), struct list_head*));

update_cn_error_message_info("  let phys = p_i * page_size(); \n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1327:9-61");

update_cn_error_message_info("  let phys = p_i * page_size(); \n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1327:9-61");

cn_assert(cn_bool_or(ptr_eq(read_prev5, read_head2), cn_bool_not(addr_eq(read_prev6, read_head3))), STATEMENT);

cn_pop_msg_info();

cn_pop_msg_info();

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, page_add_to_list(CN_LOAD(p), CN_LOAD(head)));

c_remove_from_ghost_state((&prev), sizeof(struct list_head*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&head), sizeof(struct list_head*));

{
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_pointer* O___hyp_vmemmap27_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_bits_i64* O_hyp_physvirt_offset29_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  (u64) hyp_physvirt_offset / page_size() <= p_i; p_i < shift_left(1u64, 63u64) / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1291:5-62");
  cn_pointer* O_cn_virt_ptr19_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, virt); @*/\n              ^./driver.pp.c:1309:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap27_cn, O_cn_virt_ptr19_cn, O_hyp_physvirt_offset29_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, prev); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1310:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap27_cn, O___hyp_vmemmap26_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, prev); @*/\n                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1310:30-62");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset29_cn, O_hyp_physvirt_offset28_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/if (prev != head) {\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1311:3-56");
  struct hyp_pool_cn* a_10566 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_10566->free_area = H2_cn->pool->free_area;
  a_10566->range_start = HP_cn->pool->range_start;
  a_10566->range_end = HP_cn->pool->range_end;
  a_10566->max_order = HP_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_10566), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate vmemmap_l_wf, cn_hyp_virt_to_pfn(hyp_physvirt_offset,prev);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1312:3-28");
  cn_assert(cn_map_equality(H2_cn->vmemmap, HP_cn->vmemmap, struct_hyp_page_cn_equality), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline void page_add_to_list_pool_ex1(struct hyp_pool *pool,
                struct hyp_page *p, struct list_head *head, struct hyp_page *p_ex)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  (alloc_id) __hyp_vmemmap == (alloc_id) p; 
  let p_i2 = cn_hyp_page_to_pfn(__hyp_vmemmap, p_ex); 
  take HP = Hyp_pool_ex2(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i, p_i2); 
  let free_area_l = member_shift<struct hyp_pool>(pool, free_area); 
  let phys = p_i * page_size(); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  let start_i = HP.pool.range_start / page_size(); 
  let end_i = HP.pool.range_end / page_size(); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); 
  let order = (HP.vmemmap[p_i]).order; 
  order != hyp_no_order (); 
  (HP.vmemmap[p_i]).refcount == 0u16; 
  take ZP = ZeroPage(virt, true, order); 
  head == array_shift<struct list_head>(&(pool->free_area), order); 
  p_i != p_i2; 
 ensures take H2 = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i2); 
  {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  H2.pool == {free_area: H2.pool.free_area, ..HP.pool}; 
  H2.vmemmap == HP.vmemmap; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  cn_pointer* p_ex_cn = convert_to_cn_pointer(p_ex);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_pointer* O___hyp_vmemmap28_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_bits_i64* O_hyp_physvirt_offset30_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_pointer* O_cn_virt_ptr20_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap28_cn, p_cn);
  update_cn_error_message_info("  order != hyp_no_order (); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1334:3-44");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i2_cn;
  p_i2_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap28_cn, p_ex_cn);
  update_cn_error_message_info("  take ZP = ZeroPage(virt, true, order); \n       ^./driver.pp.c:1336:8:");
  struct Hyp_pool_ex1_record* HP_cn = Hyp_pool_ex2(pool_cn, O___hyp_vmemmap28_cn, O_cn_virt_ptr20_cn, O_hyp_physvirt_offset30_cn, p_i_cn, p_i2_cn, PRE, 0);
  cn_pop_msg_info();
  cn_pointer* free_area_l_cn;
  free_area_l_cn = cn_member_shift(pool_cn, hyp_pool, free_area);
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr20_cn, O_hyp_physvirt_offset30_cn, phys_cn);
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(HP_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(HP_cn->pool->range_end, page_size());
  update_cn_error_message_info("  H2.vmemmap == HP.vmemmap; @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1342:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap28_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1343:3-85");
  cn_assert(cellPointer(O___hyp_vmemmap28_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_ex_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u8* order_cn;
  order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1345:3-28");
  cn_assert(cn_bool_not(cn_bits_u8_equality(order_cn, hyp_no_order())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1346:3-38");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(HP_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n       ^./driver.pp.c:1347:8:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), order_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/void *prev = head->prev;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1348:3-68");
  cn_assert(cn_pointer_equality(head_cn, cn_array_shift(cn_member_shift(pool_cn, hyp_pool, free_area), sizeof(struct list_head), order_cn)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, virt); @*/\n  ^~~~~~~~~~~~ ./driver.pp.c:1349:3-15");
  cn_assert(cn_bool_not(cn_bits_u64_equality(p_i_cn, p_i2_cn)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&head), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  c_add_to_ghost_state((&p_ex), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_ex_addr_cn = convert_to_cn_pointer((&p_ex));
  
    /*CN*/update_cn_error_message_info("    page_add_to_list(p, head);\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1355:14-54");

update_cn_error_message_info("    page_add_to_list(p, head);\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1355:14-53");

cn_pop_msg_info();

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("}\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1356:14-84");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("static inline struct hyp_page *node_to_page(struct list_head *node)\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1357:14-75");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("/*@ accesses __hyp_vmemmap, hyp_physvirt_offset; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1358:14-86");

cn_pop_msg_info();

    /*CN*/void *prev = CN_LOAD(CN_LOAD(head)->prev);
c_add_to_ghost_state((&prev), sizeof(void*), get_cn_stack_depth());


cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));

    /*CN*/update_cn_error_message_info("  let phys = (u64) node + (u64) hyp_physvirt_offset; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1360:14-85");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("  let p_i = phys / page_size(); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1361:14-85");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("  let page = array_shift<struct hyp_page>(__hyp_vmemmap, p_i); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1362:14-56");

cn_pop_msg_info();

    /*CN*/if (CN_LOAD(prev) != CN_LOAD(head)) {
        /*CN*/update_cn_error_message_info("  mod((u64) __hyp_vmemmap, (u64) (sizeof<struct hyp_page>)) == 0u64; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1364:18-90");

cn_pop_msg_info();

    /*CN*/};
    (
({
  ghost_call_site = EMPTY;
  0;
})
, page_add_to_list(CN_LOAD(p), CN_LOAD(head)));

c_remove_from_ghost_state((&prev), sizeof(void*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&head), sizeof(struct list_head*));

  c_remove_from_ghost_state((&p_ex), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_pointer* O___hyp_vmemmap29_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_bits_i64* O_hyp_physvirt_offset31_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p_ex); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1332:5-62");
  cn_pointer* O_cn_virt_ptr21_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract AllocatorPage, cn_hyp_virt_to_pfn(hyp_physvirt_offset, prev); @*/\n              ^./driver.pp.c:1350:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool_ex1(pool_cn, O___hyp_vmemmap29_cn, O_cn_virt_ptr21_cn, O_hyp_physvirt_offset31_cn, p_i2_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate freeArea_cell_wf, (*p).order;@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1351:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap29_cn, O___hyp_vmemmap28_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate freeArea_cell_wf, (*p).order;@*/\n                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1351:30-62");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset31_cn, O_hyp_physvirt_offset30_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/if (prev != head) {\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1352:3-56");
  struct hyp_pool_cn* a_10904 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_10904->free_area = H2_cn->pool->free_area;
  a_10904->range_start = HP_cn->pool->range_start;
  a_10904->range_end = HP_cn->pool->range_end;
  a_10904->max_order = HP_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_10904), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate vmemmap_l_wf, cn_hyp_virt_to_pfn(hyp_physvirt_offset,prev);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1353:3-28");
  cn_assert(cn_map_equality(H2_cn->vmemmap, HP_cn->vmemmap, struct_hyp_page_cn_equality), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static inline struct hyp_page *node_to_page(struct list_head *node)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset; 
 requires 0i64 <= hyp_physvirt_offset; 
  let phys = (u64) node + (u64) hyp_physvirt_offset; 
  let p_i = phys / page_size(); 
  let page = array_shift<struct hyp_page>(__hyp_vmemmap, p_i); 
  mod((u64) hyp_physvirt_offset, page_size ()) == 0u64; 
  mod((u64) __hyp_vmemmap, (u64) (sizeof<struct hyp_page>)) == 0u64; 
 ensures return == page; 
  {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  struct hyp_page* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* node_cn = convert_to_cn_pointer(node);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("}\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1369:5-49");
  cn_pointer* O___hyp_vmemmap30_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1369:5-49");
  cn_bits_i64* O_hyp_physvirt_offset32_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("static void __hyp_attach_page(struct hyp_pool *pool,\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1370:11-39");
  cn_assert(cn_bits_i64_le(convert_to_cn_bits_i64(0LL), O_hyp_physvirt_offset32_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(node_cn), cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset32_cn));
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_bits_u64_divide(phys_cn, page_size());
  cn_pointer* page_cn;
  page_cn = cn_array_shift(O___hyp_vmemmap30_cn, sizeof(struct hyp_page), p_i_cn);
  update_cn_error_message_info("  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1374:3-56");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_bits_i64_to_cn_bits_u64(O_hyp_physvirt_offset32_cn), page_size()), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  take H = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1375:3-69");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_pointer_to_cn_bits_u64(O___hyp_vmemmap30_cn), cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page)))), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&node), sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* node_addr_cn = convert_to_cn_pointer((&node));
  
    { __cn_ret = (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[((((phys_addr_t)CN_LOAD((node)) + CN_LOAD(hyp_physvirt_offset))) >> 12)]); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&node), sizeof(struct list_head*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("}\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1369:5-49");
  cn_pointer* O___hyp_vmemmap31_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1369:5-49");
  cn_bits_i64* O_hyp_physvirt_offset33_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let start_i = H.pool.range_start / page_size(); \n         ^~~~~~~~~~~~~~~ ./driver.pp.c:1376:10-25");
  cn_assert(cn_pointer_equality(return_cn, page_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size (); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1377:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap31_cn, O___hyp_vmemmap30_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size (); \n                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1377:30-62");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset33_cn, O_hyp_physvirt_offset32_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static void __hyp_attach_page(struct hyp_pool *pool,
                  struct hyp_page *p)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires (alloc_id) __hyp_vmemmap == (alloc_id) p; 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  take H = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); 
  let start_i = H.pool.range_start / page_size(); 
  let end_i = H.pool.range_end / page_size (); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  (H.vmemmap[p_i]).refcount == 0u16; 
  ((H.vmemmap[p_i]).order) != (hyp_no_order()); 
  let i_order = (H.vmemmap[p_i]).order; 
  (p_i * page_size()) + (page_size_of_order(i_order)) <= (H.pool).range_end; 
  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); 
  take P = Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, p_i), true, i_order); 
 ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  {free_area: H2.pool.free_area, ..H.pool} == H2.pool; 
  each (u64 i; p_i < i && i < end_i){(H.vmemmap[i].refcount == 0u16) || (H2.vmemmap[i] == H.vmemmap[i])}; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_pointer* O___hyp_vmemmap32_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_bits_i64* O_hyp_physvirt_offset34_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_pointer* O_cn_virt_ptr22_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take P = Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, p_i), true, i_order); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1384:11-52");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap32_cn, p_cn);
  update_cn_error_message_info("  take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n       ^./driver.pp.c:1386:8:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool_ex1(pool_cn, O___hyp_vmemmap32_cn, O_cn_virt_ptr22_cn, O_hyp_physvirt_offset34_cn, p_i_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(H_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(H_cn->pool->range_end, page_size());
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1389:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap32_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p);@*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1390:3-37");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    phys_addr_t phys = ((phys_addr_t)(((hyp_page_to_pfn(p))) << 12));\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1391:3-48");
  cn_assert(cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order, hyp_no_order())), PRE);
  cn_pop_msg_info();
  cn_bits_u8* i_order_cn;
  i_order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("    struct hyp_page *buddy = ((void *)0);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1393:3-77");
  cn_assert(cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(p_i_cn, page_size()), page_size_of_order(i_order_cn)), H_cn->pool->range_end), PRE);
  cn_pop_msg_info();
  cn_pointer* ptr_phys_0_cn;
  ptr_phys_0_cn = cn__hyp_va(O_cn_virt_ptr22_cn, O_hyp_physvirt_offset34_cn, convert_to_cn_bits_u64(0ULL));
  update_cn_error_message_info("    u8 order = p->order;\n       ^./driver.pp.c:1395:8:");
  Page(cn_array_shift(ptr_phys_0_cn, sizeof(char[4096]), p_i_cn), convert_to_cn_bool(true), i_order_cn, PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    /*CN*/update_cn_error_message_info("        /*\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1401:14-75");

cn_pop_msg_info();

    phys_addr_t phys = ((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12));
c_add_to_ghost_state((&phys), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* phys_addr_cn = convert_to_cn_pointer((&phys));

    /* struct hyp_page *buddy; */
    struct hyp_page *buddy = ((void *)0);
c_add_to_ghost_state((&buddy), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* buddy_addr_cn = convert_to_cn_pointer((&buddy));

    /*CN*/update_cn_error_message_info("         * after coallescing, so make sure to mark it HYP_NO_ORDER proactively.\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1405:14-84");

cn_pop_msg_info();

    u8 order = CN_LOAD(CN_LOAD(p)->order);
c_add_to_ghost_state((&order), sizeof(unsigned char), get_cn_stack_depth());


cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));

        /*CN*/update_cn_error_message_info("        p->order = 0xff;\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1407:18-59");

cn_pointer* read_p31 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

struct hyp_page_cn* deref_read_p310 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p31, struct hyp_page));

update_cn_error_message_info("        p->order = 0xff;\n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1407:19-57");

page_size_of_order2(deref_read_p310->order);

cn_pop_msg_info();

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, memset((
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)(((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12))) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_ptr)))), 0, ((1UL) << 12) << CN_LOAD(CN_LOAD(p)->order)));
    //if (phys < pool->range_start || phys >= pool->range_end)
    //    goto insert;
    if (!(CN_LOAD(phys) < CN_LOAD(CN_LOAD(pool)->range_start) || CN_LOAD(phys) >= CN_LOAD(CN_LOAD(pool)->range_end))) {
        /*
         * Only the first struct hyp_page of a high-order page (otherwise known
         * as the 'head') should have p->order set. The non-head pages should
         * have p->order = HYP_NO_ORDER. Here @p may no longer be the head
         * after coallescing, so make sure to mark it HYP_NO_ORDER proactively.
         */
        CN_STORE(CN_LOAD(p)->order, 0xff);
        {
struct loop_ownership* a_11276;

cn_bits_u64* O_phys15;

cn_pointer* O_buddy3;

cn_bits_u8* O_order6;

cn_pointer* O_pool18;

cn_pointer* O_p18;

cn_pointer* O___hyp_vmemmap34;

cn_bits_i64* O_hyp_physvirt_offset36;

cn_pointer* O_cn_virt_ptr24;

cn_bits_u64* p_i2;

cn_pointer* virt;

struct Hyp_pool_ex1_record* H_I;

struct hyp_page_cn* p_page;

cn_bool* a_11381;

cn_bool* a_11470;

struct hyp_pool_cn* a_11497;

cn_pointer* read___hyp_vmemmap33;

cn_pointer* read_pool3;

struct hyp_pool_cn* deref_read_pool30;

cn_pointer* read_p34;

cn_bits_u8* read_order5;

cn_pointer* read___hyp_vmemmap34;

cn_pointer* read_p35;

cn_bits_u8* read_order6;

cn_bits_u8* read_order7;
for (; ({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_11276 = initialise_loop_ownership_state();
  update_cn_error_message_info("\n        ^./driver.pp.c:1419:9-1454:10");
  O_phys15 = owned_unsigned_long_long(phys_addr_cn, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("\n        ^./driver.pp.c:1419:9-1454:10");
  O_buddy3 = owned_struct_hyp_page_pointer(buddy_addr_cn, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("\n        ^./driver.pp.c:1419:9-1454:10");
  O_order6 = owned_unsigned_char(order_addr_cn, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("\n        ^./driver.pp.c:1419:9-1454:10");
  O_pool18 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("\n        ^./driver.pp.c:1419:9-1454:10");
  O_p18 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  O___hyp_vmemmap34 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  O_hyp_physvirt_offset36 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  O_cn_virt_ptr24 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("          order < H_I.pool.max_order; \n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1420:17-58");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), LOOP);
  cn_pop_msg_info();
  p_i2 = cn_hyp_page_to_pfn(O___hyp_vmemmap34, O_p18);
  virt = cn__hyp_va(O_cn_virt_ptr24, O_hyp_physvirt_offset36, cn_bits_u64_multiply(p_i2, page_size()));
  update_cn_error_message_info("          order_aligned(p_i2,order); \n               ^./driver.pp.c:1423:16:");
  ZeroPage(virt, convert_to_cn_bool(true), O_order6, LOOP, a_11276);
  cn_pop_msg_info();
  update_cn_error_message_info("          each (u64 i; p_i < i && i < end_i)\n               ^./driver.pp.c:1425:16:");
  H_I = Hyp_pool(O_pool18, O___hyp_vmemmap34, O_cn_virt_ptr24, O_hyp_physvirt_offset36, LOOP, a_11276);
  cn_pop_msg_info();
  p_page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_I->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i2));
  update_cn_error_message_info("          H_I.pool == {free_area: (H_I.pool).free_area, ..H.pool}; @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1428:11-1429:93");
  a_11381 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        struct hyp_page_cn* a_11375 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
        a_11375->refcount = p_page->refcount;
        a_11375->order = O_order6;
        a_11375->flags = p_page->flags;
        cn_map* a_11377 = cn_map_deep_copy(H_I->vmemmap);
        a_11381 = cn_bool_and(a_11381, vmemmap_wf(i, cn_map_set(a_11377, cast_cn_bits_u64_to_cn_integer(p_i2), a_11375), O_pool18, H_I->pool));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_11381, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            if (!buddy)\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1431:11-38");
  cn_assert(cn_bits_u8_lt(O_order6, H_I->pool->max_order), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("                break;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1432:11-86");
  cn_assert(cellPointer(O___hyp_vmemmap34, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, O_p18), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,buddy); @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1433:11-35");
  cn_assert(cn_bits_u16_equality(p_page->refcount, convert_to_cn_bits_u16(0ULL)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,buddy); @*/\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1433:36-68");
  cn_assert(cn_bits_u8_equality(p_page->order, hyp_no_order()), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ apply attach_inc_loop(H_I.vmemmap,__hyp_vmemmap,*pool, p, order); @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1434:11-37");
  cn_assert(order_aligned(p_i2, O_order6), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ apply lemma2(cn_hyp_page_to_pfn(__hyp_vmemmap,p), order); @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1435:11-86");
  cn_assert(cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(p_i2, page_size()), page_size_of_order(O_order6)), H_I->pool->range_end), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ apply page_size_of_order_inc(order); @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1436:11-1437:83");
  a_11470 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL))), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_lt(p_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        a_11470 = cn_bool_and(a_11470, cn_bool_or(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL)), struct_hyp_page_cn_equality((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_I->vmemmap, cast_cn_bits_u64_to_cn_integer(i)), (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_11470, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, buddy); @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1438:11-37");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap34, O___hyp_vmemmap32_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, buddy); @*/\n                                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1438:38-70");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset36, O_hyp_physvirt_offset34_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, buddy); @*/\n                                                                      ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1438:71-88");
  cn_assert(cn_pointer_equality(O_pool18, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("            /* Take the buddy out of its list, and coallesce with @p */\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1439:11-67");
  a_11497 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_11497->free_area = H_I->pool->free_area;
  a_11497->range_start = H_cn->pool->range_start;
  a_11497->range_end = H_cn->pool->range_end;
  a_11497->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H_I->pool, a_11497), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1444:22-89");
  cn_pop_msg_info();
  update_cn_error_message_info("//insert:\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1445:22-90");
  read___hyp_vmemmap33 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_pool3 = convert_to_cn_pointer(cn_pointer_deref(pool_addr_cn, struct hyp_pool*));
  deref_read_pool30 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool3, struct hyp_pool));
  read_p34 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_order5 = convert_to_cn_bits_u8(cn_pointer_deref(order_addr_cn, unsigned char));
  update_cn_error_message_info("//insert:\n                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1445:23-88");
  attach_inc_loop(H_I->vmemmap, read___hyp_vmemmap33, deref_read_pool30, read_p34, read_order5);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate freeArea_cell_wf, order;@*/\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1446:22-82");
  read___hyp_vmemmap34 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_p35 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_order6 = convert_to_cn_bits_u8(cn_pointer_deref(order_addr_cn, unsigned char));
  update_cn_error_message_info("    /*CN*//*@instantiate freeArea_cell_wf, order;@*/\n                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1446:23-80");
  lemma2(cn_hyp_page_to_pfn(read___hyp_vmemmap34, read_p35), read_order6);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1447:22-61");
  read_order7 = convert_to_cn_bits_u8(cn_pointer_deref(order_addr_cn, unsigned char));
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1447:23-59");
  page_size_of_order_inc(read_order7);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Mark the new head, and insert it */\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1448:22-94");
  cn_pop_msg_info();
  update_cn_error_message_info("    p->order = order;\n                     ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1449:22-98");
  cn_pop_msg_info();
  update_cn_error_message_info(" requires (alloc_id) __hyp_vmemmap == (alloc_id) p; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1457:14-51");
  cn_pop_msg_info();
  update_cn_error_message_info("  take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1458:14-84");
  cn_pop_msg_info();
  update_cn_error_message_info("  let p_order = (H.vmemmap[p_i]).order; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1461:14-86");
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_11276);
  cn_bump_free_after(cn_frame_id);
  0;
})
, (CN_LOAD(order) + 1) < CN_LOAD(CN_LOAD(pool)->max_order); CN_POSTFIX(order, ++))
        /*@ inv (alloc_id) __hyp_vmemmap == (alloc_id) p; 
          let p_i2 = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
          let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, p_i2 * page_size()); 
          take Z = ZeroPage(virt, true, order); 

          take H_I = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
          let p_page = H_I.vmemmap[p_i2]; 
         // for page_group_ok 
          each (u64 i; (start_i <= i) && (i < end_i))
            {vmemmap_wf (i, (H_I.vmemmap)[p_i2: {order: order, ..p_page}], pool, H_I.pool)}; 

          order < H_I.pool.max_order; 
          cellPointer(__hyp_vmemmap,(u64) (sizeof<struct hyp_page>),start_i,end_i,p); 
          p_page.refcount == 0u16; p_page.order == hyp_no_order (); 
          order_aligned(p_i2,order); 
          (p_i2 * page_size()) + (page_size_of_order(order)) <= (H_I.pool).range_end; 
          each (u64 i; p_i < i && i < end_i)
            {(H.vmemmap[i].refcount == 0u16) || (H_I.vmemmap[i] == H.vmemmap[i])}; 
          {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; {pool} unchanged; 
          H_I.pool == {free_area: (H_I.pool).free_area, ..H.pool}; @*/
        {
            CN_STORE(buddy, __find_buddy_avail(CN_LOAD(pool), CN_LOAD(p), CN_LOAD(order)));
            if (!CN_LOAD(buddy))
                break;
            /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,buddy); @*/
            /*CN*//*@ apply attach_inc_loop(H_I.vmemmap,__hyp_vmemmap,*pool, p, order); @*/
            /*CN*//*@ apply lemma2(cn_hyp_page_to_pfn(__hyp_vmemmap,p), order); @*/
            /*CN*//*@ apply page_size_of_order_inc(order); @*/
            /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p); @*/
            /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, buddy); @*/
            /* Take the buddy out of its list, and coallesce with @p */
            page_remove_from_list_pool(CN_LOAD(pool), CN_LOAD(buddy));
            CN_STORE(CN_LOAD(buddy)->order, 0xff);
            CN_STORE(p, (CN_LOAD((p)) < CN_LOAD((buddy)) ? CN_LOAD((p)) : CN_LOAD((buddy))));
        }}
    }
//insert:
    /*CN*/update_cn_error_message_info(" requires (alloc_id) __hyp_vmemmap == (alloc_id) p; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1457:14-51");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("  take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1458:14-84");

cn_pop_msg_info();

    /* Mark the new head, and insert it */
    CN_STORE(CN_LOAD(p)->order, CN_LOAD(order));
    /*CN*/update_cn_error_message_info("  let p_order = (H.vmemmap[p_i]).order; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1461:14-86");

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, page_add_to_list_pool(CN_LOAD(pool), CN_LOAD(p), &CN_LOAD(pool)->free_area[CN_LOAD(order)]));

c_remove_from_ghost_state((&phys), sizeof(unsigned long long));


c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&order), sizeof(unsigned char));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_pointer* O___hyp_vmemmap33_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_bits_i64* O_hyp_physvirt_offset35_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1383:5-62");
  cn_pointer* O_cn_virt_ptr23_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply page_size_of_order2((*p).order); @*/\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1396:10-36");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap33_cn, O___hyp_vmemmap32_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply page_size_of_order2((*p).order); @*/\n                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1396:37-69");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset35_cn, O_hyp_physvirt_offset34_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    memset(copy_alloc_id((((phys_addr_t)(((phys_addr_t)(((hyp_page_to_pfn(p))) << 12))) - hyp_physvirt_offset)), (cn_virt_ptr)), 0, ((1UL) << 12) << p->order);\n       ^./driver.pp.c:1397:8:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap33_cn, O_cn_virt_ptr23_cn, O_hyp_physvirt_offset35_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    //if (phys < pool->range_start || phys >= pool->range_end)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1398:3-55");
  struct hyp_pool_cn* a_11695 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_11695->free_area = H2_cn->pool->free_area;
  a_11695->range_start = H_cn->pool->range_start;
  a_11695->range_end = H_cn->pool->range_end;
  a_11695->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(a_11695, H2_cn->pool), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    //    goto insert;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1399:3-106");
  cn_bool* a_11750 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL))), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_lt(p_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        a_11750 = cn_bool_and(a_11750, cn_bool_or(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL)), struct_hyp_page_cn_equality((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H2_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)), (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_11750, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
static struct hyp_page *__hyp_extract_page(struct hyp_pool *pool,
                       struct hyp_page *p,
                       u8 order)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires (alloc_id) __hyp_vmemmap == (alloc_id) p; 
  take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), H.pool.range_start / page_size(), H.pool.range_end / page_size(), p); 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  let p_order = (H.vmemmap[p_i]).order; 
  H.vmemmap[p_i].refcount == 0u16; 
  (H.APs[p_i]).prev == array_shift<struct list_head>(&(pool->free_area), p_order); 
  order <= p_order; p_order != (hyp_no_order ()); 
  order_aligned(p_i, order); 
  let start_i = H.pool.range_start / (page_size()); 
  let end_i = H.pool.range_end / page_size(); 
 ensures take H2 = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, p_i * page_size()); 
  take ZR = ZeroPage(virt, true, order); 
  {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  H2.pool == {free_area: (H2.pool).free_area, ..H.pool}; 
  return == p; 
  let p_page = H2.vmemmap[p_i]; 
  p_page.refcount == 0u16; p_page.order == order; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  struct hyp_page* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_bits_u8* order_cn = convert_to_cn_bits_u8(order);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_pointer* O___hyp_vmemmap35_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_bits_i64* O_hyp_physvirt_offset37_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_pointer* O_cn_virt_ptr25_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take H2 = Hyp_pool_ex1(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset, p_i); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1468:11-52");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, p_i * page_size()); \n       ^./driver.pp.c:1469:8:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, O___hyp_vmemmap35_cn, O_cn_virt_ptr25_cn, O_hyp_physvirt_offset37_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take ZR = ZeroPage(virt, true, order); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1470:3-132");
  cn_assert(cellPointer(O___hyp_vmemmap35_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), cn_bits_u64_divide(H_cn->pool->range_start, page_size()), cn_bits_u64_divide(H_cn->pool->range_end, page_size()), p_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap35_cn, p_cn);
  cn_bits_u8* p_order_cn;
  p_order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("  return == p; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1473:3-35");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let p_page = H2.vmemmap[p_i]; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1474:3-83");
  cn_assert(cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(H_cn->APs, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->prev, cn_array_shift(cn_member_shift(pool_cn, hyp_pool, free_area), sizeof(struct list_head), p_order_cn)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  p_page.refcount == 0u16; p_page.order == order; @*/\n  ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1475:3-20");
  cn_assert(cn_bits_u8_le(order_cn, p_order_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  p_page.refcount == 0u16; p_page.order == order; @*/\n                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1475:21-50");
  cn_assert(cn_bool_not(cn_bits_u8_equality(p_order_cn, hyp_no_order())), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1476:3-29");
  cn_assert(order_aligned(p_i_cn, order_cn), PRE);
  cn_pop_msg_info();
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(H_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(H_cn->pool->range_end, page_size());
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((&order), sizeof(unsigned char), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
    /* struct hyp_page *buddy; */
    struct hyp_page *buddy = ((void *)0);
c_add_to_ghost_state((&buddy), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* buddy_addr_cn = convert_to_cn_pointer((&buddy));

    (
({
  ghost_call_site = EMPTY;
  0;
})
, page_remove_from_list_pool(CN_LOAD(pool), CN_LOAD(p)));
    /*CN*/update_cn_error_message_info("      let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, p_i * page_size()); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1491:14-75");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("      let i_p_order = V_I[p_i].order; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1492:14-84");

cn_pop_msg_info();

    /*while (p->order > order)*/
    /*CN*/{
struct loop_ownership* a_11961;

cn_pointer* O_buddy6;

cn_pointer* O_pool21;

cn_pointer* O_p21;

cn_bits_u8* O_order9;

cn_pointer* O___hyp_vmemmap37;

cn_bits_i64* O_hyp_physvirt_offset39;

cn_pointer* O_cn_virt_ptr27;

cn_pointer* vmemmap_l;

struct Hyp_pool_ex1_record* H_I;

struct hyp_pool_cn* a_12017;

cn_map* V_I;

cn_pointer* virt;

cn_bits_u8* i_p_order;

cn_pointer* read_pool4;

struct hyp_pool_cn* deref_read_pool40;

cn_pointer* read___hyp_vmemmap44;

cn_pointer* read_p44;

cn_pointer* read_p45;

struct hyp_page_cn* deref_read_p450;

cn_pointer* read_p46;

struct hyp_page_cn* deref_read_p460;

cn_pointer* read___hyp_vmemmap45;

cn_pointer* read_p47;

cn_pointer* read_p48;

struct hyp_page_cn* deref_read_p480;

cn_pointer* read___hyp_vmemmap46;

cn_pointer* read_pool5;

struct hyp_pool_cn* deref_read_pool50;

cn_pointer* read_p50;

cn_pointer* read___hyp_vmemmap49;

cn_pointer* read_p51;

cn_pointer* read_p52;

struct hyp_page_cn* deref_read_p520;

cn_pointer* read_p53;

struct hyp_page_cn* deref_read_p530;
while (({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_11961 = initialise_loop_ownership_state();
  update_cn_error_message_info("      order <= i_p_order; i_p_order != hyp_no_order (); i_p_order < (max_order ()); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1494:11-1529:6");
  O_buddy6 = owned_struct_hyp_page_pointer(buddy_addr_cn, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("      order <= i_p_order; i_p_order != hyp_no_order (); i_p_order < (max_order ()); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1494:11-1529:6");
  O_pool21 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("      order <= i_p_order; i_p_order != hyp_no_order (); i_p_order < (max_order ()); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1494:11-1529:6");
  O_p21 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("      order <= i_p_order; i_p_order != hyp_no_order (); i_p_order < (max_order ()); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1494:11-1529:6");
  O_order9 = owned_unsigned_char(order_addr_cn, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  O___hyp_vmemmap37 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  O_hyp_physvirt_offset39 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  O_cn_virt_ptr27 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_11961);
  cn_pop_msg_info();
  vmemmap_l = O___hyp_vmemmap37;
  update_cn_error_message_info("    {\n           ^./driver.pp.c:1496:12:");
  H_I = Hyp_pool_ex1(O_pool21, vmemmap_l, O_cn_virt_ptr27, O_hyp_physvirt_offset39, p_i_cn, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1497:7-61");
  a_12017 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_12017->free_area = H_I->pool->free_area;
  a_12017->range_start = H_cn->pool->range_start;
  a_12017->range_end = H_cn->pool->range_end;
  a_12017->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H_I->pool, a_12017), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/if (!(p->order > order)) break;\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1498:7-33");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap37, O___hyp_vmemmap35_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/if (!(p->order > order)) break;\n                                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1498:34-66");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset39, O_hyp_physvirt_offset37_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1499:7-33");
  cn_assert(order_aligned(p_i_cn, O_order9), LOOP);
  cn_pop_msg_info();
  V_I = H_I->vmemmap;
  update_cn_error_message_info("         * is covered by a higher-level page (whose head is @p). Use\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1501:7-33");
  cn_assert(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V_I, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount, convert_to_cn_bits_u16(0ULL)), LOOP);
  cn_pop_msg_info();
  virt = cn__hyp_va(O_cn_virt_ptr27, O_hyp_physvirt_offset39, cn_bits_u64_multiply(p_i_cn, page_size()));
  i_p_order = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V_I, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("         */\n           ^./driver.pp.c:1504:12:");
  ZeroPage(virt, convert_to_cn_bool(true), i_p_order, LOOP, a_11961);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p); @*/\n      ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1505:7-26");
  cn_assert(cn_bits_u8_le(O_order9, i_p_order), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p); @*/\n                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1505:27-56");
  cn_assert(cn_bool_not(cn_bits_u8_equality(i_p_order, hyp_no_order())), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p); @*/\n                                                        ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1505:57-84");
  cn_assert(cn_bits_u8_lt(i_p_order, max_order()), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply order_dec_inv((*pool).range_end, cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order, (*p).order - 1u8); @*/\n      ^~~~~~~~~~~~~~ ./driver.pp.c:1506:7-21");
  cn_assert(cn_pointer_equality(O_p21, p_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply order_dec_inv((*pool).range_end, cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order, (*p).order - 1u8); @*/\n                     ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1506:22-39");
  cn_assert(cn_pointer_equality(O_pool21, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply order_dec_inv((*pool).range_end, cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order, (*p).order - 1u8); @*/\n                                       ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1506:40-58");
  cn_assert(cn_bits_u8_equality(O_order9, order_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate freeArea_cell_wf, (*p).order - 1u8;@*/\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1508:18-88");
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@ apply page_size_of_order_inc((*p).order); @*/\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1516:18-81");
  cn_pop_msg_info();
  update_cn_error_message_info("        page_add_to_list_pool_ex1(pool, buddy, &pool->free_area[buddy->order], p);\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1517:18-127");
  read_pool4 = convert_to_cn_pointer(cn_pointer_deref(pool_addr_cn, struct hyp_pool*));
  deref_read_pool40 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool4, struct hyp_pool));
  read___hyp_vmemmap44 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_p44 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_p45 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p450 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p45, struct hyp_page));
  read_p46 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p460 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p46, struct hyp_page));
  update_cn_error_message_info("        page_add_to_list_pool_ex1(pool, buddy, &pool->free_area[buddy->order], p);\n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1517:19-125");
  order_dec_inv(deref_read_pool40->range_end, cn_hyp_page_to_pfn(read___hyp_vmemmap44, read_p44), deref_read_p450->order, cn_bits_u8_sub(deref_read_p460->order, convert_to_cn_bits_u8(1UL)));
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1518:18-82");
  read___hyp_vmemmap45 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_p47 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_p48 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p480 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p48, struct hyp_page));
  update_cn_error_message_info("    }\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1518:18-80");
  lemma4(cn_hyp_page_to_pfn(read___hyp_vmemmap45, read_p47), deref_read_p480->order);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1519:18-66");
  cn_pop_msg_info();
  update_cn_error_message_info("    return p;\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1520:18-76");
  read___hyp_vmemmap46 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_pool5 = convert_to_cn_pointer(cn_pointer_deref(pool_addr_cn, struct hyp_pool*));
  deref_read_pool50 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool5, struct hyp_pool));
  read_p50 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  update_cn_error_message_info("    return p;\n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1520:19-74");
  order_align_inv_loop(read___hyp_vmemmap46, V_I, deref_read_pool50, read_p50);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1523:18-83");
  cn_pop_msg_info();
  update_cn_error_message_info(" requires (alloc_id) __hyp_vmemmap == (alloc_id) p; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1524:18-92");
  cn_pop_msg_info();
  update_cn_error_message_info("  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1526:18-86");
  read___hyp_vmemmap49 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_p51 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_p52 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p520 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p52, struct hyp_page));
  update_cn_error_message_info("  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); \n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1526:19-84");
  extract_l(cn_hyp_page_to_pfn(read___hyp_vmemmap49, read_p51), deref_read_p520->order);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("  let phys = p_i * page_size(); \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1527:18-62");
  read_p53 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p530 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p53, struct hyp_page));
  update_cn_error_message_info("  let phys = p_i * page_size(); \n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1527:19-60");
  page_size_of_order_inc(deref_read_p530->order);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("  H.pool.range_start <= phys; phys < H.pool.range_end; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1530:14-76");
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_11961);
  cn_bump_free_after(cn_frame_id);
  0;
})
, 1)
    /*@ inv let vmemmap_l = __hyp_vmemmap; 
      take H_I = Hyp_pool_ex1(pool, vmemmap_l, cn_virt_ptr, hyp_physvirt_offset, p_i); 
      H_I.pool == {free_area: H_I.pool.free_area, ..H.pool}; 
      {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
      order_aligned(p_i, order); 
      let V_I = H_I.vmemmap; 
      V_I[p_i].refcount == 0u16; 
      let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, p_i * page_size()); 
      let i_p_order = V_I[p_i].order; 
      take ZI = ZeroPage(virt, true, i_p_order); 
      order <= i_p_order; i_p_order != hyp_no_order (); i_p_order < (max_order ()); 
      {p} unchanged; {pool} unchanged; {order} unchanged; @*/
    {
        /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/
        /*CN*/if (!(CN_LOAD(CN_LOAD(p)->order) > CN_LOAD(order))) break;
        /*
         * The buddy of order n - 1 currently has HYP_NO_ORDER as it
         * is covered by a higher-level page (whose head is @p). Use
         * __find_buddy_nocheck() to find it and inject it in the
         * free_list[n - 1], effectively splitting @p in half.
         */
        /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,p); @*/
        /*CN*//*@ apply order_dec_inv((*pool).range_end, cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order, (*p).order - 1u8); @*/
        /*CN*//*@apply lemma4(cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order); @*/
        /*CN*//*@instantiate freeArea_cell_wf, (*p).order - 1u8;@*/
        /*CN*//*@ apply order_align_inv_loop(__hyp_vmemmap,V_I,*pool, p); @*/
        CN_POSTFIX(CN_LOAD(p)->order, --);
        CN_STORE(buddy, __find_buddy_nocheck(CN_LOAD(pool), CN_LOAD(p), CN_LOAD(CN_LOAD(p)->order)));
        /*CN*//*@instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap,buddy);@*/
        /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, buddy);@*/
        CN_STORE(CN_LOAD(buddy)->order, CN_LOAD(CN_LOAD(p)->order));
        /*CN*//*@ apply extract_l(cn_hyp_page_to_pfn(__hyp_vmemmap,p), (*p).order); @*/
        /*CN*//*@ apply page_size_of_order_inc((*p).order); @*/
        page_add_to_list_pool_ex1(CN_LOAD(pool), CN_LOAD(buddy), &CN_LOAD(pool)->free_area[CN_LOAD(CN_LOAD(buddy)->order)], CN_LOAD(p));
    }}
    /*CN*/update_cn_error_message_info("  H.pool.range_start <= phys; phys < H.pool.range_end; \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1530:14-76");

cn_pop_msg_info();

    { __cn_ret = CN_LOAD(p); 
c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));
goto __cn_epilogue; }

c_remove_from_ghost_state((&buddy), sizeof(struct hyp_page*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&order), sizeof(unsigned char));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_pointer* O___hyp_vmemmap36_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_bits_i64* O_hyp_physvirt_offset38_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let end_i = H.pool.range_end / page_size(); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1467:5-62");
  cn_pointer* O_cn_virt_ptr26_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    page_remove_from_list_pool(pool, p);\n              ^./driver.pp.c:1479:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool_ex1(pool_cn, O___hyp_vmemmap36_cn, O_cn_virt_ptr26_cn, O_hyp_physvirt_offset38_cn, p_i_cn, POST, 0);
  cn_pop_msg_info();
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr26_cn, O_hyp_physvirt_offset38_cn, cn_bits_u64_multiply(p_i_cn, page_size()));
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p);@*/\n       ^./driver.pp.c:1481:8:");
  ZeroPage(virt_cn, convert_to_cn_bool(true), order_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*while (p->order > order)*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1482:3-29");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap36_cn, O___hyp_vmemmap35_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*while (p->order > order)*/\n                             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1482:30-62");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset38_cn, O_hyp_physvirt_offset37_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*/while (1)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1483:3-57");
  struct hyp_pool_cn* a_12382 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_12382->free_area = H2_cn->pool->free_area;
  a_12382->range_start = H_cn->pool->range_start;
  a_12382->range_end = H_cn->pool->range_end;
  a_12382->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_12382), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ inv let vmemmap_l = __hyp_vmemmap; \n  ^~~~~~~~~~~~ ./driver.pp.c:1484:3-15");
  cn_assert(cn_pointer_equality(return_cn, p_cn), POST);
  cn_pop_msg_info();
  struct hyp_page_cn* p_page_cn;
  p_page_cn = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H2_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn));
  update_cn_error_message_info("      H_I.pool == {free_area: H_I.pool.free_area, ..H.pool}; \n  ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1486:3-27");
  cn_assert(cn_bits_u16_equality(p_page_cn->refcount, convert_to_cn_bits_u16(0ULL)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("      H_I.pool == {free_area: H_I.pool.free_area, ..H.pool}; \n                           ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1486:28-50");
  cn_assert(cn_bits_u8_equality(p_page_cn->order, order_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
static void __hyp_put_page(struct hyp_pool *pool, struct hyp_page *p)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; 
 requires (alloc_id) __hyp_vmemmap == (alloc_id) p; 
  take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  let p_i = cn_hyp_page_to_pfn(__hyp_vmemmap, p); 
  let phys = p_i * page_size(); 
  let start_i = H.pool.range_start / (page_size()); 
  let end_i = H.pool.range_end / page_size(); 
  H.pool.range_start <= phys; phys < H.pool.range_end; 
  let refcount = (H.vmemmap[p_i]).refcount; 
  cellPointer(__hyp_vmemmap, (u64) (sizeof<struct hyp_page>), start_i, end_i, p); 
  refcount > 0u16; 
  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); 
  take P = Page(virt, (refcount == 1u16), H.vmemmap[p_i].order); 
 ensures take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; 
  H2.pool == {free_area:H2.pool.free_area, .. H.pool}; 
  each (u64 i; p_i < i && i < end_i){(H.vmemmap[i].refcount == 0u16) || (H2.vmemmap[i] == H.vmemmap[i])}; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_bits_i64* O_hyp_physvirt_offset40_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_pointer* O___hyp_vmemmap38_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_pointer* O_cn_virt_ptr28_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take P = Page(virt, (refcount == 1u16), H.vmemmap[p_i].order); \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1535:11-52");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info(" ensures take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n       ^./driver.pp.c:1536:8:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, O___hyp_vmemmap38_cn, O_cn_virt_ptr28_cn, O_hyp_physvirt_offset40_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_hyp_page_to_pfn(O___hyp_vmemmap38_cn, p_cn);
  cn_bits_u64* phys_cn;
  phys_cn = cn_bits_u64_multiply(p_i_cn, page_size());
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(H_cn->pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(H_cn->pool->range_end, page_size());
  update_cn_error_message_info("    /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap, p); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1541:3-30");
  cn_assert(cn_bits_u64_le(H_cn->pool->range_start, phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@ instantiate vmemmap_wf, cn_hyp_page_to_pfn(__hyp_vmemmap, p); @*/\n                              ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1541:31-55");
  cn_assert(cn_bits_u64_lt(phys_cn, H_cn->pool->range_end), PRE);
  cn_pop_msg_info();
  cn_bits_u16* refcount_cn;
  refcount_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount;
  update_cn_error_message_info("    /*CN*//*@ extract Owned<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, p); @*/\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1543:3-82");
  cn_assert(cellPointer(O___hyp_vmemmap38_cn, cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))), start_i_cn, end_i_cn, p_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    if (hyp_page_ref_dec_and_test(p)) {\n  ^~~~~~~~~~~~~~~~ ./driver.pp.c:1544:3-19");
  cn_assert(cn_bits_u16_lt(convert_to_cn_bits_u16(0ULL), refcount_cn), PRE);
  cn_pop_msg_info();
  cn_pointer* virt_cn;
  virt_cn = cn__hyp_va(O_cn_virt_ptr28_cn, O_hyp_physvirt_offset40_cn, phys_cn);
  update_cn_error_message_info("    }\n       ^./driver.pp.c:1546:8:");
  Page(virt_cn, cn_bits_u16_equality(refcount_cn, convert_to_cn_bits_u16(1ULL)), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order, PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  
    /*CN*/update_cn_error_message_info(" * section to guarantee transient states (e.g. a page with null refcount but\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1552:14-78");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info(" * not yet attached to a free list) can't be observed by well-behaved readers.\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1553:14-89");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info(" */\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1554:14-86");

cn_pop_msg_info();

    if ((
({
  ghost_call_site = EMPTY;
  0;
})
, hyp_page_ref_dec_and_test(CN_LOAD(p)))) {
        (
({
  ghost_call_site = EMPTY;
  0;
})
, __hyp_attach_page(CN_LOAD(pool), CN_LOAD(p)));
    }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

{
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_bits_i64* O_hyp_physvirt_offset41_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_pointer* O___hyp_vmemmap39_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  let virt = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, phys); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1534:5-62");
  cn_pointer* O_cn_virt_ptr29_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n              ^./driver.pp.c:1547:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap39_cn, O_cn_virt_ptr29_cn, O_hyp_physvirt_offset41_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/*\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1548:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset41_cn, O_hyp_physvirt_offset40_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("/*\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1548:36-62");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap39_cn, O___hyp_vmemmap38_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" * Changes to the buddy tree and page refcounts must be done with the hyp_pool\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1549:3-55");
  struct hyp_pool_cn* a_12635 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_12635->free_area = H2_cn->pool->free_area;
  a_12635->range_start = H_cn->pool->range_start;
  a_12635->range_end = H_cn->pool->range_end;
  a_12635->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_12635), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" * lock held. If a refcount change requires an update to the buddy tree (e.g.\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1550:3-106");
  cn_bool* a_12690 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(p_i_cn, convert_to_cn_bits_u64(1ULL))), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_lt(p_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        a_12690 = cn_bool_and(a_12690, cn_bool_or(cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL)), struct_hyp_page_cn_equality((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H2_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)), (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(i)))));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_12690, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
/*
 * Changes to the buddy tree and page refcounts must be done with the hyp_pool
 * lock held. If a refcount change requires an update to the buddy tree (e.g.
 * hyp_put_page()), both operations must be done within the same critical
 * section to guarantee transient states (e.g. a page with null refcount but
 * not yet attached to a free list) can't be observed by well-behaved readers.
 */
void hyp_put_page(struct hyp_pool *pool, void *addr)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; 
 requires (alloc_id) addr == (alloc_id) cn_virt_ptr; 
  take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  let phys = cn__hyp_pa(hyp_physvirt_offset, addr); 
  H.pool.range_start <= phys; phys < H.pool.range_end; 
  (mod(phys,page_size())) == 0u64; addr != NULL; 
  let page_i = phys / page_size(); 
  let refcount = (H.vmemmap[page_i]).refcount; 
  refcount > 0u16; 
  take P = Page(addr, (refcount == 1u16), H.vmemmap[page_i].order); 
 ensures take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; 
  H2.pool == {free_area: H2.pool.free_area,.. H.pool}; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_bits_i64* O_hyp_physvirt_offset11_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_pointer* O___hyp_vmemmap9_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_pointer* O_cn_virt_ptr5_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  H2.pool == {free_area: H2.pool.free_area,.. H.pool}; @*/\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1568:11-53");
  cn_assert(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("{\n       ^./driver.pp.c:1569:8:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, O___hyp_vmemmap9_cn, O_cn_virt_ptr5_cn, O_hyp_physvirt_offset11_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* phys_cn;
  phys_cn = cn__hyp_pa(O_hyp_physvirt_offset11_cn, addr_cn);
  update_cn_error_message_info("    /* hyp_spin_lock(&pool->lock); */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1571:3-30");
  cn_assert(cn_bits_u64_le(H_cn->pool->range_start, phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* hyp_spin_lock(&pool->lock); */\n                              ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1571:31-55");
  cn_assert(cn_bits_u64_lt(phys_cn, H_cn->pool->range_end), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    __hyp_put_page(pool, p);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1572:3-35");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(phys_cn, page_size()), convert_to_cn_bits_u64(0ULL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    __hyp_put_page(pool, p);\n                                   ^~~~~~~~~~~~~ ./driver.pp.c:1572:36-49");
  cn_assert(cn_bool_not(cn_pointer_equality(addr_cn, convert_to_cn_pointer(0))), PRE);
  cn_pop_msg_info();
  cn_bits_u64* page_i_cn;
  page_i_cn = cn_bits_u64_divide(phys_cn, page_size());
  cn_bits_u16* refcount_cn;
  refcount_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(page_i_cn)))->refcount;
  update_cn_error_message_info("/* void hyp_get_page(void *addr) */\n  ^~~~~~~~~~~~~~~~ ./driver.pp.c:1575:3-19");
  cn_assert(cn_bits_u16_lt(convert_to_cn_bits_u16(0ULL), refcount_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("void hyp_get_page(struct hyp_pool *pool, void *addr)\n       ^./driver.pp.c:1576:8:");
  Page(addr_cn, cn_bits_u16_equality(refcount_cn, convert_to_cn_bits_u16(1ULL)), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(page_i_cn)))->order, PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&addr), sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
    struct hyp_page *p = (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[((((phys_addr_t)CN_LOAD((addr)) + CN_LOAD(hyp_physvirt_offset))) >> 12)]);
c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

    /* hyp_spin_lock(&pool->lock); */
    (
({
  ghost_call_site = EMPTY;
  0;
})
, __hyp_put_page(CN_LOAD(pool), CN_LOAD(p)));
    /* hyp_spin_unlock(&pool->lock); */

c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&addr), sizeof(void*));

{
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_bits_i64* O_hyp_physvirt_offset12_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_pointer* O___hyp_vmemmap10_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1567:5-62");
  cn_pointer* O_cn_virt_ptr6_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; \n              ^./driver.pp.c:1577:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap10_cn, O_cn_virt_ptr6_cn, O_hyp_physvirt_offset12_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1578:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset12_cn, O_hyp_physvirt_offset11_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1578:36-62");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap10_cn, O___hyp_vmemmap9_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("  let phys = cn__hyp_pa(hyp_physvirt_offset, addr); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1579:3-55");
  struct hyp_pool_cn* a_7320 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_7320->free_area = H2_cn->pool->free_area;
  a_7320->range_start = H_cn->pool->range_start;
  a_7320->range_end = H_cn->pool->range_end;
  a_7320->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_7320), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
/* void hyp_get_page(void *addr) */
void hyp_get_page(struct hyp_pool *pool, void *addr)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; 
 requires take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  let phys = cn__hyp_pa(hyp_physvirt_offset, addr); 
  let page_i = phys / page_size(); 
  H.pool.range_start <= phys; phys < H.pool.range_end; 
  (H.vmemmap[page_i]).refcount > 0u16; 
  (H.vmemmap[page_i]).refcount <= shift_left(1u16,16u16) - 2u16; 
 ensures take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  {hyp_physvirt_offset} unchanged; {__hyp_vmemmap} unchanged; 
  H2.pool == H.pool; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_bits_i64* O_hyp_physvirt_offset9_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_pointer* O___hyp_vmemmap7_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_pointer* O_cn_virt_ptr3_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* hyp_spin_lock(&pool->lock); */\n               ^./driver.pp.c:1589:16:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, O___hyp_vmemmap7_cn, O_cn_virt_ptr3_cn, O_hyp_physvirt_offset9_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* phys_cn;
  phys_cn = cn__hyp_pa(O_hyp_physvirt_offset9_cn, addr_cn);
  cn_bits_u64* page_i_cn;
  page_i_cn = cn_bits_u64_divide(phys_cn, page_size());
  update_cn_error_message_info("    hyp_page_ref_inc(p);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1592:3-30");
  cn_assert(cn_bits_u64_le(H_cn->pool->range_start, phys_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    hyp_page_ref_inc(p);\n                              ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1592:31-55");
  cn_assert(cn_bits_u64_lt(phys_cn, H_cn->pool->range_end), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* hyp_spin_unlock(&pool->lock); */\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1593:3-39");
  cn_assert(cn_bits_u16_lt(convert_to_cn_bits_u16(0ULL), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(page_i_cn)))->refcount), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1594:3-65");
  cn_assert(cn_bits_u16_le(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H_cn->vmemmap, cast_cn_bits_u64_to_cn_integer(page_i_cn)))->refcount, cn_bits_u16_sub(cn_bits_u16_shift_left(convert_to_cn_bits_u16(1ULL), convert_to_cn_bits_u16(16ULL)), convert_to_cn_bits_u16(2ULL))), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&addr), sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
    struct hyp_page *p = (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[((((phys_addr_t)CN_LOAD((addr)) + CN_LOAD(hyp_physvirt_offset))) >> 12)]);
c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

    /* hyp_spin_lock(&pool->lock); */
    /*CN*/update_cn_error_message_info("//     for (i = 1; i < (1 << order); i++) {\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1601:14-86");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("//         struct hyp_page *tail = p + i;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1602:14-55");

update_cn_error_message_info("//         struct hyp_page *tail = p + i;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1602:14-53");

cn_pop_msg_info();

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, hyp_page_ref_inc(CN_LOAD(p)));
    /* hyp_spin_unlock(&pool->lock); */

c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&addr), sizeof(void*));

{
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_bits_i64* O_hyp_physvirt_offset10_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_pointer* O___hyp_vmemmap8_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_page *p = (&((struct hyp_page *)__hyp_vmemmap)[((((phys_addr_t)(addr) + hyp_physvirt_offset)) >> 12)]);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1588:5-62");
  cn_pointer* O_cn_virt_ptr4_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("// void hyp_split_page(struct hyp_page *p)\n              ^./driver.pp.c:1595:15:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap8_cn, O_cn_virt_ptr4_cn, O_hyp_physvirt_offset10_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("// {\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1596:3-35");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset10_cn, O_hyp_physvirt_offset9_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("// {\n                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1596:36-62");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap8_cn, O___hyp_vmemmap7_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("//     u8 order = p->order;\n  ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1597:3-21");
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, H_cn->pool), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);
}
// void hyp_split_page(struct hyp_page *p)
// {
//     u8 order = p->order;
//     unsigned int i;
//
//     p->order = 0;
//     for (i = 1; i < (1 << order); i++) {
//         struct hyp_page *tail = p + i;
//
//         tail->order = 0;
//         hyp_set_page_refcounted(tail);
//     }
// }
void *hyp_alloc_pages(struct hyp_pool *pool, u8 order)
/*@ accesses hyp_physvirt_offset, __hyp_vmemmap, cn_virt_ptr; 
 requires take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  0i64 <= hyp_physvirt_offset;  // FIXME from node_to_page, suspicious
 ensures  take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset);
             take ZR = ZeroPage(return, (return != NULL), order);
             {__hyp_vmemmap} unchanged;
             {hyp_physvirt_offset} unchanged;
             H2.pool == {free_area: H2.pool.free_area, ..H.pool}; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_bits_u8* order_cn = convert_to_cn_bits_u8(order);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_bits_i64* O_hyp_physvirt_offset6_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_pointer* O___hyp_vmemmap4_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_pointer* O_cn_virt_ptr0_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Look for a high-enough-order page */\n               ^./driver.pp.c:1621:16:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(pool_cn, O___hyp_vmemmap4_cn, O_cn_virt_ptr0_cn, O_hyp_physvirt_offset6_cn, PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    while /*CN(i < pool->max_order && list_empty(&pool->free_area[i]))*/ (1)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1622:3-31");
  cn_assert(cn_bits_i64_le(convert_to_cn_bits_i64(0LL), O_hyp_physvirt_offset6_cn), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&order), sizeof(unsigned char), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
    struct hyp_page *p = ((void *)0);
c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
 /* struct hyp_page *p; */
    u8 i = CN_LOAD(order);
c_add_to_ghost_state((&i), sizeof(unsigned char), get_cn_stack_depth());


cn_pointer* i_addr_cn = convert_to_cn_pointer((&i));

    /* ----- hyp_spin_lock(&pool- >lock); */
    /* Look for a high-enough-order page */
    {
struct loop_ownership* a_6707;

cn_pointer* O_p2;

cn_bits_u8* O_i2;

cn_pointer* O_pool2;

cn_bits_u8* O_order2;

cn_bits_i64* O_hyp_physvirt_offset8;

cn_pointer* O___hyp_vmemmap6;

cn_pointer* O_cn_virt_ptr2;

struct Hyp_pool_ex1_record* H_I;

cn_pointer* read___hyp_vmemmap8;

cn_pointer* read_p9;

cn_pointer* read_p10;

struct hyp_page_cn* deref_read_p100;

cn_bits_u8* read_order1;
while /*CN(i < pool->max_order && list_empty(&pool->free_area[i]))*/ (({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_6707 = initialise_loop_ownership_state();
  update_cn_error_message_info("        /*CN*/}\n    ^~~~~~~~~~~ ./driver.pp.c:1633:5-1644:16");
  O_p2 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/}\n    ^~~~~~~~~~~ ./driver.pp.c:1633:5-1644:16");
  O_i2 = owned_unsigned_char(i_addr_cn, LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/}\n    ^~~~~~~~~~~ ./driver.pp.c:1633:5-1644:16");
  O_pool2 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/}\n    ^~~~~~~~~~~ ./driver.pp.c:1633:5-1644:16");
  O_order2 = owned_unsigned_char(order_addr_cn, LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  O_hyp_physvirt_offset8 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  O___hyp_vmemmap6 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  O_cn_virt_ptr2 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("    if (i >= pool->max_order) {\n                     ^./driver.pp.c:1634:22:");
  H_I = Hyp_pool(O_pool2, O___hyp_vmemmap6, O_cn_virt_ptr2, O_hyp_physvirt_offset8, LOOP, a_6707);
  cn_pop_msg_info();
  update_cn_error_message_info("        /* ----- hyp_spin_unlock(&pool->lock); */\n            ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1635:13-38");
  cn_assert(cn_map_equality(H_I->vmemmap, H_cn->vmemmap, struct_hyp_page_cn_equality), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /* ----- hyp_spin_unlock(&pool->lock); */\n                                      ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1635:39-58");
  cn_assert(struct_hyp_pool_cn_equality(H_I->pool, H_cn->pool), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    //cn_print_nr_u64(555555, 555555);\n            ^~~~~~~~~~~ ./driver.pp.c:1636:13-24");
  cn_assert(cn_bits_u8_le(O_order2, O_i2), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    //cn_print_nr_u64(555555, 555555);\n                        ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1636:25-50");
  cn_assert(cn_bits_u8_le(H_cn->pool->max_order, convert_to_cn_bits_u8(11UL)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        return ((void *)0);\n            ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1637:13-30");
  cn_assert(cn_pointer_equality(O_pool2, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        return ((void *)0);\n                              ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1637:31-49");
  cn_assert(cn_bits_u8_equality(O_order2, order_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n            ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1638:13-39");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap6, O___hyp_vmemmap4_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n                                       ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1638:40-72");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset8, O_hyp_physvirt_offset6_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@extract Owned<struct list_head>, (u64) i;@*/\n                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1640:23-65");
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Extract it from the tree at the right order */\n                      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1641:23-61");
  cn_pop_msg_info();
  update_cn_error_message_info("    hyp_set_page_refcounted(p);\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1650:14-54");
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_unlock(&pool->lock); */\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1651:14-56");
  cn_pop_msg_info();
  update_cn_error_message_info("/* SPDX-License-Identifier: GPL-2.0 */\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1655:14-77");
  cn_pop_msg_info();
  update_cn_error_message_info("//#ifndef __ASM_GENERIC_GETORDER_H\n                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1656:27-98");
  cn_pop_msg_info();
  update_cn_error_message_info("//#define __ASM_GENERIC_GETORDER_H\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1657:14-111");
  read___hyp_vmemmap8 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_p9 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  read_p10 = convert_to_cn_pointer(cn_pointer_deref(p_addr_cn, struct hyp_page*));
  deref_read_p100 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p10, struct hyp_page));
  read_order1 = convert_to_cn_bits_u8(cn_pointer_deref(order_addr_cn, unsigned char));
  update_cn_error_message_info("//#define __ASM_GENERIC_GETORDER_H\n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1657:15-109");
  order_dec_inv(H_cn->pool->range_end, cn_hyp_page_to_pfn(read___hyp_vmemmap8, read_p9), deref_read_p100->order, read_order1);
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("//#include <linux/log2.h>\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1660:14-88");
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_6707);
  cn_bump_free_after(cn_frame_id);
  0;
})
, 1)
        /*@ inv take H_I = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset);
            H_I.vmemmap == H.vmemmap; H_I.pool == H.pool;
            order <= i; H.pool.max_order <= 11u8;
            {pool} unchanged; {order} unchanged;
            {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; @*/
        /*CN*/{
            /*CN*/ /*@extract Owned<struct list_head>, (u64) i;@*/
            /*CN*/ /*@instantiate freeArea_cell_wf, (u8) i;@*/
            /*CN*/if (!(CN_LOAD(i) < CN_LOAD(CN_LOAD(pool)->max_order) && list_empty(&CN_LOAD(pool)->free_area[CN_LOAD(i)]))) break;
            CN_POSTFIX(i, ++);
        /*CN*/}}
    if (CN_LOAD(i) >= CN_LOAD(CN_LOAD(pool)->max_order)) {
        /* ----- hyp_spin_unlock(&pool->lock); */
    //cn_print_nr_u64(555555, 555555);
        { __cn_ret = ((void *)0); 
c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&i), sizeof(unsigned char));
goto __cn_epilogue; }
    }
    /*CN*/update_cn_error_message_info("    hyp_set_page_refcounted(p);\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1650:14-54");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("    /* ----- hyp_spin_unlock(&pool->lock); */\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1651:14-56");

cn_pop_msg_info();

    /* Extract it from the tree at the right order */
    CN_STORE(p, (
({
  ghost_call_site = EMPTY;
  0;
})
, node_to_page(CN_LOAD(CN_LOAD(pool)->free_area[CN_LOAD(i)].next))));
    // p = hyp_virt_to_page(pool->free_area[i].next);
    /*CN*/update_cn_error_message_info("/* SPDX-License-Identifier: GPL-2.0 */\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1655:14-77");

cn_pop_msg_info();

                /*CN*/ update_cn_error_message_info("//#ifndef __ASM_GENERIC_GETORDER_H\n                          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1656:27-98");

cn_pop_msg_info();

    /*CN*/update_cn_error_message_info("//#define __ASM_GENERIC_GETORDER_H\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1657:14-111");

cn_pointer* read___hyp_vmemmap4 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));

cn_pointer* read_p4 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

cn_pointer* read_p5 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&p)), struct hyp_page*));

struct hyp_page_cn* deref_read_p50 = convert_to_struct_hyp_page_cn(cn_pointer_deref(read_p5, struct hyp_page));

cn_bits_u8* read_order0 = convert_to_cn_bits_u8(cn_pointer_deref(convert_to_cn_pointer((&order)), unsigned char));

update_cn_error_message_info("//#define __ASM_GENERIC_GETORDER_H\n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1657:15-109");

order_dec_inv(H_cn->pool->range_end, cn_hyp_page_to_pfn(read___hyp_vmemmap4, read_p4), deref_read_p50->order, read_order0);

cn_pop_msg_info();

cn_pop_msg_info();

    CN_STORE(p, (
({
  ghost_call_site = EMPTY;
  0;
})
, __hyp_extract_page(CN_LOAD(pool), CN_LOAD(p), CN_LOAD(order))));
    /* ----- hyp_spin_unlock(&pool->lock); */
    /*CN*/update_cn_error_message_info("//#include <linux/log2.h>\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1660:14-88");

cn_pop_msg_info();

    (
({
  ghost_call_site = EMPTY;
  0;
})
, hyp_set_page_refcounted(CN_LOAD(p)));
    /* ----- hyp_spin_unlock(&pool->lock); */
    //cn_print_nr_u64(666666, 666666);
    { __cn_ret = (
({
  ghost_call_site = EMPTY;
  0;
})
, copy_alloc_id((((phys_addr_t)(((phys_addr_t)((
({
  ghost_call_site = EMPTY;
  0;
})
, ((hyp_page_to_pfn(CN_LOAD(p))))) << 12))) - CN_LOAD(hyp_physvirt_offset))), CN_LOAD((cn_virt_ptr)))); 
c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&i), sizeof(unsigned char));
goto __cn_epilogue; }

c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&i), sizeof(unsigned char));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&order), sizeof(unsigned char));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_bits_i64* O_hyp_physvirt_offset7_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_pointer* O___hyp_vmemmap5_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* ----- hyp_spin_lock(&pool- >lock); */\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1620:5-62");
  cn_pointer* O_cn_virt_ptr1_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ inv take H_I = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset);\n               ^./driver.pp.c:1623:16:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap5_cn, O_cn_virt_ptr1_cn, O_hyp_physvirt_offset7_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("            H_I.vmemmap == H.vmemmap; H_I.pool == H.pool;\n                  ^./driver.pp.c:1624:19:");
  ZeroPage(return_cn, cn_bool_not(cn_pointer_equality(return_cn, convert_to_cn_pointer(0))), order_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("            order <= i; H.pool.max_order <= 11u8;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1625:14-40");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap5_cn, O___hyp_vmemmap4_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("            {pool} unchanged; {order} unchanged;\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1626:14-46");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset7_cn, O_hyp_physvirt_offset6_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("            {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; @*/\n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1627:14-66");
  struct hyp_pool_cn* a_6968 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_6968->free_area = H2_cn->pool->free_area;
  a_6968->range_start = H_cn->pool->range_start;
  a_6968->range_end = H_cn->pool->range_end;
  a_6968->max_order = H_cn->pool->max_order;
  cn_assert(struct_hyp_pool_cn_equality(H2_cn->pool, a_6968), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/* SPDX-License-Identifier: GPL-2.0 */
//#ifndef __ASM_GENERIC_GETORDER_H
//#define __ASM_GENERIC_GETORDER_H
//#ifndef __ASSEMBLY__
//#include <linux/compiler.h>
//#include <linux/log2.h>
/**
 * get_order - Determine the allocation order of a memory size
 * @size: The size for which to get the order
 *
 * Determine the allocation order of a particular sized block of memory.  This
 * is on a logarithmic scale, where:
 *
 *    0 -> 2^0 * PAGE_SIZE and below
 *    1 -> 2^1 * PAGE_SIZE to 2^0 * PAGE_SIZE + 1
 *    2 -> 2^2 * PAGE_SIZE to 2^1 * PAGE_SIZE + 1
 *    3 -> 2^3 * PAGE_SIZE to 2^2 * PAGE_SIZE + 1
 *    4 -> 2^4 * PAGE_SIZE to 2^3 * PAGE_SIZE + 1
 *    ...
 *
 * The order returned is used to find the smallest allocation granule required
 * to hold an object of the specified size.
 *
 * The result is undefined if the size is 0.
 */
// CP: adding string.h include
//#include <string.h>
long fls64(long x)
{
  /* EXECUTABLE CN PRECONDITION */
  signed long __cn_ret;
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&x), sizeof(signed long), get_cn_stack_depth());
  cn_pointer* x_addr_cn = convert_to_cn_pointer((&x));
  
  long flsl(long);
  { __cn_ret = (
({
  ghost_call_site = EMPTY;
  0;
})
, flsl(CN_LOAD(x))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&x), sizeof(signed long));

return __cn_ret;

}
//#define fls64 flsl
static /*__always_inline __attribute_const__*/ int get_order(unsigned long size)
/*@ trusted; 
    requires size >= page_size();
    ensures return == (i32) get_order_uf(size); 
            return > 0i32; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("        return ilog2((size) - 1) - PAGE_SHIFT + 1;\n             ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1701:14-34");
  cn_assert(cn_bits_u64_le(page_size(), size_cn), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&size), sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
/*    if (__builtin_constant_p(size)) {
        if (!size)
            return BITS_PER_LONG - PAGE_SHIFT;

        if (size < (1UL << PAGE_SHIFT))
            return 0;

        return ilog2((size) - 1) - PAGE_SHIFT + 1;
    }
*/
    CN_POSTFIX(size, --);
    CN_STORE_OP(size,>>,12);
    { __cn_ret = (
({
  ghost_call_site = EMPTY;
  0;
})
, fls64(CN_LOAD(size))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&size), sizeof(unsigned long));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("    }\n            ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1702:13-48");
  cn_assert(cn_bits_i32_equality(return_cn, cast_cn_bits_u8_to_cn_bits_i32(get_order_uf(size_cn))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("*/\n            ^~~~~~~~~~~~~~ ./driver.pp.c:1703:13-27");
  cn_assert(cn_bits_i32_lt(convert_to_cn_bits_i32(0LL), return_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
//#endif    /* __ASSEMBLY__ */
//#endif    /* __ASM_GENERIC_GETORDER_H */
int hyp_pool_init(struct hyp_pool *pool, u64 pfn, unsigned int nr_pages,
          unsigned int reserved_pages)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr; 
 requires nr_pages > 0u32; 
  take O = Owned<struct hyp_pool>(pool); 
  let start_i = pfn; let start = start_i * page_size(); 
  let end_i = start_i + ((u64) nr_pages); let end = end_i * page_size(); 
  reserved_pages < nr_pages; 
// The hyp_pool_wf below does not mention the free area. So the
// hyp_pool_wf constraint is just a short-hand for asking start,
// end, and others to have sensible values.
  let poolv = {range_start: start, range_end: end, max_order: 11u8, ..*pool}; 
  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); 
  take V = each (u64 i; start_i <= i && i < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, i)) }; 
  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); 
  take P = each (u64 i; start_i + ((u64) reserved_pages) <= i && i < end_i)
  { Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, 0u8) }; 
 ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; 
  take H2 = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
  (H2.pool).range_start == start; 
  (H2.pool).range_end == end; 
  (H2.pool).max_order <= 11u8; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_pointer* pool_cn = convert_to_cn_pointer(pool);
  cn_bits_u64* pfn_cn = convert_to_cn_bits_u64(pfn);
  cn_bits_u32* nr_pages_cn = convert_to_cn_bits_u32(nr_pages);
  cn_bits_u32* reserved_pages_cn = convert_to_cn_bits_u32(reserved_pages);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_pointer* O___hyp_vmemmap11_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_bits_i64* O_hyp_physvirt_offset13_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_pointer* O_cn_virt_ptr7_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  take V = each (u64 i; start_i <= i && i < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, i)) }; \n          ^~~~~~~~~~~~~~~~ ./driver.pp.c:1724:11-27");
  cn_assert(cn_bits_u32_lt(convert_to_cn_bits_u32(0ULL), nr_pages_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  let ptr_phys_0 = cn__hyp_va(cn_virt_ptr, hyp_physvirt_offset, 0u64); \n       ^./driver.pp.c:1725:8:");
  struct hyp_pool_cn* O_cn = owned_struct_hyp_pool(pool_cn, PRE, 0);
  cn_pop_msg_info();
  cn_bits_u64* start_i_cn;
  start_i_cn = pfn_cn;
  cn_bits_u64* start_cn;
  start_cn = cn_bits_u64_multiply(start_i_cn, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(nr_pages_cn));
  cn_bits_u64* end_cn;
  end_cn = cn_bits_u64_multiply(end_i_cn, page_size());
  update_cn_error_message_info(" ensures {__hyp_vmemmap} unchanged; {hyp_physvirt_offset} unchanged; \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1728:3-29");
  cn_assert(cn_bits_u32_lt(reserved_pages_cn, nr_pages_cn), PRE);
  cn_pop_msg_info();
  struct hyp_pool_cn* poolv_cn;
  struct hyp_pool_cn* a_7432 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_7432->free_area = O_cn->free_area;
  a_7432->range_start = start_cn;
  a_7432->range_end = O_cn->range_end;
  a_7432->max_order = O_cn->max_order;
  struct hyp_pool_cn* a_7434 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_7434->free_area = a_7432->free_area;
  a_7434->range_start = a_7432->range_start;
  a_7434->range_end = end_cn;
  a_7434->max_order = a_7432->max_order;
  struct hyp_pool_cn* a_7438 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_7438->free_area = a_7434->free_area;
  a_7438->range_start = a_7434->range_start;
  a_7438->range_end = a_7434->range_end;
  a_7438->max_order = convert_to_cn_bits_u8(11UL);
  poolv_cn = a_7438;
  update_cn_error_message_info("{\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1733:3-64");
  cn_assert(hyp_pool_wf(pool_cn, poolv_cn, O___hyp_vmemmap11_cn, O_hyp_physvirt_offset13_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    phys_addr_t phys = ((phys_addr_t)((pfn) << 12));\n       ^./driver.pp.c:1734:8:");
  cn_map* V_cn = map_create();
  {
  cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
  while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
    if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
      cn_pointer* a_7464 = cn_array_shift(O___hyp_vmemmap11_cn, sizeof(struct hyp_page), i);
      cn_map_set(V_cn, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_7464, PRE, 0));
    }
    else {
      ;
    }
    cn_bits_u64_increment(i);
  }
}
  cn_pop_msg_info();
  cn_pointer* ptr_phys_0_cn;
  ptr_phys_0_cn = cn__hyp_va(O_cn_virt_ptr7_cn, O_hyp_physvirt_offset13_cn, convert_to_cn_bits_u64(0ULL));
  update_cn_error_message_info("    /* struct hyp_page *p; */\n       ^./driver.pp.c:1736:8:");
  {
  cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(reserved_pages_cn)));
  while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(reserved_pages_cn))), i), cn_bits_u64_lt(i, end_i_cn)))) {
    if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(reserved_pages_cn)), i), cn_bits_u64_lt(i, end_i_cn)))) {
      cn_pointer* a_7520 = cn_array_shift(ptr_phys_0_cn, sizeof(char[4096]), i);
      Page(a_7520, convert_to_cn_bool(true), convert_to_cn_bits_u8(0UL), PRE, 0);
    }
    else {
      ;
    }
    cn_bits_u64_increment(i);
  }
}
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());
  cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));
  c_add_to_ghost_state((&pfn), sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* pfn_addr_cn = convert_to_cn_pointer((&pfn));
  c_add_to_ghost_state((&nr_pages), sizeof(unsigned int), get_cn_stack_depth());
  cn_pointer* nr_pages_addr_cn = convert_to_cn_pointer((&nr_pages));
  c_add_to_ghost_state((&reserved_pages), sizeof(unsigned int), get_cn_stack_depth());
  cn_pointer* reserved_pages_addr_cn = convert_to_cn_pointer((&reserved_pages));
  
    phys_addr_t phys = ((phys_addr_t)(CN_LOAD((pfn)) << 12));
c_add_to_ghost_state((&phys), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* phys_addr_cn = convert_to_cn_pointer((&phys));

    struct hyp_page *p = ((void *)0);
c_add_to_ghost_state((&p), sizeof(struct hyp_page*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

    /* struct hyp_page *p; */
    int i;
c_add_to_ghost_state((&i), sizeof(signed int), get_cn_stack_depth());


cn_pointer* i_addr_cn = convert_to_cn_pointer((&i));

    /* hyp_spin_lock_init(&pool->lock); */
    CN_STORE(CN_LOAD(pool)->max_order, ((11) < (
({
  ghost_call_site = EMPTY;
  0;
})
, (get_order((CN_LOAD(nr_pages) + 1) << 12))) ? (11) : (
({
  ghost_call_site = EMPTY;
  0;
})
, (get_order((CN_LOAD(nr_pages) + 1) << 12)))));
    ((void) 0);
    {
struct loop_ownership* a_8308;

cn_bits_u64* O_phys11;

cn_pointer* O_p14;

cn_bits_i32* O_i14;

cn_pointer* O_pool14;

cn_bits_u64* O_pfn11;

cn_bits_u32* O_nr_pages11;

cn_bits_u32* O_reserved_pages11;

cn_pointer* O___hyp_vmemmap15;

cn_bits_i64* O_hyp_physvirt_offset17;

cn_pointer* O_cn_virt_ptr11;

struct hyp_pool_cn* OI;

cn_map* V2;

cn_bool* a_8494;

cn_bool* a_8537;

cn_bits_u8* order;

cn_bits_u8* a_8608;

cn_pointer* read___hyp_vmemmap14;

cn_pointer* read_pool2;

struct hyp_pool_cn* deref_read_pool20;
for (CN_STORE(i, 0); ({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_8308 = initialise_loop_ownership_state();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_phys11 = owned_unsigned_long_long(phys_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_p14 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_i14 = owned_signed_int(i_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_pool14 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_pfn11 = owned_unsigned_long_long(pfn_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_nr_pages11 = owned_unsigned_int(nr_pages_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("      phys == pfn * page_size(); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1751:5-1765:6");
  O_reserved_pages11 = owned_unsigned_int(reserved_pages_addr_cn, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O___hyp_vmemmap15 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_hyp_physvirt_offset17 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_cn_virt_ptr11 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("    {\n                 ^./driver.pp.c:1752:18:");
  OI = owned_struct_hyp_pool(O_pool14, LOOP, a_8308);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/ /*@ extract Owned<struct list_head>, i; @*/\n           ^./driver.pp.c:1753:12:");
  V2 = map_create();
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, j), cn_bits_u64_lt(j, end_i_cn)))) {
        cn_pointer* a_8400 = cn_array_shift(O___hyp_vmemmap15, sizeof(struct hyp_page), j);
        cn_map_set(V2, cast_cn_bits_u64_to_cn_integer(j), owned_struct_hyp_page(a_8400, LOOP, a_8308));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("        INIT_LIST_HEAD(&pool->free_area[i]);\n           ^./driver.pp.c:1754:12:");
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages11)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages11))), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages11)), j), cn_bits_u64_lt(j, end_i_cn)))) {
        cn_pointer* a_8451 = cn_array_shift(ptr_phys_0_cn, sizeof(char[4096]), j);
        Page(a_8451, convert_to_cn_bool(true), convert_to_cn_bits_u8(0UL), LOOP, a_8308);
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1755:7-104");
  a_8494 = convert_to_cn_bool(true);
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL)), j), cn_bits_u64_lt(j, cast_cn_bits_i32_to_cn_bits_u64(O_i14))))) {
      if (convert_from_cn_bool(cn_bits_u64_lt(j, cast_cn_bits_i32_to_cn_bits_u64(O_i14)))) {
        a_8494 = cn_bool_and(a_8494, cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(OI->free_area, cast_cn_bits_u64_to_cn_integer(j)))->prev, cn_array_shift(O_pool14, sizeof(struct list_head), j)));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_assert(a_8494, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_start = phys;\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1756:7-104");
  a_8537 = convert_to_cn_bool(true);
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL)), j), cn_bits_u64_lt(j, cast_cn_bits_i32_to_cn_bits_u64(O_i14))))) {
      if (convert_from_cn_bool(cn_bits_u64_lt(j, cast_cn_bits_i32_to_cn_bits_u64(O_i14)))) {
        a_8537 = cn_bool_and(a_8537, cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(OI->free_area, cast_cn_bits_u64_to_cn_integer(j)))->next, cn_array_shift(O_pool14, sizeof(struct list_head), j)));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_assert(a_8537, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1757:7-33");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap15, O___hyp_vmemmap11_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n                                 ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1757:34-51");
  cn_assert(cn_pointer_equality(O_pool14, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n                                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1757:52-84");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset17, O_hyp_physvirt_offset13_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n                                                                                    ^~~~~~~~~~~~~~~~ ./driver.pp.c:1757:85-101");
  cn_assert(cn_bits_u64_equality(O_pfn11, pfn_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n                                                                                                     ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1757:102-123");
  cn_assert(cn_bits_u32_equality(O_nr_pages11, nr_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->range_end = phys + (nr_pages << 12);\n                                                                                                                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1757:124-151");
  cn_assert(cn_bits_u32_equality(O_reserved_pages11, reserved_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Init the vmemmap portion */\n      ^~~~~~~~~~ ./driver.pp.c:1758:7-17");
  cn_assert(cn_bits_i32_le(convert_to_cn_bits_i32(0LL), O_i14), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Init the vmemmap portion */\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1758:18-47");
  cn_assert(cn_bits_i32_le(O_i14, cast_cn_bits_u8_to_cn_bits_i32(OI->max_order)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Init the vmemmap portion */\n                                               ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1758:48-72");
  cn_assert(cn_bits_u8_lt(convert_to_cn_bits_u8(0UL), OI->max_order), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* Init the vmemmap portion */\n                                                                        ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1758:73-99");
  cn_assert(cn_bits_u8_le(OI->max_order, convert_to_cn_bits_u8(11UL)), LOOP);
  cn_pop_msg_info();
  order = get_order_uf(cn_bits_u64_multiply(cn_bits_u64_add(cast_cn_bits_u32_to_cn_bits_u64(O_nr_pages11), convert_to_cn_bits_u64(1ULL)), page_size()));
  update_cn_error_message_info("    for (i = 0; i < nr_pages; i++)\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1760:7-58");
  if (convert_from_cn_bool(cn_bits_u8_lt(convert_to_cn_bits_u8(11UL), order))) {
    a_8608 = convert_to_cn_bits_u8(11UL);
  }
  else {
    a_8608 = order;
  }
  cn_assert(cn_bits_u8_equality(OI->max_order, a_8608), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ inv take OI2 = Owned(pool); \n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1761:7-33");
  cn_assert(cn_bits_u64_equality(O_phys11, cn_bits_u64_multiply(O_pfn11, page_size())), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("      take PI2 = each (u64 j; start_i + ((u64) reserved_pages) <= j && j < end_i){ Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, j), true, 0u8) }; \n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1763:19-57");
  cn_pop_msg_info();
  update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:14-63");
  read___hyp_vmemmap14 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_pool2 = convert_to_cn_pointer(cn_pointer_deref(pool_addr_cn, struct hyp_pool*));
  deref_read_pool20 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool2, struct hyp_pool));
  update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:15-61");
  page_group_ok_easy(read___hyp_vmemmap14, deref_read_pool20);
  cn_pop_msg_info();
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_8308);
  cn_bump_free_after(cn_frame_id);
  0;
})
, CN_LOAD(i) < CN_LOAD(CN_LOAD(pool)->max_order); CN_POSTFIX(i, ++))
    /*@ inv take OI = Owned(pool); 
      take V2 = each (u64 j; start_i <= j && j < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, j))}; 
      take PI = each (u64 j; start_i + ((u64) reserved_pages) <= j && j < end_i){ Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, j), true, 0u8) }; 
      each(u64 j; j < (u64) i){((*pool).free_area[j]).prev == array_shift<struct list_head>(pool, j) }; 
      each(u64 j; j < (u64) i){((*pool).free_area[j]).next == array_shift<struct list_head>(pool, j) }; 
      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; 
      0i32 <= i; i <= (i32) (*pool).max_order; (*pool).max_order > 0u8; (*pool).max_order <= 11u8; 
      let order = get_order_uf(((u64) nr_pages + 1u64)*(page_size())); 
      (*pool).max_order == (11u8 < order ? 11u8 : order); 
      phys == pfn * page_size(); @*/
    {
        /*CN*/ /*@ extract Owned<struct list_head>, i; @*/
        INIT_LIST_HEAD(&CN_LOAD(pool)->free_area[CN_LOAD(i)]);
    }}
    CN_STORE(CN_LOAD(pool)->range_start, CN_LOAD(phys));
    CN_STORE(CN_LOAD(pool)->range_end, CN_LOAD(phys) + (CN_LOAD(nr_pages) << 12));
    /* Init the vmemmap portion */
    CN_STORE(p, (&((struct hyp_page *)CN_LOAD(__hyp_vmemmap))[(CN_LOAD((phys)) >> 12)]));
    {
struct loop_ownership* a_7876;

cn_bits_u64* O_phys10;

cn_pointer* O_p13;

cn_bits_i32* O_i13;

cn_pointer* O_pool13;

cn_bits_u64* O_pfn10;

cn_bits_u32* O_nr_pages10;

cn_bits_u32* O_reserved_pages10;

cn_pointer* O___hyp_vmemmap14;

cn_bits_i64* O_hyp_physvirt_offset16;

cn_pointer* O_cn_virt_ptr10;

struct hyp_pool_cn* OI2;

cn_map* V3;

cn_bool* a_8059;

cn_bool* a_8099;

cn_bool* a_8131;

cn_bits_u8* order;

cn_bits_u8* a_8212;

cn_bits_u64* read_pfn2;

cn_bits_i32* read_i10;

cn_pointer* read___hyp_vmemmap13;

cn_pointer* read_pool1;

struct hyp_pool_cn* deref_read_pool10;
for (CN_STORE(i, 0); ({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_7876 = initialise_loop_ownership_state();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_phys10 = owned_unsigned_long_long(phys_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_p13 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_i13 = owned_signed_int(i_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_pool13 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_pfn10 = owned_unsigned_long_long(pfn_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_nr_pages10 = owned_unsigned_int(nr_pages_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).range_end == end; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1770:5-1795:6");
  O_reserved_pages10 = owned_unsigned_int(reserved_pages_addr_cn, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O___hyp_vmemmap14 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_hyp_physvirt_offset16 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_cn_virt_ptr10 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).max_order > 0u8; \n                 ^./driver.pp.c:1771:18:");
  OI2 = owned_struct_hyp_pool(O_pool13, LOOP, a_7876);
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).max_order <= 11u8; \n           ^./driver.pp.c:1772:12:");
  V3 = map_create();
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, j), cn_bits_u64_lt(j, end_i_cn)))) {
        cn_pointer* a_7968 = cn_array_shift(O___hyp_vmemmap14, sizeof(struct hyp_page), j);
        cn_map_set(V3, cast_cn_bits_u64_to_cn_integer(j), owned_struct_hyp_page(a_7968, LOOP, a_7876));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("      let order = get_order_uf(((u64)nr_pages + 1u64)*(page_size())); \n           ^./driver.pp.c:1773:12:");
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages10)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages10))), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_u32_to_cn_bits_u64(O_reserved_pages10)), j), cn_bits_u64_lt(j, end_i_cn)))) {
        cn_pointer* a_8019 = cn_array_shift(ptr_phys_0_cn, sizeof(char[4096]), j);
        Page(a_8019, convert_to_cn_bool(true), convert_to_cn_bits_u8(0UL), LOOP, a_7876);
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("      (*pool).max_order == (11u8 < order ? 11u8 : order); \n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1774:7-118");
  a_8059 = convert_to_cn_bool(true);
  {
    cn_bits_u8* j = cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL)), j), cn_bits_u8_lt(j, OI2->max_order)))) {
      if (convert_from_cn_bool(cn_bits_u8_lt(j, OI2->max_order))) {
        a_8059 = cn_bool_and(a_8059, cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(OI2->free_area, cast_cn_bits_u64_to_cn_integer(cast_cn_bits_u8_to_cn_bits_u64(j))))->prev, cn_array_shift(O_pool13, sizeof(struct list_head), j)));
      }
      else {
        ;
      }
      cn_bits_u8_increment(j);
    }
  }
  cn_assert(a_8059, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("      hyp_pool_wf(pool, (*pool), __hyp_vmemmap, hyp_physvirt_offset); \n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1775:7-120");
  a_8099 = convert_to_cn_bool(true);
  {
    cn_bits_u8* j = cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL)), j), cn_bits_u8_lt(j, OI2->max_order)))) {
      if (convert_from_cn_bool(cn_bits_u8_lt(j, OI2->max_order))) {
        a_8099 = cn_bool_and(a_8099, cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(OI2->free_area, cast_cn_bits_u64_to_cn_integer(cast_cn_bits_u8_to_cn_bits_u64(j))))->next, cn_array_shift(O_pool13, sizeof(struct list_head), j)));
      }
      else {
        ;
      }
      cn_bits_u8_increment(j);
    }
  }
  cn_assert(a_8099, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); @*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1776:7-98");
  a_8131 = convert_to_cn_bool(true);
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), j), cn_bits_u64_lt(j, cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i13)))))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, j), cn_bits_u64_lt(j, cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i13)))))) {
        a_8131 = cn_bool_and(a_8131, init_vmemmap_page(j, V3, O_pool13, OI2));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_assert(a_8131, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    {\n      ^~~~~~~~~~ ./driver.pp.c:1777:7-17");
  cn_assert(cn_bits_i32_le(convert_to_cn_bits_i32(0LL), O_i13), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    {\n                 ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1777:18-38");
  cn_assert(cn_bits_u32_le(cast_cn_bits_i32_to_cn_bits_u32(O_i13), O_nr_pages10), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1778:7-33");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap14, O___hyp_vmemmap11_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n                                 ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1778:34-51");
  cn_assert(cn_pointer_equality(O_pool13, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n                                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1778:52-84");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset16, O_hyp_physvirt_offset13_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n                                                                                    ^~~~~~~~~~~~~~~~ ./driver.pp.c:1778:85-101");
  cn_assert(cn_bits_u64_equality(O_pfn10, pfn_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n                                                                                                     ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1778:102-123");
  cn_assert(cn_bits_u32_equality(O_nr_pages10, nr_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/\n                                                                                                                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1778:124-151");
  cn_assert(cn_bits_u32_equality(O_reserved_pages10, reserved_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@extract Owned<struct hyp_page>, pfn+((u64) i); @*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1779:7-36");
  cn_assert(cn_bits_u64_equality(OI2->range_start, start_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        p[i].refcount = 0; /* added for formalisation */\n      ^~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1780:7-32");
  cn_assert(cn_bits_u64_equality(OI2->range_end, end_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        p[i].order = 0; /* added for formalisation */\n      ^~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1781:7-31");
  cn_assert(cn_bits_u8_lt(convert_to_cn_bits_u8(0UL), OI2->max_order), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        hyp_set_page_refcounted(&p[i]);\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1782:7-33");
  cn_assert(cn_bits_u8_le(OI2->max_order, convert_to_cn_bits_u8(11UL)), LOOP);
  cn_pop_msg_info();
  order = get_order_uf(cn_bits_u64_multiply(cn_bits_u64_add(cast_cn_bits_u32_to_cn_bits_u64(O_nr_pages10), convert_to_cn_bits_u64(1ULL)), page_size()));
  update_cn_error_message_info("        /*CN*//*@ apply page_size_of_order_lemma (); @*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1784:7-58");
  if (convert_from_cn_bool(cn_bits_u8_lt(convert_to_cn_bits_u8(11UL), order))) {
    a_8212 = convert_to_cn_bits_u8(11UL);
  }
  else {
    a_8212 = order;
  }
  cn_assert(cn_bits_u8_equality(OI2->max_order, a_8212), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1785:7-70");
  cn_assert(hyp_pool_wf(O_pool13, OI2, O___hyp_vmemmap14, O_hyp_physvirt_offset16), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*CN*//*@ apply page_group_ok_easy(__hyp_vmemmap,*pool); @*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1786:7-61");
  cn_assert(cn_pointer_equality(O_p13, cn_array_shift(O___hyp_vmemmap14, sizeof(struct hyp_page), O_pfn10)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    for (i = reserved_pages; i < nr_pages; i++)\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1788:18-125");
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ inv take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1789:18-66");
  cn_pop_msg_info();
  update_cn_error_message_info("      each(u64 j; start_i + (u64) i <= j && j < end_i){H.vmemmap[j].refcount == 1u16}; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1793:18-61");
  read_pfn2 = convert_to_cn_bits_u64(cn_pointer_deref(pfn_addr_cn, unsigned long long));
  read_i10 = convert_to_cn_bits_i32(cn_pointer_deref(i_addr_cn, signed int));
  update_cn_error_message_info("      each(u64 j; start_i + (u64) i <= j && j < end_i){H.vmemmap[j].refcount == 1u16}; \n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1793:19-59");
  order_aligned_init(cn_bits_u64_add(read_pfn2, cast_cn_bits_i32_to_cn_bits_u64(read_i10)));
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("      (H.pool).range_start == start; \n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1794:18-55");
  update_cn_error_message_info("      (H.pool).range_start == start; \n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1794:19-53");
  page_size_of_order_lemma();
  cn_pop_msg_info();
  cn_pop_msg_info();
  update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:14-63");
  read___hyp_vmemmap13 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));
  read_pool1 = convert_to_cn_pointer(cn_pointer_deref(pool_addr_cn, struct hyp_pool*));
  deref_read_pool10 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool1, struct hyp_pool));
  update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:15-61");
  page_group_ok_easy(read___hyp_vmemmap13, deref_read_pool10);
  cn_pop_msg_info();
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_7876);
  cn_bump_free_after(cn_frame_id);
  0;
})
, CN_LOAD(i) < CN_LOAD(nr_pages); CN_POSTFIX(i, ++))
    /*@ inv take OI2 = Owned(pool); 
      take V3 = each (u64 j; start_i <= j && j < end_i){Owned(array_shift<struct hyp_page>(__hyp_vmemmap, j)) }; 
      take PI2 = each (u64 j; start_i + ((u64) reserved_pages) <= j && j < end_i){ Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, j), true, 0u8) }; 
      each(u8 j; j < (*pool).max_order){((*pool).free_area[(u64) j]).prev == array_shift<struct list_head>(pool, j)}; 
      each(u8 j; j < ((*pool).max_order)){((*pool).free_area[(u64) j]).next == array_shift<struct list_head>(pool, j)}; 
      each (u64 j; start_i <= j && j < start_i + (u64) i){init_vmemmap_page(j, V3, pool, *pool)}; 
      0i32 <= i; (u32) i <= nr_pages; 
      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; 
      (*pool).range_start == start; 
      (*pool).range_end == end; 
      (*pool).max_order > 0u8; 
      (*pool).max_order <= 11u8; 
      let order = get_order_uf(((u64)nr_pages + 1u64)*(page_size())); 
      (*pool).max_order == (11u8 < order ? 11u8 : order); 
      hyp_pool_wf(pool, (*pool), __hyp_vmemmap, hyp_physvirt_offset); 
      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); @*/
    {
        /*CN*//*@instantiate good<struct hyp_page>, cn_hyp_page_to_pfn(__hyp_vmemmap, array_shift<struct hyp_page>(p, i)); @*/
        /*CN*//*@extract Owned<struct hyp_page>, pfn+((u64) i); @*/
        CN_STORE(CN_LOAD(p)[CN_LOAD(i)].refcount, 0); /* added for formalisation */
        CN_STORE(CN_LOAD(p)[CN_LOAD(i)].order, 0); /* added for formalisation */
        hyp_set_page_refcounted(&CN_LOAD(p)[CN_LOAD(i)]);
        /*CN*//*@ apply order_aligned_init(pfn+((u64) i)); @*/
        /*CN*//*@ apply page_size_of_order_lemma (); @*/
    }}
    /*CN*/update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n             ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:14-63");

cn_pointer* read___hyp_vmemmap11 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), struct hyp_page*));

cn_pointer* read_pool0 = convert_to_cn_pointer(cn_pointer_deref(convert_to_cn_pointer((&pool)), struct hyp_pool*));

struct hyp_pool_cn* deref_read_pool00 = convert_to_struct_hyp_pool_cn(cn_pointer_deref(read_pool0, struct hyp_pool));

update_cn_error_message_info("      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); \n              ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1796:15-61");

page_group_ok_easy(read___hyp_vmemmap11, deref_read_pool00);

cn_pop_msg_info();

cn_pop_msg_info();

    /* Attach the unused pages to the buddy tree */
    {
struct loop_ownership* a_7560;

cn_bits_u64* O_phys9;

cn_pointer* O_p12;

cn_bits_i32* O_i12;

cn_pointer* O_pool12;

cn_bits_u64* O_pfn9;

cn_bits_u32* O_nr_pages9;

cn_bits_u32* O_reserved_pages9;

cn_pointer* O___hyp_vmemmap13;

cn_bits_i64* O_hyp_physvirt_offset15;

cn_pointer* O_cn_virt_ptr9;

struct Hyp_pool_ex1_record* H;

cn_bool* a_7720;

cn_bool* a_7768;
for (CN_STORE(i, CN_LOAD(reserved_pages)); ({
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  a_7560 = initialise_loop_ownership_state();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_phys9 = owned_unsigned_long_long(phys_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_p12 = owned_struct_hyp_page_pointer(p_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_i12 = owned_signed_int(i_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_pool12 = owned_struct_hyp_pool_pointer(pool_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_pfn9 = owned_unsigned_long_long(pfn_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_nr_pages9 = owned_unsigned_int(nr_pages_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1798:5-1817:6");
  O_reserved_pages9 = owned_unsigned_int(reserved_pages_addr_cn, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O___hyp_vmemmap13 = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_hyp_physvirt_offset15 = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  O_cn_virt_ptr9 = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      (H.pool).range_start == start; \n                 ^./driver.pp.c:1799:18:");
  H = Hyp_pool(O_pool12, O___hyp_vmemmap13, O_cn_virt_ptr9, O_hyp_physvirt_offset15, LOOP, a_7560);
  cn_pop_msg_info();
  update_cn_error_message_info("      (H.pool).range_end == end; \n      ^~~~~~~~~~ ./driver.pp.c:1800:7-17");
  cn_assert(cn_bits_i32_le(convert_to_cn_bits_i32(0LL), O_i12), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("      (H.pool).max_order <= 11u8; @*/\n           ^./driver.pp.c:1801:12:");
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12))), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)), j), cn_bits_u64_lt(j, end_i_cn)))) {
        cn_pointer* a_7672 = cn_array_shift(ptr_phys_0_cn, sizeof(char[4096]), j);
        Page(a_7672, convert_to_cn_bool(true), convert_to_cn_bits_u8(0UL), LOOP, a_7560);
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("    {\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1802:7-83");
  a_7720 = convert_to_cn_bool(true);
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12))), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)), j), cn_bits_u64_lt(j, end_i_cn)))) {
        a_7720 = cn_bool_and(a_7720, cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H->vmemmap, cast_cn_bits_u64_to_cn_integer(j)))->order, convert_to_cn_bits_u8(0UL)));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_assert(a_7720, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*//*@instantiate ((u64) i)+pfn;@*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1803:7-87");
  a_7768 = convert_to_cn_bool(true);
  {
    cn_bits_u64* j = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12))), j), cn_bits_u64_lt(j, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(start_i_cn, cast_cn_bits_i32_to_cn_bits_u64(O_i12)), j), cn_bits_u64_lt(j, end_i_cn)))) {
        a_7768 = cn_bool_and(a_7768, cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(H->vmemmap, cast_cn_bits_u64_to_cn_integer(j)))->refcount, convert_to_cn_bits_u16(1ULL)));
      }
      else {
        ;
      }
      cn_bits_u64_increment(j);
    }
  }
  cn_assert(a_7768, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        // p[i].refcount = 0; /* added for formalisation */\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1804:7-37");
  cn_assert(cn_bits_u64_equality(H->pool->range_start, start_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*CN*/ /*@extract Page, start_i+((u64) i);@*/\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1805:7-33");
  cn_assert(cn_bits_u64_equality(H->pool->range_end, end_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        __hyp_put_page(pool, &p[i]);\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1806:7-61");
  cn_assert(cn_pointer_equality(O_p12, cn_array_shift(O___hyp_vmemmap13, sizeof(struct hyp_page), O_pfn9)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1807:7-33");
  cn_assert(cn_bits_u32_le(O_reserved_pages9, cast_cn_bits_i32_to_cn_bits_u32(O_i12)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    }\n                                 ^~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1807:34-54");
  cn_assert(cn_bits_u32_le(cast_cn_bits_i32_to_cn_bits_u32(O_i12), O_nr_pages9), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1808:7-33");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap13, O___hyp_vmemmap11_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n                                 ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1808:34-51");
  cn_assert(cn_pointer_equality(O_pool12, pool_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n                                                   ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1808:52-84");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset15, O_hyp_physvirt_offset13_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n                                                                                    ^~~~~~~~~~~~~~~~ ./driver.pp.c:1808:85-101");
  cn_assert(cn_bits_u64_equality(O_pfn9, pfn_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n                                                                                                     ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1808:102-123");
  cn_assert(cn_bits_u32_equality(O_nr_pages9, nr_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n                                                                                                                           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1808:124-151");
  cn_assert(cn_bits_u32_equality(O_reserved_pages9, reserved_pages_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    return 0;\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1809:7-37");
  cn_assert(cn_bits_u64_equality(H->pool->range_start, start_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("}\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1810:7-33");
  cn_assert(cn_bits_u64_equality(H->pool->range_end, end_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("\n      ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1811:7-34");
  cn_assert(cn_bits_u8_le(H->pool->max_order, convert_to_cn_bits_u8(11UL)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("void *cn_malloc(unsigned long size);\n                 ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1813:18-45");
  cn_pop_msg_info();
  update_cn_error_message_info("void cn_print_u64(const char * x, unsigned long y);\n                  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1815:19-52");
  cn_pop_msg_info();
  cn_loop_put_back_ownership(a_7560);
  cn_bump_free_after(cn_frame_id);
  0;
})
, CN_LOAD(i) < CN_LOAD(nr_pages); CN_POSTFIX(i, ++))
    /*@ inv take H = Hyp_pool(pool, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
      i >= 0i32; 
      take PI3 = each(u64 j; start_i + ((u64) i) <= j && j < end_i){ Page(array_shift<PAGE_SIZE_t>(ptr_phys_0, j), true, 0u8) }; 
      each(u64 j; start_i + (u64) i <= j && j < end_i){H.vmemmap[j].order == 0u8}; 
      each(u64 j; start_i + (u64) i <= j && j < end_i){H.vmemmap[j].refcount == 1u16}; 
      (H.pool).range_start == start; 
      (H.pool).range_end == end; 
      p == array_shift<struct hyp_page>(__hyp_vmemmap, pfn); 
      reserved_pages <= (u32) i; (u32) i <= nr_pages; 
      {__hyp_vmemmap} unchanged; {pool} unchanged; {hyp_physvirt_offset} unchanged; {pfn} unchanged; {nr_pages} unchanged; {reserved_pages} unchanged; 
      (H.pool).range_start == start; 
      (H.pool).range_end == end; 
      (H.pool).max_order <= 11u8; @*/
    {
        /*CN*//*@instantiate ((u64) i)+pfn;@*/
        // p[i].refcount = 0; /* added for formalisation */
        /*CN*/ /*@extract Page, start_i+((u64) i);@*/
        __hyp_put_page(CN_LOAD(pool), &CN_LOAD(p)[CN_LOAD(i)]);
    }}
    ((void) 0);
    { __cn_ret = 0; 
c_remove_from_ghost_state((&phys), sizeof(unsigned long long));


c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&i), sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((&phys), sizeof(unsigned long long));


c_remove_from_ghost_state((&p), sizeof(struct hyp_page*));


c_remove_from_ghost_state((&i), sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

  c_remove_from_ghost_state((&pfn), sizeof(unsigned long long));

  c_remove_from_ghost_state((&nr_pages), sizeof(unsigned int));

  c_remove_from_ghost_state((&reserved_pages), sizeof(unsigned int));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_pointer* O___hyp_vmemmap12_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_bits_i64* O_hyp_physvirt_offset14_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  hyp_pool_wf(pool, poolv, __hyp_vmemmap, hyp_physvirt_offset); \n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1723:5-62");
  cn_pointer* O_cn_virt_ptr8_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* hyp_spin_lock_init(&pool->lock); */\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1738:10-36");
  cn_assert(cn_pointer_equality(O___hyp_vmemmap12_cn, O___hyp_vmemmap11_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /* hyp_spin_lock_init(&pool->lock); */\n                                    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1738:37-69");
  cn_assert(cn_bits_i64_equality(O_hyp_physvirt_offset14_cn, O_hyp_physvirt_offset13_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    pool->max_order = ((11) < (get_order((nr_pages + 1) << 12)) ? (11) : (get_order((nr_pages + 1) << 12)));\n       ^./driver.pp.c:1739:8:");
  struct Hyp_pool_ex1_record* H2_cn = Hyp_pool(pool_cn, O___hyp_vmemmap12_cn, O_cn_virt_ptr8_cn, O_hyp_physvirt_offset14_cn, POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("    ((void) 0);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1740:3-34");
  cn_assert(cn_bits_u64_equality(H2_cn->pool->range_start, start_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    for (i = 0; i < pool->max_order; i++)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1741:3-30");
  cn_assert(cn_bits_u64_equality(H2_cn->pool->range_end, end_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    /*@ inv take OI = Owned(pool); \n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1742:3-31");
  cn_assert(cn_bits_u8_le(H2_cn->pool->max_order, convert_to_cn_bits_u8(11UL)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
void *cn_aligned_alloc(size_t align, size_t size);
void *cn_malloc(unsigned long size);
void *cn_calloc(size_t num, size_t size);
void cn_print_u64(const char * x, unsigned long y);
void cn_print_nr_u64(int x, unsigned long y);
void cn_print_nr_owned_predicates(void);
s64 hyp_physvirt_offset;
struct hyp_pool *init(unsigned int nr_pages)
/*@ accesses __hyp_vmemmap, hyp_physvirt_offset, cn_virt_ptr;
    ensures take H = Hyp_pool(return, __hyp_vmemmap, cn_virt_ptr, hyp_physvirt_offset); 
@*/
{
  /* EXECUTABLE CN PRECONDITION */
  struct hyp_pool* __cn_ret;
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  cn_bits_u32* nr_pages_cn = convert_to_cn_bits_u32(nr_pages);
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_pointer* O___hyp_vmemmap40_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_bits_i64* O_hyp_physvirt_offset42_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), PRE, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_pointer* O_cn_virt_ptr30_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), PRE, 0);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((&nr_pages), sizeof(unsigned int), get_cn_stack_depth());
  cn_pointer* nr_pages_addr_cn = convert_to_cn_pointer((&nr_pages));
  
  CN_STORE(hyp_physvirt_offset, 0x0);
  unsigned int reserved_pages = 0;
c_add_to_ghost_state((&reserved_pages), sizeof(unsigned int), get_cn_stack_depth());


cn_pointer* reserved_pages_addr_cn = convert_to_cn_pointer((&reserved_pages));

  u8 max_order = 10;
c_add_to_ghost_state((&max_order), sizeof(unsigned char), get_cn_stack_depth());


cn_pointer* max_order_addr_cn = convert_to_cn_pointer((&max_order));

  void *start_virt = (
({
  ghost_call_site = EMPTY;
  0;
})
, cn_aligned_alloc(((1UL) << 12), ((1UL) << 12) * CN_LOAD(nr_pages)));
c_add_to_ghost_state((&start_virt), sizeof(void*), get_cn_stack_depth());


cn_pointer* start_virt_addr_cn = convert_to_cn_pointer((&start_virt));

  phys_addr_t range_start = (phys_addr_t) ((phys_addr_t)CN_LOAD((start_virt)) + CN_LOAD(hyp_physvirt_offset));
c_add_to_ghost_state((&range_start), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* range_start_addr_cn = convert_to_cn_pointer((&range_start));

  u64 pfn = (CN_LOAD((range_start)) >> 12);
c_add_to_ghost_state((&pfn), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* pfn_addr_cn = convert_to_cn_pointer((&pfn));

  u64 npfn = 0-CN_LOAD(pfn);
c_add_to_ghost_state((&npfn), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* npfn_addr_cn = convert_to_cn_pointer((&npfn));

  u64 vmemmap_size = sizeof(struct hyp_page) * CN_LOAD(nr_pages);
c_add_to_ghost_state((&vmemmap_size), sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* vmemmap_size_addr_cn = convert_to_cn_pointer((&vmemmap_size));

  void *start_of_owned_vmemmap = (
({
  ghost_call_site = EMPTY;
  0;
})
, cn_malloc(CN_LOAD(vmemmap_size)));
c_add_to_ghost_state((&start_of_owned_vmemmap), sizeof(void*), get_cn_stack_depth());


cn_pointer* start_of_owned_vmemmap_addr_cn = convert_to_cn_pointer((&start_of_owned_vmemmap));

  CN_STORE(__hyp_vmemmap, ((struct hyp_page *) CN_LOAD(start_of_owned_vmemmap)) + CN_LOAD(npfn));
  struct hyp_pool *pool = (
({
  ghost_call_site = EMPTY;
  0;
})
, cn_calloc(1, sizeof(struct hyp_pool)));
c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());


cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));

  CN_STORE(CN_LOAD(pool)->range_start, CN_LOAD(range_start));
  CN_STORE(CN_LOAD(pool)->range_end, CN_LOAD(range_start) + CN_LOAD(nr_pages) * ((1UL) << 12));
  CN_STORE(CN_LOAD(pool)->max_order, CN_LOAD(max_order));
  (
({
  ghost_call_site = EMPTY;
  0;
})
, hyp_pool_init(CN_LOAD(pool), (CN_LOAD((range_start)) >> 12), CN_LOAD(nr_pages), CN_LOAD(reserved_pages)));
  { __cn_ret = CN_LOAD(pool); 
c_remove_from_ghost_state((&reserved_pages), sizeof(unsigned int));


c_remove_from_ghost_state((&max_order), sizeof(unsigned char));


c_remove_from_ghost_state((&start_virt), sizeof(void*));


c_remove_from_ghost_state((&range_start), sizeof(unsigned long long));


c_remove_from_ghost_state((&pfn), sizeof(unsigned long long));


c_remove_from_ghost_state((&npfn), sizeof(unsigned long long));


c_remove_from_ghost_state((&vmemmap_size), sizeof(unsigned long long));


c_remove_from_ghost_state((&start_of_owned_vmemmap), sizeof(void*));


c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));
goto __cn_epilogue; }

c_remove_from_ghost_state((&reserved_pages), sizeof(unsigned int));


c_remove_from_ghost_state((&max_order), sizeof(unsigned char));


c_remove_from_ghost_state((&start_virt), sizeof(void*));


c_remove_from_ghost_state((&range_start), sizeof(unsigned long long));


c_remove_from_ghost_state((&pfn), sizeof(unsigned long long));


c_remove_from_ghost_state((&npfn), sizeof(unsigned long long));


c_remove_from_ghost_state((&vmemmap_size), sizeof(unsigned long long));


c_remove_from_ghost_state((&start_of_owned_vmemmap), sizeof(void*));


c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((&nr_pages), sizeof(unsigned int));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_pointer* O___hyp_vmemmap41_cn = owned_struct_hyp_page_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp___hyp_vmemmap()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_bits_i64* O_hyp_physvirt_offset43_cn = owned_signed_long_long(convert_to_cn_pointer(cn_test_get_static_driverpp_hyp_physvirt_offset()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  u64 pfn = ((range_start) >> 12);\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1829:5-62");
  cn_pointer* O_cn_virt_ptr31_cn = owned_void_pointer(convert_to_cn_pointer(cn_test_get_static_driverpp_cn_virt_ptr()), POST, 0);
  cn_pop_msg_info();
  update_cn_error_message_info("  u64 npfn = 0-pfn;\n                 ^./driver.pp.c:1830:18:");
  struct Hyp_pool_ex1_record* H_cn = Hyp_pool(return_cn, O___hyp_vmemmap41_cn, O_cn_virt_ptr31_cn, O_hyp_physvirt_offset43_cn, POST, 0);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

  cn_bump_free_after(cn_frame_id);

return __cn_ret;

}
/*
int main(void)
{
  struct hyp_pool *pool = init();

  void *page1 = hyp_alloc_pages(pool, 2);
  if (page1) {
    ((char *)page1)[1234] = 1;
    hyp_get_page(pool, page1);
    hyp_get_page(pool, page1);
    hyp_put_page(pool, page1);
    cn_print_nr_u64(1, 1);
  }
  else {
    cn_print_nr_u64(2, 2);
  }
  return 0;
} 
*/
int main(void)
/*@ trusted; @*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret = 0;
  initialise_ownership_ghost_state();
  initialise_ghost_stack_depth();
  alloc_ghost_array(0);
  initialise_ownership_stack_mode(0);
  c_add_to_ghost_state((&hyp_physvirt_offset), sizeof(signed long long), get_cn_stack_depth());
  c_add_to_ghost_state((&__hyp_vmemmap), sizeof(struct hyp_page*), get_cn_stack_depth());
  c_add_to_ghost_state((&cn_virt_base), sizeof(void*), get_cn_stack_depth());
  c_add_to_ghost_state((&cn_virt_ptr), sizeof(void*), get_cn_stack_depth());
  
  struct hyp_pool *pool = (
({
  ghost_call_site = EMPTY;
  0;
})
, init(8));
c_add_to_ghost_state((&pool), sizeof(struct hyp_pool*), get_cn_stack_depth());


cn_pointer* pool_addr_cn = convert_to_cn_pointer((&pool));

  void *pages[8];
c_add_to_ghost_state((&pages), sizeof(void*[8]), get_cn_stack_depth());


cn_pointer* pages_addr_cn = convert_to_cn_pointer((&pages));

  int i = 0;
c_add_to_ghost_state((&i), sizeof(signed int), get_cn_stack_depth());


cn_pointer* i_addr_cn = convert_to_cn_pointer((&i));

  while (CN_LOAD(i) < 8) {
    CN_STORE(pages[CN_LOAD(i)], hyp_alloc_pages(CN_LOAD(pool), 0));
    CN_POSTFIX(i, ++);
  }
  CN_STORE(i, 0);
  while (CN_LOAD(i) < 8) {
    cn_print_nr_u64 (0, CN_LOAD(pages[CN_LOAD(i)])?1:0);
    CN_POSTFIX(i, ++);
  }
  CN_STORE(i, 0);
  while (CN_LOAD(i) < 8) {
    CN_STORE(((char *)CN_LOAD(pages[CN_LOAD(i)]))[1234], 1);
    CN_POSTFIX(i, ++);
  }
  CN_STORE(i, 0);
  while (CN_LOAD(i) < 8) {
    hyp_put_page(CN_LOAD(pool), CN_LOAD(pages[CN_LOAD(i)]));
    CN_POSTFIX(i, ++);
  }
  /* void *page = hyp_alloc_pages(pool, 2); */
  (
({
  ghost_call_site = EMPTY;
  0;
})
, cn_print_nr_owned_predicates());
  { __cn_ret = 0; 
c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));


c_remove_from_ghost_state((&pages), sizeof(void*[8]));


c_remove_from_ghost_state((&i), sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((&pool), sizeof(struct hyp_pool*));


c_remove_from_ghost_state((&pages), sizeof(void*[8]));


c_remove_from_ghost_state((&i), sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  c_remove_from_ghost_state((&hyp_physvirt_offset), sizeof(signed long long));

  c_remove_from_ghost_state((&__hyp_vmemmap), sizeof(struct hyp_page*));

  c_remove_from_ghost_state((&cn_virt_base), sizeof(void*));

  c_remove_from_ghost_state((&cn_virt_ptr), sizeof(void*));

return __cn_ret;

}
signed long long* cn_test_get_static_driverpp_hyp_physvirt_offset()
{
  return &hyp_physvirt_offset;
}

void cn_test_set_static_driverpp_hyp_physvirt_offset(signed long long*const  ptr)
{
  memcpy((&hyp_physvirt_offset), ptr, sizeof(signed long long));
}

struct hyp_page** cn_test_get_static_driverpp___hyp_vmemmap()
{
  return &__hyp_vmemmap;
}

void cn_test_set_static_driverpp___hyp_vmemmap(struct hyp_page**const  ptr)
{
  memcpy((&__hyp_vmemmap), ptr, sizeof(struct hyp_page*));
}

void** cn_test_get_static_driverpp_cn_virt_base()
{
  return &cn_virt_base;
}

void cn_test_set_static_driverpp_cn_virt_base(void**const  ptr)
{
  memcpy((&cn_virt_base), ptr, sizeof(void*));
}

void** cn_test_get_static_driverpp_cn_virt_ptr()
{
  return &cn_virt_ptr;
}

void cn_test_set_static_driverpp_cn_virt_ptr(void**const  ptr)
{
  memcpy((&cn_virt_ptr), ptr, sizeof(void*));
}
/* RECORD */
cn_bool* struct_Hyp_pool_ex1_record_equality(void* x, void* y)
{
  struct Hyp_pool_ex1_record* x_cast = (struct Hyp_pool_ex1_record*) x;
  struct Hyp_pool_ex1_record* y_cast = (struct Hyp_pool_ex1_record*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_map_equality(x_cast->APs, y_cast->APs, struct_list_head_cn_equality)), struct_hyp_pool_cn_equality(x_cast->pool, y_cast->pool)), cn_map_equality(x_cast->vmemmap, y_cast->vmemmap, struct_hyp_page_cn_equality));
}

cn_bool* struct_exclude_none_record_equality(void* x, void* y)
{
  struct exclude_none_record* x_cast = (struct exclude_none_record*) x;
  struct exclude_none_record* y_cast = (struct exclude_none_record*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bool_equality(x_cast->any, y_cast->any)), cn_bool_equality(x_cast->do_ex1, y_cast->do_ex1)), cn_bool_equality(x_cast->do_ex2, y_cast->do_ex2)), cn_bits_u64_equality(x_cast->ex1, y_cast->ex1)), cn_bits_u64_equality(x_cast->ex2, y_cast->ex2));
}

struct Hyp_pool_ex1_record* default_struct_Hyp_pool_ex1_record()
{
  struct Hyp_pool_ex1_record* a_16107 = (struct Hyp_pool_ex1_record*) cn_bump_malloc(sizeof(struct Hyp_pool_ex1_record));
  a_16107->APs = default_cn_map();
  a_16107->pool = default_struct_hyp_pool_cn();
  a_16107->vmemmap = default_cn_map();
  return a_16107;
}

struct exclude_none_record* default_struct_exclude_none_record()
{
  struct exclude_none_record* a_16116 = (struct exclude_none_record*) cn_bump_malloc(sizeof(struct exclude_none_record));
  a_16116->any = default_cn_bool();
  a_16116->do_ex1 = default_cn_bool();
  a_16116->do_ex2 = default_cn_bool();
  a_16116->ex1 = default_cn_bits_u64();
  a_16116->ex2 = default_cn_bits_u64();
  return a_16116;
}

void* cn_map_get_struct_Hyp_pool_ex1_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Hyp_pool_ex1_record();
  else
    return ret;
}

void* cn_map_get_struct_exclude_none_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_exclude_none_record();
  else
    return ret;
}
/* CONVERSION */

/* GENERATED STRUCT FUNCTIONS */

static struct hyp_page_cn* default_struct_hyp_page_cn()
{
  struct hyp_page_cn* a_15956 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
  a_15956->refcount = default_cn_bits_u16();
  a_15956->order = default_cn_bits_u8();
  a_15956->flags = default_cn_bits_u8();
  return a_15956;
}
static struct hyp_pool_cn* default_struct_hyp_pool_cn()
{
  struct hyp_pool_cn* a_15945 = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  a_15945->free_area = default_cn_map();
  a_15945->range_start = default_cn_bits_u64();
  a_15945->range_end = default_cn_bits_u64();
  a_15945->max_order = default_cn_bits_u8();
  return a_15945;
}
static struct list_head_cn* default_struct_list_head_cn()
{
  struct list_head_cn* a_15938 = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  a_15938->next = default_cn_pointer();
  a_15938->prev = default_cn_pointer();
  return a_15938;
}
static void* cn_map_get_struct_hyp_page_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_hyp_page_cn();
  else
    return ret;
}
static void* cn_map_get_struct_hyp_pool_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_hyp_pool_cn();
  else
    return ret;
}
static void* cn_map_get_struct_list_head_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_list_head_cn();
  else
    return ret;
}
static cn_bool* struct_hyp_page_cn_equality(void* x, void* y)
{
  struct hyp_page_cn* x_cast = (struct hyp_page_cn*) x;
  struct hyp_page_cn* y_cast = (struct hyp_page_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_u16_equality(x_cast->refcount, y_cast->refcount)), cn_bits_u8_equality(x_cast->order, y_cast->order)), cn_bits_u8_equality(x_cast->flags, y_cast->flags));
}
static cn_bool* struct_hyp_pool_cn_equality(void* x, void* y)
{
  struct hyp_pool_cn* x_cast = (struct hyp_pool_cn*) x;
  struct hyp_pool_cn* y_cast = (struct hyp_pool_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_map_equality(x_cast->free_area, y_cast->free_area, struct_list_head_cn_equality)), cn_bits_u64_equality(x_cast->range_start, y_cast->range_start)), cn_bits_u64_equality(x_cast->range_end, y_cast->range_end)), cn_bits_u8_equality(x_cast->max_order, y_cast->max_order));
}
static cn_bool* struct_list_head_cn_equality(void* x, void* y)
{
  struct list_head_cn* x_cast = (struct list_head_cn*) x;
  struct list_head_cn* y_cast = (struct list_head_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_pointer_equality(x_cast->next, y_cast->next)), cn_pointer_equality(x_cast->prev, y_cast->prev));
}
static struct hyp_page convert_from_struct_hyp_page_cn(struct hyp_page_cn* hyp_page)
{
  struct hyp_page res;
  res.refcount = convert_from_cn_bits_u16(hyp_page->refcount);
  res.order = convert_from_cn_bits_u8(hyp_page->order);
  res.flags = convert_from_cn_bits_u8(hyp_page->flags);
  return res;
}
static struct hyp_pool convert_from_struct_hyp_pool_cn(struct hyp_pool_cn* hyp_pool)
{
  struct hyp_pool res;
  convert_from_cn_map(res.free_area, hyp_pool->free_area, struct_list_head_cn, 11);
  res.range_start = convert_from_cn_bits_u64(hyp_pool->range_start);
  res.range_end = convert_from_cn_bits_u64(hyp_pool->range_end);
  res.max_order = convert_from_cn_bits_u8(hyp_pool->max_order);
  return res;
}
static struct list_head convert_from_struct_list_head_cn(struct list_head_cn* list_head)
{
  struct list_head res;
  res.next = convert_from_cn_pointer(list_head->next);
  res.prev = convert_from_cn_pointer(list_head->prev);
  return res;
}
static struct hyp_page_cn* convert_to_struct_hyp_page_cn(struct hyp_page hyp_page)
{
  struct hyp_page_cn* res = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
  res->refcount = convert_to_cn_bits_u16(hyp_page.refcount);
  res->order = convert_to_cn_bits_u8(hyp_page.order);
  res->flags = convert_to_cn_bits_u8(hyp_page.flags);
  return res;
}
static struct hyp_pool_cn* convert_to_struct_hyp_pool_cn(struct hyp_pool hyp_pool)
{
  struct hyp_pool_cn* res = (struct hyp_pool_cn*) cn_bump_malloc(sizeof(struct hyp_pool_cn));
  res->free_area = convert_to_cn_map(hyp_pool.free_area, convert_to_struct_list_head_cn, 11);
  res->range_start = convert_to_cn_bits_u64(hyp_pool.range_start);
  res->range_end = convert_to_cn_bits_u64(hyp_pool.range_end);
  res->max_order = convert_to_cn_bits_u8(hyp_pool.max_order);
  return res;
}
static struct list_head_cn* convert_to_struct_list_head_cn(struct list_head list_head)
{
  struct list_head_cn* res = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  res->next = convert_to_cn_pointer(list_head.next);
  res->prev = convert_to_cn_pointer(list_head.prev);
  return res;
}
/* OWNERSHIP FUNCTIONS */

/* OWNERSHIP FUNCTIONS */

static cn_bits_i32* owned_signed_int(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (signed int*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(signed int), loop_ownership);
  return convert_to_cn_bits_i32((*(signed int*) cn_ptr->ptr));
}
static cn_bits_u32* owned_unsigned_int(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (unsigned int*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(unsigned int), loop_ownership);
  return convert_to_cn_bits_u32((*(unsigned int*) cn_ptr->ptr));
}
static cn_bits_u64* owned_unsigned_long_long(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (unsigned long long*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(unsigned long long), loop_ownership);
  return convert_to_cn_bits_u64((*(unsigned long long*) cn_ptr->ptr));
}
static cn_pointer* owned_struct_hyp_pool_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (struct hyp_pool**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_pool*), loop_ownership);
  return convert_to_cn_pointer((*(struct hyp_pool**) cn_ptr->ptr));
}
static cn_bits_u8* owned_unsigned_char(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (unsigned char*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(unsigned char), loop_ownership);
  return convert_to_cn_bits_u8((*(unsigned char*) cn_ptr->ptr));
}
static cn_pointer* owned_struct_hyp_page_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (struct hyp_page**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_page*), loop_ownership);
  return convert_to_cn_pointer((*(struct hyp_page**) cn_ptr->ptr));
}
static cn_bits_i64* owned_signed_long_long(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (signed long long*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(signed long long), loop_ownership);
  return convert_to_cn_bits_i64((*(signed long long*) cn_ptr->ptr));
}
static cn_pointer* owned_void_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (void**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(void*), loop_ownership);
  return convert_to_cn_pointer((*(void**) cn_ptr->ptr));
}
static cn_bits_u8* owned_char(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (char*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(char), loop_ownership);
  return convert_to_cn_bits_u8((*(char*) cn_ptr->ptr));
}
static struct hyp_pool_cn* owned_struct_hyp_pool(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (struct hyp_pool*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_pool), loop_ownership);
  return convert_to_struct_hyp_pool_cn((*(struct hyp_pool*) cn_ptr->ptr));
}
static struct hyp_page_cn* owned_struct_hyp_page(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (struct hyp_page*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_page), loop_ownership);
  return convert_to_struct_hyp_page_cn((*(struct hyp_page*) cn_ptr->ptr));
}
static struct list_head_cn* owned_struct_list_head(cn_pointer* cn_ptr, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  void* generic_c_ptr = (void*) (struct list_head*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct list_head), loop_ownership);
  return convert_to_struct_list_head_cn((*(struct list_head*) cn_ptr->ptr));
}
/* CN FUNCTIONS */
static struct list_head_cn* todo_default_list_head()
{
  struct list_head_cn* a_13791 = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  a_13791->next = convert_to_cn_pointer(0);
  a_13791->prev = convert_to_cn_pointer(0);
  return a_13791;
}
static cn_pointer* virt(cn_pointer* phys, cn_bits_i64* physvirt_offset)
{
  return cn_array_shift(phys, sizeof(char), cn_bits_i64_sub(convert_to_cn_bits_i64(0LL), physvirt_offset));
}
static cn_bits_u8* get_order_uf(cn_bits_u64* size)
{
  return cast_cn_bits_u64_to_cn_bits_u8(cn_bits_u64_flsl(cn_bits_u64_shift_right(cn_bits_u64_sub(size, convert_to_cn_bits_u64(1ULL)), convert_to_cn_bits_u64(12ULL))));
}
static cn_bool* hyp_pool_wf(cn_pointer* pool_pointer, struct hyp_pool_cn* pool, cn_pointer* vmemmap_pointer, cn_bits_i64* physvirt_offset)
{
  cn_bits_u64* range_start = pool->range_start;
  cn_bits_u64* range_end = pool->range_end;
  cn_bits_u64* start_i = cn_bits_u64_divide(range_start, page_size());
  cn_bits_u64* end_i = cn_bits_u64_divide(range_end, page_size());
  cn_bits_u64* hp_sz = convert_to_cn_bits_u64(sizeof(struct hyp_page));
  cn_bits_u64* pool_sz = convert_to_cn_bits_u64(sizeof(struct hyp_pool));
  cn_pointer* vmemmap_start_pointer = cn_array_shift(vmemmap_pointer, sizeof(struct hyp_page), start_i);
  cn_pointer* vmemmap_boundary_pointer = cn_array_shift(vmemmap_pointer, sizeof(struct hyp_page), end_i);
  cn_bits_u64* range_start_virt = cast_cn_bits_i64_to_cn_bits_u64(cn_bits_i64_sub(cast_cn_bits_u64_to_cn_bits_i64(range_start), physvirt_offset));
  cn_bits_u64* range_end_virt = cast_cn_bits_i64_to_cn_bits_u64(cn_bits_i64_sub(cast_cn_bits_u64_to_cn_bits_i64(range_end), physvirt_offset));
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_lt(range_start, range_end), cn_bits_u64_lt(range_end, cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(52ULL)))), cn_bits_i64_lt(physvirt_offset, cast_cn_bits_u64_to_cn_bits_i64(range_start))), cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_bits_i64_to_cn_bits_u64(physvirt_offset), page_size()), convert_to_cn_bits_u64(0ULL))), cn_bits_u64_equality(cn_bits_u64_multiply(cn_bits_u64_divide(range_start, page_size()), page_size()), range_start)), cn_bits_u64_equality(cn_bits_u64_multiply(cn_bits_u64_divide(range_end, page_size()), page_size()), range_end)), cn_bits_u8_le(pool->max_order, max_order())), cn_bits_u64_equality(cn_bits_u64_mod(cast_cn_pointer_to_cn_bits_u64(vmemmap_pointer), hp_sz), convert_to_cn_bits_u64(0ULL))), cn_bool_or(cn_bits_u64_le(cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(pool_pointer), pool_sz), cast_cn_pointer_to_cn_bits_u64(vmemmap_start_pointer)), cn_bits_u64_le(cast_cn_pointer_to_cn_bits_u64(vmemmap_boundary_pointer), cast_cn_pointer_to_cn_bits_u64(pool_pointer)))), cn_bool_or(cn_bits_u64_le(cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(pool_pointer), pool_sz), range_start_virt), cn_bits_u64_le(range_end_virt, cast_cn_pointer_to_cn_bits_u64(pool_pointer))));
}
static cn_bool* freeArea_cell_wf(cn_bits_u8* cell_index, cn_bits_i64* physvirt_offset, cn_pointer* virt_ptr, cn_map* vmemmap, cn_map* APs, cn_pointer* pool_pointer, struct hyp_pool_cn* pool, struct exclude_none_record* ex)
{
  struct list_head_cn* cell = (struct list_head_cn*) cn_map_get_struct_list_head_cn(pool->free_area, cast_cn_bits_u64_to_cn_integer(cast_cn_bits_u8_to_cn_bits_u64(cell_index)));
  cn_pointer* pool_free_area_arr_pointer = cn_member_shift(pool_pointer, hyp_pool, free_area);
  cn_pointer* cell_pointer = cn_array_shift(pool_free_area_arr_pointer, sizeof(struct list_head), cell_index);
  cn_pointer* prev = cell->prev;
  cn_pointer* next = cell->next;
  cn_pointer* prev_page_pointer = prev;
  cn_bits_u64* prev_page_index = cn_hyp_virt_to_pfn(physvirt_offset, prev_page_pointer);
  struct hyp_page_cn* prev_page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(prev_page_index));
  cn_pointer* next_page_pointer = next;
  cn_bits_u64* next_page_index = cn_hyp_virt_to_pfn(physvirt_offset, next_page_pointer);
  struct hyp_page_cn* next_page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(next_page_index));
  return cn_bool_and(cn_bool_equality(cn_pointer_equality(prev, cell_pointer), cn_pointer_equality(next, cell_pointer)), cn_bool_or(cn_pointer_equality(prev, cell_pointer), cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0)), vmemmap_good_pointer(physvirt_offset, prev_page_pointer, vmemmap, pool->range_start, pool->range_end, ex)), cn_bits_u8_equality(prev_page->order, cell_index)), cn_bits_u16_equality(prev_page->refcount, convert_to_cn_bits_u16(0ULL))), cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(prev_page_index)))->next, cell_pointer)), cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0))), cn_bool_or(ptr_eq(next, cell_pointer), cn_bool_not(addr_eq(next, cell_pointer)))), vmemmap_good_pointer(physvirt_offset, next_page_pointer, vmemmap, pool->range_start, pool->range_end, ex)), cn_bits_u8_equality(next_page->order, cell_index)), cn_bits_u16_equality(next_page->refcount, convert_to_cn_bits_u16(0ULL))), cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(next_page_index)))->prev, cell_pointer))));
}
static cn_bool* vmemmap_l_wf(cn_bits_u64* page_index, cn_bits_i64* physvirt_offset, cn_pointer* virt_ptr, cn_map* vmemmap, cn_map* APs, cn_pointer* pool_pointer, struct hyp_pool_cn* pool, struct exclude_none_record* ex)
{
  struct hyp_page_cn* page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(page_index));
  cn_pointer* self_node_pointer = cn__hyp_va(virt_ptr, physvirt_offset, cn_hyp_pfn_to_phys(page_index));
  cn_pointer* pool_free_area_arr_pointer = cn_member_shift(pool_pointer, hyp_pool, free_area);
  cn_pointer* pool_free_area_pointer = cn_array_shift(pool_free_area_arr_pointer, sizeof(struct list_head), page->order);
  cn_pointer* prev = ((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(page_index)))->prev;
  cn_pointer* next = ((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(page_index)))->next;
  struct list_head_cn* free_area_entry = (struct list_head_cn*) cn_map_get_struct_list_head_cn(pool->free_area, cast_cn_bits_u64_to_cn_integer(cast_cn_bits_u8_to_cn_bits_u64(page->order)));
  cn_pointer* prev_page_pointer = prev;
  cn_bits_u64* prev_page_index = cn_hyp_virt_to_pfn(physvirt_offset, prev_page_pointer);
  struct hyp_page_cn* prev_page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(prev_page_index));
  cn_pointer* next_page_pointer = next;
  cn_bits_u64* next_page_index = cn_hyp_virt_to_pfn(physvirt_offset, next_page_pointer);
  struct hyp_page_cn* next_page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(next_page_index));
  cn_alloc_id* prov = convert_to_cn_alloc_id(0);
  cn_bool* prev_clause = cn_bool_or(cn_bool_and(cn_pointer_equality(prev, pool_free_area_pointer), cn_pointer_equality(free_area_entry->next, self_node_pointer)), cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(vmemmap_good_pointer(physvirt_offset, prev_page_pointer, vmemmap, pool->range_start, pool->range_end, ex), cn_alloc_id_equality(prov, convert_to_cn_alloc_id(0))), cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(prev_page_index)))->next, self_node_pointer)), cn_bits_u8_equality(prev_page->order, page->order)), cn_bits_u16_equality(prev_page->refcount, convert_to_cn_bits_u16(0ULL))));
  cn_bool* next_clause = cn_bool_or(cn_bool_and(cn_pointer_equality(next, pool_free_area_pointer), cn_pointer_equality(free_area_entry->prev, self_node_pointer)), cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(vmemmap_good_pointer(physvirt_offset, next_page_pointer, vmemmap, pool->range_start, pool->range_end, ex), cn_alloc_id_equality(prov, convert_to_cn_alloc_id(0))), cn_pointer_equality(((struct list_head_cn*) cn_map_get_struct_list_head_cn(APs, cast_cn_bits_u64_to_cn_integer(next_page_index)))->prev, self_node_pointer)), cn_bits_u8_equality(next_page->order, page->order)), cn_bits_u16_equality(next_page->refcount, convert_to_cn_bits_u16(0ULL))));
  cn_bool* nonempty_clause = cn_bool_and(cn_bool_not(cn_pointer_equality(prev, self_node_pointer)), cn_bool_not(cn_pointer_equality(next, self_node_pointer)));
  return cn_bool_and(prev_clause, next_clause);
}
static cn_bool* vmemmap_wf(cn_bits_u64* page_index, cn_map* vmemmap, cn_pointer* pool_pointer, struct hyp_pool_cn* pool)
{
  struct hyp_page_cn* page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(page_index));
  return cn_bool_and(cn_bool_and(cn_bool_or(cn_bits_u8_equality(page->order, hyp_no_order()), vmemmap_normal_order_wf(page_index, page, pool)), cn_bool_or(cn_bool_not(cn_bits_u8_equality(page->order, hyp_no_order())), cn_bits_u16_equality(page->refcount, convert_to_cn_bits_u16(0ULL)))), page_group_ok(page_index, vmemmap, pool));
}
static cn_bool* vmemmap_normal_order_wf(cn_bits_u64* page_index, struct hyp_page_cn* page, struct hyp_pool_cn* pool)
{
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u8_le(convert_to_cn_bits_u8(0UL), page->order), cn_bool_and(cn_bits_u8_lt(page->order, pool->max_order), cn_bits_u8_lt(page->order, max_order()))), order_aligned(page_index, page->order)), cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(page_index, page_size()), page_size_of_order(page->order)), pool->range_end));
}
static cn_bool* init_vmemmap_page(cn_bits_u64* page_index, cn_map* vmemmap, cn_pointer* pool_pointer, struct hyp_pool_cn* pool)
{
  struct hyp_page_cn* page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(page_index));
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u8_equality(page->order, convert_to_cn_bits_u8(0UL)), cn_bits_u16_equality(page->refcount, convert_to_cn_bits_u16(1ULL))), order_aligned(page_index, convert_to_cn_bits_u8(0UL))), cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(page_index, page_size()), page_size_of_order(page->order)), pool->range_end));
}
static cn_bool* page_group_ok(cn_bits_u64* page_index, cn_map* vmemmap, struct hyp_pool_cn* pool)
{
  struct hyp_page_cn* page = (struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(page_index));
  cn_bits_u64* start_i = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bool* a_13289 = convert_to_cn_bool(true);
  {
    cn_bits_u8* i = convert_to_cn_bits_u8(1);
    while (convert_from_cn_bool(cn_bits_u8_lt(i, convert_to_cn_bits_u8(10)))) {
      a_13289 = cn_bool_and(a_13289, not(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_lt(order_align(page_index, i), page_index), cn_bits_u64_le(start_i, order_align(page_index, i))), cn_bits_u8_le(i, ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(order_align(page_index, i))))->order)), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(order_align(page_index, i))))->order, hyp_no_order())))));
      cn_bits_u8_increment(i);
    }
  }
  return cn_bool_or(cn_bits_u8_equality(page->order, hyp_no_order()), a_13289);
}
static cn_bool* vmemmap_good_pointer(cn_bits_i64* physvirt_offset, cn_pointer* p, cn_map* vmemmap, cn_bits_u64* range_start, cn_bits_u64* range_end, struct exclude_none_record* ex)
{
  cn_bits_u64* pa = cn__hyp_pa(physvirt_offset, p);
  cn_bits_u64* pfn = cn_hyp_phys_to_pfn(pa);
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_equality(cn_bits_u64_mod(pa, page_size()), convert_to_cn_bits_u64(0ULL)), cn_bits_u64_le(range_start, pa)), cn_bits_u64_lt(pa, range_end)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(pfn)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(vmemmap, cast_cn_bits_u64_to_cn_integer(pfn)))->order, hyp_no_order()))), not(excluded(ex, pfn)));
}
static struct exclude_none_record* exclude_two(cn_bits_u64* ex1, cn_bits_u64* ex2)
{
  struct exclude_none_record* a_13185 = (struct exclude_none_record*) cn_bump_malloc(sizeof(struct exclude_none_record));
  a_13185->any = convert_to_cn_bool(true);
  a_13185->do_ex1 = convert_to_cn_bool(true);
  a_13185->do_ex2 = convert_to_cn_bool(true);
  a_13185->ex1 = ex1;
  a_13185->ex2 = ex2;
  return a_13185;
}
static struct exclude_none_record* exclude_one(cn_bits_u64* ex1)
{
  struct exclude_none_record* a_13169 = (struct exclude_none_record*) cn_bump_malloc(sizeof(struct exclude_none_record));
  a_13169->any = convert_to_cn_bool(true);
  a_13169->do_ex1 = convert_to_cn_bool(true);
  a_13169->do_ex2 = convert_to_cn_bool(false);
  a_13169->ex1 = ex1;
  a_13169->ex2 = convert_to_cn_bits_u64(0ULL);
  return a_13169;
}
static struct exclude_none_record* exclude_none()
{
  struct exclude_none_record* a_13152 = (struct exclude_none_record*) cn_bump_malloc(sizeof(struct exclude_none_record));
  a_13152->any = convert_to_cn_bool(false);
  a_13152->do_ex1 = convert_to_cn_bool(false);
  a_13152->do_ex2 = convert_to_cn_bool(false);
  a_13152->ex1 = convert_to_cn_bits_u64(0ULL);
  a_13152->ex2 = convert_to_cn_bits_u64(0ULL);
  return a_13152;
}
static cn_bool* excluded(struct exclude_none_record* ex, cn_bits_u64* i)
{
  return cn_bool_and(ex->any, cn_bool_or(cn_bool_and(ex->do_ex1, cn_bits_u64_equality(i, ex->ex1)), cn_bool_and(ex->do_ex2, cn_bits_u64_equality(i, ex->ex2))));
}
static cn_bool* page_aligned(cn_bits_u64* ptr, cn_bits_u8* order)
{
  return cn_bits_u64_equality(cn_bits_u64_mod(ptr, page_size_of_order(order)), convert_to_cn_bits_u64(0ULL));
}
static cn_bits_u64* page_size_of_order(cn_bits_u8* order)
{
  return cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), cn_bits_u64_add(cast_cn_bits_u8_to_cn_bits_u64(order), convert_to_cn_bits_u64(12ULL)));
}
static cn_bool* cellPointer(cn_pointer* base, cn_bits_u64* size, cn_bits_u64* starti, cn_bits_u64* endi, cn_pointer* p)
{
  cn_bits_u64* offset = cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(base), cast_cn_pointer_to_cn_bits_u64(p));
  cn_pointer* start = cn_array_shift(base, sizeof(char), cn_bits_u64_multiply(size, starti));
  cn_pointer* end = cn_array_shift(base, sizeof(char), cn_bits_u64_multiply(size, endi));
  return cn_bool_and(cn_bool_and(cn_pointer_le(start, p), cn_pointer_lt(p, end)), cn_bits_u64_equality(cn_bits_u64_mod(offset, size), convert_to_cn_bits_u64(0ULL)));
}
static cn_bits_u64* order_align(cn_bits_u64* x, cn_bits_u8* order)
{
  return cn_bits_u64_sub(x, cn_bits_u64_mod(x, cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), cast_cn_bits_u8_to_cn_bits_u64(order))));
}
static cn_bool* order_aligned(cn_bits_u64* x, cn_bits_u8* order)
{
  return cn_bits_u64_equality(cn_bits_u64_mod(x, cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), cast_cn_bits_u8_to_cn_bits_u64(order))), convert_to_cn_bits_u64(0ULL));
}
static cn_bits_u64* pfn_buddy(cn_bits_u64* x, cn_bits_u8* order)
{
  return cn_hyp_phys_to_pfn(calc_buddy(cn_hyp_pfn_to_phys(x), order));
}
static cn_bits_u64* calc_buddy(cn_bits_u64* addr, cn_bits_u8* order)
{
  return cn_bits_u64_xor(addr, cn_bits_u64_shift_left(page_size(), cast_cn_bits_u8_to_cn_bits_u64(order)));
}
static cn_pointer* cn_hyp_page_to_virt(cn_pointer* virt_ptr, cn_bits_i64* physvirtoffset, cn_pointer* hypvmemmap, cn_pointer* page)
{
  return cn__hyp_va(virt_ptr, physvirtoffset, cn_hyp_page_to_phys(hypvmemmap, page));
}
static cn_pointer* cn__hyp_va(cn_pointer* virt_ptr, cn_bits_i64* physvirtoffset, cn_bits_u64* phys)
{
  return copy_alloc_id_cn(cast_cn_bits_i64_to_cn_bits_u64(cn_bits_i64_sub(cast_cn_bits_u64_to_cn_bits_i64(phys), physvirtoffset)), virt_ptr);
}
static cn_bits_u64* cn_hyp_page_to_phys(cn_pointer* hypvmemmap, cn_pointer* page)
{
  return cn_hyp_pfn_to_phys(cn_hyp_page_to_pfn(hypvmemmap, page));
}
static cn_bits_u64* cn_hyp_pfn_to_phys(cn_bits_u64* pfn)
{
  return cn_bits_u64_multiply(pfn, page_size());
}
static cn_bits_u64* cn_hyp_virt_to_pfn(cn_bits_i64* physvirtoffset, cn_pointer* virt)
{
  return cn_hyp_phys_to_pfn(cn__hyp_pa(physvirtoffset, virt));
}
static cn_bits_u64* cn_hyp_phys_to_pfn(cn_bits_u64* phys)
{
  return cn_bits_u64_divide(phys, page_size());
}
static cn_bits_u64* cn__hyp_pa(cn_bits_i64* physvirtoffset, cn_pointer* virt)
{
  return cast_cn_bits_i64_to_cn_bits_u64(cn_bits_i64_add(cast_cn_pointer_to_cn_bits_i64(virt), physvirtoffset));
}
static cn_bits_u64* cn_hyp_page_to_pfn(cn_pointer* hypvmemmap, cn_pointer* p)
{
  return cn_bits_u64_divide(cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(p), cast_cn_pointer_to_cn_bits_u64(hypvmemmap)), cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(sizeof(struct hyp_page))));
}
static cn_bits_u8* hyp_no_order()
{
  return convert_to_cn_bits_u8(255UL);
}
static cn_bits_u8* max_order()
{
  return convert_to_cn_bits_u8(11UL);
}
static cn_bits_u64* page_size()
{
  return convert_to_cn_bits_u64(4096ULL);
}
static cn_pointer* copy_alloc_id_cn(cn_bits_u64* x, cn_pointer* p)
{
  return cn_array_shift(p, sizeof(char), cn_bits_u64_sub(x, cast_cn_pointer_to_cn_bits_u64(p)));
}
static cn_bits_u64* max_pfn()
{
  return cn_bits_u64_shift_right(cn_bits_u64_sub(convert_to_cn_bits_u64(0ULL), convert_to_cn_bits_u64(1ULL)), cast_cn_bits_i32_to_cn_bits_u64(convert_to_cn_bits_i32(12LL)));
}
static cn_bool* addr_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_bits_u64_equality(cast_cn_pointer_to_cn_bits_u64(arg1), cast_cn_pointer_to_cn_bits_u64(arg2));
}
static cn_bool* prov_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0));
}
static cn_bool* ptr_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_pointer_equality(arg1, arg2);
}
static cn_bool* is_null(cn_pointer* arg)
{
  return cn_pointer_equality(arg, convert_to_cn_pointer(0));
}
static cn_bool* not(cn_bool* arg)
{
  return cn_bool_not(arg);
}
static cn_bits_u8* MINu8()
{
  return convert_to_cn_bits_u8(0UL);
}
static cn_bits_u8* MAXu8()
{
  return convert_to_cn_bits_u8(255UL);
}
static cn_bits_u16* MINu16()
{
  return convert_to_cn_bits_u16(0ULL);
}
static cn_bits_u16* MAXu16()
{
  return convert_to_cn_bits_u16(65535ULL);
}
static cn_bits_u32* MINu32()
{
  return convert_to_cn_bits_u32(0ULL);
}
static cn_bits_u32* MAXu32()
{
  return convert_to_cn_bits_u32(4294967295ULL);
}
static cn_bits_u64* MINu64()
{
  return convert_to_cn_bits_u64(0ULL);
}
static cn_bits_u64* MAXu64()
{
  return convert_to_cn_bits_u64(18446744073709551615ULL);
}
static cn_bits_i8* MINi8()
{
  return convert_to_cn_bits_i8((-127L - 1L));
}
static cn_bits_i8* MAXi8()
{
  return convert_to_cn_bits_i8(127L);
}
static cn_bits_i16* MINi16()
{
  return convert_to_cn_bits_i16((-32767LL - 1LL));
}
static cn_bits_i16* MAXi16()
{
  return convert_to_cn_bits_i16(32767LL);
}
static cn_bits_i32* MINi32()
{
  return convert_to_cn_bits_i32((-2147483647LL - 1LL));
}
static cn_bits_i32* MAXi32()
{
  return convert_to_cn_bits_i32(2147483647LL);
}
static cn_bits_i64* MINi64()
{
  return convert_to_cn_bits_i64((-9223372036854775807LL - 1LL));
}
static cn_bits_i64* MAXi64()
{
  return convert_to_cn_bits_i64(9223372036854775807LL);
}


/* CN PREDICATES */

static struct list_head_cn* O_struct_list_head(cn_pointer* p, cn_bool* condition, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  if (convert_from_cn_bool(condition)) {
    update_cn_error_message_info("lemma order_dec_inv (u64 pool_range_end, // phys_addr_t\n         ^./driver.pp.c:880:10:");
    struct list_head_cn* v = owned_struct_list_head(p, spec_mode, loop_ownership);
    cn_pop_msg_info();
    return v;
  }
  else {
    return todo_default_list_head();
  }
}
static struct Hyp_pool_ex1_record* Hyp_pool(cn_pointer* pool_l, cn_pointer* vmemmap_l, cn_pointer* virt_ptr, cn_bits_i64* physvirt_offset, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  struct exclude_none_record* ex;
  ex = exclude_none();
  update_cn_error_message_info("                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};\n       ^./driver.pp.c:850:8:");
  struct hyp_pool_cn* P = owned_struct_hyp_pool(pool_l, spec_mode, loop_ownership);
  cn_pop_msg_info();
  cn_bits_u64* start_i;
  start_i = cn_bits_u64_divide(P->range_start, page_size());
  cn_bits_u64* end_i;
  end_i = cn_bits_u64_divide(P->range_end, page_size());
  update_cn_error_message_info("  assert (each (u64 i; (start_i <= i) && (i < end_i)\n       ^./driver.pp.c:853:8:");
  cn_map* V = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        cn_pointer* a_14500 = cn_array_shift(vmemmap_l, sizeof(struct hyp_page), i);
        cn_map_set(V, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_14500, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("            && ((V[i]).order != (hyp_no_order ()))\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:855:3-871:41");
  cn_assert(hyp_pool_wf(pool_l, P, vmemmap_l, physvirt_offset), spec_mode);
  cn_pop_msg_info();
  cn_pointer* ptr_phys_0;
  ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, convert_to_cn_bits_u64(0ULL));
  update_cn_error_message_info("    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, P, ex)});\n       ^./driver.pp.c:857:8:");
  cn_map* APs = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        cn_pointer* a_14593 = cn_array_shift(ptr_phys_0, sizeof(char[4096]), i);
        cn_map_set(APs, cast_cn_bits_u64_to_cn_integer(i), AllocatorPage(a_14593, convert_to_cn_bool(true), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("\n  ^./driver.pp.c:862:3-871:41");
  cn_bool* a_14627 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        a_14627 = cn_bool_and(a_14627, vmemmap_wf(i, V, pool_l, P));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14627, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("\n  ^./driver.pp.c:864:3-871:41");
  cn_bool* a_14677 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        a_14677 = cn_bool_and(a_14677, vmemmap_l_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, P, ex));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14677, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("    take v = Owned<struct list_head>(p);\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:869:3-871:41");
  cn_bool* a_14706 = convert_to_cn_bool(true);
  {
    cn_bits_u8* i = cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL)), i), cn_bits_u8_lt(i, P->max_order)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(convert_to_cn_bits_u8(0UL), i), cn_bits_u8_lt(i, P->max_order)))) {
        a_14706 = cn_bool_and(a_14706, freeArea_cell_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, P, ex));
      }
      else {
        ;
      }
      cn_bits_u8_increment(i);
    }
  }
  cn_assert(a_14706, spec_mode);
  cn_pop_msg_info();
  struct Hyp_pool_ex1_record* a_14717 = (struct Hyp_pool_ex1_record*) cn_bump_malloc(sizeof(struct Hyp_pool_ex1_record));
  a_14717->APs = APs;
  a_14717->pool = P;
  a_14717->vmemmap = V;
  return a_14717;
}
static struct Hyp_pool_ex1_record* Hyp_pool_ex2(cn_pointer* pool_l, cn_pointer* vmemmap_l, cn_pointer* virt_ptr, cn_bits_i64* physvirt_offset, cn_bits_u64* ex1, cn_bits_u64* ex2, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  struct exclude_none_record* ex;
  ex = exclude_two(ex1, ex2);
  update_cn_error_message_info("                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};\n       ^./driver.pp.c:813:8:");
  struct hyp_pool_cn* pool = owned_struct_hyp_pool(pool_l, spec_mode, loop_ownership);
  cn_pop_msg_info();
  cn_bits_u64* start_i;
  start_i = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bits_u64* end_i;
  end_i = cn_bits_u64_divide(pool->range_end, page_size());
  update_cn_error_message_info("  assert (each (u64 i; (start_i <= i) && (i < end_i)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:816:3-834:44");
  cn_assert(hyp_pool_wf(pool_l, pool, vmemmap_l, physvirt_offset), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("            && ((V[i]).refcount == 0u16)\n       ^./driver.pp.c:817:8:");
  cn_map* V = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        cn_pointer* a_14246 = cn_array_shift(vmemmap_l, sizeof(struct hyp_page), i);
        cn_map_set(V, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_14246, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  cn_pointer* ptr_phys_0;
  ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, convert_to_cn_bits_u64(0ULL));
  update_cn_error_message_info("    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});\n       ^./driver.pp.c:820:8:");
  cn_map* APs = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        cn_pointer* a_14338 = cn_array_shift(ptr_phys_0, sizeof(char[4096]), i);
        cn_map_set(APs, cast_cn_bits_u64_to_cn_integer(i), AllocatorPage(a_14338, convert_to_cn_bool(true), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("\n  ^./driver.pp.c:825:3-834:44");
  cn_bool* a_14372 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        a_14372 = cn_bool_and(a_14372, vmemmap_wf(i, V, pool_l, pool));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14372, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_pool pool\n  ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:827:3-834:44");
  cn_bool* a_14422 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        a_14422 = cn_bool_and(a_14422, vmemmap_l_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14422, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("    pointer pool_l\n  ^~~~~~~~~~~~~~~~ ./driver.pp.c:832:3-834:44");
  cn_bool* a_14451 = convert_to_cn_bool(true);
  {
    cn_bits_u8* i = cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL)), i), cn_bits_u8_lt(i, pool->max_order)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(convert_to_cn_bits_u8(0UL), i), cn_bits_u8_lt(i, pool->max_order)))) {
        a_14451 = cn_bool_and(a_14451, freeArea_cell_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex));
      }
      else {
        ;
      }
      cn_bits_u8_increment(i);
    }
  }
  cn_assert(a_14451, spec_mode);
  cn_pop_msg_info();
  struct Hyp_pool_ex1_record* a_14462 = (struct Hyp_pool_ex1_record*) cn_bump_malloc(sizeof(struct Hyp_pool_ex1_record));
  a_14462->APs = APs;
  a_14462->pool = pool;
  a_14462->vmemmap = V;
  return a_14462;
}
static struct Hyp_pool_ex1_record* Hyp_pool_ex1(cn_pointer* pool_l, cn_pointer* vmemmap_l, cn_pointer* virt_ptr, cn_bits_i64* physvirt_offset, cn_bits_u64* ex1, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  struct exclude_none_record* ex;
  ex = exclude_one(ex1);
  update_cn_error_message_info("                 {AllocatorPage(array_shift<PAGE_SIZE_t>(ptr_phys_0, i), true, (V[i]).order)};\n       ^./driver.pp.c:774:8:");
  struct hyp_pool_cn* pool = owned_struct_hyp_pool(pool_l, spec_mode, loop_ownership);
  cn_pop_msg_info();
  cn_bits_u64* start_i;
  start_i = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bits_u64* end_i;
  end_i = cn_bits_u64_divide(pool->range_end, page_size());
  update_cn_error_message_info("  assert (each (u64 i; (start_i <= i) && (i < end_i)\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:777:3-795:44");
  cn_assert(hyp_pool_wf(pool_l, pool, vmemmap_l, physvirt_offset), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("            && ((V[i]).refcount == 0u16)\n       ^./driver.pp.c:778:8:");
  cn_map* V = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        cn_pointer* a_13992 = cn_array_shift(vmemmap_l, sizeof(struct hyp_page), i);
        cn_map_set(V, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_13992, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  cn_pointer* ptr_phys_0;
  ptr_phys_0 = cn__hyp_va(virt_ptr, physvirt_offset, convert_to_cn_bits_u64(0ULL));
  update_cn_error_message_info("    {vmemmap_l_wf (i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex)});\n       ^./driver.pp.c:781:8:");
  cn_map* APs = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        cn_pointer* a_14084 = cn_array_shift(ptr_phys_0, sizeof(char[4096]), i);
        cn_map_set(APs, cast_cn_bits_u64_to_cn_integer(i), AllocatorPage(a_14084, convert_to_cn_bool(true), ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, spec_mode, loop_ownership));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("\n  ^./driver.pp.c:786:3-795:44");
  cn_bool* a_14118 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)))) {
        a_14118 = cn_bool_and(a_14118, vmemmap_wf(i, V, pool_l, pool));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14118, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("    struct hyp_pool pool\n  ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:788:3-795:44");
  cn_bool* a_14168 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i), i), cn_bits_u64_lt(i, end_i)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(start_i, i), cn_bits_u64_lt(i, end_i)), cn_bits_u16_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->refcount, convert_to_cn_bits_u16(0ULL))), cn_bool_not(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(i)))->order, hyp_no_order()))), not(excluded(ex, i))))) {
        a_14168 = cn_bool_and(a_14168, vmemmap_l_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_14168, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("    pointer pool_l\n  ^~~~~~~~~~~~~~~~ ./driver.pp.c:793:3-795:44");
  cn_bool* a_14197 = convert_to_cn_bool(true);
  {
    cn_bits_u8* i = cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(cast_cn_bits_u8_to_cn_bits_u8(convert_to_cn_bits_u8(0UL)), i), cn_bits_u8_lt(i, pool->max_order)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u8_le(convert_to_cn_bits_u8(0UL), i), cn_bits_u8_lt(i, pool->max_order)))) {
        a_14197 = cn_bool_and(a_14197, freeArea_cell_wf(i, physvirt_offset, virt_ptr, V, APs, pool_l, pool, ex));
      }
      else {
        ;
      }
      cn_bits_u8_increment(i);
    }
  }
  cn_assert(a_14197, spec_mode);
  cn_pop_msg_info();
  struct Hyp_pool_ex1_record* a_14208 = (struct Hyp_pool_ex1_record*) cn_bump_malloc(sizeof(struct Hyp_pool_ex1_record));
  a_14208->APs = APs;
  a_14208->pool = pool;
  a_14208->vmemmap = V;
  return a_14208;
}
static struct list_head_cn* AllocatorPage(cn_pointer* vbase, cn_bool* guard, cn_bits_u8* order, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  if (convert_from_cn_bool(cn_bool_not(guard))) {
    return todo_default_list_head();
  }
  else {
    cn_pointer* zero_start;
    zero_start = cn_array_shift(vbase, sizeof(struct list_head), convert_to_cn_bits_u8(1UL));
    update_cn_error_message_info("}\n         ^./driver.pp.c:753:10:");
    AllocatorPageZeroPart(zero_start, order, spec_mode, loop_ownership);
    cn_pop_msg_info();
    update_cn_error_message_info("Hyp_pool_ex1 (\n         ^./driver.pp.c:754:10:");
    struct list_head_cn* Node = owned_struct_list_head(vbase, spec_mode, loop_ownership);
    cn_pop_msg_info();
    return Node;
  }
}
static void AllocatorPageZeroPart(cn_pointer* zero_start, cn_bits_u8* order, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  cn_bits_u64* start;
  start = cast_cn_pointer_to_cn_bits_u64(zero_start);
  cn_bits_u64* region_length;
  region_length = page_size_of_order(order);
  cn_bits_u64* length;
  length = cn_bits_u64_sub(region_length, convert_to_cn_bits_u64(sizeof(struct list_head)));
  update_cn_error_message_info("{\n       ^./driver.pp.c:736:8:");
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start), i), cn_bits_u64_lt(i, cn_bits_u64_add(start, length))))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start, i), cn_bits_u64_lt(i, cn_bits_u64_add(start, length))))) {
        cn_pointer* a_13938 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
        ByteV(a_13938, convert_to_cn_bits_u8(0UL), spec_mode, loop_ownership);
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  return;
}
static void ZeroPage(cn_pointer* vbase, cn_bool* guard, cn_bits_u8* order, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  if (convert_from_cn_bool(cn_bool_not(guard))) {
    return;
  }
  else {
    cn_bits_u64* length;
    length = page_size_of_order(order);
    cn_bits_u64* vbaseI;
    vbaseI = cast_cn_pointer_to_cn_bits_u64(vbase);
    update_cn_error_message_info("  take Bytes = each (u64 i; (start <= i) && (i < (start + length)))\n         ^./driver.pp.c:725:10:");
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(vbaseI);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(vbaseI), i), cn_bits_u64_lt(i, cn_bits_u64_add(vbaseI, length))))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(vbaseI, i), cn_bits_u64_lt(i, cn_bits_u64_add(vbaseI, length))))) {
          cn_pointer* a_13889 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
          ByteV(a_13889, convert_to_cn_bits_u8(0UL), spec_mode, loop_ownership);
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    return;
  }
}
static void Page(cn_pointer* vbase, cn_bool* guard, cn_bits_u8* order, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  if (convert_from_cn_bool(cn_bool_not(guard))) {
    return;
  }
  else {
    cn_bits_u64* length;
    length = page_size_of_order(order);
    cn_bits_u64* vbaseI;
    vbaseI = cast_cn_pointer_to_cn_bits_u64(vbase);
    update_cn_error_message_info("  else {\n         ^./driver.pp.c:711:10:");
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(vbaseI);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(vbaseI), i), cn_bits_u64_lt(i, cn_bits_u64_add(vbaseI, length))))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(vbaseI, i), cn_bits_u64_lt(i, cn_bits_u64_add(vbaseI, length))))) {
          cn_pointer* a_13844 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
          Byte(a_13844, spec_mode, loop_ownership);
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    return;
  }
}
static void ByteV(cn_pointer* virt, cn_bits_u8* the_value, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  update_cn_error_message_info("    let length = page_size_of_order(order);\n       ^./driver.pp.c:698:8:");
  cn_bits_u8* B = owned_char(virt, spec_mode, loop_ownership);
  cn_pop_msg_info();
  update_cn_error_message_info("    let vbaseI = (u64) vbase;\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:699:3-700:9");
  cn_assert(cn_bits_u8_equality(B, the_value), spec_mode);
  cn_pop_msg_info();
  return;
}
static void Byte(cn_pointer* virt, enum spec_mode spec_mode, struct loop_ownership* loop_ownership)
{
  update_cn_error_message_info("predicate void Page (pointer vbase, boolean guard, u8 order)\n       ^./driver.pp.c:692:8:");
  cn_bits_u8* B = owned_char(virt, spec_mode, loop_ownership);
  cn_pop_msg_info();
  return;
}

/* CN LEMMAS */

static void bytes_to_struct_list_head(cn_pointer* node, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_bits_u64* length_cn;
  length_cn = page_size_of_order(order);
  cn_bits_u64* nodeI_cn;
  nodeI_cn = cast_cn_pointer_to_cn_bits_u64(node);
  update_cn_error_message_info("    requires let b_i = (u64) b;\n                ^./driver.pp.c:1057:17:");
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(nodeI_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(nodeI_cn), i), cn_bits_u64_lt(i, cn_bits_u64_add(nodeI_cn, length_cn))))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(nodeI_cn, i), cn_bits_u64_lt(i, cn_bits_u64_add(nodeI_cn, length_cn))))) {
        cn_pointer* a_15719 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
        ByteV(a_15719, convert_to_cn_bits_u8(0UL), PRE, 0);
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  {
    update_cn_error_message_info("             let c = (u8) cc;\n               ^./driver.pp.c:1058:16:");
    struct list_head_cn* Node_cn = owned_struct_list_head(node, POST, 0);
    cn_pop_msg_info();
    update_cn_error_message_info("             take B = each (u64 i; b_i <= i && i < b_i+len){Byte(array_shift<char>(NULL, i))};\n               ^./driver.pp.c:1059:16:");
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(nodeI_cn, convert_to_cn_bits_u64(sizeof(struct list_head))));
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cn_bits_u64_add(nodeI_cn, convert_to_cn_bits_u64(sizeof(struct list_head)))), i), cn_bits_u64_lt(i, cn_bits_u64_add(nodeI_cn, length_cn))))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cn_bits_u64_add(nodeI_cn, convert_to_cn_bits_u64(sizeof(struct list_head))), i), cn_bits_u64_lt(i, cn_bits_u64_add(nodeI_cn, length_cn))))) {
          cn_pointer* a_15775 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
          ByteV(a_15775, convert_to_cn_bits_u8(0UL), POST, 0);
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void struct_list_head_to_bytes(cn_pointer* node)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("\n                ^./driver.pp.c:1049:17:");
  struct list_head_cn* Node_cn = owned_struct_list_head(node, PRE, 0);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("@*/\n               ^./driver.pp.c:1050:16:");
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(cast_cn_pointer_to_cn_bits_u64(node));
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(cast_cn_pointer_to_cn_bits_u64(node)), i), cn_bits_u64_lt(i, cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(node), convert_to_cn_bits_u64(sizeof(struct list_head))))))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_pointer_to_cn_bits_u64(node), i), cn_bits_u64_lt(i, cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(node), convert_to_cn_bits_u64(sizeof(struct list_head))))))) {
          cn_pointer* a_15666 = cn_array_shift(convert_to_cn_pointer(0), sizeof(char), i);
          Byte(a_15666, POST, 0);
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void page_size_of_order2(cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("\n           ^~~~~~~~~~~~~ ./driver.pp.c:1041:12-25");
  cn_assert(cn_bits_u8_lt(order, convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("lemma bytes_to_struct_list_head(pointer node, // struct list_head *\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1042:11-47");
    cn_assert(cn_bits_u64_lt(convert_to_cn_bits_u64(0ULL), cn_bits_u64_pow(convert_to_cn_bits_u64(2ULL), cast_cn_bits_u8_to_cn_bits_u64(order))), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("                                u8 order)\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1043:11-66");
    cn_assert(cn_bits_u64_lt(cn_bits_u64_pow(convert_to_cn_bits_u64(2ULL), cast_cn_bits_u8_to_cn_bits_u64(order)), cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(11ULL))), POST);
    cn_pop_msg_info();
    cn_bits_u64* size_cn;
    size_cn = cn_bits_u64_multiply(page_size(), cn_bits_u64_pow(convert_to_cn_bits_u64(2ULL), cast_cn_bits_u8_to_cn_bits_u64(order)));
    update_cn_error_message_info("           let nodeI = ((u64) node) ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1045:11-47");
    cn_assert(cn_bits_u64_equality(size_cn, page_size_of_order(order)), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void find_buddy_xor(cn_bits_u64* addr_i, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1027:12-42");
  cn_assert(order_aligned(addr_i, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n           ^~~~~~~~~~~~~ ./driver.pp.c:1028:12-25");
  cn_assert(cn_bits_u8_lt(order, convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  {
    cn_bits_u64* two_to_order_cn;
    two_to_order_cn = cn_bits_u64_pow(convert_to_cn_bits_u64(2ULL), cast_cn_bits_u8_to_cn_bits_u64(order));
    update_cn_error_message_info("  requires order < 11u8;\n          ^~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1030:11-32");
    cn_assert(cn_bits_u64_lt(convert_to_cn_bits_u64(0ULL), two_to_order_cn), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("  ensures 0u64 < power_uf(2u64, (u64) order) ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1031:11-51");
    cn_assert(cn_bits_u64_lt(two_to_order_cn, cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(11ULL))), POST);
    cn_pop_msg_info();
    cn_bits_u64* buddy_addr_cn;
    buddy_addr_cn = calc_buddy(cn_bits_u64_multiply(addr_i, page_size()), order);
    cn_bits_u64* buddy_i_cn;
    buddy_i_cn = cn_bits_u64_divide(buddy_addr_cn, page_size());
    update_cn_error_message_info("          size == (page_size_of_order(order));\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1034:11-51");
    cn_assert(cn_bits_u64_equality(buddy_i_cn, pfn_buddy(addr_i, order)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1035:11-51");
    cn_assert(cn_bits_u64_equality(cn_bits_u64_mod(buddy_addr_cn, page_size()), convert_to_cn_bits_u64(0ULL)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1036:11-42");
    cn_assert(order_aligned(buddy_i_cn, order), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("lemma struct_list_head_to_bytes(pointer node) // struct list_head * \n          ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:1037:11-29");
    cn_assert(cn_bool_not(cn_bits_u64_equality(addr_i, buddy_i_cn)), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void attach_inc_loop(cn_map* V, cn_pointer* __hypvmemmap, struct hyp_pool_cn* pool, cn_pointer* p, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_pointer* hypvmemmap_cn;
  hypvmemmap_cn = __hypvmemmap;
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(pool->range_end, page_size());
  update_cn_error_message_info("          let min_i = (p_i < buddy_i) ? p_i : buddy_i ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1005:11-61");
  cn_assert(cellPointer(hypvmemmap_cn, convert_to_cn_bits_u64(4ULL), start_i_cn, end_i_cn, p), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_bits_u64_divide(cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(p), cast_cn_pointer_to_cn_bits_u64(__hypvmemmap)), convert_to_cn_bits_u64(4ULL));
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i_cn, order);
  cn_bits_u8* buddy_order_cn;
  buddy_order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->order;
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1009:11-30");
  cn_assert(cn_bits_u64_le(start_i_cn, buddy_i_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n                              ^~~~~~~~~~~~~~~~~ ./driver.pp.c:1009:31-48");
  cn_assert(cn_bits_u64_lt(buddy_i_cn, end_i_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1010:11-30");
  cn_assert(cn_bits_u8_lt(cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL)), convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n                              ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1010:31-53");
  cn_assert(cn_bits_u8_equality(buddy_order_cn, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1011:11-38");
  cn_assert(order_aligned(p_i_cn, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1012:11-42");
  cn_assert(order_aligned(buddy_i_cn, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("// TODO: is this (and other) lemma even useful anymore?\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1013:11-48");
  cn_assert(cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order, hyp_no_order()), PRE);
  cn_pop_msg_info();
  struct hyp_page_cn* p_page_tweaked_cn;
  struct hyp_page_cn* a_15378 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
  a_15378->refcount = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount;
  a_15378->order = order;
  a_15378->flags = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->flags;
  p_page_tweaked_cn = a_15378;
  update_cn_error_message_info("                     u8 order) // unsigned int\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1015:11-102");
  cn_bool* a_15399 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        cn_map* a_15395 = cn_map_deep_copy(V);
        a_15399 = cn_bool_and(a_15399, page_group_ok(i, cn_map_set(a_15395, cast_cn_bits_u64_to_cn_integer(p_i_cn), p_page_tweaked_cn), pool));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_15399, PRE);
  cn_pop_msg_info();
  cn_bits_u64* min_i_cn;
  cn_bits_u64* a_15413;
  if (convert_from_cn_bool(cn_bits_u64_lt(p_i_cn, buddy_i_cn))) {
    a_15413 = p_i_cn;
  }
  else {
    a_15413 = buddy_i_cn;
  }
  min_i_cn = a_15413;
  struct hyp_page_cn* min_page_cn;
  struct hyp_page_cn* a_15429 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
  a_15429->refcount = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(min_i_cn)))->refcount;
  a_15429->order = cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL));
  a_15429->flags = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(min_i_cn)))->flags;
  min_page_cn = a_15429;
  struct hyp_page_cn* buddy_page_cn;
  struct hyp_page_cn* a_15440 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
  a_15440->refcount = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->refcount;
  a_15440->order = hyp_no_order();
  a_15440->flags = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->flags;
  buddy_page_cn = a_15440;
  {
    update_cn_error_message_info("          0u64 < two_to_order ;\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:1019:10-116");
    cn_bool* a_15468 = convert_to_cn_bool(true);
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
          cn_map* a_15457 = cn_map_deep_copy(V);
          cn_map* a_15464 = cn_map_deep_copy(cn_map_set(a_15457, cast_cn_bits_u64_to_cn_integer(buddy_i_cn), buddy_page_cn));
          a_15468 = cn_bool_and(a_15468, page_group_ok(i, cn_map_set(a_15464, cast_cn_bits_u64_to_cn_integer(min_i_cn), min_page_cn), pool));
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_assert(a_15468, POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void page_size_of_order_lemma()
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  {
    update_cn_error_message_info("          cellPointer(hypvmemmap, 4u64, start_i, end_i, p) ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:994:11-52");
    cn_assert(cn_bits_u64_equality(page_size_of_order(convert_to_cn_bits_u8(0UL)), page_size()), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void order_aligned_init(cn_bits_u64* i)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  {
    update_cn_error_message_info("                            u8 order) // unsigned int\n          ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:990:11-33");
    cn_assert(order_aligned(i, convert_to_cn_bits_u8(0UL)), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void page_group_ok_easy(cn_pointer* __hypvmemmap, struct hyp_pool_cn* pool)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_pointer* hypvmemmap_cn;
  hypvmemmap_cn = __hypvmemmap;
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(pool->range_end, page_size());
  update_cn_error_message_info("lemma page_size_of_order_lemma ()\n                ^./driver.pp.c:981:17:");
  cn_map* V_cn = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        cn_pointer* a_15141 = cn_array_shift(hypvmemmap_cn, sizeof(struct hyp_page), i);
        cn_map_set(V_cn, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_15141, PRE, 0));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("  requires true;\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:982:12-76");
  cn_bool* a_15179 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        a_15179 = cn_bool_and(a_15179, cn_bits_u8_equality(((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V_cn, cast_cn_bits_u64_to_cn_integer(i)))->order, convert_to_cn_bits_u8(0UL)));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_15179, PRE);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("  ensures (page_size_of_order(0u8)) == page_size();\n               ^./driver.pp.c:983:16:");
    cn_map* V2_cn = map_create();
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
          cn_pointer* a_15213 = cn_array_shift(hypvmemmap_cn, sizeof(struct hyp_page), i);
          cn_map_set(V2_cn, cast_cn_bits_u64_to_cn_integer(i), owned_struct_hyp_page(a_15213, POST, 0));
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    update_cn_error_message_info("\n          ^~~~~~~~~ ./driver.pp.c:984:11-20");
    cn_assert(cn_map_equality(V2_cn, V_cn, struct_hyp_page_cn_equality), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:985:11-81");
    cn_bool* a_15245 = convert_to_cn_bool(true);
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
          a_15245 = cn_bool_and(a_15245, page_group_ok(i, V2_cn, pool));
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_assert(a_15245, POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void order_align_inv_loop(cn_pointer* __hypvmemmap, cn_map* V, struct hyp_pool_cn* pool, cn_pointer* p)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_pointer* hypvmemmap_cn;
  hypvmemmap_cn = __hypvmemmap;
  cn_bits_u64* p_i_cn;
  p_i_cn = cn_bits_u64_divide(cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(p), cast_cn_pointer_to_cn_bits_u64(__hypvmemmap)), convert_to_cn_bits_u64(4ULL));
  cn_bits_u64* start_i_cn;
  start_i_cn = cn_bits_u64_divide(pool->range_start, page_size());
  cn_bits_u64* end_i_cn;
  end_i_cn = cn_bits_u64_divide(pool->range_end, page_size());
  cn_bits_u8* p_order_cn;
  p_order_cn = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->order;
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~ ./driver.pp.c:965:11-26");
  cn_assert(cn_bits_u8_le(convert_to_cn_bits_u8(1UL), p_order_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n                          ^~~~~~~~~~~~~~~~ ./driver.pp.c:965:27-43");
  cn_assert(cn_bits_u8_lt(p_order_cn, convert_to_cn_bits_u8(11UL)), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("lemma page_group_ok_easy (pointer __hypvmemmap, struct hyp_pool pool)\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:966:11-40");
  cn_assert(order_aligned(p_i_cn, p_order_cn), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("  requires let hypvmemmap = __hypvmemmap ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:967:11-61");
  cn_assert(cellPointer(hypvmemmap_cn, convert_to_cn_bits_u64(4ULL), start_i_cn, end_i_cn, p), PRE);
  cn_pop_msg_info();
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i_cn, cn_bits_u8_sub(p_order_cn, convert_to_cn_bits_u8(1UL)));
  update_cn_error_message_info("           let end_i = (pool).range_end / page_size() ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:969:11-80");
  cn_bool* a_15021 = convert_to_cn_bool(true);
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
      if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
        a_15021 = cn_bool_and(a_15021, page_group_ok(i, V, pool));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_assert(a_15021, PRE);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("           take V = each (u64 i; start_i <= i && i < end_i) { Owned(array_shift<struct hyp_page>(hypvmemmap, i)) } ;\n         ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:970:10-33");
    cn_assert(cn_bits_u64_le(buddy_i_cn, max_pfn()), POST);
    cn_pop_msg_info();
    struct hyp_page_cn* p_new_page_cn;
    struct hyp_page_cn* a_15048 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
    a_15048->refcount = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->refcount;
    a_15048->order = cn_bits_u8_sub(p_order_cn, convert_to_cn_bits_u8(1UL));
    a_15048->flags = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(p_i_cn)))->flags;
    p_new_page_cn = a_15048;
    struct hyp_page_cn* buddy_new_page_cn;
    struct hyp_page_cn* a_15062 = (struct hyp_page_cn*) cn_bump_malloc(sizeof(struct hyp_page_cn));
    a_15062->refcount = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->refcount;
    a_15062->order = cn_bits_u8_sub(p_order_cn, convert_to_cn_bits_u8(1UL));
    a_15062->flags = ((struct hyp_page_cn*) cn_map_get_struct_hyp_page_cn(V, cast_cn_bits_u64_to_cn_integer(buddy_i_cn)))->flags;
    buddy_new_page_cn = a_15062;
    update_cn_error_message_info("          V2 == V ;\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:973:10-121");
    cn_bool* a_15090 = convert_to_cn_bool(true);
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(start_i_cn);
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(start_i_cn), i), cn_bits_u64_lt(i, end_i_cn)))) {
        if (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(start_i_cn, i), cn_bits_u64_lt(i, end_i_cn)))) {
          cn_map* a_15079 = cn_map_deep_copy(V);
          cn_map* a_15086 = cn_map_deep_copy(cn_map_set(a_15079, cast_cn_bits_u64_to_cn_integer(p_i_cn), p_new_page_cn));
          a_15090 = cn_bool_and(a_15090, page_group_ok(i, cn_map_set(a_15086, cast_cn_bits_u64_to_cn_integer(buddy_i_cn), buddy_new_page_cn), pool));
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_assert(a_15090, POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void lemma4(cn_bits_u64* p_i, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("          (page_size_of_order(order - 1u8)) * 2u64 == (page_size_of_order(order)) ;\n           ^~~~~~~~~~~~~~ ./driver.pp.c:938:12-26");
  cn_assert(cn_bits_u8_le(convert_to_cn_bits_u8(1UL), order), PRE);
  cn_pop_msg_info();
  cn_bits_u64* p_phys_cn;
  p_phys_cn = cn_bits_u64_multiply(p_i, page_size());
  update_cn_error_message_info("          (order_align(buddy_i, order)) == p_i;\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:940:12-39");
  cn_assert(order_aligned(p_i, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("\n           ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:941:12-30");
  cn_assert(cn_bits_u64_le(p_i, max_pfn()), PRE);
  cn_pop_msg_info();
  {
    cn_bits_u64* buddy_i_cn;
    buddy_i_cn = pfn_buddy(p_i, cn_bits_u8_sub(order, convert_to_cn_bits_u8(1UL)));
    update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:943:11-34");
    cn_assert(cn_bits_u64_le(buddy_i_cn, max_pfn()), POST);
    cn_pop_msg_info();
    cn_bits_u64* buddy_phys_cn;
    buddy_phys_cn = cn_bits_u64_multiply(buddy_i_cn, page_size());
    update_cn_error_message_info("lemma order_align_inv_loop (pointer __hypvmemmap,\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:945:11-45");
    cn_assert(cn_bool_not(order_aligned(buddy_i_cn, order)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("                            map<u64, struct hyp_page> V,\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:946:11-69");
    cn_assert(cn_bits_u64_equality(buddy_phys_cn, cn_bits_u64_add(p_phys_cn, page_size_of_order(cn_bits_u8_sub(order, convert_to_cn_bits_u8(1UL))))), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("                            struct hyp_pool pool,\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:947:11-47");
    cn_assert(cn_bits_u64_lt(convert_to_cn_bits_u64(0ULL), page_size_of_order(order)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("                            pointer p) // struct hyp_page* \n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:948:11-53");
    cn_assert(cn_bits_u64_lt(convert_to_cn_bits_u64(0ULL), page_size_of_order(cn_bits_u8_sub(order, convert_to_cn_bits_u8(1UL)))), POST);
    cn_pop_msg_info();
    update_cn_error_message_info(" requires let hypvmemmap = __hypvmemmap ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:949:11-84");
    cn_assert(cn_bits_u64_equality(cn_bits_u64_multiply(page_size_of_order(cn_bits_u8_sub(order, convert_to_cn_bits_u8(1UL))), convert_to_cn_bits_u64(2ULL)), page_size_of_order(order)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("          let p_i = ((u64) p - (u64) __hypvmemmap) / 4u64 ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:950:11-77");
    cn_assert(cn_bits_u64_le(page_size_of_order(cn_bits_u8_sub(order, convert_to_cn_bits_u8(1UL))), page_size_of_order(order)), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("          let start_i = (pool).range_start / page_size() ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:951:11-48");
    cn_assert(cn_bits_u64_equality(order_align(buddy_i_cn, order), p_i), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void page_size_of_order_inc(cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  {
    update_cn_error_message_info("          let buddy_phys = buddy_i * page_size() ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:933:11-79");
    cn_assert(cn_bits_u64_equality(page_size_of_order(cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL))), cn_bits_u64_multiply(convert_to_cn_bits_u64(2ULL), page_size_of_order(order))), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void extract_l(cn_bits_u64* p_i, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_bits_u64* p_phys_cn;
  p_phys_cn = cn_bits_u64_multiply(p_i, page_size());
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i, order);
  cn_bits_u64* buddy_phys_cn;
  buddy_phys_cn = cn_bits_u64_multiply(buddy_i_cn, page_size());
  update_cn_error_message_info("\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:924:11-44");
  cn_assert(order_aligned(p_i, cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL))), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("lemma lemma4 (u64 p_i, // intptr_t\n          ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:925:11-29");
  cn_assert(cn_bits_u64_le(p_i, max_pfn()), PRE);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("              u8 order) // unsigned int\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:926:10-62");
    cn_assert(cn_bits_u64_equality(cn_bits_u64_add(p_phys_cn, page_size_of_order(order)), buddy_phys_cn), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("  requires order >= 1u8 ;\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:927:10-39");
    cn_assert(page_aligned(p_phys_cn, order), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("           let p_phys = p_i * page_size() ;\n         ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:928:10-42");
    cn_assert(page_aligned(buddy_phys_cn, order), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void lemma2(cn_bits_u64* p_i, cn_bits_u8* order)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  cn_bits_u64* p_phys_cn;
  p_phys_cn = cn_bits_u64_multiply(p_i, page_size());
  cn_bits_u64* buddy_i_cn;
  buddy_i_cn = pfn_buddy(p_i, order);
  cn_bits_u64* buddy_phys_cn;
  buddy_phys_cn = cn_bits_u64_multiply(buddy_i_cn, page_size());
  update_cn_error_message_info("lemma extract_l (u64 p_i, // intptr_t\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:908:12-38");
  cn_assert(order_aligned(p_i, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                 u8 order) // unsigned int\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:909:12-42");
  cn_assert(order_aligned(buddy_i_cn, order), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info(" requires let p_phys = p_i * page_size() ;\n           ^~~~~~~~~~~~~~~~~~ ./driver.pp.c:910:12-30");
  cn_assert(cn_bits_u64_le(p_i, max_pfn()), PRE);
  cn_pop_msg_info();
  {
    cn_bits_u64* min_i_cn;
    cn_bits_u64* a_14780;
    if (convert_from_cn_bool(cn_bits_u64_lt(p_i, buddy_i_cn))) {
      a_14780 = p_i;
    }
    else {
      a_14780 = buddy_i_cn;
    }
    min_i_cn = a_14780;
    cn_bits_u64* min_i_phys_cn;
    min_i_phys_cn = cn_bits_u64_multiply(min_i_cn, page_size());
    update_cn_error_message_info("          order_aligned(p_i, order + 1u8) ;\n          ^~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:913:11-33");
    cn_assert(cn_bits_u64_le(buddy_i_cn, max_pfn()), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("          p_i <= max_pfn ();\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:914:11-43");
    cn_assert(order_aligned(min_i_cn, cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL))), POST);
    cn_pop_msg_info();
    update_cn_error_message_info(" ensures p_phys + (page_size_of_order(order)) == buddy_phys ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:915:11-47");
    cn_assert(page_aligned(min_i_phys_cn, cn_bits_u8_add(order, convert_to_cn_bits_u8(1UL))), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("         page_aligned(p_phys, order) ;\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:916:11-120");
    cn_assert(cn_bool_or(cn_bits_u64_equality(cn_bits_u64_add(p_phys_cn, page_size_of_order(order)), buddy_phys_cn), cn_bits_u64_equality(cn_bits_u64_sub(p_phys_cn, page_size_of_order(order)), buddy_phys_cn)), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}
static void order_dec_inv(cn_bits_u64* pool_range_end, cn_bits_u64* pfn, cn_bits_u8* order1, cn_bits_u8* order2)
{
  cn_bump_frame_id cn_frame_id = cn_bump_get_frame_id();
  ghost_stack_depth_incr();
  clear_ghost_array(0);
  ghost_call_site = CLEARED;
  update_cn_error_message_info("           let buddy_i = pfn_buddy(p_i, order);\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:895:12-39");
  cn_assert(order_aligned(pfn, order1), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("           let buddy_phys = buddy_i * page_size();\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:896:12-79");
  cn_assert(cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(pfn, page_size()), page_size_of_order(order1)), pool_range_end), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("           order_aligned(p_i, order);\n           ^~~~~~~~~~~~~~~~~ ./driver.pp.c:897:12-29");
  cn_assert(cn_bits_u8_le(order2, order1), PRE);
  cn_pop_msg_info();
  {
    update_cn_error_message_info("           order_aligned(buddy_i, order);\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:898:11-38");
    cn_assert(order_aligned(pfn, order2), POST);
    cn_pop_msg_info();
    update_cn_error_message_info("           p_i <= max_pfn ();\n          ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ ./driver.pp.c:899:11-80");
    cn_assert(cn_bits_u64_le(cn_bits_u64_add(cn_bits_u64_multiply(pfn, page_size()), page_size_of_order(order2)), pool_range_end), POST);
    cn_pop_msg_info();
    ghost_stack_depth_decr();
    cn_postcondition_leak_check();
  }
  cn_bump_free_after(cn_frame_id);
}

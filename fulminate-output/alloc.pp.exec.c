#include "alloc.pp.cn.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

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
  /* EXECUTABLE CN PRECONDITION */
  unsigned int __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u32* x_cn = convert_to_cn_bits_u32(x);
  cn_bits_u32* y_cn = convert_to_cn_bits_u32(y);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &x, sizeof(unsigned int), get_cn_stack_depth());
  cn_pointer* x_addr_cn = convert_to_cn_pointer((&x));
  c_add_to_ghost_state((uintptr_t) &y, sizeof(unsigned int), get_cn_stack_depth());
  cn_pointer* y_addr_cn = convert_to_cn_pointer((&y));
  
 { __cn_ret = (CN_LOAD((x)) < CN_LOAD((y)) ? CN_LOAD((x)) : CN_LOAD((y))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &x, sizeof(unsigned int));

  c_remove_from_ghost_state((uintptr_t) &y, sizeof(unsigned int));

{
  cn_bits_u32* return_cn = convert_to_cn_bits_u32(__cn_ret);
  update_cn_error_message_info("	ensures return == (x < y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:82:10-36");
  cn_bits_u32* a_9509;
  if (convert_from_cn_bool(cn_bits_u32_lt(x_cn, y_cn))) {
    a_9509 = x_cn;
  }
  else {
    a_9509 = y_cn;
  }
  cn_assert(cn_bits_u32_equality(return_cn, a_9509), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static inline u64 min_u64(u64 x, u64 y)
/*@
	ensures return == (x < y ? x : y);
@*/
{
  /* EXECUTABLE CN PRECONDITION */
  unsigned long long __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* x_cn = convert_to_cn_bits_u64(x);
  cn_bits_u64* y_cn = convert_to_cn_bits_u64(y);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &x, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* x_addr_cn = convert_to_cn_pointer((&x));
  c_add_to_ghost_state((uintptr_t) &y, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* y_addr_cn = convert_to_cn_pointer((&y));
  
 { __cn_ret = (CN_LOAD((x)) < CN_LOAD((y)) ? CN_LOAD((x)) : CN_LOAD((y))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &x, sizeof(unsigned long long));

  c_remove_from_ghost_state((uintptr_t) &y, sizeof(unsigned long long));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("	ensures return == (x < y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:89:10-36");
  cn_bits_u64* a_9538;
  if (convert_from_cn_bool(cn_bits_u64_lt(x_cn, y_cn))) {
    a_9538 = x_cn;
  }
  else {
    a_9538 = y_cn;
  }
  cn_assert(cn_bits_u64_equality(return_cn, a_9538), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static inline u64 max_u64(u64 x, u64 y)
/*@
	ensures return == (x > y ? x : y);
@*/
{
  /* EXECUTABLE CN PRECONDITION */
  unsigned long long __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* x_cn = convert_to_cn_bits_u64(x);
  cn_bits_u64* y_cn = convert_to_cn_bits_u64(y);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &x, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* x_addr_cn = convert_to_cn_pointer((&x));
  c_add_to_ghost_state((uintptr_t) &y, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* y_addr_cn = convert_to_cn_pointer((&y));
  
 { __cn_ret = (CN_LOAD((x)) > CN_LOAD((y)) ? CN_LOAD((x)) : CN_LOAD((y))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &x, sizeof(unsigned long long));

  c_remove_from_ghost_state((uintptr_t) &y, sizeof(unsigned long long));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("	ensures return == (x > y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:96:10-36");
  cn_bits_u64* a_9567;
  if (convert_from_cn_bool(cn_bits_u64_lt(y_cn, x_cn))) {
    a_9567 = x_cn;
  }
  else {
    a_9567 = y_cn;
  }
  cn_assert(cn_bits_u64_equality(return_cn, a_9567), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
;

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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  update_cn_error_message_info("		take H_pre = RW<struct list_head>(head);\n       ^alloc.pp.c:151:8:");
  struct list_head_cn* H_pre_cn = owned_struct_list_head(head_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &head, sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
 { __cn_ret = CN_LOAD((*(const volatile typeof(head->next) *)&(CN_LOAD(head)->next))) == CN_LOAD(head); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &head, sizeof(const struct list_head*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("		take H_post = RW<struct list_head>(head);\n       ^alloc.pp.c:153:8:");
  struct list_head_cn* H_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		return == (ptr_eq(H_post.next, head) ? 1i32 : 0i32);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:154:3-55");
  cn_bits_i32* a_9606;
  if (convert_from_cn_bool(ptr_eq(H_post_cn->next, head_cn))) {
    a_9606 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_9606 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_9606), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* list_cn = convert_to_cn_pointer(list);
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^alloc.pp.c:169:8:");
  struct list_head_cn* L_pre_cn = owned_struct_list_head(list_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &list, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* list_addr_cn = convert_to_cn_pointer((&list));
  
 // HK(patch)
 // WRITE_ONCE(list->next, list);
 // WRITE_ONCE(list->prev, list);
 CN_STORE(CN_LOAD(list)->next, CN_LOAD(list));
 CN_STORE(CN_LOAD(list)->prev, CN_LOAD(list));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &list, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^alloc.pp.c:171:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(L_post.next, list);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:172:3-29");
  cn_assert(ptr_eq(L_post_cn->next, list_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(L_post.prev, list);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:173:3-29");
  cn_assert(ptr_eq(L_post_cn->prev, list_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* list_cn = convert_to_cn_pointer(list);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^alloc.pp.c:228:8:");
  struct list_head_cn* L_pre_cn = owned_struct_list_head(list_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &list, sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* list_addr_cn = convert_to_cn_pointer((&list));
  c_add_to_ghost_state((uintptr_t) &head, sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
 { __cn_ret = CN_LOAD(CN_LOAD(list)->prev) == CN_LOAD(head); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &list, sizeof(const struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &head, sizeof(const struct list_head*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^alloc.pp.c:230:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		L_pre == L_post;\n		^~~~~~~~~~~~~~~~ alloc.pp.c:231:3-19");
  cn_assert(struct_list_head_cn_equality(L_pre_cn, L_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		return == (ptr_eq(L_pre.prev, head) ? 1i32 : 0i32);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:232:3-54");
  cn_bits_i32* a_9679;
  if (convert_from_cn_bool(ptr_eq(L_pre_cn->prev, head_cn))) {
    a_9679 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_9679 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_9679), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* list_cn = convert_to_cn_pointer(list);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^alloc.pp.c:240:8:");
  struct list_head_cn* L_pre_cn = owned_struct_list_head(list_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &list, sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* list_addr_cn = convert_to_cn_pointer((&list));
  c_add_to_ghost_state((uintptr_t) &head, sizeof(const struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
 { __cn_ret = CN_LOAD(CN_LOAD(list)->next) == CN_LOAD(head); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &list, sizeof(const struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &head, sizeof(const struct list_head*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^alloc.pp.c:242:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		L_pre == L_post;\n		^~~~~~~~~~~~~~~~ alloc.pp.c:243:3-19");
  cn_assert(struct_list_head_cn_equality(L_pre_cn, L_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("	return == (ptr_eq(L_pre.next, head) ? 1i32 : 0i32);\n	^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:244:2-53");
  cn_bits_i32* a_9730;
  if (convert_from_cn_bool(ptr_eq(L_pre_cn->next, head_cn))) {
    a_9730 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_9730 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_9730), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* new_cn = convert_to_cn_pointer(new);
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* next_cn = convert_to_cn_pointer(next);
  cn_pointer* head_cn;
  head_cn = prev_cn;
  update_cn_error_message_info("		take New_pre = RW<struct list_head>(new);\n       ^alloc.pp.c:264:8:");
  struct list_head_cn* New_pre_cn = owned_struct_list_head(new_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_pre = RW<struct list_head>(head);\n       ^alloc.pp.c:265:8:");
  struct list_head_cn* Head_pre_cn = owned_struct_list_head(head_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		!ptr_eq(new, next);\n		^~~~~~~~~~~~~~~~~~~ alloc.pp.c:266:3-22");
  cn_assert(cn_bool_not(ptr_eq(new_cn, next_cn)), PRE);
  cn_pop_msg_info();
  cn_bool* p_cn;
  p_cn = cn_bool_not(ptr_eq(head_cn, next_cn));
  update_cn_error_message_info("		take Next_pre_opt = CondListHead(next, p);\n       ^alloc.pp.c:268:8:");
  struct list_head_option* Next_pre_opt_cn = CondListHead(next_cn, p_cn, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &new, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((uintptr_t) &next, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
 update_cn_error_message_info(" /*@ split_case(!ptr_eq(head, next)); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:283:5-40");

cn_pop_msg_info();

 CN_STORE(CN_LOAD(next)->prev, CN_LOAD(new));
 CN_STORE(CN_LOAD(new)->next, CN_LOAD(next));
 CN_STORE(CN_LOAD(new)->prev, CN_LOAD(prev));
 // HK: removed WRITE_ONCE
 // WRITE_ONCE(prev->next, new);
 CN_STORE(CN_LOAD(prev)->next, CN_LOAD(new));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &new, sizeof(struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take New_post = RW<struct list_head>(new);\n       ^alloc.pp.c:270:8:");
  struct list_head_cn* New_post_cn = owned_struct_list_head(new_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_post = RW<struct list_head>(head);\n       ^alloc.pp.c:271:8:");
  struct list_head_cn* Head_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));\n       ^alloc.pp.c:272:8:");
  struct list_head_option* Next_post_opt_cn = CondListHead(next_cn, cn_bool_not(ptr_eq(head_cn, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		match Next_post_opt {\n		^~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:273:3-280:5");
  cn_bool* a_9815;
  switch (Next_post_opt_cn->tag)
  {
    case LIST_HEAD_NONE:
    {
      struct list_head_none* list_head_none_1 = Next_post_opt_cn->u.list_head_none;
      a_9815 = list_add_aux(Head_post_cn, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
    case LIST_HEAD_SOME:
    {
      struct list_head_some* list_head_some_1 = Next_post_opt_cn->u.list_head_some;
      struct list_head_cn* Next_post = list_head_some_1->L;
      a_9815 = list_add_aux(Next_post, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
  }
  cn_assert(a_9815, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}

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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* new_cn = convert_to_cn_pointer(new);
  cn_pointer* head_cn = convert_to_cn_pointer(head);
  update_cn_error_message_info("		take New_pre = RW<struct list_head>(new);\n       ^alloc.pp.c:307:8:");
  struct list_head_cn* New_pre_cn = owned_struct_list_head(new_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_pre = RW<struct list_head>(head);\n       ^alloc.pp.c:308:8:");
  struct list_head_cn* Head_pre_cn = owned_struct_list_head(head_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Head_pre_cn->next;
  update_cn_error_message_info("		!ptr_eq(new, next);\n		^~~~~~~~~~~~~~~~~~~ alloc.pp.c:310:3-22");
  cn_assert(cn_bool_not(ptr_eq(new_cn, next_cn)), PRE);
  cn_pop_msg_info();
  cn_bool* p_cn;
  p_cn = cn_bool_not(ptr_eq(head_cn, next_cn));
  update_cn_error_message_info("		take Next_pre_opt = CondListHead(next, p);\n       ^alloc.pp.c:312:8:");
  struct list_head_option* Next_pre_opt_cn = CondListHead(next_cn, p_cn, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &new, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((uintptr_t) &head, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* head_addr_cn = convert_to_cn_pointer((&head));
  
 __list_add(CN_LOAD(new), CN_LOAD(head), CN_LOAD(CN_LOAD(head)->next));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &new, sizeof(struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &head, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take New_post = RW<struct list_head>(new);\n       ^alloc.pp.c:314:8:");
  struct list_head_cn* New_post_cn = owned_struct_list_head(new_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_post = RW<struct list_head>(head);\n       ^alloc.pp.c:315:8:");
  struct list_head_cn* Head_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));\n       ^alloc.pp.c:316:8:");
  struct list_head_option* Next_post_opt_cn = CondListHead(next_cn, cn_bool_not(ptr_eq(head_cn, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		match Next_post_opt {\n		^~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:317:3-324:5");
  cn_bool* a_9889;
  switch (Next_post_opt_cn->tag)
  {
    case LIST_HEAD_NONE:
    {
      struct list_head_none* list_head_none_1 = Next_post_opt_cn->u.list_head_none;
      a_9889 = list_add_aux(Head_post_cn, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
    case LIST_HEAD_SOME:
    {
      struct list_head_some* list_head_some_1 = Next_post_opt_cn->u.list_head_some;
      struct list_head_cn* Next_post = list_head_some_1->L;
      a_9889 = list_add_aux(Next_post, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
  }
  cn_assert(a_9889, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* next_cn = convert_to_cn_pointer(next);
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^alloc.pp.c:339:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^alloc.pp.c:340:8:");
  struct list_head_cn* Prev_pre_cn = owned_struct_list_head(prev_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((uintptr_t) &next, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
 CN_STORE(CN_LOAD(next)->prev, CN_LOAD(prev));
 // TODO: Recover WRITE_ONCE
 //WRITE_ONCE(prev->next, next);
 CN_STORE(CN_LOAD(prev)->next, CN_LOAD(next));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct list_head*));

  c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^alloc.pp.c:342:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^alloc.pp.c:343:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:344:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:345:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:346:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:347:3-41");
  cn_assert(ptr_eq(Next_post_cn->next, Next_pre_cn->next), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* entry_cn = convert_to_cn_pointer(entry);
  update_cn_error_message_info("		take Entry_pre = RW<struct list_head>(entry);\n       ^alloc.pp.c:358:8:");
  struct list_head_cn* Entry_pre_cn = owned_struct_list_head(entry_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Entry_pre_cn->next;
  cn_pointer* prev_cn;
  prev_cn = Entry_pre_cn->prev;
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^alloc.pp.c:361:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^alloc.pp.c:362:8:");
  struct list_head_cn* Prev_pre_cn = owned_struct_list_head(prev_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &entry, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* entry_addr_cn = convert_to_cn_pointer((&entry));
  
 __list_del(CN_LOAD(CN_LOAD(entry)->prev), CN_LOAD(CN_LOAD(entry)->next));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &entry, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take Entry_post = RW<struct list_head>(entry);\n       ^alloc.pp.c:364:8:");
  struct list_head_cn* Entry_post_cn = owned_struct_list_head(entry_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^alloc.pp.c:365:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^alloc.pp.c:366:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:367:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:368:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:369:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:370:3-41");
  cn_assert(ptr_eq(Next_post_cn->next, Next_pre_cn->next), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* entry_cn = convert_to_cn_pointer(entry);
  update_cn_error_message_info("		take Entry_pre = RW<struct list_head>(entry);\n       ^alloc.pp.c:379:8:");
  struct list_head_cn* Entry_pre_cn = owned_struct_list_head(entry_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Entry_pre_cn->next;
  cn_pointer* prev_cn;
  prev_cn = Entry_pre_cn->prev;
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^alloc.pp.c:382:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^alloc.pp.c:383:8:");
  struct list_head_cn* Prev_pre_cn = owned_struct_list_head(prev_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &entry, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* entry_addr_cn = convert_to_cn_pointer((&entry));
  
 __list_del_entry(CN_LOAD(entry));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &entry, sizeof(struct list_head*));

{
  update_cn_error_message_info("		take Entry_post = RW<struct list_head>(entry);\n       ^alloc.pp.c:385:8:");
  struct list_head_cn* Entry_post_cn = owned_struct_list_head(entry_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^alloc.pp.c:386:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^alloc.pp.c:387:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:388:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:389:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:390:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:391:3-41");
  cn_assert(ptr_eq(Next_post_cn->next, Next_pre_cn->next), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  unsigned long __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* addr_cn = convert_to_cn_bits_u64(addr);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
 { __cn_ret = (((CN_LOAD((addr)) - (((1UL << 12)) - 1)) + ((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(unsigned long long));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
// /*@ function (u64) PAGE_ALIGN(u64 addr) @*/
// static unsigned long c_PAGE_ALIGN(unsigned long long addr) /*@  cn_function PAGE_ALIGN; @*/
// {
// 	return PAGE_ALIGN(addr);
// }

/*
 * KVM MEMCACHE ***************************************************************
 */
;
static inline void push_hyp_memcache(struct kvm_hyp_memcache *mc,
         phys_addr_t *p,
         phys_addr_t (*to_pa)(void *virt),
         unsigned long order)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* mc_cn = convert_to_cn_pointer(mc);
  cn_pointer* p_cn = convert_to_cn_pointer(p);
  cn_pointer* to_pa_cn = convert_to_cn_pointer(to_pa);
  cn_bits_u64* order_cn = convert_to_cn_bits_u64(order);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));
  c_add_to_ghost_state((uintptr_t) &p, sizeof(unsigned long long*), get_cn_stack_depth());
  cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));
  c_add_to_ghost_state((uintptr_t) &to_pa, sizeof(unsigned long long (*) (void*)), get_cn_stack_depth());
  cn_pointer* to_pa_addr_cn = convert_to_cn_pointer((&to_pa));
  c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
 CN_STORE(*CN_LOAD(p), CN_LOAD(CN_LOAD(mc)->head));
 CN_STORE(CN_LOAD(mc)->head, (CN_LOAD(to_pa)(CN_LOAD(p)) & (~((1UL << 12)-1))) |
     (((typeof(~(~((1UL << 12)-1))))CN_LOAD((order)) << (__builtin_ffsll(~(~((1UL << 12)-1))) - 1)) & (~(~((1UL << 12)-1)))));
 CN_POSTFIX(CN_LOAD(mc)->nr_pages, ++);

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));

  c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));

  c_remove_from_ghost_state((uintptr_t) &to_pa, sizeof(unsigned long long (*) (void*)));

  c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));

{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
static inline void *pop_hyp_memcache(struct kvm_hyp_memcache *mc,
         void *(*to_va)(phys_addr_t phys),
         unsigned long *order)
{
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* mc_cn = convert_to_cn_pointer(mc);
  cn_pointer* to_va_cn = convert_to_cn_pointer(to_va);
  cn_pointer* order_cn = convert_to_cn_pointer(order);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));
  c_add_to_ghost_state((uintptr_t) &to_va, sizeof(void* (*) (unsigned long long)), get_cn_stack_depth());
  cn_pointer* to_va_addr_cn = convert_to_cn_pointer((&to_va));
  c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long*), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
 phys_addr_t *p = CN_LOAD(to_va)(CN_LOAD(CN_LOAD(mc)->head) & (~((1UL << 12)-1)));
c_add_to_ghost_state((uintptr_t) &p, sizeof(unsigned long long*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

 if (!CN_LOAD(CN_LOAD(mc)->nr_pages)) {
  { __cn_ret = NULL; 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
goto __cn_epilogue; }
 }
 CN_STORE(*CN_LOAD(order), ((typeof(~(~((1UL << 12)-1))))((CN_LOAD((CN_LOAD(mc)->head)) & (~(~((1UL << 12)-1)))) >> (__builtin_ffsll(~(~((1UL << 12)-1))) - 1))));
 CN_STORE(CN_LOAD(mc)->head, CN_LOAD(*CN_LOAD(p)));
 CN_POSTFIX(CN_LOAD(mc)->nr_pages, --);
 { __cn_ret = CN_LOAD(p); 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));

  c_remove_from_ghost_state((uintptr_t) &to_va, sizeof(void* (*) (unsigned long long)));

  c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static inline int __topup_hyp_memcache(struct kvm_hyp_memcache *mc,
           unsigned long min_pages,
           void *(*alloc_fn)(void *arg, unsigned long order),
           phys_addr_t (*to_pa)(void *virt),
           void *arg,
           unsigned long order)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* mc_cn = convert_to_cn_pointer(mc);
  cn_bits_u64* min_pages_cn = convert_to_cn_bits_u64(min_pages);
  cn_pointer* alloc_fn_cn = convert_to_cn_pointer(alloc_fn);
  cn_pointer* to_pa_cn = convert_to_cn_pointer(to_pa);
  cn_pointer* arg_cn = convert_to_cn_pointer(arg);
  cn_bits_u64* order_cn = convert_to_cn_bits_u64(order);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));
  c_add_to_ghost_state((uintptr_t) &min_pages, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* min_pages_addr_cn = convert_to_cn_pointer((&min_pages));
  c_add_to_ghost_state((uintptr_t) &alloc_fn, sizeof(void* (*) (void*, unsigned long)), get_cn_stack_depth());
  cn_pointer* alloc_fn_addr_cn = convert_to_cn_pointer((&alloc_fn));
  c_add_to_ghost_state((uintptr_t) &to_pa, sizeof(unsigned long long (*) (void*)), get_cn_stack_depth());
  cn_pointer* to_pa_addr_cn = convert_to_cn_pointer((&to_pa));
  c_add_to_ghost_state((uintptr_t) &arg, sizeof(void*), get_cn_stack_depth());
  cn_pointer* arg_addr_cn = convert_to_cn_pointer((&arg));
  c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));
  
 while (CN_LOAD(CN_LOAD(mc)->nr_pages) < CN_LOAD(min_pages)) {
  phys_addr_t *p = CN_LOAD(alloc_fn)(CN_LOAD(arg), CN_LOAD(order));
c_add_to_ghost_state((uintptr_t) &p, sizeof(unsigned long long*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

  if (!CN_LOAD(p)) {
   { __cn_ret = -12; 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
goto __cn_epilogue; }
  }
  push_hyp_memcache(CN_LOAD(mc), CN_LOAD(p), CN_LOAD(to_pa), CN_LOAD(order));
 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
}
 { __cn_ret = 0; goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));

  c_remove_from_ghost_state((uintptr_t) &min_pages, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &alloc_fn, sizeof(void* (*) (void*, unsigned long)));

  c_remove_from_ghost_state((uintptr_t) &to_pa, sizeof(unsigned long long (*) (void*)));

  c_remove_from_ghost_state((uintptr_t) &arg, sizeof(void*));

  c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  unsigned long __cn_ret;
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
        { __cn_ret = 8UL; goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}

static int hyp_allocator_errno;
static struct kvm_hyp_memcache hyp_allocator_mc;
static u8 hyp_allocator_missing_donations;
static  hyp_allocator;
;
// HK: having char data at the end of the struct is very annoying
// If we write RW<struct chunk_hdr>, a single byte of the data is going to be owned
// unintentionally.
// TODO: rewrite the spec to use chunk_hdr_only instead of chunk_hdr
;
// Auxiliary functions for chunk_hdr

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
  /* EXECUTABLE CN PRECONDITION */
  unsigned int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  update_cn_error_message_info("        take C_pre = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:605:14:");
  struct chunk_hdr_cn* C_pre_cn = owned_struct_chunk_hdr(chunk_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  
        size_t len = offsetof(struct chunk_hdr, hash);
c_add_to_ghost_state((uintptr_t) &len, sizeof(size_t), get_cn_stack_depth());


cn_pointer* len_addr_cn = convert_to_cn_pointer((&len));

        // HK: How do I handle this cast while having the ownership to chunk??
        u64 *data = (u64 *)CN_LOAD(chunk);
c_add_to_ghost_state((uintptr_t) &data, sizeof(unsigned long long*), get_cn_stack_depth());


cn_pointer* data_addr_cn = convert_to_cn_pointer((&data));

        u32 hash = 0;
c_add_to_ghost_state((uintptr_t) &hash, sizeof(unsigned int), get_cn_stack_depth());


cn_pointer* hash_addr_cn = convert_to_cn_pointer((&hash));

                                                                                ;
    {
cn_bits_u64* O_len0;

cn_pointer* O_data0;

cn_bits_u32* O_hash0;

cn_pointer* O_chunk6;

cn_bits_u64* L;

struct chunk_hdr_cn* C;
while (({
  ghost_stack_depth_incr();
  update_cn_error_message_info("    while (len >= sizeof(u64))\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:622:5-637:6");
  O_len0 = owned_size_t(len_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    while (len >= sizeof(u64))\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:622:5-637:6");
  O_data0 = owned_unsigned_long_long_pointer(data_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    while (len >= sizeof(u64))\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:622:5-637:6");
  O_hash0 = owned_unsigned_int(hash_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("    while (len >= sizeof(u64))\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:622:5-637:6");
  O_chunk6 = owned_struct_chunk_hdr_pointer(chunk_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  L = cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(offsetof(struct chunk_hdr, hash)));
  update_cn_error_message_info("        take C = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:626:14:");
  C = owned_struct_chunk_hdr(O_chunk6, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        len <= L;\n        ^~~~~~~~~ alloc.pp.c:627:9-18");
  cn_assert(cn_bits_u64_le(O_len0, L), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        (u64)data + len == (u64)chunk + L;\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:628:9-43");
  cn_assert(cn_bits_u64_equality(cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(O_data0), O_len0), cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(O_chunk6), L)), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        {chunk} unchanged;\n        ^~~~~~~~~~~~~~~~~~ alloc.pp.c:629:9-27");
  cn_assert(cn_pointer_equality(O_chunk6, chunk_cn), LOOP);
  cn_pop_msg_info();
  cn_loop_put_back_ownership();
  ghost_stack_depth_decr();
  0;
})
, CN_LOAD(len) >= sizeof(u64))
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
        CN_STORE_OP(hash,^,hash_64(CN_LOAD(*CN_LOAD(data)), 32));
        CN_STORE_OP(len,-,sizeof(u64));
        CN_POSTFIX(data, ++);
    }}
        if (CN_LOAD(len)) {
                CN_STORE_OP(hash,^,hash_32(CN_LOAD(*(u32 *)CN_LOAD(data)), 32));
        }
        { __cn_ret = CN_LOAD(hash); 
c_remove_from_ghost_state((uintptr_t) &len, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &data, sizeof(unsigned long long*));


c_remove_from_ghost_state((uintptr_t) &hash, sizeof(unsigned int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &len, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &data, sizeof(unsigned long long*));


c_remove_from_ghost_state((uintptr_t) &hash, sizeof(unsigned int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

{
  cn_bits_u32* return_cn = convert_to_cn_bits_u32(__cn_ret);
  update_cn_error_message_info("        take C_post = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:610:14:");
  struct chunk_hdr_cn* C_post_cn = owned_struct_chunk_hdr(chunk_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_pre == C_post;\n        ^~~~~~~~~~~~~~~~ alloc.pp.c:614:9-25");
  cn_assert(struct_chunk_hdr_cn_equality(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  update_cn_error_message_info("        take C_pre = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:646:14:");
  struct chunk_hdr_cn* C_pre_cn = owned_struct_chunk_hdr(chunk_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  
        if (CN_LOAD(chunk)) {
                CN_STORE(CN_LOAD(chunk)->hash, chunk_hash_compute(CN_LOAD(chunk)));
        }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

{
  update_cn_error_message_info("        take C_post = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:648:14:");
  struct chunk_hdr_cn* C_post_cn = owned_struct_chunk_hdr(chunk_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        hash_change_only(C_pre, C_post);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:649:9-41");
  cn_assert(hash_change_only(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  update_cn_error_message_info("        take C_pre = MaybeChunkHdr(chunk, !is_null(chunk));\n             ^alloc.pp.c:659:14:");
  struct chunk_hdr_option* C_pre_cn = MaybeChunkHdr(chunk_cn, cn_bool_not(is_null(chunk_cn)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  
        if (CN_LOAD(chunk)) {
                (!!(CN_LOAD(CN_LOAD(chunk)->hash) != chunk_hash_compute(CN_LOAD(chunk))));
        }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

{
  update_cn_error_message_info("        take C_post = MaybeChunkHdr(chunk, !is_null(chunk));\n             ^alloc.pp.c:661:14:");
  struct chunk_hdr_option* C_post_cn = MaybeChunkHdr(chunk_cn, cn_bool_not(is_null(chunk_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_post == C_pre;\n        ^~~~~~~~~~~~~~~~ alloc.pp.c:662:9-25");
  cn_assert(struct_chunk_hdr_option_equality(C_post_cn, C_pre_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
// HK: eliminate the cast to unsigned long
// #define chunk_hdr_size() //         offsetof(struct chunk_hdr, data)
// HK: replace unsigned long with size_t
//#define chunk_size(size)         //(chunk_hdr_size() + max_u64((size_t)(size), MIN_ALLOC))

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

/*PS: if we're abstracting the chunks to a CN custom list as above, then we'll abstract a `struct chunk_hdr *chunk` to a natural-number index into that list and define an `nth`?  Or add the actual address to the abstraction and search for that to access?  Think we need that address in any case, though that doesn't decide this. */


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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:989:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:990:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:994:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:995:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        { __cn_ret = list_is_last(&CN_LOAD((chunk))->node, &CN_LOAD((allocator))->chunks) ?
                NULL : ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.next)) + (0UL - offsetof(typeof(*(chunk)), node)))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:997:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:998:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:999:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1000:17-118");
  cn_assert(cn_bool_implies(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks)), is_null(return_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1001:17-131");
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks))), ptr_eq(return_cn, next_chunk_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_post == A_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1002:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_post_cn, A_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_post == B_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1003:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_post_cn, B_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post == C_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1004:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_post_cn, C_pre_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1014:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1015:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* prev_node_cn;
  prev_node_cn = Node_cn->prev;
  cn_pointer* prev_chunk_cn;
  prev_chunk_cn = my_container_of_chunk_hdr(prev_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(prev_chunk, A_pre);\n                     ^alloc.pp.c:1019:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(prev_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.next, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1020:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->next, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        { __cn_ret = list_is_first(&CN_LOAD((chunk))->node, &CN_LOAD((allocator))->chunks) ?
                NULL : ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.prev)) + (0UL - offsetof(typeof(*(chunk)), node)))); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1022:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1023:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(prev_chunk, A_post);\n                     ^alloc.pp.c:1024:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(prev_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1025:17-119");
  cn_assert(cn_bool_implies(Cn_list_is_first(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks)), is_null(return_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, prev_chunk);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1026:17-132");
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_first(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks))), ptr_eq(return_cn, prev_chunk_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_post == A_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1027:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_post_cn, A_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_post == B_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1028:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_post_cn, B_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post == C_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1029:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_post_cn, C_pre_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1039:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1040:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:1044:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1045:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *next = __chunk_next(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));

        chunk_hash_validate(CN_LOAD(next));
        { __cn_ret = CN_LOAD(next); 
c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1047:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1048:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:1049:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1050:17-118");
  cn_assert(cn_bool_implies(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks)), is_null(return_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1051:17-131");
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks))), ptr_eq(return_cn, next_chunk_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_post == A_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1052:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_post_cn, A_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_post == B_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1053:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_post_cn, B_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post == C_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1054:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_post_cn, C_pre_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1065:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1066:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* prev_node_cn;
  prev_node_cn = Node_cn->prev;
  cn_pointer* prev_chunk_cn;
  prev_chunk_cn = my_container_of_chunk_hdr(prev_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(prev_chunk, A_pre);\n                     ^alloc.pp.c:1070:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(prev_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.next, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1071:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->next, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *prev = __chunk_prev(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));

        chunk_hash_validate(CN_LOAD(prev));
        { __cn_ret = CN_LOAD(prev); 
c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1073:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1074:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(prev_chunk, A_post);\n                     ^alloc.pp.c:1075:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(prev_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1076:17-119");
  cn_assert(cn_bool_implies(Cn_list_is_first(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks)), is_null(return_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, prev_chunk);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1077:17-132");
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_first(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks))), ptr_eq(return_cn, prev_chunk_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_post == A_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1078:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_post_cn, A_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_post == B_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1079:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_post_cn, B_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post == C_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1080:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_post_cn, C_pre_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  update_cn_error_message_info("                take C_pre = RW<struct chunk_hdr>(addr);\n                     ^alloc.pp.c:1090:22:");
  struct chunk_hdr_cn* C_pre_cn = owned_struct_chunk_hdr(addr_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
        struct chunk_hdr *chunk = (struct chunk_hdr *)CN_LOAD(addr);
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));

        chunk_hash_validate(CN_LOAD(chunk));
        { __cn_ret = CN_LOAD(chunk); 
c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(void*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take C_post = RW<struct chunk_hdr>(addr);\n                     ^alloc.pp.c:1092:22:");
  struct chunk_hdr_cn* C_post_cn = owned_struct_chunk_hdr(addr_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_pre == C_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1093:17-33");
  cn_assert(struct_chunk_hdr_cn_equality(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(return, addr);\n                ^~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1094:17-38");
  cn_assert(ptr_eq(return_cn, addr_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}

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
  /* EXECUTABLE CN PRECONDITION */
  unsigned long __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1113:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1114:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct a_9481_record* Hdr_cn;
  Hdr_cn = B_pre_cn->Hdr;
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:1119:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1120:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *next = chunk_get_next(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));

        unsigned long allocator_end = CN_LOAD(CN_LOAD((allocator))->start) +
                                      CN_LOAD(CN_LOAD((allocator))->size);
c_add_to_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* allocator_end_addr_cn = convert_to_cn_pointer((&allocator_end));

        { __cn_ret = CN_LOAD(next) ? (unsigned long)CN_LOAD(next) - ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)) :
                CN_LOAD(allocator_end) - ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)); 
c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1122:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1123:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:1124:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_pre == A_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1125:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_pre_cn, A_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_pre == B_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1126:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_pre_cn, B_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_pre == C_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1127:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                return == (u64)Cn_chunk_unmapped_size(Hdr);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1128:17-60");
  cn_assert(cn_bits_u64_equality(return_cn, cast_cn_bits_u32_to_cn_bits_u64(Cn_chunk_unmapped_size(Hdr_cn))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}


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
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("        take H_pre = Cn_hyp_allocator(allocator);\n             ^alloc.pp.c:1192:14:");
  struct Cn_hyp_allocator_record* H_pre_cn = Cn_hyp_allocator(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        !Is_chunk_some(lookup(chunk, H_pre.hdrs));\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1195:9-51");
  cn_assert(cn_bool_not(Is_chunk_some(lookup(chunk_cn, H_pre_cn->hdrs))), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        take C = Own_chunk_hdr(chunk);\n             ^alloc.pp.c:1196:14:");
  struct chunk_hdr_only_cn* C_cn = Own_chunk_hdr(chunk_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        match (lookup(prev, H_pre.hdrs))\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1199:9-1214:11");
  cn_bool* a_10988;
  switch (lookup(prev_cn, H_pre_cn->hdrs)->tag)
{
  case CHUNK_NONE:
  {
    struct chunk_none* chunk_none_1 = lookup(prev_cn, H_pre_cn->hdrs)->u.chunk_none;
    a_10988 = convert_to_cn_bool(false);
    break;
  }
  case CHUNK_SOME:
  {
    struct chunk_some* chunk_some_1 = lookup(prev_cn, H_pre_cn->hdrs)->u.chunk_some;
    struct a_9481_record* Prev = chunk_some_1->hdr;
    switch (next_chunk(prev_cn, H_pre_cn->hdrs)->tag)
    {
      case CHUNK_NONE:
      {
        struct chunk_none* chunk_none_1 = next_chunk(prev_cn, H_pre_cn->hdrs)->u.chunk_none;
        a_10988 = chunk_list_insert_aux(H_pre_cn->ha, chunk_cn, C_cn, prev_cn, cn_bits_u64_add(H_pre_cn->ha->start, cast_cn_bits_u32_to_cn_bits_u64(H_pre_cn->ha->size)));
        break;
      }
      case CHUNK_SOME:
      {
        struct chunk_some* chunk_some_1 = next_chunk(prev_cn, H_pre_cn->hdrs)->u.chunk_some;
        struct a_9481_record* Next_Chunk = chunk_some_1->hdr;
        a_10988 = chunk_list_insert_aux(H_pre_cn->ha, chunk_cn, C_cn, prev_cn, cast_cn_bits_u64_to_cn_bits_u64(Next_Chunk->header_address));
        break;
      }
    }
    break;
  }
}
  cn_assert(a_10988, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
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
        list_add(&CN_LOAD(chunk)->node, &CN_LOAD(prev)->node);
        // /*@ unfold lookup(prev, H_pre.hdrs); @*/
        chunk_hash_update(CN_LOAD(prev));
        chunk_hash_update(__chunk_next(CN_LOAD(chunk), CN_LOAD(allocator)));
        chunk_hash_update(CN_LOAD(chunk));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  update_cn_error_message_info("        take A_post = Cn_hyp_allocator(allocator);\n             ^alloc.pp.c:1216:14:");
  struct Cn_hyp_allocator_record* A_post_cn = Cn_hyp_allocator(allocator_cn, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
static inline void chunk_list_del(struct chunk_hdr *chunk,
                                  struct hyp_allocator *allocator)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *prev = __chunk_prev(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));

        struct chunk_hdr *next = __chunk_next(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));

        // non-rust ownership type part
        list_del(&CN_LOAD(chunk)->node);
        chunk_hash_update(CN_LOAD(prev));
        chunk_hash_update(CN_LOAD(next));

c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
static void hyp_allocator_unmap(struct hyp_allocator *allocator,
                                unsigned long va, size_t size)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* va_cn = convert_to_cn_bits_u64(va);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &va, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* va_addr_cn = convert_to_cn_pointer((&va));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());


cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));

        int nr_pages = CN_LOAD(size) >> 12;
c_add_to_ghost_state((uintptr_t) &nr_pages, sizeof(signed int), get_cn_stack_depth());


cn_pointer* nr_pages_addr_cn = convert_to_cn_pointer((&nr_pages));

        unsigned long __va = CN_LOAD(va);
c_add_to_ghost_state((uintptr_t) &__va, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* __va_addr_cn = convert_to_cn_pointer((&__va));

        (!!(!((((unsigned long)CN_LOAD((va))) & ((typeof((unsigned long)(va)))((1UL << 12)) - 1)) == 0)));
        (!!(!((((unsigned long)CN_LOAD((size))) & ((typeof((unsigned long)(size)))((1UL << 12)) - 1)) == 0)));
        while (CN_POSTFIX(nr_pages, --)) {
                phys_addr_t pa = __pkvm_private_range_pa((void *)CN_LOAD(__va));
c_add_to_ghost_state((uintptr_t) &pa, sizeof(unsigned long long), get_cn_stack_depth());


cn_pointer* pa_addr_cn = convert_to_cn_pointer((&pa));

                void *page = hyp_phys_to_virt(CN_LOAD(pa));
c_add_to_ghost_state((uintptr_t) &page, sizeof(void*), get_cn_stack_depth());


cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));

                push_hyp_memcache(CN_LOAD(mc), CN_LOAD(page), hyp_virt_to_phys, 0);
                CN_STORE_OP(__va,+,(1UL << 12));
        
c_remove_from_ghost_state((uintptr_t) &pa, sizeof(unsigned long long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(void*));
}
        pkvm_remove_mappings((void *)CN_LOAD(va), (void *)(CN_LOAD(va) + CN_LOAD(size)));

c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &__va, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &va, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* va_cn = convert_to_cn_bits_u64(va);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  update_cn_error_message_info("                true;\n                ^~~~~ alloc.pp.c:1272:17-22");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &va, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* va_addr_cn = convert_to_cn_pointer((&va));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());


cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));

        unsigned long va_end = CN_LOAD(va) + CN_LOAD(size);
c_add_to_ghost_state((uintptr_t) &va_end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* va_end_addr_cn = convert_to_cn_pointer((&va_end));

        int ret, nr_pages = 0;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));


c_add_to_ghost_state((uintptr_t) &nr_pages, sizeof(signed int), get_cn_stack_depth());


cn_pointer* nr_pages_addr_cn = convert_to_cn_pointer((&nr_pages));

        if (!((((unsigned long)CN_LOAD((va))) & ((typeof((unsigned long)(va)))((1UL << 12)) - 1)) == 0) || !((((unsigned long)CN_LOAD((size))) & ((typeof((unsigned long)(size)))((1UL << 12)) - 1)) == 0)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &va_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));
goto __cn_epilogue; }
        }
        if (CN_LOAD(va_end) < CN_LOAD(va) || CN_LOAD(va_end) > (CN_LOAD(CN_LOAD(allocator)->start) + CN_LOAD(CN_LOAD(allocator)->size))) {
                { __cn_ret = -7; 
c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &va_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));
goto __cn_epilogue; }
        }
        if (CN_LOAD(CN_LOAD(mc)->nr_pages) < (CN_LOAD(size) >> 12)) {
                u8 *missing_donations = (&hyp_allocator_missing_donations);
c_add_to_ghost_state((uintptr_t) &missing_donations, sizeof(unsigned char*), get_cn_stack_depth());


cn_pointer* missing_donations_addr_cn = convert_to_cn_pointer((&missing_donations));

                u32 delta = (CN_LOAD(size) >> 12) - CN_LOAD(CN_LOAD(mc)->nr_pages);
c_add_to_ghost_state((uintptr_t) &delta, sizeof(unsigned int), get_cn_stack_depth());


cn_pointer* delta_addr_cn = convert_to_cn_pointer((&delta));

                CN_STORE(*CN_LOAD(missing_donations), min_u32(CN_LOAD(delta), ((u8)~0U)));
                { __cn_ret = -12; 
c_remove_from_ghost_state((uintptr_t) &missing_donations, sizeof(unsigned char*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned int));


c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &va_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));
goto __cn_epilogue; }
        
c_remove_from_ghost_state((uintptr_t) &missing_donations, sizeof(unsigned char*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned int));
}
        while (CN_LOAD(nr_pages) < (CN_LOAD(size) >> 12)) {
                void *page;
c_add_to_ghost_state((uintptr_t) &page, sizeof(void*), get_cn_stack_depth());


cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));

                unsigned long order;
c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));

                CN_STORE(page, pop_hyp_memcache(CN_LOAD(mc), hyp_phys_to_virt, &order));
                /* We only expect 1 page at a time for now. */
                (!!(!CN_LOAD(page) || CN_LOAD(order)));
                CN_STORE(ret, __hyp_allocator_map(CN_LOAD(va), hyp_virt_to_phys(CN_LOAD(page))));
                if (CN_LOAD(ret)) {
                        push_hyp_memcache(CN_LOAD(mc), CN_LOAD(page), hyp_virt_to_phys, 0);
                        
c_remove_from_ghost_state((uintptr_t) &page, sizeof(void*));


c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));
break;
                }
                CN_STORE_OP(va,+,(1UL << 12));
                CN_POSTFIX(nr_pages, ++);
        
c_remove_from_ghost_state((uintptr_t) &page, sizeof(void*));


c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));
}
        if (CN_LOAD(ret) && CN_LOAD(nr_pages)) {
                CN_STORE_OP(va,-,(1UL << 12) * CN_LOAD(nr_pages));
                hyp_allocator_unmap(CN_LOAD(allocator), CN_LOAD(va), CN_LOAD(nr_pages) << 12);
        }
        { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &va_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &va_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &nr_pages, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &va, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("                true;\n                ^~~~~ alloc.pp.c:1274:17-22");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}


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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  cn_pointer* prev_cn = convert_to_cn_pointer(prev);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("        take Pre = ChunkInstallPre(chunk, size, prev, allocator);\n             ^alloc.pp.c:1394:14:");
  struct Cn_hyp_allocator_only_record* Pre_cn = ChunkInstallPre(chunk_cn, size_cn, prev_cn, allocator_cn, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        size_t prev_mapped_size;
c_add_to_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t), get_cn_stack_depth());


cn_pointer* prev_mapped_size_addr_cn = convert_to_cn_pointer((&prev_mapped_size));

        /* First chunk, first allocation */
        if (!CN_LOAD(prev)) {
                INIT_LIST_HEAD(&CN_LOAD(chunk)->node);
                // HK: non-rust ownership type part
                // See the comments in chunk_list_insert
                list_add(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks);
                CN_STORE(CN_LOAD(chunk)->mapped_size, (((((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL)))) + ((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)));
                CN_STORE(CN_LOAD(chunk)->alloc_size, CN_LOAD(size));
                chunk_hash_update(CN_LOAD(chunk));
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t));
goto __cn_epilogue; }
        }
        if (((unsigned long)CN_LOAD((prev)) + CN_LOAD(CN_LOAD(prev)->mapped_size)) < (unsigned long)CN_LOAD(chunk)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t));
goto __cn_epilogue; }
        }
        if ((unsigned long)((void *)(&CN_LOAD((prev))->data)) + CN_LOAD(CN_LOAD(prev)->alloc_size) > (unsigned long)CN_LOAD(chunk)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t));
goto __cn_epilogue; }
        }
        CN_STORE(prev_mapped_size, CN_LOAD(CN_LOAD(prev)->mapped_size));
        CN_STORE(CN_LOAD(prev)->mapped_size, (unsigned long)CN_LOAD(chunk) - (unsigned long)CN_LOAD(prev));
        CN_STORE(CN_LOAD(chunk)->mapped_size, CN_LOAD(prev_mapped_size) - CN_LOAD(CN_LOAD(prev)->mapped_size));
        CN_STORE(CN_LOAD(chunk)->alloc_size, CN_LOAD(size));
        chunk_list_insert(CN_LOAD(chunk), CN_LOAD(prev), CN_LOAD(allocator));
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &prev_mapped_size, sizeof(size_t));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

  c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("        take Post = ChunkInstallPost(chunk, size, prev, allocator, Pre);\n             ^alloc.pp.c:1396:14:");
  cn_bool* Post_cn = ChunkInstallPost(chunk_cn, size_cn, prev_cn, allocator_cn, Pre_cn, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static int chunk_merge(struct chunk_hdr *chunk, struct hyp_allocator *allocator)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        /* The caller already validates prev */
        struct chunk_hdr *prev = __chunk_prev(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));

        if ((!!(!CN_LOAD(prev)))) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }
        }
        /* Can only merge free chunks */
        if ((!!CN_LOAD(CN_LOAD((chunk))->alloc_size)) || (!!CN_LOAD(CN_LOAD((prev))->alloc_size))) {
                { __cn_ret = -16; 
c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }
        }
        /* Can't merge non-contiguous mapped regions */
        if (((unsigned long)CN_LOAD((prev)) + CN_LOAD(CN_LOAD(prev)->mapped_size)) != (unsigned long)CN_LOAD(chunk)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }
        }
        /* mapped region inheritance */
        CN_STORE_OP(CN_LOAD(prev)->mapped_size,+,CN_LOAD(CN_LOAD(chunk)->mapped_size));
        chunk_list_del(CN_LOAD(chunk), CN_LOAD(allocator));
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &prev, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  size_t __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  update_cn_error_message_info("                take C_pre = RW<struct chunk_hdr>(chunk);\n                     ^alloc.pp.c:1447:22:");
  struct chunk_hdr_cn* C_pre_cn = owned_struct_chunk_hdr(chunk_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_bits_u64* mapping_needs_cn;
  mapping_needs_cn = Cn_chunk_size(size_cn);
  cn_bits_u64* mapping_missing_cn;
  mapping_missing_cn = PAGE_ALIGN(cn_bits_u64_sub(mapping_needs_cn, cast_cn_bits_u32_to_cn_bits_u64(C_pre_cn->mapped_size)));
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        // TODO: fix this. Due to the Cerberus elaboration bug, we cannot use
        // size_t here currently.
        // size_t mapping_missing, mapping_needs = chunk_size(size);
        unsigned long mapping_missing, mapping_needs = (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL));
c_add_to_ghost_state((uintptr_t) &mapping_missing, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* mapping_missing_addr_cn = convert_to_cn_pointer((&mapping_missing));


c_add_to_ghost_state((uintptr_t) &mapping_needs, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* mapping_needs_addr_cn = convert_to_cn_pointer((&mapping_needs));

        if (CN_LOAD(mapping_needs) <= CN_LOAD(CN_LOAD(chunk)->mapped_size)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &mapping_missing, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapping_needs, sizeof(unsigned long));
goto __cn_epilogue; }
        }
        CN_STORE(mapping_missing, ((((CN_LOAD(mapping_needs) - CN_LOAD(CN_LOAD(chunk)->mapped_size))) + ((typeof((mapping_needs - chunk->mapped_size)))(((1UL << 12))) - 1)) & ~((typeof((mapping_needs - chunk->mapped_size)))(((1UL << 12))) - 1)));
        { __cn_ret = CN_LOAD(mapping_missing); 
c_remove_from_ghost_state((uintptr_t) &mapping_missing, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapping_needs, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &mapping_missing, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapping_needs, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("                take C_post = RW<struct chunk_hdr>(chunk);\n                     ^alloc.pp.c:1451:22:");
  struct chunk_hdr_cn* C_post_cn = owned_struct_chunk_hdr(chunk_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_pre == C_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1452:17-33");
  cn_assert(struct_chunk_hdr_cn_equality(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  cn_bits_u64* res_cn;
  cn_bits_u64* a_11248;
  if (convert_from_cn_bool(cn_bits_u64_le(mapping_needs_cn, cast_cn_bits_u32_to_cn_bits_u64(C_pre_cn->mapped_size)))) {
    a_11248 = convert_to_cn_bits_u64(0ULL);
  }
  else {
    a_11248 = mapping_missing_cn;
  }
  res_cn = a_11248;
  update_cn_error_message_info("                return == res;\n                ^~~~~~~~~~~~~~ alloc.pp.c:1455:17-31");
  cn_assert(cn_bits_u64_equality(return_cn, res_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *next_chunk = chunk_get_next(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_chunk_addr_cn = convert_to_cn_pointer((&next_chunk));

        unsigned long delta, mapped_end = ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size));
c_add_to_ghost_state((uintptr_t) &delta, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* delta_addr_cn = convert_to_cn_pointer((&delta));


c_add_to_ghost_state((uintptr_t) &mapped_end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* mapped_end_addr_cn = convert_to_cn_pointer((&mapped_end));

        struct chunk_hdr *new_chunk;
c_add_to_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* new_chunk_addr_cn = convert_to_cn_pointer((&new_chunk));

        if (((((unsigned long)CN_LOAD((mapped_end))) & ((typeof((unsigned long)(mapped_end)))((1UL << 12)) - 1)) == 0)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapped_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }
        }
        CN_STORE(new_chunk, (struct chunk_hdr *)(((CN_LOAD((mapped_end)) - (((1UL << 12)) - 1)) + ((typeof((mapped_end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((mapped_end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)));
        if ((unsigned long)CN_LOAD(new_chunk) <= (unsigned long)CN_LOAD(chunk)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapped_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }
        }
        CN_STORE(delta, ((unsigned long)CN_LOAD(next_chunk) - (unsigned long)CN_LOAD(new_chunk)));
        /*
         * This shouldn't happen, chunks are installed to a minimum distance
         * from the page start
         */
        (!!(CN_LOAD(delta) < (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL))));
        (!!(chunk_install(CN_LOAD(new_chunk), 0, CN_LOAD(chunk), CN_LOAD(allocator))));
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapped_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &mapped_end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_bits_u64* map_size_cn = convert_to_cn_bits_u64(map_size);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1537:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1538:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = C_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take Next_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:1542:22:");
  struct Cn_chunk_hdr_record* Next_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(Next_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1543:17-89");
  cn_assert(ptr_eq(Next_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  cn_bool* cond_cn;
  cond_cn = cn_bits_u64_le(map_size_cn, cast_cn_bits_u32_to_cn_bits_u64(Cn_chunk_unmapped_size(C_pre_cn->Hdr)));
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &map_size, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* map_size_addr_cn = convert_to_cn_pointer((&map_size));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        int ret;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        if (chunk_unmapped_size(CN_LOAD(chunk), CN_LOAD(allocator)) < CN_LOAD(map_size)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
        }
        // TODO(HK): this function returns a "new memory ownership", so we have
        // to handle this
        CN_STORE(ret, hyp_allocator_map(CN_LOAD(allocator), ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)),
                                CN_LOAD(map_size)));
        if (CN_LOAD(ret)) {
                { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
        }
        update_cn_error_message_info("        /*@ apply ConcatArray(array_shift<unsigned char>(chunk, Cn_chunk_hdr_size()), (u64)chunk->mapped_size - Cn_chunk_hdr_size(), (u64)map_size); @*/\n           ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1573:12-151");

cn_pop_msg_info();

        CN_STORE_OP(CN_LOAD(chunk)->mapped_size,+,CN_LOAD(map_size));
        chunk_hash_update(CN_LOAD(chunk));
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &map_size, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1546:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1547:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take Next_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:1548:22:");
  struct Cn_chunk_hdr_record* Next_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_post == A_pre;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1549:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_post_cn, A_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Next_post == Next_pre;\n                ^~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1550:17-39");
  cn_assert(struct_Cn_chunk_hdr_record_equality(Next_post_cn, Next_pre_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post.Hdr.alloc_size == C_pre.Hdr.alloc_size;\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1551:17-63");
  cn_assert(cn_bits_u32_equality(C_post_cn->Hdr->alloc_size, C_pre_cn->Hdr->alloc_size), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post.Hdr.va_size == C_pre.Hdr.va_size;\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1552:17-57");
  cn_assert(cn_bits_u32_equality(C_post_cn->Hdr->va_size, C_pre_cn->Hdr->va_size), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_post.Hdr.header_address == C_pre.Hdr.header_address;\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1553:17-71");
  cn_assert(cn_bits_u64_equality(C_post_cn->Hdr->header_address, C_pre_cn->Hdr->header_address), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !cond implies return == -EINVAL();\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1554:17-51");
  cn_assert(cn_bool_implies(cn_bool_not(cond_cn), cn_bits_i32_equality(return_cn, cn_bits_i32_negate(EINVAL()))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                return == 0i32 implies\n                ^~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1555:17-1556:83");
  cn_assert(cn_bool_implies(cn_bits_i32_equality(return_cn, convert_to_cn_bits_i32(0LL)), cn_bits_u32_equality(C_post_cn->Hdr->mapped_size, cn_bits_u32_add(C_pre_cn->Hdr->mapped_size, cast_cn_bits_u64_to_cn_bits_u32(map_size_cn)))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                return != 0i32 implies\n                ^~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1557:17-1558:65");
  cn_assert(cn_bool_implies(cn_bool_not(cn_bits_i32_equality(return_cn, convert_to_cn_bits_i32(0LL))), cn_bits_u32_equality(C_post_cn->Hdr->mapped_size, C_pre_cn->Hdr->mapped_size)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static size_t chunk_dec_map(struct chunk_hdr *chunk,
                            struct hyp_allocator *allocator,
                            size_t reclaim_target)
{
  /* EXECUTABLE CN PRECONDITION */
  size_t __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* reclaim_target_cn = convert_to_cn_bits_u64(reclaim_target);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &reclaim_target, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* reclaim_target_addr_cn = convert_to_cn_pointer((&reclaim_target));
  
        unsigned long start, end;
c_add_to_ghost_state((uintptr_t) &start, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* start_addr_cn = convert_to_cn_pointer((&start));


c_add_to_ghost_state((uintptr_t) &end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* end_addr_cn = convert_to_cn_pointer((&end));

        size_t reclaimable;
c_add_to_ghost_state((uintptr_t) &reclaimable, sizeof(size_t), get_cn_stack_depth());


cn_pointer* reclaimable_addr_cn = convert_to_cn_pointer((&reclaimable));

        CN_STORE(start, (((((unsigned long)CN_LOAD(chunk) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((CN_LOAD(chunk)->alloc_size)), 8UL)))) + ((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)));
        CN_STORE(end, ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)));
        if (CN_LOAD(start) >= CN_LOAD(end)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(size_t));
goto __cn_epilogue; }
        }
        CN_STORE(reclaimable, CN_LOAD(end) - CN_LOAD(start));
        if (CN_LOAD(reclaimable) < (1UL << 12)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(size_t));
goto __cn_epilogue; }
        }
        if (chunk_split_aligned(CN_LOAD(chunk), CN_LOAD(allocator))) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(size_t));
goto __cn_epilogue; }
        }
        CN_STORE(end, ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)));
        CN_STORE(reclaimable, min_u64(CN_LOAD(end) - CN_LOAD(start), CN_LOAD(reclaim_target)));
        CN_STORE(start, CN_LOAD(end) - CN_LOAD(reclaimable));
        hyp_allocator_unmap(CN_LOAD(allocator), CN_LOAD(start), CN_LOAD(reclaimable));
        CN_STORE_OP(CN_LOAD(chunk)->mapped_size,-,CN_LOAD(reclaimable));
        chunk_hash_update(CN_LOAD(chunk));
        { __cn_ret = CN_LOAD(reclaimable); 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(size_t));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(size_t));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &reclaim_target, sizeof(size_t));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  unsigned long __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* addr_cn = convert_to_cn_bits_u64(addr);
  cn_bits_u64* min_chunk_size_cn;
  min_chunk_size_cn = Cn_chunk_size(convert_to_cn_bits_u64(0ULL));
  cn_bits_u64* page_cn;
  page_cn = PAGE_ALIGN_DOWN(addr_cn);
  cn_bits_u64* delta_cn;
  delta_cn = cn_bits_u64_sub(addr_cn, page_cn);
  cn_bits_u64* res_cn;
  cn_bits_u64* a_11518;
  if (convert_from_cn_bool(cn_bits_u64_equality(delta_cn, convert_to_cn_bits_u64(0ULL)))) {
  a_11518 = addr_cn;
}
else {
  cn_bits_u64* a_11526;
  if (convert_from_cn_bool(cn_bits_u64_lt(delta_cn, min_chunk_size_cn))) {
    a_11526 = cn_bits_u64_add(page_cn, min_chunk_size_cn);
  }
  else {
    a_11526 = addr_cn;
  }
  a_11518 = a_11526;
}
  res_cn = a_11518;
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
        unsigned long min_chunk_size = (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL));
c_add_to_ghost_state((uintptr_t) &min_chunk_size, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* min_chunk_size_addr_cn = convert_to_cn_pointer((&min_chunk_size));

        unsigned long page = (((CN_LOAD((addr)) - (((1UL << 12)) - 1)) + ((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((addr) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1));
c_add_to_ghost_state((uintptr_t) &page, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));

        unsigned long delta = CN_LOAD(addr) - CN_LOAD(page);
c_add_to_ghost_state((uintptr_t) &delta, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* delta_addr_cn = convert_to_cn_pointer((&delta));

        if (!CN_LOAD(delta)) {
                { __cn_ret = CN_LOAD(addr); 
c_remove_from_ghost_state((uintptr_t) &min_chunk_size, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));
goto __cn_epilogue; }
        }
        /*
         * To maximize reclaim, a chunk must fit between the page start and this
         * addr.
         */
        if (CN_LOAD(delta) < CN_LOAD(min_chunk_size)) {
                { __cn_ret = CN_LOAD(page) + CN_LOAD(min_chunk_size); 
c_remove_from_ghost_state((uintptr_t) &min_chunk_size, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));
goto __cn_epilogue; }
        }
        { __cn_ret = CN_LOAD(addr); 
c_remove_from_ghost_state((uintptr_t) &min_chunk_size, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &min_chunk_size, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &delta, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(unsigned long));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("        return == res;\n        ^~~~~~~~~~~~~~ alloc.pp.c:1613:9-23");
  cn_assert(cn_bits_u64_equality(return_cn, res_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  _Bool __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1648:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1649:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  cn_pointer* chunk_node_ptr_cn;
  chunk_node_ptr_cn = cn_member_shift(chunk_cn, chunk_hdr, node);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        { __cn_ret = list_is_last(&CN_LOAD((chunk))->node, &CN_LOAD((allocator))->chunks); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1652:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1653:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                return == (Cn_list_is_last(B_pre.Node, member_shift<struct hyp_allocator>(allocator, chunks))? 1u8 : 0u8);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1654:17-123");
  cn_bits_u8* a_11589;
  if (convert_from_cn_bool(Cn_list_is_last(B_pre_cn->Node, cn_member_shift(allocator_cn, hyp_allocator, chunks)))) {
    a_11589 = convert_to_cn_bits_u8(1UL);
  }
  else {
    a_11589 = convert_to_cn_bits_u8(0UL);
  }
  cn_assert(cn_bits_u8_equality(return_cn, a_11589), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1662:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1663:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:1667:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1668:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr * next = list_is_last(&CN_LOAD((chunk))->node, &CN_LOAD((allocator))->chunks) ?
                NULL : ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.next)) + (0UL - offsetof(typeof(*(chunk)), node))));
c_add_to_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));

        chunk_hash_validate(CN_LOAD(next));
        { __cn_ret = CN_LOAD(next); 
c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("                take A_post =Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1670:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1671:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:1672:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies is_null(return);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1673:17-118");
  cn_assert(cn_bool_implies(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks)), is_null(return_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies ptr_eq(return, next_chunk);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1674:17-131");
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_last(Node_cn, cn_member_shift(allocator_cn, hyp_allocator, chunks))), ptr_eq(return_cn, next_chunk_cn)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  size_t __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("                take A_pre = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1685:22:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_pre = Cn_chunk_hdr(chunk, A_pre);\n                     ^alloc.pp.c:1686:22:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  struct a_9481_record* Hdr_cn;
  Hdr_cn = B_pre_cn->Hdr;
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("                take C_pre = Cn_chunk_hdr(next_chunk, A_pre);\n                     ^alloc.pp.c:1691:22:");
  struct Cn_chunk_hdr_record* C_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("                ptr_eq(C_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1692:17-86");
  cn_assert(ptr_eq(C_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        struct chunk_hdr *next = chunk_get_next(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));

        //struct chunk_hdr *next = my_chunk_get_next(chunk, allocator);
        unsigned long allocator_end = CN_LOAD(CN_LOAD((allocator))->start) + CN_LOAD(CN_LOAD((allocator))->size);
c_add_to_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* allocator_end_addr_cn = convert_to_cn_pointer((&allocator_end));

        { __cn_ret = CN_LOAD(next) ? (unsigned long)CN_LOAD(next) - ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size))
                    : CN_LOAD(allocator_end) - ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size)); 
c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &next, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &allocator_end, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  update_cn_error_message_info("                take A_post = Cn_hyp_allocator_only(allocator);\n                     ^alloc.pp.c:1694:22:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take B_post = Cn_chunk_hdr(chunk, A_post);\n                     ^alloc.pp.c:1695:22:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                take C_post = Cn_chunk_hdr(next_chunk, A_post);\n                     ^alloc.pp.c:1696:22:");
  struct Cn_chunk_hdr_record* C_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                A_pre == A_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1697:17-33");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_pre_cn, A_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                B_pre == B_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1698:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_pre_cn, B_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                C_pre == C_post;\n                ^~~~~~~~~~~~~~~~ alloc.pp.c:1699:17-33");
  cn_assert(struct_Cn_chunk_hdr_record_equality(C_pre_cn, C_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("                return == (u64)(Hdr.va_size - Hdr.mapped_size);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1700:17-64");
  cn_assert(cn_bits_u64_equality(return_cn, cast_cn_bits_u32_to_cn_bits_u64(cn_bits_u32_sub(Hdr_cn->va_size, Hdr_cn->mapped_size))), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  _Bool __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_bits_u64* addr_cn = convert_to_cn_bits_u64(addr);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("        take A_pre = Cn_hyp_allocator_only(allocator);\n             ^alloc.pp.c:1721:14:");
  struct Cn_hyp_allocator_only_record* A_pre_cn = Cn_hyp_allocator_only(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        take B_pre = Cn_chunk_hdr(chunk, A_pre);\n             ^alloc.pp.c:1722:14:");
  struct Cn_chunk_hdr_record* B_pre_cn = Cn_chunk_hdr(chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  cn_pointer* node_ptr_cn;
  node_ptr_cn = cn_member_shift(chunk_cn, chunk_hdr, node);
  struct a_9481_record* C_pre_cn;
  C_pre_cn = B_pre_cn->Hdr;
  struct list_head_cn* Node_cn;
  Node_cn = B_pre_cn->Node;
  cn_pointer* next_node_cn;
  next_node_cn = Node_cn->next;
  cn_pointer* next_chunk_cn;
  next_chunk_cn = my_container_of_chunk_hdr(next_node_cn);
  update_cn_error_message_info("        take D_pre = Cn_chunk_hdr(next_chunk, A_pre);\n             ^alloc.pp.c:1728:14:");
  struct Cn_chunk_hdr_record* D_pre_cn = Cn_chunk_hdr(next_chunk_cn, A_pre_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        ptr_eq(D_pre.Node.prev, member_shift<struct chunk_hdr>(chunk, node));\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1729:9-78");
  cn_assert(ptr_eq(D_pre_cn->Node->prev, cn_member_shift(chunk_cn, chunk_hdr, node)), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &addr, sizeof(unsigned long), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        unsigned long chunk_end;
c_add_to_ghost_state((uintptr_t) &chunk_end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* chunk_end_addr_cn = convert_to_cn_pointer((&chunk_end));

        /*
         * There is no point splitting the last chunk, subsequent allocations
         * would be able to use this space anyway.
         */
        if (list_is_last(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &chunk_end, sizeof(unsigned long));
goto __cn_epilogue; }
        }
        CN_STORE(chunk_end, (unsigned long)CN_LOAD(chunk) + CN_LOAD(CN_LOAD(chunk)->mapped_size) +
                    chunk_unmapped_size(CN_LOAD(chunk), CN_LOAD(allocator)));
        { __cn_ret = CN_LOAD(addr) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL)) < CN_LOAD(chunk_end); 
c_remove_from_ghost_state((uintptr_t) &chunk_end, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &chunk_end, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  update_cn_error_message_info("        take A_post = Cn_hyp_allocator_only(allocator);\n             ^alloc.pp.c:1731:14:");
  struct Cn_hyp_allocator_only_record* A_post_cn = Cn_hyp_allocator_only(allocator_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        take B_post = Cn_chunk_hdr(chunk, A_post);\n             ^alloc.pp.c:1732:14:");
  struct Cn_chunk_hdr_record* B_post_cn = Cn_chunk_hdr(chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        take D_post = Cn_chunk_hdr(next_chunk, A_post);\n             ^alloc.pp.c:1733:14:");
  struct Cn_chunk_hdr_record* D_post_cn = Cn_chunk_hdr(next_chunk_cn, A_post_cn, POST);
  cn_pop_msg_info();
  cn_bits_u64* chunk_end_cn;
  chunk_end_cn = cn_bits_u64_add(cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(chunk_cn), cast_cn_bits_u32_to_cn_bits_u64(C_pre_cn->mapped_size)), cast_cn_bits_u32_to_cn_bits_u64(Cn_chunk_unmapped_size(C_pre_cn)));
  update_cn_error_message_info("        Cn_list_is_last(Node, A_post.head)\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1737:9-1738:31");
  cn_assert(cn_bool_implies(Cn_list_is_last(Node_cn, A_post_cn->head), cn_bits_u8_equality(return_cn, convert_to_cn_bits_u8(0UL))), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        !Cn_list_is_last(Node, A_post.head)\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1739:9-1740:84");
  cn_bits_u8* a_11842;
  if (convert_from_cn_bool(cn_bits_u64_lt(cn_bits_u64_add(addr_cn, Cn_chunk_size(convert_to_cn_bits_u64(0ULL))), chunk_end_cn))) {
    a_11842 = convert_to_cn_bits_u8(1UL);
  }
  else {
    a_11842 = convert_to_cn_bits_u8(0UL);
  }
  cn_assert(cn_bool_implies(cn_bool_not(Cn_list_is_last(Node_cn, A_post_cn->head)), cn_bits_u8_equality(return_cn, a_11842)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        A_pre == A_post;\n        ^~~~~~~~~~~~~~~~ alloc.pp.c:1741:9-25");
  cn_assert(struct_Cn_hyp_allocator_only_record_equality(A_pre_cn, A_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        B_pre == B_post;\n        ^~~~~~~~~~~~~~~~ alloc.pp.c:1742:9-25");
  cn_assert(struct_Cn_chunk_hdr_record_equality(B_pre_cn, B_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        D_pre == D_post;\n        ^~~~~~~~~~~~~~~~ alloc.pp.c:1743:9-25");
  cn_assert(struct_Cn_chunk_hdr_record_equality(D_pre_cn, D_post_cn), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

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
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  update_cn_error_message_info("        take HA_pre = Cn_hyp_allocator(allocator);\n             ^alloc.pp.c:1766:14:");
  struct Cn_hyp_allocator_record* HA_pre_cn = Cn_hyp_allocator(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("        take C_pre = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:1768:14:");
  struct chunk_hdr_cn* C_pre_cn = owned_struct_chunk_hdr(chunk_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        unsigned long new_chunk_addr = (unsigned long)CN_LOAD(chunk) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL));
c_add_to_ghost_state((uintptr_t) &new_chunk_addr, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* new_chunk_addr_addr_cn = convert_to_cn_pointer((&new_chunk_addr));

        size_t missing_map, expected_mapping = CN_LOAD(size);
c_add_to_ghost_state((uintptr_t) &missing_map, sizeof(size_t), get_cn_stack_depth());


cn_pointer* missing_map_addr_cn = convert_to_cn_pointer((&missing_map));


c_add_to_ghost_state((uintptr_t) &expected_mapping, sizeof(size_t), get_cn_stack_depth());


cn_pointer* expected_mapping_addr_cn = convert_to_cn_pointer((&expected_mapping));

        struct chunk_hdr *new_chunk = NULL;
c_add_to_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* new_chunk_addr_cn = convert_to_cn_pointer((&new_chunk));

        int ret;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        CN_STORE(new_chunk_addr, chunk_addr_fixup(CN_LOAD(new_chunk_addr)));
        if (chunk_can_split(CN_LOAD(chunk), CN_LOAD(new_chunk_addr), CN_LOAD(allocator))) {
                CN_STORE(new_chunk, (struct chunk_hdr *)CN_LOAD(new_chunk_addr));
                // HK: when we can split the chunk,
                // the va addresses of the header of the new chunk have to be mapped.
                CN_STORE(expected_mapping, CN_LOAD(new_chunk_addr) + ((unsigned long)offsetof(struct chunk_hdr, data)) -
                                        (unsigned long)((void *)(&CN_LOAD((chunk))->data)));
        }
        // TODO: memcache part. We ignore this for now (HK).
        CN_STORE(missing_map, chunk_needs_mapping(CN_LOAD(chunk), CN_LOAD(expected_mapping)));
        if (CN_LOAD(missing_map)) {
                CN_STORE(ret, chunk_inc_map(CN_LOAD(chunk), CN_LOAD(missing_map), CN_LOAD(allocator)));
                if (CN_LOAD(ret)) {
                        { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((uintptr_t) &new_chunk_addr, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &missing_map, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &expected_mapping, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
                }
        }
        CN_STORE(CN_LOAD(chunk)->alloc_size, CN_LOAD(size));
        chunk_hash_update(CN_LOAD(chunk));
        if (CN_LOAD(new_chunk)) {
                (!!(chunk_install(CN_LOAD(new_chunk), 0, CN_LOAD(chunk), CN_LOAD(allocator))));
        }
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &new_chunk_addr, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &missing_map, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &expected_mapping, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &new_chunk_addr, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &missing_map, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &expected_mapping, sizeof(size_t));


c_remove_from_ghost_state((uintptr_t) &new_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("        take C_post = RW<struct chunk_hdr>(chunk);\n             ^alloc.pp.c:1771:14:");
  struct chunk_hdr_cn* C_post_cn = owned_struct_chunk_hdr(chunk_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_post.alloc_size == (u32)size;\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1772:9-40");
  cn_assert(cn_bits_u32_equality(C_post_cn->alloc_size, cast_cn_bits_u64_to_cn_bits_u32(size_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_post.mapped_size == C_pre.mapped_size;\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1773:9-49");
  cn_assert(cn_bits_u32_equality(C_post_cn->mapped_size, C_pre_cn->mapped_size), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_post.node == C_pre.node;\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1774:9-35");
  cn_assert(struct_list_head_cn_equality(C_post_cn->node, C_pre_cn->node), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        C_post.data == C_pre.data;\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1775:9-35");
  cn_assert(cn_bits_u8_equality(C_post_cn->data, C_pre_cn->data), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        return == 0i32;\n        ^~~~~~~~~~~~~~~ alloc.pp.c:1776:9-24");
  cn_assert(cn_bits_i32_equality(return_cn, convert_to_cn_bits_i32(0LL)), POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static size_t chunk_try_destroy(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator,
                                size_t reclaim_target)
{
  /* EXECUTABLE CN PRECONDITION */
  size_t __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* reclaim_target_cn = convert_to_cn_bits_u64(reclaim_target);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &reclaim_target, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* reclaim_target_addr_cn = convert_to_cn_pointer((&reclaim_target));
  
        size_t unmapped;
c_add_to_ghost_state((uintptr_t) &unmapped, sizeof(size_t), get_cn_stack_depth());


cn_pointer* unmapped_addr_cn = convert_to_cn_pointer((&unmapped));

        if ((!!CN_LOAD(CN_LOAD((chunk))->alloc_size))) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
        }
        /* Don't kill the entire chunk if this is not necessary */
        if (CN_LOAD(CN_LOAD(chunk)->mapped_size) > CN_LOAD(reclaim_target)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
        }
        if (list_is_first(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                /* last standing chunk ? */
                if (!list_is_last(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
                }
                list_del(&CN_LOAD(chunk)->node);
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
        if (!((((unsigned long)((unsigned long)CN_LOAD(chunk))) & ((typeof((unsigned long)((unsigned long)chunk)))((1UL << 12)) - 1)) == 0)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
        }
        if (list_is_last(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                goto destroy;
        }
        if ((!!CN_LOAD((chunk_get_prev(CN_LOAD(chunk), CN_LOAD(allocator)))->alloc_size))) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
        }
        if (chunk_split_aligned(CN_LOAD(chunk), CN_LOAD(allocator))) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }
        }
destroy:
        chunk_list_del(CN_LOAD(chunk), CN_LOAD(allocator));
unmap:
        CN_STORE(unmapped, CN_LOAD(CN_LOAD(chunk)->mapped_size));
        hyp_allocator_unmap(CN_LOAD(allocator), (unsigned long)CN_LOAD(chunk),
                            CN_LOAD(CN_LOAD(chunk)->mapped_size));
        { __cn_ret = CN_LOAD(unmapped); 
c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &unmapped, sizeof(size_t));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &reclaim_target, sizeof(size_t));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}

static int setup_first_chunk(struct hyp_allocator *allocator, size_t size)
/*@ requires take a_in=Cn_hyp_allocator(allocator);
    a_in.hdrs==Chunk_nil{};
    ensures
    take X = SetupFirstChunk(allocator, a_in.ha, size, return);
    X;
@*/
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  update_cn_error_message_info("/*@ requires take a_in=Cn_hyp_allocator(allocator);\n                  ^alloc.pp.c:1886:19:");
  struct Cn_hyp_allocator_record* a_in_cn = Cn_hyp_allocator(allocator_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("    a_in.hdrs==Chunk_nil{};\n    ^~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1887:5-28");
  struct cn_chunk_hdrs* a_12014 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
  a_12014->tag = CHUNK_NIL;
  cn_assert(struct_cn_chunk_hdrs_equality(a_in_cn->hdrs, a_12014), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        int ret;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        CN_STORE(ret, hyp_allocator_map(CN_LOAD(allocator), CN_LOAD(CN_LOAD(allocator)->start),
                                (((((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL)))) + ((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(size), 8UL)))))(((1UL << 12))) - 1))));
        if (CN_LOAD(ret)) {
                { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
        }
        { __cn_ret = chunk_install((struct chunk_hdr *)CN_LOAD(CN_LOAD(allocator)->start), CN_LOAD(size), NULL, CN_LOAD(allocator)); 
c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  update_cn_error_message_info("    take X = SetupFirstChunk(allocator, a_in.ha, size, return);\n         ^alloc.pp.c:1889:10:");
  cn_bool* X_cn = SetupFirstChunk(allocator_cn, a_in_cn->ha, size_cn, return_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("    X;\n    ^~ alloc.pp.c:1890:5-7");
  cn_assert(X_cn, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}

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
  /* EXECUTABLE CN PRECONDITION */
  struct chunk_hdr* __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  update_cn_error_message_info("requires take HA_in = Cn_hyp_allocator(allocator);\n              ^alloc.pp.c:1937:15:");
  struct Cn_hyp_allocator_record* HA_in_cn = Cn_hyp_allocator(allocator_cn, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        struct chunk_hdr *chunk, *best_chunk = NULL;
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));


c_add_to_ghost_state((uintptr_t) &best_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* best_chunk_addr_cn = convert_to_cn_pointer((&best_chunk));

        size_t best_available_size = CN_LOAD(CN_LOAD(allocator)->size);
c_add_to_ghost_state((uintptr_t) &best_available_size, sizeof(size_t), get_cn_stack_depth());


cn_pointer* best_available_size_addr_cn = convert_to_cn_pointer((&best_available_size));

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
        {
cn_pointer* O_chunk7;

cn_pointer* O_best_chunk0;

cn_bits_u64* O_best_available_size0;

cn_pointer* O_allocator8;

cn_bits_u64* O_size2;
for (CN_STORE(chunk, ((typeof(*chunk) *)((unsigned char *)CN_LOAD(((&CN_LOAD(allocator)->chunks)->next)) + (0UL - offsetof(typeof(*chunk), node))))); ({
  ghost_stack_depth_incr();
  update_cn_error_message_info("        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0U...\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1965:9-1989:10");
  O_chunk7 = owned_struct_chunk_hdr_pointer(chunk_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0U...\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1965:9-1989:10");
  O_best_chunk0 = owned_struct_chunk_hdr_pointer(best_chunk_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0U...\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1965:9-1989:10");
  O_best_available_size0 = owned_size_t(best_available_size_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0U...\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1965:9-1989:10");
  O_allocator8 = owned_struct_hyp_allocator_pointer(allocator_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        for (chunk = ((typeof(*chunk) *)((unsigned char *)((&allocator->chunks)->next) + (0UL - offsetof(typeof(*chunk), node)))); !(&chunk->node == (&allocator->chunks)); chunk = ((typeof(*(chunk)) *)((unsigned char *)((chunk)->node.next) + (0U...\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1965:9-1989:10");
  O_size2 = owned_size_t(size_addr_cn, LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("        /*@ inv {allocator} unchanged;\n                ^~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1966:17-39");
  cn_assert(cn_pointer_equality(O_allocator8, allocator_cn), LOOP);
  cn_pop_msg_info();
  update_cn_error_message_info("                {size} unchanged;\n                ^~~~~~~~~~~~~~~~~ alloc.pp.c:1967:17-34");
  cn_assert(cn_bits_u64_equality(O_size2, size_cn), LOOP);
  cn_pop_msg_info();
  cn_loop_put_back_ownership();
  ghost_stack_depth_decr();
  0;
})
, !(&CN_LOAD(chunk)->node == (&CN_LOAD(allocator)->chunks)); CN_STORE(chunk, ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.next)) + (0UL - offsetof(typeof(*(chunk)), node))))))
        /*@ inv {allocator} unchanged;
                {size} unchanged;
                //take Fst = Cn_chunk_hdrs_rev(ha.first, ha.head, ha, Chunk_nil{});
        @*/
        {
                size_t available_size = CN_LOAD(CN_LOAD(chunk)->mapped_size) +
                                        chunk_unmapped_size(CN_LOAD(chunk), CN_LOAD(allocator));
c_add_to_ghost_state((uintptr_t) &available_size, sizeof(size_t), get_cn_stack_depth());


cn_pointer* available_size_addr_cn = convert_to_cn_pointer((&available_size));

                if ((!!CN_LOAD(CN_LOAD((chunk))->alloc_size))) {
                        continue;
                }
                if ((((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL)) > CN_LOAD(available_size)) {
                        continue;
                }
                if (!CN_LOAD(best_chunk)) {
                        CN_STORE(best_chunk, CN_LOAD(chunk));
                        // [BUG] HK: why best_available_size is not set here?
                        continue;
                }
                if (CN_LOAD(best_available_size) <= CN_LOAD(available_size)) {
                        continue;
                }
                CN_STORE(best_chunk, CN_LOAD(chunk));
                CN_STORE(best_available_size, CN_LOAD(available_size));
        
c_remove_from_ghost_state((uintptr_t) &available_size, sizeof(size_t));
}}
        { __cn_ret = chunk_get(CN_LOAD(best_chunk)); 
c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &best_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &best_available_size, sizeof(size_t));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &best_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &best_available_size, sizeof(size_t));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("        take res = GetFreeChunk(allocator, size, return, HA_in);\n             ^alloc.pp.c:1939:14:");
  cn_bool* res_cn = GetFreeChunk(allocator_cn, size_cn, return_cn, HA_in_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("        res;\n        ^~~~ alloc.pp.c:1940:9-13");
  cn_assert(res_cn, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}

void *hyp_alloc(size_t size)
/*@
        requires true;
        // TODO: allocator (global variable) ownership
        ensures take U = MaybeCn_char_array(return, size);
@*/
{
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  update_cn_error_message_info("        requires true;\n                 ^~~~~ alloc.pp.c:2026:18-23");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        struct hyp_allocator *allocator = &hyp_allocator;
c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());


cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));

        struct chunk_hdr *chunk, *last_chunk;
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));


c_add_to_ghost_state((uintptr_t) &last_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* last_chunk_addr_cn = convert_to_cn_pointer((&last_chunk));

        unsigned long chunk_addr;
c_add_to_ghost_state((uintptr_t) &chunk_addr, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* chunk_addr_addr_cn = convert_to_cn_pointer((&chunk_addr));

        int missing_map, ret = 0;
c_add_to_ghost_state((uintptr_t) &missing_map, sizeof(signed int), get_cn_stack_depth());


cn_pointer* missing_map_addr_cn = convert_to_cn_pointer((&missing_map));


c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        CN_STORE(size, ((CN_LOAD(((size))) + ((typeof((size)))((8UL)) - 1)) & ~((typeof((size)))((8UL)) - 1)));
        hyp_spin_lock(&CN_LOAD(allocator)->lock);
        //PS: ownership from lock invariant
        //PS: hyp_spin_lock returns Cn_hyp_allocator(&allocator)
        if (list_empty(&hyp_allocator.chunks)) {
                CN_STORE(ret, setup_first_chunk(CN_LOAD(allocator), CN_LOAD(size)));
                if (CN_LOAD(ret)) {
                        goto end;
                }
                CN_STORE(chunk, (struct chunk_hdr *)CN_LOAD(CN_LOAD(allocator)->start));
                goto end;
        }
        CN_STORE(chunk, get_free_chunk(CN_LOAD(allocator), CN_LOAD(size)));
        if (CN_LOAD(chunk)) {
                CN_STORE(ret, chunk_recycle(CN_LOAD(chunk), CN_LOAD(size), CN_LOAD(allocator)));
                goto end;
        }
        // HK: when there is no free chunk, we divide the last chunk
        CN_STORE(last_chunk, chunk_get(((struct chunk_hdr *)((unsigned char *)CN_LOAD(((&CN_LOAD(allocator)->chunks)->prev)) + (0UL - offsetof(struct chunk_hdr, node))))));
        CN_STORE(chunk_addr, (unsigned long)CN_LOAD(last_chunk) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((CN_LOAD(last_chunk)->alloc_size)), 8UL)));
        CN_STORE(chunk_addr, chunk_addr_fixup(CN_LOAD(chunk_addr)));
        CN_STORE(chunk, (struct chunk_hdr *)CN_LOAD(chunk_addr));
        CN_STORE(missing_map, chunk_needs_mapping(CN_LOAD(last_chunk),
                                          CN_LOAD(chunk_addr) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((size)), 8UL)) -
                                                (unsigned long)((void *)(&CN_LOAD((last_chunk))->data))));
        if (CN_LOAD(missing_map)) {
                CN_STORE(ret, chunk_inc_map(CN_LOAD(last_chunk), CN_LOAD(missing_map), CN_LOAD(allocator)));
                if (CN_LOAD(ret)){
                        goto end;
                }
        }
        (!!(chunk_install(CN_LOAD(chunk), CN_LOAD(size), CN_LOAD(last_chunk), CN_LOAD(allocator))));
end:
        hyp_spin_unlock(&CN_LOAD(allocator)->lock);
        CN_STORE(*((&hyp_allocator_errno)), CN_LOAD(ret));
        /* Enforce zeroing allocated memory */
        if (!CN_LOAD(ret)) {
                memset(((void *)(&CN_LOAD((chunk))->data)), 0, CN_LOAD(size));
        }
        { __cn_ret = CN_LOAD(ret) ? NULL : ((void *)(&CN_LOAD((chunk))->data)); 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &last_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &chunk_addr, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &missing_map, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &last_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &chunk_addr, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &missing_map, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  update_cn_error_message_info("        ensures take U = MaybeCn_char_array(return, size);\n                     ^alloc.pp.c:2028:22:");
  MaybeCn_char_array(return_cn, size_cn, POST);
  cn_pop_msg_info();
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
void hyp_free(void *addr)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
        struct chunk_hdr *chunk, *prev_chunk, *next_chunk;
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));


c_add_to_ghost_state((uintptr_t) &prev_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* prev_chunk_addr_cn = convert_to_cn_pointer((&prev_chunk));


c_add_to_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* next_chunk_addr_cn = convert_to_cn_pointer((&next_chunk));

        struct hyp_allocator *allocator = &hyp_allocator;
c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());


cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));

        char *chunk_data = (char *)CN_LOAD(addr);
c_add_to_ghost_state((uintptr_t) &chunk_data, sizeof(char*), get_cn_stack_depth());


cn_pointer* chunk_data_addr_cn = convert_to_cn_pointer((&chunk_data));

        hyp_spin_lock(&CN_LOAD(allocator)->lock);
        CN_STORE(chunk, chunk_get(((struct chunk_hdr *)((unsigned char *)CN_LOAD((chunk_data)) + (0UL - offsetof(struct chunk_hdr, data))))));
        CN_STORE(prev_chunk, chunk_get_prev(CN_LOAD(chunk), CN_LOAD(allocator)));
        CN_STORE(next_chunk, chunk_get_next(CN_LOAD(chunk), CN_LOAD(allocator)));
        // HK: free is easy :) except for merging
        CN_STORE(CN_LOAD(chunk)->alloc_size, 0);
        chunk_hash_update(CN_LOAD(chunk));
        if (CN_LOAD(next_chunk) && !(!!CN_LOAD(CN_LOAD((next_chunk))->alloc_size))) {
                (!!(chunk_merge(CN_LOAD(next_chunk), CN_LOAD(allocator))));
        }
        if (CN_LOAD(prev_chunk) && !(!!CN_LOAD(CN_LOAD((prev_chunk))->alloc_size))) {
                (!!(chunk_merge(CN_LOAD(chunk), CN_LOAD(allocator))));
        }
        hyp_spin_unlock(&CN_LOAD(allocator)->lock);

c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &prev_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &next_chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &chunk_data, sizeof(char*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(void*));

{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
/*
 * While chunk_try_destroy() is actually destroying what can be, this function
 * only help with estimating how much pages can be reclaimed. However the same
 * comments apply here.
 */
static _Bool chunk_destroyable(struct chunk_hdr *chunk,
                              struct hyp_allocator *allocator)
{
  /* EXECUTABLE CN PRECONDITION */
  _Bool __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        if ((!!CN_LOAD(CN_LOAD((chunk))->alloc_size))) {
                { __cn_ret = 0; goto __cn_epilogue; }
        }
        if (!((((unsigned long)CN_LOAD((chunk))) & ((typeof((unsigned long)(chunk)))((1UL << 12)) - 1)) == 0)) {
                { __cn_ret = 0; goto __cn_epilogue; }
        }
        if (list_is_first(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                if (list_is_last(&CN_LOAD(chunk)->node, &CN_LOAD(allocator)->chunks)) {
                        { __cn_ret = 1; goto __cn_epilogue; }
                }
                { __cn_ret = 0; goto __cn_epilogue; }
        }
        { __cn_ret = !(!!CN_LOAD((chunk_get_prev(CN_LOAD(chunk), CN_LOAD(allocator)))->alloc_size)); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
static size_t chunk_reclaimable(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator)
{
  /* EXECUTABLE CN PRECONDITION */
  size_t __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* chunk_cn = convert_to_cn_pointer(chunk);
  cn_pointer* allocator_cn = convert_to_cn_pointer(allocator);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());
  cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));
  c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());
  cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));
  
        unsigned long start, end = ((unsigned long)CN_LOAD((chunk)) + CN_LOAD(CN_LOAD(chunk)->mapped_size));
c_add_to_ghost_state((uintptr_t) &start, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* start_addr_cn = convert_to_cn_pointer((&start));


c_add_to_ghost_state((uintptr_t) &end, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* end_addr_cn = convert_to_cn_pointer((&end));

        /*
         * This should not happen, chunks are installed at a minimum distance
         * from the page start
         */
        (!!(!((((unsigned long)CN_LOAD((end))) & ((typeof((unsigned long)(end)))((1UL << 12)) - 1)) == 0) && (CN_LOAD(end) - (((CN_LOAD((end)) - (((1UL << 12)) - 1)) + ((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) < (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(0UL), 8UL)))));
        if (chunk_destroyable(CN_LOAD(chunk), CN_LOAD(allocator))) {
                CN_STORE(start, (unsigned long)CN_LOAD(chunk));
        }
        else {
                CN_STORE(start, (((((unsigned long)CN_LOAD(chunk) + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)CN_LOAD((CN_LOAD(chunk)->alloc_size)), 8UL)))) + ((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)) & ~((typeof(((unsigned long)chunk + (((unsigned long)offsetof(struct chunk_hdr, data)) + max_u64((unsigned long)(chunk->alloc_size), 8UL)))))(((1UL << 12))) - 1)));
        }
        CN_STORE(end, (((CN_LOAD((end)) - (((1UL << 12)) - 1)) + ((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)) & ~((typeof((end) - (((1UL << 12)) - 1)))(((1UL << 12))) - 1)));
        if (CN_LOAD(start) > CN_LOAD(end)) {
                { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));
goto __cn_epilogue; }
        }
        { __cn_ret = CN_LOAD(end) - CN_LOAD(start); 
c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &start, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &end, sizeof(unsigned long));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));

  c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
// HK: counts the number of unused but mapped pages.
// This includes the pages that are in the memcache.
int hyp_alloc_reclaimable(void)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
        struct hyp_allocator *allocator = &hyp_allocator;
c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());


cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));

        struct chunk_hdr *chunk;
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));

        int reclaimable = 0;
c_add_to_ghost_state((uintptr_t) &reclaimable, sizeof(signed int), get_cn_stack_depth());


cn_pointer* reclaimable_addr_cn = convert_to_cn_pointer((&reclaimable));

        int cpu;
c_add_to_ghost_state((uintptr_t) &cpu, sizeof(signed int), get_cn_stack_depth());


cn_pointer* cpu_addr_cn = convert_to_cn_pointer((&cpu));

        hyp_spin_lock(&CN_LOAD(allocator)->lock);
        /*
         * This is slightly pessimistic: a real reclaim might be able to "fix"
         * discontiguous unmapped region by deleting chunks from the top to the
         * bottom.
         */
        for (CN_STORE(chunk, ((typeof(*chunk) *)((unsigned char *)CN_LOAD(((&CN_LOAD(allocator)->chunks)->next)) + (0UL - offsetof(typeof(*chunk), node))))); !(&CN_LOAD(chunk)->node == (&CN_LOAD(allocator)->chunks)); CN_STORE(chunk, ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.next)) + (0UL - offsetof(typeof(*(chunk)), node))))))
                CN_STORE_OP(reclaimable,+,chunk_reclaimable(CN_LOAD(chunk), CN_LOAD(allocator)) >> 12);
        for (CN_STORE(cpu, 0); CN_LOAD(cpu) < CN_LOAD(hyp_nr_cpus); CN_POSTFIX(cpu, ++)) {
                struct kvm_hyp_memcache *mc = (&hyp_allocator_mc);
c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());


cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));

                CN_STORE_OP(reclaimable,+,CN_LOAD(CN_LOAD(mc)->nr_pages));
        
c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));
}
        hyp_spin_unlock(&CN_LOAD(allocator)->lock);
        { __cn_ret = CN_LOAD(reclaimable); 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &cpu, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &reclaimable, sizeof(signed int));


c_remove_from_ghost_state((uintptr_t) &cpu, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
// Hk: another interesting target
void hyp_alloc_reclaim(struct kvm_hyp_memcache *mc, int target)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  cn_pointer* mc_cn = convert_to_cn_pointer(mc);
  cn_bits_i32* target_cn = convert_to_cn_bits_i32(target);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));
  c_add_to_ghost_state((uintptr_t) &target, sizeof(signed int), get_cn_stack_depth());
  cn_pointer* target_addr_cn = convert_to_cn_pointer((&target));
  
        struct hyp_allocator *allocator = &hyp_allocator;
c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());


cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));

        struct kvm_hyp_memcache *alloc_mc;
c_add_to_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());


cn_pointer* alloc_mc_addr_cn = convert_to_cn_pointer((&alloc_mc));

        struct chunk_hdr *chunk, *tmp;
c_add_to_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* chunk_addr_cn = convert_to_cn_pointer((&chunk));


c_add_to_ghost_state((uintptr_t) &tmp, sizeof(struct chunk_hdr*), get_cn_stack_depth());


cn_pointer* tmp_addr_cn = convert_to_cn_pointer((&tmp));

        int cpu;
c_add_to_ghost_state((uintptr_t) &cpu, sizeof(signed int), get_cn_stack_depth());


cn_pointer* cpu_addr_cn = convert_to_cn_pointer((&cpu));

        if (CN_LOAD(target) <= 0) {
                { 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &tmp, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &cpu, sizeof(signed int));
goto __cn_epilogue; }

        }
        hyp_spin_lock(&CN_LOAD(allocator)->lock);
        /* Start emptying potential unused memcache */
        for (CN_STORE(cpu, 0); CN_LOAD(cpu) < CN_LOAD(hyp_nr_cpus); CN_POSTFIX(cpu, ++)) {
                CN_STORE(alloc_mc, (&hyp_allocator_mc));
                while (CN_LOAD(CN_LOAD(alloc_mc)->nr_pages)) {
                        unsigned long order;
c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));

                        void *page = pop_hyp_memcache(CN_LOAD(alloc_mc), hyp_phys_to_virt, &order);
c_add_to_ghost_state((uintptr_t) &page, sizeof(void*), get_cn_stack_depth());


cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));

                        (!!CN_LOAD((order)));
                        push_hyp_memcache(CN_LOAD(mc), CN_LOAD(page), hyp_virt_to_phys, 0);
                        (!!(__pkvm_hyp_donate_host(hyp_virt_to_pfn(CN_LOAD(page)), 1)));
                        CN_POSTFIX(target, --);
                        if (CN_LOAD(target) <= 0) {
                                goto done;
                        }
                
c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(void*));
}
        }
        for (CN_STORE(chunk, ((typeof(*chunk) *)((unsigned char *)CN_LOAD(((&CN_LOAD(allocator)->chunks)->prev)) + (0UL - offsetof(typeof(*chunk), node))))), CN_STORE(tmp, ((typeof(*(chunk)) *)((unsigned char *)CN_LOAD((CN_LOAD((chunk))->node.prev)) + (0UL - offsetof(typeof(*(chunk)), node))))); !(&CN_LOAD(chunk)->node == (&CN_LOAD(allocator)->chunks)); CN_STORE(chunk, CN_LOAD(tmp)), CN_STORE(tmp, ((typeof(*(tmp)) *)((unsigned char *)CN_LOAD((CN_LOAD((tmp))->node.prev)) + (0UL - offsetof(typeof(*(tmp)), node)))))) {
                size_t r;
c_add_to_ghost_state((uintptr_t) &r, sizeof(size_t), get_cn_stack_depth());


cn_pointer* r_addr_cn = convert_to_cn_pointer((&r));

                chunk_hash_validate(CN_LOAD(chunk));
                CN_STORE(r, chunk_try_destroy(CN_LOAD(chunk), CN_LOAD(allocator), CN_LOAD(target) << 12));
                if (!CN_LOAD(r)) {
                        CN_STORE(r, chunk_dec_map(CN_LOAD(chunk), CN_LOAD(allocator), CN_LOAD(target) << 12));
                }
                CN_STORE_OP(target,-,CN_LOAD(r) >> 12);
                if (CN_LOAD(target) <= 0) {
                        
c_remove_from_ghost_state((uintptr_t) &r, sizeof(size_t));
break;
                }
        
c_remove_from_ghost_state((uintptr_t) &r, sizeof(size_t));
}
        CN_STORE(alloc_mc, (&hyp_allocator_mc));
        while (CN_LOAD(CN_LOAD(alloc_mc)->nr_pages)) {
                unsigned long order;
c_add_to_ghost_state((uintptr_t) &order, sizeof(unsigned long), get_cn_stack_depth());


cn_pointer* order_addr_cn = convert_to_cn_pointer((&order));

                void *page = pop_hyp_memcache(CN_LOAD(alloc_mc), hyp_phys_to_virt, &order);
c_add_to_ghost_state((uintptr_t) &page, sizeof(void*), get_cn_stack_depth());


cn_pointer* page_addr_cn = convert_to_cn_pointer((&page));

                (!!CN_LOAD((order)));
                memset(CN_LOAD(page), 0, (1UL << 12));
                                                        ;
                push_hyp_memcache(CN_LOAD(mc), CN_LOAD(page), hyp_virt_to_phys, 0);
                (!!(__pkvm_hyp_donate_host(hyp_virt_to_pfn(CN_LOAD(page)), 1)));
        
c_remove_from_ghost_state((uintptr_t) &order, sizeof(unsigned long));


c_remove_from_ghost_state((uintptr_t) &page, sizeof(void*));
}
done:
        hyp_spin_unlock(&CN_LOAD(allocator)->lock);

c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*));


c_remove_from_ghost_state((uintptr_t) &chunk, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &tmp, sizeof(struct chunk_hdr*));


c_remove_from_ghost_state((uintptr_t) &cpu, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));

  c_remove_from_ghost_state((uintptr_t) &target, sizeof(signed int));

{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
int hyp_alloc_refill(struct kvm_hyp_memcache *host_mc)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* host_mc_cn = convert_to_cn_pointer(host_mc);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &host_mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* host_mc_addr_cn = convert_to_cn_pointer((&host_mc));
  
        struct kvm_hyp_memcache *alloc_mc = (&hyp_allocator_mc);
c_add_to_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());


cn_pointer* alloc_mc_addr_cn = convert_to_cn_pointer((&alloc_mc));

        { __cn_ret = refill_memcache(CN_LOAD(alloc_mc), CN_LOAD(CN_LOAD(host_mc)->nr_pages) + CN_LOAD(CN_LOAD(alloc_mc)->nr_pages),
                               CN_LOAD(host_mc)); 
c_remove_from_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &alloc_mc, sizeof(struct kvm_hyp_memcache*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &host_mc, sizeof(struct kvm_hyp_memcache*));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
int hyp_alloc_init(size_t size)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* size_cn = convert_to_cn_bits_u64(size);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &size, sizeof(size_t), get_cn_stack_depth());
  cn_pointer* size_addr_cn = convert_to_cn_pointer((&size));
  
        struct hyp_allocator *allocator = &hyp_allocator;
c_add_to_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*), get_cn_stack_depth());


cn_pointer* allocator_addr_cn = convert_to_cn_pointer((&allocator));

        int ret;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

        CN_STORE(size, ((CN_LOAD(((size))) + ((typeof((size)))(((1UL << 12))) - 1)) & ~((typeof((size)))(((1UL << 12))) - 1)));
        /* constrained by chunk_hdr *_size types */
        if (CN_LOAD(size) > ((u32)~0U)) {
                { __cn_ret = -22; 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
        }
        CN_STORE(ret, pkvm_alloc_private_va_range(CN_LOAD(size), &CN_LOAD(allocator)->start));
        if (CN_LOAD(ret)) {
                { __cn_ret = CN_LOAD(ret); 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }
        }
        CN_STORE(CN_LOAD(allocator)->size, CN_LOAD(size));
        INIT_LIST_HEAD(&CN_LOAD(allocator)->chunks);
                                            ;
        { __cn_ret = 0; 
c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &allocator, sizeof(struct hyp_allocator*));


c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &size, sizeof(size_t));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
int hyp_alloc_errno(void)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
        int *errno = (&hyp_allocator_errno);
c_add_to_ghost_state((uintptr_t) &errno, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* errno_addr_cn = convert_to_cn_pointer((&errno));

        { __cn_ret = CN_LOAD(*CN_LOAD(errno)); 
c_remove_from_ghost_state((uintptr_t) &errno, sizeof(signed int*));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &errno, sizeof(signed int*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
u8 hyp_alloc_missing_donations(void)
{
  /* EXECUTABLE CN PRECONDITION */
  unsigned char __cn_ret;
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
        u8 *missing = ((&hyp_allocator_missing_donations));
c_add_to_ghost_state((uintptr_t) &missing, sizeof(unsigned char*), get_cn_stack_depth());


cn_pointer* missing_addr_cn = convert_to_cn_pointer((&missing));

        u8 __missing = CN_LOAD(*CN_LOAD(missing));
c_add_to_ghost_state((uintptr_t) &__missing, sizeof(unsigned char), get_cn_stack_depth());


cn_pointer* __missing_addr_cn = convert_to_cn_pointer((&__missing));

        CN_STORE(*CN_LOAD(missing), 0);
        { __cn_ret = CN_LOAD(__missing); 
c_remove_from_ghost_state((uintptr_t) &missing, sizeof(unsigned char*));


c_remove_from_ghost_state((uintptr_t) &__missing, sizeof(unsigned char));
goto __cn_epilogue; }

c_remove_from_ghost_state((uintptr_t) &missing, sizeof(unsigned char*));


c_remove_from_ghost_state((uintptr_t) &__missing, sizeof(unsigned char));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  cn_bits_u8* return_cn = convert_to_cn_bits_u8(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
void dump_chunks(void)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}

int main() {
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret = 0;
  initialise_ownership_ghost_state();
  initialise_ghost_stack_depth();
  c_add_to_ghost_state((uintptr_t) &hyp_nr_cpus, sizeof(unsigned long), get_cn_stack_depth());
  c_add_to_ghost_state((uintptr_t) &hyp_allocator_errno, sizeof(signed int), get_cn_stack_depth());
  c_add_to_ghost_state((uintptr_t) &hyp_allocator_mc, sizeof(struct kvm_hyp_memcache), get_cn_stack_depth());
  c_add_to_ghost_state((uintptr_t) &hyp_allocator_missing_donations, sizeof(unsigned char), get_cn_stack_depth());
  c_add_to_ghost_state((uintptr_t) &hyp_allocator, sizeof(struct hyp_allocator), get_cn_stack_depth());
  
/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  c_remove_from_ghost_state((uintptr_t) &hyp_nr_cpus, sizeof(unsigned long));

  c_remove_from_ghost_state((uintptr_t) &hyp_allocator_errno, sizeof(signed int));

  c_remove_from_ghost_state((uintptr_t) &hyp_allocator_mc, sizeof(struct kvm_hyp_memcache));

  c_remove_from_ghost_state((uintptr_t) &hyp_allocator_missing_donations, sizeof(unsigned char));

  c_remove_from_ghost_state((uintptr_t) &hyp_allocator, sizeof(struct hyp_allocator));

return __cn_ret;

}

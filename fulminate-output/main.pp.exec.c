#include "main.pp.cn.h"
#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

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
  update_cn_error_message_info("	ensures return == (x < y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:82:10-36");
  cn_bits_u32* a_2643;
  if (convert_from_cn_bool(cn_bits_u32_lt(x_cn, y_cn))) {
    a_2643 = x_cn;
  }
  else {
    a_2643 = y_cn;
  }
  cn_assert(cn_bits_u32_equality(return_cn, a_2643), POST);
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
  update_cn_error_message_info("	ensures return == (x < y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:89:10-36");
  cn_bits_u64* a_2672;
  if (convert_from_cn_bool(cn_bits_u64_lt(x_cn, y_cn))) {
    a_2672 = x_cn;
  }
  else {
    a_2672 = y_cn;
  }
  cn_assert(cn_bits_u64_equality(return_cn, a_2672), POST);
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
  update_cn_error_message_info("	ensures return == (x > y ? x : y);\n	        ^~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:96:10-36");
  cn_bits_u64* a_2701;
  if (convert_from_cn_bool(cn_bits_u64_lt(y_cn, x_cn))) {
    a_2701 = x_cn;
  }
  else {
    a_2701 = y_cn;
  }
  cn_assert(cn_bits_u64_equality(return_cn, a_2701), POST);
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
  update_cn_error_message_info("		take H_pre = RW<struct list_head>(head);\n       ^main.pp.c:151:8:");
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
  update_cn_error_message_info("		take H_post = RW<struct list_head>(head);\n       ^main.pp.c:153:8:");
  struct list_head_cn* H_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		return == (ptr_eq(H_post.next, head) ? 1i32 : 0i32);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:154:3-55");
  cn_bits_i32* a_2740;
  if (convert_from_cn_bool(ptr_eq(H_post_cn->next, head_cn))) {
    a_2740 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_2740 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_2740), POST);
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
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^main.pp.c:169:8:");
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
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^main.pp.c:171:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(L_post.next, list);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:172:3-29");
  cn_assert(ptr_eq(L_post_cn->next, list_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(L_post.prev, list);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:173:3-29");
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
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^main.pp.c:228:8:");
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
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^main.pp.c:230:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		L_pre == L_post;\n		^~~~~~~~~~~~~~~~ main.pp.c:231:3-19");
  cn_assert(struct_list_head_cn_equality(L_pre_cn, L_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		return == (ptr_eq(L_pre.prev, head) ? 1i32 : 0i32);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:232:3-54");
  cn_bits_i32* a_2813;
  if (convert_from_cn_bool(ptr_eq(L_pre_cn->prev, head_cn))) {
    a_2813 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_2813 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_2813), POST);
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
  update_cn_error_message_info("		take L_pre = RW<struct list_head>(list);\n       ^main.pp.c:240:8:");
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
  update_cn_error_message_info("		take L_post = RW<struct list_head>(list);\n       ^main.pp.c:242:8:");
  struct list_head_cn* L_post_cn = owned_struct_list_head(list_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		L_pre == L_post;\n		^~~~~~~~~~~~~~~~ main.pp.c:243:3-19");
  cn_assert(struct_list_head_cn_equality(L_pre_cn, L_post_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("	return == (ptr_eq(L_pre.next, head) ? 1i32 : 0i32);\n	^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:244:2-53");
  cn_bits_i32* a_2864;
  if (convert_from_cn_bool(ptr_eq(L_pre_cn->next, head_cn))) {
    a_2864 = convert_to_cn_bits_i32(1LL);
  }
  else {
    a_2864 = convert_to_cn_bits_i32(0LL);
  }
  cn_assert(cn_bits_i32_equality(return_cn, a_2864), POST);
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
  update_cn_error_message_info("		take New_pre = RW<struct list_head>(new);\n       ^main.pp.c:264:8:");
  struct list_head_cn* New_pre_cn = owned_struct_list_head(new_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_pre = RW<struct list_head>(head);\n       ^main.pp.c:265:8:");
  struct list_head_cn* Head_pre_cn = owned_struct_list_head(head_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		!ptr_eq(new, next);\n		^~~~~~~~~~~~~~~~~~~ main.pp.c:266:3-22");
  cn_assert(cn_bool_not(ptr_eq(new_cn, next_cn)), PRE);
  cn_pop_msg_info();
  cn_bool* p_cn;
  p_cn = cn_bool_not(ptr_eq(head_cn, next_cn));
  update_cn_error_message_info("		take Next_pre_opt = CondListHead(next, p);\n       ^main.pp.c:268:8:");
  struct list_head_option* Next_pre_opt_cn = CondListHead(next_cn, p_cn, PRE);
  cn_pop_msg_info();
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &new, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* new_addr_cn = convert_to_cn_pointer((&new));
  c_add_to_ghost_state((uintptr_t) &prev, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* prev_addr_cn = convert_to_cn_pointer((&prev));
  c_add_to_ghost_state((uintptr_t) &next, sizeof(struct list_head*), get_cn_stack_depth());
  cn_pointer* next_addr_cn = convert_to_cn_pointer((&next));
  
 update_cn_error_message_info(" /*@ split_case(!ptr_eq(head, next)); @*/\n    ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:283:5-40");

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
  update_cn_error_message_info("		take New_post = RW<struct list_head>(new);\n       ^main.pp.c:270:8:");
  struct list_head_cn* New_post_cn = owned_struct_list_head(new_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_post = RW<struct list_head>(head);\n       ^main.pp.c:271:8:");
  struct list_head_cn* Head_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));\n       ^main.pp.c:272:8:");
  struct list_head_option* Next_post_opt_cn = CondListHead(next_cn, cn_bool_not(ptr_eq(head_cn, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		match Next_post_opt {\n		^~~~~~~~~~~~~~~~~~~~~ main.pp.c:273:3-280:5");
  cn_bool* a_2949;
  switch (Next_post_opt_cn->tag)
  {
    case LIST_HEAD_NONE:
    {
      struct list_head_none* list_head_none_1 = Next_post_opt_cn->u.list_head_none;
      a_2949 = list_add_aux(Head_post_cn, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
    case LIST_HEAD_SOME:
    {
      struct list_head_some* list_head_some_1 = Next_post_opt_cn->u.list_head_some;
      struct list_head_cn* Next_post = list_head_some_1->L;
      a_2949 = list_add_aux(Next_post, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
  }
  cn_assert(a_2949, POST);
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
  update_cn_error_message_info("		take New_pre = RW<struct list_head>(new);\n       ^main.pp.c:307:8:");
  struct list_head_cn* New_pre_cn = owned_struct_list_head(new_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_pre = RW<struct list_head>(head);\n       ^main.pp.c:308:8:");
  struct list_head_cn* Head_pre_cn = owned_struct_list_head(head_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Head_pre_cn->next;
  update_cn_error_message_info("		!ptr_eq(new, next);\n		^~~~~~~~~~~~~~~~~~~ main.pp.c:310:3-22");
  cn_assert(cn_bool_not(ptr_eq(new_cn, next_cn)), PRE);
  cn_pop_msg_info();
  cn_bool* p_cn;
  p_cn = cn_bool_not(ptr_eq(head_cn, next_cn));
  update_cn_error_message_info("		take Next_pre_opt = CondListHead(next, p);\n       ^main.pp.c:312:8:");
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
  update_cn_error_message_info("		take New_post = RW<struct list_head>(new);\n       ^main.pp.c:314:8:");
  struct list_head_cn* New_post_cn = owned_struct_list_head(new_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Head_post = RW<struct list_head>(head);\n       ^main.pp.c:315:8:");
  struct list_head_cn* Head_post_cn = owned_struct_list_head(head_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post_opt = CondListHead(next, !ptr_eq(head, next));\n       ^main.pp.c:316:8:");
  struct list_head_option* Next_post_opt_cn = CondListHead(next_cn, cn_bool_not(ptr_eq(head_cn, next_cn)), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		match Next_post_opt {\n		^~~~~~~~~~~~~~~~~~~~~ main.pp.c:317:3-324:5");
  cn_bool* a_3023;
  switch (Next_post_opt_cn->tag)
  {
    case LIST_HEAD_NONE:
    {
      struct list_head_none* list_head_none_1 = Next_post_opt_cn->u.list_head_none;
      a_3023 = list_add_aux(Head_post_cn, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
    case LIST_HEAD_SOME:
    {
      struct list_head_some* list_head_some_1 = Next_post_opt_cn->u.list_head_some;
      struct list_head_cn* Next_post = list_head_some_1->L;
      a_3023 = list_add_aux(Next_post, New_post_cn, Head_post_cn, new_cn, next_cn, head_cn);
      break;
    }
  }
  cn_assert(a_3023, POST);
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
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^main.pp.c:339:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^main.pp.c:340:8:");
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
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^main.pp.c:342:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^main.pp.c:343:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:344:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:345:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:346:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:347:3-41");
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
  update_cn_error_message_info("		take Entry_pre = RW<struct list_head>(entry);\n       ^main.pp.c:358:8:");
  struct list_head_cn* Entry_pre_cn = owned_struct_list_head(entry_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Entry_pre_cn->next;
  cn_pointer* prev_cn;
  prev_cn = Entry_pre_cn->prev;
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^main.pp.c:361:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^main.pp.c:362:8:");
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
  update_cn_error_message_info("		take Entry_post = RW<struct list_head>(entry);\n       ^main.pp.c:364:8:");
  struct list_head_cn* Entry_post_cn = owned_struct_list_head(entry_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^main.pp.c:365:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^main.pp.c:366:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:367:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:368:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:369:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:370:3-41");
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
  update_cn_error_message_info("		take Entry_pre = RW<struct list_head>(entry);\n       ^main.pp.c:379:8:");
  struct list_head_cn* Entry_pre_cn = owned_struct_list_head(entry_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  cn_pointer* next_cn;
  next_cn = Entry_pre_cn->next;
  cn_pointer* prev_cn;
  prev_cn = Entry_pre_cn->prev;
  update_cn_error_message_info("		take Next_pre = RW<struct list_head>(next);\n       ^main.pp.c:382:8:");
  struct list_head_cn* Next_pre_cn = owned_struct_list_head(next_cn, PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), PRE);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_pre = RW<struct list_head>(prev);\n       ^main.pp.c:383:8:");
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
  update_cn_error_message_info("		take Entry_post = RW<struct list_head>(entry);\n       ^main.pp.c:385:8:");
  struct list_head_cn* Entry_post_cn = owned_struct_list_head(entry_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Next_post = RW<struct list_head>(next);\n       ^main.pp.c:386:8:");
  struct list_head_cn* Next_post_cn = owned_struct_list_head(next_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		take Prev_post = RW<struct list_head>(prev);\n       ^main.pp.c:387:8:");
  struct list_head_cn* Prev_post_cn = owned_struct_list_head(prev_cn, POST);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.next, next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:388:3-32");
  cn_assert(ptr_eq(Prev_post_cn->next, next_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.prev, prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:389:3-32");
  cn_assert(ptr_eq(Next_post_cn->prev, prev_cn), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Prev_post.prev, Prev_pre.prev);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:390:3-41");
  cn_assert(ptr_eq(Prev_post_cn->prev, Prev_pre_cn->prev), POST);
  cn_pop_msg_info();
  update_cn_error_message_info("		ptr_eq(Next_post.next, Next_pre.next);\n		^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ main.pp.c:391:3-41");
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
  { __cn_ret = __cerbvar_NULL; 
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
  /* EXECUTABLE CN PRECONDITION */
  unsigned long long __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* addr_cn = convert_to_cn_pointer(addr);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(void*), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
 { __cn_ret = (phys_addr_t)CN_LOAD(addr); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(void*));

{
  cn_bits_u64* return_cn = convert_to_cn_bits_u64(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
void* ident_to_va(phys_addr_t addr)
{
  /* EXECUTABLE CN PRECONDITION */
  void* __cn_ret;
  ghost_stack_depth_incr();
  cn_bits_u64* addr_cn = convert_to_cn_bits_u64(addr);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &addr, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* addr_addr_cn = convert_to_cn_pointer((&addr));
  
 { __cn_ret = (void*)CN_LOAD(addr); goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &addr, sizeof(unsigned long long));

{
  cn_pointer* return_cn = convert_to_cn_pointer(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
int dummy_memcache(struct kvm_hyp_memcache *mc, u64 min_pages)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret;
  ghost_stack_depth_incr();
  cn_pointer* mc_cn = convert_to_cn_pointer(mc);
  cn_bits_u64* min_pages_cn = convert_to_cn_bits_u64(min_pages);
  
	/* C OWNERSHIP */

  c_add_to_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*), get_cn_stack_depth());
  cn_pointer* mc_addr_cn = convert_to_cn_pointer((&mc));
  c_add_to_ghost_state((uintptr_t) &min_pages, sizeof(unsigned long long), get_cn_stack_depth());
  cn_pointer* min_pages_addr_cn = convert_to_cn_pointer((&min_pages));
  
 while (CN_LOAD(CN_LOAD(mc)->nr_pages) < CN_LOAD(min_pages)) {
  phys_addr_t *p = aligned_alloc((1UL << 12), (1UL << 12));
c_add_to_ghost_state((uintptr_t) &p, sizeof(unsigned long long*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

  memset(CN_LOAD(p), 0, (1UL << 12));
  if (!CN_LOAD(p)) {
   { __cn_ret = -12; 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
goto __cn_epilogue; }
  }
  push_hyp_memcache(CN_LOAD(mc), CN_LOAD(p), ident_to_pa, 0);
  // printf("  \x1b[32mPUSHED: %p -- head: %p\x1b[0m\n", p, (void*)mc->head);
 
c_remove_from_ghost_state((uintptr_t) &p, sizeof(unsigned long long*));
}
 { __cn_ret = 0; goto __cn_epilogue; }

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


  c_remove_from_ghost_state((uintptr_t) &mc, sizeof(struct kvm_hyp_memcache*));

  c_remove_from_ghost_state((uintptr_t) &min_pages, sizeof(unsigned long long));

{
  cn_bits_i32* return_cn = convert_to_cn_bits_i32(__cn_ret);
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}

return __cn_ret;

}
void dump_chunks(void);
struct kvm_hyp_memcache host_mc = { 0 };
void test1(void)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
 int *p = hyp_alloc(4*sizeof(int));
c_add_to_ghost_state((uintptr_t) &p, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

 assert(CN_LOAD(p));
 dump_chunks();
 int *q = hyp_alloc((1UL << 12) + 128);
c_add_to_ghost_state((uintptr_t) &q, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* q_addr_cn = convert_to_cn_pointer((&q));

 assert(CN_LOAD(q));
 dump_chunks();
 hyp_free(CN_LOAD(p));
 dump_chunks();
 hyp_free(CN_LOAD(q));
 dump_chunks();
 CN_STORE(p, hyp_alloc(sizeof(int)));
 assert(CN_LOAD(p));
 dump_chunks();

c_remove_from_ghost_state((uintptr_t) &p, sizeof(signed int*));


c_remove_from_ghost_state((uintptr_t) &q, sizeof(signed int*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
void test2(void)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
 dump_chunks();
 int *p = hyp_alloc(4*sizeof(int));
c_add_to_ghost_state((uintptr_t) &p, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

 assert(CN_LOAD(p));
 dump_chunks();
 int *q = hyp_alloc((1UL << 12) + 128);
c_add_to_ghost_state((uintptr_t) &q, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* q_addr_cn = convert_to_cn_pointer((&q));

 assert(CN_LOAD(q));
 dump_chunks();
 int *r = hyp_alloc(sizeof(int));
c_add_to_ghost_state((uintptr_t) &r, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* r_addr_cn = convert_to_cn_pointer((&r));

 assert(CN_LOAD(r));
 dump_chunks();
 hyp_free(CN_LOAD(r));
 dump_chunks();
 hyp_free(CN_LOAD(q));
 dump_chunks();
 CN_STORE(r, hyp_alloc((1UL << 12)));
 assert(CN_LOAD(r));
 dump_chunks();
 CN_STORE(q, hyp_alloc(sizeof(int)));
 assert(CN_LOAD(q));
 dump_chunks();
 // printf("==> %d\n", hyp_alloc_reclaimable());
 hyp_free(CN_LOAD(r));
 dump_chunks();
 hyp_alloc_reclaim(&host_mc, 14);
 dump_chunks();
 // printf("==> %d\n", hyp_alloc_reclaimable());

c_remove_from_ghost_state((uintptr_t) &p, sizeof(signed int*));


c_remove_from_ghost_state((uintptr_t) &q, sizeof(signed int*));


c_remove_from_ghost_state((uintptr_t) &r, sizeof(signed int*));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
void test3(void)
{
  /* EXECUTABLE CN PRECONDITION */
  ghost_stack_depth_incr();
  
	/* C OWNERSHIP */

  
 dump_chunks();
 assert(hyp_alloc(sizeof(int)));
 dump_chunks();
 int *p = hyp_alloc(8 + (1UL << 12));
c_add_to_ghost_state((uintptr_t) &p, sizeof(signed int*), get_cn_stack_depth());


cn_pointer* p_addr_cn = convert_to_cn_pointer((&p));

 assert(CN_LOAD(p));
 dump_chunks();
 hyp_free(CN_LOAD(p));
 dump_chunks();
 int n = hyp_alloc_reclaimable();
c_add_to_ghost_state((uintptr_t) &n, sizeof(signed int), get_cn_stack_depth());


cn_pointer* n_addr_cn = convert_to_cn_pointer((&n));

 dump_chunks();
 // printf("==> %d\n", n);
 // printf("errno: %d\n", hyp_alloc_errno());
 hyp_alloc_reclaim(&host_mc, CN_LOAD(n));
 // n = hyp_alloc_reclaimable();
 // printf("==> %d\n", n);

c_remove_from_ghost_state((uintptr_t) &p, sizeof(signed int*));


c_remove_from_ghost_state((uintptr_t) &n, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  
	/* C OWNERSHIP */


{
  ghost_stack_depth_decr();
  cn_postcondition_leak_check();
}
;
}
void shim_create_hyp_mapping(size_t size);
int main(void)
{
  /* EXECUTABLE CN PRECONDITION */
  signed int __cn_ret = 0;
  initialise_ownership_ghost_state();
  initialise_ghost_stack_depth();
  c_add_to_ghost_state((uintptr_t) &host_mc, sizeof(struct kvm_hyp_memcache), get_cn_stack_depth());
  
 int ret;
c_add_to_ghost_state((uintptr_t) &ret, sizeof(signed int), get_cn_stack_depth());


cn_pointer* ret_addr_cn = convert_to_cn_pointer((&ret));

 // SHIM INIT
 shim_create_hyp_mapping(64 << 12);
 // printf("HYP_ALLOC_INIT\n");
 CN_STORE(ret, hyp_alloc_init(16*(1UL << 12)));
 if(CN_LOAD(ret)) {
  do { exit(1); } while(0);
 }
 CN_STORE(ret, dummy_memcache(&host_mc, 16));
 if (CN_LOAD(ret)) {
  do { exit(1); } while(0);
 }
 // printf("HYP_ALLOC_REFILL\n");
 hyp_alloc_refill(&host_mc);
 test3();

c_remove_from_ghost_state((uintptr_t) &ret, sizeof(signed int));

/* EXECUTABLE CN POSTCONDITION */
__cn_epilogue:

  c_remove_from_ghost_state((uintptr_t) &host_mc, sizeof(struct kvm_hyp_memcache));

return __cn_ret;

}

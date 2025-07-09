/* SPDX-License-Identifier: GPL-2.0 */
/*
 * This is a cutdown version of include/linux/list.h
 */
#ifndef _LINUX_LIST_H
#define _LINUX_LIST_H

#include <linux/container_of.h>

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
		H_pre == H_post;
		return == (ptr_eq(H_post.next, head) ? 1i32 : 0i32);
@*/
{
	return READ_ONCE(head->next) == head;
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
		take L_pre = W<struct list_head>(list);
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
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)

/**
 * list_prev_entry - get the prev element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
#define list_prev_entry(pos, member) \
	list_entry((pos)->member.prev, typeof(*(pos)), member)


/**
 * list_next_entry - get the next element in list
 * @pos:	the type * to cursor
 * @member:	the name of the list_head within the struct.
 */
#define list_next_entry(pos, member) \
	list_entry((pos)->member.next, typeof(*(pos)), member)

/**
 * list_first_entry - get the first element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_first_entry(ptr, type, member) \
	list_entry((ptr)->next, type, member)

/**
 * list_last_entry - get the last element from a list
 * @ptr:	the list head to take the element from.
 * @type:	the type of the struct this is embedded in.
 * @member:	the name of the list_head within the struct.
 *
 * Note, that list is expected to be not empty.
 */
#define list_last_entry(ptr, type, member) \
	list_entry((ptr)->prev, type, member)

/**
 * list_entry_is_head - test if the entry points to the head of the list
 * @pos:	the type * to cursor
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
#define list_entry_is_head(pos, head, member)				\
	(&pos->member == (head))


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
		take New_pre = W<struct list_head>(new);
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
				list_add_aux(Head_post, New_post, Head_post, new, next, head, Next_pre_opt, New_pre, Head_pre)
			}
			List_Head_Some { L: Next_post } => {
				list_add_aux(Next_post, New_post, Head_post, new, next, head, Next_pre_opt, New_pre, Head_pre)
			}
		};
@*/
{
#if 0
	if (!__list_add_valid(new, prev, next))
		return;
#endif
	/*@ split_case(!ptr_eq(head, next)); @*/
	/*@ unpack CondListHead(next,p); @*/
	next->prev = new;
	new->next = next;
	new->prev = prev;
	// HK: removed WRITE_ONCE
	// WRITE_ONCE(prev->next, new);
	prev->next = new;
}

/*@
function (boolean) list_add_aux(struct list_head Next_post, struct list_head New_post, struct list_head Head_post, pointer new, pointer next, pointer head, datatype list_head_option Next_pre_opt, struct list_head New_pre, struct list_head Head_pre)
{
	// can be aliased
	match Next_pre_opt {
		List_Head_None {} => {
            ptr_eq(Next_post.prev, new)
	        && ptr_eq(New_post.next, next)
	        && ptr_eq(New_post.prev, head)
	        && ptr_eq(Head_post.next, new)
		    && ptr_eq(Head_post.prev, new)
		    && ptr_eq(Next_post.next, new)
		}
		// the case head != next
		List_Head_Some { L: Next_pre } => {
            ptr_eq(Next_post.prev, new)
	        && ptr_eq(New_post.next, next)
	        && ptr_eq(New_post.prev, head)
	        && ptr_eq(Head_post.next, new)
		    && ptr_eq(Head_post.prev, Head_pre.prev)
		    && ptr_eq(Next_post.next, Next_pre.next)
		}
	}
}
@*/

// Spec is almost the copy of __list_add.
static inline void list_add(struct list_head *new, struct list_head *head)
/*@
	requires
		take New_pre = W<struct list_head>(new);
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
				list_add_aux(Head_post, New_post, Head_post, new, next, head, Next_pre_opt, New_pre, Head_pre)
			}
			List_Head_Some { L: Next_post } => {
				list_add_aux(Next_post, New_post, Head_post, new, next, head, Next_pre_opt, New_pre, Head_pre)
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
		Entry_pre == Entry_post;
@*/
{
#if 0
	if (!__list_del_entry_valid(entry))
		return;
#endif

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
		Entry_pre == Entry_post;
@*/
{
	__list_del_entry(entry);
#if 0
	entry->next = LIST_POISON1;
	entry->prev = LIST_POISON2;
#endif
}

/**
 * list_for_each_entry	-	iterate over list of given type
 * @pos:	the type * to use as a loop cursor.
 * @head:	the head for your list.
 * @member:	the name of the list_head within the struct.
 */
#define list_for_each_entry(pos, head, member)				\
	for (pos = list_first_entry(head, typeof(*pos), member);	\
	     !list_entry_is_head(pos, head, member);			\
	     pos = list_next_entry(pos, member))

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
#define list_for_each_entry_safe_reverse(pos, n, head, member)		\
	for (pos = list_last_entry(head, typeof(*pos), member),		\
		n = list_prev_entry(pos, member);			\
	     !list_entry_is_head(pos, head, member); 			\
	     pos = n, n = list_prev_entry(n, member))


#endif /* _LINUX_LIST_H */

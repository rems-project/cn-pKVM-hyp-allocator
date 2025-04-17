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
static inline void __list_add(struct list_head *new,
			      struct list_head *prev,
			      struct list_head *next)
/*@
	requires
		!ptr_eq(new, prev) && !ptr_eq(prev, next) && !ptr_eq(next, new);
		take New_pre = RW<struct list_head>(new);
		take Prev_pre = RW<struct list_head>(prev);
		take Next_pre = RW<struct list_head>(next);
	ensures
		take Prev_post = RW<struct list_head>(prev);
		take Next_post = RW<struct list_head>(next);
		take New_post = RW<struct list_head>(new);
		ptr_eq(Next_post.prev, new);
		ptr_eq(New_post.next, next);
		ptr_eq(New_post.prev, prev);
		ptr_eq(Prev_post.next, new);
@*/
{
#if 0
	if (!__list_add_valid(new, prev, next))
		return;
#endif

	next->prev = new;
	new->next = next;
	new->prev = prev;
	// HK: removed WRITE_ONCE
	// WRITE_ONCE(prev->next, new);
	prev->next = new;
}

// HK: this is not complete
// we have to handle the case for the first allocation where
// head == allocator->chunks and head->next == allocator->chunks
static inline void list_add(struct list_head *new, struct list_head *head)
/*@
	requires
		take New_pre = RW<struct list_head>(new);
		take Head_pre = RW<struct list_head>(head);
		let next = Head_pre.next;
		!ptr_eq(new, head);
		!ptr_eq(head, next);
		!ptr_eq(next, new);
		take Next_pre = RW<struct list_head>(next);
	ensures
		take New_post = RW<struct list_head>(new);
		take Head_post = RW<struct list_head>(head);
		take Next_post = RW<struct list_head>(next);
		ptr_eq(Next_post.prev, new);
		ptr_eq(New_post.next, next);
		ptr_eq(New_post.prev, head);
		ptr_eq(Head_post.next, new);
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
{
	next->prev = prev;
	WRITE_ONCE(prev->next, next);
}

static inline void __list_del_entry(struct list_head *entry)
{
#if 0
	if (!__list_del_entry_valid(entry))
		return;
#endif

	__list_del(entry->prev, entry->next);
}

static inline void list_del(struct list_head *entry)
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

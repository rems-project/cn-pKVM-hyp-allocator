/* originally: ./include/linux/list.h */

/* SPDX-License-Identifier: GPL-2.0 */

#define list_entry(ptr, type, member) \
    container_of(ptr, type, member)
#define list_first_entry(ptr, type, member) \
    list_entry((ptr)->next, type, member)

static inline int list_empty(const struct list_head *head)
/*@ requires take O = Owned(head); 
  ptr_eq(head, (*head).next) || !addr_eq(head, (*head).next); 
 ensures take OR = Owned(head); 
  O == OR; 
  return == (((*head).next == head) ? 1i32 : 0i32); @*/
{
    /* return READ_ONCE(head->next) == head; */
    return head->next == head;
}

/* renamed list to llist to avoid clash with CN keyword list */
static inline void INIT_LIST_HEAD(struct list_head *llist)
/*@ requires take O = Owned(llist); 
 ensures take OR = Owned(llist); 
  (*llist).next == llist; (*llist).prev == llist; @*/
{
    /* WRITE_ONCE (llist->next, llist); */
    llist->next = llist;
    llist->prev = llist;
}

static inline bool __list_del_entry_valid(struct list_head *entry)
/*@ ensures return == 1u8; @*/
{
    return true;
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
        /*@ split_case prev != next; @*/
        next->prev = prev;
        /* WRITE_ONCE (prev->next, next); */
        prev->next = next;
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
        /*@ split_case (*entry).prev != entry; @*/
        /*@ split_case (*entry).prev != (*entry).next; @*/
    if (!__list_del_entry_valid(entry))
        return;

    __list_del(entry->prev, entry->next);
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
        /*CN*/ if(entry->prev != entry)
        ;
        /*CN*/ if(entry->prev != entry->next)
        ;
    __list_del_entry(entry);
    INIT_LIST_HEAD(entry);
}

static inline bool __list_add_valid(struct list_head *new,
                struct list_head *prev,
                struct list_head *next)
/*@ ensures return == 1u8; @*/
{
    return true;
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
    if (!__list_add_valid(new, prev, next))
        return;

        /*@ split_case prev != next; @*/
    next->prev = new;
    new->next = next;
    new->prev = prev;
    /* WRITE_ONCE (prev->next, new); */
    prev->next = new;
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
        /*@ split_case (*head).prev != head; @*/
    __list_add(new, head->prev, head);
}

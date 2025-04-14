// SPDX-License-Identifier: GPL-2.0-only
/*
 * Copyright (C) 2023 Google LLC
 * Author: Vincent Donnefort <vdonnefort@google.com>
 */

#ifdef STANDALONE
#include <prelude.h>
#include <alloc.h>
extern unsigned long hyp_nr_cpus;
#else
#include <nvhe/alloc.h>
#include <nvhe/alloc_mgt.h>
#include <nvhe/mem_protect.h>
#include <nvhe/mm.h>
#include <nvhe/spinlock.h>

#include <linux/build_bug.h>
#include <linux/hash.h>
#include <linux/kvm_host.h>
#include <linux/list.h>
#endif /* STANDALONE */

#define MIN_ALLOC 8UL
/*@ function (u64) MIN_ALLOC () @*/
static unsigned long c_MIN_ALLOC() /*@  cn_function MIN_ALLOC; @*/
{
        return MIN_ALLOC;
}

static DEFINE_PER_CPU(int, hyp_allocator_errno);
static DEFINE_PER_CPU(struct kvm_hyp_memcache, hyp_allocator_mc);
static DEFINE_PER_CPU(u8, hyp_allocator_missing_donations);


static struct hyp_allocator {
        struct list_head        chunks;
        unsigned long           start;
        u32                     size;
        hyp_spinlock_t          lock;
} hyp_allocator;

struct chunk_hdr {
        u32                     alloc_size;
        u32                     mapped_size;
        struct list_head        node;
        u32                     hash;
        char                    data __aligned(8);
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
    trusted; // TODO(HK): for now because I don't know how to handle the cast below correctly.
    requires
        take C_pre = Owned<struct chunk_hdr>(chunk);
    ensures
        take C_post = Owned<struct chunk_hdr>(chunk);
        C_pre == C_post;
@*/
{
        size_t len = offsetof(struct chunk_hdr, hash);
        // HK: How do I handle this cast while having the ownership to chunk??
        u64 *data = (u64 *)chunk;
        u32 hash = 0;

        BUILD_BUG_ON(!IS_ALIGNED(offsetof(struct chunk_hdr, hash), sizeof(u32)));

    while (len >= sizeof(u64))
    {
        hash ^= hash_64(*data, 32);
        len -= sizeof(u64);
        data++;
    }

        if (len)
                hash ^= hash_32(*(u32 *)data, 32);

        return hash;
}

static inline void chunk_hash_update(struct chunk_hdr *chunk)
/*@
    requires
        take C_pre = Owned<struct chunk_hdr>(chunk);
    ensures
        take C_post = Owned<struct chunk_hdr>(chunk);
        hash_change_only(C_pre, C_post);
@*/
{
        if (chunk)
                chunk->hash = chunk_hash_compute(chunk);
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
        if (chunk)
                WARN_ON(chunk->hash != chunk_hash_compute(chunk));
}

#define chunk_is_used(chunk) \
        (!!(chunk)->alloc_size)

#define chunk_hdr_size() \
        offsetof(struct chunk_hdr, data)

#ifdef NO_STATEMENT_EXPRS
#define chunk_size(size) \
        (chunk_hdr_size() + max_u64((size_t)(size), MIN_ALLOC))
#else /* NO_STATEMENT_EXPRS */
#define chunk_size(size) \
        (chunk_hdr_size() + max((size_t)(size), MIN_ALLOC))
#endif /* NO_STATEMENT_EXPRS */

#ifdef __cerb__
/*@
// HK: size_t cast is removed. Macro requires cast because it does not know what the
// argument type is.
function (u64) Cn_chunk_size (u64 size)
{
        (u64) offsetof(chunk_hdr, data) + (size > MIN_ALLOC() ? size : MIN_ALLOC())
        //(u64) member_shift<struct chunk_hdr>(NULL, data) + (size > MIN_ALLOC() ? size : MIN_ALLOC())
}
function (pointer) Cn_chunk_data (struct chunk_hdr chunk)
{
    (pointer)chunk.data
}

@*/
#endif

#ifdef __cerb__
#include "../specs/spec.c"
#endif

#define chunk_data(chunk) \
        ((void *)(&(chunk)->data))
#ifdef NO_STATEMENT_EXPRS
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
                C_pre.Node.prev == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies return == NULL;
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies return == next_chunk;
@*/
{
        return list_is_last(&(chunk)->node, &(allocator)->chunks) ?
                NULL : list_next_entry(chunk, node);
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
                C_pre.Node.next == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(prev_chunk, A_post);
                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies return == NULL;
                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies return == prev_chunk;
@*/
{
        return list_is_first(&(chunk)->node, &(allocator)->chunks) ?
                NULL : list_prev_entry(chunk, node);
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
                C_pre.Node.prev == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies return == NULL;
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies return == next_chunk;
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
                C_pre.Node.next == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(prev_chunk, A_post);
                Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies return == NULL;
                !Cn_list_is_first(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies return == prev_chunk;
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
                return == addr;
@*/
{
        struct chunk_hdr *chunk = (struct chunk_hdr *)addr;
        chunk_hash_validate(chunk);
        return chunk;
}

#define chunk_unmapped_region(chunk) \
        ((unsigned long)(chunk) + chunk->mapped_size)
/*@
function (u64) Cn_chunk_unmapped_region(pointer chunk_p, struct chunk_hdr chunk)
{
    (u64)chunk_p + (u64)chunk.mapped_size
}
@*/

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
                C_pre.Node.prev == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                A_pre == A_post;
                B_pre == B_post;
                return == (u64)(Hdr.va_size - Hdr.mapped_size);
@*/
{
        struct chunk_hdr *next = chunk_get_next(chunk, allocator);
        unsigned long allocator_end = (allocator)->start +
                                      (allocator)->size;
        return next ? (unsigned long)next - chunk_unmapped_region(chunk) :
                allocator_end - chunk_unmapped_region(chunk);
}
#else /* NO_STATEMENT_EXPRS */
#define __chunk_next(chunk, allocator)                          \
({                                                              \
        list_is_last(&(chunk)->node, &(allocator)->chunks) ?    \
                NULL : list_next_entry(chunk, node);            \
})

#define __chunk_prev(chunk, allocator)                          \
({                                                              \
        list_is_first(&(chunk)->node, &(allocator)->chunks) ?   \
                NULL : list_prev_entry(chunk, node);            \
})

#define chunk_get_next(chunk, allocator)                        \
({                                                              \
        struct chunk_hdr *next = __chunk_next(chunk, allocator);\
        chunk_hash_validate(next);                              \
        next;                                                   \
})

#define chunk_get_prev(chunk, allocator)                        \
({                                                              \
        struct chunk_hdr *prev = __chunk_prev(chunk, allocator);\
        chunk_hash_validate(prev);                              \
        prev;                                                   \
})

#define chunk_get(addr)                                         \
({                                                              \
        struct chunk_hdr *chunk = (struct chunk_hdr *)addr;     \
        chunk_hash_validate(chunk);                             \
        chunk;                                                  \
})

#define chunk_unmapped_region(chunk) \
        ((unsigned long)(chunk) + chunk->mapped_size)

#define chunk_unmapped_size(chunk, allocator)                           \
({                                                                      \
        struct chunk_hdr *next = chunk_get_next(chunk, allocator);      \
        unsigned long allocator_end = (allocator)->start +              \
                                      (allocator)->size;                \
        next ? (unsigned long)next - chunk_unmapped_region(chunk) :     \
                allocator_end - chunk_unmapped_region(chunk);           \
})
#endif /* NO_STATEMENT_EXPRS */

/*@
function (boolean) Cn_list_is_first(struct list_head node, pointer chunks)
{
        node.prev == chunks
}
function (boolean) Cn_list_is_last(struct list_head node, pointer chunks)
{
        node.next == chunks
}
function (pointer) Cn_chunk_get_next(struct chunk_hdr chunk, pointer allocator)
{
        Cn_list_is_last(chunk.node, member_shift<struct hyp_allocator>(allocator, chunks)) ?
        NULL : my_container_of_chunk_hdr(chunk.node.next)
}
// Q(HK): Do I need both &alloactor and allocator? Is there a better way to write &X?
function (u32) Cn_chunk_unmapped_size(cn_chunk_hdr hdr)
{
        hdr.va_size - hdr.mapped_size
}
@*/

static inline void chunk_list_insert(struct chunk_hdr *chunk,
                                     struct chunk_hdr *prev,
                                     struct hyp_allocator *allocator)
/*@
    requires
        take C_pre = Owned<struct chunk_hdr>(chunk);
        take HA_in = Cn_hyp_allocator(allocator);
    ensures
        take HA_out = Cn_hyp_allocator(allocator);
        take C_post = Owned<struct chunk_hdr>(chunk);
@*/
{
        // HK: non-rust ownership type part
        list_add(&chunk->node, &prev->node);
        chunk_hash_update(prev);
        chunk_hash_update(__chunk_next(chunk, allocator));
        chunk_hash_update(chunk);
}

static inline void chunk_list_del(struct chunk_hdr *chunk,
                                  struct hyp_allocator *allocator)
{
        struct chunk_hdr *prev = __chunk_prev(chunk, allocator);
        struct chunk_hdr *next = __chunk_next(chunk, allocator);

        list_del(&chunk->node);
        chunk_hash_update(prev);
        chunk_hash_update(next);
}

static void hyp_allocator_unmap(struct hyp_allocator *allocator,
                                unsigned long va, size_t size)
{
        struct kvm_hyp_memcache *mc = this_cpu_ptr(&hyp_allocator_mc);
        int nr_pages = size >> PAGE_SHIFT;
        unsigned long __va = va;

        WARN_ON(!PAGE_ALIGNED(va));
        WARN_ON(!PAGE_ALIGNED(size));

        while (nr_pages--) {
                phys_addr_t pa = __pkvm_private_range_pa((void *)__va);
                void *page = hyp_phys_to_virt(pa);

                push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                __va += PAGE_SIZE;
        }

        pkvm_remove_mappings((void *)va, (void *)(va + size));
}

static int hyp_allocator_map(struct hyp_allocator *allocator,
                             unsigned long va, size_t size)
{
        struct kvm_hyp_memcache *mc = this_cpu_ptr(&hyp_allocator_mc);
        unsigned long va_end = va + size;
        int ret, nr_pages = 0;

        if (!PAGE_ALIGNED(va) || !PAGE_ALIGNED(size))
                return -EINVAL;

        if (va_end < va || va_end > (allocator->start + allocator->size))
                return -E2BIG;

        if (mc->nr_pages < (size >> PAGE_SHIFT)) {
                u8 *missing_donations = this_cpu_ptr(&hyp_allocator_missing_donations);
                u32 delta = (size >> PAGE_SHIFT) - mc->nr_pages;

#ifdef NO_STATEMENT_EXPRS
                *missing_donations = min_u32(delta, U8_MAX);
#else /* NO_STATEMENT_EXPRS*/
                *missing_donations = min(delta, U8_MAX);
#endif /* NO_STATEMENT_EXPRS */

                return -ENOMEM;
        }

        while (nr_pages < (size >> PAGE_SHIFT)) {
                void *page;
                unsigned long order;

                page = pop_hyp_memcache(mc, hyp_phys_to_virt, &order);
                /* We only expect 1 page at a time for now. */
                WARN_ON(!page || order);

                ret = __hyp_allocator_map(va, hyp_virt_to_phys(page));
                if (ret) {
                        push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                        break;
                }
                va += PAGE_SIZE;
                nr_pages++;
        }

        if (ret && nr_pages) {
                va -= PAGE_SIZE * nr_pages;
                hyp_allocator_unmap(allocator, va, nr_pages << PAGE_SHIFT);
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

static int chunk_install(struct chunk_hdr *chunk, size_t size,
                         struct chunk_hdr *prev,
                         struct hyp_allocator *allocator)
/*@
    requires
        take Prev_pre = MaybeChunkHdr(prev, !is_null(prev));
        take C_pre = RW<struct chunk_hdr>(chunk);
    ensures
        take Prev_post = MaybeChunkHdr(prev, !is_null(prev));
        take C_post = RW<struct chunk_hdr>(chunk);
        C_post.mapped_size == (
                match Prev_pre {
                        ChunkHdr_none {} => {
                                (u32)PAGE_ALIGN_DOWN(Cn_chunk_size(size))
                        }
                        ChunkHdr_some {hdr: hdr1} => {
                                match Prev_post {
                                        ChunkHdr_none {} => { 0u32 } // unreachable
                                        ChunkHdr_some {hdr: hdr2} => {
                                                (hdr1.mapped_size - hdr2.mapped_size)
                                        }
                                }
                        }
                }
        );
        match (Prev_pre) {
                ChunkHdr_none {} => {
                        true
                }
                ChunkHdr_some {hdr: hdr1} => {
                        match (Prev_post) {
                                ChunkHdr_none {} => {
                                        false
                                }
                                ChunkHdr_some {hdr: hdr2} => {
                                        hash_change_only(hdr1, hdr2) &&
                                        chunk_install_sanity_check(prev, chunk, hdr1) implies (
                                        return == 0i32
                                        && hdr2.mapped_size == (u32)((u64)chunk - (u64)prev)
                                        )
                                }
                        }
                }
        };
        //is_null(prev) || hash_change_only(Prev_pre, Prev_post);
@*/

{
        size_t prev_mapped_size;

        /* First chunk, first allocation */
        if (!prev) {
                INIT_LIST_HEAD(&chunk->node);
                // HK: This program is insane from the perspective of Rust's ownership type system.
                // I thought the `list_add` function would take ownership of both the allocator and the chunk,
                // transferring the chunk's ownership to the allocator.
                // However, even after adding the chunk to the list, the program still manipulates the chunk.
                // Q. What is going to be a good strategy to write the predicate for lists in
                // this case?
                list_add(&chunk->node, &allocator->chunks);
                chunk->mapped_size = PAGE_ALIGN(chunk_size(size));
                chunk->alloc_size = size;

                chunk_hash_update(chunk);

                return 0;
        }

        if (chunk_unmapped_region(prev) < (unsigned long)chunk)
                return -EINVAL;
        if ((unsigned long)chunk_data(prev) + prev->alloc_size > (unsigned long)chunk)
                return -EINVAL;

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

        if (WARN_ON(!prev))
                return -EINVAL;

        /* Can only merge free chunks */
        if (chunk_is_used(chunk) || chunk_is_used(prev))
                return -EBUSY;

        /* Can't merge non-contiguous mapped regions */
        if (chunk_unmapped_region(prev) != (unsigned long)chunk)
                return 0;

        /* mapped region inheritance */
        prev->mapped_size += chunk->mapped_size;

        chunk_list_del(chunk, allocator);

        return 0;
}

static size_t chunk_needs_mapping(struct chunk_hdr *chunk, size_t size)
{
        size_t mapping_missing, mapping_needs = chunk_size(size);

        if (mapping_needs <= chunk->mapped_size)
                return 0;

        mapping_missing = PAGE_ALIGN(mapping_needs - chunk->mapped_size);

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
        unsigned long delta, mapped_end = chunk_unmapped_region(chunk);
        struct chunk_hdr *new_chunk;

        if (PAGE_ALIGNED(mapped_end))
                return 0;

        new_chunk = (struct chunk_hdr *)PAGE_ALIGN_DOWN(mapped_end);
        if ((unsigned long)new_chunk <= (unsigned long)chunk)
                return -EINVAL;

        delta = ((unsigned long)next_chunk - (unsigned long)new_chunk);

        /*
         * This shouldn't happen, chunks are installed to a minimum distance
         * from the page start
         */
        WARN_ON(delta < chunk_size(0UL));

        WARN_ON(chunk_install(new_chunk, 0, chunk, allocator));

        return 0;
}

static int chunk_inc_map(struct chunk_hdr *chunk, size_t map_size,
                         struct hyp_allocator *allocator)
{
        int ret;

        if (chunk_unmapped_size(chunk, allocator) < map_size)
                return -EINVAL;

        ret = hyp_allocator_map(allocator, chunk_unmapped_region(chunk),
                                map_size);
        if (ret)
                return ret;

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

        start = PAGE_ALIGN((unsigned long)chunk +
                           chunk_size(chunk->alloc_size));
        end = chunk_unmapped_region(chunk);

        if (start >= end)
                return 0;

        reclaimable = end - start;
        if (reclaimable < PAGE_SIZE)
                return 0;

        if (chunk_split_aligned(chunk, allocator))
                return 0;

        end = chunk_unmapped_region(chunk);
#ifdef NO_STATEMENT_EXPRS
        reclaimable = min_u64(end - start, reclaim_target);
#else /* NO_STATEMENT_EXPRS */
        reclaimable = min(end - start, reclaim_target);
#endif /* NO_STATEMENT_EXPRS */
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
        unsigned long min_chunk_size = chunk_size(0UL);
        unsigned long page = PAGE_ALIGN_DOWN(addr);
        unsigned long delta = addr - page;

        if (!delta)
                return addr;

        /*
         * To maximize reclaim, a chunk must fit between the page start and this
         * addr.
         */
        if (delta < min_chunk_size)
                return page + min_chunk_size;

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
static bool my_list_is_last(struct chunk_hdr *chunk, struct hyp_allocator *allocator)
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
                C_pre.Node.prev == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post =Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks)) implies return == NULL;
                !Cn_list_is_last(Node, member_shift<struct hyp_allocator>(allocator, chunks))  implies return == next_chunk;
@*/
{
        struct chunk_hdr * next = list_is_last(&(chunk)->node, &(allocator)->chunks) ?
                NULL : list_next_entry(chunk, node);
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
                C_pre.Node.prev == member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take A_post = Cn_hyp_allocator_only(allocator);
                take B_post = Cn_chunk_hdr(chunk, A_post);
                take C_post = Cn_chunk_hdr(next_chunk, A_post);
                A_pre == A_post;
                B_pre == B_post;
                return == (u64)(Hdr.va_size - Hdr.mapped_size);
@*/
{
        struct chunk_hdr *next = chunk_get_next(chunk, allocator);
        //struct chunk_hdr *next = my_chunk_get_next(chunk, allocator);
        unsigned long allocator_end = (allocator)->start + (allocator)->size;
        return next ? (unsigned long)next - chunk_unmapped_region(chunk)
                    : allocator_end - chunk_unmapped_region(chunk);
}

static bool chunk_can_split(struct chunk_hdr *chunk, unsigned long addr,
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
    ensures
        take A_post = Cn_hyp_allocator_only(allocator);
        take C_post = Cn_chunk_hdr(chunk, A_post);
        let chunk_end = (u64)chunk + (u64)C_pre.mapped_size +
                (u64)Cn_chunk_unmapped_size(C_pre);

        Cn_list_is_last(Node, A_post.head)
        implies return == 0u8;
        !Cn_list_is_last(Node, A_post.head)
        implies return == ((Cn_chunk_size(0u64) < chunk_end) ? 1u8 : 0u8);
        // HK: To prove the above, we require an invariant stating that
        // all sizes are less than 2^32 to avoid integer overflow.
@*/
{
        unsigned long chunk_end;

        /*
         * There is no point splitting the last chunk, subsequent allocations
         * would be able to use this space anyway.
         */
        if (list_is_last(&chunk->node, &allocator->chunks))
                return false;

        chunk_end = (unsigned long)chunk + chunk->mapped_size +
                    chunk_unmapped_size(chunk, allocator);

        return addr + chunk_size(0UL) < chunk_end;
}

static int chunk_recycle(struct chunk_hdr *chunk, size_t size,
                         struct hyp_allocator *allocator)
// remaining possible specifications
// -
/*@
    requires
        //take HA_in = Cn_hyp_allocator(allocator);
        take C_pre = Owned<struct chunk_hdr>(chunk);
    ensures
        //take HA_out = Cn_hyp_allocator(allocator);
        take C_post = Owned<struct chunk_hdr>(chunk);
        C_post.alloc_size == (u32)size;
        C_post.mapped_size == C_pre.mapped_size;
        C_post.node == C_pre.node;
        C_post.data == C_pre.data;
        return == 0i32;
        // TODO: write some spec on HA_out and HA_in
@*/
{
        unsigned long new_chunk_addr = (unsigned long)chunk + chunk_size(size);
        size_t missing_map, expected_mapping = size;
        struct chunk_hdr *new_chunk = NULL;
        int ret;

        new_chunk_addr = chunk_addr_fixup(new_chunk_addr);
        if (chunk_can_split(chunk, new_chunk_addr, allocator)) {
                new_chunk = (struct chunk_hdr *)new_chunk_addr;
                expected_mapping = new_chunk_addr + chunk_hdr_size() -
                                        (unsigned long)chunk_data(chunk);
        }
        // TODO: memcache part. We ignore this for now (HK).
        // missing_map = chunk_needs_mapping(chunk, expected_mapping);
        // if (missing_map) {
        //         ret = chunk_inc_map(chunk, missing_map, allocator);
        //         if (ret)
        //                 return ret;
        // }

        chunk->alloc_size = size;
        chunk_hash_update(chunk);

        if (new_chunk)
                WARN_ON(chunk_install(new_chunk, 0, chunk, allocator));

        return 0;
}

static size_t chunk_try_destroy(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator,
                                size_t reclaim_target)
{
        size_t unmapped;

        if (chunk_is_used(chunk))
                return 0;

        /* Don't kill the entire chunk if this is not necessary */
        if (chunk->mapped_size > reclaim_target)
                return 0;

        if (list_is_first(&chunk->node, &allocator->chunks)) {
                /* last standing chunk ? */
                if (!list_is_last(&chunk->node, &allocator->chunks))
                        return 0;

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

        if (!PAGE_ALIGNED((unsigned long)chunk))
                return 0;

        if (list_is_last(&chunk->node, &allocator->chunks))
                goto destroy;

        if (chunk_is_used(chunk_get_prev(chunk, allocator)))
                return 0;

        if (chunk_split_aligned(chunk, allocator))
                return 0;
destroy:
        chunk_list_del(chunk, allocator);
unmap:
        unmapped = chunk->mapped_size;
        hyp_allocator_unmap(allocator, (unsigned long)chunk,
                            chunk->mapped_size);

        return unmapped;
}

static int setup_first_chunk(struct hyp_allocator *allocator, size_t size)
/*@ requires take a_in=Cn_hyp_allocator(allocator);
    a_in.hdrs==Chunk_nil{};
    ensures take a_out=Cn_hyp_allocator(allocator);
@*/
{
        int ret;

        ret = hyp_allocator_map(allocator, allocator->start,
                                PAGE_ALIGN(chunk_size(size)));
        if (ret)
                return ret;

        return chunk_install((struct chunk_hdr *)allocator->start, size, NULL, allocator);
}


static struct chunk_hdr *
get_free_chunk(struct hyp_allocator *allocator, size_t size)
// should the spec of this characterise "best", or just ensure that this returns a legit chunk?  We guess the latter is sufficient for functional correctness and we'll do that
// should the spec of this pull out the ownership of that chunk, or just identify the chunk?  We guess the context will sometimes have to mess with neighbouring chunks, so we'll do the pulling out there, not here
// what variable name to use for the result of Cn_hyp_allocator?
// (should CN support enforced per-type naming conventions?)
/*@
requires  take HA_in = Cn_hyp_allocator(allocator);
ensures   take HA_out = Cn_hyp_allocator(allocator);
HA_out==HA_in;
let hdr_maybe = lookup(return, HA_in.hdrs);
if (ptr_eq(return, NULL)) {
        hdr_maybe == Chunk_none {}
} else {
        match (hdr_maybe) {
                Chunk_none {} => {false}
                Chunk_some {hdr: hdr} => {is_free_chunk(hdr, (u32)size)}
        }
};
// is_free_chunk(ret,size,HA_in.hdrs); // it returns a chunk in the list (or NIL?) st the alloc_size is zero and total size (not just mapped size, and including header size) is at least what you asked for
@*/


{
        struct chunk_hdr *chunk, *best_chunk = NULL;
        size_t best_available_size = allocator->size;

        list_for_each_entry(chunk, &allocator->chunks, node) {
                size_t available_size = chunk->mapped_size +
                                        chunk_unmapped_size(chunk, allocator);
                if (chunk_is_used(chunk))
                        continue;

                if (chunk_size(size) > available_size)
                        continue;

                if (!best_chunk) {
                        best_chunk = chunk;
                        continue;
                }

                if (best_available_size <= available_size)
                        continue;

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

        size = ALIGN(size, MIN_ALLOC);

        hyp_spin_lock(&allocator->lock);
        //PS: ownership from lock invariant
        //PS: hyp_spin_lock returns Cn_hyp_allocator(&allocator)

        if (list_empty(&hyp_allocator.chunks)) {
                ret = setup_first_chunk(allocator, size);
                if (ret)
                        goto end;

                chunk = (struct chunk_hdr *)allocator->start;
                goto end;
        }

        chunk = get_free_chunk(allocator, size);
        if (chunk) {
                ret = chunk_recycle(chunk, size, allocator);
                goto end;
        }

        last_chunk = chunk_get(list_last_entry(&allocator->chunks, struct chunk_hdr, node));

        chunk_addr = (unsigned long)last_chunk + chunk_size(last_chunk->alloc_size);
        chunk_addr = chunk_addr_fixup(chunk_addr);
        chunk = (struct chunk_hdr *)chunk_addr;

        missing_map = chunk_needs_mapping(last_chunk,
                                          chunk_addr + chunk_size(size) -
                                                (unsigned long)chunk_data(last_chunk));
        if (missing_map) {
                ret = chunk_inc_map(last_chunk, missing_map, allocator);
                if (ret)
                        goto end;
        }

        WARN_ON(chunk_install(chunk, size, last_chunk, allocator));
end:
        hyp_spin_unlock(&allocator->lock);

        *(this_cpu_ptr(&hyp_allocator_errno)) = ret;

        /* Enforce zeroing allocated memory */
        if (!ret)
                memset(chunk_data(chunk), 0, size);

        return ret ? NULL : chunk_data(chunk);
}

#ifndef STANDALONE
static size_t hyp_alloc_size(void *addr)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        char *chunk_data = (char *)addr;
        struct chunk_hdr *chunk;
        size_t size;

        hyp_spin_lock(&allocator->lock);
        chunk = chunk_get(container_of(chunk_data, struct chunk_hdr, data));
        size = chunk->alloc_size;
        hyp_spin_unlock(&allocator->lock);

        return size;
}

void *hyp_alloc_account(size_t size, struct kvm *host_kvm)
{
        void *addr = hyp_alloc(size);

        if (addr)
                atomic64_add(hyp_alloc_size(addr),
                             &host_kvm->stat.protected_hyp_mem);
        return addr;
}
#endif /* STANDALONE */

void hyp_free(void *addr)
{
        struct chunk_hdr *chunk, *prev_chunk, *next_chunk;
        struct hyp_allocator *allocator = &hyp_allocator;
        char *chunk_data = (char *)addr;

        hyp_spin_lock(&allocator->lock);

        chunk = chunk_get(container_of(chunk_data, struct chunk_hdr, data));
        prev_chunk = chunk_get_prev(chunk, allocator);
        next_chunk = chunk_get_next(chunk, allocator);

        chunk->alloc_size = 0;
        chunk_hash_update(chunk);

        if (next_chunk && !chunk_is_used(next_chunk))
                WARN_ON(chunk_merge(next_chunk, allocator));

        if (prev_chunk && !chunk_is_used(prev_chunk))
                WARN_ON(chunk_merge(chunk, allocator));

        hyp_spin_unlock(&allocator->lock);
}

#ifndef STANDALONE
void hyp_free_account(void *addr, struct kvm *host_kvm)
{
        size_t size = hyp_alloc_size(addr);

        hyp_free(addr);

        atomic64_sub(size, &host_kvm->stat.protected_hyp_mem);
}
#endif /* STANDALONE */

/*
 * While chunk_try_destroy() is actually destroying what can be, this function
 * only help with estimating how much pages can be reclaimed. However the same
 * comments apply here.
 */
static bool chunk_destroyable(struct chunk_hdr *chunk,
                              struct hyp_allocator *allocator)
{
        if (chunk_is_used(chunk))
                return false;

        if (!PAGE_ALIGNED(chunk))
                return false;

        if (list_is_first(&chunk->node, &allocator->chunks)) {
                if (list_is_last(&chunk->node, &allocator->chunks))
                        return true;

                return false;
        }

        return !chunk_is_used(chunk_get_prev(chunk, allocator));
}

static size_t chunk_reclaimable(struct chunk_hdr *chunk,
                                struct hyp_allocator *allocator)
{
        unsigned long start, end = chunk_unmapped_region(chunk);

        /*
         * This should not happen, chunks are installed at a minimum distance
         * from the page start
         */
        WARN_ON(!PAGE_ALIGNED(end) &&
                (end - PAGE_ALIGN_DOWN(end) < chunk_size(0UL)));

        if (chunk_destroyable(chunk, allocator))
                start = (unsigned long)chunk;
        else
                start = PAGE_ALIGN((unsigned long)chunk + chunk_size(chunk->alloc_size));

        end = PAGE_ALIGN_DOWN(end);
        if (start > end)
                return 0;

        return end - start;
}

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
        list_for_each_entry(chunk, &allocator->chunks, node)
                reclaimable += chunk_reclaimable(chunk, allocator) >> PAGE_SHIFT;

        for (cpu = 0; cpu < hyp_nr_cpus; cpu++) {
                struct kvm_hyp_memcache *mc = per_cpu_ptr(&hyp_allocator_mc, cpu);

                reclaimable += mc->nr_pages;
        }

        hyp_spin_unlock(&allocator->lock);

        return reclaimable;
}

void hyp_alloc_reclaim(struct kvm_hyp_memcache *mc, int target)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        struct kvm_hyp_memcache *alloc_mc;
        struct chunk_hdr *chunk, *tmp;
        int cpu;

        if (target <= 0)
                return;

        hyp_spin_lock(&allocator->lock);

        /* Start emptying potential unused memcache */
        for (cpu = 0; cpu < hyp_nr_cpus; cpu++) {
                alloc_mc = per_cpu_ptr(&hyp_allocator_mc, cpu);

                while (alloc_mc->nr_pages) {
                        unsigned long order;
                        void *page = pop_hyp_memcache(alloc_mc, hyp_phys_to_virt, &order);

                        WARN_ON(order);
                        push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                        WARN_ON(__pkvm_hyp_donate_host(hyp_virt_to_pfn(page), 1));

                        target--;
                        if (target <= 0)
                                goto done;
                }
        }

        list_for_each_entry_safe_reverse(chunk, tmp, &allocator->chunks, node) {
                size_t r;

                chunk_hash_validate(chunk);
                r = chunk_try_destroy(chunk, allocator, target << PAGE_SHIFT);
                if (!r)
                        r = chunk_dec_map(chunk, allocator, target << PAGE_SHIFT);

                target -= r >> PAGE_SHIFT;
                if (target <= 0)
                        break;
        }

        alloc_mc = this_cpu_ptr(&hyp_allocator_mc);
        while (alloc_mc->nr_pages) {
                unsigned long order;
                void *page = pop_hyp_memcache(alloc_mc, hyp_phys_to_virt, &order);

                WARN_ON(order);
                memset(page, 0, PAGE_SIZE);
                kvm_flush_dcache_to_poc(page, PAGE_SIZE);
                push_hyp_memcache(mc, page, hyp_virt_to_phys, 0);
                WARN_ON(__pkvm_hyp_donate_host(hyp_virt_to_pfn(page), 1));
        }
done:
        hyp_spin_unlock(&allocator->lock);
}

int hyp_alloc_refill(struct kvm_hyp_memcache *host_mc)
{
        struct kvm_hyp_memcache *alloc_mc = this_cpu_ptr(&hyp_allocator_mc);

        return refill_memcache(alloc_mc, host_mc->nr_pages + alloc_mc->nr_pages,
                               host_mc);
}

int hyp_alloc_init(size_t size)
{
        struct hyp_allocator *allocator = &hyp_allocator;
        int ret;

        size = PAGE_ALIGN(size);

        /* constrained by chunk_hdr *_size types */
        if (size > U32_MAX)
                return -EINVAL;

        ret = pkvm_alloc_private_va_range(size, &allocator->start);
        if (ret)
                return ret;

        allocator->size = size;
        INIT_LIST_HEAD(&allocator->chunks);
        hyp_spin_lock_init(&allocator->lock);

        return 0;
}

int hyp_alloc_errno(void)
{
        int *errno = this_cpu_ptr(&hyp_allocator_errno);

        return *errno;
}

u8 hyp_alloc_missing_donations(void)
{
        u8 *missing = (this_cpu_ptr(&hyp_allocator_missing_donations));
        u8 __missing = *missing;

        *missing = 0;

        return __missing;
}

#ifndef STANDALONE
struct hyp_mgt_allocator_ops hyp_alloc_ops = {
        .refill = hyp_alloc_refill,
        .reclaim = hyp_alloc_reclaim,
        .reclaimable = hyp_alloc_reclaimable,
};
#else
void dump_chunks(void)
{
#ifndef __cerb__
        int printf(const char *, ...);
        struct hyp_allocator *allocator = &hyp_allocator;
        struct chunk_hdr *chunk;
        u64 i = 0;
        printf("\x1b[33mBEGIN\n");
        list_for_each_entry(chunk, &allocator->chunks, node) {
                printf("  [%"PRIu64"] %p -- &data: %p { .alloc_size: %u, .mapped_size: %u }\n",
                        i++, chunk, chunk_data(chunk), chunk->alloc_size,
                        chunk->mapped_size);
        }
        printf("END\x1b[0m\n");
#endif /* __cerb__ */
}
#endif

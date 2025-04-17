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
#if 0
#include <inttypes.h>

typedef uint8_t         u8;
typedef uint32_t        u32;
typedef uint64_t        u64;

typedef u64             phys_addr_t;

// This is defined in include/linux/types.h
struct list_head {
        struct list_head *next, *prev;
};

// TODO: spinlock
typedef u64             hyp_spinlock_t;

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
        char                    data /* __aligned(8) */;
};
#endif

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
predicate (struct chunk_hdr) Own_chunk(pointer header_address)
{
        take cn_hdr = RW<struct chunk_hdr>(header_address);
        assert(cn_hdr.alloc_size <= cn_hdr.mapped_size);

        // ownership of the mapped but not allocated part of the chunk - as [from...to) in u64 va
        // HK: is this correct?
        // Who owns the memory of [p, p+alloc_size) where p = header_address + sizeof(struct chunk_hdr)?
        //take A = Cn_char_array(array_shift<unsigned char>(header_address, sizeof<struct chunk_hdr> + (u64) hdr.alloc_size), (u64) hdr.mapped_size);
        take A = Cn_char_array(array_shift<unsigned char>(header_address, Cn_chunk_hdr_size()), (u64) cn_hdr.mapped_size - Cn_chunk_hdr_size());

        return cn_hdr;
}
// Cn_chunk_hdr validates the locations of the chunk header and its next are
// in the hyp_allocator's address space
predicate ({cn_chunk_hdr Hdr, struct list_head Node}) Cn_chunk_hdr(pointer header_address, cn_hyp_allocator ha)
{
        take hdr = Own_chunk(header_address);

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
// HK: prev is unused? what is for?
// -> HK: important for sanity check of linked list (e.g. node->next->prev == node)
predicate (datatype cn_chunk_hdrs) Cn_chunk_hdrs(pointer p, pointer prev, cn_hyp_allocator ha,  pointer last)
{
        if (ptr_eq(p,last)) {
                assert(ha.start <= ha.start + (u64)ha.size);
                return Chunk_nil {};
        } else {
                let header_address = array_shift<char>(p, -(offsetof(chunk_hdr, node))); // or some offsetof arithmetic
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                assert(ptr_eq(cn_hdr.Node.prev, prev));
                take tl = Cn_chunk_hdrs(cn_hdr.Node.next, p, ha, last);
                // do we want to use resources to track the va-address-space "ownership" of any unmapped part of va address space between this chunk and the next (or the end)? unclear. pretend not for now
                return Chunk_cons { hd: cn_hdr.Hdr, tl: tl };
        }
}


predicate ({cn_hyp_allocator ha, datatype cn_chunk_hdrs hdrs}) Cn_hyp_allocator( pointer p ) { // p points to a struct hyp_allocator
  take ha = Cn_hyp_allocator_only(p);
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow
  let chunk_ptr = member_shift<struct hyp_allocator>(p, chunks);
  let next_ptr = member_shift<struct list_head>(chunk_ptr, next);
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

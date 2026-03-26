/**
chunk:
| hdr | alloc'd | mapped-but-not-alloc'd | ..maybe unmapped VA part before the start of the next chunk (or the start+size) |

      ^^^^^^^^^^ alloc_size
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  mapped_size
**/

/*@
type_synonym va = u64

type_synonym cn_chunk_hdr = {
  va header_address, // the VA of the start of the chunk_hdr
  u32 alloc_size, // exactly as in the C
  u32 mapped_size,  // exactly as in the C
  u32 va_size      // implicit in the C: the total va space size of this chunk
  // no node, no hash, no data, no ownership here
}

type_synonym cn_hyp_allocator = {
        pointer head,    // used for checking the last chunk
        pointer first,   // used for list walking
        pointer last,    // last chunk
        va start,
        u32 size
}

type_synonym cn_hyp_allocator_core = {
        pointer head,    // used for checking the last chunk
        pointer first,
        va start,
        u32 size
}

function (cn_hyp_allocator_core) Cn_hyp_allocator_core(cn_hyp_allocator ha)
{
        {
                head: ha.head,
                first: ha.first,
                start: ha.start,
                size: ha.size
        }
}

datatype cn_chunk_hdrs {
  Chunk_nil {},
  Chunk_cons { cn_chunk_hdr hd, datatype cn_chunk_hdrs tl }
}

datatype option_u64 {
        Option_u64_none {},
        Option_u64_some { u64 value }
}


predicate [nounfold] void Cn_char_array(pointer p, u64 size)
{
        take U = each(u64 i; 0u64 <= i && i < size){
                W<byte>(array_shift<byte>(p, i))
        };
        return;
}
predicate void Cn_char_array_with_offset(pointer p, u64 size, u64 offset)
{
        take U = each(u64 i; offset <= i && i < offset + size){
                W<byte>(array_shift<byte>(p, i))
        };
        return;
}

predicate void Conditional_Cn_char_array(pointer p, u64 size, boolean cond)
{
        if (cond) {
                take U = Cn_char_array(p, size);
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

predicate void MaybeCn_char_array_with_offset(pointer p, u64 size, u64 offset)
{
        if (ptr_eq(p, NULL)) {
                return;
        } else {
                take U = Cn_char_array_with_offset(p, size, offset);
                return;
        }
}

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
        assert((u64)p > 0u64);
        assert((u64)p + sizeof<struct hyp_allocator> > (u64)p);
        take ha = RW<struct hyp_allocator>(p);
        let cn_hyp = {
                head:  member_shift<struct hyp_allocator>(p, chunks),
                first: ha.chunks.next,
                last:  ha.chunks.prev,
                start: ha.start,
                size:  ha.size
        };
        assert(!is_null(cn_hyp.head));
        assert(!is_null(cn_hyp.first));
        assert(!is_null(cn_hyp.last));
        assert(ha.start < (u64)cn_hyp.start + (u64)cn_hyp.size);
        assert(ha.start > 0u64);
        assert((u64)ha.start & 0x7u64 == 0u64);

        return cn_hyp;
}
@*/

/*@
predicate (cn_chunk_hdr_raw) Own_chunk_hdr(pointer chunk)
{
        assert(!is_null(chunk));
        take alloc_size = RW<unsigned>(member_shift<struct chunk_hdr>(chunk, alloc_size));
        take mapped_size = RW<unsigned>(member_shift<struct chunk_hdr>(chunk, mapped_size));
        take node = RW<struct list_head>(member_shift<struct chunk_hdr>(chunk, node));
        assert((u64)node.next != 0u64);
        assert((u64)node.prev != 0u64);
        assert((u64)chunk & 0x7u64 == 0u64);
        assert((u64)alloc_size & 0x7u64 == 0u64);
        assert(!is_null(node.next));
        assert(!is_null(node.prev));
        take hash = RW<unsigned>(member_shift<struct chunk_hdr>(chunk, hash));
        take explicit_padding = W<unsigned>(member_shift<struct chunk_hdr>(chunk, explicit_padding));
        let cn_hdr = {
                alloc_size: alloc_size,
                mapped_size: mapped_size,
                node: node,
                hash: hash
        };
        return cn_hdr;
}

predicate ({cn_chunk_hdr Hdr, struct list_head Node}) Cn_chunk_hdr_inner(pointer header_address, cn_hyp_allocator_core ha, option_u64 va_size_opt, boolean check_node, option_u64 alloc_size_opt, boolean valid_mapped_size)
{

        assert(!is_null(header_address));
        take hdr = Own_chunk_hdr(header_address);

        let end = ha.start + (u64)ha.size;

        let va_size = match (va_size_opt) {
                Option_u64_none {} => {
                        (Cn_list_is_last(hdr.node, ha.head) ? end : (u64)my_container_of_chunk_hdr(hdr.node.next) ) - (u64)header_address
                }
                Option_u64_some {value: v} => { v }
        };
        let cn_hdr = {
                header_address : (u64) header_address,
                alloc_size : hdr.alloc_size,
                mapped_size : hdr.mapped_size,
                va_size: (u32)va_size
        };

        let valid_chunk = Option_u64_none {} == alloc_size_opt;
        assert((valid_chunk && valid_mapped_size) implies (u64)hdr.alloc_size + Cn_chunk_hdr_size() <= (u64)hdr.mapped_size);
        assert(valid_mapped_size implies cn_hdr.mapped_size <= cn_hdr.va_size);
        assert(valid_chunk implies cn_hdr.va_size <= ha.size);

        let alloc_size = match alloc_size_opt {
                Option_u64_none {} => {
                        (u64)cn_hdr.alloc_size
                }
                Option_u64_some {value: v} => {
                        v
                }
        };
        let start = array_shift<byte>(header_address, Cn_chunk_hdr_size() + alloc_size );
        let size_owned_by_ha = (u64)cn_hdr.va_size -  Cn_chunk_hdr_size() - alloc_size;
        take A = Cn_char_array(start, size_owned_by_ha);

        assert(cn_hdr.header_address >= ha.start);
        let chunk_end = cn_hdr.header_address + (u64) cn_hdr.mapped_size;
        assert(valid_mapped_size implies chunk_end <= end);
        assert(valid_mapped_size implies chunk_end >= cn_hdr.header_address);


        assert(
                check_node implies
                (((u64)member_shift<struct chunk_hdr>(header_address, node) < (u64)hdr.node.next
                    && ha.start <= (u64)hdr.node.next
                    && (u64) hdr.node.next < end)
                || (u64)hdr.node.next == (u64)ha.head)
        );
        assert(
                check_node implies
                (
                ((u64)hdr.node.prev < (u64)member_shift<struct chunk_hdr>(header_address, node)
                    && ha.start <= (u64)hdr.node.prev
                    && (u64) hdr.node.prev < end)
                || (u64)hdr.node.prev == (u64)ha.head)
        );

        return {Hdr: cn_hdr, Node: hdr.node};

}

predicate ({cn_chunk_hdr Hdr, struct list_head Node}) Cn_chunk_hdr(pointer header_address, cn_hyp_allocator_core ha)
{
        take cn_hdr = Cn_chunk_hdr_inner(header_address, ha, Option_u64_none {}, true, Option_u64_none {}, true);
        return cn_hdr;
}

datatype cn_chunk_option {
        Chunk_none {},
        Chunk_some { cn_chunk_hdr hdr, struct list_head node }
}

predicate (datatype cn_chunk_option) Maybe_Cn_chunk_hdr(pointer header_address, cn_hyp_allocator_core ha, boolean condition)
{
        if (condition)
        {
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                return Chunk_some { hdr: cn_hdr.Hdr, node: cn_hdr.Node };
        }
        else
        {
                return Chunk_none {};
        }
}

predicate [rec] (datatype cn_chunk_hdrs) Cn_chunk_hdrs(pointer p, pointer prev,  pointer last_node, cn_hyp_allocator_core ha)
{
        if (ptr_eq(p,ha.head)) {
                assert(ha.start <= ha.start + (u64)ha.size);
                assert(ptr_eq(prev, last_node));
                return Chunk_nil {};
        } else {
                assert(!is_null(p));

                let header_address = array_shift<byte>(p, -(offsetof(chunk_hdr_only, node)) ); // or some offsetof arithmetic
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                assert(ptr_eq(cn_hdr.Node.prev, prev));
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));
                take tl = Cn_chunk_hdrs(cn_hdr.Node.next, p, last_node, ha);

                return Chunk_cons { hd: cn_hdr.Hdr, tl: tl };
        }
}

predicate [rec] (datatype cn_chunk_hdrs) Cn_chunk_hdrs_rev(pointer p, pointer next, pointer first_chunk_node, cn_hyp_allocator_core ha)
{
        if (ptr_eq(p,ha.head)) {
                assert(ha.start <= ha.start + (u64)ha.size);
                assert(ptr_eq(next, first_chunk_node));
                return Chunk_nil {};
        } else {
                assert(!is_null(p));
                let header_address = array_shift<byte>(p, -(offsetof(chunk_hdr_only, node)) ); // or some offsetof arithmetic
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                assert(ptr_eq(cn_hdr.Node.next, next));
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));
                take tl = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, p, first_chunk_node, ha);

                return Chunk_cons { hd: cn_hdr.Hdr, tl: tl };
        }
}

type_synonym cn_lseg = {
        cn_chunk_hdrs before,
        cn_chunk_hdr chunk,
        cn_chunk_hdrs after
}

predicate ({cn_hyp_allocator ha, cn_lseg lseg}) Cn_hyp_allocator_focusing_on( pointer p, pointer chunk) { // p points to a struct hyp_allocator
  take ha_full = Cn_hyp_allocator_only(p);
  let ha = {head: ha_full.head, start: ha_full.start, size: ha_full.size, first: ha_full.first};
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow

  take cn_hdr = Cn_chunk_hdr(chunk, ha);
  assert(!is_null(cn_hdr.Node.next));
  assert(!is_null(cn_hdr.Node.prev));

  let chunk_node = member_shift<struct chunk_hdr_only>(chunk, node);
  take hdrs1 = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, chunk_node, ha_full.first, ha);
  take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha_full.last, ha);
  let lseg = {before: hdrs1, chunk: cn_hdr.Hdr, after: hdrs2};
  return( {ha:ha_full, lseg: lseg} );
}



// chunk_install is a special case for the fundamental invariant for the chunk lists
predicate ({cn_chunk_hdr Hdr, struct list_head Node, u64 va_size}) Cn_chunk_hdr_for_install(pointer header_address, pointer chunk, cn_hyp_allocator_core ha,  option_u64 alloc_size_opt, boolean valid_mapped_size)
{
        let end = ha.start + (u64)ha.size;
        let va_size_1 = (u64)chunk - (u64)header_address;
        take P = Cn_chunk_hdr_inner(header_address, ha, Option_u64_some{value:va_size_1} , true, Option_u64_none{}, valid_mapped_size);

        let next_chunk = (Cn_list_is_last(P.Node, ha.head) ? end : (u64)my_container_of_chunk_hdr(P.Node.next) );
        assert((u64)chunk < next_chunk);
        let va_size_2 =  next_chunk - (u64)chunk;

        return {Hdr: P.Hdr, Node: P.Node, va_size: va_size_2};

}


predicate ({cn_hyp_allocator ha, cn_lseg lseg, u64 va_size}) Cn_hyp_allocator_focusing_on_for_install( pointer p, pointer prev, pointer chunk,  option_u64 alloc_size_opt, boolean valid_mapped_size) {
  take ha_full = Cn_hyp_allocator_only(p);
  let ha = {head: ha_full.head, start: ha_full.start, size: ha_full.size, first: ha_full.first};
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow

  take cn_hdr = Cn_chunk_hdr_for_install(prev, chunk, ha, alloc_size_opt, valid_mapped_size);
  assert(!is_null(cn_hdr.Node.next));
  assert(!is_null(cn_hdr.Node.prev));

  let chunk_node = member_shift<struct chunk_hdr_only>(prev, node);
  take hdrs1 = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, chunk_node, ha_full.first, ha);
  take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha_full.last, ha);
  let lseg = {before: hdrs1, chunk: cn_hdr.Hdr, after: hdrs2};
  return ( {ha:ha_full, lseg:lseg, va_size: cn_hdr.va_size} );

}

predicate (void) FirstAllocation(pointer start, u32 size, boolean cond)
{
        if (cond) {
                take X = Cn_char_array(start, (u64)size);
                return;
        } else {
                return;
        }
}

predicate ({cn_hyp_allocator ha, datatype cn_chunk_hdrs hdrs}) Cn_hyp_allocator( pointer p ) { // p points to a struct hyp_allocator
  take ha_full = Cn_hyp_allocator_only(p);
  let ha = {head: ha_full.head, first: ha_full.first, start: ha_full.start, size: ha_full.size};
  let end = ha.start + (u64)ha.size;
  assert(ha.start < end);  // no overflow
  take hdrs = Cn_chunk_hdrs(ha.first, ha.head, ha_full.last, ha);
  take C = FirstAllocation((pointer)ha.start, ha.size, ptr_eq(ha.first, ha.head));
  return( {ha:ha_full, hdrs:hdrs} );
}

function (boolean) is_free_chunk(cn_chunk_hdr hdr, u64 size)
{
           hdr.alloc_size == 0u32 // i.e., unused
        && (u64) hdr.va_size // the code's available_size
        >= Cn_chunk_size(size)
}
@*/

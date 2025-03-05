/** 
chunk:
| hdr | alloc'd | mapped-but-not-alloc'd | ..maybe unmapped VA part before the start of the next chunk (or the start+size)..?

      ^^^^^^^^^^ alloc_size
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^  mapped_size
**/

type_synonym va = u64
  
type_synonym cn_chunk_hdr = {
  va header_address;/* the VA of the start of the chunk_hdr*/
  u32 alloc_size;   /* exactly as in the C */
  u32 mapped_size;  /* exactly as in the C */
  /* no node, no hash, no data, no ownership here */
}

datatype cn_chunk_hdrs {
  Chunk_nil {};
  Chunk_cons { cn_chunk_hdr hd; datatype cn_chunk_hdrs tl; };
}

/* invoke as cn_chunk_hdrs(ha.chunks.next, &(ha.chunks.next), ha.chunks.prev)*/
predicate Cn_chunk_hdrs( pointer p, pointer prev, pointer last ) {
  if (p==last) 
     { return Chunk_nil {}; }
  else
     { 
     let header_address = container_of(p) /*or some offsetof arithmetic */ in
       take hdr = Owned<struct chunk_hdr>(header_address);
       let cn_hdr = {
         header_address : (va)header_address;
         alloc_size : hdr.alloc_size;
         mapped_size : hdr.mapped_size;
       };
       /* ownership of the mapped but not allocated part of the chunk - as [from...to) in u64 va */
       take _ = Cn_char_array((va)header_address + sizeof(struct chunk_hdr) + hdr.alloc_size, (va)header_address + hdr.mapped_size);
       /* the tail of the list */
       take tl = Cn_chunk_hdrs(hdr.node.next, p, last);
       /* do we want to use resources to track the va-address-space "ownership" of any unmapped part of va address space between this chunk and the next (or the end)? unclear. pretend not for now */
       return Chunk_cons { hd: cn_hdr; tl: tl; };
     }
}

                            
predicate Cn_hyp_allocator( pointer p /* struct hyp_allocator* */) {
  take ha = Owned<struct hyp_allocator>(p);
  take hdrs = Cn_chunk_hdrs(ha.chunks.next, &(ha.chunks.next), ha.chunks.prev);
  /* morally on initialisation this owns all the va space that isn't in the chunks - but we're not currently representing "va ownership" with ownership.  So there is no extra ownership on initialisation - that's all in the memcache */
}

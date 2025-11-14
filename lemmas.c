void LemmaTurnU32sToU64(unsigned *a, unsigned *b)
/*@
requires
    !is_null(a);
    take X = RW<unsigned>(a);
    take Y = RW<unsigned>(b);
    ptr_eq(array_shift<unsigned>(a, 1u32), b);
ensures
    take Z = RW<unsigned long long>(a);
    Z == MergeU32s(X, Y);
@*/
{
    /*@ to_bytes RW<unsigned>(a); @*/
    /*@ to_bytes RW<unsigned>(b); @*/

    /*@ focus RW<byte>, 0u64; @*/
    /*@ focus RW<byte>, 1u64; @*/
    /*@ focus RW<byte>, 2u64; @*/
    /*@ focus RW<byte>, 3u64; @*/
    /*@ focus RW<byte>, 4u64; @*/
    /*@ focus RW<byte>, 5u64; @*/
    /*@ focus RW<byte>, 6u64; @*/
    /*@ focus RW<byte>, 7u64; @*/
    /*@ from_bytes RW<unsigned long long>(a); @*/
}
void LemmaTurnU64ToU32s(unsigned *a, unsigned *b)
/*@
requires
    take Z = RW<unsigned long long>(a);
    ptr_eq(array_shift<unsigned>(a, 1u32), b);
ensures
    take X = RW<unsigned>(a);
    take Y = RW<unsigned>(b);
    Z == MergeU32s(X, Y);
@*/
{
    /*@ to_bytes RW<unsigned long long>(a); @*/

    /*@ focus RW<byte>, 0u64; @*/
    /*@ focus RW<byte>, 1u64; @*/
    /*@ focus RW<byte>, 2u64; @*/
    /*@ focus RW<byte>, 3u64; @*/
    /*@ focus RW<byte>, 4u64; @*/
    /*@ focus RW<byte>, 5u64; @*/
    /*@ focus RW<byte>, 6u64; @*/
    /*@ focus RW<byte>, 7u64; @*/
    /*@ from_bytes RW<unsigned>(a); @*/
    /*@ from_bytes RW<unsigned>(b); @*/
}

void LemmaPtrToU64(struct list_head **a)
/*@
requires
    take P = RW<struct list_head*>(a);
ensures
    take Q = RW<unsigned long long>(a);
    (u64)P == Q;
@*/
{
    /*@ to_bytes RW<struct list_head*>(a); @*/
    /*@ from_bytes RW<unsigned long long>(a); @*/
}

void LemmaU64ToPtr(struct list_head **a)
/*@
requires
    take Q = RW<unsigned long long>(a);
ensures
    take P = RW<struct list_head*>(a);
    (u64)P == Q;
@*/
{
    /*@ to_bytes RW<unsigned long long>(a); @*/
    /*@ from_bytes RW<struct list_head*>(a); @*/
}

void LemmaNextChunk(struct chunk_hdr *chunk,
                    struct hyp_allocator *allocator)
/*@
    requires
        !is_null(chunk);
        take X = Cn_hyp_allocator_focusing_on(allocator, chunk);
        let ha_full = X.ha;
        let ha = {head: ha_full.head, start: ha_full.start, size: ha_full.size, first: ha_full.first};
        let C_pre = X.lseg.chunk;
        X.lseg.after != Chunk_nil{};
        let next = match (X.lseg.after) {
            Chunk_nil {} => {
                // dummy
                {hdr: X.lseg.chunk, tl: Chunk_nil {}}
            }
            Chunk_cons {hd:hdr, tl:tl} => {
                {hdr: hdr, tl: tl}
            }
        };
    ensures
        take Y = Cn_hyp_allocator_focusing_on(allocator, (pointer)next.hdr.header_address);
        Y.lseg.before == Chunk_cons{hd: X.lseg.chunk, tl: X.lseg.before};
        Y.lseg.chunk == next.hdr;
        Y.lseg.after == next.tl;
        Y.ha == X.ha;
@*/
{
    /*@ split_case(ptr_eq(
            member_shift<struct chunk_hdr>(chunk, node),
            member_shift<struct hyp_allocator>(allocator, chunks))); @*/
    /*@ split_case(ptr_eq(
            member_shift<struct chunk_hdr>(chunk, node)->next,
            member_shift<struct hyp_allocator>(allocator, chunks))); @*/
    /*@ split_case(!is_null(member_shift<struct chunk_hdr>(chunk, node)));@*/
    /*@ split_case(!is_null(member_shift<struct chunk_hdr>(chunk, node)->next));@*/
    /*@ unpack Cn_chunk_hdrs(member_shift<struct chunk_hdr>(chunk, node)->next,
            member_shift<struct chunk_hdr>(chunk, node), X.ha.last, ha); @*/
}

void LemmaPrevChunk(struct chunk_hdr *chunk,
                    struct hyp_allocator *allocator)
/*@
    requires
        !is_null(chunk);
        take X = Cn_hyp_allocator_focusing_on(allocator, chunk);
        X.lseg.before != Chunk_nil{};
        let prev = match (X.lseg.before) {
            Chunk_nil {} => {
                // dummy
                {hdr: X.lseg.chunk, tl: Chunk_nil {}}
            }
            Chunk_cons {hd:hdr, tl:tl} => {
                {hdr: hdr, tl: tl}
            }
        };
    ensures
        take Y = Cn_hyp_allocator_focusing_on(allocator, (pointer)prev.hdr.header_address);
        Y.lseg.after == Chunk_cons{hd: X.lseg.chunk, tl: X.lseg.after};
        Y.lseg.chunk == prev.hdr;
        Y.lseg.before == prev.tl;
        Y.ha == X.ha;

@*/
{
    /*@ split_case(ptr_eq(
            member_shift<struct chunk_hdr>(chunk, node),
            member_shift<struct hyp_allocator>(allocator, chunks))); @*/
    /*@ split_case(ptr_eq(
            member_shift<struct chunk_hdr>(chunk, node)->prev,
            member_shift<struct hyp_allocator>(allocator, chunks))); @*/
    /*@ split_case(!is_null(member_shift<struct chunk_hdr>(chunk, node)));@*/
    /*@ split_case(!is_null(member_shift<struct chunk_hdr>(chunk, node)->prev));@*/
    /*@ unpack Cn_chunk_hdrs_rev(member_shift<struct chunk_hdr>(chunk, node)->prev,
            member_shift<struct chunk_hdr>(chunk, node), X.ha.first, Cn_hyp_allocator_core(X.ha)); @*/
}
void LemmaMergeArrays(
    char *p, unsigned long size1, unsigned long size2)
/*@
requires
        let size = size1 + size2;
        let owned_by_ha = array_shift<byte>(p, size1);
        take X1 = Cn_char_array(p, size1);
        take X2 = Cn_char_array(owned_by_ha, size2);
        size1 <= (u64)MAXu32();
        size2 <= (u64)MAXu32();
        size <= (u64)MAXu32();
ensures
        take X = Cn_char_array(p, size);
@*/
{
    /*@
    unpack Cn_char_array(...);
    @*/
    unsigned long i;
    for (i = 0; i < size2; i++)
    /*@
    inv
            take L0 = Cn_char_array(p, size1 + i);
            take L1 = Cn_char_array_with_offset(owned_by_ha, size2 - i, i);
            {p} unchanged;
            {size1} unchanged;
            {size2} unchanged;
            i <= size2;
    @*/
    {
        /*@
          unpack Cn_char_array(...);
          focus W<byte>, i;
          focus W<byte>, (size1 + i);
        @*/
    }
}

void LemmaMergeChunk(char *start, unsigned long size1, unsigned long size2)
/*@
requires
        take X = Cn_char_array(start, size1);
        take Hdr = Own_chunk_hdr(array_shift<char>(start, size1));
        take Y = Cn_char_array(array_shift<char>(start, size1 + Cn_chunk_hdr_size()), size2);
        size1 <= (u64)MAXu32();
        size2 <= (u64)MAXu32();
        let size_all = size1 + size2 + Cn_chunk_hdr_size();
        size_all <= (u64)MAXu32();
ensures
        take X_post = Cn_char_array(start, size_all);
@*/
{
    /*@
    to_bytes W<struct chunk_hdr_only>(array_shift<char>(start, size1));
    @*/
    LemmaMergeArrays(start, size1, chunk_hdr_size());
    LemmaMergeArrays(start, size1 + chunk_hdr_size(), size2);
}
void LemmaSplitAndNewChunk(
    char *p, unsigned int size1, unsigned int size2)
/*@
requires
        let size = (u64)size1 + (u64)size2;
        take X = Cn_char_array(p, size);
        let owned_by_ha = array_shift<byte>(p, (u64)size1);
ensures
        take X1 = Cn_char_array(p, (u64)size1);
        take X2 = Cn_char_array(owned_by_ha, (u64)size2);
@*/
{
    /*@
    unpack Cn_char_array(p, (u64)size1 + (u64)size2);
    @*/
    unsigned long i;
    for (i = 0; i < (unsigned long)size2; i++)
    /*@
    inv
            take L0 = Cn_char_array(p, (u64)size1);
            take L1 = Cn_char_array_with_offset(p, (u64)size2 - i, (u64)size1 + (u64)i);
            take L2 = Cn_char_array(owned_by_ha, i);
            {p} unchanged;
            {size1} unchanged;
            {size2} unchanged;
            i <= (u64)size2;
    @*/
    {
        /*@
          unpack Cn_char_array(owned_by_ha, i);
          focus W<byte>, i;
          focus W<byte>, ((u64)size1 + i);
        @*/
    }
}

void LemmaCreateChunkHdr(char *chunk_data)
/*@
    requires
        !is_null(chunk_data);
        take X = Cn_char_array(chunk_data, Cn_chunk_hdr_size());
        let p = chunk_data;
    ensures
        take Y = W<struct chunk_hdr_only>(p);
@*/
{
    /*@ unpack Cn_char_array(chunk_data, Cn_chunk_hdr_size()); @*/
    /*@
    from_bytes W<struct chunk_hdr_only>(chunk_data);
    @*/
}

void LemmaCreateNewChunkAux(char *chunk_data, size_t size1, size_t size, size_t size2)
/*@
requires
    !is_null(chunk_data);
    // no overflow
    size1 <= (u64)MAXu32();
    size <=  (u64)MAXu32();
    size2 <= (u64)MAXu32();
    let size_all = size1 + size + size2 + Cn_chunk_hdr_size();
    size_all <= (u64)MAXu32();
    take C_pre = Cn_char_array(chunk_data, size_all);

    let chunk_hdr = array_shift<byte>(chunk_data, size1);
    let chunk = array_shift<byte>(chunk_data, size1 + Cn_chunk_hdr_size());
    let remaining = array_shift<byte>(chunk_data, size1 + size + Cn_chunk_hdr_size());
ensures
    take C1 = Cn_char_array(chunk_data, size1);
    take chunk_hdr_only_u = W<struct chunk_hdr_only>(chunk_hdr);
    take C2 = Cn_char_array(chunk, size);
    take C3 = Cn_char_array(remaining, size2);
@*/
{
    /*
            +---------------------------+  ← chunk_data
            |          size1            |
            +---------------------------+  ← chunk_hdr
            |        chunk_hdr          |
            +---------------------------+  ← chunk
            |           size            |
            +---------------------------+  ← remaining
            |          size2            |
            +---------------------------+  ← end
    */

    /*@ unpack Cn_char_array(chunk_data, size_all); @*/

    size_t size_all = size1 + size + size2 + chunk_hdr_size();
    char *chunk_hdr = chunk_data + size1;
    char *chunk = (char *)chunk_hdr + chunk_hdr_size();
    char *remaining = chunk + size;
    LemmaSplitAndNewChunk(chunk_data, size1, size_all - size1);
    size_all -= size1;
    LemmaSplitAndNewChunk(chunk_hdr, chunk_hdr_size(), size_all - chunk_hdr_size());
    size_all -= chunk_hdr_size();
    LemmaSplitAndNewChunk(chunk, size, size_all - size);

    /*@ unpack Cn_char_array(...); @*/
    /*@ from_bytes W<struct chunk_hdr_only>(chunk_hdr); @*/
    /*@ unpack Cn_char_array(...); @*/
}

void LemmaCreateNewChunk(struct chunk_hdr *chunk, size_t size,
                         struct chunk_hdr *prev,
                         struct hyp_allocator *allocator)
/*@
requires
        !is_null(prev);
        take HA_pre = Cn_hyp_allocator_focusing_on(allocator, prev);
        let P_pre = HA_pre.lseg.chunk;


        let allocator_end = (u64)HA_pre.ha.start + (u64)HA_pre.ha.size;
        HA_pre.ha.start <= (u64)prev && (u64)prev < allocator_end;

        // order
        // (i) prev <= prev_alloc_end
        // (ii)      <= chunk
        // (iii)     <= chunk_alloc_end
        // (iv)      <= prev_old_mapped_size
        // (v)       <= prev old_va_size
        // (vi)      <= allocator_end
        let prev_alloc_end = (u64)prev + (u64)P_pre.alloc_size + Cn_chunk_hdr_size();
        let chunk_alloc_end = (u64)chunk + size + Cn_chunk_hdr_size();
        let prev_old_mapped_size = (u64)prev + (u64)P_pre.mapped_size;
        let prev_old_va_size = (u64)prev + (u64)P_pre.va_size;
        (u64)prev <= (u64)prev + Cn_chunk_hdr_size(); // (i)
        (u64)prev + Cn_chunk_hdr_size() <= prev_alloc_end; // (i')
        prev_alloc_end <= (u64)chunk; // (ii)
        (u64)chunk < (u64)chunk + Cn_chunk_hdr_size(); // (iii')
        (u64)chunk + Cn_chunk_hdr_size() <= chunk_alloc_end; // (iii'')
        chunk_alloc_end <= prev_old_mapped_size; // (iv)
        prev_old_mapped_size <= prev_old_va_size; // (v)
        prev_old_va_size <= allocator_end; // (vi)
ensures
        take HA_post = Cn_hyp_allocator_focusing_on_for_install(allocator, prev, chunk, Option_u64_some{value: (u64)size}, false);
        HA_post.ha == HA_pre.ha;
        HA_post.lseg.before == HA_pre.lseg.before;
        HA_post.lseg.after == HA_pre.lseg.after;
        HA_post.lseg.chunk.header_address == HA_pre.lseg.chunk.header_address;
        HA_post.lseg.chunk.mapped_size == HA_pre.lseg.chunk.mapped_size;
        HA_post.lseg.chunk.alloc_size == HA_pre.lseg.chunk.alloc_size;
        (u64)HA_post.lseg.chunk.va_size + (u64)HA_post.va_size == (u64)HA_pre.lseg.chunk.va_size;

         take chunk_hdr_only_u = W<struct chunk_hdr_only>(chunk);
        take X = Cn_char_array(array_shift<byte>(chunk, Cn_chunk_hdr_size() + (u64)size), (u64)HA_post.va_size - (u64)size - Cn_chunk_hdr_size());


        take V = Cn_char_array(array_shift<byte>(chunk, Cn_chunk_hdr_size()), (u64)size);
@*/
{
    /*@
            split_case(ptr_eq(
                    member_shift<struct chunk_hdr>(prev, node)->next,
                    member_shift<struct hyp_allocator>(allocator, chunks)));
    @*/
    /*@ unpack Cn_chunk_hdrs(member_shift<struct chunk_hdr>(prev, node)->next,
            member_shift<struct chunk_hdr>(prev, node), HA_pre.ha.last, Cn_hyp_allocator_core(HA_pre.ha));
    @*/
    unsigned long chunk_end = (unsigned long)prev + prev->mapped_size +
                              chunk_unmapped_size(prev, allocator);
    size_t size_1 = (u64)chunk - (u64)prev - chunk_hdr_size() - prev->alloc_size;
    size_t size_2 = chunk_end - (u64)chunk - chunk_hdr_size() - size;
    LemmaCreateNewChunkAux((char *)chunk_data(prev) + prev->alloc_size, size_1, size, size_2);
    /*@ unpack MaybeChunkHdr(...); @*/
}
/*@
// This is for get_free_chunk
predicate [rec] (datatype cn_chunk_hdrs) Cn_chunk_hdrs_rev_alt(pointer p, pointer next, pointer first_chunk_node, cn_hyp_allocator_core ha, pointer head)
{
        if (ptr_eq(p,head)) {
                assert(ha.start <= ha.start + (u64)ha.size);
                assert(ptr_eq(next, first_chunk_node));
                return Chunk_nil {};
        } else {
                assert(!is_null(p));
                let header_address = array_shift<char>(p, -(offsetof(chunk_hdr_only, node)) ); // or some offsetof arithmetic
                take cn_hdr = Cn_chunk_hdr(header_address, ha);
                assert(ptr_eq(cn_hdr.Node.next, next));
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));
                take tl = Cn_chunk_hdrs_rev_alt(cn_hdr.Node.prev, p, first_chunk_node, ha, head);

                return Chunk_cons { hd: cn_hdr.Hdr, tl: tl };
        }
}

predicate ({cn_hyp_allocator ha, cn_chunk_hdr best_chunk, struct list_head node}) LemmaCnChunkHdrsRevToCnChunkHdrsInv(pointer allocator, pointer chunk, pointer best_chunk)
{
    if (ptr_eq(member_shift<struct chunk_hdr>(chunk, node), member_shift<struct chunk_hdr>(best_chunk, node))) {
        take ha = Cn_hyp_allocator_only(allocator);
        let ha_core = Cn_hyp_allocator_core(ha);
        take BestChunk = Cn_chunk_hdr(best_chunk, ha_core);
        assert(!is_null(BestChunk.Node.next));
        assert(!is_null(BestChunk.Node.prev));
        let best_chunk_node = member_shift<struct chunk_hdr>(best_chunk, node);
        take hdrs2_post = Cn_chunk_hdrs(BestChunk.Node.next, best_chunk_node, ha.last, ha_core);
        return {ha: ha, best_chunk: BestChunk.Hdr, node: BestChunk.Node};
    }
    else
    {
        take ha = Cn_hyp_allocator_only(allocator);
        let ha_core = Cn_hyp_allocator_core(ha);

        take BestChunk = Cn_chunk_hdr(best_chunk, ha_core);
        assert(!is_null(BestChunk.Node.next));
        assert(!is_null(BestChunk.Node.prev));
        let best_chunk_node = member_shift<struct chunk_hdr>(best_chunk, node);

        take cn_hdr = Cn_chunk_hdr(chunk, ha_core);
        assert(!is_null(cn_hdr.Node.next));
        assert(!is_null(cn_hdr.Node.prev));

        let chunk_node = member_shift<struct chunk_hdr>(chunk, node);
        take hdrs1 = Cn_chunk_hdrs_rev_alt(cn_hdr.Node.prev, chunk_node, BestChunk.Node.next, ha_core, best_chunk_node);
        take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha.last, ha_core);
        return {ha: ha, best_chunk: BestChunk.Hdr, node: BestChunk.Node};
    }
}
@*/

void LemmaCnChunkHdrsRevToCnChunkHdrs(struct hyp_allocator *allocator, struct chunk_hdr *best_chunk)
/*@
        requires
                take ha = Cn_hyp_allocator_only(allocator);
                let ha_core = Cn_hyp_allocator_core(ha);

                take BestChunk = Cn_chunk_hdr(best_chunk, ha_core);
                !is_null(BestChunk.Node.next);
                !is_null(BestChunk.Node.prev);

                let best_chunk_node = member_shift<struct chunk_hdr>(best_chunk, node);

                take hdrs2 = Cn_chunk_hdrs_rev_alt(ha.last, ha_core.head, BestChunk.Node.next, ha_core, best_chunk_node);
        ensures
                take ha2 = Cn_hyp_allocator_only(allocator);
                ha == ha2;

                take BestChunk2 = Cn_chunk_hdr(best_chunk, ha_core);
                !is_null(BestChunk.Node.next);
                !is_null(BestChunk.Node.prev);

                BestChunk == BestChunk2;
                take hdrs2_post = Cn_chunk_hdrs(BestChunk.Node.next, best_chunk_node, ha.last, ha_core);

@*/
{
        /*@ split_case(ptr_eq(ha.last, best_chunk_node)); @*/
        /*@ unpack Cn_chunk_hdrs_rev_alt(...); @*/
        struct chunk_hdr *chunk;

        for (chunk = list_last_entry(&allocator->chunks, struct chunk_hdr, node);
             &chunk->node != &best_chunk->node;
             chunk = list_prev_entry(chunk, node))
        /*@ inv {allocator} unchanged;
                {best_chunk} unchanged;
                take Inv = LemmaCnChunkHdrsRevToCnChunkHdrsInv(allocator, chunk, best_chunk);
                ha == Inv.ha;
                BestChunk.Hdr == Inv.best_chunk;
                BestChunk.Node == Inv.node;
        @*/
        {
                /*@
		unpack LemmaCnChunkHdrsRevToCnChunkHdrsInv(...);
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev,
                                member_shift<struct chunk_hdr>(best_chunk, node)
                        )
                );
                unpack Cn_chunk_hdrs_rev_alt(...);
                @*/
                /*@
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev->prev,
                                member_shift<struct chunk_hdr>(best_chunk, node)
                        )
                );
                @*/
                if (chunk->node.prev != &best_chunk->node)
                {
                        /*@
                        unpack Cn_chunk_hdrs_rev_alt(...);
                        @*/
                }
        }
	/*@ unpack LemmaCnChunkHdrsRevToCnChunkHdrsInv(...); @*/



}
/*@
predicate (cn_hyp_allocator) LemmaCnChunkHdrsRevToCnHypAllocatorInv(pointer allocator, pointer chunk)
{
        if (ptr_eq(member_shift<struct chunk_hdr>(chunk, node), member_shift<struct hyp_allocator>(allocator, chunks))) {
                take ha = Cn_hyp_allocator_only(allocator);
                let ha_core = Cn_hyp_allocator_core(ha);
                take hdrs2 = Cn_chunk_hdrs(ha.first, ha.head, ha.last, ha_core);
                return ha;
        }
        else
        {
                take ha = Cn_hyp_allocator_only(allocator);
                let ha_core = Cn_hyp_allocator_core(ha);
                take cn_hdr = Cn_chunk_hdr(chunk, ha_core);
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));

                let chunk_node = member_shift<struct chunk_hdr>(chunk, node);
                take hdrs1 = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, chunk_node, ha.first, ha_core);
                take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha.last, ha_core);
                return ha;
        }
}

@*/
void LemmaCnChunkHdrsRevToCnHypAllocator(struct hyp_allocator *allocator)
/*@
    requires
        take ha = Cn_hyp_allocator_only(allocator);
        let ha_core = Cn_hyp_allocator_core(ha);
        take hdrs1 = Cn_chunk_hdrs_rev(ha.last, ha.head, ha.first, ha_core);
    ensures
        take ha2 = Cn_hyp_allocator_only(allocator);
        take hdrs2 = Cn_chunk_hdrs(ha.first, ha.head, ha.last, ha_core);
        ha == ha2;
@*/
{
        /*@ split_case(ptr_eq(ha.last, ha.head)); @*/
        /*@ unpack  Cn_chunk_hdrs_rev(...); @*/
        struct chunk_hdr *chunk;

        for (chunk = list_last_entry(&allocator->chunks, struct chunk_hdr, node);
             !list_entry_is_head(chunk, &allocator->chunks, node);
             chunk = list_prev_entry(chunk, node))
        /*@ inv {allocator} unchanged;
                take Inv = LemmaCnChunkHdrsRevToCnHypAllocatorInv(allocator, chunk);
                ha == Inv;
        @*/
        {
                /*@
		unpack LemmaCnChunkHdrsRevToCnHypAllocatorInv(...);
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );
                unpack Cn_chunk_hdrs_rev(...);
                @*/
                /*@
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev->prev,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );
                @*/
                if (!list_entry_is_head(list_prev_entry(chunk, node), &allocator->chunks, node))
                {
                        /*@
                        unpack Cn_chunk_hdrs_rev(...);
                        @*/
                }
        }
	/*@ unpack LemmaCnChunkHdrsRevToCnHypAllocatorInv(...); @*/
}

void LemmaConcatCnChunkHdrsRev(struct hyp_allocator *allocator, struct chunk_hdr *chunk, struct chunk_hdr *best_chunk)
/*@
        requires
                take ha = Cn_hyp_allocator_only(allocator);
                let ha_core = Cn_hyp_allocator_core(ha);

                take BestChunk = Cn_chunk_hdr(best_chunk, ha_core);
                !is_null(BestChunk.Node.next);
                !is_null(BestChunk.Node.prev);

                take Chunk = Cn_chunk_hdr(chunk, ha_core);
                !is_null(Chunk.Node.next);
                !is_null(Chunk.Node.prev);

                let best_chunk_node = member_shift<struct chunk_hdr>(best_chunk, node);
                let chunk_node = member_shift<struct chunk_hdr>(chunk, node);

                take hdrs1 = Cn_chunk_hdrs_rev(BestChunk.Node.prev, best_chunk_node, ha.first, ha_core);
                // a bit hack? set the last chunk to chunk_node
                take hdrs2 = Cn_chunk_hdrs_rev_alt(Chunk.Node.prev, chunk_node, BestChunk.Node.next, ha_core, best_chunk_node);
        ensures
                take ha2 = Cn_hyp_allocator_only(allocator);
                ha == ha2;

                take Chunk2 = Cn_chunk_hdr(chunk, ha_core);
                Chunk == Chunk2;

                take hdrs3 = Cn_chunk_hdrs_rev(Chunk.Node.prev, chunk_node, ha.first, ha_core);

@*/
{
        /*@
        split_case(ptr_eq(Chunk.Node.prev, best_chunk_node));
        unpack Cn_chunk_hdrs_rev_alt(Chunk.Node.prev, chunk_node, BestChunk.Node.next, ha_core, best_chunk_node);
        @*/
        if (chunk->node.prev == &best_chunk->node)
        {
                return;
        } else {
                chunk = list_prev_entry(chunk, node);
                LemmaConcatCnChunkHdrsRev(allocator, chunk, best_chunk);
                return;
        }
}

/*@
predicate (cn_hyp_allocator) LemmaLsegToChunkHdrsInv(pointer chunk, pointer allocator)
{
        if (ptr_eq(member_shift<struct chunk_hdr>(chunk, node), member_shift<struct hyp_allocator>(allocator, chunks))) {
                take C2 = Cn_hyp_allocator(allocator);
                return C2.ha;
        }
        else
        {
                take ha = Cn_hyp_allocator_only(allocator);
                let ha_core = Cn_hyp_allocator_core(ha);
                take cn_hdr = Cn_chunk_hdr(chunk, ha_core);
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));

                let chunk_node = member_shift<struct chunk_hdr>(chunk, node);
                take hdrs1 = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, chunk_node, ha.first, ha_core);
                take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha.last, ha_core);
                return ha;
        }
}
@*/

void LemmaLsegToChunkHdrs(struct hyp_allocator *allocator, struct chunk_hdr *chunk)
/*@
        requires
                take C = Cn_hyp_allocator_focusing_on(allocator, chunk);
                let ha_full = C.ha;
                let ha = Cn_hyp_allocator_core(ha_full);
                let node = member_shift<struct chunk_hdr>(chunk, node);
        ensures
                take C2 = Cn_hyp_allocator(allocator);
                C.ha == C2.ha;
@*/
{
        /*@
        split_case(ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->next, ha.head));
        unpack Cn_chunk_hdrs(member_shift<struct chunk_hdr>(chunk, node)->next, node, ha_full.last, Cn_hyp_allocator_core(ha_full));
        split_case(ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev, ha.head));
        unpack Cn_chunk_hdrs_rev(member_shift<struct chunk_hdr>(chunk, node)->prev, node, ha_full.first, Cn_hyp_allocator_core(ha_full));
        @*/

        while (!list_entry_is_head(chunk, &allocator->chunks, node))
        /*@ inv {allocator} unchanged;
                take Inv = LemmaLsegToChunkHdrsInv(chunk, allocator);
                Inv == ha_full;

        @*/
        {
                /*@
		unpack LemmaLsegToChunkHdrsInv(...);
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );
                unpack Cn_chunk_hdrs_rev(...);
                @*/
                chunk = list_prev_entry(chunk, node);
                /*@
                split_case(ptr_eq(member_shift<struct chunk_hdr>(chunk, node), ha.head));

                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->next,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );

                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->prev,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );@*/
                if (!list_entry_is_head(chunk, &allocator->chunks, node))
                {
                        /*@
                        unpack Cn_chunk_hdrs_rev(...);
                        @*/
                }
        }
        /*@
	unpack LemmaLsegToChunkHdrsInv(...);
        split_case(
                ptr_eq(member_shift<struct hyp_allocator>(allocator, chunks)->next,
                        member_shift<struct hyp_allocator>(allocator, chunks)
                )
        );
        @*/
}


/*@
predicate void LemmaGetLastChunkInv(pointer chunk, cn_hyp_allocator ha)
{
        if (ptr_eq(member_shift<struct chunk_hdr>(chunk, node),
                ha.head)) {
                let ha_core = Cn_hyp_allocator_core(ha);
                take hdrs = Cn_chunk_hdrs_rev(ha.last, ha.head, ha.first, ha_core);
                return;
        } else {
                let ha_core = Cn_hyp_allocator_core(ha);
                take cn_hdr = Cn_chunk_hdr(chunk, ha_core);
                assert(!is_null(cn_hdr.Node.next));
                assert(!is_null(cn_hdr.Node.prev));

                let chunk_node = member_shift<struct chunk_hdr>(chunk, node);
                take hdrs1 = Cn_chunk_hdrs_rev(cn_hdr.Node.prev, chunk_node, ha.first, ha_core);
                take hdrs2 = Cn_chunk_hdrs(cn_hdr.Node.next, chunk_node, ha.last, ha_core);
                return;
        }
}
@*/

void LemmaGetLastChunk(struct hyp_allocator *allocator)
/*@
        requires
                take C = Cn_hyp_allocator(allocator);
                !ptr_eq(C.ha.first, C.ha.head);
                let ha_full = C.ha;
                let ha = {head: ha_full.head, start: ha_full.start, size: ha_full.size, first: ha_full.first};
        ensures
                let last = array_shift<char>(C.ha.last, -offsetof(chunk_hdr, node));
                take C2 = Cn_hyp_allocator_focusing_on(allocator, last);
                C2.ha == C.ha;
@*/
{
        /*@ unpack Cn_chunk_hdrs(...); @*/
        struct chunk_hdr *chunk;
        /*@ unpack FirstAllocation(...); @*/

        list_for_each_entry(chunk, &allocator->chunks, node)
        /*@ inv {allocator} unchanged;
                take ha_full_inv = Cn_hyp_allocator_only(allocator);
                let ha_inv = {head: ha_full.head, start: ha_full.start, size: ha_full.size, first: ha_full.first};
                ha_full_inv == ha_full;
                take Inv = LemmaGetLastChunkInv(chunk, ha_full_inv);
        @*/
        {
                /*@
		unpack LemmaGetLastChunkInv(...);
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->next,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );
                unpack Cn_chunk_hdrs(...);
                @*/
                /*@
                split_case(
                        ptr_eq(member_shift<struct chunk_hdr>(chunk, node)->next->next,
                                member_shift<struct hyp_allocator>(allocator, chunks)
                        )
                );
                @*/
                if (!list_entry_is_head(list_next_entry(chunk, node), &allocator->chunks, node))
                {
                        /*@ unpack Cn_chunk_hdrs(...); @*/
                }
        }
        /*@
        split_case(
                ptr_eq(member_shift<struct hyp_allocator>(allocator, chunks)->prev,
                        member_shift<struct hyp_allocator>(allocator, chunks)
                )
        );
	unpack LemmaGetLastChunkInv(...);
        unpack Cn_chunk_hdrs_rev(...);
        split_case(
                ptr_eq(member_shift<struct hyp_allocator>(allocator, chunks)->next,
                        member_shift<struct hyp_allocator>(allocator, chunks)
                )
        );
        unpack Cn_chunk_hdrs(...);
        @*/
}
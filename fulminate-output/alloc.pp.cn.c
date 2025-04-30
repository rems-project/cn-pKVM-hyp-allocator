#include "alloc.pp.cn.h"
cn_bool* struct_Cn_chunk_hdr_record_equality(void* x, void* y)
{
  struct Cn_chunk_hdr_record* x_cast = (struct Cn_chunk_hdr_record*) x;
  struct Cn_chunk_hdr_record* y_cast = (struct Cn_chunk_hdr_record*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_a_9481_record_equality(x_cast->Hdr, y_cast->Hdr)), struct_list_head_cn_equality(x_cast->Node, y_cast->Node));
}

cn_bool* struct_a_9487_record_equality(void* x, void* y)
{
  struct a_9487_record* x_cast = (struct a_9487_record*) x;
  struct a_9487_record* y_cast = (struct a_9487_record*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_cn_chunk_hdrs_equality(x_cast->after, y_cast->after)), struct_cn_chunk_hdrs_equality(x_cast->before, y_cast->before)), struct_a_9481_record_equality(x_cast->chunk, y_cast->chunk));
}

cn_bool* struct_a_9481_record_equality(void* x, void* y)
{
  struct a_9481_record* x_cast = (struct a_9481_record*) x;
  struct a_9481_record* y_cast = (struct a_9481_record*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_u32_equality(x_cast->alloc_size, y_cast->alloc_size)), cn_bits_u64_equality(x_cast->header_address, y_cast->header_address)), cn_bits_u32_equality(x_cast->mapped_size, y_cast->mapped_size)), cn_bits_u32_equality(x_cast->va_size, y_cast->va_size));
}

cn_bool* struct_Cn_hyp_allocator_only_record_equality(void* x, void* y)
{
  struct Cn_hyp_allocator_only_record* x_cast = (struct Cn_hyp_allocator_only_record*) x;
  struct Cn_hyp_allocator_only_record* y_cast = (struct Cn_hyp_allocator_only_record*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_pointer_equality(x_cast->first, y_cast->first)), cn_pointer_equality(x_cast->head, y_cast->head)), cn_pointer_equality(x_cast->last, y_cast->last)), cn_bits_u32_equality(x_cast->size, y_cast->size)), cn_bits_u64_equality(x_cast->start, y_cast->start));
}

cn_bool* struct_Cn_hyp_allocator_record_equality(void* x, void* y)
{
  struct Cn_hyp_allocator_record* x_cast = (struct Cn_hyp_allocator_record*) x;
  struct Cn_hyp_allocator_record* y_cast = (struct Cn_hyp_allocator_record*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_Cn_hyp_allocator_only_record_equality(x_cast->ha, y_cast->ha)), struct_cn_chunk_hdrs_equality(x_cast->hdrs, y_cast->hdrs));
}

cn_bool* struct_Cn_hyp_allocator_focusing_on_record_equality(void* x, void* y)
{
  struct Cn_hyp_allocator_focusing_on_record* x_cast = (struct Cn_hyp_allocator_focusing_on_record*) x;
  struct Cn_hyp_allocator_focusing_on_record* y_cast = (struct Cn_hyp_allocator_focusing_on_record*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_Cn_hyp_allocator_only_record_equality(x_cast->ha, y_cast->ha)), struct_a_9487_record_equality(x_cast->lseg, y_cast->lseg));
}

cn_bool* struct_Cn_chunk_hdrs_non_last_record_equality(void* x, void* y)
{
  struct Cn_chunk_hdrs_non_last_record* x_cast = (struct Cn_chunk_hdrs_non_last_record*) x;
  struct Cn_chunk_hdrs_non_last_record* y_cast = (struct Cn_chunk_hdrs_non_last_record*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_a_9481_record_equality(x_cast->hd, y_cast->hd)), struct_cn_chunk_hdrs_equality(x_cast->tl, y_cast->tl));
}

struct Cn_chunk_hdr_record* default_struct_Cn_chunk_hdr_record()
{
  struct Cn_chunk_hdr_record* a_13944 = (struct Cn_chunk_hdr_record*) cn_bump_malloc(sizeof(struct Cn_chunk_hdr_record));
  a_13944->Hdr = default_struct_a_9481_record();
  a_13944->Node = default_struct_list_head_cn();
  return a_13944;
}

struct a_9487_record* default_struct_a_9487_record()
{
  struct a_9487_record* a_13950 = (struct a_9487_record*) cn_bump_malloc(sizeof(struct a_9487_record));
  a_13950->after = default_struct_cn_chunk_hdrs();
  a_13950->before = default_struct_cn_chunk_hdrs();
  a_13950->chunk = default_struct_a_9481_record();
  return a_13950;
}

struct a_9481_record* default_struct_a_9481_record()
{
  struct a_9481_record* a_13957 = (struct a_9481_record*) cn_bump_malloc(sizeof(struct a_9481_record));
  a_13957->alloc_size = default_cn_bits_u32();
  a_13957->header_address = default_cn_bits_u64();
  a_13957->mapped_size = default_cn_bits_u32();
  a_13957->va_size = default_cn_bits_u32();
  return a_13957;
}

struct Cn_hyp_allocator_only_record* default_struct_Cn_hyp_allocator_only_record()
{
  struct Cn_hyp_allocator_only_record* a_13967 = (struct Cn_hyp_allocator_only_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_only_record));
  a_13967->first = default_cn_pointer();
  a_13967->head = default_cn_pointer();
  a_13967->last = default_cn_pointer();
  a_13967->size = default_cn_bits_u32();
  a_13967->start = default_cn_bits_u64();
  return a_13967;
}

struct Cn_hyp_allocator_record* default_struct_Cn_hyp_allocator_record()
{
  struct Cn_hyp_allocator_record* a_13979 = (struct Cn_hyp_allocator_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_record));
  a_13979->ha = default_struct_Cn_hyp_allocator_only_record();
  a_13979->hdrs = default_struct_cn_chunk_hdrs();
  return a_13979;
}

struct Cn_hyp_allocator_focusing_on_record* default_struct_Cn_hyp_allocator_focusing_on_record()
{
  struct Cn_hyp_allocator_focusing_on_record* a_13984 = (struct Cn_hyp_allocator_focusing_on_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_focusing_on_record));
  a_13984->ha = default_struct_Cn_hyp_allocator_only_record();
  a_13984->lseg = default_struct_a_9487_record();
  return a_13984;
}

struct Cn_chunk_hdrs_non_last_record* default_struct_Cn_chunk_hdrs_non_last_record()
{
  struct Cn_chunk_hdrs_non_last_record* a_13988 = (struct Cn_chunk_hdrs_non_last_record*) cn_bump_malloc(sizeof(struct Cn_chunk_hdrs_non_last_record));
  a_13988->hd = default_struct_a_9481_record();
  a_13988->tl = default_struct_cn_chunk_hdrs();
  return a_13988;
}

void* cn_map_get_struct_Cn_chunk_hdr_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Cn_chunk_hdr_record();
  else
    return ret;
}

void* cn_map_get_struct_a_9487_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_a_9487_record();
  else
    return ret;
}

void* cn_map_get_struct_a_9481_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_a_9481_record();
  else
    return ret;
}

void* cn_map_get_struct_Cn_hyp_allocator_only_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Cn_hyp_allocator_only_record();
  else
    return ret;
}

void* cn_map_get_struct_Cn_hyp_allocator_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Cn_hyp_allocator_record();
  else
    return ret;
}

void* cn_map_get_struct_Cn_hyp_allocator_focusing_on_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Cn_hyp_allocator_focusing_on_record();
  else
    return ret;
}

void* cn_map_get_struct_Cn_chunk_hdrs_non_last_record(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_Cn_chunk_hdrs_non_last_record();
  else
    return ret;
}

/* GENERATED STRUCT FUNCTIONS */

struct __cerbty_unnamed_tag_683_cn* convert_to_struct___cerbty_unnamed_tag_683_cn(struct __cerbty_unnamed_tag_683 __cerbty_unnamed_tag_683)
{
  struct __cerbty_unnamed_tag_683_cn* res = (struct __cerbty_unnamed_tag_683_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_683_cn));
  res->__dummy_max_align_t = convert_to_cn_pointer(__cerbty_unnamed_tag_683.__dummy_max_align_t);
  return res;
}

struct div_cn* convert_to_struct_div_cn(struct div div)
{
  struct div_cn* res = (struct div_cn*) cn_bump_malloc(sizeof(struct div_cn));
  res->quot = convert_to_cn_bits_i32(div.quot);
  res->rem = convert_to_cn_bits_i32(div.rem);
  return res;
}

struct ldiv_cn* convert_to_struct_ldiv_cn(struct ldiv ldiv)
{
  struct ldiv_cn* res = (struct ldiv_cn*) cn_bump_malloc(sizeof(struct ldiv_cn));
  res->quot = convert_to_cn_bits_i64(ldiv.quot);
  res->rem = convert_to_cn_bits_i64(ldiv.rem);
  return res;
}

struct lldiv_cn* convert_to_struct_lldiv_cn(struct lldiv lldiv)
{
  struct lldiv_cn* res = (struct lldiv_cn*) cn_bump_malloc(sizeof(struct lldiv_cn));
  res->quot = convert_to_cn_bits_i64(lldiv.quot);
  res->rem = convert_to_cn_bits_i64(lldiv.rem);
  return res;
}

struct __cerbty_unnamed_tag_813_cn* convert_to_struct___cerbty_unnamed_tag_813_cn(struct __cerbty_unnamed_tag_813 __cerbty_unnamed_tag_813)
{
  struct __cerbty_unnamed_tag_813_cn* res = (struct __cerbty_unnamed_tag_813_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_813_cn));
  res->quot = convert_to_cn_bits_i64(__cerbty_unnamed_tag_813.quot);
  res->rem = convert_to_cn_bits_i64(__cerbty_unnamed_tag_813.rem);
  return res;
}

struct list_head_cn* convert_to_struct_list_head_cn(struct list_head list_head)
{
  struct list_head_cn* res = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  res->next = convert_to_cn_pointer(list_head.next);
  res->prev = convert_to_cn_pointer(list_head.prev);
  return res;
}

struct kvm_hyp_memcache_cn* convert_to_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache kvm_hyp_memcache)
{
  struct kvm_hyp_memcache_cn* res = (struct kvm_hyp_memcache_cn*) cn_bump_malloc(sizeof(struct kvm_hyp_memcache_cn));
  res->head = convert_to_cn_bits_u64(kvm_hyp_memcache.head);
  res->nr_pages = convert_to_cn_bits_u64(kvm_hyp_memcache.nr_pages);
  res->flags = convert_to_cn_bits_u64(kvm_hyp_memcache.flags);
  return res;
}

struct hyp_allocator_cn* convert_to_struct_hyp_allocator_cn(struct hyp_allocator hyp_allocator)
{
  struct hyp_allocator_cn* res = (struct hyp_allocator_cn*) cn_bump_malloc(sizeof(struct hyp_allocator_cn));
  res->chunks = convert_to_struct_list_head_cn(hyp_allocator.chunks);
  res->start = convert_to_cn_bits_u64(hyp_allocator.start);
  res->size = convert_to_cn_bits_u32(hyp_allocator.size);
  res->lock = convert_to_cn_bits_u64(hyp_allocator.lock);
  return res;
}

struct chunk_hdr_cn* convert_to_struct_chunk_hdr_cn(struct chunk_hdr chunk_hdr)
{
  struct chunk_hdr_cn* res = (struct chunk_hdr_cn*) cn_bump_malloc(sizeof(struct chunk_hdr_cn));
  res->alloc_size = convert_to_cn_bits_u32(chunk_hdr.alloc_size);
  res->mapped_size = convert_to_cn_bits_u32(chunk_hdr.mapped_size);
  res->node = convert_to_struct_list_head_cn(chunk_hdr.node);
  res->hash = convert_to_cn_bits_u32(chunk_hdr.hash);
  res->data = convert_to_cn_bits_u8(chunk_hdr.data);
  return res;
}

struct chunk_hdr_only_cn* convert_to_struct_chunk_hdr_only_cn(struct chunk_hdr_only chunk_hdr_only)
{
  struct chunk_hdr_only_cn* res = (struct chunk_hdr_only_cn*) cn_bump_malloc(sizeof(struct chunk_hdr_only_cn));
  res->alloc_size = convert_to_cn_bits_u32(chunk_hdr_only.alloc_size);
  res->mapped_size = convert_to_cn_bits_u32(chunk_hdr_only.mapped_size);
  res->node = convert_to_struct_list_head_cn(chunk_hdr_only.node);
  res->hash = convert_to_cn_bits_u32(chunk_hdr_only.hash);
  return res;
}

struct __cerbty_unnamed_tag_683 convert_from_struct___cerbty_unnamed_tag_683_cn(struct __cerbty_unnamed_tag_683_cn* __cerbty_unnamed_tag_683)
{
  struct __cerbty_unnamed_tag_683 res;
  res.__dummy_max_align_t = convert_from_cn_pointer(__cerbty_unnamed_tag_683->__dummy_max_align_t);
  return res;
}

struct div convert_from_struct_div_cn(struct div_cn* div)
{
  struct div res;
  res.quot = convert_from_cn_bits_i32(div->quot);
  res.rem = convert_from_cn_bits_i32(div->rem);
  return res;
}

struct ldiv convert_from_struct_ldiv_cn(struct ldiv_cn* ldiv)
{
  struct ldiv res;
  res.quot = convert_from_cn_bits_i64(ldiv->quot);
  res.rem = convert_from_cn_bits_i64(ldiv->rem);
  return res;
}

struct lldiv convert_from_struct_lldiv_cn(struct lldiv_cn* lldiv)
{
  struct lldiv res;
  res.quot = convert_from_cn_bits_i64(lldiv->quot);
  res.rem = convert_from_cn_bits_i64(lldiv->rem);
  return res;
}

struct __cerbty_unnamed_tag_813 convert_from_struct___cerbty_unnamed_tag_813_cn(struct __cerbty_unnamed_tag_813_cn* __cerbty_unnamed_tag_813)
{
  struct __cerbty_unnamed_tag_813 res;
  res.quot = convert_from_cn_bits_i64(__cerbty_unnamed_tag_813->quot);
  res.rem = convert_from_cn_bits_i64(__cerbty_unnamed_tag_813->rem);
  return res;
}

struct list_head convert_from_struct_list_head_cn(struct list_head_cn* list_head)
{
  struct list_head res;
  res.next = convert_from_cn_pointer(list_head->next);
  res.prev = convert_from_cn_pointer(list_head->prev);
  return res;
}

struct kvm_hyp_memcache convert_from_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache_cn* kvm_hyp_memcache)
{
  struct kvm_hyp_memcache res;
  res.head = convert_from_cn_bits_u64(kvm_hyp_memcache->head);
  res.nr_pages = convert_from_cn_bits_u64(kvm_hyp_memcache->nr_pages);
  res.flags = convert_from_cn_bits_u64(kvm_hyp_memcache->flags);
  return res;
}

struct hyp_allocator convert_from_struct_hyp_allocator_cn(struct hyp_allocator_cn* hyp_allocator)
{
  struct hyp_allocator res;
  res.chunks = convert_from_struct_list_head_cn(hyp_allocator->chunks);
  res.start = convert_from_cn_bits_u64(hyp_allocator->start);
  res.size = convert_from_cn_bits_u32(hyp_allocator->size);
  res.lock = convert_from_cn_bits_u64(hyp_allocator->lock);
  return res;
}

struct chunk_hdr convert_from_struct_chunk_hdr_cn(struct chunk_hdr_cn* chunk_hdr)
{
  struct chunk_hdr res;
  res.alloc_size = convert_from_cn_bits_u32(chunk_hdr->alloc_size);
  res.mapped_size = convert_from_cn_bits_u32(chunk_hdr->mapped_size);
  res.node = convert_from_struct_list_head_cn(chunk_hdr->node);
  res.hash = convert_from_cn_bits_u32(chunk_hdr->hash);
  res.data = convert_from_cn_bits_u8(chunk_hdr->data);
  return res;
}

struct chunk_hdr_only convert_from_struct_chunk_hdr_only_cn(struct chunk_hdr_only_cn* chunk_hdr_only)
{
  struct chunk_hdr_only res;
  res.alloc_size = convert_from_cn_bits_u32(chunk_hdr_only->alloc_size);
  res.mapped_size = convert_from_cn_bits_u32(chunk_hdr_only->mapped_size);
  res.node = convert_from_struct_list_head_cn(chunk_hdr_only->node);
  res.hash = convert_from_cn_bits_u32(chunk_hdr_only->hash);
  return res;
}

cn_bool* struct___cerbty_unnamed_tag_683_cn_equality(void* x, void* y)
{
  struct __cerbty_unnamed_tag_683_cn* x_cast = (struct __cerbty_unnamed_tag_683_cn*) x;
  struct __cerbty_unnamed_tag_683_cn* y_cast = (struct __cerbty_unnamed_tag_683_cn*) y;
  return cn_bool_and(convert_to_cn_bool(true), cn_pointer_equality(x_cast->__dummy_max_align_t, y_cast->__dummy_max_align_t));
}

cn_bool* struct_div_cn_equality(void* x, void* y)
{
  struct div_cn* x_cast = (struct div_cn*) x;
  struct div_cn* y_cast = (struct div_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_i32_equality(x_cast->quot, y_cast->quot)), cn_bits_i32_equality(x_cast->rem, y_cast->rem));
}

cn_bool* struct_ldiv_cn_equality(void* x, void* y)
{
  struct ldiv_cn* x_cast = (struct ldiv_cn*) x;
  struct ldiv_cn* y_cast = (struct ldiv_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_i64_equality(x_cast->quot, y_cast->quot)), cn_bits_i64_equality(x_cast->rem, y_cast->rem));
}

cn_bool* struct_lldiv_cn_equality(void* x, void* y)
{
  struct lldiv_cn* x_cast = (struct lldiv_cn*) x;
  struct lldiv_cn* y_cast = (struct lldiv_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_i64_equality(x_cast->quot, y_cast->quot)), cn_bits_i64_equality(x_cast->rem, y_cast->rem));
}

cn_bool* struct___cerbty_unnamed_tag_813_cn_equality(void* x, void* y)
{
  struct __cerbty_unnamed_tag_813_cn* x_cast = (struct __cerbty_unnamed_tag_813_cn*) x;
  struct __cerbty_unnamed_tag_813_cn* y_cast = (struct __cerbty_unnamed_tag_813_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_i64_equality(x_cast->quot, y_cast->quot)), cn_bits_i64_equality(x_cast->rem, y_cast->rem));
}

cn_bool* struct_list_head_cn_equality(void* x, void* y)
{
  struct list_head_cn* x_cast = (struct list_head_cn*) x;
  struct list_head_cn* y_cast = (struct list_head_cn*) y;
  return cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_pointer_equality(x_cast->next, y_cast->next)), cn_pointer_equality(x_cast->prev, y_cast->prev));
}

cn_bool* struct_kvm_hyp_memcache_cn_equality(void* x, void* y)
{
  struct kvm_hyp_memcache_cn* x_cast = (struct kvm_hyp_memcache_cn*) x;
  struct kvm_hyp_memcache_cn* y_cast = (struct kvm_hyp_memcache_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_u64_equality(x_cast->head, y_cast->head)), cn_bits_u64_equality(x_cast->nr_pages, y_cast->nr_pages)), cn_bits_u64_equality(x_cast->flags, y_cast->flags));
}

cn_bool* struct_hyp_allocator_cn_equality(void* x, void* y)
{
  struct hyp_allocator_cn* x_cast = (struct hyp_allocator_cn*) x;
  struct hyp_allocator_cn* y_cast = (struct hyp_allocator_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), struct_list_head_cn_equality(x_cast->chunks, y_cast->chunks)), cn_bits_u64_equality(x_cast->start, y_cast->start)), cn_bits_u32_equality(x_cast->size, y_cast->size)), cn_bits_u64_equality(x_cast->lock, y_cast->lock));
}

cn_bool* struct_chunk_hdr_cn_equality(void* x, void* y)
{
  struct chunk_hdr_cn* x_cast = (struct chunk_hdr_cn*) x;
  struct chunk_hdr_cn* y_cast = (struct chunk_hdr_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_u32_equality(x_cast->alloc_size, y_cast->alloc_size)), cn_bits_u32_equality(x_cast->mapped_size, y_cast->mapped_size)), struct_list_head_cn_equality(x_cast->node, y_cast->node)), cn_bits_u32_equality(x_cast->hash, y_cast->hash)), cn_bits_u8_equality(x_cast->data, y_cast->data));
}

cn_bool* struct_chunk_hdr_only_cn_equality(void* x, void* y)
{
  struct chunk_hdr_only_cn* x_cast = (struct chunk_hdr_only_cn*) x;
  struct chunk_hdr_only_cn* y_cast = (struct chunk_hdr_only_cn*) y;
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(convert_to_cn_bool(true), cn_bits_u32_equality(x_cast->alloc_size, y_cast->alloc_size)), cn_bits_u32_equality(x_cast->mapped_size, y_cast->mapped_size)), struct_list_head_cn_equality(x_cast->node, y_cast->node)), cn_bits_u32_equality(x_cast->hash, y_cast->hash));
}

cn_bool* struct_list_head_option_equality(struct list_head_option* x, struct list_head_option* y)
{
  if (x->tag != y->tag)
    return convert_to_cn_bool(0);
  else
    switch (x->tag)
  {
    case LIST_HEAD_NONE:
    {
      return convert_to_cn_bool(1);
    }
    case LIST_HEAD_SOME:
    {
      struct list_head_some* a_13444 = x->u.list_head_some;
      struct list_head_some* a_13445 = y->u.list_head_some;
      return cn_bool_and(struct_list_head_cn_equality(a_13444->L, a_13445->L), convert_to_cn_bool(1));
    }
  }
}

cn_bool* struct_cn_chunk_hdrs_equality(struct cn_chunk_hdrs* x, struct cn_chunk_hdrs* y)
{
  if (x->tag != y->tag)
    return convert_to_cn_bool(0);
  else
    switch (x->tag)
  {
    case CHUNK_NIL:
    {
      return convert_to_cn_bool(1);
    }
    case CHUNK_CONS:
    {
      struct chunk_cons* a_13465 = x->u.chunk_cons;
      struct chunk_cons* a_13466 = y->u.chunk_cons;
      return cn_bool_and(struct_cn_chunk_hdrs_equality(a_13465->tl, a_13466->tl), cn_bool_and(struct_a_9481_record_equality(a_13465->hd, a_13466->hd), convert_to_cn_bool(1)));
    }
  }
}

cn_bool* struct_cn_chunk_hdr_option_equality(struct cn_chunk_hdr_option* x, struct cn_chunk_hdr_option* y)
{
  if (x->tag != y->tag)
    return convert_to_cn_bool(0);
  else
    switch (x->tag)
  {
    case CHUNK_NONE:
    {
      return convert_to_cn_bool(1);
    }
    case CHUNK_SOME:
    {
      struct chunk_some* a_13488 = x->u.chunk_some;
      struct chunk_some* a_13489 = y->u.chunk_some;
      return cn_bool_and(struct_a_9481_record_equality(a_13488->hdr, a_13489->hdr), convert_to_cn_bool(1));
    }
  }
}

cn_bool* struct_chunk_hdr_option_equality(struct chunk_hdr_option* x, struct chunk_hdr_option* y)
{
  if (x->tag != y->tag)
    return convert_to_cn_bool(0);
  else
    switch (x->tag)
  {
    case CHUNKHDR_NONE:
    {
      return convert_to_cn_bool(1);
    }
    case CHUNKHDR_SOME:
    {
      struct chunkhdr_some* a_13508 = x->u.chunkhdr_some;
      struct chunkhdr_some* a_13509 = y->u.chunkhdr_some;
      return cn_bool_and(struct_chunk_hdr_cn_equality(a_13508->hdr, a_13509->hdr), convert_to_cn_bool(1));
    }
  }
}

void* cn_map_get_struct___cerbty_unnamed_tag_683_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct___cerbty_unnamed_tag_683_cn();
  else
    return ret;
}

void* cn_map_get_struct_div_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_div_cn();
  else
    return ret;
}

void* cn_map_get_struct_ldiv_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_ldiv_cn();
  else
    return ret;
}

void* cn_map_get_struct_lldiv_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_lldiv_cn();
  else
    return ret;
}

void* cn_map_get_struct___cerbty_unnamed_tag_813_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct___cerbty_unnamed_tag_813_cn();
  else
    return ret;
}

void* cn_map_get_struct_list_head_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_list_head_cn();
  else
    return ret;
}

void* cn_map_get_struct_kvm_hyp_memcache_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_kvm_hyp_memcache_cn();
  else
    return ret;
}

void* cn_map_get_struct_hyp_allocator_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_hyp_allocator_cn();
  else
    return ret;
}

void* cn_map_get_struct_chunk_hdr_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_chunk_hdr_cn();
  else
    return ret;
}

void* cn_map_get_struct_chunk_hdr_only_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_chunk_hdr_only_cn();
  else
    return ret;
}

struct __cerbty_unnamed_tag_683_cn* default_struct___cerbty_unnamed_tag_683_cn()
{
  struct __cerbty_unnamed_tag_683_cn* a_13610 = (struct __cerbty_unnamed_tag_683_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_683_cn));
  a_13610->__dummy_max_align_t = default_cn_pointer();
  return a_13610;
}

struct div_cn* default_struct_div_cn()
{
  struct div_cn* a_13615 = (struct div_cn*) cn_bump_malloc(sizeof(struct div_cn));
  a_13615->quot = default_cn_bits_i32();
  a_13615->rem = default_cn_bits_i32();
  return a_13615;
}

struct ldiv_cn* default_struct_ldiv_cn()
{
  struct ldiv_cn* a_13622 = (struct ldiv_cn*) cn_bump_malloc(sizeof(struct ldiv_cn));
  a_13622->quot = default_cn_bits_i64();
  a_13622->rem = default_cn_bits_i64();
  return a_13622;
}

struct lldiv_cn* default_struct_lldiv_cn()
{
  struct lldiv_cn* a_13629 = (struct lldiv_cn*) cn_bump_malloc(sizeof(struct lldiv_cn));
  a_13629->quot = default_cn_bits_i64();
  a_13629->rem = default_cn_bits_i64();
  return a_13629;
}

struct __cerbty_unnamed_tag_813_cn* default_struct___cerbty_unnamed_tag_813_cn()
{
  struct __cerbty_unnamed_tag_813_cn* a_13636 = (struct __cerbty_unnamed_tag_813_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_813_cn));
  a_13636->quot = default_cn_bits_i64();
  a_13636->rem = default_cn_bits_i64();
  return a_13636;
}

struct list_head_cn* default_struct_list_head_cn()
{
  struct list_head_cn* a_13643 = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  a_13643->next = default_cn_pointer();
  a_13643->prev = default_cn_pointer();
  return a_13643;
}

struct kvm_hyp_memcache_cn* default_struct_kvm_hyp_memcache_cn()
{
  struct kvm_hyp_memcache_cn* a_13650 = (struct kvm_hyp_memcache_cn*) cn_bump_malloc(sizeof(struct kvm_hyp_memcache_cn));
  a_13650->head = default_cn_bits_u64();
  a_13650->nr_pages = default_cn_bits_u64();
  a_13650->flags = default_cn_bits_u64();
  return a_13650;
}

struct hyp_allocator_cn* default_struct_hyp_allocator_cn()
{
  struct hyp_allocator_cn* a_13659 = (struct hyp_allocator_cn*) cn_bump_malloc(sizeof(struct hyp_allocator_cn));
  a_13659->chunks = default_struct_list_head_cn();
  a_13659->start = default_cn_bits_u64();
  a_13659->size = default_cn_bits_u32();
  a_13659->lock = default_cn_bits_u64();
  return a_13659;
}

struct chunk_hdr_cn* default_struct_chunk_hdr_cn()
{
  struct chunk_hdr_cn* a_13671 = (struct chunk_hdr_cn*) cn_bump_malloc(sizeof(struct chunk_hdr_cn));
  a_13671->alloc_size = default_cn_bits_u32();
  a_13671->mapped_size = default_cn_bits_u32();
  a_13671->node = default_struct_list_head_cn();
  a_13671->hash = default_cn_bits_u32();
  a_13671->data = default_cn_bits_u8();
  return a_13671;
}

struct chunk_hdr_only_cn* default_struct_chunk_hdr_only_cn()
{
  struct chunk_hdr_only_cn* a_13685 = (struct chunk_hdr_only_cn*) cn_bump_malloc(sizeof(struct chunk_hdr_only_cn));
  a_13685->alloc_size = default_cn_bits_u32();
  a_13685->mapped_size = default_cn_bits_u32();
  a_13685->node = default_struct_list_head_cn();
  a_13685->hash = default_cn_bits_u32();
  return a_13685;
}

void* cn_map_get_struct_list_head_option(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_list_head_option();
  else
    return ret;
}

void* cn_map_get_struct_cn_chunk_hdrs(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_cn_chunk_hdrs();
  else
    return ret;
}

void* cn_map_get_struct_cn_chunk_hdr_option(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_cn_chunk_hdr_option();
  else
    return ret;
}

void* cn_map_get_struct_chunk_hdr_option(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_chunk_hdr_option();
  else
    return ret;
}

struct list_head_option* default_struct_list_head_option()
{
  struct list_head_option* res = (struct list_head_option*) cn_bump_malloc(sizeof(struct list_head_option));
  res->tag = LIST_HEAD_NONE;
  res->u.list_head_none = (struct list_head_none*) cn_bump_malloc(sizeof(struct list_head_none));
  return res;
}

struct cn_chunk_hdrs* default_struct_cn_chunk_hdrs()
{
  struct cn_chunk_hdrs* res = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
  res->tag = CHUNK_NIL;
  res->u.chunk_nil = (struct chunk_nil*) cn_bump_malloc(sizeof(struct chunk_nil));
  return res;
}

struct cn_chunk_hdr_option* default_struct_cn_chunk_hdr_option()
{
  struct cn_chunk_hdr_option* res = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
  res->tag = CHUNK_NONE;
  res->u.chunk_none = (struct chunk_none*) cn_bump_malloc(sizeof(struct chunk_none));
  return res;
}

struct chunk_hdr_option* default_struct_chunk_hdr_option()
{
  struct chunk_hdr_option* res = (struct chunk_hdr_option*) cn_bump_malloc(sizeof(struct chunk_hdr_option));
  res->tag = CHUNKHDR_NONE;
  res->u.chunkhdr_none = (struct chunkhdr_none*) cn_bump_malloc(sizeof(struct chunkhdr_none));
  return res;
}

/* OWNERSHIP FUNCTIONS */

cn_bits_u8* owned_char(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (char*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(char));
  return convert_to_cn_bits_u8((*(char*) cn_ptr->ptr));
}

struct chunk_hdr_cn* owned_struct_chunk_hdr(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct chunk_hdr*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct chunk_hdr));
  return convert_to_struct_chunk_hdr_cn((*(struct chunk_hdr*) cn_ptr->ptr));
}

struct chunk_hdr_only_cn* owned_struct_chunk_hdr_only(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct chunk_hdr_only*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct chunk_hdr_only));
  return convert_to_struct_chunk_hdr_only_cn((*(struct chunk_hdr_only*) cn_ptr->ptr));
}

struct hyp_allocator_cn* owned_struct_hyp_allocator(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct hyp_allocator*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_allocator));
  return convert_to_struct_hyp_allocator_cn((*(struct hyp_allocator*) cn_ptr->ptr));
}

struct list_head_cn* owned_struct_list_head(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct list_head*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct list_head));
  return convert_to_struct_list_head_cn((*(struct list_head*) cn_ptr->ptr));
}

cn_bits_u64* owned_size_t(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (size_t*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(size_t));
  return convert_to_cn_bits_u64((*(size_t*) cn_ptr->ptr));
}

cn_pointer* owned_struct_hyp_allocator_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct hyp_allocator**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct hyp_allocator*));
  return convert_to_cn_pointer((*(struct hyp_allocator**) cn_ptr->ptr));
}

cn_pointer* owned_struct_chunk_hdr_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct chunk_hdr**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct chunk_hdr*));
  return convert_to_cn_pointer((*(struct chunk_hdr**) cn_ptr->ptr));
}

cn_bits_u32* owned_unsigned_int(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (unsigned int*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(unsigned int));
  return convert_to_cn_bits_u32((*(unsigned int*) cn_ptr->ptr));
}

cn_pointer* owned_unsigned_long_long_pointer(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (unsigned long long**) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(unsigned long long*));
  return convert_to_cn_pointer((*(unsigned long long**) cn_ptr->ptr));
}
cn_bits_i64* MAXi64()
{
  return convert_to_cn_bits_i64(INT64_MAX);
}

cn_bits_i64* MINi64()
{
  return convert_to_cn_bits_i64(INT64_MIN);
}

cn_bits_i32* MAXi32()
{
  return convert_to_cn_bits_i32(INT32_MAX);
}

cn_bits_i32* MINi32()
{
  return convert_to_cn_bits_i32(INT32_MIN);
}

cn_bits_i16* MAXi16()
{
  return convert_to_cn_bits_i16(INT16_MAX);
}

cn_bits_i16* MINi16()
{
  return convert_to_cn_bits_i16(INT16_MIN);
}

cn_bits_i8* MAXi8()
{
  return convert_to_cn_bits_i8(INT8_MAX);
}

cn_bits_i8* MINi8()
{
  return convert_to_cn_bits_i8(INT8_MIN);
}

cn_bits_u64* MAXu64()
{
  return convert_to_cn_bits_u64(UINT64_MAX);
}

cn_bits_u64* MINu64()
{
  return convert_to_cn_bits_u64(0ULL);
}

cn_bits_u32* MAXu32()
{
  return convert_to_cn_bits_u32(UINT32_MAX);
}

cn_bits_u32* MINu32()
{
  return convert_to_cn_bits_u32(0ULL);
}

cn_bits_u16* MAXu16()
{
  return convert_to_cn_bits_u16(UINT16_MAX);
}

cn_bits_u16* MINu16()
{
  return convert_to_cn_bits_u16(0ULL);
}

cn_bits_u8* MAXu8()
{
  return convert_to_cn_bits_u8(UINT8_MAX);
}

cn_bits_u8* MINu8()
{
  return convert_to_cn_bits_u8(0UL);
}

cn_bool* not(cn_bool* arg)
{
  return cn_bool_not(arg);
}

cn_bool* is_null(cn_pointer* arg)
{
  return cn_pointer_equality(arg, convert_to_cn_pointer(NULL));
}

cn_bool* ptr_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_pointer_equality(arg1, arg2);
}

cn_bool* prov_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_alloc_id_equality(convert_to_cn_alloc_id(0), convert_to_cn_alloc_id(0));
}

cn_bool* addr_eq(cn_pointer* arg1, cn_pointer* arg2)
{
  return cn_bits_u64_equality(cast_cn_pointer_to_cn_bits_u64(arg1), cast_cn_pointer_to_cn_bits_u64(arg2));
}

cn_bits_i32* EINVAL()
{
  return convert_to_cn_bits_i32(22LL);
}

cn_bool* list_add_aux(struct list_head_cn* Next_post, struct list_head_cn* New_post, struct list_head_cn* Head_post, cn_pointer* new, cn_pointer* next, cn_pointer* head)
{
  return cn_bool_and(cn_bool_and(cn_bool_and(ptr_eq(Next_post->prev, new), ptr_eq(New_post->next, next)), ptr_eq(New_post->prev, head)), ptr_eq(Head_post->next, new));
}

cn_bits_u64* PAGE_ALIGN_DOWN(cn_bits_u64* addr)
{
  cn_bits_u64* page_mask = cn_bits_u64_sub(cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(12ULL)), convert_to_cn_bits_u64(1ULL));
  return cn_bits_u64_bwand(addr, cn_bits_u64_bw_compl(page_mask));
}

cn_bits_u64* PAGE_ALIGN(cn_bits_u64* addr)
{
  cn_bits_u64* page_mask = cn_bits_u64_sub(cn_bits_u64_shift_left(convert_to_cn_bits_u64(1ULL), convert_to_cn_bits_u64(12ULL)), convert_to_cn_bits_u64(1ULL));
  return cn_bits_u64_bwand(cn_bits_u64_add(addr, page_mask), cn_bits_u64_bw_compl(page_mask));
}

cn_bits_u64* MIN_ALLOC()
{
  return convert_to_cn_bits_u64(8ULL);
}

cn_bool* hash_change_only(struct chunk_hdr_cn* pre, struct chunk_hdr_cn* post)
{
  return cn_bool_and(cn_bool_and(cn_bits_u32_equality(pre->alloc_size, post->alloc_size), cn_bits_u32_equality(pre->mapped_size, post->mapped_size)), struct_list_head_cn_equality(pre->node, post->node));
}

cn_bits_u64* Cn_chunk_hdr_size()
{
  return cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(offsetof(struct chunk_hdr, data)));
}

cn_bits_u64* Cn_chunk_size(cn_bits_u64* size)
{
  cn_bits_u64* a_12362;
  if (convert_from_cn_bool(cn_bits_u64_lt(MIN_ALLOC(), size))) {
    a_12362 = size;
  }
  else {
    a_12362 = MIN_ALLOC();
  }
  return cn_bits_u64_add(Cn_chunk_hdr_size(), a_12362);
}

cn_pointer* Cn_chunk_data(struct chunk_hdr_cn* chunk)
{
  return cast_cn_bits_u8_to_cn_pointer(chunk->data);
}

cn_pointer* my_container_of_chunk_hdr(cn_pointer* p)
{
  return cast_cn_bits_u64_to_cn_pointer(cn_bits_u64_sub(cast_cn_pointer_to_cn_bits_u64(p), cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(offsetof(struct chunk_hdr, node)))));
}

cn_bool* is_last_chunk(cn_pointer* node_address, struct hyp_allocator_cn* ha)
{
  return ptr_eq(node_address, ha->chunks->prev);
}

cn_pointer* HeadOrValue(struct cn_chunk_hdrs* hdrs, cn_pointer* value)
{
  switch (hdrs->tag)
  {
    case CHUNK_NIL:
    {
      struct chunk_nil* chunk_nil_1 = hdrs->u.chunk_nil;
      return value;
    }
    case CHUNK_CONS:
    {
      struct chunk_cons* chunk_cons_1 = hdrs->u.chunk_cons;
      struct cn_chunk_hdrs* tl = chunk_cons_1->tl;
      struct a_9481_record* hdr = chunk_cons_1->hd;
      return cast_cn_bits_u64_to_cn_pointer(hdr->header_address);
    }
  }
}

struct cn_chunk_hdrs* ConcatChunkList(struct cn_chunk_hdrs* before, struct cn_chunk_hdrs* after)
{
  switch (before->tag)
  {
    case CHUNK_NIL:
    {
      struct chunk_nil* chunk_nil_1 = before->u.chunk_nil;
      return after;
    }
    case CHUNK_CONS:
    {
      struct chunk_cons* chunk_cons_1 = before->u.chunk_cons;
      struct cn_chunk_hdrs* tl = chunk_cons_1->tl;
      struct a_9481_record* hdr = chunk_cons_1->hd;
      struct cn_chunk_hdrs* a_12406 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
      a_12406->tag = CHUNK_CONS;
      a_12406->u.chunk_cons = (struct chunk_cons*) cn_bump_malloc(sizeof(struct chunk_cons));
      a_12406->u.chunk_cons->hd = hdr;
      a_12406->u.chunk_cons->tl = after;
      return ConcatChunkList(tl, a_12406);
    }
  }
}

cn_bool* Is_chunk_some(struct cn_chunk_hdr_option* maybe_hdr)
{
  switch (maybe_hdr->tag)
  {
    case CHUNK_NONE:
    {
      struct chunk_none* chunk_none_1 = maybe_hdr->u.chunk_none;
      return convert_to_cn_bool(false);
    }
    case CHUNK_SOME:
    {
      struct chunk_some* chunk_some_1 = maybe_hdr->u.chunk_some;
      struct a_9481_record* hdr = chunk_some_1->hdr;
      return convert_to_cn_bool(true);
    }
  }
}

struct cn_chunk_hdr_option* lookup(cn_pointer* p, struct cn_chunk_hdrs* hdrs)
{
  switch (hdrs->tag)
  {
    case CHUNK_NIL:
    {
      struct chunk_nil* chunk_nil_1 = hdrs->u.chunk_nil;
      struct cn_chunk_hdr_option* a_12423 = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
      a_12423->tag = CHUNK_NONE;
      return a_12423;
    }
    case CHUNK_CONS:
    {
      struct chunk_cons* chunk_cons_1 = hdrs->u.chunk_cons;
      struct cn_chunk_hdrs* tl = chunk_cons_1->tl;
      struct a_9481_record* hdr = chunk_cons_1->hd;
      struct cn_chunk_hdr_option* a_12429;
      if (convert_from_cn_bool(cn_bits_u64_equality(hdr->header_address, cast_cn_pointer_to_cn_bits_u64(p)))) {
        struct cn_chunk_hdr_option* a_12437 = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
        a_12437->tag = CHUNK_SOME;
        a_12437->u.chunk_some = (struct chunk_some*) cn_bump_malloc(sizeof(struct chunk_some));
        a_12437->u.chunk_some->hdr = hdr;
        a_12429 = a_12437;
      }
      else {
        a_12429 = lookup(p, tl);
      }
      return a_12429;
    }
  }
}

struct cn_chunk_hdr_option* next_chunk(cn_pointer* p, struct cn_chunk_hdrs* hdrs)
{
  switch (hdrs->tag)
  {
    case CHUNK_NIL:
    {
      struct chunk_nil* chunk_nil_1 = hdrs->u.chunk_nil;
      struct cn_chunk_hdr_option* a_12444 = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
      a_12444->tag = CHUNK_NONE;
      return a_12444;
    }
    case CHUNK_CONS:
    {
      struct chunk_cons* chunk_cons_1 = hdrs->u.chunk_cons;
      struct cn_chunk_hdrs* tl = chunk_cons_1->tl;
      struct a_9481_record* hdr = chunk_cons_1->hd;
      struct cn_chunk_hdr_option* a_12450;
      if (convert_from_cn_bool(cn_bits_u64_equality(hdr->header_address, cast_cn_pointer_to_cn_bits_u64(p)))) {
        switch (tl->tag)
        {
          case CHUNK_NIL:
          {
            struct chunk_nil* chunk_nil_1 = tl->u.chunk_nil;
            struct cn_chunk_hdr_option* a_12460 = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
            a_12460->tag = CHUNK_NONE;
            a_12450 = a_12460;
            break;
          }
          case CHUNK_CONS:
          {
            struct chunk_cons* chunk_cons_1 = tl->u.chunk_cons;
            struct cn_chunk_hdrs* tl2 = chunk_cons_1->tl;
            struct a_9481_record* hdr2 = chunk_cons_1->hd;
            struct cn_chunk_hdr_option* a_12466 = (struct cn_chunk_hdr_option*) cn_bump_malloc(sizeof(struct cn_chunk_hdr_option));
            a_12466->tag = CHUNK_SOME;
            a_12466->u.chunk_some = (struct chunk_some*) cn_bump_malloc(sizeof(struct chunk_some));
            a_12466->u.chunk_some->hdr = hdr2;
            a_12450 = a_12466;
            break;
          }
        }
      }
      else {
        a_12450 = lookup(p, tl);
      }
      return a_12450;
    }
  }
}

cn_bool* is_free_chunk(struct a_9481_record* hdr, cn_bits_u32* size)
{
  return cn_bool_and(cn_bits_u32_equality(hdr->alloc_size, convert_to_cn_bits_u32(0ULL)), cn_bits_u64_le(Cn_chunk_size(cast_cn_bits_u32_to_cn_bits_u64(size)), cast_cn_bits_u32_to_cn_bits_u64(hdr->va_size)));
}

cn_bits_u64* Cn_chunk_unmapped_region(cn_pointer* chunk_p, struct chunk_hdr_cn* chunk)
{
  return cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(chunk_p), cast_cn_bits_u32_to_cn_bits_u64(chunk->mapped_size));
}

cn_bool* Cn_list_is_first(struct list_head_cn* node, cn_pointer* chunks)
{
  return ptr_eq(node->prev, chunks);
}

cn_bool* Cn_list_is_last(struct list_head_cn* node, cn_pointer* chunks)
{
  return ptr_eq(node->next, chunks);
}

cn_pointer* Cn_chunk_get_next(struct chunk_hdr_cn* chunk, cn_pointer* allocator)
{
  cn_pointer* a_12504;
  if (convert_from_cn_bool(Cn_list_is_last(chunk->node, cn_member_shift(allocator, hyp_allocator, chunks)))) {
    a_12504 = convert_to_cn_pointer(NULL);
  }
  else {
    a_12504 = my_container_of_chunk_hdr(chunk->node->next);
  }
  return a_12504;
}

cn_bits_u32* Cn_chunk_unmapped_size(struct a_9481_record* hdr)
{
  return cn_bits_u32_sub(hdr->va_size, hdr->mapped_size);
}

cn_bool* chunk_list_insert_aux(struct Cn_hyp_allocator_only_record* ha, cn_pointer* chunk, struct chunk_hdr_only_cn* C, cn_pointer* prev, cn_bits_u64* next)
{
  cn_bits_u64* va_size = cn_bits_u64_sub(next, cast_cn_pointer_to_cn_bits_u64(chunk));
  return cn_bool_and(cn_bool_and(cn_bool_and(cn_bool_and(cn_bits_u64_le(ha->start, cast_cn_pointer_to_cn_bits_u64(chunk)), cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(chunk), cn_bits_u64_add(ha->start, cast_cn_bits_u32_to_cn_bits_u64(ha->size)))), cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(prev), cast_cn_pointer_to_cn_bits_u64(chunk))), cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(chunk), next)), cn_bits_u64_le(cast_cn_bits_u32_to_cn_bits_u64(C->mapped_size), va_size));
}

cn_bool* chunk_install_sanity_check(cn_pointer* prev_p, cn_pointer* chunk_p, struct chunk_hdr_cn* prev)
{
  return cn_bool_and(cn_bool_and(cn_bool_not(is_null(prev_p)), cn_bool_not(cn_bits_u64_lt(Cn_chunk_unmapped_region(prev_p, prev), cast_cn_pointer_to_cn_bits_u64(chunk_p)))), cn_bool_not(cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(chunk_p), cn_bits_u64_add(cast_cn_pointer_to_cn_bits_u64(Cn_chunk_data(prev)), cast_cn_bits_u32_to_cn_bits_u64(prev->alloc_size)))));
}


/* CN PREDICATES */

struct list_head_option* CondListHead(cn_pointer* p, cn_bool* condition, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(condition)) {
    update_cn_error_message_info("				take L = RW<struct list_head>(p);\n         ^alloc.pp.c:135:10:");
    struct list_head_cn* L = owned_struct_list_head(p, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
    cn_assert(convert_to_cn_bool(true), spec_mode);
    cn_pop_msg_info();
    struct list_head_option* a_12587 = (struct list_head_option*) cn_bump_malloc(sizeof(struct list_head_option));
    a_12587->tag = LIST_HEAD_SOME;
    a_12587->u.list_head_some = (struct list_head_some*) cn_bump_malloc(sizeof(struct list_head_some));
    a_12587->u.list_head_some->L = L;
    return a_12587;
  }
  else {
    struct list_head_option* a_12590 = (struct list_head_option*) cn_bump_malloc(sizeof(struct list_head_option));
    a_12590->tag = LIST_HEAD_NONE;
    return a_12590;
  }
}

struct Cn_hyp_allocator_only_record* Cn_hyp_allocator_only(cn_pointer* p, enum spec_mode spec_mode)
{
  update_cn_error_message_info("        take ha = RW<struct hyp_allocator>(p);\n             ^alloc.pp.c:744:14:");
  struct hyp_allocator_cn* ha = owned_struct_hyp_allocator(p, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), spec_mode);
  cn_pop_msg_info();
  struct Cn_hyp_allocator_only_record* cn_hyp;
  struct Cn_hyp_allocator_only_record* a_12599 = (struct Cn_hyp_allocator_only_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_only_record));
  a_12599->first = ha->chunks->next;
  a_12599->head = cn_member_shift(p, hyp_allocator, chunks);
  a_12599->last = ha->chunks->prev;
  a_12599->size = ha->size;
  a_12599->start = ha->start;
  cn_hyp = a_12599;
  update_cn_error_message_info("        assert(ha.start < (u64)cn_hyp.start + (u64)cn_hyp.size);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:752:9-753:22");
  cn_assert(cn_bits_u64_lt(ha->start, cn_bits_u64_add(cast_cn_bits_u64_to_cn_bits_u64(cn_hyp->start), cast_cn_bits_u32_to_cn_bits_u64(cn_hyp->size))), spec_mode);
  cn_pop_msg_info();
  return cn_hyp;
}

struct chunk_hdr_only_cn* Own_chunk_hdr(cn_pointer* header_address, enum spec_mode spec_mode)
{
  update_cn_error_message_info("        take cn_hdr = RW<struct chunk_hdr_only>(header_address);\n             ^alloc.pp.c:760:14:");
  struct chunk_hdr_only_cn* cn_hdr = owned_struct_chunk_hdr_only(header_address, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert(cn_hdr.alloc_size <= cn_hdr.mapped_size);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:761:9-762:22");
  cn_assert(cn_bits_u32_le(cn_hdr->alloc_size, cn_hdr->mapped_size), spec_mode);
  cn_pop_msg_info();
  return cn_hdr;
}

struct Cn_chunk_hdr_record* Cn_chunk_hdr(cn_pointer* header_address, struct Cn_hyp_allocator_only_record* ha, enum spec_mode spec_mode)
{
  update_cn_error_message_info("        take hdr = Own_chunk_hdr(header_address);\n             ^alloc.pp.c:768:14:");
  struct chunk_hdr_only_cn* hdr = Own_chunk_hdr(header_address, spec_mode);
  cn_pop_msg_info();
  cn_bits_u64* end;
  end = cn_bits_u64_add(ha->start, cast_cn_bits_u32_to_cn_bits_u64(ha->size));
  cn_bits_u64* va_size;
  cn_bits_u64* a_12635;
  if (convert_from_cn_bool(Cn_list_is_last(hdr->node, ha->head))) {
    a_12635 = end;
  }
  else {
    a_12635 = cast_cn_pointer_to_cn_bits_u64(my_container_of_chunk_hdr(hdr->node->next));
  }
  va_size = cn_bits_u64_sub(a_12635, cast_cn_pointer_to_cn_bits_u64(header_address));
  update_cn_error_message_info("        assert(va_size <= (u64)MAXu32());\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:772:9-807:45");
  cn_assert(cn_bits_u64_le(va_size, cast_cn_bits_u32_to_cn_bits_u64(MAXu32())), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert((u64)hdr.node.next <= end);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:773:9-807:45");
  cn_assert(cn_bits_u64_le(cast_cn_pointer_to_cn_bits_u64(hdr->node->next), end), spec_mode);
  cn_pop_msg_info();
  struct a_9481_record* cn_hdr;
  struct a_9481_record* a_12655 = (struct a_9481_record*) cn_bump_malloc(sizeof(struct a_9481_record));
  a_12655->alloc_size = hdr->alloc_size;
  a_12655->header_address = cast_cn_pointer_to_cn_bits_u64(header_address);
  a_12655->mapped_size = hdr->mapped_size;
  a_12655->va_size = cast_cn_bits_u64_to_cn_bits_u32(va_size);
  cn_hdr = a_12655;
  update_cn_error_message_info("        assert(cn_hdr.mapped_size <= cn_hdr.va_size);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:781:9-807:45");
  cn_assert(cn_bits_u32_le(cn_hdr->mapped_size, cn_hdr->va_size), spec_mode);
  cn_pop_msg_info();
  cn_pointer* chunk_data;
  chunk_data = cn_array_shift(header_address, sizeof(unsigned char), Cn_chunk_hdr_size());
  cn_pointer* start;
  cn_pointer* a_12667;
  if (convert_from_cn_bool(cn_bits_u32_equality(cn_hdr->alloc_size, convert_to_cn_bits_u32(0ULL)))) {
    a_12667 = chunk_data;
  }
  else {
    a_12667 = cn_array_shift(chunk_data, sizeof(unsigned char), cn_hdr->alloc_size);
  }
  start = a_12667;
  cn_bits_u64* size_owned_by_ha;
  cn_bits_u64* a_12677;
  if (convert_from_cn_bool(cn_bits_u32_equality(cn_hdr->alloc_size, convert_to_cn_bits_u32(0ULL)))) {
    a_12677 = cn_bits_u64_sub(cast_cn_bits_u32_to_cn_bits_u64(cn_hdr->va_size), Cn_chunk_hdr_size());
  }
  else {
    a_12677 = cn_bits_u64_sub(cn_bits_u64_sub(cast_cn_bits_u32_to_cn_bits_u64(cn_hdr->va_size), Cn_chunk_hdr_size()), cast_cn_bits_u32_to_cn_bits_u64(cn_hdr->alloc_size));
  }
  size_owned_by_ha = a_12677;
  update_cn_error_message_info("        take A = Cn_char_array(start, size_owned_by_ha);\n             ^alloc.pp.c:790:14:");
  Cn_char_array(start, size_owned_by_ha, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert(cn_hdr.header_address >= ha.start);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:793:9-807:45");
  cn_assert(cn_bits_u64_le(ha->start, cn_hdr->header_address), spec_mode);
  cn_pop_msg_info();
  cn_bits_u64* chunk_end;
  chunk_end = cn_bits_u64_add(cn_hdr->header_address, cast_cn_bits_u32_to_cn_bits_u64(cn_hdr->mapped_size));
  update_cn_error_message_info("        assert(chunk_end <= end);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:795:9-807:45");
  cn_assert(cn_bits_u64_le(chunk_end, end), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert(chunk_end >= cn_hdr.header_address);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:797:9-807:45");
  cn_assert(cn_bits_u64_le(cn_hdr->header_address, chunk_end), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert(\n        ^~~~~~~ alloc.pp.c:803:9-807:45");
  cn_assert(cn_bool_or(cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(cn_member_shift(header_address, chunk_hdr, node)), cast_cn_pointer_to_cn_bits_u64(hdr->node->next)), cn_bits_u64_equality(cast_cn_pointer_to_cn_bits_u64(hdr->node->next), cast_cn_pointer_to_cn_bits_u64(ha->head))), spec_mode);
  cn_pop_msg_info();
  struct Cn_chunk_hdr_record* a_12729 = (struct Cn_chunk_hdr_record*) cn_bump_malloc(sizeof(struct Cn_chunk_hdr_record));
  a_12729->Hdr = cn_hdr;
  a_12729->Node = hdr->node;
  return a_12729;
}

struct Cn_chunk_hdrs_non_last_record* Cn_chunk_hdrs_non_last(cn_pointer* p, cn_pointer* prev, struct Cn_hyp_allocator_only_record* ha, cn_pointer* last, enum spec_mode spec_mode)
{
  cn_pointer* header_address;
  header_address = cn_array_shift(p, sizeof(char), cn_bits_u64_negate(convert_to_cn_bits_u64(offsetof(struct chunk_hdr, node))));
  update_cn_error_message_info("        take cn_hdr = Cn_chunk_hdr(header_address, ha);\n             ^alloc.pp.c:813:14:");
  struct Cn_chunk_hdr_record* cn_hdr = Cn_chunk_hdr(header_address, ha, spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        assert(ptr_eq(cn_hdr.Node.prev, prev));\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:814:9-817:40");
  cn_assert(ptr_eq(cn_hdr->Node->prev, prev), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("        take tl = Cn_chunk_hdrs(cn_hdr.Node.next, p, ha, last);\n             ^alloc.pp.c:815:14:");
  struct cn_chunk_hdrs* tl = Cn_chunk_hdrs(cn_hdr->Node->next, p, ha, last, spec_mode);
  cn_pop_msg_info();
  struct Cn_chunk_hdrs_non_last_record* a_12743 = (struct Cn_chunk_hdrs_non_last_record*) cn_bump_malloc(sizeof(struct Cn_chunk_hdrs_non_last_record));
  a_12743->hd = cn_hdr->Hdr;
  a_12743->tl = tl;
  return a_12743;
}

struct cn_chunk_hdrs* Cn_chunk_hdrs(cn_pointer* p, cn_pointer* prev, struct Cn_hyp_allocator_only_record* ha, cn_pointer* last, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(ptr_eq(p, last))) {
    update_cn_error_message_info("                assert(ha.start <= ha.start + (u64)ha.size);\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:824:17-825:36");
    cn_assert(cn_bits_u64_le(ha->start, cn_bits_u64_add(ha->start, cast_cn_bits_u32_to_cn_bits_u64(ha->size))), spec_mode);
    cn_pop_msg_info();
    struct cn_chunk_hdrs* a_12754 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12754->tag = CHUNK_NIL;
    return a_12754;
  }
  else {
    update_cn_error_message_info("                take T = Cn_chunk_hdrs_non_last(p, prev, ha, last);\n                     ^alloc.pp.c:827:22:");
    struct Cn_chunk_hdrs_non_last_record* T = Cn_chunk_hdrs_non_last(p, prev, ha, last, spec_mode);
    cn_pop_msg_info();
    struct cn_chunk_hdrs* a_12759 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12759->tag = CHUNK_CONS;
    a_12759->u.chunk_cons = (struct chunk_cons*) cn_bump_malloc(sizeof(struct chunk_cons));
    a_12759->u.chunk_cons->hd = T->hd;
    a_12759->u.chunk_cons->tl = T->tl;
    return a_12759;
  }
}

struct cn_chunk_hdrs* Cn_chunk_hdrs_rev(cn_pointer* p, cn_pointer* prev, struct Cn_hyp_allocator_only_record* ha, cn_pointer* last, struct cn_chunk_hdrs* accum, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(ptr_eq(p, last))) {
    return accum;
  }
  else {
    cn_pointer* header_address;
    header_address = cn_array_shift(p, sizeof(char), cn_bits_u64_negate(convert_to_cn_bits_u64(offsetof(struct chunk_hdr, node))));
    update_cn_error_message_info("                take cn_hdr = Cn_chunk_hdr(header_address, ha);\n                     ^alloc.pp.c:838:22:");
    struct Cn_chunk_hdr_record* cn_hdr = Cn_chunk_hdr(header_address, ha, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("                assert(ptr_eq(cn_hdr.Node.prev, prev));\n                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:839:17-842:27");
    cn_assert(ptr_eq(cn_hdr->Node->prev, prev), spec_mode);
    cn_pop_msg_info();
    struct cn_chunk_hdrs* c;
    struct cn_chunk_hdrs* a_12774 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12774->tag = CHUNK_CONS;
    a_12774->u.chunk_cons = (struct chunk_cons*) cn_bump_malloc(sizeof(struct chunk_cons));
    a_12774->u.chunk_cons->hd = cn_hdr->Hdr;
    a_12774->u.chunk_cons->tl = accum;
    c = a_12774;
    update_cn_error_message_info("                take res = Cn_chunk_hdrs_rev(cn_hdr.Node.next, p, ha, last, c);\n                     ^alloc.pp.c:841:22:");
    struct cn_chunk_hdrs* res = Cn_chunk_hdrs_rev(cn_hdr->Node->next, p, ha, last, c, spec_mode);
    cn_pop_msg_info();
    return res;
  }
}

struct Cn_hyp_allocator_focusing_on_record* Cn_hyp_allocator_focusing_on(cn_pointer* p, cn_pointer* chunk, enum spec_mode spec_mode)
{
  update_cn_error_message_info("  take ha = Cn_hyp_allocator_only(p);\n       ^alloc.pp.c:865:8:");
  struct Cn_hyp_allocator_only_record* ha = Cn_hyp_allocator_only(p, spec_mode);
  cn_pop_msg_info();
  cn_bits_u64* end;
  end = cn_bits_u64_add(ha->start, cast_cn_bits_u32_to_cn_bits_u64(ha->size));
  update_cn_error_message_info("  assert(ha.start < end);  // no overflow\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:867:3-873:32");
  cn_assert(cn_bits_u64_lt(ha->start, end), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("  take hdrs1 = Cn_chunk_hdrs_rev(ha.first, ha.head, ha, chunk, Chunk_nil {});\n       ^alloc.pp.c:869:8:");
  struct cn_chunk_hdrs* a_12791 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
  a_12791->tag = CHUNK_NIL;
  struct cn_chunk_hdrs* hdrs1 = Cn_chunk_hdrs_rev(ha->first, ha->head, ha, chunk, a_12791, spec_mode);
  cn_pop_msg_info();
  cn_pointer* prev;
  prev = HeadOrValue(hdrs1, ha->head);
  update_cn_error_message_info("  take T = Cn_chunk_hdrs_non_last(chunk, prev, ha, ha.head);\n       ^alloc.pp.c:871:8:");
  struct Cn_chunk_hdrs_non_last_record* T = Cn_chunk_hdrs_non_last(chunk, prev, ha, ha->head, spec_mode);
  cn_pop_msg_info();
  struct a_9487_record* lseg;
  struct a_9487_record* a_12797 = (struct a_9487_record*) cn_bump_malloc(sizeof(struct a_9487_record));
  a_12797->after = T->tl;
  a_12797->before = hdrs1;
  a_12797->chunk = T->hd;
  lseg = a_12797;
  struct Cn_hyp_allocator_focusing_on_record* a_12798 = (struct Cn_hyp_allocator_focusing_on_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_focusing_on_record));
  a_12798->ha = ha;
  a_12798->lseg = lseg;
  return a_12798;
}

struct Cn_hyp_allocator_record* Cn_hyp_allocator(cn_pointer* p, enum spec_mode spec_mode)
{
  update_cn_error_message_info("  take ha = Cn_hyp_allocator_only(p);\n       ^alloc.pp.c:905:8:");
  struct Cn_hyp_allocator_only_record* ha = Cn_hyp_allocator_only(p, spec_mode);
  cn_pop_msg_info();
  cn_bits_u64* end;
  end = cn_bits_u64_add(ha->start, cast_cn_bits_u32_to_cn_bits_u64(ha->size));
  update_cn_error_message_info("  assert(ha.start < end);  // no overflow\n  ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:907:3-909:31");
  cn_assert(cn_bits_u64_lt(ha->start, end), spec_mode);
  cn_pop_msg_info();
  update_cn_error_message_info("  take hdrs = Cn_chunk_hdrs(ha.first, ha.head, ha, ha.head);\n       ^alloc.pp.c:908:8:");
  struct cn_chunk_hdrs* hdrs = Cn_chunk_hdrs(ha->first, ha->head, ha, ha->head, spec_mode);
  cn_pop_msg_info();
  struct Cn_hyp_allocator_record* a_12812 = (struct Cn_hyp_allocator_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_record));
  a_12812->ha = ha;
  a_12812->hdrs = hdrs;
  return a_12812;
}

struct chunk_hdr_option* MaybeChunkHdr(cn_pointer* chunk, cn_bool* condition, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(condition)) {
    update_cn_error_message_info("                take v = RW<struct chunk_hdr>(chunk);\n                     ^alloc.pp.c:1330:22:");
    struct chunk_hdr_cn* v = owned_struct_chunk_hdr(chunk, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
    cn_assert(convert_to_cn_bool(true), spec_mode);
    cn_pop_msg_info();
    struct chunk_hdr_option* a_12819 = (struct chunk_hdr_option*) cn_bump_malloc(sizeof(struct chunk_hdr_option));
    a_12819->tag = CHUNKHDR_SOME;
    a_12819->u.chunkhdr_some = (struct chunkhdr_some*) cn_bump_malloc(sizeof(struct chunkhdr_some));
    a_12819->u.chunkhdr_some->hdr = v;
    return a_12819;
  }
  else {
    struct chunk_hdr_option* a_12822 = (struct chunk_hdr_option*) cn_bump_malloc(sizeof(struct chunk_hdr_option));
    a_12822->tag = CHUNKHDR_NONE;
    return a_12822;
  }
}

struct Cn_hyp_allocator_only_record* ChunkInstallPre(cn_pointer* chunk, cn_bits_u64* size, cn_pointer* prev, cn_pointer* allocator, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(is_null(prev))) {
    update_cn_error_message_info("        take a_in=Cn_hyp_allocator(allocator);\n             ^alloc.pp.c:1344:14:");
    struct Cn_hyp_allocator_record* a_in = Cn_hyp_allocator(allocator, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("        assert(a_in.hdrs==Chunk_nil{});\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1345:9-1346:23");
    struct cn_chunk_hdrs* a_12829 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12829->tag = CHUNK_NIL;
    cn_assert(struct_cn_chunk_hdrs_equality(a_in->hdrs, a_12829), spec_mode);
    cn_pop_msg_info();
    return a_in->ha;
  }
  else {
    update_cn_error_message_info("        take HA_pre = Cn_hyp_allocator_focusing_on(allocator, prev);\n             ^alloc.pp.c:1350:14:");
    struct Cn_hyp_allocator_focusing_on_record* HA_pre = Cn_hyp_allocator_focusing_on(allocator, prev, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("        take Chunk = Own_chunk_hdr(chunk);\n             ^alloc.pp.c:1351:14:");
    struct chunk_hdr_only_cn* Chunk = Own_chunk_hdr(chunk, spec_mode);
    cn_pop_msg_info();
    cn_bits_u64* allocator_end;
    allocator_end = cn_bits_u64_add(cast_cn_bits_u64_to_cn_bits_u64(HA_pre->ha->start), cast_cn_bits_u32_to_cn_bits_u64(HA_pre->ha->size));
    update_cn_error_message_info("        assert(HA_pre.ha.start <= (u64)chunk && (u64)chunk < allocator_end);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1354:9-1355:25");
    cn_assert(cn_bool_and(cn_bits_u64_le(HA_pre->ha->start, cast_cn_pointer_to_cn_bits_u64(chunk)), cn_bits_u64_lt(cast_cn_pointer_to_cn_bits_u64(chunk), allocator_end)), spec_mode);
    cn_pop_msg_info();
    return HA_pre->ha;
  }
}

cn_bool* ChunkInstallPost(cn_pointer* chunk, cn_bits_u64* size, cn_pointer* prev, cn_pointer* allocator, struct Cn_hyp_allocator_only_record* ha_pre, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(is_null(prev))) {
    update_cn_error_message_info("        take HA_post =Cn_hyp_allocator_focusing_on(allocator, chunk);\n             ^alloc.pp.c:1362:14:");
    struct Cn_hyp_allocator_focusing_on_record* HA_post = Cn_hyp_allocator_focusing_on(allocator, chunk, spec_mode);
    cn_pop_msg_info();
    cn_bits_u64* allocator_end;
    allocator_end = cn_bits_u64_add(cast_cn_bits_u64_to_cn_bits_u64(ha_pre->start), cast_cn_bits_u32_to_cn_bits_u64(ha_pre->size));
    struct a_9481_record* first_chunk;
    struct a_9481_record* a_12879 = (struct a_9481_record*) cn_bump_malloc(sizeof(struct a_9481_record));
    a_12879->alloc_size = cast_cn_bits_u64_to_cn_bits_u32(size);
    a_12879->header_address = cast_cn_pointer_to_cn_bits_u64(chunk);
    a_12879->mapped_size = cast_cn_bits_u64_to_cn_bits_u32(PAGE_ALIGN(Cn_chunk_size(size)));
    a_12879->va_size = cast_cn_bits_u64_to_cn_bits_u32(cn_bits_u64_sub(allocator_end, cast_cn_pointer_to_cn_bits_u64(chunk)));
    first_chunk = a_12879;
    update_cn_error_message_info("        assert(HA_post.lseg.after == Chunk_nil {});\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1370:9-1373:20");
    struct cn_chunk_hdrs* a_12896 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12896->tag = CHUNK_NIL;
    cn_assert(struct_cn_chunk_hdrs_equality(HA_post->lseg->after, a_12896), spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("        assert(HA_post.lseg.chunk == first_chunk);\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1371:9-1373:20");
    cn_assert(struct_a_9481_record_equality(HA_post->lseg->chunk, first_chunk), spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("        assert(HA_post.lseg.before == Chunk_nil {} );\n        ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ alloc.pp.c:1372:9-1373:20");
    struct cn_chunk_hdrs* a_12905 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12905->tag = CHUNK_NIL;
    cn_assert(struct_cn_chunk_hdrs_equality(HA_post->lseg->before, a_12905), spec_mode);
    cn_pop_msg_info();
    return convert_to_cn_bool(true);
  }
  else {
    return convert_to_cn_bool(true);
  }
}

cn_bool* SetupFirstChunk(cn_pointer* allocator, struct Cn_hyp_allocator_only_record* ha_pre, cn_bits_u64* size, cn_bits_i32* ret, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(cn_bits_i32_equality(ret, convert_to_cn_bits_i32(0LL)))) {
    cn_pointer* start;
    start = cast_cn_bits_u64_to_cn_pointer(ha_pre->start);
    update_cn_error_message_info("        take a_out=Cn_hyp_allocator_focusing_on(allocator, start);\n             ^alloc.pp.c:1871:14:");
    struct Cn_hyp_allocator_focusing_on_record* a_out = Cn_hyp_allocator_focusing_on(allocator, start, spec_mode);
    cn_pop_msg_info();
    cn_pointer* chunk_data;
    chunk_data = cn_array_shift(start, sizeof(unsigned char), Cn_chunk_hdr_size());
    update_cn_error_message_info("        take D = Cn_char_array(chunk_data, (u64)a_out.lseg.chunk.alloc_size);\n             ^alloc.pp.c:1874:14:");
    Cn_char_array(chunk_data, cast_cn_bits_u32_to_cn_bits_u64(a_out->lseg->chunk->alloc_size), spec_mode);
    cn_pop_msg_info();
    struct cn_chunk_hdrs* a_12932 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12932->tag = CHUNK_NIL;
    struct cn_chunk_hdrs* a_12949 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12949->tag = CHUNK_NIL;
    return cn_bool_and(cn_bool_and(cn_bool_and(struct_cn_chunk_hdrs_equality(a_out->lseg->before, a_12932), cn_bits_u64_equality(a_out->lseg->chunk->header_address, cast_cn_pointer_to_cn_bits_u64(start))), cn_bits_u64_lt(size, cast_cn_bits_u32_to_cn_bits_u64(a_out->lseg->chunk->alloc_size))), struct_cn_chunk_hdrs_equality(a_out->lseg->after, a_12949));
  }
  else {
    update_cn_error_message_info("        take a_out=Cn_hyp_allocator(allocator);\n             ^alloc.pp.c:1880:14:");
    struct Cn_hyp_allocator_record* a_out = Cn_hyp_allocator(allocator, spec_mode);
    cn_pop_msg_info();
    struct cn_chunk_hdrs* a_12964 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12964->tag = CHUNK_NIL;
    return cn_bool_and(struct_Cn_hyp_allocator_only_record_equality(a_out->ha, ha_pre), struct_cn_chunk_hdrs_equality(a_out->hdrs, a_12964));
  }
}

cn_bool* GetFreeChunk(cn_pointer* allocator, cn_bits_u64* size, cn_pointer* result, struct Cn_hyp_allocator_record* HA_in, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(ptr_eq(result, convert_to_cn_pointer(NULL)))) {
    update_cn_error_message_info("                take HA_out = Cn_hyp_allocator(allocator);\n                     ^alloc.pp.c:1918:22:");
    struct Cn_hyp_allocator_record* HA_out = Cn_hyp_allocator(allocator, spec_mode);
    cn_pop_msg_info();
    return struct_Cn_hyp_allocator_record_equality(HA_in, HA_out);
  }
  else {
    update_cn_error_message_info("                take HA_out = Cn_hyp_allocator_focusing_on(allocator, result);\n                     ^alloc.pp.c:1921:22:");
    struct Cn_hyp_allocator_focusing_on_record* HA_out = Cn_hyp_allocator_focusing_on(allocator, result, spec_mode);
    cn_pop_msg_info();
    struct a_9487_record* lseg;
    lseg = HA_out->lseg;
    struct cn_chunk_hdrs* a_12986 = (struct cn_chunk_hdrs*) cn_bump_malloc(sizeof(struct cn_chunk_hdrs));
    a_12986->tag = CHUNK_CONS;
    a_12986->u.chunk_cons = (struct chunk_cons*) cn_bump_malloc(sizeof(struct chunk_cons));
    a_12986->u.chunk_cons->hd = lseg->chunk;
    a_12986->u.chunk_cons->tl = lseg->after;
    struct Cn_hyp_allocator_record* a_12985 = (struct Cn_hyp_allocator_record*) cn_bump_malloc(sizeof(struct Cn_hyp_allocator_record));
    a_12985->ha = HA_out->ha;
    a_12985->hdrs = ConcatChunkList(lseg->before, a_12986);
    return cn_bool_and(is_free_chunk(lseg->chunk, cast_cn_bits_u64_to_cn_bits_u32(size)), struct_Cn_hyp_allocator_record_equality(a_12985, HA_in));
  }
}

void Cn_char_array(cn_pointer* p, cn_bits_u64* size, enum spec_mode spec_mode)
{
  update_cn_error_message_info("        take U = each(u64 i; i < size){\n             ^alloc.pp.c:1995:14:");
  cn_map* U = map_create();
  {
    cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL));
    while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL)), i), cn_bits_u64_lt(i, size)))) {
      if (convert_from_cn_bool(cn_bits_u64_lt(i, size))) {
        cn_pointer* a_13015 = cn_array_shift(p, sizeof(char), i);
        cn_map_set(U, cast_cn_bits_u64_to_cn_integer(i), owned_char(a_13015, spec_mode));
      }
      else {
        ;
      }
      cn_bits_u64_increment(i);
    }
  }
  cn_pop_msg_info();
  update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
  cn_assert(convert_to_cn_bool(true), spec_mode);
  cn_pop_msg_info();
  return;
}

void Conditional_Cn_char_array(cn_pointer* p, cn_bits_u64* size, cn_bool* cond, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(cond)) {
    update_cn_error_message_info("                take U = each(u64 i; i < size){\n                     ^alloc.pp.c:2004:22:");
    cn_map* U = map_create();
    {
      cn_bits_u64* i = cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL));
      while (convert_from_cn_bool(cn_bool_and(cn_bits_u64_le(cast_cn_bits_u64_to_cn_bits_u64(convert_to_cn_bits_u64(0ULL)), i), cn_bits_u64_lt(i, size)))) {
        if (convert_from_cn_bool(cn_bits_u64_lt(i, size))) {
          cn_pointer* a_13052 = cn_array_shift(p, sizeof(char), i);
          cn_map_set(U, cast_cn_bits_u64_to_cn_integer(i), owned_char(a_13052, spec_mode));
        }
        else {
          ;
        }
        cn_bits_u64_increment(i);
      }
    }
    cn_pop_msg_info();
    update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
    cn_assert(convert_to_cn_bool(true), spec_mode);
    cn_pop_msg_info();
    return;
  }
  else {
    return;
  }
}

void MaybeCn_char_array(cn_pointer* p, cn_bits_u64* size, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(ptr_eq(p, convert_to_cn_pointer(NULL)))) {
    return;
  }
  else {
    update_cn_error_message_info("                take U = Cn_char_array(p, size);\n                     ^alloc.pp.c:2019:22:");
    Cn_char_array(p, size, spec_mode);
    cn_pop_msg_info();
    return;
  }
}

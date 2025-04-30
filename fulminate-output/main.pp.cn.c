#include "main.pp.cn.h"


/* GENERATED STRUCT FUNCTIONS */

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

struct __cerbty_unnamed_tag_742_cn* convert_to_struct___cerbty_unnamed_tag_742_cn(struct __cerbty_unnamed_tag_742 __cerbty_unnamed_tag_742)
{
  struct __cerbty_unnamed_tag_742_cn* res = (struct __cerbty_unnamed_tag_742_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_742_cn));
  res->__dummy_max_align_t = convert_to_cn_pointer(__cerbty_unnamed_tag_742.__dummy_max_align_t);
  return res;
}

struct __cerbty_unnamed_tag_774_cn* convert_to_struct___cerbty_unnamed_tag_774_cn(struct __cerbty_unnamed_tag_774 __cerbty_unnamed_tag_774)
{
  struct __cerbty_unnamed_tag_774_cn* res = (struct __cerbty_unnamed_tag_774_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_774_cn));
  res->quot = convert_to_cn_bits_i64(__cerbty_unnamed_tag_774.quot);
  res->rem = convert_to_cn_bits_i64(__cerbty_unnamed_tag_774.rem);
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

struct __cerbty_unnamed_tag_742 convert_from_struct___cerbty_unnamed_tag_742_cn(struct __cerbty_unnamed_tag_742_cn* __cerbty_unnamed_tag_742)
{
  struct __cerbty_unnamed_tag_742 res;
  res.__dummy_max_align_t = convert_from_cn_pointer(__cerbty_unnamed_tag_742->__dummy_max_align_t);
  return res;
}

struct __cerbty_unnamed_tag_774 convert_from_struct___cerbty_unnamed_tag_774_cn(struct __cerbty_unnamed_tag_774_cn* __cerbty_unnamed_tag_774)
{
  struct __cerbty_unnamed_tag_774 res;
  res.quot = convert_from_cn_bits_i64(__cerbty_unnamed_tag_774->quot);
  res.rem = convert_from_cn_bits_i64(__cerbty_unnamed_tag_774->rem);
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

cn_bool* struct___cerbty_unnamed_tag_742_cn_equality(void* x, void* y)
{
  struct __cerbty_unnamed_tag_742_cn* x_cast = (struct __cerbty_unnamed_tag_742_cn*) x;
  struct __cerbty_unnamed_tag_742_cn* y_cast = (struct __cerbty_unnamed_tag_742_cn*) y;
  return cn_bool_and(convert_to_cn_bool(true), cn_pointer_equality(x_cast->__dummy_max_align_t, y_cast->__dummy_max_align_t));
}

cn_bool* struct___cerbty_unnamed_tag_774_cn_equality(void* x, void* y)
{
  struct __cerbty_unnamed_tag_774_cn* x_cast = (struct __cerbty_unnamed_tag_774_cn*) x;
  struct __cerbty_unnamed_tag_774_cn* y_cast = (struct __cerbty_unnamed_tag_774_cn*) y;
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
      struct list_head_some* a_3782 = x->u.list_head_some;
      struct list_head_some* a_3783 = y->u.list_head_some;
      return cn_bool_and(struct_list_head_cn_equality(a_3782->L, a_3783->L), convert_to_cn_bool(1));
    }
  }
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

void* cn_map_get_struct___cerbty_unnamed_tag_742_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct___cerbty_unnamed_tag_742_cn();
  else
    return ret;
}

void* cn_map_get_struct___cerbty_unnamed_tag_774_cn(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct___cerbty_unnamed_tag_774_cn();
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

struct div_cn* default_struct_div_cn()
{
  struct div_cn* a_3857 = (struct div_cn*) cn_bump_malloc(sizeof(struct div_cn));
  a_3857->quot = default_cn_bits_i32();
  a_3857->rem = default_cn_bits_i32();
  return a_3857;
}

struct ldiv_cn* default_struct_ldiv_cn()
{
  struct ldiv_cn* a_3864 = (struct ldiv_cn*) cn_bump_malloc(sizeof(struct ldiv_cn));
  a_3864->quot = default_cn_bits_i64();
  a_3864->rem = default_cn_bits_i64();
  return a_3864;
}

struct lldiv_cn* default_struct_lldiv_cn()
{
  struct lldiv_cn* a_3871 = (struct lldiv_cn*) cn_bump_malloc(sizeof(struct lldiv_cn));
  a_3871->quot = default_cn_bits_i64();
  a_3871->rem = default_cn_bits_i64();
  return a_3871;
}

struct __cerbty_unnamed_tag_742_cn* default_struct___cerbty_unnamed_tag_742_cn()
{
  struct __cerbty_unnamed_tag_742_cn* a_3878 = (struct __cerbty_unnamed_tag_742_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_742_cn));
  a_3878->__dummy_max_align_t = default_cn_pointer();
  return a_3878;
}

struct __cerbty_unnamed_tag_774_cn* default_struct___cerbty_unnamed_tag_774_cn()
{
  struct __cerbty_unnamed_tag_774_cn* a_3883 = (struct __cerbty_unnamed_tag_774_cn*) cn_bump_malloc(sizeof(struct __cerbty_unnamed_tag_774_cn));
  a_3883->quot = default_cn_bits_i64();
  a_3883->rem = default_cn_bits_i64();
  return a_3883;
}

struct list_head_cn* default_struct_list_head_cn()
{
  struct list_head_cn* a_3890 = (struct list_head_cn*) cn_bump_malloc(sizeof(struct list_head_cn));
  a_3890->next = default_cn_pointer();
  a_3890->prev = default_cn_pointer();
  return a_3890;
}

struct kvm_hyp_memcache_cn* default_struct_kvm_hyp_memcache_cn()
{
  struct kvm_hyp_memcache_cn* a_3897 = (struct kvm_hyp_memcache_cn*) cn_bump_malloc(sizeof(struct kvm_hyp_memcache_cn));
  a_3897->head = default_cn_bits_u64();
  a_3897->nr_pages = default_cn_bits_u64();
  a_3897->flags = default_cn_bits_u64();
  return a_3897;
}

void* cn_map_get_struct_list_head_option(cn_map* m, cn_integer* key)
{
  void* ret = ht_get(m, (&key->val));
  if (0 == ret)
    return (void*) default_struct_list_head_option();
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

/* OWNERSHIP FUNCTIONS */

struct list_head_cn* owned_struct_list_head(cn_pointer* cn_ptr, enum spec_mode spec_mode)
{
  uintptr_t generic_c_ptr = (uintptr_t) (struct list_head*) cn_ptr->ptr;
  cn_get_or_put_ownership(spec_mode, generic_c_ptr, sizeof(struct list_head));
  return convert_to_struct_list_head_cn((*(struct list_head*) cn_ptr->ptr));
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


/* CN PREDICATES */

struct list_head_option* CondListHead(cn_pointer* p, cn_bool* condition, enum spec_mode spec_mode)
{
  if (convert_from_cn_bool(condition)) {
    update_cn_error_message_info("				take L = RW<struct list_head>(p);\n         ^main.pp.c:135:10:");
    struct list_head_cn* L = owned_struct_list_head(p, spec_mode);
    cn_pop_msg_info();
    update_cn_error_message_info("other_location(File 'lib/compile.ml', line 1118, characters 31-38)");
    cn_assert(convert_to_cn_bool(true), spec_mode);
    cn_pop_msg_info();
    struct list_head_option* a_3546 = (struct list_head_option*) cn_bump_malloc(sizeof(struct list_head_option));
    a_3546->tag = LIST_HEAD_SOME;
    a_3546->u.list_head_some = (struct list_head_some*) cn_bump_malloc(sizeof(struct list_head_some));
    a_3546->u.list_head_some->L = L;
    return a_3546;
  }
  else {
    struct list_head_option* a_3549 = (struct list_head_option*) cn_bump_malloc(sizeof(struct list_head_option));
    a_3549->tag = LIST_HEAD_NONE;
    return a_3549;
  }
}

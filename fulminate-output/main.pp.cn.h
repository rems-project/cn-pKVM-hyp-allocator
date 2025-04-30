#ifndef CN_HEADER
#define CN_HEADER
#include <cn-executable/utils.h>






/* ORIGINAL C STRUCTS */

struct div {
  signed int quot;
  signed int rem;
};

struct ldiv {
  signed long quot;
  signed long rem;
};

struct lldiv {
  signed long long quot;
  signed long long rem;
};

struct __cerbty_unnamed_tag_742 {
  _Alignas(8) void* __dummy_max_align_t;
};

struct __cerbty_unnamed_tag_774 {
  intmax_t quot;
  intmax_t rem;
};

struct list_head {
  struct list_head* next;
  struct list_head* prev;
};

struct kvm_hyp_memcache {
  unsigned long long head;
  unsigned long nr_pages;
  unsigned long flags;
};



/* CN VERSIONS OF C STRUCTS */

struct div_cn {
  cn_bits_i32* quot;
  cn_bits_i32* rem;
};

struct ldiv_cn {
  cn_bits_i64* quot;
  cn_bits_i64* rem;
};

struct lldiv_cn {
  cn_bits_i64* quot;
  cn_bits_i64* rem;
};

struct __cerbty_unnamed_tag_742_cn {
  _Alignas(8) cn_pointer* __dummy_max_align_t;
};

struct __cerbty_unnamed_tag_774_cn {
  cn_bits_i64* quot;
  cn_bits_i64* rem;
};

struct list_head_cn {
  cn_pointer* next;
  cn_pointer* prev;
};

struct kvm_hyp_memcache_cn {
  cn_bits_u64* head;
  cn_bits_u64* nr_pages;
  cn_bits_u64* flags;
};



/* CN DATATYPES */


enum list_head_option_tag {
  LIST_HEAD_NONE,
  LIST_HEAD_SOME
};

struct cn_datatype {
  signed int tag;
  struct cntype* cntype;
};

struct cntype {
  ;
};

struct list_head_none {
  ;
};

struct list_head_some {
  struct list_head_cn* L;
};

union list_head_option_union {
  struct list_head_none* list_head_none;
  struct list_head_some* list_head_some;
};

struct list_head_option {
  enum list_head_option_tag tag;
  struct cntype* cntype;
  union list_head_option_union u;
};




/* OWNERSHIP FUNCTIONS */


struct list_head_cn* owned_struct_list_head(cn_pointer*, enum spec_mode);


/* GENERATED STRUCT FUNCTIONS */

struct div_cn* convert_to_struct_div_cn(struct div);

struct ldiv_cn* convert_to_struct_ldiv_cn(struct ldiv);

struct lldiv_cn* convert_to_struct_lldiv_cn(struct lldiv);

struct __cerbty_unnamed_tag_742_cn* convert_to_struct___cerbty_unnamed_tag_742_cn(struct __cerbty_unnamed_tag_742);

struct __cerbty_unnamed_tag_774_cn* convert_to_struct___cerbty_unnamed_tag_774_cn(struct __cerbty_unnamed_tag_774);

struct list_head_cn* convert_to_struct_list_head_cn(struct list_head);

struct kvm_hyp_memcache_cn* convert_to_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache);

struct div convert_from_struct_div_cn(struct div_cn*);

struct ldiv convert_from_struct_ldiv_cn(struct ldiv_cn*);

struct lldiv convert_from_struct_lldiv_cn(struct lldiv_cn*);

struct __cerbty_unnamed_tag_742 convert_from_struct___cerbty_unnamed_tag_742_cn(struct __cerbty_unnamed_tag_742_cn*);

struct __cerbty_unnamed_tag_774 convert_from_struct___cerbty_unnamed_tag_774_cn(struct __cerbty_unnamed_tag_774_cn*);

struct list_head convert_from_struct_list_head_cn(struct list_head_cn*);

struct kvm_hyp_memcache convert_from_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache_cn*);

cn_bool* struct_div_cn_equality(void*, void*);

cn_bool* struct_ldiv_cn_equality(void*, void*);

cn_bool* struct_lldiv_cn_equality(void*, void*);

cn_bool* struct___cerbty_unnamed_tag_742_cn_equality(void*, void*);

cn_bool* struct___cerbty_unnamed_tag_774_cn_equality(void*, void*);

cn_bool* struct_list_head_cn_equality(void*, void*);

cn_bool* struct_kvm_hyp_memcache_cn_equality(void*, void*);

cn_bool* struct_list_head_option_equality(struct list_head_option*, struct list_head_option*);

void* cn_map_get_struct_div_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_ldiv_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_lldiv_cn(cn_map*, cn_integer*);

void* cn_map_get_struct___cerbty_unnamed_tag_742_cn(cn_map*, cn_integer*);

void* cn_map_get_struct___cerbty_unnamed_tag_774_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_list_head_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_kvm_hyp_memcache_cn(cn_map*, cn_integer*);

struct div_cn* default_struct_div_cn();

struct ldiv_cn* default_struct_ldiv_cn();

struct lldiv_cn* default_struct_lldiv_cn();

struct __cerbty_unnamed_tag_742_cn* default_struct___cerbty_unnamed_tag_742_cn();

struct __cerbty_unnamed_tag_774_cn* default_struct___cerbty_unnamed_tag_774_cn();

struct list_head_cn* default_struct_list_head_cn();

struct kvm_hyp_memcache_cn* default_struct_kvm_hyp_memcache_cn();

void* cn_map_get_struct_list_head_option(cn_map*, cn_integer*);

struct list_head_option* default_struct_list_head_option();



/* CN FUNCTIONS */

cn_bits_i64* MAXi64();

cn_bits_i64* MINi64();

cn_bits_i32* MAXi32();

cn_bits_i32* MINi32();

cn_bits_i16* MAXi16();

cn_bits_i16* MINi16();

cn_bits_i8* MAXi8();

cn_bits_i8* MINi8();

cn_bits_u64* MAXu64();

cn_bits_u64* MINu64();

cn_bits_u32* MAXu32();

cn_bits_u32* MINu32();

cn_bits_u16* MAXu16();

cn_bits_u16* MINu16();

cn_bits_u8* MAXu8();

cn_bits_u8* MINu8();

cn_bool* not(cn_bool*);

cn_bool* is_null(cn_pointer*);

cn_bool* ptr_eq(cn_pointer*, cn_pointer*);

cn_bool* prov_eq(cn_pointer*, cn_pointer*);

cn_bool* addr_eq(cn_pointer*, cn_pointer*);

cn_bits_i32* EINVAL();

cn_bool* list_add_aux(struct list_head_cn*, struct list_head_cn*, struct list_head_cn*, cn_pointer*, cn_pointer*, cn_pointer*);

cn_bits_u64* PAGE_ALIGN_DOWN(cn_bits_u64*);

cn_bits_u64* PAGE_ALIGN(cn_bits_u64*);



struct list_head_option* CondListHead(cn_pointer*, cn_bool*, enum spec_mode);

#endif
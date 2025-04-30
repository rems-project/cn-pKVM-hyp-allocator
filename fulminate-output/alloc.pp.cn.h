#ifndef CN_HEADER
#define CN_HEADER
#include <cn-executable/utils.h>




/* CN RECORDS */


struct Cn_chunk_hdr_record {
  struct a_9481_record* Hdr;
  struct list_head_cn* Node;
};
struct a_9487_record {
  struct cn_chunk_hdrs* after;
  struct cn_chunk_hdrs* before;
  struct a_9481_record* chunk;
};
struct a_9481_record {
  cn_bits_u32* alloc_size;
  cn_bits_u64* header_address;
  cn_bits_u32* mapped_size;
  cn_bits_u32* va_size;
};
struct Cn_hyp_allocator_only_record {
  cn_pointer* first;
  cn_pointer* head;
  cn_pointer* last;
  cn_bits_u32* size;
  cn_bits_u64* start;
};
struct Cn_hyp_allocator_record {
  struct Cn_hyp_allocator_only_record* ha;
  struct cn_chunk_hdrs* hdrs;
};
struct Cn_hyp_allocator_focusing_on_record {
  struct Cn_hyp_allocator_only_record* ha;
  struct a_9487_record* lseg;
};
struct Cn_chunk_hdrs_non_last_record {
  struct a_9481_record* hd;
  struct cn_chunk_hdrs* tl;
};


/* ORIGINAL C STRUCTS */

struct __cerbty_unnamed_tag_683 {
  _Alignas(8) void* __dummy_max_align_t;
};

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

struct __cerbty_unnamed_tag_813 {
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

struct hyp_allocator {
  struct list_head chunks;
  unsigned long start;
  unsigned int size;
  unsigned long long lock;
};

struct chunk_hdr {
  unsigned int alloc_size;
  unsigned int mapped_size;
  struct list_head node;
  unsigned int hash;
  char data;
};

struct chunk_hdr_only {
  unsigned int alloc_size;
  unsigned int mapped_size;
  struct list_head node;
  unsigned int hash;
};



/* CN VERSIONS OF C STRUCTS */

struct __cerbty_unnamed_tag_683_cn {
  _Alignas(8) cn_pointer* __dummy_max_align_t;
};

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

struct __cerbty_unnamed_tag_813_cn {
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

struct hyp_allocator_cn {
  struct list_head_cn* chunks;
  cn_bits_u64* start;
  cn_bits_u32* size;
  cn_bits_u64* lock;
};

struct chunk_hdr_cn {
  cn_bits_u32* alloc_size;
  cn_bits_u32* mapped_size;
  struct list_head_cn* node;
  cn_bits_u32* hash;
  cn_bits_u8* data;
};

struct chunk_hdr_only_cn {
  cn_bits_u32* alloc_size;
  cn_bits_u32* mapped_size;
  struct list_head_cn* node;
  cn_bits_u32* hash;
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


enum cn_chunk_hdrs_tag {
  CHUNK_NIL,
  CHUNK_CONS
};

struct chunk_nil {
  ;
};

struct chunk_cons {
  struct cn_chunk_hdrs* tl;
  struct a_9481_record* hd;
};

union cn_chunk_hdrs_union {
  struct chunk_nil* chunk_nil;
  struct chunk_cons* chunk_cons;
};

struct cn_chunk_hdrs {
  enum cn_chunk_hdrs_tag tag;
  struct cntype* cntype;
  union cn_chunk_hdrs_union u;
};


enum cn_chunk_hdr_option_tag {
  CHUNK_NONE,
  CHUNK_SOME
};

struct chunk_none {
  ;
};

struct chunk_some {
  struct a_9481_record* hdr;
};

union cn_chunk_hdr_option_union {
  struct chunk_none* chunk_none;
  struct chunk_some* chunk_some;
};

struct cn_chunk_hdr_option {
  enum cn_chunk_hdr_option_tag tag;
  struct cntype* cntype;
  union cn_chunk_hdr_option_union u;
};


enum chunk_hdr_option_tag {
  CHUNKHDR_NONE,
  CHUNKHDR_SOME
};

struct chunkhdr_none {
  ;
};

struct chunkhdr_some {
  struct chunk_hdr_cn* hdr;
};

union chunk_hdr_option_union {
  struct chunkhdr_none* chunkhdr_none;
  struct chunkhdr_some* chunkhdr_some;
};

struct chunk_hdr_option {
  enum chunk_hdr_option_tag tag;
  struct cntype* cntype;
  union chunk_hdr_option_union u;
};




/* OWNERSHIP FUNCTIONS */


cn_bits_u8* owned_char(cn_pointer*, enum spec_mode);

struct chunk_hdr_cn* owned_struct_chunk_hdr(cn_pointer*, enum spec_mode);

struct chunk_hdr_only_cn* owned_struct_chunk_hdr_only(cn_pointer*, enum spec_mode);

struct hyp_allocator_cn* owned_struct_hyp_allocator(cn_pointer*, enum spec_mode);

struct list_head_cn* owned_struct_list_head(cn_pointer*, enum spec_mode);

cn_bits_u64* owned_size_t(cn_pointer*, enum spec_mode);

cn_pointer* owned_struct_hyp_allocator_pointer(cn_pointer*, enum spec_mode);

cn_pointer* owned_struct_chunk_hdr_pointer(cn_pointer*, enum spec_mode);

cn_bits_u32* owned_unsigned_int(cn_pointer*, enum spec_mode);

cn_pointer* owned_unsigned_long_long_pointer(cn_pointer*, enum spec_mode);


/* GENERATED STRUCT FUNCTIONS */

struct __cerbty_unnamed_tag_683_cn* convert_to_struct___cerbty_unnamed_tag_683_cn(struct __cerbty_unnamed_tag_683);

struct div_cn* convert_to_struct_div_cn(struct div);

struct ldiv_cn* convert_to_struct_ldiv_cn(struct ldiv);

struct lldiv_cn* convert_to_struct_lldiv_cn(struct lldiv);

struct __cerbty_unnamed_tag_813_cn* convert_to_struct___cerbty_unnamed_tag_813_cn(struct __cerbty_unnamed_tag_813);

struct list_head_cn* convert_to_struct_list_head_cn(struct list_head);

struct kvm_hyp_memcache_cn* convert_to_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache);

struct hyp_allocator_cn* convert_to_struct_hyp_allocator_cn(struct hyp_allocator);

struct chunk_hdr_cn* convert_to_struct_chunk_hdr_cn(struct chunk_hdr);

struct chunk_hdr_only_cn* convert_to_struct_chunk_hdr_only_cn(struct chunk_hdr_only);

struct __cerbty_unnamed_tag_683 convert_from_struct___cerbty_unnamed_tag_683_cn(struct __cerbty_unnamed_tag_683_cn*);

struct div convert_from_struct_div_cn(struct div_cn*);

struct ldiv convert_from_struct_ldiv_cn(struct ldiv_cn*);

struct lldiv convert_from_struct_lldiv_cn(struct lldiv_cn*);

struct __cerbty_unnamed_tag_813 convert_from_struct___cerbty_unnamed_tag_813_cn(struct __cerbty_unnamed_tag_813_cn*);

struct list_head convert_from_struct_list_head_cn(struct list_head_cn*);

struct kvm_hyp_memcache convert_from_struct_kvm_hyp_memcache_cn(struct kvm_hyp_memcache_cn*);

struct hyp_allocator convert_from_struct_hyp_allocator_cn(struct hyp_allocator_cn*);

struct chunk_hdr convert_from_struct_chunk_hdr_cn(struct chunk_hdr_cn*);

struct chunk_hdr_only convert_from_struct_chunk_hdr_only_cn(struct chunk_hdr_only_cn*);

cn_bool* struct___cerbty_unnamed_tag_683_cn_equality(void*, void*);

cn_bool* struct_div_cn_equality(void*, void*);

cn_bool* struct_ldiv_cn_equality(void*, void*);

cn_bool* struct_lldiv_cn_equality(void*, void*);

cn_bool* struct___cerbty_unnamed_tag_813_cn_equality(void*, void*);

cn_bool* struct_list_head_cn_equality(void*, void*);

cn_bool* struct_kvm_hyp_memcache_cn_equality(void*, void*);

cn_bool* struct_hyp_allocator_cn_equality(void*, void*);

cn_bool* struct_chunk_hdr_cn_equality(void*, void*);

cn_bool* struct_chunk_hdr_only_cn_equality(void*, void*);

cn_bool* struct_list_head_option_equality(struct list_head_option*, struct list_head_option*);

cn_bool* struct_cn_chunk_hdrs_equality(struct cn_chunk_hdrs*, struct cn_chunk_hdrs*);

cn_bool* struct_cn_chunk_hdr_option_equality(struct cn_chunk_hdr_option*, struct cn_chunk_hdr_option*);

cn_bool* struct_chunk_hdr_option_equality(struct chunk_hdr_option*, struct chunk_hdr_option*);

void* cn_map_get_struct___cerbty_unnamed_tag_683_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_div_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_ldiv_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_lldiv_cn(cn_map*, cn_integer*);

void* cn_map_get_struct___cerbty_unnamed_tag_813_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_list_head_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_kvm_hyp_memcache_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_hyp_allocator_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_chunk_hdr_cn(cn_map*, cn_integer*);

void* cn_map_get_struct_chunk_hdr_only_cn(cn_map*, cn_integer*);

struct __cerbty_unnamed_tag_683_cn* default_struct___cerbty_unnamed_tag_683_cn();

struct div_cn* default_struct_div_cn();

struct ldiv_cn* default_struct_ldiv_cn();

struct lldiv_cn* default_struct_lldiv_cn();

struct __cerbty_unnamed_tag_813_cn* default_struct___cerbty_unnamed_tag_813_cn();

struct list_head_cn* default_struct_list_head_cn();

struct kvm_hyp_memcache_cn* default_struct_kvm_hyp_memcache_cn();

struct hyp_allocator_cn* default_struct_hyp_allocator_cn();

struct chunk_hdr_cn* default_struct_chunk_hdr_cn();

struct chunk_hdr_only_cn* default_struct_chunk_hdr_only_cn();

void* cn_map_get_struct_list_head_option(cn_map*, cn_integer*);

void* cn_map_get_struct_cn_chunk_hdrs(cn_map*, cn_integer*);

void* cn_map_get_struct_cn_chunk_hdr_option(cn_map*, cn_integer*);

void* cn_map_get_struct_chunk_hdr_option(cn_map*, cn_integer*);

struct list_head_option* default_struct_list_head_option();

struct cn_chunk_hdrs* default_struct_cn_chunk_hdrs();

struct cn_chunk_hdr_option* default_struct_cn_chunk_hdr_option();

struct chunk_hdr_option* default_struct_chunk_hdr_option();

cn_bool* struct_Cn_chunk_hdr_record_equality(void*, void*);
cn_bool* struct_a_9487_record_equality(void*, void*);
cn_bool* struct_a_9481_record_equality(void*, void*);
cn_bool* struct_Cn_hyp_allocator_only_record_equality(void*, void*);
cn_bool* struct_Cn_hyp_allocator_record_equality(void*, void*);
cn_bool* struct_Cn_hyp_allocator_focusing_on_record_equality(void*, void*);
cn_bool* struct_Cn_chunk_hdrs_non_last_record_equality(void*, void*);
struct Cn_chunk_hdr_record* default_struct_Cn_chunk_hdr_record();
struct a_9487_record* default_struct_a_9487_record();
struct a_9481_record* default_struct_a_9481_record();
struct Cn_hyp_allocator_only_record* default_struct_Cn_hyp_allocator_only_record();
struct Cn_hyp_allocator_record* default_struct_Cn_hyp_allocator_record();
struct Cn_hyp_allocator_focusing_on_record* default_struct_Cn_hyp_allocator_focusing_on_record();
struct Cn_chunk_hdrs_non_last_record* default_struct_Cn_chunk_hdrs_non_last_record();
void* cn_map_get_struct_Cn_chunk_hdr_record(cn_map*, cn_integer*);
void* cn_map_get_struct_a_9487_record(cn_map*, cn_integer*);
void* cn_map_get_struct_a_9481_record(cn_map*, cn_integer*);
void* cn_map_get_struct_Cn_hyp_allocator_only_record(cn_map*, cn_integer*);
void* cn_map_get_struct_Cn_hyp_allocator_record(cn_map*, cn_integer*);
void* cn_map_get_struct_Cn_hyp_allocator_focusing_on_record(cn_map*, cn_integer*);
void* cn_map_get_struct_Cn_chunk_hdrs_non_last_record(cn_map*, cn_integer*);

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

cn_bits_u64* MIN_ALLOC();

cn_bool* hash_change_only(struct chunk_hdr_cn*, struct chunk_hdr_cn*);

cn_bits_u64* Cn_chunk_hdr_size();

cn_bits_u64* Cn_chunk_size(cn_bits_u64*);

cn_pointer* Cn_chunk_data(struct chunk_hdr_cn*);

cn_pointer* my_container_of_chunk_hdr(cn_pointer*);

cn_bool* is_last_chunk(cn_pointer*, struct hyp_allocator_cn*);

cn_pointer* HeadOrValue(struct cn_chunk_hdrs*, cn_pointer*);

struct cn_chunk_hdrs* ConcatChunkList(struct cn_chunk_hdrs*, struct cn_chunk_hdrs*);

cn_bool* Is_chunk_some(struct cn_chunk_hdr_option*);

struct cn_chunk_hdr_option* lookup(cn_pointer*, struct cn_chunk_hdrs*);

struct cn_chunk_hdr_option* next_chunk(cn_pointer*, struct cn_chunk_hdrs*);

cn_bool* is_free_chunk(struct a_9481_record*, cn_bits_u32*);

cn_bits_u64* Cn_chunk_unmapped_region(cn_pointer*, struct chunk_hdr_cn*);

cn_bool* Cn_list_is_first(struct list_head_cn*, cn_pointer*);

cn_bool* Cn_list_is_last(struct list_head_cn*, cn_pointer*);

cn_pointer* Cn_chunk_get_next(struct chunk_hdr_cn*, cn_pointer*);

cn_bits_u32* Cn_chunk_unmapped_size(struct a_9481_record*);

cn_bool* chunk_list_insert_aux(struct Cn_hyp_allocator_only_record*, cn_pointer*, struct chunk_hdr_only_cn*, cn_pointer*, cn_bits_u64*);

cn_bool* chunk_install_sanity_check(cn_pointer*, cn_pointer*, struct chunk_hdr_cn*);



struct list_head_option* CondListHead(cn_pointer*, cn_bool*, enum spec_mode);

struct Cn_hyp_allocator_only_record* Cn_hyp_allocator_only(cn_pointer*, enum spec_mode);

struct chunk_hdr_only_cn* Own_chunk_hdr(cn_pointer*, enum spec_mode);

struct Cn_chunk_hdr_record* Cn_chunk_hdr(cn_pointer*, struct Cn_hyp_allocator_only_record*, enum spec_mode);

struct Cn_chunk_hdrs_non_last_record* Cn_chunk_hdrs_non_last(cn_pointer*, cn_pointer*, struct Cn_hyp_allocator_only_record*, cn_pointer*, enum spec_mode);

struct cn_chunk_hdrs* Cn_chunk_hdrs(cn_pointer*, cn_pointer*, struct Cn_hyp_allocator_only_record*, cn_pointer*, enum spec_mode);

struct cn_chunk_hdrs* Cn_chunk_hdrs_rev(cn_pointer*, cn_pointer*, struct Cn_hyp_allocator_only_record*, cn_pointer*, struct cn_chunk_hdrs*, enum spec_mode);

struct Cn_hyp_allocator_focusing_on_record* Cn_hyp_allocator_focusing_on(cn_pointer*, cn_pointer*, enum spec_mode);

struct Cn_hyp_allocator_record* Cn_hyp_allocator(cn_pointer*, enum spec_mode);

struct chunk_hdr_option* MaybeChunkHdr(cn_pointer*, cn_bool*, enum spec_mode);

struct Cn_hyp_allocator_only_record* ChunkInstallPre(cn_pointer*, cn_bits_u64*, cn_pointer*, cn_pointer*, enum spec_mode);

cn_bool* ChunkInstallPost(cn_pointer*, cn_bits_u64*, cn_pointer*, cn_pointer*, struct Cn_hyp_allocator_only_record*, enum spec_mode);

cn_bool* SetupFirstChunk(cn_pointer*, struct Cn_hyp_allocator_only_record*, cn_bits_u64*, cn_bits_i32*, enum spec_mode);

cn_bool* GetFreeChunk(cn_pointer*, cn_bits_u64*, cn_pointer*, struct Cn_hyp_allocator_record*, enum spec_mode);

void Cn_char_array(cn_pointer*, cn_bits_u64*, enum spec_mode);

void Conditional_Cn_char_array(cn_pointer*, cn_bits_u64*, cn_bool*, enum spec_mode);

void MaybeCn_char_array(cn_pointer*, cn_bits_u64*, enum spec_mode);

#endif
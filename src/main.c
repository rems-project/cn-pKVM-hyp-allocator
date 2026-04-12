#include <stdlib.h>
// #include <stdio.h>
#include <assert.h>
// #include <alloc.h>

#include "alloc.c"

void cn_print_nr_owned_predicates(void);

void* cn_unsafe_aligned_alloc(size_t align, size_t size);

phys_addr_t ident_to_pa(void *addr)
{
	return (phys_addr_t)addr;
}

void* ident_to_va(phys_addr_t addr)
{
	return (void*)addr;
}


int dummy_memcache(struct kvm_hyp_memcache *mc, u64 min_pages)
{
	while (mc->nr_pages < min_pages) {
		phys_addr_t *p = cn_unsafe_aligned_alloc(PAGE_SIZE, PAGE_SIZE);
		memset(p, 0, PAGE_SIZE);

		if (!p) {
			return -ENOMEM;
		}
		push_hyp_memcache(mc, p, ident_to_pa, 0);
		// printf("  \x1b[32mPUSHED: %p -- head: %p\x1b[0m\n", p, (void*)mc->head);
	}
	return 0;
}

#define fatal(STR,...)							\
	do {								\
		exit(EXIT_FAILURE);					\
	} while(0)



void dump_chunks(void);
struct kvm_hyp_memcache host_mc = { 0 };

void test1(void)
{
	int *p = hyp_alloc(4*sizeof(int));
	assert(p);
	dump_chunks();
	int *q = hyp_alloc(PAGE_SIZE + 128);
	assert(q);
	dump_chunks();
	hyp_free(p);
	dump_chunks();
	hyp_free(q);
	dump_chunks();
	p = hyp_alloc(sizeof(int));
	assert(p);
	dump_chunks();
}

void test2(void)
{
	dump_chunks();
	int *p = hyp_alloc(4*sizeof(int));
	assert(p);
	dump_chunks();
	int *q = hyp_alloc(PAGE_SIZE + 128);
	assert(q);
	dump_chunks();
	int *r = hyp_alloc(sizeof(int));
	assert(r);
	dump_chunks();
	hyp_free(r);
	dump_chunks();
	hyp_free(q);
	dump_chunks();
	r = hyp_alloc(PAGE_SIZE);
	assert(r);
	dump_chunks();
	q = hyp_alloc(sizeof(int));
	assert(q);
	dump_chunks();
	// printf("==> %d\n", hyp_alloc_reclaimable());
	hyp_free(r);
	dump_chunks();
	hyp_alloc_reclaim(&host_mc, 14);
	dump_chunks();
	// printf("==> %d\n", hyp_alloc_reclaimable());
}

void test3(void)
{
	dump_chunks();
	assert(hyp_alloc(sizeof(int)));
	dump_chunks();
	int *p = hyp_alloc(8 + PAGE_SIZE);
	assert(p);
	dump_chunks();
	hyp_free(p);
	dump_chunks();
	int n = hyp_alloc_reclaimable();
	dump_chunks();
	// printf("==> %d\n", n);
	// printf("errno: %d\n", hyp_alloc_errno());

	hyp_alloc_reclaim(&host_mc, n);
	// n = hyp_alloc_reclaimable();
	// printf("==> %d\n", n);
}

#define N_ALLOC 10
// Specialized for hyp_alloc
void test4(void)
{
	int i;
	// dump_chunks();
	// //assert(hyp_alloc(sizeof(int)));
	// dump_chunks();
	//int *p = hyp_alloc(8 + PAGE_SIZE);
	//assert(p);

	srand(2);
	int *p = hyp_alloc(400);
	assert(p);
	int *q = hyp_alloc(400);
	assert(q);
	hyp_free(p /*@ 400u64 @*/ );
	// should use chunk_recycle
	int *r = hyp_alloc(300);
	assert(p == r);
	hyp_alloc(80);
    void *ps[N_ALLOC];
    for (i = 0; i < N_ALLOC; i++) {
        ps[i] = hyp_alloc(400);
        if (ps[i] == NULL) {
            fatal("hyp_alloc failed!", -1);
        }
    }
    for (i = 0; i < N_ALLOC; i++) {
        hyp_free(ps[i] /*@ 400u64 @*/);
    }
}


void shim_create_hyp_mapping(size_t size);

#define NR_PAGES	2048
int main(void)
/*@
	accesses host_mc;
@*/
{
	int ret;
	// SHIM INIT
	shim_create_hyp_mapping(2048 << PAGE_SHIFT);

	// printf("HYP_ALLOC_INIT\n");
	ret = hyp_alloc_init(NR_PAGES*PAGE_SIZE);
	if(ret) {
		fatal("hyp_alloc_init() failed", ret);
	}


	ret = dummy_memcache(&host_mc, NR_PAGES);
	if (ret) {
		fatal("dummy_memcache() failed", ret);
	}

	// printf("HYP_ALLOC_REFILL\n");
	hyp_alloc_refill(&host_mc);

	test4();

	cn_print_nr_owned_predicates();
}

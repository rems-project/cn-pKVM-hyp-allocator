// TODO(doc): there is some code copied from pKVM (add licence notice)
#include <stdio.h>

#include <prelude.h>

#ifdef __cerb__
// TODO
const char *__func__ = "__func__";
#endif

unsigned long hyp_nr_cpus = 1;

#define log_function()							\
	({								\
		fprintf(stderr, "\x1b[31mCALLED: %s\x1b[0m\n",		\
			__func__);					\
	})

#define log_function_args(ARGS_STR, ...)				\
	({								\
		fprintf(stderr, "\x1b[31mCALLED: %s(" ARGS_STR		\
			")\x1b[0m\n", __func__, __VA_ARGS__);		\
	})


#define offset_in_page(p)	((unsigned long)(p) & ~PAGE_MASK)

phys_addr_t __pkvm_private_range_pa(void *va)
{
	// kvm_pte_t pte;
	// s8 level;

	// hyp_spin_lock(&pkvm_pgd_lock);
	// WARN_ON(kvm_pgtable_get_leaf(&pkvm_pgtable, (u64)va, &pte, &level));
	// hyp_spin_unlock(&pkvm_pgd_lock);

	// BUG_ON(!kvm_pte_valid(pte));

	// return kvm_pte_to_phys(pte) + offset_in_page(va);
	return (phys_addr_t)va;
}

/* VA ALLOCATION *************************************************************/
static u64 __io_map_base;
static u64 __hyp_vmemmap;

// int create_hyp_mapping(phys_addr_t addr, size_t size)
void shim_create_hyp_mapping(size_t size)
{
	__io_map_base = (u64)malloc(size);
	__hyp_vmemmap = __io_map_base + size;
}

static int __pkvm_alloc_private_va_range(unsigned long start, size_t size)
{
	unsigned long cur;

	//TODO: hyp_assert_lock_held(&pkvm_pgd_lock);

	if (!start || start < __io_map_base)
		return -EINVAL;

	/* The allocated size is always a multiple of PAGE_SIZE */
	cur = start + PAGE_ALIGN(size);

	/* Are we overflowing on the vmemmap ? */
	if (cur > __hyp_vmemmap)
		return -ENOMEM;

	__io_map_base = cur;

	return 0;
}
/**
 * pkvm_alloc_private_va_range - Allocates a private VA range.
 * @size:	The size of the VA range to reserve.
 * @haddr:	The hypervisor virtual start address of the allocation.
 *
 * The private virtual address (VA) range is allocated above __io_map_base
 * and aligned based on the order of @size.
 *
 * Return: 0 on success or negative error code on failure.
 */
int pkvm_alloc_private_va_range(size_t size, unsigned long *haddr)
{
	unsigned long addr;
	int ret;

	//KKK: hyp_spin_lock(&pkvm_pgd_lock);
	addr = __io_map_base;
	ret = __pkvm_alloc_private_va_range(addr, size);
	//KKK: hyp_spin_unlock(&pkvm_pgd_lock);

	*haddr = addr;

	return ret;
}

void pkvm_remove_mappings(void *from, void *to)
{
	log_function_args("from: %p, to: %p", from, to);
	printf("\x1b[31mTODO\x1b[0m\n");
}


int __pkvm_hyp_donate_host(u64 pfn, u64 nr_pages)
{
	log_function_args("<TODO>pfn: %"PRIx64", nr_pages: %"PRIu64, pfn, nr_pages);
	return 0; // TODO
}

int __hyp_allocator_map(unsigned long start, phys_addr_t phys)
{
	// log_function_args("start: %lx, phys: %"PRIx64, start, phys);
	// printf("\x1b[31mTODO\x1b[0m\n");
	return 0; // TODO
}


void *hyp_phys_to_virt(phys_addr_t phys)
{
	// log_function_args("phys: %"PRIu64, phys);
	return (void*)phys;
}
phys_addr_t hyp_virt_to_phys(void *addr)
{
	// log_function_args("addr: %p", addr);
	return (phys_addr_t)addr;
}
u64 hyp_virt_to_pfn(void *addr)
{
	// log_function_args("addr: %p", addr);
	return hyp_virt_to_phys(addr) >> PAGE_SHIFT;
}


// Spinlock
void hyp_spin_lock(hyp_spinlock_t *lock)
{
	// log_function();
}
void hyp_spin_unlock(hyp_spinlock_t *lock)
{
	// log_function();
}

u32 hash_32(u32 val, unsigned int bits)
{
	// log_function();
	// printf("\x1b[31mTODO\x1b[0m\n");
	return 0; //TODO
}
u32 hash_64(u64 val, unsigned int bits)
{
	// log_function();
	// printf("\x1b[31mTODO\x1b[0m\n");
	return 0; //TODO
}



#include <assert.h>
static void *admit_host_page(void *arg, unsigned long order)
{
	phys_addr_t p __attribute__((unused));
	struct kvm_hyp_memcache *host_mc = arg;
	unsigned long mc_order;

	if (!host_mc->nr_pages)
		return NULL;

	mc_order = FIELD_GET(~PAGE_MASK, host_mc->head);
	assert(order == mc_order);

	p = host_mc->head & PAGE_MASK;
	/*
	 * The host still owns the pages in its memcache, so we need to go
	 * through a full host-to-hyp donation cycle to change it. Fortunately,
	 * __pkvm_host_donate_hyp() takes care of races for us, so if it
	 * succeeds we're good to go.
	 */
#if 0
	if (__pkvm_host_donate_hyp(hyp_phys_to_pfn(p), 1 << order))
		return NULL;
#endif

	return pop_hyp_memcache(host_mc, hyp_phys_to_virt, &order);
}

int refill_memcache(struct kvm_hyp_memcache *mc, unsigned long min_pages,
		    struct kvm_hyp_memcache *host_mc)
{
	struct kvm_hyp_memcache tmp = *host_mc;
	int ret;

	ret =  __topup_hyp_memcache(mc, min_pages, admit_host_page,
				    hyp_virt_to_phys, &tmp, 0);
	*host_mc = tmp;

	return ret;
}

/**
 * @file
 *
 * cvmx-tlb provides access functions for setting up TLB entries for simple
 * executive applications.
 *
 * <hr>$Revision: 41586 $<hr>
 */

#define BDK_TLB_PAGEMASK_4K		(0x3     << 11)
#define BDK_TLB_PAGEMASK_16K		(0xF     << 11)
#define BDK_TLB_PAGEMASK_64K		(0x3F    << 11)
#define BDK_TLB_PAGEMASK_256K		(0xFF    << 11)
#define BDK_TLB_PAGEMASK_1M		(0x3FF   << 11)
#define BDK_TLB_PAGEMASK_4M		(0xFFF   << 11)
#define BDK_TLB_PAGEMASK_16M		(0x3FFF  << 11)
#define BDK_TLB_PAGEMASK_64M		(0xFFFF  << 11)
#define BDK_TLB_PAGEMASK_256M		(0x3FFFF << 11)

#define PAGE_MASK 			( ~(( 1<< 12 ) -1))

/**
 *  Set up a wired entry. This function is designed to be used by Simple
 *  Executive to set up its virtual to physical address mapping at start up
 *  time. After the mapping is set up, the remaining unused TLB entries can
 *  be use for run time shared memory mapping.
 *
 *  Calling this function causes the C0 wired index register to increase.
 *  Wired index register points to the separation between fixed TLB mapping
 *  and run time shared memory mapping.
 *
 *  @param  hi		Entry Hi
 *  @param  lo0		Entry Low0
 *  @param  lo1		Entry Low1
 *  @pagam  pagemask    Pagemask
 *
 *  @return 0: the entry is added
 *  @return -1: out of TLB entry
 */
int bdk_tlb_add_wired_entry( uint64_t hi, uint64_t lo0,
			      uint64_t lo1, uint64_t pagemask);


/**
 *  Find a free entry that can be used for share memory mapping.
 *
 *  @return -1: no free entry found
 *  @return :  a free entry
 */
int bdk_tlb_allocate_runtime_entry(void);

/**
 *  Invalidate the TLB entry. Remove previous mapping if one was set up
 *  @param tlbi
 */
void bdk_tlb_free_runtime_entry(uint32_t tlbi);

/**
 *  Debug routine to show all shared memory mapping
 */
void bdk_tlb_dump_shared_mapping(void);

/**
 *  Program a single TLB entry to enable the provided vaddr to paddr mapping.
 *
 *  @param index  Index of the TLB entry
 *  @param vaddr  The virtual address for this mapping
 *  @param paddr  The physical address for this mapping
 *  @param size   Size of the mapping
 *  @param tlb_flags  Entry mapping flags
 */
void bdk_tlb_write_entry(int index, uint64_t vaddr, uint64_t paddr,
                          uint64_t size, uint64_t tlb_flags);


/**
 *  Program a single TLB entry to enable the provided vaddr to paddr mapping.
 *  This version adds a wired entry that should not be changed at run time
 *
 *  @param index  Index of the TLB entry
 *  @param vaddr  The virtual address for this mapping
 *  @param paddr  The physical address for this mapping
 *  @param size   Size of the mapping
 *  @param tlb_flags  Entry mapping flags
 *  @return -1: TLB out of entries
 *           0:  fixed entry added
 *
 */
int bdk_tlb_add_fixed_entry(uint64_t vaddr, uint64_t paddr,
                          uint64_t size, uint64_t tlb_flags);

/**
 *  Program a single TLB entry to enable the provided vaddr to paddr mapping.
 *  This version writes a runtime entry. It will check the index to make sure
 *  not to overwrite any fixed entries.
 *
 *  @param index  Index of the TLB entry
 *  @param vaddr  The virtual address for this mapping
 *  @param paddr  The physical address for this mapping
 *  @param size   Size of the mapping
 *  @param tlb_flags  Entry mapping flags
 */
void bdk_tlb_write_runtime_entry(int index, uint64_t vaddr, uint64_t paddr,
                          uint64_t size, uint64_t tlb_flags);


/**
 *  Find the TLB index of a given virtual address
 *
 *  @param vaddr  The virtual address to look up
 *  @return  -1  not TLB mapped
 *  	     >=0 TLB TLB index
 */
int bdk_tlb_lookup(uint64_t vaddr);

/**
 *  Debug routine to show all TLB entries of this core
 *
 */
void bdk_tlb_dump_all(void);

/**
 *  Query for total number of TLBs of the core
 *
 *  @return Total number of TLB entries available on the core
 */
static inline uint32_t bdk_tlb_size_limit(void)
{
	uint32_t tlb_size_limit = 0;

        if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
            tlb_size_limit =  64;
        else
            tlb_size_limit = 128;

	return tlb_size_limit;
}

/*
 * @INTERNAL
 * return the next power of two value for the given input <v>
 *
 * @param v input value
 * @return next power of two value for v
 */
static inline uint64_t __upper_power_of_two(uint64_t v)
{
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    v |= v >> 32;
    v++;
    return v;
}

/**
 * @INTERNAL
 * Check if the given value 'v' is power of two.
 *
 * @param v input value
 * @return 1  yes
 * 	   0  no
 */
static inline int __is_power_of_two(uint64_t v)
{
	int num_of_1s = 0;

	BDK_DPOP(num_of_1s, v);
	return (num_of_1s  ==  1 );
}


/**
 * @INTERNAL
 *
 * Find last bit set 64bit version
 *
 * @param x the integer to find leading 1
 *
 * @return >=0 the bit position (0..63) of the most significant 1 bit in a word
 *   	   -1 if no 1 bit exists
 */
static inline uint64_t __fls64(uint64_t x)
{
	int lz;

	if (sizeof(x) != 8) return 0;

	__asm__(
	"	.set	push						\n"
	"	.set	mips64						\n"
	"	dclz	%0, %1						\n"
	"	.set	pop						\n"
	: "=r" (lz)
	: "r" (x));

	return 63 - lz;
}

/**
 * @INTERNAL
 * Compute  log2(v), only works if v is power of two.
 *
 * @param v  the input value
 * @return  log2(v)
 */
static inline uint32_t __log2(uint64_t v)
{
	uint32_t log2 = 0 ;

	if (v) log2 =  __fls64(v);

	return log2;
}


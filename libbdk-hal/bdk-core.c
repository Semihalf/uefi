#include <bdk.h>

/**
 * Adds a wired TLB entry, and returns the index of the entry added.
 * Parameters are written to TLB registers without further processing.
 *
 * @param hi     HI register value
 * @param lo0    lo0 register value
 * @param lo1    lo1 register value
 * @param page_mask   pagemask register value
 *
 * @return Success: TLB index used (0-31 Octeon, 0-63 Octeon+, or 0-127
 *         Octeon2). Failure: -1
 */
int bdk_core_add_wired_tlb_entry(uint64_t hi, uint64_t lo0, uint64_t lo1, bdk_tlb_pagemask_t page_mask)
{
    uint32_t index;

    BDK_MF_TLB_WIRED(index);
    if (index >= (unsigned int)bdk_core_get_tlb_entries())
    {
        return(-1);
    }
    BDK_MT_ENTRY_HIGH(hi);
    BDK_MT_ENTRY_LO_0(lo0);
    BDK_MT_ENTRY_LO_1(lo1);
    BDK_MT_PAGEMASK(page_mask);
    BDK_MT_TLB_INDEX(index);
    BDK_MT_TLB_WIRED(index + 1);
    BDK_EHB;
    BDK_TLBWI;
    BDK_EHB;
    return(index);
}



/**
 * Adds a fixed (wired) TLB mapping.  Returns TLB index used or -1 on error.
 * This is a wrapper around bdk_core_add_wired_tlb_entry()
 *
 * @param vaddr      Virtual address to map
 * @param page0_addr page 0 physical address, with low 3 bits representing the DIRTY, VALID, and GLOBAL bits
 * @param page1_addr page1 physical address, with low 3 bits representing the DIRTY, VALID, and GLOBAL bits
 * @param page_mask  page mask.
 *
 * @return Success: TLB index used (0-31)
 *         Failure: -1
 */
int bdk_core_add_fixed_tlb_mapping_bits(uint64_t vaddr, uint64_t page0_addr, uint64_t page1_addr, bdk_tlb_pagemask_t page_mask)
{

    if ((vaddr & (page_mask | 0x7ff))
        || ((page0_addr & ~0x7ULL) & ((page_mask | 0x7ff) >> 1))
        || ((page1_addr & ~0x7ULL) & ((page_mask | 0x7ff) >> 1)))
    {
        bdk_error("Adding tlb mapping: invalid address alignment at vaddr: 0x%llx\n", (unsigned long long)vaddr);
        return(-1);
    }


    return(bdk_core_add_wired_tlb_entry(vaddr,
                                         (page0_addr >> 6) | (page0_addr & 0x7),
                                         (page1_addr >> 6) | (page1_addr & 0x7),
                                         page_mask));

}
/**
 * Adds a fixed (wired) TLB mapping.  Returns TLB index used or -1 on error.
 * Assumes both pages are valid.  Use bdk_core_add_fixed_tlb_mapping_bits for more control.
 * This is a wrapper around bdk_core_add_wired_tlb_entry()
 *
 * @param vaddr      Virtual address to map
 * @param page0_addr page 0 physical address
 * @param page1_addr page1 physical address
 * @param page_mask  page mask.
 *
 * @return Success: TLB index used (0-31)
 *         Failure: -1
 */
int bdk_core_add_fixed_tlb_mapping(uint64_t vaddr, uint64_t page0_addr, uint64_t page1_addr, bdk_tlb_pagemask_t page_mask)
{

    return(bdk_core_add_fixed_tlb_mapping_bits(vaddr, page0_addr | TLB_DIRTY | TLB_VALID | TLB_GLOBAL, page1_addr | TLB_DIRTY | TLB_VALID | TLB_GLOBAL, page_mask));

}

/**
 * Return number of TLB entries.
 */
int bdk_core_get_tlb_entries(void)
{
    return 128;
}

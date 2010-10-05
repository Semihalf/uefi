#include <bdk.h>

static bdk_spinlock_t bdk_l2c_spinlock;

int bdk_l2c_get_core_way_partition(uint32_t core)
{
    uint32_t    field;

    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return (BDK_CSR_READ(BDK_L2C_WPAR_PPX(core)) & 0xffff);

    /* Use the lower two bits of the coreNumber to determine the bit offset
     * of the UMSK[] field in the L2C_SPAR register.
     */
    field = (core & 0x3) * 8;

    /* Return the UMSK[] field from the appropriate L2C_SPAR register based
     * on the coreNumber.
     */

    switch (core & 0xC)
    {
        case 0x0:
            return((BDK_CSR_READ(BDK_L2C_SPAR0) & (0xFF << field)) >> field);
        case 0x4:
            return((BDK_CSR_READ(BDK_L2C_SPAR1) & (0xFF << field)) >> field);
        case 0x8:
            return((BDK_CSR_READ(BDK_L2C_SPAR2) & (0xFF << field)) >> field);
    }
    return(0);
}

int bdk_l2c_set_core_way_partition(uint32_t core, uint32_t mask)
{
    uint32_t    field;
    uint32_t    valid_mask;

    valid_mask = (0x1 << bdk_l2c_get_num_assoc()) - 1;

    mask &= valid_mask;

    /* A UMSK setting which blocks all L2C Ways is an error on some chips */
    if (mask == valid_mask && !OCTEON_IS_MODEL(OCTEON_CN63XX))
        return -1;

    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
       BDK_CSR_WRITE(BDK_L2C_WPAR_PPX(core), mask);
       return 0;
    }

    /* Use the lower two bits of core to determine the bit offset of the
     * UMSK[] field in the L2C_SPAR register.
     */
    field = (core & 0x3) * 8;

    /* Assign the new mask setting to the UMSK[] field in the appropriate
     * L2C_SPAR register based on the core_num.
     *
     */
    switch (core & 0xC)
    {
        case 0x0:
            BDK_CSR_WRITE(BDK_L2C_SPAR0,
                           (BDK_CSR_READ(BDK_L2C_SPAR0) & ~(0xFF << field)) |
                           mask << field);
            break;
        case 0x4:
            BDK_CSR_WRITE(BDK_L2C_SPAR1,
                           (BDK_CSR_READ(BDK_L2C_SPAR1) & ~(0xFF << field)) |
                           mask << field);
            break;
        case 0x8:
            BDK_CSR_WRITE(BDK_L2C_SPAR2,
                           (BDK_CSR_READ(BDK_L2C_SPAR2) & ~(0xFF << field)) |
                           mask << field);
            break;
    }
    return 0;
}


int bdk_l2c_set_hw_way_partition(uint32_t mask)
{
    uint32_t valid_mask;

    valid_mask = (0x1 << bdk_l2c_get_num_assoc()) - 1;
    mask &= valid_mask;

    /* A UMSK setting which blocks all L2C Ways is an error on some chips */
    if (mask == valid_mask  && !OCTEON_IS_MODEL(OCTEON_CN63XX))
        return -1;

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        BDK_CSR_WRITE(BDK_L2C_WPAR_IOBX(0), mask);
    else
        BDK_CSR_WRITE(BDK_L2C_SPAR4, (BDK_CSR_READ(BDK_L2C_SPAR4) & ~0xFF) | mask);
    return 0;
}

int bdk_l2c_get_hw_way_partition(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return(BDK_CSR_READ(BDK_L2C_WPAR_IOBX(0)) & 0xffff);
    else
        return(BDK_CSR_READ(BDK_L2C_SPAR4) & (0xFF));
}

void bdk_l2c_config_perf(uint32_t counter, bdk_l2c_event_t event,
                          uint32_t clear_on_read)
{

    if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
    {
        bdk_l2c_pfctl_t pfctl;

        pfctl.u64 = BDK_CSR_READ(BDK_L2C_PFCTL);

        switch (counter)
        {
            case 0:
                pfctl.s.cnt0sel = event;
                pfctl.s.cnt0ena = 1;
                pfctl.s.cnt0rdclr = clear_on_read;
                break;
            case 1:
                pfctl.s.cnt1sel = event;
                pfctl.s.cnt1ena = 1;
                pfctl.s.cnt1rdclr = clear_on_read;
                break;
            case 2:
                pfctl.s.cnt2sel = event;
                pfctl.s.cnt2ena = 1;
                pfctl.s.cnt2rdclr = clear_on_read;
                break;
            case 3:
            default:
                pfctl.s.cnt3sel = event;
                pfctl.s.cnt3ena = 1;
                pfctl.s.cnt3rdclr = clear_on_read;
                break;
        }

        BDK_CSR_WRITE(BDK_L2C_PFCTL, pfctl.u64);
    }
    else
    {
        bdk_l2c_tadx_prf_t l2c_tadx_prf;
        int tad;

        bdk_warn("L2C performance counter events are different for this chip, mapping 'event' to bdk_l2c_tad_event_t\n");

        bdk_warn_if(clear_on_read, "L2C counters don't support clear on read for this chip\n");

        l2c_tadx_prf.u64 = BDK_CSR_READ(BDK_L2C_TADX_PRF(0));

        switch (counter)
        {
            case 0:
                l2c_tadx_prf.s.cnt0sel = event;
                break;
            case 1:
                l2c_tadx_prf.s.cnt1sel = event;
                break;
            case 2:
                l2c_tadx_prf.s.cnt2sel = event;
                break;
            default:
            case 3:
                l2c_tadx_prf.s.cnt3sel = event;
                break;
        }
        for (tad=0; tad<BDK_L2C_TADS; tad++)
            BDK_CSR_WRITE(BDK_L2C_TADX_PRF(tad), l2c_tadx_prf.u64);
    }
}

uint64_t bdk_l2c_read_perf(uint32_t counter)
{
    switch (counter)
    {
        case 0:
            if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
                return(BDK_CSR_READ(BDK_L2C_PFCX(0)));
            else
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC0(tad));
                return counter;
            }
        case 1:
            if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
                return(BDK_CSR_READ(BDK_L2C_PFCX(1)));
            else
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC1(tad));
                return counter;
            }
        case 2:
            if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
                return(BDK_CSR_READ(BDK_L2C_PFCX(2)));
            else
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC2(tad));
                return counter;
            }
        case 3:
        default:
            if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
                return(BDK_CSR_READ(BDK_L2C_PFCX(3)));
            else
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC3(tad));
                return counter;
            }
    }
}

/**
 * @INTERNAL
 * Helper function use to fault in cache lines for L2 cache locking
 *
 * @param addr   Address of base of memory region to read into L2 cache
 * @param len    Length (in bytes) of region to fault in
 */
static void fault_in(uint64_t addr, int len)
{
    volatile char *ptr;
    volatile char dummy;
    /* Adjust addr and length so we get all cache lines even for
    ** small ranges spanning two cache lines */
    len += addr & BDK_CACHE_LINE_MASK;
    addr &= ~BDK_CACHE_LINE_MASK;
    ptr = (volatile char *)bdk_phys_to_ptr(addr);
    BDK_DCACHE_INVALIDATE;  /* Invalidate L1 cache to make sure all loads result in data being in L2 */
    while (len > 0)
    {
        dummy += *ptr;
        len -= BDK_CACHE_LINE_SIZE;
        ptr += BDK_CACHE_LINE_SIZE;
    }
}

int bdk_l2c_lock_line(uint64_t addr)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        int shift = BDK_L2C_TAG_ADDR_ALIAS_SHIFT;
        uint64_t assoc = bdk_l2c_get_num_assoc();
        uint64_t tag = addr >> shift;
        uint64_t index = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, bdk_l2c_address_to_index(addr) << BDK_L2C_IDX_ADDR_SHIFT);
        uint64_t way;
        bdk_l2c_tadx_tag_t l2c_tadx_tag;

        BDK_CACHE_LCKL2(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, addr), 0);

        /* Make sure we were able to lock the line */
        for (way = 0; way < assoc; way++)
        {
            BDK_CACHE_LTGL2I(index | (way << shift), 0);
            BDK_SYNC;   // make sure BDK_L2C_TADX_TAG is updated
            l2c_tadx_tag.u64 = BDK_CSR_READ(BDK_L2C_TADX_TAG(0));
            if (l2c_tadx_tag.s.valid && l2c_tadx_tag.s.tag == tag)
                break;
        }

        /* Check if a valid line is found */
        if (way >= assoc)
        {
            //bdk_dprintf("ERROR: bdk_l2c_lock_line: line not found for locking at 0x%llx address\n", (unsigned long long)addr);
            return -1;
        }

        /* Check if lock bit is not set */
        if (!l2c_tadx_tag.s.lock)
        {
            //bdk_dprintf("ERROR: bdk_l2c_lock_line: Not able to lock at 0x%llx address\n", (unsigned long long)addr);
            return -1;
        }

        return way;
    }
    else
    {
        int retval = 0;
        bdk_l2c_dbg_t l2cdbg;
        bdk_l2c_lckbase_t lckbase;
        bdk_l2c_lckoff_t lckoff;
        bdk_l2t_err_t l2t_err;

        bdk_spinlock_lock(&bdk_l2c_spinlock);

        l2cdbg.u64 = 0;
        lckbase.u64 = 0;
        lckoff.u64 = 0;

        /* Clear l2t error bits if set */
        l2t_err.u64 = BDK_CSR_READ(BDK_L2T_ERR);
        l2t_err.s.lckerr = 1;
        l2t_err.s.lckerr2 = 1;
        BDK_CSR_WRITE(BDK_L2T_ERR, l2t_err.u64);

        addr &= ~BDK_CACHE_LINE_MASK;

        /* Set this core as debug core */
        l2cdbg.s.ppnum = bdk_get_core_num();
        BDK_SYNC;
        BDK_CSR_WRITE(BDK_L2C_DBG, l2cdbg.u64);
        BDK_CSR_READ(BDK_L2C_DBG);

        lckoff.s.lck_offset = 0; /* Only lock 1 line at a time */
        BDK_CSR_WRITE(BDK_L2C_LCKOFF, lckoff.u64);
        BDK_CSR_READ(BDK_L2C_LCKOFF);

        if (((bdk_l2c_cfg_t)(BDK_CSR_READ(BDK_L2C_CFG))).s.idxalias)
        {
            int alias_shift = BDK_L2C_IDX_ADDR_SHIFT + 2 * bdk_l2c_get_set_bits() - 1;
            uint64_t addr_tmp = addr ^ (addr & ((1 << alias_shift) - 1)) >> bdk_l2c_get_set_bits();
            lckbase.s.lck_base = addr_tmp >> 7;
        }
        else
        {
            lckbase.s.lck_base = addr >> 7;
        }

        lckbase.s.lck_ena = 1;
        BDK_CSR_WRITE(BDK_L2C_LCKBASE, lckbase.u64);
        BDK_CSR_READ(BDK_L2C_LCKBASE);    // Make sure it gets there

        fault_in(addr, BDK_CACHE_LINE_SIZE);

        lckbase.s.lck_ena = 0;
        BDK_CSR_WRITE(BDK_L2C_LCKBASE, lckbase.u64);
        BDK_CSR_READ(BDK_L2C_LCKBASE);    // Make sure it gets there

        /* Stop being debug core */
        BDK_CSR_WRITE(BDK_L2C_DBG, 0);
        BDK_CSR_READ(BDK_L2C_DBG);

        l2t_err.u64 = BDK_CSR_READ(BDK_L2T_ERR);
        if (l2t_err.s.lckerr || l2t_err.s.lckerr2)
            retval = 1;  /* We were unable to lock the line */

        bdk_spinlock_unlock(&bdk_l2c_spinlock);
        return(retval);
    }
}


int bdk_l2c_lock_mem_region(uint64_t start, uint64_t len)
{
    int retval = 0;

    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;

    while (len)
    {
        retval += bdk_l2c_lock_line(start);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }

    return(retval);
}


void bdk_l2c_flush(void)
{
    uint64_t assoc, set;
    uint64_t n_assoc, n_set;

    n_set = bdk_l2c_get_num_sets();
    n_assoc = bdk_l2c_get_num_assoc();

    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        uint64_t address;
        /* These may look like constants, but they aren't... */
        int assoc_shift = BDK_L2C_TAG_ADDR_ALIAS_SHIFT;
        int set_shift = BDK_L2C_IDX_ADDR_SHIFT;
        for (set=0; set < n_set; set++)
        {
            for(assoc=0; assoc < n_assoc; assoc++)
            {
                address = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS,
                                       (assoc << assoc_shift) |
                                       (set << set_shift));
                BDK_CACHE_WBIL2I(address, 0);
            }
        }
    }
    else
    {
        for (set=0; set < n_set; set++)
            for(assoc=0; assoc < n_assoc; assoc++)
                bdk_l2c_flush_line(assoc, set);
    }
}


int bdk_l2c_unlock_line(uint64_t address)
{

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        int assoc;         bdk_l2c_tag_t tag;
        uint32_t tag_addr;
        uint32_t index = bdk_l2c_address_to_index(address);

        tag_addr = ((address >> BDK_L2C_TAG_ADDR_ALIAS_SHIFT) & ((1 << BDK_L2C_TAG_ADDR_ALIAS_SHIFT) - 1));

        /* For 63XX, we can flush a line by using the physical address directly,
        ** so finding the cache line used by the address is only required to provide
        ** the proper return value for the function.
        */
        for(assoc = 0; assoc < bdk_l2c_get_num_assoc(); assoc++)
        {
            tag = bdk_l2c_get_tag(assoc, index);

            if (tag.s.V && (tag.s.addr == tag_addr))
            {
                BDK_CACHE_WBIL2(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, address), 0);
                return tag.s.L;
            }
        }
    }
    else
    {
        int assoc;
        bdk_l2c_tag_t tag;
        uint32_t tag_addr;

        uint32_t index = bdk_l2c_address_to_index(address);

        /* Compute portion of address that is stored in tag */
        tag_addr = ((address >> BDK_L2C_TAG_ADDR_ALIAS_SHIFT) & ((1 << BDK_L2C_TAG_ADDR_ALIAS_SHIFT) - 1));
        for(assoc = 0; assoc < bdk_l2c_get_num_assoc(); assoc++)
        {
            tag = bdk_l2c_get_tag(assoc, index);

            if (tag.s.V && (tag.s.addr == tag_addr))
            {
                bdk_l2c_flush_line(assoc, index);
                return tag.s.L;
            }
        }
    }
    return 0;
}

int bdk_l2c_unlock_mem_region(uint64_t start, uint64_t len)
{
    int num_unlocked = 0;
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;
    while (len > 0)
    {
        num_unlocked += bdk_l2c_unlock_line(start);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }

    return num_unlocked;
}


/* Internal l2c tag types.  These are converted to a generic structure
** that can be used on all chips */
typedef union
{
    uint64_t u64;
#if __BYTE_ORDER == __BIG_ENDIAN
    struct bdk_l2c_tag_cn52xx
    {
	uint64_t reserved		: 42;
	uint64_t V			: 1;	// Line valid
	uint64_t D			: 1;	// Line dirty
	uint64_t L			: 1;	// Line locked
	uint64_t U			: 1;	// Use, LRU eviction
	uint64_t addr			: 18;	// Phys mem addr (33..16)
    } cn52xx;
    struct bdk_l2c_tag_cn56xx
    {
	uint64_t reserved		: 44;
	uint64_t V			: 1;	// Line valid
	uint64_t D			: 1;	// Line dirty
	uint64_t L			: 1;	// Line locked
	uint64_t U			: 1;	// Use, LRU eviction
	uint64_t addr			: 16;	// Phys mem addr (33..18)
    } cn56xx;
#endif
} __bdk_l2c_tag_t;


/**
 * @INTERNAL
 * Function to read a L2C tag.  This code make the current core
 * the 'debug core' for the L2.  This code must only be executed by
 * 1 core at a time.
 *
 * @param assoc  Association (way) of the tag to dump
 * @param index  Index of the cacheline
 *
 * @return The Octeon model specific tag structure.  This is translated by a wrapper
 *         function to a generic form that is easier for applications to use.
 */
static __bdk_l2c_tag_t __read_l2_tag(uint64_t assoc, uint64_t index)
{

    uint64_t debug_tag_addr = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, (index << 7) + 96);
    uint64_t core = bdk_get_core_num();
    __bdk_l2c_tag_t tag_val;
    uint64_t dbg_addr = BDK_L2C_DBG;
    unsigned long flags;

    bdk_l2c_dbg_t debug_val;
    debug_val.u64 = 0;
    /* For low core count parts, the core number is always small enough
    ** to stay in the correct field and not set any reserved bits */
    debug_val.s.ppnum = core;
    debug_val.s.l2t = 1;
    debug_val.s.set = assoc;

    BDK_SYNC;  /* Make sure core is quiet (no prefetches, etc.) before entering debug mode */
    BDK_DCACHE_INVALIDATE;  /* Flush L1 to make sure debug load misses L1 */

    bdk_local_irq_save(flags);

    /* The following must be done in assembly as when in debug mode all data loads from
    ** L2 return special debug data, not normal memory contents.  Also, interrupts must be disabled,
    ** since if an interrupt occurs while in debug mode the ISR will get debug data from all its memory
    ** reads instead of the contents of memory */

        asm volatile (
    "        .set push              \n"
    "        .set mips64              \n"
    "        .set noreorder           \n"
    "        sd    %[dbg_val], 0(%[dbg_addr])  \n"   /* Enter debug mode, wait for store */
    "        ld    $0, 0(%[dbg_addr]) \n"
    "        ld    %[tag_val], 0(%[tag_addr]) \n"   /* Read L2C tag data */
    "        sd    $0, 0(%[dbg_addr])  \n"          /* Exit debug mode, wait for store */
    "        ld    $0, 0(%[dbg_addr]) \n"
    "        cache 9, 0($0) \n"             /* Invalidate dcache to discard debug data */
    "        .set pop             \n"
    :[tag_val] "=r" (tag_val):  [dbg_addr] "r" (dbg_addr), [dbg_val] "r" (debug_val), [tag_addr] "r" (debug_tag_addr) : "memory");

    bdk_local_irq_restore(flags);

    return(tag_val);

}


bdk_l2c_tag_t bdk_l2c_get_tag(uint32_t association, uint32_t index)
{
    bdk_l2c_tag_t tag;
    tag.u64 = 0;

    if ((int)association >= bdk_l2c_get_num_assoc())
    {
        bdk_dprintf("ERROR: bdk_l2c_get_tag association out of range\n");
        return(tag);
    }
    if ((int)index >= bdk_l2c_get_num_sets())
    {
        bdk_dprintf("ERROR: bdk_l2c_get_tag index out of range (arg: %d, max: %d)\n", (int)index, bdk_l2c_get_num_sets());
        return(tag);
    }
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        bdk_l2c_tadx_tag_t l2c_tadx_tag;
        uint64_t address = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS,
                                        (association << BDK_L2C_TAG_ADDR_ALIAS_SHIFT) |
                                        (index << BDK_L2C_IDX_ADDR_SHIFT));
        /* Use L2 cache Index load tag cache instruction, as hardware loads
           the virtual tag for the L2 cache block with the contents of
           L2C_TAD0_TAG register. */
        BDK_CACHE_LTGL2I(address, 0);
        BDK_SYNC;   // make sure BDK_L2C_TADX_TAG is updated
        l2c_tadx_tag.u64 = BDK_CSR_READ(BDK_L2C_TADX_TAG(0));

        tag.s.V     = l2c_tadx_tag.s.valid;
        tag.s.D     = l2c_tadx_tag.s.dirty;
        tag.s.L     = l2c_tadx_tag.s.lock;
        tag.s.U     = l2c_tadx_tag.s.use;
        tag.s.addr  = l2c_tadx_tag.s.tag;
    }
    else
    {
        __bdk_l2c_tag_t tmp_tag;
        /* __read_l2_tag is intended for internal use only */
        tmp_tag = __read_l2_tag(association, index);

        /* Convert all tag structure types to generic version, as it can represent all models */
        if (OCTEON_IS_MODEL(OCTEON_CN56XX))
        {
            tag.s.V    = tmp_tag.cn56xx.V;
            tag.s.D    = tmp_tag.cn56xx.D;
            tag.s.L    = tmp_tag.cn56xx.L;
            tag.s.U    = tmp_tag.cn56xx.U;
            tag.s.addr = tmp_tag.cn56xx.addr;
        }
        else if (OCTEON_IS_MODEL(OCTEON_CN52XX))
        {
            tag.s.V    = tmp_tag.cn52xx.V;
            tag.s.D    = tmp_tag.cn52xx.D;
            tag.s.L    = tmp_tag.cn52xx.L;
            tag.s.U    = tmp_tag.cn52xx.U;
            tag.s.addr = tmp_tag.cn52xx.addr;
        }
        else
        {
            bdk_dprintf("Unsupported OCTEON Model in %s\n", __FUNCTION__);
        }
    }

    return tag;
}

uint32_t bdk_l2c_address_to_index (uint64_t addr)
{
    uint64_t idx = addr >> BDK_L2C_IDX_ADDR_SHIFT;
    int indxalias = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        bdk_l2c_ctl_t l2c_ctl;
        l2c_ctl.u64 = BDK_CSR_READ(BDK_L2C_CTL);
        indxalias = !l2c_ctl.s.disidxalias;
    }
    else
    {
        bdk_l2c_cfg_t l2c_cfg;
        l2c_cfg.u64 = BDK_CSR_READ(BDK_L2C_CFG);
        indxalias = l2c_cfg.s.idxalias;
    }

    if (indxalias)
    {
        if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        {
            uint32_t a_14_12 = (idx / (BDK_L2C_MEMBANK_SELECT_SIZE/(1<<BDK_L2C_IDX_ADDR_SHIFT))) & 0x7;
            idx ^= idx / bdk_l2c_get_num_sets();
            idx ^= a_14_12;
        }
        else
        {
            idx ^= ((addr & BDK_L2C_ALIAS_MASK) >> BDK_L2C_TAG_ADDR_ALIAS_SHIFT);
        }
    }
    idx &= BDK_L2C_IDX_MASK;
    return(idx);
}

int bdk_l2c_get_cache_size_bytes(void)
{
    return (bdk_l2c_get_num_sets() * bdk_l2c_get_num_assoc() * BDK_CACHE_LINE_SIZE);
}

/**
 * Return log base 2 of the number of sets in the L2 cache
 * @return
 */
int bdk_l2c_get_set_bits(void)
{
    int l2_set_bits;
    if (OCTEON_IS_MODEL(OCTEON_CN56XX))
        l2_set_bits =  11; /* 2048 sets */
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        l2_set_bits =  10; /* 1024 sets */
    else if (OCTEON_IS_MODEL(OCTEON_CN52XX))
        l2_set_bits =  9; /* 512 sets */
    else
    {
        bdk_dprintf("Unsupported OCTEON Model in %s\n", __FUNCTION__);
        l2_set_bits =  11; /* 2048 sets */
    }
    return(l2_set_bits);

}

/* Return the number of sets in the L2 Cache */
int bdk_l2c_get_num_sets(void)
{
    return (1 << bdk_l2c_get_set_bits());
}

/* Return the number of associations in the L2 Cache */
int bdk_l2c_get_num_assoc(void)
{
    int l2_assoc;
    if (OCTEON_IS_MODEL(OCTEON_CN56XX) ||
        OCTEON_IS_MODEL(OCTEON_CN52XX))
        l2_assoc =  8;
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        l2_assoc =  16;
    else
    {
        bdk_dprintf("Unsupported OCTEON Model in %s\n", __FUNCTION__);
        l2_assoc =  8;
    }

    /* Check to see if part of the cache is disabled */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        bdk_mio_fus_dat3_t mio_fus_dat3;

        mio_fus_dat3.u64 = BDK_CSR_READ(BDK_MIO_FUS_DAT3);
        /* bdk_mio_fus_dat3.s.l2c_crip fuses map as follows
           <2> will be not used for 63xx
           <1> disables 1/2 ways
           <0> disables 1/4 ways
           They are cumulative, so for 63xx:
           <1> <0>
           0 0 16-way 2MB cache
           0 1 12-way 1.5MB cache
           1 0 8-way 1MB cache
           1 1 4-way 512KB cache */

        if (mio_fus_dat3.s.l2c_crip == 3)
            l2_assoc = 4;
        else if (mio_fus_dat3.s.l2c_crip == 2)
            l2_assoc = 8;
        else if (mio_fus_dat3.s.l2c_crip == 1)
            l2_assoc = 12;
    }
    else
    {
        bdk_l2d_fus3_t val;
        val.u64 = BDK_CSR_READ(BDK_L2D_FUS3);
        /* Using shifts here, as bit position names are different for
           each model but they all mean the same. */
        if ((val.u64 >> 35) & 0x1)
            l2_assoc = l2_assoc >> 2;
        else if ((val.u64 >> 34) & 0x1)
            l2_assoc = l2_assoc >> 1;
    }

    return(l2_assoc);
}


/**
 * Flush a line from the L2 cache
 * This should only be called from one core at a time, as this routine
 * sets the core to the 'debug' core in order to flush the line.
 *
 * @param assoc  Association (or way) to flush
 * @param index  Index to flush
 */
void bdk_l2c_flush_line(uint32_t assoc, uint32_t index)
{
    /* Check the range of the index. */
    if (index > (uint32_t)bdk_l2c_get_num_sets())
    {
        bdk_dprintf("ERROR: bdk_l2c_flush_line index out of range.\n");
        return;
    }

    /* Check the range of association. */
    if (assoc > (uint32_t)bdk_l2c_get_num_assoc())
    {
        bdk_dprintf("ERROR: bdk_l2c_flush_line association out of range.\n");
        return;
    }

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        uint64_t address;
        /* Create the address based on index and association.
           Bits<20:17> select the way of the cache block involved in
                       the operation
           Bits<16:7> of the effect address select the index */
        address = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS,
                               (assoc << BDK_L2C_TAG_ADDR_ALIAS_SHIFT) |
                               (index << BDK_L2C_IDX_ADDR_SHIFT));
        BDK_CACHE_WBIL2I(address, 0);
    }
    else
    {
        bdk_l2c_dbg_t l2cdbg;

        l2cdbg.u64 = 0;
        l2cdbg.s.ppnum = bdk_get_core_num();
        l2cdbg.s.finv = 1;

        l2cdbg.s.set = assoc;
        bdk_spinlock_lock(&bdk_l2c_spinlock);
        /* Enter debug mode, and make sure all other writes complete before we
        ** enter debug mode */
        BDK_SYNC;
        BDK_CSR_WRITE(BDK_L2C_DBG, l2cdbg.u64);
        BDK_CSR_READ(BDK_L2C_DBG);

        BDK_PREPARE_FOR_STORE (BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, index*BDK_CACHE_LINE_SIZE), 0);
        /* Exit debug mode */
        BDK_SYNC;
        BDK_CSR_WRITE(BDK_L2C_DBG, 0);
        BDK_CSR_READ(BDK_L2C_DBG);
        bdk_spinlock_unlock(&bdk_l2c_spinlock);
    }
}


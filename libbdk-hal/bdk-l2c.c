#include <bdk.h>

#define BDK_L2C_IDX_ADDR_SHIFT 7  /* based on 128 byte cache line size */
#define BDK_L2C_IDX_MASK       (bdk_l2c_get_num_sets() - 1)

/* Defines for index aliasing computations */
#define BDK_L2C_TAG_ADDR_ALIAS_SHIFT (BDK_L2C_IDX_ADDR_SHIFT + bdk_l2c_get_set_bits())
#define BDK_L2C_ALIAS_MASK (BDK_L2C_IDX_MASK << BDK_L2C_TAG_ADDR_ALIAS_SHIFT)
#define BDK_L2C_MEMBANK_SELECT_SIZE  4096


int bdk_l2c_get_core_way_partition(uint32_t core)
{
    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    return (BDK_CSR_READ(BDK_L2C_WPAR_PPX(core)) & 0xffff);
}

int bdk_l2c_set_core_way_partition(uint32_t core, uint32_t mask)
{
    uint32_t    valid_mask;

    valid_mask = (0x1 << bdk_l2c_get_num_assoc()) - 1;

    mask &= valid_mask;

    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    BDK_CSR_WRITE(BDK_L2C_WPAR_PPX(core), mask);
    return 0;
}


int bdk_l2c_set_hw_way_partition(uint32_t mask)
{
    uint32_t valid_mask;

    valid_mask = (0x1 << bdk_l2c_get_num_assoc()) - 1;
    mask &= valid_mask;

    BDK_CSR_WRITE(BDK_L2C_WPAR_IOBX(0), mask);
    return 0;
}

int bdk_l2c_get_hw_way_partition(void)
{
    return(BDK_CSR_READ(BDK_L2C_WPAR_IOBX(0)) & 0xffff);
}

void bdk_l2c_config_perf(uint32_t counter, bdk_l2c_event_t event,
                          uint32_t clear_on_read)
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

uint64_t bdk_l2c_read_perf(uint32_t counter)
{
    switch (counter)
    {
        case 0:
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC0(tad));
                return counter;
            }
        case 1:
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC1(tad));
                return counter;
            }
        case 2:
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC2(tad));
                return counter;
            }
        case 3:
        default:
            {
                uint64_t counter = 0;
                int tad;
                for (tad=0; tad<BDK_L2C_TADS; tad++)
                    counter += BDK_CSR_READ(BDK_L2C_TADX_PFC3(tad));
                return counter;
            }
    }
}

static int bdk_l2c_lock_line(uint64_t addr)
{
#if 1
    BDK_CACHE_LCKL2(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, addr), 0);
    return 0;
#else
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
        //bdk_error("bdk_l2c_lock_line: line not found for locking at 0x%llx address\n", (unsigned long long)addr);
        return -1;
    }

    /* Check if lock bit is not set */
    if (!l2c_tadx_tag.s.lock)
    {
        //bdk_error("bdk_l2c_lock_line: Not able to lock at 0x%llx address\n", (unsigned long long)addr);
        return -1;
    }

    return way;
#endif
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


static int bdk_l2c_unlock_line(uint64_t address)
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


bdk_l2c_tag_t bdk_l2c_get_tag(uint32_t association, uint32_t index)
{
    bdk_l2c_tag_t tag;
    tag.u64 = 0;

    if ((int)association >= bdk_l2c_get_num_assoc())
    {
        bdk_error("bdk_l2c_get_tag association out of range\n");
        return(tag);
    }
    if ((int)index >= bdk_l2c_get_num_sets())
    {
        bdk_error("bdk_l2c_get_tag index out of range (arg: %d, max: %d)\n", (int)index, bdk_l2c_get_num_sets());
        return(tag);
    }

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

    return tag;
}

uint32_t bdk_l2c_address_to_index (uint64_t addr)
{
    uint64_t idx = addr >> BDK_L2C_IDX_ADDR_SHIFT;
    int indxalias = 0;

    bdk_l2c_ctl_t l2c_ctl;
    l2c_ctl.u64 = BDK_CSR_READ(BDK_L2C_CTL);
    indxalias = !l2c_ctl.s.disidxalias;

    if (indxalias)
    {
        uint32_t a_14_12 = (idx / (BDK_L2C_MEMBANK_SELECT_SIZE/(1<<BDK_L2C_IDX_ADDR_SHIFT))) & 0x7;
        idx ^= idx / bdk_l2c_get_num_sets();
        idx ^= a_14_12;
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
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        l2_set_bits =  10; /* 1024 sets */
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        l2_set_bits =  11; /* 2048 sets */
    else
    {
        bdk_error("Unsupported OCTEON Model in %s\n", __FUNCTION__);
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

    /* Check to see if part of the cache is disabled */
    BDK_CSR_INIT(mio_fus_dat3, BDK_MIO_FUS_DAT3);
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
    else
        l2_assoc = 16;

    return(l2_assoc);
}


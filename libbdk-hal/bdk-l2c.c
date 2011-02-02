#include <bdk.h>

int bdk_l2c_get_core_way_partition(uint32_t core)
{
    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    return (BDK_CSR_READ(BDK_L2C_WPAR_PPX(core)) & 0xffff);
}

int bdk_l2c_set_core_way_partition(uint32_t core, uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc()) - 1;
    mask &= valid_mask;

    /* Validate the core number */
    if (core >= bdk_octeon_num_cores())
        return -1;

    BDK_CSR_WRITE(BDK_L2C_WPAR_PPX(core), mask);
    return 0;
}


int bdk_l2c_set_hw_way_partition(uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc()) - 1;
    mask &= valid_mask;

    BDK_CSR_WRITE(BDK_L2C_WPAR_IOBX(0), mask);
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_WRITE(BDK_L2C_WPAR_IOBX(1), mask);
    return 0;
}


int bdk_l2c_get_hw_way_partition(void)
{
    return (BDK_CSR_READ(BDK_L2C_WPAR_IOBX(0)) & 0xffff);
}


int bdk_l2c_lock_mem_region(uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;

    while (len)
    {
        BDK_CACHE_LCKL2(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, start), 0);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }
    return 0;
}


void bdk_l2c_flush(void)
{
    int n_set = bdk_l2c_get_num_sets();
    int n_assoc = bdk_l2c_get_num_assoc();
    int set_shift = 7;  /* based on 128 byte cache line size */
    int assoc_shift = set_shift + bdk_l2c_get_set_bits();

    for (int set=0; set < n_set; set++)
    {
        for(int assoc=0; assoc < n_assoc; assoc++)
        {
            uint64_t address = BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, (assoc << assoc_shift) | (set << set_shift));
            BDK_CACHE_WBIL2I(address, 0);
        }
    }
}


int bdk_l2c_unlock_mem_region(uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;

    while (len > 0)
    {
        BDK_CACHE_WBIL2(BDK_ADD_SEG(BDK_MIPS_SPACE_XKPHYS, start), 0);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }

    return 0;
}


int bdk_l2c_get_cache_size_bytes(void)
{
    return bdk_l2c_get_num_sets() * bdk_l2c_get_num_assoc() * BDK_CACHE_LINE_SIZE;
}


/**
 * Return log base 2 of the number of sets in the L2 cache
 * @return
 */
int bdk_l2c_get_set_bits(void)
{
    static int l2_set_bits = -1;

    if (l2_set_bits != -1)
        return l2_set_bits;

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        l2_set_bits =  10; /* 1024 sets */
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        l2_set_bits =  11; /* 2048 sets */
    else
    {
        bdk_error("Unsupported OCTEON Model in %s\n", __FUNCTION__);
        l2_set_bits =  11; /* 2048 sets */
    }
    return l2_set_bits;
}

/* Return the number of sets in the L2 Cache */
int bdk_l2c_get_num_sets(void)
{
    return 1 << bdk_l2c_get_set_bits();
}

/* Return the number of associations in the L2 Cache */
int bdk_l2c_get_num_assoc(void)
{
    static int l2_assoc = -1;

    if (l2_assoc != -1)
        return l2_assoc;

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


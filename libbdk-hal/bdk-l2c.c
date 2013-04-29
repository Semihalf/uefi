#include <bdk.h>

typedef struct
{
    int set_bits;
    int ways;
} l2_node_state_t;

static l2_node_state_t l2_node_state[BDK_NUMA_MAX_NODES];

/**
 * Perform one time initialization of L2 for improved
 * performance. This can be called after L2 is in use.
 *
 * @return Zero on success, negative on failure.
 */
int bdk_l2c_initialize(bdk_node_t node)
{
    if (!OCTEON_IS_MODEL(OCTEON_CN78XX) && !OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        /* Clear the IOB0 FIFO delay if the RCLK/SCLK ratio is less than 3 */
        uint64_t sclk = bdk_clock_get_rate(node, BDK_CLOCK_SCLK);
        uint64_t rclk = bdk_clock_get_rate(node, BDK_CLOCK_RCLK);
        if (rclk < sclk * 3)
        {
            if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            {
                BDK_CSR_MODIFY(c, node, BDK_IOB0_CTL_STATUS, c.s.fif_dly = 0);
                BDK_CSR_READ(node, BDK_IOB0_CTL_STATUS);
                BDK_CSR_MODIFY(c, node, BDK_IOB1_CTL_STATUS, c.s.fif_dly = 0);
                BDK_CSR_READ(node, BDK_IOB1_CTL_STATUS);
            }
            else
            {
                BDK_CSR_MODIFY(c, node, BDK_IOB_CTL_STATUS, c.s.fif_dly = 0);
                BDK_CSR_READ(node, BDK_IOB_CTL_STATUS);
            }
        }
    }

    /* Tell L2 to give the IOB statically higher priority compared to the
        cores. This avoids conditions where IO blocks might be starved under
        very high L2 loads */
    BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
        c.s.rsp_arb_mode = 1;
        c.s.xmc_arb_mode = 0);

    return 0;
}

int bdk_l2c_get_core_way_partition(bdk_node_t node, int core)
{
    /* Validate the core number */
    if (core >= bdk_octeon_num_cores(node))
        return -1;

    return (BDK_CSR_READ(node, BDK_L2C_WPAR_PPX(core)) & 0xffff);
}

int bdk_l2c_set_core_way_partition(bdk_node_t node, int core, uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc(node)) - 1;
    mask &= valid_mask;

    /* Validate the core number */
    if (core >= bdk_octeon_num_cores(node))
        return -1;

    BDK_CSR_WRITE(node, BDK_L2C_WPAR_PPX(core), mask);
    return 0;
}


int bdk_l2c_set_hw_way_partition(bdk_node_t node, uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc(node)) - 1;
    mask &= valid_mask;

    BDK_CSR_WRITE(node, BDK_L2C_WPAR_IOBX(0), mask);
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_WRITE(node, BDK_L2C_WPAR_IOBX(1), mask);
    return 0;
}


int bdk_l2c_get_hw_way_partition(bdk_node_t node)
{
    return (BDK_CSR_READ(node, BDK_L2C_WPAR_IOBX(0)) & 0xffff);
}


int bdk_l2c_lock_mem_region(bdk_node_t node, uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;
    start |= 1ull << 63; /* Convert to XKPHYS */

    while (len)
    {
        BDK_CACHE_LCKL2(start, 0);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }
    return 0;
}


void bdk_l2c_flush(bdk_node_t node)
{
    int n_set = bdk_l2c_get_num_sets(node);
    int n_assoc = bdk_l2c_get_num_assoc(node);
    int set_shift = 7;  /* based on 128 byte cache line size */
    int assoc_shift = set_shift + bdk_l2c_get_set_bits(node);

    for (int set=0; set < n_set; set++)
    {
        for(int assoc=0; assoc < n_assoc; assoc++)
        {
            uint64_t address = (1ull<<63) | (assoc << assoc_shift) | (set << set_shift);
            BDK_CACHE_WBIL2I(address, 0);
        }
    }
}


int bdk_l2c_unlock_mem_region(bdk_node_t node, uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;
    start |= 1ull << 63; /* Convert to XKPHYS */

    while (len > 0)
    {
        BDK_CACHE_WBIL2(start, 0);
        start += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }

    return 0;
}


int bdk_l2c_get_cache_size_bytes(bdk_node_t node)
{
    return bdk_l2c_get_num_sets(node) * bdk_l2c_get_num_assoc(node) * BDK_CACHE_LINE_SIZE;
}


/**
 * Return log base 2 of the number of sets in the L2 cache
 * @return
 */
int bdk_l2c_get_set_bits(bdk_node_t node)
{
    if (bdk_unlikely(l2_node_state[node].set_bits == 0))
    {
        int l2_set_bits;
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            l2_set_bits =  11; /* 2048 sets */
        else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
            l2_set_bits =  9; /* 512 sets */
        else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            l2_set_bits =  13; /* 8192 sets */
        else if (OCTEON_IS_MODEL(OCTEON_CN70XX))
            l2_set_bits =  13; /* FIXME: Should be 1024 sets */
        else
        {
            bdk_error("Unsupported OCTEON Model in %s\n", __FUNCTION__);
            l2_set_bits =  11; /* 2048 sets */
        }
        l2_node_state[node].set_bits = l2_set_bits;
    }
    return l2_node_state[node].set_bits;
}

/* Return the number of sets in the L2 Cache */
int bdk_l2c_get_num_sets(bdk_node_t node)
{
    return 1 << bdk_l2c_get_set_bits(node);
}

/* Return the number of associations in the L2 Cache */
int bdk_l2c_get_num_assoc(bdk_node_t node)
{
    if (bdk_unlikely(l2_node_state[node].ways == 0))
    {
        int l2_assoc;
        /* Check to see if part of the cache is disabled */
        BDK_CSR_INIT(mio_fus_dat3, node, BDK_MIO_FUS_DAT3);
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

        /* CN70XX always is 4 way */
        if (OCTEON_IS_MODEL(OCTEON_CN70XX))
            l2_assoc = 4;

        l2_node_state[node].ways = l2_assoc;
    }
    return l2_node_state[node].ways;
}


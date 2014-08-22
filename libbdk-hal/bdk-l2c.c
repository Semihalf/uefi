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
    /* Tell L2 to give the IOB statically higher priority compared to the
        cores. This avoids conditions where IO blocks might be starved under
        very high L2 loads */
    BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
        c.s.rsp_arb_mode = 1;
        c.s.xmc_arb_mode = 0);

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && !bdk_is_simulation())
    {
        /* Errata: (L2C-22279) RCAS/RSTC which hits S/S can use wrong compare data */
        BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
            c.s.dissblkdty = 1);
        /* Errata: (L2C-22249) Broadcast invals can cause starvation on the INV bus */
        for (int i = 0; i < 4; i++)
            BDK_CSR_MODIFY(c, node, BDK_L2C_CBCX_SCRATCH(i),
                c.cn88xx.invdly = 1);
    }
    return 0;
}

int bdk_l2c_get_core_way_partition(bdk_node_t node, int core)
{
    return (BDK_CSR_READ(node, BDK_L2C_WPAR_PPX(core)) & 0xffff);
}

int bdk_l2c_set_core_way_partition(bdk_node_t node, int core, uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc(node)) - 1;
    mask &= valid_mask;

    BDK_CSR_WRITE(node, BDK_L2C_WPAR_PPX(core), mask);
    return 0;
}


int bdk_l2c_set_hw_way_partition(bdk_node_t node, uint32_t mask)
{
    uint32_t valid_mask = (1 << bdk_l2c_get_num_assoc(node)) - 1;
    mask &= valid_mask;

    BDK_CSR_WRITE(node, BDK_L2C_WPAR_IOBX(0), mask);
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
    void *ptr = bdk_phys_to_ptr(start);

    while (len)
    {
        BDK_CACHE_LCKL2(ptr);
        ptr += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }
    return 0;
}

#if 0 /* Disable bdk_l2c_flush() until implemented */
void bdk_l2c_flush(bdk_node_t node)
{
}
#endif


int bdk_l2c_unlock_mem_region(bdk_node_t node, uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;
    void *ptr = bdk_phys_to_ptr(start);

    while (len > 0)
    {
        BDK_CACHE_WBIL2(ptr);
        ptr += BDK_CACHE_LINE_SIZE;
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
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
            l2_set_bits =  13; /* 8192 sets */
        else
        {
            bdk_error("Unsupported Cavium Model in %s\n", __FUNCTION__);
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
        /* Get the starting number of associations */
        l2_assoc = 16;
        /* The l2 can be reduced in 25% increments */
        BDK_CSR_INIT(mio_fus_dat3, node, BDK_MIO_FUS_DAT3);
        switch (mio_fus_dat3.s.l2c_crip)
        {
            case 3: /* 1/4 size */
                l2_assoc *= 1;
                break;
            case 2: /* 1/2 size */
                l2_assoc *= 2;
                break;
            case 1: /* 3/4 size */
                l2_assoc *= 3;
                break;
            default: /* Full size */
                l2_assoc *= 4;
                break;
        }
        l2_node_state[node].ways = l2_assoc/4;
    }
    return l2_node_state[node].ways;
}


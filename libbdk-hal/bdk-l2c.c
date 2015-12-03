#include <bdk.h>

typedef struct
{
    int sets;
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

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && !bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* Errata: (L2C-22279) RCAS/RSTC which hits S/S can use wrong compare data */
        BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
            c.s.dissblkdty = 1);
        /* Errata: (L2C-22249) Broadcast invals can cause starvation on the INV bus */
        for (int i = 0; i < 4; i++)
            BDK_CSR_MODIFY(c, node, BDK_L2C_CBCX_SCRATCH(i),
                c.s.invdly = 1);
    }

    // FIXME: Disable partial writes on pass 2 until it is debugged
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && !bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
            c.s.dissblkdty = 1);
    }

    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        /* The emulator requires L2C_CTL[DISSBLKDTY] to be set */
        BDK_CSR_MODIFY(c, node, BDK_L2C_CTL,
            c.s.dissblkdty = 1);
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
    void *ptr = (start) ? bdk_phys_to_ptr(start) : NULL;

    while (len)
    {
        BDK_CACHE_LCK_L2(ptr);
        ptr += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }
    return 0;
}

void bdk_l2c_flush(bdk_node_t node)
{
    /* The number of ways can be reduced with fuses, but the equations below
       assume the max number of ways */
    const int MAX_WAYS = 16;
    int num_sets = bdk_l2c_get_num_sets(node);
    int num_ways = bdk_l2c_get_num_assoc(node);

    int is_rtg = 1; /* Clear remote tags */
    for (int l2_way = 0; l2_way < num_ways; l2_way++)
    {
        for (int l2_set = 0; l2_set < num_sets; l2_set++)
        {
            uint64_t encoded = 128 * (l2_set + num_sets * (l2_way + (is_rtg * MAX_WAYS)));
            BDK_CACHE_WBI_L2_INDEXED(encoded);
        }
    }

    is_rtg = 0; /* Clear local tags */
    for (int l2_way = 0; l2_way < num_ways; l2_way++)
    {
        for (int l2_set = 0; l2_set < num_sets; l2_set++)
        {
            uint64_t encoded = 128 * (l2_set + num_sets * (l2_way + (is_rtg * MAX_WAYS)));
            BDK_CACHE_WBI_L2_INDEXED(encoded);
        }
    }
}

int bdk_l2c_unlock_mem_region(bdk_node_t node, uint64_t start, uint64_t len)
{
    /* Round start/end to cache line boundaries */
    len += start & BDK_CACHE_LINE_MASK;
    start &= ~BDK_CACHE_LINE_MASK;
    len = (len + BDK_CACHE_LINE_MASK) & ~BDK_CACHE_LINE_MASK;
    void *ptr = (start) ? bdk_phys_to_ptr(start) : NULL;

    while (len > 0)
    {
        /* Must use invalidate version to release lock */
        BDK_CACHE_WBI_L2(ptr);
        ptr += BDK_CACHE_LINE_SIZE;
        len -= BDK_CACHE_LINE_SIZE;
    }

    return 0;
}


int bdk_l2c_get_cache_size_bytes(bdk_node_t node)
{
    return bdk_l2c_get_num_sets(node) * bdk_l2c_get_num_assoc(node) * BDK_CACHE_LINE_SIZE;
}

/* Return the number of sets in the L2 Cache */
int bdk_l2c_get_num_sets(bdk_node_t node)
{
    if (bdk_unlikely(l2_node_state[node].sets == 0))
    {
        /* Select the L2 cache */
        bdk_ap_csselr_el1_t csselr_el1;
        csselr_el1.u = 0;
        csselr_el1.s.ind = 0;
        csselr_el1.s.level = 1;
        BDK_MSR(CSSELR_EL1, csselr_el1.u);
        /* Read its size */
        bdk_ap_ccsidr_el1_t ccsidr_el1;
        BDK_MRS(CCSIDR_EL1, ccsidr_el1.u);
        /* Store it for use later */
        l2_node_state[node].sets = ccsidr_el1.s.numsets + 1;
        l2_node_state[node].ways = ccsidr_el1.s.associativity + 1;

        /* Early chips didn't update the number of ways based on fusing */
        if (l2_node_state[node].ways == 16)
        {
            /* The l2 can be reduced in 25% increments */
            BDK_CSR_INIT(mio_fus_dat3, node, BDK_MIO_FUS_DAT3);
            switch (mio_fus_dat3.s.l2c_crip)
            {
                case 3: /* 1/4 size */
                    l2_node_state[node].ways *= 1;
                    break;
                case 2: /* 1/2 size */
                    l2_node_state[node].ways *= 2;
                    break;
                case 1: /* 3/4 size */
                    l2_node_state[node].ways *= 3;
                    break;
                default: /* Full size */
                    l2_node_state[node].ways *= 4;
                    break;
            }
            l2_node_state[node].ways /= 4;
        }
    }
    return l2_node_state[node].sets;
}

/* Return the number of associations in the L2 Cache */
int bdk_l2c_get_num_assoc(bdk_node_t node)
{
    /* Get the number of sets if the global sets/ways is not setup */
    if (bdk_unlikely(l2_node_state[node].ways == 0))
        bdk_l2c_get_num_sets(node);
    return l2_node_state[node].ways;
}

/* Return the number of locked ways in the L2 Cache */
int bdk_l2c_get_num_locked(bdk_node_t node)
{
    /* The number of ways can be reduced with fuses, but the equations below
       assume the max number of ways */
    const int MAX_WAYS = 16;
    int num_sets = bdk_l2c_get_num_sets(node);
    int num_ways = bdk_l2c_get_num_assoc(node);
    int is_rtg;
    int locked = 0;

#if 0
    // FIXME: for now no remotes
    is_rtg = 1; /* Read the remote tags */
    for (int l2_way = 0; l2_way < num_ways; l2_way++)
    {
        for (int l2_set = 0; l2_set < num_sets; l2_set++)
        {
            uint64_t encoded = 128 * (l2_set + num_sets * (l2_way + (is_rtg * MAX_WAYS)));
            BDK_CACHE_WBI_L2_INDEXED(encoded);
        }
    }
#endif

    is_rtg = 0; /* Read the local tags */
    for (int l2_way = 0; l2_way < num_ways; l2_way++)
    {
        for (int l2_set = 0; l2_set < num_sets; l2_set++)
        {
	    bdk_l2c_tadx_tag_t tag;
            uint64_t encoded = 128 * (l2_set + num_sets * (l2_way + (is_rtg * MAX_WAYS)));
	    int tadno = (encoded >> 8) & 7; // which TAD, so we can read its TAG

            BDK_CACHE_LTG_L2_INDEXED(encoded);
	    BDK_DSB;
            tag.u = BDK_CSR_READ(node, BDK_L2C_TADX_TAG(tadno));
	    if ((tag.s.ts != 0) && tag.s.lock) {
		locked++;
	    }
        }
    }
    return locked;
}

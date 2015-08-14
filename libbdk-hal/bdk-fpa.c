#include <bdk.h>
#include <malloc.h>

bdk_spinlock_t fpa_lock;
__bdk_fpa_state_t __bdk_fpa_node_state[BDK_NUMA_MAX_NODES];

/**
 * Global FPA initialization
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_fpa_init(bdk_node_t node)
{
    int result = 0;
    __bdk_fpa_state_t *fpa_state = &__bdk_fpa_node_state[node];

    bdk_spinlock_lock(&fpa_lock);

    if (!fpa_state->init_done)
    {
        BDK_TRACE(FPA, "N%d: FPA: Performing global init\n", node);

        bdk_zero_memory(fpa_state, sizeof(*fpa_state));
        /* Reserve the first auras for 1:1 mapping to pools */
        fpa_state->next_free_aura = BDK_FPA_NUM_POOLS;

        uint64_t bist = BDK_CSR_READ(node, BDK_FPA_BIST_STATUS);
        if (bist)
            bdk_error("FPA reports BIST failures (0x%lx)\n", bist);

        /* Limit to only NUM_POOLS pools */
        int pool_divide;
        BDK_CSR_INIT(fpa_const, node, BDK_FPA_CONST);
        if (BDK_FPA_NUM_POOLS > fpa_const.s.pools)
            bdk_fatal("FPA configured for more pools that hardware supports\n");
        if (BDK_FPA_NUM_POOLS > fpa_const.s.pools / 2)
            pool_divide = 1; /* Use all pools */
        else
            pool_divide = 2; /* Use half the number of pools */

        BDK_CSR_MODIFY(c, node, BDK_FPA_GEN_CFG,
            c.s.lvl_dly = 3; /* Levelizer delay */
            c.s.pools = pool_divide);
        fpa_state->init_done = 1;
    }

    bdk_spinlock_unlock(&fpa_lock);
    return result;
}

/**
 * Fill a pool with buffers
 *
 * @param node       Node to use in a Numa setup. See bdk-numa.h
 * @param pool       Pool to initialize (0 <= pool < BDK_FPA_NUM_POOLS)
 * @param num_blocks Number of blocks
 *
 * @return Zero on Success, negative on failure
 */
int bdk_fpa_fill_pool(bdk_node_t node, bdk_fpa_pool_t pool, int num_blocks)
{
    __bdk_fpa_state_t *fpa_state = &__bdk_fpa_node_state[node];
    if (!fpa_state->init_done)
    {
        int result = __bdk_fpa_init(node);
        if (result)
            return result;
    }

    /* Get FPA config info */
    BDK_CSR_INIT(fpa_const, node, BDK_FPA_CONST);
    BDK_CSR_INIT(fpa_gen_cfg, node, BDK_FPA_GEN_CFG);

    int block_size = 0;
    switch (pool)
    {
        case BDK_FPA_PACKET_POOL: /* Stores PKI packet buffers */
            block_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);
            break;
        case BDK_FPA_SSO_POOL: /* Used for internal storage in the SSO */
        {
            BDK_CSR_INIT(sso_const1, node, BDK_SSO_CONST1);
            block_size = sso_const1.s.xaq_buf_size;
            break;
        }
        case BDK_FPA_PKO_POOL: /* Used for queue storage in the PKO */
        {
            BDK_CSR_INIT(pko_const, node, BDK_PKO_CONST);
            block_size = pko_const.s.pdm_buf_size;
            break;
        }
    }
    if (block_size == 0)
        bdk_fatal("Unable to determine FPA block size for pool %d\n", pool);

    BDK_TRACE(FPA, "N%d: FPA: Fill pool %d with %d blocks of %d bytes\n", node, pool, num_blocks, block_size);

    uint64_t stack_size = BDK_CACHE_LINE_SIZE * ((num_blocks + fpa_const.s.stk_ln_ptrs - 1) / fpa_const.s.stk_ln_ptrs);
    uint64_t pool_size = num_blocks * block_size;

    void *buf = memalign(block_size, pool_size + stack_size);
    if (!buf)
    {
        bdk_error("N%d FPA: pool %d failed memory allocation\n", node, pool);
        return -num_blocks;
    }

    bdk_zero_memory(buf, pool_size + stack_size);

    uint64_t pool_start = bdk_ptr_to_phys(buf);
    uint64_t stack_start = pool_start + pool_size;
    uint64_t stack_end = stack_start + stack_size;
    BDK_TRACE(FPA, "N%d FPA: pool %d uses 0x%lx - 0x%lx with links in 0x%lx - 0x%lx\n",
        node, pool, pool_start, stack_start-1, stack_start, stack_end-1);

    /* Set the pool to be at the front */
    BDK_CSR_WRITE(node, BDK_FPA_VHPOOLX_START_ADDR(pool), pool_start);
    BDK_CSR_WRITE(node, BDK_FPA_VHPOOLX_END_ADDR(pool), stack_start);

    /* Set the stack to be at the back */
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_BASE(pool), stack_start);
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_ADDR(pool), stack_start);
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_END(pool), stack_end);

    /* Optimize the FPA internal storage */
    int fpf_sz = fpa_const.s.fpfs * (fpa_const.s.pools >> (fpa_gen_cfg.s.pools - 1));
    int fpf_rd = fpf_sz * 3 / 4;
    if (fpf_rd > fpf_sz - 48)
        fpf_rd = fpf_sz - 48;
    BDK_CSR_MODIFY(c, node, BDK_FPA_POOLX_FPF_MARKS(pool),
        c.s.fpf_rd = fpf_rd);

    /* Configure the pool */
    BDK_CSR_MODIFY(c, node, BDK_FPA_POOLX_CFG(pool),
        c.s.buf_size = block_size / BDK_CACHE_LINE_SIZE;
        c.s.buf_offset = 0;
        c.s.l_type = (BDK_USE_DWB) ? 2 : 0;
        c.s.nat_align = 1;
        c.s.ena = 1);

    fpa_state->buffer_size_pool[pool] = block_size;

    /* Create an aura that 1:1 maps the pool */
    int aura = bdk_fpa_init_aura(node, pool, pool, num_blocks);
    if (aura < 0)
        return -1;

    /* Adding buffers decrement the aura count. Update the count
        for the new buffers */
    BDK_CSR_WRITE(node, BDK_FPA_VHAURAX_CNT_ADD(aura), num_blocks);

    /* Free the buffers */
    while (num_blocks--)
    {
        bdk_fpa_free(node, buf, aura, 0);
        buf += block_size;
    }
    return 0;
}

/**
 * Initialize an Aura for a specific pool
 *
 * @param node       Node to use in a Numa setup. See bdk-numa.h
 * @param aura       Aura to initialize, or -1 to dynamically allocate a free aura
 * @param pool       Pool this aura is for (0 <= pool < BDK_FPA_NUM_POOLS)
 * @param num_blocks Number of buffers to allow this aura to contain. This may be different
 *                   from the pool
 *
 * @return Aura number or negative on failure
 */
int bdk_fpa_init_aura(bdk_node_t node, int aura, bdk_fpa_pool_t pool, int num_blocks)
{
    __bdk_fpa_state_t *fpa_state = &__bdk_fpa_node_state[node];
    BDK_CSR_INIT(fpa_const, node, BDK_FPA_CONST);

    int pool_num_blocks = (pool < BDK_FPA_NUM_POOLS) ? num_blocks : (int)BDK_CSR_READ(node, BDK_FPA_VHPOOLX_AVAILABLE(pool));

    if (BDK_FPA_NUM_AURAS > fpa_const.s.auras)
        bdk_fatal("BDK_FPA_NUM_AURAS > FPA_CONST[AURAS], change bdk-fpa.h\n");

    if (aura < 0)
    {
        if (fpa_state->next_free_aura >= fpa_const.s.auras)
        {
            bdk_error("No more FPA auras available\n");
            return -1;
        }
        aura = fpa_state->next_free_aura++;
    }

    /* Set auto tracking of counts and disable averaging */
    BDK_CSR_MODIFY(c, node, BDK_FPA_AURAX_CFG(aura),
        c.s.ptr_dis = 0;
        c.s.avg_con = 0);

    /* Figure out the optimal shift amount for sizes */
    int shift = 0;
    while ((num_blocks>>shift) >= 256)
        shift++;
    int pool_shift = 0;
    while ((pool_num_blocks>>pool_shift) >= 256)
        pool_shift++;

    /* Start count at zero */
    BDK_CSR_WRITE(node, BDK_FPA_VHAURAX_CNT(aura), 0);
    /* Assign to a pool */
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_POOL(aura), pool);
    /* Limit to not overflow */
    BDK_CSR_WRITE(node, BDK_FPA_VHAURAX_CNT_LIMIT(aura), num_blocks);
    /* Set backpressure limits based on aura count. This affects only
       this channel and is unrelated to the pool */
    BDK_CSR_MODIFY(c, node, BDK_FPA_AURAX_CNT_LEVELS(aura),
        c.s.drop_dis = 0;                   /* Dropping is enabled */
        c.s.bp_ena = 1;                     /* Enable backpressure based on [BP] level */
        c.s.red_ena = 1;                    /* Enable RED */
        c.s.shift = shift;                  /* Right shift to apply to FPA_AURA()_CNT */
        c.s.bp = (num_blocks/2)>>shift;     /* Backpressure when half empty */
        c.s.drop = (num_blocks)>>shift;     /* Drop everything when empty (If DROP is enabled) */
        c.s.pass = (num_blocks*3/4)>>shift);/* Start dropping when 3/4 empty (If RED is enabled) */
    /* Set backpressure limits based on pool count. These affect all channels
       based on the underlying pool */
    BDK_CSR_MODIFY(c, node, BDK_FPA_AURAX_POOL_LEVELS(aura),
        c.s.drop_dis = 0;                   /* Dropping is enabled */
        c.s.bp_ena = 1;                     /* Enable backpressure based on [BP] level */
        c.s.red_ena = 1;                    /* Enable RED */
        c.s.shift = pool_shift;             /* Optimal shift calculated earlier */
        c.s.bp = (pool_num_blocks/2)>>pool_shift; /* Start backpressure when pool is 1/2 empty */
        c.s.drop = 0;                       /* Drop everything when the pool is completely empty */
        c.s.pass = (pool_num_blocks*1/4)>>pool_shift); /* Begin dropping when 3/4 of buffers are in use */
    /* Disable the threshold */
    BDK_CSR_WRITE(node, BDK_FPA_VHAURAX_CNT_THRESHOLD(aura), 0xffffffffffull);
    /* Remember the buffer size */
    fpa_state->buffer_size_aura[aura] = fpa_state->buffer_size_pool[pool];
    BDK_TRACE(FPA, "N%d: FPA: Init aura %d for pool %d with %d blocks\n", node, aura, pool, num_blocks);
    return aura;
}


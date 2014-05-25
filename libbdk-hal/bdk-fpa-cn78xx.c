#include <bdk.h>
#include <malloc.h>

#define NUM_POOLS 16 /* Can be 16, 32, or 64 */
#define NUM_AURAS 1024
#define PTRS_PER_LINE 29

typedef struct
{
    int buffer_size_pool[NUM_POOLS];
    int buffer_size_aura[NUM_AURAS];
    int next_free_aura;
} bdk_fpa_state_t;

static bdk_fpa_state_t fpa_node_state[BDK_NUMA_MAX_NODES];

/**
 * Perform global FPA initialization
 */
static int fpa_init(bdk_node_t node)
{
    bdk_fpa_state_t *fpa_state = &fpa_node_state[node];

    bdk_zero_memory(fpa_state, sizeof(*fpa_state));
    /* Reserve the first auras for 1:1 mapping to pools */
    fpa_state->next_free_aura = NUM_POOLS;

    uint64_t bist = BDK_CSR_READ(node, BDK_FPA_BIST_STATUS);
    if (bist)
        bdk_error("FPA reports BIST failures (0x%lx)\n", bist);

    /* Limit to only NUM_POOLS pools */
    int pool_divide;
    if (NUM_POOLS <= 16)
        pool_divide = 2;
    else if (NUM_POOLS <= 32)
        pool_divide = 1;
    else
        pool_divide = 0;

    BDK_CSR_MODIFY(c, node, BDK_FPA_GEN_CFG,
        c.s.lvl_dly = 3; /* Levelizer delay */
        c.s.pools = pool_divide);

    /* Clear global errors */
    BDK_CSR_WRITE(node, BDK_FPA_ERR_INT, 0xf);
    return 0;
}

/**
 * Initialize an Aura for a specific pool
 *
 * @param aura       Aura to initialize, or -1 to dynamically allocate one
 * @param pool       Pool this aura is for
 * @param num_blocks Number of buffers to allow this aura to contain. This may be
 *                   different from the pool
 *
 * @return Aura number or negative on failure
 */
static int fpa_init_aura(bdk_node_t node, int aura, int pool, int num_blocks)
{
    bdk_fpa_state_t *fpa_state = &fpa_node_state[node];

    int pool_num_blocks = (pool < (int)NUM_POOLS) ? num_blocks : BDK_CSR_READ(node, BDK_FPA_POOLX_AVAILABLE(pool));

    if (aura < 0)
    {
        if (fpa_state->next_free_aura >= NUM_AURAS)
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
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_CNT(aura), 0);
    /* Assign to a pool */
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_POOL(aura), pool);
    /* Limit to not overflow */
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_CNT_LIMIT(aura), num_blocks);
    /* Set backpressure limits based on aura count. This affects only
       this channel and is unrelated to the pool. If we had unlimited
       memory we'd set this so all the channels added up to less than
       the pool. Unfortunately that isn't the case, so we don't use RED
       here */
    BDK_CSR_MODIFY(c, node, BDK_FPA_AURAX_CNT_LEVELS(aura),
        c.s.bp_ena = 1;                     /* Enable backpressure based on [BP] level */
        c.s.red_ena = 0;                    /* Don't use RED. Wait till the pool does it (below) */
        c.s.shift = shift;                  /* Right shift to apply to FPA_AURA(0..1023)_CNT */
        c.s.bp = (num_blocks/2)>>shift;     /* Backpressure when half empty */
        c.s.drop = (num_blocks)>>shift;     /* Drop everything when empty (If RED was enabled) */
        c.s.pass = (num_blocks*3/4)>>shift);/* Start dropping when 3/4 empty (If RED was enabled) */
    /* Set backpressure limits based on pool count. These affect all channels
       based on the underlying pool */
    BDK_CSR_MODIFY(c, node, BDK_FPA_AURAX_POOL_LEVELS(aura),
        c.s.bp_ena = 1;
        c.s.red_ena = 1;
        c.s.shift = pool_shift;
        c.s.bp = (pool_num_blocks/2)>>pool_shift;       /* Start backpressure when pool is 1/2 empty */
        c.s.drop = 0;                                   /* Drop everything when the pool is completely empty */
        c.s.pass = (pool_num_blocks*1/4)>>pool_shift);  /* Begin dropping when 3/4 of buffers are in use */
    /* Disable the threshold */
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_CNT_THRESHOLD(aura), 0xffffffffffull);
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_INT(aura), 1);

    fpa_state->buffer_size_aura[aura] = fpa_state->buffer_size_pool[pool];
    return aura;
}

/**
 * Initialize a single FPA pool. An aura of the same number will
 * also be setup to match it.
 *
 * @param pool       Pool to initialize
 * @param num_blocks Number of buffers to put in the pool
 * @param block_size Size of each buffer
 *
 * @return Zero on success, negative on failure
 */
static int fpa_init_pool(bdk_node_t node, int pool, int num_blocks, int block_size)
{
    bdk_fpa_state_t *fpa_state = &fpa_node_state[node];

    uint64_t stack_size = BDK_CACHE_LINE_SIZE * ((num_blocks + PTRS_PER_LINE - 1) / PTRS_PER_LINE);
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
    //bdk_dprintf("N%d FPA: pool %d uses 0x%lx - 0x%lx with links in 0x%lx - 0x%lx\n",
    //    node, pool, pool_start, stack_start-1, stack_start, stack_end-1);

    /* Set the pool to be at the front */
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_START_ADDR(pool), pool_start);
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_END_ADDR(pool), stack_start);

    /* Set the stack to be at the back */
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_BASE(pool), stack_start);
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_ADDR(pool), stack_start);
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_STACK_END(pool), stack_end);

    /* Clear any pool error interrupts */
    BDK_CSR_WRITE(node, BDK_FPA_POOLX_INT(pool), 0xf);

    /* Optimize the FPA internal storage */
    BDK_CSR_INIT(fpa_gen_cfg, node, BDK_FPA_GEN_CFG);
    int fpf_size = 320 * (1 << fpa_gen_cfg.s.pools);
    int marks = fpf_size * 3 / 4;
    BDK_CSR_MODIFY(c, node, BDK_FPA_POOLX_FPF_MARKS(pool),
        c.s.fpf_rd = marks);

    /* Configure the pool */
    BDK_CSR_MODIFY(c, node, BDK_FPA_POOLX_CFG(pool),
        c.s.buf_size = block_size / BDK_CACHE_LINE_SIZE;
        c.s.buf_offset = 0;
        c.s.l_type = (BDK_USE_DWB) ? 2 : 0;
        c.s.nat_align = 1;
        c.s.ena = 1);

    fpa_state->buffer_size_pool[pool] = block_size;

    /* Create an aura that 1:1 maps the pool */
    int aura = fpa_init_aura(node, pool, pool, num_blocks);
    if (aura < 0)
        return -1;

    /* Adding buffers decrement the aura count. Update the count
        for the new buffers */
    BDK_CSR_WRITE(node, BDK_FPA_AURAX_CNT_ADD(aura), num_blocks);

    /* Free the buffers */
    while (num_blocks--)
    {
        bdk_fpa_free(node, buf, aura, 0);
        buf += block_size;
    }
    return 0;
}

/**
 * Get the buffer size for an aura
 *
 * @param aura   Aura to get
 *
 * @return Size of the buffer in bytes
 */
static int fpa_get_block_size(bdk_node_t node, int aura)
{
    bdk_fpa_state_t *fpa_state = &fpa_node_state[node];
    return fpa_state->buffer_size_aura[aura];
}

/**
 * Get a new block from the FPA
 *
 * @param aura   Aura to get the block from
 *
 * @return Pointer to the block or NULL on failure
 */
static uint64_t fpa_alloc(bdk_node_t node, int aura)
{
    uint64_t address = 0x800129ull << 40;
    address |= (uint64_t)node << 36;
    /* address |= 0ull << 35; Don't use RED */
    address |= aura << 16;
    address = bdk_read64_uint64(address);
    //bdk_dprintf("N%d FPA alloc aura=%d addr=0x%lx\n", node, aura, address);
    return address;
}

/**
 * Free a block allocated with a FPA aura.  Doesn't provided required memory
 * ordering in cases where memory block was modified by core.
 *
 * @param address Block to free
 * @param aura    Aura to put it in
 * @param num_cache_lines
 *                Cache lines to invalidate
 */
static void fpa_free(bdk_node_t node, uint64_t address, int aura, int num_cache_lines)
{
    uint64_t store = 0x800129ull << 40;
    store |= (uint64_t)node << 36;
    store |= aura << 16;
    /* store |= 0 << 15; Not absolute */
    store |= num_cache_lines << 3;
    //bdk_dprintf("N%d FPA free aura=%d addr=0x%lx\n", node, aura, address);
    bdk_write64_uint64(store, address);
}

bdk_fpa_ops_t __bdk_fpa_ops_cn78xx = {
    .init = fpa_init,
    .init_pool = fpa_init_pool,
    .init_aura = fpa_init_aura,
    .get_block_size = fpa_get_block_size,
    .alloc = fpa_alloc,
    .free = fpa_free,
};


#include <bdk.h>
#include <malloc.h>

#define NUM_POOLS 8
static int fpa_buffer_size_pool[NUM_POOLS];

/**
 * Perform global FPA initialization
 */
static int fpa_init(bdk_node_t node)
{
    bdk_zero_memory(fpa_buffer_size_pool, sizeof(fpa_buffer_size_pool));

    /* Initialize the range checking so that no memory is in range */
    for (int i=0; i<NUM_POOLS; i++)
    {
        BDK_CSR_WRITE(node, BDK_FPA_POOLX_START_ADDR(i), 0xffffffffull);
        BDK_CSR_WRITE(node, BDK_FPA_POOLX_END_ADDR(i), 0);
    }
    BDK_CSR_MODIFY(status, node, BDK_FPA_CTL_STATUS,
        status.s.enb = 1);
    return 0;
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
    void *buf = memalign(BDK_CACHE_LINE_SIZE, num_blocks * block_size);
    if (!buf)
    {
        bdk_error("bdk_fpa_fill_pool: Pool %d failed with %d blocks to alloc\n", pool, num_blocks);
        return -num_blocks;
    }

    bdk_zero_memory(buf, num_blocks * block_size);

    {
        /* Update the start address to contain the new memory */
        uint64_t addr = bdk_ptr_to_phys(buf);
        BDK_CSR_INIT(start_addr, node, BDK_FPA_POOLX_START_ADDR(pool));
        /* Being always helpful, the HW team decided to change the format of the start address on CN78XX */
        uint64_t start = OCTEON_IS_MODEL(OCTEON_CN78XX) ? start_addr.cn78xx.addr : start_addr.cn70xx.addr;
        if (addr>>7 < start)
        {
            start = addr>>7;
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
                start <<= 7;
            BDK_CSR_WRITE(node, BDK_FPA_POOLX_START_ADDR(pool), start);
            BDK_CSR_READ(node, BDK_FPA_POOLX_START_ADDR(pool));
        }

        /* The end address needs to only contain the last buffers address,
            not the full buffer */
        addr += (num_blocks-1) * block_size;
        BDK_CSR_INIT(end_addr, node, BDK_FPA_POOLX_END_ADDR(pool));
        /* Being always helpful, the HW team decided to change the format of the end address on CN78XX */
        uint64_t end = OCTEON_IS_MODEL(OCTEON_CN78XX) ? end_addr.cn78xx.addr : end_addr.cn70xx.addr;
        if (addr>>7 > end)
        {
            end = addr>>7;
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
                end <<= 7;
            BDK_CSR_WRITE(node, BDK_FPA_POOLX_END_ADDR(pool), end);
            BDK_CSR_READ(node, BDK_FPA_POOLX_END_ADDR(pool));
        }
    }

    while (num_blocks--)
    {
        bdk_fpa_free(node, buf, pool, 0);
        buf += block_size;
    }
    fpa_buffer_size_pool[pool] = block_size;
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
    return fpa_buffer_size_pool[aura];
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
    uint64_t address = (0x800128ull + aura) << 40;
    return bdk_read64_uint64(address);
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
    address |= (0x800128ull + aura) << 40;
    /* value written is number of cache lines not written back */
    bdk_write64_uint64(address, num_cache_lines);
}

bdk_fpa_ops_t __bdk_fpa_ops_cn6xxx = {
    .init = fpa_init,
    .init_pool = fpa_init_pool,
    .init_aura = NULL,
    .get_block_size = fpa_get_block_size,
    .alloc = fpa_alloc,
    .free = fpa_free,
};


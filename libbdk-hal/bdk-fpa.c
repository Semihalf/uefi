#include <bdk.h>
#include <malloc.h>

/**
 * Enable the FPA for use. Must be performed after any CSR
 * configuration but before any other FPA functions.
 */
void bdk_fpa_enable(void)
{
    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        /* Initialize the range checking so that no memory is in range */
        for (int i=0; i<8; i++)
        {
            BDK_CSR_WRITE(BDK_FPA_POOLX_START_ADDR(i), 0xffffffffull);
            BDK_CSR_WRITE(BDK_FPA_POOLX_END_ADDR(i), 0);
        }
    }
    BDK_CSR_MODIFY(status, BDK_FPA_CTL_STATUS,
        status.s.enb = 1);
}

/**
 * Fill a pool with buffers
 *
 * @param pool       Pool to initialize
 *                   0 <= pool < 8
 * @param num_blocks Number of blocks
 *
 * @return 0 on Success,
 *         -1 on failure
 */
int bdk_fpa_fill_pool(bdk_fpa_pool_t pool, int num_blocks)
{
    int size = bdk_fpa_get_block_size(pool);

    if (!size)
        return -num_blocks;

    if (size & BDK_CACHE_LINE_MASK)
        return -num_blocks;

    void *buf = memalign(BDK_CACHE_LINE_SIZE, num_blocks * size);
    if (!buf)
    {
        bdk_error("bdk_fpa_fill_pool: Pool %d failed with %d blocks to alloc\n", pool, num_blocks);
        return -num_blocks;
    }

    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        /* Update the start address to contain the new memory */
        uint64_t addr = bdk_ptr_to_phys(buf);
        BDK_CSR_INIT(start_addr, BDK_FPA_POOLX_START_ADDR(pool));
        if (addr>>7 < start_addr.s.addr)
        {
            BDK_CSR_WRITE(BDK_FPA_POOLX_START_ADDR(pool), addr>>7);
            BDK_CSR_READ(BDK_FPA_POOLX_START_ADDR(pool));
        }

        /* The end address needs to only contain the last buffers address,
            not the full buffer */
        addr += (num_blocks-1) * size;
        BDK_CSR_INIT(end_addr, BDK_FPA_POOLX_END_ADDR(pool));
        if (addr>>7 > end_addr.s.addr)
        {
            BDK_CSR_WRITE(BDK_FPA_POOLX_END_ADDR(pool), addr>>7);
            BDK_CSR_READ(BDK_FPA_POOLX_END_ADDR(pool));
        }
    }

    while (num_blocks--)
    {
        bdk_fpa_free(buf, pool, 0);
        buf += size;
    }
    return 0;
}

int bdk_fpa_get_block_size(bdk_fpa_pool_t pool)
{
    return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0 + pool);
}

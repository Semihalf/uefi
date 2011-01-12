#include <bdk.h>
#include <malloc.h>

/**
 * Enable the FPA for use. Must be performed after any CSR
 * configuration but before any other FPA functions.
 */
void bdk_fpa_enable(void)
{
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

    while (num_blocks--)
    {
        void *buf = memalign(BDK_CACHE_LINE_SIZE, size);
        if (buf)
            bdk_fpa_free(buf, pool, 0);
        else
        {
            bdk_error("bdk_fpa_fill_pool: Pool %d failed with %d blocks to alloc\n", pool, num_blocks);
            break;
        }
    }
    return -num_blocks;
}

/**
 * Shutdown a Memory pool and validate that it had all of
 * the buffers originally placed in it. This should only be
 * called by one processor after all hardware has finished
 * using the pool. Most like you will want to have called
 * bdk_helper_shutdown_packet_io_global() before this
 * function to make sure all FPA buffers are out of the packet
 * IO hardware.
 *
 * @param pool   Pool to shutdown
 *
 * @return Zero on success
 *         - Positive is count of missing buffers
 *         - Negative is too many buffers or corrupted pointers
 */
int bdk_fpa_empty_pool(bdk_fpa_pool_t pool)
{
    while (1)
    {
        void *ptr = bdk_fpa_alloc(pool);
        if (ptr)
            free(ptr);
        else
            break;
    }
    return 0;
}

int bdk_fpa_get_block_size(bdk_fpa_pool_t pool)
{
    switch (pool)
    {
        case 0: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0);
        case 1: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE1);
        case 2: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE2);
        case 3: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE3);
        case 4: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE4);
        case 5: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE5);
        case 6: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE6);
        case 7: return bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE7);
        default:
	    return 0;
    }
}

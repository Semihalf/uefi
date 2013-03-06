#include <bdk.h>
#include <malloc.h>

/**
 * Enable the FPA for use. Must be performed after any CSR
 * configuration but before any other FPA functions.
 */
static void __bdk_fpa_enable(void)
{
    /* Initialize the range checking so that no memory is in range */
    for (int i=0; i<8; i++)
    {
        BDK_CSR_WRITE(BDK_FPA_POOLX_START_ADDR(i), 0xffffffffull);
        BDK_CSR_WRITE(BDK_FPA_POOLX_END_ADDR(i), 0);
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
    BDK_CSR_INIT(status, BDK_FPA_CTL_STATUS);
    if (!status.s.enb)
        __bdk_fpa_enable();

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

    /* Put a known pattern in the data in case someone forgets to init */
    memset(buf, 0xaa, num_blocks * size);

    {
        /* Update the start address to contain the new memory */
        uint64_t addr = bdk_ptr_to_phys(buf);
        BDK_CSR_INIT(start_addr, BDK_FPA_POOLX_START_ADDR(pool));
        /* Being always helpful, the HW team decided to change the format of the start address on CN78XX */
        uint64_t start = OCTEON_IS_MODEL(OCTEON_CN78XX) ? start_addr.cn78xx.addr : start_addr.cn68xx.addr;
        if (addr>>7 < start)
        {
            start = addr>>7;
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
                start <<= 7;
            BDK_CSR_WRITE(BDK_FPA_POOLX_START_ADDR(pool), start);
            BDK_CSR_READ(BDK_FPA_POOLX_START_ADDR(pool));
        }

        /* The end address needs to only contain the last buffers address,
            not the full buffer */
        addr += (num_blocks-1) * size;
        BDK_CSR_INIT(end_addr, BDK_FPA_POOLX_END_ADDR(pool));
        /* Being always helpful, the HW team decided to change the format of the end address on CN78XX */
        uint64_t end = OCTEON_IS_MODEL(OCTEON_CN78XX) ? end_addr.cn78xx.addr : end_addr.cn68xx.addr;
        if (addr>>7 > end)
        {
            end = addr>>7;
            if (OCTEON_IS_MODEL(OCTEON_CN78XX))
                end <<= 7;
            BDK_CSR_WRITE(BDK_FPA_POOLX_END_ADDR(pool), end);
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

/**
 * Verify that an address should be in a pool
 *
 * @param where   Message describing where the check is
 * @param pool    Pool to check against
 * @param address Address to check
 */
void bdk_fpa_check_address(const char *where, bdk_fpa_pool_t pool, uint64_t address)
{
    if (address & 0x7f)
        bdk_fatal("%s: Non cache lined address for pool %d: 0x%lx\n", where, pool, address);

    BDK_CSR_INIT(start_addr, BDK_FPA_POOLX_START_ADDR(pool));
    BDK_CSR_INIT(end_addr, BDK_FPA_POOLX_END_ADDR(pool));
    if ((address >> 7 < start_addr.u64) || (address >> 7 > end_addr.u64))
        bdk_fatal("%s: Illegal address for pool %d: 0x%lx, must be 0x%lx-0x%lx\n", where, pool, address, start_addr.u64<<7, end_addr.u64<<7);
}


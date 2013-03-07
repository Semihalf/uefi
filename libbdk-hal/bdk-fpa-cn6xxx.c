#include <bdk.h>
#include <malloc.h>

#define NUM_POOLS 8
static int fpa_buffer_size_pool[NUM_POOLS];

/**
 * Perform global FPA initialization
 */
static int fpa_init(void)
{
    memset(fpa_buffer_size_pool, 0, sizeof(fpa_buffer_size_pool));

    /* Initialize the range checking so that no memory is in range */
    for (int i=0; i<NUM_POOLS; i++)
    {
        BDK_CSR_WRITE(BDK_FPA_POOLX_START_ADDR(i), 0xffffffffull);
        BDK_CSR_WRITE(BDK_FPA_POOLX_END_ADDR(i), 0);
    }
    BDK_CSR_MODIFY(status, BDK_FPA_CTL_STATUS,
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
static int fpa_init_pool(int pool, int num_blocks, int block_size)
{
    void *buf = memalign(BDK_CACHE_LINE_SIZE, num_blocks * block_size);
    if (!buf)
    {
        bdk_error("bdk_fpa_fill_pool: Pool %d failed with %d blocks to alloc\n", pool, num_blocks);
        return -num_blocks;
    }

    /* Put a known pattern in the data in case someone forgets to init */
    memset(buf, 0xaa, num_blocks * block_size);

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
        addr += (num_blocks-1) * block_size;
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
static int fpa_get_block_size(int aura)
{
    return fpa_buffer_size_pool[aura];
}

static uint64_t fpa_alloc(int aura)
{
    return bdk_read64_uint64(BDK_ADDR_DID(BDK_FULL_DID(BDK_OCT_DID_FPA, aura)));
}

static void fpa_free(uint64_t address, int aura, int num_cache_lines)
{
    bdk_addr_t newptr;
    newptr.u64 = address;
    newptr.sfilldidspace.didspace = BDK_ADDR_DIDSPACE(BDK_FULL_DID(BDK_OCT_DID_FPA,aura));
    asm volatile ("" : : : "memory");  /* Prevent GCC from reordering around free */
    /* value written is number of cache lines not written back */
    bdk_write64_uint64(newptr.u64, num_cache_lines);
}

bdk_fpa_ops_t __bdk_fpa_ops_cn6xxx = {
    .init = fpa_init,
    .init_pool = fpa_init_pool,
    .init_aura = NULL,
    .get_block_size = fpa_get_block_size,
    .alloc = fpa_alloc,
    .free = fpa_free,
};


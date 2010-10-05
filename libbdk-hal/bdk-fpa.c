#include <bdk.h>

/**
 * Current state of all the pools. Use access functions
 * instead of using it directly.
 */
bdk_fpa_pool_info_t bdk_fpa_pool_info[BDK_FPA_NUM_POOLS];


/**
 * Setup a FPA pool to control a new block of memory. The
 * buffer pointer must be a physical address.
 *
 * @param pool       Pool to initialize
 *                   0 <= pool < 8
 * @param name       Constant character string to name this pool.
 *                   String is not copied.
 * @param buffer     Pointer to the block of memory to use. This must be
 *                   accessable by all processors and external hardware.
 * @param block_size Size for each block controlled by the FPA
 * @param num_blocks Number of blocks
 *
 * @return 0 on Success,
 *         -1 on failure
 */
int bdk_fpa_setup_pool(uint64_t pool, const char *name, void *buffer,
                         uint64_t block_size, uint64_t num_blocks)
{
    char *ptr;
    if (!buffer)
    {
        bdk_dprintf("ERROR: bdk_fpa_setup_pool: NULL buffer pointer!\n");
        return -1;
    }
    if (pool >= BDK_FPA_NUM_POOLS)
    {
        bdk_dprintf("ERROR: bdk_fpa_setup_pool: Illegal pool!\n");
        return -1;
    }

    if (block_size < BDK_FPA_MIN_BLOCK_SIZE)
    {
        bdk_dprintf("ERROR: bdk_fpa_setup_pool: Block size too small.\n");
        return -1;
    }

    if (((unsigned long)buffer & (BDK_FPA_ALIGNMENT-1)) != 0)
    {
        bdk_dprintf("ERROR: bdk_fpa_setup_pool: Buffer not aligned properly.\n");
        return -1;
    }

    bdk_fpa_pool_info[pool].name = name;
    bdk_fpa_pool_info[pool].size = block_size;
    bdk_fpa_pool_info[pool].starting_element_count = num_blocks;
    bdk_fpa_pool_info[pool].base = buffer;

    ptr = (char*)buffer;
    while (num_blocks--)
    {
        bdk_fpa_free(ptr, pool, 0);
        ptr += block_size;
    }
    return 0;
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
uint64_t bdk_fpa_shutdown_pool(uint64_t pool)
{
    int errors = 0;
    int count  = 0;
    int expected_count = bdk_fpa_pool_info[pool].starting_element_count;
    uint64_t base   = bdk_ptr_to_phys(bdk_fpa_pool_info[pool].base);
    uint64_t finish = base + bdk_fpa_pool_info[pool].size * expected_count;

    count = 0;
    while (1)
    {
        uint64_t address;
        void *ptr = bdk_fpa_alloc(pool);
        if (!ptr)
            break;

        address = bdk_ptr_to_phys(ptr);
        if ((address >= base) && (address < finish) &&
            (((address - base) % bdk_fpa_pool_info[pool].size) == 0))
        {
            count++;
        }
        else
        {
            bdk_dprintf("ERROR: bdk_fpa_shutdown_pool: Illegal address 0x%llx in pool %s(%d)\n",
                   (unsigned long long)address, bdk_fpa_pool_info[pool].name, (int)pool);
            errors++;
        }
    }

    if (count < expected_count)
    {
        bdk_dprintf("ERROR: bdk_fpa_shutdown_pool: Pool %s(%d) missing %d buffers\n",
               bdk_fpa_pool_info[pool].name, (int)pool, expected_count - count);
    }
    else if (count > expected_count)
    {
        bdk_dprintf("ERROR: bdk_fpa_shutdown_pool: Pool %s(%d) had %d duplicate buffers\n",
               bdk_fpa_pool_info[pool].name, (int)pool, count - expected_count);
    }

    if (errors)
    {
        bdk_dprintf("ERROR: bdk_fpa_shutdown_pool: Pool %s(%d) started at 0x%llx, ended at 0x%llx, with a step of 0x%x\n",
               bdk_fpa_pool_info[pool].name, (int)pool, (unsigned long long)base, (unsigned long long)finish, (int)bdk_fpa_pool_info[pool].size);
        return -errors;
    }
    else
        return expected_count - count;
}

uint64_t bdk_fpa_get_block_size(uint64_t pool)
{
    switch (pool)
    {
#warning Fix bdk_fpa_get_block_size
#if 0 // FIXME
        case 0:
	    return BDK_FPA_POOL_0_SIZE;
        case 1:
	    return BDK_FPA_POOL_1_SIZE;
        case 2:
	    return BDK_FPA_POOL_2_SIZE;
        case 3:
	    return BDK_FPA_POOL_3_SIZE;
        case 4:
	    return BDK_FPA_POOL_4_SIZE;
        case 5:
	    return BDK_FPA_POOL_5_SIZE;
        case 6:
	    return BDK_FPA_POOL_6_SIZE;
        case 7:
	    return BDK_FPA_POOL_7_SIZE;
#endif
        default:
	    return 0;
    }
}

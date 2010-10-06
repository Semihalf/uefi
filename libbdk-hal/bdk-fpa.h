/**
 * @file
 *
 * Interface to the hardware Free Pool Allocator.
 *
 * <hr>$Revision: 50048 $<hr>
 *
 */

#define BDK_FPA_NUM_POOLS      8
#define BDK_FPA_MIN_BLOCK_SIZE 128
#define BDK_FPA_ALIGNMENT      128

typedef enum
{
    BDK_FPA_PACKET_POOL,
    BDK_FPA_WQE_POOL,
    BDK_FPA_OUTPUT_BUFFER_POOL,
    BDK_FPA_TIMER_POOL,
} bdk_fpa_pool_t;

/**
 * Structure describing the data format used for stores to the FPA.
 */
typedef union
{
    uint64_t        u64;
    struct {
        uint64_t    scraddr : 8;    /**< the (64-bit word) location in scratchpad to write to (if len != 0) */
        uint64_t    len     : 8;    /**< the number of words in the response (0 => no response) */
        uint64_t    did     : 8;    /**< the ID of the device on the non-coherent bus */
        uint64_t    addr    :40;    /**< the address that will appear in the first tick on the NCB bus */
    } s;
} bdk_fpa_iobdma_data_t;

/**
 * Structure describing the current state of a FPA pool.
 */
typedef struct
{
    const char *name;                   /**< Name it was created under */
    uint64_t    size;                   /**< Size of each block */
    void *      base;                   /**< The base memory address of whole block */
    uint64_t    starting_element_count; /**< The number of elements in the pool at creation */
} bdk_fpa_pool_info_t;

/**
 * Current state of all the pools. Use access functions
 * instead of using it directly.
 */
extern bdk_fpa_pool_info_t bdk_fpa_pool_info[BDK_FPA_NUM_POOLS];

/**
 * Enable the FPA for use. Must be performed after any CSR
 * configuration but before any other FPA functions.
 */
static inline void bdk_fpa_enable(void)
{
    bdk_fpa_ctl_status_t status;

    status.u64 = BDK_CSR_READ(BDK_FPA_CTL_STATUS);
    if (status.s.enb)
    {
        bdk_dprintf("Warning: Enabling FPA when FPA already enabled.\n");
    }

    status.u64 = 0;
    status.s.enb = 1;
    BDK_CSR_WRITE(BDK_FPA_CTL_STATUS, status.u64);
}

/**
 * Get a new block from the FPA
 *
 * @param pool   Pool to get the block from
 * @return Pointer to the block or NULL on failure
 */
static inline void *bdk_fpa_alloc(uint64_t pool)
{
    uint64_t address;

    for (;;) {
        address = bdk_read64_uint64(BDK_ADDR_DID(BDK_FULL_DID(BDK_OCT_DID_FPA,pool)));
        if (bdk_likely(address)) {
            return bdk_phys_to_ptr(address);
        } else {
	   /* If pointers are available, continuously retry.  */
           if (BDK_CSR_READ(BDK_FPA_QUEX_AVAILABLE(pool)) > 0)
               bdk_wait(50);
           else
               return NULL;
	}
    }
}

/**
 * Asynchronously get a new block from the FPA
 *
 * The result of bdk_fpa_async_alloc() may be retrieved using
 * bdk_fpa_async_alloc_finish().
 *
 * @param scr_addr Local scratch address to put response in.  This is a byte address,
 *                  but must be 8 byte aligned.
 * @param pool      Pool to get the block from
 */
static inline void bdk_fpa_async_alloc(uint64_t scr_addr, uint64_t pool)
{
   bdk_fpa_iobdma_data_t data;

   /* Hardware only uses 64 bit alligned locations, so convert from byte address
   ** to 64-bit index
   */
   data.s.scraddr = scr_addr >> 3;
   data.s.len = 1;
   data.s.did = BDK_FULL_DID(BDK_OCT_DID_FPA,pool);
   data.s.addr = 0;
   bdk_send_single(data.u64);
}

/**
 * Retrieve the result of bdk_fpa_async_alloc
 *
 * @param scr_addr The Local scratch address.  Must be the same value
 * passed to bdk_fpa_async_alloc().
 *
 * @param pool Pool the block came from.  Must be the same value
 * passed to bdk_fpa_async_alloc.
 *
 * @return Pointer to the block or NULL on failure
 */
static inline void *bdk_fpa_async_alloc_finish(uint64_t scr_addr, uint64_t pool)
{
    uint64_t address;

    BDK_SYNCIOBDMA;

    address = bdk_scratch_read64(scr_addr);
    if (bdk_likely(address))
        return bdk_phys_to_ptr(address);
    else
        return bdk_fpa_alloc(pool);
}

/**
 * Free a block allocated with a FPA pool.
 * Does NOT provide memory ordering in cases where the memory block was modified by the core.
 *
 * @param ptr    Block to free
 * @param pool   Pool to put it in
 * @param num_cache_lines
 *               Cache lines to invalidate
 */
static inline void bdk_fpa_free_nosync(void *ptr, uint64_t pool, uint64_t num_cache_lines)
{
    bdk_addr_t newptr;
    newptr.u64 = bdk_ptr_to_phys(ptr);
    newptr.sfilldidspace.didspace = BDK_ADDR_DIDSPACE(BDK_FULL_DID(BDK_OCT_DID_FPA,pool));
    asm volatile ("" : : : "memory");  /* Prevent GCC from reordering around free */
    /* value written is number of cache lines not written back */
    bdk_write64_uint64(newptr.u64, num_cache_lines);
}

/**
 * Free a block allocated with a FPA pool.  Provides required memory
 * ordering in cases where memory block was modified by core.
 *
 * @param ptr    Block to free
 * @param pool   Pool to put it in
 * @param num_cache_lines
 *               Cache lines to invalidate
 */
static inline void bdk_fpa_free(void *ptr, uint64_t pool, uint64_t num_cache_lines)
{
    bdk_addr_t newptr;
    newptr.u64 = bdk_ptr_to_phys(ptr);
    newptr.sfilldidspace.didspace = BDK_ADDR_DIDSPACE(BDK_FULL_DID(BDK_OCT_DID_FPA,pool));
    /* Make sure that any previous writes to memory go out before we free this buffer.
    ** This also serves as a barrier to prevent GCC from reordering operations to after
    ** the free. */
    BDK_SYNCW;
    /* value written is number of cache lines not written back */
    bdk_write64_uint64(newptr.u64, num_cache_lines);
}

/**
 * Setup a FPA pool to control a new block of memory.
 * This can only be called once per pool. Make sure proper
 * locking enforces this.
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
extern int bdk_fpa_setup_pool(uint64_t pool, const char *name, void *buffer,
                                uint64_t block_size, uint64_t num_blocks);

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
extern uint64_t bdk_fpa_shutdown_pool(uint64_t pool);

/**
 * Get the size of blocks controlled by the pool
 * This is resolved to a constant at compile time.
 *
 * @param pool   Pool to access
 * @return Size of the block in bytes
 */
uint64_t bdk_fpa_get_block_size(uint64_t pool);


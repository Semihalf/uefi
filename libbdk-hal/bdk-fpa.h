/**
 * @file
 *
 * Interface to the hardware Free Pool Allocator.
 *
 * <hr>$Revision: 50048 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_FPA_PACKET_POOL,
    BDK_FPA_OUTPUT_BUFFER_POOL,
    BDK_FPA_TIMER_POOL,
} bdk_fpa_pool_t;

/**
 * Enable the FPA for use. Must be performed after any CSR
 * configuration but before any other FPA functions.
 */
extern void bdk_fpa_enable(void);

/**
 * Get a new block from the FPA
 *
 * @param pool   Pool to get the block from
 * @return Pointer to the block or NULL on failure
 */
static inline void *bdk_fpa_alloc(bdk_fpa_pool_t pool)
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
static inline void bdk_fpa_async_alloc(int scr_addr, bdk_fpa_pool_t pool)
{
    union {
        uint64_t        u64;
        struct {
            uint64_t scraddr : 8;
            uint64_t len     : 8;
            uint64_t did     : 8;
            uint64_t addr    :40;
        } s;
    } data;

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
static inline void *bdk_fpa_async_alloc_finish(int scr_addr, bdk_fpa_pool_t pool)
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
 * Free a block allocated with a FPA pool.  Provides required memory
 * ordering in cases where memory block was modified by core.
 *
 * @param ptr    Block to free
 * @param pool   Pool to put it in
 * @param num_cache_lines
 *               Cache lines to invalidate
 */
static inline void bdk_fpa_free(void *ptr, bdk_fpa_pool_t pool, int num_cache_lines)
{
    bdk_addr_t newptr;

    BDK_SYNCW;
    newptr.u64 = bdk_ptr_to_phys(ptr);
    newptr.sfilldidspace.didspace = BDK_ADDR_DIDSPACE(BDK_FULL_DID(BDK_OCT_DID_FPA,pool));
    asm volatile ("" : : : "memory");  /* Prevent GCC from reordering around free */
    /* value written is number of cache lines not written back */
    bdk_write64_uint64(newptr.u64, num_cache_lines);
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
extern int bdk_fpa_fill_pool(bdk_fpa_pool_t pool, int num_blocks);

/**
 * Empty an FPA pool and free() all buffers
 *
 * @param pool   Pool to empty
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_fpa_empty_pool(bdk_fpa_pool_t pool);

/**
 * Get the size of blocks controlled by the pool
 * This is resolved to a constant at compile time.
 *
 * @param pool   Pool to access
 * @return Size of the block in bytes
 */
int bdk_fpa_get_block_size(bdk_fpa_pool_t pool) __attribute__ ((pure));

/** @} */

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

typedef struct
{
    int (*init)(bdk_node_t node);
    int (*init_pool)(bdk_node_t node, int pool, int num_blocks, int block_size);
    int (*init_aura)(bdk_node_t node, int aura, int pool, int num_blocks);
    int (*get_block_size)(bdk_node_t node, int aura);
    uint64_t (*alloc)(bdk_node_t node, int aura);
    void (*free)(bdk_node_t node, uint64_t address, int aura, int num_cache_lines);
} bdk_fpa_ops_t;

typedef enum
{
    BDK_FPA_PACKET_POOL,
    BDK_FPA_OUTPUT_BUFFER_POOL,
    BDK_FPA_SSO_POOL,
    BDK_FPA_PKO_POOL,
} bdk_fpa_pool_t;

/**
 * Get a new block from the FPA
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param aura   Aura to get the block from
 *
 * @return Pointer to the block or NULL on failure
 */
static inline void *bdk_fpa_alloc(bdk_node_t node, int aura)
{
    extern bdk_fpa_ops_t __bdk_fpa_ops;
    uint64_t address = __bdk_fpa_ops.alloc(bdk_numa_id(node), aura);
    if (bdk_likely(address))
        return bdk_phys_to_ptr(address);
    else
        return NULL;
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
static inline void __bdk_fpa_raw_free(bdk_node_t node, uint64_t address, int aura, int num_cache_lines)
{
    extern bdk_fpa_ops_t __bdk_fpa_ops;
    asm volatile ("" : : : "memory");  /* Prevent GCC from reordering around free */
    __bdk_fpa_ops.free(bdk_numa_id(node), address, aura, num_cache_lines);
}

/**
 * Free a block allocated with a FPA pool.  Provides required memory
 * ordering in cases where memory block was modified by core.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param ptr    Block to free
 * @param pool   Pool to put it in
 * @param num_cache_lines
 *               Cache lines to invalidate
 */
static inline void bdk_fpa_free(bdk_node_t node, void *ptr, bdk_fpa_pool_t pool, int num_cache_lines)
{
    BDK_SYNCW;
    __bdk_fpa_raw_free(bdk_numa_id(node), bdk_ptr_to_phys(ptr), pool, num_cache_lines);
}

/**
 * Get the size of blocks controlled by the pool
 * This is resolved to a constant at compile time.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param aura   Aura to access
 *
 * @return Size of the block in bytes
 */
static inline int bdk_fpa_get_block_size(bdk_node_t node, int aura)
{
    extern bdk_fpa_ops_t __bdk_fpa_ops;
    return __bdk_fpa_ops.get_block_size(bdk_numa_id(node), aura);
}

/**
 * Fill a pool with buffers
 *
 * @param node       Node to use in a Numa setup. Can be an exact ID or a
 *                   special value.
 * @param pool       Pool to initialize
 *                   0 <= pool < 8
 * @param num_blocks Number of blocks
 *
 * @return 0 on Success,
 *         -1 on failure
 */
extern int bdk_fpa_fill_pool(bdk_node_t node, int pool, int num_blocks);

/**
 * Initialize an Aura for a specific pool
 *
 * @param node       Node to use in a Numa setup. Can be an exact ID or a
 *                   special value.
 * @param aura       Aura to initialize, or -1 to dynamically allocate one
 * @param pool       Pool this aura is for
 * @param num_blocks Number of buffers to allow this aura to contain. This may be
 *                   different from the pool
 *
 * @return Aura number or negative on failure
 */
extern int bdk_fpa_init_aura(bdk_node_t node, int aura, int pool, int num_blocks);

/** @} */

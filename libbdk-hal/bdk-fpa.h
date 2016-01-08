/**
 * @file
 *
 * Interface to the hardware Free Pool Allocator.
 *
 * @addtogroup hal
 * @{
 */

#define BDK_FPA_NUM_AURAS 512 /* 512 for CN83XX. Must not be bigger than FPA_CONST[auras] */

/**
 * This enum represents the FPA hardware pools in use by the BDK
 */
typedef enum
{
    BDK_FPA_PACKET_POOL,    /* Stores PKI packet buffers */
    BDK_FPA_SSO_POOL,       /* Used for internal storage in the SSO */
    BDK_FPA_PKO_POOL,       /* Used for queue storage in the PKO */
    BDK_FPA_NUM_POOLS = 16  /* Can be 16, or 32 for CN83XX. Must not be bigger than FPA_CONST[pools] */
} bdk_fpa_pool_t;

/**
 * Structure representing the global state of the FPA
 */
typedef struct
{
    uint16_t buffer_size_pool[BDK_FPA_NUM_POOLS];
    uint16_t buffer_size_aura[BDK_FPA_NUM_AURAS];
    int next_free_aura;
    int init_done;
} __bdk_fpa_state_t;

extern __bdk_fpa_state_t __bdk_fpa_node_state[BDK_NUMA_MAX_NODES];

/**
 * Get a new block from an aura
 *
 * @param node   Node to use in a Numa setup. See bdk-numa.h
 * @param aura   Aura to get the block from (0-BDK_FPA_NUM_AURAS)
 *
 * @return Pointer to the block or NULL on failure
 */
static inline void *bdk_fpa_alloc(bdk_node_t node, int aura)
{
    union bdk_fpa_alloc_addr_s fpa_alloc_addr;
    fpa_alloc_addr.u = BDK_FPA_VHAURAX_OP_ALLOCX(aura, 0);
    fpa_alloc_addr.s.drop = 0; /* Alloc ignores drop levels */
    fpa_alloc_addr.s.red = 0; /* Alloc ignores red levels */
    fpa_alloc_addr.u = bdk_numa_get_address(node, fpa_alloc_addr.u);
    uint64_t address = bdk_read64_uint64(fpa_alloc_addr.u);
    BDK_TRACE(FPA, "N%d FPA alloc aura=%d addr=0x%lx\n", node, aura, address);
    if (bdk_likely(address))
        return bdk_phys_to_ptr(address);
    else
        return NULL;
}

/**
 * Free a block allocated with bdk_fpa_alloc().  Does NOT provide memory ordering
 * for core stores. Software must insure all pending writes are flushed before
 * calling this function.
 *
 * @param node    Node to use in a Numa setup. See bdk-numa.h
 * @param address Physical address to free to the FPA aura
 * @param aura    Aura number to free to (0-BDK_FPA_NUM_AURAS)
 * @param num_cache_lines
 *                Cache lines to invalidate. Use this if the data in the buffer is no longer
 *                requires cache coherency. Normally best to set this to zero.
 */
static inline void __bdk_fpa_raw_free(bdk_node_t node, uint64_t address, int aura, int num_cache_lines)
{
    asm volatile ("" : : : "memory");  /* Prevent GCC from reordering around free */
    BDK_TRACE(FPA, "N%d FPA free aura=%d addr=0x%lx\n", node, aura, address);
    union bdk_fpa_free_addr_s fpa_free_addr;
    fpa_free_addr.u = BDK_FPA_VHAURAX_OP_FREEX(aura, 0);
    fpa_free_addr.s.dwb_count = num_cache_lines;
    fpa_free_addr.s.fabs = 0; /* Don't do absolute address frees */
    fpa_free_addr.u = bdk_numa_get_address(node, fpa_free_addr.u);
    bdk_write64_uint64(fpa_free_addr.u, address);
}

/**
 * Free a block allocated with bdk_fpa_alloc().  Provides memory ordering
 * for core stores.
 *
 * @param node   Node to use in a Numa setup. See bdk-numa.h
 * @param ptr    Pointer to the block to free
 * @param aura   Aura number to free to (0-BDK_FPA_NUM_AURAS)
 * @param num_cache_lines
 *               Cache lines to invalidate. Use this if the data in the buffer is no longer
 *               requires cache coherency. Normally best to set this to zero.
 */
static inline void bdk_fpa_free(bdk_node_t node, void *ptr, int aura, int num_cache_lines)
{
    BDK_WMB;
    __bdk_fpa_raw_free(node, bdk_ptr_to_phys(ptr), aura, num_cache_lines);
}

/**
 * Get the size of blocks controlled by the aura
 *
 * @param node   Node to use in a Numa setup. See bdk-numa.h
 * @param aura   Aura number to access (0-BDK_FPA_NUM_AURAS)
 *
 * @return Size of the block in bytes
 */
static inline int bdk_fpa_get_block_size(bdk_node_t node, int aura)
{
    __bdk_fpa_state_t *fpa_state = &__bdk_fpa_node_state[node];
    return fpa_state->buffer_size_aura[aura];
}

/**
 * Fill a pool with buffers
 *
 * @param node       Node to use in a Numa setup. See bdk-numa.h
 * @param pool       Pool to initialize (0 <= pool < BDK_FPA_NUM_POOLS)
 * @param num_blocks Number of blocks
 *
 * @return Zero on Success, negative on failure
 */
extern int bdk_fpa_fill_pool(bdk_node_t node, bdk_fpa_pool_t pool, int num_blocks);

/**
 * Initialize an Aura for a specific pool
 *
 * @param node       Node to use in a Numa setup. See bdk-numa.h
 * @param aura       Aura to initialize, or -1 to dynamically allocate a free aura
 * @param pool       Pool this aura is for (0 <= pool < BDK_FPA_NUM_POOLS)
 * @param num_blocks Number of buffers to allow this aura to contain. This may be different
 *                   from the pool
 *
 * @return Aura number or negative on failure
 */
extern int bdk_fpa_init_aura(bdk_node_t node, int aura, bdk_fpa_pool_t pool, int num_blocks);

/** @} */

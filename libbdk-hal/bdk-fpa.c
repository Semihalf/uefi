#include <bdk.h>
#include <malloc.h>

bdk_fpa_ops_t __bdk_fpa_ops;        /* Assume all nodes use same FPA ops */
static int __bdk_fpa_init_done = 0; /* Bitmask of Nodes that have done init */
static bdk_spinlock_t fpa_lock;     /* Protects __bdk_fpa_init_done */

/**
 * Global FPA initialization
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_fpa_init(bdk_node_t node)
{
    extern bdk_fpa_ops_t __bdk_fpa_ops_cn6xxx;
    extern bdk_fpa_ops_t __bdk_fpa_ops_cn78xx;
    int result;

    bdk_spinlock_lock(&fpa_lock);
    if (!(__bdk_fpa_init_done & (1<<node)))
    {
        if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            __bdk_fpa_ops = __bdk_fpa_ops_cn78xx;
        else
            __bdk_fpa_ops = __bdk_fpa_ops_cn6xxx;
        BDK_TRACE("N%d: FPA: Performing global init\n", node);
        result = __bdk_fpa_ops.init(node);
        __bdk_fpa_init_done |= 1<<node;
    }
    else
        result = 0;
    bdk_spinlock_unlock(&fpa_lock);
    return result;
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
int bdk_fpa_fill_pool(bdk_node_t node, int pool, int num_blocks)
{
    if (!(__bdk_fpa_init_done & (1<<node)))
    {
        int result = __bdk_fpa_init(node);
        if (result)
            return result;
    }
    int block_size = bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0 + pool);
    BDK_TRACE("N%d: FPA: Fill pool %d with %d blocks of %d bytes\n", node, pool, num_blocks, block_size);
    return __bdk_fpa_ops.init_pool(node, pool, num_blocks, block_size);
}

/**
 * Initialize an Aura for a specific pool
 *
 * @param aura       Aura to initialize, or -1 to dynamically allocate one
 * @param pool       Pool this aura is for
 * @param num_blocks Number of buffers to allow this aura to contain. This may be
 *                   different from the pool
 *
 * @return Aura number or negative on failure
 */
int bdk_fpa_init_aura(bdk_node_t node, int aura, int pool, int num_blocks)
{
    int result = -1;
    if (__bdk_fpa_ops.init_aura)
        result = __bdk_fpa_ops.init_aura(node, aura, pool, num_blocks);
    BDK_TRACE("N%d: FPA: Init aura %d for pool %d with %d blocks\n", node, result, pool, num_blocks);
    return result;
}


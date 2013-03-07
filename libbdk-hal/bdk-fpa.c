#include <bdk.h>
#include <malloc.h>

bdk_fpa_ops_t __bdk_fpa_ops;
static int __bdk_fpa_init_done = 0;
static bdk_spinlock_t fpa_lock;

/**
 * Global FPA initialization
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_fpa_init(void)
{
    extern bdk_fpa_ops_t __bdk_fpa_ops_cn6xxx;
    extern bdk_fpa_ops_t __bdk_fpa_ops_cn78xx;
    int result;

    bdk_spinlock_lock(&fpa_lock);
    if (!__bdk_fpa_init_done)
    {
        if (OCTEON_IS_MODEL(OCTEON_CN78XX))
            __bdk_fpa_ops = __bdk_fpa_ops_cn78xx;
        else
            __bdk_fpa_ops = __bdk_fpa_ops_cn6xxx;
        result = __bdk_fpa_ops.init();
        __bdk_fpa_init_done = 1;
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
int bdk_fpa_fill_pool(int pool, int num_blocks)
{
    if (!__bdk_fpa_init_done)
    {
        int result = __bdk_fpa_init();
        if (result)
            return result;
    }
    return __bdk_fpa_ops.init_pool(pool, num_blocks, bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0 + pool));
}


#include <bdk.h>

/**
 * Configure BGX on all nodes as part of booting
 */
void bdk_boot_bgx(void)
{
    /* Initialize BGX, ready for driver */
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* Enable ports based on config file. */
            for (int bgx = 0; bgx < 2; bgx++)
            {
                for (int p = 0; p < 4; p++)
                {
                    int en = bdk_config_get_int(BDK_CONFIG_BGX_ENABLE, n, bgx, p);
                    if (-1 != en)
                        BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p), en);
                }
            }
        }
    }
}

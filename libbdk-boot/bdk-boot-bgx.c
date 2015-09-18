#include <bdk.h>

/**
 * Configure BGX on all nodes as part of booting
 */
void bdk_boot_bgx(void)
{
    /* Initialize BGX, ready for driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* Enable ports based on config file. */
            for (int bgx = 0; bgx < 2; bgx++)
            {
                for (int p = 0; p < 4; p++)
                {
                    int en = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_BGX_ENABLE, n, bgx, p);
                    if (-1 != en)
                        BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p), en);
                }
            }
        }
    }
}

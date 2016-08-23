#include <bdk.h>

/**
 * Configure BGX on all nodes as part of booting
 */
void bdk_boot_bgx(void)
{
    int max_bgx = 2;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX)) max_bgx = 4;

    /* Initialize BGX, ready for driver */
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* Enable ports based on config file. */
            for (int bgx = 0; bgx < max_bgx; bgx++)
            {
                for (int p = 0; p < 4; p++)
                {
                    int en = bdk_config_get_int(BDK_CONFIG_BGX_ENABLE, n, bgx, p);
                    if (en)
                    {
                        /* Make sure the DMAC starts at the hardware default */
                        BDK_CSR_DEFINE(dmac_ctl, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p));
                        dmac_ctl.u = 0;
                        dmac_ctl.s.mcst_mode = 1;
                        dmac_ctl.s.bcst_accept = 1;
                        BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p), dmac_ctl.u);
                    }
                    else
                    {
                        /* Mark this port as disabled */
                        BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p), 0);
                    }
                }
            }
        }
    }
}

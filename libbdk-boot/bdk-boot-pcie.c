#include <bdk.h>

/**
 * Configure PCIe on all nodes as part of booting
 */
void bdk_boot_pcie(void)
{
    /* Initialize PCIe and bring up the link */
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < bdk_pcie_get_num_ports(n); p++)
            {
                /* Only init PCIe that are attached to QLMs */
                if (bdk_qlm_get(n, BDK_IF_PCIE, p, 0) != -1)
                {
                    BDK_TRACE(INIT, "Initializing PCIe%d on Node %d\n", p, n);
                    bdk_pcie_rc_initialize(n, p);
                }
                else
                {
                    BDK_TRACE(INIT, "Disabled unused PCIe%d on Node %d\n", p, n);
                    BDK_CSR_MODIFY(c, n, BDK_PEMX_CLK_EN(p),
                        c.s.pceclk_gate = 1;
                        c.s.csclk_gate = 1);
                }
            }
        }
    }
}

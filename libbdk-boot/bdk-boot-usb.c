#include <bdk.h>

/**
 * Configure USB on all nodes as part of booting
 */
void bdk_boot_usb(void)
{
    /* Initialize USB, ready for standard XHCI driver */
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < 2; p++)
            {
                BDK_TRACE(INIT, "Initializing USB%d on Node %d\n", p, n);
                bdk_usb_initialize(n, p, 0);
            }
        }
    }
}

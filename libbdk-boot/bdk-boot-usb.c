#include <bdk.h>

/**
 * Configure USB on all nodes as part of booting
 */
void bdk_boot_usb(void)
{
    /* Initialize USB, ready for standard XHCI driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < 2; p++)
            {
                BDK_TRACE(INIT, "Initializing USB%d on Node %d\n", p, n);
                int usb_gpio = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_USB_PWR_GPIO, n, p);
                if (-1 != usb_gpio)
                    bdk_gpio_initialize(n, usb_gpio, 1, 1);
                bdk_usb_intialize(n, p, 0);
            }
        }
    }
}

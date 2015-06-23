#include <bdk.h>

void board_init_early()
{
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        int usb_gpio = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_USB_PWR_GPIO, n);
        /* BDK_BRD_CFG_USB_PWR_GPIO controls USB power */
        if (-1 != usb_gpio)
            bdk_gpio_initialize(n, usb_gpio, 1, 1);
    }
}


void board_init_late()
{
    bdk_node_t node = bdk_numa_local();

    /* Setup the status lights for the PHYs */
    if (bdk_numa_exists(BDK_NODE_0))
    {
        int bus = 1;
        int phy_id = 1;
        int device = 0;
        /* CPU0 SFP+ */
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010c, 0xB610);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010d, 0x0012);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0110, 0x0000);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0111, 0x0000);
        /* CPU0 QSFP+ */
        phy_id = 0;
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0106, 0x6610);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0107, 0x0012);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010a, 0x0000);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010b, 0x0000);
    }
    if (bdk_numa_exists(BDK_NODE_1))
    {
        int bus = 1;
        int phy_id = 1;
        int device = 0;
        /* CPU1 SFP+ */
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0106, 0x6610);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x0107, 0x0032);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010a, 0x0000);
        bdk_mdio_45_write(node, bus, phy_id, device, 0x010b, 0x0000);
    }
}

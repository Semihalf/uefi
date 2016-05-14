#include <bdk.h>

static bool LOOP_INTERNAL = false;
static bool LOOP_EXTERNAL = false;

static uint8_t patch_arr[] = {
    0x44, 0x83, 0x02, 0x42, 0x12, 0x02, 0x44, 0x93, 0x02, 0x44,
    0xca, 0x02, 0x44, 0x4d, 0x02, 0x43, 0xef, 0xed, 0xff, 0xe5,
    0xfc, 0x54, 0x38, 0x64, 0x20, 0x70, 0x08, 0x65, 0xff, 0x70,
    0x04, 0xed, 0x44, 0x80, 0xff, 0x22, 0x8f, 0x19, 0x7b, 0xbb,
    0x7d, 0x0e, 0x7f, 0x04, 0x12, 0x3d, 0xd7, 0xef, 0x4e, 0x60,
    0x03, 0x02, 0x41, 0xf9, 0xe4, 0xf5, 0x1a, 0x74, 0x01, 0x7e,
    0x00, 0xa8, 0x1a, 0x08, 0x80, 0x05, 0xc3, 0x33, 0xce, 0x33,
    0xce, 0xd8, 0xf9, 0xff, 0xef, 0x55, 0x19, 0x70, 0x03, 0x02,
    0x41, 0xed, 0x85, 0x1a, 0xfb, 0x7b, 0xbb, 0xe4, 0xfd, 0xff,
    0x12, 0x3d, 0xd7, 0xef, 0x4e, 0x60, 0x03, 0x02, 0x41, 0xed,
    0xe5, 0x1a, 0x54, 0x02, 0x75, 0x1d, 0x00, 0x25, 0xe0, 0x25,
    0xe0, 0xf5, 0x1c, 0xe4, 0x78, 0xc5, 0xf6, 0xd2, 0x02, 0x12,
    0x41, 0xfa, 0x7b, 0xff, 0x7d, 0x12, 0x7f, 0x07, 0x12, 0x3d,
    0xd7, 0xef, 0x4e, 0x60, 0x03, 0x02, 0x41, 0xe7, 0xc2, 0x02,
    0x74, 0xc7, 0x25, 0x1a, 0xf9, 0x74, 0xe7, 0x25, 0x1a, 0xf8,
    0xe6, 0x27, 0xf5, 0x1b, 0xe5, 0x1d, 0x24, 0x5b, 0x12, 0x44,
    0x2a, 0x12, 0x3e, 0xda, 0x7b, 0xfc, 0x7d, 0x11, 0x7f, 0x07,
    0x12, 0x3d, 0xd7, 0x78, 0xcc, 0xef, 0xf6, 0x78, 0xc1, 0xe6,
    0xfe, 0xef, 0xd3, 0x9e, 0x40, 0x06, 0x78, 0xcc, 0xe6, 0x78,
    0xc1, 0xf6, 0x12, 0x41, 0xfa, 0x7b, 0xec, 0x7d, 0x12, 0x7f,
    0x07, 0x12, 0x3d, 0xd7, 0x78, 0xcb, 0xef, 0xf6, 0xbf, 0x07,
    0x06, 0x78, 0xc3, 0x76, 0x1a, 0x80, 0x1f, 0x78, 0xc5, 0xe6,
    0xff, 0x60, 0x0f, 0xc3, 0xe5, 0x1b, 0x9f, 0xff, 0x78, 0xcb,
    0xe6, 0x85, 0x1b, 0xf0, 0xa4, 0x2f, 0x80, 0x07, 0x78, 0xcb,
    0xe6, 0x85, 0x1b, 0xf0, 0xa4, 0x78, 0xc3, 0xf6, 0xe4, 0x78,
    0xc2, 0xf6, 0x78, 0xc2, 0xe6, 0xff, 0xc3, 0x08, 0x96, 0x40,
    0x03, 0x02, 0x41, 0xd1, 0xef, 0x54, 0x03, 0x60, 0x33, 0x14,
    0x60, 0x46, 0x24, 0xfe, 0x60, 0x42, 0x04, 0x70, 0x4b, 0xef,
    0x24, 0x02, 0xff, 0xe4, 0x33, 0xfe, 0xef, 0x78, 0x02, 0xce,
    0xa2, 0xe7, 0x13, 0xce, 0x13, 0xd8, 0xf8, 0xff, 0xe5, 0x1d,
    0x24, 0x5c, 0xcd, 0xe5, 0x1c, 0x34, 0xf0, 0xcd, 0x2f, 0xff,
    0xed, 0x3e, 0xfe, 0x12, 0x44, 0x6a, 0x7d, 0x11, 0x80, 0x0b,
    0x78, 0xc2, 0xe6, 0x70, 0x04, 0x7d, 0x11, 0x80, 0x02, 0x7d,
    0x12, 0x7f, 0x07, 0x12, 0x3e, 0x9a, 0x8e, 0x1e, 0x8f, 0x1f,
    0x80, 0x03, 0xe5, 0x1e, 0xff, 0x78, 0xc5, 0xe6, 0x06, 0x24,
    0xcd, 0xf8, 0xa6, 0x07, 0x78, 0xc2, 0x06, 0xe6, 0xb4, 0x1a,
    0x0a, 0xe5, 0x1d, 0x24, 0x5c, 0x12, 0x44, 0x2a, 0x12, 0x3e,
    0xda, 0x78, 0xc5, 0xe6, 0x65, 0x1b, 0x70, 0x82, 0x75, 0xdb,
    0x20, 0x75, 0xdb, 0x28, 0x12, 0x44, 0x42, 0x12, 0x44, 0x42,
    0xe5, 0x1a, 0x12, 0x44, 0x35, 0xe5, 0x1a, 0xc3, 0x13, 0x12,
    0x44, 0x35, 0x78, 0xc5, 0x16, 0xe6, 0x24, 0xcd, 0xf8, 0xe6,
    0xff, 0x7e, 0x08, 0x1e, 0xef, 0xa8, 0x06, 0x08, 0x80, 0x02,
    0xc3, 0x13, 0xd8, 0xfc, 0xfd, 0xc4, 0x33, 0x54, 0xe0, 0xf5,
    0xdb, 0xef, 0xa8, 0x06, 0x08, 0x80, 0x02, 0xc3, 0x13, 0xd8,
    0xfc, 0xfd, 0xc4, 0x33, 0x54, 0xe0, 0x44, 0x08, 0xf5, 0xdb,
    0xee, 0x70, 0xd8, 0x78, 0xc5, 0xe6, 0x70, 0xc8, 0x75, 0xdb,
    0x10, 0x02, 0x40, 0xfd, 0x78, 0xc2, 0xe6, 0xc3, 0x94, 0x17,
    0x50, 0x0e, 0xe5, 0x1d, 0x24, 0x62, 0x12, 0x42, 0x08, 0xe5,
    0x1d, 0x24, 0x5c, 0x12, 0x42, 0x08, 0x20, 0x02, 0x03, 0x02,
    0x40, 0x76, 0x05, 0x1a, 0xe5, 0x1a, 0xc3, 0x94, 0x04, 0x50,
    0x03, 0x02, 0x40, 0x3a, 0x22, 0xe5, 0x1d, 0x24, 0x5c, 0xff,
    0xe5, 0x1c, 0x34, 0xf0, 0xfe, 0x12, 0x44, 0x6a, 0x22, 0xff,
    0xe5, 0x1c, 0x34, 0xf0, 0xfe, 0x12, 0x44, 0x6a, 0x22, 0xd2,
    0x00, 0x75, 0xfb, 0x03, 0xab, 0x7e, 0xaa, 0x7d, 0x7d, 0x19,
    0x7f, 0x03, 0x12, 0x3e, 0xda, 0xe5, 0x7e, 0x54, 0x0f, 0x24,
    0xf3, 0x60, 0x03, 0x02, 0x42, 0xb9, 0x12, 0x44, 0xa3, 0x12,
    0x44, 0xaa, 0xd8, 0xfb, 0xff, 0x20, 0xe2, 0x2a, 0x13, 0x92,
    0x04, 0xef, 0xa2, 0xe1, 0x92, 0x03, 0x30, 0x04, 0x1f, 0xe4,
    0xf5, 0x10, 0xe5, 0x10, 0x24, 0x17, 0xfd, 0x7b, 0x54, 0x7f,
    0x04, 0x12, 0x3d, 0xd7, 0x74, 0x25, 0x25, 0x10, 0xf8, 0xa6,
    0x07, 0x05, 0x10, 0xe5, 0x10, 0xc3, 0x94, 0x02, 0x40, 0xe4,
    0x12, 0x44, 0xa3, 0x12, 0x44, 0xaa, 0xd8, 0xfb, 0x54, 0x05,
    0x64, 0x04, 0x70, 0x27, 0x78, 0xc4, 0xe6, 0x78, 0xc6, 0xf6,
    0xe5, 0x7d, 0xff, 0x33, 0x95, 0xe0, 0xef, 0x54, 0x0f, 0x78,
    0xc4, 0xf6, 0x12, 0x42, 0xcf, 0x20, 0x04, 0x0c, 0x12, 0x44,
    0xa3, 0x12, 0x44, 0xaa, 0xd8, 0xfb, 0x13, 0x92, 0x05, 0x22,
    0xc2, 0x05, 0x22, 0x12, 0x44, 0xa3, 0x12, 0x44, 0xaa, 0xd8,
    0xfb, 0x54, 0x05, 0x64, 0x05, 0x70, 0x1e, 0x78, 0xc4, 0x7d,
    0xb8, 0x12, 0x42, 0xc5, 0x78, 0xc1, 0x7d, 0x74, 0x12, 0x42,
    0xc5, 0xe4, 0x78, 0xc1, 0xf6, 0x22, 0x7b, 0x01, 0x7a, 0x00,
    0x7d, 0xee, 0x7f, 0x92, 0x12, 0x38, 0xbd, 0x22, 0xe6, 0xfb,
    0x7a, 0x00, 0x7f, 0x92, 0x12, 0x38, 0xbd, 0x22, 0x78, 0xc1,
    0xe6, 0xfb, 0x7a, 0x00, 0x7d, 0x74, 0x7f, 0x92, 0x12, 0x38,
    0xbd, 0xe4, 0x78, 0xc1, 0xf6, 0xf5, 0x11, 0x74, 0x01, 0x7e,
    0x00, 0xa8, 0x11, 0x08, 0x80, 0x05, 0xc3, 0x33, 0xce, 0x33,
    0xce, 0xd8, 0xf9, 0xff, 0x78, 0xc4, 0xe6, 0xfd, 0xef, 0x5d,
    0x60, 0x44, 0x85, 0x11, 0xfb, 0xe5, 0x11, 0x54, 0x02, 0x25,
    0xe0, 0x25, 0xe0, 0xfe, 0xe4, 0x24, 0x5b, 0xfb, 0xee, 0x12,
    0x44, 0x2d, 0x12, 0x3e, 0xda, 0x7b, 0x40, 0x7d, 0x11, 0x7f,
    0x07, 0x12, 0x3d, 0xd7, 0x74, 0xc7, 0x25, 0x11, 0xf8, 0xa6,
    0x07, 0x7b, 0x11, 0x7d, 0x12, 0x7f, 0x07, 0x12, 0x3d, 0xd7,
    0xef, 0x4e, 0x60, 0x09, 0x74, 0xe7, 0x25, 0x11, 0xf8, 0x76,
    0x04, 0x80, 0x07, 0x74, 0xe7, 0x25, 0x11, 0xf8, 0x76, 0x0a,
    0x05, 0x11, 0xe5, 0x11, 0xc3, 0x94, 0x04, 0x40, 0x9a, 0x78,
    0xc6, 0xe6, 0x70, 0x15, 0x78, 0xc4, 0xe6, 0x60, 0x10, 0x75,
    0xd9, 0x38, 0x75, 0xdb, 0x10, 0x7d, 0xfe, 0x12, 0x43, 0x7d,
    0x7d, 0x76, 0x12, 0x43, 0x7d, 0x79, 0xc6, 0xe7, 0x78, 0xc4,
    0x66, 0xff, 0x60, 0x03, 0x12, 0x40, 0x25, 0x78, 0xc4, 0xe6,
    0x70, 0x09, 0xfb, 0xfa, 0x7d, 0xfe, 0x7f, 0x8e, 0x12, 0x38,
    0xbd, 0x22, 0x7b, 0x01, 0x7a, 0x00, 0x7f, 0x8e, 0x12, 0x38,
    0xbd, 0x22, 0xe4, 0xf5, 0x19, 0x74, 0x25, 0x25, 0x19, 0xf8,
    0xe6, 0x64, 0x03, 0x60, 0x51, 0xe5, 0x19, 0x24, 0x17, 0xfd,
    0x7b, 0xeb, 0x7f, 0x04, 0x12, 0x3d, 0xd7, 0x8f, 0xfb, 0x7b,
    0x22, 0x7d, 0x18, 0x7f, 0x06, 0x12, 0x3d, 0xd7, 0xef, 0x64,
    0x01, 0x4e, 0x60, 0x1c, 0x7d, 0x1c, 0xe4, 0xff, 0x12, 0x3e,
    0x9a, 0xef, 0x54, 0x1b, 0x64, 0x0a, 0x70, 0x15, 0x7b, 0xcc,
    0x7d, 0x10, 0xff, 0x12, 0x3d, 0xd7, 0xef, 0x64, 0x01, 0x4e,
    0x70, 0x07, 0x12, 0x44, 0xb1, 0x7b, 0x03, 0x80, 0x0a, 0x12,
    0x44, 0xb1, 0x74, 0x25, 0x25, 0x19, 0xf8, 0xe6, 0xfb, 0x7a,
    0x00, 0x7d, 0x54, 0x12, 0x38, 0xbd, 0x05, 0x19, 0xe5, 0x19,
    0xc3, 0x94, 0x02, 0x40, 0x9c, 0x22, 0xe5, 0x7e, 0x30, 0xe5,
    0x35, 0x30, 0xe4, 0x0b, 0x7b, 0x02, 0x7d, 0x33, 0x7f, 0x35,
    0x12, 0x36, 0x29, 0x80, 0x10, 0x7b, 0x01, 0x7d, 0x33, 0x7f,
    0x35, 0x12, 0x36, 0x29, 0x90, 0x47, 0xd2, 0xe0, 0x44, 0x04,
    0xf0, 0x90, 0x47, 0xd2, 0xe0, 0x54, 0xf7, 0xf0, 0x90, 0x47,
    0xd1, 0xe0, 0x44, 0x10, 0xf0, 0x7b, 0x05, 0x7d, 0x84, 0x7f,
    0x86, 0x12, 0x36, 0x29, 0x22, 0xfb, 0xe5, 0x1c, 0x34, 0xf0,
    0xfa, 0x7d, 0x10, 0x7f, 0x07, 0x22, 0x54, 0x01, 0xc4, 0x33,
    0x54, 0xe0, 0xf5, 0xdb, 0x44, 0x08, 0xf5, 0xdb, 0x22, 0xf5,
    0xdb, 0x75, 0xdb, 0x08, 0xf5, 0xdb, 0x75, 0xdb, 0x08, 0x22,
    0xe5, 0x7e, 0x54, 0x0f, 0x64, 0x01, 0x70, 0x0d, 0xe5, 0x7e,
    0x30, 0xe4, 0x08, 0x90, 0x47, 0xd0, 0xe0, 0x44, 0x02, 0xf0,
    0x22, 0x90, 0x47, 0xd0, 0xe0, 0x54, 0xfd, 0xf0, 0x22, 0xab,
    0x07, 0xaa, 0x06, 0x7d, 0x10, 0x7f, 0x07, 0x12, 0x3e, 0xda,
    0x7b, 0xff, 0x7d, 0x10, 0x7f, 0x07, 0x12, 0x3d, 0xd7, 0xef,
    0x4e, 0x60, 0xf3, 0x22, 0x12, 0x44, 0xc5, 0x12, 0x44, 0xbb,
    0x90, 0x47, 0xfa, 0xe0, 0x54, 0xf8, 0x44, 0x02, 0xf0, 0x22,
    0x30, 0x04, 0x03, 0x12, 0x43, 0x87, 0x78, 0xc4, 0xe6, 0xff,
    0x60, 0x03, 0x12, 0x40, 0x25, 0x22, 0xe5, 0x7e, 0xae, 0x7d,
    0x78, 0x04, 0x22, 0xce, 0xa2, 0xe7, 0x13, 0xce, 0x13, 0x22,
    0xe5, 0x19, 0x24, 0x17, 0x54, 0x1f, 0x44, 0x80, 0xff, 0x22,
    0xe4, 0x78, 0xc4, 0xf6, 0xc2, 0x05, 0x78, 0xc1, 0xf6, 0x22,
    0xc2, 0x04, 0xc2, 0x03, 0x22, 0x22
};


/**
 * Setup Vitesse PHYs
 * This function sets up one port in a Vitesse VSC8574 for
 * either SGMII or QSGMII
 */
static void setup_vitesse_phy(bdk_node_t node, int mdio_bus, int phy_addr, bool qsgmii)
{
    // Select "G" registers
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x10);
    // Reg 19G, bit 15:14
    // 0 = SGMII
    // 1 = QSGMII
    int reg19 = bdk_mdio_read(node, mdio_bus, phy_addr, 19);
    int reg18;
    if (qsgmii)
    {
        // QSGMII
        reg19 = bdk_insert(reg19, 1, 14, 2);
        reg18 = 0x80e0;
    }
    else
    {
        // SGMII
        reg19 = bdk_insert(reg19, 0, 14, 2);
        reg18 = 0x80f0;
    }
    bdk_mdio_write(node, mdio_bus, phy_addr, 19, reg19);
    // Write 18G, change all 4 ports
    bdk_mdio_write(node, mdio_bus, phy_addr, 18, reg18);
    // Select main registers
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0);
    // Reg23, 10:8 Select copper
    int reg23 = bdk_mdio_read(node, mdio_bus, phy_addr, 23);
    reg23 = bdk_insert(23, 0, 8, 3);
    bdk_mdio_write(node, mdio_bus, phy_addr, 23, reg23);
    // Reg0, Reset
    int reg0 = bdk_mdio_read(node, mdio_bus, phy_addr, 0);
    reg0 = bdk_insert(reg0, 1, 15, 1);
    bdk_mdio_write(node, mdio_bus, phy_addr, 0, reg0);
    // Reg 16E3, bit 7 auto negotiation
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 3);
    bdk_mdio_write(node, mdio_bus, phy_addr, 16, 0x80);
    // Select main registers
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0);
    // Near end loopback (Thunder side)
    if (LOOP_INTERNAL)
    {
        reg0 = bdk_mdio_read(node, mdio_bus, phy_addr, 0);
        reg0 = bdk_insert(reg0, 1, 14, 1);
        bdk_mdio_write(node, mdio_bus, phy_addr, 0, reg0);
    }

    // Far end loopback (External side)
    if (LOOP_EXTERNAL)
    {
        for (int port=0; port < 4; port++)
        {
            reg23 = bdk_mdio_read(node, mdio_bus, phy_addr + port, 23);
            reg23 = bdk_insert(reg23, 1, 3, 1);
            bdk_mdio_write(node, mdio_bus, phy_addr + port, 23, reg23);
        }
    }

    // Dump registers
    if (false)
    {
        printf("\nVitesse PHY register dump, PHY address %d, mode %s\n",
               phy_addr, (qsgmii) ? "QSGMII" : "SGMII");
        int phy_addr = 4;
        for (int reg_set = 0; reg_set <= 0x10; reg_set += 0x10)
        {
            printf("\nDump registers with reg[31]=0x%x\n", reg_set);
            bdk_mdio_write(node, mdio_bus, phy_addr, 31, reg_set);
            for (int reg=0; reg < 32; reg++)
                printf("reg[%02d]=0x%x\n", reg, bdk_mdio_read(node, mdio_bus, phy_addr, reg));
        }
    }
}

static void wr_masked(bdk_node_t node, int mdio_bus, int phy_addr, int reg, int value, int mask)
{
    int nmask = ~mask;
    int old = bdk_mdio_read(node, mdio_bus, phy_addr, reg);
    int vmask = value & mask;
    int newv = old & nmask;
    newv = newv | vmask;
    bdk_mdio_write(node, mdio_bus, phy_addr, reg, value);
}

static void vitesse_program(bdk_node_t node, int mdio_bus, int phy_addr)
{
    printf("Programming Vitesse PHY at address %d\n", phy_addr);
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0010);
    bdk_mdio_write(node, mdio_bus, phy_addr, 18, 0x800f);
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0010);

    int reg18g = bdk_mdio_read(node, mdio_bus, phy_addr, 18);
    int timeout = 10;
    while ((reg18g & (1<<15)) && (timeout > 0))
    {
        bdk_wait_usec(100000);
        reg18g = bdk_mdio_read(node, mdio_bus, phy_addr, 18);
        timeout = timeout - 1;
    }

    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0000);
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0010);
    wr_masked(node, mdio_bus, phy_addr, 12, 0x0000, 0x0800);
    bdk_mdio_write(node, mdio_bus, phy_addr,  9, 0x005b);
    bdk_mdio_write(node, mdio_bus, phy_addr, 10, 0x005b);
    wr_masked(node, mdio_bus, phy_addr, 12, 0x0800, 0x0800);
    bdk_mdio_write(node, mdio_bus, phy_addr, 18, 0x800f);
    wr_masked(node, mdio_bus, phy_addr, 0, 0x0000, 0x8000);
    bdk_mdio_write(node, mdio_bus, phy_addr, 18, 0x0000);
    wr_masked(node, mdio_bus, phy_addr, 12, 0x0000, 0x0800);
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x10);
    bdk_mdio_write(node, mdio_bus, phy_addr, 0, 0x7009);
    bdk_mdio_write(node, mdio_bus, phy_addr, 12, 0x5002);
    bdk_mdio_write(node, mdio_bus, phy_addr, 11, 0x0000);

    for (unsigned int i=0; i<sizeof(patch_arr); i++)
    {
        int d = 0x5000 | patch_arr[i];
        bdk_mdio_write(node, mdio_bus, phy_addr, 12, d);
    }
    bdk_mdio_write(node, mdio_bus, phy_addr, 12, 0x0000);

    bdk_mdio_write(node, mdio_bus, phy_addr,  3, 0x3eb7);
    bdk_mdio_write(node, mdio_bus, phy_addr,  4, 0x4012);
    bdk_mdio_write(node, mdio_bus, phy_addr, 12, 0x0100);
    bdk_mdio_write(node, mdio_bus, phy_addr,  0, 0x4018);
    bdk_mdio_write(node, mdio_bus, phy_addr,  0, 0xc018);

    // below verifies CRC is correct in 8051 RAM.  CRC is 16-bit.
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0001);
    bdk_mdio_write(node, mdio_bus, phy_addr, 25, 0x4000);
    bdk_mdio_write(node, mdio_bus, phy_addr, 26, sizeof(patch_arr) + 1);
    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0010);
    bdk_mdio_write(node, mdio_bus, phy_addr, 18, 0x8008);

    reg18g = bdk_mdio_read(node, mdio_bus, phy_addr, 18);
    timeout = 10;
    while ((reg18g & (1<<15)) && (timeout > 0))
    {
        bdk_wait_usec(100000);
        reg18g = bdk_mdio_read(node, mdio_bus, phy_addr, 18);
        timeout = timeout - 1;
    }

    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0001);

    int crc_calculated = bdk_mdio_read(node, mdio_bus, phy_addr, 25);
    if (crc_calculated != 0xB7C2)
        printf("8051 crc_calculated = 0x%x, expected_crc = 0x%x\n", crc_calculated, 0xB7C2);

    bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x0000);
}

static void vetesse_setup(bdk_node_t node, int qlm, int mdio_bus, int phy_addr)
{
    /* Check if the PHY is Vetesse PHY we expect */
    int phy_status = bdk_mdio_read(node, mdio_bus, phy_addr, BDK_MDIO_PHY_REG_ID1);
    if (phy_status != 0x0007)
        return;

    /* Check that the GSER mode is SGMII or QSGMII */
    bdk_qlm_modes_t qlm_mode = bdk_qlm_get_mode(node, qlm);
    if ((qlm_mode != BDK_QLM_MODE_SGMII_2X1) &&
        (qlm_mode != BDK_QLM_MODE_SGMII_4X1) &&
        (qlm_mode != BDK_QLM_MODE_QSGMII_4X1))
        return;

    /* Program the Vetesse PHY */
    vitesse_program(node, mdio_bus, phy_addr);

    /* Switch the Vitesse PHY to the correct mode */
    setup_vitesse_phy(node, mdio_bus, phy_addr, (qlm_mode == BDK_QLM_MODE_QSGMII_4X1));
}

int bdk_if_phy_vetesse_setup(bdk_node_t node)
{
    for (int bgx = 0; bgx < 4; bgx++)
    {
        int port = 0;
        int phy_addr = bdk_config_get_int(BDK_CONFIG_PHY_ADDRESS, node, bgx, port);
        if (phy_addr != -1)
        {
            int node = (phy_addr >> 24) & 0xff;
            int mdio_bus = (phy_addr >> 8) & 0xff;
            int mdio_addr = phy_addr & 0xff;
            if (node == 0xff)
                node = bdk_numa_local();
            if ((phy_addr & BDK_IF_PHY_TYPE_MASK) == BDK_IF_PHY_MDIO)
            {
                int qlm = bdk_qlm_get(node, BDK_IF_BGX, bgx, port);
                if (qlm != -1)
                    vetesse_setup(node, qlm, mdio_bus, mdio_addr);
            }
        }
    }
    return 0;
}

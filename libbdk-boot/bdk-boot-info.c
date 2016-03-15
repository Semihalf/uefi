#include <bdk.h>

/**
 * Display information about strapping and other hard configuration items for
 * the specified node
 *
 * @param node   Node to display
 */
void bdk_boot_info_strapping(bdk_node_t node)
{
    BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
    BDK_CSR_INIT(gicd_iidr, node, BDK_GICD_IIDR);

    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    const char *boot_method_str;
    int boot_method = bdk_extract(gpio_strap.u, 0, 4);
    int vrm_disable = bdk_extract(gpio_strap.u, 9, 1);
    int trust_mode = bdk_extract(gpio_strap.u, 10, 1);

    switch (boot_method)
    {
        case BDK_RST_BOOT_METHOD_E_CCPI0_CN88XX:
            boot_method_str = "CCPI0";
            break;
        case BDK_RST_BOOT_METHOD_E_CCPI1_CN88XX:
            boot_method_str = "CCPI1";
            break;
        case BDK_RST_BOOT_METHOD_E_CCPI2_CN88XX:
            boot_method_str = "CCPI2";
            break;
        case BDK_RST_BOOT_METHOD_E_EMMC_LS:
            boot_method_str = "EMMC_LS";
            break;
        case BDK_RST_BOOT_METHOD_E_EMMC_SS:
            boot_method_str = "EMMC_SS";
            break;
        case BDK_RST_BOOT_METHOD_E_PCIE0_CN88XX:
            boot_method_str = "PCIE0";
            break;
        case BDK_RST_BOOT_METHOD_E_REMOTE:
            boot_method_str = "REMOTE";
            break;
        case BDK_RST_BOOT_METHOD_E_SPI24:
            boot_method_str = "SPI24";
            break;
        case BDK_RST_BOOT_METHOD_E_SPI32:
            boot_method_str = "SPI32";
            break;
        default:
            boot_method_str = "UNKNOWN";
            break;
    }

    /* Read the Pass information for fuses so we can read a different node.
       Note that pass info in MIO_FUS_DAT2[CHIP_ID] is encoded as
            bit[7] = Unused, zero
            bit[6] = Alternate package
            bit[5..3] = Major pass
            bit[2..0] = Minor pass */
    int alt_pkg = (mio_fus_dat2.s.chip_id >> 6) & 1;
    int major_pass = ((mio_fus_dat2.s.chip_id >> 3) & 7) + 1;
    int minor_pass = mio_fus_dat2.s.chip_id & 7;
    const char *package_str = (alt_pkg) ? " (alt pkg)" : "";

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_INIT(ocx_com_node, node, BDK_OCX_COM_NODE);
        printf("Node:  %d%s\n",
            node, (ocx_com_node.s.fixed_pin) ? " (Fixed)" : "");
    }

    printf(
        "Chip:  0x%x Pass %d.%d%s\n"
        "L2:    %d KB\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        gicd_iidr.s.productid, major_pass, minor_pass, package_str,
        bdk_l2c_get_cache_size_bytes(node) >> 10,
        bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) && !bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        const char *ccpi;
        BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(8));
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        {
            /* Pass 1.x used a different encoding than pass 2.x */
            switch (gserx_spd.s.spd)
            {
                case 0x0:
                    ccpi = "1.250 Ghz, ref 100 Mhz";
                    break;
                case 0x1:
                    ccpi = "2.500 Ghz, ref 100 Mhz";
                    break;
                case 0x2:
                    ccpi = "5.000 Ghz, ref 100 Mhz";
                    break;
                case 0x3:
                    ccpi = "8.000 Ghz, ref 100 Mhz";
                    break;
                case 0x4:
                    ccpi = "1.250 Ghz, ref 125 Mhz";
                    break;
                case 0x5:
                    ccpi = "2.500 Ghz, ref 125 Mhz";
                    break;
                case 0x6:
                    ccpi = "3.125 Ghz, ref 125 Mhz";
                    break;
                case 0x7:
                    ccpi = "5.000 Ghz, ref 125 Mhz";
                    break;
                case 0x8:
                    ccpi = "6.250 Ghz, ref 125 Mhz";
                    break;
                case 0x9:
                    ccpi = "8.000 Ghz, ref 125 Mhz, KR training";
                    break;
                case 0xa:
                    ccpi = "2.500 Ghz, ref 156.25 Mhz";
                    break;
                case 0xb:
                    ccpi = "3.125 Ghz, ref 156.25 Mhz";
                    break;
                case 0xc:
                    ccpi = "5.000 Ghz, ref 156.25 Mhz";
                    break;
                case 0xd:
                    ccpi = "6.250 Ghz, ref 156.25 Mhz";
                    break;
                case 0xe:
                    ccpi = "10.312 Ghz, ref 156.25 Mhz, KR training";
                    break;
                default: /* Software mode */
                    ccpi = "Disabled";
                    break;
            }
        }
        else
        {
            /* This is for pass 2.x (and beyond) */
            switch (gserx_spd.s.spd)
            {
                case 0x0:
                    ccpi = "5.000 Ghz, ref 100 Mhz, RX Equalization";
                    break;
                case 0x1:
                    ccpi = "2.500 Ghz, ref 100 Mhz";
                    break;
                case 0x2:
                    ccpi = "5.000 Ghz, ref 100 Mhz";
                    break;
                case 0x3:
                    ccpi = "8.000 Ghz, ref 100 Mhz";
                    break;
                case 0x4:
                    ccpi = "8.000 Ghz, ref 100 Mhz, RX Equalization";
                    break;
                case 0x5:
                    ccpi = "8.000 Ghz, ref 100 Mhz, KR Training";
                    break;
                case 0x6:
                    ccpi = "3.125 Ghz, ref 156.25 Mhz";
                    break;
                case 0x7:
                    ccpi = "5.000 Ghz, ref 125 Mhz";
                    break;
                case 0x8:
                    ccpi = "6.250 Ghz, ref 156.25 Mhz";
                    break;
                case 0x9:
                    ccpi = "8.000 Ghz, ref 125 Mhz";
                    break;
                case 0xa:
                    ccpi = "10.312 Ghz, ref 156.25 Mhz, RX Equalization";
                    break;
                case 0xb:
                    ccpi = "3.125 Ghz, ref 156.25 Mhz";
                    break;
                case 0xc:
                    ccpi = "5.000 Ghz, ref 125 Mhz, RX Equalization";
                    break;
                case 0xd:
                    ccpi = "6.250 Ghz, ref 156.25 Mhz, RX Equalization";
                    break;
                case 0xe:
                    ccpi = "10.312 Ghz, ref 156.25 Mhz, KR Training";
                    break;
                default: /* Software mode */
                    ccpi = "Disabled";
                    break;
            }
        }
        printf("CCPI:  %s\n", ccpi);
    }
}

/**
 * Return a string containing information about the chip's manufacture wafer
 *
 * @param node   Node to query
 *
 * @return Static string, reused on each call
 */
const char *bdk_boot_info_wafer(bdk_node_t node)
{
    #define DECODE_LOTID_CHAR(x)    (x < 10 ? '0' + x : x < 36 ? 'A' + x - 10 : ' ')
    static char buffer[64];

    /* This fuse read will load all 128 fuses into MIO_FUS_BNK_DATX */
    bdk_fuse_read(node, BDK_MIO_FUS_FUSE_NUM_E_MFG0X(0));
    /* Get MFG0 and MFG0 from MIO_FUS_BNK_DATX */
    uint64_t mfg0 = BDK_CSR_READ(node, BDK_MIO_FUS_BNK_DATX(0));
    uint64_t mfg1 = BDK_CSR_READ(node, BDK_MIO_FUS_BNK_DATX(1));
    /* If either MFG area is programed, assume they are valid */
    if (mfg0 || mfg1)
    {
        /* Extract the mother lot ID */
        int c9 = bdk_extract(mfg0, 0, 6);
        int c8 = bdk_extract(mfg0, 6, 6);
        int c7 = bdk_extract(mfg0, 12, 6);
        int c6 = bdk_extract(mfg0, 18, 6);
        int c5 = bdk_extract(mfg0, 24, 6);
        int c4 = bdk_extract(mfg0, 30, 6);
        int c3 = bdk_extract(mfg0, 36, 6);
        int c2 = bdk_extract(mfg0, 42, 6);
        int c1 = bdk_extract(mfg0, 48, 6);
        /* Extract wafer, X, and Y data */
        int y = bdk_extract(mfg1, 0, 10);
        int x = bdk_extract(mfg1, 10, 10);
        int wafer_id = bdk_extract(mfg1, 20, 6);
        snprintf(buffer, sizeof(buffer), "Lot ID: %c%c%c%c%c%c%c.%c%c, Wafer ID: %2d, X-loc: %2d, Y-loc: %2d",
            DECODE_LOTID_CHAR(c1), DECODE_LOTID_CHAR(c2), DECODE_LOTID_CHAR(c3),
            DECODE_LOTID_CHAR(c4), DECODE_LOTID_CHAR(c5), DECODE_LOTID_CHAR(c6),
            DECODE_LOTID_CHAR(c7), DECODE_LOTID_CHAR(c8), DECODE_LOTID_CHAR(c9),
            wafer_id, x, y);
    }
    else
    {
        /* Nothing programmed in the fuses */
        snprintf(buffer, sizeof(buffer), "Lot id: Not available");
    }

    return buffer;
}

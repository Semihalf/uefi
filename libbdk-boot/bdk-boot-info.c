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
    int boot_method;
    int vrm_disable;
    int trust_mode;
    const char *boot_method_str;
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);
    BDK_EXTRACT(vrm_disable, gpio_strap.u, 9, 1);
    BDK_EXTRACT(trust_mode, gpio_strap.u, 10, 1);

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


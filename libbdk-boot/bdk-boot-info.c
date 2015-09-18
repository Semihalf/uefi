#include <bdk.h>

/**
 * Display information about strapping and other hard configuration items for
 * the specified node
 *
 * @param node   Node to display
 */
void bdk_boot_info_strapping(bdk_node_t node)
{
    BDK_CSR_INIT(ocx_com_node, node, BDK_OCX_COM_NODE);
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

    printf(
        "Node:  %d%s\n"
        "Chip:  0x%x Pass %d.%d%s\n"
        "L2:    %d KB\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        node, (ocx_com_node.s.fixed_pin) ? " (Fixed)" : "",
        gicd_iidr.s.productid, major_pass, minor_pass, package_str,
        bdk_l2c_get_cache_size_bytes(node) >> 10,
        bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");
}


/**
 * Create a BDK style device name to access SPI. This name can then be
 * passed to standard C functions to open the device.
 *
 * @param buffer Buffer to fill with the device name
 * @param buffer_size
 *               Length of the buffer
 * @param boot_method
 *               Value of the pin strap choosing the boot method
 */
static void create_spi_device_name(char *buffer, int buffer_size, int boot_method)
{
    bdk_node_t node = bdk_numa_master();
    BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
    int chip_select = 0;
    int address_width;
    int active_high = mpi_cfg.s.cshi;
    int idle_mode = (mpi_cfg.s.idleclks) ? 'r' : (mpi_cfg.s.idlelo) ? 'l' : 'h';
    int is_msb = !mpi_cfg.s.lsbfirst;
    int freq_mhz = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (2 * mpi_cfg.s.clkdiv) / 1000000;

    if (boot_method == BDK_RST_BOOT_METHOD_E_SPI24)
        address_width = 24;
    else
        address_width = 32;

    snprintf(buffer, buffer_size, "/dev/n%d.mpi%d/cs-%c,2wire,idle-%c,%csb,%dbit,%d",
        node,
        chip_select,
        (active_high) ? 'h' : 'l',
        idle_mode,
        (is_msb) ? 'm' : 'l',
        address_width,
        freq_mhz);
}

/**
 * Query the hardware and determine the filename representing the boot device
 *
 * @return String represent the boot device. An example would be
 *         "/dev/n0.mmc0"
 */
const char *bdk_boot_info_bootdev(void)
{
    static char boot_device_name[48] = "";

    /* Return the last value if we've already filled boot_device_name */
    if (boot_device_name[0])
        return boot_device_name;

    bdk_node_t node = bdk_numa_master();

    /* Determine how we booted */
    int boot_method;
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

    switch (boot_method)
    {
        case BDK_RST_BOOT_METHOD_E_EMMC_LS:
        case BDK_RST_BOOT_METHOD_E_EMMC_SS:
            snprintf(boot_device_name, sizeof(boot_device_name), "/dev/n%d.mmc0", node);
            break;
        case BDK_RST_BOOT_METHOD_E_SPI24:
        case BDK_RST_BOOT_METHOD_E_SPI32:
            create_spi_device_name(boot_device_name, sizeof(boot_device_name), boot_method);
            break;
        default:
            break;
    }
    return boot_device_name;
}


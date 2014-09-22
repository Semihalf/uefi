#include <bdk.h>

/* Which TWSI interface to use for the BMC, -1 to disable */
#define BMC_TWSI -1
/* Control if we even try and do multi-node (0 ro 1) */
#define MULTI_NODE 0
/* Name of DRAM config for master node 0 */
#define DRAM_NODE0 ebb8800
/* Name of DRAM config for slave node 1 */
#define DRAM_NODE1 ebb8800
/* How long to wait for selection of diagnostics */
#define DIAGS_TIMEOUT 0
/* Address of the diagnostics in flash */
#define DIAGS_ADDRESS 0x00080000
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00800000

#define _CONFIG_FUNC_NAME(n) dram_get_config_ ## n
#define CONFIG_FUNC_NAME(n) _CONFIG_FUNC_NAME(n)

/**
 * This enumeration represents the status codes that can be reported to the BMC
 * for boot status.
 */
typedef enum
{
    BMC_STATUS_BOOT_STUB_STARTING               = 0x000,
    BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE    = 0x001,
    BMC_STATUS_BOOT_STUB_CCPI_COMPLETE          = 0x002,
    BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE    = 0x003,
    BMC_STATUS_BOOT_STUB_QLM_COMPLETE           = 0x004,
    BMC_STATUS_BOOT_STUB_LOADING_ATF            = 0x005,
    BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS    = 0x006,
    BMC_STATUS_BOOT_STUB_COMPLETE               = 0x007,
} bmc_status_t;

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(QLM);
    BDK_REQUIRE(PCIE);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(RNG);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(TWSI);
    BDK_REQUIRE(USB);
}

/**
 * Report boot status to the BMC
 *
 * @param status Status to report
 */
static void update_bmc_status(bmc_status_t status)
{
    if (BMC_TWSI != -1)
    {
        BDK_CSR_MODIFY(c, bdk_numa_master(), BDK_MIO_TWSX_SW_TWSI(BMC_TWSI),
            c.s.v = 1;
            c.s.data = status);
    }
}

/**
 * Boot an image from a device file at the specified location
 *
 * @param dev_filename
 *               Device file to read image from
 * @param loc    Location offset in the device file
 */
static void boot_image(const char *dev_filename, uint64_t loc)
{
    void *image = NULL;

    FILE *inf = fopen(dev_filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", dev_filename);
        return;
    }

    printf("    Loading image at 0x%lx\n", loc);
    fseek(inf, loc, SEEK_SET);

    bdk_image_header_t header;
    int status = bdk_image_read_header(inf, &header);
    if (status != 0)
    {
        bdk_error("Image header is corrupt\n");
        goto out;
    }

    image = malloc(header.length);
    if (image == NULL)
    {
        bdk_error("Failed to allocate %d bytes for image\n", header.length);
        goto out;
    }
    memcpy(image, &header, sizeof(header));
    int count = fread(image + sizeof(header), header.length - sizeof(header), 1, inf);
    if (count != 1)
    {
        bdk_error("Failed read image\n");
        goto out;
    }

    printf("    Verifying image\n");
    if (bdk_image_verify(image))
    {
        bdk_error("Image CRC32 is incorrect\n");
        goto out;
    }

    printf("    Putting all cores except this one in reset\n");
    bdk_reset_cores(bdk_numa_local(), ~bdk_core_to_mask());

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;

    /* Send status to the BMC: Boot stub complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_COMPLETE);

    if (bdk_jump_address(bdk_ptr_to_phys(image)))
    {
        bdk_error("Failed to jump to image\n");
        goto out;
    }

out:
    if (image)
        free(image);
    fclose(inf);
}

static void create_spi_device_name(char *buffer, int buffer_size, int boot_method)
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
    int chip_select = 0;
    int address_width;
    int active_high = mpi_cfg.s.cshi;
    int idle_mode = (mpi_cfg.s.idleclks) ? 'r' : (mpi_cfg.s.idlelo) ? 'l' : 'h';
    int is_msb = !mpi_cfg.s.lsbfirst;
    int freq_mhz = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (2 * mpi_cfg.s.clkdiv) / 1000000;

    if (boot_method == RST_BOOT_METHOD_E_SPI16)
        address_width = 16;
    else if (boot_method == RST_BOOT_METHOD_E_SPI24)
        address_width = 24;
    else
        address_width = 32;

    snprintf(buffer, buffer_size, "/dev/mpi/cs%d-%c,2wire,idle-%c,%csb,%dbit,%d",
        chip_select,
        (active_high) ? 'h' : 'l',
        idle_mode,
        (is_msb) ? 'm' : 'l',
        address_width,
        freq_mhz);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();

    /* Drive GPIO 10 high, signalling success transferring from the boot ROM */
    bdk_gpio_initialize(node, 10, 1, 1);

    /* Initialize TWSI interface TBD as a slave */
    //FIXME

    /* Send status to the BMC: Started boot stub */
    update_bmc_status(BMC_STATUS_BOOT_STUB_STARTING);

    /* Initialize UART was done earlier in the BDK */
    /* Decode how we booted and display a banner */
    bdk_sys_midr_el1_t midr_el1;
    midr_el1.u = cavium_get_model();
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    int boot_method;
    int vrm_disable;
    int trust_mode;
    const char *boot_method_str;
    char boot_device_name[48];
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);
    BDK_EXTRACT(vrm_disable, gpio_strap.u, 9, 1);
    BDK_EXTRACT(trust_mode, gpio_strap.u, 10, 1);
    BDK_CSR_INIT(ocx_com_node, node, BDK_OCX_COM_NODE);
    boot_device_name[0] = 0;

    switch (boot_method)
    {
        case RST_BOOT_METHOD_E_CCPI0:
            boot_method_str = "CCPI0";
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_CCPI1:
            boot_method_str = "CCPI1";
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_CCPI2:
            boot_method_str = "CCPI2";
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_EMMC_LS:
            boot_method_str = "EMMC_LS";
            strcpy(boot_device_name, "/dev/mmc/0");
            break;
        case RST_BOOT_METHOD_E_EMMC_SS:
            boot_method_str = "EMMC_SS";
            strcpy(boot_device_name, "/dev/mmc/0");
            break;
        case RST_BOOT_METHOD_E_PCIE0:
            boot_method_str = "PCIE0";
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_REMOTE:
            boot_method_str = "REMOTE";
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_SPI16:
            boot_method_str = "SPI16";
            create_spi_device_name(boot_device_name, sizeof(boot_device_name), boot_method);
            break;
        case RST_BOOT_METHOD_E_SPI24:
            boot_method_str = "SPI24";
            create_spi_device_name(boot_device_name, sizeof(boot_device_name), boot_method);
            break;
        case RST_BOOT_METHOD_E_SPI32:
            boot_method_str = "SPI32";
            create_spi_device_name(boot_device_name, sizeof(boot_device_name), boot_method);
            break;
        default:
            boot_method_str = "UNKNOWN";
            break;
    }

    printf(
        "BDK version: %s\n"
        "\n"
        "===============\n"
        "BDK Stage1 Boot\n"
        "===============\n"
        "Node:  %d%s\n"
        "Chip:  0x%x Pass %d.%d\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        bdk_version_string(),
        node, (ocx_com_node.s.fixed_pin) ? " (Fixed)" : "",
        midr_el1.s.partnum, midr_el1.s.variant + 1, midr_el1.s.revision,
        bdk_clock_get_rate(node, BDK_CLOCK_CORE) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");

    /* Initialize DRAM on the master node */
#ifdef DRAM_NODE0
    extern const dram_config_t* CONFIG_FUNC_NAME(DRAM_NODE0)(void);
    int mbytes = libdram_config(bdk_numa_master(), CONFIG_FUNC_NAME(DRAM_NODE0)(), 0);
    if (mbytes > 0)
    {
        if (MULTI_NODE)
            printf("Node %d: DRAM: %d MB\n", bdk_numa_master(), mbytes);
        else
            printf("DRAM:  %d MB\n", mbytes);
    }
    else
    {
        if (MULTI_NODE)
            bdk_error("Node %d failed DRAM init\n", bdk_numa_master());
        else
            bdk_error("Failed DRAM init\n");
    }
#endif

    /* Send status to the BMC: Master DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE);

    /* Setup CCPI such that both nodes can communicate */
    if (MULTI_NODE)
    {
        //FIXME
    }

    /* Send status to the BMC: Multi-node setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_CCPI_COMPLETE);

    /* Initialize DRAM on the slave node */
#ifdef DRAM_NODE1
    if (MULTI_NODE)
    {
        extern const dram_config_t* CONFIG_FUNC_NAME(DRAM_NODE1)(void);
        int mbytes = libdram_config(1, CONFIG_FUNC_NAME(DRAM_NODE1)(), 0);
        if (mbytes > 0)
            printf("Node %d: DRAM: %d MB\n", bdk_numa_master(), mbytes);
        else
            bdk_error("Node %d failed DRAM init\n", bdk_numa_master());
    }
#endif


    /* Send status to the BMC: Slave DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE);

    /* Initialize the QLMs */
    //FIXME

    /* Setup SMI/MDIO */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
            bdk_mdio_initialize(n);
    }

    /* Initialize BGX, ready for driver */
    //FIXME

    /* Send status to the BMC: QLM setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_QLM_COMPLETE);

    /* Initialize SATA, ready for standard AHCI driver */
    //FIXME

    /* Initialize USB, ready for standard XHCI driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < 2; p++)
                bdk_usb_intialize(n, p, 0);
        }
    }

    /* Initialize PCIe and bring up the link */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            bdk_pcie_global_initialize(n);
            for (int p = 0; p < bdk_pcie_get_num_ports(n); p++)
                bdk_pcie_rc_initialize(n, p);
        }
    }

    /* Setup TWSI at 100KHz frequency */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
            bdk_twsix_initialize(n);
    }

    /* Select ATF or diagnostics image */
    int use_atf = 1;
    //FIXME

    /* Initialize the filesystems be need to load code from SPI or eMMC */
    extern int bdk_fs_mmc_init(void);
    extern int bdk_fs_mpi_init(void);
    bdk_fs_mmc_init();
    bdk_fs_mpi_init();

    /* Send status to the BMC: Loading ATF */
    if (use_atf)
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_ATF);
    else
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS);

    /* Load the next image */
    /* Transfer control to next image */
    if (use_atf)
        boot_image(boot_device_name, ATF_ADDRESS);
    else
        boot_image(boot_device_name, DIAGS_ADDRESS);

    /* No image loadable */
    bdk_error("Unable to load image\n");
    if (use_atf)
    {
        printf("Trying diagnostics\n");
        boot_image(boot_device_name, DIAGS_ADDRESS);
    }

    bdk_error("Image load failed\n");
}


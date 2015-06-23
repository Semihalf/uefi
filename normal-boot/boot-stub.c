#include <bdk.h>
#include <malloc.h>

#include <board.h>

/* Set this to 0 for PCIe on QLMs 6-7. Set it to 1 for SATA when using the
   PCIe to SATA breakout card*/
#define USE_SATA_BREAKOUT_CARD 1
/* Enable verbose logging from DRAM initialization (0 or 1) */
#define DRAM_VERBOSE 0
/* Control whether the boot stub request power cycles from the BMC (0 or 1).
   This is only useful in conjuction with WATCHDOG_TIMEOUT */
#define USE_POWER_CYCLE (WATCHDOG_TIMEOUT != 0)
/* Perform a fast DRAM test before booting, rebooting or pwoer cycling on
   failure. Only useful if WATCHDOG_TIMEOUT */
#define RUN_DRAM_TEST (WATCHDOG_TIMEOUT != 0)
/* How long to wait for selection of diagnostics (seconds) */
#define DIAGS_TIMEOUT 3
/* How long to wait for selection of save boot (seconds) */
#define SAVE_BOOT_TIMEOUT 1
/* A GPIO can be used to select diagnostics without input. The following
   define controls which GPIO and the value that starts daignostics. Set
   DIAGS_GPIO_VALUE to -1 to disable */
#define DIAGS_GPIO 0
#define DIAGS_GPIO_VALUE -1
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00400000
/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_BOOT_STUB 0
/* Filename for bootstrap image on FATF filesystem */
#define BOOTSTRAP_IMAGE_FILENAME "bootstrap.bin"

/* This macro simplifies referencing DRAM configurations later in the
   code. It converts a DRAM_NODE* macro into a C function name. If
   DRAM_NODE0 is X, the function required is dram_get_config_X() */
#define _CONFIG_FUNC_NAME(n) dram_get_config_ ## n
#define CONFIG_FUNC_NAME(n) _CONFIG_FUNC_NAME(n)
#define XCONFIG_STR_NAME(n)	#n
#define CONFIG_STR_NAME(n) XCONFIG_STR_NAME(n)

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
    BMC_STATUS_REQUEST_POWER_CYCLE              = 0x0f2,
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
    BDK_REQUIRE(MDIO);
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
static int BMC_TWSI   = -1;
static int MULTI_NODE = 0;

static void update_bmc_status(bmc_status_t status)
{
    if (BMC_TWSI != -1)
    {
        BDK_CSR_MODIFY(c, bdk_numa_master(), BDK_MIO_TWSX_SW_TWSI(BMC_TWSI),
            c.s.v = 1;
            c.s.data = status);
        if (status == BMC_STATUS_REQUEST_POWER_CYCLE)
        {
            printf("Requested power cycle\n");
            bdk_wait_usec(5000000); /* 5 sec */
            bdk_reset_chip(bdk_numa_local());
        }
    }
}

static void reset_or_power_cycle(void)
{
    if (USE_POWER_CYCLE)
        update_bmc_status(BMC_STATUS_REQUEST_POWER_CYCLE);
    else
        bdk_reset_chip(bdk_numa_local());
}

/**
 * Boot an image from a device file at the specified location
 *
 * @param dev_filename
 *               Device file to read image from
 * @param loc    Location offset in the device file
 */
static void boot_image_raw(const char *dev_filename, uint64_t loc)
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

    image = memalign(128, header.length);
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
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;

    /* This string is passed to the image as a default environment. It is
       series of NAME=VALUE pairs separated by '\0'. The end is marked with
       two '\0' in a row. */
    char *image_env = "BOARD=crb_2s\0\0";

    /* Send status to the BMC: Boot stub complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_COMPLETE);

    if (WATCHDOG_TIMEOUT)
    {
        if (loc == ATF_ADDRESS)
        {
            /* Software wants the watchdog running with a 15 second timout */
            uint64_t timeout = 15 * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_SCLK) / 262144;
            /* Check for overflow */
            if (timeout > 0xffff)
                timeout = 0xffff;
            BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()),
                c.s.len = timeout;
                c.s.mode = 3);
        }
        else
        {
            /* Disable watchdog */
            BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
        }
    }
    /* Clear the boot counter */
    BDK_CSR_WRITE(bdk_numa_local(), BDK_GSERX_SCRATCH(0), 0);

    if (bdk_jump_address(bdk_ptr_to_phys(image), bdk_ptr_to_phys(image_env)))
    {
        bdk_error("Failed to jump to image\n");
        goto out;
    }

out:
    if (image)
        free(image);
    fclose(inf);
}

/**
 * Boot an image from a device file at the specified location
 *
 * @param filename      Filename of image to load
 */
static void boot_image(const char *filename)
{
    void *image = NULL;

    FILE *inf = fopen(filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", filename);
        return;
    }

    printf("    Loading image '%s'\n", filename);

    bdk_image_header_t header;
    int status = bdk_image_read_header(inf, &header);
    if (status != 0)
    {
        bdk_error("Image header is corrupt\n");
        goto out;
    }

    image = memalign(128, header.length);
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
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;

    /* This string is passed to the image as a default environment. It is
       series of NAME=VALUE pairs separated by '\0'. The end is marked with
       two '\0' in a row. */
    char *image_env = "BOARD=crb_2s\0\0";

    /* Send status to the BMC: Boot stub complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_COMPLETE);

    if (WATCHDOG_TIMEOUT)
    {
        /* Check if we are loading the ATF image. */
        if (strstr(filename, BOOTSTRAP_IMAGE_FILENAME))
        {
            /* Software wants the watchdog running with a 15 second timout */
            uint64_t timeout = 15 * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_SCLK) / 262144;
            /* Check for overflow */
            if (timeout > 0xffff)
                timeout = 0xffff;
            watchdog_set(timeout);
        }
        else
        {
            /* Disable watchdog */
            watchdog_disable();
        }
    }

    /* Clear the boot counter */
    BDK_CSR_WRITE(bdk_numa_local(), BDK_GSERX_SCRATCH(0), 0);

    if (bdk_jump_address(bdk_ptr_to_phys(image), bdk_ptr_to_phys(image_env)))
    {
        bdk_error("Failed to jump to image\n");
        goto out;
    }

out:
    if (image)
        free(image);
    fclose(inf);
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
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
    int chip_select = 0;
    int address_width;
    int active_high = mpi_cfg.s.cshi;
    int idle_mode = (mpi_cfg.s.idleclks) ? 'r' : (mpi_cfg.s.idlelo) ? 'l' : 'h';
    int is_msb = !mpi_cfg.s.lsbfirst;
    int freq_mhz = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (2 * mpi_cfg.s.clkdiv) / 1000000;

    if (boot_method == RST_BOOT_METHOD_E_SPI24)
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

static void print_node_strapping(bdk_node_t node)
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
        case RST_BOOT_METHOD_E_CCPI0:
            boot_method_str = "CCPI0";
            break;
        case RST_BOOT_METHOD_E_CCPI1:
            boot_method_str = "CCPI1";
            break;
        case RST_BOOT_METHOD_E_CCPI2:
            boot_method_str = "CCPI2";
            break;
        case RST_BOOT_METHOD_E_EMMC_LS:
            boot_method_str = "EMMC_LS";
            break;
        case RST_BOOT_METHOD_E_EMMC_SS:
            boot_method_str = "EMMC_SS";
            break;
        case RST_BOOT_METHOD_E_PCIE0:
            boot_method_str = "PCIE0";
            break;
        case RST_BOOT_METHOD_E_REMOTE:
            boot_method_str = "REMOTE";
            break;
        case RST_BOOT_METHOD_E_SPI24:
            boot_method_str = "SPI24";
            break;
        case RST_BOOT_METHOD_E_SPI32:
            boot_method_str = "SPI32";
            break;
        default:
            boot_method_str = "UNKNOWN";
            break;
    }

    printf(
        "Node:  %d%s\n"
        "Chip:  0x%x Pass %d.%d\n"
        "L2:    %d KB\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        node, (ocx_com_node.s.fixed_pin) ? " (Fixed)" : "",
        gicd_iidr.s.productid, (mio_fus_dat2.s.chip_id >> 3) + 1, mio_fus_dat2.s.chip_id & 7,
        bdk_l2c_get_cache_size_bytes(node) >> 10,
        bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();
    char *cfgfile;

    /* Initialize the FAT filesystems be need to load the next stage */
    extern int bdk_fs_fatfs_init(void);
    bdk_fs_fatfs_init();

    /* Check for save mode boot.
     *
     * This allows the user to boot in save mode in case the configuration file
     * does not work on the system and prevents boot.
     */
    printf("Press X to boot in save mode...\n");
    int key = bdk_readline_getkey(SAVE_BOOT_TIMEOUT * 1000000);
    if ((key == 'x') || (key == 'X'))
    {
        printf("=================================================\n"
               "= BOOTING in SAVE MODE\n"
               "=================================================\n");

        /* Use the safe mode configuration file. */
        cfgfile = BDK_ENV_CFG_FILE_NAME_SAVE_MODE;
    }
    else
    {
        cfgfile = NULL; /* NULL == default filename */
    }

    if (bdk_loadenv(cfgfile))
        bdk_warn("Could not read environment variables from config file. "
                 "Will use empty configuration...\n");

    /* Enable watchdog */
    watchdog_set(WATCHDOG_TIMEOUT);

    /* Read initial board configuration variables from config file. */
    BMC_TWSI   = bdk_brd_cfg_get_int(BDK_BRD_CFG_BMC_TWSI);
    MULTI_NODE = bdk_brd_cfg_get_int(BDK_BRD_CFG_MULTI_NODE);

    /* Initialize TWSI interface TBD as a slave */
    if (BMC_TWSI != -1)
    {
        BDK_TRACE(BOOT_STUB, "Initializing TWSI%d as a slave\n", BMC_TWSI);
        BDK_CSR_DEFINE(sw_twsi, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI));
        sw_twsi.u = 0;
        sw_twsi.s.slonly = 1; /* Slave only */
        BDK_CSR_WRITE(node, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI), sw_twsi.u);
    }

    /* Send status to the BMC: Started boot stub */
    update_bmc_status(BMC_STATUS_BOOT_STUB_STARTING);

    BDK_TRACE(BOOT_STUB, "Extracting strapping options\n");
    /* Initialize UART was done earlier in the BDK */
    /* Decode how we booted and display a banner */
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    int boot_method;
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

    /*
     * The code below is for loading ATF from raw flash.
     */
    char boot_device_name[48];
    boot_device_name[0] = 0;

    switch (boot_method)
    {
        case RST_BOOT_METHOD_E_CCPI0:
        case RST_BOOT_METHOD_E_CCPI1:
        case RST_BOOT_METHOD_E_CCPI2:
        case RST_BOOT_METHOD_E_PCIE0:
        case RST_BOOT_METHOD_E_REMOTE:
            /* Boot device controlled externally */
            break;
        case RST_BOOT_METHOD_E_EMMC_LS:
        case RST_BOOT_METHOD_E_EMMC_SS:
            sprintf(boot_device_name, "/dev/n%d.mmc0", node);
            break;
        case RST_BOOT_METHOD_E_SPI24:
        case RST_BOOT_METHOD_E_SPI32:
            create_spi_device_name(boot_device_name, sizeof(boot_device_name), boot_method);
            break;
        default:
            break;
    }

    /* remove this declaration once we find a good header file for this API. */
    extern const char *boot_device_volstr_for_boot_method(int boot_method);
    const char *boot_volume_id = boot_device_volstr_for_boot_method(boot_method);
    if (!boot_volume_id)
    {
        bdk_error("No valid boot volume id found for boot method (%d)\n", boot_method);
    }

    printf(
        "=========================\n"
        "Cavium THUNDERX BDK image\n"
        "=========================\n"
        "BDK version: %s\n"
        "\n",
        bdk_version_string());

    /* Poke the watchdog */
    watchdog_poke();

    if (MULTI_NODE)
    {
        BDK_TRACE(BOOT_STUB, "Initializing CCPI links\n");
        if (__bdk_init_ccpi_links(0))
        {
            printf("CCPI: Link timeout\n");
            /* Reset on failure if we're using the watchdog */
            if (WATCHDOG_TIMEOUT)
                reset_or_power_cycle();
        }
    }

    /* Initialize DRAM on the master node */
#ifdef DRAM_NODE0
    if (DRAM_VERBOSE)
        setenv("ddr_verbose", CONFIG_STR_NAME(DRAM_VERBOSE), 1);
    BDK_TRACE(BOOT_STUB, "Initializing DRAM on this node\n");
    extern const dram_config_t* CONFIG_FUNC_NAME(DRAM_NODE0)(void);
    int mbytes = libdram_config(bdk_numa_master(), CONFIG_FUNC_NAME(DRAM_NODE0)(), 0);
    if (mbytes > 0)
    {
        uint32_t freq = libdram_get_freq(bdk_numa_master());
        freq = (freq + 500000) / 1000000;
        if (MULTI_NODE)
            printf("Node %d: DRAM: %d MB, %u MHz\n", bdk_numa_master(), mbytes, freq);
        else
            printf("DRAM:  %d MB, %u MHz\n", mbytes, freq);
    }
    else
    {
        if (MULTI_NODE)
            bdk_error("Node %d failed DRAM init\n", bdk_numa_master());
        else
            bdk_error("Failed DRAM init\n");
        /* Reset on failure if we're using the watchdog */
        if (WATCHDOG_TIMEOUT)
            reset_or_power_cycle();
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Unlock L2 now that DRAM works */
    if (mbytes > 0)
    {
        uint64_t l2_size = bdk_l2c_get_cache_size_bytes(node);
        BDK_TRACE(BOOT_STUB, "Unlocking L2\n");
        bdk_l2c_unlock_mem_region(node, 0, l2_size);
        /* Poke the watchdog */
        watchdog_poke();
    }
#endif

    /* Send status to the BMC: Master DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE);

    /* Setup CCPI such that both nodes can communicate */
    if (MULTI_NODE)
    {
        BDK_TRACE(BOOT_STUB, "Initializing CCPI\n");
        bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 1);
        bdk_init_nodes(1, 0);
        /* Reset if CCPI failed */
        if (bdk_numa_is_only_one() && WATCHDOG_TIMEOUT)
            reset_or_power_cycle();
        /* Poke the watchdog */
        watchdog_poke();
    }

    /* Send status to the BMC: Multi-node setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_CCPI_COMPLETE);

    /* Initialize DRAM on the slave node */
#ifdef DRAM_NODE1
    if (MULTI_NODE)
    {
        bdk_node_t other_node = 1;
        if (bdk_numa_exists(other_node))
        {
            print_node_strapping(other_node);
            BDK_TRACE(BOOT_STUB, "Initializing DRAM on other node\n");
            extern const dram_config_t* CONFIG_FUNC_NAME(DRAM_NODE1)(void);
            int mbytes = libdram_config(other_node, CONFIG_FUNC_NAME(DRAM_NODE1)(), 0);
            if (mbytes > 0)
            {
                uint32_t freq = libdram_get_freq(other_node);
                freq = (freq + 500000) / 1000000;
                printf("Node %d: DRAM: %d MB, %u MHz\n", other_node, mbytes, freq);
                if (RUN_DRAM_TEST)
                {
                    /* Wake up one core on the other node */
                    bdk_init_cores(other_node, 1);
                    /* Run the address test to make sure DRAM works */
                    if (bdk_dram_test(13, 0, 0x10000000000ull))
                        bdk_reset_chip(node);
                    /* Put other node core back in reset */
                    BDK_CSR_WRITE(other_node, BDK_RST_PP_RESET, -1);
                    uint64_t skip = bdk_dram_get_top_of_bdk();
                    bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(node, skip)),
                        ((uint64_t)mbytes << 20) - skip);
                    bdk_zero_memory(bdk_phys_to_ptr(bdk_numa_get_address(other_node, 0)), (uint64_t)mbytes << 20);
                }
            }
            else
            {
                bdk_error("Node %d failed DRAM init\n", other_node);
                /* Reset on failure if we're using the watchdog */
                if (WATCHDOG_TIMEOUT)
                    reset_or_power_cycle();
            }
        }
        else
        {
            printf("Node %d: Not found, skipping DRAM init\n", other_node);
            /* Reset on failure if we're using the watchdog */
            if (WATCHDOG_TIMEOUT)
                reset_or_power_cycle();
        }
        /* Poke the watchdog */
        watchdog_poke();
    }
#endif

    /* Send status to the BMC: Slave DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE);

    /* Setup reference clocks */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            BDK_TRACE(BOOT_STUB, "Initializing QLM clocks on Node %d\n", n);
            for (int qlm = 0; qlm < BDK_QLM_MAX; qlm++)
            {
                /* Node 0:
                    QLM0-1: External ref clock (156.25Mhz)
                    QLM2-7: Common clock 0 (100Mhz)
                   Node 1:
                    QLM0: External ref clock (156.25Mhz)
                    QLM1-2: Disabled, use external
                    QLM3: External ref clock (100Mhz)
                    QLM4-7: Disabled, use external */
                bdk_qlm_clock_t clk = bdk_brd_cfg_get_int(BDK_BRD_CFG_QLM_CLK, n, qlm);
                if (clk == BDK_QLM_CLK_SKIP)
                    continue;

                if (clk >= BDK_QLM_CLK_MAX)
                {
                    bdk_warn("Invalid clock source %d for QLM%d on node %d. Not configuring.\n",
                             clk, qlm, n);
                    continue;
                }

                if (0 != bdk_qlm_set_clock(n, qlm, clk))
                {
                    bdk_error("Error setting clock source %d for QLM%d on node %d. Ignoring.\n",
                              clk, qlm, n);
                }
            }
        }
    }

    int timestamp = bdk_mdio_45_read(node, 1, 1, 0, 0xa);
    int is_sgmii = (timestamp == 0x1722);
    printf("Configuring networking for %s\n",
        (is_sgmii) ? "1 Gbit" : "10 Gbit");

    /* Initialize the QLMs */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            BDK_TRACE(BOOT_STUB, "Initializing QLMs on Node %d\n", n);
            for (int qlm = 0; qlm < BDK_QLM_MAX; qlm++)
            {
                const char *cfg_val;

                cfg_val   = bdk_brd_cfg_get_str(BDK_BRD_CFG_QLM_MODE, n, qlm);
                int mode  = bdk_qlm_cfg_string_to_mode(cfg_val);
                if (-1 == mode)
                {
                    bdk_error("Invalid QLM mode string '%s' for QLM%d on node %d. "
                                "Not configuring.\n", cfg_val, qlm, n);
                    continue;
                }
                int freq  = bdk_brd_cfg_get_int(BDK_BRD_CFG_QLM_FREQ, n, qlm);

                /* Only configure QLMs with defined modes. */
                if (mode != BDK_QLM_MODE_SKIP)
                    bdk_qlm_set_mode(n, qlm, mode, freq, 0);
            }
        }
    }

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

    /* Initialize BGX, ready for driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* Ports 1-3 of BGX 0 aren't used. Use BGXX_CMRX_RX_DMAC_CTL
               to signal this to following software */
            for (int p = 1; p < 4; p++)
                BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(0, p), 0);
        }
    }

    /* Send status to the BMC: QLM setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_QLM_COMPLETE);

    /* Initialize SATA, ready for standard AHCI driver */
    /* This has already been done by bdk_qlm_set_mode() */

    /* Initialize USB, ready for standard XHCI driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* GPIO 38 controls USB power */
            bdk_gpio_initialize(n, 38, 1, 1);

            for (int p = 0; p < 2; p++)
            {
                BDK_TRACE(BOOT_STUB, "Initializing USB%d on Node %d\n", p, n);
                bdk_usb_intialize(n, p, 0);
            }
        }
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Initialize PCIe and bring up the link */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < bdk_pcie_get_num_ports(n); p++)
            {
                /* Only init PCIe that are attached to QLMs */
                if (bdk_qlm_get(n, BDK_IF_PCIE, p) != -1)
                {
                    BDK_TRACE(BOOT_STUB, "Initializing PCIe%d on Node %d\n", p, n);
                    bdk_pcie_rc_initialize(n, p);
                }
            }
        }
    }

    /* Select ATF or diagnostics image */
    int use_atf = 1;
    /* A GPIO can be used to select diagnostics without input */
    if (DIAGS_GPIO_VALUE != -1)
    {
        int gpio = bdk_gpio_read(bdk_numa_master()) >> DIAGS_GPIO;
        gpio &= 1;
        if (gpio == DIAGS_GPIO_VALUE)
        {
            printf("\nStarting diagnostics based on GPIO%d\n", DIAGS_GPIO);
            use_atf = 0;
        }
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Check for 'D' override */
    if (use_atf && (DIAGS_TIMEOUT > 0))
    {
        printf("\nPress 'D' within %d seconds to boot diagnostics\n", DIAGS_TIMEOUT);
        int key = bdk_readline_getkey(DIAGS_TIMEOUT * 1000000);
        use_atf = !((key == 'd') || (key == 'D'));
    }

    /* Poke the watchdog */
    watchdog_poke();

    /* Initialize the filesystems be need to load code from SPI */
    extern int bdk_fs_mpi_init(void);
    bdk_fs_mpi_init();

    /* Send status to the BMC: Loading ATF */
    if (use_atf)
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_ATF);
    else
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS);

    /* Load the next image */
    /* Transfer control to next image */
    char filename[64];
    if (use_atf)
    {
        BDK_TRACE(BOOT_STUB, "Looking for ATF image\n");
        boot_image_raw(boot_device_name, ATF_ADDRESS);
        bdk_error("Unable to load image\n");
        printf("Trying diagnostics\n");
    }
    BDK_TRACE(BOOT_STUB, "Looking for Diagnostics image\n");
    snprintf(filename, sizeof(filename), "/fatfs/%s:/stage2.bin", boot_volume_id);
    boot_image(filename);

    bdk_error("Image load failed\n");
}


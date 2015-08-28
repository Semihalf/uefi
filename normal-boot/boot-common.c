#include <bdk.h>
#include <malloc.h>

#include "boot-common.h"

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
#endif


/*
 * Configuration variables read from the board config file.
 */
static int BMC_TWSI     = -1;
static int MULTI_NODE   = 2; /* 'auto' is default */
static int DRAM_VERBOSE = 0;
static int WATCHDOG_TIMEOUT = 0;
static const char *DRAM_NODE0 = NULL;
static const char *DRAM_NODE1 = NULL;

static int BRD_DISABLE_TWSI  = 0;
static int BRD_DISABLE_DRAM  = 0;
static int BRD_DISABLE_CCPI  = 0;
static int BRD_DISABLE_QLM   = 0;
static int BRD_DISABLE_BGX   = 0;
static int BRD_DISABLE_USB   = 0;
static int BRD_DISABLE_PCI   = 0;

void boot_read_config()
{
    MULTI_NODE        = bdk_brd_cfg_get_int(MULTI_NODE,         BDK_BRD_CFG_MULTI_NODE);
    BMC_TWSI          = bdk_brd_cfg_get_int(BMC_TWSI,           BDK_BRD_CFG_BMC_TWSI);
    DRAM_VERBOSE      = bdk_brd_cfg_get_int(DRAM_VERBOSE,       BDK_BRD_CFG_DRAM_VERBOSE);
    WATCHDOG_TIMEOUT  = bdk_brd_cfg_get_int(WATCHDOG_TIMEOUT,   BDK_BRD_CFG_WATCHDOG_TIMEOUT);
    DRAM_NODE0        = bdk_brd_cfg_get_str(DRAM_NODE0,         BDK_BRD_CFG_DRAM_NODE, 0);
    DRAM_NODE1        = bdk_brd_cfg_get_str(DRAM_NODE1,         BDK_BRD_CFG_DRAM_NODE, 1);

    BRD_DISABLE_TWSI  = bdk_brd_cfg_get_int(BRD_DISABLE_TWSI,   BDK_BRD_CFG_DISABLE_TWSI);
    BRD_DISABLE_DRAM  = bdk_brd_cfg_get_int(BRD_DISABLE_DRAM,   BDK_BRD_CFG_DISABLE_DRAM);
    BRD_DISABLE_CCPI  = bdk_brd_cfg_get_int(BRD_DISABLE_CCPI,   BDK_BRD_CFG_DISABLE_CCPI);
    BRD_DISABLE_QLM   = bdk_brd_cfg_get_int(BRD_DISABLE_QLM,    BDK_BRD_CFG_DISABLE_QLM);
    BRD_DISABLE_BGX   = bdk_brd_cfg_get_int(BRD_DISABLE_BGX,    BDK_BRD_CFG_DISABLE_BGX);
    BRD_DISABLE_USB   = bdk_brd_cfg_get_int(BRD_DISABLE_USB,    BDK_BRD_CFG_DISABLE_USB);
    BRD_DISABLE_PCI   = bdk_brd_cfg_get_int(BRD_DISABLE_PCI,    BDK_BRD_CFG_DISABLE_PCI);
}

#define XCONFIG_STR_NAME(n)	#n
#define CONFIG_STR_NAME(n) XCONFIG_STR_NAME(n)

/* Perform a fast DRAM test before booting, rebooting or pwoer cycling on
   failure. Only useful if WATCHDOG_TIMEOUT */
#define RUN_DRAM_TEST (WATCHDOG_TIMEOUT != 0)

/**
 * report boot status to the bmc
 *
 * @param status status to report
 */
void print_node_strapping(bdk_node_t node)
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
    bdk_node_t node = bdk_numa_local();
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

const char *boot_device_name_for_boot_method(int boot_method)
{
    bdk_node_t node = bdk_numa_local();
    static char boot_device_name[48] = { 0 };

    switch (boot_method)
    {
        case BDK_RST_BOOT_METHOD_E_EMMC_LS:
        case BDK_RST_BOOT_METHOD_E_EMMC_SS:
            sprintf(boot_device_name, "/dev/n%d.mmc0", node);
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

void update_bmc_status(bmc_status_t status)
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

void reset_or_power_cycle(void)
{
    if (USE_POWER_CYCLE)
        update_bmc_status(BMC_STATUS_REQUEST_POWER_CYCLE);
    else
        bdk_reset_chip(bdk_numa_local());
}

/**
 * Boot an image from a device file at the specified location
 *
 * @param filename      Filename of image to load
 * @param loc           Address offset for image (for raw flash load)
 */
void boot_image(const char *filename, uint64_t loc)
{
    void *image = NULL;

    FILE *inf = fopen(filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", filename);
        return;
    }

    if (loc)
    {
        /* raw flash case */
        printf("    Loading image at 0x%lx\n", loc);
        fseek(inf, loc, SEEK_SET);
    }
    else
        /* FATFS case */
        printf("    Loading image file '%s'\n", filename);

    bdk_image_header_t header;
    int status = bdk_image_read_header(inf, &header);
    if (status != 0)
    {
        bdk_error("Image header is corrupt\n");
        goto out;
    }

    /* Must be 4KB alight for ADRP to work */
    image = memalign(4096, header.length);
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

    BDK_TRACE(BOOT_STUB, "Putting all cores except this one in reset\n");
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;

    /* Send status to the BMC: Boot stub complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_COMPLETE);

    if (WATCHDOG_TIMEOUT)
    {
        int loading_atf = 0;

        if (loc == 0)
        {
            if (strstr(filename, BOOTSTRAP_IMAGE_FILENAME)) /* FATFS case */
                loading_atf = 1;
        }
        else
        {
            if (loc == ATF_ADDRESS) /* raw flash case */
                loading_atf = 1;
        }

        /* Check if we are loading the ATF image. */
        if (loading_atf)
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
    if (!bdk_is_platform(BDK_PLATFORM_EMULATOR))
        BDK_CSR_WRITE(bdk_numa_local(), BDK_GSERX_SCRATCH(0), 0);

    /* This string is passed to the image as a default environment. It is
       series of NAME=VALUE pairs separated by '\0'. The end is marked with
       two '\0' in a row. */
    static char image_env[64] = { 0 };
    const char  *board = bdk_brd_cfg_get_str("not-defined", BDK_BRD_CFG_BOARD);
    snprintf(image_env, sizeof(image_env), "BOARD=%s", board ? board : "none");

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

/*
 * Device initialization functions.
 */
void boot_init_twsi()
{
    if (BRD_DISABLE_TWSI)
        return;

    bdk_node_t node = bdk_numa_local();

    if (BMC_TWSI != -1)
    {
        BDK_TRACE(BOOT_STUB, "Initializing TWSI%d as a slave\n", BMC_TWSI);
        BDK_CSR_DEFINE(sw_twsi, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI));
        sw_twsi.u = 0;
        sw_twsi.s.slonly = 1; /* Slave only */
        BDK_CSR_WRITE(node, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI), sw_twsi.u);
    }
}

void boot_init_dram(bdk_node_t node)
{
    if (BRD_DISABLE_DRAM)
        return;

    if (DRAM_NODE0 && (node == BDK_NODE_0))
    {
        int ddrmhz=0;
        /* Initialize DRAM on the master node */
        if (DRAM_VERBOSE)
        {
            char buf[8];
            snprintf(buf, sizeof(buf), "%d", DRAM_VERBOSE);
            setenv("ddr_verbose", buf, 1);
        }
        BDK_TRACE(BOOT_STUB, "Initializing DRAM on this node\n");
        if (MFG_SYSTEM_LEVEL_TEST)
        {
            const char *input;
            input = bdk_readline("DDR Clock in MHz:", NULL, 0);
            ddrmhz = atoi(input);
        }
        int mbytes = bdk_dram_config(bdk_numa_master(), DRAM_NODE0, ddrmhz*1000000);
        if (mbytes > 0)
        {
            uint32_t freq = libdram_get_freq(bdk_numa_master());
            freq = (freq + 500000) / 1000000;
            if (MULTI_NODE)
                printf("Node %d: DRAM: %d MB, %u MHz\n", bdk_numa_master(), mbytes, freq);
            else
                printf("DRAM: %d MB, %u MHz\n", mbytes, freq);
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
    }

    /* Initialize DRAM on the slave node */
    if (DRAM_NODE1 && (node == BDK_NODE_1) && MULTI_NODE)
    {
        bdk_node_t other_node = 1;
        if (bdk_numa_exists(other_node))
        {
            print_node_strapping(other_node);
            BDK_TRACE(BOOT_STUB, "Initializing DRAM on other node\n");
            int mbytes = bdk_dram_config(other_node, DRAM_NODE1, 0);
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
                        reset_or_power_cycle();
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
}

void boot_init_ccpi_link()
{
    if (BRD_DISABLE_CCPI || !MULTI_NODE)
        return;

    BDK_TRACE(BOOT_STUB, "Initializing CCPI links\n");
    if (__bdk_init_ccpi_links(0))
    {
        if (1 == MULTI_NODE) /* fail case for 'on' setting */
        {
            printf("CCPI: Link timeout\n");
            /* Reset on failure if we're using the watchdog */
            if (WATCHDOG_TIMEOUT)
                reset_or_power_cycle();
        }
        else /* fail case for 'auto' setting */
        {
            BDK_TRACE(BOOT_STUB, "Auto configured 1 node.\n");
            MULTI_NODE = 0;
        }
    }
    else if (2 == MULTI_NODE) /* success case for 'auto' setting */
        BDK_TRACE(BOOT_STUB, "Auto configured 2 nodes.\n");

    watchdog_poke();
}

void boot_init_ccpi_node()
{
    if (BRD_DISABLE_CCPI || !MULTI_NODE)
        return;

    BDK_TRACE(BOOT_STUB, "Initializing CCPI\n");
    bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 1);
    bdk_init_nodes(1, 0);
    /* Reset if CCPI failed */
    if (bdk_numa_is_only_one() && WATCHDOG_TIMEOUT)
        reset_or_power_cycle();

    watchdog_poke();
}

void boot_init_qlm_clk()
{
    if (BRD_DISABLE_QLM)
        return;

    /* Setup reference clocks */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (!bdk_numa_exists(n))
            continue;

        int num_qlms = bdk_qlm_get_num(n);

        BDK_TRACE(BOOT_STUB, "Initializing QLM clocks on Node %d\n", n);
        for (int qlm = 0; qlm < num_qlms; qlm++)
        {
            bdk_qlm_clock_t clk = bdk_brd_cfg_get_int(BDK_QLM_CLK_LAST, BDK_BRD_CFG_QLM_CLK, n, qlm);
            if (BDK_QLM_CLK_LAST == clk) /* no entry */
                continue;

            if (clk > BDK_QLM_CLK_LAST)
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

void boot_init_qlm_mode()
{
    if (BRD_DISABLE_QLM)
        return;

    /* Check if QLM autoconfig is requested */
    int qlm_auto = bdk_brd_cfg_get_int(0, BDK_BRD_CFG_QLM_MODE_AUTO_CONFIG);
    if (qlm_auto)
    {
        /* Auto configuration of QLMs
         */
        for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
        {
            if (bdk_numa_exists(n))
            {
                BDK_TRACE(BOOT_STUB, "Initializing QLMs on Node %d\n", n);
                bdk_qlm_auto_config(n);
            }
        }
    }
    else
    {
        /* Initialize the QLMs based on configuration file settings
         */
        for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
        {
            if (!bdk_numa_exists(n))
                continue;

            int num_qlms = bdk_qlm_get_num(n);

            BDK_TRACE(BOOT_STUB, "Initializing QLMs on Node %d\n", n);
            for (int qlm = 0; qlm < num_qlms; qlm++)
            {
                const char *cfg_val;

                cfg_val = bdk_brd_cfg_get_str(NULL, BDK_BRD_CFG_QLM_MODE, n, qlm);
                if (!cfg_val)
                    continue;

                int mode = bdk_qlm_cfg_string_to_mode(cfg_val);
                if (-1 == mode)
                {
                    bdk_error("Invalid QLM mode string '%s' for QLM%d on node %d. "
                                "Not configuring.\n", cfg_val, qlm, n);
                    continue;
                }
                int freq = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_QLM_FREQ, n, qlm);
                if (-1 == freq)
                {
                    bdk_error("No frequency setting for QLM%d on node %d. "
                                "Not configuring.\n", qlm, n);
                    continue;
                }

                bdk_qlm_set_mode(n, qlm, mode, freq, 0);
            }
        }
    }
}

void boot_init_bgx()
{
    if (BRD_DISABLE_BGX)
        return;

    /* Initialize BGX, ready for driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            /* Enable ports based on config file. */
            for (int bgx = 0; bgx < 2; bgx++)
            {
                for (int p = 0; p < 4; p++)
                {
                    int en = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_BGX_ENABLE, n, bgx, p);
                    if (-1 != en)
                        BDK_CSR_WRITE(n, BDK_BGXX_CMRX_RX_DMAC_CTL(bgx, p), en);
                }
            }
        }
    }
}

void boot_init_usb()
{
    if (BRD_DISABLE_USB)
        return;

    /* Initialize USB, ready for standard XHCI driver */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < 2; p++)
            {
                BDK_TRACE(BOOT_STUB, "Initializing USB%d on Node %d\n", p, n);
                bdk_usb_intialize(n, p, 0);
            }
        }
    }
}

void boot_init_pci()
{
    if (BRD_DISABLE_PCI)
        return;

    /* Initialize PCIe and bring up the link */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int p = 0; p < bdk_pcie_get_num_ports(n); p++)
            {
                /* Only init PCIe that are attached to QLMs */
                if (bdk_qlm_get(n, BDK_IF_PCIE, p, 0) != -1)
                {
                    BDK_TRACE(BOOT_STUB, "Initializing PCIe%d on Node %d\n", p, n);
                    bdk_pcie_rc_initialize(n, p);
                }
            }
        }
    }
}

void watchdog_set(int timeout)
{
    if (!WATCHDOG_TIMEOUT)
        return; /* Watchdog not configured for this board */

    if (timeout <= 0)
        timeout = WATCHDOG_TIMEOUT;

    BDK_CSR_MODIFY(c, bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()),
        c.s.len = timeout;
        c.s.mode = 3);
}

void watchdog_poke()
{
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);
}

void watchdog_disable()
{
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
}

/* Weakly bound default functions. Can be overwritten by board specific
 * functions in board/$(BOARD_TYPE)/board_init.c
 */
void board_init_early() { }
void board_init_late()  { }

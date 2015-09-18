#include <bdk.h>
#include <malloc.h>

#include "boot-common.h"

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
#endif


/*
 * Configuration variables read from the board config file.
 */
static int MULTI_NODE   = 2; /* 'auto' is default */
static int DRAM_VERBOSE = 0;
static const char *DRAM_NODE0 = NULL;
static const char *DRAM_NODE1 = NULL;

static int BRD_DISABLE_DRAM  = 0;

void boot_read_config()
{
    MULTI_NODE        = bdk_brd_cfg_get_int(MULTI_NODE,         BDK_BRD_CFG_MULTI_NODE);
    DRAM_VERBOSE      = bdk_brd_cfg_get_int(DRAM_VERBOSE,       BDK_BRD_CFG_DRAM_VERBOSE);
    DRAM_NODE0        = bdk_brd_cfg_get_str(DRAM_NODE0,         BDK_BRD_CFG_DRAM_NODE, 0);
    DRAM_NODE1        = bdk_brd_cfg_get_str(DRAM_NODE1,         BDK_BRD_CFG_DRAM_NODE, 1);

    BRD_DISABLE_DRAM  = bdk_brd_cfg_get_int(BRD_DISABLE_DRAM,   BDK_BRD_CFG_DISABLE_DRAM);
}

#define XCONFIG_STR_NAME(n)	#n
#define CONFIG_STR_NAME(n) XCONFIG_STR_NAME(n)

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
            if (bdk_watchdog_is_running())
                bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
        }

        /* Poke the watchdog */
        bdk_watchdog_poke();

        /* Unlock L2 now that DRAM works */
        if (mbytes > 0)
        {
            uint64_t l2_size = bdk_l2c_get_cache_size_bytes(node);
            BDK_TRACE(BOOT_STUB, "Unlocking L2\n");
            bdk_l2c_unlock_mem_region(node, 0, l2_size);
            /* Poke the watchdog */
            bdk_watchdog_poke();
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
                if (bdk_watchdog_is_running())
                {
                    /* Wake up one core on the other node */
                    bdk_init_cores(other_node, 1);
                    /* Run the address test to make sure DRAM works */
                    if (bdk_dram_test(13, 0, 0x10000000000ull))
                        bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
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
                if (bdk_watchdog_is_running())
                    bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
            }
        }
        else
        {
            printf("Node %d: Not found, skipping DRAM init\n", other_node);
            /* Reset on failure if we're using the watchdog */
            if (bdk_watchdog_is_running())
                bdk_boot_status(BDK_BOOT_STATUS_REQUEST_POWER_CYCLE);
        }
        /* Poke the watchdog */
        bdk_watchdog_poke();
    }
}

/* Weakly bound default functions. Can be overwritten by board specific
 * functions in board/$(BOARD_TYPE)/board_init.c
 */
void board_init_early() { }
void board_init_late()  { }

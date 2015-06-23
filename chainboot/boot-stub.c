#include <bdk.h>
#include <malloc.h>

/* Set this to 0 for PCIe on QLMs 6-7. Set it to 1 for SATA when using the
   PCIe to SATA breakout card*/
#define USE_SATA_BREAKOUT_CARD 1
/* Which TWSI interface to use for the BMC, -1 to disable */
#define BMC_TWSI 1
/* Control if we even try and do multi-node (0 or 1) */
#define MULTI_NODE 1
/* On boards using software CCPI init, this is the speed to bringup CCPI at */
#define CCPI_INIT_SPEED 10312
/* Name of DRAM config for master node 0 */
#define DRAM_NODE0 crb_2s_V3
/* Enable verbose logging from DRAM initialization (0 or 1) */
#define DRAM_VERBOSE 0
/* Name of DRAM config for slave node 1 */
#define DRAM_NODE1 crb_2s_V3
/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 8010 /* 3sec at 700Mhz */
/* Control whether the boot stub request power cycles from the BMC (0 ro 1) */
#define USE_POWER_CYCLE 1 /* Currently not requesting power cycles */
/* How long to wait for selection of diagnostics (seconds) */
#define DIAGS_TIMEOUT 3
/* A GPIO can be used to select diagnostics without input. The following
   define controls which GPIO and the value that starts daignostics. Set
   DIAGS_GPIO_VALUE to -1 to disable */
#define DIAGS_GPIO 0
#define DIAGS_GPIO_VALUE -1
/* Address of the diagnostics in flash (512KB is right after boot stubs) */
#define DIAGS_ADDRESS 0x00080000
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00400000
/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_BOOT_STUB 0

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
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(TWSI);
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
 * Boot an image from an image file.
 *
 * @param img_filename
 *               Name of image file to load
 * @param loc    Location offset in the device file
 */
static void boot_image(const char *img_filename, uint64_t loc)
{
    void *image = NULL;

    FILE *inf = fopen(img_filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", img_filename);
        return;
    }

    printf("    Loading image file %s.\n", img_filename);

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

    /* Enable watchdog */
    if (WATCHDOG_TIMEOUT)
    {
        BDK_CSR_MODIFY(c, node, BDK_GTI_CWD_WDOGX(bdk_get_core_num()),
            c.s.len = WATCHDOG_TIMEOUT;
            c.s.mode = 3);
    }

    /* Drive GPIO 10 high, signalling success transferring from the boot ROM */
    BDK_TRACE(BOOT_STUB, "Driving GPIO10 high\n");
    bdk_gpio_initialize(node, 10, 1, 1);

    /* Update the boot counter help in GESR0_SCRATCH */
    uint64_t boot_count = BDK_CSR_READ(node, BDK_GSERX_SCRATCH(0));
    boot_count++;
    BDK_CSR_WRITE(node, BDK_GSERX_SCRATCH(0), boot_count);

    /* Initialize TWSI interface TBD as a slave */
    if (BMC_TWSI != -1)
    {
        BDK_TRACE(BOOT_STUB, "Initializing TWSI%d as a slave\n", BMC_TWSI);
        BDK_CSR_DEFINE(sw_twsi, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI));
        sw_twsi.u = 0;
        sw_twsi.s.slonly = 1; /* Slave only */
        BDK_CSR_WRITE(node, BDK_MIO_TWSX_SW_TWSI(BMC_TWSI), sw_twsi.u);
    }

    if ((boot_count >= 3) && USE_POWER_CYCLE)
        update_bmc_status(BMC_STATUS_REQUEST_POWER_CYCLE);

    /* Send status to the BMC: Started boot stub */
    update_bmc_status(BMC_STATUS_BOOT_STUB_STARTING);

    BDK_TRACE(BOOT_STUB, "Extracting strapping options\n");
    /* Initialize UART was done earlier in the BDK */
    /* Decode how we booted and display a banner */
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    int boot_method;
    char boot_device_name[48];
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);
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

    printf(
        "BDK version: %s\n"
        "Boot Attempt: %lu\n"
        "\n"
        "===========================\n"
        "Cavium THUNDERX Chainloader\n"
        "===========================\n",
        bdk_version_string(), boot_count);
    print_node_strapping(bdk_numa_master());

    /* Poke the watchdog */
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

#if 1
    /* Test code file read() / create() / write(). */

    /* Initialize the FAT filesystems be need to load the next stage */
    extern int bdk_fs_fatfs_init(void);
    bdk_fs_fatfs_init();

    FILE *foo = fopen("/fatfs/info.txt", "rb");
    if (!foo)
    {
        printf("##### file info.txt not found. Creating.\n");
        foo = fopen("/fatfs/info.txt", "wb");
        if (!foo)
        {
            printf("##### ERROR: Could not create info.txt.\n");
        }
        else
        {
            char *text = "If you read this, it works.";
            int n = fwrite(text, strlen(text)+1, 1, foo);
            if (n != 1)
            {
                printf("##### ERROR writing to info.txt.\n");
            }
            fclose(foo);
        }
    }
    else
    {
        printf("##### File info.txt opened OK, fp:%p\n", foo);
        char buf[256];
        int count;
        while (0 != (count = fread(buf, 1, sizeof(buf), foo)))
        {
            printf("##### Read %d bytes: '%s'\n", count, buf);
        }
        fclose(foo);
    }
#endif


    /* Setup CCPI if we're on the second node */
    if (MULTI_NODE && (node != 0))
    {
        BDK_TRACE(BOOT_STUB, "Initializing CCPI\n");
        /* Check if CCPI is in software init mode */
        BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(8));
        if (gserx_spd.s.spd == 0xf)
        {
            printf("Secondary node with CCPI init in software. Starting CCPI\n");
            if (__bdk_init_ccpi_links(CCPI_INIT_SPEED))
                bdk_fatal("CCPI init failed\n");
            extern void __bdk_reset_thread(int arg1, void *arg2);
            __bdk_reset_thread(0, NULL);
        }
        /* Disable watchdog */
        if (WATCHDOG_TIMEOUT)
            BDK_CSR_WRITE(node, BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
        extern void __bdk_reset_thread(int arg1, void *arg2);
        __bdk_reset_thread(0, NULL);
    }

    if (MULTI_NODE)
    {
        BDK_TRACE(BOOT_STUB, "Initializing CCPI links\n");
        if (__bdk_init_ccpi_links(CCPI_INIT_SPEED))
        {
            printf("CCPI: Link timeout\n");
            /* Reset on failure if we're using the watchdog */
            if (WATCHDOG_TIMEOUT)
                reset_or_power_cycle();
        }
    }


    /* Send status to the BMC: Master DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE);

    /* Setup CCPI such that both nodes can communicate */
    if (MULTI_NODE)
    {
        BDK_TRACE(BOOT_STUB, "Initializing CCPI\n");
        bdk_config_set(BDK_CONFIG_ENABLE_MULTINODE, 1);
        bdk_init_nodes(1, CCPI_INIT_SPEED);
        /* Reset if CCPI failed */
        if (bdk_numa_is_only_one())
            reset_or_power_cycle();
        /* Poke the watchdog */
        if (WATCHDOG_TIMEOUT)
            BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);
    }

    /* Send status to the BMC: Multi-node setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_CCPI_COMPLETE);

    /* Send status to the BMC: Slave DRAM init complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE);

    /* Setup reference clocks */
    for (int n = 0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            BDK_TRACE(BOOT_STUB, "Initializing QLM clocks on Node %d\n", n);
            for (int qlm=0; qlm<8; qlm++)
            {
                /* Node 0:
                    QLM0-1: External ref clock (156.25Mhz)
                    QLM2-7: Common clock 0 (100Mhz)
                   Node 1:
                    QLM0: External ref clock (156.25Mhz)
                    QLM1-2: Disabled, use external
                    QLM3: External ref clock (100Mhz)
                    QLM4-7: Disabled, use external */
                int use_common = (n == BDK_NODE_0) && (qlm >= 2);
                BDK_CSR_MODIFY(c, n, BDK_GSERX_REFCLK_SEL(qlm),
                    c.s.com_clk_sel = use_common;
                    c.s.use_com1 = 0);
            }
        }
    }

    /* Send status to the BMC: QLM setup complete */
    update_bmc_status(BMC_STATUS_BOOT_STUB_QLM_COMPLETE);

    /* Initialize SATA, ready for standard AHCI driver */
    /* This has already been done by bdk_qlm_set_mode() */

    /* Poke the watchdog */
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

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
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

    /* Check for 'D' override */
    if (use_atf && (DIAGS_TIMEOUT > 0))
    {
        printf("\nPress 'D' within %d seconds to boot diagnostics\n", DIAGS_TIMEOUT);
        int key = bdk_readline_getkey(DIAGS_TIMEOUT * 1000000);
        use_atf = !((key == 'd') || (key == 'D'));
    }

    /* Poke the watchdog */
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

    /* Send status to the BMC: Loading ATF */
    if (use_atf)
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_ATF);
    else
        update_bmc_status(BMC_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS);

    /* Initialize the FAT filesystems be need to load the next stage */
    extern int bdk_fs_fatfs_init(void);
    bdk_fs_fatfs_init();

    /* Load the next image */
    /* Transfer control to next image */
    if (use_atf)
    {
        BDK_TRACE(BOOT_STUB, "Looking for ATF image\n");
        boot_image(boot_device_name, ATF_ADDRESS);
        bdk_error("Unable to load image\n");
        printf("Trying diagnostics\n");
    }
    BDK_TRACE(BOOT_STUB, "Looking for Diagnostics image\n");
    boot_image("/fatfs/stages/stage2.bin", DIAGS_ADDRESS);

    bdk_error("Image load failed\n");
}


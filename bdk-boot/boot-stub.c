#include <bdk.h>
#include <malloc.h>

/* The boot-stub has a hard size limit of 192KB. To reduce size,
   this define can enable / disable support for DRAM init and testing
   in the boot stub. If you need this, make sure only the DRAM configs
   required are defined in DBDK_DRAM_CONFIG*. If you have too many,
   the boot stub will be too big */
#ifndef ENABLE_DRAM_MENU
#define ENABLE_DRAM_MENU 0
#endif

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(FS_XMODEM);
}

static int volatile write_needed = 0;
static char write_buffer[1024];
static int volatile write_count = 0;
static bdk_spinlock_t write_lock;

/**
 * The actual writing to flash is done in a separate thread so Xmodem doesn't
 * stall during slow erase cycles.
 *
 * @author creese (10/10/2013)
 * @param unused Unused param
 * @param handle File handle for writing
 */
static void write_thread(int unused, void *handle)
{
    FILE *outf = (FILE*)handle;
    while (write_needed || write_count)
    {
        /* Wait for data */
        if (!write_count)
        {
            bdk_thread_yield();
            continue;
        }
        bdk_spinlock_lock(&write_lock);
        /* Write the data */
        int w_count = fwrite(write_buffer, 1, write_count, outf);
        fflush(outf);
        if (w_count != write_count)
        {
            bdk_error("Write error\n");
            bdk_spinlock_unlock(&write_lock);
            break;
        }
        /* Tell the reader the buffer is empty */
        write_count = 0;
        bdk_spinlock_unlock(&write_lock);
    }
    fclose(outf);
}

/**
 * Receive a file through Xmodem and write it to an internal file representing
 * a flash device.
 *
 * @author creese (10/10/2013)
 * @param dest_file File to write to
 */
static void do_upload(const char *dest_file)
{
    /* Open the output file */
    FILE *outf = fopen(dest_file, "w");
    if (!outf)
    {
        bdk_error("Failed to open %s\n", dest_file);
        return;
    }

    /* Create a thread that does the write so Xmodem doesn't stall
       during slow flash accesses */
    write_count = 0;
    write_needed = 1;
    BDK_WMB;
    bdk_thread_create(bdk_numa_local(), 0, write_thread, 0, (void*)outf, 0);
    /* Let the thread start */
    bdk_thread_yield();

    /* Open xmodem for reading the file */
    FILE *inf = fopen("/xmodem", "r");
    if (!inf)
    {
        bdk_error("Failed to open /xmodem\n");
        BDK_WMB;
        write_needed = 0;
        BDK_WMB;
        return;
    }

    /* Loop until the file is done */
    while (!feof(inf))
    {
        char buffer[sizeof(write_buffer)];
        /* Read a block */
        int count = fread(buffer, 1, sizeof(buffer), inf);
        if (count > 0)
        {
            /* Wait for the write buffer to be empty */
            while (write_count)
                bdk_thread_yield();
            /* Put the data in the write buffer */
            bdk_spinlock_lock(&write_lock);
            memcpy(write_buffer, buffer, count);
            BDK_WMB;
            write_count = count;
            bdk_spinlock_unlock(&write_lock);
        }
    }
    fclose(inf);
    printf("\nXmodem complete\n");
    /* Wait for the write thread to finish */
    BDK_WMB;
    write_needed = 0;
    BDK_WMB;
    while (write_count)
        bdk_thread_yield();
}

/**
 * Search the given device file (SPI or eMMC) and return a list of BDK images
 * available. The iamges will also be displayed on the console.
 *
 * @param path
 *                   Device file to search
 * @param max_images Max number of images to return
 * @param image_names
 *                   List of image names
 *
 * @return Number of images found
 */
static int list_images(const char *path, int max_images, char *image_names[])
{
    int num_images = 0;
    DIR dp;

    printf("\nLooking for images in %s\n\n", path);
    FRESULT res = f_opendir(&dp, path);
    if (res)
    {
        bdk_warn("Target directory %s does not exist (res:%d). Aborting.\n", path, res);
        return 0;
    }

    FILINFO info;
#if _USE_LFN
    char lfn[_MAX_LFN + 1] = {0};
    info.lfname = lfn;
    info.lfsize = sizeof(lfn);
#endif
    res = f_findfirst(&dp, &info, path, "*.bin");
    while (FR_OK == res && info.fname[0] && num_images < max_images)
    {
        char fullpath[_MAX_LFN + 1];
        char *dirstr = info.fattrib & AM_DIR ? "/" : "";
        char *pd = path[strlen(path)-1] == '/' ? "" : "/";
#if _USE_LFN
        /* Note:
         * We have to add the "/fatfs/" prefix as WE are working directly on
         * the FATFS API while the calling code works on libc file operation
         * API.
         *
         * Also, the strdup() below will leak mem. We don't really care...
         */
        if (info.lfname[0])
            snprintf(fullpath, sizeof(fullpath), "/fatfs/%s%s%s%s", path, pd, info.lfname, dirstr);
        else
            snprintf(fullpath, sizeof(fullpath), "/fatfs/%s%s%s%s", path, pd, info.fname, dirstr);
#else
        snprintf(fullpath, sizeof(fullpath), "/fatfs/%s%s%s%s", path, pd, info.fname, dirstr);
#endif

        bdk_image_header_t header;
        FILE *fp = fopen(fullpath, "rb");
        if (fp)
        {
            fseek(fp, 0, SEEK_SET);
            int status = bdk_image_read_header(fp, &header);
            if (status == 0)
            {
                printf("  %d) %s: %s, version %s, %u bytes\n",
                    num_images+1, fullpath, header.name, header.version, header.length);
                image_names[num_images] = strdup(fullpath);
                num_images++;
            }
            fclose(fp);
        }
        res = f_findnext(&dp, &info);
    }

    f_closedir(&dp);
    return num_images;
}

/**
 * Boot an image from a device file at the specified location
 *
 * @param path
 *               Device file to read image from
 */
static void boot_image(const char *path)
{
    void *image = NULL;

    FILE *inf = fopen(path, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", path);
        return;
    }

    printf("    Loading image %s\n", path);

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

    printf("    Putting all cores except this one in reset\n");
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;
    if (bdk_jump_address(bdk_ptr_to_phys(image), 0))
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
 * Display a list of images the user can boot from a device file and let
 * them choose oen to boot.
 *
 * @param path
 *               Device file to search
 */
static void choose_image(const char *path)
{
    const int MAX_IMAGES = 20;
    char *image_names[MAX_IMAGES];
    int num_images = list_images(path, MAX_IMAGES, image_names);

    if (num_images == 0)
    {
        printf("No images found\n");
        return;
    }

    /* If DRAM is enabled, unlock the L2 cache for use by later
     * applications.  Note this only handles the local node.
     */
    if (__bdk_is_dram_enabled(bdk_numa_local()))
    {
        BDK_TRACE(INIT, "Unlocking L2 before loading image with DRAM enabled.\n");
        uint64_t l2_size = bdk_l2c_get_cache_size_bytes(bdk_numa_local());
        bdk_l2c_unlock_mem_region(bdk_numa_local(), 0, l2_size);
    }
    int use_image = 0;
    if (num_images > 1)
    {
        const char *input = bdk_readline("Image to load: ", NULL, 0);
        use_image = atoi(input);
        if ((use_image < 1) || (use_image > num_images))
        {
            printf("Not a valid image number\n");
            return;
        }
        use_image--;
    }
    else
        printf("One image found, automatically loading\n");
    boot_image(image_names[use_image]);
}

#if ENABLE_DRAM_MENU

/**
 * Display a menu of DRAM options
 */
static void dram_menu()
{
    const int MAX_DRAM_CONFIGS = 4;
    int num_dram_configs = 0;
    const char *dram_config[MAX_DRAM_CONFIGS];
    int ddr_hz = 0;

    /* Create a list of all DRAM configs */
    for (int c = 0; c < MAX_DRAM_CONFIGS; c++)
    {
        dram_config[c] = bdk_dram_get_config_name(c);
        if (dram_config[c] == NULL)
            break;
        num_dram_configs++;
    }

    while (1)
    {
        printf("\n"
            "DRAM Menu\n"
            "=========\n");
        for (int c = 0; c < num_dram_configs; c++)
        {
            printf(" %d) Initialize DRAM using config \"%s\"\n", c + 1, dram_config[c]);
        }
        printf(" %d) Configure DRAM clock\n", num_dram_configs + 1);
        printf(" %d) Main menu\n", num_dram_configs + 2);

        const char *input = bdk_readline("Menu choice: ", NULL, 0);
        int option = atoi(input);

        if ((option >= 1) && (option <= num_dram_configs))
        {
            /* Configure DRAM */
            int mbytes = bdk_dram_config(bdk_numa_local(), dram_config[option - 1], ddr_hz);
            if (mbytes <= 0)
                bdk_error("DRAM initialization failed\n");
        }
        else if (option == num_dram_configs + 1)
        {
            /* Configure DRAM clock frequency */
            input = bdk_readline("DRAM clock Hz: ", NULL, 0);
            ddr_hz = atoi(input);
        }
        else if (option == num_dram_configs + 2)
        {
            /* Exit menu */
            return;
        }
        else
        {
            bdk_error("Illegal selection\n");
        }
    }
}

#endif

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();

    bdk_ap_midr_el1_t midr_el1;
    midr_el1.u = cavium_get_model();
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
    int boot_method;
    int vrm_disable;
    int trust_mode;
    const char *boot_method_str;
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);
    BDK_EXTRACT(vrm_disable, gpio_strap.u, 9, 1);
    BDK_EXTRACT(trust_mode, gpio_strap.u, 10, 1);
    BDK_CSR_DEFINE(ocx_com_node, BDK_OCX_COM_NODE);
    ocx_com_node.u = 0;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        ocx_com_node.u = BDK_CSR_READ(node, BDK_OCX_COM_NODE);

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
        "BDK version: %s\n"
        "\n"
        "===============\n"
        "BDK Stage1 Boot\n"
        "===============\n",
        bdk_version_string());
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        printf("Node:  %d%s\n", node, (ocx_com_node.s.fixed_pin) ? " (Fixed)" : "");
    printf(
        "Chip:  0x%x Pass %d.%d%s\n"
        "L2:    %d KB\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        midr_el1.s.partnum, major_pass, minor_pass, package_str,
        bdk_l2c_get_cache_size_bytes(node) >> 10,
        bdk_clock_get_rate(node, BDK_CLOCK_RCLK) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");

    while (1)
    {
        printf(
            "\n"
            "Boot Menu\n"
            "=========\n"
            " 1) Change baud rate and flow control\n"
            " 2) Load image from MMC, eMMC, or SD\n"
            " 3) Load image from SPI\n"
            " 4) Write image to MMC, eMMC, or SD using Xmodem\n"
            " 5) Write image to SPI EEPROM or NOR using Xmodem\n"
#if ENABLE_DRAM_MENU
            " 6) DRAM options\n"
            " 7) Soft reset chip\n");
#else
            " 6) Soft reset chip\n");
#endif
        const char *input;
        if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
            input = "2"; /* Skip menu on the emulator */
        else
            input = bdk_readline("Menu choice: ", NULL, 0);
        int option = atoi(input);
        switch (option)
        {
            case 1: /* Change baud rate */
            {
                const char *baud = bdk_readline("Baudrate: ", NULL, 0);
                const char *flow = bdk_readline("Use hardware flow control [y/n]: ", NULL, 0);
                int baudrate = atoi(baud);
                if ((baudrate < 9600) || (baudrate > 4000000))
                {
                    bdk_error("Illegal baudrate\n");
                    break;
                }
                int use_flow = !(*flow == 'n');
                printf("Changing baudrate to %d\n", baudrate);
                fflush(NULL);
                bdk_wait_usec(500000);
                bdk_set_baudrate(node, 0, baudrate, use_flow);
                printf("Baudrate is now %d\n", baudrate);
                break;
            }
            case 2: /* eMMC / SD */
            {
                /* no need for '/fatfs/' prefix. choose_image() uses raw FATFS
                 * API. */
                choose_image("MMC0:");
                break;
            }
            case 3: /* SPI */
            {
                /* no need for '/fatfs/' prefix. choose_image() uses raw FATFS
                 * API. */
                choose_image("SPI0:");
                break;
            }
            case 4: /* eMMC / SD upload */
            case 5: /* SPI upload */
            {
                const char *filename = bdk_readline("Filename: ", NULL, 0);
                if (!filename || 0 == strlen(filename))
                {
                    bdk_error("Illegal filename\n");
                    break;
                }

                printf("\n");

                char name[_MAX_LFN +1];
                char *vol = option == 5 ? "SPI0:" : "MMC0:";
                snprintf(name, sizeof(name), "/fatfs/%s/%s", vol, filename);
                do_upload(name);
                break;
            }
#if ENABLE_DRAM_MENU
            case 6: /* DRAM options */
                dram_menu();
                break;
            case 7: /* Soft reset */
#else
            case 6: /* Soft reset */
#endif
                printf("Performing a soft reset\n");
                bdk_reset_chip(node);
                break;
            default:
                bdk_error("Illegal input\n");
                break;
        }
    }
}

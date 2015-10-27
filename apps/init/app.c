#include <bdk.h>
#include <malloc.h>

/* Enable or disable detailed tracing of the boot stub (0 or 1) */
#define BDK_TRACE_ENABLE_BOOT_STUB 0

/* Address of the diagnostics in flash (512KB is right after boot stubs) */
#define DIAGS_ADDRESS 0x00080000
/* Address of ATF in flash */
#define ATF_ADDRESS 0x00400000

#ifndef MFG_SYSTEM_LEVEL_TEST
#define MFG_SYSTEM_LEVEL_TEST 0
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
    BDK_REQUIRE(CCPI);
    BDK_REQUIRE(ERROR_DECODE);
    BDK_REQUIRE(FS_BOOT);
    BDK_REQUIRE(FS_FATFS);
    BDK_REQUIRE(FS_MMC);
    BDK_REQUIRE(FS_MPI);
    BDK_REQUIRE(QLM);
    BDK_REQUIRE(MDIO);
    BDK_REQUIRE(PCIE);
    BDK_REQUIRE(GPIO);
    BDK_REQUIRE(RNM);
    BDK_REQUIRE(KEY_MEMORY);
    BDK_REQUIRE(MPI);
    BDK_REQUIRE(DRAM_CONFIG);
    BDK_REQUIRE(TWSI);
    BDK_REQUIRE(USB);
    BDK_REQUIRE(ECAM);
    BDK_REQUIRE(DRIVER);

    BDK_REQUIRE(DRIVER_SMMU);
}

extern const char *boot_device_volstr_for_boot_method(int boot_method);

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
    bdk_image_boot(image_names[use_image], 0, 0);
}

static void usb_bist(int node, int cnt, int clear_bist)
{
    BDK_CSR_INIT(uctl, node, BDK_USBHX_UCTL_CTL(cnt));
	if (clear_bist) {
        uctl.s.clear_bist = 1;
	}
	else {
        uctl.s.clear_bist = 0;
	}
    BDK_CSR_WRITE(node, BDK_USBHX_UCTL_CTL(cnt), uctl.u);

    uctl.u = BDK_CSR_READ(node, BDK_USBHX_UCTL_CTL(cnt));
    uctl.s.start_bist = 1;
    uctl.s.uphy_rst = 1;
    uctl.s.uahc_rst = 1;
    uctl.s.uctl_rst = 1;
    BDK_CSR_WRITE(node, BDK_USBHX_UCTL_CTL(cnt), uctl.u);

	bdk_wait_usec(10000); //Wait 10 ms
    BDK_CSR_INIT(bist_status, node, BDK_USBHX_UCTL_BIST_STATUS(cnt));
    if (bist_status.u)
    {
        printf("BIST FAILURE in USB%d clear_bist = %d\n BIST_STATUS %lx\n", cnt, clear_bist, bist_status.u);
    }
    else
    {
        printf("BIST CHECK OK in USB%d clear_bist = %d\n", cnt, clear_bist);
    }
    uctl.u = BDK_CSR_READ(node, BDK_USBHX_UCTL_CTL(cnt));
	if (clear_bist) {
        uctl.s.clear_bist = 0;
	}
    uctl.s.start_bist = 0;
    uctl.s.uphy_rst = 1;
    uctl.s.uahc_rst = 1;
    uctl.s.uctl_rst = 1;
    BDK_CSR_WRITE(node, BDK_USBHX_UCTL_CTL(cnt), uctl.u);
}

static void usb_3_disable(int node, int port)
{
    BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(port), c.s.uphy_rst = 1);
    bdk_wait_usec(10000);
    BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(port), c.s.usb3_port_disable = 1);
    bdk_wait_usec(10000);
    BDK_CSR_MODIFY(c, node, BDK_USBHX_UCTL_CTL(port), c.s.uphy_rst = 0);
}

static void slt_boot_image(bdk_node_t node)
{
    while(1)
    {
        printf(
                "\n"
                "Boot Menu\n"
                "=========\n"
                " 1) Load image from boot device\n"
                " 2) Load ATF image from boot device\n"
                " 3) BIST Check\n"
                " 4) Do USB BIST check\n"
                " 5) Disable USB-3.0 PHY\n");
        const char *input;
        input = bdk_readline("Menu choice: ", NULL, 0);
        int option = atoi(input);
        switch (option)
        {

            case 1:
                choose_image("BOOT:");
                break;
            case 2:
                /* Try to load ATF image from raw flash */
                BDK_TRACE(BOOT_STUB, "Looking for ATF image\n");
                bdk_image_boot("/dev/n0.mmc0", ATF_ADDRESS, 0);
                bdk_error("Unable to load image\n");
                break;
            case 3:
                bdk_bist_check();
                break;
            case 4:
                usb_bist(0,0,0);
                usb_bist(0,0,1);
                usb_bist(0,1,0);
                usb_bist(0,1,1);
                printf("\nUSB BIST CHECK COMPLETE\n");
                break;
            case 5:
                usb_3_disable(0,0);
                usb_3_disable(0,1);
                break;
        }
    }
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(int argc, const char **argv)
{
    bdk_node_t node = bdk_numa_local();

    /* Enable watchdog. Must be after loading the config so we know the
       watchdog timeout */
    bdk_watchdog_set(0);

    /* Send status to the BMC: Started boot stub */
    bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_STARTING);


    printf(
        "=========================\n"
        "Cavium THUNDERX Boot Stub\n"
        "=========================\n"
        "BDK Version: %s\n"
        "\n",
        bdk_version_string());


    bdk_watchdog_poke();


    if (!bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        bdk_boot_ccpi_link();      /* Set up CCPI */

        bdk_boot_dram(bdk_numa_master(), MFG_SYSTEM_LEVEL_TEST); /* Initialize DRAM on node 0 */
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_NODE0_DRAM_COMPLETE);

        bdk_boot_ccpi_nodes();     /* Set up CCPI */
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_CCPI_COMPLETE);

        if (bdk_numa_exists(BDK_NODE_1))
            bdk_boot_info_strapping(BDK_NODE_1);
        bdk_boot_dram(BDK_NODE_1, MFG_SYSTEM_LEVEL_TEST); /* Initialize DRAM on node 1 */
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_NODE1_DRAM_COMPLETE);

        bdk_boot_qlm();
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_QLM_COMPLETE);

        bdk_boot_bgx();
        bdk_boot_usb();
    }

    bdk_watchdog_poke();

    bdk_boot_pcie();
    bdk_boot_twsi();
    bdk_boot_mdio();

    /* Poke the watchdog */
    bdk_watchdog_poke();

    if (MFG_SYSTEM_LEVEL_TEST)
    {
        printf("Manufacturing System Level Test Boot Menu:\n");
        slt_boot_image(node);
        return 0;
    }

    /* Send status to the BMC: Loading ATF */
    int use_atf = ((long)argv != 1); /* argv=1 means jump to diagnsotics */
    if (use_atf)
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_LOADING_ATF);
    else
        bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_LOADING_DIAGNOSTICS);

    /* Transfer control to next image */
    if (use_atf)
    {
        /* Try to load ATF image from raw flash */
        BDK_TRACE(BOOT_STUB, "Looking for ATF image\n");
        bdk_image_boot("/boot", ATF_ADDRESS, 0);
        bdk_error("Unable to load image\n");
        printf("Trying diagnostics\n");
    }

    /* Load Diagnostics from FAT fs */
    BDK_TRACE(BOOT_STUB, "Looking for Diagnostics image\n");
    bdk_image_boot("/fatfs/diagnostics.bin", 0, 0);
}


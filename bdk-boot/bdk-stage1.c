#include <bdk.h>

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
}

static int list_images(const char *dev_filename, int max_images, uint64_t image_address[])
{
    int num_images = 0;
    printf("\nLooking for images in %s\n\n", dev_filename);

    FILE *inf = fopen(dev_filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", dev_filename);
        return 0;
    }
    uint64_t loc = BDK_IMAGE_FIRST_OFFSET;
    uint64_t end = 1 << 24; /* Only look through the first 16MB, limit of 24bit SPI */
    while (loc < end)
    {
        bdk_image_header_t header;

        printf("0x%06lx\r", loc);

        fseek(inf, loc, SEEK_SET);
        int status = bdk_image_read_header(inf, &header);
        if (status == 0)
        {
            printf("  %d) 0x%06lx: %s, version %s, %u bytes\n",
                num_images+1, loc, header.name, header.version, header.length);
            image_address[num_images++] = loc;
        }
        loc += BDK_IMAGE_ALIGN;
    }
    printf("\n");
    fclose(inf);
    return num_images;
}

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

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;
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

static void choose_image(const char *dev_filename)
{
    const int MAX_IMAGES = 4;
    uint64_t image_address[MAX_IMAGES];
    int num_images = list_images(dev_filename, MAX_IMAGES, image_address);
    if (num_images == 0)
    {
        printf("No images found\n");
        return;
    }

    int use_image = 0;
    if (num_images > 1)
    {
        const char *input = bdk_readline("Image address to load: ", NULL, 0);
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
    boot_image(dev_filename, image_address[use_image]);
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    bdk_node_t node = bdk_numa_local();

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
        case RST_BOOT_METHOD_E_SPI16:
            boot_method_str = "SPI16";
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
        "BDK version: %s\n"
        "\n"
        "===============\n"
        "BDK Stage1 Boot\n"
        "===============\n"
        "Node:  %d\n"
        "RCLK:  %lu Mhz\n"
        "SCLK:  %lu Mhz\n"
        "Boot:  %s(%d)\n"
        "VRM:   %s\n"
        "Trust: %s\n",
        bdk_version_string(),
        node,
        bdk_clock_get_rate(node, BDK_CLOCK_CORE) / 1000000,
        bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 1000000,
        boot_method_str, boot_method,
        (vrm_disable) ? "Disabled" : "Enabled",
        (trust_mode) ? "Enabled" : "Disabled");

    extern int bdk_fs_mmc_init(void);
    extern int bdk_fs_mpi_init(void);
    bdk_fs_mmc_init();
    bdk_fs_mpi_init();

    while (1)
    {
        printf(
            "\n"
            "Boot Menu\n"
            "=========\n"
            " 1) Change baud rate and flow control\n"
            " 2) Load image from MMC, eMMC, or SD\n"
            " 3) Load image from SPI\n"
            " 4) Soft reset chip\n");
        const char *input = bdk_readline("Menu choice: ", NULL, 0);
        switch (atoi(input))
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
                bdk_set_baudrate(bdk_numa_local(), 0, baudrate, use_flow);
                printf("Baudrate is now %d\n", baudrate);
                break;
            }
            case 2: /* eMMC / SD */
            {
                choose_image("/dev/mmc/0");
                break;
            }
            case 3: /* SPI */
            {
                BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
                char name[48];
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

                snprintf(name, sizeof(name), "/dev/mpi/cs%d-%c,2wire,idle-%c,%csb,%dbit,%d",
                    chip_select,
                    (active_high) ? 'h' : 'l',
                    idle_mode,
                    (is_msb) ? 'm' : 'l',
                    address_width,
                    freq_mhz);
                choose_image(name);
                break;
            }
            case 4: /* Soft reset */
                printf("Performing a soft reset\n");
                bdk_reset_chip(bdk_numa_local());
                break;
            default:
                bdk_error("Illegal input\n");
                break;
        }
    }
}

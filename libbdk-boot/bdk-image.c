#include <bdk.h>
#include <malloc.h>
#include <ctype.h>

#define HEADER_MAGIC 0x585245444e554854L

static int header_is_valid(const bdk_image_header_t *header)
{
    /* First instruction can't be zero */
    int bad = (header->instruction == 0);
    /* Make sure the length is somewhat sane. 1GB is an arbitrary limit */
    bad |= (header->length <= sizeof(*header)) || (header->length > 1<<30);
    /* Check the magic number */
    bad |= (header->magic != HEADER_MAGIC);
    /* No constraints on CRC */
    /* Reserved space must be zero */
    bad |= (header->reserved1 != 0);
    /* Name must not be empty and must end in a zero */
    bad |= (header->name[0] == 0) || (header->name[63] != 0);
    /* Version must not be empty and must end in a zero */
    bad |= (header->version[0] == 0) || (header->version[31] != 0);
    /* Reserved space must be zero */
    for (int i = 0; i < 17; i++)
        bad |= (header->reserved[i] != 0);
    return !bad;
}

/**
 * Verify image at the given address is good
 *
 * @param image  Pointer to the image
 *
 * @return Zero on success, negative on failure
 */
int bdk_image_verify(const void *image)
{
    const bdk_image_header_t *header = image;
    if (!header_is_valid(image))
        return -1;

    uint32_t crc = bdk_crc32(image, 16, 0);
    uint32_t zero = 0;
    crc = bdk_crc32(&zero, 4, crc);
    crc = bdk_crc32(image + 20, header->length - 20, crc);

    if (crc == header->crc32)
        return 0;
    else
        return -1;
}

/**
 * Read a image header from a file
 *
 * @param handle File handel to read from
 * @param header Pointer to header structure to fill
 *
 * @return Zero on success, negative on failure
 */
int bdk_image_read_header(FILE *handle, bdk_image_header_t *header)
{
    size_t count = fread(header, sizeof(*header), 1, handle);

    /* Check if read failed */
    if (count != 1)
        return -1;

    return !header_is_valid(header);
}

/**
 * Read a image from a file and boot it, replacing the current running BDK image
 *
 * @param filename   File to read the image from
 * @param loc        Offset into file for image. This is normally zero for normal files. Device
 *                   files, such as /dev/mem, will use this to locate the image.
 *
 * @return Negative on failure. On success this function never returns.
 */
int bdk_image_boot(const char *filename, uint64_t loc)
{
    void *image = NULL;

    FILE *inf = fopen(filename, "rb");
    if (!inf)
    {
        bdk_error("Failed to open %s\n", filename);
        return -1;
    }

    if (loc)
    {
        printf("    Loading image at %s:0x%lx\n", filename, loc);
        fseek(inf, loc, SEEK_SET);
    }
    else
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

    //printf("    Verifying image\n");
    if (bdk_image_verify(image))
    {
        bdk_error("Image CRC32 is incorrect\n");
        goto out;
    }

    /* Putting all cores except this one in reset */
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("---\n");
    fflush(NULL);
    BDK_MB;

    if (bdk_watchdog_is_running())
    {
        /* Software wants the watchdog running with a 15 second timout */
        bdk_watchdog_set(15000);
    }

    /* This string is passed to the image as a default environment. It is
       series of NAME=VALUE pairs separated by '\0'. The end is marked with
       two '\0' in a row. */
    static char image_env[64] = { 0 };
    const char  *board = bdk_config_get_str(BDK_CONFIG_BOARD_MODEL);
    /* FIXME: The SDK currently (10/22/2015) has hard coded string matching
       based on board names. We need to fixup CRB strings to match. We also
       have to force the strings to lower case. This is a crazy ugly hack */
    if (strcasecmp(board, "CRB-1S") == 0)
        board = "crb_1s";
    if (strcasecmp(board, "CRB-2S") == 0)
        board = "crb_2s";
    snprintf(image_env, sizeof(image_env), "BOARD=%s", board);
    char *ptr = image_env + 6; /* Skip BOARD= */
    while (*ptr)
    {
        *ptr = tolower((int)*ptr);
        ptr++;
    }
    /* FIXME: End of board string hacks */

    bdk_jump_address(bdk_ptr_to_phys(image), bdk_ptr_to_phys(image_env), __bdk_config_export_to_mem());
    /* Should never get here */
    bdk_error("Failed to jump to image\n");
out:
    if (image)
        free(image);
    fclose(inf);
    return -1;
}


/**
 * Search the FatFS and return a list of BDK images
 * available. The images will also be displayed on the console.
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
 * them choose one to boot.
 *
 * @param path
 *               Device file to search
 */
void bdk_image_choose(const char *path)
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
    bdk_image_boot(image_names[use_image], 0);
}


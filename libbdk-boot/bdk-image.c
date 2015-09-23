#include <bdk.h>
#include <malloc.h>

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
 * @param filename File to read the image from
 * @param loc      Offset into file for image. This is normally zero for normal files. Device
 *                 files, such as /dev/mem, will use this to locate the image.
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

    printf("    Verifying image\n");
    if (bdk_image_verify(image))
    {
        bdk_error("Image CRC32 is incorrect\n");
        goto out;
    }

    /* Putting all cores except this one in reset */
    bdk_reset_cores(bdk_numa_local(), -2);

    printf("    Jumping to image at %p\n---\n", image);
    fflush(NULL);
    BDK_MB;

    /* Send status to the BMC: Boot stub complete */
    bdk_boot_status(BDK_BOOT_STATUS_BOOT_STUB_COMPLETE);

    if (bdk_watchdog_is_running())
    {
        /* Software wants the watchdog running with a 15 second timout */
        bdk_watchdog_set(15000);
    }

    /* This string is passed to the image as a default environment. It is
       series of NAME=VALUE pairs separated by '\0'. The end is marked with
       two '\0' in a row. */
    static char image_env[64] = { 0 };
    const char  *board = bdk_brd_cfg_get_str("not-defined", BDK_BRD_CFG_BOARD);
    snprintf(image_env, sizeof(image_env), "BOARD=%s", board ? board : "none");

    bdk_jump_address(bdk_ptr_to_phys(image), bdk_ptr_to_phys(image_env));
    /* Should never get here */
    bdk_error("Failed to jump to image\n");
out:
    if (image)
        free(image);
    fclose(inf);
    return -1;
}

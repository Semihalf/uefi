#include <bdk.h>

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


#include <bdk.h>
#include <fcntl.h>

typedef struct
{
    int region;
    int block;
    int block_size;
    int offset;
} nor_loc_t;

static nor_loc_t get_loc(int chip_id, int loc)
{
    nor_loc_t result;
    result.region = -1;
    result.block = -1;
    result.block_size = 0;
    result.offset = 0;

    int num_region = bdk_flash_get_num_regions(chip_id);
    for (int region=0; region<num_region; region++)
    {
        const bdk_flash_region_t *info = bdk_flash_get_region_info(chip_id, region);
        if ((info->start_offset <= loc) &&
            (info->start_offset + info->block_size*info->num_blocks > loc))
        {
            result.region = region;
            result.block = (loc - info->start_offset) / info->block_size;
            result.block_size = info->block_size;
            result.offset = (loc - info->start_offset) % info->block_size;
            break;
        }
    }
    return result;
}


static void *nor_open(const char *name, int flags)
{
    long chip_id = atoi(name);
    if ((chip_id < 0) || (chip_id >= 8))
        return NULL;

    if (!bdk_flash_get_base(chip_id))
        return NULL;

    return (void*)(chip_id + 1);
}


static int nor_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int chip_id = (long)handle->fs_state - 1;
    uint64_t base = bdk_flash_get_base(chip_id);
    unsigned int pos = handle->location;
    int read_count = 0;

    while (read_count < length)
    {
        nor_loc_t nor_loc = get_loc(chip_id, pos);
        if (!nor_loc.block_size)
            return (read_count || pos) ? read_count : -1;
        int len = nor_loc.block_size - nor_loc.offset;
        if (read_count + len > length)
            len = length - read_count;
        memcpy(buffer, bdk_phys_to_ptr(base + pos), len);
        read_count += len;
        pos += len;
        buffer += len;
    }

    return read_count;
}


static int nor_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int chip_id = (long)handle->fs_state - 1;
    unsigned int pos = handle->location;
    int write_count = 0;

    while (write_count < length)
    {
        /* Figure out which region and block we're in */
        nor_loc_t nor_loc = get_loc(chip_id, pos);
        if (!nor_loc.block_size)
            return (write_count) ? write_count : -1;

        /* Figure out how many bytes we're write to this block */
        int len = nor_loc.block_size - nor_loc.offset;
        if (write_count + len > length)
            len = length - write_count;

        /* If we're starting a new block then erase it. We assume we're
            sequencially writing to flash and we don't care about data not
            written to in the same block */
        if (nor_loc.offset == 0)
        {
            if (bdk_flash_erase_block(chip_id, nor_loc.region, nor_loc.block))
                return -1;
        }

        /* Write the data */
        if (bdk_flash_write(chip_id, pos, buffer, len))
            return -1;

        write_count += len;
        pos += len;
        buffer += len;
    }

    return write_count;
}

static const __bdk_fs_ops_t bdk_fs_nor_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = nor_open,
    .close = NULL,
    .read = nor_read,
    .write = nor_write,
};

int bdk_fs_nor_init(void)
{
    return bdk_fs_register("/dev/nor/", &bdk_fs_nor_ops);
}

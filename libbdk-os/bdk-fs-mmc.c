#include <bdk.h>

static void *mmc_open(const char *name, int flags)
{
    long chip_sel = atoi(name);
    if ((chip_sel < 0) || (chip_sel >= 4))
        return NULL;

    uint64_t size = bdk_mmc_initialize(chip_sel);
    if (size == 0)
        return NULL;

    return (void*)(chip_sel + 1);
}

static int mmc_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int chip_sel = (long)handle->fs_state - 1;
    /* Read one block into a temp buffer in case the buffer we received
       doesn't have enough space */
    char tmp[512];
    /* Force the read to be 512 byte aligned and only one block */
    int status = bdk_mmc_read(chip_sel, handle->location & -512, tmp, 512);
    if (status != 0)
        return -1;
    /* The caller may not be aligned, so drop data that he doesn't want */
    int offset = handle->location & 511;
    /* Limit the return length to one block */
    if (length > 512 - offset)
        length = 512 - offset;
    memcpy(buffer, tmp + offset, length);
    /* Return length may be much smaller than they originally wanted */
    return length;
}

static int mmc_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int chip_sel = (long)handle->fs_state - 1;
    uint64_t loc = handle->location;
    int write_count = 0;
    while (length)
    {
        /* Do a partial write if the update doesn't start on a block
           boundary or the length is shorter than a block */
        int partial = (loc & 511) || (length < 512);
        int len;
        if (partial) /* Partial block, do a read/modify/write */
        {
            /* Align on a block boundary */
            int offset = loc & 511;
            char tmp[512];
            if (bdk_mmc_read(chip_sel, loc & -512, tmp, 512))
                break;
            len = 512 - offset;
            if (len > length)
                len = length;
            memcpy(tmp + offset, buffer, len);
            if (bdk_mmc_write(chip_sel, loc & -512, tmp, 512))
                break;
        }
        else
        {
            len = length & -512;
            if (bdk_mmc_write(chip_sel, loc, buffer, len))
                break;
        }
        buffer += len;
        length -= len;
        loc += len;
        write_count += len;
    }
    return write_count;
}

static const __bdk_fs_ops_t bdk_fs_mmc_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = mmc_open,
    .close = NULL,
    .read = mmc_read,
    .write = mmc_write,
};

int bdk_fs_mmc_init(void)
{
    return bdk_fs_register("/dev/mmc/", &bdk_fs_mmc_ops);
}

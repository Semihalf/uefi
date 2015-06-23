#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_FATFS);

/* This is a BDK wrapper around FatFs for accessing files in a FAT filesystem. */

static void *fatfs_open(const char *name, int flags)
{
    BYTE mode = 0;
    FIL *fp = (FIL *) malloc(sizeof(FIL));
    if (!fp)
        return NULL;

    switch (flags & 3)
    {
        case O_RDONLY: mode = FA_READ;            break;
        case O_WRONLY: mode =           FA_WRITE; break;
        case O_RDWR:   mode = FA_READ | FA_WRITE; break;
        default:
            bdk_warn("FatFs: Unsupported flag %04x. Using default read/write.\n", flags);
            mode = FA_READ | FA_WRITE;
            break;
    }
    if (flags & O_CREAT)
    {
        mode |= FA_CREATE_ALWAYS;
    }

    FRESULT rc = f_open(fp, name, mode);
    return rc ? NULL : (void*) fp;
}

static int fatfs_close(__bdk_fs_file_t *handle)
{
    FIL *fp = handle->fs_state;
    if (!fp)
    {
        return 0;
    }

    FRESULT rc = f_close(fp);
    free(fp);
    return rc ? -1 : 0;
}

static int fatfs_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    UINT count;
    FIL *fp = handle->fs_state;
    if (!fp)
    {
        return 0;
    }

    FRESULT rc = f_read(fp, buffer, length, &count);
    return rc ? -1 : (int) count;
}

static int fatfs_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    UINT count;
    FIL *fp = handle->fs_state;
    if (!fp)
    {
        return 0;
    }

    FRESULT rc = f_write(fp, buffer, length, &count);
    return rc ? -1 : (int) count;
}

static const __bdk_fs_ops_t bdk_fs_fatfs_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = fatfs_open,
    .close = fatfs_close,
    .read = fatfs_read,
    .write = fatfs_write,
};

static FATFS fatfs; /* only one filesystem mount supported at this time */

int bdk_fs_fatfs_init(void)
{
    /* We only use a single device, no device mapping used. Hence "IGNORED". */
    f_mount(&fatfs, "spi0:", 0);
    return bdk_fs_register("/fatfs/", &bdk_fs_fatfs_ops);
}

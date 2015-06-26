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

int __bdk_fs_fatfs_init(void)
{
    static FATFS fatfs[_VOLUMES]; /* FATFS handles for all defined volumes */

    /* Go through all defined volumes and lazy-mount them. Lazy mounting will
     * always succeed. The volume will be hard-mounted later when the volume
     * will be first accessed via another operation. Any errors will be
     * generated at that point.
     */
    static const char* const str[] = {_VOLUME_STRS};
    for (int i = 0; i < _VOLUMES; i++)
    {
        char volume_id[16];
        snprintf(volume_id, sizeof(volume_id), "%s:", str[i]);
        f_mount(&fatfs[i], volume_id, 0);
    }

    /* Determine how we booted */
    bdk_node_t node = bdk_numa_local();
    int boot_method;
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

    /* Set FATFS Volume ID  based on boot method */
    extern int fatfs_set_default_volume_for_boot_method(int boot_method);
    int rc = fatfs_set_default_volume_for_boot_method(boot_method);
    if (rc)
    {
        bdk_error("No valid boot volume id found for boot method (%d)\n", boot_method);
    }

    return bdk_fs_register("/fatfs/", &bdk_fs_fatfs_ops);
}

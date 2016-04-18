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

static int fatfs_unlink(const char *name)
{
    return f_unlink(name);
}

static const __bdk_fs_ops_t bdk_fs_fatfs_ops =
{
    .stat = NULL,
    .unlink = fatfs_unlink,
    .open = fatfs_open,
    .close = fatfs_close,
    .read = fatfs_read,
    .write = fatfs_write,
};

static const char* const volstr[] = {_VOLUME_STRS};
static FATFS fatfs[_VOLUMES]; /* FATFS handles for all defined volumes */
static uint32_t mountmask = 0;
int __bdk_fs_fatfs_init(void)
{

    /* Go through all defined volumes and lazy-mount them. Lazy mounting will
     * always succeed. The volume will be hard-mounted later when the volume
     * will be first accessed via another operation. Any errors will be
     * generated at that point.
     */

    for (int i = 0; i < _VOLUMES; i++)
    {
        char volume_id[16];
        if ((i < DRV_USB0) || (i > DRV_USB2)) {
            snprintf(volume_id, sizeof(volume_id), "%s:", volstr[i]);
            f_mount(&fatfs[i], volume_id, 0);
            mountmask |= (1<<i);
        }
    }

    /* Initialize the FATFS disk IO layer. */
    if (-1 == fatfs_diskio_init())
    {
        bdk_warn("FatFs: Could not initialize disk IO layer.\n");
    }

    return bdk_fs_register("/fatfs/", &bdk_fs_fatfs_ops);
}

void __bdk_fs_fatfs_usbnotify(int drvIndex, int available)
{ /* Poor mans automounter
  ** It is called by usb proper when mass storage devices change
  ** availability or media
  */
    int pdrv = drvIndex + DRV_USB0;
    if (pdrv > DRV_USB2) return; /* There are more indexes then usb drives
                                    ... fatfs can digest */
    char volume_id[16];
    snprintf(volume_id, sizeof(volume_id), "%s:", volstr[pdrv]);
    if (available) {
        // Mass storage device became available
        // - reset its interface to blockio
        // - do lazy mount
        disk_usbnotify(drvIndex, available);
        f_mount(&fatfs[pdrv], volume_id, 0);
        mountmask |= (1<<pdrv);
    } else {
        // device is no longer there
        // - unmount
        // - reset blockio underneath
        f_mount(NULL, volume_id,1);
        mountmask &= ~(1<<pdrv);
        disk_usbnotify(drvIndex, available);
    }
    printf("\n/fatfs/%s %savailable\n", volume_id, (available) ? "" : "un");
}

void __bdk_list_fs_fatfs() {
    uint32_t tmask = 1;
    for(int i = 0; i < _VOLUMES;tmask <<=1, i++) {
        if (!(mountmask & tmask)) continue;
        printf("  %d: == /fatfs/%s:\n", i,volstr[i]);
    }
}

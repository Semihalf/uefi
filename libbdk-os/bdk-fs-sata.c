#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_SATA);

/**
 * Open a SATA disk for read/write. The SATA device is treated as raw block
 * storage without any filesystem. All reads and writes must be in 512 byte
 * chunks, aligned on 512 byte boundaries. SATA read / writes complete sectors
 * at a time.
 *
 * @param name   The sata name will be the controller number. The "/dev/sata/" prefix has
 *               already been removed.
 * @param flags  Standard open flags
 *
 * @return NULL on failure, otherwise an opaque pointer passed back in for read/write calls.
 */
static void *sata_open(const char *name, int flags)
{
    /* Assume we're accessing a SATA on the same node we're running */
    bdk_node_t node = bdk_numa_local();
    int sata = atoi(name);
    int num_sata = bdk_sata_get_controllers(node);

    /* Check that the controller is valid */
    if ((sata < 0) || (sata >= num_sata))
    {
        bdk_error("SATA: Invalid controller specified (%d)\n", sata);
        return NULL;
    }

    /* Determine how many SATA ports are connected to the controller */
    int num_ports = bdk_sata_get_ports(node, sata);

    /* If no ports are connected, call initialize to restart the controller */
    if (num_ports == 0)
    {
        if (bdk_sata_initialize(node, sata))
        {
            bdk_error("SATA%d: Initialization failed\n", sata);
            return NULL;
        }
        num_ports = bdk_sata_get_ports(node, sata);
    }

    /* We should have one port, If we don't then the QLMs aren't configured for
        SATA */
    if (num_ports == 0)
    {
        bdk_error("SATA%d: Controller not connected to any ports\n", sata);
        return NULL;
    }

    /* The opaque pointer is a combination of the SATA controller and node. It
       must be non-zero, hence the +1 */
    long state = sata + 1;
    state += node << 8;
    return (void*)state;
}

/**
 * Read from a SATA device
 *
 * @param handle FS handle
 * @param buffer Buffer to fill
 * @param length Length to fill, must be a multiple of 512
 *
 * @return Number of bytes read, or negative on error
 */
static int sata_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    /* Extract the controller and node */
    int sata = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    /* Make sure we're working with complete sectors */
    if ((length & 511) || (handle->location & 511))
    {
        bdk_error("SATA%d: File IO must be in multiples of 512 bytes\n", sata);
        return -1;
    }

    /* Do the read */
    if (bdk_sata_read(node, sata, 0, handle->location >> 9, length >> 9, buffer))
    {
        bdk_error("SATA%d: Read error\n", sata);
        return 0;
    }
    else
        return length;
}

/**
 * Write to a SATA device
 *
 * @param handle FS handle
 * @param buffer Buffer to write
 * @param length Length to buffer, must be a multiple of 512
 *
 * @return Number of bytes written, or negative on error
 */
static int sata_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    /* Extract the controller and node */
    int sata = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    /* Make sure we're working with complete sectors */
    if ((length & 511) || (handle->location & 511))
    {
        bdk_error("SATA%d: File IO must be in multiples of 512 bytes\n", sata);
        return -1;
    }

    /* Do the write */
    if (bdk_sata_write(node, sata, 0, handle->location >> 9, length >> 9, buffer))
    {
        bdk_error("SATA%d: Write error\n", sata);
        return 0;
    }
    else
        return length;
}

static const __bdk_fs_ops_t bdk_fs_sata_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = sata_open,
    .close = NULL,
    .read = sata_read,
    .write = sata_write,
};

int bdk_fs_sata_init(void)
{
    return bdk_fs_register("/dev/sata/", &bdk_fs_sata_ops);
}

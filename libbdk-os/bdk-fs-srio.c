#include <bdk.h>
#include <stdio.h>

#ifndef BDK_DISABLE_SRIO

typedef union
{
    long u;
    struct
    {
        uint8_t     valid   : 1;
        uint8_t     is16bit : 1;
        uint8_t     reserved: 6;
        uint8_t     port;
        uint16_t    device;
    } s;
} srio_file_state_t;


static void *srio_open(const char *name, int flags)
{
    srio_file_state_t state;

    int port = 0;
    int device = 0;

    /* Format of filenames is /dev/srio/port/device */
    if (sscanf(name, "%d/%d", &port, &device) != 2)
        return NULL;
    /* Validate port */
    if ((port < 0) || (port >= 4))
        return NULL;
    /* Validate device */
    if ((device < 0) || (device >= 65536))
        return NULL;

    /* Store state info for later calls */
    state.u = 0;
    state.s.valid = 1;
    state.s.port = port;
    state.s.is16bit = (device >= 256);
    state.s.device = device;
    return (void*)state.u;
}


static int srio_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    srio_file_state_t state;
    state.u = (long)handle->fs_state;

    /* Memory map SRIO */
    uint64_t address = bdk_srio_physical_map(state.s.port,
        BDK_SRIO_WRITE_MODE_AUTO, 0, BDK_SRIO_READ_MODE_NORMAL, 0,
        0, state.s.device, state.s.is16bit, handle->location, length);
    if (!address)
        return -1;

    /* Do the transfer */
    memcpy(buffer, bdk_phys_to_ptr(address), length);

    /* Free the memory map */
    if (bdk_srio_physical_unmap(address, length))
        return -1;

    return length;
}


static int srio_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    srio_file_state_t state;
    state.u = (long)handle->fs_state;

    /* Memory map SRIO */
    uint64_t address = bdk_srio_physical_map(state.s.port,
        BDK_SRIO_WRITE_MODE_AUTO, 0, BDK_SRIO_READ_MODE_NORMAL, 0,
        0, state.s.device, state.s.is16bit, handle->location, length);
    if (!address)
        return -1;

    /* Do the transfer */
    memcpy(bdk_phys_to_ptr(address), buffer, length);

    /* Free the memory map */
    if (bdk_srio_physical_unmap(address, length))
        return -1;

    return length;
}

static const __bdk_fs_ops_t bdk_fs_srio_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = srio_open,
    .close = NULL,
    .lseek = NULL,
    .read = srio_read,
    .write = srio_write,
};

int bdk_fs_srio_init(void)
{
    return bdk_fs_register("/dev/srio/", &bdk_fs_srio_ops);
}

#endif /* BDK_DISABLE_SRIO */


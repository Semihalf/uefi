#include <bdk.h>

#define REMOTE_MAGIC 0x434f4e53 /* CONS */
#define REMOTE_VERSION 0x01

/**
 * Format of the shared buffer used by the remote console. This
 * data structure is exactly 512 bytes and at a fixed location in
 * Octeon's memory. The location is __bdk_remote_console, which
 * is a symbol in bdk-start.S.
 */
typedef struct
{
    uint32_t magic;
    uint8_t  version;
    uint8_t  unused;
    uint8_t  to_octeon;
    uint8_t  from_octeon;
    uint8_t  to_buffer[256-4];
    uint8_t  from_buffer[256-4];
} remote_console_t;

/**
 * Open the remote console by setting up the shared data
 * structure. This can only be called once.
 *
 * @param name   Name of the remote console
 * @param flags  Unused flags
 *
 * @return NULL on failure
 */
static void *remote_open(const char *name, int flags)
{
    uint64_t master_offset = (uint64_t)bdk_numa_master() << 40;
    remote_console_t *remote = bdk_phys_to_ptr(0x500 + master_offset);
    if (remote->magic == REMOTE_MAGIC)
    {
        bdk_error("Attempt to open the remote console twice\n");
        return NULL;
    }
    memset(remote, 0, sizeof(*remote));
    remote->version = REMOTE_VERSION;
    BDK_SYNCW;
    /* The console can be used as soon as the magic value is written. The
        magic value must be the last part of init done */
    remote->magic = REMOTE_MAGIC;
    BDK_SYNCW;
    return remote;
}

/**
 * Read from the remote console
 *
 * @param handle File handle
 * @param buffer Buffer for data
 * @param length Bytes to read
 *
 * @return Number of bytes read, negative on failure
 */
static int remote_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    remote_console_t *remote = handle->fs_state;
    if (remote->magic != REMOTE_MAGIC)
    {
        bdk_error("Remote console magic value is incorrect (0x%x)\n", remote->magic);
        return -1;
    }

    /* Return if no data is waiting */
    if (!remote->to_octeon)
        return -1;

    if (length > remote->to_octeon)
        length = remote->to_octeon;
    memcpy(buffer, remote->to_buffer, length);

    /* Save extra data if there was more than we needed */
    if (length < remote->to_octeon)
    {
        memcpy(remote->to_buffer, remote->to_buffer + length, remote->to_octeon - length);
        BDK_SYNCW;
    }
    /* Updating the amount of data must be last as the remote host is allowed
        to write again as soon as this is zero */
    remote->to_octeon -= length;
    BDK_SYNCW;
    return length;
}

/**
 * Write to remote console
 *
 * @param handle File handle
 * @param buffer Buffer to write
 * @param length Bytes to write
 *
 * @return Number of bytes written
 */
static int remote_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    remote_console_t *remote = handle->fs_state;
    int count = 0;
    if (remote->magic != REMOTE_MAGIC)
    {
        bdk_error("Remote console magic value is incorrect (0x%x)\n", remote->magic);
        return -1;
    }

    while (length)
    {
        /* Wait for room */
        while (remote->from_octeon)
            bdk_thread_yield();
        /* Write to the buffer */
        int l = length;
        if (l > (int)sizeof(remote->from_buffer))
            l = sizeof(remote->from_buffer);
        memcpy(remote->from_buffer, buffer, l);
        BDK_SYNCW;
        /* Updating the count msut be last as the remtoe host can read data
            as soon as it is non zero */
        remote->from_octeon = l;
        BDK_SYNCW;
        length -= l;
        buffer += l;
        count += l;
    }
    return count;
}

static const __bdk_fs_ops_t bdk_fs_remote_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = remote_open,
    .close = NULL,
    .read = remote_read,
    .write = remote_write,
};

/**
 * Call early in startup to enable the remote console. Data
 * will not be written to the console until as least one byte
 * is read.
 *
 * @return Zero on success, negative on failure
 */
int bdk_fs_remote_init(void)
{
    int status = bdk_fs_register("/dev/remote", &bdk_fs_remote_ops);
    if (status)
        return status;
    extern int console_open_file(const char *filename);
    status = console_open_file("/dev/remote");
    if (status < 0)
        return status;
    return 0;
}


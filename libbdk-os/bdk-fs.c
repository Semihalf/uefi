#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <stdio.h>
#include <errno.h>

#define MAX_FILE_HANDLES 16
#define MAX_MOUNT_POINTS 12

/**
 * Structure used for mount points. This maps filenames into
 * the proper file system operations
 */
typedef struct
{
    const char *prefix;
    const __bdk_fs_ops_t *ops;
} bdk_fs_mount_t;

extern const __bdk_fs_ops_t bdk_fs_console_ops;
extern const __bdk_fs_ops_t bdk_fs_uart_ops;
extern const __bdk_fs_ops_t bdk_fs_dev_ops;
static bdk_fs_mount_t mount_points[MAX_MOUNT_POINTS] = {
    {"/console", &bdk_fs_console_ops},
    {"/dev/uart/", &bdk_fs_uart_ops},
    {"/device/", &bdk_fs_dev_ops},
    {NULL, NULL}
};

/**
 * The open file handle table. Handle 0-2 are open to start with
 * connected to uart 0. They can be closed later if needed.
 */
static __bdk_fs_file_t file_handle[MAX_FILE_HANDLES] = {
    [0] = { .fs_state = NULL, .ops = &bdk_fs_console_ops },
    [1] = { .fs_state = NULL, .ops = &bdk_fs_console_ops },
    [2] = { .fs_state = NULL, .ops = &bdk_fs_console_ops },
    [3] = { .fs_state = (void*)1, .ops = &bdk_fs_uart_ops },
    [4] = { .fs_state = (void*)2, .ops = &bdk_fs_uart_ops },
};
#undef errno
extern int errno;


/**
 * Dynamically register a new filesystem mount point. This is so
 * dependencies on stdout don't pull in all possible filesystems.
 *
 * @param prefix Prefix for mount
 * @param ops    File operations
 *
 * @return Zero on success, negative on failure
 */
int bdk_fs_register(const char *prefix, const __bdk_fs_ops_t *ops)
{
    /* Find the first empty mount point */
    int i = 0;
    while (mount_points[i].prefix)
        i++;

    /* Fail if all spots are full. Note that we must keep the last
        one as NULL to mark the end */
    if (i >= MAX_MOUNT_POINTS - 1)
    {
        bdk_error("bdk_fs_register: Too many mount points\n");
        return -1;
    }

    /* Add the new mount point */
    mount_points[i].prefix = prefix;
    mount_points[i].ops = ops;
    mount_points[i+1].prefix = NULL;
    mount_points[i+1].ops = NULL;
    return 0;
}


/**
 * Get the mount point for the given filename
 *
 * @param name   File to find mount point for
 *
 * @return Mount point index, or -1 on failure
 */
static int get_mount(const char *name)
{
    int index = 0;

    while (mount_points[index].prefix)
    {
        int len = strlen(mount_points[index].prefix);
        if (strncmp(mount_points[index].prefix, name, len) == 0)
            return index;
        index++;
    }

    return -1;
}


/**
 * Get the open file descriptor for a file handle
 *
 * @param handle File handle to get
 *
 * @return File descriptor or NULL on failure
 */
static __bdk_fs_file_t *get_file(int handle)
{
    if ((handle<0) || (handle>=MAX_FILE_HANDLES))
        return NULL;
    if (file_handle[handle].ops == NULL)
        return NULL;
    return &file_handle[handle];
}


/**
 * Perform stat()
 *
 * @param name   File to stat
 * @param st     Result of the stat
 *
 * @return Zero on success
 */
int _stat(const char *name, struct stat *st)
{
    int mount = get_mount(name);
    if ((mount != -1) && mount_points[mount].ops->stat)
    {
        name += strlen(mount_points[mount].prefix);
        return mount_points[mount].ops->stat(name, st);
    }
    else
    {
        errno = ENOENT;
        return -1;
    }
}


/**
 * Unlink / Delete a file
 *
 * @param name   File to delete
 *
 * @return Zero on success
 */
int _unlink(const char *name)
{
    int mount = get_mount(name);
    if ((mount != -1) && mount_points[mount].ops->unlink)
    {
        name += strlen(mount_points[mount].prefix);
        return mount_points[mount].ops->unlink(name);
    }
    else
    {
        errno = ENOENT;
        return -1;
    }
}


/**
 * Open a file
 *
 * @param name   File to open
 * @param flags  Read / write flags
 * @param mode   Unused attributes
 *
 * @return File handle, or -1 on failure
 */
int _open(const char *name, int flags, int mode)
{
    int handle;
    int mount = get_mount(name);
    if (mount == -1)
    {
        errno = ENOENT;
        return -1;
    }

    /* Find a free file handle */
    for (handle=0; handle<MAX_FILE_HANDLES; handle++)
        if (file_handle[handle].ops == NULL)
            break;
    if (handle == MAX_FILE_HANDLES)
    {
        errno = EMFILE;
        return -1;
    }

    /* Assign the file handle details */
    file_handle[handle].ops = mount_points[mount].ops;
    file_handle[handle].filename = strdup(name);
    file_handle[handle].location = 0;
    file_handle[handle].fs_state = NULL;

    /* Fail if the strdup of the filename failed */
    if (file_handle[handle].filename == NULL)
    {
        file_handle[handle].ops = NULL;
        errno = ENOMEM;
        return -1;
    }

    /* Call the FS open if it was supplied */
    if (mount_points[mount].ops->open)
    {
        name += strlen(mount_points[mount].prefix);
        errno = ENOENT;
        file_handle[handle].fs_state = mount_points[mount].ops->open(name, flags);
        if (file_handle[handle].fs_state == NULL)
        {
            file_handle[handle].ops = NULL;
            free((void*)file_handle[handle].filename);
            return -1;
        }
    }
    return handle;
}


/**
 * Close a file handle
 *
 * @param handle File handle to close
 *
 * @return Zero on success
 */
int _close(int handle)
{
    int result = 0;
    __bdk_fs_file_t *file = get_file(handle);
    if (!file)
    {
        errno = EBADF;
        return -1;
    }

    if (file->ops->close)
        result = file->ops->close(file);

    if (result == 0)
    {
        if (file->filename)
            free((void*)file->filename);
        memset(file, 0, sizeof(*file));
    }

    return result;
}


/**
 * Seek to a specific file location
 *
 * @param handle File handle
 * @param offset New location
 * @param whence Basis for the new location
 *
 * @return The new location in the file
 */
off_t _lseek(int handle, off_t offset, int whence)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (!file)
    {
        errno = ENOENT;
        return -1;
    }

    switch (whence)
    {
        case SEEK_SET:
            file->location = offset;
            break;
        case SEEK_CUR:
            file->location += offset;
            break;
        case SEEK_END:
            // FIXME: Implement SEEK_END
            break;
    }
    return file->location;
}


/**
 * Read from a file handle
 *
 * @param handle File to read
 * @param buffer Buffer receiving the data
 * @param length Length of the read
 *
 * @return Number of bytes read, can be zero. Negative is a failure
 */
int _read(int handle, void *buffer, int length)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (file && file->ops->read)
    {
        int result = file->ops->read(file, buffer, length);
        if (result > 0)
            file->location += result;
        return result;
    }
    else
    {
        errno = EBADF;
        return -1;
    }
}


/**
 * Write to a file handle
 *
 * @param handle File to write
 * @param buffer Data to write
 * @param length Length of the data
 *
 * @return Number of bytes written. Negative on failure
 */
int _write(int handle, const void *buffer, int length)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (file && file->ops->write)
    {
        int result = file->ops->write(file, buffer, length);
        if (result > 0)
            file->location += result;
        return result;
    }
    else
    {
        errno = EBADF;
        return -1;
    }
}


/**
 * Stat an open file
 *
 * @param handle File handle
 * @param st     Status results
 *
 * @return Zero on success
 */
int _fstat(int handle, struct stat *st)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (file && file->ops->stat)
        return file->ops->stat(file->filename, st);
    else
    {
        errno = EBADF;
        return -1;
    }
}


/**
 * Jump the PC to a physical address. No checking is performed.
 *
 * @param paddress Physical address to jump to
 *
 * @return Zero on success, negative on failure. Note that call most likely
 *         will never return.
 */
int bdk_jump_address(uint64_t paddress)
{
    int (*ptr)(void) = bdk_phys_to_ptr(paddress);
    if (ptr == NULL)
    {
        errno = EBADF;
        return -1;
    }
    asm volatile ("br %0\n" : : "r" (ptr) : "memory");
    return 0; // Not reached
}

/**
 * Used to override the default node 0 for uart output. Called early
 * in init to make uart output go to the local node.
 *
 * @param node   Node to use. Must be a physical node number.
 */
void bdk_fs_set_uart_node(bdk_node_t node)
{
    /* Change uart0 */
    long state = (long)file_handle[3].fs_state;
    state &= 0xff;
    state |= node << 8;
    file_handle[3].fs_state = (void*)state;

    /* Change uart1 */
    state = (long)file_handle[4].fs_state;
    state &= 0xff;
    state |= node << 8;
    file_handle[4].fs_state = (void*)state;
}


#include <bdk.h>
#include <sys/stat.h>
#include <sys/times.h>
#include <stdio.h>
#include <errno.h>

#define MAX_FILE_HANDLES 8

/**
 * This flag is set when a break signal is detected on uart0
 */
int bdk_interrupt_flag;

/**
 * Structure used for mount points. This maps filenames into
 * the proper file system operations
 */
typedef struct
{
    const char *prefix;
    const __bdk_fs_ops_t *ops;
} bdk_fs_mount_t;

extern const __bdk_fs_ops_t bdk_fs_uart_ops;
extern const __bdk_fs_ops_t bdk_fs_rom_ops;
extern const __bdk_fs_ops_t bdk_fs_ram_ops;
extern const __bdk_fs_ops_t bdk_fs_xmodem_ops;
extern const __bdk_fs_ops_t bdk_fs_nor_ops;
static const bdk_fs_mount_t mount_points[] = {
    {"/dev/uart/", &bdk_fs_uart_ops},
    {"/rom/", &bdk_fs_rom_ops},
    {"/ram/", &bdk_fs_ram_ops},
    {"/xmodem", &bdk_fs_xmodem_ops},
    {"/dev/nor/", &bdk_fs_nor_ops},
    {NULL, NULL}
};

/**
 * The open file handle table. Handle 0-2 are open to start with
 * connected to uart 0. They can be closed later if needed.
 */
static __bdk_fs_file_t file_handle[MAX_FILE_HANDLES] = {
    [0] = { .fs_state = (void*)1, .ops = &bdk_fs_uart_ops },
    [1] = { .fs_state = (void*)1, .ops = &bdk_fs_uart_ops },
    [2] = { .fs_state = (void*)1, .ops = &bdk_fs_uart_ops },
};
#undef errno
extern int errno;


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
int stat(const char *name, struct stat *st)
{
    int mount = get_mount(name);
    if ((mount != -1) && mount_points[mount].ops->stat)
    {
        name += strlen(mount_points[mount].prefix);
        return mount_points[mount].ops->stat(name, st);
    }
    else
        return -1;
}


/**
 * Unlink / Delete a file
 *
 * @param name   File to delete
 *
 * @return Zero on success
 */
int unlink(const char *name)
{
    int mount = get_mount(name);
    if ((mount != -1) && mount_points[mount].ops->unlink)
    {
        name += strlen(mount_points[mount].prefix);
        return mount_points[mount].ops->unlink(name);
    }
    else
        return -1;
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
int open(const char *name, int flags, int mode)
{
    int handle;
    int mount = get_mount(name);
    if (mount == -1)
        return -1;

    /* Find a free file handle */
    for (handle=0; handle<MAX_FILE_HANDLES; handle++)
        if (file_handle[handle].ops == NULL)
            break;
    if (handle == MAX_FILE_HANDLES)
        return -1;

    /* Assign the file handle details */
    file_handle[handle].ops = mount_points[mount].ops;
    file_handle[handle].filename = strdup(name);
    file_handle[handle].location = 0;
    file_handle[handle].fs_state = NULL;

    /* Fail if the strdup of the filename failed */
    if (file_handle[handle].filename == NULL)
    {
        file_handle[handle].ops = NULL;
        return -1;
    }

    /* Call the FS open if it was supplied */
    if (mount_points[mount].ops->open)
    {
        name += strlen(mount_points[mount].prefix);
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
int close(int handle)
{
    int result = 0;
    __bdk_fs_file_t *file = get_file(handle);
    if (!file)
        return -1;

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
off_t lseek(int handle, off_t offset, int whence)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (!file)
        return -1;

    if (file->ops->lseek)
        return file->ops->lseek(file, offset, whence);
    else
    {
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
int read(int handle, void *buffer, int length)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (file && file->ops->read)
    {
        int result;
        if ((file == &file_handle[0]) && (length > 1))
        {
            /* As a special case use readline for the original stdin handle */
            const char *line = bdk_readline("", NULL, 0);
            result = strlen(line);
            result++;
            if (result > length)
                result = length;
            memcpy(buffer, line, result);
            ((char*)buffer)[result-1] = '\n';
        }
        else
            result = file->ops->read(file, buffer, length);
        if (result > 0)
            file->location += result;
        return result;
    }
    else
        return -1;
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
int write(int handle, const void *buffer, int length)
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
        return -1;
}


/**
 * Stat an open file
 *
 * @param handle File handle
 * @param st     Status results
 *
 * @return Zero on success
 */
int fstat(int handle, struct stat *st)
{
    __bdk_fs_file_t *file = get_file(handle);
    if (file && file->ops->stat)
        return file->ops->stat(file->filename, st);
    else
        return -1;
}


/**
 * Memory map a file and return its physical address
 *
 * @param name   File to memory map
 * @param flags  Flags, similar to open()
 *
 * @return Physical address or -1 on failure
 */
uint64_t bdk_mmap(const char *name, int flags)
{
    int mount = get_mount(name);
    if ((mount != -1) && mount_points[mount].ops->mmap)
    {
        name += strlen(mount_points[mount].prefix);
        return mount_points[mount].ops->mmap(name, flags);
    }
    else
        return -1;
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
        return -1;
    return ptr();
}

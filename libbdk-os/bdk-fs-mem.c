#include <bdk.h>
#include <fcntl.h>

static void *mem_open(const char *name, int flags)
{
    return (void*)1;
}


static int mem_close(__bdk_fs_file_t *handle)
{
    return 0;
}


static int mem_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    memcpy(buffer, bdk_phys_to_ptr(handle->location), length);
    return length;
}


static int mem_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    memcpy(bdk_phys_to_ptr(handle->location), buffer, length);
    return length;
}

const __bdk_fs_ops_t bdk_fs_mem_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = mem_open,
    .close = mem_close,
    .lseek = NULL,
    .read = mem_read,
    .write = mem_write,
};


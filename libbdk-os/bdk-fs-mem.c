#include <bdk.h>
#include <fcntl.h>

static void *mem_open(const char *name, int flags)
{
    return (void*)1;
}


static int mem_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    /* Check location to avoid warning from bdk_phys_to_ptr */
    const void *ptr = (handle->location) ? bdk_phys_to_ptr(handle->location) : (const void*)(1ull<<63);
    memcpy(buffer, ptr, length);
    return length;
}


static int mem_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    /* Check location to avoid warning from bdk_phys_to_ptr */
    void *ptr = (handle->location) ? bdk_phys_to_ptr(handle->location) : (void*)(1ull<<63);
    memcpy(ptr, buffer, length);
    return length;
}

static const __bdk_fs_ops_t bdk_fs_mem_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = mem_open,
    .close = NULL,
    .read = mem_read,
    .write = mem_write,
};

int bdk_fs_mem_init(void)
{
    return bdk_fs_register("/dev/mem", &bdk_fs_mem_ops);
}

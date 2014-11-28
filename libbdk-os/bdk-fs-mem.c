#include <bdk.h>
#include <fcntl.h>

static int mem_read(__bdk_fs_dev_t *handle, void *buffer, int length)
{
    uint64_t address = bdk_numa_get_address(handle->dev_node, handle->location);
    /* Check location to avoid warning from bdk_phys_to_ptr */
    const void *ptr = (address) ? bdk_phys_to_ptr(address) : NULL;
    memcpy(buffer, ptr, length);
    return length;
}


static int mem_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    uint64_t address = bdk_numa_get_address(handle->dev_node, handle->location);
    /* Check location to avoid warning from bdk_phys_to_ptr */
    void *ptr = (address) ? bdk_phys_to_ptr(address) : NULL;
    memcpy(ptr, buffer, length);
    return length;
}

static const __bdk_fs_dev_ops_t bdk_fs_mem_ops =
{
    .open = NULL,
    .close = NULL,
    .read = mem_read,
    .write = mem_write,
};

int bdk_fs_mem_init(void)
{
    return bdk_fs_register_dev("mem", 0, &bdk_fs_mem_ops);
}

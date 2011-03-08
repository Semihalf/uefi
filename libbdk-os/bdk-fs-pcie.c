#include <bdk.h>
#include <fcntl.h>

static void *pcie_open(const char *name, int flags)
{
    long pcie_port = atoi(name);
    if ((pcie_port < 0) || (pcie_port >= 2))
        return NULL;

    return (void*)(pcie_port + 1);
}


static int pcie_close(__bdk_fs_file_t *handle)
{
    return 0;
}


static int pcie_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int pcie_port = (long)handle->fs_state - 1;
    uint64_t base = bdk_pcie_get_mem_base_address(pcie_port);
    memcpy(buffer, bdk_phys_to_ptr(base + handle->location), length);
    return length;
}


static int pcie_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int pcie_port = (long)handle->fs_state - 1;
    uint64_t base = bdk_pcie_get_mem_base_address(pcie_port);
    memcpy(bdk_phys_to_ptr(base + handle->location), buffer, length);
    return length;
}

const __bdk_fs_ops_t bdk_fs_pcie_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = pcie_open,
    .close = pcie_close,
    .lseek = NULL,
    .read = pcie_read,
    .write = pcie_write,
};


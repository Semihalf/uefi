#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_PCIE);

static void *pcie_open(const char *name, int flags)
{
    long pcie_port = atoi(name);
    if ((pcie_port < 0) || (pcie_port >= 4))
        return NULL;

    long state = pcie_port + 1;
    state += bdk_numa_local() << 8;
    return (void*)state;
}


static int pcie_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int pcie_port = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    uint64_t min_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    uint64_t max_address = min_address + bdk_pcie_get_base_size(node, pcie_port, BDK_PCIE_MEM_PREFETCH);
    if ((handle->location < min_address) || (handle->location + length > max_address))
    {
        bdk_error("PCIe address outside of SLI regions\n");
        return -1;
    }
    const void *ptr = bdk_phys_to_ptr(handle->location);
    memcpy(buffer, ptr, length);
    return length;
}


static int pcie_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int pcie_port = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    uint64_t min_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    uint64_t max_address = min_address + bdk_pcie_get_base_size(node, pcie_port, BDK_PCIE_MEM_PREFETCH);
    if ((handle->location < min_address) || (handle->location + length > max_address))
    {
        bdk_error("PCIe address outside of SLI regions\n");
        return -1;
    }
    void *ptr = bdk_phys_to_ptr(handle->location);
    memcpy(ptr, buffer, length);
    return length;
}

static const __bdk_fs_ops_t bdk_fs_pcie_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = pcie_open,
    .close = NULL,
    .read = pcie_read,
    .write = pcie_write,
};

int bdk_fs_pcie_init(void)
{
    return bdk_fs_register("/dev/pcie/", &bdk_fs_pcie_ops);
}

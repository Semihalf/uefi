#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_PCIE);

static void *pcie_open(const char *name, int flags)
{
    bdk_node_t node = bdk_numa_local();
    long pcie_port = atoi(name);
    int num_pcie = bdk_pcie_get_num_ports(node);

    if ((pcie_port < 0) || (pcie_port >= num_pcie))
        return NULL;

    long state = pcie_port + 1;
    state += node << 8;
    return (void*)state;
}


static int pcie_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int pcie_port = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    uint64_t min_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    uint64_t max_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_IO);
    if ((handle->location < min_address) || (handle->location + length > max_address))
    {
        bdk_error("PCIe address outside of SLI regions (0x%lx - 0x%lx)\n", min_address, max_address-1);
        return -1;
    }
    switch (length)
    {
        case 1:
            *(uint8_t *)buffer = bdk_read64_uint8(handle->location);
            break;
        case 2:
            *(uint16_t *)buffer = bdk_read64_uint16(handle->location);
            break;
        case 4:
            *(uint32_t *)buffer = bdk_read64_uint32(handle->location);
            break;
        case 8:
            *(uint64_t *)buffer = bdk_read64_uint64(handle->location);
            break;
        default:
        {
            const void *ptr = bdk_phys_to_ptr(handle->location);
            memcpy(buffer, ptr, length);
            break;
        }
    }
    return length;
}


static int pcie_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int pcie_port = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    uint64_t min_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    uint64_t max_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_IO);
    if ((handle->location < min_address) || (handle->location + length > max_address))
    {
        bdk_error("PCIe address outside of SLI regions (0x%lx - 0x%lx)\n", min_address, max_address-1);
        return -1;
    }
    switch (length)
    {
        case 1:
            bdk_write64_uint8(handle->location, *(uint8_t*)buffer);
            break;
        case 2:
            bdk_write64_uint16(handle->location, *(uint16_t*)buffer);
            break;
        case 4:
            bdk_write64_uint32(handle->location, *(uint32_t*)buffer);
            break;
        case 8:
            bdk_write64_uint64(handle->location, *(uint64_t*)buffer);
            break;
        default:
        {
            void *ptr = bdk_phys_to_ptr(handle->location);
            memcpy(ptr, buffer, length);
            break;
        }
    }
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

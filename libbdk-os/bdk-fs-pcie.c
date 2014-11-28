#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_PCIE);

static int pcie_read(__bdk_fs_dev_t *handle, void *buffer, int length)
{
    int pcie_port = handle->dev_index;
    bdk_node_t node = handle->dev_node;

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


static int pcie_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    int pcie_port = handle->dev_index;
    bdk_node_t node = handle->dev_node;

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

static const __bdk_fs_dev_ops_t bdk_fs_dev_pcie_ops =
{
    .open = NULL,
    .close = NULL,
    .read = pcie_read,
    .write = pcie_write,
};

int bdk_fs_pcie_init(void)
{
    int num_pcie = bdk_pcie_get_num_ports(bdk_numa_master());
    for (int p = 0; p < num_pcie; p++)
    {
        if (bdk_fs_register_dev("pcie", p, &bdk_fs_dev_pcie_ops))
            return -1;
    }
    return 0;
}

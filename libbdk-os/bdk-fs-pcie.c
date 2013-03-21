#include <bdk.h>
#include <fcntl.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_PCIE);

static void *pcie_open(const char *name, int flags)
{
    long pcie_port = atoi(name);
    if ((pcie_port < 0) || (pcie_port >= 2))
        return NULL;

    long state = pcie_port + 1;
    state += bdk_numa_id(BDK_NODE_LOCAL) << 8;
    return (void*)state;
}


static int pcie_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int pcie_port = (long)handle->fs_state - 1;
    bdk_node_t node = (long)handle->fs_state >> 8;
    volatile char in_progress = 1;

    bdk_dma_engine_header_t header;
    header.u64 = 0;
    header.s.lport = pcie_port;
    header.s.type = BDK_DMA_ENGINE_TRANSFER_INBOUND;
    header.s.addr = bdk_ptr_to_phys((void*)&in_progress);
    if (bdk_dma_engine_transfer(node, 0, header, bdk_ptr_to_phys(buffer), handle->location, length))
        return -1;

    /* Wait up to 2 seconds for the DMA to complete */
    uint64_t timeout = bdk_clock_get_rate(BDK_NODE_LOCAL, BDK_CLOCK_CORE)*2 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while (in_progress && (bdk_clock_get_count(BDK_CLOCK_CORE) < timeout))
        bdk_thread_yield();

    if (in_progress)
    {
        bdk_error("Timeout waiting for DMA to complete\n");
        return -1;
    }
    else
        return length;
}


static int pcie_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int pcie_port = (long)handle->fs_state - 1;
    bdk_node_t node = (long)handle->fs_state >> 8;
    volatile char in_progress = 1;

    bdk_dma_engine_header_t header;
    header.u64 = 0;
    header.s.lport = pcie_port;
    header.s.type = BDK_DMA_ENGINE_TRANSFER_OUTBOUND;
    header.s.addr = bdk_ptr_to_phys((void*)&in_progress);
    if (bdk_dma_engine_transfer(node, 0, header, bdk_ptr_to_phys((void*)buffer), handle->location, length))
        return -1;

    /* Wait up to 2 seconds for the DMA to complete */
    uint64_t timeout = bdk_clock_get_rate(BDK_NODE_LOCAL, BDK_CLOCK_CORE)*2 + bdk_clock_get_count(BDK_CLOCK_CORE);
    while (in_progress && (bdk_clock_get_count(BDK_CLOCK_CORE) < timeout))
        bdk_thread_yield();

    if (in_progress)
    {
        bdk_error("Timeout waiting for DMA to complete\n");
        return -1;
    }
    else
        return length;
}

static const __bdk_fs_ops_t bdk_fs_pcie_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = pcie_open,
    .close = NULL,
    .lseek = NULL,
    .read = pcie_read,
    .write = pcie_write,
};

int bdk_fs_pcie_init(void)
{
    return bdk_fs_register("/dev/pcie/", &bdk_fs_pcie_ops);
}

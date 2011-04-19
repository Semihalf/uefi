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
    volatile char in_progress = 1;

    bdk_dma_engine_header_t header;
    header.u64 = 0;
    header.s.lport = pcie_port;
    header.s.type = BDK_DMA_ENGINE_TRANSFER_INBOUND;
    header.s.addr = bdk_ptr_to_phys((void*)&in_progress);
    if (bdk_dma_engine_transfer(0, header, bdk_ptr_to_phys(buffer), handle->location, length))
        return -1;
    while (in_progress)
        bdk_thread_yield();
    return length;
}


static int pcie_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int pcie_port = (long)handle->fs_state - 1;
    volatile char in_progress = 1;

    bdk_dma_engine_header_t header;
    header.u64 = 0;
    header.s.lport = pcie_port;
    header.s.type = BDK_DMA_ENGINE_TRANSFER_OUTBOUND;
    header.s.addr = bdk_ptr_to_phys((void*)&in_progress);
    if (bdk_dma_engine_transfer(0, header, bdk_ptr_to_phys((void*)buffer), handle->location, length))
        return -1;
    while (in_progress)
        bdk_thread_yield();
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


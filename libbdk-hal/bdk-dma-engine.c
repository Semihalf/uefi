#include <bdk.h>

static bdk_cmd_queue_state_t dma_queue[BDK_NUMA_MAX_NODES][8];

/**
 * Return the number of DMA engimes supported by this chip
 *
 * @return Number of DMA engines
 */
int bdk_dma_engine_get_num(bdk_node_t node)
{
    return 8;
}

/**
 * Initialize the DMA engines for use
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_initialize(bdk_node_t node)
{
    int engine;

    for (engine=0; engine < bdk_dma_engine_get_num(node); engine++)
    {
        bdk_cmd_queue_result_t result;
        result = bdk_cmd_queue_initialize(node, dma_queue[node] + engine);
        if (result != BDK_CMD_QUEUE_SUCCESS)
            return -1;

        bdk_dpi_dmax_ibuff_saddr_t dpi_dmax_ibuff_saddr;
        dpi_dmax_ibuff_saddr.u64 = 0;
        dpi_dmax_ibuff_saddr.s.csize = bdk_fpa_get_block_size(node, BDK_FPA_OUTPUT_BUFFER_POOL)/8;
        /* Due to a conflict with the "idle" field on cn78xx, the saddr below
            uses the cn78xx specific field, but this works on all chips */
        dpi_dmax_ibuff_saddr.cn78xx.saddr = bdk_ptr_to_phys(bdk_cmd_queue_buffer(dma_queue[node] + engine)) >> 7;
        BDK_CSR_WRITE(node, BDK_DPI_DMAX_IBUFF_SADDR(engine), dpi_dmax_ibuff_saddr.u64);
    }

    bdk_dpi_engx_buf_t dpi_engx_buf;
    bdk_dpi_dma_control_t dma_control;
    bdk_dpi_ctl_t dpi_ctl;

    /* Give engine 0-4 1KB, and 5 3KB. This gives the packet engines better
        performance. Total must not exceed 8KB */
    dpi_engx_buf.u64 = 0;
    dpi_engx_buf.s.blks = 2;
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(0), dpi_engx_buf.u64);
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(1), dpi_engx_buf.u64);
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(2), dpi_engx_buf.u64);
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(3), dpi_engx_buf.u64);
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(4), dpi_engx_buf.u64);
    dpi_engx_buf.s.blks = 6;
    BDK_CSR_WRITE(node, BDK_DPI_ENGX_BUF(5), dpi_engx_buf.u64);

    dma_control.u64 = BDK_CSR_READ(node, BDK_DPI_DMA_CONTROL);
    dma_control.s.pkt_hp = 1;
    dma_control.s.pkt_en = 1;
    dma_control.s.dma_enb = 0x1f;
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        dma_control.cn78xx.ldwb = BDK_USE_DWB;
        dma_control.cn78xx.aura_ichk = BDK_FPA_OUTPUT_BUFFER_POOL;
    }
    else
    {
        dma_control.cn70xx.dwb_denb = BDK_USE_DWB;
        dma_control.cn70xx.dwb_ichk = bdk_fpa_get_block_size(node, BDK_FPA_OUTPUT_BUFFER_POOL)/128;
        dma_control.cn70xx.fpa_que = BDK_FPA_OUTPUT_BUFFER_POOL;
    }
    dma_control.s.o_es = 1;
    dma_control.s.o_mode = 1;
    BDK_CSR_WRITE(node, BDK_DPI_DMA_CONTROL, dma_control.u64);
    dpi_ctl.u64 = BDK_CSR_READ(node, BDK_DPI_CTL);
    dpi_ctl.s.en = 1;
    BDK_CSR_WRITE(node, BDK_DPI_CTL, dpi_ctl.u64);

    return 0;
}


/**
 * Shutdown all DMA engines. The engeines must be idle when this
 * function is called.
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_shutdown(bdk_node_t node)
{
    bdk_dpi_dma_control_t dma_control;
    dma_control.u64 = BDK_CSR_READ(node, BDK_DPI_DMA_CONTROL);
    dma_control.s.dma_enb = 0;
    BDK_CSR_WRITE(node, BDK_DPI_DMA_CONTROL, dma_control.u64);
    /* Make sure the disable completes */
    BDK_CSR_READ(node, BDK_DPI_DMA_CONTROL);

    for (int engine=0; engine < bdk_dma_engine_get_num(node); engine++)
    {
        bdk_cmd_queue_shutdown(dma_queue[node] + engine);
        BDK_CSR_WRITE(node, BDK_DPI_DMAX_IBUFF_SADDR(engine), 0);
    }

    return 0;
}


/**
 * Submit a series of DMA comamnd to the DMA engines.
 *
 * @param engine  Engine to submit to (0 to bdk_dma_engine_get_num()-1)
 * @param header  Command header
 * @param num_buffers
 *                The number of data pointers
 * @param buffers Comamnd data pointers
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_submit(bdk_node_t node, int engine, bdk_dma_engine_header_t header, int num_buffers, bdk_dma_engine_buffer_t buffers[])
{
    bdk_cmd_queue_result_t result;
    int cmd_count = 1;
    uint64_t cmds[num_buffers + 2];

    cmds[0] = header.word0.u64;
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        cmds[cmd_count++] = header.word1.u64;
    while (num_buffers--)
    {
        cmds[cmd_count++] = buffers->u64;
        buffers++;
    }

    /* Due to errata PCIE-13315, it is necessary to have the queue lock while we
        ring the doorbell for the DMA engines. This prevents doorbells from
        possibly arriving out of order with respect to the command queue
        entries */
    __bdk_cmd_queue_lock(dma_queue[node] + engine);
    result = bdk_cmd_queue_write(dma_queue[node] + engine, 0, cmd_count, cmds);
    /* This SYNCW is needed since the command queue didn't do locking, which
        normally implies the SYNCW. This one makes sure the command queue
        updates make it to L2 before we ring the doorbell */
    BDK_SYNCW;
    /* A syncw isn't needed here since the command queue did one as part of the queue unlock */
    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
        BDK_CSR_WRITE(node, BDK_DPI_DMAX_DBELL(engine), cmd_count);

    /* Here is the unlock for the above errata workaround */
    __bdk_cmd_queue_unlock(dma_queue[node] + engine);
    return result;
}


/**
 * @INTERNAL
 * Function used by bdk_dma_engine_transfer() to build the
 * internal address list.
 *
 * @param buffers Location to store the list
 * @param address Address to build list for
 * @param size    Length of the memory pointed to by address
 *
 * @return Number of internal pointer chunks created
 */
static inline int __bdk_dma_engine_build_internal_pointers(bdk_dma_engine_buffer_t *buffers, uint64_t address, int size)
{
    int segments = 0;
    while (size)
    {
        /* Each internal chunk can contain a maximum of 8191 bytes */
        int chunk = size;
        if (chunk > 8191)
            chunk = 8191;
        buffers[segments].u64 = 0;
        if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        {
            buffers[segments].internal_v3.size = chunk;
            buffers[segments].internal_v3.addr = address;
        }
        else
        {
            buffers[segments].internal_v1.size = chunk;
            buffers[segments].internal_v1.addr = address;
        }
        address += chunk;
        size -= chunk;
        segments++;
    }
    return segments;
}


/**
 * @INTERNAL
 * Function used by bdk_dma_engine_transfer() to build the PCI / PCIe address
 * list.
 * @param buffers Location to store the list
 * @param address Address to build list for
 * @param size    Length of the memory pointed to by address
 *
 * @return Number of PCI / PCIe address chunks created. The number of words used
 *         will be segments + (segments-1)/4 + 1.
 */
static inline int __bdk_dma_engine_build_external_pointers(bdk_dma_engine_buffer_t *buffers, uint64_t address, int size)
{
    const int MAX_SIZE = 65535;
    int segments = 0;
    while (size)
    {
        /* Each block of 4 PCI / PCIe pointers uses one dword for lengths followed by
            up to 4 addresses. This then repeats if more data is needed */
        buffers[0].u64 = 0;
        if (size <= MAX_SIZE)
        {
            /* Only one more segment needed */
            buffers[0].pcie_length.len0 = size;
            buffers[1].u64 = address;
            segments++;
            break;
        }
        else if (size <= MAX_SIZE * 2)
        {
            /* Two more segments needed */
            buffers[0].pcie_length.len0 = MAX_SIZE;
            buffers[0].pcie_length.len1 = size - MAX_SIZE;
            buffers[1].u64 = address;
            address += MAX_SIZE;
            buffers[2].u64 = address;
            segments+=2;
            break;
        }
        else if (size <= MAX_SIZE * 3)
        {
            /* Three more segments needed */
            buffers[0].pcie_length.len0 = MAX_SIZE;
            buffers[0].pcie_length.len1 = MAX_SIZE;
            buffers[0].pcie_length.len2 = size - MAX_SIZE * 2;
            buffers[1].u64 = address;
            address += MAX_SIZE;
            buffers[2].u64 = address;
            address += MAX_SIZE;
            buffers[3].u64 = address;
            segments+=3;
            break;
        }
        else if (size <= MAX_SIZE * 4)
        {
            /* Four more segments needed */
            buffers[0].pcie_length.len0 = MAX_SIZE;
            buffers[0].pcie_length.len1 = MAX_SIZE;
            buffers[0].pcie_length.len2 = MAX_SIZE;
            buffers[0].pcie_length.len3 = size - MAX_SIZE * 3;
            buffers[1].u64 = address;
            address += MAX_SIZE;
            buffers[2].u64 = address;
            address += MAX_SIZE;
            buffers[3].u64 = address;
            address += MAX_SIZE;
            buffers[4].u64 = address;
            segments+=4;
            break;
        }
        else
        {
            /* Five or more segments are needed */
            buffers[0].pcie_length.len0 = MAX_SIZE;
            buffers[0].pcie_length.len1 = MAX_SIZE;
            buffers[0].pcie_length.len2 = MAX_SIZE;
            buffers[0].pcie_length.len3 = MAX_SIZE;
            buffers[1].u64 = address;
            address += MAX_SIZE;
            buffers[2].u64 = address;
            address += MAX_SIZE;
            buffers[3].u64 = address;
            address += MAX_SIZE;
            buffers[4].u64 = address;
            address += MAX_SIZE;
            size -= MAX_SIZE*4;
            buffers += 5;
            segments+=4;
        }
    }
    return segments;
}


/**
 * Build the first and last pointers based on a DMA engine header
 * and submit them to the engine. The purpose of this function is
 * to simplify the building of DMA engine commands by automatically
 * converting a simple address and size into the appropriate internal
 * or PCI / PCIe address list. This function does not support gather lists,
 * so you will need to build your own lists in that case.
 *
 * @param engine Engine to submit to (0 to bdk_dma_engine_get_num()-1)
 * @param header DMA Command header. Note that the nfst and nlst fields do not
 *               need to be filled in. All other fields must be set properly.
 * @param first_address
 *               Address to use for the first pointers. In the case of INTERNAL,
 *               INBOUND, and OUTBOUND this is an Octeon memory address. In the
 *               case of EXTERNAL, this is the source PCI / PCIe address.
 * @param last_address
 *               Address to use for the last pointers. In the case of EXTERNAL,
 *               INBOUND, and OUTBOUND this is a PCI / PCIe address. In the
 *               case of INTERNAL, this is the Octeon memory destination address.
 * @param size   Size of the transfer to perform.
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_transfer(bdk_node_t node, int engine, bdk_dma_engine_header_t header,
                             uint64_t first_address, uint64_t last_address,
                             int size)
{
    bdk_dma_engine_buffer_t buffers[32];
    int words = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        switch (header.word0.v3.type)
        {
            case BDK_DMA_ENGINE_TRANSFER_INTERNAL:
                header.word0.v3.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
                words += header.word0.v3.nfst;
                header.word0.v3.nlst = __bdk_dma_engine_build_internal_pointers(buffers + words, last_address, size);
                words += header.word0.v3.nlst;
                break;
            case BDK_DMA_ENGINE_TRANSFER_INBOUND:
            case BDK_DMA_ENGINE_TRANSFER_OUTBOUND:
                header.word0.v3.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
                words += header.word0.v3.nfst;
                header.word0.v3.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
                words +=  header.word0.v3.nlst + ((header.word0.v3.nlst-1) >> 2) + 1;
                break;
            case BDK_DMA_ENGINE_TRANSFER_EXTERNAL:
                header.word0.v3.nfst = __bdk_dma_engine_build_external_pointers(buffers, first_address, size);
                words +=  header.word0.v3.nfst + ((header.word0.v3.nfst-1) >> 2) + 1;
                header.word0.v3.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
                words +=  header.word0.v3.nlst + ((header.word0.v3.nlst-1) >> 2) + 1;
                break;
        }
    }
    else
    {
        switch (header.word0.v1.type)
        {
            case BDK_DMA_ENGINE_TRANSFER_INTERNAL:
                header.word0.v1.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
                words += header.word0.v1.nfst;
                header.word0.v1.nlst = __bdk_dma_engine_build_internal_pointers(buffers + words, last_address, size);
                words += header.word0.v1.nlst;
                break;
            case BDK_DMA_ENGINE_TRANSFER_INBOUND:
            case BDK_DMA_ENGINE_TRANSFER_OUTBOUND:
                header.word0.v1.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
                words += header.word0.v1.nfst;
                header.word0.v1.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
                words +=  header.word0.v1.nlst + ((header.word0.v1.nlst-1) >> 2) + 1;
                break;
            case BDK_DMA_ENGINE_TRANSFER_EXTERNAL:
                header.word0.v1.nfst = __bdk_dma_engine_build_external_pointers(buffers, first_address, size);
                words +=  header.word0.v1.nfst + ((header.word0.v1.nfst-1) >> 2) + 1;
                header.word0.v1.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
                words +=  header.word0.v1.nlst + ((header.word0.v1.nlst-1) >> 2) + 1;
                break;
        }
    }
    return bdk_dma_engine_submit(node, engine, header, words, buffers);
}


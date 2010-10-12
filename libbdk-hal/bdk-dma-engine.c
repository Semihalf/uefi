#include <bdk.h>

/**
 * Return the number of DMA engimes supported by this chip
 *
 * @return Number of DMA engines
 */
int bdk_dma_engine_get_num(void)
{
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
            return 4;
        else
            return 5;
    }
    else
        return 8;
}

/**
 * Initialize the DMA engines for use
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_initialize(void)
{
    int engine;

    for (engine=0; engine < bdk_dma_engine_get_num(); engine++)
    {
        bdk_cmd_queue_result_t result;
        result = bdk_cmd_queue_initialize(BDK_CMD_QUEUE_DMA(engine),
                                           BDK_FPA_OUTPUT_BUFFER_POOL,
                                           bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL));
        if (result != BDK_CMD_QUEUE_SUCCESS)
            return -1;
        if (octeon_has_feature(OCTEON_FEATURE_NPEI))
        {
            bdk_npei_dmax_ibuff_saddr_t dmax_ibuff_saddr;
            dmax_ibuff_saddr.u64 = 0;
            dmax_ibuff_saddr.s.saddr = bdk_ptr_to_phys(bdk_cmd_queue_buffer(BDK_CMD_QUEUE_DMA(engine))) >> 7;
            BDK_CSR_WRITE(BDK_NPEI_DMAX_IBUFF_SADDR(engine), dmax_ibuff_saddr.u64);
        }
        else
        {
            bdk_dpi_dmax_ibuff_saddr_t dpi_dmax_ibuff_saddr;
            dpi_dmax_ibuff_saddr.u64 = 0;
            dpi_dmax_ibuff_saddr.s.csize = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/8;
            dpi_dmax_ibuff_saddr.s.saddr = bdk_ptr_to_phys(bdk_cmd_queue_buffer(BDK_CMD_QUEUE_DMA(engine))) >> 7;
            BDK_CSR_WRITE(BDK_DPI_DMAX_IBUFF_SADDR(engine), dpi_dmax_ibuff_saddr.u64);
        }
    }

    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_npei_dma_control_t dma_control;
        dma_control.u64 = 0;
        if (bdk_dma_engine_get_num() >= 5)
            dma_control.s.dma4_enb = 1;
        dma_control.s.dma3_enb = 1;
        dma_control.s.dma2_enb = 1;
        dma_control.s.dma1_enb = 1;
        dma_control.s.dma0_enb = 1;
        dma_control.s.o_mode = 1; /* Pull NS and RO from this register, not the pointers */
        //dma_control.s.dwb_denb = 1;
        //dma_control.s.dwb_ichk = BDK_FPA_OUTPUT_BUFFER_POOL_SIZE/128;
        dma_control.s.fpa_que = BDK_FPA_OUTPUT_BUFFER_POOL;
        dma_control.s.csize = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/8;
        BDK_CSR_WRITE(BDK_NPEI_DMA_CONTROL, dma_control.u64);
        /* As a workaround for errata PCIE-811 we only allow a single
            outstanding DMA read over PCIe at a time. This limits performance,
            but works in all cases. If you need higher performance, remove
            this code and implement the more complicated workaround documented
            in the errata. This only affects CN56XX pass 2.0 chips */
        if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS2_0))
        {
            bdk_npei_dma_pcie_req_num_t pcie_req_num;
            pcie_req_num.u64 = BDK_CSR_READ(BDK_NPEI_DMA_PCIE_REQ_NUM);
            pcie_req_num.s.dma_cnt = 1;
            BDK_CSR_WRITE(BDK_NPEI_DMA_PCIE_REQ_NUM, pcie_req_num.u64);
        }
    }
    else
    {
        bdk_dpi_engx_buf_t dpi_engx_buf;
        bdk_dpi_dma_control_t dma_control;
        bdk_dpi_ctl_t dpi_ctl;

        /* Give engine 0-4 1KB, and 5 3KB. This gives the packet engines better
            performance. Total must not exceed 8KB */
        dpi_engx_buf.u64 = 0;
        dpi_engx_buf.s.blks = 2;
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(0), dpi_engx_buf.u64);
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(1), dpi_engx_buf.u64);
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(2), dpi_engx_buf.u64);
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(3), dpi_engx_buf.u64);
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(4), dpi_engx_buf.u64);
        dpi_engx_buf.s.blks = 6;
        BDK_CSR_WRITE(BDK_DPI_ENGX_BUF(5), dpi_engx_buf.u64);

        dma_control.u64 = BDK_CSR_READ(BDK_DPI_DMA_CONTROL);
        dma_control.s.pkt_hp = 1;
        dma_control.s.pkt_en = 1;
        dma_control.s.dma_enb = 0x1f;
        dma_control.s.dwb_denb = 1;
        dma_control.s.dwb_ichk = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/128;
        dma_control.s.fpa_que = BDK_FPA_OUTPUT_BUFFER_POOL;
        dma_control.s.o_mode = 1;
        BDK_CSR_WRITE(BDK_DPI_DMA_CONTROL, dma_control.u64);
        dpi_ctl.u64 = BDK_CSR_READ(BDK_DPI_CTL);
        dpi_ctl.s.en = 1;
        BDK_CSR_WRITE(BDK_DPI_CTL, dpi_ctl.u64);
    }

    return 0;
}


/**
 * Shutdown all DMA engines. The engeines must be idle when this
 * function is called.
 *
 * @return Zero on success, negative on failure
 */
int bdk_dma_engine_shutdown(void)
{
    int engine;

    for (engine=0; engine < bdk_dma_engine_get_num(); engine++)
    {
        if (bdk_cmd_queue_length(BDK_CMD_QUEUE_DMA(engine)))
        {
            bdk_error("bdk_dma_engine_shutdown: Engine not idle.\n");
            return -1;
        }
    }

    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_npei_dma_control_t dma_control;
        dma_control.u64 = BDK_CSR_READ(BDK_NPEI_DMA_CONTROL);
        if (bdk_dma_engine_get_num() >= 5)
            dma_control.s.dma4_enb = 0;
        dma_control.s.dma3_enb = 0;
        dma_control.s.dma2_enb = 0;
        dma_control.s.dma1_enb = 0;
        dma_control.s.dma0_enb = 0;
        BDK_CSR_WRITE(BDK_NPEI_DMA_CONTROL, dma_control.u64);
        /* Make sure the disable completes */
        BDK_CSR_READ(BDK_NPEI_DMA_CONTROL);
    }
    else
    {
        bdk_dpi_dma_control_t dma_control;
        dma_control.u64 = BDK_CSR_READ(BDK_DPI_DMA_CONTROL);
        dma_control.s.dma_enb = 0;
        BDK_CSR_WRITE(BDK_DPI_DMA_CONTROL, dma_control.u64);
        /* Make sure the disable completes */
        BDK_CSR_READ(BDK_DPI_DMA_CONTROL);
    }

    for (engine=0; engine < bdk_dma_engine_get_num(); engine++)
    {
        bdk_cmd_queue_shutdown(BDK_CMD_QUEUE_DMA(engine));
        if (octeon_has_feature(OCTEON_FEATURE_NPEI))
            BDK_CSR_WRITE(BDK_NPEI_DMAX_IBUFF_SADDR(engine), 0);
        else
            BDK_CSR_WRITE(BDK_DPI_DMAX_IBUFF_SADDR(engine), 0);
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
int bdk_dma_engine_submit(int engine, bdk_dma_engine_header_t header, int num_buffers, bdk_dma_engine_buffer_t buffers[])
{
    bdk_cmd_queue_result_t result;
    int cmd_count = 1;
    uint64_t cmds[num_buffers + 1];

    if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X))
    {
        /* Check for Errata PCIe-604 */
        if ((header.s.nfst > 11) || (header.s.nlst > 11) || (header.s.nfst + header.s.nlst > 15))
        {
            bdk_error("DMA engine submit too large\n");
            return -1;
        }
    }

    cmds[0] = header.u64;
    while (num_buffers--)
    {
        cmds[cmd_count++] = buffers->u64;
        buffers++;
    }

    /* Due to errata PCIE-13315, it is necessary to have the queue lock while we
        ring the doorbell for the DMA engines. This prevents doorbells from
        possibly arriving out of order with respect to the command queue
        entries */
    __bdk_cmd_queue_lock(BDK_CMD_QUEUE_DMA(engine), __bdk_cmd_queue_get_state(BDK_CMD_QUEUE_DMA(engine)));
    result = bdk_cmd_queue_write(BDK_CMD_QUEUE_DMA(engine), 0, cmd_count, cmds);
    /* This SYNCW is needed since the command queue didn't do locking, which
        normally implies the SYNCW. This one makes sure the command queue
        updates make it to L2 before we ring the doorbell */
    BDK_SYNCW;
    /* A syncw isn't needed here since the command queue did one as part of the queue unlock */
    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        if (octeon_has_feature(OCTEON_FEATURE_NPEI))
        {
            /* DMA doorbells are 32bit writes in little endian space. This means we need to xor the address with 4 */
            bdk_write64_uint32(BDK_NPEI_DMAX_DBELL(engine)^4, cmd_count);
        }
        else
            BDK_CSR_WRITE(BDK_DPI_DMAX_DBELL(engine), cmd_count);
    }
    /* Here is the unlock for the above errata workaround */
    __bdk_cmd_queue_unlock(__bdk_cmd_queue_get_state(BDK_CMD_QUEUE_DMA(engine)));
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
        buffers[segments].internal.size = chunk;
        buffers[segments].internal.addr = address;
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
 * converting a simple address and size into the apropriate internal
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
int bdk_dma_engine_transfer(int engine, bdk_dma_engine_header_t header,
                             uint64_t first_address, uint64_t last_address,
                             int size)
{
    bdk_dma_engine_buffer_t buffers[32];
    int words = 0;

    switch (header.s.type)
    {
        case BDK_DMA_ENGINE_TRANSFER_INTERNAL:
            header.s.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
            words += header.s.nfst;
            header.s.nlst = __bdk_dma_engine_build_internal_pointers(buffers + words, last_address, size);
            words += header.s.nlst;
            break;
        case BDK_DMA_ENGINE_TRANSFER_INBOUND:
        case BDK_DMA_ENGINE_TRANSFER_OUTBOUND:
            header.s.nfst = __bdk_dma_engine_build_internal_pointers(buffers, first_address, size);
            words += header.s.nfst;
            header.s.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
            words +=  header.s.nlst + ((header.s.nlst-1) >> 2) + 1;
            break;
        case BDK_DMA_ENGINE_TRANSFER_EXTERNAL:
            header.s.nfst = __bdk_dma_engine_build_external_pointers(buffers, first_address, size);
            words +=  header.s.nfst + ((header.s.nfst-1) >> 2) + 1;
            header.s.nlst = __bdk_dma_engine_build_external_pointers(buffers + words, last_address, size);
            words +=  header.s.nlst + ((header.s.nlst-1) >> 2) + 1;
            break;
    }
    return bdk_dma_engine_submit(engine, header, words, buffers);
}


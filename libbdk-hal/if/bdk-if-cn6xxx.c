#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

#define USE_PER_PORT_BACKPRESSURE 1
#define PIP_IP_OFFSET 2
#define BDK_PKO_MAX_OUTPUT_QUEUES 256
static __bdk_if_port_t *__bdk_if_ipd_map[0x1000];
static int bdk_pko_next_free_queue = 0;

/**
 * One time init of global Packet Input
 *
 * @return Zero on success, negative on failure
 */
static int pki_global_init(bdk_node_t node)
{
    bdk_zero_memory(__bdk_if_ipd_map, sizeof(__bdk_if_ipd_map));

    /* Skip one cache line so we have room to put the WQE at the
        beginning of the packet buffer */
    BDK_CSR_MODIFY(c, node, BDK_IPD_1ST_MBUFF_SKIP,
        c.s.skip_sz = 16);
    /* Set the back field in the first pointer to account for the
        cache line we skipped */
    BDK_CSR_MODIFY(c, node, BDK_IPD_1ST_NEXT_PTR_BACK,
        c.s.back = 1);

    /* Chained buffers don't have any skip */
    BDK_CSR_MODIFY(c, node, BDK_IPD_NOT_1ST_MBUFF_SKIP,
        c.s.skip_sz = 0);
    /* Set the chained back field to match*/
    BDK_CSR_MODIFY(c, node, BDK_IPD_2ND_NEXT_PTR_BACK,
        c.s.back = 0);

    /* Set the Buffer pool size */
    BDK_CSR_MODIFY(c, node, BDK_IPD_PACKET_MBUFF_SIZE,
        c.s.mb_size = bdk_fpa_get_block_size(node, BDK_FPA_PACKET_POOL)/8);

    BDK_CSR_MODIFY(c, node, BDK_IPD_CTL_STATUS,
        c.s.no_wptr = 1;    /* Store WQE in packet */
        c.s.len_m8 = 1;     /* Use correct lengths */
        c.s.addpkt = USE_PER_PORT_BACKPRESSURE; /* Increment backpressure accounting for every packet */
        c.s.pbp_en = 1;     /* Enable per port backpressure accounting */
        c.s.opc_mode = 1);  /* Store into L2 */

    /* Needed to support dynamic short */
    BDK_CSR_WRITE(node, BDK_PIP_IP_OFFSET, PIP_IP_OFFSET);

    /* Configure to allow max sized frames */
    BDK_CSR_MODIFY(pip_frm_len_chkx, node, BDK_PIP_FRM_LEN_CHKX(0),
        pip_frm_len_chkx.s.minlen = 64;
        pip_frm_len_chkx.s.maxlen = -1);

    /* Don't use clear on read as it has problems on CN68XX pass 1.x */
    BDK_CSR_MODIFY(c, node, BDK_PIP_STAT_CTL,
        c.s.rdclr = 0);

    int thresh_pass = 64;
    int thresh_drop = 32;

    for (int queue=0; queue<8; queue++)
    {
        /* Set RED to begin dropping packets when we're low on buffers */
        BDK_CSR_MODIFY(c, node, BDK_IPD_QOSX_RED_MARKS(queue),
            c.s.drop = thresh_drop;
            c.s.pass = thresh_pass);

        /* Use the actual queue 0 counter, not the average */
        BDK_CSR_MODIFY(c, node, BDK_IPD_RED_QUEX_PARAM(queue),
            c.s.prb_con = (255ul<<24) / (thresh_pass - thresh_drop);
            c.s.avg_con = 1;
            c.s.new_con = 255;
            c.s.use_pcnt = 1);
    }

    return 0;
}

/**
 * Configure packet input for a specific port. This is called for each
 * port on every interface that is connected to packet input.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pki_port_init(bdk_if_handle_t handle)
{
    static int qos = 0;

    if (handle->ipd_port != -1)
    {
        handle->pknd = handle->ipd_port;
        if (handle->ipd_port >= 0x1000)
            bdk_fatal("IPD port too large for mapping table\n");
        __bdk_if_ipd_map[handle->ipd_port] = handle;
    }

    /* Have each port go to a different SSO queue */
    BDK_CSR_MODIFY(port_config, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
        port_config.s.dyn_rs = 1;
        port_config.s.qos = qos;
        port_config.s.mode = bdk_config_get(BDK_CONFIG_INPUT_PORT_SKIP_MODE));

    /* Process the headers and place the IP header in the work queue */
    BDK_CSR_MODIFY(tag_config, handle->node, BDK_PIP_PRT_TAGX(handle->pknd),
        tag_config.s.inc_prt_flag  = 1;
        tag_config.s.tcp6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.tcp4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.ip6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.ip4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.non_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
        tag_config.s.grp = 0);

    {
        /* Don't strip off FCS. We might want to see it when debugging */
        BDK_CSR_MODIFY(c, handle->node, BDK_IPD_SUB_PORT_FCS, c.u64 &= ~(1ull<<(handle->pknd)));
        if (handle->ipd_port < 36)
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_PORTX_BP_PAGE_CNT(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_RED_PORT_ENABLE, c.s.prt_enb |= 1ull<<handle->ipd_port);
        }
        else if (handle->ipd_port < 40)
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_PORTX_BP_PAGE_CNT2(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_RED_PORT_ENABLE2, c.s.prt_enb |= 1ull<<(handle->ipd_port-36));
        }
        else
        {
            /* Backpressure when this port has 256 buffers in use */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_PORTX_BP_PAGE_CNT3(handle->ipd_port),
                c.s.bp_enb = USE_PER_PORT_BACKPRESSURE;
                c.s.page_cnt = 1);
            /* Enable RED dropping */
            BDK_CSR_MODIFY(c, handle->node, BDK_IPD_RED_PORT_ENABLE2, c.s.prt_enb |= 1ull<<(handle->ipd_port-36));
        }
    }

    /* Have the next port use a different input queue */
    qos = (qos + 1) & 7;

    return 0;
}

/**
 * Enable PKI after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pki_enable(bdk_node_t node)
{
    /* Enable IPD */
    BDK_CSR_MODIFY(c, node, BDK_IPD_CTL_STATUS, c.s.ipd_en = 1);
    return 0;
}

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
static int pko_global_init(bdk_node_t node)
{
    /* We can't use the normal FPA queue size here as the command queue aren't
       setup yet and the FPA pool hasn't been configured yet */
    BDK_CSR_DEFINE(config, BDK_PKO_REG_CMD_BUF);
    config.u64 = 0;
    config.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    config.s.size = bdk_config_get(BDK_CONFIG_FPA_POOL_SIZE0 + BDK_FPA_OUTPUT_BUFFER_POOL) / 8;
    BDK_CSR_WRITE(node, BDK_PKO_REG_CMD_BUF, config.u64);

    /* Clear out all queue state */
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_QUEUE_PTRS);
        BDK_CSR_DEFINE(ptrs1, BDK_PKO_REG_QUEUE_PTRS1);

        ptrs.u64 = 0;
        ptrs.s.tail = 1;
        ptrs.s.port = -1;
        ptrs1.u64 = 0;

        for (int i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        {
            ptrs1.s.qid7 = i>>7;
            ptrs.s.queue = i & 0x3f;
            BDK_CSR_WRITE(node, BDK_PKO_REG_QUEUE_PTRS1, ptrs1.u64);
            BDK_CSR_WRITE(node, BDK_PKO_MEM_QUEUE_PTRS, ptrs.u64);
        }
    }
    return 0;
}

/**
 * Configure PKO for a specific port. This is called for each
 * port on every interface that connects to PKO.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pko_port_init(bdk_if_handle_t handle)
{
    int num_queues = sizeof(handle->cmd_queue) / sizeof(handle->cmd_queue[0]);
    int base_queue = bdk_pko_next_free_queue;
    int num_static_queues = 0;
    bdk_pko_next_free_queue += num_queues;

    handle->pko_port = handle->ipd_port;


    for (int queue=0; queue<num_queues; queue++)
    {
        if (bdk_cmd_queue_initialize(handle->node, &handle->cmd_queue[queue]))
            return -1;
        void *buf_ptr = bdk_cmd_queue_buffer(&handle->cmd_queue[queue]);

        {
            BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_QUEUE_PTRS);
            BDK_CSR_DEFINE(ptrs1, BDK_PKO_REG_QUEUE_PTRS1);

            ptrs1.u64 = 0;
            ptrs1.s.idx3    = queue >> 3;
            ptrs1.s.qid7    = (base_queue + queue) >> 7;

            ptrs.u64 = 0;
            ptrs.s.s_tail   = queue == (num_static_queues - 1);
            ptrs.s.static_p = num_static_queues > 0;
            ptrs.s.static_q = queue < num_static_queues;
            ptrs.s.qos_mask = 0xff;
            ptrs.s.buf_ptr  = bdk_ptr_to_phys(buf_ptr);
            ptrs.s.tail     = queue == (num_queues - 1);
            ptrs.s.index    = queue;
            ptrs.s.port     = handle->pko_port;
            ptrs.s.queue    = base_queue + queue;

            BDK_CSR_WRITE(handle->node, BDK_PKO_REG_QUEUE_PTRS1, ptrs1.u64);
            BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_QUEUE_PTRS, ptrs.u64);
        }
    }
    handle->pko_queue = base_queue;

    BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_COUNT0, handle->pko_port);
    BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_COUNT1, handle->pko_port);

    return 0;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pko_enable(bdk_node_t node)
{
    extern int bdk_pko_next_free_queue;
    bdk_pko_reg_flags_t flags;

    /* If we aren't using all of the queues optimize PKO's internal memory */
    if (bdk_pko_next_free_queue <= 64)
        BDK_CSR_WRITE(node, BDK_PKO_REG_QUEUE_MODE, 2);
    else if (bdk_pko_next_free_queue <= 128)
        BDK_CSR_WRITE(node, BDK_PKO_REG_QUEUE_MODE, 1);

    flags.u64 = BDK_CSR_READ(node, BDK_PKO_REG_FLAGS);
    if (flags.s.ena_pko)
        bdk_warn("Enabling PKO when PKO already enabled.\n");

    flags.s.ena_dwb = BDK_USE_DWB;
    flags.s.ena_pko = 1;
    flags.s.store_be =1;  /* always enable big endian for 3-word command. Does nothing for 2-word */
    BDK_CSR_WRITE(node, BDK_PKO_REG_FLAGS, flags.u64);
    return 0;
}

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
static int sso_init(bdk_node_t node)
{
    /* Disable tagwait FAU timeout. This needs to be done before anyone might
        start packet output using tags */
    bdk_iob_fau_timeout_t fau_to;
    fau_to.u64 = 0;
    fau_to.s.tout_val = 0xfff;
    fau_to.s.tout_enb = 0;
    BDK_CSR_WRITE(node, BDK_IOB_FAU_TIMEOUT, fau_to.u64);

    /* Set work timeout to 1k cycles. Due to a bug in Octeon 2, reads
        from scratch will always wait for get_work to complete, so we
        want this fast */
    BDK_CSR_MODIFY(c, node, BDK_SSO_NW_TIM,
        c.s.nw_tim = 0);
    return 0;
}

/**
 * Convert a WQE into a BDK packet
 *
 * @param work   Pointer to WQE to convert
 * @param packet Packet to receive the data
 *
 * @return Zero on success, negative on failure
 */
static int sso_wqe_to_packet(const void *work, bdk_if_packet_t *packet)
{
    const bdk_wqe_t *wqe = work;

    /* Get the IPD port number */
    int ipd_port = wqe->word1.v1.ipprt;

    packet->if_handle = __bdk_if_ipd_map[ipd_port];
    packet->length = wqe->word1.v1.len;
    if (bdk_unlikely(wqe->word2.v1.re))
        packet->rx_error = wqe->word2.v1.opcode;
    else
        packet->rx_error = 0;

    if (bdk_likely(wqe->word2.v1.bufs == 0))
    {
        packet->segments = 1;
        packet->packet.u64 = 0;
        packet->packet.v1.back = 0;
        packet->packet.v1.pool = BDK_FPA_PACKET_POOL;
        packet->packet.v1.size = 128; // FIXME packet size
        packet->packet.v1.addr = bdk_ptr_to_phys((void*)&(wqe->word4));
        if (bdk_likely(!wqe->word2.v1.ni))
        {
            packet->packet.v1.addr += (PIP_IP_OFFSET<<3) - wqe->word2.v1.ip_offset;
            packet->packet.v1.addr += (wqe->word2.v1.v6^1)<<2;
        }
        else
        {
            /* WARNING: This code assume that the packet is not RAW. If it was,
                we would use PIP_GBL_CFG[RAW_SHF] instead of
                PIP_GBL_CFG[NIP_SHF] */
            BDK_CSR_INIT(pip_gbl_cfg, bdk_numa_local(), BDK_PIP_GBL_CFG);
            packet->packet.v1.addr += pip_gbl_cfg.s.nip_shf;
        }
    }
    else
    {
        packet->segments = wqe->word2.v1.bufs;
        packet->packet = wqe->packet_ptr;
    }
    packet->aura = packet->packet.v1.pool;

    if (bdk_unlikely(!packet->if_handle))
    {
        bdk_error("Unable to find IF for ipd_port %d\n", ipd_port);
        return -1;
    }

    if (USE_PER_PORT_BACKPRESSURE)
    {
        /* Subtract this packet's segemnts from the port's IPD usage */
        BDK_CSR_DEFINE(page_cnt, BDK_IPD_SUB_PORT_BP_PAGE_CNT);
        page_cnt.u64 = 0;
        page_cnt.s.port = packet->if_handle->pknd;
        page_cnt.s.page_cnt = (wqe->word2.v1.bufs == 0) ? -1 : -packet->segments-1;
        BDK_CSR_WRITE(packet->if_handle->node, BDK_IPD_SUB_PORT_BP_PAGE_CNT, page_cnt.u64);
    }
    return 0;
}


/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
static int pko_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    /**
     * Structure of the first packet output command word.
     */
    typedef union
    {
        uint64_t                u64;
        struct
        {
            bdk_fau_op_size_t   size1       : 2; /**< The size of the reg1 operation - could be 8, 16, 32, or 64 bits */
            bdk_fau_op_size_t   size0       : 2; /**< The size of the reg0 operation - could be 8, 16, 32, or 64 bits */
            uint64_t            subone1     : 1; /**< If set, subtract 1, if clear, subtract packet size */
            uint64_t            reg1        :11; /**< The register, subtract will be done if reg1 is non-zero */
            uint64_t            subone0     : 1; /**< If set, subtract 1, if clear, subtract packet size */
            uint64_t            reg0        :11; /**< The register, subtract will be done if reg0 is non-zero */
            uint64_t            le          : 1; /**< When set, interpret segment pointer and segment bytes in little endian order */
            uint64_t            n2          : 1; /**< When set, packet data not allocated in L2 cache by PKO */
            uint64_t            wqp         : 1; /**< If set and rsp is set, word3 contains a pointer to a work queue entry */
            uint64_t            rsp         : 1; /**< If set, the hardware will send a response when done */
            uint64_t            gather      : 1; /**< If set, the supplied pkt_ptr is really a pointer to a list of pkt_ptr's */
            uint64_t            ipoffp1     : 7; /**< If ipoffp1 is non zero, (ipoffp1-1) is the number of bytes to IP header,
                                                    and the hardware will calculate and insert the  UDP/TCP checksum */
            uint64_t            ignore_i    : 1; /**< If set, ignore the I bit (force to zero) from all pointer structures */
            uint64_t            dontfree    : 1; /**< If clear, the hardware will attempt to free the buffers containing the packet */
            uint64_t            segs        : 6; /**< The total number of segs in the packet, if gather set, also gather list length */
            uint64_t            total_bytes :16; /**< Including L2, but no trailing CRC */
        } s;
    } bdk_pko_command_word0_t;

    /**
     * This structure defines the address to use on a packet enqueue
     */
    typedef union
    {
        uint64_t                u64;
        struct
        {
            uint64_t            mem_space       : 2;    /**< Must BDK_IO_SEG */
            uint64_t            reserved_49_61  : 13;
            uint64_t            is_io           : 1;    /**< Must be one */
            uint64_t            did             : 8;    /**< The ID of the device on the non-coherent bus */
            uint64_t            reserved_21_39  : 19;
            uint64_t            port            : 9;    /**< The hardware likes to have the output port in addition to the output queue */
            uint64_t            queue           : 9;    /**< The output queue to send the packet to (0-127 are legal) */
            uint64_t            reserved_0_2    : 3;
       } s;
    } bdk_pko_doorbell_address_t;

    if (bdk_unlikely(packet->segments >= 64))
    {
        bdk_error("PKO can't transmit packets with more than 63 segments\n");
        return -1;
    }

    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.dontfree = packet->packet.v1.i;
    pko_command.s.ignore_i = 1;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;
    bdk_buf_ptr_t buf = packet->packet;
    buf.v1.i = 0;

    bdk_cmd_queue_result_t result = bdk_cmd_queue_write2(&handle->cmd_queue[0], 1, pko_command.u64, buf.u64);

    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        bdk_pko_doorbell_address_t ptr;
        ptr.u64          = 0;
        ptr.s.mem_space  = 2;
        ptr.s.did        = 0x52;
        ptr.s.is_io      = 1;
        ptr.s.port       = handle->pko_port;
        ptr.s.queue      = handle->pko_queue;
        BDK_SYNCW;  /* Need to make sure output queue data is in DRAM before doorbell write */
        bdk_write64_uint64(ptr.u64, 2);

        /* Updates the statistics in software if need to. The simulator
            doesn't implement the hardware counters */
        if (bdk_unlikely(bdk_is_simulation()))
        {
            int octets = pko_command.s.total_bytes;
            if (handle->flags & BDK_IF_FLAGS_HAS_FCS)
                octets += 4;
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.octets, octets);
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.packets, 1);
        }
    }
    return result;
}

/**
 * Allocate a packet with buffers for the supplied amount of data
 *
 * @param packet Packet to get buffers for
 * @param length Length of the final packet in bytes
 *
 * @return Zero on success, negative on failure.
 */
static int packet_alloc(bdk_if_packet_t *packet, int length)
{
    const int FPA_SIZE = bdk_fpa_get_block_size(packet->if_handle->node, BDK_FPA_PACKET_POOL);
    bdk_buf_ptr_t *buffer_ptr = &packet->packet;

    /* Start off with an empty packet */
    packet->length = 0;
    packet->segments = 0;
    packet->aura = BDK_FPA_PACKET_POOL;

    /* Add buffers while the packet is less that the needed length */
    while (packet->length < length)
    {
        void *buffer = bdk_fpa_alloc(packet->if_handle->node, BDK_FPA_PACKET_POOL);
        if (!buffer)
        {
            /* Free all buffers allocates so far */
            bdk_if_free(packet);
            return -1;
        }
        /* Fill in the packet link pointer */
        buffer_ptr->u64 = 0;
        buffer_ptr->v1.pool = BDK_FPA_PACKET_POOL;
        buffer_ptr->v1.size = FPA_SIZE - 8;
        buffer_ptr->v1.addr = bdk_ptr_to_phys(buffer) + 8;
        packet->length += FPA_SIZE - 8;
        packet->segments++;
        /* The next chain pointer is at the beginning of the buffer */
        buffer_ptr = buffer;
    }
    /* Fix length as it will likely be too large since we increment in FPA
        chunks */
    packet->length = length;
    return 0;
}

/**
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
static void packet_free(bdk_if_packet_t *packet)
{
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    bdk_buf_ptr_t next_buffer_ptr;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Remember the back pointer is in cache lines, not 64bit words */
        uint64_t start_of_buffer = ((buffer_ptr.v1.addr >> 7) - buffer_ptr.v1.back) << 7;
        /* Read pointer to next buffer before we free the current buffer. */
        if (number_buffers)
            next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v1.addr - 8);
        __bdk_fpa_raw_free(packet->if_handle->node, start_of_buffer, buffer_ptr.v1.pool, 0);
        buffer_ptr = next_buffer_ptr;
    }
}

/**
 * Read data from a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to read from.
 * @param location Location to read
 * @param length   Length of data to read
 * @param data     Buffer to receive the data
 */
static void packet_read(bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v1.size)
    {
        location -= buffer_ptr.v1.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v1.addr - 8);
    }

    const uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v1.addr);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v1.size))
        {
            location -= buffer_ptr.v1.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v1.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v1.addr);
        }
    }
}

/**
 * Write data into a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to write to.
 * @param location Location to write
 * @param length   Length of data to write
 * @param data     Data to write
 */
static void packet_write(bdk_if_packet_t *packet, int location, int length, const void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to write past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v1.size)
    {
        location -= buffer_ptr.v1.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v1.addr - 8);
    }

    uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v1.addr);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v1.size))
        {
            location -= buffer_ptr.v1.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v1.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v1.addr);
        }
    }
}

__bdk_if_global_ops_t __bdk_if_global_ops_cn6xxx = {
    .pki_global_init = pki_global_init,
    .pki_port_init = pki_port_init,
    .pki_enable = pki_enable,
    .pko_global_init = pko_global_init,
    .pko_port_init = pko_port_init,
    .pko_enable = pko_enable,
    .sso_init = sso_init,
    .sso_wqe_to_packet = sso_wqe_to_packet,
    .pko_transmit = pko_transmit,
    .packet_alloc = packet_alloc,
    .packet_free = packet_free,
    .packet_read = packet_read,
    .packet_write = packet_write,
};


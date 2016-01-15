#include <bdk.h>
#include <malloc.h>

#define MAX_VNIC 128 /* CN88XX = 128, CN83XX = 32, CN81XX = 8 */
#define MAX_MTU 9212
#define CQ_ENTRIES_QSIZE 0
#define CQ_ENTRIES (1024 << CQ_ENTRIES_QSIZE)
#define SQ_ENTRIES_QSIZE 0
#define SQ_ENTRIES (1024 << SQ_ENTRIES_QSIZE)
#define RBDR_ENTRIES_QSIZE 0
#define RBDR_ENTRIES (8192 << RBDR_ENTRIES_QSIZE)

typedef struct
{
    /* VNIC related config */
    bdk_node_t  node;           /* Node the NIC is on */
    int         vnic;           /* NIC index number */
    bdk_nic_type_t ntype;       /* They type of device this NIC is connected to */
    int         qos;            /* NIC QoS level (0-7). We only use zero */
    int         cq;             /* Which complete queue to use. The second index is always zero */
    int         rbdr;           /* Which receive descriptor to use. The second index is always zero */
    int         shares_cq;      /* This device shares a CQ/RBDR with another port */
    bdk_if_handle_t handle;     /* bdk-if handle associated with this NIC */

    /* Transmit */
    void *      sq_base;        /* Pointer to the beginning of the SQ in memory */
    int         sq_loc;         /* Location where the next send should go */
    int         sq_available;   /* Amount of space left in the queue (fuzzy) */
} nic_t;

typedef struct
{
    void *base;
    int loc;
} nic_rbdr_state_t;

typedef struct
{
    int num_vnics;
    int next_free_vnic;
    int next_free_cq;
    int next_free_rbdr;
    int next_free_cpi;
    int next_free_rssi;
    nic_t *nic_map[MAX_VNIC];
} nic_node_state_t;

static nic_node_state_t *global_node_state[BDK_NUMA_MAX_NODES];

/**
 * Setup a receive Completion Queue (CQ). CQ can be shared across multiple NICs
 * to save space. This happens if the NIC has "shares_cq" set.
 *
 * @param nic    NIC to setup
 *
 * @return Zero on success, negative on failure
 */
static int vnic_setup_cq(nic_t *nic)
{
    nic_node_state_t *node_state = global_node_state[nic->node];
    int cq_idx = 0;

    /* CN88XX pass 1.x had the drop level reset value too low */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_CQM_CFG,
        c.s.drop_level = 128);

    if (nic->shares_cq)
    {
        /* These are allocated linearly. We know that the first port was
           the last guy to allcoate a CQ */
        nic->cq = node_state->next_free_cq - 1;
    }
    else
    {
        if (node_state->next_free_cq >= node_state->num_vnics)
        {
            bdk_error("%s: No free completion queues\n", nic->handle->name);
            return -1;
        }
        /* Note that the completion queue requires 512 byte alignment */
        void *cq_memory = memalign(512, 512 * CQ_ENTRIES);
        if (!cq_memory)
        {
            bdk_error("%s: Failed to allocate memory for completion queue\n", nic->handle->name);
            return -1;
        }
        nic->cq = node_state->next_free_cq++;
        /* Configure the completion queue (CQ) */
        BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_CQX_BASE(nic->cq, cq_idx),
            bdk_ptr_to_phys(cq_memory));
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_QSX_CQX_CFG(nic->cq, cq_idx),
            c.s.ena = 1;
            c.s.caching = 1;
            c.s.qsize = CQ_ENTRIES_QSIZE);
    }

    /* Configure our vnic to send to the CQ */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_SQX_CFG(nic->vnic, nic->qos),
        c.s.cq_qs = nic->cq;
        c.s.cq_idx = cq_idx);
    return 0;
}

/**
 * Add buffers to a receive buffer descriptor ring (RBDR). Note that RBDRs are
 * shared between NICs using the same CQ.
 *
 * @param nic       NIC using the RBDR
 * @param rbdr_free Number of buffers to add
 */
static void vnic_fill_receive_buffer(const nic_t *nic, int rbdr_free)
{
    const int buffer_size = bdk_config_get_int(BDK_CONFIG_PACKET_BUFFER_SIZE);
    int rbdr = nic->rbdr;
    int rbdr_idx = 0;

    BDK_CSR_INIT(rbdr_base, nic->node, BDK_NIC_QSX_RBDRX_BASE(rbdr, rbdr_idx));
    BDK_CSR_INIT(rbdr_tail, nic->node, BDK_NIC_QSX_RBDRX_TAIL(rbdr, rbdr_idx));

    uint64_t *rbdr_ptr = bdk_phys_to_ptr(rbdr_base.u);
    int loc = rbdr_tail.s.tail_ptr;

    int added = 0;
    for (int i = 0; i < rbdr_free; i++)
    {
        bdk_if_packet_t packet;
        if (bdk_if_alloc(&packet, buffer_size))
        {
            bdk_error("%s: Failed to allocate buffer for RX ring (added %d)\n", nic->handle->name, added);
            break;
        }
        rbdr_ptr[loc] = packet.packet[0].s.address;
        loc++;
        loc &= RBDR_ENTRIES - 1;
        added++;
    }
    BDK_WMB;
    BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_RBDRX_DOOR(rbdr, rbdr_idx), added);
}

/**
 * Setup a receive buffer descriptor ring (RBDR). Note that NIC share the RBDR if
 * "share_cq" is set.
 *
 * @param nic    NIC to setup RBDR for
 *
 * @return Zero on success, negative on failure
 */
static int vnic_setup_rbdr(nic_t *nic)
{
    nic_node_state_t *node_state = global_node_state[nic->node];
    int rbdr_idx = 0;
    int cq_idx = 0;
    int do_fill;

    if (nic->shares_cq)
    {
        /* These are allocated linearly. We know that the first port was
           the last guy to allcoate a CQ */
        nic->rbdr = node_state->next_free_rbdr - 1;
        do_fill = 0;
    }
    else
    {
        if (node_state->next_free_rbdr >= node_state->num_vnics)
        {
            bdk_error("%s: No free receive buffer descriptor rings\n", nic->handle->name);
            return -1;
        }
        void *rbdr_base = memalign(BDK_CACHE_LINE_SIZE, 8 * RBDR_ENTRIES);
        if (!rbdr_base)
        {
            bdk_error("%s: Failed to allocate memory for RBDR\n", nic->handle->name);
            return -1;
        }
        nic->rbdr = node_state->next_free_rbdr++;

        /* Configure the receive buffer ring (RBDR) */
        BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_RBDRX_BASE(nic->rbdr, rbdr_idx),
            bdk_ptr_to_phys(rbdr_base));
        const int buffer_size = bdk_config_get_int(BDK_CONFIG_PACKET_BUFFER_SIZE);
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_QSX_RBDRX_CFG(nic->rbdr, rbdr_idx),
            c.s.ena = 1;
            c.s.ldwb = BDK_USE_DWB;
            c.s.qsize = RBDR_ENTRIES_QSIZE;
            c.s.lines = buffer_size / BDK_CACHE_LINE_SIZE);
        do_fill = 1;
    }

    /* Configure our vnic to use the RBDR */
    /* Connect this RQ to the RBDR. Both the first and next buffers come from
       the same RBDR */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_RQX_CFG(nic->vnic, nic->qos),
        c.s.caching = 1; /* Allocate to L2 */
        c.s.cq_qs = nic->cq;
        c.s.cq_idx = cq_idx;
        c.s.rbdr_cont_qs = nic->rbdr;
        c.s.rbdr_cont_idx = rbdr_idx;
        c.s.rbdr_strt_qs = nic->rbdr;
        c.s.rbdr_strt_idx = rbdr_idx);
    /* NIC_PF_CQM_CFG is configure to drop everything if the CQ has 128 or
       less entries available. Start backpressure when we have 256 or less */
    int cq_bp = 256;
    int rbdr_bp = 256;
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_RQX_BP_CFG(nic->vnic, nic->qos),
        c.s.rbdr_bp_ena = 1;
        c.s.cq_bp_ena = 1;
        c.s.rbdr_bp = rbdr_bp * 256 / RBDR_ENTRIES; /* Zero means no buffers, 256 means lots available */
        c.s.cq_bp = cq_bp * 256 / CQ_ENTRIES; /* Zero means full, 256 means idle */
        c.s.bpid = nic->vnic);
    /* Errata (NIC-21269) Limited NIC receive scenario verification */
    /* RED drop set with pass=drop, so no statistical dropping */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_RQX_DROP_CFG(nic->vnic, nic->qos),
        c.s.rbdr_red = 0;
        c.s.cq_red = 0;
        c.s.rbdr_pass = 0; /* Zero means no buffers, 256 means lots available */
        c.s.rbdr_drop = 0;
        c.s.cq_pass = 0; /* Zero means full, 256 means idle */
        c.s.cq_drop = 0);

    if (do_fill)
    {
        /* We probably don't have enough space to completely fill the RBDR. Use
           1/4 of the buffers available minus a few. We expect to only have 2
           RBDR rings per node and a max of 2 nodes */
        int fill_num = (bdk_config_get_int(BDK_CONFIG_NUM_PACKET_BUFFERS) - 200) / 4;
        /* Note that RBDR must leave one spot empty */
        if (fill_num > RBDR_ENTRIES - 1)
            fill_num = RBDR_ENTRIES - 1;
        vnic_fill_receive_buffer(nic, fill_num);
    }

    return 0;
}

/**
 * Setup traffic shapping for a NIC. This put the shappers in passthrough mode
 * where no shapping is applied.
 *
 * @param nic    NIC to configure shaping for
 *
 * @return Zero on success, negative on failure
 */
static int vnic_setup_tx_shaping(nic_t *nic)
{
    int tl1_index = -1;
    int tl2_index = -1;
    int nic_chan_e = -1;

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        /* TL1 feeds the DMA engines. One for each BGX */
        tl1_index = nic->handle->interface;
        /* TL2 feeds TL1 based on the top/bottom half. Use an independent TL1
           entry for each BGX port */
        tl2_index = tl1_index * 32 + nic->handle->index;
        nic_chan_e = BDK_NIC_CHAN_E_BGXX_PORTX_CHX(nic->handle->interface, nic->handle->index, 0/*channel*/);
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
    {
        /* TL1 index by NIC_LMAC_E */
        /* TL2 index same as TL1 for straight through */
        switch (nic->ntype)
        {
            case BDK_NIC_TYPE_BGX:
                tl1_index = BDK_NIC_LMAC_E_BGXX_LMACX(nic->handle->interface, nic->handle->index);
                tl2_index = tl1_index;
                nic_chan_e = BDK_NIC_CHAN_E_BGXX_LMACX_CHX(nic->handle->interface, nic->handle->index, 0/*channel*/);
                break;
            case BDK_NIC_TYPE_LBK:
                tl1_index = BDK_NIC_LMAC_E_LBKX_CN83XX(nic->handle->index);
                tl2_index = tl1_index;
                nic_chan_e = BDK_NIC_CHAN_E_LBKX_CHX(nic->handle->interface, nic->handle->index);
                break;
            default:
                bdk_error("%s: Unsupported NIC TYPE %d\n", nic->handle->name, nic->ntype);
                return -1;
        }
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
    {
        /* TL1 index by NIC_LMAC_E */
        /* TL2 index same as TL1 for straight through */
        switch (nic->ntype)
        {
            case BDK_NIC_TYPE_BGX:
                tl1_index = BDK_NIC_LMAC_E_BGXX_LMACX(nic->handle->interface, nic->handle->index);
                tl2_index = tl1_index;
                nic_chan_e = BDK_NIC_CHAN_E_BGXX_LMACX_CHX(nic->handle->interface, nic->handle->index, 0/*channel*/);
                break;
            case BDK_NIC_TYPE_RGMII:
                tl1_index = BDK_NIC_LMAC_E_RGXX_LMACX(nic->handle->interface, nic->handle->index);
                tl2_index = tl1_index;
                nic_chan_e = BDK_NIC_CHAN_E_BGXX_LMACX_CHX(nic->handle->interface, nic->handle->index, 0/*channel*/);
                break;
            case BDK_NIC_TYPE_LBK:
                tl1_index = BDK_NIC_LMAC_E_LBKX_CN81XX(nic->handle->index);
                tl2_index = tl1_index;
                nic_chan_e = BDK_NIC_CHAN_E_LBKX_CHX(nic->handle->interface, nic->handle->index);
                break;
            default:
                bdk_error("%s: Unsupported NIC TYPE %d\n", nic->handle->name, nic->ntype);
                return -1;
        }
    }
    else
    {
        bdk_error("%s: Unsupported chip (NIC shaping)\n", nic->handle->name);
        return -1;
    }

    /* Setup TL2 to TL1 mappings */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL2X_CFG(tl2_index),
        c.s.rr_quantum = (MAX_MTU+4) / 4);
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL2X_PRI(tl2_index),
        c.s.rr_pri = 0);
    if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL2X_LMAC(tl2_index),
            c.s.lmac = tl1_index);
    }

    /* TL3 feeds Tl2. We only need one entry */
    int tl3_index = tl2_index * 4;
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL3AX_CFG(tl3_index / 4),
        c.s.tl3a = tl2_index);
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL3X_CFG(tl3_index),
        c.s.rr_quantum = (MAX_MTU+4) / 4);
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL3X_CHAN(tl3_index),
        c.s.chan = nic_chan_e);

    /* TL4 feeds TL3. We only need one entry */
    int tl4_index = tl3_index * 4;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL4AX_CFG(tl4_index / 4),
            c.s.tl4a = tl3_index);
    }
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_TL4X_CFG(tl4_index),
        c.s.sq_qs = nic->vnic;
        c.s.sq_idx = nic->qos;
        c.s.rr_quantum = (MAX_MTU+4) / 4);

    /* SQ feeds TL4 */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_SQX_CFG2(nic->vnic, nic->qos),
        c.s.tl4 = tl4_index);

    return 0;
}

/**
 * Free the buffers in a packet to the RBDR used by the port
 *
 * @param priv   Determines which RBDR is used
 * @param packet Packet to put in RBDR
 */
static void if_free_to_rbdr(bdk_if_packet_t *packet, nic_rbdr_state_t *vnic_rbdr_state)
{
    uint64_t *rbdr_ptr = vnic_rbdr_state->base;
    int loc = vnic_rbdr_state->loc;

    for (int s = 0; s < packet->segments; s++)
    {
        /* Make sure we strip off any padding added by the hardware in the address */
        uint64_t address = packet->packet[s].s.address & -BDK_CACHE_LINE_SIZE;
        rbdr_ptr[loc] = address;
        loc++;
        loc &= RBDR_ENTRIES - 1;
    }
    vnic_rbdr_state->loc = loc;
}

/**
 * Process a CQ receive entry
 *
 * @param handle
 * @param cq_header
 *
 * @return Returns the amount the RBDR doorbell needs to increment
 */
static int if_process_complete_rx(int node, nic_rbdr_state_t *vnic_rbdr_state, const union bdk_nic_cqe_rx_s *cq_header)
{
    nic_node_state_t *node_state = global_node_state[node];
    int vnic = cq_header->s.rq_qs;

    bdk_if_packet_t packet;
    packet.length = cq_header->s.len;
    packet.segments = cq_header->s.rb_cnt;
    packet.if_handle = node_state->nic_map[vnic]->handle;
    /* Combine the errlev and errop into a single 11 bit number. Errop
       is 8 bits, so errlev will be in the top byte */
    packet.rx_error = cq_header->s.errlev;
    packet.rx_error <<= 8;
    packet.rx_error |= cq_header->s.errop;

    const uint16_t *rb_sizes = (void*)cq_header + 24; /* Offset of RBSZ0 */
    const uint64_t *rb_addresses = (uint64_t*)(cq_header+1);
    int segment_length = 0;

    for (int s = 0; s < packet.segments; s++)
    {
        BDK_PREFETCH(bdk_phys_to_ptr(rb_addresses[s]), 0);
        packet.packet[s].u = rb_addresses[s];
        packet.packet[s].s.size = rb_sizes[s];
        segment_length += rb_sizes[s];
    }

    /* If we ran out of buffer the packet could be truncated */
    if (segment_length < packet.length)
        packet.length = segment_length;

    if (bdk_likely(packet.if_handle))
    {
        /* Do RX stats in software as it is fast and I don't really trust
           the hardware. The hardware tends to count packets that are received
           and dropped in some weird way. Hopefully the hardware counters
           looking for drops can find these. It is important that they
           aren't counted as good */
        packet.if_handle->stats.rx.packets++;
        packet.if_handle->stats.rx.octets += packet.length + 4;
        if (packet.rx_error)
            packet.if_handle->stats.rx.errors++;
        bdk_if_dispatch_packet(&packet);
    }
    else
    {
        bdk_error("Unable to determine interface for VNIC %d\n", vnic);
    }

    if_free_to_rbdr(&packet, vnic_rbdr_state);
    return packet.segments;
}

/**
 * Process all entries in a completion queue (CQ). Note that a CQ is shared
 * among many ports, so packets will be dispatch for other port handles.
 *
 * @param handle Interface handle connected to the CQ
 *
 * @return Number of packets received
 */
static void if_receive(int unused, void *hand)
{
    const nic_t *nic = hand;

    /* Figure out which completion queue we're using */
    int rbdr = nic->rbdr;
    int cq = nic->cq;
    int cq_idx = 0;

    BDK_CSR_INIT(cq_base, nic->node, BDK_NIC_QSX_CQX_BASE(cq, cq_idx));
    const void *cq_ptr = bdk_phys_to_ptr(cq_base.u);

    /* Find the current CQ location */
    BDK_CSR_INIT(cq_head, nic->node, BDK_NIC_QSX_CQX_HEAD(cq, cq_idx));
    int loc = cq_head.s.head_ptr;

    /* Store the RBDR data locally to avoid contention */
    int rbdr_idx = 0;
    BDK_CSR_INIT(rbdr_base, nic->node, BDK_NIC_QSX_RBDRX_BASE(rbdr, rbdr_idx));
    BDK_CSR_INIT(rbdr_tail, nic->node, BDK_NIC_QSX_RBDRX_TAIL(rbdr, rbdr_idx));
    nic_rbdr_state_t vnic_rbdr_state;
    vnic_rbdr_state.base = bdk_phys_to_ptr(rbdr_base.u);
    vnic_rbdr_state.loc = rbdr_tail.s.tail_ptr;

    while (1)
    {
        /* Exit immediately if the CQ is empty */
        BDK_CSR_INIT(cq_status, nic->node, BDK_NIC_QSX_CQX_STATUS(cq, cq_idx));
        int pending_count = cq_status.s.qcount;
        if (bdk_likely(!pending_count))
        {
            bdk_wait_usec(1);
            continue;
        }

        /* Loop through all pending CQs */
        int rbdr_doorbell = 0;
        int count = 0;
        const union bdk_nic_cqe_rx_s *cq_next = cq_ptr + loc * 512;
        while (count < pending_count)
        {
            const union bdk_nic_cqe_rx_s *cq_header = cq_next;
            loc++;
            loc &= CQ_ENTRIES - 1;
            cq_next = cq_ptr + loc * 512;
            BDK_PREFETCH(cq_next, 0);
            if (bdk_likely(cq_header->s.cqe_type == BDK_NIC_CQE_TYPE_E_RX))
                rbdr_doorbell += if_process_complete_rx(nic->node, &vnic_rbdr_state, cq_header);
            else
                bdk_error("Unsupported CQ header type %d\n", cq_header->s.cqe_type);
            count++;
        }
        /* Ring the RBDR doorbell for all packets */
        BDK_WMB;
        BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_RBDRX_DOOR(rbdr, rbdr_idx), rbdr_doorbell);
        /* Free all the CQs that we've processed */
        BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_CQX_DOOR(cq, cq_idx), count);
    }
}

/**
 * Configure NIC for a specific port. This is called for each
 * port on every interface that connects to NIC.
 *
 * @param handle Handle for port to config
 * @param ntype  Type of LMAC this NIC connects to
 * @param lmac_credits
 *               Size of the LMAC buffer in bytes. Used to configure the number of credits to
 *               setup between the NIC and LMAC
 *
 * @return Zero on success, negative on failure
 */
int bdk_nic_port_init(bdk_if_handle_t handle, bdk_nic_type_t ntype, int lmac_credits)
{
    int nic_chan_idx_e;     /* Flow channel for the CPI */
    int nic_intf_e;         /* Interface enumeration */
    int nic_intf_block_e;   /* Interface Block ID Enumeration */
    int nic_lmac_e;         /* LMAC enumeration */

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        /* Flow here is a compressed NIC_CHAN_E enum value. Flow is bit[8] and
           bit[6:0] from NIC_CHAN_E. This works out as:
           bit 7: BGX interface number(0-1)
           bit 6:4: BGX port number(0-3)
           bit 3:0: BGX channel on a port (0-15) */
        nic_chan_idx_e = (handle->interface) ? 0x80 : 0x00;
        nic_chan_idx_e += handle->index * 16;
        nic_chan_idx_e += 0; /* channel */
        nic_intf_e = BDK_NIC_INTF_E_BGXX(handle->interface);
        nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_BGXX_BLOCK(handle->interface);
        nic_lmac_e = BDK_NIC_LMAC_E_BGXX_LMACX(handle->interface, handle->index);
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
    {
        switch (ntype)
        {
            case BDK_NIC_TYPE_BGX:
                nic_chan_idx_e = BDK_NIC_CHAN_IDX_E_BGXX_LMACX_CHX(handle->interface, handle->index, 0/*channel*/);
                nic_intf_e = BDK_NIC_INTF_E_BGXX(handle->interface);
                nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_BGXX(handle->interface);
                nic_lmac_e = BDK_NIC_LMAC_E_BGXX_LMACX(handle->interface, handle->index);
                break;
            case BDK_NIC_TYPE_LBK:
                nic_chan_idx_e = BDK_NIC_CHAN_IDX_E_LBKX_CHX_CN83XX(handle->interface, handle->index);
                nic_intf_e = BDK_NIC_INTF_E_LBKX_CN83XX(handle->interface);
                nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_LBKX(handle->interface);
                nic_lmac_e = BDK_NIC_LMAC_E_LBKX_CN83XX(handle->interface);
                break;
            default:
                bdk_error("%s: Unsupported NIC TYPE %d\n", handle->name, ntype);
                return -1;
        }
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
    {
        switch (ntype)
        {
            case BDK_NIC_TYPE_BGX:
                nic_chan_idx_e = BDK_NIC_CHAN_IDX_E_BGXX_LMACX_CHX(handle->interface, handle->index, 0/*channel*/);
                nic_intf_e = BDK_NIC_INTF_E_BGXX(handle->interface);
                nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_BGXX(handle->interface);
                nic_lmac_e = BDK_NIC_LMAC_E_BGXX_LMACX(handle->interface, handle->index);
                break;
            case BDK_NIC_TYPE_RGMII:
                nic_chan_idx_e = BDK_NIC_CHAN_IDX_E_RGXX_LMACX_CHX(handle->interface, handle->index, 0/*channel*/);
                nic_intf_e = BDK_NIC_INTF_E_RGXX(handle->index);
                nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_BGXX(handle->interface);
                nic_lmac_e = BDK_NIC_LMAC_E_RGXX_LMACX(handle->interface, handle->index);
                break;
            case BDK_NIC_TYPE_LBK:
                nic_chan_idx_e = BDK_NIC_CHAN_IDX_E_LBKX_CHX_CN81XX(handle->interface, handle->index);
                nic_intf_e = BDK_NIC_INTF_E_LBKX_CN81XX(handle->interface);
                nic_intf_block_e = BDK_NIC_INTF_BLOCK_E_LBKX(handle->interface);
                nic_lmac_e = BDK_NIC_LMAC_E_LBKX_CN81XX(handle->interface);
                break;
            default:
                bdk_error("%s: Unsupported NIC TYPE %d\n", handle->name, ntype);
                return -1;
        }
    }
    else
    {
        bdk_error("%s: Unsupported chip (NIC init)\n", handle->name);
        return -1;
    }

    /* Make sure the node global state has been allocated */
    if (global_node_state[handle->node] == NULL)
    {
        global_node_state[handle->node] = calloc(1, sizeof(nic_node_state_t));
        if (global_node_state[handle->node] == NULL)
        {
            bdk_error("N%d.NIC: Failed to allocate node state\n", handle->node);
            return -1;
        }
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        {
            /* NIC_PF_CONST1 didn't exist on this chip */
            global_node_state[handle->node]->num_vnics = 128;
        }
        else
        {
            BDK_CSR_INIT(nic_pf_const1, handle->node, BDK_NIC_PF_CONST1);
            if (bdk_is_platform(BDK_PLATFORM_ASIM))
            {
                /* Asim doesn't model the NIC correctly */
                if (nic_pf_const1.u == 0)
                    nic_pf_const1.u = (CAVIUM_IS_MODEL(CAVIUM_CN81XX)) ? 0x8 : 0x20;
            }
            global_node_state[handle->node]->num_vnics = nic_pf_const1.s.vnics;
        }

    }
    nic_node_state_t *node_state = global_node_state[handle->node];

    /* See if we have a free VNIC */
    if (node_state->next_free_vnic >= node_state->num_vnics)
    {
        bdk_error("N%d.NIC: Ran out of NICs\n", handle->node);
        return -1;
    }

    /* VNIC setup requirements
       The code in this file makes the following assumptions:
       1) One RBDR for each CQ. No locking is done on RBDR
       2) A CQ can be shared across multiple ports, saving space as the
            cost of performance.
       3) One SQ per physical port, no locking on TX
       4) One RQ per physical port, many RQ may share RBDR/CQ

        Current setup without DRAM:
        1) One RBDR allocated per BGX block. RBDR = (priv->rbdr, 0)
        2) One CQ allocated per BGX block. CQ = (priv->cq, 0)
        3) One SQ allcoated per BGX port/channel. SQ = (priv->vnic, priv->qos)
        4) One RQ allcoated per BGX port/channel. RQ = (priv->vnic, priv->qos)

        Current setup with DRAM:
        1) One RBDR allocated per BGX port/channel. RBDR = (priv->rbdr, 0)
        2) One CQ allocated per BGX port/channel. CQ = (priv->cq, 0)
        3) One SQ allcoated per BGX port/channel. SQ = (priv->vnic, priv->qos)
        4) One RQ allcoated per BGX port/channel. RQ = (priv->vnic, priv->qos)
       */
    void *sq_memory = memalign(BDK_CACHE_LINE_SIZE, 16 * SQ_ENTRIES);
    if (!sq_memory)
    {
        bdk_error("%s: Unable to allocate queues\n", handle->name);
        return -1;
    }
    nic_t *nic = calloc(1, sizeof(nic_t));
    if (!nic)
    {
        free(sq_memory);
        bdk_error("%s: Unable to NIC state\n", handle->name);
        return -1;
    }

    handle->vnic = node_state->next_free_vnic++;
    node_state->nic_map[handle->vnic] = nic;

    nic->node = handle->node;
    nic->vnic = handle->vnic;
    nic->qos = 0;
    nic->handle = handle;
    nic->shares_cq = (handle->index > 0) && !__bdk_is_dram_enabled(handle->node);

    int sq = nic->vnic;
    int sq_idx = nic->qos;
    int rq = nic->vnic;
    int rq_idx = nic->qos;

    /* Enable global BP state updates */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_BP_CFG,
        c.s.bp_poll_ena = 1;
        c.s.bp_poll_dly = 3);

    /* Enable interface level backpresure */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_INTFX_BP_CFG(nic_intf_e),
        c.s.bp_ena = 1;
        c.s.bp_type = ((nic->ntype == BDK_NIC_TYPE_BGX) ||
                       (nic->ntype == BDK_NIC_TYPE_RGMII)) ? 0 : 1; /* 0=BGX, 1=LBK/TNS */
        c.s.bp_id = nic_intf_block_e);

    /* Configure the submit queue (SQ) */
    nic->sq_base = sq_memory;
    nic->sq_loc = 0;
    nic->sq_available = SQ_ENTRIES;
    BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_SQX_BASE(sq, sq_idx),
        bdk_ptr_to_phys(sq_memory));
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_QSX_SQX_CFG(sq, sq_idx),
        if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
            c.s.cq_limit = 1;
        c.s.ena = 1;
        c.s.ldwb = BDK_USE_DWB;
        c.s.qsize = SQ_ENTRIES_QSIZE);

    /* Configure the receive queue (RQ) */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_QSX_RQ_GEN_CFG(rq),
        c.s.vlan_strip = 0;
        c.s.len_l4 = 0;
        c.s.len_l3 = 0;
        c.s.csum_sctp = 0;
        c.s.csum_l4 = 0;
        c.s.ip6_udp_opt = 0;
        c.s.splt_hdr_ena = 0;
        c.s.cq_hdr_copy = 0;
        c.s.max_tcp_reass = 0;
        c.s.cq_pkt_size = 0;
        c.s.later_skip = 0;
        c.s.first_skip = 0);
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_QSX_RQX_CFG(rq, rq_idx),
        c.s.ena = 1;
        c.s.tcp_ena = 0);

    int cpi = node_state->next_free_cpi++;  /* Allocate a new Channel Parse Index (CPI) */
    int rssi = node_state->next_free_rssi++;/* Allocate a new Receive-Side Scaling Index (RSSI) */
    /* NIC_CHAN_E hard mapped to "flow". Flow chooses the CPI */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_CHANX_RX_CFG(nic_chan_idx_e),
        c.s.cpi_alg = BDK_NIC_CPI_ALG_E_NONE;
        c.s.cpi_base = cpi);
    /* Setup backpressure */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_CHANX_RX_BP_CFG(nic_chan_idx_e),
        c.s.ena = 1;
        c.s.bpid = nic->vnic);
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_CHANX_TX_CFG(nic_chan_idx_e),
        c.s.bp_ena = 1);
    /* CPI is the output of the above alogrithm, this is used to lookup the
       VNIC for receive and RSSI */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_CPIX_CFG(cpi),
        c.cn88xxp1.vnic = nic->vnic; /* TX and RX use the same VNIC */
        c.cn88xxp1.rss_size = 0; /* RSS hash is disabled */
        c.s.padd = 0; /* Used if we have multiple channels per port */
        c.cn88xxp1.rssi_base = rssi); /* Base RSSI */
    if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
    {
        /* CN88XX pass 2 moved some fields to a different CSR */
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_MPIX_CFG(cpi),
            c.s.vnic = nic->vnic; /* TX and RX use the same VNIC */
            c.s.rss_size = 0; /* RSS hash is disabled */
            c.s.rssi_base = rssi); /* Base RSSI */
    }
    /* The RSSI is used to determine which Receive Queue (RQ) we use */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_RSSIX_RQ(rssi),
        c.s.rq_qs = rq;
        c.s.rq_idx = rq_idx);
    /* Set the min and max packet size. PKND comes from BGX. It is always zero
       for now */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_PKINDX_CFG(handle->pknd),
        c.s.lenerr_en = 0;
        c.s.minlen = 0;
        c.s.maxlen = 65535);

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        /* Bypass the TNS */
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_INTFX_SEND_CFG(handle->interface),
           c.s.tns_nonbypass = 0;
           c.s.block = 0x8 + handle->interface);
    }

    /* Errata (NIC-21858) If NIC_PF_QS()_CFG ENA is set after RRM enabled...RRM breaks */
    /* Do global vnic init */
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_QSX_CFG(nic->vnic),
        c.s.ena = 1;
        c.s.vnic = nic->vnic);

    if (vnic_setup_tx_shaping(nic))
        return -1;
    if (vnic_setup_cq(nic))
        return -1;
    if (vnic_setup_rbdr(nic))
        return -1;

    /* Program LMAC credits */
    int credit = (lmac_credits - MAX_MTU) / 16;
    BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_LMACX_CREDIT(nic_lmac_e),
        c.s.cc_unit_cnt = credit;
        c.s.cc_packet_cnt = 0x1ff;
        c.s.cc_enable = 1);

    /* Pad packets to 60 bytes, 15 32bit words (before FCS) */
    if (nic->ntype != BDK_NIC_TYPE_LBK)
        BDK_CSR_MODIFY(c, nic->node, BDK_NIC_PF_LMACX_CFG(nic_lmac_e),
            c.s.min_pkt_size = 15);

    /* Create a receive thread if this handle has its own CQ/RBDR */
    if (!nic->shares_cq)
    {
        if (bdk_thread_create(nic->node, 0, if_receive, 0, nic, 0))
        {
            bdk_error("%s: Failed to allocate receive thread\n", handle->name);
            return -1;
        }
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
int bdk_nic_transmit(bdk_if_handle_t handle, const bdk_if_packet_t *packet)
{
    /* The SQ can't be filled completely as it reguires at least one free
       entry so the head and pointer don't look like empty. SQ_SLOP is the
       amount of SQ space we reserve to make sure of this */
    const int SQ_SLOP = 1;
    const nic_node_state_t *node_state = global_node_state[handle->node];
    nic_t *nic = node_state->nic_map[handle->vnic];

    /* Update the SQ available if we're out of space. The NIC should have sent
       packets, making more available. This allows us to only read the STATUS
       CSR when really necessary, normally using the L1 cached value */
    if (nic->sq_available < packet->segments + 1 + SQ_SLOP)
    {
        BDK_CSR_INIT(sq_status, nic->node, BDK_NIC_QSX_SQX_STATUS(nic->vnic, nic->qos));
        nic->sq_available = SQ_ENTRIES - sq_status.s.qcount;
    }
    /* Check for space. A packets is a header plus its segments */
    if (nic->sq_available < packet->segments + 1 + SQ_SLOP)
        return -1;

    /* Build the command */
    void *sq_ptr = nic->sq_base;
    int loc = nic->sq_loc;
    union bdk_nic_send_hdr_s send_hdr;
    send_hdr.u[0] = 0;
    send_hdr.u[1] = 0;
    send_hdr.s.subdc = BDK_NIC_SEND_SUBDC_E_HDR;
    send_hdr.s.subdcnt = packet->segments;
    send_hdr.s.total = packet->length;
    *(union bdk_nic_send_hdr_s *)(sq_ptr + loc * 16) = send_hdr;
    loc++;
    loc &= SQ_ENTRIES - 1;
    for (int s = 0; s < packet->segments; s++)
    {
        union bdk_nic_send_gather_s gather;
        gather.u[0] = 0;
        gather.u[1] = 0;
        gather.s.addr = packet->packet[s].s.address;
        gather.s.subdc = BDK_NIC_SEND_SUBDC_E_GATHER;
        gather.s.ld_type = (BDK_USE_DWB) ? BDK_NIC_SEND_LD_TYPE_E_LDWB : BDK_NIC_SEND_LD_TYPE_E_LDD;
        gather.s.size = packet->packet[s].s.size;
        *(union bdk_nic_send_gather_s *)(sq_ptr + loc * 16) = gather;
        loc++;
        loc &= SQ_ENTRIES - 1;
    }

    BDK_WMB;

    /* Ring the doorbell */
    BDK_CSR_WRITE(nic->node, BDK_NIC_QSX_SQX_DOOR(nic->vnic, nic->qos),
        packet->segments + 1);

    /* Update our cached state */
    nic->sq_available -= packet->segments + 1;
    nic->sq_loc = loc;

    return 0;
}

/**
 * Get the current TX queue depth. Note that this operation may be slow
 * and adversly affect packet IO performance.
 *
 * @param handle Port to check
 *
 * @return Depth of the queue in packets
 */
int bdk_nic_get_queue_depth(bdk_if_handle_t handle)
{
    const nic_node_state_t *node_state = global_node_state[handle->node];
    const nic_t *nic = node_state->nic_map[handle->vnic];
    BDK_CSR_INIT(sq_status, nic->node, BDK_NIC_QSX_SQX_STATUS(nic->vnic, nic->qos));
    return sq_status.s.qcount;
}

/**
 * Query NIC and fill in the transmit stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
void bdk_nic_fill_tx_stats(bdk_if_handle_t handle)
{
    /* Account for TX adding FCS */
    const int bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int vnic = handle->vnic;

    BDK_CSR_INIT(octs, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_OCTS));
    BDK_CSR_INIT(pkts, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_UCAST));
    BDK_CSR_INIT(drps, handle->node, BDK_NIC_VNICX_TX_STATX(vnic, BDK_NIC_STAT_VNIC_TX_E_TX_DROP));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(octs.u, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(pkts.u, handle->stats.tx.packets, 48);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    handle->stats.tx.dropped_packets = bdk_update_stat_with_overflow(drps.u, handle->stats.tx.dropped_packets, 48);
    /* Dropped Octets are not available */
}

/**
 * Query NIC and fill in the receive stats for the supplied
 * interface handle.
 *
 * @param handle Port handle
 */
void bdk_nic_fill_rx_stats(bdk_if_handle_t handle)
{
    /* Account for RX FCS */
    const int bytes_off_rx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int vnic = handle->vnic;

    /* Read the RX statistics. These do not include the ethernet FCS */
    BDK_CSR_INIT(rx_red, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_RED));
    BDK_CSR_INIT(rx_red_octets, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_RED_OCTS));
    BDK_CSR_INIT(rx_ovr, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_ORUN));
    BDK_CSR_INIT(rx_ovr_octets, handle->node, BDK_NIC_VNICX_RX_STATX(vnic, BDK_NIC_STAT_VNIC_RX_E_RX_ORUN_OCTS));
    uint64_t drops = rx_red.u + rx_ovr.u;
    uint64_t drop_octets = rx_red_octets.u + rx_ovr_octets.u;

    /* Drop and error counters */
    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(drop_octets, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(drops, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    /* Normal RX stats are done by software on receive */
}


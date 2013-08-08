#include <bdk.h>
#include <stdio.h>

static bdk_if_link_t if_link_get(bdk_if_handle_t handle);

static int if_num_interfaces(bdk_node_t node)
{
    if (bdk_qlm_get(node, BDK_IF_ILK, 0) < 0)
        return 0;

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Configure the SERDES */
        BDK_CSR_MODIFY(c, node, BDK_ILK_SER_CFG,
            c.s.ser_rxpol_auto = 1;
            c.s.ser_rxpol = 0;
            c.s.ser_txpol = 0);
        BDK_CSR_MODIFY(c, node, BDK_ILK_SER_CFG,
            c.s.ser_reset_n = 0xff;
            c.s.ser_pwrup = 3;
            c.s.ser_haul = 0);

        if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
        {
            extern void __bdk_qlm_powerup_G16467_part2(int qlm);
            /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive
                QLM jitter for 6.25 Gbaud */
            /* Only QLM 1 and 2 can potentially be ILK */
            for (int qlm=1; qlm<=2; qlm++)
            {
                if (bdk_qlm_get_mode(node, qlm) == BDK_QLM_MODE_ILK)
                    __bdk_qlm_powerup_G16467_part2(qlm);
            }
        }

        return 2;
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        /* Configure the SERDES */
        BDK_CSR_MODIFY(c, node, BDK_ILK_SER_CFG,
            c.s.ser_rxpol_auto = 1;
            c.s.ser_rxpol = 0;
            c.s.ser_txpol = 0);
        return 2;
    }
    else
        return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    /* See how many lanes we can potentially have. We already checked QLM1
        when probing the inteface number, now we check QLM2 */
    int max_lanes;
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        max_lanes = (bdk_qlm_get_mode(node, 2) == BDK_QLM_MODE_ILK) ? 8 : 4;
    }
    else
    {
        /* CN78XX: Loop through QLMs 4-7 counting ILK lanes. The first QLM
            that isn't ILK stops the search */
        max_lanes = 0;
        for (int qlm=4; qlm<7; qlm++)
        {
            if (bdk_qlm_get_mode(node, qlm) == BDK_QLM_MODE_ILK)
                max_lanes += 4;
            else
                break;
        }
    }

    /* In ILK interface only exists if there are lanes configured for it */
    int lanes_interface0 = bdk_config_get(BDK_CONFIG_ILK0_LANES);
    int lanes_interface1 = bdk_config_get(BDK_CONFIG_ILK1_LANES);

    if (interface == 0)
    {
        if (lanes_interface0 > max_lanes)
        {
            bdk_error("ILK0 configured for more lanes that are available\n");
            return 0;
        }
        else if (lanes_interface0 == 0)
            return 0;
    }
    else
    {
        if (lanes_interface0 + lanes_interface1 > max_lanes)
        {
            bdk_error("ILK1 configured for more lanes that are available\n");
            return 0;
        }
        else if (lanes_interface1 == 0)
            return 0;
    }

    /* User must have configured the number of ports */
    return bdk_config_get(BDK_CONFIG_ILK0_PORTS + interface);
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be "ILK%d.%d" */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "ILK%d.%d", handle->interface, handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.ILK%d.%d", handle->node, handle->interface, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    /* Use IPD ports 0 - 7 */
    handle->ipd_port = 0x400 + handle->interface*0x100 + handle->index;
    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
    return 0;
}

/**
 * Clear all TX and RX calendar entries. Each channel will be
 * enabled later on with calls to ilk_write_cal_entry().
 *
 * @param interface Interface to clear
 */
static void ilk_clear_cal_cn68xx(bdk_node_t node, int interface)
{
    int i;

    /* Setup TX write chunk */
    BDK_CSR_DEFINE(ctidx, BDK_ILK_TXX_IDX_CAL(interface));
    ctidx.u64 = 0;
    ctidx.s.index = 0;
    ctidx.s.inc = 1;
    BDK_CSR_WRITE(node, BDK_ILK_TXX_IDX_CAL(interface), ctidx.u64);

    /* Each entry will be XOF to disable TX */
    BDK_CSR_DEFINE(tcal0, BDK_ILK_TXX_MEM_CAL0(interface));
    BDK_CSR_DEFINE(tcal1, BDK_ILK_TXX_MEM_CAL1(interface));
    tcal0.u64 = 0;
    tcal0.s.entry_ctl0 = 2; /* XOF */
    tcal0.s.entry_ctl1 = 2;
    tcal0.s.entry_ctl2 = 2;
    tcal0.s.entry_ctl3 = 2;
    tcal1.u64 = 0;
    tcal1.s.entry_ctl4 = 2;
    tcal1.s.entry_ctl5 = 2;
    tcal1.s.entry_ctl6 = 2;
    tcal1.s.entry_ctl7 = 2;
    /* Write all 288 entries, 8 at a time */
    for (i=0; i<36; i++)
    {
        BDK_CSR_WRITE(node, BDK_ILK_TXX_MEM_CAL0(interface), tcal0.u64);
        BDK_CSR_WRITE(node, BDK_ILK_TXX_MEM_CAL1(interface), tcal1.u64);
    }

    /* Setup RX write chunk */
    BDK_CSR_DEFINE(cridx, BDK_ILK_RXX_IDX_CAL(interface));
    cridx.u64 = 0;
    cridx.s.index = 0;
    cridx.s.inc = 1;
    BDK_CSR_WRITE(node, BDK_ILK_RXX_IDX_CAL(interface), cridx.u64);

    /* Each entry will be Link to simplify RX */
    BDK_CSR_DEFINE(rcal0, BDK_ILK_RXX_MEM_CAL0(interface));
    BDK_CSR_DEFINE(rcal1, BDK_ILK_RXX_MEM_CAL1(interface));
    rcal0.u64 = 0;
    rcal0.s.entry_ctl0 = 1; /* Link */
    rcal0.s.entry_ctl1 = 1;
    rcal0.s.entry_ctl2 = 1;
    rcal0.s.entry_ctl3 = 1;
    rcal1.u64 = 0;
    rcal1.s.entry_ctl4 = 1;
    rcal1.s.entry_ctl5 = 1;
    rcal1.s.entry_ctl6 = 1;
    rcal1.s.entry_ctl7 = 1;
    /* Write all 288 entries, 8 at a time */
    for (i=0; i<36; i++)
    {
        BDK_CSR_WRITE(node, BDK_ILK_RXX_MEM_CAL0(interface), rcal0.u64);
        BDK_CSR_WRITE(node, BDK_ILK_RXX_MEM_CAL1(interface), rcal1.u64);
    }
}

static void ilk_clear_cal_cn78xx(bdk_node_t node, int interface)
{
    for (int i=0; i<288; i++)
    {
        BDK_CSR_DEFINE(tx_cal, BDK_ILK_TXX_CAL_ENTRYX(interface, i));
        tx_cal.u = 0;
        tx_cal.s.ctl = 2;
        BDK_CSR_WRITE(node, BDK_ILK_TXX_CAL_ENTRYX(interface, i), tx_cal.u);

        BDK_CSR_DEFINE(rx_cal, BDK_ILK_RXX_CAL_ENTRYX(interface, i));
        rx_cal.u = 0;
        rx_cal.s.ctl = 2;
        BDK_CSR_WRITE(node, BDK_ILK_RXX_CAL_ENTRYX(interface, i), rx_cal.u);
    }
}

static void ilk_clear_cal(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        ilk_clear_cal_cn68xx(node, interface);
    else
        ilk_clear_cal_cn78xx(node, interface);
}

static void ilk_write_cal_entry_cn68xx(bdk_node_t node, int interface, int channel, int bpid, int pko_pipe)
{
    /* Calendar will be setup such that each 16 entries has the global
        link status in the first entry. This allows the received to
        send global backpressure in every contorl word. This means
        we are putting 15 channel entries in every control word */
    int calendar_16_block = channel / 15;
    int calendar_16_index = channel % 15 + 1;
    int table_chunk = calendar_16_block * 2 + calendar_16_index / 8;
    int table_index = calendar_16_index % 8;

    /* Setup TX write chunk */
    BDK_CSR_DEFINE(ctidx, BDK_ILK_TXX_IDX_CAL(interface));
    ctidx.u64 = 0;
    ctidx.s.index = table_chunk;
    BDK_CSR_WRITE(node, BDK_ILK_TXX_IDX_CAL(interface), ctidx.u64);
    /* Read the current values */
    BDK_CSR_INIT(tcal0, node, BDK_ILK_TXX_MEM_CAL0(interface));
    BDK_CSR_INIT(tcal1, node, BDK_ILK_TXX_MEM_CAL1(interface));

    /* The first entry of every other calendar chunk is link status. This
        corresponds to the first bit in every 16 bit block */
    if ((table_chunk & 1) == 0)
        tcal0.s.entry_ctl0 = 1;

    /* Set the correct index */
    switch (table_index)
    {
        case 0:
            tcal0.s.entry_ctl0 = 0;
            tcal0.s.bpid0 = bpid;
            break;
        case 1:
            tcal0.s.entry_ctl1 = 0;
            tcal0.s.bpid1 = bpid;
            break;
        case 2:
            tcal0.s.entry_ctl2 = 0;
            tcal0.s.bpid2 = bpid;
            break;
        case 3:
            tcal0.s.entry_ctl3 = 0;
            tcal0.s.bpid3 = bpid;
            break;
        case 4:
            tcal1.s.entry_ctl4 = 0;
            tcal1.s.bpid4 = bpid;
            break;
        case 5:
            tcal1.s.entry_ctl5 = 0;
            tcal1.s.bpid5 = bpid;
            break;
        case 6:
            tcal1.s.entry_ctl6 = 0;
            tcal1.s.bpid6 = bpid;
            break;
        case 7:
            tcal1.s.entry_ctl7 = 0;
            tcal1.s.bpid7 = bpid;
            break;
    }
    /* Write the new values */
    BDK_CSR_WRITE(node, BDK_ILK_TXX_MEM_CAL0(interface), tcal0.u64);
    BDK_CSR_WRITE(node, BDK_ILK_TXX_MEM_CAL1(interface), tcal1.u64);

    /* Setup RX write chunk */
    BDK_CSR_DEFINE(cridx, BDK_ILK_RXX_IDX_CAL(interface));
    cridx.u64 = 0;
    cridx.s.index = table_chunk;
    BDK_CSR_WRITE(node, BDK_ILK_RXX_IDX_CAL(interface), cridx.u64);
    /* Read the current values */
    BDK_CSR_INIT(rcal0, node, BDK_ILK_RXX_MEM_CAL0(interface));
    BDK_CSR_INIT(rcal1, node, BDK_ILK_RXX_MEM_CAL1(interface));

    /* The first entry of every other calendar chunk is link status. This
        corresponds to the first bit in every 16 bit block */
    if ((table_chunk & 1) == 0)
        rcal0.s.entry_ctl0 = 1;

    /* Set the correct index */
    switch (table_index)
    {
        case 0:
            rcal0.s.entry_ctl0 = 0;
            rcal0.s.port_pipe0 = pko_pipe;
            break;
        case 1:
            rcal0.s.entry_ctl1 = 0;
            rcal0.s.port_pipe1 = pko_pipe;
            break;
        case 2:
            rcal0.s.entry_ctl2 = 0;
            rcal0.s.port_pipe2 = pko_pipe;
            break;
        case 3:
            rcal0.s.entry_ctl3 = 0;
            rcal0.s.port_pipe3 = pko_pipe;
            break;
        case 4:
            rcal1.s.entry_ctl4 = 0;
            rcal1.s.port_pipe4 = pko_pipe;
            break;
        case 5:
            rcal1.s.entry_ctl5 = 0;
            rcal1.s.port_pipe5 = pko_pipe;
            break;
        case 6:
            rcal1.s.entry_ctl6 = 0;
            rcal1.s.port_pipe6 = pko_pipe;
            break;
        case 7:
            rcal1.s.entry_ctl7 = 0;
            rcal1.s.port_pipe7 = pko_pipe;
            break;
    }
    /* Write the new values */
    BDK_CSR_WRITE(node, BDK_ILK_RXX_MEM_CAL0(interface), rcal0.u64);
    BDK_CSR_WRITE(node, BDK_ILK_RXX_MEM_CAL1(interface), rcal1.u64);
}

static void ilk_write_cal_entry_cn78xx(bdk_node_t node, int interface, int channel, int bpid, int pko_pipe)
{
    BDK_CSR_DEFINE(tx_cal, BDK_ILK_TXX_CAL_ENTRYX(0,0));
    BDK_CSR_DEFINE(rx_cal, BDK_ILK_RXX_CAL_ENTRYX(0,0));

    /* Calendar will be setup such that each 16 entries has the global
        link status in the first entry. This allows the received to
        send global backpressure in every contorl word. This means
        we are putting 15 channel entries in every control word */
    int calendar_16_block = channel / 15;
    int calendar_16_index = channel % 15 + 1;
    int index = calendar_16_block * 16 + calendar_16_index;

    /* Program the link status on first channel */
    if (calendar_16_index == 1)
    {
        tx_cal.u = 0;
        tx_cal.s.ctl = 1;
        BDK_CSR_WRITE(node, BDK_ILK_TXX_CAL_ENTRYX(interface, index-1), tx_cal.u);

        rx_cal.u = 0;
        rx_cal.s.ctl = 1;
        BDK_CSR_WRITE(node, BDK_ILK_RXX_CAL_ENTRYX(interface, index-1), rx_cal.u);
    }

    tx_cal.u = 0;
    tx_cal.s.ctl = 0;
    tx_cal.s.channel = channel;
    BDK_CSR_WRITE(node, BDK_ILK_TXX_CAL_ENTRYX(interface, index), tx_cal.u);

    rx_cal.u = 0;
    rx_cal.s.ctl = 0;
    rx_cal.s.channel = channel;
    BDK_CSR_WRITE(node, BDK_ILK_RXX_CAL_ENTRYX(interface, index), rx_cal.u);
}

static void ilk_write_cal_entry(bdk_node_t node, int interface, int channel, int bpid, int pko_pipe)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        ilk_write_cal_entry_cn68xx(node, interface, channel, bpid, pko_pipe);
    else
        ilk_write_cal_entry_cn78xx(node, interface, channel, bpid, pko_pipe);
}

static int if_init(bdk_if_handle_t handle)
{
    int num_ilk = bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface);
    static int pko_eid[2] = {-1, -1};
    static int pipe[2] = {-1, -1};
    if (OCTEON_IS_MODEL(OCTEON_CN68XX) && (pko_eid[handle->interface] == -1))
    {
        /* All ports use same eid and intr */
        pko_eid[handle->interface] = __bdk_pko_alloc_engine(handle->node);
        pipe[handle->interface] = __bdk_pko_alloc_pipe(handle->node, num_ilk);
    }

    if (handle->index == 0)
    {
        ilk_clear_cal(handle->node, handle->interface);
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
            BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_PIPE(handle->interface),
                c.s.nump = num_ilk;
                c.s.base = pipe[handle->interface]);

        /* Set jabber to allow max sized packets */
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_JABBER(handle->interface),
            c.s.cnt = 0xfff8);
    }

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */
        ptrs.s.crc = 1;         /* Use CRC on packets */
        ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
        ptrs.s.pipe = pipe[handle->interface]+handle->index;
        ptrs.s.intr = 28+handle->interface; /* Which interface */
        ptrs.s.eid = pko_eid[handle->interface];  /* Which engine */
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Map pipes to channels */
        BDK_CSR_DEFINE(idx, BDK_ILK_TXX_IDX_PMAP(handle->interface));
        idx.u64 = 0;
        idx.s.index = pipe[handle->interface]+handle->index;
        BDK_CSR_WRITE(handle->node, BDK_ILK_TXX_IDX_PMAP(handle->interface), idx.u64);
        BDK_CSR_WRITE(handle->node, BDK_ILK_TXX_MEM_PMAP(handle->interface), handle->index);
    }
    else
    {
        const int MAC_NUMBER = 0x2 + handle->interface; /* Constant from cn78xx */
        if (handle->index == 0)
        {
            BDK_CSR_MODIFY(c, handle->node, BDK_PKO_MACX_CFG(MAC_NUMBER),
                c.s.fcs_ena = 1; /* FCS */
                c.s.fcs_sop_off = 0; /* No FCS offset */
                c.s.skid_max_cnt = 2); /* All credits to one MAC */
        }
    }
    ilk_write_cal_entry(handle->node, handle->interface, handle->index, handle->pknd, pipe[handle->interface]+handle->index);

    /* Setup PKIND */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_DEFINE(pidx, BDK_ILK_RXF_IDX_PMAP);
        pidx.u64 = 0;
        pidx.s.index = handle->interface * 256 + handle->index;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXF_IDX_PMAP, pidx.u64);
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXF_MEM_PMAP,
            c.s.port_kind = handle->pknd);
    }
    else
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CHAX(handle->interface, handle->index),
            c.s.port_kind = handle->pknd);
    }

    if (handle->index+1 == num_ilk)
    {
        /* For every 15 channels we have an extra calendar entry for link
            status */
        int cal_depth = num_ilk + (num_ilk-1)/15 + 1;

        /* Figure out lanes used by this interface */
        int lane_mask = (1 << bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface)) - 1;
        if (handle->interface)
            lane_mask <<= bdk_config_get(BDK_CONFIG_ILK0_LANES);

        /* Bringup the TX side */
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask;
            c.s.cal_ena = 1;
            c.s.cal_depth = (cal_depth+7) & 0x1f8; /* Round up */
            c.s.lnk_stats_ena = 1);
        /* Configure the RX lanes */
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask;
            c.s.cal_ena = 1;
            c.s.cal_depth = cal_depth;
            c.s.lnk_stats_ena = 1);
        /* RX is brought up during link status polls */
    }

    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    /* Enable the TX path */
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_CFG1(handle->interface),
        c.s.pkt_ena = 1);
    /* The RX path will be enabled if the link is ready */
    if_link_get(handle);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CFG1(handle->interface),
        c.s.pkt_ena = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_CFG1(handle->interface),
        c.s.pkt_ena = 0);
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    int retry_count = 0;
    bdk_if_link_t result;
    result.u64 = 0;

retry:
    /* Only retry a max number of times as we could be bouncing between
        alignment on a bad link */
    retry_count++;
    if (retry_count > 10)
        goto fail;

    /* Read RX config and status bits */
    BDK_CSR_INIT(ilk_rxx_cfg1, handle->node, BDK_ILK_RXX_CFG1(handle->interface));
    BDK_CSR_INIT(ilk_rxx_int, handle->node, BDK_ILK_RXX_INT(handle->interface));

    if (ilk_rxx_cfg1.s.rx_bdry_lock_ena == 0)
    {
        /* Clear the boundary lock status bit */
        ilk_rxx_int.u64 = 0;
        ilk_rxx_int.s.word_sync_done = 1;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_INT(handle->interface), ilk_rxx_int.u64);

        /* We need to start looking for word boundary lock */
        int lane_mask = (1 << bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface)) - 1;
        if (handle->interface)
            lane_mask <<= bdk_config_get(BDK_CONFIG_ILK0_LANES);

        ilk_rxx_cfg1.s.rx_bdry_lock_ena = lane_mask;
        ilk_rxx_cfg1.s.rx_align_ena = 0;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        //printf("ILK%d: Looking for word boundary lock\n", handle->interface);
        goto retry;
    }

    if (ilk_rxx_cfg1.s.rx_align_ena == 0)
    {
        if (ilk_rxx_int.s.word_sync_done)
        {
            /* Clear the lane align status bits */
            ilk_rxx_int.u64 = 0;
            ilk_rxx_int.s.lane_align_fail = 1;
            ilk_rxx_int.s.lane_align_done = 1;
            BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_INT(handle->interface), ilk_rxx_int.u64);

            ilk_rxx_cfg1.s.rx_align_ena = 1;
            BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
            //printf("ILK%d: Looking for lane alignment\n", handle->interface);
            goto retry;
        }
        goto fail;
    }

    if (ilk_rxx_int.s.lane_align_fail)
    {
        ilk_rxx_cfg1.s.rx_bdry_lock_ena = 0;
        ilk_rxx_cfg1.s.rx_align_ena = 0;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        //printf("ILK%d: Lane alignment failed\n", handle->interface);
        goto fail;
    }

    if ((ilk_rxx_cfg1.s.pkt_ena == 0) && ilk_rxx_int.s.lane_align_done)
    {
        /* set the RX to match the TX state set by the if_enable call */
        BDK_CSR_INIT(ilk_txx_cfg1, handle->node, BDK_ILK_TXX_CFG1(handle->interface));
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CFG1(handle->interface),
            c.s.pkt_ena = ilk_txx_cfg1.s.pkt_ena);

        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        {
            /* Enable error interrupts */
            BDK_CSR_MODIFY(c, handle->node, BDK_ILK_GBL_INT_EN,
                c.s.rxf_ctl_perr = -1;
                c.s.rxf_lnk0_perr = -1;
                c.s.rxf_lnk1_perr = -1;
                c.s.rxf_pop_empty = -1;
                c.s.rxf_push_full = -1);
            BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_INT_EN(handle->interface),
                c.s.bad_pipe = -1;
                c.s.bad_seq = -1;
                c.s.txf_err = 0); /* Disable txf_err due to (ILK-16515) ILK_TX*_INT[TXF_ERR] reads as ILK_TX*_INT_EN[TXF_ERR] */
            BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_INT_EN(handle->interface),
                c.s.crc24_err = -1;
                c.s.lane_bad_word = -1;
                c.s.pkt_drop_rid = -1;
                c.s.pkt_drop_rxf = -1;
                c.s.pkt_drop_sop = -1);
        }
        int start_lane = (handle->interface) ? bdk_config_get(BDK_CONFIG_ILK0_LANES) : 0;
        int stop_lane = bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface) + start_lane - 1;
        for (int lane=start_lane; lane<stop_lane; lane++)
        {
            BDK_CSR_DEFINE(stat, BDK_ILK_RX_LNEX_INT(lane));
            stat.u64 = 0;
            stat.s.bad_64b67b = -1;
            stat.s.bdry_sync_loss = -1;
            stat.s.crc32_err = -1;
            stat.s.dskew_fifo_ovfl = -1;
            stat.s.scrm_sync_loss = -1;
            stat.s.serdes_lock_loss = -1;
            stat.s.stat_msg = -1;
            stat.s.ukwn_cntl_word = -1;
            BDK_CSR_WRITE(handle->node, BDK_ILK_RX_LNEX_INT(lane), stat.u64);
            if (OCTEON_IS_MODEL(OCTEON_CN68XX))
                BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RX_LNEX_INT_EN(lane),
                    c.s.bad_64b67b = -1;
                    c.s.bdry_sync_loss = -1;
                    c.s.crc32_err = -1;
                    c.s.dskew_fifo_ovfl = -1;
                    c.s.scrm_sync_loss = -1;
                    c.s.serdes_lock_loss = -1;
                    c.s.stat_msg = -1;
                    c.s.ukwn_cntl_word = -1);
        }
        //printf("ILK%d: Lane alignment complete\n", handle->interface);
    }

    /* Report link speed */
    result.s.up = 1;
    result.s.lanes = bdk_pop(ilk_rxx_cfg1.s.rx_bdry_lock_ena);
    result.s.full_duplex = 1;
    result.s.speed = bdk_qlm_get_gbaud_mhz(handle->node, 1 + handle->interface) * 64 / 67;
    result.s.speed *= result.s.lanes;
    return result;

fail:
    if (ilk_rxx_cfg1.s.pkt_ena)
    {
        ilk_rxx_cfg1.s.pkt_ena = 0;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        /* Disable error interrupts */
        int start_lane = (handle->interface) ? bdk_config_get(BDK_CONFIG_ILK0_LANES) : 0;
        int stop_lane = bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface) + start_lane - 1;
        for (int lane=start_lane; lane<stop_lane; lane++)
        {
            BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RX_LNEX_INT_EN(lane),
                c.s.bad_64b67b = 0;
                c.s.bdry_sync_loss = 0;
                c.s.crc32_err = 0;
                c.s.dskew_fifo_ovfl = 0;
                c.s.scrm_sync_loss = 0;
                c.s.serdes_lock_loss = 0;
                c.s.stat_msg = 0;
                c.s.ukwn_cntl_word = 0;
            );
        }
    }
    return result;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    int internal = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0);
    int external = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_CFG0(handle->interface),
        c.s.int_lpbk = internal);
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_TXX_CFG0(handle->interface),
        c.s.ext_lpbk_fc = external;
        c.s.ext_lpbk = external);
    BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CFG0(handle->interface),
        c.s.ext_lpbk_fc = external;
        c.s.ext_lpbk = external);
    return 0;
}

const __bdk_if_ops_t __bdk_if_ops_ilk = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_loopback = if_loopback,
};


#include <bdk.h>
#include <stdio.h>

static bdk_if_link_t if_link_get(bdk_if_handle_t handle);

static int if_num_interfaces(bdk_node_t node)
{
    if (bdk_qlm_get(node, BDK_IF_ILK, 0) < 0)
        return 0;

    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
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
    /* CN78XX: Loop through QLMs 4-7 counting ILK lanes. The first QLM
        that isn't ILK stops the search */
    int max_lanes = 0;
    for (int qlm=4; qlm<8; qlm++)
    {
        if (bdk_qlm_get_mode(node, qlm) == BDK_QLM_MODE_ILK)
            max_lanes += 4;
    }

    /* In ILK interface only exists if there are lanes configured for it */
    int lanes_interface0 = bdk_config_get(BDK_CONFIG_ILK0_LANES);
    int lanes_interface1 = bdk_config_get(BDK_CONFIG_ILK1_LANES);

    if (interface == 0)
    {
        if (lanes_interface0 > max_lanes)
        {
            bdk_error("ILK0 configured for more lanes than are available\n");
            return 0;
        }
        else if (lanes_interface0 == 0)
            return 0;
    }
    else
    {
        if (lanes_interface0 + lanes_interface1 > max_lanes)
        {
            bdk_error("ILK1 configured for more lanes than are available\n");
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
    ilk_clear_cal_cn78xx(node, interface);
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
    ilk_write_cal_entry_cn78xx(node, interface, channel, bpid, pko_pipe);
}

static int if_init(bdk_if_handle_t handle)
{
    int num_ilk = bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface);
    static int pipe[2] = {-1, -1};

    if (handle->index == 0)
    {
        ilk_clear_cal(handle->node, handle->interface);

        /* Set jabber to allow max sized packets */
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_JABBER(handle->interface),
            c.s.cnt = 0xfff8);
    }
    ilk_write_cal_entry(handle->node, handle->interface, handle->index, handle->pknd, pipe[handle->interface]+handle->index);

    /* Setup PKIND */
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_ILK_RXX_CHAX(handle->interface, handle->index),
            c.s.port_kind = handle->pknd);
    }

    if (handle->index+1 == num_ilk)
    {
        /* For every 15 channels we have an extra calendar entry for link
            status */
        int cal_depth = num_ilk + (num_ilk-1)/15 + 1;

        int lane_mask = 0;
        /* CN78XX: Figure out the total lanes available */
        for (int qlm = 4; qlm < 8; qlm++)
        {
            bdk_qlm_modes_t mode = bdk_qlm_get_mode(handle->node, qlm);
            if (mode == BDK_QLM_MODE_ILK)
            {
                int lanes = bdk_qlm_get_lanes(handle->node, qlm);
                lane_mask |= ((1 << lanes) - 1) << 4*(qlm-4);
            }
        }

        /* Figure out how many lanes we need */
        const int needed_lanes = bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface);
        /* Mask off lanes that are already in use */
        if (handle->interface)
        {
            BDK_CSR_INIT(cfg0, handle->node, BDK_ILK_TXX_CFG0(0));
            lane_mask &= ~cfg0.s.lane_ena;
        }
        /* Clear any lanes that we won't use */
        int lane_count = 0;
        for (int lane = 0; lane < 16; lane++)
        {
            if (lane_mask & (1 << lane))
            {
                /* Lane is valid, count it */
                lane_count++;
                if (lane_count == needed_lanes)
                {
                    /* We found all our lanes, clear unused ones */
                    lane_mask &= (1 << (lane+1)) - 1;
                    break;
                }
            }
        }
        //bdk_dprintf("%s: Using %d lanes, lane_ena=0x%x\n", handle->name, lane_count, lane_mask);

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
        }
        //printf("ILK%d: Lane alignment complete\n", handle->interface);
    }

    /* Report link speed */
    int qlm = bdk_qlm_get(handle->node, BDK_IF_ILK, handle->interface);
    result.s.up = 1;
    result.s.lanes = bdk_pop(ilk_rxx_cfg1.s.rx_bdry_lock_ena);
    result.s.full_duplex = 1;
    result.s.speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm) * 64 / 67;
    result.s.speed *= result.s.lanes;
    return result;

fail:
    if (ilk_rxx_cfg1.s.pkt_ena)
    {
        ilk_rxx_cfg1.s.pkt_ena = 0;
        BDK_CSR_WRITE(handle->node, BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
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

/**
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    if (bdk_unlikely(bdk_is_simulation()))
        return &handle->stats;

    /* Account for TX lack of FCS for most ports */
    const int bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
    const int bytes_off_rx = 0;

    /* Read the RX statistics from PKI */
    BDK_CSR_INIT(rx_packets, handle->node, BDK_ILK_RXX_PKT_CNTX(handle->interface, handle->index));
    BDK_CSR_INIT(rx_octets, handle->node, BDK_ILK_RXX_BYTE_CNTX(handle->interface, handle->index));

    /* Disable drop and error counts because they aren't per channel and PKI
       counters have some sort of issue on CN78XX */
#if 0
    BDK_CSR_INIT(rx_dropped_packets, handle->node, BDK_PKI_STATX_STAT3(handle->pknd));
    BDK_CSR_INIT(rx_dropped_octets, handle->node, BDK_PKI_STATX_STAT4(handle->pknd));
    BDK_CSR_INIT(rx_errors, handle->node, BDK_PKI_STATX_STAT7(handle->pknd));

    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(
        rx_dropped_octets.s.drp_octs, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(
        rx_dropped_packets.s.drp_pkts, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.errors = bdk_update_stat_with_overflow(
        rx_errors.s.fcs, handle->stats.rx.errors, 48);
#endif
    handle->stats.rx.octets -= handle->stats.rx.packets * bytes_off_rx;
    handle->stats.rx.octets = bdk_update_stat_with_overflow(
        rx_octets.s.rx_bytes, handle->stats.rx.octets, 40);
    handle->stats.rx.packets = bdk_update_stat_with_overflow(
        rx_packets.s.rx_pkt, handle->stats.rx.packets, 34);
    handle->stats.rx.octets += handle->stats.rx.packets * bytes_off_rx;

    /* Read the RX statistics from PKO */
    BDK_CSR_INIT(tx_octets, handle->node, BDK_ILK_TXX_PKT_CNTX(handle->interface, handle->index));
    BDK_CSR_INIT(tx_packets, handle->node, BDK_ILK_TXX_BYTE_CNTX(handle->interface, handle->index));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(tx_octets.s.tx_pkt, handle->stats.tx.octets, 40);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(tx_packets.s.tx_bytes, handle->stats.tx.packets, 34);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    return &handle->stats;
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
    .if_get_stats = if_get_stats,
};


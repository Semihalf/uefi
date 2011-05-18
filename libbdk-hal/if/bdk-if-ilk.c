#include <bdk.h>
#include <stdio.h>

static bdk_if_link_t if_link_get(bdk_if_handle_t handle);

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* No ports if QLM speed says disabled */
        if (bdk_qlm_get_gbaud_mhz(1) == 0)
            return 0;
        if (strstr(bdk_qlm_get_mode(1), "ILK") == NULL)
            return 0;

        /* Configure the SERDES */
        BDK_CSR_MODIFY(c, BDK_ILK_SER_CFG,
            c.s.ser_rxpol_auto = 1;
            c.s.ser_rxpol = 0;
            c.s.ser_txpol = 0;
            c.s.ser_reset_n = 0xff;
            c.s.ser_pwrup = 3;
            c.s.ser_haul = 0);
        return 2;
    }
    else
        return 0;
}

static int if_num_ports(int interface)
{
    /* See how many lanes we can potentially have. We already checked QLM1
        when probing the inteface number, now we check QLM2 */
    int max_lanes = (strstr(bdk_qlm_get_mode(2), "ILK")) ? 8 : 4;

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
    /* Use IPD ports 0 - 7 */
    handle->ipd_port = 0x400 + handle->interface*0x100 + handle->index;
    handle->pko_port = __bdk_pko_alloc_port();
    handle->has_fcs = 1;
    return 0;
}

static void ilk_write_cal_entry(int interface, int channel, int bpid, int pko_pipe)
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
    BDK_CSR_WRITE(BDK_ILK_TXX_IDX_CAL(interface), ctidx.u64);
    /* Read the current values */
    BDK_CSR_INIT(tcal0, BDK_ILK_TXX_MEM_CAL0(interface));
    BDK_CSR_INIT(tcal1, BDK_ILK_TXX_MEM_CAL1(interface));

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
    BDK_CSR_WRITE(BDK_ILK_TXX_MEM_CAL0(interface), tcal0.u64);
    BDK_CSR_WRITE(BDK_ILK_TXX_MEM_CAL1(interface), tcal1.u64);

    /* Setup RX write chunk */
    BDK_CSR_DEFINE(cridx, BDK_ILK_RXX_IDX_CAL(interface));
    cridx.u64 = 0;
    cridx.s.index = table_chunk;
    BDK_CSR_WRITE(BDK_ILK_RXX_IDX_CAL(interface), cridx.u64);
    /* Read the current values */
    BDK_CSR_INIT(rcal0, BDK_ILK_RXX_MEM_CAL0(interface));
    BDK_CSR_INIT(rcal1, BDK_ILK_RXX_MEM_CAL1(interface));

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
    BDK_CSR_WRITE(BDK_ILK_RXX_MEM_CAL0(interface), rcal0.u64);
    BDK_CSR_WRITE(BDK_ILK_RXX_MEM_CAL1(interface), rcal1.u64);
}

static int if_init(bdk_if_handle_t handle)
{
    int num_ilk = bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface);
    static int pko_eid[2] = {-1, -1};
    static int pipe[2] = {-1, -1};
    if (pko_eid[handle->interface] == -1)
    {
        /* All ports use same eid and intr */
        pko_eid[handle->interface] = __bdk_pko_alloc_engine();
        pipe[handle->interface] = __bdk_pko_alloc_pipe(num_ilk);
    }

    if (handle->index == 0)
    {
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_PIPE(handle->interface),
            c.s.nump = num_ilk;
            c.s.base = pipe[handle->interface]);

        /* Set jabber to allow max sized packets */
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_JABBER(handle->interface),
            c.s.cnt = 0xfff8);
    }

    BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
    ptrs.u64 = 0;
    ptrs.s.qos_mask = 0xff; /* QOS rounds */
    ptrs.s.crc = 1;         /* Use CRC on packets */
    ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
    ptrs.s.pipe = pipe[handle->interface]+handle->index;
    ptrs.s.intr = 28+handle->interface; /* Which interface */
    ptrs.s.eid = pko_eid[handle->interface];  /* Which engine */
    ptrs.s.ipid = handle->pko_port;
    BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

    /* Map pipes to channels */
    BDK_CSR_DEFINE(idx, BDK_ILK_TXX_IDX_PMAP(handle->interface));
    idx.u64 = 0;
    idx.s.index = pipe[handle->interface]+handle->index;
    BDK_CSR_WRITE(BDK_ILK_TXX_IDX_PMAP(handle->interface), idx.u64);
    BDK_CSR_WRITE(BDK_ILK_TXX_MEM_PMAP(handle->interface), handle->index);
    ilk_write_cal_entry(handle->interface, handle->index, handle->pknd, pipe[handle->interface]+handle->index);

    /* Setup PKIND */
    BDK_CSR_DEFINE(pidx, BDK_ILK_RXF_IDX_PMAP);
    pidx.u64 = 0;
    pidx.s.index = handle->interface * 256 + handle->index;
    BDK_CSR_WRITE(BDK_ILK_RXF_IDX_PMAP, pidx.u64);
    BDK_CSR_MODIFY(c, BDK_ILK_RXF_MEM_PMAP,
        c.s.port_kind = handle->pknd);

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
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask;
            c.s.cal_ena = 1;
            c.s.cal_depth = (cal_depth+7) & 0x1f8; /* Round up */
            c.s.lnk_stats_ena = 1);
        /* Configure the RX lanes */
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG0(handle->interface),
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
    BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG1(handle->interface),
        c.s.pkt_ena = 1);
    /* The RX path will be enabled if the link is ready */
    if_link_get(handle);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
        c.s.pkt_ena = 0);
    BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG1(handle->interface),
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
        goto out;

    /* Read RX config and status bits */
    BDK_CSR_INIT(ilk_rxx_cfg1, BDK_ILK_RXX_CFG1(handle->interface));
    BDK_CSR_INIT(ilk_rxx_int, BDK_ILK_RXX_INT(handle->interface));

    /* Clear all RX status bits */
    if (ilk_rxx_int.u64)
        BDK_CSR_WRITE(BDK_ILK_RXX_INT(handle->interface), ilk_rxx_int.u64);

    if (ilk_rxx_cfg1.s.rx_bdry_lock_ena == 0)
    {
        /* We need to start looking for word boundary lock */
        int lane_mask = (1 << bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface)) - 1;
        if (handle->interface)
            lane_mask <<= bdk_config_get(BDK_CONFIG_ILK0_LANES);

        ilk_rxx_cfg1.s.rx_bdry_lock_ena = lane_mask;
        ilk_rxx_cfg1.s.rx_align_ena = 0;
        BDK_CSR_WRITE(BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        //printf("ILK%d: Looking for word boundary lock\n", handle->interface);
        goto retry;
    }

    if (ilk_rxx_cfg1.s.rx_align_ena == 0)
    {
        if (ilk_rxx_int.s.word_sync_done)
        {
            ilk_rxx_cfg1.s.rx_align_ena = 1;
            BDK_CSR_WRITE(BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
            //printf("ILK%d: Looking for lane alignment\n", handle->interface);
            goto retry;
        }
        goto out;
    }

    if (ilk_rxx_int.s.lane_align_fail)
    {
        ilk_rxx_cfg1.s.rx_bdry_lock_ena = 0;
        ilk_rxx_cfg1.s.rx_align_ena = 0;
        BDK_CSR_WRITE(BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        printf("ILK%d: Lane alignment failed\n", handle->interface);
        goto out;
    }

    if (ilk_rxx_int.s.lane_align_done)
    {
        //printf("ILK%d: Lane alignment complete\n", handle->interface);
    }

    result.s.up = 1;
    result.s.lanes = bdk_pop(ilk_rxx_cfg1.s.rx_bdry_lock_ena);
    result.s.full_duplex = 1;
    result.s.speed = bdk_qlm_get_gbaud_mhz(1 + handle->interface) * 64 / 67;
    result.s.speed *= result.s.lanes;

out:
    /* If the link is down we will force disable the RX path. If it up, we'll
        set it to match the TX state set by the if_enable call */
    if (result.s.up)
    {
        BDK_CSR_INIT(ilk_txx_cfg1, BDK_ILK_TXX_CFG1(handle->interface));
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
            c.s.pkt_ena = ilk_txx_cfg1.s.pkt_ena);
    }
    else
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
            c.s.pkt_ena = 0);
    return result;
}

const __bdk_if_ops_t __bdk_if_ops_ilk = {
    .name = "ILK",
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


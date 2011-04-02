#include <bdk.h>
#include <stdio.h>

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(1));
        if (qlm_cfg.s.qlm_cfg != 1)
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
    BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(2));

    /* See how many lanes we can potentially have. We already checked QLM1
        when probing the inteface number, now we check QLM2 */
    int max_lanes = (qlm_cfg.s.qlm_cfg == 1) ? 8 : 4;

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
    /* Use PKO ports 72+ */
    handle->pko_port = 72 + handle->interface*bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface) + handle->index;
    handle->has_fcs = 1;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    if (handle->index == 0)
    {
        /* All ports use same eid and intr */
        int pko_eid = __bdk_pko_alloc_engine();
        int num_ilk = bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface);
        int pipe = __bdk_pko_alloc_pipe(num_ilk);
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_PIPE(handle->interface),
            c.s.nump = num_ilk;
            c.s.base = pipe);
        for (int i=0; i<num_ilk; i++)
        {
            BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
            ptrs.u64 = 0;
            ptrs.s.qos_mask = 0xff; /* QOS rounds */
            ptrs.s.crc = 1;         /* Use CRC on packets */
            ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
            ptrs.s.pipe = pipe+i;
            ptrs.s.intr = 28+handle->interface; /* Which interface */
            ptrs.s.eid = pko_eid;  /* Which engine */
            ptrs.s.ipid = handle->pko_port + i;
            BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

            /* Map pipes to channels */
            BDK_CSR_DEFINE(idx, BDK_ILK_TXX_IDX_PMAP(handle->interface));
            idx.u64 = 0;
            idx.s.index = pipe+i;
            BDK_CSR_WRITE(BDK_ILK_TXX_IDX_PMAP(handle->interface), idx.u64);
            BDK_CSR_WRITE(BDK_ILK_TXX_MEM_PMAP(handle->interface), i);
        }

        /* Figure out lanes used by this interface */
        int lane_mask = (1 << bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface)) - 1;
        if (handle->interface)
            lane_mask <<= bdk_config_get(BDK_CONFIG_ILK0_LANES);

        /* Set jabber to allow max sized packets */
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_JABBER(handle->interface),
            c.s.cnt = 0xfff8);

        /* Bringup the TX side */
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask;
            c.s.cal_ena = 0;
            c.s.cal_depth = num_ilk;
            c.s.lnk_stats_ena = 1);
        /* Ignore the global link flow control as we are using per pko port */
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG1(handle->interface),
            c.s.rx_link_fc_ign = 1);
        /* Configure the RX lanes */
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask;
            c.s.cal_ena = 0;
            c.s.cal_depth = num_ilk;
            c.s.lnk_stats_ena = 1);
        /* RX is brought up during lin status polls */
    }

    /* Setup PKIND */
    BDK_CSR_DEFINE(pidx, BDK_ILK_RXF_IDX_PMAP);
    pidx.u64 = 0;
    pidx.s.index = handle->interface * 256 + handle->index;
    BDK_CSR_WRITE(BDK_ILK_RXF_IDX_PMAP, pidx.u64);
    BDK_CSR_MODIFY(c, BDK_ILK_RXF_MEM_PMAP,
        c.s.port_kind = handle->pknd);

    /* Setup TX BPID */
    BDK_CSR_DEFINE(ctidx, BDK_ILK_TXX_IDX_CAL(handle->interface));
    ctidx.u64 = 0;
    ctidx.s.index = handle->index / 8;
    BDK_CSR_WRITE(BDK_ILK_TXX_IDX_CAL(handle->interface), ctidx.u64);
    BDK_CSR_INIT(tcal0, BDK_ILK_TXX_MEM_CAL0(handle->interface));
    BDK_CSR_INIT(tcal1, BDK_ILK_TXX_MEM_CAL1(handle->interface));
    switch (handle->index & 7)
    {
        case 0:
            tcal0.s.entry_ctl0 = 0;
            tcal0.s.bpid0 = handle->pknd;
            break;
        case 1:
            tcal0.s.entry_ctl1 = 0;
            tcal0.s.bpid1 = handle->pknd;
            break;
        case 2:
            tcal0.s.entry_ctl2 = 0;
            tcal0.s.bpid2 = handle->pknd;
            break;
        case 3:
            tcal0.s.entry_ctl3 = 0;
            tcal0.s.bpid3 = handle->pknd;
            break;
        case 4:
            tcal1.s.entry_ctl4 = 0;
            tcal1.s.bpid4 = handle->pknd;
            break;
        case 5:
            tcal1.s.entry_ctl5 = 0;
            tcal1.s.bpid5 = handle->pknd;
            break;
        case 6:
            tcal1.s.entry_ctl6 = 0;
            tcal1.s.bpid6 = handle->pknd;
            break;
        case 7:
            tcal1.s.entry_ctl7 = 0;
            tcal1.s.bpid7 = handle->pknd;
            break;
    }
    BDK_CSR_WRITE(BDK_ILK_TXX_MEM_CAL0(handle->interface), tcal0.u64);
    BDK_CSR_WRITE(BDK_ILK_TXX_MEM_CAL1(handle->interface), tcal1.u64);

    /* Setup RX BPID */
    BDK_CSR_DEFINE(cridx, BDK_ILK_RXX_IDX_CAL(handle->interface));
    cridx.u64 = 0;
    cridx.s.index = handle->index / 8;
    BDK_CSR_WRITE(BDK_ILK_RXX_IDX_CAL(handle->interface), cridx.u64);
    BDK_CSR_INIT(rcal0, BDK_ILK_RXX_MEM_CAL0(handle->interface));
    BDK_CSR_INIT(rcal1, BDK_ILK_RXX_MEM_CAL1(handle->interface));
    switch (handle->index & 7)
    {
        case 0:
            rcal0.s.entry_ctl0 = 0;
            rcal0.s.port_pipe0 = handle->pko_port;
            break;
        case 1:
            rcal0.s.entry_ctl1 = 0;
            rcal0.s.port_pipe1 = handle->pko_port;
            break;
        case 2:
            rcal0.s.entry_ctl2 = 0;
            rcal0.s.port_pipe2 = handle->pko_port;
            break;
        case 3:
            rcal0.s.entry_ctl3 = 0;
            rcal0.s.port_pipe3 = handle->pko_port;
            break;
        case 4:
            rcal1.s.entry_ctl4 = 0;
            rcal1.s.port_pipe4 = handle->pko_port;
            break;
        case 5:
            rcal1.s.entry_ctl5 = 0;
            rcal1.s.port_pipe5 = handle->pko_port;
            break;
        case 6:
            rcal1.s.entry_ctl6 = 0;
            rcal1.s.port_pipe6 = handle->pko_port;
            break;
        case 7:
            rcal1.s.entry_ctl7 = 0;
            rcal1.s.port_pipe7 = handle->pko_port;
            break;
    }
    BDK_CSR_WRITE(BDK_ILK_RXX_MEM_CAL0(handle->interface), rcal0.u64);
    BDK_CSR_WRITE(BDK_ILK_RXX_MEM_CAL1(handle->interface), rcal1.u64);

    if (handle->index+1 == (int)bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface))
    {
            /* Enable calendar */
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG0(handle->interface), c.s.cal_ena = 1);
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG0(handle->interface), c.s.cal_ena = 1);
    }

    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
        c.s.pkt_ena = 1);
    BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG1(handle->interface),
        c.s.pkt_ena = 1);
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
        return result;

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
        bdk_wait_usec(10000);
        goto retry;
    }

    if (ilk_rxx_cfg1.s.rx_align_ena == 0)
    {
        if (ilk_rxx_int.s.word_sync_done)
        {
            ilk_rxx_cfg1.s.rx_align_ena = 1;
            BDK_CSR_WRITE(BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
            //printf("ILK%d: Looking for lane alignment\n", handle->interface);
            bdk_wait_usec(10000);
            goto retry;
        }
        return result;
    }

    if (ilk_rxx_int.s.lane_align_fail)
    {
        ilk_rxx_cfg1.s.rx_bdry_lock_ena = 0;
        ilk_rxx_cfg1.s.rx_align_ena = 0;
        BDK_CSR_WRITE(BDK_ILK_RXX_CFG1(handle->interface), ilk_rxx_cfg1.u64);
        printf("ILK%d: Lane alignment failed\n", handle->interface);
        return result;
    }

    if (ilk_rxx_int.s.lane_align_done)
    {
        //printf("ILK%d: Lane alignment complete\n", handle->interface);
    }

    result.s.up = 1;
    result.s.lanes = bdk_pop(ilk_rxx_cfg1.s.rx_bdry_lock_ena);
    result.s.full_duplex = 1;

    BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(1 + handle->interface));
    switch (qlm_cfg.s.qlm_spd)
    {
        case 0: /* 5 Gbaud */
        case 6: /* 5 Gbaud */
        case 11: /* 5 Gbaud */
            result.s.speed = 5000 * 64 / 67;
            break;
        case 1: /* 2.5 Gbaud */
        case 2: /* 2.5 Gbaud */
            result.s.speed = 2500 * 64 / 67;
            break;
        case 3: /* 1.25 Gbaud */
        case 4: /* 1.25 Gbaud */
        case 10: /* 1.25 Gbaud */
            result.s.speed = 1250 * 64 / 67;
            break;
        case 5: /* 6.25 Gbaud */
        case 12: /* 6.25 Gbaud */
            result.s.speed = 6250 * 64 / 67;
            break;
        case 7: /* 2.5 Gbaud */
        case 9: /* 2.5 Gbaud */
            result.s.speed = 2500 * 64 / 67;
            break;
        case 8: /* 3.125 Gbaud */
        case 14: /* 3.125 Gbaud */
            result.s.speed = 3125 * 64 / 67;
            break;
        case 13: /* 3.75 Gbaud */
            result.s.speed = 3750 * 64 / 67;
            break;
        default:
            break;
    }
    result.s.speed *= result.s.lanes;

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


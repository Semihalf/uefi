#include <bdk.h>

static int if_num_interfaces(bdk_node_t node)
{
    if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        return 2;
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 5;
    else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 0; /* Covered by bdk-if-bgx */
    else if (OCTEON_IS_MODEL(OCTEON_CN70XX))
        return 1; /* CN70XX can have RXAUI on DLM0 */
    else
        return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    /* As a kludge to reuse code, the Higig IFs call this function
        to tell if XAUI is there. Normally this routine would return
        no ports, but a negative interface overrides this. When
        a negative interface is supplied then we should return the
        number of XAUI ports ignoring the fact that they are in Higig
        mode */
    int skip_higig_check = (interface < 0);
    /* Higig calls us with "-interface-1", so fix the interface number
        here */
    if (interface < 0)
        interface = -interface-1;

    if (bdk_qlm_get(node, BDK_IF_XAUI, interface) < 0)
        return 0;

    /* Check if we should skip this port if we are probing XAUI and it is
        in Higig mode */
    if (!skip_higig_check && bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface))
        return 0;

    return 1;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be "XAUI%d" */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "XAUI%d", handle->interface);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.XAUI%d", handle->node, handle->interface);
    handle->name[sizeof(handle->name)-1] = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0x840, 0x940, ... */
        handle->ipd_port = 0x840 + handle->interface*0x100;
    }
    else
    {
        /* Use IPD ports 0, 4, 8, ... */
        handle->ipd_port = handle->interface*16 + handle->index;
    }
    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
    return 0;
}

static int xaui_link_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);

    /* (1) Interface has already been enabled. */

    /* (2) Disable GMX. */
    BDK_CSR_MODIFY(c, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index),
        c.s.gmxeno = 1);

    /* (3) Disable GMX and PCSX interrupts. */
    BDK_CSR_WRITE(handle->node, BDK_GMXX_RXX_INT_EN(gmx_block, gmx_index), 0x0);
    BDK_CSR_WRITE(handle->node, BDK_GMXX_TX_INT_EN(gmx_block), 0x0);
    BDK_CSR_WRITE(handle->node, BDK_PCSXX_INT_EN_REG(gmx_block), 0x0);

    /* (4) Bring up the PCSX and GMX reconciliation layer. */
    /* (4)a Set polarity and lane swapping. */
    /* (4)b */
    BDK_CSR_MODIFY(gmxXauiTxCtl, handle->node, BDK_GMXX_TX_XAUI_CTL(gmx_block),
        gmxXauiTxCtl.s.dic_en = 1; /* Enable better IFG packing and improves performance */
        gmxXauiTxCtl.s.uni_en = 0);

    /* (4)c Power up the interface */
    BDK_CSR_MODIFY(xauiCtl, handle->node, BDK_PCSXX_CONTROL1_REG(gmx_block),
        xauiCtl.s.lo_pwr = 0);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X) && (gmx_block != 1))
    {
        extern void __bdk_qlm_powerup_G16467_part2(int qlm);
        /* Note that GMX 1 was skipped as GMX0 is on the same QLM and
            will always be done first */
        /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive
            QLM jitter for 6.25 Gbaud */
        __bdk_qlm_powerup_G16467_part2(bdk_qlm_get(handle->node, BDK_IF_XAUI, gmx_block));
    }

    /* Wait for PCS to come out of reset */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSXX_CONTROL1_REG(gmx_block), reset, ==, 0, 10000))
        return -1;
    /* Wait for PCS to be aligned */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSXX_10GBX_STATUS_REG(gmx_block), alignd, ==, 1, 10000))
        return -1;
    /* Wait for RX to be ready */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_RX_XAUI_CTL(gmx_block), status, ==, 0, 10000))
        return -1;

    /* (6) Configure GMX */

    /* Wait for GMX RX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), rx_idle, ==, 1, 10000))
        return -1;
    /* Wait for GMX TX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), tx_idle, ==, 1, 10000))
        return -1;

    /* GMX configure */
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        c.s.speed = 1;
        c.s.speed_msb = 0;
        c.s.slottime = 1);
    BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_SLOT(gmx_block, gmx_index), 512);
    BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_BURST(gmx_block, gmx_index), 8192);

    /* Wait for receive link */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSXX_STATUS1_REG(gmx_block), rcv_lnk, ==, 1, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSXX_STATUS2_REG(gmx_block), xmtflt, ==, 0, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSXX_STATUS2_REG(gmx_block), rcvflt, ==, 0, 10000))
        return -1;

    /* (8) Enable packet reception */
    BDK_CSR_MODIFY(c, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index),
        c.s.gmxeno = 0);

    /* Enable error interrupts */
    BDK_CSR_MODIFY(c, handle->node, BDK_PCSXX_INT_EN_REG(gmx_block),
        c.s.algnlos_en = -1;
        c.s.bitlckls_en = -1;
        c.s.dbg_sync_en = -1;
        c.s.rxbad_en = -1;
        c.s.rxsynbad_en = -1;
        c.s.synlos_en = -1;
        c.s.txflt_en = -1;
    );
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_RXX_INT_EN(gmx_block, gmx_index),
        c.s.bad_seq = -1;
        c.s.bad_term = -1;
        c.s.carext = -1;
        c.s.hg2cc = -1;
        c.s.hg2fld = -1;
        c.s.loc_fault = -1;
        c.s.ovrerr = -1;
        c.s.rem_fault = -1;
        c.s.skperr = -1;
        c.s.undat = -1;
        c.s.uneop = -1;
        c.s.unsop = -1;
    );
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TX_INT_EN(gmx_block),
        c.s.pko_nxa = -1;
        c.s.pko_nxp = -1;
        c.s.ptp_lost = -1;
        c.s.undflw = -1;
    );

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Configure the PKO internal port mappings */
        int pipe = __bdk_pko_alloc_pipe(handle->node, 1);
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TXX_PIPE(gmx_block, 0),
            c.s.nump = 1;
            c.s.base = pipe);
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */
        ptrs.s.crc = 1;         /* Use CRC on packets */
        ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
        ptrs.s.pipe = pipe;     /* Which PKO pipe */
        ptrs.s.intr = gmx_block*4;  /* Which interface */
        ptrs.s.eid = __bdk_pko_alloc_engine(handle->node);
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Setup PKIND */
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, 0),
            c.s.pknd = handle->pknd);

        /* Setup BPID */
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_BPID_MAPX(gmx_block, 0),
            c.s.val = 1;
            c.s.bpid = handle->pknd);
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_BPID_MSK(gmx_block),
            c.s.msk_or |= 1;
            c.s.msk_and &= ~1);
    }

    /* Due to errata GMX-700 on CN56XXp1.x and CN52XXp1.x, the interface
        needs to be enabled before IPD otherwise per port backpressure
        may not work properly */
    BDK_CSR_MODIFY(mode, handle->node, BDK_GMXX_INF_MODE(gmx_block),
        mode.s.en = 1);

    /* Tell GMX the number of TX ports on this interface */
    BDK_CSR_MODIFY(gmx_tx_prts, handle->node, BDK_GMXX_TX_PRTS(gmx_block),
        gmx_tx_prts.s.prts = 1);

    /* Tell GMX the number of RX ports on this interface */
    BDK_CSR_MODIFY(gmx_rx_prts, handle->node, BDK_GMXX_RX_PRTS(gmx_block),
        gmx_rx_prts.s.prts = 1);

    if (OCTEON_IS_MODEL(OCTEON_CN61XX))
    {
        /* Tell PKO the number of ports on this interface */
        BDK_CSR_MODIFY(pko_mode, handle->node, BDK_PKO_REG_GMX_PORT_MODE,
            if (gmx_block == 0)
                    pko_mode.s.mode0 = 4;
            else
                    pko_mode.s.mode1 = 4;
            );
    }

    /* Set GMX to buffer as much data as possible before starting transmit.
        This reduces the chances that we have a TX under run due to memory
        contention. Any packet that fits entirely in the GMX FIFO can never
        have an under run regardless of memory load */
    BDK_CSR_MODIFY(gmx_tx_thresh, handle->node, BDK_GMXX_TXX_THRESH(gmx_block, 0),
        gmx_tx_thresh.s.cnt = 0x100);

    /* Configure to allow max sized frames */
    BDK_CSR_WRITE(handle->node, BDK_GMXX_RXX_JABBER(gmx_block, 0), 65535);

    /* CN68XX adds the padding and FCS in PKO, not GMX */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TXX_APPEND(gmx_block, 0),
            c.s.fcs = 0;
            c.s.pad = 0);

    xaui_link_init(handle);
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        c.s.en = 1);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        c.s.en = 0);
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    bdk_gmxx_tx_xaui_ctl_t gmxx_tx_xaui_ctl;
    bdk_gmxx_rx_xaui_ctl_t gmxx_rx_xaui_ctl;
    bdk_pcsxx_status1_reg_t pcsxx_status1_reg;
    bdk_if_link_t result;

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(handle->node, BDK_GMXX_TX_XAUI_CTL(gmx_block));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(handle->node, BDK_GMXX_RX_XAUI_CTL(gmx_block));
    pcsxx_status1_reg.u64 = BDK_CSR_READ(handle->node, BDK_PCSXX_STATUS1_REG(gmx_block));
    result.u64 = 0;

    /* Only return a link if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls == 0) && (gmxx_rx_xaui_ctl.s.status == 0) &&
        (pcsxx_status1_reg.s.rcv_lnk == 1))
    {
        int qlm = bdk_qlm_get(handle->node, BDK_IF_XAUI, handle->interface);
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        {
            BDK_CSR_INIT(qlm_cfg, handle->node, BDK_MIO_QLMX_CFG(qlm));
            result.s.lanes = (qlm_cfg.s.qlm_cfg == 7) ? 2 : 4;
        }
        else if (OCTEON_IS_MODEL(OCTEON_CN70XX))
            result.s.lanes = 2; /* CN70XX is RXAUI */
        else
            result.s.lanes = 4;
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm) * 8 / 10;
        result.s.speed *= result.s.lanes;

        BDK_CSR_INIT(misc_ctl, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index));
        if (misc_ctl.s.gmxeno)
            xaui_link_init(handle);
    }
    else
    {
        /* Disable GMX and PCSX interrupts. */
        BDK_CSR_WRITE(handle->node, BDK_GMXX_RXX_INT_EN(gmx_block, gmx_index), 0x0);
        BDK_CSR_WRITE(handle->node, BDK_GMXX_TX_INT_EN(gmx_block), 0x0);
        BDK_CSR_WRITE(handle->node, BDK_PCSXX_INT_EN_REG(gmx_block), 0x0);
        /* Reset PCS if some lanes are up but not others */
        BDK_CSR_INIT(status, handle->node, BDK_PCSXX_10GBX_STATUS_REG(gmx_block));
        if (!status.s.alignd && (status.s.l0sync || status.s.l1sync || status.s.l2sync || status.s.l3sync))
            BDK_CSR_MODIFY(c, handle->node, BDK_PCSXX_CONTROL1_REG(gmx_block),
                c.s.reset=1);
    }
    return result;
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    /* If the link shouldn't be up, then just return */
    if (!link_info.s.up)
        return;

    int gmx_block = __bdk_if_get_gmx_block(handle);
    bdk_gmxx_tx_xaui_ctl_t gmxx_tx_xaui_ctl;
    bdk_gmxx_rx_xaui_ctl_t gmxx_rx_xaui_ctl;

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(handle->node, BDK_GMXX_TX_XAUI_CTL(gmx_block));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(handle->node, BDK_GMXX_RX_XAUI_CTL(gmx_block));

    /* Do nothing if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls != 0) || (gmxx_rx_xaui_ctl.s.status != 0))
        xaui_link_init(handle);
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);

    /* Set the internal loop */
    BDK_CSR_MODIFY(c, handle->node, BDK_PCSXX_CONTROL1_REG(gmx_block),
        c.s.loopbck1 = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));

    /* Set the external loop */
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_XAUI_EXT_LOOPBACK(gmx_block),
        c.s.en = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0));
    return 0;
}

const __bdk_if_ops_t __bdk_if_ops_xaui = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_set = if_link_set,
    .if_loopback = if_loopback,
};


#include <bdk.h>

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        return 2;
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 1;
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
        return 2;
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 5;
    else
        return 0;
}

static int if_num_ports(int interface)
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

    /* Check if we should skip this port if we are probing XAUI and it is
        in Higig mode */
    if (!skip_higig_check && bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface))
        return 0;

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* GMX1 is RXAUI only if GMX0 is RXAUI */
        if (interface == 1)
        {
            /* No ports if QLM speed says disabled */
            if (bdk_qlm_get_gbaud_mhz(0) == 0)
                return 0;
            BDK_CSR_INIT(inf_mode, BDK_GMXX_INF_MODE(0));
            if (inf_mode.s.mode == 7)
                return 1;
            else
                return 0;
        }
        else
        {
            /* No ports if QLM speed says disabled */
            if (bdk_qlm_get_gbaud_mhz(interface) == 0)
                return 0;
            /* All other GMXs are the same mode as the QLM with same number */
            BDK_CSR_INIT(inf_mode, BDK_GMXX_INF_MODE(interface));
            if ((inf_mode.s.mode == 3) || (inf_mode.s.mode == 7))
                return 1;
            else
                return 0;
        }
    }

    BDK_CSR_INIT(mode, BDK_GMXX_INF_MODE(interface));
    if (mode.s.type == 1)
        return 1;
    else
        return 0;
}

static int if_probe(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0x840, 0x940, ... */
        handle->ipd_port = 0x840 + handle->interface*0x100;
        handle->pko_port = __bdk_pko_alloc_port();
    }
    else
    {
        /* Use IPD ports 0, 4, 8, ... */
        handle->ipd_port = handle->interface*16 + handle->index;
        /* PKO ports are the same as IPD */
        handle->pko_port = handle->ipd_port;
    }
    handle->has_fcs = 1;
    return 0;
}

static int xaui_link_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);

    /* (1) Interface has already been enabled. */

    /* (2) Disable GMX. */
    BDK_CSR_MODIFY(c, BDK_PCSX_MISCX_CTL_REG(gmx_index, gmx_block),
        c.s.gmxeno = 1);

    /* (3) Disable GMX and PCSX interrupts. */
    BDK_CSR_WRITE(BDK_GMXX_RXX_INT_EN(gmx_index,gmx_block), 0x0);
    BDK_CSR_WRITE(BDK_GMXX_TX_INT_EN(gmx_block), 0x0);
    BDK_CSR_WRITE(BDK_PCSXX_INT_EN_REG(gmx_block), 0x0);

    /* (4) Bring up the PCSX and GMX reconciliation layer. */
    /* (4)a Set polarity and lane swapping. */
    /* (4)b */
    BDK_CSR_MODIFY(gmxXauiTxCtl, BDK_GMXX_TX_XAUI_CTL(gmx_block),
        gmxXauiTxCtl.s.dic_en = 1; /* Enable better IFG packing and improves performance */
        gmxXauiTxCtl.s.uni_en = 0);

    /* (4)c Power up the interface */
    BDK_CSR_MODIFY(xauiCtl, BDK_PCSXX_CONTROL1_REG(gmx_block),
        xauiCtl.s.lo_pwr = 0);

    /* Wait for PCS to come out of reset */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_CONTROL1_REG(gmx_block), reset, ==, 0, 10000))
        return -1;
    /* Wait for PCS to be aligned */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_10GBX_STATUS_REG(gmx_block), alignd, ==, 1, 10000))
        return -1;
    /* Wait for RX to be ready */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_RX_XAUI_CTL(gmx_block), status, ==, 0, 10000))
        return -1;

    /* (6) Configure GMX */

    /* Wait for GMX RX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block), rx_idle, ==, 1, 10000))
        return -1;
    /* Wait for GMX TX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block), tx_idle, ==, 1, 10000))
        return -1;

    /* GMX configure */
    BDK_CSR_MODIFY(c, BDK_GMXX_PRTX_CFG(gmx_index, gmx_block),
        c.s.speed = 1;
        c.s.speed_msb = 0;
        c.s.slottime = 1);
    BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(gmx_index, gmx_block), 512);
    BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(gmx_index, gmx_block), 8192);

    /* Wait for receive link */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS1_REG(gmx_block), rcv_lnk, ==, 1, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(gmx_block), xmtflt, ==, 0, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(gmx_block), rcvflt, ==, 0, 10000))
        return -1;

    /* (8) Enable packet reception */
    BDK_CSR_MODIFY(c, BDK_PCSX_MISCX_CTL_REG(gmx_index, gmx_block),
        c.s.gmxeno = 0);

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Configure the PKO internal port mappings */
        int pipe = __bdk_pko_alloc_pipe(1);
        BDK_CSR_MODIFY(c, BDK_GMXX_TXX_PIPE(0, gmx_block),
            c.s.nump = 1;
            c.s.base = pipe);
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */
        ptrs.s.crc = 1;         /* Use CRC on packets */
        ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
        ptrs.s.pipe = pipe;     /* Which PKO pipe */
        ptrs.s.intr = gmx_block*4;  /* Which interface */
        ptrs.s.eid = __bdk_pko_alloc_engine();
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Setup PKIND */
        BDK_CSR_MODIFY(c, BDK_GMXX_PRTX_CFG(0, gmx_block),
            c.s.pknd = handle->pknd);

        /* Setup BPID */
        BDK_CSR_MODIFY(c, BDK_GMXX_BPID_MAPX(0, gmx_block),
            c.s.val = 1;
            c.s.bpid = handle->pknd);
        BDK_CSR_MODIFY(c, BDK_GMXX_BPID_MSK(gmx_block),
            c.s.msk_or |= 1;
            c.s.msk_and &= ~1);
    }

    /* CN63XX Pass 1.0 errata G-14395 requires the QLM De-emphasis be programmed */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
    {
        BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 0x5;
            ciu_qlm.s.txmargin = 0x1a);
    }

    /* CN63XX Pass 2.0 and 2.1 errata G-15273 requires the QLM De-emphasis be
        programmed when using a 156.25Mhz ref clock */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS2_0) ||
        OCTEON_IS_MODEL(OCTEON_CN63XX_PASS2_1))
    {
        /* Read the QLM speed pins */
        BDK_CSR_INIT(mio_rst_boot, BDK_MIO_RST_BOOT);
        if (mio_rst_boot.cn63xx.qlm2_spd == 0xb)
        {
            BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
                ciu_qlm.s.txbypass = 1;
                ciu_qlm.s.txdeemph = 0xa;
                ciu_qlm.s.txmargin = 0x1f);
        }
    }

    /* Due to errata GMX-700 on CN56XXp1.x and CN52XXp1.x, the interface
        needs to be enabled before IPD otherwise per port backpressure
        may not work properly */
    BDK_CSR_MODIFY(mode, BDK_GMXX_INF_MODE(gmx_block),
        mode.s.en = 1);

    /* Tell GMX the number of TX ports on this interface */
    BDK_CSR_MODIFY(gmx_tx_prts, BDK_GMXX_TX_PRTS(gmx_block),
        gmx_tx_prts.s.prts = 1);

    /* Tell GMX the number of RX ports on this interface */
    BDK_CSR_MODIFY(gmx_rx_prts, BDK_GMXX_RX_PRTS(gmx_block),
        gmx_rx_prts.s.prts = 1);

    if (OCTEON_IS_MODEL(OCTEON_CN61XX) || OCTEON_IS_MODEL(OCTEON_CN63XX) || OCTEON_IS_MODEL(OCTEON_CN66XX))
    {
        /* Tell PKO the number of ports on this interface */
        BDK_CSR_MODIFY(pko_mode, BDK_PKO_REG_GMX_PORT_MODE,
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
    BDK_CSR_MODIFY(gmx_tx_thresh, BDK_GMXX_TXX_THRESH(0, gmx_block),
        gmx_tx_thresh.s.cnt = 0x100);

    /* Configure to allow max sized frames */
    BDK_CSR_WRITE(BDK_GMXX_RXX_JABBER(0, gmx_block), 65535);

    /* CN68XX adds the padding and FCS in PKO, not GMX */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_MODIFY(c, BDK_GMXX_TXX_APPEND(0, gmx_block),
            c.s.fcs = 0;
            c.s.pad = 0);

    xaui_link_init(handle);
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(c, BDK_GMXX_PRTX_CFG(gmx_index, gmx_block),
        c.s.en = 1);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(c, BDK_GMXX_PRTX_CFG(gmx_index, gmx_block),
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

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(gmx_block));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RX_XAUI_CTL(gmx_block));
    pcsxx_status1_reg.u64 = BDK_CSR_READ(BDK_PCSXX_STATUS1_REG(gmx_block));
    result.u64 = 0;

    /* Only return a link if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls == 0) && (gmxx_rx_xaui_ctl.s.status == 0) &&
        (pcsxx_status1_reg.s.rcv_lnk == 1))
    {
        result.s.up = 1;
        result.s.full_duplex = 1;
        if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        {
            int qlm = (gmx_block == 1) ? 0 : gmx_block;
            BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
            int speed = bdk_qlm_get_gbaud_mhz(qlm);
            result.s.speed = speed * 8 / 10;
            result.s.lanes = (qlm_cfg.s.qlm_cfg == 7) ? 2 : 4;
            result.s.speed *= result.s.lanes;
        }
        else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        {
            int qlm = (gmx_block == 1) ? 0 : 2;
            result.s.speed = bdk_qlm_get_gbaud_mhz(qlm) * 8 / 10;
            result.s.lanes = 4;
            result.s.speed *= result.s.lanes;
        }
        else
        {
            int qlm = (gmx_block == 1) ? 1 : 2;
            result.s.speed = bdk_qlm_get_gbaud_mhz(qlm) * 8 / 10;
            result.s.lanes = 4;
            result.s.speed *= result.s.lanes;
        }
        BDK_CSR_INIT(misc_ctl, BDK_PCSX_MISCX_CTL_REG(gmx_index, gmx_block));
        if (misc_ctl.s.gmxeno)
            xaui_link_init(handle);
    }
    else
    {
        /* Disable GMX and PCSX interrupts. */
        BDK_CSR_WRITE (BDK_GMXX_RXX_INT_EN(gmx_index,gmx_block), 0x0);
        BDK_CSR_WRITE (BDK_GMXX_TX_INT_EN(gmx_block), 0x0);
        BDK_CSR_WRITE (BDK_PCSXX_INT_EN_REG(gmx_block), 0x0);
        /* Reset PCS if some lanes are up but not others */
        BDK_CSR_INIT(status, BDK_PCSXX_10GBX_STATUS_REG(gmx_block));
        if (!status.s.alignd && (status.s.l0sync || status.s.l1sync || status.s.l2sync || status.s.l3sync))
            BDK_CSR_MODIFY(c, BDK_PCSXX_CONTROL1_REG(gmx_block),
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

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(gmx_block));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RX_XAUI_CTL(gmx_block));

    /* Do nothing if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls != 0) || (gmxx_rx_xaui_ctl.s.status != 0))
        xaui_link_init(handle);
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);

    /* Set the internal loop */
    BDK_CSR_MODIFY(c, BDK_PCSXX_CONTROL1_REG(gmx_block),
        c.s.loopbck1 = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));

    /* Set the external loop */
    BDK_CSR_MODIFY(c, BDK_GMXX_XAUI_EXT_LOOPBACK(gmx_block),
        c.s.en = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0));
    return 0;
}

const __bdk_if_ops_t __bdk_if_ops_xaui = {
    .name = "XAUI",
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


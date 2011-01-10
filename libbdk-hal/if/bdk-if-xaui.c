#include <bdk.h>

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 1;
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 4;
    else
        return 0;
}

static int if_num_ports(int interface)
{
    BDK_CSR_INIT(mode, BDK_GMXX_INF_MODE(interface));
    if (mode.s.type == 1)
        return 1;
    else
        return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    handle->pknd = handle->index;
    handle->ipd_port = handle->index;
    handle->pko_port = handle->index;

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

    /* Tell PKO the number of ports on this interface */
    BDK_CSR_MODIFY(pko_mode, BDK_PKO_REG_GMX_PORT_MODE,
        if (gmx_block == 0)
                pko_mode.s.mode0 = 4;
        else
                pko_mode.s.mode1 = 4;
        );

    /* Set GMX to buffer as much data as possible before starting transmit.
        This reduces the chances that we have a TX under run due to memory
        contention. Any packet that fits entirely in the GMX FIFO can never
        have an under run regardless of memory load */
    BDK_CSR_MODIFY(gmx_tx_thresh, BDK_GMXX_TXX_THRESH(0, gmx_block),
        gmx_tx_thresh.s.cnt = 0x100);

    /* Configure to allow max sized frames */
    BDK_CSR_WRITE(BDK_GMXX_RXX_JABBER(0, gmx_block), 65535);
    BDK_CSR_MODIFY(pip_frm_len_chkx, BDK_PIP_FRM_LEN_CHKX(handle->ipd_port),
        pip_frm_len_chkx.s.minlen = 64;
        pip_frm_len_chkx.s.maxlen = -1);

    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    bdk_gmxx_prtx_cfg_t          gmx_cfg;
    bdk_pcsxx_misc_ctl_reg_t     xauiMiscCtl;

    /* (1) Interface has already been enabled. */

    /* (2) Disable GMX. */
    BDK_CSR_MODIFY(xauiMiscCtl, BDK_PCSXX_MISC_CTL_REG(gmx_block),
        xauiMiscCtl.s.gmxeno = 1);

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

    /* (4)c Aply reset sequence */
    BDK_CSR_MODIFY(xauiCtl, BDK_PCSXX_CONTROL1_REG(gmx_block),
        xauiCtl.s.lo_pwr = 0;
        xauiCtl.s.reset  = 1);

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
    BDK_CSR_MODIFY(gmx_cfg, BDK_GMXX_PRTX_CFG(gmx_index, gmx_block),
        gmx_cfg.s.en = 0);

    /* Wait for GMX RX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block), rx_idle, ==, 1, 10000))
        return -1;
    /* Wait for GMX TX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block), tx_idle, ==, 1, 10000))
        return -1;

    /* GMX configure */
    gmx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block));
    gmx_cfg.s.speed = 1;
    gmx_cfg.s.speed_msb = 0;
    gmx_cfg.s.slottime = 1;
    BDK_CSR_WRITE(BDK_GMXX_TX_PRTS(gmx_block), 1);
    BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(gmx_index, gmx_block), 512);
    BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(gmx_index, gmx_block), 8192);
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(gmx_index, gmx_block), gmx_cfg.u64);

    /* Wait for receive link */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS1_REG(gmx_block), rcv_lnk, ==, 1, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(gmx_block), xmtflt, ==, 0, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(gmx_block), rcvflt, ==, 0, 10000))
        return -1;

    /* (8) Enable packet reception */
    xauiMiscCtl.s.gmxeno = 0;
    BDK_CSR_WRITE (BDK_PCSXX_MISC_CTL_REG(gmx_block), xauiMiscCtl.u64);

    BDK_CSR_MODIFY(gmx_cfg, BDK_GMXX_PRTX_CFG(gmx_index, gmx_block),
        gmx_cfg.s.en = 1);

    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    BDK_CSR_MODIFY(xauiMiscCtl, BDK_PCSXX_MISC_CTL_REG(gmx_block),
        xauiMiscCtl.s.gmxeno = 0);
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
        result.s.speed = 10000;
        result.s.lanes = 4;
    }
    else
    {
        /* Disable GMX and PCSX interrupts. */
        BDK_CSR_WRITE (BDK_GMXX_RXX_INT_EN(gmx_index,gmx_block), 0x0);
        BDK_CSR_WRITE (BDK_GMXX_TX_INT_EN(gmx_block), 0x0);
        BDK_CSR_WRITE (BDK_PCSXX_INT_EN_REG(gmx_block), 0x0);
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
        if_enable(handle);
}

const __bdk_if_ops_t __bdk_if_ops_xaui = {
    .name = "XAUI",
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_set = if_link_set,
};


#include <bdk.h>

/**
 * @INTERNAL
 * Probe a XAUI interface and determine the number of ports
 * connected to it. The XAUI interface should still be down
 * after this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
int __bdk_helper_xaui_probe(int interface)
{
    int i;
    bdk_gmxx_hg2_control_t gmx_hg2_control;

    /* CN63XX Pass 1.0 errata G-14395 requires the QLM De-emphasis be programmed */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
    {
        BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 0x5;
            ciu_qlm.s.txmargin = 0x1a);
    }

    /* Due to errata GMX-700 on CN56XXp1.x and CN52XXp1.x, the interface
        needs to be enabled before IPD otherwise per port backpressure
        may not work properly */
    BDK_CSR_MODIFY(mode, BDK_GMXX_INF_MODE(interface),
        mode.s.en = 1);

    __bdk_helper_setup_gmx(interface, 1);

    /* Setup PKO to support 16 ports for HiGig2 virtual ports. We're pointing
        all of the PKO packet ports for this interface to the XAUI. This allows
        us to use HiGig2 backpressure per port */
    for (i=0; i<16; i++)
    {
        bdk_pko_mem_port_ptrs_t pko_mem_port_ptrs;
        pko_mem_port_ptrs.u64 = 0;
        /* We set each PKO port to have equal priority in a round robin
            fashion */
        pko_mem_port_ptrs.s.static_p = 0;
        pko_mem_port_ptrs.s.qos_mask = 0xff;
        /* All PKO ports map to the same XAUI hardware port */
        pko_mem_port_ptrs.s.eid = interface*4;
        pko_mem_port_ptrs.s.pid = interface*16 + i;
        BDK_CSR_WRITE(BDK_PKO_MEM_PORT_PTRS, pko_mem_port_ptrs.u64);
    }

    /* If HiGig2 is enabled return 16 ports, otherwise return 1 port */
    gmx_hg2_control.u64 = BDK_CSR_READ(BDK_GMXX_HG2_CONTROL(interface));
    if (gmx_hg2_control.s.hg2tx_en)
        return 16;
    else
        return 1;
}


/**
 * @INTERNAL
 * Bringup and enable a XAUI interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_xaui_enable(int interface)
{
    bdk_gmxx_prtx_cfg_t          gmx_cfg;
    bdk_pcsxx_misc_ctl_reg_t     xauiMiscCtl;
    bdk_helper_link_info_t       link_info;

    /* (1) Interface has already been enabled. */

    /* (2) Disable GMX. */
    BDK_CSR_MODIFY(xauiMiscCtl, BDK_PCSXX_MISC_CTL_REG(interface),
        xauiMiscCtl.s.gmxeno = 1);

    /* (3) Disable GMX and PCSX interrupts. */
    BDK_CSR_WRITE(BDK_GMXX_RXX_INT_EN(0,interface), 0x0);
    BDK_CSR_WRITE(BDK_GMXX_TX_INT_EN(interface), 0x0);
    BDK_CSR_WRITE(BDK_PCSXX_INT_EN_REG(interface), 0x0);

    /* (4) Bring up the PCSX and GMX reconciliation layer. */
    /* (4)a Set polarity and lane swapping. */
    /* (4)b */
    BDK_CSR_MODIFY(gmxXauiTxCtl, BDK_GMXX_TX_XAUI_CTL(interface),
        gmxXauiTxCtl.s.dic_en = 1; /* Enable better IFG packing and improves performance */
        gmxXauiTxCtl.s.uni_en = 0);

    /* (4)c Aply reset sequence */
    BDK_CSR_MODIFY(xauiCtl, BDK_PCSXX_CONTROL1_REG(interface),
        xauiCtl.s.lo_pwr = 0;
        xauiCtl.s.reset  = 1);

    /* Wait for PCS to come out of reset */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_CONTROL1_REG(interface), reset, ==, 0, 10000))
        return -1;
    /* Wait for PCS to be aligned */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_10GBX_STATUS_REG(interface), alignd, ==, 1, 10000))
        return -1;
    /* Wait for RX to be ready */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_RX_XAUI_CTL(interface), status, ==, 0, 10000))
        return -1;

    /* (6) Configure GMX */
    BDK_CSR_MODIFY(gmx_cfg, BDK_GMXX_PRTX_CFG(0, interface),
        gmx_cfg.s.en = 0);

    /* Wait for GMX RX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(0, interface), rx_idle, ==, 1, 10000))
        return -1;
    /* Wait for GMX TX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(0, interface), tx_idle, ==, 1, 10000))
        return -1;

    /* GMX configure */
    gmx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(0, interface));
    gmx_cfg.s.speed = 1;
    gmx_cfg.s.speed_msb = 0;
    gmx_cfg.s.slottime = 1;
    BDK_CSR_WRITE(BDK_GMXX_TX_PRTS(interface), 1);
    BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(0, interface), 512);
    BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(0, interface), 8192);
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(0, interface), gmx_cfg.u64);

    /* Wait for receive link */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS1_REG(interface), rcv_lnk, ==, 1, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(interface), xmtflt, ==, 0, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSXX_STATUS2_REG(interface), rcvflt, ==, 0, 10000))
        return -1;

    /* (8) Enable packet reception */
    xauiMiscCtl.s.gmxeno = 0;
    BDK_CSR_WRITE (BDK_PCSXX_MISC_CTL_REG(interface), xauiMiscCtl.u64);

    BDK_CSR_MODIFY(gmx_cfg, BDK_GMXX_PRTX_CFG(0, interface),
        gmx_cfg.s.en = 1);

    link_info = bdk_helper_link_autoconf(bdk_helper_get_ipd_port(interface, 0));
    if (!link_info.s.link_up)
        return -1;

    return 0;
}

/**
 * @INTERNAL
 * Return the link state of an IPD/PKO port as returned by
 * auto negotiation. The result of this function may not match
 * Octeon's link config if auto negotiation has changed since
 * the last call to bdk_helper_link_set().
 *
 * @param ipd_port IPD/PKO port to query
 *
 * @return Link state
 */
bdk_helper_link_info_t __bdk_helper_xaui_link_get(int ipd_port)
{
    int interface = bdk_helper_get_interface_num(ipd_port);
    bdk_gmxx_tx_xaui_ctl_t gmxx_tx_xaui_ctl;
    bdk_gmxx_rx_xaui_ctl_t gmxx_rx_xaui_ctl;
    bdk_pcsxx_status1_reg_t pcsxx_status1_reg;
    bdk_helper_link_info_t result;

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(interface));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RX_XAUI_CTL(interface));
    pcsxx_status1_reg.u64 = BDK_CSR_READ(BDK_PCSXX_STATUS1_REG(interface));
    result.u64 = 0;

    /* Only return a link if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls == 0) && (gmxx_rx_xaui_ctl.s.status == 0) &&
        (pcsxx_status1_reg.s.rcv_lnk == 1))
    {
        result.s.link_up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 10000;
    }
    else
    {
        /* Disable GMX and PCSX interrupts. */
        BDK_CSR_WRITE (BDK_GMXX_RXX_INT_EN(0,interface), 0x0);
        BDK_CSR_WRITE (BDK_GMXX_TX_INT_EN(interface), 0x0);
        BDK_CSR_WRITE (BDK_PCSXX_INT_EN_REG(interface), 0x0);
    }
    return result;
}


/**
 * @INTERNAL
 * Configure an IPD/PKO port for the specified link state. This
 * function does not influence auto negotiation at the PHY level.
 * The passed link state must always match the link state returned
 * by bdk_helper_link_get(). It is normally best to use
 * bdk_helper_link_autoconf() instead.
 *
 * @param ipd_port  IPD/PKO port to configure
 * @param link_info The new link state
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_xaui_link_set(int ipd_port, bdk_helper_link_info_t link_info)
{
    int interface = bdk_helper_get_interface_num(ipd_port);
    bdk_gmxx_tx_xaui_ctl_t gmxx_tx_xaui_ctl;
    bdk_gmxx_rx_xaui_ctl_t gmxx_rx_xaui_ctl;

    gmxx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(interface));
    gmxx_rx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RX_XAUI_CTL(interface));

    /* If the link shouldn't be up, then just return */
    if (!link_info.s.link_up)
        return 0;

    /* Do nothing if both RX and TX are happy */
    if ((gmxx_tx_xaui_ctl.s.ls == 0) && (gmxx_rx_xaui_ctl.s.status == 0))
        return 0;

    /* Bring the link up */
    return __bdk_helper_xaui_enable(interface);
}


/**
 * @INTERNAL
 * Configure a port for internal and/or external loopback. Internal loopback
 * causes packets sent by the port to be received by Octeon. External loopback
 * causes packets received from the wire to sent out again.
 *
 * @param ipd_port IPD/PKO port to loopback.
 * @param enable_internal
 *                 Non zero if you want internal loopback
 * @param enable_external
 *                 Non zero if you want external loopback
 *
 * @return Zero on success, negative on failure.
 */
extern int __bdk_helper_xaui_configure_loopback(int ipd_port, int enable_internal, int enable_external)
{
    int interface = bdk_helper_get_interface_num(ipd_port);

    /* Set the internal loop */
    BDK_CSR_MODIFY(pcsxx_control1_reg, BDK_PCSXX_CONTROL1_REG(interface),
        pcsxx_control1_reg.s.loopbck1 = enable_internal);

    /* Set the external loop */
    BDK_CSR_MODIFY(gmxx_xaui_ext_loopback, BDK_GMXX_XAUI_EXT_LOOPBACK(interface),
        gmxx_xaui_ext_loopback.s.en = enable_external);

    /* Take the link through a reset */
    return __bdk_helper_xaui_enable(interface);
}


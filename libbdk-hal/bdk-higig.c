#include <bdk.h>

/**
 * Initialize the HiGig aspects of a XAUI interface. This function
 * should be called before the cvmx-helper generic init.
 *
 * @param interface Interface to initialize HiGig on (0-1)
 * @param enable_higig2
 *                  Non zero to enable HiGig2 support. Zero to support HiGig
 *                  and HiGig+.
 *
 * @return Zero on success, negative on failure
 */
int bdk_higig_initialize(int interface, int enable_higig2)
{
    bdk_pip_prt_cfgx_t pip_prt_cfg;
    bdk_gmxx_rxx_udd_skp_t gmx_rx_udd_skp;
    bdk_gmxx_txx_min_pkt_t gmx_tx_min_pkt;
    bdk_gmxx_txx_append_t gmx_tx_append;
    bdk_gmxx_tx_ifg_t gmx_tx_ifg;
    bdk_gmxx_tx_ovr_bp_t gmx_tx_ovr_bp;
    bdk_gmxx_rxx_frm_ctl_t gmx_rx_frm_ctl;
    bdk_gmxx_tx_xaui_ctl_t gmx_tx_xaui_ctl;
    int i;
    int header_size = (enable_higig2) ? 16 : 12;

    /* Setup PIP to handle HiGig */
    pip_prt_cfg.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(interface*16));
    pip_prt_cfg.s.dsa_en = 0;
    pip_prt_cfg.s.higig_en = 1;
    pip_prt_cfg.s.hg_qos = 1;
    pip_prt_cfg.s.skip = header_size;
    BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(interface*16), pip_prt_cfg.u64);

    /* Setup some sample QoS defaults. These can be changed later */
    for (i=0; i<64; i++)
    {
        bdk_pip_hg_pri_qos_t pip_hg_pri_qos;
        pip_hg_pri_qos.u64 = 0;
        pip_hg_pri_qos.s.up_qos = 1;
        pip_hg_pri_qos.s.pri = i;
        pip_hg_pri_qos.s.qos = i&7;
        BDK_CSR_WRITE(BDK_PIP_HG_PRI_QOS, pip_hg_pri_qos.u64);
    }

    /* Setup GMX RX to treat the HiGig header as user data to ignore */
    gmx_rx_udd_skp.u64 = BDK_CSR_READ(BDK_GMXX_RXX_UDD_SKP(0, interface));
    gmx_rx_udd_skp.s.len = header_size;
    gmx_rx_udd_skp.s.fcssel = 0;
    BDK_CSR_WRITE(BDK_GMXX_RXX_UDD_SKP(0, interface), gmx_rx_udd_skp.u64);

    /* Disable GMX preamble checking */
    gmx_rx_frm_ctl.u64 = BDK_CSR_READ(BDK_GMXX_RXX_FRM_CTL(0, interface));
    gmx_rx_frm_ctl.s.pre_chk = 0;
    BDK_CSR_WRITE(BDK_GMXX_RXX_FRM_CTL(0, interface), gmx_rx_frm_ctl.u64);

    /* Setup GMX TX to pad properly min sized packets */
    gmx_tx_min_pkt.u64 = BDK_CSR_READ(BDK_GMXX_TXX_MIN_PKT(0, interface));
    gmx_tx_min_pkt.s.min_size = 59 + header_size;
    BDK_CSR_WRITE(BDK_GMXX_TXX_MIN_PKT(0, interface), gmx_tx_min_pkt.u64);

    /* Setup GMX TX to not add a preamble */
    gmx_tx_append.u64 = BDK_CSR_READ(BDK_GMXX_TXX_APPEND(0, interface));
    gmx_tx_append.s.preamble = 0;
    BDK_CSR_WRITE(BDK_GMXX_TXX_APPEND(0, interface), gmx_tx_append.u64);

    /* Reduce the inter frame gap to 8 bytes */
    gmx_tx_ifg.u64 = BDK_CSR_READ(BDK_GMXX_TX_IFG(interface));
    gmx_tx_ifg.s.ifg1 = 4;
    gmx_tx_ifg.s.ifg2 = 4;
    BDK_CSR_WRITE(BDK_GMXX_TX_IFG(interface), gmx_tx_ifg.u64);

    /* Disable GMX backpressure */
    gmx_tx_ovr_bp.u64 = BDK_CSR_READ(BDK_GMXX_TX_OVR_BP(interface));
    gmx_tx_ovr_bp.s.bp = 0;
    gmx_tx_ovr_bp.s.en = 0xf;
    gmx_tx_ovr_bp.s.ign_full = 0xf;
    BDK_CSR_WRITE(BDK_GMXX_TX_OVR_BP(interface), gmx_tx_ovr_bp.u64);

    if (enable_higig2)
    {
        /* Enable HiGig2 support and forwarding of virtual port backpressure
            to PKO */
        bdk_gmxx_hg2_control_t gmx_hg2_control;
        gmx_hg2_control.u64 = BDK_CSR_READ(BDK_GMXX_HG2_CONTROL(interface));
        gmx_hg2_control.s.hg2rx_en = 1;
        gmx_hg2_control.s.hg2tx_en = 1;
        gmx_hg2_control.s.logl_en = 0xffff;
        gmx_hg2_control.s.phys_en = 1;
        BDK_CSR_WRITE(BDK_GMXX_HG2_CONTROL(interface), gmx_hg2_control.u64);
    }

    /* Enable HiGig */
    gmx_tx_xaui_ctl.u64 = BDK_CSR_READ(BDK_GMXX_TX_XAUI_CTL(interface));
    gmx_tx_xaui_ctl.s.hg_en = 1;
    BDK_CSR_WRITE(BDK_GMXX_TX_XAUI_CTL(interface), gmx_tx_xaui_ctl.u64);

    return 0;
}


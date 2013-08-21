#include <bdk.h>

extern const __bdk_if_ops_t __bdk_if_ops_xaui;

static int if_num_interfaces(bdk_node_t node)
{
    return __bdk_if_ops_xaui.if_num_interfaces(node);
}

static int if_num_ports(bdk_node_t node, int interface)
{
    /* The XAUI probe has been modified to tell us if a XAUI
        port exists when we pass a negative interface number,
        regardless if the port is in Higig mode */
    int ports = __bdk_if_ops_xaui.if_num_ports(node, -interface-1);
    if (ports == 0)
        return ports;

    switch (bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface))
    {
        case 1:
            return 1;
        case 2:
            return 1; // FIXME: Support 16 pipes for Higig2
        default:
            return 0;
    }
}

static int if_probe(bdk_if_handle_t handle)
{
    int result = __bdk_if_ops_xaui.if_probe(handle);

    /* Change name to be "HIGIG%d.%d" */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "HIGIG%d.%d", handle->interface, handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.HIGIG%d.%d", handle->node, handle->interface, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;
    return result;
}

static int if_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);

    /* Figure out what the Higig header size is */
    int header_size = (bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + gmx_block) == 2) ? 16 : 12;

    /* Setup PIP to handle HiGig */
    BDK_CSR_MODIFY(pip_prt_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
        pip_prt_cfg.s.dsa_en = 0;
        pip_prt_cfg.s.higig_en = 1;
        pip_prt_cfg.s.hg_qos = 1;
        pip_prt_cfg.s.skip = header_size);

    {
        /* Setup some sample QoS defaults. These can be changed later */
        for (int i=0; i<64; i++)
        {
            BDK_CSR_DEFINE(pip_hg_pri_qos, BDK_PIP_HG_PRI_QOS);
            pip_hg_pri_qos.u64 = 0;
            pip_hg_pri_qos.s.up_qos = 1;
            pip_hg_pri_qos.s.pri = i;
            pip_hg_pri_qos.s.qos = i&7;
            BDK_CSR_WRITE(handle->node, BDK_PIP_HG_PRI_QOS, pip_hg_pri_qos.u64);
        }
    }

    /* Setup GMX RX to treat the HiGig header as user data to ignore */
    BDK_CSR_MODIFY(gmx_rx_udd_skp, handle->node, BDK_GMXX_RXX_UDD_SKP(gmx_block, 0),
        gmx_rx_udd_skp.s.len = header_size;
        gmx_rx_udd_skp.s.fcssel = 0);

    /* Disable GMX preamble checking */
    BDK_CSR_MODIFY(gmx_rx_frm_ctl, handle->node, BDK_GMXX_RXX_FRM_CTL(gmx_block, 0),
        gmx_rx_frm_ctl.s.pre_chk = 0);

    /* Setup GMX TX to pad properly min sized packets */
    BDK_CSR_MODIFY(gmx_tx_min_pkt, handle->node, BDK_GMXX_TXX_MIN_PKT(gmx_block, 0),
        gmx_tx_min_pkt.s.min_size = 59 + header_size);

    /* Setup GMX TX to not add a preamble */
    BDK_CSR_MODIFY(gmx_tx_append, handle->node, BDK_GMXX_TXX_APPEND(gmx_block, 0),
        gmx_tx_append.s.preamble = 0);

    /* Reduce the inter frame gap to 8 bytes */
    BDK_CSR_MODIFY(gmx_tx_ifg, handle->node, BDK_GMXX_TX_IFG(gmx_block),
        gmx_tx_ifg.s.ifg1 = 4;
        gmx_tx_ifg.s.ifg2 = 4);

    /* Disable GMX backpressure */
    BDK_CSR_MODIFY(gmx_tx_ovr_bp, handle->node, BDK_GMXX_TX_OVR_BP(gmx_block),
        gmx_tx_ovr_bp.s.bp = 0;
        gmx_tx_ovr_bp.s.en = 0xf;
        gmx_tx_ovr_bp.s.ign_full = 0xf);

    /* Most of the Higig setup is done during Higig if_init(). This function
        sets enough CSRs to cause the code to detect Higig mode */
    if (header_size == 16)
    {
        /* Enable HiGig2 support and forwarding of virtual port backpressure
            to PKO */
        BDK_CSR_MODIFY(gmx_hg2_control, handle->node, BDK_GMXX_HG2_CONTROL(gmx_block),
            gmx_hg2_control.s.hg2rx_en = 1;
            gmx_hg2_control.s.hg2tx_en = 1;
            gmx_hg2_control.s.logl_en = 0xffff;
            gmx_hg2_control.s.phys_en = 1);
    }

    /* Enable HiGig */
    BDK_CSR_MODIFY(gmx_tx_xaui_ctl, handle->node, BDK_GMXX_TX_XAUI_CTL(gmx_block),
        gmx_tx_xaui_ctl.s.hg_en = 1);

    return __bdk_if_ops_xaui.if_init(handle);
}

static int if_enable(bdk_if_handle_t handle)
{
    return __bdk_if_ops_xaui.if_enable(handle);
}

static int if_disable(bdk_if_handle_t handle)
{
    return __bdk_if_ops_xaui.if_disable(handle);
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    return __bdk_if_ops_xaui.if_link_get(handle);
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    return __bdk_if_ops_xaui.if_link_set(handle, link_info);
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    return __bdk_if_ops_xaui.if_loopback(handle, loopback);
}

const __bdk_if_ops_t __bdk_if_ops_higig = {
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


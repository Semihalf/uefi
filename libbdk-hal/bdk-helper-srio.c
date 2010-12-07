#include <bdk.h>

/**
 * @INTERNAL
 * Probe a SRIO interface and determine the number of ports
 * connected to it. The SRIO interface should still be down
 * after this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
int __bdk_helper_srio_probe(int interface)
{
    bdk_sriox_status_reg_t srio0_status_reg;
    bdk_sriox_status_reg_t srio1_status_reg;

    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 0;

    srio0_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(0));
    srio1_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(1));
    if (srio0_status_reg.s.srio || srio1_status_reg.s.srio)
        return 2;
    else
        return 0;
}


/**
 * @INTERNAL
 * Bringup and enable SRIO interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_srio_enable(int interface)
{
    int num_ports = bdk_helper_ports_on_interface(interface);
    int index;
    bdk_sriomaintx_core_enables_t sriomaintx_core_enables;

    /* All SRIO ports have a bdk_srio_rx_message_header_t header
        on them that must be skipped by IPD */
    for (index=0; index<num_ports; index++)
    {
        bdk_pip_prt_cfgx_t port_config;
        bdk_sriox_omsg_sp_mrx_t sriox_omsg_sp_mrx;
        bdk_sriox_omsg_fmp_mrx_t sriox_omsg_fmp_mrx;
        bdk_sriox_omsg_nmp_mrx_t sriox_omsg_nmp_mrx;
        int ipd_port = bdk_helper_get_ipd_port(interface, index);
        port_config.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(ipd_port));
        /* Only change the skip if the user hasn't already set it */
        if (!port_config.s.skip)
        {
            port_config.s.skip = sizeof(bdk_srio_rx_message_header_t);
            BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(ipd_port), port_config.u64);
        }

        /* Enable TX with PKO */
        BDK_CSR_MODIFY(sriox_omsg_portx, BDK_SRIOX_OMSG_PORTX(index, interface - 4),
            sriox_omsg_portx.s.port = (interface - 4) * 2 + index;
            sriox_omsg_portx.s.enable = 1);

        /* Allow OMSG controller to send regardless of the state of any other
            controller. Allow messages to different IDs and MBOXes to go in
            parallel */
        sriox_omsg_sp_mrx.u64 = 0;
        sriox_omsg_sp_mrx.s.xmbox_sp = 1;
        sriox_omsg_sp_mrx.s.ctlr_sp = 1;
        sriox_omsg_sp_mrx.s.ctlr_fmp = 1;
        sriox_omsg_sp_mrx.s.ctlr_nmp = 1;
        sriox_omsg_sp_mrx.s.id_sp = 1;
        sriox_omsg_sp_mrx.s.id_fmp = 1;
        sriox_omsg_sp_mrx.s.id_nmp = 1;
        sriox_omsg_sp_mrx.s.mbox_sp = 1;
        sriox_omsg_sp_mrx.s.mbox_fmp = 1;
        sriox_omsg_sp_mrx.s.mbox_nmp = 1;
        sriox_omsg_sp_mrx.s.all_psd = 1;
        BDK_CSR_WRITE(BDK_SRIOX_OMSG_SP_MRX(index, interface-4), sriox_omsg_sp_mrx.u64);

        /* Allow OMSG controller to send regardless of the state of any other
            controller. Allow messages to different IDs and MBOXes to go in
            parallel */
        sriox_omsg_fmp_mrx.u64 = 0;
        sriox_omsg_fmp_mrx.s.ctlr_sp = 1;
        sriox_omsg_fmp_mrx.s.ctlr_fmp = 1;
        sriox_omsg_fmp_mrx.s.ctlr_nmp = 1;
        sriox_omsg_fmp_mrx.s.id_sp = 1;
        sriox_omsg_fmp_mrx.s.id_fmp = 1;
        sriox_omsg_fmp_mrx.s.id_nmp = 1;
        sriox_omsg_fmp_mrx.s.mbox_sp = 1;
        sriox_omsg_fmp_mrx.s.mbox_fmp = 1;
        sriox_omsg_fmp_mrx.s.mbox_nmp = 1;
        sriox_omsg_fmp_mrx.s.all_psd = 1;
        BDK_CSR_WRITE(BDK_SRIOX_OMSG_FMP_MRX(index, interface-4), sriox_omsg_fmp_mrx.u64);

        /* Once the first part of a message is accepted, always acept the rest
            of the message */
        sriox_omsg_nmp_mrx.u64 = 0;
        sriox_omsg_nmp_mrx.s.all_sp = 1;
        sriox_omsg_nmp_mrx.s.all_fmp = 1;
        sriox_omsg_nmp_mrx.s.all_nmp = 1;
        BDK_CSR_WRITE(BDK_SRIOX_OMSG_NMP_MRX(index, interface-4), sriox_omsg_nmp_mrx.u64);

    }

    /* Choose the receive controller based on the mailbox */
    BDK_CSR_MODIFY(sriox_imsg_ctrl, BDK_SRIOX_IMSG_CTRL(interface - 4),
        sriox_imsg_ctrl.s.prt_sel = 0;
        sriox_imsg_ctrl.s.mbox = 0xa);

    /* DPI must be enabled for us to RX messages */
    BDK_CSR_MODIFY(dpi_ctl, BDK_DPI_CTL,
        dpi_ctl.s.clk = 1;
        dpi_ctl.s.en = 1);

    /* Enable RX */
    if (!bdk_srio_config_read32(interface - 4, 0, -1, 0, 0,
        BDK_SRIOMAINTX_CORE_ENABLES(interface-4), &sriomaintx_core_enables.u32))
    {
        sriomaintx_core_enables.s.imsg0 = 1;
        sriomaintx_core_enables.s.imsg1 = 1;
        bdk_srio_config_write32(interface - 4, 0, -1, 0, 0,
            BDK_SRIOMAINTX_CORE_ENABLES(interface-4), sriomaintx_core_enables.u32);
    }

    return 0;
}

/**
 * @INTERNAL
 * Return the link state of an IPD/PKO port as returned by SRIO link status.
 *
 * @param ipd_port IPD/PKO port to query
 *
 * @return Link state
 */
bdk_helper_link_info_t __bdk_helper_srio_link_get(int ipd_port)
{
    int interface = bdk_helper_get_interface_num(ipd_port);
    int srio_port = interface - 4;
    bdk_helper_link_info_t result;
    bdk_sriox_status_reg_t srio_status_reg;
    bdk_sriomaintx_port_0_err_stat_t sriomaintx_port_0_err_stat;
    bdk_sriomaintx_port_0_ctl_t sriomaintx_port_0_ctl;
    bdk_sriomaintx_port_0_ctl2_t sriomaintx_port_0_ctl2;

    result.u64 = 0;

    /* Make sure register access is allowed */
    srio_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(srio_port));
    if (!srio_status_reg.s.access)
        return result;

    /* Read the port link status */
    if (bdk_srio_config_read32(srio_port, 0, -1, 0, 0,
        BDK_SRIOMAINTX_PORT_0_ERR_STAT(srio_port),
        &sriomaintx_port_0_err_stat.u32))
        return result;

    /* Return if link is down */
    if (!sriomaintx_port_0_err_stat.s.pt_ok)
        return result;

    /* Read the port link width and speed */
    if (bdk_srio_config_read32(srio_port, 0, -1, 0, 0,
        BDK_SRIOMAINTX_PORT_0_CTL(srio_port),
        &sriomaintx_port_0_ctl.u32))
        return result;
    if (bdk_srio_config_read32(srio_port, 0, -1, 0, 0,
        BDK_SRIOMAINTX_PORT_0_CTL2(srio_port),
        &sriomaintx_port_0_ctl2.u32))
        return result;

    /* Link is up */
    result.s.full_duplex = 1;
    result.s.link_up = 1;
    switch (sriomaintx_port_0_ctl2.s.sel_baud)
    {
        case 1:
            result.s.speed = 1250;
            break;
        case 2:
            result.s.speed = 2500;
            break;
        case 3:
            result.s.speed = 3125;
            break;
        case 4:
            result.s.speed = 5000;
            break;
        case 5:
            result.s.speed = 6250;
            break;
        default:
            result.s.speed = 0;
            break;
    }
    switch (sriomaintx_port_0_ctl.s.it_width)
    {
        case 2: /* Four lanes */
            result.s.speed += 40000;
            break;
        case 3: /* Two lanes */
            result.s.speed += 20000;
            break;
        default: /* One lane */
            result.s.speed += 10000;
            break;
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
int __bdk_helper_srio_link_set(int ipd_port, bdk_helper_link_info_t link_info)
{
    return 0;
}


#include <bdk.h>

/**
 * @INTERNAL
 * Perform initialization required only once for an SGMII port.
 *
 * @param interface Interface to init
 * @param index     Index of prot on the interface
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_sgmii_hardware_init_one_time(int interface, int index)
{
    const uint64_t clock_mhz = bdk_clock_get_rate(BDK_CLOCK_SCLK) / 1000000;
    bdk_pcsx_miscx_ctl_reg_t pcsx_miscx_ctl_reg;
    bdk_pcsx_linkx_timer_count_reg_t pcsx_linkx_timer_count_reg;

    /* Disable GMX */
    BDK_CSR_MODIFY(gmxx_prtx_cfg, BDK_GMXX_PRTX_CFG(index, interface),
        gmxx_prtx_cfg.s.en = 0);

    /* Write PCS*_LINK*_TIMER_COUNT_REG[COUNT] with the appropriate
        value. 1000BASE-X specifies a 10ms interval. SGMII specifies a 1.6ms
        interval. */
    pcsx_miscx_ctl_reg.u64 = BDK_CSR_READ(BDK_PCSX_MISCX_CTL_REG(index, interface));
    pcsx_linkx_timer_count_reg.u64 = BDK_CSR_READ(BDK_PCSX_LINKX_TIMER_COUNT_REG(index, interface));
    if (pcsx_miscx_ctl_reg.s.mode)
    {
        /* 1000BASE-X */
        pcsx_linkx_timer_count_reg.s.count = (10000ull * clock_mhz) >> 10;
    }
    else
    {
        /* SGMII */
        pcsx_linkx_timer_count_reg.s.count = (1600ull * clock_mhz) >> 10;
    }
    BDK_CSR_WRITE(BDK_PCSX_LINKX_TIMER_COUNT_REG(index, interface), pcsx_linkx_timer_count_reg.u64);

    /* Write the advertisement register to be used as the
        tx_Config_Reg<D15:D0> of the autonegotiation.
        In 1000BASE-X mode, tx_Config_Reg<D15:D0> is PCS*_AN*_ADV_REG.
        In SGMII PHY mode, tx_Config_Reg<D15:D0> is PCS*_SGM*_AN_ADV_REG.
        In SGMII MAC mode, tx_Config_Reg<D15:D0> is the fixed value 0x4001, so
        this step can be skipped. */
    if (pcsx_miscx_ctl_reg.s.mode)
    {
        /* 1000BASE-X */
        BDK_CSR_MODIFY(pcsx_anx_adv_reg, BDK_PCSX_ANX_ADV_REG(index, interface),
            pcsx_anx_adv_reg.s.rem_flt = 0;
            pcsx_anx_adv_reg.s.pause = 3;
            pcsx_anx_adv_reg.s.hfd = 1;
            pcsx_anx_adv_reg.s.fd = 1);
    }
    else
    {
        if (pcsx_miscx_ctl_reg.s.mac_phy)
        {
            /* PHY Mode */
            BDK_CSR_MODIFY(pcsx_sgmx_an_adv_reg, BDK_PCSX_SGMX_AN_ADV_REG(index, interface),
                pcsx_sgmx_an_adv_reg.s.link = 1;
                pcsx_sgmx_an_adv_reg.s.dup = 1;
                pcsx_sgmx_an_adv_reg.s.speed= 2);
        }
        else
        {
            /* MAC Mode - Nothing to do */
        }
    }
    return 0;
}


/**
 * @INTERNAL
 * Initialize the SERTES link for the first time or after a loss
 * of link.
 *
 * @param interface Interface to init
 * @param index     Index of prot on the interface
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_sgmii_hardware_init_link(int interface, int index)
{
    bdk_pcsx_mrx_control_reg_t control_reg;

    /* Take PCS through a reset sequence.
        PCS*_MR*_CONTROL_REG[PWR_DN] should be cleared to zero.
        Write PCS*_MR*_CONTROL_REG[RESET]=1 (while not changing the value of
            the other PCS*_MR*_CONTROL_REG bits).
        Read PCS*_MR*_CONTROL_REG[RESET] until it changes value to zero. */
    control_reg.u64 = BDK_CSR_READ(BDK_PCSX_MRX_CONTROL_REG(index, interface));
    {
        control_reg.s.reset = 1;
        BDK_CSR_WRITE(BDK_PCSX_MRX_CONTROL_REG(index, interface), control_reg.u64);
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSX_MRX_CONTROL_REG(index, interface), reset, ==, 0, 10000))
        {
            bdk_dprintf("SGMII%d: Timeout waiting for port %d to finish reset\n", interface, index);
            return -1;
        }
    }

    /* Write PCS*_MR*_CONTROL_REG[RST_AN]=1 to ensure a fresh sgmii negotiation starts. */
    control_reg.s.rst_an = 1;
    control_reg.s.an_en = 1;
    control_reg.s.pwr_dn = 0;
    BDK_CSR_WRITE(BDK_PCSX_MRX_CONTROL_REG(index, interface), control_reg.u64);

    /* Wait for PCS*_MR*_STATUS_REG[AN_CPT] to be set, indicating that
        sgmii autonegotiation is complete. In MAC mode this isn't an ethernet
        link, but a link between Octeon and the PHY */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_PCSX_MRX_STATUS_REG(index, interface), an_cpt, ==, 1, 10000))
    {
        //bdk_dprintf("SGMII%d: Port %d link timeout\n", interface, index);
        return -1;
    }
    return 0;
}


/**
 * @INTERNAL
 * Configure an SGMII link to the specified speed after the SERTES
 * link is up.
 *
 * @param interface Interface to init
 * @param index     Index of prot on the interface
 * @param link_info Link state to configure
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_sgmii_hardware_init_link_speed(int interface, int index, bdk_helper_link_info_t link_info)
{
    int is_enabled;
    bdk_gmxx_prtx_cfg_t gmxx_prtx_cfg;
    bdk_pcsx_miscx_ctl_reg_t pcsx_miscx_ctl_reg;

    /* Disable GMX before we make any changes. Remember the enable state */
    gmxx_prtx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(index, interface));
    is_enabled = gmxx_prtx_cfg.s.en;
    gmxx_prtx_cfg.s.en = 0;
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmxx_prtx_cfg.u64);

    /* Wait for GMX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(index, interface), rx_idle, ==, 1, 10000) ||
        BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(index, interface), tx_idle, ==, 1, 10000))
    {
        bdk_dprintf("SGMII%d: Timeout waiting for port %d to be idle\n", interface, index);
        return -1;
    }

    /* Read GMX CFG again to make sure the disable completed */
    gmxx_prtx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(index, interface));

    /* Get the misc control for PCS. We will need to set the duplication amount */
    pcsx_miscx_ctl_reg.u64 = BDK_CSR_READ(BDK_PCSX_MISCX_CTL_REG(index, interface));

    /* Use GMXENO to force the link down if the status we get says it should be down */
    pcsx_miscx_ctl_reg.s.gmxeno = !link_info.s.link_up;

    /* Only change the duplex setting if the link is up */
    if (link_info.s.link_up)
        gmxx_prtx_cfg.s.duplex = link_info.s.full_duplex;

    /* Do speed based setting for GMX */
    switch (link_info.s.speed)
    {
        case 10:
            gmxx_prtx_cfg.s.speed = 0;
            gmxx_prtx_cfg.s.speed_msb = 1;
            gmxx_prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 25; /* Setting from GMX-603 */
            BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(index, interface), 64);
            BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(index, interface), 0);
            break;
        case 100:
            gmxx_prtx_cfg.s.speed = 0;
            gmxx_prtx_cfg.s.speed_msb = 0;
            gmxx_prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 0x5;
            BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(index, interface), 64);
            BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(index, interface), 0);
            break;
        case 1000:
            gmxx_prtx_cfg.s.speed = 1;
            gmxx_prtx_cfg.s.speed_msb = 0;
            gmxx_prtx_cfg.s.slottime = 1;
            pcsx_miscx_ctl_reg.s.samp_pt = 1;
            BDK_CSR_WRITE(BDK_GMXX_TXX_SLOT(index, interface), 512);
	    if (gmxx_prtx_cfg.s.duplex)
                BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(index, interface), 0); // full duplex
	    else
                BDK_CSR_WRITE(BDK_GMXX_TXX_BURST(index, interface), 8192); // half duplex
            break;
        default:
            break;
    }

    /* Write the new misc control for PCS */
    BDK_CSR_WRITE(BDK_PCSX_MISCX_CTL_REG(index, interface), pcsx_miscx_ctl_reg.u64);

    /* Write the new GMX settings with the port still disabled */
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmxx_prtx_cfg.u64);

    /* Read GMX CFG again to make sure the config completed */
    gmxx_prtx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(index, interface));

    /* Restore the enabled / disabled state */
    gmxx_prtx_cfg.s.en = is_enabled;
    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmxx_prtx_cfg.u64);

    return 0;
}


/**
 * @INTERNAL
 * Bring up the SGMII interface to be ready for packet I/O but
 * leave I/O disabled using the GMX override. This function
 * follows the bringup documented in 10.6.3 of the manual.
 *
 * @param interface Interface to bringup
 * @param num_ports Number of ports on the interface
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_sgmii_hardware_init(int interface, int num_ports)
{
    int index;

    /* CN63XX Pass 1.0 errata G-14395 requires the QLM De-emphasis be programmed */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
    {
        BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 0xf;
            ciu_qlm.s.txmargin = 0xd);
    }

    __bdk_helper_setup_gmx(interface, num_ports);

    for (index=0; index<num_ports; index++)
    {
        int ipd_port = bdk_helper_get_ipd_port(interface, index);
        __bdk_helper_sgmii_hardware_init_one_time(interface, index);
        __bdk_helper_sgmii_link_set(ipd_port, __bdk_helper_sgmii_link_get(ipd_port));

    }

    return 0;
}


/**
 * @INTERNAL
 * Probe a SGMII interface and determine the number of ports
 * connected to it. The SGMII interface should still be down after
 * this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
int __bdk_helper_sgmii_probe(int interface)
{
    /* Due to errata GMX-700 on CN56XXp1.x and CN52XXp1.x, the interface
        needs to be enabled before IPD otherwise per port backpressure
        may not work properly */
    BDK_CSR_MODIFY(mode, BDK_GMXX_INF_MODE(interface),
        mode.s.en = 1);
    return 4;
}


/**
 * @INTERNAL
 * Bringup and enable a SGMII interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_sgmii_enable(int interface)
{
    int num_ports = bdk_helper_ports_on_interface(interface);
    int index;

    __bdk_helper_sgmii_hardware_init(interface, num_ports);

    for (index=0; index<num_ports; index++)
    {
        BDK_CSR_MODIFY(gmxx_prtx_cfg, BDK_GMXX_PRTX_CFG(index, interface),
            gmxx_prtx_cfg.s.en = 1);
    }
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
bdk_helper_link_info_t __bdk_helper_sgmii_link_get(int ipd_port)
{
    bdk_helper_link_info_t result;
    bdk_pcsx_miscx_ctl_reg_t pcsx_miscx_ctl_reg;
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);
    bdk_pcsx_mrx_control_reg_t pcsx_mrx_control_reg;

    result.u64 = 0;

    pcsx_mrx_control_reg.u64 = BDK_CSR_READ(BDK_PCSX_MRX_CONTROL_REG(index, interface));
    if (pcsx_mrx_control_reg.s.loopbck1)
    {
        /* Force 1Gbps full duplex link for internal loopback */
        result.s.link_up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 1000;
        return result;
    }


    pcsx_miscx_ctl_reg.u64 = BDK_CSR_READ(BDK_PCSX_MISCX_CTL_REG(index, interface));
    if (pcsx_miscx_ctl_reg.s.mode)
    {
        /* 1000BASE-X */
        // FIXME
    }
    else
    {
        if (pcsx_miscx_ctl_reg.s.mac_phy)
        {
            /* PHY Mode */
            bdk_pcsx_mrx_status_reg_t pcsx_mrx_status_reg;
            bdk_pcsx_anx_results_reg_t pcsx_anx_results_reg;

            /* Don't bother continuing if the SERTES low level link is down */
            pcsx_mrx_status_reg.u64 = BDK_CSR_READ(BDK_PCSX_MRX_STATUS_REG(index, interface));
            if (pcsx_mrx_status_reg.s.lnk_st == 0)
            {
                if (__bdk_helper_sgmii_hardware_init_link(interface, index) != 0)
                    return result;
            }

            /* Read the autoneg results */
            pcsx_anx_results_reg.u64 = BDK_CSR_READ(BDK_PCSX_ANX_RESULTS_REG(index, interface));
            if (pcsx_anx_results_reg.s.an_cpt)
            {
                /* Auto negotiation is complete. Set status accordingly */
                result.s.full_duplex = pcsx_anx_results_reg.s.dup;
                result.s.link_up = pcsx_anx_results_reg.s.link_ok;
                switch (pcsx_anx_results_reg.s.spd)
                {
                    case 0:
                        result.s.speed = 10;
                        break;
                    case 1:
                        result.s.speed = 100;
                        break;
                    case 2:
                        result.s.speed = 1000;
                        break;
                    default:
                        result.s.speed = 0;
                        result.s.link_up = 0;
                        break;
                }
            }
            else
            {
                /* Auto negotiation isn't complete. Return link down */
                result.s.speed = 0;
                result.s.link_up = 0;
            }
        }
        else /* MAC Mode */
        {
            if (interface)
                result = bdk_helper_board_link_get_phy(bdk_config_get(BDK_CONFIG_PHY_IF1_PORT0 + index));
            else
                result = bdk_helper_board_link_get_phy(bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + index));
        }
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
int __bdk_helper_sgmii_link_set(int ipd_port, bdk_helper_link_info_t link_info)
{
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);
    __bdk_helper_sgmii_hardware_init_link(interface, index);
    return __bdk_helper_sgmii_hardware_init_link_speed(interface, index, link_info);
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
int __bdk_helper_sgmii_configure_loopback(int ipd_port, int enable_internal, int enable_external)
{
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);

    BDK_CSR_MODIFY(pcsx_mrx_control_reg, BDK_PCSX_MRX_CONTROL_REG(index, interface),
        pcsx_mrx_control_reg.s.loopbck1 = enable_internal);

    BDK_CSR_MODIFY(pcsx_miscx_ctl_reg, BDK_PCSX_MISCX_CTL_REG(index, interface),
        pcsx_miscx_ctl_reg.s.loopbck2 = enable_external);

    __bdk_helper_sgmii_hardware_init_link(interface, index);
    return 0;
}


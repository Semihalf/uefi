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
        return 2; /* DLM0 has both GMX connected to it */
    else
        return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(interface));
        switch (inf_mode.s.mode)
        {
            case 1: /* Normal SGMII */
                return 1;
            case 2: /* Quad SGMII */
                return 4;
            default: /* Not SGMII */
                return 0;
        }
    }
    else if (bdk_qlm_get(node, BDK_IF_SGMII, interface) < 0)
        return 0;
    else
        return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be "SGMII%d.%d" */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "SGMII%d.%d", handle->interface, handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.SGMII%d.%d", handle->node, handle->interface, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0x800 - 0x830, 0x900 - 0x930, ... */
        handle->ipd_port = 0x800 + handle->interface*0x100 + handle->index*0x10;
    }
    else
    {
        /* Use IPD ports 0 - 3 */
        handle->ipd_port = handle->interface*16 + handle->index;
    }
    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
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
static int init_link(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    int forced_speed_mbps = 0;  /* Default to no forced speed, use autonegotiation */


    /* Check for special PHY address values that indicate a forced speed, and no MDIO
       connection to the PHY.  In these cases we will also force the SGMII speed, and not
       do SGMII autonegotiation. Only 1000/100 Mbits/second are supported.*/
    if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + gmx_block*4 + gmx_index) == 0x1000))
        forced_speed_mbps = 1000;
    else if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + gmx_block*4 + gmx_index) == 0x1001))
        forced_speed_mbps = 100;

    /* Disable error reporting */
    BDK_CSR_WRITE(handle->node, BDK_GMXX_RXX_INT_EN(gmx_block, gmx_index), 0);
    BDK_CSR_WRITE(handle->node, BDK_PCSX_INTX_EN_REG(gmx_block, gmx_index), 0);

    /* Take PCS through a reset sequence.
        PCS*_MR*_CONTROL_REG[PWR_DN] should be cleared to zero.
        Write PCS*_MR*_CONTROL_REG[RESET]=1 (while not changing the value of
            the other PCS*_MR*_CONTROL_REG bits).
        Read PCS*_MR*_CONTROL_REG[RESET] until it changes value to zero. */
    if (!bdk_is_simulation())
    {
        BDK_CSR_MODIFY(control_reg, handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index),
            control_reg.s.reset = 1);
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index), reset, ==, 0, 10000))
        {
            bdk_dprintf("SGMII%d%d: Timeout waiting for reset finish\n", handle->interface, handle->index);
            return -1;
        }
    }

    if (!forced_speed_mbps)
    {
        /* Write PCS*_MR*_CONTROL_REG[RST_AN]=1 to ensure a fresh sgmii negotiation starts. */
        BDK_CSR_MODIFY(control_reg, handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index),
            control_reg.s.rst_an = 1;
            control_reg.s.an_en = 1;
            control_reg.s.pwr_dn = 0);

        /* Wait for PCS*_MR*_STATUS_REG[AN_CPT] to be set, indicating that
            sgmii autonegotiation is complete. In MAC mode this isn't an ethernet
            link, but a link between Octeon and the PHY */
        if (!bdk_is_simulation() &&
            BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_PCSX_MRX_STATUS_REG(gmx_block, gmx_index), an_cpt, ==, 1, 10000))
        {
            return -1;
        }
    }
    else
    {
        /* A forced interface speed was selected, so configure this for the SGMII link as well,
           and don't do SGMII autonegotiation. */
        BDK_CSR_MODIFY(control_reg, handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index),
                       control_reg.s.spdmsb = (forced_speed_mbps == 1000);
                       control_reg.s.spdlsb = (forced_speed_mbps != 1000);
                       control_reg.s.an_en = 0;
                       control_reg.s.pwr_dn = 0);
    }

    /* CN68XX adds the padding and FCS in PKO, not GMX */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TXX_APPEND(gmx_block, gmx_index),
            c.s.fcs = 0;
            c.s.pad = 0);

    /* Enable error reporting */
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
    BDK_CSR_MODIFY(c, handle->node, BDK_PCSX_INTX_EN_REG(gmx_block, gmx_index),
        c.s.an_bad_en = -1;
        c.s.an_err_en = -1;
        c.s.dbg_sync_en = -1;
        c.s.rxbad_en = -1;
        c.s.rxlock_en = -1;
        c.s.sync_bad_en = -1;
        c.s.txbad_en = -1;
        c.s.txfifo_en = -1;
        c.s.txfifu_en = -1;
    );

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
static int init_link_speed(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    int is_enabled;

    /* Disable GMX before we make any changes. Remember the enable state */
    BDK_CSR_MODIFY(gmxx_prtx_cfg, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        is_enabled = gmxx_prtx_cfg.s.en;
        gmxx_prtx_cfg.s.en = 0);

    /* Wait for GMX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), rx_idle, ==, 1, 10000) ||
        BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), tx_idle, ==, 1, 10000))
    {
        bdk_dprintf("SGMII%d%d: Timeout waiting for idle\n", handle->interface, handle->index);
        return -1;
    }

    /* Read GMX CFG again to make sure the disable completed */
    BDK_CSR_INIT(gmxx_prtx_cfg, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index));

    /* Get the misc control for PCS. We will need to set the duplication amount */
    BDK_CSR_INIT(pcsx_miscx_ctl_reg, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index));

    /* Use GMXENO to force the link down if the status we get says it should be down */
    pcsx_miscx_ctl_reg.s.gmxeno = !link_info.s.up;

    /* Only change the duplex setting if the link is up */
    if (link_info.s.up)
        gmxx_prtx_cfg.s.duplex = link_info.s.full_duplex;

    /* Do speed based setting for GMX */
    switch (link_info.s.speed)
    {
        case 10:
            gmxx_prtx_cfg.s.speed = 0;
            gmxx_prtx_cfg.s.speed_msb = 1;
            gmxx_prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 25; /* Setting from GMX-603 */
            BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_SLOT(gmx_block, gmx_index), 64);
            BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_BURST(gmx_block, gmx_index), 0);
            break;
        case 100:
            gmxx_prtx_cfg.s.speed = 0;
            gmxx_prtx_cfg.s.speed_msb = 0;
            gmxx_prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 0x5;
            BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_SLOT(gmx_block, gmx_index), 64);
            BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_BURST(gmx_block, gmx_index), 0);
            break;
        case 1000:
            gmxx_prtx_cfg.s.speed = 1;
            gmxx_prtx_cfg.s.speed_msb = 0;
            gmxx_prtx_cfg.s.slottime = 1;
            pcsx_miscx_ctl_reg.s.samp_pt = 1;
            BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_SLOT(gmx_block, gmx_index), 512);
	    if (gmxx_prtx_cfg.s.duplex)
                BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_BURST(gmx_block, gmx_index), 0); // full duplex
	    else
                BDK_CSR_WRITE(handle->node, BDK_GMXX_TXX_BURST(gmx_block, gmx_index), 8192); // half duplex
            break;
        default:
            break;
    }

    /* Write the new misc control for PCS */
    BDK_CSR_WRITE(handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index), pcsx_miscx_ctl_reg.u64);

    /* Write the new GMX settings with the port still disabled */
    BDK_CSR_WRITE(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), gmxx_prtx_cfg.u64);

    /* Read GMX CFG again to make sure the config completed */
    gmxx_prtx_cfg.u64 = BDK_CSR_READ(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index));

    /* Restore the enabled / disabled state */
    gmxx_prtx_cfg.s.en = is_enabled;
    BDK_CSR_WRITE(handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index), gmxx_prtx_cfg.u64);

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Configure the PKO internal port mappings */
        int pipe = __bdk_pko_alloc_pipe(handle->node, 1);
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TXX_PIPE(gmx_block, gmx_index),
            c.s.nump = 1;
            c.s.base = pipe);
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */
        ptrs.s.crc = 1;         /* Use CRC on packets */
        ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
        ptrs.s.pipe = pipe;     /* Which PKO pipe */
        ptrs.s.intr = gmx_block*4 + gmx_index;  /* Which interface */
        ptrs.s.eid = __bdk_pko_alloc_engine(handle->node);
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Setup PKIND */
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
            c.s.pknd = handle->pknd);

        /* Setup BPID */
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_BPID_MAPX(gmx_block, gmx_index),
            c.s.val = 1;
            c.s.bpid = handle->pknd);
        BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_BPID_MSK(gmx_block),
            c.s.msk_or |= 1<<handle->index;
            c.s.msk_and &= ~(1<<handle->index));
    }

    if (gmx_index == 0)
    {
        /* Tell GMX the number of TX ports on this interface */
        BDK_CSR_MODIFY(gmx_tx_prts, handle->node, BDK_GMXX_TX_PRTS(gmx_block),
            gmx_tx_prts.s.prts = if_num_ports(handle->node, gmx_block));

        /* Tell GMX the number of RX ports on this interface.  This only
        ** applies to *GMII and XAUI ports */
        BDK_CSR_MODIFY(gmx_rx_prts, handle->node, BDK_GMXX_RX_PRTS(gmx_block),
            gmx_rx_prts.s.prts = if_num_ports(handle->node, gmx_block));

        if (OCTEON_IS_MODEL(OCTEON_CN61XX) || OCTEON_IS_MODEL(OCTEON_CN70XX))
        {
            /* Tell PKO the number of ports on this interface */
            BDK_CSR_MODIFY(pko_mode, handle->node, BDK_PKO_REG_GMX_PORT_MODE,
                if (gmx_block == 0)
                    pko_mode.s.mode0 = 2;
                else
                    pko_mode.s.mode1 = 2);
        }
    }

    /* Enable the interface */
    BDK_CSR_MODIFY(inf_mode, handle->node, BDK_GMXX_INF_MODE(gmx_block),
            inf_mode.s.en=1);

    /* Set GMX to buffer as much data as possible before starting transmit.
        This reduces the chances that we have a TX under run due to memory
        contention. Any packet that fits entirely in the GMX FIFO can never
        have an under run regardless of memory load */
    BDK_CSR_MODIFY(gmx_tx_thresh, handle->node, BDK_GMXX_TXX_THRESH(gmx_block, gmx_index),
        gmx_tx_thresh.s.cnt = 0x100 / 4);

    /* Disable GMX */
    BDK_CSR_MODIFY(gmxx_prtx_cfg, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        gmxx_prtx_cfg.s.en = 0);

    /* Configure to allow max sized frames */
    BDK_CSR_WRITE(handle->node, BDK_GMXX_RXX_JABBER(gmx_block, gmx_index), 65535);

    /* Disable frame alignment if using preamble. This allows the link to
        reach full rate for odd length packets. For example, without this
        SGMII is slower than RGMII for 65 byte packets */
    BDK_CSR_INIT(gmxx_txx_append, handle->node, BDK_GMXX_TXX_APPEND(gmx_block, gmx_index));
    BDK_CSR_MODIFY(c, handle->node, BDK_GMXX_TXX_SGMII_CTL(gmx_block, gmx_index),
        c.s.align = !gmxx_txx_append.s.preamble);

    /* Write PCS*_LINK*_TIMER_COUNT_REG[COUNT] with the appropriate
        value. 1000BASE-X specifies a 10ms interval. SGMII specifies a 1.6ms
        interval. */
    BDK_CSR_INIT(pcsx_miscx_ctl_reg, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index));
    BDK_CSR_INIT(pcsx_linkx_timer_count_reg, handle->node, BDK_PCSX_LINKX_TIMER_COUNT_REG(gmx_block, gmx_index));
    const uint64_t clock_mhz = bdk_clock_get_rate(handle->node, BDK_CLOCK_SCLK) / 1000000;
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
    BDK_CSR_WRITE(handle->node, BDK_PCSX_LINKX_TIMER_COUNT_REG(gmx_block, gmx_index), pcsx_linkx_timer_count_reg.u64);

    /* Write the advertisement register to be used as the
        tx_Config_Reg<D15:D0> of the autonegotiation.
        In 1000BASE-X mode, tx_Config_Reg<D15:D0> is PCS*_AN*_ADV_REG.
        In SGMII PHY mode, tx_Config_Reg<D15:D0> is PCS*_SGM*_AN_ADV_REG.
        In SGMII MAC mode, tx_Config_Reg<D15:D0> is the fixed value 0x4001, so
        this step can be skipped. */
    if (pcsx_miscx_ctl_reg.s.mode)
    {
        /* 1000BASE-X */
        BDK_CSR_MODIFY(pcsx_anx_adv_reg, handle->node, BDK_PCSX_ANX_ADV_REG(gmx_block, gmx_index),
            pcsx_anx_adv_reg.s.rem_flt = 0;
            pcsx_anx_adv_reg.s.pause = 3;
            pcsx_anx_adv_reg.s.hfd = 1;
            pcsx_anx_adv_reg.s.fd = 1);
    }
    else
    {
        if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + gmx_block*4 + gmx_index) == -1) &&
            !pcsx_miscx_ctl_reg.s.mac_phy)
        {
            bdk_dprintf("SGMII%d%d: Forcing PHY mode as PHY address is not set\n", gmx_block, gmx_index);
            pcsx_miscx_ctl_reg.s.mac_phy = 1;
            BDK_CSR_WRITE(handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index), pcsx_miscx_ctl_reg.u64);
        }

        if (pcsx_miscx_ctl_reg.s.mac_phy)
        {
            /* PHY Mode */
            BDK_CSR_MODIFY(pcsx_sgmx_an_adv_reg, handle->node, BDK_PCSX_SGMX_AN_ADV_REG(gmx_block, gmx_index),
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

static int if_enable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(gmx_cfg, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        gmx_cfg.s.en = 1);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    BDK_CSR_MODIFY(gmx_cfg, handle->node, BDK_GMXX_PRTX_CFG(gmx_block, gmx_index),
        gmx_cfg.s.en = 0);
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);
    bdk_if_link_t result;

    result.u64 = 0;

    int qlm = bdk_qlm_get(handle->node, BDK_IF_SGMII, handle->interface);
    int speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm) * 8 / 10;
    if (OCTEON_IS_MODEL(OCTEON_CN70XX))
    {
        /* Divide speed by four to account for QSGMII multiplexing */
        BDK_CSR_INIT(inf_mode, handle->node, BDK_GMXX_INF_MODE(gmx_block));
        if (inf_mode.s.mode == 2)
            speed >>= 2;
    }

    if (bdk_is_simulation())
    {
        /* The simulator gives you a simulated 1Gbps full duplex link */
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = speed;
        return result;
    }

    BDK_CSR_INIT(pcsx_mrx_control_reg, handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index));
    if (pcsx_mrx_control_reg.s.loopbck1)
    {
        /* Force 1Gbps full duplex link for internal loopback */
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = speed;
        return result;
    }


    BDK_CSR_INIT(pcsx_miscx_ctl_reg, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index));
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
            /* Don't bother continuing if the SERTES low level link is down */
            BDK_CSR_INIT(pcsx_mrx_status_reg, handle->node, BDK_PCSX_MRX_STATUS_REG(gmx_block, gmx_index));
            if (bdk_unlikely(pcsx_mrx_status_reg.s.lnk_st == 0))
            {
                /* Read a second time as the lnk_st bit is sticky */
                pcsx_mrx_status_reg.u64 = BDK_CSR_READ(handle->node, BDK_PCSX_MRX_STATUS_REG(gmx_block, gmx_index));
                if (bdk_unlikely(pcsx_mrx_status_reg.s.lnk_st == 0))
                {
                    if (init_link(handle) != 0)
                        return result;
                }
            }

            /* Read the autoneg results */
            BDK_CSR_INIT(pcsx_anx_results_reg, handle->node, BDK_PCSX_ANX_RESULTS_REG(gmx_block, gmx_index));
            if (pcsx_anx_results_reg.s.an_cpt)
            {
                /* Auto negotiation is complete. Set status accordingly */
                result.s.full_duplex = pcsx_anx_results_reg.s.dup;
                result.s.up = pcsx_anx_results_reg.s.link_ok;
                switch (pcsx_anx_results_reg.s.spd)
                {
                    case 0:
                        result.s.speed = speed / 100;
                        break;
                    case 1:
                        result.s.speed = speed / 10;
                        break;
                    case 2:
                        result.s.speed = speed;
                        break;
                    default:
                        result.s.speed = 0;
                        result.s.up = 0;
                        break;
                }
            }
            else
            {
                /* Auto negotiation isn't complete. Return link down */
                result.s.speed = 0;
                result.s.up = 0;
            }
        }
        else /* MAC Mode */
        {
            result = __bdk_if_phy_get(bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + gmx_block*4 + gmx_index));
        }
    }
    return result;
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    int status = init_link(handle);
    if (status == 0)
        status = init_link_speed(handle, link_info);
}


static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    int gmx_block = __bdk_if_get_gmx_block(handle);
    int gmx_index = __bdk_if_get_gmx_index(handle);

    BDK_CSR_MODIFY(c, handle->node, BDK_PCSX_MRX_CONTROL_REG(gmx_block, gmx_index),
        c.s.loopbck1 = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));

    BDK_CSR_MODIFY(c, handle->node, BDK_PCSX_MISCX_CTL_REG(gmx_block, gmx_index),
        c.s.loopbck2 = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0));

    init_link(handle);
    return 0;
}

const __bdk_if_ops_t __bdk_if_ops_sgmii = {
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


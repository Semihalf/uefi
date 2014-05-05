#include <bdk.h>

/* This file implements interfaces connected to the BGX block introduced
    for CN78XX. This block combines SGMII, XAUI, DXAUI, 10G, and 40G all
    into one interface */

typedef enum
{
    BGX_MODE_SGMII,
    BGX_MODE_XAUI,
    BGX_MODE_RXAUI,
    BGX_MODE_10G,
    BGX_MODE_40G,
} bgx_mode_t;

typedef union
{
    void *ptr;
    struct
    {
        uint64_t    reserved_33_64  : 30;
        uint64_t    use_training    : 1;    /* True if this port is in 10G or 40G and uses training */
        uint64_t    higig           : 1;    /* True if this port is in higig mode */
        uint64_t    num_port        : 4;    /* Number of physical ports on this interface */
        uint64_t    port            : 4;    /* Which physical port this handle connects to */
        bgx_mode_t  mode            : 4;    /* BGX mode */
        uint64_t    num_channels    : 12;   /* Total number of channels on this physical port */
        uint64_t    channel         : 8;    /* Which logical channel this handle coresponds to */
    } s;
} bgx_priv_t;

/**
 * The private structure needed by BGX is small enough to fit
 * in 64bits. It will be store in the private pointer, not in
 * memory pointed to by the private pointer
 *
 * @param node      Node this BGX is on
 * @param interface Which BGX
 * @param index     Which channel on the BGX. This is an encoding of port and channel.
 *
 * @return The private structure
 */
static bgx_priv_t create_priv(bdk_node_t node, int interface, int index)
{
    bgx_priv_t priv;
    priv.ptr = NULL;

    int qlm = bdk_qlm_get(node, BDK_IF_BGX, interface);
    if (qlm < 0)
        return priv;

    bdk_qlm_modes_t qlm_mode = bdk_qlm_get_mode(node, qlm);

    switch (qlm_mode)
    {
        case BDK_QLM_MODE_SGMII:
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_SGMII;
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            priv.s.higig = bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface);
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_XAUI;
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            priv.s.higig = bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface);
            priv.s.num_port = 2;
            priv.s.mode = BGX_MODE_RXAUI;
            break;
        case BDK_QLM_MODE_10GR_4X1:
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_10G;
            /* Only XFI supports training */
            priv.s.use_training = 1;
            break;
        case BDK_QLM_MODE_40GR4_1X4:
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_40G;
            /* XLAUI doesn't support training */
            break;
        default:
            priv.s.num_port = 0;
            break;
    }
    priv.s.port = (priv.s.higig) ? (index>>4) : index;
    priv.s.num_channels = (priv.s.higig) ? 16 : 1;
    priv.s.channel = (priv.s.higig) ? (index&0xf) : 0;
    return priv;
}

static int if_num_interfaces(bdk_node_t node)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 6;
    else
        return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    bgx_priv_t priv = create_priv(node, interface, 0);
    return priv.s.num_port * priv.s.num_channels;
}

/**
 * Perform initialization of the BGX required before use. This should only be
 * called once for each BGX. Before this is called, the mode of
 * the SERDES must be set by bdk_qlm_set_mode().
 *
 * @param interface Which BGX to setup. This will have index=0
 *
 * @return Zero on success, negative on failure
 */
static int bgx_setup_one_time(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};

    /* First warn if BIST failed */
    uint64_t bist = BDK_CSR_READ(handle->node, BDK_BGXX_CMR_BIST_STATUS(handle->interface));
    if (bist)
        bdk_warn("BGX%d failed BIST\n", handle->interface);

    int lmac_type;
    int lane_to_sds;
    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
            lmac_type = 0;
            lane_to_sds = handle->index;
            break;
        case BGX_MODE_XAUI:
            lmac_type = 1;
            lane_to_sds = 0xe4;
            break;
        case BGX_MODE_RXAUI:
            lmac_type = 2;
            lane_to_sds = (handle->index) ? 0xe : 0x4;
            break;
        case BGX_MODE_10G:
            lmac_type = 3;
            lane_to_sds = handle->index;
            break;
        case BGX_MODE_40G:
        default:
            lmac_type = 4;
            lane_to_sds = 0xe4;
            break;
    }
    /* Set mode and lanes */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(handle->interface, handle->index),
        c.s.lmac_type = lmac_type;
        c.s.lane_to_sds = lane_to_sds);
    /* Set the PKND */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_RX_ID_MAP(handle->interface, handle->index),
        c.s.pknd = handle->pknd);

    /* Set the number of LMACs we will use */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_TX_LMACS(handle->interface),
        c.s.lmacs = priv.s.num_port);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_RX_LMACS(handle->interface),
        c.s.lmacs = priv.s.num_port);

    /* Set the backpressure AND mask. Each interface gets 16 channels in this
       mask. When there is only 1 port, all 64 channels are available but
       the upper channels are used for anything. That's why this code only uses
       16 channels per interface */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_CHAN_MSK_AND(handle->interface),
        c.s.msk_and |= ((1<<priv.s.num_channels) - 1) << (handle->index * 16));

    return 0;
}

static int if_probe(bdk_if_handle_t handle)
{
    bgx_priv_t priv = create_priv(handle->node, handle->interface, handle->index);
    handle->priv = priv.ptr;

    /* Change name to be something that might be meaningful to the user */
    const char *name_format;
    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
            if (bdk_numa_is_only_one())
                name_format = "SGMII%d.%d";
            else
                name_format = "N%d.SGMII%d.%d";
            break;
        case BGX_MODE_XAUI:
            if (bdk_numa_is_only_one())
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "XAUI%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.XAUI%d";
            break;
        case BGX_MODE_RXAUI:
            if (bdk_numa_is_only_one())
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "RXAUI%d.%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.RXAUI%d.%d";
            break;
        case BGX_MODE_10G:
            if (bdk_numa_is_only_one())
                name_format = "XFI%d.%d";
            else
                name_format = "N%d.XFI%d.%d";
            break;
        case BGX_MODE_40G:
            if (bdk_numa_is_only_one())
                name_format = "XLAUI%d";
            else
                name_format = "N%d.XLAUI%d";
            break;
        default:
            return -1;
    }
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), name_format, handle->interface, priv.s.port, priv.s.channel);
    else
        snprintf(handle->name, sizeof(handle->name), name_format, handle->node, handle->interface, priv.s.port, priv.s.channel);
    handle->name[sizeof(handle->name)-1] = 0;

    /* Use IPD ports 0x800 - 0x830, 0x900 - 0x930, ... */
    handle->ipd_port = 0x800 + handle->interface*0x100 + priv.s.port*0x10 + priv.s.channel;
    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
    return bgx_setup_one_time(handle);
}

static int sgmii_link(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;

    int forced_speed_mbps = 0;  /* Default to no forced speed, use autonegotiation */
    /* Check for special PHY address values that indicate a forced speed, and no MDIO
       connection to the PHY.  In these cases we will also force the SGMII speed, and not
       do SGMII autonegotiation. Only 1000/100 Mbits/second are supported.*/
    if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + bgx_block*4 + bgx_index) == 0x1000))
        forced_speed_mbps = 1000;
    else if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + bgx_block*4 + bgx_index) == 0x1001))
        forced_speed_mbps = 100;

    /* Take PCS through a reset sequence.
        PCS*_MR*_CONTROL_REG[PWR_DN] should be cleared to zero.
        Write PCS*_MR*_CONTROL_REG[RESET]=1 (while not changing the value of
            the other PCS*_MR*_CONTROL_REG bits).
        Read PCS*_MR*_CONTROL_REG[RESET] until it changes value to zero. */
    if (!bdk_is_simulation())
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(bgx_block, bgx_index),
            c.s.reset = 1);
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(bgx_block, bgx_index), reset, ==, 0, 10000))
        {
            bdk_dprintf("%s: Timeout waiting for reset finish\n", handle->name);
            return -1;
        }
    }

    if (!forced_speed_mbps)
    {
        /* Write PCS*_MR*_CONTROL_REG[RST_AN]=1 to ensure a fresh sgmii negotiation starts. */
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(bgx_block, bgx_index),
            c.s.rst_an = 1;
            c.s.an_en = 1;
            c.s.pwr_dn = 0);

        /* Wait for PCS*_MR*_STATUS_REG[AN_CPT] to be set, indicating that
            sgmii autonegotiation is complete. In MAC mode this isn't an ethernet
            link, but a link between Octeon and the PHY */
        if (!bdk_is_simulation() &&
            BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_PCS_MRX_STATUS(bgx_block, bgx_index), an_cpt, ==, 1, 10000))
        {
            return -1;
        }
    }
    else
    {
        /* A forced interface speed was selected, so configure this for the SGMII link as well,
           and don't do SGMII autonegotiation. */
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(bgx_block, bgx_index),
                       c.s.spdmsb = (forced_speed_mbps == 1000);
                       c.s.spdlsb = (forced_speed_mbps != 1000);
                       c.s.an_en = 0;
                       c.s.pwr_dn = 0);
    }

    /* Write PCS*_LINK*_TIMER_COUNT_REG[COUNT] with the appropriate
        value. SGMII specifies a 1.6ms interval, 10ms for everybody else. */
    BDK_CSR_INIT(pcs_miscx_ctl, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index));
    BDK_CSR_INIT(pcs_linkx_timer, handle->node, BDK_BGXX_GMP_PCS_LINKX_TIMER(bgx_block, bgx_index));
    const uint64_t clock_mhz = bdk_clock_get_rate(handle->node, BDK_CLOCK_SCLK) / 1000000;
    if (pcs_miscx_ctl.s.mode)
    {
        /* 1000BASE-X */
        pcs_linkx_timer.s.count = (10000ull * clock_mhz) >> 10;
    }
    else
    {
        /* SGMII */
        pcs_linkx_timer.s.count = (1600ull * clock_mhz) >> 10;
    }
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_LINKX_TIMER(bgx_block, bgx_index), pcs_linkx_timer.u64);

    /* Write the advertisement register to be used as the
        tx_Config_Reg<D15:D0> of the autonegotiation.
        In 1000BASE-X mode, tx_Config_Reg<D15:D0> is PCS*_AN*_ADV_REG.
        In SGMII PHY mode, tx_Config_Reg<D15:D0> is PCS*_SGM*_AN_ADV_REG.
        In SGMII MAC mode, tx_Config_Reg<D15:D0> is the fixed value 0x4001, so
        this step can be skipped. */
    if (pcs_miscx_ctl.s.mode)
    {
        /* 1000BASE-X */
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_ANX_ADV(bgx_block, bgx_index),
            c.s.rem_flt = 0;
            c.s.pause = 3;
            c.s.hfd = 1;
            c.s.fd = 1);
    }
    else
    {
        if (((int)bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + bgx_block*4 + bgx_index) == -1) &&
            !pcs_miscx_ctl.s.mac_phy)
        {
            bdk_dprintf("%s: Forcing PHY mode as PHY address is not set\n", handle->name);
            pcs_miscx_ctl.s.mac_phy = 1;
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index), pcs_miscx_ctl.u64);
        }

        if (pcs_miscx_ctl.s.mac_phy)
        {
            /* PHY Mode */
            BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_SGMX_AN_ADV(bgx_block, bgx_index),
                c.s.dup = 1;
                c.s.speed= 2);
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
 * Configure an SGMII link to the specified speed after the SERTES
 * link is up.
 *
 * @param interface Interface to init
 * @param index     Index of prot on the interface
 * @param link_info Link state to configure
 *
 * @return Zero on success, negative on failure
 */
static int sgmii_speed(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    int is_enabled;

    /* Disable GMX before we make any changes. Remember the enable state */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
        is_enabled = c.s.enable;
        c.s.enable = 0);

    /* Wait for GMX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), rx_idle, ==, 1, 10000) ||
        BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), tx_idle, ==, 1, 10000))
    {
        bdk_dprintf("%s: Timeout waiting for idle\n", handle->name);
        return -1;
    }

    /* Read GMX CFG again to make sure the disable completed */
    BDK_CSR_INIT(prtx_cfg, handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index));

    /* Get the misc control for PCS. We will need to set the duplication amount */
    BDK_CSR_INIT(pcsx_miscx_ctl_reg, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index));

    /* Use GMXENO to force the link down if the status we get says it should be down */
    pcsx_miscx_ctl_reg.s.gmxeno = !link_info.s.up;

    /* Only change the duplex setting if the link is up */
    if (link_info.s.up)
        prtx_cfg.s.duplex = link_info.s.full_duplex;

    /* Do speed based setting for GMX */
    switch (link_info.s.speed)
    {
        case 10:
            prtx_cfg.s.speed = 0;
            prtx_cfg.s.speed_msb = 1;
            prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 25; /* Setting from GMX-603 */
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_SLOT(bgx_block, bgx_index), 64);
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_BURST(bgx_block, bgx_index), 0);
            break;
        case 100:
            prtx_cfg.s.speed = 0;
            prtx_cfg.s.speed_msb = 0;
            prtx_cfg.s.slottime = 0;
            pcsx_miscx_ctl_reg.s.samp_pt = 0x5;
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_SLOT(bgx_block, bgx_index), 64);
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_BURST(bgx_block, bgx_index), 0);
            break;
        case 1000:
            prtx_cfg.s.speed = 1;
            prtx_cfg.s.speed_msb = 0;
            prtx_cfg.s.slottime = 1;
            pcsx_miscx_ctl_reg.s.samp_pt = 1;
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_SLOT(bgx_block, bgx_index), 512);
	    if (prtx_cfg.s.duplex)
                BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_BURST(bgx_block, bgx_index), 0); // full duplex
	    else
                BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_TXX_BURST(bgx_block, bgx_index), 8192); // half duplex
            break;
        default:
            break;
    }

    /* Write the new misc control for PCS */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index), pcsx_miscx_ctl_reg.u64);

    /* Write the new GMX settings with the port still disabled */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), prtx_cfg.u64);

    /* Restore the enabled / disabled state */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
        c.s.enable = is_enabled);
    return 0;
}

static int setup_auto_neg(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};

    // FIXME: Disabled as it currently doesn't work
    int use_auto_neg = 0;//(priv.s.mode == BGX_MODE_10G) || (priv.s.mode == BGX_MODE_40G);

    /* Software should do the following to execute Auto-Negotiation when
       desired: */
    /* 1. Set BGX(0..5)_SPU(0..3)_AN_CONTROL[AN_EN] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_AN_CONTROL(bgx_block, bgx_index),
        c.s.an_en = use_auto_neg);

    /* 2. Program the negotiation parameters to be advertised to the link
       parter in BGX(0..5)_SPU(0..3)_AN_ADV. The advertised parameters must
       be consistent with the programmed BGX(0..5)_CMR(0..3)_CONFIG[LMAC_TYPE]
       and BGX(0..5)_SPU(0..3)_FEC_CONTROL[FEC_EN] values. */
    BDK_CSR_INIT(fec_control, handle->node, BDK_BGXX_SPUX_FEC_CONTROL(bgx_block, bgx_index));
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_AN_ADV(bgx_block, bgx_index),
        c.s.fec_req = fec_control.s.fec_en;
        c.s.fec_able = 1;
        c.s.a100g_cr10 = 0;
        c.s.a40g_cr4 = (priv.s.mode == BGX_MODE_40G);
        c.s.a40g_kr4 = (priv.s.mode == BGX_MODE_40G);
        c.s.a10g_kr = (priv.s.mode == BGX_MODE_10G);
        c.s.a10g_kx4 = (priv.s.mode == BGX_MODE_10G);
        c.s.a1g_kx = 0;
        c.s.rf = 0);

    /* 3. Set BGX(0..5)_SPU_DBG_CONTROL[AN_ARB_LINK_CHK_EN] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPU_DBG_CONTROL(bgx_block),
        c.s.an_arb_link_chk_en = use_auto_neg);

    /* 4. Execute the link bring-up sequence in Section 33.6.3. */
    /* Done after this function is called */

    /* 5. If the auto-negotiation protocol is successful,
       BGX(0..5)_SPU(0..3)_AN_ADV[AN_COMPLETE] is set along with
       BGX(0..5)_SPU(0..3)_INT[AN_COMPLETE] when the link is up. */
    /* Done after this function is called */
    return 0;
}

static int xaui_init(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};

    /* NOTE: This code was moved first, out of order compared to the HRM
       because the RESET causes all SPU registers to loose their value */
    /* 4. Next, bring up the SMU/SPU and the BGX reconciliation layer logic: */
    /* 4a. Take SMU/SPU through a reset sequence. Write
        BGX(0..5)_SPU(0..3)_CONTROL1[RESET] = 1. Read
        BGX(0..5)_SPU(0..3)_CONTROL1[RESET] until it changes value to 0. Keep
        BGX(0..5)_SPU(0..3)_MISC_CONTROL[RX_PACKET_DIS] = 1 to disable
        reception. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        c.s.reset = 1);
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index), reset, ==, 0, 1000))
    {
        BDK_TRACE("%s: SPU stuck in reset\n", handle->name);
        return -1;
    }

    /* 1. Write BGX(0..5)_CMR(0..3)_CONFIG[ENABLE] to 0,
       BGX(0..5)_SPU(0..3)_CONTROL1[LO_PWR] = 1 and
       BGX(0..5)_SPU(0..3)_MISC_CONTROL[RX_PACKET_DIS] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
        c.s.enable = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        c.s.lo_pwr = 1);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_MISC_CONTROL(bgx_block, bgx_index),
        c.s.rx_packet_dis = 1);

    /* 2. At this point, it may be appropriate to disable all BGX and SMU/SPU
       interrupts, as a number of them will occur during bring-up of the Link.
        - zero BGX(0..5)_SMU(0..3)_RX_INT
        - zero BGX(0..5)_SMU(0..3)_TX_INT
        - zero BGX(0..5)_SPU(0..3)_INT */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SMUX_RX_INT(bgx_block, bgx_index), BDK_CSR_READ(handle->node, BDK_BGXX_SMUX_RX_INT(bgx_block, bgx_index)));
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SMUX_TX_INT(bgx_block, bgx_index), BDK_CSR_READ(handle->node, BDK_BGXX_SMUX_TX_INT(bgx_block, bgx_index)));
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index), BDK_CSR_READ(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index)));

    /* 3. Configure the BGX LMAC. */
    /* 3a. Configure the LMAC type (40GBASE-R/10GBASE-R/RXAUI/XAUI) and
        SerDes selection in the BGX(0..5)_CMR(0..3)_CONFIG register, but keep
        the ENABLE, DATA_PKT_TX_EN and DATA_PKT_RX_EN bits clear. */
    /* Already done in bgx_setup_one_time */

    /* 3b. Write BGX(0..5)_SPU(0..3)_CONTROL1[LO_PWR] = 1 and
       BGX(0..5)_SPU(0..3)_MISC_CONTROL[RX_PACKET_DIS] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        c.s.lo_pwr = 1);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_MISC_CONTROL(bgx_block, bgx_index),
        c.s.rx_packet_dis = 1);

    /* 3c. Initialize the selected SerDes lane(s) in the QLM. See Section
       28.1.2.2 in the GSER chapter. */
    /* Already done in QLM setup */

    /* 3d. For 10GBASE-KR or 40GBASE-KR, enable link training by writing
       BGX(0..5)_SPU(0..3)_BR_PMD_CONTROL[TRAIN_EN] = 1. */
    if (priv.s.use_training)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, bgx_index),
            c.s.train_en = 1);
    }

    /* 3e. Program all other relevant BGX configuration while
       BGX(0..5)_CMR(0..3)_CONFIG[ENABLE] = 0. This includes all things
       described in this chapter. */
    /* Don't add a FCS as PKO does that */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SMUX_TX_APPEND(bgx_block, bgx_index),
        c.s.fcs_d = 0);

    /* 3f. If Forward Error Correction is desired for 10GBASE-R or 40GBASE-R,
       enable it by writing BGX(0..5)_SPU(0..3)_FEC_CONTROL[FEC_EN] = 1. */
    if ((priv.s.mode == BGX_MODE_10G) || (priv.s.mode == BGX_MODE_40G))
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_FEC_CONTROL(bgx_block, bgx_index),
            c.s.fec_en = 1);
    }

    /* 3g. If Auto-Negotiation is desired, configure and enable
       Auto-Negotiation as described in Section 33.6.2. */
    if (setup_auto_neg(handle))
        return -1;

    /* 3h. Set BGX(0..5)_CMR(0..3)_CONFIG[ENABLE] = 1 and
       BGX(0..5)_SPU(0..3)_CONTROL1[LO_PWR] = 0 to enable the LMAC. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
        c.s.enable = 1);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        c.s.lo_pwr = 0);

    /* 4b. Set the polarity and lane swapping of the QLM SerDes. Refer to
        Section 33.4.1, BGX(0..5)_SPU(0..3)_MISC_CONTROL[XOR_TXPLRT,XOR_RXPLRT]
        and BGX(0..5)_SPU(0..3)_MISC_CONTROL[TXPLRT,RXPLRT]. */

    /* 4c. Write BGX(0..5)_SPU(0..3)_CONTROL1[LO_PWR] = 0. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        c.s.lo_pwr = 0);

    /* 4d. Select Deficit Idle Count mode and unidirectional enable/disable
       via BGX(0..5)_SMU(0..3)_TX_CTL[DIC_EN,UNI_EN]. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SMUX_TX_CTL(bgx_block, bgx_index),
        c.s.dic_en = 1; /* Enable better IFG packing and improves performance */
        c.s.uni_en = 0);

    /* Errata #20844
    1) After the link first comes up write the following
       register on each lane to prevent the application logic
       from stomping on the Coast inputs. This is a one time write,
       or if you prefer you could put it in the link up loop and
       write it every time the link comes up.
    1a) Then write GSER(0..13)_LANE(0..3)_PCS_CTLIFC_2
            Set CTLIFC_OVRRD_REQ (later)
            Set CFG_RX_CDR_COAST_REQ_OVRRD_EN
       Its not clear if #1 and #1a can be combined, lets try it
       this way first. */
    const int qlm = bdk_qlm_get(handle->node, BDK_IF_BGX, handle->interface);
    for (int lane=0; lane<4; lane++)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
            c.s.cfg_rx_cdr_coast_req_ovrrd_en = 1);
    }

    return 0;
}

static int xaui_link(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    const int TIMEOUT = 100; /* 100us */
    bgx_priv_t priv = {.ptr = handle->priv};

    /* Disable packet reception */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_MISC_CONTROL(bgx_block, bgx_index),
        c.s.rx_packet_dis = 1);

    if (!bdk_is_simulation())
    {
        if (priv.s.use_training)
        {
            /* Check if training is done */
            BDK_CSR_INIT(spux_int, handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index));
            if (!spux_int.s.training_done)
            {
                /* Clear the training interrupts (W1C) */
                spux_int.u = 0;
                spux_int.s.training_failure = 1;
                spux_int.s.training_done = 1;
                BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index), spux_int.u);
                /* Restart training */
                BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, bgx_index),
                    c.s.train_restart = 1);
                BDK_TRACE("%s: Restarting link training\n", handle->name);
                return -1;
            }
        }
        /* Wait for PCS to come out of reset */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index), reset, ==, 0, TIMEOUT))
        {
            BDK_TRACE("%s: PCS in reset\n", handle->name);
            return -1;
        }

        if ((priv.s.mode == BGX_MODE_10G) || (priv.s.mode == BGX_MODE_40G))
        {
            /* 10G-R/40G-R - Wait for BASE-R PCS block lock */
            if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_BR_STATUS1(bgx_block, bgx_index), blk_lock, ==, 1, TIMEOUT))
            {
                BDK_TRACE("%s: BASE-R PCS block not locked\n", handle->name);
                /* Errata #20844
                2) When a link down event is registered, write the following
                    register across all lanes twice. */
                const int qlm = bdk_qlm_get(handle->node, BDK_IF_BGX, handle->interface);
                for (int lane=0; lane<4; lane++)
                {
                    BDK_CSR_MODIFY(c, handle->node, BDK_GSERX_LANEX_RX_MISC_OVRRD(qlm, lane),
                        c.s.cfg_rx_eie_det_ovrrd_en = 1;
                        c.s.cfg_rx_eie_det_ovrrd_val = 0);
                }
                for (int lane=0; lane<4; lane++)
                {
                    BDK_CSR_MODIFY(c, handle->node, BDK_GSERX_LANEX_RX_MISC_OVRRD(qlm, lane),
                        c.s.cfg_rx_eie_det_ovrrd_en = 1;
                        c.s.cfg_rx_eie_det_ovrrd_val = 1);
                    BDK_CSR_MODIFY(c, handle->node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
                        c.s.ctlifc_ovrrd_req = 1);
                }
                return -1;
            }
        }
        else
        {
            /* XAUI/DXAUI/RXAUI - Wait for PCS to be aligned */
            if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_BX_STATUS(bgx_block, bgx_index), alignd, ==, 1, TIMEOUT))
            {
                BDK_TRACE("%s: PCS not aligned\n", handle->name);
                return -1;
            }
        }

        /* Clear rcvflt bit (latching high) and read it back */
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_STATUS2(bgx_block, bgx_index),
            c.s.rcvflt = 1);
        BDK_CSR_INIT(spux_status2, handle->node, BDK_BGXX_SPUX_STATUS2(bgx_block, bgx_index));
        if (spux_status2.s.rcvflt)
        {
            BDK_TRACE("%s: Receive fault, need to retry\n", handle->name);
            if (priv.s.use_training)
            {
                /* Restart training */
                BDK_CSR_DEFINE(spux_int, BDK_BGXX_SPUX_INT(bgx_block, bgx_index));
                /* Clear the training interrupts (W1C) */
                spux_int.u = 0;
                spux_int.s.training_failure = 1;
                spux_int.s.training_done = 1;
                BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index), spux_int.u);
                /* Restart training */
                BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, bgx_index),
                    c.s.train_restart = 1);
            }
            return -1;
        }
        /* Wait for MAC RX to be ready */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SMUX_RX_CTL(bgx_block, bgx_index), status, ==, 0, TIMEOUT))
        {
            BDK_TRACE("%s: RX not ready\n", handle->name);
            return -1;
        }

        /* (6) Configure BGX */

        /* Wait for BGX RX to be idle */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SMUX_CTRL(bgx_block, bgx_index), rx_idle, ==, 1, TIMEOUT))
        {
            BDK_TRACE("%s: RX not idle\n", handle->name);
            return -1;
        }
        /* Wait for BGX TX to be idle */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SMUX_CTRL(bgx_block, bgx_index), tx_idle, ==, 1, TIMEOUT))
        {
            BDK_TRACE("%s: TX not idle\n", handle->name);
            return -1;
        }
        /* rcvflt should still be 0 */
        spux_status2.u = BDK_CSR_READ(handle->node, BDK_BGXX_SPUX_STATUS2(bgx_block, bgx_index));
        if (spux_status2.s.rcvflt)
        {
            BDK_TRACE("%s: Receive fault, need to retry\n", handle->name);
            return -1;
        }
        /* Receive link is latching low. Force it high and verify it */
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_STATUS1(bgx_block, bgx_index),
            c.s.rcv_lnk = 1);
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_STATUS1(bgx_block, bgx_index), rcv_lnk, ==, 1, TIMEOUT))
        {
            BDK_TRACE("%s: Receive link down\n", handle->name);
            return -1;
        }
    }

    /* Enable packet reception */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_MISC_CONTROL(bgx_block, bgx_index),
        c.s.rx_packet_dis = 0);
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};

    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
            /* Don't add a FCS as PKO does that */
            BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_GMI_TXX_APPEND(bgx_block, bgx_index),
                c.s.fcs = 0);
            break;
        case BGX_MODE_XAUI:
        case BGX_MODE_RXAUI:
        case BGX_MODE_10G:
        case BGX_MODE_40G:
        default:
            xaui_init(handle);
            break;
    }

    /* Set GMX to buffer as much data as possible before starting transmit.
        This reduces the chances that we have a TX under run due to memory
        contention. Any packet that fits entirely in the GMX FIFO can never
        have an under run regardless of memory load */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_GMI_TXX_THRESH(bgx_block, bgx_index),
        c.s.cnt = (0x800 / priv.s.num_port) - 1);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SMUX_TX_THRESH(bgx_block, bgx_index),
        c.s.cnt = (0x800 / priv.s.num_port) - 1);

    /* Configure to allow max sized frames */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_RXX_JABBER(bgx_block, bgx_index), 0xfff8);
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SMUX_RX_JABBER(bgx_block, bgx_index), 0xfff8);

    /* Disable frame alignment if using preamble. This allows the link to
        reach full rate for odd length packets. For example, without this
        SGMII is slower than RGMII for 65 byte packets */
    BDK_CSR_INIT(txx_append, handle->node, BDK_BGXX_GMP_GMI_TXX_APPEND(bgx_block, bgx_index));
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(bgx_block, bgx_index),
        c.s.align = !txx_append.s.preamble);

    bdk_if_link_autoconf(handle);
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(handle->interface, priv.s.port),
        c.s.enable = 1;
        c.s.data_pkt_tx_en = 1;
        c.s.data_pkt_rx_en = 1);
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(handle->interface, priv.s.port),
        c.s.enable = 0;
        c.s.data_pkt_tx_en = 0;
        c.s.data_pkt_rx_en = 0);
    return 0;
}

static bdk_if_link_t if_link_get_sgmii(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bdk_if_link_t result;
    //bgx_priv_t priv = {.ptr = handle->priv};

    result.u64 = 0;

    int qlm = bdk_qlm_get(handle->node, BDK_IF_BGX, handle->interface);
    int speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm) * 8 / 10;

    if (bdk_is_simulation())
    {
        /* The simulator gives you a simulated 1Gbps full duplex link */
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = speed;
        return result;
    }

    BDK_CSR_INIT(gmp_pcs_mrx_control, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(bgx_block, bgx_index));
    if (gmp_pcs_mrx_control.s.loopbck1)
    {
        /* Force 1Gbps full duplex link for internal loopback */
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = speed;
        return result;
    }


    BDK_CSR_INIT(gmp_pcs_miscx_ctl, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index));
    if (gmp_pcs_miscx_ctl.s.mode)
    {
        /* 1000BASE-X */
        // FIXME
    }
    else
    {
        if (gmp_pcs_miscx_ctl.s.mac_phy)
        {
            /* PHY Mode */
            /* Don't bother continuing if the SERTES low level link is down */
            BDK_CSR_INIT(gmp_pcs_mrx_status, handle->node, BDK_BGXX_GMP_PCS_MRX_STATUS(bgx_block, bgx_index));
            if (bdk_unlikely(gmp_pcs_mrx_status.s.lnk_st == 0))
            {
                /* Read a second time as the lnk_st bit is sticky */
                gmp_pcs_mrx_status.u64 = BDK_CSR_READ(handle->node, BDK_BGXX_GMP_PCS_MRX_STATUS(bgx_block, bgx_index));
                if (bdk_unlikely(gmp_pcs_mrx_status.s.lnk_st == 0))
                {
                    if (sgmii_link(handle) != 0)
                        return result;
                }
            }

            /* Read the autoneg results */
            BDK_CSR_INIT(gmp_pcs_anx_results, handle->node, BDK_BGXX_GMP_PCS_ANX_RESULTS(bgx_block, bgx_index));
            if (gmp_pcs_anx_results.s.an_cpt)
            {
                /* Auto negotiation is complete. Set status accordingly */
                result.s.full_duplex = gmp_pcs_anx_results.s.dup;
                result.s.up = gmp_pcs_anx_results.s.link_ok;
                switch (gmp_pcs_anx_results.s.spd)
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
            result = __bdk_if_phy_get(bdk_config_get(BDK_CONFIG_PHY_IF0_PORT0 + bgx_block*4 + bgx_index));
        }
    }
    return result;
}

static bdk_if_link_t if_link_get_xaui(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bdk_if_link_t result;
    result.u64 = 0;

    BDK_CSR_INIT(status1, handle->node, BDK_BGXX_SPUX_STATUS1(bgx_block, bgx_index));
    if (status1.s.rcv_lnk)
    {
        int qlm = bdk_qlm_get(handle->node, BDK_IF_BGX, handle->interface);
        result.s.lanes = 4 / priv.s.num_port;
        result.s.up = 1;
        result.s.full_duplex = 1;
        uint64_t speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm);
        switch (priv.s.mode)
        {
            case BGX_MODE_10G:
            case BGX_MODE_40G:
                /* Using 64b66b symbol encoding */
                speed = (speed * 64 + 33) / 66;
                break;
            default:
                /* Using 8b10b symbol encoding */
                speed = (speed * 8 + 5) / 10;
                break;
        }
        speed *= result.s.lanes;
        result.s.speed = speed;
    }
    else
    {
        xaui_link(handle);
    }
    return result;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    bdk_if_link_t result;
    result.u64 = 0;

    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
            result = if_link_get_sgmii(handle);
            break;
        case BGX_MODE_XAUI:
        case BGX_MODE_RXAUI:
        case BGX_MODE_10G:
        case BGX_MODE_40G:
        default:
            result = if_link_get_xaui(handle);
            break;
    }
    return result;
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
        {
            int status = sgmii_link(handle);
            if (status == 0)
                sgmii_speed(handle, link_info);
            break;
        }
        case BGX_MODE_XAUI:
        case BGX_MODE_RXAUI:
        case BGX_MODE_10G:
        case BGX_MODE_40G:
        default:
            xaui_link(handle);
            break;
    }
}


static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    bgx_priv_t priv = {.ptr = handle->priv};

    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(handle->interface, priv.s.port),
        c.s.loopbck1 = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));

    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(handle->interface, priv.s.port),
        c.s.loopbck2 = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0));

    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
            sgmii_link(handle);
            break;
        case BGX_MODE_XAUI:
        case BGX_MODE_RXAUI:
        case BGX_MODE_10G:
        case BGX_MODE_40G:
        default:
            xaui_link(handle);
            break;
    }
    return 0;
}

/**
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    if (bdk_unlikely(bdk_is_simulation()))
        return &handle->stats;

    /* Counters seem to only be wrong in XAUI and RXAUI */
    const int bytes_off_tx = (priv.s.mode != BGX_MODE_SGMII) ? -8 : 0;
    const int bytes_off_rx = 0;

    /* Read the RX statistics from BGX. These already include the ethernet FCS */
    BDK_CSR_INIT(rx_packets, handle->node, BDK_BGXX_CMRX_RX_STAT0(handle->interface, handle->index));
    BDK_CSR_INIT(rx_octets, handle->node, BDK_BGXX_CMRX_RX_STAT1(handle->interface, handle->index));
    BDK_CSR_INIT(rx_dropped_packets, handle->node, BDK_BGXX_CMRX_RX_STAT6(handle->interface, handle->index));
    BDK_CSR_INIT(rx_dropped_octets, handle->node, BDK_BGXX_CMRX_RX_STAT7(handle->interface, handle->index));
    BDK_CSR_INIT(rx_errors, handle->node, BDK_BGXX_CMRX_RX_STAT8(handle->interface, handle->index));

    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(
        rx_dropped_octets.s.cnt, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(
        rx_dropped_packets.s.cnt, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    handle->stats.rx.octets -= handle->stats.rx.packets * bytes_off_rx;
    handle->stats.rx.octets = bdk_update_stat_with_overflow(
        rx_octets.s.cnt, handle->stats.rx.octets, 48);
    handle->stats.rx.packets = bdk_update_stat_with_overflow(
        rx_packets.s.cnt, handle->stats.rx.packets, 48);
    handle->stats.rx.errors = bdk_update_stat_with_overflow(
        rx_errors.s.cnt, handle->stats.rx.errors, 48);
    handle->stats.rx.octets += handle->stats.rx.packets * bytes_off_rx;

    /* Read the TX statistics from BGX. These already include the ethernet FCS */
    BDK_CSR_INIT(tx_octets, handle->node, BDK_BGXX_CMRX_TX_STAT4(handle->interface, handle->index));
    BDK_CSR_INIT(tx_packets, handle->node, BDK_BGXX_CMRX_TX_STAT5(handle->interface, handle->index));

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(tx_octets.s.octs, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(tx_packets.s.pkts, handle->stats.tx.packets, 48);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    return &handle->stats;
}

const __bdk_if_ops_t __bdk_if_ops_bgx = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_set = if_link_set,
    .if_loopback = if_loopback,
    .if_get_stats = if_get_stats,
};


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
        uint64_t    reserved_33_64  : 31;
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
    priv.s.higig = bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + interface);

    BDK_CSR_INIT(config, node, BDK_BGXX_CMRX_CONFIG(interface, 0));

    switch (config.s.lmac_type)
    {
        case 0: /* SGMII - 1 lane each */
            priv.s.higig = 0; /* We don't support Higig over SGMII */
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_SGMII;
            break;
        case 1: /* 10GBASE-X/XAUI or DXAUI - 4 lanes each */
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_XAUI;
            break;
        case 2: /* Reduced XAUI - 2 lanes each */
            priv.s.num_port = 2;
            priv.s.mode = BGX_MODE_RXAUI;
            break;
        case 3: /* 10GBASE-R - 1 lane each */
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_10G;
            break;
        case 4: /* 40GBASE-R - 4 lanes each */
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_40G;
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
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "10G%d.%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.10G%d.%d";
            break;
        case BGX_MODE_40G:
            if (bdk_numa_is_only_one())
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "40G%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.40G%d";
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
    return 0;
}

/**
 * Perform intialization of the BGX required before use. This should only be
 * called once for each BGX. Before this is called, the mode of the BGX must be
 * set in BGXX_CMRX_CONFIG[lmac_type].
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

    /* Set the number of LMACs we will use */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_TX_LMACS(handle->interface),
        c.s.lmacs = priv.s.num_port);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_RX_LMACS(handle->interface),
        c.s.lmacs = priv.s.num_port);
    return 0;
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

static int xaui_link(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;

    /* (1) Interface has already been enabled. */

    /* (2) Disable GMX. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index),
        c.s.gmxeno = 1);

    /* (3) Disable GMX and PCSX interrupts. */
    // 78xx interrupt mess?

    /* (4) Bring up the PCSX and GMX reconciliation layer. */
    /* (4)a Set polarity and lane swapping. */
    /* (4)b */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SMUX_TX_CTL(bgx_block, bgx_index),
        c.s.dic_en = 1; /* Enable better IFG packing and improves performance */
        c.s.uni_en = 0);

    /* (4)c Power up the interface */
    BDK_CSR_MODIFY(xauiCtl, handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index),
        xauiCtl.s.lo_pwr = 0);

    /* Wait for PCS to come out of reset */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index), reset, ==, 0, 10000))
        return -1;
    /* Wait for PCS to be aligned */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_BX_STATUS(bgx_block, bgx_index), alignd, ==, 1, 10000))
        return -1;
    /* Wait for RX to be ready */
    // FIXME
    //if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_GMXX_RX_XAUI_CTL(bgx_block), status, ==, 0, 10000))
        //return -1;

    /* (6) Configure GMX */

    /* Wait for GMX RX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), rx_idle, ==, 1, 10000))
        return -1;
    /* Wait for GMX TX to be idle */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), tx_idle, ==, 1, 10000))
        return -1;

    /* Wait for receive link */
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_STATUS1(bgx_block, bgx_index), rcv_lnk, ==, 1, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_STATUS2(bgx_block, bgx_index), xmtflt, ==, 0, 10000))
        return -1;
    if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_STATUS2(bgx_block, bgx_index), rcvflt, ==, 0, 10000))
        return -1;

    /* (8) Enable packet reception */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index),
        c.s.gmxeno = 0);

    /* Enable error interrupts */
    // 78xx interrupt mess?
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};
    /* Only setup the PKO MAC on real ports, so only do channel 0 */
    if (priv.s.channel == 0)
    {
        const int MAC_NUMBER = 0x4 + handle->interface * 4 + priv.s.port; /* Constant from cn78xx */
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_MACX_CFG(MAC_NUMBER),
            c.s.fcs_ena = 1; /* FCS */
            c.s.fcs_sop_off = 0; /* No FCS offset */
            c.s.skid_max_cnt = (priv.s.num_port == 4) ? 0 : (priv.s.num_port == 2) ? 1 : 2);
        if (bgx_setup_one_time(handle))
            return -1;
    }

    switch (priv.s.mode)
    {
        case BGX_MODE_SGMII:
        case BGX_MODE_XAUI:
        case BGX_MODE_RXAUI:
        case BGX_MODE_10G:
        case BGX_MODE_40G:
        default:
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

    BDK_CSR_INIT(pcsx_mrx_control_reg, handle->node, BDK_PCSX_MRX_CONTROL_REG(bgx_block, bgx_index));
    if (pcsx_mrx_control_reg.s.loopbck1)
    {
        /* Force 1Gbps full duplex link for internal loopback */
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = speed;
        return result;
    }


    BDK_CSR_INIT(pcsx_miscx_ctl_reg, handle->node, BDK_PCSX_MISCX_CTL_REG(bgx_block, bgx_index));
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
            BDK_CSR_INIT(pcsx_mrx_status_reg, handle->node, BDK_PCSX_MRX_STATUS_REG(bgx_block, bgx_index));
            if (bdk_unlikely(pcsx_mrx_status_reg.s.lnk_st == 0))
            {
                /* Read a second time as the lnk_st bit is sticky */
                pcsx_mrx_status_reg.u64 = BDK_CSR_READ(handle->node, BDK_PCSX_MRX_STATUS_REG(bgx_block, bgx_index));
                if (bdk_unlikely(pcsx_mrx_status_reg.s.lnk_st == 0))
                {
                    if (sgmii_link(handle) != 0)
                        return result;
                }
            }

            /* Read the autoneg results */
            BDK_CSR_INIT(pcsx_anx_results_reg, handle->node, BDK_PCSX_ANX_RESULTS_REG(bgx_block, bgx_index));
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
        result.s.speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm) * 8 / 10;
        result.s.speed *= result.s.lanes;

        BDK_CSR_INIT(misc_ctl, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index));
        if (misc_ctl.s.gmxeno)
            xaui_link(handle);
    }
    else
    {
        /* Disable GMX and PCSX interrupts. */
        // 78xx interrupt mess?
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
};


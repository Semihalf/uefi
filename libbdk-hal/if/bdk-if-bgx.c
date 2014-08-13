#include <bdk.h>
#include <malloc.h>

/* This file implements interfaces connected to the BGX block introduced
    for CN78XX. This block combines SGMII, XAUI, DXAUI, RXAUI, XFI, XLAUI,
    10GBASE-KR, and 40GBASE-KR all into one interface */

#define CQ_ENTRIES_QSIZE 0
#define CQ_ENTRIES (1024 << CQ_ENTRIES_QSIZE)
#define SQ_ENTRIES_QSIZE 0
#define SQ_ENTRIES (1024 << SQ_ENTRIES_QSIZE)
#define RBDR_ENTRIES_QSIZE 0
#define RBDR_ENTRIES (8192 << RBDR_ENTRIES_QSIZE)

typedef enum
{
    BGX_MODE_SGMII, /* 1 lane, 1.250 Gbaud */
    BGX_MODE_XAUI,  /* 4 lanes, 3.125 Gbaud */
    BGX_MODE_DXAUI, /* 4 lanes, 6.250 Gbaud */
    BGX_MODE_RXAUI, /* 2 lanes, 6.250 Gbaud */
    BGX_MODE_XFI,   /* 1 lane, 10.3125 Gbaud */
    BGX_MODE_XLAUI, /* 4 lanes, 10.3125 Gbaud */
    BGX_MODE_10G_KR,/* 1 lane, 10.3125 Gbaud */
    BGX_MODE_40G_KR,/* 4 lanes, 10.3125 Gbaud */
} bgx_mode_t;

typedef union
{
    void *ptr;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        #error Big endian not supported for BGX
#else
        uint64_t    channel         : 8;    /* Which logical channel this handle coresponds to (0-15 for higig, zero otherwise) */
        uint64_t    num_channels    : 12;   /* Total number of channels on this physical port. Only greater than 1 for higig */
        bgx_mode_t  mode            : 4;    /* BGX mode */

        uint64_t    port            : 4;    /* Which physical port this handle connects to */
        uint64_t    num_port        : 4;    /* Number of physical ports on this interface */
        uint64_t    higig           : 1;    /* True if this port is in higig mode */

        uint64_t    use_training    : 1;    /* True if this port is in 10G or 40G and uses training */
        uint64_t    vnic            : 7;    /* NIC index number (0-127) */
        uint64_t    qos             : 3;    /* NIC QoS level (0-7). We only use zero */
        uint64_t    cq              : 7;    /* Which complete queue to use. The second index is always zero */
        uint64_t    rbdr            : 7;    /* Which receive descriptor to use. The second index is always zero */
        uint64_t    reserved_58_63  : 6;
#endif
    } s;
} bgx_priv_t;

/* Table used to convert VNIC numbers to interface handles */
static bdk_if_handle_t global_handle_table[128];

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
    int gbaud_mhz = bdk_qlm_get_gbaud_mhz(node, qlm);

    switch (qlm_mode)
    {
        case BDK_QLM_MODE_SGMII:
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_SGMII;
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_XAUI;
            if (gbaud_mhz == 3125)
                priv.s.mode = BGX_MODE_XAUI;
            else
                priv.s.mode = BGX_MODE_DXAUI;
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            priv.s.num_port = 2;
            priv.s.mode = BGX_MODE_RXAUI;
            break;
        case BDK_QLM_MODE_XFI_4X1:
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_XFI;
            /* XFI doesn't support tx training */
            break;
        case BDK_QLM_MODE_XLAUI_1X4:
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_XLAUI;
            /* XLAUI doesn't support tx training */
            break;
        case BDK_QLM_MODE_10G_KR_4X1:
            priv.s.num_port = 4;
            priv.s.mode = BGX_MODE_10G_KR;
            priv.s.use_training = 1; /* 10GBASE-KR supports tx training */
            break;
        case BDK_QLM_MODE_40G_KR4_1X4:
            priv.s.num_port = 1;
            priv.s.mode = BGX_MODE_40G_KR;
            priv.s.use_training = 1; /* 40GBASE-KR4 supports tx training */
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
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 2;
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

    /* Strip FCS */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMR_GLOBAL_CONFIG(handle->interface),
        c.s.fcs_strip = 1);

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
        case BGX_MODE_DXAUI:
            lmac_type = 1;
            lane_to_sds = 0xe4;
            break;
        case BGX_MODE_RXAUI:
            lmac_type = 2;
            lane_to_sds = (handle->index) ? 0xe : 0x4;
            break;
        case BGX_MODE_XFI:
            lmac_type = 3;
            lane_to_sds = handle->index;
            break;
        case BGX_MODE_XLAUI:
            lmac_type = 4;
            lane_to_sds = 0xe4;
            break;
        case BGX_MODE_10G_KR:
            lmac_type = 3;
            lane_to_sds = handle->index;
            break;
        case BGX_MODE_40G_KR:
            lmac_type = 4;
            lane_to_sds = 0xe4;
            break;
        default:
            return -1;
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
        c.s.msk_and |= ((1ull <<priv.s.num_channels) - 1ull) << (handle->index * 16));

    /* Disable all MAC filtering */
    for (int i = 0; i < 32; i++)
        BDK_CSR_WRITE(handle->node, BDK_BGXX_CMR_RX_DMACX_CAM(handle->interface, i), 0);
    return 0;
}

static int if_probe(bdk_if_handle_t handle)
{
    static int next_free_vnic = 0;

    if (next_free_vnic >= 128)
    {
        bdk_error("Ran out of VNIC interfaces\n");
        return -1;
    }

    if (next_free_vnic == 0)
    {
        /* Must be done before the first vnic */
        memset(global_handle_table, 0, sizeof(global_handle_table));
    }

    bgx_priv_t priv = create_priv(handle->node, handle->interface, handle->index);
    priv.s.vnic = next_free_vnic++;
    handle->priv = priv.ptr;

    /* Change name to be something that might be meaningful to the user */
    const char *name_format = "UNKNOWN";
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
        case BGX_MODE_DXAUI:
            if (bdk_numa_is_only_one())
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "DXAUI%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.DXAUI%d";
            break;
        case BGX_MODE_RXAUI:
            if (bdk_numa_is_only_one())
                name_format = (priv.s.higig) ? "HIGIG%d.%d.%d" : "RXAUI%d.%d";
            else
                name_format = (priv.s.higig) ? "N%d.HIGIG%d.%d.%d" : "N%d.RXAUI%d.%d";
            break;
        case BGX_MODE_XFI:
            if (bdk_numa_is_only_one())
                name_format = "XFI%d.%d";
            else
                name_format = "N%d.XFI%d.%d";
            break;
        case BGX_MODE_XLAUI:
            if (bdk_numa_is_only_one())
                name_format = "XLAUI%d";
            else
                name_format = "N%d.XLAUI%d";
            break;
        case BGX_MODE_10G_KR:
            if (bdk_numa_is_only_one())
                name_format = "10GKR%d.%d";
            else
                name_format = "N%d.10GKR%d.%d";
            break;
        case BGX_MODE_40G_KR:
            if (bdk_numa_is_only_one())
                name_format = "40GKR%d";
            else
                name_format = "N%d.40GKR%d";
            break;
    }
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), name_format, handle->interface, priv.s.port, priv.s.channel);
    else
        snprintf(handle->name, sizeof(handle->name), name_format, handle->node, handle->interface, priv.s.port, priv.s.channel);
    handle->name[sizeof(handle->name)-1] = 0;

    handle->flags |= BDK_IF_FLAGS_HAS_FCS;
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
            link, but a link between the chip and the PHY */
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
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_LINKX_TIMER(bgx_block, bgx_index), pcs_linkx_timer.u);

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
            BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index), pcs_miscx_ctl.u);
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
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(bgx_block, bgx_index), pcsx_miscx_ctl_reg.u);

    /* Write the new GMX settings with the port still disabled */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_PRTX_CFG(bgx_block, bgx_index), prtx_cfg.u);

    /* Restore the enabled / disabled state */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
        c.s.enable = is_enabled);
    return 0;
}

/**
 * Setup auto neg on a port. Called one at init for each port
 *
 * @param handle Port to configure
 *
 * @return Zero no success, negative on failure
 */
static int setup_auto_neg(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};

    /* 10GBASE-KR and 40GBASE-KR4 optionally support auto negotiation. Note
       that this referse to auto negotiation for links other than SGMII. SGMII
       takes a different code path */
    int use_auto_neg = (priv.s.mode == BGX_MODE_10G_KR) || (priv.s.mode == BGX_MODE_40G_KR);
    // FIXME: Disabled as it currently doesn't work
    use_auto_neg = 0;

    /* Software should do the following to execute Auto-Negotiation when
       desired: */
    /* 1. Set BGX(0..5)_SPU(0..3)_AN_CONTROL[AN_EN] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_AN_CONTROL(bgx_block, bgx_index),
        c.s.xnp_en=0; /* Disable extended next pages */
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
        c.s.a40g_cr4 = 0;
        c.s.a40g_kr4 = (priv.s.mode == BGX_MODE_40G_KR);
        c.s.a10g_kr = (priv.s.mode == BGX_MODE_10G_KR);
        c.s.a10g_kx4 = 0;
        c.s.a1g_kx = 0;
        c.s.xnp_able = 0;
        c.s.rf = 0);

    /* 3. Set BGX(0..5)_SPU_DBG_CONTROL[AN_ARB_LINK_CHK_EN] = 1. */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPU_DBG_CONTROL(bgx_block),
        c.s.an_nonce_match_dis=1; /* Needed for loopback */
        c.s.an_arb_link_chk_en = use_auto_neg);

    /* 4. Execute the link bring-up sequence in Section 33.6.3. */
    /* Done after this function is called */

    /* 5. If the auto-negotiation protocol is successful,
       BGX(0..5)_SPU(0..3)_AN_ADV[AN_COMPLETE] is set along with
       BGX(0..5)_SPU(0..3)_INT[AN_COMPLETE] when the link is up. */
    /* Done after this function is called */
    return 0;
}

/**
 * Port intialization for all protocols except for SGMII. Its
 * call xaui_init() for the lack of a better name, but it
 * applies to everything other than SGMII.
 *
 * @param handle Handle to the port
 *
 * @return Zero on success, negative on failure
 */
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
        /* These registers aren't cleared when training is restarted. Manually
           clear them */
        BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LP_CUP(bgx_block, bgx_index), 0);
        BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LD_CUP(bgx_block, bgx_index), 0);
        BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LD_REP(bgx_block, bgx_index), 0);
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, bgx_index),
            c.s.train_en = 1);
    }

    /* 3e. Program all other relevant BGX configuration while
       BGX(0..5)_CMR(0..3)_CONFIG[ENABLE] = 0. This includes all things
       described in this chapter. */

    /* 3f. If Forward Error Correction is desired for 10GBASE-R or 40GBASE-R,
       enable it by writing BGX(0..5)_SPU(0..3)_FEC_CONTROL[FEC_EN] = 1.
       BDK:
        FEC is optional for 10GBASE-KR, 40GBASE-KR4, and XLAUI. We're going
        to disable it by default per recommendation from Scott Meninger */
    int use_fec = 0;
    use_fec &= ((priv.s.mode == BGX_MODE_10G_KR) ||
                (priv.s.mode == BGX_MODE_40G_KR) ||
                (priv.s.mode == BGX_MODE_XLAUI));
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_FEC_CONTROL(bgx_block, bgx_index),
        c.s.fec_en = use_fec);

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

    return 0;
}

/**
 * Restart training after traiing fails
 *
 * @param handle Port to restart
 */
static void restart_training(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    BDK_CSR_DEFINE(spux_int, BDK_BGXX_SPUX_INT(bgx_block, bgx_index));
    /* Clear the training interrupts (W1C) */
    spux_int.u = 0;
    spux_int.s.training_failure = 1;
    spux_int.s.training_done = 1;
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index), spux_int.u);
    /* These registers aren't cleared when training is restarted. Manually
       clear them */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LP_CUP(bgx_block, bgx_index), 0);
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LD_CUP(bgx_block, bgx_index), 0);
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_BR_PMD_LD_REP(bgx_block, bgx_index), 0);
    /* Restart training */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, bgx_index),
        c.s.train_restart = 1);
}

/**
 * Link up/down processing for all protocols except for SGMII. Its call
 * xaui_link() for the lack of a better name, but it applies to
 * everything other than SGMII.
 *
 * @param handle Handle to the port
 *
 * @return Zero on success, negative on failure
 */
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
        /* Check if we're using auto negotiation */
        BDK_CSR_INIT(spux_an_control, handle->node, BDK_BGXX_SPUX_AN_CONTROL(bgx_block, bgx_index));
        if (spux_an_control.s.an_en)
        {
            BDK_CSR_INIT(spux_int, handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index));
            if (!spux_int.s.an_link_good)
            {
                /* Clear the auto negotiation (W1C) */
                spux_int.u = 0;
                spux_int.s.an_complete = 1;
                spux_int.s.an_link_good = 1;
                spux_int.s.an_page_rx = 1;
                BDK_CSR_WRITE(handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index), spux_int.u);
                /* Restart auto negotiation */
                BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_AN_CONTROL(bgx_block, bgx_index),
                    c.s.an_restart = 1);
                BDK_TRACE("%s: Restarting auto negotiation\n", handle->name);
                return -1;
            }
        }

        if (priv.s.use_training)
        {
            /* Check if training is done */
            BDK_CSR_INIT(spux_int, handle->node, BDK_BGXX_SPUX_INT(bgx_block, bgx_index));
            if (spux_int.s.training_failure)
            {
                restart_training(handle);
                BDK_TRACE("%s: Restarting link training\n", handle->name);
                return -1;
            }
            if (!spux_int.s.training_done)
            {
                BDK_TRACE("%s: Waiting for link training\n", handle->name);
                return -1;
            }
        }
        /* Wait for PCS to come out of reset */
        if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_CONTROL1(bgx_block, bgx_index), reset, ==, 0, TIMEOUT))
        {
            BDK_TRACE("%s: PCS in reset\n", handle->name);
            return -1;
        }

        if ((priv.s.mode == BGX_MODE_XFI) || (priv.s.mode == BGX_MODE_XLAUI) ||
            (priv.s.mode == BGX_MODE_10G_KR) || (priv.s.mode == BGX_MODE_40G_KR))
        {
            /* 10G-R/40G-R - Wait for BASE-R PCS block lock */
            if (BDK_CSR_WAIT_FOR_FIELD(handle->node, BDK_BGXX_SPUX_BR_STATUS1(bgx_block, bgx_index), blk_lock, ==, 1, TIMEOUT))
            {
                BDK_TRACE("%s: BASE-R PCS block not locked\n", handle->name);
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
                restart_training(handle);
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

static int vnic_setup_cq(bdk_if_handle_t handle)
{
    static int next_free_cq = 0;
    bgx_priv_t priv = {.ptr = handle->priv};
    int cq;
    int cq_idx = 0;

    /* Allocate a new CQ for every interface. All ports and channels on
       the same interface use same CQ */
    if ((handle->index > 0) || (priv.s.channel > 0))
    {
        /* These are allocated linearly. We know that the first port was
           the last guy to allcoate a CQ */
        cq = next_free_cq - 1;
    }
    else
    {
        if (next_free_cq >= 128)
        {
            bdk_error("%s: No free completion queues\n", handle->name);
            return -1;
        }
        /* Note that the completion queue requires 512 byte alignment */
        void *cq_memory = memalign(512, 512 * CQ_ENTRIES);
        if (!cq_memory)
        {
            bdk_error("%s: Failed to allocate memory for completion queue\n", handle->name);
            return -1;
        }
        cq = next_free_cq++;
        /* Configure the completion queue (CQ) */
        BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_CQX_BASE(cq, cq_idx),
            bdk_ptr_to_phys(cq_memory));
        BDK_CSR_MODIFY(c, handle->node, BDK_NIC_QSX_CQX_CFG(cq, cq_idx),
            c.s.ena = 1;
            c.s.caching = 1;
            c.s.qsize = CQ_ENTRIES_QSIZE);
    }

    /* Configure our vnic to send to the CQ */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_SQX_CFG(priv.s.vnic, priv.s.qos),
        c.s.cq_qs = cq;
        c.s.cq_idx = cq_idx);

    priv.s.cq = cq;
    handle->priv = priv.ptr;

    return 0;
}

static void vnic_fill_receive_buffer(bdk_if_handle_t handle, int rbdr_free)
{
    const int buffer_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);
    bgx_priv_t priv = {.ptr = handle->priv};
    int rbdr = priv.s.rbdr;
    int rbdr_idx = 0;

    BDK_CSR_INIT(rbdr_head, handle->node, BDK_NIC_QSX_RBDRX_BASE(rbdr, rbdr_idx));
    BDK_CSR_INIT(rbdr_tail, handle->node, BDK_NIC_QSX_RBDRX_TAIL(rbdr, rbdr_idx));

    uint64_t *rbdr_ptr = bdk_phys_to_ptr(rbdr_head.u);
    int loc = rbdr_tail.s.tail_ptr;

    int added = 0;
    for (int i = 0; i < rbdr_free; i++)
    {
        bdk_if_packet_t packet;
        if (bdk_if_alloc(&packet, buffer_size))
        {
            bdk_error("%s: Failed to allocate buffer for RX ring (added %d)\n", handle->name, added);
            break;
        }
        rbdr_ptr[loc] = packet.packet[0].s.address;
        loc++;
        loc &= RBDR_ENTRIES - 1;
        added++;
    }
    BDK_WMB;
    BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_RBDRX_DOOR(rbdr, rbdr_idx), added);
}

static int vnic_setup_rbdr(bdk_if_handle_t handle)
{
    static int next_free_rbdr = 0;
    bgx_priv_t priv = {.ptr = handle->priv};
    int rbdr;
    int rbdr_idx = 0;
    int do_fill;

    /* Allocate a new RBDR for every interface. All ports and channels on
       the same interface use same RBDR */
    if ((handle->index > 0) || (priv.s.channel > 0))
    {
        /* These are allocated linearly. We know that the first port was
           the last guy to allcoate a CQ */
        rbdr = next_free_rbdr - 1;
        do_fill = 0;
    }
    else
    {
        if (next_free_rbdr >= 128)
        {
            bdk_error("%s: No free receive buffer descriptor rings\n", handle->name);
            return -1;
        }
        void *rbdr_memory = memalign(128, 8 * RBDR_ENTRIES);
        if (!rbdr_memory)
        {
            bdk_error("%s: Failed to allocate memory for RBDR\n", handle->name);
            return -1;
        }
        rbdr = next_free_rbdr++;

        /* Configure the receive buffer ring (RBDR) */
        BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_RBDRX_BASE(rbdr, rbdr_idx),
            bdk_ptr_to_phys(rbdr_memory));
        const int buffer_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);
        BDK_CSR_MODIFY(c, handle->node, BDK_NIC_QSX_RBDRX_CFG(rbdr, rbdr_idx),
            c.s.ena = 1;
            c.s.ldwb = BDK_USE_DWB;
            c.s.qsize = RBDR_ENTRIES_QSIZE;
            c.s.lines = buffer_size / 128);
        do_fill = 1;
    }

    /* Configure our vnic to use the RBDR */
    /* Connect this RQ to the RBDR */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_RQX_CFG(priv.s.vnic, priv.s.qos),
        c.s.caching = 1;
        c.s.cq_qs = priv.s.cq;
        c.s.cq_idx = 0;
        c.s.rbdr_cont_qs = rbdr;
        c.s.rbdr_cont_idx = rbdr_idx;
        c.s.rbdr_strt_qs = rbdr;
        c.s.rbdr_strt_idx = rbdr_idx);
    /* Backpressure when either CQ or RBDR is 250/256 full */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_RQX_BP_CFG(priv.s.vnic, priv.s.qos),
        c.s.rbdr_bp_ena = 1;
        c.s.cq_bp_ena = 1;
        c.s.rbdr_bp = 250;
        c.s.cq_bp = 250;
        c.s.bpid = priv.s.vnic);
    /* RED drop when either CQ or RBDR is 253/256 full, drop everything at
       254/256 */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_RQX_DROP_CFG(priv.s.vnic, priv.s.qos),
        c.s.rbdr_red = 1;
        c.s.cq_red = 1;
        c.s.rbdr_pass = 253;
        c.s.rbdr_drop = 254;
        c.s.cq_pass = 253;
        c.s.cq_drop = 254);

    priv.s.rbdr = rbdr;
    handle->priv = priv.ptr;

    if (do_fill)
    {
        /* We probably don't have enough space to completely fill the RBDR. Use
           1/3 of the buffers available. We expect to only have 2 RBDR rings */
        int fill_num = bdk_config_get(BDK_CONFIG_NUM_PACKET_BUFFERS) / 3;
        if (fill_num > RBDR_ENTRIES)
            fill_num = RBDR_ENTRIES;
        vnic_fill_receive_buffer(handle, fill_num);
    }

    return 0;
}

static int vnic_setup_tx_shaping(bdk_if_handle_t handle)
{
    /* Setup traffic shaping. The BDK disables traffic-shaping, but we still
       have to assign the various TL* resourses */
    bgx_priv_t priv = {.ptr = handle->priv};

    /* TL1 feeds the DMA engines. One for each BGX */
    int tl1_index = handle->interface;

    /* TL2 feeds TL1 based on the top/bottom half. Use an independent TL1
       entry for each BGX port */
    int tl2_index = tl1_index * 32;
    tl2_index += priv.s.port;
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL2X_CFG(tl2_index),
        c.s.rr_quantum = tl2_index * 8);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL2X_PRI(tl2_index),
        c.s.rr_pri = 0);

    /* TL3 feeds Tl2. We only need one entry */
    int tl3_index = tl2_index * 4;
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL3AX_CFG(tl3_index / 4),
        c.s.tl3a = tl2_index);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL3X_CFG(tl3_index),
        c.s.rr_quantum = tl3_index * 8);
    int tl_channel = (handle->interface) ? NIC_CHAN_E_BGX1_PORT0_CH0 : NIC_CHAN_E_BGX0_PORT0_CH0;
    tl_channel += (NIC_CHAN_E_BGX0_PORT1_CH0 - NIC_CHAN_E_BGX0_PORT0_CH0) * priv.s.port;
    tl_channel += priv.s.channel;
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL3X_CHAN(tl3_index),
        c.s.chan = tl_channel);

    /* TL4 feeds TL3. We only need one entry */
    int tl4_index = tl3_index * 4;
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL4AX_CFG(tl4_index / 4),
        c.s.tl4a = tl3_index);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_TL4X_CFG(tl4_index),
        c.s.sq_qs = priv.s.vnic;
        c.s.sq_idx = priv.s.qos;
        c.s.rr_quantum = tl4_index * 8);

    /* SQ feeds TL4 */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_SQX_CFG2(priv.s.vnic, priv.s.qos),
        c.s.tl4 = tl4_index);

    return 0;
}

static int vnic_setup(bdk_if_handle_t handle)
{
    static int next_free_cpi = 0;
    static int next_free_rssi = 0;

    bgx_priv_t priv = {.ptr = handle->priv};

    void *sq_memory = memalign(128, 16 * SQ_ENTRIES);
    if (!sq_memory)
    {
        bdk_error("%s: Unable to allocate queues\n", handle->name);
        return -1;
    }

    if (vnic_setup_cq(handle))
        return -1;
    if (vnic_setup_rbdr(handle))
        return -1;

    int sq = priv.s.vnic;
    int sq_idx = priv.s.qos;
    int rq = priv.s.vnic;
    int rq_idx = priv.s.qos;

    /* Configure the submit queue (SQ) */
    BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_SQX_BASE(sq, sq_idx),
        bdk_ptr_to_phys(sq_memory));
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_QSX_SQX_CFG(sq, sq_idx),
        c.s.ena = 1;
        c.s.ldwb = BDK_USE_DWB;
        c.s.qsize = SQ_ENTRIES_QSIZE);

    /* Configure the receive queue (RQ) */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_QSX_RQ_GEN_CFG(rq),
        c.s.vlan_strip = 0;
        c.s.len_l4 = 0;
        c.s.len_l3 = 0;
        c.s.csum_sctp = 0;
        c.s.csum_l4 = 0;
        c.s.ip6_udp_opt = 0;
        c.s.splt_hdr_ena = 0;
        c.s.cq_hdr_copy = 0;
        c.s.max_tcp_reass = 0;
        c.s.cq_pkt_size = 0;
        c.s.later_skip = 0;
        c.s.first_skip = 0);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_QSX_RQX_CFG(rq, rq_idx),
        c.s.ena = 1;
        c.s.tcp_ena = 0);
    /* Determine the flow channel for the CPI */
    int flow = (handle->interface) ? 0x80 : 0x00;
    flow += priv.s.port * 16;
    flow += priv.s.channel;
    int cpi = next_free_cpi++;
    int rssi = next_free_rssi++;
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_CHANX_RX_CFG(flow),
        c.s.cpi_alg = NIC_CPI_ALG_E_NONE;
        c.s.cpi_base = cpi);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_CPIX_CFG(cpi),
        c.s.vnic = priv.s.vnic;
        c.s.rss_size = 0;
        c.s.padd = priv.s.channel;
        c.s.rssi_base = rssi);
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_RSSIX_RQ(rssi),
        c.s.rq_qs = rq;
        c.s.rq_idx = rq_idx);
    /* Set the min and max packet size */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_PKINDX_CFG(handle->pknd),
        c.s.lenerr_en = 0;
        c.s.minlen = 0);

    /* Bypass the TNS */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_INTFX_SEND_CFG(handle->interface),
       c.s.tns_nonbypass = 0;
       c.s.block = 0x8 + handle->interface);

    /* Do global vnic init */
    BDK_CSR_MODIFY(c, handle->node, BDK_NIC_PF_QSX_CFG(priv.s.vnic),
        c.s.ena = 1;
        c.s.vnic = priv.s.vnic);

    if (vnic_setup_tx_shaping(handle))
        return -1;

    global_handle_table[priv.s.vnic] = handle;

    if (0)
    {
        /* Update my private state copy after all fields are filled in */
        priv.ptr = handle->priv;
        printf("%s: channel %d of %d, port %d of %d, vnic(%d,%d), cq=%d, rbdr=%d\n",
            handle->name, priv.s.channel, priv.s.num_channels,
            priv.s.port, priv.s.num_port, priv.s.vnic, priv.s.qos,
            priv.s.cq, priv.s.rbdr);
    }

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bgx_priv_t priv = {.ptr = handle->priv};
    if (bgx_setup_one_time(handle))
        return -1;

    if (priv.s.mode != BGX_MODE_SGMII)
    {
        /* Everything other than SGMII */
        xaui_init(handle);
    }

    /* Set BGX to buffer half its FIFO before starting transmit. This reduces
       the chances that we have a TX under run due to memory contention */
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_GMI_TXX_THRESH(bgx_block, bgx_index),
        c.s.cnt = (0x800 / 2 / priv.s.num_port) - 1);
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SMUX_TX_THRESH(bgx_block, bgx_index),
        c.s.cnt = (0x800 / 2 / priv.s.num_port) - 1);

    /* Configure to allow max sized frames */
    const int buffer_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);
    int max_size = buffer_size * 12; /* 12 is from nic_cqe_rx_s */
    BDK_CSR_WRITE(handle->node, BDK_BGXX_GMP_GMI_RXX_JABBER(bgx_block, bgx_index), max_size);
    BDK_CSR_WRITE(handle->node, BDK_BGXX_SMUX_RX_JABBER(bgx_block, bgx_index), max_size);

    /* Disable frame alignment if using preamble. This allows the link to
        reach full rate for odd length packets. For example, without this
        SGMII is slower than RGMII for 65 byte packets */
    BDK_CSR_INIT(txx_append, handle->node, BDK_BGXX_GMP_GMI_TXX_APPEND(bgx_block, bgx_index));
    BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_GMI_TXX_SGMII_CTL(bgx_block, bgx_index),
        c.s.align = !txx_append.s.preamble);

    return vnic_setup(handle);
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
                gmp_pcs_mrx_status.u = BDK_CSR_READ(handle->node, BDK_BGXX_GMP_PCS_MRX_STATUS(bgx_block, bgx_index));
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

/**
 * Get link status of ports in modes other than SGMII
 *
 * @param handle Port to query
 *
 * @return Port speed structure
 */
static bdk_if_link_t if_link_get_xaui(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    const int bgx_block = handle->interface;
    const int bgx_index = handle->index;
    bdk_if_link_t result;
    result.u64 = 0;

    int link_up;
    if (bdk_is_simulation())
    {
        link_up = 1;
    }
    else
    {
        BDK_CSR_INIT(status1, handle->node, BDK_BGXX_SPUX_STATUS1(bgx_block, bgx_index));
        link_up = status1.s.rcv_lnk;
    }

    if (link_up)
    {
        int qlm = bdk_qlm_get(handle->node, BDK_IF_BGX, handle->interface);
        result.s.lanes = 4 / priv.s.num_port;
        result.s.up = 1;
        result.s.full_duplex = 1;
        uint64_t speed = bdk_qlm_get_gbaud_mhz(handle->node, qlm);
        switch (priv.s.mode)
        {
            case BGX_MODE_XFI:
            case BGX_MODE_XLAUI:
            case BGX_MODE_10G_KR:
            case BGX_MODE_40G_KR:
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

    if (priv.s.mode == BGX_MODE_SGMII)
        result = if_link_get_sgmii(handle);
    else
        result = if_link_get_xaui(handle);
    return result;
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    if (priv.s.mode == BGX_MODE_SGMII)
    {
        int status = sgmii_link(handle);
        if (status == 0)
            sgmii_speed(handle, link_info);
    }
    else
        xaui_link(handle);
}


static int if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    bgx_priv_t priv = {.ptr = handle->priv};

    /* Check for space. A max sized packet will take one header and 16 gather
       entries */
    BDK_CSR_INIT(sq_status, handle->node, BDK_NIC_QSX_SQX_STATUS(priv.s.vnic, priv.s.qos));
    if (bdk_unlikely(sq_status.s.qcount >= SQ_ENTRIES - 17))
        return -1;

    /* Build the command */
    BDK_CSR_INIT(sq_base, handle->node, BDK_NIC_QSX_SQX_BASE(priv.s.vnic, priv.s.qos));
    BDK_CSR_INIT(sq_tail, handle->node, BDK_NIC_QSX_SQX_TAIL(priv.s.vnic, priv.s.qos));
    void *sq_ptr = bdk_phys_to_ptr(sq_base.u);
    int loc = sq_tail.s.tail_ptr;
    union nic_send_hdr_s send_hdr;
    send_hdr.u[0] = 0;
    send_hdr.u[1] = 0;
    send_hdr.s.subdc = NIC_SEND_SUBDC_E_HDR;
    send_hdr.s.subdcnt = packet->segments;
    send_hdr.s.total = packet->length;
    *(union nic_send_hdr_s *)(sq_ptr + loc * 16) = send_hdr;
    loc++;
    loc &= SQ_ENTRIES - 1;
    for (int s = 0; s < packet->segments; s++)
    {
        union nic_send_gather_s gather;
        gather.u[0] = 0;
        gather.u[1] = 0;
        gather.s.addr = packet->packet[s].s.address;
        gather.s.subdc = NIC_SEND_SUBDC_E_GATHER;
        gather.s.ld_type = (BDK_USE_DWB) ? NIC_SEND_LD_TYPE_E_LDWB : NIC_SEND_LD_TYPE_E_LDD;
        gather.s.size = packet->packet[s].s.size;
        *(union nic_send_gather_s *)(sq_ptr + loc * 16) = gather;
        loc++;
        loc &= SQ_ENTRIES - 1;
    }

    BDK_WMB;

    /* Ring the doorbell */
    BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_SQX_DOOR(priv.s.vnic, priv.s.qos),
        packet->segments + 1);
    return 0;
}

static int if_process_complete_rx(const union nic_cqe_rx_s *cq_header, bdk_if_packet_t *packet)
{
    int vnic = cq_header->s.rq_qs;
    int rbdr_free = cq_header->s.rb_cnt;

    packet->length = cq_header->s.len;
    packet->segments = rbdr_free;
    packet->if_handle = global_handle_table[vnic];
    packet->rx_error = cq_header->s.errop || cq_header->s.errlev;

    const uint16_t *rb_sizes = (void*)cq_header + 24; /* Offset of RBSZ0 */
    const uint64_t *rb_addresses = (uint64_t*)(cq_header+1);

    for (int s = 0; s < packet->segments; s++)
    {
        packet->packet[s].u = rb_addresses[s];
        packet->packet[s].s.size = rb_sizes[s];
    }

    if (bdk_likely(packet->if_handle))
    {
        //printf("RQ_QS %d mapped to %s\n", vnic, packet->if_handle->name);
        bdk_if_dispatch_packet(packet);
    }
    else
        bdk_error("Unable to determine interface for VNIC %d\n", vnic);

    return rbdr_free;
}

static int if_receive(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    if (!bdk_is_boot_core())
        return -1;

    /* Figure out which completion queue we're using */
    bgx_priv_t priv = { .ptr = handle->priv };
    int cq = priv.s.cq;
    int cq_idx = 0;

    /* Exit immediately if the CQ is empty */
    BDK_CSR_INIT(cq_status, handle->node, BDK_NIC_QSX_CQX_STATUS(cq, cq_idx));
    int pending_count = cq_status.s.qcount;
    if (bdk_likely(!pending_count))
        return -1;

    /* Find the current CQ location */
    BDK_CSR_INIT(cq_base, handle->node, BDK_NIC_QSX_CQX_BASE(cq, cq_idx));
    BDK_CSR_INIT(cq_head, handle->node, BDK_NIC_QSX_CQX_HEAD(cq, cq_idx));
    int loc = cq_head.s.head_ptr;
    const void *cq_ptr = bdk_phys_to_ptr(cq_base.u);

    /* Loop through all pending CQs */
    int count = 0;
    int rbdr_free = 0;
    while (count < pending_count)
    {
        const union nic_cqe_rx_s *cq_header = cq_ptr + loc * 512;
        if (bdk_likely(cq_header->s.cqe_type == NIC_CQE_TYPE_E_RX))
            rbdr_free += if_process_complete_rx(cq_header, packet);
        else
            bdk_error("Unsupported CQ header type %d\n", cq_header->s.cqe_type);
        count++;
        loc++;
        loc &= CQ_ENTRIES - 1;
    }
    /* Free all the CQs that we've processed */
    BDK_CSR_WRITE(handle->node, BDK_NIC_QSX_CQX_DOOR(cq, cq_idx), count);

    /* Refil the receive buffers for all the packets that were extracted */
    vnic_fill_receive_buffer(handle, rbdr_free);

    /* We call dispatch directly, so this function never returns a packet */
    return -1;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    bgx_priv_t priv = {.ptr = handle->priv};

    if (priv.s.mode == BGX_MODE_SGMII)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MRX_CONTROL(handle->interface, priv.s.port),
            c.s.loopbck1 = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_GMP_PCS_MISCX_CTL(handle->interface, priv.s.port),
            c.s.loopbck2 = ((loopback & BDK_IF_LOOPBACK_EXTERNAL) != 0));
        sgmii_link(handle);
    }
    else
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_BGXX_SPUX_CONTROL1(handle->interface, priv.s.port),
            c.s.loopbck = ((loopback & BDK_IF_LOOPBACK_INTERNAL) != 0));
        if (loopback & BDK_IF_LOOPBACK_EXTERNAL)
        {
            /* FIXME: What about SPU external loopback? */
            bdk_error("%s: External loopback not implemented\n", handle->name);
        }
        xaui_link(handle);
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

    /* Read the RX statistics. These do not include the ethernet FCS */
    BDK_CSR_INIT(rx_octets, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_OCTS));
    BDK_CSR_INIT(rx_bcast, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_BCAST));
    BDK_CSR_INIT(rx_mcast, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_MCAST));
    BDK_CSR_INIT(rx_ucast, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_UCAST));
    BDK_CSR_INIT(rx_red, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_RED));
    BDK_CSR_INIT(rx_red_octets, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_RED_OCTS));
    BDK_CSR_INIT(rx_fcs, handle->node, BDK_NIC_VNICX_RX_STATX(priv.s.vnic, NIC_STAT_VNIC_RX_E_RX_FCS));

    /* Update the RX stats */
    // FIXME: Adding the rx packets together will make incorrect results on overflow
    uint64_t rx_packets = rx_bcast.u + rx_mcast.u + rx_ucast.u;
    handle->stats.rx.octets -= handle->stats.rx.packets * 4;
    handle->stats.rx.octets = bdk_update_stat_with_overflow(rx_octets.u,
        handle->stats.rx.octets, 48);
    handle->stats.rx.packets = bdk_update_stat_with_overflow(rx_packets,
        handle->stats.rx.packets, 48);
    handle->stats.rx.octets += handle->stats.rx.packets * 4;

    /* Drop and error counters */
    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * 4;
    handle->stats.rx.dropped_octets = bdk_update_stat_with_overflow(
        rx_red_octets.u, handle->stats.rx.dropped_octets, 48);
    handle->stats.rx.dropped_packets = bdk_update_stat_with_overflow(
        rx_red.u, handle->stats.rx.dropped_packets, 48);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * 4;
    handle->stats.rx.errors = bdk_update_stat_with_overflow(
        rx_fcs.u, handle->stats.rx.errors, 48);

    /* Read the TX statistics. These don't include the ethernet FCS */
    BDK_CSR_INIT(tx_octets, handle->node, BDK_NIC_VNICX_TX_STATX(priv.s.vnic, NIC_STAT_VNIC_TX_E_TX_OCTS));
    BDK_CSR_INIT(tx_packets, handle->node, BDK_NIC_VNICX_TX_STATX(priv.s.vnic, NIC_STAT_VNIC_TX_E_TX_UCAST));

    /* Update the TX stats */
    handle->stats.tx.octets -= handle->stats.tx.packets * 4;
    handle->stats.tx.octets = bdk_update_stat_with_overflow(tx_octets.u, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = bdk_update_stat_with_overflow(tx_packets.u, handle->stats.tx.packets, 48);
    handle->stats.tx.octets += handle->stats.tx.packets * 4;

    return &handle->stats;
}

static int if_get_queue_depth(bdk_if_handle_t handle)
{
    bgx_priv_t priv = {.ptr = handle->priv};
    BDK_CSR_INIT(sq_status, handle->node, BDK_NIC_QSX_SQX_STATUS(priv.s.vnic, priv.s.qos));
    return sq_status.s.qcount;
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
    .if_transmit = if_transmit,
    .if_receive = if_receive,
    .if_loopback = if_loopback,
    .if_get_queue_depth = if_get_queue_depth,
    .if_get_stats = if_get_stats,
};


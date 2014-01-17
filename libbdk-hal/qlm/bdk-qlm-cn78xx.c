#include <bdk.h>
#include <stdio.h>

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 14; /* 8 QLM + 6 OCI */
}

/**
 * Lookup the hardware QLM number for a given interface type and index. This
 * function will fail with a fatal error if called on invalid interfaces for
 * a chip. It returns the QLM number for an interface without checking to
 * see if the QLM is in hte correct mode.
 *
 * @param iftype    Interface type
 * @param interface Interface index number
 *
 * @return QLM number. Dies on a fatal error on failure.
 */
static int qlm_get_qlm_num(bdk_node_t node, bdk_if_t iftype, int interface)
{
    switch (iftype)
    {
        case BDK_IF_ILK:
            if (interface < 2)
            {
                for (int qlm = 4; qlm < 8; qlm++)
                {
                    /* Make sure the QLM is powered up and out of reset */
                    BDK_CSR_INIT(phy_ctl, node, BDK_GSERX_PHY_CTL(qlm));
                    if (phy_ctl.s.phy_pd || phy_ctl.s.phy_reset)
                        continue;
                    /* Make sure the QLM is in ILK mode */
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
                    if (gserx_cfg.s.ila)
                        return qlm;
                }
            }
            return -1;
        case BDK_IF_BGX:
        {
            int qlm;
            /* Figure out which QLM the BGX connects to */
            if (interface < 2)
            {
                BDK_CSR_INIT(gconf, node, BDK_BGXX_CMR_GLOBAL_CONFIG(interface));
                if (gconf.s.pmux_sds_sel)
                    qlm = interface  + 2; /* QLM 2 or 3 */
                else
                    qlm = interface; /* QLM 0 or 1 */
            }
            else
                qlm = interface + 2; /* QLM 4-7 */
            /* Make sure the QLM is powered up and out of reset */
            BDK_CSR_INIT(phy_ctl, node, BDK_GSERX_PHY_CTL(qlm));
            if (phy_ctl.s.phy_pd || phy_ctl.s.phy_reset)
                return -1;
            /* Make sure the QLM is in BGX mode */
            BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
            if (gserx_cfg.s.bgx)
                return qlm;
            else
                return -1;
        }
        default:
            return -1;
    }
}

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
static int qlm_get_lanes(bdk_node_t node, int qlm)
{
    return 4; /* All are 4 lanes each */
}


/**
 * Get the mode of a QLM as a human readable string
 *
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
static bdk_qlm_modes_t qlm_get_mode(bdk_node_t node, int qlm)
{
    if (qlm < 8)
    {
        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
        if (gserx_cfg.s.pcie)
            return BDK_QLM_MODE_PCIE_1X4;
        else if (gserx_cfg.s.ila)
            return BDK_QLM_MODE_ILK;
        else if (gserx_cfg.s.bgx)
        {
            BDK_CSR_INIT(lane_mode, node, BDK_GSERX_LANE_MODE(qlm));
            switch (lane_mode.s.lmode)
            {
                case 0x0: /* R_25G_REFCLK100 */
                case 0x1: /* R_5G_REFCLK100 */
                case 0x2: /* R_8G_REFCLK100 */
                    return BDK_QLM_MODE_DISABLED;
                case 0x3: /* R_125G_REFCLK15625_KX */
                    return BDK_QLM_MODE_DISABLED;
                case 0x4: /* R_3125G_REFCLK15625_XAUI */
                    return BDK_QLM_MODE_XAUI_1X4;
                case 0x5: /* R_103215G_REFCLK15625_KR */
                    if (gserx_cfg.s.bgx_quad)
                        return BDK_QLM_MODE_40GR4_1X4;
                    else
                        return BDK_QLM_MODE_10GR_4X1;
                case 0x6: /* R_125G_REFCLK15625_SGMII */
                    return BDK_QLM_MODE_SGMII;
                case 0x7: /* R_5G_REFCLK15625_QSGMII */
                    return BDK_QLM_MODE_DISABLED;
                case 0x8: /* R_625G_REFCLK15625_RXAUI */
                    return BDK_QLM_MODE_RXAUI_2X2;
                case 0x9: /* R_25G_REFCLK125 */
                case 0xa: /* R_5G_REFCLK125 */
                case 0xb: /* R_8G_REFCLK125 */
                    return BDK_QLM_MODE_DISABLED;
                default:
                    return BDK_QLM_MODE_DISABLED;
            }
        }
        else
            return BDK_QLM_MODE_DISABLED;
    }
    else
        return BDK_QLM_MODE_OCI;
}


/**
 * For chips that don't use pin strapping, this function programs
 * the QLM to the specified mode
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param mode     Desired mode
 * @param baud_mhz Desired speed
 * @param flags    Flags to specify mode specific options
 *
 * @return Zero on success, negative on failure
 */
static int qlm_set_mode(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags)
{
    int lane_mode = 0xf;
    int is_pcie = 0;
    int is_ilk = 0;
    int is_bgx = 0;

    switch (mode)
    {
        case BDK_QLM_MODE_PCIE_1X4:
        case BDK_QLM_MODE_PCIE_1X8:
            is_pcie = 1;
            // FIXME: PCIe assuming 100Mhz ref
            if (flags & BDK_QLM_MODE_FLAG_GEN1)
                lane_mode = 0; /* R_25G_REFCLK100 */
            else if (flags & BDK_QLM_MODE_FLAG_GEN2)
                lane_mode = 1; /* R_5G_REFCLK100 */
            else
                lane_mode = 2; /* R_8G_REFCLK100 */
            break;
        case BDK_QLM_MODE_ILK:
            is_ilk = 1;
            lane_mode = 1; // FIXME: ILK lane mode
            break;
        case BDK_QLM_MODE_SGMII:
            is_bgx = 1;
            lane_mode = 6; /* R_125G_REFCLK15625_SGMII */
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            is_bgx = 7;
            lane_mode = 4; /* R_3125G_REFCLK15625_XAUI */
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            is_bgx = 3;
            lane_mode = 8; /* R_625G_REFCLK15625_RXAUI */
            break;
        case BDK_QLM_MODE_10GR_4X1:
            is_bgx = 1;
            lane_mode = 5; /* R_103215G_REFCLK15625_KR */
            break;
        case BDK_QLM_MODE_40GR4_1X4:
            is_bgx = 7;
            lane_mode = 5; /* R_103215G_REFCLK15625_KR */
            break;
        default:
            /* Unknown, do nothing */
            break;
    }

    /* Power up phy, but keep it in reset */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_pd = 0;
        c.s.phy_reset = 1);

    /* Set gser for the interface mode */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(qlm),
        c.s.ila = is_ilk;
        c.s.bgx = is_bgx & 1;
        c.s.bgx_quad = (is_bgx >> 2) & 1;
        c.s.bgx_dual = (is_bgx >> 1) & 1;
        c.s.pcie = is_pcie);

    /* Lane mode */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_MODE(qlm),
        c.s.lmode = lane_mode);

    /* Bring phy out of reset */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 0);

    /* Wait 250 ns until the managment interface is ready to accept
       read/write commands.*/
    bdk_wait_usec(1);

    /* Configure the gser pll */

    /* Wait for reset to complete and the PLL to lock */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_QLM_STAT(qlm), rst_rdy, ==, 1, 10000))
    {
        bdk_error("QLM%d: Timeout waiting for GSERX_QLM_STAT[rst_rdy]\n", qlm);
        return -1;
    }
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_PLL_STAT(qlm), pll_lock, ==, 1, 10000))
    {
        bdk_error("QLM%d: Timeout waiting for GSERX_PLL_STAT[pll_lock]\n", qlm);
        return -1;
    }

    /* cdrlock will be checked in the BGX */
    return 0;
}


/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
static int qlm_get_gbaud_mhz(bdk_node_t node, int qlm)
{
    if (qlm < 8)
    {
        BDK_CSR_INIT(lane_mode, node, BDK_GSERX_LANE_MODE(qlm));
        switch (lane_mode.s.lmode)
        {
            case 0x0: /* R_25G_REFCLK100 */
                return 2500;
            case 0x1: /* R_5G_REFCLK100 */
                return 5000;
            case 0x2: /* R_8G_REFCLK100 */
                return 8000;
            case 0x3: /* R_125G_REFCLK15625_KX */
                return 1250;
            case 0x4: /* R_3125G_REFCLK15625_XAUI */
                return 3125;
            case 0x5: /* R_103215G_REFCLK15625_KR */
                return 10321;
            case 0x6: /* R_125G_REFCLK15625_SGMII */
                return 1250;
            case 0x7: /* R_5G_REFCLK15625_QSGMII */
                return 5000;
            case 0x8: /* R_625G_REFCLK15625_RXAUI */
                return 6250;
            case 0x9: /* R_25G_REFCLK125 */
                return 2500;
            case 0xa: /* R_5G_REFCLK125 */
                return 5000;
            case 0xb: /* R_8G_REFCLK125 */
                return 8000;
            default:
                return 0;
        }
    }
    else
    {
        BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(qlm));
        switch (gserx_spd.s.spd & 0x3)
        {
            case 0: return 1250;
            case 1: return 2500;
            case 2: return 3125;
            case 3: return 5000;
            case 4: return 6250;
            case 5: return 8000;
            case 6: return 10000;
            default: return 0;
        }
    }
}


/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
static int qlm_measure_refclock(bdk_node_t node, int qlm)
{
    /* We can't measure the OCI QLMs */
    if (qlm >= 8)
        return 0;

    /* Disable the PTP event counter while we configure it */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Count on rising edge, Choose which QLM to count */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG,
        c.s.evcnt_edge = 0;
        c.s.evcnt_in = 0x20 + qlm);
    /* Clear MIO_PTP_EVT_CNT */
    int64_t count = BDK_CSR_READ(node, BDK_MIO_PTP_EVT_CNT);
    BDK_CSR_WRITE(node, BDK_MIO_PTP_EVT_CNT, -count);
    /* Set MIO_PTP_EVT_CNT to 1 billion */
    BDK_CSR_WRITE(node, BDK_MIO_PTP_EVT_CNT, 1000000000);
    /* Enable the PTP event counter */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 1);
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Wait for 50ms */
    bdk_wait_usec(50000);
    /* Read the counter */
    count = BDK_CSR_READ(node, BDK_MIO_PTP_EVT_CNT);
    uint64_t stop_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Disable the PTP event counter */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Clock counted down, so reverse it */
    count = 1000000000 - count;
    /* Return the rate */
    return count * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / (stop_cycle - start_cycle);
}


/**
 * Reset a QLM to its initial state
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
static int qlm_reset(bdk_node_t node, int qlm)
{
    /* FIXME: Reset QLM */
    bdk_error("CN78XX QLM reset not implemented\n");
    return -1;
}


/**
 * Enable PRBS on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param prbs   PRBS mode (31, etc)
 * @param dir    Directions to enable. This is so you can enable TX and later
 *               enable RX after TX has run for a time
 *
 * @return Zero on success, negative on failure
 */
static int qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir)
{
    /* FIXME: Enable PRBS */
    bdk_error("CN78XX PRBS not implemented\n");
    return -1;
}

/**
 * Return the number of PRBS errors since PRBS started running
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 *
 * @return Number of errors
 */
static uint64_t qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane)
{
    /* FIXME: PRBS errors */
    bdk_error("CN78XX PRBS not implemented\n");
    return -1;
}

/**
 * Enable shallow loopback on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param loop   Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
static int qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop)
{
    bdk_error("CN78XX doesn't support shallow QLM loopback\n");
    return -1;
}

static void qlm_init_one(bdk_node_t node, int qlm)
{
    /* The QLM PLLs are controlled by an array of parameters indexed
       by the QLM mode for each QLM. We need to fill in these tables.
       Also each lane has some mode parameters, again in a array index
       by the lane_mode */
    for (int lane_mode = 0; lane_mode < 12; lane_mode++)
    {
        /* The values used below are all from
           http://mawiki.caveonetworks.com/wiki/78xx/GSER_WEST */
        BDK_CSR_INIT(mode_0, node, BDK_GSERX_PLL_PX_MODE_0(qlm, lane_mode));
        BDK_CSR_INIT(mode_1, node, BDK_GSERX_PLL_PX_MODE_1(qlm, lane_mode));
        BDK_CSR_INIT(pmode_0, node, BDK_GSERX_LANEX_PX_MODE_0(qlm, 0, lane_mode));
        BDK_CSR_INIT(pmode_1, node, BDK_GSERX_LANEX_PX_MODE_1(qlm, 0, lane_mode));
        switch (lane_mode)
        {
            case 0x0: /* R_25G_REFCLK100 */
                mode_0.s.pll_icp = 0x4;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x14;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x19;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x1;
                pmode_0.s.tx_ldiv = 0x1;
                pmode_0.s.rx_ldiv = 0x1;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x0;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0x14;
                break;
            case 0x1: /* R_5G_REFCLK100 */
                mode_0.s.pll_icp = 0x4;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x19;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x1;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0x14;
                break;
            case 0x2: /* R_8G_REFCLK100 */
                mode_0.s.pll_icp = 0x3;
                mode_0.s.pll_rloop = 0x5;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x1;
                mode_1.s.pll_opr = 0x1;
                mode_1.s.pll_div = 0x28;

                pmode_0.s.ctle = 0x3;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xb;
                pmode_1.s.ph_acc_adj = 0x23;
                break;
            case 0x3: /* R_125G_REFCLK15625_KX */
                mode_0.s.pll_icp = 0x1;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x28;

                mode_1.s.pll_16p5en = 0x1;
                mode_1.s.pll_cpadj = 0x3;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x10;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x2;
                pmode_0.s.rx_ldiv = 0x2;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x0;
                pmode_1.s.cdr_fgain = 0xc;
                pmode_1.s.ph_acc_adj = 0x1e;
                break;
            case 0x4: /* R_3125G_REFCLK15625_XAUI */
                mode_0.s.pll_icp = 0x1;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x14;

                mode_1.s.pll_16p5en = 0x1;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x10;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x1;
                pmode_0.s.rx_ldiv = 0x1;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x0;
                pmode_1.s.cdr_fgain = 0xc;
                pmode_1.s.ph_acc_adj = 0x1e;
                break;
            case 0x5: /* R_103215G_REFCLK15625_KR */
                mode_0.s.pll_icp = 0x1;
                mode_0.s.pll_rloop = 0x5;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x1;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x1;
                mode_1.s.pll_div = 0x21;

                pmode_0.s.ctle = 0x3;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x1;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0xf;
                break;
            case 0x6: /* R_125G_REFCLK15625_SGMII */
                mode_0.s.pll_icp = 0x1;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x28;

                mode_1.s.pll_16p5en = 0x1;
                mode_1.s.pll_cpadj = 0x3;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x10;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x2;
                pmode_0.s.rx_ldiv = 0x2;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x0;
                pmode_1.s.cdr_fgain = 0xc;
                pmode_1.s.ph_acc_adj = 0x1e;
                break;
            case 0x7: /* R_5G_REFCLK15625_QSGMII */
                mode_0.s.pll_icp = 0x3;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x5;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x10;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xc;
                pmode_1.s.ph_acc_adj = 0x1e;
                break;
            case 0x8: /* R_625G_REFCLK15625_RXAUI */
                mode_0.s.pll_icp = 0x1;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x2;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x14;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0x14;
                break;
            case 0x9: /* R_25G_REFCLK125 */
                mode_0.s.pll_icp = 0x3;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0x14;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x1;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x14;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x1;
                pmode_0.s.tx_ldiv = 0x1;
                pmode_0.s.rx_ldiv = 0x1;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x0;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0x14;
                break;
            case 0xa: /* R_5G_REFCLK125 */
                mode_0.s.pll_icp = 0x3;
                mode_0.s.pll_rloop = 0x3;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x1;
                mode_1.s.pll_pcie3en = 0x0;
                mode_1.s.pll_opr = 0x0;
                mode_1.s.pll_div = 0x14;

                pmode_0.s.ctle = 0x0;
                pmode_0.s.pcie = 0x1;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xa;
                pmode_1.s.ph_acc_adj = 0x14;
                break;
            case 0xb: /* R_8G_REFCLK125 */
                mode_0.s.pll_icp = 0x2;
                mode_0.s.pll_rloop = 0x5;
                mode_0.s.pll_pcs_div = 0xa;

                mode_1.s.pll_16p5en = 0x0;
                mode_1.s.pll_cpadj = 0x1;
                mode_1.s.pll_pcie3en = 0x1;
                mode_1.s.pll_opr = 0x1;
                mode_1.s.pll_div = 0x20;

                pmode_0.s.ctle = 0x3;
                pmode_0.s.pcie = 0x0;
                pmode_0.s.tx_ldiv = 0x0;
                pmode_0.s.rx_ldiv = 0x0;
                pmode_0.s.srate = 0x0;
                pmode_0.s.tx_mode = 0x3;
                pmode_0.s.rx_mode = 0x3;

                pmode_1.s.vma_fine_cfg_sel = 0x0;
                pmode_1.s.vma_mm = 0x1;
                pmode_1.s.cdr_fgain = 0xb;
                pmode_1.s.ph_acc_adj = 0x23;
                break;
        }
        BDK_CSR_WRITE(node, BDK_GSERX_PLL_PX_MODE_0(qlm, lane_mode), mode_0.u);
        BDK_CSR_WRITE(node, BDK_GSERX_PLL_PX_MODE_1(qlm, lane_mode), mode_1.u);
        for (int lane = 0; lane < 4; lane++)
        {
            BDK_CSR_WRITE(node, BDK_GSERX_LANEX_PX_MODE_0(qlm, lane, lane_mode), pmode_0.u);
            BDK_CSR_WRITE(node, BDK_GSERX_LANEX_PX_MODE_1(qlm, lane, lane_mode), pmode_1.u);
        }
    }
}

/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    int num_qlms = qlm_get_num(node);
    for (int qlm = 0; qlm < num_qlms; qlm++)
        qlm_init_one(node, qlm);
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn78xx = {
    .chip_model = OCTEON_CN78XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .set_mode = qlm_set_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
    .reset = qlm_reset,
    .enable_prbs = qlm_enable_prbs,
    .get_prbs_errors = qlm_get_prbs_errors,
    .enable_loop = qlm_enable_loop,
};



#include <bdk.h>
#include "bdk-qlm-common.h"

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 7; /* 4 QLM + 3 DLM */
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
    if (qlm < 4)
        return 4; /* QLMs 0-3 */
    else
        return 2; /* DLMs 4-6 */
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
static int qlm_get_qlm_num(bdk_node_t node, bdk_if_t iftype, int interface, int index)
{
    switch (iftype)
    {
        case BDK_IF_BGX:
        {
            int qlm;
            switch (interface)
            {
                case 0:
                    qlm = 2;
                    break;
                case 1:
                    qlm = 3;
                    break;
                case 2:
                {
                    /* This BGX spans two DLMs. The index must be used to
                       figure out which DLM we are using */
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(5));
                    if (gserx_cfg.s.bgx)
                    {
                        if (gserx_cfg.s.bgx_quad) /* 4 lanes together */
                            qlm = 5;
                        else if (gserx_cfg.s.bgx_dual) /* 2 lanes together */
                            qlm = (index >= 1) ? 6 : 5;
                        else /* All lanes independent */
                            qlm = (index >= 2) ? 6 : 5;
                    }
                    else
                        qlm = 6;
                    break;
                }
                default:
                    return -1;
            }
            if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
                return qlm;
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
        case BDK_IF_PCIE: /* PCIe */
        {
            if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
                return -1;
            switch (interface)
            {
                case 0: /* PEM0 */
                {
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(0));
                    if (gserx_cfg.s.pcie)
                        return 0; /* PEM0 is on QLM0 and possibly QLM1 */
                    else
                        return -1; /* PEM0 is disabled */
                }
                case 1: /* PEM1 */
                {
                    BDK_CSR_INIT(pem0_cfg, node, BDK_PEMX_CFG(0));
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(1));
                    if (!pem0_cfg.s.lanes8 && gserx_cfg.s.pcie)
                        return 1; /* PEM1 is on QLM 1 */
                    else
                        return -1; /* PEM1 is disabled */
                }
                case 2: /* PEM2 */
                {
                    BDK_CSR_INIT(pemx_qlm, node, BDK_PEMX_QLM(2));
                    if (pemx_qlm.s.pem_bdlm)
                    {
                        /* PEM2 is routed to DLM5 */
                        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(5));
                        if (gserx_cfg.s.pcie)
                            return 5; /* PEM2 is on DLM5 */
                        else
                            return -1; /* PEM2 is disabled */
                    }
                    else
                    {
                        /* PEM2 is routed to QLM2 */
                        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(2));
                        if (gserx_cfg.s.pcie)
                            return 2; /* PEM2 is on QLM2 and possibly QLM3 */
                        else
                            return -1; /* PEM2 is disabled */
                    }
                }
                case 3: /* PEM3 */
                {
                    BDK_CSR_INIT(pemx_qlm, node, BDK_PEMX_QLM(3));
                    if (pemx_qlm.s.pem_bdlm)
                    {
                        /* PEM3 is routed to DLM6 */
                        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(6));
                        if (gserx_cfg.s.pcie)
                            return 6; /* PEM3 is on DLM6 */
                        else
                            return -1; /* PEM3 is disabled */
                    }
                    else
                    {
                        /* PEM3 is routed to QLM3 */
                        BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
                        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(3));
                        if (!pem2_cfg.s.lanes8 && gserx_cfg.s.pcie)
                            return 3; /* PEM3 is on QLM3 */
                        else
                            return -1; /* PEM3 is disabled */
                    }
                }
                default: /* Max of 4 PEMs, 0-3 */
                    return -1;
            }
        }
        default: /* Not supported by CN83XX */
            return -1;
    }
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
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
    {
        if ((qlm == 2) || (qlm == 3))
            return BDK_QLM_MODE_XFI_4X1;
        else
            return BDK_QLM_MODE_DISABLED;
    }
    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
    if (gserx_cfg.s.pcie)
    {
        switch (qlm)
        {
            case 0: /* Either PEM0 x4 or PEM0 x8 */
            case 1: /* Either PEM0 x8 or PEM1 x4 */
            {
                BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(0));
                if (pemx_cfg.s.lanes8)
                    return BDK_QLM_MODE_PCIE_1X8;
                else
                    return BDK_QLM_MODE_PCIE_1X4;
            }
            case 2: /* Either PEM2 x4 or PEM2 x8 */
            {
                BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(2));
                if (pemx_cfg.s.lanes8)
                    return BDK_QLM_MODE_PCIE_1X8; /* PEM2 x8 */
                else
                    return BDK_QLM_MODE_PCIE_1X4; /* PEM2 x4 */
            }
            case 3: /* Either PEM2 x8 or PEM3 x4 */
            {
                /* Can be last 4 lanes of PEM2 */
                BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
                if (pem2_cfg.s.lanes8)
                    return BDK_QLM_MODE_PCIE_1X8; /* PEM2 x8 */
                /* Can be 4 lanes of PEM3 */
                return BDK_QLM_MODE_PCIE_1X4; /* PEM3 x4 */
            }
            case 5: /* PEM2 x2 */
                return BDK_QLM_MODE_PCIE_1X2; /* PEM2 x2 */
            case 6: /* PEM3 x2 */
                return BDK_QLM_MODE_PCIE_1X2; /* PEM3 x2 */
            default:
                return BDK_QLM_MODE_DISABLED;
        }
    }
    else if (gserx_cfg.s.bgx)
    {
        int bgx;
        int bgx_index;
        switch (qlm)
        {
            case 2:
                bgx = 0;
                bgx_index = 0;
                break;
            case 3:
                bgx = 1;
                bgx_index = 0;
                break;
            case 4:
                bgx = 3;
                bgx_index = 0;
                break;
            case 5:
            case 6:
                bgx = 2;
                bgx_index = (qlm == 5) ? 0 : 2;
                if (qlm == 5)
                {
                    /* Special check for RXAUI in DLM5. If DLM6 is XFI and there
                       is no RGMII, BGX will overwrite index 1 with XFI's mode
                       and RGMII will be shown in index 0 */
                    BDK_CSR_INIT(cmrx_config, node, BDK_BGXX_CMRX_CONFIG(bgx, 0));
                    if (cmrx_config.s.lmac_type == 0x2)
                        bgx_index=0;
                }
                break;
            default:
                return BDK_QLM_MODE_DISABLED;
        }
        BDK_CSR_INIT(cmrx_config, node, BDK_BGXX_CMRX_CONFIG(bgx, bgx_index));
        bool is_kr = __bdk_qlm_is_lane_kr(node, qlm, 0);
        switch (cmrx_config.s.lmac_type)
        {
            case 0x0: return (bgx >= 2) ? BDK_QLM_MODE_SGMII_2X1 : BDK_QLM_MODE_SGMII_4X1;
            case 0x1: return BDK_QLM_MODE_XAUI_1X4; /* Doesn't differntiate between XAUI and DXAUI */
            case 0x2: return (bgx >= 2) ? BDK_QLM_MODE_RXAUI_1X2 : BDK_QLM_MODE_RXAUI_2X2;
            case 0x3:
                if (is_kr)
                    return (bgx >= 2) ? BDK_QLM_MODE_10G_KR_2X1 : BDK_QLM_MODE_10G_KR_4X1;
                else
                    return (bgx >= 2) ? BDK_QLM_MODE_XFI_2X1 : BDK_QLM_MODE_XFI_4X1;
            case 0x4:
                if (is_kr)
                    return BDK_QLM_MODE_40G_KR4_1X4;
                else
                    return BDK_QLM_MODE_XLAUI_1X4;
            case 0x6: return BDK_QLM_MODE_QSGMII_4X1;
            default:  return BDK_QLM_MODE_DISABLED;
        }
    }
    else if (gserx_cfg.s.sata)
        return BDK_QLM_MODE_SATA_2X1;
    else
        return BDK_QLM_MODE_DISABLED;
}

static int qlm_set_sata(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags)
{
    const int MAX_A_CLK = 333000000; /* Max of 333Mhz */

    /* SATA has a fixed mapping for ports on CN83XX */
    int sata_port;
    switch (qlm)
    {
        case 4: /* SATA 0-1 = DLM4 lanes 0-1 */
            sata_port = 0;
            break;
        case 5: /* SATA 2-3 = DLM5 lanes 0-1 */
            sata_port = 2;
            break;
        case 6: /* SATA 4-5 = DLM6 lanes 0-1 */
            sata_port = 4;
            break;
        default:
            bdk_error("Attempted to configure SATA on QLM that doesn't support it\n");
            return -1;
    }
    int sata_port_end = sata_port + 2;

    /* 26.4.1 Cold Reset */
    /* 1.  Ensure that the SerDes reference clock is up and stable. */
    /* Already done */

    /* 2.  Optionally program the GPIO CSRs for SATA features.
        a.  For cold-presence detect, select a GPIO for the input and program GPI-
            O_BIT_CFG(0..50)[PIN_SEL] = GPIO_PIN_SEL_E::SATA(0..15)_CP_DET.
        b. For mechanical-presence detect, select a GPIO for the input and program
            GPIO_BIT_CFG(0..50)[PIN_SEL] = GPI-
            O_PIN_SEL_E::SATA(0..15)_MP_SWITCH.
        c. For BIST board-test loopback, select a GPIO for the input and program GPI-
            O_BIT_CFG(0..50)[PIN_SEL] = GPIO_PIN_SEL_E:::SATA_LAB_LB.
        d. For LED activity, select a GPIO for the output and program GPI-
            O_BIT_CFG(0..50)[PIN_SEL] = GPIO_PIN_SEL_E:::SATA(0..15)_ACT_LED.
        e. For cold-presence power-on-device, select a GPIO for the output and program
            GPIO_BIT_CFG(0..50)[PIN_SEL] = GPIO_PIN_SEL_E:::SATA(0..15)_CP_-
            POD. */
    /* Skipping */

    /* 3.  Optionally program the SGPIO unit. */
    /* Skipping */

    /* 4.  Assert all resets:
        a.  UAHC reset: SATA(0..15)_UCTL_CTL[SATA_UAHC_RST] = 1
        b. UCTL reset: SATA(0..15)_UCTL_CTL[SATA_UCTL_RST] = 1 */
    for (int p = sata_port; p < sata_port_end; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.sata_uahc_rst = 1;
            c.s.sata_uctl_rst = 1);
    }

    /* 5.  Configure the ACLK:
        a.  Reset the clock dividers: SATA(0..15)_UCTL_CTL[A_CLKDIV_RST] = 1.
        b. Select the ACLK frequency (refer to maximum values in Table 26 1).
            i. SATA(0..15)_UCTL_CTL[A_CLKDIV_SEL] = desired value,
            ii. SATA(0..15)_UCTL_CTL[A_CLK_EN] = 1 to enable the ACLK.
        c.  Deassert the ACLK clock divider reset:
            SATA(0..15)_UCTL_CTL[A_CLKDIV_RST] = 0. */
    int divisor = (bdk_clock_get_rate(node, BDK_CLOCK_SCLK) + MAX_A_CLK - 1) / MAX_A_CLK;
    int a_clkdiv;
    /* This screwy if logic is from the description of
       SATAX_UCTL_CTL[a_clkdiv_sel] in the CSR */
    if (divisor <= 4)
    {
        a_clkdiv = divisor - 1;
        /* Divisor matches calculated value */
    }
    else if (divisor <= 6)
    {
        a_clkdiv = 4;
        divisor = 6;
    }
    else if (divisor <= 8)
    {
        a_clkdiv = 5;
        divisor = 8;
    }
    else if (divisor <= 16)
    {
        a_clkdiv = 6;
        divisor = 16;
    }
    else if (divisor <= 24)
    {
        a_clkdiv = 7;
        divisor = 24;
    }
    else
    {
        bdk_error("Unable to determine SATA clock divisor\n");
        return -1;
    }
    /* Calculate the final clock rate */
    int a_clk = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / divisor;

    for (int p = sata_port; p < sata_port_end; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.a_clkdiv_rst = 1);
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.a_clk_byp_sel = 0;
            c.s.a_clkdiv_sel = a_clkdiv;
            c.s.a_clk_en = 1);
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.a_clkdiv_rst = 0);
    }
    bdk_wait_usec(1);

    /* 6.  Deassert UCTL and UAHC resets:
        a.  SATA(0..15)_UCTL_CTL[SATA_UAHC_RST] = 0
        b. SATA(0..15)_UCTL_CTL[SATA_UCTL_RST] = 0
        c. Wait 10 ACLK cycles before accessing any ACLK-only registers. */
    for (int p = sata_port; p < sata_port_end; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.sata_uahc_rst = 0;
            c.s.sata_uctl_rst = 0);
    }
    bdk_wait_usec(1);

    /* 7.  Enable conditional SCLK of UCTL by writing
        SATA(0..15)_UCTL_CTL[CSCLK_EN] = 1. */
    for (int p = sata_port; p < sata_port_end; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.csclk_en = 1);
    }

    /* 8.  Configure PHY for SATA. Refer to Section 21.1.2. */
    /* Done below, section 24.1.2.3 */

    /* 9.  TBD: Poll QLM2_MPLL_STATUS for MPLL lock */
    /* Not needed */

    /* 10. Initialize UAHC as described in the AHCI specification
        (UAHC_* registers). */
    /* Done when a SATA driver is initialized */

    /* 24.1.2.3 SATA Configuration
    Software must perform the following steps to configure the GSER_WEST
    for a SATA application. Note that the GSERW steps are on a QLM basis. */

    /* 1. Configure the SATA controller (refer to Chapter 26). */
    /* This is the code above */

    /* 2. Configure the QLM Reference clock.
        Set GSER(0..13)_REFCLK_SEL[COM_CLK_SEL] = 1 to source the reference
            clock from the external clock multiplexer.
        Configure GSER(0..13)_REFCLK_SEL[USE_COM1]:
            0 = use QLMC_REF_CLK0_P/N
            1 = use QLMC_REF_CLK1_P/N */
    /* Already done */

    /* Make sure the PHY is in reset before we reconfig */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 1);
    bdk_wait_usec(1);

    /* 3. Configure the QLM for SATA mode: set GSER(0..13)_CFG[SATA] = 1. */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(qlm),
        c.u = 0;
        c.s.sata = 1);

    /* 4. Take the PHY out of reset: write GSER(0..13)_PHY_CTL[PHY_RESET] = 0. */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 0);
    /* Wait 250 ns until the management interface is ready to accept
       read/write commands.*/
    bdk_wait_usec(1);

    /* 5. Change the P2 termination
       GSERn_RX_PWR_CTRL_P2[P2_RX_SUBBLK_PD<0>] = 0 (termination) */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_RX_PWR_CTRL_P2(qlm),
        c.s.p2_rx_subblk_pd &= 0x1e);

    /* 6. Modify the electrical IDLE detect on delay: set
       GSER(0..13)_LANE(0..3)_MISC_CFG_0[EIE_DET_STL_ON_TIME] = 0x4 */
    for (int lane=0; lane<2; lane++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_MISC_CFG_0(qlm, lane),
            c.s.eie_det_stl_on_time = 4);
    }

    /* 7. Modify the PLL and lane-protocol-mode registers to configure the
       PHY for SATA */
    /* Errata (GSER-26724) SATA never indicates GSER QLM_STAT[RST_RDY]
       We program PLL_PX_MODE_0 last due to this errata */
    for (int p=0; p<3; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PLL_PX_MODE_1(qlm, p),
            c.s.pll_16p5en = 0x0;
            c.s.pll_cpadj = 0x2;
            c.s.pll_pcie3en = 0;
            c.s.pll_opr = 0x0;
            c.s.pll_div = 0x1e);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_PX_MODE_0(qlm, p),
            c.s.ctle = (p==2) ? 0x3 : 0x0;
            c.s.pcie = 0;
            c.s.tx_ldiv = 0x0;
            c.s.rx_ldiv = 2 - p;
            c.s.srate = 0;
            c.s.tx_mode = 3;
            c.s.rx_mode = 3);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_PX_MODE_1(qlm, p),
            c.s.vma_fine_cfg_sel = 0;
            c.s.vma_mm = 1;
            c.s.cdr_fgain = 0xf; /* This values are to help with SSC */
            c.s.ph_acc_adj = 0x12); /* This values are to help with SSC */
    }
    for (int p=0; p<3; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PLL_PX_MODE_0(qlm, p),
            c.s.pll_icp = 0x1;
            c.s.pll_rloop = 0x3;
            c.s.pll_pcs_div = 0x5);
    }

    for (int s=0; s<2; s++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_SLICEX_RX_SDLL_CTRL(qlm, s),
            c.s.pcs_sds_oob_clk_ctrl  = 2;
            c.s.pcs_sds_rx_sdll_tune  = 0;
            c.s.pcs_sds_rx_sdll_swsel = 0);
    }

    for (int p=0; p<2; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_MISC_CFG_0(qlm, p),
            c.s.use_pma_polarity     = 0;
            c.s.cfg_pcs_loopback     = 0;
            c.s.pcs_tx_mode_ovrrd_en = 0;
            c.s.pcs_rx_mode_ovrrd_en = 0;
            c.s.cfg_eie_det_cnt      = 0;
            c.s.eie_det_stl_on_time  = 4;
            c.s.eie_det_stl_off_time = 0;
            c.s.tx_bit_order         = 1;
            c.s.rx_bit_order         = 1);
    }

    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* 8. Wait for GSER(0..13)_QLM_STAT[RST_RDY] = 1, indicating that the PHY
           has been reconfigured and PLLs are locked. */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_QLM_STAT(qlm), rst_rdy, ==, 1, 10000))
        {
            bdk_error("QLM%d: Timeout waiting for GSERX_QLM_STAT[rst_rdy]\n", qlm);
            return -1;
        }
    }

    /* 9. Clear the appropriate lane resets:
       GSER(0..13)_SATA_LANE_RST[Ln_RST] = 0, where n is the lane number 0-3. */
    BDK_CSR_WRITE(node, BDK_GSERX_SATA_LANE_RST(qlm), 0);
    BDK_CSR_READ(node, BDK_GSERX_SATA_LANE_RST(qlm));

    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* Poll GSERX_SATA_STATUS for PX_RDY = 1 */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_SATA_STATUS(qlm), p0_rdy, ==, 1, 10000))
        {
            bdk_error("QLM%d: Timeout waiting for GSERX_SATA_STATUS[p0_rdy]\n", qlm);
            return -1;
        }
    }

    int spd;
    if (baud_mhz < 3000)
        spd = 1;
    else if (baud_mhz < 6000)
        spd = 2;
    else
        spd = 3;
    for (int p = sata_port; p < sata_port_end; p++)
    {
        /* From the synopsis data book, SATAX_UAHC_GBL_TIMER1MS is the
           AMBA clock in MHz * 1000, which is a_clk(Hz) / 1000 */
        BDK_TRACE(QLM, "QLM%d: SATA%d set to %d Hz\n", qlm, p, a_clk);
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_GBL_TIMER1MS(p),
            c.s.timv = a_clk / 1000);
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_GBL_CAP(p),
            c.s.sss = 1;
            c.s.smps = 1);
        /* Set speed */
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_SCTL(p),
            c.s.spd = spd);
        /* Report 1 port per controller */
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_GBL_PI(p),
            c.s.pi = 1);
        /* Clear all port errors */
        BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_SERR(p), -1);
        BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_IS(p), -1);
    }

    /* Check BIST on the SATA controller. Start BIST in parallel on the
       controllers */
    for (int p = sata_port; p < sata_port_end; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_SATAX_UCTL_CTL(p),
            c.s.start_bist = 1);
    }
    bdk_wait_usec(1000);
    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        for (int p = sata_port; p < sata_port_end; p++)
        {
            BDK_CSR_INIT(bist, node, BDK_SATAX_UCTL_BIST_STATUS(p));
            if (bist.u)
                bdk_error("N%d.SATA%d: Controller failed BIST (0x%lx)\n", node, p, bist.u);
            else
                BDK_TRACE(SATA, "N%d.SATA%d: Passed BIST\n", node, p);
        }
    }

    /* Apply any custom tuning */
    __bdk_qlm_tune(node, qlm, mode, baud_mhz);
    return 0;
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
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
        return -1;

    int lane_mode = 0xf;
    int lmac_type = -1;
    int is_pcie = 0;
    int is_sata = 0;
    int is_ilk = 0;
    int is_bgx = 0;
    int bgx_block;
    int bgx_index;

    switch (qlm)
    {
        case 2:
            bgx_block = 0;
            bgx_index = 0;
            break;
        case 3:
            bgx_block = 1;
            bgx_index = 0;
            break;
        case 4:
            bgx_block = 3;
            bgx_index = 0;
            break;
        case 5 ... 6:
            bgx_block = 2;
            bgx_index = (qlm == 5) ? 0 : 2;
            break;
        default:
            bgx_block = -1;
            bgx_index = -1;
            break;
    }

    int measured_ref = bdk_qlm_measure_clock(node, qlm);
    int ref_clk = (mode == BDK_QLM_MODE_DISABLED) ? 0 : __bdk_qlm_round_refclock(measured_ref);
    int kr_mode = 0;

    switch (mode)
    {
        case BDK_QLM_MODE_PCIE_1X2:
        case BDK_QLM_MODE_PCIE_1X4:
        case BDK_QLM_MODE_PCIE_1X8:
        {
            /* Note: PCIe ignores baud_mhz. Use the GEN 1/2/3 flags
               to control speed */
            is_pcie = 1;
            if (ref_clk == REF_100MHZ)
            {
                BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_SEL(qlm),
                    c.s.pcie_refclk125 = 0);
                if (baud_mhz == 2500)
                    lane_mode = BDK_GSER_LMODE_E_R_25G_REFCLK100;
                else if (baud_mhz == 5000)
                    lane_mode = BDK_GSER_LMODE_E_R_5G_REFCLK100;
                else
                    lane_mode = BDK_GSER_LMODE_E_R_8G_REFCLK100;
            }
            else if (ref_clk == REF_125MHZ)
            {
                BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_SEL(qlm),
                    c.s.pcie_refclk125 = 1);
                if (baud_mhz == 2500)
                    lane_mode = BDK_GSER_LMODE_E_R_25G_REFCLK125;
                else if (baud_mhz == 5000)
                    lane_mode = BDK_GSER_LMODE_E_R_5G_REFCLK125;
                else
                    lane_mode = BDK_GSER_LMODE_E_R_8G_REFCLK125;
            }
            else
            {
                bdk_error("Invalid reference clock for PCIe on QLM%d\n", qlm);
                return -1;
            }
            int cfg_md;
            if (baud_mhz == 2500)
                cfg_md = 0; /* Gen1 Speed */
            else if (baud_mhz == 5000)
                cfg_md = 1; /* Gen2 Speed */
            else
                cfg_md = 2; /* Gen3 Speed */
            switch (qlm)
            {
                case 0: /* Either x4 or x8 based on PEM0 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(0),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    __bdk_qlm_setup_pem_reset(node, 0, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(0),
                        c.s.lanes8 = (mode == BDK_QLM_MODE_PCIE_1X8);
                        c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    /* x8 mode waits for QLM1 setup before turning on the PEM */
                    if (mode == BDK_QLM_MODE_PCIE_1X4)
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(0),
                            c.s.pemon = 1);
                    break;
                case 1: /* Either PEM0 x8 or PEM1 x4 */
                    if (mode == BDK_QLM_MODE_PCIE_1X8)
                    {
                        /* Last 4 lanes of PEM0 */
                        /* PEMX_CFG already setup */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(0),
                            c.s.pemon = 1);
                    }
                    else
                    {
                        /* Four lanes for PEM1 */
                        BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(1),
                            c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                        __bdk_qlm_setup_pem_reset(node, 1, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(1),
                            c.s.lanes8 = 0;
                            c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                            c.s.md = cfg_md);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(1),
                            c.s.pemon = 1);
                    }
                    break;
                case 2: /* Either PEM2 x4 or PEM2 x8 */
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_QLM(2),
                        c.s.pem_bdlm = 0); /* PEM2 is on QLM2 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(2),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    __bdk_qlm_setup_pem_reset(node, 2, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(2),
                        c.s.lanes8 = (mode == BDK_QLM_MODE_PCIE_1X8);
                        c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    /* x8 mode waits for QLM3 setup before turning on the PEM */
                    if (mode == BDK_QLM_MODE_PCIE_1X4)
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2),
                            c.s.pemon = 1);
                    /* GSER5 can't be PCIe */
                    BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(5), c.s.pcie = 0);
                    break;
                case 3: /* Either PEM2 x8, or PEM3 x4 */
                {
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(2));
                    if (pemx_cfg.s.lanes8)
                    {
                        /* Last 4 lanes of PEM2 */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_QLM(3),
                            c.s.pem_bdlm = 1); /* PEM3 can only be on DLM6 */
                        /* PEMX_CFG already setup */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2),
                            c.s.pemon = 1);
                    }
                    else
                    {
                        /* Four lanes of PEM3 */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_QLM(3),
                            c.s.pem_bdlm = 0); /* PEM3 is on QLM3 */
                        BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(3),
                            c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                        __bdk_qlm_setup_pem_reset(node, 3, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(3),
                            c.s.lanes8 = 0;
                            c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                            c.s.md = cfg_md);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(3),
                            c.s.pemon = 1);
                        /* GSER6 can't be PCIe */
                        BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(6), c.s.pcie = 0);
                    }
                    break;
                }
                case 5: /* PEM2 x2 on DLM5 */
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_QLM(2),
                        c.s.pem_bdlm = 1); /* PEM2 is on DLM5 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(2),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    __bdk_qlm_setup_pem_reset(node, 2, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(2),
                        c.s.lanes8 = 0;
                        c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2),
                        c.s.pemon = 1);
                    /* GSER2 can't be PCIe */
                    BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(2), c.s.pcie = 0);
                    break;
                case 6: /* PEM3 x2 on DLM6 */
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_QLM(3),
                        c.s.pem_bdlm = 1); /* PEM3 is on DLM6 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(3),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    __bdk_qlm_setup_pem_reset(node, 3, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(3),
                        c.s.lanes8 = 0;
                        c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(3),
                        c.s.pemon = 1);
                    /* GSER3 can't be PCIe unless pem2 is x8 */
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(2));
                    if (!pemx_cfg.s.lanes8)
                        BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(3), c.s.pcie = 0);
                    break;
                default:
                    return -1;
            }
            break;
        }
        case BDK_QLM_MODE_SGMII_4X1:
        case BDK_QLM_MODE_SGMII_2X1:
            lmac_type = 0; /* SGMII */
            is_bgx = 1;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("SGMII", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            lmac_type = 1; /* XAUI */
            is_bgx = 5;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("XAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
        case BDK_QLM_MODE_RXAUI_1X2:
            lmac_type = 2; /* RXAUI */
            is_bgx = 3;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("RXAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_XFI_4X1:
        case BDK_QLM_MODE_XFI_2X1:
            lmac_type = 3; /* 10G_R */
            is_bgx = 1;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("XFI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_XLAUI_1X4:
            lmac_type = 4; /* 40G_R */
            is_bgx = 5;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("XLAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_10G_KR_4X1:
        case BDK_QLM_MODE_10G_KR_2X1:
            lmac_type = 3; /* 10G_R */
            is_bgx = 1;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("10G-KR", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            kr_mode = 1;
            break;
        case BDK_QLM_MODE_40G_KR4_1X4:
            lmac_type = 4; /* 40G_R */
            is_bgx = 5;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("40G-KR", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            kr_mode = 1;
            break;
        case BDK_QLM_MODE_QSGMII_4X1:
            lmac_type = 6; /* QSGMII */
            is_bgx = 1;
            lane_mode = __bdk_qlm_get_lane_mode_for_speed_and_ref_clk("QSGMII", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_SATA_2X1:
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_MODE(qlm), c.s.lmode = BDK_GSER_LMODE_E_R_8G_REFCLK100);
            /* SATA initialization is different than BGX. Call its init function
               and skip the rest of this routine */
            return qlm_set_sata(node, qlm, mode, baud_mhz, flags);
        case BDK_QLM_MODE_DISABLED:
            /* Set gser for the interface mode */
            BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(qlm),
                c.u = 0);
            /* Put the PHY in reset */
            BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
                c.s.phy_reset = 1);
            return 0;
        default:
            bdk_error("Unsupported QLM mode %d\n", mode);
            return -1;
    }

    /* Power up phy, but keep it in reset */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_pd = 0;
        c.s.phy_reset = 1);

    /* Set gser for the interface mode */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_CFG(qlm),
        c.s.sata = is_sata;
        c.s.ila = is_ilk;
        c.s.bgx = is_bgx & 1;
        c.s.bgx_quad = (is_bgx >> 2) & 1;
        c.s.bgx_dual = (is_bgx >> 1) & 1;
        c.s.pcie = is_pcie);

    /* Lane mode */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_MODE(qlm),
        c.s.lmode = lane_mode);

    /* LMAC type. We only program one port as the full setup is done in BGX */
    if (lmac_type != -1)
    {
        BDK_CSR_MODIFY(c, node, BDK_BGXX_CMRX_CONFIG(bgx_block, bgx_index),
            c.s.enable = 0;
            c.s.lmac_type = lmac_type);
    }

    /* Bring phy out of reset */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 0);

    /* Wait 1us until the management interface is ready to accept
       read/write commands.*/
    bdk_wait_usec(1);

    /* Configure the gser pll */
    __bdk_qlm_init_mode_table(node, qlm);

    /* Remember which lanes are using KR over BGX */
    if (is_bgx)
    {
        int num_lanes = bdk_qlm_get_lanes(node, qlm);
        for (int lane = 0; lane < num_lanes; lane++)
            __bdk_qlm_set_lane_kr(node, qlm, lane, kr_mode);
    }

    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* Wait for reset to complete and the PLL to lock */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_PLL_STAT(qlm), pll_lock, ==, 1, 10000))
        {
            bdk_error("QLM%d: Timeout waiting for GSERX_PLL_STAT[pll_lock]\n", qlm);
            return -1;
        }

        /* PCIe mode doesn't become ready until the PEM block attempts to bring
           the interface up. Skip this check for PCIe */
        if (!is_pcie && BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_QLM_STAT(qlm), rst_rdy, ==, 1, 10000))
        {
            bdk_error("QLM%d: Timeout waiting for GSERX_QLM_STAT[rst_rdy]\n", qlm);
            return -1;
        }
    }

    /* cdrlock will be checked in the BGX */

    /* Errata (GSER-27140) SERDES temperature drift sensitivity in receiver */
    __bdk_qlm_errata_gser_27140(node, qlm, baud_mhz, false);

    /* Apply any custom tuning */
    __bdk_qlm_tune(node, qlm, mode, baud_mhz);

    /* If we're setting up the first QLM of a PCIe x8 interface, go ahead and
       setup the other inteface automatically */
    if (mode == BDK_QLM_MODE_PCIE_1X8)
    {
        switch (qlm)
        {
            case 0:
            case 2:
                /* Use the same reference clock for the second QLM */
                BDK_CSR_WRITE(node, BDK_GSERX_REFCLK_SEL(qlm + 1),
                    BDK_CSR_READ(node, BDK_GSERX_REFCLK_SEL(qlm)));
                return bdk_qlm_set_mode(node, qlm + 1, mode, baud_mhz, flags);
        }
    }

    /* If we're setting up the first DLM of a 4 lane interface on DLM5-6, go
       ahead and setup the other inteface automatically */
    if ((qlm == 5) && ((mode == BDK_QLM_MODE_XAUI_1X4) ||
                       (mode == BDK_QLM_MODE_XLAUI_1X4) ||
                       (mode == BDK_QLM_MODE_40G_KR4_1X4)))
    {
        /* Use the same reference clock for the second DLM */
        BDK_CSR_WRITE(node, BDK_GSERX_REFCLK_SEL(qlm + 1),
            BDK_CSR_READ(node, BDK_GSERX_REFCLK_SEL(qlm)));
        return bdk_qlm_set_mode(node, qlm + 1, mode, baud_mhz, flags);
    }

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
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
        return 10312;

    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
    if (gserx_cfg.u == 0)
        return 0;
    if (gserx_cfg.s.pcie)
    {
        /* QLMs in PCIe mode ignore LMODE and get their speed from
           the PEM block that controls them */
        int pem;
        switch (qlm)
        {
            case 0: /* Either PEM0 x4 or PEM0 x8 */
                pem = 0;
                break;
            case 1: /* Either PEM0 x8 or PEM1 x4 */
            {
                BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(0));
                if (pemx_cfg.s.lanes8)
                    pem = 0;
                else
                    pem = 1;
                break;
            }
            case 2: /* Either PEM2 x4 or PEM2 x8 */
                pem = 2;
                break;
            case 3: /* Either PEM2 x8 or PEM3 x4 */
            {
                /* Can be last 4 lanes of PEM2 */
                BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
                if (pem2_cfg.s.lanes8)
                {
                    pem = 2;
                }
                else
                {
                    /* Not last 4 lanes of PEM2, so should surely be PEM3 */
                    pem = 3;
                }
                break;
            }
            case 5: /* PEM2 x2 */
                pem = 2;
                break;
            case 6: /* PEM3 x2 */
                pem = 3;
                break;
            default:
                bdk_fatal("QLM%d: In PCIe mode, which shouldn't happen\n", qlm);
        }
        return __bdk_qlm_get_gbaud_mhz_pem(node, pem);
    }
    else if (gserx_cfg.s.sata)
    {
        int sata;
        switch (qlm)
        {
            case 4:
                sata = 0;
                break;
            case 5:
                sata = 2;
                break;
            case 6:
                sata = 4;
                break;
            default:
                return 0;
        }
        BDK_CSR_INIT(sata_uctl_ctl, node, BDK_SATAX_UCTL_CTL(sata));
        if (!sata_uctl_ctl.s.a_clk_en)
            return 0;
        BDK_CSR_INIT(sctl, node, BDK_SATAX_UAHC_P0_SCTL(sata));
        switch (sctl.s.spd)
        {
            case 1: return 1500;
            case 2: return 3000;
            case 3: return 6000;
            default: return 0;
        }
    }
    else
        return __bdk_qlm_get_gbaud_mhz_lmode(node, qlm);
}

/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
        return;

    /* Setup how each PEM drives the PERST lines */
    for (int pem = 0; pem < 4; pem++)
    {
        BDK_CSR_INIT(rst_ctlx, node, BDK_RST_CTLX(pem));
        __bdk_qlm_setup_pem_reset(node, pem, !rst_ctlx.s.host_mode);
    }
}

/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn83xx = {
    .chip_model = CAVIUM_CN83XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .set_mode = qlm_set_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = __bdk_qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
    .reset = __bdk_qlm_reset,
    .enable_prbs = __bdk_qlm_enable_prbs,
    .disable_prbs = __bdk_qlm_disable_prbs,
    .get_prbs_errors = __bdk_qlm_get_prbs_errors,
    .inject_prbs_error = __bdk_qlm_inject_prbs_error,
    .enable_loop = __bdk_qlm_enable_loop,
    .auto_config = bdk_qlm_mcu_auto_config,
    .tune_lane_tx = __bdk_qlm_tune_lane_tx,
    .rx_equalization = __bdk_qlm_rx_equalization,
    .eye_capture = __bdk_qlm_eye_capture_cn8xxx,
};


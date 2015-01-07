#include <bdk.h>
#include <stdio.h>

static const int REF_100MHZ = 100000000;
static const int REF_125MHZ = 125000000;
static const int REF_156MHZ = 156250000;

/* Indexed by QLM number and lane */
static uint64_t prbs_errors[14][4];

static void qlm_init_one(bdk_node_t node, int qlm);

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
        case BDK_IF_BGX:
        {
            if (interface >= 2)
                return -1;
            /* Figure out which QLM the BGX connects to */
            int qlm = interface;
#ifdef HW_EMULATOR
            return qlm;
#endif
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
#ifdef HW_EMULATOR
            return -1;
#endif
            switch (interface)
            {
                case 0: /* PEM0 */
                {
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(2));
                    if (gserx_cfg.s.pcie)
                        return 2; /* PEM0 is on QLM0 and possibly QLM2 */
                    else
                        return -1; /* PEM0 is disabled */
                }
                case 1: /* PEM1 */
                {
                    BDK_CSR_INIT(pem0_cfg, node, BDK_PEMX_CFG(0));
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(3));
                    if (!pem0_cfg.s.lanes8 && gserx_cfg.s.pcie)
                        return 3; /* PEM1 is on QLM 3 */
                    else
                        return -1; /* PEM1 is disabled */
                }
                case 2: /* PEM2 */
                {
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(4));
                    if (gserx_cfg.s.pcie)
                        return 4; /* PEM2 is on QLM2 and possibly QLM4 */
                    else
                        return -1; /* PEM2 is disabled */
                }
                case 3: /* PEM3 */
                {
                    BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(5));
                    if (!pem2_cfg.s.lanes8 && gserx_cfg.s.pcie)
                        return 5; /* PEM3 is on QLM4 */
                    else
                        return -1; /* PEM3 is disabled */
                }
                case 4: /* PEM4 */
                {
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(6));
                    if (gserx_cfg.s.pcie)
                        return 6; /* PEM4 is on QLM6 and possibly QLM7 */
                    else
                        return -1; /* PEM4 is disabled */
                }
                case 5: /* PEM5 */
                {
                    BDK_CSR_INIT(pem4_cfg, node, BDK_PEMX_CFG(4));
                    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(7));
                    if (!pem4_cfg.s.lanes8 && gserx_cfg.s.pcie)
                        return 7; /* PEM5 is on QLM7 */
                    else
                        return -1; /* PEM5 is disabled */
                }
                default: /* Max of 6 PEMs, 0-5 */
                    return -1;
            }
        }
        default: /* Not supported by CN88XX */
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
#ifdef HW_EMULATOR
        if (qlm < 2)
            return BDK_QLM_MODE_XFI_4X1;
        else
            return BDK_QLM_MODE_DISABLED;
#endif
        BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
        if (gserx_cfg.s.pcie)
        {
            switch (qlm)
            {
                case 2: /* Either PEM0 x4 or PEM0 x8 */
                case 3: /* Either PEM0 x8 or PEM1 x4 */
                {
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(0));
                    if (pemx_cfg.s.lanes8)
                        return BDK_QLM_MODE_PCIE_1X8; /* PEM0 x8 */
                    else
                        return BDK_QLM_MODE_PCIE_1X4; /* PEM0-1 x4 */
                }
                case 4: /* Either PEM2 x4 or PEM2 x8 */
                case 5: /* Either PEM2 x8 or PEM3 x4 */
                {
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(2));
                    if (pemx_cfg.s.lanes8)
                        return BDK_QLM_MODE_PCIE_1X8; /* PEM2 x8 */
                    else
                        return BDK_QLM_MODE_PCIE_1X4; /* PEM2-3 x4 */
                }
                case 6: /* Either PEM4 x8 or PEM4 x4 */
                case 7: /* Either PEM4 x8 or PEM5 x4 */
                {
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(4));
                    if (pemx_cfg.s.lanes8)
                        return BDK_QLM_MODE_PCIE_1X8; /* PEM4 x8 */
                    else
                        return BDK_QLM_MODE_PCIE_1X4; /* PEM4-5 x4 */
                }
                default: /* QLMs 0-1 can't be PCIe */
                    return BDK_QLM_MODE_DISABLED;
            }
        }
        else if (gserx_cfg.s.ila)
            return BDK_QLM_MODE_ILK;
        else if (gserx_cfg.s.sata)
        {
            /* Hardcode SATA to QLM mapping for CN88XX */
            int sata = (qlm >= 6) ? 8 + (qlm-6) * 4 : (qlm-2) * 4;
            BDK_CSR_INIT(uctl_ctl, node, BDK_SATAX_UCTL_CTL(sata));
            if (uctl_ctl.s.a_clk_en && !uctl_ctl.s.a_clkdiv_rst)
                return BDK_QLM_MODE_SATA_4X1;
            else
                return BDK_QLM_MODE_DISABLED;
        }
        else if (gserx_cfg.s.bgx)
        {
            if (qlm >= 2)
                return BDK_QLM_MODE_DISABLED;
            int bgx_block = qlm;
            BDK_CSR_INIT(cmrx_config, node, BDK_BGXX_CMRX_CONFIG(bgx_block, 0));
            BDK_CSR_INIT(spux_br_pmd_control, node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, 0));
            switch (cmrx_config.s.lmac_type)
            {
                case 0x0: return BDK_QLM_MODE_SGMII;
                case 0x1: return BDK_QLM_MODE_XAUI_1X4; /* Doesn't differentiate between XAUI and DXAUI */
                case 0x2: return BDK_QLM_MODE_RXAUI_2X2;
                case 0x3:
                    /* Use training to determine if we're in 10GBASE-KR or XFI */
                    if (spux_br_pmd_control.s.train_en)
                        return BDK_QLM_MODE_10G_KR_4X1;
                    else
                        return BDK_QLM_MODE_XFI_4X1;
                case 0x4:
                    /* Use training to determine if we're in 40GBASE-KR4 or XLAUI */
                    if (spux_br_pmd_control.s.train_en)
                        return BDK_QLM_MODE_40G_KR4_1X4;
                    else
                        return BDK_QLM_MODE_XLAUI_1X4;
                default:  return BDK_QLM_MODE_DISABLED;
            }
        }
        else
            return BDK_QLM_MODE_DISABLED;
    }
    else
        return BDK_QLM_MODE_OCI;
}

/**
 * Figure out which lane mode to use for a given reference clock and GBaud
 *
 * @param mode_name String name for error messages
 * @param qlm       QlM being configured
 * @param ref_clk   Reference clock in hertz
 * @param baud_mhz  Baud rate in Mhz
 *
 * @return Lane mode or -1 on failure
 */
static int get_lane_mode_for_speed_and_ref_clk(const char *mode_name, int qlm, int ref_clk, int baud_mhz)
{
    if (baud_mhz <= 1250)
    {
        /* FIXME: What about GSER_LMODE_E_R_125G_REFCLK15625_KX? */
        if (ref_clk == REF_156MHZ)
            return GSER_LMODE_E_R_125G_REFCLK15625_SGMII;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 2500)
    {
        if (ref_clk == REF_100MHZ)
            return GSER_LMODE_E_R_25G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return GSER_LMODE_E_R_25G_REFCLK125;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 3125)
    {
        if (ref_clk == REF_156MHZ)
            return GSER_LMODE_E_R_3125G_REFCLK15625_XAUI;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 5000)
    {
        if (ref_clk == REF_100MHZ)
            return GSER_LMODE_E_R_5G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return GSER_LMODE_E_R_5G_REFCLK125;
        else
            return GSER_LMODE_E_R_5G_REFCLK15625_QSGMII;
    }
    else if (baud_mhz <= 6250)
    {
        if (ref_clk == REF_156MHZ)
            return GSER_LMODE_E_R_625G_REFCLK15625_RXAUI;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 8000)
    {
        if (ref_clk == REF_100MHZ)
            return GSER_LMODE_E_R_8G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return GSER_LMODE_E_R_8G_REFCLK125;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else /* Baud 10312.5 */
    {
        if (ref_clk == REF_156MHZ)
            return GSER_LMODE_E_R_103125G_REFCLK15625_KR;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    bdk_error("Invalid speed for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
    return -1;
}

/**
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param node   Node to use in a Numa setup
 * @param pem    Which PEM to setuo
 * @param is_endpoint
 *               Non zero if PEM is a EP
 */
static void setup_pem_reset(bdk_node_t node, int pem, int is_endpoint)
{
    /* Make sure is_endpoint is either 0 or 1 */
    is_endpoint = (is_endpoint != 0);
    BDK_CSR_MODIFY(c, node, BDK_RST_CTLX(pem),
        c.s.prst_link = 0;          /* Link down causes soft reset */
        c.s.rst_link = 0;           /* EP PERST causes a soft reset */
        c.s.rst_drv = !is_endpoint; /* Drive if RC */
        c.s.rst_rcv = is_endpoint;  /* Only read PERST in EP mode */
        c.s.rst_chip = 0);          /* PERST doesn't pull CHIP_RESET */
}

static int qlm_set_sata(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags)
{
    const int MAX_A_CLK = 333000000; /* Max of 333Mhz */

    /* SATA hasa fixed mapping for ports on CN88XX */
    int sata_port;
    switch (qlm)
    {
        case 2: /* SATA 0-3 = QLM2 lanes 0-3 */
            sata_port = 0;
            break;
        case 3: /* SATA 4-7 = QLM3 lanes 0-3 */
            sata_port = 4;
            break;
        case 6: /* SATA 8-11 = QLM6 lanes 0-3 */
            sata_port = 8;
            break;
        case 7: /* SATA 12-15 = QLM7 lanes 0-3 */
            sata_port = 12;
            break;
        default:
            bdk_error("Attempted to configure SATA on QLM that doesn't support it\n");
            return -1;
    }
    int sata_port_end = sata_port + 4;

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
        a_clkdiv = divisor - 1;
    else if (divisor <= 6)
        a_clkdiv = 4;
    else if (divisor <= 8)
        a_clkdiv = 5;
    else if (divisor <= 16)
        a_clkdiv = 6;
    else if (divisor <= 24)
        a_clkdiv = 7;
    else
    {
        bdk_error("Unable to determine SATA clock divisor\n");
        return -1;
    }

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
    for (int lane=0; lane<4; lane++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_MISC_CFG_0(qlm, lane),
            c.s.eie_det_stl_on_time = 4);
    }

    /* 7. Modify the PLL and lane-protocol-mode registers to configure the
       PHY for SATA:
        Set GSER(0..13)_PLL_P0_MODE_0[PLL_ICP] = 0x1
        Set GSER(0..13)_PLL_P0_MODE_0[PLL_RLOOP] = 0x3
        Set GSER(0..13)_PLL_P0_MODE_0[PLL_PCS_DIV] = 0x5
        Set GSER(0..13)_PLL_P1_MODE_0[PLL_ICP] = 0x1
        Set GSER(0..13)_PLL_P1_MODE_0[PLL_RLOOP] = 0x3
        Set GSER(0..13)_PLL_P1_MODE_0[PLL_PCS_DIV] = 0x5
        Set GSER(0..13)_PLL_P2_MODE_0[PLL_ICP] = 0x1
        Set GSER(0..13)_PLL_P2_MODE_0[PLL_RLOOP] = 0x3
        Set GSER(0..13)_PLL_P2_MODE_0[PLL_PCS_DIV] = 0x5
        Set GSER(0..13)_PLL_P0_MODE_1[PLL_OPR] = 0x0
        Set GSER(0..13)_PLL_P0_MODE_1[PLL_DIV] = 0x18
        Set GSER(0..13)_PLL_P1_MODE_1[PLL_OPR] = 0x0
        Set GSER(0..13)_PLL_P1_MODE_1[PLL_DIV] = 0x18
        Set GSER(0..13)_PLL_P2_MODE_1[PLL_OPR] = 0x0
        Set GSER(0..13)_PLL_P2_MODE_1[PLL_DIV] = 0x18
        Set GSER(0..13)_LANE_P0_MODE_0[TX_LDIV] = 0x0
        Set GSER(0..13)_LANE_P0_MODE_0[RX_LDIV] = 0x2
        Set GSER(0..13)_LANE_P1_MODE_0[TX_LDIV] = 0x0
        Set GSER(0..13)_LANE_P1_MODE_0[RX_LDIV] = 0x1
        Set GSER(0..13)_LANE_P2_MODE_0[TX_LDIV] = 0x0
        Set GSER(0..13)_LANE_P2_MODE_0[RX_LDIV] = 0x1 */
    for (int p=0; p<3; p++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PLL_PX_MODE_0(qlm, p),
            c.s.pll_icp = 0x1;
            c.s.pll_rloop = 0x3;
            c.s.pll_pcs_div = 0x5);
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
            c.s.cdr_fgain = 0xa;
            c.s.ph_acc_adj = 0x15);
    }

    for (int s=0; s<2; s++)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_SLICEX_RX_SDLL_CTRL(qlm, s),
            c.s.pcs_sds_oob_clk_ctrl  = 2;
            c.s.pcs_sds_rx_sdll_tune  = 0;
            c.s.pcs_sds_rx_sdll_swsel = 0);
    }

    for (int p=0; p<4; p++)
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

    /* 8. Wait for GSER(0..13)_QLM_STAT[RST_RDY] = 1, indicating that the PHY
       has been reconfigured and PLLs are locked. */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_QLM_STAT(qlm), rst_rdy, ==, 1, 10000))
    {
        bdk_error("QLM%d: Timeout waiting for GSERX_QLM_STAT[rst_rdy]\n", qlm);
        return -1;
    }

    /* 9. Clear the appropriate lane resets:
       GSER(0..13)_SATA_LANE_RST[Ln_RST] = 0, where n is the lane number 0-3. */
    BDK_CSR_WRITE(node, BDK_GSERX_SATA_LANE_RST(qlm), 0);
    BDK_CSR_READ(node, BDK_GSERX_SATA_LANE_RST(qlm));

    /* Poll GSERX_SATA_STATUS for PX_RDY = 1 */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_SATA_STATUS(qlm), p0_rdy, ==, 1, 10000))
    {
        bdk_error("QLM%d: Timeout waiting for GSERX_SATA_STATUS[p0_rdy]\n", qlm);
        return -1;
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
#ifdef HW_EMULATOR
    return -1;
#endif
    int lane_mode = 0xf;
    int lmac_type = -1;
    int is_pcie = 0;
    int is_sata = 0;
    int is_ilk = 0;
    int is_bgx = 0;
    int bgx_block = (qlm < 2) ? qlm : -1;

    /* Disable QLMs that are affected by the QLM we're working on */
    switch (qlm)
    {
        case 2:
        case 4:
        case 6:
            /* When reconfiguring QLM that are the first of 8 pcie lanes, disable the
               second set as their config will change too */
            if ((mode != BDK_QLM_MODE_PCIE_1X8) &&
                (qlm_get_mode(node, qlm + 1) == BDK_QLM_MODE_PCIE_1X8))
                BDK_CSR_WRITE(node, BDK_GSERX_CFG(qlm + 1), 0);
            break;
        case 3:
        case 5:
        case 7:
            /* When reconfiguring QLM that are the second of 8 pcie lanes, disable the
               first set as their config will change too */
            if ((mode != BDK_QLM_MODE_PCIE_1X8) &&
                (qlm_get_mode(node, qlm - 1) == BDK_QLM_MODE_PCIE_1X8))
                BDK_CSR_WRITE(node, BDK_GSERX_CFG(qlm - 1), 0);
            break;
    }

    int measured_ref = bdk_qlm_measure_clock(node, qlm);
    int ref_clk;
    if ((measured_ref > REF_100MHZ - REF_100MHZ / 10) && (measured_ref < REF_100MHZ + REF_100MHZ / 10))
    {
        ref_clk = REF_100MHZ;
    }
    else if ((measured_ref > REF_125MHZ - REF_125MHZ / 10) && (measured_ref < REF_125MHZ + REF_125MHZ / 10))
    {
        ref_clk = REF_125MHZ;
    }
    else if ((measured_ref > REF_156MHZ - REF_156MHZ / 10) && (measured_ref < REF_156MHZ + REF_156MHZ / 10))
    {
        ref_clk = REF_156MHZ;
    }
    else if (mode == BDK_QLM_MODE_DISABLED)
    {
        /* Don't care about the ref clock, just make up one */
        ref_clk = REF_100MHZ;
    }
    else
    {
        ref_clk = measured_ref;
        bdk_error("N%d.QLM%d: Unexpected reference clock speed of %d Mhz\n", node, qlm, measured_ref / 1000000);
    }

    switch (mode)
    {
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
                    lane_mode = GSER_LMODE_E_R_25G_REFCLK100;
                else if (baud_mhz == 5000)
                    lane_mode = GSER_LMODE_E_R_5G_REFCLK100;
                else
                    lane_mode = GSER_LMODE_E_R_8G_REFCLK100;
            }
            else if (ref_clk == REF_125MHZ)
            {
                BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_SEL(qlm),
                    c.s.pcie_refclk125 = 1);
                if (baud_mhz == 2500)
                    lane_mode = GSER_LMODE_E_R_25G_REFCLK125;
                else if (baud_mhz == 5000)
                    lane_mode = GSER_LMODE_E_R_5G_REFCLK125;
                else
                    lane_mode = GSER_LMODE_E_R_8G_REFCLK125;
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
                case 2: /* Either x4 or x8 based on PEM0 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(0),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    setup_pem_reset(node, 0, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(0),
                        c.s.lanes8 = (mode == BDK_QLM_MODE_PCIE_1X8);
                        //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    /* x8 mode waits for QLM1 setup before turning on the PEM */
                    if (mode == BDK_QLM_MODE_PCIE_1X4)
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(0),
                            c.s.pemon = 1);
                    break;
                case 3: /* Either PEM0 x8 or PEM1 x4 */
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
                        setup_pem_reset(node, 1, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(0),
                            c.s.lanes8 = 0);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(1),
                            c.s.lanes8 = 0;
                            //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                            c.s.md = cfg_md);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(1),
                            c.s.pemon = 1);
                    }
                    break;
                case 4: /* Either PEM2 x4 or PEM2 x8 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(2),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    setup_pem_reset(node, 2, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(2),
                        c.s.lanes8 = (mode == BDK_QLM_MODE_PCIE_1X8);
                        //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    /* x8 mode waits for QLM3 setup before turning on the PEM */
                    if (mode == BDK_QLM_MODE_PCIE_1X4)
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2),
                            c.s.pemon = 1);
                    break;
                case 5: /* Either PEM2 x8, or PEM3 x4 */
                {
                    if (mode == BDK_QLM_MODE_PCIE_1X8)
                    {
                        /* Last 4 lanes of PEM2 */
                        /* PEMX_CFG already setup */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2),
                            c.s.pemon = 1);
                    }
                    else
                    {
                        /* Four lanes of PEM3 */
                        BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(3),
                            c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                        setup_pem_reset(node, 3, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(2),
                            c.s.lanes8 = 0);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(3),
                            c.s.lanes8 = 0;
                            //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                            c.s.md = cfg_md);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(3),
                            c.s.pemon = 1);
                    }
                    break;
                }
                case 6: /* Either PEM4 x4 or PEM4 x8 */
                    BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(4),
                        c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                    setup_pem_reset(node, 4, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                    BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(4),
                        c.s.lanes8 = (mode == BDK_QLM_MODE_PCIE_1X8);
                        //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        c.s.md = cfg_md);
                    /* x8 mode waits for QLM1 setup before turning on the PEM */
                    if (mode == BDK_QLM_MODE_PCIE_1X4)
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(4),
                            c.s.pemon = 1);
                    break;
                case 7: /* PEM4 x8 */
                    if (mode == BDK_QLM_MODE_PCIE_1X8)
                    {
                        /* Last 4 lanes of PEM4 */
                        /* PEMX_CFG already setup */
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(4),
                            c.s.pemon = 1);
                    }
                    else
                    {
                        /* Four lanes of PEM5 */
                        BDK_CSR_MODIFY(c, node, BDK_RST_SOFT_PRSTX(5),
                            c.s.soft_prst = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT));
                        setup_pem_reset(node, 5, flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(4),
                            c.s.lanes8 = 0);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(5),
                            c.s.lanes8 = 0;
                            //c.s.hostmd = !(flags & BDK_QLM_MODE_FLAG_ENDPOINT);
                            c.s.md = cfg_md);
                        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(5),
                            c.s.pemon = 1);
                    }
                    break;
                default:
                    return -1;
            }
            break;
        }
        case BDK_QLM_MODE_ILK:
            is_ilk = 1;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("ILK", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_SATA_4X1:
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_MODE(qlm), c.s.lmode = GSER_LMODE_E_R_8G_REFCLK100);
            /* SATA initialization is different than BGX. Call its init function
               and skip the rest of this routine */
            return qlm_set_sata(node, qlm, mode, baud_mhz, flags);
        case BDK_QLM_MODE_SGMII:
            lmac_type = 0; /* SGMII */
            is_bgx = 1;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("SGMII", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            lmac_type = 1; /* XAUI */
            is_bgx = 5;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("XAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            lmac_type = 2; /* RXAUI */
            is_bgx = 3;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("RXAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            break;
        case BDK_QLM_MODE_XFI_4X1:
            lmac_type = 3; /* 10G_R */
            is_bgx = 1;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("XFI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            /* Disable training. We use this to tell the difference between 10GBASE-KR and XFI */
            BDK_CSR_MODIFY(c, node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, 0), c.s.train_en = 0);
            break;
        case BDK_QLM_MODE_XLAUI_1X4:
            lmac_type = 4; /* 40G_R */
            is_bgx = 5;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("XLAUI", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            /* Disable training. We use this to tell the difference between 40GBASE-KR4 and XLAUI */
            BDK_CSR_MODIFY(c, node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, 0), c.s.train_en = 0);
            break;
        case BDK_QLM_MODE_10G_KR_4X1:
            lmac_type = 3; /* 10G_R */
            is_bgx = 1;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("10G-KR", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            /* Enable training. We use this to tell the difference between 10GBASE-KR and XFI */
            BDK_CSR_MODIFY(c, node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, 0), c.s.train_en = 1);
            break;
        case BDK_QLM_MODE_40G_KR4_1X4:
            lmac_type = 4; /* 40G_R */
            is_bgx = 5;
            lane_mode = get_lane_mode_for_speed_and_ref_clk("40G-KR", qlm, ref_clk, baud_mhz);
            if (lane_mode == -1)
                return -1;
            /* Enable training. We use this to tell the difference between 40GBASE-KR4 and XLAUI */
            BDK_CSR_MODIFY(c, node, BDK_BGXX_SPUX_BR_PMD_CONTROL(bgx_block, 0), c.s.train_en = 1);
            break;
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
        BDK_CSR_MODIFY(c, node, BDK_BGXX_CMRX_CONFIG(bgx_block, 0),
            c.s.enable = 0;
            c.s.lmac_type = lmac_type);
    }

    /* Bring phy out of reset */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 0);

    /* Wait 250 ns until the management interface is ready to accept
       read/write commands.*/
    bdk_wait_usec(1);

    /* Configure the gser pll */
    qlm_init_one(node, qlm);

    if (!bdk_is_simulation())
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

    /* If we're setting up the first QLM of a PCIe x8 interface, go ahead and
       setup the other inteface automatically */
    if (mode == BDK_QLM_MODE_PCIE_1X8)
    {
        switch (qlm)
        {
            case 2:
            case 4:
            case 6:
                return bdk_qlm_set_mode(node, qlm + 1, mode, baud_mhz, flags);
        }
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
#ifdef HW_EMULATOR
    return 10312;
#endif
    if (qlm < 8)
    {
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
                case 2: /* Either PEM0 x4 or PEM0 x8 */
                    pem = 0;
                    break;
                case 3: /* Either PEM0 x8 or PEM1 x4 */
                {
                    BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(0));
                    if (pemx_cfg.s.lanes8)
                        pem = 0;
                    else
                        pem = 1;
                    break;
                }
                case 4: /* Either PEM2 x4 or PEM2 x8 */
                    pem = 2;
                    break;
                case 5: /* Either PEM2 x8 or PEM 3 x4 */
                {
                    /* Can be last 4 lanes of PEM2 */
                    BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
                    if (pem2_cfg.s.lanes8)
                        pem = 2;
                    else
                        pem = 3;
                    break;
                }
                case 6: /* Either PEM4 x8 or PEM4 x4 */
                    pem = 4;
                    break;
                case 7: /* Either PEM4 x8 or PEm5 x4 */
                {
                    /* Can be last 4 lanes of PEM4 */
                    BDK_CSR_INIT(pem4_cfg, node, BDK_PEMX_CFG(4));
                    if (pem4_cfg.s.lanes8)
                        pem = 4;
                    else
                        pem = 5;
                    break;
                }
                default:
                    bdk_fatal("QLM%d: In PCIe mode, which shouldn't happen\n", qlm);
            }
            BDK_CSR_INIT(pem_cfg, node, BDK_PEMX_CFG(pem));
            switch (pem_cfg.s.md)
            {
                case 0: /* Gen 1 */
                    return 2500;
                case 1: /* Gen 2 */
                    return 5000;
                case 2: /* Gen 3 */
                    return 8000;
                default:
                    return 0;
            }
        }
        else if (gserx_cfg.s.sata)
        {
            int sata;
            switch (qlm)
            {
                case 2:
                    sata = 0;
                    break;
                case 3:
                    sata = 4;
                    break;
                case 6:
                    sata = 8;
                    break;
                case 7:
                    sata = 12;
                    break;
                default:
                    return 0;
            }
            BDK_CSR_INIT(uctl_ctl, node, BDK_SATAX_UCTL_CTL(sata));
            if (!uctl_ctl.s.a_clk_en || uctl_ctl.s.a_clkdiv_rst)
                return 0;
            BDK_CSR_INIT(sctl, node, BDK_SATAX_UAHC_P0_SCTL(sata));
            switch (sctl.s.spd)
            {
                case 1:
                    return 1500;
                case 2:
                    return 3000;
                case 3:
                    return 6000;
                default:
                    return 0;
            }
        }
        else
        {
            /* QLM is not in PCIe, assume LMODE is good enough for determining
               the speed */
            BDK_CSR_INIT(lane_mode, node, BDK_GSERX_LANE_MODE(qlm));
            switch (lane_mode.s.lmode)
            {
                case GSER_LMODE_E_R_25G_REFCLK100:
                    return 2500;
                case GSER_LMODE_E_R_5G_REFCLK100:
                    return 5000;
                case GSER_LMODE_E_R_8G_REFCLK100:
                    return 8000;
                case GSER_LMODE_E_R_125G_REFCLK15625_KX:
                    return 1250;
                case GSER_LMODE_E_R_3125G_REFCLK15625_XAUI:
                    return 3125;
                case GSER_LMODE_E_R_103125G_REFCLK15625_KR:
                    return 10312;
                case GSER_LMODE_E_R_125G_REFCLK15625_SGMII:
                    return 1250;
                case GSER_LMODE_E_R_5G_REFCLK15625_QSGMII:
                    return 5000;
                case GSER_LMODE_E_R_625G_REFCLK15625_RXAUI:
                    return 6250;
                case GSER_LMODE_E_R_25G_REFCLK125:
                    return 2500;
                case GSER_LMODE_E_R_5G_REFCLK125:
                    return 5000;
                case GSER_LMODE_E_R_8G_REFCLK125:
                    return 8000;
                default:
                    return 0;
            }
        }
    }
    else
    {
        /* Use the OCI strapping to find the speed. This will not work if
           the OCI is in SW_MODE */
        BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(qlm));
        switch (gserx_spd.s.spd)
        {
            case 0x0: return 1250; /* Ref 100Mhz */
            case 0x1: return 2500;
            case 0x2: return 5000;
            case 0x3: return 8000;
            case 0x4: return 1250; /* Ref 125Mhz */
            case 0x5: return 2500;
            case 0x6: return 3125;
            case 0x7: return 5000;
            case 0x8: return 6250;
            case 0x9: return 8000;
            case 0xa: return 2500; /* Ref 156.25Mhz */
            case 0xb: return 3125;
            case 0xc: return 5000;
            case 0xd: return 6250;
            case 0xe: return 10312;
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
#ifdef HW_EMULATOR
    return REF_156MHZ;
#endif
    /* Clear the counter */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_EVT_CTRL(qlm),
        c.s.enb = 0;
        c.s.clr = 1);
    bdk_wait_usec(1); /* Give counter a chance to clear */
    if (BDK_CSR_READ(node, BDK_GSERX_REFCLK_EVT_CNTR(qlm)))
        bdk_error("GSER%d: Ref clock counter not zero\n", qlm);
    /* Start counting */
    uint64_t start = bdk_clock_get_count(BDK_CLOCK_TIME);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_EVT_CTRL(qlm),
        c.s.enb = 1;
        c.s.clr = 0);
    /* Wait for a short time to get a number of counts */
    bdk_wait_usec(10000); /* 10ms */
    /* Stop counting */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_EVT_CTRL(qlm),
        c.s.enb = 0);
    uint64_t stop = bdk_clock_get_count(BDK_CLOCK_TIME);
    bdk_wait_usec(1); /* Give counter a chance to stabalize */

    /* Calculate the rate */
    uint64_t count = BDK_CSR_READ(node, BDK_GSERX_REFCLK_EVT_CNTR(qlm));
    count *= bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME);
    count /= stop - start;
    return count;
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
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 1);
    return 0;
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
    const int NUM_LANES = 4;
    int mode;
    switch (prbs)
    {
        case 31:
            mode = 1;
            break;
        case 23:
            mode = 2; /* Or 3? */
            break;
        case 16:
            mode = 4;
            break;
        case 15:
            mode = 5;
            break;
        case 11:
            mode = 6;
            break;
        case 7:
            mode = 7;
            break;
        default:
            mode = prbs & 0xff;
            for (int lane = 0; lane < NUM_LANES; lane++)
                BDK_CSR_WRITE(node, BDK_GSERX_LANEX_LBERT_PAT_CFG(qlm, lane), prbs >> 8);
            BDK_TRACE(QLM, "Using mode 0x%x with custom pattern 0x%x\n", mode, prbs >> 8);
            return -1;
    }

    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHY_CTL(qlm),
        c.s.phy_reset = 0);

    if (dir & BDK_QLM_DIRECTION_TX)
    {
        /* Disable first in case already running */
        for (int lane = 0; lane < NUM_LANES; lane++)
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
                c.s.lbert_pg_en = 0);
        for (int lane = 0; lane < NUM_LANES; lane++)
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
                c.s.lbert_pg_en = 1; /* Enable generator */
                c.s.lbert_pg_width = 3; /* 20 bit */
                c.s.lbert_pg_mode = mode);
    }

    if (dir & BDK_QLM_DIRECTION_RX)
    {
        /* Clear the error counter and Disable the matcher */
        for (int lane = 0; lane < NUM_LANES; lane++)
        {
            prbs_errors[qlm][lane] = 0;
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
                c.s.lbert_pm_en = 0);
        }
        for (int lane = 0; lane < NUM_LANES; lane++)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
                c.s.lbert_pm_en = 1; /* Enable matcher */
                c.s.lbert_pm_width = 3; /* 20 bit */
                c.s.lbert_pm_mode = mode);
        }
        /* Tell the matcher to start sync */
        for (int retry=0; retry < 4; retry++)
        {
            for (int lane = 0; lane < NUM_LANES; lane++)
            {
                BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
                    c.s.lbert_pm_sync_start = 1);
            }
            /* Wait 10ms */
            bdk_wait_usec(10000);
        }
    }
    return 0;
}

/**
 * Return the number of PRBS errors since PRBS started running
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 * @param clear  Clear counter after return the current value
 *
 * @return Number of errors
 */
static uint64_t qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane, int clear)
{
    /* Restart synchronization */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
        c.s.lbert_pm_sync_start = 1);
    /* This CSR is self clearing per the CSR description, but it doesn't
       seem to do that. Instead it clears when we trigger sync again */
    BDK_CSR_INIT(rx, node, BDK_GSERX_LANEX_LBERT_ECNT(qlm, lane));
    uint64_t errors = rx.s.lbert_err_cnt;
    if (rx.s.lbert_err_ovbit14)
        errors <<= 7;
    prbs_errors[qlm][lane] += errors;
    uint64_t result = prbs_errors[qlm][lane];
    if (clear)
        prbs_errors[qlm][lane] = 0;
    return result;
}

/**
 * Inject an error into PRBS
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 */
static void qlm_inject_prbs_error(bdk_node_t node, int qlm, int lane)
{
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
        c.s.lbert_pg_err_insert = 1);
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
    bdk_error("CN88XX doesn't support shallow QLM loopback\n");
    return -1;
}

/**
 * Call the board specific method of determining the required QLM configuration
 * and automatically settign up the QLMs to match. For example, on the EBB8800
 * this function queries the MCU for the current setup.
 *
 * @param node   Node to configure
 *
 * @return Zero on success, negative on failure
 */
int qlm_auto_config(bdk_node_t node)
{
#ifdef HW_EMULATOR
    return 0;
#endif
    if (bdk_is_simulation())
    {
        printf("QLM Config: Configuring QLMs for a sample setup\n");
        bdk_qlm_set_mode(node, 0, BDK_QLM_MODE_SGMII, 1250, 0);
        bdk_qlm_set_mode(node, 1, BDK_QLM_MODE_XAUI_1X4, 6250, 0);
        bdk_qlm_set_mode(node, 2, BDK_QLM_MODE_PCIE_1X8, 8000, 0);
        bdk_qlm_set_mode(node, 4, BDK_QLM_MODE_PCIE_1X4, 5000, 0);
        bdk_qlm_set_mode(node, 5, BDK_QLM_MODE_PCIE_1X4, 2500, 0);
        bdk_qlm_set_mode(node, 6, BDK_QLM_MODE_SATA_4X1, 6000, 0);
        bdk_qlm_set_mode(node, 7, BDK_QLM_MODE_SATA_4X1, 3000, 0);
        return 0;
    }

    const int MCU_TWSI_BUS = 0;
    const int MCU_TWSI_ADDRESS = 0x60;
    int64_t data;

    /* Check the two magic number bytes the MCU should return */
    data = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x00, 1, 1);
    if (data != 0xa5)
    {
        printf("QLM Config: MCU not found, skipping auto configuration\n");
        return -1;
    }
    data = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x01, 1, 1);
    if (data != 0x5a)
    {
        bdk_error("QLM Config: MCU magic number incorrect\n");
        return -1;
    }

    /* Read the MCU version */
    int mcu_major = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x02, 1, 1);
    int mcu_minor = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x03, 1, 1);
    BDK_TRACE(QLM, "MCU version %d.%d\n", mcu_major, mcu_minor);
    if ((mcu_major < 2) || ((mcu_major == 2) && (mcu_minor < 30)))
    {
        bdk_error("QLM Config: Unexpected MCU version %d.%d\n", mcu_major, mcu_minor);
        return -1;
    }

    /* Find out how many lanes the MCU thinks are available */
    int lanes = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x16, 1, 1);
    BDK_TRACE(QLM, "MCU says board has %d lanes\n", lanes);
    if (lanes != 32)
    {
        bdk_error("QLM Config: Unexpected number of lanes (%d) from MCU\n", lanes);
        return -1;
    }

    int lane = 0;
    int qlm = 0;
    while (lane < lanes)
    {
        /* Select the lane we are interested in */
        bdk_twsix_write_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x16, 1, 1, lane);
        /* Get the mode */
        int width = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x17, 1, 1);
        int mode = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x18, 2, 1);
        int speed = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x19, 2, 1);
        int refclk = bdk_twsix_read_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x1a, 1, 1);
        BDK_TRACE(QLM, "MCU lane %d, width %d, mode 0x%x, speed 0x%x, ref 0x%x\n",
            lane, width, mode, speed, refclk);
        if ((width != 0) && (width != 4) && (width != 8))
        {
            bdk_error("QLM Config: Unexpected interface width (%d) from MCU\n", width);
            return -1;
        }
        /* MCU reports a width of 0 for unconfigured QLMs */
        if (width == 0)
            width = bdk_qlm_get_lanes(node, qlm);
        bdk_qlm_modes_t qlm_mode;
        int qlm_speed = (speed >> 8) * 1000 + (speed & 0xff) * 1000 / 256;
        bdk_qlm_mode_flags_t qlm_flags = 0;
        switch (mode)
        {
            case 0x0000: /* No Configuration */
                qlm_mode = BDK_QLM_MODE_DISABLED;
                break;
            case 0x0101: /* PCIe Host */
                qlm_mode = (width == 8) ? BDK_QLM_MODE_PCIE_1X8 : BDK_QLM_MODE_PCIE_1X4;
                break;
            case 0x1000: /* SGMII */
                qlm_mode = BDK_QLM_MODE_SGMII;
                break;
            case 0x2000: /* XAUI */
                qlm_mode = BDK_QLM_MODE_XAUI_1X4;
                break;
            case 0x2100: /* RXAUI */
                qlm_mode = BDK_QLM_MODE_RXAUI_2X2;
                break;
            case 0x2200: /* DXAUI */
                qlm_mode = BDK_QLM_MODE_XAUI_1X4;
                break;
            case 0x4000: /* SATA */
                qlm_mode = BDK_QLM_MODE_SATA_4X1;
                break;
            case 0x5001: /* XFI */
                qlm_mode = BDK_QLM_MODE_XFI_4X1;
                break;
            case 0x5002: /* 10G-KR */
                qlm_mode = BDK_QLM_MODE_10G_KR_4X1;
                break;
            case 0x6001: /* XLAUI */
                qlm_mode = BDK_QLM_MODE_XLAUI_1X4;
                break;
            case 0x6002: /* 40G-KR4 */
                qlm_mode = BDK_QLM_MODE_40G_KR4_1X4;
                break;
            case 0x1100: /* QSGMII */
            case 0x0102: /* PCIe Endpoint */
            case 0x3001: /* Interlaken */
            case 0x3002: /* Interlaken Look-Aside */
            case 0x7000: /* SRIO */
            default:
                bdk_error("QLM Config: Unexpected interface mode (0x%x) from MCU\n", mode);
                qlm_mode = BDK_QLM_MODE_DISABLED;
                break;
        }
        BDK_TRACE(QLM, "Setting QLM%d mode %d, speed %d, flags 0x%x\n",
            qlm, qlm_mode, qlm_speed, qlm_flags);
        if (bdk_qlm_set_mode(node, qlm, qlm_mode, qlm_speed, qlm_flags))
            return -1;
        lane += width;
        qlm += width / 4;
    }
    return 0;
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
        BDK_CSR_INIT(pll_mode_0 , node, BDK_GSERX_PLL_PX_MODE_0(qlm, lane_mode));
        BDK_CSR_INIT(pll_mode_1 , node, BDK_GSERX_PLL_PX_MODE_1(qlm, lane_mode));
        BDK_CSR_INIT(lane_mode_0, node, BDK_GSERX_LANE_PX_MODE_0(qlm, lane_mode));
        BDK_CSR_INIT(lane_mode_1, node, BDK_GSERX_LANE_PX_MODE_1(qlm, lane_mode));
        switch (lane_mode)
        {
            case GSER_LMODE_E_R_25G_REFCLK100:
            case GSER_LMODE_E_R_5G_REFCLK100:
            case GSER_LMODE_E_R_8G_REFCLK100:
                /* These modes are used for PCIe where the defaults are
                   correct. Skip programming these */
                continue;
            case GSER_LMODE_E_R_125G_REFCLK15625_KX:
                pll_mode_0.s.pll_icp = 0x1;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0x28;

                pll_mode_1.s.pll_16p5en = 0x1;
                pll_mode_1.s.pll_cpadj = 0x3;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x10;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x2;
                lane_mode_0.s.rx_ldiv = 0x2;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x1;
                lane_mode_1.s.cdr_fgain = 0xc;
                lane_mode_1.s.ph_acc_adj = 0x1e;
                break;
            case GSER_LMODE_E_R_3125G_REFCLK15625_XAUI:
                pll_mode_0.s.pll_icp = 0x1;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0x14;

                pll_mode_1.s.pll_16p5en = 0x1;
                pll_mode_1.s.pll_cpadj = 0x2;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x14;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x1;
                lane_mode_0.s.rx_ldiv = 0x1;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x1;
                lane_mode_1.s.cdr_fgain = 0xc;
                lane_mode_1.s.ph_acc_adj = 0x1e;
                break;
            case GSER_LMODE_E_R_103125G_REFCLK15625_KR:
                pll_mode_0.s.pll_icp = 0x1;
                pll_mode_0.s.pll_rloop = 0x5;
                pll_mode_0.s.pll_pcs_div = 0xa;

                pll_mode_1.s.pll_16p5en = 0x1;
                pll_mode_1.s.pll_cpadj = 0x2;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x1;
                pll_mode_1.s.pll_div = 0x21;

                lane_mode_0.s.ctle = 0x3;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x0;
                lane_mode_0.s.rx_ldiv = 0x0;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x1;
                lane_mode_1.s.vma_mm = 0x0;
                lane_mode_1.s.cdr_fgain = 0xa;
                lane_mode_1.s.ph_acc_adj = 0xf;
                break;
            case GSER_LMODE_E_R_125G_REFCLK15625_SGMII:
                pll_mode_0.s.pll_icp = 0x1;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0x28;

                pll_mode_1.s.pll_16p5en = 0x1;
                pll_mode_1.s.pll_cpadj = 0x3;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x10;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x2;
                lane_mode_0.s.rx_ldiv = 0x2;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x1;
                lane_mode_1.s.cdr_fgain = 0xc;
                lane_mode_1.s.ph_acc_adj = 0x1e;
                break;
            case GSER_LMODE_E_R_5G_REFCLK15625_QSGMII:
                pll_mode_0.s.pll_icp = 0x3;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0xa;

                pll_mode_1.s.pll_16p5en = 0x0;
                pll_mode_1.s.pll_cpadj = 0x2;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x10;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x0;
                lane_mode_0.s.rx_ldiv = 0x0;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x1;
                lane_mode_1.s.cdr_fgain = 0xc;
                lane_mode_1.s.ph_acc_adj = 0x1e;
                break;
            case GSER_LMODE_E_R_625G_REFCLK15625_RXAUI:
                pll_mode_0.s.pll_icp = 0x1;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0xa;

                pll_mode_1.s.pll_16p5en = 0x0;
                pll_mode_1.s.pll_cpadj = 0x2;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x14;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x0;
                lane_mode_0.s.rx_ldiv = 0x0;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x0;
                lane_mode_1.s.cdr_fgain = 0xa;
                lane_mode_1.s.ph_acc_adj = 0x14;
                break;
            case GSER_LMODE_E_R_25G_REFCLK125:
                pll_mode_0.s.pll_icp = 0x3;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0x5;

                pll_mode_1.s.pll_16p5en = 0x0;
                pll_mode_1.s.pll_cpadj = 0x1;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x14;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x1;
                lane_mode_0.s.tx_ldiv = 0x1;
                lane_mode_0.s.rx_ldiv = 0x1;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x1;
                lane_mode_1.s.cdr_fgain = 0xa;
                lane_mode_1.s.ph_acc_adj = 0x14;
                break;
            case GSER_LMODE_E_R_5G_REFCLK125:
                pll_mode_0.s.pll_icp = 0x3;
                pll_mode_0.s.pll_rloop = 0x3;
                pll_mode_0.s.pll_pcs_div = 0xa;

                pll_mode_1.s.pll_16p5en = 0x0;
                pll_mode_1.s.pll_cpadj = 0x1;
                pll_mode_1.s.pll_pcie3en = 0x0;
                pll_mode_1.s.pll_opr = 0x0;
                pll_mode_1.s.pll_div = 0x14;

                lane_mode_0.s.ctle = 0x0;
                lane_mode_0.s.pcie = 0x1;
                lane_mode_0.s.tx_ldiv = 0x0;
                lane_mode_0.s.rx_ldiv = 0x0;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x0;
                lane_mode_1.s.cdr_fgain = 0xa;
                lane_mode_1.s.ph_acc_adj = 0x14;
                break;
            case GSER_LMODE_E_R_8G_REFCLK125:
                pll_mode_0.s.pll_icp = 0x2;
                pll_mode_0.s.pll_rloop = 0x5;
                pll_mode_0.s.pll_pcs_div = 0xa;

                pll_mode_1.s.pll_16p5en = 0x0;
                pll_mode_1.s.pll_cpadj = 0x1;
                pll_mode_1.s.pll_pcie3en = 0x1;
                pll_mode_1.s.pll_opr = 0x1;
                pll_mode_1.s.pll_div = 0x20;

                lane_mode_0.s.ctle = 0x3;
                lane_mode_0.s.pcie = 0x0;
                lane_mode_0.s.tx_ldiv = 0x0;
                lane_mode_0.s.rx_ldiv = 0x0;
                lane_mode_0.s.srate = 0x0;
                lane_mode_0.s.tx_mode = 0x3;
                lane_mode_0.s.rx_mode = 0x3;

                lane_mode_1.s.vma_fine_cfg_sel = 0x0;
                lane_mode_1.s.vma_mm = 0x0;
                lane_mode_1.s.cdr_fgain = 0xb;
                lane_mode_1.s.ph_acc_adj = 0x23;
                break;
        }
        BDK_CSR_WRITE(node, BDK_GSERX_PLL_PX_MODE_0(qlm, lane_mode), pll_mode_0.u);
        BDK_CSR_WRITE(node, BDK_GSERX_PLL_PX_MODE_1(qlm, lane_mode), pll_mode_1.u);
        BDK_CSR_WRITE(node, BDK_GSERX_LANE_PX_MODE_0(qlm, lane_mode), lane_mode_0.u);
        BDK_CSR_WRITE(node, BDK_GSERX_LANE_PX_MODE_1(qlm, lane_mode), lane_mode_1.u);
    }
}

/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
#ifdef HW_EMULATOR
    return;
#endif
    /* Setup how each PEM drives the PERST lines */
    for (int pem = 0; pem < 4; pem++)
    {
        BDK_CSR_INIT(rst_ctlx, node, BDK_RST_CTLX(pem));
        setup_pem_reset(node, pem, !rst_ctlx.s.host_mode);
    }
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn88xx = {
    .chip_model = CAVIUM_CN88XX,
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
    .inject_prbs_error = qlm_inject_prbs_error,
    .enable_loop = qlm_enable_loop,
    .auto_config = qlm_auto_config,
};


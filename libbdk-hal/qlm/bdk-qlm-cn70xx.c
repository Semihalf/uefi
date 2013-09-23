#include <bdk.h>

static uint64_t prbs_errors[3];

/**
 * These apply to DLM0
 */
typedef enum
{
    GMX_INF_MODE_DISABLED = 0,
    GMX_INF_MODE_SGMII = 1,     /* Other interface can be SGMII or QSGMII */
    GMX_INF_MODE_QSGMII = 2,    /* Other interface can be SGMII or QSGMII */
    GMX_INF_MODE_RXAUI = 3,     /* Only interface 0, interface 1 must be DISABLED */
} gmx_inf_mode_t;

/**
 * These apply to DLM1 and DLM2 if its not in SATA mode
 * Manual refers to lanes as follows:
 *  DML 0 lane 0 == GSER0 lane 0
 *  DML 0 lane 1 == GSER0 lane 1
 *  DML 1 lane 2 == GSER1 lane 0
 *  DML 1 lane 3 == GSER1 lane 1
 *  DML 2 lane 4 == GSER2 lane 0
 *  DML 2 lane 5 == GSER2 lane 1
 */
typedef enum
{
    PEM_CFG_MD_GEN2_2LANE = 0,  /* Valid for PEM0(DLM1), PEM1(DLM2) */
    PEM_CFG_MD_GEN2_1LANE = 1,  /* Valid for PEM0(DLM1.0), PEM1(DLM1.1,DLM2.0), PEM2(DLM2.1) */
    PEM_CFG_MD_GEN2_4LANE = 2,  /* Valid for PEM0(DLM1-2) */
    /* Reserved */
    PEM_CFG_MD_GEN1_2LANE = 4,  /* Valid for PEM0(DLM1), PEM1(DLM2) */
    PEM_CFG_MD_GEN1_1LANE = 5,  /* Valid for PEM0(DLM1.0), PEM1(DLM1.1,DLM2.0), PEM2(DLM2.1) */
    PEM_CFG_MD_GEN1_4LANE = 6,  /* Valid for PEM0(DLM1-2) */
    /* Reserved */
} pem_cfg_md_t;

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 3; /* Three DLMs */
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
        case BDK_IF_SGMII: /* Looking for SGMII or QSGMII */
        {
            if (interface >= 2)
                return -1;
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(interface));
            switch (inf_mode.s.mode)
            {
                case GMX_INF_MODE_SGMII: return 0;
                case GMX_INF_MODE_QSGMII: return 0;
                default: return -1;
            }
        }
        case BDK_IF_XAUI: /* Looking for RXAUI */
        {
            if (interface >= 1)
                return -1;
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(0));
            switch (inf_mode.s.mode)
            {
                case GMX_INF_MODE_RXAUI: return 0;
                default: return -1;
            }
        }
        case BDK_IF_DPI: /* Used for PCIe detection */
        {
            bdk_qlm_modes_t qlm_mode1 = bdk_qlm_get_mode(node, 1);
            bdk_qlm_modes_t qlm_mode2 = bdk_qlm_get_mode(node, 2);
            switch (interface)
            {
                case 0: /* PCIe0 can be DLM1 with 1, 2, or 4 lanes */
                    if ((qlm_mode1 == BDK_QLM_MODE_PCIE_1X4) || /* Using DLM 1-2 */
                        (qlm_mode1 == BDK_QLM_MODE_PCIE_1X2) || /* Using DLM 1 */
                        (qlm_mode1 == BDK_QLM_MODE_PCIE_1X1)) /* Using DLM 1, lane 0. Lane 1 not used */
                        return 1;
                    else
                        return -1;
                case 1: /* PCIe1 can be DLM1 1 lane(1), DLM2 1 lane(0) or 2 lanes(0-1) */
                    if (qlm_mode1 == BDK_QLM_MODE_PCIE_2X1)
                        return 1;
                    else if (qlm_mode2 == BDK_QLM_MODE_PCIE_1X1)
                        return 2;
                    else
                        return -1;
                case 2: /* PCIe2 can be DLM2 1 lanes(1) */
                    if (qlm_mode2 == BDK_QLM_MODE_PCIE_2X1)
                        return 2;
                    else
                        return -1;
                default: /* Only three PEM blocks */
                    return -1;
            }
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
    return 2; /* Each DLM has two lanes */
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
    BDK_CSR_INIT(phy, node, BDK_GSERX_DLMX_PHY_RESET(0, qlm));
    /* Return disabled if PHY is in reset */
    if (phy.s.phy_reset)
        return BDK_QLM_MODE_DISABLED;
    switch (qlm)
    {
        case 0:
        {
            BDK_CSR_INIT(inf_mode0, node, BDK_GMXX_INF_MODE(0));
            BDK_CSR_INIT(inf_mode1, node, BDK_GMXX_INF_MODE(1));
            switch (inf_mode0.s.mode)
            {
                case GMX_INF_MODE_SGMII:
                    switch (inf_mode1.s.mode)
                    {
                        case GMX_INF_MODE_SGMII:    return BDK_QLM_MODE_SGMII_SGMII;
                        case GMX_INF_MODE_QSGMII:   return BDK_QLM_MODE_SGMII_QSGMII;
                        default:                    return BDK_QLM_MODE_SGMII_DISABLED;
                    }
                case GMX_INF_MODE_QSGMII:
                    switch (inf_mode1.s.mode)
                    {
                        case GMX_INF_MODE_SGMII:    return BDK_QLM_MODE_QSGMII_SGMII;
                        case GMX_INF_MODE_QSGMII:   return BDK_QLM_MODE_QSGMII_QSGMII;
                        default:                    return BDK_QLM_MODE_QSGMII_DISABLED;
                    }
                case GMX_INF_MODE_RXAUI:
                    return BDK_QLM_MODE_RXAUI_1X2;
                default:
                    switch (inf_mode1.s.mode)
                    {
                        case GMX_INF_MODE_SGMII:    return BDK_QLM_MODE_DISABLED_SGMII;
                        case GMX_INF_MODE_QSGMII:   return BDK_QLM_MODE_DISABLED_QSGMII;
                        default:                    return BDK_QLM_MODE_DISABLED;
                    }
            }
        }
        case 1:
        {
            BDK_CSR_INIT(sata_cfg, node, BDK_GSERX_SATA_CFG(0));
            BDK_CSR_INIT(pem0_cfg, node, BDK_PEMX_CFG(0));
            switch (pem0_cfg.cn70xx.md)
            {
                case PEM_CFG_MD_GEN2_2LANE: /* Gen2 Speed, 2-lanes */
                    return BDK_QLM_MODE_PCIE_1X2;
                case PEM_CFG_MD_GEN2_1LANE: /* Gen2 Speed, 1-lane */
                    if (sata_cfg.s.sata_en)
                        return BDK_QLM_MODE_PCIE_2X1; /* Both PEM0 and PEM1 */
                    else
                        return BDK_QLM_MODE_PCIE_1X1; /* Only PEM0 */
                case PEM_CFG_MD_GEN2_4LANE: /* Gen2 Speed, 4-lanes */
                    return BDK_QLM_MODE_PCIE_1X4;
                case PEM_CFG_MD_GEN1_2LANE: /* Gen1 Speed, 2-lanes */
                    return BDK_QLM_MODE_PCIE_1X2;
                case PEM_CFG_MD_GEN1_1LANE: /* Gen1 Speed, 1-lane */
                    if (sata_cfg.s.sata_en)
                        return BDK_QLM_MODE_PCIE_2X1; /* Both PEM0 and PEM1 */
                    else
                        return BDK_QLM_MODE_PCIE_1X1; /* Only PEM0 */
                case PEM_CFG_MD_GEN1_4LANE: /* Gen1 Speed, 4-lanes */
                    return BDK_QLM_MODE_PCIE_1X4;
                default: /* Rsvd */
                    return BDK_QLM_MODE_DISABLED;
            }
        }
        case 2:
        {
            BDK_CSR_INIT(sata_cfg, node, BDK_GSERX_SATA_CFG(0));
            BDK_CSR_INIT(pem0_cfg, node, BDK_PEMX_CFG(0));
            BDK_CSR_INIT(pem1_cfg, node, BDK_PEMX_CFG(1));
            BDK_CSR_INIT(pem2_cfg, node, BDK_PEMX_CFG(2));
            if (sata_cfg.s.sata_en)
                return BDK_QLM_MODE_SATA_2X1;
            if ((pem0_cfg.cn70xx.md == PEM_CFG_MD_GEN2_4LANE) ||
                (pem0_cfg.cn70xx.md == PEM_CFG_MD_GEN1_4LANE))
                return BDK_QLM_MODE_PCIE_1X4;
            if ((pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN2_2LANE) ||
                (pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN1_2LANE))
                return BDK_QLM_MODE_PCIE_1X2;
            if ((pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN2_1LANE) ||
                (pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN1_1LANE))
            {
                if ((pem2_cfg.cn70xx.md == PEM_CFG_MD_GEN2_1LANE) ||
                    (pem2_cfg.cn70xx.md == PEM_CFG_MD_GEN1_1LANE))
                    return BDK_QLM_MODE_PCIE_2X1;
                else
                    return BDK_QLM_MODE_PCIE_1X1;
            }
            if ((pem2_cfg.cn70xx.md == PEM_CFG_MD_GEN2_1LANE) ||
                (pem2_cfg.cn70xx.md == PEM_CFG_MD_GEN1_1LANE))
                return BDK_QLM_MODE_PCIE_2X1;
            return BDK_QLM_MODE_DISABLED;
        }
        default:
            return BDK_QLM_MODE_DISABLED;
    }
}

static int dlm_setup_pll(bdk_node_t node, int qlm, int baud_mhz)
{
    // 1. Write GSER(0)_DLM(0)_REF_USE_PAD[REF_USE_PAD] = 1 (to select
    // reference-clock input).

    /* Reference clock was already chosen before we got here */

    // 2. Write GSER(0)_DLM(0)_REFCLK_SEL[REFCLK_SEL] if required for
    // reference-clock selection.

    /* Reference clock was already chosen before we got here */

    // 3. If required, write GSER(0)_DLM(0)_REF_CLKDIV2[REF_CLKDIV2] (must be
    // set if reference clock ? 100 MHz).
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    if (meas_refclock == 0)
    {
        bdk_error("DLM%d: Reference clock not running, skipping PLL setup\n", qlm);
        return -1;
    }
    /* If the reference clock is higher than 100Mhz it needs to be divied by 2.
       Use 101Mhz as the limit to account for measurement inaccuracy */
    if (meas_refclock > 101000000)
    {
        BDK_TRACE("DLM%d: Dividing ref clock by 2\n", qlm);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_REF_CLKDIV2(0, qlm),
            c.s.ref_clkdiv2 = 1);
        bdk_wait_usec(50000);
        meas_refclock /= 2;
    }

    // 4. Write GSER(0)_DLM(0)_MPLL_MULTIPLIER[MPLL_MULTIPLIER]. See Table
    // 21-1 for programming values.
    uint64_t mult = (uint64_t)baud_mhz * 1000000 + (meas_refclock/2);
    mult /= meas_refclock;
    BDK_TRACE("DLM%d: Setting multiplier to %lu\n", qlm, mult);
    BDK_CSR_WRITE(node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm), mult);

    // 5. Clear GSER(0)_DLM(0)_TEST_POWERDOWN[TEST_POWERDOWN] = 0.
    BDK_TRACE("DLM%d: Clearing GSERX_DLMX_TEST_POWERDOWN[TEST_POWERDOWN]\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TEST_POWERDOWN(0, qlm),
        c.s.test_powerdown = 0);

    // 6. Set GSER(0)_DLM(0)_REF_SSP_EN[REF_SSP_EN] = 1.
    if (qlm == 0)
    {
        /* This register only exists on DLM0 */
        BDK_TRACE("DLM%d: Enabling spread spectrum ref clock\n", qlm);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_REF_SSP_EN(0, qlm),
                c.s.ref_ssp_en = 1);
    }

    // 7. Set GSER(0)_DLM(0)_MPLL_EN[MPLL_EN] = 1.
    if (qlm == 0)
    {
        BDK_TRACE("DLM%d: Setting GSERX_DLMX_MPLL_EN[MPLL_EN]\n", qlm);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_MPLL_EN(0, qlm),
            c.s.mpll_en = 1);
    }

    // 8. Clear GSER(0)_DLM(0)_PHY_RESET[PHY_RESET] = 0.
    BDK_TRACE("DLM%d: Clearing PHY_RESET\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_PHY_RESET(0, qlm),
        c.s.phy_reset = 0);

    // 9. Poll until the MPLL locks. Wait for
    // GSER(0)_DLM(0)_MPLL_STATUS[MPLL_STATUS] = 1.
    if (!bdk_is_simulation() && BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_MPLL_STATUS(0, qlm), mpll_status, ==, 1, 10000))
    {
        bdk_error("PLL for DLM%d failed to lock\n", qlm);
        return -1;
    }
    BDK_TRACE("DLM%d: PLL is up\n", qlm);
    return 0;
}

static int dlm0_setup_tx(bdk_node_t node, int qlm)
{
    BDK_CSR_INIT(inf_mode0, node, BDK_GMXX_INF_MODE(0));
    BDK_CSR_INIT(inf_mode1, node, BDK_GMXX_INF_MODE(1));

    /* Which lanes do we need? */
    int need0 = (inf_mode0.s.mode != GMX_INF_MODE_DISABLED);
    int need1 = (inf_mode1.s.mode != GMX_INF_MODE_DISABLED) ||
                 (inf_mode0.s.mode == GMX_INF_MODE_RXAUI);

    // 1. Write GSER(0)_DLM(0)_TX_RATE[TXn_RATE]. Set according to required
    // data rate (see Table 21-1)
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_RATE(0, qlm),
        c.s.tx0_rate = (inf_mode0.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0;
        c.s.tx1_rate = (inf_mode1.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0);

    // 2. Set GSER(0)_DLM(0)_TX_EN[TXn_EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_EN(0, qlm),
        c.s.tx0_en = need0;
        c.s.tx1_en = need1);

    // 3. Set GSER(0)_DLM(0)_TX_CM_EN[TXn_CM_EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_CM_EN(0, qlm),
        c.s.tx0_cm_en = need0;
        c.s.tx1_cm_en = need1);

    // 4. Set GSER(0)_DLM(0)_TX_DATA_EN[TXn_DATA_EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_DATA_EN(0, qlm),
        c.s.tx0_data_en = need0;
        c.s.tx1_data_en = need1);

    // 5. Clear GSER(0)_DLM(0)_TX_RESET[TXn_RESET] = 0.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_RESET(0, qlm),
        c.s.tx0_reset = !need0;
        c.s.tx1_reset = !need1);

    // 6. Poll GSER(0)_DLM(0)_TX_STATUS[TXn_STATUS, TXn_CM_STATUS] until both
    // are set to 1. This prevents GMX from transmitting until the DLM is
    // ready.
    if (!bdk_is_simulation() && need0)
    {
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_TX_STATUS(0, qlm), tx0_status, ==, 1, 10000))
        {
            bdk_error("DLM%d TX0 status fail\n", qlm);
            return -1;
        }
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_TX_STATUS(0, qlm), tx0_cm_status, ==, 1, 10000))
        {
            bdk_error("DLM%d TX0 CM status fail\n", qlm);
            return -1;
        }
    }
    if (!bdk_is_simulation() && need1)
    {
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_TX_STATUS(0, qlm), tx1_status, ==, 1, 10000))
        {
            bdk_error("DLM%d TX1 status fail\n", qlm);
            return -1;
        }
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_TX_STATUS(0, qlm), tx1_cm_status, ==, 1, 10000))
        {
            bdk_error("DLM%d TX1 CM status fail\n", qlm);
            return -1;
        }
    }
    return 0;
}

static int dlm0_setup_rx(bdk_node_t node, int qlm)
{
    BDK_CSR_INIT(inf_mode0, node, BDK_GMXX_INF_MODE(0));
    BDK_CSR_INIT(inf_mode1, node, BDK_GMXX_INF_MODE(1));

    /* Which lanes do we need? */
    int need0 = (inf_mode0.s.mode != GMX_INF_MODE_DISABLED);
    int need1 = (inf_mode1.s.mode != GMX_INF_MODE_DISABLED) ||
                 (inf_mode0.s.mode == GMX_INF_MODE_RXAUI);

    // 1. Write GSER(0)_DLM(0)_RX_RATE[RXn_RATE] (must match the
    // GSER(0)_DLM(0)_TX_RATE[TXn_RATE] setting).
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_RATE(0, qlm),
        c.s.rx0_rate = (inf_mode0.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0;
        c.s.rx1_rate = (inf_mode1.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0);

    // 2. Set GSER(0)_DLM(0)_RX_PLL_EN[RXn_PLL_EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_PLL_EN(0, qlm),
        c.s.rx0_pll_en = need0;
        c.s.rx1_pll_en = need1);

    // 3. Set GSER(0)_DLM(0)_RX_DATA_EN[RXn_DATA_EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_DATA_EN(0, qlm),
        c.s.rx0_data_en = need0;
        c.s.rx1_data_en = need1);

    // 4. Clear GSER(0)_DLM(0)_RX_RESET[RXn_RESET] = 0. Now the GMX can be
    // enabled: set GMX(0..1)_INF_MODE[EN] = 1.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_RESET(0, qlm),
        c.s.rx0_reset = !need0;
        c.s.rx1_reset = !need1);
    return 0;
}

static int dlm2_setup_sata(bdk_node_t node, int qlm, int baud_mhz)
{
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    if (meas_refclock == 0)
    {
        bdk_error("DLM%d: Reference clock not running, skipping PLL setup\n", qlm);
        meas_refclock = 100000000;
        //return -1;
    }

    // 1. Write GSER(0)_DLM2_REFCLK_SEL[REFCLK_SEL] if required for
    // reference-clock selection.

    /* Reference clock was already chosen before we got here */

    // 2. Write GSER(0)_DLM2_MPLL_MULTIPLIER[MPLL_MULTIPLIER]. For a
    // 100MHz reference clock, set to 0x1E. See Table 21-2 for
    // programming values.
    uint64_t mult = (uint64_t)baud_mhz * 1000000 + (meas_refclock/2);
    mult /= meas_refclock;
    BDK_TRACE("DLM%d: Setting multiplier to %lu\n", qlm, mult);
    BDK_CSR_WRITE(node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm), mult);

    // 3. Clear GSER(0)_DLM2_TEST_POWERDOWN[TEST_POWERDOWN] = 0.
    BDK_TRACE("DLM%d: Clearing GSERX_DLMX_TEST_POWERDOWN[TEST_POWERDOWN]\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TEST_POWERDOWN(0, qlm),
        c.s.test_powerdown = 0);

    // 4. Clear GSER(0)_DLM2_PHY_RESET.
    BDK_TRACE("DLM%d: Clearing PHY_RESET\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_PHY_RESET(0, qlm),
        c.s.phy_reset = 0);

    // 5. Set GSER(0)_SATA_CFG[SATA_EN] = 1 to configure DLM2 multiplexing.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_SATA_CFG(0),
        c.s.sata_en = 1);

    // 6. Clear either/both lane0 and lane1 resets:
    // GSER(0)_SATA_LANE_RST[L0_RST, L1_RST] = 0.
    BDK_CSR_MODIFY(c, node, BDK_GSERX_SATA_LANE_RST(0),
        c.s.l0_rst = 0;
        c.s.l1_rst = 0);
    return 0;
}

static int dlmx_setup_pcie(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int gen2, int root)
{
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    if (meas_refclock == 0)
    {
        bdk_error("DLM%d: Reference clock not running, skipping PLL setup\n", qlm);
        meas_refclock = 100000000;
        //return -1;
    }

    // 1. Write GSER0_DLM(1..2)_REFCLK_SEL[REFCLK_SEL] if required for
    // reference-clock selection

    /* Reference clock was already chosen before we got here */

    // 2. If required, write GSER0_DLM(1..2)_REF_CLKDIV2[REF_CLKDIV2] = 1 (must
    // be set if reference clock >= 100 MHz)
    if (meas_refclock > 101000000)
    {
        /* Use 101Mhz as the limit to account for measurement inaccuracy */
        BDK_TRACE("DLM%d: Dividing ref clock by 2\n", qlm);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_REF_CLKDIV2(0, qlm),
            c.s.ref_clkdiv2 = 1);
        bdk_wait_usec(50000);
        meas_refclock /= 2;
    }

    // 3. Write GSER0_DLM(1..2)_MPLL_MULTIPLIER[MPLL_MULTIPLIER].
    //      for a 100MHz reference clock, set to 0x19.
    //      for a 125MHz reference clock, set to 0x28.
    //      See Table 21-3 for programming values.
    int mult = (meas_refclock > 90000000) ? 0x19 : 0x28;
    BDK_TRACE("DLM%d: Setting multiplier to %d\n", qlm, mult);
    BDK_CSR_WRITE(node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm), mult);

    // 4. Configure the PCIE PIPE:
    //  a. Write GSER0_PCIE_PIPE_PORT_SEL[PIPE_PORT_SEL] to configure the
    //      PCIE PIPE.
    //      0x0 = disables all pipes
    //      0x1 = enables pipe0 only (PEM0 4-lane)
    //      0x2 = enables pipes 0 and 1 (PEM0 and PEM1 2-lanes each)
    //      0x3 = enables pipes 0, 1, 2, and 3 (PEM0, PEM1, and PEM3 are
    //          one-lane each)
    //  b. Configure GSER0_PCIE_PIPE_PORT_SEL[CFG_PEM1_DLM2]. If PEM1 is
    //      to be configured, this bit must reflect which DLM it is logically
    //      tied to. This bit sets multiplexing logic in GSER, and it is used
    //      by the RST logic to determine when the MAC can come out of reset.
    //      0 = PEM1 is tied to DLM1 (for 3 x 1 PCIe mode).
    //      1 = PEM1 is tied to DLM2 (for all other PCIe modes).
    if (qlm == 1)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PCIE_PIPE_PORT_SEL(0),
            c.s.cfg_pem1_dlm2 = (mode == BDK_QLM_MODE_PCIE_2X1) ? 0 : 1;
            c.s.pipe_port_sel =
                (mode == BDK_QLM_MODE_PCIE_1X4) ? 1 : /* PEM0 only */
                (mode == BDK_QLM_MODE_PCIE_1X2) ? 2 : /* PEM0-1 */
                (mode == BDK_QLM_MODE_PCIE_1X1) ? 3 : /* PEM0-2 */
                (mode == BDK_QLM_MODE_PCIE_2X1) ? 2 : /* PEM0-1 */
                0); /* PCIe disabled */
    }

    // 5. Clear GSER(0)_DLM(1..2)_TEST_POWERDOWN. Configurations that use only
    // DLM1 need not clear GSER(0)_DLM2_TEST_POWERDOWN
    BDK_TRACE("DLM%d: Clearing GSERX_DLMX_TEST_POWERDOWN[TEST_POWERDOWN]\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TEST_POWERDOWN(0, qlm),
        c.s.test_powerdown = 0);

    // 6. Clear GSER(0)_DLM(1..2)_PHY_RESET. Configurations that use only DLM1
    // need not clear GSER(0)_DLM2_PHY_RESET
    BDK_TRACE("DLM%d: Clearing PHY_RESET\n", qlm);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_PHY_RESET(0, qlm),
        c.s.phy_reset = 0);

    // 7. Write the GSER(0)_PCIE_PIPE_RST register to take the appropriate
    // PIPE out of reset. There is a PIPEn_RST bit for each PIPE. Clear the
    // appropriate bits based on the configuration (reset is active high).
    if (qlm == 1)
    {
        /* PEM0 always on */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PCIE_PIPE_RST(0), c.s.pipe0_rst = 0);
        BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(0), c.s.pemon = 1);
        /* PEM1 on lane 2 if mode is 2x1 */
        int pem1 = (mode == BDK_QLM_MODE_PCIE_2X1);
        if (pem1)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_PCIE_PIPE_RST(0), c.s.pipe1_rst = 0);
            BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(1), c.s.pemon = 1);
        }
    }
    else
    {
        int pem1 = ((mode == BDK_QLM_MODE_PCIE_2X1) || /* PEM1 on lane 4, PEM2 on lane 5 */
                    (mode == BDK_QLM_MODE_PCIE_1X2));  /* PEM1 on lane 4-5 */
        int pem2 = (mode == BDK_QLM_MODE_PCIE_2X1);
        if (pem1)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_PCIE_PIPE_RST(0), c.s.pipe1_rst = 0);
            BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(1), c.s.pemon = 1);
        }
        if (pem2)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_PCIE_PIPE_RST(0), c.s.pipe2_rst = 0);
            BDK_CSR_MODIFY(c, node, BDK_PEMX_ON(2), c.s.pemon = 1);
        }
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
    switch (qlm)
    {
        case 0:
        {
            BDK_CSR_INIT(inf_mode0, node, BDK_GMXX_INF_MODE(0));
            BDK_CSR_INIT(inf_mode1, node, BDK_GMXX_INF_MODE(1));
            if (inf_mode0.s.en || inf_mode1.s.en)
            {
                bdk_error("DLM0 already configured\n");
                return -1;
            }
            switch (mode)
            {
                case BDK_QLM_MODE_RXAUI_1X2:
                    inf_mode0.s.mode = GMX_INF_MODE_RXAUI;
                    inf_mode1.s.mode = GMX_INF_MODE_DISABLED;
                    break;
                case BDK_QLM_MODE_SGMII_SGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_SGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_SGMII;
                    break;
                case BDK_QLM_MODE_SGMII_QSGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_SGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_QSGMII;
                    break;
                case BDK_QLM_MODE_SGMII_DISABLED:
                    inf_mode0.s.mode = GMX_INF_MODE_SGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_DISABLED;
                    break;
                case BDK_QLM_MODE_QSGMII_SGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_QSGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_SGMII;
                    break;
                case BDK_QLM_MODE_QSGMII_QSGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_QSGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_QSGMII;
                    break;
                case BDK_QLM_MODE_QSGMII_DISABLED:
                    inf_mode0.s.mode = GMX_INF_MODE_QSGMII;
                    inf_mode1.s.mode = GMX_INF_MODE_DISABLED;
                    break;
                case BDK_QLM_MODE_DISABLED_SGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_DISABLED;
                    inf_mode1.s.mode = GMX_INF_MODE_SGMII;
                    break;
                case BDK_QLM_MODE_DISABLED_QSGMII:
                    inf_mode0.s.mode = GMX_INF_MODE_DISABLED;
                    inf_mode1.s.mode = GMX_INF_MODE_QSGMII;
                    break;
                case BDK_QLM_MODE_DISABLED:
                    inf_mode0.s.mode = GMX_INF_MODE_DISABLED;
                    inf_mode1.s.mode = GMX_INF_MODE_DISABLED;
                    break;
                default:
                    bdk_error("DLM0 illegal mode specified\n");
                    return -1;
            }
            /* Configure the mode */
            BDK_CSR_WRITE(node, BDK_GMXX_INF_MODE(0), inf_mode0.u);
            BDK_CSR_WRITE(node, BDK_GMXX_INF_MODE(1), inf_mode1.u);
            /* Bringup the PLL */
            if (dlm_setup_pll(node, qlm, baud_mhz))
                return -1;
            /* TX Lanes */
            if (dlm0_setup_tx(node, qlm))
                return -1;
            /* RX Lanes */
            if (dlm0_setup_rx(node, qlm))
                return -1;

            if (inf_mode0.s.mode != GMX_INF_MODE_DISABLED)
                inf_mode0.s.en = 1;
            if (inf_mode1.s.mode != GMX_INF_MODE_DISABLED)
                inf_mode1.s.en = 1;
            /* Enable the interfaces */
            BDK_CSR_WRITE(node, BDK_GMXX_INF_MODE(0), inf_mode0.u);
            BDK_CSR_WRITE(node, BDK_GMXX_INF_MODE(1), inf_mode1.u);
            return 0;
        }
        case 1:
        {
            BDK_CSR_INIT(pem_cfg0, node, BDK_PEMX_CFG(0));
            BDK_CSR_INIT(pem_cfg1, node, BDK_PEMX_CFG(1));
            switch (mode)
            {
                case BDK_QLM_MODE_PCIE_1X4:
                    /* DLM0+DLM1 is PCIE0 */
                    pem_cfg0.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_4LANE : PEM_CFG_MD_GEN2_4LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_PCIE_1X2:
                    /* DLM0 is PCIE0 */
                    pem_cfg0.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_2LANE : PEM_CFG_MD_GEN2_2LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_PCIE_2X1:
                    /* DLM0 is PCIE0+PCIE1 */
                    pem_cfg0.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_1LANE : PEM_CFG_MD_GEN2_1LANE;
                    pem_cfg1.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_1LANE : PEM_CFG_MD_GEN2_1LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_PCIE_1X1:
                    /* DLM0+DLM1 is PCIE0 */
                    pem_cfg0.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_1LANE : PEM_CFG_MD_GEN2_1LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_DISABLED:
                    break;
                default:
                    bdk_error("DLM1 illegal mode specified\n");
                    return -1;
            }
            // FIXME: Lane swap?
            pem_cfg0.cn70xx.hostmd = (flags&BDK_QLM_MODE_FLAG_ENDPOINT) ? 0 : 1;
            pem_cfg1.cn70xx.hostmd = 1; /* PEM1 doesn't support EP mode */
            BDK_CSR_WRITE(node, BDK_PEMX_CFG(0), pem_cfg0.u);
            BDK_CSR_WRITE(node, BDK_PEMX_CFG(1), pem_cfg1.u);
            return 0;
        }
        case 2:
        {
            BDK_CSR_INIT(pem_cfg1, node, BDK_PEMX_CFG(1));
            BDK_CSR_INIT(pem_cfg2, node, BDK_PEMX_CFG(2));
            switch (mode)
            {
                case BDK_QLM_MODE_SATA_2X1:
                    /* DLM2 is SATA. PCIE2 is disabled */
                    if (dlm2_setup_sata(node, qlm, 3000))
                        return -1;
                    break;
                case BDK_QLM_MODE_PCIE_1X4:
                    /* DLM2 is PCIE0. PCIE1-2 are disabled */
                    /* Do nothing as setup was done with DLM 1 */
                    break;
                case BDK_QLM_MODE_PCIE_1X2:
                    /* DLM2 is PCIE1. PCIE2 is disabled */
                    pem_cfg1.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_2LANE : PEM_CFG_MD_GEN2_2LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_PCIE_2X1:
                    /* DLM2 is PCIE1 and PCIE2 */
                    pem_cfg1.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_1LANE : PEM_CFG_MD_GEN2_1LANE;
                    pem_cfg2.cn70xx.md = (flags&BDK_QLM_MODE_FLAG_GEN1) ? PEM_CFG_MD_GEN1_1LANE : PEM_CFG_MD_GEN2_1LANE;
                    if (dlmx_setup_pcie(node, qlm, mode, flags&BDK_QLM_MODE_FLAG_GEN2, !(flags&BDK_QLM_MODE_FLAG_ENDPOINT)))
                        return -1;
                    break;
                case BDK_QLM_MODE_DISABLED:
                    break;
                default:
                    bdk_error("DLM2 illegal mode specified\n");
                    return -1;
            }
            // FIXME: Lane swap?
            pem_cfg1.cn70xx.hostmd = 1; /* PEM1 doesn't support EP mode */
            pem_cfg2.cn70xx.hostmd = 1; /* PEM1 doesn't support EP mode */
            BDK_CSR_WRITE(node, BDK_PEMX_CFG(1), pem_cfg1.u);
            BDK_CSR_WRITE(node, BDK_PEMX_CFG(2), pem_cfg2.u);
            return 0;
        }
        default:
            return -1;
    }
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
    /* Measure the reference clock */
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    /* Multiply to get the final frequency */
    BDK_CSR_INIT(dlmx_mpll_multiplier, node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm));
    uint64_t freq = meas_refclock * dlmx_mpll_multiplier.s.mpll_multiplier;
    freq = (freq + 500000) / 1000000;
    return freq;
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
    /* Disable the PTP event counter while we configure it */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Count on rising edge, Choose which QLM to count */
    BDK_CSR_MODIFY(c, node, BDK_MIO_PTP_CLOCK_CFG,
        c.s.evcnt_edge = 0;
        c.s.evcnt_in = 0x10 + qlm);
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
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_TX_LBERT_CTL(0, qlm), c.s.mode = 0);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_TX_LBERT_CTL(0, qlm), c.s.mode = 0);
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
    int mode;
    if (prbs == 31)
        mode = 1;
    else if (prbs == 23)
        mode = 2;
    else if (prbs == 15)
        mode = 3;
    else if (prbs == 7)
        mode = 4;
    else
    {
        bdk_error("Invalid PRBS mode %d\n", prbs);
        return -1;
    }

    if (dir & BDK_QLM_DIRECTION_TX)
    {
        // 1) Program the GSER0_PHY(0..2)_LANE(1..0)_TX_LBERT_CTL
        //      PAT0[14:5]     - 10-bit pattern
        //      TRIG_ERR[4]    - a one shot for inserting errors
        //      MODE[3:0]      - Pattern to generate
        //      When changing modes, you must change to disabled first
        //          0:    disabled
        //          1:    lfsr31  (X^31 + X^28 + 1)
        //          2:    lfsr23  (X^23 + X^18 + 1)
        //          3:    lfsr15  (X^15 + X^14 + 1)
        //          4:    lfsr7   (X^7 + X^6 + 1)
        //          5:    Fixed Pattern (PAT0)
        //          6:    DC Balanced {PAT0, ~PAT0}
        //          7:    Word pattern (20-bit)
        //          8-15: Reserved

        /* Set to zero first in case already running */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_TX_LBERT_CTL(0, qlm), c.s.mode = 0);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_TX_LBERT_CTL(0, qlm), c.s.mode = 0);
        /* Program PRBS mode. This code doesn't support the other
            pattern modes */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_TX_LBERT_CTL(0, qlm), c.s.mode = mode);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_TX_LBERT_CTL(0, qlm), c.s.mode = mode);
    }

    if (dir & BDK_QLM_DIRECTION_RX)
    {
        // 2) Program the GSER0_PHY(0..2)_LANE(1..0)_RX_LBERT_CTL
        //      SYNC[3]        - Synchronzes the pattern matcher with the incoming data.  A write of a 1 to this bit resets
        //                      the error counter and starts a synchronization of the PM.  To run normally, there is no need
        //                      to write this field back to a zero.
        //      MODE[2:0]      - Pattern to generate, should match the mode in the TX_LBERT_CTL
        //                      When changing modes, you must change to disabled first
        //          0:    disabled
        //          1:    lfsr31  (X^31 + X^28 + 1)
        //          2:    lfsr23  (X^23 + X^18 + 1)
        //          3:    lfsr15  (X^15 + X^14 + 1)
        //          4:    lfsr7   (X^7 + X^6 + 1)
        //          5:    d[n] = d[n-10]
        //          6:    d[n] = !d[n-10]
        //          7:    d[n] = !d[n-20]

        /* Set to zero first in case already running */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_RX_LBERT_CTL(0, qlm), c.s.mode = 0);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_RX_LBERT_CTL(0, qlm), c.s.mode = 0);
        /* Program PRBS mode. This code doesn't support the other
            pattern modes */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_RX_LBERT_CTL(0, qlm), c.s.mode = mode);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_RX_LBERT_CTL(0, qlm), c.s.mode = mode);
        /* Tell the DLM to resync */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE0_RX_LBERT_CTL(0, qlm), c.s.sync = 1);
        BDK_CSR_MODIFY(c, node, BDK_GSERX_PHYX_LANE1_RX_LBERT_CTL(0, qlm), c.s.sync = 1);
        prbs_errors[qlm] = 0;
    }
    return 0;
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
    BDK_CSR_DEFINE(rx, BDK_GSERX_PHYX_LANE0_RX_LBERT_ERR(0, qlm));
    if (lane)
        rx.u = BDK_CSR_READ(node, BDK_GSERX_PHYX_LANE1_RX_LBERT_ERR(0, qlm));
    else
        rx.u = BDK_CSR_READ(node, BDK_GSERX_PHYX_LANE0_RX_LBERT_ERR(0, qlm));
    if (rx.s.ov14)
        prbs_errors[qlm] += rx.s.count << 7;
    else
        prbs_errors[qlm] += rx.s.count;
    return prbs_errors[qlm];
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
    bdk_error("Shallow loopback not supported on this chip\n");
    return -1;
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    /* Nothing to do? */
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn70xx = {
    .chip_model = OCTEON_CN70XX,
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


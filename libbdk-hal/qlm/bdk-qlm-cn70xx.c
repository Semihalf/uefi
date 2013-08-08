#include <bdk.h>

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
    if (!bdk_is_simulation() && phy.s.phy_reset)
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
            BDK_CSR_INIT(pem0_cfg, node, BDK_PEMX_CFG(0));
            BDK_CSR_INIT(pem1_cfg, node, BDK_PEMX_CFG(1));
            switch (pem0_cfg.cn70xx.md)
            {
                case PEM_CFG_MD_GEN2_2LANE: /* Gen2 Speed, 2-lanes */
                    return BDK_QLM_MODE_PCIE_1X2;
                case PEM_CFG_MD_GEN2_1LANE: /* Gen2 Speed, 1-lane */
                    if ((pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN2_1LANE) ||
                        (pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN1_1LANE))
                        return BDK_QLM_MODE_PCIE_2X1; /* Both PEM0 and PEM1 */
                    else
                        return BDK_QLM_MODE_PCIE_1X1; /* Only PEM0 */
                case PEM_CFG_MD_GEN2_4LANE: /* Gen2 Speed, 4-lanes */
                    return BDK_QLM_MODE_PCIE_1X4;
                case PEM_CFG_MD_GEN1_2LANE: /* Gen1 Speed, 2-lanes */
                    return BDK_QLM_MODE_PCIE_1X2;
                case PEM_CFG_MD_GEN1_1LANE: /* Gen1 Speed, 1-lane */
                    if ((pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN2_1LANE) ||
                        (pem1_cfg.cn70xx.md == PEM_CFG_MD_GEN1_1LANE))
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
    /* This sequnce is from http://mawiki.caveonetworks.com/wiki/70xx/SERDES#DLM0:_.2APreliminary.2A_Bring_Up_Sequence */
    // 1. Write GSER0_DLM0_REF_USE_PAD[REF_USE_PAD] (depending on which ref clock input is desired)

    // FIXME: Select ref clock

    // 2. Write GSER0_DLM0_REF_CLKDIV2[REF_CLKDIV2] (for now, see Table 3-1 in the databook for value)
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    /* If the reference clock is higher than 100Mhz it needs to be divied by 2 */
    if (meas_refclock > 100000000)
    {
        BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_REF_CLKDIV2(0, qlm),
            c.s.ref_clkdiv2 = 1);
        meas_refclock /= 2;
    }

    // 3. Write GSER0_DLM0_MPLL_MULTIPLIER[MPLL_MULTIPLIER] (for now, see Table 3-1 in the databook for value)
    uint64_t mult = baud_mhz * 1000000 + (meas_refclock/2);
    mult /= meas_refclock;
    BDK_CSR_WRITE(node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm), mult);

    // 4. Write GSER0_DLM0_MPLL_HALF_RATE[MPLL_HALF_RATE] (for now, see Table 3-1 in the databook for value)
    // Synopsys says the mpll_half_rate is deprecated
    // Do nothing

    // 5. Clear GSER0_DLM0_TEST_POWERDOWN[TEST_POWERDOWN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TEST_POWERDOWN(0, qlm),
        c.s.test_powerdown = 0);

    // 6. Set GSER0_DLM0_REF_SSP_EN[REF_SSP_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_REF_SSP_EN(0, qlm),
        c.s.ref_ssp_en = 1);

    // 7. Set GSER0_DLM0_MPLL_EN[MPLL_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_MPLL_EN(0, qlm),
        c.s.mpll_en = 1);

    // 8. Clear GSER0_DLM0_PHY_RESET[PHY_RESET]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_PHY_RESET(0, qlm),
        c.s.phy_reset = 0);

    // 9. Poll until the MPLL locks
    if (!bdk_is_simulation() && BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_DLMX_MPLL_STATUS(0, qlm), mpll_status, ==, 1, 10000))
    {
        bdk_error("PLL for DLM%d failed to lock\n", qlm);
        return -1;
    }
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

    /* This sequnce is from http://mawiki.caveonetworks.com/wiki/70xx/SERDES#DLM0:_.2APreliminary.2A_Bring_Up_Sequence */
    // 1. Write GSER0_DLM0_TX_RATE[TXn_RATE] (for now, see Table 3-1 in the databook for value)
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_RATE(0, qlm),
        c.s.tx0_rate = (inf_mode0.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0;
        c.s.tx1_rate = (inf_mode1.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0);

    // 2. Set GSER0_DLM0_TX_EN[TXn_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_EN(0, qlm),
        c.s.tx0_en = need0;
        c.s.tx1_en = need1);

    // 2.1 set GSER0_DLM0_TX_CM_EN[TXn_CM_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_CM_EN(0, qlm),
        c.s.tx0_cm_en = need0;
        c.s.tx1_cm_en = need1);

    // 3. Set GSER0_DLM0_TX_DATA_EN[TXn_DATA_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_DATA_EN(0, qlm),
        c.s.tx0_data_en = need0;
        c.s.tx1_data_en = need1);

    // 4. Clear GSER0_DLM0_TX_RESET[TXn_RESET]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_TX_RESET(0, qlm),
        c.s.tx0_reset = need0;
        c.s.tx1_reset = need1);

    // 5. Poll GSER0_DLM0_TX_STATUS[TXn_STATUS][0] and
    //    GSER0_DLM0_TX_STATUS[TXn_CM_STATUS][0] until both are set
    // This will prevent AGX from transmitting until the PHY is ready.
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

    /* This sequnce is from http://mawiki.caveonetworks.com/wiki/70xx/SERDES#DLM0:_.2APreliminary.2A_Bring_Up_Sequence */
    // 1. Write GSER0_DLM0_RX_RATE[RXn_RATE] (for now, see Table 3-1 in the databook for value)
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_RATE(0, qlm),
        c.s.rx0_rate = (inf_mode0.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0;
        c.s.rx1_rate = (inf_mode1.s.mode == GMX_INF_MODE_SGMII) ? 2 : 0);

    // 2. Set GSER0_DLM0_RX_PLL_EN[RXn_PLL_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_PLL_EN(0, qlm),
        c.s.rx0_pll_en = need0;
        c.s.rx1_pll_en = need1);

    // 3. Set GSER0_DLM0_RX_DATA_EN[RXn_DATA_EN]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_DATA_EN(0, qlm),
        c.s.rx0_data_en = need0;
        c.s.rx1_data_en = need1);

    // 4. Clear GSER0_DLM0_RX_RESET[RXn_RESET]
    BDK_CSR_MODIFY(c, node, BDK_GSERX_DLMX_RX_RESET(0, qlm),
        c.s.rx0_reset = need0;
        c.s.rx1_reset = need1);
    return 0;
}

static int dlm2_setup_sata(bdk_node_t node, int qlm, int baud_mhz)
{
    // 1. Write GSER0_DLM2_MPLL_MULTIPLIER - use values in Table 3-1 in the databook
    // 2. Clear GSER0_DLM2_TEST_POWERDOWN
    // 3. Clear GSER0_DLM2_PHY_RESET
    if (dlm_setup_pll(node, qlm, baud_mhz))
        return -1;
    // 4. Set GSER0_SATA_CFG.SATA_EN to configure DLM2 muxing correctly
    BDK_CSR_MODIFY(c, node, BDK_GSERX_SATA_CFG(0),
        c.s.sata_en = 1);
    // 5. Clear GSER0_SATA_LANE_RST - clear either or both lane 0 & 1 resets
    BDK_CSR_MODIFY(c, node, BDK_GSERX_SATA_LANE_RST(0),
        c.s.l0_rst = 0;
        c.s.l1_rst = 0);
    return 0;
}

static int dlmx_setup_pcie(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int gen2, int root)
{
    return -1; // FIXME: setup dlm for pcie
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
                    if (dlm2_setup_sata(node, qlm, 5000))
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
    /* Return zero if the PLL hasn't locked */
    BDK_CSR_INIT(dlmx_mpll, node, BDK_GSERX_DLMX_MPLL_STATUS(0, qlm));
    if (dlmx_mpll.s.mpll_status == 0)
        return 0;
    /* Measure the reference clock */
    uint64_t meas_refclock = bdk_qlm_measure_clock(node, qlm);
    uint64_t mhz = meas_refclock / 1000000;
    /* Divide it by two if the DLM is configure that way */
    BDK_CSR_INIT(dlmx_ref_clkdiv2, node, BDK_GSERX_DLMX_REF_CLKDIV2(0, qlm));
    if (dlmx_ref_clkdiv2.s.ref_clkdiv2)
        mhz /= 2;
    /* Multiply to get the final frequency */
    BDK_CSR_INIT(dlmx_mpll_multiplier, node, BDK_GSERX_DLMX_MPLL_MULTIPLIER(0, qlm));
    mhz *= dlmx_mpll_multiplier.s.mpll_multiplier;
    return mhz;
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
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn61xx;
    return bdk_qlm_ops_cn61xx.measure_refclock(node, qlm);
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
    bdk_error("CN70XX QLM reset not implemented\n");
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
    bdk_error("CN70XX PRBS not implemented\n");
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
    .enable_loop = qlm_enable_loop,
};


#include <bdk.h>
#include <stdio.h>
#include "bdk-qlm-common.h"

/* Indexed by QLM number and lane */
static uint64_t prbs_errors[14][4];

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
int __bdk_qlm_get_lane_mode_for_speed_and_ref_clk(const char *mode_name, int qlm, int ref_clk, int baud_mhz)
{
    if (baud_mhz <= 1250)
    {
        if (ref_clk == REF_156MHZ)
            return BDK_GSER_LMODE_E_R_125G_REFCLK15625_SGMII;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 2500)
    {
        if (ref_clk == REF_100MHZ)
            return BDK_GSER_LMODE_E_R_25G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return BDK_GSER_LMODE_E_R_25G_REFCLK125;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 3125)
    {
        if (ref_clk == REF_156MHZ)
            return BDK_GSER_LMODE_E_R_3125G_REFCLK15625_XAUI;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 5000)
    {
        if (ref_clk == REF_100MHZ)
            return BDK_GSER_LMODE_E_R_5G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return BDK_GSER_LMODE_E_R_5G_REFCLK125;
        else
            return BDK_GSER_LMODE_E_R_5G_REFCLK15625_QSGMII;
    }
    else if (baud_mhz <= 6250)
    {
        if (ref_clk == REF_156MHZ)
            return BDK_GSER_LMODE_E_R_625G_REFCLK15625_RXAUI;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else if (baud_mhz <= 8000)
    {
        if (ref_clk == REF_100MHZ)
            return BDK_GSER_LMODE_E_R_8G_REFCLK100;
        else if (ref_clk == REF_125MHZ)
            return BDK_GSER_LMODE_E_R_8G_REFCLK125;
        else
        {
            bdk_error("Invalid reference clock for %s on QLM%d with speed %d, ref %d Mhz\n", mode_name, qlm, baud_mhz, ref_clk / 1000000);
            return -1;
        }
    }
    else /* Baud 10312.5 */
    {
        if (ref_clk == REF_156MHZ)
            return BDK_GSER_LMODE_E_R_103125G_REFCLK15625_KR;
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
void __bdk_qlm_setup_pem_reset(bdk_node_t node, int pem, int is_endpoint)
{
    /* Make sure is_endpoint is either 0 or 1 */
    is_endpoint = (is_endpoint != 0);
    BDK_CSR_MODIFY(c, node, BDK_RST_CTLX(pem),
        c.s.prst_link = 0;          /* Link down causes soft reset */
        c.s.rst_link = is_endpoint; /* EP PERST causes a soft reset */
        c.s.rst_drv = !is_endpoint; /* Drive if RC */
        c.s.rst_rcv = is_endpoint;  /* Only read PERST in EP mode */
        c.s.rst_chip = 0);          /* PERST doesn't pull CHIP_RESET */
}

/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
int __bdk_qlm_measure_refclock(bdk_node_t node, int qlm)
{
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* Asim doesn't have reference clocks. Return reasonable values for
           the default config we support in Asim */
        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        {
            /* BGX on QLM0-1, everything else needs a 100Mhz ref */
            if (qlm < 2)
                return REF_156MHZ;
            else
                return REF_100MHZ;
        }
        else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        {
            /* BGX on QLM2-3,5-6, everything else needs a 100Mhz ref */
            if ((qlm == 2) || (qlm == 3) || (qlm == 5) || (qlm == 6))
                return REF_156MHZ;
            else
                return REF_100MHZ;
        }
        else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        {
            /* BGX on DLM0-1, everything else needs a 100Mhz ref */
            if ((qlm == 0) || (qlm == 1))
                return REF_156MHZ;
            else
                return REF_100MHZ;
        }
        return 0; /* Default to none */
    }

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
    bdk_wait_usec(20000); /* 20ms */
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
 * Put a QLM into hardware reset
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
int __bdk_qlm_reset(bdk_node_t node, int qlm)
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
int __bdk_qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir)
{
    const int NUM_LANES = bdk_qlm_get_lanes(node, qlm);
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
            break;
    }

    /* For some reason PRBS doesn't work if GSER is configured for PCIe.
       Disconnect PCIe when we start PRBS */
    BDK_CSR_INIT(gserx_cfg, node, BDK_GSERX_CFG(qlm));
    if (gserx_cfg.s.pcie)
    {
        gserx_cfg.s.pcie = 0;
        BDK_CSR_WRITE(node, BDK_GSERX_CFG(qlm), gserx_cfg.u);
        bdk_warn("N%d.QLM%d: Disabling PCIe for PRBS/pattern generation\n", node, qlm);
    }
    /* For some reason PRBS doesn't work if GSER is configured for SATA.
       Disconnect SATA when we start PRBS */
    if (gserx_cfg.s.sata)
    {
        gserx_cfg.s.sata = 0;
        BDK_CSR_WRITE(node, BDK_GSERX_CFG(qlm), gserx_cfg.u);
        bdk_warn("N%d.QLM%d: Disabling SATA for PRBS/pattern generation\n", node, qlm);
        bdk_warn("N%d.QLM%d: SATA PRBS/patterns always run at 6G\n", node, qlm);
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
 * Disable PRBS on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
int __bdk_qlm_disable_prbs(bdk_node_t node, int qlm)
{
    const int NUM_LANES = bdk_qlm_get_lanes(node, qlm);
    BDK_CSR_INIT(phy_ctl, node, BDK_GSERX_PHY_CTL(qlm));
    if (phy_ctl.s.phy_reset)
        return -1;

    for (int lane = 0; lane < NUM_LANES; lane++)
    {
        prbs_errors[qlm][lane] = 0;
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_LBERT_CFG(qlm, lane),
            c.s.lbert_pg_en = 0;
            c.s.lbert_pm_en = 0);
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
uint64_t __bdk_qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane, int clear)
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
void __bdk_qlm_inject_prbs_error(bdk_node_t node, int qlm, int lane)
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
int __bdk_qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop)
{
    bdk_error("Chip doesn't support shallow QLM loopback\n");
    return -1;
}

/**
 * Initialize the QLM mode table
 *
 * @param node   Node to initialize
 * @param qlm    Which QLM
 */
void __bdk_qlm_init_mode_table(bdk_node_t node, int qlm)
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
            case BDK_GSER_LMODE_E_R_25G_REFCLK100:
            case BDK_GSER_LMODE_E_R_5G_REFCLK100:
            case BDK_GSER_LMODE_E_R_8G_REFCLK100:
                /* These modes are used for PCIe where the defaults are
                   correct. Skip programming these */
                continue;
            case BDK_GSER_LMODE_E_R_125G_REFCLK15625_KX:
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
            case BDK_GSER_LMODE_E_R_3125G_REFCLK15625_XAUI:
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
            case BDK_GSER_LMODE_E_R_103125G_REFCLK15625_KR:
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
            case BDK_GSER_LMODE_E_R_125G_REFCLK15625_SGMII:
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
            case BDK_GSER_LMODE_E_R_5G_REFCLK15625_QSGMII:
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
            case BDK_GSER_LMODE_E_R_625G_REFCLK15625_RXAUI:
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
            case BDK_GSER_LMODE_E_R_25G_REFCLK125:
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
            case BDK_GSER_LMODE_E_R_5G_REFCLK125:
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
            case BDK_GSER_LMODE_E_R_8G_REFCLK125:
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
                lane_mode_0.s.tx_mode = 0x2;
                lane_mode_0.s.rx_mode = 0x2;

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
 * Given a valid PEM number, return its speed in Gbaud
 *
 * @param node   Node to use in numa setup
 * @param pem    PEM to get speed of
 *
 * @return Speed in Gbaud. Zero if disabled
 */
int __bdk_qlm_get_gbaud_mhz_pem(bdk_node_t node, int pem)
{
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

/**
 * Get the speed of a QLM using its LMODE. This can't be used on PCIe QLMs.
 *
 * @param node   Node to use in numa setup
 * @param qlm    Which QLM
 *
 * @return QLM speed on Gbaud
 */
int __bdk_qlm_get_gbaud_mhz_lmode(bdk_node_t node, int qlm)
{
    /* QLM is not in PCIe, assume LMODE is good enough for determining
       the speed */
    BDK_CSR_INIT(lane_mode, node, BDK_GSERX_LANE_MODE(qlm));
    switch (lane_mode.s.lmode)
    {
        case BDK_GSER_LMODE_E_R_25G_REFCLK100:
            return 2500;
        case BDK_GSER_LMODE_E_R_5G_REFCLK100:
            return 5000;
        case BDK_GSER_LMODE_E_R_8G_REFCLK100:
            return 8000;
        case BDK_GSER_LMODE_E_R_125G_REFCLK15625_KX:
            return 1250;
        case BDK_GSER_LMODE_E_R_3125G_REFCLK15625_XAUI:
            return 3125;
        case BDK_GSER_LMODE_E_R_103125G_REFCLK15625_KR:
            return 10312;
        case BDK_GSER_LMODE_E_R_125G_REFCLK15625_SGMII:
            return 1250;
        case BDK_GSER_LMODE_E_R_5G_REFCLK15625_QSGMII:
            return 5000;
        case BDK_GSER_LMODE_E_R_625G_REFCLK15625_RXAUI:
            return 6250;
        case BDK_GSER_LMODE_E_R_25G_REFCLK125:
            return 2500;
        case BDK_GSER_LMODE_E_R_5G_REFCLK125:
            return 5000;
        case BDK_GSER_LMODE_E_R_8G_REFCLK125:
            return 8000;
        default:
            return 0;
    }
}

/**
 * Converts a measured reference clock to a likely ideal value. Rounds
 * clock speed to the nearest REF_*Mhz define.
 *
 * @param measured_hz
 *               Measured value
 *
 * @return Value exactly matching a define
 */
int __bdk_qlm_round_refclock(int measured_hz)
{
    int ref_clk;
    if ((measured_hz > REF_100MHZ - REF_100MHZ / 10) && (measured_hz < REF_100MHZ + REF_100MHZ / 10))
    {
        ref_clk = REF_100MHZ;
    }
    else if ((measured_hz > REF_125MHZ - REF_125MHZ / 10) && (measured_hz < REF_125MHZ + REF_125MHZ / 10))
    {
        ref_clk = REF_125MHZ;
    }
    else if ((measured_hz > REF_156MHZ - REF_156MHZ / 10) && (measured_hz < REF_156MHZ + REF_156MHZ / 10))
    {
        ref_clk = REF_156MHZ;
    }
    else
    {
        ref_clk = measured_hz;
        bdk_error("Unexpected reference clock speed of %d Mhz\n", measured_hz / 1000000);
    }
    return ref_clk;
}

/**
 * TWSI reads from the MCU randomly timeout. Retry a few times on
 * failure to try and recover
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param twsi_id   which TWSI bus to use
 * @param dev_addr  Device address (7 bit)
 * @param internal_addr
 *                  Internal address.  Can be 0, 1 or 2 bytes in width
 * @param num_bytes Number of data bytes to read (1-4)
 * @param ia_width_bytes
 *                  Internal address size in bytes (0, 1, or 2)
 *
 * @return Read data, or -1 on failure
 */
static int64_t mcu_read(bdk_node_t node, int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes, int ia_width_bytes)
{
    int read_tries = 0;
    int64_t result;
    do
    {
        result = bdk_twsix_read_ia(node, twsi_id, dev_addr, internal_addr, num_bytes, ia_width_bytes);
        read_tries++;
        if (result < 0)
        {
            BDK_TRACE(QLM, "Timeout %d reading from MCU\n", read_tries);
            bdk_wait_usec(100000);
        }
    } while ((result < 0) && (read_tries < 3));
    return result;
}

static void __bdk_qlm_set_reference(bdk_node_t node, int qlm, int ref_clk)
{
    int use_clock;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX) || CAVIUM_IS_MODEL(CAVIUM_CN83XX) || CAVIUM_IS_MODEL(CAVIUM_CN81XX))
    {
        switch (ref_clk)
        {
            case REF_100MHZ:
                use_clock = 0; /* Common clock 0 */
                BDK_TRACE(QLM, "Setting N%d.QLM%d to use common clock 0\n", node, qlm);
                break;
            case REF_156MHZ:
                use_clock = 1; /* Common clock 1 */
                BDK_TRACE(QLM, "Setting N%d.QLM%d to use common clock 1\n", node, qlm);
                break;
            default:
                use_clock = 2; /* External clock */
                BDK_TRACE(QLM, "Setting N%d.QLM%d to use external clock\n", node, qlm);
                break;
        }
    }
    else
    {
        bdk_error("Update __bdk_qlm_set_reference() for qlm auto config of this chip\n");
        return;
    }
    BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_SEL(qlm),
        c.s.com_clk_sel = (use_clock != 2);
        c.s.use_com1 = (use_clock == 1));
}

/**
 * For Cavium EVB and EBB board, query the MCU to determine the QLM setup. Applying
 * any configuration found.
 *
 * @param node   Node to configure
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_mcu_auto_config(bdk_node_t node)
{
    const int MCU_TWSI_BUS = 0;
    const int MCU_TWSI_ADDRESS = 0x60;
    int64_t data;

    if (bdk_is_platform(BDK_PLATFORM_EMULATOR) || bdk_is_platform(BDK_PLATFORM_ASIM))
        return 0;

    /* Check the two magic number bytes the MCU should return */
    data = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x00, 1, 1);
    if (data != 0xa5)
    {
        printf("QLM Config: MCU not found, skipping auto configuration\n");
        return -1;
    }
    data = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x01, 1, 1);
    if (data != 0x5a)
    {
        bdk_error("QLM Config: MCU magic number incorrect\n");
        return -1;
    }

    /* Read the MCU version */
    int mcu_major = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x02, 1, 1);
    int mcu_minor = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x03, 1, 1);
    BDK_TRACE(QLM, "MCU version %d.%d\n", mcu_major, mcu_minor);
    if ((mcu_major < 2) || ((mcu_major == 2) && (mcu_minor < 30)))
    {
        bdk_error("QLM Config: Unexpected MCU version %d.%d\n", mcu_major, mcu_minor);
        return -1;
    }

    /* Find out how many lanes the MCU thinks are available */
    int lanes = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x16, 1, 1);
    BDK_TRACE(QLM, "MCU says board has %d lanes\n", lanes);
    int correct_lanes = 0;
    if (cavium_is_altpkg(CAVIUM_CN88XX))
        correct_lanes = 22;
    else if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        correct_lanes = 32;
    else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        correct_lanes = 22;
    if (lanes != correct_lanes)
    {
        bdk_error("QLM Config: Unexpected number of lanes (%d) from MCU\n", lanes);
        return -1;
    }

    int lane = 0;
    int qlm = 0;
    while (lane < lanes)
    {
        int write_status;
        int width;
        int mode;
        int speed;
        int refclk;
        /* TWSI reads from the MCU randomly timeout. Retry a few times on
           failure to try and recover */
        int read_tries = 0;
        do
        {
            read_tries++;
            if (read_tries > 3)
            {
                bdk_error("QLM Config: Timeouts reading from MCU\n");
                return -1;
            }
            /* Space request out 20ms */
            bdk_wait_usec(20000);
            /* Select the lane we are interested in */
            write_status = bdk_twsix_write_ia(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x16, 1, 1, lane);
            /* Space request out 20ms */
            bdk_wait_usec(20000);
            /* Get the mode */
            width = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x17, 1, 1);
            mode = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x18, 2, 1);
            speed = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x19, 2, 1);
            refclk = mcu_read(node, MCU_TWSI_BUS, MCU_TWSI_ADDRESS, 0x1a, 1, 1);
        } while ((write_status < 0) || (width < 0) || (mode < 0) || (speed < 0) || (refclk < 0));

        BDK_TRACE(QLM, "MCU lane %d, width %d, mode 0x%x, speed 0x%x, ref 0x%x\n",
            lane, width, mode, speed, refclk);
        if ((width != 0) && (width != 2) && (width != 4) && (width != 8))
        {
            bdk_error("QLM Config: Unexpected interface width (%d) from MCU\n", width);
            return -1;
        }
        /* MCU reports a width of 0 for unconfigured QLMs */
        if (width == 0)
            width = bdk_qlm_get_lanes(node, qlm);
        bdk_qlm_modes_t qlm_mode;
        int qlm_speed = (speed >> 8) * 1000 + (speed & 0xff) * 1000 / 256;
        int use_ref = 0;
        bdk_qlm_mode_flags_t qlm_flags = 0;
        if (mode < 0x4000)
        {
            switch (mode)
            {
                case 0x0000: /* No Configuration */
                    qlm_mode = BDK_QLM_MODE_DISABLED;
                    break;
                case 0x0101: /* PCIe Host */
                    qlm_mode = (width == 8) ? BDK_QLM_MODE_PCIE_1X8 : BDK_QLM_MODE_PCIE_1X4;
                    use_ref = REF_100MHZ;
                    break;
                case 0x0102: /* PCIe Endpoint */
                    qlm_mode = (width == 8) ? BDK_QLM_MODE_PCIE_1X8 : BDK_QLM_MODE_PCIE_1X4;
                    qlm_flags = BDK_QLM_MODE_FLAG_ENDPOINT;
                    use_ref = 0; /* Use the external reference for EP mode */
                    break;
                case 0x1000: /* SGMII */
                    qlm_mode = (width == 2) ? BDK_QLM_MODE_SGMII_2X1 : BDK_QLM_MODE_SGMII_4X1;
                    use_ref = REF_156MHZ;
                    break;
                case 0x2000: /* XAUI */
                    qlm_mode = BDK_QLM_MODE_XAUI_1X4;
                    use_ref = REF_156MHZ;
                    break;
                case 0x2100: /* RXAUI */
                    qlm_mode = (width == 2) ? BDK_QLM_MODE_RXAUI_1X2 : BDK_QLM_MODE_RXAUI_2X2;
                    use_ref = REF_156MHZ;
                    break;
                case 0x2200: /* DXAUI */
                    qlm_mode = BDK_QLM_MODE_XAUI_1X4;
                    use_ref = REF_156MHZ;
                    break;
                case 0x3001: /* Interlaken */
                    qlm_mode = BDK_QLM_MODE_ILK;
                    use_ref = REF_156MHZ;
                    break;
                default:
                    bdk_error("QLM Config: Unexpected interface mode (0x%x) from MCU\n", mode);
                    qlm_mode = BDK_QLM_MODE_DISABLED;
                    break;
            }
        }
        else
        {
            switch (mode)
            {
                case 0x4000: /* SATA */
                    qlm_mode = (width == 2) ? BDK_QLM_MODE_SATA_2X1 : BDK_QLM_MODE_SATA_4X1;
                    use_ref = REF_100MHZ;
                    break;
                case 0x5001: /* XFI */
                    qlm_mode = (width == 2) ? BDK_QLM_MODE_XFI_2X1 : BDK_QLM_MODE_XFI_4X1;
                    use_ref = REF_156MHZ;
                    break;
                case 0x5002: /* 10G-KR */
                    qlm_mode = (width == 2) ? BDK_QLM_MODE_10G_KR_2X1 : BDK_QLM_MODE_10G_KR_4X1;
                    use_ref = REF_156MHZ;
                    break;
                case 0x6001: /* XLAUI */
                    qlm_mode = BDK_QLM_MODE_XLAUI_1X4;
                    use_ref = REF_156MHZ;
                    break;
                case 0x6002: /* 40G-KR4 */
                    qlm_mode = BDK_QLM_MODE_40G_KR4_1X4;
                    use_ref = REF_156MHZ;
                    break;
                default:
                    bdk_error("QLM Config: Unexpected interface mode (0x%x) from MCU\n", mode);
                    qlm_mode = BDK_QLM_MODE_DISABLED;
                    break;
            }
        }
        lane += width;
        do
        {
            int internal_qlm = qlm;
            /* Alternate package parts have different QLM numbers for internal
               versus external. The MCU uses the external numbers */
            if (cavium_is_altpkg(CAVIUM_CN88XX))
            {
                switch (qlm)
                {
                    case 0: /* QLM0 -> QLM4 */
                        internal_qlm = 4;
                        break;
                    case 1: /* QLM1 -> QLM5 */
                        internal_qlm = 5;
                        break;
                    case 2: /* QLM2 -> QLM0 */
                        internal_qlm = 0;
                        break;
                    case 3: /* QLM3 -> QLM1 */
                        internal_qlm = 1;
                        break;
                    case 4: /* DLM4 -> QLM2 */
                        internal_qlm = 2;
                        break;
                    case 5: /* DLM5 -> QLM6 */
                        internal_qlm = 6;
                        break;
                    case 6: /* DLM6 -> QLM7 */
                        internal_qlm = 7;
                        break;
                    default:
                        bdk_error("Invalid external QLM%d from MCU\n", qlm);
                        return -1;
                }
            }
            const char *qlm_mode_str = bdk_qlm_mode_tostring(qlm_mode);
            if (qlm_flags & BDK_QLM_MODE_FLAG_ENDPOINT)
            {
                BDK_TRACE(QLM, "Skipping N%d.QLM%d mode %s(%d), speed %d, flags 0x%x (EP should already be setup)\n",
                    node, internal_qlm, qlm_mode_str, qlm_mode, qlm_speed, qlm_flags);
            }
            else
            {
                BDK_TRACE(QLM, "Setting N%d.QLM%d mode %s(%d), speed %d, flags 0x%x\n",
                    node, internal_qlm, qlm_mode_str, qlm_mode, qlm_speed, qlm_flags);
                /* Set the reference clock for this QLM */
                __bdk_qlm_set_reference(node, internal_qlm, use_ref);
                if (bdk_qlm_set_mode(node, internal_qlm, qlm_mode, qlm_speed, qlm_flags))
                    return -1;
            }
            int num_lanes = bdk_qlm_get_lanes(node, internal_qlm);
            /* CN86XX looks like two lanes each for DLM4-7 */
            if (cavium_is_altpkg(CAVIUM_CN88XX) && (qlm >= 4))
                num_lanes = 2;
            if (qlm_mode == BDK_QLM_MODE_PCIE_1X8)
            {
                /* PCIe x8 is a special case as the QLM config function
                   actually configures both QLMs in one go */
                qlm++;
                width -= 8;
            }
            else if (width >= num_lanes)
                width -= num_lanes;
            else
                width = 0;
            qlm++;
        } while (width > 0);
    }
    return 0;
}

/**
 * Perform RX equalization on a QLM
 *
 * @param node     Node the QLM is on
 * @param qlm      QLM to perform RX equalization on
 * @param qlm_lane Lane to use, or -1 for all lanes
 *
 * @return Zero on success, negative if any lane failed RX equalization
 */
int __bdk_qlm_rx_equalization(bdk_node_t node, int qlm, int qlm_lane)
{
    /* Emulator doesn't support GSER */
    if (bdk_is_platform(BDK_PLATFORM_EMULATOR))
        return 0;
    /* Don't touch QLMs is reset or powered down */
    BDK_CSR_INIT(phy_ctl, node, BDK_GSERX_PHY_CTL(qlm));
    if (phy_ctl.s.phy_pd || phy_ctl.s.phy_reset)
        return -1;
    int gbaud = bdk_qlm_get_gbaud_mhz(node, qlm);
    /* Slow links don't support equalization. CCPI starts 6.25G, others are at 8G */
    if (qlm < 8)
    {
        if (gbaud < 6250)
            return 0;
    }
    else
    {
        BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(qlm));
        if (gserx_spd.s.spd == 0xf) /* Supported with SW init at 6.25G */
        {
            if (gbaud < 6250)
                return 0;
        }
        else /* Only supported at 8G and higher */
        {
            if (gbaud < 8000)
                return 0;
        }
    }
    /* Don't run on PCIe links */
    if (bdk_qlm_get_mode(node, qlm) <= BDK_QLM_MODE_PCIE_1X8)
        return -1;

    int fail = 0; /* Bitmask of lanes that failed */
    int MAX_LANES = bdk_qlm_get_lanes(node, qlm);

    BDK_TRACE(QLM, "N%d.QLM%d: Starting RX equalization on lane %d\n", node, qlm, qlm_lane);
    for (int lane = 0; lane < MAX_LANES; lane++)
    {
        /* Skip lanes we don't care about */
        if ((qlm_lane != -1) && (qlm_lane != lane))
            continue;
        /* Check that the lane has completed CDR lock */
        BDK_CSR_INIT(eie_detsts, node, BDK_GSERX_RX_EIE_DETSTS(qlm));
        if (((1 << lane) & eie_detsts.s.cdrlock) == 0)
        {
            /* Mark bad so we skip this lane below */
            fail |= 1 << lane;
            continue;
        }
        /* Enable software control */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_BR_RXX_CTL(qlm, lane),
            c.s.rxt_swm = 1);
        /* Clear the completion flag and initiate a new request */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_BR_RXX_EER(qlm, lane),
            c.s.rxt_esv = 0;
            c.s.rxt_eer = 1);
    }

    /* Wait for RX equalization to complete */
    for (int lane = 0; lane < MAX_LANES; lane++)
    {
        /* Timing a few of these over XFI on CN73XX, each takes 21-23ms. XLAUI
           was about the same time. DXAUI and RXAUI both took 2-3ms. Put the
           timeout at 250ms, which is roughly 10x my measurements. */
        const int TIMEOUT_US = 250000; /* 250ms */
        /* Skip lanes we don't care about */
        if ((qlm_lane != -1) && (qlm_lane != lane))
            continue;
        /* Skip lane if it failed CDR lock above */
        if (fail & (1 << lane))
            continue;
        BDK_CSR_WAIT_FOR_FIELD(node, BDK_GSERX_BR_RXX_EER(qlm, lane), rxt_esv, ==, 1, TIMEOUT_US);
        BDK_CSR_INIT(gserx_br_rxx_eer, node, BDK_GSERX_BR_RXX_EER(qlm, lane));
        BDK_CSR_MODIFY(c, node, BDK_GSERX_BR_RXX_CTL(qlm, lane),
            c.s.rxt_swm = 0);
        if (gserx_br_rxx_eer.s.rxt_esv)
        {
            BDK_TRACE(QLM, "N%d.QLM%d: Lane %d RX equalization complete. Figure of merit %d (rxt_esm = 0x%x)\n",
                node, qlm, lane, gserx_br_rxx_eer.s.rxt_esm >> 6, gserx_br_rxx_eer.s.rxt_esm);
        }
        else
        {
            BDK_TRACE(QLM, "N%d.QLM%d: Lane %d RX equalization timeout\n", node, qlm, lane);
            fail |= 1 << lane;
        }
    }

    return (fail) ? -1 : 0;
}

/**
 * Configure the TX tuning parameters for a QLM lane. The tuning parameters can
 * be specified as -1 to maintain their current value
 *
 * @param node      Node to configure
 * @param qlm       QLM to configure
 * @param lane      Lane to configure
 * @param tx_swing  Transmit swing (coef 0) Range 0-31
 * @param tx_pre    Pre cursor emphasis (Coef -1). Range 0-15
 * @param tx_post   Post cursor emphasis (Coef +1). Range 0-31
 * @param tx_gain   Transmit gain. Range 0-7
 * @param tx_vboost Transmit voltage boost. Range 0-1
 *
 * @return Zero on success, negative on failure
 */
int __bdk_qlm_tune_lane_tx(bdk_node_t node, int qlm, int lane, int tx_swing, int tx_pre, int tx_post, int tx_gain, int tx_vboost)
{
    /* Read current hardware settings for any parameters not specified */
    if (tx_swing == -1)
    {
        BDK_CSR_INIT(sds_pin_mon_1, node, BDK_GSERX_LANEX_SDS_PIN_MON_1(qlm, lane));
        tx_swing = sds_pin_mon_1.s.pcs_sds_tx_swing;
    }
    if (tx_pre == -1)
    {
        BDK_CSR_INIT(sds_pin_mon_2, node, BDK_GSERX_LANEX_SDS_PIN_MON_2(qlm, lane));
        tx_pre = sds_pin_mon_2.s.pcs_sds_premptap & 0xf;
    }
    if (tx_post == -1)
    {
        BDK_CSR_INIT(sds_pin_mon_2, node, BDK_GSERX_LANEX_SDS_PIN_MON_2(qlm, lane));
        tx_post = sds_pin_mon_2.s.pcs_sds_premptap >> 4;
    }
    if (tx_gain == -1)
    {
        BDK_CSR_INIT(cfg_3, node, BDK_GSERX_LANEX_TX_CFG_3(qlm, lane));
        tx_gain = cfg_3.s.pcs_sds_tx_gain;
    }
    if (tx_vboost == -1)
    {
        BDK_CSR_INIT(sds_pin_mon_2, node, BDK_GSERX_LANEX_SDS_PIN_MON_2(qlm, lane));
        tx_vboost = sds_pin_mon_2.s.pcs_sds_tx_vboost_en;
    }

    /* Check tuning constraints */
    if ((tx_swing < 0) || (tx_swing > 25))
    {
        bdk_error("N%d.QLM%d: Lane %d: Invalid TX_SWING(%d)\n", node, qlm, lane, tx_swing);
        return -1;
    }
    if ((tx_pre < 0) || (tx_pre > 10))
    {
        bdk_error("N%d.QLM%d: Lane %d: Invalid TX_PRE(%d)\n", node, qlm, lane, tx_pre);
        return -1;
    }
    if ((tx_post < 0) || (tx_post > 15))
    {
        bdk_error("N%d.QLM%d: Lane %d: Invalid TX_POST(%d)\n", node, qlm, lane, tx_post);
        return -1;
    }
    if (tx_pre + tx_post - tx_swing > 2)
    {
        bdk_error("N%d.QLM%d: Lane %d: TX_PRE(%d) + TX_POST(%d) - TX_SWING(%d) must be less than or equal to 2\n", node, qlm, lane, tx_pre, tx_post, tx_swing);
        return -1;
    }
    if (tx_pre + tx_post + tx_swing > 35)
    {
        bdk_error("N%d.QLM%d: Lane %d: TX_PRE(%d) + TX_POST(%d) + TX_SWING(%d) must be less than or equal to 35\n", node, qlm, lane, tx_pre, tx_post, tx_swing);
        return -1;
    }

    BDK_TRACE(QLM, "N%d.QLM%d: Lane %d: TX_SWING=%d, TX_PRE=%d, TX_POST=%d, TX_GAIN=%d, TX_VBOOST=%d\n",
        node, qlm, lane, tx_swing, tx_pre, tx_post, tx_gain, tx_vboost);

    /* Manual Tx Swing and Tx Equalization Programming Steps */

    /* To perform a subsequent Tx swing and Tx equalization adjustment:
        a) Disable the Tx coefficient request override enable */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
        c.s.cfg_tx_coeff_req_ovrrd_en = 0;
        c.s.cfg_tx_vboost_en_ovrrd_en = 0);
    /* b) Issue a Control Interface Configuration Override request */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
        c.s.ctlifc_ovrrd_req = 1);

    /* 1) Enable Tx swing and Tx emphasis overrides */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
        c.s.tx_swing_ovrrd_en = 1;
        c.s.tx_premptap_ovrrd_val = 1;
        c.s.tx_vboost_en_ovrrd_en = 1); /* Vboost override */
    /* 2) Program the Tx swing and Tx emphasis Pre-cursor and Post-cursor values */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
        c.s.cfg_tx_swing = tx_swing);
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
        c.s.cfg_tx_premptap = (tx_post << 4) | tx_pre);
    /* Apply TX gain settings */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_3(qlm, lane),
        c.s.pcs_sds_tx_gain = tx_gain);
    /* Apply TX vboost settings */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_3(qlm, lane),
        c.s.cfg_tx_vboost_en = tx_vboost);
    /* 3) Program override for the Tx coefficient request */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_PCS_CTLIFC_0(qlm, lane),
        c.s.cfg_tx_coeff_req_ovrrd_val = 1;
        c.s.cfg_tx_vboost_en_ovrrd_val = 1);
    /* 4) Enable the Tx coefficient request override enable */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
        c.s.cfg_tx_coeff_req_ovrrd_en = 1;
        c.s.cfg_tx_vboost_en_ovrrd_en = 1);
    /* 5) Issue a Control Interface Configuration Override request to start
        the Tx equalizer Optimization cycle which applies the new Tx swing
        and equalization settings */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_PCS_CTLIFC_2(qlm, lane),
        c.s.ctlifc_ovrrd_req = 1);
    /* The new Tx swing and Pre-cursor and Post-cursor settings will now take
       effect. */
    return 0;
}

/**
 * Some QLM speeds need to override the default tuning parameters
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param mode     Desired mode
 * @param baud_mhz Desired speed
 */
void __bdk_qlm_tune(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz)
{
    /* Tuning parameters override the KR training. Don't apply them for KR links */
    switch (mode)
    {
        case BDK_QLM_MODE_10G_KR_2X1:
        case BDK_QLM_MODE_10G_KR_4X1:
        case BDK_QLM_MODE_40G_KR4_1X4:
            return;
        case BDK_QLM_MODE_OCI:
        {
            /* Skip tuning for CCPI running KR training as tuning overrides
               the values found by training */
            BDK_CSR_INIT(qlm_cfg, node, BDK_OCX_QLMX_CFG(qlm - 8));
            if (qlm_cfg.s.trn_ena && !qlm_cfg.s.trn_rxeq_only)
                return;
            break;
        }
        default:
            break;
    }

    /* We're apply tuning for all lanes on this QLM */
    int num_lanes = bdk_qlm_get_lanes(node, qlm);
    for (int lane = 0; lane < num_lanes; lane++)
    {
        /* TX Swing: First read any board specific setting from the environment */
        int swing = bdk_config_get_int(BDK_CONFIG_QLM_TUNING_TX_SWING, node, qlm, lane);
        /* If no setting, use hard coded generic defaults */
        if (swing == -1)
        {
            if (baud_mhz == 6250)
            {
                /* From lab measurements of EBB8800 at 6.25G */
                if (mode == BDK_QLM_MODE_OCI)
                    swing = 0xc;
                else
                    swing = 0x12; /* Email from Brendan Metzner about RXAUI around 2/7/2016 */
            }
            else if (baud_mhz == 10312)
            {
                /* From lab measurements of EBB8800 at 10.3125G */
                swing = 0xd;
            }
        }

        /* TX Premptap: First read any board specific setting from the environment */
        int premptap = bdk_config_get_int(BDK_CONFIG_QLM_TUNING_TX_PREMPTAP, node, qlm, lane);
        /* If no setting, use hard coded generic defaults */
        if (premptap == -1)
        {
            if (baud_mhz == 6250)
            {
                /* From lab measurements of EBB8800 at 6.25G */
                if (mode == BDK_QLM_MODE_OCI)
                    premptap = 0xc0;
                else
                    premptap = 0xa0;
            }
            else if (baud_mhz == 10312)
            {
                /* From lab measurements of EBB8800 at 10.3125G */
                premptap = 0xd0;
            }
        }

        int tx_pre = (premptap == -1) ? -1 : premptap & 0xf;
        int tx_post = (premptap == -1) ? -1 : premptap >> 4;
        int gain = bdk_config_get_int(BDK_CONFIG_QLM_TUNING_TX_GAIN, node, qlm, lane);
        int vboost = bdk_config_get_int(BDK_CONFIG_QLM_TUNING_TX_VBOOST, node, qlm, lane);

        __bdk_qlm_tune_lane_tx(node, qlm, lane, swing, tx_pre, tx_post, gain, vboost);

        /* Email from Brendan Metzner about RXAUI around 2/7/2016 suggested the
           following setting for RXAUI at 6.25G with both PHY or cable. I'm
           applying it to all lanes running at 6.25G */
        if (baud_mhz == 6250)
        {
            /* This is changing the Q/QB error sampler 0 threshold from 0xD
                to 0xF */
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_RX_CFG_4(qlm, lane),
                c.s.cfg_rx_errdet_ctrl = 0xcf6f);
        }
    }
}


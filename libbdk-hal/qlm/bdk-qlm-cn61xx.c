#include <bdk.h>
#include "bdk-qlm-jtag.h"

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 3;
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
        case BDK_IF_SGMII:
        case BDK_IF_XAUI:
        case BDK_IF_HIGIG:
            /* SGMII/XAUI 0, 1 are on QLMs 2, 0 */
            switch (interface)
            {
                case 0: return 2;
                case 1: return 0;
            }
            break;
        default:
            break;
    }
    return -1;
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
    if (qlm == 1)
        return 2;
    else
        return 4;
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
    BDK_CSR_INIT(qlm_cfg, node, BDK_MIO_QLMX_CFG(qlm));
    switch (qlm)
    {
        case 0:
            switch (qlm_cfg.s.qlm_cfg)
            {
                case 0: return BDK_QLM_MODE_PCIE_1X4;
                case 2: return BDK_QLM_MODE_SGMII;
                case 3: return BDK_QLM_MODE_XAUI_1X4;
                default: return BDK_QLM_MODE_DISABLED;
            }
            break;
        case 1:
            switch (qlm_cfg.s.qlm_cfg)
            {
                case 0: return BDK_QLM_MODE_PCIE_1X2;
                case 1: return BDK_QLM_MODE_PCIE_2X1;
                default: return BDK_QLM_MODE_DISABLED;
            }
            break;
        case 2:
            switch (qlm_cfg.s.qlm_cfg)
            {
                case 2: return BDK_QLM_MODE_SGMII;
                case 3: return BDK_QLM_MODE_XAUI_1X4;
                default: return BDK_QLM_MODE_DISABLED;
            }
            break;
    }
    return BDK_QLM_MODE_DISABLED;
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
    BDK_CSR_INIT(qlm_cfg, node, BDK_MIO_QLMX_CFG(qlm));
    switch (qlm_cfg.s.qlm_spd)
    {
        case 0: return 5000;    /* 5     Gbaud */
        case 1: return 5000;    /* 2.5/5 Gbaud */
        case 2: return 2500;    /* 2.5   Gbaud */
        case 3: return 1250;    /* 1.25  Gbaud */
        case 4: return 1250;    /* 1.25  Gbaud */
        case 5: return 6250;    /* 6.25  Gbaud */
        case 6: return 5000;    /* 5     Gbaud */
        case 7: return 2500;    /* 2.5   Gbaud */
        case 8: return 3125;    /* 3.125 Gbaud */
        case 9: return 2500;    /* 2.5   Gbaud */
        case 10: return 1250;   /* 1.25  Gbaud */
        case 11: return 5000;   /* 5     Gbaud */
        case 12: return 6250;   /* 6.25  Gbaud */
        case 13: return 3750;   /* 3.75  Gbaud */
        case 14: return 3125;   /* 3.125 Gbaud */
        default: return 0;      /* Disabled */
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
    /* Place QLM in power down */
    bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 0);
    bdk_qlm_jtag_set(qlm, -1, "cfg_pwrup_set", 0);
    bdk_qlm_jtag_set(qlm, -1, "cfg_pwrup_clr", 1);

    /* Take and hold QLM out of reset */
    bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_set", 1);
    bdk_qlm_jtag_set(qlm, -1, "cfg_pwrup_clr", 0);

    /* Turn off Shallow Loopback */
    bdk_qlm_jtag_set(qlm, -1, "shlpbck", 0);
    bdk_qlm_jtag_set(qlm, -1, "sl_enable", 0);

    /* Turn off PRBS */
    bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_rst_n", 0);
    bdk_qlm_jtag_set(qlm, -1, "jtg_run_prbs7", 0);
    bdk_qlm_jtag_set(qlm, -1, "jtg_run_prbs31", 0);
    bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_tx_rst_n", 0);
    bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_rx_rst_n", 0);
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
    if (dir & BDK_QLM_DIRECTION_TX)
    {
        /* 61xx PRBS:
            cfg_pwrup_set 0 (Covered in qlm.do_reset)
            cfg_pwrup_clr 1 (Covered in qlm.do_reset)
            cfg_rst_n_set 1 (Covered in qlm.do_reset)
            jtg_prbs_mode 0 (0=PRBS7, 1=PRBS15, 2=PRBS23, 3=PRBS31)
            cfg_pwrup_set 1
            jtg_prbs_tx_rst_n 1
            jtg_prbs_rx_rst_n 1 */
        int jtg_prbs_mode;
        switch (prbs)
        {
            case 7:
                jtg_prbs_mode = 0; /* PRBS7 */
                break;
            case 15:
                jtg_prbs_mode = 1; /* PRBS15 */
                break;
            case 23:
                jtg_prbs_mode = 2; /* PRBS23 */
                break;
            case 31:
                jtg_prbs_mode = 3; /* PRBS31 */
                break;
            default:
                bdk_error("Invalid PRBS mode. 7,  15,  23,  31 are supported\n");
                return -1;
        }
        bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_mode", jtg_prbs_mode);

        /* Disable pattern inversion. Octeon's default (0) has the PRBS
            pattern inverted. These are persistent and need clearing. */
        bdk_qlm_jtag_set(qlm, -1, "cfg_tx_pol_set", 1);
        bdk_qlm_jtag_set(qlm, -1, "cfg_rx_pol_set", 1);

        /* Power up the QLM */
        bdk_qlm_jtag_set(qlm, -1, "cfg_pwrup_set", 1);

        /* Take PRBS TX out of reset */
        bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_tx_rst_n", 1);
    }

    if (dir & BDK_QLM_DIRECTION_RX)
    {
        /* Take PRBS RX out of reset */
        bdk_qlm_jtag_set(qlm, -1, "jtg_prbs_rx_rst_n", 1);
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
    int locked = bdk_qlm_jtag_get(qlm, lane, "prbs_lock");
    if (locked)
        return bdk_qlm_jtag_get(qlm, lane, "prbs_err_cnt");
    else
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
    //qlm.do_reset(qlm_num)

    /* Turn on Shallow Loopback */
    switch (loop)
    {
        case BDK_QLM_LOOP_0_3:
            bdk_qlm_jtag_set(qlm, -1, "shlpbck", 1);
            break;
        case BDK_QLM_LOOP_1_2:
            bdk_qlm_jtag_set(qlm, -1, "shlpbck", 3);
            break;
        default:
            return -1;
    }
    bdk_qlm_jtag_set(qlm, -1, "sl_posedge_sample", 0);
    bdk_qlm_jtag_set(qlm, -1, "sl_enable", 1);

    /* Power up the QLM */
    bdk_qlm_jtag_set(qlm, -1, "cfg_pwrup_set", 1);
    return 0;
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn61xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn61xx);
    extern void __bdk_qlm_chip_tweak_5Ghz_G16467(void);
    __bdk_qlm_chip_tweak_5Ghz_G16467();
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn61xx = {
    .chip_model = OCTEON_CN61XX,
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


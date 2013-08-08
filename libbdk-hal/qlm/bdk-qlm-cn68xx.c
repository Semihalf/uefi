#include <bdk.h>
#include "bdk-qlm-jtag.h"

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 5; /* CN68XX has 5 QLMs */
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
            if (interface == 1)
            {
                /* SGMII 1 is illegal */
                return -1;
            }
            else if (interface < 5)
            {
                /* SGMII 0, 2, 3, and 4 are on QLMs 0, 2, 3, 4 */
                bdk_qlm_modes_t mode = bdk_qlm_get_mode(node, interface);
                if (mode == BDK_QLM_MODE_SGMII)
                    return interface;
                else
                    return -1;
            }
            else
                return -1;
            break;
        case BDK_IF_XAUI:
        case BDK_IF_HIGIG:
            if (interface == 1)
            {
                /* XAUI 1 only exists in RXAUI mode */
                if (bdk_qlm_get_mode(node, 0) == BDK_QLM_MODE_RXAUI_2X2)
                    return 0;
                else
                    return -1;
            }
            else if (interface < 5)
            {
                bdk_qlm_modes_t mode = bdk_qlm_get_mode(node, interface);
                /* XAUI 0, 2, 3, and 4 are on QLMs 0, 2, 3, 4 */
                if ((mode == BDK_QLM_MODE_XAUI_1X4) || (mode == BDK_QLM_MODE_RXAUI_2X2))
                    return interface;
                else
                    return -1;
            }
            else
                return -1;
        case BDK_IF_ILK:
            /* ILK 0 and 1 span QLMs 1, 2 depending on lanes */
            if (interface < 2)
            {
                bdk_qlm_modes_t mode = bdk_qlm_get_mode(node, 1);
                if (mode == BDK_QLM_MODE_ILK)
                    return 1;
                else
                    return -1;
            }
            else
                return -1;
        case BDK_IF_DPI:
            /* PCIe 0 and 1 are on QLM3 and QLM1 */
            if (interface < 2)
            {
                int qlm = (interface) ? 1 : 3;
                bdk_qlm_modes_t mode = bdk_qlm_get_mode(node, qlm);
                if (mode == BDK_QLM_MODE_PCIE_1X4)
                    return qlm;
                else
                    return -1;
            }
            else
                return -1;
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
    return 4; /* All QLMs have 4 lanes each */
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
    switch (qlm_cfg.s.qlm_cfg)
    {
        case 0: return BDK_QLM_MODE_PCIE_1X4;
        case 1: return BDK_QLM_MODE_ILK;
        case 2: return BDK_QLM_MODE_SGMII;
        case 3: return BDK_QLM_MODE_XAUI_1X4;
        case 7: return BDK_QLM_MODE_RXAUI_2X2;
        default: return BDK_QLM_MODE_DISABLED;
    }
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
    /* Chip has straps, so software can't change the mode */
    if ((mode == bdk_qlm_get_mode(node, qlm)) &&
        (baud_mhz == bdk_qlm_get_gbaud_mhz(node, qlm)))
        return 0;
    else
        return -1;
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
        case 1: return 2500;    /* 2.5/5 Gbaud */
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
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn61xx;
    return bdk_qlm_ops_cn61xx.measure_refclock(node, qlm);
}

static void __bdk_qlm_powerup_G16467_part1(int qlm)
{
    /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive QLM
        jitter for 6.25 Gbaud */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
    {
        /* This workaround only applies to QLMs running at 6.25Ghz */
        if (bdk_qlm_get_gbaud_mhz(0, qlm) == 6250)
        {
            if (bdk_qlm_jtag_get(qlm, 0, "clkf_byp") != 20)
            {
                bdk_qlm_jtag_set(qlm, -1, "clkf_byp", 20);
                bdk_wait_usec(100); /* Wait 100us for links to stabalize */
                /* Allow the QLM to exit reset */
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 0);
                /* Allow TX on QLM */
                bdk_qlm_jtag_set(qlm, -1, "cfg_tx_idle_set", 0);
            }
        }
    }
}

void __bdk_qlm_powerup_G16467_part2(int qlm)
{
    /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive
        QLM jitter for 6.25 Gbaud */
    /* This workaround only applies to QLMs running ILK at 6.25Ghz */
    if ((bdk_qlm_get_gbaud_mhz(bdk_numa_local(), qlm) == 6250) && (bdk_qlm_jtag_get(qlm, 0, "clkf_byp") != 20))
    {
        bdk_wait_usec(100); /* Wait 100us for links to stabalize */
        bdk_qlm_jtag_set(qlm, -1, "clkf_byp", 20);
        /* Allow the QLM to exit reset */
        bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 0);
        bdk_wait_usec(100); /* Wait 100us for links to stabalize */
        /* Allow TX on QLM */
        bdk_qlm_jtag_set(qlm, -1, "cfg_tx_idle_set", 0);
    }
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

    /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive QLM
        jitter for 6.25 Gbaud */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
    {
        /* This workaround only applies to QLMs running at 6.25Ghz */
        if ((bdk_qlm_get_gbaud_mhz(node, qlm) == 6250) &&
            (bdk_qlm_jtag_get(qlm, 0, "clkf_byp") != 16))
            bdk_qlm_jtag_set(qlm, -1, "clkf_byp", 16);
    }

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
        /* 68xx PRBS:
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

        __bdk_qlm_powerup_G16467_part1(qlm);

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

    __bdk_qlm_powerup_G16467_part1(qlm);
    return 0;
}

/**
 * The workaround for G-16467 applies to a number of chips at
 * 5Ghz. This function implements the workaround for all chips
 * at 5Ghz, but doesn't do 6.25Ghz. The CN68XX pass 2.0
 * workaround is different and done somewhere else.
 */
void __bdk_qlm_chip_tweak_5Ghz_G16467(bdk_node_t node)
{
    int num_qlms = bdk_qlm_get_num(node);
    for (int qlm=0; qlm<num_qlms; qlm++)
    {
        /* This workaround only applies to QLMs running at 5Ghz, but not PCIe */
        if ((bdk_qlm_get_gbaud_mhz(node, qlm) == 5000) &&
            (bdk_qlm_get_mode(node, qlm) != BDK_QLM_MODE_PCIE_1X4))
        {
            int ir50dac = bdk_qlm_jtag_get(qlm, 0, "ir50dac");
            if (ir50dac < 31)
            {
                bdk_qlm_jtag_set(qlm, -1, "cfg_cdr_trunc", 0);
                /* Hold the QLM in reset while we ramp ir50dac */
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_set", 0);
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 1);
                while (++ir50dac <= 31)
                    bdk_qlm_jtag_set(qlm, -1, "ir50dac", ir50dac);
                /* Don't force reset anymore */
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 0);
            }
        }
    }
}


/**
 * Apply QLM tweaks based on the chip errata
 */
static void qlm_chip_tweak(bdk_node_t node)
{
    int num_qlms = bdk_qlm_get_num(node);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
    {
        __bdk_qlm_chip_tweak_5Ghz_G16467(node);
        /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive
            QLM jitter for 6.25 Gbaud */
        for (int qlm=0; qlm<num_qlms; qlm++)
        {
            /* This workaround only applies to QLMs running at 6.25Ghz */
            if (bdk_qlm_get_gbaud_mhz(node, qlm) == 6250)
            {
                bdk_qlm_jtag_set(qlm, -1, "cfg_cdr_trunc", 0);
                /* Hold the QLM in reset */
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_set", 0);
                bdk_qlm_jtag_set(qlm, -1, "cfg_rst_n_clr", 1);
                /* Force TX to be idle */
                bdk_qlm_jtag_set(qlm, -1, "cfg_tx_idle_clr", 0);
                bdk_qlm_jtag_set(qlm, -1, "cfg_tx_idle_set", 1);
                if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_0))
                {
                    int ir50dac = bdk_qlm_jtag_get(qlm, 0, "ir50dac");
                    while (++ir50dac <= 31)
                        bdk_qlm_jtag_set(qlm, -1, "ir50dac", ir50dac);
                }
                bdk_qlm_jtag_set(qlm, -1, "div4_byp", 0);
                bdk_qlm_jtag_set(qlm, -1, "clkf_byp", 16);
                bdk_qlm_jtag_set(qlm, -1, "serdes_pll_byp", 1);
                bdk_qlm_jtag_set(qlm, -1, "spdsel_byp", 1);
                /* The QLM wil lbe taken out of reset later when the PLL is changed */
            }
        }
    }
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn68xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn68xx);
    qlm_chip_tweak(node);
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn68xx = {
    .chip_model = OCTEON_CN68XX,
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


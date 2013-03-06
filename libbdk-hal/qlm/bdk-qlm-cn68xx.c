#include <bdk.h>
#include "bdk-qlm-jtag.h"
#include <stdio.h>

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(void)
{
    return 5;
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
static int qlm_get_qlm_num(bdk_if_t iftype, int interface)
{
    switch (iftype)
    {
        case BDK_IF_SGMII:
            /* SGMII 0, 2, 3, and 4 are on QLMs 0, 2, 3, 4 */
            /* SGMII 1 is illegal */
            switch (interface)
            {
                case 0: return 0;
                case 2: return 2;
                case 3: return 3;
                case 4: return 4;
            }
            break;
        case BDK_IF_XAUI:
        case BDK_IF_HIGIG:
            /* XAUI 0, 1, 2, 3, and 4 are on QLMs 0, 0, 2, 3, 4 */
            /* XAUI 1 only exists in RXAUI mode */
            switch (interface)
            {
                case 0: return 0;
                case 1: return 0;
                case 2: return 2;
                case 3: return 3;
                case 4: return 4;
            }
            break;
        case BDK_IF_ILK:
            /* ILK 0 and 1 span QLMs 1, 2 depending on lanes */
            switch (interface)
            {
                case 0: return 1;
                case 1: return 1;
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
static int qlm_get_lanes(int qlm)
{
    return 4;
}


/**
 * Get the mode of a QLM as a human readable string
 *
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
static const char *qlm_get_mode(int qlm)
{
    BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
    switch (qlm_cfg.s.qlm_cfg)
    {
        case 0: return "PCIE";
        case 1: return "ILK";
        case 2: return "SGMII";
        case 3: return "XAUI";
        case 7: return "RXAUI";
        default: return "RESERVED";
    }
}


/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
static int qlm_get_gbaud_mhz(int qlm)
{
    BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
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
static int qlm_measure_refclock(int qlm)
{
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn61xx;
    return bdk_qlm_ops_cn61xx.measure_refclock(qlm);
}

/**
 * The workaround for G-16467 applies to a number of chips at
 * 5Ghz. This function implements the workaround for all chips
 * at 5Ghz, but doesn't do 6.25Ghz. The CN68XX pass 2.0
 * workaround is different and done somewhere else.
 */
void __bdk_qlm_chip_tweak_5Ghz_G16467(void)
{
    int num_qlms = bdk_qlm_get_num();
    for (int qlm=0; qlm<num_qlms; qlm++)
    {
        /* This workaround only applies to QLMs running at 5Ghz, but not PCIe */
        if ((bdk_qlm_get_gbaud_mhz(qlm) == 5000) &&
            (strstr(bdk_qlm_get_mode(qlm), "PCIE") == NULL))
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
static void qlm_chip_tweak(void)
{
    int num_qlms = bdk_qlm_get_num();

    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS1_X))
    {
        /* (G-16094) QLM Gen2 Equalizer Default Setting Change */
        for (int qlm=0; qlm<num_qlms; qlm++)
        {
            bdk_qlm_jtag_set(qlm, -1, "rx_cap_gen2", 0x1);
            bdk_qlm_jtag_set(qlm, -1, "rx_eq_gen2", 0x8);
        }
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_X))
    {
        __bdk_qlm_chip_tweak_5Ghz_G16467();
        /* Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive
            QLM jitter for 6.25 Gbaud */
        for (int qlm=0; qlm<num_qlms; qlm++)
        {
            /* This workaround only applies to QLMs running at 6.25Ghz */
            if (bdk_qlm_get_gbaud_mhz(qlm) == 6250)
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
static void qlm_init(void)
{
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn68xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn68xx);
    qlm_chip_tweak();
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn68xx = {
    .chip_model = OCTEON_CN68XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
};


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
static int qlm_get_qlm_num(bdk_if_t iftype, int interface)
{
    switch (iftype)
    {
        case BDK_IF_SGMII:
        case BDK_IF_XAUI:
        case BDK_IF_HIGIG:
            /* SGMII/XAUI 0, 1 are on QLMs 2, 1 */
            switch (interface)
            {
                case 0: return 2;
                case 1: return 1;
            }
            break;
        case BDK_IF_SRIO:
            /* SRIO 0, 1 are on QLM 0 */
            switch (interface)
            {
                case 0: return 0;
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
        case 0: return "PCIE gen2";
        case 1: return "SRIO 1x4 short";
        case 2: return "PCIE gen1 only";
        case 3: return "SRIO 1x4 long";
        case 4: return "SRIO 2x2 short";
        case 5: return "SRIO 4x1 short";
        case 6: return "SRIO 2x2 long";
        case 7: return "SRIO 4x1 long";
        case 8: return "PCIE gen2";
        case 9: return "SGMII";
        case 10: return "PCIE gen1 only";
        case 11: return "XAUI";
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
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn63xx;
    return bdk_qlm_ops_cn63xx.measure_refclock(qlm);
}


/**
 * Apply QLM tweaks based on the chip errata
 */
static void qlm_chip_tweak(void)
{
    int num_qlms = bdk_qlm_get_num();

    extern void __bdk_qlm_chip_tweak_5Ghz_G16467(void);
    __bdk_qlm_chip_tweak_5Ghz_G16467();
    /* (G-16094) QLM Gen2 Equalizer Default Setting Change */
    for (int qlm=0; qlm<num_qlms; qlm++)
    {
        bdk_qlm_jtag_set(qlm, -1, "rx_cap_gen2", 0x1);
        bdk_qlm_jtag_set(qlm, -1, "rx_eq_gen2", 0x8);
    }
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(void)
{
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn66xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn66xx);
    qlm_chip_tweak();
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn66xx = {
    .chip_model = OCTEON_CN63XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
};


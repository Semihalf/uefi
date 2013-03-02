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
    return 2;
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
            if (interface == 0)
                return 0;
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
    return 2;
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
    switch (qlm)
    {
        case 0:
            switch (qlm_cfg.s.qlm_cfg)
            {
                case 2: return "SGMII";
                default: return "RESERVED";
            }
            break;
        case 1:
            switch (qlm_cfg.s.qlm_cfg)
            {
                case 0: return "PCIE 1x2";
                case 1: return "PCIE 2x1";
                default: return "RESERVED";
            }
            break;
    }
    return "UNKOWN";
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
static int qlm_measure_refclock(int qlm)
{
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn63xx;
    return bdk_qlm_ops_cn63xx.measure_refclock(qlm);
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(void)
{
    /* Same as CN66XX */
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn66xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn66xx);
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cnf71xx = {
    .chip_model = OCTEON_CNF71XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
};


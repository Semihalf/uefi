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
    return 14;
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
    bdk_fatal("bdk_qlm_get called incorrectly for type=%d, interface=%d\n", iftype, interface);
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
    if (qlm < 8)
    {
        BDK_CSR_INIT(gserx_cfg, BDK_GSERX_CFG(qlm));
        if (gserx_cfg.s.pcie)
            return "PCIE";
        else if (gserx_cfg.s.ila)
            return "ILK";
        else if (gserx_cfg.s.bgx)
            return "BGX";
        else
            return "RESERVED";
    }
    else
        return "OCI";
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
    if (qlm < 8)
    {
        return 6250; /* FIXME */
    }
    else
    {
        BDK_CSR_INIT(gserx_spd, BDK_GSERX_SPD(qlm));
        switch (gserx_spd.s.spd & 0x3)
        {
            case 0: return 1250;
            case 1: return 2500;
            case 2: return 3125;
            case 3: return 5000;
            case 4: return 6250;
            case 5: return 8000;
            case 6: return 10000;
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
static int qlm_measure_refclock(int qlm)
{
    /* We can't measure the OCI QLMs */
    if (qlm >= 8)
        return 0;

    /* Disable the PTP event counter while we configure it */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Count on rising edge, Choose which QLM to count */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG,
        c.s.evcnt_edge = 0;
        c.s.evcnt_in = 0x20 + qlm);
    /* Clear MIO_PTP_EVT_CNT */
    int64_t count = BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT);
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, -count);
    /* Set MIO_PTP_EVT_CNT to 1 billion */
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, 1000000000);
    /* Enable the PTP event counter */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 1);
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Wait for 50ms */
    bdk_wait_usec(50000);
    /* Read the counter */
    count = BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT);
    uint64_t stop_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Disable the PTP event counter */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Clock counted down, so reverse it */
    count = 1000000000 - count;
    /* Return the rate */
    return count * bdk_clock_get_rate(BDK_CLOCK_CORE) / (stop_cycle - start_cycle);
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(void)
{
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn78xx = {
    .chip_model = OCTEON_CN78XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
};


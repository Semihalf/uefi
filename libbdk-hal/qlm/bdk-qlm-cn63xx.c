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
            /* SGMII/XAUI 0 are on QLM 2 */
            switch (interface)
            {
                case 0: return 2;
            }
            break;
        case BDK_IF_SRIO:
            /* SRIO 0, 1 are on QLMs 0, 1 */
            switch (interface)
            {
                case 0: return 0;
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
    if (qlm == 2)
    {
        BDK_CSR_INIT(inf_mode, BDK_GMXX_INF_MODE(0));
        switch (inf_mode.s.mode)
        {
            case 0: return "SGMII";
            case 1: return "XAUI";
            default: return "RESERVED";
        }
    }
    else
    {
        BDK_CSR_INIT(status_reg, BDK_SRIOX_STATUS_REG(qlm));
        if (status_reg.s.srio)
            return "SRIO 1x4";
        else
            return "PCIE";
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
    if (qlm == 2)
    {
        BDK_CSR_INIT(inf_mode, BDK_GMXX_INF_MODE(0));
        switch (inf_mode.s.speed)
        {
            case 0: return 5000;    /* 5     Gbaud */
            case 1: return 2500;    /* 2.5   Gbaud */
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
    else
    {
        BDK_CSR_INIT(status_reg, BDK_SRIOX_STATUS_REG(qlm));
        if (status_reg.s.srio)
        {
            BDK_CSR_INIT(sriomaintx_port_0_ctl2, BDK_SRIOMAINTX_PORT_0_CTL2(qlm));
            switch (sriomaintx_port_0_ctl2.s.sel_baud)
            {
                case 1: return 1250;    /* 1.25  Gbaud */
                case 2: return 2500;    /* 2.5   Gbaud */
                case 3: return 3125;    /* 3.125 Gbaud */
                case 4: return 5000;    /* 5     Gbaud */
                case 5: return 6250;    /* 6.250 Gbaud */
                default: return 0;      /* Disabled */
            }
        }
        else
        {
            BDK_CSR_INIT(pciercx_cfg032, BDK_PCIERCX_CFG032(qlm));
            switch (pciercx_cfg032.s.ls)
            {
                case 1:
                    return 2500;
                case 2:
                    return 5000;
                case 4:
                    return 8000;
                default:
                {
                    BDK_CSR_INIT(mio_rst_boot, BDK_MIO_RST_BOOT);
                    if ((qlm == 0) && mio_rst_boot.s.qlm0_spd == 0xf)
                        return 0;
                    if ((qlm == 1) && mio_rst_boot.s.qlm1_spd == 0xf)
                        return 0;
                    return 5000; /* Best guess I can make */
                }
            }
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
    /* Disable the PTP event counter while we configure it */
    BDK_CSR_READ(BDK_MIO_PTP_CLOCK_CFG); /* For CN63XXp1 errata */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Count on rising edge, Choose which QLM to count */
    BDK_CSR_READ(BDK_MIO_PTP_CLOCK_CFG); /* For CN63XXp1 errata */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG,
        c.s.evcnt_edge = 0;
        c.s.evcnt_in = 0x10 + qlm);
    /* Clear MIO_PTP_EVT_CNT */
    BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT); /* For CN63XXp1 errata */
    int64_t count = BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT);
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, -count);
    /* Set MIO_PTP_EVT_CNT to 1 billion */
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, 1000000000);
    /* Enable the PTP event counter */
    BDK_CSR_READ(BDK_MIO_PTP_CLOCK_CFG); /* For CN63XXp1 errata */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 1);
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Wait for 50ms */
    bdk_wait_usec(50000);
    /* Read the counter */
    BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT); /* For CN63XXp1 errata */
    count = BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT);
    uint64_t stop_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Disable the PTP event counter */
    BDK_CSR_READ(BDK_MIO_PTP_CLOCK_CFG); /* For CN63XXp1 errata */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Clock counted down, so reverse it */
    count = 1000000000 - count;
    /* Return the rate */
    return count * bdk_clock_get_rate(BDK_CLOCK_CORE) / (stop_cycle - start_cycle);
}

/**
 * Apply QLM tweaks based on the chip errata
 */
static void qlm_chip_tweak(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X))
    {
        /* (G-14395) Bad Default SERDES De-emphasis */
        /* Only applies to pass 1.0. */
        if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
        {
            /* QLM0: PCIe or SRIO */
            BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM0,
                ciu_qlm.s.txbypass = 1;
                ciu_qlm.s.txdeemph = 5;
                ciu_qlm.s.txmargin = 0x17);
            /* QLM1: PCIe or SRIO */
            BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM1,
                ciu_qlm.s.txbypass = 1;
                ciu_qlm.s.txdeemph = 5;
                ciu_qlm.s.txmargin = 0x17);
            BDK_CSR_INIT(mode, BDK_GMXX_INF_MODE(0));
            if (mode.s.type == 1)
            {
                /* QLM2: XAUI */
                BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
                    ciu_qlm.s.txbypass = 1;
                    ciu_qlm.s.txdeemph = 0x5;
                    ciu_qlm.s.txmargin = 0x1a);
            }
            else
            {
                /* QLM2: SGMII */
                BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
                    ciu_qlm.s.txbypass = 1;
                    ciu_qlm.s.txdeemph = 0xf;
                    ciu_qlm.s.txmargin = 0xd);
            }
        }

    }
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS2_X))
    {
        /* (G-15273) New 156.25 MHz SERDES electricals not optimal */
        /* CN63XX Pass 2.x errata G-15273 requires the QLM
            De-emphasis be programmed when using a 156.25Mhz ref clock */
        /* Read the QLM speed pins */
        BDK_CSR_INIT(mio_rst_boot, BDK_MIO_RST_BOOT);
        if (mio_rst_boot.cn63xx.qlm2_spd == 4)
        {
            BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
                ciu_qlm.s.txbypass = 1;
                ciu_qlm.s.txdeemph = 0x0;
                ciu_qlm.s.txmargin = 0xf);
        }
        else if (mio_rst_boot.cn63xx.qlm2_spd == 0xb)
        {
            BDK_CSR_MODIFY(ciu_qlm, BDK_CIU_QLM2,
                ciu_qlm.s.txbypass = 1;
                ciu_qlm.s.txdeemph = 0xa;
                ciu_qlm.s.txmargin = 0x1f);
        }
        /* More tweaks are in bdk-srio.c */
    }
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(void)
{
    extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn63xx[];
    __bdk_qlm_jtag_init(__bdk_qlm_jtag_field_cn63xx);
    qlm_chip_tweak();
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn63xx = {
    .chip_model = OCTEON_CN63XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_mode = qlm_get_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
};


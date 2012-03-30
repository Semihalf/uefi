#include <bdk.h>
#include "bdk-qlm-jtag.h"
#include <stdio.h>

/**
 * The JTAG chain for CN52XX and CN56XX is 4 * 268 bits long, or 1072.
 * CN5XXX full chain shift is:
 *     new data => lane 3 => lane 2 => lane 1 => lane 0 => data out
 * The JTAG chain for CN63XX is 4 * 300 bits long, or 1200.
 * The JTAG chain for CN68XX is 4 * 304 bits long, or 1216.
 * The JTAG chain for CN66XX is 4 * 304 bits long, or 1216.
 * CN6XXX full chain shift is:
 *     new data => lane 0 => lane 1 => lane 2 => lane 3 => data out
 * Shift LSB first, get LSB out
 */
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn63xx[];
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn66xx[];
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn68xx[];

static const __bdk_qlm_jtag_field_t *__bdk_qlm_jtag_field_current;
static int __bdk_qlm_jtag_length;
#define MAX_JTAG_UINT32 40 /* This gives space for 1280(40*32) bits */
static uint32_t __bdk_qlm_jtag_xor_ref[5][MAX_JTAG_UINT32];

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
int bdk_qlm_get_num(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 5;
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
        return 3;
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 3;
    else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        return 3;
    else if (OCTEON_IS_MODEL(OCTEON_CNF71XX))
        return 2;

    bdk_error("bdk_qlm_get_num: Needs update for this chip\n");
    return 0;
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
int bdk_qlm_get(bdk_if_t iftype, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
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
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
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
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
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
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
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
    }
    else if (OCTEON_IS_MODEL(OCTEON_CNF71XX))
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
    }
    bdk_fatal("bdk_qlm_get called incorrectly for type=%d, interface=%d\n", iftype, interface);
}

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
int bdk_qlm_get_lanes(int qlm)
{
    if (OCTEON_IS_MODEL(OCTEON_CN61XX) && (qlm == 1))
        return 2;
    else if (OCTEON_IS_MODEL(OCTEON_CNF71XX))
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
const char *bdk_qlm_get_mode(int qlm)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
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
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
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
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
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
    else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
    {
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
        switch (qlm)
        {
            case 0:
                switch (qlm_cfg.s.qlm_cfg)
                {
                    case 0: return "PCIE 1x4";
                    case 2: return "SGMII";
                    case 3: return "XAUI";
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
            case 2:
                switch (qlm_cfg.s.qlm_cfg)
                {
                    case 2: return "SGMII";
                    case 3: return "XAUI";
                    default: return "RESERVED";
                }
                break;
        }
    }
    else if (OCTEON_IS_MODEL(OCTEON_CNF71XX))
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
    }
    bdk_error("bdk_qlm_get_mode: Needs update for this chip\n");
    return "UNKNOWN";
}


/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
int bdk_qlm_get_gbaud_mhz(int qlm)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX) || OCTEON_IS_MODEL(OCTEON_CN66XX) || OCTEON_IS_MODEL(OCTEON_CN61XX) || OCTEON_IS_MODEL(OCTEON_CNF71XX))
    {
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
        switch (qlm_cfg.s.qlm_spd)
        {
            case 0: return 5000;    /* 5     Gbaud */
            case 1: return (OCTEON_IS_MODEL(OCTEON_CN61XX)||OCTEON_IS_MODEL(OCTEON_CNF71XX)) ? 5000 : 2500; /* 2.5/5 Gbaud */
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
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
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
    bdk_error("bdk_qlm_get_gbaud_mhz: Needs update for this chip\n");
    return 0;
}


/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
int bdk_qlm_measure_clock(int qlm)
{
    /* Force the reference to 156.25Mhz when running in simulation.
        This supports the most speeds */
    if (bdk_is_simulation())
        return 156250000;

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
 * Lookup the bit information for a JTAG field name
 *
 * @param name   Name to lookup
 *
 * @return Field info, or NULL on failure
 */
static const __bdk_qlm_jtag_field_t *__bdk_qlm_lookup_field(const char *name)
{
    const __bdk_qlm_jtag_field_t *ptr = __bdk_qlm_jtag_field_current;
    while (ptr->name)
    {
        if (strcmp(name, ptr->name) == 0)
            return ptr;
        ptr++;
    }
    bdk_error("__bdk_qlm_lookup_field: Illegal field name %s\n", name);
    return NULL;
}


/**
 * Get a field in a QLM JTAG chain
 *
 * @param qlm    QLM to get
 * @param lane   Lane in QLM to get
 * @param name   String name of field
 *
 * @return JTAG field value
 */
uint64_t bdk_qlm_jtag_get(int qlm, int lane, const char *name)
{
    const __bdk_qlm_jtag_field_t *field = __bdk_qlm_lookup_field(name);
    if (!field)
        return -1; /* This is obviously invalid for any field as it is wider than the field */
    int num_lanes = bdk_qlm_get_lanes(qlm);

    /* Capture the current settings */
    __bdk_qlm_jtag_capture(qlm);
    /* Shift past lanes we don't care about. CN6XXX shifts lane 3 first */
    __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length * (num_lanes-1-lane));
    /* Shift to the start of the field */
    __bdk_qlm_jtag_shift_zeros(qlm, field->start_bit);
    /* Shift out the value and return it */
    return __bdk_qlm_jtag_shift(qlm, field->stop_bit - field->start_bit + 1, 0);
}


/**
 * Set a field in a QLM JTAG chain
 *
 * @param qlm    QLM to set
 * @param lane   Lane in QLM to set, or -1 for all lanes
 * @param name   String name of field
 * @param value  Value of the field
 */
void bdk_qlm_jtag_set(int qlm, int lane, const char *name, uint64_t value)
{
    const __bdk_qlm_jtag_field_t *field = __bdk_qlm_lookup_field(name);
    if (!field)
        return;
    int num_lanes = bdk_qlm_get_lanes(qlm);

    uint32_t shift_values[MAX_JTAG_UINT32];

    /* Get the current state */
    __bdk_qlm_jtag_capture(qlm);
    for (int i=0; i<MAX_JTAG_UINT32; i++)
        shift_values[i] = __bdk_qlm_jtag_shift(qlm, 32, 0);

    /* Put new data in our local array */
    for (int l=0; l<num_lanes; l++)
    {
        if ((l != lane) && (lane != -1))
            continue;
        uint64_t new_value = value;
        for (int bits = field->start_bit + (num_lanes-1-l)*__bdk_qlm_jtag_length;
              bits <= field->stop_bit + (num_lanes-1-l)*__bdk_qlm_jtag_length;
              bits++)
        {
            if (new_value & 1)
                shift_values[bits/32] |= 1<<(bits&31);
            else
                shift_values[bits/32] &= ~(1<<(bits&31));
            new_value>>=1;
        }
    }

    /* Shift out data and xor with reference */
    int total_length = __bdk_qlm_jtag_length * num_lanes;
    int bits = 0;
    while (bits < total_length)
    {
        uint32_t shift = shift_values[bits/32] ^ __bdk_qlm_jtag_xor_ref[qlm][bits/32];
        int width = total_length - bits;
        if (width > 32)
            width = 32;
        __bdk_qlm_jtag_shift(qlm, width, shift);
        bits += 32;
    }

    /* Update the new data */
    __bdk_qlm_jtag_update(qlm);
    /* Always give the QLM 1ms to settle after every update. This may not
        always be needed, but some of the options make significant
        electrical changes */
    bdk_wait_usec(1000);
}


/**
 * Apply QLM tweaks based on the chip errata
 */
static void __bdk_qlm_chip_tweak(void)
{
    int num_qlms = bdk_qlm_get_num();

    if (OCTEON_IS_MODEL(OCTEON_CNF71XX_PASS1_X))
    {
        /* Nothing as of yet */
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS1_X))
    {
        /* (G-16094) QLM Gen2 Equalizer Default Setting Change */
        for (int qlm=0; qlm<num_qlms; qlm++)
        {
            bdk_qlm_jtag_set(qlm, -1, "rx_cap_gen2", 0x1);
            bdk_qlm_jtag_set(qlm, -1, "rx_eq_gen2", 0x8);
        }
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS2_0))
    {
        /* Nothing as of yet */
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX_PASS1_X))
    {
        /* (G-16094) QLM Gen2 Equalizer Default Setting Change */
        for (int qlm=0; qlm<num_qlms; qlm++)
        {
            bdk_qlm_jtag_set(qlm, -1, "rx_cap_gen2", 0x1);
            bdk_qlm_jtag_set(qlm, -1, "rx_eq_gen2", 0x8);
        }
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X))
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
        if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS2_0) ||
            OCTEON_IS_MODEL(OCTEON_CN63XX_PASS2_1))
        {
            /* CN63XX Pass 2.0 and 2.1 errata G-15273 requires the QLM
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
    else if (OCTEON_IS_MODEL(OCTEON_CN61XX_PASS1_X))
    {
        /* Nothing as of yet */
    }
}


/**
 * Force link detection on a QLM. Useful for getting PCIe
 * analyzers to work.
 *
 * @param qlm    QLM to configure
 */
void bdk_qlm_cn6xxx_force_link(int qlm)
{
    bdk_qlm_jtag_set(qlm, -1, "cfg_rxd_set", 1);
}


/**
 * Initialize the QLM layer
 */
void bdk_qlm_init(void)
{
    /* Figure out which JTAG chain description we're using */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        __bdk_qlm_jtag_field_current = __bdk_qlm_jtag_field_cn68xx;
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
        __bdk_qlm_jtag_field_current = __bdk_qlm_jtag_field_cn66xx;
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        __bdk_qlm_jtag_field_current = __bdk_qlm_jtag_field_cn63xx;
    else if (OCTEON_IS_MODEL(OCTEON_CN61XX))
        __bdk_qlm_jtag_field_current = __bdk_qlm_jtag_field_cn66xx; /* Same as 66 */
    else if (OCTEON_IS_MODEL(OCTEON_CNF71XX))
        __bdk_qlm_jtag_field_current = __bdk_qlm_jtag_field_cn66xx; /* Same as 66 */
    else
        bdk_error("bdk_qlm_init: Needs update for this chip\n");

    /* Figure out how many bits are in the JTAG chain */
    __bdk_qlm_jtag_length = 0;
    const __bdk_qlm_jtag_field_t *ptr = __bdk_qlm_jtag_field_current;
    while (ptr->name)
    {
        if (ptr->stop_bit > __bdk_qlm_jtag_length)
            __bdk_qlm_jtag_length = ptr->stop_bit + 1;
        ptr++;
    }

    if (4 * __bdk_qlm_jtag_length > (int)sizeof(__bdk_qlm_jtag_xor_ref[0]) * 8)
        bdk_fatal("bdk_qlm_init: JTAG chain larger than XOR ref size\n");

    /* Skip actual JTAG accesses on simulator */
    if (bdk_is_simulation())
        return;

    /* Initialize the internal JTAG */
    __bdk_qlm_jtag_init();

    /* Read the XOR defaults for the JTAG chain */
    for (int qlm=0; qlm<bdk_qlm_get_num(); qlm++)
    {
        int num_lanes = bdk_qlm_get_lanes(qlm);
        /* Shift all zeros in the chain to make sure all fields are at
            reset defaults */
        __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length * num_lanes);
        __bdk_qlm_jtag_update(qlm);
        /* Capture the reset defaults */
        __bdk_qlm_jtag_capture(qlm);
        /* Save the reset defaults. This will shift out too much data, but
            the extra zeros don't hurt anything */
        for (int i=0; i<MAX_JTAG_UINT32; i++)
            __bdk_qlm_jtag_xor_ref[qlm][i] = __bdk_qlm_jtag_shift(qlm, 32, 0);
    }

    __bdk_qlm_chip_tweak();
}


/**
 * Display the state of all register for all lanes
 * on a QLM.
 */
void bdk_qlm_dump_jtag(int qlm)
{
    int num_lanes = bdk_qlm_get_lanes(qlm);
    printf("%29s", "Field[<stop bit>:<start bit>]");
    for (int lane=0; lane<num_lanes; lane++)
        printf("\t      Lane %d", lane);
    printf("\n");

    const __bdk_qlm_jtag_field_t *ptr = __bdk_qlm_jtag_field_current;
    while (ptr->name)
    {
        printf("%20s[%3d:%3d]", ptr->name, ptr->stop_bit, ptr->start_bit);
        for (int lane=0; lane<num_lanes; lane++)
        {
            uint64_t val = bdk_qlm_jtag_get(qlm, lane, ptr->name);
            printf("\t%4lu (0x%04lx)", val, val);
        }
        printf("\n");
        ptr++;
    }
}

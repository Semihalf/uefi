#include <bdk.h>
#include "bdk-qlm-jtag.h"
#include <stdio.h>

/**
 * The JTAG chain for CN52XX and CN56XX is 4 * 268 bits long, or 1072.
 * The JTAG chain for CN63XX is 4 * 300 bits long, or 1200.
 * The JTAG chain for CN68XX is 4 * 304 bits long, or 1216.
 * Full chain shift is:
 *     new data => lane 3 => lane 2 => lane 1 => lane 0 => data out
 * Shift LSB first, get LSB out
 */
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn63xx[];
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn66xx[];
extern const __bdk_qlm_jtag_field_t __bdk_qlm_jtag_field_cn68xx[];

static const __bdk_qlm_jtag_field_t *__bdk_qlm_jtag_field_current;
static int __bdk_qlm_jtag_length;
#define MAX_JTAG_UINT32 40
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

    bdk_error("bdk_qlm_get_num: Needs update for this chip\n");
    return 0;
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
                return "SRIO";
            else
                return "PCIE";
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
    if (OCTEON_IS_MODEL(OCTEON_CN68XX) || OCTEON_IS_MODEL(OCTEON_CN66XX))
    {
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
        switch (qlm_cfg.s.qlm_spd)
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
    /* Disable the PTP event counter while we configure it */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 0);
    /* Count on rising edge, Choose which QLM to count */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG,
        c.s.evcnt_edge = 0;
        c.s.evcnt_in = 0x10 + qlm);
    /* Clear MIO_PTP_EVT_CNT */
    int64_t count = BDK_CSR_READ(BDK_MIO_PTP_EVT_CNT);
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, -count);
    /* Set MIO_PTP_EVT_CNT to 1 billion */
    BDK_CSR_WRITE(BDK_MIO_PTP_EVT_CNT, 1000000000);
    /* Enable the PTP event counter */
    BDK_CSR_MODIFY(c, BDK_MIO_PTP_CLOCK_CFG, c.s.evcnt_en = 1);
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    /* Wait for 1 second */
    bdk_wait_usec(1000000);
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
        return 0;

    /* Capture the current settings */
    __bdk_qlm_jtag_capture(qlm);
    /* Shift past lanes we don't care about */
    __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length * lane);
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

    uint32_t shift_values[MAX_JTAG_UINT32];

    /* Get the current state */
    __bdk_qlm_jtag_capture(qlm);
    for (int i=0; i<MAX_JTAG_UINT32; i++)
        shift_values[i] = __bdk_qlm_jtag_shift(qlm, 32, 0);

    /* Put new data in our local array */
    for (int l=0; l<4; l++)
    {
        if ((l != lane) && (lane != -1))
            continue;
        uint64_t new_value = value;
        for (int bits = field->start_bit + l*__bdk_qlm_jtag_length;
              bits <= field->stop_bit + l*__bdk_qlm_jtag_length;
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
    int total_length = __bdk_qlm_jtag_length * 4;
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
}


/**
 * CN68XX pass 1.x QLM tweak. This function tweaks the JTAG setting for a QLMs
 * to run better at 5 and 6.25Ghz. It will make no changes to QLMs running at
 * other speeds.
 */
static void __bdk_qlm_cn68xx_speed_tweak(void)
{
    /* Loop through the 5 QLMs on CN68XX */
    for (int qlm=0; qlm<5; qlm++)
    {
        /* Read the QLM speed */
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(qlm));
        /* If the QLM is at 6.25Ghz or 5Ghz then program JTAG */
        if ((qlm_cfg.s.qlm_spd == 5) || (qlm_cfg.s.qlm_spd == 12) ||
            (qlm_cfg.s.qlm_spd == 0) || (qlm_cfg.s.qlm_spd == 6) ||
            (qlm_cfg.s.qlm_spd == 11))
        {
            /* Update all four lanes */
            for (int lane=0; lane<4; lane++)
            {
                /* We're changing bits 15:8, so skip 8 */
                __bdk_qlm_jtag_shift_zeros(qlm, 8);
                /* We want 0x1b, so default 0x3c xor 0x27 */
                __bdk_qlm_jtag_shift(qlm, 8, 0x27);
                /* Skip the rest of the chain */
                __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length - 16);
            }
            /* Write our JTAG updates */
            __bdk_qlm_jtag_update(qlm);
        }
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
    for (int lane=0; lane<4; lane++)
    {
        __bdk_qlm_jtag_shift_zeros(qlm, 85);
        __bdk_qlm_jtag_shift(qlm, 1, 1);
        __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length-86);
    }
    __bdk_qlm_jtag_update(qlm);
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

    /* Initialize the internal JTAG */
    __bdk_qlm_jtag_init();

    /* Read the XOR defaults for the JTAG chain */
    for (int qlm=0; qlm<bdk_qlm_get_num(); qlm++)
    {
        /* Shift all zeros in the chain to make sure all fields are at
            reset defaults */
        __bdk_qlm_jtag_shift_zeros(qlm, __bdk_qlm_jtag_length * 4);
        __bdk_qlm_jtag_update(qlm);
        /* Capture the reset defaults */
        __bdk_qlm_jtag_capture(qlm);
        /* Save the reset defaults. This will shift out too much data, but
            the extra zeros don't hurt anything */
        for (int i=0; i<MAX_JTAG_UINT32; i++)
            __bdk_qlm_jtag_xor_ref[qlm][i] = __bdk_qlm_jtag_shift(qlm, 32, 0);
    }

    /* CN68XX pass 1.x needs some tweaks for QLM speeds. This
        will apply them if necessary */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX_PASS1_X))
        __bdk_qlm_cn68xx_speed_tweak();
}

#if 0 // Not to be enabled for customer builds
/**
 * Display the state of all register for all lanes
 * on a QLM.
 */
void bdk_qlm_dump_jtag(int qlm)
{
    printf("%29s", "Field[<stop bit>:<start bit>]");
    for (int lane=0; lane<4; lane++)
        printf("\t      Lane %d", lane);
    printf("\n");

    const __bdk_qlm_jtag_field_t *ptr = __bdk_qlm_jtag_field_current;
    while (ptr->name)
    {
        printf("%20s[%3d:%3d]", ptr->name, ptr->stop_bit, ptr->start_bit);
        for (int lane=0; lane<4; lane++)
        {
            uint32_t val = bdk_qlm_jtag_get(qlm, lane, ptr->name);
            printf("\t%4u (0x%04x)", val, val);
        }
        printf("\n");
        ptr++;
    }
}
#endif

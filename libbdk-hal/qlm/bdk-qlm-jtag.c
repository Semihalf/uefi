#include <bdk.h>
#include "bdk-qlm-jtag.h"

/* These are the low level bit programming functions for the QLM JTAG
    chains. These should not be used directly. Instead you should use
    the higher level functions in bdk-qlm */

/**
 * The JTAG chain for CN52XX and CN56XX is 4 * 268 bits long, or 1072.
 * CN5XXX full chain shift is:
 *     new data => lane 3 => lane 2 => lane 1 => lane 0 => data out
 * The JTAG chain for CN68XX is 4 * 304 bits long, or 1216.
 * The JTAG chain for CN61XX is 4 * 304 bits long, or 1216.
 * CN6XXX full chain shift is:
 *     new data => lane 0 => lane 1 => lane 2 => lane 3 => data out
 * Shift LSB first, get LSB out
 */
static const __bdk_qlm_jtag_field_t *__bdk_qlm_jtag_field_current;
static int __bdk_qlm_jtag_length;
#define MAX_JTAG_UINT32 40 /* This gives space for 1280(40*32) bits */
static uint32_t __bdk_qlm_jtag_xor_ref[5][MAX_JTAG_UINT32];

/**
 * Initialize the internal QLM JTAG logic to allow programming
 * of the JTAG chain by the bdk_qlm_jtag_*() functions. These functions should
 * only be used at the direction of Cavium Networks. Programming incorrect
 * values into the JTAG chain can cause chip damage.
 */
void __bdk_qlm_jtag_init(const __bdk_qlm_jtag_field_t *fields)
{
    __bdk_qlm_jtag_field_current = fields;
    if (BDK_DISABLE_QLM_JTAG)
        return;

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

    bdk_ciu_qlm_jtgc_t jtgc;
    int clock_div = 0;
    /* Clock the JTAG chain at 10 Mhz */
    int divisor = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_SCLK) / (10 * 1000000);
    divisor = (divisor-1)>>2;
    /* Convert the divisor into a power of 2 shift */
    while (divisor)
    {
        clock_div++;
        divisor>>=1;
    }

    /* Clock divider for QLM JTAG operations.  sclk is divided by 2^(CLK_DIV + 2) */
    jtgc.u64 = 0;
    jtgc.s.clk_div = clock_div;
    jtgc.s.mux_sel = 0;
    int bypass = (1<<bdk_qlm_get_num(bdk_numa_local()))-1;
    jtgc.s.bypass = bypass;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);

    /* Read the XOR defaults for the JTAG chain */
    for (int qlm=0; qlm<bdk_qlm_get_num(bdk_numa_local()); qlm++)
    {
        int num_lanes = bdk_qlm_get_lanes(bdk_numa_local(), qlm);
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
}


/**
 * Write up to 64bits into the QLM jtag chain. Bits are shifted into the MSB and
 * out the LSB, so you should shift in the low order bits followed by the high
 * order bits.
 *
 * @param qlm    QLM to shift value into
 * @param bits   Number of bits to shift in (0-64).
 * @param data   Data to shift in. Bit 0 enters the chain first, followed by
 *               bit 1, etc.
 *
 * @return The low order bits of the JTAG chain that shifted out of the
 *         circle.
 */
uint64_t __bdk_qlm_jtag_shift(int qlm, int bits, uint64_t data)
{
    if (BDK_DISABLE_QLM_JTAG)
        return 0;
    if (bdk_is_simulation())
        return 0;
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    if ((bits < 0) || (bits > 64))
    {
        bdk_error("__bdk_qlm_jtag_shift: Illegal shift of %d passed\n", bits);
        return 0;
    }

    /* Choose the QLM */
    jtgc.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);

    uint64_t result = 0;
    int shifted = 0;
    while (shifted < bits)
    {
        int n = bits - shifted;
        if (n > 32)
            n = 32;
        jtgd.u64 = 0;
        jtgd.s.shift = 1;
        jtgd.s.shft_cnt = n-1;
        jtgd.s.shft_reg = data >> shifted;
        jtgd.s.select = 1 << qlm;
        BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGD, jtgd.u64);
        do
        {
            jtgd.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGD);
        } while (jtgd.s.shift);
        result |= ((uint64_t)jtgd.s.shft_reg >> (32-n)) << shifted;
        shifted += n;
    }
    return result;
}


/**
 * Shift long sequences of zeros into the QLM JTAG chain. It is
 * common to need to shift more than 32 bits of zeros into the
 * chain. This function is a convience wrapper around bdk_qlm_jtag_shift() to
 * shift more than 32 bits of zeros at a time.
 *
 * @param qlm    QLM to shift zeros into
 * @param bits
 */
void __bdk_qlm_jtag_shift_zeros(int qlm, int bits)
{
    if (BDK_DISABLE_QLM_JTAG)
        return;
    if (bdk_is_simulation())
        return;
    while (bits > 0)
    {
        int n = bits;
        if (n > 32)
            n = 32;
        __bdk_qlm_jtag_shift(qlm, n, 0);
        bits -= n;
    }
}


/**
 * Program the QLM JTAG chain into all lanes of the QLM. You must
 * have already shifted in the proper number of bits into the
 * JTAG chain. Updating invalid values can possibly cause chip damage.
 *
 * @param qlm    QLM to program
 */
void __bdk_qlm_jtag_update(int qlm)
{
    if (BDK_DISABLE_QLM_JTAG)
        return;
    if (bdk_is_simulation())
        return;
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;

    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);

    /* Update the new data */
    jtgd.u64 = 0;
    jtgd.s.update = 1;
    jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGD);
    } while (jtgd.s.update);
}


/**
 * Load the QLM JTAG chain with data from all lanes of the QLM.
 *
 * @param qlm    QLM to program
 */
void __bdk_qlm_jtag_capture(int qlm)
{
    if (BDK_DISABLE_QLM_JTAG)
        return;
    if (bdk_is_simulation())
        return;
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;

    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGC);

    jtgd.u64 = 0;
    jtgd.s.capture = 1;
    jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(bdk_numa_local(), BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(bdk_numa_local(), BDK_CIU_QLM_JTGD);
    } while (jtgd.s.capture);
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
    if (!ptr)
        return NULL;
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
    if (bdk_is_simulation())
        return -1;
    int num_lanes = bdk_qlm_get_lanes(bdk_numa_local(), qlm);

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
    if (bdk_is_simulation())
        return;
    int num_lanes = bdk_qlm_get_lanes(bdk_numa_local(), qlm);

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
 * Display the state of all register for all lanes
 * on a QLM.
 */
void bdk_qlm_dump_jtag(int qlm)
{
    if (bdk_is_simulation())
        return;
    int num_lanes = bdk_qlm_get_lanes(bdk_numa_local(), qlm);
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


#include <bdk.h>
#include "bdk-qlm-jtag.h"

/* These are the low level bit programming functions for the QLM JTAG
    chains. These should not be used directly. Instead you should use
    the higher level functions in bdk-qlm */

/**
 * Initialize the internal QLM JTAG logic to allow programming
 * of the JTAG chain by the bdk_qlm_jtag_*() functions. These functions should
 * only be used at the direction of Cavium Networks. Programming incorrect
 * values into the JTAG chain can cause chip damage.
 */
void __bdk_qlm_jtag_init(void)
{
    if (BDK_DISABLE_QLM_JTAG)
        return;
    bdk_ciu_qlm_jtgc_t jtgc;
    int clock_div = 0;
    /* Clock the JTAG chain at 10 Mhz */
    int divisor = bdk_clock_get_rate(BDK_CLOCK_SCLK) / (10 * 1000000);
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
    int bypass = (1<<bdk_qlm_get_num())-1;
    jtgc.s.bypass = bypass;
    jtgc.s.bypass_ext = bypass >> 4;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);
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
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    if ((bits < 0) || (bits > 64))
    {
        bdk_error("__bdk_qlm_jtag_shift: Illegal shift of %d passed\n", bits);
        return 0;
    }

    /* Choose the QLM */
    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

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
        BDK_CSR_WRITE(BDK_CIU_QLM_JTGD, jtgd.u64);
        do
        {
            jtgd.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGD);
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
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;

    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    /* Update the new data */
    jtgd.u64 = 0;
    jtgd.s.update = 1;
    jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGD);
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
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;

    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    jtgd.u64 = 0;
    jtgd.s.capture = 1;
    jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGD);
    } while (jtgd.s.capture);
}


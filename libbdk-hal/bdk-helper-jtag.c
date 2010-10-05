#include <bdk.h>

/**
 * Initialize the internal QLM JTAG logic to allow programming
 * of the JTAG chain by the bdk_helper_qlm_jtag_*() functions.
 * These functions should only be used at the direction of Cavium
 * Networks. Programming incorrect values into the JTAG chain
 * can cause chip damage.
 */
void bdk_helper_qlm_jtag_init(void)
{
    bdk_ciu_qlm_jtgc_t jtgc;
    int clock_div = 0;
    int divisor = bdk_clock_get_rate(BDK_CLOCK_SCLK) / (25 * 1000000);
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
    if (OCTEON_IS_MODEL(OCTEON_CN52XX))
        jtgc.s.bypass = 0x3;
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        jtgc.s.bypass = 0x7;
    else
        jtgc.s.bypass = 0xf;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);
}


/**
 * Write up to 32bits into the QLM jtag chain. Bits are shifted
 * into the MSB and out the LSB, so you should shift in the low
 * order bits followed by the high order bits. The JTAG chain for
 * CN52XX and CN56XX is 4 * 268 bits long, or 1072. The JTAG chain
 * for CN63XX is 4 * 300 bits long, or 1200.
 *
 * @param qlm    QLM to shift value into
 * @param bits   Number of bits to shift in (1-32).
 * @param data   Data to shift in. Bit 0 enters the chain first, followed by
 *               bit 1, etc.
 *
 * @return The low order bits of the JTAG chain that shifted out of the
 *         circle.
 */
uint32_t bdk_helper_qlm_jtag_shift(int qlm, int bits, uint32_t data)
{
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
        jtgc.s.bypass = 1<<qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    jtgd.u64 = 0;
    jtgd.s.shift = 1;
    jtgd.s.shft_cnt = bits-1;
    jtgd.s.shft_reg = data;
    if (!OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X))
        jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGD);
    } while (jtgd.s.shift);
    return jtgd.s.shft_reg >> (32-bits);
}


/**
 * Shift long sequences of zeros into the QLM JTAG chain. It is
 * common to need to shift more than 32 bits of zeros into the
 * chain. This function is a convience wrapper around
 * bdk_helper_qlm_jtag_shift() to shift more than 32 bits of
 * zeros at a time.
 *
 * @param qlm    QLM to shift zeros into
 * @param bits
 */
void bdk_helper_qlm_jtag_shift_zeros(int qlm, int bits)
{
    while (bits > 0)
    {
        int n = bits;
        if (n > 32)
            n = 32;
        bdk_helper_qlm_jtag_shift(qlm, n, 0);
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
void bdk_helper_qlm_jtag_update(int qlm)
{
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
        jtgc.s.bypass = 1<<qlm;

    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    /* Update the new data */
    jtgd.u64 = 0;
    jtgd.s.update = 1;
    if (!OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X))
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
void bdk_helper_qlm_jtag_capture(int qlm)
{
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    if (!OCTEON_IS_MODEL(OCTEON_CN63XX))
        jtgc.s.bypass = 1<<qlm;

    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    jtgd.u64 = 0;
    jtgd.s.capture = 1;
    if (!OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X))
        jtgd.s.select = 1 << qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGD, jtgd.u64);
    do
    {
        jtgd.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGD);
    } while (jtgd.s.capture);
}


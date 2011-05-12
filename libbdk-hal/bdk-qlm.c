#include <bdk.h>

/**
 * Initialize the internal QLM JTAG logic to allow programming
 * of the JTAG chain by the bdk_qlm_jtag_*() functions. These functions should
 * only be used at the direction of Cavium Networks. Programming incorrect
 * values into the JTAG chain can cause chip damage.
 */
void bdk_qlm_jtag_init(void)
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
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        jtgc.s.bypass = 0x7;
    else
        jtgc.s.bypass = 0xf;
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        jtgc.s.bypass_ext = 1;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);
}


/**
 * Write up to 32bits into the QLM jtag chain. Bits are shifted
 * into the MSB and out the LSB, so you should shift in the low
 * order bits followed by the high order bits. The JTAG chain for
 * CN52XX and CN56XX is 4 * 268 bits long, or 1072. The JTAG chain
 * for CN63XX is 4 * 300 bits long, or 1200. The JTAG chain
 * for CN68XX is 4 * 304 bits long, or 1216.

 *
 * @param qlm    QLM to shift value into
 * @param bits   Number of bits to shift in (1-32).
 * @param data   Data to shift in. Bit 0 enters the chain first, followed by
 *               bit 1, etc.
 *
 * @return The low order bits of the JTAG chain that shifted out of the
 *         circle.
 */
uint32_t bdk_qlm_jtag_shift(int qlm, int bits, uint32_t data)
{
    bdk_ciu_qlm_jtgc_t jtgc;
    bdk_ciu_qlm_jtgd_t jtgd;

    jtgc.u64 = BDK_CSR_READ(BDK_CIU_QLM_JTGC);
    jtgc.s.mux_sel = qlm;
    BDK_CSR_WRITE(BDK_CIU_QLM_JTGC, jtgc.u64);
    BDK_CSR_READ(BDK_CIU_QLM_JTGC);

    jtgd.u64 = 0;
    jtgd.s.shift = 1;
    jtgd.s.shft_cnt = bits-1;
    jtgd.s.shft_reg = data;
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
 * chain. This function is a convience wrapper around bdk_qlm_jtag_shift() to
 * shift more than 32 bits of zeros at a time.
 *
 * @param qlm    QLM to shift zeros into
 * @param bits
 */
void bdk_qlm_jtag_shift_zeros(int qlm, int bits)
{
    while (bits > 0)
    {
        int n = bits;
        if (n > 32)
            n = 32;
        bdk_qlm_jtag_shift(qlm, n, 0);
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
void bdk_qlm_jtag_update(int qlm)
{
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
void bdk_qlm_jtag_capture(int qlm)
{
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


/**
 * CN68XX pass 1.x QLM tweak. This function tweaks the JTAG setting for a QLMs
 * to run better at 5 and 6.25Ghz. It will make no changes to QLMs running at
 * other speeds.
 */
void bdk_qlm_cn68xx_speed_tweak(void)
{
    /* Initialize the internal JTAG */
    bdk_qlm_jtag_init();

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
                bdk_qlm_jtag_shift_zeros(qlm, 8);
                /* We want 0x1b, so default 0x3c xor 0x27 */
                bdk_qlm_jtag_shift(qlm, 8, 0x27);
                /* Skip the rest of the chain */
                bdk_qlm_jtag_shift_zeros(qlm, 304 - 16);
            }
            /* Write our JTAG updates */
            bdk_qlm_jtag_update(qlm);
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
    int chain_len = OCTEON_IS_MODEL(OCTEON_CN68XX) ? 304 : 300;
    bdk_qlm_jtag_init();
    for (int lane=0; lane<4; lane++)
    {
        bdk_qlm_jtag_shift_zeros(qlm, 85);
        bdk_qlm_jtag_shift(qlm, 1, 1);
        bdk_qlm_jtag_shift_zeros(qlm, chain_len-86);
    }
    bdk_qlm_jtag_update(qlm);
}


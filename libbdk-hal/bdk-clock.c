#include <bdk.h>

static uint64_t rate_eclk = 0;
static uint64_t rate_sclk = 0;
static uint64_t rate_dclk = 0;

/**
 * Get clock rate based on the clock type.
 *
 * @param clock - Enumeration of the clock type.
 * @return      - return the clock rate.
 */
uint64_t bdk_clock_get_rate(bdk_clock_t clock)
{
    const uint64_t REF_CLOCK = 50000000;

    if (bdk_unlikely(!rate_eclk))
    {
        if (octeon_has_feature(OCTEON_FEATURE_NPEI))
        {
            BDK_CSR_INIT(npei_dbg_data, BDK_NPEI_DBG_DATA);
            rate_eclk =  REF_CLOCK * npei_dbg_data.s.c_mul;
            rate_sclk = rate_eclk;
        }
        else
        {
            BDK_CSR_INIT(mio_rst_boot, BDK_MIO_RST_BOOT);
            rate_eclk =  REF_CLOCK * mio_rst_boot.s.c_mul;
            rate_sclk = REF_CLOCK * mio_rst_boot.s.pnr_mul;
        }
    }

    switch (clock)
    {
        case BDK_CLOCK_SCLK:
        case BDK_CLOCK_TIM:
        case BDK_CLOCK_IPD:
            return rate_sclk;

        case BDK_CLOCK_RCLK:
        case BDK_CLOCK_CORE:
            return rate_eclk;

        case BDK_CLOCK_DDR:
            return rate_dclk;
    }

    return 0;
}


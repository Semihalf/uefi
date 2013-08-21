#include <bdk.h>

static uint64_t rate_eclk[BDK_NUMA_MAX_NODES] = {0,};
static uint64_t rate_sclk[BDK_NUMA_MAX_NODES] = {0,};

/**
 * Get clock rate based on the clock type.
 *
 * @param node    Node to use in a Numa setup. Can be an exact ID or a special value.
 * @param clock - Enumeration of the clock type.
 * @return      - return the clock rate.
 */
uint64_t bdk_clock_get_rate(bdk_node_t node, bdk_clock_t clock)
{
    const uint64_t REF_CLOCK = 50000000;
    uint64_t eclk = rate_eclk[node];
    uint64_t sclk = rate_sclk[node];

    /* This is written such that you get right answer even if globals
        are in flash */
    if (bdk_unlikely(!eclk || !sclk))
    {
        BDK_CSR_INIT(mio_rst_boot, node, BDK_RST_BOOT);
        eclk =  REF_CLOCK * mio_rst_boot.s.c_mul;
        sclk = REF_CLOCK * mio_rst_boot.s.pnr_mul;
        rate_eclk[node] = eclk;
        rate_sclk[node] = sclk;
    }

    switch (clock)
    {
        case BDK_CLOCK_SCLK:
        case BDK_CLOCK_TIM:
        case BDK_CLOCK_IPD:
            return sclk;

        case BDK_CLOCK_RCLK:
        case BDK_CLOCK_CORE:
            return eclk;
    }

    return 0;
}


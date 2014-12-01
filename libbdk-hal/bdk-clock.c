#include <bdk.h>

/**
 * Called in __bdk_init to setup the global timer
 */
void bdk_clock_setup(bdk_node_t node)
{
    /* Configure GTI to tick at BDK_GTI_RATE */
    uint64_t sclk = bdk_clock_get_rate(node, BDK_CLOCK_SCLK);
    uint64_t inc = (BDK_GTI_RATE << 32) / sclk;
    BDK_CSR_WRITE(node, BDK_GTI_CC_CNTRATE, inc);
    BDK_CSR_WRITE(node, BDK_GTI_CTL_CNTFRQ, BDK_GTI_RATE);
    BDK_CSR_MODIFY(c, node, BDK_GTI_CC_CNTCR,
        c.s.en = 1);
}

/**
 * Get cycle count based on the clock type.
 *
 * @param clock - Enumeration of the clock type.
 * @return      - Get the number of cycles executed so far.
 */
uint64_t __bdk_clock_get_count_slow(bdk_clock_t clock)
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(rst_boot, node, BDK_RST_BOOT);
    uint64_t ref_cntr = BDK_CSR_READ(node, BDK_RST_REF_CNTR);
    switch(clock)
    {
        case BDK_CLOCK_TIME:
            return 0; /* Handled in fast path */
        case BDK_CLOCK_MAIN_REF:
            return ref_cntr;
        case BDK_CLOCK_RCLK:
            return ref_cntr * rst_boot.s.c_mul;
        case BDK_CLOCK_SCLK:
            return ref_cntr * rst_boot.s.pnr_mul;
    }
    return 0;
}

/**
 * Get clock rate based on the clock type.
 *
 * @param node    Node to use in a Numa setup. Can be an exact ID or a special value.
 * @param clock - Enumeration of the clock type.
 * @return      - return the clock rate.
 */
uint64_t __bdk_clock_get_rate_slow(bdk_node_t node, bdk_clock_t clock)
{
    /* This is currently defined to be 50Mhz */
    const uint64_t REF_CLOCK = 50000000;

    BDK_CSR_INIT(mio_rst_boot, node, BDK_RST_BOOT);
    switch (clock)
    {
        case BDK_CLOCK_TIME:
            return BDK_GTI_RATE; /* Programed as part of setup */
        case BDK_CLOCK_MAIN_REF:
            return REF_CLOCK;
        case BDK_CLOCK_RCLK:
            return REF_CLOCK * mio_rst_boot.s.c_mul;
        case BDK_CLOCK_SCLK:
            return REF_CLOCK * mio_rst_boot.s.pnr_mul;
    }
    return 0;
}


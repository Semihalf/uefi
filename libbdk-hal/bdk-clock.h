/**
 * @file
 *
 * Interface to Core, IO and DDR Clock.
 *
 * <hr>$Revision: 45089 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Enumeration of different Clocks.
 */
typedef enum{
    BDK_CLOCK_MAIN_REF, /**< Main reference clock */
    BDK_CLOCK_CORE,     /**< Clock used by cores, coherent bus and L2 cache. */
    BDK_CLOCK_SCLK,     /**< Clock used by IO blocks. */
} bdk_clock_t;

/**
 * Get cycle count based on the clock type.
 *
 * @param clock - Enumeration of the clock type.
 * @return      - Get the number of cycles executed so far.
 */
static inline uint64_t bdk_clock_get_count(bdk_clock_t clock) __attribute__ ((always_inline));
static inline uint64_t bdk_clock_get_count(bdk_clock_t clock)
{
    bdk_node_t node = bdk_numa_local();
    BDK_CSR_INIT(rst_boot, node, BDK_RST_BOOT);
    uint64_t ref_cntr = BDK_CSR_READ(node, BDK_RST_REF_CNTR);
    switch(clock)
    {
        case BDK_CLOCK_MAIN_REF:
            return ref_cntr;
        case BDK_CLOCK_CORE:
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
static inline uint64_t bdk_clock_get_rate(bdk_node_t node, bdk_clock_t clock) __attribute__ ((pure));
static inline uint64_t bdk_clock_get_rate(bdk_node_t node, bdk_clock_t clock)
{
    const uint64_t REF_CLOCK = 50000000; /* This is currently defined to be 50Mhz */
    BDK_CSR_INIT(mio_rst_boot, node, BDK_RST_BOOT);
    switch (clock)
    {
        case BDK_CLOCK_MAIN_REF:
            return REF_CLOCK;
        case BDK_CLOCK_CORE:
            return REF_CLOCK * mio_rst_boot.s.c_mul;
        case BDK_CLOCK_SCLK:
            return REF_CLOCK * mio_rst_boot.s.pnr_mul;
    }
    return 0;
}

/** @} */

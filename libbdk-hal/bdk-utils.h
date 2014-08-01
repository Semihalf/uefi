/**
 * @file
 * Small utility functions and macros to ease programming.
 *
 * <hr>$Revision: 38306 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/*
 * The macros bdk_likely and bdk_unlikely use the
 * __builtin_expect GCC operation to control branch
 * probabilities for a conditional. For example, an "if"
 * statement in the code that will almost always be
 * executed should be written as "if (bdk_likely(...))".
 * If the "else" section of an if statement is more
 * probable, use "if (bdk_unlikey(...))".
 */
#define bdk_likely(x)      __builtin_expect(!!(x), 1)
#define bdk_unlikely(x)    __builtin_expect(!!(x), 0)

#define BDK_CACHE_LINE_SIZE    (128)   // In bytes
#define BDK_CACHE_LINE_MASK    (BDK_CACHE_LINE_SIZE - 1)   // In bytes
#define BDK_CACHE_LINE_ALIGNED __attribute__ ((aligned (BDK_CACHE_LINE_SIZE)))

/**
 * Builds a bit mask given the required size in bits.
 *
 * @param bits   Number of bits in the mask
 * @return The mask
 */
static inline uint64_t bdk_build_mask(uint64_t bits)
{
    if (bits == 64)
        return -1;
    else
        return ~((~0x0ull) << bits);
}


/**
 * Return the number of cores available in the chip
 *
 * @return
 */
static inline int bdk_get_num_cores(bdk_node_t node)
{
    uint64_t available = BDK_CSR_READ(node, BDK_RST_PP_AVAILABLE);
    return bdk_dpop(available);
}


/**
 * Return true if DRAM has been configured
 *
 * @return Boolean
 */
static inline int __bdk_is_dram_enabled(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_ddr_pll_ctl, node, BDK_LMCX_DDR_PLL_CTL(0));
    return lmcx_ddr_pll_ctl.s.reset_n;
}

/**
 * Zero a block of memory
 *
 * @param start
 * @param length
 */
static inline void bdk_zero_memory(void *start, uint64_t length)
{
    if (((long)start & BDK_CACHE_LINE_MASK) || (length & BDK_CACHE_LINE_MASK))
    {
        /* Use slwo memset for unaligned memory */
        memset(start, 0, length);
    }
    else
    {
        void *end = start + length;
        while (start<end)
        {
            asm volatile ("dc zva,%0" : : "r"(start));
            start += BDK_CACHE_LINE_SIZE;
        }
    }
}

/** @} */

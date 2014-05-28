/**
 * @file
 * Small utility functions and macros to ease programming of Octeon.
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

#define CASTPTR(type, v) ((type *)(long)(v))
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
 * Perform mask and shift to place the supplied value into
 * the supplied bit rage.
 *
 * Example: bdk_build_bits(39,24,value)
 * <pre>
 * 6       5       4       3       3       2       1
 * 3       5       7       9       1       3       5       7      0
 * +-------+-------+-------+-------+-------+-------+-------+------+
 * 000000000000000000000000___________value000000000000000000000000
 * </pre>
 *
 * @param high_bit Highest bit value can occupy (inclusive) 0-63
 * @param low_bit  Lowest bit value can occupy inclusive 0-high_bit
 * @param value    Value to use
 * @return Value masked and shifted
 */
static inline uint64_t bdk_build_bits(uint64_t high_bit, uint64_t low_bit, uint64_t value)
{
    return ((value & bdk_build_mask(high_bit - low_bit + 1)) << low_bit);
}


/**
 * Return the number of cores available in the chip
 *
 * @return
 */
static inline int bdk_octeon_num_cores(bdk_node_t node)
{
    uint64_t ciu_fuse = BDK_CSR_READ(node, BDK_CIU_FUSE);
    return bdk_dpop(ciu_fuse);
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
            BDK_ZCB(start);
            start += BDK_CACHE_LINE_SIZE;
        }
    }
}

/** @} */

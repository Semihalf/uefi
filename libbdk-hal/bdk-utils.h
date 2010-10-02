/**
 * @file
 * Small utility functions and macros to ease programming of Octeon.
 *
 * <hr>$Revision: 38306 $<hr>
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

extern void bdk_dvprintf(const char *format, va_list ap);
extern void bdk_dprintf(const char *format, ...) __attribute__ ((format(printf, 1, 2)));

#define CAST64(v) ((long long)(long)(v)) // use only when 'v' is a pointer
#define CASTPTR(type, v) ((type *)(long)(v))
#define BDK_CACHE_LINE_SIZE    (128)   // In bytes
#define BDK_CACHE_LINE_MASK    (BDK_CACHE_LINE_SIZE - 1)   // In bytes
#define BDK_CACHE_LINE_ALIGNED __attribute__ ((aligned (BDK_CACHE_LINE_SIZE)))

/**
 * This macro spins on a field waiting for it to reach a value. It
 * is common in code to need to wait for a specific field in a CSR
 * to match a specific value. Conceptually this macro expands to:
 *
 * 1) read csr at "address" with a csr typedef of "type"
 * 2) Check if ("type".s."field" "op" "value")
 * 3) If #2 isn't true loop to #1 unless too much time has passed.
 */
#define BDK_WAIT_FOR_FIELD64(address, type, field, op, value, timeout_usec)\
    ({int result;                                                       \
    do {                                                                \
        uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + (uint64_t)timeout_usec * \
                        bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000; \
        type c;                                                         \
        while (1)                                                       \
        {                                                               \
            c.u64 = BDK_CSR_READ(address);                             \
            if ((c.s.field) op (value)) {                               \
                result = 0;                                             \
                break;                                                  \
            } else if (bdk_clock_get_count(BDK_CLOCK_CORE) > done) {  \
                result = -1;                                            \
                break;                                                  \
            } else                                                      \
                bdk_wait(100);                                         \
        }                                                               \
    } while (0);                                                        \
    result;})

/**
 * Builds a bit mask given the required size in bits.
 *
 * @param bits   Number of bits in the mask
 * @return The mask
 */
static inline uint64_t bdk_build_mask(uint64_t bits)
{
    return ~((~0x0ull) << bits);
}


/**
 * Builds a memory address for I/O based on the Major and Sub DID.
 *
 * @param major_did 5 bit major did
 * @param sub_did   3 bit sub did
 * @return I/O base address
 */
static inline uint64_t bdk_build_io_address(uint64_t major_did, uint64_t sub_did)
{
    return ((0x1ull << 48) | (major_did << 43) | (sub_did << 40));
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
static inline uint32_t bdk_octeon_num_cores(void)
{
    uint32_t ciu_fuse = (uint32_t)BDK_CSR_READ(BDK_CIU_FUSE) & 0xffff;
    return bdk_pop(ciu_fuse);
}


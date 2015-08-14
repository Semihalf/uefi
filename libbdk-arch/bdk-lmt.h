/**
 * @file
 *
 * Defiens and functions for performing LMT operations, such as
 * LMTST and LMTCANCEL
 *
 * @defgroup lmt Local Memory Transaction (LMT) support
 * @{
 */

/**
 * Address of the LMT store area in physical memory
 */
#define __BDK_LMTLINE 0x87F100000000ull

/**
 * Flush the LMTLINE area of all previous writes and clear the valid flag
 */
static inline void bdk_lmt_cancel(void)
{
    *(volatile uint64_t *)(__BDK_LMTLINE | (1 << 10)) = 0;
}

/**
 * Store to the LMTLINE area in 64bit words. Good programming practice would
 * to always store sequencially, incrementing offset by 1 for each word written.
 *
 * @param offset Offset into LMTLINE in 64bit words (0-15)
 * @param data   Data to write
 */
static inline void bdk_lmt_store(int offset, uint64_t data)
{
    *(volatile uint64_t *)(__BDK_LMTLINE + offset * 8) = data;
}

/**
 * Send the data stored to LMTLINE to an IO block. This call may
 * fail if the hardware has invalidated the LMTLINE area. If it
 * fails, you must issue all LMT stores again and redo this
 * call. Note the return status of this function is backwards
 * to most BDK functions. It matches the LMTST hardware result.
 *
 * @param io_address 48 bit IO address where the LMTLINE data will be sent
 *
 * @return Zero on failure, non-zero on success
 */
static inline int bdk_lmt_submit(uint64_t io_address)
{
    int result = 0;
    asm volatile ("LDEOR xzr,%[rf],[%[rs]]" : [rf] "=r"(result): [rs] "r"(io_address));
    return result;
}

/** @} */

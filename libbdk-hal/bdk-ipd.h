/**
 * @file
 *
 * Interface to the hardware Input Packet Data unit.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum {
   BDK_IPD_OPC_MODE_STT = 0LL,   /* All blocks DRAM, not cached in L2 */
   BDK_IPD_OPC_MODE_STF = 1LL,   /* All blocks into L2 */
   BDK_IPD_OPC_MODE_STF1_STT = 2LL,   /* 1st block L2, rest DRAM */
   BDK_IPD_OPC_MODE_STF2_STT = 3LL    /* 1st, 2nd blocks L2, rest DRAM */
} bdk_ipd_mode_t;


/**
 * Configure IPD
 *
 * @param mbuff_size Packets buffer size in 8 byte words
 * @param first_mbuff_skip
 *                   Number of 8 byte words to skip in the first buffer
 * @param not_first_mbuff_skip
 *                   Number of 8 byte words to skip in each following buffer
 * @param first_back Must be same as first_mbuff_skip / 128
 * @param second_back
 *                   Must be same as not_first_mbuff_skip / 128
 * @param wqe_fpa_pool
 *                   FPA pool to get work entries from
 * @param cache_mode
 * @param back_pres_enable_flag
 *                   Enable or disable port back pressure at a global level.
 *                   This should always be 1 as more accurate control can be
 *                   found in IPD_PORTX_BP_PAGE_CNT[BP_ENB].
 */
extern void bdk_ipd_config(uint64_t mbuff_size,
                                   uint64_t first_mbuff_skip,
                                   uint64_t not_first_mbuff_skip,
                                   uint64_t first_back,
                                   uint64_t second_back,
                                   uint64_t wqe_fpa_pool,
                                   bdk_ipd_mode_t cache_mode,
                                   uint64_t back_pres_enable_flag
                                  );

/**
 * Enable IPD
 */
extern void bdk_ipd_enable(void);

/**
 * Disable IPD
 */
extern void bdk_ipd_disable(void);

/** @} */

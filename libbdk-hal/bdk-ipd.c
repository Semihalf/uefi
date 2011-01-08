#include <bdk.h>

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
void bdk_ipd_config(uint64_t mbuff_size,
                                   uint64_t first_mbuff_skip,
                                   uint64_t not_first_mbuff_skip,
                                   uint64_t first_back,
                                   uint64_t second_back,
                                   uint64_t wqe_fpa_pool,
                                   bdk_ipd_mode_t cache_mode,
                                   uint64_t back_pres_enable_flag
                                  )
{
    bdk_ipd_1st_mbuff_skip_t first_skip;
    bdk_ipd_not_1st_mbuff_skip_t not_first_skip;
    bdk_ipd_packet_mbuff_size_t size;
    bdk_ipd_1st_next_ptr_back_t first_back_struct;
    bdk_ipd_2nd_next_ptr_back_t second_back_struct;
    bdk_ipd_wqe_fpa_queue_t wqe_pool;
    bdk_ipd_ctl_status_t ipd_ctl_reg;

    first_skip.u64 = 0;
    first_skip.s.skip_sz = first_mbuff_skip;
    BDK_CSR_WRITE(BDK_IPD_1ST_MBUFF_SKIP, first_skip.u64);

    not_first_skip.u64 = 0;
    not_first_skip.s.skip_sz = not_first_mbuff_skip;
    BDK_CSR_WRITE(BDK_IPD_NOT_1ST_MBUFF_SKIP, not_first_skip.u64);

    size.u64 = 0;
    size.s.mb_size = mbuff_size;
    BDK_CSR_WRITE(BDK_IPD_PACKET_MBUFF_SIZE, size.u64);

    first_back_struct.u64 = 0;
    first_back_struct.s.back = first_back;
    BDK_CSR_WRITE(BDK_IPD_1ST_NEXT_PTR_BACK, first_back_struct.u64);

    second_back_struct.u64 = 0;
    second_back_struct.s.back = second_back;
    BDK_CSR_WRITE(BDK_IPD_2ND_NEXT_PTR_BACK,second_back_struct.u64);

    wqe_pool.u64 = 0;
    wqe_pool.s.wqe_pool = wqe_fpa_pool;
    BDK_CSR_WRITE(BDK_IPD_WQE_FPA_QUEUE, wqe_pool.u64);

    ipd_ctl_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_ctl_reg.s.opc_mode = cache_mode;
    ipd_ctl_reg.s.pbp_en = back_pres_enable_flag;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_reg.u64);

    /* Note: the example RED code that used to be here has been moved to
        bdk_helper_setup_red */
}


/**
 * Enable IPD
 */
void bdk_ipd_enable(void)
{
    bdk_ipd_ctl_status_t ipd_reg;
    ipd_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    if (ipd_reg.s.ipd_en)
    {
        bdk_dprintf("Warning: Enabling IPD when IPD already enabled.\n");
    }
    ipd_reg.s.ipd_en = 1;
    ipd_reg.s.len_m8 = 1;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_reg.u64);
}


/**
 * Disable IPD
 */
void bdk_ipd_disable(void)
{
    bdk_ipd_ctl_status_t ipd_reg;
    ipd_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_reg.s.ipd_en = 0;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_reg.u64);
}


#include <bdk.h>

/**
 * Initialize the RAID block
 *
 * @param polynomial Coefficients for the RAID polynomial
 *
 * @return Zero on success, negative on failure
 */
int bdk_raid_initialize(bdk_rad_reg_polynomial_t polynomial)
{
    bdk_cmd_queue_result_t result;
    bdk_rad_reg_cmd_buf_t rad_reg_cmd_buf;

    BDK_CSR_WRITE(BDK_RAD_REG_POLYNOMIAL, polynomial.u64);

    result = bdk_cmd_queue_initialize(BDK_CMD_QUEUE_RAID, 0,
                                       BDK_FPA_OUTPUT_BUFFER_POOL,
                                       bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL));
    if (result != BDK_CMD_QUEUE_SUCCESS)
        return -1;

    rad_reg_cmd_buf.u64 = 0;
    rad_reg_cmd_buf.s.dwb = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/128;
    rad_reg_cmd_buf.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    rad_reg_cmd_buf.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/8;
    rad_reg_cmd_buf.s.ptr = bdk_ptr_to_phys(bdk_cmd_queue_buffer(BDK_CMD_QUEUE_RAID))>>7;
    BDK_CSR_WRITE(BDK_RAD_REG_CMD_BUF, rad_reg_cmd_buf.u64);
    return 0;
}


/**
 * Shutdown the RAID block. RAID must be idle when
 * this function is called.
 *
 * @return Zero on success, negative on failure
 */
int bdk_raid_shutdown(void)
{
    bdk_rad_reg_ctl_t rad_reg_ctl;

    if (bdk_cmd_queue_length(BDK_CMD_QUEUE_RAID))
    {
        bdk_dprintf("ERROR: bdk_raid_shutdown: RAID not idle.\n");
        return -1;
    }

    rad_reg_ctl.u64 = BDK_CSR_READ(BDK_RAD_REG_CTL);
    rad_reg_ctl.s.reset = 1;
    BDK_CSR_WRITE(BDK_RAD_REG_CTL, rad_reg_ctl.u64);
    bdk_wait(100);

    bdk_cmd_queue_shutdown(BDK_CMD_QUEUE_RAID);
    BDK_CSR_WRITE(BDK_RAD_REG_CMD_BUF, 0);
    return 0;
}


/**
 * Submit a command to the RAID block
 *
 * @param num_words Number of command words to submit
 * @param words     Command words
 *
 * @return Zero on success, negative on failure
 */
int bdk_raid_submit(int num_words, bdk_raid_word_t words[])
{
    bdk_cmd_queue_result_t result = bdk_cmd_queue_write(BDK_CMD_QUEUE_RAID, 1, num_words, (uint64_t *)words);
    if (result == BDK_CMD_QUEUE_SUCCESS)
        bdk_write64_uint64(BDK_ADDR_DID(BDK_FULL_DID(14, 0)), num_words);
    return result;
}


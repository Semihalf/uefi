#include <bdk.h>

/**
 * Initialize the ZIP block
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_initialize(void)
{
    bdk_zip_cmd_buf_t zip_cmd_buf;
    bdk_cmd_queue_result_t result;
    result = bdk_cmd_queue_initialize(BDK_CMD_QUEUE_ZIP, BDK_FPA_OUTPUT_BUFFER_POOL,
                                       bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL));
    if (result != BDK_CMD_QUEUE_SUCCESS)
        return -1;

    zip_cmd_buf.u64 = 0;
    zip_cmd_buf.s.dwb = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/128;
    zip_cmd_buf.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    zip_cmd_buf.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL)/8;
    zip_cmd_buf.s.ptr =  bdk_ptr_to_phys(bdk_cmd_queue_buffer(BDK_CMD_QUEUE_ZIP))>>7;
    BDK_CSR_WRITE(BDK_ZIP_CMD_BUF, zip_cmd_buf.u64);
    BDK_CSR_WRITE(BDK_ZIP_ERROR, 1);
    BDK_CSR_READ(BDK_ZIP_CMD_BUF); /* Read to make sure setup is complete */
    return 0;
}

/**
 * Shutdown the ZIP block. ZIP must be idle when
 * this function is called.
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_shutdown(void)
{
    bdk_zip_cmd_ctl_t zip_cmd_ctl;

    if (bdk_cmd_queue_length(BDK_CMD_QUEUE_ZIP))
    {
        bdk_error("bdk_zip_shutdown: ZIP not idle.\n");
        return -1;
    }

    zip_cmd_ctl.u64 = BDK_CSR_READ(BDK_ZIP_CMD_CTL);
    zip_cmd_ctl.s.reset = 1;
    BDK_CSR_WRITE(BDK_ZIP_CMD_CTL, zip_cmd_ctl.u64);
    bdk_wait(100);

    bdk_cmd_queue_shutdown(BDK_CMD_QUEUE_ZIP);
    return 0;
}

/**
 * Submit a command to the ZIP block
 *
 * @param command Zip command to submit
 *
 * @return Zero on success, negative on failure
 */
int bdk_zip_submit(bdk_zip_command_t *command)
{
    bdk_cmd_queue_result_t result = bdk_cmd_queue_write(BDK_CMD_QUEUE_ZIP, 1, 8, command->u64);
    if (result == BDK_CMD_QUEUE_SUCCESS)
        bdk_write64_uint64(BDK_ADDR_DID(BDK_FULL_DID(7, 0)), 8);
    return result;
}


#include <bdk.h>

/**
 * Initialize a command queue for use. The initial FPA buffer is
 * allocated and the hardware unit is configured to point to the
 * new command queue.
 *
 * @param qstate    Hardware command queue to initialize.
 * @param fpa_pool  FPA pool the command queues should come from.
 * @param pool_size Size of each buffer in the FPA pool (bytes)
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_initialize(bdk_cmd_queue_state_t *qstate, int fpa_pool, int pool_size)
{
    if ((fpa_pool < 0) || (fpa_pool > 7))
        return BDK_CMD_QUEUE_INVALID_PARAM;
    if ((pool_size < 32) || (pool_size > 65536))
        return BDK_CMD_QUEUE_INVALID_PARAM;

    void *buffer = bdk_fpa_alloc(fpa_pool);
    if (buffer == NULL)
    {
        bdk_error("bdk_cmd_queue_initialize: Unable to allocate initial buffer.\n");
        return BDK_CMD_QUEUE_NO_MEMORY;
    }

    memset(qstate, 0, sizeof(*qstate));
    qstate->fpa_pool = fpa_pool;
    qstate->pool_size_m1 = (pool_size>>3)-1;
    qstate->base_ptr_div128 = bdk_ptr_to_phys(buffer) / 128;
    BDK_SYNCW;
    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Shutdown a queue a free it's command buffers to the FPA. The
 * hardware connected to the queue must be stopped before this
 * function is called.
 *
 * @param qptr Queue to shutdown
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_shutdown(bdk_cmd_queue_state_t *qptr)
{
    __bdk_cmd_queue_lock(qptr);
    if (qptr->base_ptr_div128)
    {
        bdk_fpa_free(bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7), qptr->fpa_pool, 0);
        qptr->base_ptr_div128 = 0;
    }
    __bdk_cmd_queue_unlock(qptr);

    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Return the command buffer to be written to. The purpose of this
 * function is to allow BDK routine access to the low level buffer
 * for initial hardware setup. User applications should not call this
 * function directly.
 *
 * @param qptr Command queue to query
 *
 * @return Command buffer or NULL on failure
 */
void *bdk_cmd_queue_buffer(bdk_cmd_queue_state_t *qptr)
{
    if (qptr->base_ptr_div128)
        return bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
    else
        return NULL;
}


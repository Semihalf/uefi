#include <bdk.h>

/**
 * Initialize a command queue for use. The initial FPA buffer is
 * allocated and the hardware unit is configured to point to the
 * new command queue.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qstate Hardware command queue to initialize.
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_initialize(bdk_node_t node, bdk_cmd_queue_state_t *qstate)
{
    static int fpa_is_ready = 0;

    BDK_TRACE("N%d: Setting up command buffer for queue %p\n", node, qstate);
    /* Allocate command buffers on first call */
    if (!fpa_is_ready)
    {
        BDK_TRACE("N%d:     Setting up FPA pool for command buffers\n", node);
        if (bdk_fpa_fill_pool(node, BDK_FPA_OUTPUT_BUFFER_POOL, bdk_config_get(BDK_CONFIG_NUM_OUTPUT_BUFFERS)))
        {
            bdk_error("bdk_cmd_queue_initialize: Unable to setup FPA pool\n");
            return BDK_CMD_QUEUE_NO_MEMORY;
        }
        fpa_is_ready = 1;
    }

    int fpa_pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    int pool_size = bdk_fpa_get_block_size(node, fpa_pool);

    void *buffer = bdk_fpa_alloc(node, fpa_pool);
    if (buffer == NULL)
    {
        bdk_error("bdk_cmd_queue_initialize: Unable to allocate initial buffer.\n");
        return BDK_CMD_QUEUE_NO_MEMORY;
    }
    BDK_TRACE("N%d:     Using FPA buffer %p\n", node, buffer);
    BDK_TRACE("N%d:     Setting up qstate %p\n", node, qstate);
    bdk_zero_memory(qstate, sizeof(*qstate));
    qstate->fpa_pool = fpa_pool;
    qstate->node = node;
    qstate->pool_size_m1 = (pool_size>>3)-1;
    qstate->base_ptr = buffer;
    BDK_SYNCW;
    BDK_TRACE("N%d:     Command queue init complete for %p\n", node, qstate);
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
    if (qptr->base_ptr)
    {
        bdk_fpa_free(qptr->node, qptr->base_ptr, qptr->fpa_pool, 0);
        qptr->base_ptr = NULL;
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
    return qptr->base_ptr;
}


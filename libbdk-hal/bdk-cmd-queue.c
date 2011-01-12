#include <bdk.h>
#include <malloc.h>

/**
 * This application uses this pointer to access the global queue
 * state. It points to a bootmem named block.
 */
__bdk_cmd_queue_all_state_t *__bdk_cmd_queue_state_ptr;

/**
 * @INTERNAL
 * Initialize the Global queue state pointer.
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static bdk_cmd_queue_result_t __bdk_cmd_queue_init_state_ptr(void)
{
    if (bdk_likely(__bdk_cmd_queue_state_ptr))
        return BDK_CMD_QUEUE_SUCCESS;

    __bdk_cmd_queue_state_ptr = memalign(BDK_CACHE_LINE_SIZE, sizeof(*__bdk_cmd_queue_state_ptr));
    if (__bdk_cmd_queue_state_ptr == NULL)
        return BDK_CMD_QUEUE_NO_MEMORY;
    memset(__bdk_cmd_queue_state_ptr, 0, sizeof(*__bdk_cmd_queue_state_ptr));
    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Initialize a command queue for use. The initial FPA buffer is
 * allocated and the hardware unit is configured to point to the
 * new command queue.
 *
 * @param queue_id  Hardware command queue to initialize.
 * @param fpa_pool  FPA pool the command queues should come from.
 * @param pool_size Size of each buffer in the FPA pool (bytes)
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_initialize(bdk_cmd_queue_id_t queue_id, int fpa_pool, int pool_size)
{
    __bdk_cmd_queue_state_t *qstate;
    bdk_cmd_queue_result_t result = __bdk_cmd_queue_init_state_ptr();
    if (result != BDK_CMD_QUEUE_SUCCESS)
        return result;

    qstate = __bdk_cmd_queue_get_state(queue_id);
    if (qstate == NULL)
        return BDK_CMD_QUEUE_INVALID_PARAM;

    if ((fpa_pool < 0) || (fpa_pool > 7))
        return BDK_CMD_QUEUE_INVALID_PARAM;
    if ((pool_size < 32) || (pool_size > 65536))
        return BDK_CMD_QUEUE_INVALID_PARAM;

    /* See if someone else has already initialized the queue */
    if (qstate->base_ptr_div128)
    {
        if (fpa_pool != qstate->fpa_pool)
        {
            bdk_error("bdk_cmd_queue_initialize: Queue already initialized with different FPA pool (%u).\n", qstate->fpa_pool);
            return BDK_CMD_QUEUE_INVALID_PARAM;
        }
        if ((pool_size>>3)-1 != qstate->pool_size_m1)
        {
            bdk_error("bdk_cmd_queue_initialize: Queue already initialized with different FPA pool size (%u).\n", (qstate->pool_size_m1+1)<<3);
            return BDK_CMD_QUEUE_INVALID_PARAM;
        }
        BDK_SYNCW;
        return BDK_CMD_QUEUE_ALREADY_SETUP;
    }
    else
    {
        bdk_fpa_ctl_status_t status;
        void *buffer;

        status.u64 = BDK_CSR_READ(BDK_FPA_CTL_STATUS);
        if (!status.s.enb)
        {
            bdk_error("bdk_cmd_queue_initialize: FPA is not enabled.\n");
            return BDK_CMD_QUEUE_NO_MEMORY;
        }
        buffer = bdk_fpa_alloc(fpa_pool);
        if (buffer == NULL)
        {
            bdk_error("bdk_cmd_queue_initialize: Unable to allocate initial buffer.\n");
            return BDK_CMD_QUEUE_NO_MEMORY;
        }

        memset(qstate, 0, sizeof(*qstate));
        qstate->fpa_pool = fpa_pool;
        qstate->pool_size_m1 = (pool_size>>3)-1;
        qstate->base_ptr_div128 = bdk_ptr_to_phys(buffer) / 128;
        /* We zeroed the now serving field so we need to also zero the ticket */
        __bdk_cmd_queue_state_ptr->ticket[__bdk_cmd_queue_get_index(queue_id)] = 0;
        BDK_SYNCW;
        return BDK_CMD_QUEUE_SUCCESS;
    }
}


/**
 * Shutdown a queue a free it's command buffers to the FPA. The
 * hardware connected to the queue must be stopped before this
 * function is called.
 *
 * @param queue_id Queue to shutdown
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_shutdown(bdk_cmd_queue_id_t queue_id)
{
    __bdk_cmd_queue_state_t *qptr = __bdk_cmd_queue_get_state(queue_id);
    if (qptr == NULL)
    {
        bdk_error("bdk_cmd_queue_shutdown: Unable to get queue information.\n");
        return BDK_CMD_QUEUE_INVALID_PARAM;
    }

    if (bdk_cmd_queue_length(queue_id) > 0)
    {
        bdk_error("bdk_cmd_queue_shutdown: Queue still has data in it.\n");
        return BDK_CMD_QUEUE_FULL;
    }

    __bdk_cmd_queue_lock(queue_id, qptr);
    if (qptr->base_ptr_div128)
    {
        bdk_fpa_free(bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7), qptr->fpa_pool, 0);
        qptr->base_ptr_div128 = 0;
    }
    __bdk_cmd_queue_unlock(qptr);

    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Return the number of command words pending in the queue. This
 * function may be relatively slow for some hardware units.
 *
 * @param queue_id Hardware command queue to query
 *
 * @return Number of outstanding commands
 */
int bdk_cmd_queue_length(bdk_cmd_queue_id_t queue_id)
{
    if (__bdk_cmd_queue_get_state(queue_id) == NULL)
        return BDK_CMD_QUEUE_INVALID_PARAM;

    /* The cast is here so gcc with check that all values in the
        bdk_cmd_queue_id_t enumeration are here */
    switch ((bdk_cmd_queue_id_t)(queue_id & 0xff0000))
    {
        case BDK_CMD_QUEUE_PKO_BASE:
            /* FIXME: Need atomic lock on BDK_PKO_REG_READ_IDX. Right now we
                are normally called with the queue lock, so that is a SLIGHT
                amount of protection */
            BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, queue_id & 0xffff);
            bdk_pko_mem_debug8_t debug8;
            debug8.u64 = BDK_CSR_READ(BDK_PKO_MEM_DEBUG8);
            return debug8.cn63xx.doorbell;
        case BDK_CMD_QUEUE_ZIP:
        case BDK_CMD_QUEUE_DFA:
        case BDK_CMD_QUEUE_RAID:
            // FIXME: Implement other lengths
            return 0;
        case BDK_CMD_QUEUE_DMA_BASE:
        {
            bdk_dpi_dmax_counts_t dmax_counts;
            dmax_counts.u64 = BDK_CSR_READ(BDK_DPI_DMAX_COUNTS(queue_id & 0x7));
            return dmax_counts.s.dbell;
        }
        case BDK_CMD_QUEUE_END:
            return BDK_CMD_QUEUE_INVALID_PARAM;
    }
    return BDK_CMD_QUEUE_INVALID_PARAM;
}


/**
 * Return the command buffer to be written to. The purpose of this
 * function is to allow BDK routine access to the low level buffer
 * for initial hardware setup. User applications should not call this
 * function directly.
 *
 * @param queue_id Command queue to query
 *
 * @return Command buffer or NULL on failure
 */
void *bdk_cmd_queue_buffer(bdk_cmd_queue_id_t queue_id)
{
    __bdk_cmd_queue_state_t *qptr = __bdk_cmd_queue_get_state(queue_id);
    if (qptr && qptr->base_ptr_div128)
        return bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
    else
        return NULL;
}


/**
 * @file
 *
 * Support functions for managing command queues used for
 * various hardware blocks.
 *
 * The common command queue infrastructure abstracts out the
 * software necessary for adding to Octeon's chained queue
 * structures. These structures are used for commands to the
 * PKO, ZIP, DFA, RAID, and DMA engine blocks. Although each
 * hardware unit takes commands and CSRs of different types,
 * they all use basic linked command buffers to store the
 * pending request. In general, users of the CVMX API don't
 * call cvmx-cmd-queue functions directly. Instead the hardware
 * unit specific wrapper should be used. The wrappers perform
 * unit specific validation and CSR writes to submit the
 * commands.
 *
 * Even though most software will never directly interact with
 * cvmx-cmd-queue, knowledge of its internal workings can help
 * in diagnosing performance problems and help with debugging.
 *
 * <hr> $Revision: 50049 $ <hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Command write operations can fail if the command queue needs
 * a new buffer and the associated FPA pool is empty. It can also
 * fail if the number of queued command words reaches the maximum
 * set at initialization.
 */
typedef enum
{
    BDK_CMD_QUEUE_SUCCESS = 0,
    BDK_CMD_QUEUE_NO_MEMORY = -1,
    BDK_CMD_QUEUE_INVALID_PARAM = -2,
} bdk_cmd_queue_result_t;

typedef struct
{
    bdk_spinlock_t lock;
    uint64_t pool_size_m1   : 16;   /**< FPA buffer size in 64bit words minus 1 */
    uint64_t index          : 16;   /**< Number of commands already used in buffer */
    uint64_t *base_ptr;             /**< Top of command buffer pointer */
    int fpa_pool;                   /**< FPA pool buffers come from */
} bdk_cmd_queue_state_t;

/**
 * Initialize a command queue for use. The initial FPA buffer is
 * allocated and the hardware unit is configured to point to the
 * new command queue.
 *
 * @param qstate    Command queue to initialize.
 * @param fpa_pool  FPA pool the command queues should come from.
 * @param pool_size Size of each buffer in the FPA pool (bytes)
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_initialize(bdk_cmd_queue_state_t *qstate, int fpa_pool, int pool_size);

/**
 * Shutdown a queue a free it's command buffers to the FPA. The
 * hardware connected to the queue must be stopped before this
 * function is called.
 *
 * @param qptr Queue to shutdown
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_shutdown(bdk_cmd_queue_state_t *qptr);

/**
 * Return the command buffer to be written to. The purpose of this
 * function is to allow CVMX routine access to the low level buffer
 * for initial hardware setup. User applications should not call this
 * function directly.
 *
 * @param qptr Command queue to query
 *
 * @return Command buffer or NULL on failure
 */
void *bdk_cmd_queue_buffer(bdk_cmd_queue_state_t *qptr);


/**
 * @INTERNAL
 * Lock the supplied queue so nobody else is updating it at the same
 * time as us.
 *
 * @param qptr     Pointer to the queue's global state
 */
static inline void __bdk_cmd_queue_lock(bdk_cmd_queue_state_t *qptr)
{
    bdk_spinlock_lock(&qptr->lock);
}


/**
 * @INTERNAL
 * Unlock the queue, flushing all writes.
 *
 * @param qptr Queue to unlock
 */
static inline void __bdk_cmd_queue_unlock(bdk_cmd_queue_state_t *qptr)
{
    bdk_spinlock_unlock(&qptr->lock);
}


/**
 * Write an arbitrary number of command words to a command queue.
 * This is a generic function; the fixed number of command word
 * functions yield higher performance.
 *
 * @param qptr  Hardware command queue to write to
 * @param use_locking
 *                  Use internal locking to ensure exclusive access for queue
 *                  updates. If you don't use this locking you must ensure
 *                  exclusivity some other way. Locking is strongly recommended.
 * @param cmd_count Number of command words to write
 * @param cmds      Array of commands to write
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write(bdk_cmd_queue_state_t *qptr, int use_locking, int cmd_count, uint64_t *cmds)
{
    if (bdk_unlikely((cmd_count < 1) || (cmd_count > 32)))
        return BDK_CMD_QUEUE_INVALID_PARAM;
    if (bdk_unlikely(cmds == NULL))
        return BDK_CMD_QUEUE_INVALID_PARAM;

    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(qptr);

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + cmd_count < qptr->pool_size_m1))
    {
        uint64_t *ptr = qptr->base_ptr;
        ptr += qptr->index;
        qptr->index += cmd_count;
        while (cmd_count--)
            *ptr++ = *cmds++;
    }
    else
    {
        uint64_t *ptr;
        int count;
        /* We need a new command buffer. Fail if there isn't one available */
        uint64_t *new_buffer = (uint64_t *)bdk_fpa_alloc(qptr->fpa_pool);
        if (bdk_unlikely(new_buffer == NULL))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_NO_MEMORY;
        }
        ptr = qptr->base_ptr;
        /* Figure out how many command words will fit in this buffer. One
            location will be needed for the next buffer pointer */
        count = qptr->pool_size_m1 - qptr->index;
        ptr += qptr->index;
        cmd_count-=count;
        while (count--)
            *ptr++ = *cmds++;
        *ptr = bdk_ptr_to_phys(new_buffer);
        /* The current buffer is full and has a link to the next buffer. Time
            to write the rest of the commands into the new buffer */
        qptr->base_ptr = new_buffer;
        qptr->index = cmd_count;
        ptr = new_buffer;
        while (cmd_count--)
            *ptr++ = *cmds++;
    }

    /* All updates are complete. Release the lock and return */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_unlock(qptr);
    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Simple function to write two command words to a command
 * queue.
 *
 * @param qptr Hardware command queue to write to
 * @param use_locking
 *                 Use internal locking to ensure exclusive access for queue
 *                 updates. If you don't use this locking you must ensure
 *                 exclusivity some other way. Locking is strongly recommended.
 * @param cmd1     Command
 * @param cmd2     Command
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write2(bdk_cmd_queue_state_t *qptr, int use_locking, uint64_t cmd1, uint64_t cmd2)
{
    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(qptr);

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + 2 < qptr->pool_size_m1))
    {
        uint64_t *ptr = qptr->base_ptr;
        ptr += qptr->index;
        qptr->index += 2;
        ptr[0] = cmd1;
        ptr[1] = cmd2;
    }
    else
    {
        uint64_t *ptr;
        /* Figure out how many command words will fit in this buffer. One
            location will be needed for the next buffer pointer */
        int count = qptr->pool_size_m1 - qptr->index;
        /* We need a new command buffer. Fail if there isn't one available */
        uint64_t *new_buffer = (uint64_t *)bdk_fpa_alloc(qptr->fpa_pool);
        if (bdk_unlikely(new_buffer == NULL))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_NO_MEMORY;
        }
        count--;
        ptr = qptr->base_ptr;
        ptr += qptr->index;
        *ptr++ = cmd1;
        if (bdk_likely(count))
            *ptr++ = cmd2;
        *ptr = bdk_ptr_to_phys(new_buffer);
        /* The current buffer is full and has a link to the next buffer. Time
            to write the rest of the commands into the new buffer */
        qptr->base_ptr = new_buffer;
        qptr->index = 0;
        if (bdk_unlikely(count == 0))
        {
            qptr->index = 1;
            new_buffer[0] = cmd2;
        }
    }

    /* All updates are complete. Release the lock and return */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_unlock(qptr);
    return BDK_CMD_QUEUE_SUCCESS;
}


/**
 * Simple function to write three command words to a command
 * queue.
 *
 * @param qptr Hardware command queue to write to
 * @param use_locking
 *                 Use internal locking to ensure exclusive access for queue
 *                 updates. If you don't use this locking you must ensure
 *                 exclusivity some other way. Locking is strongly recommended.
 * @param cmd1     Command
 * @param cmd2     Command
 * @param cmd3     Command
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write3(bdk_cmd_queue_state_t *qptr, int use_locking, uint64_t cmd1, uint64_t cmd2, uint64_t cmd3)
{
    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(qptr);

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + 3 < qptr->pool_size_m1))
    {
        uint64_t *ptr = qptr->base_ptr;
        ptr += qptr->index;
        qptr->index += 3;
        ptr[0] = cmd1;
        ptr[1] = cmd2;
        ptr[2] = cmd3;
    }
    else
    {
        uint64_t *ptr;
        /* Figure out how many command words will fit in this buffer. One
            location will be needed for the next buffer pointer */
        int count = qptr->pool_size_m1 - qptr->index;
        /* We need a new command buffer. Fail if there isn't one available */
        uint64_t *new_buffer = (uint64_t *)bdk_fpa_alloc(qptr->fpa_pool);
        if (bdk_unlikely(new_buffer == NULL))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_NO_MEMORY;
        }
        count--;
        ptr = qptr->base_ptr;
        ptr += qptr->index;
        *ptr++ = cmd1;
        if (count)
        {
            *ptr++ = cmd2;
            if (count > 1)
                *ptr++ = cmd3;
        }
        *ptr = bdk_ptr_to_phys(new_buffer);
        /* The current buffer is full and has a link to the next buffer. Time
            to write the rest of the commands into the new buffer */
        qptr->base_ptr = new_buffer;
        qptr->index = 0;
        ptr = new_buffer;
        if (count == 0)
        {
            *ptr++ = cmd2;
            qptr->index++;
        }
        if (count < 2)
        {
            *ptr++ = cmd3;
            qptr->index++;
        }
    }

    /* All updates are complete. Release the lock and return */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_unlock(qptr);
    return BDK_CMD_QUEUE_SUCCESS;
}

/** @} */

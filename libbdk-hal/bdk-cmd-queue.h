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
 * Command queue pointers are stored in a global named block
 * called "bdk_cmd_queues". Except for the PKO queues, each
 * hardware queue is stored in its own cache line to reduce SMP
 * contention on spin locks. The PKO queues are stored such that
 * every 16th queue is next to each other in memory. This scheme
 * allows for queues being in separate cache lines when there
 * are low number of queues per port. With 16 queues per port,
 * the first queue for each port is in the same cache area. The
 * second queues for each port are in another area, etc. This
 * allows software to implement very efficient lockless PKO with
 * 16 queues per port using a minimum of cache lines per core.
 * All queues for a given core will be isolated in the same
 * cache area.
 *
 * In addition to the memory pointer layout, cvmx-cmd-queue
 * provides an optimized fair ll/sc locking mechanism for the
 * queues. The lock uses a "ticket / now serving" model to
 * maintain fair order on contended locks. In addition, it uses
 * predicted locking time to limit cache contention. When a core
 * know it must wait in line for a lock, it spins on the
 * internal cycle counter to completely eliminate any causes of
 * bus traffic.
 *
 * <hr> $Revision: 50049 $ <hr>
 */

/**
 * By default we disable the max depth support. Most programs
 * don't use it and it slows down the command queue processing
 * significantly.
 */
#ifndef BDK_CMD_QUEUE_ENABLE_MAX_DEPTH
#define BDK_CMD_QUEUE_ENABLE_MAX_DEPTH 0
#endif

/**
 * Enumeration representing all hardware blocks that use command
 * queues. Each hardware block has up to 65536 sub identifiers for
 * multiple command queues. Not all chips support all hardware
 * units.
 */
typedef enum
{
    BDK_CMD_QUEUE_PKO_BASE = 0x00000,
#define BDK_CMD_QUEUE_PKO(queue) ((bdk_cmd_queue_id_t)(BDK_CMD_QUEUE_PKO_BASE + (0xffff&(queue))))
    BDK_CMD_QUEUE_ZIP      = 0x10000,
    BDK_CMD_QUEUE_DFA      = 0x20000,
    BDK_CMD_QUEUE_RAID     = 0x30000,
    BDK_CMD_QUEUE_DMA_BASE = 0x40000,
#define BDK_CMD_QUEUE_DMA(queue) ((bdk_cmd_queue_id_t)(BDK_CMD_QUEUE_DMA_BASE + (0xffff&(queue))))
    BDK_CMD_QUEUE_END      = 0x50000,
} bdk_cmd_queue_id_t;

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
    BDK_CMD_QUEUE_FULL = -2,
    BDK_CMD_QUEUE_INVALID_PARAM = -3,
    BDK_CMD_QUEUE_ALREADY_SETUP = -4,
} bdk_cmd_queue_result_t;

typedef struct
{
    uint8_t  now_serving;           /**< You have lock when this is your ticket */
    uint64_t unused1        : 24;
    uint32_t max_depth;             /**< Maximum outstanding command words */
    uint64_t fpa_pool       : 3;    /**< FPA pool buffers come from */
    uint64_t base_ptr_div128: 29;   /**< Top of command buffer pointer shifted 7 */
    uint64_t unused2        : 6;
    uint64_t pool_size_m1   : 13;   /**< FPA buffer size in 64bit words minus 1 */
    uint64_t index          : 13;   /**< Number of commands already used in buffer */
} __bdk_cmd_queue_state_t;

/**
 * This structure contains the global state of all command queues.
 * It is stored in a bootmem named block and shared by all
 * applications running on Octeon. Tickets are stored in a different
 * cache line that queue information to reduce the contention on the
 * ll/sc used to get a ticket. If this is not the case, the update
 * of queue state causes the ll/sc to fail quite often.
 */
typedef struct
{
    uint64_t                 ticket[(BDK_CMD_QUEUE_END>>16) * 256];
    __bdk_cmd_queue_state_t state[(BDK_CMD_QUEUE_END>>16) * 256];
} __bdk_cmd_queue_all_state_t;

/**
 * Initialize a command queue for use. The initial FPA buffer is
 * allocated and the hardware unit is configured to point to the
 * new command queue.
 *
 * @param queue_id  Hardware command queue to initialize.
 * @param max_depth Maximum outstanding commands that can be queued.
 * @param fpa_pool  FPA pool the command queues should come from.
 * @param pool_size Size of each buffer in the FPA pool (bytes)
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_initialize(bdk_cmd_queue_id_t queue_id, int max_depth, int fpa_pool, int pool_size);

/**
 * Shutdown a queue a free it's command buffers to the FPA. The
 * hardware connected to the queue must be stopped before this
 * function is called.
 *
 * @param queue_id Queue to shutdown
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
bdk_cmd_queue_result_t bdk_cmd_queue_shutdown(bdk_cmd_queue_id_t queue_id);

/**
 * Return the number of command words pending in the queue. This
 * function may be relatively slow for some hardware units.
 *
 * @param queue_id Hardware command queue to query
 *
 * @return Number of outstanding commands
 */
int bdk_cmd_queue_length(bdk_cmd_queue_id_t queue_id);

/**
 * Return the command buffer to be written to. The purpose of this
 * function is to allow CVMX routine access to the low level buffer
 * for initial hardware setup. User applications should not call this
 * function directly.
 *
 * @param queue_id Command queue to query
 *
 * @return Command buffer or NULL on failure
 */
void *bdk_cmd_queue_buffer(bdk_cmd_queue_id_t queue_id);

/**
 * @INTERNAL
 * Get the index into the state arrays for the supplied queue id.
 *
 * @param queue_id Queue ID to get an index for
 *
 * @return Index into the state arrays
 */
static inline int __bdk_cmd_queue_get_index(bdk_cmd_queue_id_t queue_id)
{
    /* Warning: This code currently only works with devices that have 256 queues
        or less. Devices with more than 16 queues are layed out in memory to allow
        cores quick access to every 16th queue. This reduces cache thrashing
        when you are running 16 queues per port to support lockless operation */
    int unit = queue_id>>16;
    int q = (queue_id >> 4) & 0xf;
    int core = queue_id & 0xf;
    return unit*256 + core*16 + q;
}


/**
 * @INTERNAL
 * Lock the supplied queue so nobody else is updating it at the same
 * time as us.
 *
 * @param queue_id Queue ID to lock
 * @param qptr     Pointer to the queue's global state
 */
static inline void __bdk_cmd_queue_lock(bdk_cmd_queue_id_t queue_id, __bdk_cmd_queue_state_t *qptr)
{
    extern __bdk_cmd_queue_all_state_t *__bdk_cmd_queue_state_ptr;
    int tmp;
    int my_ticket;
    BDK_PREFETCH(qptr, 0);
    asm volatile (
        ".set push\n"
        ".set noreorder\n"
        "1:\n"
        "ll     %[my_ticket], %[ticket_ptr]\n"          /* Atomic add one to ticket_ptr */
        "li     %[ticket], 1\n"                         /*    and store the original value */
        "baddu  %[ticket], %[my_ticket]\n"              /*    in my_ticket */
        "sc     %[ticket], %[ticket_ptr]\n"
        "beqz   %[ticket], 1b\n"
        " nop\n"
        "lbu    %[ticket], %[now_serving]\n"            /* Load the current now_serving ticket */
        "2:\n"
        "beq    %[ticket], %[my_ticket], 4f\n"          /* Jump out if now_serving == my_ticket */
        " subu   %[ticket], %[my_ticket], %[ticket]\n"  /* Find out how many tickets are in front of me */
        "subu  %[ticket], 1\n"                          /* Use tickets in front of me minus one to delay */
        "cins   %[ticket], %[ticket], 5, 7\n"           /* Delay will be ((tickets in front)-1)*32 loops */
        "3:\n"
        "bnez   %[ticket], 3b\n"                        /* Loop here until our ticket might be up */
        " subu  %[ticket], 1\n"
        "b      2b\n"                                   /* Jump back up to check out ticket again */
        " lbu   %[ticket], %[now_serving]\n"            /* Load the current now_serving ticket */
        "4:\n"
        ".set pop\n"
        : [ticket_ptr] "=m" (__bdk_cmd_queue_state_ptr->ticket[__bdk_cmd_queue_get_index(queue_id)]),
          [now_serving] "=m" (qptr->now_serving),
          [ticket] "=r" (tmp),
          [my_ticket] "=r" (my_ticket)
    );
}


/**
 * @INTERNAL
 * Unlock the queue, flushing all writes.
 *
 * @param qptr   Queue to unlock
 */
static inline void __bdk_cmd_queue_unlock(__bdk_cmd_queue_state_t *qptr)
{
    uint8_t ns;

    ns = qptr->now_serving + 1;
    BDK_SYNCW; /* Order queue manipulation with respect to the unlock.  */
    qptr->now_serving = ns;
    BDK_SYNCW; /* nudge out the unlock. */
}


/**
 * @INTERNAL
 * Get the queue state structure for the given queue id
 *
 * @param queue_id Queue id to get
 *
 * @return Queue structure or NULL on failure
 */
static inline __bdk_cmd_queue_state_t *__bdk_cmd_queue_get_state(bdk_cmd_queue_id_t queue_id)
{
    extern __bdk_cmd_queue_all_state_t *__bdk_cmd_queue_state_ptr;
    if (BDK_ENABLE_PARAMETER_CHECKING)
    {
        if (bdk_unlikely(queue_id >= BDK_CMD_QUEUE_END))
            return NULL;
        if (bdk_unlikely((queue_id & 0xffff) >= 256))
            return NULL;
    }
    return &__bdk_cmd_queue_state_ptr->state[__bdk_cmd_queue_get_index(queue_id)];
}


/**
 * Write an arbitrary number of command words to a command queue.
 * This is a generic function; the fixed number of command word
 * functions yield higher performance.
 *
 * @param queue_id  Hardware command queue to write to
 * @param use_locking
 *                  Use internal locking to ensure exclusive access for queue
 *                  updates. If you don't use this locking you must ensure
 *                  exclusivity some other way. Locking is strongly recommended.
 * @param cmd_count Number of command words to write
 * @param cmds      Array of commands to write
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write(bdk_cmd_queue_id_t queue_id, int use_locking, int cmd_count, uint64_t *cmds)
{
    __bdk_cmd_queue_state_t *qptr = __bdk_cmd_queue_get_state(queue_id);

    if (BDK_ENABLE_PARAMETER_CHECKING)
    {
        if (bdk_unlikely(qptr == NULL))
            return BDK_CMD_QUEUE_INVALID_PARAM;
        if (bdk_unlikely((cmd_count < 1) || (cmd_count > 32)))
            return BDK_CMD_QUEUE_INVALID_PARAM;
        if (bdk_unlikely(cmds == NULL))
            return BDK_CMD_QUEUE_INVALID_PARAM;
    }

    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(queue_id, qptr);

    /* If a max queue length was specified then make sure we don't
        exceed it. If any part of the command would be below the limit
        we allow it */
    if (BDK_CMD_QUEUE_ENABLE_MAX_DEPTH && bdk_unlikely(qptr->max_depth))
    {
        if (bdk_unlikely(bdk_cmd_queue_length(queue_id) > (int)qptr->max_depth))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_FULL;
        }
    }

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + cmd_count < qptr->pool_size_m1))
    {
        uint64_t *ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
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
        ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
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
        qptr->base_ptr_div128 = *ptr >> 7;
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
 * @param queue_id Hardware command queue to write to
 * @param use_locking
 *                 Use internal locking to ensure exclusive access for queue
 *                 updates. If you don't use this locking you must ensure
 *                 exclusivity some other way. Locking is strongly recommended.
 * @param cmd1     Command
 * @param cmd2     Command
 *
 * @return BDK_CMD_QUEUE_SUCCESS or a failure code
 */
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write2(bdk_cmd_queue_id_t queue_id, int use_locking, uint64_t cmd1, uint64_t cmd2)
{
    __bdk_cmd_queue_state_t *qptr = __bdk_cmd_queue_get_state(queue_id);

    if (BDK_ENABLE_PARAMETER_CHECKING)
    {
        if (bdk_unlikely(qptr == NULL))
            return BDK_CMD_QUEUE_INVALID_PARAM;
    }

    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(queue_id, qptr);

    /* If a max queue length was specified then make sure we don't
        exceed it. If any part of the command would be below the limit
        we allow it */
    if (BDK_CMD_QUEUE_ENABLE_MAX_DEPTH && bdk_unlikely(qptr->max_depth))
    {
        if (bdk_unlikely(bdk_cmd_queue_length(queue_id) > (int)qptr->max_depth))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_FULL;
        }
    }

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + 2 < qptr->pool_size_m1))
    {
        uint64_t *ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
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
        ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
        ptr += qptr->index;
        *ptr++ = cmd1;
        if (bdk_likely(count))
            *ptr++ = cmd2;
        *ptr = bdk_ptr_to_phys(new_buffer);
        /* The current buffer is full and has a link to the next buffer. Time
            to write the rest of the commands into the new buffer */
        qptr->base_ptr_div128 = *ptr >> 7;
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
 * @param queue_id Hardware command queue to write to
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
static inline bdk_cmd_queue_result_t bdk_cmd_queue_write3(bdk_cmd_queue_id_t queue_id, int use_locking, uint64_t cmd1, uint64_t cmd2, uint64_t cmd3)
{
    __bdk_cmd_queue_state_t *qptr = __bdk_cmd_queue_get_state(queue_id);

    if (BDK_ENABLE_PARAMETER_CHECKING)
    {
        if (bdk_unlikely(qptr == NULL))
            return BDK_CMD_QUEUE_INVALID_PARAM;
    }

    /* Make sure nobody else is updating the same queue */
    if (bdk_likely(use_locking))
        __bdk_cmd_queue_lock(queue_id, qptr);

    /* If a max queue length was specified then make sure we don't
        exceed it. If any part of the command would be below the limit
        we allow it */
    if (BDK_CMD_QUEUE_ENABLE_MAX_DEPTH && bdk_unlikely(qptr->max_depth))
    {
        if (bdk_unlikely(bdk_cmd_queue_length(queue_id) > (int)qptr->max_depth))
        {
            if (bdk_likely(use_locking))
                __bdk_cmd_queue_unlock(qptr);
            return BDK_CMD_QUEUE_FULL;
        }
    }

    /* Normally there is plenty of room in the current buffer for the command */
    if (bdk_likely(qptr->index + 3 < qptr->pool_size_m1))
    {
        uint64_t *ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
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
        ptr = (uint64_t *)bdk_phys_to_ptr((uint64_t)qptr->base_ptr_div128<<7);
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
        qptr->base_ptr_div128 = *ptr >> 7;
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


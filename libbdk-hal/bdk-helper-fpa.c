#include <bdk.h>
#include <malloc.h>

/**
 * @INTERNAL
 * Allocate memory for and initialize a single FPA pool.
 *
 * @param pool    Pool to initialize
 * @param buffer_size  Size of buffers to allocate in bytes
 * @param buffers Number of buffers to put in the pool. Zero is allowed
 * @param name    String name of the pool for debugging purposes
 * @return Zero on success, non-zero on failure
 */
static int __bdk_helper_initialize_fpa_pool(int pool, uint64_t buffer_size,
                                           uint64_t buffers, const char *name)
{
    uint64_t current_num;
    void *memory;
    uint64_t align = BDK_CACHE_LINE_SIZE;

    /* Align the allocation so that power of 2 size buffers are naturally aligned */
    while (align < buffer_size)
        align = align << 1;

    if (buffers == 0)
        return 0;

    current_num = BDK_CSR_READ(BDK_FPA_QUEX_AVAILABLE(pool));
    if (current_num)
    {
        bdk_dprintf("Fpa pool %d(%s) already has %llu buffers. Skipping setup.\n",
                     pool, name, (unsigned long long)current_num);
        return 0;
    }

    memory = memalign(align, buffer_size * buffers);
    if (memory == NULL)
    {
        bdk_dprintf("Out of memory initializing fpa pool %d(%s).\n", pool, name);
        return -1;
    }
    bdk_fpa_setup_pool(pool, name, memory, buffer_size, buffers);
    return 0;
}


/**
 * @INTERNAL
 * Allocate memory and initialize the FPA pools using memory
 * from bdk-bootmem. Specifying zero for the number of
 * buffers will cause that FPA pool to not be setup. This is
 * useful if you aren't using some of the hardware and want
 * to save memory. Use bdk_helper_initialize_fpa instead of
 * this function directly.
 *
 * @param pip_pool Should always be BDK_FPA_PACKET_POOL
 * @param pip_size Should always be BDK_FPA_PACKET_POOL_SIZE
 * @param pip_buffers
 *                 Number of packet buffers.
 * @param wqe_pool Should always be BDK_FPA_WQE_POOL
 * @param wqe_size Should always be BDK_FPA_WQE_POOL_SIZE
 * @param wqe_entries
 *                 Number of work queue entries
 * @param pko_pool Should always be BDK_FPA_OUTPUT_BUFFER_POOL
 * @param pko_size Should always be BDK_FPA_OUTPUT_BUFFER_POOL_SIZE
 * @param pko_buffers
 *                 PKO Command buffers. You should at minimum have two per
 *                 each PKO queue.
 * @param tim_pool Should always be BDK_FPA_TIMER_POOL
 * @param tim_size Should always be BDK_FPA_TIMER_POOL_SIZE
 * @param tim_buffers
 *                 TIM ring buffer command queues. At least two per timer bucket
 *                 is recommended.
 * @param dfa_pool Should always be BDK_FPA_DFA_POOL
 * @param dfa_size Should always be BDK_FPA_DFA_POOL_SIZE
 * @param dfa_buffers
 *                 DFA command buffer. A relatively small (32 for example)
 *                 number should work.
 * @return Zero on success, non-zero if out of memory
 */
static int __bdk_helper_initialize_fpa(int pip_pool, int pip_size, int pip_buffers,
                                        int wqe_pool, int wqe_size, int wqe_entries,
                                        int pko_pool, int pko_size, int pko_buffers,
                                        int tim_pool, int tim_size, int tim_buffers,
                                        int dfa_pool, int dfa_size, int dfa_buffers)
{
    int status;

    bdk_fpa_enable();

    if ((pip_buffers > 0) && (pip_buffers <= 64))
        bdk_dprintf("Warning: %d packet buffers may not be enough for hardware"
                     " prefetch. 65 or more is recommended.\n", pip_buffers);

    if (pip_pool >= 0)
    {
        status = __bdk_helper_initialize_fpa_pool(pip_pool, pip_size, pip_buffers,
                                                 "Packet Buffers");
        if (status)
            return status;
    }

    if (wqe_pool >= 0)
    {
        status = __bdk_helper_initialize_fpa_pool(wqe_pool, wqe_size, wqe_entries,
                                                 "Work Queue Entries");
        if (status)
            return status;
    }

    if (pko_pool >= 0)
    {
        status = __bdk_helper_initialize_fpa_pool(pko_pool, pko_size, pko_buffers,
                                                 "PKO Command Buffers");
        if (status)
            return status;
    }

    if (tim_pool >= 0)
    {
        status = __bdk_helper_initialize_fpa_pool(tim_pool, tim_size, tim_buffers,
                                                 "TIM Command Buffers");
        if (status)
            return status;
    }

    if (dfa_pool >= 0)
    {
        status = __bdk_helper_initialize_fpa_pool(dfa_pool, dfa_size, dfa_buffers,
                                                 "DFA Command Buffers");
        if (status)
            return status;
    }

    return 0;
}


/**
 * Allocate memory and initialize the FPA pools using memory
 * from bdk-bootmem. Sizes of each element in the pools is
 * controlled by the bdk-config.h header file. Specifying
 * zero for any parameter will cause that FPA pool to not be
 * setup. This is useful if you aren't using some of the
 * hardware and want to save memory.
 *
 * @param packet_buffers
 *               Number of packet buffers to allocate
 * @param work_queue_entries
 *               Number of work queue entries
 * @param pko_buffers
 *               PKO Command buffers. You should at minimum have two per
 *               each PKO queue.
 * @param tim_buffers
 *               TIM ring buffer command queues. At least two per timer bucket
 *               is recommended.
 * @param dfa_buffers
 *               DFA command buffer. A relatively small (32 for example)
 *               number should work.
 * @return Zero on success, non-zero if out of memory
 */
int bdk_helper_initialize_fpa(int packet_buffers, int work_queue_entries,
                               int pko_buffers, int tim_buffers, int dfa_buffers)
{
#ifndef BDK_FPA_PACKET_POOL
#define BDK_FPA_PACKET_POOL -1
#define BDK_FPA_PACKET_POOL_SIZE 0
#endif
#ifndef BDK_FPA_WQE_POOL
#define BDK_FPA_WQE_POOL -1
#define BDK_FPA_WQE_POOL_SIZE 0
#endif
#ifndef BDK_FPA_OUTPUT_BUFFER_POOL
#define BDK_FPA_OUTPUT_BUFFER_POOL -1
#define BDK_FPA_OUTPUT_BUFFER_POOL_SIZE 0
#endif
#ifndef BDK_FPA_TIMER_POOL
#define BDK_FPA_TIMER_POOL -1
#define BDK_FPA_TIMER_POOL_SIZE 0
#endif
#ifndef BDK_FPA_DFA_POOL
#define BDK_FPA_DFA_POOL -1
#define BDK_FPA_DFA_POOL_SIZE 0
#endif
    return __bdk_helper_initialize_fpa(
        BDK_FPA_PACKET_POOL,        BDK_FPA_PACKET_POOL_SIZE,          packet_buffers,
        BDK_FPA_WQE_POOL,           BDK_FPA_WQE_POOL_SIZE,             work_queue_entries,
        BDK_FPA_OUTPUT_BUFFER_POOL, BDK_FPA_OUTPUT_BUFFER_POOL_SIZE,   pko_buffers,
        BDK_FPA_TIMER_POOL,         BDK_FPA_TIMER_POOL_SIZE,           tim_buffers,
        BDK_FPA_DFA_POOL,           BDK_FPA_DFA_POOL_SIZE,             dfa_buffers);
}


#include <bdk.h>

int bdk_pko_next_free_queue = 0;
int bdk_pko_next_free_engine = 0;

int __bdk_pko_alloc_pipe(int num_pipes)
{
    static int next_free_pipe = 0;
    int pipe = next_free_pipe;
    next_free_pipe += num_pipes;
    if (next_free_pipe > 128)
        bdk_fatal("PKO ran out of pipes. bdk_if_init() is incorrect\n");
    return pipe;
}

int __bdk_pko_alloc_engine(void)
{
    int engine = bdk_pko_next_free_engine++;
    if (engine > 19)
        bdk_fatal("PKO ran out of engines. bdk_if_init() is incorrect\n");
    return engine;
}

int __bdk_pko_alloc_port(void)
{
    static int next_free_port = 0;
    int port = next_free_port++;
    if (port > 127)
        bdk_fatal("PKO ran out of ports. bdk_if_init() is incorrect\n");
    return port;
}


/**
 * Configure a output port and the associated queues for use.
 *
 * @param pko_port   PKO internal port to program
 * @param num_queues Number of queues to associate with this port
 * @param num_static_queues
 *                   Number of queues that should have static priority. Must be less
 *                   than or equal to num_queues.
 *
 * @return The base queue number, or negative on failure.
 */
int bdk_pko_config_port(int pko_port, int num_queues, int num_static_queues, bdk_cmd_queue_state_t *qptr)
{
    int base_queue = bdk_pko_next_free_queue;
    bdk_pko_next_free_queue += num_queues;

    if (num_static_queues > num_queues)
        num_static_queues = num_queues;

    for (int queue = 0; queue < num_queues; queue++)
    {
        void *buf_ptr = bdk_cmd_queue_buffer(qptr + queue);

        if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
        {
            BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_QUEUE_PTRS);
            BDK_CSR_DEFINE(ptrs1, BDK_PKO_REG_QUEUE_PTRS1);

            ptrs1.u64 = 0;
            ptrs1.s.idx3    = queue >> 3;
            ptrs1.s.qid7    = (base_queue + queue) >> 7;

            ptrs.u64 = 0;
            ptrs.s.s_tail   = queue == (num_static_queues - 1);
            ptrs.s.static_p = num_static_queues > 0;
            ptrs.s.static_q = queue < num_static_queues;
            ptrs.s.qos_mask = 0xff;
            ptrs.s.buf_ptr  = bdk_ptr_to_phys(buf_ptr);
            ptrs.s.tail     = queue == (num_queues - 1);
            ptrs.s.index    = queue;
            ptrs.s.port     = pko_port;
            ptrs.s.queue    = base_queue + queue;

            BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_PTRS1, ptrs1.u64);
            BDK_CSR_WRITE(BDK_PKO_MEM_QUEUE_PTRS, ptrs.u64);
        }
        else
        {
            BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IQUEUE_PTRS);
            ptrs.u64 = 0;
            ptrs.s.s_tail   = queue == (num_static_queues - 1);
            ptrs.s.static_p = num_static_queues > 0;
            ptrs.s.static_q = queue < num_static_queues;
            ptrs.s.qos_mask = 0xff;
            ptrs.s.buf_ptr  = bdk_ptr_to_phys(buf_ptr) >> 7;
            ptrs.s.tail     = queue == (num_queues - 1);
            ptrs.s.index    = queue;
            ptrs.s.ipid     = pko_port;
            ptrs.s.qid      = base_queue + queue;
            BDK_CSR_WRITE(BDK_PKO_MEM_IQUEUE_PTRS, ptrs.u64);
        }
    }

    return base_queue;
}


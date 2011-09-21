#include <bdk.h>

#define BDK_PKO_MAX_OUTPUT_QUEUES 256

/**
 * Internal state of packet output
 */
static int bdk_pko_next_free_queue = 0;
static int bdk_pko_next_free_engine = 0;

/**
 * Call before any other calls to initialize the packet
 * output system.  This does chip global config, and should only be
 * done by one core.
 */
void bdk_pko_initialize(void)
{
    /* Set the size of the PKO command buffers to an odd number of 64bit
        words. This allows the normal two word send to stay aligned and never
        span a comamnd word buffer. */
    BDK_CSR_DEFINE(config, BDK_PKO_REG_CMD_BUF);
    config.u64 = 0;
    config.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    config.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) / 8 - 1;
    BDK_CSR_WRITE(BDK_PKO_REG_CMD_BUF, config.u64);

    /* Clear out all queue state */
    if (!OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_QUEUE_PTRS);
        BDK_CSR_DEFINE(ptrs1, BDK_PKO_REG_QUEUE_PTRS1);

        ptrs.u64 = 0;
        ptrs.s.tail = 1;
        ptrs.s.port = -1;
        ptrs1.u64 = 0;

        for (int i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        {
            ptrs1.s.qid7 = i>>7;
            ptrs.s.queue = i & 0x3f;
            BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_PTRS1, ptrs1.u64);
            BDK_CSR_WRITE(BDK_PKO_MEM_QUEUE_PTRS, ptrs.u64);
        }
    }
    else
    {
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IQUEUE_PTRS);
        ptrs.u64 = 0;
        ptrs.s.tail = 1;
        ptrs.s.ipid = -1;
        for (int i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        {
            ptrs.s.qid = i;
            BDK_CSR_WRITE(BDK_PKO_MEM_IQUEUE_PTRS, ptrs.u64);
        }
    }
}

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

static int __bdk_pko_memory_per_engine(int engine)
{
    /* CN68XX has 40KB to devide between the engines in 2KB chunks */
    int size_per_engine = 40 / 2 / bdk_pko_next_free_engine;
    int size;

    if (engine >= bdk_pko_next_free_engine)
    {
        /* Unused engines get no space */
        size = 0;
    }
    else if (engine == bdk_pko_next_free_engine-1)
    {
        /* The last engine gets all the space lost by rounding. This means
            the ILK gets the most space */
        size = 40 / 2 - engine * size_per_engine;
    }
    else
    {
        /* All other engines get the same space */
        size = size_per_engine;
    }

    return size;
}


/**
 * Enables the packet output hardware. It must already be
 * configured.
 */
void bdk_pko_enable(void)
{
    bdk_pko_reg_flags_t flags;

    /* If we aren't using all of the queues optimize PKO's internal memory */
    /* <=32 is only supported on CN68XX */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX) && (bdk_pko_next_free_queue <= 32))
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 3);
    else if (bdk_pko_next_free_queue <= 64)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 2);
    else if (bdk_pko_next_free_queue <= 128)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 1);

    /* Optimize the PKO engine memory */
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        for (int i=0; i<2; i++)
        {
            BDK_CSR_INIT(engine_storage, BDK_PKO_REG_ENGINE_STORAGEX(i));
            engine_storage.s.engine0 = __bdk_pko_memory_per_engine(16*i + 0);
            engine_storage.s.engine1 = __bdk_pko_memory_per_engine(16*i + 1);
            engine_storage.s.engine2 = __bdk_pko_memory_per_engine(16*i + 2);
            engine_storage.s.engine3 = __bdk_pko_memory_per_engine(16*i + 3);
            engine_storage.s.engine4 = __bdk_pko_memory_per_engine(16*i + 4);
            engine_storage.s.engine5 = __bdk_pko_memory_per_engine(16*i + 5);
            engine_storage.s.engine6 = __bdk_pko_memory_per_engine(16*i + 6);
            engine_storage.s.engine7 = __bdk_pko_memory_per_engine(16*i + 7);
            engine_storage.s.engine8 = __bdk_pko_memory_per_engine(16*i + 8);
            engine_storage.s.engine9 = __bdk_pko_memory_per_engine(16*i + 9);
            engine_storage.s.engine10 = __bdk_pko_memory_per_engine(16*i + 10);
            engine_storage.s.engine11 = __bdk_pko_memory_per_engine(16*i + 11);
            engine_storage.s.engine12 = __bdk_pko_memory_per_engine(16*i + 12);
            engine_storage.s.engine13 = __bdk_pko_memory_per_engine(16*i + 13);
            engine_storage.s.engine14 = __bdk_pko_memory_per_engine(16*i + 14);
            engine_storage.s.engine15 = __bdk_pko_memory_per_engine(16*i + 15);
            BDK_CSR_WRITE(BDK_PKO_REG_ENGINE_STORAGEX(i), engine_storage.u64);
        }
        /* Enable using the internal storage for all engines */
        BDK_CSR_WRITE(BDK_PKO_REG_ENGINE_THRESH, (1<<bdk_pko_next_free_engine)-1);
    }

    flags.u64 = BDK_CSR_READ(BDK_PKO_REG_FLAGS);
    if (flags.s.ena_pko)
        bdk_warn("Enabling PKO when PKO already enabled.\n");

    flags.s.ena_dwb = BDK_USE_DWB;
    flags.s.ena_pko = 1;
    flags.s.store_be =1;  /* always enable big endian for 3-word command. Does nothing for 2-word */
    BDK_CSR_WRITE(BDK_PKO_REG_FLAGS, flags.u64);
}


/**
 * Disables the packet output. Does not affect any configuration.
 */
void bdk_pko_disable(void)
{
    BDK_CSR_MODIFY(c, BDK_PKO_REG_FLAGS,
        c.s.ena_pko = 0);
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


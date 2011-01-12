#include <bdk.h>

/* Adjust the command buffer size by 1 word so that in the case of using only
** two word PKO commands no command words stradle buffers.  The useful values
** for this are 0 and 1. */
#define BDK_PKO_COMMAND_BUFFER_SIZE_ADJUST 1
#define BDK_PKO_MAX_OUTPUT_QUEUES 256

/**
 * Internal state of packet output
 */
static int bdk_pko_next_free_queue = 0;

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
    config.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) / 8 - BDK_PKO_COMMAND_BUFFER_SIZE_ADJUST;
    BDK_CSR_WRITE(BDK_PKO_REG_CMD_BUF, config.u64);

    /* Setup port mapping */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        /* Hardware default is correct */
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        int eid = 0;
        int pipe = 8; /* Reserve 0-7 for loop interfaces */
        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */

        /* PKO ports for GMX */
        for (int gmx_block=0; gmx_block<5; gmx_block++)
        {
            int num_ports;
            BDK_CSR_INIT(mode, BDK_GMXX_INF_MODE(gmx_block));
            if (mode.s.type == 0)
                num_ports = 4;
            else
                num_ports = 1;
            for (int gmx_index=0; gmx_index<num_ports; gmx_index++)
            {
                BDK_CSR_MODIFY(c, BDK_GMXX_TXX_PIPE(gmx_index, gmx_block),
                    c.s.nump = 1;
                    c.s.base = pipe);
                ptrs.s.crc = 1;         /* Use CRC on packets */
                ptrs.s.min_pkt = 1;     /* Set min packet to 64 bytes */
                ptrs.s.pipe = pipe++;   /* Which PKO pipe */
                ptrs.s.intr = gmx_block*4 + gmx_index;  /* Which interface */
                ptrs.s.eid = eid++;     /* Which engine */
                ptrs.s.ipid = gmx_block*4 + gmx_index;  /* PKO internal port */
                BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);
            }
        }

        /* PKO port 32-63 = DPI (ports 0-31) */
        int num_dpi = 32;
        BDK_CSR_MODIFY(c, BDK_SLI_TX_PIPE,
            c.s.nump = num_dpi;
            c.s.base = pipe);
        for (int i=0; i<num_dpi; i++)
        {
            ptrs.s.crc = 0;     /* No CRC on packets */
            ptrs.s.min_pkt = 0; /* No min packet */
            ptrs.s.pipe = pipe++; /* Which PKO pipe */
            ptrs.s.intr = 30;   /* Which interface */
            ptrs.s.eid = eid;   /* Which engine */
            ptrs.s.ipid = 32+i; /* PKO internal port */
            BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);
        }
        eid++;

        /* PKO port 64-71 = PIP/IPD (Loop ports 0-7) */
        int num_loop = 8;
        for (int i=0; i<num_loop; i++)
        {
            ptrs.s.crc = 0;     /* No CRC on packets */
            ptrs.s.min_pkt = 0; /* No min packet */
            ptrs.s.pipe = i;    /* Which PKO pipe */
            ptrs.s.intr = 31;   /* Which interface */
            ptrs.s.eid = eid;   /* Which engine */
            ptrs.s.ipid = 64+i; /* PKO internal port */
            BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);
        }
        eid++;
#if 0
        /* PKO port 72 = ILK interface 0 */
        ptrs.s.crc = 1;     /* Use CRC on packets */
        ptrs.s.min_pkt = 1; /* Set min packet to 64 bytes */
        ptrs.s.pipe = 36;   /* Which PKO pipe */
        ptrs.s.intr = 28;   /* Which interface */
        ptrs.s.eid = eid++; /* Which engine */
        ptrs.s.ipid = 72;   /* PKO internal port */
        BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* PKO port 80 = ILK interface 1 */
        ptrs.s.crc = 1;     /* Use CRC on packets */
        ptrs.s.min_pkt = 1; /* Set min packet to 64 bytes */
        ptrs.s.pipe = 37;   /* Which PKO pipe */
        ptrs.s.intr = 29;   /* Which interface */
        ptrs.s.eid = eid++; /* Which engine */
        ptrs.s.ipid = 80;   /* PKO internal port */
        BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);
#endif
    }

    /* Clear out all queue state */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
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

/**
 * Enables the packet output hardware. It must already be
 * configured.
 */
void bdk_pko_enable(void)
{
    bdk_pko_reg_flags_t flags;

    /* If we aren't using all of the queues optimize PKO's internal memory */
    if (bdk_pko_next_free_queue <= 64)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 2);
    else if (bdk_pko_next_free_queue <= 128)
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 1);

    flags.u64 = BDK_CSR_READ(BDK_PKO_REG_FLAGS);
    if (flags.s.ena_pko)
        bdk_warn("Enabling PKO when PKO already enabled.\n");

    flags.s.ena_dwb = 1;
    flags.s.ena_pko = 1;
    flags.s.store_be =1;  /* always enable big endian for 3-word command. Does nothing for 2-word */
    BDK_CSR_WRITE(BDK_PKO_REG_FLAGS, flags.u64);
}


/**
 * Disables the packet output. Does not affect any configuration.
 */
void bdk_pko_disable(void)
{
    bdk_pko_reg_flags_t pko_reg_flags;
    pko_reg_flags.u64 = BDK_CSR_READ(BDK_PKO_REG_FLAGS);
    pko_reg_flags.s.ena_pko = 0;
    BDK_CSR_WRITE(BDK_PKO_REG_FLAGS, pko_reg_flags.u64);
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
int bdk_pko_config_port(int pko_port, int num_queues, int num_static_queues)
{
    int base_queue = bdk_pko_next_free_queue;
    bdk_pko_next_free_queue += num_queues;

    if (num_static_queues > num_queues)
        num_static_queues = num_queues;

    for (int queue = 0; queue < num_queues; queue++)
    {
        bdk_cmd_queue_result_t cmd_res = bdk_cmd_queue_initialize(BDK_CMD_QUEUE_PKO(base_queue + queue),
                                                                    BDK_FPA_OUTPUT_BUFFER_POOL,
                                                                    bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) - BDK_PKO_COMMAND_BUFFER_SIZE_ADJUST*8);
        if (cmd_res != BDK_CMD_QUEUE_SUCCESS)
        {
            switch (cmd_res)
            {
                case BDK_CMD_QUEUE_NO_MEMORY:
                    bdk_error("bdk_pko_config_port(%d,%d,%d): Unable to allocate output buffer.\n", pko_port, num_queues, num_static_queues);
                    return -1;
                case BDK_CMD_QUEUE_ALREADY_SETUP:
                    bdk_error("bdk_pko_config_port: Port already setup.\n");
                    return -1;
                case BDK_CMD_QUEUE_INVALID_PARAM:
                default:
                    bdk_error("bdk_pko_config_port(%d,%d,%d): Command queue initialization failed.\n", pko_port, num_queues, num_static_queues);
                    return -1;
            }
        }

        void *buf_ptr = bdk_cmd_queue_buffer(BDK_CMD_QUEUE_PKO(base_queue + queue));

        if (OCTEON_IS_MODEL(OCTEON_CN63XX))
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


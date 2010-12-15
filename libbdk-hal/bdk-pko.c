#include <bdk.h>

/**
 * Internal state of packet output
 */

/**
 * Call before any other calls to initialize the packet
 * output system.  This does chip global config, and should only be
 * done by one core.
 */

void bdk_pko_initialize(void)
{
    int i;
    uint64_t priority = 8;
    bdk_pko_reg_cmd_buf_t config;

    /* Set the size of the PKO command buffers to an odd number of 64bit
        words. This allows the normal two word send to stay aligned and never
        span a comamnd word buffer. */
    config.u64 = 0;
    config.s.pool = BDK_FPA_OUTPUT_BUFFER_POOL;
    config.s.size = bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) / 8 - 1;

    BDK_CSR_WRITE(BDK_PKO_REG_CMD_BUF, config.u64);

    for (i=0; i<BDK_PKO_MAX_OUTPUT_QUEUES; i++)
        bdk_pko_config_port(BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID, i, 1, &priority);

#if 0 // FIXME reduce queues
    /* If we aren't using all of the queues optimize PKO's internal memory */
    {
        int num_interfaces = bdk_helper_get_number_of_interfaces();
        int last_port = bdk_helper_get_last_ipd_port(num_interfaces-1);
        int max_queues = bdk_pko_get_base_queue(last_port) + bdk_pko_get_num_queues(last_port);
        if (max_queues <= 64)
            BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 2);
        else if (max_queues <= 128)
            BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_MODE, 1);
    }
#endif
}

/**
 * Enables the packet output hardware. It must already be
 * configured.
 */
void bdk_pko_enable(void)
{
    bdk_pko_reg_flags_t flags;

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
 * @INTERNAL
 * Reset the packet output.
 */
static void __bdk_pko_reset(void)
{
    bdk_pko_reg_flags_t pko_reg_flags;
    pko_reg_flags.u64 = BDK_CSR_READ(BDK_PKO_REG_FLAGS);
    pko_reg_flags.s.reset = 1;
    BDK_CSR_WRITE(BDK_PKO_REG_FLAGS, pko_reg_flags.u64);
}


/**
 * Shutdown and free resources required by packet output.
 */
void bdk_pko_shutdown(void)
{
    bdk_pko_mem_queue_ptrs_t config;
    int queue;

    bdk_pko_disable();

    for (queue=0; queue<BDK_PKO_MAX_OUTPUT_QUEUES; queue++)
    {
        config.u64          = 0;
        config.s.tail       = 1;
        config.s.index      = 0;
        config.s.port       = BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID;
        config.s.queue      = queue & 0x7f;
        config.s.qos_mask   = 0;
        config.s.buf_ptr    = 0;
        bdk_pko_reg_queue_ptrs1_t config1;
        config1.u64 = 0;
        config1.s.qid7 = queue >> 7;
        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_PTRS1, config1.u64);
        BDK_CSR_WRITE(BDK_PKO_MEM_QUEUE_PTRS, config.u64);
        bdk_cmd_queue_shutdown(BDK_CMD_QUEUE_PKO(queue));
    }
    __bdk_pko_reset();
}


/**
 * Configure a output port and the associated queues for use.
 *
 * @param port       Port to configure.
 * @param base_queue First queue number to associate with this port.
 * @param num_queues Number of queues to associate with this port
 * @param priority   Array of priority levels for each queue. Values are
 *                   allowed to be 0-8. A value of 8 get 8 times the traffic
 *                   of a value of 1.  A value of 0 indicates that no rounds
 *                   will be participated in. These priorities can be changed
 *                   on the fly while the pko is enabled. A priority of 9
 *                   indicates that static priority should be used.  If static
 *                   priority is used all queues with static priority must be
 *                   contiguous starting at the base_queue, and lower numbered
 *                   queues have higher priority than higher numbered queues.
 *                   There must be num_queues elements in the array.
 */
bdk_pko_status_t bdk_pko_config_port(uint64_t port, uint64_t base_queue, uint64_t num_queues, const uint64_t priority[])
{
    bdk_pko_status_t          result_code;
    uint64_t                   queue;
    bdk_pko_mem_queue_ptrs_t  config;
    bdk_pko_reg_queue_ptrs1_t config1;
    int static_priority_base = -1;
    int static_priority_end = -1;


    if ((port >= BDK_PKO_NUM_OUTPUT_PORTS) && (port != BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID))
    {
        bdk_error("bdk_pko_config_port: Invalid port %llu\n", (unsigned long long)port);
        return BDK_PKO_INVALID_PORT;
    }

    if (base_queue + num_queues > BDK_PKO_MAX_OUTPUT_QUEUES)
    {
        bdk_error("bdk_pko_config_port: Invalid queue range %llu\n", (unsigned long long)(base_queue + num_queues));
        return BDK_PKO_INVALID_QUEUE;
    }

    if (priority && (port != BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID))
    {
        /* Validate the static queue priority setup and set static_priority_base and static_priority_end
        ** accordingly. */
        for (queue = 0; queue < num_queues; queue++)
        {
            /* Find first queue of static priority */
            if (static_priority_base == -1 && priority[queue] == BDK_PKO_QUEUE_STATIC_PRIORITY)
                static_priority_base = queue;
            /* Find last queue of static priority */
            if (static_priority_base != -1 && static_priority_end == -1 && priority[queue] != BDK_PKO_QUEUE_STATIC_PRIORITY && queue)
                static_priority_end = queue - 1;
            else if (static_priority_base != -1 && static_priority_end == -1 && queue == num_queues - 1)
                static_priority_end = queue;  /* all queues are static priority */
            /* Check to make sure all static priority queues are contiguous.  Also catches some cases of
            ** static priorites not starting at queue 0. */
            if (static_priority_end != -1 && (int)queue > static_priority_end && priority[queue] == BDK_PKO_QUEUE_STATIC_PRIORITY)
            {
                bdk_error("bdk_pko_config_port: Static priority queues aren't contiguous or don't start at base queue. q: %d, eq: %d\n", (int)queue, static_priority_end);
                return BDK_PKO_INVALID_PRIORITY;
            }
        }
        if (static_priority_base > 0)
        {
            bdk_error("bdk_pko_config_port: Static priority queues don't start at base queue. sq: %d\n", static_priority_base);
            return BDK_PKO_INVALID_PRIORITY;
        }
    }
    /* At this point, static_priority_base and static_priority_end are either both -1,
    ** or are valid start/end queue numbers */

    result_code = BDK_PKO_SUCCESS;

    for (queue = 0; queue < num_queues; queue++)
    {
        uint64_t  *buf_ptr = NULL;

        config1.u64         = 0;
        config1.s.idx3      = queue >> 3;
        config1.s.qid7      = (base_queue + queue) >> 7;

        config.u64          = 0;
        config.s.tail       = queue == (num_queues - 1);
        config.s.index      = queue;
        config.s.port       = port;
        config.s.queue      = base_queue + queue;

        config.s.static_p   = static_priority_base >= 0;
        config.s.static_q   = (int)queue <= static_priority_end;
        config.s.s_tail     = (int)queue == static_priority_end;
        /* Convert the priority into an enable bit field. Try to space the bits
            out evenly so the packet don't get grouped up */
        switch ((int)((priority) ? priority[queue] : 8))
        {
            case 0: config.s.qos_mask = 0x00; break;
            case 1: config.s.qos_mask = 0x01; break;
            case 2: config.s.qos_mask = 0x11; break;
            case 3: config.s.qos_mask = 0x49; break;
            case 4: config.s.qos_mask = 0x55; break;
            case 5: config.s.qos_mask = 0x57; break;
            case 6: config.s.qos_mask = 0x77; break;
            case 7: config.s.qos_mask = 0x7f; break;
            case 8: config.s.qos_mask = 0xff; break;
            case BDK_PKO_QUEUE_STATIC_PRIORITY:
                config.s.qos_mask = 0xff;
                break;
            default:
                bdk_error("bdk_pko_config_port: Invalid priority %llu\n", (unsigned long long)priority[queue]);
                config.s.qos_mask = 0xff;
                result_code = BDK_PKO_INVALID_PRIORITY;
                break;
        }

        if (port != BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID)
        {
            bdk_cmd_queue_result_t cmd_res = bdk_cmd_queue_initialize(BDK_CMD_QUEUE_PKO(base_queue + queue),
                                                                        BDK_FPA_OUTPUT_BUFFER_POOL,
                                                                        bdk_fpa_get_block_size(BDK_FPA_OUTPUT_BUFFER_POOL) - BDK_PKO_COMMAND_BUFFER_SIZE_ADJUST*8);
            if (cmd_res != BDK_CMD_QUEUE_SUCCESS)
            {
	        switch (cmd_res)
		{
		    case BDK_CMD_QUEUE_NO_MEMORY:
                        bdk_error("bdk_pko_config_port: Unable to allocate output buffer.\n");
                        return(BDK_PKO_NO_MEMORY);
		    case BDK_CMD_QUEUE_ALREADY_SETUP:
                        bdk_error("bdk_pko_config_port: Port already setup.\n");
                        return(BDK_PKO_PORT_ALREADY_SETUP);
		    case BDK_CMD_QUEUE_INVALID_PARAM:
		    default:
                        bdk_error("bdk_pko_config_port: Command queue initialization failed.\n");
                        return(BDK_PKO_CMD_QUEUE_INIT_ERROR);
		}
            }

            buf_ptr = (uint64_t*)bdk_cmd_queue_buffer(BDK_CMD_QUEUE_PKO(base_queue + queue));
            config.s.buf_ptr = bdk_ptr_to_phys(buf_ptr);
        }
        else
            config.s.buf_ptr = 0;

        BDK_SYNCW;

        BDK_CSR_WRITE(BDK_PKO_REG_QUEUE_PTRS1, config1.u64);
        BDK_CSR_WRITE(BDK_PKO_MEM_QUEUE_PTRS, config.u64);
    }

    return result_code;
}


/**
 * Rate limit a PKO port to a max packets/sec. This function is only
 * supported on CN51XX and higher, excluding CN58XX.
 *
 * @param port      Port to rate limit
 * @param packets_s Maximum packet/sec
 * @param burst     Maximum number of packets to burst in a row before rate
 *                  limiting cuts in.
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_rate_limit_packets(int port, int packets_s, int burst)
{
    bdk_pko_mem_port_rate0_t pko_mem_port_rate0;
    bdk_pko_mem_port_rate1_t pko_mem_port_rate1;

    pko_mem_port_rate0.u64 = 0;
    pko_mem_port_rate0.s.pid = port;
    pko_mem_port_rate0.s.rate_pkt = bdk_clock_get_rate(BDK_CLOCK_SCLK) / packets_s / 16;
    /* No cost per word since we are limited by packets/sec, not bits/sec */
    pko_mem_port_rate0.s.rate_word = 0;

    pko_mem_port_rate1.u64 = 0;
    pko_mem_port_rate1.s.pid = port;
    pko_mem_port_rate1.s.rate_lim = ((uint64_t)pko_mem_port_rate0.s.rate_pkt * burst) >> 8;

    BDK_CSR_WRITE(BDK_PKO_MEM_PORT_RATE0, pko_mem_port_rate0.u64);
    BDK_CSR_WRITE(BDK_PKO_MEM_PORT_RATE1, pko_mem_port_rate1.u64);
    return 0;
}


/**
 * Rate limit a PKO port to a max bits/sec. This function is only
 * supported on CN51XX and higher, excluding CN58XX.
 *
 * @param port   Port to rate limit
 * @param bits_s PKO rate limit in bits/sec
 * @param burst  Maximum number of bits to burst before rate
 *               limiting cuts in.
 *
 * @return Zero on success, negative on failure
 */
int bdk_pko_rate_limit_bits(int port, uint64_t bits_s, int burst)
{
    bdk_pko_mem_port_rate0_t pko_mem_port_rate0;
    bdk_pko_mem_port_rate1_t pko_mem_port_rate1;
    uint64_t clock_rate = bdk_clock_get_rate(BDK_CLOCK_SCLK);
    uint64_t tokens_per_bit = clock_rate*16 / bits_s;

    pko_mem_port_rate0.u64 = 0;
    pko_mem_port_rate0.s.pid = port;
    /* Each packet has a 12 bytes of interframe gap, an 8 byte preamble, and a
        4 byte CRC. These are not included in the per word count. Multiply
        by 8 to covert to bits and divide by 256 for limit granularity */
    pko_mem_port_rate0.s.rate_pkt = (12 + 8 + 4) * 8 * tokens_per_bit / 256;
    /* Each 8 byte word has 64bits */
    pko_mem_port_rate0.s.rate_word = 64 * tokens_per_bit;

    pko_mem_port_rate1.u64 = 0;
    pko_mem_port_rate1.s.pid = port;
    pko_mem_port_rate1.s.rate_lim = tokens_per_bit * burst / 256;

    BDK_CSR_WRITE(BDK_PKO_MEM_PORT_RATE0, pko_mem_port_rate0.u64);
    BDK_CSR_WRITE(BDK_PKO_MEM_PORT_RATE1, pko_mem_port_rate1.u64);
    return 0;
}


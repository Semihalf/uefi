/**
 * @file
 *
 * Interface to the hardware Packet Output unit.
 *
 * Starting with SDK 1.7.0, the PKO output functions now support
 * two types of locking. BDK_PKO_LOCK_ATOMIC_TAG continues to
 * function similarly to previous SDKs by using SSO atomic tags
 * to preserve ordering and exclusivity. As a new option, you
 * can now pass BDK_PKO_LOCK_CMD_QUEUE which uses a ll/sc
 * memory based locking instead. This locking has the advantage
 * of not affecting the tag state but doesn't preserve packet
 * ordering. BDK_PKO_LOCK_CMD_QUEUE is appropriate in most
 * generic code while BDK_PKO_LOCK_CMD_QUEUE should be used
 * with hand tuned fast path code.
 *
 * Some of other SDK differences visible to the command command
 * queuing:
 * - PKO indexes are no longer stored in the FAU. A large
 *   percentage of the FAU register block used to be tied up
 *   maintaining PKO queue pointers. These are now stored in a
 *   global named block.
 * - The PKO <b>use_locking</b> parameter can now have a global
 *   effect. Since all application use the same named block,
 *   queue locking correctly applies across all operating
 *   systems when using BDK_PKO_LOCK_CMD_QUEUE.
 * - PKO 3 word commands are now supported. Use
 *   bdk_pko_send_packet_finish3().
 *
 * <hr>$Revision: 49448 $<hr>
 */

/* Adjust the command buffer size by 1 word so that in the case of using only
** two word PKO commands no command words stradle buffers.  The useful values
** for this are 0 and 1. */
#define BDK_PKO_COMMAND_BUFFER_SIZE_ADJUST (1)

#define BDK_PKO_MAX_OUTPUT_QUEUES_STATIC 256
#define BDK_PKO_MAX_OUTPUT_QUEUES      256
#define BDK_PKO_NUM_OUTPUT_PORTS       ((OCTEON_IS_MODEL(OCTEON_CN63XX)) ? 44 : 40)
#define BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID 63 /* use this for queues that are not used */
#define BDK_PKO_QUEUE_STATIC_PRIORITY  9
#define BDK_PKO_ILLEGAL_QUEUE  0xFFFF

typedef enum
{
    BDK_PKO_SUCCESS,
    BDK_PKO_INVALID_PORT,
    BDK_PKO_INVALID_QUEUE,
    BDK_PKO_INVALID_PRIORITY,
    BDK_PKO_NO_MEMORY,
    BDK_PKO_PORT_ALREADY_SETUP,
    BDK_PKO_CMD_QUEUE_INIT_ERROR
} bdk_pko_status_t;

/**
 * This enumeration represents the differnet locking modes supported by PKO.
 */
typedef enum
{
    BDK_PKO_LOCK_NONE = 0,         /**< PKO doesn't do any locking. It is the responsibility
                                        of the application to make sure that no other core is
                                        accessing the same queue at the smae time */
    BDK_PKO_LOCK_ATOMIC_TAG = 1,   /**< PKO performs an atomic tagswitch to insure exclusive
                                        access to the output queue. This will maintain
                                        packet ordering on output */
    BDK_PKO_LOCK_CMD_QUEUE = 2,    /**< PKO uses the common command queue locks to insure
                                        exclusive access to the output queue. This is a memory
                                        based ll/sc. This is the most portable locking
                                        mechanism */
} bdk_pko_lock_t;

typedef struct
{
    uint32_t    packets;
    uint64_t    octets;
  uint64_t doorbell;
} bdk_pko_port_status_t;

/**
 * This structure defines the address to use on a packet enqueue
 */
typedef union
{
    uint64_t                u64;
    struct
    {
        bdk_mips_space_t   mem_space   : 2;    /**< Must BDK_IO_SEG */
        uint64_t            reserved    :13;    /**< Must be zero */
        uint64_t            is_io       : 1;    /**< Must be one */
        uint64_t            did         : 8;    /**< The ID of the device on the non-coherent bus */
        uint64_t            reserved2   : 4;    /**< Must be zero */
        uint64_t            reserved3   :18;    /**< Must be zero */
        uint64_t            port        : 6;    /**< The hardware likes to have the output port in addition to the output queue */
        uint64_t            queue       : 9;    /**< The output queue to send the packet to (0-127 are legal) */
        uint64_t            reserved4   : 3;    /**< Must be zero */
   } s;
} bdk_pko_doorbell_address_t;

/**
 * Structure of the first packet output command word.
 */
typedef union
{
    uint64_t                u64;
    struct
    {
        bdk_fau_op_size_t  size1       : 2; /**< The size of the reg1 operation - could be 8, 16, 32, or 64 bits */
        bdk_fau_op_size_t  size0       : 2; /**< The size of the reg0 operation - could be 8, 16, 32, or 64 bits */
        uint64_t            subone1     : 1; /**< If set, subtract 1, if clear, subtract packet size */
        uint64_t            reg1        :11; /**< The register, subtract will be done if reg1 is non-zero */
        uint64_t            subone0     : 1; /**< If set, subtract 1, if clear, subtract packet size */
        uint64_t            reg0        :11; /**< The register, subtract will be done if reg0 is non-zero */
        uint64_t            le          : 1; /**< When set, interpret segment pointer and segment bytes in little endian order */
        uint64_t            n2          : 1; /**< When set, packet data not allocated in L2 cache by PKO */
        uint64_t            wqp         : 1; /**< If set and rsp is set, word3 contains a pointer to a work queue entry */
        uint64_t            rsp         : 1; /**< If set, the hardware will send a response when done */
        uint64_t            gather      : 1; /**< If set, the supplied pkt_ptr is really a pointer to a list of pkt_ptr's */
        uint64_t            ipoffp1     : 7; /**< If ipoffp1 is non zero, (ipoffp1-1) is the number of bytes to IP header,
                                                and the hardware will calculate and insert the  UDP/TCP checksum */
        uint64_t            ignore_i    : 1; /**< If set, ignore the I bit (force to zero) from all pointer structures */
        uint64_t            dontfree    : 1; /**< If clear, the hardware will attempt to free the buffers containing the packet */
        uint64_t            segs        : 6; /**< The total number of segs in the packet, if gather set, also gather list length */
        uint64_t            total_bytes :16; /**< Including L2, but no trailing CRC */
    } s;
} bdk_pko_command_word0_t;


/**
 * Call before any other calls to initialize the packet
 * output system.
 */
extern void bdk_pko_initialize_global(void);
extern int bdk_pko_initialize_local(void);


/**
 * Enables the packet output hardware. It must already be
 * configured.
 */
extern void bdk_pko_enable(void);


/**
 * Disables the packet output. Does not affect any configuration.
 */
extern void bdk_pko_disable(void);


/**
 * Shutdown and free resources required by packet output.
 */

extern void bdk_pko_shutdown(void);

/**
 * Configure a output port and the associated queues for use.
 *
 * @param port       Port to configure.
 * @param base_queue First queue number to associate with this port.
 * @param num_queues Number of queues t oassociate with this port
 * @param priority   Array of priority levels for each queue. Values are
 *                   allowed to be 1-8. A value of 8 get 8 times the traffic
 *                   of a value of 1. There must be num_queues elements in the
 *                   array.
 */
extern bdk_pko_status_t bdk_pko_config_port(uint64_t port, uint64_t base_queue, uint64_t num_queues, const uint64_t priority[]);


/**
 * Ring the packet output doorbell. This tells the packet
 * output hardware that "len" command words have been added
 * to its pending list.  This command includes the required
 * BDK_SYNCW before the doorbell ring.
 *
 * @param port   Port the packet is for
 * @param queue  Queue the packet is for
 * @param len    Length of the command in 64 bit words
 */
static inline void bdk_pko_doorbell(uint64_t port, uint64_t queue, uint64_t len)
{
   bdk_pko_doorbell_address_t ptr;

   ptr.u64          = 0;
   ptr.s.mem_space  = BDK_IO_SEG;
   ptr.s.did        = BDK_OCT_DID_PKT_SEND;
   ptr.s.is_io      = 1;
   ptr.s.port       = port;
   ptr.s.queue      = queue;
   BDK_SYNCW;  /* Need to make sure output queue data is in DRAM before doorbell write */
   bdk_write64_uint64(ptr.u64, len);
}


/**
 * Prepare to send a packet.  This may initiate a tag switch to
 * get exclusive access to the output queue structure, and
 * performs other prep work for the packet send operation.
 *
 * bdk_pko_send_packet_finish() MUST be called after this function is called,
 * and must be called with the same port/queue/use_locking arguments.
 *
 * The use_locking parameter allows the caller to use three
 * possible locking modes.
 * - BDK_PKO_LOCK_NONE
 *      - PKO doesn't do any locking. It is the responsibility
 *          of the application to make sure that no other core
 *          is accessing the same queue at the smae time.
 * - BDK_PKO_LOCK_ATOMIC_TAG
 *      - PKO performs an atomic tagswitch to insure exclusive
 *          access to the output queue. This will maintain
 *          packet ordering on output.
 * - BDK_PKO_LOCK_CMD_QUEUE
 *      - PKO uses the common command queue locks to insure
 *          exclusive access to the output queue. This is a
 *          memory based ll/sc. This is the most portable
 *          locking mechanism.
 *
 * NOTE: If atomic locking is used, the SSO entry CANNOT be
 * descheduled, as it does not contain a valid WQE pointer.
 *
 * @param port   Port to send it on
 * @param queue  Queue to use
 * @param use_locking
 *               BDK_PKO_LOCK_NONE, BDK_PKO_LOCK_ATOMIC_TAG, or BDK_PKO_LOCK_CMD_QUEUE
 */
static inline void bdk_pko_send_packet_prepare(uint64_t port, uint64_t queue, bdk_pko_lock_t use_locking)
{
    if (use_locking == BDK_PKO_LOCK_ATOMIC_TAG)
    {
        /* Must do a full switch here to handle all cases.  We use a fake WQE pointer, as the SSO does
        ** not access this memory.  The WQE pointer and group are only used if this work is descheduled,
        ** which is not supported by the bdk_pko_send_packet_prepare/bdk_pko_send_packet_finish combination.
        ** Note that this is a special case in which these fake values can be used - this is not a general technique.
        */
        uint32_t tag = BDK_TAG_SW_BITS_INTERNAL << BDK_TAG_SW_SHIFT | BDK_TAG_SUBGROUP_PKO  << BDK_TAG_SUBGROUP_SHIFT | (BDK_TAG_SUBGROUP_MASK & queue);
        bdk_sso_tag_sw_full((bdk_wqe_t *)bdk_phys_to_ptr(0x80), tag, BDK_SSO_TAG_TYPE_ATOMIC, 0);
    }
}


/**
 * Complete packet output. bdk_pko_send_packet_prepare() must be called exactly once before this,
 * and the same parameters must be passed to both bdk_pko_send_packet_prepare() and
 * bdk_pko_send_packet_finish().
 *
 * @param port   Port to send it on
 * @param queue  Queue to use
 * @param pko_command
 *               PKO HW command word
 * @param packet Packet to send
 * @param use_locking
 *               BDK_PKO_LOCK_NONE, BDK_PKO_LOCK_ATOMIC_TAG, or BDK_PKO_LOCK_CMD_QUEUE
 *
 * @return returns BDK_PKO_SUCCESS on success, or error code on failure of output
 */
static inline bdk_pko_status_t bdk_pko_send_packet_finish(uint64_t port, uint64_t queue,
                                        bdk_pko_command_word0_t pko_command,
                                        bdk_buf_ptr_t packet, bdk_pko_lock_t use_locking)
{
    bdk_cmd_queue_result_t result;
    if (use_locking == BDK_PKO_LOCK_ATOMIC_TAG)
        bdk_sso_tag_sw_wait();
    result = bdk_cmd_queue_write2(BDK_CMD_QUEUE_PKO(queue),
                                   (use_locking == BDK_PKO_LOCK_CMD_QUEUE),
                                   pko_command.u64,
                                   packet.u64);
    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        bdk_pko_doorbell(port, queue, 2);
        return BDK_PKO_SUCCESS;
    }
    else if ((result == BDK_CMD_QUEUE_NO_MEMORY) || (result == BDK_CMD_QUEUE_FULL))
    {
        return BDK_PKO_NO_MEMORY;
    }
    else
    {
        return BDK_PKO_INVALID_QUEUE;
    }
}


/**
 * Complete packet output. bdk_pko_send_packet_prepare() must be called exactly once before this,
 * and the same parameters must be passed to both bdk_pko_send_packet_prepare() and
 * bdk_pko_send_packet_finish().
 *
 * @param port   Port to send it on
 * @param queue  Queue to use
 * @param pko_command
 *               PKO HW command word
 * @param packet Packet to send
 * @param addr   Plysical address of a work queue entry or physical address to zero on complete.
 * @param use_locking
 *               BDK_PKO_LOCK_NONE, BDK_PKO_LOCK_ATOMIC_TAG, or BDK_PKO_LOCK_CMD_QUEUE
 *
 * @return returns BDK_PKO_SUCCESS on success, or error code on failure of output
 */
static inline bdk_pko_status_t bdk_pko_send_packet_finish3(uint64_t port, uint64_t queue,
                                        bdk_pko_command_word0_t pko_command,
                                        bdk_buf_ptr_t packet, uint64_t addr, bdk_pko_lock_t use_locking)
{
    bdk_cmd_queue_result_t result;
    if (use_locking == BDK_PKO_LOCK_ATOMIC_TAG)
        bdk_sso_tag_sw_wait();
    result = bdk_cmd_queue_write3(BDK_CMD_QUEUE_PKO(queue),
                                   (use_locking == BDK_PKO_LOCK_CMD_QUEUE),
                                   pko_command.u64,
                                   packet.u64,
                                   addr);
    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        bdk_pko_doorbell(port, queue, 3);
        return BDK_PKO_SUCCESS;
    }
    else if ((result == BDK_CMD_QUEUE_NO_MEMORY) || (result == BDK_CMD_QUEUE_FULL))
    {
        return BDK_PKO_NO_MEMORY;
    }
    else
    {
        return BDK_PKO_INVALID_QUEUE;
    }
}

/**
 * Return the pko output queue associated with a port and a specific core.
 * In normal mode (PKO lockless operation is disabled), the value returned
 * is the base queue.
 *
 * @param port   Port number
 * @param core   Core to get queue for
 *
 * @return Core-specific output queue
 */
static inline int bdk_pko_get_base_queue_per_core(int port, int core)
{
    if (port < BDK_PKO_MAX_PORTS_INTERFACE0)
        return port * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 + core;
    else if (port >=16 && port < 16 + BDK_PKO_MAX_PORTS_INTERFACE1)
        return BDK_PKO_MAX_PORTS_INTERFACE0 * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 +
	       (port-16) * BDK_PKO_QUEUES_PER_PORT_INTERFACE1 + core;
    else if ((port >= 32) && (port < 36))
        return BDK_PKO_MAX_PORTS_INTERFACE0 * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 +
               BDK_PKO_MAX_PORTS_INTERFACE1 * BDK_PKO_QUEUES_PER_PORT_INTERFACE1 +
               (port-32) * BDK_PKO_QUEUES_PER_PORT_PCI;
    else if ((port >= 36) && (port < 40))
        return BDK_PKO_MAX_PORTS_INTERFACE0 * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 +
               BDK_PKO_MAX_PORTS_INTERFACE1 * BDK_PKO_QUEUES_PER_PORT_INTERFACE1 +
               4 * BDK_PKO_QUEUES_PER_PORT_PCI +
               (port-36) * BDK_PKO_QUEUES_PER_PORT_LOOP;
    else if ((port >= 40) && (port < 42))
        return BDK_PKO_MAX_PORTS_INTERFACE0 * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 +
               BDK_PKO_MAX_PORTS_INTERFACE1 * BDK_PKO_QUEUES_PER_PORT_INTERFACE1 +
               4 * BDK_PKO_QUEUES_PER_PORT_PCI +
               4 * BDK_PKO_QUEUES_PER_PORT_LOOP +
	       (port-40) * BDK_PKO_QUEUES_PER_PORT_SRIO0;
    else if ((port >= 42) && (port < 44))
        return BDK_PKO_MAX_PORTS_INTERFACE0 * BDK_PKO_QUEUES_PER_PORT_INTERFACE0 +
               BDK_PKO_MAX_PORTS_INTERFACE1 * BDK_PKO_QUEUES_PER_PORT_INTERFACE1 +
               4 * BDK_PKO_QUEUES_PER_PORT_PCI +
               4 * BDK_PKO_QUEUES_PER_PORT_LOOP +
	       2 * BDK_PKO_QUEUES_PER_PORT_SRIO0 +
	       (port-42) * BDK_PKO_QUEUES_PER_PORT_SRIO1;
    else
        /* Given the limit on the number of ports we can map to
         * BDK_MAX_OUTPUT_QUEUES_STATIC queues (currently 256,
         * divided among all cores), the remaining unmapped ports
         * are assigned an illegal queue number */
        return BDK_PKO_ILLEGAL_QUEUE;
}

/**
 * For a given port number, return the base pko output queue
 * for the port.
 *
 * @param port   Port number
 * @return Base output queue
 */
static inline int bdk_pko_get_base_queue(int port)
{
    return bdk_pko_get_base_queue_per_core(port, 0);
}

/**
 * For a given port number, return the number of pko output queues.
 *
 * @param port   Port number
 * @return Number of output queues
 */
static inline int bdk_pko_get_num_queues(int port)
{
    if (port < 16)
        return BDK_PKO_QUEUES_PER_PORT_INTERFACE0;
    else if (port<32)
        return BDK_PKO_QUEUES_PER_PORT_INTERFACE1;
    else if (port<36)
        return BDK_PKO_QUEUES_PER_PORT_PCI;
    else if (port<40)
        return BDK_PKO_QUEUES_PER_PORT_LOOP;
    else if (port<42)
        return BDK_PKO_QUEUES_PER_PORT_SRIO0;
    else if (port<44)
        return BDK_PKO_QUEUES_PER_PORT_SRIO1;
    else
        return 0;
}

/**
 * Get the status counters for a port.
 *
 * @param port_num Port number to get statistics for.
 * @param clear    Set to 1 to clear the counters after they are read
 * @param status   Where to put the results.
 */
static inline void bdk_pko_get_port_status(uint64_t port_num, uint64_t clear, bdk_pko_port_status_t *status)
{
    bdk_pko_reg_read_idx_t pko_reg_read_idx;
    bdk_pko_mem_count0_t pko_mem_count0;
    bdk_pko_mem_count1_t pko_mem_count1;

    pko_reg_read_idx.u64 = 0;
    pko_reg_read_idx.s.index = port_num;
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, pko_reg_read_idx.u64);

    pko_mem_count0.u64 = BDK_CSR_READ(BDK_PKO_MEM_COUNT0);
    status->packets = pko_mem_count0.s.count;
    if (clear)
    {
        pko_mem_count0.s.count = port_num;
        BDK_CSR_WRITE(BDK_PKO_MEM_COUNT0, pko_mem_count0.u64);
    }

    pko_mem_count1.u64 = BDK_CSR_READ(BDK_PKO_MEM_COUNT1);
    status->octets = pko_mem_count1.s.count;
    if (clear)
    {
        pko_mem_count1.s.count = port_num;
        BDK_CSR_WRITE(BDK_PKO_MEM_COUNT1, pko_mem_count1.u64);
    }

    bdk_pko_mem_debug8_t debug8;
    pko_reg_read_idx.s.index = bdk_pko_get_base_queue(port_num);
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, pko_reg_read_idx.u64);
    debug8.u64 = BDK_CSR_READ(BDK_PKO_MEM_DEBUG8);
    status->doorbell = debug8.cn56xx.doorbell;
}


/**
 * Rate limit a PKO port to a max packets/sec. This function is only
 * supported on CN57XX, CN56XX, CN55XX, and CN54XX.
 *
 * @param port      Port to rate limit
 * @param packets_s Maximum packet/sec
 * @param burst     Maximum number of packets to burst in a row before rate
 *                  limiting cuts in.
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_rate_limit_packets(int port, int packets_s, int burst);

/**
 * Rate limit a PKO port to a max bits/sec. This function is only
 * supported on CN57XX, CN56XX, CN55XX, and CN54XX.
 *
 * @param port   Port to rate limit
 * @param bits_s PKO rate limit in bits/sec
 * @param burst  Maximum number of bits to burst before rate
 *               limiting cuts in.
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_pko_rate_limit_bits(int port, uint64_t bits_s, int burst);


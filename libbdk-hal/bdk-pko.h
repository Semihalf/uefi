/**
 * @file
 *
 * Interface to the hardware Packet Output unit.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

#define BDK_PKO_MAX_OUTPUT_QUEUES      256
#define BDK_PKO_MEM_QUEUE_PTRS_ILLEGAL_PID 63 /* use this for queues that are not used */
#define BDK_PKO_QUEUE_STATIC_PRIORITY  9

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
    BDK_PKO_LOCK_CMD_QUEUE = 1,    /**< PKO uses the common command queue locks to insure
                                        exclusive access to the output queue. This is a memory
                                        based ll/sc. This is the most portable locking
                                        mechanism */
} bdk_pko_lock_t;

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
extern void bdk_pko_initialize(void);


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
 * Packet output.
 *
 * @param port   Port to send it on
 * @param queue  Queue to use
 * @param pko_command
 *               PKO HW command word
 * @param packet Packet to send
 * @param use_locking
 *               BDK_PKO_LOCK_NONE or BDK_PKO_LOCK_CMD_QUEUE
 *
 * @return returns BDK_PKO_SUCCESS on success, or error code on failure of output
 */
static inline bdk_pko_status_t bdk_pko_send_packet_finish(uint64_t port, uint64_t queue,
                                        bdk_pko_command_word0_t pko_command,
                                        bdk_buf_ptr_t packet, bdk_pko_lock_t use_locking)
{
    bdk_cmd_queue_result_t result;
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
 * Packet output.
 *
 * @param port   Port to send it on
 * @param queue  Queue to use
 * @param pko_command
 *               PKO HW command word
 * @param packet Packet to send
 * @param addr   Plysical address of a work queue entry or physical address to zero on complete.
 * @param use_locking
 *               BDK_PKO_LOCK_NONE or BDK_PKO_LOCK_CMD_QUEUE
 *
 * @return returns BDK_PKO_SUCCESS on success, or error code on failure of output
 */
static inline bdk_pko_status_t bdk_pko_send_packet_finish3(uint64_t port, uint64_t queue,
                                        bdk_pko_command_word0_t pko_command,
                                        bdk_buf_ptr_t packet, uint64_t addr, bdk_pko_lock_t use_locking)
{
    bdk_cmd_queue_result_t result;
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

/** @} */

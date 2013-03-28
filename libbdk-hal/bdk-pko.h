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

/**
 * Structure of the first packet output command word.
 */
typedef union
{
    uint64_t                u64;
    struct
    {
        bdk_fau_op_size_t   size1       : 2; /**< The size of the reg1 operation - could be 8, 16, 32, or 64 bits */
        bdk_fau_op_size_t   size0       : 2; /**< The size of the reg0 operation - could be 8, 16, 32, or 64 bits */
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


extern int __bdk_pko_alloc_pipe(bdk_node_t node, int num_pipes);
extern int __bdk_pko_alloc_engine(bdk_node_t node);
extern int __bdk_pko_alloc_port(bdk_node_t node);


/**
 * Ring the packet output doorbell. This tells the packet
 * output hardware that "len" command words have been added
 * to its pending list.  This command includes the required
 * BDK_SYNCW before the doorbell ring.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param port   Port the packet is for
 * @param queue  Queue the packet is for
 * @param len    Length of the command in 64 bit words
 */
static inline void bdk_pko_doorbell(bdk_node_t node, int port, int queue, int len)
{
    /**
     * This structure defines the address to use on a packet enqueue
     */
    typedef union
    {
        uint64_t                u64;
        struct
        {
            uint64_t            mem_space       : 2;    /**< Must BDK_IO_SEG */
            uint64_t            reserved_49_61  : 13;
            uint64_t            is_io           : 1;    /**< Must be one */
            uint64_t            did             : 8;    /**< The ID of the device on the non-coherent bus */
            uint64_t            reserved_21_39  : 19;
            uint64_t            port            : 9;    /**< The hardware likes to have the output port in addition to the output queue */
            uint64_t            queue           : 9;    /**< The output queue to send the packet to (0-127 are legal) */
            uint64_t            reserved_0_2    : 3;
       } s;
    } bdk_pko_doorbell_address_t;

    bdk_pko_doorbell_address_t ptr;

    ptr.u64          = 0;
    ptr.s.mem_space  = 2;
    ptr.s.did        = 0x52;
    ptr.s.is_io      = 1;
    ptr.s.port       = port;
    ptr.s.queue      = queue;
    BDK_SYNCW;  /* Need to make sure output queue data is in DRAM before doorbell write */
    bdk_write64_uint64(ptr.u64, len);
}

/** @} */

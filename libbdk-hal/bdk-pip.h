/**
 * @file
 *
 * Interface to the hardware Packet Input Processing unit.
 *
 * <hr>$Revision: 49504 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Enumeration representing the amount of packet processing
 * and validation performed by the input hardware.
 */
typedef enum
{
    BDK_PIP_PORT_CFG_MODE_NONE = 0ull,  /**< Packet input doesn't perform any
                                            processing of the input packet. */
    BDK_PIP_PORT_CFG_MODE_SKIPL2 = 1ull,/**< Full packet processing is performed
                                            with pointer starting at the L2
                                            (ethernet MAC) header. */
    BDK_PIP_PORT_CFG_MODE_SKIPIP = 2ull /**< Input packets are assumed to be IP.
                                            Results from non IP packets is
                                            undefined. Pointers reference the
                                            beginning of the IP header. */
} bdk_pip_port_parse_mode_t;

/**
 * Status statistics for a port
 */
typedef struct
{
    uint32_t    dropped_octets;         /**< Inbound octets marked to be dropped by the IPD */
    uint32_t    dropped_packets;        /**< Inbound packets marked to be dropped by the IPD */
    uint32_t    pci_raw_packets;        /**< RAW PCI Packets received by PIP per port */
    uint32_t    octets;                 /**< Number of octets processed by PIP */
    uint32_t    packets;                /**< Number of packets processed by PIP */
    uint32_t    multicast_packets;      /**< Number of indentified L2 multicast packets.
                                            Does not include broadcast packets.
                                            Only includes packets whose parse mode is
                                            SKIP_TO_L2 */
    uint32_t    broadcast_packets;      /**< Number of indentified L2 broadcast packets.
                                            Does not include multicast packets.
                                            Only includes packets whose parse mode is
                                            SKIP_TO_L2 */
    uint32_t    len_64_packets;         /**< Number of 64B packets */
    uint32_t    len_65_127_packets;     /**< Number of 65-127B packets */
    uint32_t    len_128_255_packets;    /**< Number of 128-255B packets */
    uint32_t    len_256_511_packets;    /**< Number of 256-511B packets */
    uint32_t    len_512_1023_packets;   /**< Number of 512-1023B packets */
    uint32_t    len_1024_1518_packets;  /**< Number of 1024-1518B packets */
    uint32_t    len_1519_max_packets;   /**< Number of 1519-max packets */
    uint32_t    fcs_align_err_packets;  /**< Number of packets with FCS or Align opcode errors */
    uint32_t    runt_packets;           /**< Number of packets with length < min */
    uint32_t    runt_crc_packets;       /**< Number of packets with length < min and FCS error */
    uint32_t    oversize_packets;       /**< Number of packets with length > max */
    uint32_t    oversize_crc_packets;   /**< Number of packets with length > max and FCS error */
    uint32_t    inb_packets;            /**< Number of packets without GMX/SPX/PCI errors received by PIP */
    uint64_t    inb_octets;             /**< Total number of octets from all packets received by PIP, including CRC */
    uint16_t    inb_errors;             /**< Number of packets with GMX/SPX/PCI errors received by PIP */
} bdk_pip_port_status_t;

/**
 * Get the status counters for a port.
 *
 * @param port_num Port number to get statistics for.
 * @param clear    Set to 1 to clear the counters after they are read
 * @param status   Where to put the results.
 */
extern void bdk_pip_get_port_status(uint64_t port_num, uint64_t clear, bdk_pip_port_status_t *status);

/** @} */

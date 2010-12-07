/**
 * @file
 *
 * Support functions for managing the MII management port
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

#define BDK_MGMT_PORT_NUM_PORTS        2       /* Right now we only have one mgmt port */
#define BDK_MGMT_PORT_NUM_TX_BUFFERS   16      /* Number of TX ring buffer entries and buffers */
#define BDK_MGMT_PORT_NUM_RX_BUFFERS   128     /* Number of RX ring buffer entries and buffers */
#define BDK_MGMT_PORT_TX_BUFFER_SIZE   12288   /* Size of each TX/RX buffer */
#define BDK_MGMT_PORT_RX_BUFFER_SIZE   1536    /* Size of each TX/RX buffer */

typedef enum
{
    BDK_MGMT_PORT_SUCCESS = 0,
    BDK_MGMT_PORT_NO_MEMORY = -1,
    BDK_MGMT_PORT_INVALID_PARAM = -2,
    BDK_MGMT_PORT_INIT_ERROR = -3,
} bdk_mgmt_port_result_t;


/* Enumeration of Net Device interface flags. */
typedef enum
{
    BDK_IFF_PROMISC = 0x100, 		/* receive all packets           */
    BDK_IFF_ALLMULTI = 0x200, 		/* receive all multicast packets */
} bdk_mgmt_port_netdevice_flags_t;

/**
 * Called to initialize a management port for use. Multiple calls
 * to this function accross applications is safe.
 *
 * @param port   Port to initialize
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_initialize(int port);

/**
 * Shutdown a management port. This currently disables packet IO
 * but leaves all hardware and buffers. Another application can then
 * call initialize() without redoing the hardware setup.
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_shutdown(int port);

/**
 * Enable packet IO on a management port
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_enable(int port);

/**
 * Disable packet IO on a management port
 *
 * @param port   Management port
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_disable(int port);

/**
 * Send a packet out the management port. The packet is copied so
 * the input buffer isn't used after this call.
 *
 * @param port       Management port
 * @param packet_len Length of the packet to send. It does not include the final CRC
 * @param buffer     Packet data
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_send(int port, int packet_len, const void *buffer);

/**
 * Receive a packet from the management port.
 *
 * @param port       Management port
 * @param buffer_len Size of the buffer to receive the packet into
 * @param buffer     Buffer to receive the packet into
 *
 * @return The size of the packet, or a negative erorr code on failure. Zero
 *         means that no packets were available.
 */
extern int bdk_mgmt_port_receive(int port, int buffer_len, void *buffer);

/**
 * Set the MAC address for a management port
 *
 * @param port   Management port
 * @param mac    New MAC address. The lower 6 bytes are used.
 *
 * @return BDK_MGMT_PORT_SUCCESS or an error code
 */
extern bdk_mgmt_port_result_t bdk_mgmt_port_set_mac(int port, uint64_t mac);

/**
 * Get the MAC address for a management port
 *
 * @param port   Management port
 *
 * @return MAC address
 */
extern uint64_t bdk_mgmt_port_get_mac(int port);
#define BDK_MGMT_PORT_GET_MAC_ERROR ((unsigned long long)-2LL)

/**
 * Set the multicast list.
 *
 * @param port   Management port
 * @param flags  Interface flags
 *
 * @return
 */
extern void bdk_mgmt_port_set_multicast_list(int port, int flags);

/**
 * Set the maximum packet allowed in. Size is specified
 * including L2 but without FCS. A normal MTU would corespond
 * to 1514 assuming the standard 14 byte L2 header.
 *
 * @param port   Management port
 * @param size_without_fcs
 *               Size in bytes without FCS
 */
extern void bdk_mgmt_port_set_max_packet_size(int port, int size_without_fcs);

/**
 * Return the link state of an RGMII/MII port as returned by
 * auto negotiation. The result of this function may not match
 * Octeon's link config if auto negotiation has changed since
 * the last call to __bdk_mgmt_port_link_set().
 *
 * @param port     The RGMII/MII interface port to query
 *
 * @return Link state
 */
extern bdk_helper_link_info_t bdk_mgmt_port_link_get(int port);

/**
 * Configure RGMII/MII port for the specified link state. This
 * function does not influence auto negotiation at the PHY level.
 *
 * @param port      RGMII/MII interface port
 * @param link_info The new link state
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_mgmt_port_link_set(int port, bdk_helper_link_info_t link_info);

/** @} */

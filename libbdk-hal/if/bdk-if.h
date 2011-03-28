/**
 * @file
 *
 * Interface to external interfaces (SGMII, XAUI, SRIO, etc)
 *
 * <hr>$Revision: 45089 $<hr>
 *
 * @defgroup packetio Packet Input / Output
 * @addtogroup packetio
 * @{
 */

/**
 * Enumeration of different interfaces in Octeon.
 */
typedef enum
{
    BDK_IF_SGMII,
    BDK_IF_XAUI,
    BDK_IF_DPI,
    BDK_IF_LOOP,
    BDK_IF_SRIO,
    BDK_IF_MGMT,
    BDK_IF_ILK,
    __BDK_IF_LAST
} bdk_if_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    reserved2   : 40;
        int         speed       : 16;
        int         lanes       : 4;
        int         reserved    : 2;
        int         full_duplex : 1;
        int         up          : 1;
    } s;
} bdk_if_link_t;

typedef struct
{
    uint64_t    dropped_octets;
    uint64_t    dropped_packets;
    uint64_t    octets;
    uint64_t    packets;
    uint64_t    errors;
} __bdk_if_stats_t;

typedef struct
{
    __bdk_if_stats_t rx;
    __bdk_if_stats_t tx;
} bdk_if_stats_t;

typedef struct __bdk_if_port
{
    bdk_if_t    iftype      : 8;
    int         interface   : 8;
    int         index       : 8;
    int         pknd        : 8;
    int         ipd_port    : 16;
    int         pko_port    : 16;
    int         pko_queue   : 8;
    int         has_fcs;
    void *      priv;
    bdk_cmd_queue_state_t cmd_queue;
    bdk_if_stats_t stats;
    bdk_if_link_t link_info;
    struct __bdk_if_port *next;
} __bdk_if_port_t;

typedef __bdk_if_port_t *bdk_if_handle_t;

typedef struct
{
    bdk_if_handle_t if_handle;
    int             length;
    int             segments;
    int             rx_error; /* FIXME: Should be an enum */
    bdk_buf_ptr_t   packet;
} bdk_if_packet_t;

typedef struct
{
    const char *name;
    int (*if_num_interfaces)(void); /* Returns the number of interfaces possible on this chip */
    int (*if_num_ports)(int interface); /* For given interface, returns the number of ports on it */
    int (*if_probe)(bdk_if_handle_t handle); /* Called to assign IPD and PKO ports. Does nothing if they aren't needed */
    int (*if_init)(bdk_if_handle_t handle); /* One time hardware init */
    int (*if_enable)(bdk_if_handle_t handle); /* Enable packet IO. must be called after init */
    int (*if_disable)(bdk_if_handle_t handle); /* Disable packet IO */
    bdk_if_link_t (*if_link_get)(bdk_if_handle_t handle); /* Get link speed and state */
    void (*if_link_set)(bdk_if_handle_t handle, bdk_if_link_t link_info); /* Set link speed and state */
    const bdk_if_stats_t *(*if_get_stats)(bdk_if_handle_t handle); /* Get stats. Not needed if using IPD/PKO */
    int (*if_transmit)(bdk_if_handle_t handle, bdk_if_packet_t *packet); /* TX a packet. Not needed if using PKO */
    int (*if_receive)(bdk_if_handle_t handle, bdk_if_packet_t *packet); /* RX a packet. not needed if using IPD */
} __bdk_if_ops_t;

extern int bdk_if_init(void);
extern int bdk_if_num_interfaces(bdk_if_t iftype);
extern int bdk_if_num_ports(bdk_if_t iftype, int interface);
extern bdk_if_handle_t bdk_if_next_port(bdk_if_handle_t handle);

extern int bdk_if_enable(bdk_if_handle_t handle);
extern int bdk_if_disable(bdk_if_handle_t handle);

extern const char *bdk_if_name(bdk_if_handle_t handle);
extern bdk_if_link_t bdk_if_link_get(bdk_if_handle_t handle);
extern bdk_if_link_t bdk_if_link_autoconf(bdk_if_handle_t handle);
extern const bdk_if_stats_t *bdk_if_get_stats(bdk_if_handle_t handle);
extern bdk_if_link_t __bdk_if_phy_get(int phy_addr);

extern int bdk_if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet);
extern int bdk_if_receive(bdk_if_packet_t *packet);
extern void bdk_if_free(bdk_if_packet_t *packet);

extern int __bdk_if_get_gmx_block(bdk_if_handle_t handle);
extern int __bdk_if_get_gmx_index(bdk_if_handle_t handle);

/**
 * Get interface type. Use this function instead of accessing the handle
 * directly. The handle is considered private and may change.
 *
 * @param handle Handle of port to get info for
 *
 * @return Interface type
 */
static inline bdk_if_t bdk_if_get_type(bdk_if_handle_t handle)
{
    return handle->iftype;
}

/**
 * Get the IPD index for the tagging information of this port.
 * Use this function instead of accessing the handle directly.
 * The handle is considered private and may change.
 *
 * @param handle Handle of port to get info for
 *
 * @return IPD index for tagging information
 */
static inline int bdk_if_get_pknd(bdk_if_handle_t handle)
{
    return handle->pknd;
}

/** @} */

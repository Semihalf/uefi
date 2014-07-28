/**
 * @file
 *
 * Interface to external interfaces (SGMII, XAUI, etc)
 *
 * <hr>$Revision: 45089 $<hr>
 *
 * @defgroup packetio Packet Input / Output
 * @addtogroup packetio
 * @{
 */

/* CVMSEG location to use for async work */
#define BDK_IF_SCR_WORK 0
#define BDK_IF_MAX_GATHER 16 /* CN88XX RX support 1 + 15 */

#define BDK_IF_PHY_FIXED_1GB 0x1000
#define BDK_IF_PHY_FIXED_100MB 0x1001

/**
 * Enumeration of different interfaces in Octeon.
 */
typedef enum
{
    BDK_IF_BGX,
    __BDK_IF_LAST
} bdk_if_t;

typedef enum
{
    BDK_IF_FLAGS_HAS_FCS = 1,
    BDK_IF_FLAGS_ENABLED = 2,
} bdk_if_flags_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    reserved2   : 32;
        unsigned    speed       : 24;
        unsigned    lanes       : 6;
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
    bdk_node_t  node        : 8;
    int         interface   : 8;
    int         index       : 8;    /* ILK can have 256 channels on CN78XX */
    int         pknd        : 8;    /* 0-63 on CN78XX, same as ipd_port on others */
    int         ipd_port    : 16;   /* Sparse 0-4095 */
    int         pko_port    : 8;    /* CN78XX uses this as PKO port queue (L1) */
    int         pko_queue   : 16;   /* CN78XX has 1024, CN6XXX has 256 */
    int         aura        : 16;   /* CN78XX has 1024, CN6XXX doesn't use */
    bdk_if_flags_t flags    : 8;
    uint64_t    pko_depth_addr;     /* Physical address of pko_depth, Converting CKSEG0 addresses is slow, so we cache it here */
    int64_t     pko_depth;          /* Tracks the PKO DQ depth on 78, decremented by hardware. This is a workaround for slow PKO performance */
    void *      receiver;           /* This is a bdk_if_packet_receiver_t */
    void *      receiver_arg;
    void *      priv;
    bdk_if_stats_t stats;
    bdk_if_link_t link_info;
    char        name[16];
    struct __bdk_if_port *next;
    struct __bdk_if_port *poll_next;
} __bdk_if_port_t;

typedef __bdk_if_port_t *bdk_if_handle_t;

typedef union
{
    uint64_t u;
    struct
    {
        uint64_t size : 16;
        uint64_t address : 48;
    } s;
} bdk_packet_ptr_t;

typedef struct
{
    bdk_if_handle_t if_handle;
    int             length;
    int             aura;
    int             segments;
    int             rx_error;
    bdk_packet_ptr_t packet[BDK_IF_MAX_GATHER];
} bdk_if_packet_t;

typedef enum
{
    BDK_IF_LOOPBACK_NONE = 0,
    BDK_IF_LOOPBACK_INTERNAL = 1,
    BDK_IF_LOOPBACK_EXTERNAL = 2,
    BDK_IF_LOOPBACK_INTERNAL_EXTERNAL = 3,
} bdk_if_loopback_t;

typedef int (*bdk_if_packet_receiver_t)(bdk_if_packet_t *packet, void *arg);

typedef struct
{
    int (*if_num_interfaces)(bdk_node_t node); /* Returns the number of interfaces possible on this chip */
    int (*if_num_ports)(bdk_node_t node, int interface); /* For given interface, returns the number of ports on it */
    int (*if_probe)(bdk_if_handle_t handle); /* Called to assign IPD and PKO ports. Does nothing if they aren't needed */
    int (*if_init)(bdk_if_handle_t handle); /* One time hardware init */
    int (*if_enable)(bdk_if_handle_t handle); /* Enable packet IO. must be called after init */
    int (*if_disable)(bdk_if_handle_t handle); /* Disable packet IO */
    bdk_if_link_t (*if_link_get)(bdk_if_handle_t handle); /* Get link speed and state */
    void (*if_link_set)(bdk_if_handle_t handle, bdk_if_link_t link_info); /* Set link speed and state */
    const bdk_if_stats_t *(*if_get_stats)(bdk_if_handle_t handle); /* Get stats. Not needed if using IPD/PKO */
    int (*if_transmit)(bdk_if_handle_t handle, bdk_if_packet_t *packet); /* TX a packet. Not needed if using PKO */
    int (*if_receive)(bdk_if_handle_t handle, bdk_if_packet_t *packet); /* RX a packet. not needed if using IPD */
    int (*if_loopback)(bdk_if_handle_t handle, bdk_if_loopback_t loopback); /* Configure loopback for the port */
    int (*if_get_queue_depth)(bdk_if_handle_t handle); /* Get the current TX queue depth */
} __bdk_if_ops_t;

typedef struct
{
    int (*pki_global_init)(bdk_node_t node);
    int (*pki_port_init)(bdk_if_handle_t handle);
    int (*pki_enable)(bdk_node_t node);
    int (*pko_global_init)(bdk_node_t node);
    int (*pko_port_init)(bdk_if_handle_t handle);
    int (*pko_enable)(bdk_node_t node);
    int (*pko_get_queue_depth)(bdk_if_handle_t handle); /* Get the current TX queue depth */
    int (*sso_init)(bdk_node_t node);
    int (*sso_wqe_to_packet)(const void *wqe, bdk_if_packet_t *packet);
    int (*pko_transmit)(bdk_if_handle_t handle, bdk_if_packet_t *packet);
    int (*packet_alloc)(bdk_if_packet_t *packet, int length);
    void (*packet_free)(bdk_if_packet_t *packet);
    void (*packet_read)(bdk_if_packet_t *packet, int location, int length, void *data);
    void (*packet_write)(bdk_if_packet_t *packet, int location, int length, const void *data);
} __bdk_if_global_ops_t;

extern int bdk_if_is_configured(void);
extern int bdk_if_dispatch(void) BDK_WEAK;
extern int bdk_if_num_interfaces(bdk_node_t node, bdk_if_t iftype);
extern int bdk_if_num_ports(bdk_node_t node, bdk_if_t iftype, int interface);
extern bdk_if_handle_t bdk_if_next_port(bdk_if_handle_t handle);

extern int bdk_if_enable(bdk_if_handle_t handle);
extern int bdk_if_disable(bdk_if_handle_t handle);
extern int bdk_if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback);

extern const char *bdk_if_name(bdk_if_handle_t handle);
extern bdk_if_link_t bdk_if_link_get(bdk_if_handle_t handle);
extern bdk_if_link_t bdk_if_link_autoconf(bdk_if_handle_t handle);
extern const bdk_if_stats_t *bdk_if_get_stats(bdk_if_handle_t handle);
extern bdk_if_link_t __bdk_if_phy_get(int phy_addr);
extern int bdk_if_get_queue_depth(bdk_if_handle_t handle);

extern int bdk_if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet);
extern void bdk_if_register_for_packets(bdk_if_handle_t handle, bdk_if_packet_receiver_t receiver, void *arg);
extern int bdk_if_alloc(bdk_if_packet_t *packet, int length);
extern void bdk_if_free(bdk_if_packet_t *packet);
extern void bdk_if_packet_read(bdk_if_packet_t *packet, int location, int length, void *data);
extern void bdk_if_packet_write(bdk_if_packet_t *packet, int location, int length, const void *data);

extern int __bdk_if_get_gmx_block(bdk_if_handle_t handle);
extern int __bdk_if_get_gmx_index(bdk_if_handle_t handle);
extern uint64_t bdk_update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size);

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

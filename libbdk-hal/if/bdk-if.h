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

#define BDK_IF_MAX_GATHER 12 /* CN88XX RX supports 12 at most */

#define BDK_IF_PHY_FIXED_1GB 0x1000
#define BDK_IF_PHY_FIXED_100MB 0x1001

/**
 * Enumeration of different interfaces.
 */
typedef enum
{
    BDK_IF_BGX,
    BDK_IF_PCIE,
    BDK_IF_FAKE,
    __BDK_IF_LAST
} bdk_if_t;

typedef enum
{
    BDK_IF_FLAGS_HAS_FCS = 1, /* The device adds and removes an FCS. On thunder we assume the hardware strips FCS */
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
    bdk_if_flags_t flags    : 8;
    int         pknd        : 8;
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

/**
 * Format of each gather/segment entry in a packet. This is unrelated to
 * the underlying hardware format, but is designed to be simple to munge
 * into a hardware format. Note that only 48 bits are stored for the
 * address. This address is a physical address not mean for SMMU translation.
 */
typedef union
{
    uint64_t u;
    struct
    {
#if __BYTE_ORDER == __BIG_ENDIAN
        uint64_t size : 16;
        uint64_t address : 48;
#else
        uint64_t address : 48;
        uint64_t size : 16;
#endif
    } s;
} bdk_packet_ptr_t;

/**
 * The packet format for the BDK. This structure is designed to be exactly
 * one cache line to promote alignment and avoid false aliasing. Note that the
 * packet structure is independent from the packet data and can have a shorter
 * lifespan. The packet structure is normally on the stack and disappears on
 * stack unwind. Code requiring its data to stick around needs to copy it, but
 * not the data in the gather list.
 */
typedef struct
{
    bdk_if_handle_t if_handle;  /* Handle to interface this packet was received on */
    int             length;     /* Length of the packet in bytes */
    int             segments;   /* Number of segments the packet is spread over */
    int             rx_error;   /* Error number when packet was receive or zero for no error */
    int             reserved1;  /* Reserved for future use */
    uint64_t        reserved2;  /* Reserved for future use */
    bdk_packet_ptr_t packet[BDK_IF_MAX_GATHER]; /* List of segements. Each has a physical address and length */
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
    int (*init)(void);
    uint64_t (*alloc)(int length);
    void (*free)(uint64_t address, int length);
} __bdk_if_global_ops_t;

extern int bdk_if_is_configured(void);
extern int bdk_if_dispatch(void) BDK_WEAK;
extern void bdk_if_dispatch_packet(bdk_if_packet_t *packet);
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
extern void bdk_if_packet_read(const bdk_if_packet_t *packet, int location, int length, void *data);
extern void bdk_if_packet_write(bdk_if_packet_t *packet, int location, int length, const void *data);
extern int bdk_if_copy(bdk_if_packet_t *packet, const bdk_if_packet_t *old_packet);

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

/** @} */

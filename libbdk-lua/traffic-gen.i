#ifdef SWIG
%module bdktrafficgen
%{
#include <bdk.h>
#include <stdbool.h>
#include "traffic-gen.i"
/* Goofy macro to redefine LUA_GLOBALSINDEX as a sequence of comamnds that gets the global table  */
#define LUA_GLOBALSINDEX LUA_REGISTRYINDEX); lua_pop(L, 1); lua_pushnumber(L, LUA_RIDX_GLOBALS); lua_gettable(L, LUA_REGISTRYINDEX
%}

typedef unsigned long   uint64_t;
typedef long            int64_t;
typedef unsigned int    uint32_t;
typedef int             int32_t;
typedef unsigned short  uint16_t;
typedef short           int16_t;
typedef unsigned char   uint8_t;
typedef char            int8_t;

%rename("%(strip:[trafficgen_])s") "";
#endif

typedef struct
{
    uint64_t    tx_packets;
    uint64_t    tx_octets;
    uint64_t    tx_bits;
    uint64_t    tx_arp_requests;
    uint64_t    tx_arp_replies;

    uint64_t    rx_dropped_octets;  /* Inbound octets marked to be dropped by the IPD */
    uint64_t    rx_dropped_packets; /* Inbound packets marked to be dropped by the IPD */
    uint64_t    rx_octets;          /* Number of octets processed by PIP */
    uint64_t    rx_packets;         /* Number of packets processed by PIP */
    uint64_t    rx_multicast;       /* Number of indentified L2 multicast packets. */
    uint64_t    rx_broadcast;       /* Number of indentified L2 broadcast packets. */
    uint64_t    rx_len_64;          /* Number of 64B packets */
    uint64_t    rx_len_65_127;      /* Number of 65-127B packets */
    uint64_t    rx_len_128_255;     /* Number of 128-255B packets */
    uint64_t    rx_len_256_511;     /* Number of 256-511B packets */
    uint64_t    rx_len_512_1023;    /* Number of 512-1023B packets */
    uint64_t    rx_len_1024_1518;   /* Number of 1024-1518B packets */
    uint64_t    rx_len_1519_max;    /* Number of 1519-max packets */
    uint64_t    rx_fcs_align_err;   /* Number of packets with FCS or Align opcode errors */
    uint64_t    rx_runt;            /* Number of packets with length < min */
    uint64_t    rx_runt_crc;        /* Number of packets with length < min and FCS error */
    uint64_t    rx_oversize;        /* Number of packets with length > max */
    uint64_t    rx_oversize_crc;    /* Number of packets with length > max and FCS error */
    uint64_t    rx_errors;          /* Number of packets with GMX/SPX/PCI errors received by PIP */
    uint64_t    rx_backpressure;
    uint64_t    rx_bits;
    uint64_t    rx_arp_requests;
    uint64_t    rx_arp_replies;
    uint64_t    rx_validation_errors;
    uint64_t    rx_wqe_errors[256];
} trafficgen_port_stats_t;

typedef enum {
    PACKET_TYPE_IPV4_UDP,
    PACKET_TYPE_IPV6_UDP,
    PACKET_TYPE_IPV4_TCP,
    PACKET_TYPE_IPV6_TCP,
    PACKET_TYPE_802_3_PAUSE,
    PACKET_TYPE_CBFC_PAUSE,
    PACKET_TYPE_CJPAT,
    PACKET_TYPE_HELP    /* best to keep this last */
} trafficgen_packet_type_t;

typedef enum {
    DATA_TYPE_ABC=0,
    DATA_TYPE_ZERO,
    DATA_TYPE_ONE,
    DATA_TYPE_INC,
    DATA_TYPE_DEC,
    DATA_TYPE_RAND,
    DATA_TYPE_HELP      /* best to keep this last */
} trafficgen_payload_t;

typedef struct
{
    bdk_helper_interface_mode_t imode;
    uint64_t                output_percent_x1000;   /* percent*1000 */
    uint64_t                output_cycle_gap;
    uint64_t                output_packet_size;
    bool                    output_enable;
    uint64_t                output_count;
    trafficgen_packet_type_t output_packet_type;
    trafficgen_payload_t    output_packet_payload;
    bool                    output_arp_reply_enable;
    uint64_t                src_mac;    /* MACs are stored so a printf in hex will show them */
    int32_t                 src_mac_inc;
    uint64_t                src_mac_min;
    uint64_t                src_mac_max;
    uint64_t                dest_mac;
    int32_t                 dest_mac_inc;
    uint64_t                dest_mac_min;
    uint64_t                dest_mac_max;
    uint64_t                vlan_size;
    uint8_t                 vlan[8];
    uint32_t                src_ip;
    int32_t                 src_ip_inc;
    uint32_t                src_ip_min;
    uint32_t                src_ip_max;
    uint32_t                dest_ip;
    int32_t                 dest_ip_inc;
    uint32_t                dest_ip_min;
    uint32_t                dest_ip_max;
    uint32_t                ip_tos;
    uint16_t                src_port;
    int16_t                 src_port_inc;
    uint16_t                src_port_min;
    uint16_t                src_port_max;
    uint16_t                dest_port;
    int16_t                 dest_port_inc;
    uint16_t                dest_port_min;
    uint16_t                dest_port_max;
    bool                    do_checksum;
    int                     bridge_port;
    bool                    display_packet;
    bool                    input_arp_reply_enable;
    bool                    input_arp_request_enable;
    bool                    promisc;  /* Promiscuous mode (default to 1) */
    bool                    validate;
    bool                    respect_backpressure;
    int                     higig; /* Number of HiGig bytes to include before L2 */
    bdk_higig_header_t      higig_header; /* The HiGig header included if "higig" is set */
    bdk_srio_tx_message_header_t srio;
} trafficgen_port_setup_t;

typedef struct
{
    int port;
    trafficgen_port_setup_t setup;
    trafficgen_port_stats_t stats;
    struct {
        bdk_spinlock_t lock;
        bdk_pip_port_status_t pip_stats;
        bdk_pko_port_status_t pko_stats;
    } priv;
} trafficgen_port_info_t;

typedef struct
{
    trafficgen_port_info_t *list[BDK_PIP_NUM_INPUT_PORTS+1];
} trafficgen_port_set_t;

trafficgen_port_info_t *trafficgen_port_get(int index);
void trafficgen_port_add(trafficgen_port_set_t *set, trafficgen_port_info_t *pinfo);

int trafficgen_do_clear(const trafficgen_port_set_t *range);
int trafficgen_do_reset(const trafficgen_port_set_t *range);
int trafficgen_do_update(void);

int trafficgen_do_transmit(const trafficgen_port_set_t *range);
int trafficgen_is_transmitting(const trafficgen_port_set_t *range);


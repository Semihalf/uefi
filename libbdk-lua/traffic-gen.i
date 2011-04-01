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
    uint64_t    tx_packets_total;
    uint64_t    tx_octets_total;
    uint64_t    tx_bits;

    uint64_t    rx_packets;
    uint64_t    rx_octets;
    uint64_t    rx_packets_total;
    uint64_t    rx_octets_total;
    uint64_t    rx_dropped_octets;
    uint64_t    rx_dropped_packets;
    uint64_t    rx_errors;
    uint64_t    rx_bits;
    uint64_t    rx_backpressure;
    uint64_t    rx_validation_errors;
    //uint64_t    rx_wqe_errors[256];
} trafficgen_port_stats_t;

typedef struct
{
    int                     output_rate;
    bool                    output_rate_is_mbps;
    bool                    output_enable;
    int                     output_packet_size;
    uint64_t                output_count;
    uint64_t                src_mac;    /* MACs are stored so a printf in hex will show them */
    uint64_t                dest_mac;
    uint32_t                src_ip;
    uint32_t                dest_ip;
    uint32_t                ip_tos;
    uint16_t                src_port;
    uint16_t                dest_port;
    bool                    do_checksum;
    bool                    display_packet;
    bool                    validate;
    bdk_srio_tx_message_header_t srio;
} trafficgen_port_setup_t;

typedef struct
{
    char name[8];
    trafficgen_port_setup_t setup;
    trafficgen_port_stats_t stats;
    void *priv;
} trafficgen_port_info_t;

typedef struct
{
    trafficgen_port_info_t *list[64];
} trafficgen_port_set_t;

trafficgen_port_info_t *trafficgen_port_get(int index);
void trafficgen_port_add(trafficgen_port_set_t *set, trafficgen_port_info_t *pinfo);

int trafficgen_do_clear(const trafficgen_port_set_t *range);
int trafficgen_do_reset(const trafficgen_port_set_t *range);
int trafficgen_do_update(bool do_clear);

int trafficgen_do_transmit(const trafficgen_port_set_t *range);
bool trafficgen_is_transmitting(const trafficgen_port_set_t *range);


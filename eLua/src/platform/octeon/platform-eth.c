#include <bdk.h>
#include <stdio.h>
#include "platform.h"
#include "elua_uip.h"
#include "uip.h"

#define ETH_TIMER 0
#define ETH_PORT 0

static u32 last_poll;

void platform_eth_initialize(void)
{
    if (bdk_mgmt_port_initialize(ETH_PORT))
        printf("ERROR: bdk_mgmt_port_initialize() failed\n");

    uint64_t mac = bdk_mgmt_port_get_mac(ETH_PORT);
    struct uip_eth_addr macaddr;
    macaddr.addr[0] = mac >> 40;
    macaddr.addr[1] = mac >> 32;
    macaddr.addr[2] = mac >> 24;
    macaddr.addr[3] = mac >> 16;
    macaddr.addr[4] = mac >> 8;
    macaddr.addr[5] = mac >> 0;
    elua_uip_init(&macaddr);

    bdk_mgmt_port_enable(ETH_PORT);
}

void platform_eth_send_packet( const void* src, u32 size )
{
    if (bdk_mgmt_port_send(ETH_PORT, size, src))
        printf("ERROR: bdk_mgmt_port_send() failed");
}

u32 platform_eth_get_packet_nb( void* buf, u32 maxlen )
{
    int bytes = bdk_mgmt_port_receive(ETH_PORT, maxlen, buf);
    if (bytes < 0)
        return 0;
    return bytes;
}

void platform_eth_force_interrupt()
{
    int status = platform_cpu_set_global_interrupts(PLATFORM_CPU_DISABLE);
    elua_uip_mainloop();
    platform_cpu_set_global_interrupts(status);
    last_poll = platform_s_timer_op(ETH_TIMER, PLATFORM_TIMER_OP_READ, 0);
}

u32 platform_eth_get_elapsed_time()
{
    u32 time = platform_s_timer_op(ETH_TIMER, PLATFORM_TIMER_OP_READ, 0);
    time = platform_timer_get_diff_us(ETH_TIMER, time, last_poll) / 1000;
    return time;
}

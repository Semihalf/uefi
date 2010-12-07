#include <bdk.h>

static int if_init(bdk_if_handle_t handle)
{
    return -1;
}

static int if_num_interfaces(void)
{
    return 0;
}

static int if_num_ports(int interface)
{
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    return -1;
}

static int if_disable(bdk_if_handle_t handle)
{
    return -1;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    bdk_if_link_t result;
    result.u64 = 0;
    return result;
}

static bdk_if_link_t if_link_autoconf(bdk_if_handle_t handle)
{
    return if_link_get(handle);
}

static int if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return -1;
}

static int if_receive(bdk_if_packet_t *packet)
{
    return -1;
}

__bdk_if_ops_t __bdk_if_ops_mgmt = {
    .if_init = if_init,
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_autoconf = if_link_autoconf,
    .if_transmit = if_transmit,
    .if_receive = if_receive,
};


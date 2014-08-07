#include <bdk.h>

/* This file is suppose to implement packet IO over PCIe. Not implemented yet */

static int if_num_interfaces(bdk_node_t node)
{
    return 0;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    return 0;
}

static int if_probe(bdk_if_handle_t handle)
{
    return -1;
}

static int if_init(bdk_if_handle_t handle)
{
    return -1;
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

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
}

static int if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return -1;
}

static int if_receive(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return -1;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    return -1;
}

static int if_get_queue_depth(bdk_if_handle_t handle)
{
    return 0;
}

static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    return &handle->stats;
}

const __bdk_if_ops_t __bdk_if_ops_pcie = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_set = if_link_set,
    .if_transmit = if_transmit,
    .if_receive = if_receive,
    .if_loopback = if_loopback,
    .if_get_queue_depth = if_get_queue_depth,
    .if_get_stats = if_get_stats,
};


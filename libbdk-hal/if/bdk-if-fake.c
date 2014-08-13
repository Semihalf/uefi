#include <bdk.h>

/* This file implements a fake ethernet device that loops to itself. It allows
   testing the BDK code without ties to real hardware */

/* This interface puts packets in a fixed size TX fifo, defined here. It is a
   circular list with a head and tail index. Transmit will fail if the fifo
   is full */
#define MAX_QUEUE 32
typedef struct
{
    bdk_spinlock_t lock;
    int next_rx;
    int tx_free;
    bdk_if_packet_t queue[MAX_QUEUE];
} priv_t;


static int if_num_interfaces(bdk_node_t node)
{
    return 4;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    /* Only support one port per interface to make naming easier */
    return 1;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be something that might be meaningful to the user */
    const char *name_format;
    if (bdk_numa_is_only_one())
        name_format = "FAKE%d";
    else
        name_format = "N%d.FAKE%d";

    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), name_format, handle->interface);
    else
        snprintf(handle->name, sizeof(handle->name), name_format, handle->node, handle->interface);
    handle->name[sizeof(handle->name)-1] = 0;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    handle->priv = calloc(1, sizeof(priv_t));
    if (!handle->priv)
    {
        bdk_error("%s: Failed to allocate transmit FIFO\n", handle->name);
        return -1;
    }
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    /* Nothing to do */
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    /* Nothing to do */
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    /* Always report 10Gbps as a fake value */
    bdk_if_link_t result;
    result.u64 = 0;
    result.s.full_duplex = 1;
    result.s.lanes = 1;
    result.s.speed = 10000;
    result.s.up = 1;
    return result;
}

static void if_link_set(bdk_if_handle_t handle, bdk_if_link_t link_info)
{
    /* Nothing to do */
}

static int if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    priv_t *priv = handle->priv;

    bdk_spinlock_lock(&priv->lock);

    int next_tx_free = priv->tx_free + 1;
    if (next_tx_free >= MAX_QUEUE)
        next_tx_free = 0;
    if (next_tx_free == priv->next_rx)
    {
        /* Queue is full */
        bdk_spinlock_unlock(&priv->lock);
        return -1;
    }

    /* We must make a copy of this packet */
    if (bdk_if_copy(&priv->queue[priv->tx_free], packet))
    {
        bdk_error("%s: Failed to allocate packet space\n", handle->name);
        bdk_spinlock_unlock(&priv->lock);
        return -1;
    }

    handle->stats.tx.packets++;
    handle->stats.tx.octets += priv->queue[priv->tx_free].length;

    /* Move to the next free spot */
    priv->tx_free = next_tx_free;

    bdk_spinlock_unlock(&priv->lock);
    return 0;
}

static int if_receive(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    priv_t *priv = handle->priv;

    /* Quickly check for empty before taking the lock */
    if (bdk_likely(priv->next_rx == priv->tx_free))
        return -1;

    bdk_spinlock_lock(&priv->lock);

    /* check for empty again now that we have the lock as it might have changed */
    if (priv->next_rx == priv->tx_free)
    {
        bdk_spinlock_unlock(&priv->lock);
        return -1;
    }

    packet->if_handle = handle;
    packet->length = priv->queue[priv->next_rx].length;
    packet->segments = priv->queue[priv->next_rx].segments;
    packet->rx_error = 0;
    /* This will copy more than necessary, but gcc can inline it and make it
       efficient */
    memcpy(packet->packet, priv->queue[priv->next_rx].packet, sizeof(packet->packet));


    handle->stats.rx.packets++;
    handle->stats.rx.octets += packet->length;

    /* Move to the next packet */
    priv->next_rx++;
    if (priv->next_rx >= MAX_QUEUE)
        priv->next_rx = 0;

    bdk_spinlock_unlock(&priv->lock);
    return 0;
}

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    /* Always internal loopback */
    return 0;
}

static int if_get_queue_depth(bdk_if_handle_t handle)
{
    priv_t *priv = handle->priv;

    /* Make sure gcc reads the variables once and in the correct order */
    int next_rx = (volatile int)priv->next_rx;
    int tx_free = (volatile int)priv->tx_free;

    if (next_rx > tx_free)
        return MAX_QUEUE - next_rx + tx_free;
    else
        return tx_free - next_rx;
}

/**
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
static const bdk_if_stats_t *if_get_stats(bdk_if_handle_t handle)
{
    return &handle->stats;
}

const __bdk_if_ops_t __bdk_if_ops_fake = {
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


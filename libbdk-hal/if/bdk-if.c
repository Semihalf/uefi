#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

extern __bdk_if_global_ops_t __bdk_if_global_ops_cn88xx;

extern const __bdk_if_ops_t __bdk_if_ops_bgx;
extern const __bdk_if_ops_t __bdk_if_ops_pcie;
extern const __bdk_if_ops_t __bdk_if_ops_fake;

static const __bdk_if_ops_t *__bdk_if_ops[__BDK_IF_LAST] = {
    [BDK_IF_BGX] = &__bdk_if_ops_bgx,
    [BDK_IF_PCIE] = &__bdk_if_ops_pcie,
    [BDK_IF_FAKE] = &__bdk_if_ops_fake,
};

static __bdk_if_port_t *__bdk_if_head;
static __bdk_if_port_t *__bdk_if_tail;
static __bdk_if_port_t *__bdk_if_poll_head;
static __bdk_if_global_ops_t __bdk_if_global_ops;
extern bdk_spinlock_t __bdk_pko_reg_lock;

/**
 * Initialize a port for use. All memory is allocated dynmically
 * as each port is added. This should only be called once for each
 * port. After this call the port needs to be enabled before use.
 *
 * @param iftype    Type of the port to init
 * @param interface Which interface for the port. This always starts at zero and
 *                  increments.
 * @param index     Specific index for this port on the interface.
 *
 * @return New port handle, or NULL on failure.
 */
static bdk_if_handle_t bdk_if_init_port(bdk_node_t node, bdk_if_t iftype, int interface, int index)
{
    bdk_if_handle_t handle = calloc(1, sizeof(__bdk_if_port_t));
    if (!handle)
    {
        bdk_error("bdk_if_init_port() failed to allocate if handle\n");
        goto fail;
    }

    handle->iftype = iftype;
    handle->node = node;
    handle->interface = interface;
    handle->index = index;
    handle->next = NULL;
    handle->flags = 0;
    snprintf(handle->name, sizeof(handle->name), "P%d.%d", interface, index);
    handle->name[sizeof(handle->name)-1] = 0;

    if (__bdk_if_ops[iftype]->if_probe(handle))
    {
        bdk_error("if_probe indirect call failed\n");
        goto fail;
    }

    if (__bdk_if_ops[iftype]->if_init(handle))
    {
        bdk_error("if_init indirect call failed\n");
        goto fail;
    }

    /* Put interfaces requiring polling in the poll list */
    if (__bdk_if_ops[handle->iftype]->if_receive)
    {
        handle->poll_next = __bdk_if_poll_head;
        __bdk_if_poll_head = handle;
    }

    if (__bdk_if_tail)
        __bdk_if_tail->next = handle;
    else
        __bdk_if_head = handle;
    __bdk_if_tail = handle;

    return handle;

fail:
    if (handle)
        free(handle);
    return NULL;
}


/**
 * Initialize all packet interfaces of all types for use. This
 * is the one call needed to get all interfaces configured. Enable
 * needs to be called on each handle before actual packets flow.
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_init_node(bdk_node_t node)
{
    int result = 0;

    /* Loop through all types */
    for (bdk_if_t iftype=BDK_IF_BGX; iftype<__BDK_IF_LAST; iftype++)
    {
        /* Loop through all interfaces for each type */
        int num_interfaces = bdk_if_num_interfaces(node, iftype);
        for (int interface=0; interface<num_interfaces; interface++)
        {
            /* Loop through all indexes for each interface */
            int num_index = bdk_if_num_ports(node, iftype, interface);
            for (int index=0; index<num_index; index++)
            {
                bdk_if_handle_t handle = bdk_if_init_port(node, iftype, interface, index);
                if (!handle)
                    result--;
            }
        }
    }
    return result;
}

/**
 * Initialize all packet interfaces of all types for use. This
 * is the one call needed to get all interfaces configured. Enable
 * needs to be called on each handle before actual packets flow.
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_if_init(void)
{
    int result = 0;

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        __bdk_if_global_ops = __bdk_if_global_ops_cn88xx;
    else
        bdk_fatal("bdk-if: Unsupported chip\n");

    if (__bdk_if_global_ops.init())
    {
        bdk_error("bdk-if: Per chip global init failed\n");
        return -1;
    }

    for (int node=0; node<BDK_NUMA_MAX_NODES; node++)
    {
        if ((1<<node) & bdk_numa_get_running_mask())
            result |= __bdk_if_init_node(node);
    }
    return result;
}

/**
 * Return if the bdk_if system has been configured. This is useful
 * for code that wants to use bdk_if if it is configured, but not
 * force it to be configured. A good example is polling for link
 * status.
 *
 * @return Non zero if bdk_if is configured.
 */
int bdk_if_is_configured(void)
{
    return __bdk_if_head != NULL;
}


/**
 * Get the number of interfaces for the given type
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param iftype Interface type
 *
 * @return Number of interface. Zero if unsupported.
 */
int bdk_if_num_interfaces(bdk_node_t node, bdk_if_t iftype)
{
    if (__bdk_if_ops[iftype])
        return __bdk_if_ops[iftype]->if_num_interfaces(node);
    else
        return 0;
}


/**
 * For a given interface, return the number of ports supported
 * by that interface.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param iftype    Interface type
 * @param interface Interface number
 *
 * @return Number of ports. Zero if unsupported.
 */
int bdk_if_num_ports(bdk_node_t node, bdk_if_t iftype, int interface)
{
    return __bdk_if_ops[iftype]->if_num_ports(node, interface);
}


/**
 * Get the next valid port handle after the supplied handle. Returns
 * the first port handle when argument is NULL. This meant to make it
 * easy to write loops that iterate over ports.
 *
 * @param handle Port to get handle after. NULL means get the first port.
**
   @return Next port handle or NULL when the end is reached.
 */
bdk_if_handle_t bdk_if_next_port(bdk_if_handle_t handle)
{
    if (handle)
        return handle->next;
    else
    {
        if (!__bdk_if_head)
            __bdk_if_init();
        return __bdk_if_head;
    }
}


/**
 * Enable the given port for packet IO
 *
 * @param handle Handle to enable
 *
 * @return Zero on success, negative on failure
 */
int bdk_if_enable(bdk_if_handle_t handle)
{
    if (handle->flags & BDK_IF_FLAGS_ENABLED)
        return 0;
    handle->flags |= BDK_IF_FLAGS_ENABLED;
    return __bdk_if_ops[handle->iftype]->if_enable(handle);
}


/**
 * Disable the given port for packet IO
 *
 * @param handle Handle to disable
 *
 * @return Zero on success, negative on failure
 */
int bdk_if_disable(bdk_if_handle_t handle)
{
    if (handle->flags & BDK_IF_FLAGS_ENABLED)
    {
        handle->flags &= ~BDK_IF_FLAGS_ENABLED;
        return __bdk_if_ops[handle->iftype]->if_disable(handle);
    }
    return 0;
}


/**
 * Configure loopback on an interface
 *
 * @param handle   Handle of interface
 * @param loopback Type of loopback
 *
 * @return Zero on success, negative on failure.
 */
int bdk_if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    if (__bdk_if_ops[handle->iftype]->if_loopback)
        return __bdk_if_ops[handle->iftype]->if_loopback(handle, loopback);
    else
    {
        bdk_error("%s: Loopback not implemented\n", bdk_if_name(handle));
        return -1;
    }
}

/**
 * Read the current queue depth for a port. Note that this
 * operation may be slow and adversly affect packet IO
 * performance.
 *
 * @param handle Port to read
 *
 * @return Depth of the queue in packets. Zero means the queue is empty
 */
int bdk_if_get_queue_depth(bdk_if_handle_t handle)
{
    return __bdk_if_ops[handle->iftype]->if_get_queue_depth(handle);
}

/**
 * Return the human readable name of a handle
 *
 * @param handle Handle to name
 *
 * @return Static shared buffer for the name
 */
const char *bdk_if_name(bdk_if_handle_t handle)
{
    return handle->name;
}


/**
 * Get the link status for the port
 *
 * @param handle Handle of port
 *
 * @return Link status
 */
bdk_if_link_t bdk_if_link_get(bdk_if_handle_t handle)
{
    return handle->link_info;
}


/**
 * Get the link status for the port and configure it for that speed
 *
 * @param handle Handle of port
 *
 * @return Link status
 */
bdk_if_link_t bdk_if_link_autoconf(bdk_if_handle_t handle)
{
    static bdk_rlock_t link_lock = { 0, 0 };

    bdk_rlock_lock(&link_lock);
    bdk_if_link_t link_info = __bdk_if_ops[handle->iftype]->if_link_get(handle);

    if (link_info.u64 != handle->link_info.u64)
    {
        handle->link_info = link_info;
        if (__bdk_if_ops[handle->iftype]->if_link_set)
            __bdk_if_ops[handle->iftype]->if_link_set(handle, handle->link_info);
        if (bdk_config_get(BDK_CONFIG_SHOW_LINK_STATUS))
        {
            printf("%s: Link %s", bdk_if_name(handle), (link_info.s.up) ? "up" : "down");
            if (link_info.s.up)
            {
                printf(", %d Mbps, %s duplex", link_info.s.speed, (link_info.s.full_duplex) ? "Full" : "Half");
                if (link_info.s.lanes)
                    printf(", %d lanes", link_info.s.lanes);
            }
            printf("\n");
        }
    }
    bdk_rlock_unlock(&link_lock);
    return handle->link_info;
}


/**
 * Update a statistic that has a limited bit with. The hardware stats counters
 * add up all packets but overflow with limited precision. This function checks
 * for overflow and returns the correct sum.
 *
 * @param new_value New hardware value, limited to bit_size precision
 * @param old_value Old value return by this function. This is a full 64 bit value.
 * @param bit_size  The number of bits in the hardware counter
 *
 * @return New counter value, accounting for overflow
 */
uint64_t bdk_update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size) __attribute__ ((noinline));
uint64_t bdk_update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size)
{
    uint64_t mask = bdk_build_mask(bit_size);
    uint64_t tmp = old_value & mask;
    new_value &= mask;

    /* On overflow we need to add 1 in the upper bits */
    if (tmp > new_value)
        new_value += 1ull<<bit_size;

    /* Add in the upper bits from the old value */
    new_value += old_value & ~mask;

    return new_value;
}


/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
int bdk_if_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return __bdk_if_ops[handle->iftype]->if_transmit(handle, packet);
}


/**
 * Register to receive packet from an interface
 *
 * @param handle   Interface to register for
 * @param receiver Function to call
 * @param arg      Second argument to the function
 */
void bdk_if_register_for_packets(bdk_if_handle_t handle, bdk_if_packet_receiver_t receiver, void *arg)
{
    /* Set the receiver to NULL before we update the argument */
    handle->receiver = NULL;
    BDK_WMB;
    /* Update the argument now that we know it can't arrive at other
        cores with an old receiver */
    handle->receiver_arg = arg;
    BDK_WMB;
    /* Finally update the receiver now that the argument must be set */
    handle->receiver = receiver;
    BDK_WMB;
}


void bdk_if_dispatch_packet(bdk_if_packet_t *packet)
{
    void *receiver_arg = packet->if_handle->receiver_arg;
    bdk_if_packet_receiver_t receiver = packet->if_handle->receiver;
    int skip_free = 0;
    if (receiver)
        skip_free = receiver(packet, receiver_arg);
    if (!skip_free)
        bdk_if_free(packet);
}

static void __bdk_if_link_poll()
{
    static bdk_if_handle_t link_handle = NULL;
    static uint64_t next_poll = 0;
    static uint64_t poll_rate = 0;

    uint64_t current_time = bdk_clock_get_count(BDK_CLOCK_CORE);
    if (bdk_likely(current_time < next_poll))
        return;

    if (bdk_unlikely(poll_rate == 0))
        poll_rate = bdk_is_simulation() ? 1000000 : bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 16;

    /* Poll the link state */
    next_poll = current_time + poll_rate;
    link_handle = (link_handle) ? link_handle->next : __bdk_if_head;
    if (link_handle)
        bdk_if_link_autoconf(link_handle);
}

/**
 * Called by idle threads to handle packet IO
 */
int bdk_if_dispatch(void)
{
    if (!bdk_if_is_configured())
        return 0;
    if (bdk_is_boot_core())
        __bdk_if_link_poll();

    bdk_if_packet_t packet;
    int count = 0;
    int got_packet = 0;
    do
    {
        got_packet = 0;
        for (bdk_if_handle_t handle = __bdk_if_poll_head; handle != NULL; handle = handle->poll_next)
        {
            if (__bdk_if_ops[handle->iftype]->if_receive(handle, &packet) == 0)
            {
                bdk_if_dispatch_packet(&packet);
                got_packet = 1;
                count++;
                if (bdk_unlikely(count >= 100))
                {
                    got_packet = 0;
                    break;
                }
            }
        }
    } while (got_packet);
    return count;
}

/**
 * Allocate a packet with buffers for the supplied amount of data
 *
 * @param packet Packet to get buffers for
 * @param length Length of the final packet in bytes
 *
 * @return Zero on success, negative on failure.
 */
int bdk_if_alloc(bdk_if_packet_t *packet, int length)
{
    if (length > 9212)
    {
        bdk_error("Packets larger than 9212 (9216 with FCS) are not allowed\n");
        return -1;
    }
    const int buf_size = bdk_config_get(BDK_CONFIG_PACKET_BUFFER_SIZE);
    packet->if_handle = NULL;
    packet->free_after_send = 0;
    packet->rx_error = 0;
    packet->length = length;

    packet->segments = 0;
    while (length > 0)
    {
        int size = length;
        if (size > buf_size)
            size = buf_size;
        uint64_t buf = __bdk_if_global_ops.alloc(size);
        if (bdk_unlikely(!buf))
        {
            bdk_if_free(packet);
            return -1;
        }
        packet->packet[packet->segments].s.size = size;
        packet->packet[packet->segments].s.address = buf;
        packet->segments++;
        length -= size;
    }
    return 0;
}


/**
 * Read data from a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to read from.
 * @param location Location to read
 * @param length   Length of data to read
 * @param data     Buffer to receive the data
 */
void bdk_if_packet_read(const bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    int segment = 0;
    while (location >= packet->packet[segment].s.size)
    {
        location -= packet->packet[segment].s.size;
        segment++;
    }

    const uint8_t *ptr = bdk_phys_to_ptr(packet->packet[segment].s.address);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (length && (location >= packet->packet[segment].s.size))
        {
            location -= packet->packet[segment].s.size;
            segment++;
            ptr = bdk_phys_to_ptr(packet->packet[segment].s.address);
        }
    }
}


/**
 * Write data into a packet starting at the given location. The packet
 * must already be large enough to contain the data.
 *
 * @param packet   Packet to write to.
 * @param location Location to write
 * @param length   Length of data to write
 * @param data     Data to write
 */
void bdk_if_packet_write(bdk_if_packet_t *packet, int location, int length, const void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to write past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    int segment = 0;
    while (location >= packet->packet[segment].s.size)
    {
        location -= packet->packet[segment].s.size;
        segment++;
    }

    uint8_t *ptr = bdk_phys_to_ptr(packet->packet[segment].s.address);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (length && (location >= packet->packet[segment].s.size))
        {
            location -= packet->packet[segment].s.size;
            segment++;
            ptr = bdk_phys_to_ptr(packet->packet[segment].s.address);
        }
    }
}


/**
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
void bdk_if_free(bdk_if_packet_t *packet)
{
    for (int s = 0; s < packet->segments; s++)
        __bdk_if_global_ops.free(packet->packet[s].s.address, packet->packet[s].s.size);
    packet->segments = 0;
    packet->length = 0;
}

int bdk_if_copy(bdk_if_packet_t *packet, const bdk_if_packet_t *old_packet)
{
    packet->if_handle = NULL;
    packet->free_after_send = 0;
    packet->rx_error = 0;
    packet->length = old_packet->length;

    packet->segments = 0;
    for (int s = 0; s < old_packet->segments; s++)
    {
        uint64_t buf = __bdk_if_global_ops.alloc(old_packet->packet[s].s.size);
        if (bdk_unlikely(!buf))
        {
            bdk_if_free(packet);
            return -1;
        }
        packet->packet[s].s.address = buf;
        packet->packet[s].s.size = old_packet->packet[s].s.size;
        memcpy(bdk_phys_to_ptr(buf), bdk_phys_to_ptr(old_packet->packet[s].s.address), old_packet->packet[s].s.size);
        packet->segments++;
    }
    return 0;
}

const bdk_if_stats_t* bdk_if_get_stats(bdk_if_handle_t handle)
{
    return __bdk_if_ops[handle->iftype]->if_get_stats(handle);
}

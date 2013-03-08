#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

extern const __bdk_if_ops_t __bdk_if_ops_sgmii;
extern const __bdk_if_ops_t __bdk_if_ops_xaui;
extern const __bdk_if_ops_t __bdk_if_ops_higig;
extern const __bdk_if_ops_t __bdk_if_ops_dpi;
extern const __bdk_if_ops_t __bdk_if_ops_loop;
extern const __bdk_if_ops_t __bdk_if_ops_mgmt;
extern const __bdk_if_ops_t __bdk_if_ops_ilk;

static const __bdk_if_ops_t *__bdk_if_ops[__BDK_IF_LAST] = {
    [BDK_IF_SGMII] = &__bdk_if_ops_sgmii,
    [BDK_IF_XAUI] = &__bdk_if_ops_xaui,
    [BDK_IF_HIGIG] = &__bdk_if_ops_higig,
    [BDK_IF_DPI] = &__bdk_if_ops_dpi,
    [BDK_IF_LOOP] = &__bdk_if_ops_loop,
    [BDK_IF_MGMT] = &__bdk_if_ops_mgmt,
    [BDK_IF_ILK] = &__bdk_if_ops_ilk,
};

static void bdk_if_dispatch_thread(int unused, void *unused2);
static __bdk_if_port_t *__bdk_if_head;
static __bdk_if_port_t *__bdk_if_tail;
static __bdk_if_port_t *__bdk_if_poll_head;
static __bdk_if_global_ops_t __bdk_if_global_ops;

static inline void sso_get_work_async(int scr_addr, int wait)
{
    union
    {
        uint64_t u64;
        struct
        {
            uint64_t    scraddr : 8;    /**< the (64-bit word) location in scratchpad to write to (if len != 0) */
            uint64_t    len     : 8;    /**< the number of words in the response (0 => no response) */
            uint64_t    did     : 8;    /**< the ID of the device on the non-coherent bus */
            uint64_t    unused  :36;
            uint64_t    wait    : 1;    /**< if set, don't return load response until work is available */
            uint64_t    unused2 : 3;
        } s;
    } data;

    /* scr_addr must be 8 byte aligned */
    data.u64 = 0;
    data.s.scraddr = scr_addr >> 3;
    data.s.len = 1;
    data.s.did = 12<<3 | 0;
    data.s.wait = wait;
    bdk_send_single(data.u64);
}

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
static bdk_if_handle_t bdk_if_init_port(bdk_if_t iftype, int interface, int index)
{
    bdk_if_handle_t handle = calloc(1, sizeof(__bdk_if_port_t));
    if (!handle)
    {
        bdk_error("bdk_if_init_port() failed to allocate if handle\n");
        goto fail;
    }

    handle->iftype = iftype;
    handle->interface = interface;
    handle->index = index;
    handle->next = NULL;
    handle->pknd = -1;
    handle->ipd_port = -1;
    handle->pko_port = -1;
    handle->pko_queue = -1;
    handle->flags = 0;
    snprintf(handle->name, sizeof(handle->name), "%s%d%d", __bdk_if_ops[iftype]->name, interface, index);
    handle->name[sizeof(handle->name)-1] = 0;

    if (__bdk_if_ops[iftype]->if_probe(handle))
    {
        bdk_error("if_probe indirect call failed\n");
        goto fail;
    }

    if (handle->ipd_port != -1)
    {
        if (__bdk_if_global_ops.pki_port_init(handle))
        {
            bdk_error("pki_port_init() failed\n");
            goto fail;
        }
        if (__bdk_if_global_ops.pko_port_init(handle))
        {
            bdk_error("pko_port_init() failed\n");
            goto fail;
        }
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
static int __bdk_if_init(void)
{
    extern __bdk_if_global_ops_t __bdk_if_global_ops_cn6xxx;
    extern __bdk_if_global_ops_t __bdk_if_global_ops_cn78xx;
    int result = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        __bdk_if_global_ops = __bdk_if_global_ops_cn78xx;
    else
        __bdk_if_global_ops = __bdk_if_global_ops_cn6xxx;


    /* Setup the FPA packet buffers */
    if (bdk_fpa_fill_pool(BDK_FPA_PACKET_POOL,
        bdk_config_get(BDK_CONFIG_NUM_PACKET_BUFFERS)))
        return -1;
    /* Allocate command buffers */
    if (bdk_fpa_fill_pool(BDK_FPA_OUTPUT_BUFFER_POOL,
        bdk_config_get(BDK_CONFIG_NUM_OUTPUT_BUFFERS)))
        return -1;

    /* Make sure SMI/MDIO is enabled so we can query PHYs */
    int num_mdio = (OCTEON_IS_MODEL(OCTEON_CN68XX) || OCTEON_IS_MODEL(OCTEON_CN78XX)) ? 4 : 2;
    for (int i=0; i<num_mdio; i++)
    {
        BDK_CSR_INIT(smix_en, BDK_SMIX_EN(i));
        if (!smix_en.s.en)
        {
            smix_en.s.en = 1;
            BDK_CSR_WRITE(BDK_SMIX_EN(i), smix_en.u64);
        }
    }

    /* Setup the SSO */
    result = __bdk_if_global_ops.sso_init();
    if (result)
        return result;

    /* Setup the common global packet input. Per port stuff will be
        done later */
    result = __bdk_if_global_ops.pki_global_init();
    if (result)
        return result;

    /* Setup the common global packet output. Per port stuff will be
        done later */
    result = __bdk_if_global_ops.pko_global_init();
    if (result)
        return result;

    /* Loop through all types */
    for (bdk_if_t iftype=BDK_IF_SGMII; iftype<__BDK_IF_LAST; iftype++)
    {
        /* Loop through all interfaces for each type */
        int num_interfaces = bdk_if_num_interfaces(iftype);
        for (int interface=0; interface<num_interfaces; interface++)
        {
            /* Loop through all indexes for each interface */
            int num_index = bdk_if_num_ports(iftype, interface);
            for (int index=0; index<num_index; index++)
            {
                bdk_if_handle_t handle = bdk_if_init_port(iftype, interface, index);
                if (!handle)
                    result--;
            }
        }
    }

    /* Enable PKO now that all setup is complete */
    result = __bdk_if_global_ops.pko_enable();
    if (result)
        return result;

    /* Enable PKI now that all setup is complete */
    result = __bdk_if_global_ops.pki_enable();
    if (result)
        return result;

    /* Create dispatch threads */
    for (int core=0; core<bdk_octeon_num_cores(); core++)
    {
        if (bdk_thread_create(1ull<<core, bdk_if_dispatch_thread, 0, NULL, 0))
            bdk_error("Failed to create dispatch thread for core %d\n", core);
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
 * @param iftype Interface type
 *
 * @return Number of interface. Zero if unsupported.
 */
int bdk_if_num_interfaces(bdk_if_t iftype)
{
    if (__bdk_if_ops[iftype])
        return __bdk_if_ops[iftype]->if_num_interfaces();
    else
        return 0;
}


/**
 * For a given interface, return the number of ports supported
 * by that interface.
 *
 * @param iftype    Interface type
 * @param interface Interface number
 *
 * @return Number of ports. Zero if unsupported.
 */
int bdk_if_num_ports(bdk_if_t iftype, int interface)
{
    return __bdk_if_ops[iftype]->if_num_ports(interface);
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
    static BDK_RLOCK_DEFINE(link_lock);

    bdk_rlock_lock(&link_lock);
    bdk_if_link_t link_info = __bdk_if_ops[handle->iftype]->if_link_get(handle);

    if (link_info.u64 != handle->link_info.u64)
    {
        handle->link_info = link_info;
        if (__bdk_if_ops[handle->iftype]->if_link_set)
            __bdk_if_ops[handle->iftype]->if_link_set(handle, handle->link_info);
        if (bdk_config_get(BDK_CONFIG_SHOW_LINK_STATUS) && (handle->iftype != BDK_IF_LOOP))
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
static uint64_t update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size) __attribute__ ((noinline));
static uint64_t update_stat_with_overflow(uint64_t new_value, uint64_t old_value, int bit_size)
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
 * Get the interface RX and TX counters.
 *
 * @param handle Handle of port
 *
 * @return Statistics
 */
const bdk_if_stats_t *bdk_if_get_stats(bdk_if_handle_t handle)
{
    if (__bdk_if_ops[handle->iftype]->if_get_stats)
        return __bdk_if_ops[handle->iftype]->if_get_stats(handle);

    if (bdk_unlikely(bdk_is_simulation()))
        return &handle->stats;

    int bytes_off_tx;
    int bytes_off_rx;

    switch (handle->iftype)
    {
        case BDK_IF_HIGIG:
            /* Subtract Higig header */
            bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
            int header_size = (bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + handle->interface) == 2) ? sizeof(bdk_higig2_header_t) : sizeof(bdk_higig_header_t);
            bytes_off_tx += -header_size;
            bytes_off_rx = -header_size;
            break;
        default:
            /* Account for TX lack of FCS for most ports */
            bytes_off_tx = (handle->flags & BDK_IF_FLAGS_HAS_FCS) ? 4 : 0;
            bytes_off_rx = 0;
            break;
    }

    bdk_pip_stat0_x_t stat0;
    bdk_pip_stat1_x_t stat1;
    bdk_pip_stat2_x_t stat2;

    stat0.u64 = BDK_CSR_READ(BDK_PIP_STAT0_X(handle->pknd));
    stat1.u64 = BDK_CSR_READ(BDK_PIP_STAT1_X(handle->pknd));
    stat2.u64 = BDK_CSR_READ(BDK_PIP_STAT2_X(handle->pknd));
    BDK_CSR_INIT(pip_stat_inb_errsx, BDK_PIP_STAT_INB_ERRS_PKNDX(handle->pknd));

    handle->stats.rx.dropped_octets -= handle->stats.rx.dropped_packets * bytes_off_rx;
    handle->stats.rx.dropped_octets = update_stat_with_overflow(stat0.s.drp_octs, handle->stats.rx.dropped_octets, 32);
    handle->stats.rx.dropped_packets = update_stat_with_overflow(stat0.s.drp_pkts, handle->stats.rx.dropped_packets, 32);
    handle->stats.rx.dropped_octets += handle->stats.rx.dropped_packets * bytes_off_rx;

    handle->stats.rx.octets -= handle->stats.rx.packets * bytes_off_rx;
    handle->stats.rx.octets = update_stat_with_overflow(stat1.s.octs, handle->stats.rx.octets, 48);
    handle->stats.rx.packets = update_stat_with_overflow(stat2.s.pkts, handle->stats.rx.packets, 32);
    handle->stats.rx.errors = update_stat_with_overflow(pip_stat_inb_errsx.s.errs, handle->stats.rx.errors, 16);
    handle->stats.rx.octets += handle->stats.rx.packets * bytes_off_rx;

    BDK_CSR_INIT(pko_reg_read_idx, BDK_PKO_REG_READ_IDX);
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, handle->pko_port);
    BDK_CSR_INIT(pko_mem_count0, BDK_PKO_MEM_COUNT0);
    BDK_CSR_INIT(pko_mem_count1, BDK_PKO_MEM_COUNT1);
    BDK_CSR_WRITE(BDK_PKO_REG_READ_IDX, pko_reg_read_idx.u64);

    handle->stats.tx.octets -= handle->stats.tx.packets * bytes_off_tx;
    handle->stats.tx.octets = update_stat_with_overflow(pko_mem_count1.s.count, handle->stats.tx.octets, 48);
    handle->stats.tx.packets = update_stat_with_overflow(pko_mem_count0.s.count, handle->stats.tx.packets, 32);
    handle->stats.tx.octets += handle->stats.tx.packets * bytes_off_tx;

    return &handle->stats;
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
    if (bdk_unlikely(__bdk_if_ops[handle->iftype]->if_transmit))
        return __bdk_if_ops[handle->iftype]->if_transmit(handle, packet);

    if (bdk_unlikely(packet->segments >= 64))
    {
        bdk_error("PKO can't transmit packets with more than 63 segments\n");
        return -1;
    }

    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.dontfree = packet->packet.s.i;
    pko_command.s.ignore_i = 1;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;
    bdk_buf_ptr_t buf = packet->packet;
    buf.s.i = 0;

    bdk_cmd_queue_result_t result = bdk_cmd_queue_write2(&handle->cmd_queue[0], 1, pko_command.u64, buf.u64);

    if (bdk_likely(result == BDK_CMD_QUEUE_SUCCESS))
    {
        bdk_pko_doorbell(handle->pko_port, handle->pko_queue, 2);
        /* Updates the statistics in software if need to. The simulator
            doesn't implement the hardware counters */
        if (bdk_unlikely(bdk_is_simulation()))
        {
            int octets = pko_command.s.total_bytes;
            if (handle->flags & BDK_IF_FLAGS_HAS_FCS)
                octets += 4;
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.octets, octets);
            bdk_atomic_add64_nosync((int64_t*)&handle->stats.tx.packets, 1);
        }
    }
    return result;
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
    BDK_SYNCW;
    /* Update the argument now that we know it can't arrive at other
        cores with an old receiver */
    handle->receiver_arg = arg;
    BDK_SYNCW;
    /* Finally update the receiver now that the argument must be set */
    handle->receiver = receiver;
    BDK_SYNCW;
}


static inline void dispatch(bdk_if_packet_t *packet)
{
    void *receiver_arg = packet->if_handle->receiver_arg;
    bdk_if_packet_receiver_t receiver = packet->if_handle->receiver;
    int skip_free = 0;
    if (receiver)
        skip_free = receiver(packet, receiver_arg);
    if (!skip_free)
        bdk_if_free(packet);
}


/**
 * Called by the dispatcher thread to dispatch pending packets
 */
static int bdk_if_dispatch(void)
{
    if (!bdk_if_is_configured())
        return 0;
    int count = 0;
    bdk_if_packet_t packet;

    while (count < 100)
    {
        const void *wqe;
        /* Get the current status of the async get work */
        uint64_t raw_work = bdk_scratch_read64(BDK_IF_SCR_WORK);

        /* Issue an async get work if the previous one completed */
        if (raw_work)
        {
            /* Get a pointer to the work */
            wqe = (bdk_wqe_t*)bdk_phys_to_ptr(raw_work);
            BDK_PREFETCH(wqe, 0);

            /* The get work should already be done, but this insures that it is */
            BDK_SYNCIOBDMA;
            /* Store zero before doing async get work so we can tell when
                it is done */
            bdk_scratch_write64(BDK_IF_SCR_WORK, 0);
            sso_get_work_async(BDK_IF_SCR_WORK, 0);
        }

        /* Check devices that msut be polled if no work was available */
        if (!raw_work || (raw_work>>63))
        {
            for (bdk_if_handle_t handle=__bdk_if_poll_head; handle!=NULL; handle=handle->poll_next)
                if (__bdk_if_ops[handle->iftype]->if_receive(handle, &packet) == 0)
                {
                    count++;
                    dispatch(&packet);
                }
            return count;
        }

        count++;

        if (__bdk_if_global_ops.sso_wqe_to_packet(wqe, &packet))
        {
            bdk_error("sso_wqe_to_packet() failed\n");
            bdk_if_free(&packet);
            return count;
        }

        /* Updates the statistics in software if need to. The simulator
            doesn't implement the hardware counters */
        if (bdk_unlikely(bdk_is_simulation()))
        {
            bdk_atomic_add64_nosync((int64_t*)&packet.if_handle->stats.rx.octets, packet.length);
            bdk_atomic_add64_nosync((int64_t*)&packet.if_handle->stats.rx.packets, 1);
            if (packet.rx_error)
                bdk_atomic_add64_nosync((int64_t*)&packet.if_handle->stats.rx.errors, 1);
        }
        dispatch(&packet);
    }
    return count;
}


/**
 * Thread that dispatches packets. One thread per core.
 *
 * @param unused
 * @param unused2
 */
static void bdk_if_dispatch_thread(int unused, void *unused2)
{
    bdk_if_handle_t link_handle = NULL;
    uint64_t last_poll = 0;
    const uint64_t poll_rate = bdk_clock_get_rate(BDK_CLOCK_CORE) / 16;

    while (1)
    {
        if ((bdk_if_dispatch() == 0) && (bdk_get_core_num() == 0))
        {
            /* Poll the link state */
            uint64_t current_time = bdk_clock_get_count(BDK_CLOCK_CORE);
            if (current_time > last_poll + poll_rate)
            {
                last_poll = current_time;
                link_handle = (link_handle) ? link_handle->next : __bdk_if_head;
                if (link_handle)
                    bdk_if_link_autoconf(link_handle);
            }
        }
        bdk_thread_yield();
    }
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
    const int FPA_SIZE = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
    bdk_buf_ptr_t *buffer_ptr = &packet->packet;

    /* Start off with an empty packet */
    packet->length = 0;
    packet->segments = 0;

    /* Add buffers while the packet is less that the needed length */
    while (packet->length < length)
    {
        void *buffer = bdk_fpa_alloc(BDK_FPA_PACKET_POOL);
        if (!buffer)
        {
            /* Free all buffers allocates so far */
            bdk_if_free(packet);
            return -1;
        }
        /* Fill in the packet link pointer */
        buffer_ptr->u64 = 0;
        buffer_ptr->s.pool = BDK_FPA_PACKET_POOL;
        buffer_ptr->s.size = FPA_SIZE - 8;
        buffer_ptr->s.addr = bdk_ptr_to_phys(buffer) + 8;
        packet->length += buffer_ptr->s.size;
        packet->segments++;
        /* The next chain pointer is at the beginning of the buffer */
        buffer_ptr = buffer;
    }
    /* Fix length as it will likely be too large since we increment in FPA
        chunks */
    packet->length = length;
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
void bdk_if_packet_read(bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.s.size)
    {
        location -= buffer_ptr.s.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }

    const uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.s.size))
        {
            location -= buffer_ptr.s.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
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
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.s.size)
    {
        location -= buffer_ptr.s.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }

    uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.s.size))
        {
            location -= buffer_ptr.s.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
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
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    bdk_buf_ptr_t next_buffer_ptr;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Remember the back pointer is in cache lines, not 64bit words */
        uint64_t start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        /* Read pointer to next buffer before we free the current buffer. */
        if (number_buffers)
            next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
        __bdk_fpa_raw_free(start_of_buffer, buffer_ptr.s.pool, 0);
        buffer_ptr = next_buffer_ptr;
    }
}


/**
 * Get the GMX block number for ports that use GMX
 *
 * @param handle Port handle
 *
 * @return GMX block number
 */
int __bdk_if_get_gmx_block(bdk_if_handle_t handle)
{
    return handle->interface;
}


/**
 * Get the GMX index number for ports that use GMX
 *
 * @param handle Port handle
 *
 * @return GMX index number
 */
int __bdk_if_get_gmx_index(bdk_if_handle_t handle)
{
    return handle->index;
}


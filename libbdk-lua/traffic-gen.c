#include <bdk.h>
#include <stdbool.h>
#include <stdio.h>
#include "traffic-gen.i"

static const int ETHERNET_CRC = 4;       /* Gigabit ethernet CRC in bytes */
static const int MAC_ADDR_LEN = 6;
static const int IP_ADDR_LEN = 4;
static const int CYCLE_SHIFT = 12;
static const int PIP_IP_OFFSET = 4;       /* Number of dwords to reserve before IP packets */

typedef struct
{
    bdk_if_handle_t handle;
    bdk_if_stats_t clear_stats;
    bdk_if_stats_t delta_stats;
    uint64_t last_update;
    trafficgen_port_info_t pinfo;
} tg_port_t;

static trafficgen_port_set_t tg_all_set;

/**
 *
 * @param handle
 *
 * @return
 */
static tg_port_t *tg_get_port(bdk_if_handle_t handle)
{
    static tg_port_t *tg_port[64];

    for (int i=0; i<64; i++)
    {
        if (tg_port[i] == NULL)
        {
            tg_port[i] = calloc(1, sizeof(tg_port_t));
            if (tg_port[i])
            {
                tg_port[i]->handle = handle;
                tg_port[i]->pinfo.priv = tg_port[i];
            }
            return tg_port[i];
        }
        else if (tg_port[i]->handle == handle)
            return tg_port[i];
    }
    return NULL;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static tg_port_t *tg_info_to_port(trafficgen_port_info_t *pinfo)
{
    return (tg_port_t*)pinfo->priv;
}

/**
 *
 * @param tg_port
 */
static void tg_init_port(tg_port_t *tg_port)
{
    switch (bdk_if_get_type(tg_port->handle))
    {
        case BDK_IF_SRIO:
            tg_port->pinfo.setup.srio.s.prio = 0;
            tg_port->pinfo.setup.srio.s.tt = 1;
            tg_port->pinfo.setup.srio.s.sis = 0;
            tg_port->pinfo.setup.srio.s.ssize = 0xe;
            tg_port->pinfo.setup.srio.s.did = 0xffff;
            tg_port->pinfo.setup.srio.s.xmbox = 0;
            tg_port->pinfo.setup.srio.s.mbox = tg_port->handle->index&3;
            tg_port->pinfo.setup.srio.s.letter = 0;
            tg_port->pinfo.setup.srio.s.lns = 0;
            tg_port->pinfo.setup.srio.s.intr = 0;
            break;
        default:
            break;
    }
    bdk_if_enable(tg_port->handle);
}

/**
 */
static void tg_init(void)
{
    if (bdk_if_init())
        bdk_error("bdk_if_init() failed\n");

    int count = 0;
    for (bdk_if_handle_t handle = bdk_if_next_port(NULL); handle!=NULL; handle = bdk_if_next_port(handle))
    {
        tg_port_t *tg_port = tg_get_port(handle);
        if (tg_port)
        {
            strcpy(tg_port->pinfo.name, bdk_if_name(handle));
            tg_init_port(tg_port);
            tg_all_set.list[count++] = &tg_port->pinfo;
        }
    }

    tg_all_set.list[count] = NULL;
    trafficgen_do_reset(&tg_all_set);
}


/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_wire_overhead(const tg_port_t *tg_port)
{
    if (tg_port->pinfo.setup.srio.u64)
        return 0;
    else
        return 12 /*INTERFRAME_GAP*/ + 8 /*MAC_PREAMBLE*/ + ETHERNET_CRC;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_pre_l2(const tg_port_t *tg_port)
{
    if (tg_port->pinfo.setup.srio.u64)
    {
        /* TX needs to add SRIO header */
        return sizeof(tg_port->pinfo.setup.srio);
    }
    else
    {
        /* The preamble is created by hardware, so the length is zero for SW. */
        return 0;
    }
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_l2(const tg_port_t *tg_port)
{
    /* L2 header is two MAC addresses and a L2 size/type */
    return MAC_ADDR_LEN*2 + 2;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_ip_header(const tg_port_t *tg_port)
{
    /* We don't support options, so the size of the IP header is fixed for
        IPv4 */
    return 20;
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_size_payload(const tg_port_t *tg_port)
{
    /* The payload area is whatever is left after the previous headers. Note
        that this does not include any UDP or TCP header */
    return tg_port->pinfo.setup.output_packet_size - get_size_ip_header(tg_port) - get_size_l2(tg_port);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_pre_l2(const tg_port_t *tg_port)
{
    return get_size_pre_l2(tg_port);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_l2(const tg_port_t *tg_port)
{
    return get_end_pre_l2(tg_port) + get_size_l2(tg_port);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_ip_header(const tg_port_t *tg_port)
{
    return get_end_l2(tg_port) + get_size_ip_header(tg_port);
}

/**
 *
 * @param pinfo
 *
 * @return
 */
static int get_end_payload(const tg_port_t *tg_port)
{
    return get_end_ip_header(tg_port) + get_size_payload(tg_port);
}

/**
 *
 * @param index
 *
 * @return
 */
trafficgen_port_info_t *trafficgen_port_get(int index)
{
    if (tg_all_set.list[0] == NULL)
        tg_init();
    return tg_all_set.list[index];
}

/**
 *
 * @param set
 * @param pinfo
 */
void trafficgen_port_add(trafficgen_port_set_t *set, trafficgen_port_info_t *pinfo)
{
    int i;
    int max = sizeof(set->list) / sizeof(set->list[0]);
    for (i=0; i<max; i++)
    {
        if (set->list[i] == pinfo)
            break;
        else if (set->list[i] == NULL)
        {
            set->list[i] = pinfo;
            break;
        }
    }
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_clear(const trafficgen_port_set_t *range)
{
    for (int i=0; range->list[i] != NULL; i++)
    {
        tg_port_t *tg_port = tg_info_to_port(range->list[i]);
        const bdk_if_stats_t *stats = bdk_if_get_stats(tg_port->handle);
        tg_port->clear_stats = *stats;
        tg_port->delta_stats = *stats;
        memset(&tg_port->pinfo.stats, 0, sizeof(tg_port->pinfo.stats));
    }
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_reset(const trafficgen_port_set_t *range)
{
    uint64_t mac_addr_base = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);

    for (int i=0; range->list[i] != NULL; i++)
    {
        tg_port_t *tg_port = tg_info_to_port(range->list[i]);
        tg_port_t *connect_to = tg_port; // FIXME
        uint64_t src_mac = mac_addr_base + bdk_if_get_pknd(tg_port->handle);
        uint64_t dest_mac = mac_addr_base + bdk_if_get_pknd(connect_to->handle);
        int src_inc = bdk_if_get_pknd(tg_port->handle) << 16;
        int dest_inc = bdk_if_get_pknd(connect_to->handle) << 16;

        tg_port->pinfo.setup.output_rate                = 1000;
        tg_port->pinfo.setup.output_rate_is_mbps        = true;
        tg_port->pinfo.setup.output_enable              = 0;
        tg_port->pinfo.setup.output_count               = 0;
        tg_port->pinfo.setup.output_packet_size         = 64 - ETHERNET_CRC;
        tg_port->pinfo.setup.src_mac                    = src_mac;
        tg_port->pinfo.setup.dest_mac                   = dest_mac;
        tg_port->pinfo.setup.src_ip                     = 0x0a000063 | src_inc;        /* 10.port.0.99 */
        tg_port->pinfo.setup.dest_ip                    = 0x0a000063 | dest_inc;   /* 10.connect_to_port.0.99 */
        tg_port->pinfo.setup.src_port                   = 4096;
        tg_port->pinfo.setup.dest_port                  = 4097;
        tg_port->pinfo.setup.ip_tos                     = 0;
        tg_port->pinfo.setup.do_checksum                = 0;
        tg_port->pinfo.setup.display_packet             = false;
        tg_port->pinfo.setup.validate                   = true;
    }
    return trafficgen_do_clear(range);
}

/**
 *
 * @return
 */
int trafficgen_do_update(bool do_clear)
{
    uint64_t clock_rate = bdk_clock_get_rate(BDK_CLOCK_CORE);

    /* Get the statistics for displayed ports */
    for (int i=0; tg_all_set.list[i] != NULL; i++)
    {
        tg_port_t *tg_port = tg_info_to_port(tg_all_set.list[i]);
        uint64_t update_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
        const bdk_if_stats_t *stats = bdk_if_get_stats(tg_port->handle);

        /* TX stats */
        tg_port->pinfo.stats.tx_packets = stats->tx.packets - tg_port->delta_stats.tx.packets;
        tg_port->pinfo.stats.tx_octets = stats->tx.octets - tg_port->delta_stats.tx.octets;

        /* RX stats */
        tg_port->pinfo.stats.rx_dropped_octets = stats->rx.dropped_octets - tg_port->delta_stats.rx.dropped_octets;
        tg_port->pinfo.stats.rx_dropped_packets = stats->rx.dropped_packets - tg_port->delta_stats.rx.dropped_packets;
        tg_port->pinfo.stats.rx_octets = stats->rx.octets - tg_port->delta_stats.rx.octets;
        tg_port->pinfo.stats.rx_packets = stats->rx.packets - tg_port->delta_stats.rx.packets;

        /* Create totals */
        tg_port->pinfo.stats.tx_packets_total = stats->tx.packets - tg_port->clear_stats.tx.packets;
        tg_port->pinfo.stats.tx_octets_total = stats->tx.octets - tg_port->clear_stats.tx.octets;
        tg_port->pinfo.stats.rx_packets_total = stats->rx.packets - tg_port->clear_stats.rx.packets;
        tg_port->pinfo.stats.rx_octets_total = stats->rx.octets - tg_port->clear_stats.rx.octets;
        tg_port->pinfo.stats.rx_errors = stats->rx.errors - tg_port->clear_stats.rx.errors;

        /* Scale to account for update interval */
        if (update_cycle > tg_port->last_update)
        {
            uint64_t scale = (1ull<<32) * clock_rate / (update_cycle - tg_port->last_update);
            tg_port->pinfo.stats.tx_packets = tg_port->pinfo.stats.tx_packets * scale >> 32;
            tg_port->pinfo.stats.tx_octets = tg_port->pinfo.stats.tx_octets * scale >> 32;

            tg_port->pinfo.stats.rx_dropped_octets = tg_port->pinfo.stats.rx_dropped_octets * scale >> 32;
            tg_port->pinfo.stats.rx_dropped_packets = tg_port->pinfo.stats.rx_dropped_packets * scale >> 32;
            tg_port->pinfo.stats.rx_octets = tg_port->pinfo.stats.rx_octets * scale >> 32;
            tg_port->pinfo.stats.rx_packets = tg_port->pinfo.stats.rx_packets * scale >> 32;
        }

        /* Calculate the RX bits. By convention this include all packet
            overhead on the wire. We've already accounted for ETHERNET_CRC but
            not the preamble and IFG */
        uint64_t bytes_off_per_packet;
        switch (bdk_if_get_type(tg_port->handle))
        {
            case BDK_IF_SRIO:
                bytes_off_per_packet = 0;
                break;
            default:
                bytes_off_per_packet = get_size_wire_overhead(tg_port) - ETHERNET_CRC;
                break;
        }
        tg_port->pinfo.stats.rx_bits = (tg_port->pinfo.stats.rx_packets * bytes_off_per_packet + tg_port->pinfo.stats.rx_octets) * 8;

        /* Calculate the TX bits */
        tg_port->pinfo.stats.tx_bits = (tg_port->pinfo.stats.tx_packets * bytes_off_per_packet + tg_port->pinfo.stats.tx_octets) * 8;

        /* Get the backpressure counters */
        switch (bdk_if_get_type(tg_port->handle))
        {
            case BDK_IF_DPI:
            case BDK_IF_LOOP:
            case BDK_IF_SRIO:
                break;
            case BDK_IF_XAUI:
            {
                BDK_CSR_INIT(txx_pause_togo, BDK_GMXX_TXX_PAUSE_TOGO(0, __bdk_if_get_gmx_block(tg_port->handle)));
                tg_port->pinfo.stats.rx_backpressure += txx_pause_togo.s.time;
                break;
            }
            case BDK_IF_SGMII:
            {
                BDK_CSR_INIT(txx_pause_togo, BDK_GMXX_TXX_PAUSE_TOGO(__bdk_if_get_gmx_index(tg_port->handle), __bdk_if_get_gmx_block(tg_port->handle)));
                tg_port->pinfo.stats.rx_backpressure += txx_pause_togo.s.time;
                break;
            }
            case BDK_IF_MGMT:
                break;
            case BDK_IF_ILK:
            {
                int interface = tg_port->handle->interface;
                int pko_port = tg_port->handle->pko_port;
                if (pko_port < 64)
                {
                    BDK_CSR_INIT(ilk_rxx_flow, BDK_ILK_RXX_FLOW_CTL0(interface));
                    if (ilk_rxx_flow.s.status & (1ull << (pko_port & 63)))
                        tg_port->pinfo.stats.rx_backpressure++;
                }
                else
                {
                    BDK_CSR_INIT(ilk_rxx_flow, BDK_ILK_RXX_FLOW_CTL1(interface));
                    if (ilk_rxx_flow.s.status & (1ull << (pko_port & 63)))
                        tg_port->pinfo.stats.rx_backpressure++;
                }
                break;
            }
            case __BDK_IF_LAST:
                break;
        }
        if (do_clear)
        {
            tg_port->delta_stats = *stats;
            tg_port->last_update = update_cycle;
        }
    }
    return 0;
}



/*
 *      Fold a partial checksum without adding pseudo headers
 */
static unsigned short int csum_fold(unsigned int sum)
{
        __asm__(
        "       .set    push            # csum_fold\n"
        "       .set    noat            \n"
        "       sll     $1, %0, 16      \n"
        "       addu    %0, $1          \n"
        "       sltu    $1, %0, $1      \n"
        "       srl     %0, %0, 16      \n"
        "       addu    %0, $1          \n"
        "       xori    %0, 0xffff      \n"
        "       .set    pop"
        : "=r" (sum)
        : "0" (sum));

        return sum;
}


/*
 *      This is a version of ip_compute_csum() optimized for IP headers,
 *      which always checksum on 4 octet boundaries.
 *
 *      By Jorge Cwik <jorge@laser.satlink.net>, adapted for linux by
 *      Arnt Gulbrandsen.
 */
static unsigned short ip_fast_csum(char *iph, unsigned int ihl)
{
        unsigned int *word = (unsigned int *) iph;
        unsigned int *stop = word + ihl;
        unsigned int csum;
        int carry;

        csum = word[0];
        csum += word[1];
        carry = (csum < word[1]);
        csum += carry;

        csum += word[2];
        carry = (csum < word[2]);
        csum += carry;

        csum += word[3];
        carry = (csum < word[3]);
        csum += carry;

        word += 4;
        do {
                csum += *word;
                carry = (csum < *word);
                csum += carry;
                word++;
        } while (word != stop);

        return csum_fold(csum);
}

/**
 * Generate a valid UDP packet
 *
 * @param port   Output port to build for
 */
static char *build_packet(tg_port_t *tg_port)
{
    char *packet = malloc(tg_port->pinfo.setup.output_packet_size + ((tg_port->pinfo.setup.srio.u64) ? 8 : 0));
    if (!packet)
    {
        bdk_error("Failed to allocate TX packet for port %s\n", tg_port->pinfo.name);
        return NULL;
    }
    char *end_ptr = packet + get_end_payload(tg_port);
    char *ptr = packet;

    /* Add the SRIO header before L2 if needed */
    if (tg_port->pinfo.setup.srio.u64)
    {
        memcpy(ptr, &tg_port->pinfo.setup.srio, sizeof(tg_port->pinfo.setup.srio));
        ptr += sizeof(tg_port->pinfo.setup.srio);
    }

    /* Ethernet dest address */
    for (int i=0; i<6; i++)
        *ptr++ = (tg_port->pinfo.setup.dest_mac>>(40-i*8)) & 0xff;

    /* Ethernet source address */
    for (int i=0; i<6; i++)
        *ptr++ = (tg_port->pinfo.setup.src_mac>>(40-i*8)) & 0xff;

    *ptr++ = 0x08;                  /* Ethernet Protocol */
    *ptr++ = 0x00;
    *ptr++ = 0x45;                  /* IP version, ihl */
    *ptr++ = (tg_port->pinfo.setup.ip_tos) & 0xff;    /* IP TOS */
    int ip_length = get_size_ip_header(tg_port) + get_size_payload(tg_port);
    *ptr++ = ip_length>>8;        /* IP length */
    *ptr++ = ip_length&0xff;
    *ptr++ = 0x00;                  /* IP id */
    *ptr++ = 0x00;
    *ptr++ = 0x00;                  /* IP frag_off */
    *ptr++ = 0x00;
    *ptr++ = 0x04;                  /* IP ttl */
    *ptr++ = 0x11;                  /* IP protocol */
    uint16_t *ip_checksum_ptr = (uint16_t *)ptr;    /* remember for later */
    *ptr++ = 0x00;                  /* IP check */
    *ptr++ = 0x00;
    *ptr++ = (tg_port->pinfo.setup.src_ip>>24) & 0xff;    /* IP saddr */
    *ptr++ = (tg_port->pinfo.setup.src_ip>>16) & 0xff;
    *ptr++ = (tg_port->pinfo.setup.src_ip>>8) & 0xff;
    *ptr++ = (tg_port->pinfo.setup.src_ip>>0) & 0xff;
    *ptr++ = (tg_port->pinfo.setup.dest_ip>>24) & 0xff;    /* IP daddr */
    *ptr++ = (tg_port->pinfo.setup.dest_ip>>16) & 0xff;
    *ptr++ = (tg_port->pinfo.setup.dest_ip>>8) & 0xff;
    *ptr++ = (tg_port->pinfo.setup.dest_ip>>0) & 0xff;
    *ip_checksum_ptr = ip_fast_csum(packet+get_end_l2(tg_port), 5);

    *ptr++ = tg_port->pinfo.setup.src_port >> 8;  /* UDP source port */
    *ptr++ = tg_port->pinfo.setup.src_port & 0xff;
    *ptr++ = tg_port->pinfo.setup.dest_port >> 8; /* UDP destination port */
    *ptr++ = tg_port->pinfo.setup.dest_port & 0xff;

    int udp_length = get_size_payload(tg_port);
    *ptr++ = udp_length>>8;     /* UDP length */
    *ptr++ = udp_length&0xff;
    *ptr++ = 0x00;                  /* UDP checksum */
    *ptr++ = 0x00;

    /* Fill the rest of the packet with random bytes */
    while (ptr < end_ptr)
        *ptr++ = rand();

    if (tg_port->pinfo.setup.validate)
    {
        int end_l2 = get_end_l2(tg_port);
        ptr = packet + end_l2;
        *(uint32_t*)(end_ptr-4) = bdk_crc32(ptr, end_ptr - ptr - 4, 0xffffffff);
    }
    return packet;
}

static void packet_transmitter(int unused, tg_port_t *tg_port)
{
    char *pdata = build_packet(tg_port);
    trafficgen_port_setup_t *port_tx = &tg_port->pinfo.setup;
    uint64_t output_cycle;
    uint64_t count = port_tx->output_count;

    if (!pdata)
    {
        port_tx->output_enable = 0;
        BDK_SYNCW;
        return;
    }

    /* Figure out my TX rate */
    int packet_rate = port_tx->output_rate;
    if (port_tx->output_rate_is_mbps)
        packet_rate = packet_rate * 125000ull / (tg_port->pinfo.setup.output_packet_size + get_size_wire_overhead(tg_port));
    if (packet_rate == 0)
        packet_rate = 1;
    uint64_t output_cycle_gap = (bdk_clock_get_rate(BDK_CLOCK_CORE) << CYCLE_SHIFT) / packet_rate;

    /* Build the IF packet data structure */
    bdk_if_packet_t packet;
    packet.length = port_tx->output_packet_size + get_size_pre_l2(tg_port);
    packet.segments = 1;
    packet.packet.u64 = 0;
    packet.packet.s.pool = BDK_FPA_PACKET_POOL;
    packet.packet.s.size = 0xffff;
    packet.packet.s.back = 0;
    packet.packet.s.addr = bdk_ptr_to_phys(pdata);
    packet.packet.s.i = 1;

    output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;

    while (port_tx->output_enable)
    {
        int do_yield = 1;
        uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
        if (bdk_likely(cycle >= output_cycle))
        {
            output_cycle += output_cycle_gap;
            /* We don't care if the send fails */
            if (bdk_likely(bdk_if_transmit(tg_port->handle, &packet) == 0))
            {
                if (bdk_unlikely(--count == 0))
                    break;
                do_yield = 0;
            }
        }
        if (do_yield)
            bdk_thread_yield();
    }
    /* FIXME: Wait 1ms to allow PKO to complete before we free the buffer */
    bdk_wait_usec(1000);
    free(pdata);
    port_tx->output_enable = 0;
    BDK_SYNCW;
}

/**
 * Check the CRC on an incomming packet and return non zero if it
 * doesn't match the calculated value.
 *
 * @param work   Packet to process. We handle dynamic short.
 *
 * @return Non zero on CRC error
 */
static int is_packet_crc32c_wrong(tg_port_t *tg_port, bdk_if_packet_t *packet)
{
    const int FPA_SIZE = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
    uint32_t crc = 0xffffffff;
    bdk_buf_ptr_t buffer_ptr = packet->packet;

    /* Get a pointer to the beginning of the packet */
    void *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    int remaining_bytes = packet->length;

    /* Skip the L2 header in the CRC calculation */
    int skip = get_end_l2(tg_port);
    if (bdk_if_get_type(packet->if_handle) == BDK_IF_SRIO)
        skip += 8;
    ptr += skip;
    remaining_bytes -= skip;

    /* Reduce the length by 4, the length of the CRC at the end */
    remaining_bytes -= 4;

#if 0    /* FIXME: Force the UDP checksum to zero for CRC calculation */
    if (!work->word2.s.not_IP && work->word2.s.tcp_or_udp)
    {
        int udp_checksum_offset = 0;
        if (work->word2.s.is_v6)
        {
            if (*(uint8_t*)(ptr + 6) == 0x11)
                udp_checksum_offset = get_size_ip_header(tg_port) + 6;
        }
        else
        {
            if (*(uint8_t*)(ptr + 9) == 0x11)
                udp_checksum_offset = get_size_ip_header(tg_port) + 6;
        }

        if (udp_checksum_offset)
        {
            uint16_t zero = 0;
            crc = bdk_crc32(ptr,  udp_checksum_offset,  crc);
            crc = bdk_crc32(&zero,  2,  crc);
            ptr += udp_checksum_offset + 2;
            remaining_bytes -= udp_checksum_offset + 2;
        }
    }
#endif

    while (remaining_bytes)
    {
        /* Figure out the maximum bytes this buffer could hold for us */
        void *start_of_buffer = bdk_phys_to_ptr(((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7);
        int buffer_bytes = FPA_SIZE - (ptr - start_of_buffer);
        if (bdk_likely(remaining_bytes <= buffer_bytes))
        {
            /* The rest of the crc data fits in this single buffer */
            crc = bdk_crc32(ptr,  remaining_bytes,  crc);
            buffer_bytes -= remaining_bytes;
            /* Most of the time the CRC fits right after the data in the
                buffer. If it doesn't we need the next buffer too */
            if (bdk_likely(buffer_bytes >= 4))
                return (crc != *(uint32_t*)(ptr + remaining_bytes));
            else
            {
                if (bdk_likely(buffer_bytes))
                {
                    /* Read 4 bytes from right after the data */
                    uint32_t packet_crc1 = *(uint32_t*)(ptr + remaining_bytes);
                    /* AND off the lower bits that are actually in the next buffer */
                    packet_crc1 &= ~bdk_build_mask(8*(4-buffer_bytes));
                    /* Get a pointer to the next buffer. The rest of the CRC should
                    be at the beginning */
                    buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                    /* Read the rest of the CRC */
                    uint32_t packet_crc2 = *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr);
                    /* Shift off extra bytes read since some bytes are stored in part 1*/
                    packet_crc2 >>= 32 - 8*(4-buffer_bytes);
                    /* Compare the final CRC with both parts put together */
                    return (crc != (packet_crc1|packet_crc2));
                }
                else
                {
                    /* Get a pointer to the next buffer. The CRC should be at the beginning */
                    buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                    /* Read the CRC */
                    uint32_t packet_crc = *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr);
                    /* Compare the final CRC with both parts put together */
                    return (crc != packet_crc);
                }
            }
        }
        else
        {
            /* This buffer only contains part of our crc data */
            crc = bdk_crc32(ptr, buffer_bytes,  crc);
            remaining_bytes -= buffer_bytes;
            /* Get a pointer to the next buffer */
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
        }
    }
    return 0;
}

static void dump_packet(tg_port_t *tg_port, bdk_if_packet_t *packet)
{
    uint64_t        count;
    uint64_t        remaining_bytes;
    bdk_buf_ptr_t  buffer_ptr;
    uint64_t        start_of_buffer;
    uint8_t *       data_address;
    uint8_t *       end_of_data;

    printf("\nPacket Length:   %u\n", packet->length);
    printf("    Input Port:  %s\n", tg_port->pinfo.name);
    printf("    Buffers:     %u\n", packet->segments);
    if (packet->rx_error)
        printf("    Error code:  %u\n", packet->rx_error);

    buffer_ptr = packet->packet;
    remaining_bytes = packet->length;

    while (remaining_bytes)
    {
        start_of_buffer = ((buffer_ptr.s.addr >> 7) - buffer_ptr.s.back) << 7;
        printf("    Pool:        %u\n", buffer_ptr.s.pool);
        printf("    Address:     0x%llx\n", (unsigned long long)buffer_ptr.s.addr);
        printf("                 ");
        data_address = (uint8_t *)bdk_phys_to_ptr(buffer_ptr.s.addr);
        end_of_data = data_address + buffer_ptr.s.size;
        count = 0;
        while (data_address < end_of_data)
        {
            if (remaining_bytes == 0)
                break;
            else
                remaining_bytes--;
            printf("%02x", (unsigned int)*data_address);
            data_address++;
            if (remaining_bytes && (count == 15))
            {
                printf("\n                 ");
                count = 0;
            }
            else if (remaining_bytes && ((count&3) == 3))
            {
                printf(" ");
                count++;
            }
            else
                count++;
        }
        printf("\n");

        if (remaining_bytes)
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
    }
    fflush(stdout);
}

/**
 * Called by cores when they get work and need to process it.
 *
 * @param work   Work to be processed. Ideally it should already be prefetched
 *               into memory.
 */
static void process_packet(bdk_if_packet_t *packet)
{
    tg_port_t *tg_port = tg_get_port(packet->if_handle);

    if (bdk_likely((packet->rx_error == 0) && tg_port->pinfo.setup.validate))
    {
        if (bdk_unlikely(is_packet_crc32c_wrong(tg_port, packet)))
            bdk_atomic_add64((int64_t*)&tg_port->pinfo.stats.rx_validation_errors, 1);
    }

    if (bdk_unlikely(tg_port->pinfo.setup.display_packet))
        dump_packet(tg_port, packet);

    bdk_if_free(packet);
}

static void packet_receiver(int unused, void *unused2)
{
    bdk_if_packet_t packet;
    while (1)
    {
        int status = bdk_if_receive(&packet);
        if (status == 0)
            process_packet(&packet);
        else
            bdk_thread_yield();
    }
}

/**
 *
 * @param range
 *
 * @return
 */
int trafficgen_do_transmit(const trafficgen_port_set_t *range)
{
    static int have_rx;

    if (!have_rx)
    {
        bdk_thread_create(0, packet_receiver, 0, NULL, 0);
        bdk_thread_create(0, packet_receiver, 0, NULL, 0);
        have_rx = 1;
    }
    for (int i=0; range->list[i] != NULL; i++)
    {
        tg_port_t *tg_port = tg_info_to_port(range->list[i]);
        tg_port->pinfo.setup.output_enable = 1;
        bdk_thread_create(0, (bdk_thread_func_t)packet_transmitter, i, tg_port, 0);
    }
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
bool trafficgen_is_transmitting(const trafficgen_port_set_t *range)
{
    for (int i=0; range->list[i] != NULL; i++)
    {
        tg_port_t *tg_port = tg_info_to_port(range->list[i]);
        if (tg_port->pinfo.setup.output_enable)
            return 1;
    }
    return 0;
}


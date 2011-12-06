#include <bdk.h>
#include <stdbool.h>
#include <stdio.h>

static const int ETHERNET_CRC = 4;       /* Gigabit ethernet CRC in bytes */
static const int MAC_ADDR_LEN = 6;
static const int CYCLE_SHIFT = 12;

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
} trafficgen_port_stats_t;

typedef struct
{
    int                     output_rate;
    bool                    output_rate_is_mbps;
    bool                    output_enable;
    int                     size;
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
    int                     higig_mode;
    bdk_higig_header_t      higig;
    bdk_higig2_header_t     higig2;
} trafficgen_port_setup_t;

typedef struct
{
    char name[8];
    trafficgen_port_setup_t setup;
    trafficgen_port_stats_t stats;
    void *priv;
} trafficgen_port_info_t;

typedef struct tg_port
{
    bdk_if_handle_t handle;
    bdk_if_stats_t clear_stats;
    bdk_if_stats_t delta_stats;
    uint64_t last_update;
    trafficgen_port_info_t pinfo;
    struct tg_port *next;
} tg_port_t;

static tg_port_t *tg_port_head;
static tg_port_t *tg_port_tail;

static int is_packet_crc32c_wrong(tg_port_t *tg_port, bdk_if_packet_t *packet, int fix);
static int do_reset(tg_port_t *tg_port);
static void tg_packet_receiver(const bdk_if_packet_t *packet, void *arg);

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
            tg_port->pinfo.setup.srio.s.lns = 1;
            tg_port->pinfo.setup.srio.s.intr = 0;
            break;
        case BDK_IF_HIGIG:
            tg_port->pinfo.setup.higig_mode = bdk_config_get(BDK_CONFIG_HIGIG_MODE_IF0 + tg_port->handle->interface);
            /* HiGig headers always start with 0xfb */
            tg_port->pinfo.setup.higig.dw0.s.start = 0xfb;
            tg_port->pinfo.setup.higig2.dw0.s.k_sop = 0xfb;
            break;
        default:
            break;
    }
    bdk_if_register_for_packets(tg_port->handle, tg_packet_receiver, tg_port);
    bdk_if_enable(tg_port->handle);
}

/**
 */
static void tg_init(void)
{
    for (bdk_if_handle_t handle = bdk_if_next_port(NULL); handle!=NULL; handle = bdk_if_next_port(handle))
    {
        tg_port_t *tg_port = tg_get_port(handle);
        if (tg_port)
        {
            strcpy(tg_port->pinfo.name, bdk_if_name(handle));
            tg_port->next = NULL;
            if (tg_port_tail)
                tg_port_tail->next = tg_port;
            else
                tg_port_head = tg_port;
            tg_port_tail = tg_port;
            tg_init_port(tg_port);
            do_reset(tg_port);
        }
    }
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
    else if (tg_port->pinfo.setup.higig_mode == 1)
        return 8 /*INTERFRAME_GAP*/ + 12 /*Higig header*/ + ETHERNET_CRC;
    else if (tg_port->pinfo.setup.higig_mode == 2)
        return 8 /*INTERFRAME_GAP*/ + 16 /*Higig2 header*/ + ETHERNET_CRC;
    else
        return 12 /*INTERFRAME_GAP*/ + 8 /*MAC_PREAMBLE*/ + ETHERNET_CRC;
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
    return tg_port->pinfo.setup.size - get_size_ip_header(tg_port) - get_size_l2(tg_port);
}

/**
 *
 * @return
 */
static int trafficgen_do_update(bool do_clear)
{
    uint64_t clock_rate = bdk_clock_get_rate(BDK_CLOCK_CORE);

    /* Get the statistics for displayed ports */
    for (tg_port_t *tg_port = tg_port_head; tg_port!=NULL; tg_port = tg_port->next)
    {
        uint64_t update_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
        const bdk_if_stats_t *stats = bdk_if_get_stats(tg_port->handle);

        /* TX stats */
        tg_port->pinfo.stats.tx_packets = stats->tx.packets - tg_port->delta_stats.tx.packets;
        tg_port->pinfo.stats.tx_octets = stats->tx.octets - tg_port->delta_stats.tx.octets;

        /* RX stats */
        tg_port->pinfo.stats.rx_octets = stats->rx.octets - tg_port->delta_stats.rx.octets;
        tg_port->pinfo.stats.rx_packets = stats->rx.packets - tg_port->delta_stats.rx.packets;

        /* Create totals */
        tg_port->pinfo.stats.tx_packets_total = stats->tx.packets - tg_port->clear_stats.tx.packets;
        tg_port->pinfo.stats.tx_octets_total = stats->tx.octets - tg_port->clear_stats.tx.octets;
        tg_port->pinfo.stats.rx_packets_total = stats->rx.packets - tg_port->clear_stats.rx.packets;
        tg_port->pinfo.stats.rx_octets_total = stats->rx.octets - tg_port->clear_stats.rx.octets;
        tg_port->pinfo.stats.rx_errors = stats->rx.errors - tg_port->clear_stats.rx.errors;
        tg_port->pinfo.stats.rx_dropped_octets = stats->rx.dropped_octets - tg_port->clear_stats.rx.dropped_octets;
        tg_port->pinfo.stats.rx_dropped_packets = stats->rx.dropped_packets - tg_port->clear_stats.rx.dropped_packets;

        /* Scale to account for update interval */
        if (update_cycle > tg_port->last_update)
        {
            const int scale_shift = 16;
            uint64_t scale = (1ull<<scale_shift) * clock_rate / (update_cycle - tg_port->last_update);
            tg_port->pinfo.stats.tx_packets = tg_port->pinfo.stats.tx_packets * scale >> scale_shift;
            tg_port->pinfo.stats.tx_octets = tg_port->pinfo.stats.tx_octets * scale >> scale_shift;

            tg_port->pinfo.stats.rx_octets = tg_port->pinfo.stats.rx_octets * scale >> scale_shift;
            tg_port->pinfo.stats.rx_packets = tg_port->pinfo.stats.rx_packets * scale >> scale_shift;
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
            case BDK_IF_HIGIG:
            {
                BDK_CSR_INIT(gmxx_rx_hg2_status, BDK_GMXX_RX_HG2_STATUS(__bdk_if_get_gmx_block(tg_port->handle)));
                tg_port->pinfo.stats.rx_backpressure += gmxx_rx_hg2_status.s.lgtim2go;
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

static int write_packet(bdk_if_packet_t *packet, int loc, uint8_t data)
{
    if (loc < packet->length)
        bdk_if_packet_write(packet, loc, 1, &data);
    return loc + 1;
}

/**
 * Generate a valid UDP packet
 *
 * @param port   Output port to build for
 */
static int build_packet(tg_port_t *tg_port, bdk_if_packet_t *packet)
{
    if (tg_port->pinfo.setup.size < 1)
    {
        bdk_error("%s: Packet must be at least 1 byte\n", tg_port->pinfo.name);
        return -1;
    }

    if (tg_port->pinfo.setup.validate && (tg_port->pinfo.setup.size < 19))
    {
        /* Packets smaller than 19 bytes will skip validation. 14 bytes
            skipped for L2, 1 byte of data, and 4 bytes of CRC is the
            minimum for validation */
        bdk_warn("%s: Packets smaller than 19 bytes will not be validated\n", tg_port->pinfo.name);
    }

    int total_length = tg_port->pinfo.setup.size;
    if (tg_port->pinfo.setup.srio.u64)
        total_length += sizeof(tg_port->pinfo.setup.srio);
    if (tg_port->pinfo.setup.higig_mode == 1)
        total_length += sizeof(tg_port->pinfo.setup.higig);
    if (tg_port->pinfo.setup.higig_mode == 2)
        total_length += sizeof(tg_port->pinfo.setup.higig2);
    if (bdk_if_alloc(packet, total_length))
    {
        bdk_error("Failed to allocate TX packet for port %s\n", tg_port->pinfo.name);
        return -1;
    }
    int loc = 0;

    /* Add the SRIO header before L2 if needed */
    if (tg_port->pinfo.setup.srio.u64)
    {
        bdk_if_packet_write(packet, loc, sizeof(tg_port->pinfo.setup.srio), &tg_port->pinfo.setup.srio);
        loc += sizeof(tg_port->pinfo.setup.srio);
    }
    /* Add the Higig header before L2 if needed */
    if (tg_port->pinfo.setup.higig_mode == 1)
    {
        bdk_if_packet_write(packet, loc, sizeof(tg_port->pinfo.setup.higig), &tg_port->pinfo.setup.higig);
        loc += sizeof(tg_port->pinfo.setup.higig);
    }
    /* Add the Higig2 header before L2 if needed */
    if (tg_port->pinfo.setup.higig_mode == 2)
    {
        bdk_if_packet_write(packet, loc, sizeof(tg_port->pinfo.setup.higig2), &tg_port->pinfo.setup.higig2);
        loc += sizeof(tg_port->pinfo.setup.higig2);
    }

    /* Ethernet dest address */
    for (int i=0; i<6; i++)
        loc = write_packet(packet, loc, tg_port->pinfo.setup.dest_mac>>(40-i*8));

    /* Ethernet source address */
    for (int i=0; i<6; i++)
        loc = write_packet(packet, loc, tg_port->pinfo.setup.src_mac>>(40-i*8));

    /* Ethernet Protocol */
    loc = write_packet(packet, loc, 0x08);
    loc = write_packet(packet, loc, 0x00);
    /* IP version, ihl */
    loc = write_packet(packet, loc, 0x45);
    /* IP TOS */
    loc = write_packet(packet, loc, tg_port->pinfo.setup.ip_tos);
    /* IP length */
    int ip_length = get_size_ip_header(tg_port) + get_size_payload(tg_port);
    loc = write_packet(packet, loc, ip_length>>8);
    loc = write_packet(packet, loc, ip_length&0xff);
    /* IP id */
    loc = write_packet(packet, loc, 0x00);
    loc = write_packet(packet, loc, 0x00);
    /* IP frag_off */
    loc = write_packet(packet, loc, 0x00);
    loc = write_packet(packet, loc, 0x00);
    /* IP ttl */
    loc = write_packet(packet, loc, 0x04);
    /* IP protocol */
    loc = write_packet(packet, loc, 0x11);
    /* IP check */
    int ip_checksum_loc = loc;    /* remember for later */
    loc = write_packet(packet, loc, 0x00);
    loc = write_packet(packet, loc, 0x00);
    /* IP saddr */
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.src_ip>>24) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.src_ip>>16) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.src_ip>>8) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.src_ip>>0) & 0xff);
    /* IP daddr */
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.dest_ip>>24) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.dest_ip>>16) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.dest_ip>>8) & 0xff);
    loc = write_packet(packet, loc, (tg_port->pinfo.setup.dest_ip>>0) & 0xff);

    /* Fix the IP checksum */
    int begin_ip = get_size_l2(tg_port);
    if (tg_port->pinfo.setup.srio.u64)
        begin_ip += sizeof(tg_port->pinfo.setup.srio);
    if (tg_port->pinfo.setup.higig_mode == 1)
        begin_ip += sizeof(tg_port->pinfo.setup.higig);
    if (tg_port->pinfo.setup.higig_mode == 2)
        begin_ip += sizeof(tg_port->pinfo.setup.higig2);
    char buffer[20];
    if (packet->length >= begin_ip + (int)sizeof(buffer))
    {
        bdk_if_packet_read(packet, begin_ip, sizeof(buffer), buffer);
        uint16_t ip_checksum = ip_fast_csum(buffer, sizeof(buffer)/4);
        write_packet(packet, ip_checksum_loc, ip_checksum >> 8);
        write_packet(packet, ip_checksum_loc+1, ip_checksum);
    }

    /* UDP source port */
    loc = write_packet(packet, loc, tg_port->pinfo.setup.src_port >> 8);
    loc = write_packet(packet, loc, tg_port->pinfo.setup.src_port & 0xff);
    /* UDP destination port */
    loc = write_packet(packet, loc, tg_port->pinfo.setup.dest_port >> 8);
    loc = write_packet(packet, loc, tg_port->pinfo.setup.dest_port & 0xff);

    /* UDP length */
    int udp_length = get_size_payload(tg_port);
    loc = write_packet(packet, loc, udp_length>>8);
    loc = write_packet(packet, loc, udp_length&0xff);
    /* UDP checksum */
    loc = write_packet(packet, loc, 0x00);
    loc = write_packet(packet, loc, 0x00);

    /* Fill the rest of the packet with random bytes */
    while (loc < total_length)
        loc = write_packet(packet, loc, rand());

    if (tg_port->pinfo.setup.validate)
        is_packet_crc32c_wrong(tg_port, packet, 1);
    return 0;
}

static void dump_packet(tg_port_t *tg_port, const bdk_if_packet_t *packet)
{
    uint64_t        count;
    uint64_t        remaining_bytes;
    bdk_buf_ptr_t  buffer_ptr;
    uint64_t        start_of_buffer;
    uint8_t *       data_address;
    uint8_t *       end_of_data;

    printf("\nPacket Length:   %u\n", packet->length);
    printf("    Port:        %s\n", tg_port->pinfo.name);
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
 * Transmitter loop for generic ports. PKO based ports
 * use the optimized version below. Currently this is
 * only used for MGGMT ports.
 *
 * @param tg_port Trafficgen port to transmit on
 * @param packet  Packet to send
 * @param output_cycle_gap
 *                Gap between each packet in core cycles shifted by CYCLE_SHIFT
 */
static void packet_transmitter_generic(tg_port_t *tg_port, bdk_if_packet_t *packet, uint64_t output_cycle_gap)
{
    trafficgen_port_setup_t *port_tx = &tg_port->pinfo.setup;
    uint64_t count = port_tx->output_count;
    uint64_t output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;

    while (port_tx->output_enable)
    {
        uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
        int do_tx = cycle >= output_cycle;
        if (bdk_likely(do_tx))
        {
            output_cycle += output_cycle_gap;
            /* Only free the packet on TX if this is the last packet "i=1"
                means the packet isn't freed */
            packet->packet.s.i = (count != 1);
            if (bdk_likely(bdk_if_transmit(packet->if_handle, packet) == 0))
            {
                if (bdk_unlikely(--count == 0))
                    break;
            }
            else
            {
                /* Transmit failed. Remember we need to free the packet */
                packet->packet.s.i = 1;
                do_tx = 0;
            }
        }
        if (bdk_unlikely(!do_tx))
            bdk_thread_yield();
    }
}


/**
 * Transmitter loop for PKO ports. This is a PKO optimized
 * version of the above generic implementation.
 *
 * @param tg_port Trafficgen port to transmit on
 * @param packet  Packet to send
 * @param output_cycle_gap
 *                Gap between each packet in core cycles shifted by CYCLE_SHIFT
 */
static void packet_transmitter_pko(tg_port_t *tg_port, bdk_if_packet_t *packet, uint64_t output_cycle_gap)
{
    if (bdk_unlikely(packet->segments >= 64))
    {
        bdk_error("PKO can't transmit packets with more than 63 segments\n");
        return;
    }

    const trafficgen_port_setup_t *port_tx = &tg_port->pinfo.setup;
    const int pko_port = tg_port->handle->pko_port;
    /* Use a second queue if it exists, otherwise use the first queue */
    const int queue_offset = (sizeof(tg_port->handle->cmd_queue) > sizeof(tg_port->handle->cmd_queue[0])) ? 1 : 0;
    const int pko_queue = tg_port->handle->pko_queue + queue_offset;
    bdk_cmd_queue_state_t *cmd_queue = &tg_port->handle->cmd_queue[queue_offset];

    uint64_t count = port_tx->output_count;
    bdk_pko_command_word0_t pko_command;
    pko_command.u64 = 0;
    pko_command.s.dontfree = (count != 1);
    pko_command.s.ignore_i = 1;
    pko_command.s.segs = packet->segments;
    pko_command.s.total_bytes = packet->length;
    bdk_buf_ptr_t buf = packet->packet;
    buf.s.i = 0;

    uint64_t output_cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
    uint64_t cycle;
loop_begin:
    cycle = bdk_clock_get_count(BDK_CLOCK_CORE) << CYCLE_SHIFT;
    if (bdk_unlikely(cycle < output_cycle))
        goto idle;

    output_cycle += output_cycle_gap;
    /* Only free the packet on TX if this is the last packet "i=1"
        means the packet isn't freed */
    pko_command.s.dontfree = (count != 1);

    bdk_cmd_queue_result_t result = bdk_cmd_queue_write2(cmd_queue, 0, pko_command.u64, buf.u64);
    if (bdk_unlikely(result != BDK_CMD_QUEUE_SUCCESS))
        goto tx_failed;

    bdk_pko_doorbell(pko_port, pko_queue, 2);
    count--;

check_done:
    if (bdk_likely(port_tx->output_enable && count))
        goto loop_begin;
    packet->packet.s.i = pko_command.s.dontfree;
    return;

tx_failed:
    /* Transmit failed. Remember we need to free the packet */
    pko_command.s.dontfree = 1;
idle:
    bdk_thread_yield();
    goto check_done;
}


/**
 * Transmit loop for each port. This is started as an independent
 * thread.
 *
 * @param unused  Unused
 * @param tg_port Port to transmit on
 */
static void packet_transmitter(int unused, tg_port_t *tg_port)
{
    trafficgen_port_setup_t *port_tx = &tg_port->pinfo.setup;
    bdk_if_packet_t packet;

    packet.if_handle = tg_port->handle;
    if (build_packet(tg_port, &packet))
    {
        port_tx->output_enable = 0;
        BDK_SYNCW;
        return;
    }
    if (bdk_unlikely(tg_port->pinfo.setup.display_packet))
    {
        printf("Transmit packet:\n");
        dump_packet(tg_port, &packet);
    }

    /* Signal that this packet should not be freed */
    packet.packet.s.i = 1;

    /* Figure out my TX rate */
    int packet_rate = port_tx->output_rate;
    if (port_tx->output_rate_is_mbps)
        packet_rate = packet_rate * 125000ull / (tg_port->pinfo.setup.size + get_size_wire_overhead(tg_port));
    if (packet_rate == 0)
        packet_rate = 1;
    uint64_t output_cycle_gap = (bdk_clock_get_rate(BDK_CLOCK_CORE) << CYCLE_SHIFT) / packet_rate;

    /* Use an optimized TX routine for PKO ports. Don't do so in the simulator
        as we need software stats that aren't updated in hte optimized PKO */
    if ((tg_port->handle->pko_port != -1) && !bdk_is_simulation())
        packet_transmitter_pko(tg_port, &packet, output_cycle_gap);
    else
        packet_transmitter_generic(tg_port, &packet, output_cycle_gap);

    if (packet.packet.s.i)
    {
        /* Packet has not been freed on TX, so free it now */
        /* FIXME: What if the previous TX hasn't processed yet? */
        bdk_wait_usec(5000);
        bdk_if_free(&packet);
    }
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
static int is_packet_crc32c_wrong(tg_port_t *tg_port, bdk_if_packet_t *packet, int fix)
{
    const int FPA_SIZE = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
    uint32_t crc = 0xffffffff;
    bdk_buf_ptr_t buffer_ptr = packet->packet;

    /* Get a pointer to the beginning of the packet */
    void *ptr = bdk_phys_to_ptr(buffer_ptr.s.addr);
    int remaining_bytes = packet->length;

    /* Skip the L2 header in the CRC calculation */
    int skip = get_size_l2(tg_port);
    if (bdk_if_get_type(packet->if_handle) == BDK_IF_SRIO)
    {
        if (fix)
            skip += 8;
        else
            skip += 16;
    }
    if (bdk_if_get_type(packet->if_handle) == BDK_IF_HIGIG)
    {
        if (tg_port->pinfo.setup.higig_mode == 2)
            skip += sizeof(tg_port->pinfo.setup.higig2);
        else
            skip += sizeof(tg_port->pinfo.setup.higig);
    }
    ptr += skip;
    remaining_bytes -= skip;

    /* Skip the ethernet FCS */
    if (!fix && packet->if_handle->has_fcs)
        remaining_bytes -= 4;

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

    while (remaining_bytes > 0)
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
            {
                if (fix)
                {
                    //printf("write crc 0x%08x\n", crc);
                    *(uint32_t*)(ptr + remaining_bytes) = crc;
                    return 0;
                }
                else
                {
                    uint32_t from_packet = *(uint32_t*)(ptr + remaining_bytes);
                    //printf("crc 0x%08x, correct 0x%08x\n", from_packet, crc);
                    return (crc != from_packet);
                }
            }
            else
            {
                if (bdk_likely(buffer_bytes))
                {
                    if (fix)
                    {
                        //printf("write crc 0x%08x\n", crc);
                        memcpy(ptr + remaining_bytes, &crc, buffer_bytes);
                        /* Get a pointer to the next buffer. The rest of the CRC should
                        be at the beginning */
                        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                        memcpy(bdk_phys_to_ptr(buffer_ptr.s.addr), ((char*)&crc) + buffer_bytes, 4 - buffer_bytes);
                        return 0;
                    }
                    else
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
                        uint32_t from_packet = packet_crc1|packet_crc2;
                        //printf("crc 0x%08x, correct 0x%08x\n", from_packet, crc);
                        return (crc != from_packet);
                    }
                }
                else
                {
                    /* Get a pointer to the next buffer. The CRC should be at the beginning */
                    buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.s.addr - 8);
                    if (fix)
                    {
                        //printf("write crc 0x%08x\n", crc);
                        /* Write the CRC */
                        *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr) = crc;
                        return 0;
                    }
                    else
                    {
                        /* Read the CRC */
                        uint32_t from_packet = *(uint32_t*)bdk_phys_to_ptr(buffer_ptr.s.addr);
                        //printf("crc 0x%08x, correct 0x%08x\n", from_packet, crc);
                        return (crc != from_packet);
                    }
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

/**
 * Called by cores when they get work and need to process it.
 *
 * @param work   Work to be processed. Ideally it should already be prefetched
 *               into memory.
 */
static void tg_packet_receiver(const bdk_if_packet_t *packet, void *arg)
{
    tg_port_t *tg_port = arg;

    if (bdk_likely(tg_port->pinfo.setup.validate))
    {
        if (bdk_unlikely(is_packet_crc32c_wrong(tg_port, (bdk_if_packet_t *)packet, 0)))
            bdk_atomic_add64((int64_t*)&tg_port->pinfo.stats.rx_validation_errors, 1);
    }

    if (bdk_unlikely(tg_port->pinfo.setup.display_packet))
        dump_packet(tg_port, packet);
}


static tg_port_t *lookup_name(lua_State* L, const char *name)
{
    for (tg_port_t *tg_port = tg_port_head; tg_port!=NULL; tg_port = tg_port->next)
        if (strcasecmp(name, tg_port->pinfo.name) == 0)
            return tg_port;
    luaL_error(L, "Invalid port name %s", name);
    return NULL;
}

static int for_each_port(lua_State* L, int (*func)(tg_port_t *tg_port))
{
    luaL_checktype(L, 1, LUA_TTABLE);
    int result = 0;
    int length = luaL_len(L, 1);
    for (int count=1; count<=length; count++)
    {
        lua_pushinteger(L, count);
        lua_gettable(L, 1);
        tg_port_t *tg_port = lookup_name(L, luaL_checkstring(L, -1));
        lua_pop(L, 1);
        result |= func(tg_port);
    }
    return result;
}


/**
 *
 * @param range
 *
 * @return
 */
static int do_clear(tg_port_t *tg_port)
{
    const bdk_if_stats_t *stats = bdk_if_get_stats(tg_port->handle);
    tg_port->clear_stats = *stats;
    tg_port->delta_stats = *stats;
    memset(&tg_port->pinfo.stats, 0, sizeof(tg_port->pinfo.stats));
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
static int do_reset(tg_port_t *tg_port)
{
    uint64_t mac_addr_base = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);

    tg_port_t *connect_to = tg_port; // FIXME
    uint64_t src_mac = mac_addr_base + bdk_if_get_pknd(tg_port->handle);
    uint64_t dest_mac = mac_addr_base + bdk_if_get_pknd(connect_to->handle);
    int src_inc = bdk_if_get_pknd(tg_port->handle) << 16;
    int dest_inc = bdk_if_get_pknd(connect_to->handle) << 16;

    tg_port->pinfo.setup.output_rate                = 1000;
    tg_port->pinfo.setup.output_rate_is_mbps        = true;
    tg_port->pinfo.setup.output_enable              = 0;
    tg_port->pinfo.setup.output_count               = 0;
    tg_port->pinfo.setup.size                       = 64 - ETHERNET_CRC;
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
    return do_clear(tg_port);
}

/**
 *
 * @param range
 *
 * @return
 */
static int do_start(tg_port_t *tg_port)
{
    if (tg_port->pinfo.setup.output_enable == 0)
    {
        tg_port->pinfo.setup.output_enable = 1;
        BDK_SYNCW;
        bdk_thread_create(0, (bdk_thread_func_t)packet_transmitter, 0, tg_port, 0);
    }
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
static int do_stop(tg_port_t *tg_port)
{
    tg_port->pinfo.setup.output_enable = 0;
    BDK_SYNCW;
    return 0;
}

/**
 *
 * @param range
 *
 * @return
 */
static int do_is_transmitting(tg_port_t *tg_port)
{
    return tg_port->pinfo.setup.output_enable;
}


/**
 * Lua interface function
 * Get an array of all port names
 * Input: Nothing
 * Output: Array of port names
 *
 * @param L
 *
 * @return
 */
static int get_port_names(lua_State* L)
{
    if (!tg_port_head)
        tg_init();
    int count = 0;
    lua_newtable(L);
    for (tg_port_t *tg_port = tg_port_head; tg_port!=NULL; tg_port = tg_port->next)
    {
        lua_pushinteger(L, ++count);
        lua_pushstring(L, tg_port->pinfo.name);
        lua_settable(L, -3);
    }
    return 1;
}


/**
 * Lua interface function
 * Get the configuration of a single port
 * Input: A single port name string
 * Output: Table of setup data
 *
 * @param L
 *
 * @return
 */
static int get_config(lua_State* L)
{
    tg_port_t *tg_port = lookup_name(L, luaL_checkstring(L, 1));
    #define pushfield(field, lua_type)                      \
        lua_push##lua_type(L, tg_port->pinfo.setup.field);  \
        lua_setfield (L, -2, #field);

    lua_newtable(L);
    pushfield(output_rate,          number);
    pushfield(output_rate_is_mbps,  boolean);
    pushfield(output_enable,        boolean);
    pushfield(size,                 number);
    pushfield(output_count,         number);
    pushfield(src_mac,              number);
    pushfield(dest_mac,             number);
    pushfield(src_ip,               number);
    pushfield(dest_ip,              number);
    pushfield(ip_tos,               number);
    pushfield(src_port,             number);
    pushfield(dest_port,            number);
    pushfield(do_checksum,          boolean);
    pushfield(display_packet,       boolean);
    pushfield(validate,             boolean);
    pushfield(srio.u64,             number);
    pushfield(higig.dw0.u32,        number);
    pushfield(higig.dw1.u32,        number);
    pushfield(higig.dw2.u32,        number);
    pushfield(higig2.dw0.u32,       number);
    pushfield(higig2.dw1.u32,       number);
    pushfield(higig2.dw2.u32,       number);
    pushfield(higig2.dw3.u32,       number);
    return 1;
}


/**
 * Lua interface function
 * Set the configuration od a port. Only named paramters are changed.
 * Input: A single port name string
 * Input: Table of setup data
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int set_config(lua_State* L)
{
    tg_port_t *tg_port = lookup_name(L, luaL_checkstring(L, 1));

    #define getfield(field,  lua_type)                              \
        lua_getfield (L, 2, #field);                                \
        if (!lua_isnil(L, -1))                                      \
            tg_port->pinfo.setup.field = lua_to##lua_type(L, -1);   \
        lua_pop(L, 1);

    luaL_checktype(L, 2, LUA_TTABLE);
    getfield(output_rate,          number);
    getfield(output_rate_is_mbps,  boolean);
    getfield(output_enable,        boolean);
    getfield(size,                 number);
    getfield(output_count,         number);
    getfield(src_mac,              number);
    getfield(dest_mac,             number);
    getfield(src_ip,               number);
    getfield(dest_ip,              number);
    getfield(ip_tos,               number);
    getfield(src_port,             number);
    getfield(dest_port,            number);
    getfield(do_checksum,          boolean);
    getfield(display_packet,       boolean);
    getfield(validate,             boolean);
    getfield(srio.u64,             number);
    getfield(higig.dw0.u32,        number);
    getfield(higig.dw1.u32,        number);
    getfield(higig.dw2.u32,        number);
    getfield(higig2.dw0.u32,       number);
    getfield(higig2.dw1.u32,       number);
    getfield(higig2.dw2.u32,       number);
    getfield(higig2.dw3.u32,       number);
    BDK_SYNCW;
    return 0;
}

/**
 * Lua interface function
 * Set the loopback state of a port.
 * Input: A single port name string
 * Input: A string for loopback mode
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int set_loopback(lua_State* L)
{
    tg_port_t *tg_port = lookup_name(L, luaL_checkstring(L, 1));
    const char *loop_mode = luaL_checkstring(L, 2);

    if (strcasecmp(loop_mode, "none") == 0)
    {
        if (bdk_if_loopback(tg_port->handle, BDK_IF_LOOPBACK_NONE))
            return luaL_error(L, "Setting loopback failed");
    }
    else if (strcasecmp(loop_mode, "internal") == 0)
    {
        if (bdk_if_loopback(tg_port->handle, BDK_IF_LOOPBACK_INTERNAL))
            return luaL_error(L, "Setting loopback failed");
    }
    else if (strcasecmp(loop_mode, "external") == 0)
    {
        if (bdk_if_loopback(tg_port->handle, BDK_IF_LOOPBACK_EXTERNAL))
            return luaL_error(L, "Setting loopback failed");
    }
    else if (strcasecmp(loop_mode, "internal+external") == 0)
    {
        if (bdk_if_loopback(tg_port->handle, BDK_IF_LOOPBACK_INTERNAL_EXTERNAL))
            return luaL_error(L, "Setting loopback failed");
    }
    else
        return luaL_error(L, "Illegal loopback mode \"%s\"", loop_mode);
    return 0;
}


/**
 * Lua interface function
 * Clear the statistics for a range of ports
 * Input: Array of port names
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int clear(lua_State* L)
{
    for_each_port(L, do_clear);
    return 0;
}


/**
 * Lua interface function
 * Reset and clear a range of ports
 * Input: Array of port names
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int reset(lua_State* L)
{
    for_each_port(L, do_reset);
    return 0;
}


/**
 * Lua interface function
 * Update the statistics of all port and returns them
 * Input: clear boolean
 * Output: Table index by port name of table of stats
 *
 * @param L
 *
 * @return
 */
static int update(lua_State* L)
{
    #define pushlabel(i, field)                         \
        lua_pushnumber(L, i);                           \
        lua_pushstring(L, #field);                      \
        lua_settable(L, -3);

    #define pushstat(i, field)                          \
        lua_pushnumber(L, i);                           \
        lua_pushnumber(L, tg_port->pinfo.stats.field);  \
        lua_settable(L, -3);

    trafficgen_do_update(lua_toboolean(L, 1));

    /* This is the table that contains the entire response */
    lua_newtable(L);

    /* This table will contains the labels for the stats. It is names "labels" */
    lua_newtable(L);
    pushlabel(1, tx_packets);
    pushlabel(2, tx_octets);
    pushlabel(3, tx_packets_total);
    pushlabel(4, tx_octets_total);
    pushlabel(5, tx_bits);
    pushlabel(6, rx_packets);
    pushlabel(7, rx_octets);
    pushlabel(8, rx_packets_total);
    pushlabel(9, rx_octets_total);
    pushlabel(10, rx_dropped_octets);
    pushlabel(11, rx_dropped_packets);
    pushlabel(12, rx_errors);
    pushlabel(13, rx_bits);
    pushlabel(14, rx_backpressure);
    pushlabel(15, rx_validation_errors);
    lua_setfield(L, -2, "labels");

    /* Add stats for each interface */
    for (tg_port_t *tg_port = tg_port_head; tg_port!=NULL; tg_port = tg_port->next)
    {
        lua_newtable(L);
        pushstat(1, tx_packets);
        pushstat(2, tx_octets);
        pushstat(3, tx_packets_total);
        pushstat(4, tx_octets_total);
        pushstat(5, tx_bits);
        pushstat(6, rx_packets);
        pushstat(7, rx_octets);
        pushstat(8, rx_packets_total);
        pushstat(9, rx_octets_total);
        pushstat(10, rx_dropped_octets);
        pushstat(11, rx_dropped_packets);
        pushstat(12, rx_errors);
        pushstat(13, rx_bits);
        pushstat(14, rx_backpressure);
        pushstat(15, rx_validation_errors);
        lua_setfield(L, -2, tg_port->pinfo.name);
    }
    return 1;
}


/**
 * Lua interface function
 * Stop the supplied ports from transmitting
 * Input: Array of port names
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int stop(lua_State* L)
{
    for_each_port(L, do_stop);
    return 0;
}


/**
 * Lua interface function
 * Start the supplied ports transmitting
 * Input: Array of port names
 * Output: Nothing
 *
 * @param L
 *
 * @return
 */
static int start(lua_State* L)
{
    for_each_port(L, do_start);
    return 0;
}


/**
 * Lua interface function
 * Return a boolean of true if any of the supplied ports are transmitting
 * Input: Array of port names
 * Output: Bool, true if any of ports are transmitting
 *
 * @param L
 *
 * @return
 */
static int is_transmitting(lua_State* L)
{
    lua_pushboolean(L, for_each_port(L, do_is_transmitting));
    return 1;
}


/**
 * Initialize the trafficgen module
 *
 * @param L
 *
 * @return
 */
void register_trafficgen(lua_State *L)
{
    lua_newtable(L);
    lua_pushcfunction(L, get_port_names);
    lua_setfield(L, -2, "get_port_names");
    lua_pushcfunction(L, get_config);
    lua_setfield(L, -2, "get_config");
    lua_pushcfunction(L, set_config);
    lua_setfield(L, -2, "set_config");
    lua_pushcfunction(L, set_loopback);
    lua_setfield(L, -2, "set_loopback");
    lua_pushcfunction(L, clear);
    lua_setfield(L, -2, "clear");
    lua_pushcfunction(L, reset);
    lua_setfield(L, -2, "reset");
    lua_pushcfunction(L, update);
    lua_setfield(L, -2, "update");
    lua_pushcfunction(L, stop);
    lua_setfield(L, -2, "stop");
    lua_pushcfunction(L, start);
    lua_setfield(L, -2, "start");
    lua_pushcfunction(L, is_transmitting);
    lua_setfield(L, -2, "is_transmitting");
    lua_setfield(L, -2, "trafficgen");
}


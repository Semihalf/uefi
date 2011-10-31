#include <bdk.h>
#include <lwip/tcpip.h>
#include <lwip/inet.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(LWIP);

/**
 * Global used to track if initialization is complete.
 */
static int init_done = 0;


/**
 * Each call polls one interface and checks its link state
 *
 * @param unused
 */
static void netstack_netif_poll_link(void *unused)
{
    static bdk_if_handle_t handle = NULL;

    sys_timeout(50, netstack_netif_poll_link, NULL);

    if (bdk_if_is_configured())
        handle = bdk_if_next_port(handle);
    if (!handle)
        return;

    /* Get the link state */
    bdk_if_link_t link = bdk_if_link_get(handle);

    /* Find the netif device for this handle */
    struct netif *netif = netif_list;
    while (netif && (netif->state != handle))
        netif = netif->next;
    if (netif)
    {
        if (link.s.up)
        {
            /* Bring the link up */
            if (!netif_is_link_up(netif))
                netif_set_link_up(netif);
        }
        else
        {
            /* Bring the link up */
            if (netif_is_link_up(netif))
                netif_set_link_down(netif);
        }
    }
}


/**
 * Packet receive poll called by the tcp thread
 *
 * @param unused
 */
static void netstack_netif_rx(const bdk_if_packet_t *packet, void *arg)
{
    struct netif *netif = arg;
    struct pbuf *p = pbuf_alloc(PBUF_RAW, ETH_PAD_SIZE + packet->length, PBUF_RAM);
    if (p)
    {
        const bdk_buf_ptr_t *buf_ptr = &packet->packet;
        int to_go = packet->length;
        char *ptr = p->payload + ETH_PAD_SIZE;
        while (to_go)
        {
            const void *buf = bdk_phys_to_ptr(buf_ptr->s.addr);
            int l = (buf_ptr->s.size < to_go) ? buf_ptr->s.size : to_go;
            memcpy(ptr, buf, l);
            buf_ptr = buf - 8;
            to_go -= l;
            ptr += l;
        }
        if (netif->input(p, netif))
        {
            bdk_error("netif->input() failed\n");
            pbuf_free(p);
        }
    }
    else
        bdk_error("pbuf_alloc() failed\n");
}


/**
 * Called asynchronously by the TCP/IP stack when initialization
 * is complete.
 *
 * @param arg    Unused
 */
static void netstack_init_done(void *arg)
{
    sys_timeout(1000, netstack_netif_poll_link, NULL);
    /* This is called whe nthe TCP/IP stack is
        done with intialization */
    init_done = 1;
}


/**
 * Initialize the lwip TCP/IP stack for use
 *
 * @param flags  Flags to control initialization. Can normally be zero.
 *
 * @return Zero on success, negative on failure.
 */
int bdk_netstack_initialize(long flags)
{
    /* Do nothing if we've already been called */
    if (init_done)
        return 0;

    /* Let lwip do its magic */
    tcpip_init(netstack_init_done, NULL);

    /* Wait for the magic to complete */
    while (!init_done)
        bdk_thread_yield();
    return 0;
}


/**
 * Internal function to send a packet
 *
 * @param netif
 * @param p
 *
 * @return
 */
static err_t netstack_netif_output(struct netif *netif, struct pbuf *p)
{
    const int POOL_SIZE = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
    bdk_if_handle_t handle = netif->state;
    int total_length = p->tot_len - ETH_PAD_SIZE;

    //printf("%c%c%d: TX %d bytes\n", netif->name[0], netif->name[1], netif->num, total_length);

    bdk_if_packet_t packet;
    packet.length = 0;
    packet.segments = 0;

    /* As we change buffers the next buffer pointer will be stored in this ptr */
    bdk_buf_ptr_t *buf_ptr = &packet.packet;
    /* Location and amount of space left in the current Octeon buffer */
    void *buf = NULL;
    int buf_left = 0;
    /* Location and amount of space left in the pbuf */
    const void *ptr = p->payload + ETH_PAD_SIZE;
    int ptr_left = p->len - ETH_PAD_SIZE;

    /* Loop until we've added all bytes to the packet */
    while (packet.length < total_length)
    {
        /* Allocate a new buffer if we need more space */
        if (!buf_left)
        {
            buf = bdk_fpa_alloc(BDK_FPA_PACKET_POOL);
            if (!buf)
            {
                bdk_if_free(&packet);
                return ERR_MEM;
            }
            buf_ptr->u64 = 0;
            buf_ptr->s.pool = BDK_FPA_PACKET_POOL;
            buf_ptr->s.size = POOL_SIZE - 8;
            buf_ptr->s.addr = bdk_ptr_to_phys(buf) + 8;
            buf_ptr = (bdk_buf_ptr_t *)buf;
            packet.segments++;
            buf_left = POOL_SIZE - 8;
            buf += 8;
        }

        /* Do we need more pbuf data? */
        if (!ptr_left)
        {
            p = p->next;
            ptr = p->payload;
            ptr_left = p->len;
        }

        /* Figure out how much we can copy on this loop */
        int l = (ptr_left <= buf_left) ? ptr_left : buf_left;
        memcpy(buf, ptr, l);

        /* Update al lthe pointers and sizes */
        buf_left -= l;
        buf += l;
        ptr_left -= l;
        ptr += l;
        packet.length += l;
    }

    if (bdk_if_transmit(handle, &packet))
    {
        bdk_error("%s: bdk_if_transmit() failed\n", bdk_if_name(handle));
        bdk_if_free(&packet);
        return ERR_BUF;
    }
    else
        return ERR_OK;
}


/**
 * Internal function to setup a network interface
 *
 * @param netif
 *
 * @return
 */
static err_t netstack_netif_init(struct netif *netif)
{
    bdk_if_handle_t handle = netif->state;

    const char *name = bdk_if_name(handle);
    uint64_t mac = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);

    char *hostname = malloc(32);
    if (!hostname)
        return -1;
    snprintf(hostname, 32, "bdk-%012lx", mac);

    netif->linkoutput = netstack_netif_output;
    netif->output = etharp_output;
    netif->hwaddr_len = 6;
    netif->hwaddr[0] = (mac >> 40) & 0xff;
    netif->hwaddr[1] = (mac >> 32) & 0xff;
    netif->hwaddr[2] = (mac >> 24) & 0xff;
    netif->hwaddr[3] = (mac >> 16) & 0xff;
    netif->hwaddr[4] = (mac >> 8)  & 0xff;
    netif->hwaddr[5] = (mac >> 0)  & 0xff;
    netif->mtu = 1500;
    strncpy(netif->name, name, sizeof(netif->name));
    netif->num = handle->index; // FIXME: Don't directly index handle
    netif->flags |= NETIF_FLAG_BROADCAST | NETIF_FLAG_ETHARP | NETIF_FLAG_ETHERNET;
    netif->hostname = hostname;
    return ERR_OK;
}

static struct netif *netstack_find_by_name(const char *name, int allow_add)
{
    struct netif *netif = netif_list;

    /* Search for an existing netif */
    while (netif)
    {
        bdk_if_handle_t handle = netif->state;
        if (handle && (strcasecmp(name, bdk_if_name(handle)) == 0))
            return netif;
        netif = netif->next;
    }

    if (!allow_add)
        return NULL;

    /* Search for a bdk_if that matches the name but hasn't been connected to
        the stack yet */
    for (bdk_if_handle_t handle=bdk_if_next_port(NULL); handle != NULL; handle=bdk_if_next_port(handle))
    {
        if (strcasecmp(name, bdk_if_name(handle)))
            continue;

        netif = calloc(sizeof(struct netif), 1);
        if (!netif)
        {
            bdk_error("netstack_find_by_name: Out of memory\n");
            return NULL;
        }

        ip_addr_t ipaddr = {0x0a000002};
        ip_addr_t netmask = {0xffffff00};
        ip_addr_t gw = {0x0a000001};

        if (netifapi_netif_add(netif, &ipaddr, &netmask, &gw, handle, netstack_netif_init, tcpip_input))
        {
            bdk_error("netstack_find_by_name: netifapi_netif_add failed\n");
            free(netif);
            return NULL;
        }
        return netif;
    }
    bdk_error("netstack_find_by_name: Network interface not found\n");
    return NULL;
}


/**
 * Configure an interface for use with TCP/IP. The interface must
 * have already been added using bdk_netstack_if_add*.
 *
 * @param name    Name of the interface to configure. Case doesn't matter.
 * @param ip      IP address in "x.x.x.x" notation, the word "dhcp", or the word
 *                "auto".
 * @param netmask Netmask in the form of "x.x.x.x" or "/x". Only used if ip
 *                is static.
 * @param gw      Default gateway in the form of "x.x.x.x". Only used if ip
 *                is static.
 *
 * @return Zero on success, negative on failure.
 */
int bdk_netstack_if_configure(const char *name, const char *ip, const char *netmask, const char *gw)
{
    struct netif *netif = netstack_find_by_name(name, 1);
    if (!netif)
        return -1;

    bdk_if_register_for_packets(netif->state, netstack_netif_rx, netif);
    bdk_if_enable(netif->state);
    if (strcasecmp(ip, "dhcp") == 0)
    {
        netifapi_netif_set_default(netif);
        netifapi_dhcp_start(netif);
    }
    else if (strcasecmp(ip, "auto") == 0)
    {
        netifapi_autoip_start(netif);
    }
    else
    {
        ip_addr_t c_ipaddr = {inet_addr(ip)};
        ip_addr_t c_netmask = {inet_addr(netmask)};
        ip_addr_t c_gw = {inet_addr(gw)};
        if (netmask[0] == '/')
        {
            int bits = atoi(netmask + 1);
            c_netmask.addr = -1 << (32 - bits);
        }
        netifapi_netif_set_addr(netif, &c_ipaddr, &c_netmask, &c_gw);
        netifapi_netif_set_up(netif);
    }

    return 0;
}


/**
 * Get the IP address of an interface
 *
 * @param name   Name of interface
 *
 * @return IP address
 */
uint32_t bdk_netstack_if_get_ip(const char *name)
{
    struct netif *netif = netstack_find_by_name(name, 0);
    if (netif && netif_is_up(netif))
        return netif->ip_addr.addr;
    else
        return 0;
}


/**
 * Get the Netmask of an interface
 *
 * @param name   Name of interface
 *
 * @return Netmask
 */
uint32_t bdk_netstack_if_get_netmask(const char *name)
{
    struct netif *netif = netstack_find_by_name(name, 0);
    if (netif)
        return netif->netmask.addr;
    else
        return 0;
}


/**
 * Get the default gateway of an interface
 *
 * @param name   Name of interface
 *
 * @return default gateway
 */
uint32_t bdk_netstack_if_get_gw(const char *name)
{
    struct netif *netif = netstack_find_by_name(name, 0);
    if (netif)
        return netif->gw.addr;
    else
        return 0;
}


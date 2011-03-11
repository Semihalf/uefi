#include <bdk.h>
#include <lwip/tcpip.h>

/**
 * Global used to track if initialization is complete.
 */
static int init_done = 0;


/**
 * Packet receive poll called by the tcp thread
 *
 * @param unused
 */
static void netstack_netif_rx(void *unused)
{
    bdk_if_packet_t packet;
    while (bdk_if_receive(&packet) == 0)
    {
        struct netif *netif = netif_list;
        while (netif && (netif->state != packet.if_handle))
            netif = netif->next;
        if (netif)
        {
            struct pbuf *p = pbuf_alloc(PBUF_RAW, ETH_PAD_SIZE + packet.length, PBUF_RAM);
            if (p)
            {
                const bdk_buf_ptr_t *buf_ptr = &packet.packet;
                int to_go = packet.length;
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
        bdk_if_free(&packet);
    }

    bdk_thread_yield();
    tcpip_callback(netstack_netif_rx, NULL);
}


/**
 * Called asynchronously by the TCP/IP stack when initialization
 * is complete.
 *
 * @param arg    Unused
 */
static void netstack_init_done(void *arg)
{
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

    /* Make sure bdk_if is setup */
    if (bdk_if_init())
        return -1;

    /* Let lwip do its magic */
    tcpip_init(netstack_init_done, NULL);

    /* Wait for the magic to complete */
    while (!init_done)
        bdk_thread_yield();

    tcpip_callback(netstack_netif_rx, NULL);
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
    const int pool_size = bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL);
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
            buf_ptr->s.size = pool_size - 8;
            buf_ptr->s.addr = bdk_ptr_to_phys(buf) + 8;
            buf_ptr = (bdk_buf_ptr_t *)buf;
            packet.segments++;
            buf_left = pool_size - 8;
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

    /* Bring the link up */
    netif_set_default(netif);
    netif_set_link_up(netif);
    netif_set_up(netif);
    bdk_if_enable(handle);
    //dhcp_start(netif);
    return ERR_OK;
}


/**
 * Internal function to add a bdk_if interface to the TCP/IP stack
 *
 * @param handle bdk_if interface to add
 * @param flags  Optional flags
 *
 * @return Zero on success, egative on failure
 */
static int netstack_if_add(bdk_if_handle_t handle, long flags)
{
    struct netif *netif = calloc(sizeof(struct netif), 1);
    if (!netif)
        return -1;

    ip_addr_t ipaddr = {0x0a000001};
    ip_addr_t netmask = {0xffffff00};
    ip_addr_t gw = {0x0a000002};

    if (netifapi_netif_add(netif, &ipaddr, &netmask, &gw, handle, netstack_netif_init, tcpip_input))
    {
        bdk_error("netifapi_netif_add failed\n");
        return -1;
    }
    return 0;
}


/**
 * Function to add a bdk_if interface to the TCP/IP stack
 *
 * @param name   Name of the interface to add. Case doesn't matter.
 * @param flags  Optional flags
 *
 * @return Zero on success, egative on failure
 */
int bdk_netstack_if_add(const char *name, long flags)
{
    for (bdk_if_handle_t handle=bdk_if_next_port(NULL); handle != NULL; handle=bdk_if_next_port(handle))
    {
        if (strcasecmp(name, bdk_if_name(handle)) == 0)
            return netstack_if_add(handle, flags);
    }
    /* Not found */
    return -1;
}


/**
 * Function to add all bdk_if interfaces to the TCP/IP stack.
 *
 * @param flags  Optional flags
 *
 * @return Zero on success, egative on failure
 */
int bdk_netstack_if_add_all(long flags)
{
    for (bdk_if_handle_t handle=bdk_if_next_port(NULL); handle != NULL; handle=bdk_if_next_port(handle))
    {
        switch (bdk_if_get_type(handle))
        {
            case BDK_IF_SGMII:
            case BDK_IF_XAUI:
            case BDK_IF_MGMT:
            case BDK_IF_ILK:
                if (netstack_if_add(handle, flags))
                    return -1;
                break;
            case BDK_IF_DPI:    /* Requires extra host setup */
            case BDK_IF_LOOP:   /* Useless in this context */
            case BDK_IF_SRIO:   /* We don't handle the headers correctly yet */
            case __BDK_IF_LAST: /* Needed to supress warning */
                /* Skip */
                break;
        }
    }
    return 0;
}


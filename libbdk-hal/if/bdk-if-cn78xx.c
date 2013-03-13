#include <bdk.h>
#include <stdio.h>
#include <malloc.h>

#define PIP_IP_OFFSET 2
static __bdk_if_port_t *__bdk_if_ipd_map[0x1000];

/**
 * One time init of global Packet Input
 *
 * @return Zero on success, negative on failure
 */
static int pki_global_init(void)
{
    return 0;
}

/**
 * Configure packet input for a specific port. This is called for each
 * port on every interface that is connected to packet input.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pki_port_init(bdk_if_handle_t handle)
{
    static int qos = 0;
    /* Have the next port use a different input queue */
    qos = (qos + 1) & 7;
    return 0;
}

/**
 * Enable PKI after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pki_enable(void)
{
    return 0;
}

/**
 * Perform global init of PKO
 *
 * @return Zero on success, negative on failure
 */
static int pko_global_init(void)
{
    return 0;
}

/**
 * Configure PKO for a specific port. This is called for each
 * port on every interface that connects to PKO.
 *
 * @param handle Handle for port to config
 *
 * @return Zero on success, negative on failure
 */
static int pko_port_init(bdk_if_handle_t handle)
{
    return 0;
}

/**
 * Enable PKO after all setup is complete
 *
 * @return Zero on success, negative on failure
 */
static int pko_enable(void)
{
    return 0;
}

/**
 * Initialize the SSO
 *
 * @return Zero on success, negative on failure
 */
static int sso_init(void)
{
    int grp;

    /* Setup an FPA pool to store the SSO queues */
    const int MAX_SSO_ENTRIES = 4096;
    int num_blocks = 256 + 48 + ((MAX_SSO_ENTRIES+25)/26);
    if (bdk_fpa_fill_pool(BDK_FPA_SSO_POOL, num_blocks))
        return -1;
    int aura = BDK_FPA_SSO_POOL; /* Use 1:1 mapping aura */

    /* Initialize the 256 group/qos queues */
    for (grp=0; grp<256; grp++)
    {
        void *buffer = bdk_fpa_alloc(aura);
        if (buffer == NULL)
        {
            bdk_error("sso_init: Failed to allocate buffer\n");
            return -1;
        }
        uint64_t addr = bdk_ptr_to_phys(buffer);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_HEAD_PTR(grp),
            c.s.ptr = addr;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_HEAD_NEXT(grp),
            c.s.ptr = addr);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_TAIL_PTR(grp),
            c.s.ptr = addr;
            c.s.cl = 0);
        BDK_CSR_MODIFY(c, BDK_SSO_XAQX_TAIL_NEXT(grp),
            c.s.ptr = addr);
        /* Prefetch one cache line into L1 when a core gets work */
        BDK_CSR_MODIFY(c, BDK_SSO_GRPX_PREF(grp),
            c.s.clines = 1);
    }
    /* Set the aura number */
    BDK_CSR_MODIFY(c, BDK_SSO_XAQ_AURA,
        c.s.aura = aura);
    /* Set work timeout to 1k cycles */
    BDK_CSR_MODIFY(c, BDK_SSO_NW_TIM,
        c.s.nw_tim = 0);
    /* Setup how the SSO accesses memory */
    BDK_CSR_MODIFY(c, BDK_SSO_AW_CFG,
        c.s.rwen = 1);
    return 0;
}

/**
 * Convert a WQE into a BDK packet
 *
 * @param work   Pointer to WQE to convert
 * @param packet Packet to receive the data
 *
 * @return Zero on success, negative on failure
 */
static int sso_wqe_to_packet(const void *work, bdk_if_packet_t *packet)
{
    const bdk_wqe_t *wqe = work;

    /* Get the IPD port number */
    int ipd_port = wqe->word1.v1.ipprt;

    packet->if_handle = __bdk_if_ipd_map[ipd_port];
    packet->length = wqe->word1.v3.len;
    if (bdk_unlikely(wqe->word2.v3.errlev || wqe->word2.v3.opcode))
        packet->rx_error = wqe->word2.u64 & 0x7ff;
    else
        packet->rx_error = 0;

    if (bdk_likely(wqe->word0.v3.bufs == 0))
    {
        packet->segments = 1;
        packet->packet.u64 = 0;
        packet->packet.v3.size = 128; // FIXME packet size
        packet->packet.v3.addr = bdk_ptr_to_phys((void*)wqe->packet_data);
        if (bdk_likely(!wqe->word2.v1.ni)) // FIXME
        {
            packet->packet.v3.addr += (PIP_IP_OFFSET<<3) - wqe->word2.v1.ip_offset;
            packet->packet.v3.addr += (wqe->word2.v1.v6^1)<<2;
        }
        else
        {
            /* WARNING: This code assume that the packet is not RAW. If it was,
                we would use PIP_GBL_CFG[RAW_SHF] instead of
                PIP_GBL_CFG[NIP_SHF] */
            BDK_CSR_INIT(pip_gbl_cfg, BDK_PIP_GBL_CFG);
            packet->packet.v3.addr += pip_gbl_cfg.s.nip_shf;
        }
    }
    else
    {
        packet->segments = wqe->word0.v3.bufs;
        packet->packet = wqe->packet_ptr;
    }

    if (bdk_unlikely(!packet->if_handle))
    {
        bdk_error("Unable to find IF for ipd_port %d\n", ipd_port);
        bdk_if_free(packet);
        return -1;
    }
    return 0;
}

/**
 * Send a packet
 *
 * @param handle Handle of port to send on
 * @param packet Packet to send
 *
 * @return Zero on success, negative on failure
 */
static int pko_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return -1;
}

/**
 * Allocate a packet with buffers for the supplied amount of data
 *
 * @param packet Packet to get buffers for
 * @param length Length of the final packet in bytes
 *
 * @return Zero on success, negative on failure.
 */
static int packet_alloc(bdk_if_packet_t *packet, int length)
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
        buffer_ptr->v3.size = FPA_SIZE - 8;
        buffer_ptr->v3.addr = bdk_ptr_to_phys(buffer) + 8;
        packet->length += FPA_SIZE - 8;
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
 * Free a packet back to the FPA pools
 *
 * @param packet Packet to free. Only the data is freed. The bdk_if_packet_t structure
 *               is not freed.
 */
static void packet_free(bdk_if_packet_t *packet)
{
    int aura = 0; // FIXME
    int number_buffers = packet->segments;
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    bdk_buf_ptr_t next_buffer_ptr;
    BDK_SYNCW;
    while (number_buffers--)
    {
        /* Read pointer to next buffer before we free the current buffer. */
        if (number_buffers)
            next_buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
        __bdk_fpa_raw_free(buffer_ptr.v3.addr, aura, 0);
        buffer_ptr = next_buffer_ptr;
    }
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
static void packet_read(bdk_if_packet_t *packet, int location, int length, void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to read past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v3.size)
    {
        location -= buffer_ptr.v3.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
    }

    const uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
    uint8_t *out_data = data;
    while (length > 0)
    {
        *out_data = ptr[location];
        out_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v3.size))
        {
            location -= buffer_ptr.v3.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
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
static void packet_write(bdk_if_packet_t *packet, int location, int length, const void *data)
{
    if (location + length > packet->length)
        bdk_fatal("Attempt to write past the end of a packet\n");

    /* Skip till we get the buffer containing the start location */
    bdk_buf_ptr_t buffer_ptr = packet->packet;
    while (location >= buffer_ptr.v3.size)
    {
        location -= buffer_ptr.v3.size;
        buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
    }

    uint8_t *ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
    const uint8_t *in_data = data;
    while (length > 0)
    {
        ptr[location] = *in_data;
        in_data++;
        location++;
        length--;
        if (length && (location >= buffer_ptr.v3.size))
        {
            location -= buffer_ptr.v3.size;
            buffer_ptr = *(bdk_buf_ptr_t*)bdk_phys_to_ptr(buffer_ptr.v3.addr - 8);
            ptr = bdk_phys_to_ptr(buffer_ptr.v3.addr);
        }
    }
}

__bdk_if_global_ops_t __bdk_if_global_ops_cn78xx = {
    .pki_global_init = pki_global_init,
    .pki_port_init = pki_port_init,
    .pki_enable = pki_enable,
    .pko_global_init = pko_global_init,
    .pko_port_init = pko_port_init,
    .pko_enable = pko_enable,
    .sso_init = sso_init,
    .sso_wqe_to_packet = sso_wqe_to_packet,
    .pko_transmit = pko_transmit,
    .packet_alloc = packet_alloc,
    .packet_free = packet_free,
    .packet_read = packet_read,
    .packet_write = packet_write,
};


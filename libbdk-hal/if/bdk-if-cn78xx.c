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
    packet->length = wqe->word1.s.len;
    if (bdk_unlikely(wqe->word2.s.re))
        packet->rx_error = wqe->word2.s.opcode;
    else
        packet->rx_error = 0;

    if (bdk_likely(wqe->word2.s.bufs == 0))
    {
        packet->segments = 1;
        packet->packet.u64 = 0;
        packet->packet.s.back = 0;
        packet->packet.s.pool = BDK_FPA_PACKET_POOL;
        packet->packet.s.size = 128; // FIXME packet size
        packet->packet.s.addr = bdk_ptr_to_phys((void*)wqe->packet_data);
        if (bdk_likely(!wqe->word2.s.ni))
        {
            packet->packet.s.addr += (PIP_IP_OFFSET<<3) - wqe->word2.ip.ip_offset;
            packet->packet.s.addr += (wqe->word2.ip.v6^1)<<2;
        }
        else
        {
            /* WARNING: This code assume that the packet is not RAW. If it was,
                we would use PIP_GBL_CFG[RAW_SHF] instead of
                PIP_GBL_CFG[NIP_SHF] */
            BDK_CSR_INIT(pip_gbl_cfg, BDK_PIP_GBL_CFG);
            packet->packet.s.addr += pip_gbl_cfg.s.nip_shf;
        }
    }
    else
    {
        packet->segments = wqe->word2.s.bufs;
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

static int pko_transmit(bdk_if_handle_t handle, bdk_if_packet_t *packet)
{
    return -1;
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
};


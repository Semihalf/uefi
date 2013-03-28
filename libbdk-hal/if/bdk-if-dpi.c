#include <bdk.h>

static int if_num_interfaces(bdk_node_t node)
{
    return 0; /* FIXME: Change number of DPI interfaces to 1 once they are supported */
}

static int if_num_ports(bdk_node_t node, int interface)
{
    return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0x100 - 0x11f */
        handle->ipd_port = 0x100 + handle->index;
    }
    else
    {
        /* Use IPD ports 32 - 35 */
        handle->ipd_port = 32 + handle->index;
    }
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        static int base_pipe = -1;
        static int pko_eid = -1;
        if (base_pipe == -1)
        {
            base_pipe = __bdk_pko_alloc_pipe(handle->node, if_num_ports(handle->node, handle->interface));
            pko_eid = __bdk_pko_alloc_engine(handle->node);
        }
        /* Configure the PKO internal port mappings */
        if (handle->index == 0)
            BDK_CSR_MODIFY(c, handle->node, BDK_SLI_TX_PIPE,
                c.s.nump = if_num_ports(handle->node, handle->interface);
                c.s.base = base_pipe);

        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff;     /* QOS rounds */
        ptrs.s.crc = 0;             /* No CRC on packets */
        ptrs.s.min_pkt = 0;         /* No min packet */
        ptrs.s.pipe = base_pipe+handle->index;  /* Which PKO pipe */
        ptrs.s.intr = 30;           /* Which interface */
        ptrs.s.eid = pko_eid;       /* Which engine */
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Setup PKIND and BPID */
        BDK_CSR_MODIFY(c, handle->node, BDK_SLI_PORTX_PKIND(handle->index),
            c.s.bpkind = handle->pknd;
            c.s.pkind = handle->pknd);
    }
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    /* Enables are controlled by the remote host, so nothing to do here */
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    /* Enables are controlled by the remote host, so nothing to do here */
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    bdk_if_link_t result;
    result.u64 = 0;
    // FIXME: Link info for DPI
    return result;
}

const __bdk_if_ops_t __bdk_if_ops_dpi = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


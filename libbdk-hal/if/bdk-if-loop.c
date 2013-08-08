#include <bdk.h>

static int if_num_interfaces(bdk_node_t node)
{
    return 1;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 8;
    else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 4;
    else
        return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Change name to be "LOOP" with a single number */
    if (bdk_numa_is_only_one())
        snprintf(handle->name, sizeof(handle->name), "LOOP%d", handle->index);
    else
        snprintf(handle->name, sizeof(handle->name), "N%d.LOOP%d", handle->node, handle->index);
    handle->name[sizeof(handle->name)-1] = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
    {
        /* Use PKI_CHAN_E channel numbers 0 - 63 */
        handle->ipd_port = handle->index;
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0 - 7 */
        handle->ipd_port = handle->index;
    }
    else
    {
        /* Use IPD ports 36 - 39 */
        handle->ipd_port = 36 + handle->index;
    }

    return 0;
}

static int if_init_cn78xx(bdk_if_handle_t handle)
{
    const int MAC_NUMBER = 0x0; /* Constant from cn78xx */
    if (handle->index == 0)
    {
        BDK_CSR_MODIFY(c, handle->node, BDK_PKO_MACX_CFG(MAC_NUMBER),
            c.s.fcs_ena = 0; /* No FCS */
            c.s.fcs_sop_off = 0; /* No FCS offset */
            c.s.skid_max_cnt = 2); /* All credits to one MAC */
    }
    /* Record the PKND for this port */
    BDK_CSR_MODIFY(c, handle->node, BDK_LBK_CHX_PKIND(handle->index),
        c.s.pkind = handle->pknd);
    return 0;
}

static int if_init_cn68xx(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);

    static int pko_eid = -1;
    if (pko_eid == -1)
        pko_eid = __bdk_pko_alloc_engine(handle->node);

    /* Configure the PKO internal port mappings */
    if (handle->index == 0)
        BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
            t.s.num_ports = if_num_ports(handle->node, handle->interface));

    BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
    ptrs.u64 = 0;
    ptrs.s.qos_mask = 0xff; /* QOS rounds */
    ptrs.s.crc = 0;         /* No CRC on packets */
    ptrs.s.min_pkt = 0;     /* No min packet */
    ptrs.s.pipe = handle->index; /* Which loop */
    ptrs.s.intr = 31;       /* Which interface */
    ptrs.s.eid = pko_eid;   /* Which engine */
    ptrs.s.ipid = handle->pko_port;
    BDK_CSR_WRITE(handle->node, BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

    /* Setup the PKIND and BPID for this loopback port */
    switch (handle->index)
    {
        case 0:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind0 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid0 = handle->pknd);
            break;
        case 1:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind1 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid1 = handle->pknd);
            break;
        case 2:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind2 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid2 = handle->pknd);
            break;
        case 3:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind3 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid3 = handle->pknd);
            break;
        case 4:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind4 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid4 = handle->pknd);
            break;
        case 5:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind5 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid5 = handle->pknd);
            break;
        case 6:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind6 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid6 = handle->pknd);
            break;
        case 7:
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.pkind7 = handle->pknd);
            BDK_CSR_MODIFY(t, handle->node, BDK_PKO_REG_LOOPBACK_BPID,
                t.s.bpid7 = handle->pknd);
            break;
    }
    return 0;
}

static int if_init_cn6xxx(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return if_init_cn78xx(handle);
    else if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return if_init_cn68xx(handle);
    else
        return if_init_cn6xxx(handle);
}

static int if_enable(bdk_if_handle_t handle)
{
    return 0;
}

static int if_disable(bdk_if_handle_t handle)
{
    return 0;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    bdk_if_link_t result;
    result.u64 = 0;
    result.s.speed = 10000;
    result.s.full_duplex = 1;
    result.s.up = 1;

    return result;
}

const __bdk_if_ops_t __bdk_if_ops_loop = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


#include <bdk.h>

static int if_num_interfaces(bdk_node_t node)
{
    return 1;
}

static int if_num_ports(bdk_node_t node, int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
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

static int if_loopback(bdk_if_handle_t handle, bdk_if_loopback_t loopback)
{
    return 0;
}

const __bdk_if_ops_t __bdk_if_ops_loop = {
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_loopback = if_loopback,
};


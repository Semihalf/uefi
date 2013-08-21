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
    /* Use IPD ports 32 - 35 */
    handle->ipd_port = 32 + handle->index;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, handle->node, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);
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


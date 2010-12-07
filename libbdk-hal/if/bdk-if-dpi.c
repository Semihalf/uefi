#include <bdk.h>

static int if_init(bdk_if_handle_t handle)
{
    int pknd = bdk_if_get_pknd(handle);

    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, BDK_PIP_PRT_CFGX(pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0;);
    return 0;
}

static int if_num_interfaces(void)
{
    return 1;
}

static int if_num_ports(int interface)
{
    return 4;
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

static bdk_if_link_t if_link_autoconf(bdk_if_handle_t handle)
{
    return if_link_get(handle);
}

__bdk_if_ops_t __bdk_if_ops_dpi = {
    .if_init = if_init,
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
    .if_link_autoconf = if_link_autoconf,
    .if_transmit = __bdk_if_transmit_pko,
    .if_receive = __bdk_if_receive_sso,
};


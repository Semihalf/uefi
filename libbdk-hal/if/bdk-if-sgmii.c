#include <bdk.h>

static int if_init(bdk_if_handle_t handle)
{
    return -1;
}

static int if_num_interfaces(void)
{
    int num = 0;

    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        BDK_CSR_INIT(mode, BDK_GMXX_INF_MODE(0));
        if (mode.cn63xx.mode == 0)
            num++;
    }
    return num;
}

static int if_num_ports(int interface)
{
    return 0;
}

static int if_enable(bdk_if_handle_t handle)
{
    return -1;
}

static int if_disable(bdk_if_handle_t handle)
{
    return -1;
}

static bdk_if_link_t if_link_get(bdk_if_handle_t handle)
{
    bdk_if_link_t result;
    result.u64 = 0;
    return result;
}

static bdk_if_link_t if_link_autoconf(bdk_if_handle_t handle)
{
    return if_link_get(handle);
}

__bdk_if_ops_t __bdk_if_ops_sgmii = {
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


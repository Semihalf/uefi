#include <bdk.h>

static int if_num_interfaces(void)
{
    return 1;
}

static int if_num_ports(int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
        return 4;
    else
        return 8;
}

static int if_init(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        handle->ipd_port = 36 + handle->index;
        handle->pko_port = 36 + handle->index;

        /* We need to disable length checking so packet < 64 bytes and jumbo
            frames don't get errors */
        BDK_CSR_MODIFY(port_cfg, BDK_PIP_PRT_CFGX(handle->ipd_port),
                port_cfg.s.maxerr_en = 0;
                port_cfg.s.minerr_en = 0);

        /* Disable FCS stripping for loopback ports */
            BDK_CSR_MODIFY(ipd_sub_port_fcs, BDK_IPD_SUB_PORT_FCS,
                ipd_sub_port_fcs.s.port_bit2 &= 1<< handle->index);
    }
    else
    {
        handle->ipd_port = handle->index;
        handle->pko_port = 64 + handle->index;
    }

    return 0;
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
    .name = "LOOP",
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


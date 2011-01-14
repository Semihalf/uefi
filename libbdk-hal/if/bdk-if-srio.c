#include <bdk.h>

static int if_num_interfaces(void)
{
    int num = 0;
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        for (int i=0; i<2; i++)
        {
            bdk_sriox_status_reg_t sriox_status_reg;
            sriox_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(0));
            if (sriox_status_reg.s.srio)
                num++;
        }
    }
    return num;
}

static int if_num_ports(int interface)
{
    return 2;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Use IPD ports 40 - 41, 42 - 43 */
    handle->ipd_port = handle->index + handle->interface*2 + 40;
    /* PKO ports are the same as IPD */
    handle->pko_port = handle->ipd_port;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
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

const __bdk_if_ops_t __bdk_if_ops_srio = {
    .name = "SRIO",
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


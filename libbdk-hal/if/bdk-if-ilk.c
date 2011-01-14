#include <bdk.h>

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(1));

        /* Force simulator QLM1 to be ILK. This allows us to have virtual ILK
            interfaces even though the simulator doesn't implement the QLM
            config */
        if (bdk_is_simulation())
            qlm_cfg.s.qlm_cfg = 1;

        /* For any ILK, QLM1 must be in the right mode. It isn't legal
            to have QLM2 ILK and QLM1 not be ILK */
        return (qlm_cfg.s.qlm_cfg == 1) ? 2 : 0;
    }
    else
        return 0;
}

static int if_num_ports(int interface)
{
    BDK_CSR_INIT(qlm_cfg, BDK_MIO_QLMX_CFG(2));

    /* Force simulator QLM1 to be ILK. This allows us to have virtual ILK
        interfaces even though the simulator doesn't implement the QLM
        config */
    if (bdk_is_simulation())
        qlm_cfg.s.qlm_cfg = 1;

    /* See how many lanes we can potentially have. We already checked QLM1
        when probing the inteface number, now we check QLM2 */
    int max_lanes = (qlm_cfg.s.qlm_cfg == 1) ? 8 : 4;

    /* In ILK interface only exists if there are lanes configured for it */
    int lanes_interface0 = bdk_config_get(BDK_CONFIG_ILK0_LANES);
    int lanes_interface1 = bdk_config_get(BDK_CONFIG_ILK1_LANES);

    if (interface == 0)
    {
        if (lanes_interface0 > max_lanes)
        {
            bdk_error("ILK1 configured for more lanes that are available\n");
            return 0;
        }
    }
    else
    {
        if (lanes_interface0 + lanes_interface1 > max_lanes)
        {
            bdk_error("ILK1 configured for more lanes that are available\n");
            return 0;
        }
    }

    /* User must have configured the number of ports */
    return bdk_config_get(BDK_CONFIG_ILK0_PORTS + interface);
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Use IPD ports 0 - 7 */
    handle->ipd_port = 0x400 + handle->interface*0x100 + handle->index;
    /* Use PKO ports 72+ */
    handle->pko_port = 72 + handle->interface*bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface) + handle->index;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    if (handle->index == 0)
    {
        int lane_mask = (1 << bdk_config_get(BDK_CONFIG_ILK0_LANES + handle->interface)) - 1;
        if (handle->interface)
            lane_mask <<= bdk_config_get(BDK_CONFIG_ILK0_LANES);

        int channels = bdk_config_get(BDK_CONFIG_ILK0_PORTS + handle->interface);

        /* Set jabber to allow max sized packets */
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_JABBER(handle->interface),
            c.s.cnt = 0xfff8);

        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask);
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
            c.s.pkt_ena = 1;
            c.s.rx_bdry_lock_ena = 1);
        BDK_CSR_MODIFY(c, BDK_ILK_TXX_CFG0(handle->interface),
            c.s.lane_ena = lane_mask);
        BDK_CSR_MODIFY(c, BDK_ILK_RXX_CFG1(handle->interface),
            c.s.pkt_ena = 1);
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

const __bdk_if_ops_t __bdk_if_ops_ilk = {
    .name = "ILK",
    .if_num_interfaces = if_num_interfaces,
    .if_num_ports = if_num_ports,
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


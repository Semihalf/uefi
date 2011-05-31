#include <bdk.h>

static int if_num_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
        for (int i=0; i<2; i++)
        {
            BDK_CSR_INIT(sriox_status_reg, BDK_SRIOX_STATUS_REG(i));
            if (sriox_status_reg.s.srio)
                bdk_srio_initialize(i, 0);
        }
        return 2;
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN66XX))
    {
        for (int i=0; i<4; i++)
        {
            BDK_CSR_INIT(sriox_status_reg, BDK_SRIOX_STATUS_REG(i));
            if (sriox_status_reg.s.srio)
                bdk_srio_initialize(i, 0);
        }
        return 4;
    }
    else
        return 0;
}

static int if_num_ports(int interface)
{
    BDK_CSR_INIT(sriox_status_reg, BDK_SRIOX_STATUS_REG(interface));
    if (sriox_status_reg.s.srio)
        return 2;
    else
        return 0;
}

static int if_probe(bdk_if_handle_t handle)
{
    /* Use IPD ports 40 - 41, 42 - 43, 44 - 45, 46 - 47 */
    handle->ipd_port = handle->index + handle->interface*2 + 40;
    /* PKO ports are the same as IPD */
    handle->pko_port = handle->ipd_port;
    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* SRIO ports have a bdk_srio_rx_message_header_t header
        on them that must be skipped by IPD */
    BDK_CSR_MODIFY(c, BDK_PIP_PRT_CFGX(handle->pknd),
        c.s.skip = sizeof(bdk_srio_rx_message_header_t));

    /* Enable TX with PKO */
    BDK_CSR_MODIFY(c, BDK_SRIOX_OMSG_PORTX(handle->index, handle->interface),
        c.s.port = handle->interface * 2 + (handle->index&1);
        c.s.enable = 1);

    /* Allow OMSG controller to send regardless of the state of any other
        controller. Allow messages to different IDs and MBOXes to go in
        parallel */
    BDK_CSR_DEFINE(sriox_omsg_sp_mrx, BDK_SRIOX_OMSG_SP_MRX(handle->index, handle->interface));
    sriox_omsg_sp_mrx.u64 = 0;
    sriox_omsg_sp_mrx.s.xmbox_sp = 1;
    sriox_omsg_sp_mrx.s.ctlr_sp = 1;
    sriox_omsg_sp_mrx.s.ctlr_fmp = 1;
    sriox_omsg_sp_mrx.s.ctlr_nmp = 1;
    sriox_omsg_sp_mrx.s.id_sp = 1;
    sriox_omsg_sp_mrx.s.id_fmp = 1;
    sriox_omsg_sp_mrx.s.id_nmp = 1;
    sriox_omsg_sp_mrx.s.mbox_sp = 1;
    sriox_omsg_sp_mrx.s.mbox_fmp = 1;
    sriox_omsg_sp_mrx.s.mbox_nmp = 1;
    sriox_omsg_sp_mrx.s.all_psd = 1;
    BDK_CSR_WRITE(BDK_SRIOX_OMSG_SP_MRX(handle->index, handle->interface), sriox_omsg_sp_mrx.u64);

    /* Allow OMSG controller to send regardless of the state of any other
        controller. Allow messages to different IDs and MBOXes to go in
        parallel */
    BDK_CSR_DEFINE(sriox_omsg_fmp_mrx, BDK_SRIOX_OMSG_FMP_MRX(handle->index, handle->interface));
    sriox_omsg_fmp_mrx.u64 = 0;
    sriox_omsg_fmp_mrx.s.ctlr_sp = 1;
    sriox_omsg_fmp_mrx.s.ctlr_fmp = 1;
    sriox_omsg_fmp_mrx.s.ctlr_nmp = 1;
    sriox_omsg_fmp_mrx.s.id_sp = 1;
    sriox_omsg_fmp_mrx.s.id_fmp = 1;
    sriox_omsg_fmp_mrx.s.id_nmp = 1;
    sriox_omsg_fmp_mrx.s.mbox_sp = 1;
    sriox_omsg_fmp_mrx.s.mbox_fmp = 1;
    sriox_omsg_fmp_mrx.s.mbox_nmp = 1;
    sriox_omsg_fmp_mrx.s.all_psd = 1;
    BDK_CSR_WRITE(BDK_SRIOX_OMSG_FMP_MRX(handle->index, handle->interface), sriox_omsg_fmp_mrx.u64);

    /* Once the first part of a message is accepted, always acept the rest
        of the message */
    BDK_CSR_DEFINE(sriox_omsg_nmp_mrx, BDK_SRIOX_OMSG_NMP_MRX(handle->index, handle->interface));
    sriox_omsg_nmp_mrx.u64 = 0;
    sriox_omsg_nmp_mrx.s.all_sp = 1;
    sriox_omsg_nmp_mrx.s.all_fmp = 1;
    sriox_omsg_nmp_mrx.s.all_nmp = 1;
    BDK_CSR_WRITE(BDK_SRIOX_OMSG_NMP_MRX(handle->index, handle->interface), sriox_omsg_nmp_mrx.u64);

    /* Choose the receive controller based on the mailbox */
    BDK_CSR_MODIFY(c, BDK_SRIOX_IMSG_CTRL(handle->interface),
        c.s.prt_sel = 0;
        c.s.mbox = 0xa);

    /* DPI must be enabled for us to RX messages */
    BDK_CSR_MODIFY(c, BDK_DPI_CTL,
        c.s.clk = 1;
        c.s.en = 1);

    /* Enable RX */
    BDK_CSR_MODIFY(c, BDK_SRIOMAINTX_CORE_ENABLES(handle->interface),
        c.s.imsg0 = 1;
        c.s.imsg1 = 1);

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
    return bdk_srio_link_get(handle->interface);
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


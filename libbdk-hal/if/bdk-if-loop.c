#include <bdk.h>

static int if_num_interfaces(void)
{
    return 1;
}

static int if_num_ports(int interface)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
        return 8;
    else if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 0;
    else
        return 4;
}

static int if_probe(bdk_if_handle_t handle)
{
    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        /* Use IPD ports 0 - 7 */
        handle->ipd_port = handle->index;
        handle->pko_port = __bdk_pko_alloc_port();
    }
    else
    {
        /* Use IPD ports 36 - 39 */
        handle->ipd_port = 36 + handle->index;
        /* PKO ports are the same as IPD */
        handle->pko_port = handle->ipd_port;
    }

    return 0;
}

static int if_init(bdk_if_handle_t handle)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    BDK_CSR_MODIFY(port_cfg, BDK_PIP_PRT_CFGX(handle->pknd),
            port_cfg.s.maxerr_en = 0;
            port_cfg.s.minerr_en = 0);

    if (OCTEON_IS_MODEL(OCTEON_CN68XX))
    {
        static int pko_eid = -1;
        if (pko_eid == -1)
            pko_eid = __bdk_pko_alloc_engine();

        /* Configure the PKO internal port mappings */
        if (handle->index == 0)
            BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                t.s.num_ports = if_num_ports(handle->interface));

        BDK_CSR_DEFINE(ptrs, BDK_PKO_MEM_IPORT_PTRS);
        ptrs.u64 = 0;
        ptrs.s.qos_mask = 0xff; /* QOS rounds */
        ptrs.s.crc = 0;         /* No CRC on packets */
        ptrs.s.min_pkt = 0;     /* No min packet */
        ptrs.s.pipe = handle->index; /* Which loop */
        ptrs.s.intr = 31;       /* Which interface */
        ptrs.s.eid = pko_eid;   /* Which engine */
        ptrs.s.ipid = handle->pko_port;
        BDK_CSR_WRITE(BDK_PKO_MEM_IPORT_PTRS, ptrs.u64);

        /* Setup the PKIND and BPID for this loopback port */
        switch (handle->index)
        {
            case 0:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind0 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid0 = handle->pknd);
                break;
            case 1:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind1 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid1 = handle->pknd);
                break;
            case 2:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind2 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid2 = handle->pknd);
                break;
            case 3:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind3 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid3 = handle->pknd);
                break;
            case 4:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind4 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid4 = handle->pknd);
                break;
            case 5:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind5 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid5 = handle->pknd);
                break;
            case 6:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind6 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid6 = handle->pknd);
                break;
            case 7:
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_PKIND,
                    t.s.pkind7 = handle->pknd);
                BDK_CSR_MODIFY(t, BDK_PKO_REG_LOOPBACK_BPID,
                    t.s.bpid7 = handle->pknd);
                break;
        }
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
    .if_probe = if_probe,
    .if_init = if_init,
    .if_enable = if_enable,
    .if_disable = if_disable,
    .if_link_get = if_link_get,
};


#include <bdk.h>

/**
 * @INTERNAL
 * Probe a LOOP interface and determine the number of ports
 * connected to it. The LOOP interface should still be down
 * after this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
int __bdk_helper_loop_probe(int interface)
{
    bdk_ipd_sub_port_fcs_t ipd_sub_port_fcs;
    int num_ports = 4;
    int port;

    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    for (port=0; port<num_ports; port++)
    {
        bdk_pip_prt_cfgx_t port_cfg;
        int ipd_port = bdk_helper_get_ipd_port(interface, port);
        port_cfg.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(ipd_port));
        port_cfg.s.maxerr_en = 0;
        port_cfg.s.minerr_en = 0;
        BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(ipd_port), port_cfg.u64);
    }

    /* Disable FCS stripping for loopback ports */
    ipd_sub_port_fcs.u64 = BDK_CSR_READ(BDK_IPD_SUB_PORT_FCS);
    ipd_sub_port_fcs.s.port_bit2 = 0;
    BDK_CSR_WRITE(BDK_IPD_SUB_PORT_FCS, ipd_sub_port_fcs.u64);
    return num_ports;
}


/**
 * @INTERNAL
 * Bringup and enable a LOOP interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_loop_enable(int interface)
{
    /* Do nothing. */
    return 0;
}


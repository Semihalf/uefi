#include <bdk.h>

/**
 * @INTERNAL
 * Probe a NPI interface and determine the number of ports
 * connected to it. The NPI interface should still be down
 * after this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
int __bdk_helper_npi_probe(int interface)
{
#if BDK_PKO_QUEUES_PER_PORT_PCI > 0
    return 4;
#endif
    return 0;
}


/**
 * @INTERNAL
 * Bringup and enable a NPI interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
int __bdk_helper_npi_enable(int interface)
{
    /* We need to disable length checking so packet < 64 bytes and jumbo
        frames don't get errors */
    int num_ports = bdk_helper_ports_on_interface(interface);
    int port;
    for (port=0; port<num_ports; port++)
    {
        bdk_pip_prt_cfgx_t port_cfg;
        int ipd_port = bdk_helper_get_ipd_port(interface, port);
        port_cfg.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(ipd_port));
        port_cfg.s.maxerr_en = 0;
        port_cfg.s.minerr_en = 0;
        BDK_CSR_WRITE(BDK_PIP_PRT_CFGX(ipd_port), port_cfg.u64);
    }

    /* Enables are controlled by the remote host, so nothing to do here */
    return 0;
}


#include <bdk.h>

/* Port count per interface */
static int interface_port_count[6] = {0,};
/* Port last configured link info index by IPD/PKO port */
static bdk_helper_link_info_t port_link_info[BDK_PIP_NUM_INPUT_PORTS];


/**
 * Return the number of interfaces the chip has. Each interface
 * may have multiple ports. Most chips support two interfaces,
 * but the CNX0XX and CNX1XX are exceptions. These only support
 * one interface.
 *
 * @return Number of interfaces on chip
 */
int bdk_helper_get_number_of_interfaces(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN63XX))
	return 6;
    else
        return 6; /* FIXME for CN68XX */
}


/**
 * Return the number of ports on an interface. Depending on the
 * chip and configuration, this can be 1-16. A value of 0
 * specifies that the interface doesn't exist or isn't usable.
 *
 * @param interface Interface to get the port count for
 *
 * @return Number of ports on interface. Can be Zero.
 */
int bdk_helper_ports_on_interface(int interface)
{
    return interface_port_count[interface];
}


/**
 * Get the operating mode of an interface. Depending on the Octeon
 * chip and configuration, this function returns an enumeration
 * of the type of packet I/O supported by an interface.
 *
 * @param interface Interface to probe
 *
 * @return Mode of the interface. Unknown or unsupported interfaces return
 *         DISABLED.
 */
bdk_helper_interface_mode_t bdk_helper_interface_get_mode(int interface)
{
    bdk_gmxx_inf_mode_t mode;
    if (interface == 2)
        return BDK_HELPER_INTERFACE_MODE_NPI;

    if (interface == 3)
        return BDK_HELPER_INTERFACE_MODE_LOOP;

    if (interface == 4 || interface == 5)
    {
        bdk_sriox_status_reg_t sriox_status_reg;
        sriox_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(interface-4));
        if (sriox_status_reg.s.srio)
            return BDK_HELPER_INTERFACE_MODE_SRIO;
        else
            return BDK_HELPER_INTERFACE_MODE_DISABLED;
    }

    /* Interface 1 is always disabled on CN31XX and CN30XX */
    if ((interface == 1) && OCTEON_IS_MODEL(OCTEON_CN63XX))
        return BDK_HELPER_INTERFACE_MODE_DISABLED;

    mode.u64 = BDK_CSR_READ(BDK_GMXX_INF_MODE(interface));

    switch(mode.cn63xx.mode)
    {
        case 0: return BDK_HELPER_INTERFACE_MODE_SGMII;
        case 1: return BDK_HELPER_INTERFACE_MODE_XAUI;
        default: return BDK_HELPER_INTERFACE_MODE_DISABLED;
    }
}

/**
 * @INTERNAL
 * Configure the IPD/PIP tagging and QoS options for a specific
 * port. This function determines the SSO work queue entry
 * contents for a port. The setup performed here is controlled by
 * the defines in executive-config.h.
 *
 * @param ipd_port Port to configure. This follows the IPD numbering, not the
 *                 per interface numbering
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_port_setup_ipd(int ipd_port)
{
    bdk_pip_prt_cfgx_t port_config;
    bdk_pip_prt_tagx_t tag_config;

    port_config.u64 = BDK_CSR_READ(BDK_PIP_PRT_CFGX(ipd_port));
    tag_config.u64 = BDK_CSR_READ(BDK_PIP_PRT_TAGX(ipd_port));

    /* Have each port go to a different SSO queue */
    port_config.s.qos = ipd_port & 0x7;
    port_config.s.mode = bdk_config_get(BDK_CONFIG_INPUT_PORT_SKIP_MODE);

    /* Process the headers and place the IP header in the work queue */
    tag_config.s.inc_prt_flag  = 1;
    tag_config.s.tcp6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
    tag_config.s.tcp4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
    tag_config.s.ip6_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
    tag_config.s.ip4_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
    tag_config.s.non_tag_type = bdk_config_get(BDK_CONFIG_INPUT_TAG_TYPE);
    tag_config.s.grp = 0;

    bdk_pip_config_port(ipd_port, port_config, tag_config);

    return 0;
}


/**
 * This function probes an interface to determine the actual
 * number of hardware ports connected to it. It doesn't setup the
 * ports or enable them. The main goal here is to set the global
 * interface_port_count[interface] correctly. Hardware setup of the
 * ports will be performed later.
 *
 * @param interface Interface to probe
 *
 * @return Zero on success, negative on failure
 */
int bdk_helper_interface_probe(int interface)
{
    /* At this stage in the game we don't want packets to be moving yet.
        The following probe calls should perform hardware setup
        needed to determine port counts. Receive must still be disabled */
    switch (bdk_helper_interface_get_mode(interface))
    {
        /* These types don't support ports to IPD/PKO */
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
            interface_port_count[interface] = 0;
            break;
        /* XAUI is a single high speed port */
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            interface_port_count[interface] = __bdk_helper_xaui_probe(interface);
            break;
        /* SGMII can have 1-4 ports depending on how many are hooked up */
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            interface_port_count[interface] = __bdk_helper_sgmii_probe(interface);
            break;
        /* PCI target Network Packet Interface */
        case BDK_HELPER_INTERFACE_MODE_NPI:
            interface_port_count[interface] = __bdk_helper_npi_probe(interface);
            break;
        /* Special loopback only ports. These are not the same as other ports
            in loopback mode */
        case BDK_HELPER_INTERFACE_MODE_LOOP:
            interface_port_count[interface] = __bdk_helper_loop_probe(interface);
            break;
	/* SRIO has 2^N ports, where N is number of interfaces */
	case BDK_HELPER_INTERFACE_MODE_SRIO:
	    interface_port_count[interface] = __bdk_helper_srio_probe(interface);
	    break;
    }

    /* Make sure all global variables propagate to other cores */
    BDK_SYNCW;

    return 0;
}


/**
 * @INTERNAL
 * Setup the IPD/PIP for the ports on an interface. Packet
 * classification and tagging are set for every port on the
 * interface. The number of ports on the interface must already
 * have been probed.
 *
 * @param interface Interface to setup IPD/PIP for
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_interface_setup_ipd(int interface)
{
    int ipd_port = bdk_helper_get_ipd_port(interface, 0);
    int num_ports = interface_port_count[interface];

    while (num_ports--)
    {
        __bdk_helper_port_setup_ipd(ipd_port);
        ipd_port++;
    }
    return 0;
}


/**
 * @INTERNAL
 * Setup global setting for IPD/PIP not related to a specific
 * interface or port. This must be called before IPD is enabled.
 *
 * @return Zero on success, negative on failure.
 */
static int __bdk_helper_global_setup_ipd(void)
{
    int first_skip = bdk_config_get(BDK_CONFIG_FIRST_MBUFF_SKIP);
    int other_skip = bdk_config_get(BDK_CONFIG_NOT_FIRST_MBUFF_SKIP);

    /* Setup the global packet input options */
    bdk_ipd_config(bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL)/8,
                    first_skip/8, other_skip/8,
                    (first_skip+8) / 128, /* The +8 is to account for the next ptr */
                    (other_skip+8) / 128, /* The +8 is to account for the next ptr */
                    BDK_FPA_WQE_POOL,
                    BDK_IPD_OPC_MODE_STT,
                    1);
    return 0;
}


/**
 * @INTERNAL
 * Setup the PKO for the ports on an interface. The number of
 * queues per port and the priority of each PKO output queue
 * is set here. PKO must be disabled when this function is called.
 *
 * @param interface Interface to setup PKO for
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_interface_setup_pko(int interface)
{
    /* Each packet output queue has an associated priority. The higher the
        priority, the more often it can send a packet. A priority of 8 means
        it can send in all 8 rounds of contention. We're going to make each
        queue one less than the last.
        The vector of priorities has been extended to support CN5xxx CPUs,
        where up to 16 queues can be associated to a port.
        To keep backward compatibility we don't change the initial 8
        priorities and replicate them in the second half.
        With per-core PKO queues (PKO lockless operation) all queues have
        the same priority. */
    uint64_t priorities[16] = {8,7,6,5,4,3,2,1,8,7,6,5,4,3,2,1};

    /* Setup the IPD/PIP and PKO for the ports discovered above. Here packet
        classification, tagging and output priorities are set */
    int ipd_port = bdk_helper_get_ipd_port(interface, 0);
    int num_ports = interface_port_count[interface];
    while (num_ports--)
    {
        bdk_pko_config_port(ipd_port, bdk_pko_get_base_queue(ipd_port),
                             bdk_pko_get_num_queues(ipd_port), priorities);
        ipd_port++;
    }
    return 0;
}


/**
 * @INTERNAL
 * Setup global setting for PKO not related to a specific
 * interface or port. This must be called before PKO is enabled.
 *
 * @return Zero on success, negative on failure.
 */
static int __bdk_helper_global_setup_pko(void)
{
    /* Disable tagwait FAU timeout. This needs to be done before anyone might
        start packet output using tags */
    bdk_iob0_fau_timeout_t fau_to;
    fau_to.u64 = 0;
    fau_to.s.tout_val = 0xfff;
    fau_to.s.tout_enb = 0;
    BDK_CSR_WRITE(BDK_IOB0_FAU_TIMEOUT, fau_to.u64);
    return 0;
}


/**
 * @INTERNAL
 * Setup global backpressure setting.
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_global_setup_backpressure(void)
{
    /* Disable backpressure if configured to do so */
    /* Disable backpressure (pause frame) generation */
    int num_interfaces = bdk_helper_get_number_of_interfaces();
    int interface;
    for (interface=0; interface<num_interfaces; interface++)
    {
        switch (bdk_helper_interface_get_mode(interface))
        {
            case BDK_HELPER_INTERFACE_MODE_DISABLED:
            case BDK_HELPER_INTERFACE_MODE_PCIE:
            case BDK_HELPER_INTERFACE_MODE_SRIO:
            case BDK_HELPER_INTERFACE_MODE_NPI:
            case BDK_HELPER_INTERFACE_MODE_LOOP:
            case BDK_HELPER_INTERFACE_MODE_XAUI:
                break;
            case BDK_HELPER_INTERFACE_MODE_SGMII:
            case BDK_HELPER_INTERFACE_MODE_PICMG:
            {
                bdk_gmxx_tx_ovr_bp_t gmxx_tx_ovr_bp;
                gmxx_tx_ovr_bp.u64 = 0;
                gmxx_tx_ovr_bp.s.en = 0xf; /* Per port Enable back pressure override */
                gmxx_tx_ovr_bp.s.ign_full = 0xf; /* Ignore the RX FIFO full when computing BP */
                BDK_CSR_WRITE(BDK_GMXX_TX_OVR_BP(interface), gmxx_tx_ovr_bp.u64);
                break;
            }
        }
    }

    return 0;
}


/**
 * @INTERNAL
 * Enable packet input/output from the hardware. This function is
 * called after all internal setup is complete and IPD is enabled.
 * After this function completes, packets will be accepted from the
 * hardware ports. PKO should still be disabled to make sure packets
 * aren't sent out partially setup hardware.
 *
 * @param interface Interface to enable
 *
 * @return Zero on success, negative on failure
 */
static int __bdk_helper_packet_hardware_enable(int interface)
{
    int result = 0;
    switch (bdk_helper_interface_get_mode(interface))
    {
        /* These types don't support ports to IPD/PKO */
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
            /* Nothing to do */
            break;
        /* XAUI is a single high speed port */
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            result = __bdk_helper_xaui_enable(interface);
            break;
        /* SGMII can have 1-4 ports depending on how many are hooked up */
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            result = __bdk_helper_sgmii_enable(interface);
            break;
        /* PCI target Network Packet Interface */
        case BDK_HELPER_INTERFACE_MODE_NPI:
            result = __bdk_helper_npi_enable(interface);
            break;
        /* Special loopback only ports. These are not the same as other ports
            in loopback mode */
        case BDK_HELPER_INTERFACE_MODE_LOOP:
            result = __bdk_helper_loop_enable(interface);
            break;
	/* SRIO has 2^N ports, where N is number of interfaces */
        case BDK_HELPER_INTERFACE_MODE_SRIO:
	    result = __bdk_helper_srio_enable(interface);
	    break;
    }
    return result;
}


/**
 * Called after all internal packet IO paths are setup. This
 * function enables IPD/PIP and begins packet input and output.
 *
 * @return Zero on success, negative on failure
 */
int bdk_helper_ipd_and_packet_input_enable(void)
{
    int num_interfaces;
    int interface;

    /* Enable IPD */
    bdk_ipd_enable();

    /* Time to enable hardware ports packet input and output. Note that at this
        point IPD/PIP must be fully functional and PKO must be disabled */
    num_interfaces = bdk_helper_get_number_of_interfaces();
    for (interface=0; interface<num_interfaces; interface++)
    {
        if (bdk_helper_ports_on_interface(interface) > 0)
        {
            __bdk_helper_packet_hardware_enable(interface);
        }
    }

    /* Finally enable PKO now that the entire path is up and running */
    bdk_pko_enable();

    return 0;
}

/**
 * Initialize the PIP, IPD, and PKO hardware to support
 * simple priority based queues for the ethernet ports. Each
 * port is configured with a number of priority queues based
 * on BDK_PKO_QUEUES_PER_PORT_* where each queue is lower
 * priority than the previous.
 *
 * @return Zero on success, non-zero on failure
 */
int bdk_helper_initialize_packet_io_global(void)
{
    int result = 0;
    int interface;
    bdk_smix_en_t smix_en;
    const int num_interfaces = bdk_helper_get_number_of_interfaces();

    /* Tell L2 to give the IOB statically higher priority compared to the
        cores. This avoids conditions where IO blocks might be starved under
        very high L2 loads */
    bdk_l2c_ctl_t l2c_ctl;
    l2c_ctl.u64 = BDK_CSR_READ(BDK_L2C_CTL);
    l2c_ctl.s.rsp_arb_mode = 1;
    l2c_ctl.s.xmc_arb_mode = 0;
    BDK_CSR_WRITE(BDK_L2C_CTL, l2c_ctl.u64);

    {
        /* Make sure SMI/MDIO is enabled so we can query PHYs */
        smix_en.u64 = BDK_CSR_READ(BDK_SMIX_EN(0));
        if (!smix_en.s.en)
        {
            smix_en.s.en = 1;
            BDK_CSR_WRITE(BDK_SMIX_EN(0), smix_en.u64);
        }

        smix_en.u64 = BDK_CSR_READ(BDK_SMIX_EN(1));
        if (!smix_en.s.en)
        {
            smix_en.s.en = 1;
            BDK_CSR_WRITE(BDK_SMIX_EN(1), smix_en.u64);
        }
    }

    for (interface=0; interface<num_interfaces; interface++)
        result |= bdk_helper_interface_probe(interface);

    bdk_pko_initialize();
    for (interface=0; interface<num_interfaces; interface++)
    {
        result |= __bdk_helper_interface_setup_ipd(interface);
        result |= __bdk_helper_interface_setup_pko(interface);
    }

    result |= __bdk_helper_global_setup_ipd();
    result |= __bdk_helper_global_setup_pko();

    /* Enable any flow control and backpressure */
    result |= __bdk_helper_global_setup_backpressure();

    result |= bdk_helper_ipd_and_packet_input_enable();
    return result;
}


/**
 * Auto configure an IPD/PKO port link state and speed. This
 * function basically does the equivalent of:
 * bdk_helper_link_set(ipd_port, bdk_helper_link_get(ipd_port));
 *
 * @param ipd_port IPD/PKO port to auto configure
 *
 * @return Link state after configure
 */
bdk_helper_link_info_t bdk_helper_link_autoconf(int ipd_port)
{
    bdk_helper_link_info_t link_info;
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);

    if (index >= bdk_helper_ports_on_interface(interface))
    {
        link_info.u64 = 0;
        return link_info;
    }

    link_info = bdk_helper_link_get(ipd_port);
    if (link_info.u64 ==  port_link_info[ipd_port].u64)
        return link_info;

    /* If we fail to set the link speed, port_link_info will not change */
    bdk_helper_link_set(ipd_port, link_info);

    /* port_link_info should be the current value, which will be different
        than expect if bdk_helper_link_set() failed */
    return port_link_info[ipd_port];
}

/**
 * Return the link state of an IPD/PKO port as returned by
 * auto negotiation. The result of this function may not match
 * Octeon's link config if auto negotiation has changed since
 * the last call to bdk_helper_link_set().
 *
 * @param ipd_port IPD/PKO port to query
 *
 * @return Link state
 */
bdk_helper_link_info_t bdk_helper_link_get(int ipd_port)
{
    bdk_helper_link_info_t result;
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);

    /* The default result will be a down link unless the code below
        changes it */
    result.u64 = 0;

    if (index >= bdk_helper_ports_on_interface(interface))
        return result;

    switch (bdk_helper_interface_get_mode(interface))
    {
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
            /* Network links are not supported */
            break;
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            result = __bdk_helper_xaui_link_get(ipd_port);
            break;
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            result = __bdk_helper_sgmii_link_get(ipd_port);
            break;
        case BDK_HELPER_INTERFACE_MODE_SRIO:
            result = __bdk_helper_srio_link_get(ipd_port);
            break;
        case BDK_HELPER_INTERFACE_MODE_NPI:
        case BDK_HELPER_INTERFACE_MODE_LOOP:
            /* Network links are not supported */
            break;
    }
    return result;
}


/**
 * Configure an IPD/PKO port for the specified link state. This
 * function does not influence auto negotiation at the PHY level.
 * The passed link state must always match the link state returned
 * by bdk_helper_link_get(). It is normally best to use
 * bdk_helper_link_autoconf() instead.
 *
 * @param ipd_port  IPD/PKO port to configure
 * @param link_info The new link state
 *
 * @return Zero on success, negative on failure
 */
int bdk_helper_link_set(int ipd_port, bdk_helper_link_info_t link_info)
{
    int result = -1;
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);

    if (index >= bdk_helper_ports_on_interface(interface))
        return -1;

    switch (bdk_helper_interface_get_mode(interface))
    {
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
            break;
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            result = __bdk_helper_xaui_link_set(ipd_port, link_info);
            break;
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            result = __bdk_helper_sgmii_link_set(ipd_port, link_info);
            break;
        case BDK_HELPER_INTERFACE_MODE_SRIO:
            result = __bdk_helper_srio_link_set(ipd_port, link_info);
            break;
        case BDK_HELPER_INTERFACE_MODE_NPI:
        case BDK_HELPER_INTERFACE_MODE_LOOP:
            break;
    }
    /* Set the port_link_info here so that the link status is updated
       no matter how bdk_helper_link_set is called. We don't change
       the value if link_set failed */
    if (result == 0)
        port_link_info[ipd_port].u64 = link_info.u64;
    return result;
}


/**
 * Configure a port for internal and/or external loopback. Internal loopback
 * causes packets sent by the port to be received by Octeon. External loopback
 * causes packets received from the wire to sent out again.
 *
 * @param ipd_port IPD/PKO port to loopback.
 * @param enable_internal
 *                 Non zero if you want internal loopback
 * @param enable_external
 *                 Non zero if you want external loopback
 *
 * @return Zero on success, negative on failure.
 */
int bdk_helper_configure_loopback(int ipd_port, int enable_internal, int enable_external)
{
    int result = -1;
    int interface = bdk_helper_get_interface_num(ipd_port);
    int index = bdk_helper_get_interface_index_num(ipd_port);

    if (index >= bdk_helper_ports_on_interface(interface))
        return -1;

    switch (bdk_helper_interface_get_mode(interface))
    {
        case BDK_HELPER_INTERFACE_MODE_DISABLED:
        case BDK_HELPER_INTERFACE_MODE_PCIE:
        case BDK_HELPER_INTERFACE_MODE_SRIO:
        case BDK_HELPER_INTERFACE_MODE_NPI:
        case BDK_HELPER_INTERFACE_MODE_LOOP:
            break;
        case BDK_HELPER_INTERFACE_MODE_XAUI:
            result = __bdk_helper_xaui_configure_loopback(ipd_port, enable_internal, enable_external);
            break;
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            result = __bdk_helper_sgmii_configure_loopback(ipd_port, enable_internal, enable_external);
            break;
    }
    return result;
}


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
    else if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX))
        return 4;
    else
        return 3;
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
    {
        if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN6XXX))
            return BDK_HELPER_INTERFACE_MODE_LOOP;
        else
            return BDK_HELPER_INTERFACE_MODE_DISABLED;
    }

    if (OCTEON_IS_MODEL(OCTEON_CN6XXX) && (interface == 4 || interface == 5))
    {
        bdk_sriox_status_reg_t sriox_status_reg;
        sriox_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(interface-4));
        if (sriox_status_reg.s.srio)
            return BDK_HELPER_INTERFACE_MODE_SRIO;
        else
            return BDK_HELPER_INTERFACE_MODE_DISABLED;
    }

    /* Interface 1 is always disabled on CN31XX and CN30XX */
    if ((interface == 1) && (OCTEON_IS_MODEL(OCTEON_CN52XX) || OCTEON_IS_MODEL(OCTEON_CN63XX)))
        return BDK_HELPER_INTERFACE_MODE_DISABLED;

    mode.u64 = BDK_CSR_READ(BDK_GMXX_INF_MODE(interface));

    if (OCTEON_IS_MODEL(OCTEON_CN56XX) || OCTEON_IS_MODEL(OCTEON_CN52XX))
    {
        switch(mode.cn56xx.mode)
        {
            case 0: return BDK_HELPER_INTERFACE_MODE_DISABLED;
            case 1: return BDK_HELPER_INTERFACE_MODE_XAUI;
            case 2: return BDK_HELPER_INTERFACE_MODE_SGMII;
            case 3: return BDK_HELPER_INTERFACE_MODE_PICMG;
            default:return BDK_HELPER_INTERFACE_MODE_DISABLED;
        }
    }
    else if (OCTEON_IS_MODEL(OCTEON_CN63XX))
    {
	switch(mode.cn63xx.mode)
	{
	    case 0: return BDK_HELPER_INTERFACE_MODE_SGMII;
	    case 1: return BDK_HELPER_INTERFACE_MODE_XAUI;
	    default: return BDK_HELPER_INTERFACE_MODE_DISABLED;
	}
    }
    else
    {
        return BDK_HELPER_INTERFACE_MODE_DISABLED;
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

    /* Process the headers and place the IP header in the work queue */
    port_config.s.mode = BDK_HELPER_INPUT_PORT_SKIP_MODE;
#warning Fix BDK_HELPER_INPUT_TAG_*
#if 0 // FIXME
    tag_config.s.ip6_src_flag  = BDK_HELPER_INPUT_TAG_IPV6_SRC_IP;
    tag_config.s.ip6_dst_flag  = BDK_HELPER_INPUT_TAG_IPV6_DST_IP;
    tag_config.s.ip6_sprt_flag = BDK_HELPER_INPUT_TAG_IPV6_SRC_PORT;
    tag_config.s.ip6_dprt_flag = BDK_HELPER_INPUT_TAG_IPV6_DST_PORT;
    tag_config.s.ip6_nxth_flag = BDK_HELPER_INPUT_TAG_IPV6_NEXT_HEADER;
    tag_config.s.ip4_src_flag  = BDK_HELPER_INPUT_TAG_IPV4_SRC_IP;
    tag_config.s.ip4_dst_flag  = BDK_HELPER_INPUT_TAG_IPV4_DST_IP;
    tag_config.s.ip4_sprt_flag = BDK_HELPER_INPUT_TAG_IPV4_SRC_PORT;
    tag_config.s.ip4_dprt_flag = BDK_HELPER_INPUT_TAG_IPV4_DST_PORT;
    tag_config.s.ip4_pctl_flag = BDK_HELPER_INPUT_TAG_IPV4_PROTOCOL;
    tag_config.s.inc_prt_flag  = BDK_HELPER_INPUT_TAG_INPUT_PORT;
    tag_config.s.tcp6_tag_type = BDK_HELPER_INPUT_TAG_TYPE;
    tag_config.s.tcp4_tag_type = BDK_HELPER_INPUT_TAG_TYPE;
    tag_config.s.ip6_tag_type = BDK_HELPER_INPUT_TAG_TYPE;
    tag_config.s.ip4_tag_type = BDK_HELPER_INPUT_TAG_TYPE;
    tag_config.s.non_tag_type = BDK_HELPER_INPUT_TAG_TYPE;
#endif
    /* Put all packets in group 0. Other groups can be used by the app */
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

    interface_port_count[interface] = __bdk_helper_board_interface_probe(interface, interface_port_count[interface]);

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
    /* Setup the global packet input options */
    bdk_ipd_config(bdk_fpa_get_block_size(BDK_FPA_PACKET_POOL)/8,
                    BDK_HELPER_FIRST_MBUFF_SKIP/8,
                    BDK_HELPER_NOT_FIRST_MBUFF_SKIP/8,
                    (BDK_HELPER_FIRST_MBUFF_SKIP+8) / 128, /* The +8 is to account for the next ptr */
                    (BDK_HELPER_NOT_FIRST_MBUFF_SKIP+8) / 128, /* The +8 is to account for the next ptr */
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
        bdk_pko_config_port(ipd_port, bdk_pko_get_base_queue_per_core(ipd_port, 0),
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
    bdk_iob_fau_timeout_t fau_to;
    fau_to.u64 = 0;
    fau_to.s.tout_val = 0xfff;
    fau_to.s.tout_enb = 0;
    BDK_CSR_WRITE(BDK_IOB_FAU_TIMEOUT, fau_to.u64);
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
                bdk_gmx_set_backpressure_override(interface, 0xf);
                break;
        }
    }
    //bdk_dprintf("Disabling backpressure\n");

    return 0;
}

/**
 * @INTERNAL
 * Verify the per port IPD backpressure is aligned properly.
 * @return Zero if working, non zero if misaligned
 */
int __bdk_helper_backpressure_is_misaligned(void)
{
    uint64_t ipd_int_enb;
    bdk_ipd_ctl_status_t ipd_reg;
    uint64_t bp_status0;
    uint64_t bp_status1;
    const int port0 = 0;
    const int port1 = 16;
    bdk_helper_interface_mode_t mode0 = bdk_helper_interface_get_mode(0);
    bdk_helper_interface_mode_t mode1 = bdk_helper_interface_get_mode(1);

    /* Disable error interrupts while we check backpressure */
    ipd_int_enb = BDK_CSR_READ(BDK_IPD_INT_ENB);
    BDK_CSR_WRITE(BDK_IPD_INT_ENB, 0);

    /* Enable per port backpressure */
    ipd_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_reg.s.pbp_en = 1;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_reg.u64);

    if (mode0 != BDK_HELPER_INTERFACE_MODE_DISABLED)
    {
        /* Enable backpressure for port with a zero threshold */
        BDK_CSR_WRITE(BDK_IPD_PORTX_BP_PAGE_CNT(port0), 1<<17);
        /* Add 1000 to the page count to simulate packets coming in */
        BDK_CSR_WRITE(BDK_IPD_SUB_PORT_BP_PAGE_CNT, (port0<<25) | 1000);
    }

    if (mode1 != BDK_HELPER_INTERFACE_MODE_DISABLED)
    {
        /* Enable backpressure for port with a zero threshold */
        BDK_CSR_WRITE(BDK_IPD_PORTX_BP_PAGE_CNT(port1), 1<<17);
        /* Add 1000 to the page count to simulate packets coming in */
        BDK_CSR_WRITE(BDK_IPD_SUB_PORT_BP_PAGE_CNT, (port1<<25) | 1000);
    }

    /* Wait 500 cycles for the BP to update */
    bdk_wait(500);

    /* Read the BP state from the debug select register */
    switch (mode0)
    {
        case BDK_HELPER_INTERFACE_MODE_XAUI:
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            BDK_CSR_WRITE(BDK_NPEI_DBG_SELECT, 0x0e00);
            bp_status0 = 0xffff & BDK_CSR_READ(BDK_NPEI_DBG_DATA);
            break;
        default:
            bp_status0 = 1<<port0;
            break;
    }

    /* Read the BP state from the debug select register */
    switch (mode1)
    {
        case BDK_HELPER_INTERFACE_MODE_XAUI:
        case BDK_HELPER_INTERFACE_MODE_SGMII:
        case BDK_HELPER_INTERFACE_MODE_PICMG:
            BDK_CSR_WRITE(BDK_NPEI_DBG_SELECT, 0x1600);
            bp_status1 = 0xffff & BDK_CSR_READ(BDK_NPEI_DBG_DATA);
            break;
        default:
            bp_status1 = 1<<(port1-16);
            break;
    }

    if (mode0 != BDK_HELPER_INTERFACE_MODE_DISABLED)
    {
        /* Shutdown BP */
        BDK_CSR_WRITE(BDK_IPD_SUB_PORT_BP_PAGE_CNT, (port0<<25) | (0x1ffffff & -1000));
        BDK_CSR_WRITE(BDK_IPD_PORTX_BP_PAGE_CNT(port0), 0);
    }

    if (mode1 != BDK_HELPER_INTERFACE_MODE_DISABLED)
    {
        /* Shutdown BP */
        BDK_CSR_WRITE(BDK_IPD_SUB_PORT_BP_PAGE_CNT, (port1<<25) | (0x1ffffff & -1000));
        BDK_CSR_WRITE(BDK_IPD_PORTX_BP_PAGE_CNT(port1), 0);
    }

    /* Clear any error interrupts that might have been set */
    BDK_CSR_WRITE(BDK_IPD_INT_SUM, 0x1f);
    BDK_CSR_WRITE(BDK_IPD_INT_ENB, ipd_int_enb);

    return ((bp_status0 != 1ull<<port0) || (bp_status1 != 1ull<<(port1-16)));
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
    result |= __bdk_helper_board_hardware_enable(interface);
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
            //bdk_dprintf("Enabling packet I/O on interface %d\n", interface);
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
    bdk_l2c_cfg_t l2c_cfg;
    bdk_smix_en_t smix_en;
    const int num_interfaces = bdk_helper_get_number_of_interfaces();

    /* CN52XX pass 1: Due to a bug in 2nd order CDR, it needs to be disabled */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_0))
        __bdk_helper_errata_qlm_disable_2nd_order_cdr(1);

    /* Tell L2 to give the IOB statically higher priority compared to the
        cores. This avoids conditions where IO blocks might be starved under
        very high L2 loads */
    if (OCTEON_IS_MODEL(OCTEON_CN6XXX))
    {
        bdk_l2c_ctl_t l2c_ctl;
        l2c_ctl.u64 = BDK_CSR_READ(BDK_L2C_CTL);
        l2c_ctl.s.rsp_arb_mode = 1;
        l2c_ctl.s.xmc_arb_mode = 0;
        BDK_CSR_WRITE(BDK_L2C_CTL, l2c_ctl.u64);
    }
    else
    {
        l2c_cfg.u64 = BDK_CSR_READ(BDK_L2C_CFG);
        l2c_cfg.s.lrf_arb_mode = 0;
        l2c_cfg.s.rfb_arb_mode = 0;
        BDK_CSR_WRITE(BDK_L2C_CFG, l2c_cfg.u64);
    }

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

    bdk_pko_initialize_global();
    for (interface=0; interface<num_interfaces; interface++)
    {
        if (bdk_helper_ports_on_interface(interface) > 0)
            bdk_dprintf("Interface %d has %d ports (%s)\n",
                     interface, bdk_helper_ports_on_interface(interface),
                     bdk_helper_interface_mode_to_string(bdk_helper_interface_get_mode(interface)));
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
 * Does core local initialization for packet io
 *
 * @return Zero on success, non-zero on failure
 */
int bdk_helper_initialize_packet_io_local(void)
{
    return bdk_pko_initialize_local();
}


/**
 * Undo the initialization performed in
 * bdk_helper_initialize_packet_io_global(). After calling this routine and the
 * local version on each core, packet IO for Octeon will be disabled and placed
 * in the initial reset state. It will then be safe to call the initialize
 * later on. Note that this routine does not empty the FPA pools. It frees all
 * buffers used by the packet IO hardware to the FPA so a function emptying the
 * FPA after shutdown should find all packet buffers in the FPA.
 *
 * @return Zero on success, negative on failure.
 */
int bdk_helper_shutdown_packet_io_global(void)
{
    const int timeout = 5; /* Wait up to 5 seconds for timeouts */
    int result = 0;
    int num_interfaces;
    int interface;
    int num_ports;
    int index;
    int pool0_count;
    bdk_wqe_t *work;

    /* Step 1: Disable all backpressure */
    for (interface=0; interface<2; interface++)
        if (bdk_helper_interface_get_mode(interface) != BDK_HELPER_INTERFACE_MODE_DISABLED)
            bdk_gmx_set_backpressure_override(interface, 0xf);

    /* Step 2: Wait for the PKO queues to drain */
    num_interfaces = bdk_helper_get_number_of_interfaces();
    for (interface=0; interface<num_interfaces; interface++)
    {
        num_ports = bdk_helper_ports_on_interface(interface);
        for (index=0; index<num_ports; index++)
        {
            int pko_port = bdk_helper_get_ipd_port(interface, index);
            int queue = bdk_pko_get_base_queue(pko_port);
            int max_queue = queue + bdk_pko_get_num_queues(pko_port);
            while (queue < max_queue)
            {
                int count = bdk_cmd_queue_length(BDK_CMD_QUEUE_PKO(queue));
                uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
                uint64_t stop_cycle = start_cycle +
                    bdk_clock_get_rate(BDK_CLOCK_CORE) * timeout;
                while (count && (bdk_clock_get_count(BDK_CLOCK_CORE) < stop_cycle))
                {
                    bdk_wait(10000);
                    count = bdk_cmd_queue_length(BDK_CMD_QUEUE_PKO(queue));
                }
                if (count)
                {
                    bdk_dprintf("PKO port %d, queue %d, timeout waiting for idle\n",
                        pko_port, queue);
                    result = -1;
                }
                queue++;
            }
        }
    }

    /* Step 3: Disable TX and RX on all ports */
    for (interface=0; interface<2; interface++)
    {
        switch (bdk_helper_interface_get_mode(interface))
        {
            case BDK_HELPER_INTERFACE_MODE_DISABLED:
            case BDK_HELPER_INTERFACE_MODE_PCIE:
                /* Not a packet interface */
                break;
            case BDK_HELPER_INTERFACE_MODE_NPI:
            case BDK_HELPER_INTERFACE_MODE_SRIO:
                /* We don't handle the NPI/NPEI/SRIO packet engines. The caller
                    must know these are idle */
                break;
            case BDK_HELPER_INTERFACE_MODE_LOOP:
                /* Nothing needed. Once PKO is idle, the loopback devices
                    must be idle */
                break;
            case BDK_HELPER_INTERFACE_MODE_XAUI:
            case BDK_HELPER_INTERFACE_MODE_SGMII:
            case BDK_HELPER_INTERFACE_MODE_PICMG:
                num_ports = bdk_helper_ports_on_interface(interface);
                if (num_ports > 4)
                    num_ports = 4;
                for (index=0; index<num_ports; index++)
                {
                    bdk_gmxx_prtx_cfg_t gmx_cfg;
                    gmx_cfg.u64 = BDK_CSR_READ(BDK_GMXX_PRTX_CFG(index, interface));
                    gmx_cfg.s.en = 0;
                    BDK_CSR_WRITE(BDK_GMXX_PRTX_CFG(index, interface), gmx_cfg.u64);
                    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(index, interface), rx_idle, ==, 1, timeout*1000000))
                    {
                        bdk_dprintf("GMX RX path timeout waiting for idle\n");
                        result = -1;
                    }
                    if (BDK_CSR_WAIT_FOR_FIELD(BDK_GMXX_PRTX_CFG(index, interface), tx_idle, ==, 1, timeout*1000000))
                    {
                        bdk_dprintf("GMX TX path timeout waiting for idle\n");
                        result = -1;
                    }
                }
                break;
        }
    }

    /* Step 4: Retrieve all packets from the SSO and free them */
    while ((work = bdk_sso_work_request_sync(BDK_SSO_WAIT)))
    {
        bdk_helper_free_packet_data(work);
        bdk_fpa_free(work, BDK_FPA_WQE_POOL, 0);
    }

    /* Step 5: Disable IPD and PKO. PIP is taken care of in the next step */
    bdk_ipd_disable();
    bdk_pko_disable();

    /* Step 6: Drain all prefetched buffers from IPD/PIP. Note that IPD/PIP
        have not been reset yet */
    __bdk_ipd_free_ptr();

    /* Step 7: Free the PKO command buffers and put PKO in reset */
    bdk_pko_shutdown();

    /* Step 8: Disable MAC address filtering */
    for (interface=0; interface<2; interface++)
    {
        switch (bdk_helper_interface_get_mode(interface))
        {
            case BDK_HELPER_INTERFACE_MODE_DISABLED:
            case BDK_HELPER_INTERFACE_MODE_PCIE:
            case BDK_HELPER_INTERFACE_MODE_SRIO:
            case BDK_HELPER_INTERFACE_MODE_NPI:
            case BDK_HELPER_INTERFACE_MODE_LOOP:
                break;
            case BDK_HELPER_INTERFACE_MODE_XAUI:
            case BDK_HELPER_INTERFACE_MODE_SGMII:
            case BDK_HELPER_INTERFACE_MODE_PICMG:
                num_ports = bdk_helper_ports_on_interface(interface);
                if (num_ports > 4)
                    num_ports = 4;
                for (index=0; index<num_ports; index++)
                {
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CTL(index, interface), 1);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM_EN(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM0(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM1(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM2(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM3(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM4(index, interface), 0);
                    BDK_CSR_WRITE(BDK_GMXX_RXX_ADR_CAM5(index, interface), 0);
                }
                break;
        }
    }

    /* Step 9: Drain all FPA buffers out of pool 0 before we reset IPD/PIP.
        This is needed to keep IPD_QUE0_FREE_PAGE_CNT in sync. We use pool 1
        for temporary storage */
    pool0_count = 0;
    while (1)
    {
        void *buffer = bdk_fpa_alloc(0);
        if (buffer)
        {
            bdk_fpa_free(buffer, 1, 0);
            pool0_count++;
        }
        else
            break;
    }


    /* Step 10: Reset IPD and PIP */
    {
        bdk_ipd_ctl_status_t ipd_ctl_status;
        ipd_ctl_status.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
        ipd_ctl_status.s.reset = 1;
        BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_status.u64);

        if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
        {
            /* only try 1000 times.  Normally if this works it will happen in
            ** the first 50 loops. */
            int max_loops = 1000;
            int loop = 0;
            /* Per port backpressure counters can get misaligned after an
               IPD reset. This code realigns them by performing repeated
               resets. See IPD-13473 */
            bdk_wait(100);
            if (__bdk_helper_backpressure_is_misaligned())
            {
                bdk_dprintf("Starting to align per port backpressure counters.\n");
                while (__bdk_helper_backpressure_is_misaligned() && (loop++ < max_loops))
                {
                    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_status.u64);
                    bdk_wait(123);
                }
                if (loop < max_loops)
                    bdk_dprintf("Completed aligning per port backpressure counters (%d loops).\n", loop);
                else
                {
                    bdk_dprintf("ERROR: unable to align per port backpressure counters.\n");
                    /* For now, don't hang.... */
                }
            }
        }

        bdk_pip_sft_rst_t pip_sft_rst;
        pip_sft_rst.u64 = BDK_CSR_READ(BDK_PIP_SFT_RST);
        pip_sft_rst.s.rst = 1;
        BDK_CSR_WRITE(BDK_PIP_SFT_RST, pip_sft_rst.u64);
    }

    /* Step 11: Restore the FPA buffers into pool 0 */
    while (pool0_count--)
        bdk_fpa_free(bdk_fpa_alloc(1), 0, 0);

    return result;
}


/**
 * Does core local shutdown of packet io
 *
 * @return Zero on success, non-zero on failure
 */
int bdk_helper_shutdown_packet_io_local(void)
{
    /* Currently there is nothing to do per core. This may change in
        the future */
    return 0;
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


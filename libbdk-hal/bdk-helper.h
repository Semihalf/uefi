/**
 * @file
 *
 * Helper functions for common, but complicated tasks.
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef enum
{
    BDK_HELPER_INTERFACE_MODE_DISABLED,
    BDK_HELPER_INTERFACE_MODE_PCIE,
    BDK_HELPER_INTERFACE_MODE_XAUI,
    BDK_HELPER_INTERFACE_MODE_SGMII,
    BDK_HELPER_INTERFACE_MODE_PICMG,
    BDK_HELPER_INTERFACE_MODE_NPI,
    BDK_HELPER_INTERFACE_MODE_LOOP,
    BDK_HELPER_INTERFACE_MODE_SRIO,
} bdk_helper_interface_mode_t;

typedef union
{
    uint64_t u64;
    struct
    {
        uint64_t    reserved_20_63  : 44;
        uint64_t    link_up         : 1;    /**< Is the physical link up? */
        uint64_t    full_duplex     : 1;    /**< 1 if the link is full duplex */
        uint64_t    speed           : 18;   /**< Speed of the link in Mbps */
    } s;
} bdk_helper_link_info_t;

/**
 * This function enables the IPD and also enables the packet interfaces.
 * The packet interfaces (RGMII and SPI) must be enabled after the
 * IPD.  This should be called by the user program after any additional
 * IPD configuration changes are made if BDK_HELPER_ENABLE_IPD
 * is not set in the executive-config.h file.
 *
 * @return 0 on success
 *         -1 on failure
 */
extern int bdk_helper_ipd_and_packet_input_enable(void);

/**
 * Initialize the PIP, IPD, and PKO hardware to support
 * simple priority based queues for the ethernet ports. Each
 * port is configured with a number of priority queues based
 * on BDK_PKO_QUEUES_PER_PORT_* where each queue is lower
 * priority than the previous.
 *
 * @return Zero on success, non-zero on failure
 */
extern int bdk_helper_initialize_packet_io_global(void);

/**
 * Does core local initialization for packet io
 *
 * @return Zero on success, non-zero on failure
 */
extern int bdk_helper_initialize_packet_io_local(void);

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
extern int bdk_helper_shutdown_packet_io_global(void);

/**
 * Does core local shutdown of packet io
 *
 * @return Zero on success, non-zero on failure
 */
extern int bdk_helper_shutdown_packet_io_local(void);

/**
 * Returns the number of ports on the given interface.
 * The interface must be initialized before the port count
 * can be returned.
 *
 * @param interface Which interface to return port count for.
 *
 * @return Port count for interface
 *         -1 for uninitialized interface
 */
extern int bdk_helper_ports_on_interface(int interface);

/**
 * Return the number of interfaces the chip has. Each interface
 * may have multiple ports. Most chips support two interfaces,
 * but the CNX0XX and CNX1XX are exceptions. These only support
 * one interface.
 *
 * @return Number of interfaces on chip
 */
extern int bdk_helper_get_number_of_interfaces(void);

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
extern bdk_helper_interface_mode_t bdk_helper_interface_get_mode(int interface);

/**
 * Auto configure an IPD/PKO port link state and speed. This
 * function basically does the equivalent of:
 * bdk_helper_link_set(ipd_port, bdk_helper_link_get(ipd_port));
 *
 * @param ipd_port IPD/PKO port to auto configure
 *
 * @return Link state after configure
 */
extern bdk_helper_link_info_t bdk_helper_link_autoconf(int ipd_port);

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
extern bdk_helper_link_info_t bdk_helper_link_get(int ipd_port);

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
extern int bdk_helper_link_set(int ipd_port, bdk_helper_link_info_t link_info);



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
extern int bdk_helper_interface_probe(int interface);

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
extern int bdk_helper_configure_loopback(int ipd_port, int enable_internal, int enable_external);


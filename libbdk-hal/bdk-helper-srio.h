/**
 * @file
 *
 * Functions for SRIO initialization, configuration,
 * and monitoring.
 *
 * <hr>$Revision: 41586 $<hr>
 */

/**
 * @INTERNAL
 * Probe a SRIO interface and determine the number of ports
 * connected to it. The SRIO interface should still be down after
 * this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
extern int __bdk_helper_srio_probe(int interface);

/**
 * @INTERNAL
 * Bringup and enable a SRIO interface. After this call packet
 * I/O should be fully functional. This is called with IPD
 * enabled but PKO disabled.
 *
 * @param interface Interface to bring up
 *
 * @return Zero on success, negative on failure
 */
extern int __bdk_helper_srio_enable(int interface);

/**
 * @INTERNAL
 * Return the link state of an IPD/PKO port as returned by SRIO link status.
 *
 * @param ipd_port IPD/PKO port to query
 *
 * @return Link state
 */
extern bdk_helper_link_info_t __bdk_helper_srio_link_get(int ipd_port);

/**
 * @INTERNAL
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
extern int __bdk_helper_srio_link_set(int ipd_port, bdk_helper_link_info_t link_info);


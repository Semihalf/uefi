/**
 * @file
 *
 * Functions for RGMII/GMII/MII initialization, configuration,
 * and monitoring.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * @INTERNAL
 * Probe RGMII ports and determine the number present
 *
 * @param interface Interface to probe
 *
 * @return Number of RGMII/GMII/MII ports (0-4).
 */
extern int __bdk_helper_rgmii_probe(int interface);

/**
 * Put an RGMII interface in loopback mode. Internal packets sent
 * out will be received back again on the same port. Externally
 * received packets will echo back out.
 *
 * @param port   IPD port number to loop.
 */
extern void bdk_helper_rgmii_internal_loopback(int port);

/**
 * @INTERNAL
 * Configure all of the ASX, GMX, and PKO regsiters required
 * to get RGMII to function on the supplied interface.
 *
 * @param interface PKO Interface to configure (0 or 1)
 *
 * @return Zero on success
 */
extern int __bdk_helper_rgmii_enable(int interface);

/**
 * @INTERNAL
 * Return the link state of an IPD/PKO port as returned by
 * auto negotiation. The result of this function may not match
 * Octeon's link config if auto negotiation has changed since
 * the last call to bdk_helper_link_set().
 *
 * @param ipd_port IPD/PKO port to query
 *
 * @return Link state
 */
extern bdk_helper_link_info_t __bdk_helper_rgmii_link_get(int ipd_port);

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
extern int __bdk_helper_rgmii_link_set(int ipd_port, bdk_helper_link_info_t link_info);

/**
 * @INTERNAL
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
extern int __bdk_helper_rgmii_configure_loopback(int ipd_port, int enable_internal, int enable_external);


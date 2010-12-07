/**
 * @file
 *
 * Functions for NPI initialization, configuration,
 * and monitoring.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * @INTERNAL
 * Probe a NPI interface and determine the number of ports
 * connected to it. The NPI interface should still be down after
 * this call.
 *
 * @param interface Interface to probe
 *
 * @return Number of ports on the interface. Zero to disable.
 */
extern int __bdk_helper_npi_probe(int interface);

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
extern int __bdk_helper_npi_enable(int interface);


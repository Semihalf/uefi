/**
 * @file
 *
 * Fixes and workaround for Octeon chip errata. This file
 * contains functions called by cvmx-helper to workaround known
 * chip errata. For the most part, code doesn't need to call
 * these functions directly.
 *
 * <hr>$Revision: 50963 $<hr>
 */

/**
 * Due to errata G-720, the 2nd order CDR circuit on CN52XX pass
 * 1 doesn't work properly. The following code disables 2nd order
 * CDR for the specified QLM.
 *
 * @param qlm    QLM to disable 2nd order CDR for.
 */
extern void __bdk_helper_errata_qlm_disable_2nd_order_cdr(int qlm);


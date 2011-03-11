/**
 * @file
 *
 * Functions for controlling the TCP/IP network stack.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup netstack Network TCP/IP stack
 * @{
 */

int bdk_netstack_initialize(long flags);
int bdk_netstack_if_add(const char *name, long flags);
int bdk_netstack_if_add_all(long flags);

/** @} */

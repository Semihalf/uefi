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
int bdk_netstack_if_configure(const char *name, const char *ip, const char *netmask, const char *gw);
uint32_t bdk_netstack_if_get_ip(const char *name);
uint32_t bdk_netstack_if_get_netmask(const char *name);
uint32_t bdk_netstack_if_get_gw(const char *name);

/** @} */

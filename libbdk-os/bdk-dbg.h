/**
 * @file
 *
 * Utility functions for low level debug
 *
 * @defgroup debug Low level debug
 * @{
 */

/**
 * The routine in this file are called when some unknown bad thing has happened.
 * They bypass the normal output mechanism and push characters directly to the
 * uart. Hopefully this will allow them to work when everything else has died.
 *
 * @param c      Character to print
 */
extern void bdk_dbg_uart_char(char c);

/**
 * Write a low level string
 *
 * @param s      String to write
 */
extern void bdk_dbg_uart_str(const char *s);

/**
 * Write a low level 64bit number in hex
 *
 * @param value  Value to write
 */
extern void bdk_dbg_uart_hex(uint64_t value);

/**
 * Dump multiple samples of all cores out of reset on the given node
 *
 * @param node   Node to dump core PCs for
 */
extern void bdk_dbg_dump_pc(bdk_node_t node);

/** @} */

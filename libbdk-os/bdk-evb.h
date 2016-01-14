/**
 * @file
 *
 * Utility functions specific to Cavium evaluation boards
 *
 * @defgroup evb Cavium evaluation boards
 * @{
 */

/**
 * Intialize the LED display on a Cavium evaluation board. This is an eight
 * character display.
 *
 * @param node   Node the display is on
 */
extern void bdk_evb_display_init(bdk_node_t node);

/**
 * Write a single character to the display
 *
 * @param node   Node the display is on
 * @param loc    Location to write (0-7). Zero is left most, 7 is right most
 * @param c      Character to write
 */
extern void bdk_evb_display_write_char(bdk_node_t node, int loc, char c);

/**
 * Write a string to the display
 *
 * @param node   Node the display is on
 * @param str    String to display
 */
extern void bdk_evb_display_write_str(bdk_node_t node, const char *str);

/** @} */

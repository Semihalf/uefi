/**
 * @file
 *
 * Core initialization functions
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup thread Threading library
 * @{
 */

/**
 * Call this function to take secondary cores out of reset and have
 * them start running threads
 *
 * @param node     Node to use in a Numa setup. Can be an exact ID or a special
 *                 value.
 * @param coremask Cores to start. Zero is a shortcut for all.
 *
 * @return Zero on success, negative on failure.
 */
extern int bdk_init_cores(bdk_node_t node, uint64_t coremask);

/**
 * Call this function to take secondary nodes and cores out of
 * reset and have them start running threads
 *
 * @return Zero on success, negative on failure.
 */
extern int bdk_init_nodes(void);

/**
 * This function is the first function run on all cores once the
 * threading system takes over.
 *
 * @param arg
 * @param arg1
 */
extern void __bdk_init_main(int arg, void *arg1);

/**
 * Set the baud rate on a UART
 *
 * @param node     Node to use in a Numa setup. Can be an exact ID or a special
 *                 value.
 * @param uart     uart to set
 * @param baudrate Baud rate (9600, 19200, 115200, etc)
 * @param use_flow_control
 *                 Non zero if hardware flow control should be enabled
 */
extern void bdk_set_baudrate(bdk_node_t node, int uart, int baudrate, int use_flow_control);

#ifndef BDK_SHOW_BOOT_BANNERS
#define BDK_SHOW_BOOT_BANNERS 1
#endif

#define BDK_UART_BAUDRATE 115200
//#define BDK_UART_BAUDRATE 921600

/** @}  */

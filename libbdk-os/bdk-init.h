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
 * @param coremask Cores to start. Zero is a shortcut for all.
 *
 * @return Zero on success, negative on failure.
 */
extern int bdk_init_cores(uint64_t coremask);

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
 * @param uart     uart to set
 * @param baudrate Baud rate (9600, 19200, 115200, etc)
 * @param use_flow_control
 *                 Non zero if hardware flow control should be enabled
 */
extern void bdk_set_baudrate(int uart, int baudrate, int use_flow_control);

#ifndef BDK_SHOW_BOOT_BANNERS
#define BDK_SHOW_BOOT_BANNERS 1
#endif

/** @}  */

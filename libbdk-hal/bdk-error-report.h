/**
 * @file
 *
 * Interface to hardware error reporting.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Call this function to check if any error interrupts are
 * set in the chip.
 */
extern void (*bdk_error_check)(void) BDK_WEAK;

/**
 * Call this function to setup error enables.
 */
extern void bdk_error_enable(void) BDK_WEAK;

/** @} */

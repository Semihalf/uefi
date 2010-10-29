/**
 * @file
 *
 * General Purpose IO interface.
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * Clear the interrupt rising edge detector for the supplied
 * pins in the mask. Chips which have more than 16 GPIO pins
 * can't use them for interrupts.
 *
 * @param clear_mask Mask of pins to clear
 */
extern void bdk_gpio_interrupt_clear(uint16_t clear_mask);

/**
 * GPIO Read Data
 *
 * @return Status of the GPIO pins
 */
extern uint32_t bdk_gpio_read(void);

/**
 * GPIO Clear pin
 *
 * @param clear_mask Bit mask to indicate which bits to drive to '0'.
 */
extern void bdk_gpio_clear(uint32_t clear_mask);

/**
 * GPIO Set pin
 *
 * @param set_mask Bit mask to indicate which bits to drive to '1'.
 */
extern void bdk_gpio_set(uint32_t set_mask);


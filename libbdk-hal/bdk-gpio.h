/**
 * @file
 *
 * General Purpose IO interface.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */


/**
 * Initialize a single GPIO as either an input or output. If it is
 * an output, also set its output value.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param gpio      GPIO to initialize
 * @param is_output Non zero if this GPIO should be an output
 * @param output_value
 *                  Value of the GPIO if it should be an output. Not used if the
 *                  GPIO isn't an output.
 *
 * @return Zero on success, negative ob failure
 */
extern int bdk_gpio_initialize(bdk_node_t node, int gpio, int is_output, int output_value);

/**
 * GPIO Read Data
 *
 * @return Status of the GPIO pins
 */
extern uint64_t bdk_gpio_read(bdk_node_t node);

/**
 * GPIO Clear pin
 *
 * @param node       Node to use in a Numa setup. Can be an exact ID or a
 *                   special value.
 * @param clear_mask Bit mask to indicate which bits to drive to '0'.
 */
extern void bdk_gpio_clear(bdk_node_t node, uint64_t clear_mask);

/**
 * GPIO Set pin
 *
 * @param node     Node to use in a Numa setup. Can be an exact ID or a special
 *                 value.
 * @param set_mask Bit mask to indicate which bits to drive to '1'.
 */
extern void bdk_gpio_set(bdk_node_t node, uint64_t set_mask);

/** @} */

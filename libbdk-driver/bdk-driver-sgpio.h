/**
 * @file
 *
 * Serial GPIO interface (SGPIO)
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */
#ifndef _BDK_DRIVER_SGPIO_H_
#define _BDK_DRIVER_SGPIO_H_

typedef enum
{
    BDK_SGPIO_LED_ACT,
    BDK_SGPIO_LED_LOC,
    BDK_SGPIO_LED_ERR,
} bdk_sgpio_led_t;

typedef enum
{
    BDK_SGPIO_STATIC_ON     = BDK_SGP_TX_ACT_E_STATIC_ON,
    BDK_SGPIO_STATIC_OFF    = BDK_SGP_TX_ACT_E_STATIC_OFF,
    BDK_SGPIO_BLINK         = BDK_SGP_TX_ACT_E_A_ON_OFF,
} bdk_sgpio_led_state_t;


/**
 * Get the SGPIO controller state
 *
 * @param node      CPU node number
 *
 * @return          1 == Controller is enabled, 0 == Controller is disabled
 */
int bdk_sgpio_is_enabled(bdk_node_t node);

/**
 * Set the mode for a specific LED.
 *
 * @param node      CPU node number
 * @param drive     Drive number of LED (0-15)
 * @param led       LED type:
 *                       BDK_SGPIO_LED_ACT
 *                       BDK_SGPIO_LED_ERR
 *                       BDK_SGPIO_LED_LOC
 *
 * @return
 */
void bdk_sgpio_set_led_state(bdk_node_t node, int drive, int led, int state);

/**
 * Get the mode for a specific LED.
 *
 * @param node      CPU node number
 * @param drive     Drive number of LED (0-15)
 * @param led       LED type:
 *                       BDK_SGPIO_LED_ACT
 *                       BDK_SGPIO_LED_ERR
 *                       BDK_SGPIO_LED_LOC
 *
 * @return          LED state:
 *                      BDK_SGPIO_STATIC_ON
 *                      BDK_SGPIO_STATIC_OFF
 *                      BDK_SGPIO_BLINK
 */
int bdk_sgpio_get_led_state(bdk_node_t node, int drive, int led);

/**
 * Set the controller's SCLOCK frequency
 *
 * @param node      CPU node number
 * @param freq      Frequency to set
 *
 * @return Zero on success, negative on failure
 */
int bdk_sgpio_set_sclock(bdk_node_t node, int freq);

/**
 * Enable / disable controller
 *
 * @param node      CPU node number
 * @param ena       zero = disable, non-zero = enable
 *
 * @return
 */
void bdk_sgpio_enable_controller(bdk_node_t node, int ena);

/**
 * Set up SGPIO pin muxing based on environment.
 *
 * @param node      CPU node number
 *
 * @return Zero on success, negative on failure
 */
int bdk_sgpio_setup_gpio_pins(bdk_node_t node);

/**
 * Initialize the SGPIO controller.
 *  - Set up the SGPIO pin muxing as per configuration environment.
 *  - Turn all LEDs off
 *  - Set the blink rate to 1/2 second
 *  - Enable the controller
 *
 * @param node      CPU node number
 *
 * @return Zero on success, negative on failure
 */
int bdk_sgpio_initialize(bdk_node_t node);

/** @} */

#endif /* _BDK_DRIVER_SGPIO_H_ */

/**
 * Functions for reporting DRAM init status through GPIOs.
 * Useful for triggering scopes and such. Internal use only.
 */

extern void pulse_gpio_pin(bdk_node_t node, int pin, int usecs);


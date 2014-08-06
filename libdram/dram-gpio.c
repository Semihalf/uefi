#include <bdk.h>
#include "dram-internal.h"

void pulse_gpio_pin(bdk_node_t node, int pin, int usecs)
{
    static int configured_pin = 0;

    if (!(configured_pin & 1 << pin))
    {
        configured_pin |= 1 << pin;
        bdk_gpio_initialize(node, pin, 1, 0);
    }
    bdk_gpio_clear(node, 1 << pin);
    bdk_wait_usec(usecs);
    bdk_gpio_set(node, 1 << pin);
}


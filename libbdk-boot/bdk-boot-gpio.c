#include <bdk.h>

/**
 * Configure GPIO on all nodes as part of booting
 */
void bdk_boot_gpio(void)
{
    const int NUM_GPIO = bdk_gpio_get_num();
    for (bdk_node_t n = BDK_NODE_0; n < BDK_NUMA_MAX_NODES; n++)
    {
        if (bdk_numa_exists(n))
        {
            for (int gpio = 0; gpio < NUM_GPIO; gpio++)
            {
                int pin_sel = bdk_config_get_int(BDK_CONFIG_GPIO_PIN_SELECT, gpio, n);
                if (pin_sel >= 0)
                {
                    BDK_TRACE(INIT, "Connecting N%d.GPIO%d to pin select 0x%x\n",
                        n, gpio, pin_sel);
                    bdk_gpio_select_pin(n, gpio, pin_sel);
                }
            }
        }
    }
}

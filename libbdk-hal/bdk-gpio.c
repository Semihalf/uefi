#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(GPIO);

/**
 * Initialize a single GPIO as either an input or output. If it is
 * an output, also set its output value.
 *
 * @param gpio      GPIO to initialize
 * @param is_output Non zero if this GPIO should be an output
 * @param output_value
 *                  Value of the GPIO if it should be an output. Not used if the
 *                  GPIO isn't an output.
 *
 * @return Zero on success, negative ob failure
 */
int bdk_gpio_initialize(bdk_node_t node, int gpio, int is_output, int output_value)
{
    if (output_value)
        bdk_gpio_set(node, 1<<gpio);
    else
        bdk_gpio_clear(node, 1<<gpio);

    if (gpio < 20)
    {
        BDK_CSR_DEFINE(cfg, BDK_GPIO_BIT_CFGX(gpio));
        cfg.u = 0;
        cfg.s.tx_oe = !!is_output;
        BDK_CSR_WRITE(node, BDK_GPIO_BIT_CFGX(gpio), cfg.u);
    }
    else
    {
        bdk_error("bdk_gpio_initialize: Illegal GPIO\n");
        return -1;
    }
    return 0;
}


/**
 * GPIO Read Data
 *
 * @return Status of the GPIO pins
 */
uint32_t bdk_gpio_read(bdk_node_t node)
{
    bdk_gpio_rx_dat_t gpio_rx_dat;
    gpio_rx_dat.u = BDK_CSR_READ(node, BDK_GPIO_RX_DAT);
    return gpio_rx_dat.s.dat;
}


/**
 * GPIO Clear pin
 *
 * @param clear_mask Bit mask to indicate which bits to drive to '0'.
 */
void bdk_gpio_clear(bdk_node_t node, uint32_t clear_mask)
{
    bdk_gpio_tx_clr_t gpio_tx_clr;
    gpio_tx_clr.u = 0;
    gpio_tx_clr.s.clr = clear_mask;
    BDK_CSR_WRITE(node, BDK_GPIO_TX_CLR, gpio_tx_clr.u);
}


/**
 * GPIO Set pin
 *
 * @param set_mask Bit mask to indicate which bits to drive to '1'.
 */
void bdk_gpio_set(bdk_node_t node, uint32_t set_mask)
{
    bdk_gpio_tx_set_t gpio_tx_set;
    gpio_tx_set.u = 0;
    gpio_tx_set.s.set = set_mask;
    BDK_CSR_WRITE(node, BDK_GPIO_TX_SET, gpio_tx_set.u);
}


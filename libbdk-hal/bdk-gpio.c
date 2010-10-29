#include <bdk.h>

/**
 * Clear the interrupt rising edge detector for the supplied
 * pins in the mask. Chips which have more than 16 GPIO pins
 * can't use them for interrupts.
 *
 * @param clear_mask Mask of pins to clear
 */
void bdk_gpio_interrupt_clear(uint16_t clear_mask)
{
    bdk_gpio_int_clr_t gpio_int_clr;
    gpio_int_clr.u64 = 0;
    gpio_int_clr.s.type = clear_mask;
    BDK_CSR_WRITE(BDK_GPIO_INT_CLR, gpio_int_clr.u64);
}


/**
 * GPIO Read Data
 *
 * @return Status of the GPIO pins
 */
uint32_t bdk_gpio_read(void)
{
    bdk_gpio_rx_dat_t gpio_rx_dat;
    gpio_rx_dat.u64 = BDK_CSR_READ(BDK_GPIO_RX_DAT);
    return gpio_rx_dat.s.dat;
}


/**
 * GPIO Clear pin
 *
 * @param clear_mask Bit mask to indicate which bits to drive to '0'.
 */
void bdk_gpio_clear(uint32_t clear_mask)
{
    bdk_gpio_tx_clr_t gpio_tx_clr;
    gpio_tx_clr.u64 = 0;
    gpio_tx_clr.s.clr = clear_mask;
    BDK_CSR_WRITE(BDK_GPIO_TX_CLR, gpio_tx_clr.u64);
}


/**
 * GPIO Set pin
 *
 * @param set_mask Bit mask to indicate which bits to drive to '1'.
 */
void bdk_gpio_set(uint32_t set_mask)
{
    bdk_gpio_tx_set_t gpio_tx_set;
    gpio_tx_set.u64 = 0;
    gpio_tx_set.s.set = set_mask;
    BDK_CSR_WRITE(BDK_GPIO_TX_SET, gpio_tx_set.u64);
}


#include <bdk.h>
#include "platform.h"

/**
 * GPIO Operations
 *
 * @param port
 * @param pinmask
 * @param op
 *
 * @return
 */
pio_type platform_pio_op( unsigned port, pio_type pinmask, int op )
{
    int pin;

    BDK_CLZ(pin, pinmask);
    pin = 31 - pin;

    switch (op)
    {
        case PLATFORM_IO_PIN_SET:
            bdk_gpio_set(pinmask);
            break;

        case PLATFORM_IO_PIN_CLEAR:
            bdk_gpio_clear(pinmask);
            break;

        case PLATFORM_IO_PIN_GET:
            return bdk_gpio_read() & pinmask;

        case PLATFORM_IO_PIN_DIR_INPUT:
            BDK_CSR_MODIFY(cfg, BDK_GPIO_BIT_CFGX(pin),
                cfg.s.tx_oe = 0);
            break;

        case PLATFORM_IO_PIN_DIR_OUTPUT:
            BDK_CSR_MODIFY(cfg, BDK_GPIO_BIT_CFGX(pin),
                cfg.s.tx_oe = 1);
            break;

        case PLATFORM_IO_PIN_PULLUP:
        case PLATFORM_IO_PIN_PULLDOWN:
        case PLATFORM_IO_PIN_NOPULL:
            /* Not supported */
            break;

        case PLATFORM_IO_PORT_SET_VALUE:
            bdk_gpio_clear(~pinmask);
            bdk_gpio_set(pinmask);
            break;

        case PLATFORM_IO_PORT_GET_VALUE:
            return bdk_gpio_read();

        case PLATFORM_IO_PORT_DIR_INPUT:
        case PLATFORM_IO_PORT_DIR_OUTPUT:
            /* Not supported */
            break;
    }
    return 0;
}


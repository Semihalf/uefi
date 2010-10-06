#include <bdk.h>
#include "platform.h"

/**
 * Setup the UART
 *
 * @param id
 * @param baud
 * @param databits
 * @param parity
 * @param stopbits
 *
 * @return
 */
u32 platform_uart_setup( unsigned id, u32 baud, int databits, int parity, int stopbits )
{
    // FIXME
    return 0;
}

/**
 * Send a byte to the uart
 *
 * @param id
 * @param data
 */
void platform_uart_send( unsigned id, u8 data )
{
    u64 lsrval;

    /* Spin until there is room */
    do
    {
        lsrval = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
    } while ((lsrval & (1<<5)) == 0);
    /* Write the byte */
    BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), data);
}

/**
 * Receive a uart byte
 *
 * @param id
 * @param timeout
 *
 * @return
 */
int platform_s_uart_recv( unsigned id, s32 timeout )
{
    if (timeout == PLATFORM_UART_INFINITE_TIMEOUT)
    {
        u64 lsrval;
        do
        {
            lsrval = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        } while ((lsrval & 1) == 0);
        /* Read the byte */
        return BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
    }
    else if (BDK_CSR_WAIT_FOR_FIELD(BDK_MIO_UARTX_LSR(id), dr, ==, 1, timeout))
        return -1;
    else
        return BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
}


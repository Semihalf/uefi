#include <bdk.h>
#include "platform.h"

u32 platform_uart_setup( unsigned id, u32 baud, int databits, int parity, int stopbits )
{
  return 0;
}

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

int platform_s_uart_recv( unsigned id, s32 timeout )
{
    if (timeout == PLATFORM_UART_INFINITE_TIMEOUT)
    {
        u64 lsrval;
        do
        {
            lsrval = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        } while ((lsrval & 1) == 0);
        return BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
    }
    else if (BDK_CSR_READ(BDK_MIO_UARTX_LSR(id)) & 1)
        return BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
    else
        return -1;
}


#include <bdk.h>
#include <fcntl.h>

extern int bdk_interrupt_flag;

static void *uart_open(const char *name, int flags)
{
    long id = atoi(name);
    if ((id < 0) || (id >= 2))
        return NULL;
    /* Return the uart number plus one as our internal state */
    if (flags & O_NOCTTY)
        return (void*)(id+1 + 0x100);
    else
        return (void*)(id+1);
}

static int uart_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int count = 0;
    int id = ((long)handle->fs_state & 0xff) - 1;
    BDK_CSR_DEFINE(lsr, BDK_MIO_UARTX_LSR(id));

    while (count == 0)
    {
        lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        bdk_interrupt_flag |= lsr.s.bi;
        if (!lsr.s.dr)
        {
            if (length == 1)
                return count;
            bdk_thread_yield();
        }
        while (lsr.s.dr && length)
        {
            *(uint8_t*)buffer = BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
            lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
            bdk_interrupt_flag |= lsr.s.bi;
            buffer++;
            count++;
            length--;
        }
    }
    return count;
}

static int uart_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    BDK_CSR_DEFINE(lsr, BDK_MIO_UARTX_LSR(id));
    int l = length;
    int id = ((long)handle->fs_state & 0xff) - 1;
    const char *p = buffer;

    while (l--)
    {
        if ((*p =='\n') && (((long)handle->fs_state & 0x100) == 0))
        {
            /* Spin until there is room */
            while (1)
            {
                lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
                bdk_interrupt_flag |= lsr.s.bi;
                if (lsr.s.thre)
                    break;
                bdk_thread_yield();
            }
            /* Write the byte */
            BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), '\r');
        }

        /* Spin until there is room */
        while (1)
        {
            lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
            bdk_interrupt_flag |= lsr.s.bi;
            if (lsr.s.thre)
                break;
            bdk_thread_yield();
        }
        /* Write the byte */
        BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), *p);
        p++;
    }
    return length;
}

const __bdk_fs_ops_t bdk_fs_uart_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = uart_open,
    .close = NULL,
    .lseek = NULL,
    .read = uart_read,
    .write = uart_write,
};


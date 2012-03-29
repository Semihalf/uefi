#include <bdk.h>

static void *uart_open(const char *name, int flags)
{
    long id = atoi(name);
    if ((id < 0) || (id >= 2))
        return NULL;
    /* Return the uart number plus one as our internal state */
    return (void*)(id+1);
}

static int uart_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int count = 0;
    int id = (long)handle->fs_state - 1;

    BDK_CSR_INIT(lsr, BDK_MIO_UARTX_LSR(id));
    while (lsr.s.dr && length)
    {
        int has_error = lsr.s.ferr;
        *(uint8_t*)buffer = BDK_CSR_READ(BDK_MIO_UARTX_RBR(id));
        lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        /* Character has an error, so skip it */
        if (has_error)
            continue;
        buffer++;
        count++;
        length--;
    }
    return count;
}

static void uart_write_byte(int id, uint8_t byte)
{
    static bdk_spinlock_t tx_lock;
    BDK_CSR_DEFINE(lsr, BDK_MIO_UARTX_LSR(id));

    /* Spin until there is room */
    while (1)
    {
        bdk_spinlock_lock(&tx_lock);
        lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        if (lsr.s.thre)
        {
            /* Write the byte */
            BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), 0xff & byte);
            bdk_spinlock_unlock(&tx_lock);
            break;
        }
        bdk_spinlock_unlock(&tx_lock);
        do
        {
            bdk_thread_yield();
            lsr.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(id));
        } while (!lsr.s.thre);
    }
}

static int uart_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int l = length;
    int id = (long)handle->fs_state - 1;
    const char *p = buffer;

    while (l--)
        uart_write_byte(id, *p++);
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


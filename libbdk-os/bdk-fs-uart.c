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

static void uart_write_byte(int id, uint8_t byte)
{
    BDK_CSR_DEFINE(lsr, BDK_MIO_UARTX_LSR(id));

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
    BDK_CSR_WRITE(BDK_MIO_UARTX_THR(id), 0xff & byte);
}

static int uart_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    static volatile void *owner = NULL;
    int l = length;
    int id = ((long)handle->fs_state & 0xff) - 1;
    int is_console = (((long)handle->fs_state & 0x100) == 0);
    const char *p = buffer;

    /* Consoles have some extra processing compared to files opened with
        the O_NOCTTY flag. Consoles must insert '\r' after every '\n' to
        get the terminal to do newlines properly. It also attempts to
        write lines out as blocks such that multiple core output doesn't
        get jumbled mid line. Files opened with the O_NOCTTY flag are
        considered raw device and don't do any of this processing. This is
        useful for XMODEM */

    if (is_console)
    {
        void *me = bdk_thread_get_id();
        if (owner != me)
        {
            void *current_owner;
            do
            {
                current_owner = (void*)owner;
                /* Spin waiting for another thread to finish it's current line */
                uint64_t timeout = bdk_clock_get_count(BDK_CLOCK_CORE) + bdk_clock_get_rate(BDK_CLOCK_CORE);
                while (current_owner && (bdk_clock_get_count(BDK_CLOCK_CORE) < timeout))
                {
                    bdk_thread_yield();
                    current_owner = (void*)owner;
                }
                /* Take ownership of the uarts */
            } while (bdk_atomic_compare_and_store64_nosync((uint64_t*)&owner, (uint64_t)current_owner, (uint64_t)me) == 0);
        }
    }
    else
        owner = NULL;

    while (l--)
    {
        if ((*p =='\n') && is_console)
        {
            uart_write_byte(id, '\r');
            uart_write_byte(id, '\n');

            /* Release ownership if we have no more data */
            if (!l)
            {
                owner = NULL;
                BDK_SYNCW;
            }
        }
        else
            uart_write_byte(id, *p);
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


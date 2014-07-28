#include <bdk.h>

static void *uart_open(const char *name, int flags)
{
    long id = atoi(name);
    if ((id < 0) || (id >= 2))
        return NULL;
    /* Return the uart number plus one as our internal state */
    long state = id + 1;
    state += bdk_numa_local() << 8;
    return (void*)state;
}

static int uart_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int count = 0;
    int id = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;

    BDK_CSR_INIT(fr, node, BDK_UAAX_FR(id));
    while (!fr.s.rxfe && length)
    {
        BDK_CSR_INIT(dr, node, BDK_UAAX_DR(id));
        int has_error = dr.s.fe;
        *(uint8_t*)buffer = dr.s.data;
        fr.u = BDK_CSR_READ(node, BDK_UAAX_FR(id));
        /* Character has an error, so skip it */
        if (has_error)
            continue;
        buffer++;
        count++;
        length--;
    }
    return count;
}

static void uart_write_byte(bdk_node_t node, int id, uint8_t byte)
{
    static bdk_spinlock_t tx_lock;
    BDK_CSR_INIT(fr, node, BDK_UAAX_FR(id));

    /* Spin until there is room */
    while (1)
    {
        bdk_spinlock_lock(&tx_lock);
        fr.u = BDK_CSR_READ(node, BDK_UAAX_FR(id));
        if (!fr.s.txff) /* Are we not full? */
        {
            /* Write the byte */
            BDK_CSR_WRITE(node, BDK_UAAX_DR(id), byte);
            bdk_spinlock_unlock(&tx_lock);
            break;
        }
        bdk_spinlock_unlock(&tx_lock);
        do
        {
            bdk_thread_yield();
            fr.u = BDK_CSR_READ(node, BDK_UAAX_FR(id));
        } while (fr.s.txff); /* Spin while full */
    }
}

static int uart_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int l = length;
    int id = ((long)handle->fs_state - 1) & 0xff;
    bdk_node_t node = (long)handle->fs_state >> 8;
    const char *p = buffer;

    while (l--)
        uart_write_byte(node, id, *p++);
    return length;
}

const __bdk_fs_ops_t bdk_fs_uart_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = uart_open,
    .close = NULL,
    .read = uart_read,
    .write = uart_write,
};


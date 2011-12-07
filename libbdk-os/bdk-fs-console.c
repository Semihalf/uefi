#include <bdk.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_CONSOLE_FILES 8
static int open_files[MAX_CONSOLE_FILES] = {3,4,};
static int last_input;
static char pending_rx[32];
static int pending_rx_count = 0;

int console_open_file(const char *filename)
{
    int fd = open(filename, O_RDWR, 0);
    if (fd < 0)
    {
        bdk_error("Failed to open console file %s\n", filename);
        return -1;
    }

    for (int i=0; i<MAX_CONSOLE_FILES; i++)
    {
        if (open_files[i] == 0)
        {
            open_files[i] = fd;
            return i;
        }
    }
    close(fd);
    bdk_error("Too many open console files\n");
    return -1;
}

static void *console_open(const char *name, int flags)
{
    /* This is never called as the C library assumes stdin, stdout, and stderr
        are already open */
    return open_files;
}

static int console_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    static uint64_t last_tx_cycle;
    static void *last_tx_thread = NULL;
    const uint64_t timeout = (bdk_is_simulation()) ? 100 : bdk_clock_get_rate(BDK_CLOCK_CORE) / 20;
    int fd = open_files[last_input];
    const char *ptr = buffer;
    int len = length;

    /* Spin giving another thread time to finish its output. We mandate an idle
        time of 50ms between two different threads doing output to try and stop
        interleaving of output */
    void *me = bdk_thread_get_id();
    while (last_tx_thread != me)
    {
        uint64_t cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
        while (cycle < (last_tx_cycle + timeout))
        {
            bdk_thread_yield();
            cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
        }
        if (bdk_atomic_compare_and_store64_nosync(&last_tx_cycle, last_tx_cycle, cycle))
            last_tx_thread = me;
    }

    while (len)
    {
        /* Send all bytes up until the \n */
        int count = 0;
        while ((count < len) && (ptr[count] != '\n'))
            count++;
        if (count && (write(fd, ptr, count) < 0))
            goto error;
        /* Send a \r\n if we found a \n */
        if ((count < len) && (ptr[count] == '\n'))
        {
            if (write(fd, "\r\n", 2) < 0)
                goto error;
            count++;
        }
        ptr += count;
        len -= count;
    }
    /* Update the last ouptut time in case output took a long time */
    last_tx_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    return length;
error:
    close(fd);
    open_files[last_input] = 0;
    last_input = 0;
    return length;
}

static int console_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    while (1)
    {
        for (int i=0; i<MAX_CONSOLE_FILES; i++)
        {
            if (!open_files[i])
                continue;
            if (pending_rx_count)
            {
                int len = pending_rx_count;
                if (length < len)
                    len = length;
                memcpy(buffer, pending_rx, len);
                pending_rx_count -= len;
                if (pending_rx_count)
                    memcpy(pending_rx, pending_rx+len, pending_rx_count);
                return len;
            }
            int bytes = read(open_files[i], buffer, length);
            if (bytes > 0)
            {
                last_input = i;
                return bytes;
            }
            else if ((i>1) && (bytes == 0))
            {
                /* Close dead scokets */
                close(open_files[i]);
                open_files[i] = 0;
                if (i == last_input)
                    last_input = 0;
            }
        }
        bdk_thread_yield();
        if (length == 1)
            break;
    }
    return 0;
}

/**
 * This function is called periodically for Control-C processing
 *
 * @return Non zero if a Control-C is seen
 */
int __bdk_fs_check_break(void)
{
    char c;
    int result = console_read(NULL, &c, 1);
    if (result != 1)
        return 0;

    /* Check for Control-C */
    if (c == 0x3)
    {
        /* Cancel any buffered RX when we receive a Contorl-C */
        pending_rx_count = 0;
        return 1;
    }
    else
    {
        /* Store this character in our internal buffer */
        if (pending_rx_count < (int)sizeof(pending_rx))
            pending_rx[pending_rx_count++] = c;
        return 0;
    }
}

const __bdk_fs_ops_t bdk_fs_console_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = console_open,
    .close = NULL,
    .lseek = NULL,
    .read = console_read,
    .write = console_write,
};


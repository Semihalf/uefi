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
    int fd = open_files[last_input];
    const char *ptr = buffer;
    int len = length;
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
            int bytes;
            if (pending_rx_count)
            {
                *(char*)buffer = pending_rx[0];
                pending_rx_count--;
                memcpy(pending_rx, pending_rx+1, pending_rx_count);
                bytes = 1;
            }
            else
                bytes = read(open_files[i], buffer, 1);
            if (bytes > 0)
            {
                /* Translate telnet backspace into the normal byte */
                if (*(char*)buffer == 0x7f)
                    *(char*)buffer = '\b';
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
        if (length == 1)
            break;
        bdk_thread_yield();
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


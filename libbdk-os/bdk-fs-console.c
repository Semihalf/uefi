#include <bdk.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_CONSOLE_FILES 4
static int open_files[MAX_CONSOLE_FILES] = {3,};
static int last_input;
int readline_enable = 1;

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
    return length;
}

static int console_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    if ((length > 1) && readline_enable)
    {
        /* As a special case use readline when requesting multiple bytes.
            Note that readline will call this function again for its input,
            but the read length will be one */
        const char *line = bdk_readline("", NULL, 0);
        int result = strlen(line);
        result++;
        if (result > length)
            result = length;
        memcpy(buffer, line, result);
        ((char*)buffer)[result-1] = '\n';
        return result;
    }

    do
    {
        for (int i=0; i<MAX_CONSOLE_FILES; i++)
        {
            if (!open_files[i])
                continue;
            int bytes = read(open_files[i], buffer, 1);
            if (bytes > 0)
            {
                last_input = i;
                return bytes;
            }
        }
        if (!readline_enable)
            bdk_thread_yield();
    } while (!readline_enable);
    return 0;
}

/**
 * This function is called periodically for Control-C processing
 *
 * @return Non zero if a Control-C is seen
 */
int bdk_fs_check_break(void)
{
    char c;
    int result = console_read(NULL, &c, 1);
    return (result == 1) && (c == 0x3);
}


/**
 * Enable or disable automatic usage or readline for input. This
 * is used by RPC to temporarily stop readline while executing
 * a call.
 *
 * @param enable New readline state
 */
void bdk_fs_readline_enable(int enable)
{
    readline_enable = enable;
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


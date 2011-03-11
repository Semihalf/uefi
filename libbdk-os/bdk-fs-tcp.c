#include <bdk.h>
#include <fcntl.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

static void *tcp_open(const char *name, int flags)
{
    struct addrinfo *addr;
    char *nodename = strdup(name);
    if (!nodename)
        return NULL;
    char *port = strchr(nodename, ':');
    if (!port)
    {
        free(nodename);
        return NULL;
    }
    *port = 0;
    port++;

    int status = lwip_getaddrinfo(nodename, port, NULL, &addr);
    if (status)
    {
        bdk_error("lwip_getaddrinfo() failed\n");
        free(nodename);
        return NULL;
    }
    free(nodename);

    int sock = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        bdk_error("lwip_socket() failed\n");
        free(addr);
        return NULL;
    }

    status = lwip_connect(sock, addr->ai_addr, addr->ai_addrlen);
    free(addr);
    if (status)
    {
        bdk_error("lwip_connect() failed\n");
        lwip_close(sock);
        return NULL;
    }

    return (void*)(long)(sock + 1);
}


static int tcp_close(__bdk_fs_file_t *handle)
{
    int sock = (long)handle->fs_state - 1;
    return lwip_close(sock);
}


static int tcp_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int sock = (long)handle->fs_state - 1;
    return lwip_read(sock, buffer, length);
}


static int tcp_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int sock = (long)handle->fs_state - 1;
    return lwip_write(sock, buffer, length);
}

const __bdk_fs_ops_t bdk_fs_tcp_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = tcp_open,
    .close = tcp_close,
    .lseek = NULL,
    .read = tcp_read,
    .write = tcp_write,
};


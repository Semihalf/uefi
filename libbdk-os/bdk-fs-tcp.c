#include <bdk.h>
#include <fcntl.h>
#include <lwip/sockets.h>
#include <lwip/netdb.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_TCP);

static bdk_spinlock_t lock;

static void *tcp_open(const char *name, int flags)
{
    /* As a special hack for sockets that are already created, a name which
        starts with a '@' is assumed to be a socket number. This is used
        by the telnet server to pass already created sockets */
    if (name[0] == '@')
    {
        int sock = atoi(name+1);
        return (void*)(long)(sock + 1);
    }

    struct addrinfo *addr;
    char *nodename = strdup(name);
    if (!nodename)
    {
        errno = ENOENT;
        return NULL;
    }
    char *port = strchr(nodename, ':');
    if (!port)
    {
        free(nodename);
        errno = ENOENT;
        return NULL;
    }
    *port = 0;
    port++;

    bdk_spinlock_lock(&lock);
    int status = lwip_getaddrinfo(nodename, port, NULL, &addr);
    if (status)
    {
        bdk_spinlock_unlock(&lock);
        bdk_error("lwip_getaddrinfo() failed\n");
        free(nodename);
        errno = status;
        return NULL;
    }
    free(nodename);

    int sock = lwip_socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0)
    {
        bdk_spinlock_unlock(&lock);
        bdk_error("lwip_socket() failed\n");
        free(addr);
        return NULL;
    }

    status = lwip_connect(sock, addr->ai_addr, addr->ai_addrlen);
    free(addr);
    if (status)
    {
        lwip_close(sock);
        bdk_spinlock_unlock(&lock);
        bdk_error("lwip_connect() failed\n");
        return NULL;
    }
    bdk_spinlock_unlock(&lock);

    return (void*)(long)(sock + 1);
}


static int tcp_close(__bdk_fs_file_t *handle)
{
    int sock = (long)handle->fs_state - 1;
    bdk_spinlock_lock(&lock);
    int status = lwip_close(sock);
    bdk_spinlock_unlock(&lock);
    return status;
}


static int tcp_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    int sock = (long)handle->fs_state - 1;
    bdk_spinlock_lock(&lock);
    int bytes;
    if (length == 1)
        bytes = lwip_recvfrom(sock, buffer, length, MSG_DONTWAIT, NULL, NULL);
    else
        bytes = lwip_recvfrom(sock, buffer, length, 0, NULL, NULL);
    bdk_spinlock_unlock(&lock);
    return bytes;
}


static int tcp_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    int sock = (long)handle->fs_state - 1;
    bdk_spinlock_lock(&lock);
    int bytes = lwip_write(sock, buffer, length);
    bdk_spinlock_unlock(&lock);
    return bytes;
}

static const __bdk_fs_ops_t bdk_fs_tcp_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = tcp_open,
    .close = tcp_close,
    .lseek = NULL,
    .read = tcp_read,
    .write = tcp_write,
};

int bdk_fs_tcp_init(void)
{
    bdk_spinlock_init(&lock);
    return bdk_fs_register("/tcp/", &bdk_fs_tcp_ops);
}


#include <bdk.h>
#include <lwip/sockets.h>

#ifndef BDK_DISABLE_LWIP

static void telnet_server(int unused, void *unused2)
{
    int sock = lwip_socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0)
    {
        bdk_error("lwip_socket() failed: %s\n", strerror(errno));
        return;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));

    addr.sin_len = sizeof(addr);
    addr.sin_family = AF_INET;
    addr.sin_port = htons(23);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (lwip_bind(sock, (struct sockaddr *)&addr, sizeof(addr)))
    {
        bdk_error("lwip_bind() failed: %s\n", strerror(errno));
        goto out;
    }

    if (lwip_listen(sock, 5))
    {
        bdk_error("lwip_listen() failed: %s\n", strerror(errno));
        goto out;
    }

    while (1)
    {
        int new_sock = lwip_accept(sock, NULL, NULL);
        if (new_sock < 0)
        {
            bdk_error("lwip_accept() failed: %s\n", strerror(errno));
            break;
        }
        /* Tell telnet that we receive binary data */
        const uint8_t rx_binary[] = {255, 253, 0};
        lwip_write(new_sock, rx_binary, sizeof(rx_binary));
        /* Tell telnet that we transmit binary data */
        const uint8_t tx_binary[] = {255, 251, 0};
        lwip_write(new_sock, tx_binary, sizeof(tx_binary));
        /* Set no delay */
        int one = 1;
        lwip_setsockopt(new_sock, IPPROTO_TCP, TCP_NODELAY, &one, sizeof(one));
        /* Open the TCP file object */
        char filename[8];
        sprintf(filename, "/tcp/@%d\n", new_sock);
        extern int console_open_file(const char *filename);
        if (console_open_file(filename) < 0)
        {
            bdk_error("console_open_file() failed\n");
            lwip_close(new_sock);
        }
    }
out:
    lwip_close(sock);
    printf("Telnet: Server stopped\n");
}

/**
 * Called to initialize the Telnet server
 *
 * @return Zero on success, negative on failure
 */
int bdk_telnet_server_initialize(void)
{
    static int init_complete = 0;
    /* Return if we've already been called */
    if (init_complete)
        return 0;

    int result = bdk_thread_create(0, telnet_server, 0, NULL, 0);
    if (result == 0)
    {
        init_complete = 1;
        printf("Telnet: Server started\n");
    }
    return result;
}

#endif /* BDK_DISABLE_LWIP */



#include <bdk.h>
#include <lwip/udp.h>
#include <unistd.h>
#include <fcntl.h>

#define MAX_TFTP 2  /* Max number of simultaneous transfers */

typedef struct
{
    int init_complete;
    struct
    {
        ip_addr_t   remote_addr;        /* Remote IP this conenction is for */
        uint16_t    remote_port;        /* Remote port this conenction is for */
        int         handle;             /* File handle */
        int         block_size;         /* Transfer block size */
        int         last_block_size;    /* Size of the last block transfered */
        int         is_write;           /* Is this file open for write? */
        uint32_t    sequence_id;        /* Current sequence ID */
    } open_files[MAX_TFTP];
} tftp_server_t;


/**
 * Get a free context for a new connection
 *
 * @param state  TFTP state
 *
 * @return Context number or negative on failure
 */
static int tftp_server_get_free_file(tftp_server_t *state)
{
    for (int i=0; i<MAX_TFTP; i++)
    {
        if (state->open_files[i].handle == 0)
            return i;
    }
    bdk_error("TFTP: Max number of open connections reached\n");
    return -1;
}


/**
 * Get the context assoctiated with an open transfer
 *
 * @param state  TFTP state
 * @param addr   Remote address
 * @param port   Remote port
 *
 * @return COntext number or negative on failure
 */
static int tftp_server_get_file(tftp_server_t *state, ip_addr_t addr, uint16_t port)
{
    for (int i=0; i<MAX_TFTP; i++)
    {
        if (state->open_files[i].handle &&
            (state->open_files[i].remote_addr.addr == addr.addr) &&
            (state->open_files[i].remote_port == port))
            return i;
    }
    bdk_error("TFTP: Request for unknown state\n");
    return -1;
}


/**
 * Send a block of data to the remote client
 *
 * @param state  TFTP state
 * @param pcb    UDP socket state
 * @param fileid Which conenction is this for
 *
 * @return Zero on success, negative on failure
 */
static int tftp_server_send_block(tftp_server_t *state, struct udp_pcb *pcb, int fileid)
{
    struct pbuf *pout = pbuf_alloc(PBUF_TRANSPORT, 4 + state->open_files[fileid].block_size, PBUF_RAM);
    if (!pout)
    {
        bdk_error("TFTP: tftp_server_send_block: pbuf_alloc() failed\n");
        return -1;
    }

    *(uint16_t*)pout->payload = htons(3);
    *(uint16_t*)(pout->payload+2) = htons(state->open_files[fileid].sequence_id);

    int count = read(state->open_files[fileid].handle, pout->payload + 4, state->open_files[fileid].block_size);
    if (count < 0)
    {
        bdk_error("TFTP: tftp_server_send_block: read() failed\n");
        pbuf_free(pout);
        return -1;
    }

    pbuf_realloc(pout, count + 4);

    if (udp_sendto(pcb, pout, &state->open_files[fileid].remote_addr, state->open_files[fileid].remote_port))
    {
        bdk_error("TFTP: tftp_server_send_block: udp_sendto() failed\n");
        pbuf_free(pout);
        return -1;
    }
    state->open_files[fileid].last_block_size = count;
    return 0;
}


/**
 * Send an ACK to the remote client
 *
 * @param state  TFTP state
 * @param pcb    UDP socket state
 * @param fileid Which conenction is this for
 *
 * @return Zero on success, negative on failure
 */
static int tftp_server_send_ack(tftp_server_t *state, struct udp_pcb *pcb, int fileid)
{
    struct pbuf *pout = pbuf_alloc(PBUF_TRANSPORT, 4, PBUF_RAM);
    if (!pout)
    {
        bdk_error("TFTP: tftp_server_send_ack: pbuf_alloc() failed\n");
        return -1;
    }

    *(uint16_t*)pout->payload = htons(4);
    *(uint16_t*)(pout->payload+2) = htons(state->open_files[fileid].sequence_id);

    if (udp_sendto(pcb, pout, &state->open_files[fileid].remote_addr, state->open_files[fileid].remote_port))
    {
        bdk_error("TFTP: tftp_server_send_ack: udp_sendto() failed\n");
        pbuf_free(pout);
        return -1;
    }
    return 0;
}


/**
 * Send an error to the remote client
 *
 * @param state   TFTP state
 * @param pcb     UDP socket state
 * @param fileid  Which conenction is this for
 * @param code    Error code
 * @param message Error message
 */
static void tftp_server_send_error(tftp_server_t *state, struct udp_pcb *pcb, int fileid, int code, const char *message)
{
    int message_len = strlen(message);
    struct pbuf *pout = pbuf_alloc(PBUF_TRANSPORT, 4 + message_len + 1, PBUF_RAM);
    if (!pout)
    {
        bdk_error("TFTP: tftp_server_send_error: pbuf_alloc() failed\n");
        goto skip;
    }

    *(uint16_t*)pout->payload = htons(5);
    *(uint16_t*)(pout->payload+2) = htons(code);
    memcpy(pout->payload + 4, message, message_len);
    *(char*)(pout->payload + 4 + message_len) = 0;

    if (udp_sendto(pcb, pout, &state->open_files[fileid].remote_addr, state->open_files[fileid].remote_port))
    {
        bdk_error("TFTP: tftp_server_send_error: udp_sendto() failed\n");
        pbuf_free(pout);
    }

skip:
    /* Close the connection state */
    if (state->open_files[fileid].handle)
        close(state->open_files[fileid].handle);
    memset(&state->open_files[fileid], 0, sizeof(state->open_files[fileid]));
}


/**
 * Called by the network stack when a TFTP packet is received.
 *
 * @param arg    TFTP state
 * @param pcb    UDP socket state
 * @param p      Received packet
 * @param addr   Remote IP address
 * @param port   Remote port
 */
static void tftp_server_rx(void *arg, struct udp_pcb *pcb, struct pbuf *p, ip_addr_t *addr, u16_t port)
{
    tftp_server_t *state = arg;
    ip_addr_t raddr = *addr;

    /* Be lazy and require the packet to be linear buffer */
    p = pbuf_coalesce(p, PBUF_TRANSPORT);

    /* Get the opcode */
    uint16_t opcode = ntohs(*(uint16_t*)p->payload);

    switch (opcode)
    {
        case 1: /* Read request (RRQ) */
        {
            int fileid = tftp_server_get_free_file(state);
            if (fileid == -1)
                goto skip;

            const char *filename = p->payload + 2;
            int handle = open(filename, O_RDONLY);
            if (handle < 0)
            {
                tftp_server_send_error(state, pcb, fileid, 1, "Unable to open file");
                goto skip;
            }

            state->open_files[fileid].remote_addr = raddr;
            state->open_files[fileid].remote_port = port;
            state->open_files[fileid].handle = handle;
            state->open_files[fileid].block_size = 512;
            state->open_files[fileid].is_write = 0;
            state->open_files[fileid].sequence_id = 1;

            tftp_server_send_block(state, pcb, fileid);
            break;
        }

        case 2: /* Write request (WRQ) */
        {
            int fileid = tftp_server_get_free_file(state);
            if (fileid == -1)
                goto skip;

            const char *filename = p->payload + 2;
            int handle = open(filename, O_WRONLY|O_CREAT);
            if (handle < 0)
            {
                tftp_server_send_error(state, pcb, fileid, 1, "Unable to open file");
                goto skip;
            }

            state->open_files[fileid].remote_addr = raddr;
            state->open_files[fileid].remote_port = port;
            state->open_files[fileid].handle = handle;
            state->open_files[fileid].block_size = 512;
            state->open_files[fileid].is_write = 1;
            state->open_files[fileid].sequence_id = 0;

            if (tftp_server_send_ack(state, pcb, fileid))
                goto skip;
            state->open_files[fileid].sequence_id++;
            break;
        }

        case 3: /* Data (DATA) */
        {
            int fileid = tftp_server_get_file(state, raddr, port);
            if (fileid == -1)
                goto skip;

            if (!state->open_files[fileid].is_write)
            {
                tftp_server_send_error(state, pcb, fileid, 2, "Attempt to write to a file not open for write");
                goto skip;
            }

            uint16_t seq = ntohs(*(uint16_t*)(p->payload + 2));
            if (seq != (state->open_files[fileid].sequence_id & 0xffff))
            {
                tftp_server_send_error(state, pcb, fileid, 4, "Out of order DATA");
                goto skip;
            }

            int len = p->tot_len - 4;
            if (len > 0)
            {
                if ((int)write(state->open_files[fileid].handle, p->payload + 4, len) != len)
                {
                    tftp_server_send_error(state, pcb, fileid, 3, "File full");
                    goto skip;
                }
            }

            /* Send ACK */
            if (tftp_server_send_ack(state, pcb, fileid))
                goto skip;

            state->open_files[fileid].sequence_id++;
            if (len < state->open_files[fileid].block_size)
            {
                close(state->open_files[fileid].handle);
                memset(&state->open_files[fileid], 0, sizeof(state->open_files[fileid]));
            }
            break;
        }

        case 4: /* Acknowledgment (ACK) */
        {
            int fileid = tftp_server_get_file(state, raddr, port);
            if (fileid == -1)
                goto skip;

            if (state->open_files[fileid].is_write)
            {
                tftp_server_send_error(state, pcb, fileid, 2, "Attempt to read from a file not open for read");
                goto skip;
            }

            uint16_t seq = ntohs(*(uint16_t*)(p->payload + 2));
            if (seq != (state->open_files[fileid].sequence_id & 0xffff))
            {
                tftp_server_send_error(state, pcb, fileid, 4, "Out of order ACK");
                goto skip;
            }

            if (state->open_files[fileid].last_block_size < state->open_files[fileid].block_size)
            {
                close(state->open_files[fileid].handle);
                memset(&state->open_files[fileid], 0, sizeof(state->open_files[fileid]));
                goto skip;
            }

            /* Send DATA */
            state->open_files[fileid].sequence_id++;
            tftp_server_send_block(state, pcb, fileid);
            break;
        }

        case 5: /* Error (ERROR) */
        {
            int fileid = tftp_server_get_file(state, raddr, port);
            if (fileid >= 0)
            {
                close(state->open_files[fileid].handle);
                memset(&state->open_files[fileid], 0, sizeof(state->open_files[fileid]));
            }
            break;
        }

        default:
        {
            int fileid = tftp_server_get_file(state, raddr, port);
            if (fileid >= 0)
                tftp_server_send_error(state, pcb, fileid, 4, "Unexpected opcode");
            break;
        }
    }

skip:
    pbuf_free(p);
}


/**
 * Called to initialize the TFTP server
 *
 * @return Zero on success, negative on failure
 */
int bdk_tftp_server_initialize(void)
{
    static tftp_server_t state;

    /* Return if we've already been called */
    if (state.init_complete)
        return 0;

    /* Create a new UDP lwip socket */
    struct udp_pcb *sock = udp_new();
    if (!sock)
    {
        bdk_error("TFTP: udp_new() failed\n");
        return -1;
    }

    /* Bind to the TFTP port */
    if (udp_bind(sock, IP_ADDR_ANY, 69))
    {
        bdk_error("TFTP: udp_bind() failed\n");
        return -1;
    }

    /* Register our receive function */
    udp_recv(sock, tftp_server_rx, &state);

    state.init_complete = 1;

    printf("TFTP: Server started\n");
    return 0;
}




/***********************license start************************************
 * Copyright (c) 2003-2009  Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 * WARNING WARNING WARNING WARNING WARNING
 *
 * INTERNAL-FILE-DO-NOT-RELEASE
 *
 * This file is covered by a Macraigor NDA. It is illegal to distribute
 * this source file. Binaries and ojects made from this file can be
 * distributed, but this source file can't be.
 *
 **********************license end**************************************/

/**
 * @file
 *
 * Interface to Octeon through a Macraigor EJTAG probe
 *
 * $Id: octeon-remote-macraigor.c 55004 2010-11-24 01:18:24Z kreese $
 */
#include <bdk.h>
#include <stdio.h>
#include <netdb.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <resolv.h>
#include <sys/time.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include "octeon-remote.h"

#define ULL unsigned long long
#define MAX_MEMORY_TRANSFER_SIZE 1024
#define USE_EJTAG_PC_SAMPLING 1

typedef enum
{
    CORE_STATE_RUNNING,
    CORE_STATE_STOPPED,
    CORE_STATE_RESET,
    CORE_STATE_BAD
} core_state_t;

/* Each bit represents a valid COP0 register bit=reg*8+sel VALID_COP0[bit/64] |= 1<<(bit%63) */
extern const uint64_t OCTEON_REMOTE_VALID_COP0[];
extern int __octeon_remote_num_cores;

static int sock_fd = -1;
static uint64_t available_core_mask = 0;
static int memory_access_core = 0;
static core_state_t current_core_state[64];
static void enable_64bit_addressing(int core);

static void log_hex(int level, const char *name, void *buffer, int buffer_length)
{
    int i;
    octeon_remote_debug(level, "%s", name);
    for (i=0;i<buffer_length;i++)
        octeon_remote_output(level, "%02x", 0xff & ((char*)buffer)[i]);
    octeon_remote_output(level, "\n");
}

static int do_command(const int core, const uint8_t *command, const int command_length,
                      uint8_t *response, const int response_size)
{
    const uint8_t *ptr;
    char send_buffer[4 + command_length + 1];
    int len;
    int response_length = -1;
    uint8_t c;
    uint8_t csum;
    uint16_t u16;

    /* Send the command checksum */
    ptr = command;
    csum = 0;
    len = command_length;
    while (len--)
        csum += *ptr++;
    csum = -csum;

    send_buffer[0] = 0x55 + core; /* Send the target select */
    send_buffer[1] = 0xfe; /* Send the command length */
    *(uint16_t*)(send_buffer+2) = bdk_cpu_to_be16(command_length);
    memcpy(send_buffer+4, command, command_length);
    send_buffer[4+command_length] = csum;
    log_hex(4, "Request: ", send_buffer, 5+command_length);
    write(sock_fd, send_buffer, 5+command_length);

    /* Read the target select */
    len = read(sock_fd, &c, 1);
    if (len != 1)
    {
        octeon_remote_debug(-1, "EJTAG Target read failed\n");
        return -1;
    }
    if ((c != 0x55) && (c != 0x55 + core))
    {
        octeon_remote_debug(-1, "EJTAG Target select doesn't match\n");
        return -1;
    }

    /* Read the length */
    len = read(sock_fd, &c, 1);
    if (len != 1)
    {
        octeon_remote_debug(-1, "EJTAG length marker read failed\n");
        return -1;
    }
    if (c != 0xfe)
    {
        octeon_remote_debug(-1, "EJTAG Incorrect response\n");
        return -1;
    }
    len = read(sock_fd, &u16, 2);
    if (len != 2)
    {
        octeon_remote_debug(-1, "EJTAG length read failed\n");
        return -1;
    }
    response_length = bdk_be16_to_cpu(u16);
    if (response_length < 8)
    {
        octeon_remote_debug(-1, "EJTAG Length (%d) too short\n", response_length);
        return -1;
    }
    if (response_length-4 > response_size)
    {
        octeon_remote_debug(-1, "EJTAG Length (%d) too big\n", response_length);
        return -1;
    }
    /* Read the response with checksum */
    len = read(sock_fd, response, response_length-4);
    if (len != response_length-4)
    {
        octeon_remote_debug(-1, "EJTAG Target read failed\n");
        return -1;
    }

    char reply_name[64];
    sprintf(reply_name, "Reply: %02x fe %04x ", 0x55 + core, response_length);
    log_hex(4, reply_name, response, len);

    /* Check the checksum */
    csum = 0;
    ptr = response;
    len = response_length-5;
    while (len--)
        csum += *ptr++;
    csum = -csum;
    if (csum != response[response_length-5])
    {
        octeon_remote_debug(-1, "EJTAG Incorrect checksum\n");
        return -1;
    }

    /* Make sure response matches the command */
    if (response[0] != command[0])
    {
        octeon_remote_debug(-1, "EJTAG Incorrect command reply\n");
        return -1;
    }

    // FIXME: status is response[1]

    /* Make sure response is not an error */
    if ((response[2] != 0) && (response[2] != 6))
    {
        octeon_remote_debug(2, "EJTAG Error 0x%x\n", (int)response[2]);
        const char *message;
        switch (response[2])
        {
            case 0x01:
                message = "Unknown Fault: the interface cannot get a valid response back from the target and cannotdetermine why this is happening.";
                break;
            case 0x02:
                message = "Power Failed: the command cannot be executed because power is not applied to the target.";
                break;
            case 0x03:
                message = "Cable: the command cannot be executed because the target cable is disconnected.";
                break;
            case 0x04:
                message = "Response: the interface was not able to put the target in background mode.";
                break;
            case 0x05:
                message = "Reset: the command could not be executed because the target was being held in reset.";
                break;
            case 0x06:
                message = "The interface to the target has not yet been configured using the initialize command.";
                break;
            case 0x07:
                message = "Write Verify: after writing data to target memory, the value read back from the same location did not match what was written.";
                break;
            case 0x08:
                message = "Register buffer error: an attempt was made to read or write an MPC5xx floating point register without first setting the register buffer address.";
            case 0x09:
                message = "Invalid Register code: the host sent a command which attempted to access a CPU register which is not implemented on the target being controlled.";
                break;
            case 0x0a:
                message = "Command Not Implemented.";
                break;
            case 0x0b:
                message = "Clock frozen: unable to detect target clock.";
                break;
            case 0x0c:
                message = "Processor Running.";
                break;
            case 0x0d:
                message = "Command Error: an illegal command was received from the host.";
                break;
            case 0x0e:
                message = "Command parameter error: a command was received with an illegal or out-of-range parameter.";
                break;
            case 0x0f:
                message = "Internal processing error: an error occurred within the debug interface while processing the command.";
                break;
            case 0x10:
                message = "unknown/invalid port specified.";
                break;
            case 0x11:
                message = "Bus Error.";
                break;
            case 0x12:
                message = "Command Checksum: A command received from the host had a checksum error.";
                break;
            case 0x13:
                message = "Illegal Command : Command not allowed for this CPU type.";
                break;
            case 0x14:
                message = "Invalid parameter value for this command.";
                break;
            case 0x15:
                message = "Internal Error.";
                break;
            case 0x16:
                message = "Internal Flash Memory Error.";
                break;
            case 0x17:
                message = "Appropriate target driver not found/loaded.";
                break;
            case 0x18:
                message = "BDM error.";
                break;
            case 0x19:
                message = "Buffer Full.";
                break;
            case 0x1e:
                message = "Command Timeout.";
                break;
            case 0x1f:
                message = "DMA busy.";
                break;
            case 0x20:
                message = "Jtag can't override.";
                break;
            case 0x21:
                message = "CPU Frozen.";
                break;
            case 0x22:
                message = "Can't stop MCU.";
                break;
            default:
                message = "Unknown error.";
                break;
        }
        octeon_remote_debug(2, "Error Message: %s\n", message);
        return -(int)response[2];
    }
    /* Return the response length */
    return response_length-4;
}

static core_state_t get_core_state(int core)
{
    uint8_t command[1];
    uint8_t response[4];

    command[0] = 0; /* Are you there */
    response[1] = 0;
    int l = do_command(core, command, 1, response, sizeof(response));
    if (l==4)
    {
        if (response[1] & 1)
        {
            octeon_remote_debug(2, "Core %d in reset\n", core);
            current_core_state[core] = CORE_STATE_RESET;
            return current_core_state[core];
        }
        else if (response[1] & 4)
        {
            octeon_remote_debug(2, "Core %d is stopped\n", core);
            current_core_state[core] = CORE_STATE_STOPPED;
            return current_core_state[core];
        }
        else
        {
            octeon_remote_debug(2, "Core %d is running\n", core);
            current_core_state[core] = CORE_STATE_RUNNING;
            return current_core_state[core];
        }
    }
    octeon_remote_debug(2, "Core %d in bad state\n", core);
    current_core_state[core] = CORE_STATE_BAD;
    return current_core_state[core];
}

static core_state_t conditional_stop_core(int core)
{
    if (current_core_state[core] == CORE_STATE_STOPPED)
        return current_core_state[core];

    core_state_t old_state = get_core_state(core);

    if (old_state == CORE_STATE_RUNNING)
    {
        octeon_remote_debug(2, "Stopping core %d\n", core);
        uint8_t command[1];
        uint8_t response[4];
        command[0] = 0x22; /* Stop */
        do_command(core, command, 1, response, sizeof(response));
    }
    return old_state;
}

static void conditional_start_core(int core, core_state_t state)
{
    uint8_t command[1];
    uint8_t response[4];

    if (state != CORE_STATE_RUNNING)
        return;

    octeon_remote_debug(2, "Starting core %d\n", core);
    command[0] = 0x20; /* Run */
    do_command(core, command, 1, response, sizeof(response));
    current_core_state[core] = CORE_STATE_RUNNING;
}


/**
 * Called when octeon_remote_open() is called using a remote spec
 * for MACRAIGOR.
 *
 * @param remote_spec
 *               String specification of the remote to connect to.
 *
 * @return Zero on success, negative on failure.
 */
static int macraigor_open(const char *remote_spec)
{
    /* Remote spec = "MACRAIGOR:<name>,<tcp_port>[,<jtag_speed>]" */
    uint8_t command[256];
    uint8_t response[256];
    const char *host_ipaddr = "1.2.3.4";
    char local_spec[80];
    int jtag_speed;
    int i;
    int l;

    strncpy(local_spec,  remote_spec,  sizeof(local_spec));
    local_spec[sizeof(local_spec)-1] = 0;

    char *save_ptr = NULL;
    const char *spec_type = strtok_r(local_spec, ":", &save_ptr);
    const char *name = strtok_r(NULL, ",", &save_ptr);
    const char *port_str = strtok_r(NULL, ",", &save_ptr);
    const char *speed_str = strtok_r(NULL, ",", &save_ptr);

    if (!spec_type || !name || !port_str)
    {
        octeon_remote_debug(-1, "Illegal protocol \"%s\"\n", remote_spec);
        return -1;
    }
    int port = atoi(port_str);

    if (speed_str)
        jtag_speed = atoi(speed_str);
    else
        jtag_speed = 1;
    octeon_remote_debug(1, "Ejtag %s:%d speed=%d\n", name, port, jtag_speed);

    struct hostent *host_info = gethostbyname(name);
    if (!host_info)
    {
        octeon_remote_perror(-1, "hostname lookup failed\n");
        return -1;
    }

    /* Set up socket structure */
    struct sockaddr_in ejtag_addr;
    memset(&ejtag_addr, 0, sizeof(ejtag_addr));
    ejtag_addr.sin_family = AF_INET;
    ejtag_addr.sin_addr.s_addr = ((struct in_addr *)(host_info->h_addr))->s_addr;
    ejtag_addr.sin_port = htons(port);
    octeon_remote_debug(1, "IP address of probe: %s\n", inet_ntoa(ejtag_addr.sin_addr));

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        octeon_remote_perror(-1, "socket");
        return -1;
    }

    i=1;
    setsockopt(sock_fd, IPPROTO_TCP, TCP_NODELAY, &i, 4);

    int status = connect(sock_fd, (struct sockaddr *)&ejtag_addr, sizeof(ejtag_addr));
    if (status == -1)
    {
        octeon_remote_perror(-1, "connect");
        return -1;
    }

    command[0] = 0; /* Are you there? */
    l = do_command(0, command, 1, response, 4);
    if (l != 4)
    {
        /* Sometime it is necessary to try again after a power cycle */
        l = do_command(0, command, 1, response, 4);
        if (l != 4)
        {
            octeon_remote_debug(-1, "EJTAG not there\n");
            return -1;
        }
    }

    i = 0;
    command[i++] = 0xf0; /* Set connection */
    command[i++] = 0x40; /* Mpdemon magic device number */
    l = strlen(host_ipaddr);
    command[i++] = l; /* Length of host IP address */
    memcpy(command + i, host_ipaddr, l); /* ASCII */
    i+=l;
    l = strlen(port_str);
    command[i++] = l; /* Length of remote port */
    memcpy(command + i, port_str, l); /* ASCII */
    i+=l;
    l = do_command(0, command, i, response, 4);
    if (l != 4)
    {
        octeon_remote_debug(-1, "Unexpected response length %d from connect\n", l);
        return -1;
    }

    int reduced_speed = 0;
    do
    {
        command[0] = 0xf4; /* Analyze JTAG Scan Chain */
        command[1] = 0; /* JTAG Speed */
        command[2] = jtag_speed;
        l = do_command(0, command, i, response, sizeof(response));
        if (l < 12)
        {
            jtag_speed++;
            reduced_speed = 1;
        }
    } while ((l < 12) && (jtag_speed < 8));
    if (l < 12)
    {
        octeon_remote_debug(-1, "Analyze JTAG Scan Chain failed. Probe probably needs a software update\n");
        return -1;
    }
    __octeon_remote_num_cores = bdk_be32_to_cpu(*(uint32_t*)(response+3));
    octeon_remote_debug(2, "Probe detected %d cores\n", __octeon_remote_num_cores);
    if ((__octeon_remote_num_cores < 1) || (__octeon_remote_num_cores > 48))
    {
        octeon_remote_debug(-1, "Illegal number of cores detected (%d)\n", __octeon_remote_num_cores);
        return -1;
    }
    if (reduced_speed)
        octeon_remote_debug(0, "JTAG speed reduced to %d. Board has EJTAG signal problems.\n", jtag_speed);

    i = 0;
    command[i++] = 0x1a; /* Initialize the targets */
    command[i++] = 0;
    command[i++] = jtag_speed; /* JTAG speed */
    command[i++] = 0;
    command[i++] = __octeon_remote_num_cores;
    for (l=0; l< __octeon_remote_num_cores; l++)
        command[i++] = 0x5e; /* All Octeons use the same cpu type */
    l = do_command(0, command, i, response, 4);
    if (l != 4)
    {
        octeon_remote_debug(-1, "Unexpected response length %d from init\n", l);
        return -1;
    }

    i = 0;
    command[i++] = 0x00; /* Select Reset Type */
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0xd1;
    command[i++] = 0x00; /* 7 unused bytes */
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00;
    command[i++] = 0x00; /* 0 = Pin reset, 1 = PrRst */
    l = do_command(0, command, i, response, 4);
    if (l != 4)
    {
        octeon_remote_debug(-1, "Unexpected response length %d from select reset type\n", l);
        return -1;
    }

    available_core_mask = (1ull<<__octeon_remote_num_cores)-1;
    enable_64bit_addressing(0);

    return 0;
}


/**
 * Called when octeon_remote_close() is called.
 */
static void macraigor_close(void)
{
    if (sock_fd != -1)
    {
        close(sock_fd);
        sock_fd = -1;
    }
}


/**
 * Read data from a physical memory address.
 *
 * @param buffer_ptr Buffer to put the data in
 * @param physical_address
 *                   Physical address to read from. Bits 63-38 should be zero.
 * @param length     Length to read in bytes
 */
static void macraigor_read_mem(void *buffer, uint64_t physical_address, int length)
{
    int l;
    static uint8_t command[1 + 8 + 1 + 1 + 2];
    static uint8_t response[3 + 8 + 2 + MAX_MEMORY_TRANSFER_SIZE + 1];

    core_state_t old_state = conditional_stop_core(memory_access_core);

    while (length)
    {
        /* Limit each transfer */
        int seg_length = length;
        if (seg_length > MAX_MEMORY_TRANSFER_SIZE)
            seg_length = MAX_MEMORY_TRANSFER_SIZE;

        int response_length = 3 + 8 + 2 + seg_length + 1;
        command[0] = 0x41; /* Read large memory */
        *(uint64_t*)(command+1) = bdk_cpu_to_be64(physical_address);
        command[9] = 0; /* Auto word size */
        command[10] = 0; /* Normal memory space */
        *(uint16_t*)(command+11) = bdk_cpu_to_be16(seg_length);

        l = do_command(memory_access_core, command, sizeof(command), response, response_length);
        if (l != response_length)
            octeon_remote_debug(-1, "Unexpected response length %d\n", l);

        uint64_t address = bdk_be64_to_cpu(*(uint64_t*)(response+3));
        if (address != physical_address)
            octeon_remote_debug(-1, "Unexpected address 0x%llx\n", (ULL)address);

        l = bdk_be16_to_cpu(*(uint16_t*)(response+11));
        if (seg_length != l)
            octeon_remote_debug(-1, "Unexpected length %d\n", l);
        memcpy(buffer, response + 13, seg_length);
        buffer += seg_length;
        physical_address += seg_length;
        length -= seg_length;
    }
    conditional_start_core(memory_access_core, old_state);
}


/**
 * Write data to a physical memory address
 *
 * @param physical_address
 *                   Physical address to write to. Bits 63-38 should be zero.
 * @param buffer_ptr Buffer containing the data to write
 * @param length     Number of bytes to write
 */
static void macraigor_write_mem(uint64_t physical_address, const void *buffer, int length)
{
    int l;
    static uint8_t command[1 + 8 + 1 + 1 + 1 + 2 + MAX_MEMORY_TRANSFER_SIZE];
    static uint8_t response[3 + 8 + 1];

    core_state_t old_state = conditional_stop_core(memory_access_core);

    while (length)
    {
        /* Limit each transfer */
        int seg_length = length;
        if (seg_length > MAX_MEMORY_TRANSFER_SIZE)
            seg_length = MAX_MEMORY_TRANSFER_SIZE;

        int command_length = 1 + 8 + 1 + 1 + 1 + 2 + seg_length;
        command[0] = 0x40; /* Write large memory */
        *(uint64_t*)(command+1) = bdk_cpu_to_be64(physical_address);
        command[9] = 0; /* Auto word size */
        command[10] = 0; /* No verify */
        command[11] = 0; /* Normal memory space */
        *(uint16_t*)(command+12) = bdk_cpu_to_be16(seg_length);
        memcpy(command+14, buffer, seg_length);

        l = do_command(memory_access_core, command, command_length, response, sizeof(response));
        if (l != (int)sizeof(response))
            octeon_remote_debug(-1, "Unexpected response length %d\n", l);

        uint64_t address = bdk_be64_to_cpu(*(uint64_t*)(response+3));
        if (address != physical_address)
            octeon_remote_debug(-1, "Unexpected address 0x%llx\n", (ULL)address);
        buffer += seg_length;
        physical_address += seg_length;
        length -= seg_length;
    }
    conditional_start_core(memory_access_core, old_state);
}


/**
 * Return the Processor ID of the Octeon. This should be identical
 * to the value found in the COP0 PRID register
 *
 * @return Processor ID
 */
static uint32_t macraigor_get_model(void)
{
    /* Directly read the Processor ID register */
    return octeon_remote_read_register(0, 0x100 + 15*8 + 0);
}


/**
 * Take the cores in the bit vector out of the debug exception.
 *
 * @param start_mask Cores to start
 */
static void macraigor_start_cores(uint64_t start_mask)
{
    int core;
    uint8_t command[1];
    uint8_t response[3 + 1];

    start_mask &= available_core_mask;

    command[0] = 0x20; /* Run */
    for (core=0;core<64; core++)
        if (start_mask & (1ull<<core))
            if (get_core_state(core) == CORE_STATE_STOPPED)
            {
                do_command(core, command, 1, response, sizeof(response));
                current_core_state[core] = CORE_STATE_RUNNING;
            }
}


/**
 * Cause the cores in the stop mask to take a debug exception
 *
 * @param stop_mask Cores to stop
 */
static void macraigor_stop_cores(uint64_t stop_mask)
{
    int core;

    stop_mask &= available_core_mask;

    for (core=0;core<64; core++)
        if (stop_mask & (1ull<<core))
            conditional_stop_core(core);
}


/**
 * Get a mask where each bit represents a running core. If a core
 * is in the debug exception handler, it's bit will be zero.
 *
 * @return Bit set for every running core
 */
static uint64_t macraigor_get_running_cores(void)
{
    uint64_t result;
    int core;
    uint8_t command[1];
    uint8_t response[3 + 1];

    command[0] = 0; /* Are you there */
    result = 0;
    for (core=0;core<64; core++)
    {
        if (available_core_mask & (1ull<<core))
        {
            response[1] = 0;
            int l = do_command(core, command, 1, response, sizeof(response));
            if ((l==4) && ((response[1] & 4) == 0))
                result |= 1ull << core;
        }
    }
    return result;
}


/**
 * Read a register
 *
 * @param core   Core to read
 * @param reg    Register to read
 *
 * @return Value of the register
 */
static uint64_t macraigor_read_register(int core, int reg)
{
    uint8_t command[1 + 4];
    uint8_t response[3 + 1 + 8 + 1];
    int reg_id;

    if ((available_core_mask & (1ull<<core)) == 0)
        return 0;

    if (reg<32)
        reg_id = reg;
    else if (reg == 32)
        reg_id = 0x101;
    else if (reg == 33)
        reg_id = 0x100;
    else if ((reg >= 0x100) && (reg< 0x200) && (OCTEON_REMOTE_VALID_COP0[(reg-0x100)/64] & (1ull<<(reg&63))))
        reg_id = 0x200 + ((reg>>3)&0x1f) + ((reg&7)<<5);
    else
        return 0x0bad0bad0bad0badull;

    command[0] = 0x30; /* Read register */
    *(uint16_t*)(command+1) = bdk_cpu_to_be16(reg_id);
    *(uint16_t*)(command+3) = bdk_cpu_to_be16(reg_id);

    core_state_t old_state = conditional_stop_core(core);
    if ((old_state != CORE_STATE_RUNNING) && (old_state != CORE_STATE_STOPPED))
        return 0x0bad0bad0bad0badull;
    int l = do_command(core, command, sizeof(command), response, sizeof(response));
    conditional_start_core(core, old_state);

    if (l != (int)sizeof(response))
    {
        octeon_remote_debug(-1, "Unexpected response length %d\n", l);
        return 0x0bad0bad0bad0badull;
    }

    if (response[3] != 8)
    {
        octeon_remote_debug(-1, "Unexpected response number\n");
        return 0x0bad0bad0bad0badull;
    }

    return bdk_be64_to_cpu(*(uint64_t*)(response+4));
}


/**
 * Write a register
 *
 * @param core   Core to write
 * @param reg    Register to write
 * @param value  Value to write
 */
static void macraigor_write_register(int core, int reg, uint64_t value)
{
    uint8_t command[1 + 2 + 1 + 8];
    uint8_t response[3 + 1];
    int reg_id;

    if ((available_core_mask & (1ull<<core)) == 0)
        return;

    if (reg<32)
        reg_id = reg;
    else if (reg == 32)
        reg_id = 0x101;
    else if (reg == 33)
        reg_id = 0x100;
    else if ((reg >= 0x100) && (reg< 0x200) && (OCTEON_REMOTE_VALID_COP0[(reg-0x100)/64] & (1ull<<(reg&63))))
        reg_id = 0x200 + ((reg>>3)&0x1f) + ((reg&7)<<5);
    else
        return;

    command[0] = 0x31; /* Write register */
    *(uint16_t*)(command+1) = bdk_cpu_to_be16(reg_id);
    command[3] = 8;
    *(uint64_t*)(command+4) = bdk_cpu_to_be64(value);

    core_state_t old_state = conditional_stop_core(core);
    if ((old_state != CORE_STATE_RUNNING) && (old_state != CORE_STATE_STOPPED))
        return;
    int l = do_command(core, command, sizeof(command), response, sizeof(response));
    conditional_start_core(core, old_state);

    if (l != (int)sizeof(response))
        octeon_remote_debug(-1, "Unexpected response length %d\n", l);
}


/**
 * Get all registers, COP0, TLB, etc for a core
 *
 * @param core      Core to get state info for
 * @param registers All of the core's internal state
 *
 * @return Zero on success, negative on failure
 */
static int macraigor_get_core_state(int core, octeon_remote_registers_t *registers)
{
    int r;

    if ((available_core_mask & (1ull<<core)) == 0)
        return -1;

    core_state_t old_state = conditional_stop_core(core);
    if ((old_state != CORE_STATE_RUNNING) && (old_state != CORE_STATE_STOPPED))
        return -1;

    for (r=0; r<0x200; r++)
        registers->regs[r>>8][r&0xff] = macraigor_read_register(core, r);

    /* FIXME: The probe will truncate 64bit EntryLo* registers to 32bits */

    int tlb_num = TLB_SIZE;
    int tlb_per_transfer = 16;

    int index;
    for (index = 0; index < tlb_num; index += tlb_per_transfer)
    {
        uint8_t command[1 + 8 + 1 + 1 + 2];
        uint8_t response[3 + 8 + 2 + 24*tlb_per_transfer + 1];

        command[0] = 0x41; /* Read large memory */
        *(uint64_t*)(command+1) = bdk_cpu_to_be64(index);
        command[9] = 8; /* word size */
        command[10] = 5; /* TLB memory space */
        *(uint16_t*)(command+11) = bdk_cpu_to_be16(24*tlb_per_transfer);
        int l = do_command(core, command, sizeof(command), response, sizeof(response));
        if (l != 13+24*tlb_per_transfer+1)
        {
            octeon_remote_debug(-1, "Unexpected response length %d\n", l);
            for (r=0; r<tlb_per_transfer; r++)
            {
                registers->tlb[index+r][0] = 0x0bad0bad0bad0badull;
                registers->tlb[index+r][1] = 0x0bad0bad0bad0badull;
                registers->tlb[index+r][2] = 0x0bad0bad0bad0badull;
                registers->tlb[index+r][3] = 0x0bad0bad0bad0badull;
            }
        }
        else
        {
            for (r=0; r<tlb_per_transfer; r++)
            {
                registers->tlb[index+r][1] = bdk_be64_to_cpu(*(uint64_t*)(response+13 + 24*r));
                registers->tlb[index+r][0] = bdk_be64_to_cpu(*(uint64_t*)(response+21 + 24*r));
                registers->tlb[index+r][3] = bdk_be32_to_cpu(*(uint32_t*)(response+29 + 24*r));
                registers->tlb[index+r][2] = bdk_be32_to_cpu(*(uint32_t*)(response+33 + 24*r));
            }
        }
    }

    conditional_start_core(core, old_state);
    return 0;
}


/**
 * Set all registers, COP0, TLB, etc for a given core
 *
 * @param core      Core to set state for
 * @param registers All date for the core
 *
 * @return Zero on success, negative on failure
 */
static int macraigor_set_core_state(int core, const octeon_remote_registers_t *registers)
{
    int r;

    if ((available_core_mask & (1ull<<core)) == 0)
        return -1;

    core_state_t old_state = conditional_stop_core(core);
    if ((old_state != CORE_STATE_RUNNING) && (old_state != CORE_STATE_STOPPED))
        return -1;

    for (r=0; r<0x200; r++)
        macraigor_write_register(core, r, registers->regs[r>>8][r&0xff]);

    /* FIXME: The probe will truncate 64bit EntryLo* registers to 32bits. For
        this reason we don't implement writing the TLB */

    conditional_start_core(core, old_state);
    return 0;
}


/**
 * Enable 64bit addressing so we can get to CSRs
 *
 * @param core   Core to enable accesses for.
 */
static void enable_64bit_addressing(int core)
{
    /* Force 64 bit addressing on so we can access CSRs */
    uint64_t status = octeon_remote_read_register(core, 0x100 + 12*8 + 0);
    if (status & (1<<7))
        return;
    status |= 1<<7;
    octeon_remote_write_register(core, 0x100 + 12*8 + 0, status);
}


/**
 * Reset the core/chip
 *
 * @param stop_core Stop core 0 from booting.
 *
 * @return Zero on success, negative on failure
 */
static int macraigor_reset(int stop_core)
{
    uint8_t command[2];
    uint8_t response[4];
    if (stop_core)
    {
        command[0] = 0x24; /* Reset and halt */
        command[1] = 0xdc;
    }
    else
    {
        command[0] = 0x23; /* Reset and run */
        command[1] = 0xdd;
    }
    conditional_stop_core(0);
    do_command(0, command, 2, response, sizeof(response));
    sleep(1);
    if (stop_core)
    {
        conditional_stop_core(0);
        /* Force DEPC */
        octeon_remote_write_register(0, 0x100 + 24*8 + 0, 0xffffffffbfc00000ull);
    }
    enable_64bit_addressing(0);
    return 0;
}


/**
 * Sample performance / profiling information for a set of cores
 * minimizing the performance impact of taking the sample. The
 * amount of data returned may vary depending on the remote
 * protocol used, but at least the program counter for each core
 * will normally be supported. Values that could not be sampled
 * will be zero.
 *
 * @param coremask Each set bit represent a core that should be sampled.
 * @param sample   Array of samples to populate. Note that the sample array must
 *                 contain elements for cores not set in the coremask. These may
 *                 be filled with sample data even if the coremask bit is clear.
 *                 Some transports may sample all core efficiently and yield
 *                 unwanted core samples.
 *
 * @return Zero on success, negative on failure
 */
static int macraigor_get_sample(uint64_t coremask, octeon_remote_sample_t sample[64])
{
    int core;
    for (core=0; core<64; core++)
    {
        if ((1ull<<core) & coremask)
        {
            macraigor_stop_cores(1ull<<core);
            sample[core].pc = macraigor_read_register(core, 0x100 + 24*8 + 0);
            sample[core].perf_count[0] = macraigor_read_register(core, 0x100 + 25*8 + 1);
            sample[core].perf_count[1] = macraigor_read_register(core, 0x100 + 25*8 + 3);
            macraigor_start_cores(1ull<<core);
        }
    }
    return 0;
}


/**
 * Sample performance / profiling information for a set of cores
 * using EJTAG PC Sampling. Performance counters will be zero.
 *
 * @param coremask Each set bit represent a core that should be sampled.
 * @param sample   Array of samples to populate. Note that the sample array must
 *                 contain elements for cores not set in the coremask. These may
 *                 be filled with sample data even if the coremask bit is clear.
 *                 Some transports may sample all core efficiently and yield
 *                 unwanted core samples.
 *
 * @return Zero on success, negative on failure
 */
static int macraigor_get_sample_pc(uint64_t coremask __attribute__ ((unused)), octeon_remote_sample_t sample[64])
{
    #define ROUND_BYTES(bits) (((bits)+7)>>3)
    uint8_t command[1024];
    uint8_t response[1024];
    int len;
    int total_bits;
    int core;

    /* Tell every core to set the JTAG instruction to 0x14, which is read the
        PC samples. We need 5 bits per core clocked out */
    total_bits = 5 * __octeon_remote_num_cores;
    memset(command, 0, sizeof(command));
    command[0] = 0xf2;  /* JTAG_SCAN_IO */
    command[1] = 0;     /* Instruction */
    *(uint64_t*)(command+2) = bdk_cpu_to_be16(total_bits);
    *(uint64_t*)(command+4) = bdk_cpu_to_be16(ROUND_BYTES(total_bits));
    uint8_t *ptr = command + 6;
    for (core=0; core<__octeon_remote_num_cores; core+=8)
    {
        /* Each core needs the five bits 10100. Eight cores together ends up
            needing 40 bits, which is a nice even number of bytes. This is why
            this loop fills 8 cores at a time. Extra bits don't get used */
        /* 1010 0101 0010 1001 0100 1010 0101 0010 1001 0100 */
        /*    a    5    2    9    4    a    5    2    9    4 */
        *ptr++ = 0x94; /* Core 1<2:0>, Core 0<4:0> */
        *ptr++ = 0x52; /* Core 3<0>, Core 2<4:0>, Core 1 <4:3> */
        *ptr++ = 0x4a; /* Core 4<3:0>, Core 3<4:1> */
        *ptr++ = 0x29; /* Core 6<1:0>, Core 5<4:0>, Core 4<4> */
        *ptr++ = 0xa5; /* Core 7<4:0>, Core 6<4:2> */
    }

    /* Instruction command built, send it */
    len = do_command(0, command, 6+ROUND_BYTES(total_bits), response, sizeof(response));
    if (len != 6+ROUND_BYTES(total_bits))
    {
        octeon_remote_debug(-1, "JTAG Instruction had unexpected response length %d\n", len);
        return -1;
    }

    /* Tell every core to read the JTAG data, which will contain a PC sample
        per core. Each sample has 1 bit GUESTID, 8 bits of ASID, 64 bits of
        PC, and one valid bit (total of 74 bits) */
    total_bits = (1 + 8 + 64 + 1) * __octeon_remote_num_cores;
    memset(command, 0, sizeof(command));
    command[0] = 0xf2;  /* JTAG_SCAN_IO */
    command[1] = 1;     /* Data */
    *(uint64_t*)(command+2) = bdk_cpu_to_be16(total_bits);
    *(uint64_t*)(command+4) = bdk_cpu_to_be16(ROUND_BYTES(total_bits));
    /* All data being clocked out is zero */

    /* Data command built, send it */
    len = do_command(0, command, 6+ROUND_BYTES(total_bits), response, sizeof(response));
    if (len != 6+ROUND_BYTES(total_bits))
    {
        octeon_remote_debug(-1, "JTAG Data had unexpected response length %d\n", len);
        return -1;
    }

    /* We should have all the samples. Extract them out of the bit stream */
    int bit_loc = 0;
    uint64_t *dwords = (uint64_t *)(response + 5);
    for (core=0; core<__octeon_remote_num_cores; core++)
    {
        int dword = bit_loc / 64;
        int bit = bit_loc & 63;
        int valid = !!(bdk_le64_to_cpu(dwords[dword]) & (1ull<<bit));
        bit_loc++;
        dword = bit_loc / 64;
        bit = bit_loc & 63;
        uint64_t pc = bdk_le64_to_cpu(dwords[dword]) >> bit;
        pc |= bdk_le64_to_cpu(dwords[dword+1]) << (64-bit);
        bit_loc += 64;
        dword = bit_loc / 64;
        bit = bit_loc & 63;
        uint8_t asid = bdk_le64_to_cpu(dwords[dword]) >> bit;
        asid |= bdk_le64_to_cpu(dwords[dword+1]) << (64-bit);
        bit_loc += 8;
        int guestid = (bdk_le64_to_cpu(dwords[dword]) >> bit) & 1;
        bit_loc++;
        octeon_remote_debug(2, "core %2d guestid=%d, asid=0x%02x, pc=0x%016llx valid=%d\n",
            core, guestid, 0xff & asid, (ULL)pc, valid);
        sample[core].pc = (valid) ? pc : 0;
    }

    if (sample[0].pc == 0)
    {
        /* PC sampling probably hasn't been enabled. Enable it for every core */
        octeon_remote_debug(2, "Setting sampling for %d cores\n", __octeon_remote_num_cores);
        /* Enable PC sampling for each core */
        for (core=0; core<__octeon_remote_num_cores; core++)
        {
            uint64_t debug;
            memory_access_core = core;
            macraigor_read_mem(&debug, 0xFFFFFFFFFF300000ull, 8);
            debug = bdk_be64_to_cpu(debug);
            if ((debug & 0x1e0) != 0x1e0)
            {
                debug |= 0x1e0;
                debug = bdk_cpu_to_be64(debug);
                macraigor_write_mem(0xFFFFFFFFFF300000ull, &debug, 8);
            }
        }
        memory_access_core = 0;
    }
    return 0;
}


/**
 * Initialize the pointers needed for octeon_remote to work over Macragior EJTAG
 * probes. This doesn't actually create a connection, just setup internal data
 * structures.
 *
 * @param remote_funcs
 *               Function pointers to be populated
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_macraigor(octeon_remote_funcs_t *remote_funcs)
{
    remote_funcs->open = macraigor_open;
    remote_funcs->close = macraigor_close;
    remote_funcs->read_mem = macraigor_read_mem;
    remote_funcs->write_mem = macraigor_write_mem;
    remote_funcs->get_model = macraigor_get_model;
    remote_funcs->start_cores = macraigor_start_cores;
    remote_funcs->stop_cores = macraigor_stop_cores;
    remote_funcs->get_running_cores = macraigor_get_running_cores;
    remote_funcs->get_core_state = macraigor_get_core_state;
    remote_funcs->set_core_state = macraigor_set_core_state;
    remote_funcs->read_register = macraigor_read_register;
    remote_funcs->write_register = macraigor_write_register;
    remote_funcs->reset = macraigor_reset;
    remote_funcs->get_sample = (USE_EJTAG_PC_SAMPLING) ? macraigor_get_sample_pc : macraigor_get_sample;
    return 0;
}


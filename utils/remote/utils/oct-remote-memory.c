/***********************license start************************************
 * Copyright (c) 2003-2008 Cavium Networks (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     * Neither the name of Cavium Networks nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM NETWORKS MAKES NO PROMISES, REPRESENTATIONS
 * OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
 * RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
 * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
 * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
 * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
 * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
 * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
 * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 *
 *
 * For any questions regarding licensing please contact marketing@caviumnetworks.com
 *
 **********************license end**************************************/

/**
 * @file
 *
 * Utility to read or write memory over a remote interface
 *
 * $Id: oct-remote-memory.c 56824 2011-02-01 18:01:19Z cchavva $
 *
 *
 */
#include <stdint.h>
#include <stdio.h>
#include "octeon-remote.h"
#include "oct-remote-common.h"

static int      access_width = 8;
static int      do_write     = 0;
static uint64_t address      = 0;
static uint64_t value        = 0;

static uint64_t convert_number(const char *str)
{
    unsigned long long result;
    if ((str[0] == '0') && (str[1] == 'x'))
    {
        if (sscanf(str+2, "%llx", &result) != 1)
            result = 0;
    }
    else
    {
        if (sscanf(str, "%lli", &result) != 1)
            result = 0;
    }
    return result;
}

void usage(char * const *argv)
{
    printf("\n"
           "Usage: %s [-w width] address [value]\n"
           "    Read or write bytes at a physical memory address.\n"
           "\n"
           "    width   Width of the access. Must be 8, 4, 2, or 1. Default is 8 bytes.\n"
           "    address Address of memory to read or write.\n"
           "    value   If present, write this value to the address. Otherwise do a read.\n"
           "\n"
           "\n", argv[0]);
}

int parse_options(int argc, char * const *argv)
{
    const struct option long_options[] =
    {
        {"width", 1, 0, 'w'},
        {"help", 0, 0, 'h'},
        {NULL, 0, 0, 0}
    };

    while (1)
    {
        char option = getopt_long(argc, argv, "w:h", long_options, NULL);
        if (option <= 0)
            break;

        switch (option)
        {
            case 'w':
                access_width = convert_number(optarg);
                if ((access_width != 8) && (access_width != 4) &&
                    (access_width != 2) && (access_width != 1))
                {
                    printf("Illegal width. Must be 8, 4, 2, or 1\n");
                    return -1;
                }
                break;
            case 1:
                printf("received a 1\n");
                break;
            default:
                usage(argv);
                return -1;
        }
    }

    if (optind < argc)
    {
        address = convert_number(argv[optind]);
        if (optind+1 < argc)
        {
            value = convert_number(argv[optind+1]);
            do_write = 1;
        }
        else
            do_write = 0;
    }
    else
    {
        usage(argv);
        return -1;
    }
    return 0;
}


/**
 * Main
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char * const *argv)
{
    if (parse_options(argc, argv))
        return -1;

    /* Open a connection */
    if (octeon_remote_open(OCTEON_REMOTE_DEFAULT, 0))
        return -1;

    /* Determine if we're doing a read or a write */
    if (do_write)
    {
        switch (access_width)
        {
            case 8:
                octeon_remote_write_mem64(address, value);
                break;
            case 4:
                octeon_remote_write_mem32(address, value);
                break;
            case 2:
                octeon_remote_write_mem16(address, value);
                break;
            default:
            {
                uint8_t v = value;
                octeon_remote_write_mem(address, &v, 1);
                break;
            }
        }
    }
    else
    {
        switch (access_width)
        {
            case 8:
            {
                uint64_t v = octeon_remote_read_mem64(address);
                printf("Address 0x%016llx = 0x%016llx\n",
                    (unsigned long long)address, (unsigned long long)v);
                break;
            }
            case 4:
            {
                uint32_t v = octeon_remote_read_mem32(address);
                printf("Address 0x%016llx = 0x%08x\n",
                    (unsigned long long)address, v);
                break;
            }
            case 2:
            {
                uint16_t v = octeon_remote_read_mem16(address);
                printf("Address 0x%016llx = 0x%04x\n",
                    (unsigned long long)address, 0xffff & v);
                break;
            }
            default:
            {
                uint8_t v;
                octeon_remote_read_mem(&v, address, 1);
                printf("Address 0x%016llx = 0x%02x\n",
                    (unsigned long long)address, 0xff & v);
                break;
            }
        }
    }
    octeon_remote_close();
    return 0;
}


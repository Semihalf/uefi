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
 * Load a file into memory on the Octeon
 *
 * $Id: oct-remote-load.c 56824 2011-02-01 18:01:19Z cchavva $
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "octeon-remote.h"
#include "oct-remote-common.h"

void usage(const char *argv[])
{
    printf("\n"
           "Usage: %s <address> <file>\n"
           "    Load the file into Octeon memory at supplied address.\n"
           "\n"
           "    address     Physical memory address to load the file at.\n"
           "                If the address supplied is 0, the file will\n"
           "                be loaded into the load reserved block.\n"
           "\n"
           "\n"
           "\n"
           "    file        Filename to load.\n"
           "\n"
           "Example:\n"
           "    The following is equivalent to loading a file at the\n"
           "    bootloader prompt with either fatload or kermit(loadb).\n"
           "\n"
           "    %s 0x100000 passthrough\n"
           "\n", argv[0], argv[0]);
}

int main(int argc, const char *argv[])
{
    unsigned long long address, cur_address;
    const char *filename = argv[2];
    FILE *infile;

    uint64_t filesize = 0;
    int retval = 0;
    char buffer[65536];

    if (print_help_message(usage, argv, argc) == -1)
        return -1;

    if (argc != 3)
    {
        usage(argv);
        return -1;
    }

    if (sscanf(argv[1], "%lli", &address) != 1)
    {
        printf("Failed to parse the address\n");
        return -1;
    }

    if (octeon_remote_open(OCTEON_REMOTE_DEFAULT, 0))
        return -1;

    infile = fopen(filename, "r");
    if (infile == NULL)
    {
        perror("Unable to open file");
        octeon_remote_close();
        return -1;
    }

    /* Explicitly lock access to the bus, otherwise this is done for every
    ** read/write, which slows the load way down.
    */
    octeon_remote_lock();
    cur_address = address;
    while (!feof(infile))
    {
        int count = fread(buffer, 1, sizeof(buffer), infile);
        if (count > 0)
        {
            octeon_remote_write_mem(cur_address, buffer, count);
            cur_address += count;
            filesize += count;
        }
    }
    octeon_remote_unlock();
    fclose(infile);
    octeon_remote_close();
    return retval;
}


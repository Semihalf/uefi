/***********************license start************************************
 * Copyright (c) 2003-2009 Cavium Networks (support@cavium.com). All rights
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
 * Interface to Octeon natively under Linux
 *
 * $Id: octeon-remote-linux.c 51874 2010-08-13 22:12:40Z apinski $
 */
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "octeon-remote.h"
#include "octeon-remote-map.h"
#include "octeon-remote-debug-handler.h"

/**
 * Called when octeon_remote_open() is called using a remote spec
 * for LINUX.
 *
 * @param remote_spec
 *               String specification of the remote to connect to.
 *
 * @return Zero on success, negative on failure.
 */
static int linux_open(const char *remote_spec __attribute__ ((unused)))
{
    /* There is nothing as we are on the same board. */
    return 0;
}


/**
 * Called when octeon_remote_close() is called.
 */
static void linux_close(void)
{
    octeon_remote_debug_handler_remove();
}


/**
 * Read data from a physical memory address.
 *
 * @param buffer_ptr Buffer to put the data in
 * @param physical_address
 *                   Physical address to read from. Bits 63-38 should be zero.
 * @param length     Length to read in bytes
 */
static void linux_read_mem(void *buffer, uint64_t physical_address, int length)
{
    octeon_remote_map_cookie_t cookie;
    uint8_t *ptr = octeon_remote_map(physical_address, length, &cookie);
    /* Special case some common sizes as IO blocks may only allow certain
        size accesses. Unfortunately memcpy() seem to do silly things, like
        byte copies, for the most common operations */
    if (length == 1)
        *(uint8_t *)buffer = *(uint8_t *)ptr;
    else if (length == 2)
        *(uint16_t *)buffer = *(uint16_t *)ptr;
    else if (length == 4)
        *(uint32_t *)buffer = *(uint32_t *)ptr;
    else if (length == 8)
        *(uint64_t *)buffer = *(uint64_t *)ptr;
    else
        memcpy(buffer,  ptr,  length);
    octeon_remote_unmap(&cookie);
}


/**
 * Write data to a physical memory address
 *
 * @param physical_address
 *                   Physical address to write to. Bits 63-38 should be zero.
 * @param buffer_ptr Buffer containing the data to write
 * @param length     Number of bytes to write
 */
static void linux_write_mem(uint64_t physical_address, const void *buffer, int length)
{
    octeon_remote_map_cookie_t cookie;
    uint8_t *ptr = octeon_remote_map(physical_address, length, &cookie);
    /* Special case some common sizes as IO blocks may only allow certain
        size accesses. Unfortunately memcpy() seem to do silly things, like
        byte copies, for the most common operations */
    if (length == 1)
        *(uint8_t *)ptr = *(uint8_t *)buffer;
    else if (length == 2)
        *(uint16_t *)ptr = *(uint16_t *)buffer;
    else if (length == 4)
        *(uint32_t *)ptr = *(uint32_t *)buffer;
    else if (length == 8)
        *(uint64_t *)ptr = *(uint64_t *)buffer;
    else
        memcpy(ptr,  buffer,  length);
    octeon_remote_unmap(&cookie);
}


/**
 * Return the Processor ID of the Octeon. This should be identical
 * to the value found in the COP0 PRID register
 *
 * @return Processor ID
 */
uint32_t octeon_remote_linux_get_model(void)
{
    uint32_t result = 0;

    FILE *infile = fopen("/proc/octeon_info", "r");
    if (!infile)
    {
        octeon_remote_debug(-1, "Error opening /proc/octeon_info");
        return 0;
    }

    while (!feof(infile))
    {
        char buffer[80];
        if (fgets(buffer, sizeof(buffer), infile))
        {
            octeon_remote_debug(2, "/proc/octeon_info: %s", buffer);
            const char *field = strtok(buffer, " ");
            const char *valueS = strtok(NULL, " ");
            if (!field || !valueS)
                continue;
            if (strcmp(field, "processor_id:") == 0)
            {
                sscanf(valueS, "%i", &result);
                break;
            }
        }
    }
    fclose(infile);
    return result;
}


/**
 * Take the cores in the bit vector out of the debug exception.
 *
 * @param start_mask Cores to start
 */
static void linux_start_cores(uint64_t start_mask __attribute__ ((unused)))
{
    /* We only support the profiling debug handler, so cores automatically
        restart */
}


/**
 * Cause the cores in the stop mask to take a debug exception
 *
 * @param stop_mask Cores to stop
 */
static void linux_stop_cores(uint64_t stop_mask)
{
    if (octeon_remote_debug_handler_install(OCTEON_REMOTE_SAVE_HANDLER))
        return;
    OCTEON_REMOTE_WRITE_CSR(BDK_CIU_DINT, stop_mask);
}


/**
 * Get a mask where each bit represents a running core. If a core
 * is in the debug exception handler, it's bit will be zero.
 *
 * @return Bit set for every running core
 */
static uint64_t linux_get_running_cores(void)
{
    return ~OCTEON_REMOTE_READ_CSR(BDK_CIU_PP_DBG);
}


/**
 * Get all registers, COP0, TLB, etc for a core
 *
 * @param core      Core to get state info for
 * @param registers All of the core's internal state
 *
 * @return Zero on success, negative on failure
 */
static int linux_get_core_state(int core __attribute__ ((unused)), octeon_remote_registers_t *registers __attribute__ ((unused)))
{
    uint64_t base = octeon_remote_debug_handler_get_base(core);
    if (!base)
        return -1;
    octeon_remote_read_mem(registers, base, sizeof(*registers));
    registers->regs[0][0] = 0;
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
static int linux_set_core_state(int core __attribute__ ((unused)), const octeon_remote_registers_t *registers __attribute__ ((unused)))
{
    /* The profile debug handler doesn't support setting any registers */
    return -1;
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
static int linux_get_sample(uint64_t coremask, octeon_remote_sample_t sample[64])
{
    int num_cores = octeon_remote_get_num_cores();
    for (int core=0; core<num_cores; core++)
    {
        if ((1ull<<core) & coremask)
        {
            sample[core].pc = OCTEON_REMOTE_READ_CSR(BDK_L2C_COP0_MAPX((core<<8)|(16<<3)|0));
            if (sample[core].pc & 2)
                sample[core].pc = 0; /* The sample is invalid */
            else if (sample[core].pc >> 62 == 3)
                sample[core].pc |= 0x3ffe000000000000ull; /* The hardware doesn't store these bits */
            sample[core].perf_count[0] = OCTEON_REMOTE_READ_CSR(BDK_L2C_COP0_MAPX((core<<8)|(25<<3)|1));
            sample[core].perf_count[1] = OCTEON_REMOTE_READ_CSR(BDK_L2C_COP0_MAPX((core<<8)|(25<<3)|3));
        }
    }
    return 0;
}


/**
 * Initialize the pointers needed for octeon_remote to work over
 * LINUX. This doesn't actually create a connection, just setup
 * internal data structures.
 *
 * @param remote_funcs
 *               Function pointers to be populated
 *
 * @return Zero on success, negative on failure
 */
int octeon_remote_linux(octeon_remote_funcs_t *remote_funcs)
{
    remote_funcs->open = linux_open;
    remote_funcs->close = linux_close;
    remote_funcs->read_mem = linux_read_mem;
    remote_funcs->write_mem = linux_write_mem;
    remote_funcs->get_model = octeon_remote_linux_get_model;
    remote_funcs->start_cores = linux_start_cores;
    remote_funcs->stop_cores = linux_stop_cores;
    remote_funcs->get_running_cores = linux_get_running_cores;
    remote_funcs->get_core_state = linux_get_core_state;
    remote_funcs->set_core_state = linux_set_core_state;
    remote_funcs->get_sample = linux_get_sample;
#ifdef __mips__
    return 0;
#else
    octeon_remote_debug(-1, "LINUX remote protocol is only supported when running natively on Octeon\n");
    remote_funcs->open = NULL;
    return -1;
#endif
}


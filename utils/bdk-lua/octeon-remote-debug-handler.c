/***********************license start************************************
 * Copyright (c) 2009 Cavium Networks (support@cavium.com). All rights
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
 * This provides a simplied interface to install EJTAG debug exception
 * handlers into Octeon's memory.
 *
 * $Id: octeon-remote-map.h 41588 2009-03-19 19:41:00Z vmalov $
 */
#include <bdk.h>
#include <stdio.h>
#include <stdlib.h>
#include "octeon-remote.h"
#include "octeon-remote-debug-handler.h"

#define ULL unsigned long long

const int DEBUG_CORE_STATE_SIZE = 16384;
static int installed_handler = -1;
static uint64_t debug_handler_base = 0;

int octeon_remote_debug_handler_install(octeon_remote_debug_handler_t handler)
{
    extern void *octeon_remote_debug_handler3_begin;
    extern void *octeon_remote_debug_handler3_end;
    void *handler_begin = &octeon_remote_debug_handler3_begin;
    void *handler_end = &octeon_remote_debug_handler3_end;

    OCTEON_REMOTE_DEBUG_CALLED("handler=%d", handler);
    if (installed_handler == (int)handler)
    {
        OCTEON_REMOTE_DEBUG_RETURNED("%d - Already installed", 0);
        return 0;
    }

    if (!debug_handler_base)
    {
        const char *address = getenv("OCTEON_REMOTE_SCRATCH_ADDRESS");
        if (address)
        {
            sscanf(address, "%lli", (ULL*)&debug_handler_base);
            octeon_remote_debug(2, "Using scratch memory address from OCTEON_REMOTE_SCRATCH_ADDRESS of 0x%llx\n", (ULL)debug_handler_base);
        }
        else
        {
            /* The debug stub requires SIZE*(1 + num_cores) */
            if (CAVIUM_IS_MODEL(OCTEON_CN70XX)) // FIXME: Cache not big enough, now what?
                debug_handler_base = 0x80000 - DEBUG_CORE_STATE_SIZE * (4 + 1);
            else if (CAVIUM_IS_MODEL(OCTEON_CN78XX))
                debug_handler_base = 0x1000000 - DEBUG_CORE_STATE_SIZE * (48 + 1);
            else
            {
                octeon_remote_debug(-1, "Unknown OCTEON model in octeon_remote_debug_handler_install.\n");
                return -1;
            }
        }
        int size = (long)handler_end - (long)handler_begin;
        octeon_remote_debug(2, "Copying debug handler to 0x%llx, len=%d\n", (ULL)debug_handler_base, size);
        octeon_remote_write_mem(debug_handler_base, handler_begin, size);

        /* Fixup the address calculations in the debug handler */
        uint64_t core_base = debug_handler_base + DEBUG_CORE_STATE_SIZE;
        octeon_remote_write_mem32(debug_handler_base + 16, 0x675a0000 | ((core_base>>0)&0x7fff));
        octeon_remote_write_mem32(debug_handler_base + 24, 0x675a0000 | ((core_base>>15)&0x7fff));
        octeon_remote_write_mem32(debug_handler_base + 32, 0x675a0000 | ((core_base>>30)&0x7fff));
        octeon_remote_write_mem32(debug_handler_base + 40, 0x675a0000 | ((core_base>>45)&0x7fff));
        octeon_remote_write_mem32(debug_handler_base + 48, 0x675a0000 | ((core_base>>60)&0xf) | 8);

        octeon_remote_debug(2, "Installing bootbus region 1\n");
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_CFGX(1), (1ull << 31) | (0x1fc00480 >> 4));
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_ADR, 0x80);  /* Auto increments after write */
        /* Most sig. word executes first */
        /*      dmtc0   ra, $COP0_DESAVE    40bff800 */
        /*      bal     1f                  04110001 */
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_DAT, 0x40bff80004110001ull);
        /*       nop                        00000000 */
        /* 1:   ld      ra, 12(ra)          dfff000c */
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_DAT, 0x00000000dfff000cull);
        /*      jr      ra                  03e00008 */
        /*      dmfc0  ra, $COP0_DESAVE     403ff800 */
        OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_DAT, 0x03e00008403ff800ull);
    }

    uint64_t address = debug_handler_base;
    octeon_remote_debug(2, "Writing secondary handler address 0x%llx\n", (1ull<<63) | address);
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_ADR, 0x98);
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_DAT, (1ull<<63) | address);
    OCTEON_REMOTE_READ_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_DAT);  /* Ensure write has completed */

    /* For the handlers we must set the core stop
        mode. A value of "2" in the R0 storage location tells the low level
        stub to continue after saving the registers. A value of "0" tells
        it to stop, writing a "1" to this loc, and wait for someone to write
        a zero */
    {
        int stop_type = (handler == OCTEON_REMOTE_SAVE_HANDLER) ? 2 : 0;
        int num_cores = octeon_remote_get_num_cores();
        for (int core=0; core<num_cores; core++)
            octeon_remote_write_mem64(debug_handler_base + (core+1) * DEBUG_CORE_STATE_SIZE, stop_type);
    }

    installed_handler = handler;
    OCTEON_REMOTE_DEBUG_RETURNED("%d", 0);
    return 0;
}

int octeon_remote_debug_handler_remove(void)
{
    OCTEON_REMOTE_DEBUG_CALLED("");
    if (installed_handler == -1)
    {
        OCTEON_REMOTE_DEBUG_RETURNED("%d - Nothing to do", 0);
        return 0;
    }
    OCTEON_REMOTE_WRITE_CSR(OCTEON_REMOTE_NODE, BDK_MIO_BOOT_LOC_CFGX(1), 0);
    installed_handler = -1;
    OCTEON_REMOTE_DEBUG_RETURNED("%d", 0);
    return 0;
}

uint64_t octeon_remote_debug_handler_get_base(int core)
{
    uint64_t result;
    OCTEON_REMOTE_DEBUG_CALLED("core=%d", core);
    if ((installed_handler==-1) || !debug_handler_base)
    {
        octeon_remote_debug(-1, "Debug handler not installed\n");
        OCTEON_REMOTE_DEBUG_RETURNED("%d", -1);
        return 0;
    }

    result = debug_handler_base + (core+1) * DEBUG_CORE_STATE_SIZE;
    OCTEON_REMOTE_DEBUG_RETURNED("0x%llx", (ULL)result);
    return result;
}

int octeon_remote_debug_handler_is_installed(void)
{
    int result;
    OCTEON_REMOTE_DEBUG_CALLED("");
    result = (installed_handler != -1);
    OCTEON_REMOTE_DEBUG_RETURNED("%d", result);
    return result;
}


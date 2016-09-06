/***********************license start***********************************
* Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
* reserved.
*
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are
* met:
*
*   * Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*
*   * Redistributions in binary form must reproduce the above
*     copyright notice, this list of conditions and the following
*     disclaimer in the documentation and/or other materials provided
*     with the distribution.
*
*   * Neither the name of Cavium Inc. nor the names of
*     its contributors may be used to endorse or promote products
*     derived from this software without specific prior written
*     permission.
*
* This Software, including technical data, may be subject to U.S. export
* control laws, including the U.S. Export Administration Act and its
* associated regulations, and may be subject to export or import
* regulations in other countries.
*
* TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
* AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
* WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
* TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
* REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
* DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
* OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
* PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
* QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
* ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
***********************license end**************************************/
#include <bdk.h>
#include <stdio.h>

/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
void bdk_wait_usec(uint64_t usec)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_TIME) + usec * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) / 1000000;
    do
    {
        bdk_thread_yield();
    } while (bdk_clock_get_count(BDK_CLOCK_TIME) < done);
}

/**
 * Wait for the specified number of core clock cycles
 *
 * @param cycles
 */
void bdk_wait(uint64_t cycles)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_TIME) + cycles;

    while (bdk_clock_get_count(BDK_CLOCK_TIME) < done)
    {
        /* Spin */
    }
}

/**
 * Perform a soft reset of the chip
 *
 * @return
 */
void bdk_reset_chip(bdk_node_t node)
{
    fflush(NULL);

    /* Wait for TX fifo to empty */
    while (1)
    {
        BDK_CSR_INIT(fr, node, BDK_UAAX_FR(0));
        if (fr.s.txfe)
            break;
        bdk_thread_yield();
    }

    /* RST_OCX is not cleared by a chip reset. Clear it now to avoid repeated
       resets due to CCPI state changes during reset */
    BDK_CSR_WRITE(node, BDK_RST_OCX, 0);
    BDK_CSR_READ(node, BDK_RST_OCX);

    bdk_rst_soft_rst_t rst_soft_rst;
    rst_soft_rst.u = 0;
    rst_soft_rst.s.soft_rst = 1;
    BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, rst_soft_rst.u);
}


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

int __bdk_numa_master_node = -1;    /* Which node is the master */
static int __bdk_numa_exists_mask = 0;     /* Bitmask of nodes that exist */
static bdk_spinlock_t __bdk_numa_lock;

/**
 * Get a bitmask of the nodes that exist
 *
 * @return bitmask
 */
uint64_t bdk_numa_get_exists_mask(void)
{
    return __bdk_numa_exists_mask;
}

/**
 * Add a node to the exists mask
 *
 * @param node   Node to add
 */
void bdk_numa_set_exists(bdk_node_t node)
{
    bdk_spinlock_lock(&__bdk_numa_lock);
    __bdk_numa_exists_mask |= 1 << node;
    if (__bdk_numa_master_node == -1)
        __bdk_numa_master_node = node;
    bdk_spinlock_unlock(&__bdk_numa_lock);
}

/**
 * Return true if a node exists
 *
 * @param node   Node to check
 *
 * @return Non zero if the node exists
 */
int bdk_numa_exists(bdk_node_t node)
{
    return __bdk_numa_exists_mask & (1 << node);
}

/**
 * Return true if there is only one node
 *
 * @return
 */
extern int bdk_numa_is_only_one()
{
    return __bdk_numa_exists_mask == 1;
}


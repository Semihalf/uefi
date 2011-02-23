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
#ifndef OCT_REMOTE_COMMON_H
#define OCT_REMOTE_COMMON_H

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/**
 * @file oct-remote-common.h
 *
 * Interface to common functions used by all oct-remote-* utilities.
 *
 * $Id: oct-remote-common.h 40381 2009-02-18 12:10:51Z cchavva $
 *
*/

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Print command usage when invoked with -h/--help.
 *
 * @param func      Name of the function pointer, to print the usage
 * @param func_args Arguments to the function pointer
 * @param argc      Number of arguments the command is invoked with
 *
 * @return -1 if invoked with -h/--help option else return 0.
 */
typedef void (usage_ftype) (const char **);
extern int print_help_message(usage_ftype *func, const char **func_args, int argc);

#ifdef  __cplusplus
}
#endif

#endif

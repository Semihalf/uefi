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
 * Reset an Octeon over a remote interface
 *
 * $Id: oct-remote-reset.c 52717 2010-09-07 03:06:30Z cchavva $
 */
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <getopt.h>
#include "octeon-remote.h"

void usage(void)
{
    printf("Usage: oct-remote-reset [options]\n");
    printf("Options:\n");
    printf(" --h or -h:  print this usage message\n");

}


int main(int argc, const char *argv[])
{
    int ret = 0;
    int c;


    /* Parse command line options using getopt_long */
    while (1)
    {
        static struct option long_options[] =
        {
            {"wait",   required_argument, 0, 0},
            {"help",   no_argument, 0, 0},
            {0, 0, 0, 0}
        };
        /* getopt_long stores the option index here. */
        int option_index = 0;

        c = getopt_long (argc, (char * const *)argv, "h",
                         long_options, &option_index);


        /* Detect the end of the options. */
        if (c == -1)
            break;

        switch (c)
        {
            /* All long options handled in case 0 */
            case 0:
                if (!strcmp(long_options[option_index].name, "help"))
                {
                    usage();
                    return -1;
                }
                break;

            case 'h':
            case '?':
                usage();
                return -1;
                break;

            default:
                abort ();
        }
    }



    if (octeon_remote_open(OCTEON_REMOTE_DEFAULT, 0))
        return -1;

    octeon_remote_lock();
    octeon_remote_reset(0);

    if ((octeon_remote_get_running_cores() & 1) == 0)
    {
        /* Sometimes a soft reset is used after a hard reset.  This could
           leave the cpu stopped.  Stopping then starting it will insure
           that it continues. */
        octeon_remote_stop_cores(1);
        octeon_remote_start_cores(1);
    }
    octeon_remote_unlock();
    octeon_remote_close();
    return ret;
}

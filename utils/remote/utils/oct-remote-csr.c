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
 * Utility to display CSR of a remote Octeon
 *
 * $Id: oct-remote-csr.c 56824 2011-02-01 18:01:19Z cchavva $
 *
 *
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "octeon-remote.h"
#include "oct-remote-common.h"

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

void usage(const char *argv[])
{
    printf("\n"
           "Usage: %s CSR [value] [CSR [value] ...]\n"
           "    Read or write a CSR by name.\n"
           "\n"
           "    CSR     Name of CSR to read or write. Case is ignored.\n"
           "    value   If present, write this value to the CSR. Otherwise do a read.\n"
           "            The value can be in decimal of hex (0x...).\n"
           "\n"
           "    If CSR is a partial name, the list of CSRs starting with it are displayed.\n"
           "\n", argv[0]);
}

/**
 * Main
 *
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, const char *argv[])
{
    int index;
    const char *csr_name;

    if (print_help_message(usage, argv, argc) == -1)
        return -1;

    /* Make sure we got the correct number of arguments */
    if (argc < 2)
    {
        usage(argv);
        return -1;
    }

    /* Open a connection */
    if (octeon_remote_open(OCTEON_REMOTE_DEFAULT, 0))
        return -1;

    uint32_t model = octeon_remote_get_model();

    index = 1;
    while (index < argc)
    {
        csr_name = argv[index];

        /* Find the CSR address from the name. If this fails it will return 0 */
        const CVMX_CSR_DB_ADDRESS_TYPE *csr = cvmx_csr_db_get(model, csr_name);

        if (csr)
        {
            /* We don't support CSRs that aren't in IO space (bit 48 set) */
            if (((csr->address & (1ull<<48)) == 0) &&
                (csr->type != CVMX_CSR_DB_TYPE_PCICONFIGEP) &&
                (csr->type != CVMX_CSR_DB_TYPE_PCICONFIGRC) &&
                (csr->type != CVMX_CSR_DB_TYPE_SRIOMAINT))
            {
                printf("CSR %s: This utility can't access CSRs of this type\n", csr->name);
                octeon_remote_close();
                return -1;
            }

            /* Determine if we're doing a read or a write */
            if ((index + 1 < argc) && (argv[index+1][0] >= '0') && (argv[index+1][0] <= '9'))
            {
                uint64_t value = convert_number(argv[index+1]);
                if ((csr->type == CVMX_CSR_DB_TYPE_PCICONFIGEP) || (csr->type == CVMX_CSR_DB_TYPE_PCICONFIGRC))
                {
                    /* Names are of the format "PCIE??#_CFG???". The # is the pcie port number */
                    int pcie_port = (csr->name[6] - '0');
                    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
                    {
                        cvmx_pescx_cfg_wr_t pescx_cfg_wr;
                        pescx_cfg_wr.u64 = 0;
                        pescx_cfg_wr.s.addr = csr->address;
                        pescx_cfg_wr.s.data = value;
                        octeon_remote_write_csr(CVMX_PESCX_CFG_WR(pcie_port), pescx_cfg_wr.u64);
                    }
                    else
                    {
                        cvmx_pemx_cfg_wr_t pemx_cfg_wr;
                        pemx_cfg_wr.u64 = 0;
                        pemx_cfg_wr.s.addr = csr->address;
                        pemx_cfg_wr.s.data = value;
                        octeon_remote_write_csr(CVMX_PEMX_CFG_WR(pcie_port), pemx_cfg_wr.u64);
                    }
                }
                else if (csr->type == CVMX_CSR_DB_TYPE_SRIOMAINT)
                {
                    /* Names are of the format "SRIOMAINT#_*". The # is the srio port number */
                    int srio_port = (csr->name[9] - '0');
                    if (cvmx_srio_config_write32(srio_port, 0, -1, 0, 0, csr->address, value))
                        fprintf(stderr, "SRIO access failed\n");
                }
                else if (csr->widthbits == 32)
                    octeon_remote_write_csr32(csr->address, value);
                else
                    octeon_remote_write_csr(csr->address, value);
                index += 2;
            }
            else
            {
                uint64_t value;
                if ((csr->type == CVMX_CSR_DB_TYPE_PCICONFIGEP) || (csr->type == CVMX_CSR_DB_TYPE_PCICONFIGRC))
                {
                    /* Names are of the format "PCIE??#_CFG???". The # is the pcie port number */
                    int pcie_port = (csr->name[6] - '0');
                    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
                    {
                        cvmx_pescx_cfg_rd_t pescx_cfg_rd;
                        pescx_cfg_rd.u64 = 0;
                        pescx_cfg_rd.s.addr = csr->address;
                        octeon_remote_write_csr(CVMX_PESCX_CFG_RD(pcie_port), pescx_cfg_rd.u64);
                        pescx_cfg_rd.u64 = octeon_remote_read_csr(CVMX_PESCX_CFG_RD(pcie_port));
                        value = 0xffffffffull & pescx_cfg_rd.s.data;
                    }
                    else
                    {
                        cvmx_pemx_cfg_rd_t pemx_cfg_rd;
                        pemx_cfg_rd.u64 = 0;
                        pemx_cfg_rd.s.addr = csr->address;
                        octeon_remote_write_csr(CVMX_PEMX_CFG_RD(pcie_port), pemx_cfg_rd.u64);
                        pemx_cfg_rd.u64 = octeon_remote_read_csr(CVMX_PEMX_CFG_RD(pcie_port));
                        value = 0xffffffffull & pemx_cfg_rd.s.data;
                    }
                }
                else if (csr->type == CVMX_CSR_DB_TYPE_SRIOMAINT)
                {
                    /* Names are of the format "SRIOMAINT#_*". The # is the srio port number */
                    int srio_port = (csr->name[9] - '0');
                    uint32_t result;
                    if (cvmx_srio_config_read32(srio_port, 0, -1, 0, 0, csr->address, &result))
                    {
                        fprintf(stderr, "SRIO access failed\n");
                        result = 0;
                    }
                    value = result;
                }
                else if (csr->widthbits == 32)
                    value = octeon_remote_read_csr32(csr->address);
                else
                    value = octeon_remote_read_csr(csr->address);
                cvmx_csr_db_decode_by_name(model, csr->name, value);
                index++;
            }
        }
        else
        {
            fprintf(stderr, "CSR not found in list. Looking for prefix \"%s\"\n", csr_name);
            cvmx_csr_db_display_list(model, csr_name);
            index++;
        }
    }

    octeon_remote_close();
    return 0;
}


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

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(ECAM);

/**
 * Walk an ECAM finding all internal devices. Each internal
 * device is then added to the list of device maintained by
 * bdk-device.
 *
 * @param node   Node to walk
 * @param ecam   Ecam to walk
 * @param bus    Zero on first call. Will be non-zero when sub busses are walked
 */
static void ecam_walk_internal_bus(bdk_node_t node, int ecam, int bus)
{
    /* Create a fake bdk-device to pass around until we create the
       real device */
    bdk_device_t device;
    memset(&device, 0, sizeof(device));
    device.node = node;
    device.ecam = ecam;
    device.bus = bus;

    /* Scan all possible device IDs on the bus */
    for (int dev = 0; dev < 32; dev++)
    {
        /* Update the current scan location */
        device.dev = dev;
        device.func = 0;

        uint32_t device_id = bdk_ecam_read32(&device, BDK_PCCPF_XXX_ID);

        /* Only add devices that exist. Our internal devices can have function
           zero missing. The all ones we get back matches the multi-function
           check, but not a bridge. This means the later code works fine */
        if (device_id != (uint32_t)-1)
            bdk_device_add(device.node, device.ecam, device.bus, device.dev, device.func);

        /* Check for Multi function and Bridge devices */
        BDK_CSR_DEFINE(clsize, BDK_PCCPF_XXX_CLSIZE);
        clsize.u = bdk_ecam_read32(&device, BDK_PCCPF_XXX_CLSIZE);
        int ismultifunction = (clsize.s.hdrtype & 0x80);
        int isbridge = (clsize.s.hdrtype & 0x7f) == 1;

        if (ismultifunction)
        {
            /* Scan for other functions on multifunction devices */
            for (int func = 1; func < 8; func++)
            {
                /* Check if we're past all functions */
                device.func = func;
                uint32_t device_id = bdk_ecam_read32(&device, BDK_PCCPF_XXX_ID);
                if (device_id != (uint32_t)-1)
                    bdk_device_add(device.node, device.ecam, device.bus, device.dev, device.func);
            }
            device.func = 0;
        }
        if (isbridge)
        {
            /* Internal bus numbers are hard coded. Read the bus ID */
            bdk_pccbr_xxx_bus_t bus;
            bus.u = bdk_ecam_read32(&device, BDK_PCCBR_XXX_BUS);
            /* Asim used to have a bug where bus number were zero, report errors
               for those */
            if (bus.s.sbnum == 0)
            {
                bdk_error("N%d:E%d:%d:%d.%d: Secondary bus number is zero\n",
                    device.node, device.ecam, device.bus, device.dev, device.func);
            }
            /* Real PCIe external device use high bus numbers, so skip them */
            else if (bus.s.sbnum < 16)
            {
                ecam_walk_internal_bus(node, ecam, bus.s.sbnum);
            }
        }
    }
}

/**
 * Turn a ECAM bus into a ARI chain by finding all devices and linking them
 *
 * @param node   Node to create the chain on
 * @param ecam   ECAM to create the chain on
 * @param bus    Bus number to use
 */
static void ecam_create_ari_chain(bdk_node_t node, int ecam, int bus)
{
    /* Create a fake bdk-device to pass around until we create the
       real device */
    bdk_device_t device;
    memset(&device, 0, sizeof(device));
    device.node = node;
    device.ecam = ecam;
    device.bus = bus;
    device.dev = 0;
    device.func = 0;

    /* This is time consuming. If the ARI chain is already non-zero,
       assume a previous boot stage already executed this function */
    BDK_CSR_DEFINE(ctl, BDK_PCCPF_XXX_VSEC_CTL);
    ctl.u = bdk_ecam_read32(&device, BDK_PCCPF_XXX_VSEC_CTL);
    if (ctl.s.nxtfn_ns)
        return;

    /* Search for functions and link them into a chain */
    int last_ari = -1; /* ARI is the old PCIe dev and function combined */
    BDK_TRACE(ECAM, "Creating RSL ARI chain for ecam %d, bus %d\n", device.ecam, device.bus);
    for (int ari = 0; ari < 256; ari++)
    {
        device.dev = ari >> 3;
        device.func = ari & 7;

        /* Only visit existing device */
        uint32_t device_id = bdk_ecam_read32(&device, BDK_PCCPF_XXX_ID);
        if (device_id == (uint32_t)-1)
            continue;

        if (last_ari != -1)
        {
            device.dev = last_ari >> 3;
            device.func = last_ari & 7;

            BDK_TRACE(ECAM, "    Found ARI %d, connect to %d\n", ari, last_ari);
            ctl.u = bdk_ecam_read32(&device, BDK_PCCPF_XXX_VSEC_CTL);
            ctl.s.nxtfn_ns = ari;
            bdk_ecam_write32(&device, BDK_PCCPF_XXX_VSEC_CTL, ctl.u);

            BDK_CSR_DEFINE(sctl, BDK_PCCPF_XXX_VSEC_SCTL);
            sctl.u = bdk_ecam_read32(&device, BDK_PCCPF_XXX_VSEC_SCTL);
            sctl.s.nxtfn_s = ari;
            bdk_ecam_write32(&device, BDK_PCCPF_XXX_VSEC_SCTL, sctl.u);
        }
        else
            BDK_TRACE(ECAM, "    Found first ARI %d\n", ari);
        last_ari = ari;
    }
}

/**
 * Return the number of internal ECAMS on a node.
 *
 * @param node   Node to query
 *
 * @return Number of ECAMs available
 */
int bdk_ecam_get_num(bdk_node_t node)
{
    /* CN88XX lacks the ECAM_CONST for finding the number of ECAMs */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 4;
    else
    {
        BDK_CSR_INIT(ecam_const, node, BDK_ECAMX_CONST(0));
        if (ecam_const.s.ecams == 0)
        {
            bdk_error("N%d.ECAM: Number of ecams incorrect in ECAMX_CONST\n", node);
            return 1;
        }
        return ecam_const.s.ecams;
    }
}

/**
 * Scan all ECAMs for devices and add them to bdk-device
 *
 * @param node   Node to scan
 *
 * @return Zero on success, negative on failure
 */
int bdk_ecam_scan_all(bdk_node_t node)
{
    /* Scan for all internal devices on all ECAMs */
    int num_ecams = bdk_ecam_get_num(node);
    for (int ecam = 0; ecam < num_ecams; ecam++)
        ecam_walk_internal_bus(node, ecam, 0);

    /* Create MRML ARI chain */
    ecam_create_ari_chain(node, 0, 1);

    bdk_device_init();

    return 0;
}


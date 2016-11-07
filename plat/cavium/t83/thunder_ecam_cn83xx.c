/** @file
#
#  Copyright (c) 2016, Cavium Inc. All rights reserved.<BR>
#  This program and the accompanying materials
#  are licensed and made available under the terms and conditions of the BSD License
#  which accompanies this distribution.  The full text of the license may be found at
#  http://opensource.org/licenses/bsd-license.php
#
#  THE PROGRAM IS DISTRIBUTED UNDER THE BSD LICENSE ON AN "AS IS" BASIS,
#  WITHOUT WARRANTIES OR REPRESENTATIONS OF ANY KIND, EITHER EXPRESS OR IMPLIED.
#
#**/

#include <platform_def.h>
#include <thunder_private.h>
#include <thunder_common.h>

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "thunder_io.h"
#include "thunder_dt.h"
#include "thunder_ecam.h"

uint32_t thunder_fuse_read (int node, int i)
{
	return 0;
}

/* Probe for disabling TWSI busses from PCI scan */
static int ecam_probe_twsi(int node, unsigned long arg)
{
	return (bfdt.bmc_boot_twsi_bus != arg);
}

/* Probe RST_CTLX for PEM usability. */
static int ecam_probe_pem(int node, unsigned long arg)
{
	union cavm_rst_soft_prstx soft_prst;

	soft_prst.u = CSR_READ_PA(node, CAVM_RST_SOFT_PRSTX(arg));

	return soft_prst.s.soft_prst == 0;
}

/* Probe GSERX_CFG[SATA] for SATA usability. arg is the GSER number. */
static int ecam_probe_sata(int node, unsigned long arg)
{
	union cavm_gserx_cfg cfg;

	cfg.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg / 2 + 4));

	return cfg.s.sata != 0;
}

/* Probe GSERX_CFG[BGX] for BGX usability. arg is the GSER number. */
static int ecam_probe_bgx(int node, unsigned long arg)
{
	union cavm_gserx_cfg cfg_dlm0;
	union cavm_gserx_cfg cfg_dlm1;

	/* On 81xx BGX is split across 2 DLMs, check both DLMs
	 * for marking BGX PCi device secure 
	 */
	cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg));
	cfg_dlm1.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg + 1));

	return (cfg_dlm0.s.bgx || cfg_dlm1.s.bgx);
}

/* arg is LMC number */
static int ecam_probe_lmc(int node, unsigned long arg)
{
	return thunder_dram_is_lmc_enabled(node, arg);
}

struct ecam_device devs0_cn83xx[] = {
	{0, 1 , 0,  72, TRUE, ecam_probe_twsi, 0}, /* TWSI 0 */
	{0, 1 , 0,  73, TRUE, ecam_probe_twsi, 1}, /* TWSI 1 */
	{0, 1 , 0,  80, TRUE, ecam_probe_lmc, 0}, /* LMC 0 */
	{0, 1 , 0,  81, TRUE, ecam_probe_lmc, 1}, /* LMC 1 */
	{0, 1 , 0, 112, FALSE, ecam_probe_pem, 0}, /* PEM 0 */
	{0, 1 , 0, 113, FALSE, ecam_probe_pem, 1}, /* PEM 1 */
	{0, 1 , 0, 114, FALSE, ecam_probe_pem, 2}, /* PEM 2 */
	{0, 1 , 0, 115, FALSE, ecam_probe_pem, 3}, /* PEM 3 */
	{0, 1,  0, 128, TRUE, ecam_probe_bgx, 0}, /* BGX 0 */
	{0, 1,  0, 129, TRUE, ecam_probe_bgx, 1}, /* BGX 1 */
	{0, 1,  0, 130, TRUE, ecam_probe_bgx, 2}, /* BGX 2 */
	{0, 1,  0, 131, TRUE, ecam_probe_bgx, 3}, /* BGX 3 */
	{1, 0,  4, 0, TRUE, ecam_probe_sata, 0}, /* SATA 0 */
	{1, 0,  5, 0, TRUE, ecam_probe_sata, 1}, /* SATA 1 */
	{1, 0,  6, 0, TRUE, ecam_probe_sata, 2}, /* SATA 2 */
	{1, 0,  7, 0, TRUE, ecam_probe_sata, 3}, /* SATA 3 */
	{1, 0,  8, 0, TRUE, ecam_probe_sata, 4}, /* SATA 4 */
	{1, 0,  9, 0, TRUE, ecam_probe_sata, 5}, /* SATA 5 */
	{-1, 0, 0, 0, 0, NULL, 0},
};

static struct ecam_device *cn83xx_get_dev_idx(int node, int ecam)
{
	int node_ecam = ecam | (node << 2);
	struct ecam_device *devs = NULL;

	switch (node_ecam) {
	case 0:
		devs = &devs0_cn83xx[0];
		break;
	}
	return devs;
}

/* Check fuses to see if the device on bus is available
 * or not. If available return 0, else return -1
 */
static int cn83xx_disable_device_on_bus(int node, int bus)
{
	int i;
	uint32_t fuse_cnt = 0;

	/* Check if CPT block is available by reading the fuse */
	if (bus == 4) {
		for (i = 1665; i <= 1680; i++) {
			fuse_cnt += thunder_fuse_read(node, i);
		}

		if (fuse_cnt == 16)
			return 1;
	}

	return 0;
}

int max_bus_cn83xx[] = { 6, 0, 1, 0 };

static int cn83xx_get_max_bus(int ecam)
{
	return max_bus_cn83xx[ecam];
}

static uint64_t cn83xx_get_config_addr(int node, int ecam)
{
	/* TODO: Get this value from DTB */
//	return thunder_get_ecam_config_addr(node, ecam);
	return 0x848000000000;
}

static uint64_t cn83xx_get_config_size(int node, int ecam)
{
	/* TODO: Get this value from DTB */
//	return thunder_get_ecam_config_size(node, ecam);
	return 0x02000000;
}

const struct ecam_platform_defs ecam_defs = {
	.soc_type = T83PARTNUM,
	.get_dev_idx = cn83xx_get_dev_idx,
	.get_max_bus = cn83xx_get_max_bus,
	.get_config_addr = cn83xx_get_config_addr,
	.get_config_size = cn83xx_get_config_size,
	.disable_device_on_bus = cn83xx_disable_device_on_bus,
};


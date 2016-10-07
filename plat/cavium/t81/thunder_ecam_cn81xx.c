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

	cfg.u = CSR_READ_PA(node, CAVM_GSERX_CFG(arg));

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

struct ecam_device devs0_cn81xx[] = {
	{0, 0, 1, 0, TRUE, NULL, 0},	/* PCCBR_MRML */
	{0, 0, 2, 0, FALSE, NULL, 0},	/* SMMU 0 */
	{0, 0, 3, 0, FALSE, NULL, 0},	/* GIC */
	{0, 0, 4, 0, FALSE, NULL, 0},	/* GTI */
	{0, 0, 6, 0, TRUE, NULL, 0},	/* GPIO */
	{0, 0, 7, 0, TRUE, NULL, 0},	/* MPI */
	{0, 0, 8, 0, FALSE, NULL, 0},	/* MIO_PTP */
	{0, 0, 9, 0, TRUE, NULL, 0},	/* RNM */
	{0, 0, 10, 0, TRUE, NULL, 0},	/* BCH */
	{0, 0, 11, 0, TRUE, NULL, 0},	/* NAND */
	{0, 0, 12, 0, TRUE, NULL, 0},	/* CPT bridge */
	{0, 0, 13, 0, TRUE, NULL, 0},	/* PCM */
	{0, 0, 14, 0, TRUE, NULL, 0},	/* SLI */
	{0, 0, 15, 0, TRUE, NULL, 0},	/* PCCBR_NIC */
	{0, 0, 16, 0, TRUE, NULL, 0},	/* USB 0 */
	{0, 0, 17, 0, TRUE, NULL, 0},	/* USB 1 */
	{0, 0, 22, 0, TRUE, ecam_probe_sata, 3},	/* SATA 0 */
	{0, 0, 23, 0, TRUE, ecam_probe_sata, 3},	/* SATA 1 */

	/* Bus1, ARI functions */
	{0, 1, 0, 0, TRUE, NULL, 0},	/* MRML */
	{0, 1, 0, 1, TRUE, NULL, 0},	/* RST */
	{0, 1, 0, 2, FALSE, NULL, 0},	/* DAP */
	{0, 1, 0, 3, FALSE, NULL, 0},	/* FUS */
	{0, 1, 0, 4, FALSE, NULL, 0},	/* FUSF */
	{0, 1, 0, 9, FALSE, NULL, 0},	/* L2C */
	{0, 1, 0, 10, FALSE, NULL, 0},	/* SGP */
	{0, 1, 0, 11, TRUE, NULL, 0},	/* SMI */
	{0, 1, 0, 12, TRUE, NULL, 0},	/* MIO_EMM */
	{0, 1, 0, 13, FALSE, NULL, 0},	/* KEY */
	{0, 1, 0, 14, FALSE, NULL, 0},	/* BOOT BUS */
	{0, 1, 0, 15, TRUE, NULL, 0},	/* PBUS */
	{0, 1, 0, 16, TRUE, NULL, 0},	/* XCV */
	{0, 1, 0, 48, TRUE, NULL, 0},	/* L2C-TAD 0 */
	{0, 1, 0, 56, TRUE, NULL, 0},	/* L2C-CBC 0 */
	{0, 1, 0, 60, TRUE, NULL, 0},	/* L2C-MCI 0 */
	{0, 1, 0, 64, FALSE, NULL, 0},	/* UAA 0 */
	{0, 1, 0, 65, FALSE, NULL, 0},	/* UAA 1 */
	{0, 1, 0, 66, FALSE, NULL, 0},	/* UAA 2 */
	{0, 1, 0, 67, FALSE, NULL, 0},	/* UAA 3 */
	{0, 1, 0, 72, TRUE, ecam_probe_twsi, 0},	/* TWSI 0 */
	{0, 1, 0, 73, TRUE, ecam_probe_twsi, 1},	/* TWSI 1 */
	{0, 1, 0, 80, TRUE, NULL, 0},	/* LMC 0 */
	{0, 1, 0, 96, TRUE, NULL, 0},	/* OCLA 0 */
	{0, 1, 0, 97, TRUE, NULL, 0},	/* OCLA 1 */
	{0, 1, 0, 112, FALSE, ecam_probe_pem, 0},	/* PEM 0 */
	{0, 1, 0, 113, FALSE, ecam_probe_pem, 1},	/* PEM 1 */
	{0, 1, 0, 114, FALSE, ecam_probe_pem, 2},	/* PEM 2 */
	{0, 1, 0, 128, TRUE, ecam_probe_bgx, 0},	/* BGX 0 */
	{0, 1, 0, 129, TRUE, ecam_probe_bgx, 2},	/* BGX 1 */
	{0, 1, 0, 144, TRUE, NULL, 0},	/* RGX0 */

	{0, 2, 0, 0, TRUE, NULL, 0},	/* RNM */
	{0, 3, 0, 0, TRUE, NULL, 0},	/* BCH */
	{0, 4, 0, 0, TRUE, NULL, 0},	/* CPT0 */
	{0, 5, 0, 0, TRUE, NULL, 0},	/* NIC0 */
	{-1, 0, 0, 0, 0, NULL, 0},
};

static struct ecam_device *cn81xx_get_dev_idx(int node, int ecam)
{
	int node_ecam = ecam | (node << 2);
	struct ecam_device *devs = NULL;

	switch (node_ecam) {
	case 0:
		devs = &devs0_cn81xx[0];
		break;
	}
	return devs;
}

/* Check fuses to see if the device on bus is available
 * or not. If available return 0, else return -1
 */
static int cn81xx_disable_device_on_bus(int node, int bus)
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

int max_bus_cn81xx[] = { 6, 0, 1, 0 };

static int cn81xx_get_max_bus(int ecam)
{
	return max_bus_cn81xx[ecam];
}

static uint64_t cn81xx_get_config_addr(int node, int ecam)
{
	/* TODO: Get this value from DTB */
//	return thunder_get_ecam_config_addr(node, ecam);
	return 0x848000000000;
}

static uint64_t cn81xx_get_config_size(int node, int ecam)
{
	/* TODO: Get this value from DTB */
//	return thunder_get_ecam_config_size(node, ecam);
	return 0x02000000;
}

const struct ecam_platform_defs ecam_defs = {
	.soc_type = T81PARTNUM,
	.get_dev_idx = cn81xx_get_dev_idx,
	.get_max_bus = cn81xx_get_max_bus,
	.get_config_addr = cn81xx_get_config_addr,
	.get_config_size = cn81xx_get_config_size,
	.disable_device_on_bus = cn81xx_disable_device_on_bus,
};

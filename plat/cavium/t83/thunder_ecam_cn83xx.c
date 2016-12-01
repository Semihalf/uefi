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

	cfg_dlm1.u = 0;

	/* On 83xx BGX is split across 2 DLMs, check both DLMs
	 * for marking BGX PCi device secure 
	 */
	switch (arg) {
	case 0:
		cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(2));
		break;
	case 1:
		cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(3));
		break;
	case 2:
		cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(5));
		cfg_dlm1.u = CSR_READ_PA(node, CAVM_GSERX_CFG(6));
		break;
	case 3:
		cfg_dlm0.u = CSR_READ_PA(node, CAVM_GSERX_CFG(4));
		break;
	default:
		cfg_dlm0.u = 0;
	}

	return (cfg_dlm0.s.bgx || cfg_dlm1.s.bgx);
}

/* arg is LMC number */
static int ecam_probe_lmc(int node, unsigned long arg)
{
	return thunder_dram_is_lmc_enabled(node, arg);
}

struct ecam_device devs0_cn83xx[] = {
	{0, 0,  1,   0, TRUE, NULL, 0}, /* PCCBR_MRML */
	{0, 0,  2,   0, FALSE, NULL, 0}, /* SMMU 0 */
	{0, 0,  3,   0, FALSE, NULL, 0}, /* GIC */
	{0, 0,  4,   0, FALSE, NULL, 0}, /* GTI */
	{0, 0,  6,   0, TRUE, NULL, 0}, /* GPIO */
	{0, 0,  7,   0, FALSE, NULL, 0}, /* MPI */
	{0, 0,  8,   0, FALSE, NULL, 0}, /* MIO_PTP */
	{0, 0,  9,   0, TRUE, NULL, 0}, /* PCCBR_RNM */
	{0, 0, 10,   0, TRUE, NULL, 0}, /* PCCBR_BCH */
	{0, 0, 11,   0, TRUE, NULL, 0}, /* NDF */
	{0, 0, 12,   0, TRUE, NULL, 0}, /* PCCBR_CPT0 */
	{0, 0, 13,   0, TRUE, NULL, 0}, /* PCCBR_CPT1 */
	{0, 0, 14,   0, TRUE, NULL, 0}, /* PCCBR_RAD */
	{0, 0, 16,   0, TRUE, NULL, 0}, /* PCCBR_SSO */
	{0, 0, 17,   0, TRUE, NULL, 0}, /* PCCBR_SSOW */
	{0, 0, 18,   0, TRUE, NULL, 0}, /* PCCBR_FPA */
	{0, 0, 19,   0, TRUE, NULL, 0}, /* PCCBR_TIM */
	{0, 0, 20,   0, TRUE, NULL, 0}, /* PCCBR_DPI0 */
	{0, 1,  0,   0, TRUE, NULL, 0}, /* MRML */
	{0, 1,  0,   1, TRUE, NULL, 0}, /* RST */
	// 102 DAP
	// 103 MIO_FUS
	// 104 FUSF
	{0, 1,  0,   5, TRUE, NULL, 0}, /* OCX */

	// 108 NCSI
	// 109 L2C
	// 10A Serial GPIO
	{0, 1,  0,  11, TRUE, NULL, 0}, /* SMI */
	{0, 1,  0,  12, TRUE, NULL, 0}, /* MIO_EMM */
	{0, 1,  0,  15, TRUE, NULL, 0}, /* PBUS */
	// 10D KEY
	// 10E MIO_BOOT
	{0, 1 , 0,  48, TRUE, NULL, 0}, /* L2C-TAD 0 */
	{0, 1 , 0,  49, TRUE, NULL, 0}, /* L2C-TAD 1 */
	{0, 1 , 0,  50, TRUE, NULL, 0}, /* L2C-TAD 2 */
	{0, 1 , 0,  51, TRUE, NULL, 0}, /* L2C-TAD 3 */
	{0, 1 , 0,  56, TRUE, NULL, 0}, /* L2C-CBC 0 */
	{0, 1 , 0,  57, TRUE, NULL, 0}, /* L2C-CBC 1 */
	{0, 1 , 0,  60, TRUE, NULL, 0}, /* L2C-MCI 0 */
	{0, 1 , 0,  61, TRUE, NULL, 0}, /* L2C-MCI 1 */
	{0, 1 , 0,  62, TRUE, NULL, 0}, /* L2C-MCI 2 */

	{0, 1,  0,  64, FALSE, NULL, 0}, /* UAA 0 */
	{0, 1,  0,  65, FALSE, NULL, 0}, /* UAA 1 */
	{0, 1,  0,  66, FALSE, NULL, 0}, /* UAA 2 */
	{0, 1,  0,  67, FALSE, NULL, 0}, /* UAA 3 */
	{0, 1 , 0,  72, TRUE, ecam_probe_twsi, 0}, /* TWSI 0 */
	{0, 1 , 0,  73, TRUE, ecam_probe_twsi, 1}, /* TWSI 1 */

	{0, 1 , 0,  80, TRUE, ecam_probe_lmc, 0}, /* LMC 0 */
	{0, 1 , 0,  81, TRUE, ecam_probe_lmc, 1}, /* LMC 1 */
	// 158 IOBN 0
	// 159 IOBN 1
	{0, 1 , 0,  96, TRUE, NULL, 0}, /* OCLA 0 */
	{0, 1 , 0,  97, TRUE, NULL, 0}, /* OCLA 1 */
	{0, 1 , 0,  98, TRUE, NULL, 0}, /* OCLA 2 */

	{0, 1,  0, 104, TRUE, NULL, 0}, /* LBK0 */
	{0, 1,  0, 105, TRUE, NULL, 0}, /* LBK1 */
	{0, 1,  0, 106, TRUE, NULL, 0}, /* LBK2 */
	{0, 1,  0, 107, TRUE, NULL, 0}, /* LBK3 */

	{0, 1 , 0, 112, FALSE, ecam_probe_pem, 0}, /* PEM 0 */
	{0, 1 , 0, 113, FALSE, ecam_probe_pem, 1}, /* PEM 1 */
	{0, 1 , 0, 114, FALSE, ecam_probe_pem, 2}, /* PEM 2 */
	{0, 1 , 0, 115, FALSE, ecam_probe_pem, 3}, /* PEM 3 */

	{0, 1,  0, 128, TRUE, ecam_probe_bgx, 0}, /* BGX 0 */
	{0, 1,  0, 129, TRUE, ecam_probe_bgx, 1}, /* BGX 1 */
	{0, 1,  0, 130, TRUE, ecam_probe_bgx, 2}, /* BGX 2 */
	{0, 1,  0, 131, TRUE, ecam_probe_bgx, 3}, /* BGX 3 */
	// 1E0 GSER 0
	// 1E1 GSER 1
	// 1E2 GSER 2
	// 1E3 GSER 3
	// 1E4 GSER 4
	// 1E5 GSER 5
	// 1E6 GSER 6
	// 1E7 GSER 7
	// 1E8 GSER 8
	// 1E9 GSER 9
	// 1EA GSER 10
	// 1EB GSER 11
	// 1EC GSER 12
	// 1ED GSER 13
	{0, 2,  0,   0, TRUE, NULL, 0}, /* RNM */
	{0, 3,  0,   0, TRUE, NULL, 0}, /* BCH */
	{0, 4,  0,   0, TRUE, NULL, 0}, /* CPT0 */
	{0, 5,  0,   0, TRUE, NULL, 0}, /* CPT1 */
	{0, 6,  0,   0, TRUE, NULL, 0}, /* RAD */
	{0, 7,  0,   0, TRUE, NULL, 0}, /* SSO */
	{0, 8,  0,   0, TRUE, NULL, 0}, /* SSOW */
	{0, 9,  0,   0, TRUE, NULL, 0}, /* FPA */
	{0, 10,  0,   0, TRUE, NULL, 0}, /* TIM */
	{0, 11,  0,   0, TRUE, NULL, 0}, /* DPI0 */

	/*ECAM1*/

	{1, 0,  1, 0, FALSE, NULL, 0}, /* SMMU 1 */
	// 0, 2, 0 SLI 0
	{1, 0,  4, 0, TRUE, ecam_probe_sata, 0}, /* SATA 0 */
	{1, 0,  5, 0, TRUE, ecam_probe_sata, 1}, /* SATA 1 */
	{1, 0,  6, 0, TRUE, ecam_probe_sata, 2}, /* SATA 2 */
	{1, 0,  7, 0, TRUE, ecam_probe_sata, 3}, /* SATA 3 */
	{1, 0,  8, 0, TRUE, ecam_probe_sata, 4}, /* SATA 4 */
	{1, 0,  9, 0, TRUE, ecam_probe_sata, 5}, /* SATA 5 */
	{1, 0, 12, 0, TRUE, NULL, 0}, /* USBDRD0 */
	{1, 0, 13, 0, TRUE, NULL, 0}, /* USBDRD1 */
	{1, 0, 16, 0, TRUE, NULL, 0}, /* PCCBR_NIC */
	{1, 0, 17, 0, TRUE, NULL, 0}, /* PCCBR_PKI */
	{1, 0, 18, 0, TRUE, NULL, 0}, /* PCCBR_PKO */
	{1, 0, 19, 0, TRUE, NULL, 0}, /* PCCBR_ZIP */
	{1, 0, 20, 0, TRUE, NULL, 0}, /* PCCBR_DDF0 */
	{1, 1,  0, 0, TRUE, NULL, 0}, /* NIC */
	{1, 2,  0, 0, TRUE, NULL, 0}, /* PKI */
	{1, 3,  0, 0, TRUE, NULL, 0}, /* PKO */
	{1, 4,  0, 0, TRUE, NULL, 0}, /* ZIP */
	{1, 5,  0, 0, TRUE, NULL, 0}, /* DDF0 */
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
	case 1:
		devs = &devs0_cn83xx[1];
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

int max_bus_cn83xx[] = { 11, 5};

static int cn83xx_get_max_bus(int ecam)
{
	return max_bus_cn83xx[ecam];
}

static uint64_t cn83xx_get_config_addr(int node, int ecam)
{
	return thunder_get_ecam_config_addr(node, ecam);
}

static uint64_t cn83xx_get_config_size(int node, int ecam)
{
	return thunder_get_ecam_config_size(node, ecam);
}

const struct ecam_platform_defs ecam_devices_ops = {
	.soc_type = T83PARTNUM,
	.get_dev_idx = cn83xx_get_dev_idx,
	.get_max_bus = cn83xx_get_max_bus,
	.get_config_addr = cn83xx_get_config_addr,
	.get_config_size = cn83xx_get_config_size,
	.disable_device_on_bus = cn83xx_disable_device_on_bus,
};


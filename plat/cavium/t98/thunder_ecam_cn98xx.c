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

#include <stdint.h>
#include <stdio.h>

#include <thunder_common.h>
#include <thunder_dt.h>
#include <thunder_ecam.h>

struct ecam_device devs_cn98xx[] = {
	{0, 0, 1, 0, TRUE, -1, NULL, 0},	/* PCCBR_MRML */
	{0, 0, 2, 0, FALSE, -1, NULL, 0},	/* SMMU 0 */
	{0, 0, 3, 0, FALSE, -1, NULL, 0},	/* GIC */
	{0, 0, 4, 0, FALSE, -1, NULL, 0},	/* GTI */
	{0, 0, 6, 0, TRUE, -1, NULL, 0},	/* GPIO */
	{0, 0, 7, 0, TRUE, -1, NULL, 0},	/* MPI */
	{0, 0, 8, 0, FALSE, -1, NULL, 0},	/* MIO_PTP */
	{0, 0, 9, 0, TRUE, -1, NULL, 0},	/* RNM */
	{0, 0, 11, 0, TRUE, -1, NULL, 0},	/* NAND */
	{0, 0, 24, 0, TRUE, -1, NULL, 0},	/* SLIRE 0 */

	/* Bus1, ARI functions */
	{0, 1, 0, 0, TRUE, 0, NULL, 0},		/* MRML */
	{0, 1, 0, 1, TRUE, 0, NULL, 0},		/* RST */
	{0, 1, 0, 2, FALSE, 0, NULL, 0},	/* DAP */
	{0, 1, 0, 3, FALSE, 0, NULL, 0},	/* FUS */
	{0, 1, 0, 4, FALSE, 0, NULL, 0},	/* FUSF */
	{0, 1, 0, 5, TRUE, 0, NULL, 0},		/* OCX */
	{0, 1, 0, 8, TRUE, 0, NULL, 0},         /* NCSI */
	{0, 1, 0, 9, FALSE, 0, NULL, 0},	/* CCS */
	{0, 1, 0, 10, FALSE, 0, NULL, 0},	/* SGP */
	{0, 1, 0, 11, TRUE, 0, NULL, 0},	/* SMI */
	{0, 1, 0, 12, TRUE, 0, NULL, 0},	/* EMM */
	{0, 1, 0, 13, FALSE, 0, NULL, 0},	/* KEY */
	{0, 1, 0, 14, FALSE, 0, NULL, 0},	/* BOOT BUS */
	{0, 1, 0, 15, TRUE, 0, NULL, 0},	/* PBUS */
	{0, 1, 0, 32, FALSE, 0, NULL, 0},        /* CCU0 */
	{0, 1, 0, 33, FALSE, 0, NULL, 0},        /* CCU1 */
	{0, 1, 0, 34, FALSE, 0, NULL, 0},        /* CCU2 */
	{0, 1, 0, 35, FALSE, 0, NULL, 0},        /* CCU3 */
	{0, 1, 0, 36, FALSE, 0, NULL, 0},        /* CCU4 */
	{0, 1, 0, 37, FALSE, 0, NULL, 0},        /* CCU5 */
	{0, 1, 0, 38, FALSE, 0, NULL, 0},        /* CCU6 */
	{0, 1, 0, 39, FALSE, 0, NULL, 0},        /* CCU7 */
	{0, 1, 0, 40, FALSE, 0, NULL, 0},        /* CCU8 */
	{0, 1, 0, 64, FALSE, 0, NULL, 0},        /* MDC */
	{0, 1, 0, 68, FALSE, 0, NULL, 0},        /* TSN */
	{0, 1, 0, 72, TRUE, 0, NULL, 0},	/* TWSI 0 */
	{0, 1, 0, 73, TRUE, 0, NULL, 1},	/* TWSI 1 */
	{0, 1, 0, 74, TRUE, 0, NULL, 2},	/* TWSI 2 */
	{0, 1, 0, 75, TRUE, 0, NULL, 3},	/* TWSI 3 */
	{0, 1, 0, 76, TRUE, 0, NULL, 4},	/* TWSI 4 */
	{0, 1, 0, 77, TRUE, 0, NULL, 5},	/* TWSI 5 */
	{0, 1, 0, 80, TRUE, 0, NULL, 0},	/* LMC 0 */
	{0, 1, 0, 81, TRUE, 0, NULL, 0},	/* LMC 1 */
	{0, 1, 0, 88, FALSE, 0, NULL, 0},	/* IOBN 0 */
	{0, 1, 0, 89, FALSE, 0, NULL, 0},	/* IOBN 1 */
	{0, 1, 0, 90, FALSE, 0, NULL, 0},	/* IOBN 2 */
	{0, 1, 0, 96, FALSE, -1, NULL, 0},	/* UAA 0 */
	{0, 1, 0, 97, FALSE, -1, NULL, 0},	/* UAA 1 */
	{0, 1, 0, 98, FALSE, -1, NULL, 0},	/* UAA 2 */
	{0, 1, 0, 99, FALSE, -1, NULL, 0},	/* UAA 3 */
	{0, 1, 0, 100, FALSE, -1, NULL, 0},	/* UAA 4 */
	{0, 1, 0, 101, FALSE, -1, NULL, 0},	/* UAA 5 */
	{0, 1, 0, 102, FALSE, -1, NULL, 0},	/* UAA 6 */
	{0, 1, 0, 103, FALSE, -1, NULL, 0},	/* UAA 7 */
	{0, 1, 0, 104, TRUE, 0, NULL, 0},	/* LBK 0 */
	{0, 1, 0, 128, TRUE, 0, NULL, 0},	/* CGX 0 */
	{0, 1, 0, 129, TRUE, 0, NULL, 0},	/* CGX 1 */
	{0, 1, 0, 130, TRUE, 0, NULL, 0},	/* CGX 2 */
	{0, 1, 0, 131, TRUE, 0, NULL, 0},	/* CGX 3 */
	{0, 1, 0, 144, TRUE, 0, NULL, 0},	/* OCLA 0 */
	{0, 1, 0, 145, TRUE, 0, NULL, 0},	/* OCLA 1 */
	{0, 1, 0, 146, TRUE, 0, NULL, 0},	/* OCLA 2 */
	{0, 1, 0, 147, TRUE, 0, NULL, 0},	/* OCLA 3 */
	{0, 1, 0, 148, TRUE, 0, NULL, 0},	/* OCLA 4 */
	{0, 1, 0, 149, TRUE, 0, NULL, 0},	/* OCLA 5 */
	{0, 1, 0, 150, TRUE, 0, NULL, 0},	/* OCLA 6 */
	{0, 1, 0, 151, TRUE, 0, NULL, 0},	/* OCLA 7 */
	{0, 1, 0, 152, TRUE, 0, NULL, 0},	/* OCLA 8 */
	{0, 1, 0, 153, TRUE, 0, NULL, 0},	/* OCLA 9 */
	{0, 1, 0, 240, TRUE, 0, NULL, 0},	/* GSER 0 */
	{0, 1, 0, 241, TRUE, 0, NULL, 0},	/* GSER 1 */
	{0, 1, 0, 242, TRUE, 0, NULL, 0},	/* GSER 2 */
	{0, 1, 0, 243, TRUE, 0, NULL, 0},	/* GSER 3 */
	{0, 1, 0, 244, TRUE, 0, NULL, 0},	/* GSER 4 */
	{0, 1, 0, 245, TRUE, 0, NULL, 0},	/* GSER 5 */
	{0, 1, 0, 246, TRUE, 0, NULL, 0},	/* GSER 6 */
	{0, 1, 0, 247, TRUE, 0, NULL, 0},	/* GSER 7 */
	{0, 1, 0, 248, TRUE, 0, NULL, 0},	/* GSER 8 */
	{0, 1, 0, 249, TRUE, 0, NULL, 0},	/* GSER 9 */
	{0, 1, 0, 250, TRUE, 0, NULL, 0},	/* GSER 10 */
	{0, 1, 0, 251, TRUE, 0, NULL, 0},	/* GSER 11 */
	{0, 1, 0, 252, TRUE, 0, NULL, 0},	/* GSER 12 */
	{0, 1, 0, 253, TRUE, 0, NULL, 0},	/* GSER 13 */
	{0, 1, 0, 254, TRUE, 0, NULL, 0},	/* GSER 14 */
	{0, 1, 0, 255, TRUE, 0, NULL, 0},	/* GSER 15 */

	/* Bus 2 */
	{0, 2, 0, 0, TRUE, 0, NULL, 0},		/* RNM */

	/* Domain 1 */

	{1, 0, 1, 0, TRUE, 0, NULL, 0},		/* SMMU 1 */
	{1, 0, 2, 0, TRUE, 0, NULL, 0},		/* XCP 0 */
	{1, 0, 2, 1, TRUE, 0, NULL, 0},		/* XCP 1 */
	{1, 0, 2, 3, TRUE, 0, NULL, 0},		/* CPC */
	{1, 0, 4, 0, TRUE, 0, NULL, 0},		/* SATA 0 */
	{1, 0, 5, 0, TRUE, 0, NULL, 0},		/* SATA 1 */
	{1, 0, 6, 0, TRUE, 0, NULL, 0},		/* SATA 2 */
	{1, 0, 7, 0, TRUE, 0, NULL, 0},		/* SATA 3 */
	{1, 0, 8, 0, TRUE, 0, NULL, 0},		/* SATA 4 */
	{1, 0, 9, 0, TRUE, 0, NULL, 0},		/* SATA 5 */
	{1, 0, 10, 0, TRUE, 0, NULL, 0},	/* USBDRD 0 */
	{1, 0, 11, 0, TRUE, 0, NULL, 0},	/* USBDRD 1 */
	{1, 0, 12, 0, TRUE, 0, NULL, 0},	/* PEM 0 */
	{1, 0, 13, 0, TRUE, 0, NULL, 0},	/* PEM 1 */
	{1, 0, 14, 0, TRUE, 0, NULL, 0},	/* PEM 2 */
	{1, 0, 15, 0, TRUE, 0, NULL, 0},	/* PEM 3 */
	{1, 0, 16, 0, TRUE, 0, NULL, 0},	/* PCCBR_NIC */

	{1, 1, 0, 0, TRUE, 0, NULL, 0},		/* NIC 0 */

	/* Domain 3 */
	{3, 0, 1, 0, FALSE, 0, NULL, 0},	/* SMMU 2 */
	{3, 0, 4, 0, FALSE, 0, NULL, 0},	/* SATA 6 */
	{3, 0, 5, 0, FALSE, 0, NULL, 0},	/* SATA 7 */
	{3, 0, 6, 0, FALSE, 0, NULL, 0},	/* SATA 8 */
	{3, 0, 7, 0, FALSE, 0, NULL, 0},	/* SATA 9 */
	{3, 0, 8, 0, FALSE, 0, NULL, 0},	/* SATA 10 */
	{3, 0, 9, 0, FALSE, 0, NULL, 0},	/* SATA 11 */
	{3, 0, 10, 0, FALSE, 0, NULL, 0},	/* SATA 12 */
	{3, 0, 11, 0, FALSE, 0, NULL, 0},	/* SATA 13 */
	{3, 0, 12, 0, FALSE, 0, NULL, 0},	/* SATA 14 */
	{3, 0, 13, 0, FALSE, 0, NULL, 0},	/* SATA 15 */
	{3, 0, 14, 0, FALSE, 0, NULL, 0},	/* SATA 16 */
	{3, 0, 15, 0, FALSE, 0, NULL, 0},	/* SATA 17 */
	{3, 0, 16, 0, FALSE, 0, NULL, 0},	/* SATA 18 */
	{3, 0, 17, 0, FALSE, 0, NULL, 0},	/* SATA 19 */

	{-1, 0, 0, 0, 0, -1, NULL, 0},
};

static struct ecam_device *cn98xx_get_dev_idx(int node, int ecam)
{
	int node_ecam = ecam | (node << 2);
	struct ecam_device *devs = NULL;

	switch (node_ecam) {
	case 0:
		devs = &devs_cn98xx[0];
		break;
	}
	return devs;
}
/* TODO: Update values here */
int max_bus_cn98xx[] = { 6, 6, 6, 6 };

static int cn98xx_get_max_bus(int ecam)
{
	return max_bus_cn98xx[ecam];
}

static uint64_t cn98xx_get_config_addr(int node, int ecam)
{
	/* TODO: Get this value from DTB */
	return 0x848000000000;
}

static uint64_t cn98xx_get_config_size(int node, int ecam)
{
	/* TODO: Get this value from DTB */
	return 0x02000000;
}

const struct ecam_platform_defs ecam_defs = {
	.soc_type = T98PARTNUM,
	.get_dev_idx = cn98xx_get_dev_idx,
	.get_max_bus = cn98xx_get_max_bus,
	.get_config_addr = cn98xx_get_config_addr,
	.get_config_size = cn98xx_get_config_size,
	.disable_device_on_bus = NULL,
};


#ifndef __BDK_CSRS_SMI__
#define __BDK_CSRS_SMI__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2015  Cavium Inc. (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Inc. nor the names of
 *     its contributors may be used to endorse or promote products
 *     derived from this software without specific prior written
 *     permission.

 * This Software, including technical data, may be subject to U.S. export  control
 * laws, including the U.S. Export Administration Act and its  associated
 * regulations, and may be subject to export or import  regulations in other
 * countries.

 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR
 * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO
 * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR
 * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM
 * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,
 * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF
 * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR
 * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR
 * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 ***********************license end**************************************/


/**
 * @file
 *
 * Configuration and status register (CSR) address and type definitions for
 * Cavium SMI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * RSL - smi_#_clk
 *
 * This register determines the SMI timing characteristics.
 * If software wants to change SMI CLK timing parameters (SAMPLE/SAMPLE_HI), software
 * must delay the SMI_CLK CSR write by at least 512 coprocessor-clocks after the
 * previous SMI operation is finished.
 */
typedef union bdk_smi_x_clk {
	uint64_t u;
	struct bdk_smi_x_clk_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t mode                        : 1;  /**< R/W - IEEE operating mode; 0 = Clause 22 compliant, 1 = Clause 45 compliant. */
		uint64_t reserved_21_23              : 3;
		uint64_t sample_hi                   : 5;  /**< R/W - Sample (extended bits). Specifies in coprocessor clock cycles when to sample read data. */
		uint64_t sample_mode                 : 1;  /**< R/W - Read data sampling mode.
                                                                 According to the 802.3 specification, on read operations, the STA transitions SMIn_MDC and
                                                                 the PHY drives SMIn_MDIO with some delay relative to that edge. This is Edge1.
                                                                 The STA then samples SMIn_MDIO on the next rising edge of SMIn_MDC. This is Edge2. The
                                                                 read data can be sampled relative to either edge.
                                                                 0 = Sample time is relative to Edge2.
                                                                 1 = Sample time is relative to Edge1. */
		uint64_t reserved_14_14              : 1;
		uint64_t clk_idle                    : 1;  /**< R/W - SMIn_MDC toggle. When set, this bit causes SMIn_MDC not to toggle on idle cycles. */
		uint64_t preamble                    : 1;  /**< R/W - Preamble. When this bit is set, the 32-bit preamble is sent first on SMI transactions.
                                                                 This field must be set to 1 when MODE = 1 in order for the receiving PHY to correctly
                                                                 frame the transaction. */
		uint64_t sample                      : 4;  /**< R/W - Sample read data. Specifies the number of coprocessor clock cycles after the rising edge
                                                                 of SMIn_MDC to wait before sampling read data.

                                                                 _ (SAMPLE_HI,SAMPLE) \> 1

                                                                 _ (SAMPLE_HI,SAMPLE) + 3 \<= 2 * PHASE */
		uint64_t phase                       : 8;  /**< R/W - MDC clock phase. Specifies the number of coprocessor clock cycles that make up an SMIn_MDC
                                                                 phase.

                                                                 _ PHASE \> 2 */
#else
		uint64_t phase                       : 8;
		uint64_t sample                      : 4;
		uint64_t preamble                    : 1;
		uint64_t clk_idle                    : 1;
		uint64_t reserved_14_14              : 1;
		uint64_t sample_mode                 : 1;
		uint64_t sample_hi                   : 5;
		uint64_t reserved_21_23              : 3;
		uint64_t mode                        : 1;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_smi_x_clk_s             cn88xx; */
	/* struct bdk_smi_x_clk_s             cn88xxp1; */
} bdk_smi_x_clk_t;

static inline uint64_t BDK_SMI_X_CLK(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_X_CLK(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E005003818ull + (param1 & 1) * 0x80ull;
	csr_fatal("BDK_SMI_X_CLK", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMI_X_CLK(...) bdk_smi_x_clk_t
#define bustype_BDK_SMI_X_CLK(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_X_CLK(p1) (p1)
#define arguments_BDK_SMI_X_CLK(p1) (p1),-1,-1,-1
#define basename_BDK_SMI_X_CLK(...) "SMI_X_CLK"


/**
 * RSL - smi_#_cmd
 *
 * This register forces a read or write command to the PHY. Write operations to this register
 * create SMI transactions. Software will poll (depending on the transaction type).
 */
typedef union bdk_smi_x_cmd {
	uint64_t u;
	struct bdk_smi_x_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t phy_op                      : 2;  /**< R/W - PHY opcode, depending on SMI_()_CLK[MODE] setting.
                                                                 * If SMI_()_CLK[MODE] = 0 (\<=1Gbs / Clause 22):
                                                                 0 = write operation, encoded in the frame as 01
                                                                 1 = read operation, encoded in the frame as 10.

                                                                 * If SMI_()_CLK[MODE] = 1 (\>1Gbs / Clause 45):
                                                                 0x0 = Address.
                                                                 0x1 = Write.
                                                                 0x2 = Post-read-increment-address.
                                                                 0x3 = Read. */
		uint64_t reserved_13_15              : 3;
		uint64_t phy_adr                     : 5;  /**< R/W - PHY address. */
		uint64_t reserved_5_7                : 3;
		uint64_t reg_adr                     : 5;  /**< R/W - PHY register offset. */
#else
		uint64_t reg_adr                     : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t phy_adr                     : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t phy_op                      : 2;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_smi_x_cmd_s             cn88xx; */
	/* struct bdk_smi_x_cmd_s             cn88xxp1; */
} bdk_smi_x_cmd_t;

static inline uint64_t BDK_SMI_X_CMD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_X_CMD(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E005003800ull + (param1 & 1) * 0x80ull;
	csr_fatal("BDK_SMI_X_CMD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMI_X_CMD(...) bdk_smi_x_cmd_t
#define bustype_BDK_SMI_X_CMD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_X_CMD(p1) (p1)
#define arguments_BDK_SMI_X_CMD(p1) (p1),-1,-1,-1
#define basename_BDK_SMI_X_CMD(...) "SMI_X_CMD"


/**
 * RSL - smi_#_en
 *
 * Enables the SMI interface.
 *
 */
typedef union bdk_smi_x_en {
	uint64_t u;
	struct bdk_smi_x_en_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t en                          : 1;  /**< R/W - SMI/MDIO interface enable:
                                                                 1 = Enable interface.
                                                                 0 = Disable interface: no transactions, no SMIn_MDC transitions. */
#else
		uint64_t en                          : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_smi_x_en_s              cn88xx; */
	/* struct bdk_smi_x_en_s              cn88xxp1; */
} bdk_smi_x_en_t;

static inline uint64_t BDK_SMI_X_EN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_X_EN(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E005003820ull + (param1 & 1) * 0x80ull;
	csr_fatal("BDK_SMI_X_EN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMI_X_EN(...) bdk_smi_x_en_t
#define bustype_BDK_SMI_X_EN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_X_EN(p1) (p1)
#define arguments_BDK_SMI_X_EN(p1) (p1),-1,-1,-1
#define basename_BDK_SMI_X_EN(...) "SMI_X_EN"


/**
 * RSL - smi_#_rd_dat
 *
 * This register contains the data in a read operation.
 *
 */
typedef union bdk_smi_x_rd_dat {
	uint64_t u;
	struct bdk_smi_x_rd_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t pending                     : 1;  /**< RO/H - Read transaction pending. Indicates that an SMI read transaction is in flight. */
		uint64_t val                         : 1;  /**< RO/H - Read data valid. Asserts when the read transaction completes. A read to this register clears VAL. */
		uint64_t dat                         : 16; /**< RO/H - Read data. */
#else
		uint64_t dat                         : 16;
		uint64_t val                         : 1;
		uint64_t pending                     : 1;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_smi_x_rd_dat_s          cn88xx; */
	/* struct bdk_smi_x_rd_dat_s          cn88xxp1; */
} bdk_smi_x_rd_dat_t;

static inline uint64_t BDK_SMI_X_RD_DAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_X_RD_DAT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E005003810ull + (param1 & 1) * 0x80ull;
	csr_fatal("BDK_SMI_X_RD_DAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMI_X_RD_DAT(...) bdk_smi_x_rd_dat_t
#define bustype_BDK_SMI_X_RD_DAT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_X_RD_DAT(p1) (p1)
#define arguments_BDK_SMI_X_RD_DAT(p1) (p1),-1,-1,-1
#define basename_BDK_SMI_X_RD_DAT(...) "SMI_X_RD_DAT"


/**
 * RSL - smi_#_wr_dat
 *
 * This register provides the data for a write operation.
 *
 */
typedef union bdk_smi_x_wr_dat {
	uint64_t u;
	struct bdk_smi_x_wr_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t pending                     : 1;  /**< RO/H - Write transaction pending. Indicates that an SMI write transaction is in flight. */
		uint64_t val                         : 1;  /**< RO/H - Write data valid. Asserts when the write transaction completes. A read to this register clears VAL. */
		uint64_t dat                         : 16; /**< R/W/H - Write data. */
#else
		uint64_t dat                         : 16;
		uint64_t val                         : 1;
		uint64_t pending                     : 1;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_smi_x_wr_dat_s          cn88xx; */
	/* struct bdk_smi_x_wr_dat_s          cn88xxp1; */
} bdk_smi_x_wr_dat_t;

static inline uint64_t BDK_SMI_X_WR_DAT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_X_WR_DAT(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E005003808ull + (param1 & 1) * 0x80ull;
	csr_fatal("BDK_SMI_X_WR_DAT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_SMI_X_WR_DAT(...) bdk_smi_x_wr_dat_t
#define bustype_BDK_SMI_X_WR_DAT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_X_WR_DAT(p1) (p1)
#define arguments_BDK_SMI_X_WR_DAT(p1) (p1),-1,-1,-1
#define basename_BDK_SMI_X_WR_DAT(...) "SMI_X_WR_DAT"


/**
 * RSL - smi_drv_ctl
 *
 * Enables the SMI interface.
 *
 */
typedef union bdk_smi_drv_ctl {
	uint64_t u;
	struct bdk_smi_drv_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t pctl                        : 3;  /**< R/W - PCTL drive strength control bits. Suggested values:
                                                                 0x4 = 75 ohm.
                                                                 0x6 = 50 ohm.
                                                                 0x7 = 40 ohm. */
		uint64_t reserved_3_7                : 5;
		uint64_t nctl                        : 3;  /**< R/W - NCTL drive strength control bits. Suggested values:
                                                                 0x4 = 75 ohm.
                                                                 0x6 = 50 ohm.
                                                                 0x7 = 40 ohm. */
#else
		uint64_t nctl                        : 3;
		uint64_t reserved_3_7                : 5;
		uint64_t pctl                        : 3;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_smi_drv_ctl_s           cn88xx; */
	/* struct bdk_smi_drv_ctl_s           cn88xxp1; */
} bdk_smi_drv_ctl_t;

#define BDK_SMI_DRV_CTL BDK_SMI_DRV_CTL_FUNC()
static inline uint64_t BDK_SMI_DRV_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SMI_DRV_CTL_FUNC(void)
{
	return 0x000087E005003828ull;
}
#define typedef_BDK_SMI_DRV_CTL bdk_smi_drv_ctl_t
#define bustype_BDK_SMI_DRV_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_SMI_DRV_CTL 0
#define arguments_BDK_SMI_DRV_CTL -1,-1,-1,-1
#define basename_BDK_SMI_DRV_CTL "SMI_DRV_CTL"

#endif /* __BDK_CSRS_SMI__ */

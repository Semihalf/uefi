#ifndef __BDK_CSRS_MPI__
#define __BDK_CSRS_MPI__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Inc. (support@cavium.com). All rights
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
 * Cavium MPI.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration MPI_INT_VEC_E
 *
 * MPI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum mpi_int_vec_e {
	MPI_INT_VEC_E_INTS = 0x0,
	MPI_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * NCB - mpi_cfg
 *
 * This register provides configuration for the MPI/SPI interface.
 *
 */
typedef union bdk_mpi_cfg {
	uint64_t u;
	struct bdk_mpi_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_29_63              : 35;
		uint64_t clkdiv                      : 13; /**< R/W - Clock divisor.
                                                                 SPI_CK = coprocessor clock / (2 * CLKDIV)
                                                                 CLKDIV = coprocessor clock / (2 * SPI_CK) */
		uint64_t csena3                      : 1;  /**< R/W - Must be one. */
		uint64_t csena2                      : 1;  /**< R/W - Must be one. */
		uint64_t csena1                      : 1;  /**< R/W - Must be one. */
		uint64_t csena0                      : 1;  /**< R/W - Must be one. */
		uint64_t cslate                      : 1;  /**< R/W - SPI_CSn_L late.
                                                                 0 = SPI_CSn_L asserts 1/2 coprocessor-clock cycle before the transaction.
                                                                 1 = SPI_CSn_L asserts coincident with the transaction. */
		uint64_t tritx                       : 1;  /**< R/W - Tristate TX. Used only when WIREOR = 1
                                                                 0 = SPI_DO pin is driven when slave is not expected to be driving.
                                                                 1 = SPI_DO pin is tristated when not transmitting. */
		uint64_t idleclks                    : 2;  /**< R/W - Idle clocks. When set, guarantees idle coprocessor-clock cycles between commands. */
		uint64_t cshi                        : 1;  /**< R/W - SPI_CSn_L high: 1 = SPI_CSn_L is asserted high, 0 = SPI_CSn_L is asserted low. */
		uint64_t reserved_5_6                : 2;
		uint64_t lsbfirst                    : 1;  /**< R/W - Shift LSB first: 0 = shift MSB first, 1 = shift LSB first. */
		uint64_t wireor                      : 1;  /**< R/W - Wire-OR DO and DI.
                                                                 0 = SPI_DO and SPI_DI are separate wires (SPI). SPI_DO pin is always driven.
                                                                 1 = SPI_DO/DI is all from SPI_DO pin (MPI). SPI_DO pin is tristated when not transmitting.
                                                                 If WIREOR = 1, SPI_DI pin is not used by the MPI/SPI engine. */
		uint64_t clk_cont                    : 1;  /**< R/W - Clock control.
                                                                 0 = clock idles to value given by IDLELO after completion of MPI/SPI transaction.
                                                                 1 = clock never idles, requires SPI_CSn_L deassertion/assertion between commands. */
		uint64_t idlelo                      : 1;  /**< R/W - Clock idle low/clock invert.
                                                                 0 = SPI_CK idles high, first transition is high-to-low. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 1, CPHA = 1.
                                                                 1 = SPI_CK idles low, first transition is low-to-high. This mode corresponds to SPI Block
                                                                 Guide options CPOL = 0, CPHA = 0. */
		uint64_t enable                      : 1;  /**< R/W - MPI/SPI enable.
                                                                 0 = Pins are tristated.
                                                                 1 = Pins are driven. */
#else
		uint64_t enable                      : 1;
		uint64_t idlelo                      : 1;
		uint64_t clk_cont                    : 1;
		uint64_t wireor                      : 1;
		uint64_t lsbfirst                    : 1;
		uint64_t reserved_5_6                : 2;
		uint64_t cshi                        : 1;
		uint64_t idleclks                    : 2;
		uint64_t tritx                       : 1;
		uint64_t cslate                      : 1;
		uint64_t csena0                      : 1;
		uint64_t csena1                      : 1;
		uint64_t csena2                      : 1;
		uint64_t csena3                      : 1;
		uint64_t clkdiv                      : 13;
		uint64_t reserved_29_63              : 35;
#endif
	} s;
	/* struct bdk_mpi_cfg_s               cn88xx; */
	/* struct bdk_mpi_cfg_s               cn88xxp1; */
} bdk_mpi_cfg_t;

#define BDK_MPI_CFG BDK_MPI_CFG_FUNC()
static inline uint64_t BDK_MPI_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_CFG_FUNC(void)
{
	return 0x0000804000001000ull;
}
#define typedef_BDK_MPI_CFG bdk_mpi_cfg_t
#define bustype_BDK_MPI_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_CFG 0
#define arguments_BDK_MPI_CFG -1,-1,-1,-1
#define basename_BDK_MPI_CFG "MPI_CFG"


/**
 * NCB - mpi_dat#
 */
typedef union bdk_mpi_datx {
	uint64_t u;
	struct bdk_mpi_datx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t data                        : 8;  /**< R/W/H - Data to transmit/receive. */
#else
		uint64_t data                        : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_mpi_datx_s              cn88xx; */
	/* struct bdk_mpi_datx_s              cn88xxp1; */
} bdk_mpi_datx_t;

static inline uint64_t BDK_MPI_DATX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_DATX(unsigned long param1)
{
	if (((param1 <= 8)))
		return 0x0000804000001080ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_MPI_DATX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MPI_DATX(...) bdk_mpi_datx_t
#define bustype_BDK_MPI_DATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_DATX(p1) (p1)
#define arguments_BDK_MPI_DATX(p1) (p1),-1,-1,-1
#define basename_BDK_MPI_DATX(...) "MPI_DATX"


/**
 * NCB - mpi_int_ena_w1c
 *
 * This register clears interrupt enables.
 *
 */
typedef union bdk_mpi_int_ena_w1c {
	uint64_t u;
	struct bdk_mpi_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mpi_intr                    : 1;  /**< R/W1C - Reads or clears MPI_INT_ENA_W1S[MPI_INTR]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t mpi_intr                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mpi_int_ena_w1c_s       cn88xx; */
	/* struct bdk_mpi_int_ena_w1c_s       cn88xxp1; */
} bdk_mpi_int_ena_w1c_t;

#define BDK_MPI_INT_ENA_W1C BDK_MPI_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_MPI_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_INT_ENA_W1C_FUNC(void)
{
	return 0x0000804000001030ull;
}
#define typedef_BDK_MPI_INT_ENA_W1C bdk_mpi_int_ena_w1c_t
#define bustype_BDK_MPI_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_INT_ENA_W1C 0
#define arguments_BDK_MPI_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_MPI_INT_ENA_W1C "MPI_INT_ENA_W1C"


/**
 * NCB - mpi_int_ena_w1s
 *
 * This register sets interrupt enables.
 *
 */
typedef union bdk_mpi_int_ena_w1s {
	uint64_t u;
	struct bdk_mpi_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mpi_intr                    : 1;  /**< R/W1S - Enables reporting of MPI_STS[MPI_INTR]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t mpi_intr                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mpi_int_ena_w1s_s       cn88xx; */
	/* struct bdk_mpi_int_ena_w1s_s       cn88xxp1; */
} bdk_mpi_int_ena_w1s_t;

#define BDK_MPI_INT_ENA_W1S BDK_MPI_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_MPI_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_INT_ENA_W1S_FUNC(void)
{
	return 0x0000804000001038ull;
}
#define typedef_BDK_MPI_INT_ENA_W1S bdk_mpi_int_ena_w1s_t
#define bustype_BDK_MPI_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_INT_ENA_W1S 0
#define arguments_BDK_MPI_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_MPI_INT_ENA_W1S "MPI_INT_ENA_W1S"


/**
 * NCB - mpi_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the MPI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mpi_msix_pbax {
	uint64_t u;
	struct bdk_mpi_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated MPI_MSIX_VEC()_CTL, enumerated by MPI_INT_VEC_E. Bits
                                                                 that have no associated MPI_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_mpi_msix_pbax_s         cn88xx; */
	/* struct bdk_mpi_msix_pbax_s         cn88xxp1; */
} bdk_mpi_msix_pbax_t;

static inline uint64_t BDK_MPI_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000804000FF0000ull;
	csr_fatal("BDK_MPI_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MPI_MSIX_PBAX(...) bdk_mpi_msix_pbax_t
#define bustype_BDK_MPI_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_MSIX_PBAX(p1) (p1)
#define arguments_BDK_MPI_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_MPI_MSIX_PBAX(...) "MPI_MSIX_PBAX"


/**
 * NCB - mpi_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the MPI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mpi_msix_vecx_addr {
	uint64_t u;
	struct bdk_mpi_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MPI_MSIX_VEC()_ADDR, MPI_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MPI_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_MPI_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_mpi_msix_vecx_addr_s    cn88xx; */
	/* struct bdk_mpi_msix_vecx_addr_s    cn88xxp1; */
} bdk_mpi_msix_vecx_addr_t;

static inline uint64_t BDK_MPI_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000804000F00000ull;
	csr_fatal("BDK_MPI_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MPI_MSIX_VECX_ADDR(...) bdk_mpi_msix_vecx_addr_t
#define bustype_BDK_MPI_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_MPI_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_MPI_MSIX_VECX_ADDR(...) "MPI_MSIX_VECX_ADDR"


/**
 * NCB - mpi_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the MPI_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mpi_msix_vecx_ctl {
	uint64_t u;
	struct bdk_mpi_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts will be sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_mpi_msix_vecx_ctl_s     cn88xx; */
	/* struct bdk_mpi_msix_vecx_ctl_s     cn88xxp1; */
} bdk_mpi_msix_vecx_ctl_t;

static inline uint64_t BDK_MPI_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x0000804000F00008ull;
	csr_fatal("BDK_MPI_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MPI_MSIX_VECX_CTL(...) bdk_mpi_msix_vecx_ctl_t
#define bustype_BDK_MPI_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_MPI_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_MPI_MSIX_VECX_CTL(...) "MPI_MSIX_VECX_CTL"


/**
 * NCB - mpi_sts
 */
typedef union bdk_mpi_sts {
	uint64_t u;
	struct bdk_mpi_sts_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_13_63              : 51;
		uint64_t rxnum                       : 5;  /**< RO/H - Number of bytes written for the transaction. */
		uint64_t reserved_2_7                : 6;
		uint64_t mpi_intr                    : 1;  /**< R/W1C/H - MPI interrupt on transaction done. */
		uint64_t busy                        : 1;  /**< RO/H - Busy.
                                                                 0 = no MPI/SPI transaction in progress.
                                                                 1 = MPI/SPI engine is processing a transaction. */
#else
		uint64_t busy                        : 1;
		uint64_t mpi_intr                    : 1;
		uint64_t reserved_2_7                : 6;
		uint64_t rxnum                       : 5;
		uint64_t reserved_13_63              : 51;
#endif
	} s;
	/* struct bdk_mpi_sts_s               cn88xx; */
	/* struct bdk_mpi_sts_s               cn88xxp1; */
} bdk_mpi_sts_t;

#define BDK_MPI_STS BDK_MPI_STS_FUNC()
static inline uint64_t BDK_MPI_STS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_STS_FUNC(void)
{
	return 0x0000804000001008ull;
}
#define typedef_BDK_MPI_STS bdk_mpi_sts_t
#define bustype_BDK_MPI_STS BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_STS 0
#define arguments_BDK_MPI_STS -1,-1,-1,-1
#define basename_BDK_MPI_STS "MPI_STS"


/**
 * NCB - mpi_sts_w1s
 *
 * This register sets interrupt bits.
 *
 */
typedef union bdk_mpi_sts_w1s {
	uint64_t u;
	struct bdk_mpi_sts_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t mpi_intr                    : 1;  /**< R/W1S/H - Reads or sets MPI_STS[MPI_INTR]. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t mpi_intr                    : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mpi_sts_w1s_s           cn88xx; */
	/* struct bdk_mpi_sts_w1s_s           cn88xxp1; */
} bdk_mpi_sts_w1s_t;

#define BDK_MPI_STS_W1S BDK_MPI_STS_W1S_FUNC()
static inline uint64_t BDK_MPI_STS_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_STS_W1S_FUNC(void)
{
	return 0x0000804000001020ull;
}
#define typedef_BDK_MPI_STS_W1S bdk_mpi_sts_w1s_t
#define bustype_BDK_MPI_STS_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_STS_W1S 0
#define arguments_BDK_MPI_STS_W1S -1,-1,-1,-1
#define basename_BDK_MPI_STS_W1S "MPI_STS_W1S"


/**
 * NCB - mpi_tx
 */
typedef union bdk_mpi_tx {
	uint64_t u;
	struct bdk_mpi_tx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t csid                        : 2;  /**< WO - Which CS to assert for this transaction */
		uint64_t reserved_17_19              : 3;
		uint64_t leavecs                     : 1;  /**< WO - Leave SPI_CSn_L asserted.
                                                                 0 = deassert SPI_CSn_L after the transaction is done.
                                                                 1 = leave SPI_CSn_L asserted after the transaction is done. */
		uint64_t reserved_13_15              : 3;
		uint64_t txnum                       : 5;  /**< WO - Number of bytes to transmit. */
		uint64_t reserved_5_7                : 3;
		uint64_t totnum                      : 5;  /**< WO - Total number of bytes to shift (transmit and receive). */
#else
		uint64_t totnum                      : 5;
		uint64_t reserved_5_7                : 3;
		uint64_t txnum                       : 5;
		uint64_t reserved_13_15              : 3;
		uint64_t leavecs                     : 1;
		uint64_t reserved_17_19              : 3;
		uint64_t csid                        : 2;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_mpi_tx_s                cn88xx; */
	/* struct bdk_mpi_tx_s                cn88xxp1; */
} bdk_mpi_tx_t;

#define BDK_MPI_TX BDK_MPI_TX_FUNC()
static inline uint64_t BDK_MPI_TX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_TX_FUNC(void)
{
	return 0x0000804000001010ull;
}
#define typedef_BDK_MPI_TX bdk_mpi_tx_t
#define bustype_BDK_MPI_TX BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_TX 0
#define arguments_BDK_MPI_TX -1,-1,-1,-1
#define basename_BDK_MPI_TX "MPI_TX"


/**
 * NCB - mpi_wide_dat
 */
typedef union bdk_mpi_wide_dat {
	uint64_t u;
	struct bdk_mpi_wide_dat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W/H - Data to transmit/receive. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_mpi_wide_dat_s          cn88xx; */
	/* struct bdk_mpi_wide_dat_s          cn88xxp1; */
} bdk_mpi_wide_dat_t;

#define BDK_MPI_WIDE_DAT BDK_MPI_WIDE_DAT_FUNC()
static inline uint64_t BDK_MPI_WIDE_DAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MPI_WIDE_DAT_FUNC(void)
{
	return 0x0000804000001040ull;
}
#define typedef_BDK_MPI_WIDE_DAT bdk_mpi_wide_dat_t
#define bustype_BDK_MPI_WIDE_DAT BDK_CSR_TYPE_NCB
#define busnum_BDK_MPI_WIDE_DAT 0
#define arguments_BDK_MPI_WIDE_DAT -1,-1,-1,-1
#define basename_BDK_MPI_WIDE_DAT "MPI_WIDE_DAT"

#endif /* __BDK_CSRS_MPI__ */

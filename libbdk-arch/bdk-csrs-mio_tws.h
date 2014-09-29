#ifndef __BDK_CSRS_MIO_TWS__
#define __BDK_CSRS_MIO_TWS__
/* This file is auto-generated. Do not edit */

/***********************license start***************
 * Copyright (c) 2003-2014  Cavium Networks (support@cavium.com). All rights
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

 *   * Neither the name of Cavium Networks nor the names of
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
 * Cavium MIO_TWS.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration MIO_TWS_INT_VEC_E
 *
 * TWSI MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum mio_tws_int_vec_e {
	MIO_TWS_INT_VEC_E_INT_ST = 0x0,
	MIO_TWS_INT_VEC_E_ENUM_LAST = 0x1,
};



/**
 * RSL - mio_tws#_int
 *
 * This register contains the TWSI interrupt-enable mask and the interrupt-source bits.
 *
 */
typedef union bdk_mio_twsx_int {
	uint64_t u;
	struct bdk_mio_twsx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t scl                         : 1;  /**< RO/H - SCL signal. */
		uint64_t sda                         : 1;  /**< RO/H - SDA signal. */
		uint64_t scl_ovr                     : 1;  /**< R/W - SCL testing override:
                                                                 0 = Normal operation, SCL bus controlled by TWSI core.
                                                                 1 = Pull SCL low. */
		uint64_t sda_ovr                     : 1;  /**< R/W - SDA testing override:
                                                                 0 = Normal operation, SDA bus controlled by TWSI core.
                                                                 1 = Pull SDA low. */
		uint64_t reserved_3_7                : 5;
		uint64_t core_int                    : 1;  /**< RO/H - TWSI core interrupt, whenever IFLG is set. Ignored when the HLC is enabled. */
		uint64_t ts_int                      : 1;  /**< R/W1C/H - MIO_TWS()_TWSI_SW register-update interrupt. Ignored when the HLC is disabled. */
		uint64_t st_int                      : 1;  /**< R/W1C/H - MIO_TWS()_SW_TWSI register-update interrupt. Ignored when the HLC is disabled. */
#else
		uint64_t st_int                      : 1;
		uint64_t ts_int                      : 1;
		uint64_t core_int                    : 1;
		uint64_t reserved_3_7                : 5;
		uint64_t sda_ovr                     : 1;
		uint64_t scl_ovr                     : 1;
		uint64_t sda                         : 1;
		uint64_t scl                         : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_mio_twsx_int_s          cn85xx; */
	/* struct bdk_mio_twsx_int_s          cn88xx; */
	/* struct bdk_mio_twsx_int_s          cn88xxp1; */
} bdk_mio_twsx_int_t;

static inline uint64_t BDK_MIO_TWSX_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001010ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_INT(...) bdk_mio_twsx_int_t
#define bustype_BDK_MIO_TWSX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_INT(p1) (p1)
#define arguments_BDK_MIO_TWSX_INT(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_INT(...) "MIO_TWSX_INT"


/**
 * RSL - mio_tws#_int_ena_w1c
 */
typedef union bdk_mio_twsx_int_ena_w1c {
	uint64_t u;
	struct bdk_mio_twsx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t core_int                    : 1;  /**< R/W1C/H - Reads or clears MIO_TWS()_INT[CORE_INT]. */
		uint64_t ts_int                      : 1;  /**< R/W1C/H - Reads or clears MIO_TWS()_INT[TS_INT]. */
		uint64_t st_int                      : 1;  /**< R/W1C/H - Reads or clears MIO_TWS()_INT[ST_INT]. */
#else
		uint64_t st_int                      : 1;
		uint64_t ts_int                      : 1;
		uint64_t core_int                    : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_mio_twsx_int_ena_w1c_s  cn85xx; */
	/* struct bdk_mio_twsx_int_ena_w1c_s  cn88xx; */
	/* struct bdk_mio_twsx_int_ena_w1c_s  cn88xxp1; */
} bdk_mio_twsx_int_ena_w1c_t;

static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001028ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_INT_ENA_W1C(...) bdk_mio_twsx_int_ena_w1c_t
#define bustype_BDK_MIO_TWSX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_MIO_TWSX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_INT_ENA_W1C(...) "MIO_TWSX_INT_ENA_W1C"


/**
 * RSL - mio_tws#_int_ena_w1s
 */
typedef union bdk_mio_twsx_int_ena_w1s {
	uint64_t u;
	struct bdk_mio_twsx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t core_int                    : 1;  /**< R/W1S/H - Enables reporting of MIO_TWS()_INT[CORE_INT]. */
		uint64_t ts_int                      : 1;  /**< R/W1S/H - Enables reporting of MIO_TWS()_INT[TS_INT]. */
		uint64_t st_int                      : 1;  /**< R/W1S/H - Enables reporting of MIO_TWS()_INT[ST_INT]. */
#else
		uint64_t st_int                      : 1;
		uint64_t ts_int                      : 1;
		uint64_t core_int                    : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_mio_twsx_int_ena_w1s_s  cn85xx; */
	/* struct bdk_mio_twsx_int_ena_w1s_s  cn88xx; */
	/* struct bdk_mio_twsx_int_ena_w1s_s  cn88xxp1; */
} bdk_mio_twsx_int_ena_w1s_t;

static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001030ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_INT_ENA_W1S(...) bdk_mio_twsx_int_ena_w1s_t
#define bustype_BDK_MIO_TWSX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_MIO_TWSX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_INT_ENA_W1S(...) "MIO_TWSX_INT_ENA_W1S"


/**
 * RSL - mio_tws#_int_w1s
 */
typedef union bdk_mio_twsx_int_w1s {
	uint64_t u;
	struct bdk_mio_twsx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t core_int                    : 1;  /**< RO/H - Reads MIO_TWS()_INT[CORE_INT]. */
		uint64_t ts_int                      : 1;  /**< R/W1S/H - Reads or sets MIO_TWS()_INT[TS_INT]. */
		uint64_t st_int                      : 1;  /**< R/W1S/H - Reads or sets MIO_TWS()_INT[ST_INT]. */
#else
		uint64_t st_int                      : 1;
		uint64_t ts_int                      : 1;
		uint64_t core_int                    : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_mio_twsx_int_w1s_s      cn85xx; */
	/* struct bdk_mio_twsx_int_w1s_s      cn88xx; */
	/* struct bdk_mio_twsx_int_w1s_s      cn88xxp1; */
} bdk_mio_twsx_int_w1s_t;

static inline uint64_t BDK_MIO_TWSX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001020ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_INT_W1S(...) bdk_mio_twsx_int_w1s_t
#define bustype_BDK_MIO_TWSX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_INT_W1S(p1) (p1)
#define arguments_BDK_MIO_TWSX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_INT_W1S(...) "MIO_TWSX_INT_W1S"


/**
 * RSL - mio_tws#_mode
 */
typedef union bdk_mio_twsx_mode {
	uint64_t u;
	struct bdk_mio_twsx_mode_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t stretch                     : 1;  /**< R/W - Clock Stretching enable.
                                                                 When enabled and device in Master mode, it allows slave device
                                                                 to extend low period of the clock. During the clock extension period, the SCL output from
                                                                 Master device is disabled. */
		uint64_t hs_mode                     : 1;  /**< R/W - I2C bus high-speed mode.

                                                                 0 = Open drain drive on TWS_SCL. TWS_SCL clock signal high-to-low ratio is 1 to 1.
                                                                 OSCL output frequency divisor is 10.

                                                                 1 = Current source circuit is used to drive TWS_SCL pin when device is in master mode,
                                                                 but disabled after each repeated start condition
                                                                 and after each act or nack to give a slave a chance to stretch the clock.
                                                                 TWS_SCL clock signal high-to-low ratio is 1 to 2.
                                                                 OSCL output frequency divisor is 15. */
#else
		uint64_t hs_mode                     : 1;
		uint64_t stretch                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_mio_twsx_mode_s         cn85xx; */
	/* struct bdk_mio_twsx_mode_s         cn88xx; */
	/* struct bdk_mio_twsx_mode_s         cn88xxp1; */
} bdk_mio_twsx_mode_t;

static inline uint64_t BDK_MIO_TWSX_MODE(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MODE(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001038ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_MODE", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_MODE(...) bdk_mio_twsx_mode_t
#define bustype_BDK_MIO_TWSX_MODE(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_MODE(p1) (p1)
#define arguments_BDK_MIO_TWSX_MODE(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_MODE(...) "MIO_TWSX_MODE"


/**
 * RSL - mio_tws#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the MIO_TWS_INT_VEC_E
 * enumeration.
 */
typedef union bdk_mio_twsx_msix_pbax {
	uint64_t u;
	struct bdk_mio_twsx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated MIO_TWS()_MSIX_VEC()_CTL, enumerated by
                                                                 MIO_TWS_INT_VEC_E. Bits that have no associated MIO_TWS_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_mio_twsx_msix_pbax_s    cn85xx; */
	/* struct bdk_mio_twsx_msix_pbax_s    cn88xx; */
	/* struct bdk_mio_twsx_msix_pbax_s    cn88xxp1; */
} bdk_mio_twsx_msix_pbax_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 == 0)))
		return 0x000087E0D0FF0000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_MSIX_PBAX(...) bdk_mio_twsx_msix_pbax_t
#define bustype_BDK_MIO_TWSX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_MIO_TWSX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_MIO_TWSX_MSIX_PBAX(...) "MIO_TWSX_MSIX_PBAX"


/**
 * RSL - mio_tws#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the MIO_TWS_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mio_twsx_msix_vecx_addr {
	uint64_t u;
	struct bdk_mio_twsx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's MIO_TWS()_MSIX_VEC()_ADDR, MIO_TWS()_MSIX_VEC()_CTL, and corresponding
                                                                 bit of MIO_TWS()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_MIO_TWS()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_mio_twsx_msix_vecx_addr_s cn85xx; */
	/* struct bdk_mio_twsx_msix_vecx_addr_s cn88xx; */
	/* struct bdk_mio_twsx_msix_vecx_addr_s cn88xxp1; */
} bdk_mio_twsx_msix_vecx_addr_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 == 0)))
		return 0x000087E0D0F00000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_MSIX_VECX_ADDR(...) bdk_mio_twsx_msix_vecx_addr_t
#define bustype_BDK_MIO_TWSX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_MIO_TWSX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_MIO_TWSX_MSIX_VECX_ADDR(...) "MIO_TWSX_MSIX_VECX_ADDR"


/**
 * RSL - mio_tws#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the MIO_TWS_INT_VEC_E enumeration.
 *
 */
typedef union bdk_mio_twsx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_mio_twsx_msix_vecx_ctl_s {
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
	/* struct bdk_mio_twsx_msix_vecx_ctl_s cn85xx; */
	/* struct bdk_mio_twsx_msix_vecx_ctl_s cn88xx; */
	/* struct bdk_mio_twsx_msix_vecx_ctl_s cn88xxp1; */
} bdk_mio_twsx_msix_vecx_ctl_t;

static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 5)) && ((param2 == 0)))
		return 0x000087E0D0F00008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_MSIX_VECX_CTL(...) bdk_mio_twsx_msix_vecx_ctl_t
#define bustype_BDK_MIO_TWSX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_MIO_TWSX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_MIO_TWSX_MSIX_VECX_CTL(...) "MIO_TWSX_MSIX_VECX_CTL"


/**
 * RSL - mio_tws#_sw_twsi
 *
 * This register allows software to:
 * * Initiate master-mode operations with a write operation, and read the result with a
 * read operation.
 * * Load four bytes for later retrieval (slave mode) with a write operation and check validity
 * with a read operation.
 * * Launch a configuration read/write operation with a write operation and read the result with
 * a read operation.
 *
 * This register should be read or written by software, and read by the TWSI device. The TWSI
 * device can use either two-byte or five-byte read operations to reference this register.
 * The TWSI device considers this register valid when [V] = 1 and [SLONLY] = 1.
 */
typedef union bdk_mio_twsx_sw_twsi {
	uint64_t u;
	struct bdk_mio_twsx_sw_twsi_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t v                           : 1;  /**< RC/W/H - Valid bit. Set on a write operation (should always be written with a 1). Cleared when a
                                                                 TWSI master-mode operation completes, a TWSI configuration register access completes, or
                                                                 when the TWSI device reads the register if SLONLY = 1. */
		uint64_t slonly                      : 1;  /**< R/W - Slave-only mode.

                                                                 When this bit is set, no operations are initiated with a write operation. Only the D field
                                                                 is updated in this case.

                                                                 When this bit is clear, a write operation initiates either a master-mode operation or a
                                                                 TWSI configuration register access. */
		uint64_t eia                         : 1;  /**< R/W - Extended internal address. Sends an additional internal address byte (the MSB of IA is
                                                                 from MIO_TWS()_SW_TWSI_EXT[IA]). */
		uint64_t op                          : 4;  /**< R/W - Opcode field. When the register is written with SLONLY = 0, this field initiates one of
                                                                 the following read or write operations:
                                                                 0x0 = 7-bit byte master-mode operation.
                                                                 0x1 = 7-bit byte combined-read master-mode operation, 7-bit byte write-with-IA master-mode
                                                                 operation.
                                                                 0x2 = 10-bit byte master-mode operation.
                                                                 0x3 = 10-bit byte combined-read master-mode operation, 10-bit byte write-with-IA master-
                                                                 mode operation.
                                                                 0x4 = TWSI master-clock register, TWSI_CLK in TWSI Master Clock Register.
                                                                 0x6 = See EOP_IA field.
                                                                 0x8 = 7-bit 4-byte master-mode operation.
                                                                 0x9 = 7-bit 4-byte combined-read master-mode operation, 7-bit 4-byte write-with-IA master-
                                                                 mode operation.
                                                                 0xA = 10-bit 4-byte master-mode operation.
                                                                 0xB = 10-bit 4-byte combined-read master-mode operation, 10-bit 4-byte write-with-IA
                                                                 master-mode operation. */
		uint64_t r                           : 1;  /**< R/W/H - Read bit or result. If this bit is set on a CSR write when SLONLY = 0, the operation is a
                                                                 read operation (if clear, it is a write operation).
                                                                 On a CSR read, this bit returns the result indication for the most recent master-mode
                                                                 operation, 1 = success, 0 = failure. */
		uint64_t sovr                        : 1;  /**< R/W - Size override. If this bit is set, use the SIZE field to determine the master-mode
                                                                 operation size rather than what OP specifies. For operations greater than four bytes, the
                                                                 additional data is contained in MIO_TWS()_SW_TWSI_EXT[DATA]. */
		uint64_t size                        : 3;  /**< R/W - Size minus one. Specifies the size in bytes of the master-mode operation if SOVR = 1. (0 =
                                                                 1 byte, 1 = 2 bytes, ... 7 = 8 bytes). */
		uint64_t scr                         : 2;  /**< R/W - Scratch. Unused, but retain state. */
		uint64_t addr                        : 10; /**< R/W - Address field. The address of the remote device for a master-mode operation. ADDR\<9:7\> are
                                                                 only used for 10-bit addressing.

                                                                 Note that when mastering a 7-bit OP, ADDR\<6:0\> should not take any of the values 0x78,
                                                                 0x79, 0x7A nor 0x7B. (These 7-bit addresses are reserved to extend to 10-bit addressing). */
		uint64_t ia                          : 5;  /**< R/W - Internal Address. Used when launching a combined master-mode operation. The lower 3
                                                                 address bits are contained in EOP_IA. */
		uint64_t eop_ia                      : 3;  /**< R/W - Extra opcode, used when OP\<3:0\> = 0x6 and SLONLY = 0.
                                                                 0x0 = TWSI slave address register (TWSI_SLAVE_ADD).
                                                                 0x1 = TWSI data register (TWSI_DATA).
                                                                 0x2 = TWSI control register (TWSI_CTL).
                                                                 0x3 = (when R =  0) TWSI clock control register (TWSI_CLKCTL).
                                                                 0x3 = (when R = 1) TWSI status register (TWSI_STAT).
                                                                 0x4 = TWSI extended slave register (TWSI_SLAVE_ADD_EXT).
                                                                 0x7 = TWSI soft reset register (TWSI_RST).

                                                                 Also provides the lower 3 bits of internal address when launching a combined master-mode
                                                                 operation. */
		uint64_t data                        : 32; /**< R/W/H - Data field.
                                                                 Used on a write operation when:
                                                                 * Initiating a master-mode write operation (SLONLY = 0).
                                                                 * Writing a TWSI configuration register (SLONLY = 0).
                                                                 * A slave-mode write operation (SLONLY = 1).

                                                                 The read value is updated by:
                                                                 * A write operation to this register.
                                                                 * Master-mode completion (contains error code).
                                                                 * TWSI configuration-register read (contains result). */
#else
		uint64_t data                        : 32;
		uint64_t eop_ia                      : 3;
		uint64_t ia                          : 5;
		uint64_t addr                        : 10;
		uint64_t scr                         : 2;
		uint64_t size                        : 3;
		uint64_t sovr                        : 1;
		uint64_t r                           : 1;
		uint64_t op                          : 4;
		uint64_t eia                         : 1;
		uint64_t slonly                      : 1;
		uint64_t v                           : 1;
#endif
	} s;
	/* struct bdk_mio_twsx_sw_twsi_s      cn85xx; */
	/* struct bdk_mio_twsx_sw_twsi_s      cn88xx; */
	/* struct bdk_mio_twsx_sw_twsi_s      cn88xxp1; */
} bdk_mio_twsx_sw_twsi_t;

static inline uint64_t BDK_MIO_TWSX_SW_TWSI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_SW_TWSI(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001000ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_SW_TWSI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_SW_TWSI(...) bdk_mio_twsx_sw_twsi_t
#define bustype_BDK_MIO_TWSX_SW_TWSI(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_SW_TWSI(p1) (p1)
#define arguments_BDK_MIO_TWSX_SW_TWSI(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_SW_TWSI(...) "MIO_TWSX_SW_TWSI"


/**
 * RSL - mio_tws#_sw_twsi_ext
 *
 * This register contains an additional byte of internal address and four additional bytes of
 * data to be used with TWSI master-mode operations.
 *
 * The IA field is sent as the first byte of internal address when performing master-mode
 * combined-read/write-with-IA operations and MIO_TWS()_SW_TWSI[EIA] is set. The D field
 * extends the data field of MIO_TWS()_SW_TWSI for a total of 8 bytes (SOVR must be set to
 * perform operations greater than 4 bytes).
 */
typedef union bdk_mio_twsx_sw_twsi_ext {
	uint64_t u;
	struct bdk_mio_twsx_sw_twsi_ext_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t ia                          : 8;  /**< R/W - Extended internal address. Sent as the first byte of internal address when performing
                                                                 master-mode combined-read/write-with-IA operations and MIO_TWS()_SW_TWSI[EIA] is set. */
		uint64_t data                        : 32; /**< R/W/H - Extended data. Extends the data field of MIO_TWS()_SW_TWSI for a total of eight bytes
                                                                 (MIO_TWS()_SW_TWSI[SOVR] must be set to 1 to perform operations greater than four
                                                                 bytes). */
#else
		uint64_t data                        : 32;
		uint64_t ia                          : 8;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_mio_twsx_sw_twsi_ext_s  cn85xx; */
	/* struct bdk_mio_twsx_sw_twsi_ext_s  cn88xx; */
	/* struct bdk_mio_twsx_sw_twsi_ext_s  cn88xxp1; */
} bdk_mio_twsx_sw_twsi_ext_t;

static inline uint64_t BDK_MIO_TWSX_SW_TWSI_EXT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_SW_TWSI_EXT(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001018ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_SW_TWSI_EXT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_SW_TWSI_EXT(...) bdk_mio_twsx_sw_twsi_ext_t
#define bustype_BDK_MIO_TWSX_SW_TWSI_EXT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_SW_TWSI_EXT(p1) (p1)
#define arguments_BDK_MIO_TWSX_SW_TWSI_EXT(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_SW_TWSI_EXT(...) "MIO_TWSX_SW_TWSI_EXT"


/**
 * RSL - mio_tws#_twsi_sw
 *
 * This register allows the TWSI device to transfer data to software and later check that
 * software has received the information.
 *
 * This register should be read or written by the TWSI device, and read by software. The TWSI
 * device can use one-byte or four-byte payload write operations, and two-byte payload read
 * operations. The TWSI device considers this register valid when V = 1.
 */
typedef union bdk_mio_twsx_twsi_sw {
	uint64_t u;
	struct bdk_mio_twsx_twsi_sw_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t v                           : 2;  /**< RC/W/H - Valid bits. These bits are not directly writable. They are set to 11 on any write
                                                                 operation by the TWSI device. They are cleared to 00 on any read operation by software. */
		uint64_t reserved_32_61              : 30;
		uint64_t data                        : 32; /**< RO/H - Data field. Updated on a write operation by the TWSI device. */
#else
		uint64_t data                        : 32;
		uint64_t reserved_32_61              : 30;
		uint64_t v                           : 2;
#endif
	} s;
	/* struct bdk_mio_twsx_twsi_sw_s      cn85xx; */
	/* struct bdk_mio_twsx_twsi_sw_s      cn88xx; */
	/* struct bdk_mio_twsx_twsi_sw_s      cn88xxp1; */
} bdk_mio_twsx_twsi_sw_t;

static inline uint64_t BDK_MIO_TWSX_TWSI_SW(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_TWSX_TWSI_SW(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E0D0001008ull + (param1 & 7) * 0x1000000ull;
	csr_fatal("BDK_MIO_TWSX_TWSI_SW", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_MIO_TWSX_TWSI_SW(...) bdk_mio_twsx_twsi_sw_t
#define bustype_BDK_MIO_TWSX_TWSI_SW(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_TWSX_TWSI_SW(p1) (p1)
#define arguments_BDK_MIO_TWSX_TWSI_SW(p1) (p1),-1,-1,-1
#define basename_BDK_MIO_TWSX_TWSI_SW(...) "MIO_TWSX_TWSI_SW"

#endif /* __BDK_CSRS_MIO_TWS__ */

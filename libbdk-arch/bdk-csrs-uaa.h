#ifndef __BDK_CSRS_UAA__
#define __BDK_CSRS_UAA__
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
 * Cavium UAA.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration UAA_INT_VEC_E
 *
 * UART MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum uaa_int_vec_e {
	UAA_INT_VEC_E_INTS = 0x0,
	UAA_INT_VEC_E_INTS_CLEAR = 0x1,
	UAA_INT_VEC_E_ENUM_LAST = 0x2,
};



/**
 * RSL32b - uaa#_cidr0
 */
typedef union bdk_uaax_cidr0 {
	uint32_t u;
	struct bdk_uaax_cidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_cidr0_s            cn85xx; */
	/* struct bdk_uaax_cidr0_s            cn88xx; */
} bdk_uaax_cidr0_t;

static inline uint64_t BDK_UAAX_CIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_CIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FF0ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_CIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_CIDR0(...) bdk_uaax_cidr0_t
#define bustype_BDK_UAAX_CIDR0(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_CIDR0(p1) (p1)
#define arguments_BDK_UAAX_CIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_CIDR0(...) "UAAX_CIDR0"


/**
 * RSL32b - uaa#_cidr1
 */
typedef union bdk_uaax_cidr1 {
	uint32_t u;
	struct bdk_uaax_cidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_cidr1_s            cn85xx; */
	/* struct bdk_uaax_cidr1_s            cn88xx; */
} bdk_uaax_cidr1_t;

static inline uint64_t BDK_UAAX_CIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_CIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FF4ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_CIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_CIDR1(...) bdk_uaax_cidr1_t
#define bustype_BDK_UAAX_CIDR1(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_CIDR1(p1) (p1)
#define arguments_BDK_UAAX_CIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_CIDR1(...) "UAAX_CIDR1"


/**
 * RSL32b - uaa#_cidr2
 */
typedef union bdk_uaax_cidr2 {
	uint32_t u;
	struct bdk_uaax_cidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_cidr2_s            cn85xx; */
	/* struct bdk_uaax_cidr2_s            cn88xx; */
} bdk_uaax_cidr2_t;

static inline uint64_t BDK_UAAX_CIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_CIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FF8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_CIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_CIDR2(...) bdk_uaax_cidr2_t
#define bustype_BDK_UAAX_CIDR2(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_CIDR2(p1) (p1)
#define arguments_BDK_UAAX_CIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_CIDR2(...) "UAAX_CIDR2"


/**
 * RSL32b - uaa#_cidr3
 */
typedef union bdk_uaax_cidr3 {
	uint32_t u;
	struct bdk_uaax_cidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t preamble                    : 8;  /**< RO - Preamble identification value. */
#else
		uint32_t preamble                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_cidr3_s            cn85xx; */
	/* struct bdk_uaax_cidr3_s            cn88xx; */
} bdk_uaax_cidr3_t;

static inline uint64_t BDK_UAAX_CIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_CIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FFCull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_CIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_CIDR3(...) bdk_uaax_cidr3_t
#define bustype_BDK_UAAX_CIDR3(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_CIDR3(p1) (p1)
#define arguments_BDK_UAAX_CIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_CIDR3(...) "UAAX_CIDR3"


/**
 * RSL32b - uaa#_cr
 */
typedef union bdk_uaax_cr {
	uint32_t u;
	struct bdk_uaax_cr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t ctsen                       : 1;  /**< R/W - "CTS hardware flow control enable. If set, data is only transmitted when UART#_CTS_L is
                                                                 asserted (low)." */
		uint32_t rtsen                       : 1;  /**< R/W - RTS hardware flow control enable. If set, data is only requested when space in the receive FIFO. */
		uint32_t out2                        : 1;  /**< R/W - Unused. */
		uint32_t out1                        : 1;  /**< R/W - Data carrier detect. If set, drive UART#_DCD_L asserted (low). */
		uint32_t rts                         : 1;  /**< R/W - Request to send. If set, assert UART#_RTS_L. */
		uint32_t dtr                         : 1;  /**< R/W - Data terminal ready. If set, assert UART#_DTR_N. */
		uint32_t rxe                         : 1;  /**< R/W - Receive enable. If set, receive section is enabled. */
		uint32_t txe                         : 1;  /**< R/W - Transmit enable. */
		uint32_t lbe                         : 1;  /**< R/W - "Loopback enable. If set the serial output is looped into the serial input as if UART#_SIN
                                                                 was physically attached to UART#_SOUT." */
		uint32_t reserved_1_6                : 6;
		uint32_t uarten                      : 1;  /**< R/W - UART enable.
                                                                 0 = UART is disabled. If the UART is disabled in the middle of transmission or reception,
                                                                 it completes the current character.
                                                                 1 = UART enabled. */
#else
		uint32_t uarten                      : 1;
		uint32_t reserved_1_6                : 6;
		uint32_t lbe                         : 1;
		uint32_t txe                         : 1;
		uint32_t rxe                         : 1;
		uint32_t dtr                         : 1;
		uint32_t rts                         : 1;
		uint32_t out1                        : 1;
		uint32_t out2                        : 1;
		uint32_t rtsen                       : 1;
		uint32_t ctsen                       : 1;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_uaax_cr_s               cn85xx; */
	/* struct bdk_uaax_cr_s               cn88xx; */
} bdk_uaax_cr_t;

static inline uint64_t BDK_UAAX_CR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_CR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000030ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_CR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_CR(...) bdk_uaax_cr_t
#define bustype_BDK_UAAX_CR(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_CR(p1) (p1)
#define arguments_BDK_UAAX_CR(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_CR(...) "UAAX_CR"


/**
 * RSL32b - uaa#_dr
 *
 * Writing to this register pushes data to the FIFO for transmission. Reading it retrieves
 * received data from the receive FIFO.
 */
typedef union bdk_uaax_dr {
	uint32_t u;
	struct bdk_uaax_dr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_12_31              : 20;
		uint32_t oe                          : 1;  /**< RO/H - Overrun error. Set if data is received and FIFO was full. Cleared once a new character is
                                                                 written to the FIFO. */
		uint32_t be                          : 1;  /**< RO/H - Break error. Indicates received data input was held low for longer than a full-transmission time. */
		uint32_t pe                          : 1;  /**< RO/H - Parity error. Indicates the parity did not match that expected. */
		uint32_t fe                          : 1;  /**< RO/H - Framing error. Indicates that the received character did not have a stop bit. */
		uint32_t data                        : 8;  /**< R/W/H - On write operations, data to transmit. On read operations, received data. */
#else
		uint32_t data                        : 8;
		uint32_t fe                          : 1;
		uint32_t pe                          : 1;
		uint32_t be                          : 1;
		uint32_t oe                          : 1;
		uint32_t reserved_12_31              : 20;
#endif
	} s;
	/* struct bdk_uaax_dr_s               cn85xx; */
	/* struct bdk_uaax_dr_s               cn88xx; */
} bdk_uaax_dr_t;

static inline uint64_t BDK_UAAX_DR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_DR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_DR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_DR(...) bdk_uaax_dr_t
#define bustype_BDK_UAAX_DR(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_DR(p1) (p1)
#define arguments_BDK_UAAX_DR(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_DR(...) "UAAX_DR"


/**
 * RSL32b - uaa#_fbrd
 */
typedef union bdk_uaax_fbrd {
	uint32_t u;
	struct bdk_uaax_fbrd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t baud_divfrac                : 6;  /**< R/W - Fractional part of baud rate divisor. The output baud rate is equal to the coprocessor-
                                                                 clock frequency divided by sixteen times the value of the baud-rate divisor, as follows:
                                                                 baud rate = coprocessor-clock frequency / (16 * divisor).
                                                                 Note that once both divisor-latch registers are set, at least eight coprocessor-clock
                                                                 cycles should be allowed to pass before transmitting or receiving data. */
#else
		uint32_t baud_divfrac                : 6;
		uint32_t reserved_6_31               : 26;
#endif
	} s;
	/* struct bdk_uaax_fbrd_s             cn85xx; */
	/* struct bdk_uaax_fbrd_s             cn88xx; */
} bdk_uaax_fbrd_t;

static inline uint64_t BDK_UAAX_FBRD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_FBRD(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000028ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_FBRD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_FBRD(...) bdk_uaax_fbrd_t
#define bustype_BDK_UAAX_FBRD(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_FBRD(p1) (p1)
#define arguments_BDK_UAAX_FBRD(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_FBRD(...) "UAAX_FBRD"


/**
 * RSL32b - uaa#_fr
 */
typedef union bdk_uaax_fr {
	uint32_t u;
	struct bdk_uaax_fr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_9_31               : 23;
		uint32_t ri                          : 1;  /**< RO/H - Complement of Ring indicator. not supported. */
		uint32_t txfe                        : 1;  /**< RO/H - Transmit FIFO empty. */
		uint32_t rxff                        : 1;  /**< RO/H - Receive FIFO full. */
		uint32_t txff                        : 1;  /**< RO/H - Transmit FIFO full. */
		uint32_t rxfe                        : 1;  /**< RO/H - Receive FIFO empty. */
		uint32_t busy                        : 1;  /**< RO/H - UART busy transmitting data. */
		uint32_t dcd                         : 1;  /**< RO/H - Data carrier detect. */
		uint32_t dsr                         : 1;  /**< RO/H - Data set ready. */
		uint32_t cts                         : 1;  /**< RO/H - Clear to send. Complement of the UART#_CTS_L modem status input pin. */
#else
		uint32_t cts                         : 1;
		uint32_t dsr                         : 1;
		uint32_t dcd                         : 1;
		uint32_t busy                        : 1;
		uint32_t rxfe                        : 1;
		uint32_t txff                        : 1;
		uint32_t rxff                        : 1;
		uint32_t txfe                        : 1;
		uint32_t ri                          : 1;
		uint32_t reserved_9_31               : 23;
#endif
	} s;
	/* struct bdk_uaax_fr_s               cn85xx; */
	/* struct bdk_uaax_fr_s               cn88xx; */
} bdk_uaax_fr_t;

static inline uint64_t BDK_UAAX_FR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_FR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000018ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_FR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_FR(...) bdk_uaax_fr_t
#define bustype_BDK_UAAX_FR(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_FR(p1) (p1)
#define arguments_BDK_UAAX_FR(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_FR(...) "UAAX_FR"


/**
 * RSL32b - uaa#_ibrd
 */
typedef union bdk_uaax_ibrd {
	uint32_t u;
	struct bdk_uaax_ibrd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t baud_divint                 : 16; /**< R/W - Integer part of baud-rate divisor. See UAA(0..1)_FBRD. */
#else
		uint32_t baud_divint                 : 16;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_uaax_ibrd_s             cn85xx; */
	/* struct bdk_uaax_ibrd_s             cn88xx; */
} bdk_uaax_ibrd_t;

static inline uint64_t BDK_UAAX_IBRD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_IBRD(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000024ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_IBRD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_IBRD(...) bdk_uaax_ibrd_t
#define bustype_BDK_UAAX_IBRD(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_IBRD(p1) (p1)
#define arguments_BDK_UAAX_IBRD(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_IBRD(...) "UAAX_IBRD"


/**
 * RSL32b - uaa#_icr
 *
 * Read value is zero for this register, not the interrupt state.
 *
 */
typedef union bdk_uaax_icr {
	uint32_t u;
	struct bdk_uaax_icr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_11_31              : 21;
		uint32_t oeic                        : 1;  /**< R/W1C - Overrun-error interrupt clear. */
		uint32_t beic                        : 1;  /**< R/W1C - Break-error interrupt clear. */
		uint32_t peic                        : 1;  /**< R/W1C - Parity-error interrupt clear. */
		uint32_t feic                        : 1;  /**< R/W1C - Framing-error interrupt clear. */
		uint32_t rtic                        : 1;  /**< R/W1C - Receive-timeout interrupt clear. */
		uint32_t txic                        : 1;  /**< R/W1C - Transmit-interrupt clear. */
		uint32_t rxic                        : 1;  /**< R/W1C - Receive-interrupt clear. */
		uint32_t dsrmic                      : 1;  /**< R/W1C - DSR modem interrupt clear. */
		uint32_t dcdmic                      : 1;  /**< R/W1C - DCD modem interrupt clear. */
		uint32_t ctsmic                      : 1;  /**< R/W1C - CTS modem interrupt clear. */
		uint32_t rimic                       : 1;  /**< R/W1C - Ring indicator interrupt clear. Not implemented. */
#else
		uint32_t rimic                       : 1;
		uint32_t ctsmic                      : 1;
		uint32_t dcdmic                      : 1;
		uint32_t dsrmic                      : 1;
		uint32_t rxic                        : 1;
		uint32_t txic                        : 1;
		uint32_t rtic                        : 1;
		uint32_t feic                        : 1;
		uint32_t peic                        : 1;
		uint32_t beic                        : 1;
		uint32_t oeic                        : 1;
		uint32_t reserved_11_31              : 21;
#endif
	} s;
	/* struct bdk_uaax_icr_s              cn85xx; */
	/* struct bdk_uaax_icr_s              cn88xx; */
} bdk_uaax_icr_t;

static inline uint64_t BDK_UAAX_ICR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_ICR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000044ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_ICR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_ICR(...) bdk_uaax_icr_t
#define bustype_BDK_UAAX_ICR(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_ICR(p1) (p1)
#define arguments_BDK_UAAX_ICR(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_ICR(...) "UAAX_ICR"


/**
 * RSL32b - uaa#_ifls
 */
typedef union bdk_uaax_ifls {
	uint32_t u;
	struct bdk_uaax_ifls_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t rxiflsel                    : 3;  /**< R/W - Receive interrupt FIFO level select.
                                                                 0x0 = Receive FIFO becomes >= 1/8 full.
                                                                 0x1 = Receive FIFO becomes >= 1/4 full.
                                                                 0x2 = Receive FIFO becomes >= 1/2 full.
                                                                 0x3 = Receive FIFO becomes >= 3/4 full.
                                                                 0x4 = Receive FIFO becomes >= 7/8 full.
                                                                 0x5-0x7 = Reserved. */
		uint32_t txiflsel                    : 3;  /**< R/W - Transmit interrupt FIFO level select.
                                                                 0x0 = Transmit FIFO becomes <= 1/8 full.
                                                                 0x1 = Transmit FIFO becomes <= 1/4 full.
                                                                 0x2 = Transmit FIFO becomes <= 1/2 full.
                                                                 0x3 = Transmit FIFO becomes <= 3/4 full.
                                                                 0x4 = Transmit FIFO becomes <= 7/8 full.
                                                                 0x5-0x7 = Reserved. */
#else
		uint32_t txiflsel                    : 3;
		uint32_t rxiflsel                    : 3;
		uint32_t reserved_6_31               : 26;
#endif
	} s;
	/* struct bdk_uaax_ifls_s             cn85xx; */
	/* struct bdk_uaax_ifls_s             cn88xx; */
} bdk_uaax_ifls_t;

static inline uint64_t BDK_UAAX_IFLS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_IFLS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000034ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_IFLS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_IFLS(...) bdk_uaax_ifls_t
#define bustype_BDK_UAAX_IFLS(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_IFLS(p1) (p1)
#define arguments_BDK_UAAX_IFLS(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_IFLS(...) "UAAX_IFLS"


/**
 * RSL32b - uaa#_imsc
 */
typedef union bdk_uaax_imsc {
	uint32_t u;
	struct bdk_uaax_imsc_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_11_31              : 21;
		uint32_t oeim                        : 1;  /**< R/W - Overrun error interrupt mask. */
		uint32_t beim                        : 1;  /**< R/W - Break error interrupt mask. */
		uint32_t peim                        : 1;  /**< R/W - Parity error interrupt mask. */
		uint32_t feim                        : 1;  /**< R/W - Framing error interrupt mask. */
		uint32_t rtim                        : 1;  /**< R/W - Receive timeout interrupt mask. */
		uint32_t txim                        : 1;  /**< R/W - Transmit interrupt mask. */
		uint32_t rxim                        : 1;  /**< R/W - Receive interrupt mask. */
		uint32_t dsrmim                      : 1;  /**< R/W - DSR modem interrupt mask. */
		uint32_t dcdmim                      : 1;  /**< R/W - DCD modem interrupt mask. */
		uint32_t ctsmim                      : 1;  /**< R/W - CTS modem interrupt mask. */
		uint32_t rimim                       : 1;  /**< R/W - Ring indicator interrupt mask. Not implemented. */
#else
		uint32_t rimim                       : 1;
		uint32_t ctsmim                      : 1;
		uint32_t dcdmim                      : 1;
		uint32_t dsrmim                      : 1;
		uint32_t rxim                        : 1;
		uint32_t txim                        : 1;
		uint32_t rtim                        : 1;
		uint32_t feim                        : 1;
		uint32_t peim                        : 1;
		uint32_t beim                        : 1;
		uint32_t oeim                        : 1;
		uint32_t reserved_11_31              : 21;
#endif
	} s;
	/* struct bdk_uaax_imsc_s             cn85xx; */
	/* struct bdk_uaax_imsc_s             cn88xx; */
} bdk_uaax_imsc_t;

static inline uint64_t BDK_UAAX_IMSC(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_IMSC(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000038ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_IMSC", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_IMSC(...) bdk_uaax_imsc_t
#define bustype_BDK_UAAX_IMSC(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_IMSC(p1) (p1)
#define arguments_BDK_UAAX_IMSC(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_IMSC(...) "UAAX_IMSC"


/**
 * RSL32b - uaa#_lcr_h
 */
typedef union bdk_uaax_lcr_h {
	uint32_t u;
	struct bdk_uaax_lcr_h_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t sps                         : 1;  /**< R/W - Stick parity select. If set, and PEN is set, forces the parity bit to the opposite of EPS. */
		uint32_t wlen                        : 2;  /**< R/W - Word length:
                                                                 0x0 = 5 bits.
                                                                 0x1 = 6 bits.
                                                                 0x2 = 7 bits.
                                                                 0x3 = 8 bits. */
		uint32_t fen                         : 1;  /**< R/W - Enable FIFOs.
                                                                 0 = FIFOs disabled, FIFOs are single character deep.
                                                                 1 = FIFO enabled. */
		uint32_t stp2                        : 1;  /**< R/W - Two stop bits select. */
		uint32_t eps                         : 1;  /**< R/W - Even parity select. */
		uint32_t pen                         : 1;  /**< R/W - Parity enable. */
		uint32_t brk                         : 1;  /**< R/W - Send break. A low level is continually transmitted after completion of the current character. */
#else
		uint32_t brk                         : 1;
		uint32_t pen                         : 1;
		uint32_t eps                         : 1;
		uint32_t stp2                        : 1;
		uint32_t fen                         : 1;
		uint32_t wlen                        : 2;
		uint32_t sps                         : 1;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_lcr_h_s            cn85xx; */
	/* struct bdk_uaax_lcr_h_s            cn88xx; */
} bdk_uaax_lcr_h_t;

static inline uint64_t BDK_UAAX_LCR_H(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_LCR_H(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E02400002Cull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_LCR_H", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_LCR_H(...) bdk_uaax_lcr_h_t
#define bustype_BDK_UAAX_LCR_H(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_LCR_H(p1) (p1)
#define arguments_BDK_UAAX_LCR_H(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_LCR_H(...) "UAAX_LCR_H"


/**
 * RSL32b - uaa#_mis
 *
 * Indicates state of interrupts after masking.
 * INTERNAL: Note this register was not present in SBSA 2.3, but is referenced
 * by the Linux driver, so has been defined here.
 */
typedef union bdk_uaax_mis {
	uint32_t u;
	struct bdk_uaax_mis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_11_31              : 21;
		uint32_t oemis                       : 1;  /**< RO/H - Overrun-error interrupt status. */
		uint32_t bemis                       : 1;  /**< RO/H - Break-error interrupt status. */
		uint32_t pemis                       : 1;  /**< RO/H - Parity-error interrupt status. */
		uint32_t femis                       : 1;  /**< RO/H - Framing-error interrupt status. */
		uint32_t rtmis                       : 1;  /**< RO/H - Receive-timeout interrupt status. */
		uint32_t txmis                       : 1;  /**< RO/H - Transmit-interrupt status. */
		uint32_t rxmis                       : 1;  /**< RO/H - Receive-interrupt status. */
		uint32_t dsrmmis                     : 1;  /**< RO/H - DSR modem interrupt status. */
		uint32_t dcdmmis                     : 1;  /**< RO/H - DCD modem interrupt status. */
		uint32_t ctsmmis                     : 1;  /**< RO/H - CTS modem interrupt status. */
		uint32_t rimmis                      : 1;  /**< RO/H - Ring-indicator interrupt status. Not implemented. */
#else
		uint32_t rimmis                      : 1;
		uint32_t ctsmmis                     : 1;
		uint32_t dcdmmis                     : 1;
		uint32_t dsrmmis                     : 1;
		uint32_t rxmis                       : 1;
		uint32_t txmis                       : 1;
		uint32_t rtmis                       : 1;
		uint32_t femis                       : 1;
		uint32_t pemis                       : 1;
		uint32_t bemis                       : 1;
		uint32_t oemis                       : 1;
		uint32_t reserved_11_31              : 21;
#endif
	} s;
	/* struct bdk_uaax_mis_s              cn85xx; */
	/* struct bdk_uaax_mis_s              cn88xx; */
} bdk_uaax_mis_t;

static inline uint64_t BDK_UAAX_MIS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_MIS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000040ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_MIS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_MIS(...) bdk_uaax_mis_t
#define bustype_BDK_UAAX_MIS(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_MIS(p1) (p1)
#define arguments_BDK_UAAX_MIS(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_MIS(...) "UAAX_MIS"


/**
 * RSL - uaa#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the UAA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_uaax_msix_pbax {
	uint64_t u;
	struct bdk_uaax_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for each interrupt, enumerated by UAA_INT_VEC_E. Bits that have no
                                                                 associated UAA_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_uaax_msix_pbax_s        cn85xx; */
	/* struct bdk_uaax_msix_pbax_s        cn88xx; */
} bdk_uaax_msix_pbax_t;

static inline uint64_t BDK_UAAX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 == 0)))
		return 0x000087E024FF0000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_MSIX_PBAX(...) bdk_uaax_msix_pbax_t
#define bustype_BDK_UAAX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_UAAX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_UAAX_MSIX_PBAX(...) "UAAX_MSIX_PBAX"


/**
 * RSL - uaa#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the UAA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_uaax_msix_vecx_addr {
	uint64_t u;
	struct bdk_uaax_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's UAA()_MSIX_VEC()_ADDR, UAA()_MSIX_VEC()_CTL, and
                                                                 corresponding bit of UAA()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_UAA(0..1)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if [SECVEC]
                                                                 was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_uaax_msix_vecx_addr_s   cn85xx; */
	/* struct bdk_uaax_msix_vecx_addr_s   cn88xx; */
} bdk_uaax_msix_vecx_addr_t;

static inline uint64_t BDK_UAAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E024F00000ull + (param1 & 1) * 0x1000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_UAAX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_MSIX_VECX_ADDR(...) bdk_uaax_msix_vecx_addr_t
#define bustype_BDK_UAAX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_UAAX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_UAAX_MSIX_VECX_ADDR(...) "UAAX_MSIX_VECX_ADDR"


/**
 * RSL - uaa#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the UAA_INT_VEC_E enumeration.
 *
 */
typedef union bdk_uaax_msix_vecx_ctl {
	uint64_t u;
	struct bdk_uaax_msix_vecx_ctl_s {
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
	/* struct bdk_uaax_msix_vecx_ctl_s    cn85xx; */
	/* struct bdk_uaax_msix_vecx_ctl_s    cn88xx; */
} bdk_uaax_msix_vecx_ctl_t;

static inline uint64_t BDK_UAAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x000087E024F00008ull + (param1 & 1) * 0x1000000ull + (param2 & 1) * 0x10ull;
	csr_fatal("BDK_UAAX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_MSIX_VECX_CTL(...) bdk_uaax_msix_vecx_ctl_t
#define bustype_BDK_UAAX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_UAAX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_UAAX_MSIX_VECX_CTL(...) "UAAX_MSIX_VECX_CTL"


/**
 * RSL32b - uaa#_pidr0
 */
typedef union bdk_uaax_pidr0 {
	uint32_t u;
	struct bdk_uaax_pidr0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t partnum0                    : 8;  /**< RO - Part number <7:0>.  ARM-assigned PL011 compatible. */
#else
		uint32_t partnum0                    : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_pidr0_s            cn85xx; */
	/* struct bdk_uaax_pidr0_s            cn88xx; */
} bdk_uaax_pidr0_t;

static inline uint64_t BDK_UAAX_PIDR0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FE0ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR0(...) bdk_uaax_pidr0_t
#define bustype_BDK_UAAX_PIDR0(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR0(p1) (p1)
#define arguments_BDK_UAAX_PIDR0(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR0(...) "UAAX_PIDR0"


/**
 * RSL32b - uaa#_pidr1
 */
typedef union bdk_uaax_pidr1 {
	uint32_t u;
	struct bdk_uaax_pidr1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t idcode                      : 4;  /**< RO - ARM idenitification. */
		uint32_t partnum1                    : 4;  /**< RO - Part number <11:8>.  ARM-assigned PL011 compatible. */
#else
		uint32_t partnum1                    : 4;
		uint32_t idcode                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_pidr1_s            cn85xx; */
	/* struct bdk_uaax_pidr1_s            cn88xx; */
} bdk_uaax_pidr1_t;

static inline uint64_t BDK_UAAX_PIDR1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FE4ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR1(...) bdk_uaax_pidr1_t
#define bustype_BDK_UAAX_PIDR1(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR1(p1) (p1)
#define arguments_BDK_UAAX_PIDR1(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR1(...) "UAAX_PIDR1"


/**
 * RSL32b - uaa#_pidr2
 */
typedef union bdk_uaax_pidr2 {
	uint32_t u;
	struct bdk_uaax_pidr2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revision                    : 4;  /**< RO - UART architectural revision.
                                                                 0x3 = r1p5. */
		uint32_t jedec                       : 1;  /**< RO - JEDEC assigned. 0 = Legacy UART assignment. */
		uint32_t idcode                      : 3;  /**< RO - ARM-design compatible. */
#else
		uint32_t idcode                      : 3;
		uint32_t jedec                       : 1;
		uint32_t revision                    : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_pidr2_s            cn85xx; */
	/* struct bdk_uaax_pidr2_s            cn88xx; */
} bdk_uaax_pidr2_t;

static inline uint64_t BDK_UAAX_PIDR2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR2(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FE8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR2(...) bdk_uaax_pidr2_t
#define bustype_BDK_UAAX_PIDR2(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR2(p1) (p1)
#define arguments_BDK_UAAX_PIDR2(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR2(...) "UAAX_PIDR2"


/**
 * RSL32b - uaa#_pidr3
 */
typedef union bdk_uaax_pidr3 {
	uint32_t u;
	struct bdk_uaax_pidr3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t revand                      : 4;  /**< RO - Manufacturer revision number. For CNXXXX always 0x0. */
		uint32_t cust                        : 4;  /**< RO - Customer modified. 0x1 = Overall product information should be consulted for
                                                                 product, major and minor pass numbers. */
#else
		uint32_t cust                        : 4;
		uint32_t revand                      : 4;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_uaax_pidr3_s            cn85xx; */
	/* struct bdk_uaax_pidr3_s            cn88xx; */
} bdk_uaax_pidr3_t;

static inline uint64_t BDK_UAAX_PIDR3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR3(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FECull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR3(...) bdk_uaax_pidr3_t
#define bustype_BDK_UAAX_PIDR3(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR3(p1) (p1)
#define arguments_BDK_UAAX_PIDR3(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR3(...) "UAAX_PIDR3"


/**
 * RSL32b - uaa#_pidr4
 */
typedef union bdk_uaax_pidr4 {
	uint32_t u;
	struct bdk_uaax_pidr4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_uaax_pidr4_s            cn85xx; */
	/* struct bdk_uaax_pidr4_s            cn88xx; */
} bdk_uaax_pidr4_t;

static inline uint64_t BDK_UAAX_PIDR4(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR4(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FD0ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR4", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR4(...) bdk_uaax_pidr4_t
#define bustype_BDK_UAAX_PIDR4(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR4(p1) (p1)
#define arguments_BDK_UAAX_PIDR4(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR4(...) "UAAX_PIDR4"


/**
 * RSL32b - uaa#_pidr5
 */
typedef union bdk_uaax_pidr5 {
	uint32_t u;
	struct bdk_uaax_pidr5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_uaax_pidr5_s            cn85xx; */
	/* struct bdk_uaax_pidr5_s            cn88xx; */
} bdk_uaax_pidr5_t;

static inline uint64_t BDK_UAAX_PIDR5(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR5(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FD4ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR5", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR5(...) bdk_uaax_pidr5_t
#define bustype_BDK_UAAX_PIDR5(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR5(p1) (p1)
#define arguments_BDK_UAAX_PIDR5(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR5(...) "UAAX_PIDR5"


/**
 * RSL32b - uaa#_pidr6
 */
typedef union bdk_uaax_pidr6 {
	uint32_t u;
	struct bdk_uaax_pidr6_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_uaax_pidr6_s            cn85xx; */
	/* struct bdk_uaax_pidr6_s            cn88xx; */
} bdk_uaax_pidr6_t;

static inline uint64_t BDK_UAAX_PIDR6(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR6(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FD8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR6", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR6(...) bdk_uaax_pidr6_t
#define bustype_BDK_UAAX_PIDR6(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR6(p1) (p1)
#define arguments_BDK_UAAX_PIDR6(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR6(...) "UAAX_PIDR6"


/**
 * RSL32b - uaa#_pidr7
 */
typedef union bdk_uaax_pidr7 {
	uint32_t u;
	struct bdk_uaax_pidr7_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_0_31               : 32;
#else
		uint32_t reserved_0_31               : 32;
#endif
	} s;
	/* struct bdk_uaax_pidr7_s            cn85xx; */
	/* struct bdk_uaax_pidr7_s            cn88xx; */
} bdk_uaax_pidr7_t;

static inline uint64_t BDK_UAAX_PIDR7(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_PIDR7(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000FDCull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_PIDR7", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_PIDR7(...) bdk_uaax_pidr7_t
#define bustype_BDK_UAAX_PIDR7(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_PIDR7(p1) (p1)
#define arguments_BDK_UAAX_PIDR7(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_PIDR7(...) "UAAX_PIDR7"


/**
 * RSL32b - uaa#_ris
 *
 * Indicates state of interrupts before masking.
 *
 */
typedef union bdk_uaax_ris {
	uint32_t u;
	struct bdk_uaax_ris_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_11_31              : 21;
		uint32_t oeris                       : 1;  /**< RO/H - Overrun-error interrupt status. */
		uint32_t beris                       : 1;  /**< RO/H - Break-error interrupt status. */
		uint32_t peris                       : 1;  /**< RO/H - Parity-error interrupt status. */
		uint32_t feris                       : 1;  /**< RO/H - Framing-error interrupt status. */
		uint32_t rtris                       : 1;  /**< RO/H - Receive-timeout interrupt status. */
		uint32_t txris                       : 1;  /**< RO/H - Transmit-interrupt status. */
		uint32_t rxris                       : 1;  /**< RO/H - Receive-interrupt status. */
		uint32_t dsrrmis                     : 1;  /**< RO/H - DSR modem interrupt status. */
		uint32_t dcdrmis                     : 1;  /**< RO/H - DCD modem interrupt status. */
		uint32_t ctsrmis                     : 1;  /**< RO/H - CTS modem interrupt status. */
		uint32_t rirmis                      : 1;  /**< RO/H - Ring-indicator interrupt status. Not implemented. */
#else
		uint32_t rirmis                      : 1;
		uint32_t ctsrmis                     : 1;
		uint32_t dcdrmis                     : 1;
		uint32_t dsrrmis                     : 1;
		uint32_t rxris                       : 1;
		uint32_t txris                       : 1;
		uint32_t rtris                       : 1;
		uint32_t feris                       : 1;
		uint32_t peris                       : 1;
		uint32_t beris                       : 1;
		uint32_t oeris                       : 1;
		uint32_t reserved_11_31              : 21;
#endif
	} s;
	/* struct bdk_uaax_ris_s              cn85xx; */
	/* struct bdk_uaax_ris_s              cn88xx; */
} bdk_uaax_ris_t;

static inline uint64_t BDK_UAAX_RIS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_RIS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E02400003Cull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_RIS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_RIS(...) bdk_uaax_ris_t
#define bustype_BDK_UAAX_RIS(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_RIS(p1) (p1)
#define arguments_BDK_UAAX_RIS(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_RIS(...) "UAAX_RIS"


/**
 * RSL32b - uaa#_rsr_ecr
 */
typedef union bdk_uaax_rsr_ecr {
	uint32_t u;
	struct bdk_uaax_rsr_ecr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_4_31               : 28;
		uint32_t oe                          : 1;  /**< R/W1/H - Overrun error. Write of any value clears. */
		uint32_t be                          : 1;  /**< R/W1/H - Break error. Associated with the character at the top of the FIFO; only one 0 character is
                                                                 loaded. The next character is only enabled after the receive data goes to 1. Write of any
                                                                 value clears. */
		uint32_t pe                          : 1;  /**< R/W1/H - Parity error. Associated with character at top of the FIFO. Write of any value clears. */
		uint32_t fe                          : 1;  /**< R/W1/H - Framing error. Associated with character at top of the FIFO. Write of any value clears. */
#else
		uint32_t fe                          : 1;
		uint32_t pe                          : 1;
		uint32_t be                          : 1;
		uint32_t oe                          : 1;
		uint32_t reserved_4_31               : 28;
#endif
	} s;
	/* struct bdk_uaax_rsr_ecr_s          cn85xx; */
	/* struct bdk_uaax_rsr_ecr_s          cn88xx; */
} bdk_uaax_rsr_ecr_t;

static inline uint64_t BDK_UAAX_RSR_ECR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_RSR_ECR(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024000004ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_RSR_ECR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_RSR_ECR(...) bdk_uaax_rsr_ecr_t
#define bustype_BDK_UAAX_RSR_ECR(...) BDK_CSR_TYPE_RSL32b
#define busnum_BDK_UAAX_RSR_ECR(p1) (p1)
#define arguments_BDK_UAAX_RSR_ECR(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_RSR_ECR(...) "UAAX_RSR_ECR"


/**
 * RSL - uaa#_uctl_ctl
 */
typedef union bdk_uaax_uctl_ctl {
	uint64_t u;
	struct bdk_uaax_uctl_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_31_63              : 33;
		uint64_t h_clk_en                    : 1;  /**< R/W - UART controller clock enable. When set to 1, the UART controller clock is generated. This
                                                                 also enables access to UCTL registers 0x30-0xF8. */
		uint64_t h_clk_byp_sel               : 1;  /**< R/W - Select the bypass input to the UART controller clock divider.
                                                                 0 = Use the divided coprocessor clock from the H_CLKDIV divider
                                                                 1 = Use the bypass clock from the GPIO pins
                                                                 This signal is just a multiplexer-select signal; it does not enable the UART controller
                                                                 and APB
                                                                 clock. You must still set H_CLKDIV_EN separately. H_CLK_BYP_SEL select should not be
                                                                 changed unless H_CLKDIV_EN is disabled.
                                                                 The bypass clock can be selected and running even if the UART controller clock dividers
                                                                 are not running.
                                                                 INTERNAL: Generally bypass is only used for scan purposes. */
		uint64_t h_clkdiv_rst                : 1;  /**< R/W - UART controller clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
		uint64_t reserved_27_27              : 1;
		uint64_t h_clkdiv_sel                : 3;  /**< R/W - The UARTCLK and APB CLK frequency select.
                                                                 The divider values are the following:
                                                                 0x0 = Divide by 1.
                                                                 0x1 = Divide by 2.
                                                                 0x2 = Divide by 4.
                                                                 0x3 = Divide by 6.
                                                                 0x4 = Divide by 8.
                                                                 0x5 = Divide by 16.
                                                                 0x6 = Divide by 24.
                                                                 0x7 = Divide by 32.

                                                                 The max and min frequency of the UARTCLK is determined by the following:
                                                                 _ F_UARTCLK(min) >= 16 * baud_rate(max)
                                                                 _ F_UARTCLK(max) <= 16 * 65535 * baud_rate(min) */
		uint64_t reserved_5_23               : 19;
		uint64_t csclk_en                    : 1;  /**< R/W - Turns on the UCTL interface clock (coprocessor clock).
                                                                 This enables the UCTL registers starting from 0x30 via the RSL bus. */
		uint64_t reserved_2_3                : 2;
		uint64_t uaa_rst                     : 1;  /**< R/W - Software reset; resets UAA controller; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 protocols. */
		uint64_t uctl_rst                    : 1;  /**< R/W - Software reset; resets UCTL; active-high.
                                                                 Resets UCTL RSL registers 0x30-0xF8.
                                                                 Does not reset UCTL RSL registers 0x0-0x28.
                                                                 UCTL RSL registers starting from 0x30 can be accessed only after the UART controller clock
                                                                 is active and UCTL_RST is deasserted.
                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL and CIB protocols. */
#else
		uint64_t uctl_rst                    : 1;
		uint64_t uaa_rst                     : 1;
		uint64_t reserved_2_3                : 2;
		uint64_t csclk_en                    : 1;
		uint64_t reserved_5_23               : 19;
		uint64_t h_clkdiv_sel                : 3;
		uint64_t reserved_27_27              : 1;
		uint64_t h_clkdiv_rst                : 1;
		uint64_t h_clk_byp_sel               : 1;
		uint64_t h_clk_en                    : 1;
		uint64_t reserved_31_63              : 33;
#endif
	} s;
	/* struct bdk_uaax_uctl_ctl_s         cn85xx; */
	/* struct bdk_uaax_uctl_ctl_s         cn88xx; */
} bdk_uaax_uctl_ctl_t;

static inline uint64_t BDK_UAAX_UCTL_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_UCTL_CTL(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024001000ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_UCTL_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_UCTL_CTL(...) bdk_uaax_uctl_ctl_t
#define bustype_BDK_UAAX_UCTL_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_UCTL_CTL(p1) (p1)
#define arguments_BDK_UAAX_UCTL_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_UCTL_CTL(...) "UAAX_UCTL_CTL"


/**
 * RSL - uaa#_uctl_spare0
 *
 * This register is a spare register. This register can be reset by NCB reset.
 *
 */
typedef union bdk_uaax_uctl_spare0 {
	uint64_t u;
	struct bdk_uaax_uctl_spare0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_uaax_uctl_spare0_s      cn85xx; */
	/* struct bdk_uaax_uctl_spare0_s      cn88xx; */
} bdk_uaax_uctl_spare0_t;

static inline uint64_t BDK_UAAX_UCTL_SPARE0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_UCTL_SPARE0(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E024001010ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_UCTL_SPARE0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_UCTL_SPARE0(...) bdk_uaax_uctl_spare0_t
#define bustype_BDK_UAAX_UCTL_SPARE0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_UCTL_SPARE0(p1) (p1)
#define arguments_BDK_UAAX_UCTL_SPARE0(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_UCTL_SPARE0(...) "UAAX_UCTL_SPARE0"


/**
 * RSL - uaa#_uctl_spare1
 *
 * This register is a spare register. This register can be reset by NCB reset.
 *
 */
typedef union bdk_uaax_uctl_spare1 {
	uint64_t u;
	struct bdk_uaax_uctl_spare1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_0_63               : 64;
#else
		uint64_t reserved_0_63               : 64;
#endif
	} s;
	/* struct bdk_uaax_uctl_spare1_s      cn85xx; */
	/* struct bdk_uaax_uctl_spare1_s      cn88xx; */
} bdk_uaax_uctl_spare1_t;

static inline uint64_t BDK_UAAX_UCTL_SPARE1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_UAAX_UCTL_SPARE1(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E0240010F8ull + (param1 & 1) * 0x1000000ull;
	csr_fatal("BDK_UAAX_UCTL_SPARE1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_UAAX_UCTL_SPARE1(...) bdk_uaax_uctl_spare1_t
#define bustype_BDK_UAAX_UCTL_SPARE1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_UAAX_UCTL_SPARE1(p1) (p1)
#define arguments_BDK_UAAX_UCTL_SPARE1(p1) (p1),-1,-1,-1
#define basename_BDK_UAAX_UCTL_SPARE1(...) "UAAX_UCTL_SPARE1"

#endif /* __BDK_CSRS_UAA__ */

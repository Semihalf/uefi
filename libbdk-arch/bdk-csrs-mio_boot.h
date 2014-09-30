#ifndef __BDK_CSRS_MIO_BOOT__
#define __BDK_CSRS_MIO_BOOT__
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
 * Cavium MIO_BOOT.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * RSL - mio_boot_ap_jump
 */
typedef union bdk_mio_boot_ap_jump {
	uint64_t u;
	struct bdk_mio_boot_ap_jump_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t addr                        : 64; /**< SR/W - Boot address.  This register contains the address the internal boot loader
                                                                 will jump to after reset. */
#else
		uint64_t addr                        : 64;
#endif
	} s;
	/* struct bdk_mio_boot_ap_jump_s      cn85xx; */
	/* struct bdk_mio_boot_ap_jump_s      cn88xx; */
	/* struct bdk_mio_boot_ap_jump_s      cn88xxp1; */
} bdk_mio_boot_ap_jump_t;

#define BDK_MIO_BOOT_AP_JUMP BDK_MIO_BOOT_AP_JUMP_FUNC()
static inline uint64_t BDK_MIO_BOOT_AP_JUMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_BOOT_AP_JUMP_FUNC(void)
{
	return 0x000087E0000000D0ull;
}
#define typedef_BDK_MIO_BOOT_AP_JUMP bdk_mio_boot_ap_jump_t
#define bustype_BDK_MIO_BOOT_AP_JUMP BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_BOOT_AP_JUMP 0
#define arguments_BDK_MIO_BOOT_AP_JUMP -1,-1,-1,-1
#define basename_BDK_MIO_BOOT_AP_JUMP "MIO_BOOT_AP_JUMP"


/**
 * RSL - mio_boot_bist_stat
 *
 * The boot BIST status register contains the BIST status for the MIO boot memories: 0 = pass, 1
 * = fail.
 */
typedef union bdk_mio_boot_bist_stat {
	uint64_t u;
	struct bdk_mio_boot_bist_stat_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t stat                        : 9;  /**< RO/H - BIST status.
                                                                 INTERNAL:
                                                                   \<0\> = mio.mio_boot.mio_boot_fifo.mem.
                                                                   \<1\> = mio.mio_boot.mio_boot_rsp.mem.
                                                                   \<2\> = mio.mio_boot.mio_boot_dma.mem.
                                                                   \<3\> = mio.mio_nbt.mio_nbt_fifo.mem.
                                                                   \<4\> = mio.mio_emm.bufs.mem.mem.
                                                                   \<5\> = mio.mio_nbr.ncbo_crd_fif_mem0.
                                                                   \<6\> = mio.csr.csr_fifo.
                                                                   \<7\> = mio_boot_rom/mio_boot_rom1 (internal bootroms).
                                                                   \<8\> = mio.mio_rsl.mio_pcc.gpi_pcc. */
#else
		uint64_t stat                        : 9;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_mio_boot_bist_stat_s    cn85xx; */
	/* struct bdk_mio_boot_bist_stat_s    cn88xx; */
	/* struct bdk_mio_boot_bist_stat_s    cn88xxp1; */
} bdk_mio_boot_bist_stat_t;

#define BDK_MIO_BOOT_BIST_STAT BDK_MIO_BOOT_BIST_STAT_FUNC()
static inline uint64_t BDK_MIO_BOOT_BIST_STAT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_BOOT_BIST_STAT_FUNC(void)
{
	return 0x000087E0000000F8ull;
}
#define typedef_BDK_MIO_BOOT_BIST_STAT bdk_mio_boot_bist_stat_t
#define bustype_BDK_MIO_BOOT_BIST_STAT BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_BOOT_BIST_STAT 0
#define arguments_BDK_MIO_BOOT_BIST_STAT -1,-1,-1,-1
#define basename_BDK_MIO_BOOT_BIST_STAT "MIO_BOOT_BIST_STAT"


/**
 * RSL - mio_boot_pin_defs
 *
 * This register reflects the value of the BOOT_AD\<31:0\> pins, sampled when the internal reset
 * signal first deasserts following a cold reset.
 */
typedef union bdk_mio_boot_pin_defs {
	uint64_t u;
	struct bdk_mio_boot_pin_defs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_6_63               : 58;
		uint64_t smi_supply                  : 3;  /**< RO - SMI power supply setting based on VDD_SMI_SUPPLY_SELECT pin:
                                                                 0x1 = 1.8V.
                                                                 0x2 = 2.5V.
                                                                 0x8 = 3.3V.
                                                                 else Reserved. */
		uint64_t io_supply                   : 3;  /**< RO - I/O power supply setting based on VDD_IO_SUPPLY_SELECT pin:
                                                                 0x1 = 1.8V.
                                                                 0x2 = 2.5V.
                                                                 0x8 = 3.3V.
                                                                 else Reserved. */
#else
		uint64_t io_supply                   : 3;
		uint64_t smi_supply                  : 3;
		uint64_t reserved_6_63               : 58;
#endif
	} s;
	/* struct bdk_mio_boot_pin_defs_s     cn85xx; */
	/* struct bdk_mio_boot_pin_defs_s     cn88xx; */
	/* struct bdk_mio_boot_pin_defs_s     cn88xxp1; */
} bdk_mio_boot_pin_defs_t;

#define BDK_MIO_BOOT_PIN_DEFS BDK_MIO_BOOT_PIN_DEFS_FUNC()
static inline uint64_t BDK_MIO_BOOT_PIN_DEFS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_BOOT_PIN_DEFS_FUNC(void)
{
	return 0x000087E0000000C0ull;
}
#define typedef_BDK_MIO_BOOT_PIN_DEFS bdk_mio_boot_pin_defs_t
#define bustype_BDK_MIO_BOOT_PIN_DEFS BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_BOOT_PIN_DEFS 0
#define arguments_BDK_MIO_BOOT_PIN_DEFS -1,-1,-1,-1
#define basename_BDK_MIO_BOOT_PIN_DEFS "MIO_BOOT_PIN_DEFS"


/**
 * RSL - mio_boot_rom_limit
 *
 * This register contains the largest valid address in the internal bootrom.
 *
 */
typedef union bdk_mio_boot_rom_limit {
	uint64_t u;
	struct bdk_mio_boot_rom_limit_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t addr                        : 17; /**< SR/W/H - End of ROM Address.  This field specifies the first invalid address in ROM_MEM();
                                                                 access to a ROM_MEM() address at or above this address will return a fault and zeros.
                                                                 Writes to this register which attempt to set an [ADDR] greater than the previous [ADDR]
                                                                 setting are ignored.  INTERNAL: If trusted boot mode, resets to the size of the internal
                                                                 bootrom (0x4000), ROM boot instructions may then write to decrease the value. If
                                                                 non-trusted boot resets to a value read from ROM_MEM() at address MAX - 12, just
                                                                 before the CRC. */
#else
		uint64_t addr                        : 17;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_mio_boot_rom_limit_s    cn85xx; */
	/* struct bdk_mio_boot_rom_limit_s    cn88xx; */
	/* struct bdk_mio_boot_rom_limit_s    cn88xxp1; */
} bdk_mio_boot_rom_limit_t;

#define BDK_MIO_BOOT_ROM_LIMIT BDK_MIO_BOOT_ROM_LIMIT_FUNC()
static inline uint64_t BDK_MIO_BOOT_ROM_LIMIT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_BOOT_ROM_LIMIT_FUNC(void)
{
	return 0x000087E0000000D8ull;
}
#define typedef_BDK_MIO_BOOT_ROM_LIMIT bdk_mio_boot_rom_limit_t
#define bustype_BDK_MIO_BOOT_ROM_LIMIT BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_BOOT_ROM_LIMIT 0
#define arguments_BDK_MIO_BOOT_ROM_LIMIT -1,-1,-1,-1
#define basename_BDK_MIO_BOOT_ROM_LIMIT "MIO_BOOT_ROM_LIMIT"


/**
 * RSL - mio_boot_thr
 *
 * The boot-threshold register contains MIO boot-threshold values.
 *
 */
typedef union bdk_mio_boot_thr {
	uint64_t u;
	struct bdk_mio_boot_thr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t fif_cnt                     : 6;  /**< RO/H - Current NCB FIFO count. */
		uint64_t reserved_6_7                : 2;
		uint64_t fif_thr                     : 6;  /**< R/W - NCB busy threshold. Should always read 0x19 (the only legal value). */
#else
		uint64_t fif_thr                     : 6;
		uint64_t reserved_6_7                : 2;
		uint64_t fif_cnt                     : 6;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_mio_boot_thr_s          cn85xx; */
	/* struct bdk_mio_boot_thr_s          cn88xx; */
	/* struct bdk_mio_boot_thr_s          cn88xxp1; */
} bdk_mio_boot_thr_t;

#define BDK_MIO_BOOT_THR BDK_MIO_BOOT_THR_FUNC()
static inline uint64_t BDK_MIO_BOOT_THR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_MIO_BOOT_THR_FUNC(void)
{
	return 0x000087E0000000B0ull;
}
#define typedef_BDK_MIO_BOOT_THR bdk_mio_boot_thr_t
#define bustype_BDK_MIO_BOOT_THR BDK_CSR_TYPE_RSL
#define busnum_BDK_MIO_BOOT_THR 0
#define arguments_BDK_MIO_BOOT_THR -1,-1,-1,-1
#define basename_BDK_MIO_BOOT_THR "MIO_BOOT_THR"

#endif /* __BDK_CSRS_MIO_BOOT__ */

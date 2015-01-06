#ifndef __BDK_CSRS_PCCBR__
#define __BDK_CSRS_PCCBR__
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
 * Cavium PCCBR.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * PCCBR - pccbr_xxx_ari_cap_hdr
 */
typedef union bdk_pccbr_xxx_ari_cap_hdr {
	uint32_t u;
	struct bdk_pccbr_xxx_ari_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. Points to PCCBR_XXX_VSEC_CAP_HDR. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t ariid                       : 16; /**< RO - PCIE extended capability. */
#else
		uint32_t ariid                       : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccbr_xxx_ari_cap_hdr_s cn88xx; */
	/* struct bdk_pccbr_xxx_ari_cap_hdr_s cn88xxp1; */
} bdk_pccbr_xxx_ari_cap_hdr_t;

#define BDK_PCCBR_XXX_ARI_CAP_HDR BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC(void)
{
	return 0x0000000000000100ull;
}
#define typedef_BDK_PCCBR_XXX_ARI_CAP_HDR bdk_pccbr_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_ARI_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_ARI_CAP_HDR "PCCBR_XXX_ARI_CAP_HDR"


/**
 * PCCBR - pccbr_xxx_bus
 */
typedef union bdk_pccbr_xxx_bus {
	uint32_t u;
	struct bdk_pccbr_xxx_bus_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t slt                         : 8;  /**< RO - Secondary latency timer. Not applicable to PCI Express, hardwired to 0x0. */
		uint32_t subbnum                     : 8;  /**< R/W - Subordinate bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
		uint32_t sbnum                       : 8;  /**< R/W - Secondary bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
		uint32_t pbnum                       : 8;  /**< R/W - Primary bus number.
                                                                 This field is read-write only for software;
                                                                 hardware has a fixed topology where all PCCBR's are always off primary bus number
                                                                 zero, and does not use this register for configuration decoding. */
#else
		uint32_t pbnum                       : 8;
		uint32_t sbnum                       : 8;
		uint32_t subbnum                     : 8;
		uint32_t slt                         : 8;
#endif
	} s;
	/* struct bdk_pccbr_xxx_bus_s         cn88xx; */
	/* struct bdk_pccbr_xxx_bus_s         cn88xxp1; */
} bdk_pccbr_xxx_bus_t;

#define BDK_PCCBR_XXX_BUS BDK_PCCBR_XXX_BUS_FUNC()
static inline uint64_t BDK_PCCBR_XXX_BUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_BUS_FUNC(void)
{
	return 0x0000000000000018ull;
}
#define typedef_BDK_PCCBR_XXX_BUS bdk_pccbr_xxx_bus_t
#define bustype_BDK_PCCBR_XXX_BUS BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_BUS 0
#define arguments_BDK_PCCBR_XXX_BUS -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_BUS "PCCBR_XXX_BUS"


/**
 * PCCBR - pccbr_xxx_cap_ptr
 */
typedef union bdk_pccbr_xxx_cap_ptr {
	uint32_t u;
	struct bdk_pccbr_xxx_cap_ptr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cp                          : 8;  /**< RO - First capability pointer. Points to PCCBR_E_CAP_HDR. */
#else
		uint32_t cp                          : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_pccbr_xxx_cap_ptr_s     cn88xx; */
	/* struct bdk_pccbr_xxx_cap_ptr_s     cn88xxp1; */
} bdk_pccbr_xxx_cap_ptr_t;

#define BDK_PCCBR_XXX_CAP_PTR BDK_PCCBR_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CAP_PTR_FUNC(void)
{
	return 0x0000000000000034ull;
}
#define typedef_BDK_PCCBR_XXX_CAP_PTR bdk_pccbr_xxx_cap_ptr_t
#define bustype_BDK_PCCBR_XXX_CAP_PTR BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_CAP_PTR 0
#define arguments_BDK_PCCBR_XXX_CAP_PTR -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_CAP_PTR "PCCBR_XXX_CAP_PTR"


/**
 * PCCBR - pccbr_xxx_clsize
 */
typedef union bdk_pccbr_xxx_clsize {
	uint32_t u;
	struct bdk_pccbr_xxx_clsize_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bist                        : 8;  /**< RO - BIST. */
		uint32_t mfd                         : 1;  /**< RO - Multi function device. */
		uint32_t chf                         : 7;  /**< RO - Configuration header format. Hardwired to 0x1 for type 1, bridge. */
		uint32_t lt                          : 8;  /**< RO - Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
		uint32_t cls                         : 8;  /**< RO - Cache line size. Not implemented. */
#else
		uint32_t cls                         : 8;
		uint32_t lt                          : 8;
		uint32_t chf                         : 7;
		uint32_t mfd                         : 1;
		uint32_t bist                        : 8;
#endif
	} s;
	/* struct bdk_pccbr_xxx_clsize_s      cn88xx; */
	/* struct bdk_pccbr_xxx_clsize_s      cn88xxp1; */
} bdk_pccbr_xxx_clsize_t;

#define BDK_PCCBR_XXX_CLSIZE BDK_PCCBR_XXX_CLSIZE_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CLSIZE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CLSIZE_FUNC(void)
{
	return 0x000000000000000Cull;
}
#define typedef_BDK_PCCBR_XXX_CLSIZE bdk_pccbr_xxx_clsize_t
#define bustype_BDK_PCCBR_XXX_CLSIZE BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_CLSIZE 0
#define arguments_BDK_PCCBR_XXX_CLSIZE -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_CLSIZE "PCCBR_XXX_CLSIZE"


/**
 * PCCBR - pccbr_xxx_cmd
 */
typedef union bdk_pccbr_xxx_cmd {
	uint32_t u;
	struct bdk_pccbr_xxx_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_21_31              : 11;
		uint32_t cl                          : 1;  /**< RO - Capabilities list. Indicates presence of an extended capability item. */
		uint32_t reserved_3_19               : 17;
		uint32_t me                          : 1;  /**< RO - Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
		uint32_t msae                        : 1;  /**< RO - Memory space access enable. INTERNAL: NCB/RSL always decoded; have hardcoded BARs. */
		uint32_t reserved_0_0                : 1;
#else
		uint32_t reserved_0_0                : 1;
		uint32_t msae                        : 1;
		uint32_t me                          : 1;
		uint32_t reserved_3_19               : 17;
		uint32_t cl                          : 1;
		uint32_t reserved_21_31              : 11;
#endif
	} s;
	/* struct bdk_pccbr_xxx_cmd_s         cn88xx; */
	/* struct bdk_pccbr_xxx_cmd_s         cn88xxp1; */
} bdk_pccbr_xxx_cmd_t;

#define BDK_PCCBR_XXX_CMD BDK_PCCBR_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CMD_FUNC(void)
{
	return 0x0000000000000004ull;
}
#define typedef_BDK_PCCBR_XXX_CMD bdk_pccbr_xxx_cmd_t
#define bustype_BDK_PCCBR_XXX_CMD BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_CMD 0
#define arguments_BDK_PCCBR_XXX_CMD -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_CMD "PCCBR_XXX_CMD"


/**
 * PCCBR - pccbr_xxx_e_cap2
 */
typedef union bdk_pccbr_xxx_e_cap2 {
	uint32_t u;
	struct bdk_pccbr_xxx_e_cap2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t arifwd                      : 1;  /**< RO - ARI forwarding. The bridge does forwarding. */
		uint32_t reserved_0_4                : 5;
#else
		uint32_t reserved_0_4                : 5;
		uint32_t arifwd                      : 1;
		uint32_t reserved_6_31               : 26;
#endif
	} s;
	struct bdk_pccbr_xxx_e_cap2_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_6_31               : 26;
		uint32_t arifwd                      : 1;  /**< RO - ARI forwarding. The bridge does forwarding. */
		uint32_t reserved_4_0                : 5;
#else
		uint32_t reserved_4_0                : 5;
		uint32_t arifwd                      : 1;
		uint32_t reserved_6_31               : 26;
#endif
	} cn88xx;
	struct bdk_pccbr_xxx_e_cap2_cn88xx    cn88xxp1;
} bdk_pccbr_xxx_e_cap2_t;

#define BDK_PCCBR_XXX_E_CAP2 BDK_PCCBR_XXX_E_CAP2_FUNC()
static inline uint64_t BDK_PCCBR_XXX_E_CAP2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_E_CAP2_FUNC(void)
{
	return 0x0000000000000094ull;
}
#define typedef_BDK_PCCBR_XXX_E_CAP2 bdk_pccbr_xxx_e_cap2_t
#define bustype_BDK_PCCBR_XXX_E_CAP2 BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_E_CAP2 0
#define arguments_BDK_PCCBR_XXX_E_CAP2 -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_E_CAP2 "PCCBR_XXX_E_CAP2"


/**
 * PCCBR - pccbr_xxx_e_cap_hdr
 */
typedef union bdk_pccbr_xxx_e_cap_hdr {
	uint32_t u;
	struct bdk_pccbr_xxx_e_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t porttype                    : 4;  /**< RO - Indicates a root port of a PCIe root complex. */
		uint32_t pciecv                      : 4;  /**< RO - PCIe capability version. */
		uint32_t ncp                         : 8;  /**< RO - First capability pointer. No additional PCI capabilities. */
		uint32_t pcieid                      : 8;  /**< RO - PCIe capability ID. */
#else
		uint32_t pcieid                      : 8;
		uint32_t ncp                         : 8;
		uint32_t pciecv                      : 4;
		uint32_t porttype                    : 4;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_pccbr_xxx_e_cap_hdr_s   cn88xx; */
	/* struct bdk_pccbr_xxx_e_cap_hdr_s   cn88xxp1; */
} bdk_pccbr_xxx_e_cap_hdr_t;

#define BDK_PCCBR_XXX_E_CAP_HDR BDK_PCCBR_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_E_CAP_HDR_FUNC(void)
{
	return 0x0000000000000070ull;
}
#define typedef_BDK_PCCBR_XXX_E_CAP_HDR bdk_pccbr_xxx_e_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_E_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_E_CAP_HDR "PCCBR_XXX_E_CAP_HDR"


/**
 * PCCBR - pccbr_xxx_id
 */
typedef union bdk_pccbr_xxx_id {
	uint32_t u;
	struct bdk_pccbr_xxx_id_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t devid                       : 16; /**< RO - Device ID. \<15:8\> is PCC_PROD_E::GEN. \<7:0\> is PCC_DEV_IDL_E::PCCBR. */
		uint32_t vendid                      : 16; /**< RO - Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
#else
		uint32_t vendid                      : 16;
		uint32_t devid                       : 16;
#endif
	} s;
	/* struct bdk_pccbr_xxx_id_s          cn88xx; */
	/* struct bdk_pccbr_xxx_id_s          cn88xxp1; */
} bdk_pccbr_xxx_id_t;

#define BDK_PCCBR_XXX_ID BDK_PCCBR_XXX_ID_FUNC()
static inline uint64_t BDK_PCCBR_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_ID_FUNC(void)
{
	return 0x0000000000000000ull;
}
#define typedef_BDK_PCCBR_XXX_ID bdk_pccbr_xxx_id_t
#define bustype_BDK_PCCBR_XXX_ID BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_ID 0
#define arguments_BDK_PCCBR_XXX_ID -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_ID "PCCBR_XXX_ID"


/**
 * PCCBR - pccbr_xxx_rev
 */
typedef union bdk_pccbr_xxx_rev {
	uint32_t u;
	struct bdk_pccbr_xxx_rev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bcc                         : 8;  /**< RO - Base class code. */
		uint32_t sc                          : 8;  /**< RO - Subclass code. */
		uint32_t pi                          : 8;  /**< RO - Programming interface. */
		uint32_t rid                         : 8;  /**< RO/H - Revision ID. Read only version of PCCBR_XXX_VSEC_SCTL[RID]. */
#else
		uint32_t rid                         : 8;
		uint32_t pi                          : 8;
		uint32_t sc                          : 8;
		uint32_t bcc                         : 8;
#endif
	} s;
	/* struct bdk_pccbr_xxx_rev_s         cn88xx; */
	/* struct bdk_pccbr_xxx_rev_s         cn88xxp1; */
} bdk_pccbr_xxx_rev_t;

#define BDK_PCCBR_XXX_REV BDK_PCCBR_XXX_REV_FUNC()
static inline uint64_t BDK_PCCBR_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_REV_FUNC(void)
{
	return 0x0000000000000008ull;
}
#define typedef_BDK_PCCBR_XXX_REV bdk_pccbr_xxx_rev_t
#define bustype_BDK_PCCBR_XXX_REV BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_REV 0
#define arguments_BDK_PCCBR_XXX_REV -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_REV "PCCBR_XXX_REV"


/**
 * PCCBR - pccbr_xxx_vsec_cap_hdr
 */
typedef union bdk_pccbr_xxx_vsec_cap_hdr {
	uint32_t u;
	struct bdk_pccbr_xxx_vsec_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. None. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t rbareid                     : 16; /**< RO - PCIE extended capability. */
#else
		uint32_t rbareid                     : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccbr_xxx_vsec_cap_hdr_s cn88xx; */
	/* struct bdk_pccbr_xxx_vsec_cap_hdr_s cn88xxp1; */
} bdk_pccbr_xxx_vsec_cap_hdr_t;

#define BDK_PCCBR_XXX_VSEC_CAP_HDR BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC(void)
{
	return 0x0000000000000108ull;
}
#define typedef_BDK_PCCBR_XXX_VSEC_CAP_HDR bdk_pccbr_xxx_vsec_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_VSEC_CAP_HDR BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_VSEC_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_VSEC_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_VSEC_CAP_HDR "PCCBR_XXX_VSEC_CAP_HDR"


/**
 * PCCBR - pccbr_xxx_vsec_ctl
 */
typedef union bdk_pccbr_xxx_vsec_ctl {
	uint32_t u;
	struct bdk_pccbr_xxx_vsec_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t static_subbnum              : 8;  /**< RO - Static bus number. If non-zero, downstream block expects
                                                                 PCCBR_XXX_BUS[SUBBNUM] and PCCBR_XXX_BUS[SBNUM] to match this value. */
		uint32_t inst_num                    : 8;  /**< RO - Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
#else
		uint32_t inst_num                    : 8;
		uint32_t static_subbnum              : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_pccbr_xxx_vsec_ctl_s    cn88xx; */
	/* struct bdk_pccbr_xxx_vsec_ctl_s    cn88xxp1; */
} bdk_pccbr_xxx_vsec_ctl_t;

#define BDK_PCCBR_XXX_VSEC_CTL BDK_PCCBR_XXX_VSEC_CTL_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_CTL_FUNC(void)
{
	return 0x0000000000000110ull;
}
#define typedef_BDK_PCCBR_XXX_VSEC_CTL bdk_pccbr_xxx_vsec_ctl_t
#define bustype_BDK_PCCBR_XXX_VSEC_CTL BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_VSEC_CTL 0
#define arguments_BDK_PCCBR_XXX_VSEC_CTL -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_VSEC_CTL "PCCBR_XXX_VSEC_CTL"


/**
 * PCCBR - pccbr_xxx_vsec_id
 */
typedef union bdk_pccbr_xxx_vsec_id {
	uint32_t u;
	struct bdk_pccbr_xxx_vsec_id_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t len                         : 12; /**< RO - Number of bytes in the entire VSEC structure including PCCBR_XXX_VSEC_CAP_HDR. */
		uint32_t rev                         : 4;  /**< RO - Vendor-specific revision. */
		uint32_t id                          : 16; /**< RO - Vendor-specific ID. Indicates the ThunderX family bridge VSEC ID. */
#else
		uint32_t id                          : 16;
		uint32_t rev                         : 4;
		uint32_t len                         : 12;
#endif
	} s;
	/* struct bdk_pccbr_xxx_vsec_id_s     cn88xx; */
	/* struct bdk_pccbr_xxx_vsec_id_s     cn88xxp1; */
} bdk_pccbr_xxx_vsec_id_t;

#define BDK_PCCBR_XXX_VSEC_ID BDK_PCCBR_XXX_VSEC_ID_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_ID_FUNC(void)
{
	return 0x000000000000010Cull;
}
#define typedef_BDK_PCCBR_XXX_VSEC_ID bdk_pccbr_xxx_vsec_id_t
#define bustype_BDK_PCCBR_XXX_VSEC_ID BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_VSEC_ID 0
#define arguments_BDK_PCCBR_XXX_VSEC_ID -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_VSEC_ID "PCCBR_XXX_VSEC_ID"


/**
 * PCCBR - pccbr_xxx_vsec_sctl
 */
typedef union bdk_pccbr_xxx_vsec_sctl {
	uint32_t u;
	struct bdk_pccbr_xxx_vsec_sctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t rid                         : 8;  /**< SR/W - Revision ID. R/W version of the value to be presented in PCCBR_XXX_REV[RID]. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t rid                         : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_pccbr_xxx_vsec_sctl_s   cn88xx; */
	/* struct bdk_pccbr_xxx_vsec_sctl_s   cn88xxp1; */
} bdk_pccbr_xxx_vsec_sctl_t;

#define BDK_PCCBR_XXX_VSEC_SCTL BDK_PCCBR_XXX_VSEC_SCTL_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_SCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_SCTL_FUNC(void)
{
	return 0x0000000000000114ull;
}
#define typedef_BDK_PCCBR_XXX_VSEC_SCTL bdk_pccbr_xxx_vsec_sctl_t
#define bustype_BDK_PCCBR_XXX_VSEC_SCTL BDK_CSR_TYPE_PCCBR
#define busnum_BDK_PCCBR_XXX_VSEC_SCTL 0
#define arguments_BDK_PCCBR_XXX_VSEC_SCTL -1,-1,-1,-1
#define basename_BDK_PCCBR_XXX_VSEC_SCTL "PCCBR_XXX_VSEC_SCTL"

#endif /* __BDK_CSRS_PCCBR__ */

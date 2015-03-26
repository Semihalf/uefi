#ifndef __BDK_CSRS_PCCVF__
#define __BDK_CSRS_PCCVF__
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
 * Cavium PCCVF.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));




/**
 * PCCVF - pccvf_xxx_ari_cap_hdr
 *
 * This register is the header of the 8-byte PCI ARI capability structure.
 *
 */
typedef union bdk_pccvf_xxx_ari_cap_hdr {
	uint32_t u;
	struct bdk_pccvf_xxx_ari_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t ariid                       : 16; /**< RO - PCIE extended capability. */
#else
		uint32_t ariid                       : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccvf_xxx_ari_cap_hdr_s cn88xx; */
	/* struct bdk_pccvf_xxx_ari_cap_hdr_s cn88xxp1; */
} bdk_pccvf_xxx_ari_cap_hdr_t;

#define BDK_PCCVF_XXX_ARI_CAP_HDR BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC(void)
{
	return 0x0000000000000100ull;
}
#define typedef_BDK_PCCVF_XXX_ARI_CAP_HDR bdk_pccvf_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_ARI_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_ARI_CAP_HDR "PCCVF_XXX_ARI_CAP_HDR"


/**
 * PCCVF - pccvf_xxx_cap_ptr
 */
typedef union bdk_pccvf_xxx_cap_ptr {
	uint32_t u;
	struct bdk_pccvf_xxx_cap_ptr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cp                          : 8;  /**< RO - First capability pointer. Points to PCCVF_XXX_E_CAP_HDR. */
#else
		uint32_t cp                          : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_pccvf_xxx_cap_ptr_s     cn88xx; */
	/* struct bdk_pccvf_xxx_cap_ptr_s     cn88xxp1; */
} bdk_pccvf_xxx_cap_ptr_t;

#define BDK_PCCVF_XXX_CAP_PTR BDK_PCCVF_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_CAP_PTR_FUNC(void)
{
	return 0x0000000000000034ull;
}
#define typedef_BDK_PCCVF_XXX_CAP_PTR bdk_pccvf_xxx_cap_ptr_t
#define bustype_BDK_PCCVF_XXX_CAP_PTR BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_CAP_PTR 0
#define arguments_BDK_PCCVF_XXX_CAP_PTR -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_CAP_PTR "PCCVF_XXX_CAP_PTR"


/**
 * PCCVF - pccvf_xxx_cmd
 */
typedef union bdk_pccvf_xxx_cmd {
	uint32_t u;
	struct bdk_pccvf_xxx_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_21_31              : 11;
		uint32_t cl                          : 1;  /**< RO - Capabilities List. Indicates presence of an extended capability item. */
		uint32_t reserved_3_19               : 17;
		uint32_t me                          : 1;  /**< RO - Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
		uint32_t msae                        : 1;  /**< RO - Memory-space access enable. For SR-IOV VFs always zero. */
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
	/* struct bdk_pccvf_xxx_cmd_s         cn88xx; */
	/* struct bdk_pccvf_xxx_cmd_s         cn88xxp1; */
} bdk_pccvf_xxx_cmd_t;

#define BDK_PCCVF_XXX_CMD BDK_PCCVF_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCVF_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_CMD_FUNC(void)
{
	return 0x0000000000000004ull;
}
#define typedef_BDK_PCCVF_XXX_CMD bdk_pccvf_xxx_cmd_t
#define bustype_BDK_PCCVF_XXX_CMD BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_CMD 0
#define arguments_BDK_PCCVF_XXX_CMD -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_CMD "PCCVF_XXX_CMD"


/**
 * PCCVF - pccvf_xxx_e_cap_hdr
 *
 * This register is the header of the 64-byte PCIe capability header.
 *
 */
typedef union bdk_pccvf_xxx_e_cap_hdr {
	uint32_t u;
	struct bdk_pccvf_xxx_e_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t pciecv                      : 4;  /**< RO - PCIe capability version. */
		uint32_t ncp                         : 8;  /**< RO - Next capability pointer. If VF MSI-X is supported, points to
                                                                 PCCVF_XXX_MSIX_CAP_HDR (0xB0), else 0x0. */
		uint32_t pcieid                      : 8;  /**< RO - PCIe capability ID. */
#else
		uint32_t pcieid                      : 8;
		uint32_t ncp                         : 8;
		uint32_t pciecv                      : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_pccvf_xxx_e_cap_hdr_s   cn88xx; */
	/* struct bdk_pccvf_xxx_e_cap_hdr_s   cn88xxp1; */
} bdk_pccvf_xxx_e_cap_hdr_t;

#define BDK_PCCVF_XXX_E_CAP_HDR BDK_PCCVF_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_E_CAP_HDR_FUNC(void)
{
	return 0x0000000000000070ull;
}
#define typedef_BDK_PCCVF_XXX_E_CAP_HDR bdk_pccvf_xxx_e_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_E_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_E_CAP_HDR "PCCVF_XXX_E_CAP_HDR"


/**
 * PCCVF - pccvf_xxx_id
 *
 * This register is the header of the 64-byte PCI type 0 configuration structure.
 *
 */
typedef union bdk_pccvf_xxx_id {
	uint32_t u;
	struct bdk_pccvf_xxx_id_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t devid                       : 16; /**< RO - Device ID. For SR-IOV VFs always 0xFFFF. */
		uint32_t vendid                      : 16; /**< RO - Vendor ID. For SR-IOV VFs always 0xFFFF. */
#else
		uint32_t vendid                      : 16;
		uint32_t devid                       : 16;
#endif
	} s;
	/* struct bdk_pccvf_xxx_id_s          cn88xx; */
	/* struct bdk_pccvf_xxx_id_s          cn88xxp1; */
} bdk_pccvf_xxx_id_t;

#define BDK_PCCVF_XXX_ID BDK_PCCVF_XXX_ID_FUNC()
static inline uint64_t BDK_PCCVF_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_ID_FUNC(void)
{
	return 0x0000000000000000ull;
}
#define typedef_BDK_PCCVF_XXX_ID bdk_pccvf_xxx_id_t
#define bustype_BDK_PCCVF_XXX_ID BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_ID 0
#define arguments_BDK_PCCVF_XXX_ID -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_ID "PCCVF_XXX_ID"


/**
 * PCCVF - pccvf_xxx_msix_cap_hdr
 *
 * This register is the header of the 24-byte PCI MSI-X capability structure.
 *
 */
typedef union bdk_pccvf_xxx_msix_cap_hdr {
	uint32_t u;
	struct bdk_pccvf_xxx_msix_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixen                      : 1;  /**< R/W - MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
		uint32_t funm                        : 1;  /**< R/W - Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
		uint32_t reserved_27_29              : 3;
		uint32_t msixts                      : 11; /**< RO - MSI-X table size encoded as (table size - 1). INTERNAL: From PCC's MSIX_VF_VECS parameter. */
		uint32_t ncp                         : 8;  /**< RO - Next capability pointer. */
		uint32_t msixcid                     : 8;  /**< RO - MSI-X Capability ID. */
#else
		uint32_t msixcid                     : 8;
		uint32_t ncp                         : 8;
		uint32_t msixts                      : 11;
		uint32_t reserved_27_29              : 3;
		uint32_t funm                        : 1;
		uint32_t msixen                      : 1;
#endif
	} s;
	/* struct bdk_pccvf_xxx_msix_cap_hdr_s cn88xx; */
	/* struct bdk_pccvf_xxx_msix_cap_hdr_s cn88xxp1; */
} bdk_pccvf_xxx_msix_cap_hdr_t;

#define BDK_PCCVF_XXX_MSIX_CAP_HDR BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC(void)
{
	return 0x00000000000000B0ull;
}
#define typedef_BDK_PCCVF_XXX_MSIX_CAP_HDR bdk_pccvf_xxx_msix_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_MSIX_CAP_HDR BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_MSIX_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_MSIX_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_MSIX_CAP_HDR "PCCVF_XXX_MSIX_CAP_HDR"


/**
 * PCCVF - pccvf_xxx_msix_pba
 */
typedef union bdk_pccvf_xxx_msix_pba {
	uint32_t u;
	struct bdk_pccvf_xxx_msix_pba_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixpoffs                   : 29; /**< RO - MSI-X PBA offset register. Offset of the MSI-X PBA, as a number of eight-byte words from
                                                                 the base address of the BAR; e.g. 0x1E000 corresponds to a byte offset of 0xF0000. */
		uint32_t msixpbir                    : 3;  /**< RO - MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
#else
		uint32_t msixpbir                    : 3;
		uint32_t msixpoffs                   : 29;
#endif
	} s;
	/* struct bdk_pccvf_xxx_msix_pba_s    cn88xx; */
	/* struct bdk_pccvf_xxx_msix_pba_s    cn88xxp1; */
} bdk_pccvf_xxx_msix_pba_t;

#define BDK_PCCVF_XXX_MSIX_PBA BDK_PCCVF_XXX_MSIX_PBA_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_PBA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_PBA_FUNC(void)
{
	return 0x00000000000000B8ull;
}
#define typedef_BDK_PCCVF_XXX_MSIX_PBA bdk_pccvf_xxx_msix_pba_t
#define bustype_BDK_PCCVF_XXX_MSIX_PBA BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_MSIX_PBA 0
#define arguments_BDK_PCCVF_XXX_MSIX_PBA -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_MSIX_PBA "PCCVF_XXX_MSIX_PBA"


/**
 * PCCVF - pccvf_xxx_msix_table
 */
typedef union bdk_pccvf_xxx_msix_table {
	uint32_t u;
	struct bdk_pccvf_xxx_msix_table_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixtoffs                   : 29; /**< RO - MSI-X table offset register. Offset of the MSI-X table, as a number of eight-byte
                                                                 words from the base address of the BAR. */
		uint32_t msixtbir                    : 3;  /**< RO - MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
#else
		uint32_t msixtbir                    : 3;
		uint32_t msixtoffs                   : 29;
#endif
	} s;
	/* struct bdk_pccvf_xxx_msix_table_s  cn88xx; */
	/* struct bdk_pccvf_xxx_msix_table_s  cn88xxp1; */
} bdk_pccvf_xxx_msix_table_t;

#define BDK_PCCVF_XXX_MSIX_TABLE BDK_PCCVF_XXX_MSIX_TABLE_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_TABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_TABLE_FUNC(void)
{
	return 0x00000000000000B4ull;
}
#define typedef_BDK_PCCVF_XXX_MSIX_TABLE bdk_pccvf_xxx_msix_table_t
#define bustype_BDK_PCCVF_XXX_MSIX_TABLE BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_MSIX_TABLE 0
#define arguments_BDK_PCCVF_XXX_MSIX_TABLE -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_MSIX_TABLE "PCCVF_XXX_MSIX_TABLE"


/**
 * PCCVF - pccvf_xxx_rev
 */
typedef union bdk_pccvf_xxx_rev {
	uint32_t u;
	struct bdk_pccvf_xxx_rev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bcc                         : 8;  /**< RO - Base-class code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[23:16]. */
		uint32_t sc                          : 8;  /**< RO - Subclass code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[15:8]. */
		uint32_t pi                          : 8;  /**< RO - Programming interface. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[7:0]. */
		uint32_t rid                         : 8;  /**< RO/H - Revision ID. Read only version of PCCPF_XXX_VSEC_SCTL[RID]. */
#else
		uint32_t rid                         : 8;
		uint32_t pi                          : 8;
		uint32_t sc                          : 8;
		uint32_t bcc                         : 8;
#endif
	} s;
	/* struct bdk_pccvf_xxx_rev_s         cn88xx; */
	/* struct bdk_pccvf_xxx_rev_s         cn88xxp1; */
} bdk_pccvf_xxx_rev_t;

#define BDK_PCCVF_XXX_REV BDK_PCCVF_XXX_REV_FUNC()
static inline uint64_t BDK_PCCVF_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_REV_FUNC(void)
{
	return 0x0000000000000008ull;
}
#define typedef_BDK_PCCVF_XXX_REV bdk_pccvf_xxx_rev_t
#define bustype_BDK_PCCVF_XXX_REV BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_REV 0
#define arguments_BDK_PCCVF_XXX_REV -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_REV "PCCVF_XXX_REV"


/**
 * PCCVF - pccvf_xxx_subid
 */
typedef union bdk_pccvf_xxx_subid {
	uint32_t u;
	struct bdk_pccvf_xxx_subid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssid                        : 16; /**< RO - Device ID. \<15:8\> enumerated by PCC_PROD_E. \<7:0\> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF. INTERNAL: Unit from PCC's tie__vfunitid. */
		uint32_t ssvid                       : 16; /**< RO - Subsystem vendor ID. Cavium = 0x177D. */
#else
		uint32_t ssvid                       : 16;
		uint32_t ssid                        : 16;
#endif
	} s;
	/* struct bdk_pccvf_xxx_subid_s       cn88xx; */
	/* struct bdk_pccvf_xxx_subid_s       cn88xxp1; */
} bdk_pccvf_xxx_subid_t;

#define BDK_PCCVF_XXX_SUBID BDK_PCCVF_XXX_SUBID_FUNC()
static inline uint64_t BDK_PCCVF_XXX_SUBID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_SUBID_FUNC(void)
{
	return 0x000000000000002Cull;
}
#define typedef_BDK_PCCVF_XXX_SUBID bdk_pccvf_xxx_subid_t
#define bustype_BDK_PCCVF_XXX_SUBID BDK_CSR_TYPE_PCCVF
#define busnum_BDK_PCCVF_XXX_SUBID 0
#define arguments_BDK_PCCVF_XXX_SUBID -1,-1,-1,-1
#define basename_BDK_PCCVF_XXX_SUBID "PCCVF_XXX_SUBID"

#endif /* __BDK_CSRS_PCCVF__ */

#ifndef __BDK_CSRS_PCCVF_H__
#define __BDK_CSRS_PCCVF_H__
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

/**
 * Register (PCCVF) pccvf_xxx_msix_pba
 *
 * PCC VF MSI-X PBA Offset and BIR Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_msix_pba_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X PBA offset register. Offset of the MSI-X PBA, as a number of eight-byte words from
                                                                 the base address of the BAR; e.g. 0x1E000 corresponds to a byte offset of 0xF0000. */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
#else /* Word 0 - Little Endian */
        uint32_t msixpbir              : 3;  /**< [  2:  0](RO) MSI-X PBA BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 pending bit array into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
        uint32_t msixpoffs             : 29; /**< [ 31:  3](RO) MSI-X PBA offset register. Offset of the MSI-X PBA, as a number of eight-byte words from
                                                                 the base address of the BAR; e.g. 0x1E000 corresponds to a byte offset of 0xF0000. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_msix_pba_s cn; */
} bdk_pccvf_xxx_msix_pba_t;

#define BDK_PCCVF_XXX_MSIX_PBA BDK_PCCVF_XXX_MSIX_PBA_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_PBA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_PBA_FUNC(void)
{
    return 0xb8;
}

#define typedef_BDK_PCCVF_XXX_MSIX_PBA bdk_pccvf_xxx_msix_pba_t
#define bustype_BDK_PCCVF_XXX_MSIX_PBA BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_MSIX_PBA "PCCVF_XXX_MSIX_PBA"
#define busnum_BDK_PCCVF_XXX_MSIX_PBA 0
#define arguments_BDK_PCCVF_XXX_MSIX_PBA -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_e_cap_hdr
 *
 * PCC VF PCI Express Capabilities Register
 * This register is the header of the 64-byte PCIe capability header.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_e_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If VF MSI-X is supported, points to
                                                                 PCCVF_XXX_MSIX_CAP_HDR (0xB0), else 0x0. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If VF MSI-X is supported, points to
                                                                 PCCVF_XXX_MSIX_CAP_HDR (0xB0), else 0x0. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_e_cap_hdr_s cn; */
} bdk_pccvf_xxx_e_cap_hdr_t;

#define BDK_PCCVF_XXX_E_CAP_HDR BDK_PCCVF_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_E_CAP_HDR_FUNC(void)
{
    return 0x70;
}

#define typedef_BDK_PCCVF_XXX_E_CAP_HDR bdk_pccvf_xxx_e_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_E_CAP_HDR "PCCVF_XXX_E_CAP_HDR"
#define busnum_BDK_PCCVF_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_E_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_msix_cap_hdr
 *
 * PCC VF MSI-X Capability Register
 * This register is the header of the 24-byte PCI MSI-X capability structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_msix_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1). INTERNAL: From PCC's MSIX_VF_VECS parameter. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1). INTERNAL: From PCC's MSIX_VF_VECS parameter. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable. If MSI-X is enabled, MSI and INTx must be disabled. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_msix_cap_hdr_s cn; */
} bdk_pccvf_xxx_msix_cap_hdr_t;

#define BDK_PCCVF_XXX_MSIX_CAP_HDR BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_CAP_HDR_FUNC(void)
{
    return 0xb0;
}

#define typedef_BDK_PCCVF_XXX_MSIX_CAP_HDR bdk_pccvf_xxx_msix_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_MSIX_CAP_HDR BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_MSIX_CAP_HDR "PCCVF_XXX_MSIX_CAP_HDR"
#define busnum_BDK_PCCVF_XXX_MSIX_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_MSIX_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_ari_cap_hdr
 *
 * PCC VF ARI Capability Header Register
 * This register is the header of the 8-byte PCI ARI capability structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_ari_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_ari_cap_hdr_s cn; */
} bdk_pccvf_xxx_ari_cap_hdr_t;

#define BDK_PCCVF_XXX_ARI_CAP_HDR BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_ARI_CAP_HDR_FUNC(void)
{
    return 0x100;
}

#define typedef_BDK_PCCVF_XXX_ARI_CAP_HDR bdk_pccvf_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCVF_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_ARI_CAP_HDR "PCCVF_XXX_ARI_CAP_HDR"
#define busnum_BDK_PCCVF_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCVF_XXX_ARI_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_rev
 *
 * PCC VF Class Code/Revision ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_rev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base-class code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[23:16]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[15:8]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[7:0]. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCPF_XXX_VSEC_SCTL[RID]. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCPF_XXX_VSEC_SCTL[RID]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[7:0]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[15:8]. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base-class code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[23:16]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_rev_s cn; */
} bdk_pccvf_xxx_rev_t;

#define BDK_PCCVF_XXX_REV BDK_PCCVF_XXX_REV_FUNC()
static inline uint64_t BDK_PCCVF_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_REV_FUNC(void)
{
    return 8;
}

#define typedef_BDK_PCCVF_XXX_REV bdk_pccvf_xxx_rev_t
#define bustype_BDK_PCCVF_XXX_REV BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_REV "PCCVF_XXX_REV"
#define busnum_BDK_PCCVF_XXX_REV 0
#define arguments_BDK_PCCVF_XXX_REV -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_id
 *
 * PCC VF Vendor and Device Register
 * This register is the header of the 64-byte PCI type 0 configuration structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Vendor ID. For SR-IOV VFs always 0xFFFF. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. For SR-IOV VFs always 0xFFFF. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_id_s cn; */
} bdk_pccvf_xxx_id_t;

#define BDK_PCCVF_XXX_ID BDK_PCCVF_XXX_ID_FUNC()
static inline uint64_t BDK_PCCVF_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_ID_FUNC(void)
{
    return 0;
}

#define typedef_BDK_PCCVF_XXX_ID bdk_pccvf_xxx_id_t
#define bustype_BDK_PCCVF_XXX_ID BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_ID "PCCVF_XXX_ID"
#define busnum_BDK_PCCVF_XXX_ID 0
#define arguments_BDK_PCCVF_XXX_ID -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_msix_table
 *
 * PCC VF MSI-X Table Offset and BIR Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_msix_table_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Offset of the MSI-X table, as a number of eight-byte
                                                                 words from the base address of the BAR. */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
#else /* Word 0 - Little Endian */
        uint32_t msixtbir              : 3;  /**< [  2:  0](RO) MSI-X table BAR indicator register (BIR). Indicates which BAR is used to map the MSI-X
                                                                 table into memory space. As BARs are 64-bits, 0x4 indicates BAR4H/L. */
        uint32_t msixtoffs             : 29; /**< [ 31:  3](RO) MSI-X table offset register. Offset of the MSI-X table, as a number of eight-byte
                                                                 words from the base address of the BAR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_msix_table_s cn; */
} bdk_pccvf_xxx_msix_table_t;

#define BDK_PCCVF_XXX_MSIX_TABLE BDK_PCCVF_XXX_MSIX_TABLE_FUNC()
static inline uint64_t BDK_PCCVF_XXX_MSIX_TABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_MSIX_TABLE_FUNC(void)
{
    return 0xb4;
}

#define typedef_BDK_PCCVF_XXX_MSIX_TABLE bdk_pccvf_xxx_msix_table_t
#define bustype_BDK_PCCVF_XXX_MSIX_TABLE BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_MSIX_TABLE "PCCVF_XXX_MSIX_TABLE"
#define busnum_BDK_PCCVF_XXX_MSIX_TABLE 0
#define arguments_BDK_PCCVF_XXX_MSIX_TABLE -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_cmd
 *
 * PCC VF Command/Status Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities List. Indicates presence of an extended capability item. */
        uint32_t reserved_3_19         : 17;
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory-space access enable. For SR-IOV VFs always zero. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory-space access enable. For SR-IOV VFs always zero. */
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
        uint32_t reserved_3_19         : 17;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities List. Indicates presence of an extended capability item. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_cmd_s cn; */
} bdk_pccvf_xxx_cmd_t;

#define BDK_PCCVF_XXX_CMD BDK_PCCVF_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCVF_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_CMD_FUNC(void)
{
    return 4;
}

#define typedef_BDK_PCCVF_XXX_CMD bdk_pccvf_xxx_cmd_t
#define bustype_BDK_PCCVF_XXX_CMD BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_CMD "PCCVF_XXX_CMD"
#define busnum_BDK_PCCVF_XXX_CMD 0
#define arguments_BDK_PCCVF_XXX_CMD -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_subid
 *
 * PCC VF Subsystem ID/Subsystem Vendor ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_subid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Device ID. <15:8> enumerated by PCC_PROD_E. <7:0> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF. INTERNAL: Unit from PCC's tie__vfunitid. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Cavium = 0x177D. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Cavium = 0x177D. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Device ID. <15:8> enumerated by PCC_PROD_E. <7:0> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF. INTERNAL: Unit from PCC's tie__vfunitid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_subid_s cn; */
} bdk_pccvf_xxx_subid_t;

#define BDK_PCCVF_XXX_SUBID BDK_PCCVF_XXX_SUBID_FUNC()
static inline uint64_t BDK_PCCVF_XXX_SUBID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_SUBID_FUNC(void)
{
    return 0x2c;
}

#define typedef_BDK_PCCVF_XXX_SUBID bdk_pccvf_xxx_subid_t
#define bustype_BDK_PCCVF_XXX_SUBID BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_SUBID "PCCVF_XXX_SUBID"
#define busnum_BDK_PCCVF_XXX_SUBID 0
#define arguments_BDK_PCCVF_XXX_SUBID -1,-1,-1,-1

/**
 * Register (PCCVF) pccvf_xxx_cap_ptr
 *
 * PCC VF Capability Pointer Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccvf_xxx_cap_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCVF_XXX_E_CAP_HDR. */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCVF_XXX_E_CAP_HDR. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccvf_xxx_cap_ptr_s cn; */
} bdk_pccvf_xxx_cap_ptr_t;

#define BDK_PCCVF_XXX_CAP_PTR BDK_PCCVF_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCVF_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCVF_XXX_CAP_PTR_FUNC(void)
{
    return 0x34;
}

#define typedef_BDK_PCCVF_XXX_CAP_PTR bdk_pccvf_xxx_cap_ptr_t
#define bustype_BDK_PCCVF_XXX_CAP_PTR BDK_CSR_TYPE_PCCVF
#define basename_BDK_PCCVF_XXX_CAP_PTR "PCCVF_XXX_CAP_PTR"
#define busnum_BDK_PCCVF_XXX_CAP_PTR 0
#define arguments_BDK_PCCVF_XXX_CAP_PTR -1,-1,-1,-1

#endif /* __BDK_CSRS_PCCVF_H__ */

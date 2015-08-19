#ifndef __BDK_CSRS_PCCBR_H__
#define __BDK_CSRS_PCCBR_H__
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

/**
 * Register (PCCBR) pccbr_xxx_ari_cap_hdr
 *
 * PCC Bridge ARI Capability Header Register
 * This register is the header of the 8-byte PCI ARI capability structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_ari_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to PCCBR_XXX_VSEC_CAP_HDR. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to PCCBR_XXX_VSEC_CAP_HDR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_ari_cap_hdr_s cn; */
} bdk_pccbr_xxx_ari_cap_hdr_t;

#define BDK_PCCBR_XXX_ARI_CAP_HDR BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_ARI_CAP_HDR_FUNC(void)
{
    return 0x100;
}

#define typedef_BDK_PCCBR_XXX_ARI_CAP_HDR bdk_pccbr_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_ARI_CAP_HDR "PCCBR_XXX_ARI_CAP_HDR"
#define busnum_BDK_PCCBR_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_ARI_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_bus
 *
 * PCC Bridge Bus Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_bus_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t slt                   : 8;  /**< [ 31: 24](RO) Secondary latency timer. Not applicable to PCI Express, hardwired to 0x0. */
        uint32_t subbnum               : 8;  /**< [ 23: 16](R/W) Subordinate bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
        uint32_t sbnum                 : 8;  /**< [ 15:  8](R/W) Secondary bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
        uint32_t pbnum                 : 8;  /**< [  7:  0](R/W) Primary bus number.
                                                                 This field is read-write only for software;
                                                                 hardware has a fixed topology where all PCCBR's are always off primary bus number
                                                                 zero, and does not use this register for configuration decoding. */
#else /* Word 0 - Little Endian */
        uint32_t pbnum                 : 8;  /**< [  7:  0](R/W) Primary bus number.
                                                                 This field is read-write only for software;
                                                                 hardware has a fixed topology where all PCCBR's are always off primary bus number
                                                                 zero, and does not use this register for configuration decoding. */
        uint32_t sbnum                 : 8;  /**< [ 15:  8](R/W) Secondary bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
        uint32_t subbnum               : 8;  /**< [ 23: 16](R/W) Subordinate bus number. Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].
                                                                 If 0x0 no configuration accesses are forwarded to the secondary bus.

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] = 0, this field is read-write only for software;
                                                                 hardware has a fixed topology below this bridge and will always act as if this field is
                                                                 programmed to the value in PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM].

                                                                 If PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM] != 0, which is true only for PCCBR_PCIEP, this field
                                                                 operates as specified by PCIe to direct which configuration transactions are presented to
                                                                 downstream busses. */
        uint32_t slt                   : 8;  /**< [ 31: 24](RO) Secondary latency timer. Not applicable to PCI Express, hardwired to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_bus_s cn; */
} bdk_pccbr_xxx_bus_t;

#define BDK_PCCBR_XXX_BUS BDK_PCCBR_XXX_BUS_FUNC()
static inline uint64_t BDK_PCCBR_XXX_BUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_BUS_FUNC(void)
{
    return 0x18;
}

#define typedef_BDK_PCCBR_XXX_BUS bdk_pccbr_xxx_bus_t
#define bustype_BDK_PCCBR_XXX_BUS BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_BUS "PCCBR_XXX_BUS"
#define busnum_BDK_PCCBR_XXX_BUS 0
#define arguments_BDK_PCCBR_XXX_BUS -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_cap_ptr
 *
 * PCC Bridge Capability Pointer Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_cap_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCBR_XXX_E_CAP_HDR. */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCBR_XXX_E_CAP_HDR. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_cap_ptr_s cn; */
} bdk_pccbr_xxx_cap_ptr_t;

#define BDK_PCCBR_XXX_CAP_PTR BDK_PCCBR_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CAP_PTR_FUNC(void)
{
    return 0x34;
}

#define typedef_BDK_PCCBR_XXX_CAP_PTR bdk_pccbr_xxx_cap_ptr_t
#define bustype_BDK_PCCBR_XXX_CAP_PTR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_CAP_PTR "PCCBR_XXX_CAP_PTR"
#define busnum_BDK_PCCBR_XXX_CAP_PTR 0
#define arguments_BDK_PCCBR_XXX_CAP_PTR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_clsize
 *
 * PCC Bridge Cache Line Size Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_clsize_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) BIST. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Multi function device. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x1 for type 1, bridge. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Cache line size. Not implemented. */
#else /* Word 0 - Little Endian */
        uint32_t cls                   : 8;  /**< [  7:  0](RO) Cache line size. Not implemented. */
        uint32_t lt                    : 8;  /**< [ 15:  8](RO) Master latency timer. Not applicable for PCI Express, hardwired to 0x0. */
        uint32_t chf                   : 7;  /**< [ 22: 16](RO) Configuration header format. Hardwired to 0x1 for type 1, bridge. */
        uint32_t mfd                   : 1;  /**< [ 23: 23](RO) Multi function device. */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) BIST. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_clsize_s cn; */
} bdk_pccbr_xxx_clsize_t;

#define BDK_PCCBR_XXX_CLSIZE BDK_PCCBR_XXX_CLSIZE_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CLSIZE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CLSIZE_FUNC(void)
{
    return 0xc;
}

#define typedef_BDK_PCCBR_XXX_CLSIZE bdk_pccbr_xxx_clsize_t
#define bustype_BDK_PCCBR_XXX_CLSIZE BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_CLSIZE "PCCBR_XXX_CLSIZE"
#define busnum_BDK_PCCBR_XXX_CLSIZE 0
#define arguments_BDK_PCCBR_XXX_CLSIZE -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_cmd
 *
 * PCC Bridge Command/Status Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. */
        uint32_t reserved_3_19         : 17;
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable. INTERNAL: NCB/RSL always decoded; have hardcoded BARs. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable. INTERNAL: NCB/RSL always decoded; have hardcoded BARs. */
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable. INTERNAL: For simplicity always one; we do not disable NCB transactions. */
        uint32_t reserved_3_19         : 17;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_cmd_s cn; */
} bdk_pccbr_xxx_cmd_t;

#define BDK_PCCBR_XXX_CMD BDK_PCCBR_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCBR_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_CMD_FUNC(void)
{
    return 4;
}

#define typedef_BDK_PCCBR_XXX_CMD bdk_pccbr_xxx_cmd_t
#define bustype_BDK_PCCBR_XXX_CMD BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_CMD "PCCBR_XXX_CMD"
#define busnum_BDK_PCCBR_XXX_CMD 0
#define arguments_BDK_PCCBR_XXX_CMD -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_e_cap2
 *
 * PCC Bridge PCI Express Capabilities 2 Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_e_cap2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t arifwd                : 1;  /**< [  5:  5](RO) ARI forwarding. The bridge does forwarding. */
        uint32_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_4          : 5;
        uint32_t arifwd                : 1;  /**< [  5:  5](RO) ARI forwarding. The bridge does forwarding. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_e_cap2_s cn; */
} bdk_pccbr_xxx_e_cap2_t;

#define BDK_PCCBR_XXX_E_CAP2 BDK_PCCBR_XXX_E_CAP2_FUNC()
static inline uint64_t BDK_PCCBR_XXX_E_CAP2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_E_CAP2_FUNC(void)
{
    return 0x94;
}

#define typedef_BDK_PCCBR_XXX_E_CAP2 bdk_pccbr_xxx_e_cap2_t
#define bustype_BDK_PCCBR_XXX_E_CAP2 BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_E_CAP2 "PCCBR_XXX_E_CAP2"
#define busnum_BDK_PCCBR_XXX_E_CAP2 0
#define arguments_BDK_PCCBR_XXX_E_CAP2 -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_e_cap_hdr
 *
 * PCC Bridge PCI Express Capabilities Register
 * This register is the header of the 64-byte PCIe capability header.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_e_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to PCCBR_XXX_EA_CAP_HDR. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to PCCBR_XXX_EA_CAP_HDR. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_e_cap_hdr_s cn83xx; */
    struct bdk_pccbr_xxx_e_cap_hdr_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to PCCBR_XXX_EA_CAP_HDR.
                                                                 Changed in pass 2. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. Points to PCCBR_XXX_EA_CAP_HDR.
                                                                 Changed in pass 2. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } cn88xxp2;
    struct bdk_pccbr_xxx_e_cap_hdr_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. No additional PCI capabilities. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. No additional PCI capabilities. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t porttype              : 4;  /**< [ 23: 20](RO) Indicates a root port of a PCIe root complex. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } cn88xxp1;
} bdk_pccbr_xxx_e_cap_hdr_t;

#define BDK_PCCBR_XXX_E_CAP_HDR BDK_PCCBR_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_E_CAP_HDR_FUNC(void)
{
    return 0x70;
}

#define typedef_BDK_PCCBR_XXX_E_CAP_HDR bdk_pccbr_xxx_e_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_E_CAP_HDR "PCCBR_XXX_E_CAP_HDR"
#define busnum_BDK_PCCBR_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_E_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_ea_br
 *
 * PCC Bridge PCI Enhanced Allocation Bridge Register
 * Added in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_ea_br_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t fixed_subbnum         : 8;  /**< [ 15:  8](RO) PCI bus segment to which the subordinate interface is connected.
                                                                 Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM]. */
        uint32_t fixed_sbnum           : 8;  /**< [  7:  0](RO) PCI bus segment to which the secondary interface is connected.
                                                                 Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM]. */
#else /* Word 0 - Little Endian */
        uint32_t fixed_sbnum           : 8;  /**< [  7:  0](RO) PCI bus segment to which the secondary interface is connected.
                                                                 Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM]. */
        uint32_t fixed_subbnum         : 8;  /**< [ 15:  8](RO) PCI bus segment to which the subordinate interface is connected.
                                                                 Resets to PCCBR_XXX_VSEC_CTL[STATIC_SUBBNUM]. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_ea_br_s cn; */
} bdk_pccbr_xxx_ea_br_t;

#define BDK_PCCBR_XXX_EA_BR BDK_PCCBR_XXX_EA_BR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_EA_BR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_EA_BR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0xb4;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0xb4;
    __bdk_csr_fatal("PCCBR_XXX_EA_BR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCBR_XXX_EA_BR bdk_pccbr_xxx_ea_br_t
#define bustype_BDK_PCCBR_XXX_EA_BR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_EA_BR "PCCBR_XXX_EA_BR"
#define busnum_BDK_PCCBR_XXX_EA_BR 0
#define arguments_BDK_PCCBR_XXX_EA_BR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_ea_cap_hdr
 *
 * PCC Bridge PCI Enhanced Allocation Capabilities Register
 * This register is the header of the 8-byte PCI enhanced allocation capability
 * structure for type 1 bridges.
 * Added in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_ea_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t num_entries           : 6;  /**< [ 21: 16](RO) Number of enhanced entries. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. No additional PCI capabilities. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) Enhanced allocation capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) Enhanced allocation capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. No additional PCI capabilities. */
        uint32_t num_entries           : 6;  /**< [ 21: 16](RO) Number of enhanced entries. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_ea_cap_hdr_s cn; */
} bdk_pccbr_xxx_ea_cap_hdr_t;

#define BDK_PCCBR_XXX_EA_CAP_HDR BDK_PCCBR_XXX_EA_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_EA_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_EA_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0xb0;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0xb0;
    __bdk_csr_fatal("PCCBR_XXX_EA_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCBR_XXX_EA_CAP_HDR bdk_pccbr_xxx_ea_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_EA_CAP_HDR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_EA_CAP_HDR "PCCBR_XXX_EA_CAP_HDR"
#define busnum_BDK_PCCBR_XXX_EA_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_EA_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_id
 *
 * PCC Bridge Vendor and Device ID Register
 * This register is the header of the 64-byte PCI type 1 configuration structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. <15:8> is PCC_PROD_E::GEN. <7:0> is PCC_DEV_IDL_E::PCCBR. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. <15:8> is PCC_PROD_E::GEN. <7:0> is PCC_DEV_IDL_E::PCCBR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_id_s cn; */
} bdk_pccbr_xxx_id_t;

#define BDK_PCCBR_XXX_ID BDK_PCCBR_XXX_ID_FUNC()
static inline uint64_t BDK_PCCBR_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_ID_FUNC(void)
{
    return 0;
}

#define typedef_BDK_PCCBR_XXX_ID bdk_pccbr_xxx_id_t
#define bustype_BDK_PCCBR_XXX_ID BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_ID "PCCBR_XXX_ID"
#define busnum_BDK_PCCBR_XXX_ID 0
#define arguments_BDK_PCCBR_XXX_ID -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_rev
 *
 * PCC Bridge Class Code/Revision ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_rev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCBR_XXX_VSEC_SCTL[RID]. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCBR_XXX_VSEC_SCTL[RID]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_rev_s cn; */
} bdk_pccbr_xxx_rev_t;

#define BDK_PCCBR_XXX_REV BDK_PCCBR_XXX_REV_FUNC()
static inline uint64_t BDK_PCCBR_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_REV_FUNC(void)
{
    return 8;
}

#define typedef_BDK_PCCBR_XXX_REV bdk_pccbr_xxx_rev_t
#define bustype_BDK_PCCBR_XXX_REV BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_REV "PCCBR_XXX_REV"
#define busnum_BDK_PCCBR_XXX_REV 0
#define arguments_BDK_PCCBR_XXX_REV -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_vsec_cap_hdr
 *
 * PCC Bridge Vendor-Specific Capability Header Register
 * This register is the header of the 16-byte Cavium ThunderX family bridge capability
 * structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_vsec_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. None. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t rbareid               : 16; /**< [ 15:  0](RO) PCIE extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t rbareid               : 16; /**< [ 15:  0](RO) PCIE extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. None. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_vsec_cap_hdr_s cn; */
} bdk_pccbr_xxx_vsec_cap_hdr_t;

#define BDK_PCCBR_XXX_VSEC_CAP_HDR BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_CAP_HDR_FUNC(void)
{
    return 0x108;
}

#define typedef_BDK_PCCBR_XXX_VSEC_CAP_HDR bdk_pccbr_xxx_vsec_cap_hdr_t
#define bustype_BDK_PCCBR_XXX_VSEC_CAP_HDR BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_VSEC_CAP_HDR "PCCBR_XXX_VSEC_CAP_HDR"
#define busnum_BDK_PCCBR_XXX_VSEC_CAP_HDR 0
#define arguments_BDK_PCCBR_XXX_VSEC_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_vsec_ctl
 *
 * PCC Bridge Vendor-Specific Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_vsec_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t static_subbnum        : 8;  /**< [ 15:  8](RO) Static bus number. If non-zero, downstream block expects
                                                                 PCCBR_XXX_BUS[SUBBNUM] and PCCBR_XXX_BUS[SBNUM] to match this value. */
        uint32_t inst_num              : 8;  /**< [  7:  0](RO) Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
#else /* Word 0 - Little Endian */
        uint32_t inst_num              : 8;  /**< [  7:  0](RO) Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
        uint32_t static_subbnum        : 8;  /**< [ 15:  8](RO) Static bus number. If non-zero, downstream block expects
                                                                 PCCBR_XXX_BUS[SUBBNUM] and PCCBR_XXX_BUS[SBNUM] to match this value. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_vsec_ctl_s cn; */
} bdk_pccbr_xxx_vsec_ctl_t;

#define BDK_PCCBR_XXX_VSEC_CTL BDK_PCCBR_XXX_VSEC_CTL_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_CTL_FUNC(void)
{
    return 0x110;
}

#define typedef_BDK_PCCBR_XXX_VSEC_CTL bdk_pccbr_xxx_vsec_ctl_t
#define bustype_BDK_PCCBR_XXX_VSEC_CTL BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_VSEC_CTL "PCCBR_XXX_VSEC_CTL"
#define busnum_BDK_PCCBR_XXX_VSEC_CTL 0
#define arguments_BDK_PCCBR_XXX_VSEC_CTL -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_vsec_id
 *
 * PCC Bridge Vendor-Specific Identification Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_vsec_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t len                   : 12; /**< [ 31: 20](RO) Number of bytes in the entire VSEC structure including PCCBR_XXX_VSEC_CAP_HDR.

                                                                 INTERNAL: Matches PCCPF_XXX_VSEC_ID[LEN], so extra bytes allocated and unused at the end
                                                                 of the structure. */
        uint32_t rev                   : 4;  /**< [ 19: 16](RO) Vendor-specific revision. */
        uint32_t id                    : 16; /**< [ 15:  0](RO) Vendor-specific ID. Indicates the ThunderX family bridge VSEC ID. */
#else /* Word 0 - Little Endian */
        uint32_t id                    : 16; /**< [ 15:  0](RO) Vendor-specific ID. Indicates the ThunderX family bridge VSEC ID. */
        uint32_t rev                   : 4;  /**< [ 19: 16](RO) Vendor-specific revision. */
        uint32_t len                   : 12; /**< [ 31: 20](RO) Number of bytes in the entire VSEC structure including PCCBR_XXX_VSEC_CAP_HDR.

                                                                 INTERNAL: Matches PCCPF_XXX_VSEC_ID[LEN], so extra bytes allocated and unused at the end
                                                                 of the structure. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_vsec_id_s cn; */
} bdk_pccbr_xxx_vsec_id_t;

#define BDK_PCCBR_XXX_VSEC_ID BDK_PCCBR_XXX_VSEC_ID_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_ID_FUNC(void)
{
    return 0x10c;
}

#define typedef_BDK_PCCBR_XXX_VSEC_ID bdk_pccbr_xxx_vsec_id_t
#define bustype_BDK_PCCBR_XXX_VSEC_ID BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_VSEC_ID "PCCBR_XXX_VSEC_ID"
#define busnum_BDK_PCCBR_XXX_VSEC_ID 0
#define arguments_BDK_PCCBR_XXX_VSEC_ID -1,-1,-1,-1

/**
 * Register (PCCBR) pccbr_xxx_vsec_sctl
 *
 * PCC Bridge Vendor-Specific Secure Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccbr_xxx_vsec_sctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCBR_XXX_REV[RID]. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCBR_XXX_REV[RID]. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccbr_xxx_vsec_sctl_s cn; */
} bdk_pccbr_xxx_vsec_sctl_t;

#define BDK_PCCBR_XXX_VSEC_SCTL BDK_PCCBR_XXX_VSEC_SCTL_FUNC()
static inline uint64_t BDK_PCCBR_XXX_VSEC_SCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCBR_XXX_VSEC_SCTL_FUNC(void)
{
    return 0x114;
}

#define typedef_BDK_PCCBR_XXX_VSEC_SCTL bdk_pccbr_xxx_vsec_sctl_t
#define bustype_BDK_PCCBR_XXX_VSEC_SCTL BDK_CSR_TYPE_PCCBR
#define basename_BDK_PCCBR_XXX_VSEC_SCTL "PCCBR_XXX_VSEC_SCTL"
#define busnum_BDK_PCCBR_XXX_VSEC_SCTL 0
#define arguments_BDK_PCCBR_XXX_VSEC_SCTL -1,-1,-1,-1

#endif /* __BDK_CSRS_PCCBR_H__ */

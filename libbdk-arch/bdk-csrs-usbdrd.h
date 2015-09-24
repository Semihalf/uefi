#ifndef __BDK_CSRS_USBDRD_H__
#define __BDK_CSRS_USBDRD_H__
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
 * Cavium USBDRD.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration usbdrd_bar_e
 *
 * USBDRD Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_USBDRD_BAR_E_USBDRDX_PF_BAR0(a) (0x868000000000ll + 0x1000000000ll * (a)) /**< Base address for standard registers. */
#define BDK_USBDRD_BAR_E_USBDRDX_PF_BAR4(a) (0x868000200000ll + 0x1000000000ll * (a)) /**< Base address for MSI-X registers. */

/**
 * Enumeration usbdrd_int_vec_e
 *
 * USBDRD MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_USBDRD_INT_VEC_E_UAHC_IMAN_IP (0) /**< Changed in pass 1.1. See UAHC(0)_IMAN(0)[IP]. */
#define BDK_USBDRD_INT_VEC_E_UAHC_USBSTS_HSE (2) /**< Changed in pass 1.1. See UAHC(0..1)_USBSTS[HSE]. */
#define BDK_USBDRD_INT_VEC_E_UAHC_USBSTS_HSE_CLEAR (3) /**< Changed in pass 1.1. Level sensitive interrupt clear vector. */
#define BDK_USBDRD_INT_VEC_E_UCTL_INTSTAT (1) /**< Changed in pass 1.1.
                                       See interrupt clears USBDRD(0..1)_UCTL_INTSTAT,
                                       interrupt sets USBDRD(0..1)_UCTL_INTSTAT_W1S,
                                       enable clears USBDRD(0..1)_UCTL_INTENA_W1C,
                                       and enable sets USBDRD(0..1)_UCTL_INTENA_W1S. */

/**
 * Enumeration usbdrd_uahc_dgcmd_cmdtype_e
 *
 * USBDRD UAHC Device Generic Command Enumeration
 * Commands for USBDRD()_UAHC_DGCMD[CMDTYPE].
 * Any command encodings that are not present are considered Reserved.
 * INTERNAL: Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.6.1 for details.
 */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_ALL_FIFO_FLUSH (0xa) /**< Flush all FIFOs.
                                       This command does not use the USBDRD()_UAHC_DGCMDPAR field. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_RUN_SOC_BUS_LOOPBACK_TEST (0x10) /**< When enabled, executes an SoC Bus Loopback test, which allows the data flow from transmit
                                       to receive to be tested without any connection to a PHY.
                                       
                                       1. Configure EP0 as a non-stream capable Bulk OUT endpoint with the desired MaxPacketSize.
                                       
                                       2. Configure EP1 as a non-stream capable Bulk IN endpoint assigned to Tx-FIFO 0 with the
                                          desired MaxPacketSize.
                                       
                                       3. Issue this command with Parameter[0] set to '1', enabling Loopback mode.
                                       
                                       4. Issue Start Transfer to EP0.
                                       
                                       5. Issue Start Transfer to EP1.
                                       
                                       6. The core reads data from the IN buffers and writes it back to the OUT buffers.
                                          The IN and OUT must have an equal amount of data buffer. The Tx-FIFO 0 default value of
                                          66 should be changed to 130 for loopback mode.
                                       
                                       USBDRD()_UAHC_DGCMDPAR[0] = When 1, enables loopback mode. When 0, disables loopback
                                       mode. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_SELECTED_FIFO_FLUSH (9) /**< Flush the selected FIFO.
                                       _ USBDRD()_UAHC_DGCMDPAR[4:0] = FIFO Number.
                                       _ USBDRD()_UAHC_DGCMDPAR[5]   = 1 for TX FIFO and 0 for RX FIFO. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_SET_ENDPOINT_NRDY (0xc) /**< Issuing this command will make the core think that the given endpoint is in an NRDY state.
                                       If there are buffers available in that endpoint, the core will immediately transmit an
                                       ERDY.
                                       _ USBDRD()_UAHC_DGCMDPAR[4:0] = Physical Endpoint Number. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_SET_PERIODIC_PARAMETERS (2) /**< Allows the software to program the periodic parameters.
                                       USBDRD()_UAHC_DGCMDPAR[9:0] = Software should set this to the same value programmed
                                       by the host through the Set SEL device request, in microseconds.
                                       The Set SEL control transfer has 6 bytes of data and contains 4 values; Refer to the USB
                                       3.0 spec, Section 9.4.12.
                                       
                                       <pre>
                                       Offset Name   Meaning
                                       ------ -----  --------------------------
                                       0      U1SEL  Time in s for U1 System Exit Latency
                                       1      U1PEL  Time in s for U1 Device to Host Exit Latency
                                       2      U2SEL  Time in s for U2 System Exit Latency
                                       4      U2PEL  Time in s for U2 Device to Host Exit Latency
                                       </pre>
                                       
                                       If the device is enabled for U1 and U2, then the U2PEL should be programmed. If the device
                                       is enabled only for U1, then U1PEL should be programmed into this parameter.
                                       If the value is greater than 125us, then the software must program a value of zero into
                                       this register. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_SET_SCRATCHPAD_BUFFER_ARRAY_ADDR_H (5) /**< This command sets bits [63:32] of the external address of the scratchpad buffer
                                       array used for save/restore to the value in USBDRD()_UAHC_DGCMDPAR.
                                       If either this command or SET_SCRATCHPAD_BUFFER_ARRAY_ADDR_L is issued while the
                                       controller is stopped (USBDRD()_UAHC_DCTL[RS]=0), the
                                       USBDRD()_UAHC_DGCMD[CMDIOC] bit must be set to 0.
                                       
                                       The device scratchpad buffer array has the same format as the xHCI scratchpad buffer
                                       array; it contains an array of 64-bit pointers to data buffers that will be used to
                                       save the controller's state. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_SET_SCRATCHPAD_BUFFER_ARRAY_ADDR_L (4) /**< This command sets bits [31:0] of the external address of the scratchpad buffer
                                       array used for save/restore to the value in USBDRD()_UAHC_DGCMDPAR.
                                       If either this command or SET_SCRATCHPAD_BUFFER_ARRAY_ADDR_H is issued while the
                                       controller is stopped (USBDRD()_UAHC_DCTL[RS]=0), the
                                       USBDRD()_UAHC_DGCMD[CMDIOC] bit must be set to 0.
                                       
                                       The device scratchpad buffer array has the same format as the xHCI scratchpad buffer
                                       array; it contains an array of 64-bit pointers to data buffers that will be used to
                                       save the controller's state. */
#define BDK_USBDRD_UAHC_DGCMD_CMDTYPE_E_TRANSMIT_DEVICE_NOTIFICATION (7) /**< This command allows any device notification to be transmitted, using the notification type
                                       and notification parameters specified in the DGCMDPAR register.
                                       
                                       _ USBDRD()_UAHC_DGCMDPAR[3:0]  = Notification type.
                                       
                                       _ USBDRD()_UAHC_DGCMDPAR[31:4] = Notification parameters, depends on the
                                         notification type.
                                       
                                       For example, to transmit a Function Wake, software sets
                                       USBDRD()_UAHC_DGCMDPAR[3:0] to 1, and USBDRD()_UAHC_DGCMDPAR[10:4] to the
                                       interface number.
                                       
                                       This field relates to the Notification Type Specific field in a Device Notification
                                       Transaction Packet as described in Section 8.5.6 of the USB3 Specification. The
                                       following bits of the DGCMDPAR register have been put into the corresponding
                                       DWORD described in Section 8.5.6 of the USB3 Specification:
                                       
                                       _ USBDRD()_UAHC_DGCMDPAR[3:0]   into DWORD 1[7:4]  (Notification Type).
                                       _ USBDRD()_UAHC_DGCMDPAR[27:4]  into DWORD 1[31:8] (Notification Type Specific).
                                       + USBDRD()_UAHC_DGCMDPAR[31:28] into DWORD 2[3:0]  (Notification Type Specific).
                                       
                                       There is one exception for the Bus Interval Adjustment Device Notification:
                                       USBDRD()_UAHC_DGCMDPAR[19:4] represents the Bus Interval Adjustment field;
                                       however, in the USB3 specification, the Bus Interval Adjustment field is
                                       actually at 31:16 of DWORD 1.
                                       
                                       In the case of Host Role Request, USBDRD()_UAHC_DGCMDPAR[3:0] = 4, and
                                       USBDRD()_UAHC_DGCMDPAR[5:4] = RSP Phase. */

/**
 * Register (NCB) usbdrd#_msix_pba#
 *
 * USBDRD MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the USBDRD_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated USBDRD_MSIX_VEC()_CTL, enumerated by USBDRD_INT_VEC_E.
                                                                 Bits that have no associated USBDRD_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated USBDRD_MSIX_VEC()_CTL, enumerated by USBDRD_INT_VEC_E.
                                                                 Bits that have no associated USBDRD_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_msix_pbax_s cn; */
} bdk_usbdrdx_msix_pbax_t;

static inline uint64_t BDK_USBDRDX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x8680002f0000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x8680002f0000ll + 0x1000000000ll * ((a) & 0x1) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_MSIX_PBAX(a,b) bdk_usbdrdx_msix_pbax_t
#define bustype_BDK_USBDRDX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_MSIX_PBAX(a,b) "USBDRDX_MSIX_PBAX"
#define device_bar_BDK_USBDRDX_MSIX_PBAX(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_USBDRDX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_USBDRDX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_msix_vec#_addr
 *
 * USBDRD MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the USBDRD_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's USBDRD()_MSIX_VEC()_ADDR, USBDRD()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of USBDRD()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_USBDRD()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's USBDRD()_MSIX_VEC()_ADDR, USBDRD()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of USBDRD()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_USBDRD()_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_msix_vecx_addr_s cn; */
} bdk_usbdrdx_msix_vecx_addr_t;

static inline uint64_t BDK_USBDRDX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=3)))
        return 0x868000200000ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=3)))
        return 0x868000200000ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("USBDRDX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) bdk_usbdrdx_msix_vecx_addr_t
#define bustype_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) "USBDRDX_MSIX_VECX_ADDR"
#define device_bar_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_USBDRDX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_msix_vec#_ctl
 *
 * USBDRD MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the USBDRD_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts will be sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_msix_vecx_ctl_s cn; */
} bdk_usbdrdx_msix_vecx_ctl_t;

static inline uint64_t BDK_USBDRDX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=3)))
        return 0x868000200008ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=3)))
        return 0x868000200008ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("USBDRDX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_MSIX_VECX_CTL(a,b) bdk_usbdrdx_msix_vecx_ctl_t
#define bustype_BDK_USBDRDX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_MSIX_VECX_CTL(a,b) "USBDRDX_MSIX_VECX_CTL"
#define device_bar_BDK_USBDRDX_MSIX_VECX_CTL(a,b) 0x4 /* PF_BAR4 */
#define busnum_BDK_USBDRDX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_USBDRDX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_caplength
 *
 * XHCI Capability Length Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_caplength_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t hciversion            : 16; /**< [ 31: 16](RO) Host controller interface version number. */
        uint32_t reserved_8_15         : 8;
        uint32_t caplength             : 8;  /**< [  7:  0](RO) Capability registers length. */
#else /* Word 0 - Little Endian */
        uint32_t caplength             : 8;  /**< [  7:  0](RO) Capability registers length. */
        uint32_t reserved_8_15         : 8;
        uint32_t hciversion            : 16; /**< [ 31: 16](RO) Host controller interface version number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_caplength_s cn; */
} bdk_usbdrdx_uahc_caplength_t;

static inline uint64_t BDK_USBDRDX_UAHC_CAPLENGTH(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_CAPLENGTH(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_CAPLENGTH", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_CAPLENGTH(a) bdk_usbdrdx_uahc_caplength_t
#define bustype_BDK_USBDRDX_UAHC_CAPLENGTH(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_CAPLENGTH(a) "USBDRDX_UAHC_CAPLENGTH"
#define device_bar_BDK_USBDRDX_UAHC_CAPLENGTH(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_CAPLENGTH(a) (a)
#define arguments_BDK_USBDRDX_UAHC_CAPLENGTH(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_config
 *
 * XHCI Configuration Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.7.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_config_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t maxslotsen            : 8;  /**< [  7:  0](R/W) Maximum device slots enabled. */
#else /* Word 0 - Little Endian */
        uint32_t maxslotsen            : 8;  /**< [  7:  0](R/W) Maximum device slots enabled. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_config_s cn; */
} bdk_usbdrdx_uahc_config_t;

static inline uint64_t BDK_USBDRDX_UAHC_CONFIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_CONFIG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000058ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000058ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_CONFIG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_CONFIG(a) bdk_usbdrdx_uahc_config_t
#define bustype_BDK_USBDRDX_UAHC_CONFIG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_CONFIG(a) "USBDRDX_UAHC_CONFIG"
#define device_bar_BDK_USBDRDX_UAHC_CONFIG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_CONFIG(a) (a)
#define arguments_BDK_USBDRDX_UAHC_CONFIG(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_crcr
 *
 * XHCI Command Ring Control Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.5.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_crcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t cmd_ring_ptr          : 58; /**< [ 63:  6](WO) Command ring pointer. */
        uint64_t reserved_4_5          : 2;
        uint64_t crr                   : 1;  /**< [  3:  3](RO/H) Command ring running. */
        uint64_t ca                    : 1;  /**< [  2:  2](WO) Command abort. */
        uint64_t cs                    : 1;  /**< [  1:  1](WO) Command stop. */
        uint64_t rcs                   : 1;  /**< [  0:  0](WO) Ring cycle state. */
#else /* Word 0 - Little Endian */
        uint64_t rcs                   : 1;  /**< [  0:  0](WO) Ring cycle state. */
        uint64_t cs                    : 1;  /**< [  1:  1](WO) Command stop. */
        uint64_t ca                    : 1;  /**< [  2:  2](WO) Command abort. */
        uint64_t crr                   : 1;  /**< [  3:  3](RO/H) Command ring running. */
        uint64_t reserved_4_5          : 2;
        uint64_t cmd_ring_ptr          : 58; /**< [ 63:  6](WO) Command ring pointer. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_crcr_s cn; */
} bdk_usbdrdx_uahc_crcr_t;

static inline uint64_t BDK_USBDRDX_UAHC_CRCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_CRCR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000038ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000038ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_CRCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_CRCR(a) bdk_usbdrdx_uahc_crcr_t
#define bustype_BDK_USBDRDX_UAHC_CRCR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_CRCR(a) "USBDRDX_UAHC_CRCR"
#define device_bar_BDK_USBDRDX_UAHC_CRCR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_CRCR(a) (a)
#define arguments_BDK_USBDRDX_UAHC_CRCR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dalepena
 *
 * Device Active USB Endpoint Enable Register
 * This register indicates whether a USB endpoint is active in a given configuration or
 * interface.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.2.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dalepena_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t usbactep              : 32; /**< [ 31:  0](R/W) This field indicates if a USB endpoint is active in the current configuration
                                                                 and interface. It applies to USB IN endpoints 0-15 and OUT endpoints 0-15,
                                                                 with one bit for each of the 32 possible endpoints. Even numbers are for
                                                                 USB OUT endpoints, and odd numbers are for USB IN endpoints, as
                                                                 follows:

                                                                  <0> = USB EP0-OUT.
                                                                  <1> = USB EP0-IN.
                                                                  <2> = USB EP1-OUT.
                                                                  <3> = USB EP1-IN.

                                                                 The entity programming this register must set bits 0 and 1 because they
                                                                 enable control endpoints that map to physical endpoints (resources) after
                                                                 USBReset.

                                                                 Application software clears these bits for all endpoints (other than EP0-OUT
                                                                 and EP0-IN) after detecting a USB reset. After receiving SetConfiguration
                                                                 and SetInterface requests, the application must program endpoint registers
                                                                 accordingly and set these bits.
                                                                 INTERNAL: For more information, see 'Flexible Endpoint Mapping' on Synopsys DWC_usb3
                                                                 Databook v2.80a, page 82. */
#else /* Word 0 - Little Endian */
        uint32_t usbactep              : 32; /**< [ 31:  0](R/W) This field indicates if a USB endpoint is active in the current configuration
                                                                 and interface. It applies to USB IN endpoints 0-15 and OUT endpoints 0-15,
                                                                 with one bit for each of the 32 possible endpoints. Even numbers are for
                                                                 USB OUT endpoints, and odd numbers are for USB IN endpoints, as
                                                                 follows:

                                                                  <0> = USB EP0-OUT.
                                                                  <1> = USB EP0-IN.
                                                                  <2> = USB EP1-OUT.
                                                                  <3> = USB EP1-IN.

                                                                 The entity programming this register must set bits 0 and 1 because they
                                                                 enable control endpoints that map to physical endpoints (resources) after
                                                                 USBReset.

                                                                 Application software clears these bits for all endpoints (other than EP0-OUT
                                                                 and EP0-IN) after detecting a USB reset. After receiving SetConfiguration
                                                                 and SetInterface requests, the application must program endpoint registers
                                                                 accordingly and set these bits.
                                                                 INTERNAL: For more information, see 'Flexible Endpoint Mapping' on Synopsys DWC_usb3
                                                                 Databook v2.80a, page 82. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dalepena_s cn; */
} bdk_usbdrdx_uahc_dalepena_t;

static inline uint64_t BDK_USBDRDX_UAHC_DALEPENA(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DALEPENA(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c720ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c720ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DALEPENA", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DALEPENA(a) bdk_usbdrdx_uahc_dalepena_t
#define bustype_BDK_USBDRDX_UAHC_DALEPENA(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DALEPENA(a) "USBDRDX_UAHC_DALEPENA"
#define device_bar_BDK_USBDRDX_UAHC_DALEPENA(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DALEPENA(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DALEPENA(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_db#
 *
 * XHCI Doorbell Registers
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.6.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 *
 * INTERNAL: xHCI spec, page 32: there are USBDRD()_UAHC_HCSPARAMS1[MAXSLOTS]+1 doorbell
 * registers.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dbx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dbstreamid            : 16; /**< [ 31: 16](WO) Doorbell stream ID. */
        uint32_t reserved_8_15         : 8;
        uint32_t dbtarget              : 8;  /**< [  7:  0](WO) Doorbell target. */
#else /* Word 0 - Little Endian */
        uint32_t dbtarget              : 8;  /**< [  7:  0](WO) Doorbell target. */
        uint32_t reserved_8_15         : 8;
        uint32_t dbstreamid            : 16; /**< [ 31: 16](WO) Doorbell stream ID. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dbx_s cn; */
} bdk_usbdrdx_uahc_dbx_t;

static inline uint64_t BDK_USBDRDX_UAHC_DBX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DBX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=64)))
        return 0x868000000480ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x7f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=64)))
        return 0x868000000480ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x7f);
    __bdk_csr_fatal("USBDRDX_UAHC_DBX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DBX(a,b) bdk_usbdrdx_uahc_dbx_t
#define bustype_BDK_USBDRDX_UAHC_DBX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DBX(a,b) "USBDRDX_UAHC_DBX"
#define device_bar_BDK_USBDRDX_UAHC_DBX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DBX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_DBX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dboff
 *
 * XHCI Doorbell Array Offset Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.7.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dboff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dboff                 : 30; /**< [ 31:  2](RO) Doorbell array offset. */
        uint32_t reserved_0_1          : 2;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_1          : 2;
        uint32_t dboff                 : 30; /**< [ 31:  2](RO) Doorbell array offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dboff_s cn; */
} bdk_usbdrdx_uahc_dboff_t;

static inline uint64_t BDK_USBDRDX_UAHC_DBOFF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DBOFF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000014ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000014ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DBOFF", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DBOFF(a) bdk_usbdrdx_uahc_dboff_t
#define bustype_BDK_USBDRDX_UAHC_DBOFF(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DBOFF(a) "USBDRDX_UAHC_DBOFF"
#define device_bar_BDK_USBDRDX_UAHC_DBOFF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DBOFF(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DBOFF(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_dcbaap
 *
 * XHCI Device Context Base-Address-Array Pointer Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.6.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_dcbaap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dcbaap                : 58; /**< [ 63:  6](R/W) Device context base address array pointer. */
        uint64_t reserved_0_5          : 6;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_5          : 6;
        uint64_t dcbaap                : 58; /**< [ 63:  6](R/W) Device context base address array pointer. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dcbaap_s cn; */
} bdk_usbdrdx_uahc_dcbaap_t;

static inline uint64_t BDK_USBDRDX_UAHC_DCBAAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DCBAAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000050ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000050ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DCBAAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DCBAAP(a) bdk_usbdrdx_uahc_dcbaap_t
#define bustype_BDK_USBDRDX_UAHC_DCBAAP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_DCBAAP(a) "USBDRDX_UAHC_DCBAAP"
#define device_bar_BDK_USBDRDX_UAHC_DCBAAP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DCBAAP(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DCBAAP(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dcfg
 *
 * Device Configuration Register
 * This register configures the core in Device mode after power-on or after certain control
 * commands or enumeration. Do not make changes to this register after initial programming.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dcfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t ignorestreampp        : 1;  /**< [ 23: 23](R/W) This bit only affects stream-capable bulk endpoints.
                                                                 When this bit is set to 0x0 and the controller receives a Data Packet with the
                                                                 Packet Pending (PP) bit set to 0 for OUT endpoints, or it receives an ACK
                                                                 with the NumP field set to 0 and PP set to 0 for IN endpoints, the core
                                                                 attempts to search for another stream (CStream) to initiate to the host.

                                                                 However, there are two situations where this behavior is not optimal:

                                                                 * When the host is setting PP=0 even though it has not finished the
                                                                 stream, or

                                                                 * When the endpoint on the device is configured with one transfer
                                                                 resource and therefore does not have any other streams to initiate to the
                                                                 host.

                                                                 When this bit is set to 0x1, the core ignores the Packet Pending bit for the
                                                                 purposes of stream selection and does not search for another stream when
                                                                 it receives DP(PP=0) or ACK(NumP=0, PP=0). This can enhance the
                                                                 performance when the device system bus bandwidth is low */
        uint32_t lpmcap                : 1;  /**< [ 22: 22](R/W) LPM capable.
                                                                 The application uses this bit to control the controller's core LPM
                                                                 capabilities. If the core operates as a non-LPM-capable device, it cannot
                                                                 respond to LPM transactions.
                                                                   0x0 = LPM capability is not enabled.
                                                                   0x1 = LPM capability is enabled. */
        uint32_t nump                  : 5;  /**< [ 21: 17](R/W) Number of receive buffers.
                                                                 This bit indicates the number of receive buffers to be reported in the ACK
                                                                 TP.
                                                                 The DWC_usb3 controller uses this field if USBDRD()_UAHC_GRXTHRCFG[USBRXPKTCNTSEL]
                                                                 is set to 0x0. The application can program this value based on RxFIFO size,
                                                                 buffer sizes programmed in descriptors, and system latency.
                                                                 For an OUT endpoint, this field controls the number of receive buffers
                                                                 reported in the NumP field of the ACK TP transmitted by the core.
                                                                 INTERNAL: Note: This bit is used in host mode when Debug Capability is enabled. */
        uint32_t intrnum               : 5;  /**< [ 16: 12](R/W) Interrupt number.
                                                                 Indicates interrupt/EventQ number on which non-endpoint-specific device-related
                                                                 interrupts (see DEVT) are generated. */
        uint32_t reserved_10_11        : 2;
        uint32_t devaddr               : 7;  /**< [  9:  3](R/W) Device address.
                                                                 The application must perform the following:
                                                                  * Program this field after every SetAddress request.
                                                                  * Reset this field to zero after USB reset. */
        uint32_t devspd                : 3;  /**< [  2:  0](R/W) Device speed.
                                                                 Indicates the speed at which the application requires the core to connect, or
                                                                 the maximum speed the application can support. However, the actual bus
                                                                 speed is determined only after the chirp sequence is completed, and is
                                                                 based on the speed of the USB host to which the core is connected.
                                                                   0x0 = High-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz).
                                                                   0x1 = Full-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz).
                                                                   0x4 = SuperSpeed (USB 3.0 PHY clock is 125 MHz or 250 MHz). */
#else /* Word 0 - Little Endian */
        uint32_t devspd                : 3;  /**< [  2:  0](R/W) Device speed.
                                                                 Indicates the speed at which the application requires the core to connect, or
                                                                 the maximum speed the application can support. However, the actual bus
                                                                 speed is determined only after the chirp sequence is completed, and is
                                                                 based on the speed of the USB host to which the core is connected.
                                                                   0x0 = High-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz).
                                                                   0x1 = Full-speed (USB 2.0 PHY clock is 30 MHz or 60 MHz).
                                                                   0x4 = SuperSpeed (USB 3.0 PHY clock is 125 MHz or 250 MHz). */
        uint32_t devaddr               : 7;  /**< [  9:  3](R/W) Device address.
                                                                 The application must perform the following:
                                                                  * Program this field after every SetAddress request.
                                                                  * Reset this field to zero after USB reset. */
        uint32_t reserved_10_11        : 2;
        uint32_t intrnum               : 5;  /**< [ 16: 12](R/W) Interrupt number.
                                                                 Indicates interrupt/EventQ number on which non-endpoint-specific device-related
                                                                 interrupts (see DEVT) are generated. */
        uint32_t nump                  : 5;  /**< [ 21: 17](R/W) Number of receive buffers.
                                                                 This bit indicates the number of receive buffers to be reported in the ACK
                                                                 TP.
                                                                 The DWC_usb3 controller uses this field if USBDRD()_UAHC_GRXTHRCFG[USBRXPKTCNTSEL]
                                                                 is set to 0x0. The application can program this value based on RxFIFO size,
                                                                 buffer sizes programmed in descriptors, and system latency.
                                                                 For an OUT endpoint, this field controls the number of receive buffers
                                                                 reported in the NumP field of the ACK TP transmitted by the core.
                                                                 INTERNAL: Note: This bit is used in host mode when Debug Capability is enabled. */
        uint32_t lpmcap                : 1;  /**< [ 22: 22](R/W) LPM capable.
                                                                 The application uses this bit to control the controller's core LPM
                                                                 capabilities. If the core operates as a non-LPM-capable device, it cannot
                                                                 respond to LPM transactions.
                                                                   0x0 = LPM capability is not enabled.
                                                                   0x1 = LPM capability is enabled. */
        uint32_t ignorestreampp        : 1;  /**< [ 23: 23](R/W) This bit only affects stream-capable bulk endpoints.
                                                                 When this bit is set to 0x0 and the controller receives a Data Packet with the
                                                                 Packet Pending (PP) bit set to 0 for OUT endpoints, or it receives an ACK
                                                                 with the NumP field set to 0 and PP set to 0 for IN endpoints, the core
                                                                 attempts to search for another stream (CStream) to initiate to the host.

                                                                 However, there are two situations where this behavior is not optimal:

                                                                 * When the host is setting PP=0 even though it has not finished the
                                                                 stream, or

                                                                 * When the endpoint on the device is configured with one transfer
                                                                 resource and therefore does not have any other streams to initiate to the
                                                                 host.

                                                                 When this bit is set to 0x1, the core ignores the Packet Pending bit for the
                                                                 purposes of stream selection and does not search for another stream when
                                                                 it receives DP(PP=0) or ACK(NumP=0, PP=0). This can enhance the
                                                                 performance when the device system bus bandwidth is low */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dcfg_s cn; */
} bdk_usbdrdx_uahc_dcfg_t;

static inline uint64_t BDK_USBDRDX_UAHC_DCFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DCFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c700ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c700ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DCFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DCFG(a) bdk_usbdrdx_uahc_dcfg_t
#define bustype_BDK_USBDRDX_UAHC_DCFG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DCFG(a) "USBDRDX_UAHC_DCFG"
#define device_bar_BDK_USBDRDX_UAHC_DCFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DCFG(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DCFG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dctl
 *
 * Device Control Register
 * This register controls devlice mode.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rs                    : 1;  /**< [ 31: 31](R/W) Run/Stop.
                                                                 The software writes 1 to this bit to start the device controller operation.
                                                                 To stop the device controller operation, the software must remove any active
                                                                 transfers and write 0 to this bit. When the controller is stopped, it sets the
                                                                 USBDRD()_UAHC_DSTS[DEVCTRLHLT] bit when the core is idle and the lower layer finishes
                                                                 the disconnect process.

                                                                 The Run/Stop bit must be used in following cases as specified:

                                                                    1. After power-on reset and CSR initialization, the software must write 1 to this bit
                                                                    to start the device controller. The controller does not signal connect to the host
                                                                    until this bit is set.

                                                                    2. The software uses this bit to control the device controller to perform a soft
                                                                    disconnect. When the software writes 0 to this bit, the host does not see that
                                                                    the device is connected. The device controller stays in the disconnected state
                                                                    until the software writes 1 to this bit. The minimum duration of keeping this bit
                                                                    cleared is 30ms in SuperSpeed and 10ms in High/Full/LowSpeed.

                                                                    If the software attempts a connect after the soft disconnect or detects a
                                                                    disconnect event, it must set USBDRD()_UAHC_DCTL[ULSTCHNGREQ] to
                                                                    "Rx.Detect" before reasserting the Run/Stop bit.

                                                                    INTERNAL: 3. When the USB or Link is in a lower power state and the Two Power Rails
                                                                    configuration is selected, software writes 0 to this bit to indicate that it is going
                                                                    to turn off the Core Power Rail. After the software turns on the Core Power Rail
                                                                    again and re-initializes the device controller, it must set this bit to start the
                                                                    device controller. For more details, see Low Power Operation on page 599. */
        uint32_t csftrst               : 1;  /**< [ 30: 30](R/W1S/H) Core Soft Reset.
                                                                 Resets the all clock domains as follows:
                                                                 * Clears the interrupts and all the CSRs except the following registers:
                                                                   GCTL, GUCTL, GSTS, GSNPSID, GGPIO, GUID, GUSB2PHYCFGn registers,
                                                                   GUSB3PIPECTLn registers, DCFG, DCTL, DEVTEN, DSTS

                                                                 * All module state machines (except the SoC Bus Slave Unit) are reset to the
                                                                    IDLE state, and all the TxFIFOs and the RxFIFO are flushed.

                                                                 * Any transactions on the SoC bus Master are terminated as soon as possible,
                                                                   after gracefully completing the last data phase of a SoC bus transfer. Any
                                                                   transactions on the USB are terminated immediately.

                                                                 The application can write this bit at any time to reset the core. This is a self-clearing
                                                                 bit; the core clears this bit after all necessary logic is reset in the core,
                                                                 which may take several clocks depending on the corefs current state. Once this
                                                                 bit is cleared, the software must wait at least 3 PHY clocks before accessing the
                                                                 PHY domain (synchronization delay). Typically, software reset is used during
                                                                 software development and also when you dynamically change the PHY selection
                                                                 bits in the USB configuration registers listed above. When you change the PHY,
                                                                 the corresponding clock for the PHY is selected and used in the PHY domain.
                                                                 Once a new clock is selected, the PHY domain must be reset for proper
                                                                 operation. */
        uint32_t reserved_29           : 1;
        uint32_t hird_thres            : 5;  /**< [ 28: 24](R/W) HIRD Threshold.
                                                                 The core asserts output signals utmi_l1_suspend_n and utmi_sleep_n on the basis of this
                                                                 signal:

                                                                 * The core asserts utmi_l1_suspend_n to put the PHY into Deep Low-Power
                                                                   mode in L1 when both of the following are true:
                                                                   - HIRD value is greater than or equal to the value in HIRD_Thres[3:0]
                                                                   - HIRD_Thres[4] is set to 1'b1.

                                                                 * The core asserts utmi_sleep_n on L1 when one of the following is true:
                                                                   - If the HIRD value is less than HIRD_Thres[3:0] or
                                                                   - HIRD_Thres[4] is set to 1'b0. */
        uint32_t appl1res              : 1;  /**< [ 23: 23](R/W) LPM Response Programmed by Application.
                                                                 Handshake response to LPM token specified by device application. Response
                                                                 depends on USBDRD()_UAHC_DCFG[LPMCAP].

                                                                  LPMCAP is 0x0 - The core always responds with Timeout (that is, no
                                                                  response).

                                                                  LPMCAP is 0x1 and this bit is 0:
                                                                  The core responds with an ACK upon a successful LPM transaction,
                                                                      which requires all of the following are satisfied:

                                                                      * There are no PID/CRC5 errors in both the EXT token and the LPM token
                                                                      (if not true, inactivity results in a timeout ERROR)

                                                                      * A valid bLinkState = 0001B (L1) is received in the LPM transaction (else
                                                                      STALL)

                                                                      * No data is pending in the Transmit FIFO and OUT endpoints not in flow
                                                                      controlled state (else NYET)

                                                                  LPMCAP is 0x1 and this bit is 1:
                                                                 The core responds with an ACK upon a successful LPM, independent
                                                                     of transmit FIFO status and OUT endpoint flow control state. The LPM
                                                                     transaction is successful if all of the following are satisfied:

                                                                     * There are no PID/CRC5 errors in both the EXT token and the LPM token
                                                                     (else ERROR)

                                                                     * A valid bLinkState = 0001B (L1) is received in the LPM transaction (else
                                                                     STALL) */
        uint32_t reserved_20_22        : 3;
        uint32_t keepconnect           : 1;  /**< [ 19: 19](WO) Always write 0.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t l1hibernationen       : 1;  /**< [ 18: 18](WO) Always write 0.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t crs                   : 1;  /**< [ 17: 17](WO) Controller Restore State.
                                                                 This command is similar to the USBDRD()_UAHC_USBCMD[CRS] bit in host mode and
                                                                 initiates the restore process. When software sets this bit to 1, the controller
                                                                 immediately sets USBDRD()_UAHC_DSTS[RSS] to 1. When the controller has finished
                                                                 the restore process, it sets USBDRD()_UAHC_DSTS[RSS] to 0.
                                                                 Note: When read, this field always returns 0. */
        uint32_t css                   : 1;  /**< [ 16: 16](WO) Controller Save State.
                                                                 This command is similar to the USBDRD()_UAHC_USBCMD[CSS] bit in host mode and
                                                                 initiates the restore process. When software sets this bit to 1, the controller
                                                                 immediately sets USBDRD()_UAHC_DSTS[SSS] to 1. When the controller has finished
                                                                 the save process, it sets USBDRD()_UAHC_DSTS[SSS] to 0.
                                                                 Note: When read, this field always returns 0. */
        uint32_t reserved_13_15        : 3;
        uint32_t initu2ena             : 1;  /**< [ 12: 12](R/W) Initiate U2 Enable.
                                                                  0 = May not initiate U2 (default).
                                                                  1 = May initiate U2.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 SetFeature(U2_ENABLE), and clears this bit when ClearFeature(U2_ENABLE) is
                                                                 received.

                                                                 If USBDRD()_UAHC_DCTL[ACCEPTU2ENA] is 0, the link immediately exits U2 state. */
        uint32_t acceptu2ena           : 1;  /**< [ 11: 11](R/W) Accept U2 Enable.
                                                                  0 = Reject U2 except when Force_LinkPM_Accept bit is set (default).
                                                                  1 = Core accepts transition to U2 state if nothing is pending on the
                                                                     application side.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 a SetConfiguration command. */
        uint32_t initu1ena             : 1;  /**< [ 10: 10](R/W) Initiate U1 Enable.
                                                                  0 = May not initiate U1 (default).
                                                                  1 = May initiate U1.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 SetFeature(U1_ENABLE), and clears this bit when ClearFeature(U1_ENABLE) is
                                                                 received.

                                                                 If USBDRD()_UAHC_DCTL[ACCEPTU1ENA] is 0, the link immediately exits U1 state. */
        uint32_t acceptu1ena           : 1;  /**< [  9:  9](R/W) Accept U1 Enable.
                                                                  0 = Reject U1 except when Force_LinkPM_Accept bit is set (default)
                                                                  1 = Core accepts transition to U1 state if nothing is pending on the
                                                                     application side.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 a SetConfiguration command. */
        uint32_t ulstchngreq           : 4;  /**< [  8:  5](WO) USB/Link State Change Request.
                                                                 Software writes this field to issue a USB/Link state change request. A change in
                                                                 this field indicates a new request to the core. If software wants to issue the same
                                                                 request back-to-back, it must write a 0 to this field between the two requests. The
                                                                 result of the state change request is reflected in USBDRD()_UAHC_DSTS[USBLNKST].
                                                                 These bits are self-cleared on the MAC Layer exiting suspended state.

                                                                 If software is updating other fields of the USBDRD()_UAHC_DCTL register and not
                                                                 intending to force any link state change, then it must write a 0 to this field.
                                                                 SuperSpeed Compliance mode is normally entered and controlled by the remote link
                                                                 partner. Refer to the USB3 specification. Alternatively, you can force the local link
                                                                 directly into Compliance mode, by resetting the SuperSpeed link with the
                                                                 USBDRD()_UAHC_DCTL[RS] bit set to zero. If you then write 0xA to the ULSTCHNGREQ
                                                                 field and 1 to USBDRD()_UAHC_DCTL[RS], the Link will go to Compliance. Once you
                                                                 are in Compliance, you may alternately write 0x0 and 0xA to this field to advance
                                                                 the compliance pattern.

                                                                 In SS mode:
                                                                     0x0 = No Action.
                                                                     0x4 = SS.Disabled.
                                                                     0x5 = Rx.Detect.
                                                                     0x6 = SS.Inactive.
                                                                     0x8 = Recovery.
                                                                     0xA = Compliance.
                                                                     Others = Reserved.

                                                                 In HS/FS/LS mode:

                                                                     0x8 = Remote wakeup request.
                                                                     The Remote wakeup request should be issued 2us after the device goes into
                                                                     suspend state (USBDRD()_UAHC_DSTS[USBLNKST] is 0x3).
                                                                     Others = Reserved. */
        uint32_t tstctl                : 4;  /**< [  4:  1](R/W) Test Control.
                                                                 0x0 = Test mode disabled.
                                                                 0x1 = Test_J mode.
                                                                 0x2 = Test_K mode.
                                                                 0x3 = Test_SE0_NAK mode.
                                                                 0x4 = Test_Packet mode.
                                                                 0x5 = Test_Force_Enable.
                                                                 Others = Reserved. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t tstctl                : 4;  /**< [  4:  1](R/W) Test Control.
                                                                 0x0 = Test mode disabled.
                                                                 0x1 = Test_J mode.
                                                                 0x2 = Test_K mode.
                                                                 0x3 = Test_SE0_NAK mode.
                                                                 0x4 = Test_Packet mode.
                                                                 0x5 = Test_Force_Enable.
                                                                 Others = Reserved. */
        uint32_t ulstchngreq           : 4;  /**< [  8:  5](WO) USB/Link State Change Request.
                                                                 Software writes this field to issue a USB/Link state change request. A change in
                                                                 this field indicates a new request to the core. If software wants to issue the same
                                                                 request back-to-back, it must write a 0 to this field between the two requests. The
                                                                 result of the state change request is reflected in USBDRD()_UAHC_DSTS[USBLNKST].
                                                                 These bits are self-cleared on the MAC Layer exiting suspended state.

                                                                 If software is updating other fields of the USBDRD()_UAHC_DCTL register and not
                                                                 intending to force any link state change, then it must write a 0 to this field.
                                                                 SuperSpeed Compliance mode is normally entered and controlled by the remote link
                                                                 partner. Refer to the USB3 specification. Alternatively, you can force the local link
                                                                 directly into Compliance mode, by resetting the SuperSpeed link with the
                                                                 USBDRD()_UAHC_DCTL[RS] bit set to zero. If you then write 0xA to the ULSTCHNGREQ
                                                                 field and 1 to USBDRD()_UAHC_DCTL[RS], the Link will go to Compliance. Once you
                                                                 are in Compliance, you may alternately write 0x0 and 0xA to this field to advance
                                                                 the compliance pattern.

                                                                 In SS mode:
                                                                     0x0 = No Action.
                                                                     0x4 = SS.Disabled.
                                                                     0x5 = Rx.Detect.
                                                                     0x6 = SS.Inactive.
                                                                     0x8 = Recovery.
                                                                     0xA = Compliance.
                                                                     Others = Reserved.

                                                                 In HS/FS/LS mode:

                                                                     0x8 = Remote wakeup request.
                                                                     The Remote wakeup request should be issued 2us after the device goes into
                                                                     suspend state (USBDRD()_UAHC_DSTS[USBLNKST] is 0x3).
                                                                     Others = Reserved. */
        uint32_t acceptu1ena           : 1;  /**< [  9:  9](R/W) Accept U1 Enable.
                                                                  0 = Reject U1 except when Force_LinkPM_Accept bit is set (default)
                                                                  1 = Core accepts transition to U1 state if nothing is pending on the
                                                                     application side.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 a SetConfiguration command. */
        uint32_t initu1ena             : 1;  /**< [ 10: 10](R/W) Initiate U1 Enable.
                                                                  0 = May not initiate U1 (default).
                                                                  1 = May initiate U1.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 SetFeature(U1_ENABLE), and clears this bit when ClearFeature(U1_ENABLE) is
                                                                 received.

                                                                 If USBDRD()_UAHC_DCTL[ACCEPTU1ENA] is 0, the link immediately exits U1 state. */
        uint32_t acceptu2ena           : 1;  /**< [ 11: 11](R/W) Accept U2 Enable.
                                                                  0 = Reject U2 except when Force_LinkPM_Accept bit is set (default).
                                                                  1 = Core accepts transition to U2 state if nothing is pending on the
                                                                     application side.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 a SetConfiguration command. */
        uint32_t initu2ena             : 1;  /**< [ 12: 12](R/W) Initiate U2 Enable.
                                                                  0 = May not initiate U2 (default).
                                                                  1 = May initiate U2.

                                                                 On USB reset, hardware clears this bit to 0. Software sets this bit after receiving
                                                                 SetFeature(U2_ENABLE), and clears this bit when ClearFeature(U2_ENABLE) is
                                                                 received.

                                                                 If USBDRD()_UAHC_DCTL[ACCEPTU2ENA] is 0, the link immediately exits U2 state. */
        uint32_t reserved_13_15        : 3;
        uint32_t css                   : 1;  /**< [ 16: 16](WO) Controller Save State.
                                                                 This command is similar to the USBDRD()_UAHC_USBCMD[CSS] bit in host mode and
                                                                 initiates the restore process. When software sets this bit to 1, the controller
                                                                 immediately sets USBDRD()_UAHC_DSTS[SSS] to 1. When the controller has finished
                                                                 the save process, it sets USBDRD()_UAHC_DSTS[SSS] to 0.
                                                                 Note: When read, this field always returns 0. */
        uint32_t crs                   : 1;  /**< [ 17: 17](WO) Controller Restore State.
                                                                 This command is similar to the USBDRD()_UAHC_USBCMD[CRS] bit in host mode and
                                                                 initiates the restore process. When software sets this bit to 1, the controller
                                                                 immediately sets USBDRD()_UAHC_DSTS[RSS] to 1. When the controller has finished
                                                                 the restore process, it sets USBDRD()_UAHC_DSTS[RSS] to 0.
                                                                 Note: When read, this field always returns 0. */
        uint32_t l1hibernationen       : 1;  /**< [ 18: 18](WO) Always write 0.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t keepconnect           : 1;  /**< [ 19: 19](WO) Always write 0.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t reserved_20_22        : 3;
        uint32_t appl1res              : 1;  /**< [ 23: 23](R/W) LPM Response Programmed by Application.
                                                                 Handshake response to LPM token specified by device application. Response
                                                                 depends on USBDRD()_UAHC_DCFG[LPMCAP].

                                                                  LPMCAP is 0x0 - The core always responds with Timeout (that is, no
                                                                  response).

                                                                  LPMCAP is 0x1 and this bit is 0:
                                                                  The core responds with an ACK upon a successful LPM transaction,
                                                                      which requires all of the following are satisfied:

                                                                      * There are no PID/CRC5 errors in both the EXT token and the LPM token
                                                                      (if not true, inactivity results in a timeout ERROR)

                                                                      * A valid bLinkState = 0001B (L1) is received in the LPM transaction (else
                                                                      STALL)

                                                                      * No data is pending in the Transmit FIFO and OUT endpoints not in flow
                                                                      controlled state (else NYET)

                                                                  LPMCAP is 0x1 and this bit is 1:
                                                                 The core responds with an ACK upon a successful LPM, independent
                                                                     of transmit FIFO status and OUT endpoint flow control state. The LPM
                                                                     transaction is successful if all of the following are satisfied:

                                                                     * There are no PID/CRC5 errors in both the EXT token and the LPM token
                                                                     (else ERROR)

                                                                     * A valid bLinkState = 0001B (L1) is received in the LPM transaction (else
                                                                     STALL) */
        uint32_t hird_thres            : 5;  /**< [ 28: 24](R/W) HIRD Threshold.
                                                                 The core asserts output signals utmi_l1_suspend_n and utmi_sleep_n on the basis of this
                                                                 signal:

                                                                 * The core asserts utmi_l1_suspend_n to put the PHY into Deep Low-Power
                                                                   mode in L1 when both of the following are true:
                                                                   - HIRD value is greater than or equal to the value in HIRD_Thres[3:0]
                                                                   - HIRD_Thres[4] is set to 1'b1.

                                                                 * The core asserts utmi_sleep_n on L1 when one of the following is true:
                                                                   - If the HIRD value is less than HIRD_Thres[3:0] or
                                                                   - HIRD_Thres[4] is set to 1'b0. */
        uint32_t reserved_29           : 1;
        uint32_t csftrst               : 1;  /**< [ 30: 30](R/W1S/H) Core Soft Reset.
                                                                 Resets the all clock domains as follows:
                                                                 * Clears the interrupts and all the CSRs except the following registers:
                                                                   GCTL, GUCTL, GSTS, GSNPSID, GGPIO, GUID, GUSB2PHYCFGn registers,
                                                                   GUSB3PIPECTLn registers, DCFG, DCTL, DEVTEN, DSTS

                                                                 * All module state machines (except the SoC Bus Slave Unit) are reset to the
                                                                    IDLE state, and all the TxFIFOs and the RxFIFO are flushed.

                                                                 * Any transactions on the SoC bus Master are terminated as soon as possible,
                                                                   after gracefully completing the last data phase of a SoC bus transfer. Any
                                                                   transactions on the USB are terminated immediately.

                                                                 The application can write this bit at any time to reset the core. This is a self-clearing
                                                                 bit; the core clears this bit after all necessary logic is reset in the core,
                                                                 which may take several clocks depending on the corefs current state. Once this
                                                                 bit is cleared, the software must wait at least 3 PHY clocks before accessing the
                                                                 PHY domain (synchronization delay). Typically, software reset is used during
                                                                 software development and also when you dynamically change the PHY selection
                                                                 bits in the USB configuration registers listed above. When you change the PHY,
                                                                 the corresponding clock for the PHY is selected and used in the PHY domain.
                                                                 Once a new clock is selected, the PHY domain must be reset for proper
                                                                 operation. */
        uint32_t rs                    : 1;  /**< [ 31: 31](R/W) Run/Stop.
                                                                 The software writes 1 to this bit to start the device controller operation.
                                                                 To stop the device controller operation, the software must remove any active
                                                                 transfers and write 0 to this bit. When the controller is stopped, it sets the
                                                                 USBDRD()_UAHC_DSTS[DEVCTRLHLT] bit when the core is idle and the lower layer finishes
                                                                 the disconnect process.

                                                                 The Run/Stop bit must be used in following cases as specified:

                                                                    1. After power-on reset and CSR initialization, the software must write 1 to this bit
                                                                    to start the device controller. The controller does not signal connect to the host
                                                                    until this bit is set.

                                                                    2. The software uses this bit to control the device controller to perform a soft
                                                                    disconnect. When the software writes 0 to this bit, the host does not see that
                                                                    the device is connected. The device controller stays in the disconnected state
                                                                    until the software writes 1 to this bit. The minimum duration of keeping this bit
                                                                    cleared is 30ms in SuperSpeed and 10ms in High/Full/LowSpeed.

                                                                    If the software attempts a connect after the soft disconnect or detects a
                                                                    disconnect event, it must set USBDRD()_UAHC_DCTL[ULSTCHNGREQ] to
                                                                    "Rx.Detect" before reasserting the Run/Stop bit.

                                                                    INTERNAL: 3. When the USB or Link is in a lower power state and the Two Power Rails
                                                                    configuration is selected, software writes 0 to this bit to indicate that it is going
                                                                    to turn off the Core Power Rail. After the software turns on the Core Power Rail
                                                                    again and re-initializes the device controller, it must set this bit to start the
                                                                    device controller. For more details, see Low Power Operation on page 599. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dctl_s cn; */
} bdk_usbdrdx_uahc_dctl_t;

static inline uint64_t BDK_USBDRDX_UAHC_DCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c704ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c704ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DCTL(a) bdk_usbdrdx_uahc_dctl_t
#define bustype_BDK_USBDRDX_UAHC_DCTL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DCTL(a) "USBDRDX_UAHC_DCTL"
#define device_bar_BDK_USBDRDX_UAHC_DCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DCTL(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DCTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_depcmd#
 *
 * Device Physical Endpoint-n Command Register
 * This register enables software to issue physical endpoint-specific commands. This register
 * contains command, control, and status fields relevant to the current generic command,
 * while the USBDRD()_UAHC_DEPCMDPAR* registers provide command parameters and return
 * status information.
 *
 * Several fields (including CMDTYPE) are write-only, so their read values are undefined. After
 * power-on, prior to issuing the first endpoint command, the read value of this register is
 * undefined. In particular, the CMDACT bit may be set after power-on. In this case, it is safe
 * to issue an endpoint command.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.2.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_depcmdx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t commandparam          : 16; /**< [ 31: 16](R/W) Command or Event Parameters.
                                                                 When this register is written:

                                                                   Command Parameters:

                                                                     For Start Transfer command:
                                                                     _  - [31:16]: StreamID. The USB StreamID assigned to this transfer

                                                                     For Start Transfer command applied to an isochronous endpoint:
                                                                     _  - [31:16]: StartMicroFramNum: Indicates the (micro)frame number to
                                                                       which the first TRB applies

                                                                     For Update Transfer, End Transfer, and Start New Configuration
                                                                     commands:
                                                                     _  - [22:16]: Transfer Resource Index (XferRscIdx). The hardware-assigned
                                                                       transfer resource index for the transfer, which was returned
                                                                       in response to the Start Transfer command. The application
                                                                       software-assigned transfer resource index for a Start New
                                                                       Configuration command.

                                                                   When this register is read:

                                                                     For XferNotReady, XferComplete, and Stream events on Bulk Endpoints:
                                                                     _  - [31:16]: StreamID. Applies only to bulk endpoints that support streams. This
                                                                                  indicates the StreamID of the transfer for which the event is
                                                                                  generated
                                                                     For XferInProgress:
                                                                     _  - [31:16]: Isochronous Microframe Number (IsocMicroFrameNum): Indicates the
                                                                                  microframe number of the beginning of the interval that generated
                                                                                  the XferInProgress event (debug purposes only)
                                                                     For XferNotReady events on Isochronous Endpoints:
                                                                     _  - [31:16]: Isochronous Microframe Number (IsocMicroFrameNum). Indicates the
                                                                                  microframe number during which the endpoint was not ready

                                                                       Note: controller core represents USB bus time as a 14-bit value on the bus and also
                                                                       in the DSTS register (USBDRD()_UAHC_DSTS[SOFFN]), but as a 16-bit value in the
                                                                       XferNotReady event. Use the 16-bit value to interact with Isochronous endpoints via
                                                                       the StartXfer command. The extra two bits that the controller core produces will be
                                                                       necessary for handling wrap-around conditions in the interaction between software
                                                                       and hardware.

                                                                    For all EPCmdCmplt events
                                                                    _  - [27:24]: Command Type. The command type that completed (Valid only in a DEPEVT
                                                                                    event. Undefined when read from the
                                                                                    USBDRD()_UAHC_DEPCMD()[COMMANDPARAM] field).

                                                                    For EPCmdCmplt event in response to Start Transfer command:
                                                                    _  - [22:16]: Transfer Resource Index (XferRscIdx). The internal hardware transfer
                                                                                    resource index assigned to this transfer. This index must be used in
                                                                                    all Update Transfer and End Transfer commands. */
        uint32_t cmdstatus             : 4;  /**< [ 15: 12](R/W) Command Completion Status.
                                                                 Additional information about the completion of this command is available in
                                                                 this field.

                                                                 Within an XferNotReady event:
                                                                 _ [15]: Indicates the reason why the XferNotReady event is generated:
                                                                 _ [15] = 0: XferNotActive: Host initiated a transfer, but the requested transfer is not
                                                                       present in the hardware.
                                                                 _ [15] = 1: XferActive: Host initiated a transfer, the transfer is present, but no valid
                                                                 TRBs
                                                                       are available
                                                                 _ [14]: Not Used
                                                                 _ [13:12]: For control endpoints, indicates what stage was requested when the transfer was
                                                                   not ready:
                                                                 _ [13:12] = 0x1: Control Data Request
                                                                 _ [13:12] = 0x2: Control Status Request

                                                                 Within an XferComplete or XferInProgress event:
                                                                 _ [15]: LST bit of the completed TRB (XferComplete only)
                                                                 _ [15]: MissedIsoc: Indicates the interval did not complete successfully (XferInProgress
                                                                   only)
                                                                 _ [14]: IOC bit of the TRB that completed.
                                                                 _ [13]: Indicates the TRB completed with a short packet reception or the last packet of an
                                                                   isochronous interval
                                                                 _ [12]: Reserved.
                                                                   If the host aborts the data stage of a control transfer, software may receive a
                                                                   XferComplete event with the EventStatus field equal to 0. This is a valid event
                                                                   that must be processed as a part of the Control Transfer Programming Model.

                                                                 Within a Stream Event:
                                                                 _ [15:12] = 0x2: StreamNotFound: This stream event is issued when the stream-capable
                                                                 endpoint
                                                                       performed a search in its transfer resource cache, but could not find an active
                                                                       and ready stream.
                                                                 _ [15:12] = 0x1: StreamFound: This stream event is issued when the stream-capable endpoint
                                                                 found
                                                                       an active and ready stream in its transfer resource cache, and initiated traffic for
                                                                       that stream to the host. The ID of the selected Stream is in the EventParam field.

                                                                     In response to a Start Transfer command:
                                                                 _ [15:12] = 0x2: Indicates expiry of the bus time reflected in the Start Transfer command.
                                                                 _ [15:12] = 0x1: Indicates there is no transfer resource available on the endpoint.

                                                                 In response to a Set Transfer Resource (DEPXFERCFG) command:
                                                                 _ [15:12] = 0x1: Indicates an error has occurred because software is requesting more
                                                                 transfer
                                                                       resources to be assigned than have been configured in the hardware.

                                                                 In response to a End Transfer command:
                                                                 _ [15:12] = 0x1: Indicates an invalid transfer resource was specified.
                                                                 INTERNAL: For abort handling, see also Synopsys DWC_usb3 Databook v2.80a, Section 8.4. */
        uint32_t hipri_forcerm         : 1;  /**< [ 11: 11](R/W) HighPriority: Only valid for Start Transfer command.
                                                                 ForceRM: Only valid for End Transfer command. */
        uint32_t cmdact                : 1;  /**< [ 10: 10](R/W) Software sets this bit to 1 to enable the device endpoint controller to
                                                                 execute the generic command.
                                                                 The device controller sets this bit to 0 when the CMDSTATUS field is valid and
                                                                 the endpoint is ready to accept another command. This does not imply that
                                                                 all the effects of the previously-issued command have taken place. */
        uint32_t reserved_9            : 1;
        uint32_t cmdioc                : 1;  /**< [  8:  8](R/W) Command Interrupt on Complete.
                                                                 When this bit is set, the device controller issues a generic Endpoint
                                                                 Command Complete event after executing the command. Note that this
                                                                 interrupt is mapped to DEPCFG.IntrNum. When the DEPCFG command is
                                                                 executed, the command interrupt on completion goes to the interrupt
                                                                 pointed by the USBDRD()_UAHC_DCFG[INTRNUM] in the current command.
                                                                 Note: This field must not set to 1 if the USBDRD()_UAHC_DCTL[RS] field is 0. */
        uint32_t reserved_4_7          : 4;
        uint32_t cmdtyp                : 4;  /**< [  3:  0](R/W) Command Type.
                                                                 Specifies the type of command the software driver is requesting the core to
                                                                 perform.
                                                                 0x0 = Reserved.
                                                                 0x1 = Set Endpoint Configuration (64 or 96-bit Parameter).
                                                                 0x2 = Set Endpoint Transfer Resource Configuration (32-bit Parameter).
                                                                 0x3 = Get Endpoint State (No Parameter Needed).
                                                                 0x4 = Set Stall (No Parameter Needed).
                                                                 0x5 = Clear Stall (see Set Stall, No Parameter Needed).
                                                                 0x6 = Start Transfer (64-bit Parameter).
                                                                 0x7 = Update Transfer (No Parameter Needed).
                                                                 0x8 = End Transfer (No Parameter Needed).
                                                                 0x9 = Start New Configuration (No Parameter Needed). */
#else /* Word 0 - Little Endian */
        uint32_t cmdtyp                : 4;  /**< [  3:  0](R/W) Command Type.
                                                                 Specifies the type of command the software driver is requesting the core to
                                                                 perform.
                                                                 0x0 = Reserved.
                                                                 0x1 = Set Endpoint Configuration (64 or 96-bit Parameter).
                                                                 0x2 = Set Endpoint Transfer Resource Configuration (32-bit Parameter).
                                                                 0x3 = Get Endpoint State (No Parameter Needed).
                                                                 0x4 = Set Stall (No Parameter Needed).
                                                                 0x5 = Clear Stall (see Set Stall, No Parameter Needed).
                                                                 0x6 = Start Transfer (64-bit Parameter).
                                                                 0x7 = Update Transfer (No Parameter Needed).
                                                                 0x8 = End Transfer (No Parameter Needed).
                                                                 0x9 = Start New Configuration (No Parameter Needed). */
        uint32_t reserved_4_7          : 4;
        uint32_t cmdioc                : 1;  /**< [  8:  8](R/W) Command Interrupt on Complete.
                                                                 When this bit is set, the device controller issues a generic Endpoint
                                                                 Command Complete event after executing the command. Note that this
                                                                 interrupt is mapped to DEPCFG.IntrNum. When the DEPCFG command is
                                                                 executed, the command interrupt on completion goes to the interrupt
                                                                 pointed by the USBDRD()_UAHC_DCFG[INTRNUM] in the current command.
                                                                 Note: This field must not set to 1 if the USBDRD()_UAHC_DCTL[RS] field is 0. */
        uint32_t reserved_9            : 1;
        uint32_t cmdact                : 1;  /**< [ 10: 10](R/W) Software sets this bit to 1 to enable the device endpoint controller to
                                                                 execute the generic command.
                                                                 The device controller sets this bit to 0 when the CMDSTATUS field is valid and
                                                                 the endpoint is ready to accept another command. This does not imply that
                                                                 all the effects of the previously-issued command have taken place. */
        uint32_t hipri_forcerm         : 1;  /**< [ 11: 11](R/W) HighPriority: Only valid for Start Transfer command.
                                                                 ForceRM: Only valid for End Transfer command. */
        uint32_t cmdstatus             : 4;  /**< [ 15: 12](R/W) Command Completion Status.
                                                                 Additional information about the completion of this command is available in
                                                                 this field.

                                                                 Within an XferNotReady event:
                                                                 _ [15]: Indicates the reason why the XferNotReady event is generated:
                                                                 _ [15] = 0: XferNotActive: Host initiated a transfer, but the requested transfer is not
                                                                       present in the hardware.
                                                                 _ [15] = 1: XferActive: Host initiated a transfer, the transfer is present, but no valid
                                                                 TRBs
                                                                       are available
                                                                 _ [14]: Not Used
                                                                 _ [13:12]: For control endpoints, indicates what stage was requested when the transfer was
                                                                   not ready:
                                                                 _ [13:12] = 0x1: Control Data Request
                                                                 _ [13:12] = 0x2: Control Status Request

                                                                 Within an XferComplete or XferInProgress event:
                                                                 _ [15]: LST bit of the completed TRB (XferComplete only)
                                                                 _ [15]: MissedIsoc: Indicates the interval did not complete successfully (XferInProgress
                                                                   only)
                                                                 _ [14]: IOC bit of the TRB that completed.
                                                                 _ [13]: Indicates the TRB completed with a short packet reception or the last packet of an
                                                                   isochronous interval
                                                                 _ [12]: Reserved.
                                                                   If the host aborts the data stage of a control transfer, software may receive a
                                                                   XferComplete event with the EventStatus field equal to 0. This is a valid event
                                                                   that must be processed as a part of the Control Transfer Programming Model.

                                                                 Within a Stream Event:
                                                                 _ [15:12] = 0x2: StreamNotFound: This stream event is issued when the stream-capable
                                                                 endpoint
                                                                       performed a search in its transfer resource cache, but could not find an active
                                                                       and ready stream.
                                                                 _ [15:12] = 0x1: StreamFound: This stream event is issued when the stream-capable endpoint
                                                                 found
                                                                       an active and ready stream in its transfer resource cache, and initiated traffic for
                                                                       that stream to the host. The ID of the selected Stream is in the EventParam field.

                                                                     In response to a Start Transfer command:
                                                                 _ [15:12] = 0x2: Indicates expiry of the bus time reflected in the Start Transfer command.
                                                                 _ [15:12] = 0x1: Indicates there is no transfer resource available on the endpoint.

                                                                 In response to a Set Transfer Resource (DEPXFERCFG) command:
                                                                 _ [15:12] = 0x1: Indicates an error has occurred because software is requesting more
                                                                 transfer
                                                                       resources to be assigned than have been configured in the hardware.

                                                                 In response to a End Transfer command:
                                                                 _ [15:12] = 0x1: Indicates an invalid transfer resource was specified.
                                                                 INTERNAL: For abort handling, see also Synopsys DWC_usb3 Databook v2.80a, Section 8.4. */
        uint32_t commandparam          : 16; /**< [ 31: 16](R/W) Command or Event Parameters.
                                                                 When this register is written:

                                                                   Command Parameters:

                                                                     For Start Transfer command:
                                                                     _  - [31:16]: StreamID. The USB StreamID assigned to this transfer

                                                                     For Start Transfer command applied to an isochronous endpoint:
                                                                     _  - [31:16]: StartMicroFramNum: Indicates the (micro)frame number to
                                                                       which the first TRB applies

                                                                     For Update Transfer, End Transfer, and Start New Configuration
                                                                     commands:
                                                                     _  - [22:16]: Transfer Resource Index (XferRscIdx). The hardware-assigned
                                                                       transfer resource index for the transfer, which was returned
                                                                       in response to the Start Transfer command. The application
                                                                       software-assigned transfer resource index for a Start New
                                                                       Configuration command.

                                                                   When this register is read:

                                                                     For XferNotReady, XferComplete, and Stream events on Bulk Endpoints:
                                                                     _  - [31:16]: StreamID. Applies only to bulk endpoints that support streams. This
                                                                                  indicates the StreamID of the transfer for which the event is
                                                                                  generated
                                                                     For XferInProgress:
                                                                     _  - [31:16]: Isochronous Microframe Number (IsocMicroFrameNum): Indicates the
                                                                                  microframe number of the beginning of the interval that generated
                                                                                  the XferInProgress event (debug purposes only)
                                                                     For XferNotReady events on Isochronous Endpoints:
                                                                     _  - [31:16]: Isochronous Microframe Number (IsocMicroFrameNum). Indicates the
                                                                                  microframe number during which the endpoint was not ready

                                                                       Note: controller core represents USB bus time as a 14-bit value on the bus and also
                                                                       in the DSTS register (USBDRD()_UAHC_DSTS[SOFFN]), but as a 16-bit value in the
                                                                       XferNotReady event. Use the 16-bit value to interact with Isochronous endpoints via
                                                                       the StartXfer command. The extra two bits that the controller core produces will be
                                                                       necessary for handling wrap-around conditions in the interaction between software
                                                                       and hardware.

                                                                    For all EPCmdCmplt events
                                                                    _  - [27:24]: Command Type. The command type that completed (Valid only in a DEPEVT
                                                                                    event. Undefined when read from the
                                                                                    USBDRD()_UAHC_DEPCMD()[COMMANDPARAM] field).

                                                                    For EPCmdCmplt event in response to Start Transfer command:
                                                                    _  - [22:16]: Transfer Resource Index (XferRscIdx). The internal hardware transfer
                                                                                    resource index assigned to this transfer. This index must be used in
                                                                                    all Update Transfer and End Transfer commands. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_depcmdx_s cn; */
} bdk_usbdrdx_uahc_depcmdx_t;

static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=15)))
        return 0x86800000c80cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=15)))
        return 0x86800000c80cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("USBDRDX_UAHC_DEPCMDX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DEPCMDX(a,b) bdk_usbdrdx_uahc_depcmdx_t
#define bustype_BDK_USBDRDX_UAHC_DEPCMDX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DEPCMDX(a,b) "USBDRDX_UAHC_DEPCMDX"
#define device_bar_BDK_USBDRDX_UAHC_DEPCMDX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DEPCMDX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_DEPCMDX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_depcmdpar0_#
 *
 * Device Physical Endpoint-n Command Parameter 0 Register
 * This register indicates the physical endpoint command Parameter 0. It must be programmed
 * before issuing the command.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.2.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_depcmdpar0_x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t param0                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 0 */
#else /* Word 0 - Little Endian */
        uint32_t param0                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 0 */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_depcmdpar0_x_s cn; */
} bdk_usbdrdx_uahc_depcmdpar0_x_t;

static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR0_X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR0_X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=15)))
        return 0x86800000c808ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=15)))
        return 0x86800000c808ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("USBDRDX_UAHC_DEPCMDPAR0_X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) bdk_usbdrdx_uahc_depcmdpar0_x_t
#define bustype_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) "USBDRDX_UAHC_DEPCMDPAR0_X"
#define device_bar_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_DEPCMDPAR0_X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_depcmdpar1_#
 *
 * Device Physical Endpoint-n Command Parameter 1 Register
 * This register indicates the physical endpoint command Parameter 1. It must be programmed
 * before issuing the command.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.2.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_depcmdpar1_x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t param1                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 1 */
#else /* Word 0 - Little Endian */
        uint32_t param1                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 1 */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_depcmdpar1_x_s cn; */
} bdk_usbdrdx_uahc_depcmdpar1_x_t;

static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR1_X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR1_X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=15)))
        return 0x86800000c804ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=15)))
        return 0x86800000c804ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("USBDRDX_UAHC_DEPCMDPAR1_X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) bdk_usbdrdx_uahc_depcmdpar1_x_t
#define bustype_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) "USBDRDX_UAHC_DEPCMDPAR1_X"
#define device_bar_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_DEPCMDPAR1_X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_depcmdpar2_#
 *
 * Device Physical Endpoint-n Command Parameter 2 Register
 * This register indicates the physical endpoint command Parameter 2. It must be programmed
 * before issuing the command.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.2.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_depcmdpar2_x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t param2                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 2 */
#else /* Word 0 - Little Endian */
        uint32_t param2                : 32; /**< [ 31:  0](R/W) Physical endpoint command Parameter 2 */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_depcmdpar2_x_s cn; */
} bdk_usbdrdx_uahc_depcmdpar2_x_t;

static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR2_X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DEPCMDPAR2_X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=15)))
        return 0x86800000c800ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=15)))
        return 0x86800000c800ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0xf);
    __bdk_csr_fatal("USBDRDX_UAHC_DEPCMDPAR2_X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) bdk_usbdrdx_uahc_depcmdpar2_x_t
#define bustype_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) "USBDRDX_UAHC_DEPCMDPAR2_X"
#define device_bar_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_DEPCMDPAR2_X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_devten
 *
 * Device Event Enable Register
 * This register controls the generation of Device-Specific events.
 * If an enable bit is set to 0, the event will not be generated.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_devten_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t vndrdevtstrcveden     : 1;  /**< [ 12: 12](R/W) Vendor Device Test LMP Received Event. */
        uint32_t reserved_10_11        : 2;
        uint32_t errticerren           : 1;  /**< [  9:  9](R/W) Erratic Error Event Enable. */
        uint32_t reserved_8            : 1;
        uint32_t sofen                 : 1;  /**< [  7:  7](R/W) Start of (micro)Frame Enable.
                                                                 For debug purposes only; normally software must disable this event. */
        uint32_t u3l2l1suspen          : 1;  /**< [  6:  6](R/W) U3/L2-L1 Suspend Event Enable. */
        uint32_t hibernationreqevten   : 1;  /**< [  5:  5](R/W) This bit enables/disables the generation of the Hibernation Request Event.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t wkupevten             : 1;  /**< [  4:  4](R/W) Resume/Remote Wakeup Detected Event Enable. */
        uint32_t ulstcngen             : 1;  /**< [  3:  3](R/W) USB/Link State Change Event Enable. */
        uint32_t connectdoneen         : 1;  /**< [  2:  2](R/W) Connection Done Enable. */
        uint32_t usbrsten              : 1;  /**< [  1:  1](R/W) USB Reset Enable. */
        uint32_t disconnevten          : 1;  /**< [  0:  0](R/W) Disconnect Detected Event Enable. */
#else /* Word 0 - Little Endian */
        uint32_t disconnevten          : 1;  /**< [  0:  0](R/W) Disconnect Detected Event Enable. */
        uint32_t usbrsten              : 1;  /**< [  1:  1](R/W) USB Reset Enable. */
        uint32_t connectdoneen         : 1;  /**< [  2:  2](R/W) Connection Done Enable. */
        uint32_t ulstcngen             : 1;  /**< [  3:  3](R/W) USB/Link State Change Event Enable. */
        uint32_t wkupevten             : 1;  /**< [  4:  4](R/W) Resume/Remote Wakeup Detected Event Enable. */
        uint32_t hibernationreqevten   : 1;  /**< [  5:  5](R/W) This bit enables/disables the generation of the Hibernation Request Event.
                                                                 INTERNAL: Writing this bit to 0x1 does nothing since we don't have hibernation feature. */
        uint32_t u3l2l1suspen          : 1;  /**< [  6:  6](R/W) U3/L2-L1 Suspend Event Enable. */
        uint32_t sofen                 : 1;  /**< [  7:  7](R/W) Start of (micro)Frame Enable.
                                                                 For debug purposes only; normally software must disable this event. */
        uint32_t reserved_8            : 1;
        uint32_t errticerren           : 1;  /**< [  9:  9](R/W) Erratic Error Event Enable. */
        uint32_t reserved_10_11        : 2;
        uint32_t vndrdevtstrcveden     : 1;  /**< [ 12: 12](R/W) Vendor Device Test LMP Received Event. */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_devten_s cn; */
} bdk_usbdrdx_uahc_devten_t;

static inline uint64_t BDK_USBDRDX_UAHC_DEVTEN(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DEVTEN(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c708ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c708ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DEVTEN", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DEVTEN(a) bdk_usbdrdx_uahc_devten_t
#define bustype_BDK_USBDRDX_UAHC_DEVTEN(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DEVTEN(a) "USBDRDX_UAHC_DEVTEN"
#define device_bar_BDK_USBDRDX_UAHC_DEVTEN(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DEVTEN(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DEVTEN(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dgcmd
 *
 * Device Generic Command Register
 * This register enables software to program the core using a single generic command interface to
 * send link management packets and notifications. This register contains command, control, and
 * status fields relevant to the current generic command, while the USBDRD()_UAHC_DGCMDPAR
 * register provides the command parameter.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dgcmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t cmdstatus             : 1;  /**< [ 15: 15](RO) Command Status.
                                                                  0 = Indicates command success.
                                                                  1 = CmdErr - Indicates that the device controller encountered an error
                                                                     while processing the command. */
        uint32_t reserved_11_14        : 4;
        uint32_t cmdact                : 1;  /**< [ 10: 10](R/W1S/H) Command Active.
                                                                 The software sets this bit to 1 to enable the device controller to execute the
                                                                 generic command.
                                                                 The device controller sets this bit to 0 after executing the command. */
        uint32_t reserved_9            : 1;
        uint32_t cmdioc                : 1;  /**< [  8:  8](WO) Command Interrupt on Complete.
                                                                 When this bit is set, the device controller issues a Generic Command
                                                                 Completion event after executing the command. Note that this interrupt is
                                                                 mapped to USBDRD()_UAHC_DCFG[INTRNUM].
                                                                 Note: This field must not set to 1 if the USBDRD()_UAHC_DCTL[RS] field is 0. */
        uint32_t cmdtyp                : 8;  /**< [  7:  0](WO) Specifies the type of command the software driver is requesting the core to
                                                                 perform. See USBDRD_UAHC_DGCMD_CMDTYPE_E for encodings and usage. */
#else /* Word 0 - Little Endian */
        uint32_t cmdtyp                : 8;  /**< [  7:  0](WO) Specifies the type of command the software driver is requesting the core to
                                                                 perform. See USBDRD_UAHC_DGCMD_CMDTYPE_E for encodings and usage. */
        uint32_t cmdioc                : 1;  /**< [  8:  8](WO) Command Interrupt on Complete.
                                                                 When this bit is set, the device controller issues a Generic Command
                                                                 Completion event after executing the command. Note that this interrupt is
                                                                 mapped to USBDRD()_UAHC_DCFG[INTRNUM].
                                                                 Note: This field must not set to 1 if the USBDRD()_UAHC_DCTL[RS] field is 0. */
        uint32_t reserved_9            : 1;
        uint32_t cmdact                : 1;  /**< [ 10: 10](R/W1S/H) Command Active.
                                                                 The software sets this bit to 1 to enable the device controller to execute the
                                                                 generic command.
                                                                 The device controller sets this bit to 0 after executing the command. */
        uint32_t reserved_11_14        : 4;
        uint32_t cmdstatus             : 1;  /**< [ 15: 15](RO) Command Status.
                                                                  0 = Indicates command success.
                                                                  1 = CmdErr - Indicates that the device controller encountered an error
                                                                     while processing the command. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dgcmd_s cn; */
} bdk_usbdrdx_uahc_dgcmd_t;

static inline uint64_t BDK_USBDRDX_UAHC_DGCMD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DGCMD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c714ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c714ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DGCMD", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DGCMD(a) bdk_usbdrdx_uahc_dgcmd_t
#define bustype_BDK_USBDRDX_UAHC_DGCMD(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DGCMD(a) "USBDRDX_UAHC_DGCMD"
#define device_bar_BDK_USBDRDX_UAHC_DGCMD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DGCMD(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DGCMD(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dgcmdpar
 *
 * Device Generic Command Parameter Register
 * This register indicates the device command parameter.
 * This must be programmed before or along with USBDRD()_UAHC_DGCMD.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST] or
 * USBDRD()_UAHC_GCTL[CORESOFTRESET] or
 * USBDRD()_UAHC_USBCMD[HCRST] or USBDRD()_UAHC_USBCMD[LHCRST] or
 * USBDRD()_UAHC_DCTL[CSFTRST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dgcmdpar_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t param                 : 32; /**< [ 31:  0](R/W) Device Generic Command Parameter.
                                                                 Usage depends on which USBDRD()_UAHC_DGCMD[CMDTYPE] is used,
                                                                 see usage notes in USBDRD_UAHC_DGCMD_CMDTYPE_E descriptions. */
#else /* Word 0 - Little Endian */
        uint32_t param                 : 32; /**< [ 31:  0](R/W) Device Generic Command Parameter.
                                                                 Usage depends on which USBDRD()_UAHC_DGCMD[CMDTYPE] is used,
                                                                 see usage notes in USBDRD_UAHC_DGCMD_CMDTYPE_E descriptions. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dgcmdpar_s cn; */
} bdk_usbdrdx_uahc_dgcmdpar_t;

static inline uint64_t BDK_USBDRDX_UAHC_DGCMDPAR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DGCMDPAR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c710ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c710ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DGCMDPAR", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DGCMDPAR(a) bdk_usbdrdx_uahc_dgcmdpar_t
#define bustype_BDK_USBDRDX_UAHC_DGCMDPAR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DGCMDPAR(a) "USBDRDX_UAHC_DGCMDPAR"
#define device_bar_BDK_USBDRDX_UAHC_DGCMDPAR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DGCMDPAR(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DGCMDPAR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dnctrl
 *
 * XHCI Device Notification Control Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.4.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dnctrl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t n                     : 16; /**< [ 15:  0](R/W) Notification enable. */
#else /* Word 0 - Little Endian */
        uint32_t n                     : 16; /**< [ 15:  0](R/W) Notification enable. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dnctrl_s cn; */
} bdk_usbdrdx_uahc_dnctrl_t;

static inline uint64_t BDK_USBDRDX_UAHC_DNCTRL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DNCTRL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000034ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000034ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DNCTRL", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DNCTRL(a) bdk_usbdrdx_uahc_dnctrl_t
#define bustype_BDK_USBDRDX_UAHC_DNCTRL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DNCTRL(a) "USBDRDX_UAHC_DNCTRL"
#define device_bar_BDK_USBDRDX_UAHC_DNCTRL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DNCTRL(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DNCTRL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_dsts
 *
 * Device Status Register
 * This register indicates the status of the device controller with respect to USB-related
 * events.
 *
 * This register can be reset by IOI reset or USBDRD()_UCTL_CTL[UAHC_RST].
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.3.1.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_dsts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t dcnrd                 : 1;  /**< [ 29: 29](RO/H) Device Controller Not Ready.
                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t sre                   : 1;  /**< [ 28: 28](R/W1C/H) Save/Restore Error.
                                                                 This bit is currently not supported. */
        uint32_t reserved_26_27        : 2;
        uint32_t rss                   : 1;  /**< [ 25: 25](RO) Restore State Status.
                                                                 This bit is similar to the USBDRD()_USBSTS[RSS] in host mode.
                                                                 When the controller has finished the restore process, it will complete the
                                                                 command by setting RSS to 0.

                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t sss                   : 1;  /**< [ 24: 24](RO) Save State Status.
                                                                 This bit is similar to the USBDRD()_UAHC_USBSTS[SSS] in host mode.
                                                                 When the controller has finished the save process, it will complete the
                                                                 command by setting SSS to 0.

                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t coreidle              : 1;  /**< [ 23: 23](RO/H) Core Idle.
                                                                 The bit indicates that the core finished transferring all RxFIFO data to
                                                                 system memory, writing out all completed descriptors, and all Event Counts
                                                                 are zero.

                                                                 Note: While testing for Reset values, mask out the read value. This bit
                                                                 represents the changing state of the core and does not hold a static value. */
        uint32_t devctrlhlt            : 1;  /**< [ 22: 22](RO/H) Device Controller Halted.
                                                                 When 1, the core does not generate Device events.
                                                                 - This bit is set to 0 when the USBDRD()_UAHC_DCTL[RS] register is set to 1.
                                                                 - The core sets this bit to 1 when, after software sets USBDRD()_UAHC_DCTL[RS] to 0,
                                                                 the core is
                                                                   idle and the lower layer finishes the disconnect process. */
        uint32_t usblnkst              : 4;  /**< [ 21: 18](RO/H) USB/Link State.
                                                                 In SuperSpeed mode, uses LTSSM State:
                                                                    0x0 = U0.
                                                                    0x1 = U1.
                                                                    0x2 = U2.
                                                                    0x3 = U3.
                                                                    0x4 = SS_DIS.
                                                                    0x5 = RX_DET.
                                                                    0x6 = SS_INACT.
                                                                    0x7 = POLL.
                                                                    0x8 = RECOV.
                                                                    0x9 = HRESET.
                                                                    0xa = CMPLY.
                                                                    0xb = LPBK.
                                                                    0xf = Resume/Reset.
                                                                    others: Reserved.

                                                                 In High/Full/LowSpeed mode:
                                                                    0x0 = On state.
                                                                    0x2 = Sleep (L1) state.
                                                                    0x3 = Suspend (L2) state.
                                                                    0x4 = Disconnected state (Default state).
                                                                    0x5 = Early Suspend state.
                                                                    others: Reserved.

                                                                 The link state Resume/Reset indicates that the core received a resume or
                                                                 USB reset request from the host while the link was in hibernation. Software
                                                                 must write '8' (Recovery) to the USBDRD()_UAHC_DCTL[ULSTCHNGREQ] field to acknowledge
                                                                 the resume/reset request. */
        uint32_t rxfifoempty           : 1;  /**< [ 17: 17](RO/H) RxFIFO Empty Indication. */
        uint32_t soffn                 : 14; /**< [ 16:  3](RO/H) Frame/MicroFrame Number of the Received SOF.

                                                                 When the core is operating at high-speed,
                                                                   <16:6> = Frame number.
                                                                   <5:3> = Microframe number.

                                                                 When the core is operating at full-speed,
                                                                   <16:14> = Not used, software can ignore these 3 bits.
                                                                   <13:3> = Frame number. */
        uint32_t connectspd            : 3;  /**< [  2:  0](RO/H) Connected Speed.
                                                                 Indicates the speed at which the controller core has come up after speed
                                                                 detection through a chirp sequence.
                                                                  0x0 = High-speed (PHY clock is running at 60 MHz).
                                                                  0x1 = Full-speed (PHY clock is running at 60 MHz).
                                                                  0x2 = Low-speed  (not supported).
                                                                  0x3 = Full-speed (PHY clock is running at 48 MHz).
                                                                  0x4 = SuperSpeed (PHY clock is running at 125 or 250 MHz). */
#else /* Word 0 - Little Endian */
        uint32_t connectspd            : 3;  /**< [  2:  0](RO/H) Connected Speed.
                                                                 Indicates the speed at which the controller core has come up after speed
                                                                 detection through a chirp sequence.
                                                                  0x0 = High-speed (PHY clock is running at 60 MHz).
                                                                  0x1 = Full-speed (PHY clock is running at 60 MHz).
                                                                  0x2 = Low-speed  (not supported).
                                                                  0x3 = Full-speed (PHY clock is running at 48 MHz).
                                                                  0x4 = SuperSpeed (PHY clock is running at 125 or 250 MHz). */
        uint32_t soffn                 : 14; /**< [ 16:  3](RO/H) Frame/MicroFrame Number of the Received SOF.

                                                                 When the core is operating at high-speed,
                                                                   <16:6> = Frame number.
                                                                   <5:3> = Microframe number.

                                                                 When the core is operating at full-speed,
                                                                   <16:14> = Not used, software can ignore these 3 bits.
                                                                   <13:3> = Frame number. */
        uint32_t rxfifoempty           : 1;  /**< [ 17: 17](RO/H) RxFIFO Empty Indication. */
        uint32_t usblnkst              : 4;  /**< [ 21: 18](RO/H) USB/Link State.
                                                                 In SuperSpeed mode, uses LTSSM State:
                                                                    0x0 = U0.
                                                                    0x1 = U1.
                                                                    0x2 = U2.
                                                                    0x3 = U3.
                                                                    0x4 = SS_DIS.
                                                                    0x5 = RX_DET.
                                                                    0x6 = SS_INACT.
                                                                    0x7 = POLL.
                                                                    0x8 = RECOV.
                                                                    0x9 = HRESET.
                                                                    0xa = CMPLY.
                                                                    0xb = LPBK.
                                                                    0xf = Resume/Reset.
                                                                    others: Reserved.

                                                                 In High/Full/LowSpeed mode:
                                                                    0x0 = On state.
                                                                    0x2 = Sleep (L1) state.
                                                                    0x3 = Suspend (L2) state.
                                                                    0x4 = Disconnected state (Default state).
                                                                    0x5 = Early Suspend state.
                                                                    others: Reserved.

                                                                 The link state Resume/Reset indicates that the core received a resume or
                                                                 USB reset request from the host while the link was in hibernation. Software
                                                                 must write '8' (Recovery) to the USBDRD()_UAHC_DCTL[ULSTCHNGREQ] field to acknowledge
                                                                 the resume/reset request. */
        uint32_t devctrlhlt            : 1;  /**< [ 22: 22](RO/H) Device Controller Halted.
                                                                 When 1, the core does not generate Device events.
                                                                 - This bit is set to 0 when the USBDRD()_UAHC_DCTL[RS] register is set to 1.
                                                                 - The core sets this bit to 1 when, after software sets USBDRD()_UAHC_DCTL[RS] to 0,
                                                                 the core is
                                                                   idle and the lower layer finishes the disconnect process. */
        uint32_t coreidle              : 1;  /**< [ 23: 23](RO/H) Core Idle.
                                                                 The bit indicates that the core finished transferring all RxFIFO data to
                                                                 system memory, writing out all completed descriptors, and all Event Counts
                                                                 are zero.

                                                                 Note: While testing for Reset values, mask out the read value. This bit
                                                                 represents the changing state of the core and does not hold a static value. */
        uint32_t sss                   : 1;  /**< [ 24: 24](RO) Save State Status.
                                                                 This bit is similar to the USBDRD()_UAHC_USBSTS[SSS] in host mode.
                                                                 When the controller has finished the save process, it will complete the
                                                                 command by setting SSS to 0.

                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t rss                   : 1;  /**< [ 25: 25](RO) Restore State Status.
                                                                 This bit is similar to the USBDRD()_USBSTS[RSS] in host mode.
                                                                 When the controller has finished the restore process, it will complete the
                                                                 command by setting RSS to 0.

                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t reserved_26_27        : 2;
        uint32_t sre                   : 1;  /**< [ 28: 28](R/W1C/H) Save/Restore Error.
                                                                 This bit is currently not supported. */
        uint32_t dcnrd                 : 1;  /**< [ 29: 29](RO/H) Device Controller Not Ready.
                                                                 Will always read-as-zero.
                                                                 INTERNAL: Bit is only used with hibernation. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_dsts_s cn; */
} bdk_usbdrdx_uahc_dsts_t;

static inline uint64_t BDK_USBDRDX_UAHC_DSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_DSTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c70cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c70cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_DSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_DSTS(a) bdk_usbdrdx_uahc_dsts_t
#define bustype_BDK_USBDRDX_UAHC_DSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_DSTS(a) "USBDRDX_UAHC_DSTS"
#define device_bar_BDK_USBDRDX_UAHC_DSTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_DSTS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_DSTS(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_erdp#
 *
 * XHCI Event Ring Dequeue Pointer Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.3.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_erdpx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t erdp                  : 60; /**< [ 63:  4](R/W) Event ring dequeue pointer bits <63:4>. */
        uint64_t ehb                   : 1;  /**< [  3:  3](R/W1C/H) Event handler busy */
        uint64_t desi                  : 3;  /**< [  2:  0](R/W) Dequeue ERST segment index. */
#else /* Word 0 - Little Endian */
        uint64_t desi                  : 3;  /**< [  2:  0](R/W) Dequeue ERST segment index. */
        uint64_t ehb                   : 1;  /**< [  3:  3](R/W1C/H) Event handler busy */
        uint64_t erdp                  : 60; /**< [ 63:  4](R/W) Event ring dequeue pointer bits <63:4>. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_erdpx_s cn; */
} bdk_usbdrdx_uahc_erdpx_t;

static inline uint64_t BDK_USBDRDX_UAHC_ERDPX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_ERDPX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000478ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000478ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_ERDPX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_ERDPX(a,b) bdk_usbdrdx_uahc_erdpx_t
#define bustype_BDK_USBDRDX_UAHC_ERDPX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_ERDPX(a,b) "USBDRDX_UAHC_ERDPX"
#define device_bar_BDK_USBDRDX_UAHC_ERDPX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_ERDPX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_ERDPX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uahc_erstba#
 *
 * XHCI Event-Ring Segment-Table Base-Address Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.2.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_erstbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t erstba                : 58; /**< [ 63:  6](R/W) Event-ring segment-table base-address bits<63:6>. */
        uint64_t reserved_0_5          : 6;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_5          : 6;
        uint64_t erstba                : 58; /**< [ 63:  6](R/W) Event-ring segment-table base-address bits<63:6>. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_erstbax_s cn; */
} bdk_usbdrdx_uahc_erstbax_t;

static inline uint64_t BDK_USBDRDX_UAHC_ERSTBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_ERSTBAX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000470ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000470ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_ERSTBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_ERSTBAX(a,b) bdk_usbdrdx_uahc_erstbax_t
#define bustype_BDK_USBDRDX_UAHC_ERSTBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_ERSTBAX(a,b) "USBDRDX_UAHC_ERSTBAX"
#define device_bar_BDK_USBDRDX_UAHC_ERSTBAX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_ERSTBAX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_ERSTBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_erstsz#
 *
 * XHCI Event-Ring Segment-Table Size Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.3.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_erstszx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t erstsz                : 16; /**< [ 15:  0](R/W) Event-ring segment-table size. */
#else /* Word 0 - Little Endian */
        uint32_t erstsz                : 16; /**< [ 15:  0](R/W) Event-ring segment-table size. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_erstszx_s cn; */
} bdk_usbdrdx_uahc_erstszx_t;

static inline uint64_t BDK_USBDRDX_UAHC_ERSTSZX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_ERSTSZX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000468ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000468ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_ERSTSZX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_ERSTSZX(a,b) bdk_usbdrdx_uahc_erstszx_t
#define bustype_BDK_USBDRDX_UAHC_ERSTSZX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_ERSTSZX(a,b) "USBDRDX_UAHC_ERSTSZX"
#define device_bar_BDK_USBDRDX_UAHC_ERSTSZX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_ERSTSZX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_ERSTSZX(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gbuserraddr
 *
 * UAHC Bus-Error-Address Register
 * When the AXI Master Bus returns Error response, the SoC Bus Error is generated. In the host
 * mode, the host_system_err port indicates this condition. In addition, it is also indicated in
 * USBDRD()_UAHC_USBSTS[HSE]. Due to the nature of AXI, it is possible that multiple AXI
 * transactions
 * are active at a time. The host controller does not keep track of the start address of all
 * outstanding transactions. Instead, it keeps track of the start address of the DMA transfer
 * associated with all active transactions. It is this address that is reported in
 * USBDRD()_UAHC_GBUSERRADDR when a bus error occurs. For example, if the host controller
 * initiates
 * a DMA
 * transfer to write 1k of packet data starting at buffer address 0xABCD0000, and this DMA is
 * broken up into multiple 256B bursts on the AXI, then if a bus error occurs on any of these
 * associated AXI transfers, USBDRD()_UAHC_GBUSERRADDR reflects the DMA start address of
 * 0xABCD0000
 * regardless of which AXI transaction received the error.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.12.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gbuserraddr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t busaddr               : 64; /**< [ 63:  0](RO/H) Bus address. Contains the first bus address that encountered an SoC bus error. It is valid
                                                                 when the USBDRD()_UAHC_GSTS[BUSERRADDRVLD] = 1. It can only be cleared by resetting the
                                                                 core. */
#else /* Word 0 - Little Endian */
        uint64_t busaddr               : 64; /**< [ 63:  0](RO/H) Bus address. Contains the first bus address that encountered an SoC bus error. It is valid
                                                                 when the USBDRD()_UAHC_GSTS[BUSERRADDRVLD] = 1. It can only be cleared by resetting the
                                                                 core. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gbuserraddr_s cn; */
} bdk_usbdrdx_uahc_gbuserraddr_t;

static inline uint64_t BDK_USBDRDX_UAHC_GBUSERRADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GBUSERRADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c130ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c130ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GBUSERRADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GBUSERRADDR(a) bdk_usbdrdx_uahc_gbuserraddr_t
#define bustype_BDK_USBDRDX_UAHC_GBUSERRADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GBUSERRADDR(a) "USBDRDX_UAHC_GBUSERRADDR"
#define device_bar_BDK_USBDRDX_UAHC_GBUSERRADDR(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GBUSERRADDR(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GBUSERRADDR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gctl
 *
 * UAHC Control Register
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t pwrdnscale            : 13; /**< [ 31: 19](R/W) Power down scale. The USB3 suspend-clock input replaces pipe3_rx_pclk as a clock source to
                                                                 a small part of the USB3 core that operates when the SuperSpeed PHY is in its lowest power
                                                                 (P3) state, and therefore does not provide a clock. This field specifies how many suspend-
                                                                 clock periods fit into a 16 kHz clock period. When performing the division, round up the
                                                                 remainder.

                                                                 For example, when using an 32-bit PHY and 25-MHz suspend clock, PWRDNSCALE = 25000 kHz/16
                                                                 kHz = 1563 (rounded up).

                                                                 The minimum suspend-clock frequency is 32 KHz, and maximum suspend-clock frequency is 125
                                                                 MHz.

                                                                 The LTSSM uses Suspend clock for 12-ms and 100-ms timers during suspend mode. According to
                                                                 the USB 3.0 specification, the accuracy on these timers is 0% to +50%. 12 ms + 0~+50%
                                                                 accuracy = 18 ms (Range is 12 ms - 18 ms)
                                                                 100 ms + 0~+50% accuracy = 150 ms (Range is 100 ms - 150 ms).

                                                                 The suspend clock accuracy requirement is:
                                                                 _ (12,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 12,000 and
                                                                 18,000
                                                                 _ (100,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 100,000 and
                                                                 150,000

                                                                 For example, if your suspend_clk frequency varies from 7.5 MHz to 10.5MHz, then the value
                                                                 needs to programmed is: Power Down Scale = 10500/16 = 657 (rounded up; and fastest
                                                                 frequency used). */
        uint32_t masterfiltbypass      : 1;  /**< [ 18: 18](R/W) Master filter bypass. Not relevant for Cavium's configuration. */
        uint32_t bypssetaddr           : 1;  /**< [ 17: 17](R/W) Bypass SetAddress in Device Mode.
                                                                 Always set to 0.
                                                                 INTERNAL: When set, core uses the value in USBDRD()_UAHC_DCFG[DEVADDR] directly
                                                                 for comparing the device address tokens. In simulation, this can be used to avoid
                                                                 sending a SET_ADDRESS command. */
        uint32_t u2rstecn              : 1;  /**< [ 16: 16](R/W) If the SuperSpeed commenction fails during POLL or LMP exchange, the device connects
                                                                 at non-SuperSpeed mode. If this bit is set, then device attemps three more times to
                                                                 connect at SuperSpeed, even if it previously failed to operate in SuperSpeed mode.
                                                                 This bit is only applicable in device mode. */
        uint32_t frmscldwn             : 2;  /**< [ 15: 14](R/W) Frame scale down. Scales down device view of a SOF/USOF/ITP duration.
                                                                 For SuperSpeed/high-speed mode:
                                                                 0x0 = Interval is 125 us.
                                                                 0x1 = Interval is 62.5 us.
                                                                 0x2 = Interval is 31.25 us.
                                                                 0x3 = Interval is 15.625 us.

                                                                 For full-speed mode, the scale-down value is multiplied by 8. */
        uint32_t prtcapdir             : 2;  /**< [ 13: 12](R/W) 0x1 = for Host configurations.
                                                                 0x2 = for Device configurations. */
        uint32_t coresoftreset         : 1;  /**< [ 11: 11](R/W) Core soft reset: 1 = soft reset to core, 0 = no soft reset.
                                                                 Clears the interrupts and all the USBDRD()_UAHC_* CSRs except the
                                                                 following registers: USBDRD()_UAHC_GCTL, USBDRD()_UAHC_GUCTL, USBDRD()_UAHC_GSTS,
                                                                 USBDRD()_UAHC_GRLSID, USBDRD()_UAHC_GGPIO, USBDRD()_UAHC_GUID,
                                                                 USBDRD()_UAHC_GUSB2PHYCFG(),
                                                                 USBDRD()_UAHC_GUSB3PIPECTL().

                                                                 When you reset PHYs (using USBDRD()_UAHC_GUSB2PHYCFG() or
                                                                 USBDRD()_UAHC_GUSB3PIPECTL()), you must keep the core in reset state until PHY
                                                                 clocks are stable. This controls the bus, RAM, and MAC domain resets.

                                                                 INTERNAL: Refer to Reset Generation on Synopsys Databook page 250.
                                                                 Under soft reset, accesses to USBDRD()_UAHC_* CSRs other than USBDRD()_UAHC_GCTL may fail
                                                                 (timeout).
                                                                 This bit is for debug purposes only. Use USBDRD()_UAHC_USBCMD[HCRST] for soft reset. */
        uint32_t sofitpsync            : 1;  /**< [ 10: 10](R/W) Synchronize ITP to reference clock. In host mode, if this bit is set to:
                                                                 0 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever
                                                                 there is a SuperSpeed port that is not in Rx.Detect, SS.Disable, and U3 state.
                                                                 1 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever the
                                                                 other non-SuperSpeed ports are not in suspended state.

                                                                 This feature is useful because it saves power by suspending UTMI/ULPI when SuperSpeed only
                                                                 is active and it helps resolve when the PHY does not transmit a host resume unless it is
                                                                 placed in suspend state.
                                                                 USBDRD()_UAHC_GUSB2PHYCFG()[SUSPHY] eventually decides to put the UTMI/ULPI PHY in to
                                                                 suspend
                                                                 state. In addition, when this bit is set to 1, the core generates ITP off of the REF_CLK-
                                                                 based counter. Otherwise, ITP and SOF are generated off of UTMI/ULPI_CLK[0] based counter.

                                                                 To program the reference clock period inside the core, refer to
                                                                 USBDRD()_UAHC_GUCTL[REFCLKPER].

                                                                 If you do not plan to ever use this feature or the
                                                                 USBDRD()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL]
                                                                 feature, the minimum frequency for the ref_clk can be as low as 32KHz. You can connect the
                                                                 SUSPEND_CLK (as low as 32 KHz) to REF_CLK.

                                                                 If you plan to enable hardware-based LPM (PORTPMSC[HLE] = 1), this feature cannot be used.
                                                                 Turn off this feature by setting this bit to zero and use the
                                                                 USBDRD()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL] feature.

                                                                 If you set this bit to 1, the USBDRD()_UAHC_GUSB2PHYCFG() [U2_FREECLK_EXISTS] bit must be
                                                                 set to
                                                                 0. */
        uint32_t u1u2timerscale        : 1;  /**< [  9:  9](R/W) Disable U1/U2 timer scaledown. If set to 1, along with SCALEDOWN = 0x1, disables the scale
                                                                 down of U1/U2 inactive timer values.
                                                                 This is for simulation mode only. */
        uint32_t debugattach           : 1;  /**< [  8:  8](R/W) Debug attach. When this bit is set:
                                                                 * SuperSpeed link proceeds directly to the polling-link state (USBDRD()_UAHC_DCTL[RS] = 1)
                                                                 without checking remote termination.
                                                                 * Link LFPS polling timeout is infinite
                                                                 * Polling timeout during TS1 is infinite (in case link is waiting for TXEQ to finish). */
        uint32_t ramclksel             : 2;  /**< [  7:  6](R/W) RAM clock select. Always keep set to 0x0. */
        uint32_t scaledown             : 2;  /**< [  5:  4](R/W) Scale-down mode. When scale-down mode is enabled for simulation, the core uses scaled-down
                                                                 timing values, resulting in faster simulations. When scale-down mode is disabled, actual
                                                                 timing values are used. This is required for hardware operation.

                                                                 High-speed/full-speed/low-speed modes:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scale-down of all timing values. These include:
                                                                 * Speed enumeration
                                                                 * HNP/SRP
                                                                 * Suspend and resume

                                                                 0x2 = N/A
                                                                 0x3 = Enables bits <0> and <1> scale-down timing values.

                                                                 SuperSpeed mode:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scaled down SuperSpeed timing and repeat values including:
                                                                 * Number of TxEq training sequences reduce to eight
                                                                 * LFPS polling burst time reduce to 100 ns
                                                                 * LFPS warm reset receive reduce to 30 us.

                                                                 INTERNAL: Refer to the rtl_vip_scaledown_mapping.xls file under <workspace>/sim/SoC_sim
                                                                 directory for the complete list.
                                                                 0x2 = No TxEq training sequences are sent. Overrides bit<4>.
                                                                 0x3 = Enables bits<0> and <1> scale-down timing values. */
        uint32_t disscramble           : 1;  /**< [  3:  3](R/W) Disable scrambling. Transmit request to link partner on next transition to recovery or polling. */
        uint32_t u2exit_lfps           : 1;  /**< [  2:  2](R/W) LFPS U2 exit.
                                                                 0 = The link treats 248ns LFPS as a valid U2 exit.
                                                                 1 = The link waits for 8us of LFPS before it detects a valid U2 exit.

                                                                 This bit is added to improve interoperability with a third party host controller. This
                                                                 host controller in U2 state while performing receiver detection generates an LFPS glitch
                                                                 of about 4s duration. This causes the device to exit from U2 state because the LFPS filter
                                                                 value is 248ns. With the new functionality enabled, the device can stay in U2 while
                                                                 ignoring this glitch from the host controller. */
        uint32_t reserved_1            : 1;
        uint32_t dsblclkgtng           : 1;  /**< [  0:  0](R/W) Disable clock gating. When set to 1 and the core is in low-power mode, internal clock
                                                                 gating is disabled, which means the clocks are always running. This bit can be set to 1
                                                                 after power-up reset. */
#else /* Word 0 - Little Endian */
        uint32_t dsblclkgtng           : 1;  /**< [  0:  0](R/W) Disable clock gating. When set to 1 and the core is in low-power mode, internal clock
                                                                 gating is disabled, which means the clocks are always running. This bit can be set to 1
                                                                 after power-up reset. */
        uint32_t reserved_1            : 1;
        uint32_t u2exit_lfps           : 1;  /**< [  2:  2](R/W) LFPS U2 exit.
                                                                 0 = The link treats 248ns LFPS as a valid U2 exit.
                                                                 1 = The link waits for 8us of LFPS before it detects a valid U2 exit.

                                                                 This bit is added to improve interoperability with a third party host controller. This
                                                                 host controller in U2 state while performing receiver detection generates an LFPS glitch
                                                                 of about 4s duration. This causes the device to exit from U2 state because the LFPS filter
                                                                 value is 248ns. With the new functionality enabled, the device can stay in U2 while
                                                                 ignoring this glitch from the host controller. */
        uint32_t disscramble           : 1;  /**< [  3:  3](R/W) Disable scrambling. Transmit request to link partner on next transition to recovery or polling. */
        uint32_t scaledown             : 2;  /**< [  5:  4](R/W) Scale-down mode. When scale-down mode is enabled for simulation, the core uses scaled-down
                                                                 timing values, resulting in faster simulations. When scale-down mode is disabled, actual
                                                                 timing values are used. This is required for hardware operation.

                                                                 High-speed/full-speed/low-speed modes:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scale-down of all timing values. These include:
                                                                 * Speed enumeration
                                                                 * HNP/SRP
                                                                 * Suspend and resume

                                                                 0x2 = N/A
                                                                 0x3 = Enables bits <0> and <1> scale-down timing values.

                                                                 SuperSpeed mode:
                                                                 0x0 = Disables all scale-downs. Actual timing values are used.
                                                                 0x1 = Enables scaled down SuperSpeed timing and repeat values including:
                                                                 * Number of TxEq training sequences reduce to eight
                                                                 * LFPS polling burst time reduce to 100 ns
                                                                 * LFPS warm reset receive reduce to 30 us.

                                                                 INTERNAL: Refer to the rtl_vip_scaledown_mapping.xls file under <workspace>/sim/SoC_sim
                                                                 directory for the complete list.
                                                                 0x2 = No TxEq training sequences are sent. Overrides bit<4>.
                                                                 0x3 = Enables bits<0> and <1> scale-down timing values. */
        uint32_t ramclksel             : 2;  /**< [  7:  6](R/W) RAM clock select. Always keep set to 0x0. */
        uint32_t debugattach           : 1;  /**< [  8:  8](R/W) Debug attach. When this bit is set:
                                                                 * SuperSpeed link proceeds directly to the polling-link state (USBDRD()_UAHC_DCTL[RS] = 1)
                                                                 without checking remote termination.
                                                                 * Link LFPS polling timeout is infinite
                                                                 * Polling timeout during TS1 is infinite (in case link is waiting for TXEQ to finish). */
        uint32_t u1u2timerscale        : 1;  /**< [  9:  9](R/W) Disable U1/U2 timer scaledown. If set to 1, along with SCALEDOWN = 0x1, disables the scale
                                                                 down of U1/U2 inactive timer values.
                                                                 This is for simulation mode only. */
        uint32_t sofitpsync            : 1;  /**< [ 10: 10](R/W) Synchronize ITP to reference clock. In host mode, if this bit is set to:
                                                                 0 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever
                                                                 there is a SuperSpeed port that is not in Rx.Detect, SS.Disable, and U3 state.
                                                                 1 = The core keeps the UTMI/ULPI PHY on the first port in non-suspended state whenever the
                                                                 other non-SuperSpeed ports are not in suspended state.

                                                                 This feature is useful because it saves power by suspending UTMI/ULPI when SuperSpeed only
                                                                 is active and it helps resolve when the PHY does not transmit a host resume unless it is
                                                                 placed in suspend state.
                                                                 USBDRD()_UAHC_GUSB2PHYCFG()[SUSPHY] eventually decides to put the UTMI/ULPI PHY in to
                                                                 suspend
                                                                 state. In addition, when this bit is set to 1, the core generates ITP off of the REF_CLK-
                                                                 based counter. Otherwise, ITP and SOF are generated off of UTMI/ULPI_CLK[0] based counter.

                                                                 To program the reference clock period inside the core, refer to
                                                                 USBDRD()_UAHC_GUCTL[REFCLKPER].

                                                                 If you do not plan to ever use this feature or the
                                                                 USBDRD()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL]
                                                                 feature, the minimum frequency for the ref_clk can be as low as 32KHz. You can connect the
                                                                 SUSPEND_CLK (as low as 32 KHz) to REF_CLK.

                                                                 If you plan to enable hardware-based LPM (PORTPMSC[HLE] = 1), this feature cannot be used.
                                                                 Turn off this feature by setting this bit to zero and use the
                                                                 USBDRD()_UAHC_GFLADJ[GFLADJ_REFCLK_LPM_SEL] feature.

                                                                 If you set this bit to 1, the USBDRD()_UAHC_GUSB2PHYCFG() [U2_FREECLK_EXISTS] bit must be
                                                                 set to
                                                                 0. */
        uint32_t coresoftreset         : 1;  /**< [ 11: 11](R/W) Core soft reset: 1 = soft reset to core, 0 = no soft reset.
                                                                 Clears the interrupts and all the USBDRD()_UAHC_* CSRs except the
                                                                 following registers: USBDRD()_UAHC_GCTL, USBDRD()_UAHC_GUCTL, USBDRD()_UAHC_GSTS,
                                                                 USBDRD()_UAHC_GRLSID, USBDRD()_UAHC_GGPIO, USBDRD()_UAHC_GUID,
                                                                 USBDRD()_UAHC_GUSB2PHYCFG(),
                                                                 USBDRD()_UAHC_GUSB3PIPECTL().

                                                                 When you reset PHYs (using USBDRD()_UAHC_GUSB2PHYCFG() or
                                                                 USBDRD()_UAHC_GUSB3PIPECTL()), you must keep the core in reset state until PHY
                                                                 clocks are stable. This controls the bus, RAM, and MAC domain resets.

                                                                 INTERNAL: Refer to Reset Generation on Synopsys Databook page 250.
                                                                 Under soft reset, accesses to USBDRD()_UAHC_* CSRs other than USBDRD()_UAHC_GCTL may fail
                                                                 (timeout).
                                                                 This bit is for debug purposes only. Use USBDRD()_UAHC_USBCMD[HCRST] for soft reset. */
        uint32_t prtcapdir             : 2;  /**< [ 13: 12](R/W) 0x1 = for Host configurations.
                                                                 0x2 = for Device configurations. */
        uint32_t frmscldwn             : 2;  /**< [ 15: 14](R/W) Frame scale down. Scales down device view of a SOF/USOF/ITP duration.
                                                                 For SuperSpeed/high-speed mode:
                                                                 0x0 = Interval is 125 us.
                                                                 0x1 = Interval is 62.5 us.
                                                                 0x2 = Interval is 31.25 us.
                                                                 0x3 = Interval is 15.625 us.

                                                                 For full-speed mode, the scale-down value is multiplied by 8. */
        uint32_t u2rstecn              : 1;  /**< [ 16: 16](R/W) If the SuperSpeed commenction fails during POLL or LMP exchange, the device connects
                                                                 at non-SuperSpeed mode. If this bit is set, then device attemps three more times to
                                                                 connect at SuperSpeed, even if it previously failed to operate in SuperSpeed mode.
                                                                 This bit is only applicable in device mode. */
        uint32_t bypssetaddr           : 1;  /**< [ 17: 17](R/W) Bypass SetAddress in Device Mode.
                                                                 Always set to 0.
                                                                 INTERNAL: When set, core uses the value in USBDRD()_UAHC_DCFG[DEVADDR] directly
                                                                 for comparing the device address tokens. In simulation, this can be used to avoid
                                                                 sending a SET_ADDRESS command. */
        uint32_t masterfiltbypass      : 1;  /**< [ 18: 18](R/W) Master filter bypass. Not relevant for Cavium's configuration. */
        uint32_t pwrdnscale            : 13; /**< [ 31: 19](R/W) Power down scale. The USB3 suspend-clock input replaces pipe3_rx_pclk as a clock source to
                                                                 a small part of the USB3 core that operates when the SuperSpeed PHY is in its lowest power
                                                                 (P3) state, and therefore does not provide a clock. This field specifies how many suspend-
                                                                 clock periods fit into a 16 kHz clock period. When performing the division, round up the
                                                                 remainder.

                                                                 For example, when using an 32-bit PHY and 25-MHz suspend clock, PWRDNSCALE = 25000 kHz/16
                                                                 kHz = 1563 (rounded up).

                                                                 The minimum suspend-clock frequency is 32 KHz, and maximum suspend-clock frequency is 125
                                                                 MHz.

                                                                 The LTSSM uses Suspend clock for 12-ms and 100-ms timers during suspend mode. According to
                                                                 the USB 3.0 specification, the accuracy on these timers is 0% to +50%. 12 ms + 0~+50%
                                                                 accuracy = 18 ms (Range is 12 ms - 18 ms)
                                                                 100 ms + 0~+50% accuracy = 150 ms (Range is 100 ms - 150 ms).

                                                                 The suspend clock accuracy requirement is:
                                                                 _ (12,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 12,000 and
                                                                 18,000
                                                                 _ (100,000/62.5) * (GCTL[31:19]) * actual suspend_clk_period should be between 100,000 and
                                                                 150,000

                                                                 For example, if your suspend_clk frequency varies from 7.5 MHz to 10.5MHz, then the value
                                                                 needs to programmed is: Power Down Scale = 10500/16 = 657 (rounded up; and fastest
                                                                 frequency used). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gctl_s cn; */
} bdk_usbdrdx_uahc_gctl_t;

static inline uint64_t BDK_USBDRDX_UAHC_GCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c110ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c110ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GCTL(a) bdk_usbdrdx_uahc_gctl_t
#define bustype_BDK_USBDRDX_UAHC_GCTL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GCTL(a) "USBDRDX_UAHC_GCTL"
#define device_bar_BDK_USBDRDX_UAHC_GCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GCTL(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GCTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbgbmu
 *
 * UAHC BMU Debug Register
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbgbmu_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bmu_bcu_dbg           : 24; /**< [ 31:  8](RO/H) BMU_BCU debug information. */
        uint32_t bmu_dcu_dbg           : 4;  /**< [  7:  4](RO/H) BMU_DCU debug information. */
        uint32_t bmu_ccu_dbg           : 4;  /**< [  3:  0](RO/H) BMU_CCU debug information. */
#else /* Word 0 - Little Endian */
        uint32_t bmu_ccu_dbg           : 4;  /**< [  3:  0](RO/H) BMU_CCU debug information. */
        uint32_t bmu_dcu_dbg           : 4;  /**< [  7:  4](RO/H) BMU_DCU debug information. */
        uint32_t bmu_bcu_dbg           : 24; /**< [ 31:  8](RO/H) BMU_BCU debug information. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbgbmu_s cn; */
} bdk_usbdrdx_uahc_gdbgbmu_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGBMU(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGBMU(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c16cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c16cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGBMU", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGBMU(a) bdk_usbdrdx_uahc_gdbgbmu_t
#define bustype_BDK_USBDRDX_UAHC_GDBGBMU(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGBMU(a) "USBDRDX_UAHC_GDBGBMU"
#define device_bar_BDK_USBDRDX_UAHC_GDBGBMU(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGBMU(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGBMU(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gdbgepinfo
 *
 * UAHC Endpoint Information Debug Register
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gdbgepinfo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t endpt_dbg             : 64; /**< [ 63:  0](RO/H) Endpoint debug information. */
#else /* Word 0 - Little Endian */
        uint64_t endpt_dbg             : 64; /**< [ 63:  0](RO/H) Endpoint debug information. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbgepinfo_s cn; */
} bdk_usbdrdx_uahc_gdbgepinfo_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGEPINFO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGEPINFO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c178ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c178ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGEPINFO", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGEPINFO(a) bdk_usbdrdx_uahc_gdbgepinfo_t
#define bustype_BDK_USBDRDX_UAHC_GDBGEPINFO(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GDBGEPINFO(a) "USBDRDX_UAHC_GDBGEPINFO"
#define device_bar_BDK_USBDRDX_UAHC_GDBGEPINFO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGEPINFO(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGEPINFO(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbgfifospace
 *
 * UAHC Debug FIFO Space Available Register
 * This register is for debug purposes. It provides debug information on the internal status and
 * state machines. Global debug registers have design-specific information, and are used by state
 * machines. Global debug registers have design-specific information, and are used for debugging
 * purposes. These registers are not intended to be used by the customer. If any debug assistance
 * is needed for the silicon, contact customer support with a dump of these registers.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.2.
 * INTERNAL: Contact Synopsys directly.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbgfifospace_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t spaceavailable        : 16; /**< [ 31: 16](RO/H) Space available in the selected FIFO. */
        uint32_t reserved_9_15         : 7;
        uint32_t select                : 9;  /**< [  8:  0](R/W) FIFO/queue select/port-select.
                                                                 FIFO/queue select: <7:5> indicates the FIFO/queue type; <4:0> indicates the FIFO/queue
                                                                 number.
                                                                 For example, 0x21 refers to RxFIFO_1, and 0x5E refers to TxReqQ_30.
                                                                 0x1F-0x0: TxFIFO_31 to TxFIFO_0.
                                                                 0x3F-0x20: RxFIFO_31 to RxFIFO_0.
                                                                 0x5F-0x40: TxReqQ_31 to TxReqQ_0.
                                                                 0x7F-0x60: RxReqQ_31 to RxReqQ_0.
                                                                 0x9F-0x80: RxInfoQ_31 to RxInfoQ_0.
                                                                 0xA0: DescFetchQ.
                                                                 0xA1: EventQ.
                                                                 0xA2: ProtocolStatusQ.

                                                                 Port-select: <3:0> selects the port-number when accessing USBDRD()_UAHC_GDBGLTSSM. */
#else /* Word 0 - Little Endian */
        uint32_t select                : 9;  /**< [  8:  0](R/W) FIFO/queue select/port-select.
                                                                 FIFO/queue select: <7:5> indicates the FIFO/queue type; <4:0> indicates the FIFO/queue
                                                                 number.
                                                                 For example, 0x21 refers to RxFIFO_1, and 0x5E refers to TxReqQ_30.
                                                                 0x1F-0x0: TxFIFO_31 to TxFIFO_0.
                                                                 0x3F-0x20: RxFIFO_31 to RxFIFO_0.
                                                                 0x5F-0x40: TxReqQ_31 to TxReqQ_0.
                                                                 0x7F-0x60: RxReqQ_31 to RxReqQ_0.
                                                                 0x9F-0x80: RxInfoQ_31 to RxInfoQ_0.
                                                                 0xA0: DescFetchQ.
                                                                 0xA1: EventQ.
                                                                 0xA2: ProtocolStatusQ.

                                                                 Port-select: <3:0> selects the port-number when accessing USBDRD()_UAHC_GDBGLTSSM. */
        uint32_t reserved_9_15         : 7;
        uint32_t spaceavailable        : 16; /**< [ 31: 16](RO/H) Space available in the selected FIFO. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbgfifospace_s cn; */
} bdk_usbdrdx_uahc_gdbgfifospace_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGFIFOSPACE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGFIFOSPACE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c160ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c160ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGFIFOSPACE", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) bdk_usbdrdx_uahc_gdbgfifospace_t
#define bustype_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) "USBDRDX_UAHC_GDBGFIFOSPACE"
#define device_bar_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGFIFOSPACE(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbglnmcc
 *
 * UAHC LNMCC Debug Register
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbglnmcc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_9_31         : 23;
        uint32_t lnmcc_berc            : 9;  /**< [  8:  0](RO/H) This field indicates the bit-error-rate information for the port selected in
                                                                 USBDRD()_UAHC_GDBGFIFOSPACE[SELECT] (port-select).
                                                                 This field is for debug purposes only. */
#else /* Word 0 - Little Endian */
        uint32_t lnmcc_berc            : 9;  /**< [  8:  0](RO/H) This field indicates the bit-error-rate information for the port selected in
                                                                 USBDRD()_UAHC_GDBGFIFOSPACE[SELECT] (port-select).
                                                                 This field is for debug purposes only. */
        uint32_t reserved_9_31         : 23;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbglnmcc_s cn; */
} bdk_usbdrdx_uahc_gdbglnmcc_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGLNMCC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGLNMCC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c168ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c168ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGLNMCC", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGLNMCC(a) bdk_usbdrdx_uahc_gdbglnmcc_t
#define bustype_BDK_USBDRDX_UAHC_GDBGLNMCC(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGLNMCC(a) "USBDRDX_UAHC_GDBGLNMCC"
#define device_bar_BDK_USBDRDX_UAHC_GDBGLNMCC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGLNMCC(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGLNMCC(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbglsp
 *
 * UAHC LSP Debug Register
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbglsp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lsp_dbg               : 32; /**< [ 31:  0](RO/H) LSP debug information. */
#else /* Word 0 - Little Endian */
        uint32_t lsp_dbg               : 32; /**< [ 31:  0](RO/H) LSP debug information. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbglsp_s cn; */
} bdk_usbdrdx_uahc_gdbglsp_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGLSP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGLSP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c174ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c174ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGLSP", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGLSP(a) bdk_usbdrdx_uahc_gdbglsp_t
#define bustype_BDK_USBDRDX_UAHC_GDBGLSP(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGLSP(a) "USBDRDX_UAHC_GDBGLSP"
#define device_bar_BDK_USBDRDX_UAHC_GDBGLSP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGLSP(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGLSP(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbglspmux
 *
 * UAHC LSP Multiplexer Debug Register
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.6.
 * INTERNAL: This register is for Synopsys internal use only.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbglspmux_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t latraceportmuxselect  : 8;  /**< [ 23: 16](R/W) logic_analyzer_trace port multiplexer select. Only bits<21:16> are used. For details on
                                                                 how the mux controls the debug traces, refer to the Verilog file.
                                                                 A value of 0x3F drives 0s on the logic_analyzer_trace signal. If you plan to OR (instead
                                                                 using a mux) this signal with other trace signals in your system to generate a common
                                                                 trace signal, you can use this feature. */
        uint32_t endbc                 : 1;  /**< [ 15: 15](R/W) Enable debugging of the debug capability LSP. Use HOSTSELECT to select the DbC LSP debug
                                                                 information presented in the GDBGLSP register.
                                                                 INTERNAL: Note this can only be used if DebugCapabaility was enabled at compile. */
        uint32_t reserved_14           : 1;
        uint32_t hostselect            : 14; /**< [ 13:  0](R/W) Host select. Selects the LSP debug information presented in USBDRD()_UAHC_GDBGLSP. */
#else /* Word 0 - Little Endian */
        uint32_t hostselect            : 14; /**< [ 13:  0](R/W) Host select. Selects the LSP debug information presented in USBDRD()_UAHC_GDBGLSP. */
        uint32_t reserved_14           : 1;
        uint32_t endbc                 : 1;  /**< [ 15: 15](R/W) Enable debugging of the debug capability LSP. Use HOSTSELECT to select the DbC LSP debug
                                                                 information presented in the GDBGLSP register.
                                                                 INTERNAL: Note this can only be used if DebugCapabaility was enabled at compile. */
        uint32_t latraceportmuxselect  : 8;  /**< [ 23: 16](R/W) logic_analyzer_trace port multiplexer select. Only bits<21:16> are used. For details on
                                                                 how the mux controls the debug traces, refer to the Verilog file.
                                                                 A value of 0x3F drives 0s on the logic_analyzer_trace signal. If you plan to OR (instead
                                                                 using a mux) this signal with other trace signals in your system to generate a common
                                                                 trace signal, you can use this feature. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbglspmux_s cn; */
} bdk_usbdrdx_uahc_gdbglspmux_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGLSPMUX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGLSPMUX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c170ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c170ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGLSPMUX", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) bdk_usbdrdx_uahc_gdbglspmux_t
#define bustype_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) "USBDRDX_UAHC_GDBGLSPMUX"
#define device_bar_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGLSPMUX(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdbgltssm
 *
 * UAHC LTSSM Debug Register
 * In multiport host configuration, the port number is defined by
 * USBDRD()_UAHC_GDBGFIFOSPACE[SELECT]<3:0>. Value of this register may change immediately after
 * reset.
 * See description in USBDRD()_UAHC_GDBGFIFOSPACE.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdbgltssm_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_27_31        : 5;
        uint32_t ltdbtimeout           : 1;  /**< [ 26: 26](RO/H) LTDB timeout. */
        uint32_t ltdblinkstate         : 4;  /**< [ 25: 22](RO/H) LTDB link state. */
        uint32_t ltdbsubstate          : 4;  /**< [ 21: 18](RO/H) LTDB substate. */
        uint32_t debugpipestatus       : 18; /**< [ 17:  0](RO/H) Debug PIPE status.
                                                                 _ <17> Elastic buffer mode.
                                                                 _ <16> TX elec idle.
                                                                 _ <15> RX polarity.
                                                                 _ <14> TX Detect RX/loopback.
                                                                 _ <13:11> LTSSM PHY command state.
                                                                 _ 0x0 = PHY_IDLE (PHY command state is in IDLE. No PHY request is pending.)
                                                                 _ 0x1 = PHY_DET (Request to start receiver detection).
                                                                 _ 0x2 = PHY_DET_3 (Wait for Phy_Status (receiver detection)).
                                                                 _ 0x3 = PHY_PWR_DLY (delay Pipe3_PowerDown P0 -> P1/P2/P3 request).
                                                                 _ 0x4 = PHY_PWR_A (delay for internal logic).
                                                                 _ 0x5 = PHY_PWR_B (wait for Phy_Status(Power-state change request)).

                                                                 _ <10:9> Power down.
                                                                 _ <8> RxEq train.
                                                                 _ <7:6> TX de-emphasis.
                                                                 _ <5:3> LTSSM clock state.
                                                                 _ 0x0 = CLK_NORM (PHY is in non-P3 state and PCLK is running).
                                                                 _ 0x1 = CLK_TO_P3 (P3 entry request to PHY).
                                                                 _ 0x2 = CLK_WAIT1 (wait for Phy_Status (P3 request)).
                                                                 _ 0x3 = CLK_P3 (PHY is in P3 and PCLK is not running).
                                                                 _ 0x4 = CLK_TO_P0 (P3 exit request to PHY).
                                                                 _ 0x5 = CLK_WAIT2 (Wait for Phy_Status (P3 exit request)).

                                                                 _ <2> TX swing.
                                                                 _ <1> RX termination.
                                                                 _ <0> TX 1s/0s. */
#else /* Word 0 - Little Endian */
        uint32_t debugpipestatus       : 18; /**< [ 17:  0](RO/H) Debug PIPE status.
                                                                 _ <17> Elastic buffer mode.
                                                                 _ <16> TX elec idle.
                                                                 _ <15> RX polarity.
                                                                 _ <14> TX Detect RX/loopback.
                                                                 _ <13:11> LTSSM PHY command state.
                                                                 _ 0x0 = PHY_IDLE (PHY command state is in IDLE. No PHY request is pending.)
                                                                 _ 0x1 = PHY_DET (Request to start receiver detection).
                                                                 _ 0x2 = PHY_DET_3 (Wait for Phy_Status (receiver detection)).
                                                                 _ 0x3 = PHY_PWR_DLY (delay Pipe3_PowerDown P0 -> P1/P2/P3 request).
                                                                 _ 0x4 = PHY_PWR_A (delay for internal logic).
                                                                 _ 0x5 = PHY_PWR_B (wait for Phy_Status(Power-state change request)).

                                                                 _ <10:9> Power down.
                                                                 _ <8> RxEq train.
                                                                 _ <7:6> TX de-emphasis.
                                                                 _ <5:3> LTSSM clock state.
                                                                 _ 0x0 = CLK_NORM (PHY is in non-P3 state and PCLK is running).
                                                                 _ 0x1 = CLK_TO_P3 (P3 entry request to PHY).
                                                                 _ 0x2 = CLK_WAIT1 (wait for Phy_Status (P3 request)).
                                                                 _ 0x3 = CLK_P3 (PHY is in P3 and PCLK is not running).
                                                                 _ 0x4 = CLK_TO_P0 (P3 exit request to PHY).
                                                                 _ 0x5 = CLK_WAIT2 (Wait for Phy_Status (P3 exit request)).

                                                                 _ <2> TX swing.
                                                                 _ <1> RX termination.
                                                                 _ <0> TX 1s/0s. */
        uint32_t ltdbsubstate          : 4;  /**< [ 21: 18](RO/H) LTDB substate. */
        uint32_t ltdblinkstate         : 4;  /**< [ 25: 22](RO/H) LTDB link state. */
        uint32_t ltdbtimeout           : 1;  /**< [ 26: 26](RO/H) LTDB timeout. */
        uint32_t reserved_27_31        : 5;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdbgltssm_s cn; */
} bdk_usbdrdx_uahc_gdbgltssm_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDBGLTSSM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDBGLTSSM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c164ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c164ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDBGLTSSM", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDBGLTSSM(a) bdk_usbdrdx_uahc_gdbgltssm_t
#define bustype_BDK_USBDRDX_UAHC_GDBGLTSSM(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDBGLTSSM(a) "USBDRDX_UAHC_GDBGLTSSM"
#define device_bar_BDK_USBDRDX_UAHC_GDBGLTSSM(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDBGLTSSM(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDBGLTSSM(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gdmahlratio
 *
 * UAHC DMA High/Low Ratio Register
 * This register specifies the relative priority of the SuperSpeed FIFOs with respect to the
 * high-speed/full-speed/low-speed FIFOs. The DMA arbiter prioritizes the high-speed/full-speed
 * /low-speed round-robin arbiter group every DMA high-low priority ratio grants as indicated in
 * the register separately for TX and RX.
 *
 * To illustrate, consider that all FIFOs are requesting access simultaneously, and the ratio is
 * 4. SuperSpeed gets priority for four packets, high-speed/full-speed/low-speed gets priority
 * for one packet, SuperSpeed gets priority for four packets, high-speed/full-speed/low-speed
 * gets priority for one packet, and so on.
 *
 * If FIFOs from both speed groups are not requesting access simultaneously then:
 * * If SuperSpeed got grants four out of the last four times, then high-speed/full-speed/
 * low-speed get the priority on any future request.
 * * If high-speed/full-speed/low-speed got the grant last time, SuperSpeed gets the priority on
 * the next request.
 *
 * If there is a valid request on either SuperSpeed or high-speed/full-speed/low-speed, a grant
 * is always awarded; there is no idle.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gdmahlratio_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t rx_ratio              : 5;  /**< [ 12:  8](R/W) Speed ratio for RX arbitration. */
        uint32_t reserved_5_7          : 3;
        uint32_t tx_ratio              : 5;  /**< [  4:  0](R/W) Speed ratio for TX arbitration. */
#else /* Word 0 - Little Endian */
        uint32_t tx_ratio              : 5;  /**< [  4:  0](R/W) Speed ratio for TX arbitration. */
        uint32_t reserved_5_7          : 3;
        uint32_t rx_ratio              : 5;  /**< [ 12:  8](R/W) Speed ratio for RX arbitration. */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gdmahlratio_s cn; */
} bdk_usbdrdx_uahc_gdmahlratio_t;

static inline uint64_t BDK_USBDRDX_UAHC_GDMAHLRATIO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GDMAHLRATIO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c624ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c624ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GDMAHLRATIO", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) bdk_usbdrdx_uahc_gdmahlratio_t
#define bustype_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) "USBDRDX_UAHC_GDMAHLRATIO"
#define device_bar_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GDMAHLRATIO(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gevntadr#
 *
 * Global Event Buffer Address Register
 * This register holds the Event Buffer DMA Address pointer. Software must initialize this
 * address once during power-on initialization. Software must not change the value of this
 * register after it is initialized.
 * Software must only use the GEVNTCOUNTn register for event processing. The lower n bits of the
 * address must be USBDRD()_UAHC_GEVNTSIZ()[EVNTSIZ]-aligned.
 *
 * This register can be reset by IOI reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.2.7.1.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gevntadrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t evntadr               : 64; /**< [ 63:  0](R/W/H) Holds the start address of the external memory
                                                                 for the Event Buffer. During operation, hardware does not update
                                                                 this address. */
#else /* Word 0 - Little Endian */
        uint64_t evntadr               : 64; /**< [ 63:  0](R/W/H) Holds the start address of the external memory
                                                                 for the Event Buffer. During operation, hardware does not update
                                                                 this address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gevntadrx_s cn; */
} bdk_usbdrdx_uahc_gevntadrx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GEVNTADRX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GEVNTADRX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c400ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c400ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GEVNTADRX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) bdk_usbdrdx_uahc_gevntadrx_t
#define bustype_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) "USBDRDX_UAHC_GEVNTADRX"
#define device_bar_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GEVNTADRX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gevntcount#
 *
 * Global Event Buffer Count Register
 * This register holds the number of valid bytes in the Event Buffer. During initialization,
 * software must initialize the count by writing 0 to the Event Count field. Each time the
 * hardware writes a new event to the Event Buffer, it increments this count. Most events
 * are four bytes, but some events may span over multiple four byte entries. Whenever the
 * count is greater than zero, the hardware raises the corresponding interrupt
 * line (depending on the USBDRD()_UAHC_GEVNTSIZ()[EVNTINTMASK]). On an interrupt, software
 * processes one or more events out of the Event Buffer. Afterwards, software must write the
 * Event Count field with the number of bytes it processed.
 *
 * Clock crossing delays may result in the interrupt's continual assertion after software
 * acknowledges the last event. Therefore, when the interrupt line is asserted, software must
 * read the GEVNTCOUNT register and only process events if the GEVNTCOUNT is greater than 0.
 *
 * This register can be reset by IOI reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.2.7.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gevntcountx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t evntcount             : 16; /**< [ 15:  0](R/W/H) When read, returns the number of valid events in the Event Buffer (in bytes).
                                                                 When written, hardware decrements the count by the value written.
                                                                 The interrupt line remains high when count is not 0. */
#else /* Word 0 - Little Endian */
        uint32_t evntcount             : 16; /**< [ 15:  0](R/W/H) When read, returns the number of valid events in the Event Buffer (in bytes).
                                                                 When written, hardware decrements the count by the value written.
                                                                 The interrupt line remains high when count is not 0. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gevntcountx_s cn; */
} bdk_usbdrdx_uahc_gevntcountx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GEVNTCOUNTX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GEVNTCOUNTX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c40cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c40cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GEVNTCOUNTX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) bdk_usbdrdx_uahc_gevntcountx_t
#define bustype_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) "USBDRDX_UAHC_GEVNTCOUNTX"
#define device_bar_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GEVNTCOUNTX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gevntsiz#
 *
 * Global Event Buffer Size Register
 * This register holds the Event Buffer Size and the Event Interrupt Mask bit. During power-on
 * initialization, software must initialize the size with the number of bytes allocated for
 * the Event Buffer. The Event Interrupt Mask will mask the interrupt, but events are still
 * queued. After configuration, software must preserve the Event Buffer Size value when
 * changing the Event Interrupt Mask.
 *
 * This register can be reset by IOI reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.2.7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gevntsizx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t evntintmask           : 1;  /**< [ 31: 31](R/W) When set to 1, this prevents the interrupt from being generated.
                                                                 However, even when the mask is set, the events are queued. */
        uint32_t reserved_16_30        : 15;
        uint32_t evntsiz               : 16; /**< [ 15:  0](R/W) Holds the size of the Event Buffer in bytes; must be a multiple of
                                                                 four. This is programmed by software once during initialization.
                                                                 The minimum size of the event buffer is 32 bytes. */
#else /* Word 0 - Little Endian */
        uint32_t evntsiz               : 16; /**< [ 15:  0](R/W) Holds the size of the Event Buffer in bytes; must be a multiple of
                                                                 four. This is programmed by software once during initialization.
                                                                 The minimum size of the event buffer is 32 bytes. */
        uint32_t reserved_16_30        : 15;
        uint32_t evntintmask           : 1;  /**< [ 31: 31](R/W) When set to 1, this prevents the interrupt from being generated.
                                                                 However, even when the mask is set, the events are queued. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gevntsizx_s cn; */
} bdk_usbdrdx_uahc_gevntsizx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GEVNTSIZX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GEVNTSIZX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c408ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c408ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GEVNTSIZX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) bdk_usbdrdx_uahc_gevntsizx_t
#define bustype_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) "USBDRDX_UAHC_GEVNTSIZX"
#define device_bar_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GEVNTSIZX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gfladj
 *
 * UAHC Global Frame Length Adjustment Register
 * This register provides options for the software to control the core behavior with respect to
 * SOF (start of frame) and ITP (isochronous timestamp packet) timers and frame timer
 * functionality. It provides the option to override the sideband signal fladj_30mhz_reg. In
 * addition, it enables running SOF or ITP frame timer counters completely off of the REF_CLK.
 * This facilitates hardware LPM in host mode with the SOF or ITP counters being run off of the
 * REF_CLK signal.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.6.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gfladj_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t gfladj_refclk_240mhzdecr_pls1 : 1;/**< [ 31: 31](R/W) This field indicates that the decrement value that the controller applies for each REF_CLK
                                                                 must be GFLADJ_REFCLK_240MHZ_DECR and GFLADJ_REFCLK_240MHZ_DECR +1 alternatively on each
                                                                 REF_CLK. Set this bit to 1 only if GFLADJ_REFCLK_LPM_SEL is set to 1 and the fractional
                                                                 component of 240/ref_frequency is greater than or equal to 0.5.

                                                                 Example:

                                                                 If the REF_CLK is 19.2 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 52.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/19.2) = 12.5.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 1.

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/24) = 10.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 0. */
        uint32_t gfladj_refclk_240mhz_decr : 7;/**< [ 30: 24](R/W) This field indicates the decrement value that the controller applies for each REF_CLK in
                                                                 order to derive a frame timer in terms of a 240-MHz clock. This field must be programmed
                                                                 to a non-zero value only if GFLADJ_REFCLK_LPM_SEL is set to 1.

                                                                 The value is derived as follows:
                                                                 _ GFLADJ_REFCLK_240MHZ_DECR = 240/ref_clk_frequency

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/24 = 10.

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/48 = 5.

                                                                 If the REF_CLK is 17 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 58.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/17 = 14. */
        uint32_t gfladj_refclk_lpm_sel : 1;  /**< [ 23: 23](R/W) This bit enables the functionality of running SOF/ITP counters on the REF_CLK.
                                                                 This bit must not be set to 1 if USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1. Similarly, if
                                                                 GFLADJ_REFCLK_LPM_SEL = 1, USBDRD()_UAHC_GCTL[SOFITPSYNC] must not be set to 1.
                                                                 When GFLADJ_REFCLK_LPM_SEL = 1 the overloading of the suspend control of the USB 2.0 first
                                                                 port PHY (UTMI) with USB 3.0 port states is removed. Note that the REF_CLK frequencies
                                                                 supported in this mode are 16/17/19.2/20/24/39.7/40 MHz.
                                                                 INTERNAL: The utmi_clk[0] signal of the core must be connected to the FREECLK of the PHY.
                                                                 If you set this bit to 1, USBDRD()_UAHC_GUSB2PHYCFG()[U2_FREECLK_EXISTS] must be set to 0. */
        uint32_t reserved_22           : 1;
        uint32_t gfladj_refclk_fladj   : 14; /**< [ 21:  8](R/W) This field indicates the frame length adjustment to be applied when SOF/ITP counter is
                                                                 running off of the REF_CLK. This register value is used to adjust:.
                                                                 * ITP interval when USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1
                                                                 * both SOF and ITP interval when GFLADJ_REFCLK_LPM_SEL = 1.

                                                                 This field must be programmed to a non-zero value only if GFLADJ_REFCLK_LPM_SEL = 1 or
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1.

                                                                 The value is derived as below:

                                                                 _ FLADJ_REF_CLK_FLADJ = ((125000/ref_clk_period_integer) - (125000/ref_clk_period)) *
                                                                 ref_clk_period

                                                                 where,
                                                                 * the ref_clk_period_integer is the integer value of the REF_CLK period got by truncating
                                                                 the decimal (fractional) value that is programmed in USBDRD()_UAHC_GUCTL[REFCLKPER].
                                                                 * the ref_clk_period is the REF_CLK period including the fractional value.

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/41) -
                                                                 (125000/41.6666)) * 41.6666 = 2032 (ignoring the fractional value).

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/20) -
                                                                 (125000/20.8333)) * 20.8333 = 5208 (ignoring the fractional value). */
        uint32_t gfladj_30mhz_reg_sel  : 1;  /**< [  7:  7](R/W) This field selects whether to use the input signal fladj_30mhz_reg or the GFLADJ_30MHZ to
                                                                 adjust the frame length for the SOF/ITP. When this bit is set to, 1, the controller uses
                                                                 GFLADJ_30MHZ value 0x0, the controller uses the input signal fladj_30mhz_reg value. */
        uint32_t reserved_6            : 1;
        uint32_t gfladj_30mhz          : 6;  /**< [  5:  0](R/W) This field indicates the value that is used for frame length adjustment instead of
                                                                 considering from the sideband input signal fladj_30mhz_reg. This enables post-silicon
                                                                 frame length adjustment in case the input signal fladj_30mhz_reg is connected to a wrong
                                                                 value or is not valid. The controller uses this value if GFLADJ_30MHZ_REG_SEL = 1 and the
                                                                 SOF/ITP counters are running off of UTMI(ULPI) clock (GFLADJ_REFCLK_LPM_SEL = 0 and
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] is 1 or 0). For details on how to set this value, refer to
                                                                 section 5.2.4 Frame Length Adjustment Register (FLADJ) of the xHCI Specification. */
#else /* Word 0 - Little Endian */
        uint32_t gfladj_30mhz          : 6;  /**< [  5:  0](R/W) This field indicates the value that is used for frame length adjustment instead of
                                                                 considering from the sideband input signal fladj_30mhz_reg. This enables post-silicon
                                                                 frame length adjustment in case the input signal fladj_30mhz_reg is connected to a wrong
                                                                 value or is not valid. The controller uses this value if GFLADJ_30MHZ_REG_SEL = 1 and the
                                                                 SOF/ITP counters are running off of UTMI(ULPI) clock (GFLADJ_REFCLK_LPM_SEL = 0 and
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] is 1 or 0). For details on how to set this value, refer to
                                                                 section 5.2.4 Frame Length Adjustment Register (FLADJ) of the xHCI Specification. */
        uint32_t reserved_6            : 1;
        uint32_t gfladj_30mhz_reg_sel  : 1;  /**< [  7:  7](R/W) This field selects whether to use the input signal fladj_30mhz_reg or the GFLADJ_30MHZ to
                                                                 adjust the frame length for the SOF/ITP. When this bit is set to, 1, the controller uses
                                                                 GFLADJ_30MHZ value 0x0, the controller uses the input signal fladj_30mhz_reg value. */
        uint32_t gfladj_refclk_fladj   : 14; /**< [ 21:  8](R/W) This field indicates the frame length adjustment to be applied when SOF/ITP counter is
                                                                 running off of the REF_CLK. This register value is used to adjust:.
                                                                 * ITP interval when USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1
                                                                 * both SOF and ITP interval when GFLADJ_REFCLK_LPM_SEL = 1.

                                                                 This field must be programmed to a non-zero value only if GFLADJ_REFCLK_LPM_SEL = 1 or
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1.

                                                                 The value is derived as below:

                                                                 _ FLADJ_REF_CLK_FLADJ = ((125000/ref_clk_period_integer) - (125000/ref_clk_period)) *
                                                                 ref_clk_period

                                                                 where,
                                                                 * the ref_clk_period_integer is the integer value of the REF_CLK period got by truncating
                                                                 the decimal (fractional) value that is programmed in USBDRD()_UAHC_GUCTL[REFCLKPER].
                                                                 * the ref_clk_period is the REF_CLK period including the fractional value.

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/41) -
                                                                 (125000/41.6666)) * 41.6666 = 2032 (ignoring the fractional value).

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GLADJ_REFCLK_FLADJ = ((125000/20) -
                                                                 (125000/20.8333)) * 20.8333 = 5208 (ignoring the fractional value). */
        uint32_t reserved_22           : 1;
        uint32_t gfladj_refclk_lpm_sel : 1;  /**< [ 23: 23](R/W) This bit enables the functionality of running SOF/ITP counters on the REF_CLK.
                                                                 This bit must not be set to 1 if USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1. Similarly, if
                                                                 GFLADJ_REFCLK_LPM_SEL = 1, USBDRD()_UAHC_GCTL[SOFITPSYNC] must not be set to 1.
                                                                 When GFLADJ_REFCLK_LPM_SEL = 1 the overloading of the suspend control of the USB 2.0 first
                                                                 port PHY (UTMI) with USB 3.0 port states is removed. Note that the REF_CLK frequencies
                                                                 supported in this mode are 16/17/19.2/20/24/39.7/40 MHz.
                                                                 INTERNAL: The utmi_clk[0] signal of the core must be connected to the FREECLK of the PHY.
                                                                 If you set this bit to 1, USBDRD()_UAHC_GUSB2PHYCFG()[U2_FREECLK_EXISTS] must be set to 0. */
        uint32_t gfladj_refclk_240mhz_decr : 7;/**< [ 30: 24](R/W) This field indicates the decrement value that the controller applies for each REF_CLK in
                                                                 order to derive a frame timer in terms of a 240-MHz clock. This field must be programmed
                                                                 to a non-zero value only if GFLADJ_REFCLK_LPM_SEL is set to 1.

                                                                 The value is derived as follows:
                                                                 _ GFLADJ_REFCLK_240MHZ_DECR = 240/ref_clk_frequency

                                                                 Examples:

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/24 = 10.

                                                                 If the REF_CLK is 48 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 20.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/48 = 5.

                                                                 If the REF_CLK is 17 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 58.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = 240/17 = 14. */
        uint32_t gfladj_refclk_240mhzdecr_pls1 : 1;/**< [ 31: 31](R/W) This field indicates that the decrement value that the controller applies for each REF_CLK
                                                                 must be GFLADJ_REFCLK_240MHZ_DECR and GFLADJ_REFCLK_240MHZ_DECR +1 alternatively on each
                                                                 REF_CLK. Set this bit to 1 only if GFLADJ_REFCLK_LPM_SEL is set to 1 and the fractional
                                                                 component of 240/ref_frequency is greater than or equal to 0.5.

                                                                 Example:

                                                                 If the REF_CLK is 19.2 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 52.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/19.2) = 12.5.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 1.

                                                                 If the REF_CLK is 24 MHz then,
                                                                 * USBDRD()_UAHC_GUCTL[REFCLKPER] = 41.
                                                                 * GFLADJ_REFCLK_240MHZ_DECR = (240/24) = 10.
                                                                 * GFLADJ_REFCLK_240MHZDECR_PLS1 = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gfladj_s cn; */
} bdk_usbdrdx_uahc_gfladj_t;

static inline uint64_t BDK_USBDRDX_UAHC_GFLADJ(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GFLADJ(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c630ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c630ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GFLADJ", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GFLADJ(a) bdk_usbdrdx_uahc_gfladj_t
#define bustype_BDK_USBDRDX_UAHC_GFLADJ(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GFLADJ(a) "USBDRDX_UAHC_GFLADJ"
#define device_bar_BDK_USBDRDX_UAHC_GFLADJ(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GFLADJ(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GFLADJ(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ggpio
 *
 * UAHC Core General-Purpose I/O Register
 * The application can use this register for general purpose input and output ports or for
 * debugging.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.9.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ggpio_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t gpo                   : 16; /**< [ 31: 16](R/W) General purpose output. These outputs are not connected to anything. Can be used as scratch. */
        uint32_t gpi                   : 16; /**< [ 15:  0](RO) General purpose input. These inputs are tied 0x0. */
#else /* Word 0 - Little Endian */
        uint32_t gpi                   : 16; /**< [ 15:  0](RO) General purpose input. These inputs are tied 0x0. */
        uint32_t gpo                   : 16; /**< [ 31: 16](R/W) General purpose output. These outputs are not connected to anything. Can be used as scratch. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ggpio_s cn; */
} bdk_usbdrdx_uahc_ggpio_t;

static inline uint64_t BDK_USBDRDX_UAHC_GGPIO(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GGPIO(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c124ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c124ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GGPIO", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GGPIO(a) bdk_usbdrdx_uahc_ggpio_t
#define bustype_BDK_USBDRDX_UAHC_GGPIO(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GGPIO(a) "USBDRDX_UAHC_GGPIO"
#define device_bar_BDK_USBDRDX_UAHC_GGPIO(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GGPIO(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GGPIO(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams0
 *
 * UAHC Hardware Parameters Register 0
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t awidth                : 8;  /**< [ 31: 24](RO) USB core bus-address width. */
        uint32_t sdwidth               : 8;  /**< [ 23: 16](RO) USB core bus slave-data width. */
        uint32_t mdwidth               : 8;  /**< [ 15:  8](RO) USB core bus master-data width. */
        uint32_t sbus_type             : 2;  /**< [  7:  6](RO) USB core bus slave type: AXI. */
        uint32_t mbus_type             : 3;  /**< [  5:  3](RO) USB core bus master type: AXI. */
        uint32_t mode                  : 3;  /**< [  2:  0](RO) Operation mode: 0x2: Dual-role device. */
#else /* Word 0 - Little Endian */
        uint32_t mode                  : 3;  /**< [  2:  0](RO) Operation mode: 0x2: Dual-role device. */
        uint32_t mbus_type             : 3;  /**< [  5:  3](RO) USB core bus master type: AXI. */
        uint32_t sbus_type             : 2;  /**< [  7:  6](RO) USB core bus slave type: AXI. */
        uint32_t mdwidth               : 8;  /**< [ 15:  8](RO) USB core bus master-data width. */
        uint32_t sdwidth               : 8;  /**< [ 23: 16](RO) USB core bus slave-data width. */
        uint32_t awidth                : 8;  /**< [ 31: 24](RO) USB core bus-address width. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams0_s cn; */
} bdk_usbdrdx_uahc_ghwparams0_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c140ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c140ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS0", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS0(a) bdk_usbdrdx_uahc_ghwparams0_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS0(a) "USBDRDX_UAHC_GHWPARAMS0"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS0(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams1
 *
 * UAHC Hardware Parameters Register 1
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t en_dbc                : 1;  /**< [ 31: 31](RAZ) Enable debug capability. */
        uint32_t rm_opt_features       : 1;  /**< [ 30: 30](RO) Remove optional features. */
        uint32_t sync_rst              : 1;  /**< [ 29: 29](RO) Synchronous reset coding. */
        uint32_t ram_bus_clks_sync     : 1;  /**< [ 28: 28](RO) RAM_CLK and BUS_CLK are synchronous. INTERNAL: (appears to be orthogonal from the
                                                                 RAM_CLK_TO_BUS_CLK parameter) */
        uint32_t mac_ram_clks_sync     : 1;  /**< [ 27: 27](RO) MAC3_CLK and RAM_CLK are synchronous. */
        uint32_t mac_phy_clks_sync     : 1;  /**< [ 26: 26](RO) MAC3_CLK and PHY_CLK are synchronous. */
        uint32_t en_pwropt             : 2;  /**< [ 25: 24](RO) Power optimization mode:
                                                                 bit<0> = Clock-gating feature available.
                                                                 bit<1> = Hibernation feature available. */
        uint32_t spram_typ             : 1;  /**< [ 23: 23](RO) SRAM type: one-port RAMs. */
        uint32_t num_rams              : 2;  /**< [ 22: 21](RO) Number of RAMs. */
        uint32_t device_num_int        : 6;  /**< [ 20: 15](RO) Number of event buffers (and interrupts) in device-mode (unsupported). */
        uint32_t aspacewidth           : 3;  /**< [ 14: 12](RO) Native interface address-space port width. */
        uint32_t reqinfowidth          : 3;  /**< [ 11:  9](RO) Native interface request/response-info port width. */
        uint32_t datainfowidth         : 3;  /**< [  8:  6](RO) Native interface data-info port width. */
        uint32_t burstwidth_m1         : 3;  /**< [  5:  3](RO) Width minus one of AXI length field. */
        uint32_t idwidth_m1            : 3;  /**< [  2:  0](RO) Width minus one of AXI ID field. */
#else /* Word 0 - Little Endian */
        uint32_t idwidth_m1            : 3;  /**< [  2:  0](RO) Width minus one of AXI ID field. */
        uint32_t burstwidth_m1         : 3;  /**< [  5:  3](RO) Width minus one of AXI length field. */
        uint32_t datainfowidth         : 3;  /**< [  8:  6](RO) Native interface data-info port width. */
        uint32_t reqinfowidth          : 3;  /**< [ 11:  9](RO) Native interface request/response-info port width. */
        uint32_t aspacewidth           : 3;  /**< [ 14: 12](RO) Native interface address-space port width. */
        uint32_t device_num_int        : 6;  /**< [ 20: 15](RO) Number of event buffers (and interrupts) in device-mode (unsupported). */
        uint32_t num_rams              : 2;  /**< [ 22: 21](RO) Number of RAMs. */
        uint32_t spram_typ             : 1;  /**< [ 23: 23](RO) SRAM type: one-port RAMs. */
        uint32_t en_pwropt             : 2;  /**< [ 25: 24](RO) Power optimization mode:
                                                                 bit<0> = Clock-gating feature available.
                                                                 bit<1> = Hibernation feature available. */
        uint32_t mac_phy_clks_sync     : 1;  /**< [ 26: 26](RO) MAC3_CLK and PHY_CLK are synchronous. */
        uint32_t mac_ram_clks_sync     : 1;  /**< [ 27: 27](RO) MAC3_CLK and RAM_CLK are synchronous. */
        uint32_t ram_bus_clks_sync     : 1;  /**< [ 28: 28](RO) RAM_CLK and BUS_CLK are synchronous. INTERNAL: (appears to be orthogonal from the
                                                                 RAM_CLK_TO_BUS_CLK parameter) */
        uint32_t sync_rst              : 1;  /**< [ 29: 29](RO) Synchronous reset coding. */
        uint32_t rm_opt_features       : 1;  /**< [ 30: 30](RO) Remove optional features. */
        uint32_t en_dbc                : 1;  /**< [ 31: 31](RAZ) Enable debug capability. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams1_s cn; */
} bdk_usbdrdx_uahc_ghwparams1_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c144ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c144ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS1(a) bdk_usbdrdx_uahc_ghwparams1_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS1(a) "USBDRDX_UAHC_GHWPARAMS1"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams2
 *
 * UAHC Core GHW Parameters Register 2
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t userid                : 32; /**< [ 31:  0](RO) User ID. */
#else /* Word 0 - Little Endian */
        uint32_t userid                : 32; /**< [ 31:  0](RO) User ID. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams2_s cn; */
} bdk_usbdrdx_uahc_ghwparams2_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c148ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c148ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS2", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS2(a) bdk_usbdrdx_uahc_ghwparams2_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS2(a) "USBDRDX_UAHC_GHWPARAMS2"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS2(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams3
 *
 * UAHC GHW Parameters Register 3
 * This register contains the hardware configuration options selected at compile-time.
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t cache_total_xfer_resources : 8;/**< [ 30: 23](RO) Maximum number of transfer resources in the core. */
        uint32_t num_in_eps            : 5;  /**< [ 22: 18](RO) Maximum number of device-mode IN endpoints active. */
        uint32_t num_eps               : 6;  /**< [ 17: 12](RO) Number of device-mode single-directional endpoints. */
        uint32_t ulpi_carkit           : 1;  /**< [ 11: 11](RO) ULPI Carkit is not supported. */
        uint32_t vendor_ctl_interface  : 1;  /**< [ 10: 10](RO) UTMI+ PHY vendor control interface enabled. */
        uint32_t reserved_8_9          : 2;
        uint32_t hsphy_dwidth          : 2;  /**< [  7:  6](RO) Data width of the UTMI+ PHY interface: 0x2 = 8-or-16 bits. */
        uint32_t fsphy_interface       : 2;  /**< [  5:  4](RO) USB 1.1 full-speed serial transceiver interface. */
        uint32_t hsphy_interface       : 2;  /**< [  3:  2](RO) High-speed PHY interface: 0x1 = UTMI+. */
        uint32_t ssphy_interface       : 2;  /**< [  1:  0](RO) SuperSpeed PHY interface: 0x1 = PIPE3. */
#else /* Word 0 - Little Endian */
        uint32_t ssphy_interface       : 2;  /**< [  1:  0](RO) SuperSpeed PHY interface: 0x1 = PIPE3. */
        uint32_t hsphy_interface       : 2;  /**< [  3:  2](RO) High-speed PHY interface: 0x1 = UTMI+. */
        uint32_t fsphy_interface       : 2;  /**< [  5:  4](RO) USB 1.1 full-speed serial transceiver interface. */
        uint32_t hsphy_dwidth          : 2;  /**< [  7:  6](RO) Data width of the UTMI+ PHY interface: 0x2 = 8-or-16 bits. */
        uint32_t reserved_8_9          : 2;
        uint32_t vendor_ctl_interface  : 1;  /**< [ 10: 10](RO) UTMI+ PHY vendor control interface enabled. */
        uint32_t ulpi_carkit           : 1;  /**< [ 11: 11](RO) ULPI Carkit is not supported. */
        uint32_t num_eps               : 6;  /**< [ 17: 12](RO) Number of device-mode single-directional endpoints. */
        uint32_t num_in_eps            : 5;  /**< [ 22: 18](RO) Maximum number of device-mode IN endpoints active. */
        uint32_t cache_total_xfer_resources : 8;/**< [ 30: 23](RO) Maximum number of transfer resources in the core. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams3_s cn; */
} bdk_usbdrdx_uahc_ghwparams3_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c14cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c14cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS3", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS3(a) bdk_usbdrdx_uahc_ghwparams3_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS3(a) "USBDRDX_UAHC_GHWPARAMS3"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS3(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams4
 *
 * UAHC GHW Parameters Register 4
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams4_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bmu_lsp_depth         : 4;  /**< [ 31: 28](RO) Depth of the BMU-LSP status buffer. */
        uint32_t bmu_ptl_depth_m1      : 4;  /**< [ 27: 24](RO) Depth of the BMU-PTL source/sink buffers minus 1. */
        uint32_t en_isoc_supt          : 1;  /**< [ 23: 23](RO) Isochronous support enabled. */
        uint32_t reserved_22           : 1;
        uint32_t ext_buff_control      : 1;  /**< [ 21: 21](RO) Enables device external buffer control sideband controls. */
        uint32_t num_ss_usb_instances  : 4;  /**< [ 20: 17](RO) Number of SuperSpeed bus instances. */
        uint32_t hiber_scratchbufs     : 4;  /**< [ 16: 13](RO) Number of hibernation scratchpad buffers. */
        uint32_t reserved_6_12         : 7;
        uint32_t cache_trbs_per_transfer : 6;/**< [  5:  0](RO) Number of TRBs per transfer that can be cached. */
#else /* Word 0 - Little Endian */
        uint32_t cache_trbs_per_transfer : 6;/**< [  5:  0](RO) Number of TRBs per transfer that can be cached. */
        uint32_t reserved_6_12         : 7;
        uint32_t hiber_scratchbufs     : 4;  /**< [ 16: 13](RO) Number of hibernation scratchpad buffers. */
        uint32_t num_ss_usb_instances  : 4;  /**< [ 20: 17](RO) Number of SuperSpeed bus instances. */
        uint32_t ext_buff_control      : 1;  /**< [ 21: 21](RO) Enables device external buffer control sideband controls. */
        uint32_t reserved_22           : 1;
        uint32_t en_isoc_supt          : 1;  /**< [ 23: 23](RO) Isochronous support enabled. */
        uint32_t bmu_ptl_depth_m1      : 4;  /**< [ 27: 24](RO) Depth of the BMU-PTL source/sink buffers minus 1. */
        uint32_t bmu_lsp_depth         : 4;  /**< [ 31: 28](RO) Depth of the BMU-LSP status buffer. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams4_s cn; */
} bdk_usbdrdx_uahc_ghwparams4_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS4(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS4(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c150ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c150ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS4", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS4(a) bdk_usbdrdx_uahc_ghwparams4_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS4(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS4(a) "USBDRDX_UAHC_GHWPARAMS4"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS4(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS4(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS4(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams5
 *
 * UAHC GHW Parameters Register 5
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.6.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams5_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_28_31        : 4;
        uint32_t dfq_fifo_depth        : 6;  /**< [ 27: 22](RO) Size of the BMU descriptor fetch-request queue. */
        uint32_t dwq_fifo_depth        : 6;  /**< [ 21: 16](RO) Size of the BMU descriptor write queue. */
        uint32_t txq_fifo_depth        : 6;  /**< [ 15: 10](RO) Size of the BMU TX request queue. */
        uint32_t rxq_fifo_depth        : 6;  /**< [  9:  4](RO) Size of the BMU RX request queue. */
        uint32_t bmu_busgm_depth       : 4;  /**< [  3:  0](RO) Depth of the BMU-BUSGM source/sink buffers. */
#else /* Word 0 - Little Endian */
        uint32_t bmu_busgm_depth       : 4;  /**< [  3:  0](RO) Depth of the BMU-BUSGM source/sink buffers. */
        uint32_t rxq_fifo_depth        : 6;  /**< [  9:  4](RO) Size of the BMU RX request queue. */
        uint32_t txq_fifo_depth        : 6;  /**< [ 15: 10](RO) Size of the BMU TX request queue. */
        uint32_t dwq_fifo_depth        : 6;  /**< [ 21: 16](RO) Size of the BMU descriptor write queue. */
        uint32_t dfq_fifo_depth        : 6;  /**< [ 27: 22](RO) Size of the BMU descriptor fetch-request queue. */
        uint32_t reserved_28_31        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams5_s cn; */
} bdk_usbdrdx_uahc_ghwparams5_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS5(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS5(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c154ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c154ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS5", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS5(a) bdk_usbdrdx_uahc_ghwparams5_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS5(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS5(a) "USBDRDX_UAHC_GHWPARAMS5"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS5(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS5(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS5(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams6
 *
 * UAHC GHW Parameters Register 6
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.7.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams6_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ram0_depth            : 16; /**< [ 31: 16](RO) RAM0 Depth. */
        uint32_t en_bus_filters        : 1;  /**< [ 15: 15](RO) VBus filters support. */
        uint32_t en_bc                 : 1;  /**< [ 14: 14](RO) Enable battery-charging support. */
        uint32_t en_otg_ss             : 1;  /**< [ 13: 13](RO) Enable OTG SuperSpeed support. */
        uint32_t en_adp                : 1;  /**< [ 12: 12](RO) Enable ADP support. */
        uint32_t hnp_support           : 1;  /**< [ 11: 11](RO) HNP support. */
        uint32_t srp_support           : 1;  /**< [ 10: 10](RO) SRP support. */
        uint32_t reserved_8_9          : 2;
        uint32_t en_fpga               : 1;  /**< [  7:  7](RO) Enable FPGA implementation. */
        uint32_t en_dbg_ports          : 1;  /**< [  6:  6](RO) Enable Debug ports for FGPA. */
        uint32_t psq_fifo_depth        : 6;  /**< [  5:  0](RO) Size of the BMU-protocol status queue. */
#else /* Word 0 - Little Endian */
        uint32_t psq_fifo_depth        : 6;  /**< [  5:  0](RO) Size of the BMU-protocol status queue. */
        uint32_t en_dbg_ports          : 1;  /**< [  6:  6](RO) Enable Debug ports for FGPA. */
        uint32_t en_fpga               : 1;  /**< [  7:  7](RO) Enable FPGA implementation. */
        uint32_t reserved_8_9          : 2;
        uint32_t srp_support           : 1;  /**< [ 10: 10](RO) SRP support. */
        uint32_t hnp_support           : 1;  /**< [ 11: 11](RO) HNP support. */
        uint32_t en_adp                : 1;  /**< [ 12: 12](RO) Enable ADP support. */
        uint32_t en_otg_ss             : 1;  /**< [ 13: 13](RO) Enable OTG SuperSpeed support. */
        uint32_t en_bc                 : 1;  /**< [ 14: 14](RO) Enable battery-charging support. */
        uint32_t en_bus_filters        : 1;  /**< [ 15: 15](RO) VBus filters support. */
        uint32_t ram0_depth            : 16; /**< [ 31: 16](RO) RAM0 Depth. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams6_s cn; */
} bdk_usbdrdx_uahc_ghwparams6_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS6(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS6(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c158ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c158ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS6", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS6(a) bdk_usbdrdx_uahc_ghwparams6_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS6(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS6(a) "USBDRDX_UAHC_GHWPARAMS6"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS6(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS6(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS6(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams7
 *
 * UAHC GHW Parameters Register 7
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.3.8.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams7_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ram2_depth            : 16; /**< [ 31: 16](RO) RAM2 depth. */
        uint32_t ram1_depth            : 16; /**< [ 15:  0](RO) RAM1 depth. */
#else /* Word 0 - Little Endian */
        uint32_t ram1_depth            : 16; /**< [ 15:  0](RO) RAM1 depth. */
        uint32_t ram2_depth            : 16; /**< [ 31: 16](RO) RAM2 depth. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams7_s cn; */
} bdk_usbdrdx_uahc_ghwparams7_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS7(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS7(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c15cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c15cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS7", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS7(a) bdk_usbdrdx_uahc_ghwparams7_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS7(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS7(a) "USBDRDX_UAHC_GHWPARAMS7"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS7(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS7(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS7(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_ghwparams8
 *
 * UAHC GHW Parameters Register 8
 * This register contains the hardware configuration options selected at compile-time.
 * INTERNAL: Register field names refer to Synopsys DWC_USB3_* parameters of the same suffix.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.3.9.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_ghwparams8_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dcache_depth_info     : 32; /**< [ 31:  0](RO) Dcache depth. */
#else /* Word 0 - Little Endian */
        uint32_t dcache_depth_info     : 32; /**< [ 31:  0](RO) Dcache depth. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_ghwparams8_s cn; */
} bdk_usbdrdx_uahc_ghwparams8_t;

static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS8(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GHWPARAMS8(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c600ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c600ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GHWPARAMS8", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GHWPARAMS8(a) bdk_usbdrdx_uahc_ghwparams8_t
#define bustype_BDK_USBDRDX_UAHC_GHWPARAMS8(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GHWPARAMS8(a) "USBDRDX_UAHC_GHWPARAMS8"
#define device_bar_BDK_USBDRDX_UAHC_GHWPARAMS8(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GHWPARAMS8(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GHWPARAMS8(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gpmsts
 *
 * UAHC Global Power Management Status Register
 * This debug register gives information on which event caused the hibernation exit. These
 * registers are for debug purposes. They provide debug information on the internal status and
 * state machines. Global debug registers have design-specific information, and are used by for
 * debugging purposes. These registers are not intended to be used by the customer. If any debug
 * assistance is needed for the silicon, contact Customer Support with a dump of these registers.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.4.1.
 * INTERNAL: Contact Synopsys directly.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gpmsts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t portsel               : 4;  /**< [ 31: 28](WO) This field selects the port number. Always 0x0. */
        uint32_t reserved_17_27        : 11;
        uint32_t u3wakeup              : 5;  /**< [ 16: 12](RO/H) This field gives the USB 3.0 port wakeup conditions.
                                                                 bit<12> = Overcurrent detected.
                                                                 bit<13> = Resume detected.
                                                                 bit<14> = Connect detected.
                                                                 bit<15> = Disconnect detected.
                                                                 bit<16> = Last connection state. */
        uint32_t reserved_10_11        : 2;
        uint32_t u2wakeup              : 10; /**< [  9:  0](RO/H) This field indicates the USB 2.0 port wakeup conditions.
                                                                 bit<0> = Overcurrent detected.
                                                                 bit<1> = Resume detected.
                                                                 bit<2> = Connect detected.
                                                                 bit<3> = Disconnect detected.
                                                                 bit<4> = Last connection state.
                                                                 bit<5> = ID change detected.
                                                                 bit<6> = SRP request detected.
                                                                 bit<7> = ULPI interrupt detected.
                                                                 bit<8> = USB reset detected.
                                                                 bit<9> = Resume detected changed. */
#else /* Word 0 - Little Endian */
        uint32_t u2wakeup              : 10; /**< [  9:  0](RO/H) This field indicates the USB 2.0 port wakeup conditions.
                                                                 bit<0> = Overcurrent detected.
                                                                 bit<1> = Resume detected.
                                                                 bit<2> = Connect detected.
                                                                 bit<3> = Disconnect detected.
                                                                 bit<4> = Last connection state.
                                                                 bit<5> = ID change detected.
                                                                 bit<6> = SRP request detected.
                                                                 bit<7> = ULPI interrupt detected.
                                                                 bit<8> = USB reset detected.
                                                                 bit<9> = Resume detected changed. */
        uint32_t reserved_10_11        : 2;
        uint32_t u3wakeup              : 5;  /**< [ 16: 12](RO/H) This field gives the USB 3.0 port wakeup conditions.
                                                                 bit<12> = Overcurrent detected.
                                                                 bit<13> = Resume detected.
                                                                 bit<14> = Connect detected.
                                                                 bit<15> = Disconnect detected.
                                                                 bit<16> = Last connection state. */
        uint32_t reserved_17_27        : 11;
        uint32_t portsel               : 4;  /**< [ 31: 28](WO) This field selects the port number. Always 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gpmsts_s cn; */
} bdk_usbdrdx_uahc_gpmsts_t;

static inline uint64_t BDK_USBDRDX_UAHC_GPMSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GPMSTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c114ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c114ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GPMSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GPMSTS(a) bdk_usbdrdx_uahc_gpmsts_t
#define bustype_BDK_USBDRDX_UAHC_GPMSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GPMSTS(a) "USBDRDX_UAHC_GPMSTS"
#define device_bar_BDK_USBDRDX_UAHC_GPMSTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GPMSTS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GPMSTS(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gprtbimap
 *
 * UAHC SuperSpeed Port-to-Bus Instance Mapping Register
 * This register specifies the SuperSpeed USB instance number to which each USB 3.0 port is
 * connected. By default, USB 3.0 ports are evenly distributed among all SuperSpeed USB
 * instances. Software can program this register to specify how USB 3.0 ports are connected to
 * SuperSpeed USB instances. The UAHC only implements one SuperSpeed bus-instance, so this
 * register should always be 0.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.2.1.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gprtbimap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) SuperSpeed USB instance number for port 1. */
#else /* Word 0 - Little Endian */
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) SuperSpeed USB instance number for port 1. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gprtbimap_s cn; */
} bdk_usbdrdx_uahc_gprtbimap_t;

static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c138ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c138ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GPRTBIMAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GPRTBIMAP(a) bdk_usbdrdx_uahc_gprtbimap_t
#define bustype_BDK_USBDRDX_UAHC_GPRTBIMAP(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GPRTBIMAP(a) "USBDRDX_UAHC_GPRTBIMAP"
#define device_bar_BDK_USBDRDX_UAHC_GPRTBIMAP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GPRTBIMAP(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GPRTBIMAP(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gprtbimap_fs
 *
 * UAHC Full/LowSpeed Port-to-Bus Instance Mapping Register
 * This register specifies the full-speed/low-speed USB instance number to which each USB 1.1
 * port is connected. By default, USB 1.1 ports are evenly distributed among all full-speed/
 * low-speed USB instances. Software can program this register to specify how USB 1.1 ports are
 * connected to full-speed/low-speed USB instances. The UAHC only implements one full-speed/
 * low-speed bus-instance, so this register should always be 0x0.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.2.3.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gprtbimap_fs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) Full-speed USB instance number for port 1. */
#else /* Word 0 - Little Endian */
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) Full-speed USB instance number for port 1. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gprtbimap_fs_s cn; */
} bdk_usbdrdx_uahc_gprtbimap_fs_t;

static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP_FS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP_FS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c188ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c188ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GPRTBIMAP_FS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) bdk_usbdrdx_uahc_gprtbimap_fs_t
#define bustype_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) "USBDRDX_UAHC_GPRTBIMAP_FS"
#define device_bar_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GPRTBIMAP_FS(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uahc_gprtbimap_hs
 *
 * UAHC High-Speed Port-to-Bus Instance Mapping Register
 * This register specifies the high-speed USB instance number to which each USB 2.0 port is
 * connected. By default, USB 2.0 ports are evenly distributed among all high-speed USB
 * instances. Software can program this register to specify how USB 2.0 ports are connected to
 * high-speed USB instances. The UAHC only implements one high-speed bus-instance, so this
 * register should always be 0.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.2.2.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uahc_gprtbimap_hs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_4_63         : 60;
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) High-speed USB instance number for port 1. */
#else /* Word 0 - Little Endian */
        uint64_t binum1                : 4;  /**< [  3:  0](R/W) High-speed USB instance number for port 1. */
        uint64_t reserved_4_63         : 60;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gprtbimap_hs_s cn; */
} bdk_usbdrdx_uahc_gprtbimap_hs_t;

static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP_HS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GPRTBIMAP_HS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c180ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c180ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GPRTBIMAP_HS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) bdk_usbdrdx_uahc_gprtbimap_hs_t
#define bustype_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) "USBDRDX_UAHC_GPRTBIMAP_HS"
#define device_bar_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GPRTBIMAP_HS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_grlsid
 *
 * UAHC Release ID Register
 * This is a read-only register that contains the release number of the core.
 * INTERNAL: Original name: GSNPSID = Synopsys ID.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.8.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_grlsid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t releaseid             : 32; /**< [ 31:  0](RO) Software can use this register to configure release-specific features in the driver.
                                                                 INTERNAL: Synopsys ID
                                                                  * SynopsysID[31:16] indicates Core Identification Number. 0x5533 is ASCII for
                                                                 U3 (DWC_usb3).
                                                                  * SynopsysID[15:0] indicates the release number. Current Release is 2.50a. */
#else /* Word 0 - Little Endian */
        uint32_t releaseid             : 32; /**< [ 31:  0](RO) Software can use this register to configure release-specific features in the driver.
                                                                 INTERNAL: Synopsys ID
                                                                  * SynopsysID[31:16] indicates Core Identification Number. 0x5533 is ASCII for
                                                                 U3 (DWC_usb3).
                                                                  * SynopsysID[15:0] indicates the release number. Current Release is 2.50a. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_grlsid_s cn; */
} bdk_usbdrdx_uahc_grlsid_t;

static inline uint64_t BDK_USBDRDX_UAHC_GRLSID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GRLSID(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c120ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c120ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GRLSID", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GRLSID(a) bdk_usbdrdx_uahc_grlsid_t
#define bustype_BDK_USBDRDX_UAHC_GRLSID(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GRLSID(a) "USBDRDX_UAHC_GRLSID"
#define device_bar_BDK_USBDRDX_UAHC_GRLSID(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GRLSID(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GRLSID(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_grxfifoprihst
 *
 * UAHC RX FIFOs DMA Priority Register
 * This register specifies the relative DMA priority level among the host RXFIFOs (one per USB
 * bus instance) within the associated speed group (SuperSpeed or high-speed/full-speed/
 * low-speed). When multiple RXFIFOs compete for DMA service at a given time, the RXDMA arbiter
 * grants access on a packet-basis in the following manner:
 *
 * Among the FIFOs in the same speed group (SuperSpeed or high-speed/full-speed/low-speed):
 * * High-priority RXFIFOs are granted access using round-robin arbitration.
 * * Low-priority RXFIFOs are granted access using round-robin arbitration only after high-
 * priority
 * RXFIFOs have no further processing to do (i.e., either the RXQs are empty or the corresponding
 * RXFIFOs do not have the required data).
 *
 * The RX DMA arbiter prioritizes the SuperSpeed group or high-speed/full-speed/low-speed group
 * according to the ratio programmed in
 * USBDRD()_UAHC_GDMAHLRATIO.
 *
 * For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until
 * the entire packet is completed. The register size corresponds to the number of configured USB
 * bus instances; for example, in the default configuration, there are 3 USB bus instances (1
 * SuperSpeed, 1 high-speed, and 1 full-speed/low-speed).
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_grxfifoprihst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t rx_priority           : 3;  /**< [  2:  0](R/W) Each register bit[n] controls the priority (1 = high, 0 = low) of RXFIFO[n] within a speed group. */
#else /* Word 0 - Little Endian */
        uint32_t rx_priority           : 3;  /**< [  2:  0](R/W) Each register bit[n] controls the priority (1 = high, 0 = low) of RXFIFO[n] within a speed group. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_grxfifoprihst_s cn; */
} bdk_usbdrdx_uahc_grxfifoprihst_t;

static inline uint64_t BDK_USBDRDX_UAHC_GRXFIFOPRIHST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GRXFIFOPRIHST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c61cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c61cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GRXFIFOPRIHST", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) bdk_usbdrdx_uahc_grxfifoprihst_t
#define bustype_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) "USBDRDX_UAHC_GRXFIFOPRIHST"
#define device_bar_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GRXFIFOPRIHST(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_grxfifosiz#
 *
 * UAHC RX FIFO Size Register
 * The application can program the internal RAM start address/depth of the each RxFIFO as shown
 * below. It is recommended that software use the default value. In Host mode, per-port registers
 * are implemented. One register per FIFO.
 *
 * Reset values = 0:{0x0000_0084} 1:{0x0084_0104} 2:{0x0188_0180}.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.6.2.
 * INTERNAL: For more information, see the BMU section in Block Descriptions on Synopsys Databook
 * page 238.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_grxfifosizx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rxfstaddr             : 16; /**< [ 31: 16](R/W) RxFIFOn RAM start address. This field contains the memory start address for RxFIFOn. The
                                                                 reset value is derived from configuration parameters. */
        uint32_t rxfdep                : 16; /**< [ 15:  0](R/W) RxFIFOn depth. This value is in terms of RX RAM Data width.
                                                                 minimum value = 0x20, maximum value = 0x4000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value is derived from configuration parameters. */
#else /* Word 0 - Little Endian */
        uint32_t rxfdep                : 16; /**< [ 15:  0](R/W) RxFIFOn depth. This value is in terms of RX RAM Data width.
                                                                 minimum value = 0x20, maximum value = 0x4000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value is derived from configuration parameters. */
        uint32_t rxfstaddr             : 16; /**< [ 31: 16](R/W) RxFIFOn RAM start address. This field contains the memory start address for RxFIFOn. The
                                                                 reset value is derived from configuration parameters. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_grxfifosizx_s cn; */
} bdk_usbdrdx_uahc_grxfifosizx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GRXFIFOSIZX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GRXFIFOSIZX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=2)))
        return 0x86800000c380ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=2)))
        return 0x86800000c380ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x3);
    __bdk_csr_fatal("USBDRDX_UAHC_GRXFIFOSIZX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) bdk_usbdrdx_uahc_grxfifosizx_t
#define bustype_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) "USBDRDX_UAHC_GRXFIFOSIZX"
#define device_bar_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GRXFIFOSIZX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_grxthrcfg
 *
 * UAHC RX Threshold Control Register
 * In a normal case, an RX burst starts as soon as 1-packet space is available. This works well
 * as long as the system bus is faster than the USB3.0 bus (a 1024-bytes packet takes ~2.2 us on
 * the USB bus in SuperSpeed mode). If the system bus latency is larger than 2.2 us to access a
 * 1024-byte packet, then starting a burst on 1-packet condition leads to an early abort of the
 * burst causing unnecessary performance reduction. This register allows the configuration of
 * threshold and burst size control. This feature is enabled by USBRXPKTCNTSEL.
 *
 * Receive Path:
 * * The RX threshold is controlled by USBRXPKTCNT and the RX burst size is controlled by
 * USBMAXRXBURSTSIZE.
 * * Selecting optimal RX FIFO size, RX Threshold, and RX burst size avoids RX burst aborts due
 * to overrun if the system bus is slower than USB. Once in a while overrun is OK, and there is
 * no functional issue.
 * * Some devices do not support terminating ACK retry. With these devices, host cannot set ACK=0
 * and Retry=0 and do retry later and you have to retry immediately. For such devices, minimize
 * retry due to underrun. Setting threshold and burst size guarantees this.
 * A larger RX threshold affects the performance since the scheduler is idle during this time.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_grxthrcfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t usbrxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB receive-packet-count enable. Enables/disables the USB reception multipacket
                                                                 thresholding:
                                                                 0 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 one packet.
                                                                 1 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 USBRXPKTCNT amount of packets.
                                                                 This mode is only used for SuperSpeed.

                                                                 In device mode, setting this bit to 1 also enables the functionality of reporting
                                                                 NUMP in the ACK TP based on the RX FIFO space instead of reporting a fixed NUMP derived
                                                                 from USBDRD()_UAHC_DCFG[NUMP]. */
        uint32_t reserved_28           : 1;
        uint32_t usbrxpktcnt           : 4;  /**< [ 27: 24](R/W) USB receive-packet count. In host-mode, specifies space (in number of packets) that must
                                                                 be available in the RX FIFO before the core can start the corresponding USB RX transaction
                                                                 (burst).

                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXRXBURSTSIZE. */
        uint32_t usbmaxrxburstsize     : 5;  /**< [ 23: 19](R/W) USB maximum receive-burst size. Specifies the maximum bulk IN burst the core
                                                                 should do. When the system bus is slower than the USB, RX FIFO can overrun during a long
                                                                 burst.

                                                                 Program a smaller value to this field to limit the RX burst size that the core can do. It
                                                                 only applies to SuperSpeed Bulk, Isochronous, and Interrupt IN endpoints.
                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0x10. */
        uint32_t reserved_0_18         : 19;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_18         : 19;
        uint32_t usbmaxrxburstsize     : 5;  /**< [ 23: 19](R/W) USB maximum receive-burst size. Specifies the maximum bulk IN burst the core
                                                                 should do. When the system bus is slower than the USB, RX FIFO can overrun during a long
                                                                 burst.

                                                                 Program a smaller value to this field to limit the RX burst size that the core can do. It
                                                                 only applies to SuperSpeed Bulk, Isochronous, and Interrupt IN endpoints.
                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0x10. */
        uint32_t usbrxpktcnt           : 4;  /**< [ 27: 24](R/W) USB receive-packet count. In host-mode, specifies space (in number of packets) that must
                                                                 be available in the RX FIFO before the core can start the corresponding USB RX transaction
                                                                 (burst).

                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXRXBURSTSIZE. */
        uint32_t reserved_28           : 1;
        uint32_t usbrxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB receive-packet-count enable. Enables/disables the USB reception multipacket
                                                                 thresholding:
                                                                 0 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 one packet.
                                                                 1 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 USBRXPKTCNT amount of packets.
                                                                 This mode is only used for SuperSpeed.

                                                                 In device mode, setting this bit to 1 also enables the functionality of reporting
                                                                 NUMP in the ACK TP based on the RX FIFO space instead of reporting a fixed NUMP derived
                                                                 from USBDRD()_UAHC_DCFG[NUMP]. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    struct bdk_usbdrdx_uahc_grxthrcfg_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t usbrxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB receive-packet-count enable. Enables/disables the USB reception multipacket
                                                                 thresholding:
                                                                 0 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 one packet.
                                                                 1 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 USBRXPKTCNT amount of packets.
                                                                 This mode is only used for SuperSpeed.

                                                                 In device mode, setting this bit to 1 also enables the functionality of reporting
                                                                 NUMP in the ACK TP based on the RX FIFO space instead of reporting a fixed NUMP derived
                                                                 from USBDRD()_UAHC_DCFG[NUMP]. */
        uint32_t reserved_28           : 1;
        uint32_t usbrxpktcnt           : 4;  /**< [ 27: 24](R/W) USB receive-packet count. In host-mode, specifies space (in number of packets) that must
                                                                 be available in the RX FIFO before the core can start the corresponding USB RX transaction
                                                                 (burst).

                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXRXBURSTSIZE. */
        uint32_t usbmaxrxburstsize     : 5;  /**< [ 23: 19](R/W) USB maximum receive-burst size. Specifies the maximum bulk IN burst the core
                                                                 should do. When the system bus is slower than the USB, RX FIFO can overrun during a long
                                                                 burst.

                                                                 Program a smaller value to this field to limit the RX burst size that the core can do. It
                                                                 only applies to SuperSpeed Bulk, Isochronous, and Interrupt IN endpoints.
                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0x10. */
        uint32_t reserved_16_18        : 3;
        uint32_t reserved_15           : 1;
        uint32_t reserved_11_14        : 4;
        uint32_t reserved_0_10         : 11;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_10         : 11;
        uint32_t reserved_11_14        : 4;
        uint32_t reserved_15           : 1;
        uint32_t reserved_16_18        : 3;
        uint32_t usbmaxrxburstsize     : 5;  /**< [ 23: 19](R/W) USB maximum receive-burst size. Specifies the maximum bulk IN burst the core
                                                                 should do. When the system bus is slower than the USB, RX FIFO can overrun during a long
                                                                 burst.

                                                                 Program a smaller value to this field to limit the RX burst size that the core can do. It
                                                                 only applies to SuperSpeed Bulk, Isochronous, and Interrupt IN endpoints.
                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0x10. */
        uint32_t usbrxpktcnt           : 4;  /**< [ 27: 24](R/W) USB receive-packet count. In host-mode, specifies space (in number of packets) that must
                                                                 be available in the RX FIFO before the core can start the corresponding USB RX transaction
                                                                 (burst).

                                                                 This field is only valid when USBRXPKTCNTSEL = 1. The valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXRXBURSTSIZE. */
        uint32_t reserved_28           : 1;
        uint32_t usbrxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB receive-packet-count enable. Enables/disables the USB reception multipacket
                                                                 thresholding:
                                                                 0 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 one packet.
                                                                 1 = the core can only start reception on the USB when the RX FIFO has space for at least
                                                                 USBRXPKTCNT amount of packets.
                                                                 This mode is only used for SuperSpeed.

                                                                 In device mode, setting this bit to 1 also enables the functionality of reporting
                                                                 NUMP in the ACK TP based on the RX FIFO space instead of reporting a fixed NUMP derived
                                                                 from USBDRD()_UAHC_DCFG[NUMP]. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } cn;
} bdk_usbdrdx_uahc_grxthrcfg_t;

static inline uint64_t BDK_USBDRDX_UAHC_GRXTHRCFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GRXTHRCFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c10cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c10cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GRXTHRCFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GRXTHRCFG(a) bdk_usbdrdx_uahc_grxthrcfg_t
#define bustype_BDK_USBDRDX_UAHC_GRXTHRCFG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GRXTHRCFG(a) "USBDRDX_UAHC_GRXTHRCFG"
#define device_bar_BDK_USBDRDX_UAHC_GRXTHRCFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GRXTHRCFG(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GRXTHRCFG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gsbuscfg0
 *
 * UAHC Bus Configuration Register 0
 * This register can be used to configure the core after power-on or a change in mode of
 * operation. This register mainly contains AXI system-related configuration parameters. Do not
 * change this register after the initial programming. The application must program this register
 * before starting any transactions on AXI. When INCRBRSTENA is enabled, it has the highest
 * priority over other burst lengths. The core always performs the largest burst when enabled.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: The AXI cache signals are not connected in Cavium's hookup, so the *REQINFO fields
 * can be ignored.
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gsbuscfg0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t datrdreqinfo          : 4;  /**< [ 31: 28](R/W) AXI-cache for data-read operations. Always set to 0x0. */
        uint32_t desrdreqinfo          : 4;  /**< [ 27: 24](R/W) AXI-cache for descriptor-read operations. Always set to 0x0. */
        uint32_t datwrreqinfo          : 4;  /**< [ 23: 20](R/W) AXI-cache for data-write operations. Always set to 0x0. */
        uint32_t deswrreqinfo          : 4;  /**< [ 19: 16](R/W) AXI-cache for descriptor-write operations. Always set to 0x0. */
        uint32_t reserved_12_15        : 4;
        uint32_t datbigend             : 1;  /**< [ 11: 11](R/W) Data access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBDRD()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead.

                                                                 For diagnostic use only, drivers should be written assuming little-endian. */
        uint32_t descbigend            : 1;  /**< [ 10: 10](R/W) Descriptor access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBDRD()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead.

                                                                 For diagnostic use only, drivers should be written assuming little-endian. */
        uint32_t reserved_8_9          : 2;
        uint32_t incr256brstena        : 1;  /**< [  7:  7](R/W) INCR256 burst-type enable. Always set to 0. */
        uint32_t incr128brstena        : 1;  /**< [  6:  6](R/W) INCR128 burst-type enable. Always set to 0. */
        uint32_t incr64brstena         : 1;  /**< [  5:  5](R/W) INCR64 burst-type enable. Always set to 0. */
        uint32_t incr32brstena         : 1;  /**< [  4:  4](R/W) INCR32 burst-type enable. Always set to 0. */
        uint32_t incr16brstena         : 1;  /**< [  3:  3](R/W) INCR16 burst-type enable. Allows the AXI master to generate INCR 16-beat bursts. */
        uint32_t incr8brstena          : 1;  /**< [  2:  2](R/W) INCR8 burst-type enable. Allows the AXI master to generate INCR eight-beat bursts. */
        uint32_t incr4brstena          : 1;  /**< [  1:  1](R/W) INCR4 burst-type enable. Allows the AXI master to generate INCR four-beat bursts. */
        uint32_t incrbrstena           : 1;  /**< [  0:  0](R/W) Undefined-length INCR burst-type enable.
                                                                 This bit determines the set of burst lengths to be utilized by the master interface. It
                                                                 works in conjunction with the GSBUSCFG0[7:1] enables (INCR*BRSTENA).

                                                                 If disabled, the AXI master will use only the burst lengths
                                                                 1, 4, 8, 16 (assuming the INCR*BRSTENA are set to their reset values).

                                                                 If enabled, the AXI master uses any length less than or equal to the largest-enabled burst
                                                                 length based on the INCR*BRSTENA fields. */
#else /* Word 0 - Little Endian */
        uint32_t incrbrstena           : 1;  /**< [  0:  0](R/W) Undefined-length INCR burst-type enable.
                                                                 This bit determines the set of burst lengths to be utilized by the master interface. It
                                                                 works in conjunction with the GSBUSCFG0[7:1] enables (INCR*BRSTENA).

                                                                 If disabled, the AXI master will use only the burst lengths
                                                                 1, 4, 8, 16 (assuming the INCR*BRSTENA are set to their reset values).

                                                                 If enabled, the AXI master uses any length less than or equal to the largest-enabled burst
                                                                 length based on the INCR*BRSTENA fields. */
        uint32_t incr4brstena          : 1;  /**< [  1:  1](R/W) INCR4 burst-type enable. Allows the AXI master to generate INCR four-beat bursts. */
        uint32_t incr8brstena          : 1;  /**< [  2:  2](R/W) INCR8 burst-type enable. Allows the AXI master to generate INCR eight-beat bursts. */
        uint32_t incr16brstena         : 1;  /**< [  3:  3](R/W) INCR16 burst-type enable. Allows the AXI master to generate INCR 16-beat bursts. */
        uint32_t incr32brstena         : 1;  /**< [  4:  4](R/W) INCR32 burst-type enable. Always set to 0. */
        uint32_t incr64brstena         : 1;  /**< [  5:  5](R/W) INCR64 burst-type enable. Always set to 0. */
        uint32_t incr128brstena        : 1;  /**< [  6:  6](R/W) INCR128 burst-type enable. Always set to 0. */
        uint32_t incr256brstena        : 1;  /**< [  7:  7](R/W) INCR256 burst-type enable. Always set to 0. */
        uint32_t reserved_8_9          : 2;
        uint32_t descbigend            : 1;  /**< [ 10: 10](R/W) Descriptor access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBDRD()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead.

                                                                 For diagnostic use only, drivers should be written assuming little-endian. */
        uint32_t datbigend             : 1;  /**< [ 11: 11](R/W) Data access is big-endian. Keep this set to 0 (little-endian) and use the
                                                                 USBDRD()_UCTL_SHIM_CFG[DMA_ENDIAN_MODE] setting instead.

                                                                 For diagnostic use only, drivers should be written assuming little-endian. */
        uint32_t reserved_12_15        : 4;
        uint32_t deswrreqinfo          : 4;  /**< [ 19: 16](R/W) AXI-cache for descriptor-write operations. Always set to 0x0. */
        uint32_t datwrreqinfo          : 4;  /**< [ 23: 20](R/W) AXI-cache for data-write operations. Always set to 0x0. */
        uint32_t desrdreqinfo          : 4;  /**< [ 27: 24](R/W) AXI-cache for descriptor-read operations. Always set to 0x0. */
        uint32_t datrdreqinfo          : 4;  /**< [ 31: 28](R/W) AXI-cache for data-read operations. Always set to 0x0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gsbuscfg0_s cn; */
} bdk_usbdrdx_uahc_gsbuscfg0_t;

static inline uint64_t BDK_USBDRDX_UAHC_GSBUSCFG0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GSBUSCFG0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c100ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c100ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GSBUSCFG0", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GSBUSCFG0(a) bdk_usbdrdx_uahc_gsbuscfg0_t
#define bustype_BDK_USBDRDX_UAHC_GSBUSCFG0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GSBUSCFG0(a) "USBDRDX_UAHC_GSBUSCFG0"
#define device_bar_BDK_USBDRDX_UAHC_GSBUSCFG0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GSBUSCFG0(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GSBUSCFG0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gsbuscfg1
 *
 * UAHC Bus Configuration Register 1
 * This register can be used to configure the core after power-on or a change in mode of
 * operation. This register mainly contains AXI system-related configuration parameters. Do not
 * change this register after the initial programming. The application must program this register
 * before starting any transactions on AXI.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gsbuscfg1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t en1kpage              : 1;  /**< [ 12: 12](R/W) 1K page-boundary enable.
                                                                 0 = Break transfers at the 4K page boundary (default).
                                                                 1 = Break transfers at the 1K page boundary. */
        uint32_t pipetranslimit        : 4;  /**< [ 11:  8](R/W) AXI pipelined transfers burst-request limit. Controls the number of outstanding pipelined
                                                                 transfers requests the AXI master will push to the AXI slave. Once the AXI master reaches
                                                                 this limit, it does not make more requests on the AXI ARADDR and AWADDR buses until the
                                                                 associated data phases complete. This field is encoded as follows:
                                                                 0x0 = 1 request. 0x8 = 9 requests.
                                                                 0x1 = 2 requests. 0x9 = 10 requests.
                                                                 0x2 = 3 requests. 0xA = 11 requests.
                                                                 0x3 = 4 requests. 0xB = 12 requests.
                                                                 0x4 = 5 requests. 0xC = 13 requests.
                                                                 0x5 = 6 requests. 0xD = 14 requests.
                                                                 0x6 = 7 requests. 0xE = 15 requests.
                                                                 0x7 = 8 requests. 0xF = 16 requests. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t pipetranslimit        : 4;  /**< [ 11:  8](R/W) AXI pipelined transfers burst-request limit. Controls the number of outstanding pipelined
                                                                 transfers requests the AXI master will push to the AXI slave. Once the AXI master reaches
                                                                 this limit, it does not make more requests on the AXI ARADDR and AWADDR buses until the
                                                                 associated data phases complete. This field is encoded as follows:
                                                                 0x0 = 1 request. 0x8 = 9 requests.
                                                                 0x1 = 2 requests. 0x9 = 10 requests.
                                                                 0x2 = 3 requests. 0xA = 11 requests.
                                                                 0x3 = 4 requests. 0xB = 12 requests.
                                                                 0x4 = 5 requests. 0xC = 13 requests.
                                                                 0x5 = 6 requests. 0xD = 14 requests.
                                                                 0x6 = 7 requests. 0xE = 15 requests.
                                                                 0x7 = 8 requests. 0xF = 16 requests. */
        uint32_t en1kpage              : 1;  /**< [ 12: 12](R/W) 1K page-boundary enable.
                                                                 0 = Break transfers at the 4K page boundary (default).
                                                                 1 = Break transfers at the 1K page boundary. */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gsbuscfg1_s cn; */
} bdk_usbdrdx_uahc_gsbuscfg1_t;

static inline uint64_t BDK_USBDRDX_UAHC_GSBUSCFG1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GSBUSCFG1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c104ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c104ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GSBUSCFG1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GSBUSCFG1(a) bdk_usbdrdx_uahc_gsbuscfg1_t
#define bustype_BDK_USBDRDX_UAHC_GSBUSCFG1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GSBUSCFG1(a) "USBDRDX_UAHC_GSBUSCFG1"
#define device_bar_BDK_USBDRDX_UAHC_GSBUSCFG1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GSBUSCFG1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GSBUSCFG1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gsts
 *
 * UAHC Core Status Register
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.6.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gsts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cbelt                 : 12; /**< [ 31: 20](RO/H) Current BELT value. In host mode, indicates the minimum value of all received device BELT
                                                                 values and the BELT value that is set by the set latency tolerance value command. */
        uint32_t reserved_8_19         : 12;
        uint32_t host_ip               : 1;  /**< [  7:  7](RO/H) Host interrupt pending. Indicates that there is a pending interrupt pertaining to xHC in
                                                                 the host-event queue. */
        uint32_t device_ip             : 1;  /**< [  6:  6](RO/H) Device interrupt pending. Indicates that there is a pending interrupt pertaining to
                                                                 peripheral (device) operation in the Device event queue. */
        uint32_t csrtimeout            : 1;  /**< [  5:  5](R/W1C/H) CSR timeout. When set to 1, indicates that software performed a write or read operation to
                                                                 a core register that could not be completed within 0xFFFF controller-clock cycles. */
        uint32_t buserraddrvld         : 1;  /**< [  4:  4](R/W1C/H) Bus-error address valid. Indicates that USBDRD()_UAHC_GBUSERRADDR is valid and reports the
                                                                 first bus address that encounters a bus error. */
        uint32_t reserved_2_3          : 2;
        uint32_t curmod                : 2;  /**< [  1:  0](RO/H) Current mode of operation. 0x0 for device, 0x1 for host. */
#else /* Word 0 - Little Endian */
        uint32_t curmod                : 2;  /**< [  1:  0](RO/H) Current mode of operation. 0x0 for device, 0x1 for host. */
        uint32_t reserved_2_3          : 2;
        uint32_t buserraddrvld         : 1;  /**< [  4:  4](R/W1C/H) Bus-error address valid. Indicates that USBDRD()_UAHC_GBUSERRADDR is valid and reports the
                                                                 first bus address that encounters a bus error. */
        uint32_t csrtimeout            : 1;  /**< [  5:  5](R/W1C/H) CSR timeout. When set to 1, indicates that software performed a write or read operation to
                                                                 a core register that could not be completed within 0xFFFF controller-clock cycles. */
        uint32_t device_ip             : 1;  /**< [  6:  6](RO/H) Device interrupt pending. Indicates that there is a pending interrupt pertaining to
                                                                 peripheral (device) operation in the Device event queue. */
        uint32_t host_ip               : 1;  /**< [  7:  7](RO/H) Host interrupt pending. Indicates that there is a pending interrupt pertaining to xHC in
                                                                 the host-event queue. */
        uint32_t reserved_8_19         : 12;
        uint32_t cbelt                 : 12; /**< [ 31: 20](RO/H) Current BELT value. In host mode, indicates the minimum value of all received device BELT
                                                                 values and the BELT value that is set by the set latency tolerance value command. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gsts_s cn; */
} bdk_usbdrdx_uahc_gsts_t;

static inline uint64_t BDK_USBDRDX_UAHC_GSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GSTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c118ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c118ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GSTS(a) bdk_usbdrdx_uahc_gsts_t
#define bustype_BDK_USBDRDX_UAHC_GSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GSTS(a) "USBDRDX_UAHC_GSTS"
#define device_bar_BDK_USBDRDX_UAHC_GSTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GSTS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GSTS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gtxfifopridev
 *
 * UAHC TX FIFOs DMA Priority Register
 * This register specifies the relative DMA priority level among the host TXFIFOs (one per USB
 * bus instance) within the associated speed group (SuperSpeed or high-speed/full-speed/
 * low-speed). When multiple TXFIFOs compete for DMA service at a given time, the TXDMA arbiter
 * grants access on a packet-basis in the following manner:
 *
 * Among the FIFOs in the same speed group (SuperSpeed or high-speed/full-speed/low-speed):
 *
 * * High-priority TXFIFOs are granted access using round-robin arbitration.
 * * Low-priority TXFIFOs are granted access using round-robin arbitration only after high-
 * priority
 * TXFIFOs have no further processing to do (i.e., either the TXQs are empty or the corresponding
 * TXFIFOs do not have the required data).
 *
 * The TX DMA arbiter prioritizes the SuperSpeed group or high-speed/full-speed/low-speed group
 * according to the ratio programmed in
 * USBDRD()_UAHC_GDMAHLRATIO.
 *
 * For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until
 * the entire packet is completed. The register size corresponds to the number of configured USB
 * bus instances; for example, in the default configuration, there are 3 USB bus instances (1
 * SuperSpeed, 1 high-speed, and 1 full-speed/low-speed).
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.9.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gtxfifopridev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t tx_priority           : 3;  /**< [  2:  0](R/W) Each register bit n controls the priority (1: high, 0: low) of TX FIFO<n> within a speed
                                                                 group. */
#else /* Word 0 - Little Endian */
        uint32_t tx_priority           : 3;  /**< [  2:  0](R/W) Each register bit n controls the priority (1: high, 0: low) of TX FIFO<n> within a speed
                                                                 group. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gtxfifopridev_s cn; */
} bdk_usbdrdx_uahc_gtxfifopridev_t;

static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c610ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c610ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GTXFIFOPRIDEV", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) bdk_usbdrdx_uahc_gtxfifopridev_t
#define bustype_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) "USBDRDX_UAHC_GTXFIFOPRIDEV"
#define device_bar_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GTXFIFOPRIDEV(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gtxfifoprihst
 *
 * Global Host TX FIFO DMA Priority Register
 * This register specifies the relative DMA priority level among the Host TXFIFOs (one per USB
 * bus instance) within the associated speed group (SuperSpeed or HighSpeed/FullSpeed/LowSpeed).
 * When multiple TXFIFOs compete for DMA service at a given time, the TXDMA arbiter grants access
 * on a packet-basis in the following manner:
 *
 *   1. Among the FIFOs in the same speed group (SuperSpeed or HighSpeed/FullSpeed/LowSpeed):
 *
 * _   a. High-priority TXFIFOs are granted access using round-robin arbitration
 *
 * _   b. Low-priority TXFIFOs are granted access using round-robin arbitration only after the
 *        high priority TXFIFOs have no further processing to do (i.e., either the TXQs are empty
 *        or thecorresponding TXFIFOs are full).
 *
 *   2. The TX DMA arbiter prioritizes the SuperSpeed group or HighSpeed/FullSpeed/LowSpeed group
 *      according to the ratio programmed in the USBDRD()_UAHC_GDMAHLRATIO register.
 *
 * For scatter-gather packets, the arbiter grants successive DMA requests to the same FIFO until
 * the entire packet is completed.
 * The register size corresponds to the number of configured USB bus instances; for example, in
 * the default configuration, there are 3 USB bus instances (1 SuperSpeed, 1 HighSpeed, and 1
 * FullSpeed/LowSpeed).
 *
 * This register can be reset by IOI reset or with USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.80a, section 6.2.9.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gtxfifoprihst_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_3_31         : 29;
        uint32_t tx_priority           : 3;  /**< [  2:  0](R/W) Each register bit n controls the priority (1: high, 0: low) of TX FIFO<n> within a speed
                                                                 group. */
#else /* Word 0 - Little Endian */
        uint32_t tx_priority           : 3;  /**< [  2:  0](R/W) Each register bit n controls the priority (1: high, 0: low) of TX FIFO<n> within a speed
                                                                 group. */
        uint32_t reserved_3_31         : 29;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gtxfifoprihst_s cn; */
} bdk_usbdrdx_uahc_gtxfifoprihst_t;

static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOPRIHST(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOPRIHST(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c618ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c618ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GTXFIFOPRIHST", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) bdk_usbdrdx_uahc_gtxfifoprihst_t
#define bustype_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) "USBDRDX_UAHC_GTXFIFOPRIHST"
#define device_bar_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GTXFIFOPRIHST(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gtxfifosiz#
 *
 * UAHC TX FIFO Size Registers
 * This register holds the internal RAM start address/depth of each TxFIFO implemented. Unless
 * packet size/buffer size for each endpoint is different and application-specific, it is
 * recommended that the software use the default value. One register per FIFO. One register per
 * FIFO.
 *
 * Reset values = 0:{0x0000_0082} 1:{0x0082_0103} 2:{0x0185_0205}.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.6.1.
 * INTERNAL: For more information, refer to the BMU section in Block Descriptions on Synopsys
 * Databook page 238.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gtxfifosizx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t txfstaddr             : 16; /**< [ 31: 16](R/W) Transmit FIFOn RAM start address. Contains the memory start address for TxFIFOn. The reset
                                                                 is value derived from configuration parameters. */
        uint32_t txfdep                : 16; /**< [ 15:  0](R/W) TxFIFOn depth. This value is in terms of TX RAM data width.
                                                                 minimum value = 0x20, maximum value = 0x8000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value derived from configuration parameters. */
#else /* Word 0 - Little Endian */
        uint32_t txfdep                : 16; /**< [ 15:  0](R/W) TxFIFOn depth. This value is in terms of TX RAM data width.
                                                                 minimum value = 0x20, maximum value = 0x8000.
                                                                 INTERNAL: For more information, see the Hardware Integration chapter of the Synopsys
                                                                 Databook.
                                                                 The reset value derived from configuration parameters. */
        uint32_t txfstaddr             : 16; /**< [ 31: 16](R/W) Transmit FIFOn RAM start address. Contains the memory start address for TxFIFOn. The reset
                                                                 is value derived from configuration parameters. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gtxfifosizx_s cn; */
} bdk_usbdrdx_uahc_gtxfifosizx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOSIZX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GTXFIFOSIZX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=3)))
        return 0x86800000c300ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=3)))
        return 0x86800000c300ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x3);
    __bdk_csr_fatal("USBDRDX_UAHC_GTXFIFOSIZX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) bdk_usbdrdx_uahc_gtxfifosizx_t
#define bustype_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) "USBDRDX_UAHC_GTXFIFOSIZX"
#define device_bar_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GTXFIFOSIZX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gtxthrcfg
 *
 * UAHC TX Threshold Control Register
 * In a normal case, a TX burst starts as soon as one packet is prefetched. This works well as
 * long as the system bus is faster than the USB3.0 bus (a 1024-bytes packet takes ~2.2 us on the
 * USB bus in SuperSpeed mode). If the system bus latency is larger than 2.2 us to access a
 * 1024-byte packet, then starting a burst on 1-packet condition leads to an early abort of the
 * burst causing unnecessary performance reduction. This register allows the configuration of
 * threshold and burst size control. This feature is enabled by [USBTXPKTCNTSEL].
 *
 * Transmit Path:
 * * The TX Threshold is controlled by [USBTXPKTCNT], and the TX burst size is controlled by
 * [USBMAXTXBURSTSIZE].
 * * Selecting optimal TX FIFO size, TX Threshold, and TX burst size avoids TX burst aborts due
 * to an underrun if the system bus is slower than USB. Once in a while an underrun is OK, and
 * there is no functional issue.
 * * A larger threshold affects the performance, since the scheduler is idle during this time.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gtxthrcfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t usbtxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB transmit packet-count enable. Enables/disables the USB transmission multipacket
                                                                 thresholding:
                                                                 0 = USB transmission multipacket thresholding is disabled, the core can only start
                                                                 transmission on the USB after the entire packet has been fetched into the corresponding
                                                                 TXFIFO.
                                                                 1 = USB transmission multipacket thresholding is enabled. The core can only start
                                                                 transmission on the USB after USBTXPKTCNT amount of packets for the USB transaction
                                                                 (burst) are already in the corresponding TXFIFO.
                                                                 This mode is only used for SuperSpeed. */
        uint32_t reserved_28           : 1;
        uint32_t usbtxpktcnt           : 4;  /**< [ 27: 24](R/W) USB transmit-packet count. Specifies the number of packets that must be in the TXFIFO
                                                                 before the core can start transmission for the corresponding USB transaction (burst). This
                                                                 field is only valid when USBTXPKTCNTSEL = 1. Valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXTXBURSTSIZE. */
        uint32_t usbmaxtxburstsize     : 8;  /**< [ 23: 16](R/W) USB maximum TX burst size. When USBTXPKTCNTSEL = 1, this field specifies the maximum bulk
                                                                 OUT burst the core should do. When the system bus is slower than the USB, TX FIFO can
                                                                 underrun during a long burst. Program a smaller value to this field to limit the TX burst
                                                                 size that the core can do. It only applies to SuperSpeed Bulk, Isochronous, and Interrupt
                                                                 OUT endpoints in the host mode. Valid values are from 0x1 to 0x10. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t usbmaxtxburstsize     : 8;  /**< [ 23: 16](R/W) USB maximum TX burst size. When USBTXPKTCNTSEL = 1, this field specifies the maximum bulk
                                                                 OUT burst the core should do. When the system bus is slower than the USB, TX FIFO can
                                                                 underrun during a long burst. Program a smaller value to this field to limit the TX burst
                                                                 size that the core can do. It only applies to SuperSpeed Bulk, Isochronous, and Interrupt
                                                                 OUT endpoints in the host mode. Valid values are from 0x1 to 0x10. */
        uint32_t usbtxpktcnt           : 4;  /**< [ 27: 24](R/W) USB transmit-packet count. Specifies the number of packets that must be in the TXFIFO
                                                                 before the core can start transmission for the corresponding USB transaction (burst). This
                                                                 field is only valid when USBTXPKTCNTSEL = 1. Valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXTXBURSTSIZE. */
        uint32_t reserved_28           : 1;
        uint32_t usbtxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB transmit packet-count enable. Enables/disables the USB transmission multipacket
                                                                 thresholding:
                                                                 0 = USB transmission multipacket thresholding is disabled, the core can only start
                                                                 transmission on the USB after the entire packet has been fetched into the corresponding
                                                                 TXFIFO.
                                                                 1 = USB transmission multipacket thresholding is enabled. The core can only start
                                                                 transmission on the USB after USBTXPKTCNT amount of packets for the USB transaction
                                                                 (burst) are already in the corresponding TXFIFO.
                                                                 This mode is only used for SuperSpeed. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } s;
    struct bdk_usbdrdx_uahc_gtxthrcfg_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_30_31        : 2;
        uint32_t usbtxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB transmit packet-count enable. Enables/disables the USB transmission multipacket
                                                                 thresholding:
                                                                 0 = USB transmission multipacket thresholding is disabled, the core can only start
                                                                 transmission on the USB after the entire packet has been fetched into the corresponding
                                                                 TXFIFO.
                                                                 1 = USB transmission multipacket thresholding is enabled. The core can only start
                                                                 transmission on the USB after USBTXPKTCNT amount of packets for the USB transaction
                                                                 (burst) are already in the corresponding TXFIFO.
                                                                 This mode is only used for SuperSpeed. */
        uint32_t reserved_28           : 1;
        uint32_t usbtxpktcnt           : 4;  /**< [ 27: 24](R/W) USB transmit-packet count. Specifies the number of packets that must be in the TXFIFO
                                                                 before the core can start transmission for the corresponding USB transaction (burst). This
                                                                 field is only valid when USBTXPKTCNTSEL = 1. Valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXTXBURSTSIZE. */
        uint32_t usbmaxtxburstsize     : 8;  /**< [ 23: 16](R/W) USB maximum TX burst size. When USBTXPKTCNTSEL = 1, this field specifies the maximum bulk
                                                                 OUT burst the core should do. When the system bus is slower than the USB, TX FIFO can
                                                                 underrun during a long burst. Program a smaller value to this field to limit the TX burst
                                                                 size that the core can do. It only applies to SuperSpeed Bulk, Isochronous, and Interrupt
                                                                 OUT endpoints in the host mode. Valid values are from 0x1 to 0x10. */
        uint32_t reserved_14_15        : 2;
        uint32_t reserved_10_13        : 4;
        uint32_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_9          : 10;
        uint32_t reserved_10_13        : 4;
        uint32_t reserved_14_15        : 2;
        uint32_t usbmaxtxburstsize     : 8;  /**< [ 23: 16](R/W) USB maximum TX burst size. When USBTXPKTCNTSEL = 1, this field specifies the maximum bulk
                                                                 OUT burst the core should do. When the system bus is slower than the USB, TX FIFO can
                                                                 underrun during a long burst. Program a smaller value to this field to limit the TX burst
                                                                 size that the core can do. It only applies to SuperSpeed Bulk, Isochronous, and Interrupt
                                                                 OUT endpoints in the host mode. Valid values are from 0x1 to 0x10. */
        uint32_t usbtxpktcnt           : 4;  /**< [ 27: 24](R/W) USB transmit-packet count. Specifies the number of packets that must be in the TXFIFO
                                                                 before the core can start transmission for the corresponding USB transaction (burst). This
                                                                 field is only valid when USBTXPKTCNTSEL = 1. Valid values are from 0x1 to 0xF.
                                                                 This field must be <= USBMAXTXBURSTSIZE. */
        uint32_t reserved_28           : 1;
        uint32_t usbtxpktcntsel        : 1;  /**< [ 29: 29](R/W) USB transmit packet-count enable. Enables/disables the USB transmission multipacket
                                                                 thresholding:
                                                                 0 = USB transmission multipacket thresholding is disabled, the core can only start
                                                                 transmission on the USB after the entire packet has been fetched into the corresponding
                                                                 TXFIFO.
                                                                 1 = USB transmission multipacket thresholding is enabled. The core can only start
                                                                 transmission on the USB after USBTXPKTCNT amount of packets for the USB transaction
                                                                 (burst) are already in the corresponding TXFIFO.
                                                                 This mode is only used for SuperSpeed. */
        uint32_t reserved_30_31        : 2;
#endif /* Word 0 - End */
    } cn;
} bdk_usbdrdx_uahc_gtxthrcfg_t;

static inline uint64_t BDK_USBDRDX_UAHC_GTXTHRCFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GTXTHRCFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c108ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c108ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GTXTHRCFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GTXTHRCFG(a) bdk_usbdrdx_uahc_gtxthrcfg_t
#define bustype_BDK_USBDRDX_UAHC_GTXTHRCFG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GTXTHRCFG(a) "USBDRDX_UAHC_GTXTHRCFG"
#define device_bar_BDK_USBDRDX_UAHC_GTXTHRCFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GTXTHRCFG(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GTXTHRCFG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_guctl
 *
 * UAHC Core User-Control Register
 * This register provides a few options for the software to control the core behavior in the host
 * mode. Most of the options are used to improve host inter-operability with different devices.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.11.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_guctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t refclkper             : 10; /**< [ 31: 22](R/W) Reference-clock period. Indicates (in terms of ns) the period of REF_CLK. The default
                                                                 value is set to 0x8
                                                                 (8 ns/125 MHz). This field must be updated during power on initialization if
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1 or USBDRD()_UAHC_GFLADJ [GFLADJ_REFCLK_LPM_SEL] = 1.
                                                                 The
                                                                 programmable maximum value 62 ns, and the minimum value is 8 ns. You use a reference clock
                                                                 with a period that is a integer multiple, so that ITP can meet the jitter margin of 32 ns.
                                                                 The allowable REF_CLK frequencies whose period is not integer multiples are
                                                                 16/17/19.2/24/39.7 MHz.

                                                                 This field should not be set to 0x0 at any time. If you do not plan to use this feature,
                                                                 then you need to set this field to 0x8, the default value. */
        uint32_t noextrdl              : 1;  /**< [ 21: 21](R/W) No extra delay between SOF and the first packet.
                                                                 Some high-speed devices misbehave when the host sends a packet immediately after an SOF.
                                                                 However, adding an extra delay between an SOF and the first packet can reduce the USB data
                                                                 rate and performance.

                                                                 This bit is used to control whether the host should wait for 2 us before it sends the
                                                                 first packet after a SOF, or not. You can set this bit to 1 to improve the performance if
                                                                 those problematic devices are not a concern in your host environment.
                                                                 0 = host waits for 2 us after an SOF before it sends the first USB packet.
                                                                 1 = host does not wait after an SOF before it sends the first USB packet. */
        uint32_t psqextrressp          : 3;  /**< [ 20: 18](R/W) PSQ extra reserved space. This is a debug feature, and is not intended for normal usage.
                                                                 This parameter specifies how much additional space in the PSQ (protocol-status queue) must
                                                                 be reserved before the U3PTL initiates a new USB transaction and burst beats. */
        uint32_t sprsctrltransen       : 1;  /**< [ 17: 17](R/W) Sparse control transaction enable. Some devices are slow in responding to control
                                                                 transfers. Scheduling multiple transactions in one microframe/frame can cause these
                                                                 devices to misbehave. If this bit is set to 1, the host controller schedules transactions
                                                                 for a control transfer in different microframes/frames. */
        uint32_t resbwhseps            : 1;  /**< [ 16: 16](R/W) Reserving 85% bandwidth for high-speed periodic EPs. By default, host controller reserves
                                                                 80% of the bandwidth for periodic EPs. If this bit is set, the bandwidth is relaxed to 85%
                                                                 to accommodate two high-speed, high-bandwidth ISOC EPs.

                                                                 USB 2.0 required 80% bandwidth allocated for ISOC traffic. If two high bandwidth ISOC
                                                                 devices (HD webcams) are connected, and if each requires 1024-bytes * 3 packets per
                                                                 microframe, then the bandwidth required is around 82%. If this bit is set to 1, it is
                                                                 possible to connect two webcams of 1024 bytes * 3 payload per microframe each. Otherwise,
                                                                 you may have to reduce the resolution of the webcams. */
        uint32_t cmdevaddr             : 1;  /**< [ 15: 15](R/W) Compliance mode for device address. When set to 1, slot ID can have different value than
                                                                 device address if max_slot_enabled < 128.
                                                                 0 = Device address is equal to slot ID.
                                                                 1 = Increment device address on each address device command.

                                                                 The xHCI compliance requires this bit to be set to 1. The 0 mode is for debug purpose
                                                                 only. This allows you to easily identify a device connected to a port in the Lecroy or
                                                                 Eliisys trace during hardware debug.

                                                                 This bit is used in host mode only. */
        uint32_t usbdrdstinautoretryen : 1;  /**< [ 14: 14](R/W) Host IN auto-retry enable. When set, this field enables the auto-retry feature. For IN
                                                                 transfers (non-isochronous) that encounter data packets with CRC errors or internal
                                                                 overrun scenarios, the auto-retry feature causes the host core to reply to the device with
                                                                 a non-terminating retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP != 0).
                                                                 If the auto-retry feature is disabled (default), the core responds with a terminating
                                                                 retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP = 0). */
        uint32_t enoverlapchk          : 1;  /**< [ 13: 13](R/W) Enable check for LFPS overlap during remote Ux Exit. If this bit is set to:
                                                                 0 = When the link exists U1/U2/U3 because of a remote exit, it does not look for an LFPS
                                                                 overlap.
                                                                 1 = The SuperSpeed link, when exiting U1/U2/U3, waits for either the remote link LFPS or
                                                                 TS1/TS2 training symbols before it confirms that the LFPS handshake is complete. This is
                                                                 done to handle the case where the LFPS glitch causes the link to start exiting from the
                                                                 low power state. Looking for the LFPS overlap makes sure that the link partner also sees
                                                                 the LFPS. */
        uint32_t extcapsupten          : 1;  /**< [ 12: 12](R/W) External extended capability support enable. If disabled, a read
                                                                 USBDRD()_UAHC_SUPTPRT3_DW0
                                                                 [NEXTCAPPTR] returns 0 in the next capability pointer field. This indicates there are no
                                                                 more capabilities. If enabled, a read to USBDRD()_UAHC_SUPTPRT3_DW0[NEXTCAPPTR] returns 4
                                                                 in
                                                                 the
                                                                 next capability pointer field.
                                                                 Always set to 0x0. */
        uint32_t insrtextrfsbodi       : 1;  /**< [ 11: 11](R/W) Insert extra delay between full-speed bulk OUT transactions. Some full-speed devices are
                                                                 slow to receive bulk OUT data and can get stuck when there are consecutive bulk OUT
                                                                 transactions with short inter-transaction delays. This bit is used to control whether the
                                                                 host inserts extra delay between consecutive bulk OUT transactions to a full-speed
                                                                 endpoint.
                                                                 0 = Host does not insert extra delay.
                                                                 Setting this bit to 1 reduces the bulk OUT transfer performance for most of the full-speed
                                                                 devices.
                                                                 1 = Host inserts about 12 us extra delay between consecutive bulk OUT transactions to an
                                                                 full-speed endpoint to work around the device issue. */
        uint32_t dtct                  : 2;  /**< [ 10:  9](R/W) Device timeout coarse tuning. This field determines how long the host waits for a response
                                                                 from device before considering a timeout.
                                                                 The core first checks the DTCT value. If it is 0, then the timeout value is defined by the
                                                                 DTFT. If it is non-zero, then it uses the following timeout values:
                                                                 0x0 = 0 us; use DTFT value instead.
                                                                 0x1 = 500 us.
                                                                 0x2 = 1.5 ms.
                                                                 0x3 = 6.5 ms. */
        uint32_t dtft                  : 9;  /**< [  8:  0](R/W) Device timeout fine tuning. This field determines how long the host waits for a response
                                                                 from a device before considering a timeout. For DTFT to take effect, DTCT must be set to
                                                                 0x0.
                                                                 The DTFT value specifies the number of 125MHz clock cycles * 256 to count before
                                                                 considering a device timeout. For the 125 MHz clock cycles (8 ns period), this is
                                                                 calculated as follows:
                                                                 _ [DTFT value] * 256 * 8 (ns)
                                                                 0x2 = 2 * 256 * 8 -> 4 us.
                                                                 0x5 = 5 * 256 * 8 -> 10 us.
                                                                 0xA = 10 * 256 * 8 -> 20 us.
                                                                 0x10 = 16 * 256 * 8 -> 32 us.
                                                                 0x19 = 25 * 256 * 8 -> 51 us.
                                                                 0x31 = 49 * 256 * 8 -> 100 us.
                                                                 0x62 = 98 * 256 * 8 -> 200 us. */
#else /* Word 0 - Little Endian */
        uint32_t dtft                  : 9;  /**< [  8:  0](R/W) Device timeout fine tuning. This field determines how long the host waits for a response
                                                                 from a device before considering a timeout. For DTFT to take effect, DTCT must be set to
                                                                 0x0.
                                                                 The DTFT value specifies the number of 125MHz clock cycles * 256 to count before
                                                                 considering a device timeout. For the 125 MHz clock cycles (8 ns period), this is
                                                                 calculated as follows:
                                                                 _ [DTFT value] * 256 * 8 (ns)
                                                                 0x2 = 2 * 256 * 8 -> 4 us.
                                                                 0x5 = 5 * 256 * 8 -> 10 us.
                                                                 0xA = 10 * 256 * 8 -> 20 us.
                                                                 0x10 = 16 * 256 * 8 -> 32 us.
                                                                 0x19 = 25 * 256 * 8 -> 51 us.
                                                                 0x31 = 49 * 256 * 8 -> 100 us.
                                                                 0x62 = 98 * 256 * 8 -> 200 us. */
        uint32_t dtct                  : 2;  /**< [ 10:  9](R/W) Device timeout coarse tuning. This field determines how long the host waits for a response
                                                                 from device before considering a timeout.
                                                                 The core first checks the DTCT value. If it is 0, then the timeout value is defined by the
                                                                 DTFT. If it is non-zero, then it uses the following timeout values:
                                                                 0x0 = 0 us; use DTFT value instead.
                                                                 0x1 = 500 us.
                                                                 0x2 = 1.5 ms.
                                                                 0x3 = 6.5 ms. */
        uint32_t insrtextrfsbodi       : 1;  /**< [ 11: 11](R/W) Insert extra delay between full-speed bulk OUT transactions. Some full-speed devices are
                                                                 slow to receive bulk OUT data and can get stuck when there are consecutive bulk OUT
                                                                 transactions with short inter-transaction delays. This bit is used to control whether the
                                                                 host inserts extra delay between consecutive bulk OUT transactions to a full-speed
                                                                 endpoint.
                                                                 0 = Host does not insert extra delay.
                                                                 Setting this bit to 1 reduces the bulk OUT transfer performance for most of the full-speed
                                                                 devices.
                                                                 1 = Host inserts about 12 us extra delay between consecutive bulk OUT transactions to an
                                                                 full-speed endpoint to work around the device issue. */
        uint32_t extcapsupten          : 1;  /**< [ 12: 12](R/W) External extended capability support enable. If disabled, a read
                                                                 USBDRD()_UAHC_SUPTPRT3_DW0
                                                                 [NEXTCAPPTR] returns 0 in the next capability pointer field. This indicates there are no
                                                                 more capabilities. If enabled, a read to USBDRD()_UAHC_SUPTPRT3_DW0[NEXTCAPPTR] returns 4
                                                                 in
                                                                 the
                                                                 next capability pointer field.
                                                                 Always set to 0x0. */
        uint32_t enoverlapchk          : 1;  /**< [ 13: 13](R/W) Enable check for LFPS overlap during remote Ux Exit. If this bit is set to:
                                                                 0 = When the link exists U1/U2/U3 because of a remote exit, it does not look for an LFPS
                                                                 overlap.
                                                                 1 = The SuperSpeed link, when exiting U1/U2/U3, waits for either the remote link LFPS or
                                                                 TS1/TS2 training symbols before it confirms that the LFPS handshake is complete. This is
                                                                 done to handle the case where the LFPS glitch causes the link to start exiting from the
                                                                 low power state. Looking for the LFPS overlap makes sure that the link partner also sees
                                                                 the LFPS. */
        uint32_t usbdrdstinautoretryen : 1;  /**< [ 14: 14](R/W) Host IN auto-retry enable. When set, this field enables the auto-retry feature. For IN
                                                                 transfers (non-isochronous) that encounter data packets with CRC errors or internal
                                                                 overrun scenarios, the auto-retry feature causes the host core to reply to the device with
                                                                 a non-terminating retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP != 0).
                                                                 If the auto-retry feature is disabled (default), the core responds with a terminating
                                                                 retry ACK (i.e. an ACK transaction packet with Retry = 1 and NumP = 0). */
        uint32_t cmdevaddr             : 1;  /**< [ 15: 15](R/W) Compliance mode for device address. When set to 1, slot ID can have different value than
                                                                 device address if max_slot_enabled < 128.
                                                                 0 = Device address is equal to slot ID.
                                                                 1 = Increment device address on each address device command.

                                                                 The xHCI compliance requires this bit to be set to 1. The 0 mode is for debug purpose
                                                                 only. This allows you to easily identify a device connected to a port in the Lecroy or
                                                                 Eliisys trace during hardware debug.

                                                                 This bit is used in host mode only. */
        uint32_t resbwhseps            : 1;  /**< [ 16: 16](R/W) Reserving 85% bandwidth for high-speed periodic EPs. By default, host controller reserves
                                                                 80% of the bandwidth for periodic EPs. If this bit is set, the bandwidth is relaxed to 85%
                                                                 to accommodate two high-speed, high-bandwidth ISOC EPs.

                                                                 USB 2.0 required 80% bandwidth allocated for ISOC traffic. If two high bandwidth ISOC
                                                                 devices (HD webcams) are connected, and if each requires 1024-bytes * 3 packets per
                                                                 microframe, then the bandwidth required is around 82%. If this bit is set to 1, it is
                                                                 possible to connect two webcams of 1024 bytes * 3 payload per microframe each. Otherwise,
                                                                 you may have to reduce the resolution of the webcams. */
        uint32_t sprsctrltransen       : 1;  /**< [ 17: 17](R/W) Sparse control transaction enable. Some devices are slow in responding to control
                                                                 transfers. Scheduling multiple transactions in one microframe/frame can cause these
                                                                 devices to misbehave. If this bit is set to 1, the host controller schedules transactions
                                                                 for a control transfer in different microframes/frames. */
        uint32_t psqextrressp          : 3;  /**< [ 20: 18](R/W) PSQ extra reserved space. This is a debug feature, and is not intended for normal usage.
                                                                 This parameter specifies how much additional space in the PSQ (protocol-status queue) must
                                                                 be reserved before the U3PTL initiates a new USB transaction and burst beats. */
        uint32_t noextrdl              : 1;  /**< [ 21: 21](R/W) No extra delay between SOF and the first packet.
                                                                 Some high-speed devices misbehave when the host sends a packet immediately after an SOF.
                                                                 However, adding an extra delay between an SOF and the first packet can reduce the USB data
                                                                 rate and performance.

                                                                 This bit is used to control whether the host should wait for 2 us before it sends the
                                                                 first packet after a SOF, or not. You can set this bit to 1 to improve the performance if
                                                                 those problematic devices are not a concern in your host environment.
                                                                 0 = host waits for 2 us after an SOF before it sends the first USB packet.
                                                                 1 = host does not wait after an SOF before it sends the first USB packet. */
        uint32_t refclkper             : 10; /**< [ 31: 22](R/W) Reference-clock period. Indicates (in terms of ns) the period of REF_CLK. The default
                                                                 value is set to 0x8
                                                                 (8 ns/125 MHz). This field must be updated during power on initialization if
                                                                 USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1 or USBDRD()_UAHC_GFLADJ [GFLADJ_REFCLK_LPM_SEL] = 1.
                                                                 The
                                                                 programmable maximum value 62 ns, and the minimum value is 8 ns. You use a reference clock
                                                                 with a period that is a integer multiple, so that ITP can meet the jitter margin of 32 ns.
                                                                 The allowable REF_CLK frequencies whose period is not integer multiples are
                                                                 16/17/19.2/24/39.7 MHz.

                                                                 This field should not be set to 0x0 at any time. If you do not plan to use this feature,
                                                                 then you need to set this field to 0x8, the default value. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_guctl_s cn; */
} bdk_usbdrdx_uahc_guctl_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUCTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c12cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c12cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GUCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUCTL(a) bdk_usbdrdx_uahc_guctl_t
#define bustype_BDK_USBDRDX_UAHC_GUCTL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUCTL(a) "USBDRDX_UAHC_GUCTL"
#define device_bar_BDK_USBDRDX_UAHC_GUCTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUCTL(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GUCTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_guctl1
 *
 * UAHC Global User Control Register 1
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.7.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_guctl1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_18_31        : 14;
        uint32_t parkmode_disable_ss   : 1;  /**< [ 17: 17](R/W) This bit is for debug purpose only.
                                                                 When this bit is set to 1 all SS bus instances in park mode are
                                                                 disabled. */
        uint32_t parkmode_disable_hs   : 1;  /**< [ 16: 16](R/W) When this bit is set to 1 all HS bus instances park mode are
                                                                 disabled. */
        uint32_t parkmode_disable_fsls : 1;  /**< [ 15: 15](R/W) When this bit is set to 1 all FS/LS bus instances park mode are
                                                                 disabled. */
        uint32_t reserved_9_14         : 6;
        uint32_t l1_susp_thrld_en_for_host : 1;/**< [  8:  8](R/W) The controller puts the PHY into deep low-power mode in L1 when both of the
                                                                 following are true:

                                                                 * The HIRD/BESL value used is greater than or equal to the
                                                                   value in L1_SUSP_THRLD_FOR_HOST field.
                                                                 * The L1_SUSP_THRLD_EN_FOR_HOST bit is set.

                                                                 The controller the UTMI PHY transitions to shallow low-power
                                                                 mode in L1 by powering down necessary blocks when one of the
                                                                 following is true:

                                                                 * The HIRD/BESL value used is less than the value in
                                                                   L1_SUSP_THRLD_FOR_HOST field.
                                                                 * The L1_SUSP_THRLD_EN_FOR_HOST bit is clear. */
        uint32_t l1_susp_thrld_for_host : 4; /**< [  7:  4](R/W) This field is effective only when the L1_SUSP_THRLD_EN_FOR_HOST is set t0 1. */
        uint32_t helden                : 1;  /**< [  3:  3](R/W) When this bit is set to 1, it enables the Exit Latency Delta (ELD)
                                                                 support defined in the xHCI 1.0 Errata. */
        uint32_t hparchkdisable        : 1;  /**< [  2:  2](R/W) When this bit is set to 0 (by default), the xHC checks that the input
                                                                 slot/EP context fields comply to the xHCI Specification. Upon
                                                                 detection of a parameter error during command execution, the
                                                                 xHC generates an event TRB with completion code indicating
                                                                 'PARAMETER ERROR'.
                                                                 When the bit is set to 1, the xHC does not perform parameter
                                                                 checks and does not generate 'PARAMETER ERROR' completion
                                                                 code. */
        uint32_t ovrld_l1_susp_com     : 1;  /**< [  1:  1](R/W) Always set to 0. */
        uint32_t loa_filter_en         : 1;  /**< [  0:  0](R/W) If this bit is set, the USB 2.0 port babble is checked at least three consecutive times
                                                                 before the port is disabled. This prevents false triggering of the babble condition when
                                                                 using low quality cables. */
#else /* Word 0 - Little Endian */
        uint32_t loa_filter_en         : 1;  /**< [  0:  0](R/W) If this bit is set, the USB 2.0 port babble is checked at least three consecutive times
                                                                 before the port is disabled. This prevents false triggering of the babble condition when
                                                                 using low quality cables. */
        uint32_t ovrld_l1_susp_com     : 1;  /**< [  1:  1](R/W) Always set to 0. */
        uint32_t hparchkdisable        : 1;  /**< [  2:  2](R/W) When this bit is set to 0 (by default), the xHC checks that the input
                                                                 slot/EP context fields comply to the xHCI Specification. Upon
                                                                 detection of a parameter error during command execution, the
                                                                 xHC generates an event TRB with completion code indicating
                                                                 'PARAMETER ERROR'.
                                                                 When the bit is set to 1, the xHC does not perform parameter
                                                                 checks and does not generate 'PARAMETER ERROR' completion
                                                                 code. */
        uint32_t helden                : 1;  /**< [  3:  3](R/W) When this bit is set to 1, it enables the Exit Latency Delta (ELD)
                                                                 support defined in the xHCI 1.0 Errata. */
        uint32_t l1_susp_thrld_for_host : 4; /**< [  7:  4](R/W) This field is effective only when the L1_SUSP_THRLD_EN_FOR_HOST is set t0 1. */
        uint32_t l1_susp_thrld_en_for_host : 1;/**< [  8:  8](R/W) The controller puts the PHY into deep low-power mode in L1 when both of the
                                                                 following are true:

                                                                 * The HIRD/BESL value used is greater than or equal to the
                                                                   value in L1_SUSP_THRLD_FOR_HOST field.
                                                                 * The L1_SUSP_THRLD_EN_FOR_HOST bit is set.

                                                                 The controller the UTMI PHY transitions to shallow low-power
                                                                 mode in L1 by powering down necessary blocks when one of the
                                                                 following is true:

                                                                 * The HIRD/BESL value used is less than the value in
                                                                   L1_SUSP_THRLD_FOR_HOST field.
                                                                 * The L1_SUSP_THRLD_EN_FOR_HOST bit is clear. */
        uint32_t reserved_9_14         : 6;
        uint32_t parkmode_disable_fsls : 1;  /**< [ 15: 15](R/W) When this bit is set to 1 all FS/LS bus instances park mode are
                                                                 disabled. */
        uint32_t parkmode_disable_hs   : 1;  /**< [ 16: 16](R/W) When this bit is set to 1 all HS bus instances park mode are
                                                                 disabled. */
        uint32_t parkmode_disable_ss   : 1;  /**< [ 17: 17](R/W) This bit is for debug purpose only.
                                                                 When this bit is set to 1 all SS bus instances in park mode are
                                                                 disabled. */
        uint32_t reserved_18_31        : 14;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_guctl1_s cn; */
} bdk_usbdrdx_uahc_guctl1_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUCTL1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUCTL1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c11cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c11cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GUCTL1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUCTL1(a) bdk_usbdrdx_uahc_guctl1_t
#define bustype_BDK_USBDRDX_UAHC_GUCTL1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUCTL1(a) "USBDRDX_UAHC_GUCTL1"
#define device_bar_BDK_USBDRDX_UAHC_GUCTL1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUCTL1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GUCTL1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_guid
 *
 * UAHC Core User ID Register
 * This is a read/write register containing the User ID. The power-on value for this register is
 * specified as the User Identification Register. This register can be used in the following
 * ways:
 * * To store the version or revision of your system.
 * * To store hardware configurations that are outside of the core.
 * * As a scratch register.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.50a, section 6.2.1.10.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_guid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t userid                : 32; /**< [ 31:  0](R/W) User ID. Application-programmable ID field. */
#else /* Word 0 - Little Endian */
        uint32_t userid                : 32; /**< [ 31:  0](R/W) User ID. Application-programmable ID field. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_guid_s cn; */
} bdk_usbdrdx_uahc_guid_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUID(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUID(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000c128ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000c128ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_GUID", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUID(a) bdk_usbdrdx_uahc_guid_t
#define bustype_BDK_USBDRDX_UAHC_GUID(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUID(a) "USBDRDX_UAHC_GUID"
#define device_bar_BDK_USBDRDX_UAHC_GUID(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUID(a) (a)
#define arguments_BDK_USBDRDX_UAHC_GUID(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gusb2i2cctl#
 *
 * UAHC USB2 I2C Control Register
 * This register is reserved for future use.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gusb2i2cctlx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gusb2i2cctlx_s cn; */
} bdk_usbdrdx_uahc_gusb2i2cctlx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUSB2I2CCTLX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUSB2I2CCTLX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c240ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c240ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GUSB2I2CCTLX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) bdk_usbdrdx_uahc_gusb2i2cctlx_t
#define bustype_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) "USBDRDX_UAHC_GUSB2I2CCTLX"
#define device_bar_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GUSB2I2CCTLX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gusb2phycfg#
 *
 * UAHC USB2 PHY-Configuration Register
 * This register is used to configure the core after power-on. It contains USB 2.0 and USB 2.0
 * PHY-related configuration parameters. The application must program this register before
 * starting any transactions on either the SoC bus or the USB. Per-port registers are
 * implemented.
 *
 * Do not make changes to this register after the initial programming.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gusb2phycfgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) PHY soft reset. Causes the usb2phy_reset signal to be asserted to reset a UTMI PHY. */
        uint32_t u2_freeclk_exists     : 1;  /**< [ 30: 30](R/W) Specifies whether your USB 2.0 PHY provides a free-running PHY clock, which is active when
                                                                 the clock control input is active. If your USB 2.0 PHY provides a free-running PHY clock,
                                                                 it must be connected to the utmi_clk[0] input. The remaining utmi_clk[n] must be connected
                                                                 to the respective port clocks. The core uses the Port-0 clock for generating the internal
                                                                 mac2 clock.
                                                                 0 = USB 2.0 free clock does not exist.
                                                                 1 = USB 2.0 free clock exists.

                                                                 This field must be set to zero if you enable ITP generation based on the REF_CLK
                                                                 counter, USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1, or USBDRD()_UAHC_GFLADJ
                                                                 [GFLADJ_REFCLK_LPM_SEL] =
                                                                 1. */
        uint32_t ulpi_lpm_with_opmode_chk : 1;/**< [ 29: 29](R/W) Support the LPM over ULPI without NOPID token to the ULPI PHY. Always 0x0. */
        uint32_t hsic_con_width_adj    : 2;  /**< [ 28: 27](RO) This bit is used in the HSIC device mode of operation. Always 0x0 */
        uint32_t inv_sel_hsic          : 1;  /**< [ 26: 26](RO) The application driver uses this bit to control the HSIC enable/disable function. */
        uint32_t reserved_19_25        : 7;
        uint32_t ulpiextvbusindicator  : 1;  /**< [ 18: 18](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusdrv        : 1;  /**< [ 17: 17](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiclksusm           : 1;  /**< [ 16: 16](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiautores           : 1;  /**< [ 15: 15](R/W) Reserved (unused in this configuration). */
        uint32_t reserved_14           : 1;
        uint32_t usbtrdtim             : 4;  /**< [ 13: 10](R/W) USB 2.0 turnaround time. Sets the turnaround time in PHY clock cycles. Specifies the
                                                                 response time for a MAC request to the packet FIFO controller (PFC) to fetch data from the
                                                                 DFIFO (SPRAM).
                                                                 USB turnaround time is a critical certification criteria when using long cables and five
                                                                 hub levels.
                                                                 When the MAC interface is 8-bit UTMI+/ULPI, the required values for this field is 0x9. */
        uint32_t xcvrdly               : 1;  /**< [  9:  9](R/W) Transceiver delay.
                                                                 Enables a delay between the assertion of the UTMI Transceiver Select signal (for
                                                                 HighSpeed) and the assertion of the TxValid signal during a HighSpeed Chirp.
                                                                 When this bit is set to 1, a delay of approximately 2.5us is introduced from
                                                                 the time when the Transceiver Select is set to 0x0, to the time when the TxValid
                                                                 is driven to 0 for sending the chirp-K. This delay is required for some UTMI PHYs.
                                                                 This bit is only valid in device mode. */
        uint32_t enblslpm              : 1;  /**< [  8:  8](R/W) Enable utmi_sleep_n and utmi_l1_suspend_n. The application uses this field to control
                                                                 utmi_sleep_n and utmi_l1_suspend_n assertion to the PHY in the L1 state.
                                                                 0 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is not transferred to the
                                                                 external PHY.
                                                                 1 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is transferred to the
                                                                 external PHY.

                                                                 When hardware LPM is enabled, this bit should be set high for Port0. */
        uint32_t physel                : 1;  /**< [  7:  7](WO) USB 2.0 high-speed PHY or USB 1.1 full-speed serial transceiver select. */
        uint32_t susphy                : 1;  /**< [  6:  6](R/W) Suspend USB2.0 high-speed/full-speed/low-speed PHY. When set, USB2.0 PHY enters suspend
                                                                 mode if suspend conditions are valid. */
        uint32_t fsintf                : 1;  /**< [  5:  5](RO) Full-speed serial-interface select. Always reads as 0x0. */
        uint32_t ulpi_utmi_sel         : 1;  /**< [  4:  4](RO) ULPI or UTMI+ select. Always reads as 0x0, indicating UTMI+. */
        uint32_t phyif                 : 1;  /**< [  3:  3](R/W) PHY interface width: 1 = 16-bit, 0 = 8-bit.
                                                                 All the enabled 2.0 ports should have the same clock frequency as Port0 clock frequency
                                                                 (utmi_clk[0]).
                                                                 The UTMI 8-bit and 16-bit modes cannot be used together for different ports at the same
                                                                 time (i.e., all the ports should be in 8-bit mode, or all of them should be in 16-bit
                                                                 mode). */
        uint32_t toutcal               : 3;  /**< [  2:  0](R/W) High-speed/full-speed timeout calibration.
                                                                 The number of PHY clock cycles, as indicated by the application in this field, is
                                                                 multiplied by a bit-time factor; this factor is added to the high-speed/full-speed
                                                                 interpacket timeout duration in the core to account for additional delays introduced by
                                                                 the PHY. This might be required, since the delay introduced by the PHY in generating the
                                                                 linestate condition can vary among PHYs.

                                                                 The USB standard timeout value for high-speed operation is 736 to 816 (inclusive) bit
                                                                 times. The USB standard timeout value for full-speed operation is 16 to 18 (inclusive) bit
                                                                 times. The application must program this field based on the speed of connection.

                                                                 The number of bit times added per PHY clock are:
                                                                 * High-speed operation:
                                                                 _ one 30-MHz PHY clock = 16 bit times.
                                                                 _ one 60-MHz PHY clock = 8 bit times.

                                                                 * Full-speed operation:
                                                                 _ one 30-MHz PHY clock = 0.4 bit times.
                                                                 _ one 60-MHz PHY clock = 0.2 bit times.
                                                                 _ one 48-MHz PHY clock = 0.25 bit times. */
#else /* Word 0 - Little Endian */
        uint32_t toutcal               : 3;  /**< [  2:  0](R/W) High-speed/full-speed timeout calibration.
                                                                 The number of PHY clock cycles, as indicated by the application in this field, is
                                                                 multiplied by a bit-time factor; this factor is added to the high-speed/full-speed
                                                                 interpacket timeout duration in the core to account for additional delays introduced by
                                                                 the PHY. This might be required, since the delay introduced by the PHY in generating the
                                                                 linestate condition can vary among PHYs.

                                                                 The USB standard timeout value for high-speed operation is 736 to 816 (inclusive) bit
                                                                 times. The USB standard timeout value for full-speed operation is 16 to 18 (inclusive) bit
                                                                 times. The application must program this field based on the speed of connection.

                                                                 The number of bit times added per PHY clock are:
                                                                 * High-speed operation:
                                                                 _ one 30-MHz PHY clock = 16 bit times.
                                                                 _ one 60-MHz PHY clock = 8 bit times.

                                                                 * Full-speed operation:
                                                                 _ one 30-MHz PHY clock = 0.4 bit times.
                                                                 _ one 60-MHz PHY clock = 0.2 bit times.
                                                                 _ one 48-MHz PHY clock = 0.25 bit times. */
        uint32_t phyif                 : 1;  /**< [  3:  3](R/W) PHY interface width: 1 = 16-bit, 0 = 8-bit.
                                                                 All the enabled 2.0 ports should have the same clock frequency as Port0 clock frequency
                                                                 (utmi_clk[0]).
                                                                 The UTMI 8-bit and 16-bit modes cannot be used together for different ports at the same
                                                                 time (i.e., all the ports should be in 8-bit mode, or all of them should be in 16-bit
                                                                 mode). */
        uint32_t ulpi_utmi_sel         : 1;  /**< [  4:  4](RO) ULPI or UTMI+ select. Always reads as 0x0, indicating UTMI+. */
        uint32_t fsintf                : 1;  /**< [  5:  5](RO) Full-speed serial-interface select. Always reads as 0x0. */
        uint32_t susphy                : 1;  /**< [  6:  6](R/W) Suspend USB2.0 high-speed/full-speed/low-speed PHY. When set, USB2.0 PHY enters suspend
                                                                 mode if suspend conditions are valid. */
        uint32_t physel                : 1;  /**< [  7:  7](WO) USB 2.0 high-speed PHY or USB 1.1 full-speed serial transceiver select. */
        uint32_t enblslpm              : 1;  /**< [  8:  8](R/W) Enable utmi_sleep_n and utmi_l1_suspend_n. The application uses this field to control
                                                                 utmi_sleep_n and utmi_l1_suspend_n assertion to the PHY in the L1 state.
                                                                 0 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is not transferred to the
                                                                 external PHY.
                                                                 1 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is transferred to the
                                                                 external PHY.

                                                                 When hardware LPM is enabled, this bit should be set high for Port0. */
        uint32_t xcvrdly               : 1;  /**< [  9:  9](R/W) Transceiver delay.
                                                                 Enables a delay between the assertion of the UTMI Transceiver Select signal (for
                                                                 HighSpeed) and the assertion of the TxValid signal during a HighSpeed Chirp.
                                                                 When this bit is set to 1, a delay of approximately 2.5us is introduced from
                                                                 the time when the Transceiver Select is set to 0x0, to the time when the TxValid
                                                                 is driven to 0 for sending the chirp-K. This delay is required for some UTMI PHYs.
                                                                 This bit is only valid in device mode. */
        uint32_t usbtrdtim             : 4;  /**< [ 13: 10](R/W) USB 2.0 turnaround time. Sets the turnaround time in PHY clock cycles. Specifies the
                                                                 response time for a MAC request to the packet FIFO controller (PFC) to fetch data from the
                                                                 DFIFO (SPRAM).
                                                                 USB turnaround time is a critical certification criteria when using long cables and five
                                                                 hub levels.
                                                                 When the MAC interface is 8-bit UTMI+/ULPI, the required values for this field is 0x9. */
        uint32_t reserved_14           : 1;
        uint32_t ulpiautores           : 1;  /**< [ 15: 15](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiclksusm           : 1;  /**< [ 16: 16](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusdrv        : 1;  /**< [ 17: 17](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusindicator  : 1;  /**< [ 18: 18](R/W) Reserved (unused in this configuration). */
        uint32_t reserved_19_25        : 7;
        uint32_t inv_sel_hsic          : 1;  /**< [ 26: 26](RO) The application driver uses this bit to control the HSIC enable/disable function. */
        uint32_t hsic_con_width_adj    : 2;  /**< [ 28: 27](RO) This bit is used in the HSIC device mode of operation. Always 0x0 */
        uint32_t ulpi_lpm_with_opmode_chk : 1;/**< [ 29: 29](R/W) Support the LPM over ULPI without NOPID token to the ULPI PHY. Always 0x0. */
        uint32_t u2_freeclk_exists     : 1;  /**< [ 30: 30](R/W) Specifies whether your USB 2.0 PHY provides a free-running PHY clock, which is active when
                                                                 the clock control input is active. If your USB 2.0 PHY provides a free-running PHY clock,
                                                                 it must be connected to the utmi_clk[0] input. The remaining utmi_clk[n] must be connected
                                                                 to the respective port clocks. The core uses the Port-0 clock for generating the internal
                                                                 mac2 clock.
                                                                 0 = USB 2.0 free clock does not exist.
                                                                 1 = USB 2.0 free clock exists.

                                                                 This field must be set to zero if you enable ITP generation based on the REF_CLK
                                                                 counter, USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1, or USBDRD()_UAHC_GFLADJ
                                                                 [GFLADJ_REFCLK_LPM_SEL] =
                                                                 1. */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) PHY soft reset. Causes the usb2phy_reset signal to be asserted to reset a UTMI PHY. */
#endif /* Word 0 - End */
    } s;
    struct bdk_usbdrdx_uahc_gusb2phycfgx_cn
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) PHY soft reset. Causes the usb2phy_reset signal to be asserted to reset a UTMI PHY. */
        uint32_t u2_freeclk_exists     : 1;  /**< [ 30: 30](R/W) Specifies whether your USB 2.0 PHY provides a free-running PHY clock, which is active when
                                                                 the clock control input is active. If your USB 2.0 PHY provides a free-running PHY clock,
                                                                 it must be connected to the utmi_clk[0] input. The remaining utmi_clk[n] must be connected
                                                                 to the respective port clocks. The core uses the Port-0 clock for generating the internal
                                                                 mac2 clock.
                                                                 0 = USB 2.0 free clock does not exist.
                                                                 1 = USB 2.0 free clock exists.

                                                                 This field must be set to zero if you enable ITP generation based on the REF_CLK
                                                                 counter, USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1, or USBDRD()_UAHC_GFLADJ
                                                                 [GFLADJ_REFCLK_LPM_SEL] =
                                                                 1. */
        uint32_t ulpi_lpm_with_opmode_chk : 1;/**< [ 29: 29](R/W) Support the LPM over ULPI without NOPID token to the ULPI PHY. Always 0x0. */
        uint32_t hsic_con_width_adj    : 2;  /**< [ 28: 27](RO) This bit is used in the HSIC device mode of operation. Always 0x0 */
        uint32_t inv_sel_hsic          : 1;  /**< [ 26: 26](RO) The application driver uses this bit to control the HSIC enable/disable function. */
        uint32_t reserved_25           : 1;
        uint32_t reserved_19_24        : 6;
        uint32_t ulpiextvbusindicator  : 1;  /**< [ 18: 18](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusdrv        : 1;  /**< [ 17: 17](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiclksusm           : 1;  /**< [ 16: 16](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiautores           : 1;  /**< [ 15: 15](R/W) Reserved (unused in this configuration). */
        uint32_t reserved_14           : 1;
        uint32_t usbtrdtim             : 4;  /**< [ 13: 10](R/W) USB 2.0 turnaround time. Sets the turnaround time in PHY clock cycles. Specifies the
                                                                 response time for a MAC request to the packet FIFO controller (PFC) to fetch data from the
                                                                 DFIFO (SPRAM).
                                                                 USB turnaround time is a critical certification criteria when using long cables and five
                                                                 hub levels.
                                                                 When the MAC interface is 8-bit UTMI+/ULPI, the required values for this field is 0x9. */
        uint32_t xcvrdly               : 1;  /**< [  9:  9](R/W) Transceiver delay.
                                                                 Enables a delay between the assertion of the UTMI Transceiver Select signal (for
                                                                 HighSpeed) and the assertion of the TxValid signal during a HighSpeed Chirp.
                                                                 When this bit is set to 1, a delay of approximately 2.5us is introduced from
                                                                 the time when the Transceiver Select is set to 0x0, to the time when the TxValid
                                                                 is driven to 0 for sending the chirp-K. This delay is required for some UTMI PHYs.
                                                                 This bit is only valid in device mode. */
        uint32_t enblslpm              : 1;  /**< [  8:  8](R/W) Enable utmi_sleep_n and utmi_l1_suspend_n. The application uses this field to control
                                                                 utmi_sleep_n and utmi_l1_suspend_n assertion to the PHY in the L1 state.
                                                                 0 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is not transferred to the
                                                                 external PHY.
                                                                 1 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is transferred to the
                                                                 external PHY.

                                                                 When hardware LPM is enabled, this bit should be set high for Port0. */
        uint32_t physel                : 1;  /**< [  7:  7](WO) USB 2.0 high-speed PHY or USB 1.1 full-speed serial transceiver select. */
        uint32_t susphy                : 1;  /**< [  6:  6](R/W) Suspend USB2.0 high-speed/full-speed/low-speed PHY. When set, USB2.0 PHY enters suspend
                                                                 mode if suspend conditions are valid. */
        uint32_t fsintf                : 1;  /**< [  5:  5](RO) Full-speed serial-interface select. Always reads as 0x0. */
        uint32_t ulpi_utmi_sel         : 1;  /**< [  4:  4](RO) ULPI or UTMI+ select. Always reads as 0x0, indicating UTMI+. */
        uint32_t phyif                 : 1;  /**< [  3:  3](R/W) PHY interface width: 1 = 16-bit, 0 = 8-bit.
                                                                 All the enabled 2.0 ports should have the same clock frequency as Port0 clock frequency
                                                                 (utmi_clk[0]).
                                                                 The UTMI 8-bit and 16-bit modes cannot be used together for different ports at the same
                                                                 time (i.e., all the ports should be in 8-bit mode, or all of them should be in 16-bit
                                                                 mode). */
        uint32_t toutcal               : 3;  /**< [  2:  0](R/W) High-speed/full-speed timeout calibration.
                                                                 The number of PHY clock cycles, as indicated by the application in this field, is
                                                                 multiplied by a bit-time factor; this factor is added to the high-speed/full-speed
                                                                 interpacket timeout duration in the core to account for additional delays introduced by
                                                                 the PHY. This might be required, since the delay introduced by the PHY in generating the
                                                                 linestate condition can vary among PHYs.

                                                                 The USB standard timeout value for high-speed operation is 736 to 816 (inclusive) bit
                                                                 times. The USB standard timeout value for full-speed operation is 16 to 18 (inclusive) bit
                                                                 times. The application must program this field based on the speed of connection.

                                                                 The number of bit times added per PHY clock are:
                                                                 * High-speed operation:
                                                                 _ one 30-MHz PHY clock = 16 bit times.
                                                                 _ one 60-MHz PHY clock = 8 bit times.

                                                                 * Full-speed operation:
                                                                 _ one 30-MHz PHY clock = 0.4 bit times.
                                                                 _ one 60-MHz PHY clock = 0.2 bit times.
                                                                 _ one 48-MHz PHY clock = 0.25 bit times. */
#else /* Word 0 - Little Endian */
        uint32_t toutcal               : 3;  /**< [  2:  0](R/W) High-speed/full-speed timeout calibration.
                                                                 The number of PHY clock cycles, as indicated by the application in this field, is
                                                                 multiplied by a bit-time factor; this factor is added to the high-speed/full-speed
                                                                 interpacket timeout duration in the core to account for additional delays introduced by
                                                                 the PHY. This might be required, since the delay introduced by the PHY in generating the
                                                                 linestate condition can vary among PHYs.

                                                                 The USB standard timeout value for high-speed operation is 736 to 816 (inclusive) bit
                                                                 times. The USB standard timeout value for full-speed operation is 16 to 18 (inclusive) bit
                                                                 times. The application must program this field based on the speed of connection.

                                                                 The number of bit times added per PHY clock are:
                                                                 * High-speed operation:
                                                                 _ one 30-MHz PHY clock = 16 bit times.
                                                                 _ one 60-MHz PHY clock = 8 bit times.

                                                                 * Full-speed operation:
                                                                 _ one 30-MHz PHY clock = 0.4 bit times.
                                                                 _ one 60-MHz PHY clock = 0.2 bit times.
                                                                 _ one 48-MHz PHY clock = 0.25 bit times. */
        uint32_t phyif                 : 1;  /**< [  3:  3](R/W) PHY interface width: 1 = 16-bit, 0 = 8-bit.
                                                                 All the enabled 2.0 ports should have the same clock frequency as Port0 clock frequency
                                                                 (utmi_clk[0]).
                                                                 The UTMI 8-bit and 16-bit modes cannot be used together for different ports at the same
                                                                 time (i.e., all the ports should be in 8-bit mode, or all of them should be in 16-bit
                                                                 mode). */
        uint32_t ulpi_utmi_sel         : 1;  /**< [  4:  4](RO) ULPI or UTMI+ select. Always reads as 0x0, indicating UTMI+. */
        uint32_t fsintf                : 1;  /**< [  5:  5](RO) Full-speed serial-interface select. Always reads as 0x0. */
        uint32_t susphy                : 1;  /**< [  6:  6](R/W) Suspend USB2.0 high-speed/full-speed/low-speed PHY. When set, USB2.0 PHY enters suspend
                                                                 mode if suspend conditions are valid. */
        uint32_t physel                : 1;  /**< [  7:  7](WO) USB 2.0 high-speed PHY or USB 1.1 full-speed serial transceiver select. */
        uint32_t enblslpm              : 1;  /**< [  8:  8](R/W) Enable utmi_sleep_n and utmi_l1_suspend_n. The application uses this field to control
                                                                 utmi_sleep_n and utmi_l1_suspend_n assertion to the PHY in the L1 state.
                                                                 0 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is not transferred to the
                                                                 external PHY.
                                                                 1 = utmi_sleep_n and utmi_l1_suspend_n assertion from the core is transferred to the
                                                                 external PHY.

                                                                 When hardware LPM is enabled, this bit should be set high for Port0. */
        uint32_t xcvrdly               : 1;  /**< [  9:  9](R/W) Transceiver delay.
                                                                 Enables a delay between the assertion of the UTMI Transceiver Select signal (for
                                                                 HighSpeed) and the assertion of the TxValid signal during a HighSpeed Chirp.
                                                                 When this bit is set to 1, a delay of approximately 2.5us is introduced from
                                                                 the time when the Transceiver Select is set to 0x0, to the time when the TxValid
                                                                 is driven to 0 for sending the chirp-K. This delay is required for some UTMI PHYs.
                                                                 This bit is only valid in device mode. */
        uint32_t usbtrdtim             : 4;  /**< [ 13: 10](R/W) USB 2.0 turnaround time. Sets the turnaround time in PHY clock cycles. Specifies the
                                                                 response time for a MAC request to the packet FIFO controller (PFC) to fetch data from the
                                                                 DFIFO (SPRAM).
                                                                 USB turnaround time is a critical certification criteria when using long cables and five
                                                                 hub levels.
                                                                 When the MAC interface is 8-bit UTMI+/ULPI, the required values for this field is 0x9. */
        uint32_t reserved_14           : 1;
        uint32_t ulpiautores           : 1;  /**< [ 15: 15](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiclksusm           : 1;  /**< [ 16: 16](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusdrv        : 1;  /**< [ 17: 17](R/W) Reserved (unused in this configuration). */
        uint32_t ulpiextvbusindicator  : 1;  /**< [ 18: 18](R/W) Reserved (unused in this configuration). */
        uint32_t reserved_19_24        : 6;
        uint32_t reserved_25           : 1;
        uint32_t inv_sel_hsic          : 1;  /**< [ 26: 26](RO) The application driver uses this bit to control the HSIC enable/disable function. */
        uint32_t hsic_con_width_adj    : 2;  /**< [ 28: 27](RO) This bit is used in the HSIC device mode of operation. Always 0x0 */
        uint32_t ulpi_lpm_with_opmode_chk : 1;/**< [ 29: 29](R/W) Support the LPM over ULPI without NOPID token to the ULPI PHY. Always 0x0. */
        uint32_t u2_freeclk_exists     : 1;  /**< [ 30: 30](R/W) Specifies whether your USB 2.0 PHY provides a free-running PHY clock, which is active when
                                                                 the clock control input is active. If your USB 2.0 PHY provides a free-running PHY clock,
                                                                 it must be connected to the utmi_clk[0] input. The remaining utmi_clk[n] must be connected
                                                                 to the respective port clocks. The core uses the Port-0 clock for generating the internal
                                                                 mac2 clock.
                                                                 0 = USB 2.0 free clock does not exist.
                                                                 1 = USB 2.0 free clock exists.

                                                                 This field must be set to zero if you enable ITP generation based on the REF_CLK
                                                                 counter, USBDRD()_UAHC_GCTL[SOFITPSYNC] = 1, or USBDRD()_UAHC_GFLADJ
                                                                 [GFLADJ_REFCLK_LPM_SEL] =
                                                                 1. */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) PHY soft reset. Causes the usb2phy_reset signal to be asserted to reset a UTMI PHY. */
#endif /* Word 0 - End */
    } cn;
} bdk_usbdrdx_uahc_gusb2phycfgx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUSB2PHYCFGX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUSB2PHYCFGX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c200ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c200ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GUSB2PHYCFGX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) bdk_usbdrdx_uahc_gusb2phycfgx_t
#define bustype_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) "USBDRDX_UAHC_GUSB2PHYCFGX"
#define device_bar_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GUSB2PHYCFGX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_gusb3pipectl#
 *
 * UAHC USB3 Pipe-Control Register
 * This register is used to configure the core after power-on. It contains USB 3.0 and USB 3.0
 * PHY-related configuration parameters. The application must program this register before
 * starting any transactions on either the SoC bus or the USB. Per-port registers are
 * implemented.
 *
 * Do not make changes to this register after the initial programming.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UAHC_RST].
 *
 * INTERNAL: See Synopsys DWC_usb3 Databook v2.20a, section 6.2.5.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_gusb3pipectlx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) USB3 PHY soft reset (PHYSoftRst). When set to 1, initiates a PHY soft reset. After setting
                                                                 this bit to 1, the software needs to clear this bit. */
        uint32_t hstprtcmpl            : 1;  /**< [ 30: 30](R/W) Host port compliance. Setting this bit to 1 enables placing the SuperSpeed port link into
                                                                 a compliance state, which allows testing of the PIPE PHY compliance patterns without
                                                                 having to have a test fixture on the USB 3.0 cable. By default, this bit should be set to
                                                                 0.

                                                                 In compliance-lab testing, the SuperSpeed port link enters compliance after failing the
                                                                 first polling sequence after power on. Set this bit to 0 when you run compliance tests.

                                                                 The sequence for using this functionality is as follows:
                                                                 * Disconnect any plugged-in devices.
                                                                 * Set USBDRD()_UAHC_USBCMD[HCRST] = 1 or power-on-chip reset.
                                                                 * Set USBDRD()_UAHC_PORTSC()[PP] = 0.
                                                                 * Set HSTPRTCMPL = 1. This places the link into compliance state.

                                                                 To advance the compliance pattern, follow this sequence (toggle HSTPRTCMPL):
                                                                 * Set HSTPRTCMPL = 0.
                                                                 * Set HSTPRTCMPL = 1. This advances the link to the next compliance pattern.

                                                                 To exit from the compliance state, set USBDRD()_UAHC_USBCMD[HCRST] = 1 or power-on-chip
                                                                 reset. */
        uint32_t u2ssinactp3ok         : 1;  /**< [ 29: 29](R/W) P3 OK for U2/SS.Inactive:
                                                                 0 = During link state U2/SS.Inactive, put PHY in P2 (default).
                                                                 1 = During link state U2/SS.Inactive, put PHY in P3. */
        uint32_t disrxdetp3            : 1;  /**< [ 28: 28](R/W) Disables receiver detection in P3. If PHY is in P3 and the core needs to perform receiver
                                                                 detection:
                                                                 0 = Core performs receiver detection in P3 (default).
                                                                 1 = Core changes the PHY power state to P2 and then performs receiver detection. After
                                                                 receiver detection, core changes PHY power state to P3. */
        uint32_t ux_exit_in_px         : 1;  /**< [ 27: 27](R/W) UX exit in Px:
                                                                 0 = Core does U1/U2/U3 exit in PHY power state P0 (default behavior).
                                                                 1 = Core does U1/U2/U3 exit in PHY power state P1/P2/P3 respectively.

                                                                 This bit is added for SuperSpeed PHY workaround where SuperSpeed PHY injects a glitch on
                                                                 pipe3_RxElecIdle while receiving Ux exit LFPS, and pipe3_PowerDown change is in progress.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t ping_enchance_en      : 1;  /**< [ 26: 26](R/W) Ping enhancement enable. When set to 1, the downstream-port U1-ping-receive timeout
                                                                 becomes 500 ms instead of 300 ms. Minimum Ping.LFPS receive duration is 8 ns (one mac3_clk
                                                                 cycle). This field is valid for the downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t u1u2exitfail_to_recov : 1;  /**< [ 25: 25](R/W) U1U2exit fail to recovery. When set to 1, and U1/U2 LFPS handshake fails, the LTSSM
                                                                 transitions from U1/U2 to recovery instead of SS.inactive.
                                                                 If recovery fails, then the LTSSM can enter SS.Inactive. This is an enhancement only. It
                                                                 prevents interoperability issue if the remote link does not do the proper handshake. */
        uint32_t request_p1p2p3        : 1;  /**< [ 24: 24](R/W) Always request P1/P2/P3 for U1/U2/U3.
                                                                 0 = if immediate Ux exit (remotely initiated, or locally initiated) happens, the core does
                                                                 not request P1/P2/P3 power state change.
                                                                 1 = the core always requests PHY power change from P0 to P1/P2/P3 during U0 to U1/U2/U3
                                                                 transition.

                                                                 INTERNAL: Note: This bit should be set to 1 for Synopsys PHY. For third-party SuperSpeed
                                                                 PHY, check with your PHY vendor. */
        uint32_t startrxdetu3rxdet     : 1;  /**< [ 23: 23](WO) Start receiver detection in U3/Rx.Detect.
                                                                 If DISRXDETU3RXDET is set to 1 during reset, and the link is in U3 or Rx.Detect state, the
                                                                 core starts receiver detection on rising edge of this bit.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
        uint32_t disrxdetu3rxdet       : 1;  /**< [ 22: 22](R/W) Disable receiver detection in U3/Rx.Detect. When set to 1, the core does not do receiver
                                                                 detection in U3 or Rx.Detect state. If STARTRXDETU3RXDET is set to 1 during reset,
                                                                 receiver detection starts manually.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
        uint32_t delaypx               : 3;  /**< [ 21: 19](R/W) Delay P1P2P3. Delay P0 to P1/P2/P3 request when entering U1/U2/U3 until (DELAYPX * 8)
                                                                 8B10B error occurs, or Pipe3_RxValid drops to 0.
                                                                 DELAYPXTRANSENTERUX must reset to 1 to enable this functionality.
                                                                 INTERNAL: Should always be 0x1 for a Synopsys PHY. */
        uint32_t delaypxtransenterux   : 1;  /**< [ 18: 18](R/W) Delay PHY power change from P0 to P1/P2/P3 when link state changing from U0 to U1/U2/U3
                                                                 respectively.
                                                                 0 = when entering U1/U2/U3, transition to P1/P2/P3 without checking for Pipe3_RxElecIlde
                                                                 and pipe3_RxValid.
                                                                 1 = when entering U1/U2/U3, delay the transition to P1/P2/P3 until the pipe3 signals,
                                                                 Pipe3_RxElecIlde is 1 and pipe3_RxValid is 0.

                                                                 INTERNAL: Note: This bit should be set to '1' for Synopsys PHY. It is also used by third-
                                                                 party SuperSpeed PHY. */
        uint32_t suspend_en            : 1;  /**< [ 17: 17](R/W) Suspend USB3.0 SuperSpeed PHY (Suspend_en). When set to 1, and if suspend conditions are
                                                                 valid, the USB 3.0 PHY enters suspend mode. */
        uint32_t datwidth              : 2;  /**< [ 16: 15](RO) PIPE data width.
                                                                 0x0 = 32 bits.
                                                                 0x1 = 16 bits.
                                                                 0x2 = 8 bits.
                                                                 0x3 = reserved.

                                                                 One clock cycle after reset, these bits receive the value seen on the pipe3_DataBusWidth.
                                                                 This will always be 0x0.
                                                                 INTERNAL: The simulation testbench uses the coreConsultant parameter to configure the VIP.
                                                                 INTERNAL: These bits in the coreConsultant parameter should match your PHY data width and
                                                                 the pipe3_DataBusWidth port. */
        uint32_t abortrxdetinu2        : 1;  /**< [ 14: 14](R/W) Abort RX Detect in U2. When set to 1, and the link state is U2, the core aborts receiver
                                                                 detection if it receives U2 exit LFPS from the remote link partner.

                                                                 This bit is for downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t skiprxdet             : 1;  /**< [ 13: 13](R/W) Skip RX detect. When set to 1, the core skips RX detection if pipe3_RxElecIdle is low.
                                                                 Skip is defined as waiting for the appropriate timeout, then repeating the operation. */
        uint32_t lfpsp0algn            : 1;  /**< [ 12: 12](R/W) LFPS P0 align. When set to 1:
                                                                 * the core deasserts LFPS transmission on the clock edge that it requests Phy power state
                                                                 0 when exiting U1, U2, or U3 low power states. Otherwise, LFPS transmission is asserted
                                                                 one clock earlier.
                                                                 * the core requests symbol transmission two pipe3_rx_pclks periods after the PHY asserts
                                                                 PhyStatus as a result of the PHY switching from P1 or P2 state to P0 state.
                                                                 For USB 3.0 host, this is not required. */
        uint32_t p3p2tranok            : 1;  /**< [ 11: 11](R/W) P3 P2 transitions OK.
                                                                 0 = P0 is always entered as an intermediate state during transitions between P2 and P3, as
                                                                 defined in the PIPE3 specification.
                                                                 1 = the core transitions directly from Phy power state P2 to P3 or from state P3 to P2.

                                                                 According to PIPE3 specification, any direct transition between P3 and P2 is illegal.
                                                                 INTERNAL: This bit is used only for some non-Synopsys PHYs that cannot do LFPS in P3.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t p3exsigp2             : 1;  /**< [ 10: 10](R/W) P3 exit signal in P2. When set to 1, the core always changes the PHY power state to P2,
                                                                 before attempting a U3 exit handshake.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t lfpsfilt              : 1;  /**< [  9:  9](R/W) LFPS filter. When set to 1, filter LFPS reception with pipe3_RxValid in PHY power state
                                                                 P0, ignore LFPS reception from the PHY unless both pipe3_Rxelecidle and pipe3_RxValid are
                                                                 deasserted. */
        uint32_t rxdet2polllfpsctrl    : 1;  /**< [  8:  8](R/W) RX_DETECT to Polling.
                                                                 0 = Enables a 400 us delay to start polling LFPS after RX_DETECT. This allows VCM offset
                                                                 to settle to a proper level.
                                                                 1 = Disables the 400 us delay to start polling LFPS after RX_DETECT. */
        uint32_t ssicen                : 1;  /**< [  7:  7](R/W) SSIC is not supported. This bit must be set to 0. */
        uint32_t txswing               : 1;  /**< [  6:  6](R/W) TX swing. Refer to the PIPE3 specification. */
        uint32_t txmargin              : 3;  /**< [  5:  3](R/W) TX margin. Refer to the PIPE3 specification, table 5-3. */
        uint32_t txdeemphasis          : 2;  /**< [  2:  1](R/W) TX de-emphasis. The value driven to the PHY is controlled by the LTSSM during USB3
                                                                 compliance mode. Refer to the PIPE3 specification, table 5-3. */
        uint32_t elasticbuffermode     : 1;  /**< [  0:  0](R/W) Elastic buffer mode. Refer to the PIPE3 specification, table 5-3. */
#else /* Word 0 - Little Endian */
        uint32_t elasticbuffermode     : 1;  /**< [  0:  0](R/W) Elastic buffer mode. Refer to the PIPE3 specification, table 5-3. */
        uint32_t txdeemphasis          : 2;  /**< [  2:  1](R/W) TX de-emphasis. The value driven to the PHY is controlled by the LTSSM during USB3
                                                                 compliance mode. Refer to the PIPE3 specification, table 5-3. */
        uint32_t txmargin              : 3;  /**< [  5:  3](R/W) TX margin. Refer to the PIPE3 specification, table 5-3. */
        uint32_t txswing               : 1;  /**< [  6:  6](R/W) TX swing. Refer to the PIPE3 specification. */
        uint32_t ssicen                : 1;  /**< [  7:  7](R/W) SSIC is not supported. This bit must be set to 0. */
        uint32_t rxdet2polllfpsctrl    : 1;  /**< [  8:  8](R/W) RX_DETECT to Polling.
                                                                 0 = Enables a 400 us delay to start polling LFPS after RX_DETECT. This allows VCM offset
                                                                 to settle to a proper level.
                                                                 1 = Disables the 400 us delay to start polling LFPS after RX_DETECT. */
        uint32_t lfpsfilt              : 1;  /**< [  9:  9](R/W) LFPS filter. When set to 1, filter LFPS reception with pipe3_RxValid in PHY power state
                                                                 P0, ignore LFPS reception from the PHY unless both pipe3_Rxelecidle and pipe3_RxValid are
                                                                 deasserted. */
        uint32_t p3exsigp2             : 1;  /**< [ 10: 10](R/W) P3 exit signal in P2. When set to 1, the core always changes the PHY power state to P2,
                                                                 before attempting a U3 exit handshake.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t p3p2tranok            : 1;  /**< [ 11: 11](R/W) P3 P2 transitions OK.
                                                                 0 = P0 is always entered as an intermediate state during transitions between P2 and P3, as
                                                                 defined in the PIPE3 specification.
                                                                 1 = the core transitions directly from Phy power state P2 to P3 or from state P3 to P2.

                                                                 According to PIPE3 specification, any direct transition between P3 and P2 is illegal.
                                                                 INTERNAL: This bit is used only for some non-Synopsys PHYs that cannot do LFPS in P3.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t lfpsp0algn            : 1;  /**< [ 12: 12](R/W) LFPS P0 align. When set to 1:
                                                                 * the core deasserts LFPS transmission on the clock edge that it requests Phy power state
                                                                 0 when exiting U1, U2, or U3 low power states. Otherwise, LFPS transmission is asserted
                                                                 one clock earlier.
                                                                 * the core requests symbol transmission two pipe3_rx_pclks periods after the PHY asserts
                                                                 PhyStatus as a result of the PHY switching from P1 or P2 state to P0 state.
                                                                 For USB 3.0 host, this is not required. */
        uint32_t skiprxdet             : 1;  /**< [ 13: 13](R/W) Skip RX detect. When set to 1, the core skips RX detection if pipe3_RxElecIdle is low.
                                                                 Skip is defined as waiting for the appropriate timeout, then repeating the operation. */
        uint32_t abortrxdetinu2        : 1;  /**< [ 14: 14](R/W) Abort RX Detect in U2. When set to 1, and the link state is U2, the core aborts receiver
                                                                 detection if it receives U2 exit LFPS from the remote link partner.

                                                                 This bit is for downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t datwidth              : 2;  /**< [ 16: 15](RO) PIPE data width.
                                                                 0x0 = 32 bits.
                                                                 0x1 = 16 bits.
                                                                 0x2 = 8 bits.
                                                                 0x3 = reserved.

                                                                 One clock cycle after reset, these bits receive the value seen on the pipe3_DataBusWidth.
                                                                 This will always be 0x0.
                                                                 INTERNAL: The simulation testbench uses the coreConsultant parameter to configure the VIP.
                                                                 INTERNAL: These bits in the coreConsultant parameter should match your PHY data width and
                                                                 the pipe3_DataBusWidth port. */
        uint32_t suspend_en            : 1;  /**< [ 17: 17](R/W) Suspend USB3.0 SuperSpeed PHY (Suspend_en). When set to 1, and if suspend conditions are
                                                                 valid, the USB 3.0 PHY enters suspend mode. */
        uint32_t delaypxtransenterux   : 1;  /**< [ 18: 18](R/W) Delay PHY power change from P0 to P1/P2/P3 when link state changing from U0 to U1/U2/U3
                                                                 respectively.
                                                                 0 = when entering U1/U2/U3, transition to P1/P2/P3 without checking for Pipe3_RxElecIlde
                                                                 and pipe3_RxValid.
                                                                 1 = when entering U1/U2/U3, delay the transition to P1/P2/P3 until the pipe3 signals,
                                                                 Pipe3_RxElecIlde is 1 and pipe3_RxValid is 0.

                                                                 INTERNAL: Note: This bit should be set to '1' for Synopsys PHY. It is also used by third-
                                                                 party SuperSpeed PHY. */
        uint32_t delaypx               : 3;  /**< [ 21: 19](R/W) Delay P1P2P3. Delay P0 to P1/P2/P3 request when entering U1/U2/U3 until (DELAYPX * 8)
                                                                 8B10B error occurs, or Pipe3_RxValid drops to 0.
                                                                 DELAYPXTRANSENTERUX must reset to 1 to enable this functionality.
                                                                 INTERNAL: Should always be 0x1 for a Synopsys PHY. */
        uint32_t disrxdetu3rxdet       : 1;  /**< [ 22: 22](R/W) Disable receiver detection in U3/Rx.Detect. When set to 1, the core does not do receiver
                                                                 detection in U3 or Rx.Detect state. If STARTRXDETU3RXDET is set to 1 during reset,
                                                                 receiver detection starts manually.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
        uint32_t startrxdetu3rxdet     : 1;  /**< [ 23: 23](WO) Start receiver detection in U3/Rx.Detect.
                                                                 If DISRXDETU3RXDET is set to 1 during reset, and the link is in U3 or Rx.Detect state, the
                                                                 core starts receiver detection on rising edge of this bit.
                                                                 This bit is valid for downstream ports only, and this feature must not be enabled for
                                                                 normal operation.
                                                                 INTERNAL: If have to use this feature, contact Synopsys. */
        uint32_t request_p1p2p3        : 1;  /**< [ 24: 24](R/W) Always request P1/P2/P3 for U1/U2/U3.
                                                                 0 = if immediate Ux exit (remotely initiated, or locally initiated) happens, the core does
                                                                 not request P1/P2/P3 power state change.
                                                                 1 = the core always requests PHY power change from P0 to P1/P2/P3 during U0 to U1/U2/U3
                                                                 transition.

                                                                 INTERNAL: Note: This bit should be set to 1 for Synopsys PHY. For third-party SuperSpeed
                                                                 PHY, check with your PHY vendor. */
        uint32_t u1u2exitfail_to_recov : 1;  /**< [ 25: 25](R/W) U1U2exit fail to recovery. When set to 1, and U1/U2 LFPS handshake fails, the LTSSM
                                                                 transitions from U1/U2 to recovery instead of SS.inactive.
                                                                 If recovery fails, then the LTSSM can enter SS.Inactive. This is an enhancement only. It
                                                                 prevents interoperability issue if the remote link does not do the proper handshake. */
        uint32_t ping_enchance_en      : 1;  /**< [ 26: 26](R/W) Ping enhancement enable. When set to 1, the downstream-port U1-ping-receive timeout
                                                                 becomes 500 ms instead of 300 ms. Minimum Ping.LFPS receive duration is 8 ns (one mac3_clk
                                                                 cycle). This field is valid for the downstream port only.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t ux_exit_in_px         : 1;  /**< [ 27: 27](R/W) UX exit in Px:
                                                                 0 = Core does U1/U2/U3 exit in PHY power state P0 (default behavior).
                                                                 1 = Core does U1/U2/U3 exit in PHY power state P1/P2/P3 respectively.

                                                                 This bit is added for SuperSpeed PHY workaround where SuperSpeed PHY injects a glitch on
                                                                 pipe3_RxElecIdle while receiving Ux exit LFPS, and pipe3_PowerDown change is in progress.
                                                                 INTERNAL: Note: This bit is used by third-party SuperSpeed PHY. It should be set to 0 for
                                                                 Synopsys PHY. */
        uint32_t disrxdetp3            : 1;  /**< [ 28: 28](R/W) Disables receiver detection in P3. If PHY is in P3 and the core needs to perform receiver
                                                                 detection:
                                                                 0 = Core performs receiver detection in P3 (default).
                                                                 1 = Core changes the PHY power state to P2 and then performs receiver detection. After
                                                                 receiver detection, core changes PHY power state to P3. */
        uint32_t u2ssinactp3ok         : 1;  /**< [ 29: 29](R/W) P3 OK for U2/SS.Inactive:
                                                                 0 = During link state U2/SS.Inactive, put PHY in P2 (default).
                                                                 1 = During link state U2/SS.Inactive, put PHY in P3. */
        uint32_t hstprtcmpl            : 1;  /**< [ 30: 30](R/W) Host port compliance. Setting this bit to 1 enables placing the SuperSpeed port link into
                                                                 a compliance state, which allows testing of the PIPE PHY compliance patterns without
                                                                 having to have a test fixture on the USB 3.0 cable. By default, this bit should be set to
                                                                 0.

                                                                 In compliance-lab testing, the SuperSpeed port link enters compliance after failing the
                                                                 first polling sequence after power on. Set this bit to 0 when you run compliance tests.

                                                                 The sequence for using this functionality is as follows:
                                                                 * Disconnect any plugged-in devices.
                                                                 * Set USBDRD()_UAHC_USBCMD[HCRST] = 1 or power-on-chip reset.
                                                                 * Set USBDRD()_UAHC_PORTSC()[PP] = 0.
                                                                 * Set HSTPRTCMPL = 1. This places the link into compliance state.

                                                                 To advance the compliance pattern, follow this sequence (toggle HSTPRTCMPL):
                                                                 * Set HSTPRTCMPL = 0.
                                                                 * Set HSTPRTCMPL = 1. This advances the link to the next compliance pattern.

                                                                 To exit from the compliance state, set USBDRD()_UAHC_USBCMD[HCRST] = 1 or power-on-chip
                                                                 reset. */
        uint32_t physoftrst            : 1;  /**< [ 31: 31](R/W) USB3 PHY soft reset (PHYSoftRst). When set to 1, initiates a PHY soft reset. After setting
                                                                 this bit to 1, the software needs to clear this bit. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_gusb3pipectlx_s cn; */
} bdk_usbdrdx_uahc_gusb3pipectlx_t;

static inline uint64_t BDK_USBDRDX_UAHC_GUSB3PIPECTLX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_GUSB3PIPECTLX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000c2c0ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000c2c0ll + 0x1000000000ll * ((a) & 0x1) + 4ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_GUSB3PIPECTLX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) bdk_usbdrdx_uahc_gusb3pipectlx_t
#define bustype_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) "USBDRDX_UAHC_GUSB3PIPECTLX"
#define device_bar_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_GUSB3PIPECTLX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_hccparams
 *
 * XHCI Controller Capability Parameters Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.6.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_hccparams_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t xecp                  : 16; /**< [ 31: 16](RO) xHCI extended capabilities pointer. */
        uint32_t maxpsasize            : 4;  /**< [ 15: 12](RO) Maximum primary-stream-array size. */
        uint32_t reserved_11           : 1;
        uint32_t sec                   : 1;  /**< [ 10: 10](RO/H) Stopped EDLTA Capability */
        uint32_t spc                   : 1;  /**< [  9:  9](RO/H) Stopped - Short packet Capability */
        uint32_t pae                   : 1;  /**< [  8:  8](RO) Parse all event data. */
        uint32_t nss                   : 1;  /**< [  7:  7](RO) No secondary SID support. */
        uint32_t ltc                   : 1;  /**< [  6:  6](RO) Latency tolerance messaging capability. */
        uint32_t lhrc                  : 1;  /**< [  5:  5](RO) Light HC reset capability. */
        uint32_t pind                  : 1;  /**< [  4:  4](RO) Port indicators. */
        uint32_t ppc                   : 1;  /**< [  3:  3](RO) Port power control. Value is based on USBDRD()_UCTL_HOST_CFG[PPC_EN]. */
        uint32_t csz                   : 1;  /**< [  2:  2](RO) Context size. */
        uint32_t bnc                   : 1;  /**< [  1:  1](RO) BW negotiation capability. */
        uint32_t ac64                  : 1;  /**< [  0:  0](RO) 64-bit addressing capability. */
#else /* Word 0 - Little Endian */
        uint32_t ac64                  : 1;  /**< [  0:  0](RO) 64-bit addressing capability. */
        uint32_t bnc                   : 1;  /**< [  1:  1](RO) BW negotiation capability. */
        uint32_t csz                   : 1;  /**< [  2:  2](RO) Context size. */
        uint32_t ppc                   : 1;  /**< [  3:  3](RO) Port power control. Value is based on USBDRD()_UCTL_HOST_CFG[PPC_EN]. */
        uint32_t pind                  : 1;  /**< [  4:  4](RO) Port indicators. */
        uint32_t lhrc                  : 1;  /**< [  5:  5](RO) Light HC reset capability. */
        uint32_t ltc                   : 1;  /**< [  6:  6](RO) Latency tolerance messaging capability. */
        uint32_t nss                   : 1;  /**< [  7:  7](RO) No secondary SID support. */
        uint32_t pae                   : 1;  /**< [  8:  8](RO) Parse all event data. */
        uint32_t spc                   : 1;  /**< [  9:  9](RO/H) Stopped - Short packet Capability */
        uint32_t sec                   : 1;  /**< [ 10: 10](RO/H) Stopped EDLTA Capability */
        uint32_t reserved_11           : 1;
        uint32_t maxpsasize            : 4;  /**< [ 15: 12](RO) Maximum primary-stream-array size. */
        uint32_t xecp                  : 16; /**< [ 31: 16](RO) xHCI extended capabilities pointer. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_hccparams_s cn; */
} bdk_usbdrdx_uahc_hccparams_t;

static inline uint64_t BDK_USBDRDX_UAHC_HCCPARAMS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_HCCPARAMS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000010ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000010ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_HCCPARAMS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_HCCPARAMS(a) bdk_usbdrdx_uahc_hccparams_t
#define bustype_BDK_USBDRDX_UAHC_HCCPARAMS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_HCCPARAMS(a) "USBDRDX_UAHC_HCCPARAMS"
#define device_bar_BDK_USBDRDX_UAHC_HCCPARAMS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_HCCPARAMS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_HCCPARAMS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_hcsparams1
 *
 * XHCI Controller Structural Parameters Register 1
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_hcsparams1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t maxports              : 8;  /**< [ 31: 24](RO) Maximum number of ports. */
        uint32_t reserved_19_23        : 5;
        uint32_t maxintrs              : 11; /**< [ 18:  8](RO) Maximum number of interrupters. */
        uint32_t maxslots              : 8;  /**< [  7:  0](RO) Maximum number of device slots. */
#else /* Word 0 - Little Endian */
        uint32_t maxslots              : 8;  /**< [  7:  0](RO) Maximum number of device slots. */
        uint32_t maxintrs              : 11; /**< [ 18:  8](RO) Maximum number of interrupters. */
        uint32_t reserved_19_23        : 5;
        uint32_t maxports              : 8;  /**< [ 31: 24](RO) Maximum number of ports. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_hcsparams1_s cn; */
} bdk_usbdrdx_uahc_hcsparams1_t;

static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000004ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000004ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_HCSPARAMS1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_HCSPARAMS1(a) bdk_usbdrdx_uahc_hcsparams1_t
#define bustype_BDK_USBDRDX_UAHC_HCSPARAMS1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_HCSPARAMS1(a) "USBDRDX_UAHC_HCSPARAMS1"
#define device_bar_BDK_USBDRDX_UAHC_HCSPARAMS1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_HCSPARAMS1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_HCSPARAMS1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_hcsparams2
 *
 * XHCI Controller Structural Parameters Register 2
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.4.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_hcsparams2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t maxscratchpadbufs_l   : 5;  /**< [ 31: 27](RO) Maximum number of scratchpad buffers[4:0]. */
        uint32_t spr                   : 1;  /**< [ 26: 26](RO) Scratchpad restore. */
        uint32_t maxscratchpadbufs_h   : 5;  /**< [ 25: 21](RO) Maximum number of scratchpad buffers[9:5]. */
        uint32_t reserved_8_20         : 13;
        uint32_t erst_max              : 4;  /**< [  7:  4](RO) Event ring segment table maximum. */
        uint32_t ist                   : 4;  /**< [  3:  0](RO) Isochronous scheduling threshold. */
#else /* Word 0 - Little Endian */
        uint32_t ist                   : 4;  /**< [  3:  0](RO) Isochronous scheduling threshold. */
        uint32_t erst_max              : 4;  /**< [  7:  4](RO) Event ring segment table maximum. */
        uint32_t reserved_8_20         : 13;
        uint32_t maxscratchpadbufs_h   : 5;  /**< [ 25: 21](RO) Maximum number of scratchpad buffers[9:5]. */
        uint32_t spr                   : 1;  /**< [ 26: 26](RO) Scratchpad restore. */
        uint32_t maxscratchpadbufs_l   : 5;  /**< [ 31: 27](RO) Maximum number of scratchpad buffers[4:0]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_hcsparams2_s cn; */
} bdk_usbdrdx_uahc_hcsparams2_t;

static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000008ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000008ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_HCSPARAMS2", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_HCSPARAMS2(a) bdk_usbdrdx_uahc_hcsparams2_t
#define bustype_BDK_USBDRDX_UAHC_HCSPARAMS2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_HCSPARAMS2(a) "USBDRDX_UAHC_HCSPARAMS2"
#define device_bar_BDK_USBDRDX_UAHC_HCSPARAMS2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_HCSPARAMS2(a) (a)
#define arguments_BDK_USBDRDX_UAHC_HCSPARAMS2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_hcsparams3
 *
 * XHCI Controller Structural Parameters Register 3
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.5.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_hcsparams3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t u2_device_exit_latency : 16;/**< [ 31: 16](RO) U2 device exit latency. */
        uint32_t reserved_8_15         : 8;
        uint32_t u1_device_exit_latency : 8; /**< [  7:  0](RO) U1 device exit latency. */
#else /* Word 0 - Little Endian */
        uint32_t u1_device_exit_latency : 8; /**< [  7:  0](RO) U1 device exit latency. */
        uint32_t reserved_8_15         : 8;
        uint32_t u2_device_exit_latency : 16;/**< [ 31: 16](RO) U2 device exit latency. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_hcsparams3_s cn; */
} bdk_usbdrdx_uahc_hcsparams3_t;

static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_HCSPARAMS3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000000cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000000cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_HCSPARAMS3", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_HCSPARAMS3(a) bdk_usbdrdx_uahc_hcsparams3_t
#define bustype_BDK_USBDRDX_UAHC_HCSPARAMS3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_HCSPARAMS3(a) "USBDRDX_UAHC_HCSPARAMS3"
#define device_bar_BDK_USBDRDX_UAHC_HCSPARAMS3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_HCSPARAMS3(a) (a)
#define arguments_BDK_USBDRDX_UAHC_HCSPARAMS3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_iman#
 *
 * XHCI Interrupt Management Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_imanx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t ie                    : 1;  /**< [  1:  1](R/W) Interrupt enable. */
        uint32_t ip                    : 1;  /**< [  0:  0](R/W1C/H) Interrupt pending. */
#else /* Word 0 - Little Endian */
        uint32_t ip                    : 1;  /**< [  0:  0](R/W1C/H) Interrupt pending. */
        uint32_t ie                    : 1;  /**< [  1:  1](R/W) Interrupt enable. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_imanx_s cn; */
} bdk_usbdrdx_uahc_imanx_t;

static inline uint64_t BDK_USBDRDX_UAHC_IMANX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_IMANX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000460ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000460ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_IMANX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_IMANX(a,b) bdk_usbdrdx_uahc_imanx_t
#define bustype_BDK_USBDRDX_UAHC_IMANX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_IMANX(a,b) "USBDRDX_UAHC_IMANX"
#define device_bar_BDK_USBDRDX_UAHC_IMANX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_IMANX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_IMANX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_imod#
 *
 * XHCI Interrupt Moderation Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.2.2.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_imodx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t imodc                 : 16; /**< [ 31: 16](R/W) Interrupt moderation counter. */
        uint32_t imodi                 : 16; /**< [ 15:  0](R/W) Interrupt moderation interval. */
#else /* Word 0 - Little Endian */
        uint32_t imodi                 : 16; /**< [ 15:  0](R/W) Interrupt moderation interval. */
        uint32_t imodc                 : 16; /**< [ 31: 16](R/W) Interrupt moderation counter. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_imodx_s cn; */
} bdk_usbdrdx_uahc_imodx_t;

static inline uint64_t BDK_USBDRDX_UAHC_IMODX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_IMODX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000464ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000464ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_IMODX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_IMODX(a,b) bdk_usbdrdx_uahc_imodx_t
#define bustype_BDK_USBDRDX_UAHC_IMODX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_IMODX(a,b) "USBDRDX_UAHC_IMODX"
#define device_bar_BDK_USBDRDX_UAHC_IMODX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_IMODX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_IMODX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_mfindex
 *
 * XHCI Microframe Index Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.5.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_mfindex_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_14_31        : 18;
        uint32_t mfindex               : 14; /**< [ 13:  0](RO/H) Microframe index. */
#else /* Word 0 - Little Endian */
        uint32_t mfindex               : 14; /**< [ 13:  0](RO/H) Microframe index. */
        uint32_t reserved_14_31        : 18;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_mfindex_s cn; */
} bdk_usbdrdx_uahc_mfindex_t;

static inline uint64_t BDK_USBDRDX_UAHC_MFINDEX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_MFINDEX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000440ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000440ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_MFINDEX", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_MFINDEX(a) bdk_usbdrdx_uahc_mfindex_t
#define bustype_BDK_USBDRDX_UAHC_MFINDEX(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_MFINDEX(a) "USBDRDX_UAHC_MFINDEX"
#define device_bar_BDK_USBDRDX_UAHC_MFINDEX(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_MFINDEX(a) (a)
#define arguments_BDK_USBDRDX_UAHC_MFINDEX(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_pagesize
 *
 * XHCI Page-Size Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.3.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_pagesize_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t pagesize              : 16; /**< [ 15:  0](RO) Page size. */
#else /* Word 0 - Little Endian */
        uint32_t pagesize              : 16; /**< [ 15:  0](RO) Page size. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_pagesize_s cn; */
} bdk_usbdrdx_uahc_pagesize_t;

static inline uint64_t BDK_USBDRDX_UAHC_PAGESIZE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PAGESIZE(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000028ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000028ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_PAGESIZE", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PAGESIZE(a) bdk_usbdrdx_uahc_pagesize_t
#define bustype_BDK_USBDRDX_UAHC_PAGESIZE(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PAGESIZE(a) "USBDRDX_UAHC_PAGESIZE"
#define device_bar_BDK_USBDRDX_UAHC_PAGESIZE(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PAGESIZE(a) (a)
#define arguments_BDK_USBDRDX_UAHC_PAGESIZE(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_porthlpmc_20#
 *
 * XHCI Port Hardware LPM Control (High-Speed) Register
 * For information on this register, refer to the xHCI Specification, v1.1, section 5.4.11.2.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_porthlpmc_20x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_14_31        : 18;
        uint32_t hirdd                 : 4;  /**< [ 13: 10](R/W) See section 5.4.11.2 of the XHCI Spec 1.1.
                                                                 If USBDRD()_UAHC_SUPTPRT2_DW2[BLC] = 0, then HIRD timing is applied to this field.
                                                                 If USBDRD()_UAHC_SUPTPRT2_DW2[BLC] = 1, then BESL timing is applied to this field. */
        uint32_t l1_timeout            : 8;  /**< [  9:  2](R/W) Timeout value for the L1 inactivity timer (LPM Timer). This field is set to 0x0 by the
                                                                 assertion of PR to 1. Refer to section 4.23.5.1.1.1 (in XHCI spec 1.1) for more
                                                                 information on L1 Timeout operation.
                                                                 The following are permissible values:
                                                                 0x0 =  128 us. (default).
                                                                 0x1 =  256 us.
                                                                 0x2 =  512 us.
                                                                 0x3 =  768 us.
                                                                 _ ...
                                                                 0xFF =  65280 us. */
        uint32_t hirdm                 : 2;  /**< [  1:  0](R/W) Host-initiated resume-duration mode. */
#else /* Word 0 - Little Endian */
        uint32_t hirdm                 : 2;  /**< [  1:  0](R/W) Host-initiated resume-duration mode. */
        uint32_t l1_timeout            : 8;  /**< [  9:  2](R/W) Timeout value for the L1 inactivity timer (LPM Timer). This field is set to 0x0 by the
                                                                 assertion of PR to 1. Refer to section 4.23.5.1.1.1 (in XHCI spec 1.1) for more
                                                                 information on L1 Timeout operation.
                                                                 The following are permissible values:
                                                                 0x0 =  128 us. (default).
                                                                 0x1 =  256 us.
                                                                 0x2 =  512 us.
                                                                 0x3 =  768 us.
                                                                 _ ...
                                                                 0xFF =  65280 us. */
        uint32_t hirdd                 : 4;  /**< [ 13: 10](R/W) See section 5.4.11.2 of the XHCI Spec 1.1.
                                                                 If USBDRD()_UAHC_SUPTPRT2_DW2[BLC] = 0, then HIRD timing is applied to this field.
                                                                 If USBDRD()_UAHC_SUPTPRT2_DW2[BLC] = 1, then BESL timing is applied to this field. */
        uint32_t reserved_14_31        : 18;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_porthlpmc_20x_s cn; */
} bdk_usbdrdx_uahc_porthlpmc_20x_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTHLPMC_20X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTHLPMC_20X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x86800000042cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x86800000042cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTHLPMC_20X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) bdk_usbdrdx_uahc_porthlpmc_20x_t
#define bustype_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) "USBDRDX_UAHC_PORTHLPMC_20X"
#define device_bar_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTHLPMC_20X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_porthlpmc_ss#
 *
 * XHCI Port Hardware LPM Control (SuperSpeed) Register
 * The USB3 Port Hardware LPM Control register is reserved and shall be treated as RsvdP by
 * software. See xHCI specification v1.1 section 5.4.11.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_porthlpmc_ssx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_porthlpmc_ssx_s cn; */
} bdk_usbdrdx_uahc_porthlpmc_ssx_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTHLPMC_SSX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTHLPMC_SSX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==1)))
        return 0x86800000042cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==1)))
        return 0x86800000042cll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTHLPMC_SSX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) bdk_usbdrdx_uahc_porthlpmc_ssx_t
#define bustype_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) "USBDRDX_UAHC_PORTHLPMC_SSX"
#define device_bar_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTHLPMC_SSX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_portli_20#
 *
 * XHCI Port Link (High-Speed) Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.10.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_portli_20x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_0_31         : 32;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_31         : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_portli_20x_s cn; */
} bdk_usbdrdx_uahc_portli_20x_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTLI_20X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTLI_20X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000428ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000428ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTLI_20X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) bdk_usbdrdx_uahc_portli_20x_t
#define bustype_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) "USBDRDX_UAHC_PORTLI_20X"
#define device_bar_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTLI_20X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_portli_ss#
 *
 * XHCI Port Link (SuperSpeed) Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.10.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_portli_ssx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t linkerrorcount        : 16; /**< [ 15:  0](RO/H) Link error count. */
#else /* Word 0 - Little Endian */
        uint32_t linkerrorcount        : 16; /**< [ 15:  0](RO/H) Link error count. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_portli_ssx_s cn; */
} bdk_usbdrdx_uahc_portli_ssx_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTLI_SSX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTLI_SSX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==1)))
        return 0x868000000428ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==1)))
        return 0x868000000428ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTLI_SSX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) bdk_usbdrdx_uahc_portli_ssx_t
#define bustype_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) "USBDRDX_UAHC_PORTLI_SSX"
#define device_bar_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTLI_SSX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_portpmsc_20#
 *
 * XHCI Port Power Management Status/Control (High-Speed) Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.9.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_portpmsc_20x_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t port_test_control     : 4;  /**< [ 31: 28](R/W) Port test control. */
        uint32_t reserved_17_27        : 11;
        uint32_t hle                   : 1;  /**< [ 16: 16](R/W) Hardware LPM enable. */
        uint32_t l1_device_slot        : 8;  /**< [ 15:  8](R/W) L1 device slot. */
        uint32_t hird                  : 4;  /**< [  7:  4](R/W) Host-initiated resume duration. */
        uint32_t rwe                   : 1;  /**< [  3:  3](R/W) Remove wake enable. */
        uint32_t l1s                   : 3;  /**< [  2:  0](RO/H) L1 status. */
#else /* Word 0 - Little Endian */
        uint32_t l1s                   : 3;  /**< [  2:  0](RO/H) L1 status. */
        uint32_t rwe                   : 1;  /**< [  3:  3](R/W) Remove wake enable. */
        uint32_t hird                  : 4;  /**< [  7:  4](R/W) Host-initiated resume duration. */
        uint32_t l1_device_slot        : 8;  /**< [ 15:  8](R/W) L1 device slot. */
        uint32_t hle                   : 1;  /**< [ 16: 16](R/W) Hardware LPM enable. */
        uint32_t reserved_17_27        : 11;
        uint32_t port_test_control     : 4;  /**< [ 31: 28](R/W) Port test control. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_portpmsc_20x_s cn; */
} bdk_usbdrdx_uahc_portpmsc_20x_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTPMSC_20X(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTPMSC_20X(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000000424ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000000424ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTPMSC_20X", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) bdk_usbdrdx_uahc_portpmsc_20x_t
#define bustype_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) "USBDRDX_UAHC_PORTPMSC_20X"
#define device_bar_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTPMSC_20X(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_portpmsc_ss#
 *
 * XHCI Port Power Management Status/Control (SuperSpeed) Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.9.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_portpmsc_ssx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t fla                   : 1;  /**< [ 16: 16](R/W/H) Force link PM accept. */
        uint32_t u2_timeout            : 8;  /**< [ 15:  8](R/W/H) U2 timeout. */
        uint32_t u1_timeout            : 8;  /**< [  7:  0](R/W/H) U1 timeout. */
#else /* Word 0 - Little Endian */
        uint32_t u1_timeout            : 8;  /**< [  7:  0](R/W/H) U1 timeout. */
        uint32_t u2_timeout            : 8;  /**< [ 15:  8](R/W/H) U2 timeout. */
        uint32_t fla                   : 1;  /**< [ 16: 16](R/W/H) Force link PM accept. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_portpmsc_ssx_s cn; */
} bdk_usbdrdx_uahc_portpmsc_ssx_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTPMSC_SSX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTPMSC_SSX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==1)))
        return 0x868000000424ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==1)))
        return 0x868000000424ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTPMSC_SSX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) bdk_usbdrdx_uahc_portpmsc_ssx_t
#define bustype_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) "USBDRDX_UAHC_PORTPMSC_SSX"
#define device_bar_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTPMSC_SSX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_portsc#
 *
 * XHCI Port Status and Control Registers
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.8. Port 1
 * is USB3.0 SuperSpeed link, Port 0 is USB2.0 high-speed/full-speed/low-speed link.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_portscx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t wpr                   : 1;  /**< [ 31: 31](WO) Warm port reset. */
        uint32_t dr                    : 1;  /**< [ 30: 30](RO/H) Device removable. */
        uint32_t reserved_28_29        : 2;
        uint32_t woe                   : 1;  /**< [ 27: 27](R/W) Wake-on-overcurrent enable. */
        uint32_t wde                   : 1;  /**< [ 26: 26](R/W) Wake-on-disconnect enable. */
        uint32_t wce                   : 1;  /**< [ 25: 25](R/W) Wake-on-connect enable. */
        uint32_t cas                   : 1;  /**< [ 24: 24](RO/H) Cold-attach status. */
        uint32_t cec                   : 1;  /**< [ 23: 23](R/W1C/H) Port-configuration-error change. */
        uint32_t plc                   : 1;  /**< [ 22: 22](R/W1C/H) Port-link-state change. */
        uint32_t prc                   : 1;  /**< [ 21: 21](R/W1C/H) Port-reset change. */
        uint32_t occ                   : 1;  /**< [ 20: 20](R/W1C/H) Overcurrent change. */
        uint32_t wrc                   : 1;  /**< [ 19: 19](R/W1C/H) Warm-port-reset change. */
        uint32_t pec                   : 1;  /**< [ 18: 18](R/W1C/H) Port enabled/disabled change. */
        uint32_t csc                   : 1;  /**< [ 17: 17](R/W1C/H) Connect-status change. */
        uint32_t lws                   : 1;  /**< [ 16: 16](WO) Port-link-state write strobe. */
        uint32_t pic                   : 2;  /**< [ 15: 14](R/W/H) Port indicator control. */
        uint32_t portspeed             : 4;  /**< [ 13: 10](RO/H) Port speed. */
        uint32_t pp                    : 1;  /**< [  9:  9](R/W/H) Port power. */
        uint32_t pls                   : 4;  /**< [  8:  5](R/W/H) Port-link state. */
        uint32_t pr                    : 1;  /**< [  4:  4](R/W1S/H) Port reset. */
        uint32_t oca                   : 1;  /**< [  3:  3](RO/H) Overcurrent active. */
        uint32_t reserved_2            : 1;
        uint32_t ped                   : 1;  /**< [  1:  1](R/W1C/H) Port enabled/disabled. */
        uint32_t ccs                   : 1;  /**< [  0:  0](RO/H) Current connect status. */
#else /* Word 0 - Little Endian */
        uint32_t ccs                   : 1;  /**< [  0:  0](RO/H) Current connect status. */
        uint32_t ped                   : 1;  /**< [  1:  1](R/W1C/H) Port enabled/disabled. */
        uint32_t reserved_2            : 1;
        uint32_t oca                   : 1;  /**< [  3:  3](RO/H) Overcurrent active. */
        uint32_t pr                    : 1;  /**< [  4:  4](R/W1S/H) Port reset. */
        uint32_t pls                   : 4;  /**< [  8:  5](R/W/H) Port-link state. */
        uint32_t pp                    : 1;  /**< [  9:  9](R/W/H) Port power. */
        uint32_t portspeed             : 4;  /**< [ 13: 10](RO/H) Port speed. */
        uint32_t pic                   : 2;  /**< [ 15: 14](R/W/H) Port indicator control. */
        uint32_t lws                   : 1;  /**< [ 16: 16](WO) Port-link-state write strobe. */
        uint32_t csc                   : 1;  /**< [ 17: 17](R/W1C/H) Connect-status change. */
        uint32_t pec                   : 1;  /**< [ 18: 18](R/W1C/H) Port enabled/disabled change. */
        uint32_t wrc                   : 1;  /**< [ 19: 19](R/W1C/H) Warm-port-reset change. */
        uint32_t occ                   : 1;  /**< [ 20: 20](R/W1C/H) Overcurrent change. */
        uint32_t prc                   : 1;  /**< [ 21: 21](R/W1C/H) Port-reset change. */
        uint32_t plc                   : 1;  /**< [ 22: 22](R/W1C/H) Port-link-state change. */
        uint32_t cec                   : 1;  /**< [ 23: 23](R/W1C/H) Port-configuration-error change. */
        uint32_t cas                   : 1;  /**< [ 24: 24](RO/H) Cold-attach status. */
        uint32_t wce                   : 1;  /**< [ 25: 25](R/W) Wake-on-connect enable. */
        uint32_t wde                   : 1;  /**< [ 26: 26](R/W) Wake-on-disconnect enable. */
        uint32_t woe                   : 1;  /**< [ 27: 27](R/W) Wake-on-overcurrent enable. */
        uint32_t reserved_28_29        : 2;
        uint32_t dr                    : 1;  /**< [ 30: 30](RO/H) Device removable. */
        uint32_t wpr                   : 1;  /**< [ 31: 31](WO) Warm port reset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_portscx_s cn; */
} bdk_usbdrdx_uahc_portscx_t;

static inline uint64_t BDK_USBDRDX_UAHC_PORTSCX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_PORTSCX(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b<=1)))
        return 0x868000000420ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b<=1)))
        return 0x868000000420ll + 0x1000000000ll * ((a) & 0x1) + 0x10ll * ((b) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_PORTSCX", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_PORTSCX(a,b) bdk_usbdrdx_uahc_portscx_t
#define bustype_BDK_USBDRDX_UAHC_PORTSCX(a,b) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_PORTSCX(a,b) "USBDRDX_UAHC_PORTSCX"
#define device_bar_BDK_USBDRDX_UAHC_PORTSCX(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_PORTSCX(a,b) (a)
#define arguments_BDK_USBDRDX_UAHC_PORTSCX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_rtsoff
 *
 * XHCI Runtime Register-Space Offset Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.3.8.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_rtsoff_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t rtsoff                : 27; /**< [ 31:  5](RO) Runtime register-space offset. */
        uint32_t reserved_0_4          : 5;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_4          : 5;
        uint32_t rtsoff                : 27; /**< [ 31:  5](RO) Runtime register-space offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_rtsoff_s cn; */
} bdk_usbdrdx_uahc_rtsoff_t;

static inline uint64_t BDK_USBDRDX_UAHC_RTSOFF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_RTSOFF(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000018ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000018ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_RTSOFF", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_RTSOFF(a) bdk_usbdrdx_uahc_rtsoff_t
#define bustype_BDK_USBDRDX_UAHC_RTSOFF(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_RTSOFF(a) "USBDRDX_UAHC_RTSOFF"
#define device_bar_BDK_USBDRDX_UAHC_RTSOFF(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_RTSOFF(a) (a)
#define arguments_BDK_USBDRDX_UAHC_RTSOFF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt2_dw0
 *
 * XHCI Supported-Protocol-Capability (USB 2.0) Register 0
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt2_dw0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t majorrev              : 8;  /**< [ 31: 24](RO) Major revision. */
        uint32_t minorrev              : 8;  /**< [ 23: 16](RO) Minor revision. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = supported protocol. */
#else /* Word 0 - Little Endian */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = supported protocol. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t minorrev              : 8;  /**< [ 23: 16](RO) Minor revision. */
        uint32_t majorrev              : 8;  /**< [ 31: 24](RO) Major revision. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt2_dw0_s cn; */
} bdk_usbdrdx_uahc_suptprt2_dw0_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000890ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000890ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT2_DW0", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) bdk_usbdrdx_uahc_suptprt2_dw0_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) "USBDRDX_UAHC_SUPTPRT2_DW0"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT2_DW0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt2_dw1
 *
 * XHCI Supported-Protocol-Capability (USB 2.0) Register 1
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt2_dw1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t name                  : 32; /**< [ 31:  0](RO) Name string: 'USB'. */
#else /* Word 0 - Little Endian */
        uint32_t name                  : 32; /**< [ 31:  0](RO) Name string: 'USB'. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt2_dw1_s cn; */
} bdk_usbdrdx_uahc_suptprt2_dw1_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000894ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000894ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT2_DW1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) bdk_usbdrdx_uahc_suptprt2_dw1_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) "USBDRDX_UAHC_SUPTPRT2_DW1"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT2_DW1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt2_dw2
 *
 * XHCI Supported-Protocol-Capability (USB 2.0) Register 2
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt2_dw2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t psic                  : 4;  /**< [ 31: 28](RO) Protocol speed ID count. */
        uint32_t reserved_21_27        : 7;
        uint32_t blc                   : 1;  /**< [ 20: 20](RO) BESL LPM capability. */
        uint32_t hlc                   : 1;  /**< [ 19: 19](RO) Hardware LMP capability. */
        uint32_t ihi                   : 1;  /**< [ 18: 18](RO) Integrated hub implemented. */
        uint32_t hso                   : 1;  /**< [ 17: 17](RO) High-speed only. */
        uint32_t reserved_16           : 1;
        uint32_t compatprtcnt          : 8;  /**< [ 15:  8](RO) Compatible port count. */
        uint32_t compatprtoff          : 8;  /**< [  7:  0](RO) Compatible port offset. */
#else /* Word 0 - Little Endian */
        uint32_t compatprtoff          : 8;  /**< [  7:  0](RO) Compatible port offset. */
        uint32_t compatprtcnt          : 8;  /**< [ 15:  8](RO) Compatible port count. */
        uint32_t reserved_16           : 1;
        uint32_t hso                   : 1;  /**< [ 17: 17](RO) High-speed only. */
        uint32_t ihi                   : 1;  /**< [ 18: 18](RO) Integrated hub implemented. */
        uint32_t hlc                   : 1;  /**< [ 19: 19](RO) Hardware LMP capability. */
        uint32_t blc                   : 1;  /**< [ 20: 20](RO) BESL LPM capability. */
        uint32_t reserved_21_27        : 7;
        uint32_t psic                  : 4;  /**< [ 31: 28](RO) Protocol speed ID count. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt2_dw2_s cn; */
} bdk_usbdrdx_uahc_suptprt2_dw2_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000898ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000898ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT2_DW2", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) bdk_usbdrdx_uahc_suptprt2_dw2_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) "USBDRDX_UAHC_SUPTPRT2_DW2"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT2_DW2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt2_dw3
 *
 * XHCI Supported-Protocol-Capability (USB 2.0) Register 3
 * For information on this register, refer to the xHCI Specification, v1.1, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt2_dw3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_5_31         : 27;
        uint32_t protslottype          : 5;  /**< [  4:  0](RO) Protocol slot type. */
#else /* Word 0 - Little Endian */
        uint32_t protslottype          : 5;  /**< [  4:  0](RO) Protocol slot type. */
        uint32_t reserved_5_31         : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt2_dw3_s cn; */
} bdk_usbdrdx_uahc_suptprt2_dw3_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT2_DW3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x86800000089cll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x86800000089cll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT2_DW3", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) bdk_usbdrdx_uahc_suptprt2_dw3_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) "USBDRDX_UAHC_SUPTPRT2_DW3"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT2_DW3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt3_dw0
 *
 * XHCI Supported-Protocol-Capability (USB 3.0) Register 0
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt3_dw0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t majorrev              : 8;  /**< [ 31: 24](RO) Major revision. */
        uint32_t minorrev              : 8;  /**< [ 23: 16](RO) Minor revision. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO/H) Next capability pointer. Value depends on USBDRD()_UAHC_GUCTL[EXTCAPSUPTEN]. If
                                                                 EXTCAPSUPTEN
                                                                 =
                                                                 0, value is 0x0. If EXTCAPSUPTEN = 1, value is 0x4. */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = supported protocol. */
#else /* Word 0 - Little Endian */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = supported protocol. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO/H) Next capability pointer. Value depends on USBDRD()_UAHC_GUCTL[EXTCAPSUPTEN]. If
                                                                 EXTCAPSUPTEN
                                                                 =
                                                                 0, value is 0x0. If EXTCAPSUPTEN = 1, value is 0x4. */
        uint32_t minorrev              : 8;  /**< [ 23: 16](RO) Minor revision. */
        uint32_t majorrev              : 8;  /**< [ 31: 24](RO) Major revision. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt3_dw0_s cn; */
} bdk_usbdrdx_uahc_suptprt3_dw0_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680000008a0ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680000008a0ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT3_DW0", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) bdk_usbdrdx_uahc_suptprt3_dw0_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) "USBDRDX_UAHC_SUPTPRT3_DW0"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT3_DW0(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt3_dw1
 *
 * XHCI Supported-Protocol-Capability (USB 3.0) Register 1
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt3_dw1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t name                  : 32; /**< [ 31:  0](RO) Name string: 'USB'. */
#else /* Word 0 - Little Endian */
        uint32_t name                  : 32; /**< [ 31:  0](RO) Name string: 'USB'. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt3_dw1_s cn; */
} bdk_usbdrdx_uahc_suptprt3_dw1_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680000008a4ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680000008a4ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT3_DW1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) bdk_usbdrdx_uahc_suptprt3_dw1_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) "USBDRDX_UAHC_SUPTPRT3_DW1"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT3_DW1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt3_dw2
 *
 * XHCI Supported-Protocol-Capability (USB 3.0) Register 2
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt3_dw2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t psic                  : 4;  /**< [ 31: 28](RO) Protocol speed ID count. */
        uint32_t reserved_16_27        : 12;
        uint32_t compatprtcnt          : 8;  /**< [ 15:  8](RO) Compatible port count. */
        uint32_t compatprtoff          : 8;  /**< [  7:  0](RO) Compatible port offset. */
#else /* Word 0 - Little Endian */
        uint32_t compatprtoff          : 8;  /**< [  7:  0](RO) Compatible port offset. */
        uint32_t compatprtcnt          : 8;  /**< [ 15:  8](RO) Compatible port count. */
        uint32_t reserved_16_27        : 12;
        uint32_t psic                  : 4;  /**< [ 31: 28](RO) Protocol speed ID count. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt3_dw2_s cn; */
} bdk_usbdrdx_uahc_suptprt3_dw2_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW2(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680000008a8ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680000008a8ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT3_DW2", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) bdk_usbdrdx_uahc_suptprt3_dw2_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) "USBDRDX_UAHC_SUPTPRT3_DW2"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT3_DW2(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_suptprt3_dw3
 *
 * XHCI Supported-Protocol-Capability (USB 3.0) Register 3
 * For information on this register, refer to the xHCI Specification, v1.1, section 7.2.
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_suptprt3_dw3_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_5_31         : 27;
        uint32_t protslottype          : 5;  /**< [  4:  0](RO) Protocol slot type. */
#else /* Word 0 - Little Endian */
        uint32_t protslottype          : 5;  /**< [  4:  0](RO) Protocol slot type. */
        uint32_t reserved_5_31         : 27;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_suptprt3_dw3_s cn; */
} bdk_usbdrdx_uahc_suptprt3_dw3_t;

static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW3(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_SUPTPRT3_DW3(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680000008acll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680000008acll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_SUPTPRT3_DW3", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) bdk_usbdrdx_uahc_suptprt3_dw3_t
#define bustype_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) "USBDRDX_UAHC_SUPTPRT3_DW3"
#define device_bar_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) (a)
#define arguments_BDK_USBDRDX_UAHC_SUPTPRT3_DW3(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_usbcmd
 *
 * XHCI Command Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_usbcmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t eu3s                  : 1;  /**< [ 11: 11](R/W) Enable U3 MFINDEX stop. */
        uint32_t ewe                   : 1;  /**< [ 10: 10](R/W) Enable wrap event. */
        uint32_t crs                   : 1;  /**< [  9:  9](WO) Controller restore state. */
        uint32_t css                   : 1;  /**< [  8:  8](WO) Controller save state. */
        uint32_t lhcrst                : 1;  /**< [  7:  7](R/W1S/H) Light-host-controller reset. */
        uint32_t reserved_4_6          : 3;
        uint32_t hsee                  : 1;  /**< [  3:  3](R/W) Host-system-error enable. */
        uint32_t inte                  : 1;  /**< [  2:  2](R/W) Interrupter enable. */
        uint32_t hcrst                 : 1;  /**< [  1:  1](R/W1S/H) Host-controller reset. */
        uint32_t r_s                   : 1;  /**< [  0:  0](R/W) Run/stop. */
#else /* Word 0 - Little Endian */
        uint32_t r_s                   : 1;  /**< [  0:  0](R/W) Run/stop. */
        uint32_t hcrst                 : 1;  /**< [  1:  1](R/W1S/H) Host-controller reset. */
        uint32_t inte                  : 1;  /**< [  2:  2](R/W) Interrupter enable. */
        uint32_t hsee                  : 1;  /**< [  3:  3](R/W) Host-system-error enable. */
        uint32_t reserved_4_6          : 3;
        uint32_t lhcrst                : 1;  /**< [  7:  7](R/W1S/H) Light-host-controller reset. */
        uint32_t css                   : 1;  /**< [  8:  8](WO) Controller save state. */
        uint32_t crs                   : 1;  /**< [  9:  9](WO) Controller restore state. */
        uint32_t ewe                   : 1;  /**< [ 10: 10](R/W) Enable wrap event. */
        uint32_t eu3s                  : 1;  /**< [ 11: 11](R/W) Enable U3 MFINDEX stop. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_usbcmd_s cn; */
} bdk_usbdrdx_uahc_usbcmd_t;

static inline uint64_t BDK_USBDRDX_UAHC_USBCMD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_USBCMD(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000020ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000020ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_USBCMD", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_USBCMD(a) bdk_usbdrdx_uahc_usbcmd_t
#define bustype_BDK_USBDRDX_UAHC_USBCMD(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_USBCMD(a) "USBDRDX_UAHC_USBCMD"
#define device_bar_BDK_USBDRDX_UAHC_USBCMD(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_USBCMD(a) (a)
#define arguments_BDK_USBDRDX_UAHC_USBCMD(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_usblegctlsts
 *
 * XHCI Legacy Support Control/Status Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.1.2. Note
 * that the SMI interrupts are not connected to anything in a CNXXXX configuration.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_usblegctlsts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t smi_on_bar            : 1;  /**< [ 31: 31](R/W1C/H) System management interrupt on BAR. Never generated. */
        uint32_t smi_on_pci_command    : 1;  /**< [ 30: 30](R/W1C/H) System management interrupt on PCI command. Never generated. */
        uint32_t smi_on_os_ownership   : 1;  /**< [ 29: 29](R/W1C/H) System management interrupt on OS ownership change. This bit is set to 1 whenever
                                                                 USBDRD()_UAHC_USBLEGSUP[HC_OS_OWNED_SEMAPHORES] transitions. */
        uint32_t reserved_21_28        : 8;
        uint32_t smi_on_hostsystemerr  : 1;  /**< [ 20: 20](RO/H) System-management interrupt on host-system error. Shadow bit of USBDRD()_UAHC_USBSTS[HSE].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition and effects of the events associated with this bit being
                                                                 set to 1.

                                                                 To clear this bit to a 0, system software must write a 1 to USBDRD()_UAHC_USBSTS[HSE]. */
        uint32_t reserved_17_19        : 3;
        uint32_t smi_on_event_interrupt : 1; /**< [ 16: 16](RO/H) System-management interrupt on event interrupt. Shadow bit of USBDRD()_UAHC_USBSTS[EINT].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition. This bit automatically clears when [EINT] clears and
                                                                 sets when [EINT] sets. */
        uint32_t smi_on_bar_en         : 1;  /**< [ 15: 15](R/W) System-management interrupt on BAR enable. */
        uint32_t smi_on_pci_command_en : 1;  /**< [ 14: 14](R/W) System-management interrupt on PCI command enable. */
        uint32_t smi_on_os_ownership_en : 1; /**< [ 13: 13](R/W) System-management interrupt on OS ownership enable. */
        uint32_t reserved_5_12         : 8;
        uint32_t smi_on_hostsystemerr_en : 1;/**< [  4:  4](R/W) System-management interrupt on host-system error enable */
        uint32_t reserved_1_3          : 3;
        uint32_t usb_smi_en            : 1;  /**< [  0:  0](R/W) USB system-management interrupt enable. */
#else /* Word 0 - Little Endian */
        uint32_t usb_smi_en            : 1;  /**< [  0:  0](R/W) USB system-management interrupt enable. */
        uint32_t reserved_1_3          : 3;
        uint32_t smi_on_hostsystemerr_en : 1;/**< [  4:  4](R/W) System-management interrupt on host-system error enable */
        uint32_t reserved_5_12         : 8;
        uint32_t smi_on_os_ownership_en : 1; /**< [ 13: 13](R/W) System-management interrupt on OS ownership enable. */
        uint32_t smi_on_pci_command_en : 1;  /**< [ 14: 14](R/W) System-management interrupt on PCI command enable. */
        uint32_t smi_on_bar_en         : 1;  /**< [ 15: 15](R/W) System-management interrupt on BAR enable. */
        uint32_t smi_on_event_interrupt : 1; /**< [ 16: 16](RO/H) System-management interrupt on event interrupt. Shadow bit of USBDRD()_UAHC_USBSTS[EINT].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition. This bit automatically clears when [EINT] clears and
                                                                 sets when [EINT] sets. */
        uint32_t reserved_17_19        : 3;
        uint32_t smi_on_hostsystemerr  : 1;  /**< [ 20: 20](RO/H) System-management interrupt on host-system error. Shadow bit of USBDRD()_UAHC_USBSTS[HSE].
                                                                 Refer to
                                                                 xHCI Section 5.4.2 for definition and effects of the events associated with this bit being
                                                                 set to 1.

                                                                 To clear this bit to a 0, system software must write a 1 to USBDRD()_UAHC_USBSTS[HSE]. */
        uint32_t reserved_21_28        : 8;
        uint32_t smi_on_os_ownership   : 1;  /**< [ 29: 29](R/W1C/H) System management interrupt on OS ownership change. This bit is set to 1 whenever
                                                                 USBDRD()_UAHC_USBLEGSUP[HC_OS_OWNED_SEMAPHORES] transitions. */
        uint32_t smi_on_pci_command    : 1;  /**< [ 30: 30](R/W1C/H) System management interrupt on PCI command. Never generated. */
        uint32_t smi_on_bar            : 1;  /**< [ 31: 31](R/W1C/H) System management interrupt on BAR. Never generated. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_usblegctlsts_s cn; */
} bdk_usbdrdx_uahc_usblegctlsts_t;

static inline uint64_t BDK_USBDRDX_UAHC_USBLEGCTLSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_USBLEGCTLSTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000884ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000884ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_USBLEGCTLSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) bdk_usbdrdx_uahc_usblegctlsts_t
#define bustype_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) "USBDRDX_UAHC_USBLEGCTLSTS"
#define device_bar_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_USBLEGCTLSTS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_usblegsup
 *
 * XHCI Legacy Support Capability Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 7.1.1.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_usblegsup_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_25_31        : 7;
        uint32_t hc_os_owned_semaphores : 1; /**< [ 24: 24](R/W) HC OS-owned semaphore. */
        uint32_t reserved_17_23        : 7;
        uint32_t hc_bios_owned_semaphores : 1;/**< [ 16: 16](R/W) HC BIOS-owned semaphore. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO) Next xHCI extended-capability pointer. */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = USB legacy support. */
#else /* Word 0 - Little Endian */
        uint32_t capid                 : 8;  /**< [  7:  0](RO) Capability ID = USB legacy support. */
        uint32_t nextcapptr            : 8;  /**< [ 15:  8](RO) Next xHCI extended-capability pointer. */
        uint32_t hc_bios_owned_semaphores : 1;/**< [ 16: 16](R/W) HC BIOS-owned semaphore. */
        uint32_t reserved_17_23        : 7;
        uint32_t hc_os_owned_semaphores : 1; /**< [ 24: 24](R/W) HC OS-owned semaphore. */
        uint32_t reserved_25_31        : 7;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_usblegsup_s cn; */
} bdk_usbdrdx_uahc_usblegsup_t;

static inline uint64_t BDK_USBDRDX_UAHC_USBLEGSUP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_USBLEGSUP(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000880ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000880ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_USBLEGSUP", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_USBLEGSUP(a) bdk_usbdrdx_uahc_usblegsup_t
#define bustype_BDK_USBDRDX_UAHC_USBLEGSUP(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_USBLEGSUP(a) "USBDRDX_UAHC_USBLEGSUP"
#define device_bar_BDK_USBDRDX_UAHC_USBLEGSUP(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_USBLEGSUP(a) (a)
#define arguments_BDK_USBDRDX_UAHC_USBLEGSUP(a) (a),-1,-1,-1

/**
 * Register (NCB32b) usbdrd#_uahc_usbsts
 *
 * XHCI Status Register
 * For information on this register, refer to the xHCI Specification, v1.0, section 5.4.2.
 *
 * This register can be reset by NCB reset,
 * or USBDRD()_UCTL_CTL[UAHC_RST],
 * or USBDRD()_UAHC_GCTL[CORESOFTRESET],
 * or USBDRD()_UAHC_USBCMD[HCRST], or USBDRD()_UAHC_USBCMD[LHCRST].
 */
typedef union
{
    uint32_t u;
    struct bdk_usbdrdx_uahc_usbsts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_13_31        : 19;
        uint32_t hce                   : 1;  /**< [ 12: 12](RO/H) Host-controller error. */
        uint32_t cnr                   : 1;  /**< [ 11: 11](RO/H) Controller not ready. */
        uint32_t sre                   : 1;  /**< [ 10: 10](R/W1C/H) Save/restore error. */
        uint32_t rss                   : 1;  /**< [  9:  9](RO/H) Restore state status. */
        uint32_t sss                   : 1;  /**< [  8:  8](RO/H) Save state status. */
        uint32_t reserved_5_7          : 3;
        uint32_t pcd                   : 1;  /**< [  4:  4](R/W1C/H) Port-change detect. */
        uint32_t eint                  : 1;  /**< [  3:  3](R/W1C/H) Event interrupt. */
        uint32_t hse                   : 1;  /**< [  2:  2](R/W1C/H) Host-system error. The typical software response to an HSE is to reset the core. */
        uint32_t reserved_1            : 1;
        uint32_t hch                   : 1;  /**< [  0:  0](RO/H) HC halted. */
#else /* Word 0 - Little Endian */
        uint32_t hch                   : 1;  /**< [  0:  0](RO/H) HC halted. */
        uint32_t reserved_1            : 1;
        uint32_t hse                   : 1;  /**< [  2:  2](R/W1C/H) Host-system error. The typical software response to an HSE is to reset the core. */
        uint32_t eint                  : 1;  /**< [  3:  3](R/W1C/H) Event interrupt. */
        uint32_t pcd                   : 1;  /**< [  4:  4](R/W1C/H) Port-change detect. */
        uint32_t reserved_5_7          : 3;
        uint32_t sss                   : 1;  /**< [  8:  8](RO/H) Save state status. */
        uint32_t rss                   : 1;  /**< [  9:  9](RO/H) Restore state status. */
        uint32_t sre                   : 1;  /**< [ 10: 10](R/W1C/H) Save/restore error. */
        uint32_t cnr                   : 1;  /**< [ 11: 11](RO/H) Controller not ready. */
        uint32_t hce                   : 1;  /**< [ 12: 12](RO/H) Host-controller error. */
        uint32_t reserved_13_31        : 19;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uahc_usbsts_s cn; */
} bdk_usbdrdx_uahc_usbsts_t;

static inline uint64_t BDK_USBDRDX_UAHC_USBSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UAHC_USBSTS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000000024ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000000024ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UAHC_USBSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UAHC_USBSTS(a) bdk_usbdrdx_uahc_usbsts_t
#define bustype_BDK_USBDRDX_UAHC_USBSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_USBDRDX_UAHC_USBSTS(a) "USBDRDX_UAHC_USBSTS"
#define device_bar_BDK_USBDRDX_UAHC_USBSTS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UAHC_USBSTS(a) (a)
#define arguments_BDK_USBDRDX_UAHC_USBSTS(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_bist_status
 *
 * UCTL BIST Status Register
 * This register indicates the results from the built-in self-test (BIST) runs of USBDRD
 * memories.
 * A 0 indicates pass or never run, a 1 indicates fail. This register can be reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t uctl_xm_r_bist_ndone  : 1;  /**< [ 41: 41](RO/H) BIST is not complete for the UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_bist_ndone  : 1;  /**< [ 40: 40](RO/H) BIST is not complete for the UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_35_39        : 5;
        uint64_t uahc_ram2_bist_ndone  : 1;  /**< [ 34: 34](RO/H) BIST is not complete for the UAHC RxFIFO RAM (RAM2). */
        uint64_t uahc_ram1_bist_ndone  : 1;  /**< [ 33: 33](RO/H) BIST is not complete for the UAHC TxFIFO RAM (RAM1). */
        uint64_t uahc_ram0_bist_ndone  : 1;  /**< [ 32: 32](RO/H) BIST is not complete for the UAHC descriptor/register cache (RAM0). */
        uint64_t reserved_10_31        : 22;
        uint64_t uctl_xm_r_bist_status : 1;  /**< [  9:  9](RO/H) BIST status of the UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_bist_status : 1;  /**< [  8:  8](RO/H) BIST status of the UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_3_7          : 5;
        uint64_t uahc_ram2_bist_status : 1;  /**< [  2:  2](RO/H) BIST status of the UAHC RxFIFO RAM (RAM2). */
        uint64_t uahc_ram1_bist_status : 1;  /**< [  1:  1](RO/H) BIST status of the UAHC TxFIFO RAM (RAM1). */
        uint64_t uahc_ram0_bist_status : 1;  /**< [  0:  0](RO/H) BIST status of the UAHC descriptor/register cache (RAM0). */
#else /* Word 0 - Little Endian */
        uint64_t uahc_ram0_bist_status : 1;  /**< [  0:  0](RO/H) BIST status of the UAHC descriptor/register cache (RAM0). */
        uint64_t uahc_ram1_bist_status : 1;  /**< [  1:  1](RO/H) BIST status of the UAHC TxFIFO RAM (RAM1). */
        uint64_t uahc_ram2_bist_status : 1;  /**< [  2:  2](RO/H) BIST status of the UAHC RxFIFO RAM (RAM2). */
        uint64_t reserved_3_7          : 5;
        uint64_t uctl_xm_w_bist_status : 1;  /**< [  8:  8](RO/H) BIST status of the UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_r_bist_status : 1;  /**< [  9:  9](RO/H) BIST status of the UCTL AxiMaster read-data FIFO. */
        uint64_t reserved_10_31        : 22;
        uint64_t uahc_ram0_bist_ndone  : 1;  /**< [ 32: 32](RO/H) BIST is not complete for the UAHC descriptor/register cache (RAM0). */
        uint64_t uahc_ram1_bist_ndone  : 1;  /**< [ 33: 33](RO/H) BIST is not complete for the UAHC TxFIFO RAM (RAM1). */
        uint64_t uahc_ram2_bist_ndone  : 1;  /**< [ 34: 34](RO/H) BIST is not complete for the UAHC RxFIFO RAM (RAM2). */
        uint64_t reserved_35_39        : 5;
        uint64_t uctl_xm_w_bist_ndone  : 1;  /**< [ 40: 40](RO/H) BIST is not complete for the UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_r_bist_ndone  : 1;  /**< [ 41: 41](RO/H) BIST is not complete for the UCTL AxiMaster read-data FIFO. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_bist_status_s cn; */
} bdk_usbdrdx_uctl_bist_status_t;

static inline uint64_t BDK_USBDRDX_UCTL_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_BIST_STATUS(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100008ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100008ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_BIST_STATUS(a) bdk_usbdrdx_uctl_bist_status_t
#define bustype_BDK_USBDRDX_UCTL_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_BIST_STATUS(a) "USBDRDX_UCTL_BIST_STATUS"
#define device_bar_BDK_USBDRDX_UCTL_BIST_STATUS(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_BIST_STATUS(a) (a)
#define arguments_BDK_USBDRDX_UCTL_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_ctl
 *
 * UCTL Control Register
 * This register controls clocks, resets, power, and BIST.
 *
 * This register can be reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t clear_bist            : 1;  /**< [ 63: 63](R/W) BIST fast-clear mode select. A BIST run with this bit set clears all entries in USBDRD
                                                                 RAMs
                                                                 to 0x0.

                                                                 There are two major modes of BIST: full and clear. Full BIST is run by the BIST state
                                                                 machine when CLEAR_BIST is deasserted during BIST. Clear BIST is run if CLEAR_BIST is
                                                                 asserted during BIST.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts the
                                                                 CLEAR_BIST setting into the correct state and then perform another CSR write operation to
                                                                 set the BIST trigger (keeping the CLEAR_BIST state constant).
                                                                 CLEAR BIST completion is indicated by USBDRD()_UCTL_BIST_STATUS. A BIST clear operation
                                                                 takes almost 2,000 controller-clock cycles for the largest RAM. */
        uint64_t start_bist            : 1;  /**< [ 62: 62](R/W) Rising edge starts BIST on the memories in USBDRD.
                                                                 To run BIST, the controller clock must be both configured and enabled, and should be
                                                                 configured to the maximum available frequency given the available coprocessor clock and
                                                                 dividers.
                                                                 Also, the UCTL, UAHC, and UPHY should be held in software- initiated reset (using
                                                                 UPHY_RST, UAHC_RST, UCTL_RST) until BIST is complete.
                                                                 BIST defect status can be checked after FULL BIST completion, both of which are indicated
                                                                 in USBDRD()_UCTL_BIST_STATUS. The full BIST run takes almost 80,000 controller-clock
                                                                 cycles
                                                                 for
                                                                 the largest RAM. */
        uint64_t ref_clk_sel           : 2;  /**< [ 61: 60](R/W) Reference clock select. Choose reference-clock source for the SuperSpeed and high-speed
                                                                 PLL blocks.
                                                                 0x0 = Reference clock source for both PLLs come from the USB pads.
                                                                 0x1 = Reserved.
                                                                 0x2 = Reserved.
                                                                 0x3 = Reserved.

                                                                 This value can be changed only during UPHY_RST.

                                                                 If REF_CLK_SEL = 0x0, then the reference clock input cannot be spread-spectrum.

                                                                 INTERNAL: For the 0x1 selection, reference clock source for SuperSpeed PLL is from the USB
                                                                 pads, reference clock source for HighSpeed PLL is PLL_REF_CLK. But in 78xx, PLL_REF_CLK
                                                                 cannot be routed to USB without violating jitter requirements */
        uint64_t ssc_en                : 1;  /**< [ 59: 59](R/W) Spread-spectrum clock enable. Enables spread-spectrum clock production in the SuperSpeed
                                                                 function. If the input reference clock for the SuperSpeed PLL is already spread-spectrum,
                                                                 then do not enable this feature. The clocks sourced to the SuperSpeed function must have
                                                                 spread-spectrum to be compliant with the USB specification.
                                                                 The high-speed PLL cannot support a spread-spectrum input, so REF_CLK_SEL = 0x0 must
                                                                 enable this feature.
                                                                 This value may only be changed during UPHY_RST. */
        uint64_t ssc_range             : 3;  /**< [ 58: 56](R/W) Spread-spectrum clock range. Selects the range of spread-spectrum modulation when SSC_EN
                                                                 is asserted and the PHY is spreading the SuperSpeed transmit clocks.
                                                                 Applies a fixed offset to the phase accumulator.
                                                                 0x0 = -4980 ppm downspread of clock.
                                                                 0x1 = -4492 ppm.
                                                                 0x2 = -4003 ppm.
                                                                 0x3-0x7 = reserved.

                                                                 All of these settings are within the USB 3.0 specification. The amount of EMI emission
                                                                 reduction might decrease as the SSC_RANGE increases; therefore, the SSC_RANGE settings can
                                                                 be registered to enable the amount of spreading to be adjusted on a per-application basis.
                                                                 This value can be changed only during UPHY_RST. */
        uint64_t ssc_ref_clk_sel       : 9;  /**< [ 55: 47](R/W) Enables non-standard oscillator frequencies to generate targeted MPLL output rates. Input
                                                                 corresponds to the frequency-synthesis coefficient.

                                                                 [55:53]: modulus - 1,
                                                                 [52:47]: 2's complement push amount
                                                                 A value of 0x0 means this feature is disabled.
                                                                 The legal values are:
                                                                   If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                     0x0 is the only legal value.
                                                                   If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                     0x0:   if DLMC_REF_CLK* is another supported frequency (see list in
                                                                            MPLL_MULTIPLIER description).
                                                                 All other values are reserved.

                                                                 This value may only be changed during UPHY_RST.

                                                                 Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                 must all be programmed to the same frequency setting.
                                                                   INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                               0x0 is the only legal value.
                                                                             If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                               0x108: if DLMC_REF_CLK* is 19.2MHz, 24MHz, 26MHz, 38.4MHz, 48MHz,
                                                                                                 52MHz, 76.8MHz, 96MHz, 104MHz.
                                                                               0x0:   if DLMC_REF_CLK* is another supported frequency (see list in
                                                                                      MPLL_MULTIPLIER description). */
        uint64_t mpll_multiplier       : 7;  /**< [ 46: 40](R/W) Multiplies the reference clock to a frequency suitable for intended operating speed. The
                                                                  legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:

                                                                      0x19 = 100  MHz on DLMC_REF_CLK*

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x32 =  50  MHz on DLMC_REF_CLK*
                                                                      0x19 =  100 MHz on DLMC_REF_CLK*
                                                                      0x28 =  125 MHz on DLMC_REF_CLK*

                                                                  All other values are reserved.

                                                                  This value may only be changed during UPHY_RST.

                                                                  Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                  must all be programmed to the same frequency setting.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                 0x19 = 100  MHz on DLMC_REF_CLK*
                                                                                 0x68 =  24  MHz on DLMC_REF_CLK*
                                                                                 0x7D =  20  MHz on DLMC_REF_CLK*
                                                                                 0x02 =  19.2MHz on DLMC_REF_CLK*
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                 0x02 =  19.2MHz on DLMC_REF_CLK*
                                                                                 0x7D =  20  MHz on DLMC_REF_CLK*
                                                                                 0x68 =  24  MHz on DLMC_REF_CLK*
                                                                                 0x64 =  25  MHz on DLMC_REF_CLK*
                                                                                 0x60 =  26  MHz on DLMC_REF_CLK*
                                                                                 0x41 =  38.4MHz on DLMC_REF_CLK*
                                                                                 0x7D =  40  MHz on DLMC_REF_CLK*
                                                                                 0x34 =  48  MHz on DLMC_REF_CLK*
                                                                                 0x32 =  50  MHz on DLMC_REF_CLK*
                                                                                 0x30 =  52  MHz on DLMC_REF_CLK*
                                                                                 0x41 =  76.8MHz on DLMC_REF_CLK*
                                                                                 0x1A =  96  MHz on DLMC_REF_CLK*
                                                                                 0x19 =  100 MHz on DLMC_REF_CLK*
                                                                                 0x30 =  104 MHz on DLMC_REF_CLK* if REF_CLK_DIV2 = 0x1
                                                                                 0x18 =  104 MHz on DLMC_REF_CLK* if REF_CLK_DIV2 = 0x0
                                                                                 0x28 =  125 MHz on DLMC_REF_CLK*
                                                                                 0x19 =  200 MHz on DLMC_REF_CLK* */
        uint64_t ref_ssp_en            : 1;  /**< [ 39: 39](R/W) Enables reference clock to the prescaler for SuperSpeed function. This should always be
                                                                 enabled since this output clock is used to drive the UAHC suspend-mode clock during
                                                                 low-power states.

                                                                 This value can be changed only during UPHY_RST or during low-power states.
                                                                 The reference clock must be running and stable before UPHY_RST is deasserted and before
                                                                 REF_SSP_EN is asserted. */
        uint64_t ref_clk_div2          : 1;  /**< [ 38: 38](R/W) Divides the reference clock by 2 before feeding it into the REF_CLK_FSEL divider.
                                                                  The legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                      all DLMC_REF_CLK* frequencies: 0x0 is the only legal value.

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x1: if DLMC_REF_CLK* is 125MHz.

                                                                      0x0: if DLMC_REF_CLK* is another supported frequency (see list in
                                                                           MPLL_MULTIPLIER description).

                                                                  This value can be changed only during UPHY_RST.

                                                                  Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                  must all be programmed to the same frequency setting.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                all DLMC_REF_CLK* frequencies: 0x0 is the only legal value.
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                0x1: if DLMC_REF_CLK* is 125MHz.
                                                                                0x1: if DLMC_REF_CLK* is 40MHz, 76.8MHz, or 200MHz.
                                                                                0x0 or 0x1 if DLMC_REF_CLK* is 104MHz (depending on MPLL_MULTIPLIER
                                                                 setting)
                                                                                0x0: if DLMC_REF_CLK* is another supported frequency (see list in
                                                                                     MPLL_MULTIPLIER description). */
        uint64_t ref_clk_fsel          : 6;  /**< [ 37: 32](R/W) Selects the reference clock frequency for the SuperSpeed and high-speed PLL blocks.

                                                                  The legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:

                                                                      0x27 = 100  MHz on DLMC_REF_CLK*

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x07 is the only legal value.

                                                                  All other values are reserved.

                                                                  This value may only be changed during UPHY_RST.
                                                                  Note: When REF_CLK_SEL = 0x2 or 0x3, the MPLL_MULTIPLIER, REF_CLK_DIV2, and
                                                                  SSC_REF_CLK_SEL settings are used to configure the SuperSpeed reference clock
                                                                  multiplier.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                0x27 = 100  MHz on DLMC_REF_CLK*
                                                                                0x2A =  24  MHz on DLMC_REF_CLK*
                                                                                0x31 =  20  MHz on DLMC_REF_CLK*
                                                                                0x38 =  19.2MHz on DLMC_REF_CLK*
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                0x07 is the only legal value. */
        uint64_t reserved_31           : 1;
        uint64_t h_clk_en              : 1;  /**< [ 30: 30](R/W) Controller-clock enable. When set to 1, the controller clock is generated. This also
                                                                 enables access to UCTL registers 0x30-0xF8. */
        uint64_t h_clk_byp_sel         : 1;  /**< [ 29: 29](R/W) Select the bypass input to the controller-clock divider.
                                                                 0 = Use the divided coprocessor clock from the H_CLKDIV divider.
                                                                 1 = Use the bypass clock from the GPIO pins.

                                                                 This signal is just a multiplexer-select signal; it does not enable the controller clock.
                                                                 You must still set H_CLKDIV_EN separately. H_CLK_BYP_SEL select should not be changed
                                                                 unless H_CLKDIV_EN is disabled.

                                                                 The bypass clock can be selected and running even if the controller-clock dividers are not
                                                                 running.
                                                                 INTERNAL: Generally bypass is only used for scan purposes. */
        uint64_t h_clkdiv_rst          : 1;  /**< [ 28: 28](R/W) Controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
        uint64_t reserved_27           : 1;
        uint64_t h_clkdiv_sel          : 3;  /**< [ 26: 24](R/W) Controller clock-frequency-divider select. The controller-clock frequency is the
                                                                 coprocessor-clock frequency divided by H_CLKDIV_SEL and must be at or below 300 MHz.
                                                                 The divider values are the following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 4.
                                                                 0x3 = divide by 6.
                                                                 0x4 = divide by 8.
                                                                 0x5 = divide by 16.
                                                                 0x6 = divide by 24.
                                                                 0x7 = divide by 32.

                                                                 The hclk frequency must be at or below 300MHz.
                                                                 The hclk frequency must be at or above 150MHz for full-rate USB3
                                                                 operation.
                                                                 The hclk frequency must be at or above 125MHz for any USB3
                                                                 functionality.

                                                                 If DRD_MODE = DEVICE, the hclk frequency must be at or above 125MHz for
                                                                 correct USB2 functionality.

                                                                 If DRD_MODE = HOST, the hclk frequency must be at or above 90MHz
                                                                 for full-rate USB2 operation.

                                                                 If DRD_MODE = HOST, the hclk frequency must be at or above 62.5MHz
                                                                 for any USB2 operation.

                                                                 This field can be changed only when H_CLKDIV_RST = 1.

                                                                 INTERNAL: 150MHz is from the maximum of:
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-16, row 1, col 12.
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-17, row 7, col 9.
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-16, row 7, col 9.
                                                                           DEVICE>125MHz is from Synopsys DWC_usb3 Databook v2.80a, section A.12.4.
                                                                           HOST2>62.5MHz in HOST mode is from Synopsys DWC_usb3 Databook v2.80a,
                                                                             section A.12.5, 3rd bullet in Note on page 894.
                                                                           HOST2>90MHz was arrived at from some math: 62.5MHz +
                                                                             (diff between row 1 and 2, col 12 of table A-16). */
        uint64_t reserved_22_23        : 2;
        uint64_t usb3_port_perm_attach : 1;  /**< [ 21: 21](R/W) Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
        uint64_t usb2_port_perm_attach : 1;  /**< [ 20: 20](R/W) Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
        uint64_t reserved_19           : 1;
        uint64_t usb3_port_disable     : 1;  /**< [ 18: 18](R/W) Disables the USB3 (SuperSpeed) portion of this PHY. When set to 1, this signal stops
                                                                 reporting connect/disconnect events on the port and keeps the port in disabled state. This
                                                                 could be used for security reasons where hardware can disable a port regardless of whether
                                                                 xHCI driver enables a port or not.
                                                                 USBDRD()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should be modified only when UPHY_RST is asserted. */
        uint64_t reserved_17           : 1;
        uint64_t usb2_port_disable     : 1;  /**< [ 16: 16](R/W) Disables USB2 (high-speed/full-speed/low-speed) portion of this PHY. When set to 1, this
                                                                 signal stops reporting connect/disconnect events on the port and keeps the port in
                                                                 disabled state. This could be used for security reasons where hardware can disable a port
                                                                 regardless of whether xHCI driver enables a port or not.
                                                                 USBDRD()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted.
                                                                 If Port0 is required to be disabled, ensure that the utmi_clk[0] is running at the normal
                                                                 speed. Also, all the enabled USB2.0 ports should have the same clock frequency as Port0. */
        uint64_t reserved_15           : 1;
        uint64_t ss_power_en           : 1;  /**< [ 14: 14](R/W) PHY SuperSpeed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
        uint64_t reserved_13           : 1;
        uint64_t hs_power_en           : 1;  /**< [ 12: 12](R/W) PHY high-speed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
        uint64_t reserved_5_11         : 7;
        uint64_t csclk_en              : 1;  /**< [  4:  4](R/W) Turns on the USB UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 and UCTL registers starting from 0x30. */
        uint64_t drd_mode              : 1;  /**< [  3:  3](R/W) Switches between Host or Device mode for USBDRD.
                                                                  0 = Host.
                                                                  1 = Device. */
        uint64_t uphy_rst              : 1;  /**< [  2:  2](R/W) PHY reset; resets UPHY; active-high. */
        uint64_t uahc_rst              : 1;  /**< [  1:  1](R/W) Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
        uint64_t uctl_rst              : 1;  /**< [  0:  0](R/W) Software reset; resets UCTL; active-high.
                                                                 Resets UAHC DMA and register shims. Resets UCTL registers 0x30-0xF8.
                                                                 Does not reset UCTL registers 0x0-0x28.
                                                                 UCTL registers starting from 0x30 can be accessed only after the controller clock is
                                                                 active and UCTL_RST is deasserted.
                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and CIB protocols. */
#else /* Word 0 - Little Endian */
        uint64_t uctl_rst              : 1;  /**< [  0:  0](R/W) Software reset; resets UCTL; active-high.
                                                                 Resets UAHC DMA and register shims. Resets UCTL registers 0x30-0xF8.
                                                                 Does not reset UCTL registers 0x0-0x28.
                                                                 UCTL registers starting from 0x30 can be accessed only after the controller clock is
                                                                 active and UCTL_RST is deasserted.
                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and CIB protocols. */
        uint64_t uahc_rst              : 1;  /**< [  1:  1](R/W) Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
        uint64_t uphy_rst              : 1;  /**< [  2:  2](R/W) PHY reset; resets UPHY; active-high. */
        uint64_t drd_mode              : 1;  /**< [  3:  3](R/W) Switches between Host or Device mode for USBDRD.
                                                                  0 = Host.
                                                                  1 = Device. */
        uint64_t csclk_en              : 1;  /**< [  4:  4](R/W) Turns on the USB UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 and UCTL registers starting from 0x30. */
        uint64_t reserved_5_11         : 7;
        uint64_t hs_power_en           : 1;  /**< [ 12: 12](R/W) PHY high-speed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
        uint64_t reserved_13           : 1;
        uint64_t ss_power_en           : 1;  /**< [ 14: 14](R/W) PHY SuperSpeed block power enable.
                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted. */
        uint64_t reserved_15           : 1;
        uint64_t usb2_port_disable     : 1;  /**< [ 16: 16](R/W) Disables USB2 (high-speed/full-speed/low-speed) portion of this PHY. When set to 1, this
                                                                 signal stops reporting connect/disconnect events on the port and keeps the port in
                                                                 disabled state. This could be used for security reasons where hardware can disable a port
                                                                 regardless of whether xHCI driver enables a port or not.
                                                                 USBDRD()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should only be modified when UPHY_RST is asserted.
                                                                 If Port0 is required to be disabled, ensure that the utmi_clk[0] is running at the normal
                                                                 speed. Also, all the enabled USB2.0 ports should have the same clock frequency as Port0. */
        uint64_t reserved_17           : 1;
        uint64_t usb3_port_disable     : 1;  /**< [ 18: 18](R/W) Disables the USB3 (SuperSpeed) portion of this PHY. When set to 1, this signal stops
                                                                 reporting connect/disconnect events on the port and keeps the port in disabled state. This
                                                                 could be used for security reasons where hardware can disable a port regardless of whether
                                                                 xHCI driver enables a port or not.
                                                                 USBDRD()_UAHC_HCSPARAMS1[MAXPORTS] is not affected by this signal.

                                                                 This is a strap signal; it should be modified only when UPHY_RST is asserted. */
        uint64_t reserved_19           : 1;
        uint64_t usb2_port_perm_attach : 1;  /**< [ 20: 20](R/W) Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
        uint64_t usb3_port_perm_attach : 1;  /**< [ 21: 21](R/W) Indicates this port is permanently attached. This is a strap signal; it should be modified
                                                                 only when UPHY_RST is asserted. */
        uint64_t reserved_22_23        : 2;
        uint64_t h_clkdiv_sel          : 3;  /**< [ 26: 24](R/W) Controller clock-frequency-divider select. The controller-clock frequency is the
                                                                 coprocessor-clock frequency divided by H_CLKDIV_SEL and must be at or below 300 MHz.
                                                                 The divider values are the following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 4.
                                                                 0x3 = divide by 6.
                                                                 0x4 = divide by 8.
                                                                 0x5 = divide by 16.
                                                                 0x6 = divide by 24.
                                                                 0x7 = divide by 32.

                                                                 The hclk frequency must be at or below 300MHz.
                                                                 The hclk frequency must be at or above 150MHz for full-rate USB3
                                                                 operation.
                                                                 The hclk frequency must be at or above 125MHz for any USB3
                                                                 functionality.

                                                                 If DRD_MODE = DEVICE, the hclk frequency must be at or above 125MHz for
                                                                 correct USB2 functionality.

                                                                 If DRD_MODE = HOST, the hclk frequency must be at or above 90MHz
                                                                 for full-rate USB2 operation.

                                                                 If DRD_MODE = HOST, the hclk frequency must be at or above 62.5MHz
                                                                 for any USB2 operation.

                                                                 This field can be changed only when H_CLKDIV_RST = 1.

                                                                 INTERNAL: 150MHz is from the maximum of:
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-16, row 1, col 12.
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-17, row 7, col 9.
                                                                             Synopsys DWC_usb3 Databook v2.80a, table A-16, row 7, col 9.
                                                                           DEVICE>125MHz is from Synopsys DWC_usb3 Databook v2.80a, section A.12.4.
                                                                           HOST2>62.5MHz in HOST mode is from Synopsys DWC_usb3 Databook v2.80a,
                                                                             section A.12.5, 3rd bullet in Note on page 894.
                                                                           HOST2>90MHz was arrived at from some math: 62.5MHz +
                                                                             (diff between row 1 and 2, col 12 of table A-16). */
        uint64_t reserved_27           : 1;
        uint64_t h_clkdiv_rst          : 1;  /**< [ 28: 28](R/W) Controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
        uint64_t h_clk_byp_sel         : 1;  /**< [ 29: 29](R/W) Select the bypass input to the controller-clock divider.
                                                                 0 = Use the divided coprocessor clock from the H_CLKDIV divider.
                                                                 1 = Use the bypass clock from the GPIO pins.

                                                                 This signal is just a multiplexer-select signal; it does not enable the controller clock.
                                                                 You must still set H_CLKDIV_EN separately. H_CLK_BYP_SEL select should not be changed
                                                                 unless H_CLKDIV_EN is disabled.

                                                                 The bypass clock can be selected and running even if the controller-clock dividers are not
                                                                 running.
                                                                 INTERNAL: Generally bypass is only used for scan purposes. */
        uint64_t h_clk_en              : 1;  /**< [ 30: 30](R/W) Controller-clock enable. When set to 1, the controller clock is generated. This also
                                                                 enables access to UCTL registers 0x30-0xF8. */
        uint64_t reserved_31           : 1;
        uint64_t ref_clk_fsel          : 6;  /**< [ 37: 32](R/W) Selects the reference clock frequency for the SuperSpeed and high-speed PLL blocks.

                                                                  The legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:

                                                                      0x27 = 100  MHz on DLMC_REF_CLK*

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x07 is the only legal value.

                                                                  All other values are reserved.

                                                                  This value may only be changed during UPHY_RST.
                                                                  Note: When REF_CLK_SEL = 0x2 or 0x3, the MPLL_MULTIPLIER, REF_CLK_DIV2, and
                                                                  SSC_REF_CLK_SEL settings are used to configure the SuperSpeed reference clock
                                                                  multiplier.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                0x27 = 100  MHz on DLMC_REF_CLK*
                                                                                0x2A =  24  MHz on DLMC_REF_CLK*
                                                                                0x31 =  20  MHz on DLMC_REF_CLK*
                                                                                0x38 =  19.2MHz on DLMC_REF_CLK*
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                0x07 is the only legal value. */
        uint64_t ref_clk_div2          : 1;  /**< [ 38: 38](R/W) Divides the reference clock by 2 before feeding it into the REF_CLK_FSEL divider.
                                                                  The legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                      all DLMC_REF_CLK* frequencies: 0x0 is the only legal value.

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x1: if DLMC_REF_CLK* is 125MHz.

                                                                      0x0: if DLMC_REF_CLK* is another supported frequency (see list in
                                                                           MPLL_MULTIPLIER description).

                                                                  This value can be changed only during UPHY_RST.

                                                                  Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                  must all be programmed to the same frequency setting.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                all DLMC_REF_CLK* frequencies: 0x0 is the only legal value.
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                0x1: if DLMC_REF_CLK* is 125MHz.
                                                                                0x1: if DLMC_REF_CLK* is 40MHz, 76.8MHz, or 200MHz.
                                                                                0x0 or 0x1 if DLMC_REF_CLK* is 104MHz (depending on MPLL_MULTIPLIER
                                                                 setting)
                                                                                0x0: if DLMC_REF_CLK* is another supported frequency (see list in
                                                                                     MPLL_MULTIPLIER description). */
        uint64_t ref_ssp_en            : 1;  /**< [ 39: 39](R/W) Enables reference clock to the prescaler for SuperSpeed function. This should always be
                                                                 enabled since this output clock is used to drive the UAHC suspend-mode clock during
                                                                 low-power states.

                                                                 This value can be changed only during UPHY_RST or during low-power states.
                                                                 The reference clock must be running and stable before UPHY_RST is deasserted and before
                                                                 REF_SSP_EN is asserted. */
        uint64_t mpll_multiplier       : 7;  /**< [ 46: 40](R/W) Multiplies the reference clock to a frequency suitable for intended operating speed. The
                                                                  legal values are:

                                                                    If REF_CLK_SEL = 0x0 or 0x1, then:

                                                                      0x19 = 100  MHz on DLMC_REF_CLK*

                                                                    If REF_CLK_SEL = 0x2 or 0x3, then:

                                                                      0x32 =  50  MHz on DLMC_REF_CLK*
                                                                      0x19 =  100 MHz on DLMC_REF_CLK*
                                                                      0x28 =  125 MHz on DLMC_REF_CLK*

                                                                  All other values are reserved.

                                                                  This value may only be changed during UPHY_RST.

                                                                  Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                  must all be programmed to the same frequency setting.
                                                                    INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                                 0x19 = 100  MHz on DLMC_REF_CLK*
                                                                                 0x68 =  24  MHz on DLMC_REF_CLK*
                                                                                 0x7D =  20  MHz on DLMC_REF_CLK*
                                                                                 0x02 =  19.2MHz on DLMC_REF_CLK*
                                                                              If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                                 0x02 =  19.2MHz on DLMC_REF_CLK*
                                                                                 0x7D =  20  MHz on DLMC_REF_CLK*
                                                                                 0x68 =  24  MHz on DLMC_REF_CLK*
                                                                                 0x64 =  25  MHz on DLMC_REF_CLK*
                                                                                 0x60 =  26  MHz on DLMC_REF_CLK*
                                                                                 0x41 =  38.4MHz on DLMC_REF_CLK*
                                                                                 0x7D =  40  MHz on DLMC_REF_CLK*
                                                                                 0x34 =  48  MHz on DLMC_REF_CLK*
                                                                                 0x32 =  50  MHz on DLMC_REF_CLK*
                                                                                 0x30 =  52  MHz on DLMC_REF_CLK*
                                                                                 0x41 =  76.8MHz on DLMC_REF_CLK*
                                                                                 0x1A =  96  MHz on DLMC_REF_CLK*
                                                                                 0x19 =  100 MHz on DLMC_REF_CLK*
                                                                                 0x30 =  104 MHz on DLMC_REF_CLK* if REF_CLK_DIV2 = 0x1
                                                                                 0x18 =  104 MHz on DLMC_REF_CLK* if REF_CLK_DIV2 = 0x0
                                                                                 0x28 =  125 MHz on DLMC_REF_CLK*
                                                                                 0x19 =  200 MHz on DLMC_REF_CLK* */
        uint64_t ssc_ref_clk_sel       : 9;  /**< [ 55: 47](R/W) Enables non-standard oscillator frequencies to generate targeted MPLL output rates. Input
                                                                 corresponds to the frequency-synthesis coefficient.

                                                                 [55:53]: modulus - 1,
                                                                 [52:47]: 2's complement push amount
                                                                 A value of 0x0 means this feature is disabled.
                                                                 The legal values are:
                                                                   If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                     0x0 is the only legal value.
                                                                   If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                     0x0:   if DLMC_REF_CLK* is another supported frequency (see list in
                                                                            MPLL_MULTIPLIER description).
                                                                 All other values are reserved.

                                                                 This value may only be changed during UPHY_RST.

                                                                 Note: If REF_CLK_SEL = 0x2 or 0x3, then MPLL_MULTPLIER, REF_CLK_DIV2, and SSC_REF_CLK_SEL
                                                                 must all be programmed to the same frequency setting.
                                                                   INTERNAL: If REF_CLK_SEL = 0x0 or 0x1, then:
                                                                               0x0 is the only legal value.
                                                                             If REF_CLK_SEL = 0x2 or 0x3, then:
                                                                               0x108: if DLMC_REF_CLK* is 19.2MHz, 24MHz, 26MHz, 38.4MHz, 48MHz,
                                                                                                 52MHz, 76.8MHz, 96MHz, 104MHz.
                                                                               0x0:   if DLMC_REF_CLK* is another supported frequency (see list in
                                                                                      MPLL_MULTIPLIER description). */
        uint64_t ssc_range             : 3;  /**< [ 58: 56](R/W) Spread-spectrum clock range. Selects the range of spread-spectrum modulation when SSC_EN
                                                                 is asserted and the PHY is spreading the SuperSpeed transmit clocks.
                                                                 Applies a fixed offset to the phase accumulator.
                                                                 0x0 = -4980 ppm downspread of clock.
                                                                 0x1 = -4492 ppm.
                                                                 0x2 = -4003 ppm.
                                                                 0x3-0x7 = reserved.

                                                                 All of these settings are within the USB 3.0 specification. The amount of EMI emission
                                                                 reduction might decrease as the SSC_RANGE increases; therefore, the SSC_RANGE settings can
                                                                 be registered to enable the amount of spreading to be adjusted on a per-application basis.
                                                                 This value can be changed only during UPHY_RST. */
        uint64_t ssc_en                : 1;  /**< [ 59: 59](R/W) Spread-spectrum clock enable. Enables spread-spectrum clock production in the SuperSpeed
                                                                 function. If the input reference clock for the SuperSpeed PLL is already spread-spectrum,
                                                                 then do not enable this feature. The clocks sourced to the SuperSpeed function must have
                                                                 spread-spectrum to be compliant with the USB specification.
                                                                 The high-speed PLL cannot support a spread-spectrum input, so REF_CLK_SEL = 0x0 must
                                                                 enable this feature.
                                                                 This value may only be changed during UPHY_RST. */
        uint64_t ref_clk_sel           : 2;  /**< [ 61: 60](R/W) Reference clock select. Choose reference-clock source for the SuperSpeed and high-speed
                                                                 PLL blocks.
                                                                 0x0 = Reference clock source for both PLLs come from the USB pads.
                                                                 0x1 = Reserved.
                                                                 0x2 = Reserved.
                                                                 0x3 = Reserved.

                                                                 This value can be changed only during UPHY_RST.

                                                                 If REF_CLK_SEL = 0x0, then the reference clock input cannot be spread-spectrum.

                                                                 INTERNAL: For the 0x1 selection, reference clock source for SuperSpeed PLL is from the USB
                                                                 pads, reference clock source for HighSpeed PLL is PLL_REF_CLK. But in 78xx, PLL_REF_CLK
                                                                 cannot be routed to USB without violating jitter requirements */
        uint64_t start_bist            : 1;  /**< [ 62: 62](R/W) Rising edge starts BIST on the memories in USBDRD.
                                                                 To run BIST, the controller clock must be both configured and enabled, and should be
                                                                 configured to the maximum available frequency given the available coprocessor clock and
                                                                 dividers.
                                                                 Also, the UCTL, UAHC, and UPHY should be held in software- initiated reset (using
                                                                 UPHY_RST, UAHC_RST, UCTL_RST) until BIST is complete.
                                                                 BIST defect status can be checked after FULL BIST completion, both of which are indicated
                                                                 in USBDRD()_UCTL_BIST_STATUS. The full BIST run takes almost 80,000 controller-clock
                                                                 cycles
                                                                 for
                                                                 the largest RAM. */
        uint64_t clear_bist            : 1;  /**< [ 63: 63](R/W) BIST fast-clear mode select. A BIST run with this bit set clears all entries in USBDRD
                                                                 RAMs
                                                                 to 0x0.

                                                                 There are two major modes of BIST: full and clear. Full BIST is run by the BIST state
                                                                 machine when CLEAR_BIST is deasserted during BIST. Clear BIST is run if CLEAR_BIST is
                                                                 asserted during BIST.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts the
                                                                 CLEAR_BIST setting into the correct state and then perform another CSR write operation to
                                                                 set the BIST trigger (keeping the CLEAR_BIST state constant).
                                                                 CLEAR BIST completion is indicated by USBDRD()_UCTL_BIST_STATUS. A BIST clear operation
                                                                 takes almost 2,000 controller-clock cycles for the largest RAM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_ctl_s cn; */
} bdk_usbdrdx_uctl_ctl_t;

static inline uint64_t BDK_USBDRDX_UCTL_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100000ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100000ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_CTL(a) bdk_usbdrdx_uctl_ctl_t
#define bustype_BDK_USBDRDX_UCTL_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_CTL(a) "USBDRDX_UCTL_CTL"
#define device_bar_BDK_USBDRDX_UCTL_CTL(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_CTL(a) (a)
#define arguments_BDK_USBDRDX_UCTL_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_ecc
 *
 * UCTL ECC Control Register
 * This register can be used to disable ECC correction, insert ECC errors, and debug ECC
 * failures.
 * * The ECC_ERR* fields are captured when there are no outstanding ECC errors indicated in
 * INTSTAT and a new ECC error arrives. Prioritization for multiple events occurring on the same
 * cycle is indicated by the ECC_ERR_SOURCE enumeration: highest encoded value has highest
 * priority.
 * * The *ECC_*_DIS fields disable ECC correction; SBE and DBE errors are still reported. If
 * *ECC_*_DIS = 0x1, then no data-correction occurs.
 * * The *ECC_FLIP_SYND fields flip the syndrome<1:0> bits to generate single-bit/double-bit
 * error for testing.
 *
 * 0x0 = normal operation.
 * 0x1 = SBE on bit[0].
 * 0x2 = SBE on bit[1].
 * 0x3 = DBE on bit[1:0].
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_ecc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t ecc_err_source        : 4;  /**< [ 59: 56](RO/H) Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
        uint64_t ecc_err_syndrome      : 8;  /**< [ 55: 48](RO/H) Syndrome bits of the ECC error. */
        uint64_t ecc_err_address       : 16; /**< [ 47: 32](RO/H) RAM address of the ECC error. */
        uint64_t reserved_21_31        : 11;
        uint64_t uctl_xm_r_ecc_flip_synd : 2;/**< [ 20: 19](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_r_ecc_cor_dis : 1;  /**< [ 18: 18](R/W) Enables ECC correction on UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_ecc_flip_synd : 2;/**< [ 17: 16](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_w_ecc_cor_dis : 1;  /**< [ 15: 15](R/W) Enables ECC correction on UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_9_14         : 6;
        uint64_t uahc_ram2_ecc_flip_synd : 2;/**< [  8:  7](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_ram2_ecc_cor_dis : 1;  /**< [  6:  6](R/W) Enables ECC correction on UAHC RxFIFO RAMs (RAM2). */
        uint64_t uahc_ram1_ecc_flip_synd : 2;/**< [  5:  4](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_ram1_ecc_cor_dis : 1;  /**< [  3:  3](R/W) Enables ECC correction on UAHC TxFIFO RAMs (RAM1). */
        uint64_t uahc_ram0_ecc_flip_synd : 2;/**< [  2:  1](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_ram0_ecc_cor_dis : 1;  /**< [  0:  0](R/W) Enables ECC correction on UAHC Desc/Reg cache (RAM0). */
#else /* Word 0 - Little Endian */
        uint64_t uahc_ram0_ecc_cor_dis : 1;  /**< [  0:  0](R/W) Enables ECC correction on UAHC Desc/Reg cache (RAM0). */
        uint64_t uahc_ram0_ecc_flip_synd : 2;/**< [  2:  1](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_ram1_ecc_cor_dis : 1;  /**< [  3:  3](R/W) Enables ECC correction on UAHC TxFIFO RAMs (RAM1). */
        uint64_t uahc_ram1_ecc_flip_synd : 2;/**< [  5:  4](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_ram2_ecc_cor_dis : 1;  /**< [  6:  6](R/W) Enables ECC correction on UAHC RxFIFO RAMs (RAM2). */
        uint64_t uahc_ram2_ecc_flip_synd : 2;/**< [  8:  7](R/W) Insert ECC error for testing purposes. */
        uint64_t reserved_9_14         : 6;
        uint64_t uctl_xm_w_ecc_cor_dis : 1;  /**< [ 15: 15](R/W) Enables ECC correction on UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_w_ecc_flip_synd : 2;/**< [ 17: 16](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_r_ecc_cor_dis : 1;  /**< [ 18: 18](R/W) Enables ECC correction on UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_r_ecc_flip_synd : 2;/**< [ 20: 19](R/W) Insert ECC error for testing purposes. */
        uint64_t reserved_21_31        : 11;
        uint64_t ecc_err_address       : 16; /**< [ 47: 32](RO/H) RAM address of the ECC error. */
        uint64_t ecc_err_syndrome      : 8;  /**< [ 55: 48](RO/H) Syndrome bits of the ECC error. */
        uint64_t ecc_err_source        : 4;  /**< [ 59: 56](RO/H) Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_ecc_s cn; */
} bdk_usbdrdx_uctl_ecc_t;

static inline uint64_t BDK_USBDRDX_UCTL_ECC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_ECC(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680001000f0ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680001000f0ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_ECC", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_ECC(a) bdk_usbdrdx_uctl_ecc_t
#define bustype_BDK_USBDRDX_UCTL_ECC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_ECC(a) "USBDRDX_UCTL_ECC"
#define device_bar_BDK_USBDRDX_UCTL_ECC(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_ECC(a) (a)
#define arguments_BDK_USBDRDX_UCTL_ECC(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_host_cfg
 *
 * UCTL Host Controller Configuration Register
 * This register allows configuration of various host controller (UAHC) features. Most of these
 * are strap signals and should be modified only while the controller is not running.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_host_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_60_63        : 4;
        uint64_t host_current_belt     : 12; /**< [ 59: 48](RO) This signal indicates the minimum value of all received BELT values and the BELT that is
                                                                 set by the Set LTV command. */
        uint64_t reserved_38_47        : 10;
        uint64_t fla                   : 6;  /**< [ 37: 32](R/W) High-speed jitter adjustment. Indicates the correction required to accommodate mac3 clock
                                                                 and utmi clock jitter to measure 125us duration. With FLA tied to 0x0, the high-speed
                                                                 125us micro-frame is counted for 123933ns. The value needs to be programmed in terms of
                                                                 high-speed bit times in a 30 MHz cycle. Default value that needs to be driven is 0x20
                                                                 (assuming 30 MHz perfect clock).

                                                                 FLA connects to the FLADJ register defined in the xHCI spec in the PCI configuration
                                                                 space. Each count is equal to 16 high-speed bit times. By default when this register is
                                                                 set to 0x20, it gives 125us interval. Now, based on the clock accuracy, you can decrement
                                                                 the count or increment the count to get the 125 us uSOF window.
                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t reserved_29_31        : 3;
        uint64_t bme                   : 1;  /**< [ 28: 28](R/W) Bus-master enable. This signal is used to disable the bus-mastering capability of the
                                                                 host. Disabling this capability stalls DMA accesses. */
        uint64_t oci_en                : 1;  /**< [ 27: 27](R/W) Overcurrent-indication enable. When enabled, OCI input to UAHC is taken from the GPIO
                                                                 signals and sense-converted based on OCI_ACTIVE_HIGH_EN. The MIO GPIO multiplexer must be
                                                                 programmed accordingly.

                                                                 When disabled, OCI input to UAHC is forced to the correct inactive state based on
                                                                 OCI_ACTIVE_HIGH_EN.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t oci_active_high_en    : 1;  /**< [ 26: 26](R/W) Overcurrent sense selection. The off-chip sense (high/low) is converted to match the
                                                                 controller's active-high sense.
                                                                 0 = Overcurrent indication from off-chip source is active-low.
                                                                 1 = Overcurrent indication from off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t ppc_en                : 1;  /**< [ 25: 25](R/W) Port-power-control enable.
                                                                 0 = USBDRD()_UAHC_HCCPARAMS[PPC] report port-power-control feature is unavailable.
                                                                 1 = USBDRD()_UAHC_HCCPARAMS[PPC] reports port-power-control feature is available. PPC
                                                                 output
                                                                 from UAHC is taken to the GPIO signals and sense-converted based on PPC_ACTIVE_HIGH_EN.

                                                                 The MIO GPIO multiplexer must be programmed accordingly.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
        uint64_t ppc_active_high_en    : 1;  /**< [ 24: 24](R/W) Port power control sense selection. The active-high port-power-control output to off-chip
                                                                 source is converted to match the off-chip sense.
                                                                 0 = Port-power control to off-chip source is active-low.
                                                                 1 = Port-power control to off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
        uint64_t reserved_0_23         : 24;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_23         : 24;
        uint64_t ppc_active_high_en    : 1;  /**< [ 24: 24](R/W) Port power control sense selection. The active-high port-power-control output to off-chip
                                                                 source is converted to match the off-chip sense.
                                                                 0 = Port-power control to off-chip source is active-low.
                                                                 1 = Port-power control to off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
        uint64_t ppc_en                : 1;  /**< [ 25: 25](R/W) Port-power-control enable.
                                                                 0 = USBDRD()_UAHC_HCCPARAMS[PPC] report port-power-control feature is unavailable.
                                                                 1 = USBDRD()_UAHC_HCCPARAMS[PPC] reports port-power-control feature is available. PPC
                                                                 output
                                                                 from UAHC is taken to the GPIO signals and sense-converted based on PPC_ACTIVE_HIGH_EN.

                                                                 The MIO GPIO multiplexer must be programmed accordingly.

                                                                 This is a strap signal; it should only be modified when either the UCTL_CTL[UAHC] or
                                                                 UAHC_GCTL[CoreSoftReset] is asserted. */
        uint64_t oci_active_high_en    : 1;  /**< [ 26: 26](R/W) Overcurrent sense selection. The off-chip sense (high/low) is converted to match the
                                                                 controller's active-high sense.
                                                                 0 = Overcurrent indication from off-chip source is active-low.
                                                                 1 = Overcurrent indication from off-chip source is active-high.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t oci_en                : 1;  /**< [ 27: 27](R/W) Overcurrent-indication enable. When enabled, OCI input to UAHC is taken from the GPIO
                                                                 signals and sense-converted based on OCI_ACTIVE_HIGH_EN. The MIO GPIO multiplexer must be
                                                                 programmed accordingly.

                                                                 When disabled, OCI input to UAHC is forced to the correct inactive state based on
                                                                 OCI_ACTIVE_HIGH_EN.

                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t bme                   : 1;  /**< [ 28: 28](R/W) Bus-master enable. This signal is used to disable the bus-mastering capability of the
                                                                 host. Disabling this capability stalls DMA accesses. */
        uint64_t reserved_29_31        : 3;
        uint64_t fla                   : 6;  /**< [ 37: 32](R/W) High-speed jitter adjustment. Indicates the correction required to accommodate mac3 clock
                                                                 and utmi clock jitter to measure 125us duration. With FLA tied to 0x0, the high-speed
                                                                 125us micro-frame is counted for 123933ns. The value needs to be programmed in terms of
                                                                 high-speed bit times in a 30 MHz cycle. Default value that needs to be driven is 0x20
                                                                 (assuming 30 MHz perfect clock).

                                                                 FLA connects to the FLADJ register defined in the xHCI spec in the PCI configuration
                                                                 space. Each count is equal to 16 high-speed bit times. By default when this register is
                                                                 set to 0x20, it gives 125us interval. Now, based on the clock accuracy, you can decrement
                                                                 the count or increment the count to get the 125 us uSOF window.
                                                                 This is a strap signal; it should only be modified when UAHC is in reset (soft-reset
                                                                 okay). */
        uint64_t reserved_38_47        : 10;
        uint64_t host_current_belt     : 12; /**< [ 59: 48](RO) This signal indicates the minimum value of all received BELT values and the BELT that is
                                                                 set by the Set LTV command. */
        uint64_t reserved_60_63        : 4;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_host_cfg_s cn; */
} bdk_usbdrdx_uctl_host_cfg_t;

static inline uint64_t BDK_USBDRDX_UCTL_HOST_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_HOST_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680001000e0ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680001000e0ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_HOST_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_HOST_CFG(a) bdk_usbdrdx_uctl_host_cfg_t
#define bustype_BDK_USBDRDX_UCTL_HOST_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_HOST_CFG(a) "USBDRDX_UCTL_HOST_CFG"
#define device_bar_BDK_USBDRDX_UCTL_HOST_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_HOST_CFG(a) (a)
#define arguments_BDK_USBDRDX_UCTL_HOST_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_intena_w1c
 *
 * UCTL Interrupt Status Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_intena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t reserved_8_15         : 8;
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t reserved_3_5          : 3;
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t reserved_3_5          : 3;
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t reserved_8_15         : 8;
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1C/H) Reads or clears enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_intena_w1c_s cn; */
} bdk_usbdrdx_uctl_intena_w1c_t;

static inline uint64_t BDK_USBDRDX_UCTL_INTENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_INTENA_W1C(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100040ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100040ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_INTENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_INTENA_W1C(a) bdk_usbdrdx_uctl_intena_w1c_t
#define bustype_BDK_USBDRDX_UCTL_INTENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_INTENA_W1C(a) "USBDRDX_UCTL_INTENA_W1C"
#define device_bar_BDK_USBDRDX_UCTL_INTENA_W1C(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_INTENA_W1C(a) (a)
#define arguments_BDK_USBDRDX_UCTL_INTENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_intena_w1s
 *
 * UCTL Interrupt Status Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_intena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t reserved_8_15         : 8;
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t reserved_3_5          : 3;
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t reserved_3_5          : 3;
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t reserved_8_15         : 8;
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets enable for USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_intena_w1s_s cn; */
} bdk_usbdrdx_uctl_intena_w1s_t;

static inline uint64_t BDK_USBDRDX_UCTL_INTENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_INTENA_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100048ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100048ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_INTENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_INTENA_W1S(a) bdk_usbdrdx_uctl_intena_w1s_t
#define bustype_BDK_USBDRDX_UCTL_INTENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_INTENA_W1S(a) "USBDRDX_UCTL_INTENA_W1S"
#define device_bar_BDK_USBDRDX_UCTL_INTENA_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_INTENA_W1S(a) (a)
#define arguments_BDK_USBDRDX_UCTL_INTENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_intstat
 *
 * UCTL Interrupt Status Register
 * This register provides a summary of interrupts. DBEs are detected and
 * SBE are corrected. For debugging output for ECC DBEs/SBEs, see USBDRD()_UCTL_ECC. This
 * register can be reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_intstat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1C/H) Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1C/H) Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_22_25        : 4;
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1C/H) Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1C/H) Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1C/H) Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1C/H) Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1C/H) Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1C/H) Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
        uint64_t reserved_8_15         : 8;
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Received DMA read response error from NCBO */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Received DMA write response error from NCBO */
        uint64_t reserved_3_5          : 3;
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1C/H) Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBDRD()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBDRD()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1C/H) Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBDRD()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1C/H) Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. Error information is logged in USBDRD()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1C/H) Detected bad DMA access from UAHC to NCB. Error information is logged in
                                                                 USBDRD()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates the
                                                                 assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see the description in
                                                                 USBDRD()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE]. The hardware does not translate the request
                                                                 correctly
                                                                 and results may violate NCB protocols. */
        uint64_t reserved_3_5          : 3;
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Received DMA write response error from NCBO */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Received DMA read response error from NCBO */
        uint64_t reserved_8_15         : 8;
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1C/H) Detected single-bit error on the UAHC Desc/Reg Cache (RAM0). */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1C/H) Detected double-bit error on the UAHC Desc/Reg Cache (RAM0). */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1C/H) Detected single-bit error on the UAHC TxFIFO RAMs (RAM1). */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1C/H) Detected double-bit error on the UAHC TxFIFO RAMs (RAM1). */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1C/H) Detected single-bit error on the UAHC RxFIFO RAMs (RAM2). */
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1C/H) Detected double-bit error on the UAHC RxFIFO RAMs (RAM2). */
        uint64_t reserved_22_25        : 4;
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1C/H) Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1C/H) Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1C/H) Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1C/H) Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_intstat_s cn; */
} bdk_usbdrdx_uctl_intstat_t;

static inline uint64_t BDK_USBDRDX_UCTL_INTSTAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_INTSTAT(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100030ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100030ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_INTSTAT", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_INTSTAT(a) bdk_usbdrdx_uctl_intstat_t
#define bustype_BDK_USBDRDX_UCTL_INTSTAT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_INTSTAT(a) "USBDRDX_UCTL_INTSTAT"
#define device_bar_BDK_USBDRDX_UCTL_INTSTAT(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_INTSTAT(a) (a)
#define arguments_BDK_USBDRDX_UCTL_INTSTAT(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_intstat_w1s
 *
 * UCTL Interrupt Status Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_intstat_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_30_63        : 34;
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t reserved_8_15         : 8;
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t reserved_3_5          : 3;
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t xs_ncb_oob            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  2:  2](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t reserved_3_5          : 3;
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t reserved_8_15         : 8;
        uint64_t ram0_sbe              : 1;  /**< [ 16: 16](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM0_SBE]. */
        uint64_t ram0_dbe              : 1;  /**< [ 17: 17](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM0_DBE]. */
        uint64_t ram1_sbe              : 1;  /**< [ 18: 18](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM1_SBE]. */
        uint64_t ram1_dbe              : 1;  /**< [ 19: 19](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM1_DBE]. */
        uint64_t ram2_sbe              : 1;  /**< [ 20: 20](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM2_SBE]. */
        uint64_t ram2_dbe              : 1;  /**< [ 21: 21](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[RAM2_DBE]. */
        uint64_t reserved_22_25        : 4;
        uint64_t xm_w_sbe              : 1;  /**< [ 26: 26](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [ 27: 27](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [ 28: 28](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [ 29: 29](R/W1S/H) Reads or sets USBDRD(0..1)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t reserved_30_63        : 34;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_intstat_w1s_s cn; */
} bdk_usbdrdx_uctl_intstat_w1s_t;

static inline uint64_t BDK_USBDRDX_UCTL_INTSTAT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_INTSTAT_W1S(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100038ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100038ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_INTSTAT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) bdk_usbdrdx_uctl_intstat_w1s_t
#define bustype_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) "USBDRDX_UCTL_INTSTAT_W1S"
#define device_bar_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) (a)
#define arguments_BDK_USBDRDX_UCTL_INTSTAT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_port#_cfg_hs
 *
 * UCTL Port Configuration HighSpeed Register
 * This register controls configuration and test controls for the HS port 0 PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset.
 *
 * Internal:
 * INTERNAL: All these settings are for HS functionality, connect on DVDD power domain.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_portx_cfg_hs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_58_63        : 6;
        uint64_t comp_dis_tune         : 3;  /**< [ 57: 55](R/W) Disconnect threshold voltage. Adjusts the voltage level for the threshold used to detect a
                                                                 disconnect event at the host.
                                                                 A positive binary bit setting change results in a +1.5% incremental change in the
                                                                 threshold voltage level, while a negative binary bit setting change results in a -1.5%
                                                                 incremental change in the threshold voltage level. */
        uint64_t sq_rx_tune            : 3;  /**< [ 54: 52](R/W) Squelch threshold adjustment. Adjusts the voltage level for the threshold used to detect
                                                                 valid high-speed data.
                                                                 A positive binary bit setting change results in a -5% incremental change in threshold
                                                                 voltage level, while a negative binary bit setting change results in a +5% incremental
                                                                 change in threshold voltage level. */
        uint64_t tx_fsls_tune          : 4;  /**< [ 51: 48](R/W) Low-speed/full-speed source impedance adjustment. Adjusts the low- and full-speed single-
                                                                 ended source impedance while driving high. This parameter control is encoded in
                                                                 thermometer code.
                                                                 A positive thermometer code change results in a -2.5% incremental change in source
                                                                 impedance. A negative thermometer code change results in +2.5% incremental change in
                                                                 source impedance. Any non-thermometer code setting (that is, 0x9) is not supported and
                                                                 reserved. */
        uint64_t reserved_46_47        : 2;
        uint64_t tx_hs_xv_tune         : 2;  /**< [ 45: 44](R/W) Transmitter high-speed crossover adjustment. This bus adjusts the voltage at which the DP0
                                                                 and DM0 signals cross while transmitting in high-speed mode.
                                                                 0x3 = default setting.
                                                                 0x2 = +15 mV.
                                                                 0x1 = -15 mV.
                                                                 0x0 = reserved. */
        uint64_t tx_preemp_amp_tune    : 2;  /**< [ 43: 42](R/W) High-speed transmitter pre-emphasis current control. Controls the amount of current
                                                                 sourced to DP0 and DM0 after a J-to-K or K-to-J transition. The high-speed transmitter
                                                                 preemphasis current is defined in terms of unit amounts. One unit amount is approximately
                                                                 600 A and is defined as 1* preemphasis current.
                                                                 0x0 = High-speed TX preemphasis is disabled.
                                                                 0x1 = High-speed TX preemphasis circuit sources 1* preemphasis current.
                                                                 0x2 = High-speed TX preemphasis circuit sources 2* preemphasis current.
                                                                 0x3 = High-speed TX preemphasis circuit sources 3* preemphasis current.

                                                                 If these signals are not used, set them to 0x0. */
        uint64_t reserved_41           : 1;
        uint64_t tx_preemp_pulse_tune  : 1;  /**< [ 40: 40](R/W) High-speed transmitter preemphasis duration control. Controls the duration for which the
                                                                 high-speed preemphasis current is sourced onto DP0 or DM0. The high-speed transmitter
                                                                 preemphasis duration is defined in terms of unit amounts. One unit of preemphasis duration
                                                                 is approximately 580 ps and is defined as 1* preemphasis duration. This signal is valid
                                                                 only if either TX_PREEMP_AMP_TUNE0[1] or TX_PREEMP_AMP_TUNE0[0] is set to 1.
                                                                 0 = 2*, long preemphasis current duration (design default).
                                                                 1 = 1*, short preemphasis current duration.

                                                                 If this signal is not used, set it to 0. */
        uint64_t tx_res_tune           : 2;  /**< [ 39: 38](R/W) USB source-impedance adjustment. Some applications require additional devices to be added
                                                                 on the USB, such as a series switch, which can add significant series resistance. This bus
                                                                 adjusts the driver source impedance to compensate for added series resistance on the USB.
                                                                 0x0 = source impedance is decreased by approximately 1.5 ohm.
                                                                 0x1 = design default.
                                                                 0x2 = source impedance is decreased by approximately 2 ohm.
                                                                 0x3 = source impedance is decreased by approximately 4 ohm.

                                                                 Any setting other than the default can result in source-impedance variation across
                                                                 process, voltage, and temperature conditions that does not meet USB 2.0 specification
                                                                 limits. If this bus is not used, leave it at the default setting. */
        uint64_t tx_rise_tune          : 2;  /**< [ 37: 36](R/W) High-speed transmitter rise-/fall-time adjustment. Adjusts the rise/fall times of the
                                                                 high-speed waveform. A positive binary bit setting change results in a -4% incremental
                                                                 change in the high-speed rise/fall time. A negative binary bit setting change results in a
                                                                 +4% incremental change in the high-speed rise/fall time. */
        uint64_t tx_vref_tune          : 4;  /**< [ 35: 32](R/W) High-speed DC voltage-level adjustment. Adjusts the high-speed DC level voltage.
                                                                 A positive binary-bit-setting change results in a +1.25% incremental change in high-speed
                                                                 DC voltage level, while a negative binary-bit-setting change results in a -1.25%
                                                                 incremental change in high-speed DC voltage level.

                                                                 The default bit setting is intended to create a HighSpeed transmit
                                                                 DC level of approximately 400mV. */
        uint64_t reserved_7_31         : 25;
        uint64_t otgtune               : 3;  /**< [  6:  4](R/W) "VBUS Valid Threshold Adjustment.
                                                                 This bus adjusts the voltage level for the VBUS<#>
                                                                 valid threshold. To enable tuning at the board level, connect this
                                                                 bus to a register.
                                                                 Note: A positive binary bit setting change results in a +3%
                                                                 incremental change in threshold voltage level, while a negative
                                                                 binary bit setting change results in a -3% incremental change
                                                                 in threshold voltage level. " */
        uint64_t vatest_enable         : 2;  /**< [  3:  2](R/W) Analog test-pin select. Enables analog test voltages to be placed on the ID0 pin.
                                                                 0x0 = test functionality disabled.
                                                                 0x1 = test functionality enabled.
                                                                 0x2, 0x3 = reserved, invalid settings.

                                                                 See also the PHY databook for details on how to select which analog test voltage. */
        uint64_t loopback_enable       : 1;  /**< [  1:  1](R/W) Places the high-speed PHY in loopback mode, which concurrently enables high-speed receive
                                                                 and transmit logic. */
        uint64_t atereset              : 1;  /**< [  0:  0](R/W) Per-PHY ATE reset. When the USB core is powered up (not in suspend mode), an automatic
                                                                 tester can use this to disable PHYCLOCK and FREECLK, then re-enable them with an aligned
                                                                 phase.
                                                                 0 = PHYCLOCK and FREECLK are available within a specific period after ATERESET is
                                                                 deasserted.
                                                                 1 = PHYCLOCK and FREECLK outputs are disabled. */
#else /* Word 0 - Little Endian */
        uint64_t atereset              : 1;  /**< [  0:  0](R/W) Per-PHY ATE reset. When the USB core is powered up (not in suspend mode), an automatic
                                                                 tester can use this to disable PHYCLOCK and FREECLK, then re-enable them with an aligned
                                                                 phase.
                                                                 0 = PHYCLOCK and FREECLK are available within a specific period after ATERESET is
                                                                 deasserted.
                                                                 1 = PHYCLOCK and FREECLK outputs are disabled. */
        uint64_t loopback_enable       : 1;  /**< [  1:  1](R/W) Places the high-speed PHY in loopback mode, which concurrently enables high-speed receive
                                                                 and transmit logic. */
        uint64_t vatest_enable         : 2;  /**< [  3:  2](R/W) Analog test-pin select. Enables analog test voltages to be placed on the ID0 pin.
                                                                 0x0 = test functionality disabled.
                                                                 0x1 = test functionality enabled.
                                                                 0x2, 0x3 = reserved, invalid settings.

                                                                 See also the PHY databook for details on how to select which analog test voltage. */
        uint64_t otgtune               : 3;  /**< [  6:  4](R/W) "VBUS Valid Threshold Adjustment.
                                                                 This bus adjusts the voltage level for the VBUS<#>
                                                                 valid threshold. To enable tuning at the board level, connect this
                                                                 bus to a register.
                                                                 Note: A positive binary bit setting change results in a +3%
                                                                 incremental change in threshold voltage level, while a negative
                                                                 binary bit setting change results in a -3% incremental change
                                                                 in threshold voltage level. " */
        uint64_t reserved_7_31         : 25;
        uint64_t tx_vref_tune          : 4;  /**< [ 35: 32](R/W) High-speed DC voltage-level adjustment. Adjusts the high-speed DC level voltage.
                                                                 A positive binary-bit-setting change results in a +1.25% incremental change in high-speed
                                                                 DC voltage level, while a negative binary-bit-setting change results in a -1.25%
                                                                 incremental change in high-speed DC voltage level.

                                                                 The default bit setting is intended to create a HighSpeed transmit
                                                                 DC level of approximately 400mV. */
        uint64_t tx_rise_tune          : 2;  /**< [ 37: 36](R/W) High-speed transmitter rise-/fall-time adjustment. Adjusts the rise/fall times of the
                                                                 high-speed waveform. A positive binary bit setting change results in a -4% incremental
                                                                 change in the high-speed rise/fall time. A negative binary bit setting change results in a
                                                                 +4% incremental change in the high-speed rise/fall time. */
        uint64_t tx_res_tune           : 2;  /**< [ 39: 38](R/W) USB source-impedance adjustment. Some applications require additional devices to be added
                                                                 on the USB, such as a series switch, which can add significant series resistance. This bus
                                                                 adjusts the driver source impedance to compensate for added series resistance on the USB.
                                                                 0x0 = source impedance is decreased by approximately 1.5 ohm.
                                                                 0x1 = design default.
                                                                 0x2 = source impedance is decreased by approximately 2 ohm.
                                                                 0x3 = source impedance is decreased by approximately 4 ohm.

                                                                 Any setting other than the default can result in source-impedance variation across
                                                                 process, voltage, and temperature conditions that does not meet USB 2.0 specification
                                                                 limits. If this bus is not used, leave it at the default setting. */
        uint64_t tx_preemp_pulse_tune  : 1;  /**< [ 40: 40](R/W) High-speed transmitter preemphasis duration control. Controls the duration for which the
                                                                 high-speed preemphasis current is sourced onto DP0 or DM0. The high-speed transmitter
                                                                 preemphasis duration is defined in terms of unit amounts. One unit of preemphasis duration
                                                                 is approximately 580 ps and is defined as 1* preemphasis duration. This signal is valid
                                                                 only if either TX_PREEMP_AMP_TUNE0[1] or TX_PREEMP_AMP_TUNE0[0] is set to 1.
                                                                 0 = 2*, long preemphasis current duration (design default).
                                                                 1 = 1*, short preemphasis current duration.

                                                                 If this signal is not used, set it to 0. */
        uint64_t reserved_41           : 1;
        uint64_t tx_preemp_amp_tune    : 2;  /**< [ 43: 42](R/W) High-speed transmitter pre-emphasis current control. Controls the amount of current
                                                                 sourced to DP0 and DM0 after a J-to-K or K-to-J transition. The high-speed transmitter
                                                                 preemphasis current is defined in terms of unit amounts. One unit amount is approximately
                                                                 600 A and is defined as 1* preemphasis current.
                                                                 0x0 = High-speed TX preemphasis is disabled.
                                                                 0x1 = High-speed TX preemphasis circuit sources 1* preemphasis current.
                                                                 0x2 = High-speed TX preemphasis circuit sources 2* preemphasis current.
                                                                 0x3 = High-speed TX preemphasis circuit sources 3* preemphasis current.

                                                                 If these signals are not used, set them to 0x0. */
        uint64_t tx_hs_xv_tune         : 2;  /**< [ 45: 44](R/W) Transmitter high-speed crossover adjustment. This bus adjusts the voltage at which the DP0
                                                                 and DM0 signals cross while transmitting in high-speed mode.
                                                                 0x3 = default setting.
                                                                 0x2 = +15 mV.
                                                                 0x1 = -15 mV.
                                                                 0x0 = reserved. */
        uint64_t reserved_46_47        : 2;
        uint64_t tx_fsls_tune          : 4;  /**< [ 51: 48](R/W) Low-speed/full-speed source impedance adjustment. Adjusts the low- and full-speed single-
                                                                 ended source impedance while driving high. This parameter control is encoded in
                                                                 thermometer code.
                                                                 A positive thermometer code change results in a -2.5% incremental change in source
                                                                 impedance. A negative thermometer code change results in +2.5% incremental change in
                                                                 source impedance. Any non-thermometer code setting (that is, 0x9) is not supported and
                                                                 reserved. */
        uint64_t sq_rx_tune            : 3;  /**< [ 54: 52](R/W) Squelch threshold adjustment. Adjusts the voltage level for the threshold used to detect
                                                                 valid high-speed data.
                                                                 A positive binary bit setting change results in a -5% incremental change in threshold
                                                                 voltage level, while a negative binary bit setting change results in a +5% incremental
                                                                 change in threshold voltage level. */
        uint64_t comp_dis_tune         : 3;  /**< [ 57: 55](R/W) Disconnect threshold voltage. Adjusts the voltage level for the threshold used to detect a
                                                                 disconnect event at the host.
                                                                 A positive binary bit setting change results in a +1.5% incremental change in the
                                                                 threshold voltage level, while a negative binary bit setting change results in a -1.5%
                                                                 incremental change in the threshold voltage level. */
        uint64_t reserved_58_63        : 6;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_portx_cfg_hs_s cn; */
} bdk_usbdrdx_uctl_portx_cfg_hs_t;

static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CFG_HS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CFG_HS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000100050ll + 0x1000000000ll * ((a) & 0x1) + 0x20ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000100050ll + 0x1000000000ll * ((a) & 0x1) + 0x20ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UCTL_PORTX_CFG_HS", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) bdk_usbdrdx_uctl_portx_cfg_hs_t
#define bustype_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) "USBDRDX_UCTL_PORTX_CFG_HS"
#define device_bar_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) (a)
#define arguments_BDK_USBDRDX_UCTL_PORTX_CFG_HS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uctl_port#_cfg_ss
 *
 * UCTL Port Configuration SuperSpeed Register
 * This register controls configuration and test controls for the SS port 0 PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 *
 * INTERNAL: All these settings are for high-speed functionality, connect on DVDD power domain.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_portx_cfg_ss_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t tx_vboost_lvl         : 3;  /**< [ 63: 61](R/W) TX voltage-boost level. Sets the boosted transmit launch amplitude (mVppd). The default
                                                                 bit setting is intended to set the launch amplitude to approximately 1,008 mVppd. A
                                                                 single, positive binary bit setting change results in a +156 mVppd change in the TX launch
                                                                 amplitude.
                                                                 A single, negative binary bit setting change results in a -156 mVppd change in the TX
                                                                 launch amplitude. All settings more than one binary bit change should not be used.
                                                                 0x3 = 0.844 V launch amplitude.
                                                                 0x4 = 1.008 V launch amplitude.
                                                                 0x5 = 1.156 V launch amplitude.
                                                                 All others values are invalid. */
        uint64_t los_bias              : 3;  /**< [ 60: 58](R/W) Loss-of-signal detector threshold-level control. A positive, binary bit setting change
                                                                 results in a +15 mVp incremental change in the LOS threshold.
                                                                 A negative binary bit setting change results in a -15 mVp incremental change in the LOS
                                                                 threshold. The 0x0 setting is reserved and must not be used. The default 0x5 setting
                                                                 corresponds to approximately 105 mVp.
                                                                 0x0 = invalid.
                                                                 0x1 = 45 mV.
                                                                 0x2 = 60 mV.
                                                                 0x3 = 75 mV.
                                                                 0x4 = 90 mV.
                                                                 0x5 = 105 mV (default).
                                                                 0x6 = 120 mV.
                                                                 0x7 = 135 mV. */
        uint64_t lane0_ext_pclk_req    : 1;  /**< [ 57: 57](R/W) When asserted, this signal enables the pipe0_pclk output regardless of power state (along
                                                                 with the associated increase in power consumption). You can use this input to enable
                                                                 pipe0_pclk in the P3 state without going through a complete boot sequence. */
        uint64_t lane0_tx2rx_loopbk    : 1;  /**< [ 56: 56](R/W) When asserted, data from TX predriver is looped back to RX slicers. LOS is bypassed and
                                                                 based on the tx0_en input so that rx0_los = !tx_data_en. */
        uint64_t reserved_42_55        : 14;
        uint64_t pcs_rx_los_mask_val   : 10; /**< [ 41: 32](R/W) Configurable loss-of-signal mask width. Sets the number of reference clock cycles to mask
                                                                 the incoming LFPS in U3 and U2 states. Masks the incoming LFPS for the number of reference
                                                                 clock cycles equal to the value of pcs_rx_los_mask_val<9:0>. This control filters out
                                                                 short, non-compliant LFPS glitches sent by a noncompliant host.

                                                                 For normal operation, set to a targeted mask interval of 10us (value = 10us / Tref_clk).
                                                                 If the USBDRD()_UCTL_CTL[REF_CLK_DIV2] is used, then
                                                                 (value = 10us / (2 * Tref_clk)). These equations are based on the SuperSpeed reference
                                                                 clock frequency. The value of PCS_RX_LOS_MASK_VAL should be as follows:

                                                                 <pre>
                                                                      Frequency   DIV2  LOS_MASK
                                                                      ---------    ---  --------
                                                                      200   MHz      1     0x3E8
                                                                      125   MHz      0     0x4E2
                                                                      104   MHz      0     0x410
                                                                      100   MHz      0     0x3E8
                                                                       96   MHz      0     0x3C0
                                                                       76.8 MHz      1     0x180
                                                                       52   MHz      0     0x208
                                                                       50   MHz      0     0x1F4
                                                                       48   MHz      0     0x1E0
                                                                       40   MHz      1     0x0C8
                                                                       38.4 MHz      0     0x180
                                                                       26   MHz      0     0x104
                                                                       25   MHz      0     0x0FA
                                                                       24   MHz      0     0x0F0
                                                                       20   MHz      0     0x0C8
                                                                       19.2 MHz      0     0x0C0
                                                                 </pre>

                                                                 Setting this bus to 0x0 disables masking. The value should be defined when the PHY is in
                                                                 reset. Changing this value during operation might disrupt normal operation of the link. */
        uint64_t pcs_tx_deemph_3p5db   : 6;  /**< [ 31: 26](R/W) Fine-tune transmitter driver deemphasis when set to 3.5db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x1 (according to the PIPE3 specification). The values for transmit deemphasis are derived
                                                                 from the following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t pcs_tx_deemph_6db     : 6;  /**< [ 25: 20](R/W) Fine-tune transmitter driver deemphasis when set to 6db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x2 (according to the PIPE3 specification). This bus is provided for completeness and as a
                                                                 second potential launch amplitude. The values for transmit deemphasis are derived from the
                                                                 following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t pcs_tx_swing_full     : 7;  /**< [ 19: 13](R/W) Launch amplitude of the transmitter. Sets the launch amplitude of the transmitter. The
                                                                 values for transmit amplitude are derived from the following equation:
                                                                 TX amplitude (V) = vptx * ((pcs_tx_swing_full + 1)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t lane0_tx_term_offset  : 5;  /**< [ 12:  8](R/W) Transmitter termination offset. Reserved, set to 0x0. */
        uint64_t reserved_6_7          : 2;
        uint64_t res_tune_ack          : 1;  /**< [  5:  5](RO/H) Resistor tune acknowledge. While asserted, indicates a resistor tune is in progress. */
        uint64_t res_tune_req          : 1;  /**< [  4:  4](R/W) Resistor tune request. The rising edge triggers a resistor tune request (if one is not
                                                                 already in progress). When asserted, RES_TUNE_ACK is asserted high until calibration of
                                                                 the termination impedance is complete.
                                                                 Tuning disrupts the normal flow of data; therefore, assert RES_TUNE_REQ only when the PHY
                                                                 is inactive. The PHY automatically performs a tune when coming out of PRST. */
        uint64_t reserved_0_3          : 4;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_3          : 4;
        uint64_t res_tune_req          : 1;  /**< [  4:  4](R/W) Resistor tune request. The rising edge triggers a resistor tune request (if one is not
                                                                 already in progress). When asserted, RES_TUNE_ACK is asserted high until calibration of
                                                                 the termination impedance is complete.
                                                                 Tuning disrupts the normal flow of data; therefore, assert RES_TUNE_REQ only when the PHY
                                                                 is inactive. The PHY automatically performs a tune when coming out of PRST. */
        uint64_t res_tune_ack          : 1;  /**< [  5:  5](RO/H) Resistor tune acknowledge. While asserted, indicates a resistor tune is in progress. */
        uint64_t reserved_6_7          : 2;
        uint64_t lane0_tx_term_offset  : 5;  /**< [ 12:  8](R/W) Transmitter termination offset. Reserved, set to 0x0. */
        uint64_t pcs_tx_swing_full     : 7;  /**< [ 19: 13](R/W) Launch amplitude of the transmitter. Sets the launch amplitude of the transmitter. The
                                                                 values for transmit amplitude are derived from the following equation:
                                                                 TX amplitude (V) = vptx * ((pcs_tx_swing_full + 1)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t pcs_tx_deemph_6db     : 6;  /**< [ 25: 20](R/W) Fine-tune transmitter driver deemphasis when set to 6db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x2 (according to the PIPE3 specification). This bus is provided for completeness and as a
                                                                 second potential launch amplitude. The values for transmit deemphasis are derived from the
                                                                 following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t pcs_tx_deemph_3p5db   : 6;  /**< [ 31: 26](R/W) Fine-tune transmitter driver deemphasis when set to 3.5db.
                                                                 This static value sets the TX driver deemphasis value when pipeP_tx_deemph[1:0] is set to
                                                                 0x1 (according to the PIPE3 specification). The values for transmit deemphasis are derived
                                                                 from the following equation:

                                                                 _ TX de-emphasis (db) = 20 * log_base_10((128 - 2 * pcs_tx_deemph)/128)

                                                                 In general, the parameter controls are static signals to be set prior to taking the PHY
                                                                 out of reset. However, you can dynamically change these values on-the-fly for test
                                                                 purposes. In this case, changes to the transmitter to reflect the current value occur only
                                                                 after the pipeP_tx_deemph[1:0] input changes.
                                                                 INTERNAL: Default value is package dependant. */
        uint64_t pcs_rx_los_mask_val   : 10; /**< [ 41: 32](R/W) Configurable loss-of-signal mask width. Sets the number of reference clock cycles to mask
                                                                 the incoming LFPS in U3 and U2 states. Masks the incoming LFPS for the number of reference
                                                                 clock cycles equal to the value of pcs_rx_los_mask_val<9:0>. This control filters out
                                                                 short, non-compliant LFPS glitches sent by a noncompliant host.

                                                                 For normal operation, set to a targeted mask interval of 10us (value = 10us / Tref_clk).
                                                                 If the USBDRD()_UCTL_CTL[REF_CLK_DIV2] is used, then
                                                                 (value = 10us / (2 * Tref_clk)). These equations are based on the SuperSpeed reference
                                                                 clock frequency. The value of PCS_RX_LOS_MASK_VAL should be as follows:

                                                                 <pre>
                                                                      Frequency   DIV2  LOS_MASK
                                                                      ---------    ---  --------
                                                                      200   MHz      1     0x3E8
                                                                      125   MHz      0     0x4E2
                                                                      104   MHz      0     0x410
                                                                      100   MHz      0     0x3E8
                                                                       96   MHz      0     0x3C0
                                                                       76.8 MHz      1     0x180
                                                                       52   MHz      0     0x208
                                                                       50   MHz      0     0x1F4
                                                                       48   MHz      0     0x1E0
                                                                       40   MHz      1     0x0C8
                                                                       38.4 MHz      0     0x180
                                                                       26   MHz      0     0x104
                                                                       25   MHz      0     0x0FA
                                                                       24   MHz      0     0x0F0
                                                                       20   MHz      0     0x0C8
                                                                       19.2 MHz      0     0x0C0
                                                                 </pre>

                                                                 Setting this bus to 0x0 disables masking. The value should be defined when the PHY is in
                                                                 reset. Changing this value during operation might disrupt normal operation of the link. */
        uint64_t reserved_42_55        : 14;
        uint64_t lane0_tx2rx_loopbk    : 1;  /**< [ 56: 56](R/W) When asserted, data from TX predriver is looped back to RX slicers. LOS is bypassed and
                                                                 based on the tx0_en input so that rx0_los = !tx_data_en. */
        uint64_t lane0_ext_pclk_req    : 1;  /**< [ 57: 57](R/W) When asserted, this signal enables the pipe0_pclk output regardless of power state (along
                                                                 with the associated increase in power consumption). You can use this input to enable
                                                                 pipe0_pclk in the P3 state without going through a complete boot sequence. */
        uint64_t los_bias              : 3;  /**< [ 60: 58](R/W) Loss-of-signal detector threshold-level control. A positive, binary bit setting change
                                                                 results in a +15 mVp incremental change in the LOS threshold.
                                                                 A negative binary bit setting change results in a -15 mVp incremental change in the LOS
                                                                 threshold. The 0x0 setting is reserved and must not be used. The default 0x5 setting
                                                                 corresponds to approximately 105 mVp.
                                                                 0x0 = invalid.
                                                                 0x1 = 45 mV.
                                                                 0x2 = 60 mV.
                                                                 0x3 = 75 mV.
                                                                 0x4 = 90 mV.
                                                                 0x5 = 105 mV (default).
                                                                 0x6 = 120 mV.
                                                                 0x7 = 135 mV. */
        uint64_t tx_vboost_lvl         : 3;  /**< [ 63: 61](R/W) TX voltage-boost level. Sets the boosted transmit launch amplitude (mVppd). The default
                                                                 bit setting is intended to set the launch amplitude to approximately 1,008 mVppd. A
                                                                 single, positive binary bit setting change results in a +156 mVppd change in the TX launch
                                                                 amplitude.
                                                                 A single, negative binary bit setting change results in a -156 mVppd change in the TX
                                                                 launch amplitude. All settings more than one binary bit change should not be used.
                                                                 0x3 = 0.844 V launch amplitude.
                                                                 0x4 = 1.008 V launch amplitude.
                                                                 0x5 = 1.156 V launch amplitude.
                                                                 All others values are invalid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_portx_cfg_ss_s cn; */
} bdk_usbdrdx_uctl_portx_cfg_ss_t;

static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CFG_SS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CFG_SS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000100058ll + 0x1000000000ll * ((a) & 0x1) + 0x20ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000100058ll + 0x1000000000ll * ((a) & 0x1) + 0x20ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UCTL_PORTX_CFG_SS", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) bdk_usbdrdx_uctl_portx_cfg_ss_t
#define bustype_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) "USBDRDX_UCTL_PORTX_CFG_SS"
#define device_bar_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) (a)
#define arguments_BDK_USBDRDX_UCTL_PORTX_CFG_SS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uctl_port#_cr_dbg_cfg
 *
 * UCTL Port Debug Configuration Register
 * This register allows indirect access to the configuration and test controls for the port 0
 * PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 *
 * INTERNAL: (In body of HRM)
 * To access the PHY registers indirectly through the CR interface, the HCLK must be running,
 * UCTL_RST must be deasserted, and UPHY_RST must be deasserted. Software is responsible for
 * ensuring that only one indirect access is ongoing at a time.
 *
 * To read a PHY register via indirect CR interface:
 *   1. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the <<address>> of the register,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   2. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the <<address>> of the register,
 *     * [CAP_ADDR] field 0x1,
 *     * [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   3. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   4. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   5. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   6. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [READ] field 0x1,
 *     * [DATA_IN], [CAP_ADDR], [CAP_DATA], and [WRITE] fields 0x0.
 *   7. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   8. Read UCTL_PORTn_CR_DBG_STATUS[DATA_OUT]. This is the <<read data>>.
 *   9. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   10. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *
 * To write a PHY register via indirect CR interface:
 *   1. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the <<address>> of the register,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   2. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the <<address>> of the register,
 *     * [CAP_ADDR] field 0x1,
 *     * [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   3. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   4. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   5. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   6. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the <<write data>>,
 *     * [CAP_ADDR], [CAP_DATA], [READ], and [WRITE] fields 0x0.
 *   7. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [DATA_IN] with the write data,
 *     * [CAP_DATA] field 0x1,
 *     * [CAP_ADDR], [READ], and [WRITE] fields 0x0.
 *   8. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   9. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   10. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *   11. Write UCTL_PORTn_CR_DBG_CFG with:
 *     * [WRITE] field 0x1,
 *     * [DATA_IN], [CAP_ADDR], and [READ] fields 0x0.
 *   12. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x1.
 *   13. Write UCTL_PORTn_CR_DBG_CFG with all 0x0's.
 *   14. Poll for UCTL_PORTn_CR_DBG_STATUS[ACK] 0x0.
 *
 * For partial writes, a read-modify write is required. Note that the CAP_ADDR steps (1-5)
 * do not have to be repeated until the address needs changed.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_portx_cr_dbg_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t data_in               : 16; /**< [ 47: 32](R/W) Address or data to be written to the CR interface. */
        uint64_t reserved_4_31         : 28;
        uint64_t cap_addr              : 1;  /**< [  3:  3](R/W) Rising edge triggers the DATA_IN field to be captured as the address. */
        uint64_t cap_data              : 1;  /**< [  2:  2](R/W) Rising edge triggers the DATA_IN field to be captured as the write data. */
        uint64_t read                  : 1;  /**< [  1:  1](R/W) Rising edge triggers a register read operation of the captured address. */
        uint64_t write                 : 1;  /**< [  0:  0](R/W) Rising edge triggers a register write operation of the captured address with the captured data. */
#else /* Word 0 - Little Endian */
        uint64_t write                 : 1;  /**< [  0:  0](R/W) Rising edge triggers a register write operation of the captured address with the captured data. */
        uint64_t read                  : 1;  /**< [  1:  1](R/W) Rising edge triggers a register read operation of the captured address. */
        uint64_t cap_data              : 1;  /**< [  2:  2](R/W) Rising edge triggers the DATA_IN field to be captured as the write data. */
        uint64_t cap_addr              : 1;  /**< [  3:  3](R/W) Rising edge triggers the DATA_IN field to be captured as the address. */
        uint64_t reserved_4_31         : 28;
        uint64_t data_in               : 16; /**< [ 47: 32](R/W) Address or data to be written to the CR interface. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_portx_cr_dbg_cfg_s cn; */
} bdk_usbdrdx_uctl_portx_cr_dbg_cfg_t;

static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000100060ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000100060ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UCTL_PORTX_CR_DBG_CFG", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) bdk_usbdrdx_uctl_portx_cr_dbg_cfg_t
#define bustype_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) "USBDRDX_UCTL_PORTX_CR_DBG_CFG"
#define device_bar_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) (a)
#define arguments_BDK_USBDRDX_UCTL_PORTX_CR_DBG_CFG(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uctl_port#_cr_dbg_status
 *
 * UCTL Port Debug Status Register
 * This register allows indirect access to the configuration and test controls for the port 0
 * PHY.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_portx_cr_dbg_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_48_63        : 16;
        uint64_t data_out              : 16; /**< [ 47: 32](RO/H) Last data read from the CR interface. */
        uint64_t reserved_1_31         : 31;
        uint64_t ack                   : 1;  /**< [  0:  0](RO/H) Acknowledge that the CAP_ADDR, CAP_DATA, READ, WRITE commands have completed. */
#else /* Word 0 - Little Endian */
        uint64_t ack                   : 1;  /**< [  0:  0](RO/H) Acknowledge that the CAP_ADDR, CAP_DATA, READ, WRITE commands have completed. */
        uint64_t reserved_1_31         : 31;
        uint64_t data_out              : 16; /**< [ 47: 32](RO/H) Last data read from the CR interface. */
        uint64_t reserved_48_63        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_portx_cr_dbg_status_s cn; */
} bdk_usbdrdx_uctl_portx_cr_dbg_status_t;

static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && ((a<=1) && (b==0)))
        return 0x868000100068ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=1) && (b==0)))
        return 0x868000100068ll + 0x1000000000ll * ((a) & 0x1) + 0ll * ((b) & 0x0);
    __bdk_csr_fatal("USBDRDX_UCTL_PORTX_CR_DBG_STATUS", 2, a, b, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) bdk_usbdrdx_uctl_portx_cr_dbg_status_t
#define bustype_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) "USBDRDX_UCTL_PORTX_CR_DBG_STATUS"
#define device_bar_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) (a)
#define arguments_BDK_USBDRDX_UCTL_PORTX_CR_DBG_STATUS(a,b) (a),(b),-1,-1

/**
 * Register (NCB) usbdrd#_uctl_shim_cfg
 *
 * UCTL Shim Configuration Register
 * This register allows configuration of various shim (UCTL) features. The fields XS_NCB_OOB_*
 * are captured when there are no outstanding OOB errors indicated in INTSTAT and a new OOB error
 * arrives. The fields XS_BAD_DMA_* are captured when there are no outstanding DMA errors
 * indicated in INTSTAT and a new DMA error arrives.
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_shim_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t xs_ncb_oob_wrn        : 1;  /**< [ 63: 63](RO/H) Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
        uint64_t reserved_60_62        : 3;
        uint64_t xs_ncb_oob_osrc       : 12; /**< [ 59: 48](RO/H) SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 <59:58> = chipID.
                                                                 <57> = Request source: 0 = core, 1 = NCB-device.
                                                                 <56:51> = Core/NCB-device number. Note that for NCB devices, <56> is always 0.
                                                                 <50:48> = SubID. */
        uint64_t xm_bad_dma_wrn        : 1;  /**< [ 47: 47](RO/H) Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log */
        uint64_t reserved_44_46        : 3;
        uint64_t xm_bad_dma_type       : 4;  /**< [ 43: 40](RO/H) ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See UCTL_XM_BAD_DMA_TYPE_E. */
        uint64_t reserved_14_39        : 26;
        uint64_t dma_read_cmd          : 2;  /**< [ 13: 12](R/W) Selects the NCB read command used by DMA accesses. See UCTL_DMA_READ_CMD_E. */
        uint64_t reserved_11           : 1;
        uint64_t dma_write_cmd         : 1;  /**< [ 10: 10](R/W) Selects the NCB write command used by DMA accesses. See UCTL_DMA_WRITE_CMD_E. */
        uint64_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_9          : 10;
        uint64_t dma_write_cmd         : 1;  /**< [ 10: 10](R/W) Selects the NCB write command used by DMA accesses. See UCTL_DMA_WRITE_CMD_E. */
        uint64_t reserved_11           : 1;
        uint64_t dma_read_cmd          : 2;  /**< [ 13: 12](R/W) Selects the NCB read command used by DMA accesses. See UCTL_DMA_READ_CMD_E. */
        uint64_t reserved_14_39        : 26;
        uint64_t xm_bad_dma_type       : 4;  /**< [ 43: 40](RO/H) ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See UCTL_XM_BAD_DMA_TYPE_E. */
        uint64_t reserved_44_46        : 3;
        uint64_t xm_bad_dma_wrn        : 1;  /**< [ 47: 47](RO/H) Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log */
        uint64_t xs_ncb_oob_osrc       : 12; /**< [ 59: 48](RO/H) SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 <59:58> = chipID.
                                                                 <57> = Request source: 0 = core, 1 = NCB-device.
                                                                 <56:51> = Core/NCB-device number. Note that for NCB devices, <56> is always 0.
                                                                 <50:48> = SubID. */
        uint64_t reserved_60_62        : 3;
        uint64_t xs_ncb_oob_wrn        : 1;  /**< [ 63: 63](RO/H) Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_shim_cfg_s cn; */
} bdk_usbdrdx_uctl_shim_cfg_t;

static inline uint64_t BDK_USBDRDX_UCTL_SHIM_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_SHIM_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680001000e8ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680001000e8ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_SHIM_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_SHIM_CFG(a) bdk_usbdrdx_uctl_shim_cfg_t
#define bustype_BDK_USBDRDX_UCTL_SHIM_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_SHIM_CFG(a) "USBDRDX_UCTL_SHIM_CFG"
#define device_bar_BDK_USBDRDX_UCTL_SHIM_CFG(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_SHIM_CFG(a) (a)
#define arguments_BDK_USBDRDX_UCTL_SHIM_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_spare0
 *
 * INTERNAL: UCTL Spare Register 0
 *
 * This register is a spare register. This register can be reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_spare0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) INTERNAL: Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_spare0_s cn; */
} bdk_usbdrdx_uctl_spare0_t;

static inline uint64_t BDK_USBDRDX_UCTL_SPARE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_SPARE0(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x868000100010ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x868000100010ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_SPARE0", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_SPARE0(a) bdk_usbdrdx_uctl_spare0_t
#define bustype_BDK_USBDRDX_UCTL_SPARE0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_SPARE0(a) "USBDRDX_UCTL_SPARE0"
#define device_bar_BDK_USBDRDX_UCTL_SPARE0(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_SPARE0(a) (a)
#define arguments_BDK_USBDRDX_UCTL_SPARE0(a) (a),-1,-1,-1

/**
 * Register (NCB) usbdrd#_uctl_spare1
 *
 * INTERNAL: UCTL Spare Register 1
 *
 * This register is accessible only when USB()_UCTL_CTL[H_CLK_EN] = 1.
 *
 * This register can be reset by NCB reset or with USBDRD()_UCTL_CTL[UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_usbdrdx_uctl_spare1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) INTERNAL: Reserved for ECO usage. */
#else /* Word 0 - Little Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) INTERNAL: Reserved for ECO usage. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_usbdrdx_uctl_spare1_s cn; */
} bdk_usbdrdx_uctl_spare1_t;

static inline uint64_t BDK_USBDRDX_UCTL_SPARE1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_USBDRDX_UCTL_SPARE1(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x8680001000f8ll + 0x1000000000ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x8680001000f8ll + 0x1000000000ll * ((a) & 0x1);
    __bdk_csr_fatal("USBDRDX_UCTL_SPARE1", 1, a, 0, 0, 0);
}

#define typedef_BDK_USBDRDX_UCTL_SPARE1(a) bdk_usbdrdx_uctl_spare1_t
#define bustype_BDK_USBDRDX_UCTL_SPARE1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_USBDRDX_UCTL_SPARE1(a) "USBDRDX_UCTL_SPARE1"
#define device_bar_BDK_USBDRDX_UCTL_SPARE1(a) 0x0 /* PF_BAR0 */
#define busnum_BDK_USBDRDX_UCTL_SPARE1(a) (a)
#define arguments_BDK_USBDRDX_UCTL_SPARE1(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_USBDRD_H__ */

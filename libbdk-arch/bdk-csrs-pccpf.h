#ifndef __BDK_CSRS_PCCPF_H__
#define __BDK_CSRS_PCCPF_H__
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
 * Cavium PCCPF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pcc_dev_con_e
 *
 * PCC Device Connection Enumeration
 * Enumerates where the device is connected in the topology. Software must rely on discovery and
 * not use this enumeration as the values will vary by product, and the mnemonics are a super-set
 * of the devices available. The value of the enumeration is formatted as defined by
 * PCC_DEV_CON_S.
 */
#define BDK_PCC_DEV_CON_E_BCH_CN81XX (0x300) /**< BCH. */
#define BDK_PCC_DEV_CON_E_BCH_CN83XX (0x1000) /**< BCH. */
#define BDK_PCC_DEV_CON_E_BGXX(a) (0x180 + (a)) /**< Ethernet interface. */
#define BDK_PCC_DEV_CON_E_CPT0_CN81XX (0x400) /**< CPT 0. */
#define BDK_PCC_DEV_CON_E_CPT0_CN83XX (0x500) /**< CPT 0. */
#define BDK_PCC_DEV_CON_E_CPT1 (0x600) /**< CPT 1. */
#define BDK_PCC_DEV_CON_E_DAP (0x102) /**< Debug access point. */
#define BDK_PCC_DEV_CON_E_DDF0 (0x700) /**< DDF. */
#define BDK_PCC_DEV_CON_E_DFA (0x400) /**< HFA. */
#define BDK_PCC_DEV_CON_E_DPI0 (0xf00) /**< DPI 0. */
#define BDK_PCC_DEV_CON_E_FPA (0xd00) /**< FPA. */
#define BDK_PCC_DEV_CON_E_FUSF (0x104) /**< Field Fuses. */
#define BDK_PCC_DEV_CON_E_GIC (0x18) /**< GIC interrupt unit. */
#define BDK_PCC_DEV_CON_E_GPIO (0x30) /**< GPIO. */
#define BDK_PCC_DEV_CON_E_GSERX(a) (0x1e0 + (a)) /**< SerDes. */
#define BDK_PCC_DEV_CON_E_GTI (0x20) /**< Timer. */
#define BDK_PCC_DEV_CON_E_IOBNX(a) (0x158 + (a)) /**< I/O bridge. */
#define BDK_PCC_DEV_CON_E_KEY (0x10d) /**< KEY. */
#define BDK_PCC_DEV_CON_E_L2C (0x109) /**< Level 2 cache. */
#define BDK_PCC_DEV_CON_E_L2C_CBCX(a) (0x138 + (a)) /**< Level 2 cache CBC. */
#define BDK_PCC_DEV_CON_E_L2C_MCIX(a) (0x13c + (a)) /**< Level 2 cache MCI. */
#define BDK_PCC_DEV_CON_E_L2C_TADX(a) (0x130 + (a)) /**< Level 2 cache TAD. */
#define BDK_PCC_DEV_CON_E_LBKX(a) (0x168 + (a)) /**< Loopback. */
#define BDK_PCC_DEV_CON_E_LMCX(a) (0x150 + (a)) /**< LMC interface. */
#define BDK_PCC_DEV_CON_E_MIO_BOOT_CN81XX (0x10e) /**< Boot registers. */
#define BDK_PCC_DEV_CON_E_MIO_BOOT_CN88XX (0x10e) /**< Boot-bus. */
#define BDK_PCC_DEV_CON_E_MIO_BOOT_CN83XX (0x10e) /**< Boot registers. */
#define BDK_PCC_DEV_CON_E_MIO_EMM (0x10c) /**< eMMC. */
#define BDK_PCC_DEV_CON_E_MIO_FUS (0x103) /**< Fuses. */
#define BDK_PCC_DEV_CON_E_MIO_PTP (0x40) /**< Precision time-stamping. */
#define BDK_PCC_DEV_CON_E_MIO_TWSX(a) (0x148 + (a)) /**< TWSI. */
#define BDK_PCC_DEV_CON_E_MPI (0x38) /**< MPI. */
#define BDK_PCC_DEV_CON_E_MRML (0x100) /**< Master RSL bus bridge. */
#define BDK_PCC_DEV_CON_E_NCSI (0x108) /**< NC-SI interface. */
#define BDK_PCC_DEV_CON_E_NDF (0x58) /**< NAND flash. */
#define BDK_PCC_DEV_CON_E_NIC_CN81XX (0x500) /**< Network interface controller. */
#define BDK_PCC_DEV_CON_E_NIC_CN88XX (0x20100) /**< Network interface controller.  Contains 1 PF + 128 VFs. */
#define BDK_PCC_DEV_CON_E_NIC_CN83XX (0x20100) /**< Network interface controller.  Contains 1 PF + 128 VFs. */
#define BDK_PCC_DEV_CON_E_OCLAX(a) (0x160 + (a)) /**< OCLA. */
#define BDK_PCC_DEV_CON_E_OCX (0x105) /**< OCX. */
#define BDK_PCC_DEV_CON_E_PBUS (0x10f) /**< Parallel bus. */
#define BDK_PCC_DEV_CON_E_PCCBR_BCH_CN81XX (0x50) /**< Bridge for BCH, creating ECAM 0's bus 3. */
#define BDK_PCC_DEV_CON_E_PCCBR_BCH_CN83XX (0x50) /**< Bridge for BCH, creating ECAM 0's bus 16. */
#define BDK_PCC_DEV_CON_E_PCCBR_CPT0_CN81XX (0x60) /**< Bridge for CPT 0, creating ECAM 0's bus 4. */
#define BDK_PCC_DEV_CON_E_PCCBR_CPT0_CN83XX (0x60) /**< Bridge for CPT 0, creating ECAM 0's bus 5. */
#define BDK_PCC_DEV_CON_E_PCCBR_CPT1 (0x68) /**< Bridge for CPT 1, creating ECAM 0's bus 6. */
#define BDK_PCC_DEV_CON_E_PCCBR_DDF0 (0xb8) /**< Bridge for DDF0, creating ECAM 0's bus 7. */
#define BDK_PCC_DEV_CON_E_PCCBR_DFA (0xb0) /**< Bridge for DFA, creating ECAM 0's bus 4. */
#define BDK_PCC_DEV_CON_E_PCCBR_DPI0 (0xf8) /**< Bridge for DPI 0, creating ECAM 0's bus 15. */
#define BDK_PCC_DEV_CON_E_PCCBR_FPA (0xe8) /**< Bridge for FPA, creating ECAM 0's bus 13. */
#define BDK_PCC_DEV_CON_E_PCCBR_MRML (8) /**< Bridge for MRML, creating ECAM 0's bus 1. */
#define BDK_PCC_DEV_CON_E_PCCBR_NIC_CN81XX (0x78) /**< Bridge for NIC, creating ECAM 0's bus 5. */
#define BDK_PCC_DEV_CON_E_PCCBR_NIC_CN88XX (0x20010) /**< Bridge for NIC, creating ECAM 2's bus 1. */
#define BDK_PCC_DEV_CON_E_PCCBR_NIC_CN83XX (0x20010) /**< Bridge for NIC, creating ECAM 2's bus 1. */
#define BDK_PCC_DEV_CON_E_PCCBR_PCM (0xe0) /**< Bridge for PCM, creating ECAM 0's bus 12. */
#define BDK_PCC_DEV_CON_E_PCCBR_PKI (0xc0) /**< Bridge for PKI, creating ECAM 0's bus 8. */
#define BDK_PCC_DEV_CON_E_PCCBR_PKO (0xc8) /**< Bridge for PKO, creating ECAM 0's bus 9. */
#define BDK_PCC_DEV_CON_E_PCCBR_RAD (0xa0) /**< Bridge for RAD, creating ECAM 0's bus 2. */
#define BDK_PCC_DEV_CON_E_PCCBR_RNM_CN81XX (0x48) /**< Bridge for RNM, creating ECAM 0's bus 2. */
#define BDK_PCC_DEV_CON_E_PCCBR_RNM_CN83XX (0x48) /**< Bridge for RNM, creating ECAM 0's bus 4. */
#define BDK_PCC_DEV_CON_E_PCCBR_SSO (0xd0) /**< Bridge for SSO, creating ECAM 0's bus 10. */
#define BDK_PCC_DEV_CON_E_PCCBR_SSOW (0xd8) /**< Bridge for SSOW, creating ECAM 0's bus 11. */
#define BDK_PCC_DEV_CON_E_PCCBR_TIM (0xf0) /**< Bridge for TIM, creating ECAM 0's bus 14. */
#define BDK_PCC_DEV_CON_E_PCCBR_ZIP (0xa8) /**< Bridge for ZIP, creating ECAM 0's bus 3. */
#define BDK_PCC_DEV_CON_E_PCIERC0_CN81XX (0xc0) /**< PCIe endpoint 0.
                                       Internal:
                                       Note attributes represent those to create PCCBR_PCIERC. */
#define BDK_PCC_DEV_CON_E_PCIERC0_CN88XX (0x10080) /**< PCIe endpoint 0.
                                       Internal:
                                       Note attributes represent those to create PCCBR_PCIERC. */
#define BDK_PCC_DEV_CON_E_PCIERC0_CN83XX (0x10080) /**< PCIe endpoint 0.
                                       Internal:
                                       Note attributes represent those to create PCCBR_PCIERC. */
#define BDK_PCC_DEV_CON_E_PCIERC1_CN81XX (0xc8) /**< PCIe endpoint 1. */
#define BDK_PCC_DEV_CON_E_PCIERC1_CN88XX (0x10090) /**< PCIe endpoint 1. */
#define BDK_PCC_DEV_CON_E_PCIERC1_CN83XX (0x10090) /**< PCIe endpoint 1. */
#define BDK_PCC_DEV_CON_E_PCIERC2_CN81XX (0xd0) /**< PCIe endpoint 2. */
#define BDK_PCC_DEV_CON_E_PCIERC2_CN88XX (0x100a0) /**< PCIe endpoint 2. */
#define BDK_PCC_DEV_CON_E_PCIERC2_CN83XX (0x10098) /**< PCIe endpoint 2. */
#define BDK_PCC_DEV_CON_E_PCIERC3_CN88XX (0x30080) /**< PCIe endpoint 3. */
#define BDK_PCC_DEV_CON_E_PCIERC3_CN83XX (0x100a0) /**< PCIe endpoint 3. */
#define BDK_PCC_DEV_CON_E_PCIERC4 (0x30090) /**< PCIe endpoint 4. */
#define BDK_PCC_DEV_CON_E_PCIERC5 (0x300a0) /**< PCIe endpoint 5. */
#define BDK_PCC_DEV_CON_E_PCM_CN81XX (0x68) /**< PCM. */
#define BDK_PCC_DEV_CON_E_PCM_CN83XX (0xc00) /**< PCM. */
#define BDK_PCC_DEV_CON_E_PEMX(a) (0x170 + (a)) /**< PCI controller. */
#define BDK_PCC_DEV_CON_E_PKI (0x800) /**< PKI. */
#define BDK_PCC_DEV_CON_E_PKO (0x900) /**< PKO. */
#define BDK_PCC_DEV_CON_E_RAD (0x200) /**< RAID unit. */
#define BDK_PCC_DEV_CON_E_RGXX(a) (0x190 + (a)) /**< Ethernet interface. */
#define BDK_PCC_DEV_CON_E_RNM_CN81XX (0x200) /**< Random number generator. */
#define BDK_PCC_DEV_CON_E_RNM_CN88XX (0x48) /**< Random number generator. */
#define BDK_PCC_DEV_CON_E_RNM_CN83XX (0x400) /**< Random number generator. */
#define BDK_PCC_DEV_CON_E_RST (0x101) /**< Reset. */
#define BDK_PCC_DEV_CON_E_SATA0_CN81XX (0xb0) /**< SATA 0. */
#define BDK_PCC_DEV_CON_E_SATA0_CN88XX (0x10020) /**< SATA 0. */
#define BDK_PCC_DEV_CON_E_SATA0_CN83XX (0x10020) /**< SATA 0. */
#define BDK_PCC_DEV_CON_E_SATA1_CN81XX (0xb8) /**< SATA 1. */
#define BDK_PCC_DEV_CON_E_SATA1_CN88XX (0x10028) /**< SATA 1. */
#define BDK_PCC_DEV_CON_E_SATA1_CN83XX (0x10028) /**< SATA 1. */
#define BDK_PCC_DEV_CON_E_SATA10 (0x30030) /**< SATA 10. */
#define BDK_PCC_DEV_CON_E_SATA11 (0x30038) /**< SATA 11. */
#define BDK_PCC_DEV_CON_E_SATA12 (0x30040) /**< SATA 12. */
#define BDK_PCC_DEV_CON_E_SATA13 (0x30048) /**< SATA 13. */
#define BDK_PCC_DEV_CON_E_SATA14 (0x30050) /**< SATA 14. */
#define BDK_PCC_DEV_CON_E_SATA15 (0x30058) /**< SATA 15. */
#define BDK_PCC_DEV_CON_E_SATA2 (0x10030) /**< SATA 2. */
#define BDK_PCC_DEV_CON_E_SATA3 (0x10038) /**< SATA 3. */
#define BDK_PCC_DEV_CON_E_SATA4 (0x10040) /**< SATA 4. */
#define BDK_PCC_DEV_CON_E_SATA5 (0x10048) /**< SATA 5. */
#define BDK_PCC_DEV_CON_E_SATA6 (0x10050) /**< SATA 6. */
#define BDK_PCC_DEV_CON_E_SATA7 (0x10058) /**< SATA 7. */
#define BDK_PCC_DEV_CON_E_SATA8 (0x30020) /**< SATA 8. */
#define BDK_PCC_DEV_CON_E_SATA9 (0x30028) /**< SATA 9. */
#define BDK_PCC_DEV_CON_E_SGP (0x10a) /**< Serial GPIO. */
#define BDK_PCC_DEV_CON_E_SLI0_CN81XX (0x70) /**< SLI 0. */
#define BDK_PCC_DEV_CON_E_SLI0_CN88XX (0x10010) /**< SLI 0. */
#define BDK_PCC_DEV_CON_E_SLI1 (0x30010) /**< SLI 1. */
#define BDK_PCC_DEV_CON_E_SLIRE0 (0x10010) /**< SLI 0. */
#define BDK_PCC_DEV_CON_E_SMI (0x10b) /**< SMI. */
#define BDK_PCC_DEV_CON_E_SMMU0 (0x10) /**< System memory management unit. */
#define BDK_PCC_DEV_CON_E_SMMU1 (0x10008) /**< System memory management unit. */
#define BDK_PCC_DEV_CON_E_SMMU2 (0x20008) /**< System memory management unit. */
#define BDK_PCC_DEV_CON_E_SMMU3 (0x30008) /**< System memory management unit. */
#define BDK_PCC_DEV_CON_E_SSO (0xa00) /**< SSO. */
#define BDK_PCC_DEV_CON_E_SSOW (0xb00) /**< SSO work slots. */
#define BDK_PCC_DEV_CON_E_TIM (0xe00) /**< TIM. */
#define BDK_PCC_DEV_CON_E_TNS (0x20018) /**< Network switch. */
#define BDK_PCC_DEV_CON_E_UAAX(a) (0x140 + (a)) /**< UART. */
#define BDK_PCC_DEV_CON_E_USBDRDX(a) (0x80 + 8 * (a)) /**< USB interface. */
#define BDK_PCC_DEV_CON_E_USBHX(a) (0x80 + 8 * (a)) /**< USB interface. */
#define BDK_PCC_DEV_CON_E_VRMX(a) (0x144 + (a)) /**< Voltage regulator. */
#define BDK_PCC_DEV_CON_E_XCVX(a) (0x110 + (a)) /**< RGMII XCV. */
#define BDK_PCC_DEV_CON_E_ZIP (0x300) /**< ZIP. */

/**
 * Enumeration pcc_dev_idl_e
 *
 * PCC Device ID Low Enumeration
 * Enumerates the values of the PCI configuration header Device ID and Subsystem Device ID bits
 * <7:0>. The value of the enumeration is formatted as defined by PCC_DEV_IDL_S.
 */
#define BDK_PCC_DEV_IDL_E_BCH (0x43) /**< BCH. */
#define BDK_PCC_DEV_IDL_E_BCH_VF (0x44) /**< BCH. */
#define BDK_PCC_DEV_IDL_E_BGX (0x26) /**< Ethernet interface. */
#define BDK_PCC_DEV_IDL_E_CHIP (0) /**< Reserved. */
#define BDK_PCC_DEV_IDL_E_CHIP_VF_CN81XX (3) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_CHIP_VF_CN83XX (3) /**< External view of CNXXXX as endpoint VF. See PCIEEP()_CFG100[VFDEV]. */
#define BDK_PCC_DEV_IDL_E_CPT_CN81XX (0x40) /**< Cryptographic accelerator. */
#define BDK_PCC_DEV_IDL_E_CPT_CN88XX (0x40) /**< Internal:
                                       Reserved. 83xx crypto. */
#define BDK_PCC_DEV_IDL_E_CPT_CN83XX (0x40) /**< Cryptographic accelerator. */
#define BDK_PCC_DEV_IDL_E_CPT_VF_CN81XX (0x41) /**< Cryptographic accelerator SR-IOV virtual function. */
#define BDK_PCC_DEV_IDL_E_CPT_VF_CN88XX (0x41) /**< Internal:
                                       Reserved. 83xx crypto. */
#define BDK_PCC_DEV_IDL_E_CPT_VF_CN83XX (0x41) /**< Cryptographic accelerator SR-IOV virtual function. */
#define BDK_PCC_DEV_IDL_E_DAP (0x2c) /**< Debug access point. */
#define BDK_PCC_DEV_IDL_E_DDF_CN81XX (0x45) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_DDF_CN83XX (0x45) /**< Dedup. */
#define BDK_PCC_DEV_IDL_E_DDF_VF_CN81XX (0x46) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_DDF_VF_CN83XX (0x46) /**< Dedup virtual function. */
#define BDK_PCC_DEV_IDL_E_DFA_CN81XX (0x19) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_DFA_CN88XX (0x19) /**< HFA. */
#define BDK_PCC_DEV_IDL_E_DFA_CN83XX (0x19) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_DPI_CN81XX (0x57) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_DPI_CN83XX (0x57) /**< DPI. */
#define BDK_PCC_DEV_IDL_E_FPA_CN81XX (0x52) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_FPA_CN83XX (0x52) /**< Free pool allocator. */
#define BDK_PCC_DEV_IDL_E_FPA_VF_CN81XX (0x53) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_FPA_VF_CN83XX (0x53) /**< Free pool allocator virtual function. */
#define BDK_PCC_DEV_IDL_E_FUSF (0x32) /**< Field Fuses. */
#define BDK_PCC_DEV_IDL_E_GIC (9) /**< GIC Interrupt Unit. */
#define BDK_PCC_DEV_IDL_E_GPIO (0xa) /**< GPIO. */
#define BDK_PCC_DEV_IDL_E_GSER (0x25) /**< SerDes. */
#define BDK_PCC_DEV_IDL_E_GTI (0x17) /**< Timer. */
#define BDK_PCC_DEV_IDL_E_IOBN (0x27) /**< I/O Bridge. */
#define BDK_PCC_DEV_IDL_E_KEY (0x16) /**< KEY. Accessible only in secure mode. */
#define BDK_PCC_DEV_IDL_E_L2C (0x21) /**< Level 2 cache. */
#define BDK_PCC_DEV_IDL_E_L2C_CBC (0x2f) /**< Level 2 cache CBC. */
#define BDK_PCC_DEV_IDL_E_L2C_MCI (0x30) /**< Level 2 cache MCI. */
#define BDK_PCC_DEV_IDL_E_L2C_TAD (0x2e) /**< Level 2 cache TAD. */
#define BDK_PCC_DEV_IDL_E_LBK (0x42) /**< Loopback. */
#define BDK_PCC_DEV_IDL_E_LMC (0x22) /**< LMC interface. */
#define BDK_PCC_DEV_IDL_E_MIO_BOOT (0x11) /**< Boot-bus. */
#define BDK_PCC_DEV_IDL_E_MIO_EMM (0x10) /**< eMMC. */
#define BDK_PCC_DEV_IDL_E_MIO_FUS (0x31) /**< Fuses. */
#define BDK_PCC_DEV_IDL_E_MIO_PTP (0xc) /**< Precision Time-stamping. */
#define BDK_PCC_DEV_IDL_E_MIO_TWS (0x12) /**< TWSI. */
#define BDK_PCC_DEV_IDL_E_MIX (0xd) /**< MIX. */
#define BDK_PCC_DEV_IDL_E_MPI (0xb) /**< MPI. */
#define BDK_PCC_DEV_IDL_E_MRML (1) /**< Master RSL bus bridge. */
#define BDK_PCC_DEV_IDL_E_NCSI_CN81XX (0x29) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_NCSI_CN88XX (0x29) /**< NC-SI interface. */
#define BDK_PCC_DEV_IDL_E_NCSI_CN83XX (0x29) /**< NC-SI interface. */
#define BDK_PCC_DEV_IDL_E_NDF (0x4f) /**< NAND flash. */
#define BDK_PCC_DEV_IDL_E_NIC (0x1e) /**< Network interface controller. */
#define BDK_PCC_DEV_IDL_E_NIC_VF (0x34) /**< Network interface controller SR-IOV virtual function. */
#define BDK_PCC_DEV_IDL_E_OCLA (0x23) /**< OCLA. */
#define BDK_PCC_DEV_IDL_E_OCX_CN81XX (0x13) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_OCX_CN88XX (0x13) /**< OCX. */
#define BDK_PCC_DEV_IDL_E_OCX_CN83XX (0x13) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_OSM_CN81XX (0x24) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_OSM_CN88XX (0x24) /**< OSM. */
#define BDK_PCC_DEV_IDL_E_OSM_CN83XX (0x24) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_PBUS (0x35) /**< Parallel bus. */
#define BDK_PCC_DEV_IDL_E_PCCBR (2) /**< PCC Bridge. */
#define BDK_PCC_DEV_IDL_E_PCIERC (0x2d) /**< PCIe host bridge.
                                       Internal:
                                       Also used by fake PCCBR_PCIERC inside IOB. */
#define BDK_PCC_DEV_IDL_E_PCM_CN81XX (0x4e) /**< PCM interface. */
#define BDK_PCC_DEV_IDL_E_PCM_CN83XX (0x4e) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_PEM (0x20) /**< PCI controller. */
#define BDK_PCC_DEV_IDL_E_PKI_CN81XX (0x47) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_PKI_CN83XX (0x47) /**< Packet input. */
#define BDK_PCC_DEV_IDL_E_PKO_CN81XX (0x48) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_PKO_CN83XX (0x48) /**< Packet output. */
#define BDK_PCC_DEV_IDL_E_PKO_VF_CN81XX (0x49) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_PKO_VF_CN83XX (0x49) /**< Packet output. */
#define BDK_PCC_DEV_IDL_E_RAD_CN81XX (0x1d) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_RAD_CN88XX (0x1d) /**< RAID unit. */
#define BDK_PCC_DEV_IDL_E_RAD_CN83XX (0x1d) /**< RAID unit. */
#define BDK_PCC_DEV_IDL_E_RAD_VF (0x36) /**< RAID unit VF. */
#define BDK_PCC_DEV_IDL_E_RGX_CN81XX (0x54) /**< RGMII Ethernet interface. */
#define BDK_PCC_DEV_IDL_E_RGX_CN83XX (0x54) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_RNM (0x18) /**< Random number generator. */
#define BDK_PCC_DEV_IDL_E_RNM_VF (0x33) /**< Random number generator SR-IOV virtual function. */
#define BDK_PCC_DEV_IDL_E_RST (0xe) /**< Reset. */
#define BDK_PCC_DEV_IDL_E_SATA (0x1c) /**< SATA interface. */
#define BDK_PCC_DEV_IDL_E_SGP (0x2a) /**< Serial GPIO interface. */
#define BDK_PCC_DEV_IDL_E_SLI_CN81XX (0x15) /**< SLI. */
#define BDK_PCC_DEV_IDL_E_SLI_CN88XX (0x15) /**< SLI. */
#define BDK_PCC_DEV_IDL_E_SLI_CN83XX (0x15) /**< Internal:
                                       Reserved. SLI, which supports only root complex. */
#define BDK_PCC_DEV_IDL_E_SLIRE (0x38) /**< SLI, which supports both root complex and endpoint. */
#define BDK_PCC_DEV_IDL_E_SMI (0x2b) /**< SMI. */
#define BDK_PCC_DEV_IDL_E_SMMU (8) /**< System Memory Management Unit. */
#define BDK_PCC_DEV_IDL_E_SSO (0x4a) /**< SSO. */
#define BDK_PCC_DEV_IDL_E_SSOW (0x4c) /**< SSO work slots. */
#define BDK_PCC_DEV_IDL_E_SSOW_VF (0x4d) /**< SSO work slots virtual function. */
#define BDK_PCC_DEV_IDL_E_SSO_VF (0x4b) /**< SSO group virtual function. */
#define BDK_PCC_DEV_IDL_E_TIM_CN81XX (0x50) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_TIM_CN83XX (0x50) /**< Work timers. */
#define BDK_PCC_DEV_IDL_E_TIM_VF_CN81XX (0x51) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_TIM_VF_CN83XX (0x51) /**< Work timer virtual function. */
#define BDK_PCC_DEV_IDL_E_TNS_CN81XX (0x1f) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_TNS_CN88XX (0x1f) /**< Network switch. */
#define BDK_PCC_DEV_IDL_E_TNS_CN83XX (0x1f) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_UAA (0xf) /**< UART. */
#define BDK_PCC_DEV_IDL_E_USBDRD (0x55) /**< USB host and endpoint interface. */
#define BDK_PCC_DEV_IDL_E_USBH_CN81XX (0x1b) /**< Internal:
                                       Reserved. (See USBDRD instead.) */
#define BDK_PCC_DEV_IDL_E_USBH_CN88XX (0x1b) /**< USB host-only interface. */
#define BDK_PCC_DEV_IDL_E_USBH_CN83XX (0x1b) /**< Internal:
                                       Reserved. (See USBDRD instead.) */
#define BDK_PCC_DEV_IDL_E_VRM (0x14) /**< Voltage regulator. */
#define BDK_PCC_DEV_IDL_E_XCV (0x56) /**< RGMII XCV. */
#define BDK_PCC_DEV_IDL_E_ZIP_CN81XX (0x1a) /**< Internal:
                                       Reserved. */
#define BDK_PCC_DEV_IDL_E_ZIP_CN88XX (0x1a) /**< ZIP. */
#define BDK_PCC_DEV_IDL_E_ZIP_CN83XX (0x1a) /**< ZIP. */
#define BDK_PCC_DEV_IDL_E_ZIP_VF (0x37) /**< ZIP VF. */

/**
 * Enumeration pcc_pidr_partnum0_e
 *
 * PCC PIDR Part Number 0 Enumeration
 * When *_PIDR1[PARTNUM1] = PCC_PIDR_PARTNUM1_E::COMP, enumerates the values of Cavium-
 * assigned CoreSight PIDR part number 0 fields.
 * For example SMMU()_PIDR0[PARTNUM0].
 */
#define BDK_PCC_PIDR_PARTNUM0_E_CTI (0xd) /**< Cross-trigger interface. */
#define BDK_PCC_PIDR_PARTNUM0_E_DBG (0xe) /**< AP Debug. */
#define BDK_PCC_PIDR_PARTNUM0_E_GICD (2) /**< GIC distributor. */
#define BDK_PCC_PIDR_PARTNUM0_E_GICR (1) /**< GIC redistributor. */
#define BDK_PCC_PIDR_PARTNUM0_E_GITS (3) /**< GIC ITS. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_BZ (4) /**< GTI base. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_CC (5) /**< GTI counter control. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_CTL (6) /**< GTI control. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_RD (7) /**< GTI counter read. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_WC (8) /**< GTI watchdog control. */
#define BDK_PCC_PIDR_PARTNUM0_E_GTI_WR (9) /**< GTI watchdog write. */
#define BDK_PCC_PIDR_PARTNUM0_E_NONE (0) /**< Reserved. */
#define BDK_PCC_PIDR_PARTNUM0_E_PMU (0xa) /**< Performance monitors. */
#define BDK_PCC_PIDR_PARTNUM0_E_SMMU (0xb) /**< SMMU. */
#define BDK_PCC_PIDR_PARTNUM0_E_SYSCTI (0xf) /**< System CTI. */
#define BDK_PCC_PIDR_PARTNUM0_E_TRC (0x10) /**< Trace. */
#define BDK_PCC_PIDR_PARTNUM0_E_UAA (0xc) /**< UART. */

/**
 * Enumeration pcc_pidr_partnum1_e
 *
 * PCC PIDR Part Number 1 Enumeration
 * Enumerates the values of Cavium-assigned CoreSight PIDR PARTNUM1 fields, for example
 * SMMU()_PIDR1[PARTNUM1].
 */
#define BDK_PCC_PIDR_PARTNUM1_E_COMP (2) /**< This is a component inside the chip, e.g. a SMMU. *_PIDR0[PARTNUM0] is enumerated by
                                       PCC_PIDR_PARTNUM0_E. */
#define BDK_PCC_PIDR_PARTNUM1_E_PROD (1) /**< This component identifies the chip, i.e. is the CoreSight ROM. *_PIDR0[PARTNUM0] is
                                       enumerated by PCC_PROD_E. */

/**
 * Enumeration pcc_prod_e
 *
 * PCC Device ID Product Enumeration
 * Enumerates the chip identifier.
 */
#define BDK_PCC_PROD_E_CN81XX_CN81XX (0xa2) /**< Indicates CN81XX. Used in AP_MIDR_EL1[PARTNUM], and PCCPF_XXX_SUBID[SSID]<15:8>,
                                       and other identifier registers. */
#define BDK_PCC_PROD_E_CN81XX_CN88XX (0xa2) /**< Internal:
                                       Indicates CN81XX. Used in AP_MIDR_EL1[PARTNUM], and
                                       PCCPF_XXX_SUBID[SSID]<15:8>, and other identifier registers. */
#define BDK_PCC_PROD_E_CN81XX_CN83XX (0xa2) /**< Indicates CN81XX. Used in AP_MIDR_EL1[PARTNUM], and PCCPF_XXX_SUBID[SSID]<15:8>,
                                       and other identifier registers. */
#define BDK_PCC_PROD_E_CN83XX_CN81XX (0xa3) /**< Indicates CN83XX. Used in AP_MIDR_EL1[PARTNUM], and PCCPF_XXX_SUBID[SSID]<15:8>,
                                       and other identifier registers. */
#define BDK_PCC_PROD_E_CN83XX_CN88XX (0xa3) /**< Internal:
                                       Indicates CN83XX. Used in AP_MIDR_EL1[PARTNUM], and
                                       PCCPF_XXX_SUBID[SSID]<15:8>, and other identifier registers. */
#define BDK_PCC_PROD_E_CN83XX_CN83XX (0xa3) /**< Indicates CN83XX. Used in AP_MIDR_EL1[PARTNUM], and PCCPF_XXX_SUBID[SSID]<15:8>,
                                       and other identifier registers. */
#define BDK_PCC_PROD_E_CN88XX (0xa1) /**< Indicates CN88XX. Used in AP_MIDR_EL1[PARTNUM], PCCPF_XXX_SUBID[SSID]<15:8>, and
                                       other identifier registers. */
#define BDK_PCC_PROD_E_GEN (0xa0) /**< Indicates the generic ThunderX family. Used in only PCCPF_XXX_ID[DEVID]<15:8>. */

/**
 * Enumeration pcc_vendor_e
 *
 * PCC Vendor ID Enumeration
 * Enumerates the values of the PCI configuration header vendor ID.
 */
#define BDK_PCC_VENDOR_E_CAVIUM (0x177d) /**< Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */

/**
 * Structure pcc_dev_con_s
 *
 * PCC Device Connection Structure
 * Defines the components of the PCC device connection values enumerated by PCC_DEV_CON_E,
 * using ARI format.
 */
union bdk_pcc_dev_con_s
{
    uint32_t u;
    struct bdk_pcc_dev_con_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_18_31        : 14;
        uint32_t ecam                  : 2;  /**< [ 17: 16] ECAM number/NCB bus number. */
        uint32_t bus                   : 8;  /**< [ 15:  8] ECAM bus number. */
        uint32_t func                  : 8;  /**< [  7:  0] For ARI devices (when bus is non-zero), an eight-bit RSL function number.

                                                                 For non-ARI devices (when bus is zero), <7:3> is the device number, <2:0> the function
                                                                 number. */
#else /* Word 0 - Little Endian */
        uint32_t func                  : 8;  /**< [  7:  0] For ARI devices (when bus is non-zero), an eight-bit RSL function number.

                                                                 For non-ARI devices (when bus is zero), <7:3> is the device number, <2:0> the function
                                                                 number. */
        uint32_t bus                   : 8;  /**< [ 15:  8] ECAM bus number. */
        uint32_t ecam                  : 2;  /**< [ 17: 16] ECAM number/NCB bus number. */
        uint32_t reserved_18_31        : 14;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcc_dev_con_s_s cn; */
};

/**
 * Structure pcc_dev_idl_s
 *
 * PCC Device ID Low Structure
 * Defines the components of the PCC device-id low values enumerated by PCC_DEV_IDL_E.
 */
union bdk_pcc_dev_idl_s
{
    uint32_t u;
    struct bdk_pcc_dev_idl_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t bcc                   : 8;  /**< [ 23: 16] Base class code. */
        uint32_t sc                    : 8;  /**< [ 15:  8] Subclass code. */
        uint32_t pi                    : 8;  /**< [  7:  0] Programming interface. */
#else /* Word 0 - Little Endian */
        uint32_t pi                    : 8;  /**< [  7:  0] Programming interface. */
        uint32_t sc                    : 8;  /**< [ 15:  8] Subclass code. */
        uint32_t bcc                   : 8;  /**< [ 23: 16] Base class code. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pcc_dev_idl_s_s cn; */
};

/**
 * Structure pcc_ea_entry_s
 *
 * PCC PCI Enhanced Allocation Entry Structure
 * This structure describes the format of an enhanced allocation entry stored in
 * PCCPF_XXX_EA_ENTRY(). This describes what PCC hardware generates only; software must
 * implement a full EA parser including testing the [ENTRY_SIZE], [BASE64] and
 * [OFFSET64] fields.
 *
 * PCI configuration registers are 32-bits, however due to tool limitiations this
 * structure is described as a little-endian 64-bit wide structure.
 */
union bdk_pcc_ea_entry_s
{
    uint64_t u[3];
    struct bdk_pcc_ea_entry_s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t basel                 : 30; /**< [ 63: 34] Lower bits of the entry 0 base address. */
        uint64_t base64                : 1;  /**< [ 33: 33] 64-bit base, indicates [BASEH] is present. For CNXXXX always set. */
        uint64_t reserved_32           : 1;
        uint64_t enable                : 1;  /**< [ 31: 31] Enable. Always set. */
        uint64_t w                     : 1;  /**< [ 30: 30] Writable. Always clear. */
        uint64_t reserved_24_29        : 6;
        uint64_t sec_prop              : 8;  /**< [ 23: 16] Secondary properties. For CNXXXX always 0xFF, indicating that the primary properties must
                                                                 be used. */
        uint64_t pri_prop              : 8;  /**< [ 15:  8] Primary properties.
                                                                 0x0 = Memory space, non-prefetchable.
                                                                 0x4 = Physical function indicating virtual function memory space, non-prefetchable. */
        uint64_t bei                   : 4;  /**< [  7:  4] BAR equivelent indicator.
                                                                 0x0 = Entry is equivalent to BAR 0.
                                                                 0x2 = Entry is equivalent to BAR 2.
                                                                 0x4 = Entry is equivalent to BAR 4.
                                                                 0x7 = Equivalent not indicated.
                                                                 0x9 = Entry is equivalent to SR-IOV BAR 0.
                                                                 0xB = Entry is equivalent to SR-IOV BAR 2.
                                                                 0xD = Entry is equivalent to SR-IOV BAR 4. */
        uint64_t reserved_3            : 1;
        uint64_t entry_size            : 3;  /**< [  2:  0] Number of 32-bit words following this entry format header, excluding the header
                                                                 itself.
                                                                 0x4 = Four 32-bit words; header followed by base low, offset low, base high,
                                                                 offset high. */
#else /* Word 0 - Little Endian */
        uint64_t entry_size            : 3;  /**< [  2:  0] Number of 32-bit words following this entry format header, excluding the header
                                                                 itself.
                                                                 0x4 = Four 32-bit words; header followed by base low, offset low, base high,
                                                                 offset high. */
        uint64_t reserved_3            : 1;
        uint64_t bei                   : 4;  /**< [  7:  4] BAR equivelent indicator.
                                                                 0x0 = Entry is equivalent to BAR 0.
                                                                 0x2 = Entry is equivalent to BAR 2.
                                                                 0x4 = Entry is equivalent to BAR 4.
                                                                 0x7 = Equivalent not indicated.
                                                                 0x9 = Entry is equivalent to SR-IOV BAR 0.
                                                                 0xB = Entry is equivalent to SR-IOV BAR 2.
                                                                 0xD = Entry is equivalent to SR-IOV BAR 4. */
        uint64_t pri_prop              : 8;  /**< [ 15:  8] Primary properties.
                                                                 0x0 = Memory space, non-prefetchable.
                                                                 0x4 = Physical function indicating virtual function memory space, non-prefetchable. */
        uint64_t sec_prop              : 8;  /**< [ 23: 16] Secondary properties. For CNXXXX always 0xFF, indicating that the primary properties must
                                                                 be used. */
        uint64_t reserved_24_29        : 6;
        uint64_t w                     : 1;  /**< [ 30: 30] Writable. Always clear. */
        uint64_t enable                : 1;  /**< [ 31: 31] Enable. Always set. */
        uint64_t reserved_32           : 1;
        uint64_t base64                : 1;  /**< [ 33: 33] 64-bit base, indicates [BASEH] is present. For CNXXXX always set. */
        uint64_t basel                 : 30; /**< [ 63: 34] Lower bits of the entry 0 base address. */
#endif /* Word 0 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 1 - Big Endian */
        uint64_t baseh                 : 32; /**< [127: 96] Upper bits of the entry 0 base address. */
        uint64_t offsetl               : 30; /**< [ 95: 66] Lower bits of the entry 0 offset. Bits <1:0> of the offset are not present and
                                                                 must be interpreted as all-ones. */
        uint64_t offset64              : 1;  /**< [ 65: 65] 64-bit offset, indicates [OFFSETH] is present. For CNXXXX always set. */
        uint64_t reserved_64           : 1;
#else /* Word 1 - Little Endian */
        uint64_t reserved_64           : 1;
        uint64_t offset64              : 1;  /**< [ 65: 65] 64-bit offset, indicates [OFFSETH] is present. For CNXXXX always set. */
        uint64_t offsetl               : 30; /**< [ 95: 66] Lower bits of the entry 0 offset. Bits <1:0> of the offset are not present and
                                                                 must be interpreted as all-ones. */
        uint64_t baseh                 : 32; /**< [127: 96] Upper bits of the entry 0 base address. */
#endif /* Word 1 - End */
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 2 - Big Endian */
        uint64_t reserved_160_191      : 32;
        uint64_t offseth               : 32; /**< [159:128] Upper bits of the entry 0 offset. */
#else /* Word 2 - Little Endian */
        uint64_t offseth               : 32; /**< [159:128] Upper bits of the entry 0 offset. */
        uint64_t reserved_160_191      : 32;
#endif /* Word 2 - End */
    } s;
    /* struct bdk_pcc_ea_entry_s_s cn; */
};

/**
 * Register (PCCPF) pccpf_xxx_ari_cap_hdr
 *
 * PCC PF ARI Capability Header Register
 * This register is the header of the 8-byte PCI ARI capability structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_ari_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to PCCPF_XXX_VSEC_CAP_HDR. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. Points to PCCPF_XXX_VSEC_CAP_HDR. */
#endif /* Word 0 - End */
    } s;
    struct bdk_pccpf_xxx_ari_cap_hdr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If SR-IOV is supported as per PCC_DEV_IDL_E, points to
                                                                 PCCPF_XXX_SRIOV_CAP_HDR, else 0x0. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version (0x1). */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability (0xe). */
#else /* Word 0 - Little Endian */
        uint32_t ariid                 : 16; /**< [ 15:  0](RO) PCIE extended capability (0xe). */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version (0x1). */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If SR-IOV is supported as per PCC_DEV_IDL_E, points to
                                                                 PCCPF_XXX_SRIOV_CAP_HDR, else 0x0. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_ari_cap_hdr_s cn88xx; */
    /* struct bdk_pccpf_xxx_ari_cap_hdr_cn81xx cn83xx; */
} bdk_pccpf_xxx_ari_cap_hdr_t;

#define BDK_PCCPF_XXX_ARI_CAP_HDR BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x140;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x140;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x100;
    __bdk_csr_fatal("PCCPF_XXX_ARI_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_ARI_CAP_HDR bdk_pccpf_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_ARI_CAP_HDR "PCCPF_XXX_ARI_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_ARI_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar0l
 *
 * PCC PF Base Address 0 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar0l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar0l_s cn88xxp1; */
    struct bdk_pccpf_xxx_bar0l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_bar0l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_bar0l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_bar0l_t;

#define BDK_PCCPF_XXX_BAR0L BDK_PCCPF_XXX_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR0L_FUNC(void)
{
    return 0x10;
}

#define typedef_BDK_PCCPF_XXX_BAR0L bdk_pccpf_xxx_bar0l_t
#define bustype_BDK_PCCPF_XXX_BAR0L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR0L "PCCPF_XXX_BAR0L"
#define busnum_BDK_PCCPF_XXX_BAR0L 0
#define arguments_BDK_PCCPF_XXX_BAR0L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar0u
 *
 * PCC PF Base Address 0 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar0u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 0 base address. Bits corresponding to address bits
                                                                 less than the size of the BAR are read-as-zero, other bits are read-write only to allow
                                                                 determining the size of the BAR. Hardware has fixed address decoding and does not use this
                                                                 BAR for address decoding. After sizing, for proper software behavior, software must
                                                                 restore the register value, where the proper value may be read from PCCPF_XXX_VSEC_BAR0U,
                                                                 with software writing the node number into the field bits corresponding to address bits
                                                                 <45:44>.

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 0 base address. Bits corresponding to address bits
                                                                 less than the size of the BAR are read-as-zero, other bits are read-write only to allow
                                                                 determining the size of the BAR. Hardware has fixed address decoding and does not use this
                                                                 BAR for address decoding. After sizing, for proper software behavior, software must
                                                                 restore the register value, where the proper value may be read from PCCPF_XXX_VSEC_BAR0U,
                                                                 with software writing the node number into the field bits corresponding to address bits
                                                                 <45:44>.

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar0u_s cn; */
} bdk_pccpf_xxx_bar0u_t;

#define BDK_PCCPF_XXX_BAR0U BDK_PCCPF_XXX_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR0U_FUNC(void)
{
    return 0x14;
}

#define typedef_BDK_PCCPF_XXX_BAR0U bdk_pccpf_xxx_bar0u_t
#define bustype_BDK_PCCPF_XXX_BAR0U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR0U "PCCPF_XXX_BAR0U"
#define busnum_BDK_PCCPF_XXX_BAR0U 0
#define arguments_BDK_PCCPF_XXX_BAR0U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar2l
 *
 * PCC PF Base Address 2 Lower Register
 * This register is non-zero only for those devices needing two register BARs.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar2l_s cn88xxp1; */
    struct bdk_pccpf_xxx_bar2l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_bar2l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_bar2l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_bar2l_t;

#define BDK_PCCPF_XXX_BAR2L BDK_PCCPF_XXX_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR2L_FUNC(void)
{
    return 0x18;
}

#define typedef_BDK_PCCPF_XXX_BAR2L bdk_pccpf_xxx_bar2l_t
#define bustype_BDK_PCCPF_XXX_BAR2L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR2L "PCCPF_XXX_BAR2L"
#define busnum_BDK_PCCPF_XXX_BAR2L 0
#define arguments_BDK_PCCPF_XXX_BAR2L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar2u
 *
 * PCC PF Base Address 2 Upper Register
 * This register is non-zero only for those devices needing two register BARs.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar2u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar2u_s cn; */
} bdk_pccpf_xxx_bar2u_t;

#define BDK_PCCPF_XXX_BAR2U BDK_PCCPF_XXX_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR2U_FUNC(void)
{
    return 0x1c;
}

#define typedef_BDK_PCCPF_XXX_BAR2U bdk_pccpf_xxx_bar2u_t
#define bustype_BDK_PCCPF_XXX_BAR2U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR2U "PCCPF_XXX_BAR2U"
#define busnum_BDK_PCCPF_XXX_BAR2U 0
#define arguments_BDK_PCCPF_XXX_BAR2U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar4l
 *
 * PCC PF Base Address 4 Lower Register
 * This register is non-zero only for MSI-X devices.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar4l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar4l_s cn88xxp1; */
    struct bdk_pccpf_xxx_bar4l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_bar4l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_bar4l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_bar4l_t;

#define BDK_PCCPF_XXX_BAR4L BDK_PCCPF_XXX_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR4L_FUNC(void)
{
    return 0x20;
}

#define typedef_BDK_PCCPF_XXX_BAR4L bdk_pccpf_xxx_bar4l_t
#define bustype_BDK_PCCPF_XXX_BAR4L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR4L "PCCPF_XXX_BAR4L"
#define busnum_BDK_PCCPF_XXX_BAR4L 0
#define arguments_BDK_PCCPF_XXX_BAR4L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_bar4u
 *
 * PCC PF Base Address 4 Upper Register
 * This register is non-zero only for MSI-X devices.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_bar4u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Contains the upper 32 bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_bar4u_s cn; */
} bdk_pccpf_xxx_bar4u_t;

#define BDK_PCCPF_XXX_BAR4U BDK_PCCPF_XXX_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR4U_FUNC(void)
{
    return 0x24;
}

#define typedef_BDK_PCCPF_XXX_BAR4U bdk_pccpf_xxx_bar4u_t
#define bustype_BDK_PCCPF_XXX_BAR4U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_BAR4U "PCCPF_XXX_BAR4U"
#define busnum_BDK_PCCPF_XXX_BAR4U 0
#define arguments_BDK_PCCPF_XXX_BAR4U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_cap_ptr
 *
 * PCC PF Capability Pointer Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_cap_ptr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCPF_XXX_E_CAP_HDR. */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCPF_XXX_E_CAP_HDR. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_cap_ptr_s cn88xxp1; */
    /* struct bdk_pccpf_xxx_cap_ptr_s cn81xx; */
    /* struct bdk_pccpf_xxx_cap_ptr_s cn83xx; */
    struct bdk_pccpf_xxx_cap_ptr_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCPF_XXX_E_CAP_HDR. Changed in pass 2. */
#else /* Word 0 - Little Endian */
        uint32_t cp                    : 8;  /**< [  7:  0](RO) First capability pointer. Points to PCCPF_XXX_E_CAP_HDR. Changed in pass 2. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_cap_ptr_t;

#define BDK_PCCPF_XXX_CAP_PTR BDK_PCCPF_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CAP_PTR_FUNC(void)
{
    return 0x34;
}

#define typedef_BDK_PCCPF_XXX_CAP_PTR bdk_pccpf_xxx_cap_ptr_t
#define bustype_BDK_PCCPF_XXX_CAP_PTR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_CAP_PTR "PCCPF_XXX_CAP_PTR"
#define busnum_BDK_PCCPF_XXX_CAP_PTR 0
#define arguments_BDK_PCCPF_XXX_CAP_PTR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_clsize
 *
 * PCC PF Cache Line Size Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_clsize_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) BIST. */
        uint32_t hdrtype               : 8;  /**< [ 23: 16](RO) Header type. For RSL, 0x80 to indicate a multifunction device, else 0x0. Per the SR-IOV
                                                                 specification, VFs are not indicated as multifunction devices. */
        uint32_t lattim                : 8;  /**< [ 15:  8](RO) Latency timer. */
        uint32_t clsize                : 8;  /**< [  7:  0](RO) Cacheline size. */
#else /* Word 0 - Little Endian */
        uint32_t clsize                : 8;  /**< [  7:  0](RO) Cacheline size. */
        uint32_t lattim                : 8;  /**< [ 15:  8](RO) Latency timer. */
        uint32_t hdrtype               : 8;  /**< [ 23: 16](RO) Header type. For RSL, 0x80 to indicate a multifunction device, else 0x0. Per the SR-IOV
                                                                 specification, VFs are not indicated as multifunction devices. */
        uint32_t bist                  : 8;  /**< [ 31: 24](RO) BIST. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_clsize_s cn; */
} bdk_pccpf_xxx_clsize_t;

#define BDK_PCCPF_XXX_CLSIZE BDK_PCCPF_XXX_CLSIZE_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CLSIZE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CLSIZE_FUNC(void)
{
    return 0xc;
}

#define typedef_BDK_PCCPF_XXX_CLSIZE bdk_pccpf_xxx_clsize_t
#define bustype_BDK_PCCPF_XXX_CLSIZE BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_CLSIZE "PCCPF_XXX_CLSIZE"
#define busnum_BDK_PCCPF_XXX_CLSIZE 0
#define arguments_BDK_PCCPF_XXX_CLSIZE -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_cmd
 *
 * PCC PF Command/Status Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_21_31        : 11;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. */
        uint32_t reserved_3_19         : 17;
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable.
                                                                 Internal:
                                                                 For simplicity always one; we do not disable NCB transactions. */
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable.
                                                                 Internal:
                                                                 NCB/RSL always decoded; have hardcoded BARs. */
        uint32_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0            : 1;
        uint32_t msae                  : 1;  /**< [  1:  1](RO) Memory space access enable.
                                                                 Internal:
                                                                 NCB/RSL always decoded; have hardcoded BARs. */
        uint32_t me                    : 1;  /**< [  2:  2](RO) Master enable.
                                                                 Internal:
                                                                 For simplicity always one; we do not disable NCB transactions. */
        uint32_t reserved_3_19         : 17;
        uint32_t cl                    : 1;  /**< [ 20: 20](RO) Capabilities list. Indicates presence of an extended capability item. */
        uint32_t reserved_21_31        : 11;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_cmd_s cn; */
} bdk_pccpf_xxx_cmd_t;

#define BDK_PCCPF_XXX_CMD BDK_PCCPF_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CMD_FUNC(void)
{
    return 4;
}

#define typedef_BDK_PCCPF_XXX_CMD bdk_pccpf_xxx_cmd_t
#define bustype_BDK_PCCPF_XXX_CMD BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_CMD "PCCPF_XXX_CMD"
#define busnum_BDK_PCCPF_XXX_CMD 0
#define arguments_BDK_PCCPF_XXX_CMD -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_e_cap_hdr
 *
 * PCC PF PCI Express Capabilities Register
 * This register is the header of the 64-byte PCIe capability header.  Address changed in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_e_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device/port type. Indicates PCIe endpoint (0x0) for ARI devices (when bus is non-zero) and
                                                                 integrated endpoint (0x9) otherwise. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else 0x0. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else 0x0. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device/port type. Indicates PCIe endpoint (0x0) for ARI devices (when bus is non-zero) and
                                                                 integrated endpoint (0x9) otherwise. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    struct bdk_pccpf_xxx_e_cap_hdr_cn88xxp1
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else 0x0. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else 0x0. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } cn88xxp1;
    struct bdk_pccpf_xxx_e_cap_hdr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device/port type. Indicates PCIe endpoint (0x0) for ARI devices (when bus is non-zero) and
                                                                 integrated endpoint (0x9) otherwise. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else if PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else if PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Device/port type. Indicates PCIe endpoint (0x0) for ARI devices (when bus is non-zero) and
                                                                 integrated endpoint (0x9) otherwise. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_e_cap_hdr_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_e_cap_hdr_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Reserved. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else if PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO) PCIe capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR, else if PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t pciecv                : 4;  /**< [ 19: 16](RO) PCIe capability version. */
        uint32_t dpt                   : 4;  /**< [ 23: 20](RO) Reserved. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_e_cap_hdr_t;

#define BDK_PCCPF_XXX_E_CAP_HDR BDK_PCCPF_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_E_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x40;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x40;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        return 0x70;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x40;
    __bdk_csr_fatal("PCCPF_XXX_E_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_E_CAP_HDR bdk_pccpf_xxx_e_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_E_CAP_HDR "PCCPF_XXX_E_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_E_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_e_dev_cap
 *
 * PCC PF PCI Express Device Capabilities Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_e_dev_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. Required to be set by PCIe3.1. */
        uint32_t reserved_0_14         : 15;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_14         : 15;
        uint32_t rber                  : 1;  /**< [ 15: 15](RO) Role-based error reporting. Required to be set by PCIe3.1. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_e_dev_cap_s cn; */
} bdk_pccpf_xxx_e_dev_cap_t;

#define BDK_PCCPF_XXX_E_DEV_CAP BDK_PCCPF_XXX_E_DEV_CAP_FUNC()
static inline uint64_t BDK_PCCPF_XXX_E_DEV_CAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_E_DEV_CAP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x44;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x44;
    __bdk_csr_fatal("PCCPF_XXX_E_DEV_CAP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_E_DEV_CAP bdk_pccpf_xxx_e_dev_cap_t
#define bustype_BDK_PCCPF_XXX_E_DEV_CAP BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_E_DEV_CAP "PCCPF_XXX_E_DEV_CAP"
#define busnum_BDK_PCCPF_XXX_E_DEV_CAP 0
#define arguments_BDK_PCCPF_XXX_E_DEV_CAP -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_ea_cap_hdr
 *
 * PCC PF PCI Enhanced Allocation Capabilities Register
 * This register is the header of the variable-sized PCI enhanced allocation capability
 * structure for type 0 devices.
 * The register is 0x0 when PCCPF_XXX_VSEC_SCTL[EA] is clear.
 * Added in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_ea_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_22_31        : 10;
        uint32_t num_entries           : 6;  /**< [ 21: 16](RO/H) Number of enhanced entries:
                                                                   0x0 = No non-zero BARs.
                                                                   0x1 = 1 non-zero normal or SR-IOV BARs.
                                                                   0x2 = 2 non-zero normal or SR-IOV BARs.
                                                                   0x3 = 3 non-zero normal or SR-IOV BARs.
                                                                   0x4 = 4 non-zero normal or SR-IOV BARs.

                                                                 CNXXXX never has more than four normal or SR-IOV BARs. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer.  No next capability. */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO/H) Enhanced allocation capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t pcieid                : 8;  /**< [  7:  0](RO/H) Enhanced allocation capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer.  No next capability. */
        uint32_t num_entries           : 6;  /**< [ 21: 16](RO/H) Number of enhanced entries:
                                                                   0x0 = No non-zero BARs.
                                                                   0x1 = 1 non-zero normal or SR-IOV BARs.
                                                                   0x2 = 2 non-zero normal or SR-IOV BARs.
                                                                   0x3 = 3 non-zero normal or SR-IOV BARs.
                                                                   0x4 = 4 non-zero normal or SR-IOV BARs.

                                                                 CNXXXX never has more than four normal or SR-IOV BARs. */
        uint32_t reserved_22_31        : 10;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_ea_cap_hdr_s cn; */
} bdk_pccpf_xxx_ea_cap_hdr_t;

#define BDK_PCCPF_XXX_EA_CAP_HDR BDK_PCCPF_XXX_EA_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_EA_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_EA_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x98;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x98;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x98;
    __bdk_csr_fatal("PCCPF_XXX_EA_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_EA_CAP_HDR bdk_pccpf_xxx_ea_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_EA_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_EA_CAP_HDR "PCCPF_XXX_EA_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_EA_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_EA_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_ea_entry#
 *
 * PCC PF PCI Enhanced Allocation Entry Registers
 * These registers contain up to four sequential enhanced allocation entries. Each
 * entry consists of 5 sequential words described by PCC_EA_ENTRY_S.
 * All entries are 0x0 when PCCPF_XXX_VSEC_SCTL[EA] is clear.
 * Added in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_ea_entryx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO/H) Entry data.  See PCC_EA_ENTRY_S. */
#else /* Word 0 - Little Endian */
        uint32_t data                  : 32; /**< [ 31:  0](RO/H) Entry data.  See PCC_EA_ENTRY_S. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_ea_entryx_s cn; */
} bdk_pccpf_xxx_ea_entryx_t;

static inline uint64_t BDK_PCCPF_XXX_EA_ENTRYX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_EA_ENTRYX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=19))
        return 0x9c + 4 * ((a) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=19))
        return 0x9c + 4 * ((a) & 0x1f);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && (a<=19))
        return 0x9c + 4 * ((a) & 0x1f);
    __bdk_csr_fatal("PCCPF_XXX_EA_ENTRYX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_EA_ENTRYX(a) bdk_pccpf_xxx_ea_entryx_t
#define bustype_BDK_PCCPF_XXX_EA_ENTRYX(a) BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_EA_ENTRYX(a) "PCCPF_XXX_EA_ENTRYX"
#define busnum_BDK_PCCPF_XXX_EA_ENTRYX(a) (a)
#define arguments_BDK_PCCPF_XXX_EA_ENTRYX(a) (a),-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_id
 *
 * PCC PF Vendor and Device ID Register
 * This register is the header of the 64-byte PCI type 0 configuration structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. <15:8> is PCC_PROD_E::GEN. <7:0> enumerated by PCC_DEV_IDL_E.

                                                                 Internal:
                                                                 Unit
                                                                 from PCC's tie__pfunitid. */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
#else /* Word 0 - Little Endian */
        uint32_t vendid                : 16; /**< [ 15:  0](RO) Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
        uint32_t devid                 : 16; /**< [ 31: 16](RO) Device ID. <15:8> is PCC_PROD_E::GEN. <7:0> enumerated by PCC_DEV_IDL_E.

                                                                 Internal:
                                                                 Unit
                                                                 from PCC's tie__pfunitid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_id_s cn; */
} bdk_pccpf_xxx_id_t;

#define BDK_PCCPF_XXX_ID BDK_PCCPF_XXX_ID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_ID_FUNC(void)
{
    return 0;
}

#define typedef_BDK_PCCPF_XXX_ID bdk_pccpf_xxx_id_t
#define bustype_BDK_PCCPF_XXX_ID BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_ID "PCCPF_XXX_ID"
#define busnum_BDK_PCCPF_XXX_ID 0
#define arguments_BDK_PCCPF_XXX_ID -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_msix_cap_hdr
 *
 * PCC PF MSI-X Capability Header Register
 * This register is the header of the 36-byte PCI MSI-X capability structure. Address changed in
 * pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_msix_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable.
                                                                 0 = The MSI-X PBAs corresponding to this function are cleared.  Interrupt messages
                                                                 will not be issued.
                                                                 1 = Normal PBA and MSI-X delivery. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors' mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits.

                                                                 Setting or clearing FUNM has no effect on the state of the per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1).
                                                                 Internal:
                                                                 From PCC's MSIX_PF_VECS parameter. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Next capability pointer. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1).
                                                                 Internal:
                                                                 From PCC's MSIX_PF_VECS parameter. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors' mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits.

                                                                 Setting or clearing FUNM has no effect on the state of the per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable.
                                                                 0 = The MSI-X PBAs corresponding to this function are cleared.  Interrupt messages
                                                                 will not be issued.
                                                                 1 = Normal PBA and MSI-X delivery. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_msix_cap_hdr_s cn88xxp1; */
    struct bdk_pccpf_xxx_msix_cap_hdr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable.
                                                                 0 = The MSI-X PBAs corresponding to this function are cleared.  Interrupt messages
                                                                 will not be issued.
                                                                 1 = Normal PBA and MSI-X delivery. */
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors' mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits.

                                                                 Setting or clearing FUNM has no effect on the state of the per-vector mask bits. */
        uint32_t reserved_27_29        : 3;
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1).
                                                                 Internal:
                                                                 From PCC's MSIX_PF_VECS parameter. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID. */
#else /* Word 0 - Little Endian */
        uint32_t msixcid               : 8;  /**< [  7:  0](RO) MSI-X Capability ID. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO/H) Next capability pointer. If PCCPF_XXX_VSEC_SCTL[EA] is set points to
                                                                 PCCPF_XXX_EA_CAP_HDR, else 0x0. */
        uint32_t msixts                : 11; /**< [ 26: 16](RO) MSI-X table size encoded as (table size - 1).
                                                                 Internal:
                                                                 From PCC's MSIX_PF_VECS parameter. */
        uint32_t reserved_27_29        : 3;
        uint32_t funm                  : 1;  /**< [ 30: 30](R/W) Function mask.
                                                                 0 = Each vectors' mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits.

                                                                 Setting or clearing FUNM has no effect on the state of the per-vector mask bits. */
        uint32_t msixen                : 1;  /**< [ 31: 31](R/W) MSI-X enable.
                                                                 0 = The MSI-X PBAs corresponding to this function are cleared.  Interrupt messages
                                                                 will not be issued.
                                                                 1 = Normal PBA and MSI-X delivery. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_msix_cap_hdr_cn81xx cn83xx; */
    /* struct bdk_pccpf_xxx_msix_cap_hdr_cn81xx cn88xxp2; */
} bdk_pccpf_xxx_msix_cap_hdr_t;

#define BDK_PCCPF_XXX_MSIX_CAP_HDR BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x80;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x80;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        return 0xb0;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x80;
    __bdk_csr_fatal("PCCPF_XXX_MSIX_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_MSIX_CAP_HDR bdk_pccpf_xxx_msix_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_MSIX_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_MSIX_CAP_HDR "PCCPF_XXX_MSIX_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_MSIX_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_MSIX_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_msix_pba
 *
 * PCC PF MSI-X PBA Offset and BIR Register
 * Address changed in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_msix_pba_s
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
    /* struct bdk_pccpf_xxx_msix_pba_s cn; */
} bdk_pccpf_xxx_msix_pba_t;

#define BDK_PCCPF_XXX_MSIX_PBA BDK_PCCPF_XXX_MSIX_PBA_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_PBA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_PBA_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x88;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x88;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        return 0xb8;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x88;
    __bdk_csr_fatal("PCCPF_XXX_MSIX_PBA", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_MSIX_PBA bdk_pccpf_xxx_msix_pba_t
#define bustype_BDK_PCCPF_XXX_MSIX_PBA BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_MSIX_PBA "PCCPF_XXX_MSIX_PBA"
#define busnum_BDK_PCCPF_XXX_MSIX_PBA 0
#define arguments_BDK_PCCPF_XXX_MSIX_PBA -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_msix_table
 *
 * PCC PF MSI-X Table Offset and BIR Register
 * Address changed in pass 2.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_msix_table_s
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
    /* struct bdk_pccpf_xxx_msix_table_s cn; */
} bdk_pccpf_xxx_msix_table_t;

#define BDK_PCCPF_XXX_MSIX_TABLE BDK_PCCPF_XXX_MSIX_TABLE_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_TABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_TABLE_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x84;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x84;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        return 0xb4;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
        return 0x84;
    __bdk_csr_fatal("PCCPF_XXX_MSIX_TABLE", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_MSIX_TABLE bdk_pccpf_xxx_msix_table_t
#define bustype_BDK_PCCPF_XXX_MSIX_TABLE BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_MSIX_TABLE "PCCPF_XXX_MSIX_TABLE"
#define busnum_BDK_PCCPF_XXX_MSIX_TABLE 0
#define arguments_BDK_PCCPF_XXX_MSIX_TABLE -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_rev
 *
 * PCC PF Class Code/Revision ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_rev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[23:16]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[15:8]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[7:0]. */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCPF_XXX_VSEC_SCTL[RID]. */
#else /* Word 0 - Little Endian */
        uint32_t rid                   : 8;  /**< [  7:  0](RO/H) Revision ID. Read only version of PCCPF_XXX_VSEC_SCTL[RID]. */
        uint32_t pi                    : 8;  /**< [ 15:  8](RO) Programming interface. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[7:0]. */
        uint32_t sc                    : 8;  /**< [ 23: 16](RO) Subclass code. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[15:8]. */
        uint32_t bcc                   : 8;  /**< [ 31: 24](RO) Base class code. See PCC_DEV_IDL_E.
                                                                 Internal:
                                                                 From PCC's tie__class_code[23:16]. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_rev_s cn; */
} bdk_pccpf_xxx_rev_t;

#define BDK_PCCPF_XXX_REV BDK_PCCPF_XXX_REV_FUNC()
static inline uint64_t BDK_PCCPF_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_REV_FUNC(void)
{
    return 8;
}

#define typedef_BDK_PCCPF_XXX_REV bdk_pccpf_xxx_rev_t
#define bustype_BDK_PCCPF_XXX_REV BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_REV "PCCPF_XXX_REV"
#define busnum_BDK_PCCPF_XXX_REV 0
#define arguments_BDK_PCCPF_XXX_REV -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sari_nxt
 *
 * PCC PF ARI Capability Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sari_nxt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t nxtfn                 : 8;  /**< [ 15:  8](RO/H) Next function number. 0x0 except for PCC_DEV_IDL_E::MRML, when it points to the next MFD
                                                                 in the linked list of MFDs underneath the RSL and the value comes from
                                                                 PCCPF_XXX_VSEC_CTL[NXTFN_NS] or PCCPF_XXX_VSEC_SCTL[NXTFN_S] for non-secure or secure
                                                                 accesses respectively. */
        uint32_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_7          : 8;
        uint32_t nxtfn                 : 8;  /**< [ 15:  8](RO/H) Next function number. 0x0 except for PCC_DEV_IDL_E::MRML, when it points to the next MFD
                                                                 in the linked list of MFDs underneath the RSL and the value comes from
                                                                 PCCPF_XXX_VSEC_CTL[NXTFN_NS] or PCCPF_XXX_VSEC_SCTL[NXTFN_S] for non-secure or secure
                                                                 accesses respectively. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sari_nxt_s cn; */
} bdk_pccpf_xxx_sari_nxt_t;

#define BDK_PCCPF_XXX_SARI_NXT BDK_PCCPF_XXX_SARI_NXT_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SARI_NXT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SARI_NXT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x144;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x144;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x104;
    __bdk_csr_fatal("PCCPF_XXX_SARI_NXT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_SARI_NXT bdk_pccpf_xxx_sari_nxt_t
#define bustype_BDK_PCCPF_XXX_SARI_NXT BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SARI_NXT "PCCPF_XXX_SARI_NXT"
#define busnum_BDK_PCCPF_XXX_SARI_NXT 0
#define arguments_BDK_PCCPF_XXX_SARI_NXT -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar0l
 *
 * PCC PF SR-IOV BAR 0 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar0l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar0l_s cn88xxp1; */
    struct bdk_pccpf_xxx_sriov_bar0l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_sriov_bar0l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_sriov_bar0l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_sriov_bar0l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR0L BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC(void)
{
    return 0x1a4;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR0L bdk_pccpf_xxx_sriov_bar0l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR0L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR0L "PCCPF_XXX_SRIOV_BAR0L"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR0L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR0L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar0u
 *
 * PCC PF SR-IOV BAR 0 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar0u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and tie__vfbar0_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_rbsz and tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar0u_s cn; */
} bdk_pccpf_xxx_sriov_bar0u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR0U BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC(void)
{
    return 0x1a8;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR0U bdk_pccpf_xxx_sriov_bar0u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR0U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR0U "PCCPF_XXX_SRIOV_BAR0U"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR0U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR0U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar2l
 *
 * PCC PF SR-IOV BAR 2 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar2l_s cn88xxp1; */
    struct bdk_pccpf_xxx_sriov_bar2l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_sriov_bar2l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_sriov_bar2l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_sriov_bar2l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR2L BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC(void)
{
    return 0x1ac;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR2L bdk_pccpf_xxx_sriov_bar2l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR2L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR2L "PCCPF_XXX_SRIOV_BAR2L"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR2L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR2L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar2u
 *
 * PCC PF SR-IOV BAR 2 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar2u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar2u_s cn; */
} bdk_pccpf_xxx_sriov_bar2u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR2U BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC(void)
{
    return 0x1b0;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR2U bdk_pccpf_xxx_sriov_bar2u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR2U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR2U "PCCPF_XXX_SRIOV_BAR2U"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR2U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR2U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar4l
 *
 * PCC PF SR-IOV BAR 4 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar4l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO) BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar4l_s cn88xxp1; */
    struct bdk_pccpf_xxx_sriov_bar4l_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_sriov_bar4l_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_sriov_bar4l_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
        uint32_t reserved_4_15         : 12;
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else /* Word 0 - Little Endian */
        uint32_t mspc                  : 1;  /**< [  0:  0](RO) Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
        uint32_t typ                   : 2;  /**< [  2:  1](RO/H) BAR type. 0x0 if not implemented or PCCPF_XXX_VSEC_SCTL[EA] is set, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR.
                                                                 Changed in pass 2. */
        uint32_t pf                    : 1;  /**< [  3:  3](RO) Prefetchable. */
        uint32_t reserved_4_15         : 12;
        uint32_t lbab                  : 16; /**< [ 31: 16](R/W/H) Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_sriov_bar4l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR4L BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC(void)
{
    return 0x1b4;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR4L bdk_pccpf_xxx_sriov_bar4l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR4L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR4L "PCCPF_XXX_SRIOV_BAR4L"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR4L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR4L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_bar4u
 *
 * PCC PF SR-IOV BAR 4 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_bar4u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](R/W/H) Upper bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_bar4u_s cn; */
} bdk_pccpf_xxx_sriov_bar4u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR4U BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC(void)
{
    return 0x1b8;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_BAR4U bdk_pccpf_xxx_sriov_bar4u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR4U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_BAR4U "PCCPF_XXX_SRIOV_BAR4U"
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR4U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR4U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_cap
 *
 * PCC PF SR-IOV Capability Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfmimn                : 11; /**< [ 31: 21](RO) VF migration interrupt message number. */
        uint32_t reserved_2_20         : 19;
        uint32_t arichp                : 1;  /**< [  1:  1](RO) ARI capable hierarchy preserved. */
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO) VF migration capable. */
#else /* Word 0 - Little Endian */
        uint32_t vfmc                  : 1;  /**< [  0:  0](RO) VF migration capable. */
        uint32_t arichp                : 1;  /**< [  1:  1](RO) ARI capable hierarchy preserved. */
        uint32_t reserved_2_20         : 19;
        uint32_t vfmimn                : 11; /**< [ 31: 21](RO) VF migration interrupt message number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_cap_s cn; */
} bdk_pccpf_xxx_sriov_cap_t;

#define BDK_PCCPF_XXX_SRIOV_CAP BDK_PCCPF_XXX_SRIOV_CAP_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_FUNC(void)
{
    return 0x184;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_CAP bdk_pccpf_xxx_sriov_cap_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CAP BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_CAP "PCCPF_XXX_SRIOV_CAP"
#define busnum_BDK_PCCPF_XXX_SRIOV_CAP 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CAP -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_cap_hdr
 *
 * PCC PF SR-IOV Capability Header Register
 * This register is the header of the 64-byte PCI SR-IOV capability structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. None. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE extended capability. */
#else /* Word 0 - Little Endian */
        uint32_t pcieec                : 16; /**< [ 15:  0](RO) PCIE extended capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. None. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_cap_hdr_s cn; */
} bdk_pccpf_xxx_sriov_cap_hdr_t;

#define BDK_PCCPF_XXX_SRIOV_CAP_HDR BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC(void)
{
    return 0x180;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_CAP_HDR bdk_pccpf_xxx_sriov_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_CAP_HDR "PCCPF_XXX_SRIOV_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_SRIOV_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_ctl
 *
 * PCC PF SR-IOV Control/Status Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_17_31        : 15;
        uint32_t ms                    : 1;  /**< [ 16: 16](RO) VF migration status. */
        uint32_t reserved_5_15         : 11;
        uint32_t ach                   : 1;  /**< [  4:  4](RO) ARI capable hierarchy. */
        uint32_t mse                   : 1;  /**< [  3:  3](RO) VF MSE. Master space enable always on. */
        uint32_t mie                   : 1;  /**< [  2:  2](RO) VF migration interrupt enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO) VF migration enable. */
        uint32_t vfe                   : 1;  /**< [  0:  0](RO) VF enable. */
#else /* Word 0 - Little Endian */
        uint32_t vfe                   : 1;  /**< [  0:  0](RO) VF enable. */
        uint32_t me                    : 1;  /**< [  1:  1](RO) VF migration enable. */
        uint32_t mie                   : 1;  /**< [  2:  2](RO) VF migration interrupt enable. */
        uint32_t mse                   : 1;  /**< [  3:  3](RO) VF MSE. Master space enable always on. */
        uint32_t ach                   : 1;  /**< [  4:  4](RO) ARI capable hierarchy. */
        uint32_t reserved_5_15         : 11;
        uint32_t ms                    : 1;  /**< [ 16: 16](RO) VF migration status. */
        uint32_t reserved_17_31        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_ctl_s cn; */
} bdk_pccpf_xxx_sriov_ctl_t;

#define BDK_PCCPF_XXX_SRIOV_CTL BDK_PCCPF_XXX_SRIOV_CTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CTL_FUNC(void)
{
    return 0x188;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_CTL bdk_pccpf_xxx_sriov_ctl_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CTL BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_CTL "PCCPF_XXX_SRIOV_CTL"
#define busnum_BDK_PCCPF_XXX_SRIOV_CTL 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CTL -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_dev
 *
 * PCC PF SR-IOV VF Device ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_dev_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO) VF device ID. <15:8> is PCC_PROD_E::GEN. <7:0> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF.

                                                                 Internal:
                                                                 Unit from PCC's tie__vfunitid. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t vfdev                 : 16; /**< [ 31: 16](RO) VF device ID. <15:8> is PCC_PROD_E::GEN. <7:0> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF.

                                                                 Internal:
                                                                 Unit from PCC's tie__vfunitid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_dev_s cn; */
} bdk_pccpf_xxx_sriov_dev_t;

#define BDK_PCCPF_XXX_SRIOV_DEV BDK_PCCPF_XXX_SRIOV_DEV_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_DEV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_DEV_FUNC(void)
{
    return 0x198;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_DEV bdk_pccpf_xxx_sriov_dev_t
#define bustype_BDK_PCCPF_XXX_SRIOV_DEV BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_DEV "PCCPF_XXX_SRIOV_DEV"
#define busnum_BDK_PCCPF_XXX_SRIOV_DEV 0
#define arguments_BDK_PCCPF_XXX_SRIOV_DEV -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_fo
 *
 * PCC PF SR-IOV First VF Offset/VF Stride Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_fo_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO) VF stride. */
        uint32_t fo                    : 16; /**< [ 15:  0](RO) First VF offset. */
#else /* Word 0 - Little Endian */
        uint32_t fo                    : 16; /**< [ 15:  0](RO) First VF offset. */
        uint32_t vfs                   : 16; /**< [ 31: 16](RO) VF stride. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_fo_s cn; */
} bdk_pccpf_xxx_sriov_fo_t;

#define BDK_PCCPF_XXX_SRIOV_FO BDK_PCCPF_XXX_SRIOV_FO_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_FO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_FO_FUNC(void)
{
    return 0x194;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_FO bdk_pccpf_xxx_sriov_fo_t
#define bustype_BDK_PCCPF_XXX_SRIOV_FO BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_FO "PCCPF_XXX_SRIOV_FO"
#define busnum_BDK_PCCPF_XXX_SRIOV_FO 0
#define arguments_BDK_PCCPF_XXX_SRIOV_FO -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_nvf
 *
 * PCC PF SR-IOV Number of VFs/Function Dependency Link Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_nvf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO) Function dependency link. Only a single PF 0 exists. */
        uint32_t nvf                   : 16; /**< [ 15:  0](RO) Number of VFs that are visible.
                                                                 Internal:
                                                                 From PCC's MSIX_VFS parameter. */
#else /* Word 0 - Little Endian */
        uint32_t nvf                   : 16; /**< [ 15:  0](RO) Number of VFs that are visible.
                                                                 Internal:
                                                                 From PCC's MSIX_VFS parameter. */
        uint32_t fdl                   : 8;  /**< [ 23: 16](RO) Function dependency link. Only a single PF 0 exists. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_nvf_s cn; */
} bdk_pccpf_xxx_sriov_nvf_t;

#define BDK_PCCPF_XXX_SRIOV_NVF BDK_PCCPF_XXX_SRIOV_NVF_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_NVF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_NVF_FUNC(void)
{
    return 0x190;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_NVF bdk_pccpf_xxx_sriov_nvf_t
#define bustype_BDK_PCCPF_XXX_SRIOV_NVF BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_NVF "PCCPF_XXX_SRIOV_NVF"
#define busnum_BDK_PCCPF_XXX_SRIOV_NVF 0
#define arguments_BDK_PCCPF_XXX_SRIOV_NVF -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_ps
 *
 * PCC PF SR-IOV System Page Sizes Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_ps_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ps                    : 32; /**< [ 31:  0](RO) System page size. 1MB, as that is minimum stride between VFs. */
#else /* Word 0 - Little Endian */
        uint32_t ps                    : 32; /**< [ 31:  0](RO) System page size. 1MB, as that is minimum stride between VFs. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_ps_s cn; */
} bdk_pccpf_xxx_sriov_ps_t;

#define BDK_PCCPF_XXX_SRIOV_PS BDK_PCCPF_XXX_SRIOV_PS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_PS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_PS_FUNC(void)
{
    return 0x1a0;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_PS bdk_pccpf_xxx_sriov_ps_t
#define bustype_BDK_PCCPF_XXX_SRIOV_PS BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_PS "PCCPF_XXX_SRIOV_PS"
#define busnum_BDK_PCCPF_XXX_SRIOV_PS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_PS -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_supps
 *
 * PCC PF SR-IOV Supported Page Sizes Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_supps_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO) Supported page sizes. Indicates required 4K, 8K, 64K, 256K, 1M, 4M. The BAR fixed
                                                                 assignment makes this not useful. */
#else /* Word 0 - Little Endian */
        uint32_t supps                 : 32; /**< [ 31:  0](RO) Supported page sizes. Indicates required 4K, 8K, 64K, 256K, 1M, 4M. The BAR fixed
                                                                 assignment makes this not useful. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_supps_s cn; */
} bdk_pccpf_xxx_sriov_supps_t;

#define BDK_PCCPF_XXX_SRIOV_SUPPS BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC(void)
{
    return 0x19c;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_SUPPS bdk_pccpf_xxx_sriov_supps_t
#define bustype_BDK_PCCPF_XXX_SRIOV_SUPPS BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_SUPPS "PCCPF_XXX_SRIOV_SUPPS"
#define busnum_BDK_PCCPF_XXX_SRIOV_SUPPS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_SUPPS -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_sriov_vfs
 *
 * PCC PF SR-IOV Initial VFs/Total VFs Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_sriov_vfs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO) Total VFs.
                                                                 Internal:
                                                                 from pcc's MSIX_VFS parameter. */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO) Initial VFs.
                                                                 Internal:
                                                                 From PCC's MSIX_VFS parameter. */
#else /* Word 0 - Little Endian */
        uint32_t ivf                   : 16; /**< [ 15:  0](RO) Initial VFs.
                                                                 Internal:
                                                                 From PCC's MSIX_VFS parameter. */
        uint32_t tvf                   : 16; /**< [ 31: 16](RO) Total VFs.
                                                                 Internal:
                                                                 from pcc's MSIX_VFS parameter. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_sriov_vfs_s cn; */
} bdk_pccpf_xxx_sriov_vfs_t;

#define BDK_PCCPF_XXX_SRIOV_VFS BDK_PCCPF_XXX_SRIOV_VFS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_VFS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_VFS_FUNC(void)
{
    return 0x18c;
}

#define typedef_BDK_PCCPF_XXX_SRIOV_VFS bdk_pccpf_xxx_sriov_vfs_t
#define bustype_BDK_PCCPF_XXX_SRIOV_VFS BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SRIOV_VFS "PCCPF_XXX_SRIOV_VFS"
#define busnum_BDK_PCCPF_XXX_SRIOV_VFS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_VFS -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_subid
 *
 * PCC PF Subsystem ID/Subsystem Vendor ID Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_subid_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Device ID. <15:8> enumerated by PCC_PROD_E. <7:0> enumerated by PCC_DEV_IDL_E.

                                                                 Internal:
                                                                 Unit from PCC's tie__prod and tie__pfunitid. */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Cavium = 0x177D. */
#else /* Word 0 - Little Endian */
        uint32_t ssvid                 : 16; /**< [ 15:  0](RO) Subsystem vendor ID. Cavium = 0x177D. */
        uint32_t ssid                  : 16; /**< [ 31: 16](RO) Device ID. <15:8> enumerated by PCC_PROD_E. <7:0> enumerated by PCC_DEV_IDL_E.

                                                                 Internal:
                                                                 Unit from PCC's tie__prod and tie__pfunitid. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_subid_s cn; */
} bdk_pccpf_xxx_subid_t;

#define BDK_PCCPF_XXX_SUBID BDK_PCCPF_XXX_SUBID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SUBID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SUBID_FUNC(void)
{
    return 0x2c;
}

#define typedef_BDK_PCCPF_XXX_SUBID bdk_pccpf_xxx_subid_t
#define bustype_BDK_PCCPF_XXX_SUBID BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_SUBID "PCCPF_XXX_SUBID"
#define busnum_BDK_PCCPF_XXX_SUBID 0
#define arguments_BDK_PCCPF_XXX_SUBID -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar0l
 *
 * PCC PF Vendor-Specific Address 0 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar0l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar0l_s cn; */
} bdk_pccpf_xxx_vsec_bar0l_t;

#define BDK_PCCPF_XXX_VSEC_BAR0L BDK_PCCPF_XXX_VSEC_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x110;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x110;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x118;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR0L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR0L bdk_pccpf_xxx_vsec_bar0l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR0L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR0L "PCCPF_XXX_VSEC_BAR0L"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR0L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR0L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar0u
 *
 * PCC PF Vendor-Specific Address 0 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar0u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar0u_s cn; */
} bdk_pccpf_xxx_vsec_bar0u_t;

#define BDK_PCCPF_XXX_VSEC_BAR0U BDK_PCCPF_XXX_VSEC_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x114;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x114;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x11c;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR0U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR0U bdk_pccpf_xxx_vsec_bar0u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR0U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR0U "PCCPF_XXX_VSEC_BAR0U"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR0U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR0U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar2l
 *
 * PCC PF Vendor-Specific Address 2 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar2l_s cn; */
} bdk_pccpf_xxx_vsec_bar2l_t;

#define BDK_PCCPF_XXX_VSEC_BAR2L BDK_PCCPF_XXX_VSEC_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x118;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x118;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x120;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR2L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR2L bdk_pccpf_xxx_vsec_bar2l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR2L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR2L "PCCPF_XXX_VSEC_BAR2L"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR2L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR2L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar2u
 *
 * PCC PF Vendor-Specific Address 2 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar2u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar2u_s cn; */
} bdk_pccpf_xxx_vsec_bar2u_t;

#define BDK_PCCPF_XXX_VSEC_BAR2U BDK_PCCPF_XXX_VSEC_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x11c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x11c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x124;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR2U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR2U bdk_pccpf_xxx_vsec_bar2u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR2U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR2U "PCCPF_XXX_VSEC_BAR2U"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR2U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR2U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar4l
 *
 * PCC PF Vendor-Specific Address 4 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar4l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar4l_s cn; */
} bdk_pccpf_xxx_vsec_bar4l_t;

#define BDK_PCCPF_XXX_VSEC_BAR4L BDK_PCCPF_XXX_VSEC_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x120;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x120;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x128;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR4L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR4L bdk_pccpf_xxx_vsec_bar4l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR4L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR4L "PCCPF_XXX_VSEC_BAR4L"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR4L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR4L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_bar4u
 *
 * PCC PF Vendor-Specific Address 4 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_bar4u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__pfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_bar4u_s cn; */
} bdk_pccpf_xxx_vsec_bar4u_t;

#define BDK_PCCPF_XXX_VSEC_BAR4U BDK_PCCPF_XXX_VSEC_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x124;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x124;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x12c;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_BAR4U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_BAR4U bdk_pccpf_xxx_vsec_bar4u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR4U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_BAR4U "PCCPF_XXX_VSEC_BAR4U"
#define busnum_BDK_PCCPF_XXX_VSEC_BAR4U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR4U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_cap_hdr
 *
 * PCC PF Vendor-Specific Capability Header Register
 * This register is the header of the 64-byte Cavium ThunderX family PF capability
 * structure.
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_cap_hdr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If SR-IOV is supported as per PCC_DEV_IDL_E, points to the
                                                                 PCCPF_XXX_SRIOV_CAP_HDR, else 0x0. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsecid                : 16; /**< [ 15:  0](RO) PCIE extended capability. Indicates vendor-specific capability. */
#else /* Word 0 - Little Endian */
        uint32_t vsecid                : 16; /**< [ 15:  0](RO) PCIE extended capability. Indicates vendor-specific capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If SR-IOV is supported as per PCC_DEV_IDL_E, points to the
                                                                 PCCPF_XXX_SRIOV_CAP_HDR, else 0x0. */
#endif /* Word 0 - End */
    } s;
    struct bdk_pccpf_xxx_vsec_cap_hdr_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If this device is on a non-zero bus, points to
                                                                 PCCPF_XXX_ARI_CAP_HDR, else 0x0. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t vsecid                : 16; /**< [ 15:  0](RO) PCIE extended capability. Indicates vendor-specific capability. */
#else /* Word 0 - Little Endian */
        uint32_t vsecid                : 16; /**< [ 15:  0](RO) PCIE extended capability. Indicates vendor-specific capability. */
        uint32_t cv                    : 4;  /**< [ 19: 16](RO) Capability version. */
        uint32_t nco                   : 12; /**< [ 31: 20](RO) Next capability offset. If this device is on a non-zero bus, points to
                                                                 PCCPF_XXX_ARI_CAP_HDR, else 0x0. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_vsec_cap_hdr_s cn88xx; */
    /* struct bdk_pccpf_xxx_vsec_cap_hdr_cn81xx cn83xx; */
} bdk_pccpf_xxx_vsec_cap_hdr_t;

#define BDK_PCCPF_XXX_VSEC_CAP_HDR BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x100;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x100;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x108;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_CAP_HDR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_CAP_HDR bdk_pccpf_xxx_vsec_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_VSEC_CAP_HDR BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_CAP_HDR "PCCPF_XXX_VSEC_CAP_HDR"
#define busnum_BDK_PCCPF_XXX_VSEC_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_VSEC_CAP_HDR -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_ctl
 *
 * PCC PF Vendor-Specific Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nxtfn_ns              : 8;  /**< [ 31: 24](R/W) For non-secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN]
                                                                 indicating the next valid function number for this device.
                                                                 Must be kept as 0x0 for non-MRML PCC devices. */
        uint32_t reserved_8_23         : 16;
        uint32_t inst_num              : 8;  /**< [  7:  0](RO) Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
#else /* Word 0 - Little Endian */
        uint32_t inst_num              : 8;  /**< [  7:  0](RO) Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
        uint32_t reserved_8_23         : 16;
        uint32_t nxtfn_ns              : 8;  /**< [ 31: 24](R/W) For non-secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN]
                                                                 indicating the next valid function number for this device.
                                                                 Must be kept as 0x0 for non-MRML PCC devices. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_ctl_s cn; */
} bdk_pccpf_xxx_vsec_ctl_t;

#define BDK_PCCPF_XXX_VSEC_CTL BDK_PCCPF_XXX_VSEC_CTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_CTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x108;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x108;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x110;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_CTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_CTL bdk_pccpf_xxx_vsec_ctl_t
#define bustype_BDK_PCCPF_XXX_VSEC_CTL BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_CTL "PCCPF_XXX_VSEC_CTL"
#define busnum_BDK_PCCPF_XXX_VSEC_CTL 0
#define arguments_BDK_PCCPF_XXX_VSEC_CTL -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_id
 *
 * PCC PF Vendor-Specific Identification Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_id_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t len                   : 12; /**< [ 31: 20](RO) Number of bytes in the entire VSEC structure including PCCPF_XXX_VSEC_CAP_HDR. */
        uint32_t rev                   : 4;  /**< [ 19: 16](RO) Vendor-specific revision. */
        uint32_t id                    : 16; /**< [ 15:  0](RO) Vendor-specific ID. Indicates the ThunderX family VSEC ID. */
#else /* Word 0 - Little Endian */
        uint32_t id                    : 16; /**< [ 15:  0](RO) Vendor-specific ID. Indicates the ThunderX family VSEC ID. */
        uint32_t rev                   : 4;  /**< [ 19: 16](RO) Vendor-specific revision. */
        uint32_t len                   : 12; /**< [ 31: 20](RO) Number of bytes in the entire VSEC structure including PCCPF_XXX_VSEC_CAP_HDR. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_id_s cn; */
} bdk_pccpf_xxx_vsec_id_t;

#define BDK_PCCPF_XXX_VSEC_ID BDK_PCCPF_XXX_VSEC_ID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_ID_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x104;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x104;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x10c;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_ID", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_ID bdk_pccpf_xxx_vsec_id_t
#define bustype_BDK_PCCPF_XXX_VSEC_ID BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_ID "PCCPF_XXX_VSEC_ID"
#define busnum_BDK_PCCPF_XXX_VSEC_ID 0
#define arguments_BDK_PCCPF_XXX_VSEC_ID -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sctl
 *
 * PCC PF Vendor-Specific Secure Control Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t reserved_6_15         : 10;
        uint32_t node                  : 2;  /**< [  5:  4](SRO) Reserved. */
        uint32_t ea                    : 1;  /**< [  3:  3](SRO) Reserved. */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
#else /* Word 0 - Little Endian */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t ea                    : 1;  /**< [  3:  3](SRO) Reserved. */
        uint32_t node                  : 2;  /**< [  5:  4](SRO) Reserved. */
        uint32_t reserved_6_15         : 10;
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sctl_s cn88xxp1; */
    struct bdk_pccpf_xxx_vsec_sctl_cn81xx
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t reserved_6_15         : 10;
        uint32_t node                  : 2;  /**< [  5:  4](SR/W/H) Node number. */
        uint32_t ea                    : 1;  /**< [  3:  3](SR/W) Enable PCI enhanced allocation.

                                                                 0 = Addresses are discovered using standard BARs, however while the BARs are
                                                                 writable the value is ignored.  PCCPF_XXX_EA_ENTRY() still indicates the BARs
                                                                 but software will not read them as PCCPF_XXX_EA_CAP_HDR is not linked into the
                                                                 capabilities list (see PCCPF_XXX_E_CAP_HDR[NCP], PCCPF_XXX_MSIX_CAP_HDR[NCP]).

                                                                 1 = Addresses are discovered using enhanced allocation and PCCPF_XXX_EA_ENTRY().
                                                                 Standard BARs are read-only zero (PCCPF_XXX_BAR0L, PCCPF_XXX_BAR0U,
                                                                 PCCPF_XXX_BAR2L, PCCPF_XXX_BAR2U, PCCPF_XXX_BAR4L, PCCPF_XXX_BAR4U,
                                                                 PCCPF_XXX_SRIOV_BAR0L, PCCPF_XXX_SRIOV_BAR0U, PCCPF_XXX_SRIOV_BAR2L,
                                                                 PCCPF_XXX_SRIOV_BAR2U, PCCPF_XXX_SRIOV_BAR4L, PCCPF_XXX_SRIOV_BAR4U). */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
#else /* Word 0 - Little Endian */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t ea                    : 1;  /**< [  3:  3](SR/W) Enable PCI enhanced allocation.

                                                                 0 = Addresses are discovered using standard BARs, however while the BARs are
                                                                 writable the value is ignored.  PCCPF_XXX_EA_ENTRY() still indicates the BARs
                                                                 but software will not read them as PCCPF_XXX_EA_CAP_HDR is not linked into the
                                                                 capabilities list (see PCCPF_XXX_E_CAP_HDR[NCP], PCCPF_XXX_MSIX_CAP_HDR[NCP]).

                                                                 1 = Addresses are discovered using enhanced allocation and PCCPF_XXX_EA_ENTRY().
                                                                 Standard BARs are read-only zero (PCCPF_XXX_BAR0L, PCCPF_XXX_BAR0U,
                                                                 PCCPF_XXX_BAR2L, PCCPF_XXX_BAR2U, PCCPF_XXX_BAR4L, PCCPF_XXX_BAR4U,
                                                                 PCCPF_XXX_SRIOV_BAR0L, PCCPF_XXX_SRIOV_BAR0U, PCCPF_XXX_SRIOV_BAR2L,
                                                                 PCCPF_XXX_SRIOV_BAR2U, PCCPF_XXX_SRIOV_BAR4L, PCCPF_XXX_SRIOV_BAR4U). */
        uint32_t node                  : 2;  /**< [  5:  4](SR/W/H) Node number. */
        uint32_t reserved_6_15         : 10;
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
#endif /* Word 0 - End */
    } cn81xx;
    /* struct bdk_pccpf_xxx_vsec_sctl_cn81xx cn83xx; */
    struct bdk_pccpf_xxx_vsec_sctl_cn88xxp2
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t reserved_6_15         : 10;
        uint32_t node                  : 2;  /**< [  5:  4](SR/W/H) Node number. Added in pass 2. */
        uint32_t ea                    : 1;  /**< [  3:  3](SR/W) Enable PCI enhanced allocation.

                                                                 0 = Addresses are discovered using standard BARs, however while the BARs are
                                                                 writable the value is ignored.  PCCPF_XXX_EA_ENTRY() still indicates the BARs
                                                                 but software will not read them as PCCPF_XXX_EA_CAP_HDR is not linked into the
                                                                 capabilities list (see PCCPF_XXX_E_CAP_HDR[NCP], PCCPF_XXX_MSIX_CAP_HDR[NCP]).

                                                                 1 = Addresses are discovered using enhanced allocation and PCCPF_XXX_EA_ENTRY().
                                                                 Standard BARs are read-only zero (PCCPF_XXX_BAR0L, PCCPF_XXX_BAR0U,
                                                                 PCCPF_XXX_BAR2L, PCCPF_XXX_BAR2U, PCCPF_XXX_BAR4L, PCCPF_XXX_BAR4U,
                                                                 PCCPF_XXX_SRIOV_BAR0L, PCCPF_XXX_SRIOV_BAR0U, PCCPF_XXX_SRIOV_BAR2L,
                                                                 PCCPF_XXX_SRIOV_BAR2U, PCCPF_XXX_SRIOV_BAR4L, PCCPF_XXX_SRIOV_BAR4U).

                                                                 Added in pass 2. */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
#else /* Word 0 - Little Endian */
        uint32_t msix_phys             : 1;  /**< [  0:  0](SR/W) MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
        uint32_t msix_sec              : 1;  /**< [  1:  1](SR/W) All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC()_ADDR[SECVEC]) for all vectors in the block. */
        uint32_t bcst_rsp              : 1;  /**< [  2:  2](SR/W) Reserved, must be 0.
                                                                 Internal:
                                                                 Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
        uint32_t ea                    : 1;  /**< [  3:  3](SR/W) Enable PCI enhanced allocation.

                                                                 0 = Addresses are discovered using standard BARs, however while the BARs are
                                                                 writable the value is ignored.  PCCPF_XXX_EA_ENTRY() still indicates the BARs
                                                                 but software will not read them as PCCPF_XXX_EA_CAP_HDR is not linked into the
                                                                 capabilities list (see PCCPF_XXX_E_CAP_HDR[NCP], PCCPF_XXX_MSIX_CAP_HDR[NCP]).

                                                                 1 = Addresses are discovered using enhanced allocation and PCCPF_XXX_EA_ENTRY().
                                                                 Standard BARs are read-only zero (PCCPF_XXX_BAR0L, PCCPF_XXX_BAR0U,
                                                                 PCCPF_XXX_BAR2L, PCCPF_XXX_BAR2U, PCCPF_XXX_BAR4L, PCCPF_XXX_BAR4U,
                                                                 PCCPF_XXX_SRIOV_BAR0L, PCCPF_XXX_SRIOV_BAR0U, PCCPF_XXX_SRIOV_BAR2L,
                                                                 PCCPF_XXX_SRIOV_BAR2U, PCCPF_XXX_SRIOV_BAR4L, PCCPF_XXX_SRIOV_BAR4U).

                                                                 Added in pass 2. */
        uint32_t node                  : 2;  /**< [  5:  4](SR/W/H) Node number. Added in pass 2. */
        uint32_t reserved_6_15         : 10;
        uint32_t rid                   : 8;  /**< [ 23: 16](SR/W) Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
        uint32_t nxtfn_s               : 8;  /**< [ 31: 24](SR/W) For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
#endif /* Word 0 - End */
    } cn88xxp2;
} bdk_pccpf_xxx_vsec_sctl_t;

#define BDK_PCCPF_XXX_VSEC_SCTL BDK_PCCPF_XXX_VSEC_SCTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SCTL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x10c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x10c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x114;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SCTL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SCTL bdk_pccpf_xxx_vsec_sctl_t
#define bustype_BDK_PCCPF_XXX_VSEC_SCTL BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SCTL "PCCPF_XXX_VSEC_SCTL"
#define busnum_BDK_PCCPF_XXX_VSEC_SCTL 0
#define arguments_BDK_PCCPF_XXX_VSEC_SCTL -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar0l
 *
 * PCC PF Vendor-Specific SR-IOV Address 0 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar0l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar0l_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar0l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x128;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x128;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x130;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR0L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L bdk_pccpf_xxx_vsec_sriov_bar0l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L "PCCPF_XXX_VSEC_SRIOV_BAR0L"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar0u
 *
 * PCC PF Vendor-Specific SR-IOV Address 0 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar0u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar0_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar0u_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar0u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x12c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x12c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x134;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR0U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U bdk_pccpf_xxx_vsec_sriov_bar0u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U "PCCPF_XXX_VSEC_SRIOV_BAR0U"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar2l
 *
 * PCC PF Vendor-Specific SR-IOV Address 2 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar2l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar2l_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar2l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x130;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x130;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x138;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR2L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L bdk_pccpf_xxx_vsec_sriov_bar2l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L "PCCPF_XXX_VSEC_SRIOV_BAR2L"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar2u
 *
 * PCC PF Vendor-Specific SR-IOV Address 2 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar2u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar2_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar2u_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar2u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x134;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x134;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x13c;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR2U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U bdk_pccpf_xxx_vsec_sriov_bar2u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U "PCCPF_XXX_VSEC_SRIOV_BAR2U"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar4l
 *
 * PCC PF Vendor-Specific SR-IOV Address 4 Lower Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar4l_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_offset. */
        uint32_t reserved_0_15         : 16;
#else /* Word 0 - Little Endian */
        uint32_t reserved_0_15         : 16;
        uint32_t lbab                  : 16; /**< [ 31: 16](RO) Lower bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4L[LBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar4l_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar4l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x138;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x138;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x140;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR4L", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L bdk_pccpf_xxx_vsec_sriov_bar4l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L "PCCPF_XXX_VSEC_SRIOV_BAR4L"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L -1,-1,-1,-1

/**
 * Register (PCCPF) pccpf_xxx_vsec_sriov_bar4u
 *
 * PCC PF Vendor-Specific SR-IOV Address 4 Upper Register
 */
typedef union
{
    uint32_t u;
    struct bdk_pccpf_xxx_vsec_sriov_bar4u_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_offset. */
#else /* Word 0 - Little Endian */
        uint32_t ubab                  : 32; /**< [ 31:  0](RO) Upper bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4U[UBAB].

                                                                 Internal:
                                                                 From PCC's tie__vfbar4_offset. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pccpf_xxx_vsec_sriov_bar4u_s cn; */
} bdk_pccpf_xxx_vsec_sriov_bar4u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x13c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x13c;
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 0x144;
    __bdk_csr_fatal("PCCPF_XXX_VSEC_SRIOV_BAR4U", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U bdk_pccpf_xxx_vsec_sriov_bar4u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U BDK_CSR_TYPE_PCCPF
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U "PCCPF_XXX_VSEC_SRIOV_BAR4U"
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U -1,-1,-1,-1

#endif /* __BDK_CSRS_PCCPF_H__ */

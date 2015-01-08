#ifndef __BDK_CSRS_PCCPF__
#define __BDK_CSRS_PCCPF__
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

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration PCC_DEV_CON_E
 *
 * PCC Device Connection Enumeration
 * Enumerates where the device is connected in the topology. Software must rely on discovery and
 * not use this enumeration as the values will vary by product, and the mnemonics are a super-set
 * of the devices available. The value of the enumeration is formatted as defined by
 * PCC_DEV_CON_S.
 */
enum pcc_dev_con_e {
	PCC_DEV_CON_E_BGX0 = 0x180,
	PCC_DEV_CON_E_BGX1 = 0x181,
	PCC_DEV_CON_E_DAP = 0x102,
	PCC_DEV_CON_E_DFA = 0x400,
	PCC_DEV_CON_E_FUSF = 0x104,
	PCC_DEV_CON_E_GIC = 0x18,
	PCC_DEV_CON_E_GPIO = 0x30,
	PCC_DEV_CON_E_GSER0 = 0x1e0,
	PCC_DEV_CON_E_GSER1 = 0x1e1,
	PCC_DEV_CON_E_GSER10 = 0x1ea,
	PCC_DEV_CON_E_GSER11 = 0x1eb,
	PCC_DEV_CON_E_GSER12 = 0x1ec,
	PCC_DEV_CON_E_GSER13 = 0x1ed,
	PCC_DEV_CON_E_GSER2 = 0x1e2,
	PCC_DEV_CON_E_GSER3 = 0x1e3,
	PCC_DEV_CON_E_GSER4 = 0x1e4,
	PCC_DEV_CON_E_GSER5 = 0x1e5,
	PCC_DEV_CON_E_GSER6 = 0x1e6,
	PCC_DEV_CON_E_GSER7 = 0x1e7,
	PCC_DEV_CON_E_GSER8 = 0x1e8,
	PCC_DEV_CON_E_GSER9 = 0x1e9,
	PCC_DEV_CON_E_GTI = 0x20,
	PCC_DEV_CON_E_IOBN0 = 0x158,
	PCC_DEV_CON_E_IOBN1 = 0x159,
	PCC_DEV_CON_E_KEY = 0x10d,
	PCC_DEV_CON_E_L2C = 0x109,
	PCC_DEV_CON_E_L2C_CBC0 = 0x138,
	PCC_DEV_CON_E_L2C_CBC1 = 0x139,
	PCC_DEV_CON_E_L2C_CBC2 = 0x13a,
	PCC_DEV_CON_E_L2C_CBC3 = 0x13b,
	PCC_DEV_CON_E_L2C_MCI0 = 0x13c,
	PCC_DEV_CON_E_L2C_MCI1 = 0x13d,
	PCC_DEV_CON_E_L2C_MCI2 = 0x13e,
	PCC_DEV_CON_E_L2C_MCI3 = 0x13f,
	PCC_DEV_CON_E_L2C_TAD0 = 0x130,
	PCC_DEV_CON_E_L2C_TAD1 = 0x131,
	PCC_DEV_CON_E_L2C_TAD2 = 0x132,
	PCC_DEV_CON_E_L2C_TAD3 = 0x133,
	PCC_DEV_CON_E_L2C_TAD4 = 0x134,
	PCC_DEV_CON_E_L2C_TAD5 = 0x135,
	PCC_DEV_CON_E_L2C_TAD6 = 0x136,
	PCC_DEV_CON_E_L2C_TAD7 = 0x137,
	PCC_DEV_CON_E_LMC0 = 0x150,
	PCC_DEV_CON_E_LMC1 = 0x151,
	PCC_DEV_CON_E_LMC2 = 0x152,
	PCC_DEV_CON_E_LMC3 = 0x153,
	PCC_DEV_CON_E_MIO_BOOT = 0x10e,
	PCC_DEV_CON_E_MIO_EMM = 0x10c,
	PCC_DEV_CON_E_MIO_FUS = 0x103,
	PCC_DEV_CON_E_MIO_PTP = 0x40,
	PCC_DEV_CON_E_MIO_TWS0 = 0x148,
	PCC_DEV_CON_E_MIO_TWS1 = 0x149,
	PCC_DEV_CON_E_MIO_TWS2 = 0x14a,
	PCC_DEV_CON_E_MIO_TWS3 = 0x14b,
	PCC_DEV_CON_E_MIO_TWS4 = 0x14c,
	PCC_DEV_CON_E_MIO_TWS5 = 0x14d,
	PCC_DEV_CON_E_MPI = 0x38,
	PCC_DEV_CON_E_MRML = 0x100,
	PCC_DEV_CON_E_NCSI = 0x108,
	PCC_DEV_CON_E_NIC = 0x20100,
	PCC_DEV_CON_E_OCLA0 = 0x160,
	PCC_DEV_CON_E_OCLA1 = 0x161,
	PCC_DEV_CON_E_OCLA2 = 0x162,
	PCC_DEV_CON_E_OCLA3 = 0x163,
	PCC_DEV_CON_E_OCLA4 = 0x164,
	PCC_DEV_CON_E_OCX = 0x105,
	PCC_DEV_CON_E_PCCBR_DFA = 0xb0,
	PCC_DEV_CON_E_PCCBR_MRML = 0x8,
	PCC_DEV_CON_E_PCCBR_NIC = 0x20010,
	PCC_DEV_CON_E_PCCBR_RAD = 0xa0,
	PCC_DEV_CON_E_PCCBR_ZIP = 0xa8,
	PCC_DEV_CON_E_PCIERC0 = 0x10080,
	PCC_DEV_CON_E_PCIERC1 = 0x10090,
	PCC_DEV_CON_E_PCIERC2 = 0x100a0,
	PCC_DEV_CON_E_PCIERC3 = 0x30080,
	PCC_DEV_CON_E_PCIERC4 = 0x30090,
	PCC_DEV_CON_E_PCIERC5 = 0x300a0,
	PCC_DEV_CON_E_PEM0 = 0x170,
	PCC_DEV_CON_E_PEM1 = 0x171,
	PCC_DEV_CON_E_PEM2 = 0x172,
	PCC_DEV_CON_E_PEM3 = 0x173,
	PCC_DEV_CON_E_PEM4 = 0x174,
	PCC_DEV_CON_E_PEM5 = 0x175,
	PCC_DEV_CON_E_RAD = 0x200,
	PCC_DEV_CON_E_RNM = 0x48,
	PCC_DEV_CON_E_RST = 0x101,
	PCC_DEV_CON_E_SATA0 = 0x10020,
	PCC_DEV_CON_E_SATA1 = 0x10028,
	PCC_DEV_CON_E_SATA10 = 0x30030,
	PCC_DEV_CON_E_SATA11 = 0x30038,
	PCC_DEV_CON_E_SATA12 = 0x30040,
	PCC_DEV_CON_E_SATA13 = 0x30048,
	PCC_DEV_CON_E_SATA14 = 0x30050,
	PCC_DEV_CON_E_SATA15 = 0x30058,
	PCC_DEV_CON_E_SATA2 = 0x10030,
	PCC_DEV_CON_E_SATA3 = 0x10038,
	PCC_DEV_CON_E_SATA4 = 0x10040,
	PCC_DEV_CON_E_SATA5 = 0x10048,
	PCC_DEV_CON_E_SATA6 = 0x10050,
	PCC_DEV_CON_E_SATA7 = 0x10058,
	PCC_DEV_CON_E_SATA8 = 0x30020,
	PCC_DEV_CON_E_SATA9 = 0x30028,
	PCC_DEV_CON_E_SGP = 0x10a,
	PCC_DEV_CON_E_SLI0 = 0x10010,
	PCC_DEV_CON_E_SLI1 = 0x30010,
	PCC_DEV_CON_E_SMI = 0x10b,
	PCC_DEV_CON_E_SMMU0 = 0x10,
	PCC_DEV_CON_E_SMMU1 = 0x10008,
	PCC_DEV_CON_E_SMMU2 = 0x20008,
	PCC_DEV_CON_E_SMMU3 = 0x30008,
	PCC_DEV_CON_E_TNS = 0x20018,
	PCC_DEV_CON_E_UAA0 = 0x140,
	PCC_DEV_CON_E_UAA1 = 0x141,
	PCC_DEV_CON_E_USBH0 = 0x80,
	PCC_DEV_CON_E_USBH1 = 0x88,
	PCC_DEV_CON_E_VRM0 = 0x144,
	PCC_DEV_CON_E_VRM1 = 0x145,
	PCC_DEV_CON_E_ZIP = 0x300,
	PCC_DEV_CON_E_ENUM_LAST = 0x300a1,
};

/**
 * Enumeration PCC_DEV_IDL_E
 *
 * PCC Device ID Low Enumeration
 * Enumerates the values of the PCI configuration header Device ID and Subsystem Device ID bits
 * \<7:0\>. The value of the enumeration is formatted as defined by PCC_DEV_IDL_S.
 */
enum pcc_dev_idl_e {
	PCC_DEV_IDL_E_BGX = 0x26,
	PCC_DEV_IDL_E_BGX_CLASS_CODE = 0x28000,
	PCC_DEV_IDL_E_CHIP = 0x0,
	PCC_DEV_IDL_E_CPT = 0x40,
	PCC_DEV_IDL_E_CPT_CLASS_CODE = 0x108000,
	PCC_DEV_IDL_E_DAP = 0x2c,
	PCC_DEV_IDL_E_DAP_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_DFA = 0x19,
	PCC_DEV_IDL_E_DFA_CLASS_CODE = 0x120000,
	PCC_DEV_IDL_E_FUSF = 0x32,
	PCC_DEV_IDL_E_FUSF_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_GIC = 0x9,
	PCC_DEV_IDL_E_GIC_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_GPIO = 0xa,
	PCC_DEV_IDL_E_GPIO_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_GSER = 0x25,
	PCC_DEV_IDL_E_GSER_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_GTI = 0x17,
	PCC_DEV_IDL_E_GTI_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_IOBN = 0x27,
	PCC_DEV_IDL_E_IOBN_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_KEY = 0x16,
	PCC_DEV_IDL_E_KEY_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_L2C = 0x21,
	PCC_DEV_IDL_E_L2C_CBC = 0x2f,
	PCC_DEV_IDL_E_L2C_CBC_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_L2C_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_L2C_MCI = 0x30,
	PCC_DEV_IDL_E_L2C_MCI_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_L2C_TAD = 0x2e,
	PCC_DEV_IDL_E_L2C_TAD_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_LMC = 0x22,
	PCC_DEV_IDL_E_LMC_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_MIO_BOOT = 0x11,
	PCC_DEV_IDL_E_MIO_BOOT_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_MIO_EMM = 0x10,
	PCC_DEV_IDL_E_MIO_EMM_CLASS_CODE = 0x58000,
	PCC_DEV_IDL_E_MIO_FUS = 0x31,
	PCC_DEV_IDL_E_MIO_FUS_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_MIO_PTP = 0xc,
	PCC_DEV_IDL_E_MIO_PTP_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_MIO_TWS = 0x12,
	PCC_DEV_IDL_E_MIO_TWS_CLASS_CODE = 0xc8000,
	PCC_DEV_IDL_E_MIX = 0xd,
	PCC_DEV_IDL_E_MIX_CLASS_CODE = 0x28000,
	PCC_DEV_IDL_E_MPI = 0xb,
	PCC_DEV_IDL_E_MPI_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_MRML = 0x1,
	PCC_DEV_IDL_E_MRML_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_NCSI = 0x29,
	PCC_DEV_IDL_E_NCSI_CLASS_CODE = 0x28000,
	PCC_DEV_IDL_E_NIC = 0x1e,
	PCC_DEV_IDL_E_NIC_CLASS_CODE = 0x20000,
	PCC_DEV_IDL_E_NIC_VF = 0x34,
	PCC_DEV_IDL_E_NIC_VF_CLASS_CODE = 0x20000,
	PCC_DEV_IDL_E_OCLA = 0x23,
	PCC_DEV_IDL_E_OCLA_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_OCX = 0x13,
	PCC_DEV_IDL_E_OCX_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_OSM = 0x24,
	PCC_DEV_IDL_E_OSM_CLASS_CODE = 0x120000,
	PCC_DEV_IDL_E_PCCBR = 0x2,
	PCC_DEV_IDL_E_PCCBR_CLASS_CODE = 0x60400,
	PCC_DEV_IDL_E_PCIERC = 0x2d,
	PCC_DEV_IDL_E_PCIERC_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_PEM = 0x20,
	PCC_DEV_IDL_E_PEM_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_RAD = 0x1d,
	PCC_DEV_IDL_E_RAD_CLASS_CODE = 0x10400,
	PCC_DEV_IDL_E_RNM = 0x18,
	PCC_DEV_IDL_E_RNM_CLASS_CODE = 0x120000,
	PCC_DEV_IDL_E_RNM_VF = 0x33,
	PCC_DEV_IDL_E_RNM_VF_CLASS_CODE = 0x120000,
	PCC_DEV_IDL_E_RST = 0xe,
	PCC_DEV_IDL_E_RST_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_SATA = 0x1c,
	PCC_DEV_IDL_E_SATA_CLASS_CODE = 0x10601,
	PCC_DEV_IDL_E_SGP = 0x2a,
	PCC_DEV_IDL_E_SGP_CLASS_CODE = 0xc8000,
	PCC_DEV_IDL_E_SLI = 0x15,
	PCC_DEV_IDL_E_SLI_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_SMI = 0x2b,
	PCC_DEV_IDL_E_SMI_CLASS_CODE = 0xc8000,
	PCC_DEV_IDL_E_SMMU = 0x8,
	PCC_DEV_IDL_E_SMMU_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_TNS = 0x1f,
	PCC_DEV_IDL_E_TNS_CLASS_CODE = 0x28000,
	PCC_DEV_IDL_E_UAA = 0xf,
	PCC_DEV_IDL_E_UAA_CLASS_CODE = 0x78000,
	PCC_DEV_IDL_E_USBH = 0x1b,
	PCC_DEV_IDL_E_USBH_CLASS_CODE = 0xc0330,
	PCC_DEV_IDL_E_VRM = 0x14,
	PCC_DEV_IDL_E_VRM_CLASS_CODE = 0x88000,
	PCC_DEV_IDL_E_ZIP = 0x1a,
	PCC_DEV_IDL_E_ZIP_CLASS_CODE = 0x120000,
	PCC_DEV_IDL_E_ENUM_LAST = 0x120001,
};

/**
 * Enumeration PCC_PIDR_PARTNUM0_E
 *
 * PCC PIDR Part Number 0 Enumeration
 * When *_PIDR1[PARTNUM1] = PCC_PIDR_PARTNUM1_E::COMP, enumerates the values of Cavium-
 * assigned CoreSight PIDR part number 0 fields.
 * For example SMMU()_PIDR0[PARTNUM0].
 */
enum pcc_pidr_partnum0_e {
	PCC_PIDR_PARTNUM0_E_CTI = 0xd,
	PCC_PIDR_PARTNUM0_E_DBG = 0xe,
	PCC_PIDR_PARTNUM0_E_GICD = 0x2,
	PCC_PIDR_PARTNUM0_E_GICR = 0x1,
	PCC_PIDR_PARTNUM0_E_GITS = 0x3,
	PCC_PIDR_PARTNUM0_E_GTI_BZ = 0x4,
	PCC_PIDR_PARTNUM0_E_GTI_CC = 0x5,
	PCC_PIDR_PARTNUM0_E_GTI_CTL = 0x6,
	PCC_PIDR_PARTNUM0_E_GTI_RD = 0x7,
	PCC_PIDR_PARTNUM0_E_GTI_WC = 0x8,
	PCC_PIDR_PARTNUM0_E_GTI_WR = 0x9,
	PCC_PIDR_PARTNUM0_E_NONE = 0x0,
	PCC_PIDR_PARTNUM0_E_PMU = 0xa,
	PCC_PIDR_PARTNUM0_E_SMMU = 0xb,
	PCC_PIDR_PARTNUM0_E_SYSCTI = 0xf,
	PCC_PIDR_PARTNUM0_E_TRC = 0x10,
	PCC_PIDR_PARTNUM0_E_UAA = 0xc,
	PCC_PIDR_PARTNUM0_E_ENUM_LAST = 0x11,
};

/**
 * Enumeration PCC_PIDR_PARTNUM1_E
 *
 * PCC PIDR Part Number 1 Enumeration
 * Enumerates the values of Cavium-assigned CoreSight PIDR PARTNUM1 fields, for example
 * SMMU()_PIDR1[PARTNUM1].
 */
enum pcc_pidr_partnum1_e {
	PCC_PIDR_PARTNUM1_E_COMP = 0x2,
	PCC_PIDR_PARTNUM1_E_PROD = 0x1,
	PCC_PIDR_PARTNUM1_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration PCC_PROD_E
 *
 * PCC Device ID Product Enumeration
 * Enumerates the values of the PCI configuration header Device ID and Subsystem Device ID bits
 * \<15:8\>.
 */
enum pcc_prod_e {
	PCC_PROD_E_CN83XX = 0xa3,
	PCC_PROD_E_CN85XX = 0xa2,
	PCC_PROD_E_CN88XX = 0xa1,
	PCC_PROD_E_GEN = 0xa0,
	PCC_PROD_E_ENUM_LAST = 0xa4,
};

/**
 * Enumeration PCC_VENDOR_E
 *
 * PCC Vendor ID Enumeration
 * Enumerates the values of the PCI configuration header vendor ID.
 */
enum pcc_vendor_e {
	PCC_VENDOR_E_CAVIUM = 0x177d,
	PCC_VENDOR_E_ENUM_LAST = 0x177e,
};


/**
 * Structure PCC_DEV_CON_S
 *
 * PCC Device Connection Structure
 * Defines the components of the PCC device connection values enumerated by PCC_DEV_CON_E,
 * using ARI format.
 */
union pcc_dev_con_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46; /**< [ 63: 18] Reserved */
		uint64_t ecam                        : 2;  /**< [ 17: 16] ECAM number/NCB bus number. */
		uint64_t bus                         : 8;  /**< [ 15:  8] ECAM bus number. */
		uint64_t func                        : 8;  /**< [  7:  0] For ARI devices (when bus is non-zero), an eight-bit RSL function number.

                                                                 For non-ARI devices (when bus is zero), \<7:3\> is the device number, \<2:0\> the function
                                                                 number. */
#else
		uint64_t func                        : 8;  /**< [  7:  0] For ARI devices (when bus is non-zero), an eight-bit RSL function number.

                                                                 For non-ARI devices (when bus is zero), \<7:3\> is the device number, \<2:0\> the function
                                                                 number. */
		uint64_t bus                         : 8;  /**< [ 15:  8] ECAM bus number. */
		uint64_t ecam                        : 2;  /**< [ 17: 16] ECAM number/NCB bus number. */
		uint64_t reserved_18_63              : 46; /**< [ 63: 18] Reserved */
#endif
	} s;
};

/**
 * Structure PCC_DEV_IDL_S
 *
 * PCC Device ID Low Structure
 * Defines the components of the PCC device-id low values enumerated by PCC_DEV_IDL_E.
 */
union pcc_dev_idl_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40; /**< [ 63: 24] Reserved */
		uint64_t bcc                         : 8;  /**< [ 23: 16] Base class code. */
		uint64_t sc                          : 8;  /**< [ 15:  8] Subclass code. */
		uint64_t pi                          : 8;  /**< [  7:  0] Programming interface. */
#else
		uint64_t pi                          : 8;  /**< [  7:  0] Programming interface. */
		uint64_t sc                          : 8;  /**< [ 15:  8] Subclass code. */
		uint64_t bcc                         : 8;  /**< [ 23: 16] Base class code. */
		uint64_t reserved_24_63              : 40; /**< [ 63: 24] Reserved */
#endif
	} s;
};


/**
 * PCCPF - pccpf_xxx_ari_cap_hdr
 */
typedef union bdk_pccpf_xxx_ari_cap_hdr {
	uint32_t u;
	struct bdk_pccpf_xxx_ari_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. Points to PCCPF_XXX_VSEC_CAP_HDR. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t ariid                       : 16; /**< RO - PCIE extended capability. */
#else
		uint32_t ariid                       : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccpf_xxx_ari_cap_hdr_s cn88xx; */
	/* struct bdk_pccpf_xxx_ari_cap_hdr_s cn88xxp1; */
} bdk_pccpf_xxx_ari_cap_hdr_t;

#define BDK_PCCPF_XXX_ARI_CAP_HDR BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_ARI_CAP_HDR_FUNC(void)
{
	return 0x0000000000000100ull;
}
#define typedef_BDK_PCCPF_XXX_ARI_CAP_HDR bdk_pccpf_xxx_ari_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_ARI_CAP_HDR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_ARI_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_ARI_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_ARI_CAP_HDR "PCCPF_XXX_ARI_CAP_HDR"


/**
 * PCCPF - pccpf_xxx_bar0l
 */
typedef union bdk_pccpf_xxx_bar0l {
	uint32_t u;
	struct bdk_pccpf_xxx_bar0l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar0l_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar0l_s       cn88xxp1; */
} bdk_pccpf_xxx_bar0l_t;

#define BDK_PCCPF_XXX_BAR0L BDK_PCCPF_XXX_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR0L_FUNC(void)
{
	return 0x0000000000000010ull;
}
#define typedef_BDK_PCCPF_XXX_BAR0L bdk_pccpf_xxx_bar0l_t
#define bustype_BDK_PCCPF_XXX_BAR0L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR0L 0
#define arguments_BDK_PCCPF_XXX_BAR0L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR0L "PCCPF_XXX_BAR0L"


/**
 * PCCPF - pccpf_xxx_bar0u
 */
typedef union bdk_pccpf_xxx_bar0u {
	uint32_t u;
	struct bdk_pccpf_xxx_bar0u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Contains the upper 32 bits of the BAR 0 base address. Bits corresponding to address bits
                                                                 less than the size of the BAR are read-as-zero, other bits are read-write only to allow
                                                                 determining the size of the BAR. Hardware has fixed address decoding and does not use this
                                                                 BAR for address decoding. After sizing, for proper software behavior, software must
                                                                 restore the register value, where the proper value may be read from PCCPF_XXX_VSEC_BAR0U,
                                                                 with software writing the node number into the field bits corresponding to address bits
                                                                 \<45:44\>. INTERNAL: From PCC's tie__pfbar0_rbsz and tie__pfbar0_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar0u_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar0u_s       cn88xxp1; */
} bdk_pccpf_xxx_bar0u_t;

#define BDK_PCCPF_XXX_BAR0U BDK_PCCPF_XXX_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR0U_FUNC(void)
{
	return 0x0000000000000014ull;
}
#define typedef_BDK_PCCPF_XXX_BAR0U bdk_pccpf_xxx_bar0u_t
#define bustype_BDK_PCCPF_XXX_BAR0U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR0U 0
#define arguments_BDK_PCCPF_XXX_BAR0U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR0U "PCCPF_XXX_BAR0U"


/**
 * PCCPF - pccpf_xxx_bar2l
 *
 * This register is non-zero only for those devices needing two register BARs.
 *
 */
typedef union bdk_pccpf_xxx_bar2l {
	uint32_t u;
	struct bdk_pccpf_xxx_bar2l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar2l_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar2l_s       cn88xxp1; */
} bdk_pccpf_xxx_bar2l_t;

#define BDK_PCCPF_XXX_BAR2L BDK_PCCPF_XXX_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR2L_FUNC(void)
{
	return 0x0000000000000018ull;
}
#define typedef_BDK_PCCPF_XXX_BAR2L bdk_pccpf_xxx_bar2l_t
#define bustype_BDK_PCCPF_XXX_BAR2L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR2L 0
#define arguments_BDK_PCCPF_XXX_BAR2L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR2L "PCCPF_XXX_BAR2L"


/**
 * PCCPF - pccpf_xxx_bar2u
 *
 * This register is non-zero only for those devices needing two register BARs.
 *
 */
typedef union bdk_pccpf_xxx_bar2u {
	uint32_t u;
	struct bdk_pccpf_xxx_bar2u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Contains the upper 32 bits of the BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar2_rbsz and tie__pfbar2_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar2u_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar2u_s       cn88xxp1; */
} bdk_pccpf_xxx_bar2u_t;

#define BDK_PCCPF_XXX_BAR2U BDK_PCCPF_XXX_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR2U_FUNC(void)
{
	return 0x000000000000001Cull;
}
#define typedef_BDK_PCCPF_XXX_BAR2U bdk_pccpf_xxx_bar2u_t
#define bustype_BDK_PCCPF_XXX_BAR2U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR2U 0
#define arguments_BDK_PCCPF_XXX_BAR2U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR2U "PCCPF_XXX_BAR2U"


/**
 * PCCPF - pccpf_xxx_bar4l
 *
 * This register is non-zero only for MSI-X devices.
 *
 */
typedef union bdk_pccpf_xxx_bar4l {
	uint32_t u;
	struct bdk_pccpf_xxx_bar4l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory space indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar4l_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar4l_s       cn88xxp1; */
} bdk_pccpf_xxx_bar4l_t;

#define BDK_PCCPF_XXX_BAR4L BDK_PCCPF_XXX_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR4L_FUNC(void)
{
	return 0x0000000000000020ull;
}
#define typedef_BDK_PCCPF_XXX_BAR4L bdk_pccpf_xxx_bar4l_t
#define bustype_BDK_PCCPF_XXX_BAR4L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR4L 0
#define arguments_BDK_PCCPF_XXX_BAR4L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR4L "PCCPF_XXX_BAR4L"


/**
 * PCCPF - pccpf_xxx_bar4u
 *
 * This register is non-zero only for MSI-X devices.
 *
 */
typedef union bdk_pccpf_xxx_bar4u {
	uint32_t u;
	struct bdk_pccpf_xxx_bar4u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Contains the upper 32 bits of the BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar4_rbsz and tie__pfbar4_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_bar4u_s       cn88xx; */
	/* struct bdk_pccpf_xxx_bar4u_s       cn88xxp1; */
} bdk_pccpf_xxx_bar4u_t;

#define BDK_PCCPF_XXX_BAR4U BDK_PCCPF_XXX_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_BAR4U_FUNC(void)
{
	return 0x0000000000000024ull;
}
#define typedef_BDK_PCCPF_XXX_BAR4U bdk_pccpf_xxx_bar4u_t
#define bustype_BDK_PCCPF_XXX_BAR4U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_BAR4U 0
#define arguments_BDK_PCCPF_XXX_BAR4U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_BAR4U "PCCPF_XXX_BAR4U"


/**
 * PCCPF - pccpf_xxx_cap_ptr
 */
typedef union bdk_pccpf_xxx_cap_ptr {
	uint32_t u;
	struct bdk_pccpf_xxx_cap_ptr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_8_31               : 24;
		uint32_t cp                          : 8;  /**< RO - First capability pointer. Points to PCCPF_XXX_E_CAP_HDR. */
#else
		uint32_t cp                          : 8;
		uint32_t reserved_8_31               : 24;
#endif
	} s;
	/* struct bdk_pccpf_xxx_cap_ptr_s     cn88xx; */
	/* struct bdk_pccpf_xxx_cap_ptr_s     cn88xxp1; */
} bdk_pccpf_xxx_cap_ptr_t;

#define BDK_PCCPF_XXX_CAP_PTR BDK_PCCPF_XXX_CAP_PTR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CAP_PTR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CAP_PTR_FUNC(void)
{
	return 0x0000000000000034ull;
}
#define typedef_BDK_PCCPF_XXX_CAP_PTR bdk_pccpf_xxx_cap_ptr_t
#define bustype_BDK_PCCPF_XXX_CAP_PTR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_CAP_PTR 0
#define arguments_BDK_PCCPF_XXX_CAP_PTR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_CAP_PTR "PCCPF_XXX_CAP_PTR"


/**
 * PCCPF - pccpf_xxx_clsize
 */
typedef union bdk_pccpf_xxx_clsize {
	uint32_t u;
	struct bdk_pccpf_xxx_clsize_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bist                        : 8;  /**< RO - BIST. */
		uint32_t hdrtype                     : 8;  /**< RO - Header type. For RSL, 0x80 to indicate a multifunction device, else 0x0. Per the SR-IOV
                                                                 specification, VFs are not indicated as multifunction devices. */
		uint32_t lattim                      : 8;  /**< RO - Latency timer. */
		uint32_t clsize                      : 8;  /**< RO - Cacheline size. */
#else
		uint32_t clsize                      : 8;
		uint32_t lattim                      : 8;
		uint32_t hdrtype                     : 8;
		uint32_t bist                        : 8;
#endif
	} s;
	/* struct bdk_pccpf_xxx_clsize_s      cn88xx; */
	/* struct bdk_pccpf_xxx_clsize_s      cn88xxp1; */
} bdk_pccpf_xxx_clsize_t;

#define BDK_PCCPF_XXX_CLSIZE BDK_PCCPF_XXX_CLSIZE_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CLSIZE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CLSIZE_FUNC(void)
{
	return 0x000000000000000Cull;
}
#define typedef_BDK_PCCPF_XXX_CLSIZE bdk_pccpf_xxx_clsize_t
#define bustype_BDK_PCCPF_XXX_CLSIZE BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_CLSIZE 0
#define arguments_BDK_PCCPF_XXX_CLSIZE -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_CLSIZE "PCCPF_XXX_CLSIZE"


/**
 * PCCPF - pccpf_xxx_cmd
 */
typedef union bdk_pccpf_xxx_cmd {
	uint32_t u;
	struct bdk_pccpf_xxx_cmd_s {
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
	/* struct bdk_pccpf_xxx_cmd_s         cn88xx; */
	/* struct bdk_pccpf_xxx_cmd_s         cn88xxp1; */
} bdk_pccpf_xxx_cmd_t;

#define BDK_PCCPF_XXX_CMD BDK_PCCPF_XXX_CMD_FUNC()
static inline uint64_t BDK_PCCPF_XXX_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_CMD_FUNC(void)
{
	return 0x0000000000000004ull;
}
#define typedef_BDK_PCCPF_XXX_CMD bdk_pccpf_xxx_cmd_t
#define bustype_BDK_PCCPF_XXX_CMD BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_CMD 0
#define arguments_BDK_PCCPF_XXX_CMD -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_CMD "PCCPF_XXX_CMD"


/**
 * PCCPF - pccpf_xxx_e_cap_hdr
 */
typedef union bdk_pccpf_xxx_e_cap_hdr {
	uint32_t u;
	struct bdk_pccpf_xxx_e_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_20_31              : 12;
		uint32_t pciecv                      : 4;  /**< RO - PCIe capability version. */
		uint32_t ncp                         : 8;  /**< RO - First capability pointer. If MSI-X is supported, points to
                                                                 PCCPF_XXX_MSIX_CAP_HDR (0xB0), else 0x0. */
		uint32_t pcieid                      : 8;  /**< RO - PCIe capability ID. */
#else
		uint32_t pcieid                      : 8;
		uint32_t ncp                         : 8;
		uint32_t pciecv                      : 4;
		uint32_t reserved_20_31              : 12;
#endif
	} s;
	/* struct bdk_pccpf_xxx_e_cap_hdr_s   cn88xx; */
	/* struct bdk_pccpf_xxx_e_cap_hdr_s   cn88xxp1; */
} bdk_pccpf_xxx_e_cap_hdr_t;

#define BDK_PCCPF_XXX_E_CAP_HDR BDK_PCCPF_XXX_E_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_E_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_E_CAP_HDR_FUNC(void)
{
	return 0x0000000000000070ull;
}
#define typedef_BDK_PCCPF_XXX_E_CAP_HDR bdk_pccpf_xxx_e_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_E_CAP_HDR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_E_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_E_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_E_CAP_HDR "PCCPF_XXX_E_CAP_HDR"


/**
 * PCCPF - pccpf_xxx_id
 */
typedef union bdk_pccpf_xxx_id {
	uint32_t u;
	struct bdk_pccpf_xxx_id_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t devid                       : 16; /**< RO - Device ID. \<15:8\> is PCC_PROD_E::GEN. \<7:0\> enumerated by PCC_DEV_IDL_E. INTERNAL: Unit
                                                                 from PCC's tie__unitid. */
		uint32_t vendid                      : 16; /**< RO - Cavium's vendor ID. Enumerated by PCC_VENDOR_E::CAVIUM. */
#else
		uint32_t vendid                      : 16;
		uint32_t devid                       : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_id_s          cn88xx; */
	/* struct bdk_pccpf_xxx_id_s          cn88xxp1; */
} bdk_pccpf_xxx_id_t;

#define BDK_PCCPF_XXX_ID BDK_PCCPF_XXX_ID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_ID_FUNC(void)
{
	return 0x0000000000000000ull;
}
#define typedef_BDK_PCCPF_XXX_ID bdk_pccpf_xxx_id_t
#define bustype_BDK_PCCPF_XXX_ID BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_ID 0
#define arguments_BDK_PCCPF_XXX_ID -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_ID "PCCPF_XXX_ID"


/**
 * PCCPF - pccpf_xxx_msix_cap_hdr
 */
typedef union bdk_pccpf_xxx_msix_cap_hdr {
	uint32_t u;
	struct bdk_pccpf_xxx_msix_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t msixen                      : 1;  /**< R/W - MSI-X enable.
                                                                 0 = The MSI-X PBAs corresponding to this function are cleared.  Interrupt messages
                                                                 will not be issued.
                                                                 1 = Normal PBA and MSI-X delivery. */
		uint32_t funm                        : 1;  /**< R/W - Function mask.
                                                                 0 = Each vectors' mask bit determines whether the vector is masked or not.
                                                                 1 = All vectors associated with the function are masked, regardless of their respective
                                                                 per-vector mask bits.

                                                                 Setting or clearing FUNM has no effect on the state of the per-vector mask bits. */
		uint32_t reserved_27_29              : 3;
		uint32_t msixts                      : 11; /**< RO - MSI-X table size encoded as (table size - 1). INTERNAL: From PCC's MSIX_PF_VECS parameter. */
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
	/* struct bdk_pccpf_xxx_msix_cap_hdr_s cn88xx; */
	/* struct bdk_pccpf_xxx_msix_cap_hdr_s cn88xxp1; */
} bdk_pccpf_xxx_msix_cap_hdr_t;

#define BDK_PCCPF_XXX_MSIX_CAP_HDR BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_CAP_HDR_FUNC(void)
{
	return 0x00000000000000B0ull;
}
#define typedef_BDK_PCCPF_XXX_MSIX_CAP_HDR bdk_pccpf_xxx_msix_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_MSIX_CAP_HDR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_MSIX_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_MSIX_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_MSIX_CAP_HDR "PCCPF_XXX_MSIX_CAP_HDR"


/**
 * PCCPF - pccpf_xxx_msix_pba
 */
typedef union bdk_pccpf_xxx_msix_pba {
	uint32_t u;
	struct bdk_pccpf_xxx_msix_pba_s {
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
	/* struct bdk_pccpf_xxx_msix_pba_s    cn88xx; */
	/* struct bdk_pccpf_xxx_msix_pba_s    cn88xxp1; */
} bdk_pccpf_xxx_msix_pba_t;

#define BDK_PCCPF_XXX_MSIX_PBA BDK_PCCPF_XXX_MSIX_PBA_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_PBA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_PBA_FUNC(void)
{
	return 0x00000000000000B8ull;
}
#define typedef_BDK_PCCPF_XXX_MSIX_PBA bdk_pccpf_xxx_msix_pba_t
#define bustype_BDK_PCCPF_XXX_MSIX_PBA BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_MSIX_PBA 0
#define arguments_BDK_PCCPF_XXX_MSIX_PBA -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_MSIX_PBA "PCCPF_XXX_MSIX_PBA"


/**
 * PCCPF - pccpf_xxx_msix_table
 */
typedef union bdk_pccpf_xxx_msix_table {
	uint32_t u;
	struct bdk_pccpf_xxx_msix_table_s {
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
	/* struct bdk_pccpf_xxx_msix_table_s  cn88xx; */
	/* struct bdk_pccpf_xxx_msix_table_s  cn88xxp1; */
} bdk_pccpf_xxx_msix_table_t;

#define BDK_PCCPF_XXX_MSIX_TABLE BDK_PCCPF_XXX_MSIX_TABLE_FUNC()
static inline uint64_t BDK_PCCPF_XXX_MSIX_TABLE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_MSIX_TABLE_FUNC(void)
{
	return 0x00000000000000B4ull;
}
#define typedef_BDK_PCCPF_XXX_MSIX_TABLE bdk_pccpf_xxx_msix_table_t
#define bustype_BDK_PCCPF_XXX_MSIX_TABLE BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_MSIX_TABLE 0
#define arguments_BDK_PCCPF_XXX_MSIX_TABLE -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_MSIX_TABLE "PCCPF_XXX_MSIX_TABLE"


/**
 * PCCPF - pccpf_xxx_rev
 */
typedef union bdk_pccpf_xxx_rev {
	uint32_t u;
	struct bdk_pccpf_xxx_rev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t bcc                         : 8;  /**< RO - Base class code. See PCC_DEV_IDL_E. INTERNAL: From PCC's tie__class_code[23:16]. */
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
	/* struct bdk_pccpf_xxx_rev_s         cn88xx; */
	/* struct bdk_pccpf_xxx_rev_s         cn88xxp1; */
} bdk_pccpf_xxx_rev_t;

#define BDK_PCCPF_XXX_REV BDK_PCCPF_XXX_REV_FUNC()
static inline uint64_t BDK_PCCPF_XXX_REV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_REV_FUNC(void)
{
	return 0x0000000000000008ull;
}
#define typedef_BDK_PCCPF_XXX_REV bdk_pccpf_xxx_rev_t
#define bustype_BDK_PCCPF_XXX_REV BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_REV 0
#define arguments_BDK_PCCPF_XXX_REV -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_REV "PCCPF_XXX_REV"


/**
 * PCCPF - pccpf_xxx_sari_nxt
 */
typedef union bdk_pccpf_xxx_sari_nxt {
	uint32_t u;
	struct bdk_pccpf_xxx_sari_nxt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_16_31              : 16;
		uint32_t nxtfn                       : 8;  /**< RO/H - Next function number. 0x0 except for PCC_DEV_IDL_E::MRML, when it points to the next MFD
                                                                 in the linked list of MFDs underneath the RSL and the value comes from
                                                                 PCCPF_XXX_VSEC_CTL[NXTFN_NS] or PCCPF_XXX_VSEC_SCTL[NXTFN_S] for non-secure or secure
                                                                 accesses respectively. */
		uint32_t reserved_0_7                : 8;
#else
		uint32_t reserved_0_7                : 8;
		uint32_t nxtfn                       : 8;
		uint32_t reserved_16_31              : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sari_nxt_s    cn88xx; */
	/* struct bdk_pccpf_xxx_sari_nxt_s    cn88xxp1; */
} bdk_pccpf_xxx_sari_nxt_t;

#define BDK_PCCPF_XXX_SARI_NXT BDK_PCCPF_XXX_SARI_NXT_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SARI_NXT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SARI_NXT_FUNC(void)
{
	return 0x0000000000000104ull;
}
#define typedef_BDK_PCCPF_XXX_SARI_NXT bdk_pccpf_xxx_sari_nxt_t
#define bustype_BDK_PCCPF_XXX_SARI_NXT BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SARI_NXT 0
#define arguments_BDK_PCCPF_XXX_SARI_NXT -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SARI_NXT "PCCPF_XXX_SARI_NXT"


/**
 * PCCPF - pccpf_xxx_sriov_bar0l
 */
typedef union bdk_pccpf_xxx_sriov_bar0l {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar0l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar0_rbsz and
                                                                 tie__vfbar0_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar0l_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar0l_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar0l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR0L BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0L_FUNC(void)
{
	return 0x00000000000001A4ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR0L bdk_pccpf_xxx_sriov_bar0l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR0L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR0L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR0L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR0L "PCCPF_XXX_SRIOV_BAR0L"


/**
 * PCCPF - pccpf_xxx_sriov_bar0u
 */
typedef union bdk_pccpf_xxx_sriov_bar0u {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar0u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Upper bits of the VF BAR 0 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar0_rbsz and tie__vfbar0_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar0u_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar0u_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar0u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR0U BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR0U_FUNC(void)
{
	return 0x00000000000001A8ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR0U bdk_pccpf_xxx_sriov_bar0u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR0U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR0U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR0U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR0U "PCCPF_XXX_SRIOV_BAR0U"


/**
 * PCCPF - pccpf_xxx_sriov_bar2l
 */
typedef union bdk_pccpf_xxx_sriov_bar2l {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar2l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar2l_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar2l_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar2l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR2L BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2L_FUNC(void)
{
	return 0x00000000000001ACull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR2L bdk_pccpf_xxx_sriov_bar2l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR2L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR2L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR2L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR2L "PCCPF_XXX_SRIOV_BAR2L"


/**
 * PCCPF - pccpf_xxx_sriov_bar2u
 */
typedef union bdk_pccpf_xxx_sriov_bar2u {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar2u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Upper bits of the VF BAR 2 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar2_rbsz and tie__vfbar2_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar2u_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar2u_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar2u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR2U BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR2U_FUNC(void)
{
	return 0x00000000000001B0ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR2U bdk_pccpf_xxx_sriov_bar2u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR2U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR2U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR2U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR2U "PCCPF_XXX_SRIOV_BAR2U"


/**
 * PCCPF - pccpf_xxx_sriov_bar4l
 */
typedef union bdk_pccpf_xxx_sriov_bar4l {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar4l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< R/W/H - Lower bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
		uint32_t reserved_4_15               : 12;
		uint32_t pf                          : 1;  /**< RO - Prefetchable. */
		uint32_t typ                         : 2;  /**< RO - BAR type. 0x0 if not implemented, else 0x2:
                                                                 0x0 = 32-bit BAR, or BAR not present.
                                                                 0x2 = 64-bit BAR. */
		uint32_t mspc                        : 1;  /**< RO - Memory Space Indicator.
                                                                 0 = BAR is a memory BAR.
                                                                 1 = BAR is an I/O BAR. */
#else
		uint32_t mspc                        : 1;
		uint32_t typ                         : 2;
		uint32_t pf                          : 1;
		uint32_t reserved_4_15               : 12;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar4l_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar4l_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar4l_t;

#define BDK_PCCPF_XXX_SRIOV_BAR4L BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4L_FUNC(void)
{
	return 0x00000000000001B4ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR4L bdk_pccpf_xxx_sriov_bar4l_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR4L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR4L 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR4L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR4L "PCCPF_XXX_SRIOV_BAR4L"


/**
 * PCCPF - pccpf_xxx_sriov_bar4u
 */
typedef union bdk_pccpf_xxx_sriov_bar4u {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_bar4u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< R/W/H - Upper bits of the VF BAR 4 base address. See additional BAR related notes in
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar4_rbsz and tie__vfbar4_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_bar4u_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_bar4u_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_bar4u_t;

#define BDK_PCCPF_XXX_SRIOV_BAR4U BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_BAR4U_FUNC(void)
{
	return 0x00000000000001B8ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_BAR4U bdk_pccpf_xxx_sriov_bar4u_t
#define bustype_BDK_PCCPF_XXX_SRIOV_BAR4U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_BAR4U 0
#define arguments_BDK_PCCPF_XXX_SRIOV_BAR4U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_BAR4U "PCCPF_XXX_SRIOV_BAR4U"


/**
 * PCCPF - pccpf_xxx_sriov_cap
 */
typedef union bdk_pccpf_xxx_sriov_cap {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_cap_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vfmimn                      : 11; /**< RO - VF migration interrupt message number. */
		uint32_t reserved_2_20               : 19;
		uint32_t arichp                      : 1;  /**< RO - ARI capable hierarchy preserved. */
		uint32_t vfmc                        : 1;  /**< RO - VF migration capable. */
#else
		uint32_t vfmc                        : 1;
		uint32_t arichp                      : 1;
		uint32_t reserved_2_20               : 19;
		uint32_t vfmimn                      : 11;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_cap_s   cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_cap_s   cn88xxp1; */
} bdk_pccpf_xxx_sriov_cap_t;

#define BDK_PCCPF_XXX_SRIOV_CAP BDK_PCCPF_XXX_SRIOV_CAP_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_FUNC(void)
{
	return 0x0000000000000184ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_CAP bdk_pccpf_xxx_sriov_cap_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CAP BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_CAP 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CAP -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_CAP "PCCPF_XXX_SRIOV_CAP"


/**
 * PCCPF - pccpf_xxx_sriov_cap_hdr
 */
typedef union bdk_pccpf_xxx_sriov_cap_hdr {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. None. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t pcieec                      : 16; /**< RO - PCIE extended capability. */
#else
		uint32_t pcieec                      : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_cap_hdr_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_cap_hdr_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_cap_hdr_t;

#define BDK_PCCPF_XXX_SRIOV_CAP_HDR BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CAP_HDR_FUNC(void)
{
	return 0x0000000000000180ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_CAP_HDR bdk_pccpf_xxx_sriov_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CAP_HDR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_CAP_HDR "PCCPF_XXX_SRIOV_CAP_HDR"


/**
 * PCCPF - pccpf_xxx_sriov_ctl
 */
typedef union bdk_pccpf_xxx_sriov_ctl {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_17_31              : 15;
		uint32_t ms                          : 1;  /**< RO - VF migration status. */
		uint32_t reserved_5_15               : 11;
		uint32_t ach                         : 1;  /**< RO - ARI capable hierarchy. */
		uint32_t mse                         : 1;  /**< RO - VF MSE. Master space enable always on. */
		uint32_t mie                         : 1;  /**< RO - VF migration interrupt enable. */
		uint32_t me                          : 1;  /**< RO - VF migration enable. */
		uint32_t vfe                         : 1;  /**< RO - VF enable. */
#else
		uint32_t vfe                         : 1;
		uint32_t me                          : 1;
		uint32_t mie                         : 1;
		uint32_t mse                         : 1;
		uint32_t ach                         : 1;
		uint32_t reserved_5_15               : 11;
		uint32_t ms                          : 1;
		uint32_t reserved_17_31              : 15;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_ctl_s   cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_ctl_s   cn88xxp1; */
} bdk_pccpf_xxx_sriov_ctl_t;

#define BDK_PCCPF_XXX_SRIOV_CTL BDK_PCCPF_XXX_SRIOV_CTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_CTL_FUNC(void)
{
	return 0x0000000000000188ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_CTL bdk_pccpf_xxx_sriov_ctl_t
#define bustype_BDK_PCCPF_XXX_SRIOV_CTL BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_CTL 0
#define arguments_BDK_PCCPF_XXX_SRIOV_CTL -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_CTL "PCCPF_XXX_SRIOV_CTL"


/**
 * PCCPF - pccpf_xxx_sriov_dev
 */
typedef union bdk_pccpf_xxx_sriov_dev {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_dev_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vfdev                       : 16; /**< RO - VF device ID. \<15:8\> is PCC_PROD_E::GEN. \<7:0\> enumerated by PCC_DEV_IDL_E.
                                                                 e.g. 0xA033 for RNM_VF.
                                                                 INTERNAL: Reset value should be --; see bug23334. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t vfdev                       : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_dev_s   cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_dev_s   cn88xxp1; */
} bdk_pccpf_xxx_sriov_dev_t;

#define BDK_PCCPF_XXX_SRIOV_DEV BDK_PCCPF_XXX_SRIOV_DEV_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_DEV_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_DEV_FUNC(void)
{
	return 0x0000000000000198ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_DEV bdk_pccpf_xxx_sriov_dev_t
#define bustype_BDK_PCCPF_XXX_SRIOV_DEV BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_DEV 0
#define arguments_BDK_PCCPF_XXX_SRIOV_DEV -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_DEV "PCCPF_XXX_SRIOV_DEV"


/**
 * PCCPF - pccpf_xxx_sriov_fo
 */
typedef union bdk_pccpf_xxx_sriov_fo {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_fo_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t vfs                         : 16; /**< RO - VF stride. */
		uint32_t fo                          : 16; /**< RO - First VF offset. */
#else
		uint32_t fo                          : 16;
		uint32_t vfs                         : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_fo_s    cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_fo_s    cn88xxp1; */
} bdk_pccpf_xxx_sriov_fo_t;

#define BDK_PCCPF_XXX_SRIOV_FO BDK_PCCPF_XXX_SRIOV_FO_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_FO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_FO_FUNC(void)
{
	return 0x0000000000000194ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_FO bdk_pccpf_xxx_sriov_fo_t
#define bustype_BDK_PCCPF_XXX_SRIOV_FO BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_FO 0
#define arguments_BDK_PCCPF_XXX_SRIOV_FO -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_FO "PCCPF_XXX_SRIOV_FO"


/**
 * PCCPF - pccpf_xxx_sriov_nvf
 */
typedef union bdk_pccpf_xxx_sriov_nvf {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_nvf_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t reserved_24_31              : 8;
		uint32_t fdl                         : 8;  /**< RO - Function dependency link. Only a single PF 0 exists. */
		uint32_t nvf                         : 16; /**< RO - Number of VFs that are visible. INTERNAL: From PCC's MSIX_VFS parameter. */
#else
		uint32_t nvf                         : 16;
		uint32_t fdl                         : 8;
		uint32_t reserved_24_31              : 8;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_nvf_s   cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_nvf_s   cn88xxp1; */
} bdk_pccpf_xxx_sriov_nvf_t;

#define BDK_PCCPF_XXX_SRIOV_NVF BDK_PCCPF_XXX_SRIOV_NVF_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_NVF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_NVF_FUNC(void)
{
	return 0x0000000000000190ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_NVF bdk_pccpf_xxx_sriov_nvf_t
#define bustype_BDK_PCCPF_XXX_SRIOV_NVF BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_NVF 0
#define arguments_BDK_PCCPF_XXX_SRIOV_NVF -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_NVF "PCCPF_XXX_SRIOV_NVF"


/**
 * PCCPF - pccpf_xxx_sriov_ps
 */
typedef union bdk_pccpf_xxx_sriov_ps {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_ps_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ps                          : 32; /**< RO - System page size. 1MB, as that is minimum stride between VFs. */
#else
		uint32_t ps                          : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_ps_s    cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_ps_s    cn88xxp1; */
} bdk_pccpf_xxx_sriov_ps_t;

#define BDK_PCCPF_XXX_SRIOV_PS BDK_PCCPF_XXX_SRIOV_PS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_PS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_PS_FUNC(void)
{
	return 0x00000000000001A0ull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_PS bdk_pccpf_xxx_sriov_ps_t
#define bustype_BDK_PCCPF_XXX_SRIOV_PS BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_PS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_PS -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_PS "PCCPF_XXX_SRIOV_PS"


/**
 * PCCPF - pccpf_xxx_sriov_supps
 */
typedef union bdk_pccpf_xxx_sriov_supps {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_supps_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t supps                       : 32; /**< RO - Supported page sizes. Indicates required 4K, 8K, 64K, 256K, 1M, 4M. The BAR fixed
                                                                 assignment makes this not useful. */
#else
		uint32_t supps                       : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_supps_s cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_supps_s cn88xxp1; */
} bdk_pccpf_xxx_sriov_supps_t;

#define BDK_PCCPF_XXX_SRIOV_SUPPS BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_SUPPS_FUNC(void)
{
	return 0x000000000000019Cull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_SUPPS bdk_pccpf_xxx_sriov_supps_t
#define bustype_BDK_PCCPF_XXX_SRIOV_SUPPS BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_SUPPS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_SUPPS -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_SUPPS "PCCPF_XXX_SRIOV_SUPPS"


/**
 * PCCPF - pccpf_xxx_sriov_vfs
 */
typedef union bdk_pccpf_xxx_sriov_vfs {
	uint32_t u;
	struct bdk_pccpf_xxx_sriov_vfs_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t tvf                         : 16; /**< RO - Total VFs. INTERNAL: from pcc's MSIX_VFS parameter. */
		uint32_t ivf                         : 16; /**< RO - Initial VFs. INTERNAL: From PCC's MSIX_VFS parameter. */
#else
		uint32_t ivf                         : 16;
		uint32_t tvf                         : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_sriov_vfs_s   cn88xx; */
	/* struct bdk_pccpf_xxx_sriov_vfs_s   cn88xxp1; */
} bdk_pccpf_xxx_sriov_vfs_t;

#define BDK_PCCPF_XXX_SRIOV_VFS BDK_PCCPF_XXX_SRIOV_VFS_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SRIOV_VFS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SRIOV_VFS_FUNC(void)
{
	return 0x000000000000018Cull;
}
#define typedef_BDK_PCCPF_XXX_SRIOV_VFS bdk_pccpf_xxx_sriov_vfs_t
#define bustype_BDK_PCCPF_XXX_SRIOV_VFS BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SRIOV_VFS 0
#define arguments_BDK_PCCPF_XXX_SRIOV_VFS -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SRIOV_VFS "PCCPF_XXX_SRIOV_VFS"


/**
 * PCCPF - pccpf_xxx_subid
 */
typedef union bdk_pccpf_xxx_subid {
	uint32_t u;
	struct bdk_pccpf_xxx_subid_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ssid                        : 16; /**< RO - Device ID. \<15:8\> enumerated by PCC_PROD_E. \<7:0\> enumerated by PCC_DEV_IDL_E.
                                                                 INTERNAL: Unit from PCC's tie__prod and tie__unitid. */
		uint32_t ssvid                       : 16; /**< RO - Subsystem vendor ID. Cavium = 0x177D. */
#else
		uint32_t ssvid                       : 16;
		uint32_t ssid                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_subid_s       cn88xx; */
	/* struct bdk_pccpf_xxx_subid_s       cn88xxp1; */
} bdk_pccpf_xxx_subid_t;

#define BDK_PCCPF_XXX_SUBID BDK_PCCPF_XXX_SUBID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_SUBID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_SUBID_FUNC(void)
{
	return 0x000000000000002Cull;
}
#define typedef_BDK_PCCPF_XXX_SUBID bdk_pccpf_xxx_subid_t
#define bustype_BDK_PCCPF_XXX_SUBID BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_SUBID 0
#define arguments_BDK_PCCPF_XXX_SUBID -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_SUBID "PCCPF_XXX_SUBID"


/**
 * PCCPF - pccpf_xxx_vsec_bar0l
 */
typedef union bdk_pccpf_xxx_vsec_bar0l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar0l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0L[LBAB]. INTERNAL: From PCC's tie__pfbar0_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar0l_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar0l_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar0l_t;

#define BDK_PCCPF_XXX_VSEC_BAR0L BDK_PCCPF_XXX_VSEC_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0L_FUNC(void)
{
	return 0x0000000000000118ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR0L bdk_pccpf_xxx_vsec_bar0l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR0L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR0L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR0L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR0L "PCCPF_XXX_VSEC_BAR0L"


/**
 * PCCPF - pccpf_xxx_vsec_bar0u
 */
typedef union bdk_pccpf_xxx_vsec_bar0u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar0u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_BAR0U[UBAB]. INTERNAL: From PCC's tie__pfbar0_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar0u_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar0u_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar0u_t;

#define BDK_PCCPF_XXX_VSEC_BAR0U BDK_PCCPF_XXX_VSEC_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR0U_FUNC(void)
{
	return 0x000000000000011Cull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR0U bdk_pccpf_xxx_vsec_bar0u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR0U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR0U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR0U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR0U "PCCPF_XXX_VSEC_BAR0U"


/**
 * PCCPF - pccpf_xxx_vsec_bar2l
 */
typedef union bdk_pccpf_xxx_vsec_bar2l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar2l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2L[LBAB]. INTERNAL: From PCC's tie__pfbar2_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar2l_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar2l_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar2l_t;

#define BDK_PCCPF_XXX_VSEC_BAR2L BDK_PCCPF_XXX_VSEC_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2L_FUNC(void)
{
	return 0x0000000000000120ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR2L bdk_pccpf_xxx_vsec_bar2l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR2L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR2L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR2L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR2L "PCCPF_XXX_VSEC_BAR2L"


/**
 * PCCPF - pccpf_xxx_vsec_bar2u
 */
typedef union bdk_pccpf_xxx_vsec_bar2u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar2u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_BAR2U[UBAB]. INTERNAL: From PCC's tie__pfbar2_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar2u_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar2u_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar2u_t;

#define BDK_PCCPF_XXX_VSEC_BAR2U BDK_PCCPF_XXX_VSEC_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR2U_FUNC(void)
{
	return 0x0000000000000124ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR2U bdk_pccpf_xxx_vsec_bar2u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR2U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR2U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR2U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR2U "PCCPF_XXX_VSEC_BAR2U"


/**
 * PCCPF - pccpf_xxx_vsec_bar4l
 */
typedef union bdk_pccpf_xxx_vsec_bar4l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar4l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4L[LBAB]. INTERNAL: From PCC's tie__pfbar4_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar4l_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar4l_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar4l_t;

#define BDK_PCCPF_XXX_VSEC_BAR4L BDK_PCCPF_XXX_VSEC_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4L_FUNC(void)
{
	return 0x0000000000000128ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR4L bdk_pccpf_xxx_vsec_bar4l_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR4L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR4L 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR4L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR4L "PCCPF_XXX_VSEC_BAR4L"


/**
 * PCCPF - pccpf_xxx_vsec_bar4u
 */
typedef union bdk_pccpf_xxx_vsec_bar4u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_bar4u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_BAR4U[UBAB]. INTERNAL: From PCC's tie__pfbar4_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_bar4u_s  cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_bar4u_s  cn88xxp1; */
} bdk_pccpf_xxx_vsec_bar4u_t;

#define BDK_PCCPF_XXX_VSEC_BAR4U BDK_PCCPF_XXX_VSEC_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_BAR4U_FUNC(void)
{
	return 0x000000000000012Cull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_BAR4U bdk_pccpf_xxx_vsec_bar4u_t
#define bustype_BDK_PCCPF_XXX_VSEC_BAR4U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_BAR4U 0
#define arguments_BDK_PCCPF_XXX_VSEC_BAR4U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_BAR4U "PCCPF_XXX_VSEC_BAR4U"


/**
 * PCCPF - pccpf_xxx_vsec_cap_hdr
 */
typedef union bdk_pccpf_xxx_vsec_cap_hdr {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_cap_hdr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nco                         : 12; /**< RO - Next capability offset. If SR-IOV is supported as per PCC_DEV_IDL_E, points to the
                                                                 PCCPF_XXX_SRIOV_CAP_HDR, else 0x0. */
		uint32_t cv                          : 4;  /**< RO - Capability version. */
		uint32_t vsecid                      : 16; /**< RO - PCIE extended capability. Indicates vendor-specific capability. */
#else
		uint32_t vsecid                      : 16;
		uint32_t cv                          : 4;
		uint32_t nco                         : 12;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_cap_hdr_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_cap_hdr_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_cap_hdr_t;

#define BDK_PCCPF_XXX_VSEC_CAP_HDR BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_CAP_HDR_FUNC(void)
{
	return 0x0000000000000108ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_CAP_HDR bdk_pccpf_xxx_vsec_cap_hdr_t
#define bustype_BDK_PCCPF_XXX_VSEC_CAP_HDR BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_CAP_HDR 0
#define arguments_BDK_PCCPF_XXX_VSEC_CAP_HDR -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_CAP_HDR "PCCPF_XXX_VSEC_CAP_HDR"


/**
 * PCCPF - pccpf_xxx_vsec_ctl
 */
typedef union bdk_pccpf_xxx_vsec_ctl {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nxtfn_ns                    : 8;  /**< R/W - For non-secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN]
                                                                 indicating the next valid function number for this device.
                                                                 Must be kept as 0x0 for non-MRML PCC devices. */
		uint32_t reserved_8_23               : 16;
		uint32_t inst_num                    : 8;  /**< RO - Instance number. For blocks with multiple instances, indicates which instance number,
                                                                 otherwise 0x0; may be used to form Linux device numbers. For example for UART(1) is 0x1. */
#else
		uint32_t inst_num                    : 8;
		uint32_t reserved_8_23               : 16;
		uint32_t nxtfn_ns                    : 8;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_ctl_s    cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_ctl_s    cn88xxp1; */
} bdk_pccpf_xxx_vsec_ctl_t;

#define BDK_PCCPF_XXX_VSEC_CTL BDK_PCCPF_XXX_VSEC_CTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_CTL_FUNC(void)
{
	return 0x0000000000000110ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_CTL bdk_pccpf_xxx_vsec_ctl_t
#define bustype_BDK_PCCPF_XXX_VSEC_CTL BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_CTL 0
#define arguments_BDK_PCCPF_XXX_VSEC_CTL -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_CTL "PCCPF_XXX_VSEC_CTL"


/**
 * PCCPF - pccpf_xxx_vsec_id
 */
typedef union bdk_pccpf_xxx_vsec_id {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_id_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t len                         : 12; /**< RO - Number of bytes in the entire VSEC structure including PCCPF_XXX_VSEC_CAP_HDR. */
		uint32_t rev                         : 4;  /**< RO - Vendor-specific revision. */
		uint32_t id                          : 16; /**< RO - Vendor-specific ID. Indicates the ThunderX family VSEC ID. */
#else
		uint32_t id                          : 16;
		uint32_t rev                         : 4;
		uint32_t len                         : 12;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_id_s     cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_id_s     cn88xxp1; */
} bdk_pccpf_xxx_vsec_id_t;

#define BDK_PCCPF_XXX_VSEC_ID BDK_PCCPF_XXX_VSEC_ID_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_ID_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_ID_FUNC(void)
{
	return 0x000000000000010Cull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_ID bdk_pccpf_xxx_vsec_id_t
#define bustype_BDK_PCCPF_XXX_VSEC_ID BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_ID 0
#define arguments_BDK_PCCPF_XXX_VSEC_ID -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_ID "PCCPF_XXX_VSEC_ID"


/**
 * PCCPF - pccpf_xxx_vsec_sctl
 */
typedef union bdk_pccpf_xxx_vsec_sctl {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t nxtfn_s                     : 8;  /**< SR/W - For secure accesses, the value to be presented in PCCPF_XXX_(S)ARI_NXT[NXTFN] indicating
                                                                 the next valid function number for this device. Must be 0x0 for non-MRML PCC
                                                                 devices. */
		uint32_t rid                         : 8;  /**< SR/W - Revision ID. R/W version of the value to be presented in PCCPF_XXX_REV[RID]. */
		uint32_t reserved_3_15               : 13;
		uint32_t bcst_rsp                    : 1;  /**< SR/W - Reserved, must be 0. INTERNAL: Reserved for future use - Enable this PCC
                                                                 instance as the responder to PCC broadcast reads/writes. */
		uint32_t msix_sec                    : 1;  /**< SR/W - All MSI-X interrupts are secure. This is equivelent to setting the per-vector secure bit
                                                                 (e.g. GTI_MSIX_VEC(0..105)_ADDR[SECVEC]) for all vectors in the block. */
		uint32_t msix_phys                   : 1;  /**< SR/W - MSI-X interrupts are physical.
                                                                 0 = MSI-X interrupt vector addresses are standard virtual addresses and subject to SMMU
                                                                 address translation.
                                                                 1 = MSI-X interrupt vector addresses are considered physical addresses and PCC MSI-X
                                                                 interrupt delivery will bypass the SMMU. */
#else
		uint32_t msix_phys                   : 1;
		uint32_t msix_sec                    : 1;
		uint32_t bcst_rsp                    : 1;
		uint32_t reserved_3_15               : 13;
		uint32_t rid                         : 8;
		uint32_t nxtfn_s                     : 8;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sctl_s   cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sctl_s   cn88xxp1; */
} bdk_pccpf_xxx_vsec_sctl_t;

#define BDK_PCCPF_XXX_VSEC_SCTL BDK_PCCPF_XXX_VSEC_SCTL_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SCTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SCTL_FUNC(void)
{
	return 0x0000000000000114ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SCTL bdk_pccpf_xxx_vsec_sctl_t
#define bustype_BDK_PCCPF_XXX_VSEC_SCTL BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SCTL 0
#define arguments_BDK_PCCPF_XXX_VSEC_SCTL -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SCTL "PCCPF_XXX_VSEC_SCTL"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar0l
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar0l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar0l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0L[LBAB]. INTERNAL: From PCC's tie__vfbar0_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar0l_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar0l_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar0l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L_FUNC(void)
{
	return 0x0000000000000130ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L bdk_pccpf_xxx_vsec_sriov_bar0l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0L "PCCPF_XXX_VSEC_SRIOV_BAR0L"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar0u
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar0u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar0u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded SR-IOV BAR 0 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR0U[UBAB]. INTERNAL: From PCC's tie__vfbar0_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar0u_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar0u_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar0u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U_FUNC(void)
{
	return 0x0000000000000134ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U bdk_pccpf_xxx_vsec_sriov_bar0u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR0U "PCCPF_XXX_VSEC_SRIOV_BAR0U"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar2l
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar2l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar2l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2L[LBAB]. INTERNAL: From PCC's tie__vfbar2_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar2l_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar2l_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar2l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L_FUNC(void)
{
	return 0x0000000000000138ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L bdk_pccpf_xxx_vsec_sriov_bar2l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2L "PCCPF_XXX_VSEC_SRIOV_BAR2L"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar2u
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar2u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar2u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded SR-IOV BAR 2 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR2U[UBAB]. INTERNAL: From PCC's tie__vfbar2_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar2u_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar2u_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar2u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U_FUNC(void)
{
	return 0x000000000000013Cull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U bdk_pccpf_xxx_vsec_sriov_bar2u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR2U "PCCPF_XXX_VSEC_SRIOV_BAR2U"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar4l
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar4l {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar4l_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t lbab                        : 16; /**< RO - Lower bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4L[LBAB]. INTERNAL: From PCC's tie__vfbar4_offset. */
		uint32_t reserved_0_15               : 16;
#else
		uint32_t reserved_0_15               : 16;
		uint32_t lbab                        : 16;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar4l_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar4l_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar4l_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L_FUNC(void)
{
	return 0x0000000000000140ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L bdk_pccpf_xxx_vsec_sriov_bar4l_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4L "PCCPF_XXX_VSEC_SRIOV_BAR4L"


/**
 * PCCPF - pccpf_xxx_vsec_sriov_bar4u
 */
typedef union bdk_pccpf_xxx_vsec_sriov_bar4u {
	uint32_t u;
	struct bdk_pccpf_xxx_vsec_sriov_bar4u_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint32_t ubab                        : 32; /**< RO - Upper bits of the hard-coded SR-IOV BAR 4 base address; the reset value for
                                                                 PCCPF_XXX_SRIOV_BAR4U[UBAB]. INTERNAL: From PCC's tie__vfbar4_offset. */
#else
		uint32_t ubab                        : 32;
#endif
	} s;
	/* struct bdk_pccpf_xxx_vsec_sriov_bar4u_s cn88xx; */
	/* struct bdk_pccpf_xxx_vsec_sriov_bar4u_s cn88xxp1; */
} bdk_pccpf_xxx_vsec_sriov_bar4u_t;

#define BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC()
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U_FUNC(void)
{
	return 0x0000000000000144ull;
}
#define typedef_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U bdk_pccpf_xxx_vsec_sriov_bar4u_t
#define bustype_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U BDK_CSR_TYPE_PCCPF
#define busnum_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U 0
#define arguments_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U -1,-1,-1,-1
#define basename_BDK_PCCPF_XXX_VSEC_SRIOV_BAR4U "PCCPF_XXX_VSEC_SRIOV_BAR4U"

#endif /* __BDK_CSRS_PCCPF__ */

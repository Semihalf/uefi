#ifndef __BDK_CSRS_L2C__
#define __BDK_CSRS_L2C__
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
 * Cavium L2C.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration INV_CMD_E
 *
 * INTERNAL: INV Command Enumeration
 *
 * Enumerates the different INV command encodings.
 */
enum inv_cmd_e {
	INV_CMD_E_ALLEX = 0xc,
	INV_CMD_E_ASIDE1 = 0xd,
	INV_CMD_E_GBLSYNC = 0xf,
	INV_CMD_E_IALLU = 0x9,
	INV_CMD_E_INV = 0x8,
	INV_CMD_E_IPAS2E1 = 0x7,
	INV_CMD_E_IVAU = 0x4,
	INV_CMD_E_NOP = 0x0,
	INV_CMD_E_SEV = 0xe,
	INV_CMD_E_VAAE1 = 0x6,
	INV_CMD_E_VAEX = 0x5,
	INV_CMD_E_VMALLE1 = 0xa,
	INV_CMD_E_VMALLS12 = 0xb,
	INV_CMD_E_ENUM_LAST = 0x10,
};

/**
 * Enumeration IOC_CMD_E
 *
 * INTERNAL: IOC Command Enumeration
 *
 * Enumerates the different IOC command encodings.
 */
enum ioc_cmd_e {
	IOC_CMD_E_ADDR = 0x6,
	IOC_CMD_E_IAADD = 0xc,
	IOC_CMD_E_IACAS = 0xa,
	IOC_CMD_E_IACLR = 0xd,
	IOC_CMD_E_IASET = 0xe,
	IOC_CMD_E_IASWP = 0xb,
	IOC_CMD_E_IDLE = 0x0,
	IOC_CMD_E_LMTST = 0x3,
	IOC_CMD_E_LOAD = 0x2,
	IOC_CMD_E_SLILD = 0x8,
	IOC_CMD_E_SLIST = 0x7,
	IOC_CMD_E_STORE = 0x1,
	IOC_CMD_E_STOREP = 0x9,
	IOC_CMD_E_ENUM_LAST = 0xf,
};

/**
 * Enumeration IOR_CMD_E
 *
 * INTERNAL: IOR Command Enumeration
 *
 * Enumerates the different IOR command encodings.
 */
enum ior_cmd_e {
	IOR_CMD_E_DATA = 0x1,
	IOR_CMD_E_IDLE = 0x0,
	IOR_CMD_E_SLIRSP = 0x3,
	IOR_CMD_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration L2C_DAT_ERRPRIO_E
 *
 * L2C Quad Error Priority Enumeration
 * Enumerates the different quad error priorities.
 */
enum l2c_dat_errprio_e {
	L2C_DAT_ERRPRIO_E_FBFDBE = 0x4,
	L2C_DAT_ERRPRIO_E_FBFSBE = 0x1,
	L2C_DAT_ERRPRIO_E_L2DDBE = 0x6,
	L2C_DAT_ERRPRIO_E_L2DSBE = 0x3,
	L2C_DAT_ERRPRIO_E_NBE = 0x0,
	L2C_DAT_ERRPRIO_E_SBFDBE = 0x5,
	L2C_DAT_ERRPRIO_E_SBFSBE = 0x2,
	L2C_DAT_ERRPRIO_E_ENUM_LAST = 0x7,
};

/**
 * Enumeration L2C_TAD_PRF_SEL_E
 *
 * L2C TAD Performance Counter Select Enumeration
 * Enumerates the different TAD performance counter selects.
 */
enum l2c_tad_prf_sel_e {
	L2C_TAD_PRF_SEL_E_L2T_HIT = 0x1,
	L2C_TAD_PRF_SEL_E_L2T_MISS = 0x2,
	L2C_TAD_PRF_SEL_E_L2T_NOALLOC = 0x3,
	L2C_TAD_PRF_SEL_E_L2_OPEN_OCI = 0x48,
	L2C_TAD_PRF_SEL_E_L2_RTG_VIC = 0x44,
	L2C_TAD_PRF_SEL_E_L2_VIC = 0x4,
	L2C_TAD_PRF_SEL_E_LFB_OCC = 0x7,
	L2C_TAD_PRF_SEL_E_NONE = 0x0,
	L2C_TAD_PRF_SEL_E_QD0_BNKS = 0x82,
	L2C_TAD_PRF_SEL_E_QD0_IDX = 0x80,
	L2C_TAD_PRF_SEL_E_QD0_RDAT = 0x81,
	L2C_TAD_PRF_SEL_E_QD0_WDAT = 0x83,
	L2C_TAD_PRF_SEL_E_QD1_BNKS = 0x92,
	L2C_TAD_PRF_SEL_E_QD1_IDX = 0x90,
	L2C_TAD_PRF_SEL_E_QD1_RDAT = 0x91,
	L2C_TAD_PRF_SEL_E_QD1_WDAT = 0x93,
	L2C_TAD_PRF_SEL_E_QD2_BNKS = 0xa2,
	L2C_TAD_PRF_SEL_E_QD2_IDX = 0xa0,
	L2C_TAD_PRF_SEL_E_QD2_RDAT = 0xa1,
	L2C_TAD_PRF_SEL_E_QD2_WDAT = 0xa3,
	L2C_TAD_PRF_SEL_E_QD3_BNKS = 0xb2,
	L2C_TAD_PRF_SEL_E_QD3_IDX = 0xb0,
	L2C_TAD_PRF_SEL_E_QD3_RDAT = 0xb1,
	L2C_TAD_PRF_SEL_E_QD3_WDAT = 0xb3,
	L2C_TAD_PRF_SEL_E_QD4_BNKS = 0xc2,
	L2C_TAD_PRF_SEL_E_QD4_IDX = 0xc0,
	L2C_TAD_PRF_SEL_E_QD4_RDAT = 0xc1,
	L2C_TAD_PRF_SEL_E_QD4_WDAT = 0xc3,
	L2C_TAD_PRF_SEL_E_QD5_BNKS = 0xd2,
	L2C_TAD_PRF_SEL_E_QD5_IDX = 0xd0,
	L2C_TAD_PRF_SEL_E_QD5_RDAT = 0xd1,
	L2C_TAD_PRF_SEL_E_QD5_WDAT = 0xd3,
	L2C_TAD_PRF_SEL_E_QD6_BNKS = 0xe2,
	L2C_TAD_PRF_SEL_E_QD6_IDX = 0xe0,
	L2C_TAD_PRF_SEL_E_QD6_RDAT = 0xe1,
	L2C_TAD_PRF_SEL_E_QD6_WDAT = 0xe3,
	L2C_TAD_PRF_SEL_E_QD7_BNKS = 0xf2,
	L2C_TAD_PRF_SEL_E_QD7_IDX = 0xf0,
	L2C_TAD_PRF_SEL_E_QD7_RDAT = 0xf1,
	L2C_TAD_PRF_SEL_E_QD7_WDAT = 0xf3,
	L2C_TAD_PRF_SEL_E_RTG_HIT = 0x41,
	L2C_TAD_PRF_SEL_E_RTG_MISS = 0x42,
	L2C_TAD_PRF_SEL_E_SC_FAIL = 0x5,
	L2C_TAD_PRF_SEL_E_SC_PASS = 0x6,
	L2C_TAD_PRF_SEL_E_WAIT_LFB = 0x8,
	L2C_TAD_PRF_SEL_E_WAIT_VAB = 0x9,
	L2C_TAD_PRF_SEL_E_ENUM_LAST = 0xf4,
};

/**
 * Enumeration L2C_TAG_ERRPRIO_E
 *
 * L2C Tag Error Priority Enumeration
 * Enumerates the different TAG error priorities.
 */
enum l2c_tag_errprio_e {
	L2C_TAG_ERRPRIO_E_DBE = 0x3,
	L2C_TAG_ERRPRIO_E_NBE = 0x0,
	L2C_TAG_ERRPRIO_E_NOWAY = 0x1,
	L2C_TAG_ERRPRIO_E_SBE = 0x2,
	L2C_TAG_ERRPRIO_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration OCI_IREQ_CMD_E
 *
 * INTERNAL: OCI IREQ Command Enumeration
 *
 */
enum oci_ireq_cmd_e {
	OCI_IREQ_CMD_E_IAADD = 0x10,
	OCI_IREQ_CMD_E_IACAS = 0x15,
	OCI_IREQ_CMD_E_IACLR = 0x12,
	OCI_IREQ_CMD_E_IASET = 0x13,
	OCI_IREQ_CMD_E_IASWP = 0x14,
	OCI_IREQ_CMD_E_IDLE = 0x1f,
	OCI_IREQ_CMD_E_IOBADDR = 0x6,
	OCI_IREQ_CMD_E_IOBADDRA = 0x7,
	OCI_IREQ_CMD_E_IOBLD = 0x0,
	OCI_IREQ_CMD_E_IOBST = 0x2,
	OCI_IREQ_CMD_E_IOBSTA = 0x3,
	OCI_IREQ_CMD_E_IOBSTP = 0x4,
	OCI_IREQ_CMD_E_IOBSTPA = 0x5,
	OCI_IREQ_CMD_E_LMTST = 0x8,
	OCI_IREQ_CMD_E_LMTSTA = 0x9,
	OCI_IREQ_CMD_E_SLILD = 0x1c,
	OCI_IREQ_CMD_E_SLIST = 0x1d,
	OCI_IREQ_CMD_E_ENUM_LAST = 0x20,
};

/**
 * Enumeration OCI_IRSP_CMD_E
 *
 * INTERNAL: OCI IRSP Command Enumeration
 *
 */
enum oci_irsp_cmd_e {
	OCI_IRSP_CMD_E_IDLE = 0x1f,
	OCI_IRSP_CMD_E_IOBACK = 0x1,
	OCI_IRSP_CMD_E_IOBRSP = 0x0,
	OCI_IRSP_CMD_E_SLIRSP = 0x2,
	OCI_IRSP_CMD_E_ENUM_LAST = 0x20,
};

/**
 * Enumeration OCI_MFWD_CMD_E
 *
 * INTERNAL: OCI MFWD Command Enumeration
 *
 */
enum oci_mfwd_cmd_e {
	OCI_MFWD_CMD_E_FEVX_EH = 0xb,
	OCI_MFWD_CMD_E_FEVX_OH = 0xc,
	OCI_MFWD_CMD_E_FLDRO_E = 0x0,
	OCI_MFWD_CMD_E_FLDRO_O = 0x1,
	OCI_MFWD_CMD_E_FLDRS_E = 0x2,
	OCI_MFWD_CMD_E_FLDRS_EH = 0x4,
	OCI_MFWD_CMD_E_FLDRS_O = 0x3,
	OCI_MFWD_CMD_E_FLDRS_OH = 0x5,
	OCI_MFWD_CMD_E_FLDT_E = 0x6,
	OCI_MFWD_CMD_E_FLDX_E = 0x7,
	OCI_MFWD_CMD_E_FLDX_EH = 0x9,
	OCI_MFWD_CMD_E_FLDX_O = 0x8,
	OCI_MFWD_CMD_E_FLDX_OH = 0xa,
	OCI_MFWD_CMD_E_IDLE = 0x1f,
	OCI_MFWD_CMD_E_SINV = 0xd,
	OCI_MFWD_CMD_E_SINV_H = 0xe,
	OCI_MFWD_CMD_E_ENUM_LAST = 0x20,
};

/**
 * Enumeration OCI_MREQ_CMD_E
 *
 * INTERNAL: OCI MREQ Command Enumeration
 *
 */
enum oci_mreq_cmd_e {
	OCI_MREQ_CMD_E_GINV = 0x14,
	OCI_MREQ_CMD_E_GSYNC = 0x18,
	OCI_MREQ_CMD_E_IDLE = 0x1f,
	OCI_MREQ_CMD_E_RADD = 0xd,
	OCI_MREQ_CMD_E_RC2D_O = 0x6,
	OCI_MREQ_CMD_E_RC2D_S = 0x7,
	OCI_MREQ_CMD_E_RCAS = 0x13,
	OCI_MREQ_CMD_E_RCAS_O = 0x15,
	OCI_MREQ_CMD_E_RCAS_S = 0x16,
	OCI_MREQ_CMD_E_RCLR = 0x12,
	OCI_MREQ_CMD_E_RDEC = 0xf,
	OCI_MREQ_CMD_E_REOR = 0xb,
	OCI_MREQ_CMD_E_RINC = 0xe,
	OCI_MREQ_CMD_E_RLDD = 0x0,
	OCI_MREQ_CMD_E_RLDI = 0x1,
	OCI_MREQ_CMD_E_RLDT = 0x2,
	OCI_MREQ_CMD_E_RLDWB = 0x4,
	OCI_MREQ_CMD_E_RLDX = 0x5,
	OCI_MREQ_CMD_E_RLDY = 0x3,
	OCI_MREQ_CMD_E_RSET = 0x11,
	OCI_MREQ_CMD_E_RSMAX = 0x1b,
	OCI_MREQ_CMD_E_RSMIN = 0x1c,
	OCI_MREQ_CMD_E_RSTC = 0x17,
	OCI_MREQ_CMD_E_RSTC_O = 0x19,
	OCI_MREQ_CMD_E_RSTC_S = 0x1a,
	OCI_MREQ_CMD_E_RSTP = 0xa,
	OCI_MREQ_CMD_E_RSTT = 0x8,
	OCI_MREQ_CMD_E_RSTY = 0x9,
	OCI_MREQ_CMD_E_RSWP = 0x10,
	OCI_MREQ_CMD_E_RUMAX = 0x1d,
	OCI_MREQ_CMD_E_RUMIN = 0x1e,
	OCI_MREQ_CMD_E_ENUM_LAST = 0x20,
};

/**
 * Enumeration OCI_MRSP_CMD_E
 *
 * INTERNAL: OCI MRSP Command Enumeration
 *
 */
enum oci_mrsp_cmd_e {
	OCI_MRSP_CMD_E_GSDN = 0x18,
	OCI_MRSP_CMD_E_HAKD = 0x4,
	OCI_MRSP_CMD_E_HAKI = 0x6,
	OCI_MRSP_CMD_E_HAKN_S = 0x5,
	OCI_MRSP_CMD_E_HAKS = 0x7,
	OCI_MRSP_CMD_E_HAKV = 0x8,
	OCI_MRSP_CMD_E_IDLE = 0x1f,
	OCI_MRSP_CMD_E_P2DF = 0xd,
	OCI_MRSP_CMD_E_PACK = 0xc,
	OCI_MRSP_CMD_E_PATM = 0xb,
	OCI_MRSP_CMD_E_PEMD = 0xa,
	OCI_MRSP_CMD_E_PSHA = 0x9,
	OCI_MRSP_CMD_E_VICC = 0x1,
	OCI_MRSP_CMD_E_VICD = 0x0,
	OCI_MRSP_CMD_E_VICDHI = 0x3,
	OCI_MRSP_CMD_E_VICS = 0x2,
	OCI_MRSP_CMD_E_ENUM_LAST = 0x20,
};

/**
 * Enumeration RSC_CMD_E
 *
 * INTERNAL: RSC Command Enumeration
 *
 * Enumerates the different RSC command encodings.
 */
enum rsc_cmd_e {
	RSC_CMD_E_FLDN = 0x3,
	RSC_CMD_E_GSDN = 0x2,
	RSC_CMD_E_IACK = 0x5,
	RSC_CMD_E_IFDN = 0x1,
	RSC_CMD_E_NOP = 0x0,
	RSC_CMD_E_SCDN = 0x6,
	RSC_CMD_E_SCFL = 0x7,
	RSC_CMD_E_STDN = 0x4,
	RSC_CMD_E_ENUM_LAST = 0x8,
};

/**
 * Enumeration XMC_CMD_E
 *
 * INTERNAL: XMC Command Enumeration
 *
 * Enumerates the different XMC command encodings.
 */
enum xmc_cmd_e {
	XMC_CMD_E_AADD = 0x28,
	XMC_CMD_E_ACAS = 0x26,
	XMC_CMD_E_ACLR = 0x29,
	XMC_CMD_E_ADEC = 0x25,
	XMC_CMD_E_AEOR = 0x2a,
	XMC_CMD_E_AINC = 0x24,
	XMC_CMD_E_ALLEX = 0x3c,
	XMC_CMD_E_ASET = 0x2b,
	XMC_CMD_E_ASIDE1 = 0x3d,
	XMC_CMD_E_ASMAX = 0x2c,
	XMC_CMD_E_ASMIN = 0x2d,
	XMC_CMD_E_ASWP = 0x27,
	XMC_CMD_E_AUMAX = 0x2e,
	XMC_CMD_E_AUMIN = 0x2f,
	XMC_CMD_E_DWB = 0x5,
	XMC_CMD_E_GBLSYNC = 0x3f,
	XMC_CMD_E_IAADD = 0x68,
	XMC_CMD_E_IACAS = 0x66,
	XMC_CMD_E_IACLR = 0x69,
	XMC_CMD_E_IALLU = 0x39,
	XMC_CMD_E_IASET = 0x6b,
	XMC_CMD_E_IASWP = 0x67,
	XMC_CMD_E_INVL2 = 0x1c,
	XMC_CMD_E_IOBADDR = 0x43,
	XMC_CMD_E_IOBADDRA = 0x53,
	XMC_CMD_E_IOBLD = 0x40,
	XMC_CMD_E_IOBST = 0x41,
	XMC_CMD_E_IOBSTA = 0x51,
	XMC_CMD_E_IOBSTP = 0x42,
	XMC_CMD_E_IOBSTPA = 0x52,
	XMC_CMD_E_IPAS2E1 = 0x37,
	XMC_CMD_E_IVAU = 0x34,
	XMC_CMD_E_LCKL2 = 0x1f,
	XMC_CMD_E_LDD = 0x8,
	XMC_CMD_E_LDDT = 0xc,
	XMC_CMD_E_LDE = 0xb,
	XMC_CMD_E_LDI = 0x2,
	XMC_CMD_E_LDP = 0x7,
	XMC_CMD_E_LDT = 0x1,
	XMC_CMD_E_LDWB = 0xd,
	XMC_CMD_E_LDY = 0x6,
	XMC_CMD_E_LMTST = 0x45,
	XMC_CMD_E_LMTSTA = 0x55,
	XMC_CMD_E_LTGL2I = 0x19,
	XMC_CMD_E_NOP = 0x0,
	XMC_CMD_E_PL2 = 0x3,
	XMC_CMD_E_PL2T = 0x16,
	XMC_CMD_E_PS2 = 0xa,
	XMC_CMD_E_PS2T = 0x17,
	XMC_CMD_E_PSL1 = 0x9,
	XMC_CMD_E_RPL2 = 0x4,
	XMC_CMD_E_RSTP = 0xf,
	XMC_CMD_E_SEV = 0x3e,
	XMC_CMD_E_STC = 0x13,
	XMC_CMD_E_STF = 0x10,
	XMC_CMD_E_STFIL1 = 0x14,
	XMC_CMD_E_STGL2I = 0x1a,
	XMC_CMD_E_STP = 0x12,
	XMC_CMD_E_STT = 0x11,
	XMC_CMD_E_STTIL1 = 0x15,
	XMC_CMD_E_STY = 0xe,
	XMC_CMD_E_VAAE1 = 0x36,
	XMC_CMD_E_VAEX = 0x35,
	XMC_CMD_E_VMALLE1 = 0x3a,
	XMC_CMD_E_VMALLS12 = 0x3b,
	XMC_CMD_E_WBIL2 = 0x1d,
	XMC_CMD_E_WBIL2I = 0x18,
	XMC_CMD_E_WBL2 = 0x1e,
	XMC_CMD_E_WBL2I = 0x1b,
	XMC_CMD_E_ENUM_LAST = 0x6c,
};



/**
 * RSL - l2c_asc_region#_attr
 */
typedef union bdk_l2c_asc_regionx_attr {
	uint64_t u;
	struct bdk_l2c_asc_regionx_attr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t s_en                        : 1;  /**< R/W - Enables secure access to region.
                                                                 Undefined if both [S_EN] and [NS_EN] are set for the same region. */
		uint64_t ns_en                       : 1;  /**< R/W - Enables non-secure access to region.
                                                                 Undefined if both [S_EN] and [NS_EN] are set for the same region.
                                                                 See also DFA_ASC_REGION()_ATTR[NS_EN]. */
#else
		uint64_t ns_en                       : 1;
		uint64_t s_en                        : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_l2c_asc_regionx_attr_s  cn85xx; */
	/* struct bdk_l2c_asc_regionx_attr_s  cn88xx; */
	/* struct bdk_l2c_asc_regionx_attr_s  cn88xxp1; */
} bdk_l2c_asc_regionx_attr_t;

static inline uint64_t BDK_L2C_ASC_REGIONX_ATTR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_ASC_REGIONX_ATTR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E080801010ull + (param1 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_ASC_REGIONX_ATTR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_ASC_REGIONX_ATTR(...) bdk_l2c_asc_regionx_attr_t
#define bustype_BDK_L2C_ASC_REGIONX_ATTR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_ASC_REGIONX_ATTR(p1) (p1)
#define arguments_BDK_L2C_ASC_REGIONX_ATTR(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_ASC_REGIONX_ATTR(...) "L2C_ASC_REGIONX_ATTR"


/**
 * RSL - l2c_asc_region#_end
 */
typedef union bdk_l2c_asc_regionx_end {
	uint64_t u;
	struct bdk_l2c_asc_regionx_end_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t addr                        : 20; /**< R/W - Node-local physical address \<39:20\> marking the inclusive end of the corresponding ASC
                                                                 region.
                                                                 Note that the region includes this address.
                                                                 Software must ensure that regions do not overlap.
                                                                 To specify an empty region, clear both the [S_EN] and [NS_EN] fields of
                                                                 the corresponding L2C_ASC_REGION()_ATTR register. */
		uint64_t reserved_0_19               : 20;
#else
		uint64_t reserved_0_19               : 20;
		uint64_t addr                        : 20;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_l2c_asc_regionx_end_s   cn85xx; */
	/* struct bdk_l2c_asc_regionx_end_s   cn88xx; */
	/* struct bdk_l2c_asc_regionx_end_s   cn88xxp1; */
} bdk_l2c_asc_regionx_end_t;

static inline uint64_t BDK_L2C_ASC_REGIONX_END(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_ASC_REGIONX_END(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E080801008ull + (param1 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_ASC_REGIONX_END", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_ASC_REGIONX_END(...) bdk_l2c_asc_regionx_end_t
#define bustype_BDK_L2C_ASC_REGIONX_END(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_ASC_REGIONX_END(p1) (p1)
#define arguments_BDK_L2C_ASC_REGIONX_END(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_ASC_REGIONX_END(...) "L2C_ASC_REGIONX_END"


/**
 * RSL - l2c_asc_region#_start
 */
typedef union bdk_l2c_asc_regionx_start {
	uint64_t u;
	struct bdk_l2c_asc_regionx_start_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t addr                        : 20; /**< R/W - Node-local physical address \<39:20\> marking the start of the corresponding ASC region.
                                                                 Software must ensure that regions do not overlap. */
		uint64_t reserved_0_19               : 20;
#else
		uint64_t reserved_0_19               : 20;
		uint64_t addr                        : 20;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_l2c_asc_regionx_start_s cn85xx; */
	/* struct bdk_l2c_asc_regionx_start_s cn88xx; */
	/* struct bdk_l2c_asc_regionx_start_s cn88xxp1; */
} bdk_l2c_asc_regionx_start_t;

static inline uint64_t BDK_L2C_ASC_REGIONX_START(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_ASC_REGIONX_START(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E080801000ull + (param1 & 3) * 0x40ull;
	csr_fatal("BDK_L2C_ASC_REGIONX_START", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_ASC_REGIONX_START(...) bdk_l2c_asc_regionx_start_t
#define bustype_BDK_L2C_ASC_REGIONX_START(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_ASC_REGIONX_START(p1) (p1)
#define arguments_BDK_L2C_ASC_REGIONX_START(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_ASC_REGIONX_START(...) "L2C_ASC_REGIONX_START"


/**
 * RSL - l2c_ctl
 */
typedef union bdk_l2c_ctl {
	uint64_t u;
	struct bdk_l2c_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ocla_qos                    : 3;  /**< R/W - QOS level for the transactions from OCLA to L2C. */
		uint64_t reserved_28_28              : 1;
		uint64_t disstgl2i                   : 1;  /**< R/W - Disable STGL2Is from changing the tags. */
		uint64_t reserved_25_26              : 2;
		uint64_t discclk                     : 1;  /**< R/W - Disable conditional clocking in L2C PNR blocks. */
		uint64_t reserved_16_23              : 8;
		uint64_t rsp_arb_mode                : 1;  /**< R/W - Arbitration mode for RSC/RSD bus. 0 = round-robin; 1 = static priority.
                                                                 1. IOR data.
                                                                 2. STIN/FILLs.
                                                                 3. STDN/SCDN/SCFL. */
		uint64_t xmc_arb_mode                : 1;  /**< R/W - Arbitration mode for ADD bus QOS queues. 0 = fully determined through QOS, 1 = QOS0
                                                                 highest priority; QOS 1-7 use normal mode. */
		uint64_t rdf_cnt                     : 8;  /**< R/W - Defines the sample point of the LMC response data in the DDR-clock/core-clock crossing.
                                                                 For optimal performance set to
                                                                 10 * (DDR-clock period/core-clock period) - 1.
                                                                 To disable set to 0. All other values are reserved. */
		uint64_t reserved_4_5                : 2;
		uint64_t disldwb                     : 1;  /**< R/W - Suppresses the DWB functionality of any received LDWB, effectively turning them into LDTs. */
		uint64_t dissblkdty                  : 1;  /**< R/W - Disable bandwidth optimization between L2 and LMC and MOB which only transfers modified
                                                                 sub-blocks when possible. In an CCPI system all nodes must use the same setting of
                                                                 DISSBLKDTY or operation is undefined.
                                                                 INTERNAL: PASS2: DISSBLKDTY should reset to 0, once verif supports it. */
		uint64_t disecc                      : 1;  /**< R/W - Tag and data ECC disable. */
		uint64_t disidxalias                 : 1;  /**< R/W - Index alias disable. */
#else
		uint64_t disidxalias                 : 1;
		uint64_t disecc                      : 1;
		uint64_t dissblkdty                  : 1;
		uint64_t disldwb                     : 1;
		uint64_t reserved_4_5                : 2;
		uint64_t rdf_cnt                     : 8;
		uint64_t xmc_arb_mode                : 1;
		uint64_t rsp_arb_mode                : 1;
		uint64_t reserved_16_23              : 8;
		uint64_t discclk                     : 1;
		uint64_t reserved_25_26              : 2;
		uint64_t disstgl2i                   : 1;
		uint64_t reserved_28_28              : 1;
		uint64_t ocla_qos                    : 3;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_l2c_ctl_s               cn85xx; */
	/* struct bdk_l2c_ctl_s               cn88xx; */
	/* struct bdk_l2c_ctl_s               cn88xxp1; */
} bdk_l2c_ctl_t;

#define BDK_L2C_CTL BDK_L2C_CTL_FUNC()
static inline uint64_t BDK_L2C_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_CTL_FUNC(void)
{
	return 0x000087E080800000ull;
}
#define typedef_BDK_L2C_CTL bdk_l2c_ctl_t
#define bustype_BDK_L2C_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_CTL 0
#define arguments_BDK_L2C_CTL -1,-1,-1,-1
#define basename_BDK_L2C_CTL "L2C_CTL"


/**
 * RSL - l2c_ecc_ctl
 *
 * Flip ECC bits to generate single-bit or double-bit ECC errors in all instances of a given
 * memory type. Encodings are as follows.
 * 0x0 = No error.
 * 0x1 = Single-bit error on ECC[0].
 * 0x2 = Single-bit error on ECC[1].
 * 0x3 = Double-bit error on ECC[1:0].
 *
 * L2DFLIP allows software to generate L2DSBE, L2DDBE, VBFSBE, and VBFDBE errors for the purposes
 * of testing error handling code. When one (or both) of these bits are set, a PL2 that misses in
 * the L2 will fill with the appropriate error in the first two OWs of the fill. Software can
 * determine which OW pair gets the error by choosing the desired fill order (address\<6:5\>). A
 * PL2 that hits in the L2 will not inject any errors. Therefore sending a WBIL2 prior to the PL2
 * is recommended to make a miss likely. (If multiple processors are involved, software must be
 * sure that no other processor or I/O device can bring the block into the L2).
 *
 * To generate a VBFSBE or VBFDBE, software must first get the cache block into the cache with an
 * error using a PL2 that misses the L2. Then a store partial to a portion of the cache block
 * without the error must change the block to dirty. Then, a subsequent WBL2/WBIL2/victim will
 * trigger the VBFSBE/VBFDBE error.
 */
typedef union bdk_l2c_ecc_ctl {
	uint64_t u;
	struct bdk_l2c_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t mibflip                     : 2;  /**< R/W - Generate an ECC error in the MIB. See note above. */
		uint64_t l2dflip                     : 2;  /**< R/W - Generate an ECC error in the L2D. See note above. */
		uint64_t l2tflip                     : 2;  /**< R/W - Generate an ECC error in the L2T. */
		uint64_t rdfflip                     : 2;  /**< R/W - Generate an ECC error in RDF memory. */
		uint64_t xmdflip                     : 2;  /**< R/W - Generate an ECC error in all corresponding CBC XMD memories. */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t xmdflip                     : 2;
		uint64_t rdfflip                     : 2;
		uint64_t l2tflip                     : 2;
		uint64_t l2dflip                     : 2;
		uint64_t mibflip                     : 2;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_l2c_ecc_ctl_s           cn85xx; */
	/* struct bdk_l2c_ecc_ctl_s           cn88xx; */
	/* struct bdk_l2c_ecc_ctl_s           cn88xxp1; */
} bdk_l2c_ecc_ctl_t;

#define BDK_L2C_ECC_CTL BDK_L2C_ECC_CTL_FUNC()
static inline uint64_t BDK_L2C_ECC_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_ECC_CTL_FUNC(void)
{
	return 0x000087E080800010ull;
}
#define typedef_BDK_L2C_ECC_CTL bdk_l2c_ecc_ctl_t
#define bustype_BDK_L2C_ECC_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_ECC_CTL 0
#define arguments_BDK_L2C_ECC_CTL -1,-1,-1,-1
#define basename_BDK_L2C_ECC_CTL "L2C_ECC_CTL"


/**
 * RSL - l2c_oci_ctl
 */
typedef union bdk_l2c_oci_ctl {
	uint64_t u;
	struct bdk_l2c_oci_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_30_63              : 34;
		uint64_t lock_local_cas              : 1;  /**< R/W - When set, L2 CAS operations to remote addresses which miss at the requester will be
                                                                 performed locally (if possible) on the requesting node. Default operation will instead
                                                                 send the CAS request to be performed on the home node. For STC ops LOCK_LOCAL_STC. */
		uint64_t lock_local_stc              : 1;  /**< R/W - When set, L2 STC operations to remote addresses which miss at the requester will be
                                                                 performed locally (if possible) on the requesting node. Default operation will instead
                                                                 send the STC request to be performed on the home node. For CAS ops LOCK_LOCAL_CAS. */
		uint64_t lock_local_pp               : 1;  /**< R/W - When clear, L2 atomic operations (excluding CAS/STC) core initiated requests to remote
                                                                 addresses which miss at the requester will send the atomic request to be performed on the
                                                                 home node. Default operation will instead  be performed locally on the requesting node.
                                                                 For request initiated by IOB & for STC & CAS ops, see
                                                                 LOCK_LOCAL_IOB/LOCK_LOCAL_STC/LOCK_LOCAL_CAS. */
		uint64_t lngtolen                    : 5;  /**< R/W - Selects the bit in the counter for the long timeout value (timeout used when [SHTO] is
                                                                 clear). Values supported are between 11 and 29 (for a timeout values between 2^11 and
                                                                 2^29). Actual timeout is between 1x and 2x this interval. For example if LNGTOLEN = 28
                                                                 (the reset value), the timeout is between 256M and 512M core clocks. Note: a value of 0
                                                                 disables this timer. */
		uint64_t shtolen                     : 5;  /**< R/W - Selects the bit in the counter for the short timeout value (timeout used when [SHTO] is
                                                                 set). Values supported are between 9 and 29 (for a timeout values between 2^9 and 2^29).
                                                                 Actual timeout is between 1x and 2x this interval. For example if SHTOLEN = 14 (the reset
                                                                 value), the timeout is between 16K and 32K core clocks. Note: a value of 0 disables this
                                                                 timer. */
		uint64_t shtoioen                    : 1;  /**< R/W - When set, any core issues any of an IO load, atomic, acking store, acking IOBADDR, or
                                                                 acking LMTST to a node that doesn't exist (existence defined by the ENAOCI bits), then the
                                                                 hardware sets [SHTO]. */
		uint64_t shtoen                      : 3;  /**< R/W - When set, if the corresponding CCPI link is down, the hardware sets [SHTO].
                                                                 See OCX_COM_LINK(0..2)_CTL for a description of what events can contribute to the
                                                                 link_down condition. */
		uint64_t shto                        : 1;  /**< R/W/H - Use short timeout intervals. When set, core uses SDIDTTO for both DID and commit counter
                                                                 timeouts, rather than DIDTTO/DIDTTO2. Similarly, L2C will use short instead of long
                                                                 timeout. */
		uint64_t inv_mode                    : 2;  /**< R/W - Describes how aggressive to be when waiting for local invalidates before sending CCPI
                                                                 responses which act like commits at the remote.
                                                                 0x0 = Conservative mode, waits until all local invalidates have been sent by their
                                                                 respective CBCs to the cores.
                                                                 0x1 = Moderate mode, waits until all local invalidates have been sent to their respective
                                                                 CBCs, but not necessarily actually sent to the cores themselves.
                                                                 0x2 = Aggressive mode, does not wait for local invalidates to begin their processing. */
		uint64_t cas_fdx                     : 1;  /**< R/W - When set, L2 STC/CAS operations performed at the home will immediately bring the block
                                                                 exclusive into the home. Default operation is to first request the block shared and only
                                                                 invalidate the remote if the compare succeeds. */
		uint64_t rldd_psha                   : 1;  /**< R/W - When set, RLDD is assumed to return a shared response (PSHA). Default operation assumes an
                                                                 exclusive response (PEMD). Note that an incorrect assumption only causes an extra tag
                                                                 write to be done upon receiving the response. */
		uint64_t lock_local_iob              : 1;  /**< R/W - When set, L2 atomic operations (excluding CAS/STC) initiated by IOB to remote addresses
                                                                 which miss at the requester are performed locally on the requesting node. When clear the
                                                                 operation instead sends the atomic request to be performed on the home node. For request
                                                                 initiated by core for STC and CAS ops; see LOCK_LOCAL_PP/LOCK_LOCAL_STC/LOCK_LOCAL_CAS.
                                                                 Default is set to 1 (local locks). */
		uint64_t iofrcl                      : 1;  /**< R/W - When set, L2C services all I/O read and write operations on the local node, regardless of
                                                                 the value of the node ID bits in the physical address. During normal operation this bit is
                                                                 expected to be 0. Will only transition from 1 to 0, never from 0 to 1. */
		uint64_t reserved_4_5                : 2;
		uint64_t enaoci                      : 4;  /**< R/W - Enable CCPI processing (one bit per node_id). When set, perform CCPI
                                                                 processing. When clear, CCPI memory writes are blocked and CCPI memory reads
                                                                 return unpredictable data. When clear,
                                                                 CCPI I/O requests and MOC references are processed and sent to OCX where they are
                                                                 ultimately discarded. RDDISOCI/WRDISOCI/IORDDISOCI/IOWRDISOCI interrupts occur if and only
                                                                 if the corresponding ENAOCI\<node\> bit is clear. References to the local node (configured
                                                                 via OCX_COM_NODE[ID]) ignore the value of ENAOCI\<node\> because no CCPI processing is
                                                                 required. Similarly, all I/O references ignore the value of ENAOCI when
                                                                 L2C_OCI_CTL[IOFRCL] is set. */
#else
		uint64_t enaoci                      : 4;
		uint64_t reserved_4_5                : 2;
		uint64_t iofrcl                      : 1;
		uint64_t lock_local_iob              : 1;
		uint64_t rldd_psha                   : 1;
		uint64_t cas_fdx                     : 1;
		uint64_t inv_mode                    : 2;
		uint64_t shto                        : 1;
		uint64_t shtoen                      : 3;
		uint64_t shtoioen                    : 1;
		uint64_t shtolen                     : 5;
		uint64_t lngtolen                    : 5;
		uint64_t lock_local_pp               : 1;
		uint64_t lock_local_stc              : 1;
		uint64_t lock_local_cas              : 1;
		uint64_t reserved_30_63              : 34;
#endif
	} s;
	/* struct bdk_l2c_oci_ctl_s           cn85xx; */
	/* struct bdk_l2c_oci_ctl_s           cn88xx; */
	/* struct bdk_l2c_oci_ctl_s           cn88xxp1; */
} bdk_l2c_oci_ctl_t;

#define BDK_L2C_OCI_CTL BDK_L2C_OCI_CTL_FUNC()
static inline uint64_t BDK_L2C_OCI_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_OCI_CTL_FUNC(void)
{
	return 0x000087E080800020ull;
}
#define typedef_BDK_L2C_OCI_CTL bdk_l2c_oci_ctl_t
#define bustype_BDK_L2C_OCI_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_OCI_CTL 0
#define arguments_BDK_L2C_OCI_CTL -1,-1,-1,-1
#define basename_BDK_L2C_OCI_CTL "L2C_OCI_CTL"


/**
 * RSL - l2c_qos_pp#
 */
typedef union bdk_l2c_qos_ppx {
	uint64_t u;
	struct bdk_l2c_qos_ppx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t lvl                         : 3;  /**< R/W - QOS level to use for this core. */
#else
		uint64_t lvl                         : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_l2c_qos_ppx_s           cn85xx; */
	/* struct bdk_l2c_qos_ppx_s           cn88xx; */
	/* struct bdk_l2c_qos_ppx_s           cn88xxp1; */
} bdk_l2c_qos_ppx_t;

static inline uint64_t BDK_L2C_QOS_PPX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_QOS_PPX(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087E080880000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_L2C_QOS_PPX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_QOS_PPX(...) bdk_l2c_qos_ppx_t
#define bustype_BDK_L2C_QOS_PPX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_QOS_PPX(p1) (p1)
#define arguments_BDK_L2C_QOS_PPX(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_QOS_PPX(...) "L2C_QOS_PPX"


/**
 * RSL - l2c_qos_wgt
 */
typedef union bdk_l2c_qos_wgt {
	uint64_t u;
	struct bdk_l2c_qos_wgt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wgt7                        : 8;  /**< R/W - Weight for QOS level 7. */
		uint64_t wgt6                        : 8;  /**< R/W - Weight for QOS level 6. */
		uint64_t wgt5                        : 8;  /**< R/W - Weight for QOS level 5. */
		uint64_t wgt4                        : 8;  /**< R/W - Weight for QOS level 4. */
		uint64_t wgt3                        : 8;  /**< R/W - Weight for QOS level 3. */
		uint64_t wgt2                        : 8;  /**< R/W - Weight for QOS level 2. */
		uint64_t wgt1                        : 8;  /**< R/W - Weight for QOS level 1. */
		uint64_t wgt0                        : 8;  /**< R/W - Weight for QOS level 0. */
#else
		uint64_t wgt0                        : 8;
		uint64_t wgt1                        : 8;
		uint64_t wgt2                        : 8;
		uint64_t wgt3                        : 8;
		uint64_t wgt4                        : 8;
		uint64_t wgt5                        : 8;
		uint64_t wgt6                        : 8;
		uint64_t wgt7                        : 8;
#endif
	} s;
	/* struct bdk_l2c_qos_wgt_s           cn85xx; */
	/* struct bdk_l2c_qos_wgt_s           cn88xx; */
	/* struct bdk_l2c_qos_wgt_s           cn88xxp1; */
} bdk_l2c_qos_wgt_t;

#define BDK_L2C_QOS_WGT BDK_L2C_QOS_WGT_FUNC()
static inline uint64_t BDK_L2C_QOS_WGT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_QOS_WGT_FUNC(void)
{
	return 0x000087E080800008ull;
}
#define typedef_BDK_L2C_QOS_WGT bdk_l2c_qos_wgt_t
#define bustype_BDK_L2C_QOS_WGT BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_QOS_WGT 0
#define arguments_BDK_L2C_QOS_WGT -1,-1,-1,-1
#define basename_BDK_L2C_QOS_WGT "L2C_QOS_WGT"


/**
 * RSL - l2c_tad_ctl
 *
 * In CNXXXX, MAXLFB, EXLRQ, EXRRQ, EXFWD, EXVIC refer to half-TAD LFBs/VABs. Therefore, even
 * though there are 32 LFBs/VABs in a full TAD, the number applies to both halves.
 * * If MAXLFB is != 0, VBF_THRESH should be less than MAXLFB.
 * * If MAXVBF is != 0, VBF_THRESH should be less than MAXVBF.
 * * If MAXLFB != 0, EXLRQ + EXRRQ + EXFWD + EXVIC must be less than or equal to MAXLFB - 4.
 * * If MAXLFB == 0, EXLRQ + EXRRQ + EXFWD + EXVIC must be less than or equal to 12.
 */
typedef union bdk_l2c_tad_ctl {
	uint64_t u;
	struct bdk_l2c_tad_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t frcnalc                     : 1;  /**< R/W - When set, all cache accesses are forced to not allocate in the local L2. */
		uint64_t disrstp                     : 1;  /**< R/W - When set, if the L2 receives an RSTP XMC command, it treats it as a STP. */
		uint64_t wtlmcwrdn                   : 1;  /**< R/W - Be more conservative with LFB done relative to LMC writes. */
		uint64_t wtinvdn                     : 1;  /**< R/W - Be more conservative with LFB done relative to invalidates. */
		uint64_t wtfilldn                    : 1;  /**< R/W - Be more conservative with LFB done relative to fills. */
		uint64_t exlrq                       : 4;  /**< R/W - Extra LFBs to reserve for locally generated XMC commands. None are reserved for functional
                                                                 correctness. Ignored if L2C_OCI_CTL[ENAOCI] is 0. */
		uint64_t exrrq                       : 4;  /**< R/W - Extra LFBs to reserve for Rxxx CCPI commands beyond the 1 required for CCPI protocol
                                                                 functional correctness. Ignored if L2C_OCI_CTL[ENAOCI] is 0. */
		uint64_t exfwd                       : 4;  /**< R/W - Extra LFBs to reserve for Fxxx/SINV CCPI commands beyond the 1 required for CCPI protocol
                                                                 functional correctness. Ignored if L2C_OCI_CTL[ENAOCI] is 0. */
		uint64_t exvic                       : 4;  /**< R/W - Extra LFBs to reserve for VICx CCPI commands beyond the 1 required for CCPI protocol
                                                                 functional correctness. Ignored if L2C_OCI_CTL[ENAOCI] is 0. */
		uint64_t vbf_thresh                  : 4;  /**< R/W - VBF threshold. When the number of in-use VBFs exceeds this number the L2C TAD increases
                                                                 the priority of all its write operations in the LMC. */
		uint64_t maxvbf                      : 4;  /**< R/W - Maximum VBFs in use at once (0 means 16, 1-15 as expected). */
		uint64_t maxlfb                      : 4;  /**< R/W - Maximum VABs/LFBs in use at once (0 means 16, 1-15 as expected). */
#else
		uint64_t maxlfb                      : 4;
		uint64_t maxvbf                      : 4;
		uint64_t vbf_thresh                  : 4;
		uint64_t exvic                       : 4;
		uint64_t exfwd                       : 4;
		uint64_t exrrq                       : 4;
		uint64_t exlrq                       : 4;
		uint64_t wtfilldn                    : 1;
		uint64_t wtinvdn                     : 1;
		uint64_t wtlmcwrdn                   : 1;
		uint64_t disrstp                     : 1;
		uint64_t frcnalc                     : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_l2c_tad_ctl_s           cn85xx; */
	/* struct bdk_l2c_tad_ctl_s           cn88xx; */
	/* struct bdk_l2c_tad_ctl_s           cn88xxp1; */
} bdk_l2c_tad_ctl_t;

#define BDK_L2C_TAD_CTL BDK_L2C_TAD_CTL_FUNC()
static inline uint64_t BDK_L2C_TAD_CTL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_TAD_CTL_FUNC(void)
{
	return 0x000087E080800018ull;
}
#define typedef_BDK_L2C_TAD_CTL bdk_l2c_tad_ctl_t
#define bustype_BDK_L2C_TAD_CTL BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_TAD_CTL 0
#define arguments_BDK_L2C_TAD_CTL -1,-1,-1,-1
#define basename_BDK_L2C_TAD_CTL "L2C_TAD_CTL"


/**
 * RSL - l2c_wpar_iob#
 */
typedef union bdk_l2c_wpar_iobx {
	uint64_t u;
	struct bdk_l2c_wpar_iobx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t mask                        : 16; /**< R/W/H - Way partitioning mask (1 means do not use). The read value of MASK includes bits set
                                                                 because of the L2C cripple fuses. */
#else
		uint64_t mask                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_l2c_wpar_iobx_s         cn85xx; */
	/* struct bdk_l2c_wpar_iobx_s         cn88xx; */
	/* struct bdk_l2c_wpar_iobx_s         cn88xxp1; */
} bdk_l2c_wpar_iobx_t;

static inline uint64_t BDK_L2C_WPAR_IOBX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_WPAR_IOBX(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x000087E080840200ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_L2C_WPAR_IOBX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_WPAR_IOBX(...) bdk_l2c_wpar_iobx_t
#define bustype_BDK_L2C_WPAR_IOBX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_WPAR_IOBX(p1) (p1)
#define arguments_BDK_L2C_WPAR_IOBX(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_WPAR_IOBX(...) "L2C_WPAR_IOBX"


/**
 * RSL - l2c_wpar_pp#
 */
typedef union bdk_l2c_wpar_ppx {
	uint64_t u;
	struct bdk_l2c_wpar_ppx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t mask                        : 16; /**< R/W/H - Way partitioning mask (1 means do not use). The read value of MASK includes bits set
                                                                 because of the L2C cripple fuses. */
#else
		uint64_t mask                        : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_l2c_wpar_ppx_s          cn85xx; */
	/* struct bdk_l2c_wpar_ppx_s          cn88xx; */
	/* struct bdk_l2c_wpar_ppx_s          cn88xxp1; */
} bdk_l2c_wpar_ppx_t;

static inline uint64_t BDK_L2C_WPAR_PPX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_L2C_WPAR_PPX(unsigned long param1)
{
	if (((param1 <= 47)))
		return 0x000087E080840000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_L2C_WPAR_PPX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_L2C_WPAR_PPX(...) bdk_l2c_wpar_ppx_t
#define bustype_BDK_L2C_WPAR_PPX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_L2C_WPAR_PPX(p1) (p1)
#define arguments_BDK_L2C_WPAR_PPX(p1) (p1),-1,-1,-1
#define basename_BDK_L2C_WPAR_PPX(...) "L2C_WPAR_PPX"

#endif /* __BDK_CSRS_L2C__ */

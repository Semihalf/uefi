#ifndef __BDK_CSRS_SATA_H__
#define __BDK_CSRS_SATA_H__
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
 * Cavium SATA.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration sata_uctl_ecc_err_source_e
 *
 * SATA UCTL ECC Error Source Enumeration
 * Enumerate sources of ECC error log information.
 */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_FB_DBE (0xf) /**< UAHC FBS RAM double-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_FB_SBE (7) /**< UAHC FBS RAM single-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_NONE (0) /**< No error logged. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_RX_DBE (0xd) /**< UAHC RX asynchronous FIFO double-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_RX_SBE (5) /**< UAHC RX asynchronous FIFO single-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_TX_DBE (0xe) /**< UAHC TX asynchronous FIFO double-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_TX_SBE (6) /**< UAHC TX asynchronous FIFO single-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_XM_R_DBE (0xa) /**< UCTL AxiMaster read data asynchronous FIFO double-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_XM_R_SBE (2) /**< UCTL AxiMaster read data asynchronous FIFO single-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_XM_W_DBE (9) /**< UCTL AxiMaster write data asynchronous FIFO double-bit error. */
#define BDK_SATA_UCTL_ECC_ERR_SOURCE_E_XM_W_SBE (1) /**< UCTL AxiMaster write data asynchronous FIFO single-bit error. */

/**
 * Enumeration sata_int_vec_e
 *
 * SATA MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_SATA_INT_VEC_E_UAHC_INTRQ_IP (0) /**< See SATA()_UAHC_GBL_IS[IPS] and SATA()_UAHC_P0_IS. */
#define BDK_SATA_INT_VEC_E_UAHC_INTRQ_IP_CLEAR (1) /**< Level sensitive interrupt clear vector. */
#define BDK_SATA_INT_VEC_E_UAHC_PME_REQ_IP (2) /**< See SATA()_UAHC_P0_IS[CPDS] and
                                       SATA()_UAHC_P0_IS[DMPS] and
                                       SATA()_UAHC_P0_IS[PCS] and
                                       SATA()_UAHC_P0_IS[SDBS] and
                                       SATA()_UAHC_P0_SNTF[PMN]. */
#define BDK_SATA_INT_VEC_E_UAHC_PME_REQ_IP_CLEAR (3) /**< Level sensitive interrupt clear vector. */
#define BDK_SATA_INT_VEC_E_UCTL_INTSTAT_CN83XX (1) /**< See interrupt clears SATA(0..15)_UCTL_INTSTAT, interrupt sets
                                       SATA(0..15)_UCTL_INTSTAT_W1S, enable clears
                                       SATA(0..15)_UCTL_INTENA_W1C, and enable sets SATA(0..15)_UCTL_INTENA_W1S. */
#define BDK_SATA_INT_VEC_E_UCTL_INTSTAT_CN88XXP2 (1) /**< See interrupt clears SATA(0..15)_UCTL_INTSTAT, interrupt sets
                                       SATA(0..15)_UCTL_INTSTAT_W1S, enable clears
                                       SATA(0..15)_UCTL_INTENA_W1C, and enable sets SATA(0..15)_UCTL_INTENA_W1S. */
#define BDK_SATA_INT_VEC_E_UCTL_INTSTAT_CN88XXP1 (4) /**< See interrupt clears SATA(0..15)_UCTL_INTSTAT, interrupt sets
                                       SATA(0..15)_UCTL_INTSTAT_W1S, enable clears
                                       SATA(0..15)_UCTL_INTENA_W1C, and enable sets SATA(0..15)_UCTL_INTENA_W1S. */

/**
 * Enumeration sata_uctl_dma_write_cmd_e
 *
 * SATA UCTL DMA Write Command Enumeration
 * Enumerate NCB inbound command selections for DMA writes.
 */
#define BDK_SATA_UCTL_DMA_WRITE_CMD_E_RSTP (1) /**< Use RSTP (allocate home, no fill zero's). */
#define BDK_SATA_UCTL_DMA_WRITE_CMD_E_STP (0) /**< Use STP (allocate local, no fill zero's). Default. */

/**
 * Enumeration sata_uctl_dma_read_cmd_e
 *
 * SATA UCTL DMA Read Command Enumeration
 * Enumerates NCB inbound command selections for DMA read operations.
 */
#define BDK_SATA_UCTL_DMA_READ_CMD_E_LDI (0) /**< Use LDI (allocate). */
#define BDK_SATA_UCTL_DMA_READ_CMD_E_LDT (1) /**< Use LDT (no allocate). Default. */
#define BDK_SATA_UCTL_DMA_READ_CMD_E_LDY (2) /**< Use LDY (allocate home). */

/**
 * Enumeration sata_bar_e
 *
 * SATA Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_SATA_BAR_E_SATAX_PF_BAR0(a) (0x810000000000ll + 0x1000000000ll * (a)) /**< (0..15)Base address for standard registers. */
#define BDK_SATA_BAR_E_SATAX_PF_BAR4(a) (0x810000200000ll + 0x1000000000ll * (a)) /**< (0..15)Base address for MSI-X registers. */

/**
 * Enumeration sata_uctl_xm_bad_dma_type_e
 *
 * SATA UCTL XM Bad DMA Type Enumeration
 * Enumerates the type of DMA error seen.
 */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_ADDR_OOB (1) /**< AxAddr<63:42> != 0x0. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_LEN_GT_8 (2) /**< AxLen > 0x7. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_BYTE (3) /**< AxSize = 0x0 and AxLen != 0x0. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_HALFWORD (4) /**< AxSize = 0x1 and AxLen != 0x0. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_QWORD (6) /**< AxSize = 0x3 and AxLen != 0x0. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_MULTIBEAT_WORD (5) /**< AxSize = 0x2 and AxLen != 0x0. */
#define BDK_SATA_UCTL_XM_BAD_DMA_TYPE_E_NONE (0) /**< No error logged. */

/**
 * Register (NCB) sata#_uahc_p0_clb
 *
 * SATA UAHC Command-List Base-Address Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uahc_p0_clb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t clb                   : 54; /**< [ 63: 10](R/W) Command-list base address. */
        uint64_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_9          : 10;
        uint64_t clb                   : 54; /**< [ 63: 10](R/W) Command-list base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_clb_s cn; */
} bdk_satax_uahc_p0_clb_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CLB(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CLB(unsigned long a)
{
    if (a<=15)
        return 0x810000000100ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_CLB", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_CLB(a) bdk_satax_uahc_p0_clb_t
#define bustype_BDK_SATAX_UAHC_P0_CLB(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UAHC_P0_CLB(a) "SATAX_UAHC_P0_CLB"
#define busnum_BDK_SATAX_UAHC_P0_CLB(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_CLB(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_oobr
 *
 * SATA UAHC OOB Register
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_oobr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t we                    : 1;  /**< [ 31: 31](R/W/H) Write enable. */
        uint32_t cwmin                 : 7;  /**< [ 30: 24](R/W/H) COMWAKE minimum value. Writable only if WE is set. */
        uint32_t cwmax                 : 8;  /**< [ 23: 16](R/W/H) COMWAKE maximum value. Writable only if WE is set. */
        uint32_t cimin                 : 8;  /**< [ 15:  8](R/W/H) COMINIT minimum value. Writable only if WE is set. */
        uint32_t cimax                 : 8;  /**< [  7:  0](R/W/H) COMINIT maximum value. Writable only if WE is set. */
#else /* Word 0 - Little Endian */
        uint32_t cimax                 : 8;  /**< [  7:  0](R/W/H) COMINIT maximum value. Writable only if WE is set. */
        uint32_t cimin                 : 8;  /**< [ 15:  8](R/W/H) COMINIT minimum value. Writable only if WE is set. */
        uint32_t cwmax                 : 8;  /**< [ 23: 16](R/W/H) COMWAKE maximum value. Writable only if WE is set. */
        uint32_t cwmin                 : 7;  /**< [ 30: 24](R/W/H) COMWAKE minimum value. Writable only if WE is set. */
        uint32_t we                    : 1;  /**< [ 31: 31](R/W/H) Write enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_oobr_s cn; */
} bdk_satax_uahc_gbl_oobr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_OOBR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_OOBR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000bcll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_OOBR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_OOBR(a) bdk_satax_uahc_gbl_oobr_t
#define bustype_BDK_SATAX_UAHC_GBL_OOBR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_OOBR(a) "SATAX_UAHC_GBL_OOBR"
#define busnum_BDK_SATAX_UAHC_GBL_OOBR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_OOBR(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_bist_status
 *
 * SATA UCTL BIST Status Register
 * Results from BIST runs of SATA's memories.
 * Wait for NDONE==0, then look at defect indication.
 *
 * Accessible always.
 *
 * Reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_42_63        : 22;
        uint64_t uctl_xm_r_bist_ndone  : 1;  /**< [ 41: 41](RO/H) BIST is not complete for the UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_bist_ndone  : 1;  /**< [ 40: 40](RO/H) BIST is not complete for the UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_36_39        : 4;
        uint64_t uahc_p0_rxram_bist_ndone : 1;/**< [ 35: 35](RO/H) BIST is not complete for the UAHC Port 0 RxFIFO RAM. */
        uint64_t reserved_34           : 1;
        uint64_t uahc_p0_txram_bist_ndone : 1;/**< [ 33: 33](RO/H) BIST is not complete for the UAHC Port 0 TxFIFO RAM. */
        uint64_t reserved_10_32        : 23;
        uint64_t uctl_xm_r_bist_status : 1;  /**< [  9:  9](RO/H) BIST status of the UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_bist_status : 1;  /**< [  8:  8](RO/H) BIST status of the UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_4_7          : 4;
        uint64_t uahc_p0_rxram_bist_status : 1;/**< [  3:  3](RO/H) BIST status of the UAHC Port0 RxFIFO RAM. */
        uint64_t reserved_2            : 1;
        uint64_t uahc_p0_txram_bist_status : 1;/**< [  1:  1](RO/H) BIST status of the UAHC Port0 TxFIFO RAM. */
        uint64_t reserved_0            : 1;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0            : 1;
        uint64_t uahc_p0_txram_bist_status : 1;/**< [  1:  1](RO/H) BIST status of the UAHC Port0 TxFIFO RAM. */
        uint64_t reserved_2            : 1;
        uint64_t uahc_p0_rxram_bist_status : 1;/**< [  3:  3](RO/H) BIST status of the UAHC Port0 RxFIFO RAM. */
        uint64_t reserved_4_7          : 4;
        uint64_t uctl_xm_w_bist_status : 1;  /**< [  8:  8](RO/H) BIST status of the UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_r_bist_status : 1;  /**< [  9:  9](RO/H) BIST status of the UCTL AxiMaster read-data FIFO. */
        uint64_t reserved_10_32        : 23;
        uint64_t uahc_p0_txram_bist_ndone : 1;/**< [ 33: 33](RO/H) BIST is not complete for the UAHC Port 0 TxFIFO RAM. */
        uint64_t reserved_34           : 1;
        uint64_t uahc_p0_rxram_bist_ndone : 1;/**< [ 35: 35](RO/H) BIST is not complete for the UAHC Port 0 RxFIFO RAM. */
        uint64_t reserved_36_39        : 4;
        uint64_t uctl_xm_w_bist_ndone  : 1;  /**< [ 40: 40](RO/H) BIST is not complete for the UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_r_bist_ndone  : 1;  /**< [ 41: 41](RO/H) BIST is not complete for the UCTL AxiMaster read-data FIFO. */
        uint64_t reserved_42_63        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_bist_status_s cn; */
} bdk_satax_uctl_bist_status_t;

static inline uint64_t BDK_SATAX_UCTL_BIST_STATUS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_BIST_STATUS(unsigned long a)
{
    if (a<=15)
        return 0x810000100008ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_BIST_STATUS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_BIST_STATUS(a) bdk_satax_uctl_bist_status_t
#define bustype_BDK_SATAX_UCTL_BIST_STATUS(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_BIST_STATUS(a) "SATAX_UCTL_BIST_STATUS"
#define busnum_BDK_SATAX_UCTL_BIST_STATUS(a) (a)
#define arguments_BDK_SATAX_UCTL_BIST_STATUS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_ci
 *
 * SATA UAHC Command Issue Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_ci_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ci                    : 32; /**< [ 31:  0](R/W1S/H) Command issued. */
#else /* Word 0 - Little Endian */
        uint32_t ci                    : 32; /**< [ 31:  0](R/W1S/H) Command issued. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_ci_s cn; */
} bdk_satax_uahc_p0_ci_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CI(unsigned long a)
{
    if (a<=15)
        return 0x810000000138ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_CI", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_CI(a) bdk_satax_uahc_p0_ci_t
#define bustype_BDK_SATAX_UAHC_P0_CI(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_CI(a) "SATAX_UAHC_P0_CI"
#define busnum_BDK_SATAX_UAHC_P0_CI(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_CI(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_serr
 *
 * SATA UAHC SATA Error Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_serr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_27_31        : 5;
        uint32_t diag_x                : 1;  /**< [ 26: 26](R/W1C/H) Exchanged. */
        uint32_t diag_f                : 1;  /**< [ 25: 25](R/W1C/H) Unknown FIS type. */
        uint32_t diag_t                : 1;  /**< [ 24: 24](R/W1C/H) Transport state transition error. */
        uint32_t diag_s                : 1;  /**< [ 23: 23](R/W1C/H) Link sequence error. */
        uint32_t diag_h                : 1;  /**< [ 22: 22](R/W1C/H) Handshake error. */
        uint32_t diag_c                : 1;  /**< [ 21: 21](R/W1C/H) CRC error. */
        uint32_t diag_d                : 1;  /**< [ 20: 20](R/W1C/H) Disparity error. */
        uint32_t diag_b                : 1;  /**< [ 19: 19](R/W1C/H) 10B to 8B decode error. */
        uint32_t diag_w                : 1;  /**< [ 18: 18](R/W1C/H) COMWAKE detected. */
        uint32_t diag_i                : 1;  /**< [ 17: 17](R/W1C/H) PHY internal error. */
        uint32_t diag_n                : 1;  /**< [ 16: 16](R/W1C/H) PHY ready change. */
        uint32_t reserved_12_15        : 4;
        uint32_t err_e                 : 1;  /**< [ 11: 11](R/W1C/H) Internal error. */
        uint32_t err_p                 : 1;  /**< [ 10: 10](R/W1C/H) Protocol error. */
        uint32_t err_c                 : 1;  /**< [  9:  9](R/W1C/H) Non-recovered persistent communication error. */
        uint32_t err_t                 : 1;  /**< [  8:  8](R/W1C/H) Non-recovered transient data integrity error. */
        uint32_t reserved_2_7          : 6;
        uint32_t err_m                 : 1;  /**< [  1:  1](R/W1C/H) Recovered communication error. */
        uint32_t err_i                 : 1;  /**< [  0:  0](R/W1C/H) Recovered data integrity. */
#else /* Word 0 - Little Endian */
        uint32_t err_i                 : 1;  /**< [  0:  0](R/W1C/H) Recovered data integrity. */
        uint32_t err_m                 : 1;  /**< [  1:  1](R/W1C/H) Recovered communication error. */
        uint32_t reserved_2_7          : 6;
        uint32_t err_t                 : 1;  /**< [  8:  8](R/W1C/H) Non-recovered transient data integrity error. */
        uint32_t err_c                 : 1;  /**< [  9:  9](R/W1C/H) Non-recovered persistent communication error. */
        uint32_t err_p                 : 1;  /**< [ 10: 10](R/W1C/H) Protocol error. */
        uint32_t err_e                 : 1;  /**< [ 11: 11](R/W1C/H) Internal error. */
        uint32_t reserved_12_15        : 4;
        uint32_t diag_n                : 1;  /**< [ 16: 16](R/W1C/H) PHY ready change. */
        uint32_t diag_i                : 1;  /**< [ 17: 17](R/W1C/H) PHY internal error. */
        uint32_t diag_w                : 1;  /**< [ 18: 18](R/W1C/H) COMWAKE detected. */
        uint32_t diag_b                : 1;  /**< [ 19: 19](R/W1C/H) 10B to 8B decode error. */
        uint32_t diag_d                : 1;  /**< [ 20: 20](R/W1C/H) Disparity error. */
        uint32_t diag_c                : 1;  /**< [ 21: 21](R/W1C/H) CRC error. */
        uint32_t diag_h                : 1;  /**< [ 22: 22](R/W1C/H) Handshake error. */
        uint32_t diag_s                : 1;  /**< [ 23: 23](R/W1C/H) Link sequence error. */
        uint32_t diag_t                : 1;  /**< [ 24: 24](R/W1C/H) Transport state transition error. */
        uint32_t diag_f                : 1;  /**< [ 25: 25](R/W1C/H) Unknown FIS type. */
        uint32_t diag_x                : 1;  /**< [ 26: 26](R/W1C/H) Exchanged. */
        uint32_t reserved_27_31        : 5;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_serr_s cn; */
} bdk_satax_uahc_p0_serr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SERR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SERR(unsigned long a)
{
    if (a<=15)
        return 0x810000000130ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SERR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SERR(a) bdk_satax_uahc_p0_serr_t
#define bustype_BDK_SATAX_UAHC_P0_SERR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SERR(a) "SATAX_UAHC_P0_SERR"
#define busnum_BDK_SATAX_UAHC_P0_SERR(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SERR(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_ecc
 *
 * SATA UCTL ECC Control/Debug Register
 * This register can be used to disable ECC correction, insert ECC errors, and debug ECC
 * failures.
 *
 * Fields ECC_ERR* are captured when there are no outstanding ECC errors indicated in INTSTAT
 * and a new ECC error arrives. Prioritization for multiple events occurring on the same cycle is
 * indicated by the ECC_ERR_SOURCE enumeration: highest encoded value has highest priority.
 *
 * Fields *ECC_DIS: Disables ECC correction, SBE and DBE errors are still reported.
 * If ECC_DIS is 0x1, then no data-correction occurs.
 *
 * Fields *ECC_FLIP_SYND:  Flip the syndrom[1:0] bits to generate 1-bit/2-bits error for testing.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_ecc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_62_63        : 2;
        uint64_t ecc_err_source        : 4;  /**< [ 61: 58](RO/H) Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
        uint64_t ecc_err_syndrome      : 18; /**< [ 57: 40](RO/H) Syndrome bits of the ECC error. */
        uint64_t ecc_err_address       : 8;  /**< [ 39: 32](RO/H) RAM address of the ECC error. */
        uint64_t reserved_21_31        : 11;
        uint64_t uctl_xm_r_ecc_flip_synd : 2;/**< [ 20: 19](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_r_ecc_cor_dis : 1;  /**< [ 18: 18](R/W) Enables ECC correction on UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_w_ecc_flip_synd : 2;/**< [ 17: 16](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_w_ecc_cor_dis : 1;  /**< [ 15: 15](R/W) Enables ECC correction on UCTL AxiMaster write-data FIFO. */
        uint64_t reserved_9_14         : 6;
        uint64_t uahc_rx_ecc_flip_synd : 2;  /**< [  8:  7](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_rx_ecc_cor_dis   : 1;  /**< [  6:  6](R/W) Enables ECC correction on UAHC RxFIFO RAMs. */
        uint64_t uahc_tx_ecc_flip_synd : 2;  /**< [  5:  4](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_tx_ecc_cor_dis   : 1;  /**< [  3:  3](R/W) Enables ECC correction on UAHC TxFIFO RAMs. */
        uint64_t uahc_fb_ecc_flip_synd : 2;  /**< [  2:  1](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_fb_ecc_cor_dis   : 1;  /**< [  0:  0](R/W) Enables ECC correction on UAHC FBS RAM. */
#else /* Word 0 - Little Endian */
        uint64_t uahc_fb_ecc_cor_dis   : 1;  /**< [  0:  0](R/W) Enables ECC correction on UAHC FBS RAM. */
        uint64_t uahc_fb_ecc_flip_synd : 2;  /**< [  2:  1](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_tx_ecc_cor_dis   : 1;  /**< [  3:  3](R/W) Enables ECC correction on UAHC TxFIFO RAMs. */
        uint64_t uahc_tx_ecc_flip_synd : 2;  /**< [  5:  4](R/W) Insert ECC error for testing purposes. */
        uint64_t uahc_rx_ecc_cor_dis   : 1;  /**< [  6:  6](R/W) Enables ECC correction on UAHC RxFIFO RAMs. */
        uint64_t uahc_rx_ecc_flip_synd : 2;  /**< [  8:  7](R/W) Insert ECC error for testing purposes. */
        uint64_t reserved_9_14         : 6;
        uint64_t uctl_xm_w_ecc_cor_dis : 1;  /**< [ 15: 15](R/W) Enables ECC correction on UCTL AxiMaster write-data FIFO. */
        uint64_t uctl_xm_w_ecc_flip_synd : 2;/**< [ 17: 16](R/W) Insert ECC error for testing purposes. */
        uint64_t uctl_xm_r_ecc_cor_dis : 1;  /**< [ 18: 18](R/W) Enables ECC correction on UCTL AxiMaster read-data FIFO. */
        uint64_t uctl_xm_r_ecc_flip_synd : 2;/**< [ 20: 19](R/W) Insert ECC error for testing purposes. */
        uint64_t reserved_21_31        : 11;
        uint64_t ecc_err_address       : 8;  /**< [ 39: 32](RO/H) RAM address of the ECC error. */
        uint64_t ecc_err_syndrome      : 18; /**< [ 57: 40](RO/H) Syndrome bits of the ECC error. */
        uint64_t ecc_err_source        : 4;  /**< [ 61: 58](RO/H) Source of ECC error, see UCTL_ECC_ERR_SOURCE_E. */
        uint64_t reserved_62_63        : 2;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_ecc_s cn; */
} bdk_satax_uctl_ecc_t;

static inline uint64_t BDK_SATAX_UCTL_ECC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_ECC(unsigned long a)
{
    if (a<=15)
        return 0x8100001000f0ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_ECC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_ECC(a) bdk_satax_uctl_ecc_t
#define bustype_BDK_SATAX_UCTL_ECC(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_ECC(a) "SATAX_UCTL_ECC"
#define busnum_BDK_SATAX_UCTL_ECC(a) (a)
#define arguments_BDK_SATAX_UCTL_ECC(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_intena_w1c
 *
 * SATA UCTL Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_intena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
#else /* Word 0 - Little Endian */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1C/H) Reads or clears enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_intena_w1c_s cn; */
} bdk_satax_uctl_intena_w1c_t;

static inline uint64_t BDK_SATAX_UCTL_INTENA_W1C(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTENA_W1C(unsigned long a)
{
    if (a<=15)
        return 0x810000100040ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_INTENA_W1C", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_INTENA_W1C(a) bdk_satax_uctl_intena_w1c_t
#define bustype_BDK_SATAX_UCTL_INTENA_W1C(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_INTENA_W1C(a) "SATAX_UCTL_INTENA_W1C"
#define busnum_BDK_SATAX_UCTL_INTENA_W1C(a) (a)
#define arguments_BDK_SATAX_UCTL_INTENA_W1C(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_intena_w1s
 *
 * SATA UCTL Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_intena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
#else /* Word 0 - Little Endian */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets enable for SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_intena_w1s_s cn; */
} bdk_satax_uctl_intena_w1s_t;

static inline uint64_t BDK_SATAX_UCTL_INTENA_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTENA_W1S(unsigned long a)
{
    if (a<=15)
        return 0x810000100048ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_INTENA_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_INTENA_W1S(a) bdk_satax_uctl_intena_w1s_t
#define bustype_BDK_SATAX_UCTL_INTENA_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_INTENA_W1S(a) "SATAX_UCTL_INTENA_W1S"
#define busnum_BDK_SATAX_UCTL_INTENA_W1S(a) (a)
#define arguments_BDK_SATAX_UCTL_INTENA_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_bistsr
 *
 * SATA UAHC BIST Status Register
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_bistsr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_24_31        : 8;
        uint32_t brsterr               : 8;  /**< [ 23: 16](RO) Burst error. */
        uint32_t framerr               : 16; /**< [ 15:  0](RO) Frame error. */
#else /* Word 0 - Little Endian */
        uint32_t framerr               : 16; /**< [ 15:  0](RO) Frame error. */
        uint32_t brsterr               : 8;  /**< [ 23: 16](RO) Burst error. */
        uint32_t reserved_24_31        : 8;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_bistsr_s cn; */
} bdk_satax_uahc_gbl_bistsr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTSR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000acll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_BISTSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_BISTSR(a) bdk_satax_uahc_gbl_bistsr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTSR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_BISTSR(a) "SATAX_UAHC_GBL_BISTSR"
#define busnum_BDK_SATAX_UAHC_GBL_BISTSR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_BISTSR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_bistafr
 *
 * SATA UAHC BIST Activate FIS Register
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * This register contains the pattern definition (bits 23:16 of the
 * first DWORD) and the data pattern (bits 7:0 of the second DWORD)
 * fields of the received BIST activate FIS.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_bistafr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Bits 7:0 of the second DWORD of BIST activate FIS.
                                                                 0xF1 = low transition density pattern (LTDP).
                                                                 0xB5 = high transition density pattern (HTDP).
                                                                 0xAB = low frequency spectral component pattern (LFSCP).
                                                                 0x7F = simultaneous switching outputs pattern (SSOP).
                                                                 0x78 = mid frequency test pattern (MFTP).
                                                                 0x4A = high frequency test pattern (HFTP).
                                                                 0x7E = low frequency test pattern (LFTP).
                                                                 else = lone bit pattern (LBP). */
        uint32_t pd                    : 8;  /**< [  7:  0](RO) Bits 23:16 of the first DWORD of the BIST activate FIS. Only the following values are
                                                                 supported:
                                                                 0x10 = Far-end retimed.
                                                                 0xC0 = Far-end transmit only.
                                                                 0xE0 = Far-end transmit only with scrambler bypassed. */
#else /* Word 0 - Little Endian */
        uint32_t pd                    : 8;  /**< [  7:  0](RO) Bits 23:16 of the first DWORD of the BIST activate FIS. Only the following values are
                                                                 supported:
                                                                 0x10 = Far-end retimed.
                                                                 0xC0 = Far-end transmit only.
                                                                 0xE0 = Far-end transmit only with scrambler bypassed. */
        uint32_t ncp                   : 8;  /**< [ 15:  8](RO) Bits 7:0 of the second DWORD of BIST activate FIS.
                                                                 0xF1 = low transition density pattern (LTDP).
                                                                 0xB5 = high transition density pattern (HTDP).
                                                                 0xAB = low frequency spectral component pattern (LFSCP).
                                                                 0x7F = simultaneous switching outputs pattern (SSOP).
                                                                 0x78 = mid frequency test pattern (MFTP).
                                                                 0x4A = high frequency test pattern (HFTP).
                                                                 0x7E = low frequency test pattern (LFTP).
                                                                 else = lone bit pattern (LBP). */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_bistafr_s cn; */
} bdk_satax_uahc_gbl_bistafr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTAFR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTAFR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000a0ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_BISTAFR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_BISTAFR(a) bdk_satax_uahc_gbl_bistafr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTAFR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_BISTAFR(a) "SATAX_UAHC_GBL_BISTAFR"
#define busnum_BDK_SATAX_UAHC_GBL_BISTAFR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_BISTAFR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_physr
 *
 * SATA UAHC PHY Status Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_physr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t stat                  : 32; /**< [ 31:  0](RO) Port PHY status. */
#else /* Word 0 - Little Endian */
        uint32_t stat                  : 32; /**< [ 31:  0](RO) Port PHY status. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_physr_s cn; */
} bdk_satax_uahc_p0_physr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_PHYSR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_PHYSR(unsigned long a)
{
    if (a<=15)
        return 0x81000000017cll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_PHYSR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_PHYSR(a) bdk_satax_uahc_p0_physr_t
#define bustype_BDK_SATAX_UAHC_P0_PHYSR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_PHYSR(a) "SATAX_UAHC_P0_PHYSR"
#define busnum_BDK_SATAX_UAHC_P0_PHYSR(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_PHYSR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_dmacr
 *
 * SATA UAHC DMA Control Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_dmacr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_8_31         : 24;
        uint32_t rxts                  : 4;  /**< [  7:  4](R/W) Receive transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
        uint32_t txts                  : 4;  /**< [  3:  0](R/W) Transmit transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
#else /* Word 0 - Little Endian */
        uint32_t txts                  : 4;  /**< [  3:  0](R/W) Transmit transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
        uint32_t rxts                  : 4;  /**< [  7:  4](R/W) Receive transaction size. This field is R/W when SATA()_UAHC_P0_CMD[ST] = 0
                                                                 and read only when SATA()_UAHC_P0_CMD[ST] = 1. */
        uint32_t reserved_8_31         : 24;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_dmacr_s cn; */
} bdk_satax_uahc_p0_dmacr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_DMACR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_DMACR(unsigned long a)
{
    if (a<=15)
        return 0x810000000170ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_DMACR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_DMACR(a) bdk_satax_uahc_p0_dmacr_t
#define bustype_BDK_SATAX_UAHC_P0_DMACR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_DMACR(a) "SATAX_UAHC_P0_DMACR"
#define busnum_BDK_SATAX_UAHC_P0_DMACR(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_DMACR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_testr
 *
 * SATA UAHC Test Register
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_testr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_19_31        : 13;
        uint32_t psel                  : 3;  /**< [ 18: 16](R/W) Port select. */
        uint32_t reserved_1_15         : 15;
        uint32_t test_if               : 1;  /**< [  0:  0](R/W) Test interface. */
#else /* Word 0 - Little Endian */
        uint32_t test_if               : 1;  /**< [  0:  0](R/W) Test interface. */
        uint32_t reserved_1_15         : 15;
        uint32_t psel                  : 3;  /**< [ 18: 16](R/W) Port select. */
        uint32_t reserved_19_31        : 13;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_testr_s cn; */
} bdk_satax_uahc_gbl_testr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_TESTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_TESTR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000f4ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_TESTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_TESTR(a) bdk_satax_uahc_gbl_testr_t
#define bustype_BDK_SATAX_UAHC_GBL_TESTR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_TESTR(a) "SATAX_UAHC_GBL_TESTR"
#define busnum_BDK_SATAX_UAHC_GBL_TESTR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_TESTR(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_spare0
 *
 * INTERNAL: SATA UCTL Spare Register 0
 *
 * This register is spare.
 *
 * Accessible always.
 *
 * Reset NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_spare0_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) Spare. */
#else /* Word 0 - Little Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) Spare. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_spare0_s cn; */
} bdk_satax_uctl_spare0_t;

static inline uint64_t BDK_SATAX_UCTL_SPARE0(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SPARE0(unsigned long a)
{
    if (a<=15)
        return 0x810000100010ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_SPARE0", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_SPARE0(a) bdk_satax_uctl_spare0_t
#define bustype_BDK_SATAX_UCTL_SPARE0(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_SPARE0(a) "SATAX_UCTL_SPARE0"
#define busnum_BDK_SATAX_UCTL_SPARE0(a) (a)
#define arguments_BDK_SATAX_UCTL_SPARE0(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_spare1
 *
 * INTERNAL: SATA UCTL Spare Register 1
 *
 * This register is spare.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_spare1_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) Spare. */
#else /* Word 0 - Little Endian */
        uint64_t spare                 : 64; /**< [ 63:  0](R/W) Spare. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_spare1_s cn; */
} bdk_satax_uctl_spare1_t;

static inline uint64_t BDK_SATAX_UCTL_SPARE1(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SPARE1(unsigned long a)
{
    if (a<=15)
        return 0x8100001000f8ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_SPARE1", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_SPARE1(a) bdk_satax_uctl_spare1_t
#define bustype_BDK_SATAX_UCTL_SPARE1(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_SPARE1(a) "SATAX_UCTL_SPARE1"
#define busnum_BDK_SATAX_UCTL_SPARE1(a) (a)
#define arguments_BDK_SATAX_UCTL_SPARE1(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_cap2
 *
 * SATA AHCI HBA Capabilities Extended Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_cap2_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_6_31         : 26;
        uint32_t deso                  : 1;  /**< [  5:  5](RO) Device sleep entrance from slumber only. */
        uint32_t sadm                  : 1;  /**< [  4:  4](RO) Supports aggressive device sleep management. */
        uint32_t sds                   : 1;  /**< [  3:  3](RO) Supports device sleep. */
        uint32_t apst                  : 1;  /**< [  2:  2](RO) Automatic partial to slumber transitions. */
        uint32_t nvmp                  : 1;  /**< [  1:  1](RO) NVMHCI present. */
        uint32_t boh                   : 1;  /**< [  0:  0](RO) Supports BIOS/OS handoff. */
#else /* Word 0 - Little Endian */
        uint32_t boh                   : 1;  /**< [  0:  0](RO) Supports BIOS/OS handoff. */
        uint32_t nvmp                  : 1;  /**< [  1:  1](RO) NVMHCI present. */
        uint32_t apst                  : 1;  /**< [  2:  2](RO) Automatic partial to slumber transitions. */
        uint32_t sds                   : 1;  /**< [  3:  3](RO) Supports device sleep. */
        uint32_t sadm                  : 1;  /**< [  4:  4](RO) Supports aggressive device sleep management. */
        uint32_t deso                  : 1;  /**< [  5:  5](RO) Device sleep entrance from slumber only. */
        uint32_t reserved_6_31         : 26;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_cap2_s cn; */
} bdk_satax_uahc_gbl_cap2_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CAP2(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CAP2(unsigned long a)
{
    if (a<=15)
        return 0x810000000024ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_CAP2", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_CAP2(a) bdk_satax_uahc_gbl_cap2_t
#define bustype_BDK_SATAX_UAHC_GBL_CAP2(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_CAP2(a) "SATAX_UAHC_GBL_CAP2"
#define busnum_BDK_SATAX_UAHC_GBL_CAP2(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_CAP2(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_ctl
 *
 * SATA UCTL Control Register
 * This register controls clocks, resets, power, and BIST for the SATA.
 *
 * Accessible always.
 *
 * Reset by NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t clear_bist            : 1;  /**< [ 63: 63](R/W) BIST fast-clear mode select. There are two major modes of BIST: FULL and CLEAR.
                                                                 0 = FULL BIST is run by the BIST state machine.
                                                                 1 = CLEAR BIST is run by the BIST state machine. A clear-BIST run clears all entries in
                                                                 SATA RAMs to 0x0.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts
                                                                 CLEAR_BIST into the correct state and then perform another CSR write operation to set
                                                                 START_BIST (keeping CLEAR_BIST constant). CLEAR BIST completion is indicated by
                                                                 SATA()_UCTL_BIST_STATUS[NDONE].

                                                                 A BIST clear operation takes almost 2,000 host-controller clock cycles for the largest
                                                                 RAM. */
        uint64_t start_bist            : 1;  /**< [ 62: 62](R/W) Start BIST. The rising edge starts BIST on the memories in SATA. To run BIST, the host-
                                                                 controller clock must be both configured and enabled, and should be configured to the
                                                                 maximum available frequency given the available coprocessor clock and dividers.

                                                                 Refer to Cold Reset for clock initialization procedures. BIST defect status can be checked
                                                                 after FULL BIST completion, both of which are indicated in SATA_UCTL_BIST_STATUS. The FULL
                                                                 BIST run takes almost 80,000 host-controller clock cycles for the largest RAM. */
        uint64_t reserved_31_61        : 31;
        uint64_t a_clk_en              : 1;  /**< [ 30: 30](R/W) Host-controller clock enable. When set to 1, the host-controller clock is generated. This
                                                                 also enables access to UCTL registers 0x30-0xF8. */
        uint64_t a_clk_byp_sel         : 1;  /**< [ 29: 29](R/W) Select the bypass input to the host-controller clock divider.
                                                                 0 = Use the divided coprocessor clock from the A_CLKDIV divider.
                                                                 1 = use the bypass clock from the GPIO pins (generally bypass is only used for scan
                                                                 purposes).

                                                                 This signal is a multiplexer-select signal; it does not enable the host-controller clock.
                                                                 You must set A_CLK_EN separately. A_CLK_BYP_SEL select should not be changed unless
                                                                 A_CLK_EN is disabled. The bypass clock can be selected and running even if the host-
                                                                 controller clock dividers are not running. */
        uint64_t a_clkdiv_rst          : 1;  /**< [ 28: 28](R/W) Host-controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
        uint64_t reserved_27           : 1;
        uint64_t a_clkdiv_sel          : 3;  /**< [ 26: 24](R/W) The host-controller clock frequency is the coprocessor-clock frequency divided by
                                                                 A_CLKDIV_SEL. The host-controller clock frequency must be at or below 333MHz.
                                                                 This field can be changed only when A_CLKDIV_RST = 1. The divider values are the
                                                                 following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 3.
                                                                 0x3 = divide by 4.
                                                                 0x4 = divide by 6.
                                                                 0x5 = divide by 8.
                                                                 0x6 = divide by 16.
                                                                 0x7 = divide by 24. */
        uint64_t reserved_5_23         : 19;
        uint64_t csclk_en              : 1;  /**< [  4:  4](R/W) Turns on the SATA UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 registers via the NCB, as well as UCTL registers starting from 0x10_0030.
                                                                 Changed in pass 2. */
        uint64_t reserved_2_3          : 2;
        uint64_t sata_uahc_rst         : 1;  /**< [  1:  1](R/W) Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
        uint64_t sata_uctl_rst         : 1;  /**< [  0:  0](R/W) Software reset; resets UCTL; active-high. Resets UAHC DMA and register shims and the UCTL
                                                                 registers 0x10_0030-0x10_00F8.

                                                                 It does not reset UCTL registers 0x10_0000-0x10_0028.

                                                                 The UCTL registers starting from 0x10_0030 can be accessed only after the host-controller
                                                                 clock is active and UCTL_RST is deasserted.

                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and GIB protocols. */
#else /* Word 0 - Little Endian */
        uint64_t sata_uctl_rst         : 1;  /**< [  0:  0](R/W) Software reset; resets UCTL; active-high. Resets UAHC DMA and register shims and the UCTL
                                                                 registers 0x10_0030-0x10_00F8.

                                                                 It does not reset UCTL registers 0x10_0000-0x10_0028.

                                                                 The UCTL registers starting from 0x10_0030 can be accessed only after the host-controller
                                                                 clock is active and UCTL_RST is deasserted.

                                                                 INTERNAL: Note that soft-resetting the UCTL while it is active may cause violations of
                                                                 RSL, NCB, and GIB protocols. */
        uint64_t sata_uahc_rst         : 1;  /**< [  1:  1](R/W) Software reset; resets UAHC; active-high.
                                                                 INTERNAL: Note that soft-resetting the UAHC while it is active may cause violations of RSL
                                                                 or NCB protocols. */
        uint64_t reserved_2_3          : 2;
        uint64_t csclk_en              : 1;  /**< [  4:  4](R/W) Turns on the SATA UCTL interface clock (coprocessor clock). This enables access to UAHC
                                                                 registers via the NCB, as well as UCTL registers starting from 0x10_0030.
                                                                 Changed in pass 2. */
        uint64_t reserved_5_23         : 19;
        uint64_t a_clkdiv_sel          : 3;  /**< [ 26: 24](R/W) The host-controller clock frequency is the coprocessor-clock frequency divided by
                                                                 A_CLKDIV_SEL. The host-controller clock frequency must be at or below 333MHz.
                                                                 This field can be changed only when A_CLKDIV_RST = 1. The divider values are the
                                                                 following:
                                                                 0x0 = divide by 1.
                                                                 0x1 = divide by 2.
                                                                 0x2 = divide by 3.
                                                                 0x3 = divide by 4.
                                                                 0x4 = divide by 6.
                                                                 0x5 = divide by 8.
                                                                 0x6 = divide by 16.
                                                                 0x7 = divide by 24. */
        uint64_t reserved_27           : 1;
        uint64_t a_clkdiv_rst          : 1;  /**< [ 28: 28](R/W) Host-controller-clock divider reset. Divided clocks are not generated while the divider is
                                                                 being reset.
                                                                 This also resets the suspend-clock divider. */
        uint64_t a_clk_byp_sel         : 1;  /**< [ 29: 29](R/W) Select the bypass input to the host-controller clock divider.
                                                                 0 = Use the divided coprocessor clock from the A_CLKDIV divider.
                                                                 1 = use the bypass clock from the GPIO pins (generally bypass is only used for scan
                                                                 purposes).

                                                                 This signal is a multiplexer-select signal; it does not enable the host-controller clock.
                                                                 You must set A_CLK_EN separately. A_CLK_BYP_SEL select should not be changed unless
                                                                 A_CLK_EN is disabled. The bypass clock can be selected and running even if the host-
                                                                 controller clock dividers are not running. */
        uint64_t a_clk_en              : 1;  /**< [ 30: 30](R/W) Host-controller clock enable. When set to 1, the host-controller clock is generated. This
                                                                 also enables access to UCTL registers 0x30-0xF8. */
        uint64_t reserved_31_61        : 31;
        uint64_t start_bist            : 1;  /**< [ 62: 62](R/W) Start BIST. The rising edge starts BIST on the memories in SATA. To run BIST, the host-
                                                                 controller clock must be both configured and enabled, and should be configured to the
                                                                 maximum available frequency given the available coprocessor clock and dividers.

                                                                 Refer to Cold Reset for clock initialization procedures. BIST defect status can be checked
                                                                 after FULL BIST completion, both of which are indicated in SATA_UCTL_BIST_STATUS. The FULL
                                                                 BIST run takes almost 80,000 host-controller clock cycles for the largest RAM. */
        uint64_t clear_bist            : 1;  /**< [ 63: 63](R/W) BIST fast-clear mode select. There are two major modes of BIST: FULL and CLEAR.
                                                                 0 = FULL BIST is run by the BIST state machine.
                                                                 1 = CLEAR BIST is run by the BIST state machine. A clear-BIST run clears all entries in
                                                                 SATA RAMs to 0x0.

                                                                 To avoid race conditions, software must first perform a CSR write operation that puts
                                                                 CLEAR_BIST into the correct state and then perform another CSR write operation to set
                                                                 START_BIST (keeping CLEAR_BIST constant). CLEAR BIST completion is indicated by
                                                                 SATA()_UCTL_BIST_STATUS[NDONE].

                                                                 A BIST clear operation takes almost 2,000 host-controller clock cycles for the largest
                                                                 RAM. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_ctl_s cn; */
} bdk_satax_uctl_ctl_t;

static inline uint64_t BDK_SATAX_UCTL_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_CTL(unsigned long a)
{
    if (a<=15)
        return 0x810000100000ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_CTL(a) bdk_satax_uctl_ctl_t
#define bustype_BDK_SATAX_UCTL_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_CTL(a) "SATAX_UCTL_CTL"
#define busnum_BDK_SATAX_UCTL_CTL(a) (a)
#define arguments_BDK_SATAX_UCTL_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_timer1ms
 *
 * SATA UAHC Timer 1ms Register
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_timer1ms_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t timv                  : 20; /**< [ 19:  0](R/W) 1ms timer value. Writable only when SATA()_UAHC_GBL_CCC_CTL[EN] = 0. */
#else /* Word 0 - Little Endian */
        uint32_t timv                  : 20; /**< [ 19:  0](R/W) 1ms timer value. Writable only when SATA()_UAHC_GBL_CCC_CTL[EN] = 0. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_timer1ms_s cn; */
} bdk_satax_uahc_gbl_timer1ms_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_TIMER1MS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_TIMER1MS(unsigned long a)
{
    if (a<=15)
        return 0x8100000000e0ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_TIMER1MS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_TIMER1MS(a) bdk_satax_uahc_gbl_timer1ms_t
#define bustype_BDK_SATAX_UAHC_GBL_TIMER1MS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_TIMER1MS(a) "SATAX_UAHC_GBL_TIMER1MS"
#define busnum_BDK_SATAX_UAHC_GBL_TIMER1MS(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_TIMER1MS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_bistcr
 *
 * SATA UAHC BIST Control Register
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_bistcr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_26_31        : 6;
        uint32_t old_phy_ready         : 1;  /**< [ 25: 25](R/W) Old phy_ready. Do not change the value of this bit. */
        uint32_t late_phy_ready        : 1;  /**< [ 24: 24](R/W) Late phy_ready. */
        uint32_t reserved_21_23        : 3;
        uint32_t ferlib                : 1;  /**< [ 20: 20](WO) Far-end retimed loopback. */
        uint32_t reserved_19           : 1;
        uint32_t txo                   : 1;  /**< [ 18: 18](WO) Transmit only. */
        uint32_t cntclr                : 1;  /**< [ 17: 17](WO) Counter clear. */
        uint32_t nealb                 : 1;  /**< [ 16: 16](WO) Near-end analog loopback. */
        uint32_t llb                   : 1;  /**< [ 15: 15](R/W) Lab loopback mode. */
        uint32_t reserved_14           : 1;
        uint32_t errlossen             : 1;  /**< [ 13: 13](R/W) Error loss detect enable. */
        uint32_t sdfe                  : 1;  /**< [ 12: 12](R/W) Signal detect feature enable. */
        uint32_t rsvd_1rsvd_11         : 1;  /**< [ 11: 11](R/W) Reserved. */
        uint32_t llc                   : 3;  /**< [ 10:  8](R/W) Link layer control.
                                                                 <10> = RPD - repeat primitive drop enable.
                                                                 <9> = DESCRAM - descrambler enable.
                                                                 <8> = SCRAM - scrambler enable. */
        uint32_t reserved_7            : 1;
        uint32_t erren                 : 1;  /**< [  6:  6](R/W) Error enable. */
        uint32_t flip                  : 1;  /**< [  5:  5](R/W) Flip disparity. */
        uint32_t pv                    : 1;  /**< [  4:  4](R/W) Pattern version. */
        uint32_t pattern               : 4;  /**< [  3:  0](RO) SATA compliant pattern selection. */
#else /* Word 0 - Little Endian */
        uint32_t pattern               : 4;  /**< [  3:  0](RO) SATA compliant pattern selection. */
        uint32_t pv                    : 1;  /**< [  4:  4](R/W) Pattern version. */
        uint32_t flip                  : 1;  /**< [  5:  5](R/W) Flip disparity. */
        uint32_t erren                 : 1;  /**< [  6:  6](R/W) Error enable. */
        uint32_t reserved_7            : 1;
        uint32_t llc                   : 3;  /**< [ 10:  8](R/W) Link layer control.
                                                                 <10> = RPD - repeat primitive drop enable.
                                                                 <9> = DESCRAM - descrambler enable.
                                                                 <8> = SCRAM - scrambler enable. */
        uint32_t rsvd_1rsvd_11         : 1;  /**< [ 11: 11](R/W) Reserved. */
        uint32_t sdfe                  : 1;  /**< [ 12: 12](R/W) Signal detect feature enable. */
        uint32_t errlossen             : 1;  /**< [ 13: 13](R/W) Error loss detect enable. */
        uint32_t reserved_14           : 1;
        uint32_t llb                   : 1;  /**< [ 15: 15](R/W) Lab loopback mode. */
        uint32_t nealb                 : 1;  /**< [ 16: 16](WO) Near-end analog loopback. */
        uint32_t cntclr                : 1;  /**< [ 17: 17](WO) Counter clear. */
        uint32_t txo                   : 1;  /**< [ 18: 18](WO) Transmit only. */
        uint32_t reserved_19           : 1;
        uint32_t ferlib                : 1;  /**< [ 20: 20](WO) Far-end retimed loopback. */
        uint32_t reserved_21_23        : 3;
        uint32_t late_phy_ready        : 1;  /**< [ 24: 24](R/W) Late phy_ready. */
        uint32_t old_phy_ready         : 1;  /**< [ 25: 25](R/W) Old phy_ready. Do not change the value of this bit. */
        uint32_t reserved_26_31        : 6;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_bistcr_s cn; */
} bdk_satax_uahc_gbl_bistcr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTCR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000a4ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_BISTCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_BISTCR(a) bdk_satax_uahc_gbl_bistcr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTCR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_BISTCR(a) "SATAX_UAHC_GBL_BISTCR"
#define busnum_BDK_SATAX_UAHC_GBL_BISTCR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_BISTCR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_ccc_ctl
 *
 * SATA AHCI CCC Control Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_ccc_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t tv                    : 16; /**< [ 31: 16](R/W) Time-out value. Writable only when EN = 0. */
        uint32_t cc                    : 8;  /**< [ 15:  8](R/W) Command completions. Writable only when EN = 0. */
        uint32_t intr                  : 5;  /**< [  7:  3](RO) Specifies the port interrupt used by the CCC feature. */
        uint32_t reserved_1_2          : 2;
        uint32_t en                    : 1;  /**< [  0:  0](R/W) CCC enable. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) CCC enable. */
        uint32_t reserved_1_2          : 2;
        uint32_t intr                  : 5;  /**< [  7:  3](RO) Specifies the port interrupt used by the CCC feature. */
        uint32_t cc                    : 8;  /**< [ 15:  8](R/W) Command completions. Writable only when EN = 0. */
        uint32_t tv                    : 16; /**< [ 31: 16](R/W) Time-out value. Writable only when EN = 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_ccc_ctl_s cn; */
} bdk_satax_uahc_gbl_ccc_ctl_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_CTL(unsigned long a)
{
    if (a<=15)
        return 0x810000000014ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_CCC_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_CCC_CTL(a) bdk_satax_uahc_gbl_ccc_ctl_t
#define bustype_BDK_SATAX_UAHC_GBL_CCC_CTL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_CCC_CTL(a) "SATAX_UAHC_GBL_CCC_CTL"
#define busnum_BDK_SATAX_UAHC_GBL_CCC_CTL(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_CCC_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_cmd
 *
 * SATA UAHC Command Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t icc                   : 4;  /**< [ 31: 28](R/W) Interface communication control. */
        uint32_t asp                   : 1;  /**< [ 27: 27](R/W) Aggressive slumber/partial. */
        uint32_t alpe                  : 1;  /**< [ 26: 26](R/W) Aggressive link-power-management enable. */
        uint32_t dlae                  : 1;  /**< [ 25: 25](R/W) Drive LED on ATAPI enable. */
        uint32_t atapi                 : 1;  /**< [ 24: 24](R/W) Device is ATAPI. */
        uint32_t apste                 : 1;  /**< [ 23: 23](R/W) Automatic partial to slumber transitions enable. */
        uint32_t fbscp                 : 1;  /**< [ 22: 22](R/W) FIS-based switching capable port. Write-once. */
        uint32_t esp                   : 1;  /**< [ 21: 21](R/W) External SATA port. Write-once. */
        uint32_t cpd                   : 1;  /**< [ 20: 20](R/W) Cold-presence detection. Write-once. */
        uint32_t mpsp                  : 1;  /**< [ 19: 19](R/W) Mechanical presence switch attached to port. Write-once. */
        uint32_t hpcp                  : 1;  /**< [ 18: 18](R/W) Hot-plug-capable support. Write-once. */
        uint32_t pma                   : 1;  /**< [ 17: 17](R/W) Port multiplier attached. */
        uint32_t cps                   : 1;  /**< [ 16: 16](RO) Cold presence state. */
        uint32_t cr                    : 1;  /**< [ 15: 15](RO) Command list running. */
        uint32_t fr                    : 1;  /**< [ 14: 14](RO/H) FIS receive running. */
        uint32_t mpss                  : 1;  /**< [ 13: 13](RO) Mechanical presence switch state. */
        uint32_t ccs                   : 5;  /**< [ 12:  8](RO) Current-command slot. */
        uint32_t reserved_5_7          : 3;
        uint32_t fre                   : 1;  /**< [  4:  4](R/W) FIS-receive enable. */
        uint32_t clo                   : 1;  /**< [  3:  3](WO) Command-list override. */
        uint32_t pod                   : 1;  /**< [  2:  2](R/W) Power-on device. R/W only if CPD = 1, else read only. */
        uint32_t sud                   : 1;  /**< [  1:  1](R/W) Spin-up device. R/W only if SATA()_UAHC_GBL_CAP[SSS]=1, else read only.
                                                                 Setting this bit triggers a COMRESET initialization sequence. */
        uint32_t st                    : 1;  /**< [  0:  0](R/W) Start. */
#else /* Word 0 - Little Endian */
        uint32_t st                    : 1;  /**< [  0:  0](R/W) Start. */
        uint32_t sud                   : 1;  /**< [  1:  1](R/W) Spin-up device. R/W only if SATA()_UAHC_GBL_CAP[SSS]=1, else read only.
                                                                 Setting this bit triggers a COMRESET initialization sequence. */
        uint32_t pod                   : 1;  /**< [  2:  2](R/W) Power-on device. R/W only if CPD = 1, else read only. */
        uint32_t clo                   : 1;  /**< [  3:  3](WO) Command-list override. */
        uint32_t fre                   : 1;  /**< [  4:  4](R/W) FIS-receive enable. */
        uint32_t reserved_5_7          : 3;
        uint32_t ccs                   : 5;  /**< [ 12:  8](RO) Current-command slot. */
        uint32_t mpss                  : 1;  /**< [ 13: 13](RO) Mechanical presence switch state. */
        uint32_t fr                    : 1;  /**< [ 14: 14](RO/H) FIS receive running. */
        uint32_t cr                    : 1;  /**< [ 15: 15](RO) Command list running. */
        uint32_t cps                   : 1;  /**< [ 16: 16](RO) Cold presence state. */
        uint32_t pma                   : 1;  /**< [ 17: 17](R/W) Port multiplier attached. */
        uint32_t hpcp                  : 1;  /**< [ 18: 18](R/W) Hot-plug-capable support. Write-once. */
        uint32_t mpsp                  : 1;  /**< [ 19: 19](R/W) Mechanical presence switch attached to port. Write-once. */
        uint32_t cpd                   : 1;  /**< [ 20: 20](R/W) Cold-presence detection. Write-once. */
        uint32_t esp                   : 1;  /**< [ 21: 21](R/W) External SATA port. Write-once. */
        uint32_t fbscp                 : 1;  /**< [ 22: 22](R/W) FIS-based switching capable port. Write-once. */
        uint32_t apste                 : 1;  /**< [ 23: 23](R/W) Automatic partial to slumber transitions enable. */
        uint32_t atapi                 : 1;  /**< [ 24: 24](R/W) Device is ATAPI. */
        uint32_t dlae                  : 1;  /**< [ 25: 25](R/W) Drive LED on ATAPI enable. */
        uint32_t alpe                  : 1;  /**< [ 26: 26](R/W) Aggressive link-power-management enable. */
        uint32_t asp                   : 1;  /**< [ 27: 27](R/W) Aggressive slumber/partial. */
        uint32_t icc                   : 4;  /**< [ 31: 28](R/W) Interface communication control. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_cmd_s cn; */
} bdk_satax_uahc_p0_cmd_t;

static inline uint64_t BDK_SATAX_UAHC_P0_CMD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_CMD(unsigned long a)
{
    if (a<=15)
        return 0x810000000118ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_CMD", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_CMD(a) bdk_satax_uahc_p0_cmd_t
#define bustype_BDK_SATAX_UAHC_P0_CMD(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_CMD(a) "SATAX_UAHC_P0_CMD"
#define busnum_BDK_SATAX_UAHC_P0_CMD(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_CMD(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_pi
 *
 * SATA AHCI Ports Implemented Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_pi_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t pi                    : 1;  /**< [  0:  0](R/W) Number of ports implemented. This field is one-time writable, then becomes read-only. */
#else /* Word 0 - Little Endian */
        uint32_t pi                    : 1;  /**< [  0:  0](R/W) Number of ports implemented. This field is one-time writable, then becomes read-only. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_pi_s cn; */
} bdk_satax_uahc_gbl_pi_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_PI(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_PI(unsigned long a)
{
    if (a<=15)
        return 0x81000000000cll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_PI", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_PI(a) bdk_satax_uahc_gbl_pi_t
#define bustype_BDK_SATAX_UAHC_GBL_PI(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_PI(a) "SATAX_UAHC_GBL_PI"
#define busnum_BDK_SATAX_UAHC_GBL_PI(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_PI(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_shim_cfg
 *
 * SATA UCTL Shim Configuration Register
 * This register allows configuration of various shim (UCTL) features.
 *
 * Fields XS_NCB_OOB_* are captured when there are no outstanding OOB errors indicated in INTSTAT
 * and a new OOB error arrives.
 *
 * Fields XS_BAD_DMA_* are captured when there are no outstanding DMA errors indicated in INTSTAT
 * and a new DMA error arrives.
 *
 * Accessible only when SATA()_UCTL_CTL[A_CLK_EN].
 *
 * Reset by NCB reset or SATA()_UCTL_CTL[SATA_UCTL_RST].
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_shim_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t xs_ncb_oob_wrn        : 1;  /**< [ 63: 63](RO/H) Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
        uint64_t reserved_60_62        : 3;
        uint64_t xs_ncb_oob_osrc       : 12; /**< [ 59: 48](RO/H) SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 <59:58> = chipID.
                                                                 <57> = Request source: 0 = core, 1 = NCB-device.
                                                                 <56:51> = core/NCB-device number. Note that for NCB devices, <56> is always 0.
                                                                 <50:48> = SubID. */
        uint64_t xm_bad_dma_wrn        : 1;  /**< [ 47: 47](RO/H) Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log. */
        uint64_t reserved_44_46        : 3;
        uint64_t xm_bad_dma_type       : 4;  /**< [ 43: 40](RO/H) ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See SATA_UCTL_XM_BAD_DMA_TYPE_E. */
        uint64_t reserved_14_39        : 26;
        uint64_t dma_read_cmd          : 2;  /**< [ 13: 12](R/W) Selects the NCB read command used by DMA accesses. See SATA_UCTL_DMA_READ_CMD_E. */
        uint64_t reserved_11           : 1;
        uint64_t dma_write_cmd         : 1;  /**< [ 10: 10](R/W) Selects the NCB write command used by DMA accesses. See enum SATA_UCTL_DMA_WRITE_CMD_E. */
        uint64_t reserved_0_9          : 10;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_9          : 10;
        uint64_t dma_write_cmd         : 1;  /**< [ 10: 10](R/W) Selects the NCB write command used by DMA accesses. See enum SATA_UCTL_DMA_WRITE_CMD_E. */
        uint64_t reserved_11           : 1;
        uint64_t dma_read_cmd          : 2;  /**< [ 13: 12](R/W) Selects the NCB read command used by DMA accesses. See SATA_UCTL_DMA_READ_CMD_E. */
        uint64_t reserved_14_39        : 26;
        uint64_t xm_bad_dma_type       : 4;  /**< [ 43: 40](RO/H) ErrType error log for bad DMA access from UAHC. Encodes the type of error encountered
                                                                 (error largest encoded value has priority). See SATA_UCTL_XM_BAD_DMA_TYPE_E. */
        uint64_t reserved_44_46        : 3;
        uint64_t xm_bad_dma_wrn        : 1;  /**< [ 47: 47](RO/H) Read/write error log for bad DMA access from UAHC.
                                                                 0 = read error log, 1 = write error log. */
        uint64_t xs_ncb_oob_osrc       : 12; /**< [ 59: 48](RO/H) SRCID error log for out-of-bound UAHC register access. The NCB outbound SRCID for the OOB
                                                                 error.
                                                                 <59:58> = chipID.
                                                                 <57> = Request source: 0 = core, 1 = NCB-device.
                                                                 <56:51> = core/NCB-device number. Note that for NCB devices, <56> is always 0.
                                                                 <50:48> = SubID. */
        uint64_t reserved_60_62        : 3;
        uint64_t xs_ncb_oob_wrn        : 1;  /**< [ 63: 63](RO/H) Read/write error log for out-of-bound UAHC register access.
                                                                 0 = read, 1 = write. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_shim_cfg_s cn; */
} bdk_satax_uctl_shim_cfg_t;

static inline uint64_t BDK_SATAX_UCTL_SHIM_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_SHIM_CFG(unsigned long a)
{
    if (a<=15)
        return 0x8100001000e8ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_SHIM_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_SHIM_CFG(a) bdk_satax_uctl_shim_cfg_t
#define bustype_BDK_SATAX_UCTL_SHIM_CFG(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_SHIM_CFG(a) "SATAX_UCTL_SHIM_CFG"
#define busnum_BDK_SATAX_UCTL_SHIM_CFG(a) (a)
#define arguments_BDK_SATAX_UCTL_SHIM_CFG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_sctl
 *
 * SATA UAHC SATA Control Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_sctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_10_31        : 22;
        uint32_t ipm                   : 2;  /**< [  9:  8](R/W) Interface power-management transitions allowed. */
        uint32_t reserved_6_7          : 2;
        uint32_t spd                   : 2;  /**< [  5:  4](R/W) Speed allowed. */
        uint32_t reserved_3            : 1;
        uint32_t det                   : 3;  /**< [  2:  0](R/W) Device-detection initialization. */
#else /* Word 0 - Little Endian */
        uint32_t det                   : 3;  /**< [  2:  0](R/W) Device-detection initialization. */
        uint32_t reserved_3            : 1;
        uint32_t spd                   : 2;  /**< [  5:  4](R/W) Speed allowed. */
        uint32_t reserved_6_7          : 2;
        uint32_t ipm                   : 2;  /**< [  9:  8](R/W) Interface power-management transitions allowed. */
        uint32_t reserved_10_31        : 22;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_sctl_s cn; */
} bdk_satax_uahc_p0_sctl_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SCTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SCTL(unsigned long a)
{
    if (a<=15)
        return 0x81000000012cll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SCTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SCTL(a) bdk_satax_uahc_p0_sctl_t
#define bustype_BDK_SATAX_UAHC_P0_SCTL(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SCTL(a) "SATAX_UAHC_P0_SCTL"
#define busnum_BDK_SATAX_UAHC_P0_SCTL(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SCTL(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_ssts
 *
 * SATA UAHC SATA Status Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_ssts_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t ipm                   : 4;  /**< [ 11:  8](RO/H) Interface power management. */
        uint32_t spd                   : 4;  /**< [  7:  4](RO/H) Current interface speed. */
        uint32_t det                   : 4;  /**< [  3:  0](RO/H) Device detection. */
#else /* Word 0 - Little Endian */
        uint32_t det                   : 4;  /**< [  3:  0](RO/H) Device detection. */
        uint32_t spd                   : 4;  /**< [  7:  4](RO/H) Current interface speed. */
        uint32_t ipm                   : 4;  /**< [ 11:  8](RO/H) Interface power management. */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_ssts_s cn; */
} bdk_satax_uahc_p0_ssts_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SSTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SSTS(unsigned long a)
{
    if (a<=15)
        return 0x810000000128ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SSTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SSTS(a) bdk_satax_uahc_p0_ssts_t
#define bustype_BDK_SATAX_UAHC_P0_SSTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SSTS(a) "SATAX_UAHC_P0_SSTS"
#define busnum_BDK_SATAX_UAHC_P0_SSTS(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SSTS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_vs
 *
 * SATA AHCI Version Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_vs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t mjr                   : 16; /**< [ 31: 16](RO) Major version number. */
        uint32_t mnr                   : 16; /**< [ 15:  0](RO) Minor version number. No DEVSLP support. */
#else /* Word 0 - Little Endian */
        uint32_t mnr                   : 16; /**< [ 15:  0](RO) Minor version number. No DEVSLP support. */
        uint32_t mjr                   : 16; /**< [ 31: 16](RO) Major version number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_vs_s cn; */
} bdk_satax_uahc_gbl_vs_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_VS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_VS(unsigned long a)
{
    if (a<=15)
        return 0x810000000010ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_VS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_VS(a) bdk_satax_uahc_gbl_vs_t
#define bustype_BDK_SATAX_UAHC_GBL_VS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_VS(a) "SATAX_UAHC_GBL_VS"
#define busnum_BDK_SATAX_UAHC_GBL_VS(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_VS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_gparam2r
 *
 * SATA UAHC Global Parameter Register 2
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_gparam2r_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_31           : 1;
        uint32_t rxoob_clk_units       : 1;  /**< [ 30: 30](RO) RX OOB clock frequency units. */
        uint32_t rxoob_clk_upper       : 10; /**< [ 29: 20](RO) Upper bits of RX OOB clock frequency. */
        uint32_t bist_m                : 1;  /**< [ 19: 19](RO) BIST loopback checking depth (BIST_MODE). */
        uint32_t fbs_mem_s             : 1;  /**< [ 18: 18](RO) Context RAM memory location (FBS_MEM_S). */
        uint32_t fbs_pmpn              : 2;  /**< [ 17: 16](RO) Maximum number of port multiplier ports (FBS_PMPN_MAX). */
        uint32_t fbs_support           : 1;  /**< [ 15: 15](RO) FIS-based switching support (FBS_SUPPORT). */
        uint32_t dev_cp                : 1;  /**< [ 14: 14](RO) Cold presence detect (DEV_CP_DET). */
        uint32_t dev_mp                : 1;  /**< [ 13: 13](RO) Mechanical presence switch (DEV_MP_SWITCH). */
        uint32_t encode_m              : 1;  /**< [ 12: 12](RO) 8b/10b encoding/decoding (ENCODE_MODE). */
        uint32_t rxoob_clk_m           : 1;  /**< [ 11: 11](RO) RX OOB clock mode (RXOOB_CLK_MODE). */
        uint32_t rx_oob_m              : 1;  /**< [ 10: 10](RO) RX OOB mode (RX_OOB_MODE). */
        uint32_t tx_oob_m              : 1;  /**< [  9:  9](RO) TX OOB mode (TX_OOB_MODE). */
        uint32_t rxoob_clk             : 9;  /**< [  8:  0](RO) RX OOB clock frequency (RXOOB_CLK). */
#else /* Word 0 - Little Endian */
        uint32_t rxoob_clk             : 9;  /**< [  8:  0](RO) RX OOB clock frequency (RXOOB_CLK). */
        uint32_t tx_oob_m              : 1;  /**< [  9:  9](RO) TX OOB mode (TX_OOB_MODE). */
        uint32_t rx_oob_m              : 1;  /**< [ 10: 10](RO) RX OOB mode (RX_OOB_MODE). */
        uint32_t rxoob_clk_m           : 1;  /**< [ 11: 11](RO) RX OOB clock mode (RXOOB_CLK_MODE). */
        uint32_t encode_m              : 1;  /**< [ 12: 12](RO) 8b/10b encoding/decoding (ENCODE_MODE). */
        uint32_t dev_mp                : 1;  /**< [ 13: 13](RO) Mechanical presence switch (DEV_MP_SWITCH). */
        uint32_t dev_cp                : 1;  /**< [ 14: 14](RO) Cold presence detect (DEV_CP_DET). */
        uint32_t fbs_support           : 1;  /**< [ 15: 15](RO) FIS-based switching support (FBS_SUPPORT). */
        uint32_t fbs_pmpn              : 2;  /**< [ 17: 16](RO) Maximum number of port multiplier ports (FBS_PMPN_MAX). */
        uint32_t fbs_mem_s             : 1;  /**< [ 18: 18](RO) Context RAM memory location (FBS_MEM_S). */
        uint32_t bist_m                : 1;  /**< [ 19: 19](RO) BIST loopback checking depth (BIST_MODE). */
        uint32_t rxoob_clk_upper       : 10; /**< [ 29: 20](RO) Upper bits of RX OOB clock frequency. */
        uint32_t rxoob_clk_units       : 1;  /**< [ 30: 30](RO) RX OOB clock frequency units. */
        uint32_t reserved_31           : 1;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_gparam2r_s cn; */
} bdk_satax_uahc_gbl_gparam2r_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM2R(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM2R(unsigned long a)
{
    if (a<=15)
        return 0x8100000000ecll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_GPARAM2R", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_GPARAM2R(a) bdk_satax_uahc_gbl_gparam2r_t
#define bustype_BDK_SATAX_UAHC_GBL_GPARAM2R(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_GPARAM2R(a) "SATAX_UAHC_GBL_GPARAM2R"
#define busnum_BDK_SATAX_UAHC_GBL_GPARAM2R(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_GPARAM2R(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_versionr
 *
 * SATA UAHC Version Register
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_versionr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ver                   : 32; /**< [ 31:  0](RO) SATA IP version number. */
#else /* Word 0 - Little Endian */
        uint32_t ver                   : 32; /**< [ 31:  0](RO) SATA IP version number. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_versionr_s cn; */
} bdk_satax_uahc_gbl_versionr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_VERSIONR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_VERSIONR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000f8ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_VERSIONR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_VERSIONR(a) bdk_satax_uahc_gbl_versionr_t
#define bustype_BDK_SATAX_UAHC_GBL_VERSIONR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_VERSIONR(a) "SATAX_UAHC_GBL_VERSIONR"
#define busnum_BDK_SATAX_UAHC_GBL_VERSIONR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_VERSIONR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_is
 *
 * SATA AHCI Interrupt Status Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_is_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_2_31         : 30;
        uint32_t ips                   : 2;  /**< [  1:  0](R/W1C/H) Interrupt pending status. */
#else /* Word 0 - Little Endian */
        uint32_t ips                   : 2;  /**< [  1:  0](R/W1C/H) Interrupt pending status. */
        uint32_t reserved_2_31         : 30;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_is_s cn; */
} bdk_satax_uahc_gbl_is_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_IS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_IS(unsigned long a)
{
    if (a<=15)
        return 0x810000000008ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_IS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_IS(a) bdk_satax_uahc_gbl_is_t
#define bustype_BDK_SATAX_UAHC_GBL_IS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_IS(a) "SATAX_UAHC_GBL_IS"
#define busnum_BDK_SATAX_UAHC_GBL_IS(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_IS(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_intstat_w1s
 *
 * SATA UCTL Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_intstat_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
#else /* Word 0 - Little Endian */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XS_NCB_OOB]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_BAD_DMA]. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_W_SBE]. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_W_DBE]. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_R_SBE]. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[XM_R_DBE]. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[DMA_WR_ERR]. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[DMA_RD_ERR]. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_FB_SBE]. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_FB_DBE]. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_TX_SBE]. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_TX_DBE]. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_RX_SBE]. */
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1S/H) Reads or sets SATA(0..15)_UCTL_INTSTAT[UAHC_RX_DBE]. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_intstat_w1s_s cn; */
} bdk_satax_uctl_intstat_w1s_t;

static inline uint64_t BDK_SATAX_UCTL_INTSTAT_W1S(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTSTAT_W1S(unsigned long a)
{
    if (a<=15)
        return 0x810000100038ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_INTSTAT_W1S", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_INTSTAT_W1S(a) bdk_satax_uctl_intstat_w1s_t
#define bustype_BDK_SATAX_UCTL_INTSTAT_W1S(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_INTSTAT_W1S(a) "SATAX_UCTL_INTSTAT_W1S"
#define busnum_BDK_SATAX_UCTL_INTSTAT_W1S(a) (a)
#define arguments_BDK_SATAX_UCTL_INTSTAT_W1S(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uahc_p0_fb
 *
 * SATA UAHC FIS Base-Address Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uahc_p0_fb_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t fb                    : 56; /**< [ 63:  8](R/W) FIS base address. */
        uint64_t reserved_0_7          : 8;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_7          : 8;
        uint64_t fb                    : 56; /**< [ 63:  8](R/W) FIS base address. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_fb_s cn; */
} bdk_satax_uahc_p0_fb_t;

static inline uint64_t BDK_SATAX_UAHC_P0_FB(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_FB(unsigned long a)
{
    if (a<=15)
        return 0x810000000108ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_FB", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_FB(a) bdk_satax_uahc_p0_fb_t
#define bustype_BDK_SATAX_UAHC_P0_FB(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UAHC_P0_FB(a) "SATAX_UAHC_P0_FB"
#define busnum_BDK_SATAX_UAHC_P0_FB(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_FB(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_ghc
 *
 * SATA AHCI Global HBA Control Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_ghc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ae                    : 1;  /**< [ 31: 31](RO) AHCI enable. */
        uint32_t reserved_2_30         : 29;
        uint32_t ie                    : 1;  /**< [  1:  1](R/W) Interrupt enable. */
        uint32_t hr                    : 1;  /**< [  0:  0](R/W1/H) HBA reset. Writing a 1 resets the UAHC. Hardware clears this bit once reset is complete. */
#else /* Word 0 - Little Endian */
        uint32_t hr                    : 1;  /**< [  0:  0](R/W1/H) HBA reset. Writing a 1 resets the UAHC. Hardware clears this bit once reset is complete. */
        uint32_t ie                    : 1;  /**< [  1:  1](R/W) Interrupt enable. */
        uint32_t reserved_2_30         : 29;
        uint32_t ae                    : 1;  /**< [ 31: 31](RO) AHCI enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_ghc_s cn; */
} bdk_satax_uahc_gbl_ghc_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GHC(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GHC(unsigned long a)
{
    if (a<=15)
        return 0x810000000004ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_GHC", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_GHC(a) bdk_satax_uahc_gbl_ghc_t
#define bustype_BDK_SATAX_UAHC_GBL_GHC(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_GHC(a) "SATAX_UAHC_GBL_GHC"
#define busnum_BDK_SATAX_UAHC_GBL_GHC(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_GHC(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_msix_vec#_ctl
 *
 * SATA MSI-X Vector Table Control and Data Registers
 * This register is the MSI-X vector table, indexed by the SATA_INT_VEC_E enumeration. Changed in
 * pass 2
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_msix_vecx_ctl_s
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
    /* struct bdk_satax_msix_vecx_ctl_s cn; */
} bdk_satax_msix_vecx_ctl_t;

static inline uint64_t BDK_SATAX_MSIX_VECX_CTL(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_VECX_CTL(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=15) && (b<=3)))
        return 0x810000200008ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=15) && (b<=4)))
        return 0x810000200008ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=15) && (b<=3)))
        return 0x810000200008ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("SATAX_MSIX_VECX_CTL", 2, a, b, 0, 0);
}

#define typedef_BDK_SATAX_MSIX_VECX_CTL(a,b) bdk_satax_msix_vecx_ctl_t
#define bustype_BDK_SATAX_MSIX_VECX_CTL(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_MSIX_VECX_CTL(a,b) "SATAX_MSIX_VECX_CTL"
#define busnum_BDK_SATAX_MSIX_VECX_CTL(a,b) (a)
#define arguments_BDK_SATAX_MSIX_VECX_CTL(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_cap
 *
 * SATA AHCI HBA Capabilities Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_cap_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t s64a                  : 1;  /**< [ 31: 31](RO) Supports 64-bit addressing. */
        uint32_t sncq                  : 1;  /**< [ 30: 30](RO) Supports native command queuing. */
        uint32_t ssntf                 : 1;  /**< [ 29: 29](RO) Supports SNotification register. */
        uint32_t smps                  : 1;  /**< [ 28: 28](R/W) Supports mechanical presence switch. */
        uint32_t sss                   : 1;  /**< [ 27: 27](R/W) Supports staggered spin-up. */
        uint32_t salp                  : 1;  /**< [ 26: 26](RO) Supports agressive link power management. */
        uint32_t sal                   : 1;  /**< [ 25: 25](RO) Supports activity LED. */
        uint32_t sclo                  : 1;  /**< [ 24: 24](RO) Supports command list override. */
        uint32_t iss                   : 4;  /**< [ 23: 20](RO) Interface speed support. */
        uint32_t snzo                  : 1;  /**< [ 19: 19](RO) Supports non-zero DMA offsets. */
        uint32_t sam                   : 1;  /**< [ 18: 18](RO) Supports AHCI mode only. */
        uint32_t spm                   : 1;  /**< [ 17: 17](RO) Supports port multiplier. */
        uint32_t fbss                  : 1;  /**< [ 16: 16](RO) Supports FIS-based switching. */
        uint32_t pmd                   : 1;  /**< [ 15: 15](RO) PIO multiple DRQ block. */
        uint32_t ssc                   : 1;  /**< [ 14: 14](RO) Slumber state capable. */
        uint32_t psc                   : 1;  /**< [ 13: 13](RO) Partial state capable. */
        uint32_t ncs                   : 5;  /**< [ 12:  8](RO) Number of command slots. */
        uint32_t cccs                  : 1;  /**< [  7:  7](RO) Command completion coalescing support. */
        uint32_t ems                   : 1;  /**< [  6:  6](RO) Enclosure management support. */
        uint32_t sxs                   : 1;  /**< [  5:  5](RO) Supports external SATA. */
        uint32_t np                    : 5;  /**< [  4:  0](RO) Number of ports. 0x0 = 1 port. */
#else /* Word 0 - Little Endian */
        uint32_t np                    : 5;  /**< [  4:  0](RO) Number of ports. 0x0 = 1 port. */
        uint32_t sxs                   : 1;  /**< [  5:  5](RO) Supports external SATA. */
        uint32_t ems                   : 1;  /**< [  6:  6](RO) Enclosure management support. */
        uint32_t cccs                  : 1;  /**< [  7:  7](RO) Command completion coalescing support. */
        uint32_t ncs                   : 5;  /**< [ 12:  8](RO) Number of command slots. */
        uint32_t psc                   : 1;  /**< [ 13: 13](RO) Partial state capable. */
        uint32_t ssc                   : 1;  /**< [ 14: 14](RO) Slumber state capable. */
        uint32_t pmd                   : 1;  /**< [ 15: 15](RO) PIO multiple DRQ block. */
        uint32_t fbss                  : 1;  /**< [ 16: 16](RO) Supports FIS-based switching. */
        uint32_t spm                   : 1;  /**< [ 17: 17](RO) Supports port multiplier. */
        uint32_t sam                   : 1;  /**< [ 18: 18](RO) Supports AHCI mode only. */
        uint32_t snzo                  : 1;  /**< [ 19: 19](RO) Supports non-zero DMA offsets. */
        uint32_t iss                   : 4;  /**< [ 23: 20](RO) Interface speed support. */
        uint32_t sclo                  : 1;  /**< [ 24: 24](RO) Supports command list override. */
        uint32_t sal                   : 1;  /**< [ 25: 25](RO) Supports activity LED. */
        uint32_t salp                  : 1;  /**< [ 26: 26](RO) Supports agressive link power management. */
        uint32_t sss                   : 1;  /**< [ 27: 27](R/W) Supports staggered spin-up. */
        uint32_t smps                  : 1;  /**< [ 28: 28](R/W) Supports mechanical presence switch. */
        uint32_t ssntf                 : 1;  /**< [ 29: 29](RO) Supports SNotification register. */
        uint32_t sncq                  : 1;  /**< [ 30: 30](RO) Supports native command queuing. */
        uint32_t s64a                  : 1;  /**< [ 31: 31](RO) Supports 64-bit addressing. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_cap_s cn; */
} bdk_satax_uahc_gbl_cap_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CAP(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CAP(unsigned long a)
{
    if (a<=15)
        return 0x810000000000ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_CAP", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_CAP(a) bdk_satax_uahc_gbl_cap_t
#define bustype_BDK_SATAX_UAHC_GBL_CAP(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_CAP(a) "SATAX_UAHC_GBL_CAP"
#define busnum_BDK_SATAX_UAHC_GBL_CAP(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_CAP(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_fbs
 *
 * SATA UAHC FIS-Based Switching Control Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_fbs_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_20_31        : 12;
        uint32_t dwe                   : 4;  /**< [ 19: 16](RO) Device with error. */
        uint32_t ado                   : 4;  /**< [ 15: 12](RO) Active device optimization. */
        uint32_t dev                   : 4;  /**< [ 11:  8](R/W) Device to issue. */
        uint32_t reserved_3_7          : 5;
        uint32_t sde                   : 1;  /**< [  2:  2](RO) Single device error. */
        uint32_t dec                   : 1;  /**< [  1:  1](R/W1C/H) Device error clear. */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. */
#else /* Word 0 - Little Endian */
        uint32_t en                    : 1;  /**< [  0:  0](R/W) Enable. */
        uint32_t dec                   : 1;  /**< [  1:  1](R/W1C/H) Device error clear. */
        uint32_t sde                   : 1;  /**< [  2:  2](RO) Single device error. */
        uint32_t reserved_3_7          : 5;
        uint32_t dev                   : 4;  /**< [ 11:  8](R/W) Device to issue. */
        uint32_t ado                   : 4;  /**< [ 15: 12](RO) Active device optimization. */
        uint32_t dwe                   : 4;  /**< [ 19: 16](RO) Device with error. */
        uint32_t reserved_20_31        : 12;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_fbs_s cn; */
} bdk_satax_uahc_p0_fbs_t;

static inline uint64_t BDK_SATAX_UAHC_P0_FBS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_FBS(unsigned long a)
{
    if (a<=15)
        return 0x810000000140ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_FBS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_FBS(a) bdk_satax_uahc_p0_fbs_t
#define bustype_BDK_SATAX_UAHC_P0_FBS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_FBS(a) "SATAX_UAHC_P0_FBS"
#define busnum_BDK_SATAX_UAHC_P0_FBS(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_FBS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_idr
 *
 * SATA UAHC ID Register
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_idr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t id                    : 32; /**< [ 31:  0](RO) Core ID. */
#else /* Word 0 - Little Endian */
        uint32_t id                    : 32; /**< [ 31:  0](RO) Core ID. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_idr_s cn; */
} bdk_satax_uahc_gbl_idr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_IDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_IDR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000fcll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_IDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_IDR(a) bdk_satax_uahc_gbl_idr_t
#define bustype_BDK_SATAX_UAHC_GBL_IDR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_IDR(a) "SATAX_UAHC_GBL_IDR"
#define busnum_BDK_SATAX_UAHC_GBL_IDR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_IDR(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_uctl_intstat
 *
 * SATA UCTL Interrupt Status Register
 * Summary of different bits of interrupts.
 *
 * Accessible always.
 *
 * Reset NCB reset.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_uctl_intstat_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_14_63        : 50;
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1C/H) Detected double-bit error on the UAHC Rx FIFO. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1C/H) Detected single-bit error on the UAHC Rx FIFO. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1C/H) Detected double-bit error on the UAHC Tx FIFO. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Detected single-bit error on the UAHC Tx FIFO. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1C/H) Detected double-bit error on the UAHC FBS memory. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1C/H) Detected single-bit error on the UAHC FBS memory. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Received DMA read response error from NCBO. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Received DMA write response error from NCBO. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1C/H) Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1C/H) Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1C/H) Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1C/H) Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1C/H) Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1C/H) Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
#else /* Word 0 - Little Endian */
        uint64_t xs_ncb_oob            : 1;  /**< [  0:  0](R/W1C/H) Detected out-of-bound register access to UAHC over NCB. The UAHC defines 1MB of register
                                                                 space, starting at offset 0x0. Any accesses outside of this register space cause this bit
                                                                 to be set to 1. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XS_NCB_OOB_*]. */
        uint64_t xm_bad_dma            : 1;  /**< [  1:  1](R/W1C/H) Detected bad DMA access from UAHC to NCB. The error information is logged in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_*]. Received a DMA request from UAHC that violates
                                                                 the assumptions made by the AXI-to-NCB shim. Such scenarios include: illegal length/size
                                                                 combinations and address out-of-bounds.

                                                                 For more information on exact failures, see description in
                                                                 SATA()_UCTL_SHIM_CFG[XM_BAD_DMA_TYPE].

                                                                 The hardware does not translate the request correctly and results may violate NCB
                                                                 protocols. */
        uint64_t xm_w_sbe              : 1;  /**< [  2:  2](R/W1C/H) Detected single-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_w_dbe              : 1;  /**< [  3:  3](R/W1C/H) Detected double-bit error on the UCTL AxiMaster write-data FIFO. */
        uint64_t xm_r_sbe              : 1;  /**< [  4:  4](R/W1C/H) Detected single-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t xm_r_dbe              : 1;  /**< [  5:  5](R/W1C/H) Detected double-bit error on the UCTL AxiMaster read-data FIFO. */
        uint64_t dma_wr_err            : 1;  /**< [  6:  6](R/W1C/H) Received DMA write response error from NCBO. */
        uint64_t dma_rd_err            : 1;  /**< [  7:  7](R/W1C/H) Received DMA read response error from NCBO. */
        uint64_t uahc_fb_sbe           : 1;  /**< [  8:  8](R/W1C/H) Detected single-bit error on the UAHC FBS memory. */
        uint64_t uahc_fb_dbe           : 1;  /**< [  9:  9](R/W1C/H) Detected double-bit error on the UAHC FBS memory. */
        uint64_t uahc_tx_sbe           : 1;  /**< [ 10: 10](R/W1C/H) Detected single-bit error on the UAHC Tx FIFO. */
        uint64_t uahc_tx_dbe           : 1;  /**< [ 11: 11](R/W1C/H) Detected double-bit error on the UAHC Tx FIFO. */
        uint64_t uahc_rx_sbe           : 1;  /**< [ 12: 12](R/W1C/H) Detected single-bit error on the UAHC Rx FIFO. */
        uint64_t uahc_rx_dbe           : 1;  /**< [ 13: 13](R/W1C/H) Detected double-bit error on the UAHC Rx FIFO. */
        uint64_t reserved_14_63        : 50;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uctl_intstat_s cn; */
} bdk_satax_uctl_intstat_t;

static inline uint64_t BDK_SATAX_UCTL_INTSTAT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UCTL_INTSTAT(unsigned long a)
{
    if (a<=15)
        return 0x810000100030ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UCTL_INTSTAT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UCTL_INTSTAT(a) bdk_satax_uctl_intstat_t
#define bustype_BDK_SATAX_UCTL_INTSTAT(a) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_UCTL_INTSTAT(a) "SATAX_UCTL_INTSTAT"
#define busnum_BDK_SATAX_UCTL_INTSTAT(a) (a)
#define arguments_BDK_SATAX_UCTL_INTSTAT(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_bistdecr
 *
 * SATA UAHC BIST DWORD Error Count Register
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_bistdecr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t dwerr                 : 32; /**< [ 31:  0](RO) DWORD error count. */
#else /* Word 0 - Little Endian */
        uint32_t dwerr                 : 32; /**< [ 31:  0](RO) DWORD error count. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_bistdecr_s cn; */
} bdk_satax_uahc_gbl_bistdecr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTDECR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTDECR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000b0ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_BISTDECR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_BISTDECR(a) bdk_satax_uahc_gbl_bistdecr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTDECR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_BISTDECR(a) "SATAX_UAHC_GBL_BISTDECR"
#define busnum_BDK_SATAX_UAHC_GBL_BISTDECR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_BISTDECR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_tfd
 *
 * SATA UAHC Task File Data Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_tfd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t tferr                 : 8;  /**< [ 15:  8](RO) Copy of task-file error register. */
        uint32_t sts                   : 8;  /**< [  7:  0](RO/H) Copy of task-file status register. */
#else /* Word 0 - Little Endian */
        uint32_t sts                   : 8;  /**< [  7:  0](RO/H) Copy of task-file status register. */
        uint32_t tferr                 : 8;  /**< [ 15:  8](RO) Copy of task-file error register. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_tfd_s cn; */
} bdk_satax_uahc_p0_tfd_t;

static inline uint64_t BDK_SATAX_UAHC_P0_TFD(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_TFD(unsigned long a)
{
    if (a<=15)
        return 0x810000000120ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_TFD", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_TFD(a) bdk_satax_uahc_p0_tfd_t
#define bustype_BDK_SATAX_UAHC_P0_TFD(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_TFD(a) "SATAX_UAHC_P0_TFD"
#define busnum_BDK_SATAX_UAHC_P0_TFD(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_TFD(a) (a),-1,-1,-1

/**
 * Register (NCB) sata#_msix_vec#_addr
 *
 * SATA MSI-X Vector Table Address Registers
 * This register is the MSI-X vector table, indexed by the SATA_INT_VEC_E enumeration. Changed in
 * pass 2
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SATA()_MSIX_VEC()_ADDR, SATA()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of SATA()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SATA(0..15)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's SATA()_MSIX_VEC()_ADDR, SATA()_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of SATA()_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_SATA(0..15)_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_msix_vecx_addr_s cn; */
} bdk_satax_msix_vecx_addr_t;

static inline uint64_t BDK_SATAX_MSIX_VECX_ADDR(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_VECX_ADDR(unsigned long a, unsigned long b)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && ((a<=15) && (b<=3)))
        return 0x810000200000ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x3);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((a<=15) && (b<=4)))
        return 0x810000200000ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((a<=15) && (b<=3)))
        return 0x810000200000ll + 0x1000000000ll * ((a) & 0xf) + 0x10ll * ((b) & 0x3);
    __bdk_csr_fatal("SATAX_MSIX_VECX_ADDR", 2, a, b, 0, 0);
}

#define typedef_BDK_SATAX_MSIX_VECX_ADDR(a,b) bdk_satax_msix_vecx_addr_t
#define bustype_BDK_SATAX_MSIX_VECX_ADDR(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_MSIX_VECX_ADDR(a,b) "SATAX_MSIX_VECX_ADDR"
#define busnum_BDK_SATAX_MSIX_VECX_ADDR(a,b) (a)
#define arguments_BDK_SATAX_MSIX_VECX_ADDR(a,b) (a),(b),-1,-1

/**
 * Register (NCB) sata#_msix_pba#
 *
 * SATA MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table, the bit number is indexed by the SATA_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_satax_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SATA_MSIX_VEC()_CTL, enumerated by SATA_INT_VEC_E.
                                                                 Bits that have no associated SATA_INT_VEC_E are zero. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated SATA_MSIX_VEC()_CTL, enumerated by SATA_INT_VEC_E.
                                                                 Bits that have no associated SATA_INT_VEC_E are zero. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_msix_pbax_s cn; */
} bdk_satax_msix_pbax_t;

static inline uint64_t BDK_SATAX_MSIX_PBAX(unsigned long a, unsigned long b) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_MSIX_PBAX(unsigned long a, unsigned long b)
{
    if ((a<=15) && (b==0))
        return 0x8100002f0000ll + 0x1000000000ll * ((a) & 0xf) + 8ll * ((b) & 0x0);
    __bdk_csr_fatal("SATAX_MSIX_PBAX", 2, a, b, 0, 0);
}

#define typedef_BDK_SATAX_MSIX_PBAX(a,b) bdk_satax_msix_pbax_t
#define bustype_BDK_SATAX_MSIX_PBAX(a,b) BDK_CSR_TYPE_NCB
#define basename_BDK_SATAX_MSIX_PBAX(a,b) "SATAX_MSIX_PBAX"
#define busnum_BDK_SATAX_MSIX_PBAX(a,b) (a)
#define arguments_BDK_SATAX_MSIX_PBAX(a,b) (a),(b),-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_ccc_ports
 *
 * SATA AHCI CCC Ports Register
 * See AHCI specification v1.3 section 3.1.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_ccc_ports_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_1_31         : 31;
        uint32_t prt                   : 1;  /**< [  0:  0](R/W) Per port CCC enable. */
#else /* Word 0 - Little Endian */
        uint32_t prt                   : 1;  /**< [  0:  0](R/W) Per port CCC enable. */
        uint32_t reserved_1_31         : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_ccc_ports_s cn; */
} bdk_satax_uahc_gbl_ccc_ports_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_PORTS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_CCC_PORTS(unsigned long a)
{
    if (a<=15)
        return 0x810000000018ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_CCC_PORTS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_CCC_PORTS(a) bdk_satax_uahc_gbl_ccc_ports_t
#define bustype_BDK_SATAX_UAHC_GBL_CCC_PORTS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_CCC_PORTS(a) "SATAX_UAHC_GBL_CCC_PORTS"
#define busnum_BDK_SATAX_UAHC_GBL_CCC_PORTS(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_CCC_PORTS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_is
 *
 * SATA UAHC Interrupt Status Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_is_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cpds                  : 1;  /**< [ 31: 31](R/W1C/H) Cold-port detect status. */
        uint32_t tfes                  : 1;  /**< [ 30: 30](R/W1C/H) Task-file error status. */
        uint32_t hbfs                  : 1;  /**< [ 29: 29](R/W1C/H) Host-bus fatal-error status. */
        uint32_t hbds                  : 1;  /**< [ 28: 28](R/W1C/H) Host-bus data-error status. */
        uint32_t ifs                   : 1;  /**< [ 27: 27](R/W1C/H) Interface fatal-error status. */
        uint32_t infs                  : 1;  /**< [ 26: 26](R/W1C/H) Interface non-fatal-error status. */
        uint32_t reserved_25           : 1;
        uint32_t ofs                   : 1;  /**< [ 24: 24](R/W1C/H) Overflow status. */
        uint32_t imps                  : 1;  /**< [ 23: 23](R/W1C/H) Incorrect port-multiplier status. */
        uint32_t prcs                  : 1;  /**< [ 22: 22](RO/H) PHY-ready change status. */
        uint32_t reserved_8_21         : 14;
        uint32_t dmps                  : 1;  /**< [  7:  7](R/W1C/H) Device mechanical-presence status. */
        uint32_t pcs                   : 1;  /**< [  6:  6](RO/H) Port-connect-change status. */
        uint32_t dps                   : 1;  /**< [  5:  5](R/W1C/H) Descriptor processed. */
        uint32_t ufs                   : 1;  /**< [  4:  4](RO) Unknown FIS interrupt. */
        uint32_t sdbs                  : 1;  /**< [  3:  3](R/W1C/H) Set device bits interrupt. */
        uint32_t dss                   : 1;  /**< [  2:  2](R/W1C/H) DMA setup FIS interrupt. */
        uint32_t pss                   : 1;  /**< [  1:  1](R/W1C/H) PIO setup FIS interrupt. */
        uint32_t dhrs                  : 1;  /**< [  0:  0](R/W1C/H) Device-to-host register FIS interrupt. */
#else /* Word 0 - Little Endian */
        uint32_t dhrs                  : 1;  /**< [  0:  0](R/W1C/H) Device-to-host register FIS interrupt. */
        uint32_t pss                   : 1;  /**< [  1:  1](R/W1C/H) PIO setup FIS interrupt. */
        uint32_t dss                   : 1;  /**< [  2:  2](R/W1C/H) DMA setup FIS interrupt. */
        uint32_t sdbs                  : 1;  /**< [  3:  3](R/W1C/H) Set device bits interrupt. */
        uint32_t ufs                   : 1;  /**< [  4:  4](RO) Unknown FIS interrupt. */
        uint32_t dps                   : 1;  /**< [  5:  5](R/W1C/H) Descriptor processed. */
        uint32_t pcs                   : 1;  /**< [  6:  6](RO/H) Port-connect-change status. */
        uint32_t dmps                  : 1;  /**< [  7:  7](R/W1C/H) Device mechanical-presence status. */
        uint32_t reserved_8_21         : 14;
        uint32_t prcs                  : 1;  /**< [ 22: 22](RO/H) PHY-ready change status. */
        uint32_t imps                  : 1;  /**< [ 23: 23](R/W1C/H) Incorrect port-multiplier status. */
        uint32_t ofs                   : 1;  /**< [ 24: 24](R/W1C/H) Overflow status. */
        uint32_t reserved_25           : 1;
        uint32_t infs                  : 1;  /**< [ 26: 26](R/W1C/H) Interface non-fatal-error status. */
        uint32_t ifs                   : 1;  /**< [ 27: 27](R/W1C/H) Interface fatal-error status. */
        uint32_t hbds                  : 1;  /**< [ 28: 28](R/W1C/H) Host-bus data-error status. */
        uint32_t hbfs                  : 1;  /**< [ 29: 29](R/W1C/H) Host-bus fatal-error status. */
        uint32_t tfes                  : 1;  /**< [ 30: 30](R/W1C/H) Task-file error status. */
        uint32_t cpds                  : 1;  /**< [ 31: 31](R/W1C/H) Cold-port detect status. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_is_s cn; */
} bdk_satax_uahc_p0_is_t;

static inline uint64_t BDK_SATAX_UAHC_P0_IS(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_IS(unsigned long a)
{
    if (a<=15)
        return 0x810000000110ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_IS", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_IS(a) bdk_satax_uahc_p0_is_t
#define bustype_BDK_SATAX_UAHC_P0_IS(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_IS(a) "SATAX_UAHC_P0_IS"
#define busnum_BDK_SATAX_UAHC_P0_IS(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_IS(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_ie
 *
 * SATA UAHC Interrupt Enable Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_ie_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t cpde                  : 1;  /**< [ 31: 31](R/W) Cold-port-detect enable. */
        uint32_t tfee                  : 1;  /**< [ 30: 30](R/W) Task-file-error enable. */
        uint32_t hbfe                  : 1;  /**< [ 29: 29](R/W) Host-bus fatal-error enable. */
        uint32_t hbde                  : 1;  /**< [ 28: 28](R/W) Host-bus data-error enable. */
        uint32_t ife                   : 1;  /**< [ 27: 27](R/W) Interface fatal-error enable. */
        uint32_t infe                  : 1;  /**< [ 26: 26](R/W) Interface non-fatal-error enable. */
        uint32_t reserved_25           : 1;
        uint32_t ofe                   : 1;  /**< [ 24: 24](R/W) Overflow enable. */
        uint32_t impe                  : 1;  /**< [ 23: 23](R/W) Incorrect port-multiplier enable. */
        uint32_t prce                  : 1;  /**< [ 22: 22](R/W) PHY-ready-change enable. */
        uint32_t reserved_8_21         : 14;
        uint32_t dmpe                  : 1;  /**< [  7:  7](R/W) Device mechanical-presence enable. */
        uint32_t pce                   : 1;  /**< [  6:  6](R/W) Port-connect-change enable. */
        uint32_t dpe                   : 1;  /**< [  5:  5](R/W) Descriptor-processed enable. */
        uint32_t ufe                   : 1;  /**< [  4:  4](R/W) Unknown-FIS-interrupt enable. */
        uint32_t sdbe                  : 1;  /**< [  3:  3](R/W) Set device-bits-interrupt enable. */
        uint32_t dse                   : 1;  /**< [  2:  2](R/W) DMA-setup FIS interrupt enable. */
        uint32_t pse                   : 1;  /**< [  1:  1](R/W) PIO-setup FIS interrupt enable. */
        uint32_t dhre                  : 1;  /**< [  0:  0](R/W) Device-to-host register FIS interrupt enable. */
#else /* Word 0 - Little Endian */
        uint32_t dhre                  : 1;  /**< [  0:  0](R/W) Device-to-host register FIS interrupt enable. */
        uint32_t pse                   : 1;  /**< [  1:  1](R/W) PIO-setup FIS interrupt enable. */
        uint32_t dse                   : 1;  /**< [  2:  2](R/W) DMA-setup FIS interrupt enable. */
        uint32_t sdbe                  : 1;  /**< [  3:  3](R/W) Set device-bits-interrupt enable. */
        uint32_t ufe                   : 1;  /**< [  4:  4](R/W) Unknown-FIS-interrupt enable. */
        uint32_t dpe                   : 1;  /**< [  5:  5](R/W) Descriptor-processed enable. */
        uint32_t pce                   : 1;  /**< [  6:  6](R/W) Port-connect-change enable. */
        uint32_t dmpe                  : 1;  /**< [  7:  7](R/W) Device mechanical-presence enable. */
        uint32_t reserved_8_21         : 14;
        uint32_t prce                  : 1;  /**< [ 22: 22](R/W) PHY-ready-change enable. */
        uint32_t impe                  : 1;  /**< [ 23: 23](R/W) Incorrect port-multiplier enable. */
        uint32_t ofe                   : 1;  /**< [ 24: 24](R/W) Overflow enable. */
        uint32_t reserved_25           : 1;
        uint32_t infe                  : 1;  /**< [ 26: 26](R/W) Interface non-fatal-error enable. */
        uint32_t ife                   : 1;  /**< [ 27: 27](R/W) Interface fatal-error enable. */
        uint32_t hbde                  : 1;  /**< [ 28: 28](R/W) Host-bus data-error enable. */
        uint32_t hbfe                  : 1;  /**< [ 29: 29](R/W) Host-bus fatal-error enable. */
        uint32_t tfee                  : 1;  /**< [ 30: 30](R/W) Task-file-error enable. */
        uint32_t cpde                  : 1;  /**< [ 31: 31](R/W) Cold-port-detect enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_ie_s cn; */
} bdk_satax_uahc_p0_ie_t;

static inline uint64_t BDK_SATAX_UAHC_P0_IE(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_IE(unsigned long a)
{
    if (a<=15)
        return 0x810000000114ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_IE", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_IE(a) bdk_satax_uahc_p0_ie_t
#define bustype_BDK_SATAX_UAHC_P0_IE(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_IE(a) "SATAX_UAHC_P0_IE"
#define busnum_BDK_SATAX_UAHC_P0_IE(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_IE(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_phycr
 *
 * SATA UAHC PHY Control Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_phycr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ctrl                  : 32; /**< [ 31:  0](R/W) Port PHY control. */
#else /* Word 0 - Little Endian */
        uint32_t ctrl                  : 32; /**< [ 31:  0](R/W) Port PHY control. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_phycr_s cn; */
} bdk_satax_uahc_p0_phycr_t;

static inline uint64_t BDK_SATAX_UAHC_P0_PHYCR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_PHYCR(unsigned long a)
{
    if (a<=15)
        return 0x810000000178ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_PHYCR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_PHYCR(a) bdk_satax_uahc_p0_phycr_t
#define bustype_BDK_SATAX_UAHC_P0_PHYCR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_PHYCR(a) "SATAX_UAHC_P0_PHYCR"
#define busnum_BDK_SATAX_UAHC_P0_PHYCR(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_PHYCR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_sntf
 *
 * SATA UAHC SATA Notification Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_sntf_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_16_31        : 16;
        uint32_t pmn                   : 16; /**< [ 15:  0](R/W1C/H) PM notify. */
#else /* Word 0 - Little Endian */
        uint32_t pmn                   : 16; /**< [ 15:  0](R/W1C/H) PM notify. */
        uint32_t reserved_16_31        : 16;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_sntf_s cn; */
} bdk_satax_uahc_p0_sntf_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SNTF(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SNTF(unsigned long a)
{
    if (a<=15)
        return 0x81000000013cll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SNTF", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SNTF(a) bdk_satax_uahc_p0_sntf_t
#define bustype_BDK_SATAX_UAHC_P0_SNTF(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SNTF(a) "SATAX_UAHC_P0_SNTF"
#define busnum_BDK_SATAX_UAHC_P0_SNTF(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SNTF(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_bistfctr
 *
 * SATA UAHC BIST FIS Count Register
 * This register is shared between SATA ports. Before accessing this
 * register, first select the required port by writing the port number
 * to the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_bistfctr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t count                 : 32; /**< [ 31:  0](RO) Received BIST FIS count. */
#else /* Word 0 - Little Endian */
        uint32_t count                 : 32; /**< [ 31:  0](RO) Received BIST FIS count. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_bistfctr_s cn; */
} bdk_satax_uahc_gbl_bistfctr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_BISTFCTR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_BISTFCTR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000a8ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_BISTFCTR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_BISTFCTR(a) bdk_satax_uahc_gbl_bistfctr_t
#define bustype_BDK_SATAX_UAHC_GBL_BISTFCTR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_BISTFCTR(a) "SATAX_UAHC_GBL_BISTFCTR"
#define busnum_BDK_SATAX_UAHC_GBL_BISTFCTR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_BISTFCTR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_pparamr
 *
 * SATA UAHC Port Parameter Register
 * Port is selected by the SATA()_UAHC_GBL_TESTR[PSEL] field.
 *
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_pparamr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t reserved_12_31        : 20;
        uint32_t tx_mem_m              : 1;  /**< [ 11: 11](RO) TX FIFO memory read port type (Pn_TX_MEM_MODE). */
        uint32_t tx_mem_s              : 1;  /**< [ 10: 10](RO) TX FIFO memory type (Pn_TX_MEM_SELECT). */
        uint32_t rx_mem_m              : 1;  /**< [  9:  9](RO) RX FIFO memory read port type (Pn_RX_MEM_MODE). */
        uint32_t rx_mem_s              : 1;  /**< [  8:  8](RO) RX FIFO memory type (Pn_RX_MEM_SELECT). */
        uint32_t txfifo_depth          : 4;  /**< [  7:  4](RO) TX FIFO depth in FIFO words. */
        uint32_t rxfifo_depth          : 4;  /**< [  3:  0](RO) RX FIFO depth in FIFO words. */
#else /* Word 0 - Little Endian */
        uint32_t rxfifo_depth          : 4;  /**< [  3:  0](RO) RX FIFO depth in FIFO words. */
        uint32_t txfifo_depth          : 4;  /**< [  7:  4](RO) TX FIFO depth in FIFO words. */
        uint32_t rx_mem_s              : 1;  /**< [  8:  8](RO) RX FIFO memory type (Pn_RX_MEM_SELECT). */
        uint32_t rx_mem_m              : 1;  /**< [  9:  9](RO) RX FIFO memory read port type (Pn_RX_MEM_MODE). */
        uint32_t tx_mem_s              : 1;  /**< [ 10: 10](RO) TX FIFO memory type (Pn_TX_MEM_SELECT). */
        uint32_t tx_mem_m              : 1;  /**< [ 11: 11](RO) TX FIFO memory read port type (Pn_TX_MEM_MODE). */
        uint32_t reserved_12_31        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_pparamr_s cn; */
} bdk_satax_uahc_gbl_pparamr_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_PPARAMR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_PPARAMR(unsigned long a)
{
    if (a<=15)
        return 0x8100000000f0ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_PPARAMR", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_PPARAMR(a) bdk_satax_uahc_gbl_pparamr_t
#define bustype_BDK_SATAX_UAHC_GBL_PPARAMR(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_PPARAMR(a) "SATAX_UAHC_GBL_PPARAMR"
#define busnum_BDK_SATAX_UAHC_GBL_PPARAMR(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_PPARAMR(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_sact
 *
 * SATA UAHC SATA Active Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_sact_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t ds                    : 32; /**< [ 31:  0](R/W1S/H) Device status. */
#else /* Word 0 - Little Endian */
        uint32_t ds                    : 32; /**< [ 31:  0](R/W1S/H) Device status. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_sact_s cn; */
} bdk_satax_uahc_p0_sact_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SACT(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SACT(unsigned long a)
{
    if (a<=15)
        return 0x810000000134ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SACT", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SACT(a) bdk_satax_uahc_p0_sact_t
#define bustype_BDK_SATAX_UAHC_P0_SACT(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SACT(a) "SATAX_UAHC_P0_SACT"
#define busnum_BDK_SATAX_UAHC_P0_SACT(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SACT(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_p0_sig
 *
 * SATA UAHC Signature Registers
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_p0_sig_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t sig                   : 32; /**< [ 31:  0](RO/H) Signature. */
#else /* Word 0 - Little Endian */
        uint32_t sig                   : 32; /**< [ 31:  0](RO/H) Signature. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_p0_sig_s cn; */
} bdk_satax_uahc_p0_sig_t;

static inline uint64_t BDK_SATAX_UAHC_P0_SIG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_P0_SIG(unsigned long a)
{
    if (a<=15)
        return 0x810000000124ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_P0_SIG", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_P0_SIG(a) bdk_satax_uahc_p0_sig_t
#define bustype_BDK_SATAX_UAHC_P0_SIG(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_P0_SIG(a) "SATAX_UAHC_P0_SIG"
#define busnum_BDK_SATAX_UAHC_P0_SIG(a) (a)
#define arguments_BDK_SATAX_UAHC_P0_SIG(a) (a),-1,-1,-1

/**
 * Register (NCB32b) sata#_uahc_gbl_gparam1r
 *
 * SATA UAHC Global Parameter Register 1
 * INTERNAL: See DWC_ahsata databook v4.20a.
 */
typedef union
{
    uint32_t u;
    struct bdk_satax_uahc_gbl_gparam1r_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint32_t align_m               : 1;  /**< [ 31: 31](RO) RX data alignment mode (ALIGN_MODE). */
        uint32_t rx_buffer             : 1;  /**< [ 30: 30](RO) RX data buffer mode (RX_BUFFER_MODE). */
        uint32_t phy_data              : 2;  /**< [ 29: 28](RO) PHY data width (PHY_DATA_WIDTH). */
        uint32_t phy_rst               : 1;  /**< [ 27: 27](RO) PHY reset mode (PHY_RST_MODE). */
        uint32_t phy_ctrl              : 6;  /**< [ 26: 21](RO) PHY control width (PHY_CTRL_W). */
        uint32_t phy_stat              : 6;  /**< [ 20: 15](RO) PHY status width (PHY_STAT_W). */
        uint32_t latch_m               : 1;  /**< [ 14: 14](RO) Latch mode (LATCH_MODE). */
        uint32_t phy_type              : 3;  /**< [ 13: 11](RO) PHY interface type (PHY_INTERFACE_TYPE). */
        uint32_t return_err            : 1;  /**< [ 10: 10](RO) AMBA error response (RETURN_ERR_RESP). */
        uint32_t ahb_endian            : 2;  /**< [  9:  8](RO) AHB bus endianness (AHB_ENDIANNESS). */
        uint32_t s_haddr               : 1;  /**< [  7:  7](RO) AMBA slave address bus width (S_HADDR_WIDTH). */
        uint32_t m_haddr               : 1;  /**< [  6:  6](RO) AMBA master address bus width (M_HADDR_WIDTH). */
        uint32_t s_hdata               : 3;  /**< [  5:  3](RO) AMBA slave data width (S_HDATA_WIDTH). */
        uint32_t m_hdata               : 3;  /**< [  2:  0](RO) AMBA master data width (M_HDATA_WIDTH). */
#else /* Word 0 - Little Endian */
        uint32_t m_hdata               : 3;  /**< [  2:  0](RO) AMBA master data width (M_HDATA_WIDTH). */
        uint32_t s_hdata               : 3;  /**< [  5:  3](RO) AMBA slave data width (S_HDATA_WIDTH). */
        uint32_t m_haddr               : 1;  /**< [  6:  6](RO) AMBA master address bus width (M_HADDR_WIDTH). */
        uint32_t s_haddr               : 1;  /**< [  7:  7](RO) AMBA slave address bus width (S_HADDR_WIDTH). */
        uint32_t ahb_endian            : 2;  /**< [  9:  8](RO) AHB bus endianness (AHB_ENDIANNESS). */
        uint32_t return_err            : 1;  /**< [ 10: 10](RO) AMBA error response (RETURN_ERR_RESP). */
        uint32_t phy_type              : 3;  /**< [ 13: 11](RO) PHY interface type (PHY_INTERFACE_TYPE). */
        uint32_t latch_m               : 1;  /**< [ 14: 14](RO) Latch mode (LATCH_MODE). */
        uint32_t phy_stat              : 6;  /**< [ 20: 15](RO) PHY status width (PHY_STAT_W). */
        uint32_t phy_ctrl              : 6;  /**< [ 26: 21](RO) PHY control width (PHY_CTRL_W). */
        uint32_t phy_rst               : 1;  /**< [ 27: 27](RO) PHY reset mode (PHY_RST_MODE). */
        uint32_t phy_data              : 2;  /**< [ 29: 28](RO) PHY data width (PHY_DATA_WIDTH). */
        uint32_t rx_buffer             : 1;  /**< [ 30: 30](RO) RX data buffer mode (RX_BUFFER_MODE). */
        uint32_t align_m               : 1;  /**< [ 31: 31](RO) RX data alignment mode (ALIGN_MODE). */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_satax_uahc_gbl_gparam1r_s cn; */
} bdk_satax_uahc_gbl_gparam1r_t;

static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM1R(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_SATAX_UAHC_GBL_GPARAM1R(unsigned long a)
{
    if (a<=15)
        return 0x8100000000e8ll + 0x1000000000ll * ((a) & 0xf);
    __bdk_csr_fatal("SATAX_UAHC_GBL_GPARAM1R", 1, a, 0, 0, 0);
}

#define typedef_BDK_SATAX_UAHC_GBL_GPARAM1R(a) bdk_satax_uahc_gbl_gparam1r_t
#define bustype_BDK_SATAX_UAHC_GBL_GPARAM1R(a) BDK_CSR_TYPE_NCB32b
#define basename_BDK_SATAX_UAHC_GBL_GPARAM1R(a) "SATAX_UAHC_GBL_GPARAM1R"
#define busnum_BDK_SATAX_UAHC_GBL_GPARAM1R(a) (a)
#define arguments_BDK_SATAX_UAHC_GBL_GPARAM1R(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_SATA_H__ */

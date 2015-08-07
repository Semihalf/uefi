#ifndef __BDK_CSRS_NDF_H__
#define __BDK_CSRS_NDF_H__
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
 * Cavium NDF.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration ndf_bar_e
 *
 * NAND Flash Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_NDF_BAR_E_NDF_PF_BAR0 (0x808000000000ll) /**< Base address for standard registers. */
#define BDK_NDF_BAR_E_NDF_PF_BAR4 (0x808000f00000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration ndf_int_vec_e
 *
 * NAND Flash MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_NDF_INT_VEC_E_INTR (0) /**< See interrupt clears NDF_INT, interrupt sets NDF_INT_W1S, enable clears
                                       NDF_INT_ENA_W1C, and enable sets NDF_INT_ENA_W1S. */

/**
 * Register (NCB) ndf_bt_pg_info
 *
 * NAND Flash Page Information Register
 * This register provides the page size and the number of column-plus-row address-cycle
 * information. Software writes to this register during a boot operation from a NAND flash
 * device.
 *
 * Additionally, software also writes the multiplier value for timing parameters that is used
 * during the boot process, in the SET_TM_PARAM command. The multiplier value is used only by the
 * boot-load state machine during boot operations. Boot DMA operations do not use this value.
 *
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_bt_pg_info_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t t_mult                : 4;  /**< [ 10:  7](R/W) The boot-time TIM_MULT field of the SET_TM_PAR command. */
        uint64_t adr_cyc               : 4;  /**< [  6:  3](R/W) Number of column-address cycles. Legal values are 0x3 - 0x8. Values written to this field
                                                                 smaller than 0x3 are converted to 0x3; values larger than 0x8 are converted to 0x8. */
        uint64_t size                  : 3;  /**< [  2:  0](R/W) Number of bytes per page in the NAND flash device = 2^SIZE+1 * 256.
                                                                 0x0 = 512 bytes/page.
                                                                 0x1 = 1 KB/page.
                                                                 0x2 = 2 KB/page.
                                                                 0x3 = 4 KB/page.
                                                                 0x4 = 8 KB/page.
                                                                 0x5 = 16 KB/page.
                                                                 0x6 = 32 KB/page.
                                                                 0x7 = 64 KB/page. */
#else /* Word 0 - Little Endian */
        uint64_t size                  : 3;  /**< [  2:  0](R/W) Number of bytes per page in the NAND flash device = 2^SIZE+1 * 256.
                                                                 0x0 = 512 bytes/page.
                                                                 0x1 = 1 KB/page.
                                                                 0x2 = 2 KB/page.
                                                                 0x3 = 4 KB/page.
                                                                 0x4 = 8 KB/page.
                                                                 0x5 = 16 KB/page.
                                                                 0x6 = 32 KB/page.
                                                                 0x7 = 64 KB/page. */
        uint64_t adr_cyc               : 4;  /**< [  6:  3](R/W) Number of column-address cycles. Legal values are 0x3 - 0x8. Values written to this field
                                                                 smaller than 0x3 are converted to 0x3; values larger than 0x8 are converted to 0x8. */
        uint64_t t_mult                : 4;  /**< [ 10:  7](R/W) The boot-time TIM_MULT field of the SET_TM_PAR command. */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_bt_pg_info_s cn; */
} bdk_ndf_bt_pg_info_t;

#define BDK_NDF_BT_PG_INFO BDK_NDF_BT_PG_INFO_FUNC()
static inline uint64_t BDK_NDF_BT_PG_INFO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_BT_PG_INFO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000018ll;
    __bdk_csr_fatal("NDF_BT_PG_INFO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_BT_PG_INFO bdk_ndf_bt_pg_info_t
#define bustype_BDK_NDF_BT_PG_INFO BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_BT_PG_INFO "NDF_BT_PG_INFO"
#define busnum_BDK_NDF_BT_PG_INFO 0
#define arguments_BDK_NDF_BT_PG_INFO -1,-1,-1,-1

/**
 * Register (NCB) ndf_cmd
 *
 * NAND Flash Command Register
 * When software reads this register, NDF_MISC[RD_VAL] is cleared to 0. Software must always
 * write all eight bytes whenever it writes this register. If there are fewer than eight bytes
 * left in the command sequence that software wants the NAND flash controller to execute, it must
 * insert Idle (WAIT) commands to make up eight bytes. Software must also ensure that there is
 * enough space in the NDF_CMD queue to accept these eight bytes by first reading
 * NDF_MISC[FR_BYT].
 *
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_cmd_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t nf_cmd                : 64; /**< [ 63:  0](R/W) Eight NAND flash memory command bytes. */
#else /* Word 0 - Little Endian */
        uint64_t nf_cmd                : 64; /**< [ 63:  0](R/W) Eight NAND flash memory command bytes. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_cmd_s cn; */
} bdk_ndf_cmd_t;

#define BDK_NDF_CMD BDK_NDF_CMD_FUNC()
static inline uint64_t BDK_NDF_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_CMD_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000000ll;
    __bdk_csr_fatal("NDF_CMD", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_CMD bdk_ndf_cmd_t
#define bustype_BDK_NDF_CMD BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_CMD "NDF_CMD"
#define busnum_BDK_NDF_CMD 0
#define arguments_BDK_NDF_CMD -1,-1,-1,-1

/**
 * Register (NCB) ndf_dma_adr
 *
 * NAND Flash DMA Address Register
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_dma_adr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t adr                   : 46; /**< [ 48:  3](R/W/H) DMA engine address. 64-bit aligned. */
        uint64_t reserved_0_2          : 3;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_2          : 3;
        uint64_t adr                   : 46; /**< [ 48:  3](R/W/H) DMA engine address. 64-bit aligned. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_dma_adr_s cn; */
} bdk_ndf_dma_adr_t;

#define BDK_NDF_DMA_ADR BDK_NDF_DMA_ADR_FUNC()
static inline uint64_t BDK_NDF_DMA_ADR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_DMA_ADR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000058ll;
    __bdk_csr_fatal("NDF_DMA_ADR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_DMA_ADR bdk_ndf_dma_adr_t
#define bustype_BDK_NDF_DMA_ADR BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_DMA_ADR "NDF_DMA_ADR"
#define busnum_BDK_NDF_DMA_ADR 0
#define arguments_BDK_NDF_DMA_ADR -1,-1,-1,-1

/**
 * Register (NCB) ndf_dma_cfg
 *
 * NAND Flash DMA Configuration Register
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_dma_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine enable.  This bit is cleared at the termination of the DMA. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W) DMA engine clear EN. When set to 1, DMA is terminated and EN is cleared and the DMA_DONE
                                                                 interrupt
                                                                 occurs when either the SIZE is exhausted (normal termination) or the NDF BUS_REL is
                                                                 issued. */
        uint64_t reserved_60           : 1;
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine enable 16-bit swap. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine enable 8-bit swap. */
        uint64_t cmd_be                : 1;  /**< [ 56: 56](R/W) DMA engine command-queue endian mode: 0 = little-endian, 1 = big-endian. */
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). */
        uint64_t reserved_0_35         : 36;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_35         : 36;
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine size. Specified in the number of 64-bit transfers (encoded in -1 notation). */
        uint64_t cmd_be                : 1;  /**< [ 56: 56](R/W) DMA engine command-queue endian mode: 0 = little-endian, 1 = big-endian. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine enable 8-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine enable 16-bit swap. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 32-bit swap. */
        uint64_t reserved_60           : 1;
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W) DMA engine clear EN. When set to 1, DMA is terminated and EN is cleared and the DMA_DONE
                                                                 interrupt
                                                                 occurs when either the SIZE is exhausted (normal termination) or the NDF BUS_REL is
                                                                 issued. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine R/W bit: 0 = read, 1 = write. */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine enable.  This bit is cleared at the termination of the DMA. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_dma_cfg_s cn; */
} bdk_ndf_dma_cfg_t;

#define BDK_NDF_DMA_CFG BDK_NDF_DMA_CFG_FUNC()
static inline uint64_t BDK_NDF_DMA_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_DMA_CFG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000050ll;
    __bdk_csr_fatal("NDF_DMA_CFG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_DMA_CFG bdk_ndf_dma_cfg_t
#define bustype_BDK_NDF_DMA_CFG BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_DMA_CFG "NDF_DMA_CFG"
#define busnum_BDK_NDF_DMA_CFG 0
#define arguments_BDK_NDF_DMA_CFG -1,-1,-1,-1

/**
 * Register (NCB) ndf_drbell
 *
 * NAND Flash Doorbell Register
 * This register is designed to control the execution of the NAND flash commands. The NDF
 * command-execution unit must arbitrate for the boot bus before it can enable a NAND flash
 * device connected to the CNXXXX, which it then does by asserting the device's chip-enable
 * signal. Therefore software must first load the NDF_CMD queue, with a full sequence of commands
 * to perform a NAND flash device task.
 *
 * This command sequence starts with a BUS_ACQ command, and the last command in the sequence must
 * be a BUS_REL command. The execution unit starts execution of the sequence only if the
 * NDF_DRBELL[CNT] is non-zero when it fetches the BUS_ACQ command.
 *
 * Software can load multiple such sequences, each starting with a CHIP_EN command and ending
 * with a CHIP_DIS command, and then write a data value to this register to increment the CNT
 * field by the number of the command sequences loaded to the NDF_CMD queue.
 *
 * Software register-write operations increment CNT by the signed 8-bit value being written.
 * Software register-read operations return the current CNT value.
 *
 * Hardware can also modifies the value of CNT. Every time hardware executes a BUS_ACQ command to
 * arbitrate and win the boot bus, it decrements CNT by 1. If CNT is already 0 or negative, the
 * hardware command-execution unit stalls when it fetches the new BUS_ACQ command from the
 * NDF_CMD queue. Only when the software writes to this register with a non-zero data value can
 * the execution unit come out of the stalled condition, and resume execution.
 *
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_drbell_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t cnt                   : 8;  /**< [  7:  0](R/W/H) Doorbell count, in 2s-complement format. */
#else /* Word 0 - Little Endian */
        uint64_t cnt                   : 8;  /**< [  7:  0](R/W/H) Doorbell count, in 2s-complement format. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_drbell_s cn; */
} bdk_ndf_drbell_t;

#define BDK_NDF_DRBELL BDK_NDF_DRBELL_FUNC()
static inline uint64_t BDK_NDF_DRBELL_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_DRBELL_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000030ll;
    __bdk_csr_fatal("NDF_DRBELL", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_DRBELL bdk_ndf_drbell_t
#define bustype_BDK_NDF_DRBELL BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_DRBELL "NDF_DRBELL"
#define busnum_BDK_NDF_DRBELL 0
#define arguments_BDK_NDF_DRBELL -1,-1,-1,-1

/**
 * Register (NCB) ndf_ecc_cnt
 *
 * NAND Flash ECC Count Register
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_ecc_cnt_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t xor_ecc               : 24; /**< [ 31:  8](RO/H) Result of XOR operation of ECC read bytes and ECC generated bytes. The value pertains to
                                                                 the last single-bit ECC error.
                                                                 _ XOR_ECC ={ECC_gen_byt258, ECC_gen_byt257, ECC_gen_byt256} ^
                                                                   {ECC_258, ECC_257, ECC_256}

                                                                 ECC_258, ECC_257 and ECC_256 are bytes stored in the NAND flash device and read out during
                                                                 boot.

                                                                 ECC_gen_byt258, ECC_gen_byt257, ECC_gen_byt256 are generated from data read out from the
                                                                 NAND flash device. */
        uint64_t ecc_err               : 8;  /**< [  7:  0](RO/H) ECC error count. The number of single-bit errors fixed during boot. */
#else /* Word 0 - Little Endian */
        uint64_t ecc_err               : 8;  /**< [  7:  0](RO/H) ECC error count. The number of single-bit errors fixed during boot. */
        uint64_t xor_ecc               : 24; /**< [ 31:  8](RO/H) Result of XOR operation of ECC read bytes and ECC generated bytes. The value pertains to
                                                                 the last single-bit ECC error.
                                                                 _ XOR_ECC ={ECC_gen_byt258, ECC_gen_byt257, ECC_gen_byt256} ^
                                                                   {ECC_258, ECC_257, ECC_256}

                                                                 ECC_258, ECC_257 and ECC_256 are bytes stored in the NAND flash device and read out during
                                                                 boot.

                                                                 ECC_gen_byt258, ECC_gen_byt257, ECC_gen_byt256 are generated from data read out from the
                                                                 NAND flash device. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_ecc_cnt_s cn; */
} bdk_ndf_ecc_cnt_t;

#define BDK_NDF_ECC_CNT BDK_NDF_ECC_CNT_FUNC()
static inline uint64_t BDK_NDF_ECC_CNT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_ECC_CNT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000010ll;
    __bdk_csr_fatal("NDF_ECC_CNT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_ECC_CNT bdk_ndf_ecc_cnt_t
#define bustype_BDK_NDF_ECC_CNT BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_ECC_CNT "NDF_ECC_CNT"
#define busnum_BDK_NDF_ECC_CNT 0
#define arguments_BDK_NDF_ECC_CNT -1,-1,-1,-1

/**
 * Register (NCB) ndf_int
 *
 * NAND Flash Interrupt Register
 * This register contains the bits that can trigger an error interrupt. Sixty-four-bit operations
 * must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_int_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1C/H) DMA engine request completion interrupt. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1C/H) NDF_CMD write when FIFO is full. Generally a fatal error. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1C/H) Multibit ECC error detected during boot. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1C/H) Single-bit ECC error detected and fixed during boot. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1C/H) One of the state machines is in a bad state, */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1C/H) Watchdog timer expired during command execution. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1C/H) NDF_CMD queue is full. FULL status is updated when the NDF_CMD queue becomes full as a
                                                                 result of software writing a new command to it. */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1C/H) NDF_CMD queue is empty. EMPTY status is updated when the NDF_CMD queue becomes empty as a
                                                                 result of command execution unit fetching the last instruction out of the NDF_CMD queue. */
#else /* Word 0 - Little Endian */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1C/H) NDF_CMD queue is empty. EMPTY status is updated when the NDF_CMD queue becomes empty as a
                                                                 result of command execution unit fetching the last instruction out of the NDF_CMD queue. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1C/H) NDF_CMD queue is full. FULL status is updated when the NDF_CMD queue becomes full as a
                                                                 result of software writing a new command to it. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1C/H) Watchdog timer expired during command execution. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1C/H) One of the state machines is in a bad state, */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1C/H) Single-bit ECC error detected and fixed during boot. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1C/H) Multibit ECC error detected during boot. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1C/H) NDF_CMD write when FIFO is full. Generally a fatal error. */
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1C/H) DMA engine request completion interrupt. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_int_s cn; */
} bdk_ndf_int_t;

#define BDK_NDF_INT BDK_NDF_INT_FUNC()
static inline uint64_t BDK_NDF_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_INT_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000040ll;
    __bdk_csr_fatal("NDF_INT", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_INT bdk_ndf_int_t
#define bustype_BDK_NDF_INT BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_INT "NDF_INT"
#define busnum_BDK_NDF_INT 0
#define arguments_BDK_NDF_INT -1,-1,-1,-1

/**
 * Register (NCB) ndf_int_ena_w1c
 *
 * NAND Flash Interrupt Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_int_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NDF_INT[DMA_DONE]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NDF_INT[OVRF]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NDF_INT[ECC_MULT]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NDF_INT[ECC_1BIT]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NDF_INT[SM_BAD]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NDF_INT[WDOG]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NDF_INT[FULL]. */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NDF_INT[EMPTY]. */
#else /* Word 0 - Little Endian */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for NDF_INT[EMPTY]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for NDF_INT[FULL]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1C/H) Reads or clears enable for NDF_INT[WDOG]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1C/H) Reads or clears enable for NDF_INT[SM_BAD]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1C/H) Reads or clears enable for NDF_INT[ECC_1BIT]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1C/H) Reads or clears enable for NDF_INT[ECC_MULT]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1C/H) Reads or clears enable for NDF_INT[OVRF]. */
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1C/H) Reads or clears enable for NDF_INT[DMA_DONE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_int_ena_w1c_s cn; */
} bdk_ndf_int_ena_w1c_t;

#define BDK_NDF_INT_ENA_W1C BDK_NDF_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_NDF_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_INT_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8080000000a0ll;
    __bdk_csr_fatal("NDF_INT_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_INT_ENA_W1C bdk_ndf_int_ena_w1c_t
#define bustype_BDK_NDF_INT_ENA_W1C BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_INT_ENA_W1C "NDF_INT_ENA_W1C"
#define busnum_BDK_NDF_INT_ENA_W1C 0
#define arguments_BDK_NDF_INT_ENA_W1C -1,-1,-1,-1

/**
 * Register (NCB) ndf_int_ena_w1s
 *
 * NAND Flash Interrupt Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_int_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NDF_INT[DMA_DONE]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NDF_INT[OVRF]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NDF_INT[ECC_MULT]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NDF_INT[ECC_1BIT]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NDF_INT[SM_BAD]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NDF_INT[WDOG]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NDF_INT[FULL]. */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NDF_INT[EMPTY]. */
#else /* Word 0 - Little Endian */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for NDF_INT[EMPTY]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for NDF_INT[FULL]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets enable for NDF_INT[WDOG]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets enable for NDF_INT[SM_BAD]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets enable for NDF_INT[ECC_1BIT]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets enable for NDF_INT[ECC_MULT]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1S/H) Reads or sets enable for NDF_INT[OVRF]. */
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets enable for NDF_INT[DMA_DONE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_int_ena_w1s_s cn; */
} bdk_ndf_int_ena_w1s_t;

#define BDK_NDF_INT_ENA_W1S BDK_NDF_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_NDF_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_INT_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x8080000000a8ll;
    __bdk_csr_fatal("NDF_INT_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_INT_ENA_W1S bdk_ndf_int_ena_w1s_t
#define bustype_BDK_NDF_INT_ENA_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_INT_ENA_W1S "NDF_INT_ENA_W1S"
#define busnum_BDK_NDF_INT_ENA_W1S 0
#define arguments_BDK_NDF_INT_ENA_W1S -1,-1,-1,-1

/**
 * Register (NCB) ndf_int_w1s
 *
 * NAND Flash Interrupt Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_int_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NDF_INT[DMA_DONE]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NDF_INT[OVRF]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NDF_INT[ECC_MULT]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NDF_INT[ECC_1BIT]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NDF_INT[SM_BAD]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NDF_INT[WDOG]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NDF_INT[FULL]. */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NDF_INT[EMPTY]. */
#else /* Word 0 - Little Endian */
        uint64_t empty                 : 1;  /**< [  0:  0](R/W1S/H) Reads or sets NDF_INT[EMPTY]. */
        uint64_t full                  : 1;  /**< [  1:  1](R/W1S/H) Reads or sets NDF_INT[FULL]. */
        uint64_t wdog                  : 1;  /**< [  2:  2](R/W1S/H) Reads or sets NDF_INT[WDOG]. */
        uint64_t sm_bad                : 1;  /**< [  3:  3](R/W1S/H) Reads or sets NDF_INT[SM_BAD]. */
        uint64_t ecc_1bit              : 1;  /**< [  4:  4](R/W1S/H) Reads or sets NDF_INT[ECC_1BIT]. */
        uint64_t ecc_mult              : 1;  /**< [  5:  5](R/W1S/H) Reads or sets NDF_INT[ECC_MULT]. */
        uint64_t ovrf                  : 1;  /**< [  6:  6](R/W1S/H) Reads or sets NDF_INT[OVRF]. */
        uint64_t dma_done              : 1;  /**< [  7:  7](R/W1S/H) Reads or sets NDF_INT[DMA_DONE]. */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_int_w1s_s cn; */
} bdk_ndf_int_w1s_t;

#define BDK_NDF_INT_W1S BDK_NDF_INT_W1S_FUNC()
static inline uint64_t BDK_NDF_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_INT_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000048ll;
    __bdk_csr_fatal("NDF_INT_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_INT_W1S bdk_ndf_int_w1s_t
#define bustype_BDK_NDF_INT_W1S BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_INT_W1S "NDF_INT_W1S"
#define busnum_BDK_NDF_INT_W1S 0
#define arguments_BDK_NDF_INT_W1S -1,-1,-1,-1

/**
 * Register (NCB) ndf_misc
 *
 * NAND Flash Miscellaneous Register
 * Sixty-four-bit operations must be used to access this register.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_misc_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_28_63        : 36;
        uint64_t mb_dis                : 1;  /**< [ 27: 27](R/W) Set to disable multi-bit error hangs. Allows boot loads and boot DMAs to proceed as if no
                                                                 multi-bit errors occurred. Hardware fixes single bit errors as usual. */
        uint64_t nbr_hwm               : 3;  /**< [ 26: 24](R/W) High watermark for NBR FIFO or load/store operations. This field specifies the high
                                                                 watermark for the IOI outbound load/store commands receive FIFO. NBR_HWM+1 is used
                                                                 as the high watermark.  So a value of 0 allows 1 entry in the FIFO at a time.  The
                                                                 FIFO size is 8 entries. */
        uint64_t wait_cnt              : 6;  /**< [ 23: 18](R/W) Wait input filter count. Represents the number of coprocessor-clock cycles for glitch
                                                                 filtering of BOOT_WAIT_L from the NAND flash device. */
        uint64_t fr_byt                : 11; /**< [ 17:  7](RO/H) Unfilled NDF_CMD queue bytes. This field specifies the number of unfilled bytes in the
                                                                 NDF_CMD queue. Bytes become unfilled as commands complete execution and exit. (FIFO is 256
                                                                 bytes when BT_DIS = 0 and 1536 bytes when BT_DIS = 1.) */
        uint64_t rd_done               : 1;  /**< [  6:  6](R/W1C/H) Read done. This bit is set to 1 by hardware when it reads the last eight bytes out of the
                                                                 NDF_CMD queue in response to RD_CMD being set to 1 by software. */
        uint64_t rd_val                : 1;  /**< [  5:  5](RO/H) This read-only bit is set to 1 by hardware when it reads the next eight bytes from NDF_CMD
                                                                 queue in response to RD_CMD being set to 1. A software read of NDF_CMD clears this bit to
                                                                 0. */
        uint64_t rd_cmd                : 1;  /**< [  4:  4](R/W) Read command. When set to 1, the hardware reads the contents of the NDF_CMD queue eight
                                                                 bytes at a time and places the data into NDF_CMD. Software should first read RD_VAL to see
                                                                 if the next eight bytes from the NDF_CMD queue are available in NDF_CMD.

                                                                 All NDF_CMD queue read operations start and end on an eight-byte boundary. A RD_CMD
                                                                 command in the middle of command execution causes the execution to freeze until RD_DONE is
                                                                 set to 1.

                                                                 This bit is cleared on any NDF_CMD software write command. */
        uint64_t bt_dma                : 1;  /**< [  3:  3](R/W) Boot-time DMA enable. When set to 1, boot-time DMA is enabled. This indicates to the NAND
                                                                 flash boot-control state machine that boot DMA read operations can begin. Software should
                                                                 set this bit to 1 after loading the NDF_CMD queue. Hardware sets the bit to 0 when boot
                                                                 DMA command execution is complete. If chip-enable 0 is not a NAND flash device, this bit
                                                                 is permanently 0 with software write operations ignored.

                                                                 When [BT_DIS] = 1, this bit is 0. */
        uint64_t bt_dis                : 1;  /**< [  2:  2](R/W) Boot disable. When the boot operation is over, software must set this field to 1, which
                                                                 causes the boot-control state machines to sleep.

                                                                 This bit indicates to the NAND flash boot-control state machine that boot operation has
                                                                 ended. When this bit changes from 0 -> 1, the NDF_CMD queue is emptied as a side effect.

                                                                 This bit must never be set when booting from NAND flash and region zero is enabled. */
        uint64_t ex_dis                : 1;  /**< [  1:  1](R/W) Execution disable. When set to 1, this bit stops command execution after completing the
                                                                 execution of all commands currently in the NDF_CMD queue. Once command execution has
                                                                 stopped and then new commands are loaded into the NDF_CMD queue, command execution does
                                                                 not resume while this bit is 1.

                                                                 When this bit is set to 0, execution resumes if the NDF_CMD queue is not empty. */
        uint64_t rst_ff                : 1;  /**< [  0:  0](R/W) Reset FIFO.
                                                                 0 = Normal operation.
                                                                 1 = Reset NDF_CMD queue to empty it; any command in flight is not aborted before
                                                                 resetting. The FIFO comes up empty at the end of power on reset. */
#else /* Word 0 - Little Endian */
        uint64_t rst_ff                : 1;  /**< [  0:  0](R/W) Reset FIFO.
                                                                 0 = Normal operation.
                                                                 1 = Reset NDF_CMD queue to empty it; any command in flight is not aborted before
                                                                 resetting. The FIFO comes up empty at the end of power on reset. */
        uint64_t ex_dis                : 1;  /**< [  1:  1](R/W) Execution disable. When set to 1, this bit stops command execution after completing the
                                                                 execution of all commands currently in the NDF_CMD queue. Once command execution has
                                                                 stopped and then new commands are loaded into the NDF_CMD queue, command execution does
                                                                 not resume while this bit is 1.

                                                                 When this bit is set to 0, execution resumes if the NDF_CMD queue is not empty. */
        uint64_t bt_dis                : 1;  /**< [  2:  2](R/W) Boot disable. When the boot operation is over, software must set this field to 1, which
                                                                 causes the boot-control state machines to sleep.

                                                                 This bit indicates to the NAND flash boot-control state machine that boot operation has
                                                                 ended. When this bit changes from 0 -> 1, the NDF_CMD queue is emptied as a side effect.

                                                                 This bit must never be set when booting from NAND flash and region zero is enabled. */
        uint64_t bt_dma                : 1;  /**< [  3:  3](R/W) Boot-time DMA enable. When set to 1, boot-time DMA is enabled. This indicates to the NAND
                                                                 flash boot-control state machine that boot DMA read operations can begin. Software should
                                                                 set this bit to 1 after loading the NDF_CMD queue. Hardware sets the bit to 0 when boot
                                                                 DMA command execution is complete. If chip-enable 0 is not a NAND flash device, this bit
                                                                 is permanently 0 with software write operations ignored.

                                                                 When [BT_DIS] = 1, this bit is 0. */
        uint64_t rd_cmd                : 1;  /**< [  4:  4](R/W) Read command. When set to 1, the hardware reads the contents of the NDF_CMD queue eight
                                                                 bytes at a time and places the data into NDF_CMD. Software should first read RD_VAL to see
                                                                 if the next eight bytes from the NDF_CMD queue are available in NDF_CMD.

                                                                 All NDF_CMD queue read operations start and end on an eight-byte boundary. A RD_CMD
                                                                 command in the middle of command execution causes the execution to freeze until RD_DONE is
                                                                 set to 1.

                                                                 This bit is cleared on any NDF_CMD software write command. */
        uint64_t rd_val                : 1;  /**< [  5:  5](RO/H) This read-only bit is set to 1 by hardware when it reads the next eight bytes from NDF_CMD
                                                                 queue in response to RD_CMD being set to 1. A software read of NDF_CMD clears this bit to
                                                                 0. */
        uint64_t rd_done               : 1;  /**< [  6:  6](R/W1C/H) Read done. This bit is set to 1 by hardware when it reads the last eight bytes out of the
                                                                 NDF_CMD queue in response to RD_CMD being set to 1 by software. */
        uint64_t fr_byt                : 11; /**< [ 17:  7](RO/H) Unfilled NDF_CMD queue bytes. This field specifies the number of unfilled bytes in the
                                                                 NDF_CMD queue. Bytes become unfilled as commands complete execution and exit. (FIFO is 256
                                                                 bytes when BT_DIS = 0 and 1536 bytes when BT_DIS = 1.) */
        uint64_t wait_cnt              : 6;  /**< [ 23: 18](R/W) Wait input filter count. Represents the number of coprocessor-clock cycles for glitch
                                                                 filtering of BOOT_WAIT_L from the NAND flash device. */
        uint64_t nbr_hwm               : 3;  /**< [ 26: 24](R/W) High watermark for NBR FIFO or load/store operations. This field specifies the high
                                                                 watermark for the IOI outbound load/store commands receive FIFO. NBR_HWM+1 is used
                                                                 as the high watermark.  So a value of 0 allows 1 entry in the FIFO at a time.  The
                                                                 FIFO size is 8 entries. */
        uint64_t mb_dis                : 1;  /**< [ 27: 27](R/W) Set to disable multi-bit error hangs. Allows boot loads and boot DMAs to proceed as if no
                                                                 multi-bit errors occurred. Hardware fixes single bit errors as usual. */
        uint64_t reserved_28_63        : 36;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_misc_s cn; */
} bdk_ndf_misc_t;

#define BDK_NDF_MISC BDK_NDF_MISC_FUNC()
static inline uint64_t BDK_NDF_MISC_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_MISC_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000008ll;
    __bdk_csr_fatal("NDF_MISC", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_MISC bdk_ndf_misc_t
#define bustype_BDK_NDF_MISC BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_MISC "NDF_MISC"
#define busnum_BDK_NDF_MISC 0
#define arguments_BDK_NDF_MISC -1,-1,-1,-1

/**
 * Register (NCB) ndf_msix_pba#
 *
 * NAND Flash MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the NDF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated NDF_MSIX_VEC()_CTL, enumerated by
                                                                 NDF_INT_VEC_E. Bits that have no associated NDF_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO/H) Pending message for the associated NDF_MSIX_VEC()_CTL, enumerated by
                                                                 NDF_INT_VEC_E. Bits that have no associated NDF_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_msix_pbax_s cn; */
} bdk_ndf_msix_pbax_t;

static inline uint64_t BDK_NDF_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x808000ff0008ll + 0ll * ((a) & 0x0);
    __bdk_csr_fatal("NDF_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_NDF_MSIX_PBAX(a) bdk_ndf_msix_pbax_t
#define bustype_BDK_NDF_MSIX_PBAX(a) BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_MSIX_PBAX(a) "NDF_MSIX_PBAX"
#define busnum_BDK_NDF_MSIX_PBAX(a) (a)
#define arguments_BDK_NDF_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (NCB) ndf_msix_vec#_addr
 *
 * NAND Flash MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the NDF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NDF_MSIX_VEC()_ADDR, NDF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NDF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NDF_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](R/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NDF_MSIX_VEC()_ADDR, NDF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NDF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NDF_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is set, all vectors are secure and function as if
                                                                 [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_msix_vecx_addr_s cn; */
} bdk_ndf_msix_vecx_addr_t;

static inline uint64_t BDK_NDF_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x808000f00000ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("NDF_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_NDF_MSIX_VECX_ADDR(a) bdk_ndf_msix_vecx_addr_t
#define bustype_BDK_NDF_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_MSIX_VECX_ADDR(a) "NDF_MSIX_VECX_ADDR"
#define busnum_BDK_NDF_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_NDF_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (NCB) ndf_msix_vec#_ctl
 *
 * NAND Flash MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the NDF_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_msix_vecx_ctl_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_33_63        : 31;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
#else /* Word 0 - Little Endian */
        uint64_t data                  : 20; /**< [ 19:  0](R/W) Data to use for MSI-X delivery of this vector. */
        uint64_t reserved_20_31        : 12;
        uint64_t mask                  : 1;  /**< [ 32: 32](R/W) When set, no MSI-X interrupts are sent to this vector. */
        uint64_t reserved_33_63        : 31;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_msix_vecx_ctl_s cn; */
} bdk_ndf_msix_vecx_ctl_t;

static inline uint64_t BDK_NDF_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x808000f00008ll + 0x10ll * ((a) & 0x0);
    __bdk_csr_fatal("NDF_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_NDF_MSIX_VECX_CTL(a) bdk_ndf_msix_vecx_ctl_t
#define bustype_BDK_NDF_MSIX_VECX_CTL(a) BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_MSIX_VECX_CTL(a) "NDF_MSIX_VECX_CTL"
#define busnum_BDK_NDF_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_NDF_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (NCB) ndf_st_reg
 *
 * NAND Flash State Machine Register
 * This register aggregates all state machines used in NAND flash controller for debug purposes.
 */
typedef union
{
    uint64_t u;
    struct bdk_ndf_st_reg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_16_63        : 48;
        uint64_t exe_idle              : 1;  /**< [ 15: 15](RO/H) Command execution status
                                                                 0 = Busy.
                                                                 1 = Idle (execution of command sequence is complete and NDF_CMD queue is empty). */
        uint64_t exe_sm                : 4;  /**< [ 14: 11](RO/H) Command-execution state-machine states. */
        uint64_t bt_sm                 : 4;  /**< [ 10:  7](RO/H) Boot-load and boot-DMA state-machine states. */
        uint64_t rd_ff_bad             : 1;  /**< [  6:  6](RO/H) The NDF_CMD-queue read-back state machine is in a 'bad' state. */
        uint64_t rd_ff                 : 2;  /**< [  5:  4](RO/H) NDF_CMD-queue read-back state machine states. */
        uint64_t main_bad              : 1;  /**< [  3:  3](RO/H) The main state machine is in a 'bad' state. */
        uint64_t main_sm               : 3;  /**< [  2:  0](RO/H) Main state-machine states. */
#else /* Word 0 - Little Endian */
        uint64_t main_sm               : 3;  /**< [  2:  0](RO/H) Main state-machine states. */
        uint64_t main_bad              : 1;  /**< [  3:  3](RO/H) The main state machine is in a 'bad' state. */
        uint64_t rd_ff                 : 2;  /**< [  5:  4](RO/H) NDF_CMD-queue read-back state machine states. */
        uint64_t rd_ff_bad             : 1;  /**< [  6:  6](RO/H) The NDF_CMD-queue read-back state machine is in a 'bad' state. */
        uint64_t bt_sm                 : 4;  /**< [ 10:  7](RO/H) Boot-load and boot-DMA state-machine states. */
        uint64_t exe_sm                : 4;  /**< [ 14: 11](RO/H) Command-execution state-machine states. */
        uint64_t exe_idle              : 1;  /**< [ 15: 15](RO/H) Command execution status
                                                                 0 = Busy.
                                                                 1 = Idle (execution of command sequence is complete and NDF_CMD queue is empty). */
        uint64_t reserved_16_63        : 48;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_ndf_st_reg_s cn; */
} bdk_ndf_st_reg_t;

#define BDK_NDF_ST_REG BDK_NDF_ST_REG_FUNC()
static inline uint64_t BDK_NDF_ST_REG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NDF_ST_REG_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x808000000038ll;
    __bdk_csr_fatal("NDF_ST_REG", 0, 0, 0, 0, 0);
}

#define typedef_BDK_NDF_ST_REG bdk_ndf_st_reg_t
#define bustype_BDK_NDF_ST_REG BDK_CSR_TYPE_NCB
#define basename_BDK_NDF_ST_REG "NDF_ST_REG"
#define busnum_BDK_NDF_ST_REG 0
#define arguments_BDK_NDF_ST_REG -1,-1,-1,-1

#endif /* __BDK_CSRS_NDF_H__ */

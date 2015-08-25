#ifndef __BDK_CSRS_PBUS_H__
#define __BDK_CSRS_PBUS_H__
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
 * Cavium PBUS.
 *
 * This file is auto generated. Do not edit.
 *
 */

/**
 * Enumeration pbus_bar_e
 *
 * PBUS Base Address Register Enumeration
 * Enumerates the base address registers.
 */
#define BDK_PBUS_BAR_E_PBUS_PF_BAR0 (0x87e001000000ll) /**< Base address for standard registers. */
#define BDK_PBUS_BAR_E_PBUS_PF_BAR2 (0x800000000000ll) /**< Base address for pbus devices. */
#define BDK_PBUS_BAR_E_PBUS_PF_BAR4 (0x87e001f00000ll) /**< Base address for MSI-X registers. */

/**
 * Enumeration pbus_int_vec_e
 *
 * PBUS PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
#define BDK_PBUS_INT_VEC_E_DMAX(a) (1 + (a)) /**< (0..1)See interrupt clears PBUS_DMA_INT(0..1),
                                       interrupt sets PBUS_DMA_INT_W1S(0..1),
                                       enable clears PBUS_DMA_INT_ENA_W1C(0..1),
                                       and enable sets PBUS_DMA_INT_ENA_W1S(0..1). */
#define BDK_PBUS_INT_VEC_E_ERR (0) /**< See interrupt clears PBUS_ERR(0..1),
                                       interrupt sets PBUS_ERR_W1S(0..1),
                                       enable clears PBUS_ERR_ENA_W1C(0..1),
                                       and enable sets PBUS_ERR_ENA_W1S(0..1). */

/**
 * Register (RSL) pbus_bist_status
 *
 * MIO Boot BIST Status Register
 * The boot BIST status register contains the BIST status for the MIO boot memories: 0 = pass, 1
 * = fail.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_bist_status_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_8_63         : 56;
        uint64_t stat                  : 8;  /**< [  7:  0](RO/H) BIST status.
                                                                 INTERNAL:
                                                                   <0> = mio.mio_boot.boot_fifo.mem.
                                                                   <1> = mio.mio_boot.mio_boot_emm.mem.
                                                                   <2> = mio.mio_boot.mio_boot_mem2.mem.
                                                                   <3> = mio.mio_boot.boot_loc.mem.
                                                                   <4> = mio.mio_boot.dma_fifo.mem.
                                                                   <5> = mio.mio_nbt.mio_nbt_fifo.mem.
                                                                   <6> = mio.mio_emm.bufs.mem.mem.
                                                                   <7> = mio_boot_rom/mio_boot_rom1 (bootroms). */
#else /* Word 0 - Little Endian */
        uint64_t stat                  : 8;  /**< [  7:  0](RO/H) BIST status.
                                                                 INTERNAL:
                                                                   <0> = mio.mio_boot.boot_fifo.mem.
                                                                   <1> = mio.mio_boot.mio_boot_emm.mem.
                                                                   <2> = mio.mio_boot.mio_boot_mem2.mem.
                                                                   <3> = mio.mio_boot.boot_loc.mem.
                                                                   <4> = mio.mio_boot.dma_fifo.mem.
                                                                   <5> = mio.mio_nbt.mio_nbt_fifo.mem.
                                                                   <6> = mio.mio_emm.bufs.mem.mem.
                                                                   <7> = mio_boot_rom/mio_boot_rom1 (bootroms). */
        uint64_t reserved_8_63         : 56;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_bist_status_s cn; */
} bdk_pbus_bist_status_t;

#define BDK_PBUS_BIST_STATUS BDK_PBUS_BIST_STATUS_FUNC()
static inline uint64_t BDK_PBUS_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_BIST_STATUS_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0010000f8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0010000f8ll;
    __bdk_csr_fatal("PBUS_BIST_STATUS", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_BIST_STATUS bdk_pbus_bist_status_t
#define bustype_BDK_PBUS_BIST_STATUS BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_BIST_STATUS "PBUS_BIST_STATUS"
#define busnum_BDK_PBUS_BIST_STATUS 0
#define arguments_BDK_PBUS_BIST_STATUS -1,-1,-1,-1

/**
 * Register (RSL) pbus_comp
 *
 * MIO Boot Compensation Register
 * This register sets the output impedance of boot-bus output pins.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_comp_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_11_63        : 53;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) Boot bus PCTL. This controls the pull-up drive strength of the boot-bus drivers. Reset
                                                                 value is as follows:
                                                                 0x4 = Pullup on BOOT_AD<10> (60 ohm output impedance).
                                                                 0x6 = No pullups (40 ohm output impedance).
                                                                 0x7 = Pullup on BOOT_AD<9> (30 ohm output impedance). */
        uint64_t reserved_3_7          : 5;
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) Boot bus NCTL. This controls the pull-down drive strength of the boot-bus drivers. Reset
                                                                 value is as follows:
                                                                 0x4 = Pullup on BOOT_AD<10> (60 ohm output impedance).
                                                                 0x6 = No pullups (40 ohm output impedance).
                                                                 0x7 = Pullup on BOOT_AD<9> (30 ohm output impedance). */
#else /* Word 0 - Little Endian */
        uint64_t nctl                  : 3;  /**< [  2:  0](R/W) Boot bus NCTL. This controls the pull-down drive strength of the boot-bus drivers. Reset
                                                                 value is as follows:
                                                                 0x4 = Pullup on BOOT_AD<10> (60 ohm output impedance).
                                                                 0x6 = No pullups (40 ohm output impedance).
                                                                 0x7 = Pullup on BOOT_AD<9> (30 ohm output impedance). */
        uint64_t reserved_3_7          : 5;
        uint64_t pctl                  : 3;  /**< [ 10:  8](R/W) Boot bus PCTL. This controls the pull-up drive strength of the boot-bus drivers. Reset
                                                                 value is as follows:
                                                                 0x4 = Pullup on BOOT_AD<10> (60 ohm output impedance).
                                                                 0x6 = No pullups (40 ohm output impedance).
                                                                 0x7 = Pullup on BOOT_AD<9> (30 ohm output impedance). */
        uint64_t reserved_11_63        : 53;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_comp_s cn; */
} bdk_pbus_comp_t;

#define BDK_PBUS_COMP BDK_PBUS_COMP_FUNC()
static inline uint64_t BDK_PBUS_COMP_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_COMP_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0010000b8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0010000b8ll;
    __bdk_csr_fatal("PBUS_COMP", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_COMP bdk_pbus_comp_t
#define bustype_BDK_PBUS_COMP BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_COMP "PBUS_COMP"
#define busnum_BDK_PBUS_COMP 0
#define arguments_BDK_PBUS_COMP -1,-1,-1,-1

/**
 * Register (RSL) pbus_dma_adr#
 *
 * MIO Boot DMA Engine Address Registers
 * This is the DMA engine n address register (one register for each of two engines).
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_adrx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t adr                   : 49; /**< [ 48:  0](R/W/H) DMA engine 0-1 address. This value must be aligned to the bus width (i.e. 16-bit aligned
                                                                 if WIDTH=0, 32-bit aligned if WIDTH=1). */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 49; /**< [ 48:  0](R/W/H) DMA engine 0-1 address. This value must be aligned to the bus width (i.e. 16-bit aligned
                                                                 if WIDTH=0, 32-bit aligned if WIDTH=1). */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_adrx_s cn; */
} bdk_pbus_dma_adrx_t;

static inline uint64_t BDK_PBUS_DMA_ADRX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_ADRX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000110ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000110ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_ADRX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_ADRX(a) bdk_pbus_dma_adrx_t
#define bustype_BDK_PBUS_DMA_ADRX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_ADRX(a) "PBUS_DMA_ADRX"
#define busnum_BDK_PBUS_DMA_ADRX(a) (a)
#define arguments_BDK_PBUS_DMA_ADRX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_cfg#
 *
 * MIO Boot DMA Engine Configuration Registers
 * This is the DMA engine n configuration register (one register for each of two engines).
 * Care must be taken to insure that the DMA duration not exceed the processor timeout of 2^29
 * core clocks or the RML timeout specified in SLI_WINDOW_CTL[TIME] coprocessor clocks if
 * accesses to the bootbus occur while DMA operations are in progress.
 * The DMA operation duration in coprocessor clocks as:
 * PBUS_DMA_CFG()[SIZE] * PBUS_DMA_TIM()[TIM_MULT] * CYCLE_TIME.
 * Where:
 * CYCLE_TIME = PBUS_DMA_TIM()[RD_DLY+PAUSE+DMACK_H+WE_N+WE_A+OE_N+OE_A+DMACK_S].
 * Coprocessor clocks can be converted to core clocks by multiplying the value by the clock ratio
 * RST_BOOT[C_MUL] / RST_BOOT[PNR_MUL].
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_cfgx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine 0-1 enable. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine 0-1 R/W bit (0 = read, 1 = write). */
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W) DMA engine 0-1 clear EN on device terminated burst. */
        uint64_t reserved_60           : 1;
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 0-1 32-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 0-1 16-bit swap. */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 0-1 8-bit swap. */
        uint64_t be                    : 1;  /**< [ 56: 56](R/W) DMA engine 0-1 IOB endian mode (0 = little, 1 = big). */
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine 0-1 size. SIZE is specified in number of bus transfers, where one transfer is
                                                                 equal to the following number of bytes, dependent on PBUS_DMA_TIM()[WIDTH] and
                                                                 PBUS_DMA_TIM()[DDR]:
                                                                 _ If WIDTH=0, DDR=0, then transfer is 2 bytes.
                                                                 _ If WIDTH=0, DDR=1, then transfer is 4 bytes.
                                                                 _ If WIDTH=1, DDR=0, then transfer is 4 bytes.
                                                                 _ If WIDTH=1, DDR=1, then transfer is 8 bytes. */
        uint64_t reserved_0_35         : 36;
#else /* Word 0 - Little Endian */
        uint64_t reserved_0_35         : 36;
        uint64_t size                  : 20; /**< [ 55: 36](R/W/H) DMA engine 0-1 size. SIZE is specified in number of bus transfers, where one transfer is
                                                                 equal to the following number of bytes, dependent on PBUS_DMA_TIM()[WIDTH] and
                                                                 PBUS_DMA_TIM()[DDR]:
                                                                 _ If WIDTH=0, DDR=0, then transfer is 2 bytes.
                                                                 _ If WIDTH=0, DDR=1, then transfer is 4 bytes.
                                                                 _ If WIDTH=1, DDR=0, then transfer is 4 bytes.
                                                                 _ If WIDTH=1, DDR=1, then transfer is 8 bytes. */
        uint64_t be                    : 1;  /**< [ 56: 56](R/W) DMA engine 0-1 IOB endian mode (0 = little, 1 = big). */
        uint64_t swap8                 : 1;  /**< [ 57: 57](R/W) DMA engine 0-1 8-bit swap. */
        uint64_t swap16                : 1;  /**< [ 58: 58](R/W) DMA engine 0-1 16-bit swap. */
        uint64_t swap32                : 1;  /**< [ 59: 59](R/W) DMA engine 0-1 32-bit swap. */
        uint64_t reserved_60           : 1;
        uint64_t clr                   : 1;  /**< [ 61: 61](R/W) DMA engine 0-1 clear EN on device terminated burst. */
        uint64_t rw                    : 1;  /**< [ 62: 62](R/W) DMA engine 0-1 R/W bit (0 = read, 1 = write). */
        uint64_t en                    : 1;  /**< [ 63: 63](R/W/H) DMA engine 0-1 enable. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_cfgx_s cn; */
} bdk_pbus_dma_cfgx_t;

static inline uint64_t BDK_PBUS_DMA_CFGX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_CFGX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000100ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000100ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_CFGX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_CFGX(a) bdk_pbus_dma_cfgx_t
#define bustype_BDK_PBUS_DMA_CFGX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_CFGX(a) "PBUS_DMA_CFGX"
#define busnum_BDK_PBUS_DMA_CFGX(a) (a)
#define arguments_BDK_PBUS_DMA_CFGX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_int#
 *
 * MIO Boot DMA Engine Interrupt Registers
 * This is the DMA engine n interrupt register (one register for each of two engines).
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_intx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t dmarq                 : 1;  /**< [  1:  1](RO/H) DMA engine DMARQ asserted interrupt. */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) DMA engine request completion interrupt. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) DMA engine request completion interrupt. */
        uint64_t dmarq                 : 1;  /**< [  1:  1](RO/H) DMA engine DMARQ asserted interrupt. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_intx_s cn; */
} bdk_pbus_dma_intx_t;

static inline uint64_t BDK_PBUS_DMA_INTX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_INTX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000200ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000200ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_INTX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_INTX(a) bdk_pbus_dma_intx_t
#define bustype_BDK_PBUS_DMA_INTX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_INTX(a) "PBUS_DMA_INTX"
#define busnum_BDK_PBUS_DMA_INTX(a) (a)
#define arguments_BDK_PBUS_DMA_INTX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_int_ena_w1c#
 *
 * MIO Boot DMA Engine Interrupt Enable Clear Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_int_ena_w1cx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears PBUS_DMA_INT_ENA_W1S()[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1C/H) Reads or clears PBUS_DMA_INT_ENA_W1S()[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_int_ena_w1cx_s cn; */
} bdk_pbus_dma_int_ena_w1cx_t;

static inline uint64_t BDK_PBUS_DMA_INT_ENA_W1CX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_INT_ENA_W1CX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e0010002c0ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e0010002c0ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_INT_ENA_W1CX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_INT_ENA_W1CX(a) bdk_pbus_dma_int_ena_w1cx_t
#define bustype_BDK_PBUS_DMA_INT_ENA_W1CX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_INT_ENA_W1CX(a) "PBUS_DMA_INT_ENA_W1CX"
#define busnum_BDK_PBUS_DMA_INT_ENA_W1CX(a) (a)
#define arguments_BDK_PBUS_DMA_INT_ENA_W1CX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_int_ena_w1s#
 *
 * MIO Boot DMA Engine Interrupt Enable Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_int_ena_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or enables reporting of PBUS_DMA_INT()[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or enables reporting of PBUS_DMA_INT()[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_int_ena_w1sx_s cn; */
} bdk_pbus_dma_int_ena_w1sx_t;

static inline uint64_t BDK_PBUS_DMA_INT_ENA_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_INT_ENA_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000280ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000280ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_INT_ENA_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_INT_ENA_W1SX(a) bdk_pbus_dma_int_ena_w1sx_t
#define bustype_BDK_PBUS_DMA_INT_ENA_W1SX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_INT_ENA_W1SX(a) "PBUS_DMA_INT_ENA_W1SX"
#define busnum_BDK_PBUS_DMA_INT_ENA_W1SX(a) (a)
#define arguments_BDK_PBUS_DMA_INT_ENA_W1SX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_int_w1s#
 *
 * MIO Boot DMA Engine Interrupt Set Registers
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_int_w1sx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_1_63         : 63;
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PBUS_DMA_INT()[DONE]. */
#else /* Word 0 - Little Endian */
        uint64_t done                  : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PBUS_DMA_INT()[DONE]. */
        uint64_t reserved_1_63         : 63;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_int_w1sx_s cn; */
} bdk_pbus_dma_int_w1sx_t;

static inline uint64_t BDK_PBUS_DMA_INT_W1SX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_INT_W1SX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000240ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000240ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_INT_W1SX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_INT_W1SX(a) bdk_pbus_dma_int_w1sx_t
#define bustype_BDK_PBUS_DMA_INT_W1SX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_INT_W1SX(a) "PBUS_DMA_INT_W1SX"
#define busnum_BDK_PBUS_DMA_INT_W1SX(a) (a)
#define arguments_BDK_PBUS_DMA_INT_W1SX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_dma_tim#
 *
 * MIO Boot DMA Engine Timing Registers
 * This is the DMA engine n timing register (one register for each of two engines).
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_dma_timx_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t dmack_pi              : 1;  /**< [ 63: 63](R/W) DMA acknowledgment polarity inversion. DMACK_PI inverts the assertion level of
                                                                 BOOT_DMACKn. The default polarity of BOOT_DMACK<1:0> is selected on the first deassertion
                                                                 of reset by the values on BOOT_AD<12:11>, where 0 specifies active high and 1 specifies
                                                                 active low. (See PBUS_PIN_DEFS for a read-only copy of the default polarity.)
                                                                 BOOT_AD<12:11> have internal pull-down resistors, so place a pull-up resistor on
                                                                 BOOT_AD<n+11> for active low default polarity on engine n. To interface with CF cards in
                                                                 True IDE Mode, either a pull-up resistor should be placed on BOOT_AD<n+11> OR the
                                                                 corresponding DMACK_PI[n] should be set. */
        uint64_t dmarq_pi              : 1;  /**< [ 62: 62](R/W) DMA request polarity inversion. DMARQ_PI inverts the assertion level of BOOT_DMARQn. The
                                                                 default polarity of BOOT_DMARQ<1:0> is active high, so that setting the polarity inversion
                                                                 bits changes the polarity to active low. To interface with CF cards in True IDE Mode, the
                                                                 corresponding DMARQ_PI[n] should be clear. */
        uint64_t tim_mult              : 2;  /**< [ 61: 60](R/W) Timing multiplier. This field specifies the timing multiplier for an engine. The timing
                                                                 multiplier applies to all timing parameters, except for DMARQ and RD_DLY, which simply
                                                                 count coprocessor-clock cycles. TIM_MULT is encoded as follows: 0x0 = 4x, 0x1 = 1x, 0x2 =
                                                                 2x, 0x3 = 8x. */
        uint64_t rd_dly                : 3;  /**< [ 59: 57](R/W) Read sample delay. This field specifies the read sample delay in coprocessor-clock cycles
                                                                 for an engine. For read operations, the data bus is normally sampled on the same
                                                                 coprocessor-clock edge that drives BOOT_OE_L high (and also low in DDR mode). This
                                                                 parameter can delay that sampling edge by up to seven coprocessor-clock cycles.
                                                                 The number of coprocessor-clock cycles counted by the OE_A and DMACK_H + PAUSE timing
                                                                 parameters must be greater than RD_DLY. */
        uint64_t ddr                   : 1;  /**< [ 56: 56](R/W) DDR mode. If DDR is set, then WE_N must be less than WE_A. */
        uint64_t width                 : 1;  /**< [ 55: 55](R/W) Bus width (0 = 16 bits, 1 = 32 bits). */
        uint64_t reserved_48_54        : 7;
        uint64_t pause                 : 6;  /**< [ 47: 42](R/W) Pause count. */
        uint64_t dmack_h               : 6;  /**< [ 41: 36](R/W) DMA acknowledgment hold count. */
        uint64_t we_n                  : 6;  /**< [ 35: 30](R/W) Write enable negated count. */
        uint64_t we_a                  : 6;  /**< [ 29: 24](R/W) Write enable asserted count. */
        uint64_t oe_n                  : 6;  /**< [ 23: 18](R/W) Output enable negated count. */
        uint64_t oe_a                  : 6;  /**< [ 17: 12](R/W) Output enable asserted count. */
        uint64_t dmack_s               : 6;  /**< [ 11:  6](R/W) DMA acknowledgment setup count. */
        uint64_t dmarq                 : 6;  /**< [  5:  0](R/W) DMA request count. (Must be non-zero.) */
#else /* Word 0 - Little Endian */
        uint64_t dmarq                 : 6;  /**< [  5:  0](R/W) DMA request count. (Must be non-zero.) */
        uint64_t dmack_s               : 6;  /**< [ 11:  6](R/W) DMA acknowledgment setup count. */
        uint64_t oe_a                  : 6;  /**< [ 17: 12](R/W) Output enable asserted count. */
        uint64_t oe_n                  : 6;  /**< [ 23: 18](R/W) Output enable negated count. */
        uint64_t we_a                  : 6;  /**< [ 29: 24](R/W) Write enable asserted count. */
        uint64_t we_n                  : 6;  /**< [ 35: 30](R/W) Write enable negated count. */
        uint64_t dmack_h               : 6;  /**< [ 41: 36](R/W) DMA acknowledgment hold count. */
        uint64_t pause                 : 6;  /**< [ 47: 42](R/W) Pause count. */
        uint64_t reserved_48_54        : 7;
        uint64_t width                 : 1;  /**< [ 55: 55](R/W) Bus width (0 = 16 bits, 1 = 32 bits). */
        uint64_t ddr                   : 1;  /**< [ 56: 56](R/W) DDR mode. If DDR is set, then WE_N must be less than WE_A. */
        uint64_t rd_dly                : 3;  /**< [ 59: 57](R/W) Read sample delay. This field specifies the read sample delay in coprocessor-clock cycles
                                                                 for an engine. For read operations, the data bus is normally sampled on the same
                                                                 coprocessor-clock edge that drives BOOT_OE_L high (and also low in DDR mode). This
                                                                 parameter can delay that sampling edge by up to seven coprocessor-clock cycles.
                                                                 The number of coprocessor-clock cycles counted by the OE_A and DMACK_H + PAUSE timing
                                                                 parameters must be greater than RD_DLY. */
        uint64_t tim_mult              : 2;  /**< [ 61: 60](R/W) Timing multiplier. This field specifies the timing multiplier for an engine. The timing
                                                                 multiplier applies to all timing parameters, except for DMARQ and RD_DLY, which simply
                                                                 count coprocessor-clock cycles. TIM_MULT is encoded as follows: 0x0 = 4x, 0x1 = 1x, 0x2 =
                                                                 2x, 0x3 = 8x. */
        uint64_t dmarq_pi              : 1;  /**< [ 62: 62](R/W) DMA request polarity inversion. DMARQ_PI inverts the assertion level of BOOT_DMARQn. The
                                                                 default polarity of BOOT_DMARQ<1:0> is active high, so that setting the polarity inversion
                                                                 bits changes the polarity to active low. To interface with CF cards in True IDE Mode, the
                                                                 corresponding DMARQ_PI[n] should be clear. */
        uint64_t dmack_pi              : 1;  /**< [ 63: 63](R/W) DMA acknowledgment polarity inversion. DMACK_PI inverts the assertion level of
                                                                 BOOT_DMACKn. The default polarity of BOOT_DMACK<1:0> is selected on the first deassertion
                                                                 of reset by the values on BOOT_AD<12:11>, where 0 specifies active high and 1 specifies
                                                                 active low. (See PBUS_PIN_DEFS for a read-only copy of the default polarity.)
                                                                 BOOT_AD<12:11> have internal pull-down resistors, so place a pull-up resistor on
                                                                 BOOT_AD<n+11> for active low default polarity on engine n. To interface with CF cards in
                                                                 True IDE Mode, either a pull-up resistor should be placed on BOOT_AD<n+11> OR the
                                                                 corresponding DMACK_PI[n] should be set. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_dma_timx_s cn; */
} bdk_pbus_dma_timx_t;

static inline uint64_t BDK_PBUS_DMA_TIMX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_DMA_TIMX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001000120ll + 8ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001000120ll + 8ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_DMA_TIMX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_DMA_TIMX(a) bdk_pbus_dma_timx_t
#define bustype_BDK_PBUS_DMA_TIMX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_DMA_TIMX(a) "PBUS_DMA_TIMX"
#define busnum_BDK_PBUS_DMA_TIMX(a) (a)
#define arguments_BDK_PBUS_DMA_TIMX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_eco
 *
 * INTERNAL: PBUS ECO Register
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_eco_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_32_63        : 32;
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
#else /* Word 0 - Little Endian */
        uint64_t eco_rw                : 32; /**< [ 31:  0](R/W) ECO flops. */
        uint64_t reserved_32_63        : 32;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_eco_s cn; */
} bdk_pbus_eco_t;

#define BDK_PBUS_ECO BDK_PBUS_ECO_FUNC()
static inline uint64_t BDK_PBUS_ECO_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_ECO_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e0010001f8ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e0010001f8ll;
    __bdk_csr_fatal("PBUS_ECO", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_ECO bdk_pbus_eco_t
#define bustype_BDK_PBUS_ECO BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_ECO "PBUS_ECO"
#define busnum_BDK_PBUS_ECO 0
#define arguments_BDK_PBUS_ECO -1,-1,-1,-1

/**
 * Register (RSL) pbus_err
 *
 * MIO Boot Error Register
 * The boot-error register contains the address decode error and wait mode error bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_err_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1C/H) Wait mode error. This bit is set when wait mode is enabled and the external wait signal is
                                                                 not deasserted after 32K coprocessor-clock cycles. */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1C/H) Address decode error. This bit is set when a boot-bus access does not hit in any of the
                                                                 eight remote regions or two local regions. */
#else /* Word 0 - Little Endian */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1C/H) Address decode error. This bit is set when a boot-bus access does not hit in any of the
                                                                 eight remote regions or two local regions. */
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1C/H) Wait mode error. This bit is set when wait mode is enabled and the external wait signal is
                                                                 not deasserted after 32K coprocessor-clock cycles. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_err_s cn; */
} bdk_pbus_err_t;

#define BDK_PBUS_ERR BDK_PBUS_ERR_FUNC()
static inline uint64_t BDK_PBUS_ERR_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_ERR_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e001000300ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e001000300ll;
    __bdk_csr_fatal("PBUS_ERR", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_ERR bdk_pbus_err_t
#define bustype_BDK_PBUS_ERR BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_ERR "PBUS_ERR"
#define busnum_BDK_PBUS_ERR 0
#define arguments_BDK_PBUS_ERR -1,-1,-1,-1

/**
 * Register (RSL) pbus_err_ena_w1c
 *
 * MIO Boot Error Enable Clear Register
 * This register clears interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_err_ena_w1c_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PBUS_ERR[WAIT_ERR]. */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PBUS_ERR[ADR_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1C/H) Reads or clears enable for PBUS_ERR[ADR_ERR]. */
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1C/H) Reads or clears enable for PBUS_ERR[WAIT_ERR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_err_ena_w1c_s cn; */
} bdk_pbus_err_ena_w1c_t;

#define BDK_PBUS_ERR_ENA_W1C BDK_PBUS_ERR_ENA_W1C_FUNC()
static inline uint64_t BDK_PBUS_ERR_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_ERR_ENA_W1C_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e001000318ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e001000318ll;
    __bdk_csr_fatal("PBUS_ERR_ENA_W1C", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_ERR_ENA_W1C bdk_pbus_err_ena_w1c_t
#define bustype_BDK_PBUS_ERR_ENA_W1C BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_ERR_ENA_W1C "PBUS_ERR_ENA_W1C"
#define busnum_BDK_PBUS_ERR_ENA_W1C 0
#define arguments_BDK_PBUS_ERR_ENA_W1C -1,-1,-1,-1

/**
 * Register (RSL) pbus_err_ena_w1s
 *
 * MIO Boot Error Enable Set Register
 * This register sets interrupt enable bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_err_ena_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PBUS_ERR[WAIT_ERR]. */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PBUS_ERR[ADR_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets enable for PBUS_ERR[ADR_ERR]. */
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets enable for PBUS_ERR[WAIT_ERR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_err_ena_w1s_s cn; */
} bdk_pbus_err_ena_w1s_t;

#define BDK_PBUS_ERR_ENA_W1S BDK_PBUS_ERR_ENA_W1S_FUNC()
static inline uint64_t BDK_PBUS_ERR_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_ERR_ENA_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e001000310ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e001000310ll;
    __bdk_csr_fatal("PBUS_ERR_ENA_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_ERR_ENA_W1S bdk_pbus_err_ena_w1s_t
#define bustype_BDK_PBUS_ERR_ENA_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_ERR_ENA_W1S "PBUS_ERR_ENA_W1S"
#define busnum_BDK_PBUS_ERR_ENA_W1S 0
#define arguments_BDK_PBUS_ERR_ENA_W1S -1,-1,-1,-1

/**
 * Register (RSL) pbus_err_w1s
 *
 * MIO Boot Error Set Register
 * This register sets interrupt bits.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_err_w1s_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_2_63         : 62;
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PBUS_ERR[WAIT_ERR]. */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PBUS_ERR[ADR_ERR]. */
#else /* Word 0 - Little Endian */
        uint64_t adr_err               : 1;  /**< [  0:  0](R/W1S/H) Reads or sets PBUS_ERR[ADR_ERR]. */
        uint64_t wait_err              : 1;  /**< [  1:  1](R/W1S/H) Reads or sets PBUS_ERR[WAIT_ERR]. */
        uint64_t reserved_2_63         : 62;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_err_w1s_s cn; */
} bdk_pbus_err_w1s_t;

#define BDK_PBUS_ERR_W1S BDK_PBUS_ERR_W1S_FUNC()
static inline uint64_t BDK_PBUS_ERR_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_ERR_W1S_FUNC(void)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 0x87e001000308ll;
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 0x87e001000308ll;
    __bdk_csr_fatal("PBUS_ERR_W1S", 0, 0, 0, 0, 0);
}

#define typedef_BDK_PBUS_ERR_W1S bdk_pbus_err_w1s_t
#define bustype_BDK_PBUS_ERR_W1S BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_ERR_W1S "PBUS_ERR_W1S"
#define busnum_BDK_PBUS_ERR_W1S 0
#define arguments_BDK_PBUS_ERR_W1S -1,-1,-1,-1

/**
 * Register (RSL) pbus_msix_pba#
 *
 * PBUS MSI-X Pending Bit Array Registers
 * This register is the MSI-X PBA table; the bit number is indexed by the PBUS_INT_VEC_E
 * enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_msix_pbax_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated PBUS_MSIX_VEC()_CTL, enumerated by
                                                                 PBUS_INT_VEC_E. Bits
                                                                 that have no associated PBUS_INT_VEC_E are 0. */
#else /* Word 0 - Little Endian */
        uint64_t pend                  : 64; /**< [ 63:  0](RO) Pending message for the associated PBUS_MSIX_VEC()_CTL, enumerated by
                                                                 PBUS_INT_VEC_E. Bits
                                                                 that have no associated PBUS_INT_VEC_E are 0. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_msix_pbax_s cn; */
} bdk_pbus_msix_pbax_t;

static inline uint64_t BDK_PBUS_MSIX_PBAX(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_MSIX_PBAX(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a==0))
        return 0x87e001ff0000ll + 8ll * ((a) & 0x0);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a==0))
        return 0x87e001ff0000ll + 8ll * ((a) & 0x0);
    __bdk_csr_fatal("PBUS_MSIX_PBAX", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_MSIX_PBAX(a) bdk_pbus_msix_pbax_t
#define bustype_BDK_PBUS_MSIX_PBAX(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_MSIX_PBAX(a) "PBUS_MSIX_PBAX"
#define busnum_BDK_PBUS_MSIX_PBAX(a) (a)
#define arguments_BDK_PBUS_MSIX_PBAX(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_msix_vec#_addr
 *
 * PBUS MSI-X Vector-Table Address Register
 * This register is the MSI-X vector table, indexed by the PBUS_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_msix_vecx_addr_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_49_63        : 15;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_1            : 1;
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PBUS_MSIX_VEC()_ADDR, PBUS_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of PBUS_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.
                                                                 If PCCPF_PBUS_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else /* Word 0 - Little Endian */
        uint64_t secvec                : 1;  /**< [  0:  0](SR/W) Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's PBUS_MSIX_VEC()_ADDR, PBUS_MSIX_VEC()_CTL, and
                                                                 corresponding
                                                                 bit of PBUS_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.
                                                                 If PCCPF_PBUS_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
        uint64_t reserved_1            : 1;
        uint64_t addr                  : 47; /**< [ 48:  2](R/W) Address to use for MSI-X delivery of this vector. */
        uint64_t reserved_49_63        : 15;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_msix_vecx_addr_s cn; */
} bdk_pbus_msix_vecx_addr_t;

static inline uint64_t BDK_PBUS_MSIX_VECX_ADDR(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_MSIX_VECX_ADDR(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001f00000ll + 0x10ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001f00000ll + 0x10ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_MSIX_VECX_ADDR", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_MSIX_VECX_ADDR(a) bdk_pbus_msix_vecx_addr_t
#define bustype_BDK_PBUS_MSIX_VECX_ADDR(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_MSIX_VECX_ADDR(a) "PBUS_MSIX_VECX_ADDR"
#define busnum_BDK_PBUS_MSIX_VECX_ADDR(a) (a)
#define arguments_BDK_PBUS_MSIX_VECX_ADDR(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_msix_vec#_ctl
 *
 * PBUS MSI-X Vector-Table Control and Data Register
 * This register is the MSI-X vector table, indexed by the PBUS_INT_VEC_E enumeration.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_msix_vecx_ctl_s
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
    /* struct bdk_pbus_msix_vecx_ctl_s cn; */
} bdk_pbus_msix_vecx_ctl_t;

static inline uint64_t BDK_PBUS_MSIX_VECX_CTL(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_MSIX_VECX_CTL(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=1))
        return 0x87e001f00008ll + 0x10ll * ((a) & 0x1);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=1))
        return 0x87e001f00008ll + 0x10ll * ((a) & 0x1);
    __bdk_csr_fatal("PBUS_MSIX_VECX_CTL", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_MSIX_VECX_CTL(a) bdk_pbus_msix_vecx_ctl_t
#define bustype_BDK_PBUS_MSIX_VECX_CTL(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_MSIX_VECX_CTL(a) "PBUS_MSIX_VECX_CTL"
#define busnum_BDK_PBUS_MSIX_VECX_CTL(a) (a)
#define arguments_BDK_PBUS_MSIX_VECX_CTL(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_reg#_cfg
 *
 * MIO Boot Region Configuration Registers
 * The region n configuration register (one register for each of seven regions) contains
 * configuration parameters for boot region n.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_regx_cfg_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t reserved_44_63        : 20;
        uint64_t dmack                 : 2;  /**< [ 43: 42](R/W) Region DMACK. If non-zero, this field asserts the corresponding BOOT_DMACK[n] pin when
                                                                 an access to this region is performed. DMACK is encoded as follows:
                                                                 0x0 = disabled.
                                                                 0x1 = BOOT_DMACK[0].
                                                                 0x2 = BOOT_DMACK[1].
                                                                 0x3 = BOOT_DMACK[2].

                                                                 This is useful for CF cards in PC card memory mode that support DMA because the -REG and
                                                                 -DMACK pins are shared.

                                                                 The assertion level of boot_dmack is specified by PBUS_DMA_TIM()[DMACK_PI]. */
        uint64_t tim_mult              : 2;  /**< [ 41: 40](R/W) Region timing multiplier. Specifies the timing multiplier for a region. The timing
                                                                 multiplier applies to all timing parameters, except for WAIT and RD_DLY, which simply
                                                                 count coprocessor-clock cycles. TIM_MULT is encoded as follows: 0x0 = 4*, 0x1 = 1*, 0x2 =
                                                                 2*, 0x3 = 8*. */
        uint64_t rd_dly                : 3;  /**< [ 39: 37](R/W) Region read sample delay. Specifies the read sample delay in coprocessor-clock cycles
                                                                 for a region. For read operations, the data bus is normally sampled on the same
                                                                 coprocessor-clock edge that drives BOOT_OE_L to the inactive state (or the coprocessor-
                                                                 clock edge that toggles the lower address bits in page mode). This parameter can delay
                                                                 that sampling edge by up to seven coprocessor-clock cycles.

                                                                 The number of coprocessor-clock cycles counted by the PAGE and RD_HLD timing parameters
                                                                 must be greater than or equal to RD_DLY. */
        uint64_t sam                   : 1;  /**< [ 36: 36](R/W) Region strobe AND mode. Internally combines the output-enable and write-enable strobes
                                                                 into a single strobe that is then driven onto both BOOT_OE_L and BOOT_WE_L.

                                                                 This is useful for parts that use a single strobe along with a read/write bit (the
                                                                 read/write bit can be driven from an address pin). */
        uint64_t we_ext                : 2;  /**< [ 35: 34](R/W) Region write-enable count extension. */
        uint64_t oe_ext                : 2;  /**< [ 33: 32](R/W) Region output-enable count extension. */
        uint64_t en                    : 1;  /**< [ 31: 31](R/W) Region enable. */
        uint64_t orbit                 : 1;  /**< [ 30: 30](R/W) Region ORBIT bit. Asserts the given region's chip enable when there is an address hit
                                                                 in the previous region.  Must be clear for region 0, since there is no previous region.

                                                                 This is useful for CF cards because it allows the use of 2 separate timing configurations
                                                                 for common memory and attribute memory. */
        uint64_t ale                   : 1;  /**< [ 29: 29](R/W) Region address-latch-enable mode. Enables the multiplexed address/data bus mode. */
        uint64_t width                 : 1;  /**< [ 28: 28](R/W) Region bus width: 0 = 8 bits, 1 = 16 bits. */
        uint64_t size                  : 12; /**< [ 27: 16](R/W) Region ize. Region size is specified in 64K blocks and in 'block-1' notation (i.e.
                                                                 0x0 = one 64K block, 0x1 = two 64K blocks, etc.). */
        uint64_t base                  : 16; /**< [ 15:  0](R/W) Region base address. Specifies address bits [31:16] of the first 64K block of the
                                                                 region. */
#else /* Word 0 - Little Endian */
        uint64_t base                  : 16; /**< [ 15:  0](R/W) Region base address. Specifies address bits [31:16] of the first 64K block of the
                                                                 region. */
        uint64_t size                  : 12; /**< [ 27: 16](R/W) Region ize. Region size is specified in 64K blocks and in 'block-1' notation (i.e.
                                                                 0x0 = one 64K block, 0x1 = two 64K blocks, etc.). */
        uint64_t width                 : 1;  /**< [ 28: 28](R/W) Region bus width: 0 = 8 bits, 1 = 16 bits. */
        uint64_t ale                   : 1;  /**< [ 29: 29](R/W) Region address-latch-enable mode. Enables the multiplexed address/data bus mode. */
        uint64_t orbit                 : 1;  /**< [ 30: 30](R/W) Region ORBIT bit. Asserts the given region's chip enable when there is an address hit
                                                                 in the previous region.  Must be clear for region 0, since there is no previous region.

                                                                 This is useful for CF cards because it allows the use of 2 separate timing configurations
                                                                 for common memory and attribute memory. */
        uint64_t en                    : 1;  /**< [ 31: 31](R/W) Region enable. */
        uint64_t oe_ext                : 2;  /**< [ 33: 32](R/W) Region output-enable count extension. */
        uint64_t we_ext                : 2;  /**< [ 35: 34](R/W) Region write-enable count extension. */
        uint64_t sam                   : 1;  /**< [ 36: 36](R/W) Region strobe AND mode. Internally combines the output-enable and write-enable strobes
                                                                 into a single strobe that is then driven onto both BOOT_OE_L and BOOT_WE_L.

                                                                 This is useful for parts that use a single strobe along with a read/write bit (the
                                                                 read/write bit can be driven from an address pin). */
        uint64_t rd_dly                : 3;  /**< [ 39: 37](R/W) Region read sample delay. Specifies the read sample delay in coprocessor-clock cycles
                                                                 for a region. For read operations, the data bus is normally sampled on the same
                                                                 coprocessor-clock edge that drives BOOT_OE_L to the inactive state (or the coprocessor-
                                                                 clock edge that toggles the lower address bits in page mode). This parameter can delay
                                                                 that sampling edge by up to seven coprocessor-clock cycles.

                                                                 The number of coprocessor-clock cycles counted by the PAGE and RD_HLD timing parameters
                                                                 must be greater than or equal to RD_DLY. */
        uint64_t tim_mult              : 2;  /**< [ 41: 40](R/W) Region timing multiplier. Specifies the timing multiplier for a region. The timing
                                                                 multiplier applies to all timing parameters, except for WAIT and RD_DLY, which simply
                                                                 count coprocessor-clock cycles. TIM_MULT is encoded as follows: 0x0 = 4*, 0x1 = 1*, 0x2 =
                                                                 2*, 0x3 = 8*. */
        uint64_t dmack                 : 2;  /**< [ 43: 42](R/W) Region DMACK. If non-zero, this field asserts the corresponding BOOT_DMACK[n] pin when
                                                                 an access to this region is performed. DMACK is encoded as follows:
                                                                 0x0 = disabled.
                                                                 0x1 = BOOT_DMACK[0].
                                                                 0x2 = BOOT_DMACK[1].
                                                                 0x3 = BOOT_DMACK[2].

                                                                 This is useful for CF cards in PC card memory mode that support DMA because the -REG and
                                                                 -DMACK pins are shared.

                                                                 The assertion level of boot_dmack is specified by PBUS_DMA_TIM()[DMACK_PI]. */
        uint64_t reserved_44_63        : 20;
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_regx_cfg_s cn; */
} bdk_pbus_regx_cfg_t;

static inline uint64_t BDK_PBUS_REGX_CFG(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_REGX_CFG(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=7))
        return 0x87e001000000ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x87e001000000ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("PBUS_REGX_CFG", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_REGX_CFG(a) bdk_pbus_regx_cfg_t
#define bustype_BDK_PBUS_REGX_CFG(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_REGX_CFG(a) "PBUS_REGX_CFG"
#define busnum_BDK_PBUS_REGX_CFG(a) (a)
#define arguments_BDK_PBUS_REGX_CFG(a) (a),-1,-1,-1

/**
 * Register (RSL) pbus_reg#_tim
 *
 * MIO Boot Regions Timing Registers
 * The region n timing register (one register for each of seven regions) contains page-mode,
 * wait-mode, and timing parameters for region n.
 */
typedef union
{
    uint64_t u;
    struct bdk_pbus_regx_tim_s
    {
#if __BYTE_ORDER == __BIG_ENDIAN /* Word 0 - Big Endian */
        uint64_t pagem                 : 1;  /**< [ 63: 63](R/W) Region page mode. */
        uint64_t waitm                 : 1;  /**< [ 62: 62](R/W) Region wait mode. */
        uint64_t pages                 : 2;  /**< [ 61: 60](R/W) Region page size: 00 = 8 bytes, 01 = 2 bytes, 10 = 4 bytes, 11 = 8 bytes. */
        uint64_t ale                   : 6;  /**< [ 59: 54](R/W) Region ALE count. Must be non-zero to ensure legal transitions on the corresponding
                                                                 boot bus outputs. */
        uint64_t page                  : 6;  /**< [ 53: 48](R/W) Region page count. Must be non-zero to ensure legal transitions on the corresponding
                                                                 boot bus outputs. */
        uint64_t wait                  : 6;  /**< [ 47: 42](R/W) Region wait count, must be nonzero when WAITM is set to 1. */
        uint64_t pause                 : 6;  /**< [ 41: 36](R/W) Region pause count. */
        uint64_t wr_hld                : 6;  /**< [ 35: 30](R/W) Region write-hold count. */
        uint64_t rd_hld                : 6;  /**< [ 29: 24](R/W) Region read-hold count. */
        uint64_t we                    : 6;  /**< [ 23: 18](R/W) Region write-enable count. Must be non-zero to ensure legal transitions on the
                                                                 corresponding boot bus outputs. */
        uint64_t oe                    : 6;  /**< [ 17: 12](R/W) Region output-enable count. Must be non-zero to ensure legal transitions on the
                                                                 corresponding boot bus outputs. */
        uint64_t ce                    : 6;  /**< [ 11:  6](R/W) Region chip-enable count. */
        uint64_t adr                   : 6;  /**< [  5:  0](R/W) Region address count. */
#else /* Word 0 - Little Endian */
        uint64_t adr                   : 6;  /**< [  5:  0](R/W) Region address count. */
        uint64_t ce                    : 6;  /**< [ 11:  6](R/W) Region chip-enable count. */
        uint64_t oe                    : 6;  /**< [ 17: 12](R/W) Region output-enable count. Must be non-zero to ensure legal transitions on the
                                                                 corresponding boot bus outputs. */
        uint64_t we                    : 6;  /**< [ 23: 18](R/W) Region write-enable count. Must be non-zero to ensure legal transitions on the
                                                                 corresponding boot bus outputs. */
        uint64_t rd_hld                : 6;  /**< [ 29: 24](R/W) Region read-hold count. */
        uint64_t wr_hld                : 6;  /**< [ 35: 30](R/W) Region write-hold count. */
        uint64_t pause                 : 6;  /**< [ 41: 36](R/W) Region pause count. */
        uint64_t wait                  : 6;  /**< [ 47: 42](R/W) Region wait count, must be nonzero when WAITM is set to 1. */
        uint64_t page                  : 6;  /**< [ 53: 48](R/W) Region page count. Must be non-zero to ensure legal transitions on the corresponding
                                                                 boot bus outputs. */
        uint64_t ale                   : 6;  /**< [ 59: 54](R/W) Region ALE count. Must be non-zero to ensure legal transitions on the corresponding
                                                                 boot bus outputs. */
        uint64_t pages                 : 2;  /**< [ 61: 60](R/W) Region page size: 00 = 8 bytes, 01 = 2 bytes, 10 = 4 bytes, 11 = 8 bytes. */
        uint64_t waitm                 : 1;  /**< [ 62: 62](R/W) Region wait mode. */
        uint64_t pagem                 : 1;  /**< [ 63: 63](R/W) Region page mode. */
#endif /* Word 0 - End */
    } s;
    /* struct bdk_pbus_regx_tim_s cn; */
} bdk_pbus_regx_tim_t;

static inline uint64_t BDK_PBUS_REGX_TIM(unsigned long a) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_PBUS_REGX_TIM(unsigned long a)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN81XX) && (a<=7))
        return 0x87e001000040ll + 8ll * ((a) & 0x7);
    if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) && (a<=7))
        return 0x87e001000040ll + 8ll * ((a) & 0x7);
    __bdk_csr_fatal("PBUS_REGX_TIM", 1, a, 0, 0, 0);
}

#define typedef_BDK_PBUS_REGX_TIM(a) bdk_pbus_regx_tim_t
#define bustype_BDK_PBUS_REGX_TIM(a) BDK_CSR_TYPE_RSL
#define basename_BDK_PBUS_REGX_TIM(a) "PBUS_REGX_TIM"
#define busnum_BDK_PBUS_REGX_TIM(a) (a)
#define arguments_BDK_PBUS_REGX_TIM(a) (a),-1,-1,-1

#endif /* __BDK_CSRS_PBUS_H__ */

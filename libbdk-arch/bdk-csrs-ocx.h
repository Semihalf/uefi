#ifndef __BDK_CSRS_OCX__
#define __BDK_CSRS_OCX__
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
 * Cavium OCX.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration OCX_INT_VEC_E
 *
 * OCX MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum ocx_int_vec_e {
	OCX_INT_VEC_E_COM_INTS = 0x3,
	OCX_INT_VEC_E_LNK_INTS0 = 0x0,
	OCX_INT_VEC_E_LNK_INTS1 = 0x1,
	OCX_INT_VEC_E_LNK_INTS2 = 0x2,
	OCX_INT_VEC_E_ENUM_LAST = 0x4,
};



/**
 * RSL - ocx_com_bist_status
 *
 * Contains status from last memory BIST for all RX FIFO memories. BIST status for TX FIFO
 * memories and REPLAY memories are organized by link and are located in
 * OCX_TLK(0..2)_BIST_STATUS.
 */
typedef union bdk_ocx_com_bist_status {
	uint64_t u;
	struct bdk_ocx_com_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t status                      : 36; /**< RO/H - \<35:34\> = Link 2 VC12            RX FIFOs.
                                                                 \<33:32\> = Link 2 VC4/VC2         RX FIFOs.
                                                                 \<31:30\> = Link 2 VC10/VC8/VC6    RX FIFOs.
                                                                 \<29:28\> = Link 1 VC12            RX FIFOs.
                                                                 \<27:26\> = Link 1 VC4/VC2         RX FIFOs.
                                                                 \<25:24\> = Link 1 VC10/VC8/VC6    RX FIFOs.
                                                                 \<23:22\> = Link 0 VC12            RX FIFOs.
                                                                 \<21:20\> = Link 0 VC4/VC2         RX FIFOs.
                                                                 \<19:18\> = Link 0 VC10/VC8/VC6    RX FIFOs.
                                                                 \<17:16\> = Link 2 VC1/VC0         RX FIFOs.
                                                                 \<15:14\> = Link 2 VC5/VC3         RX FIFOs.
                                                                 \<13:12\> = Link 2 VC11/VC9/VC7    RX FIFOs.
                                                                 \<11:10\> = Link 1 VC1/VC0         RX FIFOs.
                                                                 \<9:8\>   = Link 1 VC5/VC3         RX FIFOs.
                                                                 \<7:6\>   = Link 1 VC11/VC9/VC7    RX FIFOs.
                                                                 \<5:4\>   = Link 0 VC1/VC0         RX FIFOs.
                                                                 \<3:2\>   = Link 0 VC5/VC3         RX FIFOs.
                                                                 \<1:0\>   = Link 0 VC11/VC9/VC7    RX FIFOs. */
#else
		uint64_t status                      : 36;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_ocx_com_bist_status_s   cn88xx; */
	/* struct bdk_ocx_com_bist_status_s   cn88xxp1; */
} bdk_ocx_com_bist_status_t;

#define BDK_OCX_COM_BIST_STATUS BDK_OCX_COM_BIST_STATUS_FUNC()
static inline uint64_t BDK_OCX_COM_BIST_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_BIST_STATUS_FUNC(void)
{
	return 0x000087E0110000F0ull;
}
#define typedef_BDK_OCX_COM_BIST_STATUS bdk_ocx_com_bist_status_t
#define bustype_BDK_OCX_COM_BIST_STATUS BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_BIST_STATUS 0
#define arguments_BDK_OCX_COM_BIST_STATUS -1,-1,-1,-1
#define basename_BDK_OCX_COM_BIST_STATUS "OCX_COM_BIST_STATUS"


/**
 * RSL - ocx_com_dual_sort
 */
typedef union bdk_ocx_com_dual_sort {
	uint64_t u;
	struct bdk_ocx_com_dual_sort_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t sort                        : 2;  /**< R/W - Sorting procedure for multiple links to same node:
                                                                 0x0 = All to lowest link number.
                                                                 0x1 = Split by top/bottom L2C buses. (top to lowest link number).
                                                                 0x2 = IOC 1st, IOR 2nd, Mem VCs to either based on most room in TX FIFOs.
                                                                 0x3 = Illegal. */
#else
		uint64_t sort                        : 2;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ocx_com_dual_sort_s     cn88xx; */
	/* struct bdk_ocx_com_dual_sort_s     cn88xxp1; */
} bdk_ocx_com_dual_sort_t;

#define BDK_OCX_COM_DUAL_SORT BDK_OCX_COM_DUAL_SORT_FUNC()
static inline uint64_t BDK_OCX_COM_DUAL_SORT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_DUAL_SORT_FUNC(void)
{
	return 0x000087E011000008ull;
}
#define typedef_BDK_OCX_COM_DUAL_SORT bdk_ocx_com_dual_sort_t
#define bustype_BDK_OCX_COM_DUAL_SORT BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_DUAL_SORT 0
#define arguments_BDK_OCX_COM_DUAL_SORT -1,-1,-1,-1
#define basename_BDK_OCX_COM_DUAL_SORT "OCX_COM_DUAL_SORT"


/**
 * RSL - ocx_com_int
 */
typedef union bdk_ocx_com_int {
	uint64_t u;
	struct bdk_ocx_com_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t io_badid                    : 1;  /**< R/W1C/H - I/O request or response cannot be sent because a link was not found with a packet node ID
                                                                 matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t mem_badid                   : 1;  /**< R/W1C/H - Memory request or response cannot be sent because a link was not found with a packet node
                                                                 ID matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t copr_badid                  : 1;  /**< R/W1C/H - Scheduler add work or buffer pool return cannot be sent because a link was not found with
                                                                 a node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID] with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has
                                                                 been dropped. */
		uint64_t win_req_badid               : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 cannot be sent because a link was not found with a request node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has been dropped. */
		uint64_t win_req_tout                : 1;  /**< R/W1C/H - Window or core request was dropped because it could not be send during the period
                                                                 specified by OCX_WIN_TIMER. */
		uint64_t win_req_xmit                : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 has been scheduled for transmission. If the command was not expecting a response, then a
                                                                 new command may be issued. */
		uint64_t win_rsp                     : 1;  /**< R/W1C/H - A response to a previous window request or core request has been received. A new command
                                                                 may be issued. */
		uint64_t reserved_24_47              : 24;
		uint64_t rx_lane                     : 24; /**< R/W1C/H - SerDes RX lane interrupt. See OCX_LNE(0..23)_INT for more information. */
#else
		uint64_t rx_lane                     : 24;
		uint64_t reserved_24_47              : 24;
		uint64_t win_rsp                     : 1;
		uint64_t win_req_xmit                : 1;
		uint64_t win_req_tout                : 1;
		uint64_t win_req_badid               : 1;
		uint64_t copr_badid                  : 1;
		uint64_t mem_badid                   : 1;
		uint64_t io_badid                    : 1;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_ocx_com_int_s           cn88xx; */
	/* struct bdk_ocx_com_int_s           cn88xxp1; */
} bdk_ocx_com_int_t;

#define BDK_OCX_COM_INT BDK_OCX_COM_INT_FUNC()
static inline uint64_t BDK_OCX_COM_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_INT_FUNC(void)
{
	return 0x000087E011000100ull;
}
#define typedef_BDK_OCX_COM_INT bdk_ocx_com_int_t
#define bustype_BDK_OCX_COM_INT BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_INT 0
#define arguments_BDK_OCX_COM_INT -1,-1,-1,-1
#define basename_BDK_OCX_COM_INT "OCX_COM_INT"


/**
 * RSL - ocx_com_int_ena_w1c
 */
typedef union bdk_ocx_com_int_ena_w1c {
	uint64_t u;
	struct bdk_ocx_com_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t io_badid                    : 1;  /**< R/W1C/H - I/O request or response cannot be sent because a link was not found with a packet node ID
                                                                 matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t mem_badid                   : 1;  /**< R/W1C/H - Memory request or response cannot be sent because a link was not found with a packet node
                                                                 ID matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t copr_badid                  : 1;  /**< R/W1C/H - Scheduler add work or buffer pool return cannot be sent because a link was not found with
                                                                 a node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID] with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has
                                                                 been dropped. */
		uint64_t win_req_badid               : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 cannot be sent because a link was not found with a request node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has been dropped. */
		uint64_t win_req_tout                : 1;  /**< R/W1C/H - Window or core request was dropped because it could not be send during the period
                                                                 specified by OCX_WIN_TIMER. */
		uint64_t win_req_xmit                : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 has been scheduled for transmission. If the command was not expecting a response, then a
                                                                 new command may be issued. */
		uint64_t win_rsp                     : 1;  /**< R/W1C/H - A response to a previous window request or core request has been received. A new command
                                                                 may be issued. */
		uint64_t reserved_24_47              : 24;
		uint64_t rx_lane                     : 24; /**< R/W1C/H - SerDes RX lane interrupt. See OCX_LNE(0..23)_INT for more information. */
#else
		uint64_t rx_lane                     : 24;
		uint64_t reserved_24_47              : 24;
		uint64_t win_rsp                     : 1;
		uint64_t win_req_xmit                : 1;
		uint64_t win_req_tout                : 1;
		uint64_t win_req_badid               : 1;
		uint64_t copr_badid                  : 1;
		uint64_t mem_badid                   : 1;
		uint64_t io_badid                    : 1;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_ocx_com_int_ena_w1c_s   cn88xx; */
	/* struct bdk_ocx_com_int_ena_w1c_s   cn88xxp1; */
} bdk_ocx_com_int_ena_w1c_t;

#define BDK_OCX_COM_INT_ENA_W1C BDK_OCX_COM_INT_ENA_W1C_FUNC()
static inline uint64_t BDK_OCX_COM_INT_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_INT_ENA_W1C_FUNC(void)
{
	return 0x000087E011000118ull;
}
#define typedef_BDK_OCX_COM_INT_ENA_W1C bdk_ocx_com_int_ena_w1c_t
#define bustype_BDK_OCX_COM_INT_ENA_W1C BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_INT_ENA_W1C 0
#define arguments_BDK_OCX_COM_INT_ENA_W1C -1,-1,-1,-1
#define basename_BDK_OCX_COM_INT_ENA_W1C "OCX_COM_INT_ENA_W1C"


/**
 * RSL - ocx_com_int_ena_w1s
 */
typedef union bdk_ocx_com_int_ena_w1s {
	uint64_t u;
	struct bdk_ocx_com_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t io_badid                    : 1;  /**< R/W1C/H - I/O request or response cannot be sent because a link was not found with a packet node ID
                                                                 matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t mem_badid                   : 1;  /**< R/W1C/H - Memory request or response cannot be sent because a link was not found with a packet node
                                                                 ID matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t copr_badid                  : 1;  /**< R/W1C/H - Scheduler add work or buffer pool return cannot be sent because a link was not found with
                                                                 a node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID] with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has
                                                                 been dropped. */
		uint64_t win_req_badid               : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 cannot be sent because a link was not found with a request node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has been dropped. */
		uint64_t win_req_tout                : 1;  /**< R/W1C/H - Window or core request was dropped because it could not be send during the period
                                                                 specified by OCX_WIN_TIMER. */
		uint64_t win_req_xmit                : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 has been scheduled for transmission. If the command was not expecting a response, then a
                                                                 new command may be issued. */
		uint64_t win_rsp                     : 1;  /**< R/W1C/H - A response to a previous window request or core request has been received. A new command
                                                                 may be issued. */
		uint64_t reserved_24_47              : 24;
		uint64_t rx_lane                     : 24; /**< R/W1C/H - SerDes RX lane interrupt. See OCX_LNE(0..23)_INT for more information. */
#else
		uint64_t rx_lane                     : 24;
		uint64_t reserved_24_47              : 24;
		uint64_t win_rsp                     : 1;
		uint64_t win_req_xmit                : 1;
		uint64_t win_req_tout                : 1;
		uint64_t win_req_badid               : 1;
		uint64_t copr_badid                  : 1;
		uint64_t mem_badid                   : 1;
		uint64_t io_badid                    : 1;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_ocx_com_int_ena_w1s_s   cn88xx; */
	/* struct bdk_ocx_com_int_ena_w1s_s   cn88xxp1; */
} bdk_ocx_com_int_ena_w1s_t;

#define BDK_OCX_COM_INT_ENA_W1S BDK_OCX_COM_INT_ENA_W1S_FUNC()
static inline uint64_t BDK_OCX_COM_INT_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_INT_ENA_W1S_FUNC(void)
{
	return 0x000087E011000110ull;
}
#define typedef_BDK_OCX_COM_INT_ENA_W1S bdk_ocx_com_int_ena_w1s_t
#define bustype_BDK_OCX_COM_INT_ENA_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_INT_ENA_W1S 0
#define arguments_BDK_OCX_COM_INT_ENA_W1S -1,-1,-1,-1
#define basename_BDK_OCX_COM_INT_ENA_W1S "OCX_COM_INT_ENA_W1S"


/**
 * RSL - ocx_com_int_w1s
 */
typedef union bdk_ocx_com_int_w1s {
	uint64_t u;
	struct bdk_ocx_com_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_55_63              : 9;
		uint64_t io_badid                    : 1;  /**< R/W1C/H - I/O request or response cannot be sent because a link was not found with a packet node ID
                                                                 matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t mem_badid                   : 1;  /**< R/W1C/H - Memory request or response cannot be sent because a link was not found with a packet node
                                                                 ID matching the OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set. Transaction has been dropped. */
		uint64_t copr_badid                  : 1;  /**< R/W1C/H - Scheduler add work or buffer pool return cannot be sent because a link was not found with
                                                                 a node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID] with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has
                                                                 been dropped. */
		uint64_t win_req_badid               : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 cannot be sent because a link was not found with a request node ID matching the
                                                                 OCX_COM_LINK(0..2)_CTL[ID]
                                                                 with OCX_COM_LINK(0..2)_CTL[VALID] bit set.  Transaction has been dropped. */
		uint64_t win_req_tout                : 1;  /**< R/W1C/H - Window or core request was dropped because it could not be send during the period
                                                                 specified by OCX_WIN_TIMER. */
		uint64_t win_req_xmit                : 1;  /**< R/W1C/H - Window request specified in SLI_WIN_RD_ADDR, SLI_WIN_WR_ADDR, OCX_WIN_CMD or OCX_PP_CMD
                                                                 has been scheduled for transmission. If the command was not expecting a response, then a
                                                                 new command may be issued. */
		uint64_t win_rsp                     : 1;  /**< R/W1C/H - A response to a previous window request or core request has been received. A new command
                                                                 may be issued. */
		uint64_t reserved_24_47              : 24;
		uint64_t rx_lane                     : 24; /**< R/W1C/H - SerDes RX lane interrupt. See OCX_LNE(0..23)_INT for more information. */
#else
		uint64_t rx_lane                     : 24;
		uint64_t reserved_24_47              : 24;
		uint64_t win_rsp                     : 1;
		uint64_t win_req_xmit                : 1;
		uint64_t win_req_tout                : 1;
		uint64_t win_req_badid               : 1;
		uint64_t copr_badid                  : 1;
		uint64_t mem_badid                   : 1;
		uint64_t io_badid                    : 1;
		uint64_t reserved_55_63              : 9;
#endif
	} s;
	/* struct bdk_ocx_com_int_w1s_s       cn88xx; */
	/* struct bdk_ocx_com_int_w1s_s       cn88xxp1; */
} bdk_ocx_com_int_w1s_t;

#define BDK_OCX_COM_INT_W1S BDK_OCX_COM_INT_W1S_FUNC()
static inline uint64_t BDK_OCX_COM_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_INT_W1S_FUNC(void)
{
	return 0x000087E011000108ull;
}
#define typedef_BDK_OCX_COM_INT_W1S bdk_ocx_com_int_w1s_t
#define bustype_BDK_OCX_COM_INT_W1S BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_INT_W1S 0
#define arguments_BDK_OCX_COM_INT_W1S -1,-1,-1,-1
#define basename_BDK_OCX_COM_INT_W1S "OCX_COM_INT_W1S"


/**
 * RSL - ocx_com_link#_ctl
 *
 * This register controls link operations.  In addition, the combination of some of
 * these conditions are used to generate the link_down status used by the L2C_OCI_CTL[SHTOEN] and
 * as a reset condition controlled by RST_OCX[RST_LINK].  This link_down status is true when one
 * of the following occurs:
 *
 * * Link is not initialized (See description of UP bit).
 * * Retry Counter expired (See OCX_COM_LINK_TIMER and OCX_COM_LINK(0..2)_INT[STOP].
 * * Receive REINIT request from Link Partner (See description of REINIT bit).
 * * Detected Uncorrectable ECC error while reading the Transmit FIFOs (See
 * OCX_COM_LINK(0..2)_INT[TXFIFO_DBE]).
 * * Detected Uncorrectable ECC error while reading the Replay Buffer (See
 * OCX_COM_LINK(0..2)_INT[REPLAY_DBE]).
 */
typedef union bdk_ocx_com_linkx_ctl {
	uint64_t u;
	struct bdk_ocx_com_linkx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t cclk_dis                    : 1;  /**< R/W - Reserved.  INTERNAL:  Disable conditional clocking.  Set to force link clocks on
                                                                 unconditionally. */
		uint64_t loopback                    : 1;  /**< R/W - Reserved. INTERNAL: Diagnostic data loopback. Set to force outgoing link to inbound port.
                                                                 All data and link credits are returned and appear to come from link partner. Typically
                                                                 SerDes should be disabled during this operation. */
		uint64_t reinit                      : 1;  /**< R/W - Reinitialize link. Setting this bit forces link back into init state and sets the DROP
                                                                 bit.
                                                                 Setting the bit also causes the link to transmit a REINIT request to the link partner.
                                                                 This bit must be cleared for link to operate normally. */
		uint64_t reserved_6_6                : 1;
		uint64_t auto_clr                    : 1;  /**< R/W - Automatically clear DROP bit if link partner has cleared other side. Typically disabled if
                                                                 software wishes to manage deassertion of DROP. */
		uint64_t drop                        : 1;  /**< R/W/H - Drop all requests on given link. Typically set by hardware when link has failed or been
                                                                 reinitialized. Cleared by software once pending link traffic is removed. (See
                                                                 OCX_TLK(0..2)_FIFO(0..13)_CNT.) */
		uint64_t up                          : 1;  /**< RO/H - Link is operating normally and exchanging control information. */
		uint64_t valid                       : 1;  /**< RO/H - Link has valid lanes and is exchanging information. This bit will never be set if
                                                                 OCX_LNK(0..2)_CFG[QLM_SELECT] is zero. */
		uint64_t id                          : 2;  /**< R/W - This ID is used to sort traffic by link. If more than one link has the same value, the
                                                                 OCX_COM_DUAL_SORT[SORT] field and traffic VC are used to choose a link. This field is only
                                                                 reset during a cold reset to an arbitrary value to avoid conflicts with the
                                                                 OCX_COM_NODE[ID] field and should be configured by software before memory traffic is
                                                                 generated. */
#else
		uint64_t id                          : 2;
		uint64_t valid                       : 1;
		uint64_t up                          : 1;
		uint64_t drop                        : 1;
		uint64_t auto_clr                    : 1;
		uint64_t reserved_6_6                : 1;
		uint64_t reinit                      : 1;
		uint64_t loopback                    : 1;
		uint64_t cclk_dis                    : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_ocx_com_linkx_ctl_s     cn88xx; */
	/* struct bdk_ocx_com_linkx_ctl_s     cn88xxp1; */
} bdk_ocx_com_linkx_ctl_t;

static inline uint64_t BDK_OCX_COM_LINKX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINKX_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011000020ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_COM_LINKX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_COM_LINKX_CTL(...) bdk_ocx_com_linkx_ctl_t
#define bustype_BDK_OCX_COM_LINKX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINKX_CTL(p1) (p1)
#define arguments_BDK_OCX_COM_LINKX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_COM_LINKX_CTL(...) "OCX_COM_LINKX_CTL"


/**
 * RSL - ocx_com_link#_int
 */
typedef union bdk_ocx_com_linkx_int {
	uint64_t u;
	struct bdk_ocx_com_linkx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t bad_word                    : 1;  /**< R/W1C/H - Illegal word decoded on at least one lane of link. */
		uint64_t align_fail                  : 1;  /**< R/W1C/H - Link lanes failed to align. */
		uint64_t align_done                  : 1;  /**< R/W1C/H - Link lane alignment is complete. */
		uint64_t up                          : 1;  /**< R/W1C/H - Link initialization is complete and is ready to pass traffic.  Note:  This state occurs
                                                                 some time after the link starts exchanging information as indicated in
                                                                 OCX_COM_LINK(0..2)_CTL[UP]. */
		uint64_t stop                        : 1;  /**< R/W1C/H - Link has stopped operating. Link retry count has reached threshold specified in
                                                                 OCX_COM_LINK_TIMER; outgoing traffic has been dropped and an initialization request has
                                                                 been reissued. */
		uint64_t blk_err                     : 1;  /**< R/W1C/H - Link block error count has reached threshold specified in OCX_RLK(0..2)_BLK_ERR[LIMIT]. */
		uint64_t reinit                      : 1;  /**< R/W1C/H - Link has received a initialization request from link partner after link has been established. */
		uint64_t lnk_data                    : 1;  /**< R/W1C/H - Set by hardware when a link data block is received in OCX_RLK(0..2)_LNK_DATA. It
                                                                 software's responsibility to clear the bit after reading the data. */
		uint64_t rxfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in FIFO RAMs. */
		uint64_t rxfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in FIFO RAMs. */
		uint64_t txfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in TX FIFO RAMs. */
		uint64_t txfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in TX FIFO RAMs. */
		uint64_t replay_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in REPLAY BUFFER RAMs. */
		uint64_t replay_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in REPLAY BUFFER RAMs. */
#else
		uint64_t replay_sbe                  : 1;
		uint64_t replay_dbe                  : 1;
		uint64_t txfifo_sbe                  : 1;
		uint64_t txfifo_dbe                  : 1;
		uint64_t rxfifo_sbe                  : 1;
		uint64_t rxfifo_dbe                  : 1;
		uint64_t lnk_data                    : 1;
		uint64_t reinit                      : 1;
		uint64_t blk_err                     : 1;
		uint64_t stop                        : 1;
		uint64_t up                          : 1;
		uint64_t align_done                  : 1;
		uint64_t align_fail                  : 1;
		uint64_t bad_word                    : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_ocx_com_linkx_int_s     cn88xx; */
	/* struct bdk_ocx_com_linkx_int_s     cn88xxp1; */
} bdk_ocx_com_linkx_int_t;

static inline uint64_t BDK_OCX_COM_LINKX_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINKX_INT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011000120ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_COM_LINKX_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_COM_LINKX_INT(...) bdk_ocx_com_linkx_int_t
#define bustype_BDK_OCX_COM_LINKX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINKX_INT(p1) (p1)
#define arguments_BDK_OCX_COM_LINKX_INT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_COM_LINKX_INT(...) "OCX_COM_LINKX_INT"


/**
 * RSL - ocx_com_link#_int_ena_w1c
 */
typedef union bdk_ocx_com_linkx_int_ena_w1c {
	uint64_t u;
	struct bdk_ocx_com_linkx_int_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t bad_word                    : 1;  /**< R/W1C/H - Illegal word decoded on at least one lane of link. */
		uint64_t align_fail                  : 1;  /**< R/W1C/H - Link lanes failed to align. */
		uint64_t align_done                  : 1;  /**< R/W1C/H - Link lane alignment is complete. */
		uint64_t up                          : 1;  /**< R/W1C/H - Link initialization is complete and is ready to pass traffic.  Note:  This state occurs
                                                                 some time after the link starts exchanging information as indicated in
                                                                 OCX_COM_LINK(0..2)_CTL[UP]. */
		uint64_t stop                        : 1;  /**< R/W1C/H - Link has stopped operating. Link retry count has reached threshold specified in
                                                                 OCX_COM_LINK_TIMER; outgoing traffic has been dropped and an initialization request has
                                                                 been reissued. */
		uint64_t blk_err                     : 1;  /**< R/W1C/H - Link block error count has reached threshold specified in OCX_RLK(0..2)_BLK_ERR[LIMIT]. */
		uint64_t reinit                      : 1;  /**< R/W1C/H - Link has received a initialization request from link partner after link has been established. */
		uint64_t lnk_data                    : 1;  /**< R/W1C/H - Set by hardware when a link data block is received in OCX_RLK(0..2)_LNK_DATA. It
                                                                 software's responsibility to clear the bit after reading the data. */
		uint64_t rxfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in FIFO RAMs. */
		uint64_t rxfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in FIFO RAMs. */
		uint64_t txfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in TX FIFO RAMs. */
		uint64_t txfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in TX FIFO RAMs. */
		uint64_t replay_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in REPLAY BUFFER RAMs. */
		uint64_t replay_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in REPLAY BUFFER RAMs. */
#else
		uint64_t replay_sbe                  : 1;
		uint64_t replay_dbe                  : 1;
		uint64_t txfifo_sbe                  : 1;
		uint64_t txfifo_dbe                  : 1;
		uint64_t rxfifo_sbe                  : 1;
		uint64_t rxfifo_dbe                  : 1;
		uint64_t lnk_data                    : 1;
		uint64_t reinit                      : 1;
		uint64_t blk_err                     : 1;
		uint64_t stop                        : 1;
		uint64_t up                          : 1;
		uint64_t align_done                  : 1;
		uint64_t align_fail                  : 1;
		uint64_t bad_word                    : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_ocx_com_linkx_int_ena_w1c_s cn88xx; */
	/* struct bdk_ocx_com_linkx_int_ena_w1c_s cn88xxp1; */
} bdk_ocx_com_linkx_int_ena_w1c_t;

static inline uint64_t BDK_OCX_COM_LINKX_INT_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINKX_INT_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011000180ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_COM_LINKX_INT_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_COM_LINKX_INT_ENA_W1C(...) bdk_ocx_com_linkx_int_ena_w1c_t
#define bustype_BDK_OCX_COM_LINKX_INT_ENA_W1C(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINKX_INT_ENA_W1C(p1) (p1)
#define arguments_BDK_OCX_COM_LINKX_INT_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_COM_LINKX_INT_ENA_W1C(...) "OCX_COM_LINKX_INT_ENA_W1C"


/**
 * RSL - ocx_com_link#_int_ena_w1s
 */
typedef union bdk_ocx_com_linkx_int_ena_w1s {
	uint64_t u;
	struct bdk_ocx_com_linkx_int_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t bad_word                    : 1;  /**< R/W1C/H - Illegal word decoded on at least one lane of link. */
		uint64_t align_fail                  : 1;  /**< R/W1C/H - Link lanes failed to align. */
		uint64_t align_done                  : 1;  /**< R/W1C/H - Link lane alignment is complete. */
		uint64_t up                          : 1;  /**< R/W1C/H - Link initialization is complete and is ready to pass traffic.  Note:  This state occurs
                                                                 some time after the link starts exchanging information as indicated in
                                                                 OCX_COM_LINK(0..2)_CTL[UP]. */
		uint64_t stop                        : 1;  /**< R/W1C/H - Link has stopped operating. Link retry count has reached threshold specified in
                                                                 OCX_COM_LINK_TIMER; outgoing traffic has been dropped and an initialization request has
                                                                 been reissued. */
		uint64_t blk_err                     : 1;  /**< R/W1C/H - Link block error count has reached threshold specified in OCX_RLK(0..2)_BLK_ERR[LIMIT]. */
		uint64_t reinit                      : 1;  /**< R/W1C/H - Link has received a initialization request from link partner after link has been established. */
		uint64_t lnk_data                    : 1;  /**< R/W1C/H - Set by hardware when a link data block is received in OCX_RLK(0..2)_LNK_DATA. It
                                                                 software's responsibility to clear the bit after reading the data. */
		uint64_t rxfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in FIFO RAMs. */
		uint64_t rxfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in FIFO RAMs. */
		uint64_t txfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in TX FIFO RAMs. */
		uint64_t txfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in TX FIFO RAMs. */
		uint64_t replay_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in REPLAY BUFFER RAMs. */
		uint64_t replay_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in REPLAY BUFFER RAMs. */
#else
		uint64_t replay_sbe                  : 1;
		uint64_t replay_dbe                  : 1;
		uint64_t txfifo_sbe                  : 1;
		uint64_t txfifo_dbe                  : 1;
		uint64_t rxfifo_sbe                  : 1;
		uint64_t rxfifo_dbe                  : 1;
		uint64_t lnk_data                    : 1;
		uint64_t reinit                      : 1;
		uint64_t blk_err                     : 1;
		uint64_t stop                        : 1;
		uint64_t up                          : 1;
		uint64_t align_done                  : 1;
		uint64_t align_fail                  : 1;
		uint64_t bad_word                    : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_ocx_com_linkx_int_ena_w1s_s cn88xx; */
	/* struct bdk_ocx_com_linkx_int_ena_w1s_s cn88xxp1; */
} bdk_ocx_com_linkx_int_ena_w1s_t;

static inline uint64_t BDK_OCX_COM_LINKX_INT_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINKX_INT_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011000160ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_COM_LINKX_INT_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_COM_LINKX_INT_ENA_W1S(...) bdk_ocx_com_linkx_int_ena_w1s_t
#define bustype_BDK_OCX_COM_LINKX_INT_ENA_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINKX_INT_ENA_W1S(p1) (p1)
#define arguments_BDK_OCX_COM_LINKX_INT_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_COM_LINKX_INT_ENA_W1S(...) "OCX_COM_LINKX_INT_ENA_W1S"


/**
 * RSL - ocx_com_link#_int_w1s
 */
typedef union bdk_ocx_com_linkx_int_w1s {
	uint64_t u;
	struct bdk_ocx_com_linkx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t bad_word                    : 1;  /**< R/W1C/H - Illegal word decoded on at least one lane of link. */
		uint64_t align_fail                  : 1;  /**< R/W1C/H - Link lanes failed to align. */
		uint64_t align_done                  : 1;  /**< R/W1C/H - Link lane alignment is complete. */
		uint64_t up                          : 1;  /**< R/W1C/H - Link initialization is complete and is ready to pass traffic.  Note:  This state occurs
                                                                 some time after the link starts exchanging information as indicated in
                                                                 OCX_COM_LINK(0..2)_CTL[UP]. */
		uint64_t stop                        : 1;  /**< R/W1C/H - Link has stopped operating. Link retry count has reached threshold specified in
                                                                 OCX_COM_LINK_TIMER; outgoing traffic has been dropped and an initialization request has
                                                                 been reissued. */
		uint64_t blk_err                     : 1;  /**< R/W1C/H - Link block error count has reached threshold specified in OCX_RLK(0..2)_BLK_ERR[LIMIT]. */
		uint64_t reinit                      : 1;  /**< R/W1C/H - Link has received a initialization request from link partner after link has been established. */
		uint64_t lnk_data                    : 1;  /**< R/W1C/H - Set by hardware when a link data block is received in OCX_RLK(0..2)_LNK_DATA. It
                                                                 software's responsibility to clear the bit after reading the data. */
		uint64_t rxfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in FIFO RAMs. */
		uint64_t rxfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in FIFO RAMs. */
		uint64_t txfifo_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in TX FIFO RAMs. */
		uint64_t txfifo_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in TX FIFO RAMs. */
		uint64_t replay_dbe                  : 1;  /**< R/W1C/H - Double-bit error detected in REPLAY BUFFER RAMs. */
		uint64_t replay_sbe                  : 1;  /**< R/W1C/H - Single-bit error detected/corrected in REPLAY BUFFER RAMs. */
#else
		uint64_t replay_sbe                  : 1;
		uint64_t replay_dbe                  : 1;
		uint64_t txfifo_sbe                  : 1;
		uint64_t txfifo_dbe                  : 1;
		uint64_t rxfifo_sbe                  : 1;
		uint64_t rxfifo_dbe                  : 1;
		uint64_t lnk_data                    : 1;
		uint64_t reinit                      : 1;
		uint64_t blk_err                     : 1;
		uint64_t stop                        : 1;
		uint64_t up                          : 1;
		uint64_t align_done                  : 1;
		uint64_t align_fail                  : 1;
		uint64_t bad_word                    : 1;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_ocx_com_linkx_int_w1s_s cn88xx; */
	/* struct bdk_ocx_com_linkx_int_w1s_s cn88xxp1; */
} bdk_ocx_com_linkx_int_w1s_t;

static inline uint64_t BDK_OCX_COM_LINKX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINKX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011000140ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_COM_LINKX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_COM_LINKX_INT_W1S(...) bdk_ocx_com_linkx_int_w1s_t
#define bustype_BDK_OCX_COM_LINKX_INT_W1S(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINKX_INT_W1S(p1) (p1)
#define arguments_BDK_OCX_COM_LINKX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_COM_LINKX_INT_W1S(...) "OCX_COM_LINKX_INT_W1S"


/**
 * RSL - ocx_com_link_timer
 */
typedef union bdk_ocx_com_link_timer {
	uint64_t u;
	struct bdk_ocx_com_link_timer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t tout                        : 24; /**< R/W - Number of unacknowledged retry requests issued before link stops operation and
                                                                 OCX_COM_LINK(0..2)_INT[STOP] is asserted. */
#else
		uint64_t tout                        : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_ocx_com_link_timer_s    cn88xx; */
	/* struct bdk_ocx_com_link_timer_s    cn88xxp1; */
} bdk_ocx_com_link_timer_t;

#define BDK_OCX_COM_LINK_TIMER BDK_OCX_COM_LINK_TIMER_FUNC()
static inline uint64_t BDK_OCX_COM_LINK_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_LINK_TIMER_FUNC(void)
{
	return 0x000087E011000010ull;
}
#define typedef_BDK_OCX_COM_LINK_TIMER bdk_ocx_com_link_timer_t
#define bustype_BDK_OCX_COM_LINK_TIMER BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_LINK_TIMER 0
#define arguments_BDK_OCX_COM_LINK_TIMER -1,-1,-1,-1
#define basename_BDK_OCX_COM_LINK_TIMER "OCX_COM_LINK_TIMER"


/**
 * RSL - ocx_com_node
 */
typedef union bdk_ocx_com_node {
	uint64_t u;
	struct bdk_ocx_com_node_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t fixed_pin                   : 1;  /**< RO/H - The current value of the OCI_FIXED_NODE pin. */
		uint64_t fixed                       : 1;  /**< R/W - ID Valid associated with the chip. This register is used by the link initialization
                                                                 software to help assign IDs and is transmitted over CCPI. The FIXED field set during a
                                                                 cold
                                                                 reset to the value of the OCI_FIXED_NODE pin. The value is also readable in the
                                                                 OCX_LNE(0..23)_STS_MSG[TX_META_DAT\<2\>] for each lane. The FIXED field of the link partner
                                                                 can be examined by locally reading the OCX_LNE(0..23)_STS_MSG[RX_META_DAT\<2\>] on each
                                                                 valid lane or remotely reading the OCX_COM_NODE[FIXED] on the link partner. */
		uint64_t id                          : 2;  /**< R/W - Node ID associated with the chip. This register is used by the rest of the chip to
                                                                 determine what traffic is transmitted over CCPI. The value should not match the
                                                                 OCX_COM_LINK(0..2)_CTL[ID] of any active link. The ID field is set during a cold reset to
                                                                 the value of the OCI_NODE_ID pins. The value is also readable in the
                                                                 OCX_LNE(0..23)_STS_MSG[TX_META_DAT\<1:0\>] for each lane. The ID field of the link partner
                                                                 can be examined by locally reading the OCX_LNE(0..23)_STS_MSG[RX_META_DAT\<1:0\>] on each
                                                                 valid lane or remotely reading the OCX_COM_NODE[ID] on the link partner. */
#else
		uint64_t id                          : 2;
		uint64_t fixed                       : 1;
		uint64_t fixed_pin                   : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_ocx_com_node_s          cn88xx; */
	/* struct bdk_ocx_com_node_s          cn88xxp1; */
} bdk_ocx_com_node_t;

#define BDK_OCX_COM_NODE BDK_OCX_COM_NODE_FUNC()
static inline uint64_t BDK_OCX_COM_NODE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_COM_NODE_FUNC(void)
{
	return 0x000087E011000000ull;
}
#define typedef_BDK_OCX_COM_NODE bdk_ocx_com_node_t
#define bustype_BDK_OCX_COM_NODE BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_COM_NODE 0
#define arguments_BDK_OCX_COM_NODE -1,-1,-1,-1
#define basename_BDK_OCX_COM_NODE "OCX_COM_NODE"


/**
 * RSL - ocx_dll#_status
 *
 * These registers provides the parameters for DLL observability.  Index 0 is the northeast DLL,
 * index 1 the southeast DLL.
 */
typedef union bdk_ocx_dllx_status {
	uint64_t u;
	struct bdk_ocx_dllx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_60_63              : 4;
		uint64_t max_dll_setting             : 12; /**< RO/H - Max reported DLL setting. */
		uint64_t min_dll_setting             : 12; /**< RO/H - Min reported DLL setting. */
		uint64_t pd_pos_rclk_refclk          : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdl_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t pdr_rclk_refclk             : 1;  /**< RO/H - Phase detector output. */
		uint64_t reserved_32_32              : 1;
		uint64_t dly_elem_enable             : 16; /**< RO/H - Delay element enable. */
		uint64_t dll_setting                 : 12; /**< RO/H - DLL setting. */
		uint64_t reserved_1_3                : 3;
		uint64_t dll_lock                    : 1;  /**< RO/H - DLL lock: 1 = locked, 0 = unlocked. */
#else
		uint64_t dll_lock                    : 1;
		uint64_t reserved_1_3                : 3;
		uint64_t dll_setting                 : 12;
		uint64_t dly_elem_enable             : 16;
		uint64_t reserved_32_32              : 1;
		uint64_t pdr_rclk_refclk             : 1;
		uint64_t pdl_rclk_refclk             : 1;
		uint64_t pd_pos_rclk_refclk          : 1;
		uint64_t min_dll_setting             : 12;
		uint64_t max_dll_setting             : 12;
		uint64_t reserved_60_63              : 4;
#endif
	} s;
	/* struct bdk_ocx_dllx_status_s       cn88xx; */
	/* struct bdk_ocx_dllx_status_s       cn88xxp1; */
} bdk_ocx_dllx_status_t;

static inline uint64_t BDK_OCX_DLLX_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_DLLX_STATUS(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x000087E011000080ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_OCX_DLLX_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_DLLX_STATUS(...) bdk_ocx_dllx_status_t
#define bustype_BDK_OCX_DLLX_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_DLLX_STATUS(p1) (p1)
#define arguments_BDK_OCX_DLLX_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_DLLX_STATUS(...) "OCX_DLLX_STATUS"


/**
 * RSL - ocx_frc#_stat0
 */
typedef union bdk_ocx_frcx_stat0 {
	uint64_t u;
	struct bdk_ocx_frcx_stat0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t align_cnt                   : 21; /**< R/W/H - Indicates the number of alignment sequences received (i.e. those that do not violate the
                                                                 current alignment). */
#else
		uint64_t align_cnt                   : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_ocx_frcx_stat0_s        cn88xx; */
	/* struct bdk_ocx_frcx_stat0_s        cn88xxp1; */
} bdk_ocx_frcx_stat0_t;

static inline uint64_t BDK_OCX_FRCX_STAT0(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_FRCX_STAT0(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E01100FA00ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_FRCX_STAT0", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_FRCX_STAT0(...) bdk_ocx_frcx_stat0_t
#define bustype_BDK_OCX_FRCX_STAT0(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_FRCX_STAT0(p1) (p1)
#define arguments_BDK_OCX_FRCX_STAT0(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_FRCX_STAT0(...) "OCX_FRCX_STAT0"


/**
 * RSL - ocx_frc#_stat1
 */
typedef union bdk_ocx_frcx_stat1 {
	uint64_t u;
	struct bdk_ocx_frcx_stat1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t align_err_cnt               : 21; /**< R/W/H - Indicates the number of alignment sequences received in error (i.e. those that violate the
                                                                 current alignment). */
#else
		uint64_t align_err_cnt               : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_ocx_frcx_stat1_s        cn88xx; */
	/* struct bdk_ocx_frcx_stat1_s        cn88xxp1; */
} bdk_ocx_frcx_stat1_t;

static inline uint64_t BDK_OCX_FRCX_STAT1(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_FRCX_STAT1(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E01100FA80ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_FRCX_STAT1", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_FRCX_STAT1(...) bdk_ocx_frcx_stat1_t
#define bustype_BDK_OCX_FRCX_STAT1(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_FRCX_STAT1(p1) (p1)
#define arguments_BDK_OCX_FRCX_STAT1(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_FRCX_STAT1(...) "OCX_FRCX_STAT1"


/**
 * RSL - ocx_frc#_stat2
 */
typedef union bdk_ocx_frcx_stat2 {
	uint64_t u;
	struct bdk_ocx_frcx_stat2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t align_done                  : 21; /**< R/W/H - Indicates the number of attempts at alignment that succeeded. */
#else
		uint64_t align_done                  : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_ocx_frcx_stat2_s        cn88xx; */
	/* struct bdk_ocx_frcx_stat2_s        cn88xxp1; */
} bdk_ocx_frcx_stat2_t;

static inline uint64_t BDK_OCX_FRCX_STAT2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_FRCX_STAT2(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E01100FB00ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_FRCX_STAT2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_FRCX_STAT2(...) bdk_ocx_frcx_stat2_t
#define bustype_BDK_OCX_FRCX_STAT2(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_FRCX_STAT2(p1) (p1)
#define arguments_BDK_OCX_FRCX_STAT2(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_FRCX_STAT2(...) "OCX_FRCX_STAT2"


/**
 * RSL - ocx_frc#_stat3
 */
typedef union bdk_ocx_frcx_stat3 {
	uint64_t u;
	struct bdk_ocx_frcx_stat3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t align_fail                  : 21; /**< R/W/H - Indicates the number of attempts at alignment that failed. */
#else
		uint64_t align_fail                  : 21;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_ocx_frcx_stat3_s        cn88xx; */
	/* struct bdk_ocx_frcx_stat3_s        cn88xxp1; */
} bdk_ocx_frcx_stat3_t;

static inline uint64_t BDK_OCX_FRCX_STAT3(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_FRCX_STAT3(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E01100FB80ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_FRCX_STAT3", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_FRCX_STAT3(...) bdk_ocx_frcx_stat3_t
#define bustype_BDK_OCX_FRCX_STAT3(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_FRCX_STAT3(p1) (p1)
#define arguments_BDK_OCX_FRCX_STAT3(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_FRCX_STAT3(...) "OCX_FRCX_STAT3"


/**
 * RSL - ocx_lne#_bad_cnt
 */
typedef union bdk_ocx_lnex_bad_cnt {
	uint64_t u;
	struct bdk_ocx_lnex_bad_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t tx_bad_crc32                : 1;  /**< R/W/H - Send 1 diagnostic word with bad CRC32 to the selected lane.
                                                                 Injects just once. */
		uint64_t tx_bad_6467_cnt             : 5;  /**< R/W/H - Send N bad 64B/67B code words on selected lane. */
		uint64_t tx_bad_sync_cnt             : 3;  /**< R/W/H - Send N bad sync words on selected lane. */
		uint64_t tx_bad_scram_cnt            : 3;  /**< R/W/H - Send N bad scram state on selected lane. */
#else
		uint64_t tx_bad_scram_cnt            : 3;
		uint64_t tx_bad_sync_cnt             : 3;
		uint64_t tx_bad_6467_cnt             : 5;
		uint64_t tx_bad_crc32                : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_ocx_lnex_bad_cnt_s      cn88xx; */
	/* struct bdk_ocx_lnex_bad_cnt_s      cn88xxp1; */
} bdk_ocx_lnex_bad_cnt_t;

static inline uint64_t BDK_OCX_LNEX_BAD_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_BAD_CNT(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008028ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_BAD_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_BAD_CNT(...) bdk_ocx_lnex_bad_cnt_t
#define bustype_BDK_OCX_LNEX_BAD_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_BAD_CNT(p1) (p1)
#define arguments_BDK_OCX_LNEX_BAD_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_BAD_CNT(...) "OCX_LNEX_BAD_CNT"


/**
 * RSL - ocx_lne#_cfg
 */
typedef union bdk_ocx_lnex_cfg {
	uint64_t u;
	struct bdk_ocx_lnex_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t rx_bdry_lock_dis            : 1;  /**< R/W - Disable word boundary lock. While disabled, received data is tossed. Once enabled,
                                                                 received data is searched for legal 2-bit patterns. */
		uint64_t reserved_3_7                : 5;
		uint64_t rx_stat_wrap_dis            : 1;  /**< R/W - Upon overflow, a statistics counter should saturate instead of wrapping. */
		uint64_t rx_stat_rdclr               : 1;  /**< R/W - CSR read to OCX_LNEx_STAT* clears the selected counter after returning its current value. */
		uint64_t rx_stat_ena                 : 1;  /**< R/W - Enable RX lane statistics counters. */
#else
		uint64_t rx_stat_ena                 : 1;
		uint64_t rx_stat_rdclr               : 1;
		uint64_t rx_stat_wrap_dis            : 1;
		uint64_t reserved_3_7                : 5;
		uint64_t rx_bdry_lock_dis            : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ocx_lnex_cfg_s          cn88xx; */
	/* struct bdk_ocx_lnex_cfg_s          cn88xxp1; */
} bdk_ocx_lnex_cfg_t;

static inline uint64_t BDK_OCX_LNEX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_CFG(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008000ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_CFG(...) bdk_ocx_lnex_cfg_t
#define bustype_BDK_OCX_LNEX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_CFG(p1) (p1)
#define arguments_BDK_OCX_LNEX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_CFG(...) "OCX_LNEX_CFG"


/**
 * RSL - ocx_lne#_int
 */
typedef union bdk_ocx_lnex_int {
	uint64_t u;
	struct bdk_ocx_lnex_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t disp_err                    : 1;  /**< R/W1C/H - RX disparity error encountered. */
		uint64_t bad_64b67b                  : 1;  /**< R/W1C/H - Bad 64B/67B codeword encountered. Once the bad word reaches the link, as denoted by
                                                                 OCX_COM_LINK(0..2)_INT[BAD_WORD], a retry handshake is initiated. */
		uint64_t stat_cnt_ovfl               : 1;  /**< R/W1C/H - RX lane statistic counter overflow. */
		uint64_t stat_msg                    : 1;  /**< R/W1C/H - Status bits for the link or a lane transitioned from a 1 (healthy) to a 0 (problem). */
		uint64_t dskew_fifo_ovfl             : 1;  /**< R/W1C/H - RX deskew FIFO overflow occurred. */
		uint64_t scrm_sync_loss              : 1;  /**< R/W1C/H - 4 consecutive bad sync words or 3 consecutive scramble state mismatches. */
		uint64_t ukwn_cntl_word              : 1;  /**< R/W1C/H - Unknown framing control word. Block type does not match any of (SYNC, SCRAM, SKIP, DIAG). */
		uint64_t crc32_err                   : 1;  /**< R/W1C/H - Diagnostic CRC32 errors. */
		uint64_t bdry_sync_loss              : 1;  /**< R/W1C/H - RX logic lost word boundary sync after 16 tries. Hardware automatically attempts to regain
                                                                 word boundary sync. */
		uint64_t serdes_lock_loss            : 1;  /**< R/W1C/H - RX SerDes loses lock. */
#else
		uint64_t serdes_lock_loss            : 1;
		uint64_t bdry_sync_loss              : 1;
		uint64_t crc32_err                   : 1;
		uint64_t ukwn_cntl_word              : 1;
		uint64_t scrm_sync_loss              : 1;
		uint64_t dskew_fifo_ovfl             : 1;
		uint64_t stat_msg                    : 1;
		uint64_t stat_cnt_ovfl               : 1;
		uint64_t bad_64b67b                  : 1;
		uint64_t disp_err                    : 1;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_ocx_lnex_int_s          cn88xx; */
	/* struct bdk_ocx_lnex_int_s          cn88xxp1; */
} bdk_ocx_lnex_int_t;

static inline uint64_t BDK_OCX_LNEX_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_INT(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008018ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_INT(...) bdk_ocx_lnex_int_t
#define bustype_BDK_OCX_LNEX_INT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_INT(p1) (p1)
#define arguments_BDK_OCX_LNEX_INT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_INT(...) "OCX_LNEX_INT"


/**
 * RSL - ocx_lne#_int_en
 */
typedef union bdk_ocx_lnex_int_en {
	uint64_t u;
	struct bdk_ocx_lnex_int_en_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_9_63               : 55;
		uint64_t bad_64b67b                  : 1;  /**< R/W - Enable bit for bad 64B/67B codeword encountered. */
		uint64_t stat_cnt_ovfl               : 1;  /**< R/W - Enable bit for RX lane statistic counter overflow. */
		uint64_t stat_msg                    : 1;  /**< R/W - Enable bit for status bits for the link or a lane transitioned from a 1 (healthy) to a 0 (problem). */
		uint64_t dskew_fifo_ovfl             : 1;  /**< R/W - Enable bit for RX deskew FIFO overflow occurred. */
		uint64_t scrm_sync_loss              : 1;  /**< R/W - Enable bit for 4 consecutive bad sync words or 3 consecutive scramble state mismatches. */
		uint64_t ukwn_cntl_word              : 1;  /**< R/W - Enable bit for unknown framing control word. Block type does not match any of (SYNC,
                                                                 SCRAM, SKIP, DIAG). */
		uint64_t crc32_err                   : 1;  /**< R/W - Enable bit for diagnostic CRC32 errors. */
		uint64_t bdry_sync_loss              : 1;  /**< R/W - Enable bit for RX logic lost word boundary sync after 16 tries. */
		uint64_t serdes_lock_loss            : 1;  /**< R/W - Enable bit for RX SerDes loses lock. */
#else
		uint64_t serdes_lock_loss            : 1;
		uint64_t bdry_sync_loss              : 1;
		uint64_t crc32_err                   : 1;
		uint64_t ukwn_cntl_word              : 1;
		uint64_t scrm_sync_loss              : 1;
		uint64_t dskew_fifo_ovfl             : 1;
		uint64_t stat_msg                    : 1;
		uint64_t stat_cnt_ovfl               : 1;
		uint64_t bad_64b67b                  : 1;
		uint64_t reserved_9_63               : 55;
#endif
	} s;
	/* struct bdk_ocx_lnex_int_en_s       cn88xx; */
	/* struct bdk_ocx_lnex_int_en_s       cn88xxp1; */
} bdk_ocx_lnex_int_en_t;

static inline uint64_t BDK_OCX_LNEX_INT_EN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_INT_EN(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008020ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_INT_EN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_INT_EN(...) bdk_ocx_lnex_int_en_t
#define bustype_BDK_OCX_LNEX_INT_EN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_INT_EN(p1) (p1)
#define arguments_BDK_OCX_LNEX_INT_EN(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_INT_EN(...) "OCX_LNEX_INT_EN"


/**
 * RSL - ocx_lne#_stat00
 */
typedef union bdk_ocx_lnex_stat00 {
	uint64_t u;
	struct bdk_ocx_lnex_stat00_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t ser_lock_loss_cnt           : 18; /**< RO/H - Number of times the lane lost clock-data-recovery. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t ser_lock_loss_cnt           : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat00_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat00_s       cn88xxp1; */
} bdk_ocx_lnex_stat00_t;

static inline uint64_t BDK_OCX_LNEX_STAT00(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT00(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008040ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT00", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT00(...) bdk_ocx_lnex_stat00_t
#define bustype_BDK_OCX_LNEX_STAT00(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT00(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT00(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT00(...) "OCX_LNEX_STAT00"


/**
 * RSL - ocx_lne#_stat01
 */
typedef union bdk_ocx_lnex_stat01 {
	uint64_t u;
	struct bdk_ocx_lnex_stat01_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t bdry_sync_loss_cnt          : 18; /**< RO/H - Number of times a lane lost word boundary synchronization. Saturates. Interrupt on
                                                                 saturation if OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t bdry_sync_loss_cnt          : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat01_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat01_s       cn88xxp1; */
} bdk_ocx_lnex_stat01_t;

static inline uint64_t BDK_OCX_LNEX_STAT01(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT01(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008048ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT01", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT01(...) bdk_ocx_lnex_stat01_t
#define bustype_BDK_OCX_LNEX_STAT01(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT01(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT01(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT01(...) "OCX_LNEX_STAT01"


/**
 * RSL - ocx_lne#_stat02
 */
typedef union bdk_ocx_lnex_stat02 {
	uint64_t u;
	struct bdk_ocx_lnex_stat02_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t syncw_bad_cnt               : 18; /**< RO/H - Number of bad synchronization words. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t syncw_bad_cnt               : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat02_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat02_s       cn88xxp1; */
} bdk_ocx_lnex_stat02_t;

static inline uint64_t BDK_OCX_LNEX_STAT02(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT02(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008050ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT02", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT02(...) bdk_ocx_lnex_stat02_t
#define bustype_BDK_OCX_LNEX_STAT02(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT02(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT02(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT02(...) "OCX_LNEX_STAT02"


/**
 * RSL - ocx_lne#_stat03
 */
typedef union bdk_ocx_lnex_stat03 {
	uint64_t u;
	struct bdk_ocx_lnex_stat03_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t syncw_good_cnt              : 18; /**< RO/H - Number of good synchronization words. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t syncw_good_cnt              : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat03_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat03_s       cn88xxp1; */
} bdk_ocx_lnex_stat03_t;

static inline uint64_t BDK_OCX_LNEX_STAT03(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT03(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008058ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT03", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT03(...) bdk_ocx_lnex_stat03_t
#define bustype_BDK_OCX_LNEX_STAT03(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT03(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT03(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT03(...) "OCX_LNEX_STAT03"


/**
 * RSL - ocx_lne#_stat04
 */
typedef union bdk_ocx_lnex_stat04 {
	uint64_t u;
	struct bdk_ocx_lnex_stat04_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t bad_64b67b_cnt              : 18; /**< RO/H - Number of bad 64B/67B words, meaning bit 65 or 64 has been corrupted. Saturates. Interrupt
                                                                 on saturation if OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t bad_64b67b_cnt              : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat04_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat04_s       cn88xxp1; */
} bdk_ocx_lnex_stat04_t;

static inline uint64_t BDK_OCX_LNEX_STAT04(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT04(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008060ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT04", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT04(...) bdk_ocx_lnex_stat04_t
#define bustype_BDK_OCX_LNEX_STAT04(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT04(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT04(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT04(...) "OCX_LNEX_STAT04"


/**
 * RSL - ocx_lne#_stat05
 */
typedef union bdk_ocx_lnex_stat05 {
	uint64_t u;
	struct bdk_ocx_lnex_stat05_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t data_word_cnt               : 27; /**< RO/H - Number of data words received. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t data_word_cnt               : 27;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat05_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat05_s       cn88xxp1; */
} bdk_ocx_lnex_stat05_t;

static inline uint64_t BDK_OCX_LNEX_STAT05(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT05(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008068ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT05", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT05(...) bdk_ocx_lnex_stat05_t
#define bustype_BDK_OCX_LNEX_STAT05(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT05(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT05(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT05(...) "OCX_LNEX_STAT05"


/**
 * RSL - ocx_lne#_stat06
 */
typedef union bdk_ocx_lnex_stat06 {
	uint64_t u;
	struct bdk_ocx_lnex_stat06_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t cntl_word_cnt               : 27; /**< RO/H - Number of control words received. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t cntl_word_cnt               : 27;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat06_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat06_s       cn88xxp1; */
} bdk_ocx_lnex_stat06_t;

static inline uint64_t BDK_OCX_LNEX_STAT06(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT06(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008070ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT06", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT06(...) bdk_ocx_lnex_stat06_t
#define bustype_BDK_OCX_LNEX_STAT06(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT06(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT06(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT06(...) "OCX_LNEX_STAT06"


/**
 * RSL - ocx_lne#_stat07
 */
typedef union bdk_ocx_lnex_stat07 {
	uint64_t u;
	struct bdk_ocx_lnex_stat07_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t unkwn_word_cnt              : 18; /**< RO/H - Number of unknown control words. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t unkwn_word_cnt              : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat07_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat07_s       cn88xxp1; */
} bdk_ocx_lnex_stat07_t;

static inline uint64_t BDK_OCX_LNEX_STAT07(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT07(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008078ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT07", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT07(...) bdk_ocx_lnex_stat07_t
#define bustype_BDK_OCX_LNEX_STAT07(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT07(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT07(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT07(...) "OCX_LNEX_STAT07"


/**
 * RSL - ocx_lne#_stat08
 */
typedef union bdk_ocx_lnex_stat08 {
	uint64_t u;
	struct bdk_ocx_lnex_stat08_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t scrm_sync_loss_cnt          : 18; /**< RO/H - Number of times scrambler synchronization was lost (due to either 4 consecutive bad sync
                                                                 words or 3 consecutive scrambler state mismatches). Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t scrm_sync_loss_cnt          : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat08_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat08_s       cn88xxp1; */
} bdk_ocx_lnex_stat08_t;

static inline uint64_t BDK_OCX_LNEX_STAT08(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT08(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008080ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT08", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT08(...) bdk_ocx_lnex_stat08_t
#define bustype_BDK_OCX_LNEX_STAT08(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT08(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT08(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT08(...) "OCX_LNEX_STAT08"


/**
 * RSL - ocx_lne#_stat09
 */
typedef union bdk_ocx_lnex_stat09 {
	uint64_t u;
	struct bdk_ocx_lnex_stat09_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t scrm_match_cnt              : 18; /**< RO/H - Number of scrambler state matches received. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t scrm_match_cnt              : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat09_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat09_s       cn88xxp1; */
} bdk_ocx_lnex_stat09_t;

static inline uint64_t BDK_OCX_LNEX_STAT09(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT09(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008088ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT09", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT09(...) bdk_ocx_lnex_stat09_t
#define bustype_BDK_OCX_LNEX_STAT09(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT09(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT09(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT09(...) "OCX_LNEX_STAT09"


/**
 * RSL - ocx_lne#_stat10
 */
typedef union bdk_ocx_lnex_stat10 {
	uint64_t u;
	struct bdk_ocx_lnex_stat10_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_18_63              : 46;
		uint64_t skipw_good_cnt              : 18; /**< RO/H - Number of good skip words. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t skipw_good_cnt              : 18;
		uint64_t reserved_18_63              : 46;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat10_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat10_s       cn88xxp1; */
} bdk_ocx_lnex_stat10_t;

static inline uint64_t BDK_OCX_LNEX_STAT10(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT10(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008090ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT10", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT10(...) bdk_ocx_lnex_stat10_t
#define bustype_BDK_OCX_LNEX_STAT10(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT10(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT10(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT10(...) "OCX_LNEX_STAT10"


/**
 * RSL - ocx_lne#_stat11
 */
typedef union bdk_ocx_lnex_stat11 {
	uint64_t u;
	struct bdk_ocx_lnex_stat11_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t crc32_err_cnt               : 27; /**< RO/H - Number of errors in the lane CRC. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t crc32_err_cnt               : 27;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat11_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat11_s       cn88xxp1; */
} bdk_ocx_lnex_stat11_t;

static inline uint64_t BDK_OCX_LNEX_STAT11(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT11(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008098ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT11", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT11(...) bdk_ocx_lnex_stat11_t
#define bustype_BDK_OCX_LNEX_STAT11(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT11(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT11(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT11(...) "OCX_LNEX_STAT11"


/**
 * RSL - ocx_lne#_stat12
 */
typedef union bdk_ocx_lnex_stat12 {
	uint64_t u;
	struct bdk_ocx_lnex_stat12_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t crc32_match_cnt             : 27; /**< RO/H - Number of CRC32 matches received. Saturates. Interrupt on saturation if
                                                                 OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t crc32_match_cnt             : 27;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat12_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat12_s       cn88xxp1; */
} bdk_ocx_lnex_stat12_t;

static inline uint64_t BDK_OCX_LNEX_STAT12(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT12(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080A0ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT12", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT12(...) bdk_ocx_lnex_stat12_t
#define bustype_BDK_OCX_LNEX_STAT12(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT12(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT12(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT12(...) "OCX_LNEX_STAT12"


/**
 * RSL - ocx_lne#_stat13
 */
typedef union bdk_ocx_lnex_stat13 {
	uint64_t u;
	struct bdk_ocx_lnex_stat13_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t trn_bad_cnt                 : 16; /**< RO/H - Number of training frames received with an invalid control channel. Saturates. Interrupt
                                                                 on saturation if OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t trn_bad_cnt                 : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat13_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat13_s       cn88xxp1; */
} bdk_ocx_lnex_stat13_t;

static inline uint64_t BDK_OCX_LNEX_STAT13(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT13(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080A8ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT13", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT13(...) bdk_ocx_lnex_stat13_t
#define bustype_BDK_OCX_LNEX_STAT13(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT13(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT13(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT13(...) "OCX_LNEX_STAT13"


/**
 * RSL - ocx_lne#_stat14
 */
typedef union bdk_ocx_lnex_stat14 {
	uint64_t u;
	struct bdk_ocx_lnex_stat14_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t trn_prbs_bad_cnt            : 16; /**< RO/H - Number of training frames received with a bad PRBS pattern. Saturates. Interrupt on
                                                                 saturation if OCX_LNE(0..23)_INT_EN[STAT_CNT_OVFL] is set. */
#else
		uint64_t trn_prbs_bad_cnt            : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_lnex_stat14_s       cn88xx; */
	/* struct bdk_ocx_lnex_stat14_s       cn88xxp1; */
} bdk_ocx_lnex_stat14_t;

static inline uint64_t BDK_OCX_LNEX_STAT14(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STAT14(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080B0ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STAT14", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STAT14(...) bdk_ocx_lnex_stat14_t
#define bustype_BDK_OCX_LNEX_STAT14(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STAT14(p1) (p1)
#define arguments_BDK_OCX_LNEX_STAT14(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STAT14(...) "OCX_LNEX_STAT14"


/**
 * RSL - ocx_lne#_status
 */
typedef union bdk_ocx_lnex_status {
	uint64_t u;
	struct bdk_ocx_lnex_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t rx_trn_val                  : 1;  /**< R/W/H - The control channel of a link training was received without any errors. */
		uint64_t rx_scrm_sync                : 1;  /**< RO/H - RX scrambler synchronization status. One when synchronization achieved. */
		uint64_t rx_bdry_sync                : 1;  /**< RO/H - RX word boundary sync status. One when synchronization achieved. */
#else
		uint64_t rx_bdry_sync                : 1;
		uint64_t rx_scrm_sync                : 1;
		uint64_t rx_trn_val                  : 1;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_ocx_lnex_status_s       cn88xx; */
	/* struct bdk_ocx_lnex_status_s       cn88xxp1; */
} bdk_ocx_lnex_status_t;

static inline uint64_t BDK_OCX_LNEX_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STATUS(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008008ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STATUS(...) bdk_ocx_lnex_status_t
#define bustype_BDK_OCX_LNEX_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STATUS(p1) (p1)
#define arguments_BDK_OCX_LNEX_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STATUS(...) "OCX_LNEX_STATUS"


/**
 * RSL - ocx_lne#_sts_msg
 */
typedef union bdk_ocx_lnex_sts_msg {
	uint64_t u;
	struct bdk_ocx_lnex_sts_msg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rx_meta_val                 : 1;  /**< RO/H - Meta-data received in the diagnostic word (per-lane) is valid. */
		uint64_t reserved_37_62              : 26;
		uint64_t rx_meta_dat                 : 3;  /**< RO/H - Meta-data received in the diagnostic word (per-lane). */
		uint64_t rx_lne_stat                 : 1;  /**< RO/H - Lane status received in the diagnostic word (per-lane). One when healthy (according to the
                                                                 Interlaken spec). */
		uint64_t rx_lnk_stat                 : 1;  /**< RO/H - Link status received in the diagnostic word (per-lane). One when healthy (according to the
                                                                 Interlaken spec). */
		uint64_t reserved_5_31               : 27;
		uint64_t tx_meta_dat                 : 3;  /**< RO/H - Meta-data transmitted in the diagnostic word (per-lane). */
		uint64_t tx_lne_stat                 : 1;  /**< R/W/H - Lane status transmitted in the diagnostic word (per-lane). One means healthy (according to
                                                                 the Interlaken spec). */
		uint64_t tx_lnk_stat                 : 1;  /**< R/W/H - Link status transmitted in the diagnostic word (per-lane). One means healthy (according to
                                                                 the Interlaken spec). */
#else
		uint64_t tx_lnk_stat                 : 1;
		uint64_t tx_lne_stat                 : 1;
		uint64_t tx_meta_dat                 : 3;
		uint64_t reserved_5_31               : 27;
		uint64_t rx_lnk_stat                 : 1;
		uint64_t rx_lne_stat                 : 1;
		uint64_t rx_meta_dat                 : 3;
		uint64_t reserved_37_62              : 26;
		uint64_t rx_meta_val                 : 1;
#endif
	} s;
	/* struct bdk_ocx_lnex_sts_msg_s      cn88xx; */
	/* struct bdk_ocx_lnex_sts_msg_s      cn88xxp1; */
} bdk_ocx_lnex_sts_msg_t;

static inline uint64_t BDK_OCX_LNEX_STS_MSG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_STS_MSG(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E011008010ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_STS_MSG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_STS_MSG(...) bdk_ocx_lnex_sts_msg_t
#define bustype_BDK_OCX_LNEX_STS_MSG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_STS_MSG(p1) (p1)
#define arguments_BDK_OCX_LNEX_STS_MSG(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_STS_MSG(...) "OCX_LNEX_STS_MSG"


/**
 * RSL - ocx_lne#_trn_ctl
 */
typedef union bdk_ocx_lnex_trn_ctl {
	uint64_t u;
	struct bdk_ocx_lnex_trn_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t lock                        : 1;  /**< RO/H - Training frame boundary locked. */
		uint64_t done                        : 1;  /**< R/W/H - Training done. For diagnostic use only may be written to 1 to force training done. */
		uint64_t ena                         : 1;  /**< RO/H - Training enabled. */
		uint64_t eie_detect                  : 1;  /**< RO/H - Electrical idle exit (EIE) detected. */
#else
		uint64_t eie_detect                  : 1;
		uint64_t ena                         : 1;
		uint64_t done                        : 1;
		uint64_t lock                        : 1;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_ocx_lnex_trn_ctl_s      cn88xx; */
	/* struct bdk_ocx_lnex_trn_ctl_s      cn88xxp1; */
} bdk_ocx_lnex_trn_ctl_t;

static inline uint64_t BDK_OCX_LNEX_TRN_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_TRN_CTL(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080D0ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_TRN_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_TRN_CTL(...) bdk_ocx_lnex_trn_ctl_t
#define bustype_BDK_OCX_LNEX_TRN_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_TRN_CTL(p1) (p1)
#define arguments_BDK_OCX_LNEX_TRN_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_TRN_CTL(...) "OCX_LNEX_TRN_CTL"


/**
 * RSL - ocx_lne#_trn_ld
 */
typedef union bdk_ocx_lnex_trn_ld {
	uint64_t u;
	struct bdk_ocx_lnex_trn_ld_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t lp_manual                   : 1;  /**< R/W - Allow software to manually manipulate local device CU/SR by ignoring hardware update. */
		uint64_t reserved_49_62              : 14;
		uint64_t ld_cu_val                   : 1;  /**< RO/H - Local device coefficient update field valid. */
		uint64_t ld_cu_dat                   : 16; /**< R/W/H - Local device coefficient update field data. */
		uint64_t reserved_17_31              : 15;
		uint64_t ld_sr_val                   : 1;  /**< RO/H - Local device status report field valid. */
		uint64_t ld_sr_dat                   : 16; /**< R/W/H - Local device status report field data. */
#else
		uint64_t ld_sr_dat                   : 16;
		uint64_t ld_sr_val                   : 1;
		uint64_t reserved_17_31              : 15;
		uint64_t ld_cu_dat                   : 16;
		uint64_t ld_cu_val                   : 1;
		uint64_t reserved_49_62              : 14;
		uint64_t lp_manual                   : 1;
#endif
	} s;
	/* struct bdk_ocx_lnex_trn_ld_s       cn88xx; */
	/* struct bdk_ocx_lnex_trn_ld_s       cn88xxp1; */
} bdk_ocx_lnex_trn_ld_t;

static inline uint64_t BDK_OCX_LNEX_TRN_LD(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_TRN_LD(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080C0ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_TRN_LD", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_TRN_LD(...) bdk_ocx_lnex_trn_ld_t
#define bustype_BDK_OCX_LNEX_TRN_LD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_TRN_LD(p1) (p1)
#define arguments_BDK_OCX_LNEX_TRN_LD(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_TRN_LD(...) "OCX_LNEX_TRN_LD"


/**
 * RSL - ocx_lne#_trn_lp
 */
typedef union bdk_ocx_lnex_trn_lp {
	uint64_t u;
	struct bdk_ocx_lnex_trn_lp_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t lp_cu_val                   : 1;  /**< RO/H - Link partner coefficient update field valid. */
		uint64_t lp_cu_dat                   : 16; /**< RO/H - Link partner coefficient update field data. */
		uint64_t reserved_17_31              : 15;
		uint64_t lp_sr_val                   : 1;  /**< RO/H - Link partner status report field valid. */
		uint64_t lp_sr_dat                   : 16; /**< RO/H - Link partner status report field data. */
#else
		uint64_t lp_sr_dat                   : 16;
		uint64_t lp_sr_val                   : 1;
		uint64_t reserved_17_31              : 15;
		uint64_t lp_cu_dat                   : 16;
		uint64_t lp_cu_val                   : 1;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_ocx_lnex_trn_lp_s       cn88xx; */
	/* struct bdk_ocx_lnex_trn_lp_s       cn88xxp1; */
} bdk_ocx_lnex_trn_lp_t;

static inline uint64_t BDK_OCX_LNEX_TRN_LP(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNEX_TRN_LP(unsigned long param1)
{
	if (((param1 <= 23)))
		return 0x000087E0110080C8ull + (param1 & 31) * 0x100ull;
	csr_fatal("BDK_OCX_LNEX_TRN_LP", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNEX_TRN_LP(...) bdk_ocx_lnex_trn_lp_t
#define bustype_BDK_OCX_LNEX_TRN_LP(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNEX_TRN_LP(p1) (p1)
#define arguments_BDK_OCX_LNEX_TRN_LP(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNEX_TRN_LP(...) "OCX_LNEX_TRN_LP"


/**
 * RSL - ocx_lne_dbg
 */
typedef union bdk_ocx_lne_dbg {
	uint64_t u;
	struct bdk_ocx_lne_dbg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t timeout                     : 24; /**< R/W/H - Number of core clocks (RCLKs) used by the bad lane timer. If this timer expires before all
                                                                 enabled lanes can be made ready, then any lane which is not ready is disabled via
                                                                 OCX_QLM(0..5)_CFG[SER_LANE_BAD]. For diagnostic use only. */
		uint64_t reserved_38_39              : 2;
		uint64_t frc_stats_ena               : 1;  /**< R/W - Enable FRC statistic counters. */
		uint64_t rx_dis_psh_skip             : 1;  /**< R/W/H - When RX_DIS_PSH_SKIP=0, skip words are destripped. When RX_DIS_PSH_SKIP=1, skip words are
                                                                 discarded in the lane logic. If the lane is in internal loopback mode, RX_DIS_PSH_SKIP is
                                                                 ignored and skip words are always discarded in the lane logic. */
		uint64_t rx_mfrm_len                 : 2;  /**< R/W/H - The quantity of data received on each lane including one sync word, scrambler state,
                                                                 diagnostic word, zero or more skip words, and the data payload.
                                                                 0x0 = 2048 words.
                                                                 0x1 = 1024 words.
                                                                 0x2 = 512 words.
                                                                 0x3 = 128 words. */
		uint64_t rx_dis_ukwn                 : 1;  /**< R/W - Disable normal response to unknown words. They are still logged but do not cause an error
                                                                 to all open channels. */
		uint64_t rx_dis_scram                : 1;  /**< R/W - Disable lane scrambler. */
		uint64_t reserved_5_31               : 27;
		uint64_t tx_lane_rev                 : 1;  /**< R/W - TX lane reversal. When enabled, lane destriping is performed from the most significant
                                                                 lane enabled to least significant lane enabled QLM_SELECT must be zero before changing
                                                                 LANE_REV. */
		uint64_t tx_mfrm_len                 : 2;  /**< R/W/H - The quantity of data sent on each lane including one sync word, scrambler state,
                                                                 diagnostic word, zero or more skip words, and the data payload.
                                                                 0x0 = 2048 words.
                                                                 0x1 = 1024 words.
                                                                 0x2 = 512 words.
                                                                 0x3 = 128 words. */
		uint64_t tx_dis_dispr                : 1;  /**< R/W - Disparity disable. */
		uint64_t tx_dis_scram                : 1;  /**< R/W - Scrambler disable. */
#else
		uint64_t tx_dis_scram                : 1;
		uint64_t tx_dis_dispr                : 1;
		uint64_t tx_mfrm_len                 : 2;
		uint64_t tx_lane_rev                 : 1;
		uint64_t reserved_5_31               : 27;
		uint64_t rx_dis_scram                : 1;
		uint64_t rx_dis_ukwn                 : 1;
		uint64_t rx_mfrm_len                 : 2;
		uint64_t rx_dis_psh_skip             : 1;
		uint64_t frc_stats_ena               : 1;
		uint64_t reserved_38_39              : 2;
		uint64_t timeout                     : 24;
#endif
	} s;
	/* struct bdk_ocx_lne_dbg_s           cn88xx; */
	/* struct bdk_ocx_lne_dbg_s           cn88xxp1; */
} bdk_ocx_lne_dbg_t;

#define BDK_OCX_LNE_DBG BDK_OCX_LNE_DBG_FUNC()
static inline uint64_t BDK_OCX_LNE_DBG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNE_DBG_FUNC(void)
{
	return 0x000087E01100FF00ull;
}
#define typedef_BDK_OCX_LNE_DBG bdk_ocx_lne_dbg_t
#define bustype_BDK_OCX_LNE_DBG BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNE_DBG 0
#define arguments_BDK_OCX_LNE_DBG -1,-1,-1,-1
#define basename_BDK_OCX_LNE_DBG "OCX_LNE_DBG"


/**
 * RSL - ocx_lnk#_cfg
 */
typedef union bdk_ocx_lnkx_cfg {
	uint64_t u;
	struct bdk_ocx_lnkx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_54_63              : 10;
		uint64_t qlm_manual                  : 6;  /**< R/W/H - QLM manual mask, where each bit corresponds to a QLM. A link automatically selects a QLM
                                                                 unless either QLM_MANUAL[QLM] is set or a QLM is not eligible for the link.

                                                                 _ QLM_MANUAL\<0\> = LNE(0..3) = QLM0.
                                                                 _ QLM_MANUAL\<1\> = LNE(7..4) = QLM1.
                                                                 _ QLM_MANUAL\<2\> = LNE(11..8) = QLM2.
                                                                 _ QLM_MANUAL\<3\> = LNE(15..12) = QLM3.
                                                                 _ QLM_MANUAL\<4\> = LNE(19..16) = QLM4.
                                                                 _ QLM_MANUAL\<5\> = LNE(23..23) = QLM5.
                                                                 _ LINK 0 may not select QLM4, QLM5.
                                                                 _ LINK 1 may not select QLM0, QLM1, QLM4, QLM5.
                                                                 _ LINK 2 may not select QLM0, QLM1.

                                                                 During a cold reset, this field is initialized to 0x3F when OCI_SPD\<3:0\> == 0xF.

                                                                 During a cold reset, this field is initialized to 0x0 when OCI_SPD\<3:0\> != 0xF.

                                                                 This field is not modified by hardware at any other time.

                                                                 This field is not affected by soft or warm reset. */
		uint64_t reserved_38_47              : 10;
		uint64_t qlm_select                  : 6;  /**< R/W/H - QLM select mask, where each bit corresponds to a QLM. A link will transmit/receive data
                                                                 using only the selected QLMs. A link is enabled if any QLM is selected. The same QLM
                                                                 should not be selected for multiple links.
                                                                 LANE_REV has no effect on this mapping.

                                                                 _ QLM_SELECT\<0\> = LNE(0..3) = QLM0.
                                                                 _ QLM_SELECT\<1\> = LNE(7..4) = QLM1.
                                                                 _ QLM_SELECT\<2\> = LNE(11..8) = QLM2.
                                                                 _ QLM_SELECT\<3\> = LNE(15..12) = QLM3.
                                                                 _ QLM_SELECT\<4\> = LNE(19..16) = QLM4.
                                                                 _ QLM_SELECT\<5\> = LNE(23..23) = QLM5.
                                                                 _ LINK 0 may not select QLM4, QLM5.
                                                                 _ LINK 1 may not select QLM0, QLM1, QLM4, QLM5.
                                                                 _ LINK 2 may not select QLM0, QLM1.
                                                                 _ LINK 2 may not select QLM2 or QLM3 when LINK1 selects any QLM.
                                                                 _ LINK 0 may not select QLM2 or QLM3 when LINK1 selects any QLM.
                                                                 _ LINK 0 automatically selects QLM0 when QLM_MANUAL\<0\>=0.
                                                                 _ LINK 0 automatically selects QLM1 when QLM_MANUAL\<1\>=0.
                                                                 _ LINK 0 automatically selects QLM2 when QLM_MANUAL\<2\>=0 and OCX_QLM2_CFG.SER_LOCAL=0.
                                                                 _ LINK 1 automatically selects QLM2 when QLM_MANUAL\<2\>=0 and OCX_QLM2_CFG.SER_LOCAL=1.
                                                                 _ LINK 1 automatically selects QLM3 when QLM_MANUAL\<3\>=0 and OCX_QLM3_CFG.SER_LOCAL=1.
                                                                 _ LINK 2 automatically selects QLM3 when QLM_MANUAL\<3\>=0 and OCX_QLM3_CFG.SER_LOCAL=0.
                                                                 _ LINK 3 automatically selects QLM4 when QLM_MANUAL\<4\>=0.
                                                                 _ LINK 3 automatically selects QLM5 when QLM_MANUAL\<5\>=0.

                                                                 A link with QLM_SELECT = 000000 is invalid and will never exchange traffic with the
                                                                 link partner. */
		uint64_t reserved_29_31              : 3;
		uint64_t data_rate                   : 13; /**< R/W/H - The number of rclk to transmit 32 words, where each word is 67 bits.  HW will
                                                                 automatically
                                                                 calculate a conservative value for this field.   SW can override the calculation by
                                                                 writing
                                                                 TX_DAT_RATE=roundup((67*RCLK / GBAUD)*32). */
		uint64_t low_delay                   : 6;  /**< R/W - The delay before reacting to a lane low data indication, as a multiple of 64 rclks.
                                                                 Added in pass 2. */
		uint64_t lane_align_dis              : 1;  /**< R/W/H - Disable the RX lane alignment. */
		uint64_t lane_rev                    : 1;  /**< R/W/H - RX lane reversal.   When enabled, lane destriping is performed from the most significant
                                                                 lane enabled to least significant lane enabled QLM_SELECT must be zero before changing
                                                                 LANE_REV. */
		uint64_t reserved_0_7                : 8;
#else
		uint64_t reserved_0_7                : 8;
		uint64_t lane_rev                    : 1;
		uint64_t lane_align_dis              : 1;
		uint64_t low_delay                   : 6;
		uint64_t data_rate                   : 13;
		uint64_t reserved_29_31              : 3;
		uint64_t qlm_select                  : 6;
		uint64_t reserved_38_47              : 10;
		uint64_t qlm_manual                  : 6;
		uint64_t reserved_54_63              : 10;
#endif
	} s;
	/* struct bdk_ocx_lnkx_cfg_s          cn88xx; */
	/* struct bdk_ocx_lnkx_cfg_s          cn88xxp1; */
} bdk_ocx_lnkx_cfg_t;

static inline uint64_t BDK_OCX_LNKX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_LNKX_CFG(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E01100F900ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_LNKX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_LNKX_CFG(...) bdk_ocx_lnkx_cfg_t
#define bustype_BDK_OCX_LNKX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_LNKX_CFG(p1) (p1)
#define arguments_BDK_OCX_LNKX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_LNKX_CFG(...) "OCX_LNKX_CFG"


/**
 * RSL - ocx_msix_pba#
 *
 * This register is the MSI-X PBA table; the bit number is indexed by the OCX_INT_VEC_E
 * enumeration.
 */
typedef union bdk_ocx_msix_pbax {
	uint64_t u;
	struct bdk_ocx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated OCX_MSIX_VEC()_CTL, enumerated by
                                                                 OCX_INT_VEC_E. Bits that have no associated OCX_INT_VEC_E are 0. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_ocx_msix_pbax_s         cn88xx; */
	/* struct bdk_ocx_msix_pbax_s         cn88xxp1; */
} bdk_ocx_msix_pbax_t;

static inline uint64_t BDK_OCX_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x000087E011FF0000ull;
	csr_fatal("BDK_OCX_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_MSIX_PBAX(...) bdk_ocx_msix_pbax_t
#define bustype_BDK_OCX_MSIX_PBAX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_MSIX_PBAX(p1) (p1)
#define arguments_BDK_OCX_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_MSIX_PBAX(...) "OCX_MSIX_PBAX"


/**
 * RSL - ocx_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the OCX_INT_VEC_E enumeration.
 *
 */
typedef union bdk_ocx_msix_vecx_addr {
	uint64_t u;
	struct bdk_ocx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's OCX_MSIX_VEC()_ADDR, OCX_MSIX_VEC()_CTL, and
                                                                 corresponding bit of OCX_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_OCX_VSEC_SCTL[MSIX_SEC] (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_ocx_msix_vecx_addr_s    cn88xx; */
	/* struct bdk_ocx_msix_vecx_addr_s    cn88xxp1; */
} bdk_ocx_msix_vecx_addr_t;

static inline uint64_t BDK_OCX_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E011F00000ull + (param1 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_MSIX_VECX_ADDR(...) bdk_ocx_msix_vecx_addr_t
#define bustype_BDK_OCX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_OCX_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_MSIX_VECX_ADDR(...) "OCX_MSIX_VECX_ADDR"


/**
 * RSL - ocx_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the OCX_INT_VEC_E enumeration.
 *
 */
typedef union bdk_ocx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_ocx_msix_vecx_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_33_63              : 31;
		uint64_t mask                        : 1;  /**< R/W - When set, no MSI-X interrupts are sent to this vector. */
		uint64_t reserved_20_31              : 12;
		uint64_t data                        : 20; /**< R/W - Data to use for MSI-X delivery of this vector. */
#else
		uint64_t data                        : 20;
		uint64_t reserved_20_31              : 12;
		uint64_t mask                        : 1;
		uint64_t reserved_33_63              : 31;
#endif
	} s;
	/* struct bdk_ocx_msix_vecx_ctl_s     cn88xx; */
	/* struct bdk_ocx_msix_vecx_ctl_s     cn88xxp1; */
} bdk_ocx_msix_vecx_ctl_t;

static inline uint64_t BDK_OCX_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x000087E011F00008ull + (param1 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_MSIX_VECX_CTL(...) bdk_ocx_msix_vecx_ctl_t
#define bustype_BDK_OCX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_OCX_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_MSIX_VECX_CTL(...) "OCX_MSIX_VECX_CTL"


/**
 * RSL - ocx_pp_cmd
 *
 * Contains the address, read size and write mask to used for the core operation. Write data
 * should be written first and placed in the OCX_PP_WR_DATA register. Writing this register
 * starts the operation. A second write to this register while an operation is in progress will
 * stall. Data is placed in the OCX_PP_RD_DATA register.
 * This register has the same bit fields as OCX_WIN_CMD.
 */
typedef union bdk_ocx_pp_cmd {
	uint64_t u;
	struct bdk_ocx_pp_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wr_mask                     : 8;  /**< R/W - Mask for the data to be written. When a bit is 1, the corresponding byte will be written.
                                                                 The values of this field must be contiguous and for 1, 2, 4, or 8 byte operations and
                                                                 aligned to operation size. A value of 0 will produce unpredictable results. Field is
                                                                 ignored during a read (LD_OP=1). */
		uint64_t reserved_54_55              : 2;
		uint64_t el                          : 2;  /**< R/W - Execution Level.  This field is used to supply the execution level of the generated load
                                                                 or store command. */
		uint64_t nsecure                     : 1;  /**< R/W - Non-secure mode.  Setting this bit causes the generated load or store command to be
                                                                 considered non-secure. */
		uint64_t ld_cmd                      : 2;  /**< R/W - The load command sent with the read:
                                                                 0x0 = Load 1-bytes.
                                                                 0x1 = Load 2-bytes.
                                                                 0x2 = Load 4-bytes.
                                                                 0x3 = Load 8-bytes. */
		uint64_t ld_op                       : 1;  /**< R/W - Operation Type 0=Store 1=Load operation. */
		uint64_t addr                        : 48; /**< R/W - The address used in both the load and store operations:
                                                                 \<47:46\> = Reserved.
                                                                 \<45:44\> = CCPI_ID.
                                                                 \<43:36\> = NCB_ID.
                                                                 \<35:0\>  = Address.

                                                                 When \<43:36\> NCB_ID is RSL (0x7E) address field is defined as:
                                                                 \<47:46\> = Reserved.
                                                                 \<45:44\> = CCPI_ID.
                                                                 \<43:36\> = 0x7E
                                                                 \<35:32\> = Reserved.
                                                                 \<31:24\> = RSL_ID.
                                                                 \<23:0\>  = RSL register offset.

                                                                 \<2:0\> are ignored in a store operation. */
#else
		uint64_t addr                        : 48;
		uint64_t ld_op                       : 1;
		uint64_t ld_cmd                      : 2;
		uint64_t nsecure                     : 1;
		uint64_t el                          : 2;
		uint64_t reserved_54_55              : 2;
		uint64_t wr_mask                     : 8;
#endif
	} s;
	/* struct bdk_ocx_pp_cmd_s            cn88xx; */
	/* struct bdk_ocx_pp_cmd_s            cn88xxp1; */
} bdk_ocx_pp_cmd_t;

#define BDK_OCX_PP_CMD BDK_OCX_PP_CMD_FUNC()
static inline uint64_t BDK_OCX_PP_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_PP_CMD_FUNC(void)
{
	return 0x000087E0110000C8ull;
}
#define typedef_BDK_OCX_PP_CMD bdk_ocx_pp_cmd_t
#define bustype_BDK_OCX_PP_CMD BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_PP_CMD 0
#define arguments_BDK_OCX_PP_CMD -1,-1,-1,-1
#define basename_BDK_OCX_PP_CMD "OCX_PP_CMD"


/**
 * RSL - ocx_pp_rd_data
 *
 * This register is the read response data associated with core command. Reads all-ones until
 * response is received.
 * This register has the same bit fields as OCX_WIN_RD_DATA.
 */
typedef union bdk_ocx_pp_rd_data {
	uint64_t u;
	struct bdk_ocx_pp_rd_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - Read response data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_pp_rd_data_s        cn88xx; */
	/* struct bdk_ocx_pp_rd_data_s        cn88xxp1; */
} bdk_ocx_pp_rd_data_t;

#define BDK_OCX_PP_RD_DATA BDK_OCX_PP_RD_DATA_FUNC()
static inline uint64_t BDK_OCX_PP_RD_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_PP_RD_DATA_FUNC(void)
{
	return 0x000087E0110000D0ull;
}
#define typedef_BDK_OCX_PP_RD_DATA bdk_ocx_pp_rd_data_t
#define bustype_BDK_OCX_PP_RD_DATA BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_PP_RD_DATA 0
#define arguments_BDK_OCX_PP_RD_DATA -1,-1,-1,-1
#define basename_BDK_OCX_PP_RD_DATA "OCX_PP_RD_DATA"


/**
 * RSL - ocx_pp_wr_data
 *
 * Contains the data to write to the address located in OCX_PP_CMD. Writing this register will
 * cause a write operation to take place.
 * This register has the same bit fields as OCX_WIN_WR_DATA.
 */
typedef union bdk_ocx_pp_wr_data {
	uint64_t u;
	struct bdk_ocx_pp_wr_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wr_data                     : 64; /**< R/W - The data to be written. */
#else
		uint64_t wr_data                     : 64;
#endif
	} s;
	/* struct bdk_ocx_pp_wr_data_s        cn88xx; */
	/* struct bdk_ocx_pp_wr_data_s        cn88xxp1; */
} bdk_ocx_pp_wr_data_t;

#define BDK_OCX_PP_WR_DATA BDK_OCX_PP_WR_DATA_FUNC()
static inline uint64_t BDK_OCX_PP_WR_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_PP_WR_DATA_FUNC(void)
{
	return 0x000087E0110000C0ull;
}
#define typedef_BDK_OCX_PP_WR_DATA bdk_ocx_pp_wr_data_t
#define bustype_BDK_OCX_PP_WR_DATA BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_PP_WR_DATA 0
#define arguments_BDK_OCX_PP_WR_DATA -1,-1,-1,-1
#define basename_BDK_OCX_PP_WR_DATA "OCX_PP_WR_DATA"


/**
 * RSL - ocx_qlm#_cfg
 */
typedef union bdk_ocx_qlmx_cfg {
	uint64_t u;
	struct bdk_ocx_qlmx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ser_low                     : 4;  /**< R/W/H - Reduce latency by limiting the amount of data in flight for each SerDes.  Writting to 0
                                                                 causes
                                                                 hardware to determine a typically optimal value.   Added in pass 2. */
		uint64_t reserved_42_59              : 18;
		uint64_t ser_limit                   : 10; /**< RAZ - Reserved. */
		uint64_t crd_dis                     : 1;  /**< R/W - For diagnostic use only. */
		uint64_t reserved_27_30              : 4;
		uint64_t trn_rxeq_only               : 1;  /**< R/W/H - Shortened training sequence.  Initialized to 1 during cold reset when OCI_SPD\<3:0\> pins
                                                                 indicate 5 GBAUD \<=speed \< 8 GBAUD. Otherwise, initialized to 0 during a cold reset. This
                                                                 field is
                                                                 not affected by soft or warm reset.  For diagnostic use only. */
		uint64_t timer_dis                   : 1;  /**< R/W/H - Disable bad lane timer. A timer counts core clocks (RCLKs) when any enabled lane is not
                                                                 ready, i.e. not in the scrambler sync state. If this timer expires before all enabled
                                                                 lanes can be made ready, then any lane which is not ready is disabled via
                                                                 OCX_QLM(0..5)_CFG[SER_LANE_BAD]. This field is not affected by soft or warm reset. */
		uint64_t trn_ena                     : 1;  /**< R/W/H - Link training enable. Link training is performed during auto link bring up. Initialized to
                                                                 1 during cold reset when OCI_SPD\<3:0\> pins indicate speed \>= 5 GBAUD. Otherwise,
                                                                 initialized to 0 during a cold reset. This field is not affected by soft or warm reset. */
		uint64_t ser_lane_ready              : 4;  /**< R/W/H - SerDes lanes that are ready for bundling into the link. */
		uint64_t ser_lane_bad                : 4;  /**< R/W/H - SerDes lanes excluded from use. */
		uint64_t reserved_7_15               : 9;
		uint64_t ser_lane_rev                : 1;  /**< RO/H - SerDes lane reversal has been detected. */
		uint64_t ser_rxpol_auto              : 1;  /**< R/W - SerDes lane receive polarity auto detection mode. */
		uint64_t ser_rxpol                   : 1;  /**< R/W - SerDes lane receive polarity:
                                                                 0 = RX without inversion.
                                                                 1 = RX with inversion. */
		uint64_t ser_txpol                   : 1;  /**< R/W - SerDes lane transmit polarity:
                                                                 0 = TX without inversion.
                                                                 1 = TX with inversion. */
		uint64_t reserved_1_2                : 2;
		uint64_t ser_local                   : 1;  /**< R/W/H - _ Auto initialization may set OCX_LNK0_CFG[QLM_SELECT\<2\>] = 1 only if
                                                                 OCX_QLM2_CFG[SER_LOCAL] = 0.
                                                                 _ Auto initialization may set OCX_LNK1_CFG[QLM_SELECT\<2\>] = 1 only if
                                                                 OCX_QLM2_CFG[SER_LOCAL] = 1.
                                                                 _ Auto initialization may set OCX_LNK1_CFG[QLM_SELECT\<3\>] = 1 only if
                                                                 OCX_QLM3_CFG[SER_LOCAL] = 1.
                                                                 _ Auto initialization may set OCX_LNK2_CFG[QLM_SELECT\<3\>] = 1 only if
                                                                 OCX_QLM3_CFG[SER_LOCAL] = 0.

                                                                 _ QLM0/1 can only participate in LNK0; therefore
                                                                 OCX_QLM0/1_CFG[SER_LOCAL] has no effect.
                                                                 _ QLM4/5 can only participate in LNK2; therefore
                                                                 OCX_QLM4/5_CFG[SER_LOCAL] has no effect.

                                                                 During a cold reset, initialized as follows:
                                                                 _ OCX_QLM2_CFG.SER_LOCAL = pi_oci2_link1.
                                                                 _ OCX_QLM3_CFG.SER_LOCAL = pi_oci3_link1.

                                                                 The combo of pi_oci2_link1=1 and pi_oci3_link1=0 is illegal.

                                                                 The combo of OCX_QLM2_CFG.SER_LOCAL=1 and OCX_QLM3_CFG.SER_LOCAL=0 is illegal. */
#else
		uint64_t ser_local                   : 1;
		uint64_t reserved_1_2                : 2;
		uint64_t ser_txpol                   : 1;
		uint64_t ser_rxpol                   : 1;
		uint64_t ser_rxpol_auto              : 1;
		uint64_t ser_lane_rev                : 1;
		uint64_t reserved_7_15               : 9;
		uint64_t ser_lane_bad                : 4;
		uint64_t ser_lane_ready              : 4;
		uint64_t trn_ena                     : 1;
		uint64_t timer_dis                   : 1;
		uint64_t trn_rxeq_only               : 1;
		uint64_t reserved_27_30              : 4;
		uint64_t crd_dis                     : 1;
		uint64_t ser_limit                   : 10;
		uint64_t reserved_42_59              : 18;
		uint64_t ser_low                     : 4;
#endif
	} s;
	/* struct bdk_ocx_qlmx_cfg_s          cn88xx; */
	/* struct bdk_ocx_qlmx_cfg_s          cn88xxp1; */
} bdk_ocx_qlmx_cfg_t;

static inline uint64_t BDK_OCX_QLMX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_QLMX_CFG(unsigned long param1)
{
	if (((param1 <= 5)))
		return 0x000087E01100F800ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_QLMX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_QLMX_CFG(...) bdk_ocx_qlmx_cfg_t
#define bustype_BDK_OCX_QLMX_CFG(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_QLMX_CFG(p1) (p1)
#define arguments_BDK_OCX_QLMX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_QLMX_CFG(...) "OCX_QLMX_CFG"


/**
 * RSL - ocx_rlk#_align
 */
typedef union bdk_ocx_rlkx_align {
	uint64_t u;
	struct bdk_ocx_rlkx_align_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bad_cnt                     : 32; /**< R/W/H - Number of alignment sequences received in error (i.e. those that violate the current
                                                                 alignment). Count saturates at max value. */
		uint64_t good_cnt                    : 32; /**< R/W/H - Number of alignment sequences received (i.e. those that do not violate the current
                                                                 alignment). Count saturates at max value. */
#else
		uint64_t good_cnt                    : 32;
		uint64_t bad_cnt                     : 32;
#endif
	} s;
	/* struct bdk_ocx_rlkx_align_s        cn88xx; */
	/* struct bdk_ocx_rlkx_align_s        cn88xxp1; */
} bdk_ocx_rlkx_align_t;

static inline uint64_t BDK_OCX_RLKX_ALIGN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_ALIGN(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018060ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_ALIGN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_ALIGN(...) bdk_ocx_rlkx_align_t
#define bustype_BDK_OCX_RLKX_ALIGN(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_ALIGN(p1) (p1)
#define arguments_BDK_OCX_RLKX_ALIGN(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_ALIGN(...) "OCX_RLKX_ALIGN"


/**
 * RSL - ocx_rlk#_blk_err
 */
typedef union bdk_ocx_rlkx_blk_err {
	uint64_t u;
	struct bdk_ocx_rlkx_blk_err_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t limit                       : 16; /**< R/W - Number of blocks received with errors before the OCX_COM_LINK(0..2)_INT[BLK_ERR] interrupt
                                                                 is generated. */
		uint64_t count                       : 16; /**< R/W - Number of blocks received with one or more errors detected. Multiple errors may be
                                                                 detected as the link starts up. */
#else
		uint64_t count                       : 16;
		uint64_t limit                       : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_ocx_rlkx_blk_err_s      cn88xx; */
	/* struct bdk_ocx_rlkx_blk_err_s      cn88xxp1; */
} bdk_ocx_rlkx_blk_err_t;

static inline uint64_t BDK_OCX_RLKX_BLK_ERR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_BLK_ERR(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018050ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_BLK_ERR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_BLK_ERR(...) bdk_ocx_rlkx_blk_err_t
#define bustype_BDK_OCX_RLKX_BLK_ERR(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_BLK_ERR(p1) (p1)
#define arguments_BDK_OCX_RLKX_BLK_ERR(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_BLK_ERR(...) "OCX_RLKX_BLK_ERR"


/**
 * RSL - ocx_rlk#_ecc_ctl
 */
typedef union bdk_ocx_rlkx_ecc_ctl {
	uint64_t u;
	struct bdk_ocx_rlkx_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t fifo1_flip                  : 2;  /**< R/W - Test pattern to cause ECC errors in top RX FIFO syndromes. */
		uint64_t fifo0_flip                  : 2;  /**< R/W - Test pattern to cause ECC errors in bottom RX FIFO syndromes. */
		uint64_t reserved_2_31               : 30;
		uint64_t fifo1_cdis                  : 1;  /**< R/W - ECC correction disable for top RX FIFO RAM. */
		uint64_t fifo0_cdis                  : 1;  /**< R/W - ECC correction disable for bottom RX FIFO RAM. */
#else
		uint64_t fifo0_cdis                  : 1;
		uint64_t fifo1_cdis                  : 1;
		uint64_t reserved_2_31               : 30;
		uint64_t fifo0_flip                  : 2;
		uint64_t fifo1_flip                  : 2;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_ocx_rlkx_ecc_ctl_s      cn88xx; */
	/* struct bdk_ocx_rlkx_ecc_ctl_s      cn88xxp1; */
} bdk_ocx_rlkx_ecc_ctl_t;

static inline uint64_t BDK_OCX_RLKX_ECC_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_ECC_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018018ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_ECC_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_ECC_CTL(...) bdk_ocx_rlkx_ecc_ctl_t
#define bustype_BDK_OCX_RLKX_ECC_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_ECC_CTL(p1) (p1)
#define arguments_BDK_OCX_RLKX_ECC_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_ECC_CTL(...) "OCX_RLKX_ECC_CTL"


/**
 * RSL - ocx_rlk#_enables
 */
typedef union bdk_ocx_rlkx_enables {
	uint64_t u;
	struct bdk_ocx_rlkx_enables_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t mcd                         : 1;  /**< R/W - Master enable for all inbound MCD bits. This bit must be enabled by software. once any
                                                                 trusted-mode validation has occurred and before any MCD traffic is generated. MCD traffic
                                                                 is typically controlled by the OCX_TLK(0..2)_MCD_CTL register. */
		uint64_t m_req                       : 1;  /**< R/W/H - Master enable for all inbound memory requests. This bit is typically set at reset but is
                                                                 cleared when operating in trusted-mode and must be enabled by software. */
		uint64_t io_req                      : 1;  /**< R/W/H - Master enable for all inbound I/O requests. This bit is typically set at reset but is
                                                                 cleared when operating in trusted-mode and must be enabled by software. */
		uint64_t fwd                         : 1;  /**< R/W/H - Master enable for all inbound forward commands. This bit is typically set at reset but is
                                                                 cleared when operating in trusted-mode and must be enabled by software. */
		uint64_t co_proc                     : 1;  /**< R/W/H - Master enable for all inbound coprocessor commands. This bit is typically set at reset but
                                                                 is cleared when operating in trusted-mode and must be enabled by software. */
#else
		uint64_t co_proc                     : 1;
		uint64_t fwd                         : 1;
		uint64_t io_req                      : 1;
		uint64_t m_req                       : 1;
		uint64_t mcd                         : 1;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_ocx_rlkx_enables_s      cn88xx; */
	/* struct bdk_ocx_rlkx_enables_s      cn88xxp1; */
} bdk_ocx_rlkx_enables_t;

static inline uint64_t BDK_OCX_RLKX_ENABLES(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_ENABLES(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018000ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_ENABLES", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_ENABLES(...) bdk_ocx_rlkx_enables_t
#define bustype_BDK_OCX_RLKX_ENABLES(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_ENABLES(p1) (p1)
#define arguments_BDK_OCX_RLKX_ENABLES(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_ENABLES(...) "OCX_RLKX_ENABLES"


/**
 * RSL - ocx_rlk#_fifo#_cnt
 */
typedef union bdk_ocx_rlkx_fifox_cnt {
	uint64_t u;
	struct bdk_ocx_rlkx_fifox_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< RO/H - RX FIFO count of 64-bit words to send to core. VC13 traffic is used immediately so the
                                                                 FIFO count is always 0. See OCX_RLK(0..2)_LNK_DATA. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_rlkx_fifox_cnt_s    cn88xx; */
	/* struct bdk_ocx_rlkx_fifox_cnt_s    cn88xxp1; */
} bdk_ocx_rlkx_fifox_cnt_t;

static inline uint64_t BDK_OCX_RLKX_FIFOX_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_FIFOX_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011018100ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_RLKX_FIFOX_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_FIFOX_CNT(...) bdk_ocx_rlkx_fifox_cnt_t
#define bustype_BDK_OCX_RLKX_FIFOX_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_FIFOX_CNT(p1,p2) (p1)
#define arguments_BDK_OCX_RLKX_FIFOX_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_RLKX_FIFOX_CNT(...) "OCX_RLKX_FIFOX_CNT"


/**
 * RSL - ocx_rlk#_key_high#
 */
typedef union bdk_ocx_rlkx_key_highx {
	uint64_t u;
	struct bdk_ocx_rlkx_key_highx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Transmit key data \<127:64\>.
                                                                 Reads as zero if OCX_RLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_rlkx_key_highx_s    cn88xx; */
	/* struct bdk_ocx_rlkx_key_highx_s    cn88xxp1; */
} bdk_ocx_rlkx_key_highx_t;

static inline uint64_t BDK_OCX_RLKX_KEY_HIGHX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_KEY_HIGHX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 2)))
		return 0x000087E011018208ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_RLKX_KEY_HIGHX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_KEY_HIGHX(...) bdk_ocx_rlkx_key_highx_t
#define bustype_BDK_OCX_RLKX_KEY_HIGHX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_KEY_HIGHX(p1,p2) (p1)
#define arguments_BDK_OCX_RLKX_KEY_HIGHX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_RLKX_KEY_HIGHX(...) "OCX_RLKX_KEY_HIGHX"


/**
 * RSL - ocx_rlk#_key_low#
 */
typedef union bdk_ocx_rlkx_key_lowx {
	uint64_t u;
	struct bdk_ocx_rlkx_key_lowx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Receive key data \<63:0\>.
                                                                 Reads as zero if OCX_RLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_rlkx_key_lowx_s     cn88xx; */
	/* struct bdk_ocx_rlkx_key_lowx_s     cn88xxp1; */
} bdk_ocx_rlkx_key_lowx_t;

static inline uint64_t BDK_OCX_RLKX_KEY_LOWX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_KEY_LOWX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 2)))
		return 0x000087E011018200ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_RLKX_KEY_LOWX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_KEY_LOWX(...) bdk_ocx_rlkx_key_lowx_t
#define bustype_BDK_OCX_RLKX_KEY_LOWX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_KEY_LOWX(p1,p2) (p1)
#define arguments_BDK_OCX_RLKX_KEY_LOWX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_RLKX_KEY_LOWX(...) "OCX_RLKX_KEY_LOWX"


/**
 * RSL - ocx_rlk#_lnk_data
 */
typedef union bdk_ocx_rlkx_lnk_data {
	uint64_t u;
	struct bdk_ocx_rlkx_lnk_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rcvd                        : 1;  /**< RO/H - Reads state of OCX_COM_LINK(0..2)_INT[LNK_DATA]; set by hardware when a link data block is
                                                                 received. */
		uint64_t reserved_56_62              : 7;
		uint64_t data                        : 56; /**< RO/H - Contents of this register are received from the OCX_TLK(0..2)_LNK_DATA register on the
                                                                 link partner. Each time a new value is received the RX_LDAT interrupt is generated. */
#else
		uint64_t data                        : 56;
		uint64_t reserved_56_62              : 7;
		uint64_t rcvd                        : 1;
#endif
	} s;
	/* struct bdk_ocx_rlkx_lnk_data_s     cn88xx; */
	/* struct bdk_ocx_rlkx_lnk_data_s     cn88xxp1; */
} bdk_ocx_rlkx_lnk_data_t;

static inline uint64_t BDK_OCX_RLKX_LNK_DATA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_LNK_DATA(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018028ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_LNK_DATA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_LNK_DATA(...) bdk_ocx_rlkx_lnk_data_t
#define bustype_BDK_OCX_RLKX_LNK_DATA(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_LNK_DATA(p1) (p1)
#define arguments_BDK_OCX_RLKX_LNK_DATA(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_LNK_DATA(...) "OCX_RLKX_LNK_DATA"


/**
 * RSL - ocx_rlk#_mcd_ctl
 *
 * This debug register captures which new MCD bits have been received from the link partner. The
 * MCD bits are received when the both the OCX_RLK(0..2)_ENABLES[MCD] bit is set and the MCD was
 * not previously transmitted.
 */
typedef union bdk_ocx_rlkx_mcd_ctl {
	uint64_t u;
	struct bdk_ocx_rlkx_mcd_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t clr                         : 3;  /**< R/W1C/H - Inbound MCD value being driven by link(0..2). Set by hardware receiving an MCD packet and
                                                                 cleared by this register. */
#else
		uint64_t clr                         : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_ocx_rlkx_mcd_ctl_s      cn88xx; */
	/* struct bdk_ocx_rlkx_mcd_ctl_s      cn88xxp1; */
} bdk_ocx_rlkx_mcd_ctl_t;

static inline uint64_t BDK_OCX_RLKX_MCD_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_MCD_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018020ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_MCD_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_MCD_CTL(...) bdk_ocx_rlkx_mcd_ctl_t
#define bustype_BDK_OCX_RLKX_MCD_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_MCD_CTL(p1) (p1)
#define arguments_BDK_OCX_RLKX_MCD_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_MCD_CTL(...) "OCX_RLKX_MCD_CTL"


/**
 * RSL - ocx_rlk#_protect
 */
typedef union bdk_ocx_rlkx_protect {
	uint64_t u;
	struct bdk_ocx_rlkx_protect_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t wo_key                      : 1;  /**< R/W1S - Reserved. Setting this bit blocks read access to OCX_RLK()_KEY_LOW,
                                                                 OCX_RLK()_KEY_HIGH, OCX_RLK()_SALT_LOW and OCX_RLK()_SALT_HIGH registers. */
		uint64_t reserved_1_6                : 6;
		uint64_t enable                      : 1;  /**< RO/H - Data encryption enabled. This bit is set and cleared by the transmitting link
                                                                 partner. */
#else
		uint64_t enable                      : 1;
		uint64_t reserved_1_6                : 6;
		uint64_t wo_key                      : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_ocx_rlkx_protect_s      cn88xx; */
	/* struct bdk_ocx_rlkx_protect_s      cn88xxp1; */
} bdk_ocx_rlkx_protect_t;

static inline uint64_t BDK_OCX_RLKX_PROTECT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_PROTECT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0110182C0ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_PROTECT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_PROTECT(...) bdk_ocx_rlkx_protect_t
#define bustype_BDK_OCX_RLKX_PROTECT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_PROTECT(p1) (p1)
#define arguments_BDK_OCX_RLKX_PROTECT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_PROTECT(...) "OCX_RLKX_PROTECT"


/**
 * RSL - ocx_rlk#_salt_high
 */
typedef union bdk_ocx_rlkx_salt_high {
	uint64_t u;
	struct bdk_ocx_rlkx_salt_high_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Receive salt data \<127:64\>.
                                                                 Reads as zero if OCX_RLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_rlkx_salt_high_s    cn88xx; */
	/* struct bdk_ocx_rlkx_salt_high_s    cn88xxp1; */
} bdk_ocx_rlkx_salt_high_t;

static inline uint64_t BDK_OCX_RLKX_SALT_HIGH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_SALT_HIGH(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018288ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_SALT_HIGH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_SALT_HIGH(...) bdk_ocx_rlkx_salt_high_t
#define bustype_BDK_OCX_RLKX_SALT_HIGH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_SALT_HIGH(p1) (p1)
#define arguments_BDK_OCX_RLKX_SALT_HIGH(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_SALT_HIGH(...) "OCX_RLKX_SALT_HIGH"


/**
 * RSL - ocx_rlk#_salt_low
 */
typedef union bdk_ocx_rlkx_salt_low {
	uint64_t u;
	struct bdk_ocx_rlkx_salt_low_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Receive salt data \<63:0\>.
                                                                 Reads as zero if OCX_RLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_rlkx_salt_low_s     cn88xx; */
	/* struct bdk_ocx_rlkx_salt_low_s     cn88xxp1; */
} bdk_ocx_rlkx_salt_low_t;

static inline uint64_t BDK_OCX_RLKX_SALT_LOW(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_RLKX_SALT_LOW(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011018280ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_RLKX_SALT_LOW", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_RLKX_SALT_LOW(...) bdk_ocx_rlkx_salt_low_t
#define bustype_BDK_OCX_RLKX_SALT_LOW(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_RLKX_SALT_LOW(p1) (p1)
#define arguments_BDK_OCX_RLKX_SALT_LOW(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_RLKX_SALT_LOW(...) "OCX_RLKX_SALT_LOW"


/**
 * RSL - ocx_tlk#_bist_status
 *
 * Contains status from last memory BIST for all TX FIFO memories and REPLAY memories in this
 * link. RX FIFO status can be found in OCX_COM_BIST_STATUS.
 */
typedef union bdk_ocx_tlkx_bist_status {
	uint64_t u;
	struct bdk_ocx_tlkx_bist_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t status                      : 16; /**< RO/H - \<15:14\> = REPLAY Memories BIST Status \<1:0\>.
                                                                 \<13:12\> = MOC TX_FIFO BIST Status \<1:0\>.
                                                                 \<11:0\>  = TX_FIFO[11:0] by Link VC number. */
#else
		uint64_t status                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_tlkx_bist_status_s  cn88xx; */
	/* struct bdk_ocx_tlkx_bist_status_s  cn88xxp1; */
} bdk_ocx_tlkx_bist_status_t;

static inline uint64_t BDK_OCX_TLKX_BIST_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_BIST_STATUS(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010008ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_BIST_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_BIST_STATUS(...) bdk_ocx_tlkx_bist_status_t
#define bustype_BDK_OCX_TLKX_BIST_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_BIST_STATUS(p1) (p1)
#define arguments_BDK_OCX_TLKX_BIST_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_BIST_STATUS(...) "OCX_TLKX_BIST_STATUS"


/**
 * RSL - ocx_tlk#_ecc_ctl
 */
typedef union bdk_ocx_tlkx_ecc_ctl {
	uint64_t u;
	struct bdk_ocx_tlkx_ecc_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_38_63              : 26;
		uint64_t rply1_flip                  : 2;  /**< R/W - Test pattern to cause ECC errors in RPLY1 RAM. */
		uint64_t rply0_flip                  : 2;  /**< R/W - Test pattern to cause ECC errors in RPLY0 RAM. */
		uint64_t fifo_flip                   : 2;  /**< R/W - Test pattern to cause ECC errors in TX FIFO RAM. */
		uint64_t reserved_3_31               : 29;
		uint64_t rply1_cdis                  : 1;  /**< R/W - ECC correction disable for replay top memories. */
		uint64_t rply0_cdis                  : 1;  /**< R/W - ECC correction disable for replay bottom memories. */
		uint64_t fifo_cdis                   : 1;  /**< R/W - ECC correction disable for TX FIFO memories. */
#else
		uint64_t fifo_cdis                   : 1;
		uint64_t rply0_cdis                  : 1;
		uint64_t rply1_cdis                  : 1;
		uint64_t reserved_3_31               : 29;
		uint64_t fifo_flip                   : 2;
		uint64_t rply0_flip                  : 2;
		uint64_t rply1_flip                  : 2;
		uint64_t reserved_38_63              : 26;
#endif
	} s;
	/* struct bdk_ocx_tlkx_ecc_ctl_s      cn88xx; */
	/* struct bdk_ocx_tlkx_ecc_ctl_s      cn88xxp1; */
} bdk_ocx_tlkx_ecc_ctl_t;

static inline uint64_t BDK_OCX_TLKX_ECC_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_ECC_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010018ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_ECC_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_ECC_CTL(...) bdk_ocx_tlkx_ecc_ctl_t
#define bustype_BDK_OCX_TLKX_ECC_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_ECC_CTL(p1) (p1)
#define arguments_BDK_OCX_TLKX_ECC_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_ECC_CTL(...) "OCX_TLKX_ECC_CTL"


/**
 * RSL - ocx_tlk#_fifo#_cnt
 */
typedef union bdk_ocx_tlkx_fifox_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_fifox_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< RO/H - TX FIFO count of bus cycles to send. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_tlkx_fifox_cnt_s    cn88xx; */
	/* struct bdk_ocx_tlkx_fifox_cnt_s    cn88xxp1; */
} bdk_ocx_tlkx_fifox_cnt_t;

static inline uint64_t BDK_OCX_TLKX_FIFOX_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_FIFOX_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011010100ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_FIFOX_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_FIFOX_CNT(...) bdk_ocx_tlkx_fifox_cnt_t
#define bustype_BDK_OCX_TLKX_FIFOX_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_FIFOX_CNT(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_FIFOX_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_FIFOX_CNT(...) "OCX_TLKX_FIFOX_CNT"


/**
 * RSL - ocx_tlk#_key_high#
 */
typedef union bdk_ocx_tlkx_key_highx {
	uint64_t u;
	struct bdk_ocx_tlkx_key_highx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Transmit encryption key \<127:64\>.
                                                                 Reads as zero if OCX_TLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_key_highx_s    cn88xx; */
	/* struct bdk_ocx_tlkx_key_highx_s    cn88xxp1; */
} bdk_ocx_tlkx_key_highx_t;

static inline uint64_t BDK_OCX_TLKX_KEY_HIGHX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_KEY_HIGHX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 2)))
		return 0x000087E011010708ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_TLKX_KEY_HIGHX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_KEY_HIGHX(...) bdk_ocx_tlkx_key_highx_t
#define bustype_BDK_OCX_TLKX_KEY_HIGHX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_KEY_HIGHX(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_KEY_HIGHX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_KEY_HIGHX(...) "OCX_TLKX_KEY_HIGHX"


/**
 * RSL - ocx_tlk#_key_low#
 */
typedef union bdk_ocx_tlkx_key_lowx {
	uint64_t u;
	struct bdk_ocx_tlkx_key_lowx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Transmit encryption key \<63:0\>.
                                                                 Reads as zero if OCX_TLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_key_lowx_s     cn88xx; */
	/* struct bdk_ocx_tlkx_key_lowx_s     cn88xxp1; */
} bdk_ocx_tlkx_key_lowx_t;

static inline uint64_t BDK_OCX_TLKX_KEY_LOWX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_KEY_LOWX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 2)))
		return 0x000087E011010700ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x10ull;
	csr_fatal("BDK_OCX_TLKX_KEY_LOWX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_KEY_LOWX(...) bdk_ocx_tlkx_key_lowx_t
#define bustype_BDK_OCX_TLKX_KEY_LOWX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_KEY_LOWX(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_KEY_LOWX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_KEY_LOWX(...) "OCX_TLKX_KEY_LOWX"


/**
 * RSL - ocx_tlk#_lnk_data
 */
typedef union bdk_ocx_tlkx_lnk_data {
	uint64_t u;
	struct bdk_ocx_tlkx_lnk_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t data                        : 56; /**< R/W - Writes to this register transfer the contents to the OCX_RLK(0..2)_LNK_DATA register on
                                                                 the receiving link. */
#else
		uint64_t data                        : 56;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_ocx_tlkx_lnk_data_s     cn88xx; */
	/* struct bdk_ocx_tlkx_lnk_data_s     cn88xxp1; */
} bdk_ocx_tlkx_lnk_data_t;

static inline uint64_t BDK_OCX_TLKX_LNK_DATA(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_LNK_DATA(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010028ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_LNK_DATA", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_LNK_DATA(...) bdk_ocx_tlkx_lnk_data_t
#define bustype_BDK_OCX_TLKX_LNK_DATA(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_LNK_DATA(p1) (p1)
#define arguments_BDK_OCX_TLKX_LNK_DATA(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_LNK_DATA(...) "OCX_TLKX_LNK_DATA"


/**
 * RSL - ocx_tlk#_lnk_vc#_cnt
 */
typedef union bdk_ocx_tlkx_lnk_vcx_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_lnk_vcx_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< RO/H - Link VC credits available for use. VC13 always reads 1 since credits are not required. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_tlkx_lnk_vcx_cnt_s  cn88xx; */
	/* struct bdk_ocx_tlkx_lnk_vcx_cnt_s  cn88xxp1; */
} bdk_ocx_tlkx_lnk_vcx_cnt_t;

static inline uint64_t BDK_OCX_TLKX_LNK_VCX_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_LNK_VCX_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011010200ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_LNK_VCX_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_LNK_VCX_CNT(...) bdk_ocx_tlkx_lnk_vcx_cnt_t
#define bustype_BDK_OCX_TLKX_LNK_VCX_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_LNK_VCX_CNT(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_LNK_VCX_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_LNK_VCX_CNT(...) "OCX_TLKX_LNK_VCX_CNT"


/**
 * RSL - ocx_tlk#_mcd_ctl
 *
 * This register controls which MCD bits are transported via the link. For proper operation
 * only one link must be enabled in both directions between each pair of link partners.
 *
 * INTERNAL: If N chips are connected over OCX, N-1 links should have MCD enabled.
 * A single "central" chip should connect all MCD buses and have a single MCD enabled link
 * to each of the other chips.  No MCD enabled links should connect between chips that don't
 * include the "central" chip.
 */
typedef union bdk_ocx_tlkx_mcd_ctl {
	uint64_t u;
	struct bdk_ocx_tlkx_mcd_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_3_63               : 61;
		uint64_t tx_enb                      : 3;  /**< R/W - Transmission enables for MCD bits \<2:0\>. */
#else
		uint64_t tx_enb                      : 3;
		uint64_t reserved_3_63               : 61;
#endif
	} s;
	/* struct bdk_ocx_tlkx_mcd_ctl_s      cn88xx; */
	/* struct bdk_ocx_tlkx_mcd_ctl_s      cn88xxp1; */
} bdk_ocx_tlkx_mcd_ctl_t;

static inline uint64_t BDK_OCX_TLKX_MCD_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_MCD_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010020ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_MCD_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_MCD_CTL(...) bdk_ocx_tlkx_mcd_ctl_t
#define bustype_BDK_OCX_TLKX_MCD_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_MCD_CTL(p1) (p1)
#define arguments_BDK_OCX_TLKX_MCD_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_MCD_CTL(...) "OCX_TLKX_MCD_CTL"


/**
 * RSL - ocx_tlk#_protect
 */
typedef union bdk_ocx_tlkx_protect {
	uint64_t u;
	struct bdk_ocx_tlkx_protect_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t wo_key                      : 1;  /**< R/W1S - Setting this bit blocks read access to the OCX_TLK(0..2)_KEY and
                                                                 OCX_TLK(0..2)_SALT registers. Once set this bit cannot be cleared until reset. */
		uint64_t reserved_3_6                : 4;
		uint64_t busy                        : 1;  /**< RO/H - When set, LOAD and/or BUSY signals are being transmitted to the link
                                                                 partner. Hold off any updates to the OCX_TLK()_KEY_LOW, OCX_TLK()_KEY_HIGH,
                                                                 OCX_TLK()_SALT_LOW, OCX_TLK()_SALT_HIGH and OCX_TLK()_PROTECT registers while
                                                                 this bit is set. */
		uint64_t load                        : 1;  /**< WO - Seting this register loads the current set of keys written to the
                                                                 OCX_TLK()_KEY_LOW, OCX_TLK()_KEY_HIGH, OCX_TLK()_SALT_LOW, OCX_TLK()_SALT_HIGH
                                                                 and forces the receive side of the link parter to do likewise. */
		uint64_t enable                      : 1;  /**< R/W - Enable data encryption.  When set this bit enables encryption on the
                                                                 transmitter and the receiving link partner.
                                                                 INTERNAL: Encryption is non-functional on pass 1. */
#else
		uint64_t enable                      : 1;
		uint64_t load                        : 1;
		uint64_t busy                        : 1;
		uint64_t reserved_3_6                : 4;
		uint64_t wo_key                      : 1;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_ocx_tlkx_protect_s      cn88xx; */
	/* struct bdk_ocx_tlkx_protect_s      cn88xxp1; */
} bdk_ocx_tlkx_protect_t;

static inline uint64_t BDK_OCX_TLKX_PROTECT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_PROTECT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E0110107C0ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_PROTECT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_PROTECT(...) bdk_ocx_tlkx_protect_t
#define bustype_BDK_OCX_TLKX_PROTECT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_PROTECT(p1) (p1)
#define arguments_BDK_OCX_TLKX_PROTECT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_PROTECT(...) "OCX_TLKX_PROTECT"


/**
 * RSL - ocx_tlk#_rtn_vc#_cnt
 */
typedef union bdk_ocx_tlkx_rtn_vcx_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_rtn_vcx_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< RO/H - Link VC credits to return. VC13 always reads 0 since credits are never returned. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_tlkx_rtn_vcx_cnt_s  cn88xx; */
	/* struct bdk_ocx_tlkx_rtn_vcx_cnt_s  cn88xxp1; */
} bdk_ocx_tlkx_rtn_vcx_cnt_t;

static inline uint64_t BDK_OCX_TLKX_RTN_VCX_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_RTN_VCX_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011010300ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_RTN_VCX_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_RTN_VCX_CNT(...) bdk_ocx_tlkx_rtn_vcx_cnt_t
#define bustype_BDK_OCX_TLKX_RTN_VCX_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_RTN_VCX_CNT(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_RTN_VCX_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_RTN_VCX_CNT(...) "OCX_TLKX_RTN_VCX_CNT"


/**
 * RSL - ocx_tlk#_salt_high
 */
typedef union bdk_ocx_tlkx_salt_high {
	uint64_t u;
	struct bdk_ocx_tlkx_salt_high_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Transmit salt data \<127:64\>.
                                                                 Reads as zero if OCX_TLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_salt_high_s    cn88xx; */
	/* struct bdk_ocx_tlkx_salt_high_s    cn88xxp1; */
} bdk_ocx_tlkx_salt_high_t;

static inline uint64_t BDK_OCX_TLKX_SALT_HIGH(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_SALT_HIGH(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010788ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_SALT_HIGH", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_SALT_HIGH(...) bdk_ocx_tlkx_salt_high_t
#define bustype_BDK_OCX_TLKX_SALT_HIGH(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_SALT_HIGH(p1) (p1)
#define arguments_BDK_OCX_TLKX_SALT_HIGH(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_SALT_HIGH(...) "OCX_TLKX_SALT_HIGH"


/**
 * RSL - ocx_tlk#_salt_low
 */
typedef union bdk_ocx_tlkx_salt_low {
	uint64_t u;
	struct bdk_ocx_tlkx_salt_low_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< WO - Transmit salt data \<63:0\>.
                                                                 Reads as zero if OCX_TLK(0..2)_PROTECT[WO_KEY] is set. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_salt_low_s     cn88xx; */
	/* struct bdk_ocx_tlkx_salt_low_s     cn88xxp1; */
} bdk_ocx_tlkx_salt_low_t;

static inline uint64_t BDK_OCX_TLKX_SALT_LOW(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_SALT_LOW(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010780ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_SALT_LOW", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_SALT_LOW(...) bdk_ocx_tlkx_salt_low_t
#define bustype_BDK_OCX_TLKX_SALT_LOW(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_SALT_LOW(p1) (p1)
#define arguments_BDK_OCX_TLKX_SALT_LOW(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_SALT_LOW(...) "OCX_TLKX_SALT_LOW"


/**
 * RSL - ocx_tlk#_stat_ctl
 */
typedef union bdk_ocx_tlkx_stat_ctl {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_ctl_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t clear                       : 1;  /**< WO - Setting this bit clears all OCX_TLK(a)_STAT_*CNT, OCX_TLK(a)_STAT_*CMD,
                                                                 OCX_TLK(a)_STAT_*PKT and OCX_TLK(0..2)_STAT_*CON registers. */
		uint64_t enable                      : 1;  /**< R/W - This bit controls the capture of statistics to the OCX_TLK(a)_STAT_*CNT,
                                                                 OCX_TLK(a)_STAT_*CMD, OCX_TLK(a)_STAT_*PKT and OCX_TLK(a)_STAT_*CON registers. When set,
                                                                 traffic will increment the corresponding registers. When cleared, traffic will be ignored. */
#else
		uint64_t enable                      : 1;
		uint64_t clear                       : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_ctl_s     cn88xx; */
	/* struct bdk_ocx_tlkx_stat_ctl_s     cn88xxp1; */
} bdk_ocx_tlkx_stat_ctl_t;

static inline uint64_t BDK_OCX_TLKX_STAT_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_CTL(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010040ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_CTL(...) bdk_ocx_tlkx_stat_ctl_t
#define bustype_BDK_OCX_TLKX_STAT_CTL(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_CTL(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_CTL(...) "OCX_TLKX_STAT_CTL"


/**
 * RSL - ocx_tlk#_stat_data_cnt
 */
typedef union bdk_ocx_tlkx_stat_data_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_data_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of data blocks transferred over the CCPI Link while OCX_TLK(0..2)_STAT_CTL[ENABLE]
                                                                 has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_data_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_data_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_data_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_DATA_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_DATA_CNT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010408ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_DATA_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_DATA_CNT(...) bdk_ocx_tlkx_stat_data_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_DATA_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_DATA_CNT(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_DATA_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_DATA_CNT(...) "OCX_TLKX_STAT_DATA_CNT"


/**
 * RSL - ocx_tlk#_stat_err_cnt
 */
typedef union bdk_ocx_tlkx_stat_err_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_err_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of blocks received with an error over the CCPI link while
                                                                 OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_err_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_err_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_err_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_ERR_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_ERR_CNT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010420ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_ERR_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_ERR_CNT(...) bdk_ocx_tlkx_stat_err_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_ERR_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_ERR_CNT(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_ERR_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_ERR_CNT(...) "OCX_TLKX_STAT_ERR_CNT"


/**
 * RSL - ocx_tlk#_stat_idle_cnt
 */
typedef union bdk_ocx_tlkx_stat_idle_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_idle_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of idle blocks transferred over the CCPI link while OCX_TLK(0..2)_STAT_CTL[ENABLE]
                                                                 has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_idle_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_idle_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_idle_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_IDLE_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_IDLE_CNT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010400ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_IDLE_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_IDLE_CNT(...) bdk_ocx_tlkx_stat_idle_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_IDLE_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_IDLE_CNT(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_IDLE_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_IDLE_CNT(...) "OCX_TLKX_STAT_IDLE_CNT"


/**
 * RSL - ocx_tlk#_stat_mat#_cnt
 */
typedef union bdk_ocx_tlkx_stat_matx_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_matx_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of packets that have matched OCX_TLK(a)_STAT_MATCH0 and have been transferred over
                                                                 the CCPI link while OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_matx_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_matx_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_matx_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_MATX_CNT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_MATX_CNT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 3)))
		return 0x000087E011010440ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_STAT_MATX_CNT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_MATX_CNT(...) bdk_ocx_tlkx_stat_matx_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_MATX_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_MATX_CNT(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_STAT_MATX_CNT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_STAT_MATX_CNT(...) "OCX_TLKX_STAT_MATX_CNT"


/**
 * RSL - ocx_tlk#_stat_match#
 */
typedef union bdk_ocx_tlkx_stat_matchx {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_matchx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t mask                        : 9;  /**< R/W - Setting these bits mask (really matches) the corresponding bit comparison for each packet. */
		uint64_t reserved_9_15               : 7;
		uint64_t cmd                         : 5;  /**< R/W - These bits are compared against the command for each packet sent over the link. If both
                                                                 the unmasked VC and CMD bits match then OCX_TLK(0..2)_STAT_MAT(0..3)_CNT is incremented. */
		uint64_t vc                          : 4;  /**< R/W - These bits are compared against the link VC number for each packet sent over the link. If
                                                                 both the unmasked VC and CMD bits match, then OCX_TLK(0..2)_STAT_MAT(0..3)_CNT is
                                                                 incremented. */
#else
		uint64_t vc                          : 4;
		uint64_t cmd                         : 5;
		uint64_t reserved_9_15               : 7;
		uint64_t mask                        : 9;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_matchx_s  cn88xx; */
	/* struct bdk_ocx_tlkx_stat_matchx_s  cn88xxp1; */
} bdk_ocx_tlkx_stat_matchx_t;

static inline uint64_t BDK_OCX_TLKX_STAT_MATCHX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_MATCHX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 3)))
		return 0x000087E011010080ull + (param1 & 3) * 0x2000ull + (param2 & 3) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_STAT_MATCHX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_MATCHX(...) bdk_ocx_tlkx_stat_matchx_t
#define bustype_BDK_OCX_TLKX_STAT_MATCHX(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_MATCHX(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_STAT_MATCHX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_STAT_MATCHX(...) "OCX_TLKX_STAT_MATCHX"


/**
 * RSL - ocx_tlk#_stat_retry_cnt
 */
typedef union bdk_ocx_tlkx_stat_retry_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_retry_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of data blocks repeated over the CCPI link while OCX_TLK(0..2)_STAT_CTL[ENABLE] has
                                                                 been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_retry_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_retry_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_retry_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_RETRY_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_RETRY_CNT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010418ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_RETRY_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_RETRY_CNT(...) bdk_ocx_tlkx_stat_retry_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_RETRY_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_RETRY_CNT(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_RETRY_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_RETRY_CNT(...) "OCX_TLKX_STAT_RETRY_CNT"


/**
 * RSL - ocx_tlk#_stat_sync_cnt
 */
typedef union bdk_ocx_tlkx_stat_sync_cnt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_sync_cnt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of sync (control) blocks transferred over the CCPI link while
                                                                 OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_sync_cnt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_sync_cnt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_sync_cnt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_SYNC_CNT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_SYNC_CNT(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010410ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STAT_SYNC_CNT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_SYNC_CNT(...) bdk_ocx_tlkx_stat_sync_cnt_t
#define bustype_BDK_OCX_TLKX_STAT_SYNC_CNT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_SYNC_CNT(p1) (p1)
#define arguments_BDK_OCX_TLKX_STAT_SYNC_CNT(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STAT_SYNC_CNT(...) "OCX_TLKX_STAT_SYNC_CNT"


/**
 * RSL - ocx_tlk#_stat_vc#_cmd
 */
typedef union bdk_ocx_tlkx_stat_vcx_cmd {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_vcx_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of commands on this VC that have been transfered over the CCPI link while
                                                                 OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. For VCs 6 through 13 the number of commands
                                                                 is equal to the number of packets. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_vcx_cmd_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_vcx_cmd_s cn88xxp1; */
} bdk_ocx_tlkx_stat_vcx_cmd_t;

static inline uint64_t BDK_OCX_TLKX_STAT_VCX_CMD(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_VCX_CMD(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 5)))
		return 0x000087E011010480ull + (param1 & 3) * 0x2000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_STAT_VCX_CMD", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_VCX_CMD(...) bdk_ocx_tlkx_stat_vcx_cmd_t
#define bustype_BDK_OCX_TLKX_STAT_VCX_CMD(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_VCX_CMD(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_STAT_VCX_CMD(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_STAT_VCX_CMD(...) "OCX_TLKX_STAT_VCX_CMD"


/**
 * RSL - ocx_tlk#_stat_vc#_con
 */
typedef union bdk_ocx_tlkx_stat_vcx_con {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_vcx_con_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of conflicts on this VC while OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. A
                                                                 conflict is indicated when a VC has one or more packets to send and no link credits are
                                                                 available. VC13 does not require credits so no conflicts are ever indicated (i.e. reads
                                                                 0). */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_vcx_con_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_vcx_con_s cn88xxp1; */
} bdk_ocx_tlkx_stat_vcx_con_t;

static inline uint64_t BDK_OCX_TLKX_STAT_VCX_CON(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_VCX_CON(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011010580ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_STAT_VCX_CON", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_VCX_CON(...) bdk_ocx_tlkx_stat_vcx_con_t
#define bustype_BDK_OCX_TLKX_STAT_VCX_CON(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_VCX_CON(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_STAT_VCX_CON(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_STAT_VCX_CON(...) "OCX_TLKX_STAT_VCX_CON"


/**
 * RSL - ocx_tlk#_stat_vc#_pkt
 */
typedef union bdk_ocx_tlkx_stat_vcx_pkt {
	uint64_t u;
	struct bdk_ocx_tlkx_stat_vcx_pkt_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t count                       : 64; /**< R/W - Number of packets on this VC that have been transferred over the CCPI link while
                                                                 OCX_TLK(0..2)_STAT_CTL[ENABLE] has been set. */
#else
		uint64_t count                       : 64;
#endif
	} s;
	/* struct bdk_ocx_tlkx_stat_vcx_pkt_s cn88xx; */
	/* struct bdk_ocx_tlkx_stat_vcx_pkt_s cn88xxp1; */
} bdk_ocx_tlkx_stat_vcx_pkt_t;

static inline uint64_t BDK_OCX_TLKX_STAT_VCX_PKT(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STAT_VCX_PKT(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 2)) && ((param2 <= 13)))
		return 0x000087E011010500ull + (param1 & 3) * 0x2000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_OCX_TLKX_STAT_VCX_PKT", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STAT_VCX_PKT(...) bdk_ocx_tlkx_stat_vcx_pkt_t
#define bustype_BDK_OCX_TLKX_STAT_VCX_PKT(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STAT_VCX_PKT(p1,p2) (p1)
#define arguments_BDK_OCX_TLKX_STAT_VCX_PKT(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_OCX_TLKX_STAT_VCX_PKT(...) "OCX_TLKX_STAT_VCX_PKT"


/**
 * RSL - ocx_tlk#_status
 */
typedef union bdk_ocx_tlkx_status {
	uint64_t u;
	struct bdk_ocx_tlkx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_56_63              : 8;
		uint64_t rply_fptr                   : 8;  /**< RO/H - Replay buffer last free pointer. */
		uint64_t tx_seq                      : 8;  /**< RO/H - Last block transmitted. */
		uint64_t rx_seq                      : 8;  /**< RO/H - Last block received. */
		uint64_t reserved_23_31              : 9;
		uint64_t ackcnt                      : 7;  /**< RO/H - Number of ACKs waiting to be transmitted. */
		uint64_t reserved_9_15               : 7;
		uint64_t drop                        : 1;  /**< RO/H - Link is dropping all requests. */
		uint64_t sm                          : 6;  /**< RO/H - Block state machine:
                                                                 Bit\<2\>: Req / Ack (Init or retry only).
                                                                 Bit\<3\>: Init.
                                                                 Bit\<4\>: Run.
                                                                 Bit\<5\>: Retry.
                                                                 Bit\<6\>: Replay.
                                                                 Bit\<7\>: Replay Pending. */
		uint64_t cnt                         : 2;  /**< RO/H - Block subcount. Should always increment 0,1,2,3,0.. except during TX PHY stall. */
#else
		uint64_t cnt                         : 2;
		uint64_t sm                          : 6;
		uint64_t drop                        : 1;
		uint64_t reserved_9_15               : 7;
		uint64_t ackcnt                      : 7;
		uint64_t reserved_23_31              : 9;
		uint64_t rx_seq                      : 8;
		uint64_t tx_seq                      : 8;
		uint64_t rply_fptr                   : 8;
		uint64_t reserved_56_63              : 8;
#endif
	} s;
	/* struct bdk_ocx_tlkx_status_s       cn88xx; */
	/* struct bdk_ocx_tlkx_status_s       cn88xxp1; */
} bdk_ocx_tlkx_status_t;

static inline uint64_t BDK_OCX_TLKX_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_TLKX_STATUS(unsigned long param1)
{
	if (((param1 <= 2)))
		return 0x000087E011010000ull + (param1 & 3) * 0x2000ull;
	csr_fatal("BDK_OCX_TLKX_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_OCX_TLKX_STATUS(...) bdk_ocx_tlkx_status_t
#define bustype_BDK_OCX_TLKX_STATUS(...) BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_TLKX_STATUS(p1) (p1)
#define arguments_BDK_OCX_TLKX_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_OCX_TLKX_STATUS(...) "OCX_TLKX_STATUS"


/**
 * RSL - ocx_win_cmd
 *
 * For diagnostic use only. This register is typically written by hardware after accesses to the
 * SLI_WIN_* registers. Contains the address, read size and write mask to used for the window
 * operation. Write data should be written first and placed in the OCX_WIN_WR_DATA register.
 * Writing this register starts the operation. A second write to this register while an operation
 * is in progress will stall.
 */
typedef union bdk_ocx_win_cmd {
	uint64_t u;
	struct bdk_ocx_win_cmd_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wr_mask                     : 8;  /**< R/W - Mask for the data to be written. When a bit is 1, the corresponding byte will be written.
                                                                 The values of this field must be contiguous and for 1, 2, 4, or 8 byte operations and
                                                                 aligned to operation size. A value of 0 will produce unpredictable results. Field is
                                                                 ignored during a read (LD_OP=1). */
		uint64_t reserved_54_55              : 2;
		uint64_t el                          : 2;  /**< R/W - Execution Level.  This field is used to supply the execution level of the generated load
                                                                 or store command. */
		uint64_t nsecure                     : 1;  /**< R/W - Non-secure mode.  Setting this bit causes the generated load or store command to be
                                                                 considered non-secure. */
		uint64_t ld_cmd                      : 2;  /**< R/W - The load command sent with the read:
                                                                 0x0 = Load 1-bytes.
                                                                 0x1 = Load 2-bytes.
                                                                 0x2 = Load 4-bytes.
                                                                 0x3 = Load 8-bytes. */
		uint64_t ld_op                       : 1;  /**< R/W - Operation Type 0=Store 1=Load operation. */
		uint64_t addr                        : 48; /**< R/W - The address used in both the load and store operations:
                                                                 \<47:46\> = Reserved.
                                                                 \<45:44\> = CCPI_ID.
                                                                 \<43:36\> = NCB_ID.
                                                                 \<35:0\>  = Address.

                                                                 When \<43:36\> NCB_ID is RSL (0x7E) address field is defined as:
                                                                 \<47:46\> = Reserved.
                                                                 \<45:44\> = CCPI_ID.
                                                                 \<43:36\> = 0x7E
                                                                 \<35:32\> = Reserved.
                                                                 \<31:24\> = RSL_ID.
                                                                 \<23:0\>  = RSL register offset.

                                                                 \<2:0\> are ignored in a store operation. */
#else
		uint64_t addr                        : 48;
		uint64_t ld_op                       : 1;
		uint64_t ld_cmd                      : 2;
		uint64_t nsecure                     : 1;
		uint64_t el                          : 2;
		uint64_t reserved_54_55              : 2;
		uint64_t wr_mask                     : 8;
#endif
	} s;
	/* struct bdk_ocx_win_cmd_s           cn88xx; */
	/* struct bdk_ocx_win_cmd_s           cn88xxp1; */
} bdk_ocx_win_cmd_t;

#define BDK_OCX_WIN_CMD BDK_OCX_WIN_CMD_FUNC()
static inline uint64_t BDK_OCX_WIN_CMD_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_WIN_CMD_FUNC(void)
{
	return 0x000087E011000048ull;
}
#define typedef_BDK_OCX_WIN_CMD bdk_ocx_win_cmd_t
#define bustype_BDK_OCX_WIN_CMD BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_WIN_CMD 0
#define arguments_BDK_OCX_WIN_CMD -1,-1,-1,-1
#define basename_BDK_OCX_WIN_CMD "OCX_WIN_CMD"


/**
 * RSL - ocx_win_rd_data
 *
 * For diagnostic use only. This register is the read response data associated with window
 * command. Reads all-ones until response is received.
 */
typedef union bdk_ocx_win_rd_data {
	uint64_t u;
	struct bdk_ocx_win_rd_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< RO/H - Read response data. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_ocx_win_rd_data_s       cn88xx; */
	/* struct bdk_ocx_win_rd_data_s       cn88xxp1; */
} bdk_ocx_win_rd_data_t;

#define BDK_OCX_WIN_RD_DATA BDK_OCX_WIN_RD_DATA_FUNC()
static inline uint64_t BDK_OCX_WIN_RD_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_WIN_RD_DATA_FUNC(void)
{
	return 0x000087E011000050ull;
}
#define typedef_BDK_OCX_WIN_RD_DATA bdk_ocx_win_rd_data_t
#define bustype_BDK_OCX_WIN_RD_DATA BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_WIN_RD_DATA 0
#define arguments_BDK_OCX_WIN_RD_DATA -1,-1,-1,-1
#define basename_BDK_OCX_WIN_RD_DATA "OCX_WIN_RD_DATA"


/**
 * RSL - ocx_win_timer
 *
 * Number of core clocks before untransmitted WIN request is dropped and interrupt is issued.
 *
 */
typedef union bdk_ocx_win_timer {
	uint64_t u;
	struct bdk_ocx_win_timer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t tout                        : 14; /**< R/W - Number of core clocks times four. */
		uint64_t tout1                       : 2;  /**< RO - Reserved as all-ones. */
#else
		uint64_t tout1                       : 2;
		uint64_t tout                        : 14;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_ocx_win_timer_s         cn88xx; */
	/* struct bdk_ocx_win_timer_s         cn88xxp1; */
} bdk_ocx_win_timer_t;

#define BDK_OCX_WIN_TIMER BDK_OCX_WIN_TIMER_FUNC()
static inline uint64_t BDK_OCX_WIN_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_WIN_TIMER_FUNC(void)
{
	return 0x000087E011000058ull;
}
#define typedef_BDK_OCX_WIN_TIMER bdk_ocx_win_timer_t
#define bustype_BDK_OCX_WIN_TIMER BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_WIN_TIMER 0
#define arguments_BDK_OCX_WIN_TIMER -1,-1,-1,-1
#define basename_BDK_OCX_WIN_TIMER "OCX_WIN_TIMER"


/**
 * RSL - ocx_win_wr_data
 *
 * For diagnostic use only. This register is typically written by hardware after accesses to the
 * SLI_WIN_WR_DATA register. Contains the data to write to the address located in the OCX_WIN_CMD
 * Register.
 */
typedef union bdk_ocx_win_wr_data {
	uint64_t u;
	struct bdk_ocx_win_wr_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t wr_data                     : 64; /**< R/W - The data to be written. */
#else
		uint64_t wr_data                     : 64;
#endif
	} s;
	/* struct bdk_ocx_win_wr_data_s       cn88xx; */
	/* struct bdk_ocx_win_wr_data_s       cn88xxp1; */
} bdk_ocx_win_wr_data_t;

#define BDK_OCX_WIN_WR_DATA BDK_OCX_WIN_WR_DATA_FUNC()
static inline uint64_t BDK_OCX_WIN_WR_DATA_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_OCX_WIN_WR_DATA_FUNC(void)
{
	return 0x000087E011000040ull;
}
#define typedef_BDK_OCX_WIN_WR_DATA bdk_ocx_win_wr_data_t
#define bustype_BDK_OCX_WIN_WR_DATA BDK_CSR_TYPE_RSL
#define busnum_BDK_OCX_WIN_WR_DATA 0
#define arguments_BDK_OCX_WIN_WR_DATA -1,-1,-1,-1
#define basename_BDK_OCX_WIN_WR_DATA "OCX_WIN_WR_DATA"

#endif /* __BDK_CSRS_OCX__ */

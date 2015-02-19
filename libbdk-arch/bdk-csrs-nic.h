#ifndef __BDK_CSRS_NIC__
#define __BDK_CSRS_NIC__
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
 * Cavium NIC.
 *
 * This file is auto generated. Do not edit.
 *
 */

#include <stdint.h>

extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));


/**
 * Enumeration NIC_CHAN_E
 *
 * NIC Channel Number Enumeration
 * Enumerates the values of NIC_CQE_RX_S[CHAN].
 */
enum nic_chan_e {
	NIC_CHAN_E_BGX0_PORT0_CH0 = 0x800,
	NIC_CHAN_E_BGX0_PORT0_CH1 = 0x801,
	NIC_CHAN_E_BGX0_PORT0_CH10 = 0x80a,
	NIC_CHAN_E_BGX0_PORT0_CH11 = 0x80b,
	NIC_CHAN_E_BGX0_PORT0_CH12 = 0x80c,
	NIC_CHAN_E_BGX0_PORT0_CH13 = 0x80d,
	NIC_CHAN_E_BGX0_PORT0_CH14 = 0x80e,
	NIC_CHAN_E_BGX0_PORT0_CH15 = 0x80f,
	NIC_CHAN_E_BGX0_PORT0_CH2 = 0x802,
	NIC_CHAN_E_BGX0_PORT0_CH3 = 0x803,
	NIC_CHAN_E_BGX0_PORT0_CH4 = 0x804,
	NIC_CHAN_E_BGX0_PORT0_CH5 = 0x805,
	NIC_CHAN_E_BGX0_PORT0_CH6 = 0x806,
	NIC_CHAN_E_BGX0_PORT0_CH7 = 0x807,
	NIC_CHAN_E_BGX0_PORT0_CH8 = 0x808,
	NIC_CHAN_E_BGX0_PORT0_CH9 = 0x809,
	NIC_CHAN_E_BGX0_PORT1_CH0 = 0x810,
	NIC_CHAN_E_BGX0_PORT1_CH1 = 0x811,
	NIC_CHAN_E_BGX0_PORT1_CH10 = 0x81a,
	NIC_CHAN_E_BGX0_PORT1_CH11 = 0x81b,
	NIC_CHAN_E_BGX0_PORT1_CH12 = 0x81c,
	NIC_CHAN_E_BGX0_PORT1_CH13 = 0x81d,
	NIC_CHAN_E_BGX0_PORT1_CH14 = 0x81e,
	NIC_CHAN_E_BGX0_PORT1_CH15 = 0x81f,
	NIC_CHAN_E_BGX0_PORT1_CH2 = 0x812,
	NIC_CHAN_E_BGX0_PORT1_CH3 = 0x813,
	NIC_CHAN_E_BGX0_PORT1_CH4 = 0x814,
	NIC_CHAN_E_BGX0_PORT1_CH5 = 0x815,
	NIC_CHAN_E_BGX0_PORT1_CH6 = 0x816,
	NIC_CHAN_E_BGX0_PORT1_CH7 = 0x817,
	NIC_CHAN_E_BGX0_PORT1_CH8 = 0x818,
	NIC_CHAN_E_BGX0_PORT1_CH9 = 0x819,
	NIC_CHAN_E_BGX0_PORT2_CH0 = 0x820,
	NIC_CHAN_E_BGX0_PORT2_CH1 = 0x821,
	NIC_CHAN_E_BGX0_PORT2_CH10 = 0x82a,
	NIC_CHAN_E_BGX0_PORT2_CH11 = 0x82b,
	NIC_CHAN_E_BGX0_PORT2_CH12 = 0x82c,
	NIC_CHAN_E_BGX0_PORT2_CH13 = 0x82d,
	NIC_CHAN_E_BGX0_PORT2_CH14 = 0x82e,
	NIC_CHAN_E_BGX0_PORT2_CH15 = 0x82f,
	NIC_CHAN_E_BGX0_PORT2_CH2 = 0x822,
	NIC_CHAN_E_BGX0_PORT2_CH3 = 0x823,
	NIC_CHAN_E_BGX0_PORT2_CH4 = 0x824,
	NIC_CHAN_E_BGX0_PORT2_CH5 = 0x825,
	NIC_CHAN_E_BGX0_PORT2_CH6 = 0x826,
	NIC_CHAN_E_BGX0_PORT2_CH7 = 0x827,
	NIC_CHAN_E_BGX0_PORT2_CH8 = 0x828,
	NIC_CHAN_E_BGX0_PORT2_CH9 = 0x829,
	NIC_CHAN_E_BGX0_PORT3_CH0 = 0x830,
	NIC_CHAN_E_BGX0_PORT3_CH1 = 0x831,
	NIC_CHAN_E_BGX0_PORT3_CH10 = 0x83a,
	NIC_CHAN_E_BGX0_PORT3_CH11 = 0x83b,
	NIC_CHAN_E_BGX0_PORT3_CH12 = 0x83c,
	NIC_CHAN_E_BGX0_PORT3_CH13 = 0x83d,
	NIC_CHAN_E_BGX0_PORT3_CH14 = 0x83e,
	NIC_CHAN_E_BGX0_PORT3_CH15 = 0x83f,
	NIC_CHAN_E_BGX0_PORT3_CH2 = 0x832,
	NIC_CHAN_E_BGX0_PORT3_CH3 = 0x833,
	NIC_CHAN_E_BGX0_PORT3_CH4 = 0x834,
	NIC_CHAN_E_BGX0_PORT3_CH5 = 0x835,
	NIC_CHAN_E_BGX0_PORT3_CH6 = 0x836,
	NIC_CHAN_E_BGX0_PORT3_CH7 = 0x837,
	NIC_CHAN_E_BGX0_PORT3_CH8 = 0x838,
	NIC_CHAN_E_BGX0_PORT3_CH9 = 0x839,
	NIC_CHAN_E_BGX1_PORT0_CH0 = 0x900,
	NIC_CHAN_E_BGX1_PORT0_CH1 = 0x901,
	NIC_CHAN_E_BGX1_PORT0_CH10 = 0x90a,
	NIC_CHAN_E_BGX1_PORT0_CH11 = 0x90b,
	NIC_CHAN_E_BGX1_PORT0_CH12 = 0x90c,
	NIC_CHAN_E_BGX1_PORT0_CH13 = 0x90d,
	NIC_CHAN_E_BGX1_PORT0_CH14 = 0x90e,
	NIC_CHAN_E_BGX1_PORT0_CH15 = 0x90f,
	NIC_CHAN_E_BGX1_PORT0_CH2 = 0x902,
	NIC_CHAN_E_BGX1_PORT0_CH3 = 0x903,
	NIC_CHAN_E_BGX1_PORT0_CH4 = 0x904,
	NIC_CHAN_E_BGX1_PORT0_CH5 = 0x905,
	NIC_CHAN_E_BGX1_PORT0_CH6 = 0x906,
	NIC_CHAN_E_BGX1_PORT0_CH7 = 0x907,
	NIC_CHAN_E_BGX1_PORT0_CH8 = 0x908,
	NIC_CHAN_E_BGX1_PORT0_CH9 = 0x909,
	NIC_CHAN_E_BGX1_PORT1_CH0 = 0x910,
	NIC_CHAN_E_BGX1_PORT1_CH1 = 0x911,
	NIC_CHAN_E_BGX1_PORT1_CH10 = 0x91a,
	NIC_CHAN_E_BGX1_PORT1_CH11 = 0x91b,
	NIC_CHAN_E_BGX1_PORT1_CH12 = 0x91c,
	NIC_CHAN_E_BGX1_PORT1_CH13 = 0x91d,
	NIC_CHAN_E_BGX1_PORT1_CH14 = 0x91e,
	NIC_CHAN_E_BGX1_PORT1_CH15 = 0x91f,
	NIC_CHAN_E_BGX1_PORT1_CH2 = 0x912,
	NIC_CHAN_E_BGX1_PORT1_CH3 = 0x913,
	NIC_CHAN_E_BGX1_PORT1_CH4 = 0x914,
	NIC_CHAN_E_BGX1_PORT1_CH5 = 0x915,
	NIC_CHAN_E_BGX1_PORT1_CH6 = 0x916,
	NIC_CHAN_E_BGX1_PORT1_CH7 = 0x917,
	NIC_CHAN_E_BGX1_PORT1_CH8 = 0x918,
	NIC_CHAN_E_BGX1_PORT1_CH9 = 0x919,
	NIC_CHAN_E_BGX1_PORT2_CH0 = 0x920,
	NIC_CHAN_E_BGX1_PORT2_CH1 = 0x921,
	NIC_CHAN_E_BGX1_PORT2_CH10 = 0x92a,
	NIC_CHAN_E_BGX1_PORT2_CH11 = 0x92b,
	NIC_CHAN_E_BGX1_PORT2_CH12 = 0x92c,
	NIC_CHAN_E_BGX1_PORT2_CH13 = 0x92d,
	NIC_CHAN_E_BGX1_PORT2_CH14 = 0x92e,
	NIC_CHAN_E_BGX1_PORT2_CH15 = 0x92f,
	NIC_CHAN_E_BGX1_PORT2_CH2 = 0x922,
	NIC_CHAN_E_BGX1_PORT2_CH3 = 0x923,
	NIC_CHAN_E_BGX1_PORT2_CH4 = 0x924,
	NIC_CHAN_E_BGX1_PORT2_CH5 = 0x925,
	NIC_CHAN_E_BGX1_PORT2_CH6 = 0x926,
	NIC_CHAN_E_BGX1_PORT2_CH7 = 0x927,
	NIC_CHAN_E_BGX1_PORT2_CH8 = 0x928,
	NIC_CHAN_E_BGX1_PORT2_CH9 = 0x929,
	NIC_CHAN_E_BGX1_PORT3_CH0 = 0x930,
	NIC_CHAN_E_BGX1_PORT3_CH1 = 0x931,
	NIC_CHAN_E_BGX1_PORT3_CH10 = 0x93a,
	NIC_CHAN_E_BGX1_PORT3_CH11 = 0x93b,
	NIC_CHAN_E_BGX1_PORT3_CH12 = 0x93c,
	NIC_CHAN_E_BGX1_PORT3_CH13 = 0x93d,
	NIC_CHAN_E_BGX1_PORT3_CH14 = 0x93e,
	NIC_CHAN_E_BGX1_PORT3_CH15 = 0x93f,
	NIC_CHAN_E_BGX1_PORT3_CH2 = 0x932,
	NIC_CHAN_E_BGX1_PORT3_CH3 = 0x933,
	NIC_CHAN_E_BGX1_PORT3_CH4 = 0x934,
	NIC_CHAN_E_BGX1_PORT3_CH5 = 0x935,
	NIC_CHAN_E_BGX1_PORT3_CH6 = 0x936,
	NIC_CHAN_E_BGX1_PORT3_CH7 = 0x937,
	NIC_CHAN_E_BGX1_PORT3_CH8 = 0x938,
	NIC_CHAN_E_BGX1_PORT3_CH9 = 0x939,
	NIC_CHAN_E_TNS_PORT0_CH0 = 0x600,
	NIC_CHAN_E_TNS_PORT0_CH1 = 0x601,
	NIC_CHAN_E_TNS_PORT0_CH10 = 0x60a,
	NIC_CHAN_E_TNS_PORT0_CH100 = 0x664,
	NIC_CHAN_E_TNS_PORT0_CH101 = 0x665,
	NIC_CHAN_E_TNS_PORT0_CH102 = 0x666,
	NIC_CHAN_E_TNS_PORT0_CH103 = 0x667,
	NIC_CHAN_E_TNS_PORT0_CH104 = 0x668,
	NIC_CHAN_E_TNS_PORT0_CH105 = 0x669,
	NIC_CHAN_E_TNS_PORT0_CH106 = 0x66a,
	NIC_CHAN_E_TNS_PORT0_CH107 = 0x66b,
	NIC_CHAN_E_TNS_PORT0_CH108 = 0x66c,
	NIC_CHAN_E_TNS_PORT0_CH109 = 0x66d,
	NIC_CHAN_E_TNS_PORT0_CH11 = 0x60b,
	NIC_CHAN_E_TNS_PORT0_CH110 = 0x66e,
	NIC_CHAN_E_TNS_PORT0_CH111 = 0x66f,
	NIC_CHAN_E_TNS_PORT0_CH112 = 0x670,
	NIC_CHAN_E_TNS_PORT0_CH113 = 0x671,
	NIC_CHAN_E_TNS_PORT0_CH114 = 0x672,
	NIC_CHAN_E_TNS_PORT0_CH115 = 0x673,
	NIC_CHAN_E_TNS_PORT0_CH116 = 0x674,
	NIC_CHAN_E_TNS_PORT0_CH117 = 0x675,
	NIC_CHAN_E_TNS_PORT0_CH118 = 0x676,
	NIC_CHAN_E_TNS_PORT0_CH119 = 0x677,
	NIC_CHAN_E_TNS_PORT0_CH12 = 0x60c,
	NIC_CHAN_E_TNS_PORT0_CH120 = 0x678,
	NIC_CHAN_E_TNS_PORT0_CH121 = 0x679,
	NIC_CHAN_E_TNS_PORT0_CH122 = 0x67a,
	NIC_CHAN_E_TNS_PORT0_CH123 = 0x67b,
	NIC_CHAN_E_TNS_PORT0_CH124 = 0x67c,
	NIC_CHAN_E_TNS_PORT0_CH125 = 0x67d,
	NIC_CHAN_E_TNS_PORT0_CH126 = 0x67e,
	NIC_CHAN_E_TNS_PORT0_CH127 = 0x67f,
	NIC_CHAN_E_TNS_PORT0_CH13 = 0x60d,
	NIC_CHAN_E_TNS_PORT0_CH14 = 0x60e,
	NIC_CHAN_E_TNS_PORT0_CH15 = 0x60f,
	NIC_CHAN_E_TNS_PORT0_CH16 = 0x610,
	NIC_CHAN_E_TNS_PORT0_CH17 = 0x611,
	NIC_CHAN_E_TNS_PORT0_CH18 = 0x612,
	NIC_CHAN_E_TNS_PORT0_CH19 = 0x613,
	NIC_CHAN_E_TNS_PORT0_CH2 = 0x602,
	NIC_CHAN_E_TNS_PORT0_CH20 = 0x614,
	NIC_CHAN_E_TNS_PORT0_CH21 = 0x615,
	NIC_CHAN_E_TNS_PORT0_CH22 = 0x616,
	NIC_CHAN_E_TNS_PORT0_CH23 = 0x617,
	NIC_CHAN_E_TNS_PORT0_CH24 = 0x618,
	NIC_CHAN_E_TNS_PORT0_CH25 = 0x619,
	NIC_CHAN_E_TNS_PORT0_CH26 = 0x61a,
	NIC_CHAN_E_TNS_PORT0_CH27 = 0x61b,
	NIC_CHAN_E_TNS_PORT0_CH28 = 0x61c,
	NIC_CHAN_E_TNS_PORT0_CH29 = 0x61d,
	NIC_CHAN_E_TNS_PORT0_CH3 = 0x603,
	NIC_CHAN_E_TNS_PORT0_CH30 = 0x61e,
	NIC_CHAN_E_TNS_PORT0_CH31 = 0x61f,
	NIC_CHAN_E_TNS_PORT0_CH32 = 0x620,
	NIC_CHAN_E_TNS_PORT0_CH33 = 0x621,
	NIC_CHAN_E_TNS_PORT0_CH34 = 0x622,
	NIC_CHAN_E_TNS_PORT0_CH35 = 0x623,
	NIC_CHAN_E_TNS_PORT0_CH36 = 0x624,
	NIC_CHAN_E_TNS_PORT0_CH37 = 0x625,
	NIC_CHAN_E_TNS_PORT0_CH38 = 0x626,
	NIC_CHAN_E_TNS_PORT0_CH39 = 0x627,
	NIC_CHAN_E_TNS_PORT0_CH4 = 0x604,
	NIC_CHAN_E_TNS_PORT0_CH40 = 0x628,
	NIC_CHAN_E_TNS_PORT0_CH41 = 0x629,
	NIC_CHAN_E_TNS_PORT0_CH42 = 0x62a,
	NIC_CHAN_E_TNS_PORT0_CH43 = 0x62b,
	NIC_CHAN_E_TNS_PORT0_CH44 = 0x62c,
	NIC_CHAN_E_TNS_PORT0_CH45 = 0x62d,
	NIC_CHAN_E_TNS_PORT0_CH46 = 0x62e,
	NIC_CHAN_E_TNS_PORT0_CH47 = 0x62f,
	NIC_CHAN_E_TNS_PORT0_CH48 = 0x630,
	NIC_CHAN_E_TNS_PORT0_CH49 = 0x631,
	NIC_CHAN_E_TNS_PORT0_CH5 = 0x605,
	NIC_CHAN_E_TNS_PORT0_CH50 = 0x632,
	NIC_CHAN_E_TNS_PORT0_CH51 = 0x633,
	NIC_CHAN_E_TNS_PORT0_CH52 = 0x634,
	NIC_CHAN_E_TNS_PORT0_CH53 = 0x635,
	NIC_CHAN_E_TNS_PORT0_CH54 = 0x636,
	NIC_CHAN_E_TNS_PORT0_CH55 = 0x637,
	NIC_CHAN_E_TNS_PORT0_CH56 = 0x638,
	NIC_CHAN_E_TNS_PORT0_CH57 = 0x639,
	NIC_CHAN_E_TNS_PORT0_CH58 = 0x63a,
	NIC_CHAN_E_TNS_PORT0_CH59 = 0x63b,
	NIC_CHAN_E_TNS_PORT0_CH6 = 0x606,
	NIC_CHAN_E_TNS_PORT0_CH60 = 0x63c,
	NIC_CHAN_E_TNS_PORT0_CH61 = 0x63d,
	NIC_CHAN_E_TNS_PORT0_CH62 = 0x63e,
	NIC_CHAN_E_TNS_PORT0_CH63 = 0x63f,
	NIC_CHAN_E_TNS_PORT0_CH64 = 0x640,
	NIC_CHAN_E_TNS_PORT0_CH65 = 0x641,
	NIC_CHAN_E_TNS_PORT0_CH66 = 0x642,
	NIC_CHAN_E_TNS_PORT0_CH67 = 0x643,
	NIC_CHAN_E_TNS_PORT0_CH68 = 0x644,
	NIC_CHAN_E_TNS_PORT0_CH69 = 0x645,
	NIC_CHAN_E_TNS_PORT0_CH7 = 0x607,
	NIC_CHAN_E_TNS_PORT0_CH70 = 0x646,
	NIC_CHAN_E_TNS_PORT0_CH71 = 0x647,
	NIC_CHAN_E_TNS_PORT0_CH72 = 0x648,
	NIC_CHAN_E_TNS_PORT0_CH73 = 0x649,
	NIC_CHAN_E_TNS_PORT0_CH74 = 0x64a,
	NIC_CHAN_E_TNS_PORT0_CH75 = 0x64b,
	NIC_CHAN_E_TNS_PORT0_CH76 = 0x64c,
	NIC_CHAN_E_TNS_PORT0_CH77 = 0x64d,
	NIC_CHAN_E_TNS_PORT0_CH78 = 0x64e,
	NIC_CHAN_E_TNS_PORT0_CH79 = 0x64f,
	NIC_CHAN_E_TNS_PORT0_CH8 = 0x608,
	NIC_CHAN_E_TNS_PORT0_CH80 = 0x650,
	NIC_CHAN_E_TNS_PORT0_CH81 = 0x651,
	NIC_CHAN_E_TNS_PORT0_CH82 = 0x652,
	NIC_CHAN_E_TNS_PORT0_CH83 = 0x653,
	NIC_CHAN_E_TNS_PORT0_CH84 = 0x654,
	NIC_CHAN_E_TNS_PORT0_CH85 = 0x655,
	NIC_CHAN_E_TNS_PORT0_CH86 = 0x656,
	NIC_CHAN_E_TNS_PORT0_CH87 = 0x657,
	NIC_CHAN_E_TNS_PORT0_CH88 = 0x658,
	NIC_CHAN_E_TNS_PORT0_CH89 = 0x659,
	NIC_CHAN_E_TNS_PORT0_CH9 = 0x609,
	NIC_CHAN_E_TNS_PORT0_CH90 = 0x65a,
	NIC_CHAN_E_TNS_PORT0_CH91 = 0x65b,
	NIC_CHAN_E_TNS_PORT0_CH92 = 0x65c,
	NIC_CHAN_E_TNS_PORT0_CH93 = 0x65d,
	NIC_CHAN_E_TNS_PORT0_CH94 = 0x65e,
	NIC_CHAN_E_TNS_PORT0_CH95 = 0x65f,
	NIC_CHAN_E_TNS_PORT0_CH96 = 0x660,
	NIC_CHAN_E_TNS_PORT0_CH97 = 0x661,
	NIC_CHAN_E_TNS_PORT0_CH98 = 0x662,
	NIC_CHAN_E_TNS_PORT0_CH99 = 0x663,
	NIC_CHAN_E_TNS_PORT1_CH0 = 0x700,
	NIC_CHAN_E_TNS_PORT1_CH1 = 0x701,
	NIC_CHAN_E_TNS_PORT1_CH10 = 0x70a,
	NIC_CHAN_E_TNS_PORT1_CH100 = 0x764,
	NIC_CHAN_E_TNS_PORT1_CH101 = 0x765,
	NIC_CHAN_E_TNS_PORT1_CH102 = 0x766,
	NIC_CHAN_E_TNS_PORT1_CH103 = 0x767,
	NIC_CHAN_E_TNS_PORT1_CH104 = 0x768,
	NIC_CHAN_E_TNS_PORT1_CH105 = 0x769,
	NIC_CHAN_E_TNS_PORT1_CH106 = 0x76a,
	NIC_CHAN_E_TNS_PORT1_CH107 = 0x76b,
	NIC_CHAN_E_TNS_PORT1_CH108 = 0x76c,
	NIC_CHAN_E_TNS_PORT1_CH109 = 0x76d,
	NIC_CHAN_E_TNS_PORT1_CH11 = 0x70b,
	NIC_CHAN_E_TNS_PORT1_CH110 = 0x76e,
	NIC_CHAN_E_TNS_PORT1_CH111 = 0x76f,
	NIC_CHAN_E_TNS_PORT1_CH112 = 0x770,
	NIC_CHAN_E_TNS_PORT1_CH113 = 0x771,
	NIC_CHAN_E_TNS_PORT1_CH114 = 0x772,
	NIC_CHAN_E_TNS_PORT1_CH115 = 0x773,
	NIC_CHAN_E_TNS_PORT1_CH116 = 0x774,
	NIC_CHAN_E_TNS_PORT1_CH117 = 0x775,
	NIC_CHAN_E_TNS_PORT1_CH118 = 0x776,
	NIC_CHAN_E_TNS_PORT1_CH119 = 0x777,
	NIC_CHAN_E_TNS_PORT1_CH12 = 0x70c,
	NIC_CHAN_E_TNS_PORT1_CH120 = 0x778,
	NIC_CHAN_E_TNS_PORT1_CH121 = 0x779,
	NIC_CHAN_E_TNS_PORT1_CH122 = 0x77a,
	NIC_CHAN_E_TNS_PORT1_CH123 = 0x77b,
	NIC_CHAN_E_TNS_PORT1_CH124 = 0x77c,
	NIC_CHAN_E_TNS_PORT1_CH125 = 0x77d,
	NIC_CHAN_E_TNS_PORT1_CH126 = 0x77e,
	NIC_CHAN_E_TNS_PORT1_CH127 = 0x77f,
	NIC_CHAN_E_TNS_PORT1_CH13 = 0x70d,
	NIC_CHAN_E_TNS_PORT1_CH14 = 0x70e,
	NIC_CHAN_E_TNS_PORT1_CH15 = 0x70f,
	NIC_CHAN_E_TNS_PORT1_CH16 = 0x710,
	NIC_CHAN_E_TNS_PORT1_CH17 = 0x711,
	NIC_CHAN_E_TNS_PORT1_CH18 = 0x712,
	NIC_CHAN_E_TNS_PORT1_CH19 = 0x713,
	NIC_CHAN_E_TNS_PORT1_CH2 = 0x702,
	NIC_CHAN_E_TNS_PORT1_CH20 = 0x714,
	NIC_CHAN_E_TNS_PORT1_CH21 = 0x715,
	NIC_CHAN_E_TNS_PORT1_CH22 = 0x716,
	NIC_CHAN_E_TNS_PORT1_CH23 = 0x717,
	NIC_CHAN_E_TNS_PORT1_CH24 = 0x718,
	NIC_CHAN_E_TNS_PORT1_CH25 = 0x719,
	NIC_CHAN_E_TNS_PORT1_CH26 = 0x71a,
	NIC_CHAN_E_TNS_PORT1_CH27 = 0x71b,
	NIC_CHAN_E_TNS_PORT1_CH28 = 0x71c,
	NIC_CHAN_E_TNS_PORT1_CH29 = 0x71d,
	NIC_CHAN_E_TNS_PORT1_CH3 = 0x703,
	NIC_CHAN_E_TNS_PORT1_CH30 = 0x71e,
	NIC_CHAN_E_TNS_PORT1_CH31 = 0x71f,
	NIC_CHAN_E_TNS_PORT1_CH32 = 0x720,
	NIC_CHAN_E_TNS_PORT1_CH33 = 0x721,
	NIC_CHAN_E_TNS_PORT1_CH34 = 0x722,
	NIC_CHAN_E_TNS_PORT1_CH35 = 0x723,
	NIC_CHAN_E_TNS_PORT1_CH36 = 0x724,
	NIC_CHAN_E_TNS_PORT1_CH37 = 0x725,
	NIC_CHAN_E_TNS_PORT1_CH38 = 0x726,
	NIC_CHAN_E_TNS_PORT1_CH39 = 0x727,
	NIC_CHAN_E_TNS_PORT1_CH4 = 0x704,
	NIC_CHAN_E_TNS_PORT1_CH40 = 0x728,
	NIC_CHAN_E_TNS_PORT1_CH41 = 0x729,
	NIC_CHAN_E_TNS_PORT1_CH42 = 0x72a,
	NIC_CHAN_E_TNS_PORT1_CH43 = 0x72b,
	NIC_CHAN_E_TNS_PORT1_CH44 = 0x72c,
	NIC_CHAN_E_TNS_PORT1_CH45 = 0x72d,
	NIC_CHAN_E_TNS_PORT1_CH46 = 0x72e,
	NIC_CHAN_E_TNS_PORT1_CH47 = 0x72f,
	NIC_CHAN_E_TNS_PORT1_CH48 = 0x730,
	NIC_CHAN_E_TNS_PORT1_CH49 = 0x731,
	NIC_CHAN_E_TNS_PORT1_CH5 = 0x705,
	NIC_CHAN_E_TNS_PORT1_CH50 = 0x732,
	NIC_CHAN_E_TNS_PORT1_CH51 = 0x733,
	NIC_CHAN_E_TNS_PORT1_CH52 = 0x734,
	NIC_CHAN_E_TNS_PORT1_CH53 = 0x735,
	NIC_CHAN_E_TNS_PORT1_CH54 = 0x736,
	NIC_CHAN_E_TNS_PORT1_CH55 = 0x737,
	NIC_CHAN_E_TNS_PORT1_CH56 = 0x738,
	NIC_CHAN_E_TNS_PORT1_CH57 = 0x739,
	NIC_CHAN_E_TNS_PORT1_CH58 = 0x73a,
	NIC_CHAN_E_TNS_PORT1_CH59 = 0x73b,
	NIC_CHAN_E_TNS_PORT1_CH6 = 0x706,
	NIC_CHAN_E_TNS_PORT1_CH60 = 0x73c,
	NIC_CHAN_E_TNS_PORT1_CH61 = 0x73d,
	NIC_CHAN_E_TNS_PORT1_CH62 = 0x73e,
	NIC_CHAN_E_TNS_PORT1_CH63 = 0x73f,
	NIC_CHAN_E_TNS_PORT1_CH64 = 0x740,
	NIC_CHAN_E_TNS_PORT1_CH65 = 0x741,
	NIC_CHAN_E_TNS_PORT1_CH66 = 0x742,
	NIC_CHAN_E_TNS_PORT1_CH67 = 0x743,
	NIC_CHAN_E_TNS_PORT1_CH68 = 0x744,
	NIC_CHAN_E_TNS_PORT1_CH69 = 0x745,
	NIC_CHAN_E_TNS_PORT1_CH7 = 0x707,
	NIC_CHAN_E_TNS_PORT1_CH70 = 0x746,
	NIC_CHAN_E_TNS_PORT1_CH71 = 0x747,
	NIC_CHAN_E_TNS_PORT1_CH72 = 0x748,
	NIC_CHAN_E_TNS_PORT1_CH73 = 0x749,
	NIC_CHAN_E_TNS_PORT1_CH74 = 0x74a,
	NIC_CHAN_E_TNS_PORT1_CH75 = 0x74b,
	NIC_CHAN_E_TNS_PORT1_CH76 = 0x74c,
	NIC_CHAN_E_TNS_PORT1_CH77 = 0x74d,
	NIC_CHAN_E_TNS_PORT1_CH78 = 0x74e,
	NIC_CHAN_E_TNS_PORT1_CH79 = 0x74f,
	NIC_CHAN_E_TNS_PORT1_CH8 = 0x708,
	NIC_CHAN_E_TNS_PORT1_CH80 = 0x750,
	NIC_CHAN_E_TNS_PORT1_CH81 = 0x751,
	NIC_CHAN_E_TNS_PORT1_CH82 = 0x752,
	NIC_CHAN_E_TNS_PORT1_CH83 = 0x753,
	NIC_CHAN_E_TNS_PORT1_CH84 = 0x754,
	NIC_CHAN_E_TNS_PORT1_CH85 = 0x755,
	NIC_CHAN_E_TNS_PORT1_CH86 = 0x756,
	NIC_CHAN_E_TNS_PORT1_CH87 = 0x757,
	NIC_CHAN_E_TNS_PORT1_CH88 = 0x758,
	NIC_CHAN_E_TNS_PORT1_CH89 = 0x759,
	NIC_CHAN_E_TNS_PORT1_CH9 = 0x709,
	NIC_CHAN_E_TNS_PORT1_CH90 = 0x75a,
	NIC_CHAN_E_TNS_PORT1_CH91 = 0x75b,
	NIC_CHAN_E_TNS_PORT1_CH92 = 0x75c,
	NIC_CHAN_E_TNS_PORT1_CH93 = 0x75d,
	NIC_CHAN_E_TNS_PORT1_CH94 = 0x75e,
	NIC_CHAN_E_TNS_PORT1_CH95 = 0x75f,
	NIC_CHAN_E_TNS_PORT1_CH96 = 0x760,
	NIC_CHAN_E_TNS_PORT1_CH97 = 0x761,
	NIC_CHAN_E_TNS_PORT1_CH98 = 0x762,
	NIC_CHAN_E_TNS_PORT1_CH99 = 0x763,
	NIC_CHAN_E_ENUM_LAST = 0x940,
};

/**
 * Enumeration NIC_CPI_ALG_E
 *
 * NIC CPI Algorithm Enumeration
 * Enumerates the values of NIC_PF_CHAN()_RX_CFG[CPI_ALG].
 */
enum nic_cpi_alg_e {
	NIC_CPI_ALG_E_DIFF = 0x3,
	NIC_CPI_ALG_E_NONE = 0x0,
	NIC_CPI_ALG_E_VLAN = 0x1,
	NIC_CPI_ALG_E_VLAN16 = 0x2,
	NIC_CPI_ALG_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NIC_CQE_SEND_STATUS_E
 *
 * NIC CQE Send Status Enumeration
 * Enumerates send status codes for NIC_CQE_SEND_S[SEND_STATUS].
 */
enum nic_cqe_send_status_e {
	NIC_CQE_SEND_STATUS_E_CK_OFLOW = 0x89,
	NIC_CQE_SEND_STATUS_E_CK_OVERLAP = 0x88,
	NIC_CQE_SEND_STATUS_E_DATA_FAULT = 0x84,
	NIC_CQE_SEND_STATUS_E_DATA_SEQUENCE_ERR = 0x81,
	NIC_CQE_SEND_STATUS_E_DESC_FAULT = 0x10,
	NIC_CQE_SEND_STATUS_E_GOOD = 0x0,
	NIC_CQE_SEND_STATUS_E_HDR_CONS_ERR = 0x11,
	NIC_CQE_SEND_STATUS_E_IMM_SIZE_OFLOW = 0x80,
	NIC_CQE_SEND_STATUS_E_LOCK_VIOL = 0x83,
	NIC_CQE_SEND_STATUS_E_MAX_SIZE_VIOL = 0x13,
	NIC_CQE_SEND_STATUS_E_MEM_FAULT = 0x87,
	NIC_CQE_SEND_STATUS_E_MEM_SEQUENCE_ERR = 0x82,
	NIC_CQE_SEND_STATUS_E_SUBDC_ERR = 0x12,
	NIC_CQE_SEND_STATUS_E_TSTMP_CONFLICT = 0x85,
	NIC_CQE_SEND_STATUS_E_TSTMP_TIMEOUT = 0x86,
	NIC_CQE_SEND_STATUS_E_ENUM_LAST = 0x8a,
};

/**
 * Enumeration NIC_CQE_TYPE_E
 *
 * NIC Completion-Queue Entry Type Enumeration
 * Enumerates CQE types, e.g. see NIC_CQE_SEND_S[CQE_TYPE].
 */
enum nic_cqe_type_e {
	NIC_CQE_TYPE_E_INVALID = 0x0,
	NIC_CQE_TYPE_E_RX = 0x2,
	NIC_CQE_TYPE_E_RX_SPLT = 0x3,
	NIC_CQE_TYPE_E_SEND = 0x8,
	NIC_CQE_TYPE_E_SEND_PTP = 0x9,
	NIC_CQE_TYPE_E_ENUM_LAST = 0xa,
};

/**
 * Enumeration NIC_ERRLEV_E
 *
 * NIC Error Level Enumeration
 * Enumerates the values of
 * NIC_CQE_RX_S[ERRLEV].
 */
enum nic_errlev_e {
	NIC_ERRLEV_E_L2 = 0x1,
	NIC_ERRLEV_E_L3 = 0x2,
	NIC_ERRLEV_E_L4 = 0x3,
	NIC_ERRLEV_E_LE = 0x4,
	NIC_ERRLEV_E_LF = 0x5,
	NIC_ERRLEV_E_RE = 0x0,
	NIC_ERRLEV_E_ENUM_LAST = 0x6,
};

/**
 * Enumeration NIC_ERROP_E
 *
 * NIC Error Opcode Enumeration
 * Enumerates the values of
 * NIC_CQE_RX_S[ERROP].
 */
enum nic_errop_e {
	NIC_ERROP_E_IP_CHK = 0x42,
	NIC_ERROP_E_IP_HOP = 0x45,
	NIC_ERROP_E_IP_MAL = 0x43,
	NIC_ERROP_E_IP_MALD = 0x44,
	NIC_ERROP_E_IP_NOT = 0x41,
	NIC_ERROP_E_L2_FRAGMENT = 0x20,
	NIC_ERROP_E_L2_LENMISM = 0x27,
	NIC_ERROP_E_L2_MAL = 0x24,
	NIC_ERROP_E_L2_OVERRUN = 0x21,
	NIC_ERROP_E_L2_OVERSIZE = 0x25,
	NIC_ERROP_E_L2_PCLP = 0x28,
	NIC_ERROP_E_L2_PFCS = 0x22,
	NIC_ERROP_E_L2_PUNY = 0x23,
	NIC_ERROP_E_L2_UNDERSIZE = 0x26,
	NIC_ERROP_E_L3_ICRC = 0x46,
	NIC_ERROP_E_L3_PCLP = 0x47,
	NIC_ERROP_E_L4_CHK = 0x62,
	NIC_ERROP_E_L4_MAL = 0x61,
	NIC_ERROP_E_L4_PCLP = 0x67,
	NIC_ERROP_E_L4_PORT = 0x64,
	NIC_ERROP_E_PREL2_ERR = 0x1f,
	NIC_ERROP_E_RBDR_TRUNC = 0x70,
	NIC_ERROP_E_RE_FCS = 0x7,
	NIC_ERROP_E_RE_JABBER = 0x2,
	NIC_ERROP_E_RE_NONE = 0x0,
	NIC_ERROP_E_RE_PARTIAL = 0x1,
	NIC_ERROP_E_RE_RX_CTL = 0xb,
	NIC_ERROP_E_RE_TERMINATE = 0x9,
	NIC_ERROP_E_TCP_FLAG = 0x65,
	NIC_ERROP_E_TCP_OFFSET = 0x66,
	NIC_ERROP_E_UDP_LEN = 0x63,
	NIC_ERROP_E_ENUM_LAST = 0x71,
};

/**
 * Enumeration NIC_ETHERTYPE_E
 *
 * NIC Ethertypes Enumeration
 * Enumerates the standard Ethertype values.
 */
enum nic_ethertype_e {
	NIC_ETHERTYPE_E_ARP = 0x806,
	NIC_ETHERTYPE_E_CNM = 0x22e9,
	NIC_ETHERTYPE_E_IP = 0x800,
	NIC_ETHERTYPE_E_IP6 = 0x86dd,
	NIC_ETHERTYPE_E_MPLS_8847 = 0x8847,
	NIC_ETHERTYPE_E_MPLS_8848 = 0x8848,
	NIC_ETHERTYPE_E_REVARP = 0x8035,
	NIC_ETHERTYPE_E_ROCE = 0x8915,
	NIC_ETHERTYPE_E_VLAN = 0x8100,
	NIC_ETHERTYPE_E_VLAN_88A8 = 0x88a8,
	NIC_ETHERTYPE_E_VLAN_9100 = 0x9100,
	NIC_ETHERTYPE_E_VLAN_9200 = 0x9200,
	NIC_ETHERTYPE_E_VLAN_9300 = 0x9300,
	NIC_ETHERTYPE_E_ENUM_LAST = 0x9301,
};

/**
 * Enumeration NIC_ETYPE_ALG_E
 *
 * NIC Ethertype Algorithm Enumeration
 * Enumerates the values of NIC_PF_RX_ETYPE()[ALG].
 */
enum nic_etype_alg_e {
	NIC_ETYPE_ALG_E_ENDPARSE = 0x2,
	NIC_ETYPE_ALG_E_NONE = 0x0,
	NIC_ETYPE_ALG_E_SKIP = 0x1,
	NIC_ETYPE_ALG_E_VLAN = 0x3,
	NIC_ETYPE_ALG_E_VLAN_STRIP = 0x4,
	NIC_ETYPE_ALG_E_ENUM_LAST = 0x5,
};

/**
 * Enumeration NIC_INTF_BLOCK_E
 *
 * NIC Interface Block ID Enumeration
 * Enumerates the values of NIC_PF_INTF()_SEND_CFG[BLOCK] and NIC_PF_INTF()_BP_CFG[BP_ID].
 */
enum nic_intf_block_e {
	NIC_INTF_BLOCK_E_BGX0_BLOCK = 0x8,
	NIC_INTF_BLOCK_E_BGX1_BLOCK = 0x9,
	NIC_INTF_BLOCK_E_TNS_PORT0_BLOCK = 0x6,
	NIC_INTF_BLOCK_E_TNS_PORT1_BLOCK = 0x7,
	NIC_INTF_BLOCK_E_ENUM_LAST = 0xa,
};

/**
 * Enumeration NIC_IPPROTO_E
 *
 * NIC IP Protocol Enumeration
 * Enumerates the IPv4 protocol and IPv6 next-header values.
 */
enum nic_ipproto_e {
	NIC_IPPROTO_E_AH = 0x33,
	NIC_IPPROTO_E_DEST = 0x3c,
	NIC_IPPROTO_E_ESP = 0x32,
	NIC_IPPROTO_E_FRAG = 0x2c,
	NIC_IPPROTO_E_GRE = 0x2f,
	NIC_IPPROTO_E_HOP_BY_HOP = 0x0,
	NIC_IPPROTO_E_IP4 = 0x4,
	NIC_IPPROTO_E_IP6 = 0x29,
	NIC_IPPROTO_E_IPCOMP = 0x6c,
	NIC_IPPROTO_E_ROUTING = 0x2b,
	NIC_IPPROTO_E_TCP = 0x6,
	NIC_IPPROTO_E_UDP = 0x11,
	NIC_IPPROTO_E_ENUM_LAST = 0x6d,
};

/**
 * Enumeration NIC_L3TYPE_E
 *
 * NIC Layer 3 Type Enumeration
 * Enumerates the values of
 * NIC_CQE_RX_S[L3TY].
 */
enum nic_l3type_e {
	NIC_L3TYPE_E_ET_STOP = 0xd,
	NIC_L3TYPE_E_GRH = 0x1,
	NIC_L3TYPE_E_IP4 = 0x4,
	NIC_L3TYPE_E_IP4_OPT = 0x5,
	NIC_L3TYPE_E_IP6 = 0x6,
	NIC_L3TYPE_E_IP6_OPT = 0x7,
	NIC_L3TYPE_E_NONE = 0x0,
	NIC_L3TYPE_E_OTHER = 0xe,
	NIC_L3TYPE_E_ENUM_LAST = 0xf,
};

/**
 * Enumeration NIC_L4TYPE_E
 *
 * NIC Layer 4 Type Enumeration
 * Enumerates the values of
 * NIC_CQE_RX_S[L4TY].
 */
enum nic_l4type_e {
	NIC_L4TYPE_E_BTH = 0x8,
	NIC_L4TYPE_E_GRE = 0x7,
	NIC_L4TYPE_E_IPCOMP = 0x3,
	NIC_L4TYPE_E_IPFRAG = 0x2,
	NIC_L4TYPE_E_IPSEC_ESP = 0x1,
	NIC_L4TYPE_E_NONE = 0x0,
	NIC_L4TYPE_E_NVGRE = 0xb,
	NIC_L4TYPE_E_OTHER = 0xe,
	NIC_L4TYPE_E_SCTP = 0x6,
	NIC_L4TYPE_E_TCP = 0x4,
	NIC_L4TYPE_E_UDP = 0x5,
	NIC_L4TYPE_E_UDP_BTH = 0xc,
	NIC_L4TYPE_E_UDP_GENEVE = 0x9,
	NIC_L4TYPE_E_UDP_VXLAN = 0xa,
	NIC_L4TYPE_E_ENUM_LAST = 0xf,
};

/**
 * Enumeration NIC_PF_INT_VEC_E
 *
 * NIC PF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum nic_pf_int_vec_e {
	NIC_PF_INT_VEC_E_ECC0_DBE = 0x1,
	NIC_PF_INT_VEC_E_ECC0_SBE = 0x0,
	NIC_PF_INT_VEC_E_ECC1_DBE = 0x3,
	NIC_PF_INT_VEC_E_ECC1_SBE = 0x2,
	NIC_PF_INT_VEC_E_ECC2_DBE = 0x5,
	NIC_PF_INT_VEC_E_ECC2_SBE = 0x4,
	NIC_PF_INT_VEC_E_ECC3_DBE = 0x7,
	NIC_PF_INT_VEC_E_ECC3_SBE = 0x6,
	NIC_PF_INT_VEC_E_MBOX0 = 0x8,
	NIC_PF_INT_VEC_E_MBOX1 = 0x9,
	NIC_PF_INT_VEC_E_ENUM_LAST = 0xa,
};

/**
 * Enumeration NIC_RSS_ALG_E
 *
 * NIC RSS Algorithm Enumeration
 * Enumerates the values of
 * NIC_CQE_RX_S[RSS_ALG].
 */
enum nic_rss_alg_e {
	NIC_RSS_ALG_E_GRE_IP = 0x6,
	NIC_RSS_ALG_E_INNER_GRE_IP = 0xc,
	NIC_RSS_ALG_E_INNER_IP = 0x8,
	NIC_RSS_ALG_E_INNER_ROCE = 0xd,
	NIC_RSS_ALG_E_INNER_SCTP_IP = 0xb,
	NIC_RSS_ALG_E_INNER_TCP_IP = 0x9,
	NIC_RSS_ALG_E_INNER_UDP_IP = 0xa,
	NIC_RSS_ALG_E_IP = 0x2,
	NIC_RSS_ALG_E_NONE = 0x0,
	NIC_RSS_ALG_E_PORT = 0x1,
	NIC_RSS_ALG_E_ROCE = 0x7,
	NIC_RSS_ALG_E_SCTP_IP = 0x5,
	NIC_RSS_ALG_E_TCP_IP = 0x3,
	NIC_RSS_ALG_E_UDP_IP = 0x4,
	NIC_RSS_ALG_E_ENUM_LAST = 0xe,
};

/**
 * Enumeration NIC_SEND_CKL4_E
 *
 * NIC Send Checksum L4 Enumeration
 * Enumerates the different L4 checksum algorithms for NIC_SEND_HDR_S[CKL4].
 */
enum nic_send_ckl4_e {
	NIC_SEND_CKL4_E_NONE = 0x0,
	NIC_SEND_CKL4_E_TCP = 0x2,
	NIC_SEND_CKL4_E_UDP = 0x1,
	NIC_SEND_CKL4_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration NIC_SEND_CRCALG_E
 *
 * NIC Send-CRC Algorithm Enumeration
 * Enumerates the CRC algorithm used, see NIC_SEND_CRC_S[ALG].
 */
enum nic_send_crcalg_e {
	NIC_SEND_CRCALG_E_CKSUM = 0x3,
	NIC_SEND_CRCALG_E_CRC32 = 0x0,
	NIC_SEND_CRCALG_E_CRC32C = 0x1,
	NIC_SEND_CRCALG_E_ICRC = 0x2,
	NIC_SEND_CRCALG_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NIC_SEND_LD_TYPE_E
 *
 * NIC Send Load Type Enumeration
 * Enumerates the load transaction types for reading segment bytes specified by
 * NIC_SEND_GATHER_S[LD_TYPE].
 */
enum nic_send_ld_type_e {
	NIC_SEND_LD_TYPE_E_LDD = 0x0,
	NIC_SEND_LD_TYPE_E_LDT = 0x1,
	NIC_SEND_LD_TYPE_E_LDWB = 0x2,
	NIC_SEND_LD_TYPE_E_ENUM_LAST = 0x3,
};

/**
 * Enumeration NIC_SEND_MEMALG_E
 *
 * NIC Send Memory-Modify Algorithm Enumeration
 * Enumerates the algorithms for modifying memory, see NIC_SEND_MEM_S[ALG].
 */
enum nic_send_memalg_e {
	NIC_SEND_MEMALG_E_ADD = 0x8,
	NIC_SEND_MEMALG_E_ADDLEN = 0xa,
	NIC_SEND_MEMALG_E_SET = 0x0,
	NIC_SEND_MEMALG_E_SUB = 0x9,
	NIC_SEND_MEMALG_E_SUBLEN = 0xb,
	NIC_SEND_MEMALG_E_ENUM_LAST = 0xc,
};

/**
 * Enumeration NIC_SEND_MEMDSZ_E
 *
 * NIC Send Memory-Data Size Enumeration
 * Enumerates the datum size for modifying memory, see NIC_SEND_MEM_S[DSZ].
 */
enum nic_send_memdsz_e {
	NIC_SEND_MEMDSZ_E_B16 = 0x2,
	NIC_SEND_MEMDSZ_E_B32 = 0x1,
	NIC_SEND_MEMDSZ_E_B64 = 0x0,
	NIC_SEND_MEMDSZ_E_B8 = 0x3,
	NIC_SEND_MEMDSZ_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NIC_SEND_SUBDC_E
 *
 * NIC Send Subdescriptor Operation Enumeration
 * Enumerates the send subdescriptor codes.
 */
enum nic_send_subdc_e {
	NIC_SEND_SUBDC_E_CRC = 0x2,
	NIC_SEND_SUBDC_E_EOD = 0xf,
	NIC_SEND_SUBDC_E_GATHER = 0x4,
	NIC_SEND_SUBDC_E_HDR = 0x1,
	NIC_SEND_SUBDC_E_IMM = 0x3,
	NIC_SEND_SUBDC_E_INVALID = 0x0,
	NIC_SEND_SUBDC_E_LOCK = 0xd,
	NIC_SEND_SUBDC_E_MEM = 0x5,
	NIC_SEND_SUBDC_E_SOD = 0xe,
	NIC_SEND_SUBDC_E_ENUM_LAST = 0x10,
};

/**
 * Enumeration NIC_STAT_RQ_E
 *
 * NIC RQ Statistics Enumeration
 * Enumerates the index of NIC_PF_QS()_RQ()_STAT() and
 * NIC_QS()_RQ()_STAT().
 */
enum nic_stat_rq_e {
	NIC_STAT_RQ_E_OCTS = 0x0,
	NIC_STAT_RQ_E_PKTS = 0x1,
	NIC_STAT_RQ_E_ENUM_LAST = 0x2,
};

/**
 * Enumeration NIC_STAT_SQ_E
 *
 * NIC SQ Statistics Enumeration
 * Enumerates the index of NIC_PF_QS()_SQ()_STAT()
 * andNIC_QS()_SQ()_STAT().
 */
enum nic_stat_sq_e {
	NIC_STAT_SQ_E_OCTS = 0x0,
	NIC_STAT_SQ_E_PKTS = 0x1,
	NIC_STAT_SQ_E_ENUM_LAST = 0x2,
};

/**
 * Enumeration NIC_STAT_VNIC_RX_E
 *
 * NIC VNIC Receive Statistics Enumeration
 * Enumerates the index of NIC_PF_VNIC()_RX_STAT() and NIC_VNIC()_RX_STAT().
 */
enum nic_stat_vnic_rx_e {
	NIC_STAT_VNIC_RX_E_RX_BCAST = 0x2,
	NIC_STAT_VNIC_RX_E_RX_DRP_BCAST = 0xa,
	NIC_STAT_VNIC_RX_E_RX_DRP_L3BCAST = 0xc,
	NIC_STAT_VNIC_RX_E_RX_DRP_L3MCAST = 0xd,
	NIC_STAT_VNIC_RX_E_RX_DRP_MCAST = 0xb,
	NIC_STAT_VNIC_RX_E_RX_FCS = 0x8,
	NIC_STAT_VNIC_RX_E_RX_L2ERR = 0x9,
	NIC_STAT_VNIC_RX_E_RX_MCAST = 0x3,
	NIC_STAT_VNIC_RX_E_RX_OCTS = 0x0,
	NIC_STAT_VNIC_RX_E_RX_ORUN = 0x6,
	NIC_STAT_VNIC_RX_E_RX_ORUN_OCTS = 0x7,
	NIC_STAT_VNIC_RX_E_RX_RED = 0x4,
	NIC_STAT_VNIC_RX_E_RX_RED_OCTS = 0x5,
	NIC_STAT_VNIC_RX_E_RX_UCAST = 0x1,
	NIC_STAT_VNIC_RX_E_ENUM_LAST = 0xe,
};

/**
 * Enumeration NIC_STAT_VNIC_TX_E
 *
 * NIC VNIC Transmit Statistics Enumeration
 * Enumerates the index of NIC_PF_VNIC()_TX_STAT() and NIC_VNIC()_TX_STAT().
 */
enum nic_stat_vnic_tx_e {
	NIC_STAT_VNIC_TX_E_TX_BCAST = 0x2,
	NIC_STAT_VNIC_TX_E_TX_DROP = 0x4,
	NIC_STAT_VNIC_TX_E_TX_MCAST = 0x3,
	NIC_STAT_VNIC_TX_E_TX_OCTS = 0x0,
	NIC_STAT_VNIC_TX_E_TX_UCAST = 0x1,
	NIC_STAT_VNIC_TX_E_ENUM_LAST = 0x5,
};

/**
 * Enumeration NIC_SW_SYNC_RX_CNTS_E
 *
 * INTERNAL: NIC SW Debug RX Register Enumeration
 *
 * Enumerates index into NIC_PF_SW_SYNC_RX_CNTS().
 */
enum nic_sw_sync_rx_cnts_e {
	NIC_SW_SYNC_RX_CNTS_E_PIPE0_CQ_CNT = 0x1,
	NIC_SW_SYNC_RX_CNTS_E_PIPE0_PKT_CNT = 0x0,
	NIC_SW_SYNC_RX_CNTS_E_PIPE1_CQ_CNT = 0x3,
	NIC_SW_SYNC_RX_CNTS_E_PIPE1_PKT_CNT = 0x2,
	NIC_SW_SYNC_RX_CNTS_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NIC_TNS_CREDIT_SIZE_E
 *
 * NIC TNS Credit Size Enumeration
 * Enumerates send channel credit size for a TNS interface that is not bypassed.
 */
enum nic_tns_credit_size_e {
	NIC_TNS_CREDIT_SIZE_E_C128_256 = 0x1,
	NIC_TNS_CREDIT_SIZE_E_C192_256 = 0x2,
	NIC_TNS_CREDIT_SIZE_E_C256_256 = 0x3,
	NIC_TNS_CREDIT_SIZE_E_C64_256 = 0x0,
	NIC_TNS_CREDIT_SIZE_E_ENUM_LAST = 0x4,
};

/**
 * Enumeration NIC_VF_INT_VEC_E
 *
 * NIC VF MSI-X Vector Enumeration
 * Enumerates the MSI-X interrupt vectors.
 */
enum nic_vf_int_vec_e {
	NIC_VF_INT_VEC_E_CQ0 = 0x0,
	NIC_VF_INT_VEC_E_CQ1 = 0x1,
	NIC_VF_INT_VEC_E_CQ2 = 0x2,
	NIC_VF_INT_VEC_E_CQ3 = 0x3,
	NIC_VF_INT_VEC_E_CQ4 = 0x4,
	NIC_VF_INT_VEC_E_CQ5 = 0x5,
	NIC_VF_INT_VEC_E_CQ6 = 0x6,
	NIC_VF_INT_VEC_E_CQ7 = 0x7,
	NIC_VF_INT_VEC_E_MISC = 0x12,
	NIC_VF_INT_VEC_E_QS_ERR = 0x13,
	NIC_VF_INT_VEC_E_RBDR0 = 0x10,
	NIC_VF_INT_VEC_E_RBDR1 = 0x11,
	NIC_VF_INT_VEC_E_SQ0 = 0x8,
	NIC_VF_INT_VEC_E_SQ1 = 0x9,
	NIC_VF_INT_VEC_E_SQ2 = 0xa,
	NIC_VF_INT_VEC_E_SQ3 = 0xb,
	NIC_VF_INT_VEC_E_SQ4 = 0xc,
	NIC_VF_INT_VEC_E_SQ5 = 0xd,
	NIC_VF_INT_VEC_E_SQ6 = 0xe,
	NIC_VF_INT_VEC_E_SQ7 = 0xf,
	NIC_VF_INT_VEC_E_ENUM_LAST = 0x14,
};


/**
 * Structure NIC_CQE_RX_S
 *
 * NIC CQE Receive Structure
 * Format of receive completion queue entry.
 */
union nic_cqe_rx_s {
	uint64_t u[6];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cqe_type                    : 4;  /**< [ 63: 60] Completion queue entry type (NIC_CQE_TYPE_E::RX, or NIC_CQE_TYPE_E::RX_SPLT). */
		uint64_t stdn_fault                  : 1;  /**< [ 59: 59] STDN fault detected during the data writes to memory. */
		uint64_t reserved_58_58              : 1;  /**< [ 58: 58] Reserved. */
		uint64_t rq_qs                       : 7;  /**< [ 57: 51] Indicates the RQ's QS. */
		uint64_t rq_idx                      : 3;  /**< [ 50: 48] Indicates the RQ inside the QS. */
		uint64_t reserved_36_47              : 12; /**< [ 47: 36] Reserved. */
		uint64_t rss_alg                     : 4;  /**< [ 35: 32] RSS algorithm used. Enumerated by NIC_RSS_ALG_E. */
		uint64_t reserved_28_31              : 4;  /**< [ 31: 28] Reserved. */
		uint64_t rb_cnt                      : 4;  /**< [ 27: 24] Number of RB pointers in the CQ entry. Each entry is a 8 byte structure. */
		uint64_t vv                          : 1;  /**< [ 23: 23] Indicates one or more VLANs were found in the packet. Unpredictable when [ERRLEV] \<= L2. */
		uint64_t vv_gone                     : 1;  /**< [ 22: 22] Indicates the first VLAN in network order was stripped from the packet data and written to
                                                                 [VLAN_TCI]. This field is zero when [VV]=0 or [VS_GONE]=1. */
		uint64_t vs                          : 1;  /**< [ 21: 21] Indicates a second VLAN was found in the packet. This field is zero when [VV]=0, and
                                                                 unpredictable when [ERRLEV] \<= L2. */
		uint64_t vs_gone                     : 1;  /**< [ 20: 20] Indicates the second VLAN in network order was stripped from the packet data and written
                                                                 to [VLAN_TCI]. This field is zero when [VS]=0 or [VV_GONE]=1. */
		uint64_t l4ty                        : 4;  /**< [ 19: 16] Layer 4 type. Indicates the layer 4 header type, enumerated by
                                                                 NIC_L4TYPE_E. This field is zero unless L4 parsing sets it, and is unpredictable
                                                                 when [ERRLEV] \<= L4. */
		uint64_t l3ty                        : 4;  /**< [ 15: 12] Layer 3 type. Indicates the layer 3 header type, enumerated by
                                                                 NIC_L3TYPE_E. This field is zero unless L3 parsing sets it, and is unpredictable
                                                                 when [ERRLEV] \<= L3. */
		uint64_t l2e                         : 1;  /**< [ 11: 11] Layer 2 exists. Indicates that Ethernet layer was parsed. This field is zero when L2 is
                                                                 not parsed, and unpredictable when [ERRLEV] \<= RE. */
		uint64_t errlev                      : 3;  /**< [ 10:  8] Error level. Normally zero, but when errors are detected contains the lowest protocol
                                                                 layer containing an error, and [ERROP] will indicate the precise error reason. Enumerated
                                                                 with NIC_ERRLEV_E.

                                                                 Note pseudo-code often refers to for example '[ERRLEV] \<= L3', this is a shorthand for
                                                                 'all errors at L3 and below', that is, [ERRLEV] == (RE or L2 or L3) and [ERROP] !=0, but
                                                                 is not true when [ERRLEV] == (NONE nor L4) nor when [ERROP] == 0 (no error at all). */
		uint64_t errop                       : 8;  /**< [  7:  0] Error opcode. Normally zero, but contains a (non-zero) exception opcode enumerated by
                                                                 NIC_ERROP_E when [ERRLEV] is non-zero. */
#else
		uint64_t errop                       : 8;  /**< [  7:  0] Error opcode. Normally zero, but contains a (non-zero) exception opcode enumerated by
                                                                 NIC_ERROP_E when [ERRLEV] is non-zero. */
		uint64_t errlev                      : 3;  /**< [ 10:  8] Error level. Normally zero, but when errors are detected contains the lowest protocol
                                                                 layer containing an error, and [ERROP] will indicate the precise error reason. Enumerated
                                                                 with NIC_ERRLEV_E.

                                                                 Note pseudo-code often refers to for example '[ERRLEV] \<= L3', this is a shorthand for
                                                                 'all errors at L3 and below', that is, [ERRLEV] == (RE or L2 or L3) and [ERROP] !=0, but
                                                                 is not true when [ERRLEV] == (NONE nor L4) nor when [ERROP] == 0 (no error at all). */
		uint64_t l2e                         : 1;  /**< [ 11: 11] Layer 2 exists. Indicates that Ethernet layer was parsed. This field is zero when L2 is
                                                                 not parsed, and unpredictable when [ERRLEV] \<= RE. */
		uint64_t l3ty                        : 4;  /**< [ 15: 12] Layer 3 type. Indicates the layer 3 header type, enumerated by
                                                                 NIC_L3TYPE_E. This field is zero unless L3 parsing sets it, and is unpredictable
                                                                 when [ERRLEV] \<= L3. */
		uint64_t l4ty                        : 4;  /**< [ 19: 16] Layer 4 type. Indicates the layer 4 header type, enumerated by
                                                                 NIC_L4TYPE_E. This field is zero unless L4 parsing sets it, and is unpredictable
                                                                 when [ERRLEV] \<= L4. */
		uint64_t vs_gone                     : 1;  /**< [ 20: 20] Indicates the second VLAN in network order was stripped from the packet data and written
                                                                 to [VLAN_TCI]. This field is zero when [VS]=0 or [VV_GONE]=1. */
		uint64_t vs                          : 1;  /**< [ 21: 21] Indicates a second VLAN was found in the packet. This field is zero when [VV]=0, and
                                                                 unpredictable when [ERRLEV] \<= L2. */
		uint64_t vv_gone                     : 1;  /**< [ 22: 22] Indicates the first VLAN in network order was stripped from the packet data and written to
                                                                 [VLAN_TCI]. This field is zero when [VV]=0 or [VS_GONE]=1. */
		uint64_t vv                          : 1;  /**< [ 23: 23] Indicates one or more VLANs were found in the packet. Unpredictable when [ERRLEV] \<= L2. */
		uint64_t rb_cnt                      : 4;  /**< [ 27: 24] Number of RB pointers in the CQ entry. Each entry is a 8 byte structure. */
		uint64_t reserved_28_31              : 4;  /**< [ 31: 28] Reserved. */
		uint64_t rss_alg                     : 4;  /**< [ 35: 32] RSS algorithm used. Enumerated by NIC_RSS_ALG_E. */
		uint64_t reserved_36_47              : 12; /**< [ 47: 36] Reserved. */
		uint64_t rq_idx                      : 3;  /**< [ 50: 48] Indicates the RQ inside the QS. */
		uint64_t rq_qs                       : 7;  /**< [ 57: 51] Indicates the RQ's QS. */
		uint64_t reserved_58_58              : 1;  /**< [ 58: 58] Reserved. */
		uint64_t stdn_fault                  : 1;  /**< [ 59: 59] STDN fault detected during the data writes to memory. */
		uint64_t cqe_type                    : 4;  /**< [ 63: 60] Completion queue entry type (NIC_CQE_TYPE_E::RX, or NIC_CQE_TYPE_E::RX_SPLT). */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t len                         : 16; /**< [127:112] The number of bytes in the packet and written to the CQE/RB. Bytes stripped (VLAN etc) if
                                                                 any are not included. */
		uint64_t l2ptr                       : 8;  /**< [111:104] Pointer to the first byte of L2 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= RE. */
		uint64_t l3ptr                       : 8;  /**< [103: 96] Pointer to the first byte of L3 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= L2. */
		uint64_t l4ptr                       : 8;  /**< [ 95: 88] Pointer to the first byte of L4 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= L3. */
		uint64_t size_cqd                    : 8;  /**< [ 87: 80] Size of CQ data. Number of packet bytes written to the CQ, either due to
                                                                 NIC_QS()_RQ_GEN_CFG[CQ_HDR_COPY] or the packet being smaller than
                                                                 NIC_QS()_RQ_GEN_CFG[CQ_PKT_SIZE]. */
		uint64_t apad                        : 3;  /**< [ 79: 77] Number of alignment bytes added before data in CQE and RB. */
		uint64_t reserved_76_76              : 1;  /**< [ 76: 76] Reserved. */
		uint64_t chan                        : 12; /**< [ 75: 64] Logical channel the packet arrived from, enumerated by NIC_CHAN_E. */
#else
		uint64_t chan                        : 12; /**< [ 75: 64] Logical channel the packet arrived from, enumerated by NIC_CHAN_E. */
		uint64_t reserved_76_76              : 1;  /**< [ 76: 76] Reserved. */
		uint64_t apad                        : 3;  /**< [ 79: 77] Number of alignment bytes added before data in CQE and RB. */
		uint64_t size_cqd                    : 8;  /**< [ 87: 80] Size of CQ data. Number of packet bytes written to the CQ, either due to
                                                                 NIC_QS()_RQ_GEN_CFG[CQ_HDR_COPY] or the packet being smaller than
                                                                 NIC_QS()_RQ_GEN_CFG[CQ_PKT_SIZE]. */
		uint64_t l4ptr                       : 8;  /**< [ 95: 88] Pointer to the first byte of L4 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= L3. */
		uint64_t l3ptr                       : 8;  /**< [103: 96] Pointer to the first byte of L3 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= L2. */
		uint64_t l2ptr                       : 8;  /**< [111:104] Pointer to the first byte of L2 relative to the first byte of packet data written to
                                                                 memory. Unpredictable when [ERRLEV] \<= RE. */
		uint64_t len                         : 16; /**< [127:112] The number of bytes in the packet and written to the CQE/RB. Bytes stripped (VLAN etc) if
                                                                 any are not included. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rss_tag                     : 32; /**< [191:160] Computed RSS tag value. This field is zero when [RSS_ALG] == NIC_RSS_ALG_E::NONE (0) and
                                                                 NIC_RX_HDR_S[RSS_DIS] was clear. */
		uint64_t vlan_tci                    : 16; /**< [159:144] Stripped VLAN tag control information. Unpredictable when [VV_GONE] and [VS_GONE] are
                                                                 clear. INTERNAL: Hardware zeros when unpredictable, though software must not rely on this. */
		uint64_t vvptr                       : 8;  /**< [143:136] Pointer to first VLAN. If [VV] set, [VV_GONE] clear, the first byte of the first VLAN's
                                                                 Ethertype. If [VV] set, [VV_GONE] set, the first byte after the stripped VLAN.
                                                                 Unpredictable if [VV] clear. INTERNAL: Hardware zeros when unpredictable, though software
                                                                 must not rely on this. */
		uint64_t vsptr                       : 8;  /**< [135:128] Pointer to second VLAN. If [VS] set, [VS_GONE] clear, the first byte of the second VLAN's
                                                                 Ethertype. If [VS] set, [VS_GONE] set, the first byte after the stripped VLAN.
                                                                 Unpredictable if [VS] clear. INTERNAL: Hardware zeros when unpredictable, though software
                                                                 must not rely on this. */
#else
		uint64_t vsptr                       : 8;  /**< [135:128] Pointer to second VLAN. If [VS] set, [VS_GONE] clear, the first byte of the second VLAN's
                                                                 Ethertype. If [VS] set, [VS_GONE] set, the first byte after the stripped VLAN.
                                                                 Unpredictable if [VS] clear. INTERNAL: Hardware zeros when unpredictable, though software
                                                                 must not rely on this. */
		uint64_t vvptr                       : 8;  /**< [143:136] Pointer to first VLAN. If [VV] set, [VV_GONE] clear, the first byte of the first VLAN's
                                                                 Ethertype. If [VV] set, [VV_GONE] set, the first byte after the stripped VLAN.
                                                                 Unpredictable if [VV] clear. INTERNAL: Hardware zeros when unpredictable, though software
                                                                 must not rely on this. */
		uint64_t vlan_tci                    : 16; /**< [159:144] Stripped VLAN tag control information. Unpredictable when [VV_GONE] and [VS_GONE] are
                                                                 clear. INTERNAL: Hardware zeros when unpredictable, though software must not rely on this. */
		uint64_t rss_tag                     : 32; /**< [191:160] Computed RSS tag value. This field is zero when [RSS_ALG] == NIC_RSS_ALG_E::NONE (0) and
                                                                 NIC_RX_HDR_S[RSS_DIS] was clear. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rbsz3                       : 16; /**< [255:240] Size of RB 6. */
		uint64_t rbsz2                       : 16; /**< [239:224] Size of RB 4. */
		uint64_t rbsz1                       : 16; /**< [223:208] Size of RB 2. */
		uint64_t rbsz0                       : 16; /**< [207:192] Size of RB 0. Number of bytes written to the first RB, or hardware 0x0 and software
                                                                 reserved if none written to this RB. INTERNAL: Fields are laid out so that on a litte-
                                                                 endian machine a uint16_t array can hit all 12 RBSZs. */
#else
		uint64_t rbsz0                       : 16; /**< [207:192] Size of RB 0. Number of bytes written to the first RB, or hardware 0x0 and software
                                                                 reserved if none written to this RB. INTERNAL: Fields are laid out so that on a litte-
                                                                 endian machine a uint16_t array can hit all 12 RBSZs. */
		uint64_t rbsz1                       : 16; /**< [223:208] Size of RB 2. */
		uint64_t rbsz2                       : 16; /**< [239:224] Size of RB 4. */
		uint64_t rbsz3                       : 16; /**< [255:240] Size of RB 6. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rbsz7                       : 16; /**< [319:304] Size of RB 6. */
		uint64_t rbsz6                       : 16; /**< [303:288] Size of RB 4. */
		uint64_t rbsz5                       : 16; /**< [287:272] Size of RB 2. */
		uint64_t rbsz4                       : 16; /**< [271:256] Size of RB 0. Number of bytes written to the first RB, or 0x0 if none written to this RB. */
#else
		uint64_t rbsz4                       : 16; /**< [271:256] Size of RB 0. Number of bytes written to the first RB, or 0x0 if none written to this RB. */
		uint64_t rbsz5                       : 16; /**< [287:272] Size of RB 2. */
		uint64_t rbsz6                       : 16; /**< [303:288] Size of RB 4. */
		uint64_t rbsz7                       : 16; /**< [319:304] Size of RB 6. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rbsz11                      : 16; /**< [383:368] Size of RB 6. */
		uint64_t rbsz10                      : 16; /**< [367:352] Size of RB 4. */
		uint64_t rbsz9                       : 16; /**< [351:336] Size of RB 2. */
		uint64_t rbsz8                       : 16; /**< [335:320] Size of RB 0. Number of bytes written to the first RB, or 0x0 if none written to this RB. */
#else
		uint64_t rbsz8                       : 16; /**< [335:320] Size of RB 0. Number of bytes written to the first RB, or 0x0 if none written to this RB. */
		uint64_t rbsz9                       : 16; /**< [351:336] Size of RB 2. */
		uint64_t rbsz10                      : 16; /**< [367:352] Size of RB 4. */
		uint64_t rbsz11                      : 16; /**< [383:368] Size of RB 6. */
#endif
	} s;
};

/**
 * Structure NIC_CQE_SEND_S
 *
 * NIC CQE Send Structure
 * Format of send completion queue entry.
 */
union nic_cqe_send_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cqe_type                    : 4;  /**< [ 63: 60] Completion queue entry type (NIC_CQE_TYPE_E::SEND or NIC_CQE_TYPE_E::SEND_PTP). */
		uint64_t reserved_56_59              : 4;  /**< [ 59: 56] Reserved. */
		uint64_t sqe_ptr                     : 16; /**< [ 55: 40] SQ entry pointer\<19:4\>. Address bits \<3:0\> are always 0. */
		uint64_t reserved_36_39              : 4;  /**< [ 39: 36] Reserved, for alignment padding. */
		uint64_t reserved_26_35              : 10; /**< [ 35: 26] Reserved. */
		uint64_t sq_qs                       : 7;  /**< [ 25: 19] Indicates the send queue's QS. */
		uint64_t sq_idx                      : 3;  /**< [ 18: 16] Indicates the send queue's index inside the QS. */
		uint64_t reserved_8_15               : 8;  /**< [ 15:  8] Reserved. */
		uint64_t send_status                 : 8;  /**< [  7:  0] Send completion status enumerated by NIC_CQE_SEND_STATUS_E. */
#else
		uint64_t send_status                 : 8;  /**< [  7:  0] Send completion status enumerated by NIC_CQE_SEND_STATUS_E. */
		uint64_t reserved_8_15               : 8;  /**< [ 15:  8] Reserved. */
		uint64_t sq_idx                      : 3;  /**< [ 18: 16] Indicates the send queue's index inside the QS. */
		uint64_t sq_qs                       : 7;  /**< [ 25: 19] Indicates the send queue's QS. */
		uint64_t reserved_26_35              : 10; /**< [ 35: 26] Reserved. */
		uint64_t reserved_36_39              : 4;  /**< [ 39: 36] Reserved, for alignment padding. */
		uint64_t sqe_ptr                     : 16; /**< [ 55: 40] SQ entry pointer\<19:4\>. Address bits \<3:0\> are always 0. */
		uint64_t reserved_56_59              : 4;  /**< [ 59: 56] Reserved. */
		uint64_t cqe_type                    : 4;  /**< [ 63: 60] Completion queue entry type (NIC_CQE_TYPE_E::SEND or NIC_CQE_TYPE_E::SEND_PTP). */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ptp_timestamp               : 64; /**< [127: 64] PTP timestamp value. Valid when [CQE_TYPE]=NIC_CQE_TYPE_E::SEND_PTP. */
#else
		uint64_t ptp_timestamp               : 64; /**< [127: 64] PTP timestamp value. Valid when [CQE_TYPE]=NIC_CQE_TYPE_E::SEND_PTP. */
#endif
	} s;
};

/**
 * Structure NIC_RBDR_ENTRY_S
 *
 * NIC Receive-Buffer Descriptor-Ring Entry Structure
 * Receive buffer descriptor ring entry.
 */
union nic_rbdr_entry_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15; /**< [ 63: 49] Reserved. */
		uint64_t addr                        : 42; /**< [ 48:  7] Starting address of receive data buffer. */
		uint64_t reserved_0_6                : 7;  /**< [  6:  0] Reserved for cache line alignment. */
#else
		uint64_t reserved_0_6                : 7;  /**< [  6:  0] Reserved for cache line alignment. */
		uint64_t addr                        : 42; /**< [ 48:  7] Starting address of receive data buffer. */
		uint64_t reserved_49_63              : 15; /**< [ 63: 49] Reserved. */
#endif
	} s;
};

/**
 * Structure NIC_RX_HDR_S
 *
 * NIC Receive Header Structure
 * This 64-bit header is optionally prepended by TNS onto packets received by the NIC. This
 * structure is stored with the packet data in big-endian form ([OPAQUE4] is in bytes 16-19,
 * counting the 8-byte timestamp); little-endian software must swap bytes before using this
 * structure.
 */
union nic_rx_hdr_s {
	uint64_t u;
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t opaque4                     : 32; /**< [ 63: 32] Software defined field, no meaning to hardware. */
		uint64_t rss_flow                    : 8;  /**< [ 31: 24] Flow identifier, for inclusion in RSS calculation. */
		uint64_t sl                          : 6;  /**< [ 23: 18] Skip length. Number of 2-byte words parser should skip between the end of the header and
                                                                 before beginning L2 parsing. */
		uint64_t rss_dis                     : 1;  /**< [ 17: 17] Disables NIC RSS algorithms, and forces [RSS_FLOW] into NIC_CQE_RX_S[RSS_TAG]. */
		uint64_t tcp_dis                     : 1;  /**< [ 16: 16] Reserved. INTERNAL: Reserved for future use - Disable TCP reassembly. */
		uint64_t nodrop                      : 1;  /**< [ 15: 15] Disable RED. */
		uint64_t dest_alg                    : 2;  /**< [ 14: 13] Specifies algorithm for use of DEST:
                                                                 0x0 = [DEST] is ignored.
                                                                 0x1 = [DEST]\<10:0\> specifies the CPI to receive the packet.
                                                                 0x2 = [DEST]\<9:3\> specifies the QS and [DEST]\<2:0\> the RQ in that QS.
                                                                 0x3 = Reserved. */
		uint64_t reserved_11_12              : 2;  /**< [ 12: 11] Reserved. */
		uint64_t dest                        : 11; /**< [ 10:  0] Associates a packet to a destination the RQ interface or a VNIC, see [DEST_ALG]. */
#else
		uint64_t dest                        : 11; /**< [ 10:  0] Associates a packet to a destination the RQ interface or a VNIC, see [DEST_ALG]. */
		uint64_t reserved_11_12              : 2;  /**< [ 12: 11] Reserved. */
		uint64_t dest_alg                    : 2;  /**< [ 14: 13] Specifies algorithm for use of DEST:
                                                                 0x0 = [DEST] is ignored.
                                                                 0x1 = [DEST]\<10:0\> specifies the CPI to receive the packet.
                                                                 0x2 = [DEST]\<9:3\> specifies the QS and [DEST]\<2:0\> the RQ in that QS.
                                                                 0x3 = Reserved. */
		uint64_t nodrop                      : 1;  /**< [ 15: 15] Disable RED. */
		uint64_t tcp_dis                     : 1;  /**< [ 16: 16] Reserved. INTERNAL: Reserved for future use - Disable TCP reassembly. */
		uint64_t rss_dis                     : 1;  /**< [ 17: 17] Disables NIC RSS algorithms, and forces [RSS_FLOW] into NIC_CQE_RX_S[RSS_TAG]. */
		uint64_t sl                          : 6;  /**< [ 23: 18] Skip length. Number of 2-byte words parser should skip between the end of the header and
                                                                 before beginning L2 parsing. */
		uint64_t rss_flow                    : 8;  /**< [ 31: 24] Flow identifier, for inclusion in RSS calculation. */
		uint64_t opaque4                     : 32; /**< [ 63: 32] Software defined field, no meaning to hardware. */
#endif
	} s;
};

/**
 * Structure NIC_SEND_CRC_S
 *
 * NIC Send-CRC Subdescriptor Structure
 * The Send CRC subdescriptor specifies a CRC calculation be performed during transmission. See
 * Custom Checksum.
 * There may be up to two NIC_SEND_CRC_Ss per packet send descriptor. NIC_SEND_CRC_S constraints:
 * NIC_SEND_CRC_S subdescriptors must precede all NIC_SEND_GATHER_S, NIC_SEND_IMM_S and
 * NICX_SEND_MEM_S subdescriptors in the send descriptor.
 *
 * NIC_SEND_CRC_S subdescriptors must follow the same order as their checksum and insert regions
 * in the packet, i.e. the checksum and insert regions of a NIC_SEND_CRC_S must come after the
 * checksum and insert regions of a preceding NIC_SEND_CRC_S.
 *
 * If NIC_SEND_HDR_S[CKL3] is set, the bytes covered or inserted by each individual
 * NIC_SEND_CRC_S must entirely reside within the L3 payload, i.e. they must follow the IPv4
 * header bytes (including any options).
 * the bytes covered or inserted by the CRC must not overlap the IPv4 header bytes (including any
 * options). The IPv4 header bytes (and options) start at byte NIC_SEND_HDR_S[L3PTR] in the
 * packet in this case.
 *
 * If NIC_SEND_HDR_S[CKL4] is nonzero, the bytes covered or inserted by each individual
 * NIC_SEND_CRC_S CRC must entirely reside within the L4 payload. The L4 (TCP/UDP) header
 * starts at byte NIC_SEND_HDR_S[L4PTR] in the packet in this case, and the L4 payload follows
 * the L4 header. In this case, the NIC will appear to calculate the L4 checksum last, after it
 * has completed all NIC_SEND_CRC_S CRCs.
 */
union nic_send_crc_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send CRC. Enumerated by NIC_SEND_SUBDC_E::CRC. */
		uint64_t alg                         : 2;  /**< [ 59: 58] CRC algorithm. See NIC_SEND_CRCALG_E. */
		uint64_t reserved_48_57              : 10; /**< [ 57: 48] Reserved. */
		uint64_t insert                      : 16; /**< [ 47: 32] Byte position relative to the first packet byte at which to insert the first byte of the
                                                                 calculated CRC. NIC does not allocate bytes as it inserts the CRC result into the packet,
                                                                 it overwrites four pre-supplied packet bytes using NIC_SEND_GATHER_S or NIC_SEND_IMM_S.
                                                                 The insertion point may not be within the start/size region of another NIC_SEND_CRC_S. */
		uint64_t start                       : 16; /**< [ 31: 16] Byte position relative to the first packet byte at which to start the checksum. */
		uint64_t size                        : 16; /**< [ 15:  0] Length of checksum region, must not be zero. The region is contiguous in packet bytes
                                                                 [START] through [START]+[SIZE]-1. Note that these covered reconstructed bytes need not be
                                                                 contiguous in L2/DRAM -- they can straddle any number of NIC_SEND_GATHER_S subdescriptors. */
#else
		uint64_t size                        : 16; /**< [ 15:  0] Length of checksum region, must not be zero. The region is contiguous in packet bytes
                                                                 [START] through [START]+[SIZE]-1. Note that these covered reconstructed bytes need not be
                                                                 contiguous in L2/DRAM -- they can straddle any number of NIC_SEND_GATHER_S subdescriptors. */
		uint64_t start                       : 16; /**< [ 31: 16] Byte position relative to the first packet byte at which to start the checksum. */
		uint64_t insert                      : 16; /**< [ 47: 32] Byte position relative to the first packet byte at which to insert the first byte of the
                                                                 calculated CRC. NIC does not allocate bytes as it inserts the CRC result into the packet,
                                                                 it overwrites four pre-supplied packet bytes using NIC_SEND_GATHER_S or NIC_SEND_IMM_S.
                                                                 The insertion point may not be within the start/size region of another NIC_SEND_CRC_S. */
		uint64_t reserved_48_57              : 10; /**< [ 57: 48] Reserved. */
		uint64_t alg                         : 2;  /**< [ 59: 58] CRC algorithm. See NIC_SEND_CRCALG_E. */
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send CRC. Enumerated by NIC_SEND_SUBDC_E::CRC. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
		uint64_t iv                          : 32; /**< [ 95: 64] Initial value of the checksum. If [ALG] = CKSUM, then only bits \<15:0\> in big-endian
                                                                 format are valid. INTERNAL: Pass 2 feature [ALG] = CRC, functional only with IV =
                                                                 0xffffffff. */
#else
		uint64_t iv                          : 32; /**< [ 95: 64] Initial value of the checksum. If [ALG] = CKSUM, then only bits \<15:0\> in big-endian
                                                                 format are valid. INTERNAL: Pass 2 feature [ALG] = CRC, functional only with IV =
                                                                 0xffffffff. */
		uint64_t reserved_96_127             : 32; /**< [127: 96] Reserved. */
#endif
	} s;
};

/**
 * Structure NIC_SEND_GATHER_S
 *
 * NIC Send-Gather Subdescriptor Structure
 * The Send Gather subdescriptor requests a contiguous segment of bytes be transmitted. See Send
 * Gather. There may be multiple NIC_SEND_GATHER_Ss in each NIC send descriptor. A
 * NIC_SEND_GATHER_S must not be present in a NIC send descriptor if the sum of all prior
 * NIC_SEND_GATHER_S[SIZE]s and NIC_SEND_IMM_S[SIZE]s meets or exceeds NIC_SEND_HDR_S[TOTAL].
 */
union nic_send_gather_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Gather. Enumerated by NIC_SEND_SUBDC_E::GATHER. */
		uint64_t ld_type                     : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
		uint64_t reserved_16_57              : 42; /**< [ 57: 16] Reserved. */
		uint64_t size                        : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero, else the subdescriptor is ignored. */
#else
		uint64_t size                        : 16; /**< [ 15:  0] Size of segment, in bytes. [SIZE] must be nonzero, else the subdescriptor is ignored. */
		uint64_t reserved_16_57              : 42; /**< [ 57: 16] Reserved. */
		uint64_t ld_type                     : 2;  /**< [ 59: 58] Specifies load transaction type to use for reading segment bytes. Enumerated by
                                                                 NIC_SEND_LD_TYPE_E. */
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Gather. Enumerated by NIC_SEND_SUBDC_E::GATHER. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_113_127            : 15; /**< [127:113] Reserved. INTERNAL: For 64-bit addresses. */
		uint64_t addr                        : 49; /**< [112: 64] Address. VA, IPA or PA (depending on SMMU configuration) of the first byte of packet data
                                                                 in the buffer. */
#else
		uint64_t addr                        : 49; /**< [112: 64] Address. VA, IPA or PA (depending on SMMU configuration) of the first byte of packet data
                                                                 in the buffer. */
		uint64_t reserved_113_127            : 15; /**< [127:113] Reserved. INTERNAL: For 64-bit addresses. */
#endif
	} s;
};

/**
 * Structure NIC_SEND_HDR_S
 *
 * NIC Send-Header Subdescriptor Structure
 * The send header is the first subdescriptor of every send descriptor.
 */
union nic_send_hdr_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send header. Enumerated by NIC_SEND_SUBDC_E::HDR. */
		uint64_t tso                         : 1;  /**< [ 59: 59] TCP segmentation offload. When set, the send descriptor is for a TCP segmentation
                                                                 operation to send one or more packets of a TCP flow, and the related [TSO_*] fields are
                                                                 valid. */
		uint64_t pnc                         : 1;  /**< [ 58: 58] Post normal completion. If set, a CQE is created with NIC_CQE_SEND_S[CQE_TYPE] =
                                                                 NIC_CQE_TYPE_E::SEND when the send descriptor's operation completes normally with no
                                                                 error. If clear, no CQE is added on normal completion.

                                                                 Note that a CQE is always added if the send operation terminates with an error after the
                                                                 packet is scheduled; except for LOCK_VIOL, where a CQE is determined  by
                                                                 NIC_PF_QS_CFG[LOCK_VIOL_CQE_EN].

                                                                 NIC will not add a CQE for this send descriptor until after it has completed all L2/DRAM
                                                                 fetches that service all prior NIC_SEND_GATHER_S subdescriptors, and it has fetched all
                                                                 subdescriptors in the send descriptor. If NIC_SEND_MEM_S[WMEM]=1, NIC also will not post
                                                                 the CQE until all NIC_SEND_MEM_S subdescriptors in the descriptor complete and commit. */
		uint64_t ds                          : 1;  /**< [ 57: 57] Don't send. If set, NIC hardware will not send the packet bytes to the interface; however
                                                                 it will still perform any NIC_SEND_MEM_S operations. */
		uint64_t tstmp                       : 1;  /**< [ 56: 56] PTP timestamp. When this is set, [DS] is clear and NIC_PF_QS()_CFG[SEND_TSTMP_ENA]
                                                                 is set, a CQE of NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND_PTP is posted when the
                                                                 packet is transmitted by the targeted Ethernet port. NIC_CQE_SEND_S[PTP_TIMESTAMP] is set
                                                                 to the packet's timestamp. The posted NIC_CQE_TYPE_E::SEND_PTP CQ entry is asynchronous
                                                                 relative to NIC_CQE_TYPE_E::SEND CQ entries in the same CQ.

                                                                 If this bit is set along with [PNC], two entries are posted to the CQ. The first CQ entry
                                                                 is posted with NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND when the send descriptor's
                                                                 operation is done as described above. The second CQ entry is posted with
                                                                 NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND_PTP when the packet's timestamp is
                                                                 captured or times out.

                                                                 Only one timestamp operation may be outstanding at once for a given Ethernet port.
                                                                 Ignored when [DS] is set or NIC_PF_QS()_CFG[SEND_TSTMP_ENA] is clear. */
		uint64_t subdcnt                     : 8;  /**< [ 55: 48] Subdescriptor count. Number of 128-bit subdescriptors following the send header
                                                                 subdescriptor, including immediate data. Must be between 1 and 255, thus the maximum send
                                                                 descriptor size is 256 subdescriptors (4KB). */
		uint64_t ckl4                        : 2;  /**< [ 47: 46] Checksum L4, enumerated by NIC_SEND_CKL4_E. If nonzero (not NONE):
                                                                 * NIC hardware calculates the Layer 4 TCP/UDP checksum for the packet and inserts it
                                                                 into the packet, as described in L4 Checksum.
                                                                 * [L4PTR] selects the first byte of the L4 header, and [L3PTR] must indicate the location
                                                                 of the immediately proceeding and adjacent L3 header.
                                                                 * The L4 length field must not require more than [TOTAL] bytes in the packet.
                                                                 * When NIC_SEND_CRC_S are present, the bytes covered or inserted by NIC_SEND_CRC_S must
                                                                 all reside in the L4 payload. Conceptually, NIC processes NIC_SEND_CRC_S before L4
                                                                 checksums when both are present. */
		uint64_t ckl3                        : 1;  /**< [ 45: 45] Checksum L3. If set, NIC hardware calculates the IPv4 header checksum and inserts it into
                                                                 the packet, as described in L4 Checksum. When set, [L3PTR] selects the location of the
                                                                 first byte of the L3 header and no L3 header bytes selected by [L3PTR] can overlap with
                                                                 any bytes covered or inserted by NIC_SEND_CRC_S CRCs. When [CKL3] is set, [L3PTR] must
                                                                 point to a valid IPv4 header. */
		uint64_t cklf                        : 2;  /**< [ 44: 43] Inner Checksum L4, enumerated by NIC_SEND_CKL4_E. Similar to [CKL4] but for inner L4.
                                                                 Added in pass 2. */
		uint64_t ckle                        : 1;  /**< [ 42: 42] Inner Checksum L3. Similar to [CKL3] but for inner IP.
                                                                 Added in pass 2. */
		uint64_t reserved_40_41              : 2;  /**< [ 41: 40] Reserved. */
		uint64_t l4ptr                       : 8;  /**< [ 39: 32] Layer 4 Offset. Specifies the location of the first byte of the TCP/UDP header for L4
                                                                 checksumming. The Layer 4 header must be exactly [L4PTR] bytes from the beginning of the
                                                                 packet. Software might populate this field for forwarded packets from a computation based
                                                                 off NIC_CQE_RX_S[L4PTR], which is the IP location computed by NIC when the packet is
                                                                 parsed. When [CKL4] is nonzero, no L4 header bytes indicated by [L4PTR] can overlap with
                                                                 any bytes covered by or inserted by NIC_SEND_CRC_S CRCs (but the subsequent L4 payload
                                                                 bytes can overlap with the NIC_SEND_CRC_S CRC bytes). */
		uint64_t l3ptr                       : 8;  /**< [ 31: 24] Layer 3 IP Offset. Specifies the location of the first byte of the IP packet for L3
                                                                 checksum and/or L4 checksum. (See [CKL3,CKL4].) The IP packet must be exactly [L3PTR]
                                                                 bytes from the beginning of the packet. Software might populate this field for forwarded
                                                                 packets from a computation based off NIC_CQE_RX_S[L3PTR], which is the IP location
                                                                 computed by NIC when the packet is parsed. When [L3PTR] is used for any of [CKL3,CKL4]
                                                                 calculations/modifications, then no L3 nor L2 header bytes indicated by [L3PTR] can
                                                                 overlap with any bytes covered by or inserted by NIC_SEND_CRC_S CRCs. */
		uint64_t reserved_20_23              : 4;  /**< [ 23: 20] Reserved. */
		uint64_t total                       : 20; /**< [ 19:  0] Total Byte Count. Must be greater than 0. If [TSO] is clear, the total number of bytes to
                                                                 send, including zero pad (if any), and should not exceed the lesser of 9212 (9216 minus 4
                                                                 byte FCS) or NIC_PF_LMAC()_CFG2[MAX_PKT_SIZE].

                                                                 If [TSO] is set, the total TCP payload size plus the size of the first packet's L2, L3 and
                                                                 L4 headers. In other words, the total TCP data payload size is [TOTAL] - [TSO_SB].

                                                                 [TOTAL] does not include any of the outside FCS bytes that BGX may append to the
                                                                 packet(s). NIC zero pads the packet when [TOTAL] is larger than the sum of all
                                                                 NIC_SEND_GATHER_S[SIZE]s and NIC_SEND_IMM_S[SIZE]s in the descriptor, or when the packet
                                                                 is less than the minimum size for the interface. */
#else
		uint64_t total                       : 20; /**< [ 19:  0] Total Byte Count. Must be greater than 0. If [TSO] is clear, the total number of bytes to
                                                                 send, including zero pad (if any), and should not exceed the lesser of 9212 (9216 minus 4
                                                                 byte FCS) or NIC_PF_LMAC()_CFG2[MAX_PKT_SIZE].

                                                                 If [TSO] is set, the total TCP payload size plus the size of the first packet's L2, L3 and
                                                                 L4 headers. In other words, the total TCP data payload size is [TOTAL] - [TSO_SB].

                                                                 [TOTAL] does not include any of the outside FCS bytes that BGX may append to the
                                                                 packet(s). NIC zero pads the packet when [TOTAL] is larger than the sum of all
                                                                 NIC_SEND_GATHER_S[SIZE]s and NIC_SEND_IMM_S[SIZE]s in the descriptor, or when the packet
                                                                 is less than the minimum size for the interface. */
		uint64_t reserved_20_23              : 4;  /**< [ 23: 20] Reserved. */
		uint64_t l3ptr                       : 8;  /**< [ 31: 24] Layer 3 IP Offset. Specifies the location of the first byte of the IP packet for L3
                                                                 checksum and/or L4 checksum. (See [CKL3,CKL4].) The IP packet must be exactly [L3PTR]
                                                                 bytes from the beginning of the packet. Software might populate this field for forwarded
                                                                 packets from a computation based off NIC_CQE_RX_S[L3PTR], which is the IP location
                                                                 computed by NIC when the packet is parsed. When [L3PTR] is used for any of [CKL3,CKL4]
                                                                 calculations/modifications, then no L3 nor L2 header bytes indicated by [L3PTR] can
                                                                 overlap with any bytes covered by or inserted by NIC_SEND_CRC_S CRCs. */
		uint64_t l4ptr                       : 8;  /**< [ 39: 32] Layer 4 Offset. Specifies the location of the first byte of the TCP/UDP header for L4
                                                                 checksumming. The Layer 4 header must be exactly [L4PTR] bytes from the beginning of the
                                                                 packet. Software might populate this field for forwarded packets from a computation based
                                                                 off NIC_CQE_RX_S[L4PTR], which is the IP location computed by NIC when the packet is
                                                                 parsed. When [CKL4] is nonzero, no L4 header bytes indicated by [L4PTR] can overlap with
                                                                 any bytes covered by or inserted by NIC_SEND_CRC_S CRCs (but the subsequent L4 payload
                                                                 bytes can overlap with the NIC_SEND_CRC_S CRC bytes). */
		uint64_t reserved_40_41              : 2;  /**< [ 41: 40] Reserved. */
		uint64_t ckle                        : 1;  /**< [ 42: 42] Inner Checksum L3. Similar to [CKL3] but for inner IP.
                                                                 Added in pass 2. */
		uint64_t cklf                        : 2;  /**< [ 44: 43] Inner Checksum L4, enumerated by NIC_SEND_CKL4_E. Similar to [CKL4] but for inner L4.
                                                                 Added in pass 2. */
		uint64_t ckl3                        : 1;  /**< [ 45: 45] Checksum L3. If set, NIC hardware calculates the IPv4 header checksum and inserts it into
                                                                 the packet, as described in L4 Checksum. When set, [L3PTR] selects the location of the
                                                                 first byte of the L3 header and no L3 header bytes selected by [L3PTR] can overlap with
                                                                 any bytes covered or inserted by NIC_SEND_CRC_S CRCs. When [CKL3] is set, [L3PTR] must
                                                                 point to a valid IPv4 header. */
		uint64_t ckl4                        : 2;  /**< [ 47: 46] Checksum L4, enumerated by NIC_SEND_CKL4_E. If nonzero (not NONE):
                                                                 * NIC hardware calculates the Layer 4 TCP/UDP checksum for the packet and inserts it
                                                                 into the packet, as described in L4 Checksum.
                                                                 * [L4PTR] selects the first byte of the L4 header, and [L3PTR] must indicate the location
                                                                 of the immediately proceeding and adjacent L3 header.
                                                                 * The L4 length field must not require more than [TOTAL] bytes in the packet.
                                                                 * When NIC_SEND_CRC_S are present, the bytes covered or inserted by NIC_SEND_CRC_S must
                                                                 all reside in the L4 payload. Conceptually, NIC processes NIC_SEND_CRC_S before L4
                                                                 checksums when both are present. */
		uint64_t subdcnt                     : 8;  /**< [ 55: 48] Subdescriptor count. Number of 128-bit subdescriptors following the send header
                                                                 subdescriptor, including immediate data. Must be between 1 and 255, thus the maximum send
                                                                 descriptor size is 256 subdescriptors (4KB). */
		uint64_t tstmp                       : 1;  /**< [ 56: 56] PTP timestamp. When this is set, [DS] is clear and NIC_PF_QS()_CFG[SEND_TSTMP_ENA]
                                                                 is set, a CQE of NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND_PTP is posted when the
                                                                 packet is transmitted by the targeted Ethernet port. NIC_CQE_SEND_S[PTP_TIMESTAMP] is set
                                                                 to the packet's timestamp. The posted NIC_CQE_TYPE_E::SEND_PTP CQ entry is asynchronous
                                                                 relative to NIC_CQE_TYPE_E::SEND CQ entries in the same CQ.

                                                                 If this bit is set along with [PNC], two entries are posted to the CQ. The first CQ entry
                                                                 is posted with NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND when the send descriptor's
                                                                 operation is done as described above. The second CQ entry is posted with
                                                                 NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND_PTP when the packet's timestamp is
                                                                 captured or times out.

                                                                 Only one timestamp operation may be outstanding at once for a given Ethernet port.
                                                                 Ignored when [DS] is set or NIC_PF_QS()_CFG[SEND_TSTMP_ENA] is clear. */
		uint64_t ds                          : 1;  /**< [ 57: 57] Don't send. If set, NIC hardware will not send the packet bytes to the interface; however
                                                                 it will still perform any NIC_SEND_MEM_S operations. */
		uint64_t pnc                         : 1;  /**< [ 58: 58] Post normal completion. If set, a CQE is created with NIC_CQE_SEND_S[CQE_TYPE] =
                                                                 NIC_CQE_TYPE_E::SEND when the send descriptor's operation completes normally with no
                                                                 error. If clear, no CQE is added on normal completion.

                                                                 Note that a CQE is always added if the send operation terminates with an error after the
                                                                 packet is scheduled; except for LOCK_VIOL, where a CQE is determined  by
                                                                 NIC_PF_QS_CFG[LOCK_VIOL_CQE_EN].

                                                                 NIC will not add a CQE for this send descriptor until after it has completed all L2/DRAM
                                                                 fetches that service all prior NIC_SEND_GATHER_S subdescriptors, and it has fetched all
                                                                 subdescriptors in the send descriptor. If NIC_SEND_MEM_S[WMEM]=1, NIC also will not post
                                                                 the CQE until all NIC_SEND_MEM_S subdescriptors in the descriptor complete and commit. */
		uint64_t tso                         : 1;  /**< [ 59: 59] TCP segmentation offload. When set, the send descriptor is for a TCP segmentation
                                                                 operation to send one or more packets of a TCP flow, and the related [TSO_*] fields are
                                                                 valid. */
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates send header. Enumerated by NIC_SEND_SUBDC_E::HDR. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_104_127            : 24; /**< [127:104] Reserved. */
		uint64_t lfptr                       : 8;  /**< [103: 96] Inner Layer 4 Offset. Similar to [L4PTR] but for inner L4 as directed by [CKLF]. If
                                                                 [CKLF] and [CKL4] are both non-zero, then [LFPTR] must be \> [L4PTR] + 20.
                                                                 Added in pass 2. */
		uint64_t leptr                       : 8;  /**< [ 95: 88] Inner Layer 3 IP Offset. Similar to [L3PTR] but for inner IP as directed by [CKLE]. If
                                                                 [CKLE] and [CKL3] are set, then [LEPTR] must be \> [L3PTR] + 20.
                                                                 Added in pass 2. */
		uint64_t tso_sb                      : 8;  /**< [ 87: 80] Start bytes when [TSO] set. Location of the start byte of the TCP message payload (i.e.
                                                                 the size of the headers preceding the payload). Must be less than [TOTAL], else the send
                                                                 descriptor is treated as non-TSO.
                                                                 Added in pass 2. */
		uint64_t reserved_78_79              : 2;  /**< [ 79: 78] Reserved. */
		uint64_t tso_mps                     : 14; /**< [ 77: 64] When [TSO] set, maximum payload size in bytes per packet (a.k.a. maximum TCP segment
                                                                 size). The maximum TSO packet size is [TSO_SB] + [TSO_MPS], which should not exceed the
                                                                 lesser of 9212 bytes or NIC_PF_LMAC()_CFG2[MAX_PKT_SIZE]. Must be non-zero, else the send
                                                                 descriptor is treated as non-TSO.
                                                                 Added in pass 2. */
#else
		uint64_t tso_mps                     : 14; /**< [ 77: 64] When [TSO] set, maximum payload size in bytes per packet (a.k.a. maximum TCP segment
                                                                 size). The maximum TSO packet size is [TSO_SB] + [TSO_MPS], which should not exceed the
                                                                 lesser of 9212 bytes or NIC_PF_LMAC()_CFG2[MAX_PKT_SIZE]. Must be non-zero, else the send
                                                                 descriptor is treated as non-TSO.
                                                                 Added in pass 2. */
		uint64_t reserved_78_79              : 2;  /**< [ 79: 78] Reserved. */
		uint64_t tso_sb                      : 8;  /**< [ 87: 80] Start bytes when [TSO] set. Location of the start byte of the TCP message payload (i.e.
                                                                 the size of the headers preceding the payload). Must be less than [TOTAL], else the send
                                                                 descriptor is treated as non-TSO.
                                                                 Added in pass 2. */
		uint64_t leptr                       : 8;  /**< [ 95: 88] Inner Layer 3 IP Offset. Similar to [L3PTR] but for inner IP as directed by [CKLE]. If
                                                                 [CKLE] and [CKL3] are set, then [LEPTR] must be \> [L3PTR] + 20.
                                                                 Added in pass 2. */
		uint64_t lfptr                       : 8;  /**< [103: 96] Inner Layer 4 Offset. Similar to [L4PTR] but for inner L4 as directed by [CKLF]. If
                                                                 [CKLF] and [CKL4] are both non-zero, then [LFPTR] must be \> [L4PTR] + 20.
                                                                 Added in pass 2. */
		uint64_t reserved_104_127            : 24; /**< [127:104] Reserved. */
#endif
	} s;
};

/**
 * Structure NIC_SEND_IMM_S
 *
 * NIC Send Immediate Subdescriptor Structure
 * The Send Immediate subdescriptor requests that bytes immediately following this NIC_SEND_IMM_S
 * in the NIC send descriptor are to be included in the packet. The next subdescriptor following
 * this NIC_SEND_IMM_S (when one exists) will follow the immediate bytes, after rounding up to be
 * a multiple of 16 bytes.
 *
 * There may be multiple NIC_SEND_IMM_Ss in one NIC send descriptor. A NIC_SEND_IMM_S must not be
 * present in a NIC send descriptor if the sum of all prior NIC_SEND_GATHER_S[SIZE]s and
 * NIC_SEND_IMM_S[SIZE]s meets or exceeds NIC_SEND_HDR_S[TOTAL].
 */
union nic_send_imm_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Immediate. Enumerated by NIC_SEND_SUBDC_E::IMM. */
		uint64_t reserved_12_59              : 48; /**< [ 59: 12] Reserved. */
		uint64_t size                        : 12; /**< [ 11:  0] Size of immediate data in bytes immediately following this subdescriptor, including the
                                                                 first 8 bytes in the [DATA] field. Size must be between 1 and 4072, and the total send
                                                                 descriptor size cannot exceed 4096 bytes. The next subdescriptor will follow SIZE+8 bytes
                                                                 later, rounded up to the next 16-byte aligned boundary. The subdescriptor is ignored if
                                                                 size is 0. */
#else
		uint64_t size                        : 12; /**< [ 11:  0] Size of immediate data in bytes immediately following this subdescriptor, including the
                                                                 first 8 bytes in the [DATA] field. Size must be between 1 and 4072, and the total send
                                                                 descriptor size cannot exceed 4096 bytes. The next subdescriptor will follow SIZE+8 bytes
                                                                 later, rounded up to the next 16-byte aligned boundary. The subdescriptor is ignored if
                                                                 size is 0. */
		uint64_t reserved_12_59              : 48; /**< [ 59: 12] Reserved. */
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Immediate. Enumerated by NIC_SEND_SUBDC_E::IMM. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< [127: 64] First 8 bytes of immediate data. */
#else
		uint64_t data                        : 64; /**< [127: 64] First 8 bytes of immediate data. */
#endif
	} s;
};

/**
 * Structure NIC_SEND_MEM_S
 *
 * NIC Send-Memory Subdescriptor Structure
 * The Send Memory subdescriptor atomically sets, increments or decrements a memory location. NIC
 * will not initiate the memory update for this subdescriptor until after it has processed all
 * other subdescriptors for the packet and all L2/DRAM fetches that service all NIC_SEND_GATHER_S
 * subdescriptors.
 *
 * Performance is best if a memory decrement by one is used rather than any other memory
 * set/increment/decrement. (Less internal bus bandwidth is used with memory decrements by one.)
 * NIC performance may be impacted if a send descriptor has more than 4 NIC_SEND_MEM_S
 * subdescriptors.
 */
union nic_send_mem_s {
	uint64_t u[2];
	struct {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Memory. Enumerated by NIC_SEND_SUBDC_E::MEM. */
		uint64_t alg                         : 4;  /**< [ 59: 56] Adder algorithm. How to modify the memory location, for example by setting or atomically
                                                                 incrementing. Enumerated by NIC_SEND_MEMALG_E. */
		uint64_t dsz                         : 2;  /**< [ 55: 54] Memory data size. The size of the word in memory, enumerated by NIC_SEND_MEMDSZ_E. */
		uint64_t wmem                        : 1;  /**< [ 53: 53] When NIC_SEND_HDR_S[PNC] is set, wait for memory operation to be committed before posting
                                                                 to the CQ. When clear, the memory operation may complete after the CQE is added and
                                                                 potentially after software has begun servicing the CQE. */
		uint64_t reserved_32_52              : 21; /**< [ 52: 32] Reserved. */
		uint64_t offset                      : 32; /**< [ 31:  0] Adder offset. Constant value to add or subtract or set. If the count being modified is to
                                                                 represent the true packet size, then the offset would represent the CRC and pad bytes
                                                                 appended to the packet. INTERNAL: Note IOB hardware has a special encoding for atomic
                                                                 increment/decrement, therefore a change of +/- one is twice as IOB bandwidth efficient as
                                                                 adding/subtracting other values. */
#else
		uint64_t offset                      : 32; /**< [ 31:  0] Adder offset. Constant value to add or subtract or set. If the count being modified is to
                                                                 represent the true packet size, then the offset would represent the CRC and pad bytes
                                                                 appended to the packet. INTERNAL: Note IOB hardware has a special encoding for atomic
                                                                 increment/decrement, therefore a change of +/- one is twice as IOB bandwidth efficient as
                                                                 adding/subtracting other values. */
		uint64_t reserved_32_52              : 21; /**< [ 52: 32] Reserved. */
		uint64_t wmem                        : 1;  /**< [ 53: 53] When NIC_SEND_HDR_S[PNC] is set, wait for memory operation to be committed before posting
                                                                 to the CQ. When clear, the memory operation may complete after the CQE is added and
                                                                 potentially after software has begun servicing the CQE. */
		uint64_t dsz                         : 2;  /**< [ 55: 54] Memory data size. The size of the word in memory, enumerated by NIC_SEND_MEMDSZ_E. */
		uint64_t alg                         : 4;  /**< [ 59: 56] Adder algorithm. How to modify the memory location, for example by setting or atomically
                                                                 incrementing. Enumerated by NIC_SEND_MEMALG_E. */
		uint64_t subdc                       : 4;  /**< [ 63: 60] Subdescriptor code. Indicates Send Memory. Enumerated by NIC_SEND_SUBDC_E::MEM. */
#endif
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_113_127            : 15; /**< [127:113] Reserved. INTERNAL: For 64-bit addresses. */
		uint64_t addr                        : 49; /**< [112: 64] Address. VA, IPA or PA (depending on SMMU configuration) to be modified. ADDR must be
                                                                 naturally aligned to the size specified in DSZ. */
#else
		uint64_t addr                        : 49; /**< [112: 64] Address. VA, IPA or PA (depending on SMMU configuration) to be modified. ADDR must be
                                                                 naturally aligned to the size specified in DSZ. */
		uint64_t reserved_113_127            : 15; /**< [127:113] Reserved. INTERNAL: For 64-bit addresses. */
#endif
	} s;
};


/**
 * NCB - nic_pf_bist0_status
 *
 * This register reports memory BIST status. Each bit corresponds to a different RAM; 0 = pass, 1
 * = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC0_FLIP0.
 */
typedef union bdk_nic_pf_bist0_status {
	uint64_t u;
	struct bdk_nic_pf_bist0_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< RO/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< RO/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< RO/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< RO/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_bist0_status_s   cn88xx; */
	struct bdk_nic_pf_bist0_status_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< RO/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< RO/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< RO/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_bist0_status_t;

#define BDK_NIC_PF_BIST0_STATUS BDK_NIC_PF_BIST0_STATUS_FUNC()
static inline uint64_t BDK_NIC_PF_BIST0_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_BIST0_STATUS_FUNC(void)
{
	return 0x0000843000001280ull;
}
#define typedef_BDK_NIC_PF_BIST0_STATUS bdk_nic_pf_bist0_status_t
#define bustype_BDK_NIC_PF_BIST0_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_BIST0_STATUS 0
#define arguments_BDK_NIC_PF_BIST0_STATUS -1,-1,-1,-1
#define basename_BDK_NIC_PF_BIST0_STATUS "NIC_PF_BIST0_STATUS"


/**
 * NCB - nic_pf_bist1_status
 *
 * See NIC_PF_BIST0_STATUS.
 *
 */
typedef union bdk_nic_pf_bist1_status {
	uint64_t u;
	struct bdk_nic_pf_bist1_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< RO/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< RO/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_bist1_status_s   cn88xx; */
	/* struct bdk_nic_pf_bist1_status_s   cn88xxp1; */
} bdk_nic_pf_bist1_status_t;

#define BDK_NIC_PF_BIST1_STATUS BDK_NIC_PF_BIST1_STATUS_FUNC()
static inline uint64_t BDK_NIC_PF_BIST1_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_BIST1_STATUS_FUNC(void)
{
	return 0x0000843000001288ull;
}
#define typedef_BDK_NIC_PF_BIST1_STATUS bdk_nic_pf_bist1_status_t
#define bustype_BDK_NIC_PF_BIST1_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_BIST1_STATUS 0
#define arguments_BDK_NIC_PF_BIST1_STATUS -1,-1,-1,-1
#define basename_BDK_NIC_PF_BIST1_STATUS "NIC_PF_BIST1_STATUS"


/**
 * NCB - nic_pf_bist2_status
 *
 * See NIC_PF_BIST0_STATUS.
 *
 */
typedef union bdk_nic_pf_bist2_status {
	uint64_t u;
	struct bdk_nic_pf_bist2_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< RO/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_bist2_status_s   cn88xx; */
	/* struct bdk_nic_pf_bist2_status_s   cn88xxp1; */
} bdk_nic_pf_bist2_status_t;

#define BDK_NIC_PF_BIST2_STATUS BDK_NIC_PF_BIST2_STATUS_FUNC()
static inline uint64_t BDK_NIC_PF_BIST2_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_BIST2_STATUS_FUNC(void)
{
	return 0x0000843000001290ull;
}
#define typedef_BDK_NIC_PF_BIST2_STATUS bdk_nic_pf_bist2_status_t
#define bustype_BDK_NIC_PF_BIST2_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_BIST2_STATUS 0
#define arguments_BDK_NIC_PF_BIST2_STATUS -1,-1,-1,-1
#define basename_BDK_NIC_PF_BIST2_STATUS "NIC_PF_BIST2_STATUS"


/**
 * NCB - nic_pf_bist3_status
 *
 * See NIC_PF_BIST0_STATUS.
 *
 */
typedef union bdk_nic_pf_bist3_status {
	uint64_t u;
	struct bdk_nic_pf_bist3_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< RO/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< RO/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_bist3_status_s   cn88xx; */
	/* struct bdk_nic_pf_bist3_status_s   cn88xxp1; */
} bdk_nic_pf_bist3_status_t;

#define BDK_NIC_PF_BIST3_STATUS BDK_NIC_PF_BIST3_STATUS_FUNC()
static inline uint64_t BDK_NIC_PF_BIST3_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_BIST3_STATUS_FUNC(void)
{
	return 0x0000843000001298ull;
}
#define typedef_BDK_NIC_PF_BIST3_STATUS bdk_nic_pf_bist3_status_t
#define bustype_BDK_NIC_PF_BIST3_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_BIST3_STATUS 0
#define arguments_BDK_NIC_PF_BIST3_STATUS -1,-1,-1,-1
#define basename_BDK_NIC_PF_BIST3_STATUS "NIC_PF_BIST3_STATUS"


/**
 * NCB - nic_pf_bp_cfg
 */
typedef union bdk_nic_pf_bp_cfg {
	uint64_t u;
	struct bdk_nic_pf_bp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t bp_poll_ena                 : 1;  /**< R/W - This bit enables the backpressure polling loop. */
		uint64_t bp_poll_dly                 : 6;  /**< R/W - Number of cycles between polling the various RQ resources for backpressure updates.
                                                                 Increasing values decrease power. Zero cause the BP polling to operation at the fastest
                                                                 possible speed, one indicates a level computation every other cycle, etc. */
#else
		uint64_t bp_poll_dly                 : 6;
		uint64_t bp_poll_ena                 : 1;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_nic_pf_bp_cfg_s         cn88xx; */
	/* struct bdk_nic_pf_bp_cfg_s         cn88xxp1; */
} bdk_nic_pf_bp_cfg_t;

#define BDK_NIC_PF_BP_CFG BDK_NIC_PF_BP_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_BP_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_BP_CFG_FUNC(void)
{
	return 0x0000843000000080ull;
}
#define typedef_BDK_NIC_PF_BP_CFG bdk_nic_pf_bp_cfg_t
#define bustype_BDK_NIC_PF_BP_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_BP_CFG 0
#define arguments_BDK_NIC_PF_BP_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_BP_CFG "NIC_PF_BP_CFG"


/**
 * NCB - nic_pf_cfg
 */
typedef union bdk_nic_pf_cfg {
	uint64_t u;
	struct bdk_nic_pf_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t test_mode                   : 1;  /**< R/W - Enable test mode. Must be clear during normal operation in order to prevent a VF from
                                                                 corrupting the operation of other VFs. When clear, writes to all CQ, SQ and RBDR ring
                                                                 pointers (head, tail, debug) are ignored (WI). When set, writing to the ring
                                                                 pointers is enabled. */
		uint64_t ena                         : 1;  /**< R/W - Enable NIC block. INTERNAL: Used to enable conditional SCLK. */
#else
		uint64_t ena                         : 1;
		uint64_t test_mode                   : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_nic_pf_cfg_s            cn88xx; */
	/* struct bdk_nic_pf_cfg_s            cn88xxp1; */
} bdk_nic_pf_cfg_t;

#define BDK_NIC_PF_CFG BDK_NIC_PF_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CFG_FUNC(void)
{
	return 0x0000843000000000ull;
}
#define typedef_BDK_NIC_PF_CFG bdk_nic_pf_cfg_t
#define bustype_BDK_NIC_PF_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CFG 0
#define arguments_BDK_NIC_PF_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_CFG "NIC_PF_CFG"


/**
 * NCB - nic_pf_chan#_credit
 *
 * Configures channel credits. Fields are the same as NIC_PF_LMAC()_CREDIT, though the
 * credits apply to a channel rather than an LMAC.
 */
typedef union bdk_nic_pf_chanx_credit {
	uint64_t u;
	struct bdk_nic_pf_chanx_credit_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t cc_unit_cnt                 : 20; /**< R/W/H - Channel-credit unit count. This value, plus 1 MTU, represents the maximum outstanding
                                                                 aggregate channel credit units for this LMAC. A credit unit is 16 bytes when the
                                                                 associated TNS interface is bypassed (NIC_PF_INTF()_SEND_CFG[TNS_NONBYPASS] is clear),
                                                                 and one TNS credit unit otherwise, as specified by
                                                                 NIC_PF_INTF()_SEND_CFG[TNS_CREDIT_SIZE]. Note that this 20-bit field represents a
                                                                 signed value that decrements towards zero as credits are used. Packets are not allowed to
                                                                 flow when the count is less than zero. As such, the most significant bit should normally
                                                                 be programmed as zero (positive count). This gives a maximum value for this field of 2^19
                                                                 - 1.

                                                                 In order to prevent blocking between LMACs when the associated TNS interface is bypassed,
                                                                 CC_ENABLE should be set to 1 and CC_UNIT_CNT should be less than

                                                                 _     ((LMAC TX buffer size in BGX) - (MTU excluding FCS))/16

                                                                 The LMAC TX buffer size is defined by BGX()_CMR_TX_LMACS[LMACS]. For example, if TNS is
                                                                 bypassed, BGX()_CMR_TX_LMACS[LMACS]=0x4 (12 KB per LMAC) and the LMAC's MTU excluding FCS
                                                                 is 9212 bytes (9216 minus 4 byte FCS), then CC_UNIT_CNT should be \< (12288 - 9212)/16 =
                                                                 192. */
		uint64_t cc_packet_cnt               : 10; /**< R/W/H - Channel-credit packet count. This value, plus 1, represents the maximum outstanding
                                                                 aggregate packet count for this LMAC. Note that this 10-bit field represents a signed
                                                                 value that decrements towards zero as credits are used. Packets are not allowed to flow
                                                                 when the count is less than zero. As such the most significant bit should normally be
                                                                 programmed as zero (positive count). This gives a maximum value for this field of 2^9 - 1. */
		uint64_t cc_enable                   : 1;  /**< R/W - Channel-credit enable. Enables CC_UNIT_CNT and CC_PACKET_CNT aggregate credit processing. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t cc_enable                   : 1;
		uint64_t cc_packet_cnt               : 10;
		uint64_t cc_unit_cnt                 : 20;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_chanx_credit_s   cn88xx; */
	/* struct bdk_nic_pf_chanx_credit_s   cn88xxp1; */
} bdk_nic_pf_chanx_credit_t;

static inline uint64_t BDK_NIC_PF_CHANX_CREDIT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CHANX_CREDIT(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000460000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CHANX_CREDIT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CHANX_CREDIT(...) bdk_nic_pf_chanx_credit_t
#define bustype_BDK_NIC_PF_CHANX_CREDIT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CHANX_CREDIT(p1) (p1)
#define arguments_BDK_NIC_PF_CHANX_CREDIT(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CHANX_CREDIT(...) "NIC_PF_CHANX_CREDIT"


/**
 * NCB - nic_pf_chan#_rx_bp_cfg
 */
typedef union bdk_nic_pf_chanx_rx_bp_cfg {
	uint64_t u;
	struct bdk_nic_pf_chanx_rx_bp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ena                         : 1;  /**< R/W - This bit is set to enable backpressure for this channel. */
		uint64_t reserved_8_62               : 55;
		uint64_t bpid                        : 8;  /**< R/W - BPID used for RX_CHAN backpressure. */
#else
		uint64_t bpid                        : 8;
		uint64_t reserved_8_62               : 55;
		uint64_t ena                         : 1;
#endif
	} s;
	/* struct bdk_nic_pf_chanx_rx_bp_cfg_s cn88xx; */
	/* struct bdk_nic_pf_chanx_rx_bp_cfg_s cn88xxp1; */
} bdk_nic_pf_chanx_rx_bp_cfg_t;

static inline uint64_t BDK_NIC_PF_CHANX_RX_BP_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CHANX_RX_BP_CFG(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000480000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CHANX_RX_BP_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CHANX_RX_BP_CFG(...) bdk_nic_pf_chanx_rx_bp_cfg_t
#define bustype_BDK_NIC_PF_CHANX_RX_BP_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CHANX_RX_BP_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_CHANX_RX_BP_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CHANX_RX_BP_CFG(...) "NIC_PF_CHANX_RX_BP_CFG"


/**
 * NCB - nic_pf_chan#_rx_cfg
 */
typedef union bdk_nic_pf_chanx_rx_cfg {
	uint64_t u;
	struct bdk_nic_pf_chanx_rx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t cpi_alg                     : 2;  /**< R/W - Algorithm used in QPG calculation. Enumerated by NIC_CPI_ALG_E. */
		uint64_t reserved_59_61              : 3;
		uint64_t cpi_base                    : 11; /**< R/W - Base index into NIC_PF_CPI()_CFG. */
		uint64_t reserved_0_47               : 48;
#else
		uint64_t reserved_0_47               : 48;
		uint64_t cpi_base                    : 11;
		uint64_t reserved_59_61              : 3;
		uint64_t cpi_alg                     : 2;
#endif
	} s;
	/* struct bdk_nic_pf_chanx_rx_cfg_s   cn88xx; */
	/* struct bdk_nic_pf_chanx_rx_cfg_s   cn88xxp1; */
} bdk_nic_pf_chanx_rx_cfg_t;

static inline uint64_t BDK_NIC_PF_CHANX_RX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CHANX_RX_CFG(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000420000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CHANX_RX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CHANX_RX_CFG(...) bdk_nic_pf_chanx_rx_cfg_t
#define bustype_BDK_NIC_PF_CHANX_RX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CHANX_RX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_CHANX_RX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CHANX_RX_CFG(...) "NIC_PF_CHANX_RX_CFG"


/**
 * NCB - nic_pf_chan#_sw_xoff
 */
typedef union bdk_nic_pf_chanx_sw_xoff {
	uint64_t u;
	struct bdk_nic_pf_chanx_sw_xoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t bp_xoff                     : 1;  /**< RO/H - Backpressure XOFF. When set, this channel does not send traffic due to being backpressured. */
		uint64_t sw_xoff                     : 1;  /**< R/W - Software XOFF. When set, this channel does not send traffic. */
#else
		uint64_t sw_xoff                     : 1;
		uint64_t bp_xoff                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_nic_pf_chanx_sw_xoff_s  cn88xx; */
	/* struct bdk_nic_pf_chanx_sw_xoff_s  cn88xxp1; */
} bdk_nic_pf_chanx_sw_xoff_t;

static inline uint64_t BDK_NIC_PF_CHANX_SW_XOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CHANX_SW_XOFF(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000440000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CHANX_SW_XOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CHANX_SW_XOFF(...) bdk_nic_pf_chanx_sw_xoff_t
#define bustype_BDK_NIC_PF_CHANX_SW_XOFF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CHANX_SW_XOFF(p1) (p1)
#define arguments_BDK_NIC_PF_CHANX_SW_XOFF(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CHANX_SW_XOFF(...) "NIC_PF_CHANX_SW_XOFF"


/**
 * NCB - nic_pf_chan#_tx_cfg
 */
typedef union bdk_nic_pf_chanx_tx_cfg {
	uint64_t u;
	struct bdk_nic_pf_chanx_tx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t bp_ena                      : 1;  /**< R/W - Enables listening for backpressure on this channel. */
#else
		uint64_t bp_ena                      : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_chanx_tx_cfg_s   cn88xx; */
	/* struct bdk_nic_pf_chanx_tx_cfg_s   cn88xxp1; */
} bdk_nic_pf_chanx_tx_cfg_t;

static inline uint64_t BDK_NIC_PF_CHANX_TX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CHANX_TX_CFG(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000400000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CHANX_TX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CHANX_TX_CFG(...) bdk_nic_pf_chanx_tx_cfg_t
#define bustype_BDK_NIC_PF_CHANX_TX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CHANX_TX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_CHANX_TX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CHANX_TX_CFG(...) "NIC_PF_CHANX_TX_CFG"


/**
 * NCB - nic_pf_cpi#_cfg
 */
typedef union bdk_nic_pf_cpix_cfg {
	uint64_t u;
	struct bdk_nic_pf_cpix_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_31_63              : 33;
		uint64_t vnic                        : 7;  /**< R/W - VNIC receiving this channel, and determines which RSS algorithms are enabled using
                                                                 NIC_VNIC()_RSS_CFG. */
		uint64_t rss_size                    : 4;  /**< R/W - Bits of RSS hash to add in RSSI calculation.
                                                                 0x0 = RSS is disabled.
                                                                 0x1 = RSS_TAG\<0\> included in RSSI.
                                                                 0x2 = RSS_TAG\<1:0\> included in RSSI.
                                                                 0x3 = RSS_TAG\<2:0\> included in RSSI.
                                                                 0x4 = RSS_TAG\<3:0\> included in RSSI.
                                                                 0x5 = RSS_TAG\<4:0\> included in RSSI.
                                                                 0x6 = RSS_TAG\<5:0\> included in RSSI.
                                                                 0x7 = RSS_TAG\<6:0\> included in RSSI.
                                                                 0x8 = RSS_TAG\<7:0\> included in RSSI.
                                                                 0x9-0xF = Reserved. */
		uint64_t padd                        : 4;  /**< R/W - Port to channel adder for calculating NIC_CQE_RX_S[CHAN]. For NIC channels should be zero. */
		uint64_t reserved_12_15              : 4;
		uint64_t rssi_base                   : 12; /**< R/W - Base index into NIC_PF_RSSI()_RQ. */
#else
		uint64_t rssi_base                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t padd                        : 4;
		uint64_t rss_size                    : 4;
		uint64_t vnic                        : 7;
		uint64_t reserved_31_63              : 33;
#endif
	} s;
	/* struct bdk_nic_pf_cpix_cfg_s       cn88xx; */
	/* struct bdk_nic_pf_cpix_cfg_s       cn88xxp1; */
} bdk_nic_pf_cpix_cfg_t;

static inline uint64_t BDK_NIC_PF_CPIX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CPIX_CFG(unsigned long param1)
{
	if (((param1 <= 2047)))
		return 0x0000843000200000ull + (param1 & 2047) * 0x8ull;
	csr_fatal("BDK_NIC_PF_CPIX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_CPIX_CFG(...) bdk_nic_pf_cpix_cfg_t
#define bustype_BDK_NIC_PF_CPIX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CPIX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_CPIX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_CPIX_CFG(...) "NIC_PF_CPIX_CFG"


/**
 * NCB - nic_pf_cq_avg_cfg
 */
typedef union bdk_nic_pf_cq_avg_cfg {
	uint64_t u;
	struct bdk_nic_pf_cq_avg_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t avg_en                      : 1;  /**< R/W - QoS averaging enable. When set, compute average buffer levels. When clear, do not compute
                                                                 averages and save a few mW of power. */
		uint64_t lvl_dly                     : 6;  /**< R/W - Levelizer delay. Number of cycles between level computations for backpressure and RED.
                                                                 Increasing values decrease power. Zero disables, one indicates a level computation every
                                                                 other cycle, etc. Once set to nonzero must not be later set to zero without resetting NIC. */
		uint64_t avg_dly                     : 14; /**< R/W - Average-queue-size delay. The number of levelizer-clock cycles to wait (1024 *
                                                                 ([AVG_DLY]+1) * ([LVL_DLY]+1)) coprocessor clocks) between calculating the moving averages
                                                                 for each RQ. Note the minimum value of 2048 cycles implies that at 50 M packets/sec, and a
                                                                 coprocessor clock of 800 MHz, approximately 120 packets may arrive between average
                                                                 calculations.

                                                                 Larger [LVL_DLY] values cause the backpressure indications and moving averages of all aura
                                                                 levels to track changes in the actual free space more slowly. Larger AVG_DLY also causes
                                                                 the moving averages of all levels to track changes in the actual free space more slowly,
                                                                 but does not affect backpressure. Larger NIC_QS()_CQ()_CFG[AVG_CON] or
                                                                 NIC_QS()_RBDR()_CFG[AVG_CON]) values causes a specific aura to track more
                                                                 slowly, but only affects an individual aura level, rather than all. */
#else
		uint64_t avg_dly                     : 14;
		uint64_t lvl_dly                     : 6;
		uint64_t avg_en                      : 1;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_nic_pf_cq_avg_cfg_s     cn88xx; */
	/* struct bdk_nic_pf_cq_avg_cfg_s     cn88xxp1; */
} bdk_nic_pf_cq_avg_cfg_t;

#define BDK_NIC_PF_CQ_AVG_CFG BDK_NIC_PF_CQ_AVG_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_CQ_AVG_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CQ_AVG_CFG_FUNC(void)
{
	return 0x00008430000000C0ull;
}
#define typedef_BDK_NIC_PF_CQ_AVG_CFG bdk_nic_pf_cq_avg_cfg_t
#define bustype_BDK_NIC_PF_CQ_AVG_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CQ_AVG_CFG 0
#define arguments_BDK_NIC_PF_CQ_AVG_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_CQ_AVG_CFG "NIC_PF_CQ_AVG_CFG"


/**
 * NCB - nic_pf_cqm_cfg
 */
typedef union bdk_nic_pf_cqm_cfg {
	uint64_t u;
	struct bdk_nic_pf_cqm_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t drop_level                  : 16; /**< R/W - Drop level. The minimum FIFO level before all packets for the CQ are dropped. This value
                                                                 can be increased to insure that once a packet has been "accepted", it will not get
                                                                 truncated due to buffer exhaustion. */
#else
		uint64_t drop_level                  : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_pf_cqm_cfg_s        cn88xx; */
	/* struct bdk_nic_pf_cqm_cfg_s        cn88xxp1; */
} bdk_nic_pf_cqm_cfg_t;

#define BDK_NIC_PF_CQM_CFG BDK_NIC_PF_CQM_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_CQM_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CQM_CFG_FUNC(void)
{
	return 0x00008430000000A0ull;
}
#define typedef_BDK_NIC_PF_CQM_CFG bdk_nic_pf_cqm_cfg_t
#define bustype_BDK_NIC_PF_CQM_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CQM_CFG 0
#define arguments_BDK_NIC_PF_CQM_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_CQM_CFG "NIC_PF_CQM_CFG"


/**
 * NCB - nic_pf_cqm_test
 */
typedef union bdk_nic_pf_cqm_test {
	uint64_t u;
	struct bdk_nic_pf_cqm_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = Reserved.
                                                                 \<61\> = Reserved
                                                                 \<60\> = CQM_INTR_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_cqm_test_s       cn88xx; */
	/* struct bdk_nic_pf_cqm_test_s       cn88xxp1; */
} bdk_nic_pf_cqm_test_t;

#define BDK_NIC_PF_CQM_TEST BDK_NIC_PF_CQM_TEST_FUNC()
static inline uint64_t BDK_NIC_PF_CQM_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CQM_TEST_FUNC(void)
{
	return 0x00008430000000D0ull;
}
#define typedef_BDK_NIC_PF_CQM_TEST bdk_nic_pf_cqm_test_t
#define bustype_BDK_NIC_PF_CQM_TEST BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CQM_TEST 0
#define arguments_BDK_NIC_PF_CQM_TEST -1,-1,-1,-1
#define basename_BDK_NIC_PF_CQM_TEST "NIC_PF_CQM_TEST"


/**
 * NCB - nic_pf_csi_test
 */
typedef union bdk_nic_pf_csi_test {
	uint64_t u;
	struct bdk_nic_pf_csi_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = Reserved.
                                                                 \<61\> = Reserved.
                                                                 \<60\> = PIB_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_csi_test_s       cn88xx; */
	/* struct bdk_nic_pf_csi_test_s       cn88xxp1; */
} bdk_nic_pf_csi_test_t;

#define BDK_NIC_PF_CSI_TEST BDK_NIC_PF_CSI_TEST_FUNC()
static inline uint64_t BDK_NIC_PF_CSI_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_CSI_TEST_FUNC(void)
{
	return 0x00008430000000F0ull;
}
#define typedef_BDK_NIC_PF_CSI_TEST bdk_nic_pf_csi_test_t
#define bustype_BDK_NIC_PF_CSI_TEST BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_CSI_TEST 0
#define arguments_BDK_NIC_PF_CSI_TEST -1,-1,-1,-1
#define basename_BDK_NIC_PF_CSI_TEST "NIC_PF_CSI_TEST"


/**
 * NCB - nic_pf_ecc0_cdis
 *
 * This register can be used to disable ECC correction for testing. Each bit that is set disables
 * ECC correction on read operations from a corresponding RAM.
 */
typedef union bdk_nic_pf_ecc0_cdis {
	uint64_t u;
	struct bdk_nic_pf_ecc0_cdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W - Group 0 Block 3 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<31:0\> = Reserved

                                                                 Pass 2+:
                                                                   \<31:26\> = Reserved.
                                                                   \<25\>  =
                                                                 nic_l.core.reb.nic_reb_core.nic_reb_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifo
                                                                 mem_128x128.
                                                                   \<24\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.
                                                                   \<23:16\>  =
                                                                 nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<15:8\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<7:0\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem. */
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_cdis_s      cn88xx; */
	struct bdk_nic_pf_ecc0_cdis_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_cdis_t;

#define BDK_NIC_PF_ECC0_CDIS BDK_NIC_PF_ECC0_CDIS_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_CDIS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_CDIS_FUNC(void)
{
	return 0x0000843000001100ull;
}
#define typedef_BDK_NIC_PF_ECC0_CDIS bdk_nic_pf_ecc0_cdis_t
#define bustype_BDK_NIC_PF_ECC0_CDIS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_CDIS 0
#define arguments_BDK_NIC_PF_ECC0_CDIS -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_CDIS "NIC_PF_ECC0_CDIS"


/**
 * NCB - nic_pf_ecc0_dbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc0_dbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc0_dbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_dbe_ena_w1c_s cn88xx; */
	struct bdk_nic_pf_ecc0_dbe_ena_w1c_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_dbe_ena_w1c_t;

#define BDK_NIC_PF_ECC0_DBE_ENA_W1C BDK_NIC_PF_ECC0_DBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_DBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_DBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002110ull;
}
#define typedef_BDK_NIC_PF_ECC0_DBE_ENA_W1C bdk_nic_pf_ecc0_dbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC0_DBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_DBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC0_DBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_DBE_ENA_W1C "NIC_PF_ECC0_DBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc0_dbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc0_dbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc0_dbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_dbe_ena_w1s_s cn88xx; */
	struct bdk_nic_pf_ecc0_dbe_ena_w1s_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_dbe_ena_w1s_t;

#define BDK_NIC_PF_ECC0_DBE_ENA_W1S BDK_NIC_PF_ECC0_DBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_DBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_DBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002118ull;
}
#define typedef_BDK_NIC_PF_ECC0_DBE_ENA_W1S bdk_nic_pf_ecc0_dbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC0_DBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_DBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC0_DBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_DBE_ENA_W1S "NIC_PF_ECC0_DBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc0_dbe_int
 *
 * Reports double-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC0_FLIP0.
 */
typedef union bdk_nic_pf_ecc0_dbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc0_dbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_dbe_int_s   cn88xx; */
	struct bdk_nic_pf_ecc0_dbe_int_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_dbe_int_t;

#define BDK_NIC_PF_ECC0_DBE_INT BDK_NIC_PF_ECC0_DBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_DBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_DBE_INT_FUNC(void)
{
	return 0x0000843000002100ull;
}
#define typedef_BDK_NIC_PF_ECC0_DBE_INT bdk_nic_pf_ecc0_dbe_int_t
#define bustype_BDK_NIC_PF_ECC0_DBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_DBE_INT 0
#define arguments_BDK_NIC_PF_ECC0_DBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_DBE_INT "NIC_PF_ECC0_DBE_INT"


/**
 * NCB - nic_pf_ecc0_dbe_int_w1s
 */
typedef union bdk_nic_pf_ecc0_dbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc0_dbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_dbe_int_w1s_s cn88xx; */
	struct bdk_nic_pf_ecc0_dbe_int_w1s_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_dbe_int_w1s_t;

#define BDK_NIC_PF_ECC0_DBE_INT_W1S BDK_NIC_PF_ECC0_DBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_DBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_DBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002108ull;
}
#define typedef_BDK_NIC_PF_ECC0_DBE_INT_W1S bdk_nic_pf_ecc0_dbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC0_DBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_DBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC0_DBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_DBE_INT_W1S "NIC_PF_ECC0_DBE_INT_W1S"


/**
 * NCB - nic_pf_ecc0_flip0
 *
 * This register allows inserting ECC errors for testing. Each bit that is set flips bit \<0\> on
 * writes to a corresponding RAM to test single-bit or double-bit error handling.
 */
typedef union bdk_nic_pf_ecc0_flip0 {
	uint64_t u;
	struct bdk_nic_pf_ecc0_flip0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W - Group 0 Block 3 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<31:0\> = Reserved

                                                                 Pass 2+:
                                                                   \<31:26\> = Reserved.
                                                                   \<25\>  =
                                                                 nic_l.core.reb.nic_reb_core.nic_reb_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifo
                                                                 mem_128x128.
                                                                   \<24\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.
                                                                   \<23:16\>  =
                                                                 nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<15:8\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<7:0\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem. */
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_flip0_s     cn88xx; */
	struct bdk_nic_pf_ecc0_flip0_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_flip0_t;

#define BDK_NIC_PF_ECC0_FLIP0 BDK_NIC_PF_ECC0_FLIP0_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_FLIP0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_FLIP0_FUNC(void)
{
	return 0x0000843000001000ull;
}
#define typedef_BDK_NIC_PF_ECC0_FLIP0 bdk_nic_pf_ecc0_flip0_t
#define bustype_BDK_NIC_PF_ECC0_FLIP0 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_FLIP0 0
#define arguments_BDK_NIC_PF_ECC0_FLIP0 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_FLIP0 "NIC_PF_ECC0_FLIP0"


/**
 * NCB - nic_pf_ecc0_flip1
 *
 * This register allows inserting ECC errors for testing. Each bit that is set flips bit \<1\> on
 * writes to a corresponding RAM to test single-bit or double-bit error handling.
 */
typedef union bdk_nic_pf_ecc0_flip1 {
	uint64_t u;
	struct bdk_nic_pf_ecc0_flip1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W - Group 0 Block 3 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<31:0\> = Reserved

                                                                 Pass 2+:
                                                                   \<31:26\> = Reserved.
                                                                   \<25\>  =
                                                                 nic_l.core.reb.nic_reb_core.nic_reb_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifo
                                                                 mem_128x128.
                                                                   \<24\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.
                                                                   \<23:16\>  =
                                                                 nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<15:8\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<7:0\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{7..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem. */
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_flip1_s     cn88xx; */
	struct bdk_nic_pf_ecc0_flip1_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W - Group 0 Block 2 memories. INTERNAL: REB memories:

                                                                 Changed in pass 2.

                                                                 Pass 1:
                                                                   \<15:9\> = Reserved.
                                                                   \<8:7\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.nic_reb_cqe_stdn_buffer.nic_reb_fifo_128x128.nic_reb_fifomem_128x128.
                                                                   \<6:5\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_cq_pi
                                                                 peline.cq_main_body_fifo.nic_reb_fifo_16x128.nic_reb_fifomem_16x128.
                                                                   \<4:3\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_ncx_f
                                                                 ifo.nic_reb_fifo_35x144_no_rd_lat.nic_reb_fifo_32x144.nic_reb_fifomem_32x144.
                                                                   \<2:1\>  = nic_l.core.reb.nic_reb_core.reb_pipeline{1..0}.nic_reb_data_proc.nic_reb_datap
                                                                 ath_fifo.nic_reb_fifo_128x132.nic_reb_fifomem.
                                                                   \<0\>  = nic_l.core.reb.nic_reb_core.nic_reb_resp_fifo.data_fifo.nic_reb_fifomem.

                                                                 Pass 2+:
                                                                   \<15:0\> = Reserved. */
		uint64_t blk1                        : 8;  /**< R/W - Group 0 Block 1 memories. INTERNAL: CSI memories:
                                                                 \<7:0\> = Reserved.
                                                                 \<4\>   = nic_l.core.csi.rpi.vfi.int_mem_mem.
                                                                 \<3\>   = nic_l.core.csi.rpi.msix_pmem.
                                                                 \<2\>   = nic_l.core.csi.rpi.msix_vmem.
                                                                 \<1\>   = nic_l.core.csi.mbox.mbox_mem_mem.
                                                                 \<0\>   = nic_l.core.csi.bcast.bcast_mem_mem. */
		uint64_t blk0                        : 8;  /**< R/W - Group 0 Block 0 memories. INTERNAL: CQM memories:
                                                                 \<7:2\> = Reserved.
                                                                 \<1\>   = nic_l.core.cqm.cin.cq_timer.cq_timer_mem.
                                                                 \<0\>   = nic_l.core.cqm.cin.cq.cq_mem. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_flip1_t;

#define BDK_NIC_PF_ECC0_FLIP1 BDK_NIC_PF_ECC0_FLIP1_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_FLIP1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_FLIP1_FUNC(void)
{
	return 0x0000843000001080ull;
}
#define typedef_BDK_NIC_PF_ECC0_FLIP1 bdk_nic_pf_ecc0_flip1_t
#define bustype_BDK_NIC_PF_ECC0_FLIP1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_FLIP1 0
#define arguments_BDK_NIC_PF_ECC0_FLIP1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_FLIP1 "NIC_PF_ECC0_FLIP1"


/**
 * NCB - nic_pf_ecc0_sbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc0_sbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc0_sbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_sbe_ena_w1c_s cn88xx; */
	struct bdk_nic_pf_ecc0_sbe_ena_w1c_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_sbe_ena_w1c_t;

#define BDK_NIC_PF_ECC0_SBE_ENA_W1C BDK_NIC_PF_ECC0_SBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_SBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_SBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002010ull;
}
#define typedef_BDK_NIC_PF_ECC0_SBE_ENA_W1C bdk_nic_pf_ecc0_sbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC0_SBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_SBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC0_SBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_SBE_ENA_W1C "NIC_PF_ECC0_SBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc0_sbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc0_sbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc0_sbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_sbe_ena_w1s_s cn88xx; */
	struct bdk_nic_pf_ecc0_sbe_ena_w1s_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_sbe_ena_w1s_t;

#define BDK_NIC_PF_ECC0_SBE_ENA_W1S BDK_NIC_PF_ECC0_SBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_SBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_SBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002018ull;
}
#define typedef_BDK_NIC_PF_ECC0_SBE_ENA_W1S bdk_nic_pf_ecc0_sbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC0_SBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_SBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC0_SBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_SBE_ENA_W1S "NIC_PF_ECC0_SBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc0_sbe_int
 *
 * Reports single-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC0_FLIP0.
 */
typedef union bdk_nic_pf_ecc0_sbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc0_sbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_sbe_int_s   cn88xx; */
	struct bdk_nic_pf_ecc0_sbe_int_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_sbe_int_t;

#define BDK_NIC_PF_ECC0_SBE_INT BDK_NIC_PF_ECC0_SBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_SBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_SBE_INT_FUNC(void)
{
	return 0x0000843000002000ull;
}
#define typedef_BDK_NIC_PF_ECC0_SBE_INT bdk_nic_pf_ecc0_sbe_int_t
#define bustype_BDK_NIC_PF_ECC0_SBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_SBE_INT 0
#define arguments_BDK_NIC_PF_ECC0_SBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_SBE_INT "NIC_PF_ECC0_SBE_INT"


/**
 * NCB - nic_pf_ecc0_sbe_int_w1s
 */
typedef union bdk_nic_pf_ecc0_sbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc0_sbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t blk3                        : 32; /**< R/W1C/H - Group 0 Block 3 memories.
                                                                 Added in pass 2. */
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t blk3                        : 32;
#endif
	} s;
	/* struct bdk_nic_pf_ecc0_sbe_int_w1s_s cn88xx; */
	struct bdk_nic_pf_ecc0_sbe_int_w1s_cn88xxp1 {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t blk2                        : 16; /**< R/W1C/H - Group 0 Block 2 memories. */
		uint64_t blk1                        : 8;  /**< R/W1C/H - Group 0 Block 1 memories. */
		uint64_t blk0                        : 8;  /**< R/W1C/H - Group 0 Block 0 memories. */
#else
		uint64_t blk0                        : 8;
		uint64_t blk1                        : 8;
		uint64_t blk2                        : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} cn88xxp1;
} bdk_nic_pf_ecc0_sbe_int_w1s_t;

#define BDK_NIC_PF_ECC0_SBE_INT_W1S BDK_NIC_PF_ECC0_SBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC0_SBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC0_SBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002008ull;
}
#define typedef_BDK_NIC_PF_ECC0_SBE_INT_W1S bdk_nic_pf_ecc0_sbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC0_SBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC0_SBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC0_SBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC0_SBE_INT_W1S "NIC_PF_ECC0_SBE_INT_W1S"


/**
 * NCB - nic_pf_ecc1_cdis
 *
 * See NIC_PF_ECC0_CDIS.
 *
 */
typedef union bdk_nic_pf_ecc1_cdis {
	uint64_t u;
	struct bdk_nic_pf_ecc1_cdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 1 Block 1 memories. INTERNAL: RRM memories:

                                                                 Pass 1:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.thresh_regs.
                                                                   \<1\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.base_regs.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs.

                                                                 Pass 2+:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = Reserved.
                                                                   \<1\> = Reserved.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs. */
		uint64_t blk0                        : 24; /**< R/W - Group 1 Block 0 memories. INTERNAL: RQM memories:

                                                                 Pass 1:
                                                                   \<23:17\> = Reserved.
                                                                   \<16\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_cfg_regs.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs.

                                                                 Pass 2+:
                                                                   \<23:16\> = Reserved.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_cdis_s      cn88xx; */
	/* struct bdk_nic_pf_ecc1_cdis_s      cn88xxp1; */
} bdk_nic_pf_ecc1_cdis_t;

#define BDK_NIC_PF_ECC1_CDIS BDK_NIC_PF_ECC1_CDIS_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_CDIS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_CDIS_FUNC(void)
{
	return 0x0000843000001108ull;
}
#define typedef_BDK_NIC_PF_ECC1_CDIS bdk_nic_pf_ecc1_cdis_t
#define bustype_BDK_NIC_PF_ECC1_CDIS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_CDIS 0
#define arguments_BDK_NIC_PF_ECC1_CDIS -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_CDIS "NIC_PF_ECC1_CDIS"


/**
 * NCB - nic_pf_ecc1_dbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc1_dbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc1_dbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_dbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_dbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc1_dbe_ena_w1c_t;

#define BDK_NIC_PF_ECC1_DBE_ENA_W1C BDK_NIC_PF_ECC1_DBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_DBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_DBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002310ull;
}
#define typedef_BDK_NIC_PF_ECC1_DBE_ENA_W1C bdk_nic_pf_ecc1_dbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC1_DBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_DBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC1_DBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_DBE_ENA_W1C "NIC_PF_ECC1_DBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc1_dbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc1_dbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc1_dbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_dbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_dbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc1_dbe_ena_w1s_t;

#define BDK_NIC_PF_ECC1_DBE_ENA_W1S BDK_NIC_PF_ECC1_DBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_DBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_DBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002318ull;
}
#define typedef_BDK_NIC_PF_ECC1_DBE_ENA_W1S bdk_nic_pf_ecc1_dbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC1_DBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_DBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC1_DBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_DBE_ENA_W1S "NIC_PF_ECC1_DBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc1_dbe_int
 *
 * Reports double-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC1_FLIP0.
 */
typedef union bdk_nic_pf_ecc1_dbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc1_dbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_dbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc1_dbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc1_dbe_int_t;

#define BDK_NIC_PF_ECC1_DBE_INT BDK_NIC_PF_ECC1_DBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_DBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_DBE_INT_FUNC(void)
{
	return 0x0000843000002300ull;
}
#define typedef_BDK_NIC_PF_ECC1_DBE_INT bdk_nic_pf_ecc1_dbe_int_t
#define bustype_BDK_NIC_PF_ECC1_DBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_DBE_INT 0
#define arguments_BDK_NIC_PF_ECC1_DBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_DBE_INT "NIC_PF_ECC1_DBE_INT"


/**
 * NCB - nic_pf_ecc1_dbe_int_w1s
 */
typedef union bdk_nic_pf_ecc1_dbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc1_dbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_dbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_dbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc1_dbe_int_w1s_t;

#define BDK_NIC_PF_ECC1_DBE_INT_W1S BDK_NIC_PF_ECC1_DBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_DBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_DBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002308ull;
}
#define typedef_BDK_NIC_PF_ECC1_DBE_INT_W1S bdk_nic_pf_ecc1_dbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC1_DBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_DBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC1_DBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_DBE_INT_W1S "NIC_PF_ECC1_DBE_INT_W1S"


/**
 * NCB - nic_pf_ecc1_flip0
 *
 * See NIC_PF_ECC0_FLIP0.
 *
 */
typedef union bdk_nic_pf_ecc1_flip0 {
	uint64_t u;
	struct bdk_nic_pf_ecc1_flip0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 1 Block 1 memories. INTERNAL: RRM memories:

                                                                 Pass 1:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.thresh_regs.
                                                                   \<1\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.base_regs.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs.

                                                                 Pass 2+:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = Reserved.
                                                                   \<1\> = Reserved.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs. */
		uint64_t blk0                        : 24; /**< R/W - Group 1 Block 0 memories. INTERNAL: RQM memories:

                                                                 Pass 1:
                                                                   \<23:17\> = Reserved.
                                                                   \<16\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_cfg_regs.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs.

                                                                 Pass 2+:
                                                                   \<23:16\> = Reserved.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_flip0_s     cn88xx; */
	/* struct bdk_nic_pf_ecc1_flip0_s     cn88xxp1; */
} bdk_nic_pf_ecc1_flip0_t;

#define BDK_NIC_PF_ECC1_FLIP0 BDK_NIC_PF_ECC1_FLIP0_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_FLIP0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_FLIP0_FUNC(void)
{
	return 0x0000843000001008ull;
}
#define typedef_BDK_NIC_PF_ECC1_FLIP0 bdk_nic_pf_ecc1_flip0_t
#define bustype_BDK_NIC_PF_ECC1_FLIP0 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_FLIP0 0
#define arguments_BDK_NIC_PF_ECC1_FLIP0 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_FLIP0 "NIC_PF_ECC1_FLIP0"


/**
 * NCB - nic_pf_ecc1_flip1
 *
 * See NIC_PF_ECC0_FLIP1.
 *
 */
typedef union bdk_nic_pf_ecc1_flip1 {
	uint64_t u;
	struct bdk_nic_pf_ecc1_flip1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 1 Block 1 memories. INTERNAL: RRM memories:

                                                                 Pass 1:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.thresh_regs.
                                                                   \<1\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.base_regs.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs.

                                                                 Pass 2+:
                                                                   \<15:10\> = Reserved.
                                                                   \<9:6\> = nic_l.core.rrm.nic_rrm_ptrcache.nic_rrm_ptrfifox256.nic_rrm_ptrfifox64{3..0}.ni
                                                                 c_rrm_ptrmem.
                                                                   \<5\> = nic_l.core.rrm.nic_rrm_ncx_rsp_fifo.nic_rrm_fifo_512x86.nic_rrm_fifomem_512x86.
                                                                   \<4\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_shadow_regs.
                                                                   \<3\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.nic_rrm_r_mod_w_block.r_mod_w_regs.
                                                                   \<2\> = Reserved.
                                                                   \<1\> = Reserved.
                                                                   \<0\> = nic_l.core.rrm.nic_rrm_rbdr_wrap.status1_regs. */
		uint64_t blk0                        : 24; /**< R/W - Group 1 Block 0 memories. INTERNAL: RQM memories:

                                                                 Pass 1:
                                                                   \<23:17\> = Reserved.
                                                                   \<16\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_cfg_regs.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs.

                                                                 Pass 2+:
                                                                   \<23:16\> = Reserved.
                                                                   \<15\> = nic_l.core.rqm.nic_rqm_rq_wrap.pf_qs_rq_cfg_regs.
                                                                   \<14\> = nic_l.core.rqm.nic_rqm_rq_wrap.qs_rq_gen_cfg_regs.
                                                                   \<13:11\> = nic_l.core.rqm.nic_rqm_stat_wrap.nic_rqm_stat_r_mod_w.r_mod_w_regs_{2..0}.
                                                                   \<10\> = nic_l.core.rqm.nic_rqm_bp_wrap.pf_chan_bp_cfg_regs.
                                                                   \<9\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_bp_cfg_regs.
                                                                   \<8\>  = nic_l.core.rqm.nic_rqm_bp_wrap.pf_qs_rq_drop_cfg_regs.
                                                                   \<7:3\>  = nic_l.core.rqm.nic_rqm_rss_wrap.vnic_rss_key{4..0}_regs.
                                                                   \<2\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_chan_rx_cfg_regs.
                                                                   \<1\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_rssi_rq_regs.
                                                                   \<0\>  = nic_l.core.rqm.nic_rqm_rss_wrap.nic_pf_cpi_cfg_regs. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_flip1_s     cn88xx; */
	/* struct bdk_nic_pf_ecc1_flip1_s     cn88xxp1; */
} bdk_nic_pf_ecc1_flip1_t;

#define BDK_NIC_PF_ECC1_FLIP1 BDK_NIC_PF_ECC1_FLIP1_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_FLIP1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_FLIP1_FUNC(void)
{
	return 0x0000843000001088ull;
}
#define typedef_BDK_NIC_PF_ECC1_FLIP1 bdk_nic_pf_ecc1_flip1_t
#define bustype_BDK_NIC_PF_ECC1_FLIP1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_FLIP1 0
#define arguments_BDK_NIC_PF_ECC1_FLIP1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_FLIP1 "NIC_PF_ECC1_FLIP1"


/**
 * NCB - nic_pf_ecc1_sbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc1_sbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc1_sbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_sbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_sbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc1_sbe_ena_w1c_t;

#define BDK_NIC_PF_ECC1_SBE_ENA_W1C BDK_NIC_PF_ECC1_SBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_SBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_SBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002210ull;
}
#define typedef_BDK_NIC_PF_ECC1_SBE_ENA_W1C bdk_nic_pf_ecc1_sbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC1_SBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_SBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC1_SBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_SBE_ENA_W1C "NIC_PF_ECC1_SBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc1_sbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc1_sbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc1_sbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_sbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_sbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc1_sbe_ena_w1s_t;

#define BDK_NIC_PF_ECC1_SBE_ENA_W1S BDK_NIC_PF_ECC1_SBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_SBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_SBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002218ull;
}
#define typedef_BDK_NIC_PF_ECC1_SBE_ENA_W1S bdk_nic_pf_ecc1_sbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC1_SBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_SBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC1_SBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_SBE_ENA_W1S "NIC_PF_ECC1_SBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc1_sbe_int
 *
 * Reports single-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC1_FLIP0.
 */
typedef union bdk_nic_pf_ecc1_sbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc1_sbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_sbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc1_sbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc1_sbe_int_t;

#define BDK_NIC_PF_ECC1_SBE_INT BDK_NIC_PF_ECC1_SBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_SBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_SBE_INT_FUNC(void)
{
	return 0x0000843000002200ull;
}
#define typedef_BDK_NIC_PF_ECC1_SBE_INT bdk_nic_pf_ecc1_sbe_int_t
#define bustype_BDK_NIC_PF_ECC1_SBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_SBE_INT 0
#define arguments_BDK_NIC_PF_ECC1_SBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_SBE_INT "NIC_PF_ECC1_SBE_INT"


/**
 * NCB - nic_pf_ecc1_sbe_int_w1s
 */
typedef union bdk_nic_pf_ecc1_sbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc1_sbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 1 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 1 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc1_sbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc1_sbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc1_sbe_int_w1s_t;

#define BDK_NIC_PF_ECC1_SBE_INT_W1S BDK_NIC_PF_ECC1_SBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC1_SBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC1_SBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002208ull;
}
#define typedef_BDK_NIC_PF_ECC1_SBE_INT_W1S bdk_nic_pf_ecc1_sbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC1_SBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC1_SBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC1_SBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC1_SBE_INT_W1S "NIC_PF_ECC1_SBE_INT_W1S"


/**
 * NCB - nic_pf_ecc2_cdis
 *
 * See NIC_PF_ECC0_CDIS.
 *
 */
typedef union bdk_nic_pf_ecc2_cdis {
	uint64_t u;
	struct bdk_nic_pf_ecc2_cdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W - Group 2 Block 0 memories. INTERNAL: SEB memories.
                                                                 \<49:42\> = Reserved.
                                                                 \<41\>    = nic_u1.seb.mem.dmem.simm_fptr.
                                                                 \<40:39\> = nic_u1.seb.mem.dmem.simm_iptr_fifos{1..0}.simm_iptr.
                                                                 \<38:37\> = nic_u1.seb.mem.dmem.simm_fpa_mem{1..0}.simm_dmem.
                                                                 \<36\>    = nic_u1.seb.mem.dmem.sgth_fptr.
                                                                 \<35:34\> = nic_u1.seb.mem.dmem.sgth_iptr_fifos{1..0}.sgth_iptr.
                                                                 \<33:30\> = nic_u1.seb.mem.dmem.sgth_data_mem{3..0}.sgth_fpa_mem.
                                                                 \<29\>    = nic_u1.seb.mem.dmem.dsze_fptr.
                                                                 \<28:27\> = nic_u1.seb.mem.dmem.dsze_iptr_fifos{1..0}.dsze_iptr.
                                                                 \<26:25\> = nic_u1.seb.mem.dmem.dsze_fpa_mem{1..0}.dsze_dmem.
                                                                 \<24:23\> = nic_u1.seb.mem.dmem.lock_dmem{1..0}.lock_drf.
                                                                 \<22:21\> = nic_u1.seb.mem.imem.crc_dmem{1..0}.crc_drf.
                                                                 \<20:19\> = nic_u1.seb.mem.imem.smem_dmem{1..0}.smem_drf.
                                                                 \<18\>    = nic_u1.seb.ctx.fptr.
                                                                 \<17:16\> = nic_u1.seb.ctx.intf_dpdnt_logic{1..0}.iptr.
                                                                 \<15:14\> = nic_u1.seb.ctx.seb_lctx_dmem_spr{1..0}.dmem.
                                                                 \<13:12\> = nic_u1.seb.ctx.eod_dmem{1..0}.eod_drf.
                                                                 \<11:10\> = nic_u1.seb.ctx.gctx_dmem{1..0}.gctx_drf.
                                                                 \<9:8\>   = nic_u1.seb.smc.smem_cq_context{1..0}.smem_cq_ctx.
                                                                 \<7\>     = nic_u1.seb.smc.smem_cq_stdn.
                                                                 \<6\>     = nic_u1.seb.ncx_intf.sgth_cmd.
                                                                 \<5:4\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.tx_fifo.
                                                                 \<3:2\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_sop_hdr.
                                                                 \<1:0\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_eop_hdr. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_cdis_s      cn88xx; */
	/* struct bdk_nic_pf_ecc2_cdis_s      cn88xxp1; */
} bdk_nic_pf_ecc2_cdis_t;

#define BDK_NIC_PF_ECC2_CDIS BDK_NIC_PF_ECC2_CDIS_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_CDIS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_CDIS_FUNC(void)
{
	return 0x0000843000001110ull;
}
#define typedef_BDK_NIC_PF_ECC2_CDIS bdk_nic_pf_ecc2_cdis_t
#define bustype_BDK_NIC_PF_ECC2_CDIS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_CDIS 0
#define arguments_BDK_NIC_PF_ECC2_CDIS -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_CDIS "NIC_PF_ECC2_CDIS"


/**
 * NCB - nic_pf_ecc2_dbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc2_dbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc2_dbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_dbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_dbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc2_dbe_ena_w1c_t;

#define BDK_NIC_PF_ECC2_DBE_ENA_W1C BDK_NIC_PF_ECC2_DBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_DBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_DBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002510ull;
}
#define typedef_BDK_NIC_PF_ECC2_DBE_ENA_W1C bdk_nic_pf_ecc2_dbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC2_DBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_DBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC2_DBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_DBE_ENA_W1C "NIC_PF_ECC2_DBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc2_dbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc2_dbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc2_dbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_dbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_dbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc2_dbe_ena_w1s_t;

#define BDK_NIC_PF_ECC2_DBE_ENA_W1S BDK_NIC_PF_ECC2_DBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_DBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_DBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002518ull;
}
#define typedef_BDK_NIC_PF_ECC2_DBE_ENA_W1S bdk_nic_pf_ecc2_dbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC2_DBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_DBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC2_DBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_DBE_ENA_W1S "NIC_PF_ECC2_DBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc2_dbe_int
 *
 * Reports double-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC2_FLIP0.
 */
typedef union bdk_nic_pf_ecc2_dbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc2_dbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_dbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc2_dbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc2_dbe_int_t;

#define BDK_NIC_PF_ECC2_DBE_INT BDK_NIC_PF_ECC2_DBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_DBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_DBE_INT_FUNC(void)
{
	return 0x0000843000002500ull;
}
#define typedef_BDK_NIC_PF_ECC2_DBE_INT bdk_nic_pf_ecc2_dbe_int_t
#define bustype_BDK_NIC_PF_ECC2_DBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_DBE_INT 0
#define arguments_BDK_NIC_PF_ECC2_DBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_DBE_INT "NIC_PF_ECC2_DBE_INT"


/**
 * NCB - nic_pf_ecc2_dbe_int_w1s
 */
typedef union bdk_nic_pf_ecc2_dbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc2_dbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_dbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_dbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc2_dbe_int_w1s_t;

#define BDK_NIC_PF_ECC2_DBE_INT_W1S BDK_NIC_PF_ECC2_DBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_DBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_DBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002508ull;
}
#define typedef_BDK_NIC_PF_ECC2_DBE_INT_W1S bdk_nic_pf_ecc2_dbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC2_DBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_DBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC2_DBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_DBE_INT_W1S "NIC_PF_ECC2_DBE_INT_W1S"


/**
 * NCB - nic_pf_ecc2_flip0
 *
 * See NIC_PF_ECC0_FLIP0.
 *
 */
typedef union bdk_nic_pf_ecc2_flip0 {
	uint64_t u;
	struct bdk_nic_pf_ecc2_flip0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W - Group 2 Block 0 memories. INTERNAL: SEB memories.
                                                                 \<49:42\> = Reserved.
                                                                 \<41\>    = nic_u1.seb.mem.dmem.simm_fptr.
                                                                 \<40:39\> = nic_u1.seb.mem.dmem.simm_iptr_fifos{1..0}.simm_iptr.
                                                                 \<38:37\> = nic_u1.seb.mem.dmem.simm_fpa_mem{1..0}.simm_dmem.
                                                                 \<36\>    = nic_u1.seb.mem.dmem.sgth_fptr.
                                                                 \<35:34\> = nic_u1.seb.mem.dmem.sgth_iptr_fifos{1..0}.sgth_iptr.
                                                                 \<33:30\> = nic_u1.seb.mem.dmem.sgth_data_mem{3..0}.sgth_fpa_mem.
                                                                 \<29\>    = nic_u1.seb.mem.dmem.dsze_fptr.
                                                                 \<28:27\> = nic_u1.seb.mem.dmem.dsze_iptr_fifos{1..0}.dsze_iptr.
                                                                 \<26:25\> = nic_u1.seb.mem.dmem.dsze_fpa_mem{1..0}.dsze_dmem.
                                                                 \<24:23\> = nic_u1.seb.mem.dmem.lock_dmem{1..0}.lock_drf.
                                                                 \<22:21\> = nic_u1.seb.mem.imem.crc_dmem{1..0}.crc_drf.
                                                                 \<20:19\> = nic_u1.seb.mem.imem.smem_dmem{1..0}.smem_drf.
                                                                 \<18\>    = nic_u1.seb.ctx.fptr.
                                                                 \<17:16\> = nic_u1.seb.ctx.intf_dpdnt_logic{1..0}.iptr.
                                                                 \<15:14\> = nic_u1.seb.ctx.seb_lctx_dmem_spr{1..0}.dmem.
                                                                 \<13:12\> = nic_u1.seb.ctx.eod_dmem{1..0}.eod_drf.
                                                                 \<11:10\> = nic_u1.seb.ctx.gctx_dmem{1..0}.gctx_drf.
                                                                 \<9:8\>   = nic_u1.seb.smc.smem_cq_context{1..0}.smem_cq_ctx.
                                                                 \<7\>     = nic_u1.seb.smc.smem_cq_stdn.
                                                                 \<6\>     = nic_u1.seb.ncx_intf.sgth_cmd.
                                                                 \<5:4\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.tx_fifo.
                                                                 \<3:2\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_sop_hdr.
                                                                 \<1:0\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_eop_hdr. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_flip0_s     cn88xx; */
	/* struct bdk_nic_pf_ecc2_flip0_s     cn88xxp1; */
} bdk_nic_pf_ecc2_flip0_t;

#define BDK_NIC_PF_ECC2_FLIP0 BDK_NIC_PF_ECC2_FLIP0_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_FLIP0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_FLIP0_FUNC(void)
{
	return 0x0000843000001010ull;
}
#define typedef_BDK_NIC_PF_ECC2_FLIP0 bdk_nic_pf_ecc2_flip0_t
#define bustype_BDK_NIC_PF_ECC2_FLIP0 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_FLIP0 0
#define arguments_BDK_NIC_PF_ECC2_FLIP0 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_FLIP0 "NIC_PF_ECC2_FLIP0"


/**
 * NCB - nic_pf_ecc2_flip1
 *
 * See NIC_PF_ECC0_FLIP1.
 *
 */
typedef union bdk_nic_pf_ecc2_flip1 {
	uint64_t u;
	struct bdk_nic_pf_ecc2_flip1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W - Group 2 Block 0 memories. INTERNAL: SEB memories.
                                                                 \<49:42\> = Reserved.
                                                                 \<41\>    = nic_u1.seb.mem.dmem.simm_fptr.
                                                                 \<40:39\> = nic_u1.seb.mem.dmem.simm_iptr_fifos{1..0}.simm_iptr.
                                                                 \<38:37\> = nic_u1.seb.mem.dmem.simm_fpa_mem{1..0}.simm_dmem.
                                                                 \<36\>    = nic_u1.seb.mem.dmem.sgth_fptr.
                                                                 \<35:34\> = nic_u1.seb.mem.dmem.sgth_iptr_fifos{1..0}.sgth_iptr.
                                                                 \<33:30\> = nic_u1.seb.mem.dmem.sgth_data_mem{3..0}.sgth_fpa_mem.
                                                                 \<29\>    = nic_u1.seb.mem.dmem.dsze_fptr.
                                                                 \<28:27\> = nic_u1.seb.mem.dmem.dsze_iptr_fifos{1..0}.dsze_iptr.
                                                                 \<26:25\> = nic_u1.seb.mem.dmem.dsze_fpa_mem{1..0}.dsze_dmem.
                                                                 \<24:23\> = nic_u1.seb.mem.dmem.lock_dmem{1..0}.lock_drf.
                                                                 \<22:21\> = nic_u1.seb.mem.imem.crc_dmem{1..0}.crc_drf.
                                                                 \<20:19\> = nic_u1.seb.mem.imem.smem_dmem{1..0}.smem_drf.
                                                                 \<18\>    = nic_u1.seb.ctx.fptr.
                                                                 \<17:16\> = nic_u1.seb.ctx.intf_dpdnt_logic{1..0}.iptr.
                                                                 \<15:14\> = nic_u1.seb.ctx.seb_lctx_dmem_spr{1..0}.dmem.
                                                                 \<13:12\> = nic_u1.seb.ctx.eod_dmem{1..0}.eod_drf.
                                                                 \<11:10\> = nic_u1.seb.ctx.gctx_dmem{1..0}.gctx_drf.
                                                                 \<9:8\>   = nic_u1.seb.smc.smem_cq_context{1..0}.smem_cq_ctx.
                                                                 \<7\>     = nic_u1.seb.smc.smem_cq_stdn.
                                                                 \<6\>     = nic_u1.seb.ncx_intf.sgth_cmd.
                                                                 \<5:4\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.tx_fifo.
                                                                 \<3:2\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_sop_hdr.
                                                                 \<1:0\>   = nic_u1.seb.p2x_intf.tx_fifo_mem{1..0}.p2x_eop_hdr. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_flip1_s     cn88xx; */
	/* struct bdk_nic_pf_ecc2_flip1_s     cn88xxp1; */
} bdk_nic_pf_ecc2_flip1_t;

#define BDK_NIC_PF_ECC2_FLIP1 BDK_NIC_PF_ECC2_FLIP1_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_FLIP1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_FLIP1_FUNC(void)
{
	return 0x0000843000001090ull;
}
#define typedef_BDK_NIC_PF_ECC2_FLIP1 bdk_nic_pf_ecc2_flip1_t
#define bustype_BDK_NIC_PF_ECC2_FLIP1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_FLIP1 0
#define arguments_BDK_NIC_PF_ECC2_FLIP1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_FLIP1 "NIC_PF_ECC2_FLIP1"


/**
 * NCB - nic_pf_ecc2_sbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc2_sbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc2_sbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_sbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_sbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc2_sbe_ena_w1c_t;

#define BDK_NIC_PF_ECC2_SBE_ENA_W1C BDK_NIC_PF_ECC2_SBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_SBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_SBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002410ull;
}
#define typedef_BDK_NIC_PF_ECC2_SBE_ENA_W1C bdk_nic_pf_ecc2_sbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC2_SBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_SBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC2_SBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_SBE_ENA_W1C "NIC_PF_ECC2_SBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc2_sbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc2_sbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc2_sbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_sbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_sbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc2_sbe_ena_w1s_t;

#define BDK_NIC_PF_ECC2_SBE_ENA_W1S BDK_NIC_PF_ECC2_SBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_SBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_SBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002418ull;
}
#define typedef_BDK_NIC_PF_ECC2_SBE_ENA_W1S bdk_nic_pf_ecc2_sbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC2_SBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_SBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC2_SBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_SBE_ENA_W1S "NIC_PF_ECC2_SBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc2_sbe_int
 *
 * Reports single-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC2_FLIP0.
 */
typedef union bdk_nic_pf_ecc2_sbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc2_sbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_sbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc2_sbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc2_sbe_int_t;

#define BDK_NIC_PF_ECC2_SBE_INT BDK_NIC_PF_ECC2_SBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_SBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_SBE_INT_FUNC(void)
{
	return 0x0000843000002400ull;
}
#define typedef_BDK_NIC_PF_ECC2_SBE_INT bdk_nic_pf_ecc2_sbe_int_t
#define bustype_BDK_NIC_PF_ECC2_SBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_SBE_INT 0
#define arguments_BDK_NIC_PF_ECC2_SBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_SBE_INT "NIC_PF_ECC2_SBE_INT"


/**
 * NCB - nic_pf_ecc2_sbe_int_w1s
 */
typedef union bdk_nic_pf_ecc2_sbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc2_sbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_50_63              : 14;
		uint64_t blk0                        : 50; /**< R/W1C/H - Group 2 Block 0 memories. */
#else
		uint64_t blk0                        : 50;
		uint64_t reserved_50_63              : 14;
#endif
	} s;
	/* struct bdk_nic_pf_ecc2_sbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc2_sbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc2_sbe_int_w1s_t;

#define BDK_NIC_PF_ECC2_SBE_INT_W1S BDK_NIC_PF_ECC2_SBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC2_SBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC2_SBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002408ull;
}
#define typedef_BDK_NIC_PF_ECC2_SBE_INT_W1S bdk_nic_pf_ecc2_sbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC2_SBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC2_SBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC2_SBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC2_SBE_INT_W1S "NIC_PF_ECC2_SBE_INT_W1S"


/**
 * NCB - nic_pf_ecc3_cdis
 *
 * See NIC_PF_ECC0_CDIS.
 *
 */
typedef union bdk_nic_pf_ecc3_cdis {
	uint64_t u;
	struct bdk_nic_pf_ecc3_cdis_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 3 Block 1 memories. INTERNAL: SQM memories:

                                                                 Pass 1:
                                                                   \<15:11\> = Reserved.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem.

                                                                 Pass 2+ (added tsosn_mem, mdmem2_mem):
                                                                   \<15:13\> = Reserved.
                                                                   \<12\> = nic_u1.sqm.mqm.mdmem2_mem.
                                                                   \<11\> = nic_u1.sqm.dse.send.tsosn_mem.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem. */
		uint64_t blk0                        : 24; /**< R/W - Group 3 Block 0 memories. INTERNAL: SPS memories:

                                                                 Pass 1:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13\> = nic_u2.sps.tl4.mem.ptrmem.
                                                                   \<12\> = nic_u2.sps.tl4.mem.aggrmem.
                                                                   \<11:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = nic_u2.sps.tl3.mem.aggrmem.
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem.

                                                                 Pass 2+:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = Reserved
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_cdis_s      cn88xx; */
	/* struct bdk_nic_pf_ecc3_cdis_s      cn88xxp1; */
} bdk_nic_pf_ecc3_cdis_t;

#define BDK_NIC_PF_ECC3_CDIS BDK_NIC_PF_ECC3_CDIS_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_CDIS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_CDIS_FUNC(void)
{
	return 0x0000843000001118ull;
}
#define typedef_BDK_NIC_PF_ECC3_CDIS bdk_nic_pf_ecc3_cdis_t
#define bustype_BDK_NIC_PF_ECC3_CDIS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_CDIS 0
#define arguments_BDK_NIC_PF_ECC3_CDIS -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_CDIS "NIC_PF_ECC3_CDIS"


/**
 * NCB - nic_pf_ecc3_dbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc3_dbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc3_dbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_dbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_dbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc3_dbe_ena_w1c_t;

#define BDK_NIC_PF_ECC3_DBE_ENA_W1C BDK_NIC_PF_ECC3_DBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_DBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_DBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002710ull;
}
#define typedef_BDK_NIC_PF_ECC3_DBE_ENA_W1C bdk_nic_pf_ecc3_dbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC3_DBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_DBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC3_DBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_DBE_ENA_W1C "NIC_PF_ECC3_DBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc3_dbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc3_dbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc3_dbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_dbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_dbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc3_dbe_ena_w1s_t;

#define BDK_NIC_PF_ECC3_DBE_ENA_W1S BDK_NIC_PF_ECC3_DBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_DBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_DBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002718ull;
}
#define typedef_BDK_NIC_PF_ECC3_DBE_ENA_W1S bdk_nic_pf_ecc3_dbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC3_DBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_DBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC3_DBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_DBE_ENA_W1S "NIC_PF_ECC3_DBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc3_dbe_int
 *
 * Reports double-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC3_FLIP0.
 */
typedef union bdk_nic_pf_ecc3_dbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc3_dbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_dbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc3_dbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc3_dbe_int_t;

#define BDK_NIC_PF_ECC3_DBE_INT BDK_NIC_PF_ECC3_DBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_DBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_DBE_INT_FUNC(void)
{
	return 0x0000843000002700ull;
}
#define typedef_BDK_NIC_PF_ECC3_DBE_INT bdk_nic_pf_ecc3_dbe_int_t
#define bustype_BDK_NIC_PF_ECC3_DBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_DBE_INT 0
#define arguments_BDK_NIC_PF_ECC3_DBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_DBE_INT "NIC_PF_ECC3_DBE_INT"


/**
 * NCB - nic_pf_ecc3_dbe_int_w1s
 */
typedef union bdk_nic_pf_ecc3_dbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc3_dbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_dbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_dbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc3_dbe_int_w1s_t;

#define BDK_NIC_PF_ECC3_DBE_INT_W1S BDK_NIC_PF_ECC3_DBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_DBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_DBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002708ull;
}
#define typedef_BDK_NIC_PF_ECC3_DBE_INT_W1S bdk_nic_pf_ecc3_dbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC3_DBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_DBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC3_DBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_DBE_INT_W1S "NIC_PF_ECC3_DBE_INT_W1S"


/**
 * NCB - nic_pf_ecc3_flip0
 *
 * See NIC_PF_ECC0_FLIP0.
 *
 */
typedef union bdk_nic_pf_ecc3_flip0 {
	uint64_t u;
	struct bdk_nic_pf_ecc3_flip0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 3 Block 1 memories. INTERNAL: SQM memories:

                                                                 Pass 1:
                                                                   \<15:11\> = Reserved.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem.

                                                                 Pass 2+ (added tsosn_mem, mdmem2_mem):
                                                                   \<15:13\> = Reserved.
                                                                   \<12\> = nic_u1.sqm.mqm.mdmem2_mem.
                                                                   \<11\> = nic_u1.sqm.dse.send.tsosn_mem.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem. */
		uint64_t blk0                        : 24; /**< R/W - Group 3 Block 0 memories. INTERNAL: SPS memories:

                                                                 Pass 1:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13\> = nic_u2.sps.tl4.mem.ptrmem.
                                                                   \<12\> = nic_u2.sps.tl4.mem.aggrmem.
                                                                   \<11:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = nic_u2.sps.tl3.mem.aggrmem.
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem.

                                                                 Pass 2+:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = Reserved
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_flip0_s     cn88xx; */
	/* struct bdk_nic_pf_ecc3_flip0_s     cn88xxp1; */
} bdk_nic_pf_ecc3_flip0_t;

#define BDK_NIC_PF_ECC3_FLIP0 BDK_NIC_PF_ECC3_FLIP0_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_FLIP0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_FLIP0_FUNC(void)
{
	return 0x0000843000001018ull;
}
#define typedef_BDK_NIC_PF_ECC3_FLIP0 bdk_nic_pf_ecc3_flip0_t
#define bustype_BDK_NIC_PF_ECC3_FLIP0 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_FLIP0 0
#define arguments_BDK_NIC_PF_ECC3_FLIP0 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_FLIP0 "NIC_PF_ECC3_FLIP0"


/**
 * NCB - nic_pf_ecc3_flip1
 *
 * See NIC_PF_ECC0_FLIP1.
 *
 */
typedef union bdk_nic_pf_ecc3_flip1 {
	uint64_t u;
	struct bdk_nic_pf_ecc3_flip1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W - Group 3 Block 1 memories. INTERNAL: SQM memories:

                                                                 Pass 1:
                                                                   \<15:11\> = Reserved.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem.

                                                                 Pass 2+ (added tsosn_mem, mdmem2_mem):
                                                                   \<15:13\> = Reserved.
                                                                   \<12\> = nic_u1.sqm.mqm.mdmem2_mem.
                                                                   \<11\> = nic_u1.sqm.dse.send.tsosn_mem.
                                                                   \<10\> = nic_u1.sqm.dpe.arb.sq_arb_mem_mem.
                                                                   \<9\>  = nic_u1.sqm.ctl.sq.sq_mem_mem.
                                                                   \<8\>  = nic_u1.sqm.ctl.sq.qs_mem.
                                                                   \<7\>  = nic_u1.sqm.ctl.lock.lock_mem_mem.
                                                                   \<6\>  = nic_u1.sqm.ctl.vnic.vnic_mem_mem.
                                                                   \<5\>  = nic_u1.sqm.dpe.fetch.fetch.dpe_blk.fetch_op_fifo_dpr.
                                                                   \<4\>  = nic_u1.sqm.dpe.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<3\>  = nic_u1.sqm.dse.fetch.fetch.dse_blk.fetch_op_fifo_dpr.
                                                                   \<2\>  = nic_u1.sqm.dse.fetch.fetch.fetch_data_fifo_dpr.
                                                                   \<1\>  = nic_u1.sqm.mqm.qsmem_mem.
                                                                   \<0\>  = nic_u1.sqm.mqm.mdmem_mem. */
		uint64_t blk0                        : 24; /**< R/W - Group 3 Block 0 memories. INTERNAL: SPS memories:

                                                                 Pass 1:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13\> = nic_u2.sps.tl4.mem.ptrmem.
                                                                   \<12\> = nic_u2.sps.tl4.mem.aggrmem.
                                                                   \<11:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = nic_u2.sps.tl3.mem.aggrmem.
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem.

                                                                 Pass 2+:
                                                                   \<23:18\> = Reserved
                                                                   \<17\> = nic_u2.sps.sqm_intf.mem.sqcfgmem.
                                                                   \<16\> = nic_u2.sps.tl4.mem.rtmem.
                                                                   \<15\> = nic_u2.sps.tl4.mem.stsmem.
                                                                   \<14\> = nic_u2.sps.tl4.mem.stdmem.
                                                                   \<13:9\> = Reserved
                                                                   \<8\>  = nic_u2.sps.tl3.mem.rtmem.
                                                                   \<7\>  = nic_u2.sps.tl3.mem.stsmem.
                                                                   \<6\>  = nic_u2.sps.tl3.mem.stdmem.
                                                                   \<5\>  = nic_u2.sps.tl3.mem.ccdtmem.
                                                                   \<4\>  = nic_u2.sps.tl3.mem.lcdtmem.
                                                                   \<3\>  = Reserved
                                                                   \<2\>  = nic_u2.sps.tl2.mem.rtmem.
                                                                   \<1\>  = nic_u2.sps.tl2.mem.stsmem.
                                                                   \<0\>  = nic_u2.sps.tl2.mem.stdmem. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_flip1_s     cn88xx; */
	/* struct bdk_nic_pf_ecc3_flip1_s     cn88xxp1; */
} bdk_nic_pf_ecc3_flip1_t;

#define BDK_NIC_PF_ECC3_FLIP1 BDK_NIC_PF_ECC3_FLIP1_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_FLIP1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_FLIP1_FUNC(void)
{
	return 0x0000843000001098ull;
}
#define typedef_BDK_NIC_PF_ECC3_FLIP1 bdk_nic_pf_ecc3_flip1_t
#define bustype_BDK_NIC_PF_ECC3_FLIP1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_FLIP1 0
#define arguments_BDK_NIC_PF_ECC3_FLIP1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_FLIP1 "NIC_PF_ECC3_FLIP1"


/**
 * NCB - nic_pf_ecc3_sbe_ena_w1c
 */
typedef union bdk_nic_pf_ecc3_sbe_ena_w1c {
	uint64_t u;
	struct bdk_nic_pf_ecc3_sbe_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_sbe_ena_w1c_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_sbe_ena_w1c_s cn88xxp1; */
} bdk_nic_pf_ecc3_sbe_ena_w1c_t;

#define BDK_NIC_PF_ECC3_SBE_ENA_W1C BDK_NIC_PF_ECC3_SBE_ENA_W1C_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_SBE_ENA_W1C_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_SBE_ENA_W1C_FUNC(void)
{
	return 0x0000843000002610ull;
}
#define typedef_BDK_NIC_PF_ECC3_SBE_ENA_W1C bdk_nic_pf_ecc3_sbe_ena_w1c_t
#define bustype_BDK_NIC_PF_ECC3_SBE_ENA_W1C BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_SBE_ENA_W1C 0
#define arguments_BDK_NIC_PF_ECC3_SBE_ENA_W1C -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_SBE_ENA_W1C "NIC_PF_ECC3_SBE_ENA_W1C"


/**
 * NCB - nic_pf_ecc3_sbe_ena_w1s
 */
typedef union bdk_nic_pf_ecc3_sbe_ena_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc3_sbe_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_sbe_ena_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_sbe_ena_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc3_sbe_ena_w1s_t;

#define BDK_NIC_PF_ECC3_SBE_ENA_W1S BDK_NIC_PF_ECC3_SBE_ENA_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_SBE_ENA_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_SBE_ENA_W1S_FUNC(void)
{
	return 0x0000843000002618ull;
}
#define typedef_BDK_NIC_PF_ECC3_SBE_ENA_W1S bdk_nic_pf_ecc3_sbe_ena_w1s_t
#define bustype_BDK_NIC_PF_ECC3_SBE_ENA_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_SBE_ENA_W1S 0
#define arguments_BDK_NIC_PF_ECC3_SBE_ENA_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_SBE_ENA_W1S "NIC_PF_ECC3_SBE_ENA_W1S"


/**
 * NCB - nic_pf_ecc3_sbe_int
 *
 * Reports single-bit errors detected in internal RAM. Each bit corresponds to a different RAM: 0
 * = pass, 1 = fail. INTERNAL: Bits in each field are enumerated by NIC_PF_ECC3_FLIP0.
 */
typedef union bdk_nic_pf_ecc3_sbe_int {
	uint64_t u;
	struct bdk_nic_pf_ecc3_sbe_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_sbe_int_s   cn88xx; */
	/* struct bdk_nic_pf_ecc3_sbe_int_s   cn88xxp1; */
} bdk_nic_pf_ecc3_sbe_int_t;

#define BDK_NIC_PF_ECC3_SBE_INT BDK_NIC_PF_ECC3_SBE_INT_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_SBE_INT_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_SBE_INT_FUNC(void)
{
	return 0x0000843000002600ull;
}
#define typedef_BDK_NIC_PF_ECC3_SBE_INT bdk_nic_pf_ecc3_sbe_int_t
#define bustype_BDK_NIC_PF_ECC3_SBE_INT BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_SBE_INT 0
#define arguments_BDK_NIC_PF_ECC3_SBE_INT -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_SBE_INT "NIC_PF_ECC3_SBE_INT"


/**
 * NCB - nic_pf_ecc3_sbe_int_w1s
 */
typedef union bdk_nic_pf_ecc3_sbe_int_w1s {
	uint64_t u;
	struct bdk_nic_pf_ecc3_sbe_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_40_63              : 24;
		uint64_t blk1                        : 16; /**< R/W1C/H - Group 3 Block 1 memories. */
		uint64_t blk0                        : 24; /**< R/W1C/H - Group 3 Block 0 memories. */
#else
		uint64_t blk0                        : 24;
		uint64_t blk1                        : 16;
		uint64_t reserved_40_63              : 24;
#endif
	} s;
	/* struct bdk_nic_pf_ecc3_sbe_int_w1s_s cn88xx; */
	/* struct bdk_nic_pf_ecc3_sbe_int_w1s_s cn88xxp1; */
} bdk_nic_pf_ecc3_sbe_int_w1s_t;

#define BDK_NIC_PF_ECC3_SBE_INT_W1S BDK_NIC_PF_ECC3_SBE_INT_W1S_FUNC()
static inline uint64_t BDK_NIC_PF_ECC3_SBE_INT_W1S_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECC3_SBE_INT_W1S_FUNC(void)
{
	return 0x0000843000002608ull;
}
#define typedef_BDK_NIC_PF_ECC3_SBE_INT_W1S bdk_nic_pf_ecc3_sbe_int_w1s_t
#define bustype_BDK_NIC_PF_ECC3_SBE_INT_W1S BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECC3_SBE_INT_W1S 0
#define arguments_BDK_NIC_PF_ECC3_SBE_INT_W1S -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECC3_SBE_INT_W1S "NIC_PF_ECC3_SBE_INT_W1S"


/**
 * NCB - nic_pf_eco0
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco0 {
	uint64_t u;
	struct bdk_nic_pf_eco0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco0_s           cn88xx; */
} bdk_nic_pf_eco0_t;

#define BDK_NIC_PF_ECO0 BDK_NIC_PF_ECO0_FUNC()
static inline uint64_t BDK_NIC_PF_ECO0_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO0_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003000ull;
	else 		csr_fatal("BDK_NIC_PF_ECO0", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO0 bdk_nic_pf_eco0_t
#define bustype_BDK_NIC_PF_ECO0 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO0 0
#define arguments_BDK_NIC_PF_ECO0 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO0 "NIC_PF_ECO0"


/**
 * NCB - nic_pf_eco1
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco1 {
	uint64_t u;
	struct bdk_nic_pf_eco1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco1_s           cn88xx; */
} bdk_nic_pf_eco1_t;

#define BDK_NIC_PF_ECO1 BDK_NIC_PF_ECO1_FUNC()
static inline uint64_t BDK_NIC_PF_ECO1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO1_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003010ull;
	else 		csr_fatal("BDK_NIC_PF_ECO1", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO1 bdk_nic_pf_eco1_t
#define bustype_BDK_NIC_PF_ECO1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO1 0
#define arguments_BDK_NIC_PF_ECO1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO1 "NIC_PF_ECO1"


/**
 * NCB - nic_pf_eco2
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco2 {
	uint64_t u;
	struct bdk_nic_pf_eco2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco2_s           cn88xx; */
} bdk_nic_pf_eco2_t;

#define BDK_NIC_PF_ECO2 BDK_NIC_PF_ECO2_FUNC()
static inline uint64_t BDK_NIC_PF_ECO2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO2_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003020ull;
	else 		csr_fatal("BDK_NIC_PF_ECO2", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO2 bdk_nic_pf_eco2_t
#define bustype_BDK_NIC_PF_ECO2 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO2 0
#define arguments_BDK_NIC_PF_ECO2 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO2 "NIC_PF_ECO2"


/**
 * NCB - nic_pf_eco3
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco3 {
	uint64_t u;
	struct bdk_nic_pf_eco3_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco3_s           cn88xx; */
} bdk_nic_pf_eco3_t;

#define BDK_NIC_PF_ECO3 BDK_NIC_PF_ECO3_FUNC()
static inline uint64_t BDK_NIC_PF_ECO3_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO3_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003030ull;
	else 		csr_fatal("BDK_NIC_PF_ECO3", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO3 bdk_nic_pf_eco3_t
#define bustype_BDK_NIC_PF_ECO3 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO3 0
#define arguments_BDK_NIC_PF_ECO3 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO3 "NIC_PF_ECO3"


/**
 * NCB - nic_pf_eco4
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco4 {
	uint64_t u;
	struct bdk_nic_pf_eco4_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco4_s           cn88xx; */
} bdk_nic_pf_eco4_t;

#define BDK_NIC_PF_ECO4 BDK_NIC_PF_ECO4_FUNC()
static inline uint64_t BDK_NIC_PF_ECO4_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO4_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003040ull;
	else 		csr_fatal("BDK_NIC_PF_ECO4", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO4 bdk_nic_pf_eco4_t
#define bustype_BDK_NIC_PF_ECO4 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO4 0
#define arguments_BDK_NIC_PF_ECO4 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO4 "NIC_PF_ECO4"


/**
 * NCB - nic_pf_eco5
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_eco5 {
	uint64_t u;
	struct bdk_nic_pf_eco5_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t eco_rw                      : 32; /**< R/W - INTERNAL: Reserved for ECO usage. */
#else
		uint64_t eco_rw                      : 32;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_eco5_s           cn88xx; */
} bdk_nic_pf_eco5_t;

#define BDK_NIC_PF_ECO5 BDK_NIC_PF_ECO5_FUNC()
static inline uint64_t BDK_NIC_PF_ECO5_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_ECO5_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000003050ull;
	else 		csr_fatal("BDK_NIC_PF_ECO5", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_ECO5 bdk_nic_pf_eco5_t
#define bustype_BDK_NIC_PF_ECO5 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_ECO5 0
#define arguments_BDK_NIC_PF_ECO5 -1,-1,-1,-1
#define basename_BDK_NIC_PF_ECO5 "NIC_PF_ECO5"


/**
 * NCB - nic_pf_int_timer_cfg
 */
typedef union bdk_nic_pf_int_timer_cfg {
	uint64_t u;
	struct bdk_nic_pf_int_timer_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t clk_per_int_tick            : 24; /**< R/W - Specifies tick period for the CQ interrupt timers in NIC_QS()_CQ()_STATUS2[GLOBAL_TIME].
                                                                 The number of coprocessor-clock cycles per tick is 16*CLK_PER_INT_TICK. */
#else
		uint64_t clk_per_int_tick            : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_pf_int_timer_cfg_s  cn88xx; */
	/* struct bdk_nic_pf_int_timer_cfg_s  cn88xxp1; */
} bdk_nic_pf_int_timer_cfg_t;

#define BDK_NIC_PF_INT_TIMER_CFG BDK_NIC_PF_INT_TIMER_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_INT_TIMER_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INT_TIMER_CFG_FUNC(void)
{
	return 0x0000843000000030ull;
}
#define typedef_BDK_NIC_PF_INT_TIMER_CFG bdk_nic_pf_int_timer_cfg_t
#define bustype_BDK_NIC_PF_INT_TIMER_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INT_TIMER_CFG 0
#define arguments_BDK_NIC_PF_INT_TIMER_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_INT_TIMER_CFG "NIC_PF_INT_TIMER_CFG"


/**
 * NCB - nic_pf_intf#_bp_cfg
 *
 * Configures backpressure on the NIC TNS receive interface.
 *
 */
typedef union bdk_nic_pf_intfx_bp_cfg {
	uint64_t u;
	struct bdk_nic_pf_intfx_bp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bp_ena                      : 1;  /**< R/W - This bit is used to enable the BP bus for this interface. */
		uint64_t reserved_5_62               : 58;
		uint64_t bp_type                     : 1;  /**< R/W - This bit is used to mark a BP channel as a BGX Backpressure Slot or a TNS Backpressure
                                                                 slot. 0=BGX, 1=TNS. */
		uint64_t bp_id                       : 4;  /**< R/W - Backpressure block ID for the NIC receive interface. Enumerated by NIC_INTF_BLOCK_E. Must
                                                                 set to NIC_INTF_BLOCK_E::TNS_PORT({a})_BLOCK if TNS is not bypassed,
                                                                 NIC_INTF_BLOCK_E::BGX({a})_BLOCK if TNS is bypassed, where {a} is the index of this
                                                                 register.
                                                                 INTERNAL: Specifies upper 4 bits of X2P channel ID. */
#else
		uint64_t bp_id                       : 4;
		uint64_t bp_type                     : 1;
		uint64_t reserved_5_62               : 58;
		uint64_t bp_ena                      : 1;
#endif
	} s;
	/* struct bdk_nic_pf_intfx_bp_cfg_s   cn88xx; */
	/* struct bdk_nic_pf_intfx_bp_cfg_s   cn88xxp1; */
} bdk_nic_pf_intfx_bp_cfg_t;

static inline uint64_t BDK_NIC_PF_INTFX_BP_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INTFX_BP_CFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000208ull + (param1 & 1) * 0x100ull;
	csr_fatal("BDK_NIC_PF_INTFX_BP_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_INTFX_BP_CFG(...) bdk_nic_pf_intfx_bp_cfg_t
#define bustype_BDK_NIC_PF_INTFX_BP_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INTFX_BP_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_INTFX_BP_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_INTFX_BP_CFG(...) "NIC_PF_INTFX_BP_CFG"


/**
 * NCB - nic_pf_intf#_bp_dis#
 */
typedef union bdk_nic_pf_intfx_bp_disx {
	uint64_t u;
	struct bdk_nic_pf_intfx_bp_disx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bp_dis                      : 64; /**< R/W - This is a bit mask that allows software to disable a backpressure channel. Setting a bit
                                                                 to 1 forces backpressure for that channel off. */
#else
		uint64_t bp_dis                      : 64;
#endif
	} s;
	/* struct bdk_nic_pf_intfx_bp_disx_s  cn88xx; */
	/* struct bdk_nic_pf_intfx_bp_disx_s  cn88xxp1; */
} bdk_nic_pf_intfx_bp_disx_t;

static inline uint64_t BDK_NIC_PF_INTFX_BP_DISX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INTFX_BP_DISX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x0000843000000210ull + (param1 & 1) * 0x100ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_INTFX_BP_DISX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_INTFX_BP_DISX(...) bdk_nic_pf_intfx_bp_disx_t
#define bustype_BDK_NIC_PF_INTFX_BP_DISX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INTFX_BP_DISX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_INTFX_BP_DISX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_INTFX_BP_DISX(...) "NIC_PF_INTFX_BP_DISX"


/**
 * NCB - nic_pf_intf#_bp_sw#
 */
typedef union bdk_nic_pf_intfx_bp_swx {
	uint64_t u;
	struct bdk_nic_pf_intfx_bp_swx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bp_sw                       : 64; /**< R/W - This is a bit mask that allows software to force a backpressure channel active. Setting a
                                                                 bit to 1 forces backpressure for that channel to be active. */
#else
		uint64_t bp_sw                       : 64;
#endif
	} s;
	/* struct bdk_nic_pf_intfx_bp_swx_s   cn88xx; */
	/* struct bdk_nic_pf_intfx_bp_swx_s   cn88xxp1; */
} bdk_nic_pf_intfx_bp_swx_t;

static inline uint64_t BDK_NIC_PF_INTFX_BP_SWX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INTFX_BP_SWX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 1)) && ((param2 <= 1)))
		return 0x0000843000000220ull + (param1 & 1) * 0x100ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_INTFX_BP_SWX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_INTFX_BP_SWX(...) bdk_nic_pf_intfx_bp_swx_t
#define bustype_BDK_NIC_PF_INTFX_BP_SWX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INTFX_BP_SWX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_INTFX_BP_SWX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_INTFX_BP_SWX(...) "NIC_PF_INTFX_BP_SWX"


/**
 * NCB - nic_pf_intf#_send_cfg
 *
 * Configures the NIC TNS send interface.
 *
 */
typedef union bdk_nic_pf_intfx_send_cfg {
	uint64_t u;
	struct bdk_nic_pf_intfx_send_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t cksum_enable                : 1;  /**< R/W - NIC_SEND_CRC_S checksum algorithm enable (NIC_SEND_CRCALG_E::CKSUM). Used for debug,
                                                                 should be clear for normal operation. Keeping the bit clear for either interface disables
                                                                 the checksum algorithm for both interfaces. When disabled, a NIC_SEND_CRC_S with
                                                                 NIC_SEND_CRCALG_E::CKSUM is treated as an error. */
		uint64_t cut_disable                 : 1;  /**< R/W - Send cut-through context disable. Used for debug, should be clear for normal operation.
                                                                 Setting the bit for either TNS interface disables cut-through for both interfaces. */
		uint64_t tstmp_wd_period             : 4;  /**< R/W - Timestamp watchdog timeout count. The timeout period is 4*(2^TSTMP_WD_PERIOD) timer ticks,
                                                                 where each tick is 1024 coprocessor-clock cycles: 0 = 4 ticks, 1 = 8 tick, ... 15 = 131072
                                                                 ticks.  If NIC
                                                                 sends a packet with NIC_SEND_HDR_S[TSTMP] = 1 and the packet is not transmitted by the
                                                                 targeted Ethernet port within the timeout period (e.g. if the packet is dropped by TNS), a
                                                                 CQ entry is posted with NIC_CQE_SEND_S[CQE_TYPE] = NIC_CQE_TYPE_E::SEND_PTP and
                                                                 NIC_CQE_SEND_S[SEND_STATUS] = NIC_CQE_SEND_STATUS_E::TSTMP_TIMEOUT. */
		uint64_t reserved_14_15              : 2;
		uint64_t l2ptr                       : 6;  /**< R/W - Layer 2 Offset. Specifies the location of the first byte of the L2 (Ethernet) header for
                                                                 all packets sent on the associated NIC TNS interface. NIC examines the L2 header to
                                                                 determine the packet type (unicast, broadcast or multicast) for updating the VNIC transmit
                                                                 statistics. */
		uint64_t tns_nonbypass               : 1;  /**< R/W - This bit must be clear when TNS is bypassed for this interface, and set when TNS is
                                                                 not bypassed:
                                                                 0 = 16 channels per LMAC; one octword (16 bytes) per send channel credit.
                                                                 1 = 32 channels per LMAC; channel credit size is specified by [TNS_CREDIT_SIZE]. */
		uint64_t reserved_6_6                : 1;
		uint64_t tns_credit_size             : 2;  /**< R/W - Send channel credit size when the TNS interface is not bypassed. Used only when
                                                                 [TNS_NONBYPASS] is set, and must be set to a value consistent with the header extraction
                                                                 size in TNS. Enumerated by NIC_TNS_CREDIT_SIZE_E. */
		uint64_t block                       : 4;  /**< R/W - Block ID for the NIC send interface. Enumerated by NIC_INTF_BLOCK_E. Must set to
                                                                 NIC_INTF_BLOCK_E::TNS_PORT({a})_BLOCK if TNS is not bypassed,
                                                                 NIC_INTF_BLOCK_E::BGX({a})_BLOCK if TNS is bypassed, where {a} is the index of this
                                                                 register.
                                                                 INTERNAL: Specifies upper 4 bits of P2X channel ID. */
#else
		uint64_t block                       : 4;
		uint64_t tns_credit_size             : 2;
		uint64_t reserved_6_6                : 1;
		uint64_t tns_nonbypass               : 1;
		uint64_t l2ptr                       : 6;
		uint64_t reserved_14_15              : 2;
		uint64_t tstmp_wd_period             : 4;
		uint64_t cut_disable                 : 1;
		uint64_t cksum_enable                : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_nic_pf_intfx_send_cfg_s cn88xx; */
	/* struct bdk_nic_pf_intfx_send_cfg_s cn88xxp1; */
} bdk_nic_pf_intfx_send_cfg_t;

static inline uint64_t BDK_NIC_PF_INTFX_SEND_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INTFX_SEND_CFG(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000200ull + (param1 & 1) * 0x100ull;
	csr_fatal("BDK_NIC_PF_INTFX_SEND_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_INTFX_SEND_CFG(...) bdk_nic_pf_intfx_send_cfg_t
#define bustype_BDK_NIC_PF_INTFX_SEND_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INTFX_SEND_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_INTFX_SEND_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_INTFX_SEND_CFG(...) "NIC_PF_INTFX_SEND_CFG"


/**
 * NCB - nic_pf_intf#_tx_fifo_status
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_intfx_tx_fifo_status {
	uint64_t u;
	struct bdk_nic_pf_intfx_tx_fifo_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_11_63              : 53;
		uint64_t count                       : 11; /**< RO/H - Number of 128-bit entries in the TX FIFO. */
#else
		uint64_t count                       : 11;
		uint64_t reserved_11_63              : 53;
#endif
	} s;
	/* struct bdk_nic_pf_intfx_tx_fifo_status_s cn88xx; */
} bdk_nic_pf_intfx_tx_fifo_status_t;

static inline uint64_t BDK_NIC_PF_INTFX_TX_FIFO_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_INTFX_TX_FIFO_STATUS(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 1)))
		return 0x0000843000000230ull + (param1 & 1) * 0x100ull;
	else 		csr_fatal("BDK_NIC_PF_INTFX_TX_FIFO_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_INTFX_TX_FIFO_STATUS(...) bdk_nic_pf_intfx_tx_fifo_status_t
#define bustype_BDK_NIC_PF_INTFX_TX_FIFO_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_INTFX_TX_FIFO_STATUS(p1) (p1)
#define arguments_BDK_NIC_PF_INTFX_TX_FIFO_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_INTFX_TX_FIFO_STATUS(...) "NIC_PF_INTFX_TX_FIFO_STATUS"


/**
 * NCB - nic_pf_lmac#_cfg
 */
typedef union bdk_nic_pf_lmacx_cfg {
	uint64_t u;
	struct bdk_nic_pf_lmacx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_15_63              : 49;
		uint64_t adjust                      : 7;  /**< R/W - Signed 4-byte adjustment to all scheduler decisions to account for per packet overhead.
                                                                 Reset of 6 (24 bytes) corresponds to 8 byte preamble, 12 byte IFG, 4 byte FCS. */
		uint64_t reserved_6_7                : 2;
		uint64_t min_pkt_size                : 4;  /**< R/W - Minimum packet size as a multiple of 4 bytes, excluding FCS potentially appended outside
                                                                 NIC by BGX. If a send descriptor specifies sending a smaller packet than this value, NIC
                                                                 zero pads the packet to this length. */
		uint64_t reserved_0_1                : 2;
#else
		uint64_t reserved_0_1                : 2;
		uint64_t min_pkt_size                : 4;
		uint64_t reserved_6_7                : 2;
		uint64_t adjust                      : 7;
		uint64_t reserved_15_63              : 49;
#endif
	} s;
	/* struct bdk_nic_pf_lmacx_cfg_s      cn88xx; */
	/* struct bdk_nic_pf_lmacx_cfg_s      cn88xxp1; */
} bdk_nic_pf_lmacx_cfg_t;

static inline uint64_t BDK_NIC_PF_LMACX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_LMACX_CFG(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000843000240000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_PF_LMACX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_LMACX_CFG(...) bdk_nic_pf_lmacx_cfg_t
#define bustype_BDK_NIC_PF_LMACX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_LMACX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_LMACX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_LMACX_CFG(...) "NIC_PF_LMACX_CFG"


/**
 * NCB - nic_pf_lmac#_cfg2
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_lmacx_cfg2 {
	uint64_t u;
	struct bdk_nic_pf_lmacx_cfg2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_14_63              : 50;
		uint64_t max_pkt_size                : 14; /**< R/W - Minimum packet size in bytes, excluding FCS potentially appended outside NIC by BGX.
                                                                 Should not exceed 9212 (9216 minus 4 byte FCS). If a send descriptor specifies sending a
                                                                 larger packet than this value, NIC drops the packet and posts a CQE with
                                                                 NIC_CQE_SEND_STATUS_E::MAX_SIZE_VIOL. */
#else
		uint64_t max_pkt_size                : 14;
		uint64_t reserved_14_63              : 50;
#endif
	} s;
	/* struct bdk_nic_pf_lmacx_cfg2_s     cn88xx; */
} bdk_nic_pf_lmacx_cfg2_t;

static inline uint64_t BDK_NIC_PF_LMACX_CFG2(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_LMACX_CFG2(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 7)))
		return 0x0000843000240100ull + (param1 & 7) * 0x8ull;
	else 		csr_fatal("BDK_NIC_PF_LMACX_CFG2", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_LMACX_CFG2(...) bdk_nic_pf_lmacx_cfg2_t
#define bustype_BDK_NIC_PF_LMACX_CFG2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_LMACX_CFG2(p1) (p1)
#define arguments_BDK_NIC_PF_LMACX_CFG2(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_LMACX_CFG2(...) "NIC_PF_LMACX_CFG2"


/**
 * NCB - nic_pf_lmac#_credit
 */
typedef union bdk_nic_pf_lmacx_credit {
	uint64_t u;
	struct bdk_nic_pf_lmacx_credit_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t cc_unit_cnt                 : 20; /**< R/W/H - Channel-credit unit count. This value, plus 1 MTU, represents the maximum outstanding
                                                                 aggregate channel credit units for this LMAC. A credit unit is 16 bytes when the
                                                                 associated TNS interface is bypassed (NIC_PF_INTF()_SEND_CFG[TNS_NONBYPASS] is clear),
                                                                 and one TNS credit unit otherwise, as specified by
                                                                 NIC_PF_INTF()_SEND_CFG[TNS_CREDIT_SIZE]. Note that this 20-bit field represents a
                                                                 signed value that decrements towards zero as credits are used. Packets are not allowed to
                                                                 flow when the count is less than zero. As such, the most significant bit should normally
                                                                 be programmed as zero (positive count). This gives a maximum value for this field of 2^19
                                                                 - 1.

                                                                 In order to prevent blocking between LMACs when the associated TNS interface is bypassed,
                                                                 CC_ENABLE should be set to 1 and CC_UNIT_CNT should be less than

                                                                 _     ((LMAC TX buffer size in BGX) - (MTU excluding FCS))/16

                                                                 The LMAC TX buffer size is defined by BGX()_CMR_TX_LMACS[LMACS]. For example, if TNS is
                                                                 bypassed, BGX()_CMR_TX_LMACS[LMACS]=0x4 (12 KB per LMAC) and the LMAC's MTU excluding FCS
                                                                 is 9212 bytes (9216 minus 4 byte FCS), then CC_UNIT_CNT should be \< (12288 - 9212)/16 =
                                                                 192. */
		uint64_t cc_packet_cnt               : 10; /**< R/W/H - Channel-credit packet count. This value, plus 1, represents the maximum outstanding
                                                                 aggregate packet count for this LMAC. Note that this 10-bit field represents a signed
                                                                 value that decrements towards zero as credits are used. Packets are not allowed to flow
                                                                 when the count is less than zero. As such the most significant bit should normally be
                                                                 programmed as zero (positive count). This gives a maximum value for this field of 2^9 - 1. */
		uint64_t cc_enable                   : 1;  /**< R/W - Channel-credit enable. Enables CC_UNIT_CNT and CC_PACKET_CNT aggregate credit processing. */
		uint64_t reserved_0_0                : 1;
#else
		uint64_t reserved_0_0                : 1;
		uint64_t cc_enable                   : 1;
		uint64_t cc_packet_cnt               : 10;
		uint64_t cc_unit_cnt                 : 20;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_lmacx_credit_s   cn88xx; */
	/* struct bdk_nic_pf_lmacx_credit_s   cn88xxp1; */
} bdk_nic_pf_lmacx_credit_t;

static inline uint64_t BDK_NIC_PF_LMACX_CREDIT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_LMACX_CREDIT(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000843000244000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_PF_LMACX_CREDIT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_LMACX_CREDIT(...) bdk_nic_pf_lmacx_credit_t
#define bustype_BDK_NIC_PF_LMACX_CREDIT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_LMACX_CREDIT(p1) (p1)
#define arguments_BDK_NIC_PF_LMACX_CREDIT(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_LMACX_CREDIT(...) "NIC_PF_LMACX_CREDIT"


/**
 * NCB - nic_pf_lmac#_sw_xoff
 */
typedef union bdk_nic_pf_lmacx_sw_xoff {
	uint64_t u;
	struct bdk_nic_pf_lmacx_sw_xoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t sw_xoff                     : 1;  /**< R/W - Software XOFF. When set, this LMAC does not send traffic. */
#else
		uint64_t sw_xoff                     : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_lmacx_sw_xoff_s  cn88xx; */
	/* struct bdk_nic_pf_lmacx_sw_xoff_s  cn88xxp1; */
} bdk_nic_pf_lmacx_sw_xoff_t;

static inline uint64_t BDK_NIC_PF_LMACX_SW_XOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_LMACX_SW_XOFF(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000843000242000ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_PF_LMACX_SW_XOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_LMACX_SW_XOFF(...) bdk_nic_pf_lmacx_sw_xoff_t
#define bustype_BDK_NIC_PF_LMACX_SW_XOFF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_LMACX_SW_XOFF(p1) (p1)
#define arguments_BDK_NIC_PF_LMACX_SW_XOFF(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_LMACX_SW_XOFF(...) "NIC_PF_LMACX_SW_XOFF"


/**
 * NCB - nic_pf_mbox_ena_w1c#
 */
typedef union bdk_nic_pf_mbox_ena_w1cx {
	uint64_t u;
	struct bdk_nic_pf_mbox_ena_w1cx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mbox                        : 64; /**< R/W1C/H - One interrupt bit per VF, NIC_PF_MBOX_INT(0)[MBOX\<63:0\>] for VFs 63-0,
                                                                 NIC_PF_MBOX_INT(1)[MBOX\<63:0\>] for VFs 127-64.  Each bit is set when the associated
                                                                 NIC_VF(0..127)_PF_MBOX(1) register is written. */
#else
		uint64_t mbox                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_mbox_ena_w1cx_s  cn88xx; */
	/* struct bdk_nic_pf_mbox_ena_w1cx_s  cn88xxp1; */
} bdk_nic_pf_mbox_ena_w1cx_t;

static inline uint64_t BDK_NIC_PF_MBOX_ENA_W1CX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MBOX_ENA_W1CX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000450ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_MBOX_ENA_W1CX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MBOX_ENA_W1CX(...) bdk_nic_pf_mbox_ena_w1cx_t
#define bustype_BDK_NIC_PF_MBOX_ENA_W1CX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MBOX_ENA_W1CX(p1) (p1)
#define arguments_BDK_NIC_PF_MBOX_ENA_W1CX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MBOX_ENA_W1CX(...) "NIC_PF_MBOX_ENA_W1CX"


/**
 * NCB - nic_pf_mbox_ena_w1s#
 */
typedef union bdk_nic_pf_mbox_ena_w1sx {
	uint64_t u;
	struct bdk_nic_pf_mbox_ena_w1sx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mbox                        : 64; /**< R/W1C/H - One interrupt bit per VF, NIC_PF_MBOX_INT(0)[MBOX\<63:0\>] for VFs 63-0,
                                                                 NIC_PF_MBOX_INT(1)[MBOX\<63:0\>] for VFs 127-64.  Each bit is set when the associated
                                                                 NIC_VF(0..127)_PF_MBOX(1) register is written. */
#else
		uint64_t mbox                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_mbox_ena_w1sx_s  cn88xx; */
	/* struct bdk_nic_pf_mbox_ena_w1sx_s  cn88xxp1; */
} bdk_nic_pf_mbox_ena_w1sx_t;

static inline uint64_t BDK_NIC_PF_MBOX_ENA_W1SX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MBOX_ENA_W1SX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000470ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_MBOX_ENA_W1SX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MBOX_ENA_W1SX(...) bdk_nic_pf_mbox_ena_w1sx_t
#define bustype_BDK_NIC_PF_MBOX_ENA_W1SX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MBOX_ENA_W1SX(p1) (p1)
#define arguments_BDK_NIC_PF_MBOX_ENA_W1SX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MBOX_ENA_W1SX(...) "NIC_PF_MBOX_ENA_W1SX"


/**
 * NCB - nic_pf_mbox_int#
 */
typedef union bdk_nic_pf_mbox_intx {
	uint64_t u;
	struct bdk_nic_pf_mbox_intx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mbox                        : 64; /**< R/W1C/H - One interrupt bit per VF, NIC_PF_MBOX_INT(0)[MBOX\<63:0\>] for VFs 63-0,
                                                                 NIC_PF_MBOX_INT(1)[MBOX\<63:0\>] for VFs 127-64.  Each bit is set when the associated
                                                                 NIC_VF(0..127)_PF_MBOX(1) register is written. */
#else
		uint64_t mbox                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_mbox_intx_s      cn88xx; */
	/* struct bdk_nic_pf_mbox_intx_s      cn88xxp1; */
} bdk_nic_pf_mbox_intx_t;

static inline uint64_t BDK_NIC_PF_MBOX_INTX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MBOX_INTX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000410ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_MBOX_INTX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MBOX_INTX(...) bdk_nic_pf_mbox_intx_t
#define bustype_BDK_NIC_PF_MBOX_INTX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MBOX_INTX(p1) (p1)
#define arguments_BDK_NIC_PF_MBOX_INTX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MBOX_INTX(...) "NIC_PF_MBOX_INTX"


/**
 * NCB - nic_pf_mbox_int_w1s#
 */
typedef union bdk_nic_pf_mbox_int_w1sx {
	uint64_t u;
	struct bdk_nic_pf_mbox_int_w1sx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t mbox                        : 64; /**< R/W1C/H - One interrupt bit per VF, NIC_PF_MBOX_INT(0)[MBOX\<63:0\>] for VFs 63-0,
                                                                 NIC_PF_MBOX_INT(1)[MBOX\<63:0\>] for VFs 127-64.  Each bit is set when the associated
                                                                 NIC_VF(0..127)_PF_MBOX(1) register is written. */
#else
		uint64_t mbox                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_mbox_int_w1sx_s  cn88xx; */
	/* struct bdk_nic_pf_mbox_int_w1sx_s  cn88xxp1; */
} bdk_nic_pf_mbox_int_w1sx_t;

static inline uint64_t BDK_NIC_PF_MBOX_INT_W1SX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MBOX_INT_W1SX(unsigned long param1)
{
	if (((param1 <= 1)))
		return 0x0000843000000430ull + (param1 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_MBOX_INT_W1SX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MBOX_INT_W1SX(...) bdk_nic_pf_mbox_int_w1sx_t
#define bustype_BDK_NIC_PF_MBOX_INT_W1SX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MBOX_INT_W1SX(p1) (p1)
#define arguments_BDK_NIC_PF_MBOX_INT_W1SX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MBOX_INT_W1SX(...) "NIC_PF_MBOX_INT_W1SX"


/**
 * NCB - nic_pf_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the NIC_PF_INT_VEC_E
 * enumeration.
 */
typedef union bdk_nic_pf_msix_pbax {
	uint64_t u;
	struct bdk_nic_pf_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated NIC_PF_MSIX_VEC()_CTL, enumerated by
                                                                 NIC_PF_INT_VEC_E.
                                                                 Bits that have no associated NIC_PF_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_msix_pbax_s      cn88xx; */
	/* struct bdk_nic_pf_msix_pbax_s      cn88xxp1; */
} bdk_nic_pf_msix_pbax_t;

static inline uint64_t BDK_NIC_PF_MSIX_PBAX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MSIX_PBAX(unsigned long param1)
{
	if (((param1 == 0)))
		return 0x00008430600F0000ull;
	csr_fatal("BDK_NIC_PF_MSIX_PBAX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MSIX_PBAX(...) bdk_nic_pf_msix_pbax_t
#define bustype_BDK_NIC_PF_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MSIX_PBAX(p1) (p1)
#define arguments_BDK_NIC_PF_MSIX_PBAX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MSIX_PBAX(...) "NIC_PF_MSIX_PBAX"


/**
 * NCB - nic_pf_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the NIC_PF_INT_VEC_E enumeration.
 *
 */
typedef union bdk_nic_pf_msix_vecx_addr {
	uint64_t u;
	struct bdk_nic_pf_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< SR/W - Secure vector.
                                                                 0 = This vector may be read or written by either secure or non-secure states.
                                                                 1 = This vector's NIC_PF_MSIX_VEC()_ADDR, NIC_PF_MSIX_VEC()_CTL, and corresponding
                                                                 bit of NIC_PF_MSIX_PBA() are RAZ/WI and does not cause a fault when accessed
                                                                 by the non-secure world.

                                                                 If PCCPF_NIC_VSEC_SCTL[MSIX_SEC] (for documentation, see PCCPF_XXX_VSEC_SCTL[MSIX_SEC]) is
                                                                 set, all vectors are secure and function as if [SECVEC] was set. */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_nic_pf_msix_vecx_addr_s cn88xx; */
	/* struct bdk_nic_pf_msix_vecx_addr_s cn88xxp1; */
} bdk_nic_pf_msix_vecx_addr_t;

static inline uint64_t BDK_NIC_PF_MSIX_VECX_ADDR(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MSIX_VECX_ADDR(unsigned long param1)
{
	if (((param1 <= 9)))
		return 0x0000843060000000ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_NIC_PF_MSIX_VECX_ADDR", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MSIX_VECX_ADDR(...) bdk_nic_pf_msix_vecx_addr_t
#define bustype_BDK_NIC_PF_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MSIX_VECX_ADDR(p1) (p1)
#define arguments_BDK_NIC_PF_MSIX_VECX_ADDR(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MSIX_VECX_ADDR(...) "NIC_PF_MSIX_VECX_ADDR"


/**
 * NCB - nic_pf_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the NIC_PF_INT_VEC_E enumeration.
 *
 */
typedef union bdk_nic_pf_msix_vecx_ctl {
	uint64_t u;
	struct bdk_nic_pf_msix_vecx_ctl_s {
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
	/* struct bdk_nic_pf_msix_vecx_ctl_s  cn88xx; */
	/* struct bdk_nic_pf_msix_vecx_ctl_s  cn88xxp1; */
} bdk_nic_pf_msix_vecx_ctl_t;

static inline uint64_t BDK_NIC_PF_MSIX_VECX_CTL(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_MSIX_VECX_CTL(unsigned long param1)
{
	if (((param1 <= 9)))
		return 0x0000843060000008ull + (param1 & 15) * 0x10ull;
	csr_fatal("BDK_NIC_PF_MSIX_VECX_CTL", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_MSIX_VECX_CTL(...) bdk_nic_pf_msix_vecx_ctl_t
#define bustype_BDK_NIC_PF_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_MSIX_VECX_CTL(p1) (p1)
#define arguments_BDK_NIC_PF_MSIX_VECX_CTL(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_MSIX_VECX_CTL(...) "NIC_PF_MSIX_VECX_CTL"


/**
 * NCB - nic_pf_pkind#_cfg
 */
typedef union bdk_nic_pf_pkindx_cfg {
	uint64_t u;
	struct bdk_nic_pf_pkindx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_42_63              : 22;
		uint64_t hdr_sl                      : 5;  /**< R/W - Header skip length. Number of 2-byte words parser should skip between the start of the
                                                                 packet and the NIC_RX_HDR_S (if [RX_HDR] is set) or Ethernet address (if [RX_HDR] is
                                                                 clear). For BGX, should be 0x4 if a timestamp is present; see also
                                                                 BGX()_SMU()_RX_FRM_CTL[PTP_MODE]. For TNS should be 0x8. */
		uint64_t rx_hdr                      : 3;  /**< R/W - Receive header present.
                                                                 0x0 = No NIC_RX_HDR_S is present.
                                                                 0x1 = Reserved.
                                                                 0x2 = NIC_RX_HDR_S is present, two bytes are valid; NIC_RX_HDR_S[RSS_FLOW, HDR_SL and
                                                                 RSS_DIS] are not read from the packet and treated as if zero.
                                                                 0x3 = NIC_RX_HDR_S is present, three bytes are valid; NIC_RX_HDR_S[RSS_FLOW] are not read
                                                                 from the packet and treated as if zero.
                                                                 0x4 = NIC_RX_HDR_S is present, four bytes are valid.
                                                                 0x5-0x7 = Reserved. */
		uint64_t lenerr_en                   : 1;  /**< R/W - L2 length error check enable. Check if frame was received with L2 length error, see
                                                                 NIC_ERROP_E::L2_LENMISM. */
		uint64_t reserved_32_32              : 1;
		uint64_t maxlen                      : 16; /**< R/W - Byte count for max-sized frame check. See NIC_ERROP_E::L2_OVERSIZE. This length must
                                                                 include any timstamps or NIC_CQE_RX_S, and any VLANs which may be stripped. FCS bytes are
                                                                 not included. Set to all-ones to disable this check. */
		uint64_t minlen                      : 16; /**< R/W - Byte count for min-sized frame check. See NIC_ERROP_E::L2_UNDERSIZE. Set to zero to
                                                                 disable this check. */
#else
		uint64_t minlen                      : 16;
		uint64_t maxlen                      : 16;
		uint64_t reserved_32_32              : 1;
		uint64_t lenerr_en                   : 1;
		uint64_t rx_hdr                      : 3;
		uint64_t hdr_sl                      : 5;
		uint64_t reserved_42_63              : 22;
#endif
	} s;
	/* struct bdk_nic_pf_pkindx_cfg_s     cn88xx; */
	/* struct bdk_nic_pf_pkindx_cfg_s     cn88xxp1; */
} bdk_nic_pf_pkindx_cfg_t;

static inline uint64_t BDK_NIC_PF_PKINDX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_PKINDX_CFG(unsigned long param1)
{
	if (((param1 <= 15)))
		return 0x0000843000000600ull + (param1 & 15) * 0x8ull;
	csr_fatal("BDK_NIC_PF_PKINDX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_PKINDX_CFG(...) bdk_nic_pf_pkindx_cfg_t
#define bustype_BDK_NIC_PF_PKINDX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_PKINDX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_PKINDX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_PKINDX_CFG(...) "NIC_PF_PKINDX_CFG"


/**
 * NCB - nic_pf_qs#_cfg
 */
typedef union bdk_nic_pf_qsx_cfg {
	uint64_t u;
	struct bdk_nic_pf_qsx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t ena                         : 1;  /**< R/W - Enable QS. */
		uint64_t reserved_27_30              : 4;
		uint64_t sq_ins_ena                  : 1;  /**< R/W - SQ data insertion enable. When set, insert NIC_PF_QS()_SQ()_CFG[SQ_INS_DATA]
                                                                 into transmitted packets. */
		uint64_t sq_ins_pos                  : 6;  /**< R/W - SQ data insertion position. When [SQ_INS_ENA] is set, the byte number in the transmitted
                                                                 packet at which to insert the least significant byte of
                                                                 NIC_PF_QS()_SQ()_CFG[SQ_INS_DATA]. Bytes are numbered in little endian form,
                                                                 with byte 0 the first byte onto the wire. */
		uint64_t lock_ena                    : 1;  /**< R/W - Lockdown enable. When set, the NIC_PF_QS()_LOCK() registers can be used to lock
                                                                 down one of more bytes in packets transmitted by the QS. */
		uint64_t lock_viol_cqe_ena           : 1;  /**< R/W - Enable generation of NIC_CQE_SEND_S with SEND_STATUS=NIC_CQE_SEND_STATUS_E::LOCK_VIOL. */
		uint64_t send_tstmp_ena              : 1;  /**< R/W - Send timestamp enable. When set, the QS is allowed to send packets with NIC_SEND_HDR_S[TSTMP]=1. */
		uint64_t be                          : 1;  /**< R/W - Big-endian mode. Specifies big-endian for data structures in L2C/DRAM that are accessed by
                                                                 the QS.

                                                                 When set, all data structures are in byte invariant big-endian format (BE8) with the
                                                                 following ordering within each 64-bit word: \<63:56\> at byte address 0, \<55:48\> at address
                                                                 1, ..., \<7:0\> at address 0x7.

                                                                 When clear, all data structures are in byte invariant little-endian format (LE8) with the
                                                                 following ordering within each 64-bit word: \<7:0\> at byte address 0, \<15:8\> at address 1,
                                                                 ..., \<63:56\> at address 0x7.

                                                                 The affected data structures are:
                                                                 * Receive buffer descriptor: NIC_RBDR_ENTRY_S.
                                                                 * All send subdescriptors: NIC_SEND_*_S.
                                                                 * All CQ entries, i.e. all structures starting with  NIC_CQE_RX_S and NIC_CQE_SEND_S,
                                                                 excluding any packet data embedded in these structures.
                                                                 Note that this bit does not affect the byte ordering of packet data, which is treated as a
                                                                 byte stream transmitted by incrementing byte address. The same byte ordering is also used
                                                                 for packet data that may be embedded in CQ entries that start with NIC_CQE_RX_S, or
                                                                 immediate data in or following NIC_SEND_IMM_S. */
		uint64_t reserved_7_15               : 9;
		uint64_t vnic                        : 7;  /**< R/W - VNIC to which this QS is assigned. If this QS is a VNIC, then must be set to the QS number. */
#else
		uint64_t vnic                        : 7;
		uint64_t reserved_7_15               : 9;
		uint64_t be                          : 1;
		uint64_t send_tstmp_ena              : 1;
		uint64_t lock_viol_cqe_ena           : 1;
		uint64_t lock_ena                    : 1;
		uint64_t sq_ins_pos                  : 6;
		uint64_t sq_ins_ena                  : 1;
		uint64_t reserved_27_30              : 4;
		uint64_t ena                         : 1;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_cfg_s        cn88xx; */
	/* struct bdk_nic_pf_qsx_cfg_s        cn88xxp1; */
} bdk_nic_pf_qsx_cfg_t;

static inline uint64_t BDK_NIC_PF_QSX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_CFG(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x0000843020010000ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_PF_QSX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_CFG(...) bdk_nic_pf_qsx_cfg_t
#define bustype_BDK_NIC_PF_QSX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_QSX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_QSX_CFG(...) "NIC_PF_QSX_CFG"


/**
 * NCB - nic_pf_qs#_lock#
 *
 * Changed in pass 2 to increase lockdown bytes per QS from 64 to 96.
 *
 */
typedef union bdk_nic_pf_qsx_lockx {
	uint64_t u;
	struct bdk_nic_pf_qsx_lockx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_36_63              : 28;
		uint64_t byte_ena                    : 4;  /**< R/W - Lockdown byte enable. Each set bit indicates that the transmitted packet's corresponding
                                                                 byte number will be compared against [DATA]. */
		uint64_t data                        : 32; /**< R/W - Lockdown data. If corresponding [BYTE_ENA] is set and NIC_PF_QS()_CFG[LOCK_ENA] is
                                                                 set, outbound packet data must match the [DATA] byte or the packet will be dropped. Bytes
                                                                 are numbered in little endian form, with byte 0 the first byte onto the wire:
                                                                 _ If LOCK(0)[BYTE_EN]\<0\> set, LOCK(0)[DATA]\<7:0\> = packet byte 0.
                                                                 _ If LOCK(0)[BYTE_EN]\<1\> set, LOCK(0)[DATA]\<15:8\> = packet byte 1.
                                                                 _ If LOCK(0)[BYTE_EN]\<2\> set, LOCK(0)[DATA]\<23:16\> = packet byte 2.
                                                                 _ If LOCK(0)[BYTE_EN]\<3\> set, LOCK(0)[DATA]\<31:24\> = packet byte 3.
                                                                 _ ...
                                                                 _ If LOCK(1)[BYTE_EN]\<0\> set, LOCK(1)[DATA]\<7:0\> = packet byte 4.
                                                                 _ ...
                                                                 _ If LOCK(15)[BYTE_EN]\<3\> set, LOCK(15)[DATA]\<31:24\> = packet byte 63. */
#else
		uint64_t data                        : 32;
		uint64_t byte_ena                    : 4;
		uint64_t reserved_36_63              : 28;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_lockx_s      cn88xx; */
	/* struct bdk_nic_pf_qsx_lockx_s      cn88xxp1; */
} bdk_nic_pf_qsx_lockx_t;

static inline uint64_t BDK_NIC_PF_QSX_LOCKX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_LOCKX(unsigned long param1, unsigned long param2)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((param1 <= 127)) && ((param2 <= 15)))
		return 0x0000843020006000ull + (param1 & 127) * 0x200000ull + (param2 & 15) * 0x8ull;
	else if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 127)) && ((param2 <= 23)))
		return 0x0000843020006000ull + (param1 & 127) * 0x200000ull + (param2 & 31) * 0x8ull;
	else 		csr_fatal("BDK_NIC_PF_QSX_LOCKX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_LOCKX(...) bdk_nic_pf_qsx_lockx_t
#define bustype_BDK_NIC_PF_QSX_LOCKX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_LOCKX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_LOCKX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_LOCKX(...) "NIC_PF_QSX_LOCKX"


/**
 * NCB - nic_pf_qs#_rq#_bp_cfg
 */
typedef union bdk_nic_pf_qsx_rqx_bp_cfg {
	uint64_t u;
	struct bdk_nic_pf_qsx_rqx_bp_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rbdr_bp_ena                 : 1;  /**< R/W - Enables BP based off the RBDR levels of the Start and Continue Rings. */
		uint64_t cq_bp_ena                   : 1;  /**< R/W - Enables BP based off the CQ level. */
		uint64_t reserved_24_61              : 38;
		uint64_t rbdr_bp                     : 8;  /**< R/W - Threshold level for backpressuring channel, in units of 1/256th of RBDR level. */
		uint64_t cq_bp                       : 8;  /**< R/W - Threshold level for backpressuring channel, in units of 1/256th of CQ level. */
		uint64_t bpid                        : 8;  /**< R/W - (0..1) to assert backpressure on. */
#else
		uint64_t bpid                        : 8;
		uint64_t cq_bp                       : 8;
		uint64_t rbdr_bp                     : 8;
		uint64_t reserved_24_61              : 38;
		uint64_t cq_bp_ena                   : 1;
		uint64_t rbdr_bp_ena                 : 1;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_rqx_bp_cfg_s cn88xx; */
	/* struct bdk_nic_pf_qsx_rqx_bp_cfg_s cn88xxp1; */
} bdk_nic_pf_qsx_rqx_bp_cfg_t;

static inline uint64_t BDK_NIC_PF_QSX_RQX_BP_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_RQX_BP_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x0000843020010500ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_PF_QSX_RQX_BP_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_RQX_BP_CFG(...) bdk_nic_pf_qsx_rqx_bp_cfg_t
#define bustype_BDK_NIC_PF_QSX_RQX_BP_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_RQX_BP_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_RQX_BP_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_RQX_BP_CFG(...) "NIC_PF_QSX_RQX_BP_CFG"


/**
 * NCB - nic_pf_qs#_rq#_cfg
 *
 * Used by the PF to map shared resources to a Receive Queue.
 *
 */
typedef union bdk_nic_pf_qsx_rqx_cfg {
	uint64_t u;
	struct bdk_nic_pf_qsx_rqx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t tcp_off                     : 1;  /**< R/W - Reserved. INTERNAL: Reserved for future use - Overrides NIC_QS()_RQ()_CFG[TCP_ENA]. */
		uint64_t reserved_30_62              : 33;
		uint64_t rx_cqm_format               : 1;  /**< RAZ - Reserved. */
		uint64_t strip_pre_l2                : 1;  /**< R/W - All bytes that come before the SA/DA of the L2 Layer are stripped not saved in the RBDR buffer. */
		uint64_t caching                     : 2;  /**< R/W - Select the style of write to the L2C.
                                                                 0 = writes of RBDR data will not allocate into the L2C.
                                                                 1 = all writes of RBDR data are allocated into the L2C.
                                                                 2 = the first aligned cache block is allocated into the L2C. All remaining cache blocks
                                                                 are not allocated.
                                                                 3 = the first two aligned cache blocks are allocated into the L2C. All remaining cache
                                                                 blocks are not allocated. */
		uint64_t cq_qs                       : 7;  /**< R/W - CQ's QS for this RQ. The CQ's QS must be assigned to the same VNIC as the RQ's QS. */
		uint64_t cq_idx                      : 3;  /**< R/W - CQ within [CQ_QS] for this RQ. */
		uint64_t rbdr_cont_qs                : 7;  /**< R/W - QS portion of RBDR to use for continue buffers. */
		uint64_t rbdr_cont_idx               : 1;  /**< R/W - Index within QS of RBDR to use for continue buffers. */
		uint64_t rbdr_strt_qs                : 7;  /**< R/W - QS portion of RBDR to use used for first buffer. */
		uint64_t rbdr_strt_idx               : 1;  /**< R/W - Index within OQ of RBDR to use for first buffer. */
#else
		uint64_t rbdr_strt_idx               : 1;
		uint64_t rbdr_strt_qs                : 7;
		uint64_t rbdr_cont_idx               : 1;
		uint64_t rbdr_cont_qs                : 7;
		uint64_t cq_idx                      : 3;
		uint64_t cq_qs                       : 7;
		uint64_t caching                     : 2;
		uint64_t strip_pre_l2                : 1;
		uint64_t rx_cqm_format               : 1;
		uint64_t reserved_30_62              : 33;
		uint64_t tcp_off                     : 1;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_rqx_cfg_s    cn88xx; */
	/* struct bdk_nic_pf_qsx_rqx_cfg_s    cn88xxp1; */
} bdk_nic_pf_qsx_rqx_cfg_t;

static inline uint64_t BDK_NIC_PF_QSX_RQX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_RQX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x0000843020010400ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_PF_QSX_RQX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_RQX_CFG(...) bdk_nic_pf_qsx_rqx_cfg_t
#define bustype_BDK_NIC_PF_QSX_RQX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_RQX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_RQX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_RQX_CFG(...) "NIC_PF_QSX_RQX_CFG"


/**
 * NCB - nic_pf_qs#_rq#_drop_cfg
 */
typedef union bdk_nic_pf_qsx_rqx_drop_cfg {
	uint64_t u;
	struct bdk_nic_pf_qsx_rqx_drop_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t rbdr_red                    : 1;  /**< R/W - Enable RBDR RED drop between PASS and DROP levels. */
		uint64_t cq_red                      : 1;  /**< R/W - Enable CQ RED drop between PASS and DROP levels. */
		uint64_t reserved_48_61              : 14;
		uint64_t rbdr_pass                   : 8;  /**< R/W - Threshold level for RED accepting packets, in units of 1/256th of RBDR level.
                                                                 0xff represents a full ring, 0x0 repsents and empty ring.
                                                                 If the RBDR level is greater \>= to this value then the packet is received.
                                                                 If the RBDR level is less that this value but \>= the RBDR_DROP value then the packet is in
                                                                 the RED zone
                                                                 If the RBDR level is \< the RBDR_DROP level, then the packet is dropped. */
		uint64_t rbdr_drop                   : 8;  /**< R/W - Threshold level for RED dropping packets, in units of 1/256th of RBDR level. See RBDR_PASS
                                                                 for more details. */
		uint64_t reserved_24_31              : 8;
		uint64_t cq_pass                     : 8;  /**< R/W - Threshold level for RED accepting packets, in units of 1/256th of CQ level.
                                                                 0xff represents a full ring, 0x0 repsents and empty ring.
                                                                 If the CQ level is greater \>= to this value then the packet is received.
                                                                 If the CQ level is less that this value but \>= the CQ_DROP value then the packet is in the
                                                                 RED zone
                                                                 If the CQ level is \< the CQ_DROP level, then the packet is dropped. */
		uint64_t cq_drop                     : 8;  /**< R/W - Threshold level for RED dropping packets, in units of 1/256th of CQ level. See CQ_PASS for
                                                                 more details. */
		uint64_t reserved_0_7                : 8;
#else
		uint64_t reserved_0_7                : 8;
		uint64_t cq_drop                     : 8;
		uint64_t cq_pass                     : 8;
		uint64_t reserved_24_31              : 8;
		uint64_t rbdr_drop                   : 8;
		uint64_t rbdr_pass                   : 8;
		uint64_t reserved_48_61              : 14;
		uint64_t cq_red                      : 1;
		uint64_t rbdr_red                    : 1;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_rqx_drop_cfg_s cn88xx; */
	/* struct bdk_nic_pf_qsx_rqx_drop_cfg_s cn88xxp1; */
} bdk_nic_pf_qsx_rqx_drop_cfg_t;

static inline uint64_t BDK_NIC_PF_QSX_RQX_DROP_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_RQX_DROP_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x0000843020010420ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_PF_QSX_RQX_DROP_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_RQX_DROP_CFG(...) bdk_nic_pf_qsx_rqx_drop_cfg_t
#define bustype_BDK_NIC_PF_QSX_RQX_DROP_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_RQX_DROP_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_RQX_DROP_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_RQX_DROP_CFG(...) "NIC_PF_QSX_RQX_DROP_CFG"


/**
 * NCB - nic_pf_qs#_rq#_stat#
 *
 * The third dimension indicates which statistic, and is enumerated by NIC_STAT_RQ_E.
 *
 */
typedef union bdk_nic_pf_qsx_rqx_statx {
	uint64_t u;
	struct bdk_nic_pf_qsx_rqx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< R/W/H - Statistic value. See also NIC_QS()_RQ()_STAT() for a read-only alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_rqx_statx_s  cn88xx; */
	/* struct bdk_nic_pf_qsx_rqx_statx_s  cn88xxp1; */
} bdk_nic_pf_qsx_rqx_statx_t;

static inline uint64_t BDK_NIC_PF_QSX_RQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_RQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 127)) && ((param2 <= 7)) && ((param3 <= 1)))
		return 0x0000843020010600ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_QSX_RQX_STATX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_RQX_STATX(...) bdk_nic_pf_qsx_rqx_statx_t
#define bustype_BDK_NIC_PF_QSX_RQX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_RQX_STATX(p1,p2,p3) (p1)
#define arguments_BDK_NIC_PF_QSX_RQX_STATX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_NIC_PF_QSX_RQX_STATX(...) "NIC_PF_QSX_RQX_STATX"


/**
 * NCB - nic_pf_qs#_sq#_cfg
 */
typedef union bdk_nic_pf_qsx_sqx_cfg {
	uint64_t u;
	struct bdk_nic_pf_qsx_sqx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t sq_ins_data                 : 16; /**< R/W - SQ insertion data.If NIC_PF_QS()_CFG[SQ_INS_ENA] is set, this is the data inserted
                                                                 in every packet transmitted by the SQ, as follows:
                                                                 * [SQ_INS_DATA]\<7:0\> = packet byte NIC_PF_QS()_CFG[SQ_INS_POS]
                                                                 * [SQ_INS_DATA]\<15:8\> = packet byte NIC_PF_QS()_CFG[SQ_INS_POS]+1 */
		uint64_t reserved_10_31              : 22;
		uint64_t cq_qs                       : 7;  /**< R/W - CQ's QS for this SQ. The CQ's QS must be assigned to the same VNIC as the SQ's QS. */
		uint64_t cq_idx                      : 3;  /**< R/W - CQ within [CQ_QS] for this SQ. */
#else
		uint64_t cq_idx                      : 3;
		uint64_t cq_qs                       : 7;
		uint64_t reserved_10_31              : 22;
		uint64_t sq_ins_data                 : 16;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_sqx_cfg_s    cn88xx; */
	/* struct bdk_nic_pf_qsx_sqx_cfg_s    cn88xxp1; */
} bdk_nic_pf_qsx_sqx_cfg_t;

static inline uint64_t BDK_NIC_PF_QSX_SQX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_SQX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x0000843020010C00ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_PF_QSX_SQX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_SQX_CFG(...) bdk_nic_pf_qsx_sqx_cfg_t
#define bustype_BDK_NIC_PF_QSX_SQX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_SQX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_SQX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_SQX_CFG(...) "NIC_PF_QSX_SQX_CFG"


/**
 * NCB - nic_pf_qs#_sq#_cfg2
 */
typedef union bdk_nic_pf_qsx_sqx_cfg2 {
	uint64_t u;
	struct bdk_nic_pf_qsx_sqx_cfg2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t tl4                         : 10; /**< R/W - TL4 index. Must point to the unique TL4 that will service this traffic, and
                                                                 NIC_PF_TL4()_CFG[SQ_QS]/[SQ_IDX] must point back to this SQ. As the VF controls
                                                                 NIC_QS()_SQ()_CFG[ENA], these pointers should be valid even for non-enabled SQs. */
#else
		uint64_t tl4                         : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_sqx_cfg2_s   cn88xx; */
	/* struct bdk_nic_pf_qsx_sqx_cfg2_s   cn88xxp1; */
} bdk_nic_pf_qsx_sqx_cfg2_t;

static inline uint64_t BDK_NIC_PF_QSX_SQX_CFG2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_SQX_CFG2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x0000843020010C08ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_PF_QSX_SQX_CFG2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_SQX_CFG2(...) bdk_nic_pf_qsx_sqx_cfg2_t
#define bustype_BDK_NIC_PF_QSX_SQX_CFG2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_SQX_CFG2(p1,p2) (p1)
#define arguments_BDK_NIC_PF_QSX_SQX_CFG2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_QSX_SQX_CFG2(...) "NIC_PF_QSX_SQX_CFG2"


/**
 * NCB - nic_pf_qs#_sq#_stat#
 *
 * The third dimension indicates which statistic, and is enumerated by NIC_STAT_SQ_E.
 *
 */
typedef union bdk_nic_pf_qsx_sqx_statx {
	uint64_t u;
	struct bdk_nic_pf_qsx_sqx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< R/W/H - Statistic value. See also NIC_QS()_SQ()_STAT() for a read-only alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_pf_qsx_sqx_statx_s  cn88xx; */
	/* struct bdk_nic_pf_qsx_sqx_statx_s  cn88xxp1; */
} bdk_nic_pf_qsx_sqx_statx_t;

static inline uint64_t BDK_NIC_PF_QSX_SQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_QSX_SQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 127)) && ((param2 <= 7)) && ((param3 <= 1)))
		return 0x0000843020010D00ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_QSX_SQX_STATX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_NIC_PF_QSX_SQX_STATX(...) bdk_nic_pf_qsx_sqx_statx_t
#define bustype_BDK_NIC_PF_QSX_SQX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_QSX_SQX_STATX(p1,p2,p3) (p1)
#define arguments_BDK_NIC_PF_QSX_SQX_STATX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_NIC_PF_QSX_SQX_STATX(...) "NIC_PF_QSX_SQX_STATX"


/**
 * NCB - nic_pf_rbdr_bp_state#
 */
typedef union bdk_nic_pf_rbdr_bp_statex {
	uint64_t u;
	struct bdk_nic_pf_rbdr_bp_statex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t bp_state                    : 64; /**< RO/H - Current state of the RBDR_BP signals (before BP_SW and BP_DIS masks are applied). */
#else
		uint64_t bp_state                    : 64;
#endif
	} s;
	/* struct bdk_nic_pf_rbdr_bp_statex_s cn88xx; */
	/* struct bdk_nic_pf_rbdr_bp_statex_s cn88xxp1; */
} bdk_nic_pf_rbdr_bp_statex_t;

static inline uint64_t BDK_NIC_PF_RBDR_BP_STATEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RBDR_BP_STATEX(unsigned long param1)
{
	if (((param1 <= 3)))
		return 0x0000843000000240ull + (param1 & 3) * 0x8ull;
	csr_fatal("BDK_NIC_PF_RBDR_BP_STATEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RBDR_BP_STATEX(...) bdk_nic_pf_rbdr_bp_statex_t
#define bustype_BDK_NIC_PF_RBDR_BP_STATEX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RBDR_BP_STATEX(p1) (p1)
#define arguments_BDK_NIC_PF_RBDR_BP_STATEX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_RBDR_BP_STATEX(...) "NIC_PF_RBDR_BP_STATEX"


/**
 * NCB - nic_pf_rqm_test
 */
typedef union bdk_nic_pf_rqm_test {
	uint64_t u;
	struct bdk_nic_pf_rqm_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = RQM_DROP_INTR_STALL.
                                                                 \<61\> = REB1_CQ_STALL.
                                                                 \<60\> = REB0_CQ_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_rqm_test_s       cn88xx; */
	/* struct bdk_nic_pf_rqm_test_s       cn88xxp1; */
} bdk_nic_pf_rqm_test_t;

#define BDK_NIC_PF_RQM_TEST BDK_NIC_PF_RQM_TEST_FUNC()
static inline uint64_t BDK_NIC_PF_RQM_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RQM_TEST_FUNC(void)
{
	return 0x0000843000000098ull;
}
#define typedef_BDK_NIC_PF_RQM_TEST bdk_nic_pf_rqm_test_t
#define bustype_BDK_NIC_PF_RQM_TEST BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RQM_TEST 0
#define arguments_BDK_NIC_PF_RQM_TEST -1,-1,-1,-1
#define basename_BDK_NIC_PF_RQM_TEST "NIC_PF_RQM_TEST"


/**
 * NCB - nic_pf_rrm_avg_cfg
 */
typedef union bdk_nic_pf_rrm_avg_cfg {
	uint64_t u;
	struct bdk_nic_pf_rrm_avg_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_21_63              : 43;
		uint64_t avg_en                      : 1;  /**< R/W - QoS averaging enable. When set, compute average buffer levels. When clear, do not compute
                                                                 averages and save a few mW of power. */
		uint64_t lvl_dly                     : 6;  /**< R/W - Levelizer delay. Number of cycles between level computations for backpressure and RED.
                                                                 Increasing values decrease power. Zero disables, one indicates a level computation every
                                                                 other cycle, etc. Once set to nonzero must not be later set to zero without resetting NIC. */
		uint64_t avg_dly                     : 14; /**< R/W - Average-queue-size delay. The number of levelizer-clock cycles to wait (1024 *
                                                                 ([AVG_DLY]+1) * ([LVL_DLY]+1)) coprocessor clocks) between calculating the moving averages
                                                                 for each RQ. Note the minimum value of 2048 cycles implies that at 50 M packets/sec, and a
                                                                 coprocessor clock of 800 MHz, approximately 120 packets may arrive between average
                                                                 calculations.

                                                                 Larger [LVL_DLY] values cause the backpressure indications and moving averages of all aura
                                                                 levels to track changes in the actual free space more slowly. Larger AVG_DLY also causes
                                                                 the moving averages of all levels to track changes in the actual free space more slowly,
                                                                 but does not affect backpressure. Larger NIC_QS()_CQ()_CFG[AVG_CON] or
                                                                 NIC_QS()_RBDR()_CFG[AVG_CON]) values causes a specific aura to track more
                                                                 slowly, but only affects an individual aura level, rather than all. */
#else
		uint64_t avg_dly                     : 14;
		uint64_t lvl_dly                     : 6;
		uint64_t avg_en                      : 1;
		uint64_t reserved_21_63              : 43;
#endif
	} s;
	/* struct bdk_nic_pf_rrm_avg_cfg_s    cn88xx; */
	/* struct bdk_nic_pf_rrm_avg_cfg_s    cn88xxp1; */
} bdk_nic_pf_rrm_avg_cfg_t;

#define BDK_NIC_PF_RRM_AVG_CFG BDK_NIC_PF_RRM_AVG_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_RRM_AVG_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RRM_AVG_CFG_FUNC(void)
{
	return 0x00008430000000C8ull;
}
#define typedef_BDK_NIC_PF_RRM_AVG_CFG bdk_nic_pf_rrm_avg_cfg_t
#define bustype_BDK_NIC_PF_RRM_AVG_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RRM_AVG_CFG 0
#define arguments_BDK_NIC_PF_RRM_AVG_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_RRM_AVG_CFG "NIC_PF_RRM_AVG_CFG"


/**
 * NCB - nic_pf_rrm_cfg
 */
typedef union bdk_nic_pf_rrm_cfg {
	uint64_t u;
	struct bdk_nic_pf_rrm_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t drop_level                  : 19; /**< R/W - Drop level. The minimum FIFO level before all packets for the RBDR are dropped.  This
                                                                 value can be increased to insure that once a packet has been "accepted", it will not get
                                                                 truncated due to buffer exhaustion. */
#else
		uint64_t drop_level                  : 19;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_nic_pf_rrm_cfg_s        cn88xx; */
	/* struct bdk_nic_pf_rrm_cfg_s        cn88xxp1; */
} bdk_nic_pf_rrm_cfg_t;

#define BDK_NIC_PF_RRM_CFG BDK_NIC_PF_RRM_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_RRM_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RRM_CFG_FUNC(void)
{
	return 0x0000843000000088ull;
}
#define typedef_BDK_NIC_PF_RRM_CFG bdk_nic_pf_rrm_cfg_t
#define bustype_BDK_NIC_PF_RRM_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RRM_CFG 0
#define arguments_BDK_NIC_PF_RRM_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_RRM_CFG "NIC_PF_RRM_CFG"


/**
 * NCB - nic_pf_rrm_test
 */
typedef union bdk_nic_pf_rrm_test {
	uint64_t u;
	struct bdk_nic_pf_rrm_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = RRM_NCB_REQ_STALL.
                                                                 \<61\> = RRM_NCB_RSP_STALL.
                                                                 \<60\> = RRM_INTR_FIFO. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_rrm_test_s       cn88xx; */
	/* struct bdk_nic_pf_rrm_test_s       cn88xxp1; */
} bdk_nic_pf_rrm_test_t;

#define BDK_NIC_PF_RRM_TEST BDK_NIC_PF_RRM_TEST_FUNC()
static inline uint64_t BDK_NIC_PF_RRM_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RRM_TEST_FUNC(void)
{
	return 0x0000843000000090ull;
}
#define typedef_BDK_NIC_PF_RRM_TEST bdk_nic_pf_rrm_test_t
#define bustype_BDK_NIC_PF_RRM_TEST BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RRM_TEST 0
#define arguments_BDK_NIC_PF_RRM_TEST -1,-1,-1,-1
#define basename_BDK_NIC_PF_RRM_TEST "NIC_PF_RRM_TEST"


/**
 * NCB - nic_pf_rssi#_rq
 *
 * The RSSI table is used to distribute RSS hashes to compute which RQ receives a packet.
 *
 */
typedef union bdk_nic_pf_rssix_rq {
	uint64_t u;
	struct bdk_nic_pf_rssix_rq_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t rq_qs                       : 7;  /**< R/W - RQ's QS. */
		uint64_t rq_idx                      : 3;  /**< R/W - RQ within [RQ_QS]. */
#else
		uint64_t rq_idx                      : 3;
		uint64_t rq_qs                       : 7;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_nic_pf_rssix_rq_s       cn88xx; */
	/* struct bdk_nic_pf_rssix_rq_s       cn88xxp1; */
} bdk_nic_pf_rssix_rq_t;

static inline uint64_t BDK_NIC_PF_RSSIX_RQ(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RSSIX_RQ(unsigned long param1)
{
	if (((param1 <= 4095)))
		return 0x0000843000220000ull + (param1 & 4095) * 0x8ull;
	csr_fatal("BDK_NIC_PF_RSSIX_RQ", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RSSIX_RQ(...) bdk_nic_pf_rssix_rq_t
#define bustype_BDK_NIC_PF_RSSIX_RQ(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RSSIX_RQ(p1) (p1)
#define arguments_BDK_NIC_PF_RSSIX_RQ(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_RSSIX_RQ(...) "NIC_PF_RSSIX_RQ"


/**
 * NCB - nic_pf_rx_etype#
 */
typedef union bdk_nic_pf_rx_etypex {
	uint64_t u;
	struct bdk_nic_pf_rx_etypex_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t advance                     : 3;  /**< R/W - Number of 16-bit words (note: not bytes) to advance parse by, excluding the etype word,
                                                                 when the Ethertype is matched. */
		uint64_t alg                         : 3;  /**< R/W - Ethertype action, enumerated by NIC_ETYPE_ALG_E. If non-zero, enables matching against
                                                                 this Ethertype watcher, and the action to be taken on a match. */
		uint64_t etype                       : 16; /**< R/W - Ethertype to match this rule against if [ALG] is non-zero. If multiple registers have
                                                                 [ALG] non-zero and have the same [ETYPE], all fields in this register must have identical
                                                                 values or the results are undefined. Some of the standard Ethertypes are enumerated by
                                                                 NIC_ETHERTYPE_E. */
#else
		uint64_t etype                       : 16;
		uint64_t alg                         : 3;
		uint64_t advance                     : 3;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_nic_pf_rx_etypex_s      cn88xx; */
	/* struct bdk_nic_pf_rx_etypex_s      cn88xxp1; */
} bdk_nic_pf_rx_etypex_t;

static inline uint64_t BDK_NIC_PF_RX_ETYPEX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RX_ETYPEX(unsigned long param1)
{
	if (((param1 <= 7)))
		return 0x0000843000000500ull + (param1 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_PF_RX_ETYPEX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RX_ETYPEX(...) bdk_nic_pf_rx_etypex_t
#define bustype_BDK_NIC_PF_RX_ETYPEX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RX_ETYPEX(p1) (p1)
#define arguments_BDK_NIC_PF_RX_ETYPEX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_RX_ETYPEX(...) "NIC_PF_RX_ETYPEX"


/**
 * NCB - nic_pf_rx_geneve_def
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_rx_geneve_def {
	uint64_t u;
	struct bdk_nic_pf_rx_geneve_def_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t ena                         : 1;  /**< R/W - Enables the parsing of GENEVE headers. */
		uint64_t udp_port_num                : 16; /**< R/W - UDP destination port number that indicates a GENEVE header. */
#else
		uint64_t udp_port_num                : 16;
		uint64_t ena                         : 1;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_nic_pf_rx_geneve_def_s  cn88xx; */
} bdk_nic_pf_rx_geneve_def_t;

#define BDK_NIC_PF_RX_GENEVE_DEF BDK_NIC_PF_RX_GENEVE_DEF_FUNC()
static inline uint64_t BDK_NIC_PF_RX_GENEVE_DEF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RX_GENEVE_DEF_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000000580ull;
	else 		csr_fatal("BDK_NIC_PF_RX_GENEVE_DEF", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RX_GENEVE_DEF bdk_nic_pf_rx_geneve_def_t
#define bustype_BDK_NIC_PF_RX_GENEVE_DEF BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RX_GENEVE_DEF 0
#define arguments_BDK_NIC_PF_RX_GENEVE_DEF -1,-1,-1,-1
#define basename_BDK_NIC_PF_RX_GENEVE_DEF "NIC_PF_RX_GENEVE_DEF"


/**
 * NCB - nic_pf_rx_gre_def
 *
 * INTERNAL: Added in pass 2.
 *
 */
typedef union bdk_nic_pf_rx_gre_def {
	uint64_t u;
	struct bdk_nic_pf_rx_gre_def_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t gre1_ena                    : 1;  /**< R/W - Enable detection of GRE version 1 headers for tunneling. */
		uint64_t gre0_ena                    : 1;  /**< R/W - Enable detection of GRE version 0 headers tunneling (non-NVGRE). */
		uint64_t nvgre_ena                   : 1;  /**< R/W - Enable detection of NVGRE headers for tunneling. */
		uint64_t nvgre_port_num              : 16; /**< R/W - Port number for NVGRE headers; used to distinguish between a generic GRE version
                                                                 0 header and a NVGRE header. */
#else
		uint64_t nvgre_port_num              : 16;
		uint64_t nvgre_ena                   : 1;
		uint64_t gre0_ena                    : 1;
		uint64_t gre1_ena                    : 1;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_nic_pf_rx_gre_def_s     cn88xx; */
} bdk_nic_pf_rx_gre_def_t;

#define BDK_NIC_PF_RX_GRE_DEF BDK_NIC_PF_RX_GRE_DEF_FUNC()
static inline uint64_t BDK_NIC_PF_RX_GRE_DEF_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RX_GRE_DEF_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000000590ull;
	else 		csr_fatal("BDK_NIC_PF_RX_GRE_DEF", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RX_GRE_DEF bdk_nic_pf_rx_gre_def_t
#define bustype_BDK_NIC_PF_RX_GRE_DEF BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RX_GRE_DEF 0
#define arguments_BDK_NIC_PF_RX_GRE_DEF -1,-1,-1,-1
#define basename_BDK_NIC_PF_RX_GRE_DEF "NIC_PF_RX_GRE_DEF"


/**
 * NCB - nic_pf_rx_vxlan_def#
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_rx_vxlan_defx {
	uint64_t u;
	struct bdk_nic_pf_rx_vxlan_defx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_17_63              : 47;
		uint64_t ena                         : 1;  /**< R/W - Enables the detection of VXLAN headers. */
		uint64_t udp_port_num                : 16; /**< R/W - UDP destination port number that indicates a VXLAN header. */
#else
		uint64_t udp_port_num                : 16;
		uint64_t ena                         : 1;
		uint64_t reserved_17_63              : 47;
#endif
	} s;
	/* struct bdk_nic_pf_rx_vxlan_defx_s  cn88xx; */
} bdk_nic_pf_rx_vxlan_defx_t;

static inline uint64_t BDK_NIC_PF_RX_VXLAN_DEFX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_RX_VXLAN_DEFX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 1)))
		return 0x00008430000005A0ull + (param1 & 1) * 0x8ull;
	else 		csr_fatal("BDK_NIC_PF_RX_VXLAN_DEFX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_RX_VXLAN_DEFX(...) bdk_nic_pf_rx_vxlan_defx_t
#define bustype_BDK_NIC_PF_RX_VXLAN_DEFX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_RX_VXLAN_DEFX(p1) (p1)
#define arguments_BDK_NIC_PF_RX_VXLAN_DEFX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_RX_VXLAN_DEFX(...) "NIC_PF_RX_VXLAN_DEFX"


/**
 * NCB - nic_pf_seb_test
 */
typedef union bdk_nic_pf_seb_test {
	uint64_t u;
	struct bdk_nic_pf_seb_test_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = SEB_INTERFACE_1_STALL.
                                                                 \<61\> = SEB_INTERFACE_0_STALL.
                                                                 \<60\> = SEB_FIFO_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_seb_test_s       cn88xx; */
	/* struct bdk_nic_pf_seb_test_s       cn88xxp1; */
} bdk_nic_pf_seb_test_t;

#define BDK_NIC_PF_SEB_TEST BDK_NIC_PF_SEB_TEST_FUNC()
static inline uint64_t BDK_NIC_PF_SEB_TEST_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SEB_TEST_FUNC(void)
{
	return 0x00008430000000E0ull;
}
#define typedef_BDK_NIC_PF_SEB_TEST bdk_nic_pf_seb_test_t
#define bustype_BDK_NIC_PF_SEB_TEST BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SEB_TEST 0
#define arguments_BDK_NIC_PF_SEB_TEST -1,-1,-1,-1
#define basename_BDK_NIC_PF_SEB_TEST "NIC_PF_SEB_TEST"


/**
 * NCB - nic_pf_soft_reset
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_soft_reset {
	uint64_t u;
	struct bdk_nic_pf_soft_reset_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t reset                       : 1;  /**< WO - Write 1 to reset the NIC block. Software must ensure the following before writing 1:
                                                                 * NIC_PF_CFG[ENA] = 1.
                                                                 * All NIC queues (CQ, SQ, RQ, RDBR) are idle.
                                                                 * Transmit FIFOs are empty, i.e. NIC_PF_INTF()_TX_FIFO_STATUS[COUNT] = 0.
                                                                 * TNS send and receive interfaces are quiesced.
                                                                 * NIC has no outstanding interrupts.

                                                                 Note that this operation resets all NIC registers, including MSI-X registers
                                                                 (NIC_PF_MSIX_*, NIC_VF()_MSIX_*) and PCC config space registers (PCCBR_NIC_*, PCCPF_NIC_*,
                                                                 PCCVF_NIC_*). */
#else
		uint64_t reset                       : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_soft_reset_s     cn88xx; */
} bdk_nic_pf_soft_reset_t;

#define BDK_NIC_PF_SOFT_RESET BDK_NIC_PF_SOFT_RESET_FUNC()
static inline uint64_t BDK_NIC_PF_SOFT_RESET_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SOFT_RESET_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000000050ull;
	else 		csr_fatal("BDK_NIC_PF_SOFT_RESET", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_SOFT_RESET bdk_nic_pf_soft_reset_t
#define bustype_BDK_NIC_PF_SOFT_RESET BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SOFT_RESET 0
#define arguments_BDK_NIC_PF_SOFT_RESET -1,-1,-1,-1
#define basename_BDK_NIC_PF_SOFT_RESET "NIC_PF_SOFT_RESET"


/**
 * NCB - nic_pf_sqm_test1
 */
typedef union bdk_nic_pf_sqm_test1 {
	uint64_t u;
	struct bdk_nic_pf_sqm_test1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = SQ_VNIC_STAT_STALL.
                                                                 \<61\> = SQ_DOOR_STALL.
                                                                 \<60\> = SQ_INT_SET_FIFO_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_sqm_test1_s      cn88xx; */
	/* struct bdk_nic_pf_sqm_test1_s      cn88xxp1; */
} bdk_nic_pf_sqm_test1_t;

#define BDK_NIC_PF_SQM_TEST1 BDK_NIC_PF_SQM_TEST1_FUNC()
static inline uint64_t BDK_NIC_PF_SQM_TEST1_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SQM_TEST1_FUNC(void)
{
	return 0x0000843000000100ull;
}
#define typedef_BDK_NIC_PF_SQM_TEST1 bdk_nic_pf_sqm_test1_t
#define bustype_BDK_NIC_PF_SQM_TEST1 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SQM_TEST1 0
#define arguments_BDK_NIC_PF_SQM_TEST1 -1,-1,-1,-1
#define basename_BDK_NIC_PF_SQM_TEST1 "NIC_PF_SQM_TEST1"


/**
 * NCB - nic_pf_sqm_test2
 */
typedef union bdk_nic_pf_sqm_test2 {
	uint64_t u;
	struct bdk_nic_pf_sqm_test2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t enable                      : 4;  /**< R/W - Enable test mode. For diagnostic use only.
                                                                 INTERNAL: Once this bit is set, random backpressure is generate to
                                                                 and internal FIFO path to the allow more frequent backpressure.
                                                                 \<63\> = Reserved.
                                                                 \<62\> = MQM_SEND_CMD_STALL.
                                                                 \<61\> = MQM_SCH_REQ_STALL.
                                                                 \<60\> = MQM_MDQ_UPDATE_STALL. */
		uint64_t reserved_24_59              : 36;
		uint64_t bp_cfg                      : 8;  /**< R/W - Enable NIC block random backpressure. For diagnostic use only.
                                                                 INTERNAL:
                                                                   There are 2 BP_CFG bits per enable.  The definition is
                                                                   0=100% of the time, 1=25% of the time, 2=50% of the time, 3=75% of the time.
                                                                   \<23:22\> = BP_CFG3.
                                                                   \<21:20\> = BP_CFG2.
                                                                   \<19:18\> = BP_CFG1.
                                                                   \<17:16\> = BP_CFG0. */
		uint64_t reserved_12_15              : 4;
		uint64_t lfsr_freq                   : 12; /**< R/W - Test LFSR update frequency in coprocessor-clocks minus one. */
#else
		uint64_t lfsr_freq                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t bp_cfg                      : 8;
		uint64_t reserved_24_59              : 36;
		uint64_t enable                      : 4;
#endif
	} s;
	/* struct bdk_nic_pf_sqm_test2_s      cn88xx; */
	/* struct bdk_nic_pf_sqm_test2_s      cn88xxp1; */
} bdk_nic_pf_sqm_test2_t;

#define BDK_NIC_PF_SQM_TEST2 BDK_NIC_PF_SQM_TEST2_FUNC()
static inline uint64_t BDK_NIC_PF_SQM_TEST2_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SQM_TEST2_FUNC(void)
{
	return 0x0000843000000108ull;
}
#define typedef_BDK_NIC_PF_SQM_TEST2 bdk_nic_pf_sqm_test2_t
#define bustype_BDK_NIC_PF_SQM_TEST2 BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SQM_TEST2 0
#define arguments_BDK_NIC_PF_SQM_TEST2 -1,-1,-1,-1
#define basename_BDK_NIC_PF_SQM_TEST2 "NIC_PF_SQM_TEST2"


/**
 * NCB - nic_pf_status
 */
typedef union bdk_nic_pf_status {
	uint64_t u;
	struct bdk_nic_pf_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_10_63              : 54;
		uint64_t blk_busy                    : 10; /**< RO/H - If non-zero, block is not ready for configuration. INTERNAL: Each bit corresponds to a
                                                                 subblock:
                                                                 \<9\> = Reserved.
                                                                 \<8\> = Reserved.
                                                                 \<7\> = nic_sqm.
                                                                 \<6\> = nic_sps.
                                                                 \<5\> = nic_seb.
                                                                 \<4\> = nic_rrm.
                                                                 \<3\> = nic_rqm.
                                                                 \<2\> = nic_reb.
                                                                 \<1\> = nic_csi.
                                                                 \<0\> = nic_cqm. */
#else
		uint64_t blk_busy                    : 10;
		uint64_t reserved_10_63              : 54;
#endif
	} s;
	/* struct bdk_nic_pf_status_s         cn88xx; */
	/* struct bdk_nic_pf_status_s         cn88xxp1; */
} bdk_nic_pf_status_t;

#define BDK_NIC_PF_STATUS BDK_NIC_PF_STATUS_FUNC()
static inline uint64_t BDK_NIC_PF_STATUS_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_STATUS_FUNC(void)
{
	return 0x0000843000000010ull;
}
#define typedef_BDK_NIC_PF_STATUS bdk_nic_pf_status_t
#define bustype_BDK_NIC_PF_STATUS BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_STATUS 0
#define arguments_BDK_NIC_PF_STATUS -1,-1,-1,-1
#define basename_BDK_NIC_PF_STATUS "NIC_PF_STATUS"


/**
 * NCB - nic_pf_sw_sync_rx
 */
typedef union bdk_nic_pf_sw_sync_rx {
	uint64_t u;
	struct bdk_nic_pf_sw_sync_rx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t sw_rx_sync                  : 1;  /**< R/W - Software sets this bit to kick off a sync cycle on the RX path. This sync insures that all
                                                                 packets that were in flight are flushed out to memory. This can be used to assist in the
                                                                 tearing down of an active RQ. */
#else
		uint64_t sw_rx_sync                  : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_sw_sync_rx_s     cn88xx; */
	/* struct bdk_nic_pf_sw_sync_rx_s     cn88xxp1; */
} bdk_nic_pf_sw_sync_rx_t;

#define BDK_NIC_PF_SW_SYNC_RX BDK_NIC_PF_SW_SYNC_RX_FUNC()
static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_FUNC(void)
{
	return 0x0000843000490000ull;
}
#define typedef_BDK_NIC_PF_SW_SYNC_RX bdk_nic_pf_sw_sync_rx_t
#define bustype_BDK_NIC_PF_SW_SYNC_RX BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SW_SYNC_RX 0
#define arguments_BDK_NIC_PF_SW_SYNC_RX -1,-1,-1,-1
#define basename_BDK_NIC_PF_SW_SYNC_RX "NIC_PF_SW_SYNC_RX"


/**
 * NCB - nic_pf_sw_sync_rx_cnts#
 *
 * For diagnostic use only for debug of the SW_SYNC function.
 * The first dimension indicates which the counter values, and is enumerated by
 * NIC_SW_SYNC_RX_CNTS_E.
 * Changed in pass 2: increased number of counters from 4 to 16.
 */
typedef union bdk_nic_pf_sw_sync_rx_cntsx {
	uint64_t u;
	struct bdk_nic_pf_sw_sync_rx_cntsx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t out_cnt                     : 32; /**< RO/H - Running count at output of machine. */
		uint64_t in_cnt                      : 32; /**< RO/H - Running count at input of machine. */
#else
		uint64_t in_cnt                      : 32;
		uint64_t out_cnt                     : 32;
#endif
	} s;
	/* struct bdk_nic_pf_sw_sync_rx_cntsx_s cn88xx; */
	/* struct bdk_nic_pf_sw_sync_rx_cntsx_s cn88xxp1; */
} bdk_nic_pf_sw_sync_rx_cntsx_t;

static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_CNTSX(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_CNTSX(unsigned long param1)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && ((param1 <= 3)))
		return 0x0000843000490200ull + (param1 & 3) * 0x8ull;
	else if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X) && ((param1 <= 15)))
		return 0x0000843000490200ull + (param1 & 15) * 0x8ull;
	else 		csr_fatal("BDK_NIC_PF_SW_SYNC_RX_CNTSX", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_SW_SYNC_RX_CNTSX(...) bdk_nic_pf_sw_sync_rx_cntsx_t
#define bustype_BDK_NIC_PF_SW_SYNC_RX_CNTSX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SW_SYNC_RX_CNTSX(p1) (p1)
#define arguments_BDK_NIC_PF_SW_SYNC_RX_CNTSX(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_SW_SYNC_RX_CNTSX(...) "NIC_PF_SW_SYNC_RX_CNTSX"


/**
 * NCB - nic_pf_sw_sync_rx_done
 */
typedef union bdk_nic_pf_sw_sync_rx_done {
	uint64_t u;
	struct bdk_nic_pf_sw_sync_rx_done_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t sw_rx_sync_done             : 1;  /**< RO/H - Set when NIC_PF_SW_SYNC_RX[SW_RX_SYNC] is set and all packets that were in flight before
                                                                 the sync has been flushed out to memory. */
#else
		uint64_t sw_rx_sync_done             : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_sw_sync_rx_done_s cn88xx; */
	/* struct bdk_nic_pf_sw_sync_rx_done_s cn88xxp1; */
} bdk_nic_pf_sw_sync_rx_done_t;

#define BDK_NIC_PF_SW_SYNC_RX_DONE BDK_NIC_PF_SW_SYNC_RX_DONE_FUNC()
static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_DONE_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_SW_SYNC_RX_DONE_FUNC(void)
{
	return 0x0000843000490008ull;
}
#define typedef_BDK_NIC_PF_SW_SYNC_RX_DONE bdk_nic_pf_sw_sync_rx_done_t
#define bustype_BDK_NIC_PF_SW_SYNC_RX_DONE BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_SW_SYNC_RX_DONE 0
#define arguments_BDK_NIC_PF_SW_SYNC_RX_DONE -1,-1,-1,-1
#define basename_BDK_NIC_PF_SW_SYNC_RX_DONE "NIC_PF_SW_SYNC_RX_DONE"


/**
 * NCB - nic_pf_tcp_timer
 */
typedef union bdk_nic_pf_tcp_timer {
	uint64_t u;
	struct bdk_nic_pf_tcp_timer_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t ena                         : 1;  /**< R/W - TCP timer enable. When clear, [VF_COUNTER] and [DUR_COUNTER] are forced to 0 and timer
                                                                 events will not be posted. */
		uint64_t reserved_48_62              : 15;
		uint64_t duration                    : 16; /**< R/W - Duration of the TCP timer as a multiple of 256 coprocessor-clock cycles. */
		uint64_t reserved_23_31              : 9;
		uint64_t vf_counter                  : 7;  /**< RO/H - Periodic counter that increments by one whenever [DUR_COUNTER] wraps around. Enabled when
                                                                 [ENA] is set. */
		uint64_t dur_counter                 : 16; /**< RO/H - Periodic counter that wraps around every [DURATION]*256 coprocessor-clock cycles. Enabled
                                                                 when [ENA] is set. */
#else
		uint64_t dur_counter                 : 16;
		uint64_t vf_counter                  : 7;
		uint64_t reserved_23_31              : 9;
		uint64_t duration                    : 16;
		uint64_t reserved_48_62              : 15;
		uint64_t ena                         : 1;
#endif
	} s;
	/* struct bdk_nic_pf_tcp_timer_s      cn88xx; */
	/* struct bdk_nic_pf_tcp_timer_s      cn88xxp1; */
} bdk_nic_pf_tcp_timer_t;

#define BDK_NIC_PF_TCP_TIMER BDK_NIC_PF_TCP_TIMER_FUNC()
static inline uint64_t BDK_NIC_PF_TCP_TIMER_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TCP_TIMER_FUNC(void)
{
	return 0x0000843000000060ull;
}
#define typedef_BDK_NIC_PF_TCP_TIMER bdk_nic_pf_tcp_timer_t
#define bustype_BDK_NIC_PF_TCP_TIMER BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TCP_TIMER 0
#define arguments_BDK_NIC_PF_TCP_TIMER -1,-1,-1,-1
#define basename_BDK_NIC_PF_TCP_TIMER "NIC_PF_TCP_TIMER"


/**
 * NCB - nic_pf_tl2#_cfg
 */
typedef union bdk_nic_pf_tl2x_cfg {
	uint64_t u;
	struct bdk_nic_pf_tl2x_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t rr_quantum                  : 24; /**< R/W - Round-robin (DWRR) quantum. The weighted deficit round-robin quantum (24-bit unsigned
                                                                 integer). Specifies the amount of data to transmit in an arbitration round as a multiple
                                                                 of 4 bytes. Must be non-zero when this transmit limiter is used. Typical value for
                                                                 equal-weight arbitration is MTU/4 + NIC_PF_LMAC()_CFG[ADJUST]. */
#else
		uint64_t rr_quantum                  : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_pf_tl2x_cfg_s       cn88xx; */
	/* struct bdk_nic_pf_tl2x_cfg_s       cn88xxp1; */
} bdk_nic_pf_tl2x_cfg_t;

static inline uint64_t BDK_NIC_PF_TL2X_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL2X_CFG(unsigned long param1)
{
	if (((param1 <= 63)))
		return 0x0000843000500000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL2X_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL2X_CFG(...) bdk_nic_pf_tl2x_cfg_t
#define bustype_BDK_NIC_PF_TL2X_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL2X_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_TL2X_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL2X_CFG(...) "NIC_PF_TL2X_CFG"


/**
 * NCB - nic_pf_tl2#_pri
 */
typedef union bdk_nic_pf_tl2x_pri {
	uint64_t u;
	struct bdk_nic_pf_tl2x_pri_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_4_63               : 60;
		uint64_t rr_pri                      : 4;  /**< R/W - Round-robin priority. Zero is highest priority; values 10 and above are reserved. */
#else
		uint64_t rr_pri                      : 4;
		uint64_t reserved_4_63               : 60;
#endif
	} s;
	/* struct bdk_nic_pf_tl2x_pri_s       cn88xx; */
	/* struct bdk_nic_pf_tl2x_pri_s       cn88xxp1; */
} bdk_nic_pf_tl2x_pri_t;

static inline uint64_t BDK_NIC_PF_TL2X_PRI(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL2X_PRI(unsigned long param1)
{
	if (((param1 <= 63)))
		return 0x0000843000520000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL2X_PRI", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL2X_PRI(...) bdk_nic_pf_tl2x_pri_t
#define bustype_BDK_NIC_PF_TL2X_PRI(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL2X_PRI(p1) (p1)
#define arguments_BDK_NIC_PF_TL2X_PRI(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL2X_PRI(...) "NIC_PF_TL2X_PRI"


/**
 * NCB - nic_pf_tl2#_sh_status
 */
typedef union bdk_nic_pf_tl2x_sh_status {
	uint64_t u;
	struct bdk_nic_pf_tl2x_sh_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t rr_count                    : 25; /**< R/W/H - Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else
		uint64_t rr_count                    : 25;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_nic_pf_tl2x_sh_status_s cn88xx; */
	/* struct bdk_nic_pf_tl2x_sh_status_s cn88xxp1; */
} bdk_nic_pf_tl2x_sh_status_t;

static inline uint64_t BDK_NIC_PF_TL2X_SH_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL2X_SH_STATUS(unsigned long param1)
{
	if (((param1 <= 63)))
		return 0x0000843000580000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL2X_SH_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL2X_SH_STATUS(...) bdk_nic_pf_tl2x_sh_status_t
#define bustype_BDK_NIC_PF_TL2X_SH_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL2X_SH_STATUS(p1) (p1)
#define arguments_BDK_NIC_PF_TL2X_SH_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL2X_SH_STATUS(...) "NIC_PF_TL2X_SH_STATUS"


/**
 * NCB - nic_pf_tl3#_cfg
 */
typedef union bdk_nic_pf_tl3x_cfg {
	uint64_t u;
	struct bdk_nic_pf_tl3x_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t rr_quantum                  : 24; /**< R/W - Round-robin (DWRR) quantum. The weighted deficit round-robin quantum (24-bit unsigned
                                                                 integer). Specifies the amount of data to transmit in an arbitration round as a multiple
                                                                 of 4 bytes. Must be non-zero when this transmit limiter is used. Typical value for
                                                                 equal-weight arbitration is MTU/4 + NIC_PF_LMAC()_CFG[ADJUST]. */
#else
		uint64_t rr_quantum                  : 24;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_pf_tl3x_cfg_s       cn88xx; */
	/* struct bdk_nic_pf_tl3x_cfg_s       cn88xxp1; */
} bdk_nic_pf_tl3x_cfg_t;

static inline uint64_t BDK_NIC_PF_TL3X_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL3X_CFG(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000600000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL3X_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL3X_CFG(...) bdk_nic_pf_tl3x_cfg_t
#define bustype_BDK_NIC_PF_TL3X_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL3X_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_TL3X_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL3X_CFG(...) "NIC_PF_TL3X_CFG"


/**
 * NCB - nic_pf_tl3#_chan
 */
typedef union bdk_nic_pf_tl3x_chan {
	uint64_t u;
	struct bdk_nic_pf_tl3x_chan_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t chan                        : 7;  /**< R/W - The channel sending backpressure to this TL3. The corresponding
                                                                 NIC_PF_CHAN()_TX_CFG[TL3] must point back to this channel. */
#else
		uint64_t chan                        : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_nic_pf_tl3x_chan_s      cn88xx; */
	/* struct bdk_nic_pf_tl3x_chan_s      cn88xxp1; */
} bdk_nic_pf_tl3x_chan_t;

static inline uint64_t BDK_NIC_PF_TL3X_CHAN(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL3X_CHAN(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000620000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL3X_CHAN", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL3X_CHAN(...) bdk_nic_pf_tl3x_chan_t
#define bustype_BDK_NIC_PF_TL3X_CHAN(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL3X_CHAN(p1) (p1)
#define arguments_BDK_NIC_PF_TL3X_CHAN(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL3X_CHAN(...) "NIC_PF_TL3X_CHAN"


/**
 * NCB - nic_pf_tl3#_sh_status
 */
typedef union bdk_nic_pf_tl3x_sh_status {
	uint64_t u;
	struct bdk_nic_pf_tl3x_sh_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_63_63              : 1;
		uint64_t pir_count                   : 12; /**< R/W/H - Reserved. */
		uint64_t pir_accum                   : 26; /**< R/W/H - Reserved. */
		uint64_t rr_count                    : 25; /**< R/W/H - Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else
		uint64_t rr_count                    : 25;
		uint64_t pir_accum                   : 26;
		uint64_t pir_count                   : 12;
		uint64_t reserved_63_63              : 1;
#endif
	} s;
	struct bdk_nic_pf_tl3x_sh_status_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t rr_count                    : 25; /**< R/W/H - Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else
		uint64_t rr_count                    : 25;
		uint64_t reserved_25_63              : 39;
#endif
	} cn88xx;
	/* struct bdk_nic_pf_tl3x_sh_status_s cn88xxp1; */
} bdk_nic_pf_tl3x_sh_status_t;

static inline uint64_t BDK_NIC_PF_TL3X_SH_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL3X_SH_STATUS(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x00008430006A0000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL3X_SH_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL3X_SH_STATUS(...) bdk_nic_pf_tl3x_sh_status_t
#define bustype_BDK_NIC_PF_TL3X_SH_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL3X_SH_STATUS(p1) (p1)
#define arguments_BDK_NIC_PF_TL3X_SH_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL3X_SH_STATUS(...) "NIC_PF_TL3X_SH_STATUS"


/**
 * NCB - nic_pf_tl3#_sw_xoff
 */
typedef union bdk_nic_pf_tl3x_sw_xoff {
	uint64_t u;
	struct bdk_nic_pf_tl3x_sw_xoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ch_xoff                     : 1;  /**< RO/H - Channel XOFF. When set, this TL3 does not send traffic due to channel SW_XOFF, channel
                                                                 backpressure, channel credits, LMAC SW_XOFF, or LMAC backpressure. */
		uint64_t sw_xoff                     : 1;  /**< R/W - Software XOFF. When set, this TL3 does not send traffic. */
#else
		uint64_t sw_xoff                     : 1;
		uint64_t ch_xoff                     : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_nic_pf_tl3x_sw_xoff_s   cn88xx; */
	/* struct bdk_nic_pf_tl3x_sw_xoff_s   cn88xxp1; */
} bdk_nic_pf_tl3x_sw_xoff_t;

static inline uint64_t BDK_NIC_PF_TL3X_SW_XOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL3X_SW_XOFF(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x0000843000660000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL3X_SW_XOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL3X_SW_XOFF(...) bdk_nic_pf_tl3x_sw_xoff_t
#define bustype_BDK_NIC_PF_TL3X_SW_XOFF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL3X_SW_XOFF(p1) (p1)
#define arguments_BDK_NIC_PF_TL3X_SW_XOFF(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL3X_SW_XOFF(...) "NIC_PF_TL3X_SW_XOFF"


/**
 * NCB - nic_pf_tl3a#_cfg
 */
typedef union bdk_nic_pf_tl3ax_cfg {
	uint64_t u;
	struct bdk_nic_pf_tl3ax_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_5_63               : 59;
		uint64_t tl3a                        : 5;  /**< R/W - TL3 aggregation group. Index of TL2 that pulls from this TL3 group (TL3G), i.e. lowest
                                                                 numbered TL3G in this aggregation group. If this TL3G is not part of an aggregation group,
                                                                 TL3A must match the TL3G number (the index of this register). Resets to equal the index of
                                                                 this register. TL3A\<5\> is the same as TL3G\<5\>, and so is not stored here. */
#else
		uint64_t tl3a                        : 5;
		uint64_t reserved_5_63               : 59;
#endif
	} s;
	/* struct bdk_nic_pf_tl3ax_cfg_s      cn88xx; */
	/* struct bdk_nic_pf_tl3ax_cfg_s      cn88xxp1; */
} bdk_nic_pf_tl3ax_cfg_t;

static inline uint64_t BDK_NIC_PF_TL3AX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL3AX_CFG(unsigned long param1)
{
	if (((param1 <= 63)))
		return 0x00008430005F0000ull + (param1 & 63) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL3AX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL3AX_CFG(...) bdk_nic_pf_tl3ax_cfg_t
#define bustype_BDK_NIC_PF_TL3AX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL3AX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_TL3AX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL3AX_CFG(...) "NIC_PF_TL3AX_CFG"


/**
 * NCB - nic_pf_tl4#_cfg
 */
typedef union bdk_nic_pf_tl4x_cfg {
	uint64_t u;
	struct bdk_nic_pf_tl4x_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_34_63              : 30;
		uint64_t sq_qs                       : 7;  /**< R/W - The SQ's QS that are associated with this TL4. */
		uint64_t sq_idx                      : 3;  /**< R/W - The SQ's index inside the QS which is associated with this TL4. */
		uint64_t rr_quantum                  : 24; /**< R/W - Round-robin (DWRR) quantum. The weighted deficit round-robin quantum (24-bit unsigned
                                                                 integer). Specifies the amount of data to transmit in an arbitration round as a multiple
                                                                 of 4 bytes. Must be non-zero when this transmit limiter is used. Typical value for
                                                                 equal-weight arbitration is MTU/4 + NIC_PF_LMAC()_CFG[ADJUST]. */
#else
		uint64_t rr_quantum                  : 24;
		uint64_t sq_idx                      : 3;
		uint64_t sq_qs                       : 7;
		uint64_t reserved_34_63              : 30;
#endif
	} s;
	/* struct bdk_nic_pf_tl4x_cfg_s       cn88xx; */
	/* struct bdk_nic_pf_tl4x_cfg_s       cn88xxp1; */
} bdk_nic_pf_tl4x_cfg_t;

static inline uint64_t BDK_NIC_PF_TL4X_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL4X_CFG(unsigned long param1)
{
	if (((param1 <= 1023)))
		return 0x0000843000800000ull + (param1 & 1023) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL4X_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL4X_CFG(...) bdk_nic_pf_tl4x_cfg_t
#define bustype_BDK_NIC_PF_TL4X_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL4X_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_TL4X_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL4X_CFG(...) "NIC_PF_TL4X_CFG"


/**
 * NCB - nic_pf_tl4#_sh_status
 */
typedef union bdk_nic_pf_tl4x_sh_status {
	uint64_t u;
	struct bdk_nic_pf_tl4x_sh_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t rr_count                    : 25; /**< R/W/H - Round-robin (DWRR) deficit counter. A 25-bit signed integer count. For diagnostic use. */
#else
		uint64_t rr_count                    : 25;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_nic_pf_tl4x_sh_status_s cn88xx; */
	/* struct bdk_nic_pf_tl4x_sh_status_s cn88xxp1; */
} bdk_nic_pf_tl4x_sh_status_t;

static inline uint64_t BDK_NIC_PF_TL4X_SH_STATUS(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL4X_SH_STATUS(unsigned long param1)
{
	if (((param1 <= 1023)))
		return 0x0000843000840000ull + (param1 & 1023) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL4X_SH_STATUS", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL4X_SH_STATUS(...) bdk_nic_pf_tl4x_sh_status_t
#define bustype_BDK_NIC_PF_TL4X_SH_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL4X_SH_STATUS(p1) (p1)
#define arguments_BDK_NIC_PF_TL4X_SH_STATUS(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL4X_SH_STATUS(...) "NIC_PF_TL4X_SH_STATUS"


/**
 * NCB - nic_pf_tl4#_sw_xoff
 */
typedef union bdk_nic_pf_tl4x_sw_xoff {
	uint64_t u;
	struct bdk_nic_pf_tl4x_sw_xoff_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t sw_xoff                     : 1;  /**< R/W - Software XOFF. When set, this TL4 does not send traffic. */
#else
		uint64_t sw_xoff                     : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_pf_tl4x_sw_xoff_s   cn88xx; */
	/* struct bdk_nic_pf_tl4x_sw_xoff_s   cn88xxp1; */
} bdk_nic_pf_tl4x_sw_xoff_t;

static inline uint64_t BDK_NIC_PF_TL4X_SW_XOFF(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL4X_SW_XOFF(unsigned long param1)
{
	if (((param1 <= 1023)))
		return 0x0000843000820000ull + (param1 & 1023) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL4X_SW_XOFF", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL4X_SW_XOFF(...) bdk_nic_pf_tl4x_sw_xoff_t
#define bustype_BDK_NIC_PF_TL4X_SW_XOFF(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL4X_SW_XOFF(p1) (p1)
#define arguments_BDK_NIC_PF_TL4X_SW_XOFF(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL4X_SW_XOFF(...) "NIC_PF_TL4X_SW_XOFF"


/**
 * NCB - nic_pf_tl4a#_cfg
 */
typedef union bdk_nic_pf_tl4ax_cfg {
	uint64_t u;
	struct bdk_nic_pf_tl4ax_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_7_63               : 57;
		uint64_t tl4a                        : 7;  /**< R/W - TL4 aggregation group. Index of TL3 that pulls from this TL4 group (TL4G), i.e. lowest
                                                                 numbered TL4G in this aggregation group. If this TL4G is not part of an aggregation group,
                                                                 TL4A must match the TL4G number (the index of this register). Resets to equal the index of
                                                                 this register. TL4A\<7\> is the same as TL4G\<7\>, and so is not stored here. */
#else
		uint64_t tl4a                        : 7;
		uint64_t reserved_7_63               : 57;
#endif
	} s;
	/* struct bdk_nic_pf_tl4ax_cfg_s      cn88xx; */
	/* struct bdk_nic_pf_tl4ax_cfg_s      cn88xxp1; */
} bdk_nic_pf_tl4ax_cfg_t;

static inline uint64_t BDK_NIC_PF_TL4AX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TL4AX_CFG(unsigned long param1)
{
	if (((param1 <= 255)))
		return 0x00008430006F0000ull + (param1 & 255) * 0x8ull;
	csr_fatal("BDK_NIC_PF_TL4AX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TL4AX_CFG(...) bdk_nic_pf_tl4ax_cfg_t
#define bustype_BDK_NIC_PF_TL4AX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TL4AX_CFG(p1) (p1)
#define arguments_BDK_NIC_PF_TL4AX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_PF_TL4AX_CFG(...) "NIC_PF_TL4AX_CFG"


/**
 * NCB - nic_pf_tso_cfg
 *
 * Added in pass 2.
 *
 */
typedef union bdk_nic_pf_tso_cfg {
	uint64_t u;
	struct bdk_nic_pf_tso_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_44_63              : 20;
		uint64_t fsf                         : 12; /**< R/W - Modify the TCP header flags for the first TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [FSF]. */
		uint64_t reserved_28_31              : 4;
		uint64_t msf                         : 12; /**< R/W - Modify the TCP header flags for the middle TSO segmented packets by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [MSF]. */
		uint64_t reserved_12_15              : 4;
		uint64_t lsf                         : 12; /**< R/W - Modify the TCP header flags for the last TSO segmented packet by logical AND
                                                                 with this configuration.

                                                                 _ FLAGS_new = (FLAGS_original) AND [LSF]. */
#else
		uint64_t lsf                         : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t msf                         : 12;
		uint64_t reserved_28_31              : 4;
		uint64_t fsf                         : 12;
		uint64_t reserved_44_63              : 20;
#endif
	} s;
	/* struct bdk_nic_pf_tso_cfg_s        cn88xx; */
} bdk_nic_pf_tso_cfg_t;

#define BDK_NIC_PF_TSO_CFG BDK_NIC_PF_TSO_CFG_FUNC()
static inline uint64_t BDK_NIC_PF_TSO_CFG_FUNC(void) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_TSO_CFG_FUNC(void)
{
	if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS2_X))
		return 0x0000843000000070ull;
	else 		csr_fatal("BDK_NIC_PF_TSO_CFG", 0, 0, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_TSO_CFG bdk_nic_pf_tso_cfg_t
#define bustype_BDK_NIC_PF_TSO_CFG BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_TSO_CFG 0
#define arguments_BDK_NIC_PF_TSO_CFG -1,-1,-1,-1
#define basename_BDK_NIC_PF_TSO_CFG "NIC_PF_TSO_CFG"


/**
 * NCB - nic_pf_vf#_mbox#
 */
typedef union bdk_nic_pf_vfx_mboxx {
	uint64_t u;
	struct bdk_nic_pf_vfx_mboxx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W/H - Mailbox data. These PF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. Each corresponding VF may access the same storage using
                                                                 NIC_VF()_PF_MBOX(). MBOX(0) is typically used for PF to VF signaling, MBOX(1)
                                                                 for VF to PF. Writing NIC_PF_VF(0..127)_MBOX(0) (but not
                                                                 NIC_VF(0..127)_PF_MBOX(0)) will set the corresponding NIC_VF()_INT[MBOX] which
                                                                 if appropriately enabled will send an interrupt to the VF. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_nic_pf_vfx_mboxx_s      cn88xx; */
	/* struct bdk_nic_pf_vfx_mboxx_s      cn88xxp1; */
} bdk_nic_pf_vfx_mboxx_t;

static inline uint64_t BDK_NIC_PF_VFX_MBOXX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_VFX_MBOXX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x0000843020002030ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_PF_VFX_MBOXX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_VFX_MBOXX(...) bdk_nic_pf_vfx_mboxx_t
#define bustype_BDK_NIC_PF_VFX_MBOXX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_VFX_MBOXX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_VFX_MBOXX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_VFX_MBOXX(...) "NIC_PF_VFX_MBOXX"


/**
 * NCB - nic_pf_vnic#_rx_stat#
 *
 * The second dimension indicates which statistic, and is enumerated by NIC_STAT_VNIC_RX_E.
 *
 */
typedef union bdk_nic_pf_vnicx_rx_statx {
	uint64_t u;
	struct bdk_nic_pf_vnicx_rx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< R/W/H - Statistic value. See also NIC_VNIC()_RX_STAT() for a read-only alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_pf_vnicx_rx_statx_s cn88xx; */
	/* struct bdk_nic_pf_vnicx_rx_statx_s cn88xxp1; */
} bdk_nic_pf_vnicx_rx_statx_t;

static inline uint64_t BDK_NIC_PF_VNICX_RX_STATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_VNICX_RX_STATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 13)))
		return 0x0000843020004100ull + (param1 & 127) * 0x200000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_NIC_PF_VNICX_RX_STATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_VNICX_RX_STATX(...) bdk_nic_pf_vnicx_rx_statx_t
#define bustype_BDK_NIC_PF_VNICX_RX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_VNICX_RX_STATX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_VNICX_RX_STATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_VNICX_RX_STATX(...) "NIC_PF_VNICX_RX_STATX"


/**
 * NCB - nic_pf_vnic#_tx_stat#
 *
 * The second dimension indicates which statistic, and is enumerated by NIC_STAT_VNIC_TX_E.
 *
 */
typedef union bdk_nic_pf_vnicx_tx_statx {
	uint64_t u;
	struct bdk_nic_pf_vnicx_tx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< R/W/H - Statistic value. See also NIC_VNIC()_TX_STAT() for a read-only alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_pf_vnicx_tx_statx_s cn88xx; */
	/* struct bdk_nic_pf_vnicx_tx_statx_s cn88xxp1; */
} bdk_nic_pf_vnicx_tx_statx_t;

static inline uint64_t BDK_NIC_PF_VNICX_TX_STATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_PF_VNICX_TX_STATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 4)))
		return 0x0000843020004000ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_PF_VNICX_TX_STATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_PF_VNICX_TX_STATX(...) bdk_nic_pf_vnicx_tx_statx_t
#define bustype_BDK_NIC_PF_VNICX_TX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_PF_VNICX_TX_STATX(p1,p2) (p1)
#define arguments_BDK_NIC_PF_VNICX_TX_STATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_PF_VNICX_TX_STATX(...) "NIC_PF_VNICX_TX_STATX"


/**
 * NCB - nic_qs#_cq#_base
 */
typedef union bdk_nic_qsx_cqx_base {
	uint64_t u;
	struct bdk_nic_qsx_cqx_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t base_addr                   : 40; /**< R/W - Base byte address \<48:9\> of CQ ring in DRAM (VA, IPA or PA depending on SMMU
                                                                 configuration). Address bits \<8:0\> are always 0. Writes are ignored when the CQ ring is
                                                                 enabled, i.e. NIC_QS()_CQ()_CFG[ENA]==1. */
		uint64_t reserved_0_8                : 9;
#else
		uint64_t reserved_0_8                : 9;
		uint64_t base_addr                   : 40;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_base_s      cn88xx; */
	/* struct bdk_nic_qsx_cqx_base_s      cn88xxp1; */
} bdk_nic_qsx_cqx_base_t;

static inline uint64_t BDK_NIC_QSX_CQX_BASE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_BASE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010420ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_BASE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_BASE(...) bdk_nic_qsx_cqx_base_t
#define bustype_BDK_NIC_QSX_CQX_BASE(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_BASE(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_BASE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_BASE(...) "NIC_QSX_CQX_BASE"


/**
 * NCB - nic_qs#_cq#_cfg
 *
 * Writes to all fields except for [ENA] are ignored when the CQ ring is enabled, i.e. [ENA]==1.
 *
 */
typedef union bdk_nic_qsx_cqx_cfg {
	uint64_t u;
	struct bdk_nic_qsx_cqx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_43_63              : 21;
		uint64_t ena                         : 1;  /**< R/W/H - Enable CQ. Writing a 1 to this bit enables the CQ. Writing a 0 gracefully disables the CQ.
                                                                 Software can poll this bit for a 0 to determine if all hardware processing for this CQ has
                                                                 stopped. */
		uint64_t reset                       : 1;  /**< WO - CQ Reset. Writing a 1 resets all the NIC_QS(0..127)_CQ(0..7)_* registers and internal
                                                                 state for this CQ with the exception of NIC_QS()_CQ()_CFG2. */
		uint64_t caching                     : 1;  /**< R/W - Select the style of write to the L2C.
                                                                 0 = writes of CQE data will not allocate into the L2C.
                                                                 1 = writes of CQE data are allocated into the L2C. */
		uint64_t reserved_35_39              : 5;
		uint64_t qsize                       : 3;  /**< R/W - Specifies CQ ring size in entries of 512 bytes:
                                                                 0x0 = 1K entries.
                                                                 0x1 = 2K entries.
                                                                 0x2 = 4K entries.
                                                                 0x3 = 8K entries.
                                                                 0x4 = 16K entries.
                                                                 0x5 = 32K entries.
                                                                 0x6 = 64K entries.
                                                                 0x7 = Reserved.

                                                                 Note that the usable size of the ring is the specified size minus 1 (HEAD==TAIL always
                                                                 means empty). */
		uint64_t reserved_25_31              : 7;
		uint64_t avg_con                     : 9;  /**< R/W - This value controls how much of each present average resource level is used to calculate
                                                                 the new resource level. The value is a number from 0 to 256, which represents AVG_CON/256
                                                                 of the average resource level that will be used in the calculation:

                                                                 next_LEVEL = (AVG_CON/256) * prev_LEVEL + (1-(AVG_CON/256)) * count

                                                                 Note setting this value to zero will disable averaging, and always use the most immediate
                                                                 levels. NIC_PF_CQ_AVG_CFG[AVG_EN] must be set and NIC_PF_CQ_AVG_CFG[LVL_DLY] must be
                                                                 nonzero to globally enable averaging. NIC_PF_CQ_AVG_CFG[AVG_DLY] controls the periodicity
                                                                 of the level calculations. */
		uint64_t reserved_0_15               : 16;
#else
		uint64_t reserved_0_15               : 16;
		uint64_t avg_con                     : 9;
		uint64_t reserved_25_31              : 7;
		uint64_t qsize                       : 3;
		uint64_t reserved_35_39              : 5;
		uint64_t caching                     : 1;
		uint64_t reset                       : 1;
		uint64_t ena                         : 1;
		uint64_t reserved_43_63              : 21;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_cfg_s       cn88xx; */
	/* struct bdk_nic_qsx_cqx_cfg_s       cn88xxp1; */
} bdk_nic_qsx_cqx_cfg_t;

static inline uint64_t BDK_NIC_QSX_CQX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010400ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_CFG(...) bdk_nic_qsx_cqx_cfg_t
#define bustype_BDK_NIC_QSX_CQX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_CFG(...) "NIC_QSX_CQX_CFG"


/**
 * NCB - nic_qs#_cq#_cfg2
 */
typedef union bdk_nic_qsx_cqx_cfg2 {
	uint64_t u;
	struct bdk_nic_qsx_cqx_cfg2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t int_timer_thr               : 8;  /**< R/W - CQ interrupt timer threshold. Zero disables the interrupt timer
                                                                 This is not reset by NIC_QS()_CQ()_CFG[RESET].
                                                                 It is up to software write zero to this field to disable the interrupt timer before
                                                                 reseting the CQ. */
#else
		uint64_t int_timer_thr               : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_cfg2_s      cn88xx; */
	/* struct bdk_nic_qsx_cqx_cfg2_s      cn88xxp1; */
} bdk_nic_qsx_cqx_cfg2_t;

static inline uint64_t BDK_NIC_QSX_CQX_CFG2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_CFG2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010408ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_CFG2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_CFG2(...) bdk_nic_qsx_cqx_cfg2_t
#define bustype_BDK_NIC_QSX_CQX_CFG2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_CFG2(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_CFG2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_CFG2(...) "NIC_QSX_CQX_CFG2"


/**
 * NCB - nic_qs#_cq#_debug
 */
typedef union bdk_nic_qsx_cqx_debug {
	uint64_t u;
	struct bdk_nic_qsx_cqx_debug_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t tail_ptr                    : 16; /**< R/W/H - CQ-engine pointer. Initialized to NIC_QS()_CQ()_TAIL[TAIL_PTR] when software
                                                                 writes that register. Advanced by hardware as completion messages are allocated. For
                                                                 diagnostic use only. Writes are ignored when NIC_PF_CFG[TEST_MODE] is clear. */
#else
		uint64_t tail_ptr                    : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_debug_s     cn88xx; */
	/* struct bdk_nic_qsx_cqx_debug_s     cn88xxp1; */
} bdk_nic_qsx_cqx_debug_t;

static inline uint64_t BDK_NIC_QSX_CQX_DEBUG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_DEBUG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010450ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_DEBUG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_DEBUG(...) bdk_nic_qsx_cqx_debug_t
#define bustype_BDK_NIC_QSX_CQX_DEBUG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_DEBUG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_DEBUG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_DEBUG(...) "NIC_QSX_CQX_DEBUG"


/**
 * NCB - nic_qs#_cq#_door
 *
 * Software writes to this register to notify hardware that one or more entries have been
 * dequeued from the CQ ring.
 */
typedef union bdk_nic_qsx_cqx_door {
	uint64_t u;
	struct bdk_nic_qsx_cqx_door_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< WO - Number of dequeued entries of 512 bytes. Hardware advances NIC_QS()_CQ()_TAIL[HEAD_PTR] by
                                                                 this value if the CQ is enabled. A write that would underflow the CQ (i.e. cause the CQ
                                                                 head pointer to pass the tail pointer) is suppressed and sets
                                                                 NIC_QS()_CQ()_STATUS[CQ_WR_FULL]. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_door_s      cn88xx; */
	/* struct bdk_nic_qsx_cqx_door_s      cn88xxp1; */
} bdk_nic_qsx_cqx_door_t;

static inline uint64_t BDK_NIC_QSX_CQX_DOOR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_DOOR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010438ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_DOOR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_DOOR(...) bdk_nic_qsx_cqx_door_t
#define bustype_BDK_NIC_QSX_CQX_DOOR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_DOOR(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_DOOR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_DOOR(...) "NIC_QSX_CQX_DOOR"


/**
 * NCB - nic_qs#_cq#_head
 */
typedef union bdk_nic_qsx_cqx_head {
	uint64_t u;
	struct bdk_nic_qsx_cqx_head_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t head_ptr                    : 16; /**< R/W/H - Head pointer \<24:9\> of CQ ring relative to NIC_QS()_CQ()_BASE. Address bits
                                                                 \<8:0\> are always 0. This register is automatically updated when software writes to
                                                                 NIC_QS()_CQ()_DOOR. Writes are ignored when NIC_PF_CFG[TEST_MODE] is clear. */
		uint64_t reserved_0_8                : 9;
#else
		uint64_t reserved_0_8                : 9;
		uint64_t head_ptr                    : 16;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_head_s      cn88xx; */
	/* struct bdk_nic_qsx_cqx_head_s      cn88xxp1; */
} bdk_nic_qsx_cqx_head_t;

static inline uint64_t BDK_NIC_QSX_CQX_HEAD(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_HEAD(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010428ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_HEAD", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_HEAD(...) bdk_nic_qsx_cqx_head_t
#define bustype_BDK_NIC_QSX_CQX_HEAD(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_HEAD(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_HEAD(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_HEAD(...) "NIC_QSX_CQX_HEAD"


/**
 * NCB - nic_qs#_cq#_status
 */
typedef union bdk_nic_qsx_cqx_status {
	uint64_t u;
	struct bdk_nic_qsx_cqx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t cq_wr_full                  : 1;  /**< RO/H - NIC has detected an error on this CQ. Write to CQ when full. The CQ is stopped when this
                                                                 bit is set; all receive packets for this CQ are discarded, but send packets for this CQ
                                                                 may continue transmission although no NIC_CQE_SEND_Ss will be created for them. In order
                                                                 to restart the CQ, software must first reset it by writing a 1 to
                                                                 NIC_QS()_CQ()_CFG[RESET], then reconfigure and re-enable the CQ. */
		uint64_t cq_wr_disable               : 1;  /**< RO/H - NIC has detected an error on this CQ. Write to CQ when disable. The CQ is stopped when
                                                                 this
                                                                 bit is set; all receive packets for this CQ are discarded, but send packets for this CQ
                                                                 may continue transmission although no NIC_CQE_SEND_Ss will be created for them. In order
                                                                 to restart the CQ, software must first reset it by writing a 1 to
                                                                 NIC_QS()_CQ()_CFG[RESET], then reconfigure and re-enable the CQ. */
		uint64_t cq_wr_fault                 : 1;  /**< RO/H - NIC has detected an error on this CQ. Fault on CQ write response. The CQ is stopped when
                                                                 this
                                                                 bit is set; all receive packets for this CQ are discarded, but send packets for this CQ
                                                                 may continue transmission although no NIC_CQE_SEND_Ss will be created for them. In order
                                                                 to restart the CQ, software must first reset it by writing a 1 to
                                                                 NIC_QS()_CQ()_CFG[RESET], then reconfigure and re-enable the CQ. */
		uint64_t avg                         : 8;  /**< RO/H - Time averaged queue level for RED, 0x0 indicates full, in units of /256ths of queue size. */
		uint64_t qcount                      : 16; /**< RO/H - Number of valid entries in the CQ. Computed by hardware from
                                                                 NIC_QS()_CQ()_CFG[QSIZE], NIC_QS()_CQ()_TAIL[TAIL_PTR] and
                                                                 NIC_QS()_CQ()_HEAD[HEAD_PTR]. */
#else
		uint64_t qcount                      : 16;
		uint64_t avg                         : 8;
		uint64_t cq_wr_fault                 : 1;
		uint64_t cq_wr_disable               : 1;
		uint64_t cq_wr_full                  : 1;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_status_s    cn88xx; */
	/* struct bdk_nic_qsx_cqx_status_s    cn88xxp1; */
} bdk_nic_qsx_cqx_status_t;

static inline uint64_t BDK_NIC_QSX_CQX_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010440ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_STATUS(...) bdk_nic_qsx_cqx_status_t
#define bustype_BDK_NIC_QSX_CQX_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_STATUS(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_STATUS(...) "NIC_QSX_CQX_STATUS"


/**
 * NCB - nic_qs#_cq#_status2
 */
typedef union bdk_nic_qsx_cqx_status2 {
	uint64_t u;
	struct bdk_nic_qsx_cqx_status2_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t timer_en                    : 1;  /**< RO/H - Interrupt-timer enable for this CQ. This is set when:
                                                                 NIC_QS()_CQ()_STATUS[QCOUNT] is not 0 and
                                                                 NIC_QS()_CQ()_CFG2[INT_TIMER_THR] is not 0. */
		uint64_t reserved_28_30              : 3;
		uint64_t global_time                 : 12; /**< RO/H - Global time. A free-running timer that increments on each interrupt timer tick as
                                                                 configured by NIC_PF_INT_TIMER_CFG[CLK_PER_INT_TICK]. Wraps around at maximum value. Not a
                                                                 per CQ counter, just provided here for reference. */
		uint64_t reserved_12_15              : 4;
		uint64_t int_timer                   : 12; /**< RO/H - CQ interrupt timer.
                                                                 Hardware sets [INT_TIMER] to the threshold value GLOBAL_TIME +
                                                                 NIC_QS()_CQ()_CFG2[INT_TIMER_THR] whenever one of the following occurs:
                                                                 * [TIMER_EN] goes from 0 to 1.
                                                                 * [GLOBAL_TIME] crosses [INT_TIMER] and [TIMER_EN] is 1.
                                                                 * NIC_VF()_INT[CQ] for this CQ is written with a 1 to clear and [TIMER_EN] is 1.
                                                                 * NIC_QS()_CQ()_CFG2 register is written and [TIMER_EN] is 1. */
#else
		uint64_t int_timer                   : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t global_time                 : 12;
		uint64_t reserved_28_30              : 3;
		uint64_t timer_en                    : 1;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_status2_s   cn88xx; */
	/* struct bdk_nic_qsx_cqx_status2_s   cn88xxp1; */
} bdk_nic_qsx_cqx_status2_t;

static inline uint64_t BDK_NIC_QSX_CQX_STATUS2(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_STATUS2(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010448ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_STATUS2", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_STATUS2(...) bdk_nic_qsx_cqx_status2_t
#define bustype_BDK_NIC_QSX_CQX_STATUS2(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_STATUS2(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_STATUS2(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_STATUS2(...) "NIC_QSX_CQX_STATUS2"


/**
 * NCB - nic_qs#_cq#_tail
 */
typedef union bdk_nic_qsx_cqx_tail {
	uint64_t u;
	struct bdk_nic_qsx_cqx_tail_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_25_63              : 39;
		uint64_t tail_ptr                    : 16; /**< R/W/H - Tail pointer \<24:9\> of CQ ring relative to NIC_QS()_CQ()_BASE. Address bits
                                                                 \<8:0\> are always 0. Hardware updates this register to notify software that one or more
                                                                 entries have been enqueued to the CQ ring. Writes are ignored when NIC_PF_CFG[TEST_MODE]
                                                                 is clear. */
		uint64_t reserved_0_8                : 9;
#else
		uint64_t reserved_0_8                : 9;
		uint64_t tail_ptr                    : 16;
		uint64_t reserved_25_63              : 39;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_tail_s      cn88xx; */
	/* struct bdk_nic_qsx_cqx_tail_s      cn88xxp1; */
} bdk_nic_qsx_cqx_tail_t;

static inline uint64_t BDK_NIC_QSX_CQX_TAIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_TAIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010430ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_TAIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_TAIL(...) bdk_nic_qsx_cqx_tail_t
#define bustype_BDK_NIC_QSX_CQX_TAIL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_TAIL(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_TAIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_TAIL(...) "NIC_QSX_CQX_TAIL"


/**
 * NCB - nic_qs#_cq#_thresh
 */
typedef union bdk_nic_qsx_cqx_thresh {
	uint64_t u;
	struct bdk_nic_qsx_cqx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t thresh                      : 16; /**< R/W - Queue-count threshold for CQ interrupt. When non-zero, the associated
                                                                 NIC_VF()_INT[CQ] interrupt bit is set when NIC_QS()_CQ()_STATUS[QCOUNT]
                                                                 crosses [THRESH], provided [THRESH] is non-zero. */
#else
		uint64_t thresh                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_qsx_cqx_thresh_s    cn88xx; */
	/* struct bdk_nic_qsx_cqx_thresh_s    cn88xxp1; */
} bdk_nic_qsx_cqx_thresh_t;

static inline uint64_t BDK_NIC_QSX_CQX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_CQX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010410ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_CQX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_CQX_THRESH(...) bdk_nic_qsx_cqx_thresh_t
#define bustype_BDK_NIC_QSX_CQX_THRESH(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_CQX_THRESH(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_CQX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_CQX_THRESH(...) "NIC_QSX_CQX_THRESH"


/**
 * NCB - nic_qs#_rbdr#_base
 */
typedef union bdk_nic_qsx_rbdrx_base {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t base_addr                   : 42; /**< R/W - Base byte address \<48:7\> of RBDR in DRAM (VA, IPA or PA depending on VNIC
                                                                 configuration). Address bits \<6:0\> are always 0. Writes are ignored when the RBDR is
                                                                 active, i.e.:
                                                                 * NIC_QS()_RBDR()_CFG[ENA]==1, or
                                                                 * NIC_QS()_RBDR()_HEAD[HEAD_PTR]!=NIC_QS()_RBDR()_TAIL[TAIL_PTR] */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t base_addr                   : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_base_s    cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_base_s    cn88xxp1; */
} bdk_nic_qsx_rbdrx_base_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_BASE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_BASE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C20ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_BASE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_BASE(...) bdk_nic_qsx_rbdrx_base_t
#define bustype_BDK_NIC_QSX_RBDRX_BASE(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_BASE(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_BASE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_BASE(...) "NIC_QSX_RBDRX_BASE"


/**
 * NCB - nic_qs#_rbdr#_cfg
 *
 * Writes to all fields except [ENA] and [RESET] are ignored when the RBDR is active, i.e.:
 * * [ENA]==1, or
 * * NIC_QS()_RBDR()_HEAD[HEAD_PTR]!=NIC_QS()_RBDR()_TAIL[TAIL_PTR]
 * Furthermore, writes to [RESET] are ignored when [ENA]==1.
 */
typedef union bdk_nic_qsx_rbdrx_cfg {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_45_63              : 19;
		uint64_t ena                         : 1;  /**< R/W - Enable RBDR. */
		uint64_t reset                       : 1;  /**< R/W - RBDR Reset. Writing a 1 resets all the NIC_QS(0..127)_RBDR(0..1)_* registers and internal
                                                                 state for this RBDR. Cleared by hardware when reset is complete. */
		uint64_t ldwb                        : 1;  /**< R/W - When reading RBDR entry cache lines, use LDWB transactions to invalidate the cache line. */
		uint64_t reserved_36_41              : 6;
		uint64_t qsize                       : 4;  /**< R/W - Specifies RBDR size in entries of 8 bytes, as follows:
                                                                 0x0 = 8K entries.
                                                                 0x1 = 16K entries.
                                                                 0x2 = 32K entries.
                                                                 0x3 = 64K entries.
                                                                 0x4 = 128K entries.
                                                                 0x5 = 256K entries.
                                                                 0x6 = 512K entries.
                                                                 else = Reserved.

                                                                 Note that the usable size of the ring is the specified size minus 1 (HEAD==TAIL always
                                                                 means empty). */
		uint64_t reserved_25_31              : 7;
		uint64_t avg_con                     : 9;  /**< R/W - This value controls how much of each present average resource level is used to calculate
                                                                 the new resource level. The value is a number from 0 to 256, which represents AVG_CON/256
                                                                 of the average resource level that will be used in the calculation:

                                                                 next_LEVEL = (AVG_CON/256) * prev_LEVEL + (1-(AVG_CON/256)) * count

                                                                 Note setting this value to zero will disable averaging, and always use the most immediate
                                                                 levels. NIC_PF_RRM_AVG_CFG[AVG_EN] must be set and NIC_PF_RRM_AVG_CFG[LVL_DLY] must be
                                                                 nonzero to globally enable averaging. NIC_PF_RRM_AVG_CFG[AVG_DLY] controls the periodicity
                                                                 of the level calculations. */
		uint64_t reserved_12_15              : 4;
		uint64_t lines                       : 12; /**< R/W - Size of buffers linked to this ring in 128-byte cache lines. */
#else
		uint64_t lines                       : 12;
		uint64_t reserved_12_15              : 4;
		uint64_t avg_con                     : 9;
		uint64_t reserved_25_31              : 7;
		uint64_t qsize                       : 4;
		uint64_t reserved_36_41              : 6;
		uint64_t ldwb                        : 1;
		uint64_t reset                       : 1;
		uint64_t ena                         : 1;
		uint64_t reserved_45_63              : 19;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_cfg_s     cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_cfg_s     cn88xxp1; */
} bdk_nic_qsx_rbdrx_cfg_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C00ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_CFG(...) bdk_nic_qsx_rbdrx_cfg_t
#define bustype_BDK_NIC_QSX_RBDRX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_CFG(...) "NIC_QSX_RBDRX_CFG"


/**
 * NCB - nic_qs#_rbdr#_door
 *
 * Software writes to this register to notify hardware that one or more entries have been
 * enqueued to the RBDR.
 */
typedef union bdk_nic_qsx_rbdrx_door {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_door_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t count                       : 19; /**< WO - Number of enqueued entries of 8 bytes. Hardware advances NIC_QS()_RBDR()_TAIL[TAIL_PTR] by
                                                                 this value if the RBDR is enabled.

                                                                 The usable size of the ring is the size specified by NIC_QS()_RBDR()_CFG[QSIZE] minus 1.
                                                                 As such, a doorbell write that would make the ring go full or overflow is suppressed and
                                                                 treated as a doorbell error. Hardware stops the RBDR on a doorbell error and sets
                                                                 NIC_QS()_RBDR()_STATUS0[FIFO_STATE] = 0x3 (FAIL). */
#else
		uint64_t count                       : 19;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_door_s    cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_door_s    cn88xxp1; */
} bdk_nic_qsx_rbdrx_door_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_DOOR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_DOOR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C38ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_DOOR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_DOOR(...) bdk_nic_qsx_rbdrx_door_t
#define bustype_BDK_NIC_QSX_RBDRX_DOOR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_DOOR(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_DOOR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_DOOR(...) "NIC_QSX_RBDRX_DOOR"


/**
 * NCB - nic_qs#_rbdr#_head
 */
typedef union bdk_nic_qsx_rbdrx_head {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_head_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t head_ptr                    : 19; /**< R/W/H - Head pointer \<21:3\> of RBDR in DRAM relative to NIC_QS()_RBDR()_BASE.
                                                                 Address bits \<2:0\> are always 0. Hardware updates this to notify software that one or more
                                                                 entries have been dequeued from the RBDR. Writes are ignored when NIC_PF_CFG[TEST_MODE] is
                                                                 clear. */
		uint64_t reserved_0_2                : 3;
#else
		uint64_t reserved_0_2                : 3;
		uint64_t head_ptr                    : 19;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_head_s    cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_head_s    cn88xxp1; */
} bdk_nic_qsx_rbdrx_head_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_HEAD(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_HEAD(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C28ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_HEAD", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_HEAD(...) bdk_nic_qsx_rbdrx_head_t
#define bustype_BDK_NIC_QSX_RBDRX_HEAD(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_HEAD(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_HEAD(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_HEAD(...) "NIC_QSX_RBDRX_HEAD"


/**
 * NCB - nic_qs#_rbdr#_prefetch_status
 */
typedef union bdk_nic_qsx_rbdrx_prefetch_status {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_prefetch_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t prefetch_returned_cnt       : 32; /**< RO/H - This is the count of RBDR prefetch req cycles that have returned.
                                                                 Note, these values are freerunning values that represent all prefetched return reqeusts. */
		uint64_t prefetch_req_cnt            : 32; /**< RO/H - This is the count of RBDR prefetch req cycles that have been initiated.
                                                                 Note, these values are freerunning values that represent all prefetched return reqeusts. */
#else
		uint64_t prefetch_req_cnt            : 32;
		uint64_t prefetch_returned_cnt       : 32;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_prefetch_status_s cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_prefetch_status_s cn88xxp1; */
} bdk_nic_qsx_rbdrx_prefetch_status_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C50ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_PREFETCH_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(...) bdk_nic_qsx_rbdrx_prefetch_status_t
#define bustype_BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_PREFETCH_STATUS(...) "NIC_QSX_RBDRX_PREFETCH_STATUS"


/**
 * NCB - nic_qs#_rbdr#_status0
 */
typedef union bdk_nic_qsx_rbdrx_status0 {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_status0_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t fifo_state                  : 2;  /**< RO/H - Current state of the RBDR FIFO. 00-Inactive, 01-Active, 10-Reset, 11-FAIL. The RBDR is
                                                                 stopped  when the state is FAIL and all received packets for it are discarded. In order to
                                                                 restart the RBDR, software must first reset it by writing a 1 to
                                                                 NIC_QS()_RBDR()_CFG[RESET], then reconfigure and re-enable the RBDR. */
		uint64_t reserved_55_61              : 7;
		uint64_t fifo_level                  : 7;  /**< RO/H - Current level of the internal RBDR FIFO. */
		uint64_t reserved_43_47              : 5;
		uint64_t prefetch_head               : 19; /**< RO/H - The current HW_HEAD pointer position after it has prefetch pointers to load the internal
                                                                 pointer cache. */
		uint64_t reserved_19_23              : 5;
		uint64_t qcount                      : 19; /**< RO/H - Number of valid entries in the RBDR. Computed by hardware from
                                                                 NIC_QS()_RBDR()_CFG[QSIZE], NIC_QS()_RBDR()_TAIL[TAIL_PTR] and
                                                                 NIC_QS()_RBDR()_HEAD[HEAD_PTR]. */
#else
		uint64_t qcount                      : 19;
		uint64_t reserved_19_23              : 5;
		uint64_t prefetch_head               : 19;
		uint64_t reserved_43_47              : 5;
		uint64_t fifo_level                  : 7;
		uint64_t reserved_55_61              : 7;
		uint64_t fifo_state                  : 2;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_status0_s cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_status0_s cn88xxp1; */
} bdk_nic_qsx_rbdrx_status0_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_STATUS0(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_STATUS0(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C40ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_STATUS0", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_STATUS0(...) bdk_nic_qsx_rbdrx_status0_t
#define bustype_BDK_NIC_QSX_RBDRX_STATUS0(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_STATUS0(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_STATUS0(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_STATUS0(...) "NIC_QSX_RBDRX_STATUS0"


/**
 * NCB - nic_qs#_rbdr#_status1
 */
typedef union bdk_nic_qsx_rbdrx_status1 {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_status1_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_8_63               : 56;
		uint64_t avg                         : 8;  /**< RO/H - Time averaged queue level for RED, 0x0 indicates empty, in units of /256ths of queue size. */
#else
		uint64_t avg                         : 8;
		uint64_t reserved_8_63               : 56;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_status1_s cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_status1_s cn88xxp1; */
} bdk_nic_qsx_rbdrx_status1_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_STATUS1(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_STATUS1(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C48ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_STATUS1", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_STATUS1(...) bdk_nic_qsx_rbdrx_status1_t
#define bustype_BDK_NIC_QSX_RBDRX_STATUS1(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_STATUS1(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_STATUS1(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_STATUS1(...) "NIC_QSX_RBDRX_STATUS1"


/**
 * NCB - nic_qs#_rbdr#_tail
 */
typedef union bdk_nic_qsx_rbdrx_tail {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_tail_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t tail_ptr                    : 19; /**< R/W/H - Tail pointer \<21:3\> of RBDR in DRAM relative to NIC_QS()_RBDR()_BASE.
                                                                 Address bits \<2:0\> are always 0. Automatically updated when software writes to the
                                                                 NIC_QS()_RBDR()_DOOR register. Writes are ignored when NIC_PF_CFG[TEST_MODE] is
                                                                 clear. */
		uint64_t reserved_0_2                : 3;
#else
		uint64_t reserved_0_2                : 3;
		uint64_t tail_ptr                    : 19;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_tail_s    cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_tail_s    cn88xxp1; */
} bdk_nic_qsx_rbdrx_tail_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_TAIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_TAIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C30ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_TAIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_TAIL(...) bdk_nic_qsx_rbdrx_tail_t
#define bustype_BDK_NIC_QSX_RBDRX_TAIL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_TAIL(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_TAIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_TAIL(...) "NIC_QSX_RBDRX_TAIL"


/**
 * NCB - nic_qs#_rbdr#_thresh
 */
typedef union bdk_nic_qsx_rbdrx_thresh {
	uint64_t u;
	struct bdk_nic_qsx_rbdrx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_19_63              : 45;
		uint64_t thresh                      : 19; /**< R/W - Queue-count threshold for RBDR interrupt. When non-zero, the associated
                                                                 NIC_VF()_INT[RBDR] interrupt bit is set when
                                                                 NIC_QS()_RBDR()_STATUS0[QCOUNT] crosses [THRESH]. */
#else
		uint64_t thresh                      : 19;
		uint64_t reserved_19_63              : 45;
#endif
	} s;
	/* struct bdk_nic_qsx_rbdrx_thresh_s  cn88xx; */
	/* struct bdk_nic_qsx_rbdrx_thresh_s  cn88xxp1; */
} bdk_nic_qsx_rbdrx_thresh_t;

static inline uint64_t BDK_NIC_QSX_RBDRX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RBDRX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0010C10ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RBDRX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RBDRX_THRESH(...) bdk_nic_qsx_rbdrx_thresh_t
#define bustype_BDK_NIC_QSX_RBDRX_THRESH(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RBDRX_THRESH(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RBDRX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RBDRX_THRESH(...) "NIC_QSX_RBDRX_THRESH"


/**
 * NCB - nic_qs#_rq#_cfg
 */
typedef union bdk_nic_qsx_rqx_cfg {
	uint64_t u;
	struct bdk_nic_qsx_rqx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_2_63               : 62;
		uint64_t ena                         : 1;  /**< R/W - Enable RQ. Writing a 1 to this bit enables the RQ. Writing a 0 gracefully disables the RQ.
                                                                 Software can poll this bit for a 0 to determine if all hardware processing for this RQ has
                                                                 stopped. */
		uint64_t tcp_ena                     : 1;  /**< R/W - Reserved. INTERNAL: Reserved for future use - TCP reassembly enable. */
#else
		uint64_t tcp_ena                     : 1;
		uint64_t ena                         : 1;
		uint64_t reserved_2_63               : 62;
#endif
	} s;
	/* struct bdk_nic_qsx_rqx_cfg_s       cn88xx; */
	/* struct bdk_nic_qsx_rqx_cfg_s       cn88xxp1; */
} bdk_nic_qsx_rqx_cfg_t;

static inline uint64_t BDK_NIC_QSX_RQX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RQX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010600ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_RQX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RQX_CFG(...) bdk_nic_qsx_rqx_cfg_t
#define bustype_BDK_NIC_QSX_RQX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RQX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_RQX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_RQX_CFG(...) "NIC_QSX_RQX_CFG"


/**
 * NCB - nic_qs#_rq#_stat#
 *
 * The third dimension indicates which statistic, and is enumerated by NIC_STAT_RQ_E.
 *
 */
typedef union bdk_nic_qsx_rqx_statx {
	uint64_t u;
	struct bdk_nic_qsx_rqx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< RO/H - Statistic value. See also NIC_PF_QS()_RQ()_STAT() for a writable alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_qsx_rqx_statx_s     cn88xx; */
	/* struct bdk_nic_qsx_rqx_statx_s     cn88xxp1; */
} bdk_nic_qsx_rqx_statx_t;

static inline uint64_t BDK_NIC_QSX_RQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 127)) && ((param2 <= 7)) && ((param3 <= 1)))
		return 0x00008430A0010700ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_QSX_RQX_STATX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RQX_STATX(...) bdk_nic_qsx_rqx_statx_t
#define bustype_BDK_NIC_QSX_RQX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RQX_STATX(p1,p2,p3) (p1)
#define arguments_BDK_NIC_QSX_RQX_STATX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_NIC_QSX_RQX_STATX(...) "NIC_QSX_RQX_STATX"


/**
 * NCB - nic_qs#_rq_gen_cfg
 */
typedef union bdk_nic_qsx_rq_gen_cfg {
	uint64_t u;
	struct bdk_nic_qsx_rq_gen_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t vlan_strip                  : 2;  /**< R/W - Controls the stripping of any VLAN tags:
                                                                 0 = No strip.
                                                                 1 = Strip first VLAN if exists (NIC_CQE_RX_S[VV] set).
                                                                 2 = Strip second VLAN if exists (NIC_CQE_RX_S[VS] set).
                                                                 3 = Reserved. */
		uint64_t len_l4                      : 1;  /**< R/W - Check length of L4. */
		uint64_t len_l3                      : 1;  /**< R/W - Check length of IPv4/IPv6. */
		uint64_t csum_sctp                   : 1;  /**< R/W - Reserved. */
		uint64_t csum_l4                     : 1;  /**< R/W - Compute checksum on TCP/UDP packets. */
		uint64_t ip6_udp_opt                 : 1;  /**< R/W - IPv6/UDP checksum is optional. IPv4 allows an optional UDP checksum by sending the all-0s
                                                                 patterns. IPv6 outlaws this and the spec says to always check UDP checksum.
                                                                 0 = Spec compliant, do not allow optional code.
                                                                 1 = Treat IPv6 as IPv4; the all-0s pattern will cause a UDP checksum pass. */
		uint64_t splt_hdr_ena                : 1;  /**< R/W - When set, any packet with a valid header stack down to the end of the L4 layer has its
                                                                 header split into a separate RBDR buffer. */
		uint64_t cq_hdr_copy                 : 1;  /**< R/W - If set, the header is copied into the CQE as well as existing in the packet buffer. The
                                                                 hardware will copy all defined headers. */
		uint64_t max_tcp_reass               : 2;  /**< R/W - Reserved. INTERNAL: Reserved for future use - Maximum TCP reassembled packet:
                                                                 0x0 = 64Kbytes.
                                                                 0x1 = 256Kbytes.
                                                                 0x2-0x3 = Reserved. */
		uint64_t cq_pkt_size                 : 8;  /**< R/W - Packet size in bytes. If a packet (including the TNS_HEADER field) is smaller than this
                                                                 value, the entire packet is sent to the CQ buffer and no RB is used. Maximum number of
                                                                 bytes is 249, to allow for up to 7 byte alignment pad. */
		uint64_t later_skip                  : 4;  /**< R/W - Number of eight-byte words that are skipped at the beginning of other than the first RB
                                                                 for a packet. */
		uint64_t first_skip                  : 4;  /**< R/W - Number of eight-byte words that are skipped at the beginning of the first RB for a packet. */
#else
		uint64_t first_skip                  : 4;
		uint64_t later_skip                  : 4;
		uint64_t cq_pkt_size                 : 8;
		uint64_t max_tcp_reass               : 2;
		uint64_t cq_hdr_copy                 : 1;
		uint64_t splt_hdr_ena                : 1;
		uint64_t ip6_udp_opt                 : 1;
		uint64_t csum_l4                     : 1;
		uint64_t csum_sctp                   : 1;
		uint64_t len_l3                      : 1;
		uint64_t len_l4                      : 1;
		uint64_t vlan_strip                  : 2;
		uint64_t reserved_27_63              : 37;
#endif
	} s;
	struct bdk_nic_qsx_rq_gen_cfg_cn88xx {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_27_63              : 37;
		uint64_t vlan_strip                  : 2;  /**< R/W - Controls the stripping of any VLAN tags:
                                                                 0 = No strip.
                                                                 1 = Strip first VLAN if exists (NIC_CQE_RX_S[VV] set).
                                                                 2 = Strip second VLAN if exists (NIC_CQE_RX_S[VS] set).
                                                                 3 = Reserved. */
		uint64_t len_l4                      : 1;  /**< R/W - Check length of L4. */
		uint64_t len_l3                      : 1;  /**< R/W - Check length of IPv4/IPv6. */
		uint64_t reserved_22_22              : 1;
		uint64_t csum_l4                     : 1;  /**< R/W - Compute checksum on TCP/UDP packets. */
		uint64_t ip6_udp_opt                 : 1;  /**< R/W - IPv6/UDP checksum is optional. IPv4 allows an optional UDP checksum by sending the all-0s
                                                                 patterns. IPv6 outlaws this and the spec says to always check UDP checksum.
                                                                 0 = Spec compliant, do not allow optional code.
                                                                 1 = Treat IPv6 as IPv4; the all-0s pattern will cause a UDP checksum pass. */
		uint64_t splt_hdr_ena                : 1;  /**< R/W - When set, any packet with a valid header stack down to the end of the L4 layer has its
                                                                 header split into a separate RBDR buffer. */
		uint64_t cq_hdr_copy                 : 1;  /**< R/W - If set, the header is copied into the CQE as well as existing in the packet buffer. The
                                                                 hardware will copy all defined headers. */
		uint64_t max_tcp_reass               : 2;  /**< R/W - Reserved. INTERNAL: Reserved for future use - Maximum TCP reassembled packet:
                                                                 0x0 = 64Kbytes.
                                                                 0x1 = 256Kbytes.
                                                                 0x2-0x3 = Reserved. */
		uint64_t cq_pkt_size                 : 8;  /**< R/W - Packet size in bytes. If a packet (including the TNS_HEADER field) is smaller than this
                                                                 value, the entire packet is sent to the CQ buffer and no RB is used. Maximum number of
                                                                 bytes is 249, to allow for up to 7 byte alignment pad. */
		uint64_t later_skip                  : 4;  /**< R/W - Number of eight-byte words that are skipped at the beginning of other than the first RB
                                                                 for a packet. */
		uint64_t first_skip                  : 4;  /**< R/W - Number of eight-byte words that are skipped at the beginning of the first RB for a packet. */
#else
		uint64_t first_skip                  : 4;
		uint64_t later_skip                  : 4;
		uint64_t cq_pkt_size                 : 8;
		uint64_t max_tcp_reass               : 2;
		uint64_t cq_hdr_copy                 : 1;
		uint64_t splt_hdr_ena                : 1;
		uint64_t ip6_udp_opt                 : 1;
		uint64_t csum_l4                     : 1;
		uint64_t reserved_22_22              : 1;
		uint64_t len_l3                      : 1;
		uint64_t len_l4                      : 1;
		uint64_t vlan_strip                  : 2;
		uint64_t reserved_27_63              : 37;
#endif
	} cn88xx;
	/* struct bdk_nic_qsx_rq_gen_cfg_s    cn88xxp1; */
} bdk_nic_qsx_rq_gen_cfg_t;

static inline uint64_t BDK_NIC_QSX_RQ_GEN_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_RQ_GEN_CFG(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0010010ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_QSX_RQ_GEN_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_RQ_GEN_CFG(...) bdk_nic_qsx_rq_gen_cfg_t
#define bustype_BDK_NIC_QSX_RQ_GEN_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_RQ_GEN_CFG(p1) (p1)
#define arguments_BDK_NIC_QSX_RQ_GEN_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_QSX_RQ_GEN_CFG(...) "NIC_QSX_RQ_GEN_CFG"


/**
 * NCB - nic_qs#_sq#_base
 */
typedef union bdk_nic_qsx_sqx_base {
	uint64_t u;
	struct bdk_nic_qsx_sqx_base_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t base_addr                   : 42; /**< R/W/H - Base byte address\<48:7\> of SQ ring in DRAM (VA, IPA or PA depending on VNIC
                                                                 configuration). Address bits \<6:0\> are always 0.  Writes are ignored when the SQ ring is
                                                                 active, i.e.:
                                                                 * NIC_QS()_SQ()_HEAD[HEAD_PTR]!=NIC_QS()_SQ()_TAIL[TAIL_PTR], and
                                                                 * NIC_QS()_SQ()_STATUS[STOPPED]==0. */
		uint64_t reserved_0_6                : 7;
#else
		uint64_t reserved_0_6                : 7;
		uint64_t base_addr                   : 42;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_base_s      cn88xx; */
	/* struct bdk_nic_qsx_sqx_base_s      cn88xxp1; */
} bdk_nic_qsx_sqx_base_t;

static inline uint64_t BDK_NIC_QSX_SQX_BASE(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_BASE(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010820ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_BASE", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_BASE(...) bdk_nic_qsx_sqx_base_t
#define bustype_BDK_NIC_QSX_SQX_BASE(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_BASE(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_BASE(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_BASE(...) "NIC_QSX_SQX_BASE"


/**
 * NCB - nic_qs#_sq#_cfg
 *
 * Writes to all fields except for [ENA] are ignored when the SQ ring is active, i.e.:
 * * NIC_QS()_SQ()_HEAD[HEAD_PTR]!=NIC_QS()_SQ()_TAIL[TAIL_PTR], and
 * * NIC_QS()_SQ()_STATUS[STOPPED]==0.
 */
typedef union bdk_nic_qsx_sqx_cfg {
	uint64_t u;
	struct bdk_nic_qsx_sqx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t ena                         : 1;  /**< R/W/H - Enable SQ. Software can clear this bit at any time to disable the SQ, at which time
                                                                 hardware stops servicing the SQ and sets NIC_QS()_SQ()_STATUS[STOPPED] when
                                                                 done. */
		uint64_t reserved_18_18              : 1;
		uint64_t reset                       : 1;  /**< WO - SQ Reset. Writing a 1 resets internal state for this SQ and the following registers:
                                                                 * NIC_PF_QS()_SQ()_CFG.
                                                                 * NIC_PF_QS()_SQ()_STAT().
                                                                 * NIC_QS()_SQ()_CFG.
                                                                 * NIC_QS()_SQ()_THRESH.
                                                                 * NIC_QS()_SQ()_BASE.
                                                                 * NIC_QS()_SQ()_HEAD.
                                                                 * NIC_QS()_SQ()_TAIL.
                                                                 * NIC_QS()_SQ()_DOOR.
                                                                 * NIC_QS()_SQ()_STATUS.
                                                                 * NIC_QS()_SQ()_STAT(). */
		uint64_t ldwb                        : 1;  /**< R/W/H - When reading SQEs for a scheduled send packet that include the last byte of the SQE cache
                                                                 line, use LDWB transaction to invalidate the cache line. */
		uint64_t reserved_11_15              : 5;
		uint64_t qsize                       : 3;  /**< R/W/H - Specifies SQ ring size in entries of 16 bytes:
                                                                 0x0 = 1K entries.
                                                                 0x1 = 2K entries.
                                                                 0x2 = 4K entries.
                                                                 0x3 = 8K entries.
                                                                 0x4 = 16K entries.
                                                                 0x5 = 32K entries.
                                                                 0x6 = 64K entries.
                                                                 0x7 = Reserved.

                                                                 Note that the usable size of the ring is the specified size minus 1 (HEAD==TAIL always
                                                                 means empty). */
		uint64_t reserved_3_7                : 5;
		uint64_t tstmp_bgx_intf              : 3;  /**< R/W/H - Selects the BGX interface for send timestamp capture. The upper bit selects the BGX block;
                                                                 the lower 2 bits selects the BGX interface/LMAC/port within the block. If the SQ sends a
                                                                 packet with NIC_SEND_HDR_S[TSTMP]=1, this field selects the Ethernet port from which the
                                                                 timestamp will be captured. */
#else
		uint64_t tstmp_bgx_intf              : 3;
		uint64_t reserved_3_7                : 5;
		uint64_t qsize                       : 3;
		uint64_t reserved_11_15              : 5;
		uint64_t ldwb                        : 1;
		uint64_t reset                       : 1;
		uint64_t reserved_18_18              : 1;
		uint64_t ena                         : 1;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_cfg_s       cn88xx; */
	/* struct bdk_nic_qsx_sqx_cfg_s       cn88xxp1; */
} bdk_nic_qsx_sqx_cfg_t;

static inline uint64_t BDK_NIC_QSX_SQX_CFG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_CFG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010800ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_CFG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_CFG(...) bdk_nic_qsx_sqx_cfg_t
#define bustype_BDK_NIC_QSX_SQX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_CFG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_CFG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_CFG(...) "NIC_QSX_SQX_CFG"


/**
 * NCB - nic_qs#_sq#_debug
 */
typedef union bdk_nic_qsx_sqx_debug {
	uint64_t u;
	struct bdk_nic_qsx_sqx_debug_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_32_63              : 32;
		uint64_t dpe_ptr                     : 16; /**< R/W/H - Descriptor parse engine pointer. Initialized to NIC_QS()_SQ()_HEAD[HEAD_PTR]
                                                                 when software writes that register. Advanced as queued descriptors are parsed by hardware.
                                                                 For diagnostic use only. Writes are ignored when NIC_PF_CFG[TEST_MODE] is clear. */
		uint64_t dse_ptr                     : 16; /**< R/W/H - Descriptor send engine pointer. Initialized to NIC_QS()_SQ()_HEAD[HEAD_PTR] when
                                                                 software writes that register. Advanced by hardware as send packets are scheduled. For
                                                                 diagnostic use only. Writes are ignored when NIC_PF_CFG[TEST_MODE] is clear. */
#else
		uint64_t dse_ptr                     : 16;
		uint64_t dpe_ptr                     : 16;
		uint64_t reserved_32_63              : 32;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_debug_s     cn88xx; */
	/* struct bdk_nic_qsx_sqx_debug_s     cn88xxp1; */
} bdk_nic_qsx_sqx_debug_t;

static inline uint64_t BDK_NIC_QSX_SQX_DEBUG(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_DEBUG(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010848ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_DEBUG", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_DEBUG(...) bdk_nic_qsx_sqx_debug_t
#define bustype_BDK_NIC_QSX_SQX_DEBUG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_DEBUG(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_DEBUG(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_DEBUG(...) "NIC_QSX_SQX_DEBUG"


/**
 * NCB - nic_qs#_sq#_door
 *
 * Software writes to this register to notify hardware that one or more entries have been enqeued
 * to the SQ ring.
 */
typedef union bdk_nic_qsx_sqx_door {
	uint64_t u;
	struct bdk_nic_qsx_sqx_door_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t count                       : 16; /**< WO - Number of enqueued entries (subdescriptors) of 16 bytes. Hardware advances
                                                                 NIC_QS()_SQ()_TAIL[TAIL_PTR] by this value if the SQ is enabled.

                                                                 The usable size of the ring is the size specified by NIC_QS()_SQ()_CFG[QSIZE] minus 1. As
                                                                 such, a doorbell write that would make the ring go full or overflow is suppressed and
                                                                 treated as a doorbell error. Hardware sets NIC_QS()_SQ()_STATUS[SOFT_STOP] on a doorbell
                                                                 error, stops servicing the SQ and sets NIC_QS()_SQ()_STATUS[STOPPED] when the stop
                                                                 operation is done. */
#else
		uint64_t count                       : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_door_s      cn88xx; */
	/* struct bdk_nic_qsx_sqx_door_s      cn88xxp1; */
} bdk_nic_qsx_sqx_door_t;

static inline uint64_t BDK_NIC_QSX_SQX_DOOR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_DOOR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010838ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_DOOR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_DOOR(...) bdk_nic_qsx_sqx_door_t
#define bustype_BDK_NIC_QSX_SQX_DOOR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_DOOR(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_DOOR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_DOOR(...) "NIC_QSX_SQX_DOOR"


/**
 * NCB - nic_qs#_sq#_head
 */
typedef union bdk_nic_qsx_sqx_head {
	uint64_t u;
	struct bdk_nic_qsx_sqx_head_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t head_ptr                    : 16; /**< R/W/H - Head pointer\<19:4\> of SQ ring in DRAM relative to NIC_QS()_SQ()_BASE. Address
                                                                 bits \<3:0\> are always 0. Hardware updates this register to notify software that one or
                                                                 more entries (subdescriptors) have been dequeued from the SQ ring. Writes are ignored when
                                                                 NIC_PF_CFG[TEST_MODE] is clear. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t head_ptr                    : 16;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_head_s      cn88xx; */
	/* struct bdk_nic_qsx_sqx_head_s      cn88xxp1; */
} bdk_nic_qsx_sqx_head_t;

static inline uint64_t BDK_NIC_QSX_SQX_HEAD(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_HEAD(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010828ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_HEAD", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_HEAD(...) bdk_nic_qsx_sqx_head_t
#define bustype_BDK_NIC_QSX_SQX_HEAD(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_HEAD(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_HEAD(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_HEAD(...) "NIC_QSX_SQX_HEAD"


/**
 * NCB - nic_qs#_sq#_stat#
 *
 * The third dimension indicates which statistic, and is enumerated by NIC_STAT_SQ_E.
 *
 */
typedef union bdk_nic_qsx_sqx_statx {
	uint64_t u;
	struct bdk_nic_qsx_sqx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< RO/H - Statistic value. See also NIC_PF_QS()_SQ()_STAT() for a writable alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_statx_s     cn88xx; */
	/* struct bdk_nic_qsx_sqx_statx_s     cn88xxp1; */
} bdk_nic_qsx_sqx_statx_t;

static inline uint64_t BDK_NIC_QSX_SQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_STATX(unsigned long param1, unsigned long param2, unsigned long param3)
{
	if (((param1 <= 127)) && ((param2 <= 7)) && ((param3 <= 1)))
		return 0x00008430A0010900ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull + (param3 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_QSX_SQX_STATX", 3, param1, param2, param3, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_STATX(...) bdk_nic_qsx_sqx_statx_t
#define bustype_BDK_NIC_QSX_SQX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_STATX(p1,p2,p3) (p1)
#define arguments_BDK_NIC_QSX_SQX_STATX(p1,p2,p3) (p1),(p2),(p3),-1
#define basename_BDK_NIC_QSX_SQX_STATX(...) "NIC_QSX_SQX_STATX"


/**
 * NCB - nic_qs#_sq#_status
 */
typedef union bdk_nic_qsx_sqx_status {
	uint64_t u;
	struct bdk_nic_qsx_sqx_status_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_22_63              : 42;
		uint64_t stopped                     : 1;  /**< RO/H - NIC has stopped servicing this SQ. This bit is set along with the associated
                                                                 NIC_VF()_INT[SQ\<a\>] interrupt after hardware sets [SEND_ERR], [DPE_ERR] and/or
                                                                 [SOFT_STOP]. Software can safely reset the SQ after this bit is set by writing a 1 to
                                                                 NIC_QS()_SQ()_CFG[RESET]. */
		uint64_t send_err                    : 1;  /**< RO/H - Send error. NIC sets this bit along with NIC_VF()_INT[QS_ERR] when it detects an
                                                                 error on a packet scheduled from this SQ. When this bit is set, NIC stops servicing the SQ
                                                                 and sets [STOPPED] in this register when the stop operation done. A NIC_CQE_SEND_S is
                                                                 created with [CQE_TYPE] = NIC_CQE_TYPE_E::SEND and non-zero [SEND_STATUS] for every
                                                                 scheduled packet that has an error until the SQ is stopped. */
		uint64_t dpe_err                     : 1;  /**< RO/H - Descriptor Parsing Engine error. NIC sets this bit along with NIC_VF()_INT[QS_ERR]
                                                                 when any of the following errors is detected on a send descriptor:
                                                                 * The first SQE of the send descriptor is not NIC_SEND_HDR_S, i.e. [SUBDC] is not HDR.
                                                                 * NIC_SEND_HDR_S[SUBDCNT] is 0.
                                                                 * NIC_SEND_HDR_S[TOTAL] is 0.
                                                                 * Memory fault on NIC_SEND_HDR_S read.

                                                                 When this bit is set, NIC stops servicing the SQ and sets [STOPPED] in this register when
                                                                 the stop operation done. A NIC_CQE_SEND_S is not created for a descriptor error that sets
                                                                 this bit. */
		uint64_t soft_stop                   : 1;  /**< RAZ - Reserved. */
		uint64_t reserved_16_17              : 2;
		uint64_t qcount                      : 16; /**< RO/H - Number of valid entries in the SQ. Computed by hardware from
                                                                 NIC_QS()_SQ()_CFG[QSIZE], NIC_QS()_SQ()_TAIL[TAIL_PTR] and
                                                                 NIC_QS()_SQ()_HEAD[HEAD_PTR]. */
#else
		uint64_t qcount                      : 16;
		uint64_t reserved_16_17              : 2;
		uint64_t soft_stop                   : 1;
		uint64_t dpe_err                     : 1;
		uint64_t send_err                    : 1;
		uint64_t stopped                     : 1;
		uint64_t reserved_22_63              : 42;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_status_s    cn88xx; */
	/* struct bdk_nic_qsx_sqx_status_s    cn88xxp1; */
} bdk_nic_qsx_sqx_status_t;

static inline uint64_t BDK_NIC_QSX_SQX_STATUS(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_STATUS(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010840ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_STATUS", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_STATUS(...) bdk_nic_qsx_sqx_status_t
#define bustype_BDK_NIC_QSX_SQX_STATUS(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_STATUS(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_STATUS(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_STATUS(...) "NIC_QSX_SQX_STATUS"


/**
 * NCB - nic_qs#_sq#_tail
 */
typedef union bdk_nic_qsx_sqx_tail {
	uint64_t u;
	struct bdk_nic_qsx_sqx_tail_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_20_63              : 44;
		uint64_t tail_ptr                    : 16; /**< R/W/H - Tail pointer\<19:4\> of SQ ring in DRAM relative to NIC_QS()_SQ()_BASE. Address
                                                                 bits \<3:0\> are always 0. This register is automatically updated when software writes to
                                                                 NIC_QS()_SQ()_DOOR. Writes are ignored when NIC_PF_CFG[TEST_MODE] is clear. */
		uint64_t reserved_0_3                : 4;
#else
		uint64_t reserved_0_3                : 4;
		uint64_t tail_ptr                    : 16;
		uint64_t reserved_20_63              : 44;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_tail_s      cn88xx; */
	/* struct bdk_nic_qsx_sqx_tail_s      cn88xxp1; */
} bdk_nic_qsx_sqx_tail_t;

static inline uint64_t BDK_NIC_QSX_SQX_TAIL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_TAIL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010830ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_TAIL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_TAIL(...) bdk_nic_qsx_sqx_tail_t
#define bustype_BDK_NIC_QSX_SQX_TAIL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_TAIL(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_TAIL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_TAIL(...) "NIC_QSX_SQX_TAIL"


/**
 * NCB - nic_qs#_sq#_thresh
 */
typedef union bdk_nic_qsx_sqx_thresh {
	uint64_t u;
	struct bdk_nic_qsx_sqx_thresh_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_16_63              : 48;
		uint64_t thresh                      : 16; /**< R/W/H - Queue-count threshold for SQ interrupt. When non-zero, the associated
                                                                 NIC_VF()_INT[SQ] interrupt bit is set when NIC_QS()_SQ()_STATUS[QCOUNT]
                                                                 crosses [THRESH]. */
#else
		uint64_t thresh                      : 16;
		uint64_t reserved_16_63              : 48;
#endif
	} s;
	/* struct bdk_nic_qsx_sqx_thresh_s    cn88xx; */
	/* struct bdk_nic_qsx_sqx_thresh_s    cn88xxp1; */
} bdk_nic_qsx_sqx_thresh_t;

static inline uint64_t BDK_NIC_QSX_SQX_THRESH(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_QSX_SQX_THRESH(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 7)))
		return 0x00008430A0010810ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x40000ull;
	csr_fatal("BDK_NIC_QSX_SQX_THRESH", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_QSX_SQX_THRESH(...) bdk_nic_qsx_sqx_thresh_t
#define bustype_BDK_NIC_QSX_SQX_THRESH(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_QSX_SQX_THRESH(p1,p2) (p1)
#define arguments_BDK_NIC_QSX_SQX_THRESH(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_QSX_SQX_THRESH(...) "NIC_QSX_SQX_THRESH"


/**
 * NCB - nic_vf#_cfg
 */
typedef union bdk_nic_vfx_cfg {
	uint64_t u;
	struct bdk_nic_vfx_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_1_63               : 63;
		uint64_t tcp_timer_int_ena           : 1;  /**< R/W - TCP timer interrupt enable. When set along with NIC_PF_TCP_TIMER[ENA],
                                                                 NIC_VF()_INT[TCP_TIMER_INT] is set every NIC_PF_TCP_TIMER[DURATION]*256*128
                                                                 coprocessor-clock
                                                                 cycles. */
#else
		uint64_t tcp_timer_int_ena           : 1;
		uint64_t reserved_1_63               : 63;
#endif
	} s;
	/* struct bdk_nic_vfx_cfg_s           cn88xx; */
	/* struct bdk_nic_vfx_cfg_s           cn88xxp1; */
} bdk_nic_vfx_cfg_t;

static inline uint64_t BDK_NIC_VFX_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_CFG(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0000020ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_CFG(...) bdk_nic_vfx_cfg_t
#define bustype_BDK_NIC_VFX_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_CFG(p1) (p1)
#define arguments_BDK_NIC_VFX_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VFX_CFG(...) "NIC_VFX_CFG"


/**
 * NCB - nic_vf#_ena_w1c
 */
typedef union bdk_nic_vfx_ena_w1c {
	uint64_t u;
	struct bdk_nic_vfx_ena_w1c_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t qs_err                      : 1;  /**< R/W1C/H - Queue set error. Set when a CQ, SQ or RBDR in the QS has an error, as follows:
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FULL] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_DISABLE] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FAULT] bit is set.
                                                                 * A send queue's NIC_QS()_SQ()_STATUS[SEND_ERR] or
                                                                 NIC_QS()_SQ()_STATUS[DPE_ERR] bit is set.
                                                                 * An RBDR's NIC_QS()_RBDR()_STATUS0[FIFO_STATE] field transitions to FAIL. */
		uint64_t mbox                        : 1;  /**< R/W1C/H - PF to VF mailbox interrupt. Set when the NIC_PF_VF(0..127)_MBOX(0) register is written. */
		uint64_t tcp_timer                   : 1;  /**< R/W1C/H - TCP timer interrupt. Enabled when NIC_PF_TCP_TIMER[ENA] and
                                                                 NIC_VF()_CFG[TCP_TIMER_INT_ENA] are both set. Set every
                                                                 NIC_PF_TCP_TIMER[DURATION]*256*128 coprocessor cycles when enabled. */
		uint64_t vnic_drop                   : 1;  /**< R/W1C/H - Packet dropped interrupt. Hardware sets this bit and generates an interrupt message when
                                                                 any packet has been dropped. This is intended for diagnostic use; typical production
                                                                 software will want this interrupt disabled. */
		uint64_t reserved_18_19              : 2;
		uint64_t rbdr                        : 2;  /**< R/W1C/H - RBDR interrupt. One bit for each RBDR in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following condition for its RBDR:
                                                                 * NIC_QS()_RBDR()_THRESH is non-zero and
                                                                 NIC_QS()_RBDR()_STATUS0[QCOUNT] crosses NIC_QS()_RBDR()_THRESH when
                                                                 hardware advances NIC_QS()_RBDR()_HEAD or NIC_QS()_RBDR()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t sq                          : 8;  /**< R/W1C/H - Send queue interrupt. One bit for each SQ in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following conditions for its send queue:
                                                                 * NIC_QS()_SQ()_THRESH is non-zero and NIC_QS()_SQ()_STATUS[QCOUNT]
                                                                 crosses NIC_QS()_SQ()_THRESH when hardware advances NIC_QS()_SQ()_HEAD
                                                                 or NIC_QS()_SQ()_TAIL.
                                                                 * NIC_QS()_SQ()_STATUS[STOPPED] is set.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t cq                          : 8;  /**< R/W1C/H - Completion queue interrupt. One bit for each CQ in the QS. Hardware sets each bit and
                                                                 generates an interrupt message under any of the following conditions for its completion
                                                                 queue:
                                                                 * In NIC_QS()_CQ()_STATUS2, [TIMER_EN]=1 and [GLOBAL_TIME] crosses [INT_TIMER].
                                                                 * NIC_QS()_CQ()_THRESH is non-zero and NIC_QS()_CQ()_STATUS[QCOUNT] crosses
                                                                 NIC_QS()_CQ()_THRESH when hardware advances NIC_QS()_CQ()_HEAD or NIC_QS()_CQ()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
#else
		uint64_t cq                          : 8;
		uint64_t sq                          : 8;
		uint64_t rbdr                        : 2;
		uint64_t reserved_18_19              : 2;
		uint64_t vnic_drop                   : 1;
		uint64_t tcp_timer                   : 1;
		uint64_t mbox                        : 1;
		uint64_t qs_err                      : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_vfx_ena_w1c_s       cn88xx; */
	/* struct bdk_nic_vfx_ena_w1c_s       cn88xxp1; */
} bdk_nic_vfx_ena_w1c_t;

static inline uint64_t BDK_NIC_VFX_ENA_W1C(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_ENA_W1C(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0000240ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_ENA_W1C", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_ENA_W1C(...) bdk_nic_vfx_ena_w1c_t
#define bustype_BDK_NIC_VFX_ENA_W1C(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_ENA_W1C(p1) (p1)
#define arguments_BDK_NIC_VFX_ENA_W1C(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VFX_ENA_W1C(...) "NIC_VFX_ENA_W1C"


/**
 * NCB - nic_vf#_ena_w1s
 */
typedef union bdk_nic_vfx_ena_w1s {
	uint64_t u;
	struct bdk_nic_vfx_ena_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t qs_err                      : 1;  /**< R/W1C/H - Queue set error. Set when a CQ, SQ or RBDR in the QS has an error, as follows:
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FULL] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_DISABLE] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FAULT] bit is set.
                                                                 * A send queue's NIC_QS()_SQ()_STATUS[SEND_ERR] or
                                                                 NIC_QS()_SQ()_STATUS[DPE_ERR] bit is set.
                                                                 * An RBDR's NIC_QS()_RBDR()_STATUS0[FIFO_STATE] field transitions to FAIL. */
		uint64_t mbox                        : 1;  /**< R/W1C/H - PF to VF mailbox interrupt. Set when the NIC_PF_VF(0..127)_MBOX(0) register is written. */
		uint64_t tcp_timer                   : 1;  /**< R/W1C/H - TCP timer interrupt. Enabled when NIC_PF_TCP_TIMER[ENA] and
                                                                 NIC_VF()_CFG[TCP_TIMER_INT_ENA] are both set. Set every
                                                                 NIC_PF_TCP_TIMER[DURATION]*256*128 coprocessor cycles when enabled. */
		uint64_t vnic_drop                   : 1;  /**< R/W1C/H - Packet dropped interrupt. Hardware sets this bit and generates an interrupt message when
                                                                 any packet has been dropped. This is intended for diagnostic use; typical production
                                                                 software will want this interrupt disabled. */
		uint64_t reserved_18_19              : 2;
		uint64_t rbdr                        : 2;  /**< R/W1C/H - RBDR interrupt. One bit for each RBDR in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following condition for its RBDR:
                                                                 * NIC_QS()_RBDR()_THRESH is non-zero and
                                                                 NIC_QS()_RBDR()_STATUS0[QCOUNT] crosses NIC_QS()_RBDR()_THRESH when
                                                                 hardware advances NIC_QS()_RBDR()_HEAD or NIC_QS()_RBDR()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t sq                          : 8;  /**< R/W1C/H - Send queue interrupt. One bit for each SQ in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following conditions for its send queue:
                                                                 * NIC_QS()_SQ()_THRESH is non-zero and NIC_QS()_SQ()_STATUS[QCOUNT]
                                                                 crosses NIC_QS()_SQ()_THRESH when hardware advances NIC_QS()_SQ()_HEAD
                                                                 or NIC_QS()_SQ()_TAIL.
                                                                 * NIC_QS()_SQ()_STATUS[STOPPED] is set.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t cq                          : 8;  /**< R/W1C/H - Completion queue interrupt. One bit for each CQ in the QS. Hardware sets each bit and
                                                                 generates an interrupt message under any of the following conditions for its completion
                                                                 queue:
                                                                 * In NIC_QS()_CQ()_STATUS2, [TIMER_EN]=1 and [GLOBAL_TIME] crosses [INT_TIMER].
                                                                 * NIC_QS()_CQ()_THRESH is non-zero and NIC_QS()_CQ()_STATUS[QCOUNT] crosses
                                                                 NIC_QS()_CQ()_THRESH when hardware advances NIC_QS()_CQ()_HEAD or NIC_QS()_CQ()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
#else
		uint64_t cq                          : 8;
		uint64_t sq                          : 8;
		uint64_t rbdr                        : 2;
		uint64_t reserved_18_19              : 2;
		uint64_t vnic_drop                   : 1;
		uint64_t tcp_timer                   : 1;
		uint64_t mbox                        : 1;
		uint64_t qs_err                      : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_vfx_ena_w1s_s       cn88xx; */
	/* struct bdk_nic_vfx_ena_w1s_s       cn88xxp1; */
} bdk_nic_vfx_ena_w1s_t;

static inline uint64_t BDK_NIC_VFX_ENA_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_ENA_W1S(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0000260ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_ENA_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_ENA_W1S(...) bdk_nic_vfx_ena_w1s_t
#define bustype_BDK_NIC_VFX_ENA_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_ENA_W1S(p1) (p1)
#define arguments_BDK_NIC_VFX_ENA_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VFX_ENA_W1S(...) "NIC_VFX_ENA_W1S"


/**
 * NCB - nic_vf#_int
 */
typedef union bdk_nic_vfx_int {
	uint64_t u;
	struct bdk_nic_vfx_int_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t qs_err                      : 1;  /**< R/W1C/H - Queue set error. Set when a CQ, SQ or RBDR in the QS has an error, as follows:
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FULL] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_DISABLE] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FAULT] bit is set.
                                                                 * A send queue's NIC_QS()_SQ()_STATUS[SEND_ERR] or
                                                                 NIC_QS()_SQ()_STATUS[DPE_ERR] bit is set.
                                                                 * An RBDR's NIC_QS()_RBDR()_STATUS0[FIFO_STATE] field transitions to FAIL. */
		uint64_t mbox                        : 1;  /**< R/W1C/H - PF to VF mailbox interrupt. Set when the NIC_PF_VF(0..127)_MBOX(0) register is written. */
		uint64_t tcp_timer                   : 1;  /**< R/W1C/H - TCP timer interrupt. Enabled when NIC_PF_TCP_TIMER[ENA] and
                                                                 NIC_VF()_CFG[TCP_TIMER_INT_ENA] are both set. Set every
                                                                 NIC_PF_TCP_TIMER[DURATION]*256*128 coprocessor cycles when enabled. */
		uint64_t vnic_drop                   : 1;  /**< R/W1C/H - Packet dropped interrupt. Hardware sets this bit and generates an interrupt message when
                                                                 any packet has been dropped. This is intended for diagnostic use; typical production
                                                                 software will want this interrupt disabled. */
		uint64_t reserved_18_19              : 2;
		uint64_t rbdr                        : 2;  /**< R/W1C/H - RBDR interrupt. One bit for each RBDR in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following condition for its RBDR:
                                                                 * NIC_QS()_RBDR()_THRESH is non-zero and
                                                                 NIC_QS()_RBDR()_STATUS0[QCOUNT] crosses NIC_QS()_RBDR()_THRESH when
                                                                 hardware advances NIC_QS()_RBDR()_HEAD or NIC_QS()_RBDR()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t sq                          : 8;  /**< R/W1C/H - Send queue interrupt. One bit for each SQ in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following conditions for its send queue:
                                                                 * NIC_QS()_SQ()_THRESH is non-zero and NIC_QS()_SQ()_STATUS[QCOUNT]
                                                                 crosses NIC_QS()_SQ()_THRESH when hardware advances NIC_QS()_SQ()_HEAD
                                                                 or NIC_QS()_SQ()_TAIL.
                                                                 * NIC_QS()_SQ()_STATUS[STOPPED] is set.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t cq                          : 8;  /**< R/W1C/H - Completion queue interrupt. One bit for each CQ in the QS. Hardware sets each bit and
                                                                 generates an interrupt message under any of the following conditions for its completion
                                                                 queue:
                                                                 * In NIC_QS()_CQ()_STATUS2, [TIMER_EN]=1 and [GLOBAL_TIME] crosses [INT_TIMER].
                                                                 * NIC_QS()_CQ()_THRESH is non-zero and NIC_QS()_CQ()_STATUS[QCOUNT] crosses
                                                                 NIC_QS()_CQ()_THRESH when hardware advances NIC_QS()_CQ()_HEAD or NIC_QS()_CQ()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
#else
		uint64_t cq                          : 8;
		uint64_t sq                          : 8;
		uint64_t rbdr                        : 2;
		uint64_t reserved_18_19              : 2;
		uint64_t vnic_drop                   : 1;
		uint64_t tcp_timer                   : 1;
		uint64_t mbox                        : 1;
		uint64_t qs_err                      : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_vfx_int_s           cn88xx; */
	/* struct bdk_nic_vfx_int_s           cn88xxp1; */
} bdk_nic_vfx_int_t;

static inline uint64_t BDK_NIC_VFX_INT(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_INT(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0000200ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_INT", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_INT(...) bdk_nic_vfx_int_t
#define bustype_BDK_NIC_VFX_INT(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_INT(p1) (p1)
#define arguments_BDK_NIC_VFX_INT(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VFX_INT(...) "NIC_VFX_INT"


/**
 * NCB - nic_vf#_int_w1s
 */
typedef union bdk_nic_vfx_int_w1s {
	uint64_t u;
	struct bdk_nic_vfx_int_w1s_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_24_63              : 40;
		uint64_t qs_err                      : 1;  /**< R/W1C/H - Queue set error. Set when a CQ, SQ or RBDR in the QS has an error, as follows:
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FULL] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_DISABLE] bit is set.
                                                                 * A completion queue's NIC_QS()_CQ()_STATUS[CQ_WR_FAULT] bit is set.
                                                                 * A send queue's NIC_QS()_SQ()_STATUS[SEND_ERR] or
                                                                 NIC_QS()_SQ()_STATUS[DPE_ERR] bit is set.
                                                                 * An RBDR's NIC_QS()_RBDR()_STATUS0[FIFO_STATE] field transitions to FAIL. */
		uint64_t mbox                        : 1;  /**< R/W1C/H - PF to VF mailbox interrupt. Set when the NIC_PF_VF(0..127)_MBOX(0) register is written. */
		uint64_t tcp_timer                   : 1;  /**< R/W1C/H - TCP timer interrupt. Enabled when NIC_PF_TCP_TIMER[ENA] and
                                                                 NIC_VF()_CFG[TCP_TIMER_INT_ENA] are both set. Set every
                                                                 NIC_PF_TCP_TIMER[DURATION]*256*128 coprocessor cycles when enabled. */
		uint64_t vnic_drop                   : 1;  /**< R/W1C/H - Packet dropped interrupt. Hardware sets this bit and generates an interrupt message when
                                                                 any packet has been dropped. This is intended for diagnostic use; typical production
                                                                 software will want this interrupt disabled. */
		uint64_t reserved_18_19              : 2;
		uint64_t rbdr                        : 2;  /**< R/W1C/H - RBDR interrupt. One bit for each RBDR in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following condition for its RBDR:
                                                                 * NIC_QS()_RBDR()_THRESH is non-zero and
                                                                 NIC_QS()_RBDR()_STATUS0[QCOUNT] crosses NIC_QS()_RBDR()_THRESH when
                                                                 hardware advances NIC_QS()_RBDR()_HEAD or NIC_QS()_RBDR()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t sq                          : 8;  /**< R/W1C/H - Send queue interrupt. One bit for each SQ in the QS. Hardware sets each bit and generates
                                                                 an interrupt message under any of the following conditions for its send queue:
                                                                 * NIC_QS()_SQ()_THRESH is non-zero and NIC_QS()_SQ()_STATUS[QCOUNT]
                                                                 crosses NIC_QS()_SQ()_THRESH when hardware advances NIC_QS()_SQ()_HEAD
                                                                 or NIC_QS()_SQ()_TAIL.
                                                                 * NIC_QS()_SQ()_STATUS[STOPPED] is set.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
		uint64_t cq                          : 8;  /**< R/W1C/H - Completion queue interrupt. One bit for each CQ in the QS. Hardware sets each bit and
                                                                 generates an interrupt message under any of the following conditions for its completion
                                                                 queue:
                                                                 * In NIC_QS()_CQ()_STATUS2, [TIMER_EN]=1 and [GLOBAL_TIME] crosses [INT_TIMER].
                                                                 * NIC_QS()_CQ()_THRESH is non-zero and NIC_QS()_CQ()_STATUS[QCOUNT] crosses
                                                                 NIC_QS()_CQ()_THRESH when hardware advances NIC_QS()_CQ()_HEAD or NIC_QS()_CQ()_TAIL.

                                                                 Subsequent interrupt messages are only generated after the bit has been cleared by
                                                                 software. */
#else
		uint64_t cq                          : 8;
		uint64_t sq                          : 8;
		uint64_t rbdr                        : 2;
		uint64_t reserved_18_19              : 2;
		uint64_t vnic_drop                   : 1;
		uint64_t tcp_timer                   : 1;
		uint64_t mbox                        : 1;
		uint64_t qs_err                      : 1;
		uint64_t reserved_24_63              : 40;
#endif
	} s;
	/* struct bdk_nic_vfx_int_w1s_s       cn88xx; */
	/* struct bdk_nic_vfx_int_w1s_s       cn88xxp1; */
} bdk_nic_vfx_int_w1s_t;

static inline uint64_t BDK_NIC_VFX_INT_W1S(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_INT_W1S(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A0000220ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_INT_W1S", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_INT_W1S(...) bdk_nic_vfx_int_w1s_t
#define bustype_BDK_NIC_VFX_INT_W1S(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_INT_W1S(p1) (p1)
#define arguments_BDK_NIC_VFX_INT_W1S(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VFX_INT_W1S(...) "NIC_VFX_INT_W1S"


/**
 * NCB - nic_vf#_msix_pba#
 *
 * This register is the MSI-X PBA table, the bit number is indexed by the NIC_VF_INT_VEC_E
 * enumeration.
 */
typedef union bdk_nic_vfx_msix_pbax {
	uint64_t u;
	struct bdk_nic_vfx_msix_pbax_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t pend                        : 64; /**< RO/H - Pending message for the associated NIC_VF()_MSIX_VEC()_CTL, enumerated by
                                                                 NIC_VF_INT_VEC_E. Bits that have no associated NIC_VF_INT_VEC_E are zero. */
#else
		uint64_t pend                        : 64;
#endif
	} s;
	/* struct bdk_nic_vfx_msix_pbax_s     cn88xx; */
	/* struct bdk_nic_vfx_msix_pbax_s     cn88xxp1; */
} bdk_nic_vfx_msix_pbax_t;

static inline uint64_t BDK_NIC_VFX_MSIX_PBAX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_MSIX_PBAX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 == 0)))
		return 0x00008430E00F0000ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VFX_MSIX_PBAX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_MSIX_PBAX(...) bdk_nic_vfx_msix_pbax_t
#define bustype_BDK_NIC_VFX_MSIX_PBAX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_MSIX_PBAX(p1,p2) (p1)
#define arguments_BDK_NIC_VFX_MSIX_PBAX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VFX_MSIX_PBAX(...) "NIC_VFX_MSIX_PBAX"


/**
 * NCB - nic_vf#_msix_vec#_addr
 *
 * This register is the MSI-X vector table, indexed by the NIC_VF_INT_VEC_E enumeration.
 *
 */
typedef union bdk_nic_vfx_msix_vecx_addr {
	uint64_t u;
	struct bdk_nic_vfx_msix_vecx_addr_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_49_63              : 15;
		uint64_t addr                        : 47; /**< R/W - Address to use for MSI-X delivery of this vector. */
		uint64_t reserved_1_1                : 1;
		uint64_t secvec                      : 1;  /**< RAZ - Secure vector. Zero as not supported on a per-vector basis for VFs; use
                                                                 PCCPF_NIC_VSEC_SCTL[MSIX_SEC] instead (for documentation, see
                                                                 PCCPF_XXX_VSEC_SCTL[MSIX_SEC]). */
#else
		uint64_t secvec                      : 1;
		uint64_t reserved_1_1                : 1;
		uint64_t addr                        : 47;
		uint64_t reserved_49_63              : 15;
#endif
	} s;
	/* struct bdk_nic_vfx_msix_vecx_addr_s cn88xx; */
	/* struct bdk_nic_vfx_msix_vecx_addr_s cn88xxp1; */
} bdk_nic_vfx_msix_vecx_addr_t;

static inline uint64_t BDK_NIC_VFX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_MSIX_VECX_ADDR(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 19)))
		return 0x00008430E0000000ull + (param1 & 127) * 0x200000ull + (param2 & 31) * 0x10ull;
	csr_fatal("BDK_NIC_VFX_MSIX_VECX_ADDR", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_MSIX_VECX_ADDR(...) bdk_nic_vfx_msix_vecx_addr_t
#define bustype_BDK_NIC_VFX_MSIX_VECX_ADDR(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_MSIX_VECX_ADDR(p1,p2) (p1)
#define arguments_BDK_NIC_VFX_MSIX_VECX_ADDR(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VFX_MSIX_VECX_ADDR(...) "NIC_VFX_MSIX_VECX_ADDR"


/**
 * NCB - nic_vf#_msix_vec#_ctl
 *
 * This register is the MSI-X vector table, indexed by the NIC_VF_INT_VEC_E enumeration.
 *
 */
typedef union bdk_nic_vfx_msix_vecx_ctl {
	uint64_t u;
	struct bdk_nic_vfx_msix_vecx_ctl_s {
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
	/* struct bdk_nic_vfx_msix_vecx_ctl_s cn88xx; */
	/* struct bdk_nic_vfx_msix_vecx_ctl_s cn88xxp1; */
} bdk_nic_vfx_msix_vecx_ctl_t;

static inline uint64_t BDK_NIC_VFX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_MSIX_VECX_CTL(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 19)))
		return 0x00008430E0000008ull + (param1 & 127) * 0x200000ull + (param2 & 31) * 0x10ull;
	csr_fatal("BDK_NIC_VFX_MSIX_VECX_CTL", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_MSIX_VECX_CTL(...) bdk_nic_vfx_msix_vecx_ctl_t
#define bustype_BDK_NIC_VFX_MSIX_VECX_CTL(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_MSIX_VECX_CTL(p1,p2) (p1)
#define arguments_BDK_NIC_VFX_MSIX_VECX_CTL(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VFX_MSIX_VECX_CTL(...) "NIC_VFX_MSIX_VECX_CTL"


/**
 * NCB - nic_vf#_pf_mbox#
 */
typedef union bdk_nic_vfx_pf_mboxx {
	uint64_t u;
	struct bdk_nic_vfx_pf_mboxx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t data                        : 64; /**< R/W/H - Mailbox data. These VF registers access the 16-byte-per-VF VF/PF mailbox
                                                                 RAM. The PF may access the same storage using NIC_PF_VF()_MBOX(). MBOX(0) is
                                                                 typically used for PF to VF signaling, MBOX(1) for VF to PF. Writing
                                                                 NIC_VF(0..127)_PF_MBOX(1) (but not NIC_PF_VF(0..127)_MBOX(1)) will set the
                                                                 corresponding NIC_PF_MBOX_INT() bit, which if appropriately enabled will send an
                                                                 interrupt to the PF. */
#else
		uint64_t data                        : 64;
#endif
	} s;
	/* struct bdk_nic_vfx_pf_mboxx_s      cn88xx; */
	/* struct bdk_nic_vfx_pf_mboxx_s      cn88xxp1; */
} bdk_nic_vfx_pf_mboxx_t;

static inline uint64_t BDK_NIC_VFX_PF_MBOXX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VFX_PF_MBOXX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 1)))
		return 0x00008430A0000130ull + (param1 & 127) * 0x200000ull + (param2 & 1) * 0x8ull;
	csr_fatal("BDK_NIC_VFX_PF_MBOXX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VFX_PF_MBOXX(...) bdk_nic_vfx_pf_mboxx_t
#define bustype_BDK_NIC_VFX_PF_MBOXX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VFX_PF_MBOXX(p1,p2) (p1)
#define arguments_BDK_NIC_VFX_PF_MBOXX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VFX_PF_MBOXX(...) "NIC_VFX_PF_MBOXX"


/**
 * NCB - nic_vnic#_rss_cfg
 */
typedef union bdk_nic_vnicx_rss_cfg {
	uint64_t u;
	struct bdk_nic_vnicx_rss_cfg_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_12_63              : 52;
		uint64_t rss_tun_nvgre               : 1;  /**< RAZ - Reserved. */
		uint64_t rss_tun_geneve              : 1;  /**< RAZ - Reserved. */
		uint64_t rss_tun_vxlan               : 1;  /**< RAZ - Reserved. */
		uint64_t rss_l4_bidi                 : 1;  /**< R/W - Enable bidirectional flow symmetry RSS for the L4 TCP/UDP RSS layer. */
		uint64_t rss_l3_bidi                 : 1;  /**< R/W - Enable bidirectional flow symmetry RSS for the L3 IPV4, IPV6, ROCE RSS layer. */
		uint64_t rss_roce                    : 1;  /**< R/W - Enable ROCE delivery, potentially resulting in setting NIC_CQE_RX_S[RSS_ALG] =
                                                                 NIC_RSS_ALG_E::ROCE. */
		uint64_t rss_l4etc                   : 1;  /**< R/W - Enable L4 extended RSS hashing, including GRE, potentially resulting in setting
                                                                 NIC_CQE_RX_S[RSS_ALG] = NIC_RSS_ALG_E::GRE_IP. */
		uint64_t rss_udp                     : 1;  /**< R/W - Enable IP RSS hashing, potentially resulting in setting NIC_CQE_RX_S[RSS_ALG] =
                                                                 NIC_RSS_ALG_E::UDP_IP. */
		uint64_t rss_syn_dis                 : 1;  /**< R/W - Disable RSS on TCP SYN packets. If set, TCP packets with SYN & !ACK will have RSS disabled. */
		uint64_t rss_tcp                     : 1;  /**< R/W - Enable TCP RSS hashing, potentially resulting in setting NIC_CQE_RX_S[RSS_ALG] =
                                                                 NIC_RSS_ALG_E::TCP_IP. */
		uint64_t rss_ip                      : 1;  /**< R/W - Enable IPv4/6 RSS hashing, potentially resulting in setting NIC_CQE_RX_S[RSS_ALG] =
                                                                 NIC_RSS_ALG_E::IP. */
		uint64_t rss_l2etc                   : 1;  /**< R/W - Enable L2 extended RSS hashing, potentially resulting in setting NIC_CQE_RX_S[RSS_ALG] =
                                                                 NIC_RSS_ALG_E::PORT. */
#else
		uint64_t rss_l2etc                   : 1;
		uint64_t rss_ip                      : 1;
		uint64_t rss_tcp                     : 1;
		uint64_t rss_syn_dis                 : 1;
		uint64_t rss_udp                     : 1;
		uint64_t rss_l4etc                   : 1;
		uint64_t rss_roce                    : 1;
		uint64_t rss_l3_bidi                 : 1;
		uint64_t rss_l4_bidi                 : 1;
		uint64_t rss_tun_vxlan               : 1;
		uint64_t rss_tun_geneve              : 1;
		uint64_t rss_tun_nvgre               : 1;
		uint64_t reserved_12_63              : 52;
#endif
	} s;
	/* struct bdk_nic_vnicx_rss_cfg_s     cn88xx; */
	/* struct bdk_nic_vnicx_rss_cfg_s     cn88xxp1; */
} bdk_nic_vnicx_rss_cfg_t;

static inline uint64_t BDK_NIC_VNICX_RSS_CFG(unsigned long param1) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VNICX_RSS_CFG(unsigned long param1)
{
	if (((param1 <= 127)))
		return 0x00008430A00020E0ull + (param1 & 127) * 0x200000ull;
	csr_fatal("BDK_NIC_VNICX_RSS_CFG", 1, param1, 0, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VNICX_RSS_CFG(...) bdk_nic_vnicx_rss_cfg_t
#define bustype_BDK_NIC_VNICX_RSS_CFG(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VNICX_RSS_CFG(p1) (p1)
#define arguments_BDK_NIC_VNICX_RSS_CFG(p1) (p1),-1,-1,-1
#define basename_BDK_NIC_VNICX_RSS_CFG(...) "NIC_VNICX_RSS_CFG"


/**
 * NCB - nic_vnic#_rss_key#
 */
typedef union bdk_nic_vnicx_rss_keyx {
	uint64_t u;
	struct bdk_nic_vnicx_rss_keyx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t key                         : 64; /**< R/W - Eight bytes of 320-bit key for RSS hashing. Software must set this to a random
                                                                 secret value shared with the driver. If bidirectional flows are desired to land
                                                                 on the same queue then the key must be selected to have the 32 bits that start
                                                                 at the IP/port source key position match the 32 bits at the IP/port destination
                                                                 key position. */
#else
		uint64_t key                         : 64;
#endif
	} s;
	/* struct bdk_nic_vnicx_rss_keyx_s    cn88xx; */
	/* struct bdk_nic_vnicx_rss_keyx_s    cn88xxp1; */
} bdk_nic_vnicx_rss_keyx_t;

static inline uint64_t BDK_NIC_VNICX_RSS_KEYX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VNICX_RSS_KEYX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 4)))
		return 0x00008430A0002200ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_VNICX_RSS_KEYX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VNICX_RSS_KEYX(...) bdk_nic_vnicx_rss_keyx_t
#define bustype_BDK_NIC_VNICX_RSS_KEYX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VNICX_RSS_KEYX(p1,p2) (p1)
#define arguments_BDK_NIC_VNICX_RSS_KEYX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VNICX_RSS_KEYX(...) "NIC_VNICX_RSS_KEYX"


/**
 * NCB - nic_vnic#_rx_stat#
 *
 * The second dimension indicates which statistic, and is enumerated by NIC_STAT_VNIC_RX_E.
 *
 */
typedef union bdk_nic_vnicx_rx_statx {
	uint64_t u;
	struct bdk_nic_vnicx_rx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< RO/H - Statistic value. See also NIC_PF_VNIC()_RX_STAT() for a writable alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_vnicx_rx_statx_s    cn88xx; */
	/* struct bdk_nic_vnicx_rx_statx_s    cn88xxp1; */
} bdk_nic_vnicx_rx_statx_t;

static inline uint64_t BDK_NIC_VNICX_RX_STATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VNICX_RX_STATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 13)))
		return 0x00008430A0004100ull + (param1 & 127) * 0x200000ull + (param2 & 15) * 0x8ull;
	csr_fatal("BDK_NIC_VNICX_RX_STATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VNICX_RX_STATX(...) bdk_nic_vnicx_rx_statx_t
#define bustype_BDK_NIC_VNICX_RX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VNICX_RX_STATX(p1,p2) (p1)
#define arguments_BDK_NIC_VNICX_RX_STATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VNICX_RX_STATX(...) "NIC_VNICX_RX_STATX"


/**
 * NCB - nic_vnic#_tx_stat#
 *
 * The second dimension indicates which statistic, and is enumerated by NIC_STAT_VNIC_TX_E.
 *
 */
typedef union bdk_nic_vnicx_tx_statx {
	uint64_t u;
	struct bdk_nic_vnicx_tx_statx_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t reserved_48_63              : 16;
		uint64_t stat                        : 48; /**< RO/H - Statistic value. See also NIC_PF_VNIC()_TX_STAT() for a writable alias of this field. */
#else
		uint64_t stat                        : 48;
		uint64_t reserved_48_63              : 16;
#endif
	} s;
	/* struct bdk_nic_vnicx_tx_statx_s    cn88xx; */
	/* struct bdk_nic_vnicx_tx_statx_s    cn88xxp1; */
} bdk_nic_vnicx_tx_statx_t;

static inline uint64_t BDK_NIC_VNICX_TX_STATX(unsigned long param1, unsigned long param2) __attribute__ ((pure, always_inline));
static inline uint64_t BDK_NIC_VNICX_TX_STATX(unsigned long param1, unsigned long param2)
{
	if (((param1 <= 127)) && ((param2 <= 4)))
		return 0x00008430A0004000ull + (param1 & 127) * 0x200000ull + (param2 & 7) * 0x8ull;
	csr_fatal("BDK_NIC_VNICX_TX_STATX", 2, param1, param2, 0, 0); /* No return */
}
#define typedef_BDK_NIC_VNICX_TX_STATX(...) bdk_nic_vnicx_tx_statx_t
#define bustype_BDK_NIC_VNICX_TX_STATX(...) BDK_CSR_TYPE_NCB
#define busnum_BDK_NIC_VNICX_TX_STATX(p1,p2) (p1)
#define arguments_BDK_NIC_VNICX_TX_STATX(p1,p2) (p1),(p2),-1,-1
#define basename_BDK_NIC_VNICX_TX_STATX(...) "NIC_VNICX_TX_STATX"

#endif /* __BDK_CSRS_NIC__ */

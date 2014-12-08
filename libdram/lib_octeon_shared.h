/***********************license start************************************
 * Copyright (c) 2004-2007 Cavium Inc. (support@cavium.com). All rights
 * reserved.
 *
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     * Neither the name of Cavium Inc. nor the names of
 *       its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written
 *       permission.
 *
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
 * AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS
 * OR WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH
 * RESPECT TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
 * REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
 * DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
 * OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
 * PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET
 * POSSESSION OR CORRESPONDENCE TO DESCRIPTION.  THE ENTIRE RISK ARISING OUT
 * OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
 *
 *
 * For any questions regarding licensing please contact marketing@cavium.com
 *
 ***********************license end**************************************/

extern const dimm_odt_config_t disable_odt_config[];

#define rttnom_none   0         /* Rtt_Nom disabled */
#define rttnom_60ohm  1         /* RZQ/4  = 240/4  =  60 ohms */
#define rttnom_120ohm 2         /* RZQ/2  = 240/2  = 120 ohms */
#define rttnom_40ohm  3         /* RZQ/6  = 240/6  =  40 ohms */
#define rttnom_20ohm  4         /* RZQ/12 = 240/12 =  20 ohms */
#define rttnom_30ohm  5         /* RZQ/8  = 240/8  =  30 ohms */
#define rttnom_rsrv1  6         /* Reserved */
#define rttnom_rsrv2  7         /* Reserved */

#define rttwr_none    0         /* Dynamic ODT off */
#define rttwr_60ohm   1         /* RZQ/4  = 240/4  =  60 ohms */
#define rttwr_120ohm  2         /* RZQ/2  = 240/2  = 120 ohms */
#define rttwr_rsrv1   3         /* Reserved */

#define dic_40ohm     0         /* RZQ/6  = 240/6  =  40 ohms */
#define dic_34ohm     1         /* RZQ/7  = 240/7  =  34 ohms */

#define ddr4_rttnom_none   0         /* Rtt_Nom disabled */
#define ddr4_rttnom_60ohm  1         /* RZQ/4  = 240/4  =  60 ohms */
#define ddr4_rttnom_120ohm 2         /* RZQ/2  = 240/2  = 120 ohms */
#define ddr4_rttnom_40ohm  3         /* RZQ/6  = 240/6  =  40 ohms */
#define ddr4_rttnom_240ohm 4         /* RZQ/1  = 240/1  = 240 ohms */
#define ddr4_rttnom_48ohm  5         /* RZQ/5  = 240/5  =  48 ohms */
#define ddr4_rttnom_80ohm  6         /* RZQ/3  = 240/3  =  80 ohms */
#define ddr4_rttnom_34ohm  7         /* RZQ/7  = 240/7  =  34 ohms */

#define ddr4_rttwr_none    0         /* Dynamic ODT off */
#define ddr4_rttwr_120ohm  1         /* RZQ/2  = 240/2  = 120 ohms */
#define ddr4_rttwr_240ohm  2         /* RZQ/1  = 240/1  = 240 ohms */
#define ddr4_rttwr_HiZ     3         /* HiZ */

#define ddr4_dic_34ohm     0         /* RZQ/7  = 240/7  =  34 ohms */
#define ddr4_dic_48ohm     1         /* RZQ/5  = 240/5  =  48 ohms */

#define ddr4_rttpark_none   0         /* Rtt_Park disabled */
#define ddr4_rttpark_60ohm  1         /* RZQ/4  = 240/4  =  60 ohms */
#define ddr4_rttpark_120ohm 2         /* RZQ/2  = 240/2  = 120 ohms */
#define ddr4_rttpark_40ohm  3         /* RZQ/6  = 240/6  =  40 ohms */
#define ddr4_rttpark_240ohm 4         /* RZQ/1  = 240/1  = 240 ohms */
#define ddr4_rttpark_48ohm  5         /* RZQ/5  = 240/5  =  48 ohms */
#define ddr4_rttpark_80ohm  6         /* RZQ/3  = 240/3  =  80 ohms */
#define ddr4_rttpark_34ohm  7         /* RZQ/7  = 240/7  =  34 ohms */


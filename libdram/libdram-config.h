/***********************license start************************************
 * Copyright (c) 2004-2011 Cavium Inc. (support@cavium.com). All rights
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
#ifndef __LIBDRAM_CONFIG_H__
#define __LIBDRAM_CONFIG_H__

/* Structure that provides DIMM information, either in the form of an SPD TWSI address,
** or a pointer to an array that contains SPD data.  One of the two fields must be valid. */
typedef struct {
    uint16_t spd_addrs[2];  /* TWSI address of SPD, 0 if not used */
    uint8_t *spd_ptrs[2];   /* pointer to SPD data array, NULL if not used */
} dimm_config_t;

typedef struct {
    uint8_t odt_ena;
    uint64_t odt_mask;
    bdk_lmcx_modereg_params1_t odt_mask1;
    uint8_t qs_dic;
    uint64_t rodt_ctl;
    uint8_t dic;
} dimm_odt_config_t;

typedef struct {
    uint32_t ddr_board_delay;
    uint8_t lmc_delay_clk;
    uint8_t lmc_delay_cmd;
    uint8_t lmc_delay_dq;
} ddr_delay_config_t;

/*
  The parameters below make up the custom_lmc_config data structure.
  This structure is used to customize the way that the LMC DRAM
  Controller is configured for a particular board design.

  The HRM describes LMC Read Leveling which supports automatic
  selection of per byte-lane delays.  When measuring the read delays
  the LMC configuration software sweeps through a range of settings
  for LMC0_COMP_CTL2[RODT_CTL], the Octeon II on-die-termination
  resistance and LMC0_MODEREG_PARAMS1[RTT_NOM_XX], the DRAM
  on-die-termination resistance.  The minimum and maximum parameters
  for rtt_nom_idx and rodt_ctl listed below determine the ranges of
  ODT settings used for the measurements.  Note that for rtt_nom an
  index is used into a sorted table rather than the direct csr setting
  in order to optimize the sweep.

   .min_rtt_nom_idx: 1=120ohms, 2=60ohms, 3=40ohms, 4=30ohms, 5=20ohms
   .max_rtt_nom_idx: 1=120ohms, 2=60ohms, 3=40ohms, 4=30ohms, 5=20ohms
   .min_rodt_ctl: 1=20ohms, 2=30ohms, 3=40ohms, 4=60ohms, 5=120ohms
   .max_rodt_ctl: 1=20ohms, 2=30ohms, 3=40ohms, 4=60ohms, 5=120ohms

   The settings below control the Octeon II drive strength for the CK,
   ADD/CMD, and DQ/DQS signals.  1=24ohms, 2=26.67ohms, 3=30ohms,
   4=34.3ohms, 5=40ohms, 6=48ohms, 6=60ohms.

   .dqx_ctl: Drive strength control for DDR_DQX/DDR_DQS_X_P/N drivers.
   .ck_ctl: Drive strength control for DDR_CK_X_P/DDR_DIMMX_CSX_L/DDR_DIMMX_ODT_X drivers.
   .cmd_ctl: Drive strength control for CMD/A/RESET_L/CKEX drivers.

   The LMC controller software selects the most optimal CAS Latency
   that complies with the appropriate SPD values and the frequency
   that the DRAMS are being operated.  When operating the DRAMs at
   frequencies substantially lower than their rated frequencies it
   might be necessary to limit the minimum CAS Latency the LMC
   controller software is allowed to select in order to make the DRAM
   work reliably.

   .min_cas_latency: Minimum allowed CAS Latency


   The value used for LMC0_RLEVEL_CTL[OFFSET_EN] determine how the
   read-leveling information that the Octeon II gathers is interpreted
   to determine the per-byte read delays.

   .offset_en: Value used for LMC0_RLEVEL_CTL[OFFSET_EN].
   .offset_udimm: Value used for LMC0_RLEVEL_CTL[OFFSET] for UDIMMS.
   .offset_rdimm: Value used for LMC0_RLEVEL_CTL[OFFSET] for RDIMMS.


   The LMC configuration software sweeps through a range of ODT
   settings while measuring the per-byte read delays.  During those
   measurements the software makes an assessment of the quality of the
   measurements in order to determine which measurements provide the
   most accurate delays.  The automatic settings provide the option to
   allow that same assessment to determine the most optimal RODT_CTL
   and/or RTT_NOM settings.

   The automatic approach might provide the best means to determine
   the settings used for initial poweron of a new design.  However,
   the final settings should be determined by board analysis, testing,
   and experience.

   .ddr_rtt_nom_auto: 1 means automatically set RTT_NOM value.
   .ddr_rodt_ctl_auto: 1 means automatically set RODT_CTL value.

   .rlevel_compute: Enables software interpretation of per-byte read
                    delays using the measurements collected by the
                    Octeon II rather than completely relying on the
                    Octeon II to determine the delays.  1=software
                    computation is recomended since a more complete
                    analysis is implemented in software.

   .rlevel_comp_offset: Set to 2 unless instructed differently by Cavium.

   .rlevel_average_loops: Determines the number of times the read-leveling
   			  sequence is run for each rank.  The results is
                          then averaged across the number of loops. The
                          default setting is 1.

   .ddr2t_udimm:
   .ddr2t_rdimm: Turn on the DDR 2T mode. 2-cycle window for CMD and
                 address. This mode helps relieve setup time pressure
                 on the address and command bus. Please refer to
                 Micron's tech note tn_47_01 titled DDR2-533 Memory
                 Design Guide for Two Dimm Unbuffered Systems for
                 physical details.

   .disable_sequential_delay_check: As result of the flyby topology
   	prescribed in the JEDEC specifications the byte delays should
   	maintain a consistent increasing or decreasing trend across
   	the bytes on standard dimms.  This setting can be used disable
   	that check for unusual circumstances where the check is not
   	useful.

   .maximum_adjacent_rlevel_delay_increment: An additional sequential
  	delay check for the delays that result from the flyby
  	topology. This value specifies the maximum difference between
  	the delays of adjacent bytes.  A value of 0 disables this
  	check.

    .fprch2 Front Porch Enable: When set, the turn-off               
        time for the default DDR_DQ/DQS drivers is FPRCH2 CKs earlier.
        00 = 0 CKs
        01 = 1 CKs
        10 = 2 CKs

   .parity: The parity input signal PAR_IN on each dimm must be
            strapped high or low on the board.  This bit is programmed
            into LMC0_DIMM_CTL[PARITY] and it must be set to match the
            board strapping.  This signal is typically strapped low.

    .mode32b: Enable 32-bit datapath mode.  Set to 1 if only 32 DQ pins
    	      are used. (cn61xx, cn71xx)

    .dll_write_offset: FIXME: Add description
    .dll_read_offset:  FIXME: Add description
  */

typedef struct {
    uint8_t min_rtt_nom_idx;
    uint8_t max_rtt_nom_idx;
    uint8_t min_rodt_ctl;
    uint8_t max_rodt_ctl;
    uint8_t dqx_ctl;
    uint8_t ck_ctl;
    uint8_t cmd_ctl;
    uint8_t ctl_ctl;
    uint8_t min_cas_latency;
    uint8_t offset_en;
    uint8_t offset_udimm;
    uint8_t offset_rdimm;
    uint8_t rlevel_compute;
    uint8_t ddr_rtt_nom_auto;
    uint8_t ddr_rodt_ctl_auto;
    uint8_t rlevel_comp_offset_udimm;
    uint8_t rlevel_comp_offset_rdimm;
    uint8_t rlevel_average_loops;
    uint8_t ddr2t_udimm;
    uint8_t ddr2t_rdimm;
    uint8_t disable_sequential_delay_check;
    uint8_t maximum_adjacent_rlevel_delay_increment;
    uint8_t parity;
    uint8_t fprch2;
    uint8_t mode32b;
    int8_t dll_write_offset[9];
    int8_t dll_read_offset [9];
} ddr3_custom_config_t;

#define DDR_CFG_T_MAX_DIMMS     5
typedef struct {
    dimm_config_t dimm_config_table[DDR_CFG_T_MAX_DIMMS];
    dimm_odt_config_t odt_1rank_config[4];
    dimm_odt_config_t odt_2rank_config[4];
    dimm_odt_config_t odt_4rank_config[4];
    ddr_delay_config_t unbuffered;
    ddr_delay_config_t registered;
    ddr3_custom_config_t custom_lmc_config;
} ddr_configuration_t;


typedef struct
{
    ddr_configuration_t ddr_config[4];  /* One config for each interface */
} ddr_config_table_t;


extern int libdram_config(int node, const ddr_configuration_t *ddr_config, int ddr_clock_hertz);

#endif  /* __LIBDRAM_CONFIG_H__ */

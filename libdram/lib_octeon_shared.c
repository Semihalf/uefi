/***********************license start************************************
 * Copyright (c) 2004-2014 Cavium Inc. (support@cavium.com). All rights
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

/* $Revision: 102369 $ */

#include <bdk.h>
#include "dram-internal.h"

/* Define DDR_DEBUG to debug the DDR interface.  This also enables the
** output necessary for review by Cavium Inc., Inc. */
/* #define DDR_DEBUG */


static int global_ddr_clock_initialized = 0;
static int global_ddr_memory_preserved  = 0;

/*
 * SDRAM Physical Address (figure 6-2 from the HRM)
 *                                                                   7 6    3 2   0
 * +---------+----+----------------------+---------------+--------+---+------+-----+
 * |  Dimm   |Rank|         Row          |      Col      |  Bank  | C |  Col | Bus |
 * +---------+----+----------------------+---------------+--------+---+------+-----+
 *     |    ^   |            |          ^        |           |      |
 *   0 or 1 |   |       12-18 bits      |      6-8 bits      |    1 or 2 bits
 *    bit   | 0 or 1 bit           LMC_CONFIG[ROW_LSB]+X     |    (X=1 or 2, resp)
 *          |                                                |
 *   LMC_CONFIG[PBANK_LSB]+X                               3 or 4 bits
 *
 *    Bus     = Selects the byte on the 72-bit DDR3 bus
 *    Col     = Column Address for the memory part (10-12 bits)
 *    C       = Selects the LMC that services the reference
 *              (2 bits for 4 LMC mode, 1 bit for 2 LMC mode; X=width)
 *    Bank    = Bank Address for the memory part (DDR3=3 bits, DDR4=3 or 4 bits)
 *    Row     = Row Address for the memory part (12-18 bits)
 *    Rank    = Optional Rank Address for dual-rank DIMMs
 *              (present when LMC_CONFIG[RANK_ENA] is set)
 *    Dimm    = Optional DIMM address (preseent with more than 1 DIMM)
 */


/* Sometimes the pass/fail results for all possible delay settings
 * determined by the read-leveling sequence is too forgiving.  This
 * usually occurs for DCLK speeds below 300 MHz. As a result the
 * passing range is exaggerated. This function accepts the bitmask
 * results from the sequence and truncates the passing range to a
 * reasonable range and recomputes the proper deskew setting.
 */

/* Default ODT config must disable ODT */
/* Must be const (read only) so that the structure is in flash */
const dimm_odt_config_t disable_odt_config[] = {
	/* DDR4 needs an additional field in the struct (odt_mask2) */
	/* DIMMS   ODT_ENA ODT_MASK   ODT_MASK1      ODT_MASK2     QS_DIC RODT_CTL DIC */
	/* =====   ======= ========   =========      =========     ====== ======== === */
	/*   1 */ {   0,    0x0000,   {.u = 0x0000}, {.u = 0x0000},    0,   0x0000,  0  },
	/*   2 */ {   0,    0x0000,   {.u = 0x0000}, {.u = 0x0000},    0,   0x0000,  0  },
	/*   3 */ {   0,    0x0000,   {.u = 0x0000}, {.u = 0x0000},    0,   0x0000,  0  },
	/*   4 */ {   0,    0x0000,   {.u = 0x0000}, {.u = 0x0000},    0,   0x0000,  0  },
};
/* Memory controller setup function */
static int init_octeon_dram_interface(bdk_node_t node,
				      const ddr_configuration_t *ddr_configuration,
				      uint32_t ddr_hertz,
				      uint32_t cpu_hertz,
				      uint32_t ddr_ref_hertz,
				      int board_type,
				      int board_rev_maj,
				      int board_rev_min,
				      int ddr_interface_num,
				      uint32_t ddr_interface_mask)
{
    uint32_t mem_size_mbytes = 0;

    const char *s;
    if ((s = lookup_env_parameter("ddr_timing_hertz")) != NULL)
	ddr_hertz = strtoul(s, NULL, 0);

    mem_size_mbytes = init_octeon3_ddr3_interface(node,
						  ddr_configuration,
						  ddr_hertz,
						  cpu_hertz,
						  ddr_ref_hertz,
						  board_type,
						  board_rev_maj,
						  board_rev_min,
						  ddr_interface_num,
						  ddr_interface_mask);
    ddr_print("LMC%d Configuration Completed: %d MB\n",
	      ddr_interface_num, mem_size_mbytes);
    return mem_size_mbytes;
}

int test_dram_byte(uint64_t p, int count, int byte, uint64_t bitmask)
{
    uint64_t p1, p2, d1, d2;
    uint64_t i, j, k;
    int errors = 0;
    int counter;
    uint64_t v, v1;
    uint64_t p2offset = 0x4000000;

    /* Add offset to both test regions to not clobber u-boot stuff
     * when running from L2 for NAND boot.
     */
    p += 0x4000000;

    counter = 0;
    for (k = 0; k < (1 << 18); k += (1 << 14)) {
	for (i = 0; i < (1 << 7); i += 8) {
	    for (j = 0; j < (1 << 12); j += (1 << 9)) {
		p1 = p + i + j + k;
		p2 = p1 + p2offset;
		v = (~((uint64_t)counter) & 0xff) << (8 * byte);
		v1 = ~v;

		/* test_dram_byte_print("[0x%016llX]: 0x%016llX, [0x%016llX]: 0x%016llX\n",
		 *            p1, v, p2, v1);
		 */

		bdk_write64_uint64(p1, v);
		BDK_CACHE_WBI_L2(p1);
		bdk_write64_uint64(p2, v1);
		BDK_CACHE_WBI_L2(p2);
		++counter;
	    }
	}
    }

    counter = 0;

    /* Walk through a range of addresses avoiding bits that alias
     * interfaces on the CN68XX.
     */
    for (k = 0; k < (1 << 18); k += (1 << 14)) {
	for (i = 0; i < (1 << 7); i += 8) {
	    for (j = 0; j < (1 << 12); j += (1 << 9)) {
		p1 = p + i + j + k;
		p2 = p1 + p2offset;
		v = (~((uint64_t)counter) & bitmask) << (8 * byte);
		/*v = (~((uint64_t)counter) & 0xff) << (8 * byte) & (bitmask << 8 * byte);*/
		d1 = bdk_read64_uint64(p1);
		d1 &= (bitmask << 8 * byte);
		d2 = ~bdk_read64_uint64(p2);
		d2 &= (bitmask << 8 * byte);

		/* test_dram_byte_print("[0x%016llX]: 0x%016llX, [0x%016llX]: 0x%016llX\n",
		 *             p1, d1, p2, d2);
		 */

		if (d1 != v) {
		    ++errors;
		    debug_print("%d: [0x%016llX] 0x%016llX expected 0x%016llX xor %016llX\n",
				errors, p1, d1, v, (d1 ^ v));
		    return errors;      /* Quit on first error */
		}
		if (d2 != v) {
		    ++errors;
		    debug_print("%d: [0x%016llX] 0x%016llX  expected 0x%016llX xor %016llX\n",
				errors, p2, d2, v, (d2 ^ v));
		    return errors;      /* Quit on first error */
		}
		++counter;
	    }
	}
    }
    return errors;
}

static void set_ddr_memory_preserved(bdk_node_t node)
{
    global_ddr_memory_preserved |= 0x1 << node;

}
static int ddr_memory_preserved(bdk_node_t node)
{
    return (global_ddr_memory_preserved & (0x1 << node)) != 0;
}

void perform_ddr3_init_sequence(bdk_node_t node, int rank_mask,
				       int ddr_interface_num)
{
    const char *s;
    int ddr_init_loops = 1;

    if ((s = lookup_env_parameter("ddr%d_init_loops", ddr_interface_num)) != NULL)
	ddr_init_loops = strtoul(s, NULL, 0);

    while (ddr_init_loops--) {
	if (ddr_memory_preserved(node)) {
	    /* Contents are being preserved */
	    perform_octeon3_ddr3_sequence(node, rank_mask,
                                          ddr_interface_num, 3); /* self-refresh exit */
	} else {
	    /* Contents are not being preserved */
	    perform_octeon3_ddr3_sequence(node, rank_mask,
                                          ddr_interface_num, 0); /* power-up/init */
	}

	bdk_wait_usec(1000);   /* Wait a while. */

	if ((s = lookup_env_parameter("ddr_sequence1")) != NULL) {
	    int sequence1;
	    sequence1 = strtoul(s, NULL, 0);
	    perform_octeon3_ddr3_sequence(node, rank_mask,
					  ddr_interface_num, sequence1);
	}

	if ((s = lookup_env_parameter("ddr_sequence2")) != NULL) {
	    int sequence2;
	    sequence2 = strtoul(s, NULL, 0);
	    perform_octeon3_ddr3_sequence(node, rank_mask,
					  ddr_interface_num, sequence2);
	}
    }
}

static void set_ddr_clock_initialized(bdk_node_t node, int ddr_interface, int inited_flag)
{
	int bit = node * 8 + ddr_interface;
	if (inited_flag)
		global_ddr_clock_initialized |= (0x1 << bit);
	else
		global_ddr_clock_initialized &= ~(0x1 << bit);
}
static int ddr_clock_initialized(bdk_node_t node, int ddr_interface)
{
	int bit = node * 8 + ddr_interface;
	return (!!(global_ddr_clock_initialized & (0x1 << bit)));
}


static void cn78xx_lmc_dreset_init (bdk_node_t node, int ddr_interface_num)
{
        /*
	 * This is the embodiment of the 6.9.4 LMC DRESET Initialization section below.
	 *
         * The remainder of this section describes the sequence for LMCn.
         *
         * 1. If not done already, write LMC(0..3)_DLL_CTL2 to its reset value
         *    (except without changing the LMC(0..3)_DLL_CTL2[INTF_EN] value from
         *    that set in the prior Step 3), including LMC(0..3)_DLL_CTL2[DRESET] = 1.
         *
         * 2. Without changing any other LMC(0..3)_DLL_CTL2 fields, write
         *    LMC(0..3)_DLL_CTL2[DLL_BRINGUP] = 1.
         */

        DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL2(ddr_interface_num),
			c.s.dll_bringup = 1);

        /*
         * 3. Read LMC(0..3)_DLL_CTL2 and wait for the result.
         */

        BDK_CSR_READ(node, BDK_LMCX_DLL_CTL2(ddr_interface_num));

        /*
         * 4. Wait for a minimum of 10 LMC CK cycles.
         */

        bdk_wait_usec(1);

        /*
         * 5. Without changing any other fields in LMC(0..3)_DLL_CTL2, write
         *    LMC(0..3)_DLL_CTL2[QUAD_DLL_ENA] = 1.
         *    LMC(0..3)_DLL_CTL2[QUAD_DLL_ENA] must not change after this point
         *    without restarting the LMCn DRESET initialization sequence.
         */

        DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL2(ddr_interface_num),
			c.s.quad_dll_ena = 1);

        /*
         * 6. Read LMC(0..3)_DLL_CTL2 and wait for the result.
         */

        BDK_CSR_READ(node, BDK_LMCX_DLL_CTL2(ddr_interface_num));

        /*
         * 7. Wait a minimum of 10 us.
         */

        bdk_wait_usec(10);

        /*
         * 8. Without changing any other fields in LMC(0..3)_DLL_CTL2, write
         *    LMC(0..3)_DLL_CTL2[DLL_BRINGUP] = 0.
         *    LMC(0..3)_DLL_CTL2[DLL_BRINGUP] must not change after this point
         *    without restarting the LMCn DRESET initialization sequence.
         */

        DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL2(ddr_interface_num),
			c.s.dll_bringup = 0);

        /*
         * 9. Read LMC(0..3)_DLL_CTL2 and wait for the result.
         */

        BDK_CSR_READ(node, BDK_LMCX_DLL_CTL2(ddr_interface_num));

        /*
         * 10. Without changing any other fields in LMC(0..3)_DLL_CTL2, write
         *    LMC(0..3)_DLL_CTL2[DRESET] = 0.
         *    LMC(0..3)_DLL_CTL2[DRESET] must not change after this point without
         *    restarting the LMCn DRESET initialization sequence.
         *
         *    After completing LMCn DRESET initialization, all LMC CSRs may be
         *    accessed.  Prior to completing LMC DRESET initialization, only
         *    LMC(0..3)_DDR_PLL_CTL, LMC(0..3)_DLL_CTL2, LMC(0..3)_RESET_CTL, and
         *    LMC(0..3)_COMP_CTL2 LMC CSRs can be accessed.
         */

        DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL2(ddr_interface_num),
			c.s.dreset = 0);
}


int initialize_ddr_clock(bdk_node_t node,
			 const ddr_configuration_t *ddr_configuration,
                         uint32_t cpu_hertz,
                         uint32_t ddr_hertz,
                         uint32_t ddr_ref_hertz,
                         int ddr_interface_num,
                         uint32_t ddr_interface_mask
                         )
{
    const char *s;

    if (ddr_clock_initialized(node, ddr_interface_num))
        return 0;

    if (!ddr_clock_initialized(node, 0)) { /* Do this once */
        int i;
        bdk_lmcx_reset_ctl_t reset_ctl;
        /* Check to see if memory is to be preserved and set global flag */
        for (i=3; i>=0; --i) {
            if ((ddr_interface_mask & (1 << i)) == 0)
                continue;
            reset_ctl.u = BDK_CSR_READ(node, BDK_LMCX_RESET_CTL(i));
            if (reset_ctl.s.ddr3psv == 1) {
                ddr_print("LMC%d Preserving memory\n", i);
                set_ddr_memory_preserved(node);

                /* Re-initialize flags */
                reset_ctl.s.ddr3pwarm = 0;
                reset_ctl.s.ddr3psoft = 0;
                reset_ctl.s.ddr3psv   = 0;
                DRAM_CSR_WRITE(node, BDK_LMCX_RESET_CTL(i), reset_ctl.u);
            }
        }
    }

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX)) {

        bdk_lmcx_ddr_pll_ctl_t ddr_pll_ctl;
        const dimm_config_t *dimm_config_table = ddr_configuration->dimm_config_table;
        int ddr_type;

        /* ddr_type only indicates DDR4 or DDR3 */
        ddr_type = (read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_KEY_BYTE_DEVICE_TYPE) == 0x0C)
	    ? DDR4_DRAM : DDR3_DRAM;

        /*
         * 6.9 LMC Initialization Sequence
         *
         * There are 14 parts to the LMC initialization procedure:
         *
         * 1. LMC interface enable initialization
         *
         * 2. DDR PLL initialization
         *
         * 3. LMC CK initialization
         *
         * 4. LMC DRESET initialization
         *
         * 5. LMC CK local initialization
         *
         * 6. LMC RESET initialization
         *
         * 7. Early LMC initialization
         *
         * 8. LMC offset training
         *
         * 9. LMC internal Vref training
         *
         * 10. LMC deskew training
         *
         * 11. LMC write leveling
         *
         * 12. LMC read leveling
         *
         * 13. DRAM Vref Training for DDR4
	 *
         * 14. Final LMC initialization	 
         *
         * CN88XX supports two modes:
         *
         * ­ two-LMC mode: both LMCs 2/3 must not be enabled
         *   (LMC2/3_DLL_CTL2[DRESET] must be set to 1 and LMC2/3_DLL_CTL2[INTF_EN]
         *   must be set to 0) and both LMCs 0/1 must be enabled).
         *
         * ­ four-LMC mode: all four LMCs 0..3 must be enabled.
         *
         * Steps 4 and 6..14 should each be performed for each enabled LMC (either
         * twice or four times). Steps 1..3 and 5 are more global in nature and
         * each must be executed exactly once (not once per LMC) each time the
         *  DDR PLL changes or is first brought up. Steps 1..3 and 5 need not be
         * performed if the DDR PLL is stable.
         *
         * Generally, the steps are performed in order. The exception is that the
         * CK local initialization (step 5) must be performed after some DRESET
         * initializations (step 4) and before other DRESET initializations when
         * the DDR PLL is brought up or changed. (The CK local initialization
         * uses information from some LMCs to bring up the other local CKs.) The
         * following text describes these ordering requirements in more detail.
         *
         * Following any chip reset, the DDR PLL must be brought up, and all 14
         * steps should be executed. Subsequently, it is possible to execute only
         * steps 4 and 6..14, or to execute only steps 8..14.
         *
         * The remainder of this section covers these initialization steps in
         * sequence.
         */

        if (ddr_interface_num == 0) { /* Do this once */
            bdk_lmcx_dll_ctl2_t	dll_ctl2;
            int loop_interface_num;

            /*
             * 6.9.1 LMC Interface-Enable Initialization
             *
             * LMC interface-enable initialization (Step 1) must be performed only
             * once, not once per LMC in four-LMC mode. This step is not required
	     * in two-LMC mode.
	     *
             * Perform the following three substeps for the LMC interface-enable
             * initialization:
             *
             * 1. Without changing any other LMC2_DLL_CTL2 fields (LMC(0..3)_DLL_CTL2
             *    should be at their reset values after Step 1), write
             *    LMC2_DLL_CTL2[INTF_EN] = 1 if four-LMC mode is desired.
             *
             * 2. Without changing any other LMC3_DLL_CTL2 fields, write
             *    LMC3_DLL_CTL2[INTF_EN] = 1 if four-LMC mode is desired.
             *
             * 3. Read LMC2_DLL_CTL2 and wait for the result.
             *
             * The LMC2_DLL_CTL2[INTF_EN] and LMC3_DLL_CTL2[INTF_EN] values should
             * not be changed by software from this point.
             *
             */

	    /* Put all LMCs into DRESET here */
            for (loop_interface_num = 0; loop_interface_num < 4; ++loop_interface_num) {

                dll_ctl2.u = 0;

                dll_ctl2.s.byp_setting          = 0;
                dll_ctl2.s.byp_sel              = 0;
                dll_ctl2.s.quad_dll_ena         = 0;
                dll_ctl2.s.dreset               = 1;
                dll_ctl2.s.dll_bringup          = 0;
                dll_ctl2.s.intf_en              = 0;

                DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL2(loop_interface_num), dll_ctl2.u);
            }

	    /* Now set INTF_EN for *ONLY* LMC2/3 if they are to be active */
	    /* Do *NOT* touch LMC0/1 INTF_EN setting */
            for (loop_interface_num = 2; loop_interface_num < 4; ++loop_interface_num) {
                if ((ddr_interface_mask & (1 << loop_interface_num)) == 0)
                    continue;

                DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL2(loop_interface_num),
				c.s.intf_en = 1);
                BDK_CSR_READ(node, BDK_LMCX_DLL_CTL2(loop_interface_num));
            }

            /*
             * 6.9.2 DDR PLL Initialization
             *
             * DDR PLL initialization (Step 2) must be performed for each chip reset
             * and whenever the DDR clock speed changes. This step needs to be
             * performed only once, not once per LMC.
             *
             * Perform the following eight substeps to initialize the DDR PLL:
             *
             * 1. If not done already, write all fields in LMC(0..1)_DDR_PLL_CTL and
             *    LMC(0..1)_DLL_CTL2 to their reset values, including:
             *
             * .. LMC0_DDR_PLL_CTL[DDR_DIV_RESET] = 1
             * .. LMC0_DLL_CTL2[DRESET] = 1
             *
             * This substep is not necessary after a chip reset.
             *
             */

            ddr_pll_ctl.u	= 0;

            ddr_pll_ctl.s.clkf              = 0x30;
            ddr_pll_ctl.s.reset_n           = 0;
            ddr_pll_ctl.s.clkf_ext          = 0;
            ddr_pll_ctl.s.ddr_ps_en         = 2;
            ddr_pll_ctl.s.ddr_div_reset     = 1;
            ddr_pll_ctl.s.jtg_test_mode     = 0;
            ddr_pll_ctl.s.clkr              = 0;
            ddr_pll_ctl.s.pll_rfslip        = 0;
            ddr_pll_ctl.s.pll_lock          = 0;
            ddr_pll_ctl.s.pll_fbslip        = 0;
            ddr_pll_ctl.s.ddr4_mode         = 0;
            ddr_pll_ctl.s.phy_dcok          = 0;
            ddr_pll_ctl.s.dclk_invert       = 1;
            ddr_pll_ctl.s.bwadj             = 0x18;
            ddr_pll_ctl.s.dclk_alt_refclk_sel = 0;

            if ((s = lookup_env_parameter("ddr_pll_bwadj")) != NULL) {
                ddr_pll_ctl.s.bwadj = strtoul(s, NULL, 0);
            }

            DRAM_CSR_WRITE(node, BDK_LMCX_DDR_PLL_CTL(0), ddr_pll_ctl.u);
            DRAM_CSR_WRITE(node, BDK_LMCX_DDR_PLL_CTL(1), ddr_pll_ctl.u);


            /*
             * 2. If the current DRAM contents are not preserved (see
             *    LMC(0..3)_RESET_ CTL[DDR3PSV]), this is also an appropriate time to
             *    assert the RESET# pin of the DDR3/DDR4 DRAM parts. If desired, write
             *    LMC0_RESET_ CTL[DDR3RST] = 0 without modifying any other
             *    LMC0_RESET_CTL fields to assert the DDR_RESET_L pin. No action is
             *    required here to assert DDR_RESET_L following a chip reset. Refer to
             *    Section 6.9.6. Do this for all enabled LMCs.
             */

            for (loop_interface_num = 0;
                 ( !ddr_memory_preserved(node)) && loop_interface_num < 4;
                 ++loop_interface_num) {
                bdk_lmcx_reset_ctl_t reset_ctl;

                if ((ddr_interface_mask & (1 << loop_interface_num)) == 0)
                    continue;

                reset_ctl.u = BDK_CSR_READ(node, BDK_LMCX_RESET_CTL(loop_interface_num));
                reset_ctl.s.ddr3rst = 0; /* Reset asserted */
                ddr_print("LMC%d Asserting DDR_RESET_L\n", loop_interface_num);
                DRAM_CSR_WRITE(node, BDK_LMCX_RESET_CTL(loop_interface_num), reset_ctl.u);
                BDK_CSR_READ(node, BDK_LMCX_RESET_CTL(loop_interface_num));
            }

            /*
             * 3. Without changing any other LMC0_DDR_PLL_CTL values, write LMC0_DDR_
             *    PLL_CTL[CLKF] with a value that gives a desired DDR PLL speed. The
             *    LMC0_DDR_PLL_CTL[CLKF] value should be selected in conjunction with
             *    the post-scalar divider values for LMC (LMC0_DDR_PLL_CTL[DDR_PS_EN])
             *    so that the desired LMC CK speeds are is produced (all enabled LMCs
             *    must run the same speed). Section 5.14 describes
             *    LMC0_DDR_PLL_CTL[CLKF] and LMC0_DDR_PLL_CTL[DDR_PS_EN] programmings
             *    that produce the desired LMC CK speed. Section 6.9.3 describes LMC CK
             *    initialization, which can be done separately from the DDR PLL
             *    initialization described in this section.
             *
             * The LMC0_DDR_PLL_CTL[CLKF] value must not change after this point
             * without restarting this SDRAM PLL initialization sequence.
             */

            {
                /* CLKF = (DCLK * (CLKR+1) * EN(1, 2, 3, 4, 5, 6, 7, 8, 10, 12))/DREF - 1 */
                int en_idx, save_en_idx, best_en_idx=0;
                uint64_t clkf, clkr, max_clkf = 127;
                uint64_t best_clkf=0, best_clkr=0;
                uint64_t best_pll_MHz = 0;
                uint64_t pll_MHz;
                uint64_t min_pll_MHz = 800;
                uint64_t max_pll_MHz = 5000;
                uint64_t error;
                uint64_t best_error;
                uint64_t best_calculated_ddr_hertz = 0;
                uint64_t calculated_ddr_hertz = 0;
		uint64_t orig_ddr_hertz = ddr_hertz;
                static const int _en[] = {1, 2, 3, 4, 5, 6, 7, 8, 10, 12};
                int override_pll_settings;

                error = best_error = ddr_hertz;  /* Init to max error */

                ddr_pll_ctl.u = 0;

                ddr_print("DDR Reference Hertz = %d\n", ddr_ref_hertz);

                while (best_error == ddr_hertz) {

		    for (clkr = 0; clkr < 4; ++clkr) {
			for (en_idx=sizeof(_en)/sizeof(int)-1; en_idx>=0; --en_idx) {
			    save_en_idx = en_idx;
			    clkf = ((ddr_hertz) * (clkr+1) * (_en[save_en_idx]));
			    clkf = divide_nint(clkf, ddr_ref_hertz) - 1;
			    pll_MHz = ddr_ref_hertz * (clkf+1) / (clkr+1) / 1000000;
			    calculated_ddr_hertz = ddr_ref_hertz * (clkf + 1) / ((clkr + 1) * (_en[save_en_idx]));
			    error = ddr_hertz - calculated_ddr_hertz;

			    if ((pll_MHz < min_pll_MHz) || (pll_MHz > max_pll_MHz)) continue;
			    if (clkf > max_clkf) continue; /* PLL requires clkf to be limited */
			    if (_abs(error) > _abs(best_error)) continue;

			    ddr_print("clkr: %2lu, en[%d]: %2d, clkf: %4lu, pll_MHz: %4lu, ddr_hertz: %8lu, error: %8ld\n",
				      clkr, save_en_idx, _en[save_en_idx], clkf, pll_MHz, calculated_ddr_hertz, error);

			    /* Favor the highest PLL frequency. */
			    if ((_abs(error) < _abs(best_error)) || (pll_MHz > best_pll_MHz)) {
				best_pll_MHz = pll_MHz;
				best_calculated_ddr_hertz = calculated_ddr_hertz;
				best_error = error;
				best_clkr = clkr;
				best_clkf = clkf;
				best_en_idx = save_en_idx;
			    }
			}
		    }

		    override_pll_settings = 0;

		    if ((s = lookup_env_parameter("ddr_pll_clkr")) != NULL) {
			best_clkr = strtoul(s, NULL, 0);
			override_pll_settings = 1;
		    }
		    if ((s = lookup_env_parameter("ddr_pll_clkf")) != NULL) {
			best_clkf = strtoul(s, NULL, 0);
			override_pll_settings = 1;
		    }
		    if ((s = lookup_env_parameter("ddr_pll_en_idx")) != NULL) {
			best_en_idx = strtoul(s, NULL, 0);
			override_pll_settings = 1;
		    }

		    if (override_pll_settings) {
			best_pll_MHz = ddr_ref_hertz * (clkf+1) / (clkr+1) / 1000000;
			best_calculated_ddr_hertz = ddr_ref_hertz * (clkf + 1) / ((clkr + 1) * (_en[best_en_idx]));
			best_error = ddr_hertz - calculated_ddr_hertz;
		    }

		    ddr_print("clkr: %2lu, en[%d]: %2d, clkf: %4lu, pll_MHz: %4lu, ddr_hertz: %8lu, error: %8ld <==\n",
			      best_clkr, best_en_idx, _en[best_en_idx], best_clkf, best_pll_MHz,
			      best_calculated_ddr_hertz, best_error);

		    /* Try lowering the frequency if we can't get a working configuration */
		    if (best_error == ddr_hertz) {
			if (ddr_hertz < orig_ddr_hertz - 10000000)
			    break;
			ddr_hertz -= 1000000;
			best_error = ddr_hertz;
		    }

		} /* while (best_error == ddr_hertz) */


                if (best_error == ddr_hertz) {
                    error_print("ERROR: Can not compute a legal DDR clock speed configuration.\n");
                    return(-1);
                }

                ddr_pll_ctl.s.ddr_ps_en = best_en_idx;
                ddr_pll_ctl.s.clkf = best_clkf;
                ddr_pll_ctl.s.clkr = best_clkr;
                ddr_pll_ctl.s.reset_n = 0;

                ddr_pll_ctl.s.bwadj = (best_clkf + 1) / 10;
                ddr_print("bwadj: %2d\n", ddr_pll_ctl.s.bwadj);

                if ((s = lookup_env_parameter("ddr_pll_bwadj")) != NULL) {
                    ddr_pll_ctl.s.bwadj = strtoul(s, NULL, 0);
                }

                for (loop_interface_num = 0; loop_interface_num<2; ++loop_interface_num) {
                    if ((ddr_interface_mask & (1 << loop_interface_num)) == 0)
                        continue;

                    DRAM_CSR_WRITE(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num), ddr_pll_ctl.u);
                }
            }


            for (loop_interface_num = 0; loop_interface_num<4; ++loop_interface_num) {
                if ((ddr_interface_mask & (1 << loop_interface_num)) == 0)
                    continue;

		/*
		 * 4. Read LMC0_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 5. Wait a minimum of 3 us.
		 */

		bdk_wait_usec(3);          /* Wait 3 us */

		/*
		 * 6. Write LMC0_DDR_PLL_CTL[RESET_N] = 1 without changing any other
		 *    LMC0_DDR_PLL_CTL values.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num),
				c.s.reset_n = 1);

		/*
		 * 7. Read LMC0_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 8. Wait a minimum of 25 us.
		 */

		bdk_wait_usec(25);          /* Wait 25 us */

		/*
		 * 6.9.3 LMC CK Initialization
		 *
		 * DDR PLL initialization must be completed prior to starting LMC CK
		 * initialization.
		 *
		 * Perform the following substeps to initialize the LMC CK. Perform
		 * substeps 1..3 for both LMC0 and LMC1.
		 *
		 * 1. Without changing any other LMC(0..3)_DDR_PLL_CTL values, write
		 *    LMC(0..3)_DDR_PLL_CTL[DDR_DIV_RESET] = 1 and
		 *    LMC(0..3)_DDR_PLL_CTL[DDR_PS_EN] with the appropriate value to get the
		 *    desired LMC CK speed. Section 5.14 discusses CLKF and DDR_PS_EN
		 *    programmings.  The LMC(0..3)_DDR_PLL_CTL[DDR_PS_EN] must not change
		 *    after this point without restarting this LMC CK initialization
		 *  sequence.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num),
				c.s.ddr_div_reset = 1);

		/*
		 * 2. Without changing any other fields in LMC(0..3)_DDR_PLL_CTL, write
		 *    LMC(0..3)_DDR_PLL_CTL[DDR4_MODE] = 0.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num),
				c.s.ddr4_mode = (ddr_type == DDR4_DRAM) ? 1 : 0);

		/*
		 * 3. Read LMC(0..3)_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 4. Wait a minimum of 1 us.
		 */

		bdk_wait_usec(1);          /* Wait 1 us */

		/*
		 * 5. Without changing any other fields in LMC(0..3)_DDR_PLL_CTL, write
		 *    LMC(0..3)_DDR_PLL_CTL[PHY_DCOK] = 1.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num),
				c.s.phy_dcok = 1);

		/*
		 * 6. Read LMC(0..3)_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 7. Wait a minimum of 20 us.
		 */

		bdk_wait_usec(20);          /* Wait 20 us */

		/*
		 * 8. Without changing any other LMC(0..3)_COMP_CTL2 values, write
		 *    LMC(0..3)_COMP_CTL2[CK_CTL,CONTROL_CTL,CMD_CTL] to the desired
		 *    DDR*_CK_*_P control and command signals drive strength.
		 */

		{
		    bdk_lmcx_comp_ctl2_t comp_ctl2;
		    const ddr3_custom_config_t *custom_lmc_config = &ddr_configuration->custom_lmc_config;

		    comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(loop_interface_num));

		    comp_ctl2.s.dqx_ctl  = 4; /* Default 4=34.3 ohm */
		    comp_ctl2.s.ck_ctl   =
			(custom_lmc_config->ck_ctl  == 0) ? 4 : custom_lmc_config->ck_ctl;  /* Default 4=34.3 ohm */
		    comp_ctl2.s.cmd_ctl  =
			(custom_lmc_config->cmd_ctl == 0) ? 4 : custom_lmc_config->cmd_ctl; /* Default 4=34.3 ohm */

		    comp_ctl2.s.rodt_ctl           = 0x4; /* 60 ohm */

		    if ((s = lookup_env_parameter("ddr_clk_ctl")) != NULL) {
			comp_ctl2.s.ck_ctl  = strtoul(s, NULL, 0);
		    }

		    if ((s = lookup_env_parameter("ddr_ck_ctl")) != NULL) {
			comp_ctl2.s.ck_ctl  = strtoul(s, NULL, 0);
		    }

		    if ((s = lookup_env_parameter("ddr_cmd_ctl")) != NULL) {
			comp_ctl2.s.cmd_ctl  = strtoul(s, NULL, 0);
		    }

		    if ((s = lookup_env_parameter("ddr_dqx_ctl")) != NULL) {
			comp_ctl2.s.dqx_ctl  = strtoul(s, NULL, 0);
		    }

		    DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(loop_interface_num), comp_ctl2.u);
		}

		/*
		 * 9. Read LMC(0..3)_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 10. Wait a minimum of 200 ns.
		 */

		bdk_wait_usec(1);          /* Wait 1 us */

		/*
		 * 11. Without changing any other LMC(0..3)_DDR_PLL_CTL values, write
		 *     LMC(0..3)_DDR_PLL_CTL[DDR_DIV_RESET] = 0.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num),
				c.s.ddr_div_reset = 0);

		/*
		 * 12. Read LMC(0..3)_DDR_PLL_CTL and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DDR_PLL_CTL(loop_interface_num));

		/*
		 * 13. Wait a minimum of 200 ns.
		 */
		bdk_wait_usec(1);          /* Wait 1 us */

	    } /* for (loop_interface_num = 0; loop_interface_num<4; ++loop_interface_num) */

        }  /* if (ddr_interface_num == 0) */ /* Do this once */

        if (ddr_interface_num == 0) { /* Do this once */
            bdk_lmcx_dll_ctl3_t ddr_dll_ctl3;

            /*
             * 6.9.4 LMC DRESET Initialization
             *
             * All of the DDR PLL, LMC global CK, and LMC interface enable
             * initializations must be completed prior to starting this LMC DRESET
             * initialization (Step 4).
             *
             * This LMC DRESET step is done for all enabled LMCs.
             *
             * There are special constraints on the ordering of DRESET initialization
             * (Steps 4) and CK local initialization (Step 5) whenever CK local
             * initialization must be executed.  CK local initialization must be
             * executed whenever the DDR PLL is being brought up (for each chip reset
             * and whenever the DDR clock speed changes).
             *
             * When Step 5 must be executed in the two-LMC mode case:
             * ­ LMC0 DRESET initialization must occur before Step 5.
             * ­ LMC1 DRESET initialization must occur after Step 5.
             *
             * When Step 5 must be executed in the four-LMC mode case:
             * ­ LMC2 and LMC3 DRESET initialization must occur before Step 5.
             * ­ LMC0 and LMC1 DRESET initialization must occur after Step 5.
             */

            /* TWO-LMC MODE BEFORE STEP 5 */
            if (ddr_interface_mask == 0x3) {
                cn78xx_lmc_dreset_init(node, 0);
            }

            /* FOUR-LMC MODE BEFORE STEP 5 */
            if (ddr_interface_mask == 0xf) {
                cn78xx_lmc_dreset_init(node, 2);
                cn78xx_lmc_dreset_init(node, 3);
            }

            /*
             * 6.9.5 LMC CK Local Initialization
             *
             * All of DDR PLL, LMC global CK, and LMC interface-enable
             * initializations must be completed prior to starting this LMC CK local
             * initialization (Step 5).
             *
             * LMC CK Local initialization must be performed for each chip reset and
             * whenever the DDR clock speed changes. This step needs to be performed
             * only once, not once per LMC.
             *
             * There are special constraints on the ordering of DRESET initialization
             * (Steps 4) and CK local initialization (Step 5) whenever CK local
             * initialization must be executed.  CK local initialization must be
             * executed whenever the DDR PLL is being brought up (for each chip reset
             * and whenever the DDR clock speed changes).
             *
             * When Step 5 must be executed in the two-LMC mode case:
             * ­ LMC0 DRESET initialization must occur before Step 5.
             * ­ LMC1 DRESET initialization must occur after Step 5.
             *
             * When Step 5 must be executed in the four-LMC mode case:
             * ­ LMC2 and LMC3 DRESET initialization must occur before Step 5.
             * ­ LMC0 and LMC1 DRESET initialization must occur after Step 5.
             *
             * LMC CK local initialization is different depending on whether two-LMC
             * or four-LMC modes are desired.
             */

            if (ddr_interface_mask == 0x3) {
		/*
		 * 6.9.5.1 LMC CK Local Initialization for Two-LMC Mode
		 *
		 * 1. Write LMC0_DLL_CTL3 to its reset value. (Note that
		 *    LMC0_DLL_CTL3[DLL_90_BYTE_SEL] = 0x2 .. 0x8 should also work.)
		 */

		ddr_dll_ctl3.u = 0;
		ddr_dll_ctl3.s.dclk90_recal_dis = 1;
		ddr_dll_ctl3.s.dll90_byte_sel = 1;
		DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(0),	ddr_dll_ctl3.u);

		/*
		 * 2. Read LMC0_DLL_CTL3 and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(0));

		/*
		 * 3. Without changing any other fields in LMC0_DLL_CTL3, write
		 *    LMC0_DLL_CTL3[DCLK90_FWD] = 1.  Writing LMC0_DLL_CTL3[DCLK90_FWD] = 1
		 *    causes clock-delay information to be forwarded from LMC0 to LMC1.
		 */

		ddr_dll_ctl3.s.dclk90_fwd = 1;
		DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(0),	ddr_dll_ctl3.u);

		/*
		 * 4. Read LMC0_DLL_CTL3 and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(0));
            } /* if (ddr_interface_mask == 0x3) */

            if (ddr_interface_mask == 0xf) {
		/*
		 * 6.9.5.2 LMC CK Local Initialization for Four-LMC Mode
		 *
		 * 1. Write LMC2_DLL_CTL3 to its reset value except
		 *    LMC2_DLL_CTL3[DLL90_BYTE_SEL] = 0x7.
		 */

		ddr_dll_ctl3.u = 0;
		ddr_dll_ctl3.s.dclk90_recal_dis = 1;
		ddr_dll_ctl3.s.dll90_byte_sel = 7;
		DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(2),	ddr_dll_ctl3.u);

		/*
		 * 2. Write LMC3_DLL_CTL3 to its reset value except
		 *    LMC3_DLL_CTL3[DLL90_BYTE_SEL] = 0x0.
		 */

		ddr_dll_ctl3.u = 0;
		ddr_dll_ctl3.s.dclk90_recal_dis = 1;
		ddr_dll_ctl3.s.dll90_byte_sel = 0; /* HRM wants 0, not 2 */
		DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(3),	ddr_dll_ctl3.u); /* HRM wants LMC3 */

		/*
		 * 3. Read LMC3_DLL_CTL3 and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(3));

		/*
		 * 4. Without changing any other fields in LMC2_DLL_CTL3, write
		 *    LMC2_DLL_CTL3[DCLK90_FWD] = 1 and LMC2_DLL_CTL3[DCLK90_RECAL_DIS] = 1.
		 *    Writing LMC2_DLL_CTL3[DCLK90_FWD] = 1 causes LMC 2 to forward
		 *    clock-delay information to LMC0. Setting
		 *    LMC2_DLL_CTL3[DCLK90_RECAL_DIS] to 1 prevents LMC2 from periodically
		 *    recalibrating this delay information.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL3(2),
				c.s.dclk90_fwd = 1;
				c.s.dclk90_recal_dis = 1);

		/*
		 * 5. Without changing any other fields in LMC3_DLL_CTL3, write
		 *    LMC3_DLL_CTL3[DCLK90_FWD] = 1 and LMC3_DLL_CTL3[DCLK90_RECAL_DIS] = 1.
		 *    Writing LMC3_DLL_CTL3[DCLK90_FWD] = 1 causes LMC3 to forward
		 *    clock-delay information to LMC1. Setting
		 *    LMC3_DLL_CTL3[DCLK90_RECAL_DIS] to 1 prevents LMC3 from periodically
		 *    recalibrating this delay information.
		 */

		DRAM_CSR_MODIFY(c, node, BDK_LMCX_DLL_CTL3(3),
				c.s.dclk90_fwd = 1;
				c.s.dclk90_recal_dis = 1);

		/*
		 * 6. Read LMC3_DLL_CTL3 and wait for the result.
		 */

		BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(3));
            } /* if (ddr_interface_mask == 0xf) */


            /* TWO-LMC MODE AFTER STEP 5 */
            if (ddr_interface_mask == 0x3) {
                cn78xx_lmc_dreset_init(node, 1);
            }

            /* FOUR-LMC MODE AFTER STEP 5 */
            if (ddr_interface_mask == 0xf) {
                cn78xx_lmc_dreset_init(node, 0);
                cn78xx_lmc_dreset_init(node, 1);
            }

        } /* Do this once */


        /*
         * 6.9.6 LMC RESET Initialization
         *
         * The purpose of this step is to assert/deassert the RESET# pin at the
         * DDR3/DDR4 parts.
         *
         * This LMC RESET step is done for all enabled LMCs.
         *
         * It may be appropriate to skip this step if the DDR3/DDR4 DRAM parts
         * are in self refresh and are currently preserving their
         * contents. (Software can determine this via
         * LMC(0..3)_RESET_CTL[DDR3PSV] in some circumstances.) The remainder of
         * this section assumes that the DRAM contents need not be preserved.
         *
         * The remainder of this section assumes that the CN78XX DDRn_RESET_L pin
         * is attached to the RESET# pin of the attached DDR3/DDR4 parts, as will
         * be appropriate in many systems.
         *
         * (In other systems, such as ones that can preserve DDR3/DDR4 part
         * contents while CN78XX is powered down, it will not be appropriate to
         * directly attach the CN78XX DDRn_RESET_L pin to DRESET# of the
         * DDR3/DDR4 parts, and this section may not apply.)
         *
         * The remainder of this section describes the sequence for LMCn.
         *
         * Perform the following six substeps for LMC reset initialization:
         *
         * 1. If not done already, assert DDRn_RESET_L pin by writing
         *    LMC(0..3)_RESET_ CTL[DDR3RST] = 0 without modifying any other
         *    LMC(0..3)_RESET_CTL fields.
         */

        if ( !ddr_memory_preserved(node)) {
            /*
             * 2. Read LMC(0..3)_RESET_CTL and wait for the result.
             */

            BDK_CSR_READ(node, BDK_LMCX_RESET_CTL(ddr_interface_num));

            /*
             * 3. Wait until RESET# assertion-time requirement from JEDEC DDR3/DDR4
             *    specification is satisfied (200 us during a power-on ramp, 100ns when
             *    power is already stable).
             */

            bdk_wait_usec(200);

            /*
             * 4. Deassert DDRn_RESET_L pin by writing LMC(0..3)_RESET_CTL[DDR3RST] = 1
             *    without modifying any other LMC(0..3)_RESET_CTL fields.
             */

            DRAM_CSR_MODIFY(c, node, BDK_LMCX_RESET_CTL(ddr_interface_num),
			    c.s.ddr3rst = 1);
            ddr_print("LMC%d De-asserting DDR_RESET_L\n", ddr_interface_num);

            /*
             * 5. Read LMC(0..3)_RESET_CTL and wait for the result.
             */

            BDK_CSR_READ(node, BDK_LMCX_RESET_CTL(ddr_interface_num));

            /*
             * 6. Wait a minimum of 500us. This guarantees the necessary T = 500us
             *    delay between DDRn_RESET_L deassertion and DDRn_DIMM*_CKE* assertion.
             */

            bdk_wait_usec(500);
        }
    } /* if (CAVIUM_IS_MODEL(CAVIUM_CN88XX)) */

    set_ddr_clock_initialized(node, ddr_interface_num, 1);
    return(0);
}

uint32_t measure_octeon_ddr_clock(bdk_node_t node,
				  const ddr_configuration_t *ddr_configuration,
				  uint32_t cpu_hertz,
				  uint32_t ddr_hertz,
				  uint32_t ddr_ref_hertz,
				  int ddr_interface_num,
				  uint32_t ddr_interface_mask)
{
	uint64_t core_clocks;
	uint64_t ddr_clocks;
	uint64_t calc_ddr_hertz;

	if (ddr_configuration) {
	    if (initialize_ddr_clock(node,
				     ddr_configuration,
				     cpu_hertz,
				     ddr_hertz,
				     ddr_ref_hertz,
				     ddr_interface_num,
				     ddr_interface_mask) != 0)
		return 0;
	}

	/* Dynamically determine the DDR clock speed */
        core_clocks = bdk_clock_get_count(BDK_CLOCK_TIME);
        ddr_clocks = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(ddr_interface_num));
        bdk_wait_usec(100000); /* 100ms */
        core_clocks = bdk_clock_get_count(BDK_CLOCK_TIME) - core_clocks;
        ddr_clocks = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(ddr_interface_num)) - ddr_clocks;
        calc_ddr_hertz = ddr_clocks * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME) / core_clocks;

        /* Asim doesn't have a DDR clock, force the measurement to be correct  */
        if (bdk_is_simulation())
            calc_ddr_hertz = ddr_hertz;

	ddr_print("LMC%d: Measured DDR clock: %lu, cpu clock: %u, ddr clocks: %lu\n",
		  ddr_interface_num, calc_ddr_hertz, cpu_hertz, ddr_clocks);

	/* Check for unreasonable settings. */
	if (calc_ddr_hertz == 0) {
	    error_print("DDR clock misconfigured. Exiting.\n");
	    exit(1);
	}
	return calc_ddr_hertz;
}

int octeon_ddr_initialize(bdk_node_t node,
			  uint32_t cpu_hertz,
			  uint32_t ddr_hertz,
			  uint32_t ddr_ref_hertz,
			  uint32_t ddr_interface_mask,
			  const ddr_configuration_t *ddr_configuration,
			  uint32_t *measured_ddr_hertz,
			  int board_type,
			  int board_rev_maj,
			  int board_rev_min)
{
    uint32_t ddr_config_valid_mask = 0;
    int memsize_mbytes = 0;
    char *eptr;
    int retval;
    int interface_index;
    uint32_t ddr_max_speed = 1210000000; /* needs to be this high for DDR4 */
    uint32_t calc_ddr_hertz = -1;

#ifndef OCTEON_SDK_VERSION_STRING
# define OCTEON_SDK_VERSION_STRING "Development Build"
#endif

    ddr_print(OCTEON_SDK_VERSION_STRING": $Revision: 102369 $\n");

#ifdef CAVIUM_ONLY
    /* Override speed restrictions to support internal testing. */
    ddr_max_speed = 1210000000;
#endif  /* CAVIUM_ONLY */

    if (ddr_hertz > ddr_max_speed) {
	error_print("DDR clock speed %u exceeds maximum speed supported by "
		    "processor, reducing to %uHz\n",
		    ddr_hertz, ddr_max_speed);
	ddr_hertz = ddr_max_speed;
    }

    {
	/*

	rdf_cnt: Defines the sample point of the LMC response data in
	the DDR-clock/core-clock crossing.  For optimal
	performance set to 10 * (DDR-clock period/core-clock
	period) - 1.  To disable set to 0. All other values
	are reserved.
	*/

	const char *s;
	uint64_t rdf_cnt;
	BDK_CSR_INIT(l2c_ctl, node, BDK_L2C_CTL);
	/* It is more convenient to compute the ratio using clock
	   frequencies rather than clock periods. */
	rdf_cnt = (((uint64_t) 10 * cpu_hertz) / ddr_hertz) - 1;
	rdf_cnt = rdf_cnt<256 ? rdf_cnt : 255;
	l2c_ctl.s.rdf_cnt = rdf_cnt;

	if ((s = lookup_env_parameter("early_fill_count")) != NULL)
	    l2c_ctl.s.rdf_cnt = strtoul(s, NULL, 0);

	ddr_print("%-45s : %d, cpu_hertz:%u, ddr_hertz:%u\n", "EARLY FILL COUNT  ",
		  l2c_ctl.s.rdf_cnt, cpu_hertz, ddr_hertz);
	DRAM_CSR_WRITE(node, BDK_L2C_CTL, l2c_ctl.u);
    }

    /* Check to see if we should limit the number of L2 ways. */
    eptr = getenv("limit_l2_ways");
    if (eptr) {
	int ways = strtoul(eptr, NULL, 10);
	limit_l2_ways(node, ways, 1);
    }

    /* Check for lower DIMM socket populated */
    for (interface_index=0; interface_index<4; ++interface_index) {
	if ((ddr_interface_mask & (1<<interface_index))
	    && validate_dimm(node, &ddr_configuration[(int)interface_index].dimm_config_table[0], 0))
	    ddr_config_valid_mask |= (1 << interface_index);
    }

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX)) {
	int four_lmc_mode = 1;

	const char *s;

	if ((s = getenv("ddr_four_lmc")) != NULL) {
	    four_lmc_mode = strtoul(s, NULL, 0);
	    error_print("Parameter found in environment. ddr_four_lmc = %d\n",
			four_lmc_mode);
	}

	if (!four_lmc_mode) {
	    puts("Forcing two-LMC Mode.\n");
	    ddr_config_valid_mask &= ~(3<<2); /* Invalidate LMC[2:3] */
	}
    }

    if (!ddr_config_valid_mask) {
	puts("ERROR: No valid DIMMs detected on any DDR interface.\n");
	return -1;
    }

    /* We measure the DDR frequency by counting DDR clocks.  We can
     * confirm or adjust the expected frequency as necessary.  We use
     * the measured frequency to make accurate timing calculations
     * used to configure the controller.
     */
    for (interface_index = 0; interface_index < 4; ++interface_index) {
	uint32_t tmp_hertz;

	if (! (ddr_config_valid_mask & (1 << interface_index)))
	    continue;

	tmp_hertz = measure_octeon_ddr_clock(node,
					     &ddr_configuration[interface_index],
					     cpu_hertz,
					     ddr_hertz,
					     ddr_ref_hertz,
					     interface_index,
					     ddr_config_valid_mask);
	if (tmp_hertz > 0)
	    calc_ddr_hertz = tmp_hertz;
	ddr_print("LMC%d: measured speed: %u hz\n",
		  interface_index, tmp_hertz);
    }

    if (measured_ddr_hertz)
	*measured_ddr_hertz = calc_ddr_hertz;

    memsize_mbytes = 0;
    for (interface_index = 0; interface_index < 4; ++interface_index) {
	if (! (ddr_config_valid_mask & (1 << interface_index)))
	    continue;

	retval = init_octeon_dram_interface(node,
					    &ddr_configuration[interface_index],
					    calc_ddr_hertz, /* Configure using measured value */
					    cpu_hertz,
					    ddr_ref_hertz,
					    board_type,
					    board_rev_maj,
					    board_rev_min,
					    interface_index,
					    ddr_config_valid_mask);
	if (retval > 0)
	    memsize_mbytes += retval;
    }

    if (memsize_mbytes == 0)
	/* All interfaces failed to initialize, so return error */
	return -1;

    eptr = getenv("limit_dram_mbytes");
    if (eptr) {
	unsigned int mbytes = strtoul(eptr, NULL, 10);
	if (mbytes > 0) {
	    memsize_mbytes = mbytes;
	    printf("Limiting DRAM size to %d MBytes based on limit_dram_mbytes env. variable\n",
		   mbytes);
	}
    }

    return memsize_mbytes;
}


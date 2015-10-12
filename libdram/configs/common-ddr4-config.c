#include <bdk.h>
#include "../dram-internal.h"

#define ENABLE_DLL_OFFSET_PROVISION 0 // set to 1 to get canned offsets for #121/#122

/////////////////////////////////////
// FIXUPS
//
// #1 is for RDIMM 2Rx4 1-slot only, at this time...

static void common_ddr4_fixup_1_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0; 

    //setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    bdk_lmcx_modereg_params1_t *modereg1 = &odt[dimm].odt_mask1;
    modereg1->s.rtt_wr_00       = ddr4_rttwr_240ohm/* default currently ddr4_rttwr_240ohm */;
    modereg1->s.rtt_wr_01       = ddr4_rttwr_240ohm/* default currently ddr4_rttwr_240ohm */;

    //setup_modereg_params2_2rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    bdk_lmcx_modereg_params2_t *modereg2 = &odt[dimm].odt_mask2;

    modereg2->s.rtt_park_00    = ddr4_rttpark_40ohm/* default currently ddr4_rttpark_120ohm */;
    modereg2->s.rtt_park_01    = ddr4_rttpark_40ohm/* default currently ddr4_rttpark_120ohm */;

    odt[dimm].qs_dic = ddr4_rodt_ctl_120_ohm; /* RODT_CTL */
}

/////////////////////////////////////

#if ENABLE_DLL_OFFSET_PROVISION
//
// DLL read Offset table for the #122 INPHI DIMMs
//                                                       byte   0   1   2   3   4   5   6   7   8
#define DLLRO_VERSION_2 
#ifdef DLLRO_VERSION_2
// Version 2 has more adjustments for 1050 over V1
//L0_122_list=[(2,05),(3,15),(4,10),(5,10)]
//L1_122_list=[(2,-5)]
//L2_122_list=[(1,20),(2,10),(4,-10),(5,10),(8,-20)]
//L3_122_list=[(3,15),(7,5)]

static const int8_t inphi_122_dll_read_offset  [4][9]    = { { -5,  5,  5, 15, 10, 10,  5,  0,  0}, // LMC 0
							     { -5, 10, -5,  5,  0,  0,  5,  0,  0}, // LMC 1
							     { -5, 20, 10,  5,-10, 10,  5,  0,-20}, // LMC 2
							     {  5,  5,  5, 15,  0,-10,  5,  5,  0}  // LMC 3
							   };
#else
// Version 1 is the original (DL settings) plus the following patches
// patch 1: LMC0 byte 1 from  0 to   5
// patch 2: LMC1 byte 1 from  0 to  10
// patch 3: LMC0 byte 3 from  5 to  15: from 1slot 1050 speed testing
static const int8_t inphi_122_dll_read_offset  [4][9]    = { { -5,  5,  5, 15,  0,  0,  5,  0,  0}, // LMC 0
							     { -5, 10,  5,  5,  0,  0,  5,  0,  0}, // LMC 1
							     { -5,  5, 10,  5,  0, -5,  5,  0,  0}, // LMC 2
							     {  5,  5,  5,  5,  0,-10,  5,  0,  0}  // LMC 3
							   };
#endif
#endif /* ENABLE_DLL_OFFSET_PROVISION */

/////////////////////////////////////

int common_ddr4_fixups(dram_config_t *cfg, uint32_t default_udimm_speed)
{
    /* FIXME: Switch the speed for UDIMMs */
    bdk_node_t node = bdk_numa_local();
    int spd_dimm_type = get_dimm_module_type(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_DRAM);
    int spd_rdimm = (spd_dimm_type == 1);
    if (!spd_rdimm) {
        cfg->ddr_clock_hertz = default_udimm_speed;
    }

    /* FIXME: FIXUPS
     * Here is where we can fix up configuration values dependent on the SPD contents.
     * For example, we may want to change MODEREG_PARAMSx fields like rtt_wr dependent on the DIMM.
     */
    int spd_package = 0xff & read_spd(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_SPD_PACKAGE_TYPE);
    int spd_org     = 0xff & read_spd(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_SPD_MODULE_ORGANIZATION);
    int num_ranks   = 1 +  ((spd_org >> 3) & 0x7);
    int dram_width  = 4 << ((spd_org >> 0) & 0x7);
    int lmc;

    // look for RDIMM && 2Rx4 && stacked die
    if (spd_rdimm && (num_ranks == 2) && (dram_width == 4) && ((spd_package & 0xf3) == 0x91))
    {
	// fixup ONLY the items that need to be different
	//printf("CONFIG_EBB8804: fixups for RDIMM 2Rx4 stacked die\n");

	// do each LMC
	for (lmc = 0; lmc < 4; lmc++) {
	    //fixup_dram_custom_lmc_config(&cfg->config[lmc].custom_lmc_config);
	    //fixup_dram_odt_1rank_configuration(cfg->config[lmc].odt_1rank_config);
	    common_ddr4_fixup_1_dram_odt_2rank_configuration(cfg->config[lmc].odt_2rank_config);
	    //fixup_dram_odt_4rank_configuration(cfg->config[lmc].odt_4rank_config);
	}
    }

#if ENABLE_DLL_OFFSET_PROVISION
    char part_number[21] = {0};

    // Check for specific DIMM part number and set a different DLL Read Offset table
    get_dimm_part_number(part_number, node, &cfg->config[0].dimm_config_table[0], 0, DDR4_DRAM);
    if (strcmp(part_number, "36ASF2G72PZ-2G1A2") == 0)
    {
	//printf("CONFIG_EBB8804: fixup for RDIMM #122 part number '%s'\n", part_number);

	// do each LMC
	for (lmc = 0; lmc < 4; lmc++) {
	    cfg->config[lmc].custom_lmc_config.dll_read_offset = &inphi_122_dll_read_offset[lmc][0];
	}
    }
#endif /* ENABLE_DLL_OFFSET_PROVISION */

    return 0;
}

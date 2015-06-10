#include <bdk.h>
#include "../dram-internal.h"
#include "common-spd-tables.h"

#define USE_INTERNAL_SPD 0 /* Change to 1 for compiled in SPDs */

#define DEFAULT_INTERNAL_SPD MT18ASF1G72AZ_2G1AYESZG_SPD

#define DEFAULT_NAME   "ebb8804"

#define DEFAULT_UDIMM_SPEED  1066666666
#define DEFAULT_RDIMM_SPEED  940000000

#define DEFAULT_LMC_MASK   TWO_LMC_MASK
#define DEFAULT_DIMM_MASK  ONE_DIMM_MASK

#if 0
static rlevel_table_t rlevel_rank_values[] =    {
    {
        .part = "36ASF2G72PZ-2G1A2",
        .speed = 1866,
        .rlevel_rank = {
            /*
              38 lines matching "Rlevel Rank   0x1\\|Node 0: DRAM: .* MB, .* MHz\\|Initializing node . DDR interface\\|DIMM .: DDR4" in buffer minicom-S9-23Mar1751.log.
              59:Initializing node 0 DDR interface 0, DDR Clock 933332040, DDR Reference Clock 50000000
              62:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 223344122 1.2V
              451:Rank(0) Rlevel Rank   0x1, 0x004E4503CE3D0452 :    14    17    16    15    14    15    16    17    18 (0)
              452:Rank(1) Rlevel Rank   0x1, 0x004E4503CE3D0452 :    14    17    16    15    14    15    16    17    18 (4)
              488:Initializing node 0 DDR interface 1, DDR Clock 933332040, DDR Reference Clock 50000000
              491:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 223344210 1.2V
              879:Rank(0) Rlevel Rank   0x1, 0x004E4503CE3D0452 :    14    17    16    15    14    15    16    17    18 (0)
              880:Rank(1) Rlevel Rank   0x1, 0x004E4503CE3D0452 :    14    17    16    15    14    15    16    17    18 (0)
              916:Initializing node 0 DDR interface 2, DDR Clock 933332040, DDR Reference Clock 50000000
              919:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 223344208 1.2V
              1308:Rank(0) Rlevel Rank   0x1, 0x004D44F3CD3CF411 :    13    17    15    15    13    15    15    16    17 (0)
              1309:Rank(1) Rlevel Rank   0x1, 0x004D44F3CD38F411 :    13    17    15    15    13    14    15    16    17 (0)
              1345:Initializing node 0 DDR interface 3, DDR Clock 933332040, DDR Reference Clock 50000000
              1348:DIMM 0: DDR4 RDIMM, ECC  36ASF2G72PZ-2G1A2    s/n 237508068 1.2V
              1737:Rank(0) Rlevel Rank   0x1, 0x004E44F3CD3D0412 :    14    17    15    15    13    15    16    16    18 (50)
              1738:Rank(1) Rlevel Rank   0x1, 0x004E40F3CD3D0412 :    14    16    15    15    13    15    16    16    18 (50)
              1773:Node 0: DRAM: 65536 MB, 933 MHz
            */
            { 0x004E4503CE3D0452, 0x004E4503CE3D0452, 0, 0 },
            { 0x004E4503CE3D0452, 0x004E4503CE3D0452, 0, 0 },
            { 0x004D44F3CD3CF411, 0x004D44F3CD38F411, 0, 0 },
            { 0x004E44F3CD3D0412, 0x004E40F3CD3D0412, 0, 0 }
        }
    },
    {0}                             /* Terminator */
};
#endif


static void setup_modereg_params1_1rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = 0;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_1rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_HiZ; /* Let HiZ signal to fixup to 80 ohms */
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = ddr4_rttwr_HiZ; /* Let HiZ signal to fixup to 80 ohms */
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_240ohm;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = 0;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = ddr4_rttwr_240ohm;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = ddr4_rttwr_240ohm;
    modereg->s.dic_00       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_00   = ddr4_rttnom_120ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = ddr4_rttwr_240ohm;
    modereg->s.dic_01       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_01   = ddr4_rttnom_120ohm;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = ddr4_rttwr_240ohm;
    modereg->s.dic_10       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_10   = ddr4_rttnom_120ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = ddr4_rttwr_240ohm;
    modereg->s.dic_11       = ddr4_dic_34ohm;
    modereg->s.rtt_nom_11   = ddr4_rttnom_120ohm;
}

static void setup_modereg_params1_4rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = rttwr_60ohm;
    modereg->s.dic_00       = dic_34ohm;
    modereg->s.rtt_nom_00   = rttnom_20ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = rttwr_60ohm;
    modereg->s.dic_01       = dic_34ohm;
    modereg->s.rtt_nom_01   = rttnom_none;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = rttwr_60ohm;
    modereg->s.dic_10       = dic_34ohm;
    modereg->s.rtt_nom_10   = rttnom_20ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = rttwr_60ohm;
    modereg->s.dic_11       = dic_34ohm;
    modereg->s.rtt_nom_11   = rttnom_none;
}

static void setup_modereg_params2_1rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_60ohm;
    modereg->s.vref_value_00  = 0x22;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = 0;
    modereg->s.vref_value_01  = 0;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_1rank_2slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_34ohm;
    modereg->s.vref_value_00  = 0x1f;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = 0;
    modereg->s.vref_value_01  = 0;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = ddr4_rttpark_34ohm;
    modereg->s.vref_value_10  = 0x1f;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_2rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_120ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_120ohm;
    modereg->s.vref_value_01  = 0x19;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_2rank_2slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_60ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_60ohm;
    modereg->s.vref_value_01  = 0x19;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = ddr4_rttpark_60ohm;
    modereg->s.vref_value_10  = 0x19;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = ddr4_rttpark_60ohm;
    modereg->s.vref_value_11  = 0x19;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_4rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_00  = 0x1f;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_01  = 0x1f;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = 0;
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_dram_odt_1rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_80_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x0c0c0303ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x04080102ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_4rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = ddr4_dqx_driver_34_ohm; /* DQX_CTL */
    odt[dimm].odt_mask = 0x01030203ULL; /* WODT_MASK */
    setup_modereg_params1_4rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_4rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = ddr4_rodt_ctl_48_ohm; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010202ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

/////////////////////////////////////
// FIXUPS
//
// #1 is for RDIMM 2Rx4 1-slot only, at this time...

static void fixup_1_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
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

// DLL read Offset table for the #122 INPHI DIMMs
static const int8_t inphi_122_dll_read_offset  [4][9]    = { {-5, 0, 5, 5, 0,  0, 5, 0, 0}, // LMC 0
							     {-5, 5, 0, 5, 0,  0, 5, 0, 0}, // LMC 1
							     {-5, 5,10, 5, 0, -5, 5, 0, 0}, // LMC 2
							     { 5, 5, 5, 5, 0,-10, 5, 0, 0}  // LMC 3
							   };
static const int8_t generic_dll_read_offset  [4][9]      = { {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 0
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 1
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 2
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}  // LMC 3
						   	   };
static const int8_t generic_dll_write_offset  [4][9]     = { {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 0
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 1
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}, // LMC 2
							     {0, 0,  0, 0, 0,  0, 0, 0, 0}  // LMC 3
						   	   };

static void setup_dram_custom_lmc_config(ddr3_custom_config_t *cfg, int lmc)
{
    cfg->min_rtt_nom_idx        = 1;
    cfg->max_rtt_nom_idx        = 7;
    cfg->min_rodt_ctl           = 1;
    cfg->max_rodt_ctl           = 7;
    cfg->ck_ctl                 = ddr4_driver_34_ohm;
    cfg->cmd_ctl                = ddr4_driver_34_ohm;
    cfg->ctl_ctl                = ddr4_driver_34_ohm;
    cfg->min_cas_latency        = 0;
    cfg->offset_en              = 1;
    cfg->offset_udimm           = 2;
    cfg->offset_rdimm           = 2;
    cfg->ddr_rtt_nom_auto       = 0;
    cfg->ddr_rodt_ctl_auto      = 0;
    cfg->rlevel_comp_offset_udimm       = 0;
    cfg->rlevel_comp_offset_rdimm       = 0;
    cfg->rlevel_compute         = 0;
    cfg->ddr2t_udimm            = 1;
    cfg->ddr2t_rdimm            = 1;
    cfg->maximum_adjacent_rlevel_delay_increment = 2;
    cfg->fprch2                 = 2;
    cfg->dll_write_offset       = &generic_dll_write_offset [lmc][0];
    cfg->dll_read_offset        = &generic_dll_read_offset  [lmc][0];
    cfg->parity                 = 0;
    cfg->rlevel_table		= 0; /* Initialized later */
    cfg->measured_vref		= 0;
}

const dram_config_t *dram_get_config_ebb8804(void)
{
    dram_config_t *cfg = &__libdram_global_cfg;
    int lmc;

    /* Make all fields for the node default to zero */
    memset(cfg, 0, sizeof(*cfg));

    /* Set the config name and the default frequency */
    cfg->name = DEFAULT_NAME;
    cfg->ddr_clock_hertz = DEFAULT_RDIMM_SPEED;

    /* Load the defaults for DIMMs on all four controllers */
    for (lmc = 0; lmc < 4; lmc++)
    {
        setup_dram_custom_lmc_config(&cfg->config[lmc].custom_lmc_config, lmc);

        setup_dram_odt_1rank_configuration(cfg->config[lmc].odt_1rank_config);
        setup_dram_odt_2rank_configuration(cfg->config[lmc].odt_2rank_config);
        setup_dram_odt_4rank_configuration(cfg->config[lmc].odt_4rank_config);
    }

    if (USE_INTERNAL_SPD || bdk_is_platform(BDK_PLATFORM_ASIM))
    {
	int lmc_mask  = DEFAULT_LMC_MASK;
        int dimm_mask = DEFAULT_DIMM_MASK;
	for (lmc = 0; lmc < 4; lmc++)
        {
            if (! (lmc_mask & (1 << lmc))) /* Could use the testbit macro */
                continue;

            for (int dimm = 0; dimm < 2; dimm++)
            {
                if (! (dimm_mask & (1 << dimm))) /* Could use the testbit macro */
                    continue;

                cfg->config[lmc].dimm_config_table[dimm].spd_ptrs[0] = DEFAULT_INTERNAL_SPD;
            }
        }
    }
    else
    {
        /* Set the SPD addresses as we are reading them from DIMMs */
        cfg->config[0].dimm_config_table[0].spd_addrs[0] = 0x1050;
        cfg->config[0].dimm_config_table[1].spd_addrs[0] = 0x1051;
        cfg->config[1].dimm_config_table[0].spd_addrs[0] = 0x1052;
        cfg->config[1].dimm_config_table[1].spd_addrs[0] = 0x1053;
        cfg->config[2].dimm_config_table[0].spd_addrs[0] = 0x1054;
        cfg->config[2].dimm_config_table[1].spd_addrs[0] = 0x1055;
        cfg->config[3].dimm_config_table[0].spd_addrs[0] = 0x1056;
        cfg->config[3].dimm_config_table[1].spd_addrs[0] = 0x1057;
    }

    /* FIXME: Switch the speed for UDIMMs */
    bdk_node_t node = bdk_numa_local();
    int spd_dimm_type = 0xff & read_spd(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_SPD_KEY_BYTE_MODULE_TYPE);
    int spd_rdimm = (spd_dimm_type == 1);
    if (!spd_rdimm)
    {
        cfg->ddr_clock_hertz = DEFAULT_UDIMM_SPEED;
    }

    /* FIXME: FIXUPS
     * Here is where we can fix up configuration values dependent on the SPD contents.
     * For example, we may want to change MODEREG_PARAMSx fields like rtt_wr dependent on the DIMM.
     */
    int spd_package = 0xff & read_spd(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_SPD_PACKAGE_TYPE);
    int spd_org     = 0xff & read_spd(node, &cfg->config[0].dimm_config_table[0], 0, DDR4_SPD_MODULE_ORGANIZATION);
    int num_ranks   = 1 +  ((spd_org >> 3) & 0x7);
    int dram_width  = 4 << ((spd_org >> 0) & 0x7);
    char part_number[21] = {0};

    // look for RDIMM && 2Rx4 && stacked die
    if (spd_rdimm && (num_ranks == 2) && (dram_width == 4) && ((spd_package & 0xf3) == 0x91))
    {
	// fixup ONLY the items that need to be different
	//printf("CONFIG_EBB8804: fixups for RDIMM 2Rx4 stacked die\n");

	// do each LMC
	for (lmc = 0; lmc < 4; lmc++) {
	    //fixup_dram_custom_lmc_config(&cfg->config[lmc].custom_lmc_config);
	    //fixup_dram_odt_1rank_configuration(cfg->config[lmc].odt_1rank_config);
	    fixup_1_dram_odt_2rank_configuration(cfg->config[lmc].odt_2rank_config);
	    //fixup_dram_odt_4rank_configuration(cfg->config[lmc].odt_4rank_config);
	}
    }

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

    return cfg;
};

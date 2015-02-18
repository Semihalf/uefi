#include <bdk.h>
#include "../dram-internal.h"

#define USE_INTERNAL_SPD 0 /* Change to 1 for compiled in SPDs */

#define DEFAULT_INTERNAL_SPD MT18ASF1G72AZ_2G1AYESZG_SPD

#define DEFAULT_NAME   "cn88xx-crb-2s"
#define DEFAULT_SPEED  1066666666

#define DEFAULT_LMC_MASK   TWO_LMC_MASK
#define DEFAULT_DIMM_MASK  ONE_DIMM_MASK

static const uint8_t MT18ASF1G72AZ_2G1AXESZG_SPD[] = {
    0x23,0x10,0x0c,0x02,0x84,0x19,0x00,0x00,0x00,0x00,0x00,0x03,0x09,0x0b,0x80,0x00,
    0x00,0x00,0x08,0x0c,0xf4,0x1b,0x00,0x00,0x6c,0x6c,0x6c,0x11,0x08,0x74,0x20,0x08,
    0x00,0x05,0x70,0x03,0x00,0xa8,0x1e,0x2b,0x2b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x2c,0x15,0x35,
    0x15,0x35,0x0b,0x2c,0x15,0x35,0x0b,0x2c,0x0b,0x2c,0x0b,0x35,0x15,0x36,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xec,0xb5,0xce,0x00,0x00,0x00,0x00,0x00,0xc2,0x38,0x93,
    0x11,0x11,0x04,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x2e, /* 255 */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,
    0x00,0xbc,0x61,0x4e, /* serial number */
    0x4d,0x54,0x31,0x38,0x41,0x53,0x46, /* MT18ASF1G72AZ-AXE */
    0x31,0x47,0x37,0x32,0x41,0x5a,0x2d,0x41,0x58,0x45,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t MT18ASF1G72AZ_2G1AYESZG_SPD[] = {
    0x23,0x06,0x0c,0x02,0x84,0x19,0x00,0x00,0x00,0x00,0x00,0x03,0x09,0x0b,0x80,0x00,
    0x00,0x00,0x08,0x0c,0xf4,0x1b,0x00,0x00,0x6c,0x6c,0x6c,0x11,0x08,0x74,0x20,0x08,
    0x00,0x05,0x70,0x03,0x00,0xa8,0x1e,0x2b,0x2b,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0xec,0xb5,0xce,0x00,0x00,0x00,0x00,0x00,0xc2,0x98,0xf4,
    0x11,0x11,0x04,0x01,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0c,0x2e, /* 255 */
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,
    0x00,0xbc,0x61,0x4e, /* serial number */
    0x4d,0x54,0x31,0x38,0x41,0x53,0x46, /* MT18ASF1G72AZ-AYE */
    0x31,0x47,0x37,0x32,0x41,0x5a,0x2d,0x41,0x59,0x45,0x00,0x00,0x00,0x00,0x00,0x00
};

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
    modereg->s.rtt_wr_00    = ddr4_rttwr_120ohm;
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
    modereg->s.rtt_wr_10    = ddr4_rttwr_120ohm;
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
    modereg->s.vref_value_10  = 0;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = 0;
    modereg->s.vref_value_11  = 0;
    modereg->s.vref_range_11  = 0;
}

static void setup_modereg_params2_2rank_1slot(bdk_lmcx_modereg_params2_t *modereg)
{
    modereg->u = 0;
    modereg->s.rtt_park_00    = ddr4_rttpark_40ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_40ohm;
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
    modereg->s.rtt_park_00    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_00  = 0x19;
    modereg->s.vref_range_00  = 0;
    modereg->s.rtt_park_01    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_01  = 0x19;
    modereg->s.vref_range_01  = 0;
    modereg->s.rtt_park_10    = ddr4_rttpark_80ohm;
    modereg->s.vref_value_10  = 0x19;
    modereg->s.vref_range_10  = 0;
    modereg->s.rtt_park_11    = ddr4_rttpark_80ohm;
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
    odt[dimm].odt_ena = 5; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000001ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = 7; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 4; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000000ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_1rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = 7; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00040001ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 5; /* DQX_CTL */
    odt[dimm].odt_mask = 0x00000201ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = 7; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 4; /* DQX_CTL */
    odt[dimm].odt_mask = 0x0c0c0303ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_2rank_2slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = 7; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x04080102ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_4rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 4; /* DQX_CTL */
    odt[dimm].odt_mask = 0x01030203ULL; /* WODT_MASK */
    setup_modereg_params1_4rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    setup_modereg_params2_4rank_1slot(&odt[dimm].odt_mask2); /* LMCX_MODEREG_PARAMS2 */
    odt[dimm].qs_dic = 7; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010202ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_custom_lmc_config(ddr3_custom_config_t *cfg)
{
    cfg->min_rtt_nom_idx        = 1;
    cfg->max_rtt_nom_idx        = 7;
    cfg->min_rodt_ctl           = 1;
    cfg->max_rodt_ctl           = 7;
    cfg->ck_ctl                 = 5;
    cfg->cmd_ctl                = 5;
    cfg->ctl_ctl                = 5;
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
    //cfg->dll_write_offset     = {0};
    //cfg->dll_read_offset      = {0};
    cfg->parity                 = 0;
}

const dram_config_t *dram_get_config_crb_2s(void)
{
    static dram_config_t cfg;

    /* Make all fields default to zero */
    memset(&cfg, 0, sizeof(cfg));

    /* Set the config name and the default frequency */
    cfg.name = DEFAULT_NAME;
    cfg.ddr_clock_hertz = DEFAULT_SPEED;

    /* Load the defaults for DIMMs on all four controllers */
    for (int lmc = 0; lmc < 4; lmc++)
    {
        setup_dram_custom_lmc_config(&cfg.config[lmc].custom_lmc_config);
        setup_dram_odt_1rank_configuration(cfg.config[lmc].odt_1rank_config);
        setup_dram_odt_2rank_configuration(cfg.config[lmc].odt_2rank_config);
        setup_dram_odt_4rank_configuration(cfg.config[lmc].odt_4rank_config);
    }

    if (USE_INTERNAL_SPD || bdk_is_platform(BDK_PLATFORM_ASIM))
    {
	int lmc_mask  = DEFAULT_LMC_MASK;
        int dimm_mask = DEFAULT_DIMM_MASK;
	for (int lmc = 0; lmc < 4; lmc++)
        {
            if (! (lmc_mask & (1 << lmc))) /* Could use the testbit macro */
                continue;

            for (int dimm = 0; dimm < 2; dimm++)
            {
                if (! (dimm_mask & (1 << dimm))) /* Could use the testbit macro */
                    continue;

                cfg.config[lmc].dimm_config_table[dimm].spd_ptrs[0] = DEFAULT_INTERNAL_SPD;
            }
        }
    }
    else
    {
        /* Set the SPD addresses as we are reading them from DIMMs */
        cfg.config[0].dimm_config_table[0].spd_addrs[0] = 0x2050;
        cfg.config[1].dimm_config_table[0].spd_addrs[0] = 0x2051;
        cfg.config[2].dimm_config_table[0].spd_addrs[0] = 0x2052;
        cfg.config[3].dimm_config_table[0].spd_addrs[0] = 0x2053;
    }

    return &cfg;
};

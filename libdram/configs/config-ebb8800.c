#include <bdk.h>
#include "../dram-internal.h"
#include "common-spd-tables.h"

#define USE_INTERNAL_SPD 0 /* Change to 1 for compiled in SPDs */

#define DEFAULT_INTERNAL_SPD TS512MLK72V8N_SPD
//#define DEFAULT_INTERNAL_SPD WD3UN802G13LSD_SPD

#define DEFAULT_NAME   "ebb8800"
#define DEFAULT_SPEED  933333333

#define DEFAULT_LMC_MASK   TWO_LMC_MASK
#define DEFAULT_DIMM_MASK  ONE_DIMM_MASK

static void setup_modereg_params1_1rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = 0;
    modereg->s.dic_00       = 0;
    modereg->s.rtt_nom_00   = rttnom_40ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = 0;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = 0;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = 0;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_1rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = rttwr_120ohm;
    modereg->s.dic_00       = 0;
    modereg->s.rtt_nom_00   = rttnom_20ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = 0;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = rttwr_120ohm;
    modereg->s.dic_10       = 0;
    modereg->s.rtt_nom_10   = rttnom_20ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = 0;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_1slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = 0;
    modereg->s.dic_00       = 0;
    modereg->s.rtt_nom_00   = rttnom_40ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = 0;
    modereg->s.rtt_nom_01   = 0;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = 0;
    modereg->s.rtt_nom_10   = 0;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = 0;
    modereg->s.rtt_nom_11   = 0;
}

static void setup_modereg_params1_2rank_2slot(bdk_lmcx_modereg_params1_t *modereg)
{
    modereg->u = 0;
    modereg->s.pasr_00      = 0;
    modereg->s.asr_00       = 0;
    modereg->s.srt_00       = 0;
    modereg->s.rtt_wr_00    = 0;
    modereg->s.dic_00       = dic_34ohm;
    modereg->s.rtt_nom_00   = rttnom_20ohm;
    modereg->s.pasr_01      = 0;
    modereg->s.asr_01       = 0;
    modereg->s.srt_01       = 0;
    modereg->s.rtt_wr_01    = 0;
    modereg->s.dic_01       = dic_34ohm;
    modereg->s.rtt_nom_01   = rttnom_60ohm;
    modereg->s.pasr_10      = 0;
    modereg->s.asr_10       = 0;
    modereg->s.srt_10       = 0;
    modereg->s.rtt_wr_10    = 0;
    modereg->s.dic_10       = dic_34ohm;
    modereg->s.rtt_nom_10   = rttnom_20ohm;
    modereg->s.pasr_11      = 0;
    modereg->s.asr_11       = 0;
    modereg->s.srt_11       = 0;
    modereg->s.rtt_wr_11    = 0;
    modereg->s.dic_11       = dic_34ohm;
    modereg->s.rtt_nom_11   = rttnom_60ohm;
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

static void setup_dram_odt_1rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 4; /* DQX_CTL now supplied on a per DIMM basis */
    odt[dimm].odt_mask = 0x00000001ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 2; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 4; /* DQX_CTL now supplied on a per DIMM basis */
    odt[dimm].odt_mask = 0x00050005ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00010004ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 4; /* DQX_CTL now supplied on a per DIMM basis */
    odt[dimm].odt_mask = 0x00000101ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 4; /* DQX_CTL now supplied on a per DIMM basis */
    odt[dimm].odt_mask = 0x09090606ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010404ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_4rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 4; /* DQX_CTL now supplied on a per DIMM basis */
    odt[dimm].odt_mask = 0x01030203ULL; /* WODT_MASK */
    setup_modereg_params1_4rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010202ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_custom_lmc_config(ddr3_custom_config_t *cfg)
{
    cfg->min_rtt_nom_idx        = 1;
    cfg->max_rtt_nom_idx        = 5;
    cfg->min_rodt_ctl           = 1;
    cfg->max_rodt_ctl           = 5;
    cfg->ck_ctl                 = 4;
    cfg->cmd_ctl                = 4;
    cfg->ctl_ctl                = 4;
    cfg->min_cas_latency        = 0;
    cfg->offset_en              = 1;
    cfg->offset_udimm           = 2;
    cfg->offset_rdimm           = 2;
    cfg->ddr_rtt_nom_auto       = 0;
    cfg->ddr_rodt_ctl_auto      = 0;
    cfg->rlevel_comp_offset_udimm       = 7;
    cfg->rlevel_comp_offset_rdimm       = 7;
    cfg->rlevel_compute         = 0;
    cfg->ddr2t_udimm            = 1;
    cfg->ddr2t_rdimm            = 1;
    cfg->maximum_adjacent_rlevel_delay_increment = 1;
    cfg->fprch2                 = 2;
    //cfg->dll_write_offset     = {0};
    //cfg->dll_read_offset      = {0};
    cfg->parity                 = 0;
}

const dram_config_t *dram_get_config_ebb8800(void)
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
        cfg.config[0].dimm_config_table[0].spd_addrs[0] = 0x1050;
        cfg.config[0].dimm_config_table[1].spd_addrs[0] = 0x1051;
        cfg.config[1].dimm_config_table[0].spd_addrs[0] = 0x1052;
        cfg.config[1].dimm_config_table[1].spd_addrs[0] = 0x1053;
        cfg.config[2].dimm_config_table[0].spd_addrs[0] = 0x1054;
        cfg.config[2].dimm_config_table[1].spd_addrs[0] = 0x1055;
        cfg.config[3].dimm_config_table[0].spd_addrs[0] = 0x1056;
        cfg.config[3].dimm_config_table[1].spd_addrs[0] = 0x1057;
    }

    return &cfg;
};



#include <bdk.h>
#include "../dram-internal.h"

/* Don't bother with reading SPDs for emulator or initial poweron. */
#define USE_INTERNAL_SPD

static const uint8_t WD3UN802G13LSD_SPD[] = {
    0x92, 0x11, 0x0b, 0x02, 0x03, 0x19, 0x00, 0x01, 0x03, 0x11, 0x01, 0x08, 0x0c, 0x00, 0x3c, 0x00,
    0x69, 0x78, 0x69, 0x30, 0x69, 0x11, 0x20, 0x89, 0x00, 0x05, 0x3c, 0x3c, 0x00, 0xf0, 0x83, 0x01,
    0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x01, 0x20, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x61, 0x00, 0x12, 0x30, 0x00, 0x00, 0x00, 0x00, 0xb3, 0x31
};

static const uint8_t TS512MLK72V8N_SPD[] = {
    0x92, 0x10, 0x0b, 0x02, 0x03, 0x19, 0x00, 0x09, 0x0b, 0x11, 0x01, 0x08, 0x09, 0x00, 0xfc, 0x02,
    0x69, 0x78, 0x69, 0x28, 0x69, 0x11, 0x10, 0x79, 0x00, 0x05, 0x3c, 0x3c, 0x00, 0xd8, 0x83, 0x01,
    0x80, 0x00, 0xca, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x11, 0x64, 0x01,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x4f, 0x54, 0x13, 0x49, 0x00, 0x00, 0x11, 0x12, 0x0c, 0x22
};

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
    odt[dimm].odt_ena = 0; /* Reserved */
    odt[dimm].odt_mask = 0x00000001ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 2; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 0; /* Reserved */
    odt[dimm].odt_mask = 0x00050005ULL; /* WODT_MASK */
    setup_modereg_params1_1rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00010004ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_2rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 0; /* Reserved */
    odt[dimm].odt_mask = 0x00000101ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_1slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x00000000ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */

    dimm = 1;
    odt[dimm].odt_ena = 0; /* Reserved */
    odt[dimm].odt_mask = 0x09090606ULL; /* WODT_MASK */
    setup_modereg_params1_2rank_2slot(&odt[dimm].odt_mask1); /* LMCX_MODEREG_PARAMS1 */
    odt[dimm].qs_dic = 3; /* RODT_CTL */
    odt[dimm].rodt_ctl = 0x01010404ULL; /* RODT_MASK */
    odt[dimm].dic = 0; /* Reserved */
}

static void setup_dram_odt_4rank_configuration(dimm_odt_config_t odt[4])
{
    int dimm = 0;
    odt[dimm].odt_ena = 0; /* Reserved */
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
    cfg->dqx_ctl                = 4;
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
    cfg->ddr2t_udimm            = 0;
    cfg->ddr2t_rdimm            = 1;
    cfg->maximum_adjacent_rlevel_delay_increment = 2;
    cfg->fprch2                 = 2;
    //cfg->dll_write_offset     = {0};
    //cfg->dll_read_offset      = {0};
    cfg->parity                 = 0;
}

const dram_config_t *dram_get_config_ebb8800(void)
{
    static dram_config_t cfg;
#ifdef USE_INTERNAL_SPD
    int lmc_mask  = 0x3;            /* Two LMCs */
    int dimm_mask = 0x1;            /* One DIMM */
#endif

    /* Make all fields default to zero */
    memset(&cfg, 0, sizeof(cfg));

    /* Set the config name and the default frequency */
    cfg.name = "ebb8800";
    cfg.ddr_clock_hertz = 666000000;

    /* Load the defaults for DIMMs on all four controllers */
    for (int lmc = 0; lmc < 4; lmc++)
    {
        setup_dram_custom_lmc_config(&cfg.config[lmc].custom_lmc_config);
        setup_dram_odt_1rank_configuration(cfg.config[lmc].odt_1rank_config);
        setup_dram_odt_2rank_configuration(cfg.config[lmc].odt_2rank_config);
        setup_dram_odt_4rank_configuration(cfg.config[lmc].odt_4rank_config);
    }

#ifdef USE_INTERNAL_SPD
    for (int lmc = 0; lmc < 4; lmc++)
    {
        if (! (lmc_mask & (1 << lmc))) /* Could use the testbit macro */
            continue;

        for (int dimm = 0; dimm < 2; dimm++)
        {
            if (! (dimm_mask & (1 << dimm))) /* Could use the testbit macro */
                continue;

            cfg.config[lmc].dimm_config_table[dimm].spd_ptrs[0] = TS512MLK72V8N_SPD;
        }
    }
#else
    /* Set the SPD addresses as we are reading them from DIMMs */
    cfg.config[0].dimm_config_table[0].spd_addrs[0] = 0x1050;
    cfg.config[0].dimm_config_table[1].spd_addrs[0] = 0x1051;
    cfg.config[1].dimm_config_table[0].spd_addrs[0] = 0x1052;
    cfg.config[1].dimm_config_table[1].spd_addrs[0] = 0x1053;
    cfg.config[2].dimm_config_table[0].spd_addrs[0] = 0x1054;
    cfg.config[2].dimm_config_table[1].spd_addrs[0] = 0x1055;
    cfg.config[3].dimm_config_table[0].spd_addrs[0] = 0x1056;
    cfg.config[3].dimm_config_table[1].spd_addrs[0] = 0x1057;
#endif

    return &cfg;
};


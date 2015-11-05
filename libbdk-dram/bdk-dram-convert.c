#include <bdk.h>

/**
 * Store a "odt_*rank_config" structure
 *
 * @param cfg    Config to fill
 * @param ranks  Number of ranks we're loading (1,2,4)
 * @param node   Node we're loading for
 * @param dimm   Which DIMM this is for
 * @param lmc    Which LMC this is for
 */
static void store_rank_data(const dram_config_t *cfg, int ranks, int num_dimms, int lmc, bdk_node_t node)
{
    /* Get a pointer to the structure we are filling */
    const dimm_odt_config_t *c;
    switch (ranks)
    {
        case 1:
            c = &cfg->config[lmc].odt_1rank_config[num_dimms - 1];
            break;
        case 2:
            c = &cfg->config[lmc].odt_2rank_config[num_dimms - 1];
            break;
        case 4:
            c = &cfg->config[lmc].odt_4rank_config[num_dimms - 1];
            break;
        default:
            bdk_fatal("Unexpected number of ranks\n");
            break;
    }

    /* Fill the global items */
    if (c->odt_ena)
        bdk_config_set_int(c->odt_ena, BDK_CONFIG_DDR_RANKS_DQX_CTL, ranks, num_dimms, lmc, node);
    if (c->odt_mask)
        bdk_config_set_int(c->odt_mask, BDK_CONFIG_DDR_RANKS_WODT_MASK, ranks, num_dimms, lmc, node);

    /* Fill the per rank items */
    int rank = 0;
    if (c->odt_mask1.s.pasr_00)
        bdk_config_set_int(c->odt_mask1.s.pasr_00, BDK_CONFIG_DDR_RANKS_MODE1_PASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.asr_00)
        bdk_config_set_int(c->odt_mask1.s.asr_00, BDK_CONFIG_DDR_RANKS_MODE1_ASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.srt_00)
        bdk_config_set_int(c->odt_mask1.s.srt_00, BDK_CONFIG_DDR_RANKS_MODE1_SRT, ranks, num_dimms, rank, lmc, node);
    int rtt_wr = c->odt_mask1.s.rtt_wr_00;
    rtt_wr |= c->odt_mask1.s.rtt_wr_00_ext << 2;
    if (rtt_wr)
        bdk_config_set_int(rtt_wr, BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.dic_00)
        bdk_config_set_int(c->odt_mask1.s.dic_00, BDK_CONFIG_DDR_RANKS_MODE1_DIC, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.rtt_nom_00)
        bdk_config_set_int(c->odt_mask1.s.rtt_nom_00, BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.db_output_impedance)
        bdk_config_set_int(c->odt_mask1.s.db_output_impedance, BDK_CONFIG_DDR_RANKS_MODE1_DB_OUTPUT_IMPEDANCE, ranks, num_dimms, lmc, node);
    rank = 1;
    if (c->odt_mask1.s.pasr_01)
        bdk_config_set_int(c->odt_mask1.s.pasr_01, BDK_CONFIG_DDR_RANKS_MODE1_PASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.asr_01)
        bdk_config_set_int(c->odt_mask1.s.asr_01, BDK_CONFIG_DDR_RANKS_MODE1_ASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.srt_01)
        bdk_config_set_int(c->odt_mask1.s.srt_01, BDK_CONFIG_DDR_RANKS_MODE1_SRT, ranks, num_dimms, rank, lmc, node);
    rtt_wr = c->odt_mask1.s.rtt_wr_01;
    rtt_wr |= c->odt_mask1.s.rtt_wr_01_ext << 2;
    if (rtt_wr)
        bdk_config_set_int(rtt_wr, BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.dic_01)
        bdk_config_set_int(c->odt_mask1.s.dic_01, BDK_CONFIG_DDR_RANKS_MODE1_DIC, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.rtt_nom_01)
        bdk_config_set_int(c->odt_mask1.s.rtt_nom_01, BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM, ranks, num_dimms, rank, lmc, node);
    rank = 2;
    if (c->odt_mask1.s.pasr_10)
        bdk_config_set_int(c->odt_mask1.s.pasr_10, BDK_CONFIG_DDR_RANKS_MODE1_PASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.asr_10)
        bdk_config_set_int(c->odt_mask1.s.asr_10, BDK_CONFIG_DDR_RANKS_MODE1_ASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.srt_10)
        bdk_config_set_int(c->odt_mask1.s.srt_10, BDK_CONFIG_DDR_RANKS_MODE1_SRT, ranks, num_dimms, rank, lmc, node);
    rtt_wr = c->odt_mask1.s.rtt_wr_10;
    rtt_wr |= c->odt_mask1.s.rtt_wr_10_ext << 2;
    if (rtt_wr)
        bdk_config_set_int(rtt_wr, BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.dic_10)
        bdk_config_set_int(c->odt_mask1.s.dic_10, BDK_CONFIG_DDR_RANKS_MODE1_DIC, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.rtt_nom_10)
        bdk_config_set_int(c->odt_mask1.s.rtt_nom_10, BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM, ranks, num_dimms, rank, lmc, node);
    rank = 3;
    if (c->odt_mask1.s.pasr_11)
        bdk_config_set_int(c->odt_mask1.s.pasr_11, BDK_CONFIG_DDR_RANKS_MODE1_PASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.asr_11)
        bdk_config_set_int(c->odt_mask1.s.asr_11, BDK_CONFIG_DDR_RANKS_MODE1_ASR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.srt_11)
        bdk_config_set_int(c->odt_mask1.s.srt_11, BDK_CONFIG_DDR_RANKS_MODE1_SRT, ranks, num_dimms, rank, lmc, node);
    rtt_wr = c->odt_mask1.s.rtt_wr_11;
    rtt_wr |= c->odt_mask1.s.rtt_wr_11_ext << 2;
    if (rtt_wr)
        bdk_config_set_int(rtt_wr, BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.dic_11)
        bdk_config_set_int(c->odt_mask1.s.dic_11, BDK_CONFIG_DDR_RANKS_MODE1_DIC, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask1.s.rtt_nom_11)
        bdk_config_set_int(c->odt_mask1.s.rtt_nom_11, BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM, ranks, num_dimms, rank, lmc, node);
    rank = 0;
    if (c->odt_mask2.s.rtt_park_00)
        bdk_config_set_int(c->odt_mask2.s.rtt_park_00, BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_value_00)
        bdk_config_set_int(c->odt_mask2.s.vref_value_00, BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_range_00)
        bdk_config_set_int(c->odt_mask2.s.vref_range_00, BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vrefdq_train_en)
        bdk_config_set_int(c->odt_mask2.s.vrefdq_train_en, BDK_CONFIG_DDR_RANKS_MODE2_VREFDQ_TRAIN_EN, ranks, num_dimms, lmc, node);
    rank = 1;
    if (c->odt_mask2.s.rtt_park_01)
        bdk_config_set_int(c->odt_mask2.s.rtt_park_01, BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_value_01)
        bdk_config_set_int(c->odt_mask2.s.vref_value_01, BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_range_01)
        bdk_config_set_int(c->odt_mask2.s.vref_range_01, BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE, ranks, num_dimms, rank, lmc, node);
    rank = 2;
    if (c->odt_mask2.s.rtt_park_10)
        bdk_config_set_int(c->odt_mask2.s.rtt_park_10, BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_value_10)
        bdk_config_set_int(c->odt_mask2.s.vref_value_10, BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_range_10)
        bdk_config_set_int(c->odt_mask2.s.vref_range_10, BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE, ranks, num_dimms, rank, lmc, node);
    rank = 3;
    if (c->odt_mask2.s.rtt_park_11)
        bdk_config_set_int(c->odt_mask2.s.rtt_park_11, BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_value_11)
        bdk_config_set_int(c->odt_mask2.s.vref_value_11, BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE, ranks, num_dimms, rank, lmc, node);
    if (c->odt_mask2.s.vref_range_11)
        bdk_config_set_int(c->odt_mask2.s.vref_range_11, BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE, ranks, num_dimms, rank, lmc, node);

    /* Fill more global items */
    if (c->qs_dic)
        bdk_config_set_int(c->qs_dic, BDK_CONFIG_DDR_RANKS_RODT_CTL, ranks, num_dimms, lmc, node);
    if (c->rodt_ctl)
        bdk_config_set_int(c->rodt_ctl, BDK_CONFIG_DDR_RANKS_RODT_MASK, ranks, num_dimms, lmc, node);
}

/**
 * Convert the supplied DRAM config into a device tree. The conversion modifies
 * the current in memory device tree by adding items that would create this DRAM
 * config. This function doesn't check for conflicting entries already in the
 * device tree, so care must be used. Use bdk_config_show() to display the device
 * tree as a DTS the user can cut/paste.
 *
 * @param node   Node the config is for
 * @param cfg    Config to convert
 */
void __bdk_dram_convert_to_dts(bdk_node_t node, const dram_config_t *cfg)
{
    const int MAX_LMCS = sizeof(cfg->config) / sizeof(cfg->config[0]);

    /* Fill the SPD data first as some parameters need to know the DRAM type
       to lookup the correct values */
    for (int lmc = 0; lmc < MAX_LMCS; lmc++)
    {
        for (int dimm = 0; dimm < DDR_CFG_T_MAX_DIMMS; dimm++)
        {
            int spd_addr = cfg->config[lmc].dimm_config_table[dimm].spd_addrs[0];
            if (spd_addr)
            {
                bdk_config_set_int(spd_addr, BDK_CONFIG_DDR_SPD_ADDR, dimm, lmc, node);
            }
            else
            {
                const void *spd_data = cfg->config[lmc].dimm_config_table[dimm].spd_ptrs[0];
                if (spd_data)
                    bdk_fatal("Fixed SPD data not supported yet\n");
            }
        }
    }

    for (int lmc = 0; lmc < MAX_LMCS; lmc++)
    {
        for (int num_dimms = 1; num_dimms <= DDR_CFG_T_MAX_DIMMS; num_dimms++)
        {
            store_rank_data(cfg, 1, num_dimms, lmc, node);
            store_rank_data(cfg, 2, num_dimms, lmc, node);
            store_rank_data(cfg, 4, num_dimms, lmc, node);
        }

        const ddr_configuration_t *c = &cfg->config[lmc];
        const ddr3_custom_config_t *custom = &c->custom_lmc_config;
        if (custom->min_rtt_nom_idx)
            bdk_config_set_int(custom->min_rtt_nom_idx, BDK_CONFIG_DDR_CUSTOM_MIN_RTT_NOM_IDX, lmc, node);
        if (custom->max_rtt_nom_idx)
            bdk_config_set_int(custom->max_rtt_nom_idx, BDK_CONFIG_DDR_CUSTOM_MAX_RTT_NOM_IDX, lmc, node);
        if (custom->min_rodt_ctl)
            bdk_config_set_int(custom->min_rodt_ctl, BDK_CONFIG_DDR_CUSTOM_MIN_RODT_CTL, lmc, node);
        if (custom->max_rodt_ctl)
            bdk_config_set_int(custom->max_rodt_ctl, BDK_CONFIG_DDR_CUSTOM_MAX_RODT_CTL, lmc, node);
        if (custom->ck_ctl)
            bdk_config_set_int(custom->ck_ctl, BDK_CONFIG_DDR_CUSTOM_CK_CTL, lmc, node);
        if (custom->cmd_ctl)
            bdk_config_set_int(custom->cmd_ctl, BDK_CONFIG_DDR_CUSTOM_CMD_CTL, lmc, node);
        if (custom->ctl_ctl)
            bdk_config_set_int(custom->ctl_ctl, BDK_CONFIG_DDR_CUSTOM_CTL_CTL, lmc, node);
        if (custom->min_cas_latency)
            bdk_config_set_int(custom->min_cas_latency, BDK_CONFIG_DDR_CUSTOM_MIN_CAS_LATENCY, lmc, node);
        if (custom->offset_en)
            bdk_config_set_int(custom->offset_en, BDK_CONFIG_DDR_CUSTOM_OFFSET_EN, lmc, node);
        if (custom->offset_udimm)
            bdk_config_set_int(custom->offset_udimm, BDK_CONFIG_DDR_CUSTOM_OFFSET, "UDIMM", lmc, node);
        if (custom->offset_rdimm)
            bdk_config_set_int(custom->offset_rdimm, BDK_CONFIG_DDR_CUSTOM_OFFSET, "RDIMM", lmc, node);
        if (custom->rlevel_compute)
            bdk_config_set_int(custom->rlevel_compute, BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMPUTE, lmc, node);
        if (custom->ddr_rtt_nom_auto)
            bdk_config_set_int(custom->ddr_rtt_nom_auto, BDK_CONFIG_DDR_CUSTOM_DDR_RTT_NOM_AUTO, lmc, node);
        if (custom->ddr_rodt_ctl_auto)
            bdk_config_set_int(custom->ddr_rodt_ctl_auto, BDK_CONFIG_DDR_CUSTOM_DDR_RODT_CTL_AUTO, lmc, node);
        if (custom->rlevel_comp_offset_udimm)
            bdk_config_set_int(custom->rlevel_comp_offset_udimm, BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMP_OFFSET, "UDIMM", lmc, node);
        if (custom->rlevel_comp_offset_rdimm)
            bdk_config_set_int(custom->rlevel_comp_offset_rdimm, BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMP_OFFSET, "RDIMM", lmc, node);
        if (custom->rlevel_average_loops)
            bdk_config_set_int(custom->rlevel_average_loops, BDK_CONFIG_DDR_CUSTOM_RLEVEL_AVERAGE_LOOPS, lmc, node);
        if (custom->ddr2t_udimm)
            bdk_config_set_int(custom->ddr2t_udimm, BDK_CONFIG_DDR_CUSTOM_DDR2T, "UDIMM", lmc, node);
        if (custom->ddr2t_rdimm)
            bdk_config_set_int(custom->ddr2t_rdimm, BDK_CONFIG_DDR_CUSTOM_DDR2T, "RDIMM", lmc, node);
        if (custom->disable_sequential_delay_check)
            bdk_config_set_int(custom->disable_sequential_delay_check, BDK_CONFIG_DDR_CUSTOM_DISABLE_SEQUENTIAL_DELAY_CHECK, lmc, node);
        if (custom->maximum_adjacent_rlevel_delay_increment)
            bdk_config_set_int(custom->maximum_adjacent_rlevel_delay_increment, BDK_CONFIG_DDR_CUSTOM_MAXIMUM_ADJACENT_RLEVEL_DELAY_INCREMENT, lmc, node);
        if (custom->parity)
            bdk_config_set_int(custom->parity, BDK_CONFIG_DDR_CUSTOM_PARITY, lmc, node);
        if (custom->fprch2)
            bdk_config_set_int(custom->fprch2, BDK_CONFIG_DDR_CUSTOM_FPRCH2, lmc, node);
        if (custom->mode32b)
            bdk_config_set_int(custom->mode32b, BDK_CONFIG_DDR_CUSTOM_MODE32B, lmc, node);
        if (custom->measured_vref)
            bdk_config_set_int(custom->measured_vref, BDK_CONFIG_DDR_CUSTOM_MEASURED_VREF, lmc, node);
        /* Loop through 8 bytes, plus ecc byte */
        #define NUM_BYTES 9 /* Max bytes on LMC (8 plus ECC) */
        for (int b = 0; b < NUM_BYTES; b++)
        {
            if (custom->dll_write_offset && custom->dll_write_offset[b])
                bdk_config_set_int(custom->dll_write_offset[b], BDK_CONFIG_DDR_CUSTOM_DLL_WRITE_OFFSET, b, lmc, node);
            if (custom->dll_read_offset && custom->dll_read_offset[b])
                bdk_config_set_int(custom->dll_read_offset[b], BDK_CONFIG_DDR_CUSTOM_DLL_READ_OFFSET, b, lmc, node);
        }
    }

    int speed = cfg->ddr_clock_hertz * 2 / 1000000;
    if (speed == 1880)
        speed = 1866;
    if (speed == 2100)
        speed = 2133;
    bdk_config_set_int(speed, BDK_CONFIG_DDR_SPEED, node);
};

#include <bdk.h>

/**
 * Return the number of LMC controllers in use
 *
 * @param node   Node to probe
 *
 * @return 2 or 4 depending on the mode
 */
int __bdk_dram_get_num_lmc(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_dll_ctl2, node, BDK_LMCX_DLL_CTL2(2)); // sample LMC2
    return (lmcx_dll_ctl2.s.intf_en) ? 4 : 2;
}

/**
 * Return a mask of the number of row bits in use
 *
 * @param node   Node to probe
 *
 */ 
uint32_t __bdk_dram_get_row_mask(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(0)); // sample LMC0
    int numbits = 14 + lmcx_config.s.pbank_lsb - lmcx_config.s.row_lsb - lmcx_config.s.rank_ena;
    return ((1ul << numbits) - 1);
}

/**
 * Return a mask of the number of column bits in use
 *
 * @param node   Node to probe
 *
 */ 
uint32_t __bdk_dram_get_col_mask(bdk_node_t node)
{
    int xbits = (__bdk_dram_get_num_lmc(node) >> 1); 
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(0)); // sample LMC0
    int numbits = 11 + lmcx_config.s.row_lsb - __bdk_dram_get_num_bank_bits(node);
    return ((1ul << numbits) - 1);
}

/**
 * Return the number of bank bits in use
 *
 * @param node   Node to probe
 *
 */ 
// all DDR3, and DDR4 x16 today, use only 3 bank bits; DDR4 x4 and x8 always have 4 bank bits
// NOTE: this will change in the future, when DDR4 x16 devices can come with 16 banks!! FIXME!!
int __bdk_dram_get_num_bank_bits(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(0)); // sample LMC0
    int bank_width = (__bdk_dram_is_ddr4(node) && (lmcx_config.s.bg2_enable)) ? 4 : 3; 
    return bank_width;
}

/**
 * Return whether the node has DDR3 or DDR4 DRAM
 *
 * @param node   Node to probe
 *
 * @return 0 (DDR3) or 1 (DDR4) depending on the mode
 */
int __bdk_dram_is_ddr4(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_ddr_pll_ctl, node, BDK_LMCX_DDR_PLL_CTL(0)); // sample LMC0
    return lmcx_ddr_pll_ctl.s.ddr4_mode;
}

/**
 * Get the amount of DRAM configured for a node. This is read from the LMC
 * controller after DRAM is setup.
 *
 * @param node   Node to query
 *
 * @return Size in megabytes
 */
uint64_t bdk_dram_get_size_mbytes(int node)
{
    /* Return zero if dram isn't enabled */
    if (!__bdk_is_dram_enabled(node))
        return 0;

    uint64_t memsize = 0;
    const int num_dram_controllers = __bdk_dram_get_num_lmc(node);
    for (int lmc = 0; lmc < num_dram_controllers; lmc++)
    {
        if (bdk_is_platform(BDK_PLATFORM_ASIM))
        {
            /* Asim doesn't simulate the rank detection, fake 4GB per controller */
            memsize += 4ull << 30;
        }
        else
        {
            BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(lmc));
            int num_ranks = bdk_pop(lmcx_config.s.init_status);
            uint64_t rank_size = 1ull << (28 + lmcx_config.s.pbank_lsb - lmcx_config.s.rank_ena);
            memsize += rank_size * num_ranks;
        }
    }
    return memsize >> 20;
}


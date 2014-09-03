#include <bdk.h>

/**
 * Return the numberof LMC controllers in use
 *
 * @param node   Node to probe
 *
 * @return 1, 2, or 4 depending on the chip and mode
 */
int __bdk_dram_get_num_lmc(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_dll_ctl2, node, BDK_LMCX_DLL_CTL2(2));
    if (lmcx_dll_ctl2.s.intf_en)
        return 4;
    else
        return 2;
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
        if (bdk_is_simulation())
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


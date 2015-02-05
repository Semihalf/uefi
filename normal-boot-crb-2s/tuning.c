#include <bdk.h>

/**
 * Per board custom tuning function. Called during QLM init and mode changes to
 * allow boards to supply custom tuning parameters. It is a weak symbol so boards
 * may choose not to implement it.
 *
 * @param node     Node number to be tuned
 * @param qlm      QLM to tune
 * @param mode     Mode the QLM is in
 * @param baud_mhz QLM baud rate in MHz
 */
void bdk_board_qlm_tune(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz)
{
    /* Tune the CCPI links */
    if ((qlm >= 8) && (qlm < 14))
    {
        for (int lane = 0; lane < 4; lane++)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
                c.s.cfg_tx_swing = 0x1c);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
                c.s.cfg_tx_premptap = 0x40);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
                c.s.tx_swing_ovrd_en = 1;
                c.s.tx_premptap_ovrd_val = 1);
        }
    }

}

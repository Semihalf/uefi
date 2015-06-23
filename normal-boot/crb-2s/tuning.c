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
    /* Tune the SATA links */
    for (int lane = 0; lane < 4; lane++)
    {
        int swing = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_QLM_TUNING_TX_SWING, node, qlm, lane);
        if (-1 != swing)
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
                c.s.cfg_tx_swing = swing);

        int premptap = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_QLM_TUNING_TX_PREMPTAP, node, qlm, lane);
        if (-1 != premptap)
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
                c.s.cfg_tx_premptap = premptap);

        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
            c.s.tx_swing_ovrd_en = (swing != -1 ? 1 : 0);
            c.s.tx_premptap_ovrd_val = (premptap != -1 ? 1 : 0));
    }
#if 0 /* This tuning is for the EVT2 and is incorrect for the EVT3 */
    /* Tune the CCPI links */
    if ((qlm >= 8) && (qlm < 14))
    {
        for (int lane = 0; lane < 4; lane++)
        {
            /* From Scott McIlhenny's email on 4/13/2015 */
            /*  Program the Tx swing and Tx emphasis Pre-cursor and
                    Post-cursor values {program Tx swing to 20decimal for
                    half swing and set Pre & Post to zero}
                Write GSER(8..13)_LANE(0..3)_TX_CFG_0.CFG_TX_SWING = 0x14
                Write GSER(8..13)_LANE(0..3)_TX_PRE_EMPHASIS.CFG_TX_PREMPTAP
                    CFG_TX_PREMPTAP[8:4] = 0x0
                    CFG_TX_PREMPTAP[3:0] = 0x0 */
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
                c.s.cfg_tx_swing = 0x14);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
                c.s.cfg_tx_premptap = 0x00);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
                c.s.tx_swing_ovrd_en = 1;
                c.s.tx_premptap_ovrd_val = 1);
        }
    }
#endif
}

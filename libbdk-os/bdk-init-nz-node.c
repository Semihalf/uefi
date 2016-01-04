#include <bdk.h>

#define CCPI_MIN_LANES 24
#define CCPI_MIN_LINKS 2
#define CCPI_MAX_LINKS 3
#define CCPI_SHORT_TIMEOUT 1 /* Seconds to wait for and CCPI links for quick detection of single node */
#define CCPI_MASTER_TIMEOUT 30 /* Seconds to wait for CCPI links */

#define EOL "\33[0K\r\n" /* Erase EOL */

/* The node number may change dynamically while this code is running. This
   variable contains its value after every update in the CCPI monitor loop */
static bdk_node_t node;
extern void __bdk_reset_thread(int arg1, void *arg2);

/**
 * Delay for the specified microseconds
 *
 * @param usec
 */
static void wait_usec(uint64_t usec)
{
    uint64_t timeout = bdk_clock_get_count(BDK_CLOCK_MAIN_REF) + bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF) * usec / 1000000;
    while (bdk_clock_get_count(BDK_CLOCK_MAIN_REF) < timeout)
    {
        /* Spin */
    }
}

static void uart_dec1(int v)
{
    bdk_dbg_uart_char('0' + v);
}

static void uart_dec2(int v)
{
    bdk_dbg_uart_char('0' + v / 10);
    bdk_dbg_uart_char('0' + v % 10);
}

#if 0 /* Disabled 12/17/2015 as GSER-27140 was found to break CCPI at 10G */
/**
 * (GSER-27140) SERDES temperature drift sensitivity in receiver
 * Issues have been found with the Bit Error Rate (BER) reliability of
 * 10GBASE-KR links over the commercial temperature range (0 to 100C),
 * especially when subjected to rapid thermal ramp stress testing. (See
 * HRM for corresponding case temperature requirements for each speed
 * grade.)
 *
 * @param node
 * @param qlm
 *
 * @return
 */
static int qlm_errata_gser_27140(bdk_node_t node, int qlm)
{
    /* I. For each GSER QLM: */
    /* Workaround GSER-27140: */
    /* (1) GSER-26150 */
    /* Disabled because it breaks CCPI on pass 1.x */
    /* (2) Write GSER()_LANE_VMA_FINE_CTRL_0[RX_SDLL_IQ_MAX_FINE] = 0xE */
    /* (3) Write GSER()_LANE_VMA_FINE_CTRL_0[RX_SDLL_IQ_MIN_FINE] = 0x8 */
    /* (4) Write GSER()_LANE_VMA_FINE_CTRL_0[RX_SDLL_IQ_STEP_FINE] = 0x2 */
    /* (5) Write GSER()_LANE_VMA_FINE_CTRL_0[VMA_WINDOW_WAIT_FINE] = 0x5 */
    /* (6) Write GSER()_LANE_VMA_FINE_CTRL_0[LMS_WAIT_TIME_FINE] = 0x5 */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_VMA_FINE_CTRL_0(qlm),
        c.s.rx_sdll_iq_max_fine = 0xE;
        c.s.rx_sdll_iq_min_fine = 0x8;
        c.s.rx_sdll_iq_step_fine = 0x2;
        c.s.vma_window_wait_fine = 0x5;
        c.s.lms_wait_time_fine = 0x5);
    /* (7) Write GSER()_LANE_VMA_FINE_CTRL_2[RX_PRECTLE_GAIN_MAX_FINE] = 0xB */
    /* (8) Write GSER()_LANE_VMA_FINE_CTRL_2[RX_PRECTLE_GAIN_MIN_FINE] = 0x6 */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_LANE_VMA_FINE_CTRL_2(qlm),
        c.s.rx_prectle_gain_max_fine = 0xB;
        c.s.rx_prectle_gain_min_fine = 0x6);
    /* (9) Write GSER()_RX_TXDIR_CTRL_0[RX_BOOST_LO_THRES] = 0x8 */
    /* (10) Write GSER()_RX_TXDIR_CTRL_0[RX_BOOST_HI_THRES] = 0xB */
    /* (11) Write GSER()_RX_TXDIR_CTRL_0[RX_BOOST_HI_VAL] = 0xF */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_RX_TXDIR_CTRL_0(qlm),
        c.s.rx_boost_lo_thrs = 0x8;
        c.s.rx_boost_hi_thrs = 0xB;
        c.s.rx_boost_hi_val = 0xF);
    /* (12) Write GSER()_RX_TXDIR_CTRL_1[RX_TAP1_LO_THRS] = 0x8 */
    /* (13) Write GSER()_RX_TXDIR_CTRL_1[RX_TAP1_HI_THRS] = 0x17 */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_RX_TXDIR_CTRL_1(qlm),
        c.s.rx_tap1_lo_thrs = 0x8;
        c.s.rx_tap1_hi_thrs = 0x17);

    /* Workaround GSER-26636: Applied elsewhere */
    /* (14) Write GSER()_RX_TXDIR_CTRL_1[RX_PRECORR_CHG_DIR] = 0x1 */
    /* (15) Write GSER()_RX_TXDIR_CTRL_1[RX_TAP1_CHG_DIR] = 0x1 */

    /* Workaround GSER-27140: */
    /* (16) Write GSER()_EQ_WAIT_TIME[RXEQ_WAIT_CNT] = 0x6 */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_EQ_WAIT_TIME(qlm),
        c.s.rxeq_wait_cnt = 0x6);
    /* (17) Write GSER()_RX_TXDIR_CTRL_2[RX_PRECORR_HI_THRS] = 0xFF */
    /* (18) Write GSER()_RX_TXDIR_CTRL_2[RX_PRECORR_LO_THRS] = 0x00 */
    BDK_CSR_MODIFY(c, node, BDK_GSERX_RX_TXDIR_CTRL_2(qlm),
        c.s.rx_precorr_hi_thrs = 0xFF;
        c.s.rx_precorr_lo_thrs = 0x00);

    /* II. For each GSER QLM SerDes lane: */
    /* Establish typical values, which are already reset values in pass 2: */
    for (int lane = 0; lane < 4; lane++)
    {
        /* (19) For each GSER lane in the 10GBASE-KR link: */
        /*    (a) Write GSER()_LANE()_RX_CTLE_CTRL[PCS_SDS_RX_CTLE_BIAS_CTRL] = 0x3 */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_RX_CTLE_CTRL(qlm, lane),
            c.s.pcs_sds_rx_ctle_bias_ctrl = 0x3);
        /*    (b) Write GSER()_LANE()_RX_CFG_4[CFG_RX_ERRDET_CTRL] = 0xCD6F */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_RX_CFG_4(qlm, lane),
            c.s.cfg_rx_errdet_ctrl = 0xCD6F);

        /* Workaround GSER-27140: */
        /* (20) For each GSER lane in the 10GBASE-KR link: */
        /*    (a) Write GSER()_LANE()_RX_VALBBD_CTRL_0[AGC_GAIN] = 0x3 */
        /*    (b) Write GSER()_LANE()_RX_VALBBD_CTRL_0[DFE_GAIN] = 0x2 */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_RX_VALBBD_CTRL_0(qlm, lane),
            c.s.agc_gain = 0x3;
            c.s.dfe_gain = 0x2);
    }

    /* III. The GSER QLM SerDes Lanes are now ready for 10GBASE-KR link training. */
    return 0;
}
#endif

static void restart_training(int lane)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
        return;
    /* Restart training */
    BDK_CSR_WRITE(node, BDK_OCX_LNEX_STATUS(lane), 0);
    BDK_CSR_MODIFY(c, node, BDK_OCX_LNEX_TRN_CTL(lane),
        c.s.done = 0);
}

/**
 * Read OCX setup used to determine which QLMs connect to which links
 *
 * @param node   Node to query
 * @param link   Link to query
 *
 * @return QLM mask of CCPI QLMs being used
 */
static int ccpi_get_qlm_select(int link)
{
    BDK_CSR_INIT(qlmx_cfg2, node, BDK_OCX_QLMX_CFG(2));
    BDK_CSR_INIT(qlmx_cfg3, node, BDK_OCX_QLMX_CFG(3));

    /* Determine which QLMs a link uses */
    int qlm_select = 0;
    /* qlmx_cfg2[ser_local]=1 means QLM2 is to link 1 */
    /* qlmx_cfg3[ser_local]=1 means QLM3 is to link 1 */
    switch (link)
    {
        case 0:
            qlm_select = (qlmx_cfg2.s.ser_local) ? 0x3 : 0x7;
            break;
        case 1:
            qlm_select = (qlmx_cfg2.s.ser_local) ? 0x4 : 0x0;
            qlm_select |= (qlmx_cfg3.s.ser_local) ? 0x8 : 0x0;
            break;
        case 2:
            qlm_select = (qlmx_cfg3.s.ser_local) ? 0x30 : 0x38;
            break;
    }
    return qlm_select;
}

/**
 * CN88XX pass 1.x required CCPI lane reversal to be programmed manually. This
 * function is called on the master node to setup lane reversal based on a
 * configuration parameter.
 */
static void ccpi_set_lane_reversal(void)
{
    int lane_reverse = bdk_config_get_int(BDK_CONFIG_CCPI_LANE_REVERSE);
    if (!lane_reverse)
        return;

    printf("N%d.CCPI: Applying lane reversal\n", node);

    for (int link = 0; link < CCPI_MAX_LINKS; link++)
    {
        /* QLM_SELECT must be zero before changing lane reversal */
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
            c.s.qlm_select = 0);
        /* Set RX lane reversal */
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
            c.s.lane_rev = 1);
    }
    /* Set TX lane reversal */
    BDK_CSR_MODIFY(c, node, BDK_OCX_LNE_DBG,
        c.s.tx_lane_rev = 1);
    /* Restore the QLM lane select */
    for (int link = 0; link < CCPI_MAX_LINKS; link++)
    {
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
            c.s.qlm_select = ccpi_get_qlm_select(link));
    }
}

/**
 * Called very early in during init of both the master and slave. It perfroms one
 * time init of CCPI QLM and link parameters. It must only be called once per
 * boot.
 *
 * @param is_master Non-zero if the caller is the master node
 */
void __bdk_init_ccpi_early(int is_master)
{
    /* Bail early if CCPI is disabled */
    BDK_CSR_INIT(gserx_phy_ctl, node, BDK_GSERX_PHY_CTL(8));
    if (gserx_phy_ctl.s.phy_reset)
        return;

    /* Make sure the link layer is down by disabling lane alignment */
    for (int link = 0; link < CCPI_MAX_LINKS; link++)
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
            c.s.lane_align_dis = 1);

    /* Disable the bad lane timer and clear all bad bits */
    for (int ccpi_qlm = 0; ccpi_qlm < 6; ccpi_qlm++)
    {
        BDK_CSR_MODIFY(c, node, BDK_OCX_QLMX_CFG(ccpi_qlm),
            c.s.timer_dis = 1;
            c.s.ser_lane_bad = 0);
        /* Errata (GSER-26636) KR training coefficient update inverted. As of pass 2
           this is the hardware default. It doesn't hurt to write it anyway */
        BDK_CSR_MODIFY(c, node, BDK_GSERX_RX_TXDIR_CTRL_1(ccpi_qlm + 8),
            c.s.rx_precorr_chg_dir = 1;
            c.s.rx_tap1_chg_dir = 1);
#if 0 /* Disabled 12/17/2015 as GSER-27140 was found to break CCPI at 10G */
        /* (GSER-27140) SERDES temperature drift sensitivity in receiver */
        qlm_errata_gser_27140(node, ccpi_qlm + 8);
#endif
    }

    /* Force training into manual mode so we can control it */
    for (int lane = 0; lane < 24; lane++)
    {
        BDK_CSR_DEFINE(trn_ld, BDK_OCX_LNEX_TRN_LD(lane));
        trn_ld.u = 0;
        trn_ld.s.lp_manual = 1;
        BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), trn_ld.u);
        restart_training(lane);
    }
}

/**
 * Brings the CCPI lanes and links into an operational state without perofrming
 * node discovery and enumeration. After this function succeeds, CCPI lanes and
 * links are ready for traffic, but node routing has not been setup.
 *
 * Note this function runs on the slave node with the BDK code not at its link
 * address. Many normal BDK functions do not work properly. Be careful.
 *
 * @param is_master  Non-zero when run on the master node. Zero when run on the slave
 * @param gbaud      Baud rate to run links at. This is only used if the QLMs are in software init
 *                   mode. If they are strapped for hardware init, the strapping speed is used.
 * @param ccpi_trace Non-zero to enable CCPI tracing. Note that tracing doesn't use the standard
 *                   bdk-trace functions. This code runs on the secondary node before we are
 *                   multi-node, and the C library doesn't work right.
 *
 * @return Zero on success, negative on failure. Zero means CCPI lanes and links are
 *         functional.
 */
int __bdk_init_ccpi_connection(int is_master, uint64_t gbaud, int ccpi_trace)
{
    /* Bail early if CCPI is disabled */
    BDK_CSR_INIT(gserx_phy_ctl, node, BDK_GSERX_PHY_CTL(8));
    if (gserx_phy_ctl.s.phy_reset)
        return -1;

    if (is_master)
        ccpi_set_lane_reversal();

    /* Default color, Reset scroll region, goto top, clear screen */
    if (ccpi_trace)
        bdk_dbg_uart_str("\33[0m" "\33[1;r" "\33[1;1H" "\33[2J");

    const uint64_t one_second = bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    const uint64_t start_time = bdk_clock_get_count(BDK_CLOCK_MAIN_REF);
    const uint64_t master_timeout = start_time + one_second * CCPI_MASTER_TIMEOUT;
    const uint64_t short_timeout = start_time + one_second * CCPI_SHORT_TIMEOUT;

    /* Loop forever trying to get CCPI links up */
    uint64_t link_up_time = start_time + one_second;
    while (1)
    {
        BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);
        wait_usec(100000);
        uint64_t wall_time = bdk_clock_get_count(BDK_CLOCK_MAIN_REF);

        if (is_master && (wall_time >= master_timeout))
        {
            if (ccpi_trace)
                bdk_dbg_uart_str("CCPI timeout, multi-node not available" EOL);
            return -1;
        }

        /* The node ID may change while we're running */
        int mpidr_el1;
        BDK_MRS(MPIDR_EL1, mpidr_el1);
        BDK_EXTRACT(node, mpidr_el1, 16, 8);

        if (ccpi_trace)
        {
            bdk_dbg_uart_str("\33[1;1H");
            BDK_CSR_INIT(mio_fus_dat2, node, BDK_MIO_FUS_DAT2);
            int major_pass = ((mio_fus_dat2.s.chip_id >> 3) & 7) + 1;
            int minor_pass = mio_fus_dat2.s.chip_id & 7;
            bdk_dbg_uart_str(bdk_version_string());
            bdk_dbg_uart_str(EOL);
            /* Print the node banner at the top of the screen */
            bdk_dbg_uart_str("Node ");
            uart_dec1(node);
            bdk_dbg_uart_str(" Pass ");
            uart_dec1(major_pass);
            bdk_dbg_uart_char('.');
            uart_dec1(minor_pass);
            bdk_dbg_uart_str(": Wating for CCPI" EOL);
        }

        int good_lanes = 0;
        /* Check status of the 6 CCPI QLMs */
        for (int ccpi_qlm = 0; ccpi_qlm < 6; ccpi_qlm++)
        {
            BDK_CSR_INIT(ocx_qlmx_cfg, node, BDK_OCX_QLMX_CFG(ccpi_qlm));

            if (ccpi_trace && (ccpi_qlm == 0))
            {
                if (ocx_qlmx_cfg.s.trn_ena && ocx_qlmx_cfg.s.trn_rxeq_only)
                    bdk_dbg_uart_str("KR Training: RX equalization only" EOL);
                else if (ocx_qlmx_cfg.s.trn_ena)
                    bdk_dbg_uart_str("KR Training: Enabled" EOL);
                else
                    bdk_dbg_uart_str("KR Training: Disabled" EOL);
                BDK_CSR_INIT(ocx_lnkx_cfg, node, BDK_OCX_LNKX_CFG(0));
                if (ocx_lnkx_cfg.s.lane_align_dis)
                    bdk_dbg_uart_str("Lane Alignment: Disabled" EOL);
                else
                    bdk_dbg_uart_str("Lane Alignment: Enabled" EOL);
            }

            for (int lane = ccpi_qlm * 4; lane < (ccpi_qlm + 1) * 4; lane++)
            {
                BDK_CSR_INIT(ocx_lnex_trn_ctl, node, BDK_OCX_LNEX_TRN_CTL(lane));
                int bad = (ocx_qlmx_cfg.s.ser_lane_bad >> (lane & 3)) & 1;
                int ready = (ocx_qlmx_cfg.s.ser_lane_ready >> (lane & 3)) & 1;
                int training_en = ocx_qlmx_cfg.s.trn_ena;
                int in_training = ocx_lnex_trn_ctl.s.ena;
                int training_done = ocx_lnex_trn_ctl.s.done;
                int good = ready && !bad && !in_training && training_done;

                if (ccpi_trace)
                {
                    bdk_dbg_uart_str("Lane ");
                    uart_dec2(lane);
                    bdk_dbg_uart_str(": ");
                }

                /* First we must exit electrical idle */
                if (!ocx_lnex_trn_ctl.s.eie_detect)
                {
                    if (ccpi_trace)
                        bdk_dbg_uart_str("Waiting for EIE");
                    restart_training(lane);
                    goto skip_lane;
                }

                /* Do training if it isn't done */
                if (in_training)
                {
                    if (ccpi_trace)
                        bdk_dbg_uart_str("Training");
                    int training_stable = 1;
                    BDK_CSR_INIT(trn_lp, node, BDK_OCX_LNEX_TRN_LP(lane));

                    union bdk_bgx_spu_br_train_cup_s cup;
                    cup.u = trn_lp.s.lp_cu_dat;
                    union bdk_bgx_spu_br_train_rep_s rep;
                    rep.u = trn_lp.s.lp_sr_dat;

                    /* Check link partner coefficient update field valid */
                    training_stable &= !cup.s.preset && !cup.s.init &&
                        (cup.s.post_cup == 0) && (cup.s.main_cup == 0) &&
                        (cup.s.pre_cup == 0);
                    /* Check link partner status report field valid */
                    training_stable &= (rep.s.post_cst == 0) &&
                        (rep.s.main_cst == 0) && (rep.s.pre_cst == 0);

                    rep.s.rx_ready = training_stable;
                    BDK_CSR_INIT(trn_ld, node, BDK_OCX_LNEX_TRN_LD(lane));
                    if ((trn_ld.s.ld_cu_dat != cup.u) || (trn_ld.s.ld_sr_dat != rep.u))
                    {
                        trn_ld.s.ld_cu_dat = cup.u;
                        trn_ld.s.ld_sr_dat = rep.u;
                        BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), trn_ld.u);
                    }

                    if (ccpi_trace)
                    {
                        const char *tmarkers = "=-+!"; /* Hold, Dec, Inc, Reserved */
                        const char *rmarkers = "=^-+"; /* No update, update, min, max */
                        bdk_dbg_uart_str("(TX:");
                        bdk_dbg_uart_str(cup.s.preset ? " PRESET" : "!preset");
                        bdk_dbg_uart_str(cup.s.init ? ", INIT" : ",!init");
                        bdk_dbg_uart_str(",post");
                        bdk_dbg_uart_char(tmarkers[cup.s.post_cup]);
                        bdk_dbg_uart_str(",main");
                        bdk_dbg_uart_char(tmarkers[cup.s.main_cup]);
                        bdk_dbg_uart_str(",pre");
                        bdk_dbg_uart_char(tmarkers[cup.s.pre_cup]);
                        bdk_dbg_uart_str(",RX:");
                        bdk_dbg_uart_str(rep.s.rx_ready ? " READY" : "!ready");
                        bdk_dbg_uart_str(",post");
                        bdk_dbg_uart_char(rmarkers[rep.s.post_cst]);
                        bdk_dbg_uart_str(",main");
                        bdk_dbg_uart_char(rmarkers[rep.s.main_cst]);
                        bdk_dbg_uart_str(",pre");
                        bdk_dbg_uart_char(rmarkers[rep.s.pre_cst]);
                        bdk_dbg_uart_char(')');

                        BDK_CSR_INIT(tap, node, BDK_GSERX_BR_TXX_TAP(ccpi_qlm + 8, lane & 3));
                        bdk_dbg_uart_str("post=");
                        uart_dec2(tap.s.txt_post);
                        bdk_dbg_uart_str(",main=");
                        uart_dec2(tap.s.txt_swing);
                        bdk_dbg_uart_str(",pre=");
                        uart_dec2(tap.s.txt_pre);
                        if (training_stable)
                            bdk_dbg_uart_str(" (Ready)");
                    }
                    goto skip_lane;
                }

                if (!training_done)
                {
                    if (ccpi_trace)
                        bdk_dbg_uart_str("Waiting for training done");
                    goto skip_lane;
                }

                if (bad)
                {
                    if (ccpi_trace)
                        bdk_dbg_uart_str("Clearing bad");
                    /* Clear the bad flag */
                    ocx_qlmx_cfg.s.ser_lane_bad &= ~(1 << (lane & 3));
                    BDK_CSR_WRITE(node, BDK_OCX_QLMX_CFG(ccpi_qlm), ocx_qlmx_cfg.u);
                    BDK_CSR_READ(node, BDK_OCX_QLMX_CFG(ccpi_qlm));
                    goto skip_lane;
                }

                if (!ready)
                {
                    if (training_en)
                        restart_training(lane);
                    if (ccpi_trace)
                        bdk_dbg_uart_str("Waiting for ready");
                    goto skip_lane;
                }

                if (ccpi_trace)
                    bdk_dbg_uart_str(good ? "Good" : "Unknown");

                if (good)
                    good_lanes++;
skip_lane:
                if (ccpi_trace)
                    bdk_dbg_uart_str(EOL);
            }
        }

        if (ccpi_trace)
        {
            bdk_dbg_uart_str("CCPI Lanes Ready: ");
            uart_dec2(good_lanes);
            bdk_dbg_uart_str(EOL);
        }

        if (is_master && (wall_time >= short_timeout) && (good_lanes == 0))
        {
            if (ccpi_trace)
                bdk_dbg_uart_str("CCPI node not detected, multi-node not available" EOL);
            return -1;
        }

        /* Don't check links until all lanes are up */
        if (good_lanes < CCPI_MIN_LANES)
        {
            BDK_CSR_INIT(ocx_lnkx_cfg, node, BDK_OCX_LNKX_CFG(0));
            if (ocx_lnkx_cfg.s.lane_align_dis == 0)
            {
                /* Make sure the link layer is down using lane alignment */
                for (int link = 0; link < CCPI_MAX_LINKS; link++)
                    BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
                        c.s.lane_align_dis = 1);
            }
            goto skip_links;
        }

        int valid_links = 0;
        /* Check that the three CCPI links are operating */
        for (int link = 0; link < CCPI_MAX_LINKS; link++)
        {
            /* If lane alignment is disabled, enable it and wait 100ms */
            BDK_CSR_INIT(ocx_lnkx_cfg, node, BDK_OCX_LNKX_CFG(link));
            if (ocx_lnkx_cfg.s.lane_align_dis)
            {
                BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
                    c.s.lane_align_dis = 0);
                continue;
            }
            BDK_CSR_INIT(ocx_com_linkx_ctl, node, BDK_OCX_COM_LINKX_CTL(link));
            /* Clear bits that can get set by hardware/software on error */
            if (ocx_com_linkx_ctl.s.auto_clr || ocx_com_linkx_ctl.s.drop ||
                ocx_com_linkx_ctl.s.reinit)
            {
                ocx_com_linkx_ctl.s.auto_clr = 0;
                ocx_com_linkx_ctl.s.drop = 0;
                ocx_com_linkx_ctl.s.reinit = 0;
                BDK_CSR_WRITE(node, BDK_OCX_COM_LINKX_CTL(link), ocx_com_linkx_ctl.u);
            }
            /* If the link is up and valid, check the credits */
            else if (ocx_com_linkx_ctl.s.up && ocx_com_linkx_ctl.s.valid)
            {
                BDK_CSR_INIT(ocx_tlkx_lnk_vcx_cnt, node, BDK_OCX_TLKX_LNK_VCX_CNT(link, 0));
                if (ocx_tlkx_lnk_vcx_cnt.s.count == 0)
                {
                    /* No credits, perform a reinit */
                    ocx_com_linkx_ctl.s.reinit = 1;
                    BDK_CSR_WRITE(node, BDK_OCX_COM_LINKX_CTL(link), ocx_com_linkx_ctl.u);
                    /* Reinit will be cleared teh next time through the loop */
                    if (ccpi_trace)
                    {
                        bdk_dbg_uart_str("Re-init link ");
                        uart_dec1(link);
                        bdk_dbg_uart_str(EOL);
                    }
                }
                else
                    valid_links |= 1 << link;
            }
        }

        /* Rquire the links to be valid for a length of time before marking everything good */
        if ((bdk_pop(valid_links) >= CCPI_MIN_LINKS) && (wall_time >= link_up_time))
        {
            /* Reset if we loose a link */
            BDK_CSR_WRITE(node, BDK_RST_OCX, valid_links);
            BDK_CSR_READ(node, BDK_RST_OCX);
            if (ccpi_trace)
            {
                uart_dec1(bdk_pop(valid_links));
                bdk_dbg_uart_str(" CCPI links up" EOL);
            }
            return 0;
        }
        else if (valid_links < CCPI_MIN_LINKS)
            link_up_time = wall_time + one_second;
skip_links:
        if (ccpi_trace)
            bdk_dbg_uart_str("\33[0J"); /* Erase EOS */
    }
}

/**
 * This function is called if we boot on a node that isn't the
 * one we were linked for
 */
void __bdk_init_incorrect_node(void)
{
    /* We're booting from a non-zero node. We can't call many C functions as
       we're running at an address other than our link address */
    int uart = 0;
    node = bdk_numa_local();

    /* Don't reset if a link change state */
    BDK_CSR_WRITE(node, BDK_RST_OCX, 0);
    __bdk_init_ccpi_early(0);

    /* Temporarily change the master node global to this node so some
       functions will work properly when called */
    extern int __bdk_numa_master_node;
    __bdk_numa_master_node = node;

    /* Power gate other cores */
    BDK_CSR_WRITE(node, BDK_RST_PP_POWER, -1);

    /* Setup the uart using only inline C functons */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.uaa_rst = 1;
        c.s.uctl_rst = 1);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.h_clkdiv_sel = 3; /* Run at SCLK / 6, matches emulator */
        c.s.h_clk_byp_sel = 0;
        c.s.h_clk_en = 1);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart),
        c.s.h_clkdiv_rst = 0);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.uctl_rst = 0);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.uaa_rst = 0);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_UCTL_CTL(uart), c.s.csclk_en = 1);
    BDK_CSR_INIT(rst_boot, node, BDK_RST_BOOT);

    uint64_t divisor_x_64 = 50000000ull * rst_boot.s.pnr_mul / (BDK_UART_BAUDRATE * 16 * 6 / 64);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_IBRD(uart),
        c.s.baud_divint = divisor_x_64 >> 6);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_FBRD(uart),
        c.s.baud_divfrac = divisor_x_64 & 0x3f);
    BDK_CSR_MODIFY(c, node, BDK_UAAX_LCR_H(uart),
        c.s.sps = 0; /* No parity */
        c.s.wlen = 3; /* 8 bits */
        c.s.fen = 1; /* FIFOs enabled */
        c.s.stp2 = 0; /* Use one stop bit, not two */
        c.s.eps = 0; /* No parity */
        c.s.pen = 0; /* No parity */
        c.s.brk = 0); /* Don't send a break */
    BDK_CSR_MODIFY(c, node, BDK_UAAX_CR(uart),
        c.s.ctsen = 0;
        c.s.rtsen = 0;
        c.s.out1 = 1; /* Drive data carrier detect */
        c.s.rts = 0; /* Don't override RTS */
        c.s.dtr = 0; /* Don't override DTR */
        c.s.rxe = 1; /* Enable receive */
        c.s.txe = 1; /* Enable transmit */
        c.s.lbe = 0; /* Disable loopback */
        c.s.uarten = 1); /* Enable uart */
    BDK_CSR_READ(node, BDK_UAAX_CR(uart));

    /* Pass 2 report bad model on some resets */
    uint64_t model;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (model));
    if (model == 0x430f0a17)
    {
        bdk_dbg_uart_str("Soft reset to fix MIDR_EL1" EOL);
        wait_usec(500000);
        BDK_CSR_READ(node, BDK_RST_SOFT_RST);
        BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, 1);
    }

    __bdk_init_ccpi_connection(0, 0, 1);
    bdk_dbg_uart_str("Putting core in reset" EOL);
    __bdk_reset_thread(0, NULL);
}

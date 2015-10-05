#include <bdk.h>

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT (13351*3) /* 15sec at 700Mhz */
#define CCPI_MIN_LANES 24

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

/**
 * Apply custom tuning to the CCPI QLMs on the slave node
 *
 * @param qlm    QLM to tune
 */
static void qlm_tune(int qlm)
{
    /* Skip tuning for CCPI running KR training as tuning overrides
       the values found by training */
    BDK_CSR_INIT(qlm_cfg, node, BDK_OCX_QLMX_CFG(qlm - 8));
    if (qlm_cfg.s.trn_ena)
        return;

    int baud_mhz;
    /* Use the OCI strapping to find the speed. This will not work if
       the OCI is in SW_MODE */
    BDK_CSR_INIT(gserx_spd, node, BDK_GSERX_SPD(qlm));
    switch (gserx_spd.s.spd)
    {
        case 0x0:
            baud_mhz = 1250; /* Ref 100Mhz */
            break;
        case 0x1:
            baud_mhz = 2500;
            break;
        case 0x2:
            baud_mhz = 5000;
            break;
        case 0x3:
            baud_mhz = 8000;
            break;
        case 0x4:
            baud_mhz = 1250; /* Ref 125Mhz */
            break;
        case 0x5:
            baud_mhz = 2500;
            break;
        case 0x6:
            baud_mhz = 3125;
            break;
        case 0x7:
            baud_mhz = 5000;
            break;
        case 0x8:
            baud_mhz = 6250;
            break;
        case 0x9:
            baud_mhz = 8000;
            break;
        case 0xa:
            baud_mhz = 2500; /* Ref 156.25Mhz */
            break;
        case 0xb:
            baud_mhz = 3125;
            break;
        case 0xc:
            baud_mhz = 5000;
            break;
        case 0xd:
            baud_mhz = 6250;
            break;
        case 0xe:
            baud_mhz = 10312;
            break;
        default: /* Software mode */
            baud_mhz = 0;
            break;
    }

    if (baud_mhz == 6250)
    {
        /* Change the default tuning for 6.25G, from lab measurements */
        for (int lane = 0; lane < 4; lane++)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
                c.s.cfg_tx_swing = 0xc);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
                c.s.cfg_tx_premptap = 0xc0);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
                c.s.tx_swing_ovrrd_en = 1;
                c.s.tx_premptap_ovrrd_val = 1);
        }
    }
    else if (baud_mhz == 10312)
    {
        /* Change the default tuning for 10.3125G, from lab measurements */
        for (int lane = 0; lane < 4; lane++)
        {
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_0(qlm, lane),
                c.s.cfg_tx_swing = 0xd);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_PRE_EMPHASIS(qlm, lane),
                c.s.cfg_tx_premptap = 0xd0);
            BDK_CSR_MODIFY(c, node, BDK_GSERX_LANEX_TX_CFG_1(qlm, lane),
                c.s.tx_swing_ovrrd_en = 1;
                c.s.tx_premptap_ovrrd_val = 1);
        }
    }
}

/**
 * Called to monitor CCPI and continually try and get CCPI links up. Once the
 * links are up, the core is put in reset so the master node can take over.
 */
static void monitor_ccpi(void)
{
    bdk_dbg_uart_str("Monitoring CCPI\r\n");

    /* Don't reset if a link change state */
    BDK_CSR_WRITE(node, BDK_RST_OCX, 0);

    /* Make sure the link layer is down using lane alignment */
    for (int link = 0; link < 3; link++)
        BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
            c.s.lane_align_dis = 1);

    /* Apply CCPI custom tuning */
    for (int qlm = 8; qlm < 14; qlm++)
        qlm_tune(qlm);

    /* Loop forever trying to get CCPI links up */
    int loop_count = 0;
    uint64_t link_up_time = bdk_clock_get_count(BDK_CLOCK_MAIN_REF) + bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    while (1)
    {
        /* The node ID may change while we're running */
        int mpidr_el1;
        BDK_MRS(MPIDR_EL1, mpidr_el1);
        BDK_EXTRACT(node, mpidr_el1, 16, 8);

        /* Put a spinner on the screen so we can tell the loop os running */
        const int SPINNER_SHIFT = 16;
        if ((loop_count & ((1<<SPINNER_SHIFT)-1)) == 0)
        {
            char *spinner = "/-\\|";
            bdk_dbg_uart_char(spinner[(loop_count >> SPINNER_SHIFT) & 3]);
            bdk_dbg_uart_char('\r');
        }
        loop_count++;

        int good_lanes = 0;
        /* Check status of the 6 CCPI QLMs */
        for (int ccpi_qlm = 0; ccpi_qlm < 6; ccpi_qlm++)
        {
            BDK_CSR_INIT(ocx_qlmx_cfg, node, BDK_OCX_QLMX_CFG(ccpi_qlm));

            int stuck_training = 0;
            /* If training is enabled, check that each lane has completed
               training. */
            if (ocx_qlmx_cfg.s.trn_ena)
            {
                /* Make sure no lanes are stuck in training */
                for (int lane = ccpi_qlm * 4; lane < (ccpi_qlm + 1) * 4; lane++)
                {
                    int bad = (ocx_qlmx_cfg.s.ser_lane_bad >> (lane & 3)) & 1;
                    BDK_CSR_INIT(ocx_lnex_trn_ctl, node, BDK_OCX_LNEX_TRN_CTL(lane));
                    /* CN88XX pass 1.x can get stuck in training. This code
                       implements a workaround when this is detected. This
                       is Errata (OCX-23422) */
                    if (bad && !ocx_lnex_trn_ctl.s.done)
                    {
                        stuck_training = 1;
                        /* We can't start the workaround until both the valid
                           bits are set */
                        BDK_CSR_INIT(ocx_lnex_trn_ld, node, BDK_OCX_LNEX_TRN_LD(lane));
                        if (!ocx_lnex_trn_ld.s.ld_cu_val || !ocx_lnex_trn_ld.s.ld_sr_val)
                            continue;
                        /* OCX_LNEX_TRN_LP must be read multiple times as the
                           valid bit changes dynamically */
                        BDK_CSR_INIT(ocx_lnex_trn_lp, node, BDK_OCX_LNEX_TRN_LP(lane));
                        while (!ocx_lnex_trn_lp.s.lp_cu_val)
                            ocx_lnex_trn_lp.u = BDK_CSR_READ(node, BDK_OCX_LNEX_TRN_LP(lane));
                        const char *final_status = "";
                        /* Check if a CU message was lost */
                        if ((ocx_lnex_trn_ld.s.ld_cu_dat != 0) && (ocx_lnex_trn_ld.s.ld_sr_dat == 0))
                        {
                            /* We lost a CU message */
                            BDK_CSR_DEFINE(trn_ld, BDK_OCX_LNEX_TRN_LD(lane));
                            trn_ld.u = 0;
                            BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), trn_ld.u);
                            BDK_CSR_READ(node, BDK_OCX_LNEX_TRN_LD(lane));
                            wait_usec(1);
                            trn_ld.s.ld_cu_dat = ocx_lnex_trn_ld.s.ld_cu_dat;
                            BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), trn_ld.u);
                            wait_usec(300000);
                            ocx_lnex_trn_ctl.u = BDK_CSR_READ(node, BDK_OCX_LNEX_TRN_CTL(lane));
                            if (ocx_lnex_trn_ctl.s.done)
                                final_status = " (CU lost, fixed)";
                            else
                                final_status = " (CU lost)";
                        }
                        /* Check if a SR message was lost */
                        if ((ocx_lnex_trn_ld.s.ld_cu_dat == 0) && (ocx_lnex_trn_ld.s.ld_sr_dat == 0x8000))
                        {
                            /* We lost a SR message */
                            BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), 1);
                            BDK_CSR_READ(node, BDK_OCX_LNEX_TRN_LD(lane));
                            wait_usec(1);
                            BDK_CSR_WRITE(node, BDK_OCX_LNEX_TRN_LD(lane), 0x8000);
                            wait_usec(300000);
                            ocx_lnex_trn_ctl.u = BDK_CSR_READ(node, BDK_OCX_LNEX_TRN_CTL(lane));
                            if (ocx_lnex_trn_ctl.s.done)
                                final_status = " (SR lost, fixed)";
                            else
                                final_status = " (SR lost)";
                        }
                        bdk_dbg_uart_str("Lane ");
                        bdk_dbg_uart_char('0' + lane / 10);
                        bdk_dbg_uart_char('0' + lane % 10);
                        bdk_dbg_uart_str(" TRN_LD=");
                        bdk_dbg_uart_hex(ocx_lnex_trn_ld.u);
                        bdk_dbg_uart_str(" TRN_LP=");
                        bdk_dbg_uart_hex(ocx_lnex_trn_lp.u);
                        bdk_dbg_uart_str(final_status);
                        bdk_dbg_uart_str("\r\n");
                        break; /* Skip other lanes until this one works */
                    }
                }
            }
            /* Don't bother checking for up lanes if one is stuck in training */
            if (stuck_training)
                break;

#if 0       // FIXME: RX equalization
            /* Do three time to make usre there are no glitches */
            for (int repeat = 0; repeat < 3; repeat++)
                while (bdk_qlm_rx_equalization(node, qlm, -1))
                    wait_usec(100);
#endif
            /* Make sure no lanes are bad, and all lanes are good */
            if (ocx_qlmx_cfg.s.ser_lane_bad)
            {
                int qlm = ccpi_qlm + 8;
                bdk_dbg_uart_str("QLM");
                bdk_dbg_uart_char('0' + qlm / 10);
                bdk_dbg_uart_char('0' + qlm % 10);
                bdk_dbg_uart_str(": ready ");
                bdk_dbg_uart_hex(ocx_qlmx_cfg.s.ser_lane_ready);
                bdk_dbg_uart_str(", bad ");
                bdk_dbg_uart_hex(ocx_qlmx_cfg.s.ser_lane_bad);
                bdk_dbg_uart_str("\r\n");
                ocx_qlmx_cfg.s.ser_lane_bad = 0;
                ocx_qlmx_cfg.s.ser_lane_ready = 0xf;
                BDK_CSR_WRITE(node, BDK_OCX_QLMX_CFG(ccpi_qlm), ocx_qlmx_cfg.u);
                continue;
            }
            /* Add the good lanes to the lane count */
            good_lanes += bdk_dpop(ocx_qlmx_cfg.s.ser_lane_ready);
        }

        /* Don't check links until all lanes are up */
        if (good_lanes != CCPI_MIN_LANES)
        {
            /* Make sure the link layer is down using lane alignment */
            for (int link = 0; link < 3; link++)
                BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
                    c.s.lane_align_dis = 1);
            continue;
        }

        int valid_links = 0;
        /* Check that the three CCPI links are operating */
        for (int link = 0; link < 3; link++)
        {
            /* If lane alignment is disabled, enable it and wait 100ms */
            BDK_CSR_INIT(ocx_lnkx_cfg, node, BDK_OCX_LNKX_CFG(link));
            if (ocx_lnkx_cfg.s.lane_align_dis)
            {
                BDK_CSR_MODIFY(c, node, BDK_OCX_LNKX_CFG(link),
                    c.s.lane_align_dis = 0);
                wait_usec(100000);
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
                    /* Reinit wil lbe cleared teh next time through the loop */
                    //bdk_dbg_uart_str("Re-init link ");
                    //bdk_dbg_uart_char('0' + link);
                    //bdk_dbg_uart_str("\r\n");
                }
                else
                    valid_links++;
            }
        }
        /* Rquire the links to be valid for a length of time before marking everything good */
        if ((valid_links >= 2) && (bdk_clock_get_count(BDK_CLOCK_MAIN_REF) >= link_up_time))
        {
            bdk_dbg_uart_char('0' + valid_links);
            /* Disable watchdog */
            if (WATCHDOG_TIMEOUT)
                BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
            bdk_dbg_uart_str(" CCPI links up. Putting core in reset\r\n");
            __bdk_reset_thread(0, NULL);
        }
        else if (valid_links < 2)
            link_up_time = bdk_clock_get_count(BDK_CLOCK_MAIN_REF) + bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);
    }
}

/**
 * This function is called if we boot on a node that isn't the
 * one we were linked for
 */
void __bdk_init_incorrect_node(void)
{
    /* We're booting from a non-zero node. This currently isn't supported, but
       happens by mistake when chip straps are wrong. We can't call many C
       functions as we're running at an address other than our link address */
    int uart = 0;
    node = bdk_numa_local();

    if (WATCHDOG_TIMEOUT)
    {
        /* Enable a watchdog to reset us if we don't come up quickly */
        BDK_CSR_MODIFY(c, node, BDK_GTI_CWD_WDOGX(bdk_get_core_num()),
            c.s.len = WATCHDOG_TIMEOUT;
            c.s.mode = 3);
    }

    /* Temporarily change the master node global to this node so some
       functions will work properly when called */
    extern int __bdk_numa_master_node;
    __bdk_numa_master_node = node;

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

    /* Power gate other cores */
    BDK_CSR_WRITE(node, BDK_RST_PP_POWER, -1);

    /* Spew out the node ID to uart0 as a hint that something is wrong */
    bdk_dbg_uart_str("\r\nNODE");
    bdk_dbg_uart_char('0' + node);
    bdk_dbg_uart_str("\r\n");

    /* CN88XX pass 1.x needs software workaround for CCPI. This
       call does those */
    uint64_t model;
    asm ("mrs %[rd],MIDR_EL1" : [rd] "=r" (model));
    if ((CAVIUM_CN88XX_PASS1_X & 0xf0fff0) == (model & 0xf0fff0))
        monitor_ccpi();

    /* All other chips can use the hardware default CCPI init, so put the
       core in reset and wait for the other node to take over */

    /* Disable watchdog */
    if (WATCHDOG_TIMEOUT)
        BDK_CSR_WRITE(bdk_numa_local(), BDK_GTI_CWD_WDOGX(bdk_get_core_num()), 0);
    __bdk_reset_thread(0, NULL);
}

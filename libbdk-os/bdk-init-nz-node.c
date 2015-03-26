#include <bdk.h>

/* The node number may change dynamically while this code is running. This
   variable contains its value after every update in the CCPI monitor loop */
static bdk_node_t node;

/**
* Wait for TX fifo to empty
 */
static void uart_wait_idle()
{
    while (1)
    {
        BDK_CSR_INIT(fr, node, BDK_UAAX_FR(0));
        if (fr.s.txfe)
            break;
    }
}

/**
 * Apply custom tuning to the CCPI QLMs on the slave node
 *
 * @param qlm    QLM to tune
 */
static void qlm_tune(int qlm)
{
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
                c.s.tx_swing_ovrd_en = 1;
                c.s.tx_premptap_ovrd_val = 1);
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
                c.s.tx_swing_ovrd_en = 1;
                c.s.tx_premptap_ovrd_val = 1);
        }
    }
    if (bdk_board_qlm_tune)
        bdk_board_qlm_tune(node, qlm, BDK_QLM_MODE_OCI, baud_mhz);
}

/**
 * Called to monitor CCPI and continually try and get CCPI links up. Once the
 * links are up, the core is put in reset so the master node can take over.
 */
static void monitor_ccpi(void)
{
    uint64_t loop_count = 0;
    uint64_t training_timeout = 0;
    bdk_dbg_uart_str("Monitoring CCPI\r\n");

    /* Don't reset if CCPI links change state */
    BDK_CSR_WRITE(node, BDK_RST_OCX, 0);

    /* Apply CCPI custom tuning */
    for (int qlm = 8; qlm < 14; qlm++)
        qlm_tune(qlm);

    /* Loop forever trying to get CCPI links up */
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

        int ready_lanes = 0;
        int stuck_lanes = 0;

        /* Check status of the 6 CCPI QLMs */
        for (int i = 0; i < 6; i++)
        {
            /* Make sure the lane timer is disabled, no lanes are bad, and all
               lanes are good */
            BDK_CSR_INIT(ocx_qlmx_cfg, node, BDK_OCX_QLMX_CFG(i));
            ready_lanes += bdk_dpop(ocx_qlmx_cfg.s.ser_lane_ready);
            if (!ocx_qlmx_cfg.s.timer_dis || ocx_qlmx_cfg.s.ser_lane_bad ||
                (ocx_qlmx_cfg.s.ser_lane_ready != 0xf))
            {
                ocx_qlmx_cfg.s.timer_dis = 1;
                ocx_qlmx_cfg.s.ser_lane_bad = 0;
                ocx_qlmx_cfg.s.ser_lane_ready = 0xf;
                BDK_CSR_WRITE(node, BDK_OCX_QLMX_CFG(i), ocx_qlmx_cfg.u);
            }
            if (ready_lanes && (training_timeout == 0))
                training_timeout = bdk_clock_get_count(BDK_CLOCK_MAIN_REF) + bdk_clock_get_rate(node, BDK_CLOCK_MAIN_REF);

            /* Wait until some lanes are up before checking if training is
               enabled and done. */
            if ((ready_lanes > 0) && ocx_qlmx_cfg.s.trn_ena)
            {
                /* Make sure no lanes are stuck in training */
                for (int lane = i * 4; lane < (i + 1) * 4; lane++)
                {
                    BDK_CSR_INIT(ocx_lnex_trn_ctl, node, BDK_OCX_LNEX_TRN_CTL(lane));
                    if (!ocx_lnex_trn_ctl.s.done)
                    {
                        bdk_dbg_uart_str("Lane ");
                        bdk_dbg_uart_char('0' + lane / 10);
                        bdk_dbg_uart_char('0' + lane % 10);
                        bdk_dbg_uart_str(" stuck in training\r\n");
                        stuck_lanes++;
                    }
                }
            }
        }

        /* Do a soft reset if lanes are still stuck after the training
           timout expires */
        if (stuck_lanes && (bdk_clock_get_count(BDK_CLOCK_MAIN_REF) > training_timeout))
        {
            bdk_dbg_uart_str("Doing soft reset due to stuck training\n");
            uart_wait_idle();
            bdk_rst_soft_rst_t rst_soft_rst;
            rst_soft_rst.u = 0;
            rst_soft_rst.s.soft_rst = 1;
            BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, rst_soft_rst.u);
            while (1) {}
        }

        /* Don't check links until all lanes are up */
        if (ready_lanes != 24)
            continue;

        int valid_links = 0;
        /* Check that the three CCPI links are operating */
        for (int link = 0; link < 3; link++)
        {
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
                    bdk_dbg_uart_str("Re-init link ");
                    bdk_dbg_uart_char('0' + link);
                    bdk_dbg_uart_str("\r\n");
                }
                else
                    valid_links++;
            }
        }
        if (valid_links >= 2)
        {
            /* Reset if a link change state */
            BDK_CSR_WRITE(node, BDK_RST_OCX, 0x7);
            bdk_dbg_uart_char('0' + valid_links);
            bdk_dbg_uart_str(" CCPI links up. Putting core in reset\r\n");
            extern void __bdk_reset_thread(int arg1, void *arg2);
            __bdk_reset_thread(0, NULL);
        }
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

    /* Temporarily change the master node global to this node so some
       functions will work properly when called */
    extern int __bdk_numa_master_node;
    __bdk_numa_master_node = node;

    /* Setup the uart using only inline C functons */
    BDK_CSR_WRITE(node, BDK_GPIO_BIT_CFGX(0), 1);
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

    /* Spew out the node ID to uart0 as a hint that something is wrong */
    bdk_dbg_uart_str("\r\nNODE");
    bdk_dbg_uart_char('0' + node);
    bdk_dbg_uart_str("\r\n");

    monitor_ccpi();
}

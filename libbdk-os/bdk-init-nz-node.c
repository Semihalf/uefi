#include <bdk.h>

/**
 * This function is called if we boot on a node that is non-zero
 */
void __bdk_init_non_zero_node(void)
{
    /* We're booting from a non-zero node. This currently isn't supported, but
       happens by mistake when chip straps are wrong. We can't call many C
       functions as we're running at an address other than our link address */
    int uart = 0;
    bdk_node_t node = bdk_numa_local();

    /* Setup the uart using only inline C functons */
    BDK_CSR_WRITE(bdk_numa_local(), BDK_GPIO_BIT_CFGX(0), 1);
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
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), '\r');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), '\n');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), 'N');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), 'O');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), 'D');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), 'E');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), '0' + node);
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), '\r');
    BDK_CSR_WRITE(node, BDK_UAAX_DR(uart), '\n');

    /* Spin here aswe can't run normally */
    while (1) {}
}

#include <bdk.h>

/**
 * The routine in this file are called when some unknown bad thing has happened.
 * They bypass the normal output mechanism and push characters directly to the
 * uart. Hopefully this will allow them to work when everything else has died.
 *
 * @param c      Character to print
 */
void bdk_dbg_uart_char(char c)
{
    const int id = 0;
    const bdk_node_t node = bdk_numa_master();

    BDK_CSR_INIT(fr, node, BDK_UAAX_FR(id));
    while (fr.s.txff) /* Spin while full */
        fr.u = BDK_CSR_READ(node, BDK_UAAX_FR(id));
    BDK_CSR_WRITE(node, BDK_UAAX_DR(id), c);
}

/**
 * Write a low level string
 *
 * @param s      String to write
 */
void bdk_dbg_uart_str(const char *s)
{
    while (*s)
    {
        bdk_dbg_uart_char(*s);
        s++;
    }
}

/**
 * Write a low level 64bit number in hex
 *
 * @param value  Value to write
 */
void bdk_dbg_uart_hex(uint64_t value)
{
    bdk_dbg_uart_char('0');
    bdk_dbg_uart_char('x');
    for (int i=15; i>=0; i--)
    {
        char c = (value >> (i*4)) & 0xf;
        if (c >= 10)
            c += 'a' - 10;
        else
            c += '0';
        bdk_dbg_uart_char(c);
    }
}

/**
 * Dump multiple samples of all cores out of reset on the given node
 *
 * @param node   Node to dump core PCs for
 */
void bdk_dbg_dump_pc(bdk_node_t node)
{
    uint64_t pp_reset = BDK_CSR_READ(node, BDK_RST_PP_RESET);
    int num_cores = bdk_get_num_cores(node);
    int my_core = bdk_get_core_num();

    bdk_dbg_uart_str("\r\n\r\n\r\nNode ");
    bdk_dbg_uart_char(node + '0');
    bdk_dbg_uart_str(": Dumping PCs (4 samples):\r\n");

    for (int core=0; core<num_cores; core++)
    {
        if (pp_reset & (1ull << core))
            continue;
        bdk_dbg_uart_str("Core ");
        bdk_dbg_uart_char(core / 10 + '0');
        bdk_dbg_uart_char(core % 10 + '0');
        for (int sample=0; sample < 4; sample++)
        {
            uint64_t pc = bdk_sysreg_read(node, core, BDK_SYS_CVM_DEBUG3_EL3);
            bdk_dbg_uart_char(' ');
            bdk_dbg_uart_hex(pc);
        }
        if ((node == bdk_numa_local()) && (my_core == core))
            bdk_dbg_uart_str(" (doing dump)");
        bdk_dbg_uart_str("\r\n");
    }
    bdk_dbg_uart_str("\r\n");
}

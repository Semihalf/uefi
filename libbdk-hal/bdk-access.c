#include <bdk.h>
#include <stdio.h>

/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
void bdk_wait_usec(uint64_t usec)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + usec * bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 1000000;
    do
    {
        bdk_thread_yield();
    } while (bdk_clock_get_count(BDK_CLOCK_CORE) < done);
}

/**
 * Perform a soft reset of Octeon
 *
 * @return
 */
void bdk_reset_octeon(bdk_node_t node)
{
    fflush(NULL);

    /* Wait for TX fifo to empty */
    while (1)
    {
        BDK_CSR_INIT(fr, node, BDK_UAAX_FR(0));
        if (fr.s.txfe)
            break;
        bdk_thread_yield();
    }

    bdk_rst_soft_rst_t rst_soft_rst;
    rst_soft_rst.u = 0;
    rst_soft_rst.s.soft_rst = 1;
    BDK_CSR_WRITE(node, BDK_RST_SOFT_RST, rst_soft_rst.u);
}


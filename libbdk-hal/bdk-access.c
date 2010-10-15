#include <bdk.h>

/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
void bdk_wait_usec(uint64_t usec)
{
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + usec * bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000;
    while (bdk_clock_get_count(BDK_CLOCK_CORE) < done)
        bdk_thread_yield();
}

/**
 * Perform a soft reset of Octeon
 *
 * @return
 */
void bdk_reset_octeon(void)
{
    bdk_mio_uartx_lsr_t lsrval;
    bdk_ciu_soft_rst_t ciu_soft_rst;

    fflush(NULL);

    while (1)
    {
        lsrval.u64 = BDK_CSR_READ(BDK_MIO_UARTX_LSR(0));
        if (lsrval.s.temt)
            break;
        bdk_thread_yield();
    }

    ciu_soft_rst.u64 = 0;
    ciu_soft_rst.s.soft_rst = 1;
    BDK_CSR_WRITE(BDK_CIU_SOFT_RST, ciu_soft_rst.u64);
}


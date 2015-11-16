#include <bdk.h>

/**
 * Report boot status to the BMC or whomever might care. This function
 * will return quickly except for a status of "power cycle". In the power cycle
 * case it is assumed the board is in a bad state and should not continue until
 * a power cycle restarts us.
 *
 * @param status Status to report. Enumerated in bdk_boot_status_t
 */
void bdk_boot_status(bdk_boot_status_t status)
{
    bdk_node_t node = bdk_numa_master();
    int twsi = bdk_config_get_int(BDK_CONFIG_BMC_TWSI);

    /* Update status */
    if (twsi != -1)
    {
        BDK_CSR_DEFINE(sw_twsi, BDK_MIO_TWSX_SW_TWSI(twsi));
        sw_twsi.u = 0;
        sw_twsi.s.v = 1; /* Valid data */
        sw_twsi.s.slonly = 1; /* Slave only */
        sw_twsi.s.data = status;
        BDK_CSR_WRITE(node, BDK_MIO_TWSX_SW_TWSI(twsi), sw_twsi.u);
    }

    /* As a special case, power cycle will display a message and try a
       soft reset if we can't power cycle in 5 seconds */
    if (status == BDK_BOOT_STATUS_REQUEST_POWER_CYCLE)
    {
        if (twsi != -1)
        {
            printf("Requested power cycle\n");
            bdk_wait_usec(5000000); /* 5 sec */
            printf("Power cycle failed, trying soft reset\n");
        }
        else
            printf("Performing soft reset\n");
        bdk_reset_chip(node);
    }
}


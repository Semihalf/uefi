#include <bdk.h>

/* These variable record the destination of boot status messages. Currently
   the only support destination is a TWSI bus in slave mode */
static bdk_node_t boot_status_node;
static int boot_status_twsi = -1;


/**
 * Called to setup the TWSI bus for reporting status. This is called autoamtically
 * on the first call to bdk_boot_status().
 */
static void init_twsi_slave(void)
{
    boot_status_node = bdk_numa_local();
    boot_status_twsi = bdk_brd_cfg_get_int(-1, BDK_BRD_CFG_BMC_TWSI);

    if (boot_status_twsi == -1)
        return;

    BDK_CSR_DEFINE(sw_twsi, BDK_MIO_TWSX_SW_TWSI(boot_status_twsi));
    sw_twsi.u = 0;
    sw_twsi.s.slonly = 1; /* Slave only */
    BDK_CSR_WRITE(boot_status_node, BDK_MIO_TWSX_SW_TWSI(boot_status_twsi), sw_twsi.u);
}

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
    /* Try TWSI init if we don't have a boot status destination selected */
    if (boot_status_twsi == -1)
        init_twsi_slave();

    /* Update status */
    if (boot_status_twsi != -1)
    {
        BDK_CSR_MODIFY(c, boot_status_node, BDK_MIO_TWSX_SW_TWSI(boot_status_twsi),
            c.s.v = 1;
            c.s.data = status);
    }

    /* As a special case, power cycle will display a message and try a
       soft reset if we can't pwoer cycle in 5 seconds */
    if (status == BDK_BOOT_STATUS_REQUEST_POWER_CYCLE)
    {
        if (boot_status_twsi != -1)
        {
            printf("Requested power cycle\n");
            bdk_wait_usec(5000000); /* 5 sec */
            printf("Power cycle failed, trying soft reset\n");
        }
        else
            printf("Performing soft reset\n");
        bdk_reset_chip(bdk_numa_local());
    }
}


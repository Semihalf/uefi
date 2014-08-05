#include <bdk.h>

extern int global_ddr_clock_initialized;
static volatile int thread_mbyte_result;

/**
 * Given a DRAM configuration, configure the hardware to match.
 * Note that a copy of the configuration is made, so the caller
 * may dispose of the structure after the call.
 *
 * @param board  DRAM configuration
 *
 * @return Amount of DRAM in MB, or negative on failure
 */

static void thread_dram_config_raw(int arg1, void *arg2)
{
    const int ddr_clock_hertz = arg1;
    const ddr_config_table_t *ddr_config_table = arg2;
    const bdk_node_t node = bdk_numa_local();

    BDK_TRACE("N%d: DRAM init thread started (hertz=%d, config=%p)\n", node, ddr_clock_hertz, ddr_config_table);

    const ddr_configuration_t *ddr_config = ddr_config_table->ddr_config;

    BDK_TRACE("N%d: Calling DRAM init\n", node);
    int mbytes = libdram_config(node, ddr_config, ddr_clock_hertz);
    BDK_TRACE("N%d: DRAM init returned %d\n", node, mbytes);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        thread_mbyte_result = -1;
        return;
    }

    /* Clear any DRAM errors set during init */
    BDK_TRACE("N%d: Clearing L2 errors\n", node);
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_WRITE(node, BDK_LMCX_INT(0), BDK_CSR_READ(node, BDK_LMCX_INT(0)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(1), BDK_CSR_READ(node, BDK_LMCX_INT(1)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(2), BDK_CSR_READ(node, BDK_LMCX_INT(2)));
        BDK_CSR_WRITE(node, BDK_LMCX_INT(3), BDK_CSR_READ(node, BDK_LMCX_INT(3)));
    }

    /* Store the amount of memory in the environment */
    char buffer[8];
    snprintf(buffer, sizeof(buffer), "%d", mbytes);
    buffer[sizeof(buffer)-1] = 0;
    setenv("dram_size_mbytes", buffer, 1);

    printf("BDK DRAM: %d MB, %d MHz\n", mbytes, ((ddr_clock_hertz + 500000) /1000000));
    thread_mbyte_result = mbytes;
}

/**
 * Given a DRAM configuration, configure the hardware to match.
 * Note that a copy of the configuration is made, so the caller
 * may dispose of the structure after the call.
 *
 * @param board  DRAM configuration
 *
 * @return Amount of DRAM in MB, or negative on failure
 */

int bdk_dram_config_raw(int node, const ddr_config_table_t *ddr_config_table, int ddr_clock_hertz)
{
    /* Start the DRAM code on the node we need DRAM setup. It needs a bigger
       stack than normal */
    BDK_TRACE("Starting thread for DRAM init\n");
    thread_mbyte_result = 0;
    int status = bdk_thread_create(node, 0, thread_dram_config_raw,
        ddr_clock_hertz, (void*)ddr_config_table, 16384);
    if (status)
    {
        printf("ERROR: Failed to create thread for DRAM init\n");
        return -1;
    }

    BDK_TRACE("Waiting for DRAM init to complete\n");
    /* Wait for DRAM setup to be complete */
    while (thread_mbyte_result == 0)
    {
        bdk_thread_yield();
    }
    BDK_TRACE("DRAM init returned %d\n", thread_mbyte_result);
    return thread_mbyte_result;
}


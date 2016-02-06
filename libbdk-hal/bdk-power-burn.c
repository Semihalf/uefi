#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(POWER_BURN);

static bdk_power_burn_type_t global_burn_type = BDK_POWER_BURN_NONE;

static void power_thread(int unused1, void *unused2)
{
    extern int __bdk_power_burn(void);
    BDK_TRACE(INIT, "N%d.%d: Thread burning power\n", bdk_numa_local(), bdk_get_core_num());
    bdk_wait_usec(100000);
    uint64_t second = bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME);
    while (1)
    {
        bdk_power_burn_type_t burn_type = (volatile bdk_power_burn_type_t)global_burn_type;
        switch (burn_type)
        {
            case BDK_POWER_BURN_NONE:        /* Disable power burn */
                return;
            case BDK_POWER_BURN_FULL:        /* Continuously burn power */
                __bdk_power_burn();
                break;
            case BDK_POWER_BURN_CYCLE_10MS:  /* Cycle: Burn for 10ms, idle for 10ms */
            {
                uint64_t wall = bdk_clock_get_count(BDK_CLOCK_TIME);
                wall /= second / 100;
                if (wall & 1)
                    __bdk_power_burn();
                break;
            }
            case BDK_POWER_BURN_CYCLE_1S:    /* Cycle: Burn for 1s, idle for 1s */
            {
                uint64_t wall = bdk_clock_get_count(BDK_CLOCK_TIME);
                wall /= second;
                if (wall & 1)
                    __bdk_power_burn();
                break;
            }
            case BDK_POWER_BURN_CYCLE_5S:    /* Cycle: Burn for 5s, idle for 5s */
            {
                uint64_t wall = bdk_clock_get_count(BDK_CLOCK_TIME);
                wall /= second * 5;
                if (wall & 1)
                    __bdk_power_burn();
                break;
            }
        }
        bdk_thread_yield();
    }
}

/**
 * Set the current power burn mode for a node
 *
 * @param node      Node to control power burn for
 * @param burn_type Mode of power burn
 *
 * @return Zero on success, negative on failure
 */
int bdk_power_burn(bdk_node_t node, bdk_power_burn_type_t burn_type)
{
    if (burn_type == BDK_POWER_BURN_NONE)
    {
        global_burn_type = burn_type;
        BDK_MB;
        return 0;
    }

    int need_cores = (global_burn_type == BDK_POWER_BURN_NONE);
    global_burn_type = burn_type;
    BDK_MB;
    if (!need_cores)
        return 0;

    if (bdk_init_cores(node, 0))
    {
        global_burn_type = BDK_POWER_BURN_NONE;
        BDK_MB;
        bdk_error("Not starting power burn as node's cores didn't start\n");
        return -1;
    }

    printf("Starting power burn threads\n");

    const int num_cores = bdk_get_num_cores(node);
    for (int core = 0; core < num_cores; core++)
    {
        if (bdk_thread_create(node, 1ull << core, power_thread, 0, NULL, 16384))
            bdk_error("Failed to create thread %d for power burn on node %d\n", core, node);
    }
    return 0;
}

/**
 * Set the core throttle level for all running cores
 *
 * @param node     Node to set
 * @param throttle Throttle level, raw register value
 */
void bdk_power_throttle(bdk_node_t node, int throttle)
{
    const int num_cores = bdk_get_num_cores(node);
    uint64_t running = bdk_get_running_coremask(node);
    for (int core = 0; core < num_cores; core++)
    {
        if (running & (1ull << core))
        {
            BDK_CSR_DEFINE(power, BDK_AP_CVM_POWER_EL1);
            power.u = bdk_sysreg_read(node, core, BDK_AP_CVM_POWER_EL1);
            power.s.max_setting = throttle;
            power.s.override = 1;
            bdk_sysreg_write(node, core, BDK_AP_CVM_POWER_EL1, power.u);
        }
    }
}


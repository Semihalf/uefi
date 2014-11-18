#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(POWER_BURN);

static void power_thread(int unused1, void *unused2)
{
    extern int __bdk_power_burn_dp(void);
    BDK_TRACE(INIT, "N%d.%d: Thread burning power\n", bdk_numa_local(), bdk_get_core_num());
    bdk_wait_usec(100000);
    while (1)
    {
        __bdk_power_burn_dp();
        bdk_thread_yield();
    }
}

int bdk_power_burn(bdk_node_t node)
{
    const int num_cores = bdk_get_num_cores(node);
    bdk_init_cores(node, 0);
    printf("Starting power burn threads\n");
    for (int core = 0; core < num_cores; core++)
    {
        if (bdk_thread_create(node, 1 << core, power_thread, 0, NULL, 0))
            bdk_error("Failed to create thread %d for power burn on node %d\n", core, node);
    }
    return 0;
}

void bdk_power_throttle(bdk_node_t node, int throttle)
{
    const int num_cores = bdk_get_num_cores(node);
    uint64_t running = bdk_get_running_coremask(node);
    for (int core = 0; core < num_cores; core++)
    {
        if (running & (1ull << core))
        {
            bdk_sys_cvm_power_el1_t power;
            power.u = bdk_sysreg_read(node, core, BDK_SYS_CVM_POWER_EL1);
            power.s.max_setting = throttle;
            power.s.secret_override = 1;
            bdk_sysreg_write(node, core, BDK_SYS_CVM_POWER_EL1, power.u);
        }
    }
}


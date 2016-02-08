typedef enum
{
    BDK_POWER_BURN_NONE,        /* Disable power burn */
    BDK_POWER_BURN_FULL,        /* Continuously burn power */
    BDK_POWER_BURN_CYCLE_10MS,  /* Cycle: Burn for 10ms, idle for 10ms */
    BDK_POWER_BURN_CYCLE_1S,    /* Cycle: Burn for 1s, idle for 1s */
    BDK_POWER_BURN_CYCLE_5S,    /* Cycle: Burn for 5s, idle for 5s */
    BDK_POWER_BURN_CYCLE_1M,    /* Cycle: Burn for 1m, idle for 1m */
    BDK_POWER_BURN_CYCLE_5M,    /* Cycle: Burn for 5m, idle for 5m */
} bdk_power_burn_type_t;

/**
 * Set the current power burn mode for a node
 *
 * @param node      Node to control power burn for
 * @param burn_type Mode of power burn
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_power_burn(bdk_node_t node, bdk_power_burn_type_t burn_type);

/**
 * Set the core throttle level for all running cores
 *
 * @param node     Node to set
 * @param throttle Throttle level, raw register value
 */
extern void bdk_power_throttle(bdk_node_t node, int throttle);


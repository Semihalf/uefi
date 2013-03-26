/**
 * @file
 *
 * Functions for dealing with multiple Octeon chips organized
 * into a NUMA cluster.
 *
 * <hr>$Revision: 49448 $<hr>
 */

#define BDK_NUMA_MAX_NODES 4
typedef enum
{
    BDK_NODE_MASTER = -2,
    BDK_NODE_LOCAL = -1,
    BDK_NODE_0 = 0,
    BDK_NODE_1 = 1,
    BDK_NODE_2 = 2,
    BDK_NODE_3 = 3,
} bdk_node_t;

/**
 * Get the hardware ID related to a node
 *
 * @param node   Node number of virtual enum
 *
 * @return Node ID
 */
static inline int bdk_numa_id(bdk_node_t node)
{
    switch (node)
    {
        case BDK_NODE_MASTER:
        {
            extern int __bdk_numa_master_node;
            return __bdk_numa_master_node;
        }
        case BDK_NODE_LOCAL:
        {
#ifndef BDK_BUILD_HOST
            int core_num;
            BDK_RDHWRNV(core_num, 0);
            return BDK_NODE_0 + (core_num >> 7);
#else
            return BDK_NODE_0; /* FIXME: choose remote node */
#endif
        }
        default:
            return node;
    }
}

/**
 * Get a bitmask of the nodes that exist
 *
 * @return bitmask
 */
static inline uint64_t bdk_numa_get_exists_mask(void)
{
    extern int __bdk_numa_exists_mask;
    return __bdk_numa_exists_mask;
}

/**
 * Get a bitmask of the running nodes
 *
 * @return bitmask
 */
static inline uint64_t bdk_numa_get_running_mask(void)
{
    extern int __bdk_numa_running_mask;
    return __bdk_numa_running_mask;
}

/**
 * Add a node to the exists mask
 *
 * @param node   Node to add
 */
extern void bdk_numa_set_exists(bdk_node_t node);

/**
 * Add a node to the running mask
 *
 * @param node   Node to add
 */
extern void bdk_numa_set_running(bdk_node_t node);




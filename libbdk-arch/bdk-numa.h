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
    BDK_NODE_0 = 0,
    BDK_NODE_1 = 1,
    BDK_NODE_2 = 2,
    BDK_NODE_3 = 3,
} bdk_node_t;

/**
 * Return the local node number
 *
 * @return Node number
 */
static inline bdk_node_t bdk_numa_local(void)
{
#ifndef BDK_BUILD_HOST
    int mpidr_el1;
    BDK_MRS(MPIDR_EL1, mpidr_el1);
    return BDK_NODE_0 + ((mpidr_el1 >> 16) & 0xff);
#else
    return BDK_NODE_0; /* FIXME: choose remote node */
#endif
}

/**
 * Return the master node number
 *
 * @return Node number
 */
static inline bdk_node_t bdk_numa_master(void)
{
    extern int __bdk_numa_master_node;
    return __bdk_numa_master_node;
}

/**
 * Get a bitmask of the nodes that exist
 *
 * @return bitmask
 */
extern uint64_t bdk_numa_get_exists_mask(void);

/**
 * Get a bitmask of the running nodes
 *
 * @return bitmask
 */
extern uint64_t bdk_numa_get_running_mask(void);

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

/**
 * Return true if a node exists
 *
 * @param node   Node to check
 *
 * @return Non zero if the node exists
 */
extern int bdk_numa_exists(bdk_node_t node);

/**
 * Return true if there is only one node
 *
 * @return
 */
extern int bdk_numa_is_only_one();

/**
 * Given a physical address without a node, return the proper physical address
 * for the given node.
 *
 * @param node   Node to create address for
 * @param pa     Base physical address
 *
 * @return Node specific address
 */
static inline uint64_t bdk_numa_get_address(bdk_node_t node, uint64_t pa)
{
    if (pa & (1ull << 48))
        return pa | ((uint64_t)node << 36);
    else
        return pa | ((uint64_t)node << 40);
}



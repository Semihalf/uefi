/**
 * @file
 *
 * Functions for dealing with multiple chips organized into a
 * NUMA cluster.
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef enum
{
    BDK_NODE_0 = 0,
    BDK_NODE_1 = 1,
    BDK_NODE_2 = 2,
    BDK_NODE_3 = 3,
    BDK_NUMA_MAX_NODES = 4
} bdk_node_t;

/**
 * Return the local node number
 *
 * @return Node number
 */
static inline bdk_node_t bdk_numa_local(void) __attribute__ ((always_inline, pure));
static inline bdk_node_t bdk_numa_local(void)
{
#ifndef BDK_BUILD_HOST
    int mpidr_el1;
    BDK_MRS_NV(MPIDR_EL1, mpidr_el1);
    int result;
    BDK_EXTRACT(result, mpidr_el1, 16, 8);
    return BDK_NODE_0 + result;
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
 * Add a node to the exists mask
 *
 * @param node   Node to add
 */
extern void bdk_numa_set_exists(bdk_node_t node);

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
#ifndef BDK_BUILD_HOST
    if (pa & (1ull << 47))
    {
        BDK_INSERT(pa, node, 44, 2);
    }
    else
    {
        BDK_INSERT(pa, node, 40, 2);
    }
#else
    if (pa & (1ull << 47))
        pa |= (uint64_t)node << 44;
    else
        pa |= (uint64_t)node << 40;
#endif
    return pa;
}



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

static inline int bdk_numa_id(bdk_node_t node)
{
    switch (node)
    {
        case BDK_NODE_MASTER:
            return BDK_NODE_0; /* FIXME: choose numa master */
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

static inline uint64_t bdk_numa_get_running_mask(void)
{
    return 0x1; /* FIXME: Detect numa nodes */
}

static inline uint64_t bdk_numa_get_exists_mask(void)
{
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        return 0xf; /* FIXME: Detect numa nodes */
    else
        return 0x1;
}






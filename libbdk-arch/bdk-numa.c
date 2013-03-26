#include <bdk.h>
#include <stdio.h>

int __bdk_numa_master_node = -1;    /* Which node is the master */
int __bdk_numa_exists_mask = 0xf;   /* Bitmask of nodes that exist */
int __bdk_numa_running_mask = 0;    /* Bitmask of nodes that are running */
static bdk_spinlock_t __bdk_numa_lock;

/**
 * Add a node to the exists mask
 *
 * @param node   Node to add
 */
void bdk_numa_set_exists(bdk_node_t node)
{
    node = bdk_numa_id(node);

    bdk_spinlock_lock(&__bdk_numa_lock);
    __bdk_numa_exists_mask |= 1 << node;
    /* FIXME: node detection */
    if (OCTEON_IS_MODEL(OCTEON_CN78XX))
        __bdk_numa_exists_mask |= 0xf;
    bdk_spinlock_unlock(&__bdk_numa_lock);
}

/**
 * Add a node to the running mask
 *
 * @param node   Node to add
 */
void bdk_numa_set_running(bdk_node_t node)
{
    node = bdk_numa_id(node);

    bdk_spinlock_lock(&__bdk_numa_lock);
    __bdk_numa_running_mask |= 1 << node;
    if (__bdk_numa_master_node == -1)
        __bdk_numa_master_node = node;
    bdk_spinlock_unlock(&__bdk_numa_lock);
}




#include <bdk.h>
#include "dram-internal.h"

int limit_l2_ways(bdk_node_t node, int ways, int verbose)
{
    uint32_t valid_mask = (0x1 << bdk_l2c_get_num_assoc(node)) - 1;
    int ways_max = bdk_l2c_get_num_assoc(node);
    int ways_min;
    uint32_t mask = (valid_mask << ways) & valid_mask;
    int errors = 0;

    ways_min = 0;

    if (ways >= ways_min && ways <= ways_max)
    {
        int i;
        if (verbose)
            printf("Limiting L2 to %d ways\n", ways);
        for (i = 0; i < (int)bdk_get_num_cores(node); i++)
            errors += bdk_l2c_set_core_way_partition(node, i, mask);
        errors += bdk_l2c_set_hw_way_partition(node, mask);
    }
    else
    {
        errors++;
        printf("ERROR: invalid limit_l2_ways %d, must be between %d and %d\n",
            ways, ways_min, ways_max);
    }
    if (errors)
        puts("ERROR limiting L2 cache ways\n");

    return errors;
}


/**
 * Function for DDR3 init. Internal use only.
 */

extern void perform_octeon3_ddr3_sequence(bdk_node_t node, int rank_mask,
    int ddr_interface_num, int sequence);
extern void perform_ddr3_init_sequence(bdk_node_t node, int rank_mask,
    int ddr_interface_num);

extern int init_octeon3_ddr3_interface(bdk_node_t node,
    const ddr_configuration_t *ddr_configuration, uint32_t ddr_hertz,
    uint32_t cpu_hertz, uint32_t ddr_ref_hertz, int board_type,
    int board_rev_maj, int board_rev_min, int ddr_interface_num,
    uint32_t ddr_interface_mask);


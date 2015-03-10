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

typedef struct {
    unsigned char *rodt_ohms;
    unsigned char *rtt_nom_ohms;
    unsigned char *rtt_nom_table;
    unsigned char *rtt_wr_ohms;
    unsigned char *dic_ohms;
    short         *drive_strength;
    short         *dqx_strength;
} impedence_values_t;

#define RODT_OHMS_COUNT        8
#define RTT_NOM_OHMS_COUNT     8
#define RTT_NOM_TABLE_COUNT    8
#define RTT_WR_OHMS_COUNT      8
#define DIC_OHMS_COUNT         3
#define DRIVE_STRENGTH_COUNT  15

typedef enum {
    DDR3_DRAM = 3,
    DDR4_DRAM = 4,
} ddr_type_t;


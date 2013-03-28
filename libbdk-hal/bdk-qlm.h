
/**
 * @file
 *
 * Function and structure definitions for QLM manipulation
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_QLM_MODE_DISABLED,  /* QLM is disabled */
    BDK_QLM_MODE_PCIE_1X1,  /* 1 PCIe, 1 lane */
    BDK_QLM_MODE_PCIE_2X1,  /* 2 PCIe, 1 lane each */
    BDK_QLM_MODE_PCIE_1X2,  /* 1 PCIe, 2 lanes */
    BDK_QLM_MODE_PCIE_1X4,  /* 1 PCIe, 4 lanes */
    BDK_QLM_MODE_PCIE_1X8,  /* 1 PCIe, 8 lanes */
    BDK_QLM_MODE_ILK,       /* ILK 4 lanes */
    BDK_QLM_MODE_SGMII,     /* 4 SGMII, each lane independent */
    BDK_QLM_MODE_QSGMII,    /* 4 SGMII, muliplex over one lane */
    BDK_QLM_MODE_XAUI_1x4,  /* 1 XAUI, 4 lanes */
    BDK_QLM_MODE_XAUI_4x1,  /* 4 XAUI, 1 lane each */
    BDK_QLM_MODE_RXAUI_2X2, /* 2 RXAUI, 2 lanes each */
    BDK_QLM_MODE_RXAUI_1x2, /* 1 RXAUI, 2 lanes */
    BDK_QLM_MODE_SATA_2X2,  /* 2 SATA, one lane each */
    BDK_QLM_MODE_PCIE_1X1_SATA, /* 1 lane PCIe, 1 lane SATA */
    BDK_QLM_MODE_SATA_PCIE_1X1, /* 1 lane SATA, 1 lane PCIe */
    BDK_QLM_MODE_OCI,       /* OCI Multichip interconnect */
} bkd_qlm_modes_t;

typedef enum
{
    BDK_QLM_LOOP_DISABLED,
    BDK_QLM_LOOP_0_3,
    BDK_QLM_LOOP_1_2,
    BDK_QLM_LOOP_ALL,
} bdk_qlm_loop_t;

/**
 * How to do the various QLM operations changes greatly
 * between chips. Each chip has its specific operations
 * stored in the structure below. The correct structure
 * is choosen based on the chip we're running on.
 */
typedef struct
{
    uint32_t chip_model;
    void (*init)(bdk_node_t node);
    int (*get_num)(bdk_node_t node);
    int (*get_lanes)(bdk_node_t node, int qlm);
    bkd_qlm_modes_t (*get_supported_modes)(bdk_node_t node, int qlm, bkd_qlm_modes_t last);
    bkd_qlm_modes_t (*get_mode)(bdk_node_t node, int qlm);
    int (*set_mode)(bdk_node_t node, int qlm, bkd_qlm_modes_t mode, int baud_mhz);
    int (*get_gbaud_mhz)(bdk_node_t node, int qlm);
    int (*measure_refclock)(bdk_node_t node, int qlm);
    int (*get_qlm_num)(bdk_node_t node, bdk_if_t iftype, int interface);
    int (*enable_prbs)(bdk_node_t node, int qlm, int prbs);
    int (*enable_loop)(bdk_node_t node, int qlm, bdk_qlm_loop_t loop);
} bdk_qlm_ops_t;

/**
 * Initialize the QLM layer
 */
extern void bdk_qlm_init(bdk_node_t node);

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
extern int bdk_qlm_get_num(bdk_node_t node);

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
extern int bdk_qlm_get_lanes(bdk_node_t node, int qlm);

/**
 * Iterate through the supported modes of a QLM. On first call specify
 * disabled as the last value. It will then return supported modes,
 * ending the list with disabled.
 *
 * @param node   Node to use in a Numa setup
 * @param qlm    QLM to examine
 * @param last   Previous value returned, or disabled to start list
 *
 * @return Next supported QLM mode
 */
extern bkd_qlm_modes_t bdk_qlm_get_supported_modes(bdk_node_t node, int qlm, bkd_qlm_modes_t last);

/**
 * Convert a mode into a human understandable string
 *
 * @param mode   Mode to convert
 *
 * @return Easy to read string
 */
extern const char *bdk_qlm_mode_tostring(bkd_qlm_modes_t mode);

/**
 * Get the mode of a QLM as a human readable string
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
extern bkd_qlm_modes_t bdk_qlm_get_mode(bdk_node_t node, int qlm);

/**
 * For chips that don't use pin strapping, this function programs
 * the QLM to the specified mode
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param mode     Desired mode
 * @param baud_mhz Desired speed
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_set_mode(bdk_node_t node, int qlm, bkd_qlm_modes_t mode, int baud_mhz);

/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
extern int bdk_qlm_get_gbaud_mhz(bdk_node_t node, int qlm);

/**
 * Measure the reference clock of a QLM
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
extern int bdk_qlm_measure_clock(bdk_node_t node, int qlm);

/**
 * Lookup the hardware QLM number for a given interface type and
 * index. If the associated interface doesn't map to a QLM,
 * returns -1.
 *
 * @param node      Node to use in a Numa setup
 * @param iftype    Interface type
 * @param interface Interface index number
 *
 * @return QLM number or -1 on failure
 */
extern int bdk_qlm_get(bdk_node_t node, bdk_if_t iftype, int interface);

/**
 * Enable PRBS on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param prbs   PRBS mode (31, etc)
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_enable_prbs(bdk_node_t node, int qlm, int prbs);

/**
 * Enable shallow loopback on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param loop   Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop);

/** @} */


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
    BDK_QLM_MODE_DISABLED,  /* QLM is disabled (all chips) */
    BDK_QLM_MODE_PCIE_1X1,  /* 1 PCIe, 1 lane. Other lanes unused */
    BDK_QLM_MODE_PCIE_2X1,  /* 2 PCIe, 1 lane each */
    BDK_QLM_MODE_PCIE_1X2,  /* 1 PCIe, 2 lanes */
    BDK_QLM_MODE_PCIE_1X4,  /* 1 PCIe, 4 lanes */
    BDK_QLM_MODE_PCIE_1X8,  /* 1 PCIe, 8 lanes */

    BDK_QLM_MODE_SGMII_SGMII, /* Two SGMII (cn70xx) */
    BDK_QLM_MODE_SGMII_QSGMII, /* SGMII, QSGMII (cn70xx) */
    BDK_QLM_MODE_SGMII_DISABLED, /* SGMII, Disabled (cn70xx) */
    BDK_QLM_MODE_QSGMII_SGMII, /* QSGMII, SGMII (cn70xx) */
    BDK_QLM_MODE_QSGMII_QSGMII, /* Two QSGMII (cn70xx) */
    BDK_QLM_MODE_QSGMII_DISABLED, /* QSGMII, Disabled (cn70xx) */
    BDK_QLM_MODE_DISABLED_SGMII, /* Disabled, SGMII (cn70xx) */
    BDK_QLM_MODE_DISABLED_QSGMII, /* Disabled, QSGMII (cn70xx) */
    BDK_QLM_MODE_RXAUI_1X2, /* 1 RXAUI, 2 lanes (cn70xx) */
    BDK_QLM_MODE_SATA_2X1,  /* 2 SATA, one lane each (cn70xx) */

    BDK_QLM_MODE_ILK,       /* ILK 4 lanes (cn78xx) */
    BDK_QLM_MODE_SGMII,     /* SGMII, each lane independent (cn78xx) */
    BDK_QLM_MODE_XAUI_1X4,  /* 1 XAUI, 4 lanes (cn78xx) */
    BDK_QLM_MODE_RXAUI_2X2, /* 2 RXAUI, 2 lanes each (cn78xx) */
    BDK_QLM_MODE_OCI,       /* OCI Multichip interconnect (cn78xx) */
    BDK_QLM_MODE_10GR_4X1,  /* 4 10GBASE-R, 1 lane each (cn78xx) */
    BDK_QLM_MODE_40GR4_1X4,  /* 1 40GBASE-R4, 4 lanes each (cn78xx) */
} bdk_qlm_modes_t;

typedef enum
{
    BDK_QLM_MODE_FLAG_ENDPOINT = 1, /* PCIe in EP instead of RC */
    BDK_QLM_MODE_FLAG_GEN1 = 2,     /* Limit PCIe to gen1 speeds */
    BDK_QLM_MODE_FLAG_GEN2 = 4,     /* Limit PCIe to gen2 speeds */
    BDK_QLM_MODE_FLAG_GEN3 = 8,     /* Limit PCIe to gen3 speeds */
} bdk_qlm_mode_flags_t;

typedef enum
{
    BDK_QLM_LOOP_DISABLED,  /* No shallow loopback */
    BDK_QLM_LOOP_0_3,       /* Loopback lane 0 and 3 */
    BDK_QLM_LOOP_1_2,       /* Loopback lane 1 and 2 */
    BDK_QLM_LOOP_ALL,       /* Loopback all lanes */
} bdk_qlm_loop_t;

typedef enum
{
    BDK_QLM_DIRECTION_TX = 1,
    BDK_QLM_DIRECTION_RX = 2,
    BDK_QLM_DIRECTION_BOTH = 3,
} bdk_qlm_direction_t;

/**
 * How to do the various QLM operations changes greatly
 * between chips. Each chip has its specific operations
 * stored in the structure below. The correct structure
 * is chosen based on the chip we're running on.
 */
typedef struct
{
    uint32_t chip_model;
    void (*init)(bdk_node_t node);
    int (*get_num)(bdk_node_t node);
    int (*get_lanes)(bdk_node_t node, int qlm);
    bdk_qlm_modes_t (*get_mode)(bdk_node_t node, int qlm);
    int (*set_mode)(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags);
    int (*get_gbaud_mhz)(bdk_node_t node, int qlm);
    int (*measure_refclock)(bdk_node_t node, int qlm);
    int (*get_qlm_num)(bdk_node_t node, bdk_if_t iftype, int interface);
    int (*reset)(bdk_node_t node, int qlm);
    int (*enable_prbs)(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir);
    uint64_t (*get_prbs_errors)(bdk_node_t node, int qlm, int lane);
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
 * Convert a mode into a human understandable string
 *
 * @param mode   Mode to convert
 *
 * @return Easy to read string
 */
extern const char *bdk_qlm_mode_tostring(bdk_qlm_modes_t mode);

/**
 * Get the mode of a QLM as a human readable string
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
extern bdk_qlm_modes_t bdk_qlm_get_mode(bdk_node_t node, int qlm);

/**
 * For chips that don't use pin strapping, this function programs
 * the QLM to the specified mode
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param mode     Desired mode
 * @param baud_mhz Desired speed
 * @param flags    Flags to specify mode specific options
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_set_mode(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags);

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
 * Reset a QLM to its initial state
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_reset(bdk_node_t node, int qlm);

/**
 * Enable PRBS on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param prbs   PRBS mode (31, etc)
 * @param dir    Directions to enable. This is so you can enable TX and later
 *               enable RX after TX has run for a time
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir);

/**
 * Return the number of PRBS errors since PRBS started running
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 *
 * @return Number of errors
 */
extern uint64_t bdk_qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane);

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

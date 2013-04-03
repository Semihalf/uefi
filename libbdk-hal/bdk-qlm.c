#include <bdk.h>
#include <stdio.h>

/* Each chip has its own QLM operation table */
extern const bdk_qlm_ops_t bdk_qlm_ops_cn61xx;
extern const bdk_qlm_ops_t bdk_qlm_ops_cn68xx;
extern const bdk_qlm_ops_t bdk_qlm_ops_cn70xx;
extern const bdk_qlm_ops_t bdk_qlm_ops_cn78xx;

static const bdk_qlm_ops_t *qlm_ops_list[] = {
    &bdk_qlm_ops_cn61xx,
    &bdk_qlm_ops_cn68xx,
    &bdk_qlm_ops_cn70xx,
    &bdk_qlm_ops_cn78xx,
    NULL
};
static const bdk_qlm_ops_t *qlm_ops;

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
int bdk_qlm_get_num(bdk_node_t node)
{
    return qlm_ops->get_num(node);
}

/**
 * Lookup the hardware QLM number for a given interface type and index. This
 * function will fail with a fatal error if called on invalid interfaces for
 * a chip. It returns the QLM number for an interface without checking to
 * see if the QLM is in hte correct mode.
 *
 * @param iftype    Interface type
 * @param interface Interface index number
 *
 * @return QLM number. Dies on a fatal error on failure.
 */
int bdk_qlm_get(bdk_node_t node, bdk_if_t iftype, int interface)
{
    return qlm_ops->get_qlm_num(node, iftype, interface);
}

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
int bdk_qlm_get_lanes(bdk_node_t node, int qlm)
{
    return qlm_ops->get_lanes(node, qlm);
}


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
bdk_qlm_modes_t bdk_qlm_get_supported_modes(bdk_node_t node, int qlm, bdk_qlm_modes_t last)
{
    return qlm_ops->get_supported_modes(node, qlm, last);
}

/**
 * Convert a mode into a human understandable string
 *
 * @param mode   Mode to convert
 *
 * @return Easy to read string
 */
const char *bdk_qlm_mode_tostring(bdk_qlm_modes_t mode)
{
    const char *result = "Unknown, update bdk_qlm_mode_tostring()";
    switch (mode)
    {
        case BDK_QLM_MODE_DISABLED:
            result = "Disabled";
            break;
        case BDK_QLM_MODE_PCIE_1X1:
            result = "1 PCIe, 1 lane";
            break;
        case BDK_QLM_MODE_PCIE_2X1:
            result = "2 PCIe, 1 lane each";
            break;
        case BDK_QLM_MODE_PCIE_1X2:
            result = "1 PCIe, 2 lanes";
            break;
        case BDK_QLM_MODE_PCIE_1X4:
            result = "1 PCIe, 4 lanes";
            break;
        case BDK_QLM_MODE_PCIE_1X8:
            result = "1 PCIe, 8 lanes";
            break;
        case BDK_QLM_MODE_ILK:
            result = "Interlaken";
            break;
        case BDK_QLM_MODE_SGMII:
            result = "SGMII, each lane independent";
            break;
        case BDK_QLM_MODE_QSGMII:
            result = "Quad SGMII, four SGMII muliplex over each lane";
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            result = "1 XAUI, 4 lanes";
            break;
        case BDK_QLM_MODE_XAUI_4X1:
            result = "4 XAUI, 1 lane each";
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            result = "2 RXAUI, 2 lanes each";
            break;
        case BDK_QLM_MODE_RXAUI_1X2:
            result = "1 RXAUI, 2 lanes";
            break;
        case BDK_QLM_MODE_SATA_2X2:
            result = "2 SATA, one lane each";
            break;
        case BDK_QLM_MODE_PCIE_1X1_SATA:
            result = "1 lane PCIe, 1 lane SATA";
            break;
        case BDK_QLM_MODE_SATA_PCIE_1X1:
            result = "1 lane SATA, 1 lane PCIe";
            break;
        case BDK_QLM_MODE_OCI:
            result = "Octeon Coherent Interconnect";
            break;
    }
    return result;
}

/**
 * Get the mode of a QLM as a human readable string
 *
 * @param node   Node to use in a Numa setup. Can be an exact ID or a special
 *               value.
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
bdk_qlm_modes_t bdk_qlm_get_mode(bdk_node_t node, int qlm)
{
    return qlm_ops->get_mode(node, qlm);
}

/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
int bdk_qlm_get_gbaud_mhz(bdk_node_t node, int qlm)
{
    return qlm_ops->get_gbaud_mhz(node, qlm);
}

/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
int bdk_qlm_measure_clock(bdk_node_t node, int qlm)
{
    /* Force the reference to 156.25Mhz when running in simulation.
        This supports the most speeds */
    if (bdk_is_simulation())
        return 156250000;
    return qlm_ops->measure_refclock(node, qlm);
}


/**
 * Reset a QLM to its initial state
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_reset(bdk_node_t node, int qlm)
{
    return qlm_ops->reset(node, qlm);
}


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
int bdk_qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir)
{
    return qlm_ops->enable_prbs(node, qlm, prbs, dir);
}


/**
 * Enable shallow loopback on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param loop   Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop)
{
    return qlm_ops->enable_loop(node, qlm, loop);
}


/**
 * Initialize the QLM layer
 */
void bdk_qlm_init(bdk_node_t node)
{
    /* Find the QLM operations for this chip */
    qlm_ops = NULL;
    int i = 0;
    while (qlm_ops_list[i])
    {
        if (OCTEON_IS_MODEL(qlm_ops_list[i]->chip_model))
        {
            qlm_ops = qlm_ops_list[i];
            break;
        }
        i++;
    }

    if (!qlm_ops)
        bdk_fatal("bdk_qlm_init: OPs table not found for this chip\n");

    /* Skip QLM setup in simulation */
    if (!bdk_is_simulation())
        qlm_ops->init(node);
}


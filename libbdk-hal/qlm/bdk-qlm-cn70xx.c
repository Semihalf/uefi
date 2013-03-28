#include <bdk.h>

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
static int qlm_get_num(bdk_node_t node)
{
    return 3; /* Three DLMs */
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
static int qlm_get_qlm_num(bdk_node_t node, bdk_if_t iftype, int interface)
{
    switch (iftype)
    {
        case BDK_IF_SGMII: /* Looking for SGMII or QSGMII */
        {
            if (interface >= 2)
                return -1;
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(interface));
            switch (inf_mode.s.mode)
            {
                case 0: return 0; /* SGMII */
                case 2: return 0; /* QSGMII */
                default: return -1;
            }
        }
        case BDK_IF_XAUI: /* Looking for RXAUI */
        {
            if (interface >= 1)
                return -1;
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(0));
            switch (inf_mode.s.mode)
            {
                case 1: return 0; /* RXAUI */
                default: return -1;
            }
        }
        case BDK_IF_DPI: /* Used for PCIe detection */
        {
            bdk_qlm_modes_t qlm_mode = bdk_qlm_get_mode(bdk_numa_local(), 1);
            switch (interface)
            {
                case 0: /* PCIe0 can be DLM1, 1, 2, or 4 lanes */
                    if ((qlm_mode == BDK_QLM_MODE_PCIE_1X2) ||
                        (qlm_mode == BDK_QLM_MODE_PCIE_2X1) ||
                        (qlm_mode == BDK_QLM_MODE_PCIE_1X4))
                        return 1;
                    else
                        return -1;
                case 1: /* PCIe1 can be DLM1, 1 lane */
                    if (qlm_mode == BDK_QLM_MODE_PCIE_2X1)
                        return 1;
                    else
                        return -1;
                case 2: /* PCIe2 can be DLM2, 2 lanes */
                    if (qlm_mode == BDK_QLM_MODE_PCIE_1X4)
                        return -1;
                    else if (bdk_qlm_get_mode(bdk_numa_local(), 2) == BDK_QLM_MODE_PCIE_1X2)
                        return 2;
                    else
                        return -1;
                default: /* Only three PEM blocks */
                    return -1;
            }
        }
        default:
            return -1;
    }
}

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
static int qlm_get_lanes(bdk_node_t node, int qlm)
{
    return 2; /* Each DLM has two lanes */
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
static bdk_qlm_modes_t qlm_get_supported_modes(bdk_node_t node, int qlm, bdk_qlm_modes_t last)
{
    switch (qlm)
    {
        case 0:
            switch (last)
            {
                case BDK_QLM_MODE_DISABLED: return BDK_QLM_MODE_SGMII;
                case BDK_QLM_MODE_SGMII:    return BDK_QLM_MODE_QSGMII;
                case BDK_QLM_MODE_QSGMII:   return BDK_QLM_MODE_RXAUI_1X2;
                default:                    return BDK_QLM_MODE_DISABLED;
            }
        case 1:
            switch (last)
            {
                case BDK_QLM_MODE_DISABLED: return BDK_QLM_MODE_PCIE_1X2;
                case BDK_QLM_MODE_PCIE_1X2: return BDK_QLM_MODE_PCIE_2X1;
                case BDK_QLM_MODE_PCIE_2X1: return BDK_QLM_MODE_PCIE_1X4;
                default:                    return BDK_QLM_MODE_DISABLED;
            }
        case 2:
            switch (last)
            {
                case BDK_QLM_MODE_DISABLED: return BDK_QLM_MODE_PCIE_1X4;
                case BDK_QLM_MODE_PCIE_1X4: return BDK_QLM_MODE_PCIE_1X2;
                case BDK_QLM_MODE_PCIE_1X2: return BDK_QLM_MODE_SATA_2X2;
                case BDK_QLM_MODE_SATA_2X2: return BDK_QLM_MODE_PCIE_1X1_SATA;
                case BDK_QLM_MODE_PCIE_1X1_SATA: return BDK_QLM_MODE_SATA_PCIE_1X1;
                default:                    return BDK_QLM_MODE_DISABLED;
            }
        default:
            return BDK_QLM_MODE_DISABLED;
    }
}


/**
 * Get the mode of a QLM as a human readable string
 *
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
static bdk_qlm_modes_t qlm_get_mode(bdk_node_t node, int qlm)
{
    switch (qlm)
    {
        case 0:
        {
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(0));
            switch (inf_mode.s.mode)
            {
                case 0: return BDK_QLM_MODE_SGMII;
                case 1: return BDK_QLM_MODE_RXAUI_1X2;
                case 2: return BDK_QLM_MODE_QSGMII;
                default: return BDK_QLM_MODE_DISABLED;
            }
        }
        case 1:
            return BDK_QLM_MODE_DISABLED; /* FIXME: DLM1 mode */
        case 2:
            return BDK_QLM_MODE_DISABLED; /* FIXME: DLM2 mode */
        default:
            return BDK_QLM_MODE_DISABLED;
    }
}


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
static int qlm_set_mode(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz)
{
    /* FIXME: Set mode */
    bdk_error("CN70XX qlm_set_mode not implemented\n");
    return -1;
}


/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
static int qlm_get_gbaud_mhz(bdk_node_t node, int qlm)
{
    switch (qlm)
    {
        case 0:
        {
            BDK_CSR_INIT(inf_mode, node, BDK_GMXX_INF_MODE(0));
            switch (inf_mode.s.speed)
            {
                case 0: return 5000;    /* 5     Gbaud */
                case 1: return 2500;    /* 2.5   Gbaud */
                case 2: return 2500;    /* 2.5   Gbaud */
                case 3: return 1250;    /* 1.25  Gbaud */
                case 4: return 1250;    /* 1.25  Gbaud */
                case 5: return 6250;    /* 6.25  Gbaud */
                case 6: return 5000;    /* 5     Gbaud */
                case 7: return 2500;    /* 2.5   Gbaud */
                case 8: return 3125;    /* 3.125 Gbaud */
                case 9: return 2500;    /* 2.5   Gbaud */
                case 10: return 1250;   /* 1.25  Gbaud */
                case 11: return 5000;   /* 5     Gbaud */
                case 12: return 6250;   /* 6.25  Gbaud */
                case 13: return 3750;   /* 3.75  Gbaud */
                case 14: return 3125;   /* 3.125 Gbaud */
                default: return 0;      /* Disabled */
            }
        }
        case 1:
            return 0; /* FIXME: QLM speed */
        case 2:
            return 0; /* FIXME: QLM speed */
        default:
            return 0;
    }
}


/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
static int qlm_measure_refclock(bdk_node_t node, int qlm)
{
    extern const bdk_qlm_ops_t bdk_qlm_ops_cn61xx;
    return bdk_qlm_ops_cn61xx.measure_refclock(node, qlm);
}


/**
 * Reset a QLM to its initial state
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
static int qlm_reset(bdk_node_t node, int qlm)
{
    /* FIXME: Reset QLM */
    bdk_error("CN70XX QLM reset not implemented\n");
    return -1;
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
static int qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir)
{
    /* FIXME: Enable PRBS */
    bdk_error("CN70XX PRBS not implemented\n");
    return -1;
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
static int qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop)
{
    bdk_error("CN70XX doesn't support shallow QLM loopback\n");
    return -1;
}


/**
 * Initialize the QLM layer
 */
static void qlm_init(bdk_node_t node)
{
    /* Nothing to do? */
}


/* Each chip has its own QLM operation table */
const bdk_qlm_ops_t bdk_qlm_ops_cn70xx = {
    .chip_model = OCTEON_CN70XX,
    .init = qlm_init,
    .get_num = qlm_get_num,
    .get_lanes = qlm_get_lanes,
    .get_supported_modes = qlm_get_supported_modes,
    .get_mode = qlm_get_mode,
    .set_mode = qlm_set_mode,
    .get_gbaud_mhz = qlm_get_gbaud_mhz,
    .measure_refclock = qlm_measure_refclock,
    .get_qlm_num = qlm_get_qlm_num,
    .reset = qlm_reset,
    .enable_prbs = qlm_enable_prbs,
    .enable_loop = qlm_enable_loop,
};


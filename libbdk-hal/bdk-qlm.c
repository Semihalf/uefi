#include <bdk.h>
#include <stdio.h>
#include <math.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(QLM);

/* Each chip has its own QLM operation table */
extern const bdk_qlm_ops_t bdk_qlm_ops_cn88xx;

static const bdk_qlm_ops_t *qlm_ops_list[] = {
    &bdk_qlm_ops_cn88xx,
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
 * Convert a mode into a configuration variable string value
 *
 * @param mode   Mode to convert
 *
 * @return configuration value string
 */
const char *bdk_qlm_mode_to_cfg_str(bdk_qlm_modes_t mode)
{
#define MODE_CASE(m) case m: return #m+4
    switch (mode)
    {
        MODE_CASE(BDK_QLM_MODE_DISABLED);
        MODE_CASE(BDK_QLM_MODE_PCIE_1X1);
        MODE_CASE(BDK_QLM_MODE_PCIE_2X1);
        MODE_CASE(BDK_QLM_MODE_PCIE_1X2);
        MODE_CASE(BDK_QLM_MODE_PCIE_1X4);
        MODE_CASE(BDK_QLM_MODE_PCIE_1X8);

        MODE_CASE(BDK_QLM_MODE_SATA_4X1);

        MODE_CASE(BDK_QLM_MODE_ILK);
        MODE_CASE(BDK_QLM_MODE_SGMII);
        MODE_CASE(BDK_QLM_MODE_XAUI_1X4);
        MODE_CASE(BDK_QLM_MODE_RXAUI_2X2);
        MODE_CASE(BDK_QLM_MODE_OCI);
        MODE_CASE(BDK_QLM_MODE_XFI_4X1);
        MODE_CASE(BDK_QLM_MODE_XLAUI_1X4);
        MODE_CASE(BDK_QLM_MODE_10G_KR_4X1);
        MODE_CASE(BDK_QLM_MODE_40G_KR4_1X4);
        MODE_CASE(BDK_QLM_MODE_SKIP);

        case BDK_QLM_MODE_MAX: break; /* fall through error */
    }
    return "INVALID_QLM_MODE_VALUE";
}

/**
 * Convert a configuration variable value string into a mode
 *
 * @param val  Configuration variable value
 *
 * @return mode
 */
bdk_qlm_modes_t bdk_qlm_cfg_string_to_mode(const char *val)
{
    bdk_qlm_modes_t mode;

    for (mode = 0; mode < BDK_QLM_MODE_MAX; mode++)
    {
        if (0 == strcmp(val, bdk_qlm_mode_to_cfg_str(mode)))
        {
            return mode;
        }
    }
    return -1;
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

        case BDK_QLM_MODE_SATA_4X1:
            result = "4 SATA, one lane each";
            break;

        case BDK_QLM_MODE_ILK:
            result = "Interlaken";
            break;
        case BDK_QLM_MODE_SGMII:
            result = "SGMII, 1 lane each";
            break;
        case BDK_QLM_MODE_XAUI_1X4:
            result = "1 XAUI, 4 lanes";
            break;
        case BDK_QLM_MODE_RXAUI_2X2:
            result = "2 RXAUI, 2 lanes each";
            break;
        case BDK_QLM_MODE_OCI:
            result = "Cavium Coherent Processor Interconnect";
            break;
        case BDK_QLM_MODE_XFI_4X1:
            result = "4 XFI, 1 lane each";
            break;
        case BDK_QLM_MODE_XLAUI_1X4:
            result = "1 XLAUI, 4 lanes";
            break;
        case BDK_QLM_MODE_10G_KR_4X1:
            result = "4 10GBASE-KR, 1 lane each";
            break;
        case BDK_QLM_MODE_40G_KR4_1X4:
            result = "1 40GBASE-KR4, 4 lanes";
            break;
        case BDK_QLM_MODE_SKIP:
            result = "Not configured";
            break;
        case BDK_QLM_MODE_MAX:
            break; /* fallthrough error */
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
int bdk_qlm_set_mode(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz, bdk_qlm_mode_flags_t flags)
{
    int rc;

    bdk_qlm_modes_t old_mode = bdk_qlm_get_mode(node, qlm);
    if (old_mode == mode)
    {
        int old_baud_mhz = bdk_qlm_get_gbaud_mhz(node, qlm);
        if (old_baud_mhz == baud_mhz)
        {
            BDK_TRACE(QLM, "N%d.QLM%d: Skipping set_mode as QLM is already in correct mode\n", node, qlm);
            return 0;
        }
    }
    rc = qlm_ops->set_mode(node, qlm, mode, baud_mhz, flags);
    if (!rc)
    {
        /* If we succeeded to set the QLM mode, we also set the configuration
         * variables in the environment.
         */
        const char *mode_str = bdk_qlm_mode_to_cfg_str(mode);
        bdk_brd_cfg_set_str(mode_str, BRD_CFG_QLM_MODE, node, qlm);
        bdk_brd_cfg_set_int(baud_mhz, BRD_CFG_QLM_FREQ, node, qlm);
    }
    return rc;
}

/**
 * Set the QLM's clock source.
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param clk      Clock source for QLM
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_set_clock(bdk_node_t node, int qlm, bdk_qlm_clock_t clk)
{
    int sel;
    int com1;
    switch (clk)
    {
    case BDK_QLM_CLK_COMMON_0: sel = 1; com1 = 0; break;
    case BDK_QLM_CLK_COMMON_1: sel = 1; com1 = 1; break;
    case BDK_QLM_CLK_EXTERNAL: sel = 0; com1 = 0; break;
    default:
        bdk_warn("Unrecognized clock mode %d for QLM%d on node %d.\n",
                 clk, qlm, node);
        return -1;
    }

    BDK_CSR_MODIFY(c, node, BDK_GSERX_REFCLK_SEL(qlm),
        c.s.com_clk_sel = sel;
        c.s.use_com1 = com1);
    printf("##### bdk_qlm_set_clock(): clk:%d\n", clk);
    bdk_brd_cfg_set_int(clk, BRD_CFG_QLM_CLK, node, qlm);
    return 0;
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
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        /* Force the reference to 156.25Mhz when running in simulation.
            This supports the most speeds */
        return 156250000;
    }
    int ref_clock = qlm_ops->measure_refclock(node, qlm);
    BDK_TRACE(QLM, "N%d.QLM%d: Ref clock %d Hz\n", node, qlm, ref_clock);
    return ref_clock;
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
 * Return the number of PRBS errors since PRBS started running
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 * @param clear  Clear the counter after returning its value
 *
 * @return Number of errors
 */
uint64_t bdk_qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane, int clear)
{
    return qlm_ops->get_prbs_errors(node, qlm, lane, clear);
}

/**
 * Inject an error into PRBS
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 */
void bdk_qlm_inject_prbs_error(bdk_node_t node, int qlm, int lane)
{
    qlm_ops->inject_prbs_error(node, qlm, lane);
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
 * Perform RX equalization on a QLM
 *
 * @param node   Node the QLM is on
 * @param qlm    QLM to perform RX equalization on
 * @param lane   Lane to use, or -1 for all lanes
 *
 * @return Zero on success, negative if any lane failed RX equalization
 */
int bdk_qlm_rx_equalization(bdk_node_t node, int qlm, int lane)
{
    return qlm_ops->rx_equalization(node, qlm, lane);
}

/**
 * Capture an eye diagram for the given QLM lane. The output data is written
 * to "eye".
 *
 * @param node     Node to use in numa setup
 * @param qlm      QLM to use
 * @param qlm_lane Which lane
 * @param eye      Output eye data
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_eye_capture(bdk_node_t node, int qlm, int qlm_lane, bdk_qlm_eye_t *eye)
{
    if (qlm_ops->eye_capture)
        return qlm_ops->eye_capture(node, qlm, qlm_lane, eye);
    else
    {
        bdk_error("Eye capture not supported on this chip\n");
        return -1;
    }
}

/**
 * Display an eye diagram for the given QLM lane. The eye data can be in "eye", or
 * captured during the call if "eye" is NULL.
 *
 * @param node     Node to use in numa setup
 * @param qlm      QLM to use
 * @param qlm_lane Which lane
 * @param format   Display format. 0 = raw, 1 = Color ASCII
 * @param eye      Eye data to display, or NULL if the data should be captured.
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_eye_display(bdk_node_t node, int qlm, int qlm_lane, int format, const bdk_qlm_eye_t *eye)
{
    int result;
    int need_free = 0;
    if (eye == NULL)
    {
        bdk_qlm_eye_t *eye_data = malloc(sizeof(bdk_qlm_eye_t));
        if (eye_data == NULL)
        {
            bdk_error("Failed to allocate space for eye\n");
            return -1;
        }
        if (bdk_qlm_eye_capture(node, qlm, qlm_lane, eye_data))
            return -1;
        eye = eye_data;
    }

    printf("\nEye Diagram for Node %d, QLM %d, Lane %d\n", node, qlm, qlm_lane);

    if (format == 0) /* Raw */
    {
        for (int y = 0; y < eye->height; y++)
        {
            for (int x = 0; x < eye->width; x++)
                printf("%u\t", eye->data[y][x]);
            printf("\n");
        }
        result = 0;
    }
    else if (format == 1) /* Color ASCII */
    {
        int last_color = -1;
        char color_str[] = "\33[40m"; /* Note: This is modified, not constant */

        for (int y = 0; y < eye->height-1; y++)
        {
            for (int x = 0; x < eye->width-1; x++)
            {
                #define DIFF(a,b) (a<b) ? b-a : a-b
                int64_t dy = DIFF(eye->data[y][x], eye->data[y + 1][x]);
                int64_t dx = DIFF(eye->data[y][x], eye->data[y][x + 1]);
                #undef DIFF
                int64_t dist = dx * dx + dy * dy;
                double f = log10(sqrt(dist) + 1);
                const double MAX_LOG = 6;
                if (f > MAX_LOG)
                    f = MAX_LOG;
                int level = 9 * f / MAX_LOG + 0.5;
                int color = 7.0 * f / MAX_LOG + 0.5;
                if (color != last_color)
                {
                    color_str[3] = '0' + color;
                    fputs(color_str, stdout);
                    last_color = color;
                }
                fputc('0' + level, stdout);
            }
            fputs("\33[0m\n", stdout);
            last_color = -1;
        }
        result = 0;
    }
    else
        result = -1;

    if (need_free)
        free((void*)eye);
    return result;
}

/**
 * Call the board specific method of determining the required QLM configuration
 * and automatically settign up the QLMs to match. For example, on the EBB8800
 * this function queries the MCU for the current setup.
 *
 * @param node   Node to configure
 *
 * @return Zero on success, negative on failure
 */
int bdk_qlm_auto_config(bdk_node_t node)
{
    if (qlm_ops->auto_config)
        return qlm_ops->auto_config(node);
    bdk_error("QLM auto config is not implemented for this setup");
    return -1;
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
        if (CAVIUM_IS_MODEL(qlm_ops_list[i]->chip_model))
        {
            qlm_ops = qlm_ops_list[i];
            break;
        }
        i++;
    }

    if (!qlm_ops)
        bdk_fatal("bdk_qlm_init: OPs table not found for this chip\n");

    /* Skip QLM setup in simulation */
    if (!bdk_is_platform(BDK_PLATFORM_ASIM))
        qlm_ops->init(node);
}


#ifndef __BDK_QLM_COMMON_H__
#define __BDK_QLM_COMMON_H__

/* Common QLM code for Thunder based processors. The following chips
    use the same style SERDES, using the code defined in this header.
        CN88XX
        CN83XX
*/

/* These constants represent the possible QLM reference clock speeds in Hz */
#define REF_100MHZ 100000000
#define REF_125MHZ 125000000
#define REF_156MHZ 156250000

/**
 * Figure out which lane mode to use for a given reference clock and GBaud
 *
 * @param mode_name String name for error messages
 * @param qlm       QlM being configured
 * @param ref_clk   Reference clock in hertz
 * @param baud_mhz  Baud rate in Mhz
 *
 * @return Lane mode or -1 on failure
 */
extern int __bdk_qlm_get_lane_mode_for_speed_and_ref_clk(const char *mode_name, int qlm, int ref_clk, int baud_mhz);

/**
 * Setup the PEM to either driver or receive reset from PRST based on RC or EP
 *
 * @param node   Node to use in a Numa setup
 * @param pem    Which PEM to setuo
 * @param is_endpoint
 *               Non zero if PEM is a EP
 */
extern void __bdk_qlm_setup_pem_reset(bdk_node_t node, int pem, int is_endpoint);

/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
extern int __bdk_qlm_measure_refclock(bdk_node_t node, int qlm);

/**
 * Put a QLM into hardware reset
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
extern int __bdk_qlm_reset(bdk_node_t node, int qlm);

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
extern int __bdk_qlm_enable_prbs(bdk_node_t node, int qlm, int prbs, bdk_qlm_direction_t dir);

/**
 * Disable PRBS on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 *
 * @return Zero on success, negative on failure
 */
extern int __bdk_qlm_disable_prbs(bdk_node_t node, int qlm);

/**
 * Return the number of PRBS errors since PRBS started running
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 * @param clear  Clear counter after return the current value
 *
 * @return Number of errors
 */
extern uint64_t __bdk_qlm_get_prbs_errors(bdk_node_t node, int qlm, int lane, int clear);

/**
 * Inject an error into PRBS
 *
 * @param node   Node to use in numa setup
 * @param qlm    QLM to use
 * @param lane   Which lane
 */
extern void __bdk_qlm_inject_prbs_error(bdk_node_t node, int qlm, int lane);

/**
 * Enable shallow loopback on a QLM
 *
 * @param node   Node to use in a numa setup
 * @param qlm    QLM to use
 * @param loop   Type of loopback. Not all QLMs support all modes
 *
 * @return Zero on success, negative on failure
 */
extern int __bdk_qlm_enable_loop(bdk_node_t node, int qlm, bdk_qlm_loop_t loop);

/**
 * Initialize the QLM mode table
 *
 * @param node   Node to initialize
 * @param qlm    Which QLM
 */
extern void __bdk_qlm_init_mode_table(bdk_node_t node, int qlm);

/**
 * Given a valid PEM number, return its speed in Gbaud
 *
 * @param node   Node to use in numa setup
 * @param pem    PEM to get speed of
 *
 * @return Speed in Gbaud. Zero if disabled
 */
extern int __bdk_qlm_get_gbaud_mhz_pem(bdk_node_t node, int pem);

/**
 * Get the speed of a QLM using its LMODE. This can't be used on PCIe QLMs.
 *
 * @param node   Node to use in numa setup
 * @param qlm    Which QLM
 *
 * @return QLM speed on Gbaud
 */
extern int __bdk_qlm_get_gbaud_mhz_lmode(bdk_node_t node, int qlm);

/**
 * Converts a measured reference clock to a likely ideal value. Rounds
 * clock speed to the nearest REF_*Mhz define.
 *
 * @param measured_hz
 *               Measured value
 *
 * @return Value exactly matching a define
 */
extern int __bdk_qlm_round_refclock(int measured_hz);

/**
 * For Cavium EVB and EBB board, query the MCU to determine the QLM setup. Applying
 * any configuration found.
 *
 * @param node   Node to configure
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_qlm_mcu_auto_config(bdk_node_t node);

/**
 * Perform RX equalization on a QLM
 *
 * @param node     Node the QLM is on
 * @param qlm      QLM to perform RX equalization on
 * @param qlm_lane Lane to use, or -1 for all lanes
 *
 * @return Zero on success, negative if any lane failed RX equalization
 */
extern int __bdk_qlm_rx_equalization(bdk_node_t node, int qlm, int qlm_lane);

/**
 * Some QLM speeds need to override the default tuning parameters
 *
 * @param node     Node to use in a Numa setup
 * @param qlm      QLM to configure
 * @param mode     Desired mode
 * @param baud_mhz Desired speed
 */
extern void __bdk_qlm_tune(bdk_node_t node, int qlm, bdk_qlm_modes_t mode, int baud_mhz);

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
extern int __bdk_qlm_eye_capture_cn8xxx(bdk_node_t node, int qlm, int lane, bdk_qlm_eye_t *eye_data);

#endif /* __BDK_QLM_COMMON_H__ */

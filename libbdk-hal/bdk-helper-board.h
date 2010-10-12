/**
 * @file
 *
 * Helper functions to abstract board specific data about
 * network ports from the rest of the cvmx-helper files.
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef enum {
    USB_CLOCK_TYPE_REF_12,
    USB_CLOCK_TYPE_REF_24,
    USB_CLOCK_TYPE_REF_48,
    USB_CLOCK_TYPE_CRYSTAL_12,
} bdk_helper_board_usb_clock_types_t;

typedef enum {
    set_phy_link_flags_autoneg                  = 0x1,
    set_phy_link_flags_flow_control_dont_touch  = 0x0 << 1,
    set_phy_link_flags_flow_control_enable      = 0x1 << 1,
    set_phy_link_flags_flow_control_disable     = 0x2 << 1,
    set_phy_link_flags_flow_control_mask        = 0x3 << 1,  /* Mask for 2 bit wide flow control field */
} bdk_helper_board_set_phy_link_flags_types_t;


/* Fake IPD port, the RGMII/MII interface may use different PHY, use this
   macro to return appropriate MIX address to read the PHY. */
#define BDK_HELPER_BOARD_MGMT_IPD_PORT     -10

/**
 * bdk_override_board_link_get(int ipd_port) is a function
 * pointer. It is meant to allow customization of the process of
 * talking to a PHY to determine link speed. It is called every
 * time a PHY must be polled for link status. Users should set
 * this pointer to a function before calling any cvmx-helper
 * operations.
 */
extern bdk_helper_link_info_t (*bdk_override_board_link_get)(int ipd_port);

/**
 * This function as a board specific method of changing the PHY
 * speed, duplex, and autonegotiation. This programs the PHY and
 * not Octeon. This can be used to force Octeon's links to
 * specific settings.
 *
 * @param phy_addr  The address of the PHY to program
 * @param link_flags
 *                  Flags to control autonegotiation.  Bit 0 is autonegotiation
 *                  enable/disable to maintain backward compatibility.
 * @param link_info Link speed to program. If the speed is zero and autonegotiation
 *                  is enabled, all possible negotiation speeds are advertised.
 *
 * @return Zero on success, negative on failure
 */
int bdk_helper_board_link_set_phy(int phy_addr, bdk_helper_board_set_phy_link_flags_types_t link_flags,
                                   bdk_helper_link_info_t link_info);


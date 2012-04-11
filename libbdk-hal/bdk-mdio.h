/**
 * @file
 *
 * Interface to the SMI/MDIO hardware, including support for both IEEE 802.3
 * clause 22 and clause 45 operations.
 *
 * <hr>$Revision: 51350 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * PHY register 0 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_CONTROL 0
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t reset : 1;
        uint16_t loopback : 1;
        uint16_t speed_lsb : 1;
        uint16_t autoneg_enable : 1;
        uint16_t power_down : 1;
        uint16_t isolate : 1;
        uint16_t restart_autoneg : 1;
        uint16_t duplex : 1;
        uint16_t collision_test : 1;
        uint16_t speed_msb : 1;
        uint16_t unidirectional_enable : 1;
        uint16_t reserved_0_4 : 5;
    } s;
} bdk_mdio_phy_reg_control_t;

/**
 * PHY register 1 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_STATUS 1
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t capable_100base_t4 : 1;
        uint16_t capable_100base_x_full : 1;
        uint16_t capable_100base_x_half : 1;
        uint16_t capable_10_full : 1;
        uint16_t capable_10_half : 1;
        uint16_t capable_100base_t2_full : 1;
        uint16_t capable_100base_t2_half : 1;
        uint16_t capable_extended_status : 1;
        uint16_t capable_unidirectional : 1;
        uint16_t capable_mf_preamble_suppression : 1;
        uint16_t autoneg_complete : 1;
        uint16_t remote_fault : 1;
        uint16_t capable_autoneg : 1;
        uint16_t link_status : 1;
        uint16_t jabber_detect : 1;
        uint16_t capable_extended_registers : 1;

    } s;
} bdk_mdio_phy_reg_status_t;

/**
 * PHY register 2 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_ID1 2
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t oui_bits_3_18;
    } s;
} bdk_mdio_phy_reg_id1_t;

/**
 * PHY register 3 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_ID2 3
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t oui_bits_19_24 : 6;
        uint16_t model : 6;
        uint16_t revision : 4;
    } s;
} bdk_mdio_phy_reg_id2_t;

/**
 * PHY register 4 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_AUTONEG_ADVER 4
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t next_page : 1;
        uint16_t reserved_14 : 1;
        uint16_t remote_fault : 1;
        uint16_t reserved_12 : 1;
        uint16_t asymmetric_pause : 1;
        uint16_t pause : 1;
        uint16_t advert_100base_t4 : 1;
        uint16_t advert_100base_tx_full : 1;
        uint16_t advert_100base_tx_half : 1;
        uint16_t advert_10base_tx_full : 1;
        uint16_t advert_10base_tx_half : 1;
        uint16_t selector : 5;
    } s;
} bdk_mdio_phy_reg_autoneg_adver_t;

/**
 * PHY register 5 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_LINK_PARTNER_ABILITY 5
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t next_page : 1;
        uint16_t ack : 1;
        uint16_t remote_fault : 1;
        uint16_t reserved_12 : 1;
        uint16_t asymmetric_pause : 1;
        uint16_t pause : 1;
        uint16_t advert_100base_t4 : 1;
        uint16_t advert_100base_tx_full : 1;
        uint16_t advert_100base_tx_half : 1;
        uint16_t advert_10base_tx_full : 1;
        uint16_t advert_10base_tx_half : 1;
        uint16_t selector : 5;
    } s;
} bdk_mdio_phy_reg_link_partner_ability_t;

/**
 * PHY register 6 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_AUTONEG_EXPANSION 6
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t reserved_5_15 : 11;
        uint16_t parallel_detection_fault : 1;
        uint16_t link_partner_next_page_capable : 1;
        uint16_t local_next_page_capable : 1;
        uint16_t page_received : 1;
        uint16_t link_partner_autoneg_capable : 1;

    } s;
} bdk_mdio_phy_reg_autoneg_expansion_t;

/**
 * PHY register 9 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_CONTROL_1000 9
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t test_mode : 3;
        uint16_t manual_master_slave : 1;
        uint16_t master : 1;
        uint16_t port_type : 1;
        uint16_t advert_1000base_t_full : 1;
        uint16_t advert_1000base_t_half : 1;
        uint16_t reserved_0_7 : 8;
    } s;
} bdk_mdio_phy_reg_control_1000_t;

/**
 * PHY register 10 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_STATUS_1000 10
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t master_slave_fault : 1;
        uint16_t is_master : 1;
        uint16_t local_receiver_ok : 1;
        uint16_t remote_receiver_ok : 1;
        uint16_t remote_capable_1000base_t_full : 1;
        uint16_t remote_capable_1000base_t_half : 1;
        uint16_t reserved_8_9 : 2;
        uint16_t idle_error_count : 8;
    } s;
} bdk_mdio_phy_reg_status_1000_t;

/**
 * PHY register 15 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_EXTENDED_STATUS 15
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t capable_1000base_x_full : 1;
        uint16_t capable_1000base_x_half : 1;
        uint16_t capable_1000base_t_full : 1;
        uint16_t capable_1000base_t_half : 1;
        uint16_t reserved_0_11 : 12;
    } s;
} bdk_mdio_phy_reg_extended_status_t;


/**
 * PHY register 13 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_MMD_CONTROL 13
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t function : 2;
        uint16_t reserved_5_13 : 9;
        uint16_t devad : 5;
    } s;
} bdk_mdio_phy_reg_mmd_control_t;

/**
 * PHY register 14 from the 802.3 spec
 */
#define BDK_MDIO_PHY_REG_MMD_ADDRESS_DATA 14
typedef union
{
    uint16_t u16;
    struct
    {
        uint16_t address_data : 16;
    } s;
} bdk_mdio_phy_reg_mmd_address_data_t;

/* MMD identifiers, mostly for accessing devices within XENPAK modules. */
#define BDK_MMD_DEVICE_PMA_PMD      1
#define BDK_MMD_DEVICE_WIS          2
#define BDK_MMD_DEVICE_PCS          3
#define BDK_MMD_DEVICE_PHY_XS       4
#define BDK_MMD_DEVICE_DTS_XS       5
#define BDK_MMD_DEVICE_TC           6
#define BDK_MMD_DEVICE_CL22_EXT     29
#define BDK_MMD_DEVICE_VENDOR_1     30
#define BDK_MMD_DEVICE_VENDOR_2     31

/**
 * Perform an MII read. This function is used to read PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param location Register location to read
 *
 * @return Result from the read or -1 on failure
 */
extern int bdk_mdio_read(int bus_id, int phy_id, int location);

/**
 * Perform an MII write. This function is used to write PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param location Register location to write
 * @param val      Value to write
 *
 * @return -1 on error
 *         0 on success
 */
extern int bdk_mdio_write(int bus_id, int phy_id, int location, int val);

/**
 * Perform an IEEE 802.3 clause 45 MII read. This function is used to read PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param device   MDIO Manageable Device (MMD) id
 * @param location Register location to read
 *
 * @return Result from the read or -1 on failure
 */

extern int bdk_mdio_45_read(int bus_id, int phy_id, int device, int location);

/**
 * Perform an IEEE 802.3 clause 45 MII write. This function is used to write PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param device   MDIO Manageable Device (MMD) id
 * @param location Register location to write
 * @param val      Value to write
 *
 * @return -1 on error
 *         0 on success
 */
extern int bdk_mdio_45_write(int bus_id, int phy_id, int device, int location,
                                     int val);

/** @} */

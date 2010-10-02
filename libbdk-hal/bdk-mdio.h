/**
 * @file
 *
 * Interface to the SMI/MDIO hardware, including support for both IEEE 802.3
 * clause 22 and clause 45 operations.
 *
 * <hr>$Revision: 51350 $<hr>
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

/* Operating request encodings. */
#define MDIO_CLAUSE_22_WRITE    0
#define MDIO_CLAUSE_22_READ     1

#define MDIO_CLAUSE_45_ADDRESS  0
#define MDIO_CLAUSE_45_WRITE    1
#define MDIO_CLAUSE_45_READ_INC 2
#define MDIO_CLAUSE_45_READ     3

/* MMD identifiers, mostly for accessing devices withing XENPAK modules. */
#define BDK_MMD_DEVICE_PMA_PMD      1
#define BDK_MMD_DEVICE_WIS          2
#define BDK_MMD_DEVICE_PCS          3
#define BDK_MMD_DEVICE_PHY_XS       4
#define BDK_MMD_DEVICE_DTS_XS       5
#define BDK_MMD_DEVICE_TC           6
#define BDK_MMD_DEVICE_CL22_EXT     29
#define BDK_MMD_DEVICE_VENDOR_1     30
#define BDK_MMD_DEVICE_VENDOR_2     31

#define BDK_MDIO_TIMEOUT   100000 /* 100 millisec */

/* Helper function to put MDIO interface into clause 45 mode */
static inline void __bdk_mdio_set_clause45_mode(int bus_id)
{
    bdk_smix_clk_t smi_clk;
    /* Put bus into clause 45 mode */
    smi_clk.u64 = BDK_CSR_READ(BDK_SMIX_CLK(bus_id));
    smi_clk.s.mode = 1;
    smi_clk.s.preamble = 1;
    BDK_CSR_WRITE(BDK_SMIX_CLK(bus_id), smi_clk.u64);
}
/* Helper function to put MDIO interface into clause 22 mode */
static inline void __bdk_mdio_set_clause22_mode(int bus_id)
{
    bdk_smix_clk_t smi_clk;
    /* Put bus into clause 22 mode */
    smi_clk.u64 = BDK_CSR_READ(BDK_SMIX_CLK(bus_id));
    smi_clk.s.mode = 0;
    BDK_CSR_WRITE(BDK_SMIX_CLK(bus_id), smi_clk.u64);
}

/**
 * @INTERNAL
 * Function to read SMIX_RD_DAT and check for timeouts. This
 * code sequence is done fairly often, so put in in one spot.
 *
 * @param bus_id SMI/MDIO bus to read
 *
 * @return Value of SMIX_RD_DAT. pending will be set on
 *         a timeout.
 */
static inline bdk_smix_rd_dat_t __bdk_mdio_read_rd_dat(int bus_id)
{
    bdk_smix_rd_dat_t smi_rd;
    uint64_t done = bdk_get_cycle() + (uint64_t)BDK_MDIO_TIMEOUT *
                       bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000;
    do
    {
        bdk_wait(1000);
        smi_rd.u64 = BDK_CSR_READ(BDK_SMIX_RD_DAT(bus_id));
    } while (smi_rd.s.pending && (bdk_get_cycle() < done));
    return smi_rd;
}


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
static inline int bdk_mdio_read(int bus_id, int phy_id, int location)
{
#if defined(BDK_BUILD_FOR_LINUX_KERNEL) && defined(CONFIG_PHYLIB)
	struct mii_bus *bus;
	int rv;

	BUG_ON(bus_id > 1 || bus_id < 0);

	bus = octeon_mdiobuses[bus_id];
	if (bus == NULL)
		return -1;

	rv = mdiobus_read(bus, phy_id, location);

	if (rv < 0)
		return -1;
	return rv;
#else
    bdk_smix_cmd_t smi_cmd;
    bdk_smix_rd_dat_t smi_rd;

    if (octeon_has_feature(OCTEON_FEATURE_MDIO_CLAUSE_45))
        __bdk_mdio_set_clause22_mode(bus_id);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_22_READ;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = location;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    smi_rd = __bdk_mdio_read_rd_dat(bus_id);
    if (smi_rd.s.val)
        return smi_rd.s.dat;
    else
        return -1;
#endif
}


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
static inline int bdk_mdio_write(int bus_id, int phy_id, int location, int val)
{
#if defined(BDK_BUILD_FOR_LINUX_KERNEL) && defined(CONFIG_PHYLIB)
	struct mii_bus *bus;
	int rv;

	BUG_ON(bus_id > 1 || bus_id < 0);

	bus = octeon_mdiobuses[bus_id];
	if (bus == NULL)
		return -1;

	rv = mdiobus_write(bus, phy_id, location, (u16)val);

	if (rv < 0)
		return -1;
	return 0;
#else
     bdk_smix_cmd_t smi_cmd;
    bdk_smix_wr_dat_t smi_wr;

    if (octeon_has_feature(OCTEON_FEATURE_MDIO_CLAUSE_45))
        __bdk_mdio_set_clause22_mode(bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = val;
    BDK_CSR_WRITE(BDK_SMIX_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_22_WRITE;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = location;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    if (BDK_WAIT_FOR_FIELD64(BDK_SMIX_WR_DAT(bus_id),
        bdk_smix_wr_dat_t, pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    return 0;
#endif
}

#ifndef BDK_BUILD_FOR_LINUX_KERNEL
/**
 * Perform an IEEE 802.3 clause 45 MII read. This function is used to read PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param device   MDIO Managable Device (MMD) id
 * @param location Register location to read
 *
 * @return Result from the read or -1 on failure
 */

static inline int bdk_mdio_45_read(int bus_id, int phy_id, int device, int location)
{
    bdk_smix_cmd_t smi_cmd;
    bdk_smix_rd_dat_t smi_rd;
    bdk_smix_wr_dat_t smi_wr;

    if (!octeon_has_feature(OCTEON_FEATURE_MDIO_CLAUSE_45))
        return -1;

    __bdk_mdio_set_clause45_mode(bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = location;
    BDK_CSR_WRITE(BDK_SMIX_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_ADDRESS;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    if (BDK_WAIT_FOR_FIELD64(BDK_SMIX_WR_DAT(bus_id),
        bdk_smix_wr_dat_t, pending, ==, 0, BDK_MDIO_TIMEOUT))
    {
        bdk_dprintf ("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   TIME OUT(address)\n", bus_id, phy_id, device, location);
        return -1;
    }

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_READ;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    smi_rd = __bdk_mdio_read_rd_dat(bus_id);
    if (smi_rd.s.pending)
    {
        bdk_dprintf ("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   TIME OUT(data)\n", bus_id, phy_id, device, location);
        return -1;
    }

    if (smi_rd.s.val)
        return smi_rd.s.dat;
    else
    {
        bdk_dprintf ("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   INVALID READ\n", bus_id, phy_id, device, location);
        return -1;
    }
}

/**
 * Perform an IEEE 802.3 clause 45 MII write. This function is used to write PHY
 * registers controlling auto negotiation.
 *
 * @param bus_id   MDIO bus number. Zero on most chips, but some chips (ex CN56XX)
 *                 support multiple busses.
 * @param phy_id   The MII phy id
 * @param device   MDIO Managable Device (MMD) id
 * @param location Register location to write
 * @param val      Value to write
 *
 * @return -1 on error
 *         0 on success
 */
static inline int bdk_mdio_45_write(int bus_id, int phy_id, int device, int location,
                                     int val)
{
    bdk_smix_cmd_t smi_cmd;
    bdk_smix_wr_dat_t smi_wr;

    if (!octeon_has_feature(OCTEON_FEATURE_MDIO_CLAUSE_45))
        return -1;

    __bdk_mdio_set_clause45_mode(bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = location;
    BDK_CSR_WRITE(BDK_SMIX_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_ADDRESS;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    if (BDK_WAIT_FOR_FIELD64(BDK_SMIX_WR_DAT(bus_id),
        bdk_smix_wr_dat_t, pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    smi_wr.u64 = 0;
    smi_wr.s.dat = val;
    BDK_CSR_WRITE(BDK_SMIX_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_WRITE;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(BDK_SMIX_CMD(bus_id), smi_cmd.u64);

    if (BDK_WAIT_FOR_FIELD64(BDK_SMIX_WR_DAT(bus_id),
        bdk_smix_wr_dat_t, pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    return 0;
}
#endif


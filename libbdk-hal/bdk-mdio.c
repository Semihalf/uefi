#include <bdk.h>

#define BDK_MDIO_TIMEOUT   100000 /* 100 millisec */

/* Operating request encodings. */
#define MDIO_CLAUSE_22_WRITE    0
#define MDIO_CLAUSE_22_READ     1

#define MDIO_CLAUSE_45_ADDRESS  0
#define MDIO_CLAUSE_45_WRITE    1
#define MDIO_CLAUSE_45_READ_INC 2
#define MDIO_CLAUSE_45_READ     3

/**
 * Helper function to put MDIO interface into clause 45 mode
 *
 * @param bus_id
 */
static void __bdk_mdio_set_clause45_mode(bdk_node_t node, int bus_id)
{
    bdk_smi_x_clk_t smi_clk;
    /* Put bus into clause 45 mode */
    smi_clk.u64 = BDK_CSR_READ(node, BDK_SMI_X_CLK(bus_id));
    if (smi_clk.s.mode != 1)
    {
        smi_clk.s.mode = 1;
        smi_clk.s.preamble = 1;
        BDK_CSR_WRITE(node, BDK_SMI_X_CLK(bus_id), smi_clk.u64);
    }
}

/**
 * Helper function to put MDIO interface into clause 22 mode
 *
 * @param bus_id
 */
static void __bdk_mdio_set_clause22_mode(bdk_node_t node, int bus_id)
{
    bdk_smi_x_clk_t smi_clk;
    /* Put bus into clause 22 mode */
    smi_clk.u64 = BDK_CSR_READ(node, BDK_SMI_X_CLK(bus_id));
    if (smi_clk.s.mode != 0)
    {
        smi_clk.s.mode = 0;
        BDK_CSR_WRITE(node, BDK_SMI_X_CLK(bus_id), smi_clk.u64);
    }
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
static bdk_smi_x_rd_dat_t __bdk_mdio_read_rd_dat(bdk_node_t node, int bus_id)
{
    bdk_smi_x_rd_dat_t smi_rd;
    uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + (uint64_t)BDK_MDIO_TIMEOUT *
                       bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 1000000;
    do
    {
        bdk_wait(1000);
        smi_rd.u64 = BDK_CSR_READ(node, BDK_SMI_X_RD_DAT(bus_id));
    } while (smi_rd.s.pending && (bdk_clock_get_count(BDK_CLOCK_CORE) < done));
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
int bdk_mdio_read(bdk_node_t node, int bus_id, int phy_id, int location)
{
    bdk_smi_x_cmd_t smi_cmd;
    bdk_smi_x_rd_dat_t smi_rd;

    __bdk_mdio_set_clause22_mode(node, bus_id);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_22_READ;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = location;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    smi_rd = __bdk_mdio_read_rd_dat(node, bus_id);
    if (smi_rd.s.val)
        return smi_rd.s.dat;
    else
        return -1;
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
int bdk_mdio_write(bdk_node_t node, int bus_id, int phy_id, int location, int val)
{
    bdk_smi_x_cmd_t smi_cmd;
    bdk_smi_x_wr_dat_t smi_wr;

    __bdk_mdio_set_clause22_mode(node, bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = val;
    BDK_CSR_WRITE(node, BDK_SMI_X_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_22_WRITE;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = location;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_SMI_X_WR_DAT(bus_id), pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    return 0;
}

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

int bdk_mdio_45_read(bdk_node_t node, int bus_id, int phy_id, int device, int location)
{
    bdk_smi_x_cmd_t smi_cmd;
    bdk_smi_x_rd_dat_t smi_rd;
    bdk_smi_x_wr_dat_t smi_wr;

    __bdk_mdio_set_clause45_mode(node, bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = location;
    BDK_CSR_WRITE(node, BDK_SMI_X_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_ADDRESS;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_SMI_X_WR_DAT(bus_id), pending, ==, 0, BDK_MDIO_TIMEOUT))
    {
        bdk_error("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   TIME OUT(address)\n", bus_id, phy_id, device, location);
        return -1;
    }

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_READ;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    smi_rd = __bdk_mdio_read_rd_dat(node, bus_id);
    if (smi_rd.s.pending)
    {
        bdk_error("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   TIME OUT(data)\n", bus_id, phy_id, device, location);
        return -1;
    }

    if (smi_rd.s.val)
        return smi_rd.s.dat;
    else
    {
        bdk_error("bdk_mdio_45_read: bus_id %d phy_id %2d device %2d register %2d   INVALID READ\n", bus_id, phy_id, device, location);
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
 * @param device   MDIO Manageable Device (MMD) id
 * @param location Register location to write
 * @param val      Value to write
 *
 * @return -1 on error
 *         0 on success
 */
int bdk_mdio_45_write(bdk_node_t node, int bus_id, int phy_id, int device, int location,
                                     int val)
{
    bdk_smi_x_cmd_t smi_cmd;
    bdk_smi_x_wr_dat_t smi_wr;

    __bdk_mdio_set_clause45_mode(node, bus_id);

    smi_wr.u64 = 0;
    smi_wr.s.dat = location;
    BDK_CSR_WRITE(node, BDK_SMI_X_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_ADDRESS;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_SMI_X_WR_DAT(bus_id), pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    smi_wr.u64 = 0;
    smi_wr.s.dat = val;
    BDK_CSR_WRITE(node, BDK_SMI_X_WR_DAT(bus_id), smi_wr.u64);

    smi_cmd.u64 = 0;
    smi_cmd.s.phy_op = MDIO_CLAUSE_45_WRITE;
    smi_cmd.s.phy_adr = phy_id;
    smi_cmd.s.reg_adr = device;
    BDK_CSR_WRITE(node, BDK_SMI_X_CMD(bus_id), smi_cmd.u64);

    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_SMI_X_WR_DAT(bus_id), pending, ==, 0, BDK_MDIO_TIMEOUT))
        return -1;

    return 0;
}



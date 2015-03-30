#include <bdk.h>

/**
 * Called when the PHY is connected through TWSI
 *
 * @param dev_node Node the etherent device is on
 * @param phy_addr Encoded address, see bdk-if.h for format
 *
 * @return Link status
 */
static bdk_if_link_t __bdk_if_phy_get_twsi(bdk_node_t dev_node, int phy_addr)
{
    /* For TWSI:
        Bits[31:24]: Node ID, 0xff for device node
        Bits[23:16]: TWSI internal address width in bytes (0-2)
        Bits[15:12]: 2=TWSI
        Bits[11:8]: TWSI bus number
        Bits[7:0]: TWSI address */
    int node = (phy_addr >> 24) & 0xff;
    int twsi_ia_width = (phy_addr >> 16) & 0xff;
    int twsi_bus = (phy_addr >> 8) & 0xf;
    int twsi_addr = phy_addr & 0xff;
    if (node == 0xff)
        node = dev_node;

    bdk_if_link_t result;
    result.u64 = 0;

    /* This is from the Avago SFP 1G Module data sheet
       Register 17 (Extended Status 1) */
    int64_t phy_status = bdk_twsix_read_ia(node, twsi_bus, twsi_addr, 17, 2, twsi_ia_width);
    if (phy_status != -1)
    {
        int speed = (phy_status >> 14)& 3;
        int duplex = (phy_status >> 13)& 1;
        int resolved = (phy_status >> 11)& 1;
        int link = (phy_status >> 10)& 1;
        if (resolved)
        {
            result.s.up = link;
            result.s.full_duplex = duplex;
            switch (speed)
            {
                case 0: /* 10 Mbps */
                    result.s.speed = 10;
                    break;
                case 1: /* 100 Mbps */
                    result.s.speed = 100;
                    break;
                case 2: /* 1 Gbps */
                    result.s.speed = 1000;
                    break;
                case 3: /* Illegal */
                    result.u64 = 0;
                    break;
            }
        }
    }

    return result;
}

/**
 * Read the status of a PHY
 *
 * @param dev_node Node the etherent device is on
 * @param phy_addr Encoded PHY address, see bdk-if.h for format
 *
 * @return Link status
 */
bdk_if_link_t __bdk_if_phy_get(bdk_node_t dev_node, int phy_addr)
{
    int node = (phy_addr >> 24) & 0xff;
    int mdio_bus = (phy_addr >> 8) & 0xff;
    int mdio_addr = phy_addr & 0xff;
    if (node == 0xff)
        node = dev_node;
    int phy_status;
    bdk_if_link_t result;
    result.u64 = 0;

    /* PHY address of -1 menas there is no PHY and we should have never
        gotten here */
    if (phy_addr == -1)
        return result;

    /* A PHY address with the special value 0x1000 represents a PHY we can't
        connect to through MDIO which is assumed to be at 1Gbps */
    if (phy_addr == BDK_IF_PHY_FIXED_1GB)
    {
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 1000;
        return result;
    }

    /* A PHY address with the special value 0x1001 represents a PHY we can't
        connect to through MDIO which is assumed to be at 100Mbps */
    if (phy_addr == BDK_IF_PHY_FIXED_100MB)
    {
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 100;
        return result;
    }

    /* The simulator doesn't model PHYs, so just assume a 1Gbps connection */
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
    {
        result.s.up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 1000;
        return result;
    }

    /* Check for a PHY connected through TWSI */
    if ((phy_addr & BDK_IF_PHY_TYPE_MASK) == BDK_IF_PHY_TWSI)
        return __bdk_if_phy_get_twsi(dev_node, phy_addr);

    phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, BDK_MDIO_PHY_REG_ID1);
    if ((phy_status <= 0) || (phy_status == 0xffff))
        return result;

    switch (phy_status)
    {
        case 0x0141: /* Marvell */
        {
            /* This code assumes we are using a Marvell Gigabit PHY. All the
                speed information can be read from register 17 in one go. Somebody
                using a different PHY will need to handle it above in the board
                specific area */
            phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, 17);
            if (phy_status < 0)
                return result;

            /* If the resolve bit 11 isn't set, see if autoneg is turned off
                (bit 12, reg 0). The resolve bit doesn't get set properly when
                autoneg is off, so force it */
            if ((phy_status & (1<<11)) == 0)
            {
                bdk_mdio_phy_reg_control_t control;
                int phy_c = bdk_mdio_read(node, mdio_bus, mdio_addr, BDK_MDIO_PHY_REG_CONTROL);
                if (phy_c < 0)
                    return result;
                control.u16 = phy_c;
                if (control.s.autoneg_enable == 0)
                    phy_status |= 1<<11;
            }

            /* Only return a link if the PHY has finished auto negotiation
                and set the resolved bit (bit 11) */
            if (phy_status & (1<<11))
            {
                result.s.up = 1;
                result.s.full_duplex = ((phy_status>>13)&1);
                switch ((phy_status>>14)&3)
                {
                    case 0: /* 10 Mbps */
                        result.s.speed = 10;
                        break;
                    case 1: /* 100 Mbps */
                        result.s.speed = 100;
                        break;
                    case 2: /* 1 Gbps */
                        result.s.speed = 1000;
                        break;
                    case 3: /* Illegal */
                        result.u64 = 0;
                        break;
                }
            }
            break;
        }
        case 0x0022: /* Kendin */
        {
            /* Register 13h - Digital PMA/PCS Status */
            phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, 0x13);
            if (phy_status & 4) /* 1 Gbps, full duplex */
            {
                result.s.up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 1000;
            }
            else if (phy_status & 1) /* 100 Mbs, full duplex */
            {
                result.s.up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 100;
            }
            break;
        }
        case 0x0007: /* Vitesse */
        {
            /* Auxiliary Control and Status, Address 28 (0x1C) */
            phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, 0x1c);
            result.s.full_duplex = (phy_status>>5)&1;
            switch ((phy_status>>3) & 3)
            {
                case 0:
                    result.s.speed = 10;
                    result.s.up = 1;
                    break;
                case 1:
                    result.s.speed = 100;
                    result.s.up = 1;
                    break;
                default:
                    result.s.speed = 1000;
                    break;
            }
            phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, 0x01);
            result.s.up = (phy_status>>2)&1;
            break;
        }
        default: /* Treat like Broadcom */
        {
            /* Below we are going to read SMI/MDIO register 0x19 which works
                on Broadcom parts */
            phy_status = bdk_mdio_read(node, mdio_bus, mdio_addr, 0x19);
            if (phy_status < 0)
                return result;

            switch ((phy_status>>8) & 0x7)
            {
                case 0:
                    result.u64 = 0;
                    break;
                case 1:
                    result.s.up = 1;
                    result.s.full_duplex = 0;
                    result.s.speed = 10;
                    break;
                case 2:
                    result.s.up = 1;
                    result.s.full_duplex = 1;
                    result.s.speed = 10;
                    break;
                case 3:
                    result.s.up = 1;
                    result.s.full_duplex = 0;
                    result.s.speed = 100;
                    break;
                case 4:
                    result.s.up = 1;
                    result.s.full_duplex = 1;
                    result.s.speed = 100;
                    break;
                case 5:
                    result.s.up = 1;
                    result.s.full_duplex = 1;
                    result.s.speed = 100;
                    break;
                case 6:
                    result.s.up = 1;
                    result.s.full_duplex = 0;
                    result.s.speed = 1000;
                    break;
                case 7:
                    result.s.up = 1;
                    result.s.full_duplex = 1;
                    result.s.speed = 1000;
                    break;
            }
            break;
        }
    }

    /* If link is down, return all fields as zero. */
    if (!result.s.up)
        result.u64 = 0;

    return result;
}


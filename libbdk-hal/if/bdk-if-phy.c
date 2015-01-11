#include <bdk.h>

bdk_if_link_t __bdk_if_phy_get(int phy_addr)
{
    int node = phy_addr >> 24;
    int mdio_bus = (phy_addr >> 8) & 0xff;
    int mdio_addr = phy_addr & 0xff;
    int phy_status;
    bdk_if_link_t result;
    result.u64 = 0;

    /* PHY address of -1 menas there is no PHY and we should have never
        gotten here */
    if (phy_addr < 0)
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


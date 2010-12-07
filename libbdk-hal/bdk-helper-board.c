#include <bdk.h>

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
                                   bdk_helper_link_info_t link_info)
{

    /* Set the flow control settings based on link_flags */
    if ((link_flags & set_phy_link_flags_flow_control_mask) != set_phy_link_flags_flow_control_dont_touch)
    {
        bdk_mdio_phy_reg_autoneg_adver_t reg_autoneg_adver;
        reg_autoneg_adver.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER);
        reg_autoneg_adver.s.asymmetric_pause = (link_flags & set_phy_link_flags_flow_control_mask) == set_phy_link_flags_flow_control_enable;
        reg_autoneg_adver.s.pause = (link_flags & set_phy_link_flags_flow_control_mask) == set_phy_link_flags_flow_control_enable;
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER, reg_autoneg_adver.u16);
    }

    /* If speed isn't set and autoneg is on advertise all supported modes */
    if ((link_flags & set_phy_link_flags_autoneg) && (link_info.s.speed == 0))
    {
        bdk_mdio_phy_reg_control_t reg_control;
        bdk_mdio_phy_reg_status_t reg_status;
        bdk_mdio_phy_reg_autoneg_adver_t reg_autoneg_adver;
        bdk_mdio_phy_reg_extended_status_t reg_extended_status;
        bdk_mdio_phy_reg_control_1000_t reg_control_1000;

        reg_status.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_STATUS);
        reg_autoneg_adver.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER);
        reg_autoneg_adver.s.advert_100base_t4 = reg_status.s.capable_100base_t4;
        reg_autoneg_adver.s.advert_10base_tx_full = reg_status.s.capable_10_full;
        reg_autoneg_adver.s.advert_10base_tx_half = reg_status.s.capable_10_half;
        reg_autoneg_adver.s.advert_100base_tx_full = reg_status.s.capable_100base_x_full;
        reg_autoneg_adver.s.advert_100base_tx_half = reg_status.s.capable_100base_x_half;
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER, reg_autoneg_adver.u16);
        if (reg_status.s.capable_extended_status)
        {
            reg_extended_status.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_EXTENDED_STATUS);
            reg_control_1000.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL_1000);
            reg_control_1000.s.advert_1000base_t_full = reg_extended_status.s.capable_1000base_t_full;
            reg_control_1000.s.advert_1000base_t_half = reg_extended_status.s.capable_1000base_t_half;
            bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL_1000, reg_control_1000.u16);
        }
        reg_control.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL);
        reg_control.s.autoneg_enable = 1;
        reg_control.s.restart_autoneg = 1;
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL, reg_control.u16);
    }
    else if ((link_flags & set_phy_link_flags_autoneg))
    {
        bdk_mdio_phy_reg_control_t reg_control;
        bdk_mdio_phy_reg_status_t reg_status;
        bdk_mdio_phy_reg_autoneg_adver_t reg_autoneg_adver;
        bdk_mdio_phy_reg_extended_status_t reg_extended_status;
        bdk_mdio_phy_reg_control_1000_t reg_control_1000;

        reg_status.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_STATUS);
        reg_autoneg_adver.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER);
        reg_autoneg_adver.s.advert_100base_t4 = 0;
        reg_autoneg_adver.s.advert_10base_tx_full = 0;
        reg_autoneg_adver.s.advert_10base_tx_half = 0;
        reg_autoneg_adver.s.advert_100base_tx_full = 0;
        reg_autoneg_adver.s.advert_100base_tx_half = 0;
        if (reg_status.s.capable_extended_status)
        {
            reg_extended_status.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_EXTENDED_STATUS);
            reg_control_1000.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL_1000);
            reg_control_1000.s.advert_1000base_t_full = 0;
            reg_control_1000.s.advert_1000base_t_half = 0;
        }
        switch (link_info.s.speed)
        {
            case 10:
                reg_autoneg_adver.s.advert_10base_tx_full = link_info.s.full_duplex;
                reg_autoneg_adver.s.advert_10base_tx_half = !link_info.s.full_duplex;
                break;
            case 100:
                reg_autoneg_adver.s.advert_100base_tx_full = link_info.s.full_duplex;
                reg_autoneg_adver.s.advert_100base_tx_half = !link_info.s.full_duplex;
                break;
            case 1000:
                reg_control_1000.s.advert_1000base_t_full = link_info.s.full_duplex;
                reg_control_1000.s.advert_1000base_t_half = !link_info.s.full_duplex;
                break;
        }
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_AUTONEG_ADVER, reg_autoneg_adver.u16);
        if (reg_status.s.capable_extended_status)
            bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL_1000, reg_control_1000.u16);
        reg_control.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL);
        reg_control.s.autoneg_enable = 1;
        reg_control.s.restart_autoneg = 1;
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL, reg_control.u16);
    }
    else
    {
        bdk_mdio_phy_reg_control_t reg_control;
        reg_control.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL);
        reg_control.s.autoneg_enable = 0;
        reg_control.s.restart_autoneg = 1;
        reg_control.s.duplex = link_info.s.full_duplex;
        if (link_info.s.speed == 1000)
        {
            reg_control.s.speed_msb = 1;
            reg_control.s.speed_lsb = 0;
        }
        else if (link_info.s.speed == 100)
        {
            reg_control.s.speed_msb = 0;
            reg_control.s.speed_lsb = 1;
        }
        else if (link_info.s.speed == 10)
        {
            reg_control.s.speed_msb = 0;
            reg_control.s.speed_lsb = 0;
        }
        bdk_mdio_write(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL, reg_control.u16);
    }
    return 0;
}

bdk_helper_link_info_t bdk_helper_board_link_get_phy(int phy_addr)
{
    int phy_status;
    int is_broadcom_phy;
    bdk_helper_link_info_t result;
    result.u64 = 0;

    if (phy_addr < 0)
        return result;

    if (bdk_is_simulation())
    {
        result.s.link_up = 1;
        result.s.full_duplex = 1;
        result.s.speed = 1000;
        return result;
    }

    phy_status = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_ID1);
    if (phy_status < 0)
        return result;

    /* Assume PHYs with OUI not equal to Marvell should take the Broadcom path */
    is_broadcom_phy = (phy_status != 0x0141);

    if (is_broadcom_phy)
    {
        /* Below we are going to read SMI/MDIO register 0x19 which works
            on Broadcom parts */
        phy_status = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, 0x19);
        if (phy_status < 0)
            return result;

        switch ((phy_status>>8) & 0x7)
        {
            case 0:
                result.u64 = 0;
                break;
            case 1:
                result.s.link_up = 1;
                result.s.full_duplex = 0;
                result.s.speed = 10;
                break;
            case 2:
                result.s.link_up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 10;
                break;
            case 3:
                result.s.link_up = 1;
                result.s.full_duplex = 0;
                result.s.speed = 100;
                break;
            case 4:
                result.s.link_up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 100;
                break;
            case 5:
                result.s.link_up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 100;
                break;
            case 6:
                result.s.link_up = 1;
                result.s.full_duplex = 0;
                result.s.speed = 1000;
                break;
            case 7:
                result.s.link_up = 1;
                result.s.full_duplex = 1;
                result.s.speed = 1000;
                break;
        }
    }
    else
    {
        /* This code assumes we are using a Marvell Gigabit PHY. All the
            speed information can be read from register 17 in one go. Somebody
            using a different PHY will need to handle it above in the board
            specific area */
        phy_status = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, 17);
        if (phy_status < 0)
            return result;

        /* If the resolve bit 11 isn't set, see if autoneg is turned off
            (bit 12, reg 0). The resolve bit doesn't get set properly when
            autoneg is off, so force it */
        if ((phy_status & (1<<11)) == 0)
        {
            bdk_mdio_phy_reg_control_t control;
            control.u16 = bdk_mdio_read(phy_addr >> 8, phy_addr & 0xff, BDK_MDIO_PHY_REG_CONTROL);
            if (control.s.autoneg_enable == 0)
                phy_status |= 1<<11;
        }

        /* Only return a link if the PHY has finished auto negotiation
            and set the resolved bit (bit 11) */
        if (phy_status & (1<<11))
        {
            result.s.link_up = 1;
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
    }

    /* If link is down, return all fields as zero. */
    if (!result.s.link_up)
        result.u64 = 0;

    return result;
}


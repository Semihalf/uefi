-- Configure the BDK for a evb7000 board.
print("Configuring for the EVB7000")
local bit64 = require("bit64")

local set_config = octeon.c.bdk_config_set
local node = 0

--
-- Setup Vitesse PHYs
--
local mdio_bus = 1
for phy_addr=4,8,4 do
    -- Select "G" registers
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0x10)
    -- Reg 19G, bit 15:14
    -- 0 = SGMII
    -- 1 = QSGMII
    local reg19 = octeon.c.bdk_mdio_read(node, mdio_bus, phy_addr, 19)
    local reg18
    if false then
        -- QSGMII
        reg19 = bit64.binsert(reg19, 1, 14, 15)
        reg18 = 0x80f0
    else
        -- SGMII
        reg19 = bit64.binsert(reg19, 0, 14, 15)
        reg18 = 0x80e0
    end
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 19, reg19)
    -- Write 18G, change all 4 ports
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 18, reg18)
    -- Select main registers
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 31, 0)
    -- Reg23, 10:8 Select copper
    local reg23 = octeon.c.bdk_mdio_read(node, mdio_bus, phy_addr, 23)
    reg23 = bit64.binsert(23, 0, 8, 10)
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 23, reg23)
    -- Reg0, Reset
    local reg0 = octeon.c.bdk_mdio_read(node, mdio_bus, phy_addr, 0)
    reg0 = bit64.binsert(reg0, 1, 15, 15)
    octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 0, reg0)
    -- Near end loopback
    if false then
    reg0 = octeon.c.bdk_mdio_read(node, mdio_bus, phy_addr, 0)
        reg0 = bit64.binsert(reg0, 1, 14, 14)
        octeon.c.bdk_mdio_write(node, mdio_bus, phy_addr, 0, reg0)
    end
end

-- RGMII PHY address is 3, on SMI0
set_config(octeon.CONFIG_PHY_MGMT_PORT0, 3)

-- (Q)SGMII PHY address for interface 0 are 4-7, on SMI1
--set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x1000)
--set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x1000)
--set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x1000)
--set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x1000)
set_config(octeon.CONFIG_PHY_IF0_PORT0, 256 + 4)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 256 + 5)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 256 + 6)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 256 + 7)

-- (Q)SGMII PHY address for interface 1 are 8-11, on SMI1
--set_config(octeon.CONFIG_PHY_IF1_PORT0, 0x1000)
--set_config(octeon.CONFIG_PHY_IF1_PORT1, 0x1000)
--set_config(octeon.CONFIG_PHY_IF1_PORT2, 0x1000)
--set_config(octeon.CONFIG_PHY_IF1_PORT3, 0x1000)
set_config(octeon.CONFIG_PHY_IF1_PORT0, 256 + 8)
set_config(octeon.CONFIG_PHY_IF1_PORT1, 256 + 9)
set_config(octeon.CONFIG_PHY_IF1_PORT2, 256 + 10)
set_config(octeon.CONFIG_PHY_IF1_PORT3, 256 + 11)

-- RXAUI PHY address is 18, hex 0x12, on SMI1
-- set_config(octeon.CONFIG_PHY_IF0_PORT0, 256 + 18)

-- TWSI info
-- DDR0 converter: Address 0x31
-- Core converter: Address 0x40
-- DDR0 Rom: Address 0x50
-- EEPROM: Address 0x56
-- QLM Rom: Address 0x57
-- DDR clock control: Address 0x58
-- PNR clock control: Address 0x5b
-- PLL clock control: Address 0x5a


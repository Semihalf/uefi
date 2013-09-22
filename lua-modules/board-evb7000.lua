-- Configure the BDK for a evb7000 board.
print("Configuring for the EVB7000")

local set_config = octeon.c.bdk_config_set

-- RGMII PHY address is 3, on SMI0
set_config(octeon.CONFIG_PHY_MGMT_PORT0, 3)

-- (Q)SGMII PHY address for interface 0 are 4-7, on SMI1
set_config(octeon.CONFIG_PHY_IF0_PORT0, 256 + 4)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 256 + 5)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 256 + 6)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 256 + 7)

-- (Q)SGMII PHY address for interface 1 are 8-11, on SMI1
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


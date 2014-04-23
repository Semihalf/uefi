-- Configure the BDK for a ebb7800 board.
print("Configuring for the EBB7800")

local set_config = octeon.c.bdk_config_set

-- QLM0
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x000 + 1)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x000 + 2)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x000 + 3)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x000 + 4)
-- QLM1
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x100 + 1)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x100 + 2)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x100 + 3)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x100 + 4)
-- QLM2
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x200 + 1)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x200 + 2)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x200 + 3)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x200 + 4)
-- QLM3
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x300 + 1)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x300 + 2)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x300 + 3)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x300 + 4)
-- QLM4
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x000 + 5)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x000 + 6)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x000 + 7)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x000 + 8)
-- QLM5
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x100 + 5)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x100 + 6)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x100 + 7)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x100 + 8)

-- printf("Configuring QLMs for a sample setup\n");
-- local node = octeon.MASTER_NODE
-- octeon.c.bdk_qlm_set_mode(node, 0, octeon.QLM_MODE_SGMII, 1250, 0)
-- octeon.c.bdk_qlm_set_mode(node, 1, octeon.QLM_MODE_XAUI_1X4, 3125, 0)
-- octeon.c.bdk_qlm_set_mode(node, 2, octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3)
-- octeon.c.bdk_qlm_set_mode(node, 3, octeon.QLM_MODE_PCIE_1X8, 8000, octeon.QLM_MODE_FLAG_GEN3)
-- octeon.c.bdk_qlm_set_mode(node, 4, octeon.QLM_MODE_RXAUI_2X2, 6250, 0)
-- octeon.c.bdk_qlm_set_mode(node, 5, octeon.QLM_MODE_10GR_4X1, 10321, 0)
-- octeon.c.bdk_qlm_set_mode(node, 6, octeon.QLM_MODE_40GR4_1X4, 10321, 0)
-- octeon.c.bdk_qlm_set_mode(node, 7, octeon.QLM_MODE_ILK, 5000, 0)


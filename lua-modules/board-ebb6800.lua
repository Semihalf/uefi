-- Configure the BDK for a ebb6800 board.
print("Configuring for the EBB6800")

-- Configure MDIO mux to connect MGMT port _and_ QLM4 to MDIO 0.
-- Connect just QLM0 to MDIO 1, as only QLM0 has GMX interfaces.
octeon.c.bdk_twsix_write_ia(0, 0x71, 0, 1, 1, 0xf3)
octeon.c.bdk_wait_usec(11000)

local set_config = octeon.c.bdk_config_set

-- Mgmt port PHY address
set_config(octeon.CONFIG_PHY_MGMT_PORT0, 0x000 + 6)

-- This is SGMII on QLM0
set_config(octeon.CONFIG_PHY_IF0_PORT0, 0x100 + 1)
set_config(octeon.CONFIG_PHY_IF0_PORT1, 0x100 + 2)
set_config(octeon.CONFIG_PHY_IF0_PORT2, 0x100 + 3)
set_config(octeon.CONFIG_PHY_IF0_PORT3, 0x100 + 4)

-- QLM1 doesn't do SGMII, so no PHY addresses

-- This is SGMII on QLM2
set_config(octeon.CONFIG_PHY_IF2_PORT0, 0x200 + 1)
set_config(octeon.CONFIG_PHY_IF2_PORT1, 0x200 + 2)
set_config(octeon.CONFIG_PHY_IF2_PORT2, 0x200 + 3)
set_config(octeon.CONFIG_PHY_IF2_PORT3, 0x200 + 4)

-- This is SGMII on QLM3
set_config(octeon.CONFIG_PHY_IF3_PORT0, 0x300 + 1)
set_config(octeon.CONFIG_PHY_IF3_PORT1, 0x300 + 2)
set_config(octeon.CONFIG_PHY_IF3_PORT2, 0x300 + 3)
set_config(octeon.CONFIG_PHY_IF3_PORT3, 0x300 + 4)

-- This is SGMII on QLM4
set_config(octeon.CONFIG_PHY_IF4_PORT0, 0x000 + 1)
set_config(octeon.CONFIG_PHY_IF4_PORT1, 0x000 + 2)
set_config(octeon.CONFIG_PHY_IF4_PORT2, 0x000 + 3)
set_config(octeon.CONFIG_PHY_IF4_PORT3, 0x000 + 4)

-- These QLM tuning parameters are specific to the ebb6800
-- using Cavium QLM cables. They should be removed or modified
-- for use on customer boards. This simply serves as a good example
-- of where to put tuning parameters.
for qlm=0,4 do
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "biasdrv_hs_ls_byp", 12);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "biasdrv_hf_byp", 12);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "biasdrv_lf_ls_byp", 12);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "biasdrv_lf_byp", 12);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "tcoeff_hf_byp", 15);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "tcoeff_hf_ls_byp", 15);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "tcoeff_lf_ls_byp", 15);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "tcoeff_lf_byp", 15);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "rx_cap_gen2", 0);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "rx_eq_gen2", 11);
    octeon.c.bdk_qlm_jtag_set(qlm, -1, "serdes_tx_byp", 1);
end

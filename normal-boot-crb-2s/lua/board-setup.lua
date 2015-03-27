-- Configure the BDK for a crb_1s board.
print("Configuring for the CN88XX-CRB-2S")

local set_config = cavium.c.bdk_config_set

-- BGX0 (QLM0) is SFP using Local Node, TWSI3, address 0x56, 1 byte internal address
-- Bits[31:24]: Node number, 0xff is same as network device
-- Bits[23:16]: TWSI internal address width in bytes (1)
-- Bits[15:12]: TWSI (2)
-- Bits[11:8]: TWSI bus number (3)
-- Bits[7:0]: TWSI address (0x56)
set_config(cavium.CONFIG_PHY_IF0_PORT0, 0xff012356)

-- Report boot OK to BMC
cavium.csr.MIO_TWSX_SW_TWSI(2).data = 0x80
cavium.csr.MIO_TWSX_SW_TWSI(2).v = 1

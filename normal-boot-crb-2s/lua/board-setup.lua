-- Configure the BDK for a crb_1s board.
print("Configuring for the CN88XX-CRB-2S")

local set_config = cavium.c.bdk_config_set

-- Report boot OK to BMC
cavium.csr.MIO_TWSX_SW_TWSI(2).data = 0x80
cavium.csr.MIO_TWSX_SW_TWSI(2).v = 1

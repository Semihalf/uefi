--
-- BDK Example Lua script
--
-- This script shows an example of how to try different DDR3 speed on
-- a EBB6300 using a remote connection. Although this example
-- only changes the DDR3 clock speeds, other configuration parameters
-- could easily be changed.
--
local BOARD_NAME = "ebb6300"
local MEMORY_TEST_START = 0x40000000 -- Start at 64MB
local MEMORY_TEST_LENGTH = 0x1000000 -- Length of 16MB

-- It's always good practice to avoid using globals. Use "strict" to
-- remind us if we mistakenly use globals
require("strict")

-- Open the octoen module, which is a remote connection. The environment
-- variable OCTEON_REMOTE_CONSOLE needs to set to the device name of your
-- serial port. "/dev/ttyS0" is likely a good choice.
require("octeon")

-- Make sure the "ddr" module is loaded on the Octeon side
octeon.global.require("ddr")

-- Create a local variable to store a reference to the ddr module. This
-- prevents us from looking it up over RPC constantly.
local ddr = octeon.global.ddr

-- Get the DDR3 config for the EBB6300
print("Getting the DDR3 config for the board \"" .. BOARD_NAME .. '"')
local config = ddr.get_config(BOARD_NAME)

-- Display the starting DDR3 configuration
print("Here is the current DDR3 config:")
ddr.show_config(config)

-- Loop through some clock speeds checking memory
for clock_mhz = 400, 800, 33 do
    local clock_hz = clock_mhz * 1000000
    print("DDR3 clock:", clock_hz)
    config.default_ddr_clock_hz = clock_hz
    ddr.set_config(config)
    ddr.test(MEMORY_TEST_START, MEMORY_TEST_LENGTH)
end


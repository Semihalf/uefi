-- BDK SPI/MPI menu.
-- Displays the GUI interface for accessing SPI/MPI.
require("strict")
require("utils")
require("menu")

local node = 0

local function mpi_init()
    local clock_rate_hz = menu.prompt_number("Clock rate", 1000000, 1, 16000000)
    local cs0 = menu.prompt_yes_no("Configure chip select 0", "y")
    local cs1 = menu.prompt_yes_no("Configure chip select 1", "y")
    local cs2 = menu.prompt_yes_no("Configure chip select 2", "y")
    local cs3 = menu.prompt_yes_no("Configure chip select 3", "y")
    local cs_high = menu.prompt_yes_no("Chip selects are active high", "n")
    local one_wire = menu.prompt_yes_no("Only use SPI_DO (one wire mode)", "n")
    local idle_clock = menu.prompt_yes_no("Clock when idle", "n")
    local idle_low = menu.prompt_yes_no("Clock is low on idle", "n")
    local lsb = menu.prompt_yes_no("Transfer LSB first", "n")

    local flags = 0
    flags = flags + (cs0 and octeon.MPI_FLAGS_ENABLE_CS0 or 0)
    flags = flags + (cs1 and octeon.MPI_FLAGS_ENABLE_CS1 or 0)
    flags = flags + (cs2 and octeon.MPI_FLAGS_ENABLE_CS2 or 0)
    flags = flags + (cs3 and octeon.MPI_FLAGS_ENABLE_CS3 or 0)
    flags = flags + (cs_high and octeon.MPI_FLAGS_CS_ACTIVE_HI or 0)
    flags = flags + (one_wire and octeon.MPI_FLAGS_ONE_WIRE or 0)
    flags = flags + (idle_clock and octeon.MPI_FLAGS_IDLE_CLOCKS or 0)
    flags = flags + (idle_low and octeon.MPI_FLAGS_IDLE_LOW or 0)
    flags = flags + (lsb and octeon.MPI_FLAGS_LSB_FIRST or 0)

    local result = octeon.c.bdk_mpi_initialize(node, clock_rate_hz, flags)
    assert(result == 0, "SPI/MPI initialization failed")
end

local function mpi_transfer()
    local chip_select = menu.prompt_number("Chip select", 0, 0, 3)
    local tri_state_shift = menu.prompt_yes_no("Tri-state during shift", "n")
    local tx_bytes = menu.prompt_string("Transmit bytes", "")
    local shift_bytes = menu.prompt_string("Shift bytes", "")

    local result = octeon.c.bdk_mpi_transfer(node, chip_select,
        tri_state_shift, 0, #tx_bytes, tx_bytes, #shift_bytes, shift_bytes)
    assert(result == 0, "SPI/MPI transfer failed")

    if #shift_bytes > 0 then
        print("Shift bytes: %s" % shift_bytes:hex())
    end
end

local m = menu.new("SPI/MPI Menu")

m:item("init", "Initialize", mpi_init)
m:item("tran", "Perform transfer", mpi_transfer)
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end



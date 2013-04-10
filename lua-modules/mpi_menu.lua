-- BDK SPI/MPI menu.
-- Displays the GUI interface for accessing SPI/MPI.
require("strict")
require("utils")
require("menu")
local fileio = require("fileio")
local bit64 = require("bit64")

local node = 0
local init_complete = false

-- Use globals so menu remembers last choice
local chip_select   = 0
local addr_width    = 2     -- Default for EEPROM. Should be 3 for flash
local read_cmd      = 0x03  -- Matches EEPROM, not flash
local write_cmd     = 0x02  -- Matches EEPROM, not flash
local write_enable  = 0x06  -- Matches EEPROM, not flash
local write_disable = 0x04  -- Matches EEPROM, not flash
local read_status   = 0x05  -- Matches EEPROM, not flash
local write_status  = 0x01  -- Matches EEPROM, not flash
local filename      = nil

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
    init_complete = true
end

local function mpi_transfer()
    local chip_select = menu.prompt_number("Chip select", chip_select, 0, 3)
    local tx_count = menu.prompt_number("Transmit bytes", 1, 0, 8)
    local tx_data = menu.prompt_number("Transmit data")
    local rx_count = menu.prompt_number("Receive bytes", 1, 0, 9 - tx_count)

    local result = octeon.c.bdk_mpi_transfer(node, chip_select, 0, tx_count, tx_data, rx_count)
    if rx_count > 0 then
        print("Receive: 0x%x" % result)
    else
        assert(result == 0, "SPI/MPI transfer failed")
    end
end

local function mpi_display()
    chip_select = menu.prompt_number("Chip select", chip_select, 0, 3)
    addr_width = menu.prompt_number("Address width in bytes", addr_width, 1, 4)
    local addr = menu.prompt_number("Address", 0)
    read_cmd = menu.prompt_number("Read command", read_cmd, 0x00, 0xff)
    local count = menu.prompt_number("Bytes to read", 128, 1)

    local cmd = bit64.lshift(read_cmd, addr_width*8) + addr
    local result = octeon.c.bdk_mpi_transfer(node, chip_select, true, addr_width+1, cmd, 0)
    assert(result == 0, "SPI/MPI transfer failed")
    while count > 0 do
        local rx_size = (count > 8) and 8 or count
        result = octeon.c.bdk_mpi_transfer(node, chip_select, rx_size < count, 0, 0, rx_size)
        printf("%08x: %016x\n", addr, result)
        addr = addr + rx_size
        count = count - rx_size
    end
end

local function mpi_read()
    chip_select = menu.prompt_number("Chip select", chip_select, 0, 3)
    addr_width = menu.prompt_number("Address width in bytes", addr_width, 1, 4)
    local addr = menu.prompt_number("Address", 0)
    -- read_cmd = menu.prompt_number("Read command", read_cmd, 0x00, 0xff)
    local count = menu.prompt_number("Bytes to read", 1, 1)
    filename = menu.prompt_string("Save to file", filename)

    local f = fileio.open(filename, "w")

    -- Issue the read command
    local cmd = bit64.lshift(read_cmd, addr_width*8) + addr
    local result = octeon.c.bdk_mpi_transfer(node, chip_select, true, addr_width+1, cmd, 0)
    assert(result == 0, "SPI/MPI transfer failed")

    -- Read the data in a loop
    while count > 0 do
        local rx_size = (count > 8) and 8 or count
        result = octeon.c.bdk_mpi_transfer(node, chip_select, rx_size < count, 0, 0, rx_size)
        for i=1,rx_size do
            local data = bit64.rshift(result, (rx_size - i)*8)
            data = bit64.band(data, 0xff)
            f:write(string.char(data))
        end
        count = count - rx_size
    end
    f:close()
end

local function mpi_write()
    chip_select = menu.prompt_number("Chip select", chip_select, 0, 3)
    addr_width = menu.prompt_number("Address width in bytes", addr_width, 1, 4)
    local addr = menu.prompt_number("Address", 0)
    -- write_cmd = menu.prompt_number("Write command", write_cmd, 0x00, 0xff)
    filename = menu.prompt_string("Read from file", filename)

    -- Read the status register
    local result = octeon.c.bdk_mpi_transfer(node, chip_select, true, 1, read_status, 1)
    assert(bit64.band(result, 1) == 0, "SPI/MPI device stuck in write")

    -- Enable writing
    local result = octeon.c.bdk_mpi_transfer(node, chip_select, true, 1, write_enable, 0)
    assert(result == 0, "SPI/MPI transfer failed")

    local f = fileio.open(filename, "r")

    -- Issue the write command without any data. Leave CS selected
    local cmd = bit64.lshift(write_cmd, addr_width*8) + addr
    result = octeon.c.bdk_mpi_transfer(node, chip_select, true, addr_width+1, cmd, 0)
    assert(result == 0, "SPI/MPI transfer failed")

    -- Write the data in a loop
    repeat
        local data = f:read(8)
        if data then
            local tx_data = 0
            for i=1,#data do
                tx_data = bit64.lshift(tx_data, 8)
                tx_data = tx_data + data:byte(i)
            end
            result = octeon.c.bdk_mpi_transfer(node, chip_select, true, #data, tx_data, 0)
            assert(result == 0, "SPI/MPI transfer failed")
        end
    until data == nil
    f:close()

    -- Read the status register, waiting for write complete
    repeat
        local result = octeon.c.bdk_mpi_transfer(node, chip_select, true, 1, read_status, 1)
        local busy = bit64.band(result, 1)
    until busy == 0

    -- Disable writing
    result = octeon.c.bdk_mpi_transfer(node, chip_select, true, 1, write_disable, 0)
    assert(result == 0, "SPI/MPI transfer failed")
end

local m = menu.new("SPI/MPI Menu")
repeat
    m:item("init", "Initialize", mpi_init)
    if init_complete then
        m:item("tran", "Perform a single transfer", mpi_transfer)
        m:item("dis", "Bulk read and hex display", mpi_display)
        m:item("read", "Bulk read", mpi_read)
        m:item("write", "Bulk write", mpi_write)
        m:item("quit", "Main menu")
    end
until m:show() == "quit"


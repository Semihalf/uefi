-- BDK SPI/MPI menu.
-- Displays the GUI interface for accessing SPI/MPI.
require("strict")
require("utils")
require("menu")
local fileio = require("fileio")
local bit64 = require("bit64")

local node = octeon.MASTER_NODE
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

local function mpi_view(filename)
    local offset = menu.prompt_number("Starting offset")
    local length = menu.prompt_number("Bytes to display")
    fileio.hexdump(filename, offset, length)
end

local function mpi_write(filename)
    local source = menu.prompt_filename("Enter source filename")
    local offset = menu.prompt_number("Starting offset")
    fileio.copy(source, nil, filename, offset)
end

local function mpi_device()
    -- MPI/SPI filenames are of the format:
    -- /dev/mpi/cs0-[hl],[12]wire,idle-[rhl]-[ml]sb-##bit-<freq>
    -- cs0 = Chip select to use [0-3]
    -- [hl] = Chip select is active High or Low
    -- [12] = Use 1 wire half duplex or 2 wire full duplex
    -- [rhl] = Should the clock continue to Run when idle, go High, or go Low
    -- [ml] = MSB or LSB first
    -- ## = Address width (16, 24, or 32)
    -- <freq> = Clock frequency in Mhz
    local m = menu.new("SPI/MPI Device Menu")
    local chip_sel = 0
    local chip_hi = false
    local wire = 2
    local idle = "h"
    local msb = true
    local address_width = 16
    local freq = 10
    repeat
        m:item("cs", "Select chip select (CS%d)" % chip_sel,
               function()
                   chip_sel = menu.prompt_number("Chip select to use", chip_sel, 0, 3)
               end)
        m:item("hl", "Select chip select type (Active %s)" % (chip_hi and "high" or "low"),
               function()
                   chip_hi = menu.prompt_yes_no("Is the chip select active high", chip_hi)
               end)
        m:item("12", "Use one or two data wires (%d wire)" % wire,
               function()
                   wire = menu.prompt_number("Use 1 wire or 2 (in + out)", wire, 1, 2)
               end)
        m:item("rhl", "Idle clock type (%s)" % (((idle == "r") and "Run") or ((idle == "h") and "Hi" or "Low")),
               function()
                   local run = menu.prompt_yes_no("Should the clock run when idle", idle == "r")
                   if run then
                       idle = "r"
                   else
                       if menu.prompt_yes_no("Should the clock be high when idle", idle == "h") then
                           idle = "h"
                       else
                           idle = "l"
                       end
                   end
               end)
        m:item("ml", "Endian order (%s)" % (msb and "MSB" or "LSB"),
               function()
                   msb = menu.prompt_yes_no("Shift bits MSB first", msb)
               end)
        m:item("add", "Address width (%d)" % address_width,
               function()
                   address_width = menu.prompt_number("Address width in bits", address_width, 8, 32)
               end)
        m:item("freq", "Frequency (%d MHz)" % freq,
               function()
                   freq = menu.prompt_number("Frequency in Mhz", freq, 1, 50)
               end)

        local filename = "/dev/mpi/cs%d-%s,%dwire,idle-%s,%ssb,%dbit,%d" %
            {chip_sel,
             chip_hi and "h" or "l",
             wire, idle,
             msb and "m" or "l",
             address_width,
             freq}
        m:item("read", "View device contents", mpi_view, filename)
        m:item("write", "Write to device", mpi_write, filename)
        m:item("quit", "Main menu")
    until m:show() == "quit"
end

local m = menu.new("SPI/MPI Menu")
repeat
    m:item("dev", "Access an EEPROM or NOR flash", mpi_device)
    m:item("init", "Initialize", mpi_init)
    if init_complete then
        m:item("tran", "Perform a single transfer", mpi_transfer)
    end
    m:item("quit", "Main menu")
until m:show() == "quit"


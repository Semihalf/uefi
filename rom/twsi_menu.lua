
-- BDK DDR menu

require("strict")
require("utils")
require("menu")

local function twsi_init(twsi_bus)
    -- Slow down the TWSI clock, as some boards (Thunder) seem to need
    -- it slower than the default, especially when a spi4000 is
    -- connected.
    octeon.csr.MIO_TWSX_SW_TWSI(twsi_bus).op = 0x6
    octeon.csr.MIO_TWSX_SW_TWSI(twsi_bus).eop_ia = 0x3
    octeon.csr.MIO_TWSX_SW_TWSI(twsi_bus).d = 0x78
    octeon.csr.MIO_TWSX_SW_TWSI(twsi_bus).v = 1
end

local function twsi_scan(twsi_bus)
    printf("TWSI%d: Scanning bus...\n", twsi_bus)
    for dev_addr = 0, 127 do
        local data = octeon.c.bdk_twsix_read_ia(twsi_bus, dev_addr, 0, 1, 0)
        if data >= 0 then
            printf("TWSI%d: Address %3d (0x%02x) responded\n", twsi_bus, dev_addr, dev_addr)
        end
    end
end

local function twsi_read(twsi_bus)
    local dev_addr = menu.prompt_number("Device address", nil, 0, 127)
    local ia_width = menu.prompt_number("Internal address width", nil, 0, 2)
    local ia_address = 0
    if ia_width > 0 then
        ia_address = menu.prompt_number("Internal address")
    end
    local num_bytes = menu.prompt_number("Number of bytes to read", nil, 1, 4)
    local result = octeon.c.bdk_twsix_read_ia(twsi_bus, dev_addr, ia_address, num_bytes, ia_width)
    assert(result ~= -1, "TWSI read failed")
    printf("Result: %d (0x%x)\n", result, result)
end

local function twsi_write(twsi_bus)
    local dev_addr = menu.prompt_number("Device address", nil, 0, 127)
    local ia_width = menu.prompt_number("Internal address width", nil, 0, 2)
    local ia_address = 0
    if ia_width > 0 then
        ia_address = menu.prompt_number("Internal address")
    end
    local num_bytes = menu.prompt_number("Number of bytes to write", nil, 1, 4)
    local data = menu.prompt_number("Data to write")
    local result = octeon.c.bdk_twsix_write_ia(twsi_bus, dev_addr, ia_address, num_bytes, ia_width, data)
    assert(result ~= -1, "TWSI write failed")
end

local function twsi_submenu(twsi_bus)
    local m = menu.new("TWSI Menu - Bus " .. twsi_bus)
    m:item("init", "Initialize bus", twsi_init, twsi_bus)
    m:item("scan", "Scan bus", twsi_scan, twsi_bus)
    m:item("read", "Read", twsi_read, twsi_bus)
    m:item("write", "Write", twsi_write, twsi_bus)
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end


local m = menu.new("TWSI Menu")

-- Build a list of TWSI busses
local twsi_busses = 2
for bus = 0, twsi_busses-1 do
    m:item("bus" .. bus, "TWSI bus " .. bus, twsi_submenu, bus)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end



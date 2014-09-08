-- BDK SATA menu.
-- Displays the GUI interface for accessing SATA.
require("strict")
require("utils")
require("fileio")
require("menu")

local option = ""
local node = cavium.MASTER_NODE
local sata = 0
local PATTERNS = {0x00, 0xff, 0x55, 0xaa}

--
-- Create a "length" sector string for the given pattern. The string
-- length will be 512 * length.
--
local function get_pattern(pattern, length)
    local pat = string.char(pattern)
    pat = pat:rep(length * 512)
    return pat
end

--
-- A number of palces below need to ask the user for an area to work on and
-- open a file at that location. This function consolidates this
--
local function get_file_data(file_mode)
    local filename = "/dev/sata/" .. tostring(sata)
    local offset = menu.prompt_number("Starting sector")
    local length = menu.prompt_number("Number of sectors", 1)

    local handle = assert(cavium.devopen(filename, file_mode))
    local loc = handle:seek("set", offset * 512)
    if not loc then
        handle:close()
        error('Seek failed in file "' .. filename ..'"')
    end

    return handle, offset, length
end

--
-- Write a fixed pattern to SATA
--
local function write_pattern(pattern)
    local handle, offset, length = get_file_data("w")
    handle:write(get_pattern(pattern, length))
    handle:close()
end

--
-- Read SATA and verify the data matches the pattern
--
local function read_pattern(pattern)
    local handle, offset, length = get_file_data("r")
    local correct = get_pattern(pattern, length)
    local data = handle:read(length * 512)
    handle:close()
    assert(correct == data, "SATA data doesn't match pattern")
end

--
-- Put the menu on the screen
--
while (option ~= "quit") do
    local m = menu.new("SATA Menu")

    m:item("port", "Select SATA port (Currently %d)" % sata, function()
        local num_sata = cavium.c.bdk_sata_get_controllers(node)
        sata = menu.prompt_number("SATA port to use", sata, 0, num_sata - 1)
    end)

    m:item("id", "Perform an identify disk", function()
        local size = cavium.c.bdk_sata_identify(node, sata, 0)
    end)

    m:item("hex", "Hex display", function()
        local offset = menu.prompt_number("Starting sector")
        local length = menu.prompt_number("Number of sectors", 1)
        local filename = "/dev/sata/" .. tostring(sata)
        fileio.hexdump(filename, offset * 512, length * 512)
    end)

    for i,p in ipairs(PATTERNS) do
        m:item("w" .. tostring(p), "Write pattern 0x%02x" % p, write_pattern, p)
        m:item("r" .. tostring(p), "Read  pattern 0x%02x" % p, read_pattern, p)
    end

    m:item("quit", "Main menu")
    option = m:show()
end


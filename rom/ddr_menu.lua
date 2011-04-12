
-- BDK DDR menu

require("strict")
require("utils")
require("menu")
require("ddr")
require("fileio")

-- List of board strings that can be passed to ddr.set_config()
local BOARD_CHOICES = {
    "ebb6300",
    "ebb6800",
}

local m = menu.new("DDR Menu")

-- Build a list of choice for each board
for _,board in ipairs(BOARD_CHOICES) do
    local text = "Initialize DDR for the \"%s\"" % board
    m:item(board, text, ddr.set_config, board)
end

-- Add more options for testing DDR
m:item("show", "Dump the current DRAM config", ddr.show_config)

m:item("save", "Save the current DRAM config", function()
    local filename = menu.prompt_string("Filename")
    ddr.show_config(nil, filename)
end)

m:item("load", "Load a DRAM config", function()
    local filename = menu.prompt_string("Filename")
    local handle = fileio.open(filename, "r")
    local data = handle:read("*a")
    handle:close()
    -- Some transfers (xmodem) get extra junk at the end which Lua doesn't like
    data = data:gsub("\26", "")
    declareGlobal("config", ddr.get_config())
    local f = assert(loadstring(data))
    f()
    ddr.set_config(config)
end)

m:item("64MB", "Test DDR from 64MB to 128MB", ddr.test, 0x4000000, 0x4000000)

m:item("test", "Test DDR over a specified range", function()
    -- Test a variable range
    local start_address = menu.prompt_number("Physical byte address to start memory test at:")
    if start_address >= 0 then
        local length = menu.prompt_number("Length of region(in bytes):")
        if length > 0 then
            ddr.test(start_address, length)
        else
            print("Invalid length")
        end
    else
        print("Invalid start address")
    end
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end



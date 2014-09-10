-- BDK USB menu.
-- Displays the GUI interface for configuring and accessing USB.
require("strict")
require("utils")
require("menu")

local node = cavium.MASTER_NODE
local usb_port = 0

local function usb_init(usb_port)
    local clock_type = 0
    local status = cavium.c.bdk_usb_intialize(node, usb_port, clock_type)
    assert(status == 0, "Failed to initialize the USB port")
end

local function usb_test(usb_port, test)
    assert(cavium.c.bdk_usb_test_mode(node, usb_port, test) == 0, "Failed to set USB test mode")
end

repeat
    local m = menu.new("USB Menu")

    m:item("port", "Select USB port (Currently %d)" % usb_port,
        function()
            usb_port = menu.prompt_number("USB port", usb_port, 0, 1)
        end)

    m:item("init", "Initialize the port", usb_init, usb_port)
    local test = 0
    while true do
        local name = cavium.c.bdk_usb_get_test_mode_string(test)
        if name == nil then
            break
        end
        m:item("test" .. tostring(test), name, usb_test, usb_port, test)
        test = test + 1
    end

    m:item("quit", "Main menu")
until m:show() == "quit"


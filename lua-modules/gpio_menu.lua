-- BDK GPIO menu.
-- Displays the GUI interface for configuring and accessing GPIO pins.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--
require("strict")
require("utils")
require("menu")
local bit64 = require("bit64")

local function gpio_config()
    local gpio = menu.prompt_number("GPIO number")
    local is_output = menu.prompt_yes_no("Configure as output")
    local value
    if is_output then
        value = menu.prompt_number("GPIO state", nil, 0, 1)
    else
        value = 0
    end
    assert(cavium.c.bdk_gpio_initialize(menu.node, gpio, is_output, value) == 0, "GPIO configure failed")
end

local function gpio_read()
    local gpio = menu.prompt_number("GPIO number")
    local state = cavium.c.bdk_gpio_read(menu.node)
    if bit64.btest(state, bit64.lshift(1, gpio)) then
        printf("GPIO %d: 1\n", gpio)
    else
        printf("GPIO %d: 0\n", gpio)
    end
end

local m = menu.new("GPIO Menu")

m:item_node() -- Adds option to choose the node number
m:item("cfg", "Configure a GPIO", gpio_config)
m:item("read", "Read GPIO state", gpio_read)
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


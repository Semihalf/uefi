
-- BDK GPIO menu

require("strict")
require("utils")
require("menu")

local function gpio_config()
    local gpio = menu.prompt_number("GPIO number")
    local is_output = menu.prompt_string("Configure as output(y/n)")
    assert((is_output == "y") or (is_output == "n"), "Expected y or n")
    local value
    if is_output == "y" then
        is_output = 1
        value = menu.prompt_number("GPIO state (0/1)")
        assert((value == 0) or (value == 1), "Expected 0 or 1")
    else
        is_output = 0
        value = 0
    end
    assert(octeon.c.bdk_gpio_initialize(gpio, is_output, value) == 0, "GPIO configure failed")
end

local function gpio_read()
    local gpio = menu.prompt_number("GPIO number")
    local state = octeon.c.bdk_gpio_read()
    if bit64.btest(state, bit64.lshift(1, gpio)) then
        printf("GPIO %d: 1\n", gpio)
    else
        printf("GPIO %d: 0\n", gpio)
    end
end

local m = menu.new("GPIO Menu")

m:item("cfg", "Configure a GPIO", gpio_config)
m:item("read", "Read GPIO state", gpio_read)
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


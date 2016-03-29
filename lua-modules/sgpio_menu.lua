-- BDK SGPIO menu.
-- Displays the GUI interface for running patterns on SGPIO interface
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2016 Cavium Inc.
--
require("strict")
require("utils")
require("menu")

local function sgpio_led_set(led_type)
    local drive = menu.prompt_number("SGPIO drive number (16=all)", 0, 0, 16)

    local led_state = cavium.SGPIO_STATIC_ON
    local choice = menu.prompt_string("Enter LED state (o=On, -=Off, b=Blink)", "o")
    if choice == 'o' or choice == '1' then
        led_state = cavium.SGPIO_STATIC_ON
    elseif choice == '-' or choice == '0' then
        led_state = cavium.SGPIO_STATIC_OFF
    elseif choice == 'b' or choice == '*' then
        led_state = cavium.SGPIO_BLINK
    end

    if drive == 16 then
        for i = 0,15 do
            cavium.c.bdk_sgpio_set_led_state(menu.node, i, led_type, led_state)
        end
    else
        cavium.c.bdk_sgpio_set_led_state(menu.node, drive, led_type, led_state)
    end
end

local function sgpio_led_status_line(led_type)
    local s

    if led_type == cavium.SGPIO_LED_ACT then
        s = 'ACTIVITY'
    elseif led_type == cavium.SGPIO_LED_LOC then
        s = 'LOCATE  '
    elseif led_type == cavium.SGPIO_LED_ERR then
        s = 'ERROR   '
    end

    for i = 0,15 do
        if (i % 4) == 0 then
            s = s .. '   '      -- divide into groups of 4 for readability
        end

        local led_state = cavium.c.bdk_sgpio_get_led_state(menu.node, i, led_type)
        if led_state == cavium.SGPIO_STATIC_ON then
            s = s .. '  o'      -- LED is on
        elseif led_state == cavium.SGPIO_BLINK then
            s = s .. '  *'      -- LED is blinking
        else
            s = s .. '  -'      -- LED is off
        end
    end
    return s
end

local function sgpio_configure_controller()
    local sclock    = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SCLOCK, menu.node)
    local sload     = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SLOAD,  menu.node)
    local sdataout0 = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 0)
    local sdataout1 = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 1)
    local sdataout2 = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 2)
    local sdataout3 = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 3)
    local power     = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_PIN_POWER,  menu.node)
    local f_sclock  = cavium.c.bdk_config_get_int(cavium.CONFIG_SGPIO_SCLOCK_FREQ,  menu.node)

    repeat
        local m = menu.new("Configure SGPIO controller")
        m:item("",   "--- CLOCK setting ---")
        m:item("f",  "Set SCLOCK frequency (currently %d Hz)" % f_sclock)
        m:item("",   "")
        m:item("",   "--- GPIO pin settings (-1 == not used or configured) ---")
        m:item("c",  "Set GPIO pin for SCLOCK      (%d)" % sclock)
        m:item("l",  "Set GPIO pin for SLOAD       (%d)" % sload)
        m:item("d0", "Set GPIO pin for SDATAOUT[0] (%d)" % sdataout0)
        m:item("d1", "Set GPIO pin for SDATAOUT[1] (%d)" % sdataout1)
        m:item("d2", "Set GPIO pin for SDATAOUT[2] (%d)" % sdataout2)
        m:item("d3", "Set GPIO pin for SDATAOUT[3] (%d)" % sdataout3)
        m:item("p",  "Set GPIO pin for POWER       (%d - not used on all designs)" % power)
        m:item("",   "")
        m:item("q",  "Back to SGPIO Menu")

        local choice = m:show()
        if choice == "f" then
            f_sclock = menu.prompt_number("Frequency setting for SCLOCK?")
            cavium.c.bdk_config_set_int(f_sclock, cavium.CONFIG_SGPIO_SCLOCK_FREQ, menu.node)
            cavium.c.bdk_sgpio_set_sclock(menu.node, f_sclock)
        elseif choice == "c" then
            sclock = menu.prompt_number("GPIO pin for SCLOCK?")
            cavium.c.bdk_config_set_int(sclock, cavium.CONFIG_SGPIO_PIN_SCLOCK, menu.node)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "l" then
            sload = menu.prompt_number("GPIO pin for SLOAD?")
            cavium.c.bdk_config_set_int(sload, cavium.CONFIG_SGPIO_PIN_SLOAD, menu.node)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "d0" then
            sdataout0 = menu.prompt_number("GPIO pin for SDATAOUT[0]?")
            cavium.c.bdk_config_set_int(sdataout0, cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 0)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "d1" then
            sdataout1 = menu.prompt_number("GPIO pin for SDATAOUT[1]?")
            cavium.c.bdk_config_set_int(sdataout1, cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 1)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "d2" then
            sdataout2 = menu.prompt_number("GPIO pin for SDATAOUT[2]?")
            cavium.c.bdk_config_set_int(sdataout2, cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 2)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "d3" then
            sdataout3 = menu.prompt_number("GPIO pin for SDATAOUT[3]?")
            cavium.c.bdk_config_set_int(sdataout3, cavium.CONFIG_SGPIO_PIN_SDATAOUT, menu.node, 3)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        elseif choice == "p" then
            power = menu.prompt_number("GPIO pin for POWER?")
            cavium.c.bdk_config_set_int(power, cavium.CONFIG_SGPIO_PIN_POWER, menu.node)
            cavium.c.bdk_sgpio_setup_gpio_pins(menu.node)
        end

    until choice == "q"
end

local m = menu.new("SGPIO Menu")

repeat
    m:clear()

    m:item_node() -- Adds option to choose the node number
    m:item("", "--- Controller setup ---")
    m:item("c", "Configure SCLOCK and GPIO settings", sgpio_configure_controller)
    m:item("", "")
    if cavium.c.bdk_sgpio_is_enabled(menu.node) == 1 then
        m:item("", "--- Controller output is ON ---")
    else
        m:item("", "--- Controller output is OFF ---")
    end
    m:item("t", "Toggle SGPIO controller output ON/OFF", cavium.c.bdk_sgpio_enable_controller, menu.node, 
                                cavium.c.bdk_sgpio_is_enabled(menu.node) == 1 and 0 or 1)
    m:item("", "")
    m:item("", "--- LED control ---")
    m:item("a", "Configure ACTIVITY LEDs", sgpio_led_set, cavium.SGPIO_LED_ACT)
    m:item("l", "Configure LOCATE LEDs",   sgpio_led_set, cavium.SGPIO_LED_LOC)
    m:item("e", "Configure ERROR LEDs",    sgpio_led_set, cavium.SGPIO_LED_ERR)
    m:item("", "")
    m:item("", "Current LED states (o:On  -:Off  *:Blink):")
    m:item("", "LED#         0  1  2  3     4  5  6  7     8  9 10 11    12 13 14 15")
    m:item("", "--------------------------------------------------------------------")

    local status_line
    status_line = sgpio_led_status_line(cavium.SGPIO_LED_ACT)
    m:item("", status_line)
    status_line = sgpio_led_status_line(cavium.SGPIO_LED_LOC)
    m:item("", status_line)
    status_line = sgpio_led_status_line(cavium.SGPIO_LED_ERR)

    m:item("", status_line)
    m:item("", "")
    m:item("q", "Main menu")

    local choice = m:show()
until choice == "q"

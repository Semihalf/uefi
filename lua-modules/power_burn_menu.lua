-- BDK power burn menu.
require("strict")
require("utils")
require("menu")

local function do_throttle()
    local throttle = menu.prompt_number("Throttle level", 0xcc, 0, 0xff)
    cavium.c.bdk_power_throttle(menu.node, throttle)
end

repeat
    local m = menu.new("Power Burn Menu")
    m:item_node() -- Adds option to choose the node number

    m:item("off", "Disable power burn", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_NONE)
    m:item("full", "Full power burn", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_FULL)
    -- The generically namd transient is 1s on, 1s idle
    m:item("tran", "Transient power burn", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_1S)
    -- These other options are disabled by default to reduce confusion
    --m:item("10ms", "Cycle 10ms power burn, 10ms idle", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_10MS)
    --m:item("1s", "Cycle 1s power burn, 1s idle", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_1S)
    --m:item("5s", "Cycle 5s power burn, 5s idle", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_5S)
    --m:item("1m", "Cycle 1m power burn, 1m idle", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_1M)
    --m:item("5m", "Cycle 5m power burn, 5m idle", cavium.c.bdk_power_burn, menu.node, cavium.POWER_BURN_CYCLE_5M)
    -- Disable on multi-node due to errata DAP-24000
    if (not cavium.is_model(cavium.CN88XXP1)) or (cavium.c.bdk_numa_is_only_one() == 1) then
        m:item("throt", "Set power throttle level", do_throttle)
    end

    m:item("quit", "Main menu")
until m:show() == "quit"


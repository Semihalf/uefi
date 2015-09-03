#!/usr/bin/env bdk-lua

-- BDK Main menu

-- Reset scroll region and goto bottom
print("\27[1;r\27[100;1H")

require("strict")
require("utils")
require("menu")
require("rpc")
require("cavium")

-- Set the baudrate. Many messages have already been printed, but we needed
-- to wait for the cavium module.
-- The first argument is the node number (0-1)
-- The second argument is the uart number (0-1)
-- The third argument is the baud rate (9600, 19200, 115200, etc).
-- The fourth argument is whether flow control is enabled.
-- cavium.c.bdk_set_baudrate(cavium.MASTER_NODE, 0, 115200, true)
-- cavium.c.bdk_set_baudrate(cavium.MASTER_NODE, 1, 115200, true)

-- Do board specific setup
--
-- When there is a general board setup file present in the filesystem, execute
-- that. Otherwise, execute the board setup based on the chip model.
if utils.isglobal("BOARD_SETUP_DONE") then
    -- Board setup is already complete, don't do it again
elseif package.searchpath("board-setup", package.path) then
    menu.dofile("board-setup")
elseif cavium.is_model(cavium.CN88XX) then
    menu.dofile("board-ebb8800")
elseif cavium.is_model(cavium.CN83XX) then
    menu.dofile("board-ebb830x")
elseif cavium.is_model(cavium.CN81XX) then
    menu.dofile("board-ebb810x")
end
BOARD_SETUP_DONE = true

local function do_trafficgen()
    local trafficgen = require("trafficgen")
    local tg = trafficgen.new()
    if cavium.is_platform(cavium.PLATFORM_EMULATOR) then
        tg:command("csr RST_PP_RESET")
        tg:command("csr RST_PP_AVAILABLE")
        tg:command("loopback all internal")
        cavium.c.bdk_if_link_wait_all(100000);
        tg:command("default up")
        tg:command("perf_test")
        tg:command("tx_packets_total")
        tg:command("rx_packets_total")
        tg:command("rx_errors")
    end
    return tg:run()
end

if cavium.is_platform(cavium.PLATFORM_EMULATOR) then
    do_trafficgen()
end

local function do_throttle()
    local throttle = menu.prompt_number("Throttle level", 0xcc, 0, 0xff)
    local node = cavium.MASTER_NODE
    if cavium.c.bdk_numa_is_only_one() == 0 then
        node = menu.prompt_number("Node to use", menu.node, 0, 3)
    end
    cavium.c.bdk_power_throttle(node, throttle)
end

local function do_burn()
    local node = cavium.MASTER_NODE
    if cavium.c.bdk_numa_is_only_one() == 0 then
        node = menu.prompt_number("Node to use", menu.node, 0, 3)
    end
    cavium.c.bdk_power_burn(node)
end

local m = menu.new("Main Menu")
m:item("qlm",   "SERDES configuration",     menu.dofile, "qlm_menu")
m:item("config","Software configuration",   menu.dofile, "config_menu")
m:item("file",  "File options",             menu.dofile, "file")
m:item("ddr",   "DDR options",              menu.dofile, "ddr_menu")
m:item("pcie",  "PCIe options",             menu.dofile, "pcie_menu")
m:item("twsi",  "TWSI options",             menu.dofile, "twsi_menu")
m:item("smi",   "SMI/MDIO options",         menu.dofile, "smi_menu")
m:item("mpi",   "SPI/MPI options",          menu.dofile, "mpi_menu")
m:item("emmc",  "eMMC/SD options",          menu.dofile, "emmc")
m:item("sata",  "SATA options",             menu.dofile, "sata")
m:item("gpio",  "GPIO options",             menu.dofile, "gpio_menu")
m:item("usb",   "USB options",              menu.dofile, "usb_menu")
m:item("ilua",  "Interactive Lua prompt",   menu.dofile, "ilua")
m:item("tg",    "Traffic Generator",        do_trafficgen)
m:item("burn",  "Burn power",               do_burn)
m:item("save",  "Save board configuration", cavium.c.bdk_saveenv, 0)
-- Disable on multi-node due to errata DAP-24000
if (not cavium.is_model(cavium.CN88XXP1)) or (cavium.c.bdk_numa_is_only_one() == 1) then
    m:item("throt", "Set power throttle level", do_throttle)
end
m:item("rbt",   "Reboot",                   cavium.c.bdk_reset_chip, cavium.MASTER_NODE)
if cavium.global then
    m:item("quit", "Exit menu")
end

while (m:show() ~= "quit") do
    -- Spinning on menu
end


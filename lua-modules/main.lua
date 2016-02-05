#!/usr/bin/env bdk-lua

-- BDK Main menu

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

local m = menu.new("Main Menu")
m:item("cfg",   "Display current configuration", cavium.c.bdk_config_show)
m:item("qlm",   "SERDES configuration",     menu.dofile, "qlm_menu")
m:item("file",  "File options",             menu.dofile, "file")
m:item("ddr",   "DDR options",              menu.dofile, "ddr_menu")
m:item("pcie",  "PCIe options",             menu.dofile, "pcie_menu")
m:item("twsi",  "TWSI options",             menu.dofile, "twsi_menu")
m:item("smi",   "SMI/MDIO options",         menu.dofile, "smi_menu")
m:item("mpi",   "SPI/MPI options",          menu.dofile, "mpi_menu")
m:item("emmc",  "eMMC/SD options",          menu.dofile, "emmc")
m:item("sata",  "SATA options",             menu.dofile, "sata")
m:item("gpio",  "GPIO options",             menu.dofile, "gpio_menu")
m:item("sgpio", "SGPIO options",            menu.dofile, "sgpio_menu")
m:item("usb",   "USB options",              menu.dofile, "usb_menu")
m:item("ilua",  "Interactive Lua prompt",   menu.dofile, "ilua")
m:item("tg",    "Traffic Generator",        do_trafficgen)
m:item("burn",  "Power Burn options",       menu.dofile, "power_burn_menu")
m:item("ccpi",  "CCPI options",             menu.dofile, "ccpi_menu")
-- Look for a custom board test file
local board = cavium.c.bdk_config_get_str(cavium.CONFIG_BOARD_MODEL)
local board_test_name = ("board-test-%s" % board):lower()
if package.searchpath(board_test_name, package.path) then
    local test = require(board_test_name)
    m:item("brdtest", "Run board test", test)
end
m:item("rbt",   "Reboot",                   cavium.c.bdk_reset_chip, cavium.MASTER_NODE)
if cavium.global then
    m:item("quit", "Exit menu")
end

while (m:show() ~= "quit") do
    -- Spinning on menu
end


#!/usr/bin/env bdk-lua

-- BDK Main menu

-- Reset scroll region and goto bottom
print("\27[1;r\27[100;1H")

require("strict")
require("utils")
require("menu")
require("rpc")
require("octeon")

-- Set the baudrate. Many messages have already been printed, but we needed
-- to wait for the octeon module.
-- The first argument is the uart number (0-1)
-- The second argument is the baud rate (9600, 19200, 115200, etc).
-- The third argument is whether flow control is enabled.
-- octeon.c.bdk_set_baudrate(0, 0, 115200, true)
-- octeon.c.bdk_set_baudrate(0, 1, 115200, true)

-- Do board specific setup
if octeon.is_model(octeon.CN61XX) then
    menu.dofile("board-ebb6100")
elseif octeon.is_model(octeon.CN70XX) then
    menu.dofile("board-ebb7000")
elseif octeon.is_model(octeon.CN78XX) then
    menu.dofile("board-ebb7800")
end
-- Allow the user to do some board specific customization
utils.run("autorun-board")

local m = menu.new("Main Menu")
m:item("config","Configuration options",    menu.dofile, "config_menu")
m:item("file",  "File options",             menu.dofile, "file")
m:item("flash", "Flash options",            menu.dofile, "flash")
m:item("ddr",   "DDR options",              menu.dofile, "ddr_menu")
m:item("qlm",   "QLM options",              menu.dofile, "qlm_menu")
m:item("pcie",  "PCIe options",             menu.dofile, "pcie_menu")
m:item("twsi",  "TWSI options",             menu.dofile, "twsi_menu")
m:item("smi",   "SMI/MDIO options",         menu.dofile, "smi_menu")
m:item("mpi",   "SPI/MPI options",          menu.dofile, "mpi_menu")
m:item("gpio",  "GPIO options",             menu.dofile, "gpio_menu")
m:item("ilua",  "Interactive Lua prompt",   menu.dofile, "ilua")
if octeon.trafficgen then
    m:item("tg",    "Traffic Generator",    menu.dofile, "trafficgen")
end
m:item("rbt",   "Reboot",                   octeon.c.bdk_reset_octeon, 0)
if octeon.global then
    m:item("quit", "Exit menu")
end

while (m:show() ~= "quit") do
    -- Spinning on menu
end


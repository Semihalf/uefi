
-- BDK PCIe menu

require("strict")
require("utils")
require("menu")
local pcie = require("pcie")

local pcie_root = {}
local m = menu.new("PCIe Menu")

m:item("p0i", "PCIe0: Initialize", function()
    pcie_root[0] = pcie.initialize(0)
end)

m:item("p0s", "PCIe0: Scan for devices", function()
    pcie_root[0]:scan()
end)

m:item("p0e", "PCIe0: Enumerate devices", function()
    pcie_root[0]:enumerate()
end)

m:item("p0d", "PCIe0: Display devices", function()
    pcie_root[0]:display()
end)

m:item("p0f", "PCIe0: Shutdown", function()
    pcie_root[0]:shutdown()
    pcie_root[0] = nil
end)

m:item("p1i", "PCIe1: Initialize", function()
    pcie_root[1] = pcie.initialize(1)
end)

m:item("p1s", "PCIe1: Scan for devices", function()
    pcie_root[1]:scan()
end)

m:item("p1e", "PCIe1: Enumerate devices", function()
    pcie_root[1]:enumerate()
end)

m:item("p1d", "PCIe1: Display devices", function()
    pcie_root[1]:display()
end)

m:item("p1f", "PCIe1: Shutdown", function()
    pcie_root[1]:shutdown()
    pcie_root[1] = nil
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end

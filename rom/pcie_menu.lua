
-- BDK PCIe menu

require("strict")
require("utils")
require("menu")
local pcie = require("pcie")

local choices = {
    "PCIe0: Initialize",
    "PCIe0: Scan for devices",
    "PCIe0: Enumerate devices",
    "PCIe0: Display devices",
    "PCIe0: Shutdown",
    "PCIe1: Initialize",
    "PCIe1: Scan for devices",
    "PCIe1: Enumerate devices",
    "PCIe1: Display devices",
    "PCIe1: Shutdown",
    "Main menu",
}

local pcie_root = {}

while (true) do
    local c = menu.show(choices)
    if (c == 1) then
        pcie_root[0] = pcie.initialize(0)
    elseif (c == 2) then
        pcie_root[0]:scan()
    elseif (c == 3) then
        pcie_root[0]:enumerate()
    elseif (c == 4) then
        pcie_root[0]:display()
    elseif (c == 5) then
        pcie_root[0]:shutdown()
        pcie_root[0] = nil
    elseif (c == 6) then
        pcie_root[1] = pcie.initialize(1)
    elseif (c == 7) then
        pcie_root[1]:scan()
    elseif (c == 8) then
        pcie_root[1]:enumerate()
    elseif (c == 9) then
        pcie_root[1]:display()
    elseif (c == 10) then
        pcie_root[1]:shutdown()
        pcie_root[1] = nil
    elseif (c == 11) then
        return
    end
end

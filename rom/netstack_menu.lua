
-- BDK File menu

require("strict")
require("utils")
require("menu")

local function iptostr(ip)
    local a = bit32.AND(bit32.SHR(ip, 24), 0xff)
    local b = bit32.AND(bit32.SHR(ip, 16), 0xff)
    local c = bit32.AND(bit32.SHR(ip, 8), 0xff)
    local d = bit32.AND(bit32.SHR(ip, 0), 0xff)
    return "%d.%d.%d.%d" % {a, b, c, d}
end

local function setconfig(name, ip, netmask, gw)
    local status = octeon.c.bdk_netstack_if_configure(name, ip, netmask, gw)
    if status ~= 0 then
        error("Failed to configure interface " .. name)
    end
end

local m = menu.new("TCP/IP Networking Menu")

m:item("show", "Show port configuration", function()
    local name = menu.prompt_string("Interface name: ")
    local ip = octeon.c.bdk_netstack_if_get_ip(name)
    local netmask = octeon.c.bdk_netstack_if_get_netmask(name)
    local gateway = octeon.c.bdk_netstack_if_get_gw(name)
    printf("Interface: %s IP: %s Netmask %s Gateway %s\n", name, iptostr(ip), iptostr(netmask), iptostr(gateway))
end)

m:item("fixed", "Configure MGMT0 with a static IP 10.0.0.2/24", setconfig, "MGMT00", "10.0.0.2", "/24", "10.0.0.1")

m:item("dhcp", "Configure a network port with DHCP", function()
    local name = menu.prompt_string("Interface name: ")
    setconfig(name, "dhcp")
end)

m:item("static", "Configure a network port with a static IP", function()
    local name = menu.prompt_string("Interface name: ")
    local ip = menu.prompt_string("IP: ")
    local netmask = menu.prompt_string("Netmask: ")
    local gw = menu.prompt_string("Gateway: ")
    setconfig(name, ip, netmask, gw)
end)

m:item("auto", "Configure a network port with auto IP", function()
    local name = menu.prompt_string("Interface name: ")
    setconfig(name, "auto")
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end

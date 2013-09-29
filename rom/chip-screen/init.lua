require("strict")
require("menu")
require("utils")
require("octeon")

-- Print out a banner
print("")
print("Octeon Chip Screen")
print("Copyright (C) 2013 Cavium Networks")
print("Version ".. require("bdk-version"))
print("")

-- Do board specific setup
if octeon.is_model(octeon.CN70XX) then
    menu.dofile("screen-evb7000")
elseif octeon.is_model(octeon.CN78XX) then
    menu.dofile("screen-ebb7800")
end

-- Go multicore
octeon.c.bdk_init_nodes();

local function tg_run(tg, ports, size, count, rate)
    print("")
    tg:command("default %s" % ports)
    tg:command("clear all")
    tg:command("size %d" % size)
    tg:command("count %d" % count)
    tg:command("tx_percent %d" % rate)
    tg:command("start")
    octeon.c.bdk_wait_usec(2000000)
    tg:command("rx_octets_total")
    local stats = tg:get_stats()
    local ports_pass = true
    for port,stat in pairs(stats) do
        local pass = true
        pass = pass and (stat.tx_packets_total == count)
        pass = pass and (stat.rx_packets_total == count)
        pass = pass and (stat.tx_octets_total == stat.rx_octets_total)
        pass = pass and (stat.rx_errors == 0)
        pass = pass and (stat.rx_validation_errors == 0)
        if not pass then
            pprint(port, stat)
        end
        ports_pass = ports_pass and pass
    end
    if ports_pass then
        printf("Test %s, size %d, count %d: PASS\n", ports, size, count)
    else
        printf("Test %s, size %d, count %d: FAIL\n", ports, size, count)
    end
    return ports_pass
end

local all_pass = true

--
-- Network Traffic Tests
--

local trafficgen = require("trafficgen")
local tg = trafficgen.new()
-- Wait for PHY link messages
octeon.c.bdk_wait_usec(5000000)

all_pass = all_pass and tg_run(tg, "LOOP0-LOOP3", 60, 10000, 1000)
all_pass = all_pass and tg_run(tg, "LOOP0-LOOP3", 1500, 10000, 1000)
all_pass = all_pass and tg_run(tg, "LOOP0-LOOP3", 65524, 10000, 1000)

all_pass = all_pass and tg_run(tg, "SGMII0.0-SGMII0.3", 60, 10000, 100)
all_pass = all_pass and tg_run(tg, "SGMII0.0-SGMII0.3", 1500, 10000, 100)
all_pass = all_pass and tg_run(tg, "SGMII0.0-SGMII0.3", 65524, 1000, 100)

all_pass = all_pass and tg_run(tg, "SGMII1.0-SGMII1.3", 60, 10000, 100)
all_pass = all_pass and tg_run(tg, "SGMII1.0-SGMII1.3", 1500, 10000, 100)
all_pass = all_pass and tg_run(tg, "SGMII1.0-SGMII1.3", 65524, 1000, 100)

--
-- MMC Tests
--
local capacity = octeon.mmc.init()
if capacity > 0 then
    print("MMC Init test: PASS")
else
    print("MMC capacity", capacity)
    print("MMC Init test: FAIL")
    all_pass = false
end

--
-- PCIe
--
local pcie = require("pcie")
local rc = pcie.initialize(0, 0)
if rc then
    rc:scan()
    rc:enumerate()
    rc:display()
    print("PCIe init: PASS")
else
    print("PCIe init: FAIL")
end

--
-- Summary
--
print("")
if all_pass then
    print("All tested summary: PASS")
else
    print("All tested summary: FAIL")
end
print("")


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

local board_name = menu.prompt_string("Board type: ", "ebb7800")
local coremask = menu.prompt_number("Coremask: ", 0xffffffffffff)
local config_num = menu.prompt_number("Config Number (1 or 2): ", 1)
local all_pass = true

local function pci_test(rc_port, ep_port)
    local ret_value = false
    print ("In function pci_test\n")
--QLM 0
    octeon.csr.GSERX_REFCLK_SEL(rc_port).USE_COM1 = 0
    octeon.csr.GSERX_REFCLK_SEL(rc_port).COM_CLK_SEL = 1
    octeon.c.bdk_qlm_reset(0, rc_port)
    octeon.c.bdk_qlm_set_mode(0, rc_port, octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2)

--QLM 1
    octeon.csr.GSERX_REFCLK_SEL(ep_port).USE_COM1 = 0
    octeon.csr.GSERX_REFCLK_SEL(ep_port).COM_CLK_SEL = 1
    octeon.c.bdk_qlm_reset(0, ep_port)
    octeon.c.bdk_qlm_set_mode(0, ep_port, octeon.QLM_MODE_PCIE_1X4, 5000, octeon.QLM_MODE_FLAG_GEN2+octeon.QLM_MODE_FLAG_ENDPOINT)

--
-- PCIe
--
    print("test start: PCIe")
    local pcie = require("pcie")
    local status, rc = pcall(pcie.initialize, 0, rc_port)
    if status then
--    t
--    t
--    w
        rc:scan()
        rc:enumerate()
        rc:display()
        print("PCIe%d init: PASS" % rc_port)
        ret_value = true
    else
        print("PCIe%d init: FAIL" % rc_port)
    end
    print("test end: PCIe")
    return ret_value
end

-- Do board specific setup
if (config_num == 1) then
    all_pass = all_pass and pci_test(2,3)
    all_pass = all_pass and pci_test(3,2)
    menu.dofile("screen-ebb7800")
elseif (config_num == 2) then
    all_pass = all_pass and pci_test(0,1)
    all_pass = all_pass and pci_test(1,0)
    menu.dofile("screen-ebb7800-config2")
elseif (config_num == 3) then
    menu.dofile("screen-ebb7800-config3");
else
    print ("ERROR: Invalid configuration number\n");
    --    return 
end

-- Go multicore, based on coremask provided by script.
printf("Using coremask: 0x%x\n", coremask)
octeon.c.bdk_init_cores(0, coremask)


local function tg_run(tg, ports, size, count, rate, to_secs)
    print("")
    tg:command("default %s" % ports)
    tg:command("clear all")
    tg:command("size %d" % size)
    tg:command("count %d" % count)
    tg:command("tx_percent %d" % rate)
    tg:command("start")
    octeon.c.bdk_wait_usec(to_secs * 1000000)
    tg:command("rx_octets_total")
    local stats = tg:get_stats()
    local ports_pass = false
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
        ports_pass = pass
    end
    if ports_pass then
        printf("Test %s, size %d, count %d: PASS\n", ports, size, count)
    else
        printf("Test %s, size %d, count %d: FAIL\n", ports, size, count)
    end
    return ports_pass
end

--
-- MMC Tests
--
print("test start: mmc")
local capacity = octeon.c.bdk_mmc_initialize(0)
if (capacity > 0) then
    print("MMC0 Init test: PASS")
else
    print("MMC0 capacity:", capacity)
    print("MMC0 Init test: FAIL")
    all_pass = false
end

if (board_name == "evb7800_sff") then
-- EMMC on SFF board
    capacity = octeon.c.bdk_mmc_initialize(1)
    if (capacity > 0) then
        print("MMC1 Init test: PASS")
    else
        print("MMC1 capacity:", capacity)
        print("MMC1 Init test: FAIL")
        all_pass = false
    end
end
print("test end: mmc")

local oci0_status = true
local oci1_status = true
local oci2_status = true
print("test start: oci")
if ((octeon.csr.OCX_COM_LINKX_CTL(0).UP ~= 1) or
    (octeon.csr.OCX_COM_LINKX_CTL(0).VALID ~= 1)) then
    print ("oci0: FAIL")
    oci0_status = false
end
if ((octeon.csr.OCX_COM_LINKX_CTL(1).UP ~= 1) or
    (octeon.csr.OCX_COM_LINKX_CTL(1).VALID ~= 1)) then
    print ("oci1: FAIL")
    oci1_status = false
end
if ((octeon.csr.OCX_COM_LINKX_CTL(2).UP ~= 1) or
    (octeon.csr.OCX_COM_LINKX_CTL(2).VALID ~= 1)) then
    print ("oci2: FAIL")
    oci2_status = false
end
if (oci0_status and oci1_status and oci2_status) then
    print ("OCI Test: PASS")
else
    print ("OCI Test: FAIL")
    all_pass = false
end
    

--
-- PCIe
--
--print("test start: PCIe")
--local pcie = require("pcie")
--local status, rc = pcall(pcie.initialize, 0, 0)
--if status then
--    t
--    t
--    w
--    rc:scan()
--    rc:enumerate()
--    rc:display()
--    print("PCIe init: PASS")
--else
--    print("PCIe init: FAIL")
--    all_pass = false
--end
--print("test end: PCIe")


--
-- Network Traffic Tests
--
print("test start: traffic")
local tg_pass = true
local trafficgen = require("trafficgen")
local tg = trafficgen.new()

--Wait for the links to come up
octeon.c.bdk_wait_usec(5 * 1000000)

-- Wait for PHY link messages while testing loop ports
--tg_pass = tg_run(tg, "LOOP0-LOOP3", 60, 10000, 1000, 2)
--tg_pass = tg_pass and tg_run(tg, "LOOP0-LOOP3", 1500, 10000, 1000, 2)
--tg_pass = tg_pass and tg_run(tg, "LOOP0-LOOP3", 65524, 10000, 1000, 4)
--all_pass = all_pass and tg_pass
-- octeon.c.bdk_wait_usec(5000000)


--tg_pass = tg_run(tg, "SGMII0.0-SGMII0.3", 60, 10000, 100, 2)
--tg_pass = tg_pass and tg_run(tg, "SGMII0.0-SGMII0.3", 1500, 10000, 100, 2)
--tg_pass = tg_pass and tg_run(tg, "SGMII0.0-SGMII0.3", 65524, 1000, 100, 2)
--all_pass = all_pass and tg_pass

--tg_pass = tg_run(tg, "SGMII1.0-SGMII1.3", 60, 10000, 100, 2)
--tg_pass = tg_pass and tg_run(tg, "SGMII1.0-SGMII1.3", 1500, 10000, 100, 2)
--tg_pass = tg_pass and tg_run(tg, "SGMII1.0-SGMII1.3", 65524, 1000, 100, 2)
--all_pass = all_pass and tg_pass

--RXAUII 2*2 for now

tg_pass = 1;
if (config_num == 1) then
    tg_pass = tg_pass and tg_run(tg, "LOOP0-LOOP3", 8000, 100000, 1000, 3)
    tg_pass = tg_pass and tg_run(tg, "RXAUI0.0-RXAUI0.1,RXAUI1.0-RXAUI1.1", 8000, 1000, 1000, 3)

    tg_pass = tg_pass and tg_run(tg, "RXAUI0.0,RXAUI1.0", 8000, 10000, 1000, 3)
    tg_pass = tg_pass and tg_run(tg, "RXAUI0.1,RXAUI1.1", 8000, 10000, 1000, 3)

    tg_pass = tg_pass and tg_run(tg, "10GKR2.0-10GKR2.3,10GKR4.0-10GKR4.3", 8000, 10000, 600, 3)

    tg_pass = tg_pass and tg_run(tg, "10GKR2.0,10GKR4.0", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR2.1,10GKR4.1", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR2.2,10GKR4.2", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR2.3,10GKR4.3", 8000, 10000, 600, 3)
    all_pass = all_pass and tg_pass
elseif (config_num == 2) then 
    tg_pass = tg_pass and tg_run(tg, "LOOP0-LOOP3", 8000, 100000, 1000, 3)
    tg_pass = tg_pass and tg_run(tg, "DXAUI0-DXAUI1", 8000, 10000, 1000, 3)

    tg_pass = tg_pass and tg_run(tg, "10GKR3.0-10GKR3.3,10GKR5.0-10GKR5.3", 8000, 10000, 600, 3)

    tg_pass = tg_pass and tg_run(tg, "10GKR3.0,10GKR5.0", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR3.1,10GKR5.1", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR3.2,10GKR5.2", 8000, 10000, 600, 3)
    tg_pass = tg_pass and tg_run(tg, "10GKR3.3,10GKR5.3", 8000, 10000, 600, 3)
    all_pass = all_pass and tg_pass
elseif (config_num == 3) then
    tg_pass = tg_pass and tg_run(tg, "SGMII0.0-SGMII0.1", 8000, 10000, 1000, 3)
    tg_pass = tg_pass and tg_run(tg, "SGMII0.2-SGMII0.3", 8000, 10000, 1000, 3)
    all_pass = all_pass and tg_pass
end

print("test end: traffic")


--
-- Summary
--
print("")
if all_pass then
    print("All tested summary: PASS")
end
print("Octeon Chip Screen complete.")
print("")


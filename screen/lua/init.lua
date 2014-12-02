require("strict")
require("menu")
require("utils")
require("cavium")
require("trafficgen")
local bit64 = require("bit64")

local set_config = cavium.c.bdk_config_set
local node = 0
local all_pass = true

local function tg_run(tg, ports, size, count, rate, to_secs)
    print("")
    tg:command("default %s" % ports)
    tg:command("clear all")
    tg:command("size %d" % size)
    tg:command("count %d" % count)
    tg:command("tx_percent %d" % rate)
    tg:command("start")
    cavium.c.bdk_wait_usec(to_secs * 1000000)
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



local function pcie_rc(pem)
    --
    -- PCIe
    --
        print("test start: PCIe")
        local pcie = require("pcie")
        local status, rc = pcall(pcie.initialize, 0, pem)
        if status then
    --    t
    --    t
    --    w
            rc:scan()
            rc:enumerate()
            rc:display()
            print("PCIe%d init: PASS" % pem)
        else
            print("PCIe%d init: FAIL" % pem)
        end
        print("test end: PCIe")
end

local function mmc_test(device)
    --
    -- MMC Tests
    --
    local mmc_pass = false
    local capacity = cavium.c.bdk_mmc_initialize(node, device)
    if (capacity > 0) then
        mmc_pass = true
        printf("MMC%d Init test: PASS\n", device)
    else
        printf("MMC%d capacity:%d\n", device, capacity)
        printf("MMC%d Init test: FAIL\n",device)
        mmc_pass = false
    end
    return mmc_pass
end

-- Print out a banner
print("")
print("BDK version ".. require("bdk-version"))
print("THUNDERX Chip Screen")
print("Copyright (C) 2010-2014 Cavium Inc.")

local coremask = menu.prompt_number("Coremask: ", 0xffffffffffff)
-- Go multicore, based on coremask provided by script.
printf("Using coremask: 0x%x\n", coremask)
cavium.c.bdk_init_cores(0, coremask)

-- Set up traffic QLMs here, as we want to overlap the link negotiation delay
-- with other tests.
cavium.csr.GSERX_REFCLK_SEL(0).COM_CLK_SEL = 1
cavium.csr.GSERX_REFCLK_SEL(0).USE_COM1 = 1
cavium.c.bdk_qlm_reset(node, 0)
cavium.c.bdk_qlm_set_mode(node, 0, cavium.QLM_MODE_40G_KR4_1X4, 10312, 0)

cavium.csr.GSERX_REFCLK_SEL(1).COM_CLK_SEL = 1
cavium.csr.GSERX_REFCLK_SEL(1).USE_COM1 = 1
cavium.c.bdk_qlm_reset(node, 1)
cavium.c.bdk_qlm_set_mode(node, 1, cavium.QLM_MODE_40G_KR4_1X4, 10312, 0)


-- Configure all QLMS at Gen 3x8
cavium.csr.GSERX_REFCLK_SEL(2).COM_CLK_SEL = 1
cavium.csr.GSERX_REFCLK_SEL(2).USE_COM1 = 0
cavium.c.bdk_qlm_reset(node, 2)
cavium.c.bdk_qlm_set_mode(node, 2, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)

cavium.csr.GSERX_REFCLK_SEL(4).COM_CLK_SEL = 1
cavium.csr.GSERX_REFCLK_SEL(4).USE_COM1 = 0
cavium.c.bdk_qlm_reset(node, 4)
cavium.c.bdk_qlm_set_mode(node, 4, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)

cavium.csr.GSERX_REFCLK_SEL(6).COM_CLK_SEL = 1
cavium.csr.GSERX_REFCLK_SEL(6).USE_COM1 = 0
cavium.c.bdk_qlm_reset(node, 6)
cavium.c.bdk_qlm_set_mode(node, 6, cavium.QLM_MODE_PCIE_1X8, 8000, cavium.QLM_MODE_FLAG_GEN3)



-- OCI test - confirm all QLMs are up and valid.
local oci0_status = true
local oci1_status = true
local oci2_status = true
print("test start: oci")
if ((cavium.csr.OCX_COM_LINKX_CTL(0).UP ~= 1) or
    (cavium.csr.OCX_COM_LINKX_CTL(0).VALID ~= 1)) then
    print ("oci0: FAIL")
    oci0_status = false
end
if ((cavium.csr.OCX_COM_LINKX_CTL(1).UP ~= 1) or
    (cavium.csr.OCX_COM_LINKX_CTL(1).VALID ~= 1)) then
    print ("oci1: FAIL")
    oci1_status = false
end
if ((cavium.csr.OCX_COM_LINKX_CTL(2).UP ~= 1) or
    (cavium.csr.OCX_COM_LINKX_CTL(2).VALID ~= 1)) then
    print ("oci2: FAIL")
    oci2_status = false
end
if (oci0_status and oci1_status and oci2_status) then
    print ("OCI Test: PASS")
else
    all_pass = false
    print ("OCI Test: FAIL")
end


local mmc_pass = true
mmc_pass = mmc_test(0)
mmc_pass = mmc_test(1) and mmc_pass
all_pass = all_pass and mmc_pass

-- PCIe tests.  All QLMs x8 RC

pcie_rc(0)
pcie_rc(2)
pcie_rc(4)


--
-- Network Traffic Tests
--
print("test start: traffic")
local tg_pass = true
local trafficgen = require("trafficgen")
local tg = trafficgen.new()
cavium.c.bdk_wait_usec(3 * 1000000) -- wait for links to come up.
tg_pass = tg_run(tg, "40GKR0-40GKR1", 60, 100000, 50, 5)
tg_pass = tg_run(tg, "40GKR0-40GKR1", 1499, 100000, 50, 7) and tg_pass
tg_pass = tg_run(tg, "40GKR0-40GKR1", 9111, 10000, 10, 12) and tg_pass
all_pass = all_pass and tg_pass

--
-- Summary
--
print("")
if all_pass then
    print("All tested summary: PASS")
else
    print("All tested summary: FAIL")
end
print("BDK Chip Screen complete.")
print("")

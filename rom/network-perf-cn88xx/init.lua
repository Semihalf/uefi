require("strict")
require("menu")
require("utils")
require("cavium")

-- Print out a banner
print("")
print("Network Performance Test")
print("Copyright (C) 2014 Cavium Networks")
printf("Version %s\n", require("bdk-version"))
print("")

menu.dofile("board-ebb7800")

print("Setup the QLMs")
-- Use external ref clock
for qlm=2,7 do
    cavium.csr.GSERX_REFCLK_SEL(qlm).COM_CLK_SEL = 0
    cavium.csr.GSERX_REFCLK_SEL(qlm).USE_COM1 = 0
end
-- Two XAUI
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 2, cavium.QLM_MODE_XAUI_1X4, 3125, 0)
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 3, cavium.QLM_MODE_XAUI_1X4, 3125, 0)
-- Two 10G-KR
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 4, cavium.QLM_MODE_10G_KR_4X1, 10321, 0)
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 5, cavium.QLM_MODE_10G_KR_4X1, 10321, 0)
-- Two 40G-KR
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 6, cavium.QLM_MODE_40G_KR4_1X4, 10321, 0)
cavium.c.bdk_qlm_set_mode(cavium.MASTER, 7, cavium.QLM_MODE_40G_KR4_1X4, 10321, 0)

print("Setting up for 2048 2KB packet buffers")
cavium.c.bdk_config_set(cavium.CONFIG_NUM_PACKET_BUFFERS, 2048)
cavium.c.bdk_config_set(cavium.CONFIG_FPA_POOL_SIZE0, 2048)

print("Creating traffic-gen")
local trafficgen = require("trafficgen")
local tg = trafficgen.new()
local USEC = 1000000
tg:command("default all")
tg:command("count all 0")

print("Wait for the links to come up")
cavium.c.bdk_wait_usec(5 * USEC)

local function tg_perf(tg, tx_ports, size, rate_mbps)
    tg:command("size %s %d" % {tx_ports, size})
    tg:command("tx_percent %s %d" % {tx_ports, rate_mbps / 10})
    tg:command("clear all")
    tg:command("start %s" % tx_ports)
    cavium.c.bdk_wait_usec(1 * USEC)
    tg:get_stats(true)
    cavium.c.bdk_wait_usec(3 * USEC)
    local stats = tg:get_stats(false)
    tg:command("stop all")
    local tx_mbps = 0
    local rx_mbps = 0
    -- LOOP ports use PKI counters that given bogus values randomly. Ignore
    -- these ports unless we really need to count them
    local use_loop_stats = tx_ports:find("LOOP")
    for port,stat in pairs(stats) do
        if (not port:find("LOOP")) or use_loop_stats then
            tx_mbps = tx_mbps + stat.tx_bits
            rx_mbps = rx_mbps + stat.rx_bits
        end
    end
    tx_mbps = (tx_mbps + 500000) / 1000000
    rx_mbps = (rx_mbps + 500000) / 1000000
    printf("%s: size %4d, rate %5d Mbps, tx %5d Mbps, rx %5d Mbps\n", tx_ports, size, rate_mbps, tx_mbps, rx_mbps)
    return rx_mbps
end

--
-- Network Traffic Tests
--
local PACKET_SIZES = {60, 128, 500, 1500, 8000}
local PORT_LISTS = {
    {"LOOP0-LOOP3",         10000},
    {"XAUI0",               10000},
    {"XAUI0-XAUI1",         10000},
    {"10GKR2.0",            10000},
    {"40GKR4",              40000},
    {"10GKR2.0-10GKR3.3",   10000},
    {"40GKR4-40GKR5",       40000},
}

print("Starting tests")
print("")
local summary = {}
for pindex,port_info in pairs(PORT_LISTS) do
    summary[pindex] = {}
    printf("Starting ports %s\n", port_info[1])
    for sindex,packet_size in pairs(PACKET_SIZES) do
        summary[pindex][sindex] = tg_perf(tg, port_info[1], packet_size, port_info[2])
    end
end
print("")
printf("%18s      Packet Sizes, Speeds in Mbps\n", "")
printf("%18s ", "TX Ports")
for sindex,packet_size in pairs(PACKET_SIZES) do
    printf("%8d", packet_size)
end
printf("\n")
for pindex,port_info in pairs(PORT_LISTS) do
    printf("%18s ", port_info[1])
    for sindex,packet_size in pairs(PACKET_SIZES) do
        printf("%8d", summary[pindex][sindex])
    end
    printf("\n")
end
print("")
tg:run()


-- BDK CCPI menu.
-- Displays the GUI interface for CCPI testing
require("strict")
require("utils")
require("menu")
require("fileio")
local bit64 = require("bit64")

--
-- Used on a single node to test the internal CCPI logic
--
local function do_loopback_test()
    assert(cavium.c.bdk_numa_is_only_one() == 1, "Loopback test can't run in a multinode setup")
    cavium.c.bdk_ccpi_test_loopback()
end

--
-- Called to test CCPI with a memory test
--
local function do_margin_check(node, lane)
    -- Define the range of memory to check for CCPI loading
    local mem_address = 0x4000000
    local mem_length = 0x1000000
    local test_flags = cavium.DRAM_TEST_NO_STOP_ERROR + cavium.DRAM_TEST_NO_PROGRESS +
        cavium.DRAM_TEST_NO_BANNERS + cavium.DRAM_TEST_USE_CCPI + cavium.DRAM_TEST_NO_STATS
    -- Clear lane errors
    cavium.csr[node].OCX_LNEX_INT(lane).write(-1)
    -- Run the mem test
    local errors = cavium.c.bdk_dram_test(11, mem_address, mem_length, test_flags)
    -- Read the lane error bits
    local err_bits = cavium.csr[node].OCX_LNEX_INT(lane).read()
    -- Fail if there were any errors other than counter overflow (bit 7)
    if (err_bits ~= 0) and (err_bits ~= 0x80) then
        errors = errors + 1
    end
    cavium.csr[node].OCX_LNEX_INT(lane).write(-1)
    cavium.csr[node].OCX_COM_LINKX_INT(0).write(-1)
    cavium.csr[node].OCX_COM_LINKX_INT(1).write(-1)
    cavium.csr[node].OCX_COM_LINKX_INT(2).write(-1)
    return errors
end

--
-- Perform a margin sweep on all CCPI lanes
--
local function do_margin_rx()
    local MARGIN_PASS = 7 -- To pass, max-min must be greater than equal to this
    assert(cavium.c.bdk_numa_is_only_one() == 0, "Margin test can't run in a single node setup")
    assert(not cavium.is_model(cavium.CN88XXP1), "Margin test can't run on CN88XX pass 1.x")
    assert(cavium.c.bdk_init_nodes(0,0) == 0, "Failed to start all cores on all nodes")

    for node=0,1 do
        printf("N%d.CCPI: Measuring Eye Height for each lane\n", node)
        for qlm=8,13 do
            for qlm_lane=0,3 do
                local avg_eye_height = 0
                local avg_count = 3
                for avg_repeat=1,avg_count do
                    local ccpi_lane = (qlm - 8) * 4 + qlm_lane
                    local vert_center = cavium.c.bdk_qlm_margin_rx_get(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
                    local vert_min = cavium.c.bdk_qlm_margin_rx_get_min(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
                    local vert_max = cavium.c.bdk_qlm_margin_rx_get_max(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
                    for vert = vert_center,vert_max do
                        cavium.c.bdk_qlm_margin_rx_set(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert);
                        local have_error = do_margin_check(node, ccpi_lane) > 0
                        --printf("    %d - %s\n", vert, have_error and "FAIL" or "PASS")
                        if have_error then
                            vert_max = vert - 1
                            break
                        end
                    end

                    for vert = vert_center,vert_min,-1 do
                        cavium.c.bdk_qlm_margin_rx_set(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert);
                        local have_error = do_margin_check(node, ccpi_lane) > 0
                        --printf("    %d - %s\n", vert, have_error and "FAIL" or "PASS")
                        if have_error then
                            vert_min = vert + 1
                            break
                        end
                    end
                    cavium.c.bdk_qlm_margin_rx_restore(node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert_center);
                    --printf("N%d.CCPI QLM%d Lane %d: Min=%d, Middle=%d, Max=%d\n", node, qlm, qlm_lane, vert_min, vert_center, vert_max)
                    local eye_height = (vert_max - vert_min) + 1
                    avg_eye_height = avg_eye_height + eye_height
                end
                local eye_height = avg_eye_height / avg_count
                local status = (eye_height >= MARGIN_PASS) and "PASS" or "FAIL"
                printf("N%d.CCPI QLM%d Lane %d: Eye Height %2d - %s\n", node, qlm, qlm_lane, eye_height, status)
            end
        end
    end
end

--
-- CCPI main menu
--

local m = menu.new("CCPI Menu")
m:item("ccpi",  "Test CCPI using internal loopback", do_loopback_test)
m:item("margin",  "Run CCPI margining tool", do_margin_rx)
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end

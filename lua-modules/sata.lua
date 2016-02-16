-- BDK SATA menu.
-- Displays the GUI interface for accessing SATA.
require("strict")
require("utils")
require("fileio")
require("menu")
local readline = require("readline")
local bit64 = require("bit64")

local option = ""
local sata = 0
local PATTERNS = {0x00, 0xff, 0x55, 0xaa}

--
-- Create a "length" sector string for the given pattern. The string
-- length will be 512 * length.
--
local function get_pattern(pattern, length)
    local pat = string.char(pattern)
    pat = pat:rep(length * 512)
    return pat
end

--
-- A number of palces below need to ask the user for an area to work on and
-- open a file at that location. This function consolidates this
--
local function get_file_data(file_mode)
    local filename = utils.devfile("sata", sata)
    local offset = menu.prompt_number("Starting sector")
    local length = menu.prompt_number("Number of sectors", 1)

    local handle = assert(cavium.devopen(filename, file_mode))
    local loc = handle:seek("set", offset * 512)
    if not loc then
        handle:close()
        error('Seek failed in file "' .. filename ..'"')
    end

    return handle, offset, length
end

--
-- Write a fixed pattern to SATA
--
local function write_pattern(pattern)
    local handle, offset, length = get_file_data("w")
    handle:write(get_pattern(pattern, length))
    handle:close()
end

--
-- Read SATA and verify the data matches the pattern
--
local function read_pattern(pattern)
    local handle, offset, length = get_file_data("r")
    local correct = get_pattern(pattern, length)
    local data = handle:read(length * 512)
    handle:close()
    assert(correct == data, "SATA data doesn't match pattern")
end

local function run_auto()
    -- Allow this test to be repeated for long term testing
    local loop_count = menu.prompt_number("Repeat count (-1 for infinite)", 1)

    local filename = utils.devfile("sata", sata)
    local handle = assert(cavium.devopen(filename, "r+"))
    local sector = 0

    -- Get the end loop count
    if loop_count == -1 then
        loop_count = 0x7fffffffffffffff
    elseif loop_count < 1 then
        loop_count = 1
    end
    -- Loop running the test
    for count=1,loop_count do
        -- Show progress
        if loop_count == 0x7fffffffffffffff then
            printf("Pass %d - Press return to exit\n", count)
        else
            printf("Pass %d of %d - Press return to exit\n", count, loop_count)
        end
        -- Run the test
        for length=1,128 do
            printf("Testing %d sector accesses\n", length)
            for i,p in ipairs(PATTERNS) do
                local correct = get_pattern(p, length)
                assert(handle:seek("set", sector * 512), "Write seek failed")
                handle:write(correct)
                assert(handle:seek("set", sector * 512), "Read seek failed")
                local data = handle:read(length * 512)
                assert(correct == data, "SATA data doesn't match pattern")
            end
            local key = readline.getkey()
            if key == '\r' then
                printf("\nAbort on key press\n")
                goto abort_key
            end
        end
    end
::abort_key::
    handle:close()
end

--
-- Check margin range for SATA channel
--
local function margin_rx()
    local filename = utils.devfile("sata", sata)
    local handle = assert(cavium.devopen(filename, "r+"))
    local function do_data()
        local length = 128
        local correct = get_pattern(0x55, length)
        assert(handle:seek("set", 0), "Write seek failed")
        handle:write(correct)
        for rep = 1,16384 do -- Reads total 1Gb of data
            assert(handle:seek("set", 0), "Read seek failed")
            local data = handle:read(length * 512)
            assert(correct == data, "SATA data doesn't match pattern")
            local have_error = cavium.csr[menu.node].SATAX_UAHC_P0_SERR(sata).read() ~= 0
            if have_error then
                break
            end
        end
    end
    local qlm = (sata >= 8) and (6 + (sata - 8) / 4) or (2 + sata / 4) -- FIXME: Only CN88XX
    local qlm_lane = bit64.band(sata, 3)
    local vert_center = cavium.c.bdk_qlm_margin_rx_get(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
    local vert_min = cavium.c.bdk_qlm_margin_rx_get_min(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
    local vert_max = cavium.c.bdk_qlm_margin_rx_get_max(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL);
    for vert = vert_center,vert_max do
        cavium.csr[menu.node].SATAX_UAHC_P0_SERR(sata).write(-1)
        cavium.c.bdk_qlm_margin_rx_set(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert);
        do_data() -- Send data
        local have_error = cavium.csr[menu.node].SATAX_UAHC_P0_SERR(sata).read() ~= 0
        printf("    %d - %s\n", vert, have_error and "FAIL" or "PASS")
        if have_error then
            vert_max = vert - 1
            break
        end
    end
    for vert = vert_center,vert_min,-1 do
        cavium.csr[menu.node].SATAX_UAHC_P0_SERR(sata).write(-1)
        cavium.c.bdk_qlm_margin_rx_set(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert);
        do_data() -- Send data
        local have_error = cavium.csr[menu.node].SATAX_UAHC_P0_SERR(sata).read() ~= 0
        printf("    %d - %s\n", vert, have_error and "FAIL" or "PASS")
        if have_error then
            vert_min = vert + 1
            break
        end
    end
    cavium.c.bdk_qlm_margin_rx_restore(menu.node, qlm, qlm_lane, cavium.QLM_MARGIN_VERTICAL, vert_center);
    printf("N%d.SATA%d: Min=%d, Middle=%d, Max=%d\n", menu.node, sata, vert_min, vert_center, vert_max)
    handle:close()
end

--
-- Put the menu on the screen
--
while (option ~= "quit") do
    local m = menu.new("SATA Menu")
    m:item_node() -- Adds option to choose the node number

    m:item("port", "Select SATA port (Currently %d)" % sata, function()
        local num_sata = cavium.c.bdk_sata_get_controllers(menu.node)
        sata = menu.prompt_number("SATA port to use", sata, 0, num_sata - 1)
    end)

    m:item("id", "Perform an identify disk", function()
        local size = cavium.c.bdk_sata_identify(menu.node, sata, 0)
    end)

    m:item("sw-retimed", "Enter Local-end Retimed Loopback", function()
        printf("Entering Local-end Retimed Loopback\n")
        cavium.c.bdk_sata_bist_fis(menu.node, sata, 0, cavium.SATA_BIST_SW_RETIMED)
    end)

    local function add_tx_only(test, descr)
        m:item("sw-tx%d" % test, "Enter Local-end Transmit Only, %s" % descr, function()
            printf("Entering %s\n" % descr)
            cavium.c.bdk_sata_bist_fis(menu.node, sata, 0, test)
        end)
    end
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_SSOP, "Simultaneous switching outputs pattern (SSOP)")
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_HTDP, "High transition density pattern (HTDP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_LTDP, "Low transition density pattern (LTDP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_LFSCP,"Low frequency spectral component pattern (LFSCP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_COMP, "Composite pattern (COMP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_LBP,  "Lone bit pattern (LBP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_MFTP, "Mid frequency test pattern (MFTP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_HFTP, "High frequency test pattern (HFTP)");
    add_tx_only(cavium.SATA_BIST_SW_TX_ONLY_LFTP, "Low frequency test pattern (LFTP)");

    m:item("reset", "Reset the controller", function()
        printf("Resetting the controller\n")
        local status = cavium.c.bdk_sata_shutdown(menu.node, sata)
    end)

    m:item("hex", "Hex display", function()
        local offset = menu.prompt_number("Starting sector")
        local length = menu.prompt_number("Number of sectors", 1)
        local filename = utils.devfile("sata", sata)
        fileio.hexdump(filename, offset * 512, length * 512)
    end)

    for i,p in ipairs(PATTERNS) do
        m:item("w" .. tostring(p), "Write pattern 0x%02x" % p, write_pattern, p)
        m:item("r" .. tostring(p), "Read  pattern 0x%02x" % p, read_pattern, p)
    end

    m:item("auto", "Run automated pattern test", run_auto)
    m:item("margin", "Run margining tool", margin_rx)

    m:item("quit", "Main menu")
    option = m:show()
end


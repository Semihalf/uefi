#!/usr/bin/env bdk-lua

--
-- Lua script supplying command line access to a remtoe Octeon
-- Run without arguments for help
--

require("strict")
require("utils")
local oremote = require("oremote")
local bit64 = require("bit64")
local norflash = require("norflash")
local remoteconsole = require("remoteconsole")

local remote = {}

local REGISTER_NAMES = {
    [0] = "zero",
    [1] = "at",
    [2] = "v0",
    [3] = "v1",
    [4] = "a0",
    [5] = "a1",
    [6] = "a2",
    [7] = "a3",
    [8] = "a4",
    [9] = "a5",
    [10] = "a6",
    [11] = "a7",
    [12] = "t0",
    [13] = "t1",
    [14] = "t2",
    [15] = "t3",
    [16] = "s0",
    [17] = "s1",
    [18] = "s2",
    [19] = "s3",
    [20] = "s4",
    [21] = "s5",
    [22] = "s6",
    [23] = "s7",
    [24] = "t8",
    [25] = "t9",
    [26] = "k0",
    [27] = "k1",
    [28] = "gp",
    [29] = "sp",
    [30] = "s8/fp",
    [31] = "ra",
    [32] = "lo",
    [33] = "hi",
    [0x100 +  0*8 + 0] = "Index",
    [0x100 +  1*8 + 0] = "Random",
    [0x100 +  2*8 + 0] = "EntryLo0",
    [0x100 +  3*8 + 0] = "EntryLo1",
    [0x100 +  4*8 + 0] = "Context",
    [0x100 +  5*8 + 0] = "PageMask",
    [0x100 +  5*8 + 1] = "PageGrain",
    [0x100 +  6*8 + 0] = "Wired",
    [0x100 +  7*8 + 0] = "HWREna",
    [0x100 +  8*8 + 0] = "BadVAddr",
    [0x100 +  9*8 + 0] = "Count",
    [0x100 + 10*8 + 0] = "EntryHi",
    [0x100 + 11*8 + 0] = "Compare",
    [0x100 + 12*8 + 0] = "Status",
    [0x100 + 12*8 + 1] = "IntCtl",
    [0x100 + 12*8 + 2] = "SRSCtl",
    [0x100 + 13*8 + 0] = "Cause",
    [0x100 + 14*8 + 0] = "EPC",
    [0x100 + 15*8 + 0] = "PRId",
    [0x100 + 15*8 + 1] = "Ebase",
    [0x100 + 16*8 + 0] = "Config",
    [0x100 + 16*8 + 1] = "Config1",
    [0x100 + 16*8 + 2] = "Config2",
    [0x100 + 16*8 + 3] = "Config3",
    [0x100 + 18*8 + 0] = "WatchLo0",
    [0x100 + 18*8 + 1] = "WatchLo1",
    [0x100 + 19*8 + 0] = "WatchHi0",
    [0x100 + 19*8 + 1] = "WatchHi1",
    [0x100 + 20*8 + 0] = "XContext",
    [0x100 + 23*8 + 0] = "Debug",
    [0x100 + 25*8 + 0] = "PerfControl0",
    [0x100 + 25*8 + 2] = "PerfControl1",
    [0x100 + 24*8 + 0] = "DEPC",
    [0x100 + 25*8 + 1] = "PerfCount0",
    [0x100 + 25*8 + 3] = "PerfCount1",
    [0x100 + 27*8 + 0] = "IcacheError",
    [0x100 + 27*8 + 1] = "DcacheError",
    [0x100 + 28*8 + 0] = "IcacheTagLo",
    [0x100 + 28*8 + 1] = "IcacheDataLo",
    [0x100 + 28*8 + 2] = "DcacheTagLo",
    [0x100 + 28*8 + 3] = "DcacheDataLo",
    [0x100 + 29*8 + 1] = "IcacheDataHi",
    [0x100 + 29*8 + 2] = "DcacheTagHi",
    [0x100 + 29*8 + 3] = "DcacheDataHi",
    [0x100 + 30*8 + 0] = "ErrorEPC",
    [0x100 + 31*8 + 0] = "DESAVE",
    [0x100 +  9*8 + 7] = "CvmCtl",
    [0x100 + 11*8 + 7] = "CvmMemCt",
    [0x100 +  9*8 + 6] = "CvmCount",
    [0x100 + 22*8 + 0] = "MultiCoreDebug",
    [0x100 +  4*8 + 2] = "UserLocal",    -- From here on only exists in Octeon 2
    [0x100 + 16*8 + 4] = "Config4",
    [0x100 + 11*8 + 6] = "PowThr",
    [0x100 + 23*8 + 6] = "Debug2",
    [0x100 + 31*8 + 2] = "Kscratch1",
    [0x100 + 31*8 + 3] = "Kscratch2",
    [0x100 + 31*8 + 4] = "Kscratch3",
    [0x100 +  8*8 + 1] = "BadInstr",    -- From here on only exists in Octeon 3
    [0x100 +  8*8 + 2] = "BadInstrP",
    [0x100 + 10*8 + 4] = "GuestCtl1",
    [0x100 + 10*8 + 5] = "GuestCtl2",
    [0x100 + 12*8 + 6] = "GuestCtl0",
    [0x100 + 12*8 + 7] = "GTOoffest",
    [0x100 + 16*8 + 5] = "Config5",
    [0x100 + 16*8 + 6] = "CvmMemCtl2",
    [0x100 + 16*8 + 7] = "CvmVMConfig",
    [0x100 + 25*8 + 4] = "PerfControl2",
    [0x100 + 25*8 + 5] = "PerfValue2",
    [0x100 + 25*8 + 6] = "PerfControl3",
    [0x100 + 25*8 + 7] = "PerfValue3",
    [0x100 + 26*8 + 0] = "ErrCtl",
    [0x100 + 27*8 + 2] = "ICacheDebug",
    [0x100 + 28*8 + 4] = "TagLoD1",
    [0x100 + 31*8 + 5] = "Kscratch4",
}

function remote.csr(args)
    -- csr <csr>
    -- csr <csr> <value>
    -- csr <csr> <value> decode
    assert(args[1] == "csr", "Expected keyword 'csr'")
    if #args == 1 then
        local count = 0
        for n in oremote.csr() do
            printf("%-25s ", n)
            count = count + 1
            if count == 3 then
                printf("\n")
                count = 0
            end
        end
        if count ~= 0 then
            printf("\n")
        end
        return
    end

    local partial_matches = {}
    local found = false
    local is_csr, csr = pcall(oremote.csr.lookup, args[2])
    if is_csr then
        if #args == 2 then
            csr.display()
        elseif #args == 3 then
            csr.write(args[3])
        elseif #args == 4 then
            assert(args[4] == "decode", "Expected keyword 'decode'")
            csr.display(args[3])
        else
            error("Invalid number of args")
        end
    else
        print(csr)
        args[2] = args[2]:upper()
        local len = #args[2]
        for n in oremote.csr() do
            if n == args[2] then
                found = true
                break
            elseif n:sub(1,len) == args[2] then
                table.insert(partial_matches, n)
            end
        end
        print("Here are some similar names:")
        partial_matches = table.sorted_values(partial_matches)
        local count = 0
        for i = 1, #partial_matches do
            printf("%-25s ", partial_matches[i])
            count = count + 1
            if count == 3 then
                printf("\n")
                count = 0
            end
        end
        if count ~= 0 then
            printf("\n")
        end
    end
end

function remote.boot(args)
    -- boot <filename>
    assert(args[1] == "boot", "Expected keyword 'boot'")
    local f = assert(io.open(args[2], "r"))
    local d = f:read("*a")
    f:close()

    -- Reset and stop the cores
    oremote.reset(1)
    -- Disable L2 aliasing
    if oremote.csr.L2C_CTL.DISIDXALIAS == 0 then
        oremote.csr.L2C_CTL.DISIDXALIAS = 1
    end
    -- Write the image to L2
    oremote.write_mem(0, d)
    -- Setup the Bootbus moveable region
    oremote.csr.MIO_BOOT_LOC_CFGX(0).write(0x81fc0000)
    oremote.csr.MIO_BOOT_LOC_ADR.write(0);
    -- 0:   3c1a8000        lui     k0,0x8000
    -- 4:   03400008        jr      k0
    -- 8:   00000000        nop
    -- c:   00000000        nop
    oremote.csr.MIO_BOOT_LOC_DAT.write(0x3c1a800003400008);
    oremote.csr.MIO_BOOT_LOC_DAT.write(0x0000000000000000);
    -- Start core 0
    oremote.start_cores(1)
end

function remote.reset(args)
    -- reset
    assert(args[1] == "reset", "Expected keyword 'reset'")
    oremote.reset(0)
end

function remote.console(args)
    -- reset
    assert(args[1] == "console", "Expected keyword 'console'")
    remoteconsole.run()
end

function remote.flash(args)
    -- flash info
    -- flash read <filename> <address> <length>
    -- flash write <filename> <address>
    assert(args[1] == "flash", "Expected keyword 'flash'")
    oremote.stop_cores(-1)
    if args[2] == "info" then
        assert(#args == 2, "Expected two arguments")
        local nor = assert(norflash.query(0))
        pprint(nor.params)
    elseif args[2] == "read" then
        assert(#args == 5, "Expected five arguments")
        local nor = assert(norflash.query(0))
        local f = assert(io.open(args[3], "w"))
        local len = args[5]
        local address = args[4]
        printf("Reading %s: ", args[3])
        printf("  0%%")
        local loc = 0
        while loc < len do
            local percent = 100 * loc / len
            printf("\b\b\b\b%3d%%", percent)
            io.flush()
            local s = len - loc
            if s > 0x10000 then
                s = 0x10000
            end
            f:write(nor:read(address, s))
            address = address + s
            loc = loc + s
        end
        printf("\b\b\b\b100%%\n")
        f:close()
    elseif args[2] == "write" then
        assert(#args == 4, "Expected four arguments")
        local nor = assert(norflash.query(0))
        local f = assert(io.open(args[3], "r"))
        local d = f:read("*a")
        f:close()
        printf("Writing %s: ", args[3])
        nor:burn(args[4], d, true)
    else
        error("Invalid number of args")
    end
end

function remote.mmc(args)
    -- mmc info
    -- mmc read <filename> <address> <length>
    -- mmc write <filename> <address>
    assert(args[1] == "mmc", "Expected keyword 'mmc'")
    oremote.stop_cores(-1)
    if args[2] == "info" then
        assert(#args == 2, "Expected two arguments")
        local size = oremote.mmc.init()
        if size > bit64.lshift(1, 30) then
            printf("Found device of size %d GB\n", bit64.rshift(size, 30))
        elseif size > bit64.lshift(1, 20) then
            printf("Found device of size %d MB\n", bit64.rshift(size, 20))
        elseif size > bit64.lshift(1, 10) then
            printf("Found device of size %d KB\n", bit64.rshift(size, 10))
        else
            printf("Found device of size %d bytes\n", size)
        end
    elseif args[2] == "read" then
        assert(#args == 5, "Expected five arguments")
        local size = oremote.mmc.init()
        local f = assert(io.open(args[3], "w"))
        local len = args[5]
        local address = args[4]
        printf("Reading %s: ", args[3])
        printf("  0%%")
        local loc = 0
        while loc < len do
            local percent = 100 * loc / len
            printf("\b\b\b\b%3d%%", percent)
            io.flush()
            local data = oremote.mmc.read(address, 512)
            local s = len - loc
            if s < #data then
                data = data:sub(1,s)
            else
                s = #data
            end
            f:write(data)
            address = address + s
            loc = loc + s
        end
        printf("\b\b\b\b100%%\n")
        f:close()
    elseif args[2] == "write" then
        assert(#args == 4, "Expected four arguments")
        local address = args[4]
        local size = oremote.mmc.init()
        local f = assert(io.open(args[3], "r"))
        local data = f:read("*a")
        f:close()
        printf("Writing %s: ", args[3])
        printf("  0%%")
        local loc = 0
        while loc < #data do
            local percent = 100 * loc / #data
            printf("\b\b\b\b%3d%%", percent)
            io.flush()
            local chunk = data:sub(loc+1, loc+512)
            if #chunk < 512 then
                chunk = chunk .. string.rep("\0", 512 - #chunk)
            end
            oremote.mmc.write(address, chunk)
            address = address + #chunk
            loc = loc + #chunk
        end
        printf("\b\b\b\b100%%\n")
    else
        error("Invalid number of args")
    end
end

function remote.core(args)
    -- core <core>
    assert(args[1] == "core", "Expected keyword 'core'")
    local state = oremote.get_core_state(args[2])
    printf("Core %d\n", args[2]);
    printf("CPU registers:\n");
    for num=0,33,2 do
        printf("%-14s = 0x%016x    %-14s = 0x%016x\n", REGISTER_NAMES[num], state[1][num+1], REGISTER_NAMES[num+1], state[1][num+2])
    end
    printf("Coprocessor 0 registers:\n");
    local count = 0
    for num=0x100,0x200 do
        if REGISTER_NAMES[num] then
            printf("%-14s = 0x%016x    ", REGISTER_NAMES[num], state[2][num+1 - 0x100])
            count = count + 1
            if count >= 2 then
                printf("\n")
                count = 0
            end
        end
    end
    if count then
        printf("\n")
    end
    -- Skip the TLB if the pagemask isn't filled in
    if state[3][1][2] == 0x0bad0bad0bad0bad then
        return
    end
    printf("TLB:\n");
    for r=1,256 do
        local va = state[3][r][1]/4096*4096
        if bit64.bextract(va, 32,63) == 0xc001ffff then
            va = bit64.bor(va, 0x3ffe000000000000)
        end
        local asid       = state[3][r][1] % 256
        local pagemask   = (state[3][r][2] + 0x1fff) / 2
        local pagesize   = (pagemask+1) / 1024
        local page0      = state[3][r][3]/64*4096
        local cache0     = (state[3][r][3]/8) % 8
        local dirty0     = (state[3][r][3]/4) % 2
        local valid0     = (state[3][r][3]/2) % 2
        local glbl0      = state[3][r][3] % 2
        local ri0        = (state[3][r][3]/2^63) % 2
        local xi0        = (state[3][r][3]/2^62) % 2
        local page1      = state[3][r][4]/64*4096
        local cache1     = (state[3][r][4]/8) % 8
        local dirty1     = (state[3][r][4]/4) % 2
        local valid1     = (state[3][r][4]/2) % 2
        local glbl1      = state[3][r][4] % 2
        local ri1        = (state[3][r][4]/2^63) % 2
        local xi1        = (state[3][r][4]/2^62) % 2
        printf("%3d: Virtual=0x%016x Page0=0x%09x,C=%d,D=%d,V=%d,G=%d,RI=%d,XI=%d Page1=0x%09x,C=%d,D=%d,V=%d,G=%d,RI=%d,XI=%d ASID=%3d Size=%dKB\n",
            r, va, page0, cache0, dirty0, valid0, glbl0, ri0, xi0, page1, cache1, dirty1, valid1, glbl1, ri1, xi1, asid, pagesize)
    end
end

function remote.reg(args)
    -- reg <core> <register>
    -- reg <core> <register> <value>
    assert(args[1] == "reg", "Expected keyword 'reg'")
    if #args == 3 then
        local v = oremote.read_register(args[2], args[3])
        printf("Core %d, register %s: hex 0x%016x decimal %d\n", args[2], REGISTER_NAMES[args[3]], v, v)
    elseif #args == 4 then
        oremote.write_register(args[2], args[3], args[4])
    else
        error("Invalid number of args")
    end
end

function remote.mem(args)
    -- mem <address>
    -- mem <width> <address>
    -- mem <width> <address> <value>
    -- mem load <filename> <address>
    -- mem save <filename> <address> <length>
    assert(args[1] == "mem", "Expected keyword 'mem'")
    if args[2] == "load" then
        assert(#args == 4, "Expected four arguments")
        local f = assert(io.open(args[3], "r"))
        local d = f:read("*a")
        f:close()
        oremote.write_mem(args[4], d)
    elseif args[2] == "save" then
        assert(#args == 5, "Expected five arguments")
        local f = assert(io.open(args[3], "w"))
        local d = oremote.read_mem(args[4], args[5])
        f:write(d)
        f:close()
    elseif #args == 2 then
        local v = oremote.read_mem64(args[2])
        printf("Address 0x%016x = 0x%016x\n", args[2], v)
    elseif #args == 3 then
        if args[2] == 8 then
            local v = oremote.read_mem64(args[3])
            printf("Address 0x%016x = 0x%016x\n", args[3], v)
        elseif args[2] == 4 then
            local v = oremote.read_mem32(args[3])
            printf("Address 0x%016x = 0x%08x\n", args[3], v)
        elseif args[2] == 2 then
            local v = oremote.read_mem16(args[3])
            printf("Address 0x%016x = 0x%04x\n", args[3], v)
        elseif args[2] == 1 then
            local v = oremote.read_mem(args[3], 1)
            v = v:byte()
            printf("Address 0x%016x = 0x%02x\n", args[3], v)
        else
            error("Illegal width")
        end
    elseif #args == 4 then
        if args[2] == 8 then
            oremote.write_mem64(args[3], args[4])
        elseif args[2] == 4 then
            oremote.write_mem32(args[3], args[4])
        elseif args[2] == 2 then
            oremote.write_mem16(args[3], args[4])
        elseif args[2] == 1 then
            oremote.write_mem(args[3], string.char(args[4]))
        else
            error("Illegal width")
        end
    else
        error("Invalid number of args")
    end
end

function remote.profile(args)
    -- profile
    -- profile <coremask>
    local coremask = -1
    assert(args[1] == "profile", "Expected keyword 'profile'")
    if #args == 1 then
        -- Do nothing
    elseif #args == 2 then
        coremask = args[2]
    else
        error("Invalid number of args")
    end
    local num_cores = oremote.get_num_cores()
    local profile_data = {}
    local show_time = os.time() + 5
    while true do
        local sample = oremote.get_sample(coremask)
        for core, pc in ipairs(sample) do
            if core > num_cores then
                break
            end
            if not profile_data[pc] then
                profile_data[pc] = {}
                for core = 1, num_cores do
                    profile_data[pc][core] = 0
                end
            end
            profile_data[pc][core] = profile_data[pc][core] + 1
        end
        if os.time() > show_time then
            for _,pc in ipairs(table.sorted_keys(profile_data)) do
                printf("0x%016x:", pc)
                for core = 1, num_cores do
                    printf(" %d", profile_data[pc][core])
                end
                printf("\n")
            end
            printf("\n")
            io.flush()
            profile_data = {}
            show_time = os.time() + 5
        end
    end
end

function remote.help(args)
    assert(args[1] == "help", "Expected keyword 'help'")
    local message =
[[
bdk-remote:
    csr
        Print a list of all valid CSR names.
    csr <csr>
        Read the named CSR and decode it.
    csr <csr> <value>
        Write the named CSR.
    csr <csr> <value> decode
        Decode <value> as if it were the named CSR.

    boot <filename>
        Boot <filename> on Octeon.
    reset
        Reset Octeon.
    console
        Access the BDK console remotely.

    flash info
        Probe a NOR flash and display information about it.
    flash read <filename> <address> <length>
        Read <length> bytes from <address> in NOR flash on
        CS0 and save it to <filename>.
    flash write <filename> <address>
        Write <filename> to a NOR flash on CS0 starting at <address>.

    mmc info
        Probe a eMMC, MMC, or SD and display information about it.
    mmc read <filename> <address> <length>
        Read <length> bytes from <address> in a eMMC, MMC, or SD
        and save it to <filename>.
    mmc write <filename> <address>
        Write <filename> to a eMMC, MMC, or SD starting at <address>.

    core <core>
        Dump all CPU registers, COP0, and TLB entries for <core>.

    reg <core> <register>
        Read CPU <register> for <core>.
    reg <core> <register> <value>
        Write <value> to register <register> for CPU <core>.

    mem <address>
        Read eight bytes from <address>.
    mem <width> <address>
        Read <width> bytes from <address>.
    mem <width> <address> <value>
        Write <value> as <width> bytes to <address>.
    mem load <filename> <address>
        Load <filename> to <address>.
    mem save <filename> <address> <length>
        Save <length> bytes at <address> to <filename>.

    profile
        Profile all cores.
    profile <coremask>
        Profile cores in the supplied <coremask>.

    help
        Display this help.

Parameter descriptions:
    <csr>
        A name of a CSR, such as CIU_FUSE or CIU_INTX_SUM0(0).
    <value>
        A numeric value specified in either decimal or hexadecimal.
    <filename>
        Standard unix format file name.
    <core>
        Octeon CPU core number, starting at zero.
    <address>
        An Octeon physical memory address specified in either decimal or
        hexadecimal.
    <width>
        A byte width. Must be 8, 4, 2, or 1.
    <coremask>
        A decimal or hexadecimal number representing CPU cores. Each set bit
        represents a single CPU core. For example, 0x2f represents cores 0-3
        and 5.
    <register>
        One of the following CPU register names.]]
    print(message)
    local count = 0
    for _,name in ipairs(table.sorted_values(REGISTER_NAMES)) do
        printf("%-13s", name)
        count = count + 1
        if count >= 6 then
            printf("\n")
            count = 0
        end
    end
    if count then
        printf("\n")
    end
end

local function parse_args()
    local formats = {
        "csr",
        "csr <csr>",
        "csr <csr> <value>",
        "csr <csr> <value> decode",
        "boot <filename>",
        "reset",
        "console",
        "flash info",
        "flash read <filename> <address> <length>",
        "flash write <filename> <address>",
        "mmc info",
        "mmc read <filename> <address> <length>",
        "mmc write <filename> <address>",
        "core <core>",
        "reg <core> <register>",
        "reg <core> <register> <value>",
        "mem <address>",
        "mem <width> <address>",
        "mem <width> <address> <value>",
        "mem load <filename> <address>",
        "mem save <filename> <address> <length>",
        "profile",
        "profile <coremask>",
        "help"
    }

    for _,format in ipairs(formats) do
        local parsed = {}
        local index = 1
        for word in format:gmatch("%g+") do
            if index > #arg then
                -- Arguments are too short
                index = -1
                break
            end
            local n = tonumber(arg[index])
            if word == "<csr>" then
                table.insert(parsed, arg[index]:lower())
            elseif word == "<value>" then
                if n == nil then
                    -- Illegal number
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == "<filename>" then
                table.insert(parsed, arg[index])
            elseif word == "<core>" then
                if (n < 0) or (n > 64) then
                    -- Illegal core number
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == "<register>" then
                local search = arg[index]:lower()
                for num,name in pairs(REGISTER_NAMES) do
                    if name:lower() == search then
                        table.insert(parsed, num)
                        search = nil
                    end
                end
                if search then
                    -- Illegal register number
                    index = -1
                    break
                end
            elseif word == "<address>" then
                if n == nil then
                    -- Illegal number
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == "<width>" then
                if (n ~= 1) and (n ~= 2) and (n ~= 4) and (n ~= 8) then
                    -- Illegal width
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == "<coremask>" then
                if n == nil then
                    -- Illegal number
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == "<length>" then
                if n < 1 then
                    -- Illegal length
                    index = -1
                    break
                end
                table.insert(parsed, n)
            elseif word == arg[index]:lower() then
                table.insert(parsed, word)
            else
                -- Illegal word
                index = -1
                break
            end
            -- Parsed correctly, move to next word
            index = index + 1
        end
        -- Return the arguments if all words parsed
        if index == #arg + 1 then
            return parsed
        end
    end
    error("Invalid command line")
end

local function main()
    local status, my_args = pcall(parse_args)
    if status then
        remote[my_args[1]](my_args)
    else
        print("ERROR:", my_args)
        remote.help({"help"})
    end
end

main()
oremote.close()

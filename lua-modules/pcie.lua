--
-- Lua module supporting PCIe
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--
require("strict")
require("utils")
require("cavium")
local bit64 = require("bit64")

-- This is the table we use to contain the module
local pcie = {}

-- Config registers for all devices
local PCICONFIG_VENDOR_ID           = 0
local PCICONFIG_DEVICE_ID           = 2
local PCICONFIG_COMMAND             = 4
local PCICONFIG_STATUS              = 6
local PCICONFIG_CLASS_CODE_REV_ID   = 8
local PCICONFIG_CACHE_LINE_SIZE     = 0xc
local PCICONFIG_MASTER_LT           = 0xd
local PCICONFIG_HEADER_TYPE         = 0xe
local PCICONFIG_BIST                = 0xf
local PCICONFIG_BAR0                = 0x10
local PCICONFIG_CARDBUS_CIS         = 0x28
local PCICONFIG_SUBVENDOR_ID        = 0x2c
local PCICONFIG_SUBDEVICE_ID        = 0x2e
local PCICONFIG_ROM                 = 0x30
local PCICONFIG_CAP_PTR             = 0x34
local PCICONFIG_INT_LINE            = 0x3c
local PCICONFIG_INT_PIN             = 0x3d
local PCICONFIG_MIN_GNT             = 0x3e
local PCICONFIG_MAX_LAT             = 0x3f

-- Config registers for bridges/switches
local PCICONFIG_PRIMARY_BUS         = 0x18
local PCICONFIG_SECONDARY_BUS       = 0x19
local PCICONFIG_SUBORIDINATE_BUS    = 0x1a
local PCICONFIG_SECONDARY_LAT       = 0x1b
local PCICONFIG_IO_BASE             = 0x1c
local PCICONFIG_IO_LIMIT            = 0x1d
local PCICONFIG_SECONDARY_STATUS    = 0x1e
local PCICONFIG_MEMORY_BASE         = 0x20
local PCICONFIG_MEMORY_LIMIT        = 0x22
local PCICONFIG_PREF_BASE           = 0x24
local PCICONFIG_PREF_LIMIT          = 0x26
local PCICONFIG_PREF_BASE_UPPER     = 0x28
local PCICONFIG_PREF_LIMIT_UPPER    = 0x2c
local PCICONFIG_IO_BASE_UPPER       = 0x30
local PCICONFIG_IO_LIMIT_UPPER      = 0x32


local configr8 = cavium.c.bdk_pcie_config_read8
local configr16 = cavium.c.bdk_pcie_config_read16
local configr32 = cavium.c.bdk_pcie_config_read32
local configw8 = cavium.c.bdk_pcie_config_write8
local configw16 = cavium.c.bdk_pcie_config_write16
local configw32 = cavium.c.bdk_pcie_config_write32

--
-- This function creates a table representing a PCIe device. It reads
-- the VENDOR and DEVICE ID. If these are undefined it returns nil as the
-- device doesn't exist.
--
local function create_device(root, bus, deviceid, func)
    local newdev = {}
    newdev.root = root
    newdev.bus = bus
    newdev.deviceid = deviceid
    newdev.func = func

    --
    -- PCIe config space reads
    --
    function newdev:read8(reg)
        return bit64.band(configr8(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg), 0xff)
    end
    function newdev:read16(reg)
        return bit64.band(configr16(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg), 0xffff)
    end
    function newdev:read32(reg)
        return bit64.band(configr32(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg), 0xffffffff)
    end

    --
    -- PCIe config space writes
    --
    function newdev:write8(reg, val)
        configw8(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg, val)
    end
    function newdev:write16(reg, val)
        configw16(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg, val)
    end
    function newdev:write32(reg, val)
        configw32(self.root.node, self.root.port, self.bus, self.deviceid, self.func, reg, val)
    end

    --
    -- Scan for devices behind this one on a subordinate bus. The scan is
    -- recursive.
    --
    function newdev:scan()
        -- This can only be called if the device is a brdige/switch
        assert(self.isbridge)
        -- Create a table that will contain our sub devices
        self.devices = {}
        -- Scan all possible device IDs on the bus
        for deviceid = 0,31 do
            -- Try and create a device
            local device = create_device(self.root, self.busnum, deviceid, 0)
            -- Device will be nil if nothing was there
            if device then
                -- Add the new device to my children
                table.insert(self.devices, device)
                -- Scan for other functions on multifunction devices
                if device.ismultifunction then
                    for func = 1,7 do
                        -- Try and create a device
                        device = create_device(self.root, self.busnum, deviceid, func)
                        -- Device will be nil if nothing was there
                        if device then
                            -- Add the new device to my children
                            table.insert(self.devices, device)
                        else
                            -- Past last function for device. stop function scanning
                            break
                        end
                    end
                end
            end
        end
    end

    local function  bar_size_compare(a, b)
        return a[3] > b[3]
    end

    function newdev:getresources()
        local io_bars = {}
        local mem_bars = {}
        local pmem_bars = {}
        if self.isbridge then
            for _,device in ipairs(self.devices) do
                local io, mem, pmem = device:getresources()
                for inp,outp in pairs({[io]=io_bars, [mem]=mem_bars, [pmem]=pmem_bars}) do
                    local size = 0
                    for i = 1,#inp do
                        size = size + inp[i][3]
                    end
                    if size > 0 then
                        table.insert(outp, {nil, 0, size, 0})
                    end
                end
            end
        end
        local max_bar = PCICONFIG_CARDBUS_CIS
        if self.isbridge then
            max_bar = PCICONFIG_PRIMARY_BUS
        end
        local bar = PCICONFIG_BAR0
        while bar < max_bar do
            self:write32(bar, 0xffffffff)
            local v = self:read32(bar)
            local ismem = not bit64.btest(v, 1)
            local is64 = ismem and bit64.btest(v, 4)
            local ispref = ismem and bit64.btest(v, 8)
            if is64 then
                self:write32(bar+4, 0xffffffff)
                v = self:read32(bar+4) * 2^32 + v
            end
            if v ~= 0 then
                if ispref then
                    local size = bit64.bnot(bit64.band(v, -16)) + 1
                    table.insert(pmem_bars, {self, bar, size, v})
                elseif ismem then
                    local size = bit64.bnot(bit64.band(v, -16)) + 1
                    table.insert(mem_bars, {self, bar, size, v})
                else
                    local size = bit64.bnot(bit64.band(v, -4)) + 1
                    table.insert(io_bars, {self, bar, size, v})
                end
            end
            if is64 then
                bar = bar + 8
            else
                bar = bar + 4
            end
        end
        table.sort(io_bars, bar_size_compare)
        table.sort(mem_bars, bar_size_compare)
        table.sort(pmem_bars, bar_size_compare)
        return io_bars, mem_bars, pmem_bars
    end

    --
    -- Assign resources to the device
    --
    function newdev:enumerate(io_address, mem_address, pmem_address)
        local io_bars, mem_bars, pmem_bars = self:getresources()
        for _,bar_table in ipairs({io_bars, mem_bars, pmem_bars}) do
            for _,bar in ipairs(bar_table) do
                local device, bar_addr, size, barv = table.unpack(bar)
                if device then
                    if bar_table == io_bars then
                        if bit64.band(io_address, size - 1) then
                            io_address = io_address + size - 1
                            io_address = bit64.band(io_address, -size)
                        end
                        -- printf("%d:%d.%d [%x] = %x (%x bytes) [IO]\n", device.bus, device.deviceid, device.func, bar_addr, io_address, size)
                        device:write32(bar_addr, io_address)
                        io_address = io_address + size
                    elseif bar_table == mem_bars then
                        local is64 = bit64.btest(barv, 4)
                        if bit64.band(mem_address, size - 1) then
                            mem_address = mem_address + size - 1
                            mem_address = bit64.band(mem_address, -size)
                        end
                        -- printf("%d:%d.%d [%x] = %x (%x bytes) [Mem]\n", device.bus, device.deviceid, device.func, bar_addr, mem_address, size)
                        device:write32(bar_addr, mem_address)
                        if is64 then
                            device:write32(bar_addr+4, mem_address / 2^32)
                        end
                        mem_address = mem_address + size
                    else
                        local is64 = bit64.btest(barv, 4)
                        if bit64.band(pmem_address, size - 1) then
                            pmem_address = pmem_address + size - 1
                            pmem_address = bit64.band(pmem_address, -size)
                        end
                        -- printf("%d:%d.%d [%x] = %x (%x bytes) [PMem]\n", device.bus, device.deviceid, device.func, bar_addr, pmem_address, size)
                        device:write32(bar_addr, pmem_address)
                        if is64 then
                            device:write32(bar_addr+4, pmem_address / 2^32)
                        end
                        pmem_address = pmem_address + size
                    end
                    -- Enable IO, MEM, and Bus master
                    local cmd = self:read16(PCICONFIG_COMMAND)
                    cmd = bit64.bor(cmd, 7)
                    self:write16(PCICONFIG_COMMAND, cmd)
                end
            end
        end
        if self.isbridge then
            -- Align IO on a 4k boundary
            if bit64.band(io_address, 4095) then
                io_address = io_address + 4095
                io_address = bit64.band(io_address, -4096)
            end
            -- Align Mem on a 1M boundary
            if bit64.band(mem_address, 0xfffff) then
                mem_address = mem_address + 0xfffff
                mem_address = bit64.band(mem_address, -0x100000)
            end
            -- Align Pmem on a 1M boundary
            if bit64.band(pmem_address, 0xfffff) then
                pmem_address = pmem_address + 0xfffff
                pmem_address = bit64.band(pmem_address, -0x100000)
            end
            -- printf("%d:%d.%d Bridge base IO = %x, Mem = %x, PMem = %x\n", self.bus, self.deviceid, self.func, io_address, mem_address, pmem_address)
            -- Program IO base
            local v = self:read8(PCICONFIG_IO_BASE)
            self:write8(PCICONFIG_IO_BASE, bit64.rshift(io_address, 8))
            if bit64.btest(v, 1) then
                self:write16(PCICONFIG_IO_BASE_UPPER, bit64.rshift(io_address, 16))
            end
            -- Program Mem base
            self:write16(PCICONFIG_MEMORY_BASE, bit64.rshift(mem_address, 16))
            -- Program Pmem base
            local v = self:read16(PCICONFIG_PREF_BASE)
            self:write16(PCICONFIG_PREF_BASE, bit64.rshift(pmem_address, 16))
            if bit64.btest(v, 1) then
                self:write32(PCICONFIG_PREF_BASE_UPPER, bit64.rshift(pmem_address, 32))
            end
            for _,device in ipairs(self.devices) do
                io_address, mem_address, pmem_address = device:enumerate(io_address, mem_address, pmem_address)
            end
            -- printf("%d:%d.%d Bridge limit IO = %x, Mem = %x, PMem = %x\n", self.bus, self.deviceid, self.func, io_address, mem_address, pmem_address)
            -- Program IO limit
            local v = self:read8(PCICONFIG_IO_LIMIT)
            self:write8(PCICONFIG_IO_LIMIT, bit64.rshift(io_address-1, 8))
            if bit64.btest(v, 1) then
                self:write8(PCICONFIG_IO_LIMIT_UPPER, bit64.rshift(io_address-1, 16))
            end
            -- Program Mem limit
            self:write16(PCICONFIG_MEMORY_LIMIT, bit64.rshift(mem_address-1, 16))
            -- Program Pmem limit
            local v = self:read16(PCICONFIG_PREF_LIMIT)
            self:write16(PCICONFIG_PREF_LIMIT, bit64.rshift(pmem_address-1, 16))
            if bit64.btest(v, 1) then
                self:write32(PCICONFIG_PREF_LIMIT_UPPER, bit64.rshift(pmem_address-1, 32))
            end
        end
        return io_address, mem_address, pmem_address
    end

    --
    -- Display a device and all children
    --
    function newdev:display(indent)
        if not indent then
            indent = ""
        end
        local t = self:read32(PCICONFIG_CLASS_CODE_REV_ID)
        printf("%s%d:%d.%d Class:%06x Vendor:%04x Device:%04x (Rev %02x)\n",
            indent,
            self.bus,
            self.deviceid,
            self.func,
            bit64.rshift(t, 8),
            self:read16(PCICONFIG_VENDOR_ID),
            self:read16(PCICONFIG_DEVICE_ID),
            bit64.band(t, 0xff))
        printf("%s    Command:%04x Status:%04x\n",
            indent,
            self:read16(PCICONFIG_COMMAND),
            self:read16(PCICONFIG_STATUS))
        --printf("%s    Cache Line Size:%02x Master Latency Timer:%02x Header Type:%02x BIST:%02x\n",
        --    indent,
        --    self:read8(PCICONFIG_CACHE_LINE_SIZE),
        --    self:read8(PCICONFIG_MASTER_LT),
        --    self:read8(PCICONFIG_HEADER_TYPE),
        --    self:read8(PCICONFIG_BIST))
        --printf("%s    Cardbus CIS Pointer:%08x\n",
        --    indent,
        --    self:read32(PCICONFIG_CARDBUS_CIS))
        printf("%s    Subsystem Vendor:%04x Device:%04x\n",
            indent,
            self:read16(PCICONFIG_SUBVENDOR_ID),
            self:read16(PCICONFIG_SUBDEVICE_ID))
        --printf("%s    Expansion ROM:%08x\n",
        --    indent,
        --    self:read32(PCICONFIG_ROM))
        --printf("%s    Capabilities Pointer:%02x\n",
        --    indent,
        --    self:read8(PCICONFIG_CAP_PTR))
        --printf("%s    Interrupt Line:%02x Interrupt Pin:%02x Min Grant:%02x Max Latency:%02x\n",
        --    indent,
        --    self:read8(PCICONFIG_INT_LINE),
        --    self:read8(PCICONFIG_INT_PIN),
        --    self:read8(PCICONFIG_MIN_GNT),
        --    self:read8(PCICONFIG_MAX_LAT))
        if self.isbridge then
            printf("%s    Primary Bus:%02x Secondary Bus:%02x Subordinate Bus:%02x Secondary Latency Timer:%02x\n",
                indent,
                self:read8(PCICONFIG_PRIMARY_BUS),
                self:read8(PCICONFIG_SECONDARY_BUS),
                self:read8(PCICONFIG_SUBORIDINATE_BUS),
                self:read8(PCICONFIG_SECONDARY_LAT))
            printf("%s    Secondary Status:%04x\n",
                indent,
                self:read16(PCICONFIG_SECONDARY_STATUS))
            printf("%s    IO Base:%04x%02x00 Limit:%04x%02xff\n",
                indent,
                self:read16(PCICONFIG_IO_BASE_UPPER),
                bit64.band(self:read8(PCICONFIG_IO_BASE), -16),
                self:read16(PCICONFIG_IO_LIMIT_UPPER),
                bit64.bor(self:read8(PCICONFIG_IO_LIMIT), 0xf))
            printf("%s    Memory Base:%02x0000 Limit:%02xffff\n",
                indent,
                bit64.band(self:read16(PCICONFIG_MEMORY_BASE), -16),
                bit64.bor(self:read16(PCICONFIG_MEMORY_LIMIT), 0xf))
            printf("%s    Prefetchable Memory Base:%04x%02x0000 Limit:%04x%02xffff\n",
                indent,
                self:read32(PCICONFIG_PREF_BASE_UPPER),
                bit64.band(self:read16(PCICONFIG_PREF_BASE), -16),
                self:read32(PCICONFIG_PREF_LIMIT_UPPER),
                bit64.bor(self:read16(PCICONFIG_PREF_LIMIT), 0xf))
        end
        local max_bar = PCICONFIG_CARDBUS_CIS
        if self.isbridge then
            max_bar = PCICONFIG_PRIMARY_BUS
        end
        local bar = PCICONFIG_BAR0
        local barno = 0
        while bar < max_bar do
            local v = self:read32(bar)
            local ismem = not bit64.btest(v, 1)
            local is64 = ismem and bit64.btest(v, 4)
            local ispref = ismem and bit64.btest(v, 8)
            local display_type = "IO"
            if ismem then
                display_type = "Memory"
                if ispref then
                    display_type = "Prefetchable Memory"
                end
            end
            if is64 then
                v = self:read32(bar+4) * 2^32 + v
                if v ~= 0 then
                    printf("%s    BAR%d: %016x [%s]\n", indent, barno, v, display_type)
                end
                bar = bar + 8
            else
                if v ~= 0 then
                    printf("%s    BAR%d: %08x [%s]\n", indent, barno, v, display_type)
                end
                bar = bar + 4
            end
            barno = barno + 1
        end
        if self.isbridge then
            indent = indent .. "    "
            for _,device in ipairs(self.devices) do
                device:display(indent)
            end
        end
    end

    -- Read the VENDOR and DEVICE ID
    newdev.did = newdev:read32(PCICONFIG_VENDOR_ID)
    -- Fail create if device didn't respond
    if newdev.did == 0xffffffff then
        return nil
    end
    --printf("%d:%d.%d Found %08x\n", newdev.bus, newdev.deviceid, newdev.func, newdev.did)

    -- Figure out if the device supports multiple functions and/or
    -- if it is a switch
    local header_type = newdev:read8(PCICONFIG_HEADER_TYPE)
    newdev.ismultifunction = bit64.btest(header_type, 0x80)
    newdev.isbridge = bit64.band(header_type, 0x7f) == 1
    if newdev.isbridge then
        -- Device is a bridge/switch. Assign bus numbers so we can
        -- scan for subordinate devices
        newdev:write8(PCICONFIG_PRIMARY_BUS, newdev.bus)
        root.last_bus = root.last_bus + 1
        newdev.busnum = root.last_bus
        newdev:write8(PCICONFIG_SECONDARY_BUS, newdev.busnum)
        -- Set to max value as we don't know how many busses are there
        newdev:write8(PCICONFIG_SUBORIDINATE_BUS, 0xff)
        -- Scan for children
        newdev:scan()
        -- Update the last bus number now that we know how many busses
        -- were there
        newdev:write8(PCICONFIG_SUBORIDINATE_BUS, root.last_bus)
    end
    -- Return the device
    return newdev
end

--
-- Initialize a PCIe port and return a table of information about it.
--
function pcie.initialize(node, pcie_port)
    -- Initialize the PCIe link
    if cavium.c.bdk_pcie_rc_initialize(node, pcie_port) ~= 0 then
        error("bdk_pcie_rc_initialize() failed")
    end

    -- Create the root table for storing information
    local pcie_root = {}
    pcie_root.node = node
    pcie_root.port = pcie_port
    pcie_root.last_bus = 0
    pcie_root.devices = {}

    --
    -- Scan the PCIe bus and find all devices
    --
    function pcie_root:scan()
        self.devices = {}
        -- Get the top level bus number
        self.last_bus = cavium.csr.PCIERCX_CFG006(self.port).PBNUM
        for dev=0,31 do
            local device = create_device(self, self.last_bus, dev, 0)
            if device then
                table.insert(self.devices, device)
                -- Device is mulifunction so scan the other functions
                if device.ismultifunction then
                    for func = 1,7 do
                        -- Try and create a device
                        device = create_device(self, self.last_bus, dev, func)
                        -- Device will be nil if nothing was there
                        if device then
                            -- Add the new device to my children
                            table.insert(self.devices, device)
                        else
                            -- Past last function for device. stop function scanning
                            break
                        end
                    end
                end
            end
        end
    end

    --
    -- Enumerate and assign resources.
    --
    function pcie_root:enumerate()
        -- Perform a scan if it hasn't already been done
        if #self.devices == 0 then
            self:scan()
        end
        local io_address = cavium.c.bdk_pcie_get_base_address(self.port, cavium.PCIE_MEM_IO)
        local mem_address = cavium.c.bdk_pcie_get_base_address(self.port, cavium.PCIE_MEM_NORMAL)
        local pmem_address = cavium.c.bdk_pcie_get_base_address(self.port, cavium.PCIE_MEM_PREFETCH)
        -- Assign resources to all top level devices
        for _,device in ipairs(self.devices) do
            io_address, mem_address = device:enumerate(io_address, mem_address, pmem_address)
        end
    end

    --
    -- Display all devices on the bus
    --
    function pcie_root:display()
        printf("PCIe port %d:\n", self.port)
        for _,device in ipairs(self.devices) do
            device:display()
        end
    end

    --
    -- Get devices on a PCIe port. Must call scan() first.
    --
    function pcie_root:get_devices()
        return self.devices
    end

    --
    -- Shutdown a PCIe port
    --
    function pcie_root:shutdown()
        local status = cavium.c.bdk_pcie_rc_shutdown(self.node, self.port)
        if status ~= 0 then
            error("bdk_pcie_rc_shutdown() failed")
        end
    end

    return pcie_root
end

return pcie


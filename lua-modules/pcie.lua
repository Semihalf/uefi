--
-- Lua module supporting PCIe
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2015 Cavium Inc.
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

-- Table to show nice names for devices that are Cavium internal
local DEVICE_NAME = {
    [0xa001] = "MRML",
    [0xa002] = "PCC Bridge",
    [0xa008] = "SMMU",
    [0xa009] = "GIC",
    [0xa00a] = "GPIO",
    [0xa00b] = "MPI",
    [0xa00c] = "MIO_PTP",
    [0xa00d] = "MIX",
    [0xa00e] = "RST",
    [0xa00f] = "UAA",
    [0xa010] = "MIO_EMM",
    [0xa011] = "MIO_BOOT",
    [0xa012] = "MIO_TWS",
    [0xa013] = "OCX",
    [0xa014] = "VRM",
    [0xa015] = "SLI",
    [0xa016] = "KEY",
    [0xa017] = "GTI",
    [0xa018] = "RNM",
    [0xa019] = "DFA",
    [0xa01a] = "ZIP",
    [0xa01b] = "USBH",
    [0xa01c] = "SATA",
    [0xa01d] = "RAD",
    [0xa01e] = "NIC",
    [0xa01f] = "TNS",
    [0xa020] = "PEM",
    [0xa021] = "L2C",
    [0xa022] = "LMC",
    [0xa023] = "OCLA",
    [0xa024] = "OSM",
    [0xa025] = "GSER",
    [0xa026] = "BGX",
    [0xa027] = "IOBN",
    [0xa029] = "NCSI",
    [0xa02a] = "SGP",
    [0xa02b] = "SMI",
    [0xa02c] = "DAP",
    [0xa02d] = "PCIERC",
    [0xa02e] = "L2C_TAD",
    [0xa02f] = "L2C_CBC",
    [0xa030] = "L2C_MCI",
    [0xa031] = "MIO_FUS",
    [0xa032] = "FUSF",
    [0xa033] = "RNM_VF",
    [0xa034] = "NIC_VF",
    [0xa035] = "PBUS",
    [0xa036] = "RAD_VF",
    [0xa037] = "ZIP_VF",
    [0xa038] = "SLIRE",
    [0xa040] = "CPT",
    [0xa041] = "CPT_VF",
    [0xa042] = "LBK",
    [0xa043] = "BCH",
    [0xa044] = "BCH_VF",
    [0xa045] = "DDF",
    [0xa046] = "DDF_VF",
    [0xa047] = "PKI",
    [0xa048] = "PKO",
    [0xa049] = "PKO_VF",
    [0xa04a] = "SSO",
    [0xa04b] = "SSO_VF",
    [0xa04c] = "SSOW",
    [0xa04d] = "SSOW_VF",
    [0xa04e] = "PCM",
    [0xa04f] = "NDF",
    [0xa050] = "TIM",
    [0xa051] = "TIM_VF",
    [0xa052] = "FPA",
    [0xa053] = "FPA_VF",
    [0xa054] = "RGX",
    [0xa055] = "USBDRD",
    [0xa056] = "XCV",
    [0xa057] = "DPI",
    [0xa100] = "THUNDERX_CN88XX",
    [0xa300] = "THUNDERX_CN83XX",
}

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

    --
    -- BARs are stored as an array of 4 elements
    -- 1) Pointer to the device (self)
    -- 2) The PCIe config address of the BAR
    -- 3) The size of the bar in bytes
    -- 4) The address of the BAR in PCIe space
    -- This function compares the BAR sizes so they
    -- can be sorted largest to smallest
    --
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
        local vendor = self:read16(PCICONFIG_VENDOR_ID)
        local deviceid = self:read16(PCICONFIG_DEVICE_ID)
        local deviceid_str = ""
        if (vendor == 0x177d) and (DEVICE_NAME[deviceid]) then
            deviceid_str = DEVICE_NAME[deviceid]
        end

        printf("%s%d:%d.%d Class:%06x Vendor:%04x Device:%04x %s(Rev %02x)\n",
            indent,
            self.bus,
            self.deviceid,
            self.func,
            bit64.rshift(t, 8),
            vendor,
            deviceid,
            deviceid_str,
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
        printf("%s    Capabilities Pointer:%02x\n",
            indent,
            self:read8(PCICONFIG_CAP_PTR))
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
            printf("%s    Memory Base:%04x0000 Limit:%04xffff\n",
                indent,
                bit64.band(self:read16(PCICONFIG_MEMORY_BASE), -16),
                bit64.bor(self:read16(PCICONFIG_MEMORY_LIMIT), 0xf))
            printf("%s    Prefetchable Memory Base:%08x%04x0000 Limit:%08x%04xffff\n",
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

        -- Display the PCI capabilities headers
        local has_pcie = false
        local cap_loc = self:read8(PCICONFIG_CAP_PTR)
        while cap_loc ~= 0 do
            local cap_id = self:read8(cap_loc)
            local cap_next = self:read8(cap_loc + 1)
            printf("%s    PCI Capability %02x ID:%02x Next:%02x\n",
                   indent, cap_loc, cap_id, cap_next)
            if cap_id == 0x10 then
                has_pcie = true
                printf("%s        PCIe\n", indent)
            end
            if cap_id == 0x11 then
                printf("%s        MSI-X\n", indent)
            end
            if cap_id == 0x14 then
                printf("%s        Enhanced Allocation\n", indent)
            end
            cap_loc = cap_next
        end

        -- Display the PCIe capabilities headers
        if has_pcie then
            cap_loc = 0x100
            while cap_loc ~= 0 do
                local cap = self:read32(cap_loc)
                local cap_id = bit64.bextract(cap, 0, 15)
                local cap_ver = bit64.bextract(cap, 16, 19)
                local cap_next = bit64.bextract(cap, 20, 31)
                printf("%s    PCIe Capability %03x ID:%04x Version:%x Next:%03x\n",
                       indent, cap_loc, cap_id, cap_ver, cap_next)
                if cap_id == 0xe then
                    local ari_cap_reg = self:read16(cap_loc+4)
                    local ari_cap_m = bit64.bextract(ari_cap_reg, 0, 0)
                    local ari_cap_a = bit64.bextract(ari_cap_reg, 1, 1)
                    local ari_cap_next = bit64.bextract(ari_cap_reg, 8, 15)
                    local next_dev = bit64.bextract(ari_cap_next, 3, 7)
                    local next_fun = bit64.bextract(ari_cap_next, 0, 2)
                    printf("%s        ARI MFVC: %x ACS: %x Next: %02x (%d.%d)\n", indent, ari_cap_m, ari_cap_a, ari_cap_next, next_dev, next_fun)
                    local ari_ctl_reg = self:read16(cap_loc+6)
                    local ari_ctl_m = bit64.bextract(ari_ctl_reg, 0, 0)
                    local ari_ctl_a = bit64.bextract(ari_ctl_reg, 1, 1)
                    local ari_ctl_grp = bit64.bextract(ari_ctl_reg, 4, 6)
                    printf("%s        MFVC Enable: %x ACS Enable: %x Group: %x\n", indent, ari_ctl_m, ari_ctl_a, ari_ctl_grp)
                end
                if cap_id == 0xb then
                    local vsec_id = self:read32(cap_loc+4)
                    local vsec_id_id = bit64.bextract(vsec_id, 0, 15)
                    local vsec_id_rev = bit64.bextract(vsec_id, 16, 19)
                    local vsec_id_len = bit64.bextract(vsec_id, 20, 31)
                    printf("%s        Vendor ID: %04x Rev: %x Size %03x\n", indent, vsec_id_id, vsec_id_rev, vsec_id_len);
                    -- Check for Cavium extension. Low bits change per model
                    if bit64.band(vsec_id_id, 0xf0) == 0xa0 then
                        if vsec_id_rev == 1 then
                            local vsec_ctl = self:read32(cap_loc+8)
                            local vsec_ctl_inst_num = bit64.bextract(vsec_ctl, 0, 7)
                            local vsec_ctl_subnum = bit64.bextract(vsec_ctl, 8, 15)
                            printf("%s        Instance: %02x Static Bus: %02x\n", indent, vsec_ctl_inst_num, vsec_ctl_subnum);
                            local vsec_sctl = self:read32(cap_loc+12)
                            local vsec_sctl_rid = bit64.bextract(vsec_ctl, 16, 23)
                            printf("%s        Revision ID: %02x\n", indent, vsec_sctl_rid);
                        else
                            printf("%s        Unknown extension revision\n", indent);
                        end
                    end
                end
                cap_loc = cap_next
            end
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
    printf("Bus %d Dev %2d.%d Found %04x:%04x\n", newdev.bus, newdev.deviceid, newdev.func,
           bit64.band(newdev.did, 0xffff), bit64.rshift(newdev.did, 16))

    -- Figure out if the device supports multiple functions and/or
    -- if it is a switch
    local header_type = newdev:read8(PCICONFIG_HEADER_TYPE)
    newdev.ismultifunction = bit64.btest(header_type, 0x80)
    newdev.isbridge = bit64.band(header_type, 0x7f) == 1
    if newdev.isbridge then
        -- Device is a bridge/switch. Assign bus numbers so we can
        -- scan for subordinate devices
        if newdev:read8(PCICONFIG_SECONDARY_BUS) == 0 then
            newdev:write8(PCICONFIG_PRIMARY_BUS, newdev.bus)
            root.last_bus = root.last_bus + 1
            newdev.busnum = root.last_bus
            newdev:write8(PCICONFIG_SECONDARY_BUS, newdev.busnum)
            -- Set to max value as we don't know how many busses are there
            newdev:write8(PCICONFIG_SUBORIDINATE_BUS, 0xff)
        else
            root.last_bus = newdev:read8(PCICONFIG_SECONDARY_BUS)
            newdev.busnum = root.last_bus
        end
        -- Scan for children
        newdev:scan()
        -- Update the last bus number now that we know how many busses
        -- were there
        if newdev:read8(PCICONFIG_SUBORIDINATE_BUS) == 0xff then
            newdev:write8(PCICONFIG_SUBORIDINATE_BUS, root.last_bus)
        else
            root.last_bus = newdev:read8(PCICONFIG_SUBORIDINATE_BUS)
        end
    end
    -- Return the device
    return newdev
end

--
-- Initialize a PCIe port and return a table of information about it.
--
function pcie.initialize(node, pcie_port)
    -- Initialize the PCIe link. Only do this for real PCIe ports.
    -- The internal ECAMs are at a fake port of 100+, so skip init
    -- on those
    if pcie_port < 100 then
        if cavium.c.bdk_pcie_rc_initialize(node, pcie_port) ~= 0 then
            error("bdk_pcie_rc_initialize() failed")
        end
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
        -- Get the top level bus number. The PCIe ports in Thunder
        -- are behind a "bridge" on the ECAM. In an effort not to confuse
        -- people, this enumeration code starts at the bus behind the
        -- "bridge".
        local max_device
        if pcie_port < 100 then
            -- Real ports only have one device connect, most likely a PCIe
            -- bridge. Bus number is programmed by software, read from
            -- hardware
            self.last_bus = cavium.csr[self.node].PCIERCX_CFG006(self.port).SBNUM
            max_device = 0
        else
            -- Internal ECAMs all start at 0 and have multiple devices
            self.last_bus = 0
            max_device = 31
        end
        local bus = self.last_bus
        for dev=0,max_device do
            local device = create_device(self, bus, dev, 0)
            if device then
                table.insert(self.devices, device)
                -- Device is mulifunction so scan the other functions
                if device.ismultifunction then
                    for func = 1,7 do
                        -- Try and create a device
                        device = create_device(self, bus, dev, func)
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
        if self.port >= 100 then
            -- Internal ECAMs have fixed resource, so no enumeration is needed
            return
        end
        -- Perform a scan if it hasn't already been done
        if #self.devices == 0 then
            self:scan()
        end
        local io_address = self.port * 0x10000 -- 64KB of IO per PEM
        local mem_address = 0x10000000 -- Normal mem starts at 256MB
        local pmem_address = 0x1000000000 -- Prefetch starts at 64GB
        -- Assign resources to all top level devices
        for _,device in ipairs(self.devices) do
            io_address, mem_address, pmem_address = device:enumerate(io_address, mem_address, pmem_address)
        end
    end

    --
    -- Display all devices on the bus
    --
    function pcie_root:display()
        if self.port < 100 then
            printf("PCIe port %d:\n", self.port)
        else
            printf("Internal ECAM%d:\n", self.port - 100)
        end
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


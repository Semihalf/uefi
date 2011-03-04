--
-- Lua module supporting PCIe
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
--

require("strict")
require("utils")

local c_func
local csr
if isglobal("octeon") then
    -- We're running natively on Octeon
    c_func = octeon.c
    csr = octeon.csr
else
    -- We're running remotely. Assume arg[1] is where we should connect to
    local rpc = require("rpc")
    local remote = rpc.connect(arg[1])
    c_func = remote.octeon.c
    csr = remote.octeon.csr
end

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

--
-- This function creates a table representing a PCIe device. It reads
-- the VENDOR and DEVICE ID. If these are undefined it returns nil as the
-- device doesn't exist.
--
local function create_device(root, bus, deviceid, func)
    local device = {}
    device.config = {}
    device.root = root
    device.bus = bus
    device.deviceid = deviceid
    device.func = func

    --
    -- PCIe config space reads
    --
    function device.config.read8(reg)
        return bit32.AND(c_func.bdk_pcie_config_read8(device.root.port, device.bus, device.deviceid, device.func, reg), 0xff)
    end
    function device.config.read16(reg)
        return bit32.AND(c_func.bdk_pcie_config_read16(device.root.port, device.bus, device.deviceid, device.func, reg), 0xffff)
    end
    function device.config.read32(reg)
        return bit32.AND(c_func.bdk_pcie_config_read32(device.root.port, device.bus, device.deviceid, device.func, reg), 0xffffffff)
    end

    --
    -- PCIe config space writes
    --
    function device.config.write8(reg, val)
        c_func.bdk_pcie_config_write8(device.root.port, device.bus, device.deviceid, device.func, reg, val)
    end
    function device.config.write16(reg, val)
        c_func.bdk_pcie_config_write16(device.root.port, device.bus, device.deviceid, device.func, reg, val)
    end
    function device.config.write32(reg, val)
        c_func.bdk_pcie_config_write32(device.root.port, device.bus, device.deviceid, device.func, reg, val)
    end

    --
    -- Scan for devices behind this one on a subordinate bus. The scan is
    -- recursive.
    --
    function device:scan()
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
                        device = create_device(self.root, self.busnum, deviceid, 0)
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
    -- Assign resources to the device
    --
    function device:enumerate(start_address)
    end

    --
    -- Display a device and all children
    --
    function device:display(indent)
        if not indent then
            indent = ""
        end
        local t = device.config.read32(PCICONFIG_CLASS_CODE_REV_ID)
        printf("%s%d:%d.%d Class:%06x Vendor:%04x Device:%04x (Rev %02x)\n",
            indent,
            self.bus,
            self.deviceid,
            self.func,
            bit32.SAR(t, 8),
            device.config.read16(PCICONFIG_VENDOR_ID),
            device.config.read16(PCICONFIG_DEVICE_ID),
            bit32.AND(t, 0xff))
        printf("%s    Command:%04x Status:%04x\n",
            indent,
            device.config.read16(PCICONFIG_COMMAND),
            device.config.read16(PCICONFIG_STATUS))
        printf("%s    Cache Line Size:%02x Master Latency Timer:%02x Header Type:%02x BIST:%02x\n",
            indent,
            device.config.read8(PCICONFIG_CACHE_LINE_SIZE),
            device.config.read8(PCICONFIG_MASTER_LT),
            device.config.read8(PCICONFIG_HEADER_TYPE),
            device.config.read8(PCICONFIG_BIST))
        printf("%s    Cardbus CIS Pointer:%08x\n",
            indent,
            device.config.read32(PCICONFIG_CARDBUS_CIS))
        printf("%s    Subsystem Vendor:%04x Device:%04x\n",
            indent,
            device.config.read16(PCICONFIG_SUBVENDOR_ID),
            device.config.read16(PCICONFIG_SUBDEVICE_ID))
        printf("%s    Expansion ROM:%08x\n",
            indent,
            device.config.read32(PCICONFIG_ROM))
        printf("%s    Capabilities Pointer:%02x\n",
            indent,
            device.config.read8(PCICONFIG_CAP_PTR))
        printf("%s    Interrupt Line:%02x Interrupt Pin:%02x Min Grant:%02x Max Latency:%02x\n",
            indent,
            device.config.read8(PCICONFIG_INT_LINE),
            device.config.read8(PCICONFIG_INT_PIN),
            device.config.read8(PCICONFIG_MIN_GNT),
            device.config.read8(PCICONFIG_MAX_LAT))
        local max_bar = PCICONFIG_CARDBUS_CIS
        if self.isbridge then
            max_bar = PCICONFIG_PRIMARY_BUS
        end
        local bar = PCICONFIG_BAR0
        local barno = 0
        while bar < max_bar do
            local v = device.config.read32(bar)
            local ismem = not bit32.TEST(v, 1)
            local is64 = ismem and bit32.TEST(v, 4)
            if is64 then
                v = device.config.read32(bar+4) * 2^32 + v
                printf("%s    BAR%d: %016x\n", indent, barno, v)
                bar = bar + 8
            else
                printf("%s    BAR%d: %08x\n", indent, barno, v)
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
    device.did = device.config.read32(PCICONFIG_VENDOR_ID)
    -- Fail create if device didn't respond
    if device.did == 0xffffffff then
        return nil
    end
    -- printf("PCICONFIG_VENDOR_ID(port=%d, bus=%d, deviceid=%d, func=%d) 0x%x\n", device.root.port, device.bus, device.deviceid, device.func, device.did)

    -- Figure out if the device supports multiple functions and/or
    -- if it is a switch
    local header_type = device.config.read8(PCICONFIG_HEADER_TYPE)
    device.ismultifunction = bit32.TEST(header_type, 0x80)
    device.isbridge = bit32.AND(header_type, 0x7f) == 1
    if device.isbridge then
        -- Device is a bridge/switch. Assign bus numbers so we can
        -- scan for subordinate devices
        device.config.write8(PCICONFIG_PRIMARY_BUS, device.bus)
        root.last_bus = root.last_bus + 1
        device.busnum = root.last_bus
        device.config.write8(PCICONFIG_SECONDARY_BUS, device.busnum)
        -- Set to max value as we don't know how many busses are there
        device.config.write8(PCICONFIG_SUBORIDINATE_BUS, 0xff)
        -- Scan for children
        device:scan()
        -- Update the last bus number now that we know how many busses
        -- were there
        device.config.write8(PCICONFIG_SUBORIDINATE_BUS, root.last_bus)
    end
    -- Return the device
    return device
end

--
-- Initialize a PCIe port and return a table of information about it.
--
function pcie.initialize(pcie_port)
    -- Initialize the PCIe link
    if c_func.bdk_pcie_rc_initialize(pcie_port) ~= 0 then
        error("bdk_pcie_rc_initialize() failed")
    end

    -- Create the root table for storing information
    local pcie_root = {}
    pcie_root.port = pcie_port
    pcie_root.last_bus = 0
    pcie_root.devices = {}

    --
    -- Scan the PCIe bus and find all devices
    --
    function pcie_root:scan()
        self.devices = {}
        -- Get the top level bus number
        self.last_bus = csr.PCIERCX_CFG006(self.port).PBNUM
        -- Read device zero, which must exist per PCIe spec
        local device = create_device(self, self.last_bus, 0, 0)
        if not device then
            error("Unable to find first PCIe device")
        end
        table.insert(self.devices, device)
        -- Device is mulifunction so scan the other functions
        if device.ismultifunction then
            for func = 1,7 do
                -- Try and create a device
                device = create_device(self, self.last_bus, 0, func)
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

    --
    -- Enumerate and assign resources.
    --
    function pcie_root:enumerate()
        -- Perform a scan if it hasn't already been done
        if #self.devices == 0 then
            self:scan()
        end
        local start_address = 0xf0000000
        -- Assign resources to all top level devices
        for _,device in ipairs(self.devices) do
            start_address = device:enumerate(start_address)
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
        local status = c_func.bdk_pcie_rc_shutdown(self.port)
        if status ~= 1 then
            error("bdk_pcie_rc_shutdown() failed")
        end
    end

    return pcie_root
end

if not isglobal("octeon") then
    for port = 0,1 do
        local pcie_root = pcie.initialize(port)
        pcie_root:enumerate()
        pcie_root:display()
    end
end


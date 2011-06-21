--
-- Lua module supporting SRIO
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
--

require("strict")
require("utils")
require("octeon")

-- This is the table we use to contain the module
srio = {}
srio.debug = false
srio.debug_maint = false

local IS16BIT = 0
local ANY_ID = 0xff
local UNUSED_HOP = 0xff

-- Local variables to cache C functions to save RPC calls
local bdk_srio_initialize = octeon.c.bdk_srio_initialize
local bdk_srio_config_read32 = octeon.c.bdk_srio_config_read32
local bdk_srio_config_write32 = octeon.c.bdk_srio_config_write32
local bdk_wait_usec = octeon.c.bdk_wait_usec

-- These are fixed MAINT register addresses from the SRIO spec
local CAR_DEVICE_ID = 0x00
local CAR_ASSEMBLY_INFO = 0x0c
local CAR_PE_FEAT = 0x10
local CAR_SWITCH_PORT = 0x14
local CAR_SWITCH_ROUTE_LIMIT = 0x34
local CAR_BASE_DEVICE_ID = 0x60
local CAR_HOST_LOCK = 0x68
local CAR_SWITCH_ROUTE_DID = 0x70
local CAR_SWITCH_ROUTE_PORT = 0x74
local CAR_SWITCH_ROUTE_DEFAULT = 0x78
local CAR_PORT_0_ERROR_STATUS = 0x58
local CAR_PORT_0_CONTROL = 0x5c
local CAR_PORT_INC = 0x7c - 0x5c

local function dprintf(...)
    if srio.debug then
        printf(...)
    end
end

--
-- The SRIO spec numbers bits opposite of Octeon's normal standard. This
-- function tests if a bit is set based on the spec numbering so that the
-- magic bit numbers in the code match what is found in the spec.
--
local function test_spec_bit(data, bit)
    return bit64.btest(data, bit64.lshift(1, 31-bit))
end

--
-- Perform a MAINT read and return the result. Failures throw errors.
--
local function maint_read(srio_root, devid, hopcount, maint)
    if hopcount == -1 then
        -- Talking to the local Octeon port
        devid = -1
        hopcount = 0
    elseif devid ~= ANY_ID then
        -- Hop count needs to be max when talking to a specific device
        assert(hopcount == UNUSED_HOP, "Illegal hopcount for specific device")
    end
    if srio.debug_maint then
        printf("MAINT READ devid=%d, hop=%d, maint=0x%x = ", devid, hopcount, maint)
    end
    local result = bdk_srio_config_read32(srio_root.port, 0, devid, IS16BIT, hopcount, maint)
    if srio.debug_maint then
        printf("0x%08x\n", result)
    end
    assert(result ~= -1, "MAINT read failed")
    return result
end

--
-- Perform a MAINT write. Failures throw errors.
--
local function maint_write(srio_root, devid, hopcount, maint, value)
    if hopcount == -1 then
        -- Talking to the local Octeon port
        devid = -1
        hopcount = 0
    elseif devid ~= ANY_ID then
        -- Hop count needs to be max when talking to a specific device
        assert(hopcount == UNUSED_HOP, "Illegal hopcount for specific device")
    end
    if srio.debug_maint then
        printf("MAINT WRITE devid=%d, hop=%d, maint=0x%x value=0x%x\n", devid, hopcount, maint, value)
    end
    local result = bdk_srio_config_write32(srio_root.port, 0, devid, IS16BIT, hopcount, maint, value)
    assert(result ~= -1, "MAINT write failed")
end

local function device_lock(srio_root, devid, hopcount)
    -- Read the current lock
    local lock = maint_read(srio_root, devid, hopcount, CAR_HOST_LOCK)
    assert(lock ~= 0xffffffff, "Illegal read response for lock read")
    if lock == srio_root.host_id then
        dprintf("        Device already visited\n")
        return 1
    end

    if lock ~= 0xffff then
        dprintf("        Waiting for lock to be released by 0x%x\n", lock)
    end

    repeat
        -- Wait for the lock to be available
        while lock ~= 0xffff do
            lock = maint_read(srio_root, devid, hopcount, CAR_HOST_LOCK)
            assert(lock ~= 0xffffffff, "Illegal read response for lock read")
        end
        -- Attempt to get the lock
        maint_write(srio_root, devid, hopcount, CAR_HOST_LOCK, srio_root.host_id)
        -- Read and make sure we got the lock
        lock = maint_read(srio_root, devid, hopcount, CAR_HOST_LOCK)
        assert(lock ~= 0xffffffff, "Illegal read response for lock read")
    until lock == srio_root.host_id
    return 0
end

local function device_unlock(srio_root, devid, hopcount)
    -- Make sure I currently own the lock
    local lock = maint_read(srio_root, devid, hopcount, CAR_HOST_LOCK)
    assert(lock == srio_root.host_id, "Device not locked by me")

    -- Release the lock
    maint_write(srio_root, devid, hopcount, CAR_HOST_LOCK, srio_root.host_id)

    -- Make sure the lock was released
    lock = maint_read(srio_root, devid, hopcount, CAR_HOST_LOCK)
    assert(lock ~= srio_root.host_id, "Device won't unlock")
end

--
-- Search the feature blocks and find the one specified by feature_id.
-- Raises an error if any error happens or the block can't be found.
--
local function get_feature_block(srio_root, devid, hopcount, feature_id)
    -- Make sure the extended features are available
    local feat = maint_read(srio_root, devid, hopcount, CAR_PE_FEAT)
    if not test_spec_bit(feat, 28) then
        error("Extended features not supported")
    end

    -- Search the extended features looking for feature_id
    local data = maint_read(srio_root, devid, hopcount, CAR_ASSEMBLY_INFO)
    local efp = bit64.band(data, 0xffff)
    while efp ~= 0 do
        local data = maint_read(srio_root, devid, hopcount, efp)
        -- We're looking for a nine
        if bit64.band(data, 0xffff) == feature_id then
            break
        end
        efp = bit64.rshift(data, 16)
    end

    -- Fail if we can't find the extended port info
    if efp == 0 then
        error("Extended feature port not found")
    end
    return efp
end

--
-- Check the link status of a specific port on a SRIO switch.
-- Return is zero if the link is down, or the number of lanes for
-- a working link.
--
local function is_link_up(srio_root, devid, hopcount, link_port)
    -- Search the extended features looking for port status
    local efp = get_feature_block(srio_root, devid, hopcount, 0x9)
    -- Read the port's state
    local data = maint_read(srio_root, devid, hopcount, efp + CAR_PORT_0_ERROR_STATUS + link_port * CAR_PORT_INC)
    if  not test_spec_bit(data, 30) then
        return false
    end

    -- Read the port width
    data = maint_read(srio_root, devid, hopcount, efp + CAR_PORT_0_CONTROL + link_port * CAR_PORT_INC)
    data = bit64.rshift(data, 31-4)
    data = bit64.band(data, 3)
    if data == 0 then
        return 1    -- One lane
    elseif data == 1 then
        return 1    -- One lane
    elseif data == 2 then
        return 4    -- Four lanes
    elseif data == 3 then
        return 2    -- Two lanes
    else
        return false    -- Unkown lane encoding, say link down
    end
end


--
-- Set the SRIO input and output enables
--
local function set_srio_enables(srio_root, devid, hopcount, feature_id, port)
    -- Search the extended features looking for generic endpoint device
    local efp = get_feature_block(srio_root, devid, hopcount, feature_id)
    local data = maint_read(srio_root, devid, hopcount, efp + CAR_PORT_0_CONTROL + port * CAR_PORT_INC)
    assert(test_spec_bit(data, 31), "Port 0 control isn't SRIO")
    data = bit64.bor(data, bit64.lshift(1, 22)) -- Output enable
    data = bit64.bor(data, bit64.lshift(1, 21)) -- Input enable
    maint_write(srio_root, devid, hopcount, efp + CAR_PORT_0_CONTROL + port * CAR_PORT_INC, data)
end

--
-- Program switch route table
--
local function switch_setup_routes(srio_root, hopcount, routes, default_route)
    -- Read the switch features
    local pe_feat = maint_read(srio_root, ANY_ID, hopcount, CAR_PE_FEAT)

    -- Read the number of route table entries
    local data = maint_read(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_LIMIT)
    local max_routes = bit64.band(data, 0xffff) + 1

    -- Use the extended route writes if supported
    if test_spec_bit(pe_feat, 22) then
        -- Program four entries at a time
        for id = 0, max_routes-1, 4 do
            maint_write(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_DID, bit64.bor(id, 0x80000000))
            local route
            if routes[id] then
                route = routes[id]
            else
                route = default_route
            end
            if routes[id+1] then
                route = bit64.bor(route, bit64.lshift(routes[id+1], 8))
            else
                route = bit64.bor(route, bit64.lshift(default_route, 8))
            end
            if routes[id+2] then
                route = bit64.bor(route, bit64.lshift(routes[id+2], 16))
            else
                route = bit64.bor(route, bit64.lshift(default_route, 16))
            end
            if routes[id+3] then
                route = bit64.bor(route, bit64.lshift(routes[id+3], 24))
            else
                route = bit64.bor(route, bit64.lshift(default_route, 24))
            end
            maint_write(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_PORT, route)
        end
    else
        -- Program one entrie at a time
        for id = 0, max_routes-1 do
            maint_write(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_DID, id)
            local route
            if routes[id] then
                route = routes[id]
            else
                route = default_route
            end
            maint_write(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_PORT, route)
        end
    end

    -- Set the default route to the device port
    maint_write(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_DEFAULT, default_route)
end

--
-- Setup the route for a switch such that two addresses are valid. Messages
-- destine to me come to my port, all other messages go to the device port.
--
local function switch_setup_scan_routes(srio_root, hopcount, my_port, device_port)
    local routes = {}
    routes[srio_root.host_id] = my_port
    switch_setup_routes(srio_root, hopcount, routes, device_port)
end

--
-- Setup the final routes after all devices conencted to the switch are enumerated
--
local function switch_setup_final_routes(srio_root, hopcount, device)
    local routes = {}
    local function recurse_devices(device)
        for p,d in pairs(device.port_connections) do
            routes[d.devid] = p
            recurse_devices(d)
        end
    end
    recurse_devices(device)
    switch_setup_routes(srio_root, hopcount, routes, device.parent_port)
end

--
-- Create a new SRIO device structure
--
local function create_device(srio_root, hopcount)
    local device = {}
    device.devid = ANY_ID
    device.hopcount = hopcount
    device.parent_port = nil
    device.port_connections = {}
    device.ident = maint_read(srio_root, ANY_ID, hopcount, CAR_DEVICE_ID)
    assert(device.ident ~= 0xffffffff, "Device didn't respond to CAR_DEVICE_ID read")

    --
    -- Dispaly a device and all other devices connected to it
    --
    function device:display(prefix)
        if prefix == nil then
            prefix = ""
        end
        if device.parent_port then
            printf("%sSwitch\n", prefix)
            printf("%s  Parent is on port %d\n", prefix, device.parent_port)
        elseif device.devid == ANY_ID then
            printf("%sUnenumerated device\n", prefix)
        else
            local data
            if hopcount == -1 then
                data = maint_read(srio_root, -1, hopcount, CAR_BASE_DEVICE_ID)
            else
                data = maint_read(srio_root, device.devid, UNUSED_HOP, CAR_BASE_DEVICE_ID)
            end
            local devid8 = bit64.band(bit64.rshift(data, 16), 0xff)
            local devid16 = bit64.band(data, 0xffff)
            printf("%sDevice 0x%x (8bit) 0x%x (16bit)\n", prefix, devid8, devid16)
        end
        printf("%s  ID 0x%08x\n", prefix, device.ident)
        for p,d in pairs(device.port_connections) do
            printf("%s  Port %d\n", prefix, p)
            d:display(prefix .. "    ")
        end
    end

    --
    -- Scan the device looking for devices connected to it
    --
    function device:scan()
        -- lock the device so we can make changes needed for the scan
        local lock_state = device_lock(srio_root, ANY_ID, hopcount)
        if lock_state == 1 then
            return
        end

        local feat = maint_read(srio_root, ANY_ID, hopcount, CAR_PE_FEAT)
        if not test_spec_bit(feat, 3) then
            dprintf("Device is not a switch\n")
            device_unlock(srio_root, ANY_ID, hopcount)
            return
        end
        dprintf("Device is a switch\n")

        -- Make sure the switch implements a standard routing table
        if not test_spec_bit(feat, 23) then
            dprintf("        Unknown switch table. skipping\n")
            device_unlock(srio_root, ANY_ID, hopcount)
            return
        end

        -- Tell the user if extended routing table operations are supported
        if test_spec_bit(feat, 22) then
            dprintf("        Device has a extended route table\n")
        end

        -- Determine the number of entries in the routing table
        local data = maint_read(srio_root, ANY_ID, hopcount, CAR_SWITCH_ROUTE_LIMIT)
        local max_routes = bit64.band(data, 0xffff) + 1
        dprintf("        Route table has %d entries\n", max_routes)

        -- Determine the number of ports on the switch
        data = maint_read(srio_root, ANY_ID, hopcount, CAR_SWITCH_PORT);
        device.parent_port = bit64.band(data, 0xff);
        local num_sw_port = bit64.band(bit64.rshift(data, 8), 0xffff);
        dprintf("        Scanning from port %d, switch has %d ports\n", device.parent_port, num_sw_port)

        -- Loop through all ports and enumerate devices connected to them
        for port=0, num_sw_port-1 do
            -- Skip the port we came in on
            if port ~= device.parent_port then
                -- Report the switch port link status
                dprintf("    Port %d - ", port)
                local link = is_link_up(srio_root, ANY_ID, hopcount, port)
                if link then
                    dprintf("%d lanes", link)
                    -- Setup switch routes to allow us to access this port
                    switch_setup_scan_routes(srio_root, hopcount, device.parent_port, port)
                    -- Scan the device connected to this port
                    local lock = maint_read(srio_root, ANY_ID, hopcount+1, CAR_HOST_LOCK)
                    if lock ~= srio_root.host_id then
                        dprintf(", new device\n")
                        local d = create_device(srio_root, hopcount+1)
                        device.port_connections[port] = d
                        d:scan()
                    else
                        dprintf(", already visited\n")
                    end
                else
                    dprintf("Down\n");
                end
            end
            -- Set the SRIO input and output enables for this switch port
            set_srio_enables(srio_root, ANY_ID, hopcount, 0x9, port)
        end
        device_unlock(srio_root, ANY_ID, hopcount)
    end

    --
    -- Assign device ID to the device and all devices connected to it
    --
    function device:enumerate()
        -- lock the device so we can make changes needed for the enumeration
        local lock_state = device_lock(srio_root, ANY_ID, hopcount)
        assert(lock_state == 0, "Locking device failed")

        -- Don't assign device IDs to switches as they don't use them
        if not device.parent_port then
            device.devid = srio_root.free_id
            srio_root.free_id = srio_root.free_id + 1
            -- Set our device ID, which is also used as our host ID for locks
            dprintf("Assigning device id 0x%x to hopcount=%d\n", device.devid, hopcount);
            local my_id = device.devid + bit64.lshift(device.devid, 16)
            maint_write(srio_root, ANY_ID, hopcount, CAR_BASE_DEVICE_ID, my_id)
            if hopcount == -1 then
                -- My local device must be treated as a special case
                local readback = maint_read(srio_root, -1, hopcount, CAR_BASE_DEVICE_ID)
                assert(readback == my_id, "Read back of programmed device ID failed")
            else
                local readback = maint_read(srio_root, device.devid, UNUSED_HOP, CAR_BASE_DEVICE_ID)
                assert(readback == my_id, "Read back of programmed device ID failed")
            end

            -- Set the SRIO input and output enables. Skip the local device as
            -- SRIO init already set the enables
            if hopcount > -1 then
                set_srio_enables(srio_root, device.devid, UNUSED_HOP, 0x1, 0)
            end
        end

        -- Iterate through all sub devices
        for p,d in pairs(device.port_connections) do
            if hopcount ~= -1 then
                switch_setup_scan_routes(srio_root, hopcount, device.parent_port, p)
            end
            d:enumerate()
        end
        if device.parent_port then
            switch_setup_final_routes(srio_root, hopcount, device)
            device_unlock(srio_root, ANY_ID, hopcount)
        else
            if hopcount == -1 then
                -- My local device must be treated as a special case
                device_unlock(srio_root, -1, hopcount)
            else
                device_unlock(srio_root, device.devid, UNUSED_HOP)
            end
        end
    end
    return device
end

--
-- Initialize a SRIO port
--
function srio.initialize(srio_port)
    if bdk_srio_initialize(srio_port, 0) ~= 0 then
        error("bdk_srio_initialize() failed")
    end
    -- Create the root table for storing information
    local srio_root = {}
    srio_root.port = srio_port
    srio_root.device = nil
    srio_root.host_id = srio_port
    srio_root.free_id = srio_root.host_id
    -- Set our device ID, which is also used as our host ID for locks
    local my_id = srio_root.port + bit64.lshift(srio_root.port, 16)
    maint_write(srio_root, ANY_ID, -1, CAR_BASE_DEVICE_ID, my_id)

    --
    -- Function to call to find all devices on a SRIO port
    --
    function srio_root:scan()
        -- Create a device for ourselves that is zero hops away
        srio_root.device = create_device(srio_root, -1)
        -- Create another device for one hop away
        local device = create_device(srio_root, 0)
        device:scan()
        -- Add the device as being off my port 0
        srio_root.device.port_connections[0] = device
    end

    --
    -- Function to call to assign device IDs for all devices and program
    -- switch tables
    --
    function srio_root:enumerate()
        if not srio_root.device then
            srio_root:scan()
        end
        srio_root.device:enumerate()
    end

    --
    -- Display all the devices connected to a SRIO port
    --
    function srio_root:display()
        printf("SRIO port %d:\n", self.port)
        self.device:display()
    end

    return srio_root
end

return srio



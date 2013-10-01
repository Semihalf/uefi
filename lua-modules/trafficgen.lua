--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--
require("strict")
require("utils")
local readline = require("readline")
local node = 0

local GOTO_TOP      = "\27[1;1H"   -- ESC[1;1H begins output at the top of the terminal (line 1)
local GOTO_BOTTOM   = "\27[100;1H" -- ESC[1;1H begins output at the bottom of the terminal (actually line 100)
local GOTO_BOL      = "\27[100D"   -- Go to beginning of line
local ERASE_EOL     = "\27[0K"     -- Erase to end of line
local ERASE_EOS     = "\27[0J"     -- Erase to end screen
local ERASE_WIN     = "\27[2J"     -- Erase the window
local REVERSE       = "\27[7m"     -- Reverse the display
local NORMAL        = "\27[0m"     -- Normal display
local NONZEROHI     = "\27[33m"    -- Yellow used for non zero rows
local ZEROHI        = "\27[32m"    -- Green used for zero rows
local SCROLL_FULL   = "\27[1;r"    -- Normal full-screen scrolling for statistics region
local CURSOR_ON     = "\27[?25h"   -- Turn on cursor
local CURSOR_OFF    = "\27[?25l"   -- Turn off cursor

local ALIASES = {
    ["F1"]="help",
    ["F9"]="validate all on",
    ["F10"]="stop all",
    ["F11"]="start default",
    ["F12"]="stop default",
    ["PageUp"]="clear all",
    ["PageDown"]="clear default",
}

local TrafficGen = {}
function TrafficGen.new()
    local self = {}
    --
    -- Private variables
    --
    local known_ports = octeon.trafficgen.get_port_names()
    local visible_ports = {}
    local default_ports = {}
    local is_running = true
    local use_readline = true
    local last_display = 0
    local transmit_start = 0
    local transmit_time = 0
    local l2_stats_table = {}
    local show_l2_stats = false

    --
    -- Public variables
    --

    --
    -- Private Methods
    --

    -- Parse a port list string
    local function parse_port_list(str)
        local ports = {}
        local index = 1
        local start_name = nil
        str = str:upper()
        while index <= #str do
            local name, sep = str:match("^([A-Za-z0-9.]+)([,-]?)", index)
            if not name then
                return nil
            end
            index = index + #name + #sep
            if sep == "-" then
                start_name = name
            else
                local stop_name = name
                if not start_name then
                    start_name = stop_name
                end
                local in_range = false
                for _,port in ipairs(known_ports) do
                    if port == start_name then
                        in_range = true
                    end
                    if in_range then
                        table.insert(ports, port)
                    end
                    if port == stop_name then
                        in_range = false
                    end
                end
                start_name = nil
            end
        end
        if #ports == 0 then
            return nil
        else
            return ports
        end
    end

    local function do_update(zero_stats)
        local stats = octeon.trafficgen.update(zero_stats)
        local labels = stats.labels
        stats.labels = nil
        local result = {}
        for p,s in pairs(stats) do
            result[p] = {}
            for i=1, #labels do
                result[p][labels[i]] = s[i]
            end
        end
        return result
    end

    -- Parse a command line into a command, a port range, and arguments
    local function parse_command(str)
        local SPECIAL_WORDS = {["true"]=true, ["false"]=false, ["on"]=true, ["off"]=false}
        local command
        local range
        local args = {}
        local word_num = 0
        for word in str:gmatch("[^ ]+") do
            word_num = word_num + 1
            if word_num == 1 then
                for _,prefix in ipairs({"cmdp_", "cmd_"}) do
                    command = prefix .. word
                    if type(self[command]) == "function" then
                        break;
                    end
                end
            elseif word_num == 2 then
                if command:sub(1,5) == "cmdp_" then
                    if word == "all" then
                        range = known_ports
                    elseif word == "default" then
                        range = default_ports
                    else
                        range = parse_port_list(word)
                        if range == nil then
                            if SPECIAL_WORDS[word] ~= nil then
                                table.insert(args, SPECIAL_WORDS[word])
                            else
                                table.insert(args, word)
                            end
                        end
                    end
                elseif SPECIAL_WORDS[word] ~= nil then
                    table.insert(args, SPECIAL_WORDS[word])
                else
                    table.insert(args, word)
                end
            elseif SPECIAL_WORDS[word] ~= nil then
                table.insert(args, SPECIAL_WORDS[word])
            else
                table.insert(args, word)
            end
        end
        if range == nil then
            if command:sub(1,5) == "cmdp_" then
                range = default_ports
            end
        end
        return command, range, args
    end

    local zero_hide = {
        rx_backpressure=-5,
        rx_dropped_octets=-5,
        rx_dropped_packets=-5,
        rx_errors=-5,
        rx_validation_errors=-5,
    }
    -- Display a single statistic line
    local function display_stat(stat_name, stats)
        local totals = 0
        for _,p in ipairs(visible_ports) do
            totals = totals + stats[p][stat_name]
        end
        local color = NORMAL
        if zero_hide[stat_name] then
            if totals == 0 then
                if zero_hide[stat_name] + 5 < os.time() then
                    return 0
                end
                color = ZEROHI
            else
                zero_hide[stat_name] = os.time()
                color = NONZEROHI
            end
        end
        local COL_SEP = ZEROHI .. "|" .. color
        local is_bits = stat_name:sub(-5,-1) == "_bits"
        if is_bits then
            printf(color .. "%-20s", stat_name:sub(1,-6) .. " Mbps")
        else
            printf(color .. "%-20s", stat_name:gsub("_", " "))
        end
        for _,p in ipairs(visible_ports) do
            local v = stats[p][stat_name]
            if is_bits then
                v = v / 1000000
            end
            printf("%s%10s", COL_SEP, v)
        end
        if is_bits then
            totals = totals / 1000000
        end
        printf("%s%10d%s%s\n", COL_SEP, totals, NORMAL, ERASE_EOL)
        return 1
    end

    -- Create commands for getting and setting each value in the port config
    -- structure.
    local function create_config_commands()
        local config = octeon.trafficgen.get_config(known_ports[1])
        -- Add in sorted order
        for _,field_name in ipairs(table.sorted_keys(config)) do
            self["cmdp_" .. field_name] = function (self, port_range, args)
                for _, port in pairs(port_range) do
                    if #args == 1 then
                        octeon.trafficgen.set_config(port, {[field_name]=args[1]})
                    else
                        local config = octeon.trafficgen.get_config(port)
                        printf("Port %s: %s = %s\n", port, field_name, tostring(config[field_name]))
                    end
                end
            end
        end
    end
    create_config_commands()

    -- Create commands for getting each value in the port statistics.
    local function create_stats_commands()
        local stats = do_update(false)
        local stat_names = stats[known_ports[1]]
        -- Add in sorted order
        for _,field_name in ipairs(table.sorted_keys(stat_names)) do
            self["cmdp_" .. field_name] = function (self, port_range, args)
                local stats = do_update(false)
                for _, port in pairs(port_range) do
                    printf("Port %s: %s = %s\n", port, field_name, tostring(stats[port][field_name]))
                end
            end
        end
    end
    create_stats_commands()

    --
    -- Public Methods
    --

    -- Print a list of all commands
    function self:cmd_help(port_range, args)
        local commands = {}
        for k in pairs(ALIASES) do
            table.insert(commands, "<" .. k .. ">=\"" .. ALIASES[k] .. "\"")
        end
        for k in pairs(self) do
            if k:sub(1,4) == "cmd_" then
                table.insert(commands, k:sub(5))
            end
            if k:sub(1,5) == "cmdp_" then
                table.insert(commands, k:sub(6))
            end
        end
        table.sort(commands)
        local clm = (#commands+2)/3
        for i=1,clm do
            if commands[i] then
                printf("%-27s ", commands[i])
            end
            if commands[i+clm] then
                printf("%-27s ", commands[i+clm])
            end
            if commands[i+clm*2] then
                printf("%-27s ", commands[i+clm*2])
            end
            printf("\n")
        end
        print()
        print("Most commands take an optional port range.  The port range is")
        print("specified as a series of names separated by commas or dashes.")
        print("Dashes include all ports between the named ports.  No spaces")
        print("are allowed in a port range. Some example port ranges are")
        print("\"SGMII00-SGMII03\", \"XAUI00,XAUI10\", and \"LOOP00-LOOP03\".")
        print("When not specified, the port range is taken from the range")
        print("given in the last \"default\" command.  For a full list of the")
        print("supported port names, type the command \"default all\".")
    end

    -- Select which ports to used by default
    function self:cmdp_default(port_range, args)
        assert (#args == 0, "No arguments expected")

        default_ports = port_range

        printf("Default ports:")
        for _,port in ipairs(default_ports) do
            printf(" %s", port)
        end
        printf("\n")
    end

    -- Quit the main run() loop
    function self:cmd_quit(port_range, args)
        assert (#args == 0, "No arguments expected")
        is_running = false
    end

    -- Enable/disable readline so scripting can be easier
    function self:cmd_readline(port_range, args)
        assert (#args == 1, "One argument expected (on/off)")
        use_readline = args[1]
    end

    function self:cmdp_start(port_range, args)
        assert (#args == 0, "No arguments expected")
        octeon.trafficgen.start(port_range)
    end

    function self:cmdp_stop(port_range, args)
        assert (#args == 0, "No arguments expected")
        octeon.trafficgen.stop(port_range)
    end

    function self:cmdp_show(port_range, args)
        assert (#args == 0, "No arguments expected")
        -- FIXME: Do union
        visible_ports = port_range
    end

    function self:cmdp_hide(port_range, args)
        assert (#args == 0, "No arguments expected")
        -- FIXME: Do intersection
        visible_ports = {}
        printf(SCROLL_FULL .. GOTO_BOTTOM)
    end

    function self:cmdp_clear(port_range, args)
        assert (#args == 0, "No arguments expected")
        octeon.trafficgen.clear(port_range)
    end

    function self:cmdp_reset(port_range, args)
        assert (#args == 0, "No arguments expected")
        octeon.trafficgen.reset(port_range)
    end

    function self:cmdp_loopback(port_range, args)
        assert (#args == 1, "Argument expected, either INTERNAL, EXTERNAL, INTERNAL+EXTERNAL, or NONE")
        for _,port in pairs(port_range) do
            octeon.trafficgen.set_loopback(port, args[1])
        end
    end

    function self:cmdp_tx_percent(port_range, args)
        for _,port in pairs(port_range) do
            if #args == 1 then
                octeon.trafficgen.set_config(port, {output_rate_is_mbps = true, output_rate = args[1] * 10})
            else
                local config = octeon.trafficgen.get_config(port)
                if config.output_rate_is_mbps then
                    printf("Port %s: %d Mbps\n", port, config.output_rate)
                else
                    printf("Port %s: %d packets/s\n", port, config.output_rate)
                end
            end
        end
    end

    function self:cmdp_tx_rate(port_range, args)
        for _,port in pairs(port_range) do
            if #args == 1 then
                octeon.trafficgen.set_config(port, {output_rate_is_mbps = false, output_rate = args[1]})
            else
                local config = octeon.trafficgen.get_config(port)
                if config.output_rate_is_mbps then
                    printf("Port %s: %d Mbps\n", port, config.output_rate)
                else
                    printf("Port %s: %d packets/s\n", port, config.output_rate)
                end
            end
        end
    end

    -- CSR access command only needed if we have a CSR database
    if octeon.csr then
        function self:cmd_csr(port_range, args)
            assert(args[1], "CSR name[.field] expected with optional value for write")
            local value = args[2]
            local dot = args[1]:find(".", 2, true)
            if dot then
                local name = args[1]:sub(1,dot-1):upper()
                local field = args[1]:sub(dot+1):upper()
                if value then
                    octeon.csr[name][field] = value
                else
                    local v = octeon.csr[name][field]
                    printf("%s.%s = %d (0x%x)\n", name, field, v, v)
                end
            else
                local name = args[1]:upper()
                if value then
                    octeon.csr.lookup(name).write(value)
                else
                    octeon.csr.lookup(name).display()
                end
            end
        end
    end

    function self:cmd_cls(port_range, args)
        assert (#args == 0, "No arguments expected")
        printf(ERASE_WIN .. GOTO_BOTTOM);
    end

    function self:cmd_reboot(port_range, args)
        assert (#args == 0, "No arguments expected")
        printf(SCROLL_FULL .. GOTO_BOTTOM)
        io.flush()
        octeon.c.bdk_reset_octeon(node)
    end

    function self:cmd_l2_stats(port_range, args)
        assert (#args == 1, "One argument expected, on or off")
        show_l2_stats = args[1]
    end

    function self:cmd_sleep(port_range, args)
        assert (#args == 1, "One argument expected, how long to sleep in seconds")
        printf("Sleeping for %d seconds\n", args[1])
        local timeout = os.time() + args[1]
        while os.time() < timeout do
            self:display(false)
        end
    end

    function self:cmdp_scan_sizes(port_range, args)
        -- Get the size of one FPA buffer
        local fpa_size = octeon.c.bdk_config_get(octeon.BDK_CONFIG_FPA_POOL_SIZE0)
        -- PKO can only handle a maximum of 63 segments. Each segment has
        -- 8 bytes to link to the next one
        local max_packet = 63 * (fpa_size - 8)
        -- IPD can't handle packets larger than 65524
        if max_packet > 65524 then
            max_packet = 65524
        end
        -- Get our setup params
        local output_count = 100
        local size_start = 60
        local size_stop = max_packet
        local size_incr = 1
        -- Get the latest statistics
        local all_stats = self:display(true)
        -- Start with current counts
        local expected_packets = 0
        local expected_octets = 0
        local expected_rx_errors = 0
        local expected_validation_errors = 0
        for _,port in ipairs(port_range) do
            if port:sub(1,5) == "HIGIG" then
                -- Higig has an extra 12 byte header, Higig2 has 16
                -- Reduce max size to allow space for max size header
                size_stop = max_packet - 16
            end
            expected_packets = expected_packets + all_stats[port].rx_packets_total
            expected_octets = expected_octets + all_stats[port].rx_octets_total
            expected_rx_errors = expected_rx_errors + all_stats[port].rx_errors
            expected_validation_errors = expected_validation_errors + all_stats[port].rx_validation_errors
        end

        -- Loop through the sizes
        local new_config = {output_count = output_count}
        for _,port in ipairs(port_range) do
            octeon.trafficgen.set_config(port, new_config)
        end
        new_config.output_count=nil
        for size=size_start,size_stop,size_incr do
            printf("Size %d\n", size)
            new_config.size = size;
            -- Setup TX and count how many packets we expect
            for _,port in ipairs(port_range) do
                octeon.trafficgen.set_config(port, new_config)
                expected_packets = expected_packets + output_count
                if (port:sub(1,4) == "LOOP") then
                    -- Loop doesn't have the 4 bytes of ethernet CRC
                    expected_octets = expected_octets + output_count * size
                else
                    -- Account for the extra 4 bytes of ethernet CRC
                    expected_octets = expected_octets + output_count * (size+4)
                end
            end
            -- Limit to five seconds per size
            local timeout = os.time() + 5
            -- Do the TX
            octeon.trafficgen.start(port_range)
            while octeon.trafficgen.is_transmitting(port_range) and (os.time() < timeout) do
                if octeon.global == nil then
                    -- Waiting for TX to be done
                    octeon.c.bdk_thread_yield();
                end
                -- Get the latest statistics
                self:display(false)
            end
            local rx_packets
            local rx_octets
            local rx_errors
            local validation_errors
            repeat
                if octeon.global == nil then
                    octeon.c.bdk_thread_yield();
                end
                -- Get the latest statistics
                all_stats = self:display(true)
                -- Count the amount of data received
                rx_packets = 0
                rx_octets = 0
                rx_errors = 0
                validation_errors = 0
                for _,port in ipairs(port_range) do
                    rx_packets = rx_packets + all_stats[port].rx_packets_total
                    rx_octets = rx_octets + all_stats[port].rx_octets_total
                    rx_errors = rx_errors + all_stats[port].rx_errors
                    validation_errors = validation_errors + all_stats[port].rx_validation_errors
                end
            until ((rx_packets >= expected_packets) and (rx_octets >= expected_octets)) or (os.time() >= timeout)
            -- Make sure we got the right amount of data
            if (rx_packets ~= expected_packets) or (rx_octets ~= expected_octets) then
                if os.time() >= timeout then
                    printf("Scan timeout\n")
                else
                    printf("Scan failed\n")
                end
                printf("RX packets %d, octets %d\n", rx_packets, rx_octets)
                printf("Expected packets %d, octets %d\n", expected_packets, expected_octets)
                printf("Delta packets %d, octets %d\n", expected_packets - rx_packets, expected_octets - rx_octets)
                break
            end
            if (rx_errors ~= expected_rx_errors) then
                printf("Scan failed due to RX errors\n")
                break
            end
            if (validation_errors ~= expected_validation_errors) then
                printf("Scan failed due to validation errors\n")
                break
            end
        end
    end

    -- Short aliases for common commands
    self.cmdp_count = self.cmdp_output_count
    -- This command is kept around for backwards compatibility
    self.cmdp_output_packet_size = self.cmdp_size

    -- Delete commands that were created based on fields that aren't useful
    self.cmdp_do_checksum = nil
    self.cmdp_output_enable = nil
    self.cmdp_output_rate = nil
    self.cmdp_output_rate_is_mbps = nil
    self.cmdp_ip_tos = nil

    -- Issue a traffic gen comamnd line
    function self:command(command_line)
        local command, port_range, args = parse_command(command_line)
        if type(self[command]) ~= "function" then
            printf("Invalid command \"%s\"\n", command)
        else
            local status, result = pcall(self[command], self, port_range, args)
            if status then
                return result
            else
                printf("ERROR: %s\n", result)
            end
        end
    end

    function self:display(need_stats)
        local display_cycle = os.time()
        if last_display == display_cycle then
            if need_stats then
                -- Make sure the stats are updated
                return do_update(false)
            else
                return
            end
        end
        last_display = display_cycle
        local all_stats = do_update(true)

        if #visible_ports == 0 then
            return all_stats
        end

        local num_rows = 0
        printf(CURSOR_OFF .. GOTO_TOP)

        if octeon.trafficgen.is_transmitting(known_ports) then
            transmit_time = display_cycle - transmit_start
            printf(NONZEROHI)
        else
            transmit_start = display_cycle
            printf(ZEROHI)
        end
        printf("%4d:%02d:%02d", transmit_time/3600, transmit_time/60%60, transmit_time%60)

        printf(ZEROHI .. "%10s", "Port")
        for _,port in ipairs(visible_ports) do
            printf("|%10s", port)
        end
        printf("|%10s%s\n%s", "Totals", ERASE_EOL, NORMAL);
        local stat_names = table.sorted_keys(all_stats[known_ports[1]])
        for _,stat_name in ipairs(stat_names) do
            num_rows = num_rows + display_stat(stat_name, all_stats)
        end
        local COL_SEP = ZEROHI .. "|" .. NORMAL
        if octeon.csr then
            -- Create a row reporting free packet buffers, command buffers, Lua mem, and C mem
            if octeon.is_model(octeon.CN78XX) then
                printf("Packets%5d, PKO buffers%5d, Lua mem%5dKB, C mem%5dKB%s\n",
                    octeon.csr.FPA_POOLX_AVAILABLE(0).read(), -- Packet pool
                    octeon.csr.FPA_POOLX_AVAILABLE(3).read(), -- PKO pool
                    collectgarbage("count"),
                    octeon.c.get_sbrk() / 1024,
                    ERASE_EOL);
            else
                printf("Packets%5d, Cmd buffers%5d, Lua mem%5dKB, C mem%5dKB%s\n",
                    octeon.csr.FPA_QUEX_AVAILABLE(0).read(), -- Packet pool
                    octeon.csr.FPA_QUEX_AVAILABLE(1).read(), -- Comamdn buffer pool
                    collectgarbage("count"),
                    octeon.c.get_sbrk() / 1024,
                    ERASE_EOL);
            end
        else
            -- Create a row reporting Lua mem, and C mem
            printf("Lua mem%5dKB, C mem%5dKB%s\n",
                collectgarbage("count"),
                octeon.c.get_sbrk() / 1024,
                ERASE_EOL);
        end
        num_rows = num_rows + 1
        if show_l2_stats then
            l2_stats_table = octeon.perf.get_l2(l2_stats_table)
            for _,n in ipairs(table.sorted_keys(l2_stats_table["tad0"])) do
                printf("%-20s", n)
                for _,tad in ipairs(table.sorted_keys(l2_stats_table)) do
                    printf("%s%10s", COL_SEP, tostring(l2_stats_table[tad][n]))
                end
                printf("%s\n", ERASE_EOL)
                num_rows = num_rows + 1
            end
        end

        print(ZEROHI .. "-------" .. NORMAL .. ERASE_EOL)
        printf(ERASE_EOL .. "\n");

        -- Confine scrolling region
        printf("\27[%d;r" .. GOTO_BOTTOM .. CURSOR_ON, num_rows + 3)
        if need_stats then
            return all_stats
        else
            return
        end
    end

    function self:build_tab()
        local tab = {}
        for n,v in pairs(self) do
            if n:sub(1,5) == "cmdp_" then
                tab[n:sub(6)] = known_ports
            elseif n:sub(1,4) == "cmd_" then
                tab[#tab+1] = n:sub(5)
            end
        end
        return tab
    end

    function self:get_stats()
        local stats = do_update(false)
        local result = {}
        for _,port in ipairs(default_ports) do
            result[port] = stats[port]
        end
        return result
    end

    -- Run traffic gen interactively
    function self:run()
        printf(SCROLL_FULL .. GOTO_BOTTOM)
        printf("\n\nBDK Traffic Generator\n\n")
        printf("Type \"help\" for a list of commands\n")
        octeon.c.bdk_init_nodes();
        -- Allow the user to do some trafficgen specific customization. First argument
        -- is trafficgen, so the script can add/remove comamnds or modify trafficgen.
        utils.run("autorun-trafficgen", self)
        local tab = self:build_tab()
        is_running = true
        while is_running do
            self:display(false)
            local cmd
            if use_readline then
                -- We only need second updates if stats are shown
                local timeout = (#visible_ports == 0) and 0 or 1000000
                cmd = readline.readline("Command> ", tab, timeout)
            else
                printf("Command> ")
                io.flush()
                cmd = io.read("*l")
                print(cmd)
            end
            if ALIASES[cmd] then
                cmd = ALIASES[cmd]
                printf("<%s>\n", cmd)
            end
            if cmd and (cmd ~= "") then
                local status, result = pcall(self.command, self, cmd)
                if not status then
                    printf(GOTO_BOTTOM .. CURSOR_ON .. "ERROR: %s\n", result)
                end
            end
        end
        printf(SCROLL_FULL .. GOTO_BOTTOM)
    end

    return self
end

return TrafficGen

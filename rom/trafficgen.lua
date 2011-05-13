
require("strict")
require("utils")

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
    local input_file = nil
    local last_display = 0
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
            local name, sep = str:match("^([A-Za-z0-9]+)([,-]?)", index)
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

    -- Display a single statistic line
    local function display_stat(stat_name, stats)
        local COL_SEP = ZEROHI .. "|" .. NORMAL
        local totals = 0
        local is_bits = stat_name:sub(-5,-1) == "_bits"
        if is_bits then
            printf("%-20s", stat_name:sub(1,-6) .. " Mbps")
        else
            printf("%-20s", stat_name:gsub("_", " "))
        end
        for _,p in ipairs(visible_ports) do
            local v = stats[p][stat_name]
            if is_bits then
                v = v / 1000000
            end
            totals = totals + v
            printf("%s%10s", COL_SEP, v)
        end
        printf("%s%10d%s\n", COL_SEP, totals, ERASE_EOL)
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
        local stats = octeon.trafficgen.update(false)
        stats = stats[known_ports[1]]
        -- Add in sorted order
        for _,field_name in ipairs(table.sorted_keys(stats)) do
            self["cmdp_" .. field_name] = function (self, port_range, args)
                local stats = octeon.trafficgen.update(false)
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
        if (not use_readline) and (not input_file) then
            input_file = io.open("/dev/uart/0", "r")
            assert(input_file, "Failed to open UART for access without readline")
        end
    end

    function self:cmdp_start(port_range, args)
        assert (#args == 0, "No arguments expected")
        octeon.trafficgen.start(port_range)
    end

    function self:cmdp_stop(port_range, args)
        assert (#args == 0, "No arguments expected")
        self:cmdp_output_enable(port_range, {false})
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

    function self:cmd_csr(port_range, args)
        local name = args[1]
        local value = args[2]
        if value then
            octeon.csr[name].write(value)
        else
            value = octeon.csr[name].read()
            octeon.c.bdk_csr_decode(name, value)
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
        octeon.c.bdk_reset_octeon()
    end

    function self:cmd_l2_stats(port_range, args)
        assert (#args == 1, "One argument expected, on or off")
        show_l2_stats = args[1]
    end

    function self:cmdp_scan_sizes(port_range, args)
        -- Get our setup params
        local output_count = 100
        local size_start = 60
        local size_stop = 65524
        local size_incr = 1
        -- Get the latest statistics
        local all_stats = self:display()
        -- Start with current counts
        local expected_packets = 0
        local expected_octets = 0
        local expected_rx_errors = 0
        local expected_validation_errors = 0
        for _,port in ipairs(port_range) do
            if port:sub(1,4) == "SRIO" then
                -- SRIO rounds packets to multiples of 8 and can only handle
                -- sizes up to 4096. It can handle smaller sizes, but the
                -- packet building code requires at least 46 bytes
                size_start = 48
                size_stop = 4096
                size_incr = 8
            end
            expected_packets = expected_packets + all_stats[port].rx_packets_total
            expected_octets = expected_octets + all_stats[port].rx_octets_total
            expected_rx_errors = expected_rx_errors + all_stats[port].rx_errors
            expected_validation_errors = expected_validation_errors + all_stats[port].rx_validation_errors
        end

        -- Loop through the sizes
        local new_config = {output_count = output_count}
        for size=size_start,size_stop,size_incr do
            printf("Size %d\n", size)
            new_config.output_packet_size = size;
            -- Setup TX and count how many packets we expect
            for _,port in ipairs(port_range) do
                octeon.trafficgen.set_config(port, new_config)
                expected_packets = expected_packets + output_count
                if (port:sub(1,5) == "SGMII") or (port:sub(1,4) == "XAUI") or (port:sub(1,3) == "ILK") then
                    -- Account for the extra 4 bytes of ethernet CRC
                    expected_octets = expected_octets + output_count * (size+4)
                else
                    expected_octets = expected_octets + output_count * size
                end
            end
            -- Limit to five seconds per size
            local timeout = os.time() + 5
            -- Do the TX
            octeon.trafficgen.start(port_range)
            while octeon.trafficgen.is_transmitting(port_range) and (os.time() < timeout) do
                -- Waiting for TX to be done
                octeon.c.bdk_thread_yield();
                -- Get the latest statistics
                self:display()
                collectgarbage()
            end
            local rx_packets
            local rx_octets
            local rx_errors
            local validation_errors
            repeat
                collectgarbage()
                octeon.c.bdk_thread_yield();
                -- Get the latest statistics
                all_stats = self:display()
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

    function self:display()
        local display_cycle = os.time()
        if last_display == display_cycle then
            -- Make sure the stats are updated
            return octeon.trafficgen.update(false)
        end
        last_display = display_cycle
        local all_stats = octeon.trafficgen.update(true)

        if #visible_ports == 0 then
            return all_stats
        end

        local num_rows = 0
        printf(CURSOR_OFF .. GOTO_TOP)

        printf(ZEROHI .. "%20s", "Port")
        for _,port in ipairs(visible_ports) do
            printf("|%10s", port)
        end
        printf("|%10s%s\n%s", "Totals", ERASE_EOL, NORMAL);
        local stat_names = table.sorted_keys(all_stats[known_ports[1]])
        for _,stat_name in ipairs(stat_names) do
            display_stat(stat_name, all_stats)
            num_rows = num_rows + 1
        end
        local COL_SEP = ZEROHI .. "|" .. NORMAL
        -- Create a row reporting Lua's memory usage
        printf("%-20s%s%10d%s\n", "Lua memory(KB)", COL_SEP, collectgarbage("count"), ERASE_EOL)
        num_rows = num_rows + 1
        -- Create a row reporting C's memory usage
        printf("%-20s%s%10d%s\n", "C memory(KB)", COL_SEP, octeon.get_sbrk() / 1024, ERASE_EOL)
        num_rows = num_rows + 1
        if show_l2_stats then
            local l2stats = octeon.perf.get_l2(l2_stats_table)
            for _,n in ipairs(table.sorted_keys(l2stats["tad0"])) do
                printf("%-20s", n)
                for _,tad in ipairs(table.sorted_keys(l2stats)) do
                    printf("%s%10s", COL_SEP, tostring(l2stats[tad][n]))
                end
                printf("%s\n", ERASE_EOL)
                num_rows = num_rows + 1
            end
        end

        print(ZEROHI .. "-------" .. NORMAL .. ERASE_EOL)
        printf(ERASE_EOL .. "\n");

        -- Confine scrolling region
        printf("\27[%d;r" .. GOTO_BOTTOM .. CURSOR_ON, num_rows + 3)
        return all_stats
    end

    -- Run traffic gen interactively
    function self:run()
        is_running = true
        while is_running do
            self:display()
            local cmd
            if use_readline then
                cmd = octeon.readline("Command", nil, 1000000)
            else
                printf("Command> ")
                io.flush()
                cmd = input_file:read("*l")
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

printf(SCROLL_FULL .. GOTO_BOTTOM)
printf("\n\nBDK Traffic Generator\n\n")
printf("Type \"help\" for a list of commands\n")
octeon.c.bdk_init_cores(0);
TrafficGen.new():run()

return TrafficGen

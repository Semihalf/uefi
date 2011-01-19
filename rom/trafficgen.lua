
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

local Row = {}
local row_counter = 0
function Row.new(name, struct, field, has_totals)
    local self = {}
    row_counter = row_counter + 1
    -- Private variables

    -- Public variables
    self.name = name
    self.visible = (struct == "stats")
    self.number = row_counter

    -- Private Methods

    -- Public Methods
    function self:display(ports)
        local COL_SEP = ZEROHI .. "|" .. NORMAL
        local totals = 0
        printf("%2d:%-20s", self.number, self.name)
        for _,p in ipairs(ports) do
            local v = p[struct][field]
            if type(v) == "number" then
                totals = totals + v
            else
                has_totals = false
            end
            printf("%s%10s", COL_SEP, tostring(v))
        end
        if has_totals then
            printf("%s%10d%s\n", COL_SEP, totals, ERASE_EOL)
        else
            printf(COL_SEP .. ERASE_EOL .. "\n")
        end
    end

    return self
end

local TrafficGen = {}
function TrafficGen.new()
    local self = {}
    --
    -- Private variables
    --
    local known_ports = {}
    local visible_ports = {}
    local default_ports = {}
    local known_rows = {}
    local is_running = true
    local last_display = 0

    --
    -- Public variables
    --

    --
    -- Private Methods
    --

    -- Get the list of possible ports from the C code. Result is stored in
    -- known_ports
    local function get_possible_ports()
        local index = 0
        repeat
            local port_info = bdktrafficgen.port_get(index)
            if port_info then
                index = index + 1
                known_ports[index] = port_info
            end
        until (port_info == nil)
    end
    get_possible_ports()
    visible_ports[1] = known_ports[1]

    -- Convert a list of ports into a C port_set_t
    -- FIXME: Does the port_set_t get GC?
    local function get_port_set(range)
        local set = bdktrafficgen.port_set_t()
        for _,port in ipairs(range) do
            bdktrafficgen.port_add(set, port)
        end
        return set
    end

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
                    if port.name == start_name then
                        in_range = true
                    end
                    if in_range then
                        table.insert(ports, port)
                    end
                    if port.name == stop_name then
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
                for _,prefix in ipairs({"cmdp_", "cmdr_", "cmd_"}) do
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
                elseif command:sub(1,5) == "cmdr_" then
                    if word == "all" then
                        range = known_rows
                    else
                        range = parse_range_list(word)
                        if range == nil then
                            table.insert(args, word)
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
            elseif command:sub(1,5) == "cmdr_" then
                range = known_rows
            end
        end
        return command, range, args
    end

    -- Create commands for getting and setting each value in the port.setup
    -- structure.
    local function create_struct_commands(name, struct)
        -- SWIG struct have a ".get" meta field with a list of all structure members
        local meta = getmetatable(struct)
        local fields = meta[".get"]
        -- Add in sorted order
        for _,field_name in ipairs(table.sorted_keys(fields)) do
            -- Skip complex types and fields beginning with "_"
            if (type(struct[field_name]) ~= "userdata") and (field_name:sub(1,1) ~= '_') then
                self["cmdp_" .. field_name] = function (self, port_range, args)
                    for _, port in pairs(port_range) do
                        if #args == 1 then
                            port[name][field_name] = args[1]
                        else
                            printf("Port %s: %s = %s\n", port.name, field_name, tostring(port[name][field_name]))
                        end
                    end
                end
                table.insert(known_rows, Row.new(field_name, name, field_name, true))
            end
        end
    end
    create_struct_commands("stats", known_ports[1].stats)
    create_struct_commands("setup", known_ports[1].setup)

    -- Create a row reporting Lua's memory usage
    do
        local memusage = Row.new("Lua memory(KB)", nil, nil, false)
        memusage.display = function (self, port_range)
            local COL_SEP = ZEROHI .. "|" .. NORMAL
            printf("%2d:%-20s", self.number, self.name)
            printf("%s%10d%s\n", COL_SEP, collectgarbage("count"), ERASE_EOL)
        end
        memusage.visible = 1
        table.insert(known_rows, memusage)
    end

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
            if k:sub(1,5) == "cmdr_" then
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
    end

    -- Select which ports to used by default
    function self:cmdp_default(port_range, args)
        assert (#args == 0, "No arguments expected")

        default_ports = port_range

        printf("Default ports:")
        for _,port in ipairs(default_ports) do
            printf(" %s", port.name)
        end
        printf("\n")
    end

    -- Quit the main run() loop
    function self:cmd_quit(port_range, args)
        assert (#args == 0, "No arguments expected")
        is_running = false
    end

    function self:cmdp_start(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_transmit(get_port_set(port_range))
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
    end

    function self:cmdp_clear(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_clear(get_port_set(port_range))
    end

    function self:cmdp_reset(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_reset(get_port_set(port_range))
    end

    function self:cmdp_tx_percent(port_range, args)
        for _,port in pairs(port_range) do
            if #args == 1 then
                port.setup.output_rate_is_mbps = true
                port.setup.output_rate = args[1] * 10
            else
                if port.setup.output_rate_is_mbps then
                    printf("Port %s: %d Mbps\n", port.name, port.setup.output_rate)
                else
                    printf("Port %s: %d packets/s\n", port.name, port.setup.output_rate)
                end
            end
        end
    end

    function self:cmdp_tx_rate(port_range, args)
        for _,port in pairs(port_range) do
            if #args == 1 then
                port.setup.output_rate_is_mbps = false
                port.setup.output_rate = args[1]
            else
                if port.setup.output_rate_is_mbps then
                    printf("Port %s: %d Mbps\n", port.name, port.setup.output_rate)
                else
                    printf("Port %s: %d packets/s\n", port.name, port.setup.output_rate)
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

    function self:cmdr_row(row_range, args)
        print "Not implemented"
    end

    function self:cmdr_hli(row_range, args)
        print "Not implemented"
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

    function self:cmdp_find_max(port_range, args)
        print "Not implemented"
    end

    function self:cmdp_scan_sizes(port_range, args)
        -- Get our setup params
        local port_set = get_port_set(port_range)
        local output_count = 100
        local size_start = 60
        local size_stop = 65524
        local size_incr = 1
        -- Get the latest statistics
        bdktrafficgen.do_update(false)
        -- Start with current counts
        local expected_packets = 0
        local expected_octets = 0
        for _,port in ipairs(port_range) do
            expected_packets = expected_packets + port.stats.rx_packets_total
            expected_octets = expected_octets + port.stats.rx_octets_total
        end

        -- Loop through the sizes
        for size=size_start,size_stop,size_incr do
            -- Setup TX and count how many packets we expect
            for _,port in ipairs(port_range) do
                port.setup.output_packet_size = size
                port.setup.output_count = output_count
                expected_packets = expected_packets + output_count
                expected_octets = expected_octets + output_count * (size+4)
            end
            -- Do the TX
            bdktrafficgen.do_transmit(port_set)
            while bdktrafficgen.is_transmitting(port_set) do
                -- Waiting for TX to be done
                octeon.c.bdk_thread_yield();
                -- Get the latest statistics
                self:display()
            end
            local rx_packets
            local rx_octets
            repeat
                octeon.c.bdk_thread_yield();
                -- Get the latest statistics
                self:display()
                -- Count the amount of data received
                rx_packets = 0
                rx_octets = 0
                for _,port in ipairs(port_range) do
                    rx_packets = rx_packets + port.stats.rx_packets_total
                    rx_octets = rx_octets + port.stats.rx_octets_total
                end
            until (rx_octets >= expected_octets)
            printf("Size %d\n", size)
            -- Make sure we got the right amount of data
            if (rx_packets ~= expected_packets) or (rx_octets ~= expected_octets) then
                printf("Scan failed at size %d\n", size)
                printf("RX packets %d, octets %d\n", rx_packets, rx_octets)
                break
            end
        end
    end

    function self:cmd_echo(port_range, args)
        pprint(table.unpack(args))
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
            bdktrafficgen.do_update(false)
            return 0
        end
        last_display = display_cycle
        bdktrafficgen.do_update(true)

        if #visible_ports == 0 then
            return 0
        end

        local num_rows = 0
        printf(CURSOR_OFF .. GOTO_TOP)

        printf(ZEROHI .. "   %20s", "Port")
        for _,port in ipairs(visible_ports) do
            printf("|%10s", port.name)
        end
        printf("|%10s%s\n%s", "Totals", ERASE_EOL, NORMAL);
        for _,row in ipairs(known_rows) do
            if row.visible then
                row:display(visible_ports)
                num_rows = num_rows + 1
            end
        end
        print("-------" .. ERASE_EOL)
        printf(ERASE_EOL .. "\n");

        -- Confine scrolling region
        printf("\27[%d;r" .. GOTO_BOTTOM .. CURSOR_ON, num_rows + 3)
        return num_rows
    end

    -- Run traffic gen interactively
    function self:run()
        is_running = true
        while is_running do
            self:display()
            local cmd = octeon.readline("Command", nil, 1000000)
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

octeon.c.bdk_init_cores(0);
TrafficGen.new():run()

return TrafficGen

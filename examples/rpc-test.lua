require("octeon")

-- Print out all the CSR names
for k in octeon.csr() do
    print(k)
end

-- Loop the following a hundred times as a simple test
for count=1,100 do
    print("Loop:", count)
    print("Octeon RCLK:", octeon.c.bdk_clock_get_rate(0))
    print("Octeon SCLK:", octeon.c.bdk_clock_get_rate(1))
    print("Octeon CIU_FUSE:", octeon.csr.ciu_fuse.read())
    print("Is CN63XX?", octeon.is_model(octeon.CN63XX))
    print("Is CN68XX?", octeon.is_model(octeon.CN68XX))
    print("Lua mem:", octeon.global.collectgarbage("count"))
    print("C mem:", octeon.get_sbrk() / 1024)
    collectgarbage()
end

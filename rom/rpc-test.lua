if #arg < 1 then
    print("You must specify the file to do RPC over. Example /dev/ttyS0")
    return
end

rpc = require("rpc")
r = rpc.connect(arg[1], arg[2])

for k in r.octeon.csr() do
    print(k)
end

count = 0
while true do
    count = count + 1
    print("Loop:", count)
    print (r._VERSION)
    r.foo = {1, 2, 3 ,4}
    print("Length of new table:", #r.foo)
    r.print("Hello World")
    --r.print(1, 2, nil, "foo", {foo=1}, true, false)

    print("Octeon RCLK:", r.octeon.c.bdk_clock_get_rate(0))
    print("Octeon SCLK:", r.octeon.c.bdk_clock_get_rate(1))
    print("Octeon CIU_FUSE:", r.octeon.csr.ciu_fuse.read())
    print("Is CN63XX?", r.octeon.is_model(r.octeon.CN63XX))
    print("Is CN68XX?", r.octeon.is_model(r.octeon.CN68XX))
    print("Lua mem:", r.collectgarbage("count"))
    print("C mem:", r.octeon.get_sbrk() / 1024)
    collectgarbage()
end

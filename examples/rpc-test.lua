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

-- Do nothing expressions that increase code coverage
rpc.debug = true
assert(octeon.global.assert(true))
rpc.debug = false
assert(octeon.global.assert({1, 2, true, false, nil, {}}))
assert(octeon.global.assert(true, false, nil))
assert(1 == octeon.global.tonumber("1"))
assert(nil == octeon.global.tonumber("foo"))

octeon.global.print("hello world")

octeon.global.foo = {1,2,3,4}
assert(#octeon.global.foo == 4)

for k,v in ipairs(octeon.global.foo) do
    assert(k==v)
end

octeon.global.foo[5] = 5
assert(octeon.global.foo[5] == 5)

for k,v in pairs(octeon.global.foo) do
    assert(k==v)
end

octeon.global.foo = nil
local r, message = pcall(octeon.global.assert, false)
assert(r == false, "r should be false: " .. tostring(r))


require("octeon")

-- Print out all the CSR names
for k in octeon.csr() do
    print(k)
end

-- Loop the following a hundred times as a simple test
for count=1,100 do
    print("Loop:", count)
    print("Octeon RCLK:", octeon.c.bdk_clock_get_rate(0,0))
    print("Octeon SCLK:", octeon.c.bdk_clock_get_rate(0,1))
    print("Octeon CIU_FUSE:", octeon.csr.CIU_FUSE.read())
    print("Is CN61XX?", octeon.is_model(octeon.CN61XX))
    print("Lua mem:", octeon.global.collectgarbage("count"))
    print("C mem:", octeon.c.get_sbrk() / 1024)
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

octeon.global.foo = nil
print("About to test remote assert. Expect spurious output")
local r, message = pcall(octeon.global.assert, false)
assert(r == false, "r should be false: " .. tostring(r))
local r, message = pcall(octeon.global.assert, true)
assert(r == true, "r should be true: " .. tostring(r))
print("Remote assert worked")

-- Make sure all possible bytes can be sent in a string
local t = {}
for i = 0, 255 do
    table.insert(t, string.char(i))
end
t = table.concat(t)
octeon.global.foo = t
local t2 = octeon.global.foo
assert(t == t2, "All character string corrupted")
print("Test complete")


--
-- Print all functions and modules available in the global environment
--
function show_modules()
    for m,v in pairs(_G) do
        if m ~= "_G" then
            print(m, type(v))
            if type(v) == 'table' then
                for e,v2 in pairs(v) do
                    print("    " .. m .. "." .. e, type(v2))
                end
            end
        end
    end
end

show_modules()

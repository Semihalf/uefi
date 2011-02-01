require("strict")

menu = {}

--
-- Show a simple menu and get the user's selection
--
function menu.show(choices)
    while (true) do
        -- print the menu, one item per line
        for i=1,#choices do
            print(i, choices[i])
        end

        -- Read a number from the user
        local c = io.read()
    	if c then
            c = tonumber(c)
        end
    	if not c then
    	    c = 999
    	end

        -- Validate the user's choice
    	if (c > 0) and (c <= #choices) then
    	    return c
    	else
    	    print("Invalid choice")
    	end
    end
end


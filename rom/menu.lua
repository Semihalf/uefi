menu = {}

function menu.show(choices)
    while (true) do
        for i=1,#choices do
            print(i, choices[i])
        end
        local c = io.read("*n")
	if not c then
	    c = 999
	end
	if (c > 0) and (c <= #choices) then
	    return c
	else
	    print("Invalid choice")
	end
    end
end


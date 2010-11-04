for m in pairs(_G) do
    if m ~= "_G" then
	print(m, type(_G[m]))
	if type(_G[m]) == 'table' then
	    for e in pairs(_G[m]) do
		print("    "..m.."."..e, type(_G[m][e]))
	    end
	end
    end
end
print("---")

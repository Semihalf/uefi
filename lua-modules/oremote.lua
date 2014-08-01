
-- Get the table of C functions for the bases of the oremote module
local oremote = require("oremote-internal")

-- Open a connection so the CSR database can determine the chip model
oremote.open()

-- Create the oremote.csr table
local lookup = require("csr")
oremote.csr = lookup(oremote, oremote.read_csr, oremote.write_csr)

-- Return the complete module
return oremote

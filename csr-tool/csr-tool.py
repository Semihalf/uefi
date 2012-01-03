#!/usr/bin/python

import sys
import getopt
import cPickle
import csr_read_hw_octcsr
import csr_output_html
import csr_list_combiner
import csr_output_header
import csr_output_db
import csr_output_lua
import csr_output_error_decodes

#
# Top level script for working with CSRs
#

OUTPUT_FILENAME_TYPEDEFS        = "bdk-csrs.h"
OUTPUT_FILENAME_DB              = "bdk-csrs.c"
OUTPUT_FILENAME_LUA             = "csr_db.lua"

csr_files = []          # List of CSR files to load. Each item is a chip,file tuple
generate_html = 0       # Non zero if HTML output of the CSRs should be generated

# Parse the user arguments
longopt=["help", "csr=", "html"]
try:
    (options, args) = getopt.getopt(sys.argv[1:], None, longopt)
    if len(options) == 0:
        raise Exception("show usage")
    for option,value in options:
        if option =="--help":
            raise Exception("show usage")
        elif option == "--csr":
            name, file = value.split(",")
            csr_files.append((name, file))
        elif option == "--html":
            generate_html = 1
except:
    print "Usage: csr-tool [options]"
    print "    Cavium Octeon CSR generation utility."
    print
    print "Options:"
    print "    --help                       Display this message"
    print "    --csr=chip,file              Load a file of CSRs for the named chip"
    print "    --html                       Generate HTML documentation of the CSRs"
    print
    print "Notes:"
    print "    - There should be a '--csr' for every support chip."
    print "    - At least one '--csr' option must be specified."
    print "    - HTML output assumes a directory 'html' exists."
    print "    - You may specify '--check-header' any number of times."
    print
    print "Example: This generates a header and HTML for CN31XX and CN30XX CSRs"
    print "    ./csr-tool.py --html \\"
    print "         --csr cn31xx,octcsr_cn31xxp1.txt \\"
    print "         --csr cn30xx,octcsr_cn30xx.txt"
    print
    sys.exit(-1)

# Make sure we have the minimum to do anything
if not csr_files:
    print "At least one '--csr' option is required."
    sys.exit(-1)

# Loop through the CSR files and read them in. There will be a list per chip
print "Reading CSRs:"
separate_chip_lists = []
for name,file in csr_files:
    pickle_file = file .replace(".txt", ".pickle")
    try:
        inf = open(pickle_file, "r")
        print "    %8s from %s" % (name, pickle_file)
        csrs = cPickle.load(inf)
        inf.close()
    except:
        print "    %8s from %s" % (name, file)
        csrs = csr_read_hw_octcsr.read(name, file)
        # Should really be done in csr.validate() but address isn't known then
        for csr in csrs:
            csr.validateAddresses()
        out = open(pickle_file, "w")
        cPickle.dump(csrs, out)
        out.close()
    separate_chip_lists.append(csrs)

print "Checking for address overlaps"
for csr_list in separate_chip_lists:
    io_space_used_addresses = {}
    per_type_used_addresses = {}
    chip = csr_list.name
    for csr in csr_list:
        for name,address,unused1,unused2 in csr.iterateAddresses():
            conflict = None
            if address & (1<<48):
                if address in io_space_used_addresses:
                    conflict = io_space_used_addresses[address]
                else:
                    io_space_used_addresses[address] = (name, csr)
            else:
                if not csr.type in per_type_used_addresses:
                    per_type_used_addresses[csr.type] = {}
                if address in per_type_used_addresses[csr.type]:
                    # Don't allow a CSR to conflict with itself (PCIe config on differnet ports)
                    if csr != per_type_used_addresses[csr.type][address][1]:
                        conflict = per_type_used_addresses[csr.type][address]
                else:
                    per_type_used_addresses[csr.type][address] = (name, csr)
            if (conflict):
                print "    %s: Address 0x%016x, conflict %-32s and %-32s" % (chip, address, name, conflict[0])

# Combine all chips into a master CSR list
print "Combining CSRs"
combined_list = csr_list_combiner.combine(separate_chip_lists)

# Generate the html docs if needed
if generate_html:
    print "Writing HTML"
    csr_output_html.writeAll(combined_list, diff=(("cn63xxp1", "cn63xx"),
                                                  ("cn63xx", "cn68xxp1"),
                                                  ("cn68xxp1", "cn68xx"),
                                                  ("cn63xx", "cn66xx"),
                                                  ("cn63xx", "cn61xx"),
                                                  ("cn66xx", "cn61xx"),
                                                  ("cn61xx", "cnf71xx")))

print "Writing " + OUTPUT_FILENAME_TYPEDEFS
csr_output_header.write(OUTPUT_FILENAME_TYPEDEFS, combined_list, 0)
print "Writing Cisco " + OUTPUT_FILENAME_TYPEDEFS
csr_output_header.write("cisco/" + OUTPUT_FILENAME_TYPEDEFS, combined_list, 1)
# Delete the combined list so that it can't be used by accident. It only
# is useful for C code and documentation.
combined_list = None

print "Writing " + OUTPUT_FILENAME_DB
csr_output_db.write(OUTPUT_FILENAME_DB, separate_chip_lists, 0)
print "Writing " + OUTPUT_FILENAME_LUA
csr_output_lua.write(OUTPUT_FILENAME_LUA, separate_chip_lists, 0)
#print "Writing Error decodes"
#csr_output_error_decodes.write(separate_chip_lists)

print "Writing Cisco " + OUTPUT_FILENAME_DB
csr_output_db.write("cisco/" + OUTPUT_FILENAME_DB, separate_chip_lists, 1)


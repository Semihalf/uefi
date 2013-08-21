#!/usr/bin/python

import sys
import os
import getopt
import cPickle
import csr_read_hw_octcsr
import csr_read_yaml
import csr_output_html
import csr_list_combiner
import csr_output_header
import csr_output_db
import csr_output_lua

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
separate_chip_infos = []
for name,file in csr_files:
    pickle_file = file + ".pickle"
    try:
        inf = open(pickle_file, "r")
        print "    %8s from %s" % (name, pickle_file)
        csrs = cPickle.load(inf)
        inf.close()
    except:
        print "    %8s from %s" % (name, file)
        if os.path.isdir(file):
            csrs = csr_read_yaml.read(name, file)
        else:
            csrs = csr_read_hw_octcsr.read(name, file)
        for enum in csrs.iterEnum():
            enum.validate()
        for struct in csrs.iterStruct():
            struct.validate()
        # Should really be done in csr.validate() but address isn't known then
        for csr in csrs.iterCsr():
            csr.validateAddresses()
        out = open(pickle_file, "w")
        cPickle.dump(csrs, out)
        out.close()
    separate_chip_infos.append(csrs)

print "Checking for address overlaps"
for chip_info in separate_chip_infos:
    io_space_used_addresses = {}
    per_type_used_addresses = {}
    chip = chip_info.name
    for csr in chip_info.iterCsr():
        for address_instance in csr.iterateAddresses():
            name = address_instance[0]
            address = address_instance[1]
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
combined_list = csr_list_combiner.combine(separate_chip_infos)

# Generate the html docs if needed
if generate_html:
    print "Writing HTML"
    csr_output_html.writeAll(combined_list, diff=(("cn70xx", "cn78xx"),))

print "Writing " + OUTPUT_FILENAME_TYPEDEFS
csr_output_header.write(OUTPUT_FILENAME_TYPEDEFS, combined_list, 0)

print "Writing " + OUTPUT_FILENAME_DB
csr_output_db.write(OUTPUT_FILENAME_DB, separate_chip_infos, 0)
print "Writing " + OUTPUT_FILENAME_LUA
csr_output_lua.write(OUTPUT_FILENAME_LUA, separate_chip_infos, 0)

if False:
    print "Writing Cisco " + OUTPUT_FILENAME_TYPEDEFS
    csr_output_header.write("cisco/" + OUTPUT_FILENAME_TYPEDEFS, combined_list, 1)
    print "Writing Cisco " + OUTPUT_FILENAME_DB
    csr_output_db.write("cisco/" + OUTPUT_FILENAME_DB, separate_chip_infos, 1)


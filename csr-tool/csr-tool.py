#!/usr/bin/python

import sys
import os
import getopt
import cPickle
import csr_read_yaml
import csr_output_html
import csr_list_combiner
import csr_output_header
import chip_database
import csr_output_db
import csr_output_lua
import bar_combiner
import enum_combiner
import struct_combiner
from chip_info import ChipInfo

#
# Top level script for working with CSRs
#

OUTPUT_FILENAME_TYPEDEFS        = "output/bdk-csrs.h"
OUTPUT_FILENAME_DB              = "output/bdk-csrs.c"
OUTPUT_FILENAME_LUA             = "output/bdk-csrs.lua"

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
            name, loc, pass_info = value.split(",")
            csr_files.append((name, loc, pass_info))
        elif option == "--html":
            generate_html = 1
except:
    print "Usage: csr-tool [options]"
    print "    Cavium CSR generation utility."
    print
    print "Options:"
    print "    --help                       Display this message"
    print "    --csr=chip_name,dir,pass     Load CSRs for the named chip from dir, using pass for chip_pass equations"
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
for name,file,pass_info in csr_files:
    pickle_file = name + ".pickle"
    try:
        inf = open(pickle_file, "r")
        print "    %8s from %s" % (name, pickle_file)
        chip_info = cPickle.load(inf)
        inf.close()
    except:
        print "    %8s from %s for %s" % (name, file, pass_info)
        pass_dict = {}
        pass_name, pass_value = pass_info.split("=")
        pass_dict[pass_name] = float(pass_value)
        chip_info = csr_read_yaml.read(name, file, pass_dict)
        for enum in chip_info.iterEnum():
            enum.validate()
        for struct in chip_info.iterStruct():
            struct.validate()
        # Should really be done in csr.validate() but address isn't known then
        for csr in chip_info.iterCsr():
            csr.validateAddresses()
        out = open(pickle_file, "w")
        cPickle.dump(chip_info, out)
        out.close()
    separate_chip_infos.append(chip_info)

print "Checking for address overlaps"
for chip_info in separate_chip_infos:
    io_space_used_addresses = {} # All global IO addresses should be unique
    per_type_used_addresses = {} # Addresses on a given bus should be unique
    chip = chip_info.name
    for csr in chip_info.iterCsr():
        for address_instance in csr.iterateAddresses():
            name = address_instance[0]
            address = address_instance[1]
            # Global addresses start with the top bit set, for IO space
            if address & (1<<47):
                if address in io_space_used_addresses:
                    print "    %s: Address 0x%016x, conflict %s and %s" % (
                        chip, address, name, io_space_used_addresses[address])
                else:
                    io_space_used_addresses[address] = name
            # Now check for any address on the same bus
                if not csr.type in per_type_used_addresses:
                    per_type_used_addresses[csr.type] = {}
                if address in per_type_used_addresses[csr.type]:
                    # Don't allow a CSR to conflict with itself (PCIe config on differnet ports)
                    if csr != per_type_used_addresses[csr.type][address][1]:
                        print "    %s: Bus %s, Address 0x%016x, conflict %s and %s" % (
                            chip, csr.type, address, name, per_type_used_addresses[csr.type][address][0])
                else:
                    per_type_used_addresses[csr.type][address] = (name, csr)

# Combine all chips into a master CSR list
combinedInfo = ChipInfo("s", {})
print "Combining Bars"
bar_combiner.combine(combinedInfo, separate_chip_infos)
print "Combining Enums"
enum_combiner.combine(combinedInfo, separate_chip_infos)
print "Combining Structs"
struct_combiner.combine(combinedInfo, separate_chip_infos)
#combinedInfo._bars = separate_chip_infos[0]._bars # FIXME
print "Combining CSRs"
combined_list = csr_list_combiner.combine(separate_chip_infos)

# Generate the html docs if needed
if generate_html:
    print "Writing HTML"
    csr_output_html.writeAll(combined_list, diff=(
        ("cn88xx", "cn85xx"),
        ("cn88xxp1", "cn88xx"),
        ))

print "Writing C headers"
csr_output_header.write(OUTPUT_FILENAME_TYPEDEFS, combined_list, combinedInfo)

print "Writing " + OUTPUT_FILENAME_DB
csr_output_db.write(OUTPUT_FILENAME_DB, separate_chip_infos)
print "Writing " + OUTPUT_FILENAME_LUA
csr_output_lua.write(OUTPUT_FILENAME_LUA, separate_chip_infos)


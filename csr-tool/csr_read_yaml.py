import os
import re
import yaml
import pprint
from csr import *

RE_ADDRESS_1 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*a[*](0x[0-9a-fA-F]+)$")
RE_ADDRESS_2a = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*a[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*b[*](0x[0-9a-fA-F]+)$")
RE_ADDRESS_2b = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*a[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*b[*]([0-9]+)$")
RE_ADDRESS_3 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[|][ ]*a<<([0-9]+)$")
RE_ADDRESS_4 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[|][ ]*a<<([0-9]+)[ ]*[|][ ]*b<<([0-9]+)$")
RE_ADDRESS_5 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*a[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*b[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*c[*]([0-9]+)$")
RE_ADDRESS_5b = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*a[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*b[*](0x[0-9a-fA-F]+)[ ]*[+][ ]*c[*](0x[0-9]+)$")
RE_ADDRESS_6 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[+][ ]*[(]a-([0-9]+)[)][*](0x[0-9a-fA-F]+)$")
RE_ADDRESS_7 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[|][ ]*a<<([0-9]+)[ ]*[|][ ]*b<<([0-9]+)[ ]*[|][ ]*c<<([0-9]+)$")
RE_ADDRESS_8 = re.compile("^(0x[0-9a-fA-F]+)[ ]*[|][ ]*a<<([0-9]+)[ ]*[|][ ]*b<<([0-9]+)[ ]*[|][ ]*c<<([0-9]+)[ ]*[|][ ]*d<<([0-9]+)$")

pp = pprint.PrettyPrinter(indent=4, width=132)

#
# Convert the string name from YAML into a list of strings and
# list ranges
#
def parseCsrName(name):
    assert isinstance(name, StringType)
    result = []
    while "(" in name:
        paren = name.find("(")
        result.append(name[0:paren])
        paren2 = name.find(")", paren)
        args = name[paren+1:paren2]
        args = args.split(",")
        range = []
        for arg in args:
            parts = arg.split("..")
            if len(parts) == 1:
                range.append(long(parts[0]))
                range.append(long(parts[0]))
            elif len(parts) == 2:
                range.append(long(parts[0]))
                range.append(long(parts[1]))
            else:
                assert False, name
        result.append(range)
        name = name[paren2+1:]
    if name:
        result.append(name)
    return result

#
# Parse the string from YAML into the three numbers we need
#
def parseAddress(addressStr):
    # A number means we got the address directly
    if isinstance(addressStr, IntType):
        return [addressStr]
    assert isinstance(addressStr, StringType)
    match = RE_ADDRESS_1.match(addressStr)
    if match:
        return [long(match.group(1), 0), long(match.group(2), 0)]
    match = RE_ADDRESS_2a.match(addressStr)
    if match:
        return [long(match.group(1), 0), long(match.group(2), 0), long(match.group(3), 0)]
    match = RE_ADDRESS_2b.match(addressStr)
    if match:
        return [long(match.group(1), 0), long(match.group(2), 0), long(match.group(3), 0)]
    match = RE_ADDRESS_3.match(addressStr)
    if match:
        return [long(match.group(1), 0), 1<<long(match.group(2), 0)]
    match = RE_ADDRESS_4.match(addressStr)
    if match:
        return [long(match.group(1), 0), 1<<long(match.group(2), 0), 1<<long(match.group(3), 0)]
    match = RE_ADDRESS_5.match(addressStr)
    if match:
        return [long(match.group(1), 0), long(match.group(2), 0), long(match.group(3), 0), long(match.group(4), 0)]
    match = RE_ADDRESS_5b.match(addressStr)
    if match:
        return [long(match.group(1), 0), long(match.group(2), 0), long(match.group(3), 0), long(match.group(4), 0)]
    match = RE_ADDRESS_6.match(addressStr)
    if match:
        base = long(match.group(1), 0)
        offset = long(match.group(2), 0)
        mult = long(match.group(3), 0)
        base = base - offset*mult
        return [base, mult]
    match = RE_ADDRESS_7.match(addressStr)
    if match:
        return [long(match.group(1), 0), 1<<long(match.group(2), 0), 1<<long(match.group(3), 0), 1<<long(match.group(4), 0)]
    match = RE_ADDRESS_8.match(addressStr)
    if match:
        return [long(match.group(1), 0), 1<<long(match.group(2), 0), 1<<long(match.group(3), 0), 1<<long(match.group(4), 0), 1<<long(match.group(5), 0)]
    assert False, addressStr

#
# Read a single YAML file and add its registers to the supplied csr list
#
def read_yaml(csr_list, filename):
    # Read the entire YAML file
    inf = open(filename, "r")
    raw = yaml.load(inf)
    inf.close()
    # Some files don't have any registers, just enums and such
    if not "registers" in raw:
        return
    # Iterate through the register list
    for register in raw["registers"]:
        # FIXME
        if not "fields" in register:
            continue
        #pp.pprint(register)
        # Parse the register name, description, and notes
        name_list = parseCsrName(register["name"])
        description = register.get("description", "").split("\n")
        notes = register.get("notes", "")
        if notes:
            notes = notes.split("\n")
        else:
            notes = []
        # We now have enough to start building the CSR
        csr = Csr(name_list, register["bus"], description)
        # Parse this address information
        csr.address_info = parseAddress(register["address"])
        # Due to a carry over from the old CSRs, some CSRs are special
        # in that the address equation is generated by these scripts and not
        # from the yaml
        if csr.name in ["fpa_fpf#_marks", "fpa_que#_page_index", "ipd_qos#_red_marks", "ipd_red_que#_param"]:
            assert len(csr.address_info) == 1
            csr.address_info = [csr.address_info[0] - 8 * csr.range[0][0], 8]
        # Iterate through all register fields
        for field in register["fields"]:
            name = field["name"]
            # Bits is either a single number or a range separated by ".."
            bits = field["bits"]
            if isinstance(bits, StringType):
                bits = bits.split("..")
                stop_bit = long(bits[0])
                start_bit = long(bits[1])
            else:
                start_bit = long(bits)
                stop_bit = start_bit
            # Field types are now called "access" with "---" standing for
            # reserved
            field_type = field["access"]
            if field_type == "---":
                field_type = "RAZ"
            # The new files sometimes use "--" as a name for reserved fields
            if name == "--":
                name = "reserved"
            # FIXME: Why do types have a "/H"
            if field_type.endswith("/H"):
                field_type = field_type[0:-2]
            reset_value = field["reset"]
            if isinstance(reset_value, IntType):
                reset_value = long(reset_value)
            typical_value = field["typical"]
            if isinstance(typical_value, IntType):
                typical_value = long(typical_value)
            # Reset and Typical uses "--" instead of "NS" as in previous chips. Convert
            # it to the old style to preserve compatability
            if typical_value == "--":
                typical_value = "NS"
            if reset_value == "--":
                reset_value = "NS"
            description = field.get("description", "").split("\n")
            csrField = CsrField(start_bit, stop_bit, name, field_type, reset_value, typical_value, description)
            csr.addField(csrField)
        # The CSR should be complete
        csr.validate()
        csr_list.addCsr(csr)

#
# Read all the YAML files in a directory and create a complete CSR list
# for the chip
#
def read(chip_name, input_dir):
    csr_list = CsrList(chip_name)
    input_files = os.listdir(input_dir)
    for file in input_files:
        if file in [".svn", ".gitignore"]:
            continue
        try:
            print "\t\t%s" % file
            read_yaml(csr_list, input_dir + "/" + file)
        except:
            raise
    return csr_list


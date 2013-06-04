import os
import yaml
import pprint
from csr import Csr
from csr import CsrField
from chip_info import ChipInfo
from chip_enum import ChipEnum
from chip_enum import ChipEnumValue
from chip_struct import ChipStruct
from chip_struct import ChipStructField
from types import *

pp = pprint.PrettyPrinter(indent=4, width=132)

#
# Check that all the keys in "dict" are listed in "keys". Name is text to
# print on failure to help debug
#
def check_keys(name, dict, keys):
    for k in dict:
        if not k in keys:
            pp.pprint(dict)
            assert False, "%s doesn't expect key %s, expect %s" % (name, k, keys)

#
# Parse a bit value into a start and stop bit
# Input is "number" or "number..number"
#
def parseBitRange(bits):
    word = 0
    if isinstance(bits, StringType):
        if bits[0] == "w":
            bits = bits.split("(")
            assert len(bits) == 2
            word = long(bits[0][1:])
            assert bits[1][-1] == ")"
            bits = bits[1][0:-1].split("..")
            if len(bits) == 1:
                start_bit = long(bits[0])
                stop_bit = start_bit
            else:
                assert(len(bits) == 2)
                stop_bit = long(bits[0])
                start_bit = long(bits[1])
        else:
            bits = bits.split("..")
            assert(len(bits) == 2)
            stop_bit = long(bits[0])
            start_bit = long(bits[1])
    else:
        start_bit = long(bits)
        stop_bit = start_bit
    assert word < 16
    assert (start_bit >= 0) and (start_bit < 64)
    assert (stop_bit >= start_bit) and (stop_bit < 64)
    start_bit = start_bit + word*64
    stop_bit = stop_bit + word*64
    return start_bit, stop_bit

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
def parseAddress(addressStr, num_params):
    # A number means we got the address directly
    if isinstance(addressStr, IntType):
        return [addressStr]
    assert isinstance(addressStr, StringType)
    address_info = []
    locals = {}
    for i in range(num_params):
        locals[chr(ord('a') + i)] = 0
    address_base = eval(addressStr, {}, locals)
    assert isinstance(address_base, IntType), address_base
    address_info.append(address_base)
    for i in range(num_params):
        locals[chr(ord('a') + i)] = 1
        tmp = eval(addressStr, {}, locals)
        assert isinstance(tmp, IntType), tmp
        locals[chr(ord('a') + i)] = 0
        tmp -= address_base
        address_info.append(tmp)
    return address_info

def build_enum(chip_info, enum):
    pass # FIXME: Not implementing the enum craziness

def build_struct(chip_info, struct):
    #pp.pprint(struct)
    check_keys("struct", struct, [
               "name",          # Name of the structure (text)
               "description",   # Optional description (text)
               "fields",        # Structure fields (sub tree)
               "attributes"])   # Optional attributes (sub tree)
    name = struct["name"]
    description = struct.get("description", "")
    chip_struct = ChipStruct(name, description)
    if "attributes" in struct:
        check_keys("struct[attributes]", struct["attributes"], [
                   "ignore_naming_convention",  # FIXME: What is this?
                   "allow_missing_bits"])       # Not all bits are specified, assume reserved for others
        # FIXME: What to do with attributes?
    for field in struct["fields"]:
        check_keys("struct[fields]", field, [
                   "name",          # Field name (text)
                   "description",   # Optional description (text)
                   "bits",          # Either a single number or "number..number"
                   "attributes"])   # Optional attributes (sub tree)
        name = field["name"]
        description = field.get("description", "")
        start_bit, stop_bit = parseBitRange(field["bits"])
        if "attributes" in field:
            check_keys("struct.fields[attributes]", field["attributes"], [
                       "const",                     # Field has a constant value
                       "verilog_struct_row_offset", # FIXME?
                       "wqe_related_field_name"])   # Affects this WQE field. Text not well formated
            # FIXME: What to do with attributes?
        chip_field = ChipStructField(name, None, start_bit, stop_bit, description)
        chip_struct.addField(chip_field)

    chip_info.addStruct(chip_struct)

def build_csr(chip_info, register, raw):
    check_keys("csr", register, [
               "name",          # CSR name (text with range info embedded)
               "inherits",      # Where to get fields if it doesn't exist (text name of csr)
               "fields",        # Fields of the register (sub tree)
               "description",   # Description of the register (text)
               "notes",         # Extra notes after description (text)
               "title",         # One line title/description (text)
               "address",       # Address equation for register (text equation)
               "bus",           # Type of the register (keyword)
               "attributes",    # Optional attributes (sub tree)
               "internal"])     # Internal description (text)
    if not "fields" in register:
        assert "inherits" in register, "No fields and no inherits %s" % register["name"]
        for r in raw["registers"]:
            if r["name"] == register["inherits"]:
                register["fields"] = r["fields"]
        assert "fields" in register, "Inherits not found by name"
    else:
        assert not "inherits" in register, "Fields and inherits"
    if "attributes" in register:
        check_keys("register[attributes]", register["attributes"], [
                   "arch_max",
                   "dv_force_no_compare",
                   "min_stride",
                   "mem_to_csr",
                   "regtest_alias",
                   "regtest_skip",
                   "rtlgen_cib",
                   "rtlgen_soft_reset",
                   "rtlgen_tie_rst_data",
                   "uvm_default_constraint"])
    #pp.pprint(register)
    # Parse the register name, description, and notes
    name_list = parseCsrName(register["name"])
    description = register.get("description", "").split("\n")
    notes = register.get("notes", "")
    if notes:
        notes = notes.split("\n")
    else:
        notes = []
    if name_list[0].startswith("POW_"):
        name_list[0] = "SSO_" + name_list[0][4:]
    # We now have enough to start building the CSR
    csr = Csr(name_list, register["bus"], description)
    # Parse this address information
    csr.address_info = parseAddress(register["address"], len(csr.range))
    # Due to a carry over from the old CSRs, some CSRs are special
    # in that the address equation is generated by these scripts and not
    # from the yaml
    if csr.name in ["fpa_fpf#_marks", "fpa_que#_page_index", "ipd_qos#_red_marks", "ipd_red_que#_param"]:
        assert len(csr.address_info) == 1
        csr.address_info = [csr.address_info[0] - 8 * csr.range[0][0], 8]
    # Iterate through all register fields
    for field in register["fields"]:
        check_keys("csr[fields]", field, [
                   "name",          # Name of the field (text name)
                   "bits",          # Bits used. Either single number or "number..number"
                   "access",        # Access mode (RO, RW, etc)
                   "reset",         # Reset value of the fields
                   "typical",       # Typical value
                   "description",   # Description of the field (text)
                   "attributes"])   # Optional attributes (sub tree)
        if "attributes" in field:
           check_keys("register.field[attributes]", field["attributes"], [
                      "no_soft_reset",
                      "dv_uvm_force_compare",
                      "dv_uvm_cov_val_disable",
                      "regtest_force",
                      "uvm_default_constraint"])
        name = field["name"]
        # Bits is either a single number or a range separated by ".."
        start_bit, stop_bit = parseBitRange(field["bits"])
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
    chip_info.addCsr(csr)
#
# Read a single YAML file and add its registers to the supplied csr list
#
def read_yaml(chip_info, filename):
    # Read the entire YAML file
    inf = open(filename, "r")
    raw = yaml.load(inf)
    inf.close()
    # Iterate through the enum list
    if "enums" in raw:
        for enum in raw["enums"]:
            build_enum(chip_info, enum)
    # Iterate through the struct list
    if "structs" in raw:
        for struct in raw["structs"]:
            build_struct(chip_info, struct)
    # Iterate through the register list
    if "registers" in raw:
        for register in raw["registers"]:
            build_csr(chip_info, register, raw)

#
# Read all the YAML files in a directory and create a complete CSR list
# for the chip
#
def read(chip_name, input_dir):
    chip_info = ChipInfo(chip_name)
    input_files = os.listdir(input_dir)
    for file in input_files:
        if file in [".svn", ".gitignore", "csr.txt"]:
            continue
        try:
            print "\t\t%s" % file
            read_yaml(chip_info, input_dir + "/" + file)
        except:
            raise
    return chip_info


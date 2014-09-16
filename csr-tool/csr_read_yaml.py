import os
import yaml
import pprint
from csr import Csr
from csr import CsrField
from chip_info import ChipInfo
from chip_enum import ChipEnum
from chip_enum import ChipEnumValue
from chip_enum import iterateEnumValues
from chip_struct import ChipStruct
from chip_struct import ChipStructField
from chip_bar import ChipBar
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
    assert word < 32
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
    name = name.replace("(S)", "s")
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

#
# Build an enumeration object from its yaml representation
#
def build_enum(chip_info, group, enum):
    #pp.pprint(enum)
    check_keys("enum", enum, [
               "name",          # Name of the enum (text)
               "title",         # Short description (text)
               "attributes",    # Optional attributes (sub tree)
               "description",   # Optional description (text)
               "internal",      # Optional internal (text)
               "values"])       # Enum values (sub tree)
    name = enum["name"]
    description = enum.get("title", "")
    if "description" in enum:
        description += "\n" + enum.get("description")
    width = int(enum["attributes"]["width"])
    chip_enum = ChipEnum(group, name, description, width)
    for enum_value in enum["values"]:
        check_keys("enum[values]", enum_value, [
                   "name",          # Value name (text)
                   "value",         # Value (number or equation)
                   "attributes",    # Optional attributes (sub tree)
                   "description"])  # Optional description (text)
        bar_size = 0
	class_code = 0
        if "attributes" in enum_value:
            if "pcc_bar_size_bits" in enum_value["attributes"]:
                bar_size = int(enum_value["attributes"]["pcc_bar_size_bits"])
	    elif "class_code" in enum_value["attributes"]:
		if enum_value["attributes"]["class_code"] != "--":
		    class_code = int(enum_value["attributes"]["class_code"], 0)
        n = enum_value["name"]
        v = enum_value["value"]
        if "(" in n:
            n = parseCsrName(n)
            range = []
            for part in n:
                if isinstance(part, ListType):
                    range.append(part)
            value_info = parseAddress(v, len(range))
            for data in iterateEnumValues(n, range, value_info):
                if bar_size:
                    chip_bar = ChipBar(group, data[0], description, data[1], bar_size, name)
                    chip_info.addBar(chip_bar)
                else:
                    chip_value = ChipEnumValue(data[0], data[1], enum_value.get("description", ""))
                    chip_enum.addValue(chip_value)
        else:
            if bar_size:
                chip_bar = ChipBar(group, n, description, v, bar_size, name)
                chip_info.addBar(chip_bar)
            else:
                chip_value = ChipEnumValue(n, v, enum_value.get("description", ""))
		if class_code:
		    class_value = ChipEnumValue(n + "_CLASS_CODE", class_code, "")
		    chip_enum.addValue(class_value)
                chip_enum.addValue(chip_value)
    chip_enum.validate()
    if len(chip_enum.values) > 0:
        chip_info.addEnum(chip_enum)

#
# Build a structure object from its yaml representation
#
def build_struct(chip_info, group, struct):
    #pp.pprint(struct)
    check_keys("struct", struct, [
               "name",          # Name of the structure (text)
               "title",         # Short description (text)
               "description",   # Optional description (text)
               "fields",        # Structure fields (sub tree)
               "attributes"])   # Optional attributes (sub tree)
    name = struct["name"]
    description = struct.get("title", "")
    if "description" in struct:
        description += "\n" + struct.get("description")
    chip_struct = ChipStruct(group, name, description)
    if "attributes" in struct:
        check_keys("struct[attributes]", struct["attributes"], [
                   "ignore_naming_convention",  # FIXME: What is this?
                   "allow_missing_bits",        # Not all bits are specified, assume reserved for others
                   "mif_operation",
                   "subblock"])                 # FIXME: What is this?
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
                       "wqe_related_field_name",    # Affects this WQE field. Text not well formated
                       "exempt_keyword"])
            # FIXME: What to do with attributes?
        chip_field = ChipStructField(name, None, start_bit, stop_bit, description)
        chip_struct.addField(chip_field)

    chip_info.addStruct(chip_struct)

#
# Build a csr object from its yaml representation
#
def build_csr(chip_info, group, register, raw):
    #pp.pprint(register)
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
               "bar",           # Information about how to device the CSR space inot PCIe BARs
               "internal"])     # Internal description (text)
    if not "fields" in register:
        assert "inherits" in register, "No fields and no inherits %s" % register["name"]
        for r in raw["registers"]:
            if r["name"] == register["inherits"]:
                register["fields"] = r["fields"]
                if "attributes" in r or "attributes" in register:
		    if "attributes" in register and "attributes" in r:
		        register["attributes"] = dict(register["attributes"].items() + r["attributes"].items())
		    elif "attributes" in r:
			register["attributes"] = r["attributes"]
        assert "fields" in register, "Inherits not found by name"
    else:
        assert not "inherits" in register, "Fields and inherits"
    if "attributes" in register:
        check_keys("register[attributes]", register["attributes"], [
                   "arch_max",
                   "backdoor_mem_path",
                   "dv_bist_all_fail_test",
                   "dv_fc_scratch",
                   "dv_force_no_compare",
                   "dv_testbuilder_no_create",
                   "dv_uvm_no_create",
                   "exempt_name_length",
                   "exempt_name_inherits",
                   "exempt_natural_alignment",
                   "exempt_no_bar",
                   "exempt_w1c_w",
                   "inherits_algorithm",
                   "mem_to_csr",
                   "min_stride",
                   "min_write_size",
                   "pcc_present_if",
                   "regtest_alias",
                   "regtest_skip",
                   "rtlgen_cib",
                   "rtlgen_extern",
                   "rtlgen_msix",
                   "rtlgen_pib",
                   "rtlgen_soft_reset",
                   "rtlgen_tie_rst_data",
                   "secure",
		   "secure_alias",
                   "secure_banked",
                   "secure_ignore_aware",
                   "stage",
                   "subblock",
                   "tns_fused",
                   "uvm_default_constraint",
                   "xpliant_xml_skip"])
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
    is_banked = "attributes" in register and "secure_banked" in register["attributes"]
    inherits_algorithm = "None"
    if "attributes" in register:
        if "inherits_algorithm" in register["attributes"]:
	    inherits_algorithm = register["attributes"]["inherits_algorithm"]
    csr = Csr(group, name_list, register["bus"], description, [], is_banked, inherits_algorithm)
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
                   "internal",      # Hardware team internal only notes
                   "attributes"])   # Optional attributes (sub tree)
        if "attributes" in field:
           check_keys("register.field[attributes]", field["attributes"], [
                      "no_soft_reset",
                      "chip_pass",
                      "dv_uvm_force_compare",
                      "dv_uvm_cov_val_disable",
                      "exempt_keyword",
                      "exempt_name_double_underscore",
                      "regtest_force",
                      "pcc_conditional",
                      "pcc_exempt_access",
                      "tns_fused",
                      "uvm_default_constraint"])
           if "chip_pass" in field["attributes"]:
               pass_equation = field["attributes"]["chip_pass"]
               is_this_pass = eval(pass_equation, {}, chip_info.pass_dict)
               #print pass_equation, is_this_pass
               if not is_this_pass:
                   continue
        name = field["name"]
        # Bits is either a single number or a range separated by ".."
        start_bit, stop_bit = parseBitRange(field["bits"])
        # Field types are now called "access" with "--" standing for
        # reserved
        field_type = field["access"]
        if field_type == "--":
            field_type = "RAZ"
        # The new files sometimes use "--" as a name for reserved fields
        if name == "--":
            name = "reserved"
        reset_value = field["reset"]
        if isinstance(reset_value, IntType):
            reset_value = long(reset_value)
        typical_value = field["typical"]
        if isinstance(typical_value, IntType):
            typical_value = long(typical_value)
        # Reset and Typical uses "--" instead of "NS" as in previous chips. Convert
        # it to the old style to preserve compatibility
        if typical_value == "--":
            typical_value = "NS"
        if reset_value == "--":
            reset_value = "NS"
        description = field.get("description", "").split("\n")
        csrField = CsrField(start_bit, stop_bit, name, field_type, reset_value, typical_value, description)
        csr.addField(csrField)
    # The CSR should be complete
    csr.validate()
    # Merge MIO_BOOT_REG_CFG0 into MIO_BOOT_REG_CFGX
    if csr.name == "mio_boot_reg_cfg0":
        return
    if csr.name == "mio_boot_reg_cfg#":
        csr.range[0][0] = 0
    chip_info.addCsr(csr)

#
# Read a single YAML file and add its registers to the supplied csr list
#
def read_yaml(chip_info, filename):
    # Read the entire YAML file
    inf = open(filename, "r")
    raw = yaml.load(inf)
    inf.close()
    check_keys("Top level", raw, [
        "name",         # High level block name
        "attributes",   # Attrbiutes for the block
        "description",  # Description of the block
        "enums",        # List of enumerations
        "structs",      # List of structures
        "registers",    # List of CSRs
        "internal"])    # Hardware team stuff
    group = raw["name"]
    # Iterate through the enum list
    if "enums" in raw:
        for enum in raw["enums"]:
            build_enum(chip_info, group, enum)
    # Iterate through the struct list
    if "structs" in raw:
        for struct in raw["structs"]:
            build_struct(chip_info, group, struct)
    # Iterate through the register list
    if "registers" in raw:
        for register in raw["registers"]:
            build_csr(chip_info, group, register, raw)

#
# Read all the YAML files in a directory and create a complete CSR list
# for the chip
#
def read(chip_name, input_dir, pass_dict):
    chip_info = ChipInfo(chip_name, pass_dict)
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


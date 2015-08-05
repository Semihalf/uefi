import re
from types import IntType
import chip_list
import csr_data
import csr_utils
from yaml_utils import *

def _parseBus(yaml):
    bus = getChild(yaml,"bus")
    if not bus in chip_list.VALID_BUSSES:
        raiseException(yaml, "Unexpected bus \"%s\"" % bus)
    return bus

def _parseAccess(yaml):
    access = getChild(yaml,"access")
    # Strip off the hardware modified flag during checking
    if access.endswith("/H"):
        a = access[0:-2]
    else:
        a = access
    if not a in chip_list.VALID_ACCESS:
        raiseException(yaml, "Unexpected access \"%s\"" % access)
    return access

def _parseFieldValue(yaml, name):
    value = getChild(yaml, name).lower()
    if value in ["--", "ns", "x"]:
        value = "--"
    elif value in ["all-ones"]:
        value = long(-1)
    else:
        try:
            value = long(value, 0)
        except:
            raiseException(yaml, "Invalid value for %s \"%s\"" % (name, value))
    return value

#
# Parse the string from YAML into the numbers we need
#
def parseAddress(yaml, name):
    str_eq = getChild(yaml, name).lower()
    try:
        return [long(str_eq, 0)]
    except:
        pass
    # The address equation takes an unknown number of arguments. Keep adding
    # arguments until we can evaluate the equation. The max number of arguments
    # is arbitrary and can be increased in the future
    num_args = 0
    locals = {}
    for i in range(4):
        # Add another argument to the locals environment
        locals[chr(ord('a') + i)] = 0
        # Try and evaluate the equation
        try:
            tmp = eval(str_eq, {}, locals)
            # Success, record the number of args
            num_args = i + 1
            break
        except:
            pass # We probably need another argument
    if num_args == 0:
        raiseException(yaml, "Invalid equation for %s \"%s\"" % (name, str_eq))
    address_info = []
    address_base = eval(str_eq, {}, locals)
    if not isinstance(address_base, IntType):
        raiseException(yaml, "Invalid equation for %s \"%s\"" % (name, str_eq))
    address_info.append(address_base)
    for i in range(num_args):
        locals[chr(ord('a') + i)] = 1
        tmp = eval(str_eq, {}, locals)
        if not isinstance(tmp, IntType):
            raiseException(yaml, "Invalid equation for %s \"%s\"" % (name, str_eq))
        locals[chr(ord('a') + i)] = 0
        tmp -= address_base
        address_info.append(tmp)
    return address_info

#
# Parse the bit description out of a structure field. The value
# is in the format "#", or "#..#"
#
def _parseBits(yaml):
    bits_str = getChild(yaml, "bits")
    bits = bits_str.split("..")
    if len(bits) == 1:
        start_bit = int(bits[0])
        stop_bit = start_bit
    elif len(bits) != 2:
        raiseException(yaml, "Unexpected bit format \"%s\"" % bits_str)
    else:
        stop_bit = int(bits[0])
        start_bit = int(bits[1])
    if (start_bit < 0) or (start_bit >= 64) or (stop_bit < start_bit) or (stop_bit >= 64):
        raiseException(yaml, "Unexpected bit format \"%s\"" % bits_str)
    # These will always be ordered with the smallest first
    return start_bit, stop_bit

#
# Parse an individual register
#
def _parseReg(root, yaml, chip, yaml_root, block):
    # Check that yaml doesn't have any unexpected tags
    checkChildren(yaml, [
        "name",          # CSR name (text with range info embedded)
        "fields",        # Fields of the register (sub tree)
        "description",   # Description of the register (text)
        "notes",         # Extra notes after description (text)
        "title",         # One line title/description (text)
        "address",       # Address equation for register (text equation)
        "bus",           # Type of the register (keyword)
        "attributes",    # Optional attributes (sub tree)
        "bar",           # Information about how to device the CSR space into PCIe BARs
        "internal"])     # Internal description (text)
    # Make the type name is lower case
    name = getChild(yaml,"name").lower()
    # "(s)" in the name represents secure, change it to a "s"
    name = name.replace("(s)", "s")
    name, ranges = csr_utils.parseNameForRanges(name, yaml)
    if name in root:
        work_reg = root[name]
    else:
        work_reg = csr_data.Register(name)
    # Add this chip and YAML
    work_reg.addChip(chip, yaml)
    root[name] = work_reg
    work_reg["block"] = block
    work_reg["address"][chip] = parseAddress(yaml,"address")
    work_reg["ranges"][chip] = ranges
    work_reg["bus"][chip] = _parseBus(yaml)
    work_reg["bar"][chip] = getChild(yaml,"bar", True)
    # Inherits should have been handled by csr3
    inherits = getChild(yaml, "inherits", True)
    if inherits:
        raiseException(yaml, "Unexpected inherit")
    # Iterate all yaml fields
    fields = getChild(yaml, "fields")
    for f in fields:
        # Check that yaml doesn't have any unexpected tags
        checkChildren(f, [
            "name",          # Name of the field (text name)
            "bits",          # Bits used. Either single number or "number..number"
            "access",        # Access mode (RO, RW, etc)
            "reset",         # Reset value of the fields
            "typical",       # Typical value
            "description",   # Description of the field (text)
            "internal",      # Hardware team internal only notes
            "attributes"])   # Optional attributes (sub tree)
        name = getChild(f, "name").lower()
        bits = _parseBits(f)
        if csr_utils.isReserved(name):
            name = csr_utils.getReservedName(bits)
        if not name in work_reg["fields"]:
            work_reg["fields"][name] = csr_data.RegisterField(name)
        item = work_reg["fields"][name]
        item.addChip(chip, f)
        item["bits"][chip] = bits
        item["access"][chip] = _parseAccess(f)
        item["reset"][chip] = _parseFieldValue(f, "reset")
        item["typical"][chip] = _parseFieldValue(f, "typical")

#
# Check for errors
#
def _validateReg(root, name):
    reg = root[name]
    # Validate the type name
    if not re.match("^[a-z][a-z0-9#_]*$", name):
        raiseException(reg, "Reg: Illegal name \"%s\"" % name)
    # Count the number of parameters
    num_params = name.count("#")
    # Limit to 4 parameters as a sanity check. This can be raised without
    # issue
    if num_params > 4:
        raiseException(reg, "Reg: Too many params, name \"%s\"" % name)
    # Make sure the address equation agrees on the number of params
    for chip in reg["address"]:
        eq = reg["address"][chip]
        if len(eq) != num_params + 1:
            raiseException(reg, "Reg: Unexpected equation length for %s %s" % (chip, eq))
        if len(reg["ranges"][chip]) != num_params :
            raiseException(reg, "Reg: Unexpected range length for %s %s" % (chip, reg["ranges"][chip]))
    # Check fields
    for n in reg["fields"]:
        if not re.match("^[a-z][a-z0-9_]*$", n):
            raiseException(reg, "Reg: Illegal field name \"%s\"" % n)
    # Find any missing bits
    chip_holes = csr_utils.findBitHoles(reg, multipleOf=32)
    # Create reserved fields for bits
    for chip in chip_holes:
        raiseException(reg, "Reg: Missing bits for chip %s %s" % (chip, chip_holes[chip]))
    # Sanity check the size. These can be changed without issue
    size = csr_utils.getSizeBits(reg, multipleOf=0)
    if (size != 32) and (size != 64):
        raiseException(struct, "Reg: Size not 32 or 64 bits")

#
# Process all registers
#
def process(yaml_all):
    # This will return all the registers when we're done
    root = {}
    # Loop through all chips
    for chip in chip_list.getChips():
        # Get the YAML coresponding to this chip
        file = chip_list.getYamlFile(chip)
        yaml_root = yaml_all[file]
        # Loop through all blocks
        for block in yaml_root:
            yaml_block = yaml_root[block]
            # Find the yaml registers section
            yaml_regs = getChild(yaml_block, "registers", True)
            if not yaml_regs:
                continue
            # Process each register for this chip
            for reg in yaml_regs:
                _parseReg(root, reg, chip, yaml_root, block)
    for r in root:
        _validateReg(root, r)
    return root

from csr_output_header import writeCopyrightBanner
from csr_output_header import getCname

CHIP_TO_MODEL = {
    "cn63xxp1": "OCTEON_CN63XX_PASS1_X",
    "cn63xx":   "OCTEON_CN63XX_PASS2_X",
    "cn68xx":   "OCTEON_CN68XX",
}

FATAL_FUNCTION = "__bdk_csr_fatal"

def toHex(v, digits=0):
    if digits == 0:
        return hex(v).upper().replace("L", "").replace("X", "x")
    hex_digit = "0123456789ABCDEF"
    result = "0x"
    for digit in xrange(digits):
        bit_shift = (digits - digit - 1) * 4
        result += hex_digit[(v>>bit_shift) & 0xf]
    return result

def getBitMask(max_number):
    mask = 0;
    while max_number:
        mask = (mask<<1) | 1
        max_number = max_number>>1
    return mask

def createRangeCheck(arg, ranges):
    index = 0
    range_check = ""
    while index < len(ranges):
        low = ranges[index]
        high = ranges[index+1]
        index += 2
        if low == high:
            range_check += " || (%s == %d)" % (arg, low)
        elif low == 0:
            range_check += " || (%s <= %d)" % (arg, high)
        else:
            range_check += " || ((%s >= %d) && (%s <= %d))" % (arg, low, arg, high)
    range_check = range_check[4:]
    return range_check

def writeAddress(out, csr, pci_alias, chip_list):
    num_params = len(csr["s"].range)
    name = getCname(csr["s"]).upper()
    if csr["s"].pci_alias == -1:
        if pci_alias:
            return
    else:
        if not pci_alias:
            return # Leave this code as we might need it someday
            if csr["s"].type == "PEXP_NCB":
                name = "PEXP_" + name
            elif (csr["s"].type == "PCICONFIG") or (csr["s"].type == "PCI_NCB"):
                name = "NPI_" + name
            else:
                raise Exception("Unexpected csr.type %s with pci alias" % csr["s"].type)

    if num_params == 0:
        out.write("#define %s %s_FUNC()\n" % (name, name))
        out.write("static inline uint64_t %s_FUNC(void) __attribute__ ((pure));\n" % name)
        out.write("static inline uint64_t %s_FUNC(void)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s);" % (FATAL_FUNCTION, name, 0, "0", "0")
    elif num_params == 1:
        if ("offset" in csr["s"].getAddressEquation()):
            out.write("static inline uint64_t %s(unsigned long offset) __attribute__ ((pure));\n" % name)
            out.write("static inline uint64_t %s(unsigned long offset)\n" % name)
            error_message = "%s(\"%s\", %d, %s, %s);" % (FATAL_FUNCTION, name, 1, "offset", "0")
        else:
            out.write("static inline uint64_t %s(unsigned long block_id) __attribute__ ((pure));\n" % name)
            out.write("static inline uint64_t %s(unsigned long block_id)\n" % name)
            error_message = "%s(\"%s\", %d, %s, %s);" % (FATAL_FUNCTION, name, 1, "block_id", "0")
    elif num_params == 2:
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id) __attribute__ ((pure));\n" % name)
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s);" % (FATAL_FUNCTION, name, 2, "offset", "block_id")
    else:
        raise Exception("Unexpected number of parameters")
    out.write("{\n")
    chips = csr.keys()
    chips.sort()
    chips.reverse()
    address_list = []
    for chip in chips:
        if chip == "s":
            continue
        if num_params == 0:
            range_check = ""
        elif num_params == 1:
            if ("offset" in csr["s"].getAddressEquation()):
                range_check = " && (%s)" % createRangeCheck("offset", csr[chip].range[0])
            else:
                range_check = " && (%s)" % createRangeCheck("block_id", csr[chip].range[0])
        else:
            range_check = " && (%s) && (%s)" % (createRangeCheck("block_id", csr[chip].range[0]), createRangeCheck("offset", csr[chip].range[1]))
        address_list.append((chip, range_check, csr[chip].getAddressEquation(pci_alias=pci_alias)))
    all_same = (len(chip_list) == len(address_list))
    for line in address_list[1:]:
        if (line[1] != address_list[0][1]) or (line[2] != address_list[0][2]):
            all_same = 0
    if all_same:
        range_check = address_list[0][1]
        if range_check:
            out.write("\tif (%s)\n" % (range_check[4:]))
            out.write("\t\treturn %s;\n" % address_list[0][2])
            out.write("\telse {\n")
            out.write("\t\t%s /* No return */\n" % error_message);
            out.write("\t}\n");
        else:
            out.write("\treturn %s;\n" % address_list[0][2])
    else:
        out.write("\t")
        for line in address_list:
            out.write("if (OCTEON_IS_MODEL(%s)%s)\n" % (CHIP_TO_MODEL[line[0]], line[1]))
            out.write("\t\treturn %s;\n" % line[2])
            out.write("\telse ")
        out.write("{\n")
        out.write("\t\t%s /* No return */\n" % error_message);
        out.write("\t}\n");
    out.write("}\n");

def write(out, csr, chip_list):
    writeAddress(out, csr, 0, chip_list)
    writeAddress(out, csr, 1, chip_list)


from csr_output_header import writeCopyrightBanner
from csr_output_header import getCname

CHIP_TO_MODEL = {
    "cn38xxp2": "OCTEON_CN38XX_PASS2_X",
    "cn31xx":   "OCTEON_CN31XX",
    "cn30xx":   "OCTEON_CN30XX",
    "cn38xx":   "OCTEON_CN38XX_PASS3_X",
    "cn58xxp1": "OCTEON_CN58XX_PASS1_X",
    "cn58xx":   "OCTEON_CN58XX",
    "cn56xxp1": "OCTEON_CN56XX_PASS1_X",
    "cn56xx":   "OCTEON_CN56XX_PASS2_X",
    "cn50xx":   "OCTEON_CN50XX",
    "cn52xxp1": "OCTEON_CN52XX_PASS1_X",
    "cn52xx":   "OCTEON_CN52XX_PASS2_X",
    "cn63xxp1": "OCTEON_CN63XX_PASS1_X",
    "cn63xx":   "OCTEON_CN63XX_PASS2_X",
    "cn68xx":   "OCTEON_CN68XX",
}

WARN_FUNCTION = "bdk_warn"

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

def writeAddress(out, csr, pci_alias):
    num_params = len(csr["s"].range)
    name = getCname(csr["s"]).upper()
    if csr["s"].pci_alias == -1:
        if pci_alias:
            return
    else:
        if not pci_alias:
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
        warning = "%s(\"%s not supported on this chip\\n\");" % (WARN_FUNCTION, name)
    elif num_params == 1:
        if ("offset" in csr["s"].getAddressEquation()):
            out.write("static inline uint64_t %s(unsigned long offset) __attribute__ ((pure));\n" % name)
            out.write("static inline uint64_t %s(unsigned long offset)\n" % name)
            warning = "%s(\"%s(%%lu) is invalid on this chip\\n\", offset);" % (WARN_FUNCTION, name)
        else:
            out.write("static inline uint64_t %s(unsigned long block_id) __attribute__ ((pure));\n" % name)
            out.write("static inline uint64_t %s(unsigned long block_id)\n" % name)
            warning = "%s(\"%s(%%lu) is invalid on this chip\\n\", block_id);" % (WARN_FUNCTION, name)
    elif num_params == 2:
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id) __attribute__ ((pure));\n" % name)
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id)\n" % name)
        warning = "%s(\"%s(%%lu,%%lu) is invalid on this chip\\n\", offset, block_id);" % (WARN_FUNCTION, name)
    else:
        raise Exception("Unexpected number of parameters")
    out.write("{\n")
    out.write("\t")
    chips = csr.keys()
    chips.sort()
    chips.reverse()
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
        out.write("if (OCTEON_IS_MODEL(%s)%s)\n" % (CHIP_TO_MODEL[chip], range_check))
        out.write("\t\treturn %s;\n" % csr[chip].getAddressEquation(pci_alias=pci_alias))
        out.write("\telse ")
    out.write("{\n")
    out.write("\t\t%s\n" % warning);
    out.write("\t\treturn %s;\n" % csr["s"].getAddressEquation(pci_alias=pci_alias))
    out.write("\t}\n");
    out.write("}\n");

def write(out, csr):
    writeAddress(out, csr, pci_alias=0)
    writeAddress(out, csr, pci_alias=1)


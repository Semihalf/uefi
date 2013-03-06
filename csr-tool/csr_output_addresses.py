from csr_output_header import writeCopyrightBanner
from csr_output_header import getCname

CHIP_TO_MODEL = {
    "cn68xx":   "OCTEON_CN68XX_PASS2_X",
    "cn61xx":   "OCTEON_CN61XX_PASS1_X",
    "cn78xx":   "OCTEON_CN78XX_PASS1_X",
    "cn70xx":   "OCTEON_CN70XX_PASS1_X",
}

# This is filled in when write() is called. It is derived from the chip list
# and CHIP_TO_MODEL. Format is:
# CHIP_PASS_LIST["CN61XX"] = ["PASS1_X", "PASS2_X"]
CHIP_PASS_LIST = {}

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

def writeAddress(out, csr, chip_list):
    num_params = len(csr["s"].range)
    name = getCname(csr["s"]).upper()
    if num_params == 0:
        out.write("#define %s %s_FUNC()\n" % (name, name))
        out.write("static inline uint64_t %s_FUNC(void) __attribute__ ((pure, always_inline));\n" % name)
        out.write("static inline uint64_t %s_FUNC(void)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 0, "0", "0", "0", "0")
    elif num_params == 1:
        if ("offset" in csr["s"].getAddressEquation()):
            out.write("static inline uint64_t %s(unsigned long offset) __attribute__ ((pure, always_inline));\n" % name)
            out.write("static inline uint64_t %s(unsigned long offset)\n" % name)
            error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 1, "offset", "0", "0", "0")
        else:
            out.write("static inline uint64_t %s(unsigned long block_id) __attribute__ ((pure, always_inline));\n" % name)
            out.write("static inline uint64_t %s(unsigned long block_id)\n" % name)
            error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 1, "block_id", "0", "0", "0")
    elif num_params == 2:
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id) __attribute__ ((pure, always_inline));\n" % name)
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 2, "offset", "block_id", "0", "0")
    elif num_params == 3:
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id, unsigned long param3) __attribute__ ((pure, always_inline));\n" % name)
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id, unsigned long param3)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 3, "offset", "block_id", "param3", "0")
    elif num_params == 4:
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id, unsigned long param3, unsigned long param4) __attribute__ ((pure, always_inline));\n" % name)
        out.write("static inline uint64_t %s(unsigned long offset, unsigned long block_id, unsigned long param3, unsigned long param4)\n" % name)
        error_message = "%s(\"%s\", %d, %s, %s, %s, %s);" % (FATAL_FUNCTION, name, 4, "offset", "block_id", "param3", "param4")
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
        address_list.append((CHIP_TO_MODEL[chip], range_check, csr[chip].getAddressEquation()))
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
        #
        # Convert the list into a table of the format:
        # model_by_pass["CN61XX"]["PASS1_X"] = line
        #
        model_by_pass = {}
        for line in address_list:
            octeon, chip_model, chip_pass = line[0].split("_", 2)
            if not chip_model in model_by_pass:
                model_by_pass[chip_model] = {}
            model_by_pass[chip_model][chip_pass] = line
        #
        # Simplify entries where all passes are present and they are all
        # the same
        #
        for chip_model in model_by_pass:
            match_line = None
            all_passes = True
            for chip_pass in CHIP_PASS_LIST[chip_model]:
                if not chip_pass in model_by_pass[chip_model]:
                    all_passes = False
            for chip_pass in model_by_pass[chip_model]:
                line = model_by_pass[chip_model][chip_pass]
                if not match_line:
                    match_line = line
                if line[1:] != match_line[1:]:
                    print "Different address lines for passes of %s:" % chip_model
                    print "match", match_line
                    print "line", line
                    all_passes = False
            if all_passes:
                model_by_pass[chip_model] = {"": match_line}
        #
        # Write out the address checking stuff
        #
        out.write("\t")
        t = model_by_pass.keys()
        t.sort()
        for chip_model in t:
            for chip_pass in model_by_pass[chip_model]:
                line = model_by_pass[chip_model][chip_pass]
                full = "OCTEON_" + chip_model
                if chip_pass:
                    full += "_" + chip_pass
                out.write("if (OCTEON_IS_MODEL(%s)%s)\n" % (full, line[1]))
                out.write("\t\treturn %s;\n" % line[2])
                out.write("\telse ")
        out.write("{\n")
        out.write("\t\t%s /* No return */\n" % error_message);
        out.write("\t}\n");
    out.write("}\n");

def write(out, csr, chip_list):
    # Build the constant CHIP_PASS_LIST table on the first call
    if not CHIP_PASS_LIST:
        for chip in chip_list:
            full = CHIP_TO_MODEL[chip]
            octeon, chip_model, chip_pass = full.split("_", 2)
            if not chip_model in CHIP_PASS_LIST:
                CHIP_PASS_LIST[chip_model] = []
            if not chip_pass in CHIP_PASS_LIST[chip_model]:
                CHIP_PASS_LIST[chip_model].append(chip_pass)
    writeAddress(out, csr, chip_list)


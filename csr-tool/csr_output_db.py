from csr_output_addresses import CHIP_TO_MODEL

def toHex(v):
    return hex(v).replace("L","").rjust(18)

#
# Given a dictionary, return its keys sorted by the values they point to. This
# assumes that all values are unique
#
def getKeysSorted(dict):
    swapped = {}
    for k in dict:
        swapped[dict[k]] = k
    keys = swapped.keys()
    keys.sort()
    result = []
    for k in keys:
        result.append(swapped[k])
    return result

#
# Store a string into a global table and return its index. The index
# is half the actual value, requiring string to be a even length. Odd
# length strings will have an added zero when written.
#
globalStringTable = {}
globalStringTableLookup = {}
globalStringTableLen = 0
def getStringTable(str):
    global globalStringTable
    global globalStringTableLookup
    global globalStringTableLen
    str = str.upper()   # Force all strings to upper case
    if not str in globalStringTableLookup:
        for k in globalStringTable:
            if k.endswith(str):
                position = globalStringTable[k] + len(k) - len(str)
                if position & 1 == 0:
                    globalStringTableLookup[str] = position/2
                    return globalStringTableLookup[str]
        globalStringTable[str] = globalStringTableLen
        globalStringTableLookup[str] = globalStringTableLen/2
        globalStringTableLen += len(str) + 1
        if globalStringTableLen & 1 == 1:
            globalStringTableLen += 1
    return globalStringTableLookup[str]

#
# Store a number into a global table and return its index
#
globalNumberTable = {}
globalNumberTableLen = 0
def getNumberTable(n):
    global globalNumberTable
    global globalNumberTableLen
    if not n in globalNumberTable:
        globalNumberTable[n] = globalNumberTableLen
        globalNumberTableLen += 1
    return globalNumberTable[n]

#
# Store a CSR field into a global table and return its index
#
globalFieldTable = {}
globalFieldTableLen = 0
def getFieldTable(field):
    global globalFieldTable
    global globalFieldTableLen
    name_index = getStringTable(field.name)
    key = "%d,%d,%d" % (name_index, field.start_bit, field.stop_bit)
    if not key in globalFieldTable:
        globalFieldTable[key] = globalFieldTableLen
        globalFieldTableLen += 3
    return globalFieldTable[key]

#
# Store a CSR field list into a global table and return its index
#
globalFieldListTable = {}
globalFieldListTableLen = 0
def getFieldListTable(csr):
    global globalFieldListTable
    global globalFieldListTableLen
    bit_list = csr.fields.keys()
    bit_list.sort()
    fieldList = "%d" % len(bit_list)
    for bit in bit_list:
        fieldList += ",%d" % getFieldTable(csr.fields[bit])
    if not fieldList in globalFieldListTable:
        globalFieldListTable[fieldList] = globalFieldListTableLen
        globalFieldListTableLen += len(bit_list) + 1
    return globalFieldListTable[fieldList]

#
# Store a range into a global table and return its index
#
globalRangeTable = {}
globalRangeTableLen = 0
def getRangeTable(range):
    global globalRangeTable
    global globalRangeTableLen
    key = "%d" % len(range)
    for r in range:
        key += ",%d" % r
    if not key in globalRangeTable:
        globalRangeTable[key] = globalRangeTableLen
        globalRangeTableLen += len(range) + 1
    return globalRangeTable[key]

#
# Store a CSR into a global table and return its index
#
globalCsrTable = {}
globalCsrTableLen = 0
def getCsrTable(csr_str):
    global globalCsrTable
    global globalCsrTableLen
    key = csr_str
    if not key in globalCsrTable:
        globalCsrTable[key] = globalCsrTableLen
        globalCsrTableLen += 1
    return globalCsrTable[key]

#
# Create a CSR database
#
def write(file, separate_chip_lists, include_cisco_only):
    out = open(file, "w")
    out.write('#include <bdk.h>\n')
    out.write("\n")
    empty_range = getRangeTable([-1,-1])

    #
    # Write the per chip CSR tables
    #
    null_csr = getCsrTable("{-1, BDK_CSR_TYPE_NCB,0,0,0,0,0,0,0}")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("static const int16_t __bdk_csr_db_%s[] = {\n" % chip)
        for csr in separate_chip_lists[chip_index]:
            if csr.cisco_only and not include_cisco_only:
                continue
            num_fields = len(csr.fields.keys())
            range_len = len(csr.range)
            if range_len == 0:
                range1 = empty_range
                range2 = empty_range
                offset_inc = 0
                block_inc = 0
            elif range_len == 1:
                range1 = getRangeTable(csr.range[0])
                range2 = empty_range
                offset_inc = csr.address_info[1]
                block_inc = 0
            else:
                range1 = getRangeTable(csr.range[1])
                range2 = getRangeTable(csr.range[0])
                offset_inc = csr.address_info[2]
                block_inc = csr.address_info[1]
            name = csr.name.replace("#", "X")
            csr_str = "{%5d, BDK_CSR_TYPE_%s,%d,%3d,%2d,%2d,%s,%s,%s}" % (
                        getStringTable(name), csr.type, csr.getNumBits() / 8, getFieldListTable(csr),
                        range1, range2, getNumberTable(csr.address_info[0]), getNumberTable(offset_inc), getNumberTable(block_inc))
            csr_index = getCsrTable(csr_str)
            out.write("    %d, /* %s */\n" % (csr_index, name))

        out.write("    %d\n" % null_csr)
        out.write("};\n\n")
    #
    # Write the global CSR table
    #
    out.write("const __bdk_csr_db_type_t __bdk_csr_db_csr[] = {\n")
    keys = getKeysSorted(globalCsrTable)
    for key in keys:
        out.write("    %s, /* %d */\n" % (key, globalCsrTable[key]))
    out.write("};\n\n")
    #
    # Write the CSR fieldList table
    #
    out.write("const uint16_t __bdk_csr_db_fieldList[] = {\n")
    keys = getKeysSorted(globalFieldListTable)
    for key in keys:
        out.write("    %s, /* %d */\n" % (key, globalFieldListTable[key]))
    out.write("};\n\n")
    #
    # Write the CSR field table
    #
    out.write("const uint16_t __bdk_csr_db_field[] = {\n")
    keys = getKeysSorted(globalFieldTable)
    for key in keys:
        out.write("    %s, /* %d */\n" % (key, globalFieldTable[key]))
    out.write("};\n\n")
    #
    # Write the CSR range table
    #
    out.write("const int __bdk_csr_db_range[] = {\n")
    keys = getKeysSorted(globalRangeTable)
    for key in keys:
        out.write("    %s, /* %d */\n" % (key, globalRangeTable[key]))
    out.write("};\n\n")
    #
    # Write the CSR string table
    #
    out.write("const char __bdk_csr_db_string[] = ")
    keys = getKeysSorted(globalStringTable)
    for key in keys:
        if len(key) &1 == 0:
            out.write("\n    \"%s\\0\\0\" /* %s/2 */" % (key, globalStringTable[key]))
        else:
            out.write("\n    \"%s\\0\" /* %s/2 */" % (key, globalStringTable[key]))
    out.write("\n    \"\";\n\n")
    #
    # Write the CSR number table
    #
    out.write("const uint64_t __bdk_csr_db_number[] = {\n")
    keys = getKeysSorted(globalNumberTable)
    for key in keys:
        out.write("    %sull, /* %s */\n" % (toHex(key), globalNumberTable[key]))
    out.write("};\n\n")
    #
    # Write the chip id to CSR table map
    #
    out.write("const __bdk_csr_db_map_t __bdk_csr_db[] = {\n")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("    {%s, __bdk_csr_db_%s},\n" % (CHIP_TO_MODEL[chip], chip))
    out.write("    {0, NULL}\n")
    out.write("};\n\n")
    out.close()



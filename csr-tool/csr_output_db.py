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
# Store a string into a global table and return its index
#
globalStringTable = {}
globalStringTableLen = 0
def getStringTable(str):
    global globalStringTable
    global globalStringTableLen
    str = str.upper()   # Force all strings to upper case
    if not str in globalStringTable:
        globalStringTable[str] = globalStringTableLen
        globalStringTableLen += len(str) + 1
    return globalStringTable[str]

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
# Create a CSR database
#
def write(file, separate_chip_lists, include_cisco_only):
    out = open(file, "w")
    out.write('#include <bdk.h>\n')
    out.write("\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    empty_range = getRangeTable([-1,-1])

    #
    # Write the CSR table
    #
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("static const __bdk_csr_db_type_t __bdk_csr_db_%s[] = {\n" % chip)
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
                offset_inc = csr.address_offset_inc
                block_inc = 0
            else:
                range1 = getRangeTable(csr.range[0])
                range2 = getRangeTable(csr.range[1])
                offset_inc = csr.address_offset_inc
                block_inc = csr.address_block_inc
            out.write("    {%5d, BDK_CSR_TYPE_%s,%d,%3d,%2d,%2d,%s,%s,%s},\n" %
                      (getStringTable(csr.name.replace("#", "X")), csr.type, csr.getNumBits() / 8, getFieldListTable(csr),
                       range1, range2, getNumberTable(csr.address_base), getNumberTable(offset_inc), getNumberTable(block_inc)))
        out.write("    {-1, BDK_CSR_TYPE_NCB,0,0,0,0,0,0,0}\n")
        out.write("};\n\n")
    out.write("#endif\n")
    #
    # Write the CSR fieldList table
    #
    out.write("const uint16_t __bdk_csr_db_fieldList[] = {\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    keys = getKeysSorted(globalFieldListTable)
    for key in keys:
        out.write("    %s,\n" % key)
    out.write("#endif\n")
    out.write("};\n\n")
    #
    # Write the CSR field table
    #
    out.write("const uint16_t __bdk_csr_db_field[] = {\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    keys = getKeysSorted(globalFieldTable)
    for key in keys:
        out.write("    %s,\n" % key)
    out.write("#endif\n")
    out.write("};\n\n")
    #
    # Write the CSR range table
    #
    out.write("const int __bdk_csr_db_range[] = {\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    keys = getKeysSorted(globalRangeTable)
    for key in keys:
        out.write("    %s,\n" % key)
    out.write("#endif\n")
    out.write("};\n\n")
    #
    # Write the CSR string table
    #
    out.write("const char __bdk_csr_db_string[] = ")
    out.write("\n#ifndef BDK_DISABLE_CSR_DB")
    keys = getKeysSorted(globalStringTable)
    for key in keys:
        out.write("\n    \"%s\\0\"" % key)
    out.write("\n#endif")
    out.write("\n    \"\";\n\n")
    #
    # Write the CSR number table
    #
    out.write("const uint64_t __bdk_csr_db_number[] = {\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    keys = getKeysSorted(globalNumberTable)
    for key in keys:
        out.write("    %sull,\n" % toHex(key))
    out.write("#endif\n")
    out.write("};\n\n")
    #
    # Write the chip id to CSR table map
    #
    out.write("const __bdk_csr_db_map_t __bdk_csr_db[] = {\n")
    out.write("#ifndef BDK_DISABLE_CSR_DB\n")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("    {%s, __bdk_csr_db_%s},\n" % (CHIP_TO_MODEL[chip], chip))
    out.write("#endif\n")
    out.write("    {0, NULL}\n")
    out.write("};\n\n")
    out.close()



from csr_output_addresses import CHIP_TO_MODEL

def range_string(range):
    result = "{"
    for i in range:
        result += "%d," % i
    result = result[0:-1] + "}"
    return result

#
# Create a CSR database
#
def write(file, separate_chip_lists, include_cisco_only):
    out = open(file, "w")
    out.write('--\n')
    out.write('-- Definitions for Octeon CSR\n')
    out.write('-- Auto generated, do not edit\n')
    out.write('--\n')
    out.write("local csr_db = {\n")
    #
    # Write the per chip CSR tables
    #
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("    %s = {\n" % chip.upper())
        for csr in separate_chip_lists[chip_index]:
            if csr.cisco_only and not include_cisco_only:
                continue
            range_len = len(csr.range)
            if range_len == 0:
                range1 = None
                range2 = None
                offset_inc = 0
                block_inc = 0
            elif range_len == 1:
                range1 = csr.range[0]
                range2 = None
                offset_inc = csr.address_info[1]
                block_inc = 0
            else:
                range1 = csr.range[1]
                range2 = csr.range[0]
                offset_inc = csr.address_info[2]
                block_inc = csr.address_info[1]
            name = csr.name.replace("#", "X")
            out.write("        %s = {\n" % name.upper())
            out.write("            name = \"%s\",\n" % csr.name.upper())
            out.write("            type = \"%s\",\n" % csr.type.upper())
            out.write("            width = %d,\n" % (csr.getNumBits() / 8))
            out.write("            address = 0x%x,\n" % csr.address_info[0])
            if range1:
                out.write("            range1 = %s,\n" % range_string(range1))
                out.write("            range1_inc = 0x%x,\n" % offset_inc)
            if range2:
                out.write("            range2 = %s,\n" % range_string(range2))
                out.write("            range2_inc = 0x%x,\n" % block_inc)
            out.write("            fields = {\n")
            bits = csr.fields.keys()
            bits.sort()
            bits.reverse()
            for bit in bits:
                f = csr.fields[bit]
                out.write("                {name = \"%s\", start = %d, stop = %d},\n" % (f.name.upper(), f.start_bit, f.stop_bit))
            out.write("            }\n")
            out.write("        },\n")
        out.write("    },\n")
    out.write("}\n")
    out.write("return csr_db\n\n")
    out.close()



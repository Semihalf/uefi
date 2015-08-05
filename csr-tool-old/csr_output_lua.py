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
def write(file, separate_chip_infos):
    out = open(file, "w")
    out.write('--\n')
    out.write('-- Definitions for Cavium CSR\n')
    out.write('-- Auto generated, do not edit\n')
    out.write('--\n')
    out.write("local csr_db = {\n")
    #
    # Write the per chip CSR tables
    #
    for chip_info in separate_chip_infos:
        chip = chip_info.name
        out.write("    %s = {\n" % chip.upper())
        for csr in chip_info.iterCsr():
            name = csr.name.replace("#", "X")
            out.write("        %s = {\n" % name.upper())
            out.write("            name = \"%s\",\n" % csr.name.upper())
            out.write("            type = \"%s\",\n" % csr.type.upper())
            out.write("            width = %d,\n" % (csr.getNumBits() / 8))
            out.write("            address = 0x%x,\n" % csr.address_info[0])
            for i in xrange(len(csr.range)):
                r = csr.range[i]
                mult = csr.address_info[i+1]
                out.write("            range%d = %s,\n" % (i+1, range_string(r)))
                out.write("            range%d_inc = 0x%x,\n" % (i+1, mult))
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



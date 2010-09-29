from csr_output_header import writeCopyrightBanner

def toHex(v):
    return hex(v).replace("L","").rjust(18)

def writeValue(out, value):
    out.write(',\t')
    out.write(str(value))

def writeCsrType(out, csr, field_offset, address_offset):
    num_addresses = 0
    for name,address,unused1,unused2 in csr.iterateAddresses():
        num_addresses += 1
    out.write(('\t{"cvmx_' + csr.name + '"').ljust(32))  # the base name of the CSR
    writeValue(out, "CVMX_CSR_DB_TYPE_"+csr.type)   # the type
    writeValue(out, csr.getNumBits())               # the width of the CSR in bits
    writeValue(out, address_offset)                 # the position of the first address in cvmx_csr_db_addresses[] (numblocks*indexnum is #)
    writeValue(out, len(csr.fields.keys()))         # the number of fields in the CSR (and in cvmx_csr_db_fields[])
    writeValue(out, field_offset)                   # the position of the first field in cvmx_csr_db_fields[]
    out.write('},\n')
    return num_addresses

def writeCsrField(out, csr, field, csr_offset):
    out.write(('\t{"' + field.name.upper() + '"').ljust(32))  # name of the field
    writeValue(out, field.start_bit)                # starting bit position of the field
    writeValue(out, field.stop_bit - field.start_bit + 1)# the size of the field in bits
    writeValue(out, csr_offset)                     # position of the CSR containing the field in cvmx_csr_db[] (get alias from there)
    writeValue(out, '"' + field.type + '"')         # the type of the field R/W, R/W1C, ...
    if isinstance(field.reset_value, str):          # set if the reset value is unknown
        writeValue(out, 1)
    else:
        writeValue(out, 0)
    if isinstance(field.typical_value, str):        # set if the reset value is unknown
        writeValue(out, 1)
    else:
        writeValue(out, 0)
    if not isinstance(field.reset_value, str):
        writeValue(out, str(field.reset_value)+"ull") # the reset value of the field
    else:
        writeValue(out, 0)
    if not isinstance(field.typical_value, str):
        writeValue(out, str(field.typical_value)+"ull") # the typical value of the field
    else:
        writeValue(out, 0)
    out.write('},\n')

def writeCsrAddress(out, csr, name, csr_offset):
    for name,address,unused1,unused2 in csr.iterateAddresses():
        out.write(('\t{"' + name + '"').ljust(32))      # CSR name at the supplied address
        writeValue(out, toHex(address)+"ull")           # Address = octeon internal, PCI BAR0 relative, PCI CONFIG relative
        writeValue(out, "CVMX_CSR_DB_TYPE_"+csr.type)   # the type
        writeValue(out, csr.getNumBits())               # the width of the CSR in bits
        writeValue(out, csr_offset)                     # position of the CSR in cvmx_csr_db[]
        out.write('},\n')

def write(file, separate_chip_lists, include_cisco_only):
    out = open(file, "w")
    writeCopyrightBanner(out)
    out.write("/**\n")
    out.write(" * @file\n")
    out.write(" *\n")
    out.write(" * Configuration and status register (CSR) address and type definitions for\n")
    out.write(" * Octeon.\n")
    out.write(" *\n")
    out.write(" * This file is auto generated. Do not edit.\n")
    out.write(" *\n")
    out.write(" * <hr>$" + "Revision" + "$<hr>\n")
    out.write(" *\n")
    out.write(" */\n")
    out.write("\n")
    out.write('#ifdef CVMX_BUILD_FOR_LINUX_KERNEL\n')
    out.write('#include <asm/octeon/cvmx.h>\n')
    out.write('#include <asm/octeon/cvmx-csr-db.h>\n')
    out.write('#else\n')
    out.write('#include "cvmx-csr-db.h"\n')
    out.write('#endif\n')
    out.write("\n")

    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        #
        # Write the CSR table
        #
        out.write("static const CVMX_CSR_DB_TYPE cvmx_csr_db_" + chip + "[] = {\n")
        out.write('\t /* name'.ljust(32))     # the base name of the CSR
        writeValue(out, "---------------type")  # the type
        writeValue(out, "bits")         # the width of the CSR in bits
        writeValue(out, "off")          # the position of the first address in cvmx_csr_db_addresses[] (numblocks*indexnum is #)
        writeValue(out, "#field")       # the number of fields in the CSR (and in cvmx_csr_db_fields[])
        writeValue(out, "fld of */\n")  # the position of the first field in cvmx_csr_db_fields[]
        field_offset = 0    # This is the index into cvmx_csr_db_fields where the fields for this CSR start
        address_offset = 0  # This is the index into cvmx_csr_db_addresses where the addresses for this CSR start
        for csr in separate_chip_lists[chip_index]:
            if csr.cisco_only and not include_cisco_only:
                continue
            address_offset += writeCsrType(out, csr, field_offset, address_offset)
            field_offset += len(csr.fields.keys())
        out.write("\t{NULL,0,0,0,0,0}\n")
        out.write("};\n")
        #
        # Write the CSR address table
        #
        out.write("static const CVMX_CSR_DB_ADDRESS_TYPE cvmx_csr_db_addresses_" + chip + "[] = {\n")
        out.write('\t/* name'.ljust(32))        # CSR name at the supplied address
        writeValue(out, "--------------address")# Address = octeon internal, PCI BAR0 relative, PCI CONFIG relative
        writeValue(out, "---------------type")  # the type
        writeValue(out, "bits")                 # the width of the CSR in bits
        writeValue(out, "csr offset */\n")      # position of the CSR in cvmx_csr_db[]
        csr_offset=0        # This is the index into cvmx_csr_db where the CSR for this address start
        address="0x123"
        for csr in separate_chip_lists[chip_index]:
            if csr.cisco_only and not include_cisco_only:
                continue
            writeCsrAddress(out, csr, csr.name, csr_offset)
            csr_offset+=1
        out.write("\t{NULL,0,0,0,0}\n")
        out.write("};\n")
        #
        # Write the CSR field table
        #
        out.write("static const CVMX_CSR_DB_FIELD_TYPE cvmx_csr_db_fields_" + chip + "[] = {\n")
        out.write('\t/* name'.ljust(32))# name of the field
        writeValue(out, "bit")          # starting bit position of the field
        writeValue(out, "width")        # the size of the field in bits
        writeValue(out, "csr")          # position of the CSR containing the field in cvmx_csr_db[] (get alias from there)
        writeValue(out, "type")         # the type of the field R/W, R/W1C, ...
        writeValue(out, "rst un")       # set if the reset value is unknown
        writeValue(out, "typ un")       # set if the typical value is unknown
        writeValue(out, "reset")        # reset value
        writeValue(out, "typical */\n") # typical value
        csr_offset=0        # This is the index into cvmx_csr_db where the CSR for this field start
        for csr in separate_chip_lists[chip_index]:
            if csr.cisco_only and not include_cisco_only:
                continue
            bit_list = csr.fields.keys()
            bit_list.sort()
            for bit in bit_list:
                writeCsrField(out, csr, csr.fields[bit], csr_offset)
            csr_offset+=1
        out.write("\t{NULL,0,0,0,0,0,0,0,0}\n")
        out.write("};\n")
    out.write("\n")
    out.write("\n")
    out.write("const CVMX_CSR_DB_TYPE *cvmx_csr_db[] = {\n")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("\tcvmx_csr_db_" + chip + ",\n")
    out.write("\tNULL\n")
    out.write("};\n")
    out.write("const CVMX_CSR_DB_ADDRESS_TYPE *cvmx_csr_db_addresses[] = {\n")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("\tcvmx_csr_db_addresses_" + chip + ",\n")
    out.write("\tNULL\n")
    out.write("};\n")
    out.write("const CVMX_CSR_DB_FIELD_TYPE *cvmx_csr_db_fields[] = {\n")
    for chip_index in range(len(separate_chip_lists)):
        chip = separate_chip_lists[chip_index].name
        out.write("\tcvmx_csr_db_fields_" + chip + ",\n")
    out.write("\tNULL\n")
    out.write("};\n")
    out.close()



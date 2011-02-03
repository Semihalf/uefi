import csr_output_addresses

def writeCopyrightBanner(out):
    out.write("/***********************license start***************\n")
    out.write(" * Copyright (c) 2003-2011  Cavium Networks (support@cavium.com). All rights\n")
    out.write(" * reserved.\n")
    out.write(" *\n")
    out.write(" *\n")
    out.write(" * Redistribution and use in source and binary forms, with or without\n")
    out.write(" * modification, are permitted provided that the following conditions are\n")
    out.write(" * met:\n")
    out.write(" *\n")
    out.write(" *   * Redistributions of source code must retain the above copyright\n")
    out.write(" *     notice, this list of conditions and the following disclaimer.\n")
    out.write(" *\n")
    out.write(" *   * Redistributions in binary form must reproduce the above\n")
    out.write(" *     copyright notice, this list of conditions and the following\n")
    out.write(" *     disclaimer in the documentation and/or other materials provided\n")
    out.write(" *     with the distribution.\n")
    out.write("\n")
    out.write(" *   * Neither the name of Cavium Networks nor the names of\n")
    out.write(" *     its contributors may be used to endorse or promote products\n")
    out.write(" *     derived from this software without specific prior written\n")
    out.write(" *     permission.\n")
    out.write("\n")
    out.write(" * This Software, including technical data, may be subject to U.S. export  control\n")
    out.write(" * laws, including the U.S. Export Administration Act and its  associated\n")
    out.write(" * regulations, and may be subject to export or import  regulations in other\n")
    out.write(" * countries.\n")
    out.write("\n")
    out.write(" * TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED \"AS IS\"\n")
    out.write(" * AND WITH ALL FAULTS AND CAVIUM  NETWORKS MAKES NO PROMISES, REPRESENTATIONS OR\n")
    out.write(" * WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT TO\n")
    out.write(" * THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY REPRESENTATION OR\n")
    out.write(" * DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT DEFECTS, AND CAVIUM\n")
    out.write(" * SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES OF TITLE,\n")
    out.write(" * MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR PURPOSE, LACK OF\n")
    out.write(" * VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT, QUIET POSSESSION OR\n")
    out.write(" * CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK ARISING OUT OF USE OR\n")
    out.write(" * PERFORMANCE OF THE SOFTWARE LIES WITH YOU.\n")
    out.write(" ***********************license end**************************************/\n")
    out.write("\n")
    out.write("\n")

def getCname(csr):
    return "bdk_" + csr.name.replace("#","x")

def writeStruct(out, name, csr, showDescr=0):
    out.write("\tstruct " + getCname(csr) + "_" + name + "\n")
    out.write("\t{\n");
    out.write("#if __BYTE_ORDER == __BIG_ENDIAN\n")
    bit_list = csr.fields.keys()
    bit_list.sort()
    bit_list.reverse()
    for bit in bit_list:
        field = csr.fields[bit]
        line = ("\t" + field.c_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        if showDescr and field.description:
            l = line.ljust(45) + "/**< " + "\n".ljust(58).join(field.description).strip() + " */"
            line = ""
            for l in l.split("\n"):
                line += l.rstrip() + "\n";
        else:
            line += "\n"
        out.write(line)
    out.write("#else\n")
    bit_list.sort()
    for bit in bit_list:
        field = csr.fields[bit]
        line = ("\t" + field.c_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        out.write(line + "\n")
    out.write("#endif\n")
    out.write("\t} " + name + ";\n")

def writeCombinedCsr(out, combined_list):
    chips = combined_list.keys()
    chips.sort()
    # Use the combined superset for the common info
    csr = combined_list["s"]
    bits_in_csr = csr.getNumBits()
    out.write("\n")
    out.write("/**\n")
    out.write(" * " + csr.name + "\n")
    if csr.description:
        out.write(" *\n")
        for l in csr.description:
            l = l.rstrip();
            if l:
                out.write(" * %s\n" % l)
            else:
                out.write(" *\n")
    if csr.notes:
        out.write(" *\n")
        out.write(" * Notes:\n")
        for l in csr.notes:
            l = l.rstrip();
            if l:
                out.write(" * %s\n" % l)
            else:
                out.write(" *\n")
    out.write(" */\n")
    typedef_base = getCname(csr)
    out.write("typedef union " + typedef_base + "\n")
    out.write("{\n")
    out.write("\tuint" + str(bits_in_csr) + "_t u;\n")
    out.write("\tuint" + str(bits_in_csr) + "_t u" + str(bits_in_csr) + ";\n")
    writeStruct(out, "s", csr, showDescr=1)
    signatures = {csr.getSignature():typedef_base + "_s"}
    for chip in chips:
        if chip != "s":
            chip_csr = combined_list[chip]
            sig = chip_csr.getSignature()
            if sig in signatures:
                if signatures[sig].endswith("_s"):
                    out.write(("\t/* struct " + signatures[sig]).ljust(38) + " " + chip + "; */\n")
                else:
                    out.write(("\tstruct " + signatures[sig]).ljust(38) + " " + chip + ";\n")
            else:
                writeStruct(out, chip, chip_csr, showDescr=1)
                signatures[sig] = typedef_base + "_" + chip
    out.write("} %s_t;\n" % typedef_base)

def write(file, csr_list, include_cisco_only):
    out = open(file, "w")
    define_name = "__BDK_CSRS_H__"
    out.write("#ifndef " + define_name + "\n")
    out.write("#define " + define_name + "\n")
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
    old_prefix = ""
    for csr in csr_list:
        if csr["s"].cisco_only and not include_cisco_only:
            continue
        writeCombinedCsr(out, csr)
        out.write("\n")
        csr_output_addresses.write(out, csr, csr_list.getChipList())
        cname = getCname(csr["s"])
        macro_name = cname.upper()
        if len(csr["s"].range):
            macro_name += "(...)"
        out.write("#define typedef_%s %s_t\n" % (macro_name, cname))
        out.write("#define bustype_%s BDK_CSR_TYPE_%s\n" % (macro_name, csr["s"].type))
        if len(csr["s"].range) == 0:
            out.write("#define busnum_%s 0\n" % cname.upper())
        elif len(csr["s"].range) == 1:
            out.write("#define busnum_%s(p) (p)\n" % cname.upper())
        else:
            out.write("#define busnum_%s(unused, p) (p)\n" % cname.upper())
        out.write("\n")
    out.write("#endif /* " + define_name + " */\n")
    out.close()



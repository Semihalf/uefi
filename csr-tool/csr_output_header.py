import datetime
from csr_list_combiner import CombinedCsrList
import csr_output_addresses

def writeCopyrightBanner(out):
    year = datetime.date.today().year
    out.write("/* This file is auto-generated. Do not edit */\n")
    out.write("\n")
    out.write("/***********************license start***************\n")
    out.write(" * Copyright (c) 2003-%d  Cavium Networks (support@cavium.com). All rights\n" % year)
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

def writeEnum(out, enum):
    out.write("\n")
    out.write("/**\n")
    out.write(" * Enumeration %s\n" % enum.name)
    if enum.description:
        out.write(" *\n")
        for l in enum.description:
            l = l.rstrip();
            if l:
                out.write(" * %s\n" % l)
            else:
                out.write(" *\n")
    out.write(" */\n")
    out.write("enum %s {\n" % enum.name.lower())
    keys = enum.values.keys()
    keys.sort()
    max_value = 0
    for n in keys:
        if max_value < enum.values[n].value:
            max_value = enum.values[n].value
        out.write("\t%s_%s = 0x%x,\n" % (enum.name, n, enum.values[n].value))
    out.write("\t%s_ENUM_LAST = 0x%x,\n" % (enum.name, max_value+1))
    out.write("};\n")

def writeStruct(out, struct):
    out.write("\n")
    out.write("/**\n")
    out.write(" * Structure %s\n" % struct.name)
    if struct.description:
        out.write(" *\n")
        for l in struct.description:
            l = l.rstrip();
            if l:
                out.write(" * %s\n" % l)
            else:
                out.write(" *\n")
    out.write(" */\n")
    out.write("union " + struct.name.lower() + " {\n")
    width = struct.getWidthBits()
    if width > 64:
        out.write("\tuint64_t u[%d];\n" % (width / 64))
    else:
        assert width == 64
        out.write("\tuint64_t u;\n")
    out.write("\tstruct {\n")
    out.write("#if __BYTE_ORDER == __BIG_ENDIAN\n")
    bit_list = struct.getStartBitList()
    bit_list.reverse()
    for bit in bit_list:
        field = struct.getField(bit)
        line = ("\t\t" + field.enum_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        if field.description:
            l = line.ljust(45) + "/**< [%3d:%3d] %s */" % (field.stop_bit, field.start_bit, "\n".ljust(66).join(field.description).strip())
            line = ""
            for l in l.split("\n"):
                line += l.rstrip() + "\n";
        else:
            line += "\n"
        out.write(line)
    out.write("#else\n")
    bit_list.sort()
    for bit in bit_list:
        field = struct.getField(bit)
        line = ("\t\t" + field.enum_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        out.write(line + "\n")
    out.write("#endif\n")
    out.write("\t} s;\n")
    out.write("};\n")

def writeCsrStruct(out, name, csr, showDescr=0):
    out.write("\tstruct bdk_" + csr.getCname().lower() + "_" + name + " {\n")
    out.write("#if __BYTE_ORDER == __BIG_ENDIAN\n")
    bit_list = csr.fields.keys()
    bit_list.sort()
    bit_list.reverse()
    for bit in bit_list:
        field = csr.fields[bit]
        line = ("\t\t" + field.c_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        if showDescr and field.description:
            l = line.ljust(45) + "/**< %s - %s */" % (field.type, "\n".ljust(66).join(field.description).strip())
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
        line = ("\t\t" + field.c_type + " " + field.name).ljust(38) + " : " + str(field.stop_bit-field.start_bit+1) + ";"
        out.write(line + "\n")
    out.write("#endif\n")
    out.write("\t} " + name + ";\n")

def writeCombinedCsr(out, combined_list, chip_info):
    chips = combined_list.keys()
    chips.sort()
    # Use the combined superset for the common info
    csr = combined_list["s"]
    bits_in_csr = csr.getNumBits()
    out.write("\n")
    out.write("/**\n")
    out.write(" * %s - %s\n" % (csr.type, csr.name))
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
    typedef_base = "bdk_" + csr.getCname()
    typedef_base = typedef_base.lower()
    out.write("typedef union " + typedef_base + " {\n")
    out.write("\tuint" + str(bits_in_csr) + "_t u;\n")
    writeCsrStruct(out, "s", csr, showDescr=1)
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
                writeCsrStruct(out, chip, chip_csr, showDescr=1)
                signatures[sig] = typedef_base + "_" + chip
    out.write("} %s_t;\n" % typedef_base)
    out.write("\n")
    csr_output_addresses.write(out, combined_list, combined_list.keys())
    macro_name = typedef_base.upper()
    if len(combined_list["s"].range) == 0:
        out.write("#define typedef_%s %s_t\n" % (macro_name, typedef_base))
        out.write("#define bustype_%s BDK_CSR_TYPE_%s\n" % (macro_name, combined_list["s"].type))
        out.write("#define busnum_%s 0\n" % macro_name)
        out.write("#define arguments_%s -1,-1,-1,-1\n" % macro_name)
        out.write("#define basename_%s \"%s\"\n" % (macro_name, macro_name[4:]))
    else:
        out.write("#define typedef_%s(...) %s_t\n" % (macro_name, typedef_base))
        out.write("#define bustype_%s(...) BDK_CSR_TYPE_%s\n" % (macro_name, combined_list["s"].type))
        params = "p1"
        params_paren = "(p1)"
        for p in range(1, len(combined_list["s"].range)):
            params += ",p%d" % (p+1)
            params_paren += ",(p%d)" % (p+1)
        # params_paren must always have 4 arguments
        for p in range(len(combined_list["s"].range), 4):
            params_paren += ",-1"
        out.write("#define busnum_%s(%s) (p1)\n" % (macro_name, params))
        out.write("#define arguments_%s(%s) %s\n" % (macro_name, params, params_paren))
        out.write("#define basename_%s(...) \"%s\"\n" % (macro_name, macro_name[4:]))
    out.write("\n")

def write_file(group, file, csr_list, chip_info):
    out = open(file, "w")
    define_name = "__BDK_CSRS_%s__" % group.upper()
    out.write("#ifndef " + define_name + "\n")
    out.write("#define " + define_name + "\n")
    writeCopyrightBanner(out)
    out.write("/**\n")
    out.write(" * @file\n")
    out.write(" *\n")
    out.write(" * Configuration and status register (CSR) address and type definitions for\n")
    out.write(" * Cavium %s.\n" % group)
    out.write(" *\n")
    out.write(" * This file is auto generated. Do not edit.\n")
    out.write(" *\n")
    out.write(" */\n")
    out.write("\n")
    out.write("#include <stdint.h>\n")
    out.write("\n")
    out.write("extern void csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));\n")
    out.write("\n")
    header = False
    for bar in chip_info.iterBar():
        if bar.group != group:
            continue
	if header == False:
	    out.write("\n")
	    out.write("/**\n")
	    out.write(" * Bar %s\n" % bar.enum_name)
	    if bar.description:
		out.write(" *\n")
		for l in bar.description:
		    l = l.rstrip();
		    if l:
			out.write(" * %s\n" % l)
		    else:
			out.write(" *\n")
	    out.write(" */\n")
	    out.write("#ifdef __cplusplus\n")
	    out.write("namespace %s {\n" % bar.enum_name)
	    header = True
        out.write("\tconst uint64_t %s = 0x%x;\n" % (bar.name, bar.start))
        out.write("\tconst uint64_t %s_PCC_BAR_SIZE_BITS = %u;\n" % (bar.name, bar.size))
    if header:
        out.write("};\n")
        out.write("#endif\n")
	
    for enum in chip_info.iterEnum():
        if enum.group != group:
            continue
        writeEnum(out, enum)
    out.write("\n")
    for struct in chip_info.iterStruct():
        if struct.group != group:
            continue
        writeStruct(out, struct)
    out.write("\n")
    for csr in csr_list:
        if csr["s"].group != group:
            continue
        writeCombinedCsr(out, csr, chip_info)
    out.write("#endif /* " + define_name + " */\n")
    out.close()

def write(file, csr_list, chip_info):
    groups = []
    for csr in csr_list:
        g = csr["s"].group
        if not g in groups:
            groups.append(g)
    groups.sort()
    out_all = open(file, "w")
    out_all.write("#ifndef __BDK_CSRS_H__\n")
    out_all.write("#define __BDK_CSRS_H__\n")
    writeCopyrightBanner(out_all)
    out_all.write("/* Include all CSR files for easy access */\n")
    for g in groups:
        filename = file.replace(".h", "-%s.h" % g.lower())
        write_file(g, filename, csr_list, chip_info)
        out_all.write("#include \"%s\"\n" % filename.split("/")[-1])
    out_all.write("#endif /* __BDK_CSRS_H__ */\n")
    out_all.close()


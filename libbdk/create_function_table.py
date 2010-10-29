#!/usr/bin/python

import os
import sys

def read_functions(elf, func_list):
    file = os.popen("mipsisa64-octeon-elf-readelf --wide -s %s | grep GLOBAL | grep FUNC" % elf)
    for line in file:
        parts = line.split()
        func = parts[-1]
        if not func in func_list:
            func_list.append(func)
    file.close()
    return func_list

def filter(list, prefix):
    result = []
    for e in list:
        if e.startswith(prefix):
            result.append(e)
    return result

def write_function_table(out, table_name, functions):
    out.write("\n")
    for f in functions:
        out.write("extern void %s();\n" % f)
    out.write("\n")
    out.write("const struct {const char *name; void *func;} %s[] = {\n" % table_name)
    for f in functions:
        out.write("    {\"%s\", %s},\n" % (f, f))
    out.write("    {0, 0}\n")
    out.write("};\n")
    out.write("\n")



all_funcs = []
for elf in sys.argv[2:]:
    read_functions(elf, all_funcs)

bdk_funcs = filter(all_funcs, "bdk_")
bdk_funcs.sort()

out = open(sys.argv[1], "w")
write_function_table(out, "bdk_functions", bdk_funcs)
out.close()


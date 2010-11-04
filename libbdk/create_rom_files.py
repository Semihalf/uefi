#!/usr/bin/python

import os
import sys

def write_file(out, var_name, filename):
    inf = open(filename, "rb")
    file = inf.read()
    inf.close()
    out.write("static const char %s[] = {\n" % var_name)
    count = 0
    out.write("    ")
    for b in file[0:-1]:
        out.write("0x%02x, " % ord(b))
        count += 1
        if count == 16:
            out.write("\n    ")
            count = 0
    out.write("0x%02x};\n" % ord(file[-1]))
    out.write("\n")

out_filename = sys.argv[1]
prefix = sys.argv[2]
out = open(out_filename, "w")
out.write("#include \"bdk-fs-rom.h\"\n")
count = 0
for name in sys.argv[3:]:
    count += 1
    write_file(out, "file%d" % count, name)
out.write("const bdk_fs_rom_t bdk_fs_rom_files[] = {\n")
count = 0
for name in sys.argv[3:]:
    count += 1
    out.write("    {\"%s\", file%d, sizeof(file%d)},\n" % (name.replace(prefix,""), count, count))
out.write("    {0, 0, 0}\n")
out.write("};\n")
out.write("\n")
out.close()


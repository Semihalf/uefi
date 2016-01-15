#!/usr/bin/python
import sys
import struct

def usage():
    print 'USAGE: %s input_file output_file' % sys.argv[0]

def main():
    try:
        input_file  = sys.argv[1]
        output_file = sys.argv[2]
    except:
        usage()
        exit(-1)

    try:
        fin  = open(input_file, 'r')
    except:
        print 'ERROR: Can not open input file', input_file
        exit(-1)

    try:
        fout = open(output_file, 'w')
    except:
        print 'ERROR: Can not open output file', output_file
        fin.close()
        exit(-1)

    line = fin.readline()
    while (line):
        items = line.split()
        if not items:
            line = fin.readline()
            continue

        # Only parse 'write' lines
        if 'write' != items[0]:
            line = fin.readline()
            continue

        reg = int(items[1], 16)
        val = int(items[2], 16)
        fout.write(struct.pack('H', reg))
        fout.write(struct.pack('H', val))
        line = fin.readline()

    fin.close()
    fout.close()

if __name__ == "__main__":
    main()

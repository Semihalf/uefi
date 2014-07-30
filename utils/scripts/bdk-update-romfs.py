#!/usr/bin/python

import os
import sys
import binascii
import struct

BOOTLOADER_HEADER_MAGIC = "BOOT"
BOOTLOADER_HEADER_COMMENT_LEN = 64
BOOTLOADER_HEADER_VERSION_LEN = 64
BOOTLOADER_HEADER_SIZE = 0xc0
BOOTLOADER_HEADER_MAX_SIZE = 0x200

BOOTLOADER_HEADER_CURRENT_MAJOR_REV = 1
BOOTLOADER_HEADER_CURRENT_MINOR_REV = 2
BOOTLOADER_HEADER_BOARD_GENERIC = 28
BOOTLOADER_HEADER_IMAGE_TYPE = 3

def pack(width, data):
    if width == 1:
        return struct.pack(">B", data)
    elif width == 2:
        return struct.pack(">H", data)
    elif width == 4:
        return struct.pack(">I", data)
    elif width == 8:
        return struct.pack(">Q", data)
    else:
        raise Exception("Invalid width")


def load_file(filename):
    inf = open(filename, "rb")
    file = inf.read()
    inf.close()
    return file

def update_header(filename, data):
    raw_instructions = data[0:8]
    data = data[BOOTLOADER_HEADER_SIZE:]
    # Header begins with two raw instructions for 8 bytes
    header = raw_instructions
    # Four bytes of magic number
    header += BOOTLOADER_HEADER_MAGIC
    # Header CRC - filled later
    header += pack(4, 0)
    # Header length
    header += pack(2, 0)
    # Major revision
    header += pack(2, BOOTLOADER_HEADER_CURRENT_MAJOR_REV)
    # Minor revision
    header += pack(2, BOOTLOADER_HEADER_CURRENT_MINOR_REV)
    # Board Type
    header += pack(2, BOOTLOADER_HEADER_BOARD_GENERIC)
    # Data length
    header += pack(4, len(data))
    # Data CRC
    header += pack(4, 0xffffffffL & binascii.crc32(data))
    # Load virtual address
    header += pack(8, 0xffffffffe0000000L)
    # Flags
    header += pack(4, 0)
    # Image type
    header += pack(2, BOOTLOADER_HEADER_IMAGE_TYPE)
    # Reserved0
    header += pack(2, 0)
    # Reserved1
    header += pack(4, 0)
    # Reserved2
    header += pack(4, 0)
    # Reserved3
    header += pack(4, 0)
    # Reserved4
    header += pack(4, 0)
    # Comment string
    header += "".ljust(BOOTLOADER_HEADER_COMMENT_LEN).replace(" ", "\0")
    # Version string
    header += "".ljust(BOOTLOADER_HEADER_VERSION_LEN).replace(" ", "\0")
    # Fix Header length
    header = header[0:16] + pack(2, len(header)) + header[18:]
    # Fix the Header CRC
    header = header[0:12] + pack(4, 0xffffffffL & binascii.crc32(header[0:12]+header[16:])) + header[16:]
    # Write the new file
    fhandle = open(filename, "wb")
    # Write the header
    fhandle.write(header)
    # Rewrite the data
    fhandle.seek(BOOTLOADER_HEADER_SIZE)
    fhandle.write(data)
    # Close, we're done
    fhandle.close()

if len(sys.argv) < 3:
    print
    print "Usage:"
    print "    %s new_image old_image [rom files...]" % sys.argv[0]
    print
    print "Update the Uboot image header in a '*.bin' file and possibly"
    print "add files to the image for use in the '/rom' filesystem."
    print
    print "    new_image: File name to write new bin image to."
    print "    old_image: File name of base bin image."
    print "    rom files: Optional list of file names to add to the image"
    print "               for use by the '/rom' file system. For example,"
    print "               'rom/*' includes all files in the BDK rom directory."
    print
    sys.exit(1)


out_filename = sys.argv[1]
in_filename = sys.argv[2]
rom_filenames = sys.argv[3:]

image_file = load_file(in_filename)
# ROM files are stored sequencially after the end of the image, starting
# at the _end symbol. Each ROM file starts with six bytes "ROM-FS",
# a two byte filename length, a four byte file length, the bytes for
# the filename, and the file's data. The filename is not \0 terminated.
for rom in rom_filenames:
    if rom.endswith(".lua"):
        # Compile Lua files to save space
        os.system(os.getenv("BDK_ROOT") + "/bin/bdk-luac -s -o luac.out " + rom)
        rom_file = load_file("luac.out")
        os.system("rm luac.out")
    else:
        rom_file = load_file(rom)
    name = rom.split("/")[-1]
    tmp = "ROM-FS"
    tmp += pack(2, len(name))
    tmp += pack(4, len(rom_file))
    tmp += name
    tmp += rom_file
    image_file += tmp

update_header(out_filename, image_file)


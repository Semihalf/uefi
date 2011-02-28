#!/usr/bin/python

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

def update_header(filename):
    fhandle = open(filename, "rb")
    raw_instructions = fhandle.read(8)
    fhandle.seek(BOOTLOADER_HEADER_SIZE)
    data = fhandle.read()
    fhandle.close()
    # Header begins with two raw mips instructions for 8 bytes
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
    header += pack(4, 0xffffffff & binascii.crc32(data))
    # Load virtual address
    header += pack(8, 0xffffffffe0000000)
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
    header += "".ljust(BOOTLOADER_HEADER_COMMENT_LEN, "\0")
    # Version string
    header += "".ljust(BOOTLOADER_HEADER_VERSION_LEN, "\0")
    # Fix Header length
    header = header[0:16] + pack(2, len(header)) + header[18:]
    # Fix the Header CRC
    header = header[0:12] + pack(4, 0xffffffff & binascii.crc32(header[0:12]+header[16:])) + header[16:]
    # Write the new file
    fhandle = open(filename, "wb")
    # Write the header
    fhandle.write(header)
    # Rewrite the data
    fhandle.seek(BOOTLOADER_HEADER_SIZE)
    fhandle.write(data)
    # Close, we're done
    fhandle.close()

if len(sys.argv) == 2:
    update_header(sys.argv[1])
else:
    print("Usage:")
    print("    bdk-update-header <filename>")






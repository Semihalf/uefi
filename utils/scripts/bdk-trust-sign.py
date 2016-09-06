#!/usr/bin/python
# ***********************license start***********************************
# Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
# reserved.
#
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#   * Redistributions in binary form must reproduce the above
#     copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided
#     with the distribution.
#
#   * Neither the name of Cavium Inc. nor the names of
#     its contributors may be used to endorse or promote products
#     derived from this software without specific prior written
#     permission.
#
# This Software, including technical data, may be subject to U.S. export
# control laws, including the U.S. Export Administration Act and its
# associated regulations, and may be subject to export or import
# regulations in other countries.
#
# TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
# AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
# WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
# TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
# REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
# DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
# OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
# PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
# QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
# ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
# **********************license end**************************************

import argparse
import base64
import binascii
import hashlib
import os
import random
import struct
import subprocess
import sys
import ecdsa

ROTPK = "" # Root of trust public key bytes

#
# Argument parser. Results is a namespace with:
# result.command = genkey, sign
# result.file = Name of for genkey, or bdk image for sign
# result.encrypt = Hex AES key for encryption, or nothing
# result.key = Filename of private key for signing
#
def do_arg_parse():
    parser = argparse.ArgumentParser(description="Sign, and optionally encrypt the BDK boot stub for use with trusted boot")
    subparsers = parser.add_subparsers(title="supported commands",
                                       help="Operation to be performed, listed below",
                                       dest="command")

    genkey = subparsers.add_parser("genkey",
                                   help="Generate a new Root of Trust signing key",
                                   description="Generate a new Root of Trust signing key")
    genkey.add_argument("file", type=str, help="Generate a new Public/Private key pair, written to FILE")

    sign = subparsers.add_parser("sign",
                                 help="Sign an image for trusted boot",
                                 description="Sign an image for trusted boot")
    sign.add_argument("--key", type=str, required=True, help="Key file to use for signing (Required)")
    sign.add_argument("--encrypt", type=str, required=False, help="Encrypt the trusted boot stub with AES128 key (SSK HEX string)")
    sign.add_argument("--fuses", required=False, action="store_true", help="Display the fuses setting required for this image")
    sign.add_argument("file", type=str, help="BDK image file to sign for trusted boot")
    return parser.parse_args()

#
# Generate a Thunder ROM_CSIB_S structure
#
def generate_csib(crypt_type, boot_image):
    global ROTPK
    # Word 0
    csib = struct.pack("<Q", 0x424953435f4d5643) # Magic
    assert len(csib) == 8
    # Word 1
    csib_expose = 0
    csib_bkpt = 0
    csib_siden = 0
    csib_flags = (csib_expose << 7) | (csib_bkpt << 6) | (csib_siden << 4) | crypt_type
    csib += struct.pack("<B", csib_flags) # Above Flags
    csib += struct.pack("<B", 0) * 5 # 5 unused bytes
    csib += struct.pack("<B", 0) # NV count
    csib += struct.pack("<B", 0) # Version
    # Word 2
    csib += struct.pack("<Q", 0) # Reserved
    # Word 3
    csib += struct.pack("<Q", len(boot_image)) # Size
    # Word 4-7
    csib += hashlib.sha256(boot_image).digest()
    # Word 8-15
    assert len(ROTPK) == 64, "Public key must be two 256 bits numbers, 64 bytes"
    csib += ROTPK
    # Word 16-25
    csib += struct.pack("<Q", 0) * 10 # Reserved for software
    # Word 26-27
    csib += struct.pack("<Q", 0) * 2 # Sofware name / UUID
    # Word 28-31
    csib += struct.pack("<Q", random.getrandbits(64)) # Random Nonce
    csib += struct.pack("<Q", random.getrandbits(64)) # Random Nonce
    csib += struct.pack("<Q", random.getrandbits(64)) # Random Nonce
    csib += struct.pack("<Q", random.getrandbits(64)) # Random Nonce
    assert len(csib) == 256, "CSIB should be 256 bytes"
    return csib

#
# Generate a Thunder ROM_CLIB_S structure
#
def generate_clib(csib, offset, size, private_key):
    # Word 0
    clib = struct.pack("<Q", 0x42494c435f4d5643) # Magic
    # Word 1
    clib += struct.pack("<Q", 0) # Version and reserved
    # Word 2
    clib += struct.pack("<Q", offset) # Offset
    # Word 3
    clib += struct.pack("<Q", size) # Size
    # Word 4-7
    clib += struct.pack("<Q", 0) * 4 # Reserved
    # Word 8-15
    clib += sign_blob(csib, private_key)
    # Word 16-31
    clib += struct.pack("<Q", 0) * 16 # Reserved
    assert len(clib) == 256, "CLIB should be 256 bytes"
    return clib

#
# Sign a CSIB blob with the given private key file
# Result is 64 bytes
#
def sign_blob(blob, private_key):
    priv_key = ecdsa.SigningKey.from_pem(open(private_key).read())
    assert priv_key
    sign = priv_key.sign_deterministic(blob, hashfunc=hashlib.sha256)
    assert len(sign) == 64
    # Break into the R and S number
    r = sign[0:32]
    s = sign[32:64]
    # Results is R followed by S in little endian format
    return r[::-1] + s[::-1]

#
# Encrypt an image (binary string) with AES using key (hex string)
#
def encrypt_image(image, key):
    # The IV is hard coded as zero
    iv = "00000000000000000000000000000000"
    assert len(key) == 32, "AES key must be 32 hex chars, 128 bits"
    p = subprocess.Popen(["openssl", "enc", "-aes-128-cbc", "-e", "-K", key, "-iv", iv, "-nopad"],
                         stdin=subprocess.PIPE, stdout=subprocess.PIPE,
                         stderr=subprocess.PIPE)
    out, err = p.communicate(image)
    assert p.returncode == 0, "openssl command failed"
    assert len(out) == len(image)
    return out

#
# Read the public key from a private key file
#
def read_pub_key(private_key):
    inf = open(private_key, "rb")
    pem = inf.read()
    inf.close()
    priv_key = ecdsa.SigningKey.from_pem(pem)
    pub = priv_key.get_verifying_key().to_string()
    assert len(pub) == 64, "Public key must be two 256 bits numbers, 64 bytes"
    r = pub[0:32]
    s = pub[32:64]
    return r[::-1] + s[::-1]

#
# Command: Generate a new private key
#
def cmd_genkey(args):
    private_key = ecdsa.SigningKey.generate(curve=ecdsa.NIST256p)
    outf = open(args.file, "wb")
    outf.write(private_key.to_pem())
    outf.close()
    return 0

#
# Command: Sign an image
#
def cmd_sign(args):
    global ROTPK
    # Read the input image file
    inf = open(args.file, "r")
    bdk_image = inf.read()
    inf.close()
    bdk_image_len = len(bdk_image)
    assert bdk_image_len >= 0x80000, "Images must be at least 512KB"

    # Read the Root of Trust key
    ROTPK = read_pub_key(args.key)

    # Update non-secure image. We will do full signing even though the
    # boot ROM doesn't check it
    boot_stub = bdk_image[0x20000:0x50000]
    csib = generate_csib(0, boot_stub)
    clib = generate_clib(csib, 0x20000, len(boot_stub), args.key)
    bdk_image = bdk_image[0:0x10000] + clib + bdk_image[0x10100:]
    bdk_image = bdk_image[0:0x10100] + csib + bdk_image[0x10200:]

    # Update secure image
    boot_stub = bdk_image[0x50000:0x80000]
    crypt_type = 0 # Sign only
    if args.encrypt:
        crypt_type = 1 # Sign and encrypt with SSK
    csib = generate_csib(crypt_type, boot_stub)
    clib = generate_clib(csib, 0x50000, len(boot_stub), args.key)
    bdk_image = bdk_image[0:0x10200] + clib + bdk_image[0x10300:]
    bdk_image = bdk_image[0:0x10300] + csib + bdk_image[0x10400:]
    # Encrypt the image if necessary
    if args.encrypt:
        bdk_image = bdk_image[0:0x50000] + encrypt_image(boot_stub, args.encrypt) + bdk_image[0x80000:]
    # Make sure the file size didn't change
    assert len(bdk_image) == bdk_image_len, "Images corrupted, length changed"
    # Write the output file
    out = open(args.file, "w")
    out.write(bdk_image)
    out.close()
    # Display fuses if desired
    if args.fuses:
        rotpk_sha = hashlib.sha256(ROTPK).digest()
        fusf_rotpkx = [rotpk_sha[0:8], rotpk_sha[8:16], rotpk_sha[16:24], rotpk_sha[24:32]]
        print "Field Fuses:"
        print "0x3ff:0x300 (ROTPK SHA256) " + binascii.hexlify(rotpk_sha[::-1])
        if args.encrypt:
            print "0x47f:0x400 (SSK)   " + args.encrypt
        print
        print "Asim:"
        print "control n0.gpio0 set strap 0x405"
        print "mm8 0x87e004000060 = 0x%s secure external" % binascii.hexlify(fusf_rotpkx[0][::-1])
        print "mm8 0x87e004000068 = 0x%s secure external" % binascii.hexlify(fusf_rotpkx[1][::-1])
        print "mm8 0x87e004000070 = 0x%s secure external" % binascii.hexlify(fusf_rotpkx[2][::-1])
        print "mm8 0x87e004000078 = 0x%s secure external" % binascii.hexlify(fusf_rotpkx[3][::-1])
        if args.encrypt:
            print "mm8 0x87e004000080 = 0x%s secure external" % args.encrypt[0:16][::-1]
            print "mm8 0x87e004000088 = 0x%s secure external" % args.encrypt[16:32][::-1]

        fuse_list = []
        fuse = 0x300
        for b in rotpk_sha:
            byte = ord(b)
            for bit in range(8):
                if byte & (1<<bit):
                    fuse_list.append("0x%x" % fuse)
                fuse += 1
        if args.encrypt:
            aes_key = binascii.unhexlify(args.encrypt)[::-1]
            fuse = 0x400
            for b in aes_key:
                byte = ord(b)
                for bit in range(8):
                    if byte & (1<<bit):
                        fuse_list.append("0x%x" % fuse)
                    fuse += 1
        print
        print "BDK Lua:"
        print "for _,fuse in ipairs({" + ",".join(fuse_list) + "}) do; cavium.c.bdk_fuse_field_soft_blow(0,fuse); end"
    return 0

#
# Main entry point
#
def main():
    args = do_arg_parse()
    if args == None:
        return 1
    elif args.command == "genkey":
        return cmd_genkey(args)
    elif args.command == "sign":
        return cmd_sign(args)

# Call main
sys.exit(main())

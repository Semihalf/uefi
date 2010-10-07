import re
from csr_fixes import fixCsrName
from csr_fixes import fixCsr
from types import *
from csr_output_addresses import toHex, getBitMask

VALID_FIELD_TYPES = ["RAZ",     # Read as zero
                     "R/W",     # Read / Write
                     "R/W1C",   # Read, write ones to clear
                     "R/W0C",   # Read, write zeros to clear
                     "RO",      # Read only
                     "RC/W",    # Read to clear, write
                     "RC",      # Read clear
                     "WO",      # Write only
                     "R/W1",    # Read, write one
                     "WR0",
                     "RO/WRSL", # Read only, cna be written through RSL
                     "WORSL"]
VALID_CSR_TYPES = ["RSL", "NCB", "PCICONFIG", "PCI", "PCI_NCB",
                   "PEXP",          # PCIe BAR 0 address only
                   "PEXP_NCB",      # NCB-direct and PCIe BAR0 address
                   "PCICONFIGEP", "PCICONFIGEP0", "PCICONFIGEP1",   # PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR
                   "PCICONFIGRC", "PCICONFIGRC0", "PCICONFIGRC1",   # PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR
                   "SRIOMAINT", "SRIOMAINT0", "SRIOMAINT1"]

#
# This class contains a list of CSRs for a specific chip. It is iterable, so
# you can use it in loops and such
#
class CsrList:
    def __init__(self, name):
        assert isinstance(name, StringType), type(name)
        self.name = name
        self._csrs = {}

    def __iter__(self):
        keys = self._csrs.keys()
        keys.sort()
        sorted = []
        for k in keys:
            sorted.append(self._csrs[k])
        return sorted.__iter__()

    def addCsr(self, csr):
        assert isinstance(csr, Csr), type(Csr)
        if csr.name in self._csrs:
            existing = self._csrs[csr.name]
            if len(csr.fields) != len(existing.fields):
                raise Exception("Two CSRs with same name but differnet bits")
            for bit in csr.fields:
                if not bit in existing.fields:
                    raise Exception("Two CSRs with same name but differnet bits")
            if len(csr.range) !=  len(existing.range):
                raise Exception("Two CSRs with same name but differnet range number")
            for i in range(len(csr.range)):
                if len(csr.range[i]) != 2:
                    raise Exception("Illegal range added")
                if existing.range[i][-1]+1 == csr.range[i][0]:
                    # New range continues an existing range
                    existing.range[i][-1] = csr.range[i][1]
                else:
                    # New range is disjoint from existing range
                    existing.range[i].extend(csr.range[i])
                    #if len(existing.range[i]) != 4:
                    #    raise Exception("Not allowed to have more than one disjoint range: " + str(existing.range))
        else:
            self._csrs[csr.name] = csr

#
# The basic definition of a CSR. Each one only supports a single chip's version
#
class Csr:
    def __init__(self, name, csr_type, description, notes=[]):
        assert isinstance(name, ListType), type(name)
        assert isinstance(csr_type, StringType), type(csr_type)
        assert isinstance(description, ListType), type(description)
        assert isinstance(notes, ListType), type(notes)
        name = fixCsrName(name)
        self.name = ""
        self.range = []
        while len(name):
            self.name += name[0]
            if len(name) > 1:
                self.name += "#"
                r = []
                r.extend(name[1])
                self.range.append(r)
                name = name[2:]
            else:
                name = []
        self.name = self.name.lower()
        if len(self.range) > 2:
            raise Exception("Having a CSR with more than two indexes isn't allowed: " + str(self.range))
        self.type = csr_type
        self.description = description
        self.fields = {}
        self.addresses = {}
        self.cisco_only = 0
        self.setNotes(notes)
        self.address_base = 0
        self.address_block_inc = 0xbadbadbadbad
        self.address_offset_inc = 0xbadbadbadbad
        self.pci_alias = -1
        for i in xrange(len(self.description)-1, -1, -1):
            if "CISCO-SPECIFIC" in self.description[i]:
                self.cisco_only = 1
                del self.description[i]

    def addField(self, field):
        assert isinstance(field, CsrField), type(field)
        if field.start_bit in self.fields:
            raise Exception("Field start bit alread in use")
        self.fields[field.start_bit] = field

    def getField(self, name):
        for bit in self.fields:
            if self.fields[bit].name == name:
                return self.fields[bit]
        raise Exception("CSR %s, field %s not found" % (self.name, name))

    def setNotes(self, notes):
        assert isinstance(notes, ListType), type(notes)
        for i in xrange(len(notes)-1, -1, -1):
            if "CISCO-SPECIFIC" in notes[i]:
                self.cisco_only = 1
                del notes[i]
        self.notes = notes

    def getNumBits(self):
        field_keys = self.fields.keys()
        field_keys.sort()
        return self.fields[field_keys[-1]].stop_bit + 1

    def getSignature(self, include_all=0):
        signature = ""
        field_keys = self.fields.keys()
        field_keys.sort()
        for bit in field_keys:
            field = self.fields[bit]
            signature += "+" + str(field.start_bit) + "-" + str(field.stop_bit) + "," + field.c_type + "," + field.name
            if include_all:
                signature += "+%s,%s,%s" % (field.type, str(field.reset_value), str(field.typical_value))
        return signature

    def validateRange(self):
        assert len(self.range) < 3
        for range_list in self.range:
            last = 0
            for i in range_list:
                assert i >= 0
                assert i < 65536
                assert i >= last
                last = i

    def validateBits(self):
        # Combine all reserved fields that are next to each other
        bits = self.fields.keys()
        bits.sort()
        while bits:
            bit = bits[0]
            next_bit = self.fields[bit].stop_bit + 1
            if not next_bit in self.fields:
                break
            if self.fields[bit].name.startswith("reserved") and self.fields[next_bit].name.startswith("reserved"):
                self.fields[bit].stop_bit = self.fields[next_bit].stop_bit
                self.fields[bit].name = "reserved_" + str(self.fields[bit].start_bit) + "_" + str(self.fields[bit].stop_bit)
                del self.fields[next_bit]
                del bits[1]
            else:
                bits = bits[1:]
        # Build a bit mask to check the field bits in
        bitmask = []
        for i in range(0,64):
            bitmask.append(0)

        # Set all the bits used by fields. Don't allow fields to overlap
        for f in self.fields:
            field = self.fields[f]
            for bit in range(field.start_bit, field.stop_bit+1):
                if bitmask[bit] == 0:
                    bitmask[bit] = 1
                else:
                    raise Exception("Bit overlap in CSR")

        # If only the lower 32 bits are used then truncate down to 32 bits
        if sum(bitmask[32:64]) == 0:
            bitmask = bitmask[0:32]
            default_c_type = "uint32_t"
        else:
            default_c_type = "uint64_t"

        # Make sure all bits are account for
        for bit in bitmask:
            if bit == 0:
                raise Exception("Unused Bit in CSR: " + str(bitmask))

        # Set the c_type if it isn't set already
        for f in self.fields:
            field = self.fields[f]
            if not field.c_type:
                field.c_type = default_c_type

    def validateAddresses(self):
        # Require everyone except PCI(e) and SRIOMAINT to start at non zero
        assert (self.address_base != 0) or (self.type == "PCI") or (self.type == "PCICONFIGEP") or (self.type == "PCICONFIGRC") or (self.type == "PEXP") or (self.type == "SRIOMAINT")
        if len(self.range) == 0:
            # No range data, so both increments must be bad
            assert self.address_offset_inc == 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_offset_inc)
            assert self.address_block_inc == 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_block_inc)
        elif len(self.range) == 1:
            # Increment must not be bad
            assert self.address_offset_inc != 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_offset_inc)
            if self.range[0][0] == self.range[0][-1]:
                # Force increment to be zero if range only covers one value
                assert self.address_offset_inc == 0, "%s 0x%x" % (self.name, self.address_offset_inc)
            else:
                if self.type in ["PCICONFIGEP", "PCICONFIGRC", "SRIOMAINT"]:
                    # PCI(e) and SRIO MAINT are special in that they have the same address on all ports
                    assert self.address_offset_inc == 0, "%s 0x%x" % (self.name, self.address_offset_inc)
                else:
                    # Increment must not be zero if there is a useful range
                    assert self.address_offset_inc != 0, "%s 0x%x" % (self.name, self.address_offset_inc)
            # Unused block increment must be bad
            assert self.address_block_inc == 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_block_inc)
        elif len(self.range) == 2:
            # Increment must not be bad
            assert self.address_offset_inc != 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_offset_inc)
            if self.range[1][0] == self.range[1][-1]:
                # Force increment to be zero if range only covers one value
                assert self.address_offset_inc == 0, "%s 0x%x" % (self.name, self.address_offset_inc)
            else:
                # Increment must not be zero if there is a useful range
                assert self.address_offset_inc != 0, "%s 0x%x" % (self.name, self.address_offset_inc)
            # Increment must not be bad
            assert self.address_block_inc != 0xbadbadbadbad, "%s 0x%x" % (self.name, self.address_block_inc)
            if self.range[0][0] == self.range[0][-1]:
                # Force increment to be zero if range only covers one value
                assert self.address_block_inc == 0, "%s 0x%x" % (self.name, self.address_block_inc)
            else:
                if self.type in ["SRIOMAINT"]:
                    # SRIO MAINT are special in that they have the same address on all ports
                    assert self.address_block_inc == 0, "%s 0x%x" % (self.name, self.address_block_inc)
                else:
                    # Increment must not be zero if there is a useful range
                    assert self.address_block_inc != 0, "%s 0x%x" % (self.name, self.address_block_inc)
        else:
            raise Exception("CSR %s, Illegal range length" % (self.name))

    def validate(self):
        fixCsr(self) # Do the ugly custom fix stuff
        if not re.match("^[a-z][a-z0-9_#]*$", self.name):
            raise Exception("Invalid CSR name: " + self.name)
        self.validateRange()
        if not self.type in VALID_CSR_TYPES:
            raise Exception("Incorrect CSR type: " + self.type)
        self.validateBits()
        # FIXME: Address stuff not loaded yet. Done in csr-tool.py
        #self.validateAddresses()

    def display(self, show_comments):
        print self.name, self.range, "Type =", self.type
        if show_comments:
            for l in self.description:
                print "    " + l
        for bit in self.fields:
            f = self.fields[bit]
            print "<" + str(f.start_bit) + ":" + str(f.stop_bit) + ">\t" + f.c_type + "\t" + f.name + "\t" + f.type + "\t" + str(f.reset_value) + "\t" + str(f.typical_value)
            if show_comments:
                for l in f.description:
                    print "    " + l
        if show_comments and self.notes:
            print "  Notes:"
            for l in self.notes:
                print "    " + l

    #
    # Return an iterator that loops over every address for this CSR. Each
    # loop will receive a tuple (name, address, arg1, arg2). The name is
    # the CSR name mangled with indexes and in upper case. The address is the
    # CSR location as a long. arg1 and arg2 are optional and specifiy the
    # range arguments.
    #
    def iterateAddresses(self):
        name = self.name.upper()
        if len(self.range) == 0:
            assert "#" not in name
            yield (name, self.address_base, -1, -1)
        elif len(self.range) == 1:
            name_parts = name.split("#")
            assert len(name_parts) == 2
            range_num = 0
            while range_num < len(self.range[0]):
                index_low = self.range[0][range_num]
                index_high = self.range[0][range_num+1]
                range_num += 2
                for i in range(index_low, index_high+1):
                    n = "%s%d%s" % (name_parts[0], i, name_parts[1])
                    address = self.address_base + self.address_offset_inc*i
                    yield (n, address, i, -1)
        elif len(self.range) == 2:
            name_parts = name.split("#")
            assert len(name_parts) == 3
            block_range_num = 0
            while block_range_num < len(self.range[0]):
                block_index_low = self.range[0][block_range_num]
                block_index_high = self.range[0][block_range_num+1]
                block_range_num += 2
                for block in range(block_index_low, block_index_high+1):
                    offset_range_num = 0
                    while offset_range_num < len(self.range[1]):
                        offset_index_low = self.range[1][offset_range_num]
                        offset_index_high = self.range[1][offset_range_num+1]
                        offset_range_num += 2
                        for i in range(offset_index_low, offset_index_high+1):
                            n = "%s%d%s%03d%s" % (name_parts[0], block, name_parts[1],  i, name_parts[2])
                            address = self.address_base + self.address_block_inc*block + self.address_offset_inc*i
                            yield (n, address, i,  block)
        else:
            raise Exception("Illegal range on csr " + self.name)
        return

    #
    # Return a string containing a C style equation for calculating the address
    # given the required block/index arguments.
    #
    def getAddressEquation(self, pci_alias=0, no_ull=0):
        if pci_alias:
            base_address = self.pci_alias
        else:
            base_address = self.address_base
        if self.range:
            first_offset = self.range[0][0]
            offset_max = max(self.range[0])
            if len(self.range) > 1:
                offset_max = max(self.range[1])
                block_max = max(self.range[0])
            else:
                block_max = 0
        else:
            first_offset = 0
            offset_max = 0
            block_max = 0

        if len(self.range) == 0:
            address_part = toHex(base_address, 16) + "ull"
        elif len(self.range) == 1:
            address_part = "%sull" % toHex(base_address + self.address_offset_inc * first_offset, 16)
            bit_mask = getBitMask(offset_max)
            if bit_mask and self.address_offset_inc:
                if self.address_offset_inc >= 65536:
                    address_part += " + (block_id & %d) * %sull" % (bit_mask, toHex(self.address_offset_inc))
                elif self.address_offset_inc:
                    address_part += " + (offset & %d) * %d" % (bit_mask, self.address_offset_inc)
            if first_offset and self.address_offset_inc:
                address_part += " - %d*%d" % (self.address_offset_inc, first_offset)
        elif len(self.range) == 2:
            # The following is a workaround for a bug in the gcc expression
            # optimizer. If you have an expression x*A+y*B, gcc will attempt
            # to change it into (x+y*B/A)*A. The problem is that it truncates
            # B/A into 32bits. Here we do the transform ourselves to avoid this
            # behavior.
            if self.address_offset_inc and (self.address_block_inc % self.address_offset_inc == 0):
                offset_bit_mask = getBitMask(offset_max)
                block_bit_mask = getBitMask(block_max)
                if offset_bit_mask:
                    if block_bit_mask and self.address_block_inc:
                        address_part = "%sull + ((offset & %d) + (block_id & %d) * %sull) * %d" % (toHex(base_address, 16), offset_bit_mask, block_bit_mask, toHex(self.address_block_inc/self.address_offset_inc), self.address_offset_inc)
                    else:
                        address_part = "%sull + (offset & %d) * %d" % (toHex(base_address, 16), offset_bit_mask, self.address_offset_inc)
                else:
                    address_part = "%sull" % toHex(base_address, 16)
                    if block_bit_mask and self.address_block_inc:
                        address_part += " + (block_id & %d) * %sull" % (block_bit_mask, toHex(self.address_block_inc))
            else:
                address_part = "%sull" % toHex(base_address, 16)
                bit_mask = getBitMask(offset_max)
                if bit_mask and self.address_offset_inc:
                    address_part += " + (offset & %d) * %d" % (bit_mask, self.address_offset_inc)
                bit_mask = getBitMask(block_max)
                if bit_mask and self.address_block_inc:
                    address_part += " + (block_id & %d) * %sull" % (bit_mask, toHex(self.address_block_inc))
        else:
            raise Exception("Unexpected number of parameters")
        if no_ull:
            address_part = address_part.replace("ull", "")
        return address_part

class CsrField:
    # These are the characters allowed in field names
    RE_AZ09 = re.compile("^[a-z][a-z0-9_]*$")
    # Fields starting with these names followed by optional numbers will be
    # silently renamed to reserved.
    begins = ["reserved", "reserved_", "rsvrd", "rsvd", "spare", "spares", "spr", "unused"]
    RE_RESERVED_NAMES = re.compile("^((%s))[0-9]*$" % ")|(".join(begins))

    def __init__(self, start_bit, stop_bit, name, field_type, reset_value, typical_value, description, c_type=None):
        assert isinstance(start_bit, LongType), type(start_bit)
        assert isinstance(stop_bit, LongType), type(stop_bit)
        assert isinstance(name, StringType), type(name)
        assert isinstance(field_type, StringType), type(field_type)
        assert isinstance(reset_value, (LongType, StringType)), type(reset_value)
        assert isinstance(typical_value, (LongType, StringType)), type(typical_value)
        assert isinstance(description, ListType), type(description)
        assert (c_type == None) or isinstance(c_type, StringType), type(c_type)
        self.start_bit = start_bit
        self.stop_bit = stop_bit
        name = name.lower()
        if CsrField.RE_RESERVED_NAMES.match(name):
            if field_type != "RAZ":
                #print "    Warning: Reserved field %s wasn't RAZ" % name
                field_type = "RAZ"
            name = "reserved_" + str(start_bit) + "_" + str(stop_bit)
        self.name = name
        self.description = description
        self.type = field_type
        self.reset_value = reset_value
        self.typical_value = typical_value
        self.c_type = c_type
        self.validate()

    def validate(self):
        if (self.start_bit < 0) or (self.start_bit > 63):
            raise Exception("Incorrect CSR field start bit")
        if (self.stop_bit < self.start_bit) or (self.stop_bit > 63):
            raise Exception("Incorrect CSR field stop bit")
        if not CsrField.RE_AZ09.match(self.name):
            raise Exception("Invalid field name: " + self.name)
        if not self.type in VALID_FIELD_TYPES:
            raise Exception("Incorrect CSR field type: " + self.type)
        # Anything for reset_value
        # Anything for typical_value


import re
from csr_fixes import fixCsrName
from csr_fixes import fixCsr
from types import *
from csr_output_addresses import getBitMask

VALID_FIELD_TYPES = ["RAZ",     # Read as zero
                     "R/W",     # Read / Write
                     "R/W1C",   # Read, write ones to clear
                     "R/W1S",   # Read, write ones to set
                     "R/W0C",   # Read, write zeros to clear
                     "RO",      # Read only
                     "RC/W",    # Read to clear, write
                     "RC",      # Read clear
                     "WO",      # Write only
                     "R/W1",    # Read, write one
                     "WR0",
                     "RO/WRSL", # Read only, cna be written through RSL
                     "WORSL"]
VALID_CSR_TYPES = ["RSL", "NCB",
                   "PEXP",          # PCIe BAR 0 address only
                   "PEXP_NCB",      # NCB-direct and PCIe BAR0 address
                   "PEXPV_NCB",     # Virtual NCB-direct and PCIe BAR0 address
                   "PCICONFIGEP", "PCICONFIGEP0", "PCICONFIGEP1",   # PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR
                   "PCICONFIGRC", "PCICONFIGRC0", "PCICONFIGRC1",   # PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR
                   ]

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
        if len(self.range) > 4:
            raise Exception("Having a CSR with more than four indexes isn't allowed: " + str(self.range))
        self.type = csr_type
        self.description = description
        self.fields = {}
        self.cisco_only = 0
        self.setNotes(notes)
        self.address_info = None
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
        # Allow a max of 4 arguments
        assert len(self.range) < 5
        for range_list in self.range:
            last = 0
            for i in range_list:
                assert i >= 0
                assert i < (1<<20)
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
                raise Exception("Unused Bit in CSR %s: %s" % (self.name, str(bitmask)))

        # Set the c_type if it isn't set already
        for f in self.fields:
            field = self.fields[f]
            if not field.c_type:
                field.c_type = default_c_type

    def validateAddresses(self):
        assert len(self.range) + 1 == len(self.address_info), "%s: Range length %d doesn't match address_info_length %d" % (self.name, len(self.range) + 1, len(self.address_info))
        for a in self.address_info:
            assert a >= 0, "%s address is negative" % self.name

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
    def iterateAddresses(self, recurse_args = None):
        num_args = len(self.range)
        if num_args == 0:
            yield (self.name.upper(), self.address_info[0])
        else:
            name_parts = self.name.upper().split("#")
            address = self.address_info[0]
            if recurse_args:
                arg_index = len(recurse_args) + 1
                for i,v in enumerate(recurse_args):
                    address = address + self.address_info[i+1] * v
            else:
                arg_index = 1
            mult = self.address_info[arg_index]
            work_range = self.range[arg_index-1]
            range_num = 0
            while range_num < len(work_range):
                index_low = work_range[range_num]
                index_high = work_range[range_num+1]
                range_num += 2
                if arg_index != num_args:
                    if recurse_args:
                        recurse_args.append(0)
                    else:
                        recurse_args = [0]
                    for i in range(index_low, index_high+1):
                        recurse_args[-1] = i
                        for o in self.iterateAddresses(recurse_args):
                            yield o
                    del recurse_args[-1]
                else:
                    base_name = [name_parts[0]]
                    if recurse_args:
                        for i,v in enumerate(recurse_args):
                            base_name.append(str(v))
                            base_name.append(name_parts[i+1])
                    base_name = "".join(base_name)
                    for i in range(index_low, index_high+1):
                        if arg_index > 1:
                            n = "%s%03d%s" % (base_name, i, name_parts[arg_index])
                        else:
                            n = "%s%d%s" % (base_name, i, name_parts[arg_index])
                        output = [n, address + mult*i]
                        if recurse_args:
                            for v in recurse_args:
                                output.append(v)
                        output.append(i)
                        yield output
        return

    #
    # Return a string containing a C style equation for calculating the address
    # given the required block/index arguments.
    #
    def getAddressEquation(self, no_ull=0):
        address_part = "0x%016Xull" % self.address_info[0]
        PARAMS = ["none", "param1", "param2", "param3", "param4"]
        for i in xrange(1, len(self.address_info)):
            if self.address_info[i] == 0:
                continue
            offset_max = max(self.range[i-1])
            if offset_max == 0:
                continue
            bit_mask = getBitMask(offset_max)
            param = PARAMS[i]
            address_part += " + (%s & %d) * 0x%Xull" % (param, bit_mask, self.address_info[i])
        if no_ull:
            address_part = address_part.replace("ull", "")
        return address_part

class CsrField:
    # These are the characters allowed in field names
    RE_AZ09 = re.compile("^[a-z][a-z0-9_]*$")
    # Fields starting with these names followed by optional numbers will be
    # silently renamed to reserved.
    begins = ["reserved", "reserved_", "rsvrd", "rsvd", "spare", "spares", "spr", "unused", "res_"]
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


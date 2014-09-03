import re
from csr_fixes import fixCsr
from types import *

VALID_CSR_TYPES = ["RSL",           # Slow CSR
                   "RSL32b",        # Slow CSR, 32bit
                   "NCB",           # Non coherent bus - Fast CSR
                   "NCB32b",        # Non coherent bus 32bit - Fast CSR
                   "PEXP",          # PCIe BAR 0 address only
                   "PEXP_NCB",      # NCB-direct and PCIe BAR0 address
                   "PEXPV_NCB",     # Virtual NCB-direct and PCIe BAR0 address
                   "PCICONFIGEP",   # PCIe config space in EP mode
                   "PCICONFIGRC",   # PCIe config space in RC mode
                   "PCCBR",
                   "PCCPF",
                   "PCCVF",
                   "DAB32b",
                   "DAB"]

def getBitMask(max_number):
    mask = 0;
    while max_number:
        mask = (mask<<1) | 1
        max_number = max_number>>1
    return mask

#
# The basic definition of a CSR. Each one only supports a single chip's version
#
class Csr:
    def __init__(self, group, name, csr_type, description, notes, is_banked, inherits_algorithm):
        assert isinstance(group, StringType), type(group)
        assert isinstance(name, ListType), type(name)
        assert isinstance(csr_type, StringType), type(csr_type)
        assert isinstance(description, ListType), type(description)
        assert isinstance(notes, ListType), type(notes)
        assert isinstance(is_banked, BooleanType), type(is_banked)
        self.group = group;
        self.name = ""
        self.is_banked = is_banked
	self.inherits_algorithm = inherits_algorithm
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
        self.setNotes(notes)
        self.address_info = None

    def getCname(self):
        # Return the C version of the CSR's name
        return self.name.replace("#","x").upper()

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
                raise Exception("Unused Bit in CSR: " + str(bitmask))

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
        self.generate_masks()
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

    #
    # Each CSR has a series of bit mask that represent aspects of its
    # individual bits:
    # AND mask: Bits not set in this mask are read only, possibly always zero
    # OR mask: Bits set in this mask are always set
    # COPY mask: These bits are read only, copy old value
    # Secure copy mask: These bits are read only in secure mode, copy old value
    # Reset value: The initial value of the CSR
    #
    def generate_masks(self):
        bits = self.getNumBits()
        self.and_mask = (1L << bits) - 1 # Bits not set here are always zero
        self.or_mask = 0        # Bits in this mask are always one
        self.copy_mask = 0      # Bits in this mask are RO in non-secure mode
        self.scopy_mask = 0     # Bits in this mask are RO in secure mode
        self.secure_mask = 0    # Bits in this mask are secure and forced to zero for non-secure reads
        self.w1s_mask = 0       # Bits in this mask are set on a write of 1
        self.w1c_mask = 0       # Bits in this mask are clear on a write of 1
        self.wclear_mask = 0    # Bits in this mask are cleared on any write
        self.reset_value = 0    # Hardware reset value
        for f in self.fields:
            field = self.fields[f]
            bits = (1L<<(field.stop_bit - field.start_bit + 1)) - 1
            bits = bits << field.start_bit
            self.reset_value |= field.reset_value << field.start_bit
            if field.type == "RAZ":         # Read as zero, write ignore
                self.and_mask = self.and_mask & ~bits
            elif field.type == "R/W":       # Read, write
                pass
            elif field.type == "R/W/H":     # Read, write, changed by hardware
                pass
            elif field.type == "R/W1C":     # Read, write 1 clear
                self.w1c_mask = self.w1c_mask | bits
            elif field.type == "R/W1C/H":   # Read, write 1 clear, changed by hardware
                self.w1c_mask = self.w1c_mask | bits
            elif field.type == "R/W1S":     # Read, write 1 set
                self.w1s_mask = self.w1s_mask | bits
            elif field.type == "R/W1S/H":   # Read, write 1 set, changed by hardware
                self.w1s_mask = self.w1s_mask | bits
            elif field.type == "RO":        # Read, write ignore
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
            elif field.type == "RO/H":      # Read, write ignore, changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
            elif field.type == "RC/W/H":    # Special hardware knowledge needed
                pass
            elif field.type == "RC/H":      # Special hardware knowledge needed
                pass
            elif field.type == "RO/WRSL":   # Read only, writable through RSL (PCIe regs)
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
            elif field.type == "RO/WRSL/H": # Read only, writable through RSL (PCIe regs), changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
            elif field.type == "R/W1":      # Read, write any value clears
                self.wclear_mask = self.wclear_mask | bits
            elif field.type == "R/W1/H":    # Read, write any value clears, changed by hardware
                self.wclear_mask = self.wclear_mask | bits
            elif field.type == "SR/W":      # Secure read, write
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
            elif field.type == "SR/W/H":    # Secure read, write, changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
            elif field.type == "SR/W1C":    # Secure read, write one clear
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
                self.w1c_mask = self.w1c_mask | bits
            elif field.type == "SR/W1C/H":    # Secure read, write one clear, changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
                self.w1c_mask = self.w1c_mask | bits
            elif field.type == "SR/W1S":    # Secure read, write one set
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
                self.w1s_mask = self.w1s_mask | bits
            elif field.type == "SR/W1S/H":    # Secure read, write one set, changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.secure_mask = self.secure_mask | bits
                self.w1s_mask = self.w1s_mask | bits
            elif field.type == "SRO":       # Secure read, write ignore
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
                self.secure_mask = self.secure_mask | bits
            elif field.type == "SRO/H":     # Secure read, write ignore, changed by hardware
                self.copy_mask = self.copy_mask | bits
                self.scopy_mask = self.scopy_mask | bits
                self.secure_mask = self.secure_mask | bits
            elif field.type == "SWO":       # Secure write only, FIXME: read?
                self.secure_mask = self.secure_mask | bits
            elif field.type == "WO":        # Write only?
                pass
            elif field.type == "WO/H":      # Write only?, changed by hardware
                pass
            elif field.type == "WORSL/H":   # Only writable through RSL (PCIe regs), FIXME: Read?
                pass
            else:
                assert False, "Add support for field type %s to mask generation" % field.type
	if self.inherits_algorithm == "int_w1s" or self.inherits_algorithm == "int_ena_w1s":
	    temp = self.w1s_mask
	    self.w1s_mask = self.w1c_mask
            self.w1c_mask = temp
	elif self.inherits_algorithm == "int_ena_w1c":
	    pass   # Not sure what else this algorithm requires, masks don't change

class CsrField:
    # These are the characters allowed in field names
    RE_AZ09 = re.compile("^[a-z][a-z0-9_]*$")
    # Fields starting with these names followed by optional numbers will be
    # silently renamed to reserved.
    begins = ["reserved", "reserved_", "rsvrd", "rsvd", "spare", "spares", "spr", "unused", "res_"]
    RE_RESERVED_NAMES = re.compile("^((%s))[0-9]*$" % ")|(".join(begins))

    def __init__(self, start_bit, stop_bit, name, field_type, reset_value, typical_value, description, c_type=None):
        # The craptastic YAML parser is turning ON/OFF into true/false. Idiots.
        if isinstance(name, BooleanType):
            if name:
                name = "on"
            else:
                name = "off"
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
        if reset_value in ["NS", "X"]:
            self.reset_value = 0L
        elif reset_value in ["all-ones", "All-ones"]:
            self.reset_value = (1L<<(stop_bit - start_bit + 1)) - 1
        elif isinstance(reset_value, LongType):
            self.reset_value = reset_value
        else:
            assert reset_value.startswith("0x"), reset_value
            assert reset_value.endswith("L"), reset_value
            self.reset_value = long(reset_value, 0)
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
        # Anything for reset_value
        # Anything for typical_value


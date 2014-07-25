from types import *
from chip_enum import ChipEnum
from csr_fixes import fixDescription

#
# The basic definition of a enumeration
#
class ChipStruct:
    def __init__(self, group, name, description):
        assert isinstance(group, StringType), type(group)
        assert isinstance(name, StringType), type(name)
        assert isinstance(description, StringType), type(description)
        self.group = group;
        self.name = name
        self.description = fixDescription(description.split("\n"))
        self.fields = {}

    def addField(self, field):
        assert isinstance(field, ChipStructField), type(field)
        assert not field.name in self.fields
        self.fields[field.name] = field

    def validate(self):
        assert isinstance(self.group, StringType), type(self.group)
        assert isinstance(self.name, StringType), type(self.name)
        assert isinstance(self.description, ListType), type(self.description)
        assert isinstance(self.fields, DictType), type(self.fields)
        # Fill in holes where reserved bits weren't specified
        start_bits = self.getStartBitList()
        used_bits = 0
        for bit in start_bits:
            field = self.getField(bit)
            assert bit >= used_bits, bit
            if used_bits < bit:
                self.addField(ChipStructField("--", None, used_bits, bit-1, "Reserved"))
            used_bits = field.stop_bit + 1
        # Make sure upper bits are reserved as needed
        if used_bits&63 != 0:
            width = 64 - (used_bits&63)
            self.addField(ChipStructField("--", None, used_bits, used_bits+width-1, "Reserved"))

    def getStartBitList(self):
        start_bits = []
        for f in self.fields:
            start_bits.append(self.fields[f].start_bit)
        start_bits.sort()
        return start_bits

    def getWidthBits(self):
        width = 0
        for f in self.fields:
            if self.fields[f].stop_bit >= width:
                width = self.fields[f].stop_bit+1
        return width

    def getField(self, start_bit):
        for f in self.fields:
            if start_bit == self.fields[f].start_bit:
                return self.fields[f]
        assert False, "Field not found with start_bit %d" % start_bit

class ChipStructField:
    def __init__(self, name, enum_type, start_bit, stop_bit, description):
        assert isinstance(name, StringType), type(name)
        assert (enum_type == None) or isinstance(enum_type, ChipEnum), type(enum_type)
        assert isinstance(start_bit, LongType), type(start_bit)
        assert isinstance(stop_bit, LongType), type(stop_bit)
        assert isinstance(description, StringType), type(description)
        assert start_bit >= 0, start_bit
        assert stop_bit >= start_bit, stop_bit
        assert start_bit/64 == stop_bit/64
        # FIXME: Handle bits in next word
        if name == "--":
            name = "reserved_%d_%d" % (start_bit, stop_bit)
        assert not "-" in name
        self.name = name.lower()
        if enum_type:
            self.enum_type = "%s::enum_t" % enum_type
        else:
            self.enum_type = "uint64_t"
        self.start_bit = start_bit
        self.stop_bit = stop_bit
        self.description = fixDescription(description.split("\n"))


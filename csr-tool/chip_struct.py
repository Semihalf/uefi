from types import *
from chip_enum import ChipEnum
from csr_fixes import fixDescription

#
# The basic definition of a enumeration
#
class ChipStruct:
    def __init__(self, name, description):
        assert isinstance(name, StringType), type(name)
        assert isinstance(description, StringType), type(description)
        self.name = name
        self.description = fixDescription(description)
        self.fields = {}

    def addField(self, field):
        assert isinstance(field, ChipStructField), type(field)
        assert not field.name in self.fields
        self.fields[field.name] = field

    def validate(self):
        assert isinstance(self.name, StringType), type(self.name)
        assert isinstance(self.description, ListType), type(self.description)
        assert isinstance(self.fields, DictType), type(self.fields)

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
        self.name = name
        self.enum_type = enum_type
        self.start_bit = start_bit
        self.stop_bit = stop_bit
        self.description = fixDescription(description)


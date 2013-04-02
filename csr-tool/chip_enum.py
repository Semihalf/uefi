from types import *
from csr_fixes import fixDescription

#
# The basic definition of a enumeration
#
class ChipEnum:
    def __init__(self, name, description, width=0):
        assert isinstance(name, StringType), type(name)
        assert isinstance(description, StringType), type(description)
        assert isinstance(width, IntType), type(width)
        self.name = name
        self.description = fixDescription(description)
        self.width = width
        self.values = {}

    def addValue(self, enum_value):
        assert isinstance(enum_value, ChipEnumValue), type(enum_value)
        assert not enum_value.name in self.values
        self.values[enum_value.name] = enum_value

    def validate(self):
        assert isinstance(self.name, StringType), type(self.name)
        assert isinstance(self.description, ListType), type(self.description)

class ChipEnumValue:
    def __init__(self, name, value, description):
        assert isinstance(name, StringType), type(name)
        assert isinstance(value, IntType), type(value)
        assert isinstance(description, StringType), type(description)
        self.name = name
        self.value = value
        self.description = fixDescription(description)


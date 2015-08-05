from types import *
from csr_fixes import fixDescription

#
# The basic definition of a BAR range, used for describing devices
#
class ChipBar:
    def __init__(self, group, name, description, start, size, enum_name):
        assert isinstance(group, StringType), type(group)
        assert isinstance(name, StringType), type(name)
        assert isinstance(description, StringType), type(description)
        assert isinstance(start, IntType), type(start)
        assert isinstance(size, IntType), type(size)
        assert isinstance(enum_name, StringType), type(enum_name)
        assert (size > 0) and (size <= 36), size # Arbitrary limit bars to 64GB
        self.group = group
        self.name = name
        self.description = fixDescription(description.split("\n"))
        self.start = start
        self.size = size
	self.enum_name = enum_name
        #print "BAR %s 0x%x %d bits" % (self.name, self.start, self.size)

    def validate(self):
        assert isinstance(self.name, StringType), type(self.name)
        assert isinstance(self.description, ListType), type(self.description)


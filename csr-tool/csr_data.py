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
import types
import chip_list
from yaml_utils import getChild
from yaml_utils import raiseException

#
# Various data items below contain dictionaries that are index per chip. This
# class overrides the default dictionary so we can do better checking and find
# script bugs. It is a dictionary that requires all values to be type checked
# and all keys must be a valid chip, or "s".
#
class PerChip(types.DictType):
    def __init__(self, allowedType, allowedType2=None):
        self.allowedType = allowedType
        self.allowedType2 = allowedType2
    def __setitem__(self, name, value):
        if name != "s":
            assert name in chip_list.getChips()
        if not isinstance(value, self.allowedType):
            if not self.allowedType2 or not isinstance(value, self.allowedType2):
                assert False, "%s: %s not %s or %s" % (name, value, self.allowedType, self.allowedType2)
        types.DictType.__setitem__(self, name, value)

#
# All data extracted from YAML derives from this class. For any YAML
# node it is connected to, this class extracts the title, description,
# notes, and attributes. Each DataItem may apply to multiple chips, so
# every field is dictionary index by the chip name.
#
class DataItem(types.DictType):
    def __init__(self, name):
        assert isinstance(name, types.StringType), name
        self["name"] = name # String with # where params were
        self["attributes"] = PerChip(types.DictType)    # Index by chip, raw yaml
        self["description"] = PerChip(types.StringType) # Index by chip, string with newlines in it
        # The location in YAML will be filled per chip
        self["__FILE__"] = PerChip(types.StringType)    # Index by chip
        self["__LINE__"] = PerChip(types.IntType)       # Index by chip
        self["__COLUMN__"] = PerChip(types.IntType)     # Index by chip

    def addChip(self, chip, yaml):
        # Record where we found this element for debug
        for tag in ["__FILE__", "__LINE__", "__COLUMN__"]:
            self[tag][chip] = getChild(yaml, tag)
        # Check if we have any attributes
        attributes = getChild(yaml, "attributes", True)
        if attributes:
            # Chip pass should not exist
            chip_pass = getChild(attributes, "chip_pass", True)
            assert chip_pass == None, "Unexpected chip_pass attribute. These are suppose to be filtered by csr3"
        # Add the new chip
        if chip in self["attributes"]:
            raiseException(yaml, "Chip %s already in attributes" % chip)
        # Get the description from the title and description in the YAML
        description = []
        title = getChild(yaml, "title", True)
        if title:
            description.append(title)
        d = getChild(yaml, "description", True)
        if d:
            description.append(d)
        d = getChild(yaml, "notes", True)
        if d:
            description.append("Notes:")
            description.append(d)
        d = getChild(yaml, "internal", True)
        if d:
            description.append("Internal:")
            description.append(d)
        description = "\n".join(description)
        self["description"][chip] = description.rstrip()
        # Copy the YAML attributes
        self["attributes"][chip] = {}
        if attributes:
            for a in attributes:
                self["attributes"][chip][a] = attributes[a]

#
# Enumeration data types
#

class Enum(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["block"] = None    # Single string
        self["width"] = PerChip(types.IntType) # Width in bits(int), per chip
        self["values"] = {}     # Instances of EnumValue, indexed by name
class EnumValue(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["value"] = PerChip(types.ListType)     # List created by parseAddress(), per chip
        self["ranges"] = PerChip(types.ListType)    # List created by parseNameForRanges(), per chip
        self["bar_size"] = PerChip(types.IntType)   # Used for size of bars(int), per chip

#
# Structure data types
#

class Struct(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["block"] = None    # Single string
        self["fields"] = {}     # Instances of StructField, indexed by name
class StructField(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["bits"] = PerChip(types.TupleType) # List [start,stop] created by _parseBits(), per chip

#
# Register data types
#

class Register(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["block"] = None    # Single string
        self["fields"] = {}     # Instances of RegisterField, indexed by name
        self["address"] = PerChip(types.ListType) # List created by parseAddress(), per chip
        self["ranges"] = PerChip(types.ListType)  # List created by parseNameForRanges(), per chip
        self["bus"] = PerChip(types.StringType)   # String for bus type, per chip (see VALID_BUSSES)
        self["bar"] = PerChip(types.StringType, types.NoneType) # String for bar name, per chip
class RegisterField(DataItem):
    def __init__(self, name):
        DataItem.__init__(self, name)
        self["bits"] = PerChip(types.TupleType)   # List [start,stop] created by _parseBits(), per chip
        self["access"] = PerChip(types.StringType)# String for access type, per chip (VALID_ACCESS with possible "/H")
        self["reset"] = PerChip(types.StringType, types.LongType) # Number(int) or the string "--", per chip (see _parseFieldValue)
        self["typical"] = PerChip(types.StringType, types.LongType) # Number(int) or the string "--", per chip (see _parseFieldValue)


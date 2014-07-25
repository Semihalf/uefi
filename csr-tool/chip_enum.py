from types import *
from csr_fixes import fixDescription

#
# The basic definition of a enumeration
#
class ChipEnum:
    def __init__(self, group, name, description, width):
        assert isinstance(group, StringType), type(group)
        assert isinstance(name, StringType), type(name)
        assert isinstance(description, StringType), type(description)
        assert isinstance(width, IntType), type(width)
        assert (width > 0) and (width <= 64)
        self.group = group
        self.name = name
        self.description = fixDescription(description.split("\n"))
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
        self.description = description

def iterateEnumValues(name_list, range, value_info, recurse_args = None):
    assert isinstance(name_list, ListType), type(name_list)
    assert isinstance(range, ListType), type(range)
    assert isinstance(value_info, ListType), type(value_info)
    for i in xrange(len(name_list)-1, 0, -1):
        if isinstance(name_list[i], ListType):
            del name_list[i]
    num_args = len(range)
    if num_args == 0:
        yield (name_list[0], value_info[0])
    else:
        value = value_info[0]
        if recurse_args:
            arg_index = len(recurse_args) + 1
            for i,v in enumerate(recurse_args):
                value = value + value_info[i+1] * v
        else:
            arg_index = 1
        mult = value_info[arg_index]
        work_range = range[arg_index-1]
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
                for i in xrange(index_low, index_high+1):
                    recurse_args[-1] = i
                    for o in iterateEnumValues(name_list, range, value_info, recurse_args):
                        yield o
                del recurse_args[-1]
            else:
                base_name = [name_list[0]]
                if recurse_args:
                    for i,v in enumerate(recurse_args):
                        base_name.append(str(v))
                        base_name.append(name_list[i+1])
                base_name = "".join(base_name)
                for i in xrange(index_low, index_high+1):
                    if arg_index == len(name_list):
                        n = "%s%d" % (base_name, i)
                    else:
                        n = "%s%d%s" % (base_name, i, name_list[arg_index])
                    output = [n, value + mult*i]
                    if recurse_args:
                        for v in recurse_args:
                            output.append(v)
                    output.append(i)
                    yield output
    return


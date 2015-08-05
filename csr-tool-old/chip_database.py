import sys
import pprint
from types import *
from csr_fixes import fixDescription

#
# We build a database about all CSRs, structures, enumerations, etc
# about a chip so the utility TBD can provide information and decodes
# for easy debug.
#
class ChipDatabase:
    def __init__(self):
        self.objects = {}

    def add(self, name, type, width, address, description):
        assert not name in self.objects, name
        name = name.upper()
        if isinstance(description, ListType):
            description = "\n".join(description)
        obj = {}
        obj["type"] = type
        obj["width"] = width
        obj["address"] = address
        obj["description"] = description
        self.objects[name] = obj

    def addField(self, parent_name, name, type, start_bit, stop_bit, description):
        parent_name = parent_name.upper()
        if isinstance(description, ListType):
            description = "\n".join(description)
        field = {}
        field["name"] = name
        field["type"] = type
        field["start_bit"] = start_bit
        field["stop_bit"] = stop_bit
        field["description"] = description
        if not "fields" in self.objects[parent_name]:
            self.objects[parent_name]["fields"] = []
        self.objects[parent_name]["fields"].append(field)

    def addValue(self, parent_name, name, value, description):
        parent_name = parent_name.upper()
        if isinstance(description, ListType):
            description = "\n".join(description)
        v = {}
        v["name"] = name
        v["value"] = value
        v["description"] = description
        if not "values" in self.objects[parent_name]:
            self.objects[parent_name]["values"] = []
        self.objects[parent_name]["values"].append(v)

    def write(self, out=sys.stdout):
        pp = pprint.PrettyPrinter(indent=2, width=132, stream=out)
        pp.pprint(self.objects)

    def read(self, filename):
        inf = open(filename).read()
        objs = eval(inf)
        for n in objs:
            assert not n in self.objects, n
            self.objects[n] = objs[n]

    def build(self, chip_info):
        for o in chip_info.iterEnum():
            self.add(o.name, "enum", o.width, None, o.description)
            for v in o.values:
                self.addValue(o.name, v, o.values[v].value, o.values[v].description)
        for o in chip_info.iterStruct():
            self.add(o.name, "struct", None, None, o.description)
            bits = o.getStartBitList()
            bits.reverse()
            for b in bits:
                f = o.getField(b)
                self.addField(o.name, f.name, f.enum_type, f.start_bit, f.stop_bit, f.description)
        for o in chip_info.iterCsr():
            self.add(o.name, "csr", o.getNumBits(), o.address_info[0], o.description)
            bits = o.fields.keys()
            bits.sort()
            bits.reverse()
            for b in bits:
                f = o.fields[b]
                self.addField(o.name, f.name, f.type, f.start_bit, f.stop_bit, f.description)


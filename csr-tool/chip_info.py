from csr import Csr
from chip_enum import ChipEnum
from chip_struct import ChipStruct
from chip_bar import ChipBar

#
# ChipInfo represents all information about a specific chip. This includes:
# - Chip name
# - Enumerations
# - Structures
# - CSRs
#
class ChipInfo:
    def __init__(self, name, pass_dict):
        self.name = name
        self.pass_dict = pass_dict # Stores the name=number pass info for this chip
        self._csrs = {}
        self._enums = {}
        self._structs = {}
        self._bars = {}

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
        else:
            self._csrs[csr.name] = csr

    def addEnum(self, enum):
        assert isinstance(enum, ChipEnum)
        assert not enum.name in self._enums
        self._enums[enum.name] = enum

    def addStruct(self, struct):
        assert isinstance(struct, ChipStruct)
        assert not struct.name in self._structs
        self._structs[struct.name] = struct

    def addBar(self, bar):
        assert isinstance(bar, ChipBar)
        assert not bar.name in self._bars
        for n in self._bars:
            b = self._bars[n]
            assert (bar.start >= b.start + (1 << b.size)) or (bar.start + (1 << bar.size) <= b.start)
        self._bars[bar.name] = bar

    def iterCsr(self):
        keys = self._csrs.keys()
        keys.sort()
        sorted = []
        for k in keys:
            sorted.append(self._csrs[k])
        return sorted.__iter__()

    def iterEnum(self):
        keys = self._enums.keys()
        keys.sort()
        sorted = []
        for k in keys:
            sorted.append(self._enums[k])
        return sorted.__iter__()

    def iterStruct(self):
        keys = self._structs.keys()
        keys.sort()
        sorted = []
        for k in keys:
            sorted.append(self._structs[k])
        return sorted.__iter__()

    def iterBar(self):
        keys = self._bars.keys()
        keys.sort()
        sorted = []
        for k in keys:
            sorted.append(self._bars[k])
        return sorted.__iter__()


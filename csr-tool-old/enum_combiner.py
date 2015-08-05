from types import *
from chip_info import ChipInfo
from chip_enum import ChipEnum

def combine(combined, chip_infos):
    assert isinstance(combined, ChipInfo), type(combined)
    assert isinstance(chip_infos, ListType), type(chip_infos)
    combined_enums = {}
    for chip in chip_infos:
        for enum in chip.iterEnum():
            assert isinstance(enum, ChipEnum), type(enum)
            if not enum.name in combined_enums:
                combined_enums[enum.name] = ChipEnum(enum.group, enum.name, "\n".join(enum.description), enum.width)
            prev = combined_enums[enum.name]
            assert enum.group == prev.group
            #assert enum.description == prev.description
            assert enum.width == prev.width
            for n in enum.values:
                v = enum.values[n]
                if n in prev.values:
                    assert v.value == prev.values[n].value
                else:
                    prev.values[n] = v
    for n in combined_enums:
        combined.addEnum(combined_enums[n])
    return combined

from types import *
from chip_info import ChipInfo
from chip_bar import ChipBar

def combine(combined, chip_infos):
    assert isinstance(combined, ChipInfo), type(combined)
    assert isinstance(chip_infos, ListType), type(chip_infos)
    combined_bars = {}
    for chip in chip_infos:
        for bar in chip.iterBar():
            assert isinstance(bar, ChipBar), type(bar)
            if not bar.name in combined_bars:
                combined_bars[bar.name] = ChipBar(bar.group, bar.name, "\n".join(bar.description), bar.start, bar.size, bar.enum_name)
            prev = combined_bars[bar.name]
            assert bar.group == prev.group
            #assert bar.description == bar.description
            assert bar.start == prev.start
            assert bar.size == prev.size
            assert bar.start == prev.start
            assert bar.enum_name == prev.enum_name
    for n in combined_bars:
        combined.addBar(combined_bars[n])
    return combined

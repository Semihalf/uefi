from types import *
from chip_info import ChipInfo
from chip_struct import ChipStruct

#
# Given a list of ChipInfo for a bunch of chips, combine
# all the structure definitions into a common superset and
# put them in "combined", the aggregate ChipInfo.
#
def combine(combined, chip_infos):
    # If only python had static typing...
    assert isinstance(combined, ChipInfo), type(combined)
    assert isinstance(chip_infos, ListType), type(chip_infos)
    # This is a dict indexed by structure name. It will have a ChipStruct
    # for every structure definition of all chips
    combined_structs = {}
    # For every chip
    for chip in chip_infos:
        # For every struct for this chip
        for struct in chip.iterStruct():
            # Make sure we get what we expect
            assert isinstance(struct, ChipStruct), type(struct)
            # Check if we've already hit this structure
            if not struct.name in combined_structs:
                # New structure, add it
                combined_structs[struct.name] = ChipStruct(struct.group, struct.name, "\n".join(struct.description))
                is_new = True
            else:
                # Require that the structures be the same size
                assert struct.getWidthBits() == combined_structs[struct.name].getWidthBits()
                is_new = False
            # prev = structure we've already combined
            prev = combined_structs[struct.name]
            # Must be in same group
            assert struct.group == prev.group
            # Check all fields
            for n in struct.fields:
                field = struct.fields[n]
                if n in prev.fields:
                    # Fields with same name must be in same location
                    p_field = prev.fields[n]
                    assert field.start_bit == p_field.start_bit
                    assert field.stop_bit == p_field.stop_bit
                else:
                    assert is_new == True
                    prev.addField(field)
    # Return the combined list
    for n in combined_structs:
        combined.addStruct(combined_structs[n])
    return combined

from csr import *

class CombinedCsrList:
    def __init__(self):
        self._csrs = {}

    # Returns an individual CSRs with "name" for "chip".
    def get(self, name, chip):
        return self._csrs[name][chip]

    # Returns a dictionary of CSRs with "name" indexed by chip.
    def hasChip(self, name, chip):
        return (chip in self._csrs[name])

    # Return a sorted list of all CSR names
    def getNameList(self):
        keys = self._csrs.keys()
        keys.sort()
        return keys

    # Return each chip CSR dictionary, one at a time
    def __iter__(self):
        sorted = []
        for k in self.getNameList():
            sorted.append(self._csrs[k])
        return sorted.__iter__()

    # Add a CSR for a specific chip to the list
    def addCsr(self, chip, csr):
        if csr.name in self._csrs:
            self._csrs[csr.name][chip] = csr
        else:
            self._csrs[csr.name] = {chip:csr}

def combine(csr_lists):
    final_list = CombinedCsrList()
    # Create a information search order. Whenever we need to get generic info,
    # we use this to determine the order to search the supported chips
    info_search_order = []
    for list in csr_lists:
        info_search_order.append(list.name)
    info_search_order.reverse()
    # Create a dictionary index by CSR names. Each entry is another dictionary
    # index by the chip the CSR is for "combined_list[csr_name][chip] = Csr()".
    # Chips that don't support a csr are missing in the combined_list[csr_name]
    # map.
    combined_list = {}
    for csr_list in csr_lists:
        for csr in csr_list:
            chip = csr_list.name
            if not csr.name in combined_list:
                combined_list[csr.name] = {}
            combined_list[csr.name][chip] = csr
    # Create a sorted list of CSR names
    csr_names = combined_list.keys()
    csr_names.sort()
    for name in csr_names:
        csr_by_chip = combined_list[name]
        chips = csr_by_chip.keys()
        chips.sort()
        current = csr_by_chip[chips[0]]

        # Make sure all CSRs are mostly the same
        cisco_only = current.cisco_only
        for chip in chips[1:]:
            csr = csr_by_chip[chip]
            cisco_only |= csr.cisco_only
            assert csr.type == current.type, "%s %s:%s == %s:%s" % (name, chip, csr.type, chips[0], current.type)
            assert len(csr.range) == len(current.range), "%s %s:%d == %s:%d" % (name, chip, len(csr.range), chips[0], len(current.range))
            if csr.address_base != current.address_base:
                print "ERROR address_base %s %s:0x%x == %s:0x%x" % (name, chip, csr.address_base, chips[0], current.address_base)
            if csr.address_offset_inc == 0:
                csr.address_offset_inc = current.address_offset_inc
            elif current.address_offset_inc == 0:
                current.address_offset_inc = csr.address_offset_inc
            if csr.address_offset_inc != current.address_offset_inc:
                print "ERROR address_offset_inc %s %s:0x%x == %s:0x%x" % (name, chip, csr.address_offset_inc, chips[0], current.address_offset_inc)
            if csr.address_block_inc == 0:
                csr.address_block_inc = current.address_block_inc
            elif current.address_block_inc == 0:
                current.address_block_inc = csr.address_block_inc
            if csr.address_block_inc != current.address_block_inc:
                print "ERROR address_block_inc %s %s:0x%x == %s:0x%x" % (name, chip, csr.address_block_inc, chips[0], current.address_block_inc)
            if csr.pci_alias != current.pci_alias:
                print "ERROR pci_alias %s %s:0x%x == %s:0x%x" % (name, chip, csr.pci_alias, chips[0], current.pci_alias)

        # Figure out the range data for the superset
        # FIXME: Make this create a nice range
        csr_range = []
        for index in xrange(len(current.range)):
            range_set = {}
            for chip in chips:
                csr = csr_by_chip[chip]
                range_index = 0
                while range_index < len(csr.range[index]):
                    for i in xrange(csr.range[index][range_index], csr.range[index][range_index+1]+1):
                        range_set[i] = i
                    range_index += 2
            range_set = range_set.keys()
            range_set.sort()
            r = []
            for i in range_set:
                if len(r) and (r[-1] == i-1):
                    r[-1] = i
                else:
                    r.append(i)
                    r.append(i)
            csr_range.append(r)
        assert len(csr_range) == len(current.range), "%s %d == %d" % (name, len(csr_range), len(current.range))

        # Use the description and notes from the first chip that has either
        description = []
        notes = []
        for chip in info_search_order:
            if (chip in csr_by_chip) and (csr_by_chip[chip].description or csr_by_chip[chip].notes):
                description = csr_by_chip[chip].description
                notes = csr_by_chip[chip].notes
                break
        combined_csr = Csr([name], current.type, description, notes)
        combined_csr.cisco_only = cisco_only
        combined_csr.range = csr_range
        combined_csr.address_base = current.address_base
        combined_csr.address_offset_inc = current.address_offset_inc
        combined_csr.address_block_inc = current.address_block_inc
        combined_csr.pci_alias = current.pci_alias

        bits_in_csr = current.getNumBits()
        used_bits = ["reserved" for b in range(bits_in_csr)]
        field_type = ["RAZ" for b in range(bits_in_csr)]
        reset_value = ["X" for b in range(bits_in_csr)]
        typical_value = ["X" for b in range(bits_in_csr)]
        description = [[] for b in range(bits_in_csr)]
        c_type = [None for b in range(bits_in_csr)]
        for chip in chips:
            csr = csr_by_chip[chip]
            final_list.addCsr(chip, csr)
            for start_bit in csr.fields:
                field = csr.fields[start_bit]
                if field.name.startswith("reserved"):
                    continue
                conflict = 0
                # The following loop checks all chips and makes sure a field
                # of the same name doesn't exist in a different spot. If it does,
                # then we must mark this asa conflict
                for chip2 in chips:
                    for start_bit2 in csr_by_chip[chip2].fields:
                        # Conflict occurs if two chips have the same field name at
                        # differnet bit positions
                        if (csr_by_chip[chip2].fields[start_bit2].name == field.name) and (start_bit != start_bit2):
                            conflict = 1
                            # Mark all bits in this field as conflicting
                            for b in xrange(start_bit, field.stop_bit+1):
                                used_bits[b] = "conflict"
                                field_type[b] = "RAZ"
                                reset_value[b] = "X"
                                typical_value[b] = "X"
                                description[b] = []
                                c_type[b] = None
                            break
                for bit in xrange(start_bit, field.stop_bit+1):
                    if not used_bits[bit] in ["reserved", field.name]:
                        conflict = 1
                        conflict_name = used_bits[bit]
                        for b in xrange(bits_in_csr):
                            if used_bits[b] in [conflict_name, field.name]:
                                used_bits[b] = "conflict"
                                field_type[b] = "RAZ"
                                reset_value[b] = "X"
                                typical_value[b] = "X"
                                description[b] = []
                                c_type[b] = None
                if not conflict:
                    for bit in xrange(start_bit, field.stop_bit+1):
                        used_bits[bit] = field.name
                        field_type[bit] = field.type
                        reset_value[bit] = field.reset_value
                        typical_value[bit] = field.typical_value
                        description[bit] = field.description
                        c_type[bit] = field.c_type
        if "conflict" in used_bits:
            print "    Conflicting fields: " + csr.name
        bit = 0L
        while bit < bits_in_csr:
            start_bit = bit
            while (bit<bits_in_csr) and used_bits[bit] == used_bits[start_bit]:
                bit += 1
            stop_bit = bit-1
            if used_bits[start_bit] == "conflict":
                field = CsrField(start_bit, stop_bit, "reserved", "RAZ", "X", "X", [], None)
            else:
                field = CsrField(start_bit, stop_bit, used_bits[start_bit], field_type[start_bit], reset_value[start_bit], typical_value[start_bit], description[start_bit], c_type[start_bit])
            combined_csr.addField(field)
        combined_csr.validate()
        final_list.addCsr("s", combined_csr)
    return final_list

from csr import Csr
from csr import CsrField

class CombinedCsrList:
    def __init__(self):
        self._csrs = {}
        self._chips = []

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

    # Return a list of chips
    def getChipList(self):
        return self._chips

    # Return each chip CSR dictionary, one at a time
    def __iter__(self):
        sorted = []
        for k in self.getNameList():
            sorted.append(self._csrs[k])
        return sorted.__iter__()

    # Add a CSR for a specific chip to the list
    def addCsr(self, chip, csr):
        if (chip != "s") and (not chip in self._chips):
            self._chips.append(chip)
        if csr.name in self._csrs:
            self._csrs[csr.name][chip] = csr
        else:
            self._csrs[csr.name] = {chip:csr}

def combine(chip_infos):
    final_list = CombinedCsrList()
    # Create a information search order. Whenever we need to get generic info,
    # we use this to determine the order to search the supported chips
    info_search_order = []
    for info in chip_infos:
        info_search_order.append(info.name)
    info_search_order.reverse()
    # Create a dictionary index by CSR names. Each entry is another dictionary
    # index by the chip the CSR is for "combined_list[csr_name][chip] = Csr()".
    # Chips that don't support a csr are missing in the combined_list[csr_name]
    # map.
    combined_list = {}
    for chip_info in chip_infos:
        for csr in chip_info.iterCsr():
            chip = chip_info.name
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
            # Silently convert mismatches between NCB and RSL CSRs into NCB.
            # They are both access in the same way, so nobody should care
            if (csr.type == "NCB") and (current.type == "RSL"):
                current.type = "NCB"
            if (csr.type == "RSL") and (current.type == "NCB"):
                csr.type = "NCB"
            # FIXME: Is this true?
            # Silently convert mismatches between virtual and non virtual
            # PEXP. They are both access in the same way, so nobody
            # should care
            if (csr.type == "PEXP_NCB") and (current.type == "PEXPV_NCB"):
                csr.type = "PEXPV_NCB"
            if (csr.type == "PEXPV_NCB") and (current.type == "PEXP_NCB"):
                current.type = "PEXPV_NCB"
            assert csr.type == current.type, "%s %s:%s == %s:%s" % (name, chip, csr.type, chips[0], current.type)
            assert len(csr.range) == len(current.range), "%s %s:%d == %s:%d" % (name, chip, len(csr.range), chips[0], len(current.range))
            for i in xrange(1, len(csr.address_info)):
                if csr.address_info[i] == 0:
                    csr.address_info[i] = current.address_info[i]
                elif current.address_info[i] == 0:
                    current.address_info[i] = csr.address_info[i]

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
        combined_csr.address_info = current.address_info

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
                # then we must mark this as a conflict
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
                        if ((not csr_by_chip[chip2].fields[start_bit2].name.startswith("reserve")) and
                            (csr_by_chip[chip2].fields[start_bit2].name != field.name) and
                            (start_bit == start_bit2)):
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

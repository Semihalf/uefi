
import sys
import re
import csr_output_html
import traceback
from pyparsing import *
from csr import *

NAME_TO_ADDRESS_NAME_MAPPING = {
    "LMC0_WODT_CTL0":          "LMC0_WODT_CTL",
    "SMI0_CLK":                "SMI_CLK",
    "SMI0_CMD":                "SMI_CMD",
    "SMI0_EN":                 "SMI_EN",
    "SMI0_RD_DAT":             "SMI_RD_DAT",
    "SMI0_WR_DAT":             "SMI_WR_DAT",
    "MIO_TWS0_INT":            "MIO_TWS_INT",
    "MIO_TWS0_SW_TWSI":        "MIO_TWS_SW_TWSI",
    "MIO_TWS0_SW_TWSI_EXT":    "MIO_TWS_SW_TWSI_EXT",
    "MIO_TWS0_TWSI_SW":        "MIO_TWS_TWSI_SW",
}

CSR_NAMES_TO_SKIP = [
    "mio_boot_reg_cfg0",
    "mio_boot_reg_tim0",
    "usbc#_diepctl0",
    "usbc#_dieptsiz0",
    "usbc#_doepctl0",
    "usbc#_doeptsiz0",
]

#
# Global variables
#
current_csr_list = None
current_csr = None
current_address_list = None
incomplete_csrs = []

#
# The following are callback functions called by pyparsing as the input
# is parsed
#

# Convert a number string into a long
def actionNumber(pstr, loc, t):
    return long(t[0], 0)

# Create a new CSR when we parse a CSR header
def actionCsrHeader(pstr, loc, t):
    global current_csr
    try:
        name = []
        name.extend(t[1])
        descr = []
        descr.extend(t[0])
        current_csr = Csr(name, t[2], descr)
        incomplete_csrs.append(current_csr)
    except:
        raise ParseFatalException(pstr, loc, traceback.format_exc())

# Convert a bit number field into a tuple
def actionBitNums(pstr, loc, t):
    if len(t) == 3:
        return (t[1],t[1])
    elif len(t) == 5:
        if t[1] < t[3]:
            return (t[1],t[3])
        else:
            return (t[3],t[1])
    else:
        raise ParseFatalException(pstr, loc, "Invalid bit width field")

# Convert a range x(..y) into a tuple
def actionRangePart(pstr, loc, t):
    if len(t) == 1:
        return (t[0],t[0])
    elif len(t) == 3:
        if t[0] < t[2]:
            return (t[0],t[2])
        else:
            return (t[2],t[0])
    else:
        raise ParseFatalException(pstr, loc, "Invalid range part")

# Convert a range x(..y)(,x..y) into a tuple
def actionRange(pstr, loc, t):
    result = []
    for range in t:
        result.extend(range)
    result = [result]
    return result

# Add a field to the CSR when one is parsed
def actionField(pstr, loc, t):
    global current_csr
    try:
        descr = []
        descr.extend(t[5])
        current_csr.addField(CsrField(start_bit = t[0][0],
                                  stop_bit = t[0][1],
                                  name = t[1],
                                  field_type = t[2],
                                  reset_value = t[3],
                                  typical_value = t[4],
                                  description = descr))
    except:
        raise ParseFatalException(pstr, loc, traceback.format_exc())

# Set the notes for a CSR when they are found
def actionNotes(pstr, loc, t):
    global current_csr
    try:
        current_csr.setNotes(t[0].replace("\r", "").split("\n"))
    except:
        raise ParseFatalException(pstr, loc, traceback.format_exc())

# Called when a CSR has been completely parsed
def actionCsr(pstr, loc, t):
    global current_csr
    global current_csr_list
    global incomplete_csrs
    try:
        for csr in incomplete_csrs[0:-1]:
            csr.fields = current_csr.fields
            csr.validate()
            current_csr_list.addCsr(csr)
        incomplete_csrs = []
        if not current_csr.name in CSR_NAMES_TO_SKIP:
            current_csr.validate()
            current_csr_list.addCsr(current_csr)
    except:
        raise ParseFatalException(pstr, loc, traceback.format_exc())


# Called when a CSR address is completely parsed
def actionCsrAddress(pstr, loc, t):
    global current_address_list
    try:
        name = t[0][0].upper()
        name = name.replace("PCI_DBELL_", "PCI_DBELL")
        if name in current_address_list:
            raise ParseFatalException(pstr, loc, "Duplicate address line: " + str(t))
        if len(t) == 5:
            current_address_list[name] = (t[3], t[1]) # NCB address, PCI alias
        else:
            current_address_list[name] = (t[1], -1) # NCB address, no PCI alias
    except:
        raise ParseFatalException(pstr, loc, traceback.format_exc())

#
# Build a grammer to match a series of keywords
#
def buildKeywordMatcher(keyword_list):
    result = Keyword(keyword_list[0])
    for k in keyword_list:
        result ^= Keyword(k)
    return result

#
# Common items for building a grammer
#
WHITE = Suppress(Word(" "))
EOL = Suppress(Optional(Literal("\r")) + Literal("\n"))
LINE = restOfLine + EOL
EMPTY_LINE=Optional(WHITE) + EOL
EMPTY_LINES=ZeroOrMore(EMPTY_LINE)

NUMBER = Combine((Literal("0x") + Word(nums+"abcdefABCDEF")) ^ Word(nums))
NUMBER.setParseAction(actionNumber)

#
# CSR grammer items
#
EQUALS_BANNER=WHITE + Literal("==============================================================")
DASHES_BANNER=Literal("----------------------------------------------------------------------------------------------------")
FIELD_TITLE1=Literal("Bit      Field   Field    Reset     Typical     Field")
FIELD_TITLE2=Literal("Pos      Name    Type     Value     Value       Description")
FIELD_COMMENT_INDENT=Suppress(Literal("                    ") ^ Literal("\t\t\t\t\t"))

STAR_COMMENT=Suppress(Optional(WHITE) + (Literal("*")^Literal("//"))) + LINE
STAR_BLOCK = OneOrMore(STAR_COMMENT)

RANGEPART = NUMBER + Optional(Literal("..") + NUMBER)
RANGEPART.setParseAction(actionRangePart)
RANGE = Literal("(").suppress() + RANGEPART + ZeroOrMore(Literal(",").suppress() + Optional(Literal(" ")).suppress() + RANGEPART) + Literal(")").suppress()
RANGE.setParseAction(actionRange)

CSR_TYPES = buildKeywordMatcher(VALID_CSR_TYPES)
CSR_NAME = Group(OneOrMore(Word(alphas+"_"+nums)+Optional(RANGE)))

BIT_NUMS = Literal("<") + NUMBER + Optional(Literal(":") + NUMBER) + ">"
BIT_NUMS.setParseAction(actionBitNums)
FIELD_NAME = Word(alphas+"_"+nums)
FIELD_TYPE = buildKeywordMatcher(VALID_FIELD_TYPES)
RESET_VALUE = Keyword("NS") ^ Keyword("X") ^ Keyword("{@}") ^ NUMBER
TYPICAL_VALUE = Keyword("NS") ^ Keyword("X") ^ Keyword("NA") ^ Keyword("{@}") ^ (NUMBER + Optional(Literal("/") + NUMBER))
COMMENT = LINE + ZeroOrMore((EMPTY_LINE ^ (FIELD_COMMENT_INDENT + LINE)))
FIELD = Optional(WHITE) + BIT_NUMS + WHITE + FIELD_NAME + WHITE + FIELD_TYPE + WHITE + RESET_VALUE + WHITE + TYPICAL_VALUE + Group(EOL ^ (WHITE + COMMENT))
FIELD.setParseAction(actionField)
FIELDS = OneOrMore(FIELD)

NOTES = Suppress(Optional(Literal(" ")) + (CaselessLiteral("Notes:") ^ CaselessLiteral("Note:"))) + SkipTo(DASHES_BANNER)
NOTES.setParseAction(actionNotes)

CSR_HEADER = (Group(ZeroOrMore(STAR_BLOCK + EMPTY_LINES)) +
    Suppress(EQUALS_BANNER + EOL) +
    WHITE + CSR_NAME + WHITE + Suppress(Literal("Type=")) + CSR_TYPES + EOL +
    Suppress(EQUALS_BANNER + EOL))
CSR_HEADER.setParseAction(actionCsrHeader)

CSR = (OneOrMore(CSR_HEADER +
    EMPTY_LINES) +
    Suppress(DASHES_BANNER + EOL +
    FIELD_TITLE1 + EOL +
    FIELD_TITLE2 + EOL +
    DASHES_BANNER + EOL +
    Optional(EMPTY_LINE)) +
    FIELDS +
    Optional(NOTES) +
    Suppress(DASHES_BANNER + EOL) +
    Suppress(Literal("===") + EOL))
CSR.setParseAction(actionCsr)

#
# CSR address grammer items
#
ADDRESS_BANNER1 = Literal("CSR                            Address            CSR Type     Address            CSR_Type")
ADDRESS_BANNER2 = Literal("------------------------------------------------------------------------------------------")
ADDRESS_BANNER = ADDRESS_BANNER1 + EOL + ADDRESS_BANNER2 + Optional(WHITE) + EOL

CSR_ADDRESS = CSR_NAME + WHITE + NUMBER + WHITE + CSR_TYPES + Optional(WHITE + NUMBER + WHITE + CSR_TYPES) + Optional(WHITE) + EOL
CSR_ADDRESS.setParseAction(actionCsrAddress)

#
# Entire file grammer
#
CSR_FILE = (EMPTY_LINES +
    OneOrMore(CSR + EMPTY_LINES) +
    Suppress(ADDRESS_BANNER) +
    OneOrMore(CSR_ADDRESS) +
    StringEnd())
CSR_FILE.leaveWhitespace()


#
#
#
def read(name, file):
    global current_csr_list
    global current_address_list
    current_csr_list = CsrList(name)
    current_address_list = {}
    try:
        CSR_FILE.parseFile(file)
    except:
        if current_csr:
            print"********************************************"
            print"Exception on CSR: " + current_csr.name
            print"********************************************"
        raise
    # Loop through all CSRs to calculate the address base, block offset, and offset increment
    for csr in current_csr_list:
        #print csr.name, csr.range
        if len(csr.range) == 0:
            # This CSR doesn't have a range. Get a single value
            assert "#" not in csr.name, "# found in csr %d without a range" % csr.name
            name = csr.name.upper()
            csr.address_info = [current_address_list[name][0]]
            del current_address_list[name]
        elif len(csr.range) == 1:
            # This CSR has a single index
            parts = csr.name.upper().split("#")
            assert len(parts) == 2, csr.name
            offset = csr.range[0][0]
            if csr.range[0][0] == csr.range[0][1]:
                if len(csr.range[0]) > 2:
                    offset_delta = csr.range[0][2] - csr.range[0][0]
                else:
                    offset_delta = 0
            else:
                offset_delta = 1
            offset_digits = len(str(max(csr.range[0])))
            n1 = "%s%d%s" % (parts[0], offset, parts[1])
            if not n1 in current_address_list:
                n1 = NAME_TO_ADDRESS_NAME_MAPPING[n1]
            address1 = current_address_list[n1][0]
            n2 = "%s%d%s" % (parts[0], offset+offset_delta, parts[1])
            if not n2 in current_address_list:
                n2 = NAME_TO_ADDRESS_NAME_MAPPING[n2]
            address2 = current_address_list[n2][0]
            csr.address_info = [0,0]
            if offset_delta:
                csr.address_info[1] = (address2 - address1) / offset_delta
            else:
                csr.address_info[1] = 0
            # The base is the value if the index were zero. If it starts
            # higher than that we need to subtract stuff off
            csr.address_info[0] = address1 - csr.address_info[1]*offset

            for name,calc_address,unused1,unused2 in csr.iterateAddresses():
                if not name in current_address_list:
                    name = NAME_TO_ADDRESS_NAME_MAPPING[name]
                assert calc_address == current_address_list[name][0], "%x == %x[%s][0]" % (calc_address, current_address_list[name][0], name)
                del current_address_list[name]
        elif len(csr.range) == 2:
            # This CSR has two indexes
            parts = csr.name.upper().split("#")
            assert len(parts) == 3, csr.name
            block = csr.range[0][0]
            block2 = csr.range[0][-1]
            offset = csr.range[1][0]
            offset2 = csr.range[1][-1]
            n1 = "%s%d%s%03d%s" % (parts[0], block, parts[1], offset, parts[2])
            csr.address_info = [0,0,0]
            if offset == offset2:
                address1 = current_address_list[n1][0]
                address2 = address1
                csr.address_info[2] = 0
            else:
                address1 = current_address_list[n1][0]
                n2 = "%s%d%s%03d%s" % (parts[0], block, parts[1], offset2, parts[2])
                address2 = current_address_list[n2][0]
                csr.address_info[2] = (address2 - address1) / (offset2 - offset)
            if block == block2:
                address1 = current_address_list[n1][0]
                address2 = address1
                csr.address_info[1] = 0
            else:
                address1 = current_address_list[n1][0]
                n2 = "%s%d%s%03d%s" % (parts[0], block2, parts[1], offset, parts[2])
                address2 = current_address_list[n2][0]
                csr.address_info[1] = (address2 - address1) / (block2 - block)
                if csr.type == "SRIOMAINT":
                    assert (csr.address_info[1] == 0)
                else:
                    assert (csr.address_info[1] in [0x1000000, 0x8000000, 0x60000000, 0x100000000000]), "%s offset=%d offset_inc=%d block_inc=%x" % (csr.name, offset,  csr.address_info[2], csr.address_info[1])
            csr.address_info[0] = address1 - csr.address_info[1]*csr.range[0][0] - csr.address_info[2]*csr.range[1][0]

            for name,calc_address,unused1,unused2 in csr.iterateAddresses():
                assert calc_address == current_address_list[name][0], "%x == %x[%s][0]" % (calc_address, current_address_list[name][0], name)
                del current_address_list[name]
        else:
            raise Exception("Unexpected CSR range length")
    # When we are done the address list should be empty. Each was removed as a
    # CSR verified against it.
    assert not current_address_list, str(current_address_list)
    return current_csr_list


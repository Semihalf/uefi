import re
import textwrap

def fixDescription(descr):
    if not descr:
        return []
    description = []
    description.extend(descr)
    # Remove some strings that we don't want in our descriptions
    for i in range(0,len(description)):
        description[i] = description[i].replace("*DON'T PUT IN HRM*", "")
        description[i] = description[i].replace("*UNUSED IN 63xx*", "")
        description[i] = description[i].replace("*** NOTE: O9N PASS1 Addition", "")
        description[i] = description[i].replace("*** NOTE: PASS2 Addition", "")
        description[i] = description[i].replace("*** NOTE: O56 PASS1 Addition", "")
        description[i] = description[i].replace("*** NOTE: O9N PASS2 Addition", "")
        description[i] = description[i].replace("NOTE: O9N Addition", "")
        description[i] = description[i].replace("(PASS2 only)", "")
        description[i] = description[i].replace("PASS2 Field.", "")
        description[i] = description[i].replace("** NEW O9N **", "")
        description[i] = description[i].replace("O1P", "CN30XX")
        description[i] = description[i].replace("O9N", "CN58XX")
        description[i] = description[i].replace("O56", "CN56XX")
    # Strip off ending "|", "$R", "NS"
    for i in range(0,len(description)):
        description[i] = description[i].rstrip()
        for s in ["NS", "$R", "$PR", "|"]:
            if description[i].endswith(s):
                description[i] = description[i][0:-len(s)].rstrip()
    # Remove leading blank lines
    while len(description) and description[0].strip() == "":
        del description[0]
    # Remove trailing blank lines
    while len(description) and description[-1].strip() == "":
        del description[-1]
    # Make sure there is a description
    if len(description) == 0:
        return []
    # The first line should not be indented
    description[0] = description[0].strip()
    # Check each line
    for i in range(0,len(description)):
        # Replace @ with the CSR range
        if "@" in description[i]:
            if description[i].strip().find("@") == 0:   # Probably a doxygen command
                pass
            else:
                description[i] = description[i].replace("@", "X")   # Probably a ref to another CSR
        # Don't put {} in comments
        description[i] = description[i].replace("{", "[")
        description[i] = description[i].replace("}", "]")
        description[i] = description[i].replace("/*", "/ *")
        description[i] = description[i].replace("*/", "* /")
        description[i] = description[i].replace("<version>", "\\<version\\>") # Doxygen mistakenly thinks it is html

        description[i] = re.sub("^([ ]+)[ ]([0-9](-[0-9]+)?):", "\\1- \\2:", description[i]) # Create lists from lines that start with number ranges
        description[i] = re.sub("^([ ]+)([0-9]+(-[0-9]+)?):", "\\1- \\2:", description[i]) # Create lists from lines that start with number ranges
        description[i] = re.sub("^([ ]+)\\.\\.$", "\\1- ...", description[i]) # Create lists from .. lines
        description[i] = re.sub("^([ ]+)(\\.[\\.]+)$", "\\1- \\2", description[i]) # Create lists from ... lines
        description[i] = re.sub("([^a-zA-Z\\\\])\\#", "\\1\\#", description[i]) # Need to escape '#' or doxygen complains
        # Doxygen doesn't like lines that end with "..". It thinks they are some
        # sort of list. Three dots is ok.
        if not description[i].endswith("...") and description[i].endswith(".."):
            description[i] = description[i][0:-2]
        # Check for invalid characters
        if not re.match("^[a-zA-Z0-9_@()\- \.=\]\[:,`#/+<>!^*|'\"&$?;~%\\\\]*$", description[i]):
            raise Exception("Illegal character in description: " + description[i])

    description[1:] = textwrap.dedent("\n".join(description[1:])).split("\n")
    return description


def fixFieldName(csr, field):
    old_name = field.name
    if old_name == "break":
        return "brk"
    elif old_name == "int":
        return "intr"
    elif old_name == "or":
        return "orbit"
    elif old_name == "short":
        return "shortl"
    elif old_name == "static":
        return "statc"
    elif old_name == "switch":
        return "switchf"
    elif old_name == "enum":
        return "enumb"
    else:
        return old_name.lower()


def fixFields(csr):
    for bit in csr.fields:
        f = csr.fields[bit]
        f.name =fixFieldName(csr, f)
        f.description = fixDescription(f.description)
        if f.name.startswith("reserved"):
            f.description = []
            f.field_type = "RAZ"
            f.reset_value = 0L
            f.typical_value = "NS"


def fixCsr(csr):
    csr.description = fixDescription(csr.description)
    csr.notes = fixDescription(csr.notes)
    fixFields(csr)


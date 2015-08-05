import re
import textwrap

def fixDescription(descr):
    if not descr:
        return []
    description = []
    description.extend(descr)
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
        description[i] = description[i].replace("/*", "/ *")
        description[i] = description[i].replace("*/", "* /")
        description[i] = re.sub("([^\\\\])<", "\\1\\<", description[i]) # Replace < not already escaped with escaped <
        description[i] = re.sub("^<", "\\<", description[i]) # Replace < not already escaped with escaped <
        description[i] = re.sub("([^\\\\])>", "\\1\\>", description[i]) # Replace > not already escaped with escaped >
        description[i] = re.sub("([^\\\\])#", "\\1\\#", description[i]) # Replace # not already escaped with escaped #
        description[i] = re.sub("^([ ]+)[ ]([0-9](-[0-9]+)?):", "\\1- \\2:", description[i]) # Create lists from lines that start with number ranges
        description[i] = re.sub("^([ ]+)([0-9]+(-[0-9]+)?):", "\\1- \\2:", description[i]) # Create lists from lines that start with number ranges
        description[i] = re.sub("^([ ]+)\\.\\.$", "\\1- ...", description[i]) # Create lists from .. lines
        description[i] = re.sub("^([ ]+)(\\.[\\.]+)$", "\\1- \\2", description[i]) # Create lists from ... lines
        # Doxygen doesn't like lines that end with "..". It thinks they are some
        # sort of list. Three dots is ok.
        if not description[i].endswith("...") and description[i].endswith(".."):
            description[i] = description[i][0:-2]
        # Check for invalid characters
        if not re.match("^[a-zA-Z0-9_@(){}\- \.=\]\[:,`#/+<>!^*|'\"&$?;~%\\\\]*$", description[i]):
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


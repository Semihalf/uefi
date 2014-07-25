import time
import os

BG_RESERVED = "gray"
BG_TITLE = "lightgray"
BG_NEW = "lightgreen"
BG_MOVED = "lightblue"
BG_SIZED = "yellow"
BG_DELETED = "lightpink"
BG_CHANGED = "cyan"

BEGIN_TABLE = "<table cellspacing=1 cellpadding=1 bgcolor=black>\n"

def TD(s, width=None, rowspan=1, colspan=1, bgcolor=None):
    result = "<td align=left valign=top"

    if width:
        result += " width=" + width
    if bgcolor:
        result += " bgcolor=" + bgcolor
    else:
        result += " bgcolor=white"
    if rowspan > 1:
        result += " rowspan=" + str(rowspan)
    if colspan > 1:
        result += " colspan=" + str(colspan)
    result += ">" + s + "</td>"
    return result

def PRE(s):
    return "<pre>\n" + s + "</pre>"

def csr_link_text(name):
    return name.replace("#", "x")

def csr_output_filename(name):
    return csr_link_text(name) + ".html"

def rangeAsString(range):
    str = ""
    for r in range:
        rng = ""
        loc = 0
        while loc < len(r):
            a = r[loc]
            b = r[loc+1]
            loc += 2
            if a == b:
                rng += ",%d" % a
            else:
                rng += ",%d-%d" % (a,b)
        str += ",(%s)" % rng[1:]
    if str:
        str = str[1:]
    return str

def writePageHeader(out, title):
    out.write("<html>\n")
    out.write("<head>\n")
    out.write("<title>%s</title>\n" % title)
    out.write("</head>\n")
    out.write("<body>\n")
    out.write("<font size=+3>%s</font><br>\n" % title)
    out.write("<font size=-1>Updated: %s</font><br><br>\n" % time.asctime())

def writePageFooter(out):
    out.write("</body>\n")
    out.write("</html>\n")

def writeCsrHeader(out, csr, hide_address=0):
    display_name = csr_link_text(csr.name).upper()
    out.write(BEGIN_TABLE)
    out.write("<tr>" + TD("Name", bgcolor=BG_TITLE) + TD(display_name) + "</tr>\n")
    out.write("<tr>" + TD("Type", bgcolor=BG_TITLE) + TD(csr.type) + "</tr>\n")
    out.write("<tr>" + TD("Range", bgcolor=BG_TITLE) + TD(rangeAsString(csr.range)) + "</tr>\n")
    if not hide_address:
        out.write("<tr>" + TD("Address", bgcolor=BG_TITLE) + TD(csr.getAddressEquation(no_ull=1)) + "</tr>\n")
    out.write("<tr>" + TD("Description", bgcolor=BG_TITLE, colspan=2) + "</tr>\n")
    out.write("<tr>" + TD(PRE("\n".join(csr.description)), colspan=2) + "</tr>\n")
    out.write("<tr>" + TD("Notes", bgcolor=BG_TITLE, colspan=2) + "</tr>\n")
    out.write("<tr>" + TD(PRE("\n".join(csr.notes)), colspan=2) + "</tr>\n")
    out.write("</table>\n")

def writeCsr(out, csr, title=None, colors={}):
    if title:
        out.write("<font size=+2>%s</font>\n" % title)
    out.write(BEGIN_TABLE)
    out.write("<tr>")
    out.write(TD("Bit", bgcolor=BG_TITLE))
    out.write(TD("Field", bgcolor=BG_TITLE))
    out.write(TD("Type", bgcolor=BG_TITLE))
    out.write(TD("Reset", bgcolor=BG_TITLE))
    out.write(TD("Typical", bgcolor=BG_TITLE))
    out.write(TD("Description", bgcolor=BG_TITLE))
    out.write("</tr>")
    bits = csr.fields.keys()
    bits.sort()
    bits.reverse()
    for start_bit in bits:
        field = csr.fields[start_bit]
        if field.name.startswith("reserved"):
            continue
        out.write("<tr>")
        if field.start_bit in colors:
            bg_color = colors[field.start_bit]
        else:
            bg_color = None
        if field.start_bit == field.stop_bit:
            out.write(TD("%d" % field.start_bit, bgcolor=bg_color))
        else:
            out.write(TD("%2d:%2d" % (field.stop_bit, field.start_bit), bgcolor=bg_color))
        out.write(TD(field.name, bgcolor=bg_color))
        out.write(TD(field.type, bgcolor=bg_color))
        out.write(TD(str(field.reset_value), bgcolor=bg_color))
        out.write(TD(str(field.typical_value), bgcolor=bg_color))
        out.write(TD(PRE("\n".join(field.description)), bgcolor=bg_color))
        out.write("</tr>")
    out.write("</table>\n")

def writeCombinedCsr(combined_list):
    chips = combined_list.keys()
    chips.sort()
    chips.reverse()
    # Use the combined superset for the common info
    csr = combined_list["s"]
    bits_in_csr = csr.getNumBits()
    # Open the output file
    out = open("html/s/" + csr_output_filename(csr.name), "w")
    writePageHeader(out, csr_link_text(csr.name).upper())
    out.write("<table>")
    out.write("<tr><td valign=top>")
    writeCsrHeader(out, csr, 1)
    by_signature = {}
    for chip in chips:
        if chip != "s":
            signature = combined_list[chip].getSignature()
            if signature in by_signature:
                by_signature[signature][0] += ", %s" % chip
            else:
                by_signature[signature] = [chip, combined_list[chip]]
    csr_list = [by_signature[x] for x in by_signature]
    csr_list.sort()
    csr_list.reverse()
    for pair in csr_list:
        writeCsr(out, pair[1], title=pair[0].upper())
    # Create a bit table for use in filling in the HTML table
    bit_table = {}
    for chip in chips:
        bit_table[chip] = ["reserved" for b in xrange(bits_in_csr)]
        csr = combined_list[chip]
        for start_bit in csr.fields:
            field = csr.fields[start_bit]
            for bit in xrange(field.start_bit, field.stop_bit+1):
                if field.name.startswith("reserved"):
                    bit_table[chip][bit] = "reserved"
                else:
                    bit_table[chip][bit] = field.name
    # Delete the name for every bit that has the same name as the one above
    # it. This reduces clutter in the HTML table
    for chip in chips:
        for bit in xrange(bits_in_csr-1):
            if bit_table[chip][bit] == bit_table[chip][bit+1]:
                bit_table[chip][bit] = None
    out.write("</td><td valign=top>")
    out.write("<font size=+2>Bit Overview</font>\n")
    out.write(BEGIN_TABLE)
    out.write("<tr>")
    out.write(TD("Bit", bgcolor=BG_TITLE))
    for chip in chips:
        out.write(TD(chip, bgcolor=BG_TITLE))
    out.write("</tr>\n")
    for bit in xrange(bits_in_csr-1, -1, -1):
        out.write("<tr>")
        # Use a smaller font for the bit numbers
        out.write(TD("<font size=-3>"+str(bit)+"</font>", bgcolor=BG_TITLE))
        for chip in chips:
            # Emty places in the bit table are filled by row spans
            if bit_table[chip][bit]:
                rowspan = 1
                # Span until then next non empty field
                while bit-rowspan>=0:
                    if bit_table[chip][bit-rowspan]:
                        break
                    rowspan+=1
                # Just gray out reserved fields. Don't show any other data for them
                if bit_table[chip][bit] == "reserved":
                    out.write(TD("", rowspan=rowspan, bgcolor=BG_RESERVED))
                else:
                    out.write(TD(bit_table[chip][bit], rowspan=rowspan))
        out.write("</tr>\n")
    out.write("</table>\n")
    out.write("</td></tr>")
    out.write("</table>\n")
    writePageFooter(out)
    out.close()

def writeLinkTable(out, link_dict):
    MAX_COLUMNS = 5
    current_prefix = None
    columns = 0
    out.write(BEGIN_TABLE + "<tr><td bgcolor=white valign=top>\n")
    names = link_dict.keys()
    names.sort()
    for name in names:
        prefix = name.split("_")[0]
        if prefix != current_prefix:
            columns += 1
            if columns > MAX_COLUMNS:
                columns = 1
                out.write("</td></tr>\n<tr><td bgcolor=white valign=top>\n")
            elif current_prefix:
                out.write("</td><td bgcolor=white valign=top>\n")
            current_prefix = prefix
        out.write("<a href=%s>%s</a><br>\n" % (link_dict[name], name))
    while columns < MAX_COLUMNS:
        columns += 1
        out.write("</td><td bgcolor=white valign=top>\n")
    out.write("</td></tr></table>\n")

def writeCsrIndex(filename, title, csr_name_list):
    current_prefix = None
    columns = 0
    out = open("html/s/index.html", "w")
    writePageHeader(out, "Thunder CSRs across all chips")
    link_dict = {}
    for name in csr_name_list:
        link_dict[csr_link_text(name)] = csr_output_filename(name)
    writeLinkTable(out, link_dict)
    writePageFooter(out)

def diffField(field, old_csr, missing_is_new):
    for start_bit in old_csr.fields:
        oldf = old_csr.fields[start_bit]
        if field.name == oldf.name:
            if field.start_bit == oldf.start_bit:
                if field.stop_bit == oldf.stop_bit:
                    if ((field.type != oldf.type) or
                        (field.reset_value != oldf.reset_value) or
                        (field.typical_value != oldf.typical_value)):
                        return BG_CHANGED
                    else:
                        return None
                else:
                    return BG_SIZED
            else:
                return BG_MOVED
    if missing_is_new:
        return BG_NEW
    else:
        return BG_DELETED

def writeDiffCsr(old_chip, old_csr, new_chip, new_csr):
    if new_csr:
        csr = new_csr
    else:
        csr = old_csr
    # Open the output file
    out = open("html/%s-%s-diff/%s" % (old_chip, new_chip, csr_output_filename(csr.name)), "w")
    writePageHeader(out, csr_link_text(csr.name).upper())
    out.write("<table><tr>")
    if new_csr:
        out.write("<td valign=top>")
        writeCsrHeader(out, new_csr)
        out.write("</td>")
    if old_csr:
        out.write("<td valign=top>")
        writeCsrHeader(out, old_csr)
        out.write("</td>")
    out.write("</tr><tr>")
    if new_csr:
        bg_color = {}
        if old_csr:
            for start_bit in new_csr.fields:
                c = diffField(new_csr.fields[start_bit], old_csr, 1)
                if c:
                   bg_color[start_bit] = c
        else:
            for start_bit in new_csr.fields:
                bg_color[start_bit] = BG_NEW
        out.write("<td valign=bottom>")
        writeCsr(out, new_csr, title=new_chip.upper(), colors=bg_color)
        out.write("</td>")
    if old_csr:
        bg_color = {}
        if new_csr:
            for start_bit in old_csr.fields:
                c = diffField(old_csr.fields[start_bit], new_csr, 0)
                if c:
                   bg_color[start_bit] = c
        else:
           for start_bit in old_csr.fields:
               bg_color[start_bit] = BG_DELETED
        out.write("<td valign=bottom>")
        writeCsr(out, old_csr, title=old_chip.upper(), colors=bg_color)
        out.write("</td>")
    out.write("</tr></table>")
    out.write(BEGIN_TABLE)
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp", bgcolor=BG_NEW), TD("New fields")))
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp", bgcolor=BG_DELETED), TD("Deleted fields")))
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp", bgcolor=BG_SIZED), TD("Resized fields")))
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp", bgcolor=BG_MOVED), TD("Moved fields")))
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp", bgcolor=BG_CHANGED), TD("Changed fields")))
    out.write("<tr>%s%s</tr>\n" % (TD("&nbsp&nbsp&nbsp"), TD("Unchanged fields")))
    out.write("</table>\n")
    out.write("</body>\n")
    out.write("</html>\n")
    out.close()

def writeChipDiffList(out, list, old_chip, new_chip):
    link_dict = {}
    for csr in list:
        link_dict[csr_link_text(csr.name)] = csr_output_filename(csr.name)
    writeLinkTable(out, link_dict)

def writeChipDiff(combined_list, old_chip, new_chip):
    added_csrs = []
    deleted_csrs = []
    modified_csrs = []
    same_csrs = []
    for csr in combined_list:
        old_csr = csr.get(old_chip, None)
        new_csr = csr.get(new_chip, None)
        if old_csr:
            if new_csr:
                if old_csr.getSignature(include_all=1) != new_csr.getSignature(include_all=1):
                    modified_csrs.append(new_csr)
                    writeDiffCsr(old_chip, old_csr, new_chip, new_csr)
                else:
                    same_csrs.append(new_csr)
                    writeDiffCsr(old_chip, old_csr, new_chip, new_csr)
            else:
                deleted_csrs.append(old_csr)
                writeDiffCsr(old_chip, old_csr, new_chip, None)
        else:
            if new_chip in csr:
                added_csrs.append(new_csr)
                writeDiffCsr(old_chip, None, new_chip, new_csr)
            else:
                continue # CSR not in either the old or new chips
    out = open("html/%s-%s-diff/index.html" % (old_chip, new_chip), "w")
    writePageHeader(out, "CSR Differences between %s (old) and %s (new)" % (old_chip.upper(), new_chip.upper()))
    out.write("<font size=+2>%s</font>\n" % "Modified")
    writeChipDiffList(out, modified_csrs, old_chip, new_chip)
    out.write("<font size=+2>%s</font>\n" % ("Added in %s" % new_chip.upper()))
    writeChipDiffList(out, added_csrs, old_chip, new_chip)
    out.write("<font size=+2>%s</font>\n" % ("Deleted in %s" % new_chip.upper()))
    writeChipDiffList(out, deleted_csrs, old_chip, new_chip)
    out.write("<font size=+2>%s</font>\n" % "Identical")
    writeChipDiffList(out, same_csrs, old_chip, new_chip)
    writePageFooter(out)


def writeAll(combined_list, diff=[]):
    os.mkdir("html/s")
    for csr in combined_list:
        writeCombinedCsr(csr)
    writeCsrIndex("html/s/index.html", "CSRs across all chips", combined_list.getNameList())

    chip_link_list = {}
    for csr in combined_list:
        for chip in csr:
            if chip == "s":
                continue
            if not chip in chip_link_list:
                chip_link_list[chip] = {}
                os.mkdir("html/%s" % chip)
            link_text = csr_link_text(csr[chip].name)
            filename = "%s/%s.html" % (chip, link_text)
            chip_link_list[chip][link_text] = "%s.html" % (link_text)
            out = open("html/" + filename, "w")
            writePageHeader(out, "%s - %s" % (chip.upper(), link_text.upper()))
            writeCsrHeader(out, csr[chip])
            writeCsr(out, csr[chip])
            writePageFooter(out)
            out.close()

    for chip in chip_link_list:
        filename = "html/%s/index.html" % (chip)
        out = open(filename, "w")
        writePageHeader(out, "CSRs for %s" % (chip.upper()))
        writeLinkTable(out, chip_link_list[chip])
        writePageFooter(out)
        out.close()

    for pair in diff:
        os.mkdir("html/%s-%s-diff" % (pair[0], pair[1]))
        writeChipDiff(combined_list, pair[0], pair[1])

    out = open("html/index.html", "w")
    writePageHeader(out, "Cavium Thunder CSRs")
    out.write("<a href=s/index.html>CSRs for all chips</a><br><br>\n")
    groups = {}
    groups["Thunder"] = []
    for chip in chip_link_list:
        if chip.startswith("cn8"):
            groups["Thunder"].append(chip)
        else:
            assert(0)
    archs = ["Thunder"]
    out.write(BEGIN_TABLE)
    out.write("<tr>")
    for arch in archs:
        out.write(TD(arch, bgcolor=BG_TITLE))
    out.write("</tr>\n")
    out.write("<tr>")
    for arch in archs:
        chips = groups[arch]
        chips.sort()
        s = ""
        for chip in chips:
            s += "<a href=%s/index.html>%s</a><br>\n" % (chip, chip)
        out.write(TD(s))
    out.write("</tr>\n")
    out.write("</table>\n")
    out.write("<br><br>\n")
    out.write(BEGIN_TABLE)
    out.write("<tr>")
    out.write(TD("Deltas between chips", bgcolor=BG_TITLE))
    out.write("</tr>\n")
    out.write("<tr>")
    s = ""
    for pair in diff:
        s +="<a href=%s-%s-diff/index.html>%s - %s</a><br>\n" % (pair[0], pair[1], pair[0], pair[1])
    out.write(TD(s))
    out.write("</tr>\n")
    out.write("</table>\n")
    writePageFooter(out)


import re
import textwrap

CSR_NAME_MAPPINGS = {
    "['IPD_QOS0_RED_MARKS']":       ["ipd_qos", [0,0], "_red_marks"],
    "['IPD_QOS1_RED_MARKS']":       ["ipd_qos", [1,1], "_red_marks"],
    "['IPD_QOS2_RED_MARKS']":       ["ipd_qos", [2,2], "_red_marks"],
    "['IPD_QOS3_RED_MARKS']":       ["ipd_qos", [3,3], "_red_marks"],
    "['IPD_QOS4_RED_MARKS']":       ["ipd_qos", [4,4], "_red_marks"],
    "['IPD_QOS5_RED_MARKS']":       ["ipd_qos", [5,5], "_red_marks"],
    "['IPD_QOS6_RED_MARKS']":       ["ipd_qos", [6,6], "_red_marks"],
    "['IPD_QOS7_RED_MARKS']":       ["ipd_qos", [7,7], "_red_marks"],
    "['IPD_RED_QUE0_PARAM']":       ["ipd_red_que", [0,0], "_param"],
    "['IPD_RED_QUE1_PARAM']":       ["ipd_red_que", [1,1], "_param"],
    "['IPD_RED_QUE2_PARAM']":       ["ipd_red_que", [2,2], "_param"],
    "['IPD_RED_QUE3_PARAM']":       ["ipd_red_que", [3,3], "_param"],
    "['IPD_RED_QUE4_PARAM']":       ["ipd_red_que", [4,4], "_param"],
    "['IPD_RED_QUE5_PARAM']":       ["ipd_red_que", [5,5], "_param"],
    "['IPD_RED_QUE6_PARAM']":       ["ipd_red_que", [6,6], "_param"],
    "['IPD_RED_QUE7_PARAM']":       ["ipd_red_que", [7,7], "_param"],
    "['FPA_FPF0_MARKS']":           ["fpa_fpf0_marks"],
    "['FPA_FPF1_MARKS']":           ["fpa_fpf", [1,1], "_marks"],
    "['FPA_FPF2_MARKS']":           ["fpa_fpf", [2,2], "_marks"],
    "['FPA_FPF3_MARKS']":           ["fpa_fpf", [3,3], "_marks"],
    "['FPA_FPF4_MARKS']":           ["fpa_fpf", [4,4], "_marks"],
    "['FPA_FPF5_MARKS']":           ["fpa_fpf", [5,5], "_marks"],
    "['FPA_FPF6_MARKS']":           ["fpa_fpf", [6,6], "_marks"],
    "['FPA_FPF7_MARKS']":           ["fpa_fpf", [7,7], "_marks"],
    "['FPA_QUE0_PAGE_INDEX']":      ["fpa_que", [0,0], "_page_index"],
    "['FPA_QUE1_PAGE_INDEX']":      ["fpa_que", [1,1], "_page_index"],
    "['FPA_QUE2_PAGE_INDEX']":      ["fpa_que", [2,2], "_page_index"],
    "['FPA_QUE3_PAGE_INDEX']":      ["fpa_que", [3,3], "_page_index"],
    "['FPA_QUE4_PAGE_INDEX']":      ["fpa_que", [4,4], "_page_index"],
    "['FPA_QUE5_PAGE_INDEX']":      ["fpa_que", [5,5], "_page_index"],
    "['FPA_QUE6_PAGE_INDEX']":      ["fpa_que", [6,6], "_page_index"],
    "['FPA_QUE7_PAGE_INDEX']":      ["fpa_que", [7,7], "_page_index"],
    "['L2C_PFC0']":                 ["l2c_pfc", [0,0]],
    "['L2C_PFC1']":                 ["l2c_pfc", [1,1]],
    "['L2C_PFC2']":                 ["l2c_pfc", [2,2]],
    "['L2C_PFC3']":                 ["l2c_pfc", [3,3]],
    "['LMC', [0L, 0L], '_WODT_CTL']": ["lmc", [0,0], "_wodt_ctl0"],
    "['NPI_MEM_ACCESS_SUBID6']":    ["npi_mem_access_subid", [6,6]],
    "['NPI_MEM_ACCESS_SUBID5']":    ["npi_mem_access_subid", [5,5]],
    "['NPI_MEM_ACCESS_SUBID4']":    ["npi_mem_access_subid", [4,4]],
    "['NPI_MEM_ACCESS_SUBID3']":    ["npi_mem_access_subid", [3,3]],
    "['PCI_PKTS_SENT_INT_LEV3']":   ["pci_pkts_sent_int_lev",[3,3]],
    "['PCI_PKTS_SENT_INT_LEV2']":   ["pci_pkts_sent_int_lev",[2,2]],
    "['PCI_PKTS_SENT_INT_LEV1']":   ["pci_pkts_sent_int_lev",[1,1]],
    "['PCI_PKTS_SENT_INT_LEV0']":   ["pci_pkts_sent_int_lev",[0,0]],
    "['PCI_PKTS_SENT_TIME3']":      ["pci_pkts_sent_time",[3,3]],
    "['PCI_PKTS_SENT_TIME2']":      ["pci_pkts_sent_time",[2,2]],
    "['PCI_PKTS_SENT_TIME1']":      ["pci_pkts_sent_time",[1,1]],
    "['PCI_PKTS_SENT_TIME0']":      ["pci_pkts_sent_time",[0,0]],
    "['PCI_PKTS_SENT3']":           ["pci_pkts_sent", [3,3]],
    "['PCI_PKTS_SENT2']":           ["pci_pkts_sent", [2,2]],
    "['PCI_PKTS_SENT1']":           ["pci_pkts_sent", [1,1]],
    "['PCI_PKTS_SENT0']":           ["pci_pkts_sent", [0,0]],
    "['PCI_INSTR_COUNT3']":         ["pci_instr_count", [3,3]],
    "['PCI_INSTR_COUNT2']":         ["pci_instr_count", [2,2]],
    "['PCI_INSTR_COUNT1']":         ["pci_instr_count", [1,1]],
    "['PCI_INSTR_COUNT0']":         ["pci_instr_count", [0,0]],
    "['PCI_DMA_TIME1']":            ["pci_dma_time", [1,1]],
    "['PCI_DMA_TIME0']":            ["pci_dma_time", [0,0]],
    "['PCI_DMA_INT_LEV1']":         ["pci_dma_int_lev", [1,1]],
    "['PCI_DMA_INT_LEV0']":         ["pci_dma_int_lev", [0,0]],
    "['PCI_DMA_CNT1']":             ["pci_dma_cnt", [1,1]],
    "['PCI_DMA_CNT0']":             ["pci_dma_cnt", [0,0]],
    "['PCI_DBELL_3']":              ["pci_dbell", [3,3]],
    "['PCI_DBELL_2']":              ["pci_dbell", [2,2]],
    "['PCI_DBELL_1']":              ["pci_dbell", [1,1]],
    "['PCI_DBELL_0']":              ["pci_dbell", [0,0]],
    "['PCI_PKT_CREDITS3']":         ["pci_pkt_credits", [3,3]],
    "['PCI_PKT_CREDITS2']":         ["pci_pkt_credits", [2,2]],
    "['PCI_PKT_CREDITS1']":         ["pci_pkt_credits", [1,1]],
    "['PCI_PKT_CREDITS0']":         ["pci_pkt_credits", [0,0]],
    "['NPI_NUM_DESC_OUTPUT0']":     ["npi_num_desc_output", [0,0]],
    "['NPI_NUM_DESC_OUTPUT1']":     ["npi_num_desc_output", [1,1]],
    "['NPI_NUM_DESC_OUTPUT2']":     ["npi_num_desc_output", [2,2]],
    "['NPI_NUM_DESC_OUTPUT3']":     ["npi_num_desc_output", [3,3]],
    "['NPI_BASE_ADDR_INPUT0']":     ["npi_base_addr_input", [0,0]],
    "['NPI_BASE_ADDR_INPUT1']":     ["npi_base_addr_input", [1,1]],
    "['NPI_BASE_ADDR_INPUT2']":     ["npi_base_addr_input", [2,2]],
    "['NPI_BASE_ADDR_INPUT3']":     ["npi_base_addr_input", [3,3]],
    "['NPI_BASE_ADDR_OUTPUT0']":    ["npi_base_addr_output", [0,0]],
    "['NPI_BASE_ADDR_OUTPUT1']":    ["npi_base_addr_output", [1,1]],
    "['NPI_BASE_ADDR_OUTPUT2']":    ["npi_base_addr_output", [2,2]],
    "['NPI_BASE_ADDR_OUTPUT3']":    ["npi_base_addr_output", [3,3]],
    "['NPI_BUFF_SIZE_OUTPUT0']":     ["npi_buff_size_output", [0,0]],
    "['NPI_BUFF_SIZE_OUTPUT1']":     ["npi_buff_size_output", [1,1]],
    "['NPI_BUFF_SIZE_OUTPUT2']":     ["npi_buff_size_output", [2,2]],
    "['NPI_BUFF_SIZE_OUTPUT3']":     ["npi_buff_size_output", [3,3]],
    "['NPI_P0_DBPAIR_ADDR']":   ["npi_p", [0,0], "_dbpair_addr"],
    "['NPI_P1_DBPAIR_ADDR']":   ["npi_p", [1,1], "_dbpair_addr"],
    "['NPI_P2_DBPAIR_ADDR']":   ["npi_p", [2,2], "_dbpair_addr"],
    "['NPI_P3_DBPAIR_ADDR']":   ["npi_p", [3,3], "_dbpair_addr"],
    "['NPI_P0_INSTR_ADDR']":    ["npi_p", [0,0], "_instr_addr"],
    "['NPI_P1_INSTR_ADDR']":    ["npi_p", [1,1], "_instr_addr"],
    "['NPI_P2_INSTR_ADDR']":    ["npi_p", [2,2], "_instr_addr"],
    "['NPI_P3_INSTR_ADDR']":    ["npi_p", [3,3], "_instr_addr"],
    "['NPI_P0_INSTR_CNTS']":    ["npi_p", [0,0], "_instr_cnts"],
    "['NPI_P1_INSTR_CNTS']":    ["npi_p", [1,1], "_instr_cnts"],
    "['NPI_P2_INSTR_CNTS']":    ["npi_p", [2,2], "_instr_cnts"],
    "['NPI_P3_INSTR_CNTS']":    ["npi_p", [3,3], "_instr_cnts"],
    "['NPI_P0_PAIR_CNTS']":     ["npi_p", [0,0], "_pair_cnts"],
    "['NPI_P1_PAIR_CNTS']":     ["npi_p", [1,1], "_pair_cnts"],
    "['NPI_P2_PAIR_CNTS']":     ["npi_p", [2,2], "_pair_cnts"],
    "['NPI_P3_PAIR_CNTS']":     ["npi_p", [3,3], "_pair_cnts"],
    "['NPI_SIZE_INPUT0']":      ["npi_size_input", [0,0]],
    "['NPI_SIZE_INPUT1']":      ["npi_size_input", [1,1]],
    "['NPI_SIZE_INPUT2']":      ["npi_size_input", [2,2]],
    "['NPI_SIZE_INPUT3']":      ["npi_size_input", [3,3]],
    "['SMI_CLK']":              ["smi", [0,0], "_clk"],
    "['SMI_CMD']":              ["smi", [0,0], "_cmd"],
    "['SMI_EN']":               ["smi", [0,0], "_en"],
    "['SMI_RD_DAT']":           ["smi", [0,0], "_rd_dat"],
    "['SMI_WR_DAT']":           ["smi", [0,0], "_wr_dat"],
    "['MIO_TWS_INT']":          ["mio_tws", [0,0], "_int"],
    "['MIO_TWS_SW_TWSI']":      ["mio_tws", [0,0], "_sw_twsi"],
    "['MIO_TWS_SW_TWSI_EXT']":  ["mio_tws", [0,0], "_sw_twsi_ext"],
    "['MIO_TWS_TWSI_SW']":      ["mio_tws", [0,0], "_twsi_sw"],
}

def fixCsrName(name):
    str_name = str(name)
    if str_name in CSR_NAME_MAPPINGS:
        return CSR_NAME_MAPPINGS[str_name]
    else:
        return name

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
    if ((old_name == "ns") or old_name.startswith("rsvrd") or old_name.startswith("rsvd") or
        old_name.startswith("unused") or (old_name == "revrd")) and (old_name != "rsvd_thr"):
        return "reserved_" + str(field.start_bit) + "_" + str(field.stop_bit)
    elif (csr.name == "ciu_mbox_set#") and (old_name == "set"):
        return "bits"
    elif (csr.name == "ciu_mbox_clr#") and (old_name == "clr"):
        return "bits"
    elif (csr.name == "ipd_wqe_fpa_queue") and (old_name == "wqe_que"):
        return "wqe_pool"
    elif (csr.name == "pko_mem_queue_ptrs") and (old_name == "qid"):
        return "queue"
    elif (csr.name == "pko_mem_queue_ptrs") and (old_name == "pid"):
        return "port"
    elif csr.name == "pip_prt_tag#":
        remap = {"inc_prt": "inc_prt_flag", "ip6_dprt": "ip6_dprt_flag", "ip4_dprt": "ip4_dprt_flag",
                "ip6_sprt": "ip6_sprt_flag", "ip4_sprt": "ip4_sprt_flag", "ip4_pctl": "ip4_pctl_flag",
                "ip6_nxth": "ip6_nxth_flag", "ip6_dst": "ip6_dst_flag", "ip4_dst": "ip4_dst_flag",
                "ip6_src": "ip6_src_flag", "ip4_src": "ip4_src_flag", "tcp6_tag": "tcp6_tag_type",
                "tcp4_tag": "tcp4_tag_type", "ip6_tag": "ip6_tag_type", "ip4_tag": "ip4_tag_type",
                "non_tag": "non_tag_type"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "pip_qos_watch#":
        remap = {"match":"match_value", "type":"match_type", "watcher":"qos"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "tim_reg_flags":
        remap = {"ena_tim": "enable_timers", "ena_dwb": "enable_dwb"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "tim_mem_ring0":
        remap = {"rid": "ring", "bsize": "num_buckets", "base": "first_bucket"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "tim_mem_ring1":
        remap = {"rid": "ring", "csize": "words_per_chunk", "cpool": "pool", "ena": "enable"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "pci_dma_cnt#":
        remap = {"dma0_cnt": "dma_cnt"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "mio_boot_bist_stat":
        remap = {"ncbo": "ncbo_0"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif csr.name == "npi_rsl_int_blocks":
        remap = {"rint_4": "key"}
        try:
            return remap[old_name]
        except:
            return old_name.lower()
    elif old_name == "idx":
        return "index"
    elif old_name == "break":
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
    elif old_name == "a":
        return "addr"
    elif old_name == "d":
        return "data"
    elif (csr.name == "lmc#_ctl") and (old_name == "sparef"):
        return "reserved_" + str(field.start_bit) + "_" + str(field.stop_bit)
    elif (csr.name == "l2d_fus3") and (old_name == "fus_spare"):
        return "reserved_" + str(field.start_bit) + "_" + str(field.stop_bit)
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


#
# This file generates functions for enabling and printing interrupt status
# registers. The idea here is to automate the process of creating the leaf
# CSR decodes for processing NPEI_RSL_INT_BLOCKS
#

import sys
import pprint
import csr
from types import *
from csr_output_header import writeCopyrightBanner

pp = pprint.PrettyPrinter(indent=4)

ERROR_REGISTERS = []
#
# Add a error register to the possible list in ERROR_REGISTERS. Entries
# not valid for the current chip are ignored. Parent can be either a
# string or a list of strings. When it is a list, the first item is used
# for CN68XX, the second for all other chips.
#
def add_reg(group, status, enable, parent):
    ERROR_REGISTERS.append({"group": group, "status": status, "enable": enable, "parent": parent})

#
# Roots for CN61XX, CN63XX, CN66XX, and CNF71XX
# There are two as some interrupts go to ciu_int0_sum0
# and some go to ciu_int_sum1
#
add_reg(group = None,
    status = "ciu_int0_sum0:!mpi,timer,key_zero,ipd_drp,gmx_drp,gpio",
    enable = "ciu_int0_en0",
    parent = "root:root")
add_reg(group = None,
    status = "ciu_int_sum1:!ptp",
    enable = "ciu_int0_en1",
    parent = "root:root2")
add_reg(group = None,
    status = "ciu_block_int",
    enable = None, # RML has no enable
    parent = "ciu_int0_sum0:rml")
#
# Root for CN68XX
# We use IP2 as the top of everything
#
add_reg(group = None,
    status = "ciu2_sum_pp0_ip2",
    enable = None, # Top level has no enable
    parent = "root:root3")
add_reg(group = None,
    status = "ciu2_src_pp0_ip2_io",
    enable = "ciu2_en_pp0_ip2_io",
    parent = "ciu2_sum_pp0_ip2:io")
add_reg(group = None,
    status = "ciu2_src_pp0_ip2_mem",
    enable = "ciu2_en_pp0_ip2_mem",
    parent = "ciu2_sum_pp0_ip2:mem")
add_reg(group = None,
    status = "ciu2_src_pp0_ip2_mio",
    enable = "ciu2_en_pp0_ip2_mio",
    parent = "ciu2_sum_pp0_ip2:mio")
add_reg(group = None,
    status = "ciu2_src_pp0_ip2_pkt",
    enable = "ciu2_en_pp0_ip2_pkt",
    parent = "ciu2_sum_pp0_ip2:pkt")
add_reg(group = None,
    status = "ciu2_src_pp0_ip2_rml",
    enable = "ciu2_en_pp0_ip2_rml",
    parent = "ciu2_sum_pp0_ip2:rml")
#
# AGL
#
add_reg(group = "agl",
    status = "agl_gmx_bad_reg:!statovr",
    enable = None, # No enable as of 3/9/2012
    parent = ["ciu2_src_pp0_ip2_pkt:agl", "ciu_block_int:agl"])
add_reg(group = "agl",
    status = "agl_gmx_rx0_int_reg:skperr,ovrerr",
    enable = "agl_gmx_rx0_int_en",
    parent = ["ciu2_src_pp0_ip2_pkt:agl", "ciu_block_int:agl"])
add_reg(group = "agl",
    status = "agl_gmx_rx1_int_reg:skperr,ovrerr",
    enable = "agl_gmx_rx1_int_en",
    parent = ["ciu2_src_pp0_ip2_pkt:agl", "ciu_block_int:agl"])
add_reg(group = "agl",
    status = "agl_gmx_tx_int_reg:pko_nxa,undflw",
    enable = "agl_gmx_tx_int_en",
    parent = ["ciu2_src_pp0_ip2_pkt:agl", "ciu_block_int:agl"])
#
# DFA
#
add_reg(group = "dfa",
    status = "dfa_error",
    enable = "dfa_intmsk",
    parent = ["ciu2_src_pp0_ip2_rml:dfa", "ciu_block_int:dfa"])
#
# DPI
#
add_reg(group = "dpi",
    status = "dpi_int_reg",
    enable = "dpi_int_en",
    parent = ["ciu2_src_pp0_ip2_rml:dpi", "ciu_block_int:dpi"])
add_reg(group = "dpi",
    status = "dpi_pkt_err_rsp",
    enable = None, # No enable as of 3/9/2012
    parent = ["ciu2_src_pp0_ip2_rml:dpi", "ciu_block_int:dpi"])
add_reg(group = "dpi",
    status = "dpi_req_err_rsp",
    enable = None, # No enable as of 3/9/2012
    parent = ["ciu2_src_pp0_ip2_rml:dpi", "ciu_block_int:dpi"])
add_reg(group = "dpi",
    status = "dpi_req_err_rst",
    enable = None, # No enable as of 3/9/2012
    parent = ["ciu2_src_pp0_ip2_rml:dpi", "ciu_block_int:dpi"])
#
# FPA
#
add_reg(group = "fpa",
    status = "fpa_int_sum",
    enable = "fpa_int_enb",
    parent = ["ciu2_src_pp0_ip2_rml:fpa", "ciu_block_int:fpa"])
#
# GMX
#
for interface in xrange(5): # CN68XX has up to 5
    parent = ["ciu2_src_pp0_ip2_pkt:agx[%d]" % interface]
    if interface < 2:
        parent.append("ciu_block_int:gmx%d" % interface)
    for index in xrange(4): # Up to 4 SGMII ports per interface
        prefix = "gmx%d_rx%03d_" % (interface, index)
        add_reg(group = "gmx",
            status = prefix + "int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
            enable = prefix + "int_en",
            parent = parent)
    prefix = "gmx%d_" % interface
    add_reg(group = "gmx",
        status = prefix + "tx_int_reg:!xscol,xsdef,late_col,xchange",
        enable = prefix + "tx_int_en",
        parent = parent)
    add_reg(group = "gmx",
        status = prefix + "bad_reg",
        enable = None, # No enable as of 3/9/2012
        parent = parent)
#
# ILK
#
add_reg(group = "ilk",
    status = "ilk_gbl_int",
    enable = "ilk_gbl_int_en",
    parent = "ciu2_src_pp0_ip2_pkt:ilk")
for interface in xrange(2): # Two interfaces on CN68XX
    add_reg(group = "ilk",
        status = "ilk_tx%d_int" % interface,
        enable = "ilk_tx%d_int_en" % interface,
        parent = "ciu2_src_pp0_ip2_pkt:ilk")
    add_reg(group = "ilk",
        status = "ilk_rx%d_int:!lane_align_done,lane_align_fail,word_sync_done" % interface,
        enable = "ilk_rx%d_int_en" % interface,
        parent = "ciu2_src_pp0_ip2_pkt:ilk")
for lane in xrange(8): # CN68XX supports up to 8 lanes
    add_reg(group = "ilk",
        status = "ilk_rx_lne%d_int" % lane,
        enable = "ilk_rx_lne%d_int_en" % lane,
        parent = "ciu2_src_pp0_ip2_pkt:ilk")
#
# IOB
#
add_reg(group = "iob",
    status = "iob0_int_sum",
    enable = "iob0_int_enb",
    parent = ["ciu2_src_pp0_ip2_rml:iob", "ciu_block_int:iob"])
#
# IPD
#
add_reg(group = "ipd",
    status = "ipd_int_sum:!pq_add,pq_sub",
    enable = "ipd_int_enb",
    parent = ["ciu2_src_pp0_ip2_rml:ipd", "ciu_block_int:ipd"])
#
# KEY
#
add_reg(group = "key",
    status = "key_int_sum",
    enable = "key_int_enb",
    parent = ["ciu2_src_pp0_ip2_rml:key", "ciu_block_int:key"])
#
# L2C
#
add_reg(group = "l2c",
    status = "l2c_int_reg",
    enable = "l2c_int_ena",
    parent = ["ciu2_src_pp0_ip2_rml:l2c", "ciu_block_int:l2c"])
for tad in xrange(4): # CN68XX has 4 TADs
    add_reg(group = "l2c_tad",
        status = "l2c_tad%d_int" % tad,
        enable = "l2c_tad%d_ien" % tad,
        parent = "l2c_int_reg:tad%d" % tad)
    # These bits have shadow copies in l2c_tad%d_int
    #add_reg(status = "l2c_err_tdt%d" %tad,
    #    enable = None,
    #    parent = "l2c_int_reg:tad%d" % tad)
    #add_reg(status = "l2c_err_ttg%d" % tad,
    #    enable = None,
    #    parent = "l2c_int_reg:tad%d" % tad)
#
# LMC
#
for lmc in xrange(4): # CN68XX has 4
    parent = ["ciu2_src_pp0_ip2_mem:lmc[%d]" % lmc]
    if lmc < 1:
        parent.append("ciu_block_int:lmc%d" % lmc)
    add_reg(group = "lmc",
        status = "lmc%d_int:nxm_wr_err,sec_err,ded_err" % lmc,
        enable = "lmc%d_int_en:intr_nxm_wr_ena,intr_sec_ena,intr_ded_ena" % lmc,
        parent = parent)
#
# MIO
#
add_reg(group = "mio",
    status = "mio_boot_err",
    enable = "mio_boot_int",
    parent = ["ciu2_src_pp0_ip2_mio:mio", "ciu_block_int:mio"])
add_reg(group = "mio",
    status = "mio_rst_int",
    enable = "mio_rst_int_en",
    parent = ["ciu2_src_pp0_ip2_mio:mio", "ciu_block_int:mio"])
#
# MIX
#
add_reg(group = "mix",
    status = "mix0_isr:!orthresh,irthresh,ts",
    enable = "mix0_intena",
    parent = ["ciu2_src_pp0_ip2_pkt:mii", "ciu_int0_sum0:mii"])
add_reg(group = "mix",
    status = "mix1_isr:!orthresh,irthresh,ts",
    enable = "mix1_intena",
    parent = ["ciu2_src_pp0_ip2_pkt:mii", "ciu_int_sum1:mii1"])
#
# NDF
#
add_reg(group = "nand",
    status = "ndf_int:!full,empty",
    enable = "ndf_int_en",
    parent = ["ciu2_src_pp0_ip2_mio:nand", "ciu_int_sum1:nand"])
#
# PCM
#
for pcm in xrange(4): # CN61XX has 4?
    add_reg(group = "pcm",
        status = "pcm%d_int_sum:fsyncmissed,fsyncextra,txempty,rxovf" % pcm,
        enable = "pcm%d_int_ena" % pcm,
        parent = "ciu_int0_sum0:pcm")
#
# PCS
#
for pcs in xrange(5): # CN68XX can have 5 RXAUI/XAUI
    parent = ["ciu2_src_pp0_ip2_pkt:agx[%d]" % pcs]
    if pcs < 2:
        parent.append("ciu_block_int:asxpcs%d" % pcs)
    for index in xrange(4): # 4 SGMII per interface
        add_reg(group = "pcs",
            status = "pcs%d_int%03d_reg:!xmit,dup,rxerr,lnkspd" % (pcs, index),
            enable = "pcs%d_int%03d_en_reg" % (pcs, index),
            parent = parent)
#
# PCSX
#
for pcsx in xrange(5): # CN68XX can have 5 RXAUI/XAUI
    parent = ["ciu2_src_pp0_ip2_pkt:agx[%d]" % pcsx]
    if pcsx < 2:
        parent.append("ciu_block_int:asxpcs%d" % pcsx)
    add_reg(group = "pcsx",
        status = "pcsx%d_int_reg" % pcsx,
        enable = "pcsx%d_int_en_reg" % pcsx,
        parent = parent)
#
# PEM
#
for pem in xrange(2): # Two PCIe controllers
    add_reg(group = "pem",
        status = "pem%d_int_sum" % pem,
        enable = "pem%d_int_enb" % pem,
        parent = ["ciu2_src_pp0_ip2_io:pem[%d]" % pem, "ciu_block_int:pem%d" % pem])
    add_reg(group = "pem",
        status = "pem%d_dbg_info" % pem,
        enable = "pem%d_dbg_info_en" % pem,
        parent = "pem%d_int_sum:exc" % pem)
#
# PKO
#
add_reg(group = "pko",
    status = "pko_reg_error",
    enable = "pko_reg_int_mask",
    parent = ["ciu2_src_pp0_ip2_rml:pko", "ciu_block_int:pko"])
#
# PIP
#
add_reg(group = "pip",
    status = "pip_int_reg:!pktdrp,crcerr,bckprs,minerr,maxerr,lenerr",
    enable = "pip_int_en",
    parent = ["ciu2_src_pp0_ip2_rml:pip", "ciu_block_int:pip"])
#
# SSO
#
if False: #FIXME: Now R/W1C safe
    add_reg(group = "sso_cn6xxx",
        status = "sso_ecc_err:sbe,dbe,rpe,iop",
        enable = "sso_ecc_err:sbe_ie,dbe_ie,rpe_ie,iop_ie",
        parent = ["ciu_block_int:pow"])
add_reg(group = "sso_cn68xx",
    status = "sso_err",
    enable = "sso_err_enb",
    parent = "ciu2_src_pp0_ip2_rml:sso")
#
# RAD
#
add_reg(group = "rad",
    status = "rad_reg_error",
    enable = "rad_reg_int_mask",
    parent = ["ciu2_src_pp0_ip2_rml:rad", "ciu_block_int:rad"])
#
# SRIO
#
for srio in xrange(2): # CN63XX and CN66XX have two SRIO controllers
    add_reg(group = "srio",
        status = "srio%d_int_reg:!omsg1,omsg0,link_up,link_dwn,soft_rx,soft_tx,mce_tx,wr_done,maint_op,rxbell,bell_err,txbell" % srio,
        enable = "srio%d_int_enable" % srio,
        parent = "ciu_block_int:srio%d" % srio)
#
# TIM
#
add_reg(group = "tim_cn6xxx",
    status = "tim_reg_error",
    enable = "tim_reg_int_mask",
    parent = "ciu_block_int:tim")
add_reg(group = "tim_cn68xx",
    status = "tim_int0",
    enable = "tim_int0_en",
    parent = "ciu2_src_pp0_ip2_rml:tim")
add_reg(group = "tim_cn68xx",
    status = "tim_int_eccerr",
    enable = "tim_int_eccerr_en",
    parent = "ciu2_src_pp0_ip2_rml:tim")
#
# USB
#
add_reg(group = "usb",
    status = "uctl0_int_reg",
    enable = "uctl0_int_ena",
    parent = ["ciu2_src_pp0_ip2_mio:usb_uctl", "ciu_int_sum1:usb"])
#
# ZIP
#
add_reg(group = "zip",
    status = "zip_error",
    enable = "zip_int_mask",
    parent = ["ciu2_src_pp0_ip2_rml:zip", "ciu_block_int:zip"])
add_reg(group = "zip",
    status = "zip_int_reg",
    enable = "zip_int_ena",
    parent = "ciu2_src_pp0_ip2_rml:zip")

#
# CsrInstance represents a specific instance of a generic CSR. An instance
# represents a CSR with a block and index number, ie fully specified for an
# exact chip register.
#
class CsrInstance:
    def __init__(self, pcsr, index=-1, block=-1):
        assert isinstance(pcsr, csr.Csr), type(csr)
        self.csr = pcsr
        self.index = index
        self.block = block

    def addressName(self):
        name = self.csr.name.replace("#", "X").upper()
        if self.block != -1:
            return "%s(%d,%d)" % (name, self.index, self.block)
        elif self.index != -1:
            return "%s(%d)" % (name, self.index)
        else:
            return name

    def instanceName(self):
        if self.block != -1:
            name = self.csr.name.split("#")
            assert len(name) == 3, "CSR name must have two #s"
            return "%s%d%s%d%s" % (name[0], self.block, name[1], self.index, name[2])
        elif self.index != -1:
            name = self.csr.name.split("#")
            assert len(name) == 2, "CSR name must have one #"
            return "%s%d%s" % (name[0], self.index, name[1])
        else:
            name = self.csr.name.split("#")
            assert len(name) == 1, "CSR name must not have a #"
            return name[0]

    def is_W1C_safe(self):
        for bit in self.csr.fields:
            field = self.csr.fields[bit]
            if (not field.type in ["R/W1C", "RO", "RAZ"]) and not field.name.startswith("reserved"):
                return False
        return True

#
# This function creates a name lookup dictionary that converts a specific
# CSR instance name into a CSR instance object
# dict["gmx0_rx001_ifg"] = CsrInstance(CSR("gmx#_rx#_ifg"), 1, 0)
#
def buildCsrByName(list):
    dict = {}
    for csr in list:
        for name, address, index, block in csr["s"].iterateAddresses():
            name = name.lower()
            assert not name in dict, "Duplicate name in CSR list"
            dict[name] = CsrInstance(csr["s"], index, block)
    return dict

#
#
#
class ErrorTreeNode:
    def __init__(self, group, status_csr, enable_csr):
        assert (group == None) or isinstance(group, StringType)
        assert isinstance(status_csr, CsrInstance), type(status_csr)
        assert (enable_csr == None) or isinstance(enable_csr, CsrInstance), type(enable_csr)
        self.group = group
        self.status_csr = status_csr
        self.enable_csr = enable_csr
        self.bits = {}

    def addChild(self, status_bit, enable_bit, node):
        assert isinstance(status_bit, StringType)
        assert (enable_bit == None) or isinstance(enable_bit, StringType)
        assert (node == None) or isinstance(node, ErrorTreeNode)
        if "[" in status_bit:
            assert status_bit[-1] == "]", "Brackets must be last on status bit"
            parts = status_bit.split("[")
            assert len(parts) == 2, "Only expect one '['"
            field_name = parts[0]
            sb = self.status_csr.csr.getField(field_name)
            b = int(parts[1][0:-1])
            assert (b >= 0) and (b < (sb.stop_bit - sb.start_bit + 1)), "Bit index outside of field width"
        else:
            sb = self.status_csr.csr.getField(status_bit)
            assert (not node) or (sb.start_bit == sb.stop_bit), "Parent fields must be 1 bit wide"
        if node:
            assert sb.type == "RO", "Parent fields must be RO - " + sb.type
        else:
            assert sb.type == "R/W1C", "Error bits must be R/W1C - " + sb.type
            assert self.status_csr.is_W1C_safe()
        if enable_bit:
            eb = self.enable_csr.csr.getField(enable_bit)
            assert eb.type == "R/W", "Enable bits must be R/W - " + eb.type
            # require the enable to be the same with as the status bit or
            # exactly one bit wide
            assert (eb.start_bit == eb.stop_bit) or (eb.stop_bit - eb.start_bit == sb.stop_bit - sb.start_bit)
        if node:
            if status_bit in self.bits:
                assert not node in self.bits[status_bit][1]
                assert self.bits[status_bit][0] == enable_bit, "All status bits must have the same enable"
                self.bits[status_bit][1].append(node)
            else:
                self.bits[status_bit] = (enable_bit, [node])
        else:
            if status_bit in self.bits:
                assert self.bits[status_bit][0] == enable_bit, "All status bits must have the same enable"
            else:
                self.bits[status_bit] = (enable_bit, None)

    def addBit(self, status_bit, enable_bit):
        self.addChild(status_bit, enable_bit, None)

    def writeAbstract(self, out, indent=""):
        assert len(self.bits) != 0, "Nodes must have at least one child or error bit"
        status_name = self.status_csr.addressName()
        if self.enable_csr:
            enable_name = self.enable_csr.addressName()
        else:
            enable_name = "none"
        out.write(indent + "%s/%s [\n" % (status_name, enable_name))
        indent = indent + "    "
        for sbit in sorted(self.bits.keys()):
            ebit = self.bits[sbit][0]
            children = self.bits[sbit][1]
            if children:
                out.write(indent + "%s/%s ->\n" % (sbit, ebit))
                for child in children:
                    child.writeAbstract(out, indent + "    ")
            else:
                out.write(indent + "%s/%s\n" % (sbit, ebit))
        indent = indent[0:-4]
        out.write(indent + "]\n")

    def writeCheck(self, out, indent=""):
        assert len(self.bits) != 0, "Nodes must have at least one child or error bit"
        status_name = self.status_csr.addressName()
        if self.enable_csr:
            enable_name = self.enable_csr.addressName()
        else:
            enable_name = "none"
        #out.write(indent + "/* Enable is BDK_%s */\n" % enable_name)
        out.write(indent + "BDK_CSR_INIT(c, BDK_%s);\n" % status_name)
        for sbit in sorted(self.bits.keys()):
            children = self.bits[sbit][1]
            if children:
                out.write(indent + "if (c.s.%s)\n" % sbit)
                out.write(indent + "{\n")
                for child in children:
                    if child.group and child.group != self.group:
                        out.write(indent + "    check_%s() /* %s */\n" % (child.group, child.status_csr.addressName()))
                    else:
                        if len(children) > 1:
                            indent = indent + "    "
                            out.write(indent + "{\n")
                        child.writeCheck(out, indent + "    ")
                        if len(children) > 1:
                            out.write(indent + "}\n")
                            indent = indent[0:-4]
                out.write(indent + "}\n")
            else:
                out.write(indent + "CHECK_ERROR(BDK_%s, %s);\n" % (status_name, sbit))

    def writeEnable(self, out, indent=""):
        assert len(self.bits) != 0, "Nodes must have at least one child or error bit"
        status_name = self.status_csr.addressName()
        if self.enable_csr:
            enable_name = self.enable_csr.addressName()
            out.write(indent + "BDK_CSR_MODIFY(c, BDK_%s,\n" % enable_name)
        for sbit in sorted(self.bits.keys()):
            ebit = self.bits[sbit][0]
            if ebit:
                out.write(indent + "    c.s.%s = -1;\n" % ebit)
        if self.enable_csr:
            out.write(indent + ");\n")
        for sbit in sorted(self.bits.keys()):
            children = self.bits[sbit][1]
            if children:
                for child in children:
                    if child.enable_csr and child.group and child.group != self.group:
                        out.write(indent + "    enable_%s() /* %s */\n" % (child.group, child.enable_csr.addressName()))
                    else:
                        child.writeEnable(out, indent + "    ")

    def findGroups(self, groups):
        if self.group:
            if not self.group in groups:
                groups[self.group] = [self]
            elif not self in groups[self.group]:
                groups[self.group].append(self)
        for bit in self.bits:
            nodes = self.bits[bit][1]
            if nodes:
                for node in nodes:
                    node.findGroups(groups)

#
# An instance of the ErrorTree class represents all registers and their
# parents for a specific chip.
#
class ErrorTree:
    def __init__(self):
        root_csr = csr.Csr(["root"], "RSL", [])
        root_csr.addField(csr.CsrField(0L, 0L, "root", "RO", 0L, 0L, []))
        root_csr.addField(csr.CsrField(1L, 1L, "root2", "RO", 0L, 0L, []))
        root_csr.addField(csr.CsrField(2L, 2L, "root3", "RO", 0L, 0L, []))
        self.allNodes = {"root": ErrorTreeNode(None, CsrInstance(root_csr), None)}

    def add(self, treeNode, parent_name, parent_bit):
        assert isinstance(treeNode, ErrorTreeNode)
        assert isinstance(parent_name, StringType)
        assert isinstance(parent_bit, StringType)
        status_name = treeNode.status_csr.instanceName()
        p = self.allNodes[parent_name]
        if p.enable_csr:
            pb = parent_bit.split("[")[0]
            sb = p.status_csr.csr.getField(pb)
            if sb.start_bit in p.enable_csr.csr.fields:
                enable_bit = p.enable_csr.csr.fields[sb.start_bit].name
            else:
                enable_bit = None # FIXME: Should I allow this?
        else:
            enable_bit = None
        p.addChild(parent_bit, enable_bit, treeNode)
        self.allNodes[status_name] = treeNode

    def writeAbstract(self, out):
        root = self.allNodes["root"]
        root.writeAbstract(out)

    def writeCheck(self, out):
        self.writeGroupCheck(out)
        root = self.allNodes["root"]
        root.writeCheck(out)

    def writeEnable(self, out):
        self.writeGroupEnable(out)
        root = self.allNodes["root"]
        root.writeEnable(out)

    def findGroups(self):
        groups = {}
        root = self.allNodes["root"]
        root.findGroups(groups)
        return groups

    def writeGroupCheck(self, out):
        groups = self.findGroups()
        for group in sorted(groups.keys()):
            out.write("\n")
            out.write("static void check_%s(void)\n" % group)
            out.write("{\n")
            for node in groups[group]:
                if len(groups[group]) == 1:
                    node.writeCheck(out, "    ")
                else:
                    out.write("    {\n")
                    node.writeCheck(out, "        ")
                    out.write("    }\n")
            out.write("}\n")

    def writeGroupEnable(self, out):
        groups = self.findGroups()
        for group in sorted(groups.keys()):
            out.write("\n")
            out.write("static void enable_%s(void)\n" % group)
            out.write("{\n")
            for node in groups[group]:
                if len(groups[group]) == 1:
                    node.writeEnable(out, "    ")
                else:
                    out.write("    {\n")
                    node.writeEnable(out, "        ")
                    out.write("    }\n")
            out.write("}\n")

#
#
#
def parseName(name_string, csr_dict, autoFillEmpty):
    parts = name_string.split(":")
    name = parts[0]
    instance = csr_dict[name]
    # Parse the optional bit include/exclude list
    if len(parts) != 1:
        parts = parts[1].split("!")
        if parts[0]:
            includes = parts[0].split(",")
        else:
            includes = []
        if len(parts) != 1:
            excludes = parts[1].split(",")
        else:
            excludes = []
    else:
        includes = []
        excludes = []
    # Change the wildcard include into a complete bit list
    if autoFillEmpty and not includes:
        for bit in instance.csr.fields:
            if instance.csr.fields[bit].type == "R/W1C":
                includes.append(instance.csr.fields[bit].name)
    # Remove the exclude list from the include list
    for e in excludes:
        for i, n in enumerate(includes):
            if n == e:
                del includes[i]
                break
    return (instance, includes)

#
#
#
def processErrorRegistersEntry(errorTree, csr_dict, entry):
    status_csr, status_bits = parseName(entry["status"], csr_dict, True)
    # Convert the enable into a CSR and bit list
    if entry["enable"]:
        enable_csr, enable_bits = parseName(entry["enable"], csr_dict, False)
        if not enable_bits:
            for bit in status_bits:
                sf = status_csr.csr.getField(bit)
                ef = enable_csr.csr.fields[sf.start_bit]
                enable_bits.append(ef.name)
        assert len(enable_bits) == len(status_bits), "Must have an enable for every status bit"
    else:
        enable_csr = None
        enable_bits = None
    # Convert the parent name info into a CSR and bit list
    if isinstance(entry["parent"], StringType):
        entry["parent"] = [entry["parent"]]
    for parent in entry["parent"]:
        parent_name, parent_bit = parent.split(":")
        status_name = status_csr.instanceName()
        if status_name in errorTree.allNodes:
            treeNode = errorTree.allNodes[status_name]
            assert treeNode.group == entry["group"]
            assert treeNode.status_csr == status_csr
            assert treeNode.enable_csr == enable_csr
        else:
            treeNode = ErrorTreeNode(entry["group"], status_csr, enable_csr)
        for i,bit in enumerate(status_bits):
            if enable_csr:
                treeNode.addBit(bit, enable_bits[i])
            else:
                treeNode.addBit(bit, None)
        errorTree.add(treeNode, parent_name, parent_bit)

#
#
#
def write(separate_chip_lists):
    csr_dict = buildCsrByName(separate_chip_lists)
    errorTree = ErrorTree()
    for entry in ERROR_REGISTERS:
        processErrorRegistersEntry(errorTree, csr_dict, entry)
    out = open("bdk-error-report.template", "w")
    out.write('#include <bdk.h>\n')
    out.write('#include "bdk-error-support.h"\n')
    writeCopyrightBanner(out)
    out.write("/**\n")
    out.write(" * @file\n")
    out.write(" *\n")
    out.write(" * Automatically generated error messages.\n")
    out.write(" *\n")
    out.write(" * This file is auto generated. Do not edit.\n")
    out.write(" */\n")
    out.write("\n")
    out.write("/* Abstract tree\n")
    errorTree.writeAbstract(out)
    out.write("*/\n")
    out.write("void bdk_error_check(void)\n")
    out.write("{\n")
    errorTree.writeCheck(out)
    out.write("}\n")
    out.write("void bdk_error_enable(void)\n")
    out.write("{\n")
    errorTree.writeEnable(out)
    out.write("}\n")
    out.close()


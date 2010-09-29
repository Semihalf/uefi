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

G_INTERNAL  = "CVMX_ERROR_GROUP_INTERNAL"
G_ETHERNET  = "CVMX_ERROR_GROUP_ETHERNET"
G_MGMT_PORT = "CVMX_ERROR_GROUP_MGMT_PORT"
G_PCI       = "CVMX_ERROR_GROUP_PCI"
G_SRIO      = "CVMX_ERROR_GROUP_SRIO"
G_USB       = "CVMX_ERROR_GROUP_USB"
G_LMC       = "CVMX_ERROR_GROUP_LMC"

R_NONE      = "__CVMX_ERROR_REGISTER_NONE"
R_IO64      = "CVMX_ERROR_REGISTER_IO64"
R_IO32      = "CVMX_ERROR_REGISTER_IO32"
R_PCI       = "CVMX_ERROR_REGISTER_PCICONFIG"
R_SRIO      = "CVMX_ERROR_REGISTER_SRIOMAINT"

F_ECC_SBIT = "CVMX_ERROR_FLAGS_ECC_SINGLE_BIT"
F_CORRECTABLE = "CVMX_ERROR_FLAGS_CORRECTABLE"

ERROR_REGISTERS = [
    {"status": "ciu_int0_sum0:!mpi,timer,key_zero,ipd_drp,gmx_drp",
     "enable": None,
     "parent": "root:root",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "ciu_int_sum1:!ptp",
     "enable": None,
     "parent": "root:root",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "ciu_block_int",
     "enable": None,
     "parent": "root:root",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "npei_rsl_int_blocks",
     "enable": None,
     "parent": "root:root",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "npi_rsl_int_blocks",
     "enable": None,
     "parent": "root:root",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "agl_gmx_bad_reg:!statovr",
     "enable": None,
     "parent": "rsl:agl",
     "group": G_MGMT_PORT,
     "index": 0},
    {"status":
     "agl_gmx_rx0_int_reg:skperr,ovrerr",
     "enable": "agl_gmx_rx0_int_en",
     "parent": "rsl:agl",
     "group": G_MGMT_PORT,
     "index": 0},
    {"status":
     "agl_gmx_rx1_int_reg:skperr,ovrerr",
     "enable": "agl_gmx_rx1_int_en",
     "parent": "rsl:agl",
     "group": G_MGMT_PORT,
     "index": 1},
    {"status":
     "agl_gmx_tx_int_reg:pko_nxa,undflw",
     "enable": "agl_gmx_tx_int_en",
     "parent": "rsl:agl",
     "group": G_MGMT_PORT,
     "index": 0},
    {"status": "asx0_int_reg",
     "enable": "asx0_int_en",
     "parent": "rsl:asx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status": "asx1_int_reg",
     "enable": "asx1_int_en",
     "parent": "rsl:asx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "dfa_err",
    "enable": None,
    "parent": "rsl:dfa",
    "group": G_INTERNAL,
    "index": 0},
    {"status": "dfa_error",
     "enable": "dfa_intmsk",
     "parent": "rsl:dfa",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "dfm_fnt_stat",
     "enable": "dfm_fnt_iena",
     "parent": "rsl:dfm",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "dfm_int:nxm_wr_err,sec_err,ded_err",
     "enable": "dfm_int_en:intr_nxm_wr_ena,intr_sec_ena,intr_ded_ena",
     "parent": "rsl:dfm",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "dpi_int_reg",
     "enable": "dpi_int_en",
     "parent": "rsl:dpi",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "dpi_pkt_err_rsp",
     "enable": None,
     "parent": "rsl:dpi",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "dpi_req_err_rsp",
     "enable": None,
     "parent": "rsl:dpi",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "dpi_req_err_rst",
     "enable": None,
     "parent": "rsl:dpi",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "fpa_int_sum",
     "enable": "fpa_int_enb",
     "parent": "rsl:fpa",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "gmx0_bad_reg",
     "enable": None,
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status": "gmx1_bad_reg",
     "enable": None,
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status":
     "gmx0_rx000_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx0_rx000_int_en",
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status":
     "gmx0_rx001_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx0_rx001_int_en",
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 1},
    {"status":
     "gmx0_rx002_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx0_rx002_int_en",
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 2},
    {"status":
     "gmx0_rx003_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx0_rx003_int_en",
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 3},
    {"status":
     "gmx1_rx000_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx1_rx000_int_en",
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status":
     "gmx1_rx001_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx1_rx001_int_en",
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 17},
    {"status":
     "gmx1_rx002_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx1_rx002_int_en",
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 18},
    {"status":
     "gmx1_rx003_int_reg:!pause_drp,ifgerr,coldet,falerr,rsverr,pcterr,rcverr,fcserr,jabber,minerr,phy_link,phy_spd,phy_dupx",
     "enable": "gmx1_rx003_int_en",
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 19},
    {"status":
     "gmx0_tx_int_reg:!xscol,xsdef,late_col",
     "enable": "gmx0_tx_int_en",
     "parent": "rsl:gmx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status":
     "gmx1_tx_int_reg:!xscol,xsdef,late_col",
     "enable": "gmx1_tx_int_en",
     "parent": "rsl:gmx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "iob_int_sum",
     "enable": "iob_int_enb",
     "parent": "rsl:iob",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "ipd_int_sum:!pq_add,pq_sub",
     "enable": "ipd_int_enb",
     "parent": "rsl:ipd",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "key_int_sum",
     "enable": "key_int_enb",
     "parent": "rsl:key",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2c_int_reg",
     "enable": "l2c_int_ena",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2c_int_stat:l2tsec,l2dsec",
     "enable": "l2c_int_en",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status": "l2c_int_stat:!l2tsec,l2dsec",
     "enable": "l2c_int_en",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2c_err_tdt0",
     "enable": None,
     "parent": "l2c_int_reg:tad0",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2c_err_ttg0",
     "enable": None,
     "parent": "l2c_int_reg:tad0",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2d_err:sec_err",
     "enable": "l2d_err:sec_intena",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status": "l2d_err:ded_err",
     "enable": "l2d_err:ded_intena",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "l2t_err:sec_err",
     "enable": "l2t_err:sec_intena",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status": "l2t_err:ded_err,lckerr,lckerr2",
     "enable": "l2t_err:ded_intena,lck_intena,lck_intena2",
     "parent": "rsl:l2c",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "lmc0_int:sec_err",
     "enable": "lmc0_int_en:intr_sec_ena",
     "parent": "rsl:lmc0",
     "group": G_LMC,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status":
     "lmc0_int:nxm_wr_err,ded_err",
     "enable": "lmc0_int_en:intr_nxm_wr_ena,intr_ded_ena",
     "parent": "rsl:lmc0",
     "group": G_LMC,
     "index": 0},
    {"status": "lmc1_int:sec_err",
     "enable": "lmc1_int_en:intr_sec_ena",
     "parent": "rsl:lmc1",
     "group": G_LMC,
     "index": 1,
     "flags": [F_ECC_SBIT]},
    {"status": "lmc1_int:nxm_wr_err,ded_err",
     "enable": "lmc1_int_en:intr_nxm_wr_ena,intr_ded_ena",
     "parent": "rsl:lmc1",
     "group": G_LMC,
     "index": 1},
    {"status": "lmc0_mem_cfg0:sec_err",
     "enable": "lmc0_mem_cfg0:intr_sec_ena",
     "parent": "rsl:lmc0",
     "group": G_LMC,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status": "lmc0_mem_cfg0:ded_err",
     "enable": "lmc0_mem_cfg0:intr_ded_ena",
     "parent": "rsl:lmc0",
     "group": G_LMC,
     "index": 0},
    {"status": "lmc1_mem_cfg0:sec_err",
     "enable": "lmc1_mem_cfg0:intr_sec_ena",
     "parent": "rsl:lmc1",
     "group": G_LMC,
     "index": 1,
     "flags": [F_ECC_SBIT]},
    {"status": "lmc1_mem_cfg0:ded_err",
     "enable": "lmc1_mem_cfg0:intr_ded_ena",
     "parent": "rsl:lmc1",
     "group": G_LMC,
     "index": 1},
    {"status": "mio_boot_err",
     "enable": "mio_boot_int",
     "parent": "rsl:mio",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "mio_rst_int",
     "enable": "mio_rst_int_en",
     "parent": "rsl:mio",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "mix0_isr:!orthresh,irthresh,ts",
     "enable": "mix0_intena",
     "parent": "ciu_int0_sum0:mii",
     "group": G_MGMT_PORT,
     "index": 0},
    {"status":
     "mix1_isr:!orthresh,irthresh,ts",
     "enable": "mix1_intena",
     "parent": "ciu_int_sum1:mii1",
     "group": G_MGMT_PORT,
     "index": 1},
    {"status": "ndf_int:!full,empty",
     "enable": "ndf_int_en",
     "parent": "ciu_int_sum1:nand",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "npei_int_sum:c0_ldwn,c0_se,c0_un_b0,c0_un_b1,c0_un_b2,c0_un_bx,c0_un_wf,c0_un_wi,c0_up_b0,c0_up_b1,c0_up_b2,c0_up_bx,c0_up_wf,c0_up_wi,c0_wake",
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_PCI,
     "index": 0},
    # FIXME npei_int_sum:c0_pmei
    {"status": "npei_int_sum:crs0_dr,crs0_er", # These are not in CN56XXp1
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_PCI,
     "index": 0},
    {"status": "npei_int_sum:c1_ldwn,c1_se,c1_un_b0,c1_un_b1,c1_un_b2,c1_un_bx,c1_un_wf,c1_un_wi,c1_up_b0,c1_up_b1,c1_up_b2,c1_up_bx,c1_up_wf,c1_up_wi,c1_wake",
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_PCI,
     "index": 1},
    # FIXME npei_int_sum:c1_pmei
    {"status": "npei_int_sum:crs1_dr,crs1_er", # These are not in CN56XXp1
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_PCI,
     "index": 1},
    {"status": "npei_int_sum:bar0_to,dma0dbo,dma1dbo,dma2dbo,dma3dbo,iob2big,rml_rto,rml_wto",
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "npei_int_sum:dma4dbo",
     "enable": "npei_int_enb2",
     "parent": "rsl:npei",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "npi_int_sum:!dma0fi,dma1fi,dcnt0,dcnt1,dtime0,dtime1",
     "enable": "npi_int_enb",
     "parent": "rsl:npi",
     "group": G_PCI,
     "index": 0},
    #{"status": "pci_cfg01",            "enable": None,                         "parent": None},
    #{"status": "pci_cfg19",            "enable": None,                         "parent": None},
    #{"status": "pci_cfg22",            "enable": None,                         "parent": None},
    #{"status": "pci_cfg57",            "enable": None,                         "parent": None},
    {"status":
     "pci_int_sum2:!dma1_fi,dma0_fi,dtime1,dtime0,dcnt1,dcnt0,ptime3,ptime2,ptime1,ptime0,pcnt3,pcnt2,pcnt1,pcnt0,rsl_int",
     "enable": "pci_int_enb2",
     "parent": "npi_int_sum:pci_rsl",
     "group": G_PCI,
     "index": 0},
    {"status": "pem0_int_sum", # Moved here to be before PCIERC stuff
     "enable": "pem0_int_enb",
     "parent": "rsl:pem0",
     "group": G_PCI,
     "index": 0},
    {"status": "pem1_int_sum", # Moved here to be before PCIERC stuff
     "enable": "pem1_int_enb",
     "parent": "rsl:pem1",
     "group": G_PCI,
     "index": 1},
    #{"status": "pcierc#_cfg007",       "enable": None,                         "parent": None},
    #{"status": "pcierc#_cfg030",       "enable": None,                         "parent": None},
    #{"status": "pcierc#_cfg034",       "enable": None,                         "parent": None},
    #{"status": "pcierc#_cfg036",       "enable": None,                         "parent": None},
    #
    # FIXME: The following registers represent PCIe advanced error reporting.
    # They are disabled right now as they are causing some issues with CN56XX
    # chips on EBH5610. On these boards NPEI_INT_SUM[c*_aeri] is getting set
    # sometimes when the associated PCIe port isn't clocked. This causes
    # PCIERC*_CFG* registers to be read and bus error.
    #
    #{"status": "pcierc0_cfg065",
    # "enable": "pcierc0_cfg066",
    # "parent": "npei_int_sum:c0_aeri",
    # "group": G_PCI,
    # "index": 0},
    #{"status": "pcierc1_cfg065",
    # "enable": "pcierc1_cfg066",
    # "parent": "npei_int_sum:c1_aeri",
    # "group": G_PCI,
    # "index": 1},
    #{"status": "pcierc0_cfg068",
    # "enable": "pcierc0_cfg069",
    # "parent": "npei_int_sum:c0_aeri",
    # "group": G_PCI,
    # "index": 0},
    #{"status": "pcierc1_cfg068",
    # "enable": "pcierc1_cfg069",
    # "parent": "npei_int_sum:c1_aeri",
    # "group": G_PCI,
    # "index": 1},
    #
    #{"status": "pcierc#_cfg076",       "enable": None,                         "parent": None},
    {"status": "pcm0_int_sum:fsyncmissed,fsyncextra,txempty,rxovf",
     "enable": "pcm0_int_ena",
     "parent": "ciu_int0_sum0:pcm",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pcm1_int_sum:fsyncmissed,fsyncextra,txempty,rxovf",
     "enable": "pcm1_int_ena",
     "parent": "ciu_int0_sum0:pcm",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pcm2_int_sum:fsyncmissed,fsyncextra,txempty,rxovf",
     "enable": "pcm2_int_ena",
     "parent": "ciu_int0_sum0:pcm",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pcm3_int_sum:fsyncmissed,fsyncextra,txempty,rxovf",
     "enable": "pcm3_int_ena",
     "parent": "ciu_int0_sum0:pcm",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pcs0_int000_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs0_int000_en_reg",
     "parent": "rsl:asxpcs0",
     "group": G_ETHERNET,
     "index": 0},
    {"status": "pcs0_int001_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs0_int001_en_reg",
     "parent": "rsl:asxpcs0",
     "group": G_ETHERNET,
     "index": 1},
    {"status": "pcs0_int002_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs0_int002_en_reg",
     "parent": "rsl:asxpcs0",
     "group": G_ETHERNET,
     "index": 2},
    {"status": "pcs0_int003_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs0_int003_en_reg",
     "parent": "rsl:asxpcs0",
     "group": G_ETHERNET,
     "index": 3},
    {"status": "pcs1_int000_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs1_int000_en_reg",
     "parent": "rsl:asxpcs1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "pcs1_int001_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs1_int001_en_reg",
     "parent": "rsl:asxpcs1",
     "group": G_ETHERNET,
     "index": 17},
    {"status": "pcs1_int002_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs1_int002_en_reg",
     "parent": "rsl:asxpcs1",
     "group": G_ETHERNET,
     "index": 18},
    {"status": "pcs1_int003_reg:!xmit,dup,rxerr,lnkspd",
     "enable": "pcs1_int003_en_reg",
     "parent": "rsl:asxpcs1",
     "group": G_ETHERNET,
     "index": 19},
    {"status": "pcsx0_int_reg:!bitlckls",
     "enable": "pcsx0_int_en_reg",
     "parent": "rsl:asxpcs0",
     "group": G_ETHERNET,
     "index": 0},
    {"status": "pcsx1_int_reg:!bitlckls",
     "enable": "pcsx1_int_en_reg",
     "parent": "rsl:asxpcs1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "pem0_dbg_info:!rtlpmal",
     "enable": "pem0_dbg_info_en",
     "parent": "pem0_int_sum:exc",
     "group": G_PCI,
     "index": 0},
    {"status": "pem1_dbg_info:!rtlpmal",
     "enable": "pem1_dbg_info_en",
     "parent": "pem1_int_sum:exc",
     "group": G_PCI,
     "index": 1},
    {"status":
     "pesc0_dbg_info:!rtlpmal",
     "enable": "pesc0_dbg_info_en",
     "parent": "npei_int_sum:c0_exc",
     "group": G_PCI,
     "index": 0},
    {"status":
     "pesc1_dbg_info:!rtlpmal",
     "enable": "pesc1_dbg_info_en",
     "parent": "npei_int_sum:c1_exc",
     "group": G_PCI,
     "index": 1},
    {"status":
     "pip_int_reg:!pktdrp,crcerr,bckprs,minerr,maxerr,lenerr",
     "enable": "pip_int_en",
     "parent": "rsl:pip",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pko_reg_error",
     "enable": "pko_reg_int_mask",
     "parent": "rsl:pko",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pow_ecc_err:sbe",
     "enable": "pow_ecc_err:sbe_ie",
     "parent": "rsl:pow",
     "group": G_INTERNAL,
     "index": 0,
     "flags": [F_ECC_SBIT]},
    {"status": "pow_ecc_err:dbe,rpe",
     "enable": "pow_ecc_err:dbe_ie,rpe_ie",
     "parent": "rsl:pow",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "pow_ecc_err:iop", # These are not in CN38XXp2 and CN31XX
     "enable": "pow_ecc_err:iop_ie",
     "parent": "rsl:pow",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "rad_reg_error",
     "enable": "rad_reg_int_mask",
     "parent": "rsl:rad",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "sli_int_sum:!dtime,dcnt,dmafi",
     "enable": "sli_int_enb_ciu",
     "parent": "rsl:sli",
     "group": G_INTERNAL,
     "index": 0},
    {"status":
     "spx0_int_reg:!spf",
     "enable": "spx0_int_msk",
     "parent": "rsl:spx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status":
     "spx1_int_reg:!spf",
     "enable": "spx1_int_msk",
     "parent": "rsl:spx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "srio0_int_reg:!omsg1,omsg0,link_up,link_dwn,soft_rx,soft_tx,mce_tx,wr_done,maint_op,rxbell,bell_err,txbell",
     "enable": "srio0_int_enable",
     "parent": "rsl:srio0",
     "group": G_SRIO,
     "index": 0},
    {"status": "srio1_int_reg:!omsg1,omsg0,link_up,link_dwn,soft_rx,soft_tx,mce_tx,wr_done,maint_op,rxbell,bell_err,txbell",
     "enable": "srio1_int_enable",
     "parent": "rsl:srio1",
     "group": G_SRIO,
     "index": 1},
    #{"status": "sriomaint#_port_0_err_stat","enable": None,                    "parent": "srio#_int_reg:phy_erb"},
    {"status": "stx0_int_reg",
     "enable": "stx0_int_msk",
     "parent": "rsl:spx0",
     "group": G_ETHERNET,
     "index": 0},
    {"status": "stx1_int_reg",
     "enable": "stx1_int_msk",
     "parent": "rsl:spx1",
     "group": G_ETHERNET,
     "index": 16},
    {"status": "tim_reg_error",
     "enable": "tim_reg_int_mask",
     "parent": "rsl:tim",
     "group": G_INTERNAL,
     "index": 0},
    {"status": "uctl0_int_reg",
     "enable": "uctl0_int_ena",
     "parent": "rsl:usb",
     "group": G_USB,
     "index": 0},
    {"status": "usbn0_int_sum",
     "enable": "usbn0_int_enb",
     "parent": "rsl:usb",
     "group": G_USB,
     "index": 0},
    {"status": "usbn1_int_sum",
     "enable": "usbn1_int_enb",
     "parent": "rsl:usb1",
     "group": G_USB,
     "index": 1},
    {"status": "zip_error",
     "enable": "zip_int_mask",
     "parent": "rsl:zip",
     "group": G_INTERNAL,
     "index": 0},
]

#
#
#
class CsrInstance:
    def __init__(self, pcsr, index=-1, block=-1):
        assert isinstance(pcsr, csr.Csr), type(csr)
        self.csr = pcsr
        self.index = index
        self.block = block

    def getType(self):
        if self.csr.address_base & (1<<48):
            if self.csr.getNumBits() == 64:
                return R_IO64
            elif self.csr.getNumBits() == 32:
                return  R_IO32
            else:
                raise Exception("Illegal CSR width %d" % self.csr.getNumBits())
        elif self.csr.name == "root":
            return  R_NONE
        elif self.csr.type.startswith("PCICONFIGRC"):
            return R_PCI
        else:
            raise Exception("Non IO CSR not handled")

    def addressName(self):
        name = self.csr.name.replace("#", "X").upper()
        name = name.replace("CVMX_SLI_", "CVMX_PEXP_SLI_")
        name = name.replace("CVMX_NPEI_", "CVMX_PEXP_NPEI_")
        name = name.replace("CVMX_PCI_", "CVMX_NPI_PCI_")
        if self.block != -1:
            name = "%s(%d,%d)" % (name, self.index, self.block)
        elif self.index != -1:
            name = "%s(%d)" % (name, self.index)
        if self.csr.type.startswith("PCICONFIGRC"):
            name += "|(%sull<<32)" % self.index
        return name

    def dotName(self):
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

    def getMask(self, bit):
        assert isinstance(bit, StringType), type(bit)
        f = self.csr.getField(bit)
        if f.start_bit == f.stop_bit:
            return "1ull<<%d /* %s */" % (f.start_bit, f.name)
        else:
            return "0x%xull<<%d /* %s */" % ((1<<(f.stop_bit-f.start_bit+1))-1, f.start_bit, f.name)

    def is_W1C_safe(self):
        for bit in self.csr.fields:
            field = self.csr.fields[bit]
            if (not field.type in ["R/W1C", "RO", "RAZ"]) and not field.name.startswith("reserved"):
                return False
        return True

#
#
#
def buildCsrByName(list):
    dict = {}
    for csr in list:
        for name, address, index, block in csr.iterateAddresses():
            name = name.lower()
            assert not name in dict, "Duplicate name"
            dict[name] = CsrInstance(csr, index, block)
    return dict

class ErrorTreeBit:
    def __init__(self, status_csr, status_bit, enable_csr, enable_bit, group, group_index, flags):
        assert isinstance(status_csr, CsrInstance), type(status_csr)
        assert isinstance(status_bit, StringType), type(status_bit)
        if enable_csr:
            assert isinstance(enable_csr, CsrInstance), type(enable_csr)
            assert isinstance(enable_bit, StringType), type(enable_bit)
        else:
            assert enable_csr == None
            assert enable_bit == None
        assert isinstance(group, StringType), type(group)
        assert isinstance(group_index, IntType), type(group_index)
        assert isinstance(flags, ListType), type(flags)
        self.status_csr = status_csr
        self.status_bit = status_bit
        self.enable_csr = enable_csr
        self.enable_bit = enable_bit
        self.group = group
        self.group_index = group_index
        self.flags = flags
        assert self.status_bit
        assert self.status_csr.csr.getField(self.status_bit).type == "R/W1C", "Status bit %s[%s] must be R/W1C, was %s" % (self.status_csr.addressName(), self.status_bit, self.status_csr.csr.getField(self.status_bit).type)
        if self.enable_csr:
            assert self.enable_bit
            assert self.enable_csr.csr.getField(self.enable_bit).type == "R/W", "Incorrect enable field type"

    def writeC(self, out, parent_csr, parent_bit):
        assert isinstance(parent_csr, CsrInstance), type(parent_csr)
        assert isinstance(parent_bit, StringType), type(parent_bit)
        status_name = self.status_csr.addressName()
        out.write("    info.reg_type           = %s;\n" % self.status_csr.getType())
        out.write("    info.status_addr        = %s;\n" % status_name)
        out.write("    info.status_mask        = %s;\n" % self.status_csr.getMask(self.status_bit))
        if self.enable_csr:
            out.write("    info.enable_addr        = %s;\n" % self.enable_csr.addressName())
            out.write("    info.enable_mask        = %s;\n" % self.enable_csr.getMask(self.enable_bit))
        else:
            out.write("    info.enable_addr        = 0;\n")
            out.write("    info.enable_mask        = 0;\n")
        if self.flags:
            out.write("    info.flags              = %s;\n" % "|".join(self.flags))
        else:
            out.write("    info.flags              = 0;\n")
        out.write("    info.group              = %s;\n" % self.group)
        out.write("    info.group_index        = %d;\n" % self.group_index)
        out.write("    info.parent.reg_type    = %s;\n" % parent_csr.getType())
        if parent_csr.getType() == R_NONE:
            out.write("    info.parent.status_addr = 0;\n")
            out.write("    info.parent.status_mask = 0;\n")
        else:
            out.write("    info.parent.status_addr = %s;\n" % parent_csr.addressName())
            out.write("    info.parent.status_mask = %s;\n" % parent_csr.getMask(parent_bit))
        if self.status_csr.is_W1C_safe():
            out.write("    info.func               = __cvmx_error_display;\n")
        else:
            func = "__cvmx_error_handle_%s_%s" % (self.status_csr.csr.name.replace("#", "x"). self.status_bit)
            out.write("    info.func               = %s;\n" % func)
        out.write("    info.user_info          = (long)")
        sf = self.status_csr.csr.getField(self.status_bit)
        if sf.description:
            out.write("\n        \"ERROR %s[%s]: %s\\n\"" % (status_name, self.status_bit.upper(), sf.description[0].replace("\#", "#").replace('"', '\\"')))
            for d in sf.description[1:]:
                if d:
                    out.write("\n        \"    %s\\n\"" % d.replace("\#", "#").replace('"', '\\"'))
        else:
            out.write("\n        \"ERROR %s[%s]: Error Bit\\n\"\n" % (status_name, self.status_bit.upper()))
        out.write(";\n")
        out.write("    fail |= cvmx_error_add(&info);\n")
        out.write("\n")

class ErrorTreeBitList:
    def __init__(self, status_csr, enable_csr):
        assert isinstance(status_csr, CsrInstance), type(status_csr)
        if enable_csr:
            assert isinstance(enable_csr, CsrInstance), type(enable_csr)
        self.status_csr = status_csr
        self.enable_csr = enable_csr
        self.bits = []

    def __len__(self):
        return len(self.bits)

    def __iter__(self):
        return self.bits.__iter__()

    def has(self, name):
        assert isinstance(name, StringType), type(name)
        for ebit in self.bits:
            if ebit.status_bit == name:
                return True
        return False

    def add(self, new_bit):
        assert isinstance(new_bit, ErrorTreeBit), type(new_bit)
        assert new_bit.status_csr == self.status_csr
        assert new_bit.enable_csr == self.enable_csr
        for ebit in self.bits:
            assert ebit.status_bit != new_bit.status_bit
            assert ebit.enable_bit != new_bit.status_bit
        if new_bit.enable_csr:
            for ebit in self.bits:
                assert ebit.status_bit != new_bit.enable_bit
                assert ebit.enable_bit != new_bit.enable_bit
        self.bits.append(new_bit)

#
#
#
class ErrorTreeNode:
    def __init__(self, status_csr, enable_csr):
        assert isinstance(status_csr, CsrInstance), type(status_csr)
        if enable_csr:
            assert isinstance(enable_csr, CsrInstance), type(enable_csr)
        self.status_csr = status_csr
        self.bits = ErrorTreeBitList(status_csr, enable_csr)
        self.children = {}

    def addBit(self, errorTreeBit):
        assert isinstance(errorTreeBit, ErrorTreeBit), type(errorTreeBit)
        self.bits.add(errorTreeBit)

    def addChild(self, bit, node):
        assert isinstance(bit, StringType), type(bit)
        assert isinstance(node, ErrorTreeNode), type(node)
        assert not self.bits.has(bit), "Bit can't be a status bit and a parent for another register"
        if not bit in self.children:
            self.children[bit] = []
        assert not node in self.children[bit], "Bug caused adding same tree node twice"
        assert self.status_csr.csr.getField(bit).type == "RO", "Parent bit must be read only"
        self.children[bit].append(node)

    def getDotName(self):
        return self.status_csr.dotName()

    def writeDot(self, out):
        name = self.getDotName()
        label = self.status_csr.addressName()
        label = label.split("|")[0] # Removes PCI port hacks
        for ebit in self.bits:
            label += "|<%s>%s" % (ebit.status_bit, ebit.status_bit)
        for bit in self.children:
            label += "|<%s>%s" % (bit, bit)
        out.write(" *     %s [label=\"%s\"];\n" % (name, label))
        for bit in self.children:
            for child in self.children[bit]:
                child.writeDot(out)
                out.write(" *     %s:%s:e -> %s [label=\"%s\"];\n" % (name, bit, child.getDotName(), bit))
        bits = self.children.keys()
        for i in range(1, len(bits)):
            for j in range(1, len(self.children[bits[i]])):
                c1 = self.children[bits[i]][j-1]
                c2 = self.children[bits[i]][j]
                out.write(" *     %s -> %s [style=invis];\n" % (c1.getDotName(), c2.getDotName()))
            c1 = self.children[bits[i-1]][0]
            c2 = self.children[bits[i]][0]

    def writeC(self, out, parent=None, parent_bit=None):
        status_name = self.status_csr.addressName()
        if parent:
            out.write("    /* %s */\n" % status_name)
        for ebit in self.bits:
            ebit.writeC(out, parent.status_csr, parent_bit)
        if self.children and parent:
            out.write("    info.reg_type           = %s;\n" % self.status_csr.getType())
            out.write("    info.status_addr        = %s;\n" % self.status_csr.addressName())
            out.write("    info.status_mask        = 0;\n")
            out.write("    info.enable_addr        = 0;\n")
            out.write("    info.enable_mask        = 0;\n")
            out.write("    info.flags              = 0;\n")
            out.write("    info.group              = %s;\n" % G_INTERNAL)
            out.write("    info.group_index        = 0;\n")
            if parent.status_csr.getType() == R_NONE:
                out.write("    info.parent.reg_type    = %s;\n" % parent.status_csr.getType())
                out.write("    info.parent.status_addr = 0;\n")
                out.write("    info.parent.status_mask = 0;\n")
            else:
                out.write("    info.parent.reg_type    = %s;\n" % parent.status_csr.getType())
                out.write("    info.parent.status_addr = %s;\n" % parent.status_csr.addressName())
                out.write("    info.parent.status_mask = %s;\n" % parent.status_csr.getMask(parent_bit))
            out.write("    info.func               = __cvmx_error_decode;\n")
            out.write("    info.user_info          = 0;\n")
            out.write("    fail |= cvmx_error_add(&info);\n")
            out.write("\n")
        for bit in self.children:
            for child in self.children[bit]:
                sf = self.status_csr.csr.getField(bit)
                assert sf.start_bit == sf.stop_bit, "Parent bit needs to be one bit"
                child.writeC(out, self, sf.name)

#
# An instance of the ErrorTree class represents all registers and their
# parents for a specific chip.
#
class ErrorTree:
    def __init__(self, name):
        assert isinstance(name, StringType), type(name)
        self.name = name
        root_csr = csr.Csr(["root"], "RSL", [])
        root_csr.addField(csr.CsrField(0L, 0L, "root", "RO", 0L, 0L, []))
        self.allNodes = {"root": ErrorTreeNode(CsrInstance(root_csr), None)}

    def addEmpty(self, status_csr, parent_name, parent_bit):
        assert isinstance(status_csr, CsrInstance), type(status_csr)
        assert isinstance(parent_name, StringType), type(parent_name)
        assert isinstance(parent_bit, StringType), type(parent_bit)
        status_name = status_csr.dotName()
        assert not status_name in self.allNodes
        node = ErrorTreeNode(status_csr, None)
        self.allNodes[status_name] = node
        p = self.allNodes[parent_name]
        p.addChild(parent_bit, node)

    def addBit(self, errorTreeBit, parent_name, parent_bit):
        assert isinstance(errorTreeBit, ErrorTreeBit), type(errorTreeBit)
        assert isinstance(parent_name, StringType), type(parent_name)
        assert isinstance(parent_bit, StringType), type(parent_bit)
        status_name = errorTreeBit.status_csr.dotName()
        if not status_name in self.allNodes:
            node = ErrorTreeNode(errorTreeBit.status_csr, errorTreeBit.enable_csr)
            self.allNodes[status_name] = node
            p = self.allNodes[parent_name]
            p.addChild(parent_bit, node)
        self.allNodes[status_name].addBit(errorTreeBit)

    def writeDot(self, out):
        self.allNodes["root"].writeDot(out)

    def writeC(self, out):
        self.allNodes["root"].writeC(out)

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
    if not entry["status"].split(":")[0] in csr_dict:
        return
    if (errorTree.name in ["cn38xxp2", "cn31xx"]) and (entry["status"] in ["pow_ecc_err:iop"]):
        return
    if (errorTree.name == "cn56xxp1") and (entry["status"] in ["npei_int_sum:crs0_dr,crs0_er", "npei_int_sum:crs1_dr,crs1_er"]):
        return
    if (errorTree.name == "cn52xxp1") and (entry["status"] in ["npei_int_sum:dma4dbo"]):
        return
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
    parent_name, parent_bit = entry["parent"].split(":")
    if parent_name == "rsl":
        for n in ["ciu_block_int", "npei_rsl_int_blocks", "npi_rsl_int_blocks"]:
            if n in csr_dict:
                parent_name = n
                break
    # Chip specific fixups
    if (errorTree.name.startswith("cn3") or errorTree.name.startswith("cn58") or errorTree.name.startswith("cn50")) and (parent_bit == "lmc0"):
        parent_bit = "lmc"
    if (errorTree.name in ("cn63xxp1", "cn63xx", "cn68xx")) and (parent_name == "npei_int_sum"):
        parent_name = "pem%d_int_sum" % entry["index"]
        parent_bit = "aeri"
    #
    if not status_bits:
        assert not enable_csr
        errorTree.addEmpty(status_csr, parent_name, parent_bit)
    for i,bit in enumerate(status_bits):
        if enable_csr:
            errorTreeBit = ErrorTreeBit(status_csr, bit, enable_csr, enable_bits[i], entry["group"], entry["index"], entry.get("flags", []))
        else:
            errorTreeBit = ErrorTreeBit(status_csr, bit, enable_csr, None, entry["group"], entry["index"], entry.get("flags", []))
        errorTree.addBit(errorTreeBit, parent_name, parent_bit)

#
#
#
def write(separate_chip_lists):
    errorTree = {}
    for list in separate_chip_lists:
        csr_dict = buildCsrByName(list)
        errorTree[list.name] = ErrorTree(list.name)
        for entry in ERROR_REGISTERS:
            processErrorRegistersEntry(errorTree[list.name], csr_dict, entry)

    for chip in errorTree:
        out = open("cvmx-error-init-%s.c" % chip, "w")
        writeCopyrightBanner(out)
        out.write("/**\n")
        out.write(" * @file\n")
        out.write(" *\n")
        out.write(" * Automatically generated error messages for %s.\n" % chip)
        out.write(" *\n")
        out.write(" * This file is auto generated. Do not edit.\n")
        out.write(" *\n")
        out.write(" * <hr>$" + "Revision" + "$<hr>\n")
        out.write(" *\n")
        out.write(" * <hr><h2>Error tree for %s</h2>\n" % chip.upper())
        out.write(" * @dot\n")
        out.write(" * digraph %s\n" % chip)
        out.write(" * {\n")
        out.write(" *     rankdir=LR;\n")
        out.write(" *     node [shape=record, width=.1, height=.1, fontsize=8, font=helvitica];\n")
        out.write(" *     edge [fontsize=7, font=helvitica];\n")
        errorTree[chip].writeDot(out)
        out.write(" * }\n")
        out.write(" * @enddot\n")
        out.write(" */\n")
        out.write('#ifdef CVMX_BUILD_FOR_LINUX_KERNEL\n')
        out.write('#include <asm/octeon/cvmx.h>\n')
        out.write('#include <asm/octeon/cvmx-error.h>\n')
        out.write('#include <asm/octeon/cvmx-error-custom.h>\n')
        out.write('#include <asm/octeon/cvmx-csr-typedefs.h>\n')
        out.write('#else\n')
        out.write('#include "cvmx.h"\n')
        out.write('#include "cvmx-error.h"\n')
        out.write('#include "cvmx-error-custom.h"\n')
        out.write('#endif\n')
        out.write("\n")
        out.write("int cvmx_error_initialize_%s(void)\n" % chip)
        out.write("{\n")
        out.write("    cvmx_error_info_t info;\n")
        out.write("    int fail = 0;\n")
        out.write("\n")
        errorTree[chip].writeC(out)
        out.write("    return fail;\n")
        out.write("}\n")
        out.write("\n")
        out.close()

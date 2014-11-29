#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(PCIE);

/* We need to know when global init is complete as the config access
   needs to only block certain addresses after init */
static int pcie_global_init_done[BDK_NUMA_MAX_NODES] = {0,};

/* The ECAM has a bug where accessing a non-existent device causes an
   exception. This is a list of all valid devices */
static const uint32_t INTERNAL_DEVICES[] = {
    PCC_DEV_CON_E_BGX0,
    PCC_DEV_CON_E_BGX1,
    PCC_DEV_CON_E_DAP,
    PCC_DEV_CON_E_DFA,
    PCC_DEV_CON_E_FUSF,
    PCC_DEV_CON_E_GIC,
    PCC_DEV_CON_E_GPIO,
    PCC_DEV_CON_E_GSER0,
    PCC_DEV_CON_E_GSER1,
    PCC_DEV_CON_E_GSER10,
    PCC_DEV_CON_E_GSER11,
    PCC_DEV_CON_E_GSER12,
    PCC_DEV_CON_E_GSER13,
    PCC_DEV_CON_E_GSER2,
    PCC_DEV_CON_E_GSER3,
    PCC_DEV_CON_E_GSER4,
    PCC_DEV_CON_E_GSER5,
    PCC_DEV_CON_E_GSER6,
    PCC_DEV_CON_E_GSER7,
    PCC_DEV_CON_E_GSER8,
    PCC_DEV_CON_E_GSER9,
    PCC_DEV_CON_E_GTI,
    PCC_DEV_CON_E_IOBN0,
    PCC_DEV_CON_E_IOBN1,
    PCC_DEV_CON_E_KEY,
    PCC_DEV_CON_E_L2C,
    PCC_DEV_CON_E_L2C_CBC0,
    PCC_DEV_CON_E_L2C_CBC1,
    PCC_DEV_CON_E_L2C_CBC2,
    PCC_DEV_CON_E_L2C_CBC3,
    PCC_DEV_CON_E_L2C_MCI0,
    PCC_DEV_CON_E_L2C_MCI1,
    PCC_DEV_CON_E_L2C_MCI2,
    PCC_DEV_CON_E_L2C_MCI3,
    PCC_DEV_CON_E_L2C_TAD0,
    PCC_DEV_CON_E_L2C_TAD1,
    PCC_DEV_CON_E_L2C_TAD2,
    PCC_DEV_CON_E_L2C_TAD3,
    PCC_DEV_CON_E_L2C_TAD4,
    PCC_DEV_CON_E_L2C_TAD5,
    PCC_DEV_CON_E_L2C_TAD6,
    PCC_DEV_CON_E_L2C_TAD7,
    PCC_DEV_CON_E_LMC0,
    PCC_DEV_CON_E_LMC1,
    PCC_DEV_CON_E_LMC2,
    PCC_DEV_CON_E_LMC3,
    PCC_DEV_CON_E_MIO_BOOT,
    PCC_DEV_CON_E_MIO_EMM,
    PCC_DEV_CON_E_MIO_FUS,
    PCC_DEV_CON_E_MIO_PTP,
    PCC_DEV_CON_E_MIO_TWS0,
    PCC_DEV_CON_E_MIO_TWS1,
    PCC_DEV_CON_E_MIO_TWS2,
    PCC_DEV_CON_E_MIO_TWS3,
    PCC_DEV_CON_E_MIO_TWS4,
    PCC_DEV_CON_E_MIO_TWS5,
    PCC_DEV_CON_E_MPI,
    PCC_DEV_CON_E_MRML,
    PCC_DEV_CON_E_NCSI,
    PCC_DEV_CON_E_NIC,
    PCC_DEV_CON_E_OCLA0,
    PCC_DEV_CON_E_OCLA1,
    PCC_DEV_CON_E_OCLA2,
    PCC_DEV_CON_E_OCLA3,
    PCC_DEV_CON_E_OCLA4,
    PCC_DEV_CON_E_OCX,
    PCC_DEV_CON_E_PCCBR_DFA,
    PCC_DEV_CON_E_PCCBR_MRML,
    PCC_DEV_CON_E_PCCBR_NIC,
    PCC_DEV_CON_E_PCCBR_RAD,
    PCC_DEV_CON_E_PCCBR_ZIP,
    PCC_DEV_CON_E_PCIERC0,
    PCC_DEV_CON_E_PCIERC1,
    PCC_DEV_CON_E_PCIERC2,
    PCC_DEV_CON_E_PCIERC3,
    PCC_DEV_CON_E_PCIERC4,
    PCC_DEV_CON_E_PCIERC5,
    PCC_DEV_CON_E_PEM0,
    PCC_DEV_CON_E_PEM1,
    PCC_DEV_CON_E_PEM2,
    PCC_DEV_CON_E_PEM3,
    PCC_DEV_CON_E_PEM4,
    PCC_DEV_CON_E_PEM5,
    PCC_DEV_CON_E_RAD,
    PCC_DEV_CON_E_RNM,
    PCC_DEV_CON_E_RST,
    PCC_DEV_CON_E_SATA0,
    PCC_DEV_CON_E_SATA1,
    PCC_DEV_CON_E_SATA10,
    PCC_DEV_CON_E_SATA11,
    PCC_DEV_CON_E_SATA12,
    PCC_DEV_CON_E_SATA13,
    PCC_DEV_CON_E_SATA14,
    PCC_DEV_CON_E_SATA15,
    PCC_DEV_CON_E_SATA2,
    PCC_DEV_CON_E_SATA3,
    PCC_DEV_CON_E_SATA4,
    PCC_DEV_CON_E_SATA5,
    PCC_DEV_CON_E_SATA6,
    PCC_DEV_CON_E_SATA7,
    PCC_DEV_CON_E_SATA8,
    PCC_DEV_CON_E_SATA9,
    PCC_DEV_CON_E_SGP,
    PCC_DEV_CON_E_SLI0,
    PCC_DEV_CON_E_SLI1,
    PCC_DEV_CON_E_SMI,
    PCC_DEV_CON_E_SMMU0,
    PCC_DEV_CON_E_SMMU1,
    PCC_DEV_CON_E_SMMU2,
    PCC_DEV_CON_E_SMMU3,
    PCC_DEV_CON_E_TNS,
    PCC_DEV_CON_E_UAA0,
    PCC_DEV_CON_E_UAA1,
    PCC_DEV_CON_E_USBH0,
    PCC_DEV_CON_E_USBH1,
    PCC_DEV_CON_E_VRM0,
    PCC_DEV_CON_E_VRM1,
    PCC_DEV_CON_E_ZIP,
    0,
};


/**
 * For some errata workaround we need a check to tell if a ECAM access is to a
 * valid intenral device. This function decodes a pcc_dev_con_e enumeration and
 * checks if the supplied arguments match it.
 *
 * @param ecam    ECAM to check
 * @param bus     ECAM bus number
 * @param dev     Device to check
 * @param fn      sub function of device
 * @param dev_con Enumeration to match against
 *
 * @return Non zero if the device matches
 */
static int is_internal(int ecam, int bus, int dev, int fn, enum pcc_dev_con_e dev_con)
{
    union pcc_dev_con_s d = { .u = dev_con };
    return (d.s.ecam == ecam) && (d.s.bus == bus) && (d.s.func == ((dev<<3)|fn));
}

/**
 * This is a companion to the function above to determine if the ECAM device is
 * any of the valid internal devices.
 *
 * @param ecam   ECAM to check
 * @param bus    ECAM bus number
 * @param dev    Device to check
 * @param fn     sub function of device
 *
 * @return Non zero if the device matches
 */
static int is_any_internal(int ecam, int bus, int dev, int fn)
{
    int loc = 0;
    while (INTERNAL_DEVICES[loc])
    {
        if (is_internal(ecam, bus, dev, fn, INTERNAL_DEVICES[loc]))
            return 1;
        loc++;
    }
    return 0;
}

/**
 * This function is called for every Cavium device on the internal ECAMs. Hardware
 * doesn't fully setup the ECAM values for the internal devices, so this code
 * updates various ECAM values to get them ready for enumeration by generic PCIe
 * enumeration code.
 *
 * @param node   Which node to setup
 * @param ecam   Which ecam to setup
 * @param bus    Bus number
 * @param dev    Device number on the ecam
 * @param fn     Sub-function on the ECAM
 */
static void pcie_internal_init_dev(bdk_node_t node, int ecam, int bus, int dev, int fn)
{
    /* Get the current chip ID and pass. We'll need this to fill in version
       information for the device */
    bdk_sys_midr_el1_t midr_el1;
    BDK_MRS(MIDR_EL1, midr_el1.u);

    /* PCCPF_XXX_VSEC_SCTL[RID] with the revision of the chip,
       read from fuses */
    BDK_TRACE(INIT, "        Setting revision\n");
    BDK_CSR_DEFINE(sctl, BDK_PCCPF_XXX_VSEC_SCTL);
    sctl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_VSEC_SCTL);
    sctl.s.rid = midr_el1.s.revision;
    bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_VSEC_SCTL, sctl.u);

    /* PCCPF_XXX_BAR0U, PCCPF_XXX_BAR2U, PCCPF_XXX_SRIOV_BAR0U,
       PCCPF_XXX_SRIOV_BAR2U with the address node number bits, read from
       OCX */
    BDK_TRACE(INIT, "        BAR0L\n");
    bdk_pccpf_xxx_bar0l_t barl;
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR0L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        BAR0U\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR0U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR0U, upper_bits);
    }
    BDK_TRACE(INIT, "        BAR2L\n");
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR2L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        BARUL\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR2U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR2U, upper_bits);
    }
    BDK_TRACE(INIT, "        BAR4L\n");
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR4L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        BAR4U\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR4U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_BAR4U, upper_bits);
    }

    BDK_TRACE(INIT, "        SRIOV BAR0L\n");
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        SRIOV BAR0U\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0U, upper_bits);
    }
    BDK_TRACE(INIT, "        SRIOV BAR2L\n");
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        SRIOV BAR2U\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2U, upper_bits);
    }
    BDK_TRACE(INIT, "        SRIOV BAR4L\n");
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4L);
    if (barl.s.typ == 2)
    {
        BDK_TRACE(INIT, "        SRIOV BAR4U\n");
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, bus, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4U, upper_bits);
    }
}

/**
 * Thunder requires some PCIe initialization that is common between all PCIe
 * ports. Numerous fields in the internal ECAMs need to be set for proper
 * enumeration. This function should be called before any other PCIe function.
 *
 * @param node   Node to initialize
 *
 * @return Zero on success, negative on failure
 */
int bdk_pcie_global_initialize(bdk_node_t node)
{
    /* Go through all the internal devices and set them up */
    int loc = 0;
    BDK_TRACE(INIT, "Enabling internal devices\n");
    while (INTERNAL_DEVICES[loc])
    {
        union pcc_dev_con_s dev = { .u = INTERNAL_DEVICES[loc] };
        BDK_TRACE(INIT, "    Enabling ECAM %d Bus %d Device %d Func %d\n",
            dev.s.ecam, dev.s.bus, dev.s.func >> 3, dev.s.func & 7);
        pcie_internal_init_dev(node, dev.s.ecam, dev.s.bus, dev.s.func >> 3, dev.s.func & 7);
        loc++;
    }

    /* Search MRML for functions and link them into a chain.
       PCCPF_XXX_VSEC_CTL[NXTFN_NS] and PCCPF_XXX_VSEC_SCTL[NXTFN_S] with
       the first function number and next-function number of each RSL
       function, as determined by which devices exist and are enabled
       with ECAM(0..3)_RSL(0..255)_SDIS and ECAM(0..3)_RSL(0..255)_NSDIS */
    int ecam = 0;
    int mrml_bus = 1;
    int last_ari = -1; /* ARI is the old PCIe dev and function combined */
    BDK_TRACE(INIT, "Creating RSL ARI chain\n");
    for (int ari = 0; ari < 256; ari++)
    {
        /* Only visit existing device */
        if (is_any_internal(ecam, mrml_bus, ari >> 3, ari & 7))
            continue;
        if (last_ari != -1)
        {
            BDK_TRACE(INIT, "    Found ARI %d, connect to %d\n", ari, last_ari);
            BDK_CSR_DEFINE(ctl, BDK_PCCPF_XXX_VSEC_CTL);
            ctl.u = bdk_pcie_config_read32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_CTL);
            ctl.s.nxtfn_ns = ari;
            bdk_pcie_config_write32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_CTL, ctl.u);

            BDK_CSR_DEFINE(sctl, BDK_PCCPF_XXX_VSEC_SCTL);
            sctl.u = bdk_pcie_config_read32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_SCTL);
            sctl.s.nxtfn_s = ari;
            bdk_pcie_config_write32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_SCTL, sctl.u);
        }
        else
            BDK_TRACE(INIT, "    Found first ARI %d\n", ari);
        last_ari = ari;
    }
    BDK_TRACE(INIT, "PCIe global init complete\n");
    pcie_global_init_done[node] = 1;
    return 0;
}

/**
 * Return the number of possible PCIe ports on a node. The actual number
 * of configured ports may be less and may also be disjoint.
 *
 * @author creese (8/7/2014)
 * @param node   Node to query
 *
 * @return Number of PCIe ports that are possible
 */
int bdk_pcie_get_num_ports(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 6;
    else
        return 0;
}

/**
 * Return the Core physical base address for PCIe MEM access. Memory is
 * read/written as an offset from this address.
 *
 * @param node      Node to use in a Numa setup
 * @param pcie_port PCIe port the memory is on
 * @param mem_type  Type of memory
 *
 * @return 64bit physical address for read/write
 */
uint64_t bdk_pcie_get_base_address(bdk_node_t node, int pcie_port, bdk_pcie_mem_t mem_type)
{
    /* See __bdk_pcie_sli_initialize() for a description about how SLI regions work */
    /* Ports 0-2 goto SLI0, ports 3-5 goto SLI1 */
    int sli = (pcie_port >= 3) ? 1 : 0;
    int sli_group = pcie_port - sli * 3;
    int region = (sli_group << 6) | (mem_type << 4);
    union sli_s2m_op_s s2m_op;
    s2m_op.u = 0;
    s2m_op.s.io = 1;
    s2m_op.s.node = node;
    s2m_op.s.did_hi = 0x8 + sli;
    s2m_op.s.region = region;
    return s2m_op.u;
}

/**
 * Size of the Mem address region returned at address
 * bdk_pcie_get_base_address()
 *
 * @param node      Node to use in a Numa setup
 * @param pcie_port PCIe port the IO is for
 * @param mem_type  Type of memory
 *
 * @return Size of the Mem window
 */
uint64_t bdk_pcie_get_base_size(bdk_node_t node, int pcie_port, bdk_pcie_mem_t mem_type)
{
    return 1ull << 36;
}

/**
 * @INTERNAL
 * Initialize the RC config space CSRs
 *
 * @param pcie_port PCIe port to initialize
 */
static void __bdk_pcie_rc_initialize_config_space(bdk_node_t node, int pcie_port)
{
    /* Value is recommended in CSR files */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port),
        c.s.cfg_rtry = 32);

    /* Max Payload Size (PCIE*_CFG030[MPS]) */
    /* Max Read Request Size (PCIE*_CFG030[MRRS]) */
    /* Relaxed-order, no-snoop enables (PCIE*_CFG030[RO_EN,NS_EN] */
    /* Error Message Enables (PCIE*_CFG030[CE_EN,NFE_EN,FE_EN,UR_EN]) */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG030(pcie_port),
        c.s.mps = 1; /* Support 256 byte MPS */
        c.s.mrrs = 0x5; /* Support 4KB MRRS */
        c.s.ro_en = 1; /* Enable relaxed order processing. This will allow devices to affect read response ordering */
        c.s.ns_en = 1; /* Enable no snoop processing. Not used */
        c.s.ce_en = 1; /* Correctable error reporting enable. */
        c.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        c.s.fe_en = 1; /* Fatal error reporting enable. */
        c.s.ur_en = 1); /* Unsupported request reporting enable. */

    /* ECRC Generation (PCIE*_CFG070[GE,CE]) */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG070(pcie_port),
        c.s.ge = 1; /* ECRC generation enable. */
        c.s.ce = 1); /* ECRC check enable. */

    /* Access Enables (PCIE*_CFG001[MSAE,ME]) */
        /* ME and MSAE should always be set. */
    /* Interrupt Disable (PCIE*_CFG001[I_DIS]) */
    /* System Error Message Enable (PCIE*_CFG001[SEE]) */
        BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG001(pcie_port),
        c.s.msae = 1; /* Memory space enable. */
        c.s.me = 1; /* Bus master enable. */
        c.s.i_dis = 1; /* INTx assertion disable. */
        c.s.see = 1); /* SERR# enable */

    /* Advanced Error Recovery Message Enables */
    /* (PCIE*_CFG066,PCIE*_CFG067,PCIE*_CFG069) */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG066(pcie_port), 0);
    /* Use BDK_PCIERCX_CFG067 hardware default */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG069(pcie_port), 0);


    /* Active State Power Management (PCIE*_CFG032[ASLPC]) */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG032(pcie_port),
        c.s.aslpc = 0); /* Active state Link PM control. */

    /* Link Width Mode (PCIERCn_CFG452[LME]) - Set during bdk_pcie_rc_initialize_link() */
    /* Primary Bus Number (PCIERCn_CFG006[PBNUM]) */
    /* Use bus numbers as follows:
        64-127: Port 0 on SLI
        128-191: Port 1 on SLI
        192-255: Port 2 on SLI */
    int bus = (pcie_port >= 3) ? pcie_port - 3 : pcie_port;
    bus *= 64;
    bus += 64;
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG006(pcie_port),
        c.s.pbnum = 0;
        c.s.sbnum = bus;
        c.s.subbnum = bus + 63);

    /* Memory-mapped I/O BAR (PCIERCn_CFG008) */
    uint64_t mem_base = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    uint64_t mem_limit = mem_base + bdk_pcie_get_base_size(node, pcie_port, BDK_PCIE_MEM_NORMAL) - 1;
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG008(pcie_port),
        c.s.mb_addr = mem_base >> 16;
        c.s.ml_addr = mem_limit >> 16);

    /* Prefetchable BAR (PCIERCn_CFG009,PCIERCn_CFG010,PCIERCn_CFG011) */
    uint64_t prefetch_base = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_PREFETCH);
    uint64_t prefetch_limit = prefetch_base + bdk_pcie_get_base_size(node, pcie_port, BDK_PCIE_MEM_PREFETCH) - 1;
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG009(pcie_port),
        c.s.lmem_base = prefetch_base >> 16;
        c.s.lmem_limit = prefetch_limit >> 16);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG010(pcie_port),
        c.s.umem_base = prefetch_base >> 32);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG011(pcie_port),
        c.s.umem_limit = prefetch_limit >> 32);

    /* System Error Interrupt Enables (PCIERCn_CFG035[SECEE,SEFEE,SENFEE]) */
    /* PME Interrupt Enables (PCIERCn_CFG035[PMEIE]) */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG035(pcie_port),
        c.s.secee = 1; /* System error on correctable error enable. */
        c.s.sefee = 1; /* System error on fatal error enable. */
        c.s.senfee = 1; /* System error on non-fatal error enable. */
        c.s.pmeie = 1); /* PME interrupt enable. */

    /* Advanced Error Recovery Interrupt Enables */
    /* (PCIERCn_CFG075[CERE,NFERE,FERE]) */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG075(pcie_port),
        c.s.cere = 1; /* Correctable error reporting enable. */
        c.s.nfere = 1; /* Non-fatal error reporting enable. */
        c.s.fere = 1); /* Fatal error reporting enable. */

    /* Make sure the PEM agrees with GSERX about the speed its going to try */
    const int qlm = bdk_qlm_get(node, BDK_IF_PCIE, pcie_port);
    const int gbaud = bdk_qlm_get_gbaud_mhz(node, qlm);
    switch (gbaud)
    {
        case 2500: /* Gen1 */
            BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(pcie_port),
                c.s.md = 0);
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 1);
            break;
        case 5000: /* Gen2 */
            BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(pcie_port),
                c.s.md = 1);
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 2);
            break;
        case 8000: /* Gen3 */
            BDK_CSR_MODIFY(c, node, BDK_PEMX_CFG(pcie_port),
                c.s.md = 2);
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 3);
            break;
        default:
            bdk_error("N%d.PCIe%d: Unexpected rate of %d GBaud on QLM%d\n", node, pcie_port, gbaud, qlm);
            break;
    }

    /* Link Width Mode (PCIERCn_CFG452[LME]) */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(pcie_port));
        BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG452(pcie_port),
            c.s.lme = (pemx_cfg.s.lanes8) ? 0xf : 0x7);
    }
}


/**
 * @INTERNAL
 * Initialize a host mode PCIe gen 2 link. This function takes a PCIe
 * port from reset to a link up state. Software can then begin
 * configuring the rest of the link.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
static int __bdk_pcie_rc_initialize_link(bdk_node_t node, int pcie_port)
{
    /* Simulation doesn't support PCIe host */
    if (bdk_is_simulation())
        return -1;

    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_ON(pcie_port), pemoor, ==, 1, 100000))
    {
        printf("N%d.PCIe%d: PEM not on, skipping.\n", node, pcie_port);
        return -1;
    }

    /* Bring up the link */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port), c.s.lnk_enb = 1);

    /* Wait for the link to come up and link training to be complete */
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    while ((pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1))
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle > bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE))
            return -1;
        bdk_wait_usec(1000);
        pciercx_cfg032.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
    }

    return 0;
}

/**
 * Setup the SLI memory mapped regions to allow access to PCIe by the cores
 * using addresses returned by bdk_pcie_get_base_address().
 *
 * @param node      Node to configure
 * @param pcie_port PCIe port to configure
 */
static void __bdk_pcie_sli_initialize(bdk_node_t node, int pcie_port)
{
    int sli = (pcie_port >= 3) ? 1 : 0;

    /* Setup store merge timer */
    BDK_CSR_MODIFY(c, node, BDK_SLIX_S2M_CTL(sli),
        c.s.max_word = 0;     /* Allow 16 words to combine */
        c.s.timer = 50);      /* Wait up to 50 cycles for more data */

    /* There are 256 regions per SLI. We need four regions per PCIe port to
       support config, IO, normal, and prefetchable regions. The 256 regions
       are shared across PCIe, so we need three groups of these (one group
       for each PCIe). The setup is:
       SLI bit[7:6]: PCIe port, relative to SLI (SLI0 is PCIe 0-2, SLI1 is PCIe 3-5)
       SLI bit[5:4]: Region. See bdk_pcie_mem_t enumeration
       SLI bit[3:0]: Address extension from 32 bits to 36 bits
       */
    int sli_group = pcie_port - 3 * sli;
    for (bdk_pcie_mem_t mem_region = BDK_PCIE_MEM_CONFIG; mem_region <= BDK_PCIE_MEM_IO; mem_region++)
    {
        /* Use top two bits for PCIe port, next two bits for memory region */
        int sli_region = sli_group << 6;
        /* Use next two bits for mem region type */
        sli_region |= mem_region << 4;
        /* Figure out the hardware setting for each region */
        int ctype = 3;
        int nmerge = 1;
        int ordering = 0;
        switch (mem_region)
        {
            case BDK_PCIE_MEM_CONFIG: /* Config space */
                ctype = 1;      /* Config space */
                nmerge = 1;     /* No merging allowed */
                ordering = 0;   /* NO "relaxed ordering" or "no snoop" */
                break;
            case BDK_PCIE_MEM_NORMAL: /* Memory, not prefetchable */
                ctype = 0;      /* Memory space */
                nmerge = 0;     /* Merging allowed */
                ordering = 0;   /* NO "relaxed ordering" or "no snoop" */
                break;
            case BDK_PCIE_MEM_PREFETCH: /* Memory, prefetchable */
                ctype = 0;      /* Memory space */
                nmerge = 0;     /* Merging allowed */
                ordering = 0;   /* Yes "relaxed ordering" and "no snoop" */
                break;
            case BDK_PCIE_MEM_IO: /* IO */
                ctype = 2;      /* I/O space */
                nmerge = 1;     /* No merging allowed */
                ordering = 0;   /* NO "relaxed ordering" or "no snoop" */
                break;
        }
        /* Use the lower order bits to work as an address extension, allowing
           each PCIe port to map a total of 36 bits (32bit each region, 16
           regions) */
        for (int r = sli_region; r < sli_region + 16; r++)
        {
            uint64_t address = 0;
            /* Address only applies to memory space */
            if (ctype == 0)
            {
                /* Calculate the upper bits to match the core physical address. This
                   was the PCIe bus address matches the core physical address. This
                   only works because we assume all devices support 64bit addressing */
                address = bdk_pcie_get_base_address(node, pcie_port, mem_region);
                address >>= 32;
                address += r - sli_region;
            }
            BDK_CSR_MODIFY(c, node, BDK_SLIX_S2M_REGX_ACC(sli, r),
                c.s.ctype = ctype;
                c.s.zero = 0;
                c.s.mac = sli_group;
                c.s.nmerge = nmerge;
                c.s.wtype = ordering;
                c.s.rtype = ordering;
                c.s.ba = address);
        }
    }

    /* Setup MAC control */
    BDK_CSR_MODIFY(c, node, BDK_SLIX_M2S_MACX_CTL(sli, sli_group),
        c.s.ctlp_ro = 1;
        c.s.ptlp_ro = 1;
        c.s.wind_d = 1;
        c.s.bar0_d = 1);
}

/**
 * Initialize a PCIe port for use in host(RC) mode. It doesn't
 * enumerate the bus.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_rc_initialize(bdk_node_t node, int pcie_port)
{
    const int qlm = bdk_qlm_get(node, BDK_IF_PCIE, pcie_port);
    if (qlm < 0)
    {
        bdk_error("N%d.PCIe%d: QLM not in PCIe mode.\n", node, pcie_port);
        return -1;
    }

    /* Make sure we aren't trying to setup a target mode interface in host mode */
    //BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(pcie_port));
    int host_mode = 1; //pemx_cfg.s.hostmd;
    if (!host_mode)
    {
        printf("N%d.PCIe%d: Port in endpoint mode.\n", node, pcie_port);
        return -1;
    }

    /* Bring the PCIe out of reset */
    /* After a chip reset the PCIe will also be in reset. If it isn't,
        most likely someone is trying to init it again without a proper
        PCIe reset */
    BDK_CSR_INIT(soft_prst, node, BDK_RST_SOFT_PRSTX(pcie_port));
    if (!soft_prst.s.soft_prst)
    {
        /* Reset the port */
        BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), 1);
        /* Wait until pcie resets the ports. */
        bdk_wait_usec(2000);
    }
    BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), 0);

    /* Wait for PCIe reset to complete */
    bdk_wait_usec(1000);

    /* Check and make sure PCIe came out of reset. If it doesn't the board
        probably hasn't wired the clocks up and the interface should be
        skipped */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_RST_CTLX(pcie_port), rst_done, ==, 1, 10000))
    {
        if (!bdk_is_simulation())
        {
            printf("N%d.PCIe%d: Stuck in reset, skipping.\n", node, pcie_port);
            return -1;
        }
    }

    /* Check BIST status */
    BDK_CSR_INIT(pemx_bist_status, node, BDK_PEMX_BIST_STATUS(pcie_port));
    if (pemx_bist_status.u)
        bdk_warn("N%d.PCIe%d: BIST FAILED (0x%016lx)\n", node, pcie_port, pemx_bist_status.u);

    /* Initialize the config space CSRs */
    __bdk_pcie_rc_initialize_config_space(node, pcie_port);

    /* Enable gen2 speed selection */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG515(pcie_port),
        c.s.dsc = 1);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link(node, pcie_port))
    {
        if (!bdk_is_simulation())
        {
            printf("N%d.PCIe%d: Link timeout, probably the slot is empty\n", node, pcie_port);
            return -1;
        }
    }

    /* Setup the SLI windows to allow access to this PCIe from the core */
    __bdk_pcie_sli_initialize(node, pcie_port);

    /* Disable BAR0 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR0_START(pcie_port), -1);
    /* Disable BAR1 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR1_START(pcie_port), -1);
    /* Set BAR2 to cover all memory starting at address 0 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR2_START(pcie_port), 0);
    /* Setup BAR attributes */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_BAR_CTL(pcie_port),
        c.s.bar1_siz = 1; /* 64MB BAR1 (not used) */
        c.s.bar2_enb = 1; /* BAR2 is enabled */
        c.s.bar2_cax = 0); /* Cache in L2 */

    /* Display the link status */
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    if (bdk_is_simulation())
        printf("N%d.PCIe%d: Simulation, can't report link speed\n", node, pcie_port);
    else
        printf("N%d.PCIe%d: Link active, %d lanes, speed gen%d\n", node, pcie_port, pciercx_cfg032.s.nlw, pciercx_cfg032.s.ls);

    return 0;
}


/**
 * Shutdown a PCIe port and put it in reset
 *
 * @param pcie_port PCIe port to shutdown
 *
 * @return Zero on success
 */
int bdk_pcie_rc_shutdown(bdk_node_t node, int pcie_port)
{
    /* Wait for all pending operations to complete */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_CPL_LUT_VALID(pcie_port), tag, ==, 0, 2000))
        printf("N%d.PCIe%d: Shutdown timeout\n", node, pcie_port);

    /* Force reset */
    BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), 1);
    return 0;
}

/**
 * @INTERNAL
 * Build a PCIe config space request address for a device
 *
 * @param pcie_port PCIe port to access
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return 64bit IO address
 */
static uint64_t __bdk_pcie_build_config_addr(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    switch (pcie_port)
    {
        case 0 ... 5:
        {
            /* Errata (SLI-22555) ECAM to off-chip PCI misroutes address. Use
               the SLI regions instead of ECAMs for config space access */
            uint64_t address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_CONFIG);
            address += (uint64_t)bus << 24;   /* Bus is bits 31:24 */
            address += dev << 19;   /* device+func is bits 23:16 */
            address += fn << 16;
            address += reg;         /* Offset is bits 11:0 */
            return address;
        }
        case 100 ... 103: /* Use fake ports 100+ to directly access the internal ECAMs */
        {
            int ecam = pcie_port - 100;

            /* Errata (ECAM-22630) ECAM function accesses can fault */
            /* Skip internal devices that don't exists */
            int loc = 0;
            int found = 0;
            while (INTERNAL_DEVICES[loc])
            {
                found = is_internal(ecam, bus, dev, fn, INTERNAL_DEVICES[loc]);
                if (found)
                    break;
                loc++;
            }
            if (!found)
                return 0;

            /* Errata (ECAM-23020) PCIERC transactions fault unless PEM is
               out of reset. The PCIe ports don't work until the PEM is
               turned on. Check for one of the PCIe ports */
            int pem = -1;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC0))
                pem = 0;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC1))
                pem = 1;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC2))
                pem = 2;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC3))
                pem = 3;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC4))
                pem = 4;
            if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_PCIERC5))
                pem = 5;
            if (pem != -1)
            {
                BDK_CSR_INIT(pem_on, node, BDK_PEMX_ON(pem));
                if (!pem_on.s.pemon || !pem_on.s.pemoor)
                    return 0;
            }

            /* Don't check SATA ports during one time init */
            if (pcie_global_init_done[node])
            {
                /* SATA ports should be hidden if they aren't configured at the QLM */
                int qlm = -1;
                if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA0) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA1) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA2) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA3))
                    qlm = 2;
                if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA4) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA5) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA6) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA7))
                    qlm = 3;
                if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA8) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA9) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA10) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA11))
                    qlm = 6;
                if (is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA12) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA13) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA14) ||
                    is_internal(ecam, bus, dev, fn, PCC_DEV_CON_E_SATA15))
                    qlm = 7;
                if (qlm != -1)
                {
                    BDK_CSR_INIT(cfg, node, BDK_GSERX_CFG(qlm));
                    if (!cfg.s.sata)
                        return 0;
                }
            }

            /* Valid ECAM access, build the address */
            union ecam_cfg_addr_s address;
            address.u = 0;
            address.s.io = 1;
            address.s.node = node;
            address.s.did = 0x48 + ecam;
            address.s.setup = 0;
            address.s.bcst = 0;
            address.s.bus = bus;
            address.s.func = dev << 3 | fn;
            address.s.addr = reg;
            return address.u;
        }
    }
    return 0;
}


/**
 * Read 8bits from a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint8_t bdk_pcie_config_read8(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Read8(bus=%d, dev=%d, fn=%d, reg=0x%x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, address);
    uint8_t result;
    if (address)
        result = bdk_read64_uint8(address);
    else
        result = 0xff;
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d:     Result=0x%02x\n", node, pcie_port, result);
    return result;
}


/**
 * Read 16bits from a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint16_t bdk_pcie_config_read16(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Read16(bus=%d, dev=%d, fn=%d, reg=0x%x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, address);
    uint16_t result;
    if (address)
        result = bdk_le16_to_cpu(bdk_read64_uint16(address));
    else
        result = 0xffff;
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d:     Result=0x%04x\n", node, pcie_port, result);
    return result;
}


/**
 * Read 32bits from a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint32_t bdk_pcie_config_read32(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Read32(bus=%d, dev=%d, fn=%d, reg=0x%x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, address);
    uint32_t result;
    if (address)
        result = bdk_le32_to_cpu(bdk_read64_uint32(address));
    else
        result = 0xffffffff;
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d:     Result=0x%08x\n", node, pcie_port, result);
    return result;
}


/**
 * Write 8bits to a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write8(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint8_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Write8(bus=%d, dev=%d, fn=%d, reg=0x%x, val=0x%02x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, val, address);
    if (address)
        bdk_write64_uint8(address, val);
}


/**
 * Write 16bits to a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write16(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint16_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Write16(bus=%d, dev=%d, fn=%d, reg=0x%x, val=0x%04x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, val, address);
    if (address)
        bdk_write64_uint16(address, bdk_cpu_to_le16(val));
}


/**
 * Write 32bits to a Device's config space
 *
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write32(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint32_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(node, pcie_port, bus, dev, fn, reg);
    BDK_TRACE(PCIE_CONFIG, "N%d.PCIe%d: Config Write32(bus=%d, dev=%d, fn=%d, reg=0x%x, val=0x%08x, internal=0x%lx)\n",
        node, pcie_port, bus, dev, fn, reg, val, address);
    if (address)
        bdk_write64_uint32(address, bdk_cpu_to_le32(val));
}


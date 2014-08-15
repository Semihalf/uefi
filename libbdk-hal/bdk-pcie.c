#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(PCIE);

#define MRRS_CN6XXX 3 /* 1024 byte Max Read Request Size */
#define MPS_CN6XXX  0 /* 128 byte Max Packet Size (Limit of most PCs) */


static void pcie_internal_init(bdk_node_t node, int ecam, int dev, int fn)
{
    bdk_sys_midr_el1_t midr_el1;
    BDK_MRS(MIDR_EL1, midr_el1.u);

    /* PCCPF_XXX_VSEC_SCTL[RID] with the revision of the chip,
       read from fuses */
    BDK_CSR_DEFINE(sctl, BDK_PCCPF_XXX_VSEC_SCTL);
    sctl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_VSEC_SCTL);
    sctl.s.rid = midr_el1.s.revision;
    bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_VSEC_SCTL, sctl.u);

    /* PCCPF_XXX_BAR0U, PCCPF_XXX_BAR2U, PCCPF_XXX_SRIOV_BAR0U,
       PCCPF_XXX_SRIOV_BAR2U with the address node number bits, read from
       OCX */
    bdk_pccpf_xxx_bar0l_t barl;
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR0L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR0U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR0U, upper_bits);
    }
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR2L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR2U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR2U, upper_bits);
    }
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR4L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR4U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_BAR4U, upper_bits);
    }

    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR0U, upper_bits);
    }
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR2U, upper_bits);
    }
    barl.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4L);
    if (barl.s.typ == 2)
    {
        uint32_t upper_bits = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4U);
        upper_bits |= node << (44 - 32);
        bdk_pcie_config_write32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_SRIOV_BAR4U, upper_bits);
    }

    /* ECAM(0..3)_DEV(0..31)_SDIS, ECAM(0..3)_DEV(0..31)_NSDIS,
       ECAM(0..3)_BUS(0..255)_SDIS, ECAM(0..3)_BUS(0..255)_NSDIS,
       ECAM(0..3)_RSL(0..255)_SDIS, ECAM(0..3)_RSL(0..255)_NSDIS with the
       PCC functions to be made secure or hidden from the secure or
       non-secure worlds */
    /* All secure and non-secure access to everything */
    if (!bdk_is_simulation())
    {
        BDK_CSR_WRITE(node, BDK_ECAMX_DEVX_SDIS(ecam, dev), 0);
        BDK_CSR_WRITE(node, BDK_ECAMX_DEVX_NSDIS(ecam, dev), 0);
        for (int bus = 0; bus < 255; bus++)
        {
            BDK_CSR_WRITE(node, BDK_ECAMX_BUSX_SDIS(ecam, bus), 0);
            BDK_CSR_WRITE(node, BDK_ECAMX_BUSX_NSDIS(ecam, bus), 0);
            if (ecam == 0)
            {
                /* Only ECAM0 has RSL */
                BDK_CSR_WRITE(node, BDK_ECAMX_RSLX_SDIS(ecam, bus), 0);
                BDK_CSR_WRITE(node, BDK_ECAMX_RSLX_NSDIS(ecam, bus), 0);
            }

        }
    }

    /* PCCPF_XXX_VSEC_CTL[NXTFN_NS] and PCCPF_XXX_VSEC_SCTL[NXTFN_S] with
       the first function number and next-function number of each RSL
       function, as determined by which devices exist and are enabled
       with ECAM(0..3)_RSL(0..255)_SDIS and ECAM(0..3)_RSL(0..255)_NSDIS */

    /* This only applies to the MRML device. Right now we hard code this
       device location */
    if ((ecam == 0) && (dev == 1))
    {
        /* We need to connect the ARI devices into a linked list. Loop through
           all devices on ECAM 0, BUS 1 looking for MRML devices */
        int mrml_bus = 1;
        int last_ari = 0; /* ARI is the old PCIe dev and function combined */
        for (int ari = 0; ari < 256; ari++)
        {
            BDK_CSR_DEFINE(pccbr_id, BDK_PCCPF_XXX_ID);
            pccbr_id.u = bdk_pcie_config_read32(node, 100 + ecam, mrml_bus, ari >> 3, ari & 7, BDK_PCCPF_XXX_ID);
            if (pccbr_id.s.vendid == PCC_VENDOR_E_CAVIUM)
            {
                BDK_CSR_DEFINE(ctl, BDK_PCCPF_XXX_VSEC_CTL);
                ctl.u = bdk_pcie_config_read32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_CTL);
                ctl.s.nxtfn_ns = ari;
                bdk_pcie_config_write32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_CTL, ctl.u);

                BDK_CSR_DEFINE(sctl, BDK_PCCPF_XXX_VSEC_SCTL);
                sctl.u = bdk_pcie_config_read32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_SCTL);
                sctl.s.nxtfn_s = ari;
                bdk_pcie_config_write32(node, 100 + ecam, mrml_bus, last_ari >> 3, last_ari & 7, BDK_PCCPF_XXX_VSEC_SCTL, sctl.u);
                last_ari = ari;
            }
        }
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
    for (int ecam = 0; ecam < 4; ecam++)
    {
        for (int dev = 0; dev < 32; dev++)
        {
            for (int fn = 0; fn < 8; fn++)
            {
                BDK_CSR_DEFINE(pccbr_id, BDK_PCCPF_XXX_ID);
                pccbr_id.u = bdk_pcie_config_read32(node, 100 + ecam, 0, dev, fn, BDK_PCCPF_XXX_ID);
                if (pccbr_id.s.vendid == PCC_VENDOR_E_CAVIUM)
                    pcie_internal_init(node, ecam, dev, fn);
            }
        }
    }
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
    /* Ports 0-2 goto SLI0, ports 3-5 goto SLI1 */
    int sli = (pcie_port >= 3) ? 1 : 0;
    union sli_s2m_op_s s2m_op;
    s2m_op.u = 0;
    s2m_op.s.io = 1;
    s2m_op.s.node = node;
    s2m_op.s.did_hi = 0x8 + sli;
    s2m_op.s.region = mem_type; /* We might want to group multiple for more space */
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
    /* We might want to group multiple for more space */
    return 1ull << 32;
}

/**
 * @INTERNAL
 * Initialize the RC config space CSRs
 *
 * @param pcie_port PCIe port to initialize
 */
static void __bdk_pcie_rc_initialize_config_space(bdk_node_t node, int pcie_port)
{
    /* Max Payload Size (PCIE*_CFG030[MPS]) */
    /* Max Read Request Size (PCIE*_CFG030[MRRS]) */
    /* Relaxed-order, no-snoop enables (PCIE*_CFG030[RO_EN,NS_EN] */
    /* Error Message Enables (PCIE*_CFG030[CE_EN,NFE_EN,FE_EN,UR_EN]) */
    {
        bdk_pciercx_cfg030_t pciercx_cfg030;
        pciercx_cfg030.u= BDK_CSR_READ(node, BDK_PCIERCX_CFG030(pcie_port));
        pciercx_cfg030.s.mps = MPS_CN6XXX;
        pciercx_cfg030.s.mrrs = MRRS_CN6XXX;
        pciercx_cfg030.s.ro_en = 1; /* Enable relaxed order processing. This will allow devices to affect read response ordering */
        pciercx_cfg030.s.ns_en = 1; /* Enable no snoop processing. Not used */
        pciercx_cfg030.s.ce_en = 1; /* Correctable error reporting enable. */
        pciercx_cfg030.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg030.s.fe_en = 1; /* Fatal error reporting enable. */
        pciercx_cfg030.s.ur_en = 1; /* Unsupported request reporting enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG030(pcie_port), pciercx_cfg030.u);
    }

#if 0 // FIXME
    {
        /* Max Payload Size (DPI_SLI_PRTX_CFG[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (DPI_SLI_PRTX_CFG[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_dpi_sli_prtx_cfg_t prt_cfg;
        prt_cfg.u = BDK_CSR_READ(node, BDK_DPI_SLI_PRTX_CFG(pcie_port));
        prt_cfg.s.mps = MPS_CN6XXX;
        prt_cfg.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(node, BDK_DPI_SLI_PRTX_CFG(pcie_port), prt_cfg.u);
    }
#endif

    /* ECRC Generation (PCIE*_CFG070[GE,CE]) */
    {
        bdk_pciercx_cfg070_t pciercx_cfg070;
        pciercx_cfg070.u= BDK_CSR_READ(node, BDK_PCIERCX_CFG070(pcie_port));
        pciercx_cfg070.s.ge = 1; /* ECRC generation enable. */
        pciercx_cfg070.s.ce = 1; /* ECRC check enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG070(pcie_port), pciercx_cfg070.u);
    }

    /* Access Enables (PCIE*_CFG001[MSAE,ME]) */
        /* ME and MSAE should always be set. */
    /* Interrupt Disable (PCIE*_CFG001[I_DIS]) */
    /* System Error Message Enable (PCIE*_CFG001[SEE]) */
    {
        bdk_pciercx_cfg001_t pciercx_cfg001;
        pciercx_cfg001.u= BDK_CSR_READ(node, BDK_PCIERCX_CFG001(pcie_port));
        pciercx_cfg001.s.msae = 1; /* Memory space enable. */
        pciercx_cfg001.s.me = 1; /* Bus master enable. */
        pciercx_cfg001.s.i_dis = 1; /* INTx assertion disable. */
        pciercx_cfg001.s.see = 1; /* SERR# enable */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG001(pcie_port), pciercx_cfg001.u);
    }


    /* Advanced Error Recovery Message Enables */
    /* (PCIE*_CFG066,PCIE*_CFG067,PCIE*_CFG069) */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG066(pcie_port), 0);
    /* Use BDK_PCIERCX_CFG067 hardware default */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG069(pcie_port), 0);


    /* Active State Power Management (PCIE*_CFG032[ASLPC]) */
    {
        bdk_pciercx_cfg032_t pciercx_cfg032;
        pciercx_cfg032.u= BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
        pciercx_cfg032.s.aslpc = 0; /* Active state Link PM control. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG032(pcie_port), pciercx_cfg032.u);
    }

    /* Link Width Mode (PCIERCn_CFG452[LME]) - Set during bdk_pcie_rc_initialize_link() */
    /* Primary Bus Number (PCIERCn_CFG006[PBNUM]) */
    {
        /* We set the primary bus number to 1 so IDT bridges are happy. They don't like zero */
        bdk_pciercx_cfg006_t pciercx_cfg006;
        pciercx_cfg006.u= 0;
        pciercx_cfg006.s.pbnum = 1;
        pciercx_cfg006.s.sbnum = 1;
        pciercx_cfg006.s.subbnum = 1;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG006(pcie_port), pciercx_cfg006.u);
    }

    /* Memory-mapped I/O BAR (PCIERCn_CFG008) */
    /* Most applications should disable the memory-mapped I/O BAR by */
    /* setting PCIERCn_CFG008[ML_ADDR] < PCIERCn_CFG008[MB_ADDR] */
    {
        bdk_pciercx_cfg008_t pciercx_cfg008;
        pciercx_cfg008.u = 0;
        pciercx_cfg008.s.mb_addr = 0x100;
        pciercx_cfg008.s.ml_addr = 0;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG008(pcie_port), pciercx_cfg008.u);
    }

    /* Prefetchable BAR (PCIERCn_CFG009,PCIERCn_CFG010,PCIERCn_CFG011) */
    /* Most applications should disable the prefetchable BAR by setting */
    /* PCIERCn_CFG011[UMEM_LIMIT],PCIERCn_CFG009[LMEM_LIMIT] < */
    /* PCIERCn_CFG010[UMEM_BASE],PCIERCn_CFG009[LMEM_BASE] */
    {
        bdk_pciercx_cfg009_t pciercx_cfg009;
        bdk_pciercx_cfg010_t pciercx_cfg010;
        bdk_pciercx_cfg011_t pciercx_cfg011;
        pciercx_cfg009.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG009(pcie_port));
        pciercx_cfg010.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG010(pcie_port));
        pciercx_cfg011.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG011(pcie_port));
        pciercx_cfg009.s.lmem_base = 0x100;
        pciercx_cfg009.s.lmem_limit = 0;
        pciercx_cfg010.s.umem_base = 0x100;
        pciercx_cfg011.s.umem_limit = 0;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG009(pcie_port), pciercx_cfg009.u);
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG010(pcie_port), pciercx_cfg010.u);
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG011(pcie_port), pciercx_cfg011.u);
    }

    /* System Error Interrupt Enables (PCIERCn_CFG035[SECEE,SEFEE,SENFEE]) */
    /* PME Interrupt Enables (PCIERCn_CFG035[PMEIE]) */
    {
        bdk_pciercx_cfg035_t pciercx_cfg035;
        pciercx_cfg035.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG035(pcie_port));
        pciercx_cfg035.s.secee = 1; /* System error on correctable error enable. */
        pciercx_cfg035.s.sefee = 1; /* System error on fatal error enable. */
        pciercx_cfg035.s.senfee = 1; /* System error on non-fatal error enable. */
        pciercx_cfg035.s.pmeie = 1; /* PME interrupt enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG035(pcie_port), pciercx_cfg035.u);
    }

    /* Advanced Error Recovery Interrupt Enables */
    /* (PCIERCn_CFG075[CERE,NFERE,FERE]) */
    {
        bdk_pciercx_cfg075_t pciercx_cfg075;
        pciercx_cfg075.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG075(pcie_port));
        pciercx_cfg075.s.cere = 1; /* Correctable error reporting enable. */
        pciercx_cfg075.s.nfere = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg075.s.fere = 1; /* Fatal error reporting enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG075(pcie_port), pciercx_cfg075.u);
    }

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
            bdk_error("PCIe%d: Unexpected rate of %d GBaud on QLM%d\n", pcie_port, gbaud, qlm);
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
    uint64_t start_cycle;
    bdk_pemx_ctl_status_t pem_ctl_status;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_pciercx_cfg448_t pciercx_cfg448;

    /* Simulation doesn't support PCIe host */
    if (bdk_is_simulation())
        return -1;

    /* For CN7XXX we must turn the PEM on */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_ON(pcie_port), pemoor, ==, 1, 100000))
    {
        bdk_dprintf("PCIe: Port %d PEM not on, skipping.\n", pcie_port);
        return -1;
    }

    /* Bring up the link */
    pem_ctl_status.u = BDK_CSR_READ(node, BDK_PEMX_CTL_STATUS(pcie_port));
    pem_ctl_status.s.lnk_enb = 1;
    BDK_CSR_WRITE(node, BDK_PEMX_CTL_STATUS(pcie_port), pem_ctl_status.u);

    /* Wait for the link to come up and link training to be complete */
    start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    do
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle > bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE))
            return -1;
        bdk_wait_usec(1000);
        pciercx_cfg032.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
    } while ((pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1));

    /* Update the Replay Time Limit. Empirically, some PCIe devices take a
        little longer to respond than expected under load. As a workaround for
        this we configure the Replay Time Limit to the value expected for a 512
        byte MPS instead of our actual 256 byte MPS. The numbers below are
        directly from the PCIe spec table 3-4 */
    pciercx_cfg448.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG448(pcie_port));
    switch (pciercx_cfg032.s.nlw)
    {
        case 1: /* 1 lane */
            pciercx_cfg448.s.rtl = 1677;
            break;
        case 2: /* 2 lanes */
            pciercx_cfg448.s.rtl = 867;
            break;
        case 4: /* 4 lanes */
            pciercx_cfg448.s.rtl = 462;
            break;
        case 8: /* 8 lanes */
            pciercx_cfg448.s.rtl = 258;
            break;
    }
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG448(pcie_port), pciercx_cfg448.u);

    return 0;
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
        bdk_error("PCIe%d: QLM not in PCIe mode.\n", pcie_port);
        return -1;
    }

    /* Make sure we aren't trying to setup a target mode interface in host mode */
    //BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(pcie_port));
    int host_mode = 1; //pemx_cfg.s.hostmd;
    if (!host_mode)
    {
        bdk_dprintf("PCIe%d: Port in endpoint mode.\n", pcie_port);
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
        bdk_dprintf("PCIe: Port %d stuck in reset, skipping.\n", pcie_port);
        return -1;
    }

    /* Check BIST status */
    BDK_CSR_INIT(pemx_bist_status, node, BDK_PEMX_BIST_STATUS(pcie_port));
    if (pemx_bist_status.u)
        bdk_dprintf("PCIe: BIST FAILED for port %d (0x%016lx)\n", pcie_port, pemx_bist_status.u);

    /* Initialize the config space CSRs */
    __bdk_pcie_rc_initialize_config_space(node, pcie_port);

    /* Enable gen2 speed selection */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG515(pcie_port),
        c.s.dsc = 1);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link(node, pcie_port))
    {
        bdk_dprintf("PCIe: Link timeout on port %d, probably the slot is empty\n", pcie_port);
        return -1;
    }

#if 0 // FIXME
    /* Store merge control (SLI_MEM_ACCESS_CTL[TIMER,MAX_WORD]) */
    sli_mem_access_ctl.u = BDK_CSR_READ(node, BDK_SLI_MEM_ACCESS_CTL);
    sli_mem_access_ctl.s.max_word = 0;     /* Allow 16 words to combine */
    sli_mem_access_ctl.s.timer = 127;      /* Wait up to 127 cycles for more data */
    BDK_CSR_WRITE(node, BDK_SLI_MEM_ACCESS_CTL, sli_mem_access_ctl.u);

    /* Setup Mem access SubDIDs */
    mem_access_subid.u = 0;
    mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
    mem_access_subid.s.nmerge = 0;  /* Allow merging as it works on CN6XXX. */
    mem_access_subid.s.esr = 1;     /* Endian-swap for Reads. */
    mem_access_subid.s.esw = 1;     /* Endian-swap for Writes. */
    mem_access_subid.s.wtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
    mem_access_subid.s.rtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
    mem_access_subid.s.ba = 0;      /* PCIe Adddress Bits <63:34>. */

    /* Setup mem access 12-15 for port 0, 16-19 for port 1, supplying 36 bits of address space */
    for (i=12 + pcie_port*4; i<16 + pcie_port*4; i++)
    {
        BDK_CSR_WRITE(node, BDK_SLI_MEM_ACCESS_SUBIDX(i), mem_access_subid.u);
        mem_access_subid.s.ba += 1; /* Set each SUBID to extend the addressable range */
    }

    if (1)
    {
        /* Disable the peer to peer forwarding register. This must be setup
            by the OS after it enumerates the bus and assigns addresses to the
            PCIe busses */
        for (i=0; i<4; i++)
        {
            BDK_CSR_WRITE(node, BDK_PEMX_P2P_BARX_START(pcie_port,i), -1);
            BDK_CSR_WRITE(node, BDK_PEMX_P2P_BARX_END(pcie_port,i), -1);
        }
    }

    /* Set Octeon's BAR0 to decode 0-16KB. It overlaps with Bar2 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR0_START(pcie_port), 0);

    /* Set Octeon's BAR2 to decode 0-2^41. Bar0 and Bar1 take precedence
        where they overlap. It also overlaps with the device addresses, so
        make sure the peer to peer forwarding is set right */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR2_START(pcie_port), 0);

    /* Setup BAR2 attributes */
    /* Relaxed Ordering (NPEI_CTL_PORTn[PTLP_RO,CTLP_RO, WAIT_COM]) */
    /* ­ PTLP_RO,CTLP_RO should normally be set (except for debug). */
    /* ­ WAIT_COM=0 will likely work for all applications. */
    /* Load completion relaxed ordering (NPEI_CTL_PORTn[WAITL_COM]) */
    pemx_bar_ctl.u = BDK_CSR_READ(node, BDK_PEMX_BAR_CTL(pcie_port));
    pemx_bar_ctl.s.bar1_siz = 3;  /* 256MB BAR1*/
    pemx_bar_ctl.s.bar2_enb = 1;
    pemx_bar_ctl.s.bar2_esx = 1;
    pemx_bar_ctl.s.bar2_cax = 0;
    BDK_CSR_WRITE(node, BDK_PEMX_BAR_CTL(pcie_port), pemx_bar_ctl.u);
    sli_ctl_portx.u = BDK_CSR_READ(node, BDK_SLI_CTL_PORTX(pcie_port));
    sli_ctl_portx.s.ptlp_ro = 1;
    sli_ctl_portx.s.ctlp_ro = 1;
    sli_ctl_portx.s.wait_com = 0;
    sli_ctl_portx.s.waitl_com = 0;
    BDK_CSR_WRITE(node, BDK_SLI_CTL_PORTX(pcie_port), sli_ctl_portx.u);

    /* BAR1 follows BAR2 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR1_START(pcie_port), BDK_PCIE_BAR1_RC_BASE);

    bar1_index.u = 0;
    bar1_index.s.addr_idx = (BDK_PCIE_BAR1_PHYS_BASE >> 22);
    bar1_index.s.ca = 1;       /* Not Cached */
    bar1_index.s.end_swp = 1;  /* Endian Swap mode */
    bar1_index.s.addr_v = 1;   /* Valid entry */

    for (i = 0; i < 16; i++) {
        BDK_CSR_WRITE(node, BDK_PEMX_BAR1_INDEXX(pcie_port,i), bar1_index.u);
        /* 256MB / 16 >> 22 == 4 */
        bar1_index.s.addr_idx += (((1ull << 28) / 16ull) >> 22);
    }

    /* Value is recommended in CSR files */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port),
        c.s.cfg_rtry = 32);
#endif

    /* Display the link status */
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    bdk_dprintf("PCIe: Port %d link active, %d lanes, speed gen%d\n", pcie_port, pciercx_cfg032.s.nlw, pciercx_cfg032.s.ls);

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
        bdk_dprintf("PCIe: Port %d shutdown timeout\n", pcie_port);

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
static inline uint64_t __bdk_pcie_build_config_addr(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    int ecam = 0;

    switch (pcie_port)
    {
        case 0 ... 2:
            ecam = 1;   /* PCIe RC 0-2 */
            break;
        case 3 ... 5:
            ecam = 3;   /* PCIe RC 3-5 */
            break;
        case 100:
        case 101:
        case 102:
        case 103:
            /* Use fake ports 100+ to directly access the internal ECAMs */
            ecam = pcie_port - 100;
            break;
    }

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
    if (address)
        return bdk_read64_uint8(address);
    else
        return 0xff;
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
    if (address)
        return bdk_le16_to_cpu(bdk_read64_uint16(address));
    else
        return 0xffff;
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
    if (address)
        return bdk_le32_to_cpu(bdk_read64_uint32(address));
    else
        return 0xffffffff;
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
    if (address)
        bdk_write64_uint32(address, bdk_cpu_to_le32(val));
}


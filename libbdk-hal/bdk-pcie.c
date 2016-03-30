#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(PCIE);

/**
 * Return the number of possible PCIe ports on a node. The actual number
 * of configured ports may be less and may also be disjoint.
 *
 * @param node   Node to query
 *
 * @return Number of PCIe ports that are possible
 */
int bdk_pcie_get_num_ports(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 6;
    else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX))
        return 4;
    else if (CAVIUM_IS_MODEL(CAVIUM_CN81XX))
        return 3;
    else
        return 0;
}

/**
 * Given a PCIe port, determine which SLI controls its memory regions
 *
 * @param node      Node for the PCIe port
 * @param pcie_port The PCIe port
 * @param sli       The SLI index is written to this integer pointer
 * @param sli_group The index of the PCIe port on the SLI is returned here. This is a sequencial
 *                  number for each PCIe on an SLI. Use this to index SLI regions.
 */
static void __bdk_pcie_get_sli(bdk_node_t node, int pcie_port, int *sli, int *sli_group)
{
    /* This mapping should be determined by find the SLI number on the
       same ECAM bus as the PCIERC bridge. That is fairly complex, so it is
       hardcoded for now */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        /* Ports 0-2 goto SLI0, ports 3-5 goto SLI1 */
        *sli = (pcie_port >= 3) ? 1 : 0;
        *sli_group = pcie_port - *sli * 3;
        return;
    }
    else if (CAVIUM_IS_MODEL(CAVIUM_CN83XX) || CAVIUM_IS_MODEL(CAVIUM_CN81XX))
    {
        /* Only one SLI */
        *sli = 0;
        *sli_group = pcie_port;
        return;
    }
    else
        bdk_fatal("Unable to determine SLI for PCIe port. Update __bdk_pcie_get_sli()\n");
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
    int sli;
    int sli_group;
    __bdk_pcie_get_sli(node, pcie_port, &sli, &sli_group);
    int region = (sli_group << 6) | (mem_type << 4);
    union bdk_sli_s2m_op_s s2m_op;
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
    int sli;
    int sli_group;
    __bdk_pcie_get_sli(node, pcie_port, &sli, &sli_group);

    /* The reset default for config retries is too short. Set it to 48ms, which
       is what the Octeon SDK team is using. There is no documentation about
       where they got the 48ms number */
    int cfg_retry = 48 * 1000000 / (bdk_clock_get_rate(node, BDK_CLOCK_SCLK) >> 16);
    if (cfg_retry >= 0x10000)
        cfg_retry = 0xfffff;
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port),
        c.s.cfg_rtry = cfg_retry);


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
        0 - 31: Reserved for internal ECAM
        32 - 87: First PCIe on SLI
        88 - 143: Second PCIe on SLI
        144 - 199: Third PCIe on SLI
        200 - 255: Fourth PCIe on SLI
        Start bus = 32 + pcie * 56 */
    const int BUSSES_PER_PCIE = 56;
    int bus = 32 + sli_group * BUSSES_PER_PCIE;
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG006(pcie_port),
        c.s.pbnum = 0;
        c.s.sbnum = bus;
        c.s.subbnum = bus + BUSSES_PER_PCIE - 1);

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
    BDK_CSR_INIT(pem_cfg, node, BDK_PEMX_CFG(pcie_port));
    switch (pem_cfg.s.md)
    {
        case 0: /* Gen 1 */
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 1);
            break;
        case 1: /* Gen 2 */
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 2);
            break;
        case 2: /* Gen 3 */
            /* Set the target link speed */
            BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG040(pcie_port),
                c.s.tls = 3);
            break;
        default:
            bdk_error("N%d.PCIe%d: Unexpected rate of %d\n", node, pcie_port, pem_cfg.s.md);
            break;
    }

    /* Link Width Mode (PCIERCn_CFG452[LME]) */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
    {
        BDK_CSR_INIT(pemx_cfg, node, BDK_PEMX_CFG(pcie_port));
        BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG452(pcie_port),
            c.s.lme = (pemx_cfg.s.lanes8) ? 0xf : 0x7);
    }

    /* Errata PEM-26189 - PEM EQ Preset Removal */
    /* CFG554.PRV default changed from 16'h7ff to 16'h593. Should be
       safe to apply to CN88XX, CN81XX, and CN83XX */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG554(pcie_port),
        c.s.prv = 0x593);

    /* Errata PEM-26189 - Disable the 2ms timer on all chips */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG554(pcie_port),
        c.s.p23td = 1);

    /* Errata PEM-21178 - Change the CFG[089-092] LxUTP and LxDTP defaults.
       Should be safe to apply to CN88XX, CN81XX, and CN83XX */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG089(pcie_port),
        c.s.l0dtp = 0x7;
        c.s.l0utp = 0x7;
        c.s.l1ddtp = 0x7;
        c.s.l1utp = 0x7);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG090(pcie_port),
        c.s.l2dtp = 0x7;
        c.s.l2utp = 0x7;
        c.s.l3dtp = 0x7;
        c.s.l3utp = 0x7);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG091(pcie_port),
        c.s.l4dtp = 0x7;
        c.s.l4utp = 0x7;
        c.s.l5dtp = 0x7;
        c.s.l5utp = 0x7);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG092(pcie_port),
        c.s.l6dtp = 0x7;
        c.s.l6utp = 0x7;
        c.s.l7dtp = 0x7;
        c.s.l7utp = 0x7);

    /* (ECAM-27114) PCIERC has incorrect device code */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG002(pcie_port),
        c.s.sc = 0x4;
        c.s.bcc = 0x6);
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
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        return -1;

    BDK_TRACE(PCIE, "N%d.PCIe%d: Checking the PEM in on\n", node, pcie_port);
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_ON(pcie_port), pemoor, ==, 1, 100000))
    {
        printf("N%d.PCIe%d: PEM not on, skipping.\n", node, pcie_port);
        return -1;
    }

    /* Bring up the link */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Enabling the link\n", node, pcie_port);
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port), c.s.lnk_enb = 1);

    /* Wait for the link to come up and link training to be complete */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Waiting for link\n", node, pcie_port);
    uint64_t start_cycle = bdk_clock_get_count(BDK_CLOCK_TIME);
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    while ((pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1))
    {
        if (bdk_clock_get_count(BDK_CLOCK_TIME) - start_cycle > bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_TIME))
        {
            if (pciercx_cfg032.s.dlla == 0)
                BDK_TRACE(PCIE, "N%d.PCIe%d: Link timeout, Data Link Layer not active(DLLA)\n", node, pcie_port);
            if (pciercx_cfg032.s.lt == 1)
                BDK_TRACE(PCIE, "N%d.PCIe%d: Link timeout, Link training not done(LT)\n", node, pcie_port);
            return -1;
        }
        bdk_wait_usec(1000);
        pciercx_cfg032.u = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
    }
    BDK_TRACE(PCIE, "N%d.PCIe%d: Link is up\n", node, pcie_port);

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
    int sli;
    int sli_group;
    __bdk_pcie_get_sli(node, pcie_port, &sli, &sli_group);

    /* Setup store merge timer */
    BDK_CSR_MODIFY(c, node, BDK_SLIX_S2M_CTL(sli),
        c.s.max_word = 0;     /* Allow 16 words to combine */
        c.s.timer = 50);      /* Wait up to 50 cycles for more data */

    /* There are 256 regions per SLI. We need four regions per PCIe port to
       support config, IO, normal, and prefetchable regions. The 256 regions
       are shared across PCIe, so we need three groups of these (one group
       for each PCIe). The setup is:
       SLI bit[7:6]: PCIe port, relative to SLI (max of 4)
       SLI bit[5:4]: Region. See bdk_pcie_mem_t enumeration
       SLI bit[3:0]: Address extension from 32 bits to 36 bits
       */
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
                nmerge = 1;     /* No merging allowed */
                ordering = 0;   /* NO "relaxed ordering" or "no snoop" */
                break;
            case BDK_PCIE_MEM_PREFETCH: /* Memory, prefetchable */
                ctype = 0;      /* Memory space */
                nmerge = 0;     /* Merging allowed */
                ordering = 1;   /* Yes "relaxed ordering" and "no snoop" */
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
            if (mem_region == BDK_PCIE_MEM_NORMAL)
            {
                /* Normal starts at bus address 0 */
                address = r - sli_region;
            } else if (mem_region == BDK_PCIE_MEM_PREFETCH)
            {
                /* Normal starts at bus address 0x10.0000.0000 */
                address = r - sli_region + 16;
            }
            BDK_CSR_MODIFY(c, node, BDK_SLIX_S2M_REGX_ACC(sli, r),
                c.s.ctype = ctype;
                c.s.zero = 0;
                c.cn81xx.mac = sli_group;
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
    int i;
    bdk_pemx_bar1_indexx_t bar1_idx;

    BDK_CSR_INIT(pemx_on, node, BDK_PEMX_ON(pcie_port));
    if (!pemx_on.s.pemon)
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
        BDK_TRACE(PCIE, "N%d.PCIe%d: Performing PCIe reset\n", node, pcie_port);
        /* Reset the port */
        BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), 1);
        /* Wait until pcie resets the ports. */
        bdk_wait_usec(2000);
    }
    BDK_TRACE(PCIE, "N%d.PCIe%d: Taking port out of reset\n", node, pcie_port);
    BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), 0);

    /* Wait for PCIe reset to complete */
    bdk_wait_usec(1000);

    /* Check and make sure PCIe came out of reset. If it doesn't the board
        probably hasn't wired the clocks up and the interface should be
        skipped */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Waiting for reset to complete\n", node, pcie_port);
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_RST_CTLX(pcie_port), rst_done, ==, 1, 10000))
    {
        if (!bdk_is_platform(BDK_PLATFORM_ASIM))
        {
            printf("N%d.PCIe%d: Stuck in reset, skipping.\n", node, pcie_port);
            return -1;
        }
    }

    /* Check BIST status */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Checking BIST\n", node, pcie_port);
    BDK_CSR_INIT(pemx_bist_status, node, BDK_PEMX_BIST_STATUS(pcie_port));
    if (pemx_bist_status.u)
        bdk_warn("N%d.PCIe%d: BIST FAILED (0x%016lx)\n", node, pcie_port, pemx_bist_status.u);

    /* Initialize the config space CSRs */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Setting up internal config space\n", node, pcie_port);
    __bdk_pcie_rc_initialize_config_space(node, pcie_port);

    /* Enable gen2 speed selection */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Enabling dynamic speed changes\n", node, pcie_port);
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG515(pcie_port),
        c.s.dsc = 1);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link(node, pcie_port))
    {
        if (!bdk_is_platform(BDK_PLATFORM_ASIM))
        {
            printf("N%d.PCIe%d: Link timeout, probably the slot is empty\n", node, pcie_port);
            return -1;
        }
    }

    /* Setup the SLI windows to allow access to this PCIe from the core */
    BDK_TRACE(PCIE, "N%d.PCIe%d: Initializing SLI\n", node, pcie_port);
    __bdk_pcie_sli_initialize(node, pcie_port);

    BDK_TRACE(PCIE, "N%d.PCIe%d: Setting up internal BARs\n", node, pcie_port);
    /* Disable BAR0 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR0_START(pcie_port), -1);
    /* BAR1 Starting at address 0 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR1_START(pcie_port), 0);
    /* Set BAR2 to cover all memory starting at address 0 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR2_START(pcie_port), 0);
    /* Setup BAR attributes */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_BAR_CTL(pcie_port),
        c.s.bar1_siz = 1; /* 64MB BAR1 */
        c.s.bar2_enb = 1; /* BAR2 is enabled */
        c.s.bar2_cax = 0); /* Cache in L2 */

    /* Allow devices that truncate the bus address to 32-bits to reach the GITS_TRANSLATER */
    bar1_idx.u          = 0;
    bar1_idx.s.addr_idx = bdk_numa_get_address(node, BDK_GITS_TRANSLATER) >> 22;
    bar1_idx.s.addr_v   = 1;

    BDK_CSR_WRITE(node, BDK_PEMX_BAR1_INDEXX(pcie_port, 0), bar1_idx.u);

    /* The rest of the windows map linearly to match the BAR2 translation. */
    for (i = 1; i < 16; i++)
    {
        bar1_idx.s.addr_idx = i;
        BDK_CSR_WRITE(node, BDK_PEMX_BAR1_INDEXX(pcie_port, i), bar1_idx.u);
    }

    /* Display the link status */
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    if (bdk_is_platform(BDK_PLATFORM_ASIM))
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
    /* Check that the controller is out of reset */
    BDK_CSR_INIT(rst_ctlx, node, BDK_RST_CTLX(pcie_port));
    if (!rst_ctlx.s.rst_done)
        goto skip_idle_wait;

    /* Check if link is up */
    BDK_CSR_INIT(pciercx_cfg032, node, BDK_PCIERCX_CFG032(pcie_port));
    if ((pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1))
        goto skip_idle_wait;

    /* Wait for all pending operations to complete */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_PEMX_CPL_LUT_VALID(pcie_port), tag, ==, 0, 2000))
        printf("N%d.PCIe%d: Shutdown timeout\n", node, pcie_port);

skip_idle_wait:
    /* Bring down the link */
    BDK_CSR_MODIFY(c, node, BDK_PEMX_CTL_STATUS(pcie_port), c.s.lnk_enb = 0);
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
    int num_pems = bdk_pcie_get_num_ports(node);
    if (pcie_port < num_pems)
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
    else if (pcie_port >= 100)
    {
        bdk_device_t device;
        memset(&device, 0, sizeof(device));
        device.node = node;
        device.ecam = pcie_port - 100;
        device.bus = bus;
        device.dev = dev;
        device.func = fn;
        return __bdk_ecam_build_address(&device, reg);
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

    /* Errata ECAM-22630: CN88XX pass 1.x, except pass 1.0, will return zero
       for non-existent devices instead of ones. We look for this special case
       for 32bit reads for reg=0 so we can scan device properly */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && (reg == 0) && (result == 0))
        result = 0xffffffff;

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

/**
 * Read 64bits from PCIe using a memory transaction
 *
 * @param node      Node to read from
 * @param pcie_port PCIe port to read
 * @param address   PCIe address to read
 *
 * @return Result of the read
 */
uint64_t bdk_pcie_mem_read64(bdk_node_t node, int pcie_port, uint64_t address)
{
    uint64_t base_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    return bdk_read64_uint64(base_address + address);
}

/**
 * Write 64bits to PCIe memory
 *
 * @param node      Node to write to
 * @param pcie_port PCIe port to use
 * @param address   Address to write
 * @param data      Data to write
 */
void bdk_pcie_mem_write64(bdk_node_t node, int pcie_port, uint64_t address, uint64_t data)
{
    uint64_t base_address = bdk_pcie_get_base_address(node, pcie_port, BDK_PCIE_MEM_NORMAL);
    bdk_write64_uint64(base_address + address, data);
}


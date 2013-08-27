#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(PCIE);

#define MRRS_CN5XXX 0 /* 128 byte Max Read Request Size */
#define MPS_CN5XXX  0 /* 128 byte Max Packet Size (Limit of most PCs) */
#define MRRS_CN6XXX 3 /* 1024 byte Max Read Request Size */
#define MPS_CN6XXX  0 /* 128 byte Max Packet Size (Limit of most PCs) */

/**
 * Return the Core virtual base address for PCIe IO access. IOs are
 * read/written as an offset from this address.
 *
 * @param pcie_port PCIe port the IO is for
 *
 * @return 64bit Octeon IO base address for read/write
 */
uint64_t bdk_pcie_get_io_base_address(bdk_node_t node, int pcie_port)
{
    bdk_pcie_address_t pcie_addr;
    pcie_addr.u64 = 0;
    pcie_addr.io.upper = 0;
    pcie_addr.io.io = 1;
    pcie_addr.io.did = 3;
    pcie_addr.io.subdid = 2;
    pcie_addr.io.node = node;
    pcie_addr.io.es = 1;
    pcie_addr.io.port = pcie_port;
    return pcie_addr.u64;
}


/**
 * Size of the IO address region returned at address
 * bdk_pcie_get_io_base_address()
 *
 * @param pcie_port PCIe port the IO is for
 *
 * @return Size of the IO window
 */
uint64_t bdk_pcie_get_io_size(bdk_node_t node, int pcie_port)
{
    return 1ull<<32;
}


/**
 * Return the Core virtual base address for PCIe MEM access. Memory is
 * read/written as an offset from this address.
 *
 * @param pcie_port PCIe port the IO is for
 *
 * @return 64bit Octeon IO base address for read/write
 */
uint64_t bdk_pcie_get_mem_base_address(bdk_node_t node, int pcie_port)
{
    bdk_pcie_address_t pcie_addr;
    pcie_addr.u64 = 0;
    pcie_addr.mem.upper = 0;
    pcie_addr.mem.io = 1;
    pcie_addr.mem.did = 3;
    pcie_addr.mem.subdid = 3 + pcie_port;
    pcie_addr.mem.node = node;
    return pcie_addr.u64;
}


/**
 * Size of the Mem address region returned at address
 * bdk_pcie_get_mem_base_address()
 *
 * @param pcie_port PCIe port the IO is for
 *
 * @return Size of the Mem window
 */
uint64_t bdk_pcie_get_mem_size(bdk_node_t node, int pcie_port)
{
    return 1ull<<36;
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
        pciercx_cfg030.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG030(pcie_port));
        pciercx_cfg030.s.mps = MPS_CN6XXX;
        pciercx_cfg030.s.mrrs = MRRS_CN6XXX;
        pciercx_cfg030.s.ro_en = 1; /* Enable relaxed order processing. This will allow devices to affect read response ordering */
        pciercx_cfg030.s.ns_en = 1; /* Enable no snoop processing. Not used by Octeon */
        pciercx_cfg030.s.ce_en = 1; /* Correctable error reporting enable. */
        pciercx_cfg030.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg030.s.fe_en = 1; /* Fatal error reporting enable. */
        pciercx_cfg030.s.ur_en = 1; /* Unsupported request reporting enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG030(pcie_port), pciercx_cfg030.u32);
    }

    {
        /* Max Payload Size (DPI_SLI_PRTX_CFG[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (DPI_SLI_PRTX_CFG[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_dpi_sli_prtx_cfg_t prt_cfg;
        prt_cfg.u64 = BDK_CSR_READ(node, BDK_DPI_SLI_PRTX_CFG(pcie_port));
        prt_cfg.s.mps = MPS_CN6XXX;
        prt_cfg.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(node, BDK_DPI_SLI_PRTX_CFG(pcie_port), prt_cfg.u64);

        if (!OCTEON_IS_MODEL(OCTEON_CN78XX))
        {
            BDK_CSR_MODIFY(c, node, BDK_SLI_S2M_PORTX_CTL(pcie_port),
                c.cn70xx.mrrs = MRRS_CN6XXX);
        }
    }

    /* ECRC Generation (PCIE*_CFG070[GE,CE]) */
    {
        bdk_pciercx_cfg070_t pciercx_cfg070;
        pciercx_cfg070.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG070(pcie_port));
        pciercx_cfg070.s.ge = 1; /* ECRC generation enable. */
        pciercx_cfg070.s.ce = 1; /* ECRC check enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG070(pcie_port), pciercx_cfg070.u32);
    }

    /* Access Enables (PCIE*_CFG001[MSAE,ME]) */
        /* ME and MSAE should always be set. */
    /* Interrupt Disable (PCIE*_CFG001[I_DIS]) */
    /* System Error Message Enable (PCIE*_CFG001[SEE]) */
    {
        bdk_pciercx_cfg001_t pciercx_cfg001;
        pciercx_cfg001.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG001(pcie_port));
        pciercx_cfg001.s.msae = 1; /* Memory space enable. */
        pciercx_cfg001.s.me = 1; /* Bus master enable. */
        pciercx_cfg001.s.i_dis = 1; /* INTx assertion disable. */
        pciercx_cfg001.s.see = 1; /* SERR# enable */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG001(pcie_port), pciercx_cfg001.u32);
    }


    /* Advanced Error Recovery Message Enables */
    /* (PCIE*_CFG066,PCIE*_CFG067,PCIE*_CFG069) */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG066(pcie_port), 0);
    /* Use BDK_PCIERCX_CFG067 hardware default */
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG069(pcie_port), 0);


    /* Active State Power Management (PCIE*_CFG032[ASLPC]) */
    {
        bdk_pciercx_cfg032_t pciercx_cfg032;
        pciercx_cfg032.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
        pciercx_cfg032.s.aslpc = 0; /* Active state Link PM control. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG032(pcie_port), pciercx_cfg032.u32);
    }

    /* Link Width Mode (PCIERCn_CFG452[LME]) - Set during bdk_pcie_rc_initialize_link() */
    /* Primary Bus Number (PCIERCn_CFG006[PBNUM]) */
    {
        /* We set the primary bus number to 1 so IDT bridges are happy. They don't like zero */
        bdk_pciercx_cfg006_t pciercx_cfg006;
        pciercx_cfg006.u32 = 0;
        pciercx_cfg006.s.pbnum = 1;
        pciercx_cfg006.s.sbnum = 1;
        pciercx_cfg006.s.subbnum = 1;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG006(pcie_port), pciercx_cfg006.u32);
    }

    /* Memory-mapped I/O BAR (PCIERCn_CFG008) */
    /* Most applications should disable the memory-mapped I/O BAR by */
    /* setting PCIERCn_CFG008[ML_ADDR] < PCIERCn_CFG008[MB_ADDR] */
    {
        bdk_pciercx_cfg008_t pciercx_cfg008;
        pciercx_cfg008.u32 = 0;
        pciercx_cfg008.s.mb_addr = 0x100;
        pciercx_cfg008.s.ml_addr = 0;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG008(pcie_port), pciercx_cfg008.u32);
    }

    /* Prefetchable BAR (PCIERCn_CFG009,PCIERCn_CFG010,PCIERCn_CFG011) */
    /* Most applications should disable the prefetchable BAR by setting */
    /* PCIERCn_CFG011[UMEM_LIMIT],PCIERCn_CFG009[LMEM_LIMIT] < */
    /* PCIERCn_CFG010[UMEM_BASE],PCIERCn_CFG009[LMEM_BASE] */
    {
        bdk_pciercx_cfg009_t pciercx_cfg009;
        bdk_pciercx_cfg010_t pciercx_cfg010;
        bdk_pciercx_cfg011_t pciercx_cfg011;
        pciercx_cfg009.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG009(pcie_port));
        pciercx_cfg010.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG010(pcie_port));
        pciercx_cfg011.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG011(pcie_port));
        pciercx_cfg009.s.lmem_base = 0x100;
        pciercx_cfg009.s.lmem_limit = 0;
        pciercx_cfg010.s.umem_base = 0x100;
        pciercx_cfg011.s.umem_limit = 0;
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG009(pcie_port), pciercx_cfg009.u32);
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG010(pcie_port), pciercx_cfg010.u32);
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG011(pcie_port), pciercx_cfg011.u32);
    }

    /* System Error Interrupt Enables (PCIERCn_CFG035[SECEE,SEFEE,SENFEE]) */
    /* PME Interrupt Enables (PCIERCn_CFG035[PMEIE]) */
    {
        bdk_pciercx_cfg035_t pciercx_cfg035;
        pciercx_cfg035.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG035(pcie_port));
        pciercx_cfg035.s.secee = 1; /* System error on correctable error enable. */
        pciercx_cfg035.s.sefee = 1; /* System error on fatal error enable. */
        pciercx_cfg035.s.senfee = 1; /* System error on non-fatal error enable. */
        pciercx_cfg035.s.pmeie = 1; /* PME interrupt enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG035(pcie_port), pciercx_cfg035.u32);
    }

    /* Advanced Error Recovery Interrupt Enables */
    /* (PCIERCn_CFG075[CERE,NFERE,FERE]) */
    {
        bdk_pciercx_cfg075_t pciercx_cfg075;
        pciercx_cfg075.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG075(pcie_port));
        pciercx_cfg075.s.cere = 1; /* Correctable error reporting enable. */
        pciercx_cfg075.s.nfere = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg075.s.fere = 1; /* Fatal error reporting enable. */
        BDK_CSR_WRITE(node, BDK_PCIERCX_CFG075(pcie_port), pciercx_cfg075.u32);
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
static int __bdk_pcie_rc_initialize_link_gen2(bdk_node_t node, int pcie_port)
{
    uint64_t start_cycle;
    bdk_pemx_ctl_status_t pem_ctl_status;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_pciercx_cfg448_t pciercx_cfg448;

    /* Bring up the link */
    pem_ctl_status.u64 = BDK_CSR_READ(node, BDK_PEMX_CTL_STATUS(pcie_port));
    pem_ctl_status.s.lnk_enb = 1;
    BDK_CSR_WRITE(node, BDK_PEMX_CTL_STATUS(pcie_port), pem_ctl_status.u64);

    /* Wait for the link to come up and link training to be complete */
    start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    do
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle > bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE))
            return -1;
        bdk_wait(10000);
        pciercx_cfg032.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
    } while ((pciercx_cfg032.s.dlla == 0) || (pciercx_cfg032.s.lt == 1));

    /* Update the Replay Time Limit. Empirically, some PCIe devices take a
        little longer to respond than expected under load. As a workaround for
        this we configure the Replay Time Limit to the value expected for a 512
        byte MPS instead of our actual 256 byte MPS. The numbers below are
        directly from the PCIe spec table 3-4 */
    pciercx_cfg448.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG448(pcie_port));
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
    BDK_CSR_WRITE(node, BDK_PCIERCX_CFG448(pcie_port), pciercx_cfg448.u32);

    return 0;
}

static int __bdk_pcie_read_soft_prst(bdk_node_t node, int pcie_port)
{
    return BDK_CSR_READ(node, BDK_RST_SOFT_PRSTX(pcie_port));
}

static void __bdk_pcie_write_soft_prst(bdk_node_t node, int pcie_port, int soft_prst)
{
    BDK_CSR_WRITE(node, BDK_RST_SOFT_PRSTX(pcie_port), soft_prst);
}

/**
 * Initialize a PCIe gen 2 port for use in host(RC) mode. It doesn't enumerate
 * the bus.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
static int __bdk_pcie_rc_initialize_gen2(bdk_node_t node, int pcie_port)
{
    int i;
    bdk_rst_ctlx_t rst_ctl;
    bdk_pemx_bar_ctl_t pemx_bar_ctl;
    bdk_pemx_ctl_status_t pemx_ctl_status;
    bdk_pemx_bist_status_t pemx_bist_status;
    bdk_pemx_bist_status2_t pemx_bist_status2;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_sli_ctl_portx_t sli_ctl_portx;
    bdk_sli_mem_access_ctl_t sli_mem_access_ctl;
    bdk_sli_mem_access_subidx_t mem_access_subid;
    bdk_pemx_bar1_indexx_t bar1_index;

    if (bdk_qlm_get(node, BDK_IF_DPI, pcie_port) < 0)
    {
        bdk_error("PCIe%d: QLM not in PCIe mode.\n", pcie_port);
        return -1;
    }

    /* Make sure we aren't trying to setup a target mode interface in host mode */
    rst_ctl.u64 = BDK_CSR_READ(node, BDK_RST_CTLX(pcie_port));
    if (!rst_ctl.s.host_mode)
    {
        bdk_dprintf("PCIe: Port %d in endpoint mode.\n", pcie_port);
        return -1;
    }

    /* Bring the PCIe out of reset */
    /* After a chip reset the PCIe will also be in reset. If it isn't,
        most likely someone is trying to init it again without a proper
        PCIe reset */
    if (__bdk_pcie_read_soft_prst(node, pcie_port) == 0)
    {
        /* Reset the port */
        __bdk_pcie_write_soft_prst(node, pcie_port, 1);
        /* Wait until pcie resets the ports. */
        bdk_wait_usec(2000);
    }
    __bdk_pcie_write_soft_prst(node, pcie_port, 0);

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
    pemx_bist_status.u64 = BDK_CSR_READ(node, BDK_PEMX_BIST_STATUS(pcie_port));
    if (pemx_bist_status.u64)
        bdk_dprintf("PCIe: BIST FAILED for port %d (0x%016lx)\n", pcie_port, pemx_bist_status.u64);
    pemx_bist_status2.u64 = BDK_CSR_READ(node, BDK_PEMX_BIST_STATUS2(pcie_port));
    if (pemx_bist_status2.u64)
        bdk_dprintf("PCIe: BIST2 FAILED for port %d (0x%016lx)\n", pcie_port, pemx_bist_status2.u64);

    /* Initialize the config space CSRs */
    __bdk_pcie_rc_initialize_config_space(node, pcie_port);

    /* Enable gen2 speed selection */
    BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG515(pcie_port),
        c.s.dsc = 1);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link_gen2(node, pcie_port))
    {
        /* Some gen1 devices don't handle the gen 2 training correctly. Disable
            gen2 and try again with only gen1 */
        BDK_CSR_MODIFY(c, node, BDK_PCIERCX_CFG031(pcie_port),
            c.s.mls = 1);
        if (__bdk_pcie_rc_initialize_link_gen2(node, pcie_port))
        {
            bdk_dprintf("PCIe: Link timeout on port %d, probably the slot is empty\n", pcie_port);
            return -1;
        }
    }

    /* Store merge control (SLI_MEM_ACCESS_CTL[TIMER,MAX_WORD]) */
    sli_mem_access_ctl.u64 = BDK_CSR_READ(node, BDK_SLI_MEM_ACCESS_CTL);
    sli_mem_access_ctl.s.max_word = 0;     /* Allow 16 words to combine */
    sli_mem_access_ctl.s.timer = 127;      /* Wait up to 127 cycles for more data */
    BDK_CSR_WRITE(node, BDK_SLI_MEM_ACCESS_CTL, sli_mem_access_ctl.u64);

    /* Setup Mem access SubDIDs */
    mem_access_subid.u64 = 0;
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
        BDK_CSR_WRITE(node, BDK_SLI_MEM_ACCESS_SUBIDX(i), mem_access_subid.u64);
        mem_access_subid.s.ba += 1; /* Set each SUBID to extend the addressable range */
    }

    if (!OCTEON_IS_MODEL(OCTEON_CN70XX))
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
    pemx_bar_ctl.u64 = BDK_CSR_READ(node, BDK_PEMX_BAR_CTL(pcie_port));
    pemx_bar_ctl.s.bar1_siz = 3;  /* 256MB BAR1*/
    pemx_bar_ctl.s.bar2_enb = 1;
    pemx_bar_ctl.s.bar2_esx = 1;
    pemx_bar_ctl.s.bar2_cax = 0;
    BDK_CSR_WRITE(node, BDK_PEMX_BAR_CTL(pcie_port), pemx_bar_ctl.u64);
    sli_ctl_portx.u64 = BDK_CSR_READ(node, BDK_SLI_CTL_PORTX(pcie_port));
    sli_ctl_portx.s.ptlp_ro = 1;
    sli_ctl_portx.s.ctlp_ro = 1;
    sli_ctl_portx.s.wait_com = 0;
    sli_ctl_portx.s.waitl_com = 0;
    BDK_CSR_WRITE(node, BDK_SLI_CTL_PORTX(pcie_port), sli_ctl_portx.u64);

    /* BAR1 follows BAR2 */
    BDK_CSR_WRITE(node, BDK_PEMX_P2N_BAR1_START(pcie_port), BDK_PCIE_BAR1_RC_BASE);

    bar1_index.u64 = 0;
    bar1_index.s.addr_idx = (BDK_PCIE_BAR1_PHYS_BASE >> 22);
    bar1_index.s.ca = 1;       /* Not Cached */
    bar1_index.s.end_swp = 1;  /* Endian Swap mode */
    bar1_index.s.addr_v = 1;   /* Valid entry */

    for (i = 0; i < 16; i++) {
        BDK_CSR_WRITE(node, BDK_PEMX_BAR1_INDEXX(pcie_port,i), bar1_index.u64);
        /* 256MB / 16 >> 22 == 4 */
        bar1_index.s.addr_idx += (((1ull << 28) / 16ull) >> 22);
    }

    /* Allow config retries for 250ms. Count is based off the 5Ghz SERDES
        clock */
    pemx_ctl_status.u64 = BDK_CSR_READ(node, BDK_PEMX_CTL_STATUS(pcie_port));
    pemx_ctl_status.s.cfg_rtry = 250 * 5000000 / 0x10000;
    BDK_CSR_WRITE(node, BDK_PEMX_CTL_STATUS(pcie_port), pemx_ctl_status.u64);

    /* Display the link status */
    pciercx_cfg032.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG032(pcie_port));
    bdk_dprintf("PCIe: Port %d link active, %d lanes, speed gen%d\n", pcie_port, pciercx_cfg032.s.nlw, pciercx_cfg032.s.ls);

    return 0;
}

/**
 * Initialize a PCIe port for use in host(RC) mode. It doesn't enumerate the bus.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_rc_initialize(bdk_node_t node, int pcie_port)
{
    return __bdk_pcie_rc_initialize_gen2(node, pcie_port);
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
    __bdk_pcie_write_soft_prst(node, pcie_port, 1);
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
 * @return 64bit Octeon IO address
 */
static inline uint64_t __bdk_pcie_build_config_addr(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg)
{
    bdk_pcie_address_t pcie_addr;
    bdk_pciercx_cfg006_t pciercx_cfg006;

    pciercx_cfg006.u32 = BDK_CSR_READ(node, BDK_PCIERCX_CFG006(pcie_port));
    if ((bus <= pciercx_cfg006.s.pbnum) && (dev != 0))
        return 0;

    pcie_addr.u64 = 0;
    pcie_addr.config.upper = 2;
    pcie_addr.config.io = 1;
    pcie_addr.config.did = 3;
    pcie_addr.config.subdid = 1;
    pcie_addr.config.node = node;
    pcie_addr.config.es = 1;
    pcie_addr.config.port = pcie_port;
    pcie_addr.config.ty = (bus > pciercx_cfg006.s.pbnum);
    pcie_addr.config.bus = bus;
    pcie_addr.config.dev = dev;
    pcie_addr.config.func = fn;
    pcie_addr.config.reg = reg;
    return pcie_addr.u64;
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


/**
 * Initialize a PCIe port for use in target(EP) mode.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_ep_initialize(bdk_node_t node, int pcie_port)
{
    bdk_rst_ctlx_t rst_ctl;
    rst_ctl.u64 = BDK_CSR_READ(node, BDK_RST_CTLX(pcie_port));
    if (rst_ctl.s.host_mode)
        return -1;

    /* Enable bus master and memory */
    BDK_CSR_WRITE(node, BDK_PCIEEPX_CFG001(pcie_port), 0x6);

    /* Max Payload Size (PCIE*_CFG030[MPS]) */
    /* Max Read Request Size (PCIE*_CFG030[MRRS]) */
    /* Relaxed-order, no-snoop enables (PCIE*_CFG030[RO_EN,NS_EN] */
    /* Error Message Enables (PCIE*_CFG030[CE_EN,NFE_EN,FE_EN,UR_EN]) */
    {
        bdk_pcieepx_cfg030_t pcieepx_cfg030;
        pcieepx_cfg030.u32 = BDK_CSR_READ(node, BDK_PCIEEPX_CFG030(pcie_port));
        pcieepx_cfg030.s.mps = MPS_CN6XXX;
        pcieepx_cfg030.s.mrrs = MRRS_CN6XXX;
        pcieepx_cfg030.s.ro_en = 1; /* Enable relaxed ordering. */
        pcieepx_cfg030.s.ns_en = 1; /* Enable no snoop. */
        pcieepx_cfg030.s.ce_en = 1; /* Correctable error reporting enable. */
        pcieepx_cfg030.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        pcieepx_cfg030.s.fe_en = 1; /* Fatal error reporting enable. */
        pcieepx_cfg030.s.ur_en = 1; /* Unsupported request reporting enable. */
        BDK_CSR_WRITE(node, BDK_PCIEEPX_CFG030(pcie_port), pcieepx_cfg030.u32);
    }

    {
        /* Max Payload Size (DPI_SLI_PRTX_CFG[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (DPI_SLI_PRTX_CFG[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_dpi_sli_prtx_cfg_t prt_cfg;
        prt_cfg.u64 = BDK_CSR_READ(node, BDK_DPI_SLI_PRTX_CFG(pcie_port));
        prt_cfg.s.mps = MPS_CN6XXX;
        prt_cfg.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(node, BDK_DPI_SLI_PRTX_CFG(pcie_port), prt_cfg.u64);

        if (!OCTEON_IS_MODEL(OCTEON_CN78XX))
        {
            BDK_CSR_MODIFY(c, node, BDK_SLI_S2M_PORTX_CTL(pcie_port),
                c.cn70xx.mrrs = MRRS_CN6XXX);
        }
    }

    /* Setup Mem access SubDID 12 to access Host memory */
    {
        bdk_sli_mem_access_subidx_t mem_access_subid;
        mem_access_subid.u64 = 0;
        mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
        mem_access_subid.s.nmerge = 0;  /* Merging is allowed in this window. */
        mem_access_subid.s.esr = 0;     /* Endian-swap for Reads. */
        mem_access_subid.s.esw = 0;     /* Endian-swap for Writes. */
        mem_access_subid.s.wtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
        mem_access_subid.s.rtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
        mem_access_subid.s.ba = 0;      /* PCIe Adddress Bits <63:34>. */
        BDK_CSR_WRITE(node, BDK_SLI_MEM_ACCESS_SUBIDX(12 + pcie_port*4), mem_access_subid.u64);
    }
    return 0;
}


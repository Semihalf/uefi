#include <bdk.h>

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
uint64_t bdk_pcie_get_io_base_address(int pcie_port)
{
    bdk_pcie_address_t pcie_addr;
    pcie_addr.u64 = 0;
    pcie_addr.io.upper = 0;
    pcie_addr.io.io = 1;
    pcie_addr.io.did = 3;
    pcie_addr.io.subdid = 2;
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
uint64_t bdk_pcie_get_io_size(int pcie_port)
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
uint64_t bdk_pcie_get_mem_base_address(int pcie_port)
{
    bdk_pcie_address_t pcie_addr;
    pcie_addr.u64 = 0;
    pcie_addr.mem.upper = 0;
    pcie_addr.mem.io = 1;
    pcie_addr.mem.did = 3;
    pcie_addr.mem.subdid = 3 + pcie_port;
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
uint64_t bdk_pcie_get_mem_size(int pcie_port)
{
    return 1ull<<36;
}


/**
 * @INTERNAL
 * Initialize the RC config space CSRs
 *
 * @param pcie_port PCIe port to initialize
 */
static void __bdk_pcie_rc_initialize_config_space(int pcie_port)
{
    /* Max Payload Size (PCIE*_CFG030[MPS]) */
    /* Max Read Request Size (PCIE*_CFG030[MRRS]) */
    /* Relaxed-order, no-snoop enables (PCIE*_CFG030[RO_EN,NS_EN] */
    /* Error Message Enables (PCIE*_CFG030[CE_EN,NFE_EN,FE_EN,UR_EN]) */
    {
        bdk_pciercx_cfg030_t pciercx_cfg030;
        pciercx_cfg030.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG030(pcie_port));
        if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
        {
            pciercx_cfg030.s.mps = MPS_CN5XXX;
            pciercx_cfg030.s.mrrs = MRRS_CN5XXX;
        }
        else
        {
            pciercx_cfg030.s.mps = MPS_CN6XXX;
            pciercx_cfg030.s.mrrs = MRRS_CN6XXX;
        }
        pciercx_cfg030.s.ro_en = 1; /* Enable relaxed order processing. This will allow devices to affect read response ordering */
        pciercx_cfg030.s.ns_en = 1; /* Enable no snoop processing. Not used by Octeon */
        pciercx_cfg030.s.ce_en = 1; /* Correctable error reporting enable. */
        pciercx_cfg030.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg030.s.fe_en = 1; /* Fatal error reporting enable. */
        pciercx_cfg030.s.ur_en = 1; /* Unsupported request reporting enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG030(pcie_port), pciercx_cfg030.u32);
    }

    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        /* Max Payload Size (NPEI_CTL_STATUS2[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (NPEI_CTL_STATUS2[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_npei_ctl_status2_t npei_ctl_status2;
        npei_ctl_status2.u64 = BDK_CSR_READ(BDK_NPEI_CTL_STATUS2);
        npei_ctl_status2.s.mps = MPS_CN5XXX; /* Max payload size = 128 bytes for best Octeon DMA performance */
        npei_ctl_status2.s.mrrs = MRRS_CN5XXX; /* Max read request size = 128 bytes for best Octeon DMA performance */
        if (pcie_port)
            npei_ctl_status2.s.c1_b1_s = 3; /* Port1 BAR1 Size 256MB */
        else
            npei_ctl_status2.s.c0_b1_s = 3; /* Port0 BAR1 Size 256MB */

        BDK_CSR_WRITE(BDK_NPEI_CTL_STATUS2, npei_ctl_status2.u64);
    }
    else
    {
        /* Max Payload Size (DPI_SLI_PRTX_CFG[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (DPI_SLI_PRTX_CFG[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_dpi_sli_prtx_cfg_t prt_cfg;
        bdk_sli_s2m_portx_ctl_t sli_s2m_portx_ctl;
        prt_cfg.u64 = BDK_CSR_READ(BDK_DPI_SLI_PRTX_CFG(pcie_port));
        prt_cfg.s.mps = MPS_CN6XXX;
        prt_cfg.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(BDK_DPI_SLI_PRTX_CFG(pcie_port), prt_cfg.u64);

        sli_s2m_portx_ctl.u64 = BDK_CSR_READ(BDK_SLI_S2M_PORTX_CTL(pcie_port));
        sli_s2m_portx_ctl.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(BDK_SLI_S2M_PORTX_CTL(pcie_port), sli_s2m_portx_ctl.u64);
    }

    /* ECRC Generation (PCIE*_CFG070[GE,CE]) */
    {
        bdk_pciercx_cfg070_t pciercx_cfg070;
        pciercx_cfg070.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG070(pcie_port));
        pciercx_cfg070.s.ge = 1; /* ECRC generation enable. */
        pciercx_cfg070.s.ce = 1; /* ECRC check enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG070(pcie_port), pciercx_cfg070.u32);
    }

    /* Access Enables (PCIE*_CFG001[MSAE,ME]) */
        /* ME and MSAE should always be set. */
    /* Interrupt Disable (PCIE*_CFG001[I_DIS]) */
    /* System Error Message Enable (PCIE*_CFG001[SEE]) */
    {
        bdk_pciercx_cfg001_t pciercx_cfg001;
        pciercx_cfg001.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG001(pcie_port));
        pciercx_cfg001.s.msae = 1; /* Memory space enable. */
        pciercx_cfg001.s.me = 1; /* Bus master enable. */
        pciercx_cfg001.s.i_dis = 1; /* INTx assertion disable. */
        pciercx_cfg001.s.see = 1; /* SERR# enable */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG001(pcie_port), pciercx_cfg001.u32);
    }


    /* Advanced Error Recovery Message Enables */
    /* (PCIE*_CFG066,PCIE*_CFG067,PCIE*_CFG069) */
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG066(pcie_port), 0);
    /* Use BDK_PCIERCX_CFG067 hardware default */
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG069(pcie_port), 0);


    /* Active State Power Management (PCIE*_CFG032[ASLPC]) */
    {
        bdk_pciercx_cfg032_t pciercx_cfg032;
        pciercx_cfg032.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG032(pcie_port));
        pciercx_cfg032.s.aslpc = 0; /* Active state Link PM control. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG032(pcie_port), pciercx_cfg032.u32);
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
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG006(pcie_port), pciercx_cfg006.u32);
    }

    /* Memory-mapped I/O BAR (PCIERCn_CFG008) */
    /* Most applications should disable the memory-mapped I/O BAR by */
    /* setting PCIERCn_CFG008[ML_ADDR] < PCIERCn_CFG008[MB_ADDR] */
    {
        bdk_pciercx_cfg008_t pciercx_cfg008;
        pciercx_cfg008.u32 = 0;
        pciercx_cfg008.s.mb_addr = 0x100;
        pciercx_cfg008.s.ml_addr = 0;
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG008(pcie_port), pciercx_cfg008.u32);
    }

    /* Prefetchable BAR (PCIERCn_CFG009,PCIERCn_CFG010,PCIERCn_CFG011) */
    /* Most applications should disable the prefetchable BAR by setting */
    /* PCIERCn_CFG011[UMEM_LIMIT],PCIERCn_CFG009[LMEM_LIMIT] < */
    /* PCIERCn_CFG010[UMEM_BASE],PCIERCn_CFG009[LMEM_BASE] */
    {
        bdk_pciercx_cfg009_t pciercx_cfg009;
        bdk_pciercx_cfg010_t pciercx_cfg010;
        bdk_pciercx_cfg011_t pciercx_cfg011;
        pciercx_cfg009.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG009(pcie_port));
        pciercx_cfg010.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG010(pcie_port));
        pciercx_cfg011.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG011(pcie_port));
        pciercx_cfg009.s.lmem_base = 0x100;
        pciercx_cfg009.s.lmem_limit = 0;
        pciercx_cfg010.s.umem_base = 0x100;
        pciercx_cfg011.s.umem_limit = 0;
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG009(pcie_port), pciercx_cfg009.u32);
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG010(pcie_port), pciercx_cfg010.u32);
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG011(pcie_port), pciercx_cfg011.u32);
    }

    /* System Error Interrupt Enables (PCIERCn_CFG035[SECEE,SEFEE,SENFEE]) */
    /* PME Interrupt Enables (PCIERCn_CFG035[PMEIE]) */
    {
        bdk_pciercx_cfg035_t pciercx_cfg035;
        pciercx_cfg035.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG035(pcie_port));
        pciercx_cfg035.s.secee = 1; /* System error on correctable error enable. */
        pciercx_cfg035.s.sefee = 1; /* System error on fatal error enable. */
        pciercx_cfg035.s.senfee = 1; /* System error on non-fatal error enable. */
        pciercx_cfg035.s.pmeie = 1; /* PME interrupt enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG035(pcie_port), pciercx_cfg035.u32);
    }

    /* Advanced Error Recovery Interrupt Enables */
    /* (PCIERCn_CFG075[CERE,NFERE,FERE]) */
    {
        bdk_pciercx_cfg075_t pciercx_cfg075;
        pciercx_cfg075.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG075(pcie_port));
        pciercx_cfg075.s.cere = 1; /* Correctable error reporting enable. */
        pciercx_cfg075.s.nfere = 1; /* Non-fatal error reporting enable. */
        pciercx_cfg075.s.fere = 1; /* Fatal error reporting enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG075(pcie_port), pciercx_cfg075.u32);
    }

    /* HP Interrupt Enables (PCIERCn_CFG034[HPINT_EN], */
    /* PCIERCn_CFG034[DLLS_EN,CCINT_EN]) */
    {
        bdk_pciercx_cfg034_t pciercx_cfg034;
        pciercx_cfg034.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG034(pcie_port));
        pciercx_cfg034.s.hpint_en = 1; /* Hot-plug interrupt enable. */
        pciercx_cfg034.s.dlls_en = 1; /* Data Link Layer state changed enable */
        pciercx_cfg034.s.ccint_en = 1; /* Command completed interrupt enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG034(pcie_port), pciercx_cfg034.u32);
    }
}

/**
 * @INTERNAL
 * Initialize a host mode PCIe gen 1 link. This function takes a PCIe
 * port from reset to a link up state. Software can then begin
 * configuring the rest of the link.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
static int __bdk_pcie_rc_initialize_link_gen1(int pcie_port)
{
    uint64_t start_cycle;
    bdk_pescx_ctl_status_t pescx_ctl_status;
    bdk_pciercx_cfg452_t pciercx_cfg452;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_pciercx_cfg448_t pciercx_cfg448;

    /* Set the lane width */
    pciercx_cfg452.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG452(pcie_port));
    pescx_ctl_status.u64 = BDK_CSR_READ(BDK_PESCX_CTL_STATUS(pcie_port));
    if (pescx_ctl_status.s.qlm_cfg == 0)
    {
        /* We're in 8 lane (56XX) or 4 lane (54XX) mode */
        pciercx_cfg452.s.lme = 0xf;
    }
    else
    {
        /* We're in 4 lane (56XX) or 2 lane (52XX) mode */
        pciercx_cfg452.s.lme = 0x7;
    }
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG452(pcie_port), pciercx_cfg452.u32);

    /* CN52XX pass 1.x has an errata where length mismatches on UR responses can
        cause bus errors on 64bit memory reads. Turning off length error
        checking fixes this */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
    {
        bdk_pciercx_cfg455_t pciercx_cfg455;
        pciercx_cfg455.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG455(pcie_port));
        pciercx_cfg455.s.m_cpl_len_err = 1;
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG455(pcie_port), pciercx_cfg455.u32);
    }

    /* Lane swap needs to be manually enabled for CN52XX */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX) && (pcie_port == 1))
    {
      pescx_ctl_status.s.lane_swp = 1;
      BDK_CSR_WRITE(BDK_PESCX_CTL_STATUS(pcie_port),pescx_ctl_status.u64);
    }

    /* Bring up the link */
    pescx_ctl_status.u64 = BDK_CSR_READ(BDK_PESCX_CTL_STATUS(pcie_port));
    pescx_ctl_status.s.lnk_enb = 1;
    BDK_CSR_WRITE(BDK_PESCX_CTL_STATUS(pcie_port), pescx_ctl_status.u64);

    /* CN52XX pass 1.0: Due to a bug in 2nd order CDR, it needs to be disabled */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_0))
        __bdk_helper_errata_qlm_disable_2nd_order_cdr(0);

    /* Wait for the link to come up */
    start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    do
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle > 2*bdk_clock_get_rate(BDK_CLOCK_CORE))
        {
            bdk_dprintf("PCIe: Port %d link timeout\n", pcie_port);
            return -1;
        }
        bdk_wait(10000);
        pciercx_cfg032.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG032(pcie_port));
    } while (pciercx_cfg032.s.dlla == 0);

    /* Clear all pending errors */
    BDK_CSR_WRITE(BDK_NPEI_INT_SUM, BDK_CSR_READ(BDK_NPEI_INT_SUM));

    /* Update the Replay Time Limit. Empirically, some PCIe devices take a
        little longer to respond than expected under load. As a workaround for
        this we configure the Replay Time Limit to the value expected for a 512
        byte MPS instead of our actual 256 byte MPS. The numbers below are
        directly from the PCIe spec table 3-4 */
    pciercx_cfg448.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG448(pcie_port));
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
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG448(pcie_port), pciercx_cfg448.u32);

    return 0;
}


/**
 * Initialize a PCIe gen 1 port for use in host(RC) mode. It doesn't enumerate
 * the bus.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
static int __bdk_pcie_rc_initialize_gen1(int pcie_port)
{
    int i;
    int base;
    uint64_t addr_swizzle;
    bdk_ciu_soft_prst_t ciu_soft_prst;
    bdk_pescx_bist_status_t pescx_bist_status;
    bdk_pescx_bist_status2_t pescx_bist_status2;
    bdk_npei_ctl_status_t npei_ctl_status;
    bdk_npei_mem_access_ctl_t npei_mem_access_ctl;
    bdk_npei_mem_access_subidx_t mem_access_subid;
    bdk_npei_dbg_data_t npei_dbg_data;
    bdk_pescx_ctl_status2_t pescx_ctl_status2;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_npei_bar1_indexx_t bar1_index;

retry:
    /* Make sure we aren't trying to setup a target mode interface in host mode */
    npei_ctl_status.u64 = BDK_CSR_READ(BDK_NPEI_CTL_STATUS);
    if ((pcie_port==0) && !npei_ctl_status.s.host_mode)
    {
        bdk_dprintf("PCIe: Port %d in endpoint mode\n", pcie_port);
        return -1;
    }

    /* Make sure a CN52XX isn't trying to bring up port 1 when it is disabled */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX))
    {
        npei_dbg_data.u64 = BDK_CSR_READ(BDK_NPEI_DBG_DATA);
        if ((pcie_port==1) && npei_dbg_data.cn52xx.qlm0_link_width)
        {
            bdk_dprintf("PCIe: ERROR: bdk_pcie_rc_initialize() called on port1, but port1 is disabled\n");
            return -1;
        }
    }

    /* PCIe switch arbitration mode. '0' == fixed priority NPEI, PCIe0, then PCIe1. '1' == round robin. */
    npei_ctl_status.s.arb = 1;
    /* Allow up to 0x20 config retries */
    npei_ctl_status.s.cfg_rtry = 0x20;
    /* CN52XX pass1.x has an errata where P0_NTAGS and P1_NTAGS don't reset */
    if (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
    {
        npei_ctl_status.s.p0_ntags = 0x20;
        npei_ctl_status.s.p1_ntags = 0x20;
    }
    BDK_CSR_WRITE(BDK_NPEI_CTL_STATUS, npei_ctl_status.u64);

    /* Bring the PCIe out of reset */
    if (0) //(bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBH5200)
    {
        /* The EBH5200 board swapped the PCIe reset lines on the board. As a
            workaround for this bug, we bring both PCIe ports out of reset at
            the same time instead of on separate calls. So for port 0, we bring
            both out of reset and do nothing on port 1 */
        if (pcie_port == 0)
        {
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
            /* After a chip reset the PCIe will also be in reset. If it isn't,
                most likely someone is trying to init it again without a proper
                PCIe reset */
            if (ciu_soft_prst.s.soft_prst == 0)
            {
		/* Reset the ports */
		ciu_soft_prst.s.soft_prst = 1;
		BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
		ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
		ciu_soft_prst.s.soft_prst = 1;
		BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
		/* Wait until pcie resets the ports. */
		bdk_wait_usec(2000);
            }
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
            ciu_soft_prst.s.soft_prst = 0;
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
            ciu_soft_prst.s.soft_prst = 0;
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
        }
    }
    else
    {
        /* The normal case: The PCIe ports are completely separate and can be
            brought out of reset independently */
        if (pcie_port)
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
        else
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
        /* After a chip reset the PCIe will also be in reset. If it isn't,
            most likely someone is trying to init it again without a proper
            PCIe reset */
        if (ciu_soft_prst.s.soft_prst == 0)
        {
	    /* Reset the port */
	    ciu_soft_prst.s.soft_prst = 1;
	    if (pcie_port)
		BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
 	    else
		BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
	    /* Wait until pcie resets the ports. */
	    bdk_wait_usec(2000);
        }
        if (pcie_port)
        {
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
            ciu_soft_prst.s.soft_prst = 0;
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
        }
        else
        {
            ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
            ciu_soft_prst.s.soft_prst = 0;
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
        }
    }

    /* Wait for PCIe reset to complete. Due to errata PCIE-700, we don't poll
       PESCX_CTL_STATUS2[PCIERST], but simply wait a fixed number of cycles */
    bdk_wait(400000);

    /* PESCX_BIST_STATUS2[PCLK_RUN] was missing on pass 1 of CN56XX and
        CN52XX, so we only probe it on newer chips */
    if (!OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X) && !OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
    {
        /* Clear PCLK_RUN so we can check if the clock is running */
        pescx_ctl_status2.u64 = BDK_CSR_READ(BDK_PESCX_CTL_STATUS2(pcie_port));
        pescx_ctl_status2.s.pclk_run = 1;
        BDK_CSR_WRITE(BDK_PESCX_CTL_STATUS2(pcie_port), pescx_ctl_status2.u64);
        /* Now that we cleared PCLK_RUN, wait for it to be set again telling
            us the clock is running */
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_PESCX_CTL_STATUS2(pcie_port), pclk_run, ==, 1, 10000))
        {
            bdk_dprintf("PCIe: Port %d isn't clocked, skipping.\n", pcie_port);
            return -1;
        }
    }

    /* Check and make sure PCIe came out of reset. If it doesn't the board
        probably hasn't wired the clocks up and the interface should be
        skipped */
    pescx_ctl_status2.u64 = BDK_CSR_READ(BDK_PESCX_CTL_STATUS2(pcie_port));
    if (pescx_ctl_status2.s.pcierst)
    {
        bdk_dprintf("PCIe: Port %d stuck in reset, skipping.\n", pcie_port);
        return -1;
    }

    /* Check BIST2 status. If any bits are set skip this interface. This
        is an attempt to catch PCIE-813 on pass 1 parts */
    pescx_bist_status2.u64 = BDK_CSR_READ(BDK_PESCX_BIST_STATUS2(pcie_port));
    if (pescx_bist_status2.u64)
    {
        bdk_dprintf("PCIe: Port %d BIST2 failed. Most likely this port isn't hooked up, skipping.\n", pcie_port);
        return -1;
    }

    /* Check BIST status */
    pescx_bist_status.u64 = BDK_CSR_READ(BDK_PESCX_BIST_STATUS(pcie_port));
    if (pescx_bist_status.u64)
        bdk_dprintf("PCIe: BIST FAILED for port %d (0x%016llx)\n", pcie_port, CAST64(pescx_bist_status.u64));

    /* Initialize the config space CSRs */
    __bdk_pcie_rc_initialize_config_space(pcie_port);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link_gen1(pcie_port))
    {
        bdk_dprintf("PCIe: Failed to initialize port %d, probably the slot is empty\n", pcie_port);
        return -1;
    }

    /* Store merge control (NPEI_MEM_ACCESS_CTL[TIMER,MAX_WORD]) */
    npei_mem_access_ctl.u64 = BDK_CSR_READ(BDK_NPEI_MEM_ACCESS_CTL);
    npei_mem_access_ctl.s.max_word = 0;     /* Allow 16 words to combine */
    npei_mem_access_ctl.s.timer = 127;      /* Wait up to 127 cycles for more data */
    BDK_CSR_WRITE(BDK_NPEI_MEM_ACCESS_CTL, npei_mem_access_ctl.u64);

    /* Setup Mem access SubDIDs */
    mem_access_subid.u64 = 0;
    mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
    mem_access_subid.s.nmerge = 1;  /* Due to an errata on pass 1 chips, no merging is allowed. */
    mem_access_subid.s.esr = 1;     /* Endian-swap for Reads. */
    mem_access_subid.s.esw = 1;     /* Endian-swap for Writes. */
    mem_access_subid.s.nsr = 0;     /* Enable Snooping for Reads. Octeon doesn't care, but devices might want this more conservative setting */
    mem_access_subid.s.nsw = 0;     /* Enable Snoop for Writes. */
    mem_access_subid.s.ror = 0;     /* Disable Relaxed Ordering for Reads. */
    mem_access_subid.s.row = 0;     /* Disable Relaxed Ordering for Writes. */
    mem_access_subid.s.ba = 0;      /* PCIe Adddress Bits <63:34>. */

    /* Setup mem access 12-15 for port 0, 16-19 for port 1, supplying 36 bits of address space */
    for (i=12 + pcie_port*4; i<16 + pcie_port*4; i++)
    {
        BDK_CSR_WRITE(BDK_NPEI_MEM_ACCESS_SUBIDX(i), mem_access_subid.u64);
        mem_access_subid.s.ba += 1; /* Set each SUBID to extend the addressable range */
    }

    /* Disable the peer to peer forwarding register. This must be setup
        by the OS after it enumerates the bus and assigns addresses to the
        PCIe busses */
    for (i=0; i<4; i++)
    {
        BDK_CSR_WRITE(BDK_PESCX_P2P_BARX_START(i, pcie_port), -1);
        BDK_CSR_WRITE(BDK_PESCX_P2P_BARX_END(i, pcie_port), -1);
    }

    /* Set Octeon's BAR0 to decode 0-16KB. It overlaps with Bar2 */
    BDK_CSR_WRITE(BDK_PESCX_P2N_BAR0_START(pcie_port), 0);

    /* BAR1 follows BAR2 with a gap so it has the same address as for gen2. */
    BDK_CSR_WRITE(BDK_PESCX_P2N_BAR1_START(pcie_port), BDK_PCIE_BAR1_RC_BASE);

    bar1_index.u32 = 0;
    bar1_index.s.addr_idx = (BDK_PCIE_BAR1_PHYS_BASE >> 22);
    bar1_index.s.ca = 1;       /* Not Cached */
    bar1_index.s.end_swp = 1;  /* Endian Swap mode */
    bar1_index.s.addr_v = 1;   /* Valid entry */

    base = pcie_port ? 16 : 0;

    /* Big endian swizzle for 32-bit PEXP_NCB register. */
#ifdef __MIPSEB__
    addr_swizzle = 4;
#else
    addr_swizzle = 0;
#endif
    for (i = 0; i < 16; i++) {
        bdk_write64_uint32((BDK_NPEI_BAR1_INDEXX(base) ^ addr_swizzle), bar1_index.u32);
        base++;
        /* 256MB / 16 >> 22 == 4 */
        bar1_index.s.addr_idx += (((1ull << 28) / 16ull) >> 22);
    }

    /* Set Octeon's BAR2 to decode 0-2^39. Bar0 and Bar1 take precedence
        where they overlap. It also overlaps with the device addresses, so
        make sure the peer to peer forwarding is set right */
    BDK_CSR_WRITE(BDK_PESCX_P2N_BAR2_START(pcie_port), 0);

    /* Setup BAR2 attributes */
    /* Relaxed Ordering (NPEI_CTL_PORTn[PTLP_RO,CTLP_RO, WAIT_COM]) */
    /* ­ PTLP_RO,CTLP_RO should normally be set (except for debug). */
    /* ­ WAIT_COM=0 will likely work for all applications. */
    /* Load completion relaxed ordering (NPEI_CTL_PORTn[WAITL_COM]) */
    if (pcie_port)
    {
        bdk_npei_ctl_port1_t npei_ctl_port;
        npei_ctl_port.u64 = BDK_CSR_READ(BDK_NPEI_CTL_PORT1);
        npei_ctl_port.s.bar2_enb = 1;
        npei_ctl_port.s.bar2_esx = 1;
        npei_ctl_port.s.bar2_cax = 0;
        npei_ctl_port.s.ptlp_ro = 1;
        npei_ctl_port.s.ctlp_ro = 1;
        npei_ctl_port.s.wait_com = 0;
        npei_ctl_port.s.waitl_com = 0;
        BDK_CSR_WRITE(BDK_NPEI_CTL_PORT1, npei_ctl_port.u64);
    }
    else
    {
        bdk_npei_ctl_port0_t npei_ctl_port;
        npei_ctl_port.u64 = BDK_CSR_READ(BDK_NPEI_CTL_PORT0);
        npei_ctl_port.s.bar2_enb = 1;
        npei_ctl_port.s.bar2_esx = 1;
        npei_ctl_port.s.bar2_cax = 0;
        npei_ctl_port.s.ptlp_ro = 1;
        npei_ctl_port.s.ctlp_ro = 1;
        npei_ctl_port.s.wait_com = 0;
        npei_ctl_port.s.waitl_com = 0;
        BDK_CSR_WRITE(BDK_NPEI_CTL_PORT0, npei_ctl_port.u64);
    }

    /* Both pass 1 and pass 2 of CN52XX and CN56XX have an errata that causes
        TLP ordering to not be preserved after multiple PCIe port resets. This
        code detects this fault and corrects it by aligning the TLP counters
        properly. Another link reset is then performed. See PCIE-13340 */
    if (OCTEON_IS_MODEL(OCTEON_CN56XX_PASS2_X) || OCTEON_IS_MODEL(OCTEON_CN52XX_PASS2_X) ||
        OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X) || OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X))
    {
        bdk_npei_dbg_data_t dbg_data;
        int old_in_fif_p_count;
        int in_fif_p_count;
        int out_p_count;
        int in_p_offset = (OCTEON_IS_MODEL(OCTEON_CN52XX_PASS1_X) || OCTEON_IS_MODEL(OCTEON_CN56XX_PASS1_X)) ? 4 : 1;
        int i;

        /* Choose a write address of 1MB. It should be harmless as all bars
            haven't been setup */
        uint64_t write_address = (bdk_pcie_get_mem_base_address(pcie_port) + 0x100000) | (1ull<<63);

        /* Make sure at least in_p_offset have been executed before we try and
            read in_fif_p_count */
        i = in_p_offset;
        while (i--)
        {
            bdk_write64_uint32(write_address, 0);
            bdk_wait(10000);
        }

        /* Read the IN_FIF_P_COUNT from the debug select. IN_FIF_P_COUNT can be
            unstable sometimes so read it twice with a write between the reads.
            This way we can tell the value is good as it will increment by one
            due to the write */
        BDK_CSR_WRITE(BDK_NPEI_DBG_SELECT, (pcie_port) ? 0xd7fc : 0xcffc);
        BDK_CSR_READ(BDK_NPEI_DBG_SELECT);
        do
        {
            dbg_data.u64 = BDK_CSR_READ(BDK_NPEI_DBG_DATA);
            old_in_fif_p_count = dbg_data.s.data & 0xff;
            bdk_write64_uint32(write_address, 0);
            bdk_wait(10000);
            dbg_data.u64 = BDK_CSR_READ(BDK_NPEI_DBG_DATA);
            in_fif_p_count = dbg_data.s.data & 0xff;
        } while (in_fif_p_count != ((old_in_fif_p_count+1) & 0xff));

        /* Update in_fif_p_count for it's offset with respect to out_p_count */
        in_fif_p_count = (in_fif_p_count + in_p_offset) & 0xff;

        /* Read the OUT_P_COUNT from the debug select */
        BDK_CSR_WRITE(BDK_NPEI_DBG_SELECT, (pcie_port) ? 0xd00f : 0xc80f);
        BDK_CSR_READ(BDK_NPEI_DBG_SELECT);
        dbg_data.u64 = BDK_CSR_READ(BDK_NPEI_DBG_DATA);
        out_p_count = (dbg_data.s.data>>1) & 0xff;

        /* Check that the two counters are aligned */
        if (out_p_count != in_fif_p_count)
        {
            bdk_dprintf("PCIe: Port %d aligning TLP counters as workaround to maintain ordering\n", pcie_port);
            while (in_fif_p_count != 0)
            {
                bdk_write64_uint32(write_address, 0);
                bdk_wait(10000);
                in_fif_p_count = (in_fif_p_count + 1) & 0xff;
            }
            /* The EBH5200 board swapped the PCIe reset lines on the board. This
                means we must bring both links down and up, which will cause the
                PCIe0 to need alignment again. Lots of messages will be displayed,
                but everything should work */
            if (0 && //(bdk_sysinfo_get()->board_type == BDK_BOARD_TYPE_EBH5200) &&
                (pcie_port == 1))
                bdk_pcie_rc_initialize(0);
            /* Rety bringing this port up */
            goto retry;
        }
    }

    /* Display the link status */
    pciercx_cfg032.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG032(pcie_port));
    bdk_dprintf("PCIe: Port %d link active, %d lanes\n", pcie_port, pciercx_cfg032.s.nlw);

    return 0;
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
static int __bdk_pcie_rc_initialize_link_gen2(int pcie_port)
{
    uint64_t start_cycle;
    bdk_pemx_ctl_status_t pem_ctl_status;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_pciercx_cfg448_t pciercx_cfg448;

    /* Bring up the link */
    pem_ctl_status.u64 = BDK_CSR_READ(BDK_PEMX_CTL_STATUS(pcie_port));
    pem_ctl_status.s.lnk_enb = 1;
    BDK_CSR_WRITE(BDK_PEMX_CTL_STATUS(pcie_port), pem_ctl_status.u64);

    /* Wait for the link to come up */
    start_cycle = bdk_clock_get_count(BDK_CLOCK_CORE);
    do
    {
        if (bdk_clock_get_count(BDK_CLOCK_CORE) - start_cycle > bdk_clock_get_rate(BDK_CLOCK_CORE))
            return -1;
        bdk_wait(10000);
        pciercx_cfg032.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG032(pcie_port));
    } while (pciercx_cfg032.s.dlla == 0);

    /* Update the Replay Time Limit. Empirically, some PCIe devices take a
        little longer to respond than expected under load. As a workaround for
        this we configure the Replay Time Limit to the value expected for a 512
        byte MPS instead of our actual 256 byte MPS. The numbers below are
        directly from the PCIe spec table 3-4 */
    pciercx_cfg448.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG448(pcie_port));
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
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG448(pcie_port), pciercx_cfg448.u32);

    return 0;
}


/**
 * Initialize a PCIe gen 2 port for use in host(RC) mode. It doesn't enumerate
 * the bus.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
static int __bdk_pcie_rc_initialize_gen2(int pcie_port)
{
    int i;
    bdk_ciu_soft_prst_t ciu_soft_prst;
    bdk_mio_rst_ctlx_t mio_rst_ctl;
    bdk_pemx_bar_ctl_t pemx_bar_ctl;
    bdk_pemx_ctl_status_t pemx_ctl_status;
    bdk_pemx_bist_status_t pemx_bist_status;
    bdk_pemx_bist_status2_t pemx_bist_status2;
    bdk_pciercx_cfg032_t pciercx_cfg032;
    bdk_pciercx_cfg515_t pciercx_cfg515;
    bdk_sli_ctl_portx_t sli_ctl_portx;
    bdk_sli_mem_access_ctl_t sli_mem_access_ctl;
    bdk_sli_mem_access_subidx_t mem_access_subid;
    bdk_mio_rst_ctlx_t mio_rst_ctlx;
    bdk_sriox_status_reg_t sriox_status_reg;
    bdk_pemx_bar1_indexx_t bar1_index;

    /* Make sure this interface isn't SRIO */
    sriox_status_reg.u64 = BDK_CSR_READ(BDK_SRIOX_STATUS_REG(pcie_port));
    if (sriox_status_reg.s.srio)
    {
        bdk_dprintf("PCIe: Port %d is SRIO, skipping.\n", pcie_port);
        return -1;
    }

    /* Make sure we aren't trying to setup a target mode interface in host mode */
    mio_rst_ctl.u64 = BDK_CSR_READ(BDK_MIO_RST_CTLX(pcie_port));
    if (!mio_rst_ctl.s.host_mode)
    {
        bdk_dprintf("PCIe: Port %d in endpoint mode.\n", pcie_port);
        return -1;
    }

    /* CN63XX Pass 1.0 errata G-14395 requires the QLM De-emphasis be programmed */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
    {
        if (pcie_port)
        {
            bdk_ciu_qlm1_t ciu_qlm;
            ciu_qlm.u64 = BDK_CSR_READ(BDK_CIU_QLM1);
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 5;
            ciu_qlm.s.txmargin = 0x17;
            BDK_CSR_WRITE(BDK_CIU_QLM1, ciu_qlm.u64);
        }
        else
        {
            bdk_ciu_qlm0_t ciu_qlm;
            ciu_qlm.u64 = BDK_CSR_READ(BDK_CIU_QLM0);
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 5;
            ciu_qlm.s.txmargin = 0x17;
            BDK_CSR_WRITE(BDK_CIU_QLM0, ciu_qlm.u64);
        }
    }

    /* Bring the PCIe out of reset */
    if (pcie_port)
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
    else
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
    /* After a chip reset the PCIe will also be in reset. If it isn't,
        most likely someone is trying to init it again without a proper
        PCIe reset */
    if (ciu_soft_prst.s.soft_prst == 0)
    {
        /* Reset the port */
        ciu_soft_prst.s.soft_prst = 1;
        if (pcie_port)
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
        else
            BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
        /* Wait until pcie resets the ports. */
        bdk_wait_usec(2000);
    }
    if (pcie_port)
    {
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
        ciu_soft_prst.s.soft_prst = 0;
        BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
    }
    else
    {
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
        ciu_soft_prst.s.soft_prst = 0;
        BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
    }

    /* Wait for PCIe reset to complete */
    bdk_wait_usec(1000);

    /* Check and make sure PCIe came out of reset. If it doesn't the board
        probably hasn't wired the clocks up and the interface should be
        skipped */
    mio_rst_ctlx.u64 = BDK_CSR_READ(BDK_MIO_RST_CTLX(pcie_port));
    if (!mio_rst_ctlx.s.rst_done)
    {
        bdk_dprintf("PCIe: Port %d stuck in reset, skipping.\n", pcie_port);
        return -1;
    }

    /* Check BIST status */
    pemx_bist_status.u64 = BDK_CSR_READ(BDK_PEMX_BIST_STATUS(pcie_port));
    if (pemx_bist_status.u64)
        bdk_dprintf("PCIe: BIST FAILED for port %d (0x%016llx)\n", pcie_port, CAST64(pemx_bist_status.u64));
    pemx_bist_status2.u64 = BDK_CSR_READ(BDK_PEMX_BIST_STATUS2(pcie_port));
    /* Errata PCIE-14766 may cause the lower 6 bits to be randomly set on CN63XXp1 */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_X))
        pemx_bist_status2.u64 &= ~0x3full;
    if (pemx_bist_status2.u64)
        bdk_dprintf("PCIe: BIST2 FAILED for port %d (0x%016llx)\n", pcie_port, CAST64(pemx_bist_status2.u64));

    /* Initialize the config space CSRs */
    __bdk_pcie_rc_initialize_config_space(pcie_port);

    /* Enable gen2 speed selection */
    pciercx_cfg515.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG515(pcie_port));
    pciercx_cfg515.s.dsc = 1;
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG515(pcie_port), pciercx_cfg515.u32);

    /* Bring the link up */
    if (__bdk_pcie_rc_initialize_link_gen2(pcie_port))
    {
        /* Some gen1 devices don't handle the gen 2 training correctly. Disable
            gen2 and try again with only gen1 */
        bdk_pciercx_cfg031_t pciercx_cfg031;
        pciercx_cfg031.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG031(pcie_port));
        pciercx_cfg031.s.mls = 1;
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIERCX_CFG031(pcie_port), pciercx_cfg515.u32);
        if (__bdk_pcie_rc_initialize_link_gen2(pcie_port))
        {
            bdk_dprintf("PCIe: Link timeout on port %d, probably the slot is empty\n", pcie_port);
            return -1;
        }
    }

    /* Store merge control (SLI_MEM_ACCESS_CTL[TIMER,MAX_WORD]) */
    sli_mem_access_ctl.u64 = BDK_CSR_READ(BDK_SLI_MEM_ACCESS_CTL);
    sli_mem_access_ctl.s.max_word = 0;     /* Allow 16 words to combine */
    sli_mem_access_ctl.s.timer = 127;      /* Wait up to 127 cycles for more data */
    BDK_CSR_WRITE(BDK_SLI_MEM_ACCESS_CTL, sli_mem_access_ctl.u64);

    /* Setup Mem access SubDIDs */
    mem_access_subid.u64 = 0;
    mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
    mem_access_subid.s.nmerge = 0;  /* Allow merging as it works on CN6XXX. */
    mem_access_subid.s.esr = 1;     /* Endian-swap for Reads. */
    mem_access_subid.s.esw = 1;     /* Endian-swap for Writes. */
    mem_access_subid.s.wtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
    mem_access_subid.s.rtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
    mem_access_subid.cn63xx.ba = 0;      /* PCIe Adddress Bits <63:34>. */

    /* Setup mem access 12-15 for port 0, 16-19 for port 1, supplying 36 bits of address space */
    for (i=12 + pcie_port*4; i<16 + pcie_port*4; i++)
    {
        BDK_CSR_WRITE(BDK_SLI_MEM_ACCESS_SUBIDX(i), mem_access_subid.u64);
        mem_access_subid.cn63xx.ba += 1; /* Set each SUBID to extend the addressable range */
    }

    /* Disable the peer to peer forwarding register. This must be setup
        by the OS after it enumerates the bus and assigns addresses to the
        PCIe busses */
    for (i=0; i<4; i++)
    {
        BDK_CSR_WRITE(BDK_PEMX_P2P_BARX_START(i, pcie_port), -1);
        BDK_CSR_WRITE(BDK_PEMX_P2P_BARX_END(i, pcie_port), -1);
    }

    /* Set Octeon's BAR0 to decode 0-16KB. It overlaps with Bar2 */
    BDK_CSR_WRITE(BDK_PEMX_P2N_BAR0_START(pcie_port), 0);

    /* Set Octeon's BAR2 to decode 0-2^41. Bar0 and Bar1 take precedence
        where they overlap. It also overlaps with the device addresses, so
        make sure the peer to peer forwarding is set right */
    BDK_CSR_WRITE(BDK_PEMX_P2N_BAR2_START(pcie_port), 0);

    /* Setup BAR2 attributes */
    /* Relaxed Ordering (NPEI_CTL_PORTn[PTLP_RO,CTLP_RO, WAIT_COM]) */
    /* ­ PTLP_RO,CTLP_RO should normally be set (except for debug). */
    /* ­ WAIT_COM=0 will likely work for all applications. */
    /* Load completion relaxed ordering (NPEI_CTL_PORTn[WAITL_COM]) */
    pemx_bar_ctl.u64 = BDK_CSR_READ(BDK_PEMX_BAR_CTL(pcie_port));
    pemx_bar_ctl.s.bar1_siz = 3;  /* 256MB BAR1*/
    pemx_bar_ctl.s.bar2_enb = 1;
    pemx_bar_ctl.s.bar2_esx = 1;
    pemx_bar_ctl.s.bar2_cax = 0;
    BDK_CSR_WRITE(BDK_PEMX_BAR_CTL(pcie_port), pemx_bar_ctl.u64);
    sli_ctl_portx.u64 = BDK_CSR_READ(BDK_SLI_CTL_PORTX(pcie_port));
    sli_ctl_portx.s.ptlp_ro = 1;
    sli_ctl_portx.s.ctlp_ro = 1;
    sli_ctl_portx.s.wait_com = 0;
    sli_ctl_portx.s.waitl_com = 0;
    BDK_CSR_WRITE(BDK_SLI_CTL_PORTX(pcie_port), sli_ctl_portx.u64);

    /* BAR1 follows BAR2 */
    BDK_CSR_WRITE(BDK_PEMX_P2N_BAR1_START(pcie_port), BDK_PCIE_BAR1_RC_BASE);

    bar1_index.u64 = 0;
    bar1_index.s.addr_idx = (BDK_PCIE_BAR1_PHYS_BASE >> 22);
    bar1_index.s.ca = 1;       /* Not Cached */
    bar1_index.s.end_swp = 1;  /* Endian Swap mode */
    bar1_index.s.addr_v = 1;   /* Valid entry */

    for (i = 0; i < 16; i++) {
        BDK_CSR_WRITE(BDK_PEMX_BAR1_INDEXX(i, pcie_port), bar1_index.u64);
        /* 256MB / 16 >> 22 == 4 */
        bar1_index.s.addr_idx += (((1ull << 28) / 16ull) >> 22);
    }

    /* Allow config retries for 250ms. Count is based off the 5Ghz SERDES
        clock */
    pemx_ctl_status.u64 = BDK_CSR_READ(BDK_PEMX_CTL_STATUS(pcie_port));
    pemx_ctl_status.s.cfg_rtry = 250 * 5000000 / 0x10000;
    BDK_CSR_WRITE(BDK_PEMX_CTL_STATUS(pcie_port), pemx_ctl_status.u64);

    /* Display the link status */
    pciercx_cfg032.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG032(pcie_port));
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
int bdk_pcie_rc_initialize(int pcie_port)
{
    int result;
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
        result = __bdk_pcie_rc_initialize_gen1(pcie_port);
    else
        result = __bdk_pcie_rc_initialize_gen2(pcie_port);
    return result;
}


/**
 * Shutdown a PCIe port and put it in reset
 *
 * @param pcie_port PCIe port to shutdown
 *
 * @return Zero on success
 */
int bdk_pcie_rc_shutdown(int pcie_port)
{
    /* Wait for all pending operations to complete */
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_PESCX_CPL_LUT_VALID(pcie_port), tag, ==, 0, 2000))
            bdk_dprintf("PCIe: Port %d shutdown timeout\n", pcie_port);
    }
    else
    {
        if (BDK_CSR_WAIT_FOR_FIELD(BDK_PEMX_CPL_LUT_VALID(pcie_port), tag, ==, 0, 2000))
            bdk_dprintf("PCIe: Port %d shutdown timeout\n", pcie_port);
    }

    /* Force reset */
    if (pcie_port)
    {
        bdk_ciu_soft_prst_t ciu_soft_prst;
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST1);
        ciu_soft_prst.s.soft_prst = 1;
        BDK_CSR_WRITE(BDK_CIU_SOFT_PRST1, ciu_soft_prst.u64);
    }
    else
    {
        bdk_ciu_soft_prst_t ciu_soft_prst;
        ciu_soft_prst.u64 = BDK_CSR_READ(BDK_CIU_SOFT_PRST);
        ciu_soft_prst.s.soft_prst = 1;
        BDK_CSR_WRITE(BDK_CIU_SOFT_PRST, ciu_soft_prst.u64);
    }
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
static inline uint64_t __bdk_pcie_build_config_addr(int pcie_port, int bus, int dev, int fn, int reg)
{
    bdk_pcie_address_t pcie_addr;
    bdk_pciercx_cfg006_t pciercx_cfg006;

    pciercx_cfg006.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIERCX_CFG006(pcie_port));
    if ((bus <= pciercx_cfg006.s.pbnum) && (dev != 0))
        return 0;

    pcie_addr.u64 = 0;
    pcie_addr.config.upper = 2;
    pcie_addr.config.io = 1;
    pcie_addr.config.did = 3;
    pcie_addr.config.subdid = 1;
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
uint8_t bdk_pcie_config_read8(int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
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
uint16_t bdk_pcie_config_read16(int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
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
uint32_t bdk_pcie_config_read32(int pcie_port, int bus, int dev, int fn, int reg)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
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
void bdk_pcie_config_write8(int pcie_port, int bus, int dev, int fn, int reg, uint8_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
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
void bdk_pcie_config_write16(int pcie_port, int bus, int dev, int fn, int reg, uint16_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
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
void bdk_pcie_config_write32(int pcie_port, int bus, int dev, int fn, int reg, uint32_t val)
{
    uint64_t address = __bdk_pcie_build_config_addr(pcie_port, bus, dev, fn, reg);
    if (address)
        bdk_write64_uint32(address, bdk_cpu_to_le32(val));
}


/**
 * Read a PCIe config space register indirectly. This is used for
 * registers of the form PCIEEP_CFG??? and PCIERC?_CFG???.
 *
 * @param pcie_port  PCIe port to read from
 * @param cfg_offset Address to read
 *
 * @return Value read
 */
uint32_t bdk_pcie_cfgx_read(int pcie_port, uint32_t cfg_offset)
{
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_pescx_cfg_rd_t pescx_cfg_rd;
        pescx_cfg_rd.u64 = 0;
        pescx_cfg_rd.s.addr = cfg_offset;
        BDK_CSR_WRITE(BDK_PESCX_CFG_RD(pcie_port), pescx_cfg_rd.u64);
        pescx_cfg_rd.u64 = BDK_CSR_READ(BDK_PESCX_CFG_RD(pcie_port));
        return pescx_cfg_rd.s.data;
    }
    else
    {
        bdk_pemx_cfg_rd_t pemx_cfg_rd;
        pemx_cfg_rd.u64 = 0;
        pemx_cfg_rd.s.addr = cfg_offset;
        BDK_CSR_WRITE(BDK_PEMX_CFG_RD(pcie_port), pemx_cfg_rd.u64);
        pemx_cfg_rd.u64 = BDK_CSR_READ(BDK_PEMX_CFG_RD(pcie_port));
        return pemx_cfg_rd.s.data;
    }
}


/**
 * Write a PCIe config space register indirectly. This is used for
 * registers of the form PCIEEP_CFG??? and PCIERC?_CFG???.
 *
 * @param pcie_port  PCIe port to write to
 * @param cfg_offset Address to write
 * @param val        Value to write
 */
void bdk_pcie_cfgx_write(int pcie_port, uint32_t cfg_offset, uint32_t val)
{
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_pescx_cfg_wr_t pescx_cfg_wr;
        pescx_cfg_wr.u64 = 0;
        pescx_cfg_wr.s.addr = cfg_offset;
        pescx_cfg_wr.s.data = val;
        BDK_CSR_WRITE(BDK_PESCX_CFG_WR(pcie_port), pescx_cfg_wr.u64);
    }
    else
    {
        bdk_pemx_cfg_wr_t pemx_cfg_wr;
        pemx_cfg_wr.u64 = 0;
        pemx_cfg_wr.s.addr = cfg_offset;
        pemx_cfg_wr.s.data = val;
        BDK_CSR_WRITE(BDK_PEMX_CFG_WR(pcie_port), pemx_cfg_wr.u64);
    }
}


/**
 * Initialize a PCIe port for use in target(EP) mode.
 *
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_ep_initialize(int pcie_port)
{
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_npei_ctl_status_t npei_ctl_status;
        npei_ctl_status.u64 = BDK_CSR_READ(BDK_NPEI_CTL_STATUS);
        if (npei_ctl_status.s.host_mode)
            return -1;
    }
    else
    {
        bdk_mio_rst_ctlx_t mio_rst_ctl;
        mio_rst_ctl.u64 = BDK_CSR_READ(BDK_MIO_RST_CTLX(pcie_port));
        if (mio_rst_ctl.s.host_mode)
            return -1;
    }

    /* CN63XX Pass 1.0 errata G-14395 requires the QLM De-emphasis be programmed */
    if (OCTEON_IS_MODEL(OCTEON_CN63XX_PASS1_0))
    {
        if (pcie_port)
        {
            bdk_ciu_qlm1_t ciu_qlm;
            ciu_qlm.u64 = BDK_CSR_READ(BDK_CIU_QLM1);
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 5;
            ciu_qlm.s.txmargin = 0x17;
            BDK_CSR_WRITE(BDK_CIU_QLM1, ciu_qlm.u64);
        }
        else
        {
            bdk_ciu_qlm0_t ciu_qlm;
            ciu_qlm.u64 = BDK_CSR_READ(BDK_CIU_QLM0);
            ciu_qlm.s.txbypass = 1;
            ciu_qlm.s.txdeemph = 5;
            ciu_qlm.s.txmargin = 0x17;
            BDK_CSR_WRITE(BDK_CIU_QLM0, ciu_qlm.u64);
        }
    }

    /* Enable bus master and memory */
    bdk_pcie_cfgx_write(pcie_port, BDK_PCIEEPX_CFG001(pcie_port), 0x6);

    /* Max Payload Size (PCIE*_CFG030[MPS]) */
    /* Max Read Request Size (PCIE*_CFG030[MRRS]) */
    /* Relaxed-order, no-snoop enables (PCIE*_CFG030[RO_EN,NS_EN] */
    /* Error Message Enables (PCIE*_CFG030[CE_EN,NFE_EN,FE_EN,UR_EN]) */
    {
        bdk_pcieepx_cfg030_t pcieepx_cfg030;
        pcieepx_cfg030.u32 = bdk_pcie_cfgx_read(pcie_port, BDK_PCIEEPX_CFG030(pcie_port));
        if (OCTEON_IS_MODEL(OCTEON_CN5XXX))
        {
            pcieepx_cfg030.s.mps = MPS_CN5XXX;
            pcieepx_cfg030.s.mrrs = MRRS_CN5XXX;
        }
        else
        {
            pcieepx_cfg030.s.mps = MPS_CN6XXX;
            pcieepx_cfg030.s.mrrs = MRRS_CN6XXX;
        }
        pcieepx_cfg030.s.ro_en = 1; /* Enable relaxed ordering. */
        pcieepx_cfg030.s.ns_en = 1; /* Enable no snoop. */
        pcieepx_cfg030.s.ce_en = 1; /* Correctable error reporting enable. */
        pcieepx_cfg030.s.nfe_en = 1; /* Non-fatal error reporting enable. */
        pcieepx_cfg030.s.fe_en = 1; /* Fatal error reporting enable. */
        pcieepx_cfg030.s.ur_en = 1; /* Unsupported request reporting enable. */
        bdk_pcie_cfgx_write(pcie_port, BDK_PCIEEPX_CFG030(pcie_port), pcieepx_cfg030.u32);
    }

    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        /* Max Payload Size (NPEI_CTL_STATUS2[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (NPEI_CTL_STATUS2[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_npei_ctl_status2_t npei_ctl_status2;
        npei_ctl_status2.u64 = BDK_CSR_READ(BDK_NPEI_CTL_STATUS2);
        npei_ctl_status2.s.mps = MPS_CN5XXX; /* Max payload size = 128 bytes (Limit of most PCs) */
        npei_ctl_status2.s.mrrs = MRRS_CN5XXX; /* Max read request size = 128 bytes for best Octeon DMA performance */
        BDK_CSR_WRITE(BDK_NPEI_CTL_STATUS2, npei_ctl_status2.u64);
    }
    else
    {
        /* Max Payload Size (DPI_SLI_PRTX_CFG[MPS]) must match PCIE*_CFG030[MPS] */
        /* Max Read Request Size (DPI_SLI_PRTX_CFG[MRRS]) must not exceed PCIE*_CFG030[MRRS] */
        bdk_dpi_sli_prtx_cfg_t prt_cfg;
        bdk_sli_s2m_portx_ctl_t sli_s2m_portx_ctl;
        prt_cfg.u64 = BDK_CSR_READ(BDK_DPI_SLI_PRTX_CFG(pcie_port));
        prt_cfg.s.mps = MPS_CN6XXX;
        prt_cfg.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(BDK_DPI_SLI_PRTX_CFG(pcie_port), prt_cfg.u64);

        sli_s2m_portx_ctl.u64 = BDK_CSR_READ(BDK_SLI_S2M_PORTX_CTL(pcie_port));
        sli_s2m_portx_ctl.s.mrrs = MRRS_CN6XXX;
        BDK_CSR_WRITE(BDK_SLI_S2M_PORTX_CTL(pcie_port), sli_s2m_portx_ctl.u64);
    }

    /* Setup Mem access SubDID 12 to access Host memory */
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_npei_mem_access_subidx_t mem_access_subid;
        mem_access_subid.u64 = 0;
        mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
        mem_access_subid.s.nmerge = 1;  /* Merging is not allowed in this window. */
        mem_access_subid.s.esr = 0;     /* Endian-swap for Reads. */
        mem_access_subid.s.esw = 0;     /* Endian-swap for Writes. */
        mem_access_subid.s.nsr = 0;     /* Enable Snooping for Reads. Octeon doesn't care, but devices might want this more conservative setting */
        mem_access_subid.s.nsw = 0;     /* Enable Snoop for Writes. */
        mem_access_subid.s.ror = 0;     /* Disable Relaxed Ordering for Reads. */
        mem_access_subid.s.row = 0;     /* Disable Relaxed Ordering for Writes. */
        mem_access_subid.s.ba = 0;      /* PCIe Adddress Bits <63:34>. */
        BDK_CSR_WRITE(BDK_NPEI_MEM_ACCESS_SUBIDX(12), mem_access_subid.u64);
    }
    else
    {
        bdk_sli_mem_access_subidx_t mem_access_subid;
        mem_access_subid.u64 = 0;
        mem_access_subid.s.port = pcie_port; /* Port the request is sent to. */
        mem_access_subid.s.nmerge = 0;  /* Merging is allowed in this window. */
        mem_access_subid.s.esr = 0;     /* Endian-swap for Reads. */
        mem_access_subid.s.esw = 0;     /* Endian-swap for Writes. */
        mem_access_subid.s.wtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
        mem_access_subid.s.rtype = 0;   /* "No snoop" and "Relaxed ordering" are not set */
        mem_access_subid.cn63xx.ba = 0;      /* PCIe Adddress Bits <63:34>. */
        BDK_CSR_WRITE(BDK_SLI_MEM_ACCESS_SUBIDX(12 + pcie_port*4), mem_access_subid.u64);
    }
    return 0;
}


/**
 * Wait for posted PCIe read/writes to reach the other side of
 * the internal PCIe switch. This will insure that core
 * read/writes are posted before anything after this function
 * is called. This may be necessary when writing to memory that
 * will later be read using the DMA/PKT engines.
 *
 * @param pcie_port PCIe port to wait for
 */
void bdk_pcie_wait_for_pending(int pcie_port)
{
    if (octeon_has_feature(OCTEON_FEATURE_NPEI))
    {
        bdk_npei_data_out_cnt_t npei_data_out_cnt;
        int a;
        int b;
        int c;

        /* See section 9.8, PCIe Core-initiated Requests, in the manual for a
            description of how this code works */
        npei_data_out_cnt.u64 = BDK_CSR_READ(BDK_NPEI_DATA_OUT_CNT);
        if (pcie_port)
        {
            if (!npei_data_out_cnt.s.p1_fcnt)
                return;
            a = npei_data_out_cnt.s.p1_ucnt;
            b = (a + npei_data_out_cnt.s.p1_fcnt-1) & 0xffff;
        }
        else
        {
            if (!npei_data_out_cnt.s.p0_fcnt)
                return;
            a = npei_data_out_cnt.s.p0_ucnt;
            b = (a + npei_data_out_cnt.s.p0_fcnt-1) & 0xffff;
        }

        while (1)
        {
            npei_data_out_cnt.u64 = BDK_CSR_READ(BDK_NPEI_DATA_OUT_CNT);
            c = (pcie_port) ? npei_data_out_cnt.s.p1_ucnt : npei_data_out_cnt.s.p0_ucnt;
            if (a<=b)
            {
                if ((c<a) || (c>b))
                    return;
            }
            else
            {
                if ((c>b) && (c<a))
                    return;
            }
        }
    }
    else
    {
        bdk_sli_data_out_cnt_t sli_data_out_cnt;
        int a;
        int b;
        int c;

        sli_data_out_cnt.u64 = BDK_CSR_READ(BDK_SLI_DATA_OUT_CNT);
        if (pcie_port)
        {
            if (!sli_data_out_cnt.s.p1_fcnt)
                return;
            a = sli_data_out_cnt.s.p1_ucnt;
            b = (a + sli_data_out_cnt.s.p1_fcnt-1) & 0xffff;
        }
        else
        {
            if (!sli_data_out_cnt.s.p0_fcnt)
                return;
            a = sli_data_out_cnt.s.p0_ucnt;
            b = (a + sli_data_out_cnt.s.p0_fcnt-1) & 0xffff;
        }

        while (1)
        {
            sli_data_out_cnt.u64 = BDK_CSR_READ(BDK_SLI_DATA_OUT_CNT);
            c = (pcie_port) ? sli_data_out_cnt.s.p1_ucnt : sli_data_out_cnt.s.p0_ucnt;
            if (a<=b)
            {
                if ((c<a) || (c>b))
                    return;
            }
            else
            {
                if ((c>b) && (c<a))
                    return;
            }
        }
    }
}

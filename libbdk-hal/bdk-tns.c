#include <bdk.h>

/* This code is an optional part of the BDK.  It is only linked in 
   if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(TNS);

/* Constants to define the number of various interfaces */
#define TNS_MAX_LMACS	8
#define TNS_MIN_LMAC	0
#define TNS_MAX_NICS	2
#define TNS_MIN_NIC		8
#define TNS_MAX_PORTS	TNS_PHYS_PORT_E_ENUM_LAST

#define TNS_MAX_LOGICAL_PORTS	256

#define TNS_MAX_NIC_PLUT_ENTRIES	256
#define TNS_MAX_LMAC_PLUT_ENTRIES	8
#define TNS_MAX_FWD_PLUT_ENTRIES	TNS_MAX_NIC_PLUT_ENTRIES

#define TNS_NIC_PLUT_ILLEGAL	0xff
#define TNS_LMAC_PLUT_ILLEGAL	TNS_NIC_PLUT_ILLEGAL
#define TNS_LB_PLUT_ILLEGAL		TNS_NIC_PLUT_ILLEGAL
#define TNS_FWD_PLUT_ILLEGAL	0xf

/* This caches the TNS enable bit */
static int tns_enabled = 0;

/* Private internal structure to avoid shifting */
typedef union tns_acc_data {
	uint64_t u;
	struct tns_acc_data_s {
#if __BYTE_ORDER == __BIG_ENDIAN
		uint64_t upper32				: 32;
		uint64_t lower32				: 32;
#else
		uint64_t lower32				: 32;
		uint64_t upper32				: 32;
#endif
	} s;
} tns_acc_data_t;

/**
 * Verify that BIST0-BIST11 contain no boot initialization errors.
 * If any are found log a message and dump the register contents.
 *
 * @param bdk_node_t node
 *
 * @return
 */
static void bdk_tns_check_bist(bdk_node_t node)
{
	bdk_tns_bist_status_t bist_status;
	bdk_tns_bist_status1_t bist_status1;
	bdk_tns_bist_status2_t bist_status2;
	bdk_tns_bist_status3_t bist_status3;
	bdk_tns_bist_status4_t bist_status4;
	bdk_tns_bist_status5_t bist_status5;
	bdk_tns_bist_status6_t bist_status6;
	bdk_tns_bist_status7_t bist_status7;
	bdk_tns_bist_status8_t bist_status8;
	bdk_tns_bist_status9_t bist_status9;
	bdk_tns_bist_status10_t bist_status10;
	bdk_tns_bist_status11_t bist_status11;

#define BDK_TNS_REG_NAME(r) basename_##r
	/* BIST 0 */
	bist_status.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS);
	if (bist_status.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST0 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS), bist_status.u);
	}
	/* BIST 1 */
	bist_status1.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS1);
	if (bist_status1.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST1 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS1), bist_status1.u);
	}
	/* BIST 2 */
	bist_status2.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS2);
	if (bist_status2.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST2 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS2), bist_status2.u);
	}
	/* BIST 3 */
	bist_status3.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS3);
	if (bist_status3.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST3 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS3), bist_status3.u);
	}
	/* BIST 4 */
	bist_status4.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS4);
	if (bist_status4.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST4 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS4), bist_status4.u);
	}
	/* BIST 5 */
	bist_status5.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS5);
	if (bist_status5.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST5 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS5), bist_status5.u);
	}
	/* BIST 6 */
	bist_status6.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS6);
	if (bist_status6.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST6 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS6), bist_status6.u);
	}
	/* BIST 7 */
	bist_status7.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS7);
	if (bist_status7.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST7 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS7), bist_status7.u);
	}
	/* BIST 8 */
	bist_status8.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS8);
	if (bist_status8.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST8 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS8), bist_status8.u);
	}
	/* BIST 9 */
	bist_status9.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS9);
	if (bist_status9.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST9 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS9), bist_status9.u);
	}
	/* BIST 10 */
	bist_status10.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS10);
	if (bist_status10.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST10 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS10), bist_status10.u);
	}
	/* BIST 11 */
	bist_status11.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS11);
	if (bist_status11.u != 0ULL)
	{
		bdk_warn("bdk_tns_check_bist: BIST11 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS11), bist_status11.u);
	}
#undef BDK_TNS_REG_NAME
}

/**
 * Debug Control of TDMA functionality.  Allows the setting of the token
 * levels in the drop request, p2x, x2p and loopback FIFOs at which
 * backpressure is asserted.  Also enables the cut-thru packet transmission
 * to each physical port.
 *
 * @param bdk_node_t node
 * @param uint8_t x2p_thresh
 * @param uint8_t p2x_thresh
 * @param uint8_t lb_thresh
 * @param uint8_t drop_req_thresh
 * @param uint8_t lb_credits
 * @param uint8_t nic_on
 * @param uint8_t lmac_on
 * @param uint8_t lb_on
 *
 * @return Zero on success, negative on failure
 */
static int bdk_tns_config_sched_and_cutthru(bdk_node_t node, uint8_t x2p_thresh, uint8_t p2x_thresh, uint8_t lb_thresh,
											uint8_t drop_req_thresh, uint8_t lb_credits, uint8_t nic_on, uint8_t lmac_on,
											uint8_t lb_on)
{
	bdk_tns_tdma_nb_dbg_config1_t tdma_nb_dbg_config1;

	/* Enable Scheduling thresholds */
	tdma_nb_dbg_config1.u = 0ULL;

	/*
	 * Both NIC interfaces have a FIFO for receiving tokens from the TxQ HW block.
	 * Each FIFO can store 8 tokens, set the number of tokens at which the port
	 * available signal to TxQ is de-asserted. (NB: This includes inflight tokens).
	 */
	if (x2p_thresh > 8)
	{
		bdk_warn("bdk_tns_config_sched_and_cutthru: X2P FIFO size exceeded!\n");
		return -1;
	}
	else
	{
		tdma_nb_dbg_config1.s.x2p_tkn_sch_thresh = x2p_thresh;
	}

	/*
	 * The internal loopback has a FIFO for receiving tokens from the TxQ HW block.
	 * The FIFO can store 8 tokens, set the number of tokens at which the port
	 * available signal to TxQ is de-asserted. (NB: Include inflight tokens).
	 */
	if (lb_thresh > 8)
	{
		bdk_warn("bdk_tns_config_sched_and_cutthru: Loopback FIFO size exceeded!\n");
		return -1;
	}
	else
	{
		tdma_nb_dbg_config1.s.lb_tkn_sch_thresh = lb_thresh;
	}

	/*
	 * Each BGx ports has a FIFO for receiving tokens from the ports's per-
	 * priority Token FIFOs.  The FIFO can store 8 tokens, set the number of
	 * tokens at which the FIFO will stop pulling tokens from the per-
	 * priority Token FIFOs.
	 */
	if (p2x_thresh > 8)
	{
		bdk_warn("bdk_tns_config_sched_and_cutthru: P2X FIFO size exceeded!\n");
		return -1;
	}
	else
	{
		tdma_nb_dbg_config1.s.p2x_tkn_sch_thresh = p2x_thresh;
	}

	/*
	 * Requests to drop packets from the TxQ.  Arriving requests can take one
	 * of two paths:
	 *
	 *   1) If the packet is a single-copy packet, the packet is pushed to a
	 *      16-entry FIFO in the Link List walker logic.
	 *   2) If the packet is a multiple-copy packet, the packet is pushed to 
	 *      a 16-entry FIFO in the Page Reference Count logic.
	 * Set the level at which either of these FIFOs will assert flow control
	 * to TxQ to prevent additional dropped messages from arriving.
	 */
	if (drop_req_thresh > 16)
	{
		bdk_warn("bdk_tns_config_sched_and_cutthru: TxQ Drop Request FIFO size exceeded!\n");
		return -1;
	}
	else
	{
		tdma_nb_dbg_config1.s.txq_drop_req_thresh = drop_req_thresh;
	}

	/*
	 * The flow of data from TDMA to RDMA along the internal loopback path is
	 * metered by credits.  Each credit represents the transfer of a 32-byte
	 * flit.  A maximum of 16 credits is allowed.  A minimum of 2 credits is
	 * required for proper operation.
	 */
	if ((lb_credits > 16) || (lb_credits < 2))
	{
		bdk_warn("bdk_tns_config_sched_and_cutthru: Loopback credits must 2 <= c <= 16\n");
		return -1;
	}
	else
	{
		tdma_nb_dbg_config1.s.lb_init_cdts = lb_credits;
	}
	/* Enable cut-thru towards NIC and LMAC */
	tdma_nb_dbg_config1.s.nic_cutthru_en = !!nic_on;
	tdma_nb_dbg_config1.s.lmac_cutthru_en = !!lmac_on;
	tdma_nb_dbg_config1.s.lb_cutthru_en = !!lb_on;

	BDK_CSR_WRITE(node, BDK_TNS_TDMA_NB_DBG_CONFIG1, tdma_nb_dbg_config1.u);
	/* bdk_wait_usec(10) */

	return 0;
}

/**
 * Designate the number of bytes which are considered part of the packet
 * header and will be extracted for processing by TNS.  Bytes received
 * after the header are considered part of the packet body.  Timestamp
 * bytes received from LMAC (if enabled) are not counted against the
 * header size.  Size are enumberated by TNS_RDMA_HDR_SZ_E.
 *
 * @param bdk_node_t node
 * @param tns_rdma_hdr_sz_e size
 *
 * @return Zero on success, negative on failure.
 */
static int bdk_tns_config_header_size(bdk_node_t node, uint8_t size)
{
	bdk_tns_rdma_nb_hdr_sz_cfg_t rdma_nb_hdr_sz_cfg;

	if (size >= TNS_RDMA_HDR_SZ_E_ENUM_LAST)
	{
		bdk_warn("bdk_tns_config_header_size: Illegal Header size was specified\n");
		return -1;
	}

	rdma_nb_hdr_sz_cfg.u = 0ULL;
	rdma_nb_hdr_sz_cfg.s.lmac0 = size;
	rdma_nb_hdr_sz_cfg.s.lmac1 = size;
	rdma_nb_hdr_sz_cfg.s.lmac2 = size;
	rdma_nb_hdr_sz_cfg.s.lmac3 = size;
	rdma_nb_hdr_sz_cfg.s.lmac4 = size;
	rdma_nb_hdr_sz_cfg.s.lmac5 = size;
	rdma_nb_hdr_sz_cfg.s.lmac6 = size;
	rdma_nb_hdr_sz_cfg.s.lmac7 = size;
	rdma_nb_hdr_sz_cfg.s.nici0 = size;
	rdma_nb_hdr_sz_cfg.s.nici1 = size;
	rdma_nb_hdr_sz_cfg.s.lb = size;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_HDR_SZ_CFG, rdma_nb_hdr_sz_cfg.u);
	/* bdk_wait_usec(10) */

	return 0;
}

/**
 * Initialize the DataPath Port Lookup tables.  Set each entry of these
 * tables to all ones.  Currently all ones are illegal ports for TNS.
 *
 * @param bdk_node_t node
 *
 * @return Nothing
 */
static void bdk_tns_init_pluts(bdk_node_t node)
{
	int i;
	bdk_tns_rdma_nb_lmac_plutx_t lmac_plut;
	bdk_tns_rdma_nb_nic_plutx_t nic_plut;
	bdk_tns_rdma_nb_loopback_plut_t lb_plut;
	bdk_tns_rdma_nb_lp_plutx_t fwd_plut;

	/* Initialize the LMAC PLUT Table */
	for (i = 0; i < TNS_MAX_LMAC_PLUT_ENTRIES; i++)
	{
		lmac_plut.u = 0ULL;
		lmac_plut.s.logical_port = TNS_LMAC_PLUT_ILLEGAL;
		BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_LMAC_PLUTX(i), lmac_plut.u);
		/* bdk_wait_usec(10) */
	}

	/* Initialize the NIC PLUT Table */
	for (i = 0; i < TNS_MAX_NIC_PLUT_ENTRIES; i++)
	{
		nic_plut.u = 0ULL;
		nic_plut.s.logical_port = TNS_NIC_PLUT_ILLEGAL;
		BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_NIC_PLUTX(i), nic_plut.u);
		/* bdk_wait_usec(10) */
	}

	/* Initialize the Forwarding PLUT Table */

	for (i = 0; i < TNS_MAX_FWD_PLUT_ENTRIES; i++)
	{
		fwd_plut.u = 0ULL;
		fwd_plut.s.physical_port = TNS_FWD_PLUT_ILLEGAL;
		BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_LP_PLUTX(i), fwd_plut.u);
		/* bdk_wait_usec(10) */
	}

	/* Initialize the Loopback PLUT Table */
	lb_plut.u = 0ULL;
	lb_plut.s.logical_port = TNS_LB_PLUT_ILLEGAL;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_LOOPBACK_PLUT, lb_plut.u);
	/* bdk_wait_usec(10) */
}

/**
 * Initialize the TNS block to handle packet processing (NON-BYPASS) mode.
 * TNS at power-up will be in BYPASS mode where packets from the vNIC pipes
 * to the BGx ports will be direct.  This is normally called automatically
 * in bdk-init-main.c.
 *
 * @param node Node to initialize
 *
 * @return Zero on success, negative on failure
 */
int bdk_tns_initialize(bdk_node_t node)
{
	int i;

	/* Receive DMA registers (BYPASS MODE) */
	bdk_tns_rdma_config_t rdma_config;
	bdk_tns_rdma_hdr_ts_cfg_t rdma_hdr_ts_cfg;

	/* Receive DMA registers (NON-BYPASS MODE) */
	bdk_tns_rdma_nb_path_enable_t rdma_nb_path_enable;
	bdk_tns_rdma_nb_config_t rdma_nb_config;
	bdk_tns_rdma_nb_lmacx_rpkt_sz_t rdma_lmac_rpkt_sz;
	bdk_tns_rdma_nb_nicix_rpkt_sz_t rdma_nb_nic_rpkt_sz;
	bdk_tns_rdma_nb_dbg_config_t rdma_nb_dbg_config;

	/* Transmit DMA registers (BYPASS MODE) */
	bdk_tns_tdma_cap_t tdma_cap;
	bdk_tns_tdma_config_t tdma_config;
	bdk_tns_tdma_reset_ctl_t tdma_reset_ctl;
	bdk_tns_tdma_lmacx_config_t tdma_lmac_cfg;

    /* Transmit DMA registers (NON-BYPASS MODE) */
	bdk_tns_tdma_nb_config1_t tdma_nb_config1;
	bdk_tns_tdma_nb_status_t tdma_nb_status;

	/* Only valid for the HW or HW emulator, ASIM doesn't support TNS */
	if (bdk_is_platform(BDK_PLATFORM_ASIM))
	{
		tns_enabled = 0;
		return -1;
	}

	/* Check if TNS is available */
	tdma_cap.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CAP);
	if (!tdma_cap.s.switch_capable)
	{
		bdk_warn("TNS is not available!\n");
		return -1; /* TNS is not available */
	}
	else
	{
		tns_enabled = tdma_cap.s.switch_capable;
	}

	/* TNS non-bypass initialization - Taken from Section 6.2.1.2 TNS Data Path RTL
	   Block Technical Specification. */

	/* 1. Verify no BIST errors */
	bdk_tns_check_bist(node);

	/* (not documented) Disable backpressure */
	rdma_config.u = 0ULL;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_CONFIG, rdma_config.u);
    bdk_wait_usec(10);

	/* (Mentioned in 6.2.1) Configure each LMAC with 512 credits in BYPASS mode */
	for (i = TNS_MIN_LMAC; i < (TNS_MIN_LMAC + TNS_MAX_LMACS); i++) {
		tdma_lmac_cfg.u = 0ULL;
		tdma_lmac_cfg.s.fifo_cdts = 0x200;
		BDK_CSR_WRITE(node, BDK_TNS_TDMA_LMACX_CONFIG(i), tdma_lmac_cfg.u);
		bdk_wait_usec(10);
	}

	/* 2. Enable the TNS Clocks and BYPASS mode */
	tdma_config.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CONFIG);
	tdma_config.s.bypass0_ena = 1;
	tdma_config.s.bypass1_ena = 1;
	tdma_config.s.clk_2x_ena = 1;
	tdma_config.s.clk_ena = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_CONFIG, tdma_config.u);

	/* 3. Enable CSR access (this allows us to talk to the rest of the TNS HW) */
	tdma_config.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CONFIG);
	tdma_config.s.csr_access_ena = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_CONFIG, tdma_config.u);

	/* 4. Clear TNS_TDMA_RESET_CTL */
	tdma_reset_ctl.u = 0ULL;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_RESET_CTL, tdma_reset_ctl.u);

	/* 5. Assume no timestamps at this time for packets arriving from LMAC */
	rdma_hdr_ts_cfg.u = 0ULL;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_HDR_TS_CFG, rdma_hdr_ts_cfg.u);

	/* 6 Configure PM_DEPTH, NICI1_PKND, NICI0_PKND, TXQ QMAP, TXQ EQ
	     PM_DEPTH = 0 (Use all of packet memory)
         NICI1_PKND = 0
         NICI0_PKND = 0
         TXQ QMAP = 0xffff (all available ports)
         TXQ EQ = 0xffff (all available ports) */
	tdma_nb_config1.u = 0ULL;
	tdma_nb_config1.s.txq_eq_link_up = 0xffff;
	tdma_nb_config1.s.txq_qmap_link_up = 0xffff;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_NB_CONFIG1, tdma_nb_config1.u);
	bdk_wait_usec(10);

    /* 7. Enable backpressure on all ports for NON-BYPASS mode and
          disable LMACs, NICs and Loopback */
	rdma_nb_path_enable.u = 0ULL;
	rdma_nb_path_enable.s.bgx0_bp = 1;
	rdma_nb_path_enable.s.bgx1_bp = 1;
	rdma_nb_path_enable.s.nici0_bp = 1;
	rdma_nb_path_enable.s.nici1_bp = 1;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_PATH_ENABLE, rdma_nb_path_enable.u);
	bdk_wait_usec(10);

	/* 8. Run auto-initialization */
	tdma_nb_config1.u = BDK_CSR_READ(node, BDK_TNS_TDMA_NB_CONFIG1);
	tdma_nb_config1.s.auto_init = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_NB_CONFIG1, tdma_nb_config1.u);

	/* 9. Wait for auto-initialization to complete */
	tdma_nb_status.u = BDK_CSR_READ(node, BDK_TNS_TDMA_NB_STATUS);
	while(tdma_nb_status.s.init_done != 1)
	{
		bdk_wait_usec(10);
		tdma_nb_status.u = BDK_CSR_READ(node, BDK_TNS_TDMA_NB_STATUS);
		/* TODO - Add a limit and fail if passed */
	}

	/* 10. Enable DataPath to receive packets from the physical ports */
    rdma_nb_path_enable.u = BDK_CSR_READ(node, BDK_TNS_RDMA_NB_PATH_ENABLE);
	rdma_nb_path_enable.s.lmac = 0xff;
	rdma_nb_path_enable.s.nici0 = 1;
	rdma_nb_path_enable.s.nici1 = 1;
	rdma_nb_path_enable.s.loopback = 1;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_PATH_ENABLE, rdma_nb_path_enable.u);
	bdk_wait_usec(10);

	/* 11. Enable TNS switch for receiving packets */
	rdma_nb_config.u = 0ULL;
	rdma_nb_config.s.master_en = 1;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_CONFIG, rdma_nb_config.u);
	bdk_wait_usec(10);

	/* 12. Enable TNS switch for sending packets allows packets to be stored in packet memory */
	tdma_nb_config1.u = BDK_CSR_READ(node, BDK_TNS_TDMA_NB_CONFIG1);
	tdma_nb_config1.s.master_en = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_NB_CONFIG1, tdma_nb_config1.u);
	bdk_wait_usec(10);

	/* 13-14 are done outside of TNS setup */

	/* 15-18. Initialize the PLUT table entries to all-ones */
	bdk_tns_init_pluts(node);

	/* 19. Set the number of bytes which are considered part of the the packet
	       header and will be extracted and passed on to the SDE for processing. */
	if (bdk_tns_config_header_size(node, TNS_RDMA_HDR_SZ_E_BYTES_64) < 0)
	{
		return -1;
	}

    /* 20. Clear (Disable) runt packet filtering for packets from LMAC */
	for (i = TNS_MIN_LMAC; i < (TNS_MIN_LMAC + TNS_MAX_LMACS); i++)
	{
		rdma_lmac_rpkt_sz.u = 0ULL;
		BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_LMACX_RPKT_SZ(i), rdma_lmac_rpkt_sz.u);
	}
	bdk_wait_usec(10);

	/* 21. Clear (Disable) runt packet filtering for packets from NIC */
	for (i = TNS_MIN_NIC; i < (TNS_MIN_NIC + TNS_MAX_NICS); i++)
	{
		rdma_nb_nic_rpkt_sz.u = 0ULL;
		BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_NICIX_RPKT_SZ((i-TNS_MIN_NIC)), rdma_nb_nic_rpkt_sz.u);
	}
	bdk_wait_usec(10);

	/* Set scheduling thresholds */
	if (bdk_tns_config_sched_and_cutthru(node, 0x04, 0x05, 0x04, 0x0c, 0x10, 1, 1, 0) < 0)
	{
		return -1;
	}

	/* Enable SDE receipt of packet errors for a single-page packet */
	rdma_nb_dbg_config.u = 0ULL;
	rdma_nb_dbg_config.s.body_ptr_error_value = 0x3ff; /* Must match SDE value */

	/* Set the level at which the SDMA will assert backpressure to the SDE */
	rdma_nb_dbg_config.s.sdma_fifo_bp = 0x08;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_NB_DBG_CONFIG, rdma_nb_dbg_config.u);
	bdk_wait_usec(10);

	/* Enable backpressure to physical ports */
	rdma_config.u = 0ULL;
	rdma_config.s.nici_bp_enable = 1;
    rdma_config.s.lmac_bp_enable = 1;
	BDK_CSR_WRITE(node, BDK_TNS_RDMA_CONFIG, rdma_config.u);
	bdk_wait_usec(10);

	/* 31. Disable Bypass, this effectively puts TNS into the traffic path */
	tdma_config.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CONFIG);
	tdma_config.s.bypass0_ena = 0;
	tdma_config.s.bypass1_ena = 0;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_CONFIG, tdma_config.u);
	bdk_wait_usec(10);

	return 0;
}

/**
 * Disable TNS from processing packets.  After this, TNS must be fully
 * initialized.  The NIC and BGX blocks must already be stopped before
 * calling this function.
 *
 * Nota Bene: In CN88XX_PASS_1 there is a bug that prevents TNS DataPath
 *            from draining packets.  So ensure that NIC and BGX have
 *            also drained their packet queues.
 *
 * @param node
 *
 * @return Zero on success, negative on failure
 */
int bdk_tns_shutdown(bdk_node_t node)
{
	if (tns_enabled)
	{
		/* 1. Stop packet traffic from entering TNS via NIC and BGX, this must
		      occur before calling this function. */
		/* 2. Drain packets from the TNS. */
		if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
		{
			/* TBD */
		}

		/* 3. Disable backpressure for BGX and NIC */
		BDK_CSR_MODIFY(c, node, BDK_TNS_RDMA_NB_PATH_ENABLE,
					   c.s.nici1_bp = 0;
					   c.s.nici0_bp = 0;
					   c.s.bgx1_bp = 0;
					   c.s.bgx0_bp = 0);
		bdk_wait_usec(10);

		/* 4. Enable Bypass mode */
		BDK_CSR_MODIFY(c, node, BDK_TNS_TDMA_CONFIG,
					   c.s.bypass1_ena = 1;
					   c.s.bypass0_ena = 1);
		bdk_wait_usec(10);

		/* 5. Disable TNS from transmitting packets */
		BDK_CSR_MODIFY(c, node, BDK_TNS_TDMA_NB_CONFIG1,
					   c.s.master_en = 0);

		/* 6. Disable TNS from receiving packets */
		BDK_CSR_MODIFY(c, node, BDK_TNS_RDMA_NB_CONFIG,
					   c.s.master_en = 0);

		/* 7. Force a reset of all TNS HW blocks */
		BDK_CSR_MODIFY(c, node, BDK_TNS_TDMA_RESET_CTL,
					   c.u = 0x000000FFFFFFFFFFULL);

		/* 8. Disable CSR access */
		BDK_CSR_MODIFY(c, node, BDK_TNS_TDMA_CONFIG,
					   c.s.csr_access_ena = 0);

		/* 9. Disable CLK2 and CLK */
		BDK_CSR_MODIFY(c, node, BDK_TNS_TDMA_CONFIG,
					   c.s.clk_2x_ena = 0;
					   c.s.clk_ena = 0);		
	}

	return 0;
}

/**
 * Write out a block of data to starting at 'address'.  We allow
 * an address to be specified instead of a register, so that we
 * can do bulk loads using the *SST* registers in the DataPath.
 *
 * @param node    Node to use in a Numa setup
 * @param address Register address to write to
 * @param *dataw  Array of 32-bit values. dataw[0] is bits[31:0].
 * @param cnt     Number of 32-bit entries in dataw
 *
 * @return Zero on success, negative on failure
 */
int bdk_tns_write_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt)
{
	bdk_tns_tdma_sst_acc_cmd_t acccmd;
	tns_acc_data_t data;
	int i, j, w = 0;

	/* If TNS is not available, punt! */
	if (!tns_enabled)
	{
		bdk_warn("TNS is not available!\n");
		return -1;
	}

	/*
	 * Validate the data
	 */
	if ((cnt <= 0) || (dataw == NULL)) {
		bdk_error("bdk_tns_write_data: Illegal count or invalid data array detected!\n");
		return -1;
	}

	/*
	 * Load the data first
	 */
	data.u = 0ULL;
	for (j = 0, i = 0; i < cnt; i++)
	{
		/* Odd words go in the upper 32 bits of the data register */
		if (i & 1)
		{
			data.s.upper32 = dataw[i];
			BDK_CSR_WRITE(node, BDK_TNS_TDMA_SST_ACC_WDATX(j), data.u);
			data.u = 0ULL;
			j++; /* Advance to the next data word */
			w = 0;
		}
		else
		{
			data.s.lower32 = dataw[i]; /* Lower 32 bits contain words 0, 2, 4, etc. */
			w = 1;
		}
	}

	/*
	 * If the last word was a partial (< 64 bits) then
	 * see if we need to write it.
	 */
	if (w)
	{
		BDK_CSR_WRITE(node, BDK_TNS_TDMA_SST_ACC_WDATX(j), data.u);
	}

	/*
	 * Build the Write command, op = 0 for writes
	 */
	acccmd.u = 0ULL;
	acccmd.s.go = 1; /* Cleared once the request is serviced */
	acccmd.s.size = cnt;
	acccmd.s.addr = address;

	/* Execute it */
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_SST_ACC_CMD, acccmd.u);

	return 0;
}

/**
 * Read in a block of data starting from 'address' for 'cnt' number of 
 * 32-bit words.  The caller must supply an array of 32-bit unsigned
 * values to store the data and the number of 32-bit words to read.
 *
 * @param node    Node to use in a Numa setup
 * @param address Register address to read from
 * @param *dataw  Array of 32-bit values.  dataw[0] will contain the bits[31:0], etc.
 * @param cnt     Number of 32-bit entries in dataw.
 *
 * @return Zero on success, negative on failure
 */
int bdk_tns_read_data(bdk_node_t node, uint32_t address, uint32_t *dataw, int cnt)
{
	bdk_tns_tdma_sst_acc_cmd_t acccmd;
	bdk_tns_tdma_sst_acc_stat_t accstat;
	tns_acc_data_t data;
	int i, j, dcnt;

	/* If TNS is not available, punt! */
	if (!tns_enabled)
	{
		bdk_warn("TNS is not available!\n");
		return -1;
	}

	/*
	 * Validate the data
	 */
	if ((cnt <= 0) || (dataw == NULL)) {
		bdk_error("bdk_tns_read_data: Illegal count or invalid data array detected!\n");
		return -1;
	}

	/* Construct the command */
	acccmd.u = 0ULL;
	acccmd.s.op = 1; /* Read operation */
	acccmd.s.size = cnt;
	acccmd.s.addr = address;
	acccmd.s.go = 1; /* Execute */

	BDK_CSR_WRITE(node, BDK_TNS_TDMA_SST_ACC_CMD, acccmd.u);

	/* Poll on accstat.s.cmd_done and accstat.s.error */
	accstat.u = 0ULL;
	while(!accstat.s.cmd_done && !accstat.s.error)
	{
		accstat.u = BDK_CSR_READ(node, BDK_TNS_TDMA_SST_ACC_STAT);
	}

	/* Check for error, and report it */
	if (accstat.s.error)
	{
		bdk_error("bdk_tns_read_data: Error reading data from 0x%08x\n", address);
		return -1;
	}

	/* Got data, move it into the array */
	dcnt = cnt / 2;
	if (cnt & 1) dcnt++;
	for (i = 0, j = 0; (j < dcnt) && (i < cnt); j++)
	{
		data.u = BDK_CSR_READ(node, BDK_TNS_TDMA_SST_ACC_RDATX(j));
		dataw[i++] = data.s.lower32;
		if (i < cnt)
		{
			dataw[i++] = data.s.upper32;
		}
	}

    return 0;
}

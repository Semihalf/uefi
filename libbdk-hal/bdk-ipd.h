/**
 * @file
 *
 * Interface to the hardware Input Packet Data unit.
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef enum {
   BDK_IPD_OPC_MODE_STT = 0LL,   /* All blocks DRAM, not cached in L2 */
   BDK_IPD_OPC_MODE_STF = 1LL,   /* All blocks into L2 */
   BDK_IPD_OPC_MODE_STF1_STT = 2LL,   /* 1st block L2, rest DRAM */
   BDK_IPD_OPC_MODE_STF2_STT = 3LL    /* 1st, 2nd blocks L2, rest DRAM */
} bdk_ipd_mode_t;


/**
 * Configure IPD
 *
 * @param mbuff_size Packets buffer size in 8 byte words
 * @param first_mbuff_skip
 *                   Number of 8 byte words to skip in the first buffer
 * @param not_first_mbuff_skip
 *                   Number of 8 byte words to skip in each following buffer
 * @param first_back Must be same as first_mbuff_skip / 128
 * @param second_back
 *                   Must be same as not_first_mbuff_skip / 128
 * @param wqe_fpa_pool
 *                   FPA pool to get work entries from
 * @param cache_mode
 * @param back_pres_enable_flag
 *                   Enable or disable port back pressure at a global level.
 *                   This should always be 1 as more accurate control can be
 *                   found in IPD_PORTX_BP_PAGE_CNT[BP_ENB].
 */
static inline void bdk_ipd_config(uint64_t mbuff_size,
                                   uint64_t first_mbuff_skip,
                                   uint64_t not_first_mbuff_skip,
                                   uint64_t first_back,
                                   uint64_t second_back,
                                   uint64_t wqe_fpa_pool,
                                   bdk_ipd_mode_t cache_mode,
                                   uint64_t back_pres_enable_flag
                                  )
{
    bdk_ipd_1st_mbuff_skip_t first_skip;
    bdk_ipd_not_1st_mbuff_skip_t not_first_skip;
    bdk_ipd_packet_mbuff_size_t size;
    bdk_ipd_1st_next_ptr_back_t first_back_struct;
    bdk_ipd_2nd_next_ptr_back_t second_back_struct;
    bdk_ipd_wqe_fpa_queue_t wqe_pool;
    bdk_ipd_ctl_status_t ipd_ctl_reg;

    first_skip.u64 = 0;
    first_skip.s.skip_sz = first_mbuff_skip;
    BDK_CSR_WRITE(BDK_IPD_1ST_MBUFF_SKIP, first_skip.u64);

    not_first_skip.u64 = 0;
    not_first_skip.s.skip_sz = not_first_mbuff_skip;
    BDK_CSR_WRITE(BDK_IPD_NOT_1ST_MBUFF_SKIP, not_first_skip.u64);

    size.u64 = 0;
    size.s.mb_size = mbuff_size;
    BDK_CSR_WRITE(BDK_IPD_PACKET_MBUFF_SIZE, size.u64);

    first_back_struct.u64 = 0;
    first_back_struct.s.back = first_back;
    BDK_CSR_WRITE(BDK_IPD_1ST_NEXT_PTR_BACK, first_back_struct.u64);

    second_back_struct.u64 = 0;
    second_back_struct.s.back = second_back;
    BDK_CSR_WRITE(BDK_IPD_2ND_NEXT_PTR_BACK,second_back_struct.u64);

    wqe_pool.u64 = 0;
    wqe_pool.s.wqe_pool = wqe_fpa_pool;
    BDK_CSR_WRITE(BDK_IPD_WQE_FPA_QUEUE, wqe_pool.u64);

    ipd_ctl_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_ctl_reg.s.opc_mode = cache_mode;
    ipd_ctl_reg.s.pbp_en = back_pres_enable_flag;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_ctl_reg.u64);

    /* Note: the example RED code that used to be here has been moved to
        bdk_helper_setup_red */
}


/**
 * Enable IPD
 */
static inline void bdk_ipd_enable(void)
{
    bdk_ipd_ctl_status_t ipd_reg;
    ipd_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    if (ipd_reg.s.ipd_en)
    {
        bdk_dprintf("Warning: Enabling IPD when IPD already enabled.\n");
    }
    ipd_reg.s.ipd_en = 1;
    ipd_reg.s.len_m8 = 1;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_reg.u64);
}


/**
 * Disable IPD
 */
static inline void bdk_ipd_disable(void)
{
    bdk_ipd_ctl_status_t ipd_reg;
    ipd_reg.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
    ipd_reg.s.ipd_en = 0;
    BDK_CSR_WRITE(BDK_IPD_CTL_STATUS, ipd_reg.u64);
}

/**
 * @INTERNAL
 * This function is called by bdk_helper_shutdown() to extract
 * all FPA buffers out of the IPD and PIP. After this function
 * completes, all FPA buffers that were prefetched by IPD and PIP
 * wil be in the apropriate FPA pool. This functions does not reset
 * PIP or IPD as FPA pool zero must be empty before the reset can
 * be performed. WARNING: It is very important that IPD and PIP be
 * reset soon after a call to this function.
 */
static inline void __bdk_ipd_free_ptr(void)
{
    /* Only CN38XXp{1,2} cannot read pointer out of the IPD */
    if (1) {
	int no_wptr = 0;
	bdk_ipd_ptr_count_t ipd_ptr_count;
	ipd_ptr_count.u64 = BDK_CSR_READ(BDK_IPD_PTR_COUNT);

	/* Handle Work Queue Entry in cn56xx and cn52xx */
	if (octeon_has_feature(OCTEON_FEATURE_NO_WPTR)) {
	    bdk_ipd_ctl_status_t ipd_ctl_status;
	    ipd_ctl_status.u64 = BDK_CSR_READ(BDK_IPD_CTL_STATUS);
	    if (ipd_ctl_status.s.no_wptr)
		no_wptr = 1;
	}

	/* Free the prefetched WQE */
	if (ipd_ptr_count.s.wqev_cnt) {
	    bdk_ipd_wqe_ptr_valid_t ipd_wqe_ptr_valid;
	    ipd_wqe_ptr_valid.u64 = BDK_CSR_READ(BDK_IPD_WQE_PTR_VALID);
	    if (no_wptr)
	        bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_wqe_ptr_valid.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
	    else
	        bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_wqe_ptr_valid.s.ptr<<7), BDK_FPA_WQE_POOL, 0);
	}

	/* Free all WQE in the fifo */
	if (ipd_ptr_count.s.wqe_pcnt) {
	    int i;
	    bdk_ipd_pwp_ptr_fifo_ctl_t ipd_pwp_ptr_fifo_ctl;
	    ipd_pwp_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PWP_PTR_FIFO_CTL);
	    for (i = 0; i < ipd_ptr_count.s.wqe_pcnt; i++) {
		ipd_pwp_ptr_fifo_ctl.s.cena = 0;
		ipd_pwp_ptr_fifo_ctl.s.raddr = ipd_pwp_ptr_fifo_ctl.s.max_cnts + (ipd_pwp_ptr_fifo_ctl.s.wraddr+i) % ipd_pwp_ptr_fifo_ctl.s.max_cnts;
		BDK_CSR_WRITE(BDK_IPD_PWP_PTR_FIFO_CTL, ipd_pwp_ptr_fifo_ctl.u64);
		ipd_pwp_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PWP_PTR_FIFO_CTL);
		if (no_wptr)
		    bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_pwp_ptr_fifo_ctl.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
		else
		    bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_pwp_ptr_fifo_ctl.s.ptr<<7), BDK_FPA_WQE_POOL, 0);
	    }
	    ipd_pwp_ptr_fifo_ctl.s.cena = 1;
	    BDK_CSR_WRITE(BDK_IPD_PWP_PTR_FIFO_CTL, ipd_pwp_ptr_fifo_ctl.u64);
	}

	/* Free the prefetched packet */
	if (ipd_ptr_count.s.pktv_cnt) {
	    bdk_ipd_pkt_ptr_valid_t ipd_pkt_ptr_valid;
	    ipd_pkt_ptr_valid.u64 = BDK_CSR_READ(BDK_IPD_PKT_PTR_VALID);
	    bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_pkt_ptr_valid.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
	}

	/* Free the per port prefetched packets */
	if (1) {
	    int i;
	    bdk_ipd_prc_port_ptr_fifo_ctl_t ipd_prc_port_ptr_fifo_ctl;
	    ipd_prc_port_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PRC_PORT_PTR_FIFO_CTL);

	    for (i = 0; i < ipd_prc_port_ptr_fifo_ctl.s.max_pkt; i++) {
		ipd_prc_port_ptr_fifo_ctl.s.cena = 0;
		ipd_prc_port_ptr_fifo_ctl.s.raddr = i % ipd_prc_port_ptr_fifo_ctl.s.max_pkt;
		BDK_CSR_WRITE(BDK_IPD_PRC_PORT_PTR_FIFO_CTL, ipd_prc_port_ptr_fifo_ctl.u64);
		ipd_prc_port_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PRC_PORT_PTR_FIFO_CTL);
		bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_prc_port_ptr_fifo_ctl.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
	    }
	    ipd_prc_port_ptr_fifo_ctl.s.cena = 1;
	    BDK_CSR_WRITE(BDK_IPD_PRC_PORT_PTR_FIFO_CTL, ipd_prc_port_ptr_fifo_ctl.u64);
	}

	/* Free all packets in the holding fifo */
	if (ipd_ptr_count.s.pfif_cnt) {
	    int i;
	    bdk_ipd_prc_hold_ptr_fifo_ctl_t ipd_prc_hold_ptr_fifo_ctl;

	    ipd_prc_hold_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PRC_HOLD_PTR_FIFO_CTL);

	    for (i = 0; i < ipd_ptr_count.s.pfif_cnt; i++) {
		ipd_prc_hold_ptr_fifo_ctl.s.cena = 0;
		ipd_prc_hold_ptr_fifo_ctl.s.raddr = (ipd_prc_hold_ptr_fifo_ctl.s.praddr + i) % ipd_prc_hold_ptr_fifo_ctl.s.max_pkt;
		BDK_CSR_WRITE(BDK_IPD_PRC_HOLD_PTR_FIFO_CTL, ipd_prc_hold_ptr_fifo_ctl.u64);
		ipd_prc_hold_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PRC_HOLD_PTR_FIFO_CTL);
		bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_prc_hold_ptr_fifo_ctl.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
	    }
	    ipd_prc_hold_ptr_fifo_ctl.s.cena = 1;
	    BDK_CSR_WRITE(BDK_IPD_PRC_HOLD_PTR_FIFO_CTL, ipd_prc_hold_ptr_fifo_ctl.u64);
	}

	/* Free all packets in the fifo */
	if (ipd_ptr_count.s.pkt_pcnt) {
	    int i;
	    bdk_ipd_pwp_ptr_fifo_ctl_t ipd_pwp_ptr_fifo_ctl;
	    ipd_pwp_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PWP_PTR_FIFO_CTL);

	    for (i = 0; i < ipd_ptr_count.s.pkt_pcnt; i++) {
		ipd_pwp_ptr_fifo_ctl.s.cena = 0;
		ipd_pwp_ptr_fifo_ctl.s.raddr = (ipd_pwp_ptr_fifo_ctl.s.praddr+i) % ipd_pwp_ptr_fifo_ctl.s.max_cnts;
		BDK_CSR_WRITE(BDK_IPD_PWP_PTR_FIFO_CTL, ipd_pwp_ptr_fifo_ctl.u64);
		ipd_pwp_ptr_fifo_ctl.u64 = BDK_CSR_READ(BDK_IPD_PWP_PTR_FIFO_CTL);
		bdk_fpa_free(bdk_phys_to_ptr((uint64_t)ipd_pwp_ptr_fifo_ctl.s.ptr<<7), BDK_FPA_PACKET_POOL, 0);
	    }
	    ipd_pwp_ptr_fifo_ctl.s.cena = 1;
	    BDK_CSR_WRITE(BDK_IPD_PWP_PTR_FIFO_CTL, ipd_pwp_ptr_fifo_ctl.u64);
	}
    }
}


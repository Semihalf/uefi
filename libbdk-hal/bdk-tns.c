#include <bdk.h>

/* This code is an optional part of the BDK.  It is only linked in 
   if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(TNS);

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
 * Initialize the TNS block to handle packet processing (NON-BYPASS) mode.
 * TNS at power-up will be in BYPASS mode where packets from the vNIC pipes
 * to the BGx ports will be direct.  This is normally called automatically
 * in bdk-init-main.c.
 *
 * Initialization Sequence
 *
 *    1. Check that TNS is available by checking that TDMA_CAP[SWITCH_CAPABLE]
 *       is 1.
 *
 *    2. Verify BIST0-BIST11 contain no boot initialization errors.
 *
 *    3. Enable the TNS clocks in TNS_TDMA_CONFIG.
 *
 *    4. Enable CSR access in TNS_TDMA_CONFIG.
 *
 *    5. Clear TNS_TDMA_RESET_CTL.
 *
 * @return Zero on success, negative on failure
 */
int bdk_tns_initialize(bdk_node_t node)
{
	bdk_tns_tdma_cap_t tdma_cap;
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
	bdk_tns_tdma_config_t tdma_config;
	bdk_tns_tdma_reset_ctl_t tdma_reset_ctl;

/* Only valid for the HW emulator, ASIM doesn't support */
#if defined(HW_EMULATOR)
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

	/* Verify no BIST errors */

#define BDK_TNS_REG_NAME(r) basename_##r
	/* BIST 0 */
	bist_status.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS);
	if (bist_status.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST0 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS), bist_status.u);
	}
	/* BIST 1 */
	bist_status1.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS1);
	if (bist_status1.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST1 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS1), bist_status1.u);
	}
	/* BIST 2 */
	bist_status2.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS2);
	if (bist_status2.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST2 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS2), bist_status2.u);
	}
	/* BIST 3 */
	bist_status3.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS3);
	if (bist_status3.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST3 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS3), bist_status3.u);
	}
	/* BIST 4 */
	bist_status4.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS4);
	if (bist_status4.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST4 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS4), bist_status4.u);
	}
	/* BIST 5 */
	bist_status5.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS5);
	if (bist_status5.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST5 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS5), bist_status5.u);
	}
	/* BIST 6 */
	bist_status6.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS6);
	if (bist_status6.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST6 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS6), bist_status6.u);
	}
	/* BIST 7 */
	bist_status7.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS7);
	if (bist_status7.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST7 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS7), bist_status7.u);
	}
	/* BIST 8 */
	bist_status8.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS8);
	if (bist_status8.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST8 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS8), bist_status8.u);
		return -1;
	}
	/* BIST 9 */
	bist_status9.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS9);
	if (bist_status9.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST9 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS9), bist_status9.u);
	}
	/* BIST 10 */
	bist_status10.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS10);
	if (bist_status10.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST10 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS10), bist_status10.u);
		return -1;
	}
	/* BIST 11 */
	bist_status11.u = BDK_CSR_READ(node, BDK_TNS_BIST_STATUS11);
	if (bist_status11.u != 0ULL)
	{
		bdk_warn("bdk_tns_initialize: BIST11 failures\n");
		bdk_csr_decode(BDK_TNS_REG_NAME(BDK_TNS_BIST_STATUS11), bist_status11.u);
	}
#undef BDK_TNS_REG_NAME

	/* Enable the TNS Clocks */
	tdma_config.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CONFIG);
	tdma_config.s.clk_2x_ena = 1;
	tdma_config.s.clk_ena = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_CONFIG, tdma_config.u);

	/* Enable CSR access (this allows us to talk to the rest of the TNS HW) */
	tdma_config.u = BDK_CSR_READ(node, BDK_TNS_TDMA_CONFIG);
	tdma_config.s.csr_access_ena = 1;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_CONFIG, tdma_config.u);

	/* Clear TNS_TDMA_RESET_CTL */
	tdma_reset_ctl.u = 0ULL;
	BDK_CSR_WRITE(node, BDK_TNS_TDMA_RESET_CTL, tdma_reset_ctl.u);
#else
	/* REMOVE IF/WHEN Asim has TNS support */
	bdk_warn("bdk_tns_initialize: TNS only works on the HW Emulator!\n");
#endif

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
		bdk_error("TNS is not available!\n");
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
		bdk_error("TNS is not available!\n");
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

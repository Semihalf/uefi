#include <bdk.h>
#include "dram-internal.h"

#define RLEXTRAS_PATCH     1 // write to unused RL rank entries
#define ADD_48_OHM_SKIP    1
#define NOSKIP_40_48_OHM   1
#define MAJORITY_OVER_AVG  1

#define DEFAULT_BEST_RANK_SCORE  9999999
#define MAX_RANK_SCORE_LIMIT     99 // FIXME? 

#define DEBUG_VALIDATE_BITMASK 0
#if DEBUG_VALIDATE_BITMASK
#define debug_bitmask_print printf
#else
#define debug_bitmask_print(...)
#endif

#define DEBUG_EXTRA_PRINTS 1
#undef DEBUG_EXTRA_PRINT_LOOP

#if DEBUG_EXTRA_PRINTS
#define extra_ddr_print ddr_print
#else
#define extra_ddr_print(...)
#endif

#define RUN_INIT_SEQ_1      1
#define RUN_INIT_SEQ_2      0
#define RUN_INIT_SEQ_3      0

#define ENABLE_LOCK_RETRIES
#define DEFAULT_LOCK_RETRIES  5 // FIXME: is this enough? too much?

#undef ENABLE_SLOT_CTL_ACCESS
#undef ENABLE_CUSTOM_RLEVEL_TABLE

#define ENABLE_DISPLAY_MPR_PAGE 0
#if ENABLE_DISPLAY_MPR_PAGE
static void Display_MPR_Page_Location(bdk_node_t node, int rank,
                                      int ddr_interface_num, int dimm_count,
                                      int page, int location, uint64_t *mpr_data);
#endif

/* Read out Deskew Settings for DDR */

typedef struct {
    int saturated;
    int unlocked;
    int nibble_errs;
} deskew_counts_t;

deskew_counts_t deskew_training_results;

static void Validate_Deskew_Training(bdk_node_t node, int rank_mask, int ddr_interface_num,
                                     deskew_counts_t *counts, int print_enable)
{
    bdk_lmcx_phy_ctl_t phy_ctl;
    int byte_lane, bit_num;
    bdk_lmcx_config_t  lmc_config;
    uint8_t dsk_bytes[9];
    uint8_t dsk_min, dsk_max, dsk_bad;
    int c;
    
    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));

    counts->saturated = 0;
    counts->unlocked    = 0;
    counts->nibble_errs  = 0;

    BDK_CSR_MODIFY(phy_ctl, node, BDK_LMCX_PHY_CTL(ddr_interface_num),
                   phy_ctl.s.dsk_dbg_clk_scaler = 3);

    if (print_enable) {
        ddr_print("N%d.LMC%d: Deskew Settings:          Bit =>         :",
		  node, ddr_interface_num);
	for (bit_num = 8; bit_num >= 0; --bit_num) {
	    if (bit_num != 4)
		ddr_print(" %3d  ", (bit_num > 4) ? bit_num - 1 : bit_num);
	}
        ddr_print("\n");
    }
    for (byte_lane = 0; byte_lane < 8+lmc_config.s.ecc_ena; byte_lane++){
        if (print_enable)
            ddr_print("N%d.LMC%d: Bit Deskew Byte %d                        :",
                      node, ddr_interface_num, byte_lane);
        for (bit_num = 8; bit_num >= 0; --bit_num){
            if (bit_num == 4) continue;

            //set byte lane and bit to read
            BDK_CSR_MODIFY(phy_ctl, node, BDK_LMCX_PHY_CTL(ddr_interface_num),
                           (phy_ctl.s.dsk_dbg_bit_sel = bit_num,
                            phy_ctl.s.dsk_dbg_byte_sel = byte_lane));
            //start read sequence
            BDK_CSR_MODIFY(phy_ctl, node, BDK_LMCX_PHY_CTL(ddr_interface_num),
                           phy_ctl.s.dsk_dbg_rd_start = 1);
            //poll for read sequence to complete
            do {
                phy_ctl.u = BDK_CSR_READ(node, BDK_LMCX_PHY_CTL(ddr_interface_num));
            } while (phy_ctl.s.dsk_dbg_rd_complete != 1);
			
	    int flags = phy_ctl.s.dsk_dbg_rd_data & 7;
	    int deskew = phy_ctl.s.dsk_dbg_rd_data >> 3;

            c = ' ';
            if (flags & 0x4) {
                c = '+';        /* Saturated High */
                ++counts->saturated;
            }
            if (flags & 0x2) {
                c = '-';        /* Saturated Low */
                ++counts->saturated;
            }
            if (! (flags & 0x1)) {
                c = '?';        /* Failed to Lock */
                ++counts->unlocked;
            }
	    dsk_bytes[bit_num] = deskew;

            if (print_enable)
                ddr_print(" %3d %c", deskew, c);
        } /* for (bit_num = 8; bit_num >= 0; --bit_num) */

	// now look for nibble errors
	/*
	  For bit 55, it looks like a bit deskew problem. When the upper nibble of byte 6 
	   needs to go to saturation, bit7 of byte 6 lock prematurely at 64.
	  For DIMMs with raw card A and B, can we reset the deskew training when we encounter this case?
	  The reset criteria should be looking at one nibble at a time for raw card A and B;
	  if the bit-deskew setting within a nibble is differed > 33, we'll issue a reset
	  to the bit deskew training.

	  LMC0 Bit Deskew Byte(6): 64 0 - 0 - 0 - 26 61 35 64 
	*/
	dsk_bad = 0;

	// upper nibble
	dsk_min = 127; dsk_max = 0;
        for (bit_num = 8; bit_num >= 5; --bit_num) {
	    dsk_min = min(dsk_bytes[bit_num], dsk_min);
	    dsk_max = max(dsk_bytes[bit_num], dsk_max);
        }
	dsk_bad += ((dsk_max - dsk_min) > 33) ? 1 : 0;

	// lower nibble
	dsk_min = 127; dsk_max = 0;
        for (bit_num = 3; bit_num >= 0; --bit_num) {
	    dsk_min = min(dsk_bytes[bit_num], dsk_min);
	    dsk_max = max(dsk_bytes[bit_num], dsk_max);
        }
	dsk_bad += ((dsk_max - dsk_min) > 33) ? 1 : 0;

	if ((dsk_bad > 0) && print_enable)
	    ddr_print(" @");

	counts->nibble_errs += dsk_bad;

        if (print_enable)
            ddr_print("\n");
    } /* for (byte_lane = 0; byte_lane < 8+lmc_config.s.ecc_ena; byte_lane++) */
	
    return;
}

#define DEFAULT_SAT_RETRY_LIMIT  11    // 1 + 10 retries
#define DEFAULT_LOCK_RETRY_LIMIT 10    // 10 retries
#define PRINT_RETRY_LIMIT         0    // make equal to sat_retry_limit if you want all of them

static void perform_LMC_Deskew_Training(bdk_node_t node, int rank_mask, int ddr_interface_num, int spd_rawcard)
{
    int unsaturated, locked;
    int sat_retries, lock_retries;
    int do_print;
    deskew_counts_t dsk_counts;

    ddr_print("N%d.LMC%d: Performing Deskew Training.\n", node, ddr_interface_num);

    sat_retries = 0;
    unsaturated = 0;

    do { /* while (sat_retries < sat_retry_limit) */

        /*
         * 4.8.8 LMC Deskew Training
         * 
         * LMC requires input-read-data deskew training.
         * 
         * 1. Write LMC(0)_EXT_CONFIG[VREFINT_SEQ_DESKEW] = 1.
         */
	ddr_seq_print("Performing LMC sequence: Set vrefint_seq_deskew = 1\n");
        DRAM_CSR_MODIFY(ext_config, node, BDK_LMCX_EXT_CONFIG(ddr_interface_num),
			ext_config.s.vrefint_seq_deskew = 1); /* Set Deskew sequence */

        /*
         * 2. Write LMC(0)_SEQ_CTL[SEQ_SEL] = 0x0A and
         *    LMC(0)_SEQ_CTL[INIT_START] = 1.
         * 
         * 3. Wait for LMC(0)_SEQ_CTL[SEQ_COMPLETE] to be set to 1.
         */
        DRAM_CSR_MODIFY(phy_ctl, node, BDK_LMCX_PHY_CTL(ddr_interface_num),
			phy_ctl.s.phy_dsk_reset = 1); /* Reset Deskew sequence */
        perform_octeon3_ddr3_sequence(node, rank_mask, ddr_interface_num, 0x0A); /* LMC Deskew Training */

        Validate_Deskew_Training(node, rank_mask, ddr_interface_num, &dsk_counts, 0);

	lock_retries = 0;

    perform_deskew_training:
        DRAM_CSR_MODIFY(phy_ctl, node, BDK_LMCX_PHY_CTL(ddr_interface_num),
			phy_ctl.s.phy_dsk_reset = 0);
        perform_octeon3_ddr3_sequence(node, rank_mask, ddr_interface_num, 0x0A); /* LMC Deskew Training */

	do_print = 0;
	if (1/*(sat_retries <= PRINT_RETRY_LIMIT) && (lock_retries == 0)*/) {
	    ddr_print("N%d.LMC%d: Deskew Training: retry %d/%d: Training Results.\n",
		      node, ddr_interface_num, sat_retries, lock_retries);
	    do_print = 1;
	}

        Validate_Deskew_Training(node, rank_mask, ddr_interface_num, &dsk_counts, do_print);

        unsaturated = (dsk_counts.saturated == 0);
	locked = (dsk_counts.unlocked == 0);

	/*
	 * At this point, check for a DDR4 RDIMM that will not benefit from retries; if so, exit loop
	 */
	// RAW CARD must be bit 7=0 and bits 4-0 either 00000 or 00001 for this to be true 
	if (spd_rawcard) { // 
	    ddr_print("N%d.LMC%d: Deskew Training Loop: Exiting for RAWCARD == A|B.\n",
		      node, ddr_interface_num);
	    break; // no sat or lock retries
	}

#ifdef ENABLE_LOCK_RETRIES

	if (unsaturated) { // only do locking retries if unsaturated, otherwise full SAT retry
	    if (!locked) { // and not locked
		lock_retries++;
		if (lock_retries <= DEFAULT_LOCK_RETRY_LIMIT) {
		    goto perform_deskew_training;
		} else {
		    ddr_print("N%d.LMC%d: LOCK RETRIES failed after %d retries\n",
			      node, ddr_interface_num, DEFAULT_LOCK_RETRY_LIMIT);
		}
	    } else {
		ddr_print("N%d.LMC%d: LOCK RETRIES successful after %d retries\n",
			  node, ddr_interface_num, lock_retries);
	    }
	} /* if (unsaturated) */

#endif /* ENABLE_LOCK_RETRIES */

        ++sat_retries;

    } while (!unsaturated && (sat_retries < DEFAULT_SAT_RETRY_LIMIT));

    ddr_print("N%d.LMC%d: Deskew Training %s. %d retries\n", node, ddr_interface_num,
              (sat_retries >= DEFAULT_SAT_RETRY_LIMIT) ? "Timed Out" : "Completed", sat_retries-1);

    // NOTE: we (currently) always print one last training validation before starting Read Leveling... 
}

#define SCALING_FACTOR (1000)
static int compute_Vref_1slot_2rank(int rtt_wr, int rtt_park, int dqx_ctl)
{
    uint64_t Reff_s;
    uint64_t Rser_s = 15;
    uint64_t Vdd = 1200;
    uint64_t Vref;
    //uint64_t Vl;
    uint64_t rtt_wr_s = (rtt_wr == 0 ? 1*1024*1024 : rtt_wr);
    uint64_t rtt_park_s = (rtt_park == 0 ? 1*1024*1024 : rtt_park);
    uint64_t dqx_ctl_s = (dqx_ctl == 0 ? 1*1024*1024 : dqx_ctl);
    int Vref_value;
    uint64_t Rangepc = 6000; // range1 base
    uint64_t Vrefpc;
    int Vref_range = 0;

    //printf("rtt_wr = %d, rtt_park = %d, dqx_ctl = %d\n", rtt_wr, rtt_park, dqx_ctl);
    //printf("rtt_wr_s = %d, rtt_park_s = %d, dqx_ctl_s = %d\n", rtt_wr_s, rtt_park_s, dqx_ctl_s);

    Reff_s = divide_nint((rtt_wr_s * rtt_park_s) , (rtt_wr_s + rtt_park_s));
    //printf("Reff_s = %d\n", Reff_s);

    //Vl = (((Rser_s + dqx_ctl_s) * SCALING_FACTOR) / (Rser_s + dqx_ctl_s + Reff_s)) * Vdd / SCALING_FACTOR;
    //printf("Vl = %d\n", Vl);

    Vref = (((Rser_s + dqx_ctl_s) * SCALING_FACTOR) / (Rser_s + dqx_ctl_s + Reff_s)) + SCALING_FACTOR;
    //printf("Vref = %d\n", Vref);

    Vref = (Vref * Vdd) / 2 / SCALING_FACTOR;
    //printf("Vref = %d\n", Vref);

    Vrefpc = (Vref * 100 * 100) / Vdd;
    //printf("Vrefpc = %d\n", Vrefpc);

    if (Vrefpc < Rangepc) { // < range1 base, use range2
	Vref_range = 1 << 6; // set bit A6 for range2
	Rangepc = 4500; // range2 base is 45%
    }

    Vref_value = divide_nint(Vrefpc - Rangepc, 65);
    if (Vref_value < 0)
	Vref_value = Vref_range; // set to base of range
    else
	Vref_value |= Vref_range;
    //printf("Vref_value = %d (0x%02x)\n", Vref_value, Vref_value);

    debug_print("rtt_wr:%d, rtt_park:%d, dqx_ctl:%d, Vref_value:%d (0x%x)\n",
           rtt_wr, rtt_park, dqx_ctl, Vref_value, Vref_value);

    return Vref_value;
}
static int compute_Vref_2slot_2rank(int rtt_wr, int rtt_park, int dqx_ctl, int rtt_nom)
{
    //uint64_t Rser = 15;
    uint64_t Vdd = 1200;
    //uint64_t Vref;
    uint64_t Vl, Vlp, Vcm;
    uint64_t Rd0, Rd1, Rpullup;
    uint64_t rtt_wr_s = (rtt_wr == 0 ? 1*1024*1024 : rtt_wr);
    uint64_t rtt_park_s = (rtt_park == 0 ? 1*1024*1024 : rtt_park);
    uint64_t dqx_ctl_s = (dqx_ctl == 0 ? 1*1024*1024 : dqx_ctl);
    uint64_t rtt_nom_s = (rtt_nom == 0 ? 1*1024*1024 : rtt_nom);
    int Vref_value;
    uint64_t Rangepc = 6000; // range1 base
    uint64_t Vrefpc;
    int Vref_range = 0;

    // Rd0 = (RTT_NOM /*parallel*/ RTT_WR) + 15 = ((RTT_NOM * RTT_WR) / (RTT_NOM + RTT_WR)) + 15
    Rd0 = divide_nint((rtt_nom_s * rtt_wr_s), (rtt_nom_s + rtt_wr_s)) + 15;
    //printf("Rd0 = %ld\n", Rd0);

    // Rd1 = (RTT_PARK / 2) + 15
    Rd1 = (rtt_park_s / 2) + 15;
    //printf("Rd1 = %ld\n", Rd1);

    // Rpullup = Rd0 /*parallel*/ Rd1 = (Rd0 * Rd1) / (Rd0 + Rd1)
    Rpullup = divide_nint((Rd0 * Rd1), (Rd0 + Rd1));
    //printf("Rpullup = %ld\n", Rpullup);

    // Vl = (DQX_CTL / (DQX_CTL + Rpullup)) * 1.2
    Vl = divide_nint((dqx_ctl_s * Vdd), (dqx_ctl_s + Rpullup));
    //printf("Vl = %ld\n", Vl);

    // Vlp = ((15 / Rd0) * (1.2 - Vl)) + Vl
    Vlp = divide_nint((15 * (Vdd - Vl)), Rd0) + Vl;
    //printf("Vlp = %ld\n", Vlp);

    // Vcm = (Vlp + 1.2) / 2
    Vcm = divide_nint((Vlp + Vdd), 2);
    //printf("Vcm = %ld\n", Vcm);

    // Vrefpc = (Vcm / 1.2) * 100
    Vrefpc = divide_nint((Vcm * 100 * 100), Vdd);
    //printf("Vrefpc = %ld\n", Vrefpc);

    if (Vrefpc < Rangepc) { // < range1 base, use range2
	Vref_range = 1 << 6; // set bit A6 for range2
	Rangepc = 4500; // range2 base is 45%
    }

    Vref_value = divide_nint(Vrefpc - Rangepc, 65);
    if (Vref_value < 0)
	Vref_value = Vref_range; // set to base of range
    else
	Vref_value |= Vref_range;
    //printf("Vref_value = %d (0x%02x)\n", Vref_value, Vref_value);

    debug_print("rtt_wr:%d, rtt_park:%d, dqx_ctl:%d, rtt_nom:%d, Vref_value:%d (0x%x)\n",
		rtt_wr, rtt_park, dqx_ctl, rtt_nom, Vref_value, Vref_value);

    return Vref_value;
}

static int encode_row_lsb_ddr3(int row_lsb, int ddr_interface_wide)
{
    int encoded_row_lsb;
    int row_lsb_start = 14;

    /*  Decoding for row_lsb             */
    /*       000: row_lsb = mem_adr[14]  */
    /*       001: row_lsb = mem_adr[15]  */
    /*       010: row_lsb = mem_adr[16]  */
    /*       011: row_lsb = mem_adr[17]  */
    /*       100: row_lsb = mem_adr[18]  */
    /*       101: row_lsb = mem_adr[19]  */
    /*       110: row_lsb = mem_adr[20]  */
    /*       111: RESERVED               */

    row_lsb_start = 14;

    encoded_row_lsb      = row_lsb - row_lsb_start ;

    return encoded_row_lsb;
}

static int encode_pbank_lsb_ddr3(int pbank_lsb, int ddr_interface_wide)
{
    int encoded_pbank_lsb;

    /*  Decoding for pbank_lsb                                             */
    /*       0000:DIMM = mem_adr[28]    / rank = mem_adr[27] (if RANK_ENA) */
    /*       0001:DIMM = mem_adr[29]    / rank = mem_adr[28]      "        */
    /*       0010:DIMM = mem_adr[30]    / rank = mem_adr[29]      "        */
    /*       0011:DIMM = mem_adr[31]    / rank = mem_adr[30]      "        */
    /*       0100:DIMM = mem_adr[32]    / rank = mem_adr[31]      "        */
    /*       0101:DIMM = mem_adr[33]    / rank = mem_adr[32]      "        */
    /*       0110:DIMM = mem_adr[34]    / rank = mem_adr[33]      "        */
    /*       0111:DIMM = 0              / rank = mem_adr[34]      "        */
    /*       1000-1111: RESERVED                                           */

    int pbank_lsb_start = 0;

    pbank_lsb_start = 28;

    encoded_pbank_lsb      = pbank_lsb - pbank_lsb_start;

    return encoded_pbank_lsb;
}

static uint64_t octeon_read_lmcx_ddr3_rlevel_dbg(bdk_node_t node, int ddr_interface_num, int idx)
{
    DRAM_CSR_MODIFY(c, node, BDK_LMCX_RLEVEL_CTL(ddr_interface_num),
		    c.s.byte = idx);
    BDK_CSR_READ(node, BDK_LMCX_RLEVEL_CTL(ddr_interface_num));
    BDK_CSR_INIT(rlevel_dbg, node, BDK_LMCX_RLEVEL_DBG(ddr_interface_num));
    return rlevel_dbg.s.bitmask;
}

static uint64_t octeon_read_lmcx_ddr3_wlevel_dbg(bdk_node_t node, int ddr_interface_num, int idx)
{
    bdk_lmcx_wlevel_dbg_t wlevel_dbg;

    wlevel_dbg.u = 0;
    wlevel_dbg.s.byte = idx;

    DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_DBG(ddr_interface_num), wlevel_dbg.u);
    BDK_CSR_READ(node, BDK_LMCX_WLEVEL_DBG(ddr_interface_num));

    wlevel_dbg.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_DBG(ddr_interface_num));
    return wlevel_dbg.s.bitmask;
}


/*
 * Apply a filter to the BITMASK results returned from Octeon
 * read-leveling to determine the most likely delay result.  This
 * computed delay may be used to qualify the delay result returned by
 * Octeon. Accumulate an error penalty for invalid characteristics of
 * the bitmask so that they can be used to select the most reliable
 * results.
 *
 * The algorithm searches for the largest contigous MASK within a
 * maximum RANGE of bits beginning with the MSB.  A MASK with a WIDTH
 * less than 4 will be penalized.  Bubbles in the bitmask that occur
 * before or after the MASK will be penalized. If there are no
 * trailing bubbles then extra bits that occur beyond the maximum
 * RANGE will be penalized.
 *
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++
 *   +                                                 +
 *   +   e.g. bitmask = 27B00                          +
 *   +                                                 +
 *   +   63                  +--- mstart           0   +
 *   +   |                   |                     |   +
 *   +   |         +---------+     +--- fb         |   +
 *   +   |         |  range  |     |               |   +
 *   +   V         V         V     V               V   +
 *   +                                                 +
 *   +   0 0 ... 1 0 0 1 1 1 1 0 1 1 0 0 0 0 0 0 0 0   +
 *   +                                                 +
 *   +           ^     ^     ^                         +
 *   +           |     | mask|                         +
 *   +     lb ---+     +-----+                         +
 *   +                  width                          +
 *   +                                                 +
 *   +++++++++++++++++++++++++++++++++++++++++++++++++++
 */
#define MASKRANGE 0x3f
static int validate_ddr3_rlevel_bitmask(const uint64_t bitmask, uint8_t *mstartp, uint8_t *widthp)
{
    int i;
    int errors  = 0;
    uint32_t range;
    uint64_t mask = 0;      /* Used in 64-bit comparisons */
    int8_t  mstart = 0;
    uint8_t width = 0;
    uint8_t firstbit = 0;
    uint8_t lastbit = 0;
    uint8_t bubble = 0;
    uint8_t tbubble = 0;
    uint8_t blank = 0;
    uint8_t narrow = 0;
    uint8_t trailing = 0;

    if (bitmask == 0) {
	blank += RLEVEL_BITMASK_BLANK_ERROR;
    } else {
	/* Look for fb, the first bit */
	for (firstbit = 0; firstbit < 64; ++firstbit) {
	    if ((bitmask>>firstbit) & 1)
		break;
	}

	/* Look for lb, the last bit */
	for (lastbit = 63; lastbit >= firstbit; --lastbit) {
	    if ((bitmask>>lastbit) & 1)
		break;
	}

	/* Measure the max allowed mask range */
	range=0;
	while ((MASKRANGE >> range) & 1) {
	    debug_bitmask_print("MASKRANGE:%x, range:%x\n", MASKRANGE, range);
	    ++range;
	}

	/* Use the range to find the largest mask within the bitmask
	 * data
	 */
	width = range;
	for (mask=MASKRANGE; mask>0; mask >>= 1, width-=1) {
	    int match = 0;
	    for (mstart=lastbit-width+1; mstart>=0; --mstart) {
		debug_bitmask_print("bm:%lx, mask: %lx, width:%2d, mstart:%2d\n",
				    bitmask, mask, width,
				    mstart);
				
		if ((bitmask&(mask<<mstart)) == (mask<<mstart)) {
		    match = 1;
		    break;
		}
	    }
	    if (match)
		break;
	}

	/* Shift mask into position incase the mask has contiguous
	 * trailing bits.
	 */
	debug_bitmask_print("mstart:%d", mstart);
	while ((bitmask >> mstart) & 1) {
	    debug_bitmask_print(" %d", mstart);
	    --mstart;
	}
	debug_bitmask_print("\n");
	++mstart;

	/* Detect if bitmask is too narrow. */
	if (width < 4)
	    narrow = (4-width) * RLEVEL_BITMASK_NARROW_ERROR;

	/* detect leading bubble bits */
	for (i = firstbit; i < mstart; ++i) {
	    if (((bitmask >> i) & 1) == 0)
		bubble += RLEVEL_BITMASK_BUBBLE_BITS_ERROR;
	}

	/* Detect trailing bubble bits. */
	for (i = mstart + width; ((bitmask >> i) != 0) && (i < 64); ++i) {
	    debug_bitmask_print("%d, mstart+width:%u, (bitmask>>i):%0lx\n",
				i, mstart+width, (bitmask>>i));
	    if (((bitmask >> i) & 1) == 0)
		tbubble += RLEVEL_BITMASK_BUBBLE_BITS_ERROR;
	}

	/* Detect invalid bits at the trailing end of the range. */
	if (tbubble == 0) {
	    for (i = mstart + range; i <= lastbit; ++i) {
		if ((bitmask >> i) & 1)
		    trailing +=
			RLEVEL_BITMASK_TRAILING_BITS_ERROR;
	    }
	}
    }

    errors = bubble + tbubble + blank + narrow + trailing;

    /* Pass out useful statistics */
    *mstartp = mstart;
    *widthp = width;

    debug_bitmask_print("bm:%05lx mask:%2lx, width:%2u, mstart:%2d, fb:%2u, lb:%2u"
			" (bu:%d, tb:%d, bl:%d, n:%d, t:%d) errors:%3d ",
			(unsigned long) bitmask, mask, width, mstart,
			firstbit, lastbit, bubble, tbubble, blank, narrow,
			trailing, errors);

    if (errors) {
	debug_bitmask_print(" => invalid");
    }

    debug_bitmask_print("\n");

    return errors;
}

static int compute_ddr3_rlevel_delay(uint8_t mstart, uint8_t width, bdk_lmcx_rlevel_ctl_t rlevel_ctl)
{
    int delay;

    debug_bitmask_print("  offset_en:%d", rlevel_ctl.s.offset_en);

    if (rlevel_ctl.s.offset_en) {
	delay = max(mstart, mstart + width - 1 - rlevel_ctl.s.offset);
    } else {
	/* if (rlevel_ctl.s.offset) { */ /* Experimental */
	if (0) {
	    delay = max(mstart + rlevel_ctl.s.offset, mstart + 1);
	    /* Insure that the offset delay falls within the bitmask */
	    delay = min(delay, mstart + width-1);
	} else {
	    delay = (width - 1) / 2 + mstart; /* Round down */
	    /* delay = (width/2) + mstart; */  /* Round up */
	}
    }

    return delay;
}

#define WLEVEL_BYTE_BITS 5
#define WLEVEL_BYTE_MSK  ((1UL << 5) - 1)

static void update_wlevel_rank_struct(bdk_lmcx_wlevel_rankx_t *lmc_wlevel_rank,
				      int byte, int delay)
{
    bdk_lmcx_wlevel_rankx_t temp_wlevel_rank;
    if (byte >= 0 && byte <= 8) {
	temp_wlevel_rank.u = lmc_wlevel_rank->u;
	temp_wlevel_rank.u &= ~(WLEVEL_BYTE_MSK << (WLEVEL_BYTE_BITS * byte));
	temp_wlevel_rank.u |= ((delay & WLEVEL_BYTE_MSK) << (WLEVEL_BYTE_BITS * byte));
	lmc_wlevel_rank->u = temp_wlevel_rank.u;
    }
}

static int  get_wlevel_rank_struct(bdk_lmcx_wlevel_rankx_t *lmc_wlevel_rank,
				   int byte)
{
    int delay = 0;
    if (byte >= 0 && byte <= 8) {
	delay = ((lmc_wlevel_rank->u) >> (WLEVEL_BYTE_BITS * byte)) & WLEVEL_BYTE_MSK;
    }
    return delay;
}

#define RLEVEL_BYTE_BITS 6
#define RLEVEL_BYTE_MSK  ((1UL << 6) - 1)

static void update_rlevel_rank_struct(bdk_lmcx_rlevel_rankx_t *lmc_rlevel_rank,
				      int byte, int delay)
{
    bdk_lmcx_rlevel_rankx_t temp_rlevel_rank;
    if (byte >= 0 && byte <= 8) {
	temp_rlevel_rank.u = lmc_rlevel_rank->u & ~(RLEVEL_BYTE_MSK << (RLEVEL_BYTE_BITS * byte));
	temp_rlevel_rank.u |= ((delay & RLEVEL_BYTE_MSK) << (RLEVEL_BYTE_BITS * byte));
	lmc_rlevel_rank->u = temp_rlevel_rank.u;
    }
}

static int  get_rlevel_rank_struct(bdk_lmcx_rlevel_rankx_t *lmc_rlevel_rank,
				   int byte)
{
    int delay = 0;
    if (byte >= 0 && byte <= 8) {
	delay = ((lmc_rlevel_rank->u) >> (RLEVEL_BYTE_BITS * byte)) & RLEVEL_BYTE_MSK;
    }
    return delay;
}

static void rlevel_to_wlevel(bdk_lmcx_rlevel_rankx_t *lmc_rlevel_rank,
			     bdk_lmcx_wlevel_rankx_t *lmc_wlevel_rank, int byte)
{
    int byte_delay = get_rlevel_rank_struct(lmc_rlevel_rank, byte);

    debug_print("Estimating Wlevel delay byte %d: ", byte);
    debug_print("Rlevel=%d => ", byte_delay);
    byte_delay = divide_roundup(byte_delay,2) & 0x1e;
    debug_print("Wlevel=%d\n", byte_delay);
    update_wlevel_rank_struct(lmc_wlevel_rank, byte, byte_delay);
}

/* Delay trend: constant=0, decreasing=-1, increasing=1 */
static int64_t calc_delay_trend(int64_t v)
{
    if (v == 0)
	return (0);
    if (v < 0)
	return (-1);
    return 1;
}

/* Evaluate delay sequence across the whole range of byte delays while
** keeping track of the overall delay trand, increasing or decreasing.
** If the trend changes charge an error amount to the score. */
static int nonsequential_delays(rlevel_byte_data_t *rlevel_byte,
				int start, int end, int max_adj_delay_inc)
{
    int error = 0;
    int delay_trend, prev_trend = 0;
    int byte_idx;
    int delay_inc;
    for (byte_idx=start; byte_idx<end; ++byte_idx) {
	delay_trend = calc_delay_trend(rlevel_byte[byte_idx+1].delay -
				       rlevel_byte[byte_idx].delay);
	debug_bitmask_print("Byte %d: %2d, Byte %d: %2d, delay_trend: %2d, prev_trend: %2d",
			    byte_idx+0, rlevel_byte[byte_idx+0].delay,
			    byte_idx+1, rlevel_byte[byte_idx+1].delay,
			    delay_trend, prev_trend);
	if ((prev_trend != 0) && (delay_trend != 0) &&
	    (prev_trend != delay_trend)) {
	    /* Increment error each time the trend changes. */
	    error += RLEVEL_NONSEQUENTIAL_DELAY_ERROR;
	    prev_trend = delay_trend;
	    debug_bitmask_print(" => Nonsequential byte delay");
	}

	delay_inc = _abs(rlevel_byte[byte_idx+1].delay
			 - rlevel_byte[byte_idx].delay);
	if ((max_adj_delay_inc != 0) && (delay_inc > max_adj_delay_inc)) {
	    error += (delay_inc - max_adj_delay_inc) * RLEVEL_ADJACENT_DELAY_ERROR;
	    debug_bitmask_print(" => Adjacent delay error");
	}

	debug_bitmask_print("\n");
	if (delay_trend != 0)
	    prev_trend = delay_trend;
    }
    return error;
}

static int roundup_ddr3_wlevel_bitmask(int bitmask)
{
    int shifted_bitmask;
    int leader;
    int delay;

    for (leader=0; leader<8; ++leader) {
	shifted_bitmask = (bitmask>>leader);
	if ((shifted_bitmask&1) == 0)
	    break;
    }

    for (leader=leader; leader<16; ++leader) {
	shifted_bitmask = (bitmask>>(leader%8));
	if (shifted_bitmask&1)
	    break;
    }

    delay = (leader & 1) ? leader + 1 : leader;
    delay = delay % 8;

    return delay;
}

/* Check to see if any custom offset values are used */
static int is_dll_offset_enabled(const int8_t *dll_offset_table)
{
    int i;
    if (dll_offset_table != NULL) {
	for (i=0; i<9; ++i) {
	    if (dll_offset_table[i] != 0)
		return (1);
	}
    }
    return (0);
}

/////////////////// These are the RLEVEL settings display routines

// flags
#define WITH_NOTHING 0
#define WITH_SCORE   1
#define WITH_AVERAGE 2
#define WITH_FINAL   4
static void do_display_read_leveling_settings(bdk_node_t node, int ddr_interface_num,
					      bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank,
					      int rank, int flags, int score)
{
    char score_buf[16];
    if (flags & WITH_SCORE)
	snprintf(score_buf, sizeof(score_buf), "(%d)", score);
    else {
	score_buf[0] = ' '; score_buf[1] = 0;
    }

    char *msg_buf;
    char hex_buf[20];
    if (flags & WITH_AVERAGE) {
	msg_buf = "  DELAY AVERAGES  ";
    } else if (flags & WITH_FINAL) {
	msg_buf = "  FINAL SETTINGS  ";
    } else {
	snprintf(hex_buf, sizeof(hex_buf), "0x%016lX", lmc_rlevel_rank.u);
	msg_buf = hex_buf;
    }

    ddr_print("N%d.LMC%d.R%d: Rlevel Rank %#4x, %s  : %5d %5d %5d %5d %5d %5d %5d %5d %5d %s\n",
              node, ddr_interface_num, rank,
              lmc_rlevel_rank.s.status,
              msg_buf,
              lmc_rlevel_rank.s.byte8,
              lmc_rlevel_rank.s.byte7,
              lmc_rlevel_rank.s.byte6,
              lmc_rlevel_rank.s.byte5,
              lmc_rlevel_rank.s.byte4,
              lmc_rlevel_rank.s.byte3,
              lmc_rlevel_rank.s.byte2,
              lmc_rlevel_rank.s.byte1,
              lmc_rlevel_rank.s.byte0,
	      score_buf
              );
}

static inline void display_read_leveling_settings(bdk_node_t node, int ddr_interface_num, bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank, int rank)
{
    do_display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rank, 0, 0);
}

static inline void display_read_leveling_settings_with_score(bdk_node_t node, int ddr_interface_num, bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank, int rank, int score)
{
    do_display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rank, 1, score);
}

static inline void display_read_leveling_settings_with_average(bdk_node_t node, int ddr_interface_num, bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank, int rank, int score)
{
    do_display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rank, 3, score);
}

static inline void display_read_leveling_settings_with_final(bdk_node_t node, int ddr_interface_num, bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank, int rank, int score)
{
    do_display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rank, 4, 0);
}

// flag values
#define WITH_RODT_BLANK    0
#define WITH_RODT_SKIPPING 1
#define WITH_RODT_BESTROW  2
// control
#define SKIP_SKIPPING 1
static void display_read_leveling_settings_with_RODT(bdk_node_t node, int ddr_interface_num, 
						     bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank, int rank, int score,
							int rtt_nom, int nom_ohms, int rodt_ctl, int rodt_ohms, int flag)
{
    char *msg_buf;
#if SKIP_SKIPPING
    if (flag == WITH_RODT_SKIPPING) return;
#endif
    msg_buf = (flag == WITH_RODT_SKIPPING) ? "SKIPPING" : ((flag == WITH_RODT_BESTROW) ? "BEST ROW" : "        ");
    
    ddr_print("N%d.LMC%d.R%d: Rlevel NOM %1d/%3d RODT %1d/%3d  %s : %5d %5d %5d %5d %5d %5d %5d %5d %5d (%d)\n",
	      node, ddr_interface_num, rank,
	      rtt_nom, nom_ohms,
	      rodt_ctl, rodt_ohms,
	      msg_buf,
	      lmc_rlevel_rank.s.byte8,
	      lmc_rlevel_rank.s.byte7,
	      lmc_rlevel_rank.s.byte6,
	      lmc_rlevel_rank.s.byte5,
	      lmc_rlevel_rank.s.byte4,
	      lmc_rlevel_rank.s.byte3,
	      lmc_rlevel_rank.s.byte2,
	      lmc_rlevel_rank.s.byte1,
	      lmc_rlevel_rank.s.byte0,
	      score
	      );
}

static void display_write_leveling_settings(bdk_node_t node, int ddr_interface_num, bdk_lmcx_wlevel_rankx_t lmc_wlevel_rank, int rank)
{
    ddr_print("N%d.LMC%d.R%d: Wlevel Rank %#4x, 0x%016lX  : %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
	      node, ddr_interface_num, rank,
	      lmc_wlevel_rank.s.status,
	      lmc_wlevel_rank.u,
	      lmc_wlevel_rank.s.byte8,
	      lmc_wlevel_rank.s.byte7,
	      lmc_wlevel_rank.s.byte6,
	      lmc_wlevel_rank.s.byte5,
	      lmc_wlevel_rank.s.byte4,
	      lmc_wlevel_rank.s.byte3,
	      lmc_wlevel_rank.s.byte2,
	      lmc_wlevel_rank.s.byte1,
	      lmc_wlevel_rank.s.byte0
	      );
}

static unsigned short load_dll_offset(bdk_node_t node, int ddr_interface_num, int dll_offset_mode, int byte_offset, int byte)
{
    bdk_lmcx_dll_ctl3_t ddr_dll_ctl3;
    /* byte_sel:
       0x1 = byte 0, ..., 0x9 = byte 8
       0xA = all bytes */
    int byte_sel = (byte == 10) ? byte : byte + 1;

    ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
    SET_DDR_DLL_CTL3(load_offset, 0);
    DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
    ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

    SET_DDR_DLL_CTL3(mode_sel, dll_offset_mode);
    SET_DDR_DLL_CTL3(offset, (_abs(byte_offset)&0x3f) | (_sign(byte_offset) << 6)); /* Always 6-bit field? */
    SET_DDR_DLL_CTL3(byte_sel, byte_sel);
    DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
    ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

    SET_DDR_DLL_CTL3(load_offset, 1);
    DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
    ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

    return ((unsigned short) GET_DDR_DLL_CTL3(offset));
}

static void process_custom_dll_offsets(bdk_node_t node, int ddr_interface_num, const char *enable_str,
				       const int8_t *offsets, const char *byte_str, int mode)
{
    const char *s;

    if (((s = lookup_env_parameter(enable_str)) != NULL) || is_dll_offset_enabled(offsets)) {
        bdk_lmcx_dll_ctl3_t ddr_dll_ctl3;
        int byte_offset;
        unsigned short offset[9] = {0};
        int i;

        for (i = 0; i < 9; ++i) {
            byte_offset = (offsets != NULL) ? offsets[i] : 0;

            if ((s = lookup_env_parameter(byte_str, ddr_interface_num, i)) != NULL) {
                byte_offset = strtol(s, NULL, 0);
            }

            offset[i] = load_dll_offset(node, ddr_interface_num, mode, byte_offset, i);
        }

        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
        SET_DDR_DLL_CTL3(offset_ena, 1);
        DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);

        ddr_print("N%d.LMC%d: DLL %s Offset 8:0       :  0x%02x  0x%02x  0x%02x  0x%02x  0x%02x  0x%02x  0x%02x  0x%02x  0x%02x\n",
                  node, ddr_interface_num, (mode == 2) ? "Read " : "Write",
                  offset[8], offset[7], offset[6], offset[5], offset[4],
                  offset[3], offset[2], offset[1], offset[0]);
    }
}

#ifdef ENABLE_AUTO_SET_DLL
static void auto_set_dll_offset(bdk_node_t node, int dll_offset_mode, int ddr_interface_num, int ddr_interface_64b)
{
    bdk_lmcx_dll_ctl3_t ddr_dll_ctl3;
    int byte_offset;
    unsigned short result[9];
    int byte;
    uint64_t rank_addr;
    signed char byte_delay_start[9] = {0};
    signed char byte_delay_count[9] = {0};
    signed char byte_delay_best_start[9] = {0};
    signed char byte_delay_best_count[9] = {0};
    char sbuffer[50];

    rank_addr = (ddr_interface_num<<7); /* Map address into proper interface */
    ddr_print("Rank Address: 0x%lx\n", rank_addr);

    for (byte_offset=-63; byte_offset<63; ++byte_offset) {
        int i;
        uint64_t byte_bitmask = 0xff;

        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
        SET_DDR_DLL_CTL3(offset_ena, 0);
        DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);

        load_dll_offset(node, ddr_interface_num, dll_offset_mode, byte_offset, 10 /* All bytes at once */);

        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
        SET_DDR_DLL_CTL3(offset_ena, 1);
        DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

        for (byte=0; byte<9; ++byte) {
            /* If we will be switching to 32bit mode only test 4 ECC bits.  */
            if ((! ddr_interface_64b) && (byte == 4))
                byte_bitmask = 0x0f;

            result[byte] = 0;
            for (i=0; i<2; ++i) {
                BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);
                result[byte] += test_dram_byte(rank_addr, 4096, byte, byte_bitmask);
            }
            if (result[byte] == 0) {
                if (byte_delay_count[byte] == 0) {
                    byte_delay_start[byte] = byte_offset;
                }
                byte_delay_count[byte] += 1;

                if (byte_delay_count[byte] > byte_delay_best_count[byte]) {
                    byte_delay_best_count[byte] = byte_delay_count[byte];
                    byte_delay_best_start[byte] = byte_delay_start[byte];
                }
            } else {
                byte_delay_count[byte] = 0;
            }
       }

        sprintf(sbuffer, "DLL %s Offset Test %3d", dll_offset_mode == 1 ? "Write" : "Read", byte_offset);
        ddr_print("%-45s : ", sbuffer);
        for (byte=0; byte<9; ++byte) {
            if (result[byte])
                ddr_print(" %2d", result[byte]);
            else
                ddr_print("  .");
            /*
            debug_print("(%2d,%2d,%2d,%2d)", byte_delay_start[byte], byte_delay_count[byte],
                      byte_delay_best_start[byte], byte_delay_best_count[byte]);
            */
        }
        ddr_print("\n");
    }

    sprintf(sbuffer, "DLL %s Offset Delay", dll_offset_mode == 1 ? "Write" : "Read");
    ddr_print("%-45s : ", sbuffer);
    for (byte=0; byte<9; ++byte) {
        byte_offset =  byte_delay_best_start[byte] + byte_delay_best_count[byte] / 2;
        ddr_print(" %2d", byte_offset);

        load_dll_offset(node, ddr_interface_num, dll_offset_mode, byte_offset, byte);

        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
        SET_DDR_DLL_CTL3(offset_ena, 1);
        DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
    }
    ddr_print("\n");
}
#endif  /* ENABLE_AUTO_SET_DLL */

void perform_octeon3_ddr3_sequence(bdk_node_t node, int rank_mask, int ddr_interface_num, int sequence)
{
    /*
     * 3. Without changing any other fields in LMC(0)_CONFIG, write
     *    LMC(0)_CONFIG[RANKMASK] then write both
     *    LMC(0)_SEQ_CTL[SEQ_SEL,INIT_START] = 1 with a single CSR write
     *    operation. LMC(0)_CONFIG[RANKMASK] bits should be set to indicate
     *    the ranks that will participate in the sequence.
     * 
     *    The LMC(0)_SEQ_CTL[SEQ_SEL] value should select power-up/init or
     *    selfrefresh exit, depending on whether the DRAM parts are in
     *    self-refresh and whether their contents should be preserved. While
     *    LMC performs these sequences, it will not perform any other DDR3
     *    transactions. When the sequence is complete, hardware sets the
     *    LMC(0)_CONFIG[INIT_STATUS] bits for the ranks that have been
     *    initialized.
     * 
     *    If power-up/init is selected immediately following a DRESET
     *    assertion, LMC executes the sequence described in the "Reset and
     *    Initialization Procedure" section of the JEDEC DDR3
     *    specification. This includes activating CKE, writing all four DDR3
     *    mode registers on all selected ranks, and issuing the required ZQCL
     *    command. The LMC(0)_CONFIG[RANKMASK] value should select all ranks
     *    with attached DRAM in this case. If LMC(0)_CONTROL[RDIMM_ENA] = 1,
     *    LMC writes the JEDEC standard SSTE32882 control words selected by
     *    LMC(0)_DIMM_CTL[DIMM*_WMASK] between DDR_CKE* signal assertion and
     *    the first DDR3 mode register write operation.
     *    LMC(0)_DIMM_CTL[DIMM*_WMASK] should be cleared to 0 if the
     *    corresponding DIMM is not present.
     * 
     *    If self-refresh exit is selected, LMC executes the required SRX
     *    command followed by a refresh and ZQ calibration. Section 4.5
     *    describes behavior of a REF + ZQCS.  LMC does not write the DDR3
     *    mode registers as part of this sequence, and the mode register
     *    parameters must match at self-refresh entry and exit times.
     * 
     * 4. Read LMC(0)_SEQ_CTL and wait for LMC(0)_SEQ_CTL[SEQ_COMPLETE] to be
     *    set.
     * 
     * 5. Read LMC(0)_CONFIG[INIT_STATUS] and confirm that all ranks have
     *    been initialized.
     */

    const char *s;

#ifdef DEBUG_PERFORM_DDR3_SEQUENCE
    static const char *sequence_str[] = {
	"Power-up/init",
	"Read-leveling",
	"Self-refresh entry",
	"Self-refresh exit",
	"Illegal",
	"Illegal",
	"Write-leveling",
	"Init Register Control Words",
	"Mode Register Write",
	"MPR Register Access",
	"LMC Deskew/Internal Vref training",
	"Offset Training"
    };
#endif

    bdk_lmcx_seq_ctl_t seq_ctl;
    bdk_lmcx_config_t  lmc_config;

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    lmc_config.s.rankmask     = rank_mask;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

    seq_ctl.u    = 0;

    seq_ctl.s.init_start  = 1;
    seq_ctl.s.seq_sel    = sequence;

    ddr_seq_print("Performing LMC sequence: rank_mask=0x%02x, sequence=%x, %s\n",
		  rank_mask, sequence, sequence_str[sequence]);

    if ((s = lookup_env_parameter("ddr_trigger_sequence%d", sequence)) != NULL) {
	int trigger = strtoul(s, NULL, 0);
	if (trigger)
	    pulse_gpio_pin(node, 1, 2);
    }

    DRAM_CSR_WRITE(node, BDK_LMCX_SEQ_CTL(ddr_interface_num), seq_ctl.u);
    BDK_CSR_READ(node, BDK_LMCX_SEQ_CTL(ddr_interface_num));

    /* Wait 100us minimum before checking for sequence complete */
    bdk_wait_usec(100);
    if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
	BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_SEQ_CTL(ddr_interface_num), seq_complete, ==, 1, 1000000))
    {
	error_print("Timeout waiting for LMC sequence, ignoring: rank_mask=0x%02x, sequence=%x\n",
		    rank_mask, sequence);
    }
    else
	ddr_seq_print("           LMC sequence=%x: Completed.\n", sequence);
}

static void ddr4_mrw(bdk_node_t node, int ddr_interface_num, int rank,
              int mr_wr_addr, int mr_wr_sel, int mr_wr_bg1)
{
    bdk_lmcx_mr_mpr_ctl_t lmc_mr_mpr_ctl;

    lmc_mr_mpr_ctl.u = 0;
    lmc_mr_mpr_ctl.s.mr_wr_addr                 = (mr_wr_addr == -1) ? 0 : mr_wr_addr;
    lmc_mr_mpr_ctl.s.mr_wr_sel                  = mr_wr_sel;
    lmc_mr_mpr_ctl.s.mr_wr_rank                 = rank;
    //lmc_mr_mpr_ctl.s.mr_wr_pda_mask           =
    //lmc_mr_mpr_ctl.s.mr_wr_pda_enable         =
    //lmc_mr_mpr_ctl.s.mpr_loc                  = 
    //lmc_mr_mpr_ctl.s.mpr_wr                   = 
    //lmc_mr_mpr_ctl.s.mpr_bit_select           =
    //lmc_mr_mpr_ctl.s.mpr_byte_select          =
    //lmc_mr_mpr_ctl.s.mpr_whole_byte_enable    =
    lmc_mr_mpr_ctl.s.mr_wr_use_default_value    = (mr_wr_addr == -1) ? 1 : 0;
    lmc_mr_mpr_ctl.s.mr_wr_bg1                  = mr_wr_bg1;
    DRAM_CSR_WRITE(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num), lmc_mr_mpr_ctl.u);

    /* Mode Register Write */
    perform_octeon3_ddr3_sequence(node, 1 << rank, ddr_interface_num, 0x8);
}

#define InvA0_17(x) (x ^ 0x22bf8)

static void set_mpr_mode (bdk_node_t node, int rank_mask,
                          int ddr_interface_num, int dimm_count, int mpr, int bg1)
{
    int rankx;

    for (rankx = 0; rankx < dimm_count*4; rankx++) {
        if (!(rank_mask & (1 << rankx)))
            continue;
        ddr_print("Rank(%d): Set mpr mode = %x %c-side\n", rankx, mpr, (bg1==0) ? 'A' : 'B');
        if (bg1 == 0)
            ddr4_mrw(node, ddr_interface_num, rankx,          mpr<<2,   3, bg1); /* MR3 A-side */
        else
            ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(mpr<<2), ~3, bg1); /* MR3 B-side */
    }
}

#if ENABLE_DISPLAY_MPR_PAGE
static void do_ddr4_mpr_read(bdk_node_t node, int ddr_interface_num, int rank,
                      int page, int location)
{
    bdk_lmcx_mr_mpr_ctl_t lmc_mr_mpr_ctl;

    lmc_mr_mpr_ctl.u = BDK_CSR_READ(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num));

    lmc_mr_mpr_ctl.s.mr_wr_addr                 = 0;
    lmc_mr_mpr_ctl.s.mr_wr_sel                  = page; /* Page */
    lmc_mr_mpr_ctl.s.mr_wr_rank                 = rank;
    //lmc_mr_mpr_ctl.s.mr_wr_pda_mask           =
    //lmc_mr_mpr_ctl.s.mr_wr_pda_enable         =
    lmc_mr_mpr_ctl.s.mpr_loc                    = location;
    lmc_mr_mpr_ctl.s.mpr_wr                     = 0; /* Read=0, Write=1 */
    //lmc_mr_mpr_ctl.s.mpr_bit_select           =
    //lmc_mr_mpr_ctl.s.mpr_byte_select          =
    //lmc_mr_mpr_ctl.s.mpr_whole_byte_enable    =
    //lmc_mr_mpr_ctl.s.mr_wr_use_default_value  =
    //lmc_mr_mpr_ctl.s.mr_wr_bg1                =

    DRAM_CSR_WRITE(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num), lmc_mr_mpr_ctl.u);

    /* MPR register access sequence */
    perform_octeon3_ddr3_sequence(node, 1 << rank, ddr_interface_num, 0x9);

    debug_print("LMC_MR_MPR_CTL             : 0x%016lx\n", lmc_mr_mpr_ctl.u);
    debug_print("lmc_mr_mpr_ctl.s.mr_wr_addr: 0x%02x\n", lmc_mr_mpr_ctl.s.mr_wr_addr);
    debug_print("lmc_mr_mpr_ctl.s.mr_wr_sel : 0x%02x\n", lmc_mr_mpr_ctl.s.mr_wr_sel);
    debug_print("lmc_mr_mpr_ctl.s.mpr_loc   : 0x%02x\n", lmc_mr_mpr_ctl.s.mpr_loc);
    debug_print("lmc_mr_mpr_ctl.s.mpr_wr    : 0x%02x\n", lmc_mr_mpr_ctl.s.mpr_wr);

}
#endif

int set_rdimm_mode(bdk_node_t node, int ddr_interface_num, int enable)
{
    bdk_lmcx_control_t lmc_control;
    int save_rdimm_mode;

    lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
    save_rdimm_mode = lmc_control.s.rdimm_ena;
    lmc_control.s.rdimm_ena       = enable;
    ddr_print("Setting RDIMM_ENA = %x\n", enable);
    DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

    return (save_rdimm_mode);
}

#if ENABLE_DISPLAY_MPR_PAGE
static void ddr4_mpr_read(bdk_node_t node, int ddr_interface_num, int rank,
			  int page, int location, uint64_t *mpr_data)
{
    do_ddr4_mpr_read(node, ddr_interface_num, rank, page, location);

    mpr_data[0] = BDK_CSR_READ(node, BDK_LMCX_MPR_DATA0(ddr_interface_num));
    mpr_data[1] = BDK_CSR_READ(node, BDK_LMCX_MPR_DATA1(ddr_interface_num));
    mpr_data[2] = BDK_CSR_READ(node, BDK_LMCX_MPR_DATA2(ddr_interface_num));

    debug_print("MPR Read %016lx.%016lx.%016lx\n", mpr_data[2], mpr_data[1], mpr_data[0]);
}

/* Display MPR values for Page Location */
static void Display_MPR_Page_Location(bdk_node_t node, int rank,
                                      int ddr_interface_num, int dimm_count,
                                      int page, int location, uint64_t *mpr_data)
{
    ddr4_mpr_read(node, ddr_interface_num, rank, page, location, mpr_data);
    ddr_print("MPR Page %d, Loc %d %016lx.%016lx.%016lx\n",
              page, location, mpr_data[2], mpr_data[1], mpr_data[0]);
}

/* Display MPR values for Page */
static void Display_MPR_Page(bdk_node_t node, int rank_mask,
                      int ddr_interface_num, int dimm_count, int page)
{
    int rankx;
    uint64_t mpr_data[3];

    for (rankx = 0; rankx < dimm_count * 4;rankx++) {
        if (!(rank_mask & (1 << rankx)))
            continue;

        ddr_print("Rank %d: MPR values for Page %d\n", rankx, page);
        for (int location = 0; location < 4; location++) {
            Display_MPR_Page_Location(node, rankx, ddr_interface_num, dimm_count,
                                      page, location, &mpr_data[0]);
        }

    } /* for (rankx = 0; rankx < dimm_count * 4; rankx++) */
}
#endif

void ddr4_mpr_write(bdk_node_t node, int ddr_interface_num, int rank,
                    int page, int location, uint8_t mpr_data)
{
    bdk_lmcx_mr_mpr_ctl_t lmc_mr_mpr_ctl;

    lmc_mr_mpr_ctl.u = 0;
    lmc_mr_mpr_ctl.s.mr_wr_addr                 = mpr_data;
    lmc_mr_mpr_ctl.s.mr_wr_sel                  = page; /* Page */
    lmc_mr_mpr_ctl.s.mr_wr_rank                 = rank;
    //lmc_mr_mpr_ctl.s.mr_wr_pda_mask           =
    //lmc_mr_mpr_ctl.s.mr_wr_pda_enable         =
    lmc_mr_mpr_ctl.s.mpr_loc                    = location;
    lmc_mr_mpr_ctl.s.mpr_wr                     = 1; /* Read=0, Write=1 */
    //lmc_mr_mpr_ctl.s.mpr_bit_select           =
    //lmc_mr_mpr_ctl.s.mpr_byte_select          =
    //lmc_mr_mpr_ctl.s.mpr_whole_byte_enable    =
    //lmc_mr_mpr_ctl.s.mr_wr_use_default_value  =
    //lmc_mr_mpr_ctl.s.mr_wr_bg1                =
    DRAM_CSR_WRITE(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num), lmc_mr_mpr_ctl.u);

    /* MPR register access sequence */
    perform_octeon3_ddr3_sequence(node, (1 << rank), ddr_interface_num, 0x9);

    debug_print("LMC_MR_MPR_CTL             : 0x%016lx\n", lmc_mr_mpr_ctl.u);
    debug_print("lmc_mr_mpr_ctl.s.mr_wr_addr: 0x%02x\n", lmc_mr_mpr_ctl.s.mr_wr_addr);
    debug_print("lmc_mr_mpr_ctl.s.mr_wr_sel : 0x%02x\n", lmc_mr_mpr_ctl.s.mr_wr_sel);
    debug_print("lmc_mr_mpr_ctl.s.mpr_loc   : 0x%02x\n", lmc_mr_mpr_ctl.s.mpr_loc);
    debug_print("lmc_mr_mpr_ctl.s.mpr_wr    : 0x%02x\n", lmc_mr_mpr_ctl.s.mpr_wr);
}

void set_vref(bdk_node_t node, int ddr_interface_num, int rank,
	      int range, int value)
{
    bdk_lmcx_mr_mpr_ctl_t lmc_mr_mpr_ctl;
    bdk_lmcx_modereg_params3_t lmc_modereg_params3;
    int mr_wr_addr = 0;

    lmc_mr_mpr_ctl.u = 0;
    lmc_modereg_params3.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS3(ddr_interface_num));

    mr_wr_addr |= lmc_modereg_params3.s.tccd_l<<10; /* A12:A10 tCCD_L */
    mr_wr_addr |= 1<<7;         /* A7 1 = Enable(Training Mode) */
    mr_wr_addr |= range<<6;     /* A6 VrefDQ Training Range */
    mr_wr_addr |= value<<0;     /* A5:A0 VrefDQ Training Value */

    lmc_mr_mpr_ctl.s.mr_wr_addr               = mr_wr_addr;
    lmc_mr_mpr_ctl.s.mr_wr_sel                = 6; /* Write MR6 */
    lmc_mr_mpr_ctl.s.mr_wr_rank               = rank;
    //lmc_mr_mpr_ctl.s.mr_wr_pda_mask           =
    //lmc_mr_mpr_ctl.s.mr_wr_pda_enable         =
    //lmc_mr_mpr_ctl.s.mpr_loc                  = location;
    //lmc_mr_mpr_ctl.s.mpr_wr                   = 0; /* Read=0, Write=1 */
    //lmc_mr_mpr_ctl.s.mpr_bit_select           =
    //lmc_mr_mpr_ctl.s.mpr_byte_select          =
    //lmc_mr_mpr_ctl.s.mpr_whole_byte_enable    =
    //lmc_mr_mpr_ctl.s.mr_wr_use_default_value  =
    //lmc_mr_mpr_ctl.s.mr_wr_bg1                =
    DRAM_CSR_WRITE(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num), lmc_mr_mpr_ctl.u);

    /* 0x8 = Mode Register Write */
    perform_octeon3_ddr3_sequence(node, 1<<rank, ddr_interface_num, 0x8);

    /* It is vendor specific whether Vref_value is captured with A7=1.
       A subsequent MRS might be necessary. */
    perform_octeon3_ddr3_sequence(node, 1<<rank, ddr_interface_num, 0x8);

    mr_wr_addr &= ~(1<<7);         /* A7 0 = Disable(Training Mode) */
    lmc_mr_mpr_ctl.s.mr_wr_addr               = mr_wr_addr;
    DRAM_CSR_WRITE(node, BDK_LMCX_MR_MPR_CTL(ddr_interface_num), lmc_mr_mpr_ctl.u);
}

static void set_DRAM_output_inversion (bdk_node_t node,
                                       int ddr_interface_num,
                                       int dimm_count,
                                       int rank_mask,
                                       int inversion)
{
    bdk_lmcx_ddr4_dimm_ctl_t lmc_ddr4_dimm_ctl;
    bdk_lmcx_dimmx_params_t lmc_dimmx_params;
    bdk_lmcx_dimm_ctl_t lmc_dimm_ctl;
    int dimm_no;

    lmc_ddr4_dimm_ctl.u = 0;  /* Don't touch extended register control words */
    DRAM_CSR_WRITE(node, BDK_LMCX_DDR4_DIMM_CTL(ddr_interface_num), lmc_ddr4_dimm_ctl.u);

    for (dimm_no = 0; dimm_no < dimm_count; ++dimm_no) {

        lmc_dimmx_params.u = BDK_CSR_READ(node, BDK_LMCX_DIMMX_PARAMS(ddr_interface_num, dimm_no));
        lmc_dimmx_params.s.rc0  = (lmc_dimmx_params.s.rc0 & ~1) | (inversion & 1);

        DRAM_CSR_WRITE(node, BDK_LMCX_DIMMX_PARAMS(ddr_interface_num, dimm_no), lmc_dimmx_params.u);

        ddr_print("DIMM%d Register Control Words              RC0 : %x\n",
                  dimm_no, lmc_dimmx_params.s.rc0);
    }

    /* LMC0_DIMM_CTL */
    lmc_dimm_ctl.u = BDK_CSR_READ(node, BDK_LMCX_DIMM_CTL(ddr_interface_num));
    lmc_dimm_ctl.s.dimm0_wmask         = 0x1;
    lmc_dimm_ctl.s.dimm1_wmask         = (dimm_count > 1) ? 0x0001 : 0x0000;

    ddr_print("LMC DIMM_CTL                                  : 0x%016lx\n", lmc_dimm_ctl.u);
    DRAM_CSR_WRITE(node, BDK_LMCX_DIMM_CTL(ddr_interface_num), lmc_dimm_ctl.u);

    perform_octeon3_ddr3_sequence(node, rank_mask, ddr_interface_num, 0x7 ); /* Init RCW */
}

static void write_mpr_page0_pattern (bdk_node_t node, int rank_mask,
                                     int ddr_interface_num, int dimm_count, int pattern, int location_mask)
{
    int rankx;
    int location;

    for (rankx = 0; rankx < dimm_count*4; rankx++) {
        if (!(rank_mask & (1 << rankx)))
            continue;
        for (location = 0; location < 4; ++location) {
            if (!(location_mask & (1 << location)))
                continue;

            ddr4_mpr_write(node, ddr_interface_num, rankx,
                           /* page */ 0, /* location */ location, pattern);
        }
    }
}

static void change_rdimm_mpr_pattern (bdk_node_t node, int rank_mask,
                                      int ddr_interface_num, int dimm_count)
{
    int save_ref_zqcs_int;
    bdk_lmcx_config_t  lmc_config;

    /*
      Okay, here is the latest sequence.  This should work for all
      chips and passes (78,88,73,etc).  This sequence should be run
      immediately after DRAM INIT.  The basic idea is to write the
      same pattern into each of the 4 MPR locations in the DRAM, so
      that the same value is returned when doing MPR reads regardless
      of the inversion state.  My advice is to put this into a
      function, change_rdimm_mpr_pattern or something like that, so
      that it can be called multiple times, as I think David wants a
      clock-like pattern for OFFSET training, but does not want a
      clock pattern for Bit-Deskew.  You should then be able to call
      this at any point in the init sequence (after DRAM init) to
      change the pattern to a new value.
      Mike

      A correction: PHY doesn't need any pattern during offset
      training, but needs clock like pattern for internal vref and
      bit-dskew training.  So for that reason, these steps below have
      to be conducted before those trainings to pre-condition
      the pattern.  David

      Note: Step 3, 4, 8 and 9 have to be done through RDIMM
      sequence. If you issue MRW sequence to do RCW write (in o78 pass
      1 at least), LMC will still do two commands because
      CONTROL[RDIMM_ENA] is still set high. We don't want it to have
      any unintentional mode register write so it's best to do what
      Mike is doing here.
      Andrew
    */


    /* 1) Disable refresh (REF_ZQCS_INT = 0) */

    debug_print("1) Disable refresh (REF_ZQCS_INT = 0)\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    save_ref_zqcs_int         = lmc_config.s.ref_zqcs_int;
    lmc_config.s.ref_zqcs_int = 0;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);


    /* 2) Put all devices in MPR mode (Run MRW sequence (sequence=8)
       with MODEREG_PARAMS0[MPRLOC]=0,
       MODEREG_PARAMS0[MPR]=1, MR_MPR_CTL[MR_WR_SEL]=3, and
       MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=1) */

    debug_print("2) Put all devices in MPR mode (Run MRW sequence (sequence=8)\n");

    set_mpr_mode(node, rank_mask, ddr_interface_num, dimm_count, /* mpr */ 1, /* bg1 */ 0); /* A-side */
    set_mpr_mode(node, rank_mask, ddr_interface_num, dimm_count, /* mpr */ 1, /* bg1 */ 1); /* B-side */

    /*    a. Or you can set MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=0 and set
          the value you would like directly into
          MR_MPR_CTL[MR_WR_ADDR] */

    /* 3) Disable RCD Parity (if previously enabled) - parity does not
       work if inversion disabled */

    debug_print("3) Disable RCD Parity\n");

    /* 4) Disable Inversion in the RCD. */
    /*    a. I did (3&4) via the RDIMM sequence (seq_sel=7), but it
          may be easier to use the MRW sequence (seq_sel=8).  Just set
          MR_MPR_CTL[MR_WR_SEL]=7, MR_MPR_CTL[MR_WR_ADDR][3:0]=data,
          MR_MPR_CTL[MR_WR_ADDR][7:4]=RCD reg */

    debug_print("4) Disable Inversion in the RCD.\n");

    set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                               1 /* 1=disable output inversion*/);

    /* 5) Disable CONTROL[RDIMM_ENA] so that MR sequence goes out
       non-inverted.  */

    debug_print("5) Disable CONTROL[RDIMM_ENA]\n");

    set_rdimm_mode(node, ddr_interface_num, 0);

    /* 6) Write all 4 MPR registers with the desired pattern (have to
       do this for all enabled ranks) */
    /*    a. MR_MPR_CTL.MPR_WR=1, MR_MPR_CTL.MPR_LOC=0..3,
          MR_MPR_CTL.MR_WR_SEL=0, MR_MPR_CTL.MR_WR_ADDR[7:0]=pattern */

    debug_print("6) Write all 4 MPR page 0 Training Patterns\n");

    write_mpr_page0_pattern(node, rank_mask,
                             ddr_interface_num, dimm_count, 0x55, 0x8);

    /* 7) Re-enable RDIMM_ENA */

    debug_print("7) Re-enable RDIMM_ENA\n");

    set_rdimm_mode(node, ddr_interface_num, 1);

    /* 8) Re-enable RDIMM inversion */

    debug_print("8) Re-enable RDIMM inversion\n");

    set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                               0 /* 0=re-enable output inversion*/);

    /* 9) Re-enable RDIMM parity (if desired) */

    debug_print("9) Re-enable RDIMM parity (if desired)\n");

    /* 10)Take B-side devices out of MPR mode (Run MRW sequence
       (sequence=8) with MODEREG_PARAMS0[MPRLOC]=0,
       MODEREG_PARAMS0[MPR]=0, MR_MPR_CTL[MR_WR_SEL]=3, and
       MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=1) */

    debug_print("10)Take B-side devices out of MPR mode\n");

    set_mpr_mode(node, rank_mask, ddr_interface_num, dimm_count, /* mpr */ 0, /* bg1 */ 1);

    /*    a. Or you can set MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=0 and
          set the value you would like directly into
          MR_MPR_CTL[MR_WR_ADDR] */

    /* 11)Re-enable refresh (REF_ZQCS_INT=previous value) */

    debug_print("11)Re-enable refresh (REF_ZQCS_INT=previous value)\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    lmc_config.s.ref_zqcs_int = save_ref_zqcs_int;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

}

#if RUN_INIT_SEQ_2
static void change_rdimm_mpr_pattern2 (bdk_node_t node, int rank_mask,
                                      int ddr_interface_num, int dimm_count)
{
    int save_ref_zqcs_int;
    bdk_lmcx_config_t  lmc_config;

    /*
      Okay, here is the latest sequence.  This should work for all
      chips and passes (78,88,73,etc).  This sequence should be run
      immediately after DRAM INIT.  The basic idea is to write the
      same pattern into each of the 4 MPR locations in the DRAM, so
      that the same value is returned when doing MPR reads regardless
      of the inversion state.  My advice is to put this into a
      function, change_rdimm_mpr_pattern or something like that, so
      that it can be called multiple times, as I think David wants a
      clock-like pattern for OFFSET training, but does not want a
      clock pattern for Bit-Deskew.  You should then be able to call
      this at any point in the init sequence (after DRAM init) to
      change the pattern to a new value.
      Mike

      A correction: PHY doesn't need any pattern during offset
      training, but needs clock like pattern for internal vref and
      bit-dskew training.  So for that reason, these steps below have
      to be conducted before those trainings to pre-condition
      the pattern.  David

      Note: Step 3, 4, 8 and 9 have to be done through RDIMM
      sequence. If you issue MRW sequence to do RCW write (in o78 pass
      1 at least), LMC will still do two commands because
      CONTROL[RDIMM_ENA] is still set high. We don't want it to have
      any unintentional mode register write so it's best to do what
      Mike is doing here.
      Andrew
    */


    /* 1. Disable refresh (REF_ZQCS_INT=0) */

    debug_print("1. Disable refresh (REF_ZQCS_INT=0)\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    save_ref_zqcs_int         = lmc_config.s.ref_zqcs_int;
    lmc_config.s.ref_zqcs_int = 0;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

    /* 2. Write B-side Page 0 MPR3 with the desired clock-like pattern
          (sequence=9). This will trash the A-side data pattern in
          Page 0 MPR0.  (MR_MPR_CTL.MPR_WR=1, MR_MPR_CTL.MR_WR_SEL=0,
          MR_MPR_CTL.MPR_LOC=0, MR_MPR_CTL.MR_WR_ADDR[7:0]=0xAD) Note,
          repeat this step for all active ranks by updating the CSR
          MR_MPR_CTL.MR_WR_RANK. */

    debug_print("Write B-side Page 0 MPR3 with the desired clock-like pattern (sequence=9).\n");

    write_mpr_page0_pattern(node, rank_mask,
                             ddr_interface_num, dimm_count, 0xAD, 0x1);

    /* 3. Disable CONTROL[RDIMM_ENA] so that we can recover the A-side
          pattern. */

    set_rdimm_mode(node, ddr_interface_num, 1);

    /* 4. Recover A-side Page 0 MPR0 with the desired clock-like
          pattern (sequence=9). B-side does not get set into MPR mode
          so it won't process the MPR Write command on this step.
          (MR_MPR_CTL.MPR_WR=1, MR_MPR_CTL.MR_WR_SEL=0,
          MR_MPR_CTL.MPR_LOC=0, MR_MPR_CTL.MR_WR_ADDR[7:0]=0x55).
          Note, repeat this step for all active ranks by updating the
          CSR MR_MPR_CTL.MR_WR_RANK. */

    debug_print("4. Recover A-side Page 0 MPR0 with the desired clock-like pattern (sequence=9).\n");

    write_mpr_page0_pattern(node, rank_mask,
                             ddr_interface_num, dimm_count, 0x55, 0x1);

    /* 5. Re-enable CONTROL[RDIMM_ENA]. */

    debug_print("5. Re-enable CONTROL[RDIMM_ENA].\n");

    set_rdimm_mode(node, ddr_interface_num, 1);

    /* 6. Re-enable refresh (REF_ZQCS_INT=previous value). */

    debug_print("6. Re-enable refresh (REF_ZQCS_INT=previous value).\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    lmc_config.s.ref_zqcs_int = save_ref_zqcs_int;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
}
#endif
#if RUN_INIT_SEQ_3
static void change_rdimm_mpr_pattern3 (bdk_node_t node, int rank_mask,
				       int ddr_interface_num, int dimm_count)
{
    int save_ref_zqcs_int;
    bdk_lmcx_config_t  lmc_config;
    int rankx;

    /*
     * From:	Gamulja, Andrew
     * Sent:	Thursday, January 08, 2015 6:59 PM
     * To:	Hooker, Franklin
     * Cc:	Lin, David; Dennison, Michael; Metzner, Brendan
     * Subject:	RE: Manual RDIMM bringup
     * 
     * Scratch my previous e-mail, I discovered some errors. This should be the correct sequence:
     */

    /* 1) Disable Refresh (CONFIG[REF_ZQCS_INT] = 0). */

    debug_print ("1) Disable Refresh (CONFIG[REF_ZQCS_INT] = 0).\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    save_ref_zqcs_int         = lmc_config.s.ref_zqcs_int;
    lmc_config.s.ref_zqcs_int = 0;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

    /* 2) Disable RCD Parity (if previously enabled) - parity does not work if inversion disabled. */

    debug_print("2) Disable RCD Parity\n");

#if 0
    /* 3) Disable Inversion in RCD. First set the CSR DIMM0_PARAMS[RC0<0>] = 1, 
       DIMM_CTL[DIMM0_WMASK] = 0x1. */

    debug_print("3) Disable Inversion in the RCD.\n");

    set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                               1 /* 1=disable output inversion*/);
#endif

    /* 4) Turn off lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 0. */

    debug_print("4) Disable CONTROL[RDIMM_ENA]\n");

    set_rdimm_mode(node, ddr_interface_num, 0);

    /*
     * 5) Set CONFIG[RANKMASK] = 0x0 (Rank 0 Init).
     */

    debug_print("5) Set CONFIG[RANKMASK] = 0x0 (Rank 0 Init).\n");

    /*
     * 6) Perform Init sequence (SEQ_CTL[SEQ_SEL] = 0, SEQ_CTL[INIT_START] = 1).
     * (Running Init to bring LMC into normal state. No MRS's are sent out since RANKMASK = 0).
     */

    debug_print("6) Perform Init sequence (SEQ_CTL[SEQ_SEL] = 0, SEQ_CTL[INIT_START] = 1).\n");

    {
        bdk_lmcx_modereg_params0_t lmc_modereg_params0;

        lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));

        lmc_modereg_params0.s.dllr = 1;
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);

        perform_octeon3_ddr3_sequence(node, 0 /* rankmask=0 */,
                                      ddr_interface_num, 0); /* power-up/init */

        lmc_modereg_params0.s.dllr = 0;
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);
    }

    for (rankx = 0; rankx < 8; rankx++) {
        if (!(rank_mask & (1 << rankx)))
            continue;

        /*
         * 7) Set DRAM's MR3 to both the A and B sides separately (two MRW sequence SEQ_CTL[SEQ_SEL] = 8,
         *  SEQ_CTL[INIT_START] = 1): 
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence: 
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 3.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("7) Set DRAM's MR3 to both the A and  sides separately (two MRW sequence SEQ_CTL[SEQ_SEL] = 8, SEQ_CTL[INIT_START] = 1\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x000,   3, 0); /* MR3 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x000), ~3, 1); /* MR3 B-side */

        /*
         * 8) Set DRAM's MR6 to both A and B sides separately (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 6.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("8) Set DRAM's MR6 to both A and B sides separately (two MRW sequence):\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x416,   6, 0); /* MR6 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x416), ~6, 1); /* MR6 B-side */

        /*
         * 9) Set DRAM's MR5 to both A and B sides (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:  
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 5.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("9) Set DRAM's MR5 to both A and B sides (two MRW sequence)\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x040,   5, 0); /* MR5 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x040), ~5, 1); /* MR5 B-side */

        /*
         * 10) Set DRAM's MR4 to both A and B sides (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:  
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 4.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("10) Set DRAM's MR4 to both A and B sides (two MRW sequence)\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x000,   4, 0); /* MR4 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x000), ~4, 1); /* MR4 B-side */

        /*
         * 11) Set DRAM's MR2 to both A and B sides (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:  
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 2.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("11) Set DRAM's MR2 to both A and B sides (two MRW sequence)\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x400,   2, 0); /* MR2 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x400), ~2, 1); /* MR2 B-side */

        /*
         * 12) Set DRAM's MR1 to both A and B sides (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:  
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 1.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("12) Set DRAM's MR1 to both A and B sides (two MRW sequence)\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x201,   1, 0); /* MR1 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x201), ~1, 1); /* MR1 B-side */

        /*
         * 13) Set DRAM's MR0 to both A and B sides (two MRW sequence):
         *      - A side: Set the CSR MR_MPR_CTL as follows before running the MRW sequence:  
         *                     MR_WR_BG1 = 0, MR_WR_USE_DEFAULT_VALUE = 1, MR_WR_SEL = 0.
         *      - B side: MR_WR_BG1 = 1.
         */

        debug_print("13) Set DRAM's MR0 to both A and B sides (two MRW sequence)\n");

        ddr4_mrw(node, ddr_interface_num, rankx,          0x318,   0, 0); /* MR0 A-side */
        ddr4_mrw(node, ddr_interface_num, rankx, InvA0_17(0x318), ~0, 1); /* MR0 B-side */

        /*
         * 14) Set CONFIG[RANKMASK] = current rank.
         */

        debug_print("14) Set CONFIG[RANKMASK] = current rank.\n");

        /*
         * 15) Perform Init sequence (SEQ_CTL[SEQ_SEL] = 0, SEQ_CTL[INIT_START] = 1).
         * (This will re-init the A-side only followed by ZQCL command).
         */

        debug_print("15) Perform Init sequence (SEQ_CTL[SEQ_SEL] = 0, SEQ_CTL[INIT_START] = 1).\n");

        perform_octeon3_ddr3_sequence(node, 1<<rankx,
                                      ddr_interface_num, 0); /* power-up/init */
        /*
         * 16) For multiple ranks (i.e., dual-rank dimm and/or two dimms), repeat Step 7-15. Adjust the 
         * MR_MPR_CTL[MR_WR_RANK] and CONFIG[RANKMASK] accordingly as follows:
         *        - rank0: MR_MPR_CTL[MR_WR_RANK] = 0, CONFIG[RANKMASK] = 0x1.  
         *        - rank1: MR_MPR_CTL[MR_WR_RANK] = 1, CONFIG[RANKMASK] = 0x2.
         *        - rank2: MR_MPR_CTL[MR_WR_RANK] = 2, CONFIG[RANKMASK] = 0x4.
         *        - rank3: MR_MPR_CTL[MR_WR_RANK] = 3, CONFIG[RANKMASK] = 0x8.
         */

        debug_print("16) For multiple ranks (i.e., dual-rank dimm and/or two dimms), repeat Step 7-15.\n");

    } /* for (rankx = 0; rankx < 8; rankx++) */

    for (rankx = 0; rankx < 8; rankx++) {
        if (!(rank_mask & (1 << rankx)))
            continue;


        /*
         * 17) Put all devices in MPR mode (Run MRW sequence (sequence=8) with 
         * MODEREG_PARAMS0[MPRLOC]=0, MODEREG_PARAMS0[MPR]=1, 
         * MR_MPR_CTL[MR_WR_SEL]=3, and MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=1). A side 
         * (MR_WR_BG1 = 0) and B side (MR_WR_BG1 = 1) need to be programmed separately.
         */
 
        debug_print("17) Put all devices in MPR mode (Run MRW sequence (sequence=8)\n");

        set_mpr_mode (node, 1<<rankx, ddr_interface_num, dimm_count, /* mpr */ 1, /* bg1 */ 0); /* A-side */
        set_mpr_mode (node, 1<<rankx, ddr_interface_num, dimm_count, /* mpr */ 1, /* bg1 */ 1); /* B-side */

#if 0
        /*
         * 17b) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1 (required for step 18&19).
         */

        debug_print("17b) Re-enable RDIMM_ENA\n");

        set_rdimm_mode(node, ddr_interface_num, 1);

        /* 17c) Disable Inversion in RCD. First set the CSR DIMM0_PARAMS[RC0<0>] = 1, 
           DIMM_CTL[DIMM0_WMASK] = 0x1. */

        debug_print("17c) Disable Inversion in the RCD.\n");

        set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                                   1 /* 1=disable output inversion*/);

        /*
         * 17d) Disable lmc's RDIMM mode. Control[RDIMM_ENA] = 0.
         * 
         */

        debug_print("17d) Disable CONTROL[RDIMM_ENA]\n");

        set_rdimm_mode(node, ddr_interface_num, 0);

        /* 
         * 18) Write all 4 MPR registers with the desired pattern (have to do this for all enabled ranks). 
         * (sequence=9). 
         *         MR_MPR_CTL.MPR_WR=1, MR_MPR_CTL.MPR_LOC=0..3, MR_MPR_CTL.MR_WR_SEL=0, 
         * MR_MPR_CTL.MR_WR_ADDR[7:0]=pattern
         */

        debug_print("16) Write all 4 MPR page 0 Training Patterns\n");

        write_mpr_page0_pattern(node, 1<<rankx,
                                 ddr_interface_num, dimm_count, 0x55, 0x8);

#else
        /* KC's workaround, update the steps as follow: */

        /*
         * 18) MR3 Write. Replace this step with the following:
         * 
         * 18b) Do MPR Write sequence (MR_MPR_CTL.MPR_WR=1,
         * MR_MPR_CTL.MR_WR_SEL=0, MR_MPR_CTL.MPR_LOC=0,
         * MR_MPR_CTL.MR_WR_ADDR = 0xAD, sequence=9).
         */

        write_mpr_page0_pattern(node, 1<<rankx,
                                 ddr_interface_num, dimm_count, 0xAD, 0x1);

        /*
         * 18c) Disable MPR mode on B side MR3 (DEFAULT_VALUE = 0).
         */

        set_mpr_mode(node, rank_mask, ddr_interface_num, dimm_count, /* mpr */ 0, /* bg1 */ 1); /* B-side */

        /*
         * 18d) Do MPR Write sequence (MR_MPR_CTL.MPR_WR=1,
         * MR_MPR_CTL.MR_WR_SEL=0, MR_MPR_CTL.MPR_LOC=0,
         * MR_MPR_CTL.MR_WR_ADDR = 0x55, sequence=9). (Write command
         * without activate will be send out to B-side).
         */

        write_mpr_page0_pattern (node, 1<<rankx,
                                 ddr_interface_num, dimm_count, 0x55, 0x1);

#endif
    } /* for (rankx = 0; rankx < 8; rankx++) */

#if 0
    /*
     * 19) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1 (required for step 18&19).
     */

    debug_print("19) Re-enable RDIMM_ENA\n");

    set_rdimm_mode(node, ddr_interface_num, 1);

    /*
     * 20) Re-enable RDIMM inversion.
     */

    debug_print("20) Re-enable RDIMM inversion\n");

    set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, 1<<rankx,
                               0 /* 0=re-enable output inversion*/);

    /*
     * 21) Re-enable RDIMM parity (if desired)
     */

    debug_print("21) Re-enable RDIMM parity (if desired)\n");

#endif

    /*
     * 22) Re-enable refresh (REF_ZQCS_INT=previous value)
     */

    debug_print("22)Re-enable refresh (REF_ZQCS_INT=previous value)\n");

    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    lmc_config.s.ref_zqcs_int = save_ref_zqcs_int;
    DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

    /*
     * 23) Disable lmc's RDIMM mode. Control[RDIMM_ENA] = 0.
     * 
     */

    debug_print("23) Disable CONTROL[RDIMM_ENA]\n");

    set_rdimm_mode(node, ddr_interface_num, 0);
}
#endif

static unsigned char ddr4_rodt_ohms     [RODT_OHMS_COUNT     ] = {  0,  40,  60, 80, 120, 240, 34, 48 };
static unsigned char ddr4_rtt_nom_ohms  [RTT_NOM_OHMS_COUNT  ] = {  0,  60, 120, 40, 240,  48, 80, 34 };
static unsigned char ddr4_rtt_nom_table [RTT_NOM_TABLE_COUNT ] = {  0,   4,   2,  6,   1,   5,  3,  7 };
static unsigned char ddr4_rtt_wr_ohms   [RTT_WR_OHMS_COUNT   ] = {  0, 120,  240, -1,  80 };
static unsigned char ddr4_dic_ohms      [DIC_OHMS_COUNT      ] = { 34,  48 };
static short         ddr4_drive_strength[DRIVE_STRENGTH_COUNT] = {  0,   0, 26, 30, 34, 40, 48, 68, 0,0,0,0,0,0,0 };
static short         ddr4_dqx_strength  [DRIVE_STRENGTH_COUNT] = {  0,  24, 27, 30, 34, 40, 48, 60, 0,0,0,0,0,0,0 };
static impedence_values_t ddr4_impedence_values = {
    .rodt_ohms             =  ddr4_rodt_ohms     ,
    .rtt_nom_ohms          =  ddr4_rtt_nom_ohms  ,
    .rtt_nom_table         =  ddr4_rtt_nom_table ,
    .rtt_wr_ohms           =  ddr4_rtt_wr_ohms   ,
    .dic_ohms              =  ddr4_dic_ohms      ,
    .drive_strength        =  ddr4_drive_strength,
    .dqx_strength          =  ddr4_dqx_strength  ,
};

static unsigned char ddr3_rodt_ohms     [RODT_OHMS_COUNT     ] = { 0, 20, 30, 40, 60, 120, 0, 0 };
static unsigned char ddr3_rtt_nom_ohms  [RTT_NOM_OHMS_COUNT  ] = { 0, 60, 120, 40, 20, 30, 0, 0 };
static unsigned char ddr3_rtt_nom_table [RTT_NOM_TABLE_COUNT ] = { 0, 2, 1, 3, 5, 4, 0, 0 };
static unsigned char ddr3_rtt_wr_ohms   [RTT_WR_OHMS_COUNT   ] = { 0, 60, 120 };
static unsigned char ddr3_dic_ohms      [DIC_OHMS_COUNT      ] = { 40, 34 };
static short         ddr3_drive_strength[DRIVE_STRENGTH_COUNT] = { 0, 24, 27, 30, 34, 40, 48, 60, 0,0,0,0,0,0,0 };
static impedence_values_t ddr3_impedence_values = {
    .rodt_ohms             =  ddr3_rodt_ohms     ,
    .rtt_nom_ohms          =  ddr3_rtt_nom_ohms  ,
    .rtt_nom_table         =  ddr3_rtt_nom_table ,
    .rtt_wr_ohms           =  ddr3_rtt_wr_ohms   ,
    .dic_ohms              =  ddr3_dic_ohms      ,
    .drive_strength        =  ddr3_drive_strength,
    .dqx_strength          =  ddr3_drive_strength,
};


#define DEBUG_RC3X_COMPUTE 0
#define rc3x_print(...) \
    do { if (DEBUG_RC3X_COMPUTE) printf(__VA_ARGS__); } while (0)

static int compute_rc3x (int64_t tclk_psecs)
{
    long speed;
    long tclk_psecs_min, tclk_psecs_max;
    long data_rate_mhz, data_rate_mhz_min, data_rate_mhz_max;
    int rc3x;

#define DIVIDEND_SCALE 1000      /* Scale by 100 to avoid rounding error. */
#define ENCODING_BASE 1240

    data_rate_mhz = divide_nint(divide_nint((2 * 1000000 * DIVIDEND_SCALE), (tclk_psecs)), DIVIDEND_SCALE);

    /* 2400 MT/s is a special case. Using integer arithmetic it rounds
       from 833 psecs to 2401 MT/s. Force it to 2400 to pick the
       proper setting from the table. */
    if (tclk_psecs == 833)
        data_rate_mhz = 2400;

    for (speed = ENCODING_BASE; speed < 3200; speed += 20) {
        int error = 0;
        tclk_psecs_min = divide_nint((uint64_t) 1000*1000*1000*1000, (speed + 00) * 1000*1000 / 2 ); /* Clock in psecs */
        tclk_psecs_max = divide_nint((uint64_t) 1000*1000*1000*1000, (speed + 18) * 1000*1000 / 2 ); /* Clock in psecs */

        data_rate_mhz_min = divide_nint((2 * 1000000 * DIVIDEND_SCALE), (tclk_psecs_min)) / DIVIDEND_SCALE;
        data_rate_mhz_max = divide_nint((2 * 1000000 * DIVIDEND_SCALE), (tclk_psecs_max)) / DIVIDEND_SCALE;

        /* Force alingment to multiple to avound rounding errors. */
        data_rate_mhz_min = ((data_rate_mhz_min + 18) / 20) * 20;
        data_rate_mhz_max = ((data_rate_mhz_max + 18) / 20) * 20;

        error += (speed + 00 != data_rate_mhz_min);
        error += (speed + 20 != data_rate_mhz_max);

        rc3x = (speed - ENCODING_BASE) / 20;

        rc3x_print("rc3x: %02x speed: %4ld MT/s < f <= %4ld MT/s, psec: %3ld:%3ld %4ld:%4ld %s\n",
                   rc3x,
                   speed, speed + 20,
                   tclk_psecs_min, tclk_psecs_max,
                   data_rate_mhz_min, data_rate_mhz_max,
                   error ? "****" : "");

        if (data_rate_mhz <= (speed + 20)) {
            rc3x_print("rc3x: %4ld MT/s <= %4ld MT/s\n", data_rate_mhz, speed + 20);
            break;
        }
    }
    return rc3x;
}

static const int   run_init_sequence_1 = RUN_INIT_SEQ_1;
static const int   run_init_sequence_2 = RUN_INIT_SEQ_2;
static const int   run_init_sequence_3 = RUN_INIT_SEQ_3;

static const int   rlevel_separate_ab  = 1;

int init_octeon3_ddr3_interface(bdk_node_t node,
                               const ddr_configuration_t *ddr_configuration,
                               uint32_t ddr_hertz,
                               uint32_t cpu_hertz,
                               uint32_t ddr_ref_hertz,
                               int board_type,
                               int board_rev_maj,
                               int board_rev_min,
                               int ddr_interface_num,
                               uint32_t ddr_interface_mask
                               )
{
    const char *s;

    const dimm_odt_config_t *odt_1rank_config = ddr_configuration->odt_1rank_config;
    const dimm_odt_config_t *odt_2rank_config = ddr_configuration->odt_2rank_config;
    const dimm_odt_config_t *odt_4rank_config = ddr_configuration->odt_4rank_config;
    const dimm_config_t *dimm_config_table = ddr_configuration->dimm_config_table;
    const dimm_odt_config_t *odt_config;
    const ddr3_custom_config_t *custom_lmc_config = &ddr_configuration->custom_lmc_config;
    int odt_idx;

    /*
    ** Compute clock rates to the nearest picosecond.
    */
    uint64_t tclk_psecs = divide_nint((uint64_t) 1000*1000*1000*1000, ddr_hertz); /* Clock in psecs */
    uint64_t eclk_psecs = divide_nint((uint64_t) 1000*1000*1000*1000, cpu_hertz); /* Clock in psecs */

    int row_bits, col_bits, num_banks, num_ranks, dram_width;
    int dimm_count = 0;
    int fatal_error = 0;        /* Accumulate and report all the errors before giving up */

    int safe_ddr_flag = 0; /* Flag that indicates safe DDR settings should be used */
    int ddr_interface_64b = 1;  /* Octeon II Default: 64bit interface width */
    int ddr_interface_bytemask;
    uint32_t mem_size_mbytes = 0;
    unsigned int didx;
    int bank_bits = 0;
    int bunk_enable;
    int rank_mask;
    int column_bits_start = 1;
    int row_lsb;
    int pbank_lsb;
    int use_ecc = 1;
    int mtb_psec = 0; /* quiet */
    short ftb_Dividend;
    short ftb_Divisor;
    int tAAmin;
    int tCKmin;
    int CL, min_cas_latency = 0, max_cas_latency = 0, override_cas_latency = 0;
    int ddr_rtt_nom_auto, ddr_rodt_ctl_auto;
    int i;

    int spd_addr;
    int spd_org;
    int spd_banks;
    int spd_rdimm;
    int spd_dimm_type;
    int spd_ecc;
    uint32_t spd_cas_latency;
    int spd_mtb_dividend;
    int spd_mtb_divisor;
    int spd_tck_min;
    int spd_taa_min;
    int spd_twr;
    int spd_trcd;
    int spd_trrd;
    int spd_trp;
    int spd_tras;
    int spd_trc;
    int spd_trfc;
    int spd_twtr;
    int spd_trtp;
    int spd_tfaw;
    int spd_addr_mirror;
    int spd_package = 0;
    int spd_rawcard = 0;

    /* FTB values are two's complement ranging from +127 to -128. */
    typedef signed char SC_t;

    int twr;
    int trcd;
    int trrd;
    int trp;
    int tras;
    int trc;
    int trfc;
    int twtr;
    int trtp = 0;  /* quiet */
    int tfaw;

    int wlevel_bitmask_errors = 0;
    int wlevel_loops = 0;
    int default_rtt_nom[4];
    int dyn_rtt_nom_mask = 0;

    ddr_type_t ddr_type;
    int ddr4_tCKAVGmin = 0; /* quiet */
    int ddr4_tCKAVGmax = 0; /* quiet */
    int ddr4_tRCDmin = 0; /* quiet */
    int ddr4_tRPmin = 0; /* quiet */
    int ddr4_tRASmin = 0; /* quiet */
    int ddr4_tRCmin = 0; /* quiet */
    int ddr4_tRFC1min = 0; /* quiet */
    int ddr4_tRFC2min = 0; /* quiet */
    int ddr4_tRFC4min = 0; /* quiet */
    int ddr4_tFAWmin = 0; /* quiet */
    int ddr4_tRRD_Smin = 0; /* quiet */
    int ddr4_tRRD_Lmin;
    int ddr4_tCCD_Lmin;
    impedence_values_t *imp_values;

    /* Initialize these to shut up the compiler. They are configured
       and used only for DDR4  */
    ddr4_tRRD_Lmin = 6000;
    ddr4_tCCD_Lmin = 6000;

    ddr_print("\nInitializing node %d DDR interface %d, DDR Clock %d, DDR Reference Clock %d\n",
              node, ddr_interface_num, ddr_hertz, ddr_ref_hertz);

    if (dimm_config_table[0].spd_addrs[0] == 0 && !dimm_config_table[0].spd_ptrs[0]) {
        error_print("ERROR: No dimms specified in the dimm_config_table.\n");
        return (-1);
    }

#if 0 // FIXME: do we really need this anymore?
    if (dram_is_verbose(NORMAL)) {
        printf("DDR SPD Table:");
        for (didx = 0; didx < DDR_CFG_T_MAX_DIMMS; ++didx) {
            if (dimm_config_table[didx].spd_addrs[0] == 0) break;
            printf(" --ddr%dspd=0x%02x", ddr_interface_num, dimm_config_table[didx].spd_addrs[0]);
            if (dimm_config_table[didx].spd_addrs[1] != 0)
                printf(",0x%02x", dimm_config_table[didx].spd_addrs[1]);
        }
        printf("\n");
    }
#endif

    /*
    ** Walk the DRAM Socket Configuration Table to see what is installed.
    */
    for (didx = 0; didx < DDR_CFG_T_MAX_DIMMS; ++didx)
    {
        /* Check for lower DIMM socket populated */
        if (validate_dimm(node, &dimm_config_table[didx], 0)) {
            if (dram_is_verbose(NORMAL))
                report_dimm(node, &dimm_config_table[didx], 0, dimm_count);
            ++dimm_count;
        } else { break; }       /* Finished when there is no lower DIMM */
    }


    initialize_ddr_clock(node,
			 ddr_configuration,
			 cpu_hertz,
			 ddr_hertz,
			 ddr_ref_hertz,
			 ddr_interface_num,
			 ddr_interface_mask);

    if (!odt_1rank_config)
        odt_1rank_config = disable_odt_config;
    if (!odt_2rank_config)
        odt_2rank_config = disable_odt_config;
    if (!odt_4rank_config)
        odt_4rank_config = disable_odt_config;

    if ((s = lookup_env_parameter("ddr_safe")) != NULL) {
        safe_ddr_flag = !!strtoul(s, NULL, 0);
    }


    if (dimm_count == 0) {
        error_print("ERROR: DIMM 0 not detected.\n");
        return(-1);
    }

    if (custom_lmc_config->mode32b)
        ddr_interface_64b = 0;

    if ((s = lookup_env_parameter("ddr_interface_64b")) != NULL) {
        ddr_interface_64b = !!strtoul(s, NULL, 0);
    }

    if (ddr_interface_64b == 0) {
        error_print("32-bit interface width is not supported for this Octeon model\n");
        ++fatal_error;
    }

    /* ddr_type only indicates DDR4 or DDR3 */
    ddr_type = get_ddr_type(node, &dimm_config_table[0], 0);
    debug_print("DRAM Device Type: DDR%d\n", ddr_type);

    spd_dimm_type = get_dimm_module_type(node, &dimm_config_table[0], 0, ddr_type);

    if (ddr_type == DDR4_DRAM) {
        imp_values = &ddr4_impedence_values;

        spd_addr = read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_ADDRESSING_ROW_COL_BITS);
        spd_org = read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MODULE_ORGANIZATION);
        spd_banks = read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_DENSITY_BANKS) & 0xff;

        bank_bits = (2 + ((spd_banks >> 4) & 0x3)) + ((spd_banks >> 6) & 0x3);
        bank_bits = min((int)bank_bits, 4); /* Controller can only address 4 bits. */

	spd_package = read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_PACKAGE_TYPE);
	debug_print("DDR4: Package Type 0x%x \n", spd_package);

        spd_rdimm       = (spd_dimm_type == 1);
	if (spd_rdimm) {
	    int spd_mfgr_id = read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_REGISTER_MANUFACTURER_ID_LSB) |
		(read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_REGISTER_MANUFACTURER_ID_MSB) << 8);
	    extra_ddr_print("DDR4: RDIMM Register Manufacturer ID 0x%x \n", spd_mfgr_id);

	    // RAW CARD must be bit 7=0 and bits 4-0 either 00000 or 00001 
	    spd_rawcard = 0xFF & read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_RDIMM_REFERENCE_RAW_CARD);
	    extra_ddr_print("DDR4: RDIMM Reference Raw Card 0x%x \n", spd_rawcard);
	    spd_rawcard = ((spd_rawcard & 0x9fUL) <= 1);
	}
    } else {
        imp_values = &ddr3_impedence_values;

        spd_addr = read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_ADDRESSING_ROW_COL_BITS);
        spd_org = read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MODULE_ORGANIZATION);
        spd_banks = read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_DENSITY_BANKS) & 0xff;

        bank_bits = 3 + ((spd_banks >> 4) & 0x7);
        bank_bits = min((int)bank_bits, 3); /* Controller can only address 3 bits. */

        spd_rdimm       = (spd_dimm_type == 1) || (spd_dimm_type == 5) || (spd_dimm_type == 9);
    }

#if 0 // FIXME: why should this be possible OR needed?
    if ((s = lookup_env_parameter("ddr_rdimm_ena")) != NULL) {
        spd_rdimm = !!strtoul(s, NULL, 0);
    }
#endif

    debug_print("spd_addr        : %#06x\n", spd_addr );
    debug_print("spd_org         : %#06x\n", spd_org );
    debug_print("spd_banks       : %#06x\n", spd_banks );

    row_bits = 12 + ((spd_addr >> 3) & 0x7);
    col_bits =  9 + ((spd_addr >> 0) & 0x7);

    num_ranks =  1 + ((spd_org >> 3) & 0x7);
    dram_width = 4 << ((spd_org >> 0) & 0x7);
    num_banks = 1 << bank_bits;

    if ((s = lookup_env_parameter("ddr_num_ranks")) != NULL) {
        num_ranks = strtoul(s, NULL, 0);
    }

    /* FIX
    ** Check that values are within some theoretical limits.
    ** col_bits(min) = row_lsb(min) - bank_bits(max) - bus_bits(max) = 14 - 3 - 4 = 7
    ** col_bits(max) = row_lsb(max) - bank_bits(min) - bus_bits(min) = 18 - 2 - 3 = 13
    */
    if ((col_bits > 13) || (col_bits < 7)) {
        error_print("Unsupported number of Col Bits: %d\n", col_bits);
        ++fatal_error;
    }

    /* FIX
    ** Check that values are within some theoretical limits.
    ** row_bits(min) = pbank_lsb(min) - row_lsb(max) - rank_bits = 26 - 18 - 1 = 7
    ** row_bits(max) = pbank_lsb(max) - row_lsb(min) - rank_bits = 33 - 14 - 1 = 18
    */
    if ((row_bits > 18) || (row_bits < 7)) {
        error_print("Unsupported number of Row Bits: %d\n", row_bits);
        ++fatal_error;
    }

    wlevel_loops = 1;

    if (bdk_is_platform(BDK_PLATFORM_ASIM))
        wlevel_loops = 0;

    if ((s = lookup_env_parameter("ddr%d_wlevel_loops", ddr_interface_num)) != NULL) {
        wlevel_loops = strtoul(s, NULL, 0);
    }

    bunk_enable = (num_ranks > 1);

    column_bits_start = 3;

    row_lsb = column_bits_start + col_bits + bank_bits - (! ddr_interface_64b);
    debug_print("row_lsb = column_bits_start + col_bits + bank_bits = %d\n", row_lsb);

    pbank_lsb = row_lsb + row_bits + bunk_enable;
    debug_print("pbank_lsb = row_lsb + row_bits + bunk_enable = %d\n", pbank_lsb);


    mem_size_mbytes =  dimm_count * ((1ull << pbank_lsb) >> 20);
    if (num_ranks == 4) {
        /* Quad rank dimm capacity is equivalent to two dual-rank dimms. */
        mem_size_mbytes *= 2;
    }

    /* Mask with 1 bits set for for each active rank, allowing 2 bits per dimm.
    ** This makes later calculations simpler, as a variety of CSRs use this layout.
    ** This init needs to be updated for dual configs (ie non-identical DIMMs).
    ** Bit 0 = dimm0, rank 0
    ** Bit 1 = dimm0, rank 1
    ** Bit 2 = dimm1, rank 0
    ** Bit 3 = dimm1, rank 1
    ** ...
    */
    rank_mask = 0x1;
    if (num_ranks > 1)
        rank_mask = 0x3;
    if (num_ranks > 2)
        rank_mask = 0xf;

    for (i = 1; i < dimm_count; i++)
        rank_mask |= ((rank_mask & 0x3) << (2*i));


#ifdef CAVIUM_ONLY
    /* Special request: mismatched DIMM support. Slot 0: 2-Rank, Slot 1: 1-Rank */
    if (0)
    {
        /*
        ** Calculate the total memory size in terms of the total
        ** number of ranks instead of the number of dimms.  The usual
        ** requirement is for both dimms to be identical.  This check
        ** works around that requirement to allow one exception.  The
        ** dimm in the second slot may now have fewer ranks than the
        ** first slot.
        */
        int spd_org_dimm1;
        int num_ranks_dimm1;
        int rank_count;
        int rank_mask_dimm1;

        if (dimm_count > 1) {
            spd_org_dimm1 = read_spd(node, &dimm_config_table[1] /* dimm 1*/,
                                     0, DDR3_SPD_MODULE_ORGANIZATION);
            num_ranks_dimm1 = 1 + ((spd_org_dimm1 >> 3) & 0x7);
            rank_count =  num_ranks/* dimm 0 */ + num_ranks_dimm1 /* dimm 1 */;

            if (num_ranks != num_ranks_dimm1) {
                mem_size_mbytes =  rank_count * ((1ull << (pbank_lsb-bunk_enable)) >> 20);
                rank_mask = 1 | ((num_ranks > 1) << 1);
                rank_mask_dimm1 = 1 | ((num_ranks_dimm1 > 1) << 1);
                rank_mask |= ((rank_mask_dimm1 & 0x3) << 2);
                ddr_print("DIMM 1 - ranks: %d, size: %d MB\n",
                          num_ranks_dimm1, num_ranks_dimm1 * ((1ull << (pbank_lsb-bunk_enable)) >> 20));
            }
        }
    }
#endif  /* CAVIUM_ONLY */

    ddr_print("row bits: %d, col bits: %d, bank bits: %d, banks: %d, ranks: %d, dram width: %d, size: %d MB\n",
              row_bits, col_bits, bank_bits, num_banks, num_ranks, dram_width, mem_size_mbytes);

    spd_ecc = get_dimm_ecc(node, &dimm_config_table[0], 0, ddr_type);

    if (ddr_type == DDR4_DRAM) {
	spd_cas_latency  = ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_CAS_LATENCIES_BYTE0)) <<  0);
	spd_cas_latency |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_CAS_LATENCIES_BYTE1)) <<  8);
	spd_cas_latency |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_CAS_LATENCIES_BYTE2)) << 16);
	spd_cas_latency |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_CAS_LATENCIES_BYTE3)) << 24);
    } else {
	spd_cas_latency  = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_CAS_LATENCIES_LSB);
	spd_cas_latency |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_CAS_LATENCIES_MSB)) << 8);
    }
    debug_print("spd_cas_latency : %#06x\n", spd_cas_latency );

    if (ddr_type == DDR4_DRAM) {

        /* No other values for DDR4 MTB and FTB are specified at the
         * current time so don't bother reading them. Can't speculate how
         * new values will be represented.
         */
        int spdMTB = 125;
        int spdFTB = 1;

        tAAmin
	  = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_CAS_LATENCY_TAAMIN)
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_CAS_LATENCY_FINE_TAAMIN);

        ddr4_tCKAVGmin
	  = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MINIMUM_CYCLE_TIME_TCKAVGMIN)
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_CYCLE_TIME_FINE_TCKAVGMIN);

        ddr4_tCKAVGmax
	  = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MAXIMUM_CYCLE_TIME_TCKAVGMAX)
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MAX_CYCLE_TIME_FINE_TCKAVGMAX);

        ddr4_tRCDmin
	  = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_RAS_CAS_DELAY_TRCDMIN)
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_RAS_TO_CAS_DELAY_FINE_TRCDMIN);

        ddr4_tRPmin
	  = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ROW_PRECHARGE_DELAY_TRPMIN)
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ROW_PRECHARGE_DELAY_FINE_TRPMIN);

        ddr4_tRASmin
	  = spdMTB * (((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_UPPER_NIBBLES_TRAS_TRC) & 0xf) << 8) +
		      ( read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ACTIVE_PRECHARGE_LSB_TRASMIN) & 0xff));

        ddr4_tRCmin
	  = spdMTB * ((((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_UPPER_NIBBLES_TRAS_TRC) >> 4) & 0xf) << 8) +
		      (  read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ACTIVE_REFRESH_LSB_TRCMIN) & 0xff))
	  + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ACT_TO_ACT_REFRESH_DELAY_FINE_TRCMIN);

        ddr4_tRFC1min
	  = spdMTB * (((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_MSB_TRFC1MIN) & 0xff) << 8) +
		      ( read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_LSB_TRFC1MIN) & 0xff));

        ddr4_tRFC2min
            = spdMTB * (((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_MSB_TRFC2MIN) & 0xff) << 8) +
                        ( read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_LSB_TRFC2MIN) & 0xff));

        ddr4_tRFC4min
            = spdMTB * (((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_MSB_TRFC4MIN) & 0xff) << 8) +
                        ( read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_REFRESH_RECOVERY_LSB_TRFC4MIN) & 0xff));

        ddr4_tFAWmin
            = spdMTB * (((read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_FOUR_ACTIVE_WINDOW_MSN_TFAWMIN) & 0xf) << 8) +
                        ( read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_FOUR_ACTIVE_WINDOW_LSB_TFAWMIN) & 0xff));

        ddr4_tRRD_Smin
            = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ROW_ACTIVE_DELAY_SAME_TRRD_SMIN)
            + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ACT_TO_ACT_DELAY_DIFF_FINE_TRRD_SMIN);

        ddr4_tRRD_Lmin
            = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ROW_ACTIVE_DELAY_DIFF_TRRD_LMIN)
            + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_ACT_TO_ACT_DELAY_SAME_FINE_TRRD_LMIN);

        ddr4_tCCD_Lmin
            = spdMTB *        read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_CAS_TO_CAS_DELAY_TCCD_LMIN)
            + spdFTB * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR4_SPD_MIN_CAS_TO_CAS_DELAY_FINE_TCCD_LMIN);

        ddr_print("%-45s : %6d ps\n", "Medium Timebase (MTB)",          		   spdMTB);
        ddr_print("%-45s : %6d ps\n", "Fine Timebase   (FTB)",          		   spdFTB);

    #define DDR4_TWR 15000
    #define DDR4_TWTR_S 2500


        tCKmin	        = ddr4_tCKAVGmin;
        twr             = DDR4_TWR;
        trcd            = ddr4_tRCDmin;
        trrd            = ddr4_tRRD_Smin;
        trp             = ddr4_tRPmin;
        tras            = ddr4_tRASmin;
        trc             = ddr4_tRCmin;
        trfc            = ddr4_tRFC1min;
        twtr            = DDR4_TWTR_S;
        tfaw            = ddr4_tFAWmin;

        if (spd_rdimm) {
	    spd_addr_mirror = read_spd(node, &dimm_config_table[0], 0,DDR4_SPD_RDIMM_ADDR_MAPPING_FROM_REGISTER_TO_DRAM) & 0x1;
        } else {
	    spd_addr_mirror = read_spd(node, &dimm_config_table[0], 0,DDR4_SPD_UDIMM_ADDR_MAPPING_FROM_EDGE) & 0x1;
        }
        debug_print("spd_addr_mirror : %#06x\n", spd_addr_mirror );

    } else { /* if (ddr_type == DDR4_DRAM) */
        spd_mtb_dividend = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MEDIUM_TIMEBASE_DIVIDEND);
        spd_mtb_divisor  = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MEDIUM_TIMEBASE_DIVISOR);
        spd_tck_min      = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MINIMUM_CYCLE_TIME_TCKMIN);
        spd_taa_min      = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_CAS_LATENCY_TAAMIN);

        spd_twr          = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_WRITE_RECOVERY_TWRMIN);
        spd_trcd         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_RAS_CAS_DELAY_TRCDMIN);
        spd_trrd         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_ROW_ACTIVE_DELAY_TRRDMIN);
        spd_trp          = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_ROW_PRECHARGE_DELAY_TRPMIN);
        spd_tras         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_ACTIVE_PRECHARGE_LSB_TRASMIN);
        spd_tras        |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_UPPER_NIBBLES_TRAS_TRC)&0xf) << 8);
        spd_trc          = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_ACTIVE_REFRESH_LSB_TRCMIN);
        spd_trc         |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_UPPER_NIBBLES_TRAS_TRC)&0xf0) << 4);
        spd_trfc         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_REFRESH_RECOVERY_LSB_TRFCMIN);
        spd_trfc        |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_REFRESH_RECOVERY_MSB_TRFCMIN)) << 8);
        spd_twtr         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_INTERNAL_WRITE_READ_CMD_TWTRMIN);
        spd_trtp         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_INTERNAL_READ_PRECHARGE_CMD_TRTPMIN);
        spd_tfaw         = 0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_FOUR_ACTIVE_WINDOW_TFAWMIN);
        spd_tfaw        |= ((0xff & read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_UPPER_NIBBLE_TFAW)&0xf) << 8);
        spd_addr_mirror  = 0xff & read_spd(node, &dimm_config_table[0], 0,DDR3_SPD_ADDRESS_MAPPING) & 0x1;
        spd_addr_mirror  = spd_addr_mirror && !spd_rdimm; /* Only address mirror unbuffered dimms.  */
        ftb_Dividend     = read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_FINE_TIMEBASE_DIVIDEND_DIVISOR) >> 4;
        ftb_Divisor      = read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_FINE_TIMEBASE_DIVIDEND_DIVISOR) & 0xf;
        ftb_Divisor      = (ftb_Divisor == 0) ? 1 : ftb_Divisor; /* Make sure that it is not 0 */

        debug_print("spd_twr         : %#06x\n", spd_twr );
        debug_print("spd_trcd        : %#06x\n", spd_trcd);
        debug_print("spd_trrd        : %#06x\n", spd_trrd);
        debug_print("spd_trp         : %#06x\n", spd_trp );
        debug_print("spd_tras        : %#06x\n", spd_tras);
        debug_print("spd_trc         : %#06x\n", spd_trc );
        debug_print("spd_trfc        : %#06x\n", spd_trfc);
        debug_print("spd_twtr        : %#06x\n", spd_twtr);
        debug_print("spd_trtp        : %#06x\n", spd_trtp);
        debug_print("spd_tfaw        : %#06x\n", spd_tfaw);
        debug_print("spd_addr_mirror : %#06x\n", spd_addr_mirror);

        mtb_psec        = spd_mtb_dividend * 1000 / spd_mtb_divisor;
        tAAmin          = mtb_psec * spd_taa_min;
        tAAmin         += ftb_Dividend * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MIN_CAS_LATENCY_FINE_TAAMIN) / ftb_Divisor;
        tCKmin          = mtb_psec * spd_tck_min;
        tCKmin         += ftb_Dividend * (SC_t) read_spd(node, &dimm_config_table[0], 0, DDR3_SPD_MINIMUM_CYCLE_TIME_FINE_TCKMIN) / ftb_Divisor;

        twr             = spd_twr  * mtb_psec;
        trcd            = spd_trcd * mtb_psec;
        trrd            = spd_trrd * mtb_psec;
        trp             = spd_trp  * mtb_psec;
        tras            = spd_tras * mtb_psec;
        trc             = spd_trc  * mtb_psec;
        trfc            = spd_trfc * mtb_psec;
        twtr            = spd_twtr * mtb_psec;
        trtp            = spd_trtp * mtb_psec;
        tfaw            = spd_tfaw * mtb_psec;

    } /* if (ddr_type == DDR4_DRAM) */

    if (ddr_type == DDR4_DRAM) {
        ddr_print("%-45s : %6d ps\n", "SDRAM Minimum Cycle Time (tCKAVGmin)",          ddr4_tCKAVGmin);
        ddr_print("%-45s : %6d ps\n", "SDRAM Maximum Cycle Time (tCKAVGmax)",          ddr4_tCKAVGmax);
        ddr_print("%-45s : %6d ps\n", "Minimum CAS Latency Time (tAAmin)",             tAAmin);
        ddr_print("%-45s : %6d ps\n", "Minimum RAS to CAS Delay Time (tRCDmin)",       ddr4_tRCDmin);
        ddr_print("%-45s : %6d ps\n", "Minimum Row Precharge Delay Time (tRPmin)",     ddr4_tRPmin);
        ddr_print("%-45s : %6d ps\n", "Minimum Active to Precharge Delay (tRASmin)",   ddr4_tRASmin);
        ddr_print("%-45s : %6d ps\n", "Minimum Active to Active/Refr. Delay (tRCmin)", ddr4_tRCmin);
        ddr_print("%-45s : %6d ps\n", "Minimum Refresh Recovery Delay (tRFC1min)",     ddr4_tRFC1min);
        ddr_print("%-45s : %6d ps\n", "Minimum Refresh Recovery Delay (tRFC2min)",     ddr4_tRFC2min);
        ddr_print("%-45s : %6d ps\n", "Minimum Refresh Recovery Delay (tRFC4min)",     ddr4_tRFC4min);
        ddr_print("%-45s : %6d ps\n", "Minimum Four Activate Window Time (tFAWmin)",   ddr4_tFAWmin);
        ddr_print("%-45s : %6d ps\n", "Minimum Act. to Act. Delay (tRRD_Smin)",        ddr4_tRRD_Smin);
        ddr_print("%-45s : %6d ps\n", "Minimum Act. to Act. Delay (tRRD_Lmin)",        ddr4_tRRD_Lmin);
        ddr_print("%-45s : %6d ps\n", "Minimum CAS to CAS Delay Time (tCCD_Lmin)",     ddr4_tCCD_Lmin);
    } else {
	ddr_print("Medium Timebase (MTB)                         : %6d ps\n", mtb_psec);
	ddr_print("Minimum Cycle Time (tCKmin)                   : %6d ps\n", tCKmin);
	ddr_print("Minimum CAS Latency Time (tAAmin)             : %6d ps\n", tAAmin);
	ddr_print("Write Recovery Time (tWR)                     : %6d ps\n", twr);
	ddr_print("Minimum RAS to CAS delay (tRCD)               : %6d ps\n", trcd);
	ddr_print("Minimum Row Active to Row Active delay (tRRD) : %6d ps\n", trrd);
	ddr_print("Minimum Row Precharge Delay (tRP)             : %6d ps\n", trp);
	ddr_print("Minimum Active to Precharge (tRAS)            : %6d ps\n", tras);
	ddr_print("Minimum Active to Active/Refresh Delay (tRC)  : %6d ps\n", trc);
	ddr_print("Minimum Refresh Recovery Delay (tRFC)         : %6d ps\n", trfc);
	ddr_print("Internal write to read command delay (tWTR)   : %6d ps\n", twtr);
	ddr_print("Min Internal Rd to Precharge Cmd Delay (tRTP) : %6d ps\n", trtp);
	ddr_print("Minimum Four Activate Window Delay (tFAW)     : %6d ps\n", tfaw);
    }


    /* When the cycle time is within 1 psec of the minimum accept it
       as a slight rounding error and adjust it to exactly the minimum
       cycle time. This avoids an unnecessary warning. */
    if (_abs(tclk_psecs - tCKmin) < 2)
        tclk_psecs = tCKmin;

    if (tclk_psecs < (uint64_t)tCKmin) {
        error_print("WARNING!!!!: DDR Clock Rate (tCLK: %ld) exceeds DIMM specifications (tCKmin: %ld)!!!!\n",
                    tclk_psecs, (uint64_t)tCKmin);
    }


    ddr_print("DDR Clock Rate (tCLK)                         : %6lu ps\n", tclk_psecs);
    ddr_print("Core Clock Rate (eCLK)                        : %6lu ps\n", eclk_psecs);

    if ((s = lookup_env_parameter("ddr_use_ecc")) != NULL) {
        use_ecc = !!strtoul(s, NULL, 0);
    }
    use_ecc = use_ecc && spd_ecc;

    ddr_interface_bytemask = ddr_interface_64b
        ? (use_ecc ? 0x1ff : 0xff)
        : (use_ecc ? 0x01f : 0x0f);

    ddr_print("DRAM Interface width: %d bits %s\n",
              ddr_interface_64b ? 64 : 32, use_ecc ? "+ECC" : "");

    ddr_print("\n------ Board Custom Configuration Settings ------\n");
    ddr_print("%-45s : %d\n", "MIN_RTT_NOM_IDX   ", custom_lmc_config->min_rtt_nom_idx);
    ddr_print("%-45s : %d\n", "MAX_RTT_NOM_IDX   ", custom_lmc_config->max_rtt_nom_idx);
    ddr_print("%-45s : %d\n", "MIN_RODT_CTL      ", custom_lmc_config->min_rodt_ctl);
    ddr_print("%-45s : %d\n", "MAX_RODT_CTL      ", custom_lmc_config->max_rodt_ctl);
#ifndef DDR3_ENHANCE_PRINT
    ddr_print("%-45s : %d\n", "DQX_CTL           ", 4); /* hack to match original fixed value */
    ddr_print("%-45s : %d\n", "CK_CTL            ", custom_lmc_config->ck_ctl);
    ddr_print("%-45s : %d\n", "CMD_CTL           ", custom_lmc_config->cmd_ctl);
    ddr_print("%-45s : %d\n", "CONTROL_CTL       ", custom_lmc_config->ctl_ctl);
#endif
    ddr_print("%-45s : %d\n", "MIN_CAS_LATENCY   ", custom_lmc_config->min_cas_latency);
    ddr_print("%-45s : %d\n", "OFFSET_EN         ", custom_lmc_config->offset_en);
    ddr_print("%-45s : %d\n", "OFFSET_UDIMM      ", custom_lmc_config->offset_udimm);
    ddr_print("%-45s : %d\n", "OFFSET_RDIMM      ", custom_lmc_config->offset_rdimm);
    ddr_print("%-45s : %d\n", "DDR_RTT_NOM_AUTO  ", custom_lmc_config->ddr_rtt_nom_auto);
    ddr_print("%-45s : %d\n", "DDR_RODT_CTL_AUTO ", custom_lmc_config->ddr_rodt_ctl_auto);
    if (spd_rdimm)
        ddr_print("%-45s : %d\n", "RLEVEL_COMP_OFFSET", custom_lmc_config->rlevel_comp_offset_rdimm);
    else
        ddr_print("%-45s : %d\n", "RLEVEL_COMP_OFFSET", custom_lmc_config->rlevel_comp_offset_udimm);
    ddr_print("%-45s : %d\n", "RLEVEL_COMPUTE    ", custom_lmc_config->rlevel_compute);
    ddr_print("%-45s : %d\n", "DDR2T_UDIMM       ", custom_lmc_config->ddr2t_udimm);
    ddr_print("%-45s : %d\n", "DDR2T_RDIMM       ", custom_lmc_config->ddr2t_rdimm);
    ddr_print("%-45s : %d\n", "FPRCH2            ", custom_lmc_config->fprch2);
    ddr_print("-------------------------------------------------\n");


    CL              = divide_roundup(tAAmin, tclk_psecs);

    ddr_print("Desired CAS Latency                           : %6d\n", CL);

    min_cas_latency = custom_lmc_config->min_cas_latency;


    if ((s = lookup_env_parameter("ddr_min_cas_latency")) != NULL) {
        min_cas_latency = strtoul(s, NULL, 0);
    }

    {
        int base_CL;
        ddr_print("CAS Latencies supported in DIMM               :");
        base_CL = (ddr_type == DDR4_DRAM) ? 7 : 4;
        for (i=0; i<32; ++i) {
            if ((spd_cas_latency >> i) & 1) {
                ddr_print(" %d", i+base_CL);
                max_cas_latency = i+base_CL;
                if (min_cas_latency == 0)
                    min_cas_latency = i+base_CL;
            }
        }
        ddr_print("\n");

        /* Use relaxed timing when running slower than the minimum
           supported speed.  Adjust timing to match the smallest supported
           CAS Latency. */
        if (CL < min_cas_latency) {
            ulong adjusted_tclk = tAAmin / min_cas_latency;
            CL = min_cas_latency;
            ddr_print("Slow clock speed. Adjusting timing: tClk = %lu, Adjusted tClk = %ld\n",
                      tclk_psecs, adjusted_tclk);
            tclk_psecs = adjusted_tclk;
        }

        if ((s = lookup_env_parameter("ddr_cas_latency")) != NULL) {
            override_cas_latency = strtoul(s, NULL, 0);
        }

        /* Make sure that the selected cas latency is legal */
        for (i=(CL-base_CL); i<32; ++i) {
            if ((spd_cas_latency >> i) & 1) {
                CL = i+base_CL;
                break;
            }
        }
    }

    if (CL > max_cas_latency)
        CL = max_cas_latency;

    if (override_cas_latency != 0) {
        CL = override_cas_latency;
    }

    ddr_print("CAS Latency                                   : %6d\n", CL);

    if ((CL * tCKmin) > 20000)
    {
        ddr_print("(CLactual * tCKmin) = %d exceeds 20 ns\n", (CL * tCKmin));
    }

    if ((num_banks != 4) && (num_banks != 8) && (num_banks != 16))
    {
        error_print("Unsupported number of banks %d. Must be 4 or 8 or 16.\n", num_banks);
        ++fatal_error;
    }

    if ((num_ranks != 1) && (num_ranks != 2) && (num_ranks != 4))
    {
        error_print("Unsupported number of ranks: %d\n", num_ranks);
        ++fatal_error;
    }

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX)) {
        if ((dram_width != 8) && (dram_width != 16) && (dram_width != 4)) {
            error_print("Unsupported SDRAM Width, %d.  Must be 4, 8 or 16.\n", dram_width);
            ++fatal_error;
        }
    } else if ((dram_width != 8) && (dram_width != 16)) {
        error_print("Unsupported SDRAM Width, %d.  Must be 8 or 16.\n", dram_width);
        ++fatal_error;
    }


    /*
    ** Bail out here if things are not copasetic.
    */
    if (fatal_error)
        return(-1);

    {
        bdk_lmcx_control_t lmc_control;
        bdk_lmcx_scramble_cfg0_t lmc_scramble_cfg0;
        bdk_lmcx_scramble_cfg1_t lmc_scramble_cfg1;

        lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(0));
        lmc_scramble_cfg0.u = BDK_CSR_READ(node, BDK_LMCX_SCRAMBLE_CFG0(0));
        lmc_scramble_cfg1.u = BDK_CSR_READ(node, BDK_LMCX_SCRAMBLE_CFG1(0));

        if ((s = lookup_env_parameter_ull("ddr_scramble_cfg0")) != NULL) {
            lmc_scramble_cfg0.u    = strtoull(s, NULL, 0);
            lmc_control.s.scramble_ena = 1;
        }
        ddr_print("%-45s : 0x%016lx\n", "LMC_SCRAMBLE_CFG0", lmc_scramble_cfg0.u);

        DRAM_CSR_WRITE(node, BDK_LMCX_SCRAMBLE_CFG0(0), lmc_scramble_cfg0.u);

        if ((s = lookup_env_parameter_ull("ddr_scramble_cfg1")) != NULL) {
            lmc_scramble_cfg1.u    = strtoull(s, NULL, 0);
            lmc_control.s.scramble_ena = 1;
        }
        ddr_print("%-45s : 0x%016lx\n", "LMC_SCRAMBLE_CFG1", lmc_scramble_cfg1.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_SCRAMBLE_CFG1(0), lmc_scramble_cfg1.u);

        DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(0), lmc_control.u);
    }


    odt_idx = min(dimm_count - 1, 3);

    switch (num_ranks) {
    case 1:
        odt_config = odt_1rank_config;
        break;
    case 2:
        odt_config = odt_2rank_config;
        break;
    case 4:
        odt_config = odt_4rank_config;
        break;
    default:
        odt_config = disable_odt_config;
        error_print("Unsupported number of ranks: %d\n", num_ranks);
        ++fatal_error;
    }


    /* Parameters from DDR3 Specifications */
#define DDR3_tREFI         7800000    /* 7.8 us */
#define DDR3_ZQCS          80000ull   /* 80 ns */
#define DDR3_ZQCS_Interval 1280000000 /* 128ms/100 */
#define DDR3_tCKE          5000       /* 5 ns */
#define DDR3_tMRD          4          /* 4 nCK */
#define DDR3_tDLLK         512        /* 512 nCK */
#define DDR3_tMPRR         1          /* 1 nCK */
#define DDR3_tWLMRD        40         /* 40 nCK */
#define DDR3_tWLDQSEN      25         /* 25 nCK */

    /* Parameters from DDR4 Specifications */
#define DDR4_tMRD          8          /* 8 nCK */
#define DDR4_tDLLK         768        /* 768 nCK */

     /*
     * 4.8.5 Early LMC Initialization
     * 
     * All of DDR PLL, LMC CK, and LMC DRESET initializations must be
     * completed prior to starting this LMC initialization sequence.
     * 
     * Perform the following five substeps for early LMC initialization:
     * 
     * 1. Software must ensure there are no pending DRAM transactions.
     * 
     * 2. Write LMC(0)_CONFIG, LMC(0)_CONTROL, LMC(0)_TIMING_PARAMS0,
     *    LMC(0)_TIMING_PARAMS1, LMC(0)_MODEREG_PARAMS0,
     *    LMC(0)_MODEREG_PARAMS1, LMC(0)_DUAL_MEMCFG, LMC(0)_NXM,
     *    LMC(0)_WODT_MASK, LMC(0)_RODT_MASK, LMC(0)_COMP_CTL2,
     *    LMC(0)_PHY_CTL, LMC(0)_DIMM0/1_PARAMS, and LMC(0)_DIMM_CTL with
     *    appropriate values. All sections in this chapter can be used to
     *    derive proper register settings.
     */

    /* LMC(0)_CONFIG */
    {
        bdk_lmcx_config_t lmcx_config;

        lmcx_config.u = 0;

        lmcx_config.s.ecc_ena         = use_ecc;
        lmcx_config.s.row_lsb         = encode_row_lsb_ddr3(row_lsb, ddr_interface_64b);
        lmcx_config.s.pbank_lsb       = encode_pbank_lsb_ddr3(pbank_lsb, ddr_interface_64b);

        lmcx_config.s.idlepower       = 0; /* Disabled */

        if ((s = lookup_env_parameter("ddr_idlepower")) != NULL) {
            lmcx_config.s.idlepower = strtoul(s, NULL, 0);
        }

        lmcx_config.s.forcewrite      = 0; /* Disabled */
        lmcx_config.s.ecc_adr         = 1; /* Include memory reference address in the ECC */

        if ((s = lookup_env_parameter("ddr_ecc_adr")) != NULL) {
            lmcx_config.s.ecc_adr = strtoul(s, NULL, 0);
        }

        lmcx_config.s.reset           = 0;

        /*
         *  Program LMC0_CONFIG[24:18], ref_zqcs_int(6:0) to
         *  RND-DN(tREFI/clkPeriod/512) Program LMC0_CONFIG[36:25],
         *  ref_zqcs_int(18:7) to
         *  RND-DN(ZQCS_Interval/clkPeriod/(512*128)). Note that this
         *  value should always be greater than 32, to account for
         *  resistor calibration delays.
         */

        lmcx_config.s.ref_zqcs_int     = ((DDR3_tREFI/tclk_psecs/512) & 0x7f);
        lmcx_config.s.ref_zqcs_int    |= ((max(33ull, (DDR3_ZQCS_Interval/(tclk_psecs/100)/(512*128))) & 0xfff) << 7);


        lmcx_config.s.early_dqx       = 1; /* Default to enabled */

        if ((s = lookup_env_parameter("ddr_early_dqx")) == NULL)
            s = lookup_env_parameter("ddr%d_early_dqx", ddr_interface_num);
        if (s != NULL) {
            lmcx_config.s.early_dqx = strtoul(s, NULL, 0);
        }

        lmcx_config.s.sref_with_dll        = 0;

        lmcx_config.s.rank_ena        = bunk_enable;
        lmcx_config.s.rankmask        = rank_mask; /* Set later */
        lmcx_config.s.mirrmask        = (spd_addr_mirror << 1 | spd_addr_mirror << 3) & rank_mask;
        lmcx_config.s.init_status     = rank_mask; /* Set once and don't change it. */
        lmcx_config.s.early_unload_d0_r0   = 0;
        lmcx_config.s.early_unload_d0_r1   = 0;
        lmcx_config.s.early_unload_d1_r0   = 0;
        lmcx_config.s.early_unload_d1_r1   = 0;
        lmcx_config.s.scrz                 = 0;
        lmcx_config.s.mode_x4dev           = (dram_width == 4) ? 1 : 0;
        lmcx_config.s.bg2_enable	   = ((ddr_type == DDR4_DRAM) && (dram_width == 16)) ? 0 : 1;

        if ((s = lookup_env_parameter_ull("ddr_config")) != NULL) {
            lmcx_config.u    = strtoull(s, NULL, 0);
        }
        ddr_print("LMC_CONFIG                                    : 0x%016lx\n", lmcx_config.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmcx_config.u);
    }

    /* LMC(0)_CONTROL */
    {
        /* .s. */
        bdk_lmcx_control_t lmc_control;
        lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
        lmc_control.s.rdimm_ena       = spd_rdimm;
        lmc_control.s.bwcnt           = 0; /* Clear counter later */
        if (spd_rdimm)
            lmc_control.s.ddr2t       = (safe_ddr_flag ? 1 : custom_lmc_config->ddr2t_rdimm );
        else
            lmc_control.s.ddr2t       = (safe_ddr_flag ? 1 : custom_lmc_config->ddr2t_udimm );
        lmc_control.s.pocas           = 0;
        lmc_control.s.fprch2          = (safe_ddr_flag ? 2 : custom_lmc_config->fprch2 );
        lmc_control.s.throttle_rd     = safe_ddr_flag ? 1 : 0;
        lmc_control.s.throttle_wr     = safe_ddr_flag ? 1 : 0;
        lmc_control.s.inorder_rd      = safe_ddr_flag ? 1 : 0;
        lmc_control.s.inorder_wr      = safe_ddr_flag ? 1 : 0;
        lmc_control.s.elev_prio_dis   = safe_ddr_flag ? 1 : 0;
        lmc_control.s.nxm_write_en    = 0; /* discards writes to
                                            addresses that don't exist
                                            in the DRAM */
        lmc_control.s.max_write_batch = 8;
        lmc_control.s.xor_bank        = 1;
        lmc_control.s.auto_dclkdis    = 1;
        lmc_control.s.int_zqcs_dis    = 0;
        lmc_control.s.ext_zqcs_dis    = 0;
        lmc_control.s.bprch           = 1;
        lmc_control.s.wodt_bprch      = 1;
        lmc_control.s.rodt_bprch      = 1;

        if ((s = lookup_env_parameter("ddr_xor_bank")) != NULL) {
            lmc_control.s.xor_bank = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_2t")) != NULL) {
            lmc_control.s.ddr2t = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_fprch2")) != NULL) {
            lmc_control.s.fprch2 = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_bprch")) != NULL) {
            lmc_control.s.bprch = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_wodt_bprch")) != NULL) {
            lmc_control.s.wodt_bprch = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rodt_bprch")) != NULL) {
            lmc_control.s.rodt_bprch = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_int_zqcs_dis")) != NULL) {
            lmc_control.s.int_zqcs_dis = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_ext_zqcs_dis")) != NULL) {
            lmc_control.s.ext_zqcs_dis = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter_ull("ddr_control")) != NULL) {
            lmc_control.u    = strtoull(s, NULL, 0);
        }
        ddr_print("LMC_CONTROL                                   : 0x%016lx\n", lmc_control.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);
    }

    /* LMC(0)_TIMING_PARAMS0 */
    {
        unsigned trp_value;
        bdk_lmcx_timing_params0_t lmc_timing_params0;
        lmc_timing_params0.u = BDK_CSR_READ(node, BDK_LMCX_TIMING_PARAMS0(ddr_interface_num));

        trp_value = divide_roundup(trp, tclk_psecs)
            + divide_roundup(max(4*tclk_psecs, 7500ull), tclk_psecs) - 5;

        lmc_timing_params0.s.txpr     = divide_roundup(max(5*tclk_psecs, trfc+10000ull), 16*tclk_psecs);
        lmc_timing_params0.s.tzqinit  = divide_roundup(max(512*tclk_psecs, 640000ull), (256*tclk_psecs));
        lmc_timing_params0.s.trp      = trp_value & 0x1f;
        lmc_timing_params0.s.tcksre   = divide_roundup(max(5*tclk_psecs, 10000ull), tclk_psecs) - 1;

        if (ddr_type == DDR4_DRAM) {
            lmc_timing_params0.s.tzqcs    = divide_roundup(128*tclk_psecs, (16*tclk_psecs)); /* Always 8. */
	    lmc_timing_params0.s.tcke     = divide_roundup(max(3*tclk_psecs, (ulong) DDR3_tCKE), tclk_psecs) - 1;
	    lmc_timing_params0.s.tmrd     = divide_roundup((DDR4_tMRD*tclk_psecs), tclk_psecs) - 1;
	    //lmc_timing_params0.s.tmod     = divide_roundup(max(24*tclk_psecs, 15000ull), tclk_psecs) - 1;
	    lmc_timing_params0.s.tmod     = 25; /* 25 is the max allowed */
	    lmc_timing_params0.s.tdllk    = divide_roundup(DDR4_tDLLK, 256);
        } else {
            lmc_timing_params0.s.tzqcs    = divide_roundup(max(64*tclk_psecs, DDR3_ZQCS), (16*tclk_psecs));
	    lmc_timing_params0.s.tcke     = divide_roundup(DDR3_tCKE, tclk_psecs) - 1;
	    lmc_timing_params0.s.tmrd     = divide_roundup((DDR3_tMRD*tclk_psecs), tclk_psecs) - 1;
	    lmc_timing_params0.s.tmod     = divide_roundup(max(12*tclk_psecs, 15000ull), tclk_psecs) - 1;
	    lmc_timing_params0.s.tdllk    = divide_roundup(DDR3_tDLLK, 256);
        }

        if ((s = lookup_env_parameter_ull("ddr_timing_params0")) != NULL) {
            lmc_timing_params0.u    = strtoull(s, NULL, 0);
        }
        ddr_print("TIMING_PARAMS0                                : 0x%016lx\n", lmc_timing_params0.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_TIMING_PARAMS0(ddr_interface_num), lmc_timing_params0.u);
    }

    /* LMC(0)_TIMING_PARAMS1 */
    {
        int txp;
        bdk_lmcx_timing_params1_t lmc_timing_params1;
        lmc_timing_params1.u = BDK_CSR_READ(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num));


        lmc_timing_params1.s.tmprr    = divide_roundup(DDR3_tMPRR*tclk_psecs, tclk_psecs) - 1;

        lmc_timing_params1.s.tras     = divide_roundup(tras, tclk_psecs) - 1;

        if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X)) {
            /* Let .trcd=0 serve as a flag that the field has
               overflowed. Must use Additive Latency mode as a
               workaround. */
            lmc_timing_params1.s.trcd     = (divide_roundup(trcd, tclk_psecs) > 15)
                ? 0 : divide_roundup(trcd, tclk_psecs);
        } else {
            lmc_timing_params1.s.trcd     = divide_roundup(trcd, tclk_psecs);
        }

        lmc_timing_params1.s.twtr     = divide_roundup(twtr, tclk_psecs) - 1;
        lmc_timing_params1.s.trfc     = divide_roundup(trfc, 8*tclk_psecs);
        if ((ddr_type == DDR4_DRAM) && CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X)) {
            /* Workaround bug 24006. Use Trrd_l. */
            lmc_timing_params1.s.trrd     = divide_roundup(ddr4_tRRD_Lmin, tclk_psecs) - 2;
        } else
            lmc_timing_params1.s.trrd     = divide_roundup(trrd, tclk_psecs) - 2;


        /*
        ** tXP = max( 3nCK, 7.5 ns)     DDR3-800   tCLK = 2500 psec
        ** tXP = max( 3nCK, 7.5 ns)     DDR3-1066  tCLK = 1875 psec
        ** tXP = max( 3nCK, 6.0 ns)     DDR3-1333  tCLK = 1500 psec
        ** tXP = max( 3nCK, 6.0 ns)     DDR3-1600  tCLK = 1250 psec
        ** tXP = max( 3nCK, 6.0 ns)     DDR3-1866  tCLK = 1071 psec
        ** tXP = max( 3nCK, 6.0 ns)     DDR3-2133  tCLK =  937 psec
        */
        txp = (tclk_psecs < 1875) ? 6000 : 7500;
        lmc_timing_params1.s.txp      = divide_roundup(max(3*tclk_psecs, (unsigned)txp), tclk_psecs) - 1;

        lmc_timing_params1.s.twlmrd   = divide_roundup(DDR3_tWLMRD*tclk_psecs, 4*tclk_psecs);
        lmc_timing_params1.s.twldqsen = divide_roundup(DDR3_tWLDQSEN*tclk_psecs, 4*tclk_psecs);
        lmc_timing_params1.s.tfaw     = divide_roundup(tfaw, 4*tclk_psecs);
        lmc_timing_params1.s.txpdll   = divide_roundup(max(10*tclk_psecs, 24000ull), tclk_psecs) - 1;

        if ((s = lookup_env_parameter_ull("ddr_timing_params1")) != NULL) {
            lmc_timing_params1.u    = strtoull(s, NULL, 0);
        }
        ddr_print("TIMING_PARAMS1                                : 0x%016lx\n", lmc_timing_params1.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num), lmc_timing_params1.u);
    }

    /* LMC(0)_TIMING_PARAMS2 */
    if (ddr_type == DDR4_DRAM) {
        bdk_lmcx_timing_params1_t lmc_timing_params1;
        bdk_lmcx_timing_params2_t lmc_timing_params2;
        lmc_timing_params1.u = BDK_CSR_READ(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num));
        lmc_timing_params2.u = BDK_CSR_READ(node, BDK_LMCX_TIMING_PARAMS2(ddr_interface_num));
        ddr_print("TIMING_PARAMS2                                : 0x%016lx\n", lmc_timing_params2.u);

        lmc_timing_params2.s.trrd_l = divide_roundup(ddr4_tRRD_Lmin, tclk_psecs) - 1;
        lmc_timing_params2.s.twtr_l = divide_nint(max(4*tclk_psecs, 7500ull), tclk_psecs) - 1; // correct for 1600-2400
        lmc_timing_params2.s.t_rw_op_max = 7;
        lmc_timing_params2.s.trtp = divide_roundup(max(4*tclk_psecs, 7500ull), tclk_psecs) - 1;

        ddr_print("TIMING_PARAMS2                                : 0x%016lx\n", lmc_timing_params2.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_TIMING_PARAMS2(ddr_interface_num), lmc_timing_params2.u);

        /* Workaround Errata 25823 - LMC: Possible DDR4 tWTR_L not met
           for Write-to-Read operations to the same Bank Group */
        if (lmc_timing_params1.s.twtr < (lmc_timing_params2.s.twtr_l - 4)) {
            lmc_timing_params1.s.twtr = lmc_timing_params2.s.twtr_l - 4;
	    ddr_print("ERRATA 25823: NEW: TWTR: %d, TWTR_L: %d\n", lmc_timing_params1.s.twtr, lmc_timing_params2.s.twtr_l);
            ddr_print("TIMING_PARAMS1                                : 0x%016lx\n", lmc_timing_params1.u);
            DRAM_CSR_WRITE(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num), lmc_timing_params1.u);
        }
    }

    /* LMC(0)_MODEREG_PARAMS0 */
    {
        /* .s. */
        bdk_lmcx_modereg_params0_t lmc_modereg_params0;
        int param;

        lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));

        if (ddr_type == DDR4_DRAM) {
	    lmc_modereg_params0.s.cwl     = 0; /* 1600 (1250ps) */
	    if (tclk_psecs < 1250)
	        lmc_modereg_params0.s.cwl = 1; /* 1866 (1072ps) */
	    if (tclk_psecs < 1072)
	        lmc_modereg_params0.s.cwl = 2; /* 2133 (938ps) */
	    if (tclk_psecs < 938)
	        lmc_modereg_params0.s.cwl = 3; /* 2400 (833ps) */
	    if (tclk_psecs < 833)
	        lmc_modereg_params0.s.cwl = 4; /* 2666 (750ps) */
	    if (tclk_psecs < 750)
	        lmc_modereg_params0.s.cwl = 5; /* 3200 (625ps) */
        } else {
        /*
        ** CSR   CWL         CAS write Latency
        ** ===   ===   =================================
        **  0      5   (           tCK(avg) >=   2.5 ns)
        **  1      6   (2.5 ns   > tCK(avg) >= 1.875 ns)
        **  2      7   (1.875 ns > tCK(avg) >= 1.5   ns)
        **  3      8   (1.5 ns   > tCK(avg) >= 1.25  ns)
        **  4      9   (1.25 ns  > tCK(avg) >= 1.07  ns)
        **  5     10   (1.07 ns  > tCK(avg) >= 0.935 ns)
        **  6     11   (0.935 ns > tCK(avg) >= 0.833 ns)
        **  7     12   (0.833 ns > tCK(avg) >= 0.75  ns)
        */

        lmc_modereg_params0.s.cwl     = 0;
        if (tclk_psecs < 2500)
            lmc_modereg_params0.s.cwl = 1;
        if (tclk_psecs < 1875)
            lmc_modereg_params0.s.cwl = 2;
        if (tclk_psecs < 1500)
            lmc_modereg_params0.s.cwl = 3;
        if (tclk_psecs < 1250)
            lmc_modereg_params0.s.cwl = 4;
        if (tclk_psecs < 1070)
            lmc_modereg_params0.s.cwl = 5;
        if (tclk_psecs <  935)
            lmc_modereg_params0.s.cwl = 6;
        if (tclk_psecs <  833)
            lmc_modereg_params0.s.cwl = 7;
	}

        if ((s = lookup_env_parameter("ddr_cwl")) != NULL) {
            lmc_modereg_params0.s.cwl = strtoul(s, NULL, 0) - 5;
        }

        if (ddr_type == DDR4_DRAM) {
            ddr_print("%-45s : %d, [0x%x]\n", "CAS Write Latency CWL, [CSR]",
                      lmc_modereg_params0.s.cwl + 9
                      + ((lmc_modereg_params0.s.cwl>2) ? (lmc_modereg_params0.s.cwl-3) * 2 : 0),
                      lmc_modereg_params0.s.cwl);
        } else {
#ifdef DDR3_ENHANCE_PRINT
            ddr_print("%-45s : %d, [0x%x]\n", "CAS Write Latency CWL, [CSR]",
                      lmc_modereg_params0.s.cwl + 5,
                      lmc_modereg_params0.s.cwl);
#else
	    ddr_print("CAS Write Latency                             : %6d\n", lmc_modereg_params0.s.cwl + 5);
#endif
        }

        lmc_modereg_params0.s.mprloc  = 0;
        lmc_modereg_params0.s.mpr     = 0;
        lmc_modereg_params0.s.dll     = (ddr_type == DDR4_DRAM)?1:0; /* enable(0) for DDR3 and disable(1) for DDR4 */
        lmc_modereg_params0.s.al      = 0;
        lmc_modereg_params0.s.wlev    = 0; /* Read Only */
        lmc_modereg_params0.s.tdqs    = (ddr_type == DDR4_DRAM)?0:1; /* enable(1) for DDR3 and disable(0) for DDR4 */
        lmc_modereg_params0.s.qoff    = 0;
        lmc_modereg_params0.s.bl      = 0; /* Read Only */

        if ((s = lookup_env_parameter("ddr_cl")) != NULL) {
            CL = strtoul(s, NULL, 0);
            ddr_print("CAS Latency                                   : %6d\n", CL);
        }

        if (ddr_type == DDR4_DRAM) {
	    lmc_modereg_params0.s.cl      = 0x0;
	    if (CL > 9)
	        lmc_modereg_params0.s.cl  = 0x1;
	    if (CL > 10)
	        lmc_modereg_params0.s.cl  = 0x2;
	    if (CL > 11)
	        lmc_modereg_params0.s.cl  = 0x3;
	    if (CL > 12)
	        lmc_modereg_params0.s.cl  = 0x4;
	    if (CL > 13)
	        lmc_modereg_params0.s.cl  = 0x5;
	    if (CL > 14)
	        lmc_modereg_params0.s.cl  = 0x6;
	    if (CL > 15)
	        lmc_modereg_params0.s.cl  = 0x7;
	    if (CL > 16)
	        lmc_modereg_params0.s.cl  = 0x8;
	    if (CL > 18)
	        lmc_modereg_params0.s.cl  = 0x9;
	    if (CL > 20)
	        lmc_modereg_params0.s.cl  = 0xA;
	    if (CL > 24)
	        lmc_modereg_params0.s.cl  = 0xB;
        } else {
	    lmc_modereg_params0.s.cl      = 0x2;
	    if (CL > 5)
		lmc_modereg_params0.s.cl  = 0x4;
	    if (CL > 6)
		lmc_modereg_params0.s.cl  = 0x6;
	    if (CL > 7)
		lmc_modereg_params0.s.cl  = 0x8;
	    if (CL > 8)
		lmc_modereg_params0.s.cl  = 0xA;
	    if (CL > 9)
		lmc_modereg_params0.s.cl  = 0xC;
	    if (CL > 10)
		lmc_modereg_params0.s.cl  = 0xE;
	    if (CL > 11)
		lmc_modereg_params0.s.cl  = 0x1;
	    if (CL > 12)
		lmc_modereg_params0.s.cl  = 0x3;
	    if (CL > 13)
		lmc_modereg_params0.s.cl  = 0x5;
	    if (CL > 14)
		lmc_modereg_params0.s.cl  = 0x7;
	    if (CL > 15)
		lmc_modereg_params0.s.cl  = 0x9;
	}

        lmc_modereg_params0.s.rbt     = 0; /* Read Only. */
        lmc_modereg_params0.s.tm      = 0;
        lmc_modereg_params0.s.dllr    = 0;

        param = divide_roundup(twr, tclk_psecs);

        if (ddr_type == DDR4_DRAM) {    /* DDR4 */
	    lmc_modereg_params0.s.wrp     = 1;
	    if (param > 12)
	        lmc_modereg_params0.s.wrp = 2;
	    if (param > 14)
	        lmc_modereg_params0.s.wrp = 3;
	    if (param > 16)
	        lmc_modereg_params0.s.wrp = 4;
	    if (param > 18)
	        lmc_modereg_params0.s.wrp = 5;
	    if (param > 20)
	        lmc_modereg_params0.s.wrp = 6;
	    if (param > 24)         /* RESERVED in DDR4 spec */
	        lmc_modereg_params0.s.wrp = 7;
        } else {                /* DDR3 */
	    lmc_modereg_params0.s.wrp     = 1;
	    if (param > 5)
		lmc_modereg_params0.s.wrp = 2;
	    if (param > 6)
		lmc_modereg_params0.s.wrp = 3;
	    if (param > 7)
		lmc_modereg_params0.s.wrp = 4;
	    if (param > 8)
		lmc_modereg_params0.s.wrp = 5;
	    if (param > 10)
		lmc_modereg_params0.s.wrp = 6;
	    if (param > 12)
		lmc_modereg_params0.s.wrp = 7;
	}

        lmc_modereg_params0.s.ppd     = 0;

        if ((s = lookup_env_parameter("ddr_wrp")) != NULL) {
            lmc_modereg_params0.s.wrp = strtoul(s, NULL, 0);
        }

        ddr_print("%-45s : %d, [0x%x]\n", "Write recovery for auto precharge WRP, [CSR]",
                  param, lmc_modereg_params0.s.wrp);

        if ((s = lookup_env_parameter_ull("ddr_modereg_params0")) != NULL) {
            lmc_modereg_params0.u    = strtoull(s, NULL, 0);
        }
        ddr_print("MODEREG_PARAMS0                               : 0x%016lx\n", lmc_modereg_params0.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);
    }

    /* LMC(0)_MODEREG_PARAMS1 */
    {
        /* .s. */
        bdk_lmcx_modereg_params1_t lmc_modereg_params1;
        bdk_lmcx_modereg_params2_t lmc_modereg_params2;

        lmc_modereg_params1.u = odt_config[odt_idx].odt_mask1.u;
        lmc_modereg_params2.u = odt_config[odt_idx].odt_mask2.u;

#ifdef CAVIUM_ONLY
        /* Special request: mismatched DIMM support. Slot 0: 2-Rank, Slot 1: 1-Rank */
        if (rank_mask == 0x7) { /* 2-Rank, 1-Rank */
            lmc_modereg_params1.s.rtt_nom_00 = 0;
            lmc_modereg_params1.s.rtt_nom_01 = 3; /* rttnom_40ohm */
            lmc_modereg_params1.s.rtt_nom_10 = 3; /* rttnom_40ohm */
            lmc_modereg_params1.s.rtt_nom_11 = 0;
            dyn_rtt_nom_mask = 0x6;
        }
#endif  /* CAVIUM_ONLY */

        if ((s = lookup_env_parameter("ddr_rtt_nom_mask")) != NULL) {
            dyn_rtt_nom_mask    = strtoul(s, NULL, 0);
        }


        /* Save the original rtt_nom settings before sweeping through settings. */
        default_rtt_nom[0] = lmc_modereg_params1.s.rtt_nom_00;
        default_rtt_nom[1] = lmc_modereg_params1.s.rtt_nom_01;
        default_rtt_nom[2] = lmc_modereg_params1.s.rtt_nom_10;
        default_rtt_nom[3] = lmc_modereg_params1.s.rtt_nom_11;

        ddr_rtt_nom_auto = custom_lmc_config->ddr_rtt_nom_auto;

        for (i=0; i<4; ++i) {
            uint64_t value;
            if ((s = lookup_env_parameter("ddr_rtt_nom_%1d%1d", !!(i&2), !!(i&1))) == NULL)
                s = lookup_env_parameter("ddr%d_rtt_nom_%1d%1d", ddr_interface_num, !!(i&2), !!(i&1));
            if (s != NULL) {
                value = strtoul(s, NULL, 0);
                lmc_modereg_params1.u &= ~((uint64_t)0x7  << (i*12+9));
                lmc_modereg_params1.u |=  ( (value & 0x7) << (i*12+9));
                default_rtt_nom[i] = value;
                ddr_rtt_nom_auto = 0;
            }
        }


        if ((s = lookup_env_parameter("ddr_rtt_nom")) == NULL)
            s = lookup_env_parameter("ddr%d_rtt_nom", ddr_interface_num);
        if (s != NULL) {
            uint64_t value;
            value = strtoul(s, NULL, 0);


            if (dyn_rtt_nom_mask & 1)
                default_rtt_nom[0] = lmc_modereg_params1.s.rtt_nom_00 = value;
            if (dyn_rtt_nom_mask & 2)
                default_rtt_nom[1] = lmc_modereg_params1.s.rtt_nom_01 = value;
            if (dyn_rtt_nom_mask & 4)
                default_rtt_nom[2] = lmc_modereg_params1.s.rtt_nom_10 = value;
            if (dyn_rtt_nom_mask & 8)
                default_rtt_nom[3] = lmc_modereg_params1.s.rtt_nom_11 = value;

            ddr_rtt_nom_auto = 0;
        }

#if 0
	// FIXME: this is a duplicate of code just above, and uses an invalid mask - 3 should be 7
	// FIXME: disabled, awaiting removal...
        for (i=0; i<4; ++i) {
            uint64_t value;
            if ((s = lookup_env_parameter("ddr_rtt_nom_%1d%1d", !!(i&2), !!(i&1))) == NULL)
                s = lookup_env_parameter("ddr%d_rtt_nom_%1d%1d", ddr_interface_num, !!(i&2), !!(i&1));
            if (s != NULL) {
                value = strtoul(s, NULL, 0);
                lmc_modereg_params1.u &= ~((uint64_t)0x3  << (i*12+9));
                lmc_modereg_params1.u |=  ( (value & 0x3) << (i*12+9));

                ddr_rtt_nom_auto = 0;
            }
        }
#endif

        for (i=0; i<4; ++i) {
            uint64_t value;
            if ((s = lookup_env_parameter("ddr_rtt_wr_%1d%1d", !!(i&2), !!(i&1))) == NULL)
                s = lookup_env_parameter("ddr%d_rtt_wr_%1d%1d", ddr_interface_num, !!(i&2), !!(i&1));
            if (s != NULL) {
                value = strtoul(s, NULL, 0);
                lmc_modereg_params1.u &= ~((uint64_t)0x3  << (i*12+5));
                lmc_modereg_params1.u |=  ( (value & 0x3) << (i*12+5));
            }
        }

        if ((s = lookup_env_parameter("ddr_dic")) != NULL) {
            uint64_t value = strtoul(s, NULL, 0);
            for (i=0; i<4; ++i) {
                lmc_modereg_params1.u &= ~((uint64_t)0x3  << (i*12+7));
                lmc_modereg_params1.u |=  ( (value & 0x3) << (i*12+7));
            }
        }

        for (i=0; i<4; ++i) {
            uint64_t value;
            if ((s = lookup_env_parameter("ddr_dic_%1d%1d", !!(i&2), !!(i&1))) != NULL) {
                value = strtoul(s, NULL, 0);
                lmc_modereg_params1.u &= ~((uint64_t)0x3  << (i*12+7));
                lmc_modereg_params1.u |=  ( (value & 0x3) << (i*12+7));
            }
        }

        if ((s = lookup_env_parameter_ull("ddr_modereg_params1")) != NULL) {
            lmc_modereg_params1.u    = strtoull(s, NULL, 0);
        }

        ddr_print("RTT_NOM     %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
                  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_11],
                  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_10],
                  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_01],
                  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_00],
                  lmc_modereg_params1.s.rtt_nom_11,
                  lmc_modereg_params1.s.rtt_nom_10,
                  lmc_modereg_params1.s.rtt_nom_01,
                  lmc_modereg_params1.s.rtt_nom_00);

        ddr_print("RTT_WR      %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
                  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_11],
                  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_10],
                  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_01],
                  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_00],
                  lmc_modereg_params1.s.rtt_wr_11,
                  lmc_modereg_params1.s.rtt_wr_10,
                  lmc_modereg_params1.s.rtt_wr_01,
                  lmc_modereg_params1.s.rtt_wr_00);

        ddr_print("DIC         %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
                  imp_values->dic_ohms[lmc_modereg_params1.s.dic_11],
                  imp_values->dic_ohms[lmc_modereg_params1.s.dic_10],
                  imp_values->dic_ohms[lmc_modereg_params1.s.dic_01],
                  imp_values->dic_ohms[lmc_modereg_params1.s.dic_00],
                  lmc_modereg_params1.s.dic_11,
                  lmc_modereg_params1.s.dic_10,
                  lmc_modereg_params1.s.dic_01,
                  lmc_modereg_params1.s.dic_00);

        if (ddr_type == DDR4_DRAM) {

	    for (i=0; i<4; ++i) {
		uint64_t value;
		if ((s = lookup_env_parameter("ddr_rtt_park_%1d%1d", !!(i&2), !!(i&1))) != NULL) {
		    value = strtoul(s, NULL, 0);
		    lmc_modereg_params2.u &= ~((uint64_t)0x7  << (i*10+0));
		    lmc_modereg_params2.u |=  ( (value & 0x7) << (i*10+0));
		}
	    }

	    if ((s = lookup_env_parameter_ull("ddr_modereg_params2")) != NULL) {
		lmc_modereg_params2.u    = strtoull(s, NULL, 0);
	    }

            ddr_print("RTT_PARK    %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
		      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_11],
		      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_10],
		      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_01],
		      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_00],
		      lmc_modereg_params2.s.rtt_park_11,
		      lmc_modereg_params2.s.rtt_park_10,
		      lmc_modereg_params2.s.rtt_park_01,
		      lmc_modereg_params2.s.rtt_park_00);

            ddr_print("%-45s :  0x%x,0x%x,0x%x,0x%x\n", "VREF_RANGE",
                      lmc_modereg_params2.s.vref_range_11,
                      lmc_modereg_params2.s.vref_range_10,
                      lmc_modereg_params2.s.vref_range_01,
                      lmc_modereg_params2.s.vref_range_00);

            ddr_print("%-45s :  0x%x,0x%x,0x%x,0x%x\n", "VREF_VALUE",
                      lmc_modereg_params2.s.vref_value_11,
                      lmc_modereg_params2.s.vref_value_10,
                      lmc_modereg_params2.s.vref_value_01,
                      lmc_modereg_params2.s.vref_value_00);
        }

        ddr_print("MODEREG_PARAMS1                               : 0x%016lx\n", lmc_modereg_params1.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num), lmc_modereg_params1.u);

        if (ddr_type == DDR4_DRAM) {
	    ddr_print("MODEREG_PARAMS2                               : 0x%016lx\n", lmc_modereg_params2.u);
	    DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS2(ddr_interface_num), lmc_modereg_params2.u);
	}
    }

    /* LMC(0)_MODEREG_PARAMS3 */
    if (ddr_type == DDR4_DRAM) {
        bdk_lmcx_modereg_params3_t lmc_modereg_params3;

        lmc_modereg_params3.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS3(ddr_interface_num));

        //lmc_modereg_params3.s.max_pd          =
        //lmc_modereg_params3.s.tc_ref          =
        //lmc_modereg_params3.s.vref_mon        =
        //lmc_modereg_params3.s.cal             =
        //lmc_modereg_params3.s.sre_abort       =
        //lmc_modereg_params3.s.rd_preamble     =
        //lmc_modereg_params3.s.wr_preamble     =
        //lmc_modereg_params3.s.par_lat_mode    =
        //lmc_modereg_params3.s.odt_pd          =
        //lmc_modereg_params3.s.ca_par_pers     =
        //lmc_modereg_params3.s.dm              =
        //lmc_modereg_params3.s.wr_dbi          =
        //lmc_modereg_params3.s.rd_dbi          =
        lmc_modereg_params3.s.tccd_l            = max(divide_roundup(ddr4_tCCD_Lmin, tclk_psecs), 5ull) - 4;
        //lmc_modereg_params3.s.lpasr           =
        //lmc_modereg_params3.s.crc             =
        //lmc_modereg_params3.s.gd              =
        //lmc_modereg_params3.s.pda             =
        //lmc_modereg_params3.s.temp_sense      =
        //lmc_modereg_params3.s.fgrm            =
        //lmc_modereg_params3.s.wr_cmd_lat      =
        //lmc_modereg_params3.s.mpr_fmt         =

        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS3(ddr_interface_num), lmc_modereg_params3.u);
    }

    /* LMC(0)_NXM */
    {
        bdk_lmcx_nxm_t lmc_nxm;
        lmc_nxm.u = BDK_CSR_READ(node, BDK_LMCX_NXM(ddr_interface_num));

        /* .s. */
        if (rank_mask & 0x1)
            lmc_nxm.s.mem_msb_d0_r0 = row_lsb + row_bits - 26;
        if (rank_mask & 0x2)
            lmc_nxm.s.mem_msb_d0_r1 = row_lsb + row_bits - 26;
        if (rank_mask & 0x4)
            lmc_nxm.s.mem_msb_d1_r0 = row_lsb + row_bits - 26;
        if (rank_mask & 0x8)
            lmc_nxm.s.mem_msb_d1_r1 = row_lsb + row_bits - 26;

        lmc_nxm.s.cs_mask = ~rank_mask & 0xff; /* Set the mask for non-existant ranks. */

       if ((s = lookup_env_parameter_ull("ddr_nxm")) != NULL) {
            lmc_nxm.u    = strtoull(s, NULL, 0);
        }
        ddr_print("LMC_NXM                                       : 0x%016lx\n", lmc_nxm.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_NXM(ddr_interface_num), lmc_nxm.u);
    }

    /* LMC(0)_WODT_MASK */
    {
        bdk_lmcx_wodt_mask_t lmc_wodt_mask;
        lmc_wodt_mask.u = odt_config[odt_idx].odt_mask;

        if ((s = lookup_env_parameter_ull("ddr_wodt_mask")) != NULL) {
            lmc_wodt_mask.u    = strtoull(s, NULL, 0);
        }

        ddr_print("WODT_MASK                                     : 0x%016lx\n", lmc_wodt_mask.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_WODT_MASK(ddr_interface_num), lmc_wodt_mask.u);
    }

    /* LMC(0)_RODT_MASK */
    {
        int rankx;
        bdk_lmcx_rodt_mask_t lmc_rodt_mask;
        lmc_rodt_mask.u = odt_config[odt_idx].rodt_ctl;

        if ((s = lookup_env_parameter_ull("ddr_rodt_mask")) != NULL) {
            lmc_rodt_mask.u    = strtoull(s, NULL, 0);
        }

        ddr_print("%-45s : 0x%016lx\n", "RODT_MASK", lmc_rodt_mask.u);
	DRAM_CSR_WRITE(node, BDK_LMCX_RODT_MASK(ddr_interface_num), lmc_rodt_mask.u);

        dyn_rtt_nom_mask = 0;
        for (rankx = 0; rankx < dimm_count * 4;rankx++) {
            if (!(rank_mask & (1 << rankx)))
                continue;
            dyn_rtt_nom_mask |= ((lmc_rodt_mask.u >> (8*rankx)) & 0xff);
        }
        if (num_ranks == 4) {
            /* Normally ODT1 is wired to rank 1. For quad-ranked DIMMs
               ODT1 is wired to the third rank (rank 2).  The mask,
               dyn_rtt_nom_mask, is used to indicate for which ranks
               to sweep RTT_NOM during read-leveling. Shift the bit
               from the ODT1 position over to the "ODT2" position so
               that the read-leveling analysis comes out right. */
            int odt1_bit = dyn_rtt_nom_mask & 2;
            dyn_rtt_nom_mask &= ~2;
            dyn_rtt_nom_mask |= odt1_bit<<1;
        }
        ddr_print("%-45s : 0x%02x\n", "DYN_RTT_NOM_MASK", dyn_rtt_nom_mask);
    }

    /* LMC(0)_COMP_CTL2 */
    {
        bdk_lmcx_comp_ctl2_t comp_ctl2;

        comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));

        comp_ctl2.s.dqx_ctl	= odt_config[odt_idx].odt_ena;
        comp_ctl2.s.ck_ctl	= (custom_lmc_config->ck_ctl  == 0) ? 4 : custom_lmc_config->ck_ctl;  /* Default 4=34.3 ohm */
        comp_ctl2.s.cmd_ctl	= (custom_lmc_config->cmd_ctl == 0) ? 4 : custom_lmc_config->cmd_ctl; /* Default 4=34.3 ohm */
        comp_ctl2.s.control_ctl	= (custom_lmc_config->ctl_ctl == 0) ? 4 : custom_lmc_config->ctl_ctl; /* Default 4=34.3 ohm */

        comp_ctl2.s.ntune_offset    = 0;
        comp_ctl2.s.ptune_offset    = 0;

        comp_ctl2.s.rodt_ctl = odt_config[odt_idx].qs_dic;

        if ((s = lookup_env_parameter("ddr_ck_ctl")) != NULL) {
            comp_ctl2.s.ck_ctl  = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_cmd_ctl")) != NULL) {
            comp_ctl2.s.cmd_ctl  = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_control_ctl")) != NULL) {
	    comp_ctl2.s.control_ctl  = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_dqx_ctl")) != NULL) {
            comp_ctl2.s.dqx_ctl  = strtoul(s, NULL, 0);
        }

#ifdef DDR3_ENHANCE_PRINT
        ddr_print("%-45s : %d, %d ohms\n", "DQX_CTL           ", comp_ctl2.s.dqx_ctl    , imp_values->dqx_strength  [comp_ctl2.s.dqx_ctl    ]);
        ddr_print("%-45s : %d, %d ohms\n", "CK_CTL            ", comp_ctl2.s.ck_ctl     , imp_values->drive_strength[comp_ctl2.s.ck_ctl     ]);
        ddr_print("%-45s : %d, %d ohms\n", "CMD_CTL           ", comp_ctl2.s.cmd_ctl    , imp_values->drive_strength[comp_ctl2.s.cmd_ctl    ]);
        ddr_print("%-45s : %d, %d ohms\n", "CONTROL_CTL       ", comp_ctl2.s.control_ctl, imp_values->drive_strength[comp_ctl2.s.control_ctl]);
#endif
        DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), comp_ctl2.u);
    }

    /* LMC(0)_PHY_CTL */
    {
        /* .s. */
        bdk_lmcx_phy_ctl_t lmc_phy_ctl;
        lmc_phy_ctl.u = BDK_CSR_READ(node, BDK_LMCX_PHY_CTL(ddr_interface_num));
        lmc_phy_ctl.s.ts_stagger           = 0;

        ddr_print("PHY_CTL                                       : 0x%016lx\n", lmc_phy_ctl.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_PHY_CTL(ddr_interface_num), lmc_phy_ctl.u);
    }

    /* LMC(0)_DIMM0/1_PARAMS */
    if (spd_rdimm) {
        bdk_lmcx_dimm_ctl_t lmc_dimm_ctl;

        for (didx = 0; didx < (unsigned)dimm_count; ++didx) {
	    bdk_lmcx_dimmx_params_t lmc_dimmx_params;
	    int dimm = didx;
	    int rc;

	    lmc_dimmx_params.u = BDK_CSR_READ(node, BDK_LMCX_DIMMX_PARAMS(ddr_interface_num, dimm));


            if (ddr_type == DDR4_DRAM) {

                bdk_lmcx_dimmx_ddr4_params0_t lmc_dimmx_ddr4_params0;
                bdk_lmcx_dimmx_ddr4_params1_t lmc_dimmx_ddr4_params1;
                bdk_lmcx_ddr4_dimm_ctl_t lmc_ddr4_dimm_ctl;

                lmc_dimmx_params.s.rc0  = 0;
                lmc_dimmx_params.s.rc1  = 0;
                lmc_dimmx_params.s.rc2  = 0;

                rc = read_spd(node, &dimm_config_table[didx], 0, DDR4_SPD_RDIMM_REGISTER_DRIVE_STRENGTH_CTL);
                lmc_dimmx_params.s.rc3  = (rc >> 4) & 0xf;
                lmc_dimmx_params.s.rc4  = ((rc >> 0) & 0x3) << 2;
                lmc_dimmx_params.s.rc4 |= ((rc >> 2) & 0x3) << 0;

                rc = read_spd(node, &dimm_config_table[didx], 0, DDR4_SPD_RDIMM_REGISTER_DRIVE_STRENGTH_CK);
                lmc_dimmx_params.s.rc5  = ((rc >> 0) & 0x3) << 2;
                lmc_dimmx_params.s.rc5 |= ((rc >> 2) & 0x3) << 0;

                lmc_dimmx_params.s.rc6  = 0;
                lmc_dimmx_params.s.rc7  = 0;
                lmc_dimmx_params.s.rc8  = 0;
                lmc_dimmx_params.s.rc9  = 0;

                /*
                ** rc10               DDR4 RDIMM Operating Speed
                ** ====   =========================================================
                **  0                 tclk_psecs >= 1250 psec DDR4-1600 (1250 ps)
                **  1     1250 psec > tclk_psecs >= 1071 psec DDR4-1866 (1071 ps)
                **  2     1071 psec > tclk_psecs >=  938 psec DDR4-2133 ( 938 ps)
                **  3      938 psec > tclk_psecs >=  833 psec DDR4-2400 ( 833 ps)
                **  4      833 psec > tclk_psecs >=  750 psec DDR4-2666 ( 750 ps)
                **  5      750 psec > tclk_psecs >=  625 psec DDR4-3200 ( 625 ps)
                */
                lmc_dimmx_params.s.rc10        = 0;
                if (1250 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 1;
                if (1071 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 2;
                if (938 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 3;
                if (833 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 4;
                if (750 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 5;

                lmc_dimmx_params.s.rc11 = 0;
                lmc_dimmx_params.s.rc12 = 0;
		lmc_dimmx_params.s.rc13 = (spd_dimm_type == 4) ? 0 : 4; /* 0=LRDIMM, 1=RDIMM */
		lmc_dimmx_params.s.rc13 |= (ddr_type == DDR4_DRAM) ? (spd_addr_mirror << 3) : 0;
                lmc_dimmx_params.s.rc14 = 0;
                //lmc_dimmx_params.s.rc15 = 4; /* 0 nCK latency adder */
                lmc_dimmx_params.s.rc15 = 0; /* 1 nCK latency adder */

                lmc_dimmx_ddr4_params0.u = 0;

                lmc_dimmx_ddr4_params0.s.rc8x = 0;
                lmc_dimmx_ddr4_params0.s.rc7x = 0;
                lmc_dimmx_ddr4_params0.s.rc6x = 0;
                lmc_dimmx_ddr4_params0.s.rc5x = 0;
                lmc_dimmx_ddr4_params0.s.rc4x = 0;

                lmc_dimmx_ddr4_params0.s.rc3x = compute_rc3x(tclk_psecs);

                lmc_dimmx_ddr4_params0.s.rc2x = 0;
                lmc_dimmx_ddr4_params0.s.rc1x = 0;

                lmc_dimmx_ddr4_params1.u = 0;

                lmc_dimmx_ddr4_params1.s.rcbx = 0;
                lmc_dimmx_ddr4_params1.s.rcax = 0;
                lmc_dimmx_ddr4_params1.s.rc9x = 0;

                lmc_ddr4_dimm_ctl.u = 0;
                lmc_ddr4_dimm_ctl.s.ddr4_dimm0_wmask = 0x004;
                lmc_ddr4_dimm_ctl.s.ddr4_dimm1_wmask = (dimm_count > 1) ? 0x004 : 0x0000;

		/*
		 * Handle any overrides from envvars here...
		 */
		if ((s = lookup_env_parameter("ddr_ddr4_params0")) != NULL) {
		    lmc_dimmx_ddr4_params0.u = strtoul(s, NULL, 0);
		}

		if ((s = lookup_env_parameter("ddr_ddr4_params1")) != NULL) {
		    lmc_dimmx_ddr4_params1.u = strtoul(s, NULL, 0);
		}

		if ((s = lookup_env_parameter("ddr_ddr4_dimm_ctl")) != NULL) {
		    lmc_ddr4_dimm_ctl.u = strtoul(s, NULL, 0);
		}

		for (i=0; i<11; ++i) {
		    uint64_t value;
		    if ((s = lookup_env_parameter("ddr_ddr4_rc%1xx", i+1)) != NULL) {
			value = strtoul(s, NULL, 0);
			if (i < 8) {
			    lmc_dimmx_ddr4_params0.u &= ~((uint64_t)0xff << (i*8));
			    lmc_dimmx_ddr4_params0.u |=           (value << (i*8));
			} else {
			    lmc_dimmx_ddr4_params1.u &= ~((uint64_t)0xff << ((i-8)*8));
			    lmc_dimmx_ddr4_params1.u |=           (value << ((i-8)*8));
			}
		    }
		}

		/*
		 * write the final CSR values
		 */
                DRAM_CSR_WRITE(node, BDK_LMCX_DIMMX_DDR4_PARAMS0(ddr_interface_num, dimm), lmc_dimmx_ddr4_params0.u);

                DRAM_CSR_WRITE(node, BDK_LMCX_DDR4_DIMM_CTL(ddr_interface_num), lmc_ddr4_dimm_ctl.u);

                DRAM_CSR_WRITE(node, BDK_LMCX_DIMMX_DDR4_PARAMS1(ddr_interface_num, dimm), lmc_dimmx_ddr4_params1.u);

                ddr_print("DIMM%d Register Control Words        RCBx:RC1x : %x %x %x %x %x %x %x %x %x %x %x\n",
                          dimm,
                          lmc_dimmx_ddr4_params1.s.rcbx,
                          lmc_dimmx_ddr4_params1.s.rcax,
                          lmc_dimmx_ddr4_params1.s.rc9x,
                          lmc_dimmx_ddr4_params0.s.rc8x,
                          lmc_dimmx_ddr4_params0.s.rc7x,
                          lmc_dimmx_ddr4_params0.s.rc6x,
                          lmc_dimmx_ddr4_params0.s.rc5x,
                          lmc_dimmx_ddr4_params0.s.rc4x,
                          lmc_dimmx_ddr4_params0.s.rc3x,
                          lmc_dimmx_ddr4_params0.s.rc2x,
                          lmc_dimmx_ddr4_params0.s.rc1x );

            } else { /* if (ddr_type == DDR4_DRAM) */
		rc = read_spd(node, &dimm_config_table[didx], 0, 69);
		lmc_dimmx_params.s.rc0         = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc1         = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 70);
		lmc_dimmx_params.s.rc2         = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc3         = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 71);
		lmc_dimmx_params.s.rc4         = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc5         = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 72);
		lmc_dimmx_params.s.rc6         = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc7         = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 73);
		lmc_dimmx_params.s.rc8         = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc9         = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 74);
		lmc_dimmx_params.s.rc10        = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc11        = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 75);
		lmc_dimmx_params.s.rc12        = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc13        = (rc >> 4) & 0xf;

		rc = read_spd(node, &dimm_config_table[didx], 0, 76);
		lmc_dimmx_params.s.rc14        = (rc >> 0) & 0xf;
		lmc_dimmx_params.s.rc15        = (rc >> 4) & 0xf;


		if ((s = lookup_env_parameter("ddr_clk_drive")) != NULL) {
		    if (strcmp(s,"light") == 0) {
			lmc_dimmx_params.s.rc5         = 0x0; /* Light Drive */
		    }
		    if (strcmp(s,"moderate") == 0) {
			lmc_dimmx_params.s.rc5         = 0x5; /* Moderate Drive */
		    }
		    if (strcmp(s,"strong") == 0) {
			lmc_dimmx_params.s.rc5         = 0xA; /* Strong Drive */
		    }
		}

		if ((s = lookup_env_parameter("ddr_cmd_drive")) != NULL) {
		    if (strcmp(s,"light") == 0) {
			lmc_dimmx_params.s.rc3         = 0x0; /* Light Drive */
		    }
		    if (strcmp(s,"moderate") == 0) {
			lmc_dimmx_params.s.rc3         = 0x5; /* Moderate Drive */
		    }
		    if (strcmp(s,"strong") == 0) {
			lmc_dimmx_params.s.rc3         = 0xA; /* Strong Drive */
		    }
		}

		if ((s = lookup_env_parameter("ddr_ctl_drive")) != NULL) {
		    if (strcmp(s,"light") == 0) {
			lmc_dimmx_params.s.rc4         = 0x0; /* Light Drive */
		    }
		    if (strcmp(s,"moderate") == 0) {
			lmc_dimmx_params.s.rc4         = 0x5; /* Moderate Drive */
		    }
		}


                /*
                ** rc10               DDR3 RDIMM Operating Speed
                ** ====   =========================================================
                **  0                 tclk_psecs >= 2500 psec DDR3/DDR3L-800 (default)
                **  1     2500 psec > tclk_psecs >= 1875 psec DDR3/DDR3L-1066
                **  2     1875 psec > tclk_psecs >= 1500 psec DDR3/DDR3L-1333
                **  3     1500 psec > tclk_psecs >= 1250 psec DDR3/DDR3L-1600
                **  4     1250 psec > tclk_psecs >= 1071 psec DDR3-1866
                */
                lmc_dimmx_params.s.rc10        = 0;
                if (2500 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 1;
                if (1875 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 2;
                if (1500 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 3;
                if (1250 > tclk_psecs)
                    lmc_dimmx_params.s.rc10    = 4;

	    } /* if (ddr_type == DDR4_DRAM) */

            if ((s = lookup_env_parameter("ddr_dimmx_params")) != NULL) {
                lmc_dimmx_params.u = strtoul(s, NULL, 0);
            }

	    for (i=0; i<16; ++i) {
		uint64_t value;
		if ((s = lookup_env_parameter("ddr_rc%d", i)) != NULL) {
		    value = strtoul(s, NULL, 0);
		    lmc_dimmx_params.u &= ~((uint64_t)0xf << (i*4));
		    lmc_dimmx_params.u |=           (  value << (i*4));
		}
	    }

	    DRAM_CSR_WRITE(node, BDK_LMCX_DIMMX_PARAMS(ddr_interface_num, dimm), lmc_dimmx_params.u);

	    ddr_print("DIMM%d Register Control Words         RC15:RC0 : %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x\n",
		      dimm,
		      lmc_dimmx_params.s.rc15,
		      lmc_dimmx_params.s.rc14,
		      lmc_dimmx_params.s.rc13,
		      lmc_dimmx_params.s.rc12,
		      lmc_dimmx_params.s.rc11,
		      lmc_dimmx_params.s.rc10,
		      lmc_dimmx_params.s.rc9 ,
		      lmc_dimmx_params.s.rc8 ,
		      lmc_dimmx_params.s.rc7 ,
		      lmc_dimmx_params.s.rc6 ,
		      lmc_dimmx_params.s.rc5 ,
		      lmc_dimmx_params.s.rc4 ,
		      lmc_dimmx_params.s.rc3 ,
		      lmc_dimmx_params.s.rc2 ,
		      lmc_dimmx_params.s.rc1 ,
		      lmc_dimmx_params.s.rc0 );
	} /* for didx */

	if (ddr_type == DDR4_DRAM) {

	    /* LMC0_DIMM_CTL */
	    lmc_dimm_ctl.u = BDK_CSR_READ(node, BDK_LMCX_DIMM_CTL(ddr_interface_num));
	    lmc_dimm_ctl.s.dimm0_wmask         = 0xdf3f;
	    lmc_dimm_ctl.s.dimm1_wmask         = (dimm_count > 1) ? 0xdf3f : 0x0000;
	    lmc_dimm_ctl.s.tcws                = 0x4e0;
	    lmc_dimm_ctl.s.parity              = custom_lmc_config->parity;

	    if ((s = lookup_env_parameter("ddr_dimm0_wmask")) != NULL) {
		lmc_dimm_ctl.s.dimm0_wmask    = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm1_wmask")) != NULL) {
		lmc_dimm_ctl.s.dimm1_wmask    = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm_ctl_parity")) != NULL) {
		lmc_dimm_ctl.s.parity = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm_ctl_tcws")) != NULL) {
		lmc_dimm_ctl.s.tcws = strtoul(s, NULL, 0);
	    }

	    ddr_print("LMC DIMM_CTL                                  : 0x%016lx\n", lmc_dimm_ctl.u);
	    DRAM_CSR_WRITE(node, BDK_LMCX_DIMM_CTL(ddr_interface_num), lmc_dimm_ctl.u);

	    perform_octeon3_ddr3_sequence(node, rank_mask,
					  ddr_interface_num, 0x7 ); /* Init RCW */

	    /* Write RC0D last */
	    lmc_dimm_ctl.s.dimm0_wmask         = 0x2000;
	    lmc_dimm_ctl.s.dimm1_wmask         = (dimm_count > 1) ? 0x2000 : 0x0000;
	    ddr_print("LMC DIMM_CTL                                  : 0x%016lx\n", lmc_dimm_ctl.u);
	    DRAM_CSR_WRITE(node, BDK_LMCX_DIMM_CTL(ddr_interface_num), lmc_dimm_ctl.u);

	    /* Don't write any extended registers the second time */
	    DRAM_CSR_WRITE(node, BDK_LMCX_DDR4_DIMM_CTL(ddr_interface_num), 0);

	    perform_octeon3_ddr3_sequence(node, rank_mask,
					  ddr_interface_num, 0x7 ); /* Init RCW */
        } else {

	    /* LMC0_DIMM_CTL */
	    lmc_dimm_ctl.u = BDK_CSR_READ(node, BDK_LMCX_DIMM_CTL(ddr_interface_num));
	    lmc_dimm_ctl.s.dimm0_wmask         = 0xffff;
	    lmc_dimm_ctl.s.dimm1_wmask         = (dimm_count > 1) ? 0xffff : 0x0000;
	    lmc_dimm_ctl.s.tcws                = 0x4e0;
	    lmc_dimm_ctl.s.parity              = custom_lmc_config->parity;

	    if ((s = lookup_env_parameter("ddr_dimm0_wmask")) != NULL) {
		lmc_dimm_ctl.s.dimm0_wmask    = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm1_wmask")) != NULL) {
		lmc_dimm_ctl.s.dimm1_wmask    = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm_ctl_parity")) != NULL) {
		lmc_dimm_ctl.s.parity = strtoul(s, NULL, 0);
	    }

	    if ((s = lookup_env_parameter("ddr_dimm_ctl_tcws")) != NULL) {
		lmc_dimm_ctl.s.tcws = strtoul(s, NULL, 0);
	    }

	    ddr_print("LMC DIMM_CTL                                : 0x%016lx\n", lmc_dimm_ctl.u);
	    DRAM_CSR_WRITE(node, BDK_LMCX_DIMM_CTL(ddr_interface_num), lmc_dimm_ctl.u);

	    perform_octeon3_ddr3_sequence(node, rank_mask,
					  ddr_interface_num, 0x7 ); /* Init RCW */
	}
    } else { /* if (spd_rdimm) */
        /* Disable register control writes for unbuffered */
        bdk_lmcx_dimm_ctl_t lmc_dimm_ctl;
        lmc_dimm_ctl.u = BDK_CSR_READ(node, BDK_LMCX_DIMM_CTL(ddr_interface_num));
        lmc_dimm_ctl.s.dimm0_wmask         = 0;
        lmc_dimm_ctl.s.dimm1_wmask         = 0;
        DRAM_CSR_WRITE(node, BDK_LMCX_DIMM_CTL(ddr_interface_num), lmc_dimm_ctl.u);
    } /* if (spd_rdimm) */

    /*
     * Comments (steps 3 through 5) continue in perform_octeon3_ddr3_sequence()
     */

    if (! (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm))
    {
        bdk_lmcx_modereg_params0_t lmc_modereg_params0;

        lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));

        lmc_modereg_params0.s.dllr = 1;
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);

        perform_ddr3_init_sequence(node, rank_mask, ddr_interface_num);

        lmc_modereg_params0.s.dllr = 0;
        DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);
    }

    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X) && (spd_rdimm) && (ddr_type == DDR4_DRAM)) {
#if RUN_INIT_SEQ_1
        if (run_init_sequence_1) {
            ddr_print("Running init sequence 1\n");
            change_rdimm_mpr_pattern(node, rank_mask, ddr_interface_num, dimm_count);
        }
#endif
#if RUN_INIT_SEQ_2
        if (run_init_sequence_2) {
            ddr_print("Running init sequence 2\n");
            change_rdimm_mpr_pattern2(node, rank_mask, ddr_interface_num, dimm_count);
        }
#endif
#if RUN_INIT_SEQ_3
        if (run_init_sequence_3) {
            ddr_print("Running init sequence 3\n");
            change_rdimm_mpr_pattern3(node, rank_mask, ddr_interface_num, dimm_count);
        }
#endif
    }

    int offset_vref_training_loops = 2;
    while (--offset_vref_training_loops) {
    /*
     * 4.8.6 LMC Offset Training
     * 
     * LMC requires input-receiver offset training.
     * 
     * 1. Write LMC(0)_PHY_CTL[DAC_ON] = 1
     */
#if RUN_INIT_SEQ_3
    if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {
        ddr_print("24) Offset Training sequence=0xb\n");
    }
#endif
    if (ddr_interface_num != 1)
    {
        bdk_lmcx_phy_ctl_t lmc_phy_ctl;
        lmc_phy_ctl.u = BDK_CSR_READ(node, BDK_LMCX_PHY_CTL(ddr_interface_num));
        lmc_phy_ctl.s.dac_on = 1;
        ddr_print("PHY_CTL                                       : 0x%016lx\n", lmc_phy_ctl.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_PHY_CTL(ddr_interface_num), lmc_phy_ctl.u);
    }

    if ((s = lookup_env_parameter_ull("ddr_phy_ctl")) != NULL) {
        bdk_lmcx_phy_ctl_t lmc_phy_ctl;
        lmc_phy_ctl.u    = strtoull(s, NULL, 0);
        ddr_print("PHY_CTL                                       : 0x%016lx\n", lmc_phy_ctl.u);
        DRAM_CSR_WRITE(node, BDK_LMCX_PHY_CTL(ddr_interface_num), lmc_phy_ctl.u);
    }

    /*
     * 2. Write LMC(0)_SEQ_CTL[SEQ_SEL] = 0x0B and
     *    LMC(0)_SEQ_CTL[INIT_START] = 1.
     * 
     * 3. Wait for LMC(0)_SEQ_CTL[SEQ_COMPLETE] to be set to 1.
     */
    {
        bdk_lmcx_comp_ctl2_t lmc_comp_ctl2;
        lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));

        ddr_print("Read ODT_CTL                                  : 0x%x (%d ohms)\n",
                  lmc_comp_ctl2.s.rodt_ctl, imp_values->rodt_ohms[lmc_comp_ctl2.s.rodt_ctl]);
	perform_octeon3_ddr3_sequence(node, rank_mask, ddr_interface_num, 0x0B); /* Offset training sequence */
    }

    /*
     * 4.8.7 LMC Internal Vref Training
     * 
     * LMC requires input-reference-voltage training.
     * 
     * 1. Write LMC(0)_EXT_CONFIG[VREFINT_SEQ_DESKEW] = 0.
     */
#if RUN_INIT_SEQ_3
    if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {
        ddr_print("25) VREF internal training (sequence = 0xa). At this point, the B-side is still in MPR mode.\n");
        ddr_print("25a) Put the B side only of rank 0 into MPR mode\n");

        set_mpr_mode(node, 1, ddr_interface_num, dimm_count, /* mpr */ 1, /* bg1 */ 1); /* B-side */
    }
#endif
    {
        bdk_lmcx_ext_config_t ext_config;
        ext_config.u = BDK_CSR_READ(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num));
        ext_config.s.vrefint_seq_deskew = 0;

	ddr_seq_print("Performing LMC sequence: vrefint_seq_deskew = %d\n",
                      ext_config.s.vrefint_seq_deskew);

        DRAM_CSR_WRITE(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num), ext_config.u);
    }

    /*
     * 2. Write LMC(0)_SEQ_CTL[SEQ_SEL] = 0x0a and
     *    LMC(0)_SEQ_CTL[INIT_START] = 1.
     * 
     * 3. Wait for LMC(0)_SEQ_CTL[SEQ_COMPLETE] to be set to 1.
     */

    perform_octeon3_ddr3_sequence(node, rank_mask, ddr_interface_num, 0x0A); /* LMC Internal Vref Training */

    } /* while (--offset_vref_training_loops) */

    perform_LMC_Deskew_Training(node, rank_mask, ddr_interface_num, spd_rawcard);

    // save the results of the original training
    Validate_Deskew_Training(node, rank_mask, ddr_interface_num, &deskew_training_results, 0);


#if RUN_INIT_SEQ_3
    if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {

#if 0
        /*
         * 27) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1. (required for step 25).
         */

        ddr_print("27) Re-enable RDIMM_ENA\n");

        set_rdimm_mode(node, ddr_interface_num, 1);

        /* 28) Disable RDIMM Inversion (RC00[0]=1). */

        ddr_print("28) Disable RDIMM Inversion (RC00[0]=1).\n");

        set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                               1 /* 1=disable output inversion*/);
#endif

        /*
         * 29) Disable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 0.
         */

        ddr_print("29) Disable CONTROL[RDIMM_ENA]\n");

        set_rdimm_mode(node, ddr_interface_num, 0);

        /*
         * 30) Take B-side devices out of MPR mode (Run MRW sequence (sequence=8) with 
         * MODEREG_PARAMS0[MPR]=0, MR_MPR_CTL[MR_WR_SEL]=3, 
         * MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=1 and MR_MPR_CTL[MR_WR_BG1] = 1 ).
         */

        ddr_print("30)Take B-side devices out of MPR mode\n");

        set_mpr_mode(node, rank_mask, ddr_interface_num, dimm_count, /* mpr */ 0, /* bg1 */ 1); /* B-side */

#if 0
        /*
         * 31) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1. (required for step 29).
         */

        ddr_print("31) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1. (required for step 29).\n");

        set_rdimm_mode(node, ddr_interface_num, 1);

        /*
         * 32) Re-enable RDIMM Inversion (RC00[0]=0).
         */

        ddr_print("32) Re-enable RDIMM Inversion (RC00[0]=0).\n");

        set_DRAM_output_inversion(node, ddr_interface_num, dimm_count, rank_mask,
                               1 /* 1=disable output inversion*/);

        /*
         * 33) Turn Off lmc's RDIMM mode before running hardware write leveling. 
         * CONTROL[RDIMM_ENA] = 0.
         */

        ddr_print("33) Turn Off lmc's RDIMM mode before running hardware write leveling. \n");

        set_rdimm_mode(node, ddr_interface_num, 0);
#endif
    }
#endif

    /* LMC(0)_EXT_CONFIG */
    {
        bdk_lmcx_ext_config_t ext_config;
        ext_config.u = BDK_CSR_READ(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num));
        ext_config.s.vrefint_seq_deskew = 0;
        ext_config.s.read_ena_bprch = 1;
        ext_config.s.read_ena_fprch = 1;
        ext_config.s.drive_ena_fprch = 1;
        ext_config.s.drive_ena_bprch = 1;

        if ((s = lookup_env_parameter("ddr_read_fprch")) != NULL) {
            ext_config.s.read_ena_fprch = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_read_bprch")) != NULL) {
            ext_config.s.read_ena_bprch = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_drive_fprch")) != NULL) {
            ext_config.s.drive_ena_fprch = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_drive_bprch")) != NULL) {
            ext_config.s.drive_ena_bprch = strtoul(s, NULL, 0);
        }

        DRAM_CSR_WRITE(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num), ext_config.u);
        ddr_print("%-45s : 0x%016lx\n", "EXT_CONFIG", ext_config.u);
    }


    {
        bdk_lmcx_config_t lmc_config;
        int save_ref_zqcs_int;
        uint64_t temp_delay_usecs;

        lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));

        /* Temporarily select the minimum ZQCS interval and wait
           long enough for a few ZQCS calibrations to occur.  This
           should ensure that the calibration circuitry is
           stabilized before read/write leveling occurs. */
	save_ref_zqcs_int         = lmc_config.s.ref_zqcs_int;
	lmc_config.s.ref_zqcs_int = 1 | (32<<7); /* set smallest interval */

        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
        BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));

        /* Compute an appropriate delay based on the current ZQCS
           interval. The delay should be long enough for the
           current ZQCS delay counter to expire plus ten of the
           minimum intarvals to ensure that some calibrations
           occur. */
        temp_delay_usecs = (((uint64_t)save_ref_zqcs_int >> 7)
                            * tclk_psecs * 100 * 512 * 128) / (10000*10000)
            + 10 * ((uint64_t)32 * tclk_psecs * 100 * 512 * 128) / (10000*10000);

        ddr_print ("Waiting %ld usecs for ZQCS calibrations to start\n",
                   temp_delay_usecs);
        bdk_wait_usec(temp_delay_usecs);

	lmc_config.s.ref_zqcs_int = save_ref_zqcs_int; /* Restore computed interval */

        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
        BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
    }

    /*
     * 4.8.9 LMC Write Leveling
     * 
     * LMC supports an automatic write leveling like that described in the
     * JEDEC DDR3 specifications separately per byte-lane.
     * 
     * All of DDR PLL, LMC CK, LMC DRESET, and early LMC initializations must
     * be completed prior to starting this LMC write-leveling sequence.
     * 
     * There are many possible procedures that will write-level all the
     * attached DDR3 DRAM parts. One possibility is for software to simply
     * write the desired values into LMC(0)_WLEVEL_RANK(0..3). This section
     * describes one possible sequence that uses LMC's autowrite-leveling
     * capabilities.
     * 
     * 1. If the DQS/DQ delays on the board may be more than the ADD/CMD
     *    delays, then ensure that LMC(0)_CONFIG[EARLY_DQX] is set at this
     *    point.
     * 
     * Do the remaining steps 2-7 separately for each rank i with attached
     * DRAM.
     * 
     * 2. Write LMC(0)_WLEVEL_RANKi = 0.
     * 
     * 3. For ×8 parts:
     * 
     *    Without changing any other fields in LMC(0)_WLEVEL_CTL, write
     *    LMC(0)_WLEVEL_CTL[LANEMASK] to select all byte lanes with attached
     *    DRAM.
     * 
     *    For ×16 parts:
     * 
     *    Without changing any other fields in LMC(0)_WLEVEL_CTL, write
     *    LMC(0)_WLEVEL_CTL[LANEMASK] to select all even byte lanes with
     *    attached DRAM.
     * 
     * 4. Without changing any other fields in LMC(0)_CONFIG,
     * 
     *    o write LMC(0)_SEQ_CTL[SEQ_SEL] to select write-leveling
     * 
     *    o write LMC(0)_CONFIG[RANKMASK] = (1 << i)
     * 
     *    o write LMC(0)_SEQ_CTL[INIT_START] = 1
     * 
     *    LMC will initiate write-leveling at this point. Assuming
     *    LMC(0)_WLEVEL_CTL [SSET] = 0, LMC first enables write-leveling on
     *    the selected DRAM rank via a DDR3 MR1 write, then sequences through
     *    and accumulates write-leveling results for eight different delay
     *    settings twice, starting at a delay of zero in this case since
     *    LMC(0)_WLEVEL_RANKi[BYTE*<4:3>] = 0, increasing by 1/8 CK each
     *    setting, covering a total distance of one CK, then disables the
     *    write-leveling via another DDR3 MR1 write.
     * 
     *    After the sequence through 16 delay settings is complete:
     * 
     *    o LMC sets LMC(0)_WLEVEL_RANKi[STATUS] = 3
     * 
     *    o LMC sets LMC(0)_WLEVEL_RANKi[BYTE*<2:0>] (for all ranks selected
     *      by LMC(0)_WLEVEL_CTL[LANEMASK]) to indicate the first write
     *      leveling result of 1 that followed result of 0 during the
     *      sequence, except that the LMC always writes
     *      LMC(0)_WLEVEL_RANKi[BYTE*<0>]=0.
     * 
     *    o Software can read the eight write-leveling results from the first
     *      pass through the delay settings by reading
     *      LMC(0)_WLEVEL_DBG[BITMASK] (after writing
     *      LMC(0)_WLEVEL_DBG[BYTE]). (LMC does not retain the writeleveling
     *      results from the second pass through the eight delay
     *      settings. They should often be identical to the
     *      LMC(0)_WLEVEL_DBG[BITMASK] results, though.)
     * 
     * 5. Wait until LMC(0)_WLEVEL_RANKi[STATUS] != 2.
     * 
     *    LMC will have updated LMC(0)_WLEVEL_RANKi[BYTE*<2:0>] for all byte
     *    lanes selected by LMC(0)_WLEVEL_CTL[LANEMASK] at this point.
     *    LMC(0)_WLEVEL_RANKi[BYTE*<4:3>] will still be the value that
     *    software wrote in substep 2 above, which is 0.
     * 
     * 6. For ×16 parts:
     * 
     *    Without changing any other fields in LMC(0)_WLEVEL_CTL, write
     *    LMC(0)_WLEVEL_CTL[LANEMASK] to select all odd byte lanes with
     *    attached DRAM.
     * 
     *    Repeat substeps 4 and 5 with this new LMC(0)_WLEVEL_CTL[LANEMASK]
     *    setting. Skip to substep 7 if this has already been done.
     * 
     *    For ×8 parts:
     * 
     *    Skip this substep. Go to substep 7.
     * 
     * 7. Calculate LMC(0)_WLEVEL_RANKi[BYTE*<4:3>] settings for all byte
     *    lanes on all ranks with attached DRAM.
     * 
     *    At this point, all byte lanes on rank i with attached DRAM should
     *    have been write-leveled, and LMC(0)_WLEVEL_RANKi[BYTE*<2:0>] has
     *    the result for each byte lane.
     * 
     *    But note that the DDR3 write-leveling sequence will only determine
     *    the delay modulo the CK cycle time, and cannot determine how many
     *    additional CK cycles of delay are present. Software must calculate
     *    the number of CK cycles, or equivalently, the
     *    LMC(0)_WLEVEL_RANKi[BYTE*<4:3>] settings.
     * 
     *    This BYTE*<4:3> calculation is system/board specific.
     * 
     * Many techniques can be used to calculate write-leveling BYTE*<4:3> values,
     * including:
     * 
     *    o Known values for some byte lanes.
     * 
     *    o Relative values for some byte lanes relative to others.
     * 
     *    For example, suppose lane X is likely to require a larger
     *    write-leveling delay than lane Y. A BYTEX<2:0> value that is much
     *    smaller than the BYTEY<2:0> value may then indicate that the
     *    required lane X delay wrapped into the next CK, so BYTEX<4:3>
     *    should be set to BYTEY<4:3>+1.
     * 
     *    When ECC DRAM is not present (i.e. when DRAM is not attached to the
     *    DDR_CBS_0_* and DDR_CB<7:0> chip signals, or the DDR_DQS_<4>_* and
     *    DDR_DQ<35:32> chip signals), write LMC(0)_WLEVEL_RANK*[BYTE8] =
     *    LMC(0)_WLEVEL_RANK*[BYTE0], using the final calculated BYTE0 value.
     *    Write LMC(0)_WLEVEL_RANK*[BYTE4] = LMC(0)_WLEVEL_RANK*[BYTE0],
     *    using the final calculated BYTE0 value.
     * 
     * 8. Initialize LMC(0)_WLEVEL_RANK* values for all unused ranks.
     * 
     *    Let rank i be a rank with attached DRAM.
     * 
     *    For all ranks j that do not have attached DRAM, set
     *    LMC(0)_WLEVEL_RANKj = LMC(0)_WLEVEL_RANKi.
     */
    {
#pragma pack(push,1)
        bdk_lmcx_wlevel_ctl_t wlevel_ctl;
        bdk_lmcx_wlevel_rankx_t lmc_wlevel_rank;
#if RUN_INIT_SEQ_3
        bdk_lmcx_modereg_params0_t lmc_modereg_params0;
        bdk_lmcx_modereg_params1_t lmc_modereg_params1;
#endif
        bdk_lmcx_config_t lmc_config;
        int rankx = 0;
        int wlevel_bitmask[9];
        int byte_idx;
        int passx;
        int ecc_ena;
        int ddr_wlevel_roundup = 0;
        int save_mode32b;
#pragma pack(pop)

        if (wlevel_loops)
            ddr_print("N%d.LMC%d: Performing Write-Leveling\n", node, ddr_interface_num);
        else {
            wlevel_bitmask_errors = 1; /* Force software write-leveling to run */
#ifdef DDR3_ENHANCE_PRINT
            ddr_print("Forcing software Write-Leveling\n");
#endif
	}
#if RUN_INIT_SEQ_3
        if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {
            /* 
             * 36) Hardware Write leveling (sequence = 6)
             *        Write leveling to both A and B sides.
             */
            ddr_print("36) Hardware Write leveling (sequence = 6) Write leveling to both A and B sides.\n");
        }
#endif
        lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
        save_mode32b = lmc_config.s.mode32b;
        lmc_config.s.mode32b         = (! ddr_interface_64b);
        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
        ddr_print("%-45s : %d\n", "MODE32B", lmc_config.s.mode32b);

        while(wlevel_loops--) {

	    if ((s = lookup_env_parameter("ddr_wlevel_roundup")) != NULL) {
		ddr_wlevel_roundup = strtoul(s, NULL, 0);
	    }
#if RUN_INIT_SEQ_3
	    lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));
	    lmc_modereg_params1.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num));
#endif
	    for (rankx = 0; rankx < dimm_count * 4; rankx++) {
#if RUN_INIT_SEQ_3
		uint32_t mr_wr_addr;
#endif

		if (!(rank_mask & (1 << rankx)))
		    continue;

		wlevel_ctl.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_CTL(ddr_interface_num));
		lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
		ecc_ena = lmc_config.s.ecc_ena;

		wlevel_ctl.s.rtt_nom   = ddr4_rttnom_240ohm - 1; /* FIX */

		if ((s = lookup_env_parameter("ddr_wlevel_rtt_nom")) != NULL) {
		    wlevel_ctl.s.rtt_nom   = strtoul(s, NULL, 0);
		}

#if RUN_INIT_SEQ_3
		if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {
		    int rank_disable;
		    int rank_disable_mask = rank_mask & ~(1 << rankx); /* Disable all the others */
		    for (rank_disable = 0; rank_disable < dimm_count * 4; rank_disable++) {
			if (!(rank_disable_mask & (1 << rank_disable)))
			    continue;
			/*
			 * 34) Disable B side Output Buffer for all ranks that are not being write leveled. (One MRW 
			 * sequence for each rank). Sequence = 8.
			 *        - MR_MPR_CTL[MR_WR_BG1]=1, MR_MPR_CTL[MR_WR_SEL]=0x6, 
			 * MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=0,
			 *          MR_MPR_CTL[MR_WR_RANK] = x.  
			 *  
			 *          MR_MPR_CTL[MR_WR_ADDR<17>] = 1. 
			 *          MR_MPR_CTL[MR_WR_ADDR<16:14>] = 0. 
			 *          MR_MPR_CTL[MR_WR_ADDR<13>] = 1 
			 *          MR_MPR_CTL[MR_WR_ADDR<12>] = 1 (disable output buffer).  ***
			 *          MR_MPR_CTL[MR_WR_ADDR<11>] = ~MODEREG_PARAMS0[TDQS].  
			 *          MR_MPR_CTL[MR_WR_ADDR<10>] = MODEREG_PARAMS1[RTT_NOM_x<2>]. 
			 *          MR_MPR_CTL[MR_WR_ADDR<9>]   = ~MODEREG_PARAMS1[RTT_NOM_x<1>].
			 *          MR_MPR_CTL[MR_WR_ADDR<8>]   = ~MODEREG_PARAMS1[RTT_NOM_x<0>].
			 *          MR_MPR_CTL[MR_WR_ADDR<7>]   = 1
			 *          MR_MPR_CTL[MR_WR_ADDR<6:5>] = 3  
			 *          MR_MPR_CTL[MR_WR_ADDR<4:3>] = 3 
			 *          MR_MPR_CTL[MR_WR_ADDR<2:1>] = MODEREG_PARAMS1[DIC_x<1:0>]. 
			 *          MR_MPR_CTL[MR_WR_ADDR<0>]   = MODEREG_PARAMS0[DLL]. 
			 *          
			 *          Where 'x' is the rank number (2'b00 - 2'b11) that is not being write leveled.
			 */

			ddr_print("34) Disable B side Output Buffer for all ranks that are not being write leveled.\n");

			mr_wr_addr  =  lmc_modereg_params0.s.dll; /* DLL Enable */
			mr_wr_addr |=  ((lmc_modereg_params1.u >> (rank_disable*12+7)) & 3)  <<  1; /* DIC */
			mr_wr_addr |=     3                                                    <<  3; /* Additive Latency */
			mr_wr_addr |=     3                                                    <<  5; /* RFU */
			mr_wr_addr |=     1                                                    <<  7; /* Turn off Write Leveling mode */
			mr_wr_addr |= (~(lmc_modereg_params1.u >> (rank_disable*12+9))  & 3) <<  8; /* RTT_NOM<0:1> */
			mr_wr_addr |= ( (lmc_modereg_params1.u >> (rank_disable*12+11)) & 1) << 10; /* RTT_NOM<2> */
			mr_wr_addr |=  lmc_modereg_params0.s.tdqs                              << 11; /* TDQS enable */
			mr_wr_addr |=     1                                                    << 12; /* disable output buffer */
			mr_wr_addr |=     1                                                    << 13; /* RFU */
			mr_wr_addr |=     0                                                    << 14;
			mr_wr_addr |=     1                                                    << 17; /* RFU */
			ddr4_mrw(node, ddr_interface_num, rank_disable, mr_wr_addr, ~1, 1); /* MR1 B-side */
		    }

		    /*
		     * 35) Enable B side write-leveling mode to a particular rank. (One MRW sequence). Sequence = 8. 
		     *        - MR_MPR_CTL[MR_WR_BG1]=1, MR_MPR_CTL[MR_WR_SEL]=0x6, 
		     * MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=0, 
		     *          MR_MPR_CTL[MR_WR_RANK] = y.
		     *          MR_MPR_CTL[MR_WR_ADDR<17>] = 1.  
		     *          MR_MPR_CTL[MR_WR_ADDR<16:14>] = 0. 
		     *          MR_MPR_CTL[MR_WR_ADDR<13>] = 1 
		     *          MR_MPR_CTL[MR_WR_ADDR<12>] = 0 (enable output buffer).
		     *          MR_MPR_CTL[MR_WR_ADDR<11>] = ~MODEREG_PARAMS0[TDQS].
		     * 
		     *          variable wlevel_rtt_nom[2:0] =  WLEVEL_CTL[RTT_NOM] + 3'h1.  
		     *  
		     *          MR_MPR_CTL[MR_WR_ADDR<10>] = wlevel_rtt_nom[2]. 
		     *          MR_MPR_CTL[MR_WR_ADDR<9>]   = ~wlevel_rtt_nom[1].
		     *          MR_MPR_CTL[MR_WR_ADDR<8>]   = ~wlevel_rtt_nom[0].
		     *          MR_MPR_CTL[MR_WR_ADDR<7>]   = 0. (Turn on Write Leveling mode). ***
		     *          MR_MPR_CTL[MR_WR_ADDR<6:5>] = 3  
		     *          MR_MPR_CTL[MR_WR_ADDR<4:3>] = 3 
		     *          MR_MPR_CTL[MR_WR_ADDR<2:1>] = MODEREG_PARAMS1[DIC_y<1:0>]. 
		     *          MR_MPR_CTL[MR_WR_ADDR<0>]   = MODEREG_PARAMS0[DLL].
		     *          
		     *          Where 'y' is the rank number (2'b00 - 2'b11) that is going to be write-leveled.
		     */

		    ddr_print("35) Enable B side write-leveling mode to a particular rank. (One MRW sequence). Sequence = 8. \n");

		    mr_wr_addr  =  lmc_modereg_params0.s.dll; /* DLL Enable */
		    mr_wr_addr |=  ((lmc_modereg_params1.u >> (rankx*12+7)) & 3)  <<  1; /* DIC */
		    mr_wr_addr |=     3                                             <<  3; /* Additive Latency */
		    mr_wr_addr |=     3                                             <<  5; /* RFU */
		    mr_wr_addr |=     0                                             <<  7; /* Turn on Write Leveling mode */
		    mr_wr_addr |=  ( ~wlevel_ctl.s.rtt_nom  & 3)                    <<  8; /* RTT_NOM<0:1> */
		    mr_wr_addr |=  ( (wlevel_ctl.s.rtt_nom >> 2)  & 1)              << 10; /* RTT_NOM<2> */
		    mr_wr_addr |=  lmc_modereg_params0.s.tdqs                       << 11; /* TDQS enable */
		    mr_wr_addr |=     0                                             << 12; /* enable output buffer */
		    mr_wr_addr |=     1                                             << 13; /* RFU */
		    mr_wr_addr |=     0                                             << 14;
		    mr_wr_addr |=     1                                             << 17; /* RFU */
		    ddr4_mrw(node, ddr_interface_num, rankx, mr_wr_addr, ~1, 1); /* MR1 B-side */ // FIXME??
		}
#endif
		DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), 0); /* Clear write-level delays */
		wlevel_bitmask_errors = 0; /* Reset error counter */

		for (byte_idx=0; byte_idx<9; ++byte_idx) {
		    wlevel_bitmask[byte_idx] = 0; /* Reset bitmasks */
		}

		/* Make separate passes for each byte to reduce power. */
#if 0
		for (passx=0; passx<(8+ecc_ena); ++passx) {

		    if (!(ddr_interface_bytemask&(1<<passx)))
			continue;

		    wlevel_ctl.s.lanemask = (1<<passx);

		    DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_CTL(ddr_interface_num), wlevel_ctl.u);

		    /* Read and write values back in order to update the
		       status field. This insurs that we read the updated
		       values after write-leveling has completed. */
		    DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx),
				   BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx)));

		    perform_octeon3_ddr3_sequence(node, 1 << rankx, ddr_interface_num, 6); /* write-leveling */

		    if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
			BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx),
					       status, ==, 3, 1000000))
		    {
			error_print("ERROR: Timeout waiting for WLEVEL\n");
		    }
		    lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

		    wlevel_bitmask[passx] = octeon_read_lmcx_ddr3_wlevel_dbg(node, ddr_interface_num, passx);
		    if (wlevel_bitmask[passx] == 0)
			++wlevel_bitmask_errors;
		} /* for (passx=0; passx<(8+ecc_ena); ++passx) */
#else
		wlevel_ctl.s.lanemask = 0x1ff;

		DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_CTL(ddr_interface_num), wlevel_ctl.u);

		/* Read and write values back in order to update the
		   status field. This insurs that we read the updated
		   values after write-leveling has completed. */
		DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx),
			       BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx)));

		perform_octeon3_ddr3_sequence(node, 1 << rankx, ddr_interface_num, 6); /* write-leveling */

		if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
		    BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx),
					   status, ==, 3, 1000000))
		{
		    error_print("ERROR: Timeout waiting for WLEVEL\n");
		}
		lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

		for (passx=0; passx<(8+ecc_ena); ++passx) {
		    wlevel_bitmask[passx] = octeon_read_lmcx_ddr3_wlevel_dbg(node, ddr_interface_num, passx);
		    if (wlevel_bitmask[passx] == 0)
			++wlevel_bitmask_errors;
		} /* for (passx=0; passx<(8+ecc_ena); ++passx) */
#endif

		ddr_print("N%d.LMC%d.R%d: Wlevel Debug Results                  : %05x %05x %05x %05x %05x %05x %05x %05x %05x\n",
			  node, ddr_interface_num, rankx,
			  wlevel_bitmask[8],
			  wlevel_bitmask[7],
			  wlevel_bitmask[6],
			  wlevel_bitmask[5],
			  wlevel_bitmask[4],
			  wlevel_bitmask[3],
			  wlevel_bitmask[2],
			  wlevel_bitmask[1],
			  wlevel_bitmask[0]
			  );

		display_write_leveling_settings(node, ddr_interface_num, lmc_wlevel_rank, rankx);

		if (ddr_wlevel_roundup) { /* Round up odd bitmask delays */
		    for (byte_idx=0; byte_idx<(8+ecc_ena); ++byte_idx) {
			if (!(ddr_interface_bytemask&(1<<byte_idx)))
			    continue;
			update_wlevel_rank_struct(&lmc_wlevel_rank,
						  byte_idx,
						  roundup_ddr3_wlevel_bitmask(wlevel_bitmask[byte_idx]));
		    }
		    DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), lmc_wlevel_rank.u);
		    display_write_leveling_settings(node, ddr_interface_num, lmc_wlevel_rank, rankx);
		}

		if (wlevel_bitmask_errors != 0) {
		    ddr_print("Rank(%d) Write-Leveling Failed: %d Bitmask errors\n", rankx, wlevel_bitmask_errors);
		}
#if RUN_INIT_SEQ_3
		if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {
		    /*
		     * 37) Disable write-leveling on the B side. Re-enable output buffer on all ranks that were not 
		     * write-leveled. (One MRW sequence per rank). Sequence = 8.
		     *        Do this step for all available ranks.
		     *        - MR_MPR_CTL[MR_WR_BG1]=1, MR_MPR_CTL[MR_WR_SEL]=0x6, 
		     *          MR_MPR_CTL[MR_WR_USE_DEFAULT_VALUE]=0, 
		     *          MR_MPR_CTL[MR_WR_RANK] = x.
		     *          MR_MPR_CTL[MR_WR_ADDR<17>] = 1.  
		     *          MR_MPR_CTL[MR_WR_ADDR<16:14>] = 0. 
		     *          MR_MPR_CTL[MR_WR_ADDR<13>] = 1 
		     *          MR_MPR_CTL[MR_WR_ADDR<12>] = 0 (enable output buffer).
		     *          MR_MPR_CTL[MR_WR_ADDR<11>] = ~MODEREG_PARAMS0[TDQS].
		     *          MR_MPR_CTL[MR_WR_ADDR<10>] = MODEREG_PARAMS1[RTT_NOM_x<2>].
		     *          MR_MPR_CTL[MR_WR_ADDR<9>]   = ~MODEREG_PARAMS1[RTT_NOM_x<1>].
		     *          MR_MPR_CTL[MR_WR_ADDR<8>]   = ~MODEREG_PARAMS1[RTT_NOM_x<0>].
		     *          MR_MPR_CTL[MR_WR_ADDR<7>]   = 1. (Turn off Write Leveling mode).
		     *          MR_MPR_CTL[MR_WR_ADDR<6:5>] = 3  
		     *          MR_MPR_CTL[MR_WR_ADDR<4:3>] = 3 
		     *          MR_MPR_CTL[MR_WR_ADDR<2:1>] = MODEREG_PARAMS1[DIC_x<1:0>]. 
		     *          MR_MPR_CTL[MR_WR_ADDR<0>]   = MODEREG_PARAMS0[DLL].
		     *          
		     *          Where 'x' is the rank number (2'b00 - 2'b11).
		     */

		    ddr_print("37) Disable write-leveling on the B side. Re-enable output buffer on all ranks that were not \n");

		    mr_wr_addr  =  lmc_modereg_params0.s.dll; /* DLL Enable */
		    mr_wr_addr |=  ((lmc_modereg_params1.u >> (rankx*12+7)) & 3)  <<  1; /* DIC */
		    mr_wr_addr |=     3                                             <<  3; /* Additive Latency */
		    mr_wr_addr |=     3                                             <<  5; /* RFU */
		    mr_wr_addr |=     1                                             <<  7; /* Turn off Write Leveling mode */
		    mr_wr_addr |= (~(lmc_modereg_params1.u >> (rankx*12+9))  & 3) <<  8; /* RTT_NOM<0:1> */
		    mr_wr_addr |= ( (lmc_modereg_params1.u >> (rankx*12+11)) & 1) << 10; /* RTT_NOM<2> */
		    mr_wr_addr |=  lmc_modereg_params0.s.tdqs                       << 11; /* TDQS enable */
		    mr_wr_addr |=     0                                             << 12; /* enable output buffer */
		    mr_wr_addr |=     1                                             << 13; /* RFU */
		    mr_wr_addr |=     0                                             << 14;
		    mr_wr_addr |=     1                                             << 17; /* RFU */
		    ddr4_mrw(node, ddr_interface_num, rankx, mr_wr_addr, ~1, 1); /* MR1 B-side */

		    /* 
		     * 38) Repeat Step 34-37 for all ranks that needed to be write leveled.
		     */

		    ddr_print("38) Repeat Step 31-34 for all ranks that needed to be write leveled.\n");
		}
#endif
	    } /* for (rankx = 0; rankx < dimm_count * 4;rankx++) */
        } /* while(wlevel_loops--) */

#if RUN_INIT_SEQ_3
        if (run_init_sequence_3 && (ddr_type == DDR4_DRAM) && spd_rdimm) {

            /*
             * 39) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1.
             */

            ddr_print("39) Re-enable lmc's RDIMM mode. CONTROL[RDIMM_ENA] = 1.\n");

            set_rdimm_mode(node, ddr_interface_num, 1);
        }
#endif
        lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
        lmc_config.s.mode32b         = save_mode32b;
        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
        ddr_print("%-45s : %d\n", "MODE32B", lmc_config.s.mode32b);
    }

    // At the end of HW Write Leveling, check on some things...
    {
        deskew_counts_t dsk_counts;

	ddr_print("N%d.LMC%d: Check Deskew Settings before Read-Leveling.\n", node, ddr_interface_num);
        Validate_Deskew_Training(node, rank_mask, ddr_interface_num, &dsk_counts, 1);

	// at this point, we may still have some saturation - look for it
	// Only do this for the 2Rx4 stacked die DIMMs...
	if ((((spd_package & 0xf3) == 0x91) && (num_ranks == 2) && (dram_width == 4))) // 2Rx4 stacked die
	{
	    if (dsk_counts.saturated > 0) {
		ddr_print("N%d.LMC%d: Deskew Status indicates some saturation - retry Training.\n",
			  node, ddr_interface_num);
		perform_LMC_Deskew_Training(node, rank_mask, ddr_interface_num, spd_rawcard);
	    }
	}
    }

    /*
     * 4.8.10 LMC Read Leveling
     * 
     * LMC supports an automatic read-leveling separately per byte-lane using
     * the DDR3 multipurpose register predefined pattern for system
     * calibration defined in the JEDEC DDR3 specifications.
     * 
     * All of DDR PLL, LMC CK, and LMC DRESET, and early LMC initializations
     * must be completed prior to starting this LMC read-leveling sequence.
     * 
     * Software could simply write the desired read-leveling values into
     * LMC(0)_RLEVEL_RANK(0..3). This section describes a sequence that uses
     * LMC's autoread-leveling capabilities.
     * 
     * When LMC does the read-leveling sequence for a rank, it first enables
     * the DDR3 multipurpose register predefined pattern for system
     * calibration on the selected DRAM rank via a DDR3 MR3 write, then
     * executes 64 RD operations at different internal delay settings, then
     * disables the predefined pattern via another DDR3 MR3 write
     * operation. LMC determines the pass or fail of each of the 64 settings
     * independently for each byte lane, then writes appropriate
     * LMC(0)_RLEVEL_RANK(0..3)[BYTE*] values for the rank.
     * 
     * After read-leveling for a rank, software can read the 64 pass/fail
     * indications for one byte lane via LMC(0)_RLEVEL_DBG[BITMASK]. Software
     * can observe all pass/fail results for all byte lanes in a rank via
     * separate read-leveling sequences on the rank with different
     * LMC(0)_RLEVEL_CTL[BYTE] values.
     * 
     * The 64 pass/fail results will typically have failures for the low
     * delays, followed by a run of some passing settings, followed by more
     * failures in the remaining high delays.  LMC sets
     * LMC(0)_RLEVEL_RANK(0..3)[BYTE*] to one of the passing settings.
     * First, LMC selects the longest run of successes in the 64 results. (In
     * the unlikely event that there is more than one longest run, LMC
     * selects the first one.) Then if LMC(0)_RLEVEL_CTL[OFFSET_EN] = 1 and
     * the selected run has more than LMC(0)_RLEVEL_CTL[OFFSET] successes,
     * LMC selects the last passing setting in the run minus
     * LMC(0)_RLEVEL_CTL[OFFSET]. Otherwise LMC selects the middle setting in
     * the run (rounding earlier when necessary). We expect the read-leveling
     * sequence to produce good results with the reset values
     * LMC(0)_RLEVEL_CTL [OFFSET_EN]=1, LMC(0)_RLEVEL_CTL[OFFSET] = 2.
     * 
     * The read-leveling sequence has the following steps:
     * 
     * 1. Select desired LMC(0)_RLEVEL_CTL[OFFSET_EN,OFFSET,BYTE] settings.
     *    Do the remaining substeps 2-4 separately for each rank i with
     *    attached DRAM.
     * 
     * 2. Without changing any other fields in LMC(0)_CONFIG,
     * 
     *    o write LMC(0)_SEQ_CTL[SEQ_SEL] to select read-leveling
     * 
     *    o write LMC(0)_CONFIG[RANKMASK] = (1 << i)
     * 
     *    o write LMC(0)_SEQ_CTL[INIT_START] = 1
     * 
     *    This initiates the previously-described read-leveling.
     * 
     * 3. Wait until LMC(0)_RLEVEL_RANKi[STATUS] != 2
     * 
     *    LMC will have updated LMC(0)_RLEVEL_RANKi[BYTE*] for all byte lanes
     *    at this point.
     * 
     *    If ECC DRAM is not present (i.e. when DRAM is not attached to the
     *    DDR_CBS_0_* and DDR_CB<7:0> chip signals, or the DDR_DQS_<4>_* and
     *    DDR_DQ<35:32> chip signals), write LMC(0)_RLEVEL_RANK*[BYTE8] =
     *    LMC(0)_RLEVEL_RANK*[BYTE0]. Write LMC(0)_RLEVEL_RANK*[BYTE4] =
     *    LMC(0)_RLEVEL_RANK*[BYTE0].
     * 
     * 4. If desired, consult LMC(0)_RLEVEL_DBG[BITMASK] and compare to
     *    LMC(0)_RLEVEL_RANKi[BYTE*] for the lane selected by
     *    LMC(0)_RLEVEL_CTL[BYTE]. If desired, modify LMC(0)_RLEVEL_CTL[BYTE]
     *    to a new value and repeat so that all BITMASKs can be observed.
     * 
     * 5. Initialize LMC(0)_RLEVEL_RANK* values for all unused ranks.
     * 
     *    Let rank i be a rank with attached DRAM.
     * 
     *    For all ranks j that do not have attached DRAM, set
     *    LMC(0)_RLEVEL_RANKj = LMC(0)_RLEVEL_RANKi.
     * 
     * This read-leveling sequence can help select the proper CN70XX ODT
     * resistance value (LMC(0)_COMP_CTL2[RODT_CTL]). A hardware-generated
     * LMC(0)_RLEVEL_RANKi[BYTEj] value (for a used byte lane j) that is
     * drastically different from a neighboring LMC(0)_RLEVEL_RANKi[BYTEk]
     * (for a used byte lane k) can indicate that the CN70XX ODT value is
     * bad. It is possible to simultaneously optimize both
     * LMC(0)_COMP_CTL2[RODT_CTL] and LMC(0)_RLEVEL_RANKn[BYTE*] values by
     * performing this read-leveling sequence for several
     * LMC(0)_COMP_CTL2[RODT_CTL] values and selecting the one with the best
     * LMC(0)_RLEVEL_RANKn[BYTE*] profile for the ranks.
     */

    {
#pragma pack(push,4)
        bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank;
        bdk_lmcx_config_t lmc_config;
        bdk_lmcx_comp_ctl2_t lmc_comp_ctl2;
        bdk_lmcx_rlevel_ctl_t rlevel_ctl;
        bdk_lmcx_control_t lmc_control;
        bdk_lmcx_modereg_params1_t lmc_modereg_params1;
        unsigned char rodt_ctl;
        unsigned char rankx = 0;
        int rlevel_rodt_errors = 0;
        unsigned char ecc_ena;
        unsigned char rtt_nom;
        unsigned char rtt_idx;
        int min_rtt_nom_idx;
        int max_rtt_nom_idx;
        int min_rodt_ctl;
        int max_rodt_ctl;
        int rlevel_debug_loops = 1;
        int default_rodt_ctl;
        unsigned char save_ddr2t;
        int rlevel_avg_loops;
        int ddr_rlevel_compute;
        int saved_ddr__ptune, saved_ddr__ntune, rlevel_comp_offset;
        int saved_int_zqcs_dis = 0;
        int disable_sequential_delay_check = 0;
        int maximum_adjacent_rlevel_delay_increment = 0;
        struct {
            uint64_t setting;
            int      score;
        } rlevel_scoreboard[RTT_NOM_OHMS_COUNT][RODT_OHMS_COUNT][4];
#pragma pack(pop)

        default_rodt_ctl = odt_config[odt_idx].qs_dic;

        lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
        save_ddr2t                    = lmc_control.s.ddr2t;

        lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
        ecc_ena = lmc_config.s.ecc_ena;

#if 0
        {
            int save_ref_zqcs_int;
            uint64_t temp_delay_usecs;

            /* Temporarily select the minimum ZQCS interval and wait
               long enough for a few ZQCS calibrations to occur.  This
               should ensure that the calibration circuitry is
               stabilized before read-leveling occurs. */
            save_ref_zqcs_int         = lmc_config.s.ref_zqcs_int;
            lmc_config.s.ref_zqcs_int = 1 | (32<<7); /* set smallest interval */
            DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
            BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));

            /* Compute an appropriate delay based on the current ZQCS
               interval. The delay should be long enough for the
               current ZQCS delay counter to expire plus ten of the
               minimum intarvals to ensure that some calibrations
               occur. */
            temp_delay_usecs = (((uint64_t)save_ref_zqcs_int >> 7)
                                * tclk_psecs * 100 * 512 * 128) / (10000*10000)
                + 10 * ((uint64_t)32 * tclk_psecs * 100 * 512 * 128) / (10000*10000);

            ddr_print ("Waiting %lu usecs for ZQCS calibrations to start\n",
                         temp_delay_usecs);
            bdk_wait_usec(temp_delay_usecs);

            lmc_config.s.ref_zqcs_int = save_ref_zqcs_int; /* Restore computed interval */
            DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);
            BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
        }
#endif

        if ((s = lookup_env_parameter("ddr_rlevel_2t")) != NULL) {
            lmc_control.s.ddr2t = strtoul(s, NULL, 0);
        }

        DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

        ddr_print("N%d.LMC%d: Performing Read-Leveling\n", node, ddr_interface_num);

        rlevel_ctl.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_CTL(ddr_interface_num));

        rlevel_avg_loops = custom_lmc_config->rlevel_average_loops;
        if (rlevel_avg_loops == 0) rlevel_avg_loops = RLEVEL_AVG_LOOPS_DEFAULT;

        ddr_rlevel_compute = custom_lmc_config->rlevel_compute;
        rlevel_ctl.s.offset_en = custom_lmc_config->offset_en;
        rlevel_ctl.s.offset    = spd_rdimm
            ? custom_lmc_config->offset_rdimm
            : custom_lmc_config->offset_udimm;

        rlevel_ctl.s.delay_unload_0 = 1; /* should normally be set */
        rlevel_ctl.s.delay_unload_1 = 1; /* should normally be set */
        rlevel_ctl.s.delay_unload_2 = 1; /* should normally be set */
        rlevel_ctl.s.delay_unload_3 = 1; /* should normally be set */

        {
            int byte_bitmask = 0xff;

            /* If we will be switching to 32bit mode level based on only
               four bits because there are only 4 ECC bits. */
            if (! ddr_interface_64b)
                byte_bitmask = 0x0f;

	    rlevel_ctl.s.or_dis = 1;
            rlevel_ctl.s.bitmask  = byte_bitmask;
        }

        ddr_rodt_ctl_auto = custom_lmc_config->ddr_rodt_ctl_auto;

        rlevel_comp_offset = spd_rdimm
            ? custom_lmc_config->rlevel_comp_offset_rdimm
            : custom_lmc_config->rlevel_comp_offset_udimm;

        if ((s = lookup_env_parameter("ddr_rlevel_offset")) != NULL) {
            rlevel_ctl.s.offset   = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rlevel_offset_en")) != NULL) {
            rlevel_ctl.s.offset_en   = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_rlevel_ctl")) != NULL) {
            rlevel_ctl.u   = strtoul(s, NULL, 0);
        }

        DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_CTL(ddr_interface_num), rlevel_ctl.u);

        if (bdk_is_platform(BDK_PLATFORM_ASIM))
            rlevel_debug_loops = 0;

        if ((s = lookup_env_parameter("ddr%d_rlevel_debug_loops", ddr_interface_num)) != NULL) {
            rlevel_debug_loops = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rtt_nom_auto")) != NULL) {
            ddr_rtt_nom_auto = !!strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rodt_ctl")) == NULL)
            s = lookup_env_parameter("ddr%d_rodt_ctl", ddr_interface_num);
        if (s != NULL) {
            default_rodt_ctl    = strtoul(s, NULL, 0);
            ddr_rodt_ctl_auto = 0;
        }

        if ((s = lookup_env_parameter("ddr_rodt_ctl_auto")) != NULL) {
            ddr_rodt_ctl_auto = !!strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rlevel_average")) != NULL) {
            rlevel_avg_loops = strtoul(s, NULL, 0);
        }

        if ((s = lookup_env_parameter("ddr_rlevel_compute")) != NULL) {
            ddr_rlevel_compute = strtoul(s, NULL, 0);
        }

        ddr_print("RLEVEL_CTL                                    : 0x%016lx\n", rlevel_ctl.u);
        ddr_print("RLEVEL_OFFSET                                 : %6d\n", rlevel_ctl.s.offset);
        ddr_print("RLEVEL_OFFSET_EN                              : %6d\n", rlevel_ctl.s.offset_en);

        /* The purpose for the indexed table is to sort the settings
        ** by the ohm value to simplify the testing when incrementing
        ** through the settings.  (index => ohms) 1=120, 2=60, 3=40,
        ** 4=30, 5=20 */
        min_rtt_nom_idx = (custom_lmc_config->min_rtt_nom_idx == 0) ? 1 : custom_lmc_config->min_rtt_nom_idx;
        max_rtt_nom_idx = (custom_lmc_config->max_rtt_nom_idx == 0) ? 5 : custom_lmc_config->max_rtt_nom_idx;

        min_rodt_ctl = (custom_lmc_config->min_rodt_ctl == 0) ? 1 : custom_lmc_config->min_rodt_ctl;
        max_rodt_ctl = (custom_lmc_config->max_rodt_ctl == 0) ? 5 : custom_lmc_config->max_rodt_ctl;

        if ((s = lookup_env_parameter("ddr_min_rodt_ctl")) != NULL) {
            min_rodt_ctl = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_max_rodt_ctl")) != NULL) {
            max_rodt_ctl = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_min_rtt_nom_idx")) != NULL) {
            min_rtt_nom_idx = strtoul(s, NULL, 0);
        }
        if ((s = lookup_env_parameter("ddr_max_rtt_nom_idx")) != NULL) {
            max_rtt_nom_idx = strtoul(s, NULL, 0);
        }

#ifdef ENABLE_CUSTOM_RLEVEL_TABLE
        if (custom_lmc_config->rlevel_table != NULL) {
	    char part_number[21];
            /* Check for hard-coded read-leveling settings */
            get_dimm_part_number(part_number, node, &dimm_config_table[0], 0, ddr_type);
            for (rankx = 0; rankx < dimm_count * 4;rankx++) {
                if (!(rank_mask & (1 << rankx)))
                    continue;

                lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

                i = 0;
                while (custom_lmc_config->rlevel_table[i].part != NULL) {
                    debug_print("DIMM part number:\"%s\", SPD: \"%s\"\n", custom_lmc_config->rlevel_table[i].part, part_number);
                    if ((strcmp(part_number, custom_lmc_config->rlevel_table[i].part) == 0) 
                        && (_abs(custom_lmc_config->rlevel_table[i].speed - 2*ddr_hertz/(1000*1000)) < 10 ))
		    {
                        ddr_print("Using hard-coded read leveling for DIMM part number: \"%s\"\n", part_number);
                        lmc_rlevel_rank.u = custom_lmc_config->rlevel_table[i].rlevel_rank[ddr_interface_num][rankx];
                        DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), lmc_rlevel_rank.u);
                        lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));
                        display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rankx);
                        rlevel_debug_loops = 0; /* Disable h/w read-leveling */
                        break;
                    }
                    ++i;
                }
            }
        }
#endif /* ENABLE_CUSTOM_RLEVEL_TABLE */

        while(rlevel_debug_loops--) {
	    /* Initialize the error scoreboard */
	    for (rtt_idx = 1; rtt_idx < RTT_NOM_OHMS_COUNT; ++rtt_idx) {
		rtt_nom = imp_values->rtt_nom_table[rtt_idx];
		for (rodt_ctl = RODT_OHMS_COUNT - 1; rodt_ctl > 0; --rodt_ctl) {
		    for (rankx = 0; rankx < dimm_count * 4; rankx++) {
			if (!(rank_mask & (1 << rankx)))
			    continue;
			rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score   = 0;
			rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].setting = 0;
		    }
		}
	    }

	    if ((s = lookup_env_parameter("ddr_rlevel_comp_offset")) != NULL) {
		rlevel_comp_offset = strtoul(s, NULL, 0);
	    }

	    disable_sequential_delay_check = custom_lmc_config->disable_sequential_delay_check;

	    if ((s = lookup_env_parameter("ddr_disable_sequential_delay_check")) != NULL) {
		disable_sequential_delay_check = strtoul(s, NULL, 0);
	    }

	    maximum_adjacent_rlevel_delay_increment = custom_lmc_config->maximum_adjacent_rlevel_delay_increment;

	    if ((s = lookup_env_parameter("ddr_maximum_adjacent_rlevel_delay_increment")) != NULL) {
		maximum_adjacent_rlevel_delay_increment = strtoul(s, NULL, 0);
	    }

	    lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
	    saved_ddr__ptune = lmc_comp_ctl2.s.ddr__ptune;
	    saved_ddr__ntune = lmc_comp_ctl2.s.ddr__ntune;

	    /* Disable dynamic compensation settings */
	    if (rlevel_comp_offset != 0) {
		lmc_comp_ctl2.s.ptune = saved_ddr__ptune;
		lmc_comp_ctl2.s.ntune = saved_ddr__ntune;

		/* Round up the ptune calculation to bias the odd cases toward ptune */
		lmc_comp_ctl2.s.ptune += divide_roundup(rlevel_comp_offset, 2);
		lmc_comp_ctl2.s.ntune -= rlevel_comp_offset/2;

		lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
		saved_int_zqcs_dis = lmc_control.s.int_zqcs_dis;
		lmc_control.s.int_zqcs_dis    = 1; /* Disable ZQCS while in bypass. */
		DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

		lmc_comp_ctl2.s.byp = 1; /* Enable bypass mode */
		DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), lmc_comp_ctl2.u);
		BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
		lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num)); /* Read again */
		ddr_print("DDR__PTUNE/DDR__NTUNE                         : %d/%d\n",
			  lmc_comp_ctl2.s.ddr__ptune, lmc_comp_ctl2.s.ddr__ntune);
	    }

	    lmc_modereg_params1.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num));

	    for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) {
		rtt_nom = imp_values->rtt_nom_table[rtt_idx];

		/* When the read ODT mask is zero the dyn_rtt_nom_mask is
		   zero than RTT_NOM will not be changing during
		   read-leveling.  Since the value is fixed we only need
		   to test it once. */
		if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
		    continue;

		if (dyn_rtt_nom_mask & 1) lmc_modereg_params1.s.rtt_nom_00 = rtt_nom;
		if (dyn_rtt_nom_mask & 2) lmc_modereg_params1.s.rtt_nom_01 = rtt_nom;
		if (dyn_rtt_nom_mask & 4) lmc_modereg_params1.s.rtt_nom_10 = rtt_nom;
		if (dyn_rtt_nom_mask & 8) lmc_modereg_params1.s.rtt_nom_11 = rtt_nom;

		DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num), lmc_modereg_params1.u);
		ddr_print("\n");
		ddr_print("RTT_NOM     %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_11],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_10],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_01],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_00],
			  lmc_modereg_params1.s.rtt_nom_11,
			  lmc_modereg_params1.s.rtt_nom_10,
			  lmc_modereg_params1.s.rtt_nom_01,
			  lmc_modereg_params1.s.rtt_nom_00);

		perform_ddr3_init_sequence(node, rank_mask, ddr_interface_num);

		for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) {
		    rlevel_rodt_errors = 0;
		    lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
		    lmc_comp_ctl2.s.rodt_ctl = rodt_ctl;
		    DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), lmc_comp_ctl2.u);
		    lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
		    bdk_wait_usec(1); /* Give it a little time to take affect */
		    ddr_print("Read ODT_CTL                                  : 0x%x (%d ohms)\n",
			      lmc_comp_ctl2.s.rodt_ctl, imp_values->rodt_ohms[lmc_comp_ctl2.s.rodt_ctl]);

		    for (rankx = 0; rankx < dimm_count * 4; rankx++) {
			int byte_idx;
#if RLEVEL_AVG_LOOPS_DEBUG
			rlevel_byte_data_t rlevel_byte[9] = {{0, 0, 0, 0, 0}};
#else
			rlevel_byte_data_t rlevel_byte[9] = {{0, 0, 0}};
#endif
			int average_loops;
			int rlevel_rank_errors;

			if (!(rank_mask & (1 << rankx)))
			    continue;

			for (average_loops = 0; average_loops < rlevel_avg_loops; average_loops++) {
			    rlevel_rank_errors = 0;

			    if (! (rlevel_separate_ab && spd_rdimm && (ddr_type == DDR4_DRAM))) {
				/* Clear read-level delays */
				DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), 0);

				perform_octeon3_ddr3_sequence(node, 1 << rankx, ddr_interface_num, 1); /* read-leveling */

				if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
				    BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx),
							   status, ==, 3, 1000000))
				    {
					error_print("ERROR: Timeout waiting for RLEVEL\n");
				    }
			    }

			    lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

			    {
				struct {
				    uint64_t bm;
				    uint8_t mstart;
				    uint8_t width;
				} rlevel_bitmask[9]={{0, 0, 0}};

				if (rlevel_separate_ab && spd_rdimm && (ddr_type == DDR4_DRAM)) {
				    bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank_aside;
				    bdk_lmcx_modereg_params0_t lmc_modereg_params0;

				    /* A-side */
				    lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));
				    lmc_modereg_params0.s.mprloc = 0; /* MPR Page 0 Location 0 */
				    DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);

				    /* Clear read-level delays */
				    DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), 0);

				    perform_octeon3_ddr3_sequence(node, 1 << rankx, ddr_interface_num, 1); /* read-leveling */

				    if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
					BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx),
							       status, ==, 3, 1000000))
					{
					    error_print("ERROR: Timeout waiting for RLEVEL\n");

					}
				    lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

				    lmc_rlevel_rank_aside.u = lmc_rlevel_rank.u;

				    rlevel_bitmask[0].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 0);
				    rlevel_bitmask[1].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 1);
				    rlevel_bitmask[2].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 2);
				    rlevel_bitmask[3].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 3);
				    rlevel_bitmask[8].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 8);
				    /* A-side complete */


				    /* B-side */
				    lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));
				    lmc_modereg_params0.s.mprloc = 3; /* MPR Page 0 Location 3 */
				    DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);

				    /* Clear read-level delays */
				    DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), 0);

				    perform_octeon3_ddr3_sequence(node, 1 << rankx, ddr_interface_num, 1); /* read-leveling */

				    if (!bdk_is_platform(BDK_PLATFORM_ASIM) &&
					BDK_CSR_WAIT_FOR_FIELD(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx),
							       status, ==, 3, 1000000))
					{
					    error_print("ERROR: Timeout waiting for RLEVEL\n");
					}
				    lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

				    rlevel_bitmask[4].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 4);
				    rlevel_bitmask[5].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 5);
				    rlevel_bitmask[6].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 6);
				    rlevel_bitmask[7].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, 7);
				    /* B-side complete */

                        
				    update_rlevel_rank_struct(&lmc_rlevel_rank, 0, lmc_rlevel_rank_aside.s.byte0);
				    update_rlevel_rank_struct(&lmc_rlevel_rank, 1, lmc_rlevel_rank_aside.s.byte1);
				    update_rlevel_rank_struct(&lmc_rlevel_rank, 2, lmc_rlevel_rank_aside.s.byte2);
				    update_rlevel_rank_struct(&lmc_rlevel_rank, 3, lmc_rlevel_rank_aside.s.byte3);
				    update_rlevel_rank_struct(&lmc_rlevel_rank, 8, lmc_rlevel_rank_aside.s.byte8); /* ECC A-side */

				    lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));
				    lmc_modereg_params0.s.mprloc = 0; /* MPR Page 0 Location 0 */
				    DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);
				} /* if (rlevel_separate_ab && spd_rdimm && (ddr_type == DDR4_DRAM)) */

				/* Evaluate the quality of the read-leveling
				   delays. Also save off a software computed
				   read-leveling mask that may be used later
				   to qualify the delay results from Octeon. */
				for (byte_idx = 0; byte_idx < (8+ecc_ena); ++byte_idx) {
				    if (!(ddr_interface_bytemask&(1<<byte_idx)))
					continue;
				    if (! (rlevel_separate_ab && spd_rdimm && (ddr_type == DDR4_DRAM))) {
					rlevel_bitmask[byte_idx].bm = octeon_read_lmcx_ddr3_rlevel_dbg(node, ddr_interface_num, byte_idx);
				    }
				    rlevel_rank_errors += validate_ddr3_rlevel_bitmask(rlevel_bitmask[byte_idx].bm,
										       &rlevel_bitmask[byte_idx].mstart,
										       &rlevel_bitmask[byte_idx].width);
				}

				/* Set delays for unused bytes to match byte 0. */
				for (byte_idx = 0; byte_idx < 9; ++byte_idx) {
				    if (ddr_interface_bytemask & (1 << byte_idx))
					continue;
				    update_rlevel_rank_struct(&lmc_rlevel_rank, byte_idx, lmc_rlevel_rank.s.byte0);
				}

				/* Save a copy of the byte delays in physical
				   order for sequential evaluation. */
				if ((ddr_interface_bytemask & 0xff) == 0xff) {
				    if (ecc_ena) {
					rlevel_byte[8].delay = lmc_rlevel_rank.s.byte7;
					rlevel_byte[7].delay = lmc_rlevel_rank.s.byte6;
					rlevel_byte[6].delay = lmc_rlevel_rank.s.byte5;
					rlevel_byte[5].delay = lmc_rlevel_rank.s.byte4;
					rlevel_byte[4].delay = lmc_rlevel_rank.s.byte8; /* ECC */
				    } else {
					rlevel_byte[7].delay = lmc_rlevel_rank.s.byte7;
					rlevel_byte[6].delay = lmc_rlevel_rank.s.byte6;
					rlevel_byte[5].delay = lmc_rlevel_rank.s.byte5;
					rlevel_byte[4].delay = lmc_rlevel_rank.s.byte4;
				    }
				} else {
				    rlevel_byte[8].delay = lmc_rlevel_rank.s.byte8; /* unused */
				    rlevel_byte[7].delay = lmc_rlevel_rank.s.byte7; /* unused */
				    rlevel_byte[6].delay = lmc_rlevel_rank.s.byte6; /* unused */
				    rlevel_byte[5].delay = lmc_rlevel_rank.s.byte5; /* unused */
				    rlevel_byte[4].delay = lmc_rlevel_rank.s.byte4; /* ECC */
				}
				rlevel_byte[3].delay = lmc_rlevel_rank.s.byte3;
				rlevel_byte[2].delay = lmc_rlevel_rank.s.byte2;
				rlevel_byte[1].delay = lmc_rlevel_rank.s.byte1;
				rlevel_byte[0].delay = lmc_rlevel_rank.s.byte0;

				if (! disable_sequential_delay_check) {
				    if ((ddr_interface_bytemask & 0xff) == 0xff) {
					/* Evaluate delay sequence across the whole range of bytes for stantard dimms. */
					if ((spd_dimm_type == 1) || (spd_dimm_type == 5)) { /* 1=RDIMM, 5=Mini-RDIMM */
					    int register_adjacent_delay = _abs(rlevel_byte[4].delay - rlevel_byte[5].delay);
					    /* Registered dimm topology routes from the center. */
					    rlevel_rank_errors += nonsequential_delays(rlevel_byte, 0, 3+ecc_ena, maximum_adjacent_rlevel_delay_increment);
					    rlevel_rank_errors += nonsequential_delays(rlevel_byte, 5, 7+ecc_ena, maximum_adjacent_rlevel_delay_increment);
					    if (register_adjacent_delay > 1) {
						/* Assess proximity of bytes on opposite sides of register */
						rlevel_rank_errors += (register_adjacent_delay-1) * RLEVEL_ADJACENT_DELAY_ERROR;
					    }
					}
					if ((spd_dimm_type == 2) || (spd_dimm_type == 6)) { /* 1=UDIMM, 5=Mini-UDIMM */
					    /* Unbuffered dimm topology routes from end to end. */
					    rlevel_rank_errors += nonsequential_delays(rlevel_byte, 0, 7+ecc_ena, maximum_adjacent_rlevel_delay_increment);
					}
				    } else {
					rlevel_rank_errors += nonsequential_delays(rlevel_byte, 0, 3+ecc_ena, maximum_adjacent_rlevel_delay_increment);
				    }
				}

				ddr_print("N%d.LMC%d.R%d: Rlevel Debug Test Results  8:0        : %05lx %05lx %05lx %05lx %05lx %05lx %05lx %05lx %05lx\n",
					  node, ddr_interface_num, rankx,
					  rlevel_bitmask[8].bm,
					  rlevel_bitmask[7].bm,
					  rlevel_bitmask[6].bm,
					  rlevel_bitmask[5].bm,
					  rlevel_bitmask[4].bm,
					  rlevel_bitmask[3].bm,
					  rlevel_bitmask[2].bm,
					  rlevel_bitmask[1].bm,
					  rlevel_bitmask[0].bm
					  );

				display_read_leveling_settings_with_score(node, ddr_interface_num, lmc_rlevel_rank, rankx, rlevel_rank_errors);

				if (ddr_rlevel_compute) {
				    /* Recompute the delays based on the bitmask */
				    for (byte_idx = 0; byte_idx < (8+ecc_ena); ++byte_idx) {
					if (!(ddr_interface_bytemask & (1 << byte_idx)))
					    continue;
					update_rlevel_rank_struct(&lmc_rlevel_rank, byte_idx,
								  compute_ddr3_rlevel_delay(rlevel_bitmask[byte_idx].mstart,
											    rlevel_bitmask[byte_idx].width,
											    rlevel_ctl));
				    }

				    /* Override the copy of byte delays with the computed results. */
				    if ((ddr_interface_bytemask & 0xff) == 0xff) {
					if (ecc_ena) {
					    rlevel_byte[8].delay = lmc_rlevel_rank.s.byte7;
					    rlevel_byte[7].delay = lmc_rlevel_rank.s.byte6;
					    rlevel_byte[6].delay = lmc_rlevel_rank.s.byte5;
					    rlevel_byte[5].delay = lmc_rlevel_rank.s.byte4;
					    rlevel_byte[4].delay = lmc_rlevel_rank.s.byte8; /* ECC */
					} else {
					    rlevel_byte[7].delay = lmc_rlevel_rank.s.byte7;
					    rlevel_byte[6].delay = lmc_rlevel_rank.s.byte6;
					    rlevel_byte[5].delay = lmc_rlevel_rank.s.byte5;
					    rlevel_byte[4].delay = lmc_rlevel_rank.s.byte4;
					}
				    } else {
					rlevel_byte[4].delay = lmc_rlevel_rank.s.byte8; /* unused */
					rlevel_byte[7].delay = lmc_rlevel_rank.s.byte7; /* unused */
					rlevel_byte[6].delay = lmc_rlevel_rank.s.byte6; /* unused */
					rlevel_byte[5].delay = lmc_rlevel_rank.s.byte5; /* unused */
					rlevel_byte[4].delay = lmc_rlevel_rank.s.byte4; /* ECC */
				    }
				    rlevel_byte[3].delay = lmc_rlevel_rank.s.byte3;
				    rlevel_byte[2].delay = lmc_rlevel_rank.s.byte2;
				    rlevel_byte[1].delay = lmc_rlevel_rank.s.byte1;
				    rlevel_byte[0].delay = lmc_rlevel_rank.s.byte0;

				    ddr_print("N%d.LMC%d.R%d: Computed delays                       : %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
					      node, ddr_interface_num, rankx,
					      lmc_rlevel_rank.s.byte8,
					      lmc_rlevel_rank.s.byte7,
					      lmc_rlevel_rank.s.byte6,
					      lmc_rlevel_rank.s.byte5,
					      lmc_rlevel_rank.s.byte4,
					      lmc_rlevel_rank.s.byte3,
					      lmc_rlevel_rank.s.byte2,
					      lmc_rlevel_rank.s.byte1,
					      lmc_rlevel_rank.s.byte0
					      );
				} /* if (ddr_rlevel_compute) */
			    }

			    /* Accumulate the total score across averaging loops for this setting */
			    rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score += rlevel_rank_errors;
			    debug_print("rlevel_scoreboard[rtt_nom=%d][rodt_ctl=%d][rankx=%d].score:%d\n",
					rtt_nom, rodt_ctl, rankx,
					rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score);

			    /* Accumulate the delay totals and loop counts
			       necessary to compute average delay results */
			    for (byte_idx = 0; byte_idx < 9; ++byte_idx) {
				if (rlevel_byte[byte_idx].delay != 0) { /* Don't include delay=0 in the average */
				    ++rlevel_byte[byte_idx].loop_count;
				    rlevel_byte[byte_idx].loop_total += rlevel_byte[byte_idx].delay;
#if RLEVEL_AVG_LOOPS_DEBUG
				    if (average_loops > 0) {
					// incr diffs if delay != last
					rlevel_byte[byte_idx].diffs += (rlevel_byte[byte_idx].delay != rlevel_byte[byte_idx].last) ? 1 : 0;
				    } else {
					// zero diffs on first loop
					rlevel_byte[byte_idx].diffs = 0;
				    }
				    // always copy delays to lasts
				    rlevel_byte[byte_idx].last = rlevel_byte[byte_idx].delay;
#endif
				}
			    }

			    rlevel_rodt_errors += rlevel_rank_errors;
			} /* for (average_loops = 0; average_loops < rlevel_avg_loops; average_loops++) */

			/* Compute the average score across averaging loops */
			rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score =
			    divide_nint(rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score, rlevel_avg_loops);

			/* Compute the average delay results */
			for (byte_idx=0; byte_idx < 9; ++byte_idx) {
			    if (rlevel_byte[byte_idx].loop_count == 0)
				rlevel_byte[byte_idx].loop_count = 1;
			    rlevel_byte[byte_idx].delay = divide_nint(rlevel_byte[byte_idx].loop_total,
								      rlevel_byte[byte_idx].loop_count);
			}

			lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

			if ((ddr_interface_bytemask & 0xff) == 0xff) {
			    if (ecc_ena) {
				lmc_rlevel_rank.s.byte7 = rlevel_byte[8].delay;
				lmc_rlevel_rank.s.byte6 = rlevel_byte[7].delay;
				lmc_rlevel_rank.s.byte5 = rlevel_byte[6].delay;
				lmc_rlevel_rank.s.byte4 = rlevel_byte[5].delay;
				lmc_rlevel_rank.s.byte8 = rlevel_byte[4].delay; /* ECC */
			    } else {
				lmc_rlevel_rank.s.byte7 = rlevel_byte[7].delay;
				lmc_rlevel_rank.s.byte6 = rlevel_byte[6].delay;
				lmc_rlevel_rank.s.byte5 = rlevel_byte[5].delay;
				lmc_rlevel_rank.s.byte4 = rlevel_byte[4].delay;
			    }
			} else {
			    lmc_rlevel_rank.s.byte8 = rlevel_byte[8].delay;
			    lmc_rlevel_rank.s.byte7 = rlevel_byte[7].delay;
			    lmc_rlevel_rank.s.byte6 = rlevel_byte[6].delay;
			    lmc_rlevel_rank.s.byte5 = rlevel_byte[5].delay;
			    lmc_rlevel_rank.s.byte4 = rlevel_byte[4].delay;
			}
			lmc_rlevel_rank.s.byte3 = rlevel_byte[3].delay;
			lmc_rlevel_rank.s.byte2 = rlevel_byte[2].delay;
			lmc_rlevel_rank.s.byte1 = rlevel_byte[1].delay;
			lmc_rlevel_rank.s.byte0 = rlevel_byte[0].delay;

			if (rlevel_avg_loops > 1) {

			    display_read_leveling_settings_with_average(node, ddr_interface_num, lmc_rlevel_rank, rankx,
									rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score);
#if RLEVEL_AVG_LOOPS_DEBUG
			    /* Display the average delay loop debug info */
			    if (((ddr_interface_bytemask & 0xff) == 0xff) && ecc_ena) {
				ddr_print("N%d.LMC%d.R%d: Average of %d, delay diffs             : %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
					  node, ddr_interface_num, rankx, rlevel_avg_loops,
					  rlevel_byte[4].diffs,
					  rlevel_byte[8].diffs,
					  rlevel_byte[7].diffs,
					  rlevel_byte[6].diffs,
					  rlevel_byte[5].diffs,
					  rlevel_byte[3].diffs,
					  rlevel_byte[2].diffs,
					  rlevel_byte[1].diffs,
					  rlevel_byte[0].diffs
					  );
			    } else {
				ddr_print("N%d.LMC%d.R%d: Average of %d, delay diffs             : %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
					  node, ddr_interface_num, rankx, rlevel_avg_loops,
					  rlevel_byte[8].diffs,
					  rlevel_byte[7].diffs,
					  rlevel_byte[6].diffs,
					  rlevel_byte[5].diffs,
					  rlevel_byte[4].diffs,
					  rlevel_byte[3].diffs,
					  rlevel_byte[2].diffs,
					  rlevel_byte[1].diffs,
					  rlevel_byte[0].diffs
					  );
			    }
#endif
			}

			rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].setting = lmc_rlevel_rank.u;
		    } /* for (rankx = 0; rankx < dimm_count*4; rankx++) */
		} /* for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) */
	    } /*  for (rtt_idx=min_rtt_nom_idx; rtt_idx<max_rtt_nom_idx; ++rtt_idx) */


	    /* Re-enable dynamic compensation settings. */
	    if (rlevel_comp_offset != 0) {
		lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));

		lmc_comp_ctl2.s.ptune = 0;
		lmc_comp_ctl2.s.ntune = 0;
		lmc_comp_ctl2.s.byp = 0; /* Disable bypass mode */
		DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), lmc_comp_ctl2.u);
		BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num)); /* Read once */

		lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num)); /* Read again */
		ddr_print("DDR__PTUNE/DDR__NTUNE                         : %d/%d\n",
			  lmc_comp_ctl2.s.ddr__ptune, lmc_comp_ctl2.s.ddr__ntune);

		lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
		lmc_control.s.int_zqcs_dis    = saved_int_zqcs_dis; /* Restore original setting */
		DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

	    }


	    {
		int override_compensation = 0;
		if ((s = lookup_env_parameter("ddr__ptune")) != NULL) {
		    saved_ddr__ptune = strtoul(s, NULL, 0);
		    override_compensation = 1;
		}
		if ((s = lookup_env_parameter("ddr__ntune")) != NULL) {
		    saved_ddr__ntune = strtoul(s, NULL, 0);
		    override_compensation = 1;
		}
		if (override_compensation) {
		    lmc_comp_ctl2.s.ptune = saved_ddr__ptune;
		    lmc_comp_ctl2.s.ntune = saved_ddr__ntune;

		    lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
		    saved_int_zqcs_dis = lmc_control.s.int_zqcs_dis;
		    lmc_control.s.int_zqcs_dis    = 1; /* Disable ZQCS while in bypass. */
		    DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

		    lmc_comp_ctl2.s.byp = 1; /* Enable bypass mode */
		    DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), lmc_comp_ctl2.u);
		    lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num)); /* Read again */

		    ddr_print("DDR__PTUNE/DDR__NTUNE                         : %d/%d\n",
			      lmc_comp_ctl2.s.ptune, lmc_comp_ctl2.s.ntune);
		}
	    }
	    { /* Evaluation block */
		int      best_rodt_score = DEFAULT_BEST_RANK_SCORE; /* Start with an arbitrarily high score */
		int      auto_rodt_ctl = 0;
		int      auto_rtt_nom  = 0;
		int      rodt_score;
		int      rodt_row_skip_mask = 0;

		// just add specific RODT rows to the skip mask for DDR4 at this time...
		if (ddr_type == DDR4_DRAM) {
		    rodt_row_skip_mask |= (1 << ddr4_rodt_ctl_34_ohm); // skip RODT row 34 ohms for all DDR4 types
		    rodt_row_skip_mask |= (1 << ddr4_rodt_ctl_40_ohm); // skip RODT row 40 ohms for all DDR4 types
#if ADD_48_OHM_SKIP
		    rodt_row_skip_mask |= (1 << ddr4_rodt_ctl_48_ohm); // skip RODT row 48 ohms for all DDR4 types
#endif /* ADD_48OHM_SKIP */
#if NOSKIP_40_48_OHM
		    // For now, do not skip RODT row 40 or 48 ohm when ddr_hertz is above 1075 MHz
		    if (ddr_hertz > 1075000000) {
			rodt_row_skip_mask &= ~(1 << ddr4_rodt_ctl_40_ohm); // noskip RODT row 40 ohms
			rodt_row_skip_mask &= ~(1 << ddr4_rodt_ctl_48_ohm); // noskip RODT row 48 ohms
		    }
#endif /* NOSKIP_40_48_OHM */
#if 0 // FIXME: should this be removed for good?
		    // For now, add in skip of RODT row 48 ohm when ddr_hertz is at or above 1000 MHz,
		    // but only for the 2Rx4 stacked die DIMMs
		    if ((((spd_package & 0xf3) == 0x91) && (num_ranks == 2) && (dram_width == 4)) // 2Rx4 stacked die
			&& (ddr_hertz >= 1000000000))
			{
			    rodt_row_skip_mask |= (1 << ddr4_rodt_ctl_48_ohm); // skip RODT row 48 ohms
			}
#endif
		}

		ddr_print("Evaluating Read-Leveling Scoreboard for AUTO settings.\n");
		for (rtt_idx=min_rtt_nom_idx; rtt_idx<=max_rtt_nom_idx; ++rtt_idx) {
		    rtt_nom = imp_values->rtt_nom_table[rtt_idx];

		    /* When the read ODT mask is zero the dyn_rtt_nom_mask is
		       zero than RTT_NOM will not be changing during
		       read-leveling.  Since the value is fixed we only need
		       to test it once. */
		    if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
			continue;

		    for (rodt_ctl=max_rodt_ctl; rodt_ctl>=min_rodt_ctl; --rodt_ctl) {
			rodt_score = 0;
			for (rankx = 0; rankx < dimm_count * 4;rankx++) {
			    if (!(rank_mask & (1 << rankx)))
				continue;
			    debug_print("rlevel_scoreboard[rtt_nom=%d][rodt_ctl=%d][rankx=%d].score:%d\n",
					rtt_nom, rodt_ctl, rankx, rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score);
			    rodt_score += rlevel_scoreboard[rtt_nom][rodt_ctl][rankx].score;
			}
			// FIXME: do we need to skip RODT rows here, like we do below in the by-RANK settings?

			/* When using automatic ODT settings use the ODT
			   settings associated with the best score for
			   all of the tested ODT combinations. */

			if ((rodt_score < best_rodt_score) || // always take lower score, OR
			    ((rodt_score == best_rodt_score) && // take same score if RODT ohms are higher
			     (imp_values->rodt_ohms[rodt_ctl] > imp_values->rodt_ohms[auto_rodt_ctl])))
			    {
				debug_print("AUTO: new best score for rodt:%d (%3d), new score:%d, previous score:%d\n",
					    rodt_ctl, imp_values->rodt_ohms[rodt_ctl], rodt_score, best_rodt_score);
				best_rodt_score = rodt_score;
				auto_rodt_ctl   = rodt_ctl;
				auto_rtt_nom    = rtt_nom;
			    }
		    } /* for (rodt_ctl=max_rodt_ctl; rodt_ctl>=min_rodt_ctl; --rodt_ctl) */
		} /* for (rtt_idx=min_rtt_nom_idx; rtt_idx<=max_rtt_nom_idx; ++rtt_idx) */

		lmc_modereg_params1.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num));

		if (ddr_rtt_nom_auto) {
		    /* Store the automatically set RTT_NOM value */
		    if (dyn_rtt_nom_mask & 1) lmc_modereg_params1.s.rtt_nom_00 = auto_rtt_nom;
		    if (dyn_rtt_nom_mask & 2) lmc_modereg_params1.s.rtt_nom_01 = auto_rtt_nom;
		    if (dyn_rtt_nom_mask & 4) lmc_modereg_params1.s.rtt_nom_10 = auto_rtt_nom;
		    if (dyn_rtt_nom_mask & 8) lmc_modereg_params1.s.rtt_nom_11 = auto_rtt_nom;
		} else {
		    /* restore the manual settings to the register */
		    lmc_modereg_params1.s.rtt_nom_00 = default_rtt_nom[0];
		    lmc_modereg_params1.s.rtt_nom_01 = default_rtt_nom[1];
		    lmc_modereg_params1.s.rtt_nom_10 = default_rtt_nom[2];
		    lmc_modereg_params1.s.rtt_nom_11 = default_rtt_nom[3];
		}

		DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num), lmc_modereg_params1.u);
		ddr_print("RTT_NOM     %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_11],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_10],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_01],
			  imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_00],
			  lmc_modereg_params1.s.rtt_nom_11,
			  lmc_modereg_params1.s.rtt_nom_10,
			  lmc_modereg_params1.s.rtt_nom_01,
			  lmc_modereg_params1.s.rtt_nom_00);

		ddr_print("RTT_WR      %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
			  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_11],
			  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_10],
			  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_01],
			  imp_values->rtt_wr_ohms[lmc_modereg_params1.s.rtt_wr_00],
			  lmc_modereg_params1.s.rtt_wr_11,
			  lmc_modereg_params1.s.rtt_wr_10,
			  lmc_modereg_params1.s.rtt_wr_01,
			  lmc_modereg_params1.s.rtt_wr_00);

		ddr_print("DIC         %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
			  imp_values->dic_ohms[lmc_modereg_params1.s.dic_11],
			  imp_values->dic_ohms[lmc_modereg_params1.s.dic_10],
			  imp_values->dic_ohms[lmc_modereg_params1.s.dic_01],
			  imp_values->dic_ohms[lmc_modereg_params1.s.dic_00],
			  lmc_modereg_params1.s.dic_11,
			  lmc_modereg_params1.s.dic_10,
			  lmc_modereg_params1.s.dic_01,
			  lmc_modereg_params1.s.dic_00);

		if (ddr_type == DDR4_DRAM) {
		    bdk_lmcx_modereg_params2_t lmc_modereg_params2;
		    /*
		     * We must read the CSR, and not depend on odt_config[odt_idx].odt_mask2,
		     * since we could have overridden values with envvars.
		     * NOTE: this corrects the printout, since the CSR is not written with the old values...
		     */
		    lmc_modereg_params2.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS2(ddr_interface_num));

		    ddr_print("RTT_PARK    %3d, %3d, %3d, %3d ohms           :  %x,%x,%x,%x\n",
			      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_11],
			      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_10],
			      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_01],
			      imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_00],
			      lmc_modereg_params2.s.rtt_park_11,
			      lmc_modereg_params2.s.rtt_park_10,
			      lmc_modereg_params2.s.rtt_park_01,
			      lmc_modereg_params2.s.rtt_park_00);

		    ddr_print("%-45s :  0x%x,0x%x,0x%x,0x%x\n", "VREF_RANGE",
			      lmc_modereg_params2.s.vref_range_11,
			      lmc_modereg_params2.s.vref_range_10,
			      lmc_modereg_params2.s.vref_range_01,
			      lmc_modereg_params2.s.vref_range_00);

		    ddr_print("%-45s :  0x%x,0x%x,0x%x,0x%x\n", "VREF_VALUE",
			      lmc_modereg_params2.s.vref_value_11,
			      lmc_modereg_params2.s.vref_value_10,
			      lmc_modereg_params2.s.vref_value_01,
			      lmc_modereg_params2.s.vref_value_00);
		}

		lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
		if (ddr_rodt_ctl_auto)
		    lmc_comp_ctl2.s.rodt_ctl = auto_rodt_ctl;
		else
		    lmc_comp_ctl2.s.rodt_ctl = default_rodt_ctl;
		DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(ddr_interface_num), lmc_comp_ctl2.u);
		lmc_comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));
		ddr_print("Read ODT_CTL                                  : 0x%x (%d ohms)\n",
			  lmc_comp_ctl2.s.rodt_ctl, imp_values->rodt_ohms[lmc_comp_ctl2.s.rodt_ctl]);

		/* Use the delays associated with the best score for each individual rank */
		ddr_print("Evaluating Read-Leveling Scoreboard for per-RANK settings.\n");

		////////////////// this is the start of the RANK MAJOR LOOP

		for (rankx = 0; rankx < dimm_count * 4; rankx++) {
		    int best_rank_score = DEFAULT_BEST_RANK_SCORE; /* Start with an arbitrarily high score */
		    int best_rank_rtt_nom = 0;
		    int best_rank_nom_ohms = 0;
		    int best_rank_ctl = 0;
		    int best_rank_ohms = 0;
		    int best_rankx = 0;

		    if (!(rank_mask & (1 << rankx)))
			continue;

		    // some of the rank-related loops below need to operate only on the ranks of a single DIMM,
		    // so create a mask for their use here
		    int dimm_rank_mask;
		    if (num_ranks == 4)
			dimm_rank_mask = rank_mask; // should be 1111
		    else {
			dimm_rank_mask = rank_mask & 3; // should be 01 or 11
			if (rankx >= 2)
			    dimm_rank_mask <<= 2; // doing a rank on the second DIMM, should be 0100 or 1100
		    }
		    debug_print("DIMM rank mask: 0x%x, rank mask: 0x%x, rankx: %d\n", dimm_rank_mask, rank_mask, rankx);

		    ////////////////// this is the start of the BEST ROW SCORE LOOP

		    for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) {
			int rtt_nom_ohms;
			rtt_nom = imp_values->rtt_nom_table[rtt_idx];
			rtt_nom_ohms = imp_values->rtt_nom_ohms[rtt_nom];

			/* When the read ODT mask is zero the dyn_rtt_nom_mask is
			   zero than RTT_NOM will not be changing during
			   read-leveling.  Since the value is fixed we only need
			   to test it once. */
			if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
			    continue;

			debug_print("N%d.LMC%d.R%d: starting RTT_NOM %d (%d)\n",
				    node, ddr_interface_num, rankx, rtt_nom, rtt_nom_ohms);

			for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) {
			    int next_ohms = imp_values->rodt_ohms[rodt_ctl];

			    // skip RODT rows in mask, but *NOT* rows with too high a score;
			    // we will not use the skipped ones for printing or evaluating, but
			    // we need to allow all the non-skipped ones to be candidates for "best"
			    if (((1 << rodt_ctl) & rodt_row_skip_mask) != 0) {
				debug_print("N%d.LMC%d.R%d: SKIPPING rodt:%d (%d) with rank_score:%d\n",
					    node, ddr_interface_num, rankx, rodt_ctl, next_ohms, next_score);
				continue;
			    }
			    for (int orankx = 0; orankx < dimm_count * 4; orankx++) { // this is ROFFIX-0528
				if (!(dimm_rank_mask & (1 << orankx))) // stay on the same DIMM
				    continue;

				int next_score = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].score;

				if (next_score > best_rank_score) // always skip a higher score
				    continue;
				if (next_score == best_rank_score) { // if scores are equal
				    if (next_ohms < best_rank_ohms) // always skip lower ohms
					continue;
				    if (next_ohms == best_rank_ohms) { // if same ohms
					if (orankx != rankx) // always skip the other rank(s)
					    continue;
				    }
				    // else next_ohms are greater, always choose it
				}
				// else next_score is less than current best, so always choose it
				    extra_ddr_print("N%d.LMC%d.R%d: new best score: rank %d, rodt %d(%3d), new best %d, previous best %d(%d)\n",
						    node, ddr_interface_num, rankx, orankx, rodt_ctl, next_ohms, next_score,
						    best_rank_score, best_rank_ohms);
				    best_rank_score	    = next_score;
				    best_rank_rtt_nom   = rtt_nom;
				    best_rank_nom_ohms  = rtt_nom_ohms;
				    best_rank_ctl       = rodt_ctl;
				    best_rank_ohms      = next_ohms;
				    best_rankx          = orankx;
				    lmc_rlevel_rank.u   = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].setting;
 
			    } /* for (int orankx = 0; orankx < dimm_count * 4; orankx++) */
			} /* for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) */
		    } /* for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) */

		    ////////////////// this is the end of the BEST ROW SCORE LOOP

		    // DANGER, Will Robinson!! Abort now if we did not find a best score at all...
		    if (best_rank_score == DEFAULT_BEST_RANK_SCORE) {
			error_print("WARNING: no best rank score found for N%d.LMC%d.R%d - resetting node...\n",
				    node, ddr_interface_num, rankx);
			bdk_wait_usec(500000);
			bdk_reset_chip(node);
		    }

		    int MAX_RANK_SCORE = best_rank_score + (MAX_RANK_SCORE_LIMIT / dimm_count); // FIXME: relative now, but still arbitrary...

		    if (!ecc_ena){
			lmc_rlevel_rank.s.byte8 = lmc_rlevel_rank.s.byte0; /* ECC is not used */
		    }

		    // at the end, write the best row settings to the current rank
		    DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), lmc_rlevel_rank.u);
		    lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

		    // print the best row selected
		    display_read_leveling_settings_with_RODT(node, ddr_interface_num, 
							     lmc_rlevel_rank, best_rankx, best_rank_score,
							     best_rank_rtt_nom, best_rank_nom_ohms,
							     best_rank_ctl, best_rank_ohms, WITH_RODT_BESTROW);

		    bdk_lmcx_rlevel_rankx_t saved_rlevel_rank;
		    saved_rlevel_rank.u = lmc_rlevel_rank.u;

#ifdef DEBUG_EXTRA_PRINT_LOOP
		    ////////////////// this is the start of the PRINT LOOP 

		    // for pass==0, print current rank, pass==1 print other rank(s) 
		    // this is done because we want to show each ranks RODT values together, not interlaced
		    for (int pass = 0; pass < 2; pass++ ) {
			for (int orankx = 0; orankx < dimm_count * 4; orankx++) {
			    if (!(dimm_rank_mask & (1 << orankx))) // stay on the same DIMM
				continue;

			    if (((pass == 0) && (orankx != rankx)) || ((pass != 0) && (orankx == rankx)))
				continue;

			    for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) {
				rtt_nom = imp_values->rtt_nom_table[rtt_idx];
				if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
				    continue;

				// cycle through all the RODT values...
				for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) {
				    bdk_lmcx_rlevel_rankx_t temp_rlevel_rank;
				    int temp_score = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].score;
				    temp_rlevel_rank.u = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].setting;

				    // skip RODT rows in mask, or rows with too high a score;
				    // we will not use them for printing or evaluating...
				    int skip_row = (((1 << rodt_ctl) & rodt_row_skip_mask) || (temp_score > MAX_RANK_SCORE))
					            ? WITH_RODT_SKIPPING: WITH_RODT_BLANK;
				    display_read_leveling_settings_with_RODT(node, ddr_interface_num, 
									     temp_rlevel_rank, orankx, temp_score,
									     rtt_nom,  imp_values->rtt_nom_ohms[rtt_nom],
									     rodt_ctl, imp_values->rodt_ohms[rodt_ctl],
									     skip_row);

				} /* for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) */
			    } /* for (rtt_idx=min_rtt_nom_idx; rtt_idx<=max_rtt_nom_idx; ++rtt_idx) */
			} /* for (int orankx = 0; orankx < dimm_count * 4; orankx++) { */
		    } /* for (int pass = 0; pass < 2; pass++ ) */

		    ////////////////// this is the end of the PRINT LOOP 

#endif /* DEBUG_EXTRA_PRINT_LOOP */

		    // now evaluate which bytes need adjusting
		    uint64_t byte_msk = 0x3f; // 6-bit fields
		    uint64_t best_byte, new_byte, temp_byte, orig_best_byte;

		    uint64_t rank_best_bytes[9]; // collect the new byte values; first init with current best for neighbor use
		    for (int byte_idx = 0, byte_sh = 0; byte_idx < 8+ecc_ena; byte_idx++, byte_sh += 6) {
			rank_best_bytes[byte_idx] = (lmc_rlevel_rank.u >> byte_sh) & byte_msk;
		    }

		    ////////////////// this is the start of the BEST BYTE LOOP 

		    for (int byte_idx = 0, byte_sh = 0; byte_idx < 8+ecc_ena; byte_idx++, byte_sh += 6) {
			best_byte = orig_best_byte = rank_best_bytes[byte_idx];

			////////////////// this is the start of the BEST BYTE AVERAGING LOOP 

			// validate the initial "best" byte by looking at the average of the unskipped byte-column entries
			// we want to do this before we go further, so we can try to start with a better initial value
			// this is the so-called "BESTBUY" patch set
			int sum = 0, count = 0;

			for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) {
			    rtt_nom = imp_values->rtt_nom_table[rtt_idx];
			    if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
				continue;

			    for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) {
				bdk_lmcx_rlevel_rankx_t temp_rlevel_rank;
				int temp_score;
				for (int orankx = 0; orankx < dimm_count * 4; orankx++) { // average over all the ranks
				    if (!(dimm_rank_mask & (1 << orankx))) // stay on the same DIMM
					continue;
				    temp_score = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].score;
				    // skip RODT rows in mask, or rows with too high a score;
				    // we will not use them for printing or evaluating...

				    if (!((1 << rodt_ctl) & rodt_row_skip_mask) &&
					(temp_score <= MAX_RANK_SCORE))
				    {
					temp_rlevel_rank.u = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].setting;
					temp_byte = (temp_rlevel_rank.u >> byte_sh) & byte_msk;
					sum += temp_byte;
					count++;
#ifndef DEBUG_EXTRA_PRINT_LOOP
					// only print first time through../
					if (byte_idx == 0) {
					    display_read_leveling_settings_with_RODT(node, ddr_interface_num, temp_rlevel_rank, orankx, temp_score,
										     rtt_nom,  imp_values->rtt_nom_ohms[rtt_nom],
										     rodt_ctl, imp_values->rodt_ohms[rodt_ctl],
										     WITH_RODT_BLANK);
					}
#endif /* DEBUG_EXTRA_PRINT_LOOP */
				    }
				} /* for (int orankx = 0; orankx < dimm_count * 4; orankx++) */
			    } /* for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) */
			} /* for (rtt_idx=min_rtt_nom_idx; rtt_idx<=max_rtt_nom_idx; ++rtt_idx) */

			////////////////// this is the end of the BEST BYTE AVERAGING LOOP 


			uint64_t avg_byte = divide_nint(sum, count); // FIXME: validate count and sum??
			int avg_diff = (int)best_byte - (int)avg_byte;
			new_byte = best_byte;
			if (avg_diff != 0) { 
			    // bump best up/dn by 1, not necessarily all the way to avg
			    new_byte = best_byte + ((avg_diff > 0) ? -1: 1);
			}

			extra_ddr_print("START: Byte %d: best %d is different by %d from average %d, using %d.\n",
					byte_idx, (int)best_byte, avg_diff, (int)avg_byte, (int)new_byte);
			best_byte = new_byte;

			// At this point best_byte is either:
			// 1. the original byte-column value from the best scoring RODT row, OR
			// 2. that value bumped toward the average of all the byte-column values
			//
			// best_byte will not change from here on...

			////////////////// this is the start of the BEST BYTE COUNTING LOOP 

			// NOTE: we do this next loop separately from above, because we count relative to "best_byte"
			// which may have been modified by the above averaging operation...
			int count_less = 0, count_same = 0, count_more = 0;

			for (rtt_idx = min_rtt_nom_idx; rtt_idx <= max_rtt_nom_idx; ++rtt_idx) {
			    rtt_nom = imp_values->rtt_nom_table[rtt_idx];
			    if ((dyn_rtt_nom_mask == 0) && (rtt_idx != min_rtt_nom_idx))
				continue;

			    for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) {
				bdk_lmcx_rlevel_rankx_t temp_rlevel_rank;
				int temp_score;
				for (int orankx = 0; orankx < dimm_count * 4; orankx++) { // count over all the ranks
				    if (!(dimm_rank_mask & (1 << orankx))) // stay on the same DIMM
					continue;
				    temp_score = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].score;
				    // skip RODT rows in mask, or rows with too high a score;
				    // we will not use them for printing or evaluating...
				    if (((1 << rodt_ctl) & rodt_row_skip_mask) ||
					(temp_score > MAX_RANK_SCORE))
					{
					    continue;
					}
				    temp_rlevel_rank.u = rlevel_scoreboard[rtt_nom][rodt_ctl][orankx].setting;
				    temp_byte = (temp_rlevel_rank.u >> byte_sh) & byte_msk;

				    if (temp_byte == 0) // do not count it if illegal
					;//continue;
				    else if (temp_byte == best_byte)
					count_same++;
				    else if (temp_byte == best_byte - 1)
					count_less++;
				    else if (temp_byte == best_byte + 1)
					count_more++;
				    // else do not count anything more than 1 away from the best
				} /* for (int orankx = 0; orankx < dimm_count * 4; orankx++) */
			    } /* for (rodt_ctl = max_rodt_ctl; rodt_ctl >= min_rodt_ctl; --rodt_ctl) */
			} /* for (rtt_idx=min_rtt_nom_idx; rtt_idx<=max_rtt_nom_idx; ++rtt_idx) */

			extra_ddr_print("COUNT: Byte %d: orig %d now %d, more %d same %d less %d\n",
				  byte_idx, (int)orig_best_byte, (int)best_byte,
				  count_more, count_same, count_less);

			////////////////// this is the end of the BEST BYTE COUNTING LOOP 

			// choose the new byte value
			// we need to check that there is no gap greater than 2 between adjacent bytes
			//  (adjacency depends on DIMM type)
			// use the neighbor value to help decide
			// initially, the rank_best_bytes[] will contain values from the chosen lowest score rank
			new_byte = 0;

			// neighbor is index-1 unless we are index 0 or index 8 (ECC)
			int neighbor = (byte_idx == 8) ? 3 : ((byte_idx == 0) ? 1 : byte_idx - 1);
			uint64_t neigh_byte = rank_best_bytes[neighbor];


			// can go up or down or stay the same, so look at a numeric average to help
			    new_byte = divide_nint(((count_more * (best_byte + 1)) +
						    (count_same * (best_byte + 0)) +
						    (count_less * (best_byte - 1))),
					       max(1, (count_more + count_same + count_less)));

			    // use neighbor to help choose with average
			if ((byte_idx > 0) && (_abs(neigh_byte - new_byte) > 2)) // but not for byte 0
			{
				uint64_t avg_pick = new_byte;
				if ((new_byte - best_byte) != 0)
				    new_byte = best_byte; // back to best, average did not get better
				else // avg was the same, still too far, now move it towards the neighbor
				    new_byte += (neigh_byte > new_byte) ? 1 : -1;

				extra_ddr_print("AVERAGE: Byte %d: neighbor %d too different %d from average %d, picking %d.\n",
						byte_idx, neighbor, (int)neigh_byte, (int)avg_pick, (int)new_byte);
			    }
#if MAJORITY_OVER_AVG
			// NOTE:
			// For now, we let the neighbor processing above trump the new simple majority processing here.
			// This is mostly because we have seen no smoking gun for a neighbor bad choice (yet?).
			// Also note that we will ALWAYS be using byte 0 majority, because of the if clause above.
			else {
			    // majority is dependent on the counts, which are relative to best_byte, so start there
			    uint64_t maj_byte = best_byte;
			    if ((count_more > count_same) && (count_more > count_less)) {
				maj_byte++;
			    } else if ((count_less > count_same) && (count_less > count_more)) {
				maj_byte--;
			    }
			    if (maj_byte != new_byte) {
				// print only when majority choice is different from average
				extra_ddr_print("MAJORITY: Byte %d: picking majority of %d over average %d.\n",
						byte_idx, (int)maj_byte, (int)new_byte);
				new_byte = maj_byte;
			    } else {
				extra_ddr_print("AVERAGE: Byte %d: picking average of %d.\n", byte_idx, (int)new_byte);
			    }
			}
#else
			else {
			    extra_ddr_print("AVERAGE: Byte %d: picking average of %d.\n", byte_idx, (int)new_byte);
			}
#endif

			extra_ddr_print("SUMMARY: Byte %d: %s: orig %d now %d, more %d same %d less %d, using %d\n",
					byte_idx, "AVG", (int)orig_best_byte, 
					(int)best_byte, count_more, count_same, count_less, (int)new_byte);

			// update the byte with the new value (NOTE: orig value in the CSR may not be current "best")
			lmc_rlevel_rank.u &= ~(byte_msk << byte_sh);
			lmc_rlevel_rank.u |= (new_byte << byte_sh);

			rank_best_bytes[byte_idx] = new_byte; // save new best for neighbor use

		    } /* for (byte_idx = 0; byte_idx < 8+ecc_ena; byte_idx++) */

		    ////////////////// this is the end of the BEST BYTE LOOP 

		    if (saved_rlevel_rank.u != lmc_rlevel_rank.u) {
			DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), lmc_rlevel_rank.u);
			lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));
			debug_print("Adjusting Read-Leveling per-RANK settings.\n");
		    } else {
			debug_print("Not Adjusting Read-Leveling per-RANK settings.\n");
		    }
		    display_read_leveling_settings_with_final(node, ddr_interface_num, lmc_rlevel_rank, rankx, best_rank_score);

#if RLEXTRAS_PATCH
		    {
#define RLEVEL_RANKX_EXTRAS_INCR  4
			bdk_lmcx_rlevel_rankx_t temp_rlevel_rank = lmc_rlevel_rank;
			int byte, delay;
			if (rankx < 3) {
			    extra_ddr_print("N%d.LMC%d.R%d: writing RLEVEL_RANK unused entries.\n",
					    node, ddr_interface_num, rankx);
			    for (byte = 0; byte < 9; byte++) {
				delay = get_rlevel_rank_struct(&temp_rlevel_rank, byte) + RLEVEL_RANKX_EXTRAS_INCR;
				if (delay > (int)RLEVEL_BYTE_MSK) delay = RLEVEL_BYTE_MSK;
				update_rlevel_rank_struct(&temp_rlevel_rank, byte, delay);
			    }
			    if (rankx == 0) { // if 0, write 1, and 2
				DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, 1), temp_rlevel_rank.u);
				DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, 2), temp_rlevel_rank.u);
			    }
			    // if 0, 1 or 2, write 3
			    DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, 3), temp_rlevel_rank.u);
			}
		    }
#endif /* RLEXTRAS_PATCH */
		} /* for (rankx = 0; rankx < dimm_count * 4; rankx++) */

		////////////////// this is the end of the RANK MAJOR LOOP

	    }  /* Evaluation block */
        } /* while(rlevel_debug_loops--) */

        lmc_control.s.ddr2t           = save_ddr2t;
        DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);
        lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));
        ddr_print("DDR2T                                         : %6d\n", lmc_control.s.ddr2t); /* Display final 2T value */



        perform_ddr3_init_sequence(node, rank_mask, ddr_interface_num);

        for (rankx = 0; rankx < dimm_count * 4;rankx++) {
            uint64_t value;
            int parameter_set = 0;
            if (!(rank_mask & (1 << rankx)))
                continue;

            lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));

            for (i=0; i<9; ++i) {
                if ((s = lookup_env_parameter("ddr%d_rlevel_rank%d_byte%d", ddr_interface_num, rankx, i)) != NULL) {
                    parameter_set |= 1;
                    value = strtoul(s, NULL, 0);

                    update_rlevel_rank_struct(&lmc_rlevel_rank, i, value);
                }
            }

            if ((s = lookup_env_parameter_ull("ddr%d_rlevel_rank%d", ddr_interface_num, rankx)) != NULL) {
                parameter_set |= 1;
                value = strtoull(s, NULL, 0);
                lmc_rlevel_rank.u = value;
            }


            if (bdk_is_platform(BDK_PLATFORM_ASIM)) {
                parameter_set |= 1;

                lmc_rlevel_rank.s.byte8 = 3;
                lmc_rlevel_rank.s.byte7 = 3;
                lmc_rlevel_rank.s.byte6 = 3;
                lmc_rlevel_rank.s.byte5 = 3;
                lmc_rlevel_rank.s.byte4 = 3;
                lmc_rlevel_rank.s.byte3 = 3;
                lmc_rlevel_rank.s.byte2 = 3;
                lmc_rlevel_rank.s.byte1 = 3;
                lmc_rlevel_rank.s.byte0 = 3;
            }

            if (parameter_set) {
                DRAM_CSR_WRITE(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx), lmc_rlevel_rank.u);
                display_read_leveling_settings(node, ddr_interface_num, lmc_rlevel_rank, rankx);
            }
        }
    }

    /* Workaround Trcd overflow by using Additive latency. */
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X))
    {
        bdk_lmcx_modereg_params0_t lmc_modereg_params0;
        bdk_lmcx_timing_params1_t lmc_timing_params1;
        bdk_lmcx_control_t lmc_control;
        int rankx;

        lmc_timing_params1.u = BDK_CSR_READ(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num));
        lmc_modereg_params0.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num));
        lmc_control.u = BDK_CSR_READ(node, BDK_LMCX_CONTROL(ddr_interface_num));

        if (lmc_timing_params1.s.trcd == 0) {
            ddr_print("Workaround Trcd overflow by using Additive latency.\n");
            lmc_timing_params1.s.trcd     = 12; /* Hard code this to 12 and enable additive latency */
            lmc_modereg_params0.s.al      = 2; /* CL-2 */
            lmc_control.s.pocas           = 1;

            ddr_print("MODEREG_PARAMS0                               : 0x%016lx\n", lmc_modereg_params0.u);
            DRAM_CSR_WRITE(node, BDK_LMCX_MODEREG_PARAMS0(ddr_interface_num), lmc_modereg_params0.u);
            ddr_print("TIMING_PARAMS1                                : 0x%016lx\n", lmc_timing_params1.u);
            DRAM_CSR_WRITE(node, BDK_LMCX_TIMING_PARAMS1(ddr_interface_num), lmc_timing_params1.u);

            ddr_print("LMC_CONTROL                                   : 0x%016lx\n", lmc_control.u);
            DRAM_CSR_WRITE(node, BDK_LMCX_CONTROL(ddr_interface_num), lmc_control.u);

            for (rankx = 0; rankx < dimm_count * 4; rankx++) {
                if (!(rank_mask & (1 << rankx)))
                    continue;

                ddr4_mrw(node, ddr_interface_num, rankx, -1, 1, 0); /* MR1 */
            }
        }
    }

    // this is here just for output, to allow check of the Deskew settings one last time...
    {
        deskew_counts_t dsk_counts;
	ddr_print("N%d.LMC%d: Check Deskew Settings before software Write-Leveling.\n",
		  node, ddr_interface_num);
        Validate_Deskew_Training(node, rank_mask, ddr_interface_num, &dsk_counts, 1);
    }


    /* Workaround Errata 26304 (T88@2.0)

       When the CSRs LMCX_DLL_CTL3[WR_DESKEW_ENA] = 1 AND
       LMCX_PHY_CTL2[DQS[0..8]_DSK_ADJ] > 4, set
       LMCX_EXT_CONFIG[DRIVE_ENA_BPRCH] = 1.
    */
    if (!CAVIUM_IS_MODEL(CAVIUM_CN88XX_PASS1_X)) {
        bdk_lmcx_dll_ctl3_t dll_ctl3;
        bdk_lmcx_phy_ctl2_t phy_ctl2;
        bdk_lmcx_ext_config_t ext_config;
        int increased_dsk_adj = 0;
        int byte;

        phy_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_PHY_CTL2(ddr_interface_num));
        ext_config.u = BDK_CSR_READ(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num));
        dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

        for (byte = 0; byte < 8; ++byte) {
            if (!(ddr_interface_bytemask&(1<<byte)))
                continue;
            increased_dsk_adj |= (((phy_ctl2.u >> (byte*3)) & 0x7) > 4);
        }

        if ((dll_ctl3.s.wr_deskew_ena == 1) && increased_dsk_adj) {
            ext_config.s.drive_ena_bprch = 1;
            DRAM_CSR_WRITE(node, BDK_LMCX_EXT_CONFIG(ddr_interface_num),
                                      ext_config.u);
        }
    }

    { // Software Write-Leveling block

        /* Try to determine/optimize write-level delays experimentally. */
#pragma pack(push,1)
        bdk_lmcx_wlevel_rankx_t lmc_wlevel_rank;
        bdk_lmcx_wlevel_rankx_t lmc_wlevel_rank_hw_results;
        bdk_lmcx_rlevel_rankx_t lmc_rlevel_rank;
        bdk_lmcx_config_t lmc_config;
        int byte;
        int delay;
        int rankx = 0;
        int save_ecc_ena;
        int active_rank;
        int sw_wlevel_offset = 1;
        int sw_wlevel_enable = 1; /* FIX... Should be customizable. */
        int interfaces;
	int measured_vref_flag;
        typedef enum {
            WL_ESTIMATED = 0,   /* HW/SW wleveling failed. Results
                                   estimated. */
            WL_HARDWARE  = 1,   /* H/W wleveling succeeded */
            WL_SOFTWARE  = 2,   /* S/W wleveling passed 2 contiguous
                                   settings. */
            WL_SOFTWARE1 = 3,   /* S/W wleveling passed 1 marginal
                                   setting. */
        } sw_wl_status_t;

        static const char *wl_status_strings[] = {
            "(e)",
            "   ",
            "   ",
            "(1)"
        };
#pragma pack(pop)

        if ((s = lookup_env_parameter("ddr_software_wlevel")) != NULL) {
            sw_wlevel_enable = strtoul(s, NULL, 0);
        }

        if (sw_wlevel_enable)
            ddr_print("N%d.LMC%d: Performing software Write-Leveling\n", node, ddr_interface_num);

	/* Get the measured_vref setting from the config, check for an override... */
	/* NOTE: measured_vref=1 (ON) means force use of MEASURED Vref... */
        measured_vref_flag = custom_lmc_config->measured_vref;
        if ((s = lookup_env_parameter("ddr_measured_vref")) != NULL) {
            measured_vref_flag = strtoul(s, NULL, 0);
        }

        /* Disable ECC for DRAM tests */
        lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(ddr_interface_num));
        save_ecc_ena = lmc_config.s.ecc_ena;
        lmc_config.s.ecc_ena = 0;
        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

        limit_l2_ways(node, 0, 0);       /* Disable l2 sets for DRAM testing */

        /* We need to track absolute rank number, as well as how many
        ** active ranks we have.  Two single rank DIMMs show up as
        ** ranks 0 and 2, but only 2 ranks are active. */
        active_rank = 0;

        interfaces = __builtin_popcount(ddr_interface_mask);

        for (rankx = 0; rankx < dimm_count * 4; rankx++) {
            uint64_t rank_addr;
            int vref_value, final_vref_value, override_final_vref_value;
            char best_vref_values_count, vref_values_count;
            char best_vref_values_start, vref_values_start;

            int bytes_failed;
            sw_wl_status_t byte_test_status[9];
            sw_wl_status_t sw_wl_rank_status = WL_HARDWARE;

            if (!sw_wlevel_enable)
                break;

            if (!(rank_mask & (1 << rankx)))
                continue;


            /* Save off the h/w wl results */
            lmc_wlevel_rank_hw_results.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

            vref_values_count = 0;
            vref_values_start = 0;
            best_vref_values_count = 0;
            best_vref_values_start = 0;

            debug_print("Rank(%d)", rankx);
            for (vref_value=0; vref_value<(0x33); ++vref_value) {
                debug_print(" %02x", vref_value);
            }
            debug_print("\nRank(%d)", rankx);
            /* Loop one extra time using the Final Vref value. */
            for (vref_value=0; vref_value<(0x33+1); ++vref_value) {
                if (ddr_type == DDR4_DRAM) {
                    if (vref_value < 0x33) {
		        set_vref(node, ddr_interface_num, rankx, 0, vref_value);
                    } else {
                        /* Set the final Vref value. */
                        if (best_vref_values_count > 0) {
                            best_vref_values_count = max(best_vref_values_count, 2);
                            final_vref_value = best_vref_values_start + divide_roundup((best_vref_values_count-1)*4,10);
                        } else {
                            /* If nothing passed use the default Vref value for this rank */
                            bdk_lmcx_modereg_params2_t lmc_modereg_params2;

                            lmc_modereg_params2.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS2(ddr_interface_num));

                            switch (rankx) {
                            case 0:
                                final_vref_value = lmc_modereg_params2.s.vref_value_00;
                                break;
                            case 1:
                                final_vref_value = lmc_modereg_params2.s.vref_value_01;
                                break;
                            case 2:
                                final_vref_value = lmc_modereg_params2.s.vref_value_10;
                                break;
                            case 3:
                                final_vref_value = lmc_modereg_params2.s.vref_value_11;
                                break;
                            }
                        }
                        debug_print(" (0x%02x)\n", final_vref_value);

                        /* Calculate an override of the measured Vref value
			   but only for configurations we know how to...*/
			// we have code for 2-rank DIMMs in both 1-slot or 2-slot configs,
			// and can use the 2-rank 1-slot code for 1-rank DIMMs in 1-slot configs
			if ((num_ranks == 2) || ((num_ranks == 1) && (dimm_count == 1)))
			{
                            int rtt_wr, rtt_park, dqx_ctl, rtt_nom;
                            bdk_lmcx_modereg_params1_t lmc_modereg_params1;
                            bdk_lmcx_modereg_params2_t lmc_modereg_params2;
                            bdk_lmcx_comp_ctl2_t comp_ctl2;

                            lmc_modereg_params1.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS1(ddr_interface_num));
                            lmc_modereg_params2.u = BDK_CSR_READ(node, BDK_LMCX_MODEREG_PARAMS2(ddr_interface_num));
                            comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(ddr_interface_num));

                            switch (rankx) {
                            case 0:
                                rtt_wr   = imp_values->rtt_wr_ohms [lmc_modereg_params1.s.rtt_wr_00];
                                rtt_park = imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_00];
				rtt_nom  = imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_00];
                                break;
                            case 1:
                                rtt_wr   = imp_values->rtt_wr_ohms [lmc_modereg_params1.s.rtt_wr_01];
                                rtt_park = imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_01];
				rtt_nom  = imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_01];
                                break;
                            case 2:
                                rtt_wr   = imp_values->rtt_wr_ohms [lmc_modereg_params1.s.rtt_wr_10];
                                rtt_park = imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_10];
				rtt_nom  = imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_10];
                                break;
                            case 3:
                                rtt_wr   = imp_values->rtt_wr_ohms [lmc_modereg_params1.s.rtt_wr_11];
                                rtt_park = imp_values->rtt_nom_ohms[lmc_modereg_params2.s.rtt_park_11];
				rtt_nom  = imp_values->rtt_nom_ohms[lmc_modereg_params1.s.rtt_nom_11];
                                break;
                            }
                            dqx_ctl = imp_values->dqx_strength  [comp_ctl2.s.dqx_ctl    ];

			    if (dimm_count == 1) // separate calcs for 1 vs 2 DIMMs per LMC
				override_final_vref_value = compute_Vref_1slot_2rank(rtt_wr, rtt_park, dqx_ctl);
			    else
				override_final_vref_value = compute_Vref_2slot_2rank(rtt_wr, rtt_park, dqx_ctl, rtt_nom);

			    ddr_print("N%d.LMC%d.R%d: Vref Computed Summary                 :"
				      "              %2d (0x%02x)\n",
				      node, ddr_interface_num,
				      rankx, override_final_vref_value,
				      override_final_vref_value);
                        } else {
			    ddr_print("N%d.LMC%d.R%d: Vref NOT COMPUTED\n", node, ddr_interface_num, rankx);
			    override_final_vref_value = 0;
			}

                        ddr_print("N%d.LMC%d.R%d: Vref Training Summary                 :"
                                  "    %2d <----- %2d (0x%02x) -----> %2d range: %2d\n",
				  node, ddr_interface_num,
                                  rankx, best_vref_values_start,
                                  final_vref_value, final_vref_value,
                                  best_vref_values_start+best_vref_values_count-1,
                                  best_vref_values_count-1);

                        if ((s = lookup_env_parameter("ddr%d_vref_value_%1d%1d",
                                                      ddr_interface_num, !!(rankx&2), !!(rankx&1))) != NULL) {
                            final_vref_value = strtoul(s, NULL, 0);
                        }

			// We can use COMPUTED Vref only for some configs (see above)
			if ((num_ranks == 2) || ((num_ranks == 1) && (dimm_count == 1))) {
			    // but allow MEASURED Vref to be used...
			    if (measured_vref_flag || (override_final_vref_value == 0)) {
				ddr_print("N%d.LMC%d.R%d: Using MEASURED Vref %2d (0x%02x) vs COMPUTED %2d (0x%02x)\n",
					  node, ddr_interface_num, 
				       rankx, final_vref_value, final_vref_value,
				       override_final_vref_value, override_final_vref_value);
				set_vref(node, ddr_interface_num, rankx, 0, final_vref_value);
			    } else {
				ddr_print("N%d.LMC%d.R%d: Using COMPUTED Vref %2d (0x%02x) vs MEASURED %2d (0x%02x)\n",
					  node, ddr_interface_num,
				       rankx, override_final_vref_value, override_final_vref_value,
				       final_vref_value, final_vref_value);
				set_vref(node, ddr_interface_num, rankx, 0, override_final_vref_value);
			    }
			} else { // always use measured for other DIMM configs for now
			    ddr_print("N%d.LMC%d.R%d: Using MEASURED Vref %2d (0x%02x)\n",
				      node, ddr_interface_num,
				   rankx, final_vref_value, final_vref_value);
			    set_vref(node, ddr_interface_num, rankx, 0, final_vref_value);
			}
                    }
                } /* if (ddr_type == DDR4_DRAM) */
                lmc_wlevel_rank.u = lmc_wlevel_rank_hw_results.u; /* Restore the saved value */

		for (byte = 0; byte < 8; ++byte)
		    byte_test_status[byte] = WL_ESTIMATED;

                if (wlevel_bitmask_errors == 0) {
                    /* Determine address of DRAM to test for software write leveling. */
                    rank_addr  = active_rank * ((1ull << (pbank_lsb+interfaces/2))/(1+bunk_enable));
                    rank_addr |= (ddr_interface_num<<7); /* Map address into proper interface */
                    rank_addr = bdk_numa_get_address(node, rank_addr);
                    debug_print("Rank Address: 0x%lx\n", rank_addr);

                    for (byte = 0; byte < 8; ++byte) {
                        uint64_t byte_bitmask = 0xff;
                        if (!(ddr_interface_bytemask&(1<<byte)))
                            continue;

                        /* If we will be switching to 32bit mode only test 4 ECC bits.  */
                        if ((! ddr_interface_64b) && (byte == 4))
                            byte_bitmask = 0x0f;

                        /* If h/w write-leveling had no errors then use
                        ** s/w write-leveling to fixup only the upper bits
                        ** of the delays. */
                        for (delay = get_wlevel_rank_struct(&lmc_wlevel_rank, byte); delay < 32; delay += 8) {
                            update_wlevel_rank_struct(&lmc_wlevel_rank, byte, delay);
			    debug_print("Testing byte %d delay %2d\n", byte, delay);
                            DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), lmc_wlevel_rank.u);
                            lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

                            BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

                            if (!test_dram_byte(rank_addr, 4096, byte, byte_bitmask)) {
                                debug_print("        byte %d(0x%lx) delay %2d Passed\n", byte, rank_addr, delay);
                                byte_test_status[byte] = WL_HARDWARE;
                                break;
                            } else {
                                debug_print("        byte %d delay %2d Errors\n", byte, delay);
                            }
                        } /* for (delay = ...) */
                    } /* for (byte = 0; byte < 8; ++byte) */

                    if ((ddr_interface_bytemask & 0xff) == 0xff) {
                        if (save_ecc_ena) {
                            int save_byte8 = lmc_wlevel_rank.s.byte8;
                            byte_test_status[8] = WL_HARDWARE; /* H/W delay value */

                            if ((save_byte8 != lmc_wlevel_rank.s.byte3) &&
                                (save_byte8 != lmc_wlevel_rank.s.byte4)) {

                                int test_byte8 = save_byte8;
                                int test_byte8_error;
                                int byte8_error = 0x1f;
                                int adder;
                                for (adder = 0; adder<= 32; adder+=8) {
                                    test_byte8_error = _abs((adder+save_byte8) - divide_nint(lmc_wlevel_rank.s.byte3+lmc_wlevel_rank.s.byte4, 2));
                                    if (test_byte8_error < byte8_error) {
                                        byte8_error = test_byte8_error;
                                        test_byte8 = save_byte8 + adder;
                                    }
                                }

                                lmc_wlevel_rank.s.byte8 = test_byte8 & ~1; /* Use only even settings */
                            }

                            if (lmc_wlevel_rank.s.byte8 != save_byte8) {
                                /* Change the status if s/w adjusted the delay */
                                byte_test_status[8] = WL_SOFTWARE; /* Estimated delay */
                            }
                        } else {
			    byte_test_status[8] = WL_HARDWARE; /* H/W delay value */
                            lmc_wlevel_rank.s.byte8 = lmc_wlevel_rank.s.byte0; /* ECC is not used */
                        }
                    } else {
                        if (save_ecc_ena) {
                            /* Estimate the ECC byte delay  */
                            if (lmc_wlevel_rank.s.byte4 < lmc_wlevel_rank.s.byte3)
                               lmc_wlevel_rank.s.byte4 = lmc_wlevel_rank.s.byte3;
                        } else {
                            lmc_wlevel_rank.s.byte4 = lmc_wlevel_rank.s.byte0; /* ECC is not used */
                        }
                    }
                } /* if (wlevel_bitmask_errors == 0) */

                bytes_failed = 0;
                for (byte = 0; byte < 8; ++byte) {
                    /* Don't accumulate errors for untested bytes. */
                    if (!(ddr_interface_bytemask & (1 << byte)))
                        continue;
                    bytes_failed += (byte_test_status[byte] == WL_ESTIMATED);
                }

                 /* Vref training loop is only used for DDR4  */
                if (ddr_type != DDR4_DRAM)
			break;

                if (vref_value < 0x33) {
                    debug_print(" %2d", bytes_failed);
                }
                if (bytes_failed == 0) {
                    if (vref_values_count == 0) {
                        vref_values_start = vref_value;
                    }
                    ++vref_values_count;
                    if (vref_values_count > best_vref_values_count) {
                        best_vref_values_count = vref_values_count;
                        best_vref_values_start = vref_values_start;
                        debug_print("N%d.LMC%d.R%d: Vref Training                    (%2d) :    0x%02x <----- ???? -----> 0x%02x\n",
				    node, ddr_interface_num,
                                  rankx, vref_value, best_vref_values_start,
                                  best_vref_values_start+best_vref_values_count-1);
                    }
                } else {
                    vref_values_count = 0;
                        debug_print("N%d.LMC%d.R%d: Vref Training                    (%2d) :    failed\n",
				    node, ddr_interface_num,
                                  rankx, vref_value);
                }
            } /* for (vref_value=0; vref_value<0x33; ++vref_value) */

            if (bytes_failed) {
                uint64_t rank_addr;
                sw_wl_rank_status = WL_SOFTWARE;
                /* If s/w fixups failed then retry using s/w write-leveling. */
                if (wlevel_bitmask_errors == 0) {
                    /* h/w succeeded but s/w fixups failed. So retry s/w. */
                    debug_print("N%d.LMC%d.R%d: Retrying software Write-Leveling.\n",
				node, ddr_interface_num, rankx);
                }
                for (byte = 0; byte < 8; ++byte) {
                    int passed = 0;
                    int wl_offset;
                    uint64_t byte_bitmask = 0xff;

                    if (!(ddr_interface_bytemask & (1 << byte)))
                        continue;

                    /* If we will be switching to 32bit mode only test 4 ECC bits.  */
                    if ((! ddr_interface_64b) && (byte == 4))
                        byte_bitmask = 0x0f;

                    /* Determine address of DRAM to test for software write leveling. */
                    rank_addr  = active_rank * ((1ull << (pbank_lsb+interfaces/2))/(1+bunk_enable));
                    rank_addr |= (ddr_interface_num<<7); /* Map address into proper interface */
                    rank_addr = bdk_numa_get_address(node, rank_addr);
                    debug_print("Rank Address: 0x%lx\n", rank_addr);

                    for (wl_offset = sw_wlevel_offset; wl_offset >= 0; --wl_offset) {
                    //for (delay=30; delay>=0; delay-=2) { /* Top-Down */
                        for (delay = 0; delay < 32; delay += 2) {  /* Bottom-UP */
                            update_wlevel_rank_struct(&lmc_wlevel_rank, byte, delay);
                            debug_print("Testing byte %d delay %2d\n", byte, delay);
                            DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), lmc_wlevel_rank.u);
                            lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

                            BDK_CSR_WRITE(node, BDK_GTI_CWD_POKEX(bdk_get_core_num()), 0);

                            if (!test_dram_byte(rank_addr, 2048, byte, byte_bitmask)) {
                                ++passed;
                                if (passed == (1 + wl_offset)) { /* Look for consecutive working settings */
                                    debug_print("        byte %d(0x%lx) delay %2d Passed\n", byte, rank_addr, delay);
                                    if (wl_offset == 1) {
                                        byte_test_status[byte] = WL_SOFTWARE;
                                    } else if (wl_offset == 0) {
                                        byte_test_status[byte] = WL_SOFTWARE1;
                                    }
                                    break;
                                }
                            } else {
                                debug_print("        byte %d delay %2d Errors\n", byte, delay);
                                passed = 0;
                            }
                        } /* for (delay = 0; delay < 32; delay += 2) */
                        if (passed == (1 + wl_offset)) { /* Look for consecutive working settings */
                            break;
                        }
                    } /* for (wl_offset = sw_wlevel_offset; wl_offset >= 0; --wl_offset) */
                    if (passed == 0) {
                        /* Last resort. Use Rlevel settings to estimate
                           Wlevel if software write-leveling fails */
                        lmc_rlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_RLEVEL_RANKX(ddr_interface_num, rankx));
                        rlevel_to_wlevel(&lmc_rlevel_rank, &lmc_wlevel_rank, byte);
                    }
                } /* for (byte = 0; byte < 8; ++byte) */

                if (save_ecc_ena) {
                    /* ECC byte has to be estimated. Take the average of the two surrounding bytes. */
                    int test_byte8 = divide_nint(lmc_wlevel_rank.s.byte3
                                                 + lmc_wlevel_rank.s.byte4
                                                 + 2 /* round-up*/ , 2);
                    lmc_wlevel_rank.s.byte8 = test_byte8 & ~1; /* Use only even settings */
                    byte_test_status[8] = WL_ESTIMATED; /* Estimated delay */
                } else {
                    byte_test_status[8] = WL_HARDWARE; /* H/W delay value */
                    lmc_wlevel_rank.s.byte8 = lmc_wlevel_rank.s.byte0; /* ECC is not used */
                }

                /* Set delays for unused bytes to match byte 0. */
                for (byte=0; byte<8; ++byte) {
                    if ((ddr_interface_bytemask & (1 << byte)))
                        continue;
                    update_wlevel_rank_struct(&lmc_wlevel_rank, byte,
					      lmc_wlevel_rank.s.byte0);
                    byte_test_status[byte] = WL_SOFTWARE;
                }

            } /* if (bytes_failed) */

            DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), lmc_wlevel_rank.u);
            lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

            ddr_print("N%d.LMC%d.R%d: Wlevel Rank %#4x, 0x%016lX  : %2d%3s %2d%3s %2d%3s %2d%3s %2d%3s %2d%3s %2d%3s %2d%3s %2d%3s %s\n",
                      node, ddr_interface_num, rankx,
                      lmc_wlevel_rank.s.status,
                      lmc_wlevel_rank.u,
                      lmc_wlevel_rank.s.byte8, wl_status_strings[byte_test_status[8]],
                      lmc_wlevel_rank.s.byte7, wl_status_strings[byte_test_status[7]],
                      lmc_wlevel_rank.s.byte6, wl_status_strings[byte_test_status[6]],
                      lmc_wlevel_rank.s.byte5, wl_status_strings[byte_test_status[5]],
                      lmc_wlevel_rank.s.byte4, wl_status_strings[byte_test_status[4]],
                      lmc_wlevel_rank.s.byte3, wl_status_strings[byte_test_status[3]],
                      lmc_wlevel_rank.s.byte2, wl_status_strings[byte_test_status[2]],
                      lmc_wlevel_rank.s.byte1, wl_status_strings[byte_test_status[1]],
                      lmc_wlevel_rank.s.byte0, wl_status_strings[byte_test_status[0]],
                      (sw_wl_rank_status == WL_HARDWARE) ? "" : "(s)"
                      );

            if ((ddr_type == DDR4_DRAM) && (best_vref_values_count == 0)) {
                error_print("INFO: Training results poor, need retry on N%d.LMC%d.R%d. Resetting node...\n",
			    node, ddr_interface_num, rankx);
                bdk_wait_usec(500000);
                bdk_reset_chip(node);
            }

            active_rank++;
        } /* for (rankx = 0; rankx < dimm_count * 4; rankx++) */

        for (rankx = 0; rankx < dimm_count * 4;rankx++) {
            uint64_t value;
            int parameter_set = 0;
            if (!(rank_mask & (1 << rankx)))
                continue;

            lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));

            if (bdk_is_platform(BDK_PLATFORM_ASIM)) {
                parameter_set |= 1;

                lmc_wlevel_rank.s.byte8 = 0;
                lmc_wlevel_rank.s.byte7 = 0;
                lmc_wlevel_rank.s.byte6 = 0;
                lmc_wlevel_rank.s.byte5 = 0;
                lmc_wlevel_rank.s.byte4 = 0;
                lmc_wlevel_rank.s.byte3 = 0;
                lmc_wlevel_rank.s.byte2 = 0;
                lmc_wlevel_rank.s.byte1 = 0;
                lmc_wlevel_rank.s.byte0 = 0;
            }

            for (i=0; i<9; ++i) {
                if ((s = lookup_env_parameter("ddr%d_wlevel_rank%d_byte%d", ddr_interface_num, rankx, i)) != NULL) {
                    parameter_set |= 1;
                    value = strtoul(s, NULL, 0);

                    update_wlevel_rank_struct(&lmc_wlevel_rank, i, value);
                }
            }

            if ((s = lookup_env_parameter_ull("ddr%d_wlevel_rank%d", ddr_interface_num, rankx)) != NULL) {
                parameter_set |= 1;
                value = strtoull(s, NULL, 0);
                lmc_wlevel_rank.u = value;
            }

            if (parameter_set) {
                DRAM_CSR_WRITE(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx), lmc_wlevel_rank.u);
                lmc_wlevel_rank.u = BDK_CSR_READ(node, BDK_LMCX_WLEVEL_RANKX(ddr_interface_num, rankx));
		display_write_leveling_settings(node, ddr_interface_num, lmc_wlevel_rank, rankx);
            }
        } /* for (rankx = 0; rankx < dimm_count * 4;rankx++) */

        /* Enable 32-bit mode if required. */
        lmc_config.s.mode32b         = (! ddr_interface_64b);
        ddr_print("%-45s : %d\n", "MODE32B", lmc_config.s.mode32b);

        /* Restore the ECC configuration */
        lmc_config.s.ecc_ena = save_ecc_ena;
        DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(ddr_interface_num), lmc_config.u);

        /* Restore the l2 set configuration */
	if ((s = lookup_env_parameter("limit_l2_ways")) != NULL) {
            int ways = strtoul(s, NULL, 10);
            limit_l2_ways(node, ways, 1);
        } else {
            limit_l2_ways(node, bdk_l2c_get_num_assoc(node), 0);
        }
    }

#if ENABLE_DISPLAY_MPR_PAGE
    if (ddr_type == DDR4_DRAM) {
            Display_MPR_Page(node, rank_mask, ddr_interface_num, dimm_count, 2);
            Display_MPR_Page(node, rank_mask, ddr_interface_num, dimm_count, 0);
    }
#endif

#if 1 // was #ifdef CAVIUM_ONLY
    {
        int i;
        int setting[9];
        bdk_lmcx_dll_ctl3_t ddr_dll_ctl3;
        ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));

        for (i=0; i<9; ++i) {
	    SET_DDR_DLL_CTL3(dll90_byte_sel, ENCODE_DLL90_BYTE_SEL(i));
            DRAM_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	ddr_dll_ctl3.u);
            BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
            ddr_dll_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_DLL_CTL3(ddr_interface_num));
	    setting[i] = GET_DDR_DLL_CTL3(dll90_setting);
            debug_print("%d. LMC%d_DLL_CTL3[%d] = %016lx %d\n", i, ddr_interface_num,
                      GET_DDR_DLL_CTL3(dll90_byte_sel), ddr_dll_ctl3.u, setting[i]);
        }

        ddr_print("%-45s : %5d %5d %5d %5d %5d %5d %5d %5d %5d\n",
                  "DLL90 Setting 8:0",
                  setting[8], setting[7], setting[6], setting[5], setting[4],
                  setting[3], setting[2], setting[1], setting[0]);

        //BDK_CSR_WRITE(node, BDK_LMCX_DLL_CTL3(ddr_interface_num),	save_ddr_dll_ctl3.u);
    }
#endif  /* CAVIUM_ONLY */

    process_custom_dll_offsets(node, ddr_interface_num, "ddr_dll_write_offset",
			       custom_lmc_config->dll_write_offset, "ddr%d_dll_write_offset_byte%d", 1);
    process_custom_dll_offsets(node, ddr_interface_num, "ddr_dll_read_offset", 
			       custom_lmc_config->dll_read_offset,  "ddr%d_dll_read_offset_byte%d",  2);

#ifdef ENABLE_AUTO_SET_DLL
    /* Experimental code to try to automatically adjust the DLL offset */
    if ((s = lookup_env_parameter("ddr_auto_set_dll_offset")) != NULL) {
        /* Disable l2 sets for DRAM testing */
        limit_l2_ways(node, 0, 0);

        auto_set_dll_offset(node,  1 /* 1=write */, ddr_interface_num, ddr_interface_64b);
        auto_set_dll_offset(node,  2 /* 2=read */, ddr_interface_num, ddr_interface_64b);

        /* Restore the l2 set configuration */
	if ((s = lookup_env_parameter("limit_l2_ways")) != NULL) {
            int ways = strtoul(s, NULL, 10);
            limit_l2_ways(node, ways, 1);
        } else {
            limit_l2_ways(node, bdk_l2c_get_num_assoc(node), 0);
        }
    }
#endif  /* ENABLE_AUTO_SET_DLL */

    /*
     * 4.8.11 Final LMC Initialization
     * 
     * Early LMC initialization, LMC write-leveling, and LMC read-leveling
     * must be completed prior to starting this final LMC initialization.
     * 
     * LMC hardware updates the LMC(0)_SLOT_CTL0, LMC(0)_SLOT_CTL1,
     * LMC(0)_SLOT_CTL2 CSRs with minimum values based on the selected
     * readleveling and write-leveling settings. Software should not write
     * the final LMC(0)_SLOT_CTL0, LMC(0)_SLOT_CTL1, and LMC(0)_SLOT_CTL2
     * values until after the final read-leveling and write-leveling settings
     * are written.
     * 
     * Software must ensure the LMC(0)_SLOT_CTL0, LMC(0)_SLOT_CTL1, and
     * LMC(0)_SLOT_CTL2 CSR values are appropriate for this step. These CSRs
     * select the minimum gaps between read operations and write operations
     * of various types.
     * 
     * Software must not reduce the values in these CSR fields below the
     * values previously selected by the LMC hardware (during write-leveling
     * and read-leveling steps above).
     * 
     * All sections in this chapter may be used to derive proper settings for
     * these registers.
     * 
     * For minimal read latency, L2C_CTL[EF_ENA,EF_CNT] should be programmed
     * properly. This should be done prior to the first read.
     */

#ifdef ENABLE_SLOT_CTL_ACCESS
    {
	bdk_lmcx_slot_ctl0_t lmc_slot_ctl0;
	bdk_lmcx_slot_ctl1_t lmc_slot_ctl1;
	bdk_lmcx_slot_ctl2_t lmc_slot_ctl2;
	bdk_lmcx_slot_ctl3_t lmc_slot_ctl3;

        lmc_slot_ctl0.u = BDK_CSR_READ(node, BDK_LMCX_SLOT_CTL0(ddr_interface_num));
        lmc_slot_ctl1.u = BDK_CSR_READ(node, BDK_LMCX_SLOT_CTL1(ddr_interface_num));
        lmc_slot_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_SLOT_CTL2(ddr_interface_num));
        lmc_slot_ctl3.u = BDK_CSR_READ(node, BDK_LMCX_SLOT_CTL3(ddr_interface_num));

        ddr_print("%-45s : 0x%016lx\n", "LMC_SLOT_CTL0", lmc_slot_ctl0.u);
        ddr_print("%-45s : 0x%016lx\n", "LMC_SLOT_CTL1", lmc_slot_ctl1.u);
        ddr_print("%-45s : 0x%016lx\n", "LMC_SLOT_CTL2", lmc_slot_ctl2.u);
        ddr_print("%-45s : 0x%016lx\n", "LMC_SLOT_CTL3", lmc_slot_ctl3.u);

	// for now, look only for SLOT_CTL1 envvar for override of contents
	if ((s = lookup_env_parameter("ddr%d_slot_ctl1", ddr_interface_num)) != NULL) {
	    int slot_ctl1_incr = strtoul(s, NULL, 0);
	    // validate the value
	    if ((slot_ctl1_incr < 1) || (slot_ctl1_incr > 3)) {
		error_print("ddr%d_slot_ctl1 illegal value (%d); must be 1-3\n",
			    ddr_interface_num, slot_ctl1_incr);
	    } else {

#define INCR(csr, chip, field, incr)  \
		csr.chip.field = (csr.chip.field < (64 - incr)) ? (csr.chip.field + incr) : 63

		// modify all the SLOT_CTL1 fields by the increment, for now...
		// but make sure the value will not overflow!!!
		INCR(lmc_slot_ctl1, s, r2r_xrank_init, slot_ctl1_incr);
		INCR(lmc_slot_ctl1, s, r2w_xrank_init, slot_ctl1_incr);
		INCR(lmc_slot_ctl1, s, w2r_xrank_init, slot_ctl1_incr);
		INCR(lmc_slot_ctl1, s, w2w_xrank_init, slot_ctl1_incr);
		DRAM_CSR_WRITE(node, BDK_LMCX_SLOT_CTL1(ddr_interface_num), lmc_slot_ctl1.u);
	    }
	}
    }
#endif /* ENABLE_SLOT_CTL_ACCESS */
    {
        /* Clear any residual ECC errors */
        int num_tads = 1;
        int tad;

        DRAM_CSR_WRITE(node, BDK_LMCX_INT(ddr_interface_num), -1ULL);
        BDK_CSR_READ(node, BDK_LMCX_INT(ddr_interface_num));

        for (tad=0; tad<num_tads; tad++)
            DRAM_CSR_WRITE(node, BDK_L2C_TADX_INT_W1C(tad), BDK_CSR_READ(node, BDK_L2C_TADX_INT_W1C(tad)));

        ddr_print("%-45s : 0x%08lx\n", "LMC_INT",
                  BDK_CSR_READ(node, BDK_LMCX_INT(ddr_interface_num)));
    }

    return(mem_size_mbytes);
}

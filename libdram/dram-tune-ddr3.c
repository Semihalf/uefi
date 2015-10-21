#include <bdk.h>
#include "dram-internal.h"

#if 0
/*
 * Suggested testing patterns.
 */
static const uint64_t test_pattern_2[] = {
    0xFFFFFFFFFFFFFFFFULL,
    0xAAAAAAAAAAAAAAAAULL,
    0xFFFFFFFFFFFFFFFFULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0xFFFFFFFFFFFFFFFFULL,
    0xAAAAAAAAAAAAAAAAULL,
    0xFFFFFFFFFFFFFFFFULL,
    0x5555555555555555ULL,
    0xFFFFFFFFFFFFFFFFULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xFFFFFFFFFFFFFFFFULL,
    0x5555555555555555ULL,
};
 /*
 *  or possibly
 */
static const uint64_t test_pattern_3[] = {
    0xFDFDFDFDFDFDFDFDULL,
    0x8787878787878787ULL,
    0xFEFEFEFEFEFEFEFEULL,
    0xC3C3C3C3C3C3C3C3ULL,
    0x7F7F7F7F7F7F7F7FULL,
    0xE1E1E1E1E1E1E1E1ULL,
    0xBFBFBFBFBFBFBFBFULL,
    0xF0F0F0F0F0F0F0F0ULL,
    0xDFDFDFDFDFDFDFDFULL,
    0x7878787878787878ULL,
    0xEFEFEFEFEFEFEFEFULL,
    0x3C3C3C3C3C3C3C3CULL,
    0xF7F7F7F7F7F7F7F7ULL,
    0x1E1E1E1E1E1E1E1EULL,
    0xFBFBFBFBFBFBFBFBULL,
    0x0F0F0F0F0F0F0F0FULL,
};

static const uint64_t test_pattern_1[] = {
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
#if 0 // only need a cacheline size
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
    0xAAAAAAAAAAAAAAAAULL,
    0x5555555555555555ULL,
#endif
};

// setup default for test pattern array
static const uint64_t *dram_tune_test_pattern = test_pattern_1;
#endif

// set this to 1 to shorten the testing to exit when all byte lanes have errors
// having this at 0 forces the testing to take place over the entire range every iteration
#define EXIT_WHEN_ALL_LANES_HAVE_ERRORS 0

#define DEFAULT_TEST_BURSTS 7 // FIXME: this is what works so far...
int dram_tune_use_bursts = DEFAULT_TEST_BURSTS;

// dram_tune_rank_offset is used to offset the second area used in test_dram_mem_xor.
//
// If only a single-rank DIMM, the offset will be 256MB from the start of the first area,
//  which is more than enough for the restricted looping/address range actually tested...
//
// If a 2-rank DIMM, the offset will be the size of a rank's address space, so the effect
//  will be to have the first and second areas in different ranks on the same DIMM.
//
// So, we default this to single-rank, and it will be overridden when 2-ranks are detected.
//

// FIXME: ASSUME that we have DIMMS no less than 4GB in size

// offset to first area that avoids any boot stuff in low range (below 256MB)
#define AREA_BASE_OFFSET (1ULL << 28) // bit 28 always ON

// offset to duplicate area; may coincide with rank 1 base address for 2-rank 4GB DIMM
#define AREA_DUPE_OFFSET (1ULL << 31) // bit 31 always ON

// defaults to DUPE, but will be set elsewhere to offset to next RANK if multi-rank DIMM
static uint64_t dram_tune_rank_offset = AREA_DUPE_OFFSET; // default

// defaults to 0, but will be set elsewhere to the address offset to next DIMM if multi-slot
static uint64_t dram_tune_dimm_offset = 0; // default

static int test_dram_mem_xor(uint64_t p, uint64_t bitmask)
{
    uint64_t p1, p2, d1, d2;
    uint64_t v, v1;
    uint64_t p2offset = dram_tune_rank_offset; // FIXME?
    uint64_t datamask;
    uint64_t xor;
    uint64_t i, j, k;
    uint64_t ii;
    int errors = 0;
    //uint64_t index;
    uint64_t pattern1 = bdk_rng_get_random64();
    uint64_t pattern2 = 0;

    // Byte lanes may be clear in the mask to indicate no testing on that lane.
    datamask = bitmask;

    /* Add offset to both test regions to not clobber boot stuff
     * when running from L2 for NAND boot.
     */
    p += AREA_BASE_OFFSET; // make sure base is out of the way of boot

#define II_INC (1ULL << 29)
#define II_MAX (1ULL << 31)
#define K_INC  (1ULL << 14)
#define K_MAX  (1ULL << 20)
#define J_INC  (1ULL <<  9)
#define J_MAX  (1ULL << 12)
#define I_INC  (1ULL <<  3)
#define I_MAX  (1ULL <<  7)

    BDK_PREFETCH(p           , BDK_CACHE_LINE_SIZE);
    BDK_PREFETCH(p + p2offset, BDK_CACHE_LINE_SIZE);

    // loops are ordered so that only a single 64-bit slot is written to each cacheline at one time,
    // then the cachelines are forced out; this should maximize read/write traffic
    for (ii = 0; ii < II_MAX; ii += II_INC) { // FIXME? extend the range of memory tested!!
	for (k = 0; k < K_MAX; k += K_INC) {
	    for (i = 0; i < I_MAX; i += I_INC) {
		for (j = 0; j < J_MAX; j += J_INC) {

		    p1 = p + ii + k + j;
		    p2 = p1 + p2offset;

		    BDK_PREFETCH(p1 + J_INC, BDK_CACHE_LINE_SIZE);
		    BDK_PREFETCH(p2 + J_INC, BDK_CACHE_LINE_SIZE);
	    
		    v = pattern1 * (p1 + i);
		    v1 = v; // write the same thing to both areas

		    __bdk_dram_write64(p1 + i, v);
		    __bdk_dram_write64(p2 + i, v1);

		    BDK_CACHE_WBI_L2(p1);
		    BDK_CACHE_WBI_L2(p2);
		}
	    }
	}
    } /* for (ii = 0; ii < (1ULL << 31); ii += (1ULL << 29)) */

#if 0
    __bdk_dram_flush_to_mem_range(p, p + (1ULL << 20)); // max_addr is start + where k stops...
    __bdk_dram_flush_to_mem_range(p + p2offset, p + p2offset + (1ULL << 20)); // max_addr is start + where k stops...
#endif
    BDK_DCACHE_INVALIDATE;

    /* Make a series of passes over the memory areas. */

    for (int burst = 0; burst < dram_tune_use_bursts; burst++)
    {
	uint64_t this_pattern = bdk_rng_get_random64();
	pattern2 ^= this_pattern;

        /* XOR the data with a random value, applying the change to both
         * memory areas.
         */
	BDK_PREFETCH(p           , BDK_CACHE_LINE_SIZE);
	BDK_PREFETCH(p + p2offset, BDK_CACHE_LINE_SIZE);

	for (ii = 0; ii < II_MAX; ii += II_INC) { // FIXME? extend the range of memory tested!!
	    for (k = 0; k < K_MAX; k += K_INC) {
		for (i = 0; i < I_MAX; i += I_INC) { // FIXME: rearranged, did not make much difference?
		    for (j = 0; j < J_MAX; j += J_INC) {

			p1 = p + ii + k + j;
			p2 = p1 + p2offset;

			BDK_PREFETCH(p1 + J_INC, BDK_CACHE_LINE_SIZE);
			BDK_PREFETCH(p2 + J_INC, BDK_CACHE_LINE_SIZE);
	    
			v  = __bdk_dram_read64(p1 + i) ^ this_pattern;
			v1 = __bdk_dram_read64(p2 + i) ^ this_pattern;

			__bdk_dram_write64(p1 + i, v);
			__bdk_dram_write64(p2 + i, v1);

			BDK_CACHE_WBI_L2(p1);
			BDK_CACHE_WBI_L2(p2);
		    }
		}
	    }
	} /* for (ii = 0; ii < (1ULL << 31); ii += (1ULL << 29)) */

#if 0
	__bdk_dram_flush_to_mem_range(p, p + (1ULL << 20)); // max_addr is start + where k stops...
	__bdk_dram_flush_to_mem_range(p + p2offset, p + p2offset + (1ULL << 20)); // max_addr is start + where k stops...
#endif
        BDK_DCACHE_INVALIDATE;

	BDK_PREFETCH(p           , BDK_CACHE_LINE_SIZE);
	BDK_PREFETCH(p + p2offset, BDK_CACHE_LINE_SIZE);

        /* Look for differences in the areas. If there is a mismatch, reset
         * both memory locations with the same pattern. Failing to do so
         * means that on all subsequent passes the pair of locations remain
         * out of sync giving spurious errors.
         */
	// FIXME: change the loop order so that an entire cache line is compared at one time
	// FIXME: this is so that a read error that occurs *anywhere* on the cacheline will be caught,
	// FIXME: rather than comparing only 1 cacheline slot at a time, where an error on a different
	// FIXME: slot will be missed that time around
	// Does the above make sense?

	for (ii = 0; ii < II_MAX; ii += II_INC) { // FIXME? extend the range of memory tested!!
	    for (k = 0; k < K_MAX; k += K_INC) {
		for (j = 0; j < J_MAX; j += J_INC) {

		    p1 = p + ii + k + j;
		    p2 = p1 + p2offset;

		    BDK_PREFETCH(p1 + J_INC, BDK_CACHE_LINE_SIZE);
		    BDK_PREFETCH(p2 + J_INC, BDK_CACHE_LINE_SIZE);
	    
		    // process entire cachelines in the innermost loop
		    for (i = 0; i < I_MAX; i += I_INC) {

			v = ((p1 + i) * pattern1) ^ pattern2; // FIXME: this should predict what we find...???
			d1 = __bdk_dram_read64(p1 + i);
			d2 = __bdk_dram_read64(p2 + i);

			xor = ((d1 ^ v) | (d2 ^ v)) & datamask; // union of error bits only in active byte lanes

			int bybit = 1;
			uint64_t bymsk = 0xffULL; // start in byte lane 0
			while (xor != 0) {
			    debug_print("ERROR(%03d): [0x%016lX] [0x%016lX]  expected 0x%016lX d1 %016lX d2 %016lX\n",
					burst, p1, p2, v, d1, d2);
			    if (xor & bymsk) { // error(s) in this lane
				errors |= bybit; // set the byte error bit
				xor &= ~bymsk; // clear byte lane in error bits
				datamask &= ~bymsk; // clear the byte lane in the mask
#if EXIT_WHEN_ALL_LANES_HAVE_ERRORS
				if (datamask == 0) { // nothing left to do
				    return errors; // completely done when errors found in all byte lanes in datamask
				}
#endif /* EXIT_WHEN_ALL_LANES_HAVE_ERRORS */
			    }
			    bymsk <<= 8; // move mask into next byte lane
			    bybit <<= 1; // move bit into next byte position
			}
		    }
		    BDK_CACHE_WBI_L2(p1);
		    BDK_CACHE_WBI_L2(p2);
		}
	    }
	} /* for (ii = 0; ii < (1ULL << 31); ii += (1ULL << 29)) */
    } /* for (int burst = 0; burst < dram_tune_use_bursts; burst++) */

    return errors;
}

#if 0
static int test_dram_mem_rows(uint64_t p, uint64_t bitmask)
{
    uint64_t p1, p2, d1, d2;
    uint64_t v, v1;
    uint64_t p2offset = dram_tune_rank_offset; // FIXME?
    uint64_t datamask;
    uint64_t xor;
    int i, j, k, ii;
    int errors = 0;
    int index;
    uint64_t pattern1 = 0; // FIXME: maybe this could be from a table?
    uint64_t pattern2;

    // Byte lanes may be clear in the mask to indicate no testing on that lane.
    datamask = bitmask;

    /* Add offset to both test regions to not clobber boot stuff
     * when running from L2 for NAND boot.
     */
    p += 0x10000000; // FIXME? was: 0x4000000; // make sure base is out of the way of cores for tuning

    pattern2 = pattern1;
    for (k = 0; k < (1 << 20); k += (1 << 14)) {
	for (j = 0; j < (1 << 12); j += (1 << 9)) {
	    for (i = 0; i < (1 << 7); i += 8) {
		index = i + j + k;
		p1 = p + index;
		p2 = p1 + p2offset;

		v = pattern2;
		v1 = v; // write the same thing to same slot in both cachelines
		pattern2 = ~pattern2; // flip bits for next slots

		__bdk_dram_write64(p1, v);
		__bdk_dram_write64(p2, v1);
	    }
#if 1
	    BDK_CACHE_WBI_L2(p1);
	    BDK_CACHE_WBI_L2(p2);
#endif
	}
    }

#if 0
    __bdk_dram_flush_to_mem_range(p, p + (1ULL << 20)); // max_addr is start + where k stops...
    __bdk_dram_flush_to_mem_range(p + p2offset, p + p2offset + (1ULL << 20)); // max_addr is start + where k stops...
#endif
    BDK_DCACHE_INVALIDATE;

    /* Make a series of passes over the memory areas. */

    for (int burst = 0; burst < dram_tune_use_bursts; burst++)
    {
        /* just read and flip the bits applying the change to both
         * memory areas.
         */
	for (k = 0; k < (1 << 20); k += (1 << 14)) {
	    for (j = 0; j < (1 << 12); j += (1 << 9)) {
		for (i = 0; i < (1 << 7); i += 8) {
		    index = i + j + k;
		    p1 = p + index;
		    p2 = p1 + p2offset;

		    v  = ~__bdk_dram_read64(p1);
		    v1 = ~__bdk_dram_read64(p2);

		    __bdk_dram_write64(p1, v);
		    __bdk_dram_write64(p2, v1);
		}
#if 1
		BDK_CACHE_WBI_L2(p1);
		BDK_CACHE_WBI_L2(p2);
#endif
	    }
	}

#if 0
	__bdk_dram_flush_to_mem_range(p, p + (1ULL << 20)); // max_addr is start + where k stops...
	__bdk_dram_flush_to_mem_range(p + p2offset, p + p2offset + (1ULL << 20)); // max_addr is start + where k stops...
#endif
        BDK_DCACHE_INVALIDATE;

        /* Look for differences in the areas. If there is a mismatch, reset
         * both memory locations with the same pattern. Failing to do so
         * means that on all subsequent passes the pair of locations remain
         * out of sync giving spurious errors.
         */

	// FIXME: change the loop order so that an entire cache line is compared at one time
	// FIXME: this is so that a read error that occurs *anywhere* on the cacheline will be caught,
	// FIXME: rather than comparing only 1 cacheline slot at a time, where an error on a different
	// FIXME: slot will be missed that time around
	// Does the above make sense?

	pattern2 = ~pattern1; // slots have been flipped by the above loop

	for (k = 0; k < (1 << 20); k += (1 << 14)) {
	    for (j = 0; j < (1 << 12); j += (1 << 9)) {
		for (i = 0; i < (1 << 7); i += 8) {
		    index = i + j + k;
		    p1 = p + index;
		    p2 = p1 + p2offset;

		    v = pattern2; // FIXME: this should predict what we find...???
		    d1 = __bdk_dram_read64(p1);
		    d2 = __bdk_dram_read64(p2);
		    pattern2 = ~pattern2; // flip for next slot

		    xor = ((d1 ^ v) | (d2 ^ v)) & datamask; // union of error bits only in active byte lanes

		    int bybit = 1;
		    uint64_t bymsk = 0xffULL; // start in byte lane 0
		    while (xor != 0) {
			debug_print("ERROR(%03d): [0x%016lX] [0x%016lX]  expected 0x%016lX d1 %016lX d2 %016lX\n",
				  burst, p1, p2, v, d1, d2);
			if (xor & bymsk) { // error(s) in this lane
			    errors |= bybit; // set the byte error bit
			    xor &= ~bymsk; // clear byte lane in error bits
			    datamask &= ~bymsk; // clear the byte lane in the mask
#if EXIT_WHEN_ALL_LANES_HAVE_ERRORS
			    if (datamask == 0) { // nothing left to do
				return errors; // completely done when errors found in all byte lanes in datamask
			    }
#endif /* EXIT_WHEN_ALL_LANES_HAVE_ERRORS */
			}
			bymsk <<= 8; // move mask into next byte lane
			bybit <<= 1; // move bit into next byte position
		    }
		}
	    }
	}
	pattern1 = ~pattern1; // flip the starting pattern for the next burst

    } /* for (int burst = 0; burst < dram_tune_use_bursts; burst++) */
    return errors;
}
#endif

// cores to use
#define DEFAULT_USE_CORES 44   // FIXME: was (1 << CORE_BITS)
int dram_tune_use_cores = DEFAULT_USE_CORES; // max cores to use, override available
int dram_tune_max_cores; // max cores available on a node
#define CORE_SHIFT 22          // FIXME: offset into rank_address passed to test_dram_byte

static  int64_t test_dram_byte_threads_done;
static uint64_t test_dram_byte_threads_errs;
static uint64_t test_dram_byte_lmc_errs[4];

#define USE_SPINLOCKS_NOT_ATOMICS 0
#if USE_SPINLOCKS_NOT_ATOMICS
bdk_spinlock_t test_dram_byte_error_lock;
#endif

typedef struct
{
    bdk_node_t node;
    uint64_t num_lmcs;
    uint64_t byte_mask;
} test_dram_byte_info_t;

test_dram_byte_info_t test_dram_byte_info;

static void test_dram_byte_thread(int arg, void *arg1)
{
    test_dram_byte_info_t *test_info = arg1;
    int core = arg;
    uint64_t errs;
    bdk_node_t node = test_info->node;
    int lmc = (core % test_info->num_lmcs); // FIXME: map core numbers into hopefully equal groups per LMC
    
    uint64_t rank_address = (lmc << 7);
    uint64_t bytemask = test_info->byte_mask;

    /* Figure out our work memory range.
     *
     * Note: rank_address above just provides the physical offset which determines
     * specific LMC portions of the address space and does not have the node bits set.
     */
    rank_address  = bdk_numa_get_address(node, rank_address); // map to node
    rank_address |= (core << CORE_SHIFT); // FIXME: also put full core into address
    if (dram_tune_dimm_offset) { // if multi-slot in some way, choose a DIMM for the core
	rank_address |= (core & (1 << (test_info->num_lmcs >> 1))) ? dram_tune_dimm_offset : 0;
    }

    debug_print("Node %d, core %d, Testing area 1 at 0x%011lx, area 2 at 0x%011lx\n",
		node, core, rank_address + AREA_BASE_OFFSET,
		rank_address + AREA_BASE_OFFSET + dram_tune_rank_offset);

    errs = test_dram_mem_xor(rank_address, bytemask);
    //errs = test_dram_mem_rows(rank_address, bytemask);

    /* Report that we're done */
    debug_print("Core %d on LMC %d node %d done with test_dram_byte with 0x%lx errs\n",
	      core, node, errs);

    if (errs) {
#if USE_SPINLOCKS_NOT_ATOMICS
	bdk_spinlock_lock(&test_dram_byte_error_lock);
	test_dram_byte_threads_errs  |= errs;
	test_dram_byte_lmc_errs[lmc] |= errs;	
	bdk_spinlock_unlock(&test_dram_byte_error_lock);
#else
	bdk_atomic_fetch_and_bset64_nosync(&test_dram_byte_threads_errs, errs);
	bdk_atomic_fetch_and_bset64_nosync(&test_dram_byte_lmc_errs[lmc], errs);
#endif
    }

    bdk_atomic_add64_nosync(&test_dram_byte_threads_done, 1);

    return;
}

static int
run_test_dram_byte_threads(bdk_node_t node, int num_lmcs, uint64_t bytemask)
{
    test_dram_byte_info_t *test_info = &test_dram_byte_info;
    int total_count = 0;

    test_info->node = node;
    test_info->num_lmcs = num_lmcs;
    test_info->byte_mask = bytemask;

    // init some global data
    bdk_atomic_set64(&test_dram_byte_threads_done, 0);
    bdk_atomic_set64((int64_t *)&test_dram_byte_threads_errs, 0);
    // FIXME? do we need to use atomics for this, and the above?
    memset(test_dram_byte_lmc_errs, 0, sizeof(test_dram_byte_lmc_errs));

#if USE_SPINLOCKS_NOT_ATOMICS
    bdk_spinlock_init(&test_dram_byte_error_lock); // FIXME?
#endif

    /* Start threads for cores on the node */
    if (bdk_numa_exists(node)) {
	debug_print("Starting %d threads for test_dram_byte\n", dram_tune_use_cores);
	for (int core = 0; core < dram_tune_use_cores; core++) {
	    if (bdk_thread_create(node, 0, test_dram_byte_thread, core, (void *)test_info, 0)) {
		bdk_error("Failed to create thread %d for test_dram_byte\n", core);
	    } else {
		total_count++;
	    }
	}
    }

    /* Wait for threads to finish */
    while (bdk_atomic_get64(&test_dram_byte_threads_done) < total_count)
	bdk_thread_yield();

    // NOTE: this is the summary of errors across all LMCs
    return (int)bdk_atomic_get64((int64_t *)&test_dram_byte_threads_errs);
}

#define DEFAULT_SAMPLE_GRAN 5 // sample for errors every N offset values (was 3)
#define MIN_BYTE_OFFSET -63
#define MAX_BYTE_OFFSET +63
int dram_tune_use_gran = DEFAULT_SAMPLE_GRAN;

static void auto_set_dll_offset(bdk_node_t node, int dll_offset_mode,
				int num_lmcs, int ddr_interface_64b)
{
    int byte_offset;
    //unsigned short result[9];
    int byte;
    int byte_delay_start[4][9];
    int byte_delay_count[4][9];
    int byte_delay_best_start[4][9];
    int byte_delay_best_count[4][9];
    char sbuffer[50];
    int this_rodt;
    uint64_t percent_x10;
    uint64_t ops_sum[4], dclk_sum[4];
    uint64_t start_dram_dclk[4], stop_dram_dclk[4];
    uint64_t start_dram_ops[4], stop_dram_ops[4];
    int errors, tot_errors;
    int lmc;

    int start_offset, end_offset, incr_offset;

    if (dram_tune_use_gran != DEFAULT_SAMPLE_GRAN) {
	ddr_print("N%d: changing sample granularity from %d to %d\n",
		  node, DEFAULT_SAMPLE_GRAN, dram_tune_use_gran);
    }
    // ensure sample is taken at 0
    start_offset = MIN_BYTE_OFFSET - (MIN_BYTE_OFFSET % dram_tune_use_gran);
    end_offset   = MAX_BYTE_OFFSET - (MAX_BYTE_OFFSET % dram_tune_use_gran);
    incr_offset  = dram_tune_use_gran;

    memset(ops_sum, 0, sizeof(ops_sum));
    memset(dclk_sum, 0, sizeof(dclk_sum));
    memset(byte_delay_start, 0, sizeof(byte_delay_start));
    memset(byte_delay_count, 0, sizeof(byte_delay_count));
    memset(byte_delay_best_start, 0, sizeof(byte_delay_best_start));
    memset(byte_delay_best_count, 0, sizeof(byte_delay_best_count));

    // FIXME: must revise this for 2-slot!!!
    // FIXME? consult LMC0 only
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(0));
    if (lmcx_config.s.rank_ena) { // replace the default offset when there is more than 1 rank...
	dram_tune_rank_offset = 1ull << (28 + lmcx_config.s.pbank_lsb - lmcx_config.s.rank_ena + (num_lmcs/2));
	ddr_print("N%d: auto_set_dll_offset: changing rank offset to 0x%lx\n", node, dram_tune_rank_offset);
    }
    if (lmcx_config.s.init_status & 0x0c) { // bit 2 or 3 set indicates 2 DIMMs
	dram_tune_dimm_offset = 1ull << (28 + lmcx_config.s.pbank_lsb + (num_lmcs/2));
	ddr_print("N%d: auto_set_dll_offset: changing dimm offset to 0x%lx\n", node, dram_tune_dimm_offset);
    }

    // FIXME? do this for LMC0 only
    BDK_CSR_INIT(comp_ctl2, node, BDK_LMCX_COMP_CTL2(0));
    this_rodt = comp_ctl2.s.rodt_ctl;

    // construct the bytemask
    int bytes_todo = (ddr_interface_64b) ? 0xff : 0x0f; // FIXME: hack?
    uint64_t bytemask = 0;
    for (byte = 0; byte < 8; ++byte) {
	uint64_t bitmask;
	if (bytes_todo & (1 << byte)) {
	    bitmask = ((!ddr_interface_64b) && (byte == 4)) ? 0x0f: 0xff;
	    bytemask |= bitmask << (8*byte); // set the bytes bits in the bytemask 
	}
    } /* for (byte = 0; byte < 8; ++byte) */

    // now loop through all legal values for the DLL byte offset...

    for (byte_offset = start_offset; byte_offset <= end_offset; byte_offset += incr_offset) {

	// do the setup on active LMCs
	for (lmc = 0; lmc < num_lmcs; lmc++) {
	    change_dll_offset_enable(node, lmc, 0);

	    // set all byte lanes at once
	    load_dll_offset(node, lmc, dll_offset_mode, byte_offset, 10 /* All bytes at once */);
	    // but then clear the ECC byte lane so it should be neutral for the test...
	    load_dll_offset(node, lmc, dll_offset_mode, 0, 8);

	    change_dll_offset_enable(node, lmc, 1);

	    // record start cycle CSRs here for utilization measure
	    start_dram_dclk[lmc] = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(lmc));
	    start_dram_ops[lmc]  = BDK_CSR_READ(node, BDK_LMCX_OPS_CNT(lmc));
	} /* for (lmc = 0; lmc < num_lmcs; lmc++) */

	bdk_watchdog_poke();

	// run the test(s)
	// only 1 call should be enough, let the bursts, etc, control the load...  
	tot_errors = run_test_dram_byte_threads(node, num_lmcs, bytemask);

	for (lmc = 0; lmc < num_lmcs; lmc++) {
	    // record stop cycle CSRs here for utilization measure
	    stop_dram_dclk[lmc] = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(lmc));
	    stop_dram_ops[lmc]  = BDK_CSR_READ(node, BDK_LMCX_OPS_CNT(lmc));

	    // accumulate...
	    ops_sum[lmc]  += stop_dram_ops[lmc]  - start_dram_ops[lmc];
	    dclk_sum[lmc] += stop_dram_dclk[lmc] - start_dram_dclk[lmc];

	    errors = test_dram_byte_lmc_errs[lmc];

	    // check errors by byte
	    for (byte = 0; byte < 8; ++byte) {
		if (!(bytes_todo & (1 << byte))) // is this byte lane to be done
		    continue; // no

		if (errors & (1 << byte)) { // yes, an error in this byte lane
		    if (byte_delay_count[lmc][byte] > 0) { // had started run
			byte_delay_count[lmc][byte] = 0; // stop now
		    }
		    // FIXME: else had not started run - nothing else to do?
		} else { // no error in this byte lane
		    if (byte_delay_count[lmc][byte] == 0) { // first success, set run start
			byte_delay_start[lmc][byte] = byte_offset;
		    }
		    byte_delay_count[lmc][byte] += incr_offset; // bump run length

		    if (byte_delay_count[lmc][byte] > byte_delay_best_count[lmc][byte]) {
			byte_delay_best_count[lmc][byte] = byte_delay_count[lmc][byte];
			byte_delay_best_start[lmc][byte] = byte_delay_start[lmc][byte];
		    }
		}
	    } /* for (byte = 0; byte < 8; ++byte) */

	    // only print when there are errors and verbose...
	    if (errors) {
		debug_print("DLL %s Offset Test %3d: errors 0x%x\n",
			    dll_offset_mode == 1 ? "Write" : "Read",
			    byte_offset, errors);
	    }
	} /* for (lmc = 0; lmc < num_lmcs; lmc++) */

    } /* for (byte_offset=-63; byte_offset<63; byte_offset += BYTE_OFFSET_INCR) */

    // done with testing, load up the offsets we found...
    for (lmc = 0; lmc < num_lmcs; lmc++) {
	// disable offsets while we load...
	change_dll_offset_enable(node, lmc, 0);

	// first print and load the offset values themselves
	sprintf(sbuffer, "N%d.LMC%d: DLL %s Offset Delay (RODT%d)", node, lmc,
		dll_offset_mode == 1 ? "Write" : "Read ", this_rodt);
	printf("%-45s : ", sbuffer); // FIXME: force print
	for (byte = 8; byte >= 0; --byte) { // print in "normal" reverse index order
	    byte_offset =  byte_delay_best_start[lmc][byte] +
		((byte_delay_best_count[lmc][byte] - incr_offset) / 2); // adj by incr
	    printf(" %3d", byte_offset); // FIXME: force print

	    load_dll_offset(node, lmc, dll_offset_mode, byte_offset, byte);

	}
	printf("\n"); // FIXME: force print

	// re-enable the offsets now that we are done loading
	change_dll_offset_enable(node, lmc, 1);

#if 1
	// next print the window counts
	sprintf(sbuffer, "N%d.LMC%d: DLL %s Offset Count (RODT%d)", node, lmc,
		dll_offset_mode == 1 ? "Write" : "Read ", this_rodt);
	printf("%-45s : ", sbuffer); // FIXME: force print
	for (byte = 8; byte >= 0; --byte) { // print in "normal" reverse index order
	    printf(" %3d", byte_delay_best_count[lmc][byte]); // FIXME: force print
	}
	printf("\n"); // FIXME: force print
#endif
    } /* for (lmc = 0; lmc < num_lmcs; lmc++) */

    // finally, print the utilizations all together
    for (lmc = 0; lmc < num_lmcs; lmc++) {
	percent_x10 = ops_sum[lmc] * 1000 / dclk_sum[lmc];
	printf("N%d.LMC%d: ops %lu, cycles %lu, used %lu.%lu%%\n",
	       node, lmc, ops_sum[lmc], dclk_sum[lmc], percent_x10 / 10, percent_x10 % 10);
    } /* for (lmc = 0; lmc < num_lmcs; lmc++) */

    // run the test one last time 
    // print whether there are errors or not, but only when verbose...
    bdk_watchdog_poke();
    tot_errors = run_test_dram_byte_threads(node, num_lmcs, bytemask);
    printf("DLL %s Offset Final Test: errors 0x%x\n",
	   dll_offset_mode == 1 ? "Write" : "Read", tot_errors);
}

#define USE_L2_WAYS_LIMIT 0 // non-zero to enable L2 ways limiting

/*
 * Automatically adjust the DLL offset for the data bytes
 */
int perform_dll_offset_tuning(bdk_node_t node, int dll_offset_mode)
{
    int ddr_interface_64b;
    int save_ecc_ena[4];
    bdk_lmcx_config_t lmc_config;
    int lmc, num_lmcs = __bdk_dram_get_num_lmc(node);
    const char *s;
#if USE_L2_WAYS_LIMIT
    int ways, ways_print = 0;
#endif
    int dram_tune_use_rodt = -1, save_rodt[4];
    bdk_lmcx_comp_ctl2_t comp_ctl2;
    int loops = 1, loop;

    // enable all the cores on this node
    bdk_init_cores(node, 0);
    dram_tune_max_cores = bdk_get_num_running_cores(node);

    // but use only a certain number of cores, at most what is available
    if ((s = getenv("ddr_tune_use_cores")) != NULL) {
	dram_tune_use_cores = strtoul(s, NULL, 0);
	if (dram_tune_use_cores <= 0) // allow 0 or negative to mean all
	    dram_tune_use_cores = dram_tune_max_cores;
    }
    if (dram_tune_use_cores > dram_tune_max_cores)
	dram_tune_use_cores = dram_tune_max_cores;

    // see if we want to do the tuning more than once per LMC...
    if ((s = getenv("ddr_tune_use_loops"))) {
	loops = strtoul(s, NULL, 0);
    }

    // see if we want to change the granularity of the byte_offset sampling 
    if ((s = getenv("ddr_tune_use_gran"))) {
	dram_tune_use_gran = strtoul(s, NULL, 0);
    }

    // allow override of the test repeats (bursts) per thread create
    if ((s = getenv("ddr_tune_use_bursts")) != NULL) {
        dram_tune_use_bursts = strtoul(s, NULL, 10);
    }

    // allow override of Read ODT setting just during the tuning run(s)
    if ((s = getenv("ddr_tune_use_rodt")) != NULL) {
        int temp = strtoul(s, NULL, 10);
	// validity check
	if (temp >= 0 && temp <= 7)
	    dram_tune_use_rodt = temp;
    }

#if 0
    // allow override of the test pattern
    // FIXME: a bit simplistic...
    if ((s = getenv("ddr_tune_use_pattern")) != NULL) {
	int patno = strtoul(s, NULL, 10);
	if (patno == 2)
	    dram_tune_test_pattern = test_pattern_2;
	else if (patno == 3)
	    dram_tune_test_pattern = test_pattern_3;
	else // all other values use default
	    dram_tune_test_pattern = test_pattern_1;
    }
#endif

    // print current working values // FIXME: force print
    printf("N%d: perform_lmc_offset_tuning: started %d cores, use %d cores, use %d bursts.\n",
	   node, dram_tune_max_cores, dram_tune_use_cores, dram_tune_use_bursts);

#if USE_L2_WAYS_LIMIT
    // see if L2 ways are limited
    if ((s = lookup_env_parameter("limit_l2_ways")) != NULL) {
	ways = strtoul(s, NULL, 10);
	ways_print = 1;
    } else {
	ways = bdk_l2c_get_num_assoc(node);
    }
#endif

    // if RODT is to be overridden during tuning, note change
    if (dram_tune_use_rodt >= 0) {
	ddr_print("N%d: using RODT %d for tuning.\n",
		  node, dram_tune_use_rodt);
    }

    // FIXME? get flag from LMC0 only
    ddr_interface_64b = !lmc_config.s.mode32b;

    // do setup for each active LMC
    debug_print("N%d: perform_lmc_offset_tuning: starting LMCs setup.\n", node);
    for (lmc = 0; lmc < num_lmcs; lmc++) {

	// if RODT change, save old and set new here...
	if (dram_tune_use_rodt >= 0) {
	    comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(lmc));
	    save_rodt[lmc] = comp_ctl2.s.rodt_ctl;
	    comp_ctl2.s.rodt_ctl = dram_tune_use_rodt;
	    DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(lmc), comp_ctl2.u);
	    BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(lmc));
	}

	/* Disable ECC for DRAM tests */
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));
	save_ecc_ena[lmc] = lmc_config.s.ecc_ena;
	lmc_config.s.ecc_ena = 0;
	DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(lmc), lmc_config.u);
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));

    } /* for (lmc = 0; lmc < num_lmcs; lmc++) */

#if USE_L2_WAYS_LIMIT
    /* Disable l2 sets for DRAM testing */
    limit_l2_ways(node, 0, ways_print);
#endif

    // testing is done on all LMCs simultaneously
    // FIXME: for now, loop here to show what happens multiple times
    for (loop = 0; loop < loops; loop++) {
	/* Perform DLL offset tuning */
	//auto_set_dll_offset(node,  1 /* 1=write */, lmc, ddr_interface_64b);
	auto_set_dll_offset(node,  2 /* 2=read */, num_lmcs, ddr_interface_64b);
    }

#if USE_L2_WAYS_LIMIT
    /* Restore the l2 set configuration */
    limit_l2_ways(node, ways, ways_print);
#endif

    // perform cleanup on all active LMCs   
    debug_print("N%d: perform_lmc_offset_tuning: starting LMCs cleanup.\n", node);
    for (lmc = 0; lmc < num_lmcs; lmc++) {

	/* Restore ECC for DRAM tests */
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));
	lmc_config.s.ecc_ena = save_ecc_ena[lmc];
	DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(lmc), lmc_config.u);
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));

	// if RODT change, restore old here...
	if (dram_tune_use_rodt >= 0) {
	    comp_ctl2.u = BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(lmc));
	    comp_ctl2.s.rodt_ctl = save_rodt[lmc];
	    DRAM_CSR_WRITE(node, BDK_LMCX_COMP_CTL2(lmc), comp_ctl2.u);
	    BDK_CSR_READ(node, BDK_LMCX_COMP_CTL2(lmc));
	}

	// finally, see if there are any read offset overrides after tuning
	for (int by = 0; by < 9; by++) {
	    if ((s = lookup_env_parameter("ddr%d_tune_byte%d", lmc, by)) != NULL) {
		int dllro = strtoul(s, NULL, 10);
		change_dll_offset_enable(node, lmc, 0);
		load_dll_offset(node, lmc, 2 /* 2=read */, dllro, by);
		change_dll_offset_enable(node, lmc, 1);
	    }
	}

    } /* for (lmc = 0; lmc < num_lmcs; lmc++) */

    // finish up...

    // if RODT was overridden during tuning, note restore
    if (dram_tune_use_rodt >= 0) {
	ddr_print("N%d: restoring RODT %d after tuning.\n",
		  node, save_rodt[0]); // FIXME? use LMC0
    }

    // put the unnecessary cores on this node back into reset
    bdk_reset_cores(node, ((int)node == 0) ? ~1ULL: ~0ULL);

    return 0;
} /* perform_dll_offset_tuning */

/////////////////////////////////////////////////////////////////////////////////////////////

/////    ECC byte tuning   //////

#if 1
// setup default for ECC byte test pattern array
#if 0
static const uint64_t ecc_pattern_1[] = {
    0x5555555555555555ULL, // GP0
    0xAAAAAAAAAAAAAAAAULL, // GP1
    0xAA55ULL,             // GP2
};
static const uint64_t ecc_pattern_2[] = {
    0xA5A5A5A5A5A5A5A5ULL, // GP0
    0x5A5A5A5A5A5A5A5AULL, // GP1
    0x5AA5ULL,             // GP2
};
#else
// take these from the HRM section 6.9.13
static const uint64_t ecc_pattern_1[] = {
    0xFFAAFFFFFF55FFFFULL, // GP0
    0x55555555AAAAAAAAULL, // GP1
    0xAA55AAAAULL,         // GP2
};
static const uint64_t ecc_pattern_2[] = {
    0xFBF7EFDFBF7FFEFDULL, // GP0
    0x0F1E3C78F0E1C387ULL, // GP1
    0xF0E1BF7FULL,         // GP2
};
#endif

static const uint64_t *ecc_patterns[] = { ecc_pattern_1, ecc_pattern_2};
#define NUM_ECC_PATTERNS ((int)(sizeof(ecc_patterns)/sizeof(uint64_t *)))

#define DEFAULT_ECC_BURSTS 32 // FIXME: this is what what the longest test usually has
int dram_tune_ecc_bursts = DEFAULT_ECC_BURSTS;
#endif

static void auto_set_ECC_dll_offset(bdk_node_t node, int dll_offset_mode,
				int lmc, int ddr_interface_64b)
{
    int byte_offset, new_best_offset;
    int rank_delay_start[4];
    int rank_delay_count[4];
    int rank_delay_best_start[4];
    int rank_delay_best_count[4];
    //char sbuffer[50];
    int errors[4], off_errors, tot_errors;
    int num_lmcs = __bdk_dram_get_num_lmc(node);
    int rank_max = 1; // default to 1 rank
    int pattern;
    const uint64_t *pattern_p;
    int rankx;

    // FIXME: must revise this for 2-slot!!!
    BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(lmc));
    if (lmcx_config.s.rank_ena) { // replace the default offset when there is more than 1 rank...
	dram_tune_rank_offset = 1ull << (28 + lmcx_config.s.pbank_lsb - lmcx_config.s.rank_ena + (num_lmcs/2));
	rank_max = 2; // FIXME???
    }

    debug_print("N%d: auto_set_ECC_dll_offset: starting LMC%d with rank offset 0x%lx\n",
	      node, lmc, dram_tune_rank_offset);

    // start of pattern loop
    // we do the set of tests for each pattern supplied...

    new_best_offset = 0;
    for (pattern = 0; pattern < NUM_ECC_PATTERNS; pattern++) {
	int pat_best_offset = 0;
	pattern_p = ecc_patterns[pattern];

	/*
	  3) Setup GENERAL_PURPOSE[0-2] registers with the data pattern of choice.
	  a. GENERAL_PURPOSE0[DATA<63:0>] – sets the initial lower (rising edge) 64 bits of data.
	  b. GENERAL_PURPOSE1[DATA<63:0>] – sets the initial upper (falling edge) 64 bits of data.
	  c. GENERAL_PURPOSE2[DATA<15:0>] – sets the initial lower (rising edge <7:0>) and upper
	     (falling edge <15:8>) ECC data.
	*/
	DRAM_CSR_MODIFY(general_purpose0, node, BDK_LMCX_GENERAL_PURPOSE0(lmc), 
			general_purpose0.s.data = pattern_p[0]);
	DRAM_CSR_MODIFY(general_purpose1, node, BDK_LMCX_GENERAL_PURPOSE1(lmc),
			general_purpose1.s.data = pattern_p[1]);
	DRAM_CSR_MODIFY(general_purpose2, node, BDK_LMCX_GENERAL_PURPOSE2(lmc),
			general_purpose2.s.data = pattern_p[2]);

	// now loop through all legal values for the DLL byte offset...

#define BYTE_OFFSET_INCR 3 // FIXME: make this tunable?

	tot_errors = 0;

	memset(rank_delay_count, 0, sizeof(rank_delay_count));
	memset(rank_delay_start, 0, sizeof(rank_delay_start));
	memset(rank_delay_best_count, 0, sizeof(rank_delay_best_count));
	memset(rank_delay_best_start, 0, sizeof(rank_delay_best_start));

	for (byte_offset = -63; byte_offset < 64; byte_offset += BYTE_OFFSET_INCR) {

	    // do the setup on the active LMC
	    // set *only* the ECC byte lane DLL offset
	    change_dll_offset_enable(node, lmc, 0);
	    load_dll_offset(node, lmc, dll_offset_mode, byte_offset, 8);
	    change_dll_offset_enable(node, lmc, 1);

	    bdk_watchdog_poke();

	    // run the test on each rank
	    // only 1 call per rank should be enough, let the bursts, loops, etc, control the load...
	
	    off_errors = 0;

	    for (rankx = 0; rankx < rank_max; rankx++) {
		uint64_t phys_addr = (lmc << 7);
		phys_addr |= (rankx) ? dram_tune_rank_offset : 0; // FIXME!! what if ranks> 2?
		errors[rankx] = test_dram_byte_hw(node, lmc, phys_addr, 8, 0xff);

		// check errors
		if (errors[rankx]) { // yes, an error in the ECC byte lane in this rank
		    off_errors |= errors[rankx];

		    ddr_print("N%d.LMC%d.R%d: ECC DLL %s Offset Test %3d: Address 0x%012lx errors 0x%x\n",
			      node, lmc, rankx, dll_offset_mode == 1 ? "Write" : "Read",
			      byte_offset, phys_addr, errors[rankx]);

		    if (rank_delay_count[rankx] > 0) { // had started run
			ddr_print("N%d.LMC%d.R%d: ECC DLL %s Offset Test %3d: stopping a run here\n",
				  node, lmc, rankx, dll_offset_mode == 1 ? "Write" : "Read", byte_offset);
			rank_delay_count[rankx] = 0;   // stop now
		    }
		    // FIXME: else had not started run - nothing else to do?
		} else { // no error in the ECC byte lane
		    if (rank_delay_count[rankx] == 0) { // first success, set run start
			ddr_print("N%d.LMC%d.R%d: ECC DLL %s Offset Test %3d: starting a run here\n",
				  node, lmc, rankx, dll_offset_mode == 1 ? "Write" : "Read", byte_offset);
			rank_delay_start[rankx] = byte_offset;
		    }
		    rank_delay_count[rankx] += BYTE_OFFSET_INCR; // bump run length

		    // is this now the biggest window?
		    if (rank_delay_count[rankx] > rank_delay_best_count[rankx]) {
			rank_delay_best_count[rankx] = rank_delay_count[rankx];
			rank_delay_best_start[rankx] = rank_delay_start[rankx];
			debug_print("N%d.LMC%d.R%d: ECC DLL %s Offset Test %3d: updating best to %d/%d\n",
				  node, lmc, rankx, dll_offset_mode == 1 ? "Write" : "Read", byte_offset,
				  rank_delay_best_start[rankx], rank_delay_best_count[rankx]);
		    }
		}
	    } /* for (rankx = 0; rankx < rank_max; rankx++) */

	    tot_errors |= off_errors;

	} /* for (byte_offset = -63; byte_offset < 64; byte_offset += BYTE_OFFSET_INCR) */

	// now choose the best byte_offset for this pattern according to the best windows of the tested ranks

	int pat_sum = 0, pat_cnt = 0;
	for (rankx = 0; rankx < rank_max; rankx++) {
	    int rank_delay_best = rank_delay_best_start[rankx] + (rank_delay_best_count[rankx] / 2);
	    pat_sum += rank_delay_best;
	    pat_cnt++;
	    ddr_print("N%d.LMC%d.R%d: ECC DLL %s Offset Test:  Rank Best %3d\n",
		      node, lmc, rankx, dll_offset_mode == 1 ? "Write" : "Read",
		      rank_delay_best);
	} /* for (rankx = 0; rankx < rank_max; rankx++) */

	pat_best_offset = pat_sum / pat_cnt;
	ddr_print("N%d.LMC%d: ECC DLL %s Offset Test:  Pattern %d Average %3d\n",
		  node, lmc, dll_offset_mode == 1 ? "Write" : "Read",
		  pattern, pat_best_offset);


#if 0
	// FIXME: next print the window counts
	sprintf(sbuffer, "N%d.LMC%d Pattern %d: DLL %s Offset Count ",
		node, lmc, pattern,
		dll_offset_mode == 1 ? "Write" : "Read ");
	printf("%-45s : ", sbuffer); // FIXME: force print
	printf(" %3d", byte_delay_best_count); // FIXME: force print
	printf("\n"); // FIXME: force print
#endif

	new_best_offset += pat_best_offset; // sum the pattern averages
    } // end of pattern loop

    new_best_offset /= NUM_ECC_PATTERNS; // create the new average

    // print the best offset from all patterns

    ddr_print("N%d.LMC%d: ECC DLL %s Offset Best Delay: %3d\n",
	      node, lmc,
	      dll_offset_mode == 1 ? "Write" : "Read ",
	      new_best_offset);

    // done with testing, load up the best offset we found...
    change_dll_offset_enable(node, lmc, 0); // disable offsets while we load...
    load_dll_offset(node, lmc, dll_offset_mode, new_best_offset, 8);
    change_dll_offset_enable(node, lmc, 1); // re-enable the offsets now that we are done loading

#if 0
    // run the test one last time 
    // print whether there are errors or not, but only when verbose...
    tot_errors = run_test_dram_byte_threads(node, num_lmcs, bytemask);
    printf("ECC DLL %s Offset Final Test: errors 0x%x\n",
	   dll_offset_mode == 1 ? "Write" : "Read", tot_errors);
#endif
}

/*
 * Automatically adjust the DLL offset for the ECC byte
 */
int perform_ECC_dll_offset_tuning(bdk_node_t node, int dll_offset_mode)
{
    int ddr_interface_64b;
    int save_ecc_ena[4];
    bdk_lmcx_config_t lmc_config;
    int lmc, num_lmcs = __bdk_dram_get_num_lmc(node);
    const char *s;
    //bdk_lmcx_comp_ctl2_t comp_ctl2;
    int loops = 1, loop;
    int tune_enable = 0; // disable by default

    // FIXME? allow override of the filtering
    if ((s = getenv("ddr_tune_ecc_enable")) != NULL) {
        tune_enable = !!strtoul(s, NULL, 10);
    }
    if (!tune_enable) {
	printf("N%d: ECC DLL read offset currently not eligible for tuning.\n", node);
	// FIXME? allow override to do tuning?
	return 0;
    }

    // see if we want to do the tuning more than once per LMC...
    if ((s = getenv("ddr_tune_ecc_loops"))) {
	loops = strtoul(s, NULL, 0);
    }

    // allow override of the test repeats (bursts)
    if ((s = getenv("ddr_tune_ecc_bursts")) != NULL) {
        dram_tune_ecc_bursts = strtoul(s, NULL, 10);
    }

    // print current working values // FIXME: force print
    printf("N%d: perform_ECC_dll_offset_tuning: %d loops, %d bursts, %d patterns.\n",
	   node, loops, dram_tune_ecc_bursts, NUM_ECC_PATTERNS);

    // FIXME? get flag from LMC0 only
    lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(0));
    ddr_interface_64b = !lmc_config.s.mode32b;

    // do once for each active LMC

    for (lmc = 0; lmc < num_lmcs; lmc++) {

	ddr_print("N%d: perform_ECC_dll_offset_tuning: starting LMC%d ECC tune.\n", node, lmc);

	/* Enable ECC for the HW tests */
	// NOTE: we do enable ECC, but the HW tests used will not generate "visible" errors
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));
	save_ecc_ena[lmc] = lmc_config.s.ecc_ena;
	lmc_config.s.ecc_ena = 1;
	DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(lmc), lmc_config.u);
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));

	// testing is done on a single LMC at a time
	// FIXME: for now, loop here to show what happens multiple times
	for (loop = 0; loop < loops; loop++) {
	    /* Perform DLL offset tuning */
	    //auto_set_dll_offset(node,  1 /* 1=write */, lmc, ddr_interface_64b);
	    auto_set_ECC_dll_offset(node,  2 /* 2=read */, lmc, ddr_interface_64b);
	}

	// perform cleanup on active LMC   
	ddr_print("N%d: perform_ECC_dll_offset_tuning: finishing LMC%d ECC tune.\n", node, lmc);

	/* Restore ECC for DRAM tests */
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));
	lmc_config.s.ecc_ena = save_ecc_ena[lmc];
	DRAM_CSR_WRITE(node, BDK_LMCX_CONFIG(lmc), lmc_config.u);
	lmc_config.u = BDK_CSR_READ(node, BDK_LMCX_CONFIG(lmc));

	// finally, see if there are any read offset overrides after tuning
	for (int by = 0; by < 9; by++) {
	    if ((s = lookup_env_parameter("ddr%d_tune_byte%d", lmc, by)) != NULL) {
		int dllro = strtoul(s, NULL, 10);
		change_dll_offset_enable(node, lmc, 0);
		load_dll_offset(node, lmc, 2 /* 2=read */, dllro, by);
		change_dll_offset_enable(node, lmc, 1);
	    }
	}

    } /* for (lmc = 0; lmc < num_lmcs; lmc++) */

    // finish up...

    return 0;

} /* perform_ECC_dll_offset_tuning */

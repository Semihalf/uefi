#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(DRAM_TEST);

#define MAX_ERRORS_TO_REPORT 50
#define ENABLE_LMC_PERCENT 1 /* Show LMC load after each DRAM test */
#define ENABLE_CCPI_PERCENT 0 /* Show CCPI load after each DRAM test */

typedef struct
{
    const char *        name;       /* Friendly name for the test */
    __bdk_dram_test_t   test_func;  /* Function to call */
    int                 bursts;     /* Bursts parameter to pass to the test */
    int                 max_cores;  /* Maximum number of cores the test should be run on in parallel. Zero means all */
} dram_test_info_t;

static const dram_test_info_t TEST_INFO[] = {
    /* Name,                    Test function,                      Bursts, Max Cores */
    { "Data Bus",               __bdk_dram_test_mem_data_bus,       8,      1},
    { "Address Bus",            __bdk_dram_test_mem_address_bus,    0,      1},
    { "Marching Rows",          __bdk_dram_test_mem_rows,           16,     0},
    { "Random Data",            __bdk_dram_test_mem_random,         32,     0},
    { "Random XOR (32 Burst)",  __bdk_dram_test_mem_xor,            32,     0},
    { "Self Address",           __bdk_dram_test_mem_self_addr,      1,      0},
    { "March C- Solid Bits",    __bdk_dram_test_mem_solid,          1,      0},
    { "March C- Checkerboard",  __bdk_dram_test_mem_checkerboard,   1,      0},
    { "Walking Ones Left",      __bdk_dram_test_mem_leftwalk1,      1,      0},
    { "Walking Ones Right",     __bdk_dram_test_mem_rightwalk1,     1,      0},
    { "Walking Zeros Left",     __bdk_dram_test_mem_leftwalk0,      1,      0},
    { "Walking Zeros Right",    __bdk_dram_test_mem_rightwalk0,     1,      0},
    { "Random XOR (224 Burst)", __bdk_dram_test_mem_xor,            224,    0},
    { NULL,                     NULL,                               0,      0}
};

/* These variables count the number of ECC errors. They should only be accessed atomically */
int64_t __bdk_dram_ecc_single_bit_errors;
int64_t __bdk_dram_ecc_double_bit_errors;

static int64_t dram_test_thread_done;
static int64_t dram_test_thread_errors;
static uint64_t dram_test_thread_start;
static uint64_t dram_test_thread_end;
static uint64_t dram_test_thread_size;

/**
 * Force the memory at the pointer location to be written to memory and evicted
 * from L2. L1 will be unaffected.
 *
 * @param address Physicalmemory location
 */
void __bdk_dram_flush_to_mem(uint64_t address)
{
    BDK_MB;
    /* The DRAM code doesn't use the normal bdk_phys_to_ptr() because of the
       NULL check in it. This greatly slows down the memory tests */
    char *ptr = (void*)address;
    BDK_CACHE_WBI_L2(ptr);
}

/**
 * Force a memory regoin to be written to DRAM and evicted from L2
 *
 * @param area   Start of the region
 * @param max_address
 *               End of the region (exclusive)
 */
void __bdk_dram_flush_to_mem_range(uint64_t area, uint64_t max_address)
{
    /* The DRAM code doesn't use the normal bdk_phys_to_ptr() because of the
       NULL check in it. This greatly slows down the memory tests */
    char *ptr = (void*)area;
    char *end = (void*)max_address;
    BDK_MB;
    while (ptr < end)
    {
        BDK_CACHE_WBI_L2(ptr);
        ptr += 128;
    }
}

/**
 * Convert a test enumeration into a string
 *
 * @param test   Test to convert
 *
 * @return String for display
 */
const char *bdk_dram_get_test_name(int test)
{
    if (test < (int)(sizeof(TEST_INFO) / sizeof(TEST_INFO[0])))
        return TEST_INFO[test].name;
    else
        return NULL;
}

/**
 * This function is run as a thread to perform memory tests over multiple cores.
 * Each thread gets a section of memory to work on, which is controlled by global
 * variables at the beginning of this file.
 *
 * @param arg    Number of the region we should check
 * @param arg1   Pointer the the test_info structure
 */
static void dram_test_thread(int arg, void *arg1)
{
    const dram_test_info_t *test_info = arg1;
    const int bursts = test_info->bursts;
    const int range_number = arg;

    /* Figure out our work memory range.
     *
     * Note start_address and end_address just provide the physical offset
     * portion of the address and do not have the node bits set. This is
     * is to simplify address checks and calculations. Later, when about to run
     * the memory test, the routines adds in the node bits to form the final
     * addresses.
     */
    uint64_t start_address = dram_test_thread_start + dram_test_thread_size * range_number;
    uint64_t end_address = start_address + dram_test_thread_size;
    if (end_address > dram_test_thread_end)
        end_address = dram_test_thread_end;

    bdk_node_t node = bdk_numa_local();

    /* Insert the node part of the address */
    start_address = bdk_numa_get_address(node, start_address);
    end_address = bdk_numa_get_address(node, end_address);
    /* Test the region */
    BDK_TRACE(DRAM_TEST, "  Node %d, core %d, Testing [0x%011lx:0x%011lx]\n",
        node, bdk_get_core_num() & 127, start_address, end_address - 1);
    test_info->test_func(start_address, end_address, bursts);

    /* Report that we're done */
    BDK_TRACE(DRAM_TEST, "Thread %d on node %d done with memory test\n", range_number, node);
    bdk_atomic_add64_nosync(&dram_test_thread_done, 1);
}

/**
 * Run the memory test.
 *
 * @param test   Test to run
 * @param start_address
 *               Physical address to start at
 * @param length Length of memory block
 *
 * @return Number of errors found. Zero is success. Negative means the test
 *         did not run due to some other failure.
 */
static int __bdk_dram_run_test(const dram_test_info_t *test_info, uint64_t start_address, uint64_t length)
{
    /* Figure out the addess of the byte one off the top of memory */
    uint64_t max_address = bdk_dram_get_size_mbytes(bdk_numa_local());
    BDK_TRACE(DRAM_TEST, "DRAM available per node: %lu MB\n", max_address);
    max_address <<= 20;

    /* Make sure we have enough */
    if (max_address < (16<<20))
    {
        bdk_error("DRAM size is too small\n");
        return -1;
    }

    /* Make sure the amount is sane */
    if (max_address > (1ull << 40))
        max_address = 1ull << 40;
    BDK_TRACE(DRAM_TEST, "DRAM max address: 0x%011lx\n", max_address-1);

    /* Make sure the start address is lower than the top of memory */
    if (start_address >= max_address)
    {
        bdk_error("Start address is larger than the amount of memory: 0x%011lx versus 0x%011lx\n",
	          start_address, max_address);
        return -1;
    }
    if (length == (uint64_t)-1)
        length = max_address - start_address;

    /* Final range checks */
    uint64_t end_address = start_address + length;
    if (end_address > max_address)
    {
        end_address = max_address;
        length = end_address - start_address;
    }
    if (length == 0)
        return 0;

    /* Ready to run the test. Figure out how many cores we need */
    int max_cores = test_info->max_cores;

    /* Figure out the number of cores available in the system */
    if (max_cores == 0)
        max_cores += bdk_get_num_running_cores(bdk_numa_local());
    BDK_TRACE(DRAM_TEST, "Using %d cores for memory tests\n", max_cores);

    printf("Starting Test \"%s\" for [0x%011lx:0x%011lx]\n",
        test_info->name, start_address, end_address - 1);

#if ENABLE_LMC_PERCENT
    /* Remember the LMC perf counters for stats after the test */
    uint64_t start_dram_dclk[BDK_NUMA_MAX_NODES][4];
    uint64_t start_dram_ops[BDK_NUMA_MAX_NODES][4];
    uint64_t stop_dram_dclk[BDK_NUMA_MAX_NODES][4];
    uint64_t stop_dram_ops[BDK_NUMA_MAX_NODES][4];
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            const int num_dram_controllers = __bdk_dram_get_num_lmc(node);
            for (int i = 0; i < num_dram_controllers; i++)
            {
                start_dram_dclk[node][i] = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(i));
                start_dram_ops[node][i] = BDK_CSR_READ(node, BDK_LMCX_OPS_CNT(i));
            }
        }
    }
#endif
#if ENABLE_CCPI_PERCENT
    /* Remember the CCPI link counters for stats after the test */
    uint64_t start_ccpi_data[BDK_NUMA_MAX_NODES][3];
    uint64_t start_ccpi_idle[BDK_NUMA_MAX_NODES][3];
    uint64_t start_ccpi_err[BDK_NUMA_MAX_NODES][3];
    uint64_t stop_ccpi_data[BDK_NUMA_MAX_NODES][3];
    uint64_t stop_ccpi_idle[BDK_NUMA_MAX_NODES][3];
    uint64_t stop_ccpi_err[BDK_NUMA_MAX_NODES][3];
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            for (int link = 0; link < 3; link++)
            {
                start_ccpi_data[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_DATA_CNT(link));
                start_ccpi_idle[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_IDLE_CNT(link));
                start_ccpi_err[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_ERR_CNT(link));
            }
        }
    }
#endif

    /* WARNING: This code assumes the same memory range is being tested on
       all nodes. The same number of cores are used on each node to test
       its local memory */
    uint64_t work_address = start_address;
    while (work_address < end_address)
    {
        /* Check at most MAX_CHUNK_SIZE across each iteration. We only report
           progress between chunks, so keep them reasonably small */
        const uint64_t MAX_CHUNK_SIZE = 1ull << 28; /* 256MB */
        uint64_t size = end_address - work_address;
        if (size > MAX_CHUNK_SIZE)
            size = MAX_CHUNK_SIZE;

        /* Divide memory evenly between the cores. Round the size up so that
           all memory is covered. The last core may have slightly less memory to
           test */
        uint64_t thread_size = (size + (max_cores - 1)) / max_cores;
        thread_size += 127;
        thread_size &= -128;
        dram_test_thread_start = work_address;
        dram_test_thread_end = work_address + size;
        dram_test_thread_size = thread_size;
        BDK_WMB;

        /* Report progress percentage */
        int percent_x10 = (work_address - start_address) * 1000 / (end_address - start_address);
        printf("  %3d.%d%% complete, testing [0x%011lx:0x%011lx]\r",
            percent_x10 / 10, percent_x10 % 10,  work_address, work_address + size - 1);
        fflush(stdout);
        work_address += size;

        /* Start threads for all the cores */
        int total_count = 0;
        bdk_atomic_set64(&dram_test_thread_done, 0);
        bdk_atomic_set64(&dram_test_thread_errors, 0);
        for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
        {
            if (bdk_numa_exists(node))
            {
                const int num_cores = bdk_get_num_cores(node);
                int per_node = 0;
                for (int core = 0; core < num_cores; core++)
                {
                    if (per_node >= max_cores)
                        break;
                    BDK_TRACE(DRAM_TEST, "Starting thread %d on node %d for memory test\n", per_node, node);
                    if (bdk_thread_create(node, 0, dram_test_thread, per_node, (void *)test_info, 0))
                    {
                        bdk_error("Failed to create thread %d for memory test on node %d\n", per_node, node);
                    }
                    else
                    {
                        per_node++;
                        total_count++;
                    }
                }
            }
        }

        /* Wait for threads to finish */
        while (bdk_atomic_get64(&dram_test_thread_done) < total_count)
            bdk_thread_yield();
    }

#if ENABLE_LMC_PERCENT
    /* Get the DRAM perf counters */
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            const int num_dram_controllers = __bdk_dram_get_num_lmc(node);
            for (int i = 0; i < num_dram_controllers; i++)
            {
                stop_dram_dclk[node][i] = BDK_CSR_READ(node, BDK_LMCX_DCLK_CNT(i));
                stop_dram_ops[node][i] = BDK_CSR_READ(node, BDK_LMCX_OPS_CNT(i));
            }
        }
    }
#endif
#if ENABLE_CCPI_PERCENT
    /* Get the CCPI link counters */
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            for (int link = 0; link < 3; link++)
            {
                stop_ccpi_data[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_DATA_CNT(link));
                stop_ccpi_idle[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_IDLE_CNT(link));
                stop_ccpi_err[node][link] = BDK_CSR_READ(node, BDK_OCX_TLKX_STAT_ERR_CNT(link));
            }
        }
    }
#endif
#if ENABLE_LMC_PERCENT
    /* Display LMC load */
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            const int num_dram_controllers = __bdk_dram_get_num_lmc(node);
            for (int i = 0; i < num_dram_controllers; i++)
            {
                uint64_t ops = stop_dram_ops[node][i] - start_dram_ops[node][i];
                uint64_t dclk = stop_dram_dclk[node][i] - start_dram_dclk[node][i];
                if (dclk == 0)
                    dclk = 1;
                uint64_t percent_x10 = ops * 1000 / dclk;
                printf("  Node %d, LMC%d: ops %lu, cycles %lu, used %lu.%lu%%\n",
                    node, i, ops, dclk, percent_x10 / 10, percent_x10 % 10);
            }
        }
    }
#endif
#if ENABLE_CCPI_PERCENT
    /* Display CCPI load */
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            for (int link = 0; link < 3; link++)
            {
                uint64_t busy = stop_ccpi_data[node][link] - start_ccpi_data[node][link];
                busy += stop_ccpi_err[node][link] - start_ccpi_err[node][link];
                uint64_t total = stop_ccpi_idle[node][link] - start_ccpi_idle[node][link];
                total += busy;
                if (total == 0)
                    continue;
                uint64_t percent_x10 = busy * 1000 / total;
                printf("  Node %d, CCPI%d: busy %lu, total %lu, used %lu.%lu%%\n",
                    node, link, busy, total, percent_x10 / 10, percent_x10 % 10);
            }
        }
    }
#endif
    return dram_test_thread_errors;
}

/**
 * Perform a memory test.
 *
 * @param test   Test type to run
 * @param start_address
 *               Physical address to start at
 * @param length Length of memory block
 *
 * @return Number of errors found. Zero is success. Negative means the test
 *         did not run due to some other failure.
 */
int bdk_dram_test(int test, uint64_t start_address, uint64_t length)
{
    /* These limits are arbitrary. They just make sure we aren't doing something
       silly, like test a non cache line aligned memory region */
    if (start_address & 0xffff)
    {
        bdk_error("DRAM test start address must be aligned on a 64KB boundary\n");
        return -1;
    }
    if (length & 0xffff)
    {
        bdk_error("DRAM test length must be a multiple of 64KB\n");
        return -1;
    }

    const char *name = bdk_dram_get_test_name(test);
    if (name == NULL)
    {
        bdk_error("Invalid DRAM test number %d\n", test);
        return -1;
    }

    /* Make sure the start address is higher that the BDK's active range */
    uint64_t top_of_bdk = bdk_dram_get_top_of_bdk();
    if (start_address < top_of_bdk)
        start_address = top_of_bdk;

    /* Clear ECC error counters before starting the test */
    bdk_atomic_set64(&__bdk_dram_ecc_single_bit_errors, 0);
    bdk_atomic_set64(&__bdk_dram_ecc_double_bit_errors, 0);

    int errors = __bdk_dram_run_test(&TEST_INFO[test], start_address, length);

    /* Check ECC error counters ater the test */
    int64_t ecc_single = bdk_atomic_get64(&__bdk_dram_ecc_single_bit_errors);
    int64_t ecc_double = bdk_atomic_get64(&__bdk_dram_ecc_double_bit_errors);
    if (ecc_single || ecc_double)
    {
        printf("Test \"%s\": ECC errors, %ld corrected, %ld uncorrected\n",
            name, ecc_single, ecc_double);
    }
    if (errors)
        printf("Test \"%s\": FAIL\n", name);
    else if (ecc_single || ecc_double)
    {
        printf("Test \"%s\": FAIL due to ECC errors\n", name);
    }
    else
        BDK_TRACE(DRAM_TEST, "Test \"%s\": PASS\n", name);
    return errors;
}

static void extract_address_info(uint64_t address, int *node, int *lmc, int *dimm, int *rank, int *bank, int *row, int *col)
{
    #define EXTRACT(v, lsb, width) (((v) >> (lsb)) & ((1ull << (width)) - 1))
    *node = EXTRACT(address, 40, 2); /* Address bits [41:40] */
    /* Determine the LMC controller */
    BDK_CSR_INIT(l2c_ctl, *node, BDK_L2C_CTL);
    int bank_lsb;
    if (__bdk_dram_get_num_lmc() == 4)
    {
        bank_lsb = 9;
        if (l2c_ctl.s.disidxalias)
            *lmc = EXTRACT(address, 7, 2);
        else
            *lmc = EXTRACT(address, 7, 2) ^ EXTRACT(address, 18, 2) ^ EXTRACT(address, 12, 2);
    }
    else
    {
        bank_lsb = 8;
        if (l2c_ctl.s.disidxalias)
            *lmc = EXTRACT(address, 7, 1);
        else
            *lmc = EXTRACT(address, 7, 1) ^ EXTRACT(address, 18, 1) ^ EXTRACT(address, 12, 1);
    }

    /* Figure out hte bank field width */
    BDK_CSR_INIT(lmcx_config, *node, BDK_LMCX_CONFIG(*lmc));
    int bank_width;
    int is_ddr4 = 0; /* FIXME: Detect DDR4 */
    if (is_ddr4)
    {
        bdk_fatal("Add DDR4 support"); // FIXME
    }
    else
        bank_width = 3;

    /* Extract bit positions from the LMC config */
    int dimm_lsb    = 28 + lmcx_config.s.pbank_lsb;
    int dimm_width  = 40 - dimm_lsb;
    int rank_lsb    = dimm_lsb - lmcx_config.s.rank_ena;
    int rank_width  = dimm_lsb - rank_lsb;
    int row_lsb     = 14 + lmcx_config.s.row_lsb;
    int row_width   = rank_lsb - row_lsb;
    int col_hi_lsb  = bank_lsb + bank_width;
    int col_hi_width= row_lsb - col_hi_lsb;

    /* Extract the parts of the address */
    *dimm = EXTRACT(address, dimm_lsb, dimm_width);
    *rank = EXTRACT(address, rank_lsb, rank_width);
    *row = EXTRACT(address, row_lsb, row_width);
    int col_hi = EXTRACT(address, col_hi_lsb, col_hi_width);
    *bank = EXTRACT(address, bank_lsb, bank_width);
    /* LMC number already extracted */
    *col = EXTRACT(address, 3, 4) | (col_hi << 4);
    /* Bus byte is address bits [2:0]. Unused here */
}

/**
 * Report a DRAM error. Errors are not shown after MAX_ERRORS_TO_REPORT is
 * exceeded.
 *
 * @param address Physical address the error occurred at
 * @param data    Data read from memory
 * @param correct Correct data
 * @param burst   Which burst this is from, informational only
 *
 * @return Zero if a message was logged, non-zero if the error limit has been reached
 */
int __bdk_dram_report_error(uint64_t address, uint64_t data, uint64_t correct, int burst)
{
    int64_t errors = bdk_atomic_fetch_and_add64(&dram_test_thread_errors, 1);
    if (errors < MAX_ERRORS_TO_REPORT)
    {
        int core = bdk_get_core_num();
        int node, lmc, dimm, rank, bank, row, col;
        extract_address_info(address, &node, &lmc, &dimm, &rank, &bank, &row, &col);

        bdk_error("[0x%011lx] data: 0x%016lx, expected: 0x%016lx, xor: 0x%016lx, burst: %d "
                  "(N%d,Core%d,LMC%d,DIMM%d,Rank%d,Bank%d,Row 0x%x,Col 0x%x)\n",
            address, data, correct, data ^ correct, burst,
            node, core, lmc, dimm, rank, bank, row, col);
        if (errors == MAX_ERRORS_TO_REPORT-1)
            bdk_error("No further DRAM errors will be reported\n");
        return errors == MAX_ERRORS_TO_REPORT - 1;
    }
    else
        return -1;
}

/**
 * Report a DRAM error. Errors are not shown after MAX_ERRORS_TO_REPORT is
 * exceeded. Used when two address might be involved in the failure.
 *
 * @param address1 First address involved in the failure
 * @param data1    Data from the first address
 * @param address2 Second address involved in the failure
 * @param data2    Data from second address
 * @param burst    Which burst this is from, informational only
 *
 * @return Zero if a message was logged, non-zero if the error limit has been reached
 */
int __bdk_dram_report_error2(uint64_t address1, uint64_t data1, uint64_t address2, uint64_t data2, int burst)
{
    int64_t errors = bdk_atomic_fetch_and_add64(&dram_test_thread_errors, 1);
    if (errors < MAX_ERRORS_TO_REPORT)
    {
        int core = bdk_get_core_num();
        int node1, lmc1, dimm1, rank1, bank1, row1, col1;
        extract_address_info(address1, &node1, &lmc1, &dimm1, &rank1, &bank1, &row1, &col1);
        int node2, lmc2, dimm2, rank2, bank2, row2, col2;
        extract_address_info(address2, &node2, &lmc2, &dimm2, &rank2, &bank2, &row2, &col2);

        bdk_error("[0x%011lx] data: 0x%016lx, [0x%016lx] expected: 0x%016lx, xor: 0x%016lx, burst: %d\n"
            "    N%d,Core%d,LMC%d,DIMM%d,Rank%d,Bank%d,Row 0x%x,Col 0x%x\n"
            "    N%d,Core%d,LMC%d,DIMM%d,Rank%d,Bank%d,Row 0x%x,Col 0x%x\n",
            address1, data1, address2, data2, data1 ^ data2, burst,
            node1, core, lmc1, dimm1, rank1, bank1, row1, col1,
            node2, core, lmc2, dimm2, rank2, bank2, row2, col2);
        if (errors == MAX_ERRORS_TO_REPORT-1)
            bdk_error("No further DRAM errors will be reported\n");
        return errors == MAX_ERRORS_TO_REPORT - 1;
    }
    else
        return -1;
}


#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(DRAM_TEST);

/* The physical memory map has a hole between 256MB and 512MB for the
   bootbus. These defines represent this in address caclulations */
#define BDK_DRAM_HOLE_START 0x10000000ull
#define BDK_DRAM_HOLE_SIZE 0x10000000ull
#define MAX_ERRORS_TO_REPORT 50
#define ENABLE_LMC_PERCENT 1 /* Show LMC load after each DRAM test */

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

static int64_t dram_test_thread_done;
static int64_t dram_test_thread_errors;
static uint64_t dram_test_thread_start;
static uint64_t dram_test_thread_end;
static uint64_t dram_test_thread_size;

/**
 * Return the numberof LMC controllers in use
 *
 * @param node   Node to probe
 *
 * @return 1, 2, or 4 depending on the chip and mode
 */
int __bdk_dram_get_num_lmc(bdk_node_t node)
{
    BDK_CSR_INIT(lmcx_dll_ctl2, node, BDK_LMCX_DLL_CTL2(2));
    if (lmcx_dll_ctl2.s.intf_en)
        return 4;
    else
        return 2;
}

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
    char *ptr = (void*)(address | (1ull<<63));
    BDK_CACHE_WBIL2(ptr);
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
    char *ptr = (void*)(area | (1ull<<63));
    char *end = (void*)(max_address | (1ull<<63));
    BDK_MB;
    while (ptr < end)
    {
        BDK_CACHE_WBIL2(ptr);
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
    if (dram_test_thread_start < BDK_DRAM_HOLE_START + BDK_DRAM_HOLE_SIZE)
    {
        if (start_address >= BDK_DRAM_HOLE_START)
        {
            start_address += BDK_DRAM_HOLE_SIZE;
            end_address += BDK_DRAM_HOLE_SIZE;
        }
        else if (end_address > BDK_DRAM_HOLE_START)
        {
            end_address += BDK_DRAM_HOLE_SIZE;
        }
    }
    else
    {
        if ((end_address > BDK_DRAM_HOLE_START) && (start_address < BDK_DRAM_HOLE_START + BDK_DRAM_HOLE_SIZE))
            end_address += BDK_DRAM_HOLE_SIZE;
    }
    if (end_address > dram_test_thread_end)
        end_address = dram_test_thread_end;

    bdk_node_t node = bdk_numa_local();

    /* Check if we're spanning the memory hole */
    if ((start_address < BDK_DRAM_HOLE_START) && (end_address > BDK_DRAM_HOLE_START))
    {
        /* Insert the node part of the address */
        uint64_t s1 = start_address;
        uint64_t e1 = BDK_DRAM_HOLE_START;
        uint64_t s2 = BDK_DRAM_HOLE_START + BDK_DRAM_HOLE_SIZE;
        uint64_t e2 = end_address;
        s1 |= ((uint64_t)node) << 40;
        e1 |= ((uint64_t)node) << 40;
        s2 |= ((uint64_t)node) << 40;
        e2 |= ((uint64_t)node) << 40;

        /* Test before the hole */
        BDK_TRACE("  Node %d, core %d, Testing [0x%016lx:0x%016lx]\n",
            node, bdk_get_core_num() & 127, s1, e1 - 1);
        test_info->test_func(s1, e1, bursts);
        /* Test after the hole */
        BDK_TRACE("  Node %d, core %d, Testing [0x%016lx:0x%016lx]\n",
            node, bdk_get_core_num() & 127, s2, e2 - 1);
        test_info->test_func(s2, e2, bursts);
    }
    else
    {
        /* Insert the node part of the address */
        start_address |= ((uint64_t)node) << 40;
        end_address |= ((uint64_t)node) << 40;
        /* Test the region */
        BDK_TRACE("  Node %d, core %d, Testing [0x%016lx:0x%016lx]\n",
            node, bdk_get_core_num() & 127, start_address, end_address - 1);
        test_info->test_func(start_address, end_address, bursts);
    }

    /* Report that we're done */
    BDK_TRACE("Thread %d on node %d done with memory test\n", range_number, node);
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
    BDK_TRACE("DRAM available per node: %lu MB\n", max_address);
    max_address <<= 20;
    /* More than 256MB gets offset by 256MB due to the bootbus hole */
    if (max_address > BDK_DRAM_HOLE_START)
        max_address += BDK_DRAM_HOLE_SIZE;

    /* Make sure we have enough */
    if (max_address < (16<<20))
    {
        bdk_error("DRAM size is too small\n");
        return -1;
    }

    /* Make sure the amount is sane */
    if (max_address > (1ull << 40))
        max_address = 1ull << 40;
    BDK_TRACE("DRAM max address: 0x%016lx\n", max_address-1);

    /* Make sure the start address is lower than the top of memory */
    if (start_address >= max_address)
    {
        bdk_error("Start address is larger than the amount of memory: 0x%016lx versus 0x%016lx\n",
	          start_address, max_address);
        return -1;
    }
    if (length == (uint64_t)-1)
        length = max_address - start_address;

    /* Final range checks */
    uint64_t end_address = start_address + length;
    if ((start_address < BDK_DRAM_HOLE_START) && (end_address > BDK_DRAM_HOLE_START))
    {
        /* Account for hole in length check */
        end_address += BDK_DRAM_HOLE_SIZE;
        if (end_address > max_address)
        {
            end_address = max_address;
            length = end_address - start_address;
            if (end_address > BDK_DRAM_HOLE_START)
                length -= BDK_DRAM_HOLE_SIZE;
        }
    }
    else
    {
        if (end_address > max_address)
        {
            end_address = max_address;
            length = end_address - start_address;
        }
    }
    if (length == 0)
        return 0;

    /* Ready to run the test. Figure out how many cores we need */
    int max_cores = test_info->max_cores;

    /* Figure out the number of cores available in the system */
    if (max_cores == 0)
        max_cores += bdk_get_num_running_cores(bdk_numa_local());
    BDK_TRACE("Using %d cores for memory tests\n", max_cores);

    printf("Starting Test \"%s\" for [0x%016lx:0x%016lx]\n",
        test_info->name, start_address, end_address - 1);

    /* WARNING: This code assumes the same memory range is being tested on
       all nodes. The same number of cores are used on each node to test
       its local memory */

    /* Divide memory evenly between the cores. Round the size up so that
       all memory is covered. The last core may have slightly less memory to
       test */
    uint64_t size = (length + (max_cores - 1)) / max_cores;
    size += 127;
    size &= -128;
    dram_test_thread_start = start_address;
    dram_test_thread_end = end_address;
    dram_test_thread_size = size;
    BDK_WMB;
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

    /* Start threads for all the cores */
    int total_count = 0;
    bdk_atomic_set64(&dram_test_thread_done, 0);
    bdk_atomic_set64(&dram_test_thread_errors, 0);
    for (int node = 0; node < BDK_NUMA_MAX_NODES; node++)
    {
        if (bdk_numa_exists(node))
        {
            const int num_cores = bdk_octeon_num_cores(node);
            int per_node = 0;
            for (int core = 0; core < num_cores; core++)
            {
                if (per_node >= max_cores)
                    break;
                BDK_TRACE("Starting thread %d on node %d for memory test\n", per_node, node);
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
    /* Don't allow Bootbus addresses as start addresses. Other code handles
       the case where start is before the DRAM hole and length extends into it
       */
    if ((start_address >= BDK_DRAM_HOLE_START) &&
        (start_address < BDK_DRAM_HOLE_START + BDK_DRAM_HOLE_SIZE))
    {
        bdk_error("DRAM test start address must not be in the DRAM hole (256MB - 512MB)\n");
        return -1;
    }

    const char *name = bdk_dram_get_test_name(test);
    if (name == NULL)
    {
        bdk_error("Invalid DRAM test number %d\n", test);
        return -1;
    }

    /* Make sure the start address is higher that the BDK's active range.
     *
     * As sbrk() returns an final address, mask off the node portion of
     * the address to make it a physical offset. Doing this simplifies the
     * address checks and calculations which only work with physical offsets.
     */
    extern caddr_t sbrk(int incr);
    uint64_t top_of_bdk = (bdk_ptr_to_phys(sbrk(0)) & 0x000000FFFFFFFFFF);
    if (start_address < top_of_bdk)
    {
        /* Give 4MB of extra so the BDK has room to grow while the test runs */
        start_address = top_of_bdk + (4 << 20);
        /* Align it on a 64KB boundary */
        start_address >>= 16;
        start_address <<= 16;
    }

    int errors = __bdk_dram_run_test(&TEST_INFO[test], start_address, length);
    if (errors)
        printf("Test \"%s\": FAIL\n", name);
    else
        BDK_TRACE("Test \"%s\": PASS\n", name);
    return errors;
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
        bdk_error("[0x%016lx] data: 0x%016lx, expected: 0x%016lx, xor: 0x%016lx, burst: %d\n",
            address, data, correct, data ^ correct, burst);
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
        bdk_error("[0x%016lx] data: 0x%016lx, [0x%016lx] expected: 0x%016lx, xor: 0x%016lx, burst: %d\n",
            address1, data1, address2, data2, data1 ^ data2, burst);
        if (errors == MAX_ERRORS_TO_REPORT-1)
            bdk_error("No further DRAM errors will be reported\n");
        return errors == MAX_ERRORS_TO_REPORT - 1;
    }
    else
        return -1;
}


/**
 * Get the amount of DRAM configured for a node. This is read from the LMC
 * controller after DRAM is setup.
 *
 * @param node   Node to query
 *
 * @return Size in megabytes
 */
uint64_t bdk_dram_get_size_mbytes(int node)
{
    /* Return zero if dram isn't enabled */
    if (!__bdk_is_dram_enabled(node))
        return 0;

    uint64_t memsize = 0;
    const int num_dram_controllers = __bdk_dram_get_num_lmc(node);
    for (int lmc = 0; lmc < num_dram_controllers; lmc++)
    {
        BDK_CSR_INIT(lmcx_config, node, BDK_LMCX_CONFIG(lmc));
        int num_ranks = bdk_pop(lmcx_config.s.init_status);
        uint64_t rank_size = 1ull << (28 + lmcx_config.s.pbank_lsb - lmcx_config.s.rank_ena);
        memsize += rank_size * num_ranks;
    }
    return memsize >> 20;
}


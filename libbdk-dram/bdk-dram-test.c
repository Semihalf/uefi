#include <bdk.h>

#define MAX_REPORT_ERRORS 100

/**
 * Convert a test enumeration into a string
 *
 * @param test   Test to convert
 *
 * @return String for display
 */
static const char *__bdk_dram_test_to_string(bdk_dram_test_t test)
{
    int prefix_len = sizeof("BDK_DRAM_TEST"); /* NULL is added so last _ is removed */

#define DO_CASE(s) case s: return #s + prefix_len

    switch (test)
    {
        DO_CASE(BDK_DRAM_TEST_SEQUENCIAL_WRITE_READ);
        DO_CASE(BDK_DRAM_TEST_RANDOM_XOR);
    }
    return "Unknown test. Update __bdk_dram_test_to_string()";
}


/**
 * Report a memory test error
 *
 * @param test     Which test failed
 * @param address  The address that failed
 * @param expected The expected value
 * @param received What was read from memory
 */
static void __bdk_dram_report_error(bdk_dram_test_t test, uint64_t address, uint64_t expected, uint64_t received)
{
    bdk_error("DRAM test %s: 0x%016lx expected 0x%016lx, received 0x%016lx, xor 0x%016lx\n",
              __bdk_dram_test_to_string(test), address, expected, received, expected ^ received);
}


/**
 * Perform a trivial sequencial write and the sequncial read test
 * on memory.
 *
 * @param start_address
 *               Physical address to start at
 * @param length Length of memory block
 *
 * @return Number of errors found. Zero is success.
 */
static int __bdk_dram_test_sequencial_write_read(uint64_t start_address, uint64_t length)
{
    int errors = 0;
    uint64_t *start = bdk_phys_to_ptr(start_address);
    uint64_t *end = start + length/8;
    uint64_t *ptr;

    /* Fill the memory with its addresses */
    for (ptr = start; ptr < end; ptr++)
        *ptr = (uint64_t)ptr;

    /* Read back the memory and see that it is correct */
    for (ptr = start; ptr < end; ptr++)
    {
        uint64_t received = *ptr;
        if (received != (uint64_t)ptr)
        {
            if (errors < MAX_REPORT_ERRORS)
                __bdk_dram_report_error(BDK_DRAM_TEST_SEQUENCIAL_WRITE_READ, bdk_ptr_to_phys(ptr), (uint64_t)ptr, received);
            errors++;
        }
    }

    return errors;
}


/**
 * Perform a random XOR test on memory.
 *
 * @param start_address
 *               Physical address to start at
 * @param length Length of memory block
 *
 * @return Number of errors found. Zero is success.
 */
static int __bdk_dram_test_random_xor(uint64_t start_address, uint64_t length)
{
    int read_loops = 100;
    int errors = 0;
    uint64_t *half = bdk_phys_to_ptr(start_address + length / 2);
    uint64_t pattern = bdk_rng_get_random64();
    uint64_t *p1;
    uint64_t *p2;

    /* Fill both halves of the memory area with identical randomized data */
    p1 = bdk_phys_to_ptr(start_address);
    p2 = half;
    while (p1 < half)
    {
        uint64_t t = pattern * (uint64_t)p1;
        *p1++ = t;
        *p2++ = t;
    }

    /* Make a series of passes over the memory areas. */
    while (read_loops--)
    {
        /* XOR the data with a random value, applying the change to both memory areas */
        pattern = bdk_rng_get_random64();

        p1 = bdk_phys_to_ptr(start_address);
        p2 = half;
        while (p1 < half)
        {
            *p1++ ^= pattern;
            *p2++ ^= pattern;
        }

        /* Look for differences in the areas. If there is a mismatch, reset
            both memory locations with the same pattern. Failing to do so
            means that on all subsequent passes the pair of locations remain
            out of sync giving spurious errors. */
        p1 = bdk_phys_to_ptr(start_address);
        p2 = half;
        while (p1 < half)
        {
            uint64_t d1 = *p1;
            uint64_t d2 = *p2;
            if (d1 != d2)
            {
                if (errors < MAX_REPORT_ERRORS)
                    __bdk_dram_report_error(BDK_DRAM_TEST_RANDOM_XOR, bdk_ptr_to_phys(p2), d1, d2);
                /* Synchronize the two areas, adjusting for the error. */
                *p1 = d2;
                errors++;
            }
            p1++;
            p2++;
        }
        bdk_thread_yield();
    }
    return errors;
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
int bdk_dram_test(bdk_dram_test_t test, uint64_t start_address, uint64_t length)
{
    switch (test)
    {
        case BDK_DRAM_TEST_SEQUENCIAL_WRITE_READ:
            return __bdk_dram_test_sequencial_write_read(start_address, length);
        case BDK_DRAM_TEST_RANDOM_XOR:
            bdk_rng_enable();
            return __bdk_dram_test_random_xor(start_address, length);
    }
    return -1;
}


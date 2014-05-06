#include "bdk.h"

/* Used for all memory reads/writes related to the test */
#define READ64(address) __bdk_dram_read64(address)
#define WRITE64(address, data) __bdk_dram_write64(address, data)

#define RETRY_LIMIT 1000

/* Report the circumstances of a failure and try re-reading the memory
 * location to see if the error is transient or permanent.
 *
 * Note: re-reading requires using evicting addresses
 */
static int retry_failure(int burst, uint64_t address, uint64_t data, uint64_t expected)
{
    if (__bdk_dram_report_error(address, data, expected, burst))
        return 1;

    int repass = 0;
    int refail = 0;
    int didFail = 1;

    /* Try re-reading the memory location. A transient error may fail on
     * on one read and work on another. Keep on retrying even when a
     * read succeeds.
     */
    for (int i = 0; i < RETRY_LIMIT; i++)
    {
        __bdk_dram_flush_to_mem(address);
        BDK_DCACHE_INVALIDATE;
        data = READ64(address);
        if ((data != expected))
        {
            refail++;
            didFail = 1;
        }
        else
        {
            if (didFail)
                printf("  ReRead%03u of 0x%08lX passed\n",
                    i, address);
            repass++;
            didFail = 0;
        }
    }
    printf("  Reread %d times: Passed: %d, Failed %d\n",
        RETRY_LIMIT, repass, refail);
    return 1;
}

/**
 * Fill an memory area with the address of each 64-bit word in the area.
 * Reread to confirm the pattern.
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area (exclusive)
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_self_addr(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;

    for (int burst = 0; burst < bursts; burst++)
    {
        /* Write the pattern to memory. Each location receives the address
         * of the location.
         */
        for (uint64_t address = area; address < max_address; address+=8)
            WRITE64(address, address);
        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Read by ascending address the written memory and confirm that it
         * has the expected data pattern.
         */
        for (uint64_t address = area; address < max_address; address+=8)
        {
            uint64_t data = READ64(address);
            if (bdk_unlikely(data != address))
                failures += retry_failure(burst, address, data, address);
        }
        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Read by descending address the written memory and confirm that it
         * has the expected data pattern.
         */
        uint64_t end = max_address - sizeof(uint64_t);
        for (uint64_t address = end; address >= area; address-=8)
        {
            uint64_t data = READ64(address);
            if (bdk_unlikely(data != address))
                failures += retry_failure(burst, address, data, address);
        }
        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Read from random addresses within the memory area.
         */
        uint64_t probes = (max_address - area) / 8;
        for (uint64_t i = 0; i < probes; i++)
        {
            uint64_t address = bdk_rng_get_random64() % (max_address - area);
            address += area;
            address &= -8;
            uint64_t data = READ64(address);
            if (bdk_unlikely(data != address))
                failures += retry_failure(burst, address, data, address);
        }
    }
    return failures;
}

/**
 * Write "pattern" and its compliment to memory and verify it was written
 * properly. Memory will be filled with DWORDs pattern, ~pattern, pattern,
 * ~pattern, ...
 *
 * @param area    Start physical address of memory
 * @param max_address
 *                End of physical memory region
 * @param pattern Pattern to write
 * @param passes  Number of time to repeat the test
 *
 * @return Number of errors, zero on success
 */
static uint32_t test_mem_pattern(uint64_t area, uint64_t max_address, uint64_t pattern,
    int passes)
{
    int failures = 0;

    for (int pass = 0; pass < passes; pass++)
    {
        if (pass & 0x1)
            pattern = ~pattern;

        for (uint64_t address = area; address < max_address; address += 8)
            WRITE64(address, pattern);
        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Read the written memory and confirm that it has the expected
         * data pattern.
         */
        for (uint64_t address = area; address < max_address; address += 8)
        {
            uint64_t data = READ64(address);
            if (bdk_unlikely(data != pattern))
                failures += retry_failure(pass, address, data, pattern);
        }
    }
    return failures;
}

/**
 * Walking zero written to memory, left shift
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_leftwalk0(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
    {
        for (uint64_t pattern = 1; pattern != 0; pattern = pattern << 1)
            failures += test_mem_pattern(area, max_address, ~pattern, 1);
    }
    return failures;
}

/**
 * Walking one written to memory, left shift
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_leftwalk1(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
    {
        for (uint64_t pattern = 1; pattern != 0; pattern = pattern << 1)
            failures += test_mem_pattern(area, max_address, pattern, 1);
    }
    return failures;
}

/**
 * Walking zero written to memory, right shift
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_rightwalk0(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
    {
        for (uint64_t pattern = 1ull << 63; pattern != 0; pattern = pattern >> 1)
            failures += test_mem_pattern(area, max_address, ~pattern, 1);
    }
    return failures;
}

/**
 * Walking one written to memory, right shift
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_rightwalk1(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
    {
        for (uint64_t pattern = 1ull<<63; pattern != 0; pattern = pattern >> 1)
            failures += test_mem_pattern(area, max_address, pattern, 1);
    }
    return failures;
}

/**
 * Apply the March C- testing algorithm to the given memory area.
 * 1) Write "pattern" to memory.
 * 2) Verify "pattern" and write "~pattern".
 * 3) Verify "~pattern" and write "pattern".
 * 4) Verify "pattern" and write "~pattern".
 * 5) Verify "~pattern" and write "pattern".
 * 6) Verify "pattern".
 *
 * @param area    Start of the physical memory area
 * @param max_address
 *                End of the physical memory area
 * @param pattern
 *
 * @return Number of errors, zero on success
 */
static int test_mem_march_c(uint64_t area, uint64_t max_address, uint64_t pattern)
{
    int failures = 0;

    /* Pass 1 ascending addresses, fill memory with pattern. */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase1, address incrementing, pattern 0x%016lx\n", area, max_address-1, pattern);
    for (uint64_t address = area; address < max_address; address += 8)
        WRITE64(address, pattern);

    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Pass 2: ascending addresses, read pattern and write ~pattern */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase2, address incrementing, pattern 0x%016lx\n", area, max_address-1, ~pattern);
    for (uint64_t address = area; address < max_address; address += 8)
    {
        uint64_t data = READ64(address);
        if (bdk_unlikely(data != pattern))
            failures += retry_failure(1, address, data, pattern);
        WRITE64(address, ~pattern);
    }

    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Pass 3: ascending addresses, read ~pattern and write pattern. */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase3, address incrementing, pattern 0x%016lx\n", area, max_address-1, pattern);
    for (uint64_t address = area; address < max_address; address += 8)
    {
        uint64_t data = READ64(address);
        if (bdk_unlikely(data != ~pattern))
            failures += retry_failure(1, address, data, ~pattern);
        WRITE64(address, pattern);
    }

    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Pass 4: descending addresses, read pattern and write ~pattern. */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase4, address decrementing, pattern 0x%016lx\n", area, max_address-1, ~pattern);
    uint64_t end = max_address - sizeof(uint64_t);
    for (uint64_t address = end; address >= area; address -= 8)
    {
        uint64_t data = READ64(address);
        if (bdk_unlikely(data != pattern))
            failures += retry_failure(1, address, data, pattern);
        WRITE64(address, ~pattern);
    }

    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Pass 5: descending addresses, read ~pattern and write pattern. */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase5, address decrementing, pattern 0x%016lx\n", area, max_address-1, pattern);
    for (uint64_t address = end; address >= area; address -= 8)
    {
        uint64_t data = READ64(address);
        if (bdk_unlikely(data != ~pattern))
            failures += retry_failure(1, address, data, ~pattern);
        WRITE64(address, pattern);
    }

    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Pass 6: ascending addresses, read pattern. */
    BDK_TRACE("    [0x%016lx:0x%016lx] Phase6, address incrementing\n", area, max_address-1);
    for (uint64_t address = area; address < max_address; address += 8)
    {
        uint64_t data = READ64(address);
        if (bdk_unlikely(data != pattern))
            failures += retry_failure(1, address, data, pattern);
    }

    return failures;
}

/**
 * Use test_mem_march_c() with a all ones pattern
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_solid(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
        failures += test_mem_march_c(area, max_address, -1);
    return failures;
}

/**
 * Use test_mem_march_c() with a 0x55 pattern
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_checkerboard(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
        failures += test_mem_march_c(area, max_address, 0x5555555555555555L);
    return failures;
}

/**
 * Write a pseudo random pattern to memory and verify it
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_random(uint64_t area, uint64_t max_address, int bursts)
{
    /* This constant is used to increment the pattern after every DWORD. This
       makes only the first DWORD truly random, but saves us processing
       power generatign the random values */
    const uint64_t INC = 0x1010101010101010ULL;

    int failures = 0;
    for (int burst = 0; burst < bursts; burst++)
    {
        const uint64_t init_pattern = bdk_rng_get_random64();
        uint64_t pattern = init_pattern;

        /* Write the pattern to memory. Each location receives the address
         * of the location. A second write pass is needed to force all of
         * the cached memory out to the DDR.
         */
        for (uint64_t address = area; address < max_address; address += 8)
        {
            WRITE64(address, pattern);
            pattern += INC;
        }

        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Read the written memory and confirm that it has the expected
         * data pattern.
         */
        pattern = init_pattern;
        for (uint64_t address = area; address < max_address; address += 8)
        {
            uint64_t data = READ64(address);
            if (bdk_unlikely(data != pattern))
                failures += retry_failure(burst, address, data, pattern);
            pattern += INC;
        }
    }
    return failures;
}

/**
 * retry_xor_failure
 *
 * @param burst
 * @param address1
 * @param address2
 */
static void retry_xor_failure(int burst, uint64_t address1, uint64_t address2)
{
    int repass = 0;
    int refail = 0;

    for (int i = 0; i < RETRY_LIMIT; i++)
    {
        __bdk_dram_flush_to_mem(address1);
        __bdk_dram_flush_to_mem(address2);
        BDK_DCACHE_INVALIDATE;

        uint64_t d1 = READ64(address1);
        uint64_t d2 = READ64(address2);

        if (d1 != d2)
        {
            refail++;
        }
        else
        {
            if (!repass)
                printf("  ReRead%03u passes\n", i);
            repass++;
        }
    }
    printf("  Reread %d times: Passed: %d, Failed %d\n",
        RETRY_LIMIT, repass, refail);
}

/**
 * test_mem_xor
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_xor(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;

    uint64_t extent = max_address - area;
    uint64_t count = (extent / sizeof(uint64_t)) / 2;

    /* Fill both halves of the memory area with identical randomized data.
     */
    uint64_t address1 = area;
    uint64_t address2 = area + count * sizeof(uint64_t);

    uint64_t pattern = bdk_rng_get_random64();

    for (uint64_t j = 0; j < count; j++)
    {
        uint64_t p = pattern * address1;
        WRITE64(address1, p);
        WRITE64(address2, p);
        address1 += 8;
        address2 += 8;
    }
    __bdk_dram_flush_to_mem_range(area, max_address);
    BDK_DCACHE_INVALIDATE;

    /* Make a series of passes over the memory areas. */
    for (int burst = 0; burst < bursts; burst++)
    {
        /* XOR the data with a random value, applying the change to both
         * memory areas.
         */
        address1 = area;
        address2 = area + count * sizeof(uint64_t);

        pattern = bdk_rng_get_random64();

        for (uint64_t j = 0; j < count; j++)
        {
            WRITE64(address1, READ64(address1) ^ pattern);
            WRITE64(address2, READ64(address2) ^ pattern);
            address1 += 8;
            address2 += 8;
        }

        __bdk_dram_flush_to_mem_range(area, max_address);
        BDK_DCACHE_INVALIDATE;

        /* Look for differences in the areas. If there is a mismatch, reset
         * both memory locations with the same pattern. Failing to do so
         * means that on all subsequent passes the pair of locations remain
         * out of sync giving spurious errors.
         */
        address1 = area;
        address2 = area + count * sizeof(uint64_t);
        for (uint64_t j = 0; j < count; j++)
        {
            uint64_t d1 = READ64(address1);
            uint64_t d2 = READ64(address2);
            if (bdk_unlikely(d1 != d2))
            {
                if (__bdk_dram_report_error2(address1, d1, address2, d2, burst) == 0)
                    retry_xor_failure(burst, address1, address2);

                // Synchronize the two areas, adjusting for the error.
                WRITE64(address1, d2);
                WRITE64(address2, d2);
                failures++;
            }
            address1 += 8;
            address2 += 8;
        }
    }
    return failures;
}

/**
 * test_mem_rows
 *
 * @param area   Start of the physical memory area
 * @param max_address
 *               End of the physical memory area
 * @param bursts Number of time to repeat the test over the entire area
 *
 * @return Number of errors, zero on success
 */
int __bdk_dram_test_mem_rows(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;
    uint64_t pattern = 0x0;
    uint64_t extent = max_address - area;
    uint64_t count  = (extent / sizeof(uint64_t)) / 2;

    /* Fill both halves of the memory area with identical data pattern.
     */
    uint64_t address1 = area;
    uint64_t address2 = area + count * sizeof(uint64_t);

    for (uint64_t j = 0; j < (count / 2); j++)
    {
        WRITE64(address1, pattern);
        WRITE64(address2, pattern);
        address1 += 8;
        address2 += 8;
        WRITE64(address1, ~pattern);
        WRITE64(address2, ~pattern);
        address1 += 8;
        address2 += 8;
    }

    /* Make a series of passes over the memory areas. */
    for (int burst = 0; burst < bursts; burst++)
    {
        /* XOR the data with a random value, applying the change to both
         * memory areas.
         */
        address1 = area;
        address2 = area + count * sizeof(uint64_t);

        for (uint64_t j = 0; j < count; j++)
        {
            WRITE64(address1, READ64(address1));
            WRITE64(address2, READ64(address2));
            address1 += 8;
            address2 += 8;
        }

        /* Look for differences in the areas. If there is a mismatch, reset
         * both memory locations with the same pattern. Failing to do so
         * means that on all subsequent passes the pair of locations remain
         * out of sync giving spurious errors.
         */
        address1 = area;
        address2 = area + count * sizeof(uint64_t);
        for (uint64_t j = 0; j < count; j++)
        {
            uint64_t d1 = READ64(address1);
            uint64_t d2 = READ64(address2);
            if (bdk_unlikely(d1 != d2))
            {
                __bdk_dram_report_error2(address1, d1, address2, d2, burst);
                failures++;
            }
            address1 += 8;
            address2 += 8;
        }
    }
    return failures;
}

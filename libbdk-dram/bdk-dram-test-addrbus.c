#include "bdk.h"

/* Used for all memory reads/writes related to the test */
#define READ64(address) __bdk_dram_read64(address)
#define WRITE64(address, data) __bdk_dram_write64(address, data)

/*----------------*/
/*  search_alias  */
/*----------------*/
static int search_alias(uint64_t base, uint64_t p1, uint64_t max_address)
{
    int result;
    uint64_t p3;
    uint64_t offset;

    result = 0;
    offset = 0x80LL;

    while (1)
    {
        p3 = base | offset;

        if ((p3 != p1) && (READ64(p3) == 0xAAAAAAAAAAAAAAAALL))
        {
            result = 1;
        }

        offset = offset << 1;
        if (((base | offset) > max_address) ||
            (offset & p3))
        {
            return result;
        }
    }
    return result;
}

/*-----------------*/
/*  test_addr_bus  */
/*-----------------*/
int __bdk_dram_test_mem_address_bus(uint64_t area, uint64_t max_address, int bursts)
{
    int failures = 0;

    /* Find the closest Power of Two address within 'area'. This is the
     * starting address for the scan. If there is no such address, start
     * with the 'area' and count up.
     */
    uint64_t address = 0x80LL;
    while (address < area)
    {
        address <<= 1;
    }

    if (address > max_address)
    {
        /* Next power of two address falls outside the address range.*/
        address = area;
    }

    for (int burst = 0; burst < bursts; burst++)
    {
        /* Fill the memory at selected locations with a checkerboard
         * pattern.
         *
         * Force the data pattern out by writing to both a primary and
         * evicting address. A write to the evicting address causes the
         * L2C to write out the primary address.
         */
        uint64_t base = address;
        uint64_t start = base;

        while (1)
        {
            uint64_t offset = 0x80LL;

            while (1)
            {
                address = base | offset;

                WRITE64(address, 0x5555555555555555LL);
                __bdk_dram_flush_to_mem(address);

                offset = offset << 1;
                if (((base | offset) > max_address) ||
                    (offset & address))
                {
                    base = address;
                    break;
                }
            }

            if (address & 0x80LL)
                break;
        }

        /* Compare with expected: Look at each memory location written
             * in the preceding step. Report any mismatches as failures.
             * This catches stuck HIGH address bits.
             */
        address = start;
        base = address;

        while (1)
        {
            uint64_t offset = 0x80LL;

            while (1)
            {
                address = base | offset;

                if (READ64(address) != 0x5555555555555555LL)
                {
                    failures++;
                }

                offset = offset << 1;
                if (((base | offset) > max_address) ||
                    (offset & address))
                {
                    base = address;
                    break;
                }
            }

            if (address & 0x80LL)
                break;
        }

        /* Check for address aliasing */
        address = start;
        base = address;

        while (1)
        {
            uint64_t offset = 0x80LL;

            while (1)
            {
                address = base | offset;

                /* Write the inverse pattern to the target address. All
                         * other address should have the normal pattern.
                         */
                WRITE64(address, 0xAAAAAAAAAAAAAAAALL);
                __bdk_dram_flush_to_mem(address);

                /* Scan across all test addresses looking for a match
                 * against the inverse pattern. If there is a match and it
                 * is not at the target address, the target address write
                 * failed and the pattern went to an aliased address.
                 */
                if (search_alias(start, address, max_address))
                {
                    failures++;
                }

                /* Reset the target address to the normal pattern. */
                WRITE64(address, 0x5555555555555555LL);
                __bdk_dram_flush_to_mem(address);

                offset = offset << 1;
                if (((base | offset) > max_address) ||
                    (offset & address))
                {
                    base = address;
                    break;
                }
            }

            if (address & 0x80LL)
                break;
        }
    }

    return failures;
}


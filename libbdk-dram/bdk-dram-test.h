/**
 * @file
 *
 * Functions for configuring DRAM.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup dram DRAM related functions
 * @{
 */

typedef enum
{
    BDK_DRAM_TEST_SEQUENCIAL_WRITE_READ,
    BDK_DRAM_TEST_RANDOM_XOR,
} bdk_dram_test_t;

extern int bdk_dram_test(bdk_dram_test_t test, uint64_t start_address, uint64_t length);

/** @} */


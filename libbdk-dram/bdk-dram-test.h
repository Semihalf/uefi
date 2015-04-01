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

/* This is the external interface for callers */
extern const char* bdk_dram_get_test_name(int test);
extern int bdk_dram_test(int test, uint64_t start_address, uint64_t length);
extern int bdk_dram_get_batch_mode(void);
extern void bdk_dram_set_batch_mode(int mode);

/* These variables count the number of ECC errors. They should only be accessed atomically */
/* Keep the counts per memory channel (LMC) for more detail. */
#define MAX_MEM_CHANS 4
extern int64_t __bdk_dram_ecc_single_bit_errors[MAX_MEM_CHANS];
extern int64_t __bdk_dram_ecc_double_bit_errors[MAX_MEM_CHANS];

/* These are internal support functions */
extern void __bdk_dram_flush_to_mem(uint64_t address);
extern void __bdk_dram_flush_to_mem_range(uint64_t area, uint64_t max_address);
extern void __bdk_dram_report_error(uint64_t address, uint64_t data, uint64_t correct, int burst, int fails);
extern void __bdk_dram_report_error2(uint64_t address1, uint64_t data1, uint64_t address2, uint64_t data2, int burst, int fails);
extern int  __bdk_dram_retry_failure(int burst, uint64_t address, uint64_t data, uint64_t expected);
extern int  __bdk_dram_retry_failure2(int burst, uint64_t address1, uint64_t data1, uint64_t address2, uint64_t data2);

static inline void __bdk_dram_write64(uint64_t address, uint64_t data)
{
    /* The DRAM code doesn't use the normal bdk_phys_to_ptr() because of the
       NULL check in it. This greatly slows down the memory tests */
    volatile uint64_t *ptr = (void*)address;
    *ptr = data;
}

static inline uint64_t __bdk_dram_read64(uint64_t address)
{
    /* The DRAM code doesn't use the normal bdk_phys_to_ptr() because of the
       NULL check in it. This greatly slows down the memory tests */
    volatile uint64_t *ptr = (void*)address;
    return *ptr;
}

/* This is the function prototype that all test must use. "start_address" is
   the first byte to be tested (inclusive), "end_address" is the address right
   after the region (exclusive). For example, if start_address equals
   end_address, no memory will be tested */
typedef int (*__bdk_dram_test_t)(uint64_t start_address, uint64_t end_address, int bursts);

/* These are the actual tests that get run. Each test is meant to be run with
   a small range and repeated on lots of cores and large ranges. The return
   value is the number of errors found */
extern int __bdk_dram_test_mem_address_bus(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_checkerboard(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_data_bus(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_leftwalk0(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_leftwalk1(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_random(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_rightwalk0(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_rightwalk1(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_rows(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_self_addr(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_solid(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_mem_xor(uint64_t start_address, uint64_t end_address, int bursts);
extern int __bdk_dram_test_fast_scan(uint64_t area, uint64_t max_address, int bursts);

/** @} */


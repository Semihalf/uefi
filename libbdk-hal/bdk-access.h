/**
 * @file
 * Function prototypes for accessing memory and CSRs on Octeon.
 *
 * <hr>$Revision: 38306 $<hr>
 *
 * @addtogroup hal
 * @{
*/

/* We're going to assume that if we are compiling for Mips then we must be
    running natively on Octoen. It is possible that this code could be
    compiled on a non Octeon Mips that is acting as a PCI/PCIe host. In this
    case this assumption will be wrong and cause issues We can't key off of
    __octeon__ since some people use stock gcc toolchains */
#define BDK_FUNCTION static inline

/**
 * Convert a memory pointer (void*) into a hardware compatable
 * memory address (uint64_t). Octeon hardware widgets don't
 * understand logical addresses.
 *
 * @param ptr    C style memory pointer
 * @return Hardware physical address
 */
BDK_FUNCTION uint64_t bdk_ptr_to_phys(void *ptr);

/**
 * Convert a hardware physical address (uint64_t) into a
 * memory pointer (void *).
 *
 * @param physical_address
 *               Hardware physical address to memory
 * @return Pointer to memory
 */
BDK_FUNCTION void *bdk_phys_to_ptr(uint64_t physical_address);

BDK_FUNCTION void bdk_write64_int64(uint64_t address, int64_t value);
BDK_FUNCTION void bdk_write64_uint64(uint64_t address, uint64_t value);
BDK_FUNCTION void bdk_write64_int32(uint64_t address, int32_t value);
BDK_FUNCTION void bdk_write64_uint32(uint64_t address, uint32_t value);
BDK_FUNCTION void bdk_write64_int16(uint64_t address, int16_t value);
BDK_FUNCTION void bdk_write64_uint16(uint64_t address, uint16_t value);
BDK_FUNCTION void bdk_write64_int8(uint64_t address, int8_t value);
BDK_FUNCTION void bdk_write64_uint8(uint64_t address, uint8_t value);

BDK_FUNCTION int64_t bdk_read64_int64(uint64_t address);
BDK_FUNCTION uint64_t bdk_read64_uint64(uint64_t address);
BDK_FUNCTION int32_t bdk_read64_int32(uint64_t address);
BDK_FUNCTION uint32_t bdk_read64_uint32(uint64_t address);
BDK_FUNCTION int16_t bdk_read64_int16(uint64_t address);
BDK_FUNCTION uint16_t bdk_read64_uint16(uint64_t address);
BDK_FUNCTION int8_t bdk_read64_int8(uint64_t address);
BDK_FUNCTION uint8_t bdk_read64_uint8(uint64_t address);

/**
 * Number of the Core on which the program is currently running.
 *
 * @return Number of cores
 */
BDK_FUNCTION unsigned int bdk_get_core_num(void);

/**
 * Returns the number of bits set in the provided value.
 * Simple wrapper for POP instruction.
 *
 * @param val    32 bit value to count set bits in
 *
 * @return Number of bits set
 */
BDK_FUNCTION uint32_t bdk_pop(uint32_t val);

/**
 * Returns the number of bits set in the provided value.
 * Simple wrapper for DPOP instruction.
 *
 * @param val    64 bit value to count set bits in
 *
 * @return Number of bits set
 */
BDK_FUNCTION int bdk_dpop(uint64_t val);

/**
 * Wait for the specified number of core clock cycles
 *
 * @param cycles
 */
BDK_FUNCTION void bdk_wait(uint64_t cycles);

/**
 * Wait for the specified number of micro seconds
 *
 * @param usec   micro seconds to wait
 */
extern void bdk_wait_usec(uint64_t usec);

/**
 * Perform a soft reset of Octeon
 *
 * @return
 */
extern void bdk_reset_octeon(void);

#undef BDK_FUNCTION

/** @} */

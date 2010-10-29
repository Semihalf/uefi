/**
 * @file
 *
 * This file provides support for the processor local scratch memory.
 * Scratch memory is byte addressable - all addresses are byte addresses.
 *
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/* Note: This define must be a long, not a long long in order to compile
        without warnings for both 32bit and 64bit. */
#define BDK_SCRATCH_BASE       (-32768l) /* 0xffffffffffff8000 */


/**
 * Reads an 8 bit value from the processor local scratchpad memory.
 *
 * @param address byte address to read from
 *
 * @return value read
 */
static inline uint8_t bdk_scratch_read8(uint64_t address)
{
    return *CASTPTR(volatile uint8_t, BDK_SCRATCH_BASE + address);
}
/**
 * Reads a 16 bit value from the processor local scratchpad memory.
 *
 * @param address byte address to read from
 *
 * @return value read
 */
static inline uint16_t bdk_scratch_read16(uint64_t address)
{
    return *CASTPTR(volatile uint16_t, BDK_SCRATCH_BASE + address);
}
/**
 * Reads a 32 bit value from the processor local scratchpad memory.
 *
 * @param address byte address to read from
 *
 * @return value read
 */
static inline uint32_t bdk_scratch_read32(uint64_t address)
{
    return *CASTPTR(volatile uint32_t, BDK_SCRATCH_BASE + address);
}
/**
 * Reads a 64 bit value from the processor local scratchpad memory.
 *
 * @param address byte address to read from
 *
 * @return value read
 */
static inline uint64_t bdk_scratch_read64(uint64_t address)
{
    return *CASTPTR(volatile uint64_t, BDK_SCRATCH_BASE + address);
}



/**
 * Writes an 8 bit value to the processor local scratchpad memory.
 *
 * @param address byte address to write to
 * @param value   value to write
 */
static inline void bdk_scratch_write8(uint64_t address, uint64_t value)
{
    *CASTPTR(volatile uint8_t, BDK_SCRATCH_BASE + address) = (uint8_t)value;
}
/**
 * Writes a 32 bit value to the processor local scratchpad memory.
 *
 * @param address byte address to write to
 * @param value   value to write
 */
static inline void bdk_scratch_write16(uint64_t address, uint64_t value)
{
    *CASTPTR(volatile uint16_t, BDK_SCRATCH_BASE + address) = (uint16_t)value;
}
/**
 * Writes a 16 bit value to the processor local scratchpad memory.
 *
 * @param address byte address to write to
 * @param value   value to write
 */
static inline void bdk_scratch_write32(uint64_t address, uint64_t value)
{
    *CASTPTR(volatile uint32_t, BDK_SCRATCH_BASE + address) = (uint32_t)value;
}
/**
 * Writes a 64 bit value to the processor local scratchpad memory.
 *
 * @param address byte address to write to
 * @param value   value to write
 */
static inline void bdk_scratch_write64(uint64_t address, uint64_t value)
{
    *CASTPTR(volatile uint64_t, BDK_SCRATCH_BASE + address) = value;
}

/** @} */

#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(KEY_MEMORY);

/**
 * Read from KEY memory
 *
 * @param address Address (byte) in key memory to read
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @return Value from key memory
 */
uint64_t bdk_key_read(uint64_t address)
{
    address |= 0x800120ull << 40;
    return bdk_read64_uint64(address);
}


/**
 * Write to KEY memory
 *
 * @param address Address (byte) in key memory to write
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @param value   Value to write to key memory
 */
void bdk_key_write(uint64_t address, uint64_t value)
{
    address |= 0x800120ull << 40;
    bdk_write64_uint64(address, value);
}


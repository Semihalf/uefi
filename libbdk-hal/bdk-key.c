#include <bdk.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(KEY_MEMORY);

/**
 * Read from KEY memory
 *
 * @param node    Which node to use
 * @param address Address (byte) in key memory to read
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @return Value from key memory
 */
uint64_t bdk_key_read(bdk_node_t node, uint64_t address)
{
    return BDK_CSR_READ(node, BDK_KEY_MEMX(address >> 3));
}


/**
 * Write to KEY memory
 *
 * @param node    Which node to use
 * @param address Address (byte) in key memory to write
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @param value   Value to write to key memory
 */
void bdk_key_write(bdk_node_t node, uint64_t address, uint64_t value)
{
    return BDK_CSR_WRITE(node, BDK_KEY_MEMX(address >> 3), value);
}


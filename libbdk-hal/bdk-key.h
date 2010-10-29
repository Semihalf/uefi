/**
 * @file
 *
 * Interface to the on chip key memory. Key memory is
 * 8k on chip that is inaccessible from off chip. It can
 * also be cleared using an external hardware pin.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 */

#define BDK_KEY_MEM_SIZE 8192  /* Size in bytes */

/**
 * Read from KEY memory
 *
 * @param address Address (byte) in key memory to read
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @return Value from key memory
 */
extern uint64_t bdk_key_read(uint64_t address);

/**
 * Write to KEY memory
 *
 * @param address Address (byte) in key memory to write
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @param value   Value to write to key memory
 */
extern void bdk_key_write(uint64_t address, uint64_t value);


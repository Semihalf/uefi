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
static inline uint64_t bdk_key_read(uint64_t address)
{
    bdk_addr_t ptr;

    ptr.u64 = 0;
    ptr.sio.mem_region  = BDK_IO_SEG;
    ptr.sio.is_io       = 1;
    ptr.sio.did         = BDK_OCT_DID_KEY_RW;
    ptr.sio.offset      = address;

    return bdk_read64_uint64(ptr.u64);
}


/**
 * Write to KEY memory
 *
 * @param address Address (byte) in key memory to write
 *                0 <= address < BDK_KEY_MEM_SIZE
 * @param value   Value to write to key memory
 */
static inline void bdk_key_write(uint64_t address, uint64_t value)
{
    bdk_addr_t ptr;

    ptr.u64 = 0;
    ptr.sio.mem_region  = BDK_IO_SEG;
    ptr.sio.is_io       = 1;
    ptr.sio.did         = BDK_OCT_DID_KEY_RW;
    ptr.sio.offset      = address;

    bdk_write64_uint64(ptr.u64, value);
}


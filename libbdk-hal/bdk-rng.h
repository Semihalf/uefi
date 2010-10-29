/**
 * @file
 *
 * Function and structure definitions for random number generator hardware
 *
 * <hr>$Revision: 49448 $<hr>
 */

/**
 * Enables the random number generator. Must be called before RNG is used
 */
extern void bdk_rng_enable(void);

/**
 * Reads 8 bits of random data from Random number generator
 *
 * @return random data
 */
extern uint8_t bdk_rng_get_random8(void);

/**
 * Reads 16 bits of random data from Random number generator
 *
 * @return random data
 */
extern uint16_t bdk_rng_get_random16(void);

/**
 * Reads 32 bits of random data from Random number generator
 *
 * @return random data
 */
extern uint32_t bdk_rng_get_random32(void);

/**
 * Reads 64 bits of random data from Random number generator
 *
 * @return random data
 */
extern uint64_t bdk_rng_get_random64(void);

/**
 * Requests random data from the RNG block asynchronously using and IOBDMA operation.
 * The random data will be written into the cores
 * local memory at the specified address.  A SYNCIOBDMA
 * operation should be issued to stall for completion of the write.
 *
 * @param scr_addr  Address in scratch memory to put the result
 *                  MUST be a multiple of 8 bytes
 * @param num_bytes Number of bytes of random data to write at
 *                  scr_addr
 *                  MUST be a multiple of 8 bytes
 *
 * @return 0 on success
 *         1 on error
 */
extern int bdk_rng_request_random_async(uint64_t scr_addr, uint64_t num_bytes);


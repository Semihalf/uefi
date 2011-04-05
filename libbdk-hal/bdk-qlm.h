
/**
 * @file
 *
 * Function and structure definitions for QLM manipulation
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Initialize the internal QLM JTAG logic to allow programming
 * of the JTAG chain by the cvmx_qlm_jtag_*() functions. These functions should
 * only be used at the direction of Cavium Networks. Programming incorrect
 * values into the JTAG chain can cause chip damage.
 */
extern void bdk_qlm_jtag_init(void);

/**
 * Write up to 32bits into the QLM jtag chain. Bits are shifted
 * into the MSB and out the LSB, so you should shift in the low
 * order bits followed by the high order bits. The JTAG chain for
 * CN52XX and CN56XX is 4 * 268 bits long, or 1072. The JTAG chain
 * for CN63XX is 4 * 300 bits long, or 1200. The JTAG chain
 * for CN68XX is 4 * 304 bits long, or 1216.

 *
 * @param qlm    QLM to shift value into
 * @param bits   Number of bits to shift in (1-32).
 * @param data   Data to shift in. Bit 0 enters the chain first, followed by
 *               bit 1, etc.
 *
 * @return The low order bits of the JTAG chain that shifted out of the
 *         circle.
 */
extern uint32_t bdk_qlm_jtag_shift(int qlm, int bits, uint32_t data);

/**
 * Shift long sequences of zeros into the QLM JTAG chain. It is
 * common to need to shift more than 32 bits of zeros into the
 * chain. This function is a convience wrapper around cvmx_qlm_jtag_shift() to
 * shift more than 32 bits of zeros at a time.
 *
 * @param qlm    QLM to shift zeros into
 * @param bits
 */
extern void bdk_qlm_jtag_shift_zeros(int qlm, int bits);

/**
 * Program the QLM JTAG chain into all lanes of the QLM. You must
 * have already shifted in the proper number of bits into the
 * JTAG chain. Updating invalid values can possibly cause chip damage.
 *
 * @param qlm    QLM to program
 */
extern void bdk_qlm_jtag_update(int qlm);

/**
 * Load the QLM JTAG chain with data from all lanes of the QLM.
 *
 * @param qlm    QLM to program
 */
extern void bdk_qlm_jtag_capture(int qlm);

/**
 * CN68XX pass 1.x QLM tweak. This function tweaks the JTAG setting for a QLMs
 * to run better at 6.25Ghz. It will make no changes to QLMs running at other
 * speeds.
 */
extern void bdk_qlm_cn68xx_6250(void);

/** @} */

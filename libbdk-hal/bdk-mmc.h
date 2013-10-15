/**
 * @file
 *
 * Interface to the MMC, eMMC, or SD
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Initialize a MMC for read/write
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 *
 * @return Size of the SD card, zero on failure
 */
extern int64_t bdk_mmc_initialize(int chip_sel);

/**
 * Read blocks from a MMC card
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 * @param address  Offset into the card in bytes. Must be a multiple of 512
 * @param buffer   Buffer to read into
 * @param length   Length to read in bytes. Must be a multiple of 512
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_mmc_read(int chip_sel, uint64_t address, void *buffer, int length);

/**
 * Write blocks to a MMC card
 *
 * @author creese (10/14/2013)
 * @param chip_sel Chip select to use
 * @param address  Offset into the card in bytes. Must be a multiple of 512
 * @param buffer   Buffer to write
 * @param length   Length to write in bytes. Must be a multiple of 512
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_mmc_write(int chip_sel, uint64_t address, const void *buffer, int length);

/** @} */

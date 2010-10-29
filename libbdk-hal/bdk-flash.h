/**
 * @file
 *
 * This file provides bootbus flash operations
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef struct
{
    int start_offset;
    int block_size;
    int num_blocks;
} bdk_flash_region_t;

/**
 * Initialize the flash access library
 */
void bdk_flash_initialize(void);

/**
 * Return a pointer to the flash chip
 *
 * @param chip_id Chip ID to return
 * @return NULL if the chip doesn't exist
 */
void *bdk_flash_get_base(int chip_id);

/**
 * Return the number of erasable regions on the chip
 *
 * @param chip_id Chip to return info for
 * @return Number of regions
 */
int bdk_flash_get_num_regions(int chip_id);

/**
 * Return information about a flash chips region
 *
 * @param chip_id Chip to get info for
 * @param region  Region to get info for
 * @return Region information
 */
const bdk_flash_region_t *bdk_flash_get_region_info(int chip_id, int region);

/**
 * Erase a block on the flash chip
 *
 * @param chip_id Chip to erase a block on
 * @param region  Region to erase a block in
 * @param block   Block number to erase
 * @return Zero on success. Negative on failure
 */
int bdk_flash_erase_block(int chip_id, int region, int block);

/**
 * Write a block on the flash chip
 *
 * @param chip_id Chip to write a block on
 * @param region  Region to write a block in
 * @param block   Block number to write
 * @param data    Data to write
 * @return Zero on success. Negative on failure
 */
int bdk_flash_write_block(int chip_id, int region, int block, const void *data);

/**
 * Erase and write data to a flash
 *
 * @param address Memory address to write to
 * @param data    Data to write
 * @param len     Length of the data
 * @return Zero on success. Negative on failure
 */
int bdk_flash_write(void *address, const void *data, int len);

/** @} */

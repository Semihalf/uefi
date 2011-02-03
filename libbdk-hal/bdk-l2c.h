/**
 * @file
 *
 * Interface to the Level 2 Cache (L2C) control, measurement, and debugging
 * facilities.
 *
 * <hr>$Revision: 50663 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * Perform one time initialization of L2 for improved
 * performance. This can be called after L2 is in use.
 *
 * @return Zero on success, negative on failure.
 */
int bdk_l2c_initialize(void);

/**
 * Return the L2 Cache way partitioning for a given core.
 *
 * @param core  The core processor of interest.
 *
 * @return    The mask specifying the partitioning. 0 bits in mask indicates
 *              the cache 'ways' that a core can evict from.
 *            -1 on error
 */
int bdk_l2c_get_core_way_partition(int core);

/**
 * Partitions the L2 cache for a core
 *
 * @param core   The core that the partitioning applies to.
 * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core
 *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines
 *             from that way. There must be at least one allowed way (0 bit) in the mask.
 *
 * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have
 *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from
 *        all ways regardless of the partitioning.
 */
int bdk_l2c_set_core_way_partition(int core, uint32_t mask);

/**
 * Return the L2 Cache way partitioning for the hw blocks.
 *
 * @return    The mask specifying the reserved way. 0 bits in mask indicates
 *              the cache 'ways' that a core can evict from.
 *            -1 on error
 */
int bdk_l2c_get_hw_way_partition(void);

/**
 * Partitions the L2 cache for the hardware blocks.
 *
 * @param mask The partitioning of the ways expressed as a binary mask. A 0 bit allows the core
 *             to evict cache lines from a way, while a 1 bit blocks the core from evicting any lines
 *             from that way. There must be at least one allowed way (0 bit) in the mask.
 *
 * @note  If any ways are blocked for all cores and the HW blocks, then those ways will never have
 *        any cache lines evicted from them.  All cores and the hardware blocks are free to read from
 *        all ways regardless of the partitioning.
 */
int bdk_l2c_set_hw_way_partition(uint32_t mask);

/**
 * Locks a specified memory region in the L2 cache.
 *
 * Note that if not all lines can be locked, that means that all
 * but one of the ways (associations) available to the locking
 * core are locked.  Having only 1 association available for
 * normal caching may have a significant adverse affect on performance.
 * Care should be taken to ensure that enough of the L2 cache is left
 * unlocked to allow for normal caching of DRAM.
 *
 * @param start  Physical address of the start of the region to lock
 * @param len    Length (in bytes) of region to lock
 *
 * @return Number of requested lines that where not locked.
 *         0 on success (all locked)
 */
int bdk_l2c_lock_mem_region(uint64_t start, uint64_t len);

/**
 * Unlocks a region of memory that is locked in the L2 cache
 *
 * @param start  start physical address
 * @param len    length (in bytes) to unlock
 *
 * @return Number of locked lines that the call unlocked
 */
int bdk_l2c_unlock_mem_region(uint64_t start, uint64_t len);

/**
 * Flushes (and unlocks) the entire L2 cache.
 * IMPORTANT: Must only be run by one core at a time due to use
 * of L2C debug features.
 */
void bdk_l2c_flush(void);

/**
 *
 * @return Returns the size of the L2 cache in bytes,
 * -1 on error (unrecognized model)
 */
int bdk_l2c_get_cache_size_bytes(void);

/**
 * Return the number of sets in the L2 Cache
 *
 * @return
 */
int bdk_l2c_get_num_sets(void);

/**
 * Return log base 2 of the number of sets in the L2 cache
 * @return
 */
int bdk_l2c_get_set_bits(void);

/**
 * Return the number of associations in the L2 Cache
 *
 * @return
 */
int bdk_l2c_get_num_assoc(void);

/** @} */

/**
 * @file
 *
 * Functions for reading Cavium chip fuses.
 *
 * <hr>$Revision: 49448 $<hr>
 */


/**
 * Read a single fuse bit
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
extern int bdk_fuse_read(bdk_node_t node, int fuse);

/**
 * Soft blow a fuse. Soft blown fuses keep there new value over soft resets, but
 * not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_fuse_soft_blow(bdk_node_t node, int fuse);

/**
 * Read a single fuse bit from the field set (FUSF)
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
extern int bdk_fuse_field_read(bdk_node_t node, int fuse);

/**
 * Soft blow a fuse in the field set (FUSF). Soft blown fuses
 * keep there new value over soft resets, but not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_fuse_field_soft_blow(bdk_node_t node, int fuse);

/**
 * Fuse initialization is called very early in startup to determine if fuses are
 * properly setup. This function is called before the GTI clock is setup, so care
 * must be taken with delays. It is also called on secondary nodes before CCPI
 * is up and running. This function may trigger a soft reset internally, forcing
 * a reload of fuse information.
 *
 * @param node   Node to check and initialize fuses on
 *
 * @return Zero on success, negative on failure
 */
extern int bdk_fuse_init(bdk_node_t node);


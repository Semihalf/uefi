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


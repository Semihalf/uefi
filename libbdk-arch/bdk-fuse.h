/**
 * @file
 *
 * Functions for reading Octeon chip fuses.
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
extern int bdk_fuse_read(int fuse);


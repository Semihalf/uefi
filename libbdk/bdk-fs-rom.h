/**
 * @file
 *
 * This is the structure used for all ROM based files
 *
 * <hr>$Revision: 49448 $<hr>
 */

typedef struct
{
    const char *name;
    const char *data;
    unsigned int length;
} bdk_fs_rom_t;

/**
 * This is the structure used for all ROM based files
 */
extern const bdk_fs_rom_t bdk_fs_rom_files[];


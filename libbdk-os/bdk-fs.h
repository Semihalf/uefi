/**
 * @file
 *
 * Infastructure to allow standard C file IO to various file systems.
 *
 * <hr>$Revision: 49448 $<hr>
 * @defgroup internal Structures and functions for internal use only
 * @{
 */

struct stat;

typedef struct
{
    void *fs_state;
    const struct bdk_fs_ops_s *ops;
    const char *filename;
    uint64_t location;
} bdk_fs_file_t;

typedef struct bdk_fs_ops_s
{
    int (*stat)(const char *name, struct stat *st);
    int (*unlink)(const char *name);
    void *(*open)(const char *name, int flags);
    int (*close)(bdk_fs_file_t *handle);
    int (*lseek)(bdk_fs_file_t *handle, int64_t offset, int whence);
    int (*read)(bdk_fs_file_t *handle, void *buffer, int length);
    int (*write)(bdk_fs_file_t *handle, const void *buffer, int length);
} bdk_fs_ops_t;

/** @} */

/**
 * @file
 *
 * Infastructure to allow standard C file IO to various file systems.
 *
 * <hr>$Revision: 49448 $<hr>
 */

struct stat;

typedef struct
{
    void *fs_state;
    const struct bdk_fs_ops_s *ops;
    const char *filename;
    uint64_t location;
} __bdk_fs_file_t;

typedef struct bdk_fs_ops_s
{
    int (*stat)(const char *name, struct stat *st);
    int (*unlink)(const char *name);
    void *(*open)(const char *name, int flags);
    int (*close)(__bdk_fs_file_t *handle);
    int (*lseek)(__bdk_fs_file_t *handle, int64_t offset, int whence);
    int (*read)(__bdk_fs_file_t *handle, void *buffer, int length);
    int (*write)(__bdk_fs_file_t *handle, const void *buffer, int length);
} __bdk_fs_ops_t;


/**
 * @file
 *
 * Infastructure to allow standard C file IO to various file systems.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup stdio Standard IO related functions
 * @{
 */

struct stat;

/**
 * This structure represents non-device files which have free form names
 */
typedef struct
{
    void *fs_state;
    const struct __bdk_fs_ops_s *ops;
    const char *filename;
    uint64_t location;
} __bdk_fs_file_t;

/**
 * This structure are the operations that can be performed on non-device files
 */
typedef struct __bdk_fs_ops_s
{
    int (*stat)(const char *name, struct stat *st);
    int (*unlink)(const char *name);
    void *(*open)(const char *name, int flags);
    int (*close)(__bdk_fs_file_t *handle);
    int (*read)(__bdk_fs_file_t *handle, void *buffer, int length);
    int (*write)(__bdk_fs_file_t *handle, const void *buffer, int length);
} __bdk_fs_ops_t;

/**
 * This represents state for device files that represent hardware
 */
typedef struct
{
    const char *filename;
    uint64_t location;
    bdk_node_t dev_node;
    int dev_index;
} __bdk_fs_dev_t;

/**
 * These are the operations that can be performed on device files
 */
typedef struct
{
    int (*open)(__bdk_fs_dev_t *dev, int flags);
    int (*close)(__bdk_fs_dev_t *dev);
    int (*read)(__bdk_fs_dev_t *dev, void *buffer, int length);
    int (*write)(__bdk_fs_dev_t *dev, const void *buffer, int length);
} __bdk_fs_dev_ops_t;

int __bdk_fs_init(void);
int bdk_fs_register(const char *prefix, const __bdk_fs_ops_t *ops);
int bdk_fs_register_dev(const char *dev_base, int dev_index, const __bdk_fs_dev_ops_t *ops);
int bdk_jump_address(uint64_t paddress, uint64_t arg0);
int __bdk_fs_check_break(void);

/** @} */

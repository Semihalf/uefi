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
    int (*read)(__bdk_fs_file_t *handle, void *buffer, int length);
    int (*write)(__bdk_fs_file_t *handle, const void *buffer, int length);
    uint64_t (*mmap)(const char *name, int flags);
} __bdk_fs_ops_t;

int bdk_fs_register(const char *prefix, const __bdk_fs_ops_t *ops);
uint64_t bdk_mmap(const char *name, int flags);
int bdk_jump_address(uint64_t paddress);
int __bdk_fs_check_break(void);
void bdk_fs_set_uart_node(bdk_node_t node);

/** @} */

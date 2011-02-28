#include <bdk.h>

static void *rom_open(const char *name, int flags)
{
    const bdk_fs_rom_t *ptr = bdk_fs_rom_files;

    while (ptr->name && strcmp(name, ptr->name))
        ptr++;

    if (ptr->name)
        return(void*)ptr;
    else
        return NULL;
}

static int rom_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    unsigned int count;
    const bdk_fs_rom_t *ptr = handle->fs_state;
    unsigned int pos = handle->location;

    if (pos > ptr->length)
        return -1;
    else if (pos == ptr->length)
        return 0;

    count = length;
    if (pos + count > ptr->length)
        count = ptr->length - pos;

    memcpy(buffer, ptr->data + pos, count);
    return count;
}

uint64_t rom_mmap(const char *name, int flags)
{
    const bdk_fs_rom_t *ptr = bdk_fs_rom_files;

    while (ptr->name && strcmp(name, ptr->name))
        ptr++;

    if (ptr->name)
        return bdk_ptr_to_phys((void*)ptr->data);
    else
        return -1;
}

const __bdk_fs_ops_t bdk_fs_rom_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = rom_open,
    .close = NULL,
    .lseek = NULL,
    .read = rom_read,
    .write = NULL,
    .mmap = rom_mmap,
};


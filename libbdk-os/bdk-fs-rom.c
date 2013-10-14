#include <bdk.h>

/* ROM files are stored sequencially after the end of the image, starting
    at the _end symbol. Each ROM file starts with six bytes "ROM-FS",
    a two byte filename length, a four byte file length, the bytes for
    the filename, and the file's data. The filename is not \0 terminated */

static void *find_file(const char *name)
{
    extern void _end();
    /* Do a needless address transaltion to force pointer to be a XKPHYS
        address. This is in case the filesystem is larger than my code
        TLB entry */
    const char *ptr = bdk_phys_to_ptr(bdk_ptr_to_phys(&_end));
    int name_length = strlen(name);
    while (memcmp(ptr, "ROM-FS", 6) == 0)
    {
        uint16_t fname_length = *(uint16_t*)(ptr+6);
        uint32_t fdata_length = *(uint32_t*)(ptr+8);
        const char *fname_ptr = ptr+12;
        const char *fdata_ptr = fname_ptr + fname_length;
        if ((name_length == fname_length) &&
            (memcmp(name, fname_ptr, name_length) == 0))
            return (void*)ptr;
        ptr = fdata_ptr + fdata_length;
    }
    return NULL;
}

uint64_t bdk_fs_romfs_get_end(void)
{
    extern void _end();
    /* Do a needless address transaltion to force pointer to be a XKPHYS
        address. This is in case the filesystem is larger than my code
        TLB entry */
    char *ptr = bdk_phys_to_ptr(bdk_ptr_to_phys(&_end));
    while (memcmp(ptr, "ROM-FS", 6) == 0)
    {
        uint16_t fname_length = *(uint16_t*)(ptr+6);
        uint32_t fdata_length = *(uint32_t*)(ptr+8);
        char *fname_ptr = ptr+12;
        char *fdata_ptr = fname_ptr + fname_length;
        ptr = fdata_ptr + fdata_length;
    }
    return bdk_ptr_to_phys(ptr);
}

static void *rom_open(const char *name, int flags)
{
    return find_file(name);
}

static int rom_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    unsigned int pos = handle->location;
    const char *fptr = handle->fs_state;
    uint16_t fname_length = *(uint16_t*)(fptr+6);
    uint32_t fdata_length = *(uint32_t*)(fptr+8);
    const char *fname_ptr = fptr+12;
    const char *fdata_ptr = fname_ptr + fname_length;

    if (pos > fdata_length)
        return -1;
    else if (pos == fdata_length)
        return 0;

    int count = length;
    if (pos + count > fdata_length)
        count = fdata_length - pos;

    memcpy(buffer, fdata_ptr + pos, count);
    return count;
}

uint64_t rom_mmap(const char *name, int flags)
{
    void *fptr = find_file(name);
    if (!fptr)
        return -1;

    uint16_t fname_length = *(uint16_t*)(fptr+6);
    char *fname_ptr = fptr+12;
    char *fdata_ptr = fname_ptr + fname_length;
    return bdk_ptr_to_phys(fdata_ptr);
}

static const __bdk_fs_ops_t bdk_fs_rom_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = rom_open,
    .close = NULL,
    .read = rom_read,
    .write = NULL,
    .mmap = rom_mmap,
};

int bdk_fs_rom_init(void)
{
    return bdk_fs_register("/rom/", &bdk_fs_rom_ops);
}

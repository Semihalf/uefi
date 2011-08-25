#include <bdk.h>

static const char *argv[] = {
    "lua",
    "-i",
    "/rom/init.lua",
    NULL,
};

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    extern int bdk_lua_main(int argc, const char **argv);

    if (BDK_IS_REQUIRED(LWIP) && bdk_netstack_initialize(0))
        bdk_error("bdk_netstack_if_initialize() failed\n");

    extern int bdk_fs_remote_init(void);
    bdk_fs_remote_init();
    extern int bdk_fs_rom_init(void);
    bdk_fs_rom_init();
    extern int bdk_fs_mem_init(void);
    bdk_fs_mem_init();
    extern int bdk_fs_nor_init(void);
    bdk_fs_nor_init();
    if (BDK_IS_REQUIRED(FS_PCIE))
    {
        extern int bdk_fs_pcie_init(void) BDK_WEAK;
        bdk_fs_pcie_init();
    }
    if (BDK_IS_REQUIRED(FS_RAM))
    {
        extern int bdk_fs_ram_init(void) BDK_WEAK;
        bdk_fs_ram_init();
    }
    if (BDK_IS_REQUIRED(FS_TCP))
    {
        extern int bdk_fs_tcp_init(void) BDK_WEAK;
        bdk_fs_tcp_init();
    }
    if (BDK_IS_REQUIRED(FS_XMODEM))
    {
        extern int bdk_fs_xmodem_init(void) BDK_WEAK;
        bdk_fs_xmodem_init();
    }
    if (BDK_IS_REQUIRED(FS_SRIO))
    {
        extern int bdk_fs_srio_init(void) BDK_WEAK;
        bdk_fs_srio_init();
    }

    if (bdk_thread_create(0, (bdk_thread_func_t)bdk_lua_main, 3, argv, 16384))
        bdk_fatal("Create of Lua thread failed\n");
    return 0;
}


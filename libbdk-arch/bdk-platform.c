#include <bdk.h>

bdk_platform_t __bdk_platform;

void __bdk_platform_init()
{
    BDK_CSR_INIT(c, bdk_numa_master(), BDK_OCLAX_CONST(0));
    if (c.u == 0)
    {
        __bdk_platform = BDK_PLATFORM_ASIM;
    }
    else
    {
        int plat2 = bdk_fuse_read(bdk_numa_master(), 197);
        int plat1 = bdk_fuse_read(bdk_numa_master(), 196);
        int plat0 = bdk_fuse_read(bdk_numa_master(), 195);
        __bdk_platform = (plat2 << 2) | (plat1 << 1) | plat0;
    }
}

#ifdef HW_EMULATOR
#error "HW_EMULATOR should not be used. Fuses[197:1195] define the platform"
#endif

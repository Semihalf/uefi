#include <bdk.h>
#include <fcntl.h>
#include <unistd.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(FS_BOOT);

/* "/boot" is a trivial filessytem to pass all operations to the boot
   device. Its purpose is to abstract the name of the boot device from
   the various open calls that want to access it */

static char boot_dev_name[64];

static int boot_stat(const char *name, struct stat *st)
{
    return stat(boot_dev_name, st);
}

static void *boot_open(const char *name, int flags)
{
    int handle = open(boot_dev_name, flags);
    if (handle < 0)
        return NULL;
    else
        return (void*)(long)handle;
}

static int boot_close(__bdk_fs_file_t *handle)
{
    return close((long)handle->fs_state);
}

static int boot_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    lseek((long)handle->fs_state, handle->location, SEEK_SET);
    return read((long)handle->fs_state, buffer, length);
}

static int boot_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    lseek((long)handle->fs_state, handle->location, SEEK_SET);
    return write((long)handle->fs_state, buffer, length);
}

static const __bdk_fs_ops_t bdk_fs_boot_ops =
{
    .stat = boot_stat,
    .open = boot_open,
    .close = boot_close,
    .read = boot_read,
    .write = boot_write,
};

int __bdk_fs_boot_init(void)
{
    bdk_node_t node = bdk_numa_master();

    /* Determine how we booted */
    int boot_method;
    BDK_CSR_INIT(gpio_strap, node, BDK_GPIO_STRAP);
    BDK_EXTRACT(boot_method, gpio_strap.u, 0, 4);

    switch (boot_method)
    {
        case BDK_RST_BOOT_METHOD_E_EMMC_LS:
        case BDK_RST_BOOT_METHOD_E_EMMC_SS:
            snprintf(boot_dev_name, sizeof(boot_dev_name), "/dev/n%d.mmc0", node);
            break;

        case BDK_RST_BOOT_METHOD_E_SPI24:
        case BDK_RST_BOOT_METHOD_E_SPI32:
        {
            BDK_CSR_INIT(mpi_cfg, bdk_numa_master(), BDK_MPI_CFG);
            int chip_select = 0;
            int address_width;
            int active_high = mpi_cfg.s.cshi;
            int idle_mode = (mpi_cfg.s.idleclks) ? 'r' : (mpi_cfg.s.idlelo) ? 'l' : 'h';
            int is_msb = !mpi_cfg.s.lsbfirst;
            int freq_mhz = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / (2 * mpi_cfg.s.clkdiv) / 1000000;

            if (boot_method == BDK_RST_BOOT_METHOD_E_SPI24)
		address_width = 24;
            else
		address_width = 32;

            snprintf(boot_dev_name, sizeof(boot_dev_name),
                "/dev/n%d.mpi%d/cs-%c,2wire,idle-%c,%csb,%dbit,%d",
                node, chip_select, (active_high) ? 'h' : 'l', idle_mode,
                (is_msb) ? 'm' : 'l', address_width, freq_mhz);
            break;
        }

        default:
            snprintf(boot_dev_name, sizeof(boot_dev_name), "/dev/n%d.mem0", node);
            break;
    }
    return bdk_fs_register("/boot", &bdk_fs_boot_ops);
}

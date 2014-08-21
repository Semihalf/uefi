#include <bdk.h>

/* MPI/SPI filenames are of the format:
   /dev/mpi/cs0-[hl],[12]wire,idle-[rhl],[ml]sb,##bit,<freq>
    - cs0 = Chip select to use [0-3]
    - [hl] = Chip select is active High or Low
    - [12] = Use 1 wire half duplex or 2 wire full duplex
    - [rhl] = Should the clock continue to Run when idle, go High, or go Low
    - [ml] = MSB or LSB first
    - ## = Address width (16, 24, or 32)
    - <freq> = Clock frequency in Mhz
   */

static void *mpi_open(const char *name, int flags)
{
    const int CMD_WRITE_STATUS = 0x01;
    const bdk_node_t node = bdk_numa_local();
    int chip_sel;
    char chip_hl;
    char wire;
    char idle;
    char endian;
    int address_width;
    int freq;
    int count = sscanf(name, "cs%d-%c,%cwire,idle-%c,%csb,%dbit,%d",
        &chip_sel, &chip_hl, &wire, &idle, &endian, &address_width, &freq);
    if (count != 7)
        goto bad;
    if ((chip_sel < 0) || (chip_sel > 3))
        goto bad;
    if ((chip_hl != 'h') && (chip_hl != 'l'))
        goto bad;
    if ((wire != '1') && (wire != '2'))
        goto bad;
    if ((idle != 'r') && (idle != 'h') && (idle != 'l'))
        goto bad;
    if ((endian != 'm') && (endian != 'l'))
        goto bad;
    if ((address_width < 8) || (address_width > 32))
        goto bad;
    if ((freq < 1) || (freq > 50))
        goto bad;

    bdk_mpi_flags_t mpi_flags = 1 << chip_sel;
    if (chip_hl == 'h')
        mpi_flags |= BDK_MPI_FLAGS_CS_ACTIVE_HI;
    if (wire == '1')
        mpi_flags |= BDK_MPI_FLAGS_ONE_WIRE;
    if (idle == 'r')
        mpi_flags |= BDK_MPI_FLAGS_IDLE_CLOCKS;
    else if (idle == 'l')
        mpi_flags |= BDK_MPI_FLAGS_IDLE_LOW;
    if (endian == 'l')
        mpi_flags |= BDK_MPI_FLAGS_LSB_FIRST;

    if (bdk_mpi_initialize(bdk_numa_local(), freq * 1000000, mpi_flags))
        return NULL;

    /* Write zero to status register to disable write protection */
    bdk_mpi_transfer(node, chip_sel, 0, 2, CMD_WRITE_STATUS, 0);

    return (void*)((long)chip_sel | (address_width << 8));

bad:
    bdk_error("Illegal filename: %s\n", name);
    return NULL;
}

static int mpi_read(__bdk_fs_file_t *handle, void *buffer, int length)
{
    const int CMD_READ = 0x03;
    const bdk_node_t node = bdk_numa_local();
    const int chip_sel = (long)handle->fs_state & 0xff;
    const int address_width = (long)handle->fs_state >> 8;

    uint64_t tx_data;

    BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
    if (mpi_cfg.s.lsbfirst)
    {
        tx_data = handle->location << 8;
        tx_data |= CMD_READ;
    }
    else
    {
        tx_data = handle->location & bdk_build_mask(address_width);
        tx_data |= CMD_READ << address_width;
    }

    bdk_mpi_transfer(node, chip_sel, 1, 1 + address_width/8, tx_data, 0);
    int data_left = length;
    while (data_left)
    {
        *(uint8_t*)buffer = bdk_mpi_transfer(node, chip_sel, data_left>1, 0, 0, 1);
        buffer++;
        data_left--;
    }
    return length;
}

static int wait_for_write_complete(bdk_node_t node, int chip_sel)
{
    const int CMD_READ_STATUS = 0x05;
    uint8_t status;
    uint64_t timeout = bdk_clock_get_count(BDK_CLOCK_CORE) + bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE);
    do
    {
        status = bdk_mpi_transfer(node, chip_sel, 0, 1, CMD_READ_STATUS, 1);
        if (status & 1)
        {
            if (bdk_clock_get_count(BDK_CLOCK_CORE) > timeout)
            {
                bdk_error("MPI-fs timeout waiting for WIP to clear (0x%02x)\n", status);
                return -1;
            }
            bdk_thread_yield();
        }
    } while (status & 1);
    return 0;
}

static int mpi_write(__bdk_fs_file_t *handle, const void *buffer, int length)
{
    const int CMD_WRITE = 0x02;
    const int CMD_WRITE_EN = 0x06;
    const bdk_node_t node = bdk_numa_local();
    const int chip_sel = (long)handle->fs_state & 0xff;
    const int address_width = (long)handle->fs_state >> 8;

    uint64_t loc = handle->location;
    int need_new_write = 1;
    int data_left = length;
    while (data_left)
    {
        if (need_new_write)
        {
            if (wait_for_write_complete(node, chip_sel))
                return -1;
            /* Write enable */
            bdk_mpi_transfer(node, chip_sel, 0, 1, CMD_WRITE_EN, 0);
            /* Begin write */
            bdk_mpi_transfer(node, chip_sel, 1, 1, CMD_WRITE, 0);
            bdk_mpi_transfer(node, chip_sel, 1, address_width/8, loc, 0);
        }
        need_new_write = ((loc & 63) == 63) || (data_left == 1);
        bdk_mpi_transfer(node, chip_sel, !need_new_write, 1, *(uint8_t*)buffer, 0);
        buffer++;
        loc++;
        data_left--;
    }

    if (wait_for_write_complete(node, chip_sel))
        return -1;

    return length;
}

static const __bdk_fs_ops_t bdk_fs_mpi_ops =
{
    .stat = NULL,
    .unlink = NULL,
    .open = mpi_open,
    .close = NULL,
    .read = mpi_read,
    .write = mpi_write,
    .mmap = NULL,
};

int bdk_fs_mpi_init(void)
{
    return bdk_fs_register("/dev/mpi/", &bdk_fs_mpi_ops);
}

#include <bdk.h>
#include <fcntl.h>

/* MPI/SPI filenames are of the format:
   n0.mpi0/cs-[hl],[12]wire,idle-[rhl],[ml]sb,##bit,<freq>
    - mpi0 = Chip select to use [0-3]
    - [hl] = Chip select is active High or Low
    - [12] = Use 1 wire half duplex or 2 wire full duplex
    - [rhl] = Should the clock continue to Run when idle, go High, or go Low
    - [ml] = MSB or LSB first
    - ## = Address width (16, 24, or 32)
    - <freq> = Clock frequency in Mhz
   */

static int mpi_open(__bdk_fs_dev_t *handle, int flags)
{
    const int CMD_WRITE_STATUS = 0x01;
    int node;
    int chip_sel;
    char chip_hl;
    char wire;
    char idle;
    char endian;
    int address_width;
    int freq;
    int count = sscanf(handle->filename, "n%d.mpi%d/cs-%c,%cwire,idle-%c,%csb,%dbit,%d",
        &node, &chip_sel, &chip_hl, &wire, &idle, &endian, &address_width, &freq);
    if (count != 8)
        goto bad;
    if (node != (int)handle->dev_node)
        goto bad;
    if (chip_sel != handle->dev_index)
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

    if (bdk_mpi_initialize(node, freq * 1000000, mpi_flags))
        return -1;

    /* Write zero to status register to disable write protection */
    if ((flags&3) != O_RDONLY)
        bdk_mpi_transfer(node, chip_sel, 0, 2, CMD_WRITE_STATUS, 0);

    return 0;

bad:
    bdk_error("Illegal filename: %s\n", handle->filename);
    return -1;
}

static int get_address_width(const char *name)
{
    if (strstr(name, ",24bit,"))
        return 24;
    else if (strstr(name, ",32bit,"))
        return 32;
    else
        return 16;
}

/**
 * Read bytes from a MPI/SPI device. This function supports reading from a
 * SPI EEPROM, a SPI NOR, or a SPI NAND. All three use a common read comamnd
 * and format.
 *
 * @param handle Handle to file state
 * @param buffer Buffer to fill
 * @param length Number of bytes to read
 *
 * @return Number of bytes read, negative on failure
 */
static int mpi_read(__bdk_fs_dev_t *handle, void *buffer, int length)
{
    const int CMD_READ = 0x03;
    const bdk_node_t node = handle->dev_node;
    const int chip_sel = handle->dev_index;
    const int address_width = get_address_width(handle->filename);

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
    while (data_left > 0)
    {
        *(uint64_t*)buffer = bdk_be64_to_cpu(bdk_mpi_transfer(node, chip_sel, data_left>8, 0, 0, 8));
        buffer+=8;
        data_left-=8;
    }
    return length;
}

/**
 * Wait for the previous MPI/SPI command to complete
 *
 * @param node     Note the MPI/SPI bus is on
 * @param chip_sel Chip select the device is on
 *
 * @return Zero on success, negative on timeout
 */
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

/**
 * Write to a SPI EEPROM. This code assumes the device can only
 * be written 64 bytes at a time.
 *
 * @param handle Handle to file state
 * @param buffer Buffer to write to the device
 * @param length Length of the write in bytes
 *
 * @return Number of bytes written, negative on failure
 */
static int eeprom_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    const int CMD_WRITE = 0x02;
    const int CMD_WRITE_EN = 0x06;
    const bdk_node_t node = handle->dev_node;
    const int chip_sel = handle->dev_index;
    const int address_width = get_address_width(handle->filename);

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

/**
 * Write to a SPI NOR.
 *
 * @param handle Handle to file state
 * @param buffer Buffer to write to the device
 * @param length Length of the write in bytes
 *
 * @return Number of bytes written, negative on failure
 */
static int nor_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    /* From datasheet for N25Q128A13ESE40. It is a 16MB NOR flash with
       256 sectors (64KB each), each sector divided into 4KB subsectors, each
       divided into 256 byte pages. Smallest erase size is a subsector (4KB).
       Once erase, a page (256 bytes) must be programemd at a time */
    const int SECTOR_SIZE = 65536;
    const int SUBSECTOR_SIZE = 4096;
    const int PAGE_SIZE = 256;
    /* We only use a small subset of the comamnds support by the NOR */
    const int CMD_WREN  = 0x06; /* Write enable */
    const int CMD_PP    = 0x02; /* Page program */
    const int CMD_SSE   = 0x20; /* Subsector erase */
    const int CMD_SE    = 0xd8; /* Sector erase */
    const int USE_SECTOR_ERASE = 1;
    const int ERASE_CMD = (USE_SECTOR_ERASE) ? CMD_SE : CMD_SSE;
    const int ERASE_SIZE = (USE_SECTOR_ERASE) ? SECTOR_SIZE : SUBSECTOR_SIZE;

    const bdk_node_t node = handle->dev_node;
    const int chip_sel = handle->dev_index;
    const int address_width = get_address_width(handle->filename);

    if (handle->location & (PAGE_SIZE-1))
    {
        bdk_error("SPI-NOR: Write location must be on a page boundary\n");
        return -1;
    }

    if (wait_for_write_complete(node, chip_sel))
        return -1;

    uint64_t loc = handle->location;
    int data_left = length;
    while (data_left)
    {
        /* See if we're at the start of an erase block */
        if ((loc & (ERASE_SIZE-1)) == 0)
        {
            bdk_mpi_transfer(node, chip_sel, 0, 1, CMD_WREN, 0);
            /* We need to erase the next block */
            bdk_mpi_transfer(node, chip_sel, 0, /* Disable chip select */
                1 + address_width/8, /* One command byte plus address */
                (ERASE_CMD << address_width) | loc, /* Command and address */
                0); /* No receive data */
            if (wait_for_write_complete(node, chip_sel))
                return -1;
        }

        bdk_mpi_transfer(node, chip_sel, 0, 1, CMD_WREN, 0);
        /* Begin page program */
        bdk_mpi_transfer(node, chip_sel, 1, /* Keep chip select active */
            1 + address_width/8, /* One command byte plus address */
            (CMD_PP << address_width) | loc, /* Command and address */
            0); /* No receive data */

        /* Write a page at a time */
        int len = PAGE_SIZE;
        if (len > data_left)
            len = data_left;
        while (len--)
        {
            /* The last byte written deassert the chip select */
            bdk_mpi_transfer(node, chip_sel, (len != 0),
                1, /* One data byte */
                *(uint8_t*)buffer, /* Data to write */
                0); /* No receive data */
            buffer++;
            loc++;
            data_left--;
        }

        if (wait_for_write_complete(node, chip_sel))
            return -1;
    }

    return length;
}

/**
 * Write to a MPI/SPI device. This currently only support SPI EEPROM and SPI NOR
 * flash.
 *
 * @param handle Handle to file state
 * @param buffer Data to write
 * @param length Length of the data in bytes
 *
 * @return Number of bytes written, negative on failure
 */
static int mpi_write(__bdk_fs_dev_t *handle, const void *buffer, int length)
{
    /* This code is very simple and assumes devices using 16 bit addresses
       are EEPROMs and anything else is NOR */
    const int address_width = get_address_width(handle->filename);
    if (address_width == 16)
        return eeprom_write(handle, buffer, length);
    else
        return nor_write(handle, buffer, length);
}

static const __bdk_fs_dev_ops_t bdk_fs_mpi_ops =
{
    .open = mpi_open,
    .close = NULL,
    .read = mpi_read,
    .write = mpi_write,
};

int bdk_fs_mpi_init(void)
{
    for (int cs = 0; cs < 4; cs++)
    {
        if (bdk_fs_register_dev("mpi", cs, &bdk_fs_mpi_ops))
            return -1;
    }
    return 0;
}

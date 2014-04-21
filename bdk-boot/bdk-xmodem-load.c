#include <bdk.h>

/**
 * This function is not defined by the BDK libraries. It must be
 * defined by all BDK applications. It should be empty except for
 * containing BDK_REQUIRE() lines. The bdk-init code has a strong
 * reference to bdk_requires_depends() which then contains strong
 * references to all needed components.
 */
void __bdk_require_depends(void)
{
    BDK_REQUIRE(FS_XMODEM);
}

static int volatile write_needed = 0;
static char write_buffer[1024];
static int volatile write_count = 0;
static bdk_spinlock_t write_lock;

/**
 * The actual writing to flash is done in a separate thread so Xmodem doesn't
 * stall during slow erase cycles.
 *
 * @author creese (10/10/2013)
 * @param unused Unused param
 * @param handle File handle for writing
 */
static void write_thread(int unused, void *handle)
{
    FILE *outf = (FILE*)handle;
    while (write_needed)
    {
        /* Wait for data */
        if (!write_count)
        {
            bdk_thread_yield();
            continue;
        }
        bdk_spinlock_lock(&write_lock);
        /* Write the data */
        int w_count = fwrite(write_buffer, 1, write_count, outf);
        fflush(outf);
        if (w_count != write_count)
        {
            bdk_error("Write error\n");
            bdk_spinlock_unlock(&write_lock);
            break;
        }
        /* Tell the reader the buffer is empty */
        write_count = 0;
        bdk_spinlock_unlock(&write_lock);
    }
    fclose(outf);
}

/**
 * Receive a file through Xmodem and write it to an internal file representing
 * a flash device.
 *
 * @author creese (10/10/2013)
 * @param dest_file File to write to
 * @param offset    Offset into the file to start at
 */
static void do_upload(const char *dest_file, int offset)
{
    /* Open the output file */
    FILE *outf = fopen(dest_file, "w");
    if (!outf)
    {
        bdk_error("Failed to open %s\n", dest_file);
        return;
    }
    fseek(outf, offset, SEEK_SET);

    /* Create a thread that does the write so Xmodem doesn't stall
       during slow flash accesses */
    write_count = 0;
    write_needed = 1;
    BDK_SYNCW;
    bdk_thread_create(bdk_numa_local(), 0, write_thread, 0, (void*)outf, 0);
    /* Let the thread start */
    bdk_thread_yield();

    /* Open xmodem for reading the file */
    FILE *inf = fopen("/xmodem", "r");
    if (!inf)
    {
        bdk_error("Failed to open /xmodem\n");
        BDK_SYNCW;
        write_needed = 0;
        BDK_SYNCW;
        return;
    }

    /* Loop until the file is done */
    while (!feof(inf))
    {
        char buffer[sizeof(write_buffer)];
        /* Read a block */
        int count = fread(buffer, 1, sizeof(buffer), inf);
        if (count > 0)
        {
            /* Wait for the write buffer to be empty */
            while (write_count)
                bdk_thread_yield();
            /* Put the data in the write buffer */
            bdk_spinlock_lock(&write_lock);
            memcpy(write_buffer, buffer, count);
            BDK_SYNCW;
            write_count = count;
            bdk_spinlock_unlock(&write_lock);
        }
    }
    fclose(inf);
    printf("\nXmodem complete\n");
    /* Wait for the write thread to finish */
    BDK_SYNCW;
    write_needed = 0;
    BDK_SYNCW;
    while (write_count)
        bdk_thread_yield();
}

/**
 * Main entry point
 *
 * @return exit code
 */
int main(void)
{
    printf(
        "BDK version: %s\n"
        "\n"
        "BDK Xmodem file load utility\n"
        "\n"
        "This utility can load files through Xmodem into:\n"
        "\tParallel NOR\n"
        "\tMMC, eMMC, or SD\n"
        "\tSPI EEPROM or NOR\n"
        "\n", bdk_version_string());

    extern int bdk_fs_xmodem_init(void);
    extern int bdk_fs_nor_init(void);
    extern int bdk_fs_mmc_init(void);
    extern int bdk_fs_mpi_init(void);
    bdk_fs_xmodem_init();
    bdk_fs_nor_init();
    bdk_fs_mmc_init();
    bdk_fs_mpi_init();

    while (1)
    {
        printf(
            "\n"
            "=================================\n"
            "Main Menu\n"
            "=================================\n"
            " 1) Change baud rate and flow control\n"
            " 2) Load file into parallel NOR\n"
            " 3) Load file into MMC, eMMC, or SD\n"
            " 4) Load file into SPI EEPROM or NOR\n"
            " 5) Soft reset Octeon\n");
        const char *input = bdk_readline("Menu choice: ", NULL, 0);
        switch (atoi(input))
        {
            case 1: /* Change baud rate */
            {
                const char *baud = bdk_readline("Baudrate: ", NULL, 0);
                const char *flow = bdk_readline("Use hardware flow control [y/n]: ", NULL, 0);
                int baudrate = atoi(baud);
                if ((baudrate < 9600) || (baudrate > 4000000))
                {
                    bdk_error("Illegal baudrate\n");
                    break;
                }
                int use_flow = !(*flow == 'n');
                printf("Changing baudrate to %d\n", baudrate);
                fflush(NULL);
                bdk_wait_usec(500000);
                bdk_set_baudrate(bdk_numa_local(), 0, baudrate, use_flow);
                printf("Baudrate is now %d\n", baudrate);
                break;
            }
            case 2: /* pNOR */
            {
                const char *offset_str = bdk_readline("Offset into flash [0]: ", NULL, 0);
                int offset = atoi(offset_str);
                if ((offset < 0) || (offset > (1 << 30)))
                    bdk_error("Illegal offset\n");
                else
                {
                    printf("\n");
                    bdk_flash_initialize(bdk_numa_local());
                    printf("\n");
                    do_upload("/dev/nor/0", offset);
                }
                break;
            }
            case 3: /* eMMC / SD */
            {
                const char *chip_str = bdk_readline("Chip select [0]: ", NULL, 0);
                int chip_sel = atoi(chip_str);
                if ((chip_sel < 0) || (chip_sel >= 4))
                {
                    bdk_error("Illegal chip select\n");
                    break;
                }

                const char *offset_str = bdk_readline("Offset into flash [0]: ", NULL, 0);
                int offset = atoi(offset_str);
                if ((offset < 0) || (offset > (1 << 30)))
                {
                    bdk_error("Illegal offset\n");
                    break;
                }
                printf("\n");
                char filename[32];
                sprintf(filename, "/dev/mmc/%d", chip_sel);
                do_upload(filename, offset);
                break;
            }
            case 4: /* SPI NOR */
            {
                const char *chip_str = bdk_readline("Chip select [0]: ", NULL, 0);
                int chip_sel = atoi(chip_str);
                if ((chip_sel < 0) || (chip_sel >= 4))
                {
                    bdk_error("Illegal chip select\n");
                    break;
                }

                const char *offset_str = bdk_readline("Offset into flash [0]: ", NULL, 0);
                int offset = atoi(offset_str);
                if ((offset < 0) || (offset > (1 << 30)))
                {
                    bdk_error("Illegal offset\n");
                    break;
                }

                const char *width_str = bdk_readline("Address width in bits [16]: ", NULL, 0);
                int width = atoi(width_str);
                if (*width_str == 0)
                    width = 16;
                if ((width < 8) || (width > 32))
                {
                    bdk_error("Illegal address width\n");
                    break;
                }
                printf("\n");
                char filename[64];
                sprintf(filename, "/dev/mpi/cs%d-l,2wire,idle-h,msb,%dbit,10", chip_sel, width);
                do_upload(filename, offset);
                break;
            }
            case 5: /* Soft reset */
                printf("Performing a soft reset\n");
                bdk_reset_octeon(bdk_numa_local());
                break;
            default:
                bdk_error("Illegal input\n");
                break;
        }
    }
}

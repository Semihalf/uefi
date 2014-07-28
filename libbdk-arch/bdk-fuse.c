#include <bdk.h>

/**
 * Read a byte of fuse data
 * @param byte_addr   address to read
 *
 * @return fuse value: 0 or 1
 */
static uint8_t bdk_fuse_read_byte(bdk_node_t node, int byte_addr)
{
    bdk_mio_fus_rcmd_t read_cmd;

    read_cmd.u = 0;
    read_cmd.s.addr = byte_addr;
    read_cmd.s.pend = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_RCMD, read_cmd.u);
    do
    {
        read_cmd.u = BDK_CSR_READ(node, BDK_MIO_FUS_RCMD);
    } while (read_cmd.s.pend);
    return read_cmd.s.dat;
}


/**
 * Read a single fuse bit
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
int bdk_fuse_read(bdk_node_t node, int fuse)
{
    return((bdk_fuse_read_byte(node, fuse >> 3) >> (fuse & 0x7)) & 1);
}


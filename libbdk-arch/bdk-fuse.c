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
    read_cmd.s.addr_hi = byte_addr >> 8;
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

/**
 * Soft blow a fuse. Soft blown fuses keep there new value over soft resets, but
 * not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
int bdk_fuse_soft_blow(bdk_node_t node, int fuse)
{
    /* Select the fuse bank. there are 128 fuses per bank */
    BDK_CSR_WRITE(node, BDK_MIO_FUS_WADR, fuse / 128);

    /* Select the fuse to program in the bank */
    int index = fuse & 127;
    if (index < 64)
    {
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(0), 1ull << index);
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(1), 0);
    }
    else
    {
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(0), 0);
        BDK_CSR_WRITE(node, BDK_MIO_FUS_BNK_DATX(1), 1ull << (index - 64));
    }

    /* Set to do a soft blow */
    BDK_CSR_DEFINE(fus_prog, BDK_MIO_FUS_PROG);
    fus_prog.u = 0;
    fus_prog.s.sft = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_PROG, fus_prog.u);

    /* Do the actual program */
    fus_prog.s.prog = 1;
    BDK_CSR_WRITE(node, BDK_MIO_FUS_PROG, fus_prog.u);

    /* Wait for the program to complete */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_MIO_FUS_PROG, prog, ==, 0, 100000))
    {
        bdk_error("Timeout soft blowing fuse\n");
        return -1;
    }

    /* Read the fuse to make sure it was really soft blown */
    if (bdk_fuse_read(node, fuse) == 0)
    {
        bdk_error("Soft blowing fuse failed\n");
        return -1;
    }
    return 0;
}

/**
 * Read a single fuse bit from the field set (FUSF)
 *
 * @param fuse   Fuse number (0-1024)
 *
 * @return fuse value: 0 or 1
 */
int bdk_fuse_field_read(bdk_node_t node, int fuse)
{
    bdk_fusf_rcmd_t read_cmd;

    read_cmd.u = 0;
    read_cmd.s.addr = fuse >> 8;
    read_cmd.s.addr_hi = fuse >> 16;
    read_cmd.s.pend = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_RCMD, read_cmd.u);
    do
    {
        read_cmd.u = BDK_CSR_READ(node, BDK_FUSF_RCMD);
    } while (read_cmd.s.pend);

    int index = fuse & 0x7f;
    uint64_t dat = BDK_CSR_READ(node, BDK_FUSF_BNK_DATX(index >> 6));
    return (dat >> (index & 0x3f)) & 1;
}

/**
 * Soft blow a fuse in the field set (FUSF). Soft blown fuses
 * keep there new value over soft resets, but not pwoer cycles.
 *
 * @param node   Node to blow
 * @param fuse   Fuse to blow
 *
 * @return Zero on success, negative on failure
 */
int bdk_fuse_field_soft_blow(bdk_node_t node, int fuse)
{
    /* Select the fuse bank. there are 128 fuses per bank */
    BDK_CSR_WRITE(node, BDK_FUSF_WADR, fuse / 128);

    /* Select the fuse to program in the bank */
    int index = fuse & 127;
    if (index < 64)
    {
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(0), 1ull << index);
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(1), 0);
    }
    else
    {
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(0), 0);
        BDK_CSR_WRITE(node, BDK_FUSF_BNK_DATX(1), 1ull << (index - 64));
    }

    /* Set to do a soft blow */
    BDK_CSR_DEFINE(fus_prog, BDK_FUSF_PROG);
    fus_prog.u = 0;
    fus_prog.s.sft = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_PROG, fus_prog.u);

    /* Do the actual program */
    fus_prog.s.prog = 1;
    BDK_CSR_WRITE(node, BDK_FUSF_PROG, fus_prog.u);

    /* Wait for the program to complete */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_FUSF_PROG, prog, ==, 0, 100000))
    {
        bdk_error("Timeout soft blowing field fuse\n");
        return -1;
    }

    /* Read the fuse to make sure it was really soft blown */
    if (bdk_fuse_field_read(node, fuse) == 0)
    {
        bdk_error("Soft blowing field fuse failed\n");
        return -1;
    }
    return 0;
}

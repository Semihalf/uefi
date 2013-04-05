#include <bdk.h>

/**
 * Initialize MPI/SPI for use. The different configuration
 * options are encoded as bitmask inside the flags parameter.
 *
 * @param node   Numa node to use
 * @param clock_rate_hz
 *               Clock rate in Hz (1-16M)
 * @param flags  Setup flags ORed together
 *
 * @return Zero on success, negative on failure
 */
int bdk_mpi_initialize(bdk_node_t node, int clock_rate_hz, bdk_mpi_flags_t flags)
{
    if (clock_rate_hz < 1)
        return -1;

    uint64_t divider = bdk_clock_get_rate(node, BDK_CLOCK_SCLK) / 2 / clock_rate_hz;

    BDK_CSR_INIT(mpi_cfg, node, BDK_MPI_CFG);
    mpi_cfg.s.clkdiv = divider;
    mpi_cfg.s.csena3 = (flags & BDK_MPI_FLAGS_ENABLE_CS3) != 0;
    mpi_cfg.s.csena2 = (flags & BDK_MPI_FLAGS_ENABLE_CS2) != 0;
    mpi_cfg.s.csena1 = (flags & BDK_MPI_FLAGS_ENABLE_CS1) != 0;
    mpi_cfg.s.csena0 = (flags & BDK_MPI_FLAGS_ENABLE_CS0) != 0;
    /* mpi_cfg.s.cslate is unchanged */
    /* mpi_cfg.s.tritx is programed during transmit */
    mpi_cfg.s.idleclks = (flags & BDK_MPI_FLAGS_IDLE_CLOCKS) != 0;
    mpi_cfg.s.cshi = (flags & BDK_MPI_FLAGS_CS_ACTIVE_HI) != 0;
    mpi_cfg.s.lsbfirst = (flags & BDK_MPI_FLAGS_LSB_FIRST) != 0;
    mpi_cfg.s.wireor = (flags & BDK_MPI_FLAGS_ONE_WIRE) != 0;
    mpi_cfg.s.clk_cont = mpi_cfg.s.idleclks;
    mpi_cfg.s.idlelo = (flags & BDK_MPI_FLAGS_IDLE_LOW) != 0;
    mpi_cfg.s.enable = 1;
    BDK_CSR_WRITE(node, BDK_MPI_CFG, mpi_cfg.u64);
    return 0;
}

/**
 * Perform a SPI/MPI transfer
 *
 * @param node     Numa node to use
 * @param chip_select
 *                 Which chip select to enable during the transfer
 * @param tri_state_shift
 *                 Non zero if SPI_DO should be tristated during the shift stage of
 *                 the transfer. This will only be needed in one wire more for reads.
 * @param leave_cs_enabled
 *                 Leave the chip select assert after the transaction. Normally can
 *                 be zero. Set to non zero if you want to perform repeated poll
 *                 reads.
 * @param tx_count Number of bytes to transfer before startng the shift data. Can
 *                 be zero.
 * @param tx_bytes Bytes to transmit
 * @param shift_count
 *                 Number of byte shift in/out after the transmit phase. May be
 *                 zero.
 * @param shift_bytes
 *                 Data being shifted out and where data shifted in gets written
 *
 * @return Zero on success, negative on failure
 */
int bdk_mpi_transfer(bdk_node_t node, int chip_select,
    int tri_state_shift, int leave_cs_enabled,
    int tx_count, const uint8_t tx_bytes[],
    int shift_count, uint8_t shift_bytes[])
{
    const int TIMEOUT = 1000000; /* 1sec */
    const int MAX_PER_TRANSER = 9; /* There are 9 MPI_DAT regsiters */

    /* Program the tri state option */
    BDK_CSR_MODIFY(c, node, BDK_MPI_CFG,
        c.s.tritx = (tri_state_shift!=0));

    int tx_loc = 0;
    int shift_loc = 0;
    /* Loop until we've finished data */
    while ((tx_loc < tx_count) || (shift_loc < shift_count))
    {
        /* Fill in the TX data first */
        int tx = tx_count - tx_loc;
        if (tx > MAX_PER_TRANSER)
            tx = MAX_PER_TRANSER;
        for (int i=0; i<tx; i++)
            BDK_CSR_WRITE(node, BDK_MPI_DATX(i), tx_bytes[tx_loc++]);

        /* Add shift data if there is room */
        int shift = MAX_PER_TRANSER - tx;
        if (shift > shift_count - shift_loc)
            shift = shift_count - shift_loc;
        for (int i=0; i<shift; i++)
            BDK_CSR_WRITE(node, BDK_MPI_DATX(tx + i), shift_bytes[shift_loc + i]);

        /* Leave the chip select enabled if we will have more tx data, more
            shift data, or the caller requested it */
        int leave_cs = ((tx_loc < tx_count) ||
                        (shift_loc + shift < shift_count) ||
                        leave_cs_enabled);

        /* Do the operation */
        BDK_CSR_DEFINE(mpi_tx, BDK_MPI_TX);
        mpi_tx.u64 = 0;
        mpi_tx.s.csid = chip_select;
        mpi_tx.s.leavecs = leave_cs;
        mpi_tx.s.txnum = tx;
        mpi_tx.s.totnum = tx + shift;
        BDK_CSR_WRITE(node, BDK_MPI_TX, mpi_tx.u64);

        /* Wait for completion */
        if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_MPI_STS, busy, ==, 0, TIMEOUT))
        {
            bdk_error("MPI/SPI: Timeout waiting for transaction to complete\n");
            return -1;
        }

        /* Read out the shift data */
        for (int i=0; i<shift; i++)
            shift_bytes[shift_loc++] = BDK_CSR_READ(node, BDK_MPI_DATX(i));
    }
    return 0;
}


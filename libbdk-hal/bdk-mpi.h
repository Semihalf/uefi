/**
 * @file
 *
 * Interface to the SPI / MPI bus
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

typedef enum
{
    BDK_MPI_FLAGS_ENABLE_CS0    = 1<<0, /**< Chip select 0 will be needed */
    BDK_MPI_FLAGS_ENABLE_CS1    = 1<<1, /**< Chip select 1 will be needed */
    BDK_MPI_FLAGS_ENABLE_CS2    = 1<<2, /**< Chip select 2 will be needed */
    BDK_MPI_FLAGS_ENABLE_CS3    = 1<<3, /**< Chip select 3 will be needed */
    BDK_MPI_FLAGS_CS_ACTIVE_HI  = 1<<4, /**< Chip select is active high, else active low */
    BDK_MPI_FLAGS_ONE_WIRE      = 1<<5, /**< Input and output are multiplexed over SPI_DO */
    BDK_MPI_FLAGS_IDLE_CLOCKS   = 1<<7, /**< Continue to clock between commands */
    BDK_MPI_FLAGS_IDLE_LOW      = 1<<8, /**< Clear the clock is idle high, Set the clock is idle low */
    BDK_MPI_FLAGS_LSB_FIRST     = 1<<9, /**< Set to shift the LSB first, otherwise MSB will shift first */
} bdk_mpi_flags_t;

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
extern int bdk_mpi_initialize(bdk_node_t node, int clock_rate_hz, bdk_mpi_flags_t flags);

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
extern int bdk_mpi_transfer(bdk_node_t node, int chip_select,
    int tri_state_shift, int leave_cs_enabled,
    int tx_count, const uint8_t tx_bytes[],
    int shift_count, uint8_t shift_bytes[]);

/** @} */

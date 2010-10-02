/**
 * @file
 *
 * This file contains defines for the SPI interface

 * <hr>$Revision: 49448 $<hr>
 *
 *
 */

typedef enum
{
    BDK_SPI_MODE_UNKNOWN = 0,
    BDK_SPI_MODE_TX_HALFPLEX = 1,
    BDK_SPI_MODE_RX_HALFPLEX = 2,
    BDK_SPI_MODE_DUPLEX = 3
} bdk_spi_mode_t;

/** Callbacks structure to customize SPI4 initialization sequence */
typedef struct
{
    /** Called to reset SPI4 DLL */
    int (*reset_cb)(int interface, bdk_spi_mode_t mode);

    /** Called to setup calendar */
    int (*calendar_setup_cb)(int interface, bdk_spi_mode_t mode, int num_ports);

    /** Called for Tx and Rx clock detection */
    int (*clock_detect_cb)(int interface, bdk_spi_mode_t mode, int timeout);

    /** Called to perform link training */
    int (*training_cb)(int interface, bdk_spi_mode_t mode, int timeout);

    /** Called for calendar data synchronization */
    int (*calendar_sync_cb)(int interface, bdk_spi_mode_t mode, int timeout);

    /** Called when interface is up */
    int (*interface_up_cb)(int interface, bdk_spi_mode_t mode);

} bdk_spi_callbacks_t;


/**
 * Return true if the supplied interface is configured for SPI
 *
 * @param interface Interface to check
 * @return True if interface is SPI
 */
static inline int bdk_spi_is_spi_interface(int interface)
{
    uint64_t gmxState = BDK_CSR_READ(BDK_GMXX_INF_MODE(interface));
    return ((gmxState & 0x2) && (gmxState & 0x1));
}

/**
 * Initialize and start the SPI interface.
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param timeout   Timeout to wait for clock synchronization in seconds
 * @param num_ports Number of SPI ports to configure
 *
 * @return Zero on success, negative of failure.
 */
extern int bdk_spi_start_interface(int interface, bdk_spi_mode_t mode, int timeout, int num_ports);

/**
 * This routine restarts the SPI interface after it has lost synchronization
 * with its corespondant system.
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param timeout   Timeout to wait for clock synchronization in seconds
 * @return Zero on success, negative of failure.
 */
extern int bdk_spi_restart_interface(int interface, bdk_spi_mode_t mode, int timeout);

/**
 * Return non-zero if the SPI interface has a SPI4000 attached
 *
 * @param interface SPI interface the SPI4000 is connected to
 *
 * @return
 */
extern int bdk_spi4000_is_present(int interface);

/**
 * Initialize the SPI4000 for use
 *
 * @param interface SPI interface the SPI4000 is connected to
 */
extern int bdk_spi4000_initialize(int interface);

/**
 * Poll all the SPI4000 port and check its speed
 *
 * @param interface Interface the SPI4000 is on
 * @param port      Port to poll (0-9)
 * @return Status of the port. 0=down. All other values the port is up.
 */
extern bdk_gmxx_rxx_rx_inbnd_t bdk_spi4000_check_speed(int interface, int port);

/**
 * Get current SPI4 initialization callbacks
 *
 * @param callbacks  Pointer to the callbacks structure.to fill
 *
 * @return Pointer to bdk_spi_callbacks_t structure.
 */
extern void bdk_spi_get_callbacks(bdk_spi_callbacks_t * callbacks);

/**
 * Set new SPI4 initialization callbacks
 *
 * @param new_callbacks  Pointer to an updated callbacks structure.
 */
extern void bdk_spi_set_callbacks(bdk_spi_callbacks_t * new_callbacks);

/**
 * Callback to perform SPI4 reset
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_reset_cb(int interface, bdk_spi_mode_t mode);

/**
 * Callback to setup calendar and miscellaneous settings before clock detection
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param num_ports Number of ports to configure on SPI
 *
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_calendar_setup_cb(int interface, bdk_spi_mode_t mode, int num_ports);

/**
 * Callback to perform clock detection
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param timeout   Timeout to wait for clock synchronization in seconds
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_clock_detect_cb(int interface, bdk_spi_mode_t mode, int timeout);

/**
 * Callback to perform link training
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param timeout   Timeout to wait for link to be trained (in seconds)
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_training_cb(int interface, bdk_spi_mode_t mode, int timeout);

/**
 * Callback to perform calendar data synchronization
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @param timeout   Timeout to wait for calendar data in seconds
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_calendar_sync_cb(int interface, bdk_spi_mode_t mode, int timeout);

/**
 * Callback to handle interface up
 *
 * @param interface The identifier of the packet interface to configure and
 *                  use as a SPI interface.
 * @param mode      The operating mode for the SPI interface. The interface
 *                  can operate as a full duplex (both Tx and Rx data paths
 *                  active) or as a halfplex (either the Tx data path is
 *                  active or the Rx data path is active, but not both).
 * @return Zero on success, non-zero error code on failure (will cause SPI initialization to abort)
 */
extern int bdk_spi_interface_up_cb(int interface, bdk_spi_mode_t mode);


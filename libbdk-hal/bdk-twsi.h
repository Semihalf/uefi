/**
 * @file
 *
 * Interface to the TWSI / I2C bus
 *
 * Note: Currently on 7 bit device addresses are supported
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

    /* Extra TWSI Bus Opcodes */
#define TWSI_SLAVE_ADD     0
#define TWSI_DATA          1
#define TWSI_CTL           2
#define TWSI_CLKCTL_STAT   3       /* R=0 selects CLKCTL, R=1 selects STAT */
#define TWSI_STAT          3       /* when R = 1 */
#define TWSI_SLAVE_ADD_EXT 4
#define TWSI_RST           7


/**
 * Do a twsi read from a 7 bit device address using an (optional) internal address.
 * Up to 8 bytes can be read at a time.
 *
 * @param twsi_id   which Octeon TWSI bus to use
 * @param dev_addr  Device address (7 bit)
 * @param internal_addr
 *                  Internal address.  Can be 0, 1 or 2 bytes in width
 * @param num_bytes Number of data bytes to read
 * @param ia_width_bytes
 *                  Internal address size in bytes (0, 1, or 2)
 * @param data      Pointer argument where the read data is returned.
 *
 * @return read data returned in 'data' argument
 *         Number of bytes read on success
 *         -1 on failure
 */
extern int bdk_twsix_read_ia(int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes, int ia_width_bytes, uint64_t *data);

/**
 * A convenience wrapper function around bdk_twsix_read_ia() that
 * only supports 8 bit internal addresses.
 * Reads up to 7 bytes, and returns both the value read or error
 * value in the return value
 *
 * @param twsi_id   which Octeon TWSI bus to use
 * @param dev_addr  Device address (7 bit only)
 * @param internal_addr
 *                  Internal address (8 bit only)
 * @param num_bytes Number of bytes to read (0-7)
 *
 * @return Value read from TWSI on success
 *         -1 on error
 */
extern int64_t bdk_twsix_read_ia8(int twsi_id, uint8_t dev_addr, uint8_t internal_addr, int num_bytes);

/**
 * A convenience wrapper function around bdk_twsix_read_ia() that
 * only supports 16 bit internal addresses.
 * Reads up to 7 bytes, and returns both the value read or error
 * value in the return value
 *
 * @param twsi_id   which Octeon TWSI bus to use
 * @param dev_addr  Device address (7 bit only)
 * @param internal_addr
 *                  Internal address (16 bit only)
 * @param num_bytes Number of bytes to read (0-7)
 *
 * @return Value read from TWSI on success
 *         -1 on error
 */
extern int64_t bdk_twsix_read_ia16(int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes);

/**
 * Read from a TWSI device (7 bit device address only) without generating any
 * internal addresses.
 * Read from 1-8 bytes and returns them in the data pointer.
 *
 * @param twsi_id   TWSI interface on Octeon to use
 * @param dev_addr  TWSI device address (7 bit only)
 * @param num_bytes number of bytes to read
 * @param data      Pointer to data read from TWSI device
 *
 * @return Number of bytes read on success
 *         -1 on error
 */
extern int bdk_twsix_read(int twsi_id, uint8_t dev_addr, int num_bytes, uint64_t *data);



/**
 * Perform a twsi write operation to a 7 bit device address.
 *
 * Note that many eeprom devices have page restrictions regarding address boundaries
 * that can be crossed in one write operation.  This is device dependent, and this routine
 * does nothing in this regard.
 * This command does not generate any internal addressess.
 *
 * @param twsi_id   Octeon TWSI interface to use
 * @param dev_addr  TWSI device address
 * @param num_bytes Number of bytes to write (between 1 and 8 inclusive)
 * @param data      Data to write
 *
 * @return 0 on success
 *         -1 on failure
 */
extern int bdk_twsix_write(int twsi_id, uint8_t dev_addr, int num_bytes, uint64_t data);

/**
 * Write 1-8 bytes to a TWSI device using an internal address.
 *
 * @param twsi_id   which TWSI interface on Octeon to use
 * @param dev_addr  TWSI device address (7 bit only)
 * @param internal_addr
 *                  TWSI internal address (0, 8, or 16 bits)
 * @param num_bytes Number of bytes to write (1-8)
 * @param ia_width_bytes
 *                  internal address width, in bytes (0, 1, 2)
 * @param data      Data to write.  Data is written MSB first on the twsi bus, and only the lower
 *                  num_bytes bytes of the argument are valid.  (If a 2 byte write is done, only
 *                  the low 2 bytes of the argument is used.
 *
 * @return Number of bytes read on success,
 *         -1 on error
 */
extern int bdk_twsix_write_ia(int twsi_id, uint8_t dev_addr, uint16_t internal_addr, int num_bytes, int ia_width_bytes, uint64_t data);

/***********************************************************************
** Functions below are deprecated, and not recomended for use.
** They have been superceded by more flexible functions that are
** now provided.
************************************************************************/






/**
 * Read 8-bit from a device on the TWSI / I2C bus
 *
 * @param twsi_id  Which TWSI bus to use. CN3XXX, CN58XX, and CN50XX only
 *                 support 0. CN56XX and CN57XX support 0-1.
 * @param dev_addr I2C device address (7 bit)
 * @param internal_addr
 *                 Internal device address
 *
 * @return 8-bit data or < 0 in case of error
 */
extern int bdk_twsix_read8(int twsi_id, uint8_t dev_addr, uint8_t internal_addr);

/**
 * Read 8-bit from a device on the TWSI / I2C bus
 *
 * Uses current internal address
 *
 * @param twsi_id  Which TWSI bus to use. CN3XXX, CN58XX, and CN50XX only
 *                 support 0. CN56XX and CN57XX support 0-1.
 * @param dev_addr I2C device address (7 bit)
 *
 * @return 8-bit value or < 0 in case of error
 */
extern int bdk_twsix_read8_cur_addr(int twsi_id, uint8_t dev_addr);

/**
 * Write 8-bit to a device on the TWSI / I2C bus
 *
 * @param twsi_id  Which TWSI bus to use. CN3XXX, CN58XX, and CN50XX only
 *                 support 0. CN56XX and CN57XX support 0-1.
 * @param dev_addr I2C device address (7 bit)
 * @param internal_addr
 *                 Internal device address
 * @param data     Data to be written
 *
 * @return 0 on success and < 0 in case of error
 */
extern int bdk_twsix_write8(int twsi_id, uint8_t dev_addr, uint8_t internal_addr, uint8_t data);

/**
 * Read 8-bit from a device on the TWSI / I2C bus zero.
 *
 * This function is for compatibility with SDK 1.6.0 and
 * before which only supported a single TWSI bus.
 *
 * @param dev_addr I2C device address (7 bit)
 * @param internal_addr
 *                 Internal device address
 *
 * @return 8-bit data or < 0 in case of error
 */
extern int bdk_twsi_read8(uint8_t dev_addr, uint8_t internal_addr);

/**
 * Read 8-bit from a device on the TWSI / I2C bus zero.
 *
 * Uses current internal address
 *
 * This function is for compatibility with SDK 1.6.0 and
 * before which only supported a single TWSI bus.
 *
 * @param dev_addr I2C device address (7 bit)
 *
 * @return 8-bit value or < 0 in case of error
 */
extern int bdk_twsi_read8_cur_addr(uint8_t dev_addr);

/**
 * Write 8-bit to a device on the TWSI / I2C bus zero.
 * This function is for compatibility with SDK 1.6.0 and
 * before which only supported a single TWSI bus.
 *
 * @param dev_addr I2C device address (7 bit)
 * @param internal_addr
 *                 Internal device address
 * @param data     Data to be written
 *
 * @return 0 on success and < 0 in case of error
 */
extern int bdk_twsi_write8(uint8_t dev_addr, uint8_t internal_addr, uint8_t data);

/** @} */

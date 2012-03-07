
/**
 * @file
 *
 * Function and structure definitions for QLM manipulation
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/**
 * This structure is used to describe the QLM bits in bdk-qlm-table
 */
typedef struct
{
    const char *name;
    uint16_t stop_bit;
    uint16_t start_bit;
} __bdk_qlm_jtag_field_t;

/**
 * Initialize the QLM layer
 */
extern void bdk_qlm_init(void);

/**
 * Return the number of QLMs supported for the chip
 *
 * @return Number of QLMs
 */
extern int bdk_qlm_get_num(void);

/**
 * Return the number of lanes in a QLM. QLMs normally contain
 * 4 lanes, except for chips which only have half of a QLM.
 *
 * @param qlm    QLM to get lanes number for
 *
 * @return Number of lanes on the QLM
 */
extern int bdk_qlm_get_lanes(int qlm);

/**
 * Get the mode of a QLM as a human readable string
 *
 * @param qlm    QLM to examine
 *
 * @return String mode
 */
extern const char *bdk_qlm_get_mode(int qlm);

/**
 * Get the speed (Gbaud) of the QLM in Mhz.
 *
 * @param qlm    QLM to examine
 *
 * @return Speed in Mhz
 */
extern int bdk_qlm_get_gbaud_mhz(int qlm);

/**
 * Measure the reference clock of a QLM
 *
 * @param qlm    QLM to measure
 *
 * @return Clock rate in Hz
 */
extern int bdk_qlm_measure_clock(int qlm);

/**
 * Lookup the hardware QLM number for a given interface type and index. This
 * function will fail with a fatal error if called on invalid interfaces for
 * a chip. It returns the QLM number for an interface without checking to
 * see if the QLM is in hte correct mode.
 *
 * @param iftype    Interface type
 * @param interface Interface index number
 *
 * @return QLM number. Dies on a fatal error on failure.
 */
extern int bdk_qlm_get(bdk_if_t iftype, int interface);

/**
 * Get a field in a QLM JTAG chain
 *
 * @param qlm    QLM to get
 * @param lane   Lane in QLM to get
 * @param name   String name of field
 *
 * @return JTAG field value
 */
extern uint64_t bdk_qlm_jtag_get(int qlm, int lane, const char *name);

/**
 * Set a field in a QLM JTAG chain
 *
 * @param qlm    QLM to set
 * @param lane   Lane in QLM to set, or -1 for all lanes
 * @param name   String name of field
 * @param value  Value of the field
 */
extern void bdk_qlm_jtag_set(int qlm, int lane, const char *name, uint64_t value);

/**
 * Force link detection on a QLM. Useful for getting PCIe
 * analyzers to work.
 *
 * @param qlm    QLM to configure
 */
extern void bdk_qlm_cn6xxx_force_link(int qlm);

/** @} */

/* These are the low level bit programming functions for the QLM JTAG
    chains. These should not be used directly. Instead you should use
    the higher level functions in bdk-qlm */

/**
 * This structure is used to describe the QLM bits in bdk-qlm-table
 */
typedef struct
{
    const char *name;
    uint16_t stop_bit;
    uint16_t start_bit;
} __bdk_qlm_jtag_field_t;

extern void __bdk_qlm_jtag_init(const __bdk_qlm_jtag_field_t *fields);
extern uint64_t __bdk_qlm_jtag_shift(int qlm, int bits, uint64_t data);
extern void __bdk_qlm_jtag_shift_zeros(int qlm, int bits);
extern void __bdk_qlm_jtag_update(int qlm);
extern void __bdk_qlm_jtag_capture(int qlm);

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


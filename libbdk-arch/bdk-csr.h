/**
 * @file
 *
 * Functions and macros for accessing Octeon CSRs.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup csr CSR support
 * @{
 */

/**
 * Possible CSR bus types
 */
typedef enum {
   BDK_CSR_TYPE_RSL,        /**< Octeon internal address, but indirect and slow (not used for addresses) */
   BDK_CSR_TYPE_NCB,        /**< Octeon internal address */
   BDK_CSR_TYPE_PEXP,       /**< PCIe BAR 0 address only */
   BDK_CSR_TYPE_PEXP_NCB,   /**< NCB-direct and PCIe BAR0 address */
   BDK_CSR_TYPE_PEXPV_NCB,  /**< Virtual NCB-direct and PCIe BAR0 address */
   BDK_CSR_TYPE_PCICONFIGEP,/**< PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
   BDK_CSR_TYPE_PCICONFIGRC,/**< PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
} bdk_csr_type_t;

#define BDK_CSR_DB_MAX_PARAM 4
typedef struct __attribute__ ((packed)) {
    uint16_t        name_index;     /**< Index into __bdk_csr_db_string where the name is */
    bdk_csr_type_t  type : 4;       /**< Enum type from above */
    uint8_t         width : 4;      /**< CSR width in bytes */
    uint16_t        field_index;    /**< Index into __bdk_csr_db_fieldList where the fields start */
    uint8_t         range[BDK_CSR_DB_MAX_PARAM]; /**< Index into __bdk_csr_db_range where the range is */
    uint16_t        base_index;     /**< Index into __bdk_csr_db_number where the base address is */
    uint16_t        param_inc[BDK_CSR_DB_MAX_PARAM]; /**< Index into __bdk_csr_db_number where the param multiplier is */
} __bdk_csr_db_type_t;

typedef struct {
    uint32_t model;
    const int16_t *data;            /**< Array of integers indexing __bdk_csr_db_csr */
} __bdk_csr_db_map_t;

extern void __bdk_csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2, unsigned long arg3, unsigned long arg4) __attribute__ ((noreturn));

extern int bdk_csr_decode(const char *name, uint64_t value);
extern int bdk_csr_field(const char *csr_name, int field_start_bit, const char **field_name);
extern uint64_t bdk_csr_read_by_name(bdk_node_t node, const char *name);
extern int bdk_csr_write_by_name(bdk_node_t node, const char *name, uint64_t value);
extern int bdk_csr_get_name(const char *last_name, char *buffer);

#ifndef BDK_BUILD_HOST

/**
 * Read a value from a CSR. Normally this function should not be
 * used directly. Instead use the macro BDK_CSR_READ that fills
 * in the parameters to this function for you.
 *
 * @param node    Node to use in a Numa setup. Can be an exact ID or a special value.
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 *
 * @return The value of the CSR
 */
static inline uint64_t bdk_csr_read(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address) __attribute__ ((always_inline));
static inline uint64_t bdk_csr_read(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    extern uint64_t __bdk_csr_read_slow(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address);
    switch (type)
    {
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            address |= 1ull<<63;
            address |= (uint64_t)node << 36;
            switch (size)
            {
                case 1:
                    return *(volatile uint8_t *)address;
                case 2:
                    return *(volatile uint16_t *)address;
                case 4:
                    return *(volatile uint32_t *)address;
                default:
                    return *(volatile uint64_t *)address;
            }
        default:
            return __bdk_csr_read_slow(node, type, busnum, size, address);
    }
}


/**
 * Wrate a value to a CSR. Normally this function should not be
 * used directly. Instead use the macro BDK_CSR_WRITE that fills
 * in the parameters to this function for you.
 *
 * @param node    Node to use in a Numa setup. Can be an exact ID or a special value.
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 * @param value   Value to write to the CSR
 */
static inline void bdk_csr_write(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value) __attribute__ ((always_inline));
static inline void bdk_csr_write(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    extern void __bdk_csr_write_slow(bdk_node_t node, bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);
    switch (type)
    {
        case BDK_CSR_TYPE_PEXP_NCB:
        case BDK_CSR_TYPE_PEXPV_NCB:
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            address |= 1ull<<63;
            address |= (uint64_t)node << 36;
            switch (size)
            {
                case 1:
                    *(volatile uint8_t *)address = value;
                    break;
                case 2:
                    *(volatile uint16_t *)address = value;
                    break;
                case 4:
                    *(volatile uint32_t *)address = value;
                    break;
                default:
                    *(volatile uint64_t *)address = value;
                    break;
            }
            break;

        default:
            __bdk_csr_write_slow(node, type, busnum, size, address, value);
    }
}

static inline void bdk_send_single(uint64_t data) __attribute__ ((always_inline));
static inline void bdk_send_single(uint64_t data)
{
    *(volatile uint64_t *)0xffffffffffffa200ull = data;
}

#else
#define bdk_csr_read octeon_remote_read_csr
#define bdk_csr_write octeon_remote_write_csr
#endif

/**
 * This macro makes it easy to define a variable of the correct
 * type for a CSR.
 */
#define BDK_CSR_DEFINE(name, csr) typedef_##csr name

/**
 * This macro makes it easy to define a variable and initialize it
 * with a CSR.
 */
#define BDK_CSR_INIT(name, node, csr) typedef_##csr name = {.u = bdk_csr_read(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)}

/**
 * Macro to read a CSR
 */
#define BDK_CSR_READ(node, csr) bdk_csr_read(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)

/**
 * Macro to write a CSR
 */
#define BDK_CSR_WRITE(node, csr, value) bdk_csr_write(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, value)

/**
 * Macro to make a read, modify, and write sequence easy. The "code_block"
 * should be replaced with a C code block or a comma separated list of
 * "name.s.field = value", without the quotes.
 */
#define BDK_CSR_MODIFY(name, node, csr, code_block) do { \
        typedef_##csr name = {.u = bdk_csr_read(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)}; \
        code_block; \
        bdk_csr_write(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, name.u); \
    } while (0)

/**
 * This macro spins on a field waiting for it to reach a value. It
 * is common in code to need to wait for a specific field in a CSR
 * to match a specific value. Conceptually this macro expands to:
 *
 * 1) read csr at "address" with a csr typedef of "type"
 * 2) Check if ("type".s."field" "op" "value")
 * 3) If #2 isn't true loop to #1 unless too much time has passed.
 */
#define BDK_CSR_WAIT_FOR_FIELD(node, csr, field, op, value, timeout_usec) \
    ({int result;                                                       \
    do {                                                                \
        uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + (uint64_t)timeout_usec * \
                        bdk_clock_get_rate(bdk_numa_local(), BDK_CLOCK_CORE) / 1000000;   \
        typedef_##csr c;                                                \
        while (1)                                                       \
        {                                                               \
            c.u = bdk_csr_read(node, bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr);                             \
            if ((c.s.field) op (value)) {                               \
                result = 0;                                             \
                break;                                                  \
            } else if (bdk_clock_get_count(BDK_CLOCK_CORE) > done) {    \
                result = -1;                                            \
                break;                                                  \
            } else                                                      \
                bdk_thread_yield();                                     \
        }                                                               \
    } while (0);                                                        \
    result;})

/** @} */

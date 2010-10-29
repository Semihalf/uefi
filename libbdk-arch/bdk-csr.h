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
   BDK_CSR_TYPE_PCICONFIGEP,/**< PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
   BDK_CSR_TYPE_PCICONFIGRC,/**< PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
   BDK_CSR_TYPE_SRIOMAINT   /**< SRIOMAINT - SRIO maintenance registers */
} bdk_csr_type_t;

typedef struct {
    uint16_t        name_index;
    bdk_csr_type_t  type : 8;
    uint8_t         width;
    uint16_t        field_index;
    uint8_t         offset_range;
    uint8_t         block_range;
    uint64_t        base;
    uint64_t        offset_inc;
    uint64_t        block_inc;
} bdk_csr_db_type_t;

typedef struct {
    uint32_t model;
    const bdk_csr_db_type_t *data;
} bdk_csr_db_map_t;


/**
 * Read a value from a CSR. Normally this function should not be
 * used directly. Instead use the macro BDK_CSR_READ that fills
 * in the parameters to this function for you.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 *
 * @return The value of the CSR
 */
static inline uint64_t bdk_csr_read(bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    extern uint64_t __bdk_csr_read_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address);
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            address |= 1ull<<63;
            if (size == 4)
                return *(volatile uint32_t *)(address ^ 4);
            else
                return *(volatile uint64_t *)address;

        case BDK_CSR_TYPE_PEXP_NCB:
            address |= 0x80011F0000008000ull;
            if (size == 4)
                return *(volatile uint32_t *)(address ^ 4);
            else
                return *(volatile uint64_t *)address;
        default:
            return __bdk_csr_read_slow(type, busnum, size, address);
    }
}


/**
 * Wrate a value to a CSR. Normally this function should not be
 * used directly. Instead use the macro BDK_CSR_WRITE that fills
 * in the parameters to this function for you.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 * @param value   Value to write to the CSR
 */
static inline void bdk_csr_write(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    extern void __bdk_csr_write_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
            address |= 1ull<<63;
            if (size == 4)
                *(volatile uint32_t *)(address ^ 4) = value;
            else
                *(volatile uint64_t *)address = value;
            /* Perform an immediate read after every write to an RSL register to force
                the write to complete. It doesn't matter what RSL read we do, so we
                choose MIO_BOOT_BIST_STAT because it is fast and harmless. We use a
                hardcoded address to avoid needing all the CSRs */
            *(volatile uint64_t *)0x80011800000000F8ull;
            break;

        case BDK_CSR_TYPE_NCB:
            address |= 1ull<<63;
            if (size == 4)
                *(volatile uint32_t *)(address ^ 4) = value;
            else
                *(volatile uint64_t *)address = value;
            break;

        case BDK_CSR_TYPE_PEXP_NCB:
            address |= 0x80011F0000008000ull;
            if (size == 4)
                *(volatile uint32_t *)(address ^ 4) = value;
            else
                *(volatile uint64_t *)address = value;
            break;

        default:
            __bdk_csr_write_slow(type, busnum, size, address, value);
    }
}

static inline void bdk_send_single(uint64_t data)
{
    *(volatile uint64_t *)0xffffffffffffa200ull = data;
}

extern int bdk_csr_decode(const char *name, uint64_t value);
extern uint64_t bdk_csr_read_by_name(const char *name);
extern int bdk_csr_write_by_name(const char *name, uint64_t value);
extern int bdk_csr_get_name(const char *last_name, char *buffer);

/**
 * This macro makes it easy to define a variable of the correct
 * type for a CSR.
 */
#define BDK_CSR_DEFINE(name, csr) typedef_##csr name

/**
 * This macro makes it easy to define a variable and initialize it
 * with a CSR.
 */
#define BDK_CSR_INIT(name, csr) typedef_##csr name = {.u64 = bdk_csr_read(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)}

/**
 * Macro to read a CSR
 */
#define BDK_CSR_READ(csr) bdk_csr_read(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)

/**
 * Macro to write a CSR
 */
#define BDK_CSR_WRITE(csr, value) bdk_csr_write(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, value)

/**
 * Macro to make a read, modify, and write sequence easy. The "code_block"
 * should be replaced with a C code block or a comma seperated list of
 * "name.s.field = value", without the quotes.
 */
#define BDK_CSR_MODIFY(name, csr, code_block) do { \
        typedef_##csr name = {.u64 = bdk_csr_read(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)}; \
        code_block; \
        bdk_csr_write(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, name.u64); \
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
#define BDK_CSR_WAIT_FOR_FIELD(csr, field, op, value, timeout_usec)     \
    ({int result;                                                       \
    do {                                                                \
        uint64_t done = bdk_clock_get_count(BDK_CLOCK_CORE) + (uint64_t)timeout_usec * \
                        bdk_clock_get_rate(BDK_CLOCK_CORE) / 1000000;   \
        typedef_##csr c;                                                \
        while (1)                                                       \
        {                                                               \
            c.u64 = bdk_csr_read(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr);                             \
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

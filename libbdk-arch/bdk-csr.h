/**
 * Possible CSR bus types
 */
typedef enum {
   BDK_CSR_TYPE_RSL,        /**< Octeon internal address, but indirect and slow (not used for addresses) */
   BDK_CSR_TYPE_NCB,        /**< Octeon internal address */
   BDK_CSR_TYPE_PCI_NCB,    /**< Can be accessed through PCI BAR0, also an NCB alias (not used for addresses) */
   BDK_CSR_TYPE_PCICONFIG,  /**< PCI Config, also an NCB alias */
   BDK_CSR_TYPE_PCI,        /**< PCI BAR0 (only) */
   BDK_CSR_TYPE_PEXP,       /**< PCIe BAR 0 address only */
   BDK_CSR_TYPE_PEXP_NCB,   /**< NCB-direct and PCIe BAR0 address */
   BDK_CSR_TYPE_PCICONFIGEP,/**< PCIe config address (EP mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
   BDK_CSR_TYPE_PCICONFIGRC,/**< PCICONFIGRC - PCIe config address (RC mode) + indirect through PESC*_CFG_RD/PESC*_CFG_WR */
   BDK_CSR_TYPE_SRIOMAINT   /**< SRIOMAINT - SRIO maintenance registers */
} bdk_csr_type_t;


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
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
            address |= 1ull<<63;
            if (size == 4)
                return *(volatile uint32_t *)(address ^ 4);
            else
                return *(volatile uint64_t *)address;

        case BDK_CSR_TYPE_PCI_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            break;

        case BDK_CSR_TYPE_PCI:
        case BDK_CSR_TYPE_PEXP:
            break;

        case BDK_CSR_TYPE_PCICONFIG:
        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
            break;

        case BDK_CSR_TYPE_SRIOMAINT:
            break;
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

        case BDK_CSR_TYPE_PCI_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            break;

        case BDK_CSR_TYPE_PCI:
        case BDK_CSR_TYPE_PEXP:
            break;

        case BDK_CSR_TYPE_PCICONFIG:
        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
            break;

        case BDK_CSR_TYPE_SRIOMAINT:
            break;
    }
}

static inline void bdk_send_single(uint64_t data)
{
    *(volatile uint64_t *)0xffffffffffffa200ull = data;
}

extern void bdk_warn(const char *format, ...) __attribute__ ((format(printf, 1, 2)));

/**
 * This macro makes it easy to define a variable of the correct
 * type for a CSR.
 */
#define BDK_CSR_DEFINE(name, csr) typedef_##csr name

/**
 * This macro makes it easy to define a variable and initialize it
 * with a CSR.
 */
#define BDK_CSR_INIT(name, csr) typedef_##csr name = {.u64 = BDK_CSR_READ(csr)}

/**
 * Macro to read a CSR
 */
#define BDK_CSR_READ(csr) bdk_csr_read(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr)

/**
 * Macro to write a CSR
 */
#define BDK_CSR_WRITE(csr, value) bdk_csr_write(bustype_##csr, busnum_##csr, sizeof(typedef_##csr), csr, value)

/**
 * Macro to make a read, modify, and write sequence easy. The "..."
 * should be replaced with a comma seperated list of
 * "name.s.field = value", without the quotes.
 */
#define BDK_CSR_MODIFY(name, csr, ...) do { BDK_CSR_INIT(name, csr); __VARGS__; BDK_CSR_WRITE(csr, name);} while (0)


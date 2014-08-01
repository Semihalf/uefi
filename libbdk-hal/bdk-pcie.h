/**
 * @file
 *
 * Interface to PCIe as a host(RC) or target(EP)
 *
 * <hr>$Revision: 51109 $<hr>
 *
 * @addtogroup hal
 * @{
 */

/*
 * The physical memory base mapped by BAR1.  256MB at the end of the
 * first 4GB.
 */
#define BDK_PCIE_BAR1_PHYS_BASE ((1ull << 32) - (1ull << 28))
#define BDK_PCIE_BAR1_PHYS_SIZE (1ull << 28)

/*
 * The RC base of BAR1.  gen1 has a 39-bit BAR2, gen2 has 41-bit BAR2,
 * place BAR1 so it is the same for both.
 */
#define BDK_PCIE_BAR1_RC_BASE (1ull << 41)

typedef union
{
    uint64_t    u64;
    struct
    {
        uint64_t    upper           : 2;    /* Normally 2 for XKPHYS */
        uint64_t    reserved_49_61  : 13;   /* Must be zero */
        uint64_t    io              : 1;    /* 1 for IO space access */
        uint64_t    did             : 5;    /* PCIe DID = 3 */
        uint64_t    subdid          : 3;    /* PCIe SubDID = 1 */
        uint64_t    reserved_38_39  : 2;    /* Must be zero */
        uint64_t    node            : 2;    /* Numa node number */
        uint64_t    es              : 2;    /* Endian swap = 1 */
        uint64_t    port            : 2;    /* PCIe port 0,1 */
        uint64_t    reserved_29_31  : 3;    /* Must be zero */
        uint64_t    ty              : 1;    /* Selects the type of the configuration request (0 = type 0, 1 = type 1). */
        uint64_t    bus             : 8;    /* Target bus number sent in the ID in the request. */
        uint64_t    dev             : 5;    /* Target device number sent in the ID in the request. Note that Dev must be
                                                zero for type 0 configuration requests. */
        uint64_t    func            : 3;    /* Target function number sent in the ID in the request. */
        uint64_t    reg             : 12;   /* Selects a register in the configuration space of the target. */
    } config;
    struct
    {
        uint64_t    upper           : 2;    /* Normally 2 for XKPHYS */
        uint64_t    reserved_49_61  : 13;   /* Must be zero */
        uint64_t    io              : 1;    /* 1 for IO space access */
        uint64_t    did             : 5;    /* PCIe DID = 3 */
        uint64_t    subdid          : 3;    /* PCIe SubDID = 2 */
        uint64_t    reserved_38_39  : 2;    /* Must be zero */
        uint64_t    node            : 2;    /* Numa node number */
        uint64_t    es              : 2;    /* Endian swap = 1 */
        uint64_t    port            : 2;    /* PCIe port 0,1 */
        uint64_t    address         : 32;   /* PCIe IO address */
    } io;
    struct
    {
        uint64_t    upper           : 2;    /* Normally 2 for XKPHYS */
        uint64_t    reserved_49_61  : 13;   /* Must be zero */
        uint64_t    io              : 1;    /* 1 for IO space access */
        uint64_t    did             : 5;    /* PCIe DID = 3 */
        uint64_t    subdid          : 3;    /* PCIe SubDID = 3-6 */
        uint64_t    reserved_38_39  : 2;    /* Must be zero */
        uint64_t    node            : 2;    /* Numa node number */
        uint64_t    address         : 36;   /* PCIe Mem address */
    } mem;
} bdk_pcie_address_t;


/**
 * Return the Core virtual base address for PCIe IO access. IOs are
 * read/written as an offset from this address.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the IO is for
 *
 * @return 64bit IO base address for read/write
 */
uint64_t bdk_pcie_get_io_base_address(bdk_node_t node, int pcie_port);

/**
 * Size of the IO address region returned at address
 * bdk_pcie_get_io_base_address()
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the IO is for
 *
 * @return Size of the IO window
 */
uint64_t bdk_pcie_get_io_size(bdk_node_t node, int pcie_port);

/**
 * Return the Core virtual base address for PCIe MEM access. Memory is
 * read/written as an offset from this address.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the IO is for
 *
 * @return 64bit IO base address for read/write
 */
uint64_t bdk_pcie_get_mem_base_address(bdk_node_t node, int pcie_port);

/**
 * Size of the Mem address region returned at address
 * bdk_pcie_get_mem_base_address()
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the IO is for
 *
 * @return Size of the Mem window
 */
uint64_t bdk_pcie_get_mem_size(bdk_node_t node, int pcie_port);

/**
 * Initialize a PCIe port for use in host(RC) mode. It doesn't enumerate the bus.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_rc_initialize(bdk_node_t node, int pcie_port);

/**
 * Shutdown a PCIe port and put it in reset
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port to shutdown
 *
 * @return Zero on success
 */
int bdk_pcie_rc_shutdown(bdk_node_t node, int pcie_port);

/**
 * Read 8bits from a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint8_t bdk_pcie_config_read8(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg);

/**
 * Read 16bits from a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint16_t bdk_pcie_config_read16(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg);

/**
 * Read 32bits from a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 *
 * @return Result of the read
 */
uint32_t bdk_pcie_config_read32(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg);

/**
 * Write 8bits to a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write8(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint8_t val);

/**
 * Write 16bits to a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write16(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint16_t val);

/**
 * Write 32bits to a Device's config space
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port the device is on
 * @param bus       Sub bus
 * @param dev       Device ID
 * @param fn        Device sub function
 * @param reg       Register to access
 * @param val       Value to write
 */
void bdk_pcie_config_write32(bdk_node_t node, int pcie_port, int bus, int dev, int fn, int reg, uint32_t val);

/**
 * Initialize a PCIe port for use in target(EP) mode.
 *
 * @param node      Node to use in a Numa setup. Can be an exact ID or a special
 *                  value.
 * @param pcie_port PCIe port to initialize
 *
 * @return Zero on success
 */
int bdk_pcie_ep_initialize(bdk_node_t node, int pcie_port);

/** @} */

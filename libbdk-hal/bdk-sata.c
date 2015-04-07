#include <bdk.h>
#include <malloc.h>

/* This code is an optional part of the BDK. It is only linked in
    if BDK_REQUIRE() needs it */
BDK_REQUIRE_DEFINE(SATA);

/* Most all information used to create this code was gotten from this wiki
   page: http://wiki.osdev.org/AHCI */

/**
 * Following code defines different kinds of FIS specified in Serial
 *    ATA Revision 3.0.
 */
typedef enum
{
    FIS_TYPE_REG_H2D    = 0x27, /**< Register FIS - host to device */
    FIS_TYPE_REG_D2H    = 0x34, /**< Register FIS - device to host */
    FIS_TYPE_DMA_ACT    = 0x39, /**< DMA activate FIS - device to host */
    FIS_TYPE_DMA_SETUP  = 0x41, /**< DMA setup FIS - bidirectional */
    FIS_TYPE_DATA       = 0x46, /**< Data FIS - bidirectional */
    FIS_TYPE_BIST       = 0x58, /**< BIST activate FIS - bidirectional */
    FIS_TYPE_PIO_SETUP  = 0x5F, /**< PIO setup FIS - device to host */
    FIS_TYPE_DEV_BITS   = 0xA1, /**< Set device bits FIS - device to host */
} fis_type_t;

/**
 * A host to device register FIS is used by the host to send
 * command or control to a device. As illustrated in the
 * following data structure, it contains the IDE registers such
 * as command, LBA, device, feature, count and control. An ATA
 * command is constructed in this structure and issued to the
 * device. All reserved fields in an FIS should be cleared to
 * zero.
 */
typedef struct
{
        // DWORD 0
        uint8_t fis_type;   /**< FIS_TYPE_REG_H2D */
        uint8_t pmport:4;   /**< Port multiplier */
        uint8_t rsv0:3;     /**< Reserved */
        uint8_t c:1;        /**< 1: Command, 0: Control */
        uint8_t command;    /**< Command register */
        uint8_t featurel;   /**< Feature register, 7:0 */
        // DWORD 1
        uint8_t lba0;       /**< LBA low register, 7:0 */
        uint8_t lba1;       /**< LBA mid register, 15:8 */
        uint8_t lba2;       /**< LBA high register, 23:16 */
        uint8_t device;     /**< Device register */
        // DWORD 2
        uint8_t lba3;       /**< LBA register, 31:24 */
        uint8_t lba4;       /**< LBA register, 39:32 */
        uint8_t lba5;       /**< LBA register, 47:40 */
        uint8_t featureh;   /**< Feature register, 15:8 */
        // DWORD 3
        uint16_t count;     /**< Count register */
        uint8_t icc;        /**< Isochronous command completion */
        uint8_t control;    /**< Control register */
        // DWORD 4
        uint8_t rsv1[4];    /**< Reserved */
} fis_reg_h2d_t;

/**
 * A device to host register FIS is used by the device to notify
 * the host that some ATA register has changed. It contains the
 * updated task files such as status, error and other registers.
 */
typedef struct
{
        // DWORD 0
        uint8_t fis_type;    /**< FIS_TYPE_REG_D2H */
        uint8_t pmport:4;    /**< Port multiplier */
        uint8_t rsv0:2;      /**< Reserved */
        uint8_t i:1;         /**< Interrupt bit */
        uint8_t rsv1:1;      /**< Reserved */
        uint8_t status;      /**< Status register */
        uint8_t error;       /**< Error register */
        // DWORD 1
        uint8_t lba0;        /**< LBA low register, 7:0 */
        uint8_t lba1;        /**< LBA mid register, 15:8 */
        uint8_t lba2;        /**< LBA high register, 23:16 */
        uint8_t device;      /**< Device register */
        // DWORD 2
        uint8_t lba3;        /**< LBA register, 31:24 */
        uint8_t lba4;        /**< LBA register, 39:32 */
        uint8_t lba5;        /**< LBA register, 47:40 */
        uint8_t rsv2;        /**< Reserved */
        // DWORD 3
        uint8_t countl;      /**< Count register, 7:0 */
        uint8_t counth;      /**< Count register, 15:8 */
        uint8_t rsv3[2];     /**< Reserved */
        // DWORD 4
        uint8_t rsv4[4];     /**< Reserved */
} fis_reg_d2h_t;

/**
 * This FIS is used by the host or device to send data payload.
 * The data size can be varied.
 */
typedef struct
{
        // DWORD 0
        uint8_t fis_type;   /**< FIS_TYPE_DATA */
        uint8_t pmport:4;   /**< Port multiplier */
        uint8_t rsv0:4;     /**< Reserved */
        uint8_t rsv1[2];    /**< Reserved */
        // DWORD 1 ~ N
        uint32_t data[1];   /**< Payload */
} fis_data_t;

/**
 * This FIS is used by the device to tell the host that it's
 * about to send or ready to receive a PIO data payload.
 */
typedef struct
{
        // DWORD 0
        uint8_t fis_type;   /**< FIS_TYPE_PIO_SETUP */
        uint8_t pmport:4;   /**< Port multiplier */
        uint8_t rsv0:1;     /**< Reserved */
        uint8_t d:1;        /**< Data transfer direction, 1 - device to host */
        uint8_t i:1;        /**< Interrupt bit */
        uint8_t rsv1:1;
        uint8_t status;     /**< Status register */
        uint8_t error;      /**< Error register */
        // DWORD 1
        uint8_t lba0;       /**< LBA low register, 7:0 */
        uint8_t lba1;       /**< LBA mid register, 15:8 */
        uint8_t lba2;       /**< LBA high register, 23:16 */
        uint8_t device;     /**< Device register */
        // DWORD 2
        uint8_t lba3;       /**< LBA register, 31:24 */
        uint8_t lba4;       /**< LBA register, 39:32 */
        uint8_t lba5;       /**< LBA register, 47:40 */
        uint8_t rsv2;       /**< Reserved */
        // DWORD 3
        uint8_t countl;     /**< Count register, 7:0 */
        uint8_t counth;     /**< Count register, 15:8 */
        uint8_t rsv3;       /**< Reserved */
        uint8_t e_status;   /**< New value of status register */
        // DWORD 4
        uint16_t tc;        /**< Transfer count */
        uint8_t rsv4[2];    /**< Reserved */
} fis_pio_setup_t;

/**
 * DMA Setup ? Device to Host
 */
typedef struct __attribute__ ((__packed__))
{
        // DWORD 0
        uint8_t fis_type;   /**< FIS_TYPE_DMA_SETUP */
        uint8_t pmport:4;   /**< Port multiplier */
        uint8_t rsv0:1;     /**< Reserved */
        uint8_t d:1;        /**< Data transfer direction, 1 - device to host */
        uint8_t i:1;        /**< Interrupt bit */
        uint8_t a:1;        /**< Auto-activate. Specifies if DMA Activate FIS is needed */
        uint8_t rsved[2];   /**< Reserved */
        //DWORD 1&2
        uint64_t DMAbufferID; /**< DMA Buffer Identifier. Used to Identify DMA buffer in host memory. SATA Spec says host specific and not in Spec. Trying AHCI spec might work. */
        //DWORD 3
        uint32_t rsvd;      /**< More reserved */
        //DWORD 4
        uint32_t DMAbufOffset; /**< Byte offset into buffer. First 2 bits must be 0 */
        //DWORD 5
        uint32_t TransferCount; /**< Number of bytes to transfer. Bit 0 must be 0 */
        //DWORD 6
        uint32_t resvd;     /**< Reserved */
} fis_dma_setup_t;

/**
 * There are four kinds of FIS which may be sent to the host by
 * the device as indicated in the following structure
 * declaration. When an FIS has been copied into the host
 * specified memory, an according bit will be set in the Port
 * Interrupt Status register (HBA_PORT.is).
 * Data FIS - Device to Host is not copied to this structure.
 * Data payload is sent and received through PRDT (Physical
 * Region Descriptor Table) in Command List, as will be
 * introduced later.
 */
typedef struct
{
        // 0x00
        fis_dma_setup_t dsfis;      /**< DMA Setup FIS */
        uint8_t         pad0[4];
        // 0x20
        fis_pio_setup_t psfis;      /**< PIO Setup FIS */
        uint8_t         pad1[12];
        // 0x40
        fis_reg_d2h_t   rfis;       /**< Register ? Device to Host FIS */
        uint8_t         pad2[4];
        // 0x58
        uint8_t         sdbfis[8];  /**< Set Device Bit FIS (fis_dev_bits_t) */
        // 0x60
        uint8_t         ufis[64];
        // 0xA0
        uint8_t         rsv[0x100-0xA0];
} hba_fis_t;

/**
 * Command header
 */
typedef struct
{
        // DW0
        uint8_t cfl:5;      /**< Command FIS length in DWORDS, 2 ~ 16 */
        uint8_t a:1;        /**< ATAPI */
        uint8_t w:1;        /**< Write, 1: H2D, 0: D2H */
        uint8_t p:1;        /**< Prefetchable */
        uint8_t r:1;        /**< Reset */
        uint8_t b:1;        /**< BIST */
        uint8_t c:1;        /**< Clear busy upon R_OK */
        uint8_t rsv0:1;     /**< Reserved */
        uint8_t pmp:4;      /**< Port multiplier port */
        uint16_t prdtl;     /**< Physical region descriptor table length in entries */
        // DW1
        uint32_t prdbc;     /**< Physical region descriptor byte count transferred */
        // DW2, 3
        uint64_t ctba;      /**< Command table descriptor base address */
        // DW4 - 7
        uint32_t rsv1[4];   /**< Reserved */
} hba_cmd_header_t;

/**
 * Physical Region Descriptor Table Entry
 */
typedef struct
{
	uint64_t dba;       /**< Data base address */
	uint32_t rsv0;      /**< Reserved */
	uint32_t dbc:22;    /**< Byte count, 4M max */
	uint32_t rsv1:9;    /**< Reserved */
	uint32_t i:1;       /**< Interrupt on completion */
} hba_prdt_entry_t;

/**
 * Command Table
 */
typedef struct
{
	uint8_t cfis[64];   /**< Command FIS */
	uint8_t acmd[16];   /**< ATAPI command, 12 or 16 bytes */
        uint8_t rsv[48];    /**< Reserved */
	hba_prdt_entry_t prdt_entry[1]; /**< Physical region descriptor table entries, 0 ~ 65535 */
} hba_cmd_tbl_t;

/**
 * Return the number of SATA controllers on the chip
 *
 * @param node   Node to query
 *
 * @return Number of controllers, could be zero.
 */
int bdk_sata_get_controllers(bdk_node_t node)
{
    if (CAVIUM_IS_MODEL(CAVIUM_CN88XX))
        return 16; /* 16 controllers on QLMs 2,3, 6-7 */
    else
        return 0;
}

static int __bdk_sata_is_initialized(bdk_node_t node, int controller)
{
    /* Make sure port is clocked before proceeding */
    BDK_CSR_INIT(uctl_ctl, node, BDK_SATAX_UCTL_CTL(controller));
    if (!uctl_ctl.s.a_clk_en || uctl_ctl.s.a_clkdiv_rst)
        return 0;
    BDK_CSR_INIT(fb, node, BDK_SATAX_UAHC_P0_FB(controller));
    return fb.u != 0;
}

/**
 * Initialize a SATA controller and begin device detection
 *
 * @param node       Node to initialize
 * @param controller Which controller to initalize
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_initialize(bdk_node_t node, int controller)
{
    static_assert(sizeof(fis_reg_h2d_t) == 5 * 4);
    static_assert(sizeof(fis_reg_d2h_t)== 5 * 4);
    static_assert(sizeof(fis_data_t) == 2 * 4);
    static_assert(sizeof(fis_pio_setup_t) == 5 * 4);
    static_assert(sizeof(fis_dma_setup_t) == 7 * 4);
    static_assert(sizeof(hba_fis_t) == 256);
    static_assert(sizeof(hba_cmd_header_t) == 8 * 4);
    static_assert(sizeof(hba_prdt_entry_t) == 4 * 4);
    static_assert(sizeof(hba_cmd_tbl_t)== 128 + sizeof(hba_prdt_entry_t));

    /* Make sure port is clocked before proceeding */
    BDK_CSR_INIT(uctl_ctl, node, BDK_SATAX_UCTL_CTL(controller));
    if (!uctl_ctl.s.a_clk_en || uctl_ctl.s.a_clkdiv_rst)
    {
        bdk_error("N%d.SATA%d: Not in SATA mode\n", node, controller);
        return -1;
    }

    /* Allocate area for commands */
    void *clb = memalign(1024, sizeof(hba_cmd_header_t) * 32);
    if (clb == NULL)
    {
        bdk_error("N%d.SATA%d: Failed to allocate command list\n", node, controller);
        return -1;
    }
    memset(clb, 0, sizeof(hba_cmd_header_t) * 32);
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_CLB(controller),
        bdk_ptr_to_phys(clb));

    /* Allocate area for FIS DMAs */
    hba_fis_t *fb = memalign(256, sizeof(hba_fis_t));
    if (fb == NULL)
    {
        bdk_error("N%d.SATA%d: Failed to allocate FIS\n", node, controller);
        return -1;
    }
    memset(fb, 0, sizeof(hba_fis_t));
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_FB(controller),
        bdk_ptr_to_phys(fb));

    /* Enable AHCI command queuing */
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_GBL_CCC_CTL(controller),
        c.s.tv = 0;
        c.s.en = 1);
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_GBL_CCC_PORTS(controller),
        c.s.prt = 1);

    /* Enable the FIS and clear any pending errors */
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_FBS(controller),
        c.s.dec = 1;
        c.s.en = 1);

    /* Disable all interrupts */
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_IE(controller), 0);

    /* Clear all status bits */
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_IS(controller), -1);

    /* Clear all error bits */
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_SERR(controller), -1);

    /* Allow device detection */
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_SCTL(controller),
        c.s.det = 1);

    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_SACT(controller),
        c.s.ds = 1);

    /* Start the port controller */
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_CMD(controller),
        c.s.fre = 1;
        c.s.sud = 1;
        c.s.st = 1);
    return 0;
}

/**
 * Shutdown a SATA controller
 *
 * @param node       Node to access
 * @param controller Controller to shutdown
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_shutdown(bdk_node_t node, int controller)
{
    /* Disable the FIS */
    BDK_CSR_MODIFY(c, node, BDK_SATAX_UAHC_P0_FBS(controller), c.s.en = 0);
    return 0;
}

/**
 * Return the number of SATA ports connected to this AHCI controller
 *
 * @param node       Node to query
 * @param controller SATA controller
 *
 * @return Number of ports. Zero if the controller doesn't connect to a QLM.
 */
int bdk_sata_get_ports(bdk_node_t node, int controller)
{
    BDK_CSR_INIT(ctl, node, BDK_SATAX_UAHC_GBL_CCC_CTL(controller));
    return (ctl.s.en) ? 1 : 0;
}

/**
 * Convert an IDE string into a C string with a NULL terminator
 *
 * @param buffer   Buffer for new string. Must be one longer than length
 * @param original IDE string of identify command
 * @param length   Length of the string in bytes
 */
static void get_ide_string(char *buffer, void *original, int length)
{
    /* Copy the IDE string 2 bytes at a time, swapping as we go */
    uint16_t *newp = (uint16_t *)buffer;
    uint16_t *oldp = (uint16_t *)original;
    for (int i = 0; i < length / 2; i++)
        newp[i] = bdk_swap16(oldp[i]);

    /* Force a NULL terminator */
    buffer[length] = 0;

    /* Remove all trailing spaces */
    while (buffer[length-1] == ' ')
    {
        buffer[length - 1] = 0;
        length--;
    }
}

static int issue_command(bdk_node_t node, int controller, int command, int is_write, uint64_t lba, void *buffer, int size)
{
    /* Pick a command slot to use */
    int slot = 0;
    hba_cmd_header_t *cmd_header = bdk_phys_to_ptr(BDK_CSR_READ(node, BDK_SATAX_UAHC_P0_CLB(controller)));
    cmd_header += slot;

    /* Build a command table with the command to execute */
    hba_cmd_tbl_t cmd_table BDK_CACHE_LINE_ALIGNED;
    memset(&cmd_table, 0, sizeof(hba_cmd_tbl_t));
    /* Where the data is */
    cmd_table.prdt_entry[0].dba = bdk_ptr_to_phys(buffer);
    cmd_table.prdt_entry[0].dbc = size;

    /* The actual command */
    fis_reg_h2d_t *cmd_fis = (fis_reg_h2d_t *)cmd_table.cfis;
    cmd_fis->fis_type = FIS_TYPE_REG_H2D;
    cmd_fis->command = command;
    cmd_fis->device = 1 << 6; /* LBA mode */
    cmd_fis->c = 1; /* Write command register */
    cmd_fis->lba0 = (lba >> 0) & 0xff;
    cmd_fis->lba1 = (lba >> 8) & 0xff;
    cmd_fis->lba2 = (lba >> 16) & 0xff;
    cmd_fis->lba3 = (lba >> 24) & 0xff;
    cmd_fis->lba4 = (lba >> 32) & 0xff;
    cmd_fis->lba5 = (lba >> 40) & 0xff;
    cmd_fis->count = size / 512;

    /* Setup the command header */
    cmd_header->cfl = sizeof(fis_reg_h2d_t) / 4;
    cmd_header->w = is_write;
    cmd_header->prdtl = 1;
    cmd_header->ctba = bdk_ptr_to_phys(&cmd_table);

    BDK_WMB;

    /* Check that the slot is idle */
    BDK_CSR_INIT(ci, node, BDK_SATAX_UAHC_P0_CI(controller));
    if (ci.u & (1<<slot))
    {
        bdk_error("N%d.SATA%d: Command slot busy before submit\n", node, controller);
        return -1;
    }

    /* Clear all status bits */
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_IS(controller), -1);
    BDK_CSR_READ(node, BDK_SATAX_UAHC_P0_IS(controller));

    /* Issue command */
    BDK_CSR_WRITE(node, BDK_SATAX_UAHC_P0_CI(controller), 1 << slot);

    /* Wait for command accept */
    const int TIMEOUT = 5000000; /* 5 seconds */
    if (BDK_CSR_WAIT_FOR_FIELD(node,BDK_SATAX_UAHC_P0_CI(controller), ci & (1<<slot), ==, 0, TIMEOUT))
    {
        bdk_error("N%d.SATA%d: Command timeout\n", node, controller);
        return -1;
    }

    /* Wait for completion */
    if (BDK_CSR_WAIT_FOR_FIELD(node,BDK_SATAX_UAHC_P0_IS(controller), dhrs | c.s.pss | c.s.dss, !=, 0, TIMEOUT))
    {
        bdk_error("N%d.SATA%d: Response timeout\n", node, controller);
        return -1;
    }

    /* Read status */
    BDK_CSR_INIT(p_is, node, BDK_SATAX_UAHC_P0_IS(controller));
    if (p_is.s.tfes)
    {
        bdk_error("N%d.SATA%d: Task-file error\n", node, controller);
        return -1;
    }
    return 0;
}

/**
 * Identify the SATA device connected to a controller
 *
 * @param node       Node to query
 * @param controller Controller to query
 * @param port       Which SATA port on the controller, zero based
 *
 * @return Size of the disk in bytes
 */
uint64_t bdk_sata_identify(bdk_node_t node, int controller, int port)
{
    if (!__bdk_sata_is_initialized(node, controller))
    {
        if (bdk_sata_initialize(node, controller))
            return -1;
    }

    const int TIMEOUT = 1000000; /* 1 seconds */
    if (BDK_CSR_WAIT_FOR_FIELD(node, BDK_SATAX_UAHC_P0_SSTS(controller), ipm, !=, 0, TIMEOUT))
    {
        bdk_error("N%d.SATA%d: Response timeout\n", node, controller);
        return -1;
    }

    /* Read the Serial ATA Status */
    BDK_CSR_INIT(ssts, node, BDK_SATAX_UAHC_P0_SSTS(controller));

    /* Check the link power state */
    switch (ssts.s.ipm)
    {
        case 0: /* Device not present or communication not established */
            BDK_TRACE(SATA, "N%d.SATA%d: Device not present or communication not established\n", node, controller);
            return 0;
        case 1: /* Interface in active state */
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in active state\n", node, controller);
            break;
        case 2: /* Interface in Partial power management state */
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in Partial power management state\n", node, controller);
            return 0;
        case 6: /* Interface in Slumber power management state */
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in Slumber power management state\n", node, controller);
            return 0;
        case 8: /* Interface in DevSleep power management state */
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in DevSleep power management state\n", node, controller);
            return 0;
        default:
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in unknown power state %d\n", node, controller, ssts.s.ipm);
            return 0;
    }

    /* Check the link speed */
    switch (ssts.s.spd)
    {
        case 0: /* Device not present or communication not established */
            BDK_TRACE(SATA, "N%d.SATA%d: Device not present or communication not established\n", node, controller);
            return 0;
        case 1:
        case 2:
        case 3:
            BDK_TRACE(SATA, "N%d.SATA%d: Speed Gen%d\n", node, controller, ssts.s.spd);
            break;
        default:
            BDK_TRACE(SATA, "N%d.SATA%d: Interface in unknown speed %d\n", node, controller, ssts.s.spd);
            return 0;
    }

    /* Check the device detection */
    switch (ssts.s.det)
    {
        case 0: /* No device detected and Phy communication not established */
            BDK_TRACE(SATA, "N%d.SATA%d: No device detected and Phy communication not established\n", node, controller);
            return 0;
        case 1: /* Device presence detected but Phy communication not established */
            BDK_TRACE(SATA, "N%d.SATA%d: Device presence detected but Phy communication not established\n", node, controller);
            return 0;
        case 3: /* Device presence detected and Phy communication established */
            BDK_TRACE(SATA, "N%d.SATA%d: Device presence detected and Phy communication established\n", node, controller);
            break;
        case 4: /* Phy in offline mode as a result of the interface being disabled or running in a BIST loopback mode */
            BDK_TRACE(SATA, "N%d.SATA%d: Phy in offline mode\n", node, controller);
            return 0;
        default:
            BDK_TRACE(SATA, "N%d.SATA%d: Device presence in unknown state %d\n", node, controller, ssts.s.det);
            return 0;
    }

    /* Read the port signature to identify the device type */
    BDK_CSR_INIT(sig, node, BDK_SATAX_UAHC_P0_SIG(controller));
    switch (sig.s.sig)
    {
        case 0x00000101: /* SATA_SIG_ATA 0x00000101, SATA drive */
            BDK_TRACE(SATA, "N%d.SATA%d: SATA drive\n", node, controller);
            break;
        case 0xEB140101: /* SATA_SIG_ATAPI 0xEB140101, SATAPI drive */
            BDK_TRACE(SATA, "N%d.SATA%d: ATAPI drive, not supported by the BDK\n", node, controller);
            return 0;
        case 0xC33C0101: /* SATA_SIG_SEMB 0xC33C0101, Enclosure management bridge */
            BDK_TRACE(SATA, "N%d.SATA%d: Enclosure management bridge, not supported by the BDK\n", node, controller);
            return 0;
        case 0x96690101: /* SATA_SIG_PM 0x96690101, Port multiplier */
            BDK_TRACE(SATA, "N%d.SATA%d: Port multiplier, not supported by the BDK\n", node, controller);
            return 0;
        default: /* Just assume it is a drive */
            BDK_TRACE(SATA, "N%d.SATA%d: Unknown signature 0x%08x, assuming a SATA drive\n", node, controller, sig.u);
            break;
    }

    /* Send identify to the device */
    const int ATA_CMD_IDENTIFY = 0xec;
    char buffer[512];
    if (issue_command(node, controller, ATA_CMD_IDENTIFY, 0, 0, buffer, sizeof(buffer)))
        return 0;

    /* Extract the data out of the IDENTIFY response */
    uint16_t *ptr = (uint16_t *)buffer;
    uint64_t sectors = ptr[57];
    sectors += (uint32_t)ptr[58] << 16;
    char serial[20  + 1];
    get_ide_string(serial, ptr + 10, 20);
    char firmware[8 + 1];
    get_ide_string(firmware, ptr + 23, 8);
    char model[40 + 1];
    get_ide_string(model, ptr + 27, 40);

    printf("N%d.SATA%d: Model=\"%s\", Firmware=\"%s\", Serial=\"%s\", Sectors=%lu, Link=Gen%d\n",
        node, controller, model, firmware, serial, sectors, ssts.s.spd);

    /* Return size in bytes */
    return sectors * 512;
}

/**
 * Read data from a SATA device
 *
 * @param node       Node the controller is on
 * @param controller Which controller
 * @param port       Which port on the controller, zero based
 * @param lba        48 bit Block address to read
 * @param sectors    Number of 512 bytes sectors to read
 * @param buffer     Buffer to receive the data. Must be at least 512 * sectors in size
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_read(bdk_node_t node, int controller, int port, uint64_t lba, int sectors, void *buffer)
{
    if (!__bdk_sata_is_initialized(node, controller))
    {
        if (bdk_sata_initialize(node, controller))
            return -1;
    }

    const int ATA_READ_DMA = 0xc8;
    if (issue_command(node, controller, ATA_READ_DMA, 0, lba, buffer, sectors * 512))
        return -1;
    return 0;
}

/**
 * Write data to a SATA device
 *
 * @param node       Node the controller is on
 * @param controller Which controller
 * @param port       Which port on the controller, zero based
 * @param lba        48 bit Block address to write
 * @param sectors    Number of 512 bytes sectors to write
 * @param buffer     Data buffer to write. Must be at least 512 * sectors in size
 *
 * @return Zero on success, negative on failure
 */
int bdk_sata_write(bdk_node_t node, int controller, int port, uint64_t lba, int sectors, const void *buffer)
{
    if (!__bdk_sata_is_initialized(node, controller))
    {
        if (bdk_sata_initialize(node, controller))
            return -1;
    }

    const int ATA_WRITE_DMA = 0xca;
    if (issue_command(node, controller, ATA_WRITE_DMA, 1, lba, (void*)buffer, sectors * 512))
        return -1;
    return 0;
}


#include <bdk.h>

/**
 * Return a help string for the given configuration parameter
 *
 * @param cfg_item Configuration parameter to get help for
 *
 * @return Help string for the user
 */
const char* bdk_config_get_help(bdk_config_t cfg_item)
{
    static const char *help[__BDK_CONFIG_END] = {
    /* Board manufacturing data */
    [BDK_CONFIG_BOARD_MODEL] =
            "Board model number. This is used to determine the name of the\n"
            "configuration file containing the boards default settings. This\n"
            "parameter is stored in a static board manufacturing area at the\n"
            "top of the boot flash.",
    [BDK_CONFIG_BOARD_REVISION] =
            "The board revision level. This parameter is stored in a static\n"
            "board manufacturing area at the top of the boot flash.",
    [BDK_CONFIG_BOARD_SERIAL] =
            "Unique string used as a serial number. This parameter is stored\n"
            "in a static board manufacturing area at the top of the boot flash.",
    [BDK_CONFIG_MAC_ADDRESS] =
            "The first MAC address assigned to the THUNDERX network ports. MAC\n"
            "addresses are in a contiguous block starting at this address and\n"
            "containing BOARD-MAC-ADDRESS-NUM number of addresses. The format\n"
            "of this parameter is 0xXXXXXXXXXXXX, 12 hex digits starting with\n"
            "'0x'.This parameter is stored in a static board manufacturing\n"
            "area at the top of the boot flash.",
    [BDK_CONFIG_MAC_ADDRESS_NUM] =
            "The number of MAC addresses assigned to the THUNDERX network\n"
            "ports. See BOARD-MAC-ADDRESS for the actual MAC address numeric\n"
            "value.This parameter is stored in a static board manufacturing\n"
            "area at the top of the boot flash.",
    /* Board generic */
    [BDK_CONFIG_BMC_TWSI] =
            "THUNDERX TWSI port connected to the BMC for IPMI traffic.\n"
            "-1 = No connection exists. 0+ is TWSI bus number.",
    [BDK_CONFIG_WATCHDOG_TIMEOUT] =
            "This specifies a watchdog timer should run during boot and reset\n"
            "the chip if boot hangs for some reason. The timeout is specified\n"
            "in milliseconds. Zero disables the watchdog.",
    [BDK_CONFIG_TWSI_WRITE] =
            "Allow a sequence of TWSI writes to be performed during boot. Each\n"
            "string in the list line is executed in sequence. The TWSI write\n"
            "format is:\n"
            "    node,twsi_id,dev_addr,internal_addr,num_bytes,ia_width_bytes,data\n"
            "    sleep,ms\n"
            "node           = THUNDERX node ID the twsi bus is on. -1 means the local node\n"
            "twsi_id        = THUNDERX twsi bus to use\n"
            "dev_addr       = TWSI bus address\n"
            "internal_addr  = TWSI internal address, zero if not used\n"
            "num_bytes      = Number of bytes to write (1-8)\n"
            "ia_width_bytes = Internal address width in bytes (0-2)\n"
            "data           = Data to write as a 64bit number\n"
            "sleep,ms       = This on a line delays for 'ms' milliseconds",
    [BDK_CONFIG_MDIO_WRITE] =
            "Allow a sequence of MDIO writes to be performed during boot. Each\n"
            "string in the list line is executed in sequence. The MDIO write\n"
            "format is:\n"
            "    clause,node,bus_id,phy_id,device,location,val\n"
            "    sleep,ms\n"
            "clause   = MDIO clause for the write (22 or 45)\n"
            "node     = THUNDERX node the MDIO bus is connected, -1 for local\n"
            "bus_id   = THUNDERX MDIO bus to use\n"
            "phy_id   = MDIO address\n"
            "device   = Clause 45 internal device address, zero for clause 22\n"
            "location = MDIO register\n"
            "val      = Value to write\n"
            "sleep,ms = This on a line delays for 'ms' milliseconds",
    /* Board wiring of network ports and PHYs */
    [BDK_CONFIG_PHY_ADDRESS] =
            "PHY address encoding:\n"
            "    Bits[31:24]: Node ID, 0xff for node the ethernet device is on\n"
            "    Bits[23:16]: Only used for TWSI\n"
            "    Bits[15:12]: PHY connection type (0=MDIO, 1=Fixed, 2=TWSI)\n"
            "For MDIO:\n"
            "    Bits[31:24]: Node ID, 0xff for node the ethernet device is on\n"
            "    Bits[23:16]: 0\n"
            "    Bits[15:12]: 0=MDIO\n"
            "    Bits[11:8]: MDIO bus number\n"
            "    Bits[7:0]: MDIO address\n"
            "For Fixed:\n"
            "    Bits[31:24]: 0\n"
            "    Bits[23:16]: Zero\n"
            "    Bits[15:12]: 1=Fixed\n"
            "    Bits[11:0]:  0 = 1Gb, 1 = 100Mb\n"
            "For TWSI:\n"
            "    Bits[31:24]: Node ID, 0xff for node the ethernet device is on\n"
            "    Bits[23:16]: TWSI internal address width in bytes (0-2)\n"
            "    Bits[15:12]: 2=TWSI\n"
            "    Bits[11:8]: TWSI bus number\n"
            "    Bits[7:0]: TWSI address",
    [BDK_CONFIG_BGX_ENABLE] =
            "Independent enables for each BGX port of THUNDERX. Use this to\n"
            "disable ports that are not wired on a board. Default is that all\n"
            "ports are enabled.",
    /* BDK Configuration params */
    [BDK_CONFIG_NUM_PACKET_BUFFERS] =
            "Number of packet buffers in the BDK.",
    [BDK_CONFIG_PACKET_BUFFER_SIZE] =
            "The size of each packet buffer in the BDK.",
    [BDK_CONFIG_SHOW_LINK_STATUS] =
            "Controls whether the BDK displays link status messages.",
    [BDK_CONFIG_COREMASK] =
            "Controls the cores used by the BDK. Zero means all cores.",
    [BDK_CONFIG_BOOT_MENU_TIMEOUT] =
            "Timeout for the boot menu in seconds.",
    [BDK_CONFIG_BOOT_PATH_OPTION] =
            "This is used by the boot menu to control which boot path the init\n"
            "code chooses. The supported options are\n"
            "    0 = Normal boot path\n"
            "    1 = Diagnostics boot path",
    [BDK_CONFIG_BOOT_NEXT_STAGE] =
            "This is used by the boot apps to determine the next boot stage.\n"
            "    e.g.:\n"
            "      BDK-CONFIG-BOOT-NEXT-STAGE-INIT=/fatfs/cortina-app.bin",
    [BDK_CONFIG_TRACE] =
            "BDK trace level. This is a bitmask of the enumeration defined in\n"
            "bdk-trace.h. Each bit turns on tracing of a specific BDK\n"
            "component.",
    /* Chip feature items */
    [BDK_CONFIG_MULTI_NODE] =
            "Determine how multi-node is supported for this system:\n"
            "    0 = Multi-node is not supported\n"
            "    1 = Multi-node is supported and booting requires two nodes\n"
            "    2 = Multi-node is auto detected. Two nodes are used if\n"
            "        if available, otherwise fall back to single node.",
    [BDK_CONFIG_PCIE_EA] =
            "Determine if internal PCIe ECAMs support Enhanced Allocation(EA):\n"
            "    0 = Enhanced Allocation is not supported\n"
            "    1 = Enhanced Allocation is supported\n"
            "Note EA is not supported on CN88XX pass 1.x, and is always\n"
            "disabled.",
    [BDK_CONFIG_CCPI_LANE_REVERSE] =
            "Force CCPI lane reversal. This should be set for boards which\n"
            "reverse the CCPI lanes between nodes. If lane 0 connects to lane\n"
            "23, this option is needed. CN88XX pass 2.0 and higher automatically\n"
            "detect lane reversal, so setting this is optional.\n"
            "    0 = Automatically detect lane reversal, no lane reversal on\n"
            "        CN88XX pass 1.x.\n"
            "    1 = Force lane reversal, required on CN88XX pass 1.0 with CCPI\n"
            "        lanes reversed.",
    [BDK_CONFIG_CHIP_SKU] =
            "Cavium SKU for the chip. This is determined by early code and\n"
            "passed to later software for display. This should not be set in\n"
            "the input device tree, it will be ignored.",
    /* QLM related config */
    [BDK_CONFIG_QLM_AUTO_CONFIG] =
            "For Cavium evaluation boards, query the MCU for QLM setup\n"
            "information. The MCU supplies a TWSI protocol for THUNDERX to\n"
            "query the modules plugged in and automatically set the QLMs to\n"
            "the correct mode. This should only be enabled(1) on Cavium\n"
            "EBB8XXX boards. Other boards should have it disabled(0).",
    [BDK_CONFIG_QLM_MODE] =
            "Set the mode of a QLM. The possible mode strings are:\n"
            "    DISABLED\n"
            "    PCIE_1X1\n"
            "    PCIE_2X1\n"
            "    PCIE_1X2\n"
            "    PCIE_1X4\n"
            "    PCIE_1X8\n"
            "    SATA_4X1\n"
            "    SATA_2X1\n"
            "    ILK\n"
            "    SGMII_4X1\n"
            "    SGMII_2X1\n"
            "    XAUI_1X4\n"
            "    RXAUI_2X2\n"
            "    RXAUI_1X2\n"
            "    OCI\n"
            "    XFI_4X1\n"
            "    XFI_2X1\n"
            "    XLAUI_1X4\n"
            "    10G_KR_4X1\n"
            "    10G_KR_2X1\n"
            "    40G_KR4_1X4",
    [BDK_CONFIG_QLM_FREQ] =
            "Set the speed of a QLM in Mhz. The possible speeds are:\n"
            "    1250\n"
            "    1500\n"
            "    2500\n"
            "    3000\n"
            "    3125\n"
            "    5000\n"
            "    6000\n"
            "    6250\n"
            "    8000\n"
            "   10312",
    [BDK_CONFIG_QLM_CLK] =
            "Set the source of the QLM reference clock:\n"
            "    0 = Common clock 0\n"
            "    1 = Common clock 1\n"
            "    2 = QLM external reference",
    [BDK_CONFIG_QLM_TUNING_TX_SWING] =
            "Setting of GSERX_LANEX_TX_CFG_0[CFG_TX_SWING] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
    [BDK_CONFIG_QLM_TUNING_TX_PREMPTAP] =
            "Setting of GSERX_LANEX_TX_PRE_EMPHASIS[CFG_TX_PREMPTAP] for the\n"
            "QLM. This should only be used for QLMs used for BGX and CCPI not\n"
            "using KR training. CFG_TX_PREMPTAP:\n"
            "    Bits[8:5] = Tx Post Tap; Bits[3:0] = Tx Pre Tap",
    [BDK_CONFIG_QLM_TUNING_TX_GAIN] =
            "Setting of GSERX_LANEX_TX_CFG_3[PCS_SDS_TX_GAIN] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
    [BDK_CONFIG_QLM_TUNING_TX_VBOOST] =
            "Setting of GSERX_LANEX_TX_CFG_3[CFG_TX_VBOOST_EN] for the QLM. This\n"
            "should only be used for QLMs used for BGX and CCPI not using KR\n"
            "training.",
    /* DRAM configuration options */
    [BDK_CONFIG_DRAM_NODE] =
            "Deprecated: DRAM configuration name to use for the board. This\n"
            "corresponds to a file in lib-dram/configs/config-*.c. Boards should\n"
            "configure DRAM using the board device tree. This is only present\n"
            "for boards that have not been converted to device tree yet. This\n"
            "option will be removed in the future\n"
            "Parameters:\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_SPEED] =
            "Speed grade to use for DRAM in MT/s. Hardware may adjust this value\n"
            "slightly to improve DRAM stability, so scope measurements may not\n"
            "exactly match the frequency with MT/s. The Cavium supported speed\n"
            "grades are:\n"
            "    666 MT/s\n"
            "    800 MT/s\n"
            "    1066 MT/s\n"
            "    1333 MT/s\n"
            "    1600 MT/s\n"
            "    1866 MT/s\n"
            "    2133 MT/s (DDR4 only)\n"
            "Parameters:\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_ALT_REFCLK] =
            "Set to use a an alternate reference clock for DRAM than the usual\n"
            "50Mhz reference. The value of here specifies the frequency of the\n"
            "alternate clock in Mhz. Currently the only supported reference\n"
            "clock frequencies are 50Mhz and 100Mhz.\n"
            "Parameters:\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_SPD_ADDR] =
            "TWSI address of the DIMM SPD. The encoding of this address is\n:"
            "    [15:12]: TWSI bus the DIMM is connected to.\n"
            "     [11:7]: Reserved, set to zero.\n"
            "      [6:0]: TWSI address for the DIMM.\n"
            "A value of zero means the DIMMs are not accessible. Hard coded\n"
            "values will be read from DDR-CONFIG-SPD-DATA."
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_SPD_DATA] =
            "DIMM SPD data to be used if memory doesn't support the standard\n"
            "TWSI access to DIMM SPDs. The format of this is a binary blob\n"
            "stored in the device tree. An example would be:\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_DQX_CTL] =
            "Drive strength control for DDR_DQ* / DDR_DQS_*_P/N drivers.\n"
            "    0x1 = 24 ohm.\n"
            "    0x2 = 26.67 ohm.\n"
            "    0x3 = 30 ohm.\n"
            "    0x4 = 34.3 ohm.\n"
            "    0x5 = 40 ohm.\n"
            "    0x6 = 48 ohm.\n"
            "    0x7 = 60 ohm.\n"
            "    _ else = Reserved.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_WODT_MASK] =
            "LMC Write OnDieTermination Mask Register\n"
            "System designers may desire to terminate DQ/DQS lines for\n"
            "higher-frequency DDR operations, especially on a multirank system.\n"
            "DDR3 DQ/DQS I/Os have built-in termination resistors that can be\n"
            "turned on or off by the controller, after meeting TAOND and TAOF\n"
            "timing requirements. Each rank has its own ODT pin that fans out\n"
            "to all of the memory parts in that DIMM. System designers may\n"
            "prefer different combinations of ODT ONs for write operations into\n"
            "different ranks. CNXXXX supports full programmability by way of\n"
            "the mask register below. Each rank position has its own 8-bit\n"
            "programmable field. When the controller does a write to that rank,\n"
            "it sets the 4 ODT pins to the mask pins below. For example, when\n"
            "doing a write into Rank0, a system designer may desire to terminate\n"
            "the lines with the resistor on DIMM0/Rank1. The mask WODT_D0_R0\n"
            "would then be {00000010}.\n"
            "CNXXXX drives the appropriate mask values on the ODT pins by\n"
            "default. If this feature is not required, write 0x0 in this\n"
            "register. When a given RANK is selected, the WODT mask for that\n"
            "RANK is used.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_PASR] =
            "Partial array self-refresh per rank. LMC writes this value to\n"
            "MR2[PASR] in the rank (i.e. DIMM0_CS0) DDR3 parts when selected\n"
            "during power-up/init, write-leveling, and, if\n"
            "LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit\n"
            "instruction sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and\n"
            "LMC()_CONFIG[RANKMASK] and LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT].\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_ASR] =
            "Auto self-refresh per rank. LMC writes this value to MR2[ASR] in\n"
            "the rank (i.e. DIMM0_CS0) DDR3 parts when selected during\n"
            "power-up/init, write-leveling, and, if LMC()_CONFIG[SREF_WITH_DLL]\n"
            "is set, self-refresh entry and exit instruction sequences. See\n"
            "LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and\n"
            "LMC()_RESET_CTL [DDR3PWARM,DDR3PSOFT].\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_SRT] =
            "Self-refresh temperature range per rank. LMC writes this value to\n"
            "MR2[SRT] in the rank (i.e. DIMM0_CS0) DDR3 parts when selected\n"
            "during power-up/init, write-leveling, and, if\n"
            "LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit\n"
            "instruction sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and\n"
            "LMC()_CONFIG[RANKMASK] and LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT].\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_RTT_WR] =
            "RTT_WR per rank. LMC writes this value to MR2[RTT_WR] in the rank\n"
            "(i.e. DIMM0_CS0) DDR3 parts when selected during power-up/init,\n"
            "write-leveling, and, if LMC()_CONFIG[SREF_WITH_DLL] is set,\n"
            "self-refresh entry and exit instruction sequences. See\n"
            "LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and\n"
            "LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT].\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_DIC] =
            "Output driver impedance control per rank. LMC writes this value\n"
            "to MR1[D.I.C.] in the rank (i.e. DIMM0_CS0) DDR3 parts when \n"
            "selected during power-up/init, write-leveling, and, if\n"
            "LMC()_CONFIG[SREF_WITH_DLL] is set, self-refresh entry and exit\n"
            "instruction sequences. See LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and\n"
            "LMC()_CONFIG[RANKMASK] and LMC()_RESET_CTL[DDR3PWARM,DDR3PSOFT].\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_RTT_NOM] =
            "RTT_NOM per rank. LMC writes this value to MR1[RTT_NOM] in the\n"
            "rank (i.e. DIMM0_CS0) DDR3 parts when selected during\n"
            "power-up/init, write-leveling, and, if LMC()_CONFIG[SREF_WITH_DLL]\n"
            "is set, self-refresh entry and exit instruction sequences. See\n"
            "LMC()_SEQ_CTL[SEQ_SEL,INIT_START] and LMC()_CONFIG[RANKMASK] and\n"
            "LMC()_RESET_CTL[DDR3PWARM, DDR3PSOFT]. Per JEDEC DDR3\n"
            "specifications, if RTT_NOM is used during write operations, only\n"
            "values MR1[RTT_NOM] = 1 (RZQ/4), 2 (RZQ/2), or 3 (RZQ/6) are\n"
            "allowed. Otherwise, values MR1[RTT_NOM] = 4 (RZQ/12) and 5 (RZQ/8)\n"
            "are also allowed.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE1_DB_OUTPUT_IMPEDANCE] =
            "Host Interface DQ/DQS Output Driver Impedance control for DIMM0's\n"
            "Data Buffer. This is the default value used during Host Interface\n"
            "Write Leveling in LRDIMM environment, i.e.,\n"
            "LMC()_CONFIG[LRDIMM_ENA] = 1, LMC()_SEQ_CTL[SEQ_SEL] = 0x6.\n"
            "    0x0 = RZQ/6 (40 ohm).\n"
            "    0x1 = RZQ/7 (34 ohm).\n"
            "    0x2 = RZQ/5 (48 ohm).\n"
            "    0x3-0x7 = Reserved.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE2_RTT_PARK] =
            "RTT park value per rank.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE2_VREF_VALUE] =
            "VREF value per rank.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE2_VREF_RANGE] =
            "VREF range per rank.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    RANK#: Parameter can be different for each rank of a DIMM. This\n"
            "        specifies which rank the value is for. Rank must be\n"
            "        0-3. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_MODE2_VREFDQ_TRAIN_EN] =
            "Vref training mode enable, used for all ranks.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_RODT_CTL] =
            "RODT NCTL impedance control bits. This field controls ODT values\n"
            "during a memory read.\n"
            "    0x0 = No ODT.\n"
            "    0x1 = 20 ohm.\n"
            "    0x2 = 30 ohm.\n"
            "    0x3 = 40 ohm.\n"
            "    0x4 = 60 ohm.\n"
            "    0x5 = 120 ohm.\n"
            "    _ else = Reserved.\n"
            "In DDR4 mode:\n"
            "    0x0 = No ODT.\n"
            "    0x1 = 40 ohm.\n"
            "    0x2 = 60 ohm.\n"
            "    0x3 = 80 ohm.\n"
            "    0x4 = 120 ohm.\n"
            "    0x5 = 240 ohm.\n"
            "    0x6 = 34 ohm.\n"
            "    0x7 = 48 ohm.\n"
            "    _ else = Reserved.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_RANKS_RODT_MASK] =
            "LMC Read OnDieTermination Mask Register\n"
            "System designers may desire to terminate DQ/DQS lines for higher\n"
            "frequency DDR operations, especially on a multirank system. DDR3\n"
            "DQ/DQS I/Os have built-in termination resistors that can be turned\n"
            "on or off by the controller, after meeting TAOND and TAOF timing\n"
            "requirements.\n"
            "Each rank has its own ODT pin that fans out to all the memory\n"
            "parts in that DIMM. System designers may prefer different\n"
            "combinations of ODT ONs for read operations into different ranks.\n"
            "CNXXXX supports full programmability by way of the mask register\n"
            "below. Each rank position has its own 4-bit programmable field.\n"
            "When the controller does a read to that rank, it sets the 4 ODT\n"
            "pins to the MASK pins below. For example, when doing a read from\n"
            "Rank0, a system designer may desire to terminate the lines with\n"
            "the resistor on DIMM0/Rank1. The mask RODT_D0_R0 would then be {0010}.\n"
            "CNXXXX drives the appropriate mask values on the ODT pins by\n"
            "default. If this feature is not required, write 0x0 in this\n"
            "register. Note that, as per the JEDEC DDR3 specifications, the ODT\n"
            "pin for the rank that is being read should always be 0x0. When a\n"
            "given RANK is selected, the RODT mask for that rank is used.\n"
            "Parameters:\n"
            "    RANKS#: Specifies that this parameter only applies to DIMMs\n"
            "        with the supplied number of ranks. Support ranks is 1, 2,\n"
            "        or 4. Optional.\n"
            "    DIMMS#: Specifies that this parameter only applies when the\n"
            "        DIMMs per memory controller matches. Support number of\n"
            "        DIMMs is 1 or 2. Optional.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MIN_RTT_NOM_IDX] =
            "1=120ohms, 2=60ohms, 3=40ohms, 4=30ohms, 5=20ohms\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MAX_RTT_NOM_IDX] =
            "1=120ohms, 2=60ohms, 3=40ohms, 4=30ohms, 5=20ohms\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MIN_RODT_CTL] =
            "1=20ohms, 2=30ohms, 3=40ohms, 4=60ohms, 5=120ohms\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MAX_RODT_CTL] =
            "1=20ohms, 2=30ohms, 3=40ohms, 4=60ohms, 5=120ohms\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_CK_CTL] =
            "Drive strength control for DDR_CK_X_P, DDR_DIMMX_CSX_L,\n"
            "DDR_DIMMX_ODT_X drivers.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_CMD_CTL] =
            "Drive strength control for CMD/A/RESET_L/CKEX drivers.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_CTL_CTL] =
            "Drive strength control for ODT, etc. drivers.\n"
            "In DDR3 mode:\n"
            "    0x1 = 24 ohm.\n"
            "    0x2 = 26.67 ohm.\n"
            "    0x3 = 30 ohm.\n"
            "    0x4 = 34.3 ohm.\n"
            "    0x5 = 40 ohm.\n"
            "    0x6 = 48 ohm.\n"
            "    0x7 = 60 ohm.\n"
            "    else = Reserved.\n"
            "In DDR4 mode:\n"
            "    0x0 = Reserved.\n"
            "    0x1 = Reserved.\n"
            "    0x2 = 26 ohm.\n"
            "    0x3 = 30 ohm.\n"
            "    0x4 = 34 ohm.\n"
            "    0x5 = 40 ohm.\n"
            "    0x6 = 48 ohm.\n"
            "    else = Reserved.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MIN_CAS_LATENCY] =
            "Minimum allowed CAS Latency\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_OFFSET_EN] =
            "When set, LMC attempts to select the read-leveling setting that is\n"
            "LMC()_RLEVEL_CTL[OFFSET] settings earlier than the last passing\n"
            "read-leveling setting in the largest contiguous sequence of\n"
            "passing settings. When clear, or if the setting selected by\n"
            "LMC()_RLEVEL_CTL[OFFSET] did not pass, LMC selects the middle\n"
            "setting in the largest contiguous sequence of passing settings,\n"
            "rounding earlier when necessary.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_OFFSET] =
            "The offset used when LMC()_RLEVEL_CTL[OFFSET] is set.\n"
            "Parameters:\n"
            "   %s: This setting can by specified by DRAM type (UDIMM or RDIMM)\n"
            "       Different settings can be used for each, or the type can be\n"
            "       omitted to use the same setting for both.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMPUTE] =
            "Enables software interpretation of per-byte read delays using the\n"
            "measurements collected by the chip rather than completely relying\n"
            "on the automatically to determine the delays. 1=software\n"
            "computation is recommended since a more complete analysis is\n"
            "implemented in software.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DDR_RTT_NOM_AUTO] =
            "1 means automatically set RTT_NOM value.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DDR_RODT_CTL_AUTO] =
            "1 means automatically set RODT_CTL value.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_COMP_OFFSET] =
            "Set to 2 unless instructed differently by Cavium.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_RLEVEL_AVERAGE_LOOPS] =
            "Determines the number of times the read-leveling sequence is run\n"
            "for each rank. The results is then averaged across the number of\n"
            "loops. The default setting is 1.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DDR2T] =
            "Turn on the DDR 2T mode. 2-cycle window for CMD and address. This\n"
            "mode helps relieve setup time pressure on the address and command\n"
            "bus. Please refer to Micron's tech note tn_47_01 titled DDR2-533\n"
            "Memory Design Guide for Two DIMM Unbuffered Systems for physical\n"
            "details.\n"
            "Parameters:\n"
            "   %s: This setting can by specified by DRAM type (UDIMM or RDIMM)\n"
            "       Different settings can be used for each, or the type can be\n"
            "       omitted to use the same setting for both.\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DISABLE_SEQUENTIAL_DELAY_CHECK] =
            "As result of the flyby topology prescribed in the JEDEC\n"
            "specifications the byte delays should maintain a consistent\n"
            "increasing or decreasing trend across the bytes on standard DIMMs.\n"
            "This setting can be used disable that check for unusual\n"
            "circumstances where the check is not useful.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MAXIMUM_ADJACENT_RLEVEL_DELAY_INCREMENT] =
            "An additional sequential delay check for the delays that result\n"
            "from the flyby topology. This value specifies the maximum\n"
            "difference between the delays of adjacent bytes.  A value of 0\n"
            "disables this check.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_PARITY] =
            "The parity input signal PAR_IN on each DIMM must be strapped high\n"
            "or low on the board.  This bit is programmed into\n"
            "LMC0_DIMM_CTL[PARITY] and it must be set to match the board\n"
            "strapping.  This signal is typically strapped low.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_FPRCH2] =
            "Front Porch Enable: When set, the turn-off time for the default\n"
            "DDR_DQ/DQS drivers is FPRCH2 CKs earlier.\n"
            "    0 = 0 CKs\n"
            "    1 = 1 CKs\n"
            "    2 = 2 CKs\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MODE32B] =
            "Enable 32-bit datapath mode. Set to 1 if only 32 DQ pins are\n"
            "used.\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_MEASURED_VREF] =
            "Use Measured VREF\n"
            "Parameters:\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DLL_WRITE_OFFSET] =
            "Supply a custom DLL write offset\n"
            "Parameters:\n"
            "    BYTE#: Byte lane to apply the parameter to (0-8).\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    [BDK_CONFIG_DDR_CUSTOM_DLL_READ_OFFSET] =
            "Supply a custom DLL read offset\n"
            "Parameters:\n"
            "    BYTE#: Byte lane to apply the parameter to (0-8).\n"
            "    LMC#: Parameter can be different for memory controller. This\n"
            "        specifies which LMC the value is for. LMC must be\n"
            "        0-3. Optional.\n"
            "    N#: Parameter can be different for each node. This specifies\n"
            "        which node the value is for. Node must be 0-3. Optional.",
    /* High level DRAM options */
    [BDK_CONFIG_DRAM_VERBOSE] =
            "Choose the debug logging level used during DRAM initialization.\n"
            "Zero disables debug logging. The possible debug levels are:\n"
            "    0: Off, no logging\n"
            "    1: Logging of DRAM initialization at a normal detail level\n"
            "    2: Logging of DRAM initialization at FAE detail level\n"
            "    3: Logging of DRAM initialization at TME detail level\n"
            "    4: Logging of DRAM initialization at DEV detail level\n"
            "    5: Logging of DRAM initialization at DEV2 detail level\n"
            "    6: Logging of DRAM initialization at DEV3 detail level\n"
            "    7: Logging of DRAM initialization at DEV4 detail level\n"
            "Add in the following for special trace features.\n"
            "   16: Trace specialized DRAM controller sequences.\n"
            "   32: Trace every DRAM controller register write.",
    [BDK_CONFIG_DRAM_BOOT_TEST] =
            "Run a short DRAM test after DRAM is initialized as quick check\n"
            "for functionality. This is normally not needed required. Boards\n"
            "with poor DRAM power supplies may use this to detect failures\n"
            "during boot. This should be used in combination with the watchdog\n"
            "timer.",
    [BDK_CONFIG_DRAM_CONFIG_GPIO] =
            "The DRAM initialization code has the ability to toggle a GPIO to\n"
            "signal when it is running. Boards may need to mux TWSI access\n"
            "between a BMC and THUNDERX so the BMC can monitor DIMM temperatures\n"
            "and health. This GPIO will be driven high when THUNDERX may read\n"
            "from the SPDs on the DIMMs. When driven low, another device (BMC)\n"
            "may takeover the TWSI connections to the DIMMS. The default value\n"
            "(-1) disables this feature.",
    /* USB */
    [BDK_CONFIG_USB_PWR_GPIO] =
            "Specify a THUNDERX GPIO used to control power for a USB port. When\n"
            "set, the USB host controller will toggle the GPIO automatically\n"
            "during USB reset events. The default value assumes THUNDERX has no\n"
            "control of the USB power and it is always on.",
    [BDK_CONFIG_USB_PWR_GPIO_POLARITY] =
            "Specify the polarity of a THUNDERX GPIO used to control power for\n"
            "a USB port. The GPIO used is specified by USB-PWR-GPIO. Setting this\n"
            "GPIO low. The default value drives the GPIO high.",
    /* How EYE diagrams are captured from a QLM */
    [BDK_CONFIG_EYE_ZEROS] =
            "Number of reading with no errors to signal the start of an\n"
            "eye. The default value should be good for most cases.",
    [BDK_CONFIG_EYE_SAMPLE_TIME] =
            "Time to sample at each location in microseconds. The default\n"
            "value should be good for most cases.",
    [BDK_CONFIG_EYE_SETTLE_TIME] =
            "Time to settle after each movement in microseconds. The\n"
            "default value should be good for most cases.",
    /* SGPIO configuration */
    [BDK_CONFIG_SGPIO_SCLOCK_FREQ] =
            "Reference clock in Hz. CN88XX drives data on rising edges of this\n"
            "clock, and the target latches data on the falling edges of this\n"
            "clock. On reset CN88XX tristates SGPIO_SCLK. When not exchanging\n"
            "a bit stream CN88XX keeps SGPIO_SCLK low.\n"
            "  Min: 128 Hz\n"
            "  Max: 100 kHz",
    [BDK_CONFIG_SGPIO_PIN_POWER] =
            "Output pin number for SGPIO controller power control.",
    [BDK_CONFIG_SGPIO_PIN_SCLOCK] =
            "Output pin number for SGPIO SCLOCK signal.",
    [BDK_CONFIG_SGPIO_PIN_SLOAD] =
            "Output pin number for SGPIO SLOAD signal.",
    [BDK_CONFIG_SGPIO_PIN_SDATAOUT] =
            "Output pin number for SGPIO SDATAOUT[n] signal. n = 0..3.",
    };
    return help[cfg_item];
}


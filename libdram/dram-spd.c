#include <bdk.h>
#include "dram-internal.h"


/* Read an DIMM SPD value, either using TWSI to read it from the DIMM, or
 * from a provided array.
 */
int read_spd(bdk_node_t node, const dimm_config_t *dimm_config, int dimm_index, int spd_field)
{
    dimm_index = !!dimm_index;
    /* If pointer to data is provided, use it, otherwise read from SPD over twsi */
    if (dimm_config->spd_ptrs[dimm_index])
        return dimm_config->spd_ptrs[dimm_index][spd_field];
    else if (dimm_config->spd_addrs[dimm_index])
    {
        int bus = dimm_config->spd_addrs[dimm_index] >> 12;
        int address = dimm_config->spd_addrs[dimm_index] & 0x7f;

	/* this should only happen for DDR4, which has a second bank of 256 bytes */
	static int bank = 0; /* 0 = bank 0 (RESET), 1 = bank 1 */
	int new_bank = (spd_field >> 8) & 1;
	if (bank != new_bank) {
	    bdk_twsix_write_ia(node, bus, 0x36 | new_bank, 0, 2, 1, 0);
	    bank = new_bank;
	    spd_field %= 256;
	}

        return bdk_twsix_read_ia(node, bus, address, spd_field, 1, 1);
    }
    else
        return -1;
}

static uint16_t ddr3_crc16(uint8_t *ptr, int count)
{
    /* From DDR3 spd specification */
    int crc, i;
    crc = 0;
    while (--count >= 0)
    {
        crc = crc ^ (int)*ptr++ << 8;
        for (i = 0; i < 8; ++i)
            if (crc & 0x8000)
                crc = crc << 1 ^ 0x1021;
            else
                crc = crc << 1;
    }
    return crc & 0xFFFF;
}

static int validate_spd_checksum_ddr3(bdk_node_t node, int twsi_addr, int silent)
{
    uint8_t spd_data[128];
    int crc_bytes = 126;
    uint16_t crc_comp;
    int i;
    int rv;
    for (i = 0; i < 128; i++)
    {
        rv = bdk_twsix_read_ia(node, twsi_addr >> 12, twsi_addr & 0x7f, i, 1, 1);
        if (rv < 0)
            return 0;   /* TWSI read error */
        spd_data[i] = (uint8_t)rv;
    }
    /* Check byte 0 to see how many bytes checksum is over */
    if (spd_data[0] & 0x80)
        crc_bytes = 117;

    crc_comp = ddr3_crc16(spd_data, crc_bytes);

    if (spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE] == (crc_comp & 0xff) &&
        spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE] == (crc_comp >> 8))
    {
        return 1;
    }
    else
    {
        if (!silent)
            printf("DDR3 SPD CRC error, spd addr: 0x%x, calculated crc: 0x%04x, read crc: 0x%02x%02x\n",
		   twsi_addr, crc_comp,
		   spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE],
		   spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE]);
        return 0;
    }
}

static int validate_spd_checksum(bdk_node_t node, int twsi_addr, int silent)
{
    int rv;

    debug_print("Validating DIMM at address 0x%x\n", twsi_addr);

#ifdef DDR3_ENHANCE_PRINT
    if (!twsi_addr) return 1; /* return OK if we are not doing real DIMMs */
#endif

    /* Look up module type to determine if DDR3 or DDR4 */
    rv = bdk_twsix_read_ia(node, twsi_addr >> 12, twsi_addr & 0x7f, 2, 1, 1);
    if (rv < 0)
        return 0;   /* TWSI read error */
    if (rv >= 0x8 && rv <= 0xA)
        printf("%s: Error: DDR2 support disabled\n", __func__);
    if (rv >= 0xB && rv <= 0xB) /* this is DDR3 */
        return validate_spd_checksum_ddr3(node, twsi_addr, silent);
    if (rv >= 0xC && rv <= 0xC) /* this is DDR4, do like DDR3 */
	return validate_spd_checksum_ddr3(node, twsi_addr, silent);
     if (!silent)
        printf("Unrecognized DIMM type: 0x%x at spd address: 0x%x\n",
            rv, twsi_addr);
    return 0;
}


int validate_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int dimm_index)
{
    int spd_addr;
    dimm_index = !!dimm_index;  /* Normalize to 0/1 */
    spd_addr = dimm_config->spd_addrs[dimm_index];

#ifdef DDR3_ENHANCE_PRINT
    debug_print("Validating dimm %d, spd addr: 0x%02x spd ptr: %x\n",
		dimm_index, spd_addr, dimm_config->spd_ptrs[dimm_index]);
#else
    debug_print("Validating dimm %d, spd ptr: %p\n", dimm_index,
	       dimm_config->spd_ptrs[dimm_index]);
#endif

#ifndef DDR3_ENHANCE_PRINT
    /* Only validate 'real' dimms, assume compiled in values are OK */
    if (!dimm_config->spd_ptrs[dimm_index])
#endif
    {
        int val0, val1;
        int dimm_type = read_spd(node, dimm_config, dimm_index,
				 DDR3_SPD_KEY_BYTE_DEVICE_TYPE) & 0xff;
        switch (dimm_type)
        {
            case 0x0B:              /* DDR3 */
#ifdef DDR3_ENHANCE_PRINT
                debug_print("Validating DDR3 DIMM %d\n", dimm_index);
#else
                debug_print("Validating DIMM %d\n", dimm_index);
#endif
                val0 = read_spd(node, dimm_config, dimm_index, DDR3_SPD_DENSITY_BANKS);
                val1 = read_spd(node, dimm_config, dimm_index, DDR3_SPD_ADDRESSING_ROW_COL_BITS);
                if (val0 < 0 && val1 < 0)
                {
                    ddr_print("Error reading SPD for DIMM %d\n", dimm_index);
                    return 0; /* Failed to read dimm */
                }
                if (val0 == 0xff && val1 == 0xff)
                {
                    ddr_print("Blank or unreadable SPD for DIMM %d\n", dimm_index);
                    return 0; /* Blank SPD or otherwise unreadable device */
                }

                /* Don't treat bad checksums as fatal. */
                validate_spd_checksum(node, spd_addr, 0);
                break;
	    case 0x0C:              /* DDR4 */
		ddr_print("Validating DDR4 DIMM %d\n", dimm_index);
		val0 = read_spd(node, dimm_config, dimm_index, DDR4_SPD_DENSITY_BANKS);
		val1 = read_spd(node, dimm_config, dimm_index, DDR4_SPD_ADDRESSING_ROW_COL_BITS);
		if (val0 < 0 && val1 < 0) {
		    ddr_print("Error reading SPD for DIMM %d\n", dimm_index);
		    return 0; /* Failed to read dimm */
		}
		if (val0 == 0xff && val1 == 0xff) {
		    ddr_print("Blank or unreadable SPD for DIMM %d\n", dimm_index);
		    return 0; /* Blank SPD or otherwise unreadable device */
		}

		/* Don't treat bad checksums as fatal. */
		validate_spd_checksum(node, spd_addr, 0);
		break;
            default:
#ifdef DDR3_ENHANCE_PRINT
		debug_print("Unknown DIMM type 0x%x for DIMM %d @ 0x%x\n",
			     dimm_type, dimm_index,
			     dimm_config->spd_addrs[dimm_index]);
#else
		debug_print("Unknown DIMM type 0x%x for DIMM %d @ 0x%x\n",
			  dimm_type, dimm_index,
			  dimm_config->spd_addrs[dimm_index]);
#endif
                return 0;      /* Failed to read dimm */
        }
    }

    return 1;
}

static
void report_ddr3_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm, int dimm)
{
    int spd_ecc;
    unsigned spd_module_type;
    int i;
    int strlen;
    uint32_t serial_number;
    int spd_voltage;
    static const char *dimm_types[] = {
        /* 0000	*/ "Undefined",
        /* 0001	*/ "RDIMM",
        /* 0010	*/ "UDIMM",
        /* 0011	*/ "SO-DIMM",
        /* 0100	*/ "Micro-DIMM",
        /* 0101	*/ "Mini-RDIMM",
        /* 0110	*/ "Mini-UDIMM",
        /* 0111	*/ "Mini-CDIMM",
        /* 1000	*/ "72b-SO-UDIMM",
        /* 1001	*/ "72b-SO-RDIMM",
        /* 1010	*/ "72b-SO-CDIMM"
    };
    char part_number[19] = { 0 }; /* 18 bytes plus string terminator */

    upper_dimm = !!upper_dimm;  /* Normalize to 0/1 */

    spd_module_type = read_spd(node, dimm_config, upper_dimm,
        DDR3_SPD_KEY_BYTE_MODULE_TYPE);

    /* Validate dimm type */
    spd_module_type = (spd_module_type >= (sizeof(dimm_types) / sizeof(char *)))
        ? 0 : spd_module_type;

    spd_ecc = !!(read_spd(node, dimm_config, upper_dimm, DDR3_SPD_MEMORY_BUS_WIDTH) & 8);

    printf("DIMM %d: DDR3 %s, %s", dimm,
        dimm_types[spd_module_type], (spd_ecc ? "ECC" : "non-ECC"));

    strlen = 0;
    for (i = 0; i < 18; ++i)
    {
        part_number[i] = (read_spd(node, dimm_config, upper_dimm, i + 128) & 0xff);
        if (part_number[i])
            ++strlen;
        /* debug_print("spd[%d]: 0x%02x\n", i+128, part_number[i]); */
    }
    if (strlen)
        printf("  %s", part_number);

    serial_number = 0;
    for (i = 0; i < 4; ++i)
    {
        serial_number |= ((read_spd(node, dimm_config, upper_dimm, 122 + i) & 0xff) << ((3 - i) * 8));
    }
    if ((serial_number != 0) && (serial_number != 0xffffffff))
    {
        printf("  s/n %u", serial_number);
    }
    else
    {
        unsigned spd_chksum;
        spd_chksum  =   0xff & read_spd(node, dimm_config, upper_dimm,
            DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE);
        spd_chksum |= ((0xff & read_spd(node, dimm_config, upper_dimm,
                    DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE)) << 8);
        printf("  chksum: %u (0x%04x)", spd_chksum, spd_chksum);
    }

    spd_voltage = read_spd(node, dimm_config, upper_dimm, DDR3_SPD_NOMINAL_VOLTAGE);
    if ((spd_voltage == 0) || (spd_voltage & 3))
        printf(" 1.5V");
    if (spd_voltage & 2)
        printf(" 1.35V");
    if (spd_voltage & 4)
        printf(" 1.2xV");

    printf("\n");
}

static void report_ddr4_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm,
			     int dimm)
{
    int spd_ecc;
    unsigned spd_module_type;
    int i;
    int strlen;
    uint32_t serial_number;
    int spd_voltage;
    static const char *dimm_types[] = {
	/* 0000 */ "Undefined",
	/* 0001 */ "RDIMM",
	/* 0010 */ "UDIMM",
	/* 0011 */ "SO-DIMM",
	/* 0100 */ "LRDIMM",
	/* 0101 */ "Mini-RDIMM",
	/* 0110 */ "Mini-UDIMM",
	/* 0111 */ "Reserved",
	/* 1000 */ "72b-SO-RDIMM",
	/* 1001 */ "72b-SO-UDIMM",
	/* 1011 */ "Reserved",
	/* 1100 */ "16b-SO-DIMM",
	/* 1101 */ "32b-SO-DIMM",
	/* 1110 */ "Reserved",
	/* 1111 */ "Undefined"
    };

    char part_number[20] = {0}; /* 18 bytes plus string terminator */

    upper_dimm = !!upper_dimm;  /* Normalize to 0/1 */

    spd_module_type = read_spd(node, dimm_config, upper_dimm,
			       DDR4_SPD_KEY_BYTE_MODULE_TYPE);

    /* Validate dimm type */
    spd_module_type = (spd_module_type > (sizeof(dimm_types)/sizeof(char*)))
	? 0 : spd_module_type;

    spd_ecc = !!(read_spd(node, dimm_config, upper_dimm, DDR4_SPD_MODULE_MEMORY_BUS_WIDTH) & 8);

    printf("DIMM %d: DDR4 %s, %s", dimm,
	   dimm_types[spd_module_type], (spd_ecc ? "ECC" : "non-ECC"));

    strlen = 0;
    for (i = 0; i < 19; ++i) {
	part_number[i] = (read_spd(node, dimm_config, upper_dimm,
				   DDR4_SPD_MODULE_PART_NUMBER+i) & 0xff);
	if (part_number[i])
	    ++strlen;
	/* debug_print("spd[%d]: 0x%02x\n", DDR4_SPD_MODULE_PART_NUMBER+i, part_number[i]); */
    }
    if (strlen)
	printf("  %s", part_number);

    serial_number = 0;
    for (i = 0 ; i < 4; ++i) {
	serial_number |= ((read_spd(node, dimm_config, upper_dimm,
				    DDR4_SPD_MODULE_SERIAL_NUMBER+i) & 0xff) << ((3-i)*8));
    }
    if ((serial_number!=0) && (serial_number!=0xffffffff)) {
	printf("  s/n %u", serial_number);
    } else {
	unsigned spd_chksum;
	spd_chksum  =   0xff & read_spd(node, dimm_config, upper_dimm,
					DDR4_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE);
	spd_chksum |= ((0xff & read_spd(node, dimm_config, upper_dimm,
					DDR4_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE)) << 8);
	printf("  chksum: %u (0x%04x)", spd_chksum, spd_chksum);
    }

    spd_voltage = read_spd(node, dimm_config, upper_dimm, DDR4_SPD_MODULE_NOMINAL_VOLTAGE);
    if ((spd_voltage == 0x01) || (spd_voltage & 0x02))
	printf(" 1.2V");
    if ((spd_voltage == 0x04) || (spd_voltage & 0x08))
	printf(" TBD1 V");
    if ((spd_voltage == 0x10) || (spd_voltage & 0x20))
	printf(" TBD2 V");

    printf("\n");
}

void report_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm,
			     int dimm)
{
        int spd_ddr_type;
        int ddr_type;
	upper_dimm = !!upper_dimm;  /* Normalize to 0/1 */
        spd_ddr_type = read_spd(node, dimm_config, upper_dimm, DDR4_SPD_KEY_BYTE_DEVICE_TYPE);

        debug_print("%s:%d spd_ddr_type=0x%02x\n", __FUNCTION__, __LINE__, spd_ddr_type);

        /* ddr_type only indicates DDR4 or DDR3 */
        ddr_type = (spd_ddr_type == 0x0C) ? 4 : 3;

        if (ddr_type == 4)
	    report_ddr4_dimm(node, dimm_config, 0, dimm);
        else
	    report_ddr3_dimm(node, dimm_config, 0, dimm);
}


#include <bdk.h>
#include "dram-internal.h"


/* Read an DIMM SPD value, either using TWSI to read it from the DIMM, or
 * from a provided array.
 */
int read_spd(const dimm_config_t *dimm_config, int dimm_index, int spd_field)
{
        bdk_node_t node = bdk_numa_local();
	dimm_index = !!dimm_index;
	/* If pointer to data is provided, use it, otherwise read from SPD over twsi */
	if (dimm_config->spd_ptrs[dimm_index]) {
		return dimm_config->spd_ptrs[dimm_index][spd_field];
	} else if (dimm_config->spd_addrs[dimm_index]) {
            int bus = dimm_config->spd_addrs[dimm_index] >> 8;
            int address = dimm_config->spd_addrs[dimm_index] & 0x7f;
            return bdk_twsix_read_ia(node, bus, address, spd_field, 1, 1);
	} else {
	        return -1;
	}
}

static uint16_t ddr3_crc16(uint8_t *ptr, int count)
{
	/* From DDR3 spd specification */
	int crc, i;
	crc = 0;
	while (--count >= 0) {
		crc = crc ^ (int)*ptr++ << 8;
		for (i = 0; i < 8; ++i)
			if (crc & 0x8000)
				crc = crc << 1 ^ 0x1021;
			else
				crc = crc << 1;
	}
	return (crc & 0xFFFF);
}

static int validate_spd_checksum_ddr3(int twsi_addr, int silent)
{
        bdk_node_t node = bdk_numa_local();
	uint8_t spd_data[128];
	int crc_bytes = 126;
	uint16_t crc_comp;
	int i;
	int rv;
	for (i = 0; i < 128; i++) {
                rv = bdk_twsix_read_ia(node, twsi_addr >> 8, twsi_addr & 0x7f, i, 1, 1);
		if (rv < 0)
			return 0;   /* TWSI read error */
		spd_data[i]  = (uint8_t)rv;
	}
	/* Check byte 0 to see how many bytes checksum is over */
	if (spd_data[0] & 0x80)
		crc_bytes = 117;

	crc_comp = ddr3_crc16(spd_data, crc_bytes);

	if (spd_data[126] == (crc_comp & 0xff) &&
	    spd_data[127] == (crc_comp >> 8)) {
		return 1;
	} else {
		if (!silent)
			printf("DDR3 SPD CRC error, spd addr: 0x%x, calculated crc: 0x%04x, read crc: 0x%02x%02x\n",
			       twsi_addr, crc_comp, spd_data[126], spd_data[127]);
		return 0;
	}
}

static int validate_spd_checksum(int twsi_addr, int silent)
{
        bdk_node_t node = bdk_numa_local();
	int rv;

	if (dram_is_verbose())
		printf("Validating DIMM at address 0x%x\n", twsi_addr);

	/* Look up module type to determine if DDR2 or DDR3 */
        rv = bdk_twsix_read_ia(node, twsi_addr >> 8, twsi_addr & 0x7f, 2, 1, 1);
	if (rv < 0)
		return 0;   /* TWSI read error */
	if (rv >= 0x8 && rv <= 0xA)
            printf("%s: Error: DDR2 support disabled\n", __func__);
	if (rv >= 0xB && rv <= 0xB)
		return validate_spd_checksum_ddr3(twsi_addr, silent);
	if (!silent)
		printf("Unrecognized DIMM type: 0x%x at spd address: 0x%x\n",
		       rv, twsi_addr);
	return 0;
}


int validate_dimm(const dimm_config_t *dimm_config, int dimm_index)
{
        int spd_addr;
	dimm_index = !!dimm_index;  /* Normalize to 0/1 */
	spd_addr = dimm_config->spd_addrs[dimm_index];

	if (dram_is_verbose())
		printf("Validating dimm %d, spd ptr: 0x%p\n",
                       dimm_index,
		       dimm_config->spd_ptrs[dimm_index]);
	/* Only validate 'real' dimms, assume compiled in values are OK */
	if (!dimm_config->spd_ptrs[dimm_index]) {
		int val0, val1;
		int dimm_type = read_spd(dimm_config, dimm_index,
					 DDR2_SPD_MEM_TYPE) & 0xff;
		switch (dimm_type) {
		case 0x0B:              /* DDR3 */
			if (dram_is_verbose())
				printf("Validating DIMM %d\n", dimm_index);
			val0 = read_spd(dimm_config, dimm_index,
					DDR3_SPD_DENSITY_BANKS);
			val1 = read_spd(dimm_config, dimm_index,
					DDR3_SPD_ADDRESSING_ROW_COL_BITS);
			if (val0 < 0 && val1 < 0) {
				if (dram_is_verbose())
					printf("Error reading SPD for DIMM %d\n",
					       dimm_index);
				return 0; /* Failed to read dimm */
			}
			if (val0 == 0xff && val1 == 0xff) {
				if (dram_is_verbose())
					printf("Blank or unreadable SPD for DIMM %d\n",
					       dimm_index);
				return 0; /* Blank SPD or otherwise unreadable device */
			}

			/* Don't treat bad checksums as fatal. */
			validate_spd_checksum(spd_addr, 0);
		break;
		default:
			if (dram_is_verbose())
				printf("Unknown DIMM type 0x%x for DIMM %d @ 0x%x\n",
				       dimm_type, dimm_index,
				       dimm_config->spd_addrs[dimm_index]);
			return 0;      /* Failed to read dimm */
		}
	}

	return 1;
}

void report_ddr3_dimm(const dimm_config_t *dimm_config, int upper_dimm,
			     int dimm)
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
	char part_number[19] = {0}; /* 18 bytes plus string terminator */

	upper_dimm = !!upper_dimm;  /* Normalize to 0/1 */

	spd_module_type = read_spd(dimm_config, upper_dimm,
				   DDR3_SPD_KEY_BYTE_MODULE_TYPE);

	/* Validate dimm type */
	spd_module_type = (spd_module_type >= (sizeof(dimm_types)/sizeof(char*)))
				? 0 : spd_module_type;

	spd_ecc = !!(read_spd(dimm_config, upper_dimm, DDR3_SPD_MEMORY_BUS_WIDTH) & 8);

	printf("DIMM %d: DDR3 %s, %s", dimm,
	       dimm_types[spd_module_type], (spd_ecc ? "ECC" : "non-ECC"));

	strlen = 0;
	for (i = 0; i < 18; ++i) {
		part_number[i] = (read_spd(dimm_config, upper_dimm, i+128) & 0xff);
		if (part_number[i])
			++strlen;
		/* debug_print("spd[%d]: 0x%02x\n", i+128, part_number[i]); */
	}
	if (strlen)
		printf("  %s", part_number);

	serial_number = 0;
	for (i = 0 ; i < 4; ++i) {
		serial_number |= ((read_spd(dimm_config, upper_dimm, 122+i) & 0xff) << ((3-i)*8));
	}
	if ((serial_number!=0) && (serial_number!=0xffffffff)) {
		printf("  s/n %u", serial_number);
	} else {
		unsigned spd_chksum;
		spd_chksum  =   0xff & read_spd(dimm_config, upper_dimm,
						DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE);
		spd_chksum |= ((0xff & read_spd(dimm_config, upper_dimm,
						DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE)) << 8);
		printf("  chksum: %u (0x%04x)", spd_chksum, spd_chksum);
	}

	spd_voltage = read_spd(dimm_config, upper_dimm, DDR3_SPD_NOMINAL_VOLTAGE);
	if ((spd_voltage == 0) || (spd_voltage & 3))
		puts(" 1.5V");
	if (spd_voltage & 2)
		puts(" 1.35V");
	if (spd_voltage & 4)
		puts(" 1.2xV");

	puts("\n");
}


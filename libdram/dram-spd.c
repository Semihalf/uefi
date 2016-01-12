#include <bdk.h>
#include <ctype.h>
#include "dram-internal.h"

/**
 * Read the entire contents of a DIMM SPD and store it in the device tree. The
 * current DRAM config is also updated, so future SPD accesses used the cached
 * copy.
 *
 * @param node   Node the DRAM config is for
 * @param cfg    Current DRAM config. Updated with SPD data
 * @param lmc    LMC to read DIMM for
 * @param dimm   DIMM slot for SPD to read
 *
 * @return Zero on success, negative on failure
 */
int read_entire_spd(bdk_node_t node, dram_config_t *cfg, int lmc, int dimm)
{
    /* If pointer to data is provided, use it, otherwise read from SPD over twsi */
    if (cfg->config[lmc].dimm_config_table[dimm].spd_ptrs[0])
        return 0;
    if (!cfg->config[lmc].dimm_config_table[dimm].spd_addrs[0])
        return -1;

    /* Figure out how to access the SPD */
    int spd_addr = cfg->config[lmc].dimm_config_table[dimm].spd_addrs[0];
    int bus = spd_addr >> 12;
    int address = spd_addr & 0x7f;

    /* Figure out the size we will read */
    int64_t dev_type = bdk_twsix_read_ia(node, bus, address, DDR4_SPD_KEY_BYTE_DEVICE_TYPE, 1, 1);
    if (dev_type < 0)
        return -1; /* No DIMM */
    int spd_size = (dev_type == 0x0c) ? 512 : 256;

    /* Allocate storage */
    uint32_t *spd_buf = malloc(spd_size);
    if (!spd_buf)
        return -1;
    uint32_t *ptr = spd_buf;

    for (int bank = 0; bank < (spd_size >> 8); bank++)
    {
        /* this should only happen for DDR4, which has a second bank of 256 bytes */
        if (bank)
            bdk_twsix_write_ia(node, bus, 0x36 | bank, 0, 2, 1, 0);
        int bank_size = 256;
        for (int i = 0; i < bank_size; i += 4)
        {
            int64_t data = bdk_twsix_read_ia(node, bus, address, i, 4, 1);
            if (data < 0)
            {
                bdk_error("Failed to read SPD data at 0x%x\n", i + (bank << 8));
                /* Restore the bank to zero */
                if (bank)
                    bdk_twsix_write_ia(node, bus, 0x36 | 0, 0, 2, 1, 0);
                return -1;
            }
            else
                *ptr++ = bdk_be32_to_cpu(data);
        }
        /* Restore the bank to zero */
        if (bank)
            bdk_twsix_write_ia(node, bus, 0x36 | 0, 0, 2, 1, 0);
    }

    /* Store the SPD in the device tree */
    bdk_config_set_blob(spd_size, spd_buf, BDK_CONFIG_DDR_SPD_DATA, dimm, lmc, node);
    cfg->config[lmc].dimm_config_table[dimm].spd_ptrs[0] = (void*)spd_buf;

    return 0;
}

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
        int data;
        int bus = dimm_config->spd_addrs[dimm_index] >> 12;
        int address = dimm_config->spd_addrs[dimm_index] & 0x7f;

	/* this should only happen for DDR4, which has a second bank of 256 bytes */
	int bank = (spd_field >> 8) & 1;
	if (bank) {
	    bdk_twsix_write_ia(node, bus, 0x36 | bank, 0, 2, 1, 0);
	    spd_field %= 256;
	}

        data = bdk_twsix_read_ia(node, bus, address, spd_field, 1, 1);

        /* Restore the bank to zero */
        if (bank) {
            bdk_twsix_write_ia(node, bus, 0x36 | 0, 0, 2, 1, 0);
        }
        
        return data;
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
    int ret = 1;
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

    if (spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE] != (crc_comp & 0xff) ||
        spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE] != (crc_comp >> 8))
    {
        if (!silent) {
            printf("DDR3 SPD CRC error, spd addr: 0x%x, calculated crc: 0x%04x, read crc: 0x%02x%02x\n",
		   twsi_addr, crc_comp,
		   spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE],
		   spd_data[DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE]);
	}
        ret = 0;
    }
    return ret;
}

static int validate_spd_checksum(bdk_node_t node, int twsi_addr, int silent)
{
    int rv;

    debug_print("Validating DIMM at address 0x%x\n", twsi_addr);

    if (!twsi_addr) return 1; /* return OK if we are not doing real DIMMs */

    /* Look up module type to determine if DDR3 or DDR4 */
    rv = bdk_twsix_read_ia(node, twsi_addr >> 12, twsi_addr & 0x7f, 2, 1, 1);

    if (rv >= 0xB && rv <= 0xC) /* this is DDR3 or DDR4, do same */
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

    debug_print("Validating dimm %d, spd addr: 0x%02x spd ptr: %x\n",
		dimm_index, spd_addr, dimm_config->spd_ptrs[dimm_index]);

    {
        int val0, val1;
        int ddr_type = get_ddr_type(node, dimm_config, dimm_index);

        switch (ddr_type)
        {
            case DDR3_DRAM:              /* DDR3 */
	    case DDR4_DRAM:              /* DDR4 */

		debug_print("Validating DDR%d DIMM %d\n", ((dimm_type >> 2) & 3) + 1, dimm_index);

#define DENSITY_BANKS DDR4_SPD_DENSITY_BANKS           // same for DDR3 and DDR4
#define ROW_COL_BITS  DDR4_SPD_ADDRESSING_ROW_COL_BITS // same for DDR3 and DDR4

		val0 = read_spd(node, dimm_config, dimm_index, DENSITY_BANKS);
		val1 = read_spd(node, dimm_config, dimm_index, ROW_COL_BITS);
		if (val0 < 0 && val1 < 0) {
		    debug_print("Error reading SPD for DIMM %d\n", dimm_index);
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
		debug_print("Unknown DIMM type 0x%x for DIMM %d @ 0x%x\n",
			     dimm_type, dimm_index,
			     dimm_config->spd_addrs[dimm_index]);
                return 0;      /* Failed to read dimm */
        }
    }

    return 1;
}

int get_dimm_part_number(char *buffer, bdk_node_t node,
			   const dimm_config_t *dimm_config, int dimm_index,
			   int ddr_type)
{
    int i;
    int c;
    int skipping = 1;
    int strlen   = 0;

#define PART_LIMIT(t)  (((t) == DDR4_DRAM) ? 19 : 18)
#define PART_NUMBER(t) (((t) == DDR4_DRAM) ? DDR4_SPD_MODULE_PART_NUMBER : DDR3_SPD_MODULE_PART_NUMBER)

    int limit  = PART_LIMIT(ddr_type);
    int offset = PART_NUMBER(ddr_type);

    for (i = 0; i < limit; ++i) {

	c = (read_spd(node, dimm_config, dimm_index, offset+i) & 0xff);
	if (c == 0) // any null, we are done
	    break;

	/* Skip leading spaces. */
	if (skipping) {
	    if (isspace(c))
		continue;
	    else
		skipping = 0;
	}

	/* Put non-null non-leading-space-skipped char into buffer */
	buffer[strlen] = c;
	++strlen;
    }

    if (strlen > 0) {
	i = strlen - 1; // last char put into buf
	while (i >= 0 && isspace((int)buffer[i])) { // still in buf and a space
	    --i;
	    --strlen;
	}
    }
    buffer[strlen] = 0;       /* Insure that the string is terminated */

    return strlen;
}

uint32_t get_dimm_serial_number(bdk_node_t node, const dimm_config_t *dimm_config, int dimm_index, int ddr_type)
{
    uint32_t serial_number = 0;
    int offset;

#define SERIAL_NUMBER(t) (((t) == DDR4_DRAM) ? DDR4_SPD_MODULE_SERIAL_NUMBER : DDR3_SPD_MODULE_SERIAL_NUMBER)

    offset = SERIAL_NUMBER(ddr_type);

    for (int i = 0, j = 24; i < 4; ++i, j -= 8) {
        serial_number |= ((read_spd(node, dimm_config, dimm_index, offset + i) & 0xff) << j);
    }

    return serial_number;
}

static uint32_t get_dimm_checksum(bdk_node_t node, const dimm_config_t *dimm_config, int dimm_index, int ddr_type)
{
    uint32_t spd_chksum;

#define LOWER_NIBBLE(t) (((t) == DDR4_DRAM) ? DDR4_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE : DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_LOWER_NIBBLE)
#define UPPER_NIBBLE(t) (((t) == DDR4_DRAM) ? DDR4_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE : DDR3_SPD_CYCLICAL_REDUNDANCY_CODE_UPPER_NIBBLE)

    spd_chksum  =   0xff & read_spd(node, dimm_config, dimm_index, LOWER_NIBBLE(ddr_type));
    spd_chksum |= ((0xff & read_spd(node, dimm_config, dimm_index, UPPER_NIBBLE(ddr_type))) << 8);

    return spd_chksum;
}

static
void report_common_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm, int dimm,
			const char **dimm_types, int ddr_type, char *volt_str)
{
    int spd_ecc;
    unsigned spd_module_type;
    uint32_t serial_number;
    char part_number[21]; /* 20 bytes plus string terminator is big enough for either */
    char *sn_str;

    spd_module_type = get_dimm_module_type(node, dimm_config, upper_dimm, ddr_type);
    spd_ecc = get_dimm_ecc(node, dimm_config, upper_dimm, ddr_type);

    (void) get_dimm_part_number(part_number, node, dimm_config, upper_dimm, ddr_type);

    serial_number = get_dimm_serial_number(node, dimm_config, upper_dimm, ddr_type);
    if ((serial_number != 0) && (serial_number != 0xffffffff)) {
        sn_str = "s/n";
    } else {
        serial_number = get_dimm_checksum(node, dimm_config, upper_dimm, ddr_type);
        sn_str = "chksum";
    }

    // FIXME: add output of DIMM rank/width, as in: 2Rx4, 1Rx8, etc
    printf("DIMM %d: DDR%d %s, %s  %s  %s: %u   %s\n", dimm, ddr_type, dimm_types[spd_module_type],
	   (spd_ecc ? "ECC" : "non-ECC"), part_number, sn_str, serial_number, volt_str);
}

static
void report_ddr3_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm, int dimm)
{
    int spd_voltage;
    char *volt_str;

    static const char *dimm_types[16] = {
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
	/* 1011 */ "LRDIMM",
	/* 1100 */ "16b-SO-DIMM",
	/* 1101 */ "32b-SO-DIMM",
	/* 1110 */ "Reserved",
	/* 1111 */ "Reserved"
    };

    spd_voltage = read_spd(node, dimm_config, upper_dimm, DDR3_SPD_NOMINAL_VOLTAGE);
    if ((spd_voltage == 0) || (spd_voltage & 3))
        volt_str = "1.5V";
    if (spd_voltage & 2)
        volt_str = "1.35V";
    if (spd_voltage & 4)
        volt_str = "1.2xV";

    report_common_dimm(node, dimm_config, upper_dimm, dimm, dimm_types, DDR3_DRAM, volt_str);
}

static
void report_ddr4_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm, int dimm)
{
    int spd_voltage;
    char *volt_str;

    static const char *dimm_types[16] = {
	/* 0000 */ "Extended",
	/* 0001 */ "RDIMM",
	/* 0010 */ "UDIMM",
	/* 0011 */ "SO-DIMM",
	/* 0100 */ "LRDIMM",
	/* 0101 */ "Mini-RDIMM",
	/* 0110 */ "Mini-UDIMM",
	/* 0111 */ "Reserved",
	/* 1000 */ "72b-SO-RDIMM",
	/* 1001 */ "72b-SO-UDIMM",
	/* 1010 */ "Reserved",
	/* 1011 */ "Reserved",
	/* 1100 */ "16b-SO-DIMM",
	/* 1101 */ "32b-SO-DIMM",
	/* 1110 */ "Reserved",
	/* 1111 */ "Reserved"
    };

    spd_voltage = read_spd(node, dimm_config, upper_dimm, DDR4_SPD_MODULE_NOMINAL_VOLTAGE);
    if ((spd_voltage == 0x01) || (spd_voltage & 0x02))
	volt_str = "1.2V";
    if ((spd_voltage == 0x04) || (spd_voltage & 0x08))
	volt_str = "TBD1 V";
    if ((spd_voltage == 0x10) || (spd_voltage & 0x20))
	volt_str = "TBD2 V";

    report_common_dimm(node, dimm_config, upper_dimm, dimm, dimm_types, DDR4_DRAM, volt_str);
}

void report_dimm(bdk_node_t node, const dimm_config_t *dimm_config, int upper_dimm, int dimm)
{
        int ddr_type;

        /* ddr_type only indicates DDR4 or DDR3 */
        ddr_type = get_ddr_type(node, dimm_config, upper_dimm);

        if (ddr_type == DDR4_DRAM)
	    report_ddr4_dimm(node, dimm_config, 0, dimm);
        else
	    report_ddr3_dimm(node, dimm_config, 0, dimm);
}


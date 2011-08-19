#include <bdk.h>
#include <stdio.h>

#ifndef BDK_DISABLE_CSR_DB
extern const __bdk_csr_db_map_t __bdk_csr_db[];
extern const __bdk_csr_db_type_t __bdk_csr_db_csr[];
extern const uint16_t __bdk_csr_db_fieldList[];
extern const uint16_t __bdk_csr_db_field[];
extern const int __bdk_csr_db_range[];
extern const char __bdk_csr_db_string[];
extern const uint64_t __bdk_csr_db_number[];

/* This will point to one of the "data" arrays listed in __bdk_csr_db. The
    numbers index __bdk_csr_db_csr[] to find the CSR. The last one is zero,
    which has a null CSR at __bdk_csr_db_csr[0] */
static const int16_t *csr_list = NULL;
#endif

#ifndef BDK_BUILD_HOST

/**
 * Read a slow CSR, not RSL or NCB.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 *
 * @return The value of the CSR
 */
uint64_t __bdk_csr_read_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address)
{
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PEXP:
            /* We don't handle BAR0 CSRs */
            bdk_error("%s: PEXP registers not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_rd_t pemx_cfg_rd;
            pemx_cfg_rd.u = 0;
            pemx_cfg_rd.s.addr = address;
            BDK_CSR_WRITE(BDK_PEMX_CFG_RD(busnum), pemx_cfg_rd.u);
            pemx_cfg_rd.u = BDK_CSR_READ(BDK_PEMX_CFG_RD(busnum));
            return pemx_cfg_rd.s.data;
        }

        case BDK_CSR_TYPE_SRIOMAINT:
        {
            if (BDK_IS_REQUIRED(SRIO))
                return bdk_srio_config_read32(busnum, 0, -1, 0, 0, address);
            else
                return -1;
        }
    }
    return -1; /* Return -1 as this looks invalid in register dumps. Zero is too common as a good value */
}


/**
 * Write a value to a slow CSR, not RSL or NCB.
 *
 * @param type    Bus type the CSR is on
 * @param busnum  Bus number the CSR is on
 * @param size    Width of the CSR in bytes
 * @param address The address of the CSR
 * @param value   Value to write to the CSR
 */
void __bdk_csr_write_slow(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value)
{
    switch (type)
    {
        case BDK_CSR_TYPE_RSL:
        case BDK_CSR_TYPE_NCB:
        case BDK_CSR_TYPE_PEXP_NCB:
            /* Handled by inline code, we should never get here */
            bdk_error("%s: Passed type that should be handled inline\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PEXP:
            /* We don't handle BAR0 CSRs */
            bdk_error("%s: PEXP registers not supported\n", __FUNCTION__);
            break;

        case BDK_CSR_TYPE_PCICONFIGEP:
        case BDK_CSR_TYPE_PCICONFIGRC:
        {
            bdk_pemx_cfg_wr_t pemx_cfg_wr;
            pemx_cfg_wr.u = 0;
            pemx_cfg_wr.s.addr = address;
            pemx_cfg_wr.s.data = value;
            BDK_CSR_WRITE(BDK_PEMX_CFG_WR(busnum), pemx_cfg_wr.u);
            break;
        }

        case BDK_CSR_TYPE_SRIOMAINT:
            if (BDK_IS_REQUIRED(SRIO))
                bdk_srio_config_write32(busnum, 0, -1, 0, 0, address, value);
            break;
    }
}

#endif

#ifndef BDK_DISABLE_CSR_DB
/**
 * Check if a supplied value is in a CSR range
 *
 * @param rangeid Range ID to check against
 * @param value   Value to check range on
 * @param next    If supplied, this is filled with the next valid value in the range. If the
 *                current value is the last one, then this is set to -1. If value
 *                is invalid, then this will be set to -1.
 *
 * @return Zero if the supplied value is valid. Negative if it is not
 */
static int __bdk_csr_check_range(int rangeid, int value, int *next)
{
    /* Ranges are stored as a length followed by min/max pairs. Length is always
        a multiple of 2 */
    int range_len = __bdk_csr_db_range[rangeid];
    int i = rangeid+1;
    while (range_len)
    {
        range_len -= 2;
        if ((value >= __bdk_csr_db_range[i]) && (value <= __bdk_csr_db_range[i+1]))
        {
            if (next)
            {
                if (value + 1 <= __bdk_csr_db_range[i+1])
                    *next = value + 1;
                else if (range_len)
                    *next = __bdk_csr_db_range[i+2];
                else
                    *next = -1;
            }
            return 0;
        }
        i += 2;
    }
    if (next)
        *next = -1;
    return -1;

}


/**
 * Given a name, find the CSR associated with it.
 *
 * @param name   Name to find. It can contain extra range info in parenthesis
 * @param offset Filled with the argument in parenthesis from the name
 * @param block  Filled with the argument in parenthesis from the name
 *
 * @return Index into csr_list table, or -1 on failure
 */
static int __bdk_csr_lookup_index(const char *name, int *offset, int *block)
{
    if (!csr_list)
    {
        /* Search the CSR DB for a csr map for this chip */
        const __bdk_csr_db_map_t *map = __bdk_csr_db;
        while (map->model && !OCTEON_IS_MODEL(map->model))
            map++;
        if (map->model == 0)
        {
            bdk_error("CSR lookup can't find this chip\n");
            return -1;
        }
        csr_list = map->data;
    }

    /* Return the first DB entry if no name was supplied */
    if (name == NULL)
        return 0;

    /* Extract the CSR index info from the name */
    char *compare = strdup(name);
    char *ptr = strchr(compare, '(');
    if (ptr)
    {
        if (strchr(ptr, ','))
        {
            sscanf(ptr+1, " %d, %d", offset, block);
        }
        else
        {
            sscanf(ptr+1, " %d", offset);
            *block = -1;
        }
        *ptr = 0;
    }
    else
    {
        *offset = -1;
        *block = -1;
    }

    /* Search the DB for this CSR */
    int index=0;
    const __bdk_csr_db_type_t *db = &__bdk_csr_db_csr[csr_list[index]];
    while (db->width)
    {
        if (strcasecmp(compare, __bdk_csr_db_string + db->name_index) == 0)
            break;
        index++;
        db = &__bdk_csr_db_csr[csr_list[index]];
    }
    free(compare);

    /* Fail if we reached the end of the list without finding it */
    if (db->width == 0)
        return -1;

    /* Fail if offset in invalid */
    if (__bdk_csr_check_range(db->offset_range, *offset, NULL))
    {
        //bdk_error("CSR lookup with invalid offset\n");
        return -1;
    }

    /* Fail if block in invalid */
    if (__bdk_csr_check_range(db->block_range, *block, NULL))
    {
        //bdk_error("CSR lookup with invalid block\n");
        return -1;
    }

    return index;
}


/**
 * Given a name, find the CSR associated with it.
 *
 * @param name   Name to find. It can contain extra range info in parenthesis
 * @param offset Filled with the argument in parenthesis from the name
 * @param block  Filled with the argument in parenthesis from the name
 *
 * @return Non NULL on success
 */
static const __bdk_csr_db_type_t *__bdk_csr_lookup(const char *name, int *offset, int *block)
{
    int db_index = __bdk_csr_lookup_index(name, offset, block);
    /* Fail if we can't find the CSR */
    if (db_index == -1)
    {
        bdk_error("CSR lookup can't find this CSR\n");
        return NULL;
    }
    return &__bdk_csr_db_csr[csr_list[db_index]];
}


/**
 * Figure out the address of a CSR given its DB entry and range arguments
 *
 * @param db     DB entry for CSR
 * @param offset Offset inside block
 * @param block  Block index
 *
 * @return Address of CSR
 */
static uint64_t __bdk_csr_lookup_address(const __bdk_csr_db_type_t *db, int offset, int block)
{
    uint64_t address = __bdk_csr_db_number[db->base_index];
    if (offset != -1)
        address += __bdk_csr_db_number[db->offset_index] * offset;
    if (block != -1)
        address += __bdk_csr_db_number[db->block_index] * block;
    return address;
}


/**
 * Decode a CSR in a human readable format
 *
 * @param name   Name of CSR to decode
 * @param value  Value to decode
 *
 * @return Zero on success, negative on failure
 */
int bdk_csr_decode(const char *name, uint64_t value)
{
    int offset = -1;
    int block = -1;
    const __bdk_csr_db_type_t *db = __bdk_csr_lookup(name, &offset, &block);
    int num_fields;

    /* Fail if we can't find the CSR */
    if (!db)
        return -1;

    /* Print the official CSR name */
    if (block != -1)
        printf("%s(%d,%d)", __bdk_csr_db_string + db->name_index, offset, block);
    else if (offset != -1)
        printf("%s(%d)", __bdk_csr_db_string + db->name_index, offset);
    else
        printf("%s", __bdk_csr_db_string + db->name_index);

    /* Print the address and value */
    printf("[0x%016llx] = 0x%016llx\n", (unsigned long long)__bdk_csr_lookup_address(db, offset, block), (unsigned long long)value);

    num_fields = __bdk_csr_db_fieldList[db->field_index];
    while (num_fields--)
    {
        int field = __bdk_csr_db_fieldList[db->field_index + 1 + num_fields];
        const char *field_name = __bdk_csr_db_string + __bdk_csr_db_field[field];
        int start_bit = __bdk_csr_db_field[field+1];
        int stop_bit = __bdk_csr_db_field[field+2];
        int size_bits = stop_bit - start_bit + 1;
        uint64_t v = (value >> start_bit);
        if(size_bits < 64)
            v = v & ~((~0x0ull) << size_bits);
        if (size_bits == 1)
            printf("  [   %2d] %-20s = %10llu (0x%llx)\n", start_bit, field_name,
                (unsigned long long)v, (unsigned long long)v);
        else
            printf("  [%2d:%2d] %-20s = %10llu (0x%llx)\n", stop_bit, start_bit, field_name,
                (unsigned long long)v, (unsigned long long)v);
    }
    return 0;
}


/**
 * Lookup a field by knowning its CSR and start_bit. By starting
 * at zero, you can walk all fields.
 *
 * @param csr_name   CSR to lookup field for
 * @param field_start_bit
 *                   Starting bit of field
 * @param field_name Constant character pointer to receive the address of the field name.
 *
 * @return Width of the field, or negative on failure.
 */
int bdk_csr_field(const char *csr_name, int field_start_bit, const char **field_name)
{
    int offset = -1;
    int block = -1;
    const __bdk_csr_db_type_t *db = __bdk_csr_lookup(csr_name, &offset, &block);
    int num_fields;
    int i;

    /* Fail if we can't find the CSR */
    if (!db)
        return -1;

    num_fields = __bdk_csr_db_fieldList[db->field_index];
    i = db->field_index + 1;
    while (num_fields--)
    {
        int field = __bdk_csr_db_fieldList[i++];
        int start_bit = __bdk_csr_db_field[field+1];
        if (start_bit == field_start_bit)
        {
            int stop_bit = __bdk_csr_db_field[field+2];
            *field_name = __bdk_csr_db_string + __bdk_csr_db_field[field];
            return stop_bit - start_bit + 1;
        }
    }
    return -1;
}


/**
 * Do a CSR read based on the string name of a CSR
 *
 * @param name   Name of CSR to read
 *
 * @return Zero on failure or the CSR value
 */
uint64_t bdk_csr_read_by_name(const char *name)
{
    int offset = -1;
    int block = -1;
    const __bdk_csr_db_type_t *db = __bdk_csr_lookup(name, &offset, &block);
    if (!db)
        return 0;

#ifndef BDK_BUILD_HOST
    return bdk_csr_read(db->type, (block == -1) ? offset : block, db->width,
        __bdk_csr_lookup_address(db, offset, block));
#else
    extern uint64_t octeon_remote_read_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address);
    return octeon_remote_read_csr(db->type, (block == -1) ? offset : block, db->width,
        __bdk_csr_lookup_address(db, offset, block));
#endif
}


/**
 * Do a CSR write based on the string name of a CSR
 *
 * @param name   Name of the CSR to write
 * @param value  Value to write
 *
 * @return Zero on success, negative on failure
 */
int bdk_csr_write_by_name(const char *name, uint64_t value)
{
    int offset = -1;
    int block = -1;
    const __bdk_csr_db_type_t *db = __bdk_csr_lookup(name, &offset, &block);
    if (!db)
        return -1;
#ifndef BDK_BUILD_HOST
    bdk_csr_write(db->type, (block == -1) ? offset : block, db->width,
        __bdk_csr_lookup_address(db, offset, block), value);
#else
    extern void octeon_remote_write_csr(bdk_csr_type_t type, int busnum, int size, uint64_t address, uint64_t value);
    octeon_remote_write_csr(db->type, (block == -1) ? offset : block, db->width,
        __bdk_csr_lookup_address(db, offset, block), value);
#endif
    return 0;
}


/**
 * Get a CSR name. This is menat to be used to iterate through all
 * possible CSR names.
 *
 * @param last_name Get the CSR follwoing this name. Supply NULL for the first CSR
 * @param buffer    Buffer to fill with the CSR name
 *
 * @return Zero on success, negative on list end or failure
 */
int bdk_csr_get_name(const char *last_name, char *buffer)
{
    int offset = -1;
    int block = -1;
    const __bdk_csr_db_type_t *db;

    /* Find our current DB spot */
    int db_index = __bdk_csr_lookup_index(last_name, &offset, &block);
    if (db_index == -1)
        return -1;
    db = &__bdk_csr_db_csr[csr_list[db_index]];

    /* We we are continuing we need to process the range data and figure out what is next */
    if (last_name)
    {
        /* Check if offset might need to increment */
        if (offset != -1)
        {
            int next = -1;
            /* Make sure the current offset is valid */
            if (__bdk_csr_check_range(db->offset_range, offset, &next))
                return -1;
            /* If there isn't a next, we may need to increment block */
            if (next == -1)
            {
                /* Offset goes back to the lowest index */
                offset = __bdk_csr_db_range[db->offset_range+1];
                if (block != -1)
                {
                    /* Make sure the current block is valid */
                    if (__bdk_csr_check_range(db->block_range, block, &next))
                        return -1;
                    /* If there isn't a next, we're done with this CSR */
                    if (next == -1)
                    {
                        /* End of block range, so skip to next CSR */
                        db = &__bdk_csr_db_csr[csr_list[++db_index]];
                        offset = __bdk_csr_db_range[db->offset_range+1];
                        block = __bdk_csr_db_range[db->block_range+1];
                    }
                    else
                        block = next;
                }
                else
                {
                    /* No block range, so skip to next CSR */
                    db = &__bdk_csr_db_csr[csr_list[++db_index]];
                    offset = __bdk_csr_db_range[db->offset_range+1];
                    block = __bdk_csr_db_range[db->block_range+1];
                }
            }
            else
                offset = next;
        }
        else
        {
            /* No range data, so skip to next CSR */
            db = &__bdk_csr_db_csr[csr_list[++db_index]];
            offset = __bdk_csr_db_range[db->offset_range+1];
            block = __bdk_csr_db_range[db->block_range+1];
        }
    }

    /* End of list, return failure */
    if (db->width == 0)
        return -1;

    /* Fill in the next name */
    if (buffer)
    {
        if (block != -1)
            sprintf(buffer, "%s(%d,%d)", __bdk_csr_db_string + db->name_index, offset, block);
        else if (offset != -1)
            sprintf(buffer, "%s(%d)", __bdk_csr_db_string + db->name_index, offset);
        else
            sprintf(buffer, "%s", __bdk_csr_db_string + db->name_index);
    }

    return 0;
}

#endif

void __bdk_csr_fatal(const char *name, int num_args, unsigned long arg1, unsigned long arg2)
{
    switch (num_args)
    {
        case 0:
            bdk_fatal("%s is invalid on this chip\n", name);
        case 1:
            bdk_fatal("%s(%lu) is invalid on this chip\n", name, arg1);
        default:
            bdk_fatal("%s(%lu,%lu) is invalid on this chip\n", name, arg1, arg2);
    }
}


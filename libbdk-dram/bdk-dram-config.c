#include <bdk.h>

BDK_REQUIRE_DEFINE(DRAM_CONFIG);

/* DRAM is configured by matching it against a string name. The BDK supports
   loading up to four different DRAM configs by using the defines
   BDK_DRAM_CONFIG, BDK_DRAM_CONFIG2, BDK_DRAM_CONFIG3, and
   BDK_DRAM_CONFIG4. More can be easily added if necessary */

#define _CONFIG_FUNC_NAME(n) dram_get_config_ ## n
#define CONFIG_FUNC_NAME(n) _CONFIG_FUNC_NAME(n)

#ifndef BDK_DRAM_CONFIG
/* No DRAM config was specified, pick the ebb8800 as a default so at
   least one configuration is avaialable */
#define BDK_DRAM_CONFIG ebb8800
#warning No DRAM config specified, defaulting to ebb8800
#endif

typedef const dram_config_t* (*config_func_t)();

/* These externs pull in configs defined in other files */
#ifdef BDK_DRAM_CONFIG
extern const dram_config_t *CONFIG_FUNC_NAME(BDK_DRAM_CONFIG)();
#endif
#ifdef BDK_DRAM_CONFIG2
extern const dram_config_t *CONFIG_FUNC_NAME(BDK_DRAM_CONFIG2)();
#endif
#ifdef BDK_DRAM_CONFIG3
extern const dram_config_t *CONFIG_FUNC_NAME(BDK_DRAM_CONFIG3)();
#endif
#ifdef BDK_DRAM_CONFIG4
extern const dram_config_t *CONFIG_FUNC_NAME(BDK_DRAM_CONFIG4)();
#endif

/* This table is the list of supported DRAM configs */
static const config_func_t dram_table[] =
{
#ifdef BDK_DRAM_CONFIG
    CONFIG_FUNC_NAME(BDK_DRAM_CONFIG),
#endif
#ifdef BDK_DRAM_CONFIG2
    CONFIG_FUNC_NAME(BDK_DRAM_CONFIG2),
#endif
#ifdef BDK_DRAM_CONFIG3
    CONFIG_FUNC_NAME(BDK_DRAM_CONFIG3),
#endif
#ifdef BDK_DRAM_CONFIG4
    CONFIG_FUNC_NAME(BDK_DRAM_CONFIG4),
#endif
    NULL /* Table must end in NULL */
};

static const dram_config_t *bdk_find_dram_config_by_name(int node, const char *config_name)
{
    const config_func_t *table = dram_table;
    const dram_config_t *config = NULL;
    while (*table)
    {
        const dram_config_t *c = (*table)();
        if (strcmp(c->name, config_name) == 0)
        {
            config = c;
            break;
        }
        table++;
    }
    return config;
}

/**
 * Lookup a DRAM configuration by name and intialize dram with it
 *
 * @param node   Node to configure
 * @param config_name
 *               Name of the configuration to use
 * @param ddr_clock_override
 *               If non zero, override the DRAM frequency specified in the config with
 *               this value
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
int bdk_dram_config(int node, const char *config_name, int ddr_clock_override)
{
    const dram_config_t *config = bdk_find_dram_config_by_name(node, config_name);

    if (!config)
    {
        bdk_error("DRAM config not found: %s\n", config_name);
        return -1;
    }

    BDK_TRACE(DRAM, "N%d: Starting DRAM init (config=%p, ddr_clock_override=%d)\n", node, config, ddr_clock_override);
    int mbytes = libdram_config(node, config, ddr_clock_override);
    BDK_TRACE(DRAM, "N%d: DRAM init returned %d\n", node, mbytes);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    int ddr_clock_hertz = (ddr_clock_override) ? ddr_clock_override : config->ddr_clock_hertz;
    printf("BDK DRAM: %d MB, %d MHz\n", mbytes, ((ddr_clock_hertz + 500000) /1000000));
    return mbytes;
}

/**
 * Lookup a DRAM configuration by name and return ddr_clock_hertz field
 *
 * @param node   Node to configure
 * @param config_name
 *               Name of the configuration to use
 *
 * @return DDR Clock hertz, or negative on failure
 */
int bdk_dram_config_get_hertz_by_name(int node, const char *config_name)
{
    const dram_config_t *config = bdk_find_dram_config_by_name(node, config_name);

    if (!config)
    {
        bdk_error("DRAM config not found: %s\n", config_name);
        return -1;
    }

    return config->ddr_clock_hertz;
}

/**
 * Return the name of the DRAM configuration at the specified index. If index
 * is larger than the number of DRAM configs, NULL is returned.
 *
 * @param index  Index to retrieve
 *
 * @return Name or NULL
 */
const char* bdk_dram_get_config_name(int index)
{
    /* The -1 is to account for the NULL at the end */
    const int table_size = sizeof(dram_table) / sizeof(dram_table[0]) - 1;
    if ((index < 0) || (index >= table_size))
        return NULL;
    else
        return dram_table[index]()->name;
}


/**
 * Return the highest address currently used by the BDK. This address will
 * be about 4MB above the top of the BDK to make sure small growths between the
 * call and its use don't cause corruption. Any call to memory allocation can
 * change this value.
 *
 * @return Size of the BDK in bytes
 */
uint64_t bdk_dram_get_top_of_bdk(void)
{
    /* Make sure the start address is higher that the BDK's active range.
     *
     * As sbrk() returns a node address, mask off the node portion of
     * the address to make it a physical offset. Doing this simplifies the
     * address checks and calculations which only work with physical offsets.
     */
    extern caddr_t sbrk(int incr);
    uint64_t top_of_bdk = (bdk_ptr_to_phys(sbrk(0)) & bdk_build_mask(40));
    /* Give 4MB of extra so the BDK has room to grow */
    top_of_bdk += 4 << 20;
    /* Align it on a 64KB boundary */
    top_of_bdk >>= 16;
    top_of_bdk <<= 16;
    return top_of_bdk;
}


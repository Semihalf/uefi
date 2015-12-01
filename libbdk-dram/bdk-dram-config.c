#include <bdk.h>

BDK_REQUIRE_DEFINE(DRAM_CONFIG);

/* DRAM is configured by matching it against a string name */

#define _CONFIG_FUNC_NAME(n) dram_get_config_ ## n
#define CONFIG_FUNC_NAME(n) _CONFIG_FUNC_NAME(n)

typedef const dram_config_t* (*config_func_t)();

/* These externs pull in configs defined in other files */
//extern const dram_config_t* CONFIG_FUNC_NAME(ebb8800)();

/* This table is the list of supported DRAM configs */
static const config_func_t dram_table[] =
{
    //CONFIG_FUNC_NAME(ebb8800),
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
 * Lookup a DRAM configuration by name and initialize DRAM using it
 *
 * @param node   Node to configure
 * @param ddr_clock_override
 *               If non zero, override the DRAM frequency specified
 *               in the config with this value
 *
 * @return Amount of DRAM in MB, or negative on failure
 */
int bdk_dram_config(int node, int ddr_clock_override)
{
    const dram_config_t *config = libdram_config_load(node);
    if (!config)
    {
        const char *config_name = bdk_config_get_str(BDK_CONFIG_DRAM_NODE, node);
        config = bdk_find_dram_config_by_name(node, config_name);
        if (config)
        {
            printf("\33[1m"); /* Bold */
            bdk_warn("\n");
            bdk_warn("********************************************************\n");
            bdk_warn("DRAM configuration not found in device tree. Using the\n");
            bdk_warn("legacy configuration \"%s\".\n", config_name);
            bdk_warn("A template device tree has been created from the legacy\n");
            bdk_warn("configuration. Enter diagnostics and display the device\n");
            bdk_warn("tree by selecting \"Display current configuration\".\n");
            bdk_warn("********************************************************\n");
            bdk_warn("\n");
            printf("\33[0m"); /* Normal */
            __bdk_dram_convert_to_dts(node, config);
        }
        else
        {
            bdk_error("DRAM config not found: %s\n", config_name);
            return -1;
        }
    }

    BDK_TRACE(DRAM, "N%d: Starting DRAM init (config=%p, ddr_clock_override=%d)\n", node, config, ddr_clock_override);
    int mbytes = libdram_config(node, config, ddr_clock_override);
    BDK_TRACE(DRAM, "N%d: DRAM init returned %d\n", node, mbytes);
    if (mbytes <= 0)
    {
        printf("ERROR: DDR initialization failed\n");
        return -1;
    }

    return mbytes;
}

/**
 * Do DRAM configuration tuning
 *
 * @param node   Node to tune
 *
 * @return Success or Fail
 */
int bdk_dram_tune(int node)
{
    int ret;
    BDK_TRACE(DRAM, "N%d: Starting DRAM tuning\n", node);
    ret = libdram_tune(node);
    BDK_TRACE(DRAM, "N%d: DRAM tuning returned %d\n", node, ret);
    return ret;
}

/**
 * Do all the DRAM Margin tests 
 *
 * @param node   Node to test
 *
 * @return Success or Fail
 */
void bdk_dram_margin_all(int node)
{
    int ret_rt, ret_wt, ret_rv, ret_wv;
    char *risk[2] = { "Low Risk", "Needs Review" };

    BDK_TRACE(DRAM, "N%d: Starting DRAM Margin ALL\n", node);
    ret_rt = libdram_margin_read_timing(node);
    ret_wt = libdram_margin_write_timing(node);
    ret_rv = libdram_margin_read_voltage(node);
    ret_wv = libdram_margin_write_voltage(node);
    BDK_TRACE(DRAM, "N%d: DRAM Margin ALL finished\n", node);
    /*
      >>> Summary from DDR Margining tool:
      >>> N0: Read Timing Margin   : Low Risk
      >>> N0: Write Timing Margin  : Low Risk
      >>> N0: Read Voltage Margin  : Low Risk
      >>> N0: Write Voltage Margin : Low Risk  
     */
    printf("  \n");
    printf("-------------------------------------\n");
    printf("  \n");
    printf("Summary from DDR Margining tool\n");
    printf("N%d: Read Timing Margin   : %s\n", node, risk[!!ret_rt]);
    printf("N%d: Write Timing Margin  : %s\n", node, risk[!!ret_wt]);

    // these may not have been done due to DDR3 and/or THUNDER pass 1.x
    // FIXME? would it be better to print an appropriate message here? 
    if (ret_rv != -1) printf("N%d: Read Voltage Margin  : %s\n", node, risk[!!ret_rv]);
    if (ret_wv != -1) printf("N%d: Write Voltage Margin : %s\n", node, risk[!!ret_wv]);

    printf("  \n");
    printf("-------------------------------------\n");
    printf("  \n");

    return;
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
 * Return the string of the DRAM configuration info at the specified node.
 * If the node is not configured, NULL is returned.
 *
 * @param index  node
 *
 * @return string or NULL
 */
#define INFO_STRING_LEN 40
static char info_string[INFO_STRING_LEN];
static const char *info_ptr = info_string;

const char* bdk_dram_get_info_string(int node)
{
    /* FIXME: need to validate node */

    snprintf(info_string, INFO_STRING_LEN,
             " %ld MB, %d MHz, %s %s",
             bdk_dram_get_size_mbytes(node),
             ((libdram_get_freq_from_pll(node, 0) + 500000) /1000000),
             (__bdk_dram_is_ddr4(node, 0)) ? "DDR4" : "DDR3",
             (__bdk_dram_is_rdimm(node, 0)) ? "RDIMM" : "UDIMM");

    return info_ptr;
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

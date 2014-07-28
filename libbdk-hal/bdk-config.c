#include <bdk.h>
#include <stdio.h>

static uint8_t __bdk_config_is_valid[__BDK_CONFIG_END];
static uint64_t __bdk_config_cache[__BDK_CONFIG_END];

typedef struct
{
    const char *name;
    uint64_t default_value;
} bdk_config_entry_t;

#define AS_INIT(name, default_value) [name] = {#name, default_value}
static const bdk_config_entry_t __bdk_config_table[__BDK_CONFIG_END] =
{
    /* CN78XX currently requires FPA buffers to be a power of 2. The memalign()
       used to allocate the buffers isn't smart enough to handle arbitrary
       alignment */
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE0, 256),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE1, 128),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE2, 4096), /* CN78XX SSO requires 4KB */
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE3, 4096), /* CN78XX PKO requires 4KB */
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE4, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE5, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE6, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE7, 0),

    AS_INIT(BDK_CONFIG_INPUT_TAG_TYPE, BDK_WQE_TAG_TYPE_ORDERED),
    AS_INIT(BDK_CONFIG_INPUT_PORT_SKIP_MODE, 2),

    AS_INIT(BDK_CONFIG_PHY_MGMT_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_MGMT_PORT1, -1),

    AS_INIT(BDK_CONFIG_PHY_IF0_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF0_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF0_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF0_PORT3, -1),
    AS_INIT(BDK_CONFIG_PHY_IF1_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF1_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF1_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF1_PORT3, -1),
    AS_INIT(BDK_CONFIG_PHY_IF2_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF2_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF2_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF2_PORT3, -1),
    AS_INIT(BDK_CONFIG_PHY_IF3_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF3_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF3_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF3_PORT3, -1),
    AS_INIT(BDK_CONFIG_PHY_IF4_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF4_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF4_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF4_PORT3, -1),
    AS_INIT(BDK_CONFIG_PHY_IF5_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_IF5_PORT1, -1),
    AS_INIT(BDK_CONFIG_PHY_IF5_PORT2, -1),
    AS_INIT(BDK_CONFIG_PHY_IF5_PORT3, -1),

    AS_INIT(BDK_CONFIG_THREAD_STACK_SIZE, 4096),
    /* This is Cavium's OUI with the local admin bit. We will use this as a
        default as it won't collide with official addresses, but is sort of
        part of the Cavium range. The lower three bytes will be updated with
        the wafer info later */
    AS_INIT(BDK_CONFIG_MAC_ADDRESS, 0x020fb7000000ull),

    AS_INIT(BDK_CONFIG_ILK0_LANES, 4),
    AS_INIT(BDK_CONFIG_ILK1_LANES, 4),
    AS_INIT(BDK_CONFIG_ILK0_PORTS, 8),
    AS_INIT(BDK_CONFIG_ILK1_PORTS, 8),

    /* No ports default to Higig mode. 0 = XAUI, 1 = Higig(+), 2 = Higig2 */
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF0, 0),
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF1, 0),
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF2, 0),
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF3, 0),
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF4, 0),
    AS_INIT(BDK_CONFIG_HIGIG_MODE_IF5, 0),

    /* The number of packet buffers is filled in dynamically in __bdk_config_init() */
    AS_INIT(BDK_CONFIG_NUM_PACKET_BUFFERS, 0),
    AS_INIT(BDK_CONFIG_NUM_OUTPUT_BUFFERS, 0),

    /* Controls if link status messages are displayed. Turning this off
        can be useful to help scripting as the messages are aynchronous */
    AS_INIT(BDK_CONFIG_SHOW_LINK_STATUS, BDK_SHOW_BOOT_BANNERS),


    /* Coremask (good cores) to run when 'all' cores are started.
       0x0 is interpreted as all cores being good.*/
    AS_INIT(BDK_CONFIG_COREMASK, 0x0ull),
};
#undef AS_INIT

static uint64_t __bdk_config_get_slow(bdk_config_t cfg)
{
    const bdk_config_entry_t *entry = &__bdk_config_table[cfg];
    uint64_t result = entry->default_value;
    const char *value = getenv(entry->name);

    if (value)
    {
        if ((value[0] == '0') && (value[1] == 'x'))
        {
            if (sscanf(value+2, "%llx", (unsigned long long *)&result) != 1)
                result = 0;
        }
        else
        {
            if (sscanf(value, "%lli", (unsigned long long *)&result) != 1)
                result = 0;
        }
    }
    __bdk_config_cache[cfg] = result;
    BDK_SYNCW;
    __bdk_config_is_valid[cfg] = 1;
    BDK_SYNCW;
    return result;
}


uint64_t bdk_config_get(bdk_config_t cfg)
{
    if (bdk_likely(__bdk_config_is_valid[cfg]))
        return __bdk_config_cache[cfg];
    else
        return __bdk_config_get_slow(cfg);
}


void bdk_config_set(bdk_config_t cfg, uint64_t value)
{
    __bdk_config_cache[cfg] = value;
    BDK_SYNCW;
    __bdk_config_is_valid[cfg] = 1;
    BDK_SYNCW;
}

const char *bdk_config_get_name(bdk_config_t cfg)
{
    const bdk_config_entry_t *entry = &__bdk_config_table[cfg];
    return entry->name + 4; /* Strip off "BDK_" */
}

/**
 * Initialize config options that can't be statically setup at
 * compile time.
 */
void __bdk_config_init(void)
{
    /* Set the lower MAC address bits based on the chip manufacturing
        information. This should give reasonable MAC address defaults
        for production parts */
    BDK_CSR_INIT(fus_dat0, bdk_numa_local(), BDK_MIO_FUS_DAT0);
    uint64_t mac_address = bdk_config_get(BDK_CONFIG_MAC_ADDRESS);
    mac_address |= fus_dat0.u64 & 0xffffff;
    bdk_config_set(BDK_CONFIG_MAC_ADDRESS, mac_address);

    /* Set the number of packet buffers in FPA pool 0 */
    int num_packet_buffers = 768;
    int num_output_buffers = 256;
    if (CAVIUM_IS_MODEL(OCTEON_CN78XX))
    {
        num_packet_buffers = 8192;
    }
    bdk_config_set(BDK_CONFIG_NUM_PACKET_BUFFERS, num_packet_buffers);
    bdk_config_set(BDK_CONFIG_NUM_OUTPUT_BUFFERS, num_output_buffers);

    if (__bdk_is_dram_enabled(bdk_numa_local()))
    {
        /* Use more packet buffers if DRAM is enabled */
        bdk_config_set(BDK_CONFIG_NUM_PACKET_BUFFERS, 2048);
        /* Use larger packet buffers if DRAM is enabled */
        bdk_config_set(BDK_CONFIG_FPA_POOL_SIZE0, 2048);
        /* Use larger command buffers if DRAM is enabled */
        bdk_config_set(BDK_CONFIG_FPA_POOL_SIZE1, 2048);
    }
}

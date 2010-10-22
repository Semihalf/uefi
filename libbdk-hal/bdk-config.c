#include <bdk.h>
#include <stdio.h>

uint8_t __bdk_config_is_valid[__BDK_CONFIG_END];
uint64_t __bdk_config_cache[__BDK_CONFIG_END];

typedef struct
{
    const char *name;
    uint64_t default_value;
} bdk_config_entry_t;

#define AS_INIT(name, default_value) [name] = {#name, default_value}
static const bdk_config_entry_t __bdk_config_table[__BDK_CONFIG_END] =
{
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE0, 2048),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE1, 128),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE2, 1024),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE3, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE4, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE5, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE6, 0),
    AS_INIT(BDK_CONFIG_FPA_POOL_SIZE7, 0),

    AS_INIT(BDK_CONFIG_FIRST_MBUFF_SKIP, 0),
    AS_INIT(BDK_CONFIG_NOT_FIRST_MBUFF_SKIP, 0),
    AS_INIT(BDK_CONFIG_ENABLE_IPD, 1),
    AS_INIT(BDK_CONFIG_INPUT_TAG_TYPE, BDK_SSO_TAG_TYPE_ORDERED),
    AS_INIT(BDK_CONFIG_INPUT_PORT_SKIP_MODE, BDK_PIP_PORT_CFG_MODE_SKIPL2),

    AS_INIT(BDK_CONFIG_PHY_MGMT_PORT0, -1),
    AS_INIT(BDK_CONFIG_PHY_MGMT_PORT1, -1),

    AS_INIT(BDK_CONFIG_THREAD_STACK_SIZE, 16384),
    AS_INIT(BDK_CONFIG_MAC_ADDRESS, 0xdeadbeef00),
};
#undef AS_INIT

uint64_t __bdk_config_get_slow(bdk_config_t cfg)
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

extern void bdk_config_set(bdk_config_t cfg, uint64_t value)
{
    const bdk_config_entry_t *entry = &__bdk_config_table[cfg];
    char buffer[19];

    __bdk_config_cache[cfg] = value;
    BDK_SYNCW;
    __bdk_config_is_valid[cfg] = 1;
    BDK_SYNCW;

    sprintf(buffer, "0x%llu", (unsigned long long)value);
    setenv(entry->name, buffer, 1);
}

